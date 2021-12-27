#define GLEW_STATIC

#include "global.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "port/options.h"

#define WIN64
#define IS_FULL_SCREEN false

static const float identity[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};

struct Matrix
{
	Matrix()
	{
	}

	Matrix(const float* fm)
	{
		if(fm)
		{
			memcpy(m, fm, sizeof(float) * 16);
		}
	}

	float m[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
};

#include "platform_sdl2.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "port/gfx/fast64.h"
#include "gfx_cc.h"
#include "gfx_screen_config.h"
#include <unordered_map>
//#include "engine/asset.h"
#include "xxhash32.h"
#include "xxhash64.h"
#include "fast64.h"
#include "port/audio/audio_api.h"
#include <algorithm>
#include <thread>
#include <chrono>
//#include "game/options.h"

#if defined(_MSC_VER) && defined(DEBUG)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

extern AudioAPI audio_sdl;
extern AudioAPI* audio_api;

struct TriIndex
{
	u32 index[3];
} PACKED;

static_assert(sizeof(TriIndex) == sizeof(u32) * 3, "TriIndex incorrect size!");

#define SUPPORT_CHECK(x) assert(x)

static u8 rgba32_buf[2048 * 2048 * 4];

static u32 g_vtx_buf_size;
static u32 g_vtx_buf_dest;

// SCALE_M_N: upscale/downscale M-bit integer to N-bit
#define SCALE_5_8(VAL_) (((VAL_)*0xFF) / 0x1F)
#define SCALE_8_5(VAL_) ((((VAL_) + 4) * 0x1F) / 0xFF)
#define SCALE_4_8(VAL_) ((VAL_)*0x11)
#define SCALE_8_4(VAL_) ((VAL_) / 0x11)
#define SCALE_3_8(VAL_) ((VAL_)*0x24)
#define SCALE_8_3(VAL_) ((VAL_) / 0x24)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define HALF_SCREEN_WIDTH (SCREEN_WIDTH / 2)
#define HALF_SCREEN_HEIGHT (SCREEN_HEIGHT / 2)

#define RATIO_X (gfx_current_dimensions.width / (2.0f * HALF_SCREEN_WIDTH))
#define RATIO_Y (gfx_current_dimensions.height / (2.0f * HALF_SCREEN_HEIGHT))

#define MAX_VBO 128
#define MAX_BUFFERED (256 * 256)
#define MAX_LIGHTS 2
#define MAX_VERTICES (256 * 256)

#define INVALID_VBO 0xFFFFFFFFFFFFFFFE

struct Vbo
{
	Vbo() : handle(INVALID_VBO), num_tris(0)
	{
	}

	Vbo(Vbo&& vbo)
	{
		handle	 = vbo.handle;
		num_tris = vbo.num_tris;

		vbo.handle   = INVALID_VBO;
		vbo.num_tris = 0;
	}

	Vbo(u64 handle, size_t num_tris) : handle(handle), num_tris(num_tris)
	{
	}

	u64 handle;
	size_t num_tris;
};

static std::unordered_map<u64, std::shared_ptr<Vbo>> g_triCache;

namespace sm64::gfx
{
	struct RGBA
	{
		u8 r, g, b, a;
	};

	struct XYWidthHeight
	{
		XYWidthHeight() : x(0), y(0), width(0), height(0)
		{
		}

		XYWidthHeight(u16 x, u16 y, u16 width, u16 height) : x(x), y(y), width(width), height(height)
		{
		}

		u16 x, y, width, height;

		bool operator==(const XYWidthHeight& b) const
		{
			return memcmp(this, &b, sizeof(b)) == 0;
		}

		bool operator!=(const XYWidthHeight& b) const
		{
			return !operator==(b);
		}
	};

	struct LoadedVertex
	{
		float x, y, z, w;
		float u, v;
		struct RGBA color;
		u8 clip_rej;
	};

	struct ColorCombiner
	{
		u32 cc_id;
		ShaderProgram* prg;
		u8 shader_input_mapping[2][4];
	};

	static ColorCombiner color_combiner_pool[64];
	static u8 color_combiner_pool_size;

	static bool dropped_frame;

	static float buf_vbo[MAX_BUFFERED * (26 * 3)]; // 3 vertices in a triangle and 26 floats per vtx
	static size_t buf_vbo_len;
	static size_t buf_vbo_num_tris;

	static platform::Sdl* gfx_wapi	= nullptr;
	static opengl::Opengl* gfx_rapi = nullptr;

	static const ColorCombiner* prev_combiner = nullptr;
	static std::unordered_map<u64, TextureNode> g_textureCache;

	class VBO_TMP
	{
		public:
		VBO_TMP()
		{
			handle = gfx_rapi->create_vbo();
		}

		VBO_TMP(const void* buffer, const u64 sz)
		{
			handle = gfx_rapi->create_vbo();
			upload(buffer, sz);
		}

		~VBO_TMP()
		{
			handle = gfx_rapi->delete_vbo(handle);
			handle = INVALID_VBO;
		}

		void upload(const void* buffer, const u64 sz)
		{
			gfx_rapi->update_vbo(handle, (float*)buffer, sz);
		}

		u64 handle;
	};

	static u64 current_vbo = 0;

	VBO_TMP& nextVbo()
	{
		static VBO_TMP vbos[MAX_VBO];

		if(current_vbo >= MAX_VBO)
		{
			current_vbo = current_vbo % MAX_VBO;
		}

		return vbos[current_vbo++];
	}

	static struct RenderingState
	{
		bool depth_test;
		bool depth_mask;
		bool decal_mode;
		bool alpha_blend;
		struct XYWidthHeight viewport, scissor;
		struct ShaderProgram* shader_program;
		struct TextureNode* textures[2];
	} rendering_state;

	void flush();
	const ColorCombiner* gfx_lookup_or_create_color_combiner(u32 cc_id);
	ShaderProgram* lookup_or_create_shader_program(u32 shader_id);
	void import_texture(int tile);

	void set_fullscreen(bool value)
	{
		if(gfx_wapi)
		{
			gfx_wapi->set_fullscreen(value, true);
		}
	}

	struct RSP
	{
		void setGeometryMode(const u32 value)
		{
			if(m_geometry_mode != value)
			{
				m_geometry_mode = value;

				if(geoModeZbuffer() != rendering_state.depth_test)
				{
					flush();
					gfx_rapi->set_depth_test(geoModeZbuffer());
					rendering_state.depth_test = geoModeZbuffer();
				}
			}
		}

		const u32 geometryMode() const
		{
			return m_geometry_mode;
		}

		const bool geoModeLighting() const
		{
			return m_geometry_mode & G_LIGHTING;
		}

		const bool geoModeTextureGen() const
		{
			return m_geometry_mode & G_TEXTURE_GEN;
		}

		const bool geoModeFog() const
		{
			return m_geometry_mode & G_FOG;
		}

		const bool geoModeZbuffer() const
		{
			return m_geometry_mode & G_ZBUFFER;
		}

		const u32 geoModeCullBoth() const
		{
			return m_geometry_mode & G_CULL_BOTH;
		}

		void saveMatrix()
		{
			memcpy(MP_matrix_cached, MP_matrix, sizeof(MP_matrix));
		}

		void setIdentityMatrix()
		{
			memcpy(MP_matrix_cached, identity, sizeof(identity));
		}

		const float* matrix() const
		{
			return &MP_matrix_cached[0][0];
		}

		float* matrix()
		{
			return &MP_matrix_cached[0][0];
		}

		u64 hash() const
		{
			XXHash64 h(0);
			h.add(&m_geometry_mode, sizeof(m_geometry_mode));
			return h.hash();
		}

		void setFogMetrics(const s16 scaler, const s16 offset)
		{
			m_fog_mul    = scaler;
			m_fog_offset = offset;
			gfx_rapi->setFogMetrics(scaler, offset);
		}

		float modelview_matrix_stack[11][4][4];
		u8 modelview_matrix_stack_size;

		float MP_matrix_cached[4][4];
		float MP_matrix[4][4];
		float P_matrix[4][4];

		Light_t current_lights[MAX_LIGHTS + 1];
		float current_lights_coeffs[MAX_LIGHTS][3];
		float current_lookat_coeffs[2][3]; // lookat_x, lookat_y
		u8 current_num_lights;		   // includes ambient light
		bool lights_changed;

		u32 m_geometry_mode;
		s16 m_fog_mul;
		s16 m_fog_offset;

		struct
		{
			// U0.16
			u16 s;
			u16 t;
		} texture_scaling_factor;

		struct
		{
			size_t n_vertices;
			size_t dest_index;
			const Vtx* vertices;
		} verticies;

		LoadedVertex loaded_vertices[MAX_VERTICES + 4];
	};

	struct RDP
	{
		void setTransformed(const bool value)
		{
			if(m_transformed != value)
			{
				flush();
				m_transformed = value;
				refresh();
			}
		}

		void setFogColor(const u8 r, const u8 g, const u8 b, const u8 a)
		{
			flush();

			fog_color.r = r;
			fog_color.g = g;
			fog_color.b = b;
			fog_color.a = a;

			gfx_rapi->setFogColor((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
		}

		const bool isTransformed() const
		{
			return m_transformed;
		}

		void setCombineMode(const u32 value)
		{
			if(m_combine_mode != value)
			{
				m_combine_mode = value;
			}
		}

		const u32 combineMode() const
		{
			return m_combine_mode;
		}

		void setOtherModeL(const u32 value)
		{
			if(m_other_mode_l != value)
			{
				m_other_mode_l = value;

				if(updateZ() != rendering_state.depth_mask)
				{
					flush();
					gfx_rapi->set_depth_mask(updateZ());
					rendering_state.depth_mask = updateZ();
				}

				if(useZmodeDecal() != rendering_state.decal_mode)
				{
					flush();
					gfx_rapi->set_zmode_decal(useZmodeDecal());
					rendering_state.decal_mode = useZmodeDecal();
				}
				//refresh();
			}
		}

		void setOtherModeH(const u32 value)
		{
			if(m_other_mode_h != value)
			{
				m_other_mode_h = value;
				//refresh();
			}
		}

		const u32 otherModeL() const
		{
			return m_other_mode_l;
		}

		const u32 otherModeH() const
		{
			return m_other_mode_h;
		}

		bool useFog() const
		{
			return (m_other_mode_l >> 30) == G_BL_CLR_FOG;
		}

		bool useTextureEdge() const
		{
			return (m_other_mode_l & CVG_X_ALPHA) == CVG_X_ALPHA;
		}

		bool useNoise() const
		{
			return (m_other_mode_l & G_AC_DITHER) == G_AC_DITHER;
		}

		bool useFrameBufferAlpha() const
		{
			return (m_other_mode_l & (G_BL_A_MEM << 18)) == 0;
		}

		bool useLinearFilter() const
		{
			return (m_other_mode_h & (3U << G_MDSFT_TEXTFILT)) != G_TF_POINT;
		}

		bool updateZ() const
		{
			return (m_other_mode_l & Z_UPD) == Z_UPD;
		}

		bool useZmodeDecal() const
		{
			return (m_other_mode_l & ZMODE_DEC) == ZMODE_DEC;
		}

		bool useAlpha() const
		{
			return useFrameBufferAlpha() | useTextureEdge();
		}

		u32 modeMdsftTextfilt() const
		{
			return m_other_mode_h & (3U << G_MDSFT_TEXTFILT);
		}

		u32 cycleType() const
		{
			return (m_other_mode_h & (3U << G_MDSFT_CYCLETYPE));
		}

		void refresh()
		{
			u32 cc_id = m_combine_mode;

			const bool use_alpha = useFrameBufferAlpha() | useTextureEdge();

			if(use_alpha)
			{
				cc_id |= SHADER_OPT_ALPHA;
			}

			if(useFog())
			{
				cc_id |= SHADER_OPT_FOG;
			}

			if(useTextureEdge())
			{
				cc_id |= SHADER_OPT_TEXTURE_EDGE;
			}

			if(useNoise())
			{
				cc_id |= SHADER_OPT_NOISE;
			}

			if(!use_alpha)
			{
				cc_id &= ~0xfff000;
			}

			comb		   = gfx_lookup_or_create_color_combiner(cc_id);
			ShaderProgram* prg = comb->prg;

			if(prg != rendering_state.shader_program)
			{
				flush();
				gfx_rapi->unload_shader(rendering_state.shader_program);
				gfx_rapi->load_shader(prg);
				rendering_state.shader_program = prg;
			}

			if(use_alpha != rendering_state.alpha_blend)
			{
				flush();
				gfx_rapi->set_use_alpha(use_alpha);
				rendering_state.alpha_blend = use_alpha;
			}

			gfx_rapi->shader_get_info(prg, &shader.num_inputs, shader.used_textures);

			//applyTextures();

			// checkViewport();
		}

		void applyTextures()
		{
			for(int i = 0; i < 2; i++)
			{
				if(shader.used_textures[i])
				{
					setTile(i);

					if(rendering_state.textures[i])
					{
						if(useLinearFilter() != rendering_state.textures[i]->linear_filter || texture_tile.cms != rendering_state.textures[i]->cms || texture_tile.cmt != rendering_state.textures[i]->cmt)
						{
							flush();

							rendering_state.textures[i]->linear_filter = useLinearFilter();
							rendering_state.textures[i]->cms	   = texture_tile.cms;
							rendering_state.textures[i]->cmt	   = texture_tile.cmt;

							gfx_rapi->set_sampler_parameters(i, *rendering_state.textures[i]);
						}
					}
				}
			}
		}

		void setTile(int tile)
		{
			if(m_textures_changed[tile])
			{
				flush();
				import_texture(tile);
				m_textures_changed[tile] = false;
				//refresh();
			}
		}

		void setTexturesChangedA(bool value)
		{
			if(value != m_textures_changed[0])
			{
				m_textures_changed[0] = value;
				//refresh();
			}
		}

		bool textureChanged(u8 index) const
		{
			return m_textures_changed[index];
		}

		void setTexturesChanged(u8 index, bool value)
		{
			m_textures_changed[index] = value;
			//refresh();
		}

		void setTexturesChangedB(bool value)
		{
			m_textures_changed[1] = value;
			//refresh();
		}

		void setTexturesChangedAB(bool a, bool b)
		{
			m_textures_changed[0] = a;
			m_textures_changed[1] = b;
			//refresh();
		}

		void setTexturesChanged(s8 a = -1, s8 b = -1)
		{
			m_textures_changed[0] = a;
			m_textures_changed[1] = b;
			//refresh();
		}

		void setViewportChanged()
		{
			m_viewport_or_scissor_changed = true;
		}

		void checkViewport()
		{
			if(m_viewport_or_scissor_changed)
			{
				if(memcmp(&m_viewport, &rendering_state.viewport, sizeof(m_viewport)) != 0)
				{
					flush();
					gfx_rapi->set_viewport(m_viewport.x, m_viewport.y, m_viewport.width, m_viewport.height);
					rendering_state.viewport = m_viewport;
				}

				if(memcmp(&m_scissor, &rendering_state.scissor, sizeof(m_scissor)) != 0)
				{
					flush();
					gfx_rapi->set_scissor(m_scissor.x, m_scissor.y, m_scissor.width, m_scissor.height);
					rendering_state.scissor = m_scissor;
				}

				m_viewport_or_scissor_changed = false;
				//refresh();
			}
		}

		const XYWidthHeight& viewport()
		{
			return m_viewport;
		}

		void setViewport(const XYWidthHeight& viewport)
		{
			if(m_viewport != viewport)
			{
				m_viewport		      = viewport;
				m_viewport_or_scissor_changed = true;
			}
		}

		void setScissor(const XYWidthHeight& scissor)
		{
			if(m_scissor != scissor)
			{
				m_scissor		      = scissor;
				m_viewport_or_scissor_changed = true;
			}
		}

		u64 hash() const
		{
			XXHash64 h(0);
			h.add(&m_other_mode_l, sizeof(m_other_mode_l));
			h.add(&m_other_mode_l, sizeof(m_other_mode_h));
			h.add(&m_combine_mode, sizeof(m_combine_mode));
			return h.hash();
		}

		const u8* palette;

		struct
		{
			const u8* addr;
			u8 siz;
			u8 tile_number;
		} texture_to_load;

		struct
		{
			const u8* addr;
			u32 size_bytes;
		} loaded_texture[2];

		struct
		{
			u8 fmt;
			u8 siz;
			u8 cms, cmt;
			u16 uls, ult, lrs, lrt; // U10.2
			u32 line_size_bytes;
		} texture_tile;

		bool m_textures_changed[2];

		u32 m_other_mode_l;
		u32 m_other_mode_h;
		u32 m_combine_mode;

		struct Shader
		{
			u8 num_inputs;
			bool used_textures[2];

			bool useTextures() const
			{
				return used_textures[0] || used_textures[1];
			}
		} shader;

		RGBA env_color;
		RGBA prim_color;
		RGBA fog_color;
		RGBA fill_color;

		XYWidthHeight m_viewport;
		XYWidthHeight m_scissor;

		bool m_viewport_or_scissor_changed;
		const void* z_buf_address;
		const void* color_image_address;

		const ColorCombiner* comb;

		bool m_transformed;
	};

	static RSP rsp;
	static RDP rdp;

	void flush()
	{
		if(buf_vbo_len > 0)
		{
			if(rdp.isTransformed())
			{
				auto& vbo = nextVbo();
				vbo.upload(buf_vbo, buf_vbo_len);
				gfx_rapi->draw_triangles(vbo.handle, buf_vbo_num_tris, nullptr);
				// vbo.upload(nullptr, 0);
			}
			else
			{
				auto& vbo = nextVbo();
				vbo.upload(buf_vbo, buf_vbo_len);
				gfx_rapi->draw_triangles(vbo.handle, buf_vbo_num_tris, rsp.matrix());
				// vbo.upload(nullptr, 0);
				/*auto key = XXHash64::hash(buf_vbo, buf_vbo_len, 0);

				if (g_triCache.count(key))
				{
					const auto& vbo = *g_triCache[key];
					gfx_rapi->draw_triangles(vbo.handle, vbo.num_tris, rsp.matrix());
				}
				else
				{

					auto handle = gfx_rapi->create_vbo(buf_vbo, buf_vbo_len);
					gfx_rapi->draw_triangles(handle, buf_vbo_num_tris, rsp.matrix());
					g_triCache[key] = std::make_shared<Vbo>(handle, buf_vbo_num_tris);
				}*/
			}

			buf_vbo_len	 = 0;
			buf_vbo_num_tris = 0;
		}
	}

	void init()
	{
		gfx_wapi = new platform::Sdl("SM64", IS_FULL_SCREEN);
		gfx_rapi = new opengl::Opengl();
		// Used in the 120 star TAS
		static u32 precomp_shaders[] = {0x01200200, 0x00000045, 0x00000200, 0x01200a00, 0x00000a00, 0x01a00045, 0x00000551, 0x01045045, 0x05a00a00, 0x01200045, 0x05045045, 0x01045a00, 0x01a00a00,
						0x0000038d, 0x01081081, 0x0120038d, 0x03200045, 0x03200a00, 0x01a00a6f, 0x01141045, 0x07a00a00, 0x05200200, 0x03200200, 0x09200200, 0x0920038d, 0x09200045};

		for(size_t i = 0; i < sizeof(precomp_shaders) / sizeof(u32); i++)
		{
			lookup_or_create_shader_program(precomp_shaders[i]);
		}
	}

	static ShaderProgram* lookup_or_create_shader_program(u32 shader_id)
	{
		struct ShaderProgram* prg = gfx_rapi->lookup_shader(shader_id);

		if(prg == NULL)
		{
			gfx_rapi->unload_shader(rendering_state.shader_program);
			prg			       = gfx_rapi->create_and_load_new_shader(shader_id);
			rendering_state.shader_program = prg;
		}

		return prg;
	}

	static void generate_cc(ColorCombiner* comb, u32 cc_id)
	{
		u8 c[2][4];
		u32 shader_id		      = (cc_id >> 24) << 24;
		u8 shader_input_mapping[2][4] = {{0}};

		for(int i = 0; i < 4; i++)
		{
			c[0][i] = (cc_id >> (i * 3)) & 7;
			c[1][i] = (cc_id >> (12 + i * 3)) & 7;
		}

		for(int i = 0; i < 2; i++)
		{
			if(c[i][0] == c[i][1] || c[i][2] == CC_0)
			{
				c[i][0] = c[i][1] = c[i][2] = 0;
			}
			u8 input_number[8]    = {0};
			int next_input_number = SHADER_INPUT_1;
			for(int j = 0; j < 4; j++)
			{
				int val = 0;
				switch(c[i][j])
				{
					case CC_0:
						break;
					case CC_TEXEL0:
						val = SHADER_TEXEL0;
						break;
					case CC_TEXEL1:
						val = SHADER_TEXEL1;
						break;
					case CC_TEXEL0A:
						val = SHADER_TEXEL0A;
						break;
					case CC_PRIM:
					case CC_SHADE:
					case CC_ENV:
					case CC_LOD:
						if(input_number[c[i][j]] == 0)
						{
							shader_input_mapping[i][next_input_number - 1] = c[i][j];
							input_number[c[i][j]]			       = next_input_number++;
						}
						val = input_number[c[i][j]];
						break;
				}
				shader_id |= val << (i * 12 + j * 3);
			}
		}
		comb->cc_id = cc_id;
		comb->prg   = lookup_or_create_shader_program(shader_id);
		memcpy(comb->shader_input_mapping, shader_input_mapping, sizeof(shader_input_mapping));
	}

	static const ColorCombiner* gfx_lookup_or_create_color_combiner(u32 cc_id)
	{
		if(prev_combiner != NULL && prev_combiner->cc_id == cc_id)
		{
			return prev_combiner;
		}

		for(const auto& a : color_combiner_pool)
		{
			if(a.cc_id == cc_id)
			{
				return prev_combiner = &a;
			}
		}

#ifdef DEBUG
		if(color_combiner_pool_size >= 63)
		{
			return nullptr;
		}
#endif

		flush();
		struct ColorCombiner* comb = &color_combiner_pool[color_combiner_pool_size++];
		generate_cc(comb, cc_id);
		return prev_combiner = comb;
	}

	static constexpr u64 CacheKey(const u8* address, u8 format, u8 size)
	{
		return ((u64)address & 0x0000FFFFFFFFFFFF) | ((u64)format << (64 - 8)) | ((u64)size << (64 - 16));
	}

	static bool gfx_texture_cache_lookup(int tile, struct TextureNode** n, const u8* orig_addr, u32 fmt, u32 siz)
	{
		const auto key = CacheKey(orig_addr, fmt, siz);
		auto& node     = g_textureCache[key];
		*n	       = &node;

		if(node.isValid())
		{
			gfx_rapi->select_texture(tile, node);

			return true;
		}

		node.texture_id = gfx_rapi->new_texture();

		gfx_rapi->select_texture(tile, node);
		gfx_rapi->set_sampler_parameters(tile, node);
		node.cms	   = 0;
		node.cmt	   = 0;
		node.linear_filter = false;
		node.texture_addr  = orig_addr;
		node.fmt	   = fmt;
		node.siz	   = siz;
		return false;
	}

	static void import_texture_rgba16(int tile, TextureNode& node)
	{
		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes / 2; i++)
		{
			u16 col16	      = (rdp.loaded_texture[tile].addr[2 * i] << 8) | rdp.loaded_texture[tile].addr[2 * i + 1];
			u8 a		      = col16 & 1;
			u8 r		      = col16 >> 11;
			u8 g		      = (col16 >> 6) & 0x1f;
			u8 b		      = (col16 >> 1) & 0x1f;
			rgba32_buf[4 * i + 0] = SCALE_5_8(r);
			rgba32_buf[4 * i + 1] = SCALE_5_8(g);
			rgba32_buf[4 * i + 2] = SCALE_5_8(b);
			rgba32_buf[4 * i + 3] = a ? 255 : 0;
		}

		u32 width  = rdp.texture_tile.line_size_bytes / 2;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_rgba32(int tile, TextureNode& node)
	{
		u32 width  = rdp.texture_tile.line_size_bytes / 2;
		u32 height = (rdp.loaded_texture[tile].size_bytes / 2) / rdp.texture_tile.line_size_bytes;
		gfx_rapi->upload_texture(rdp.loaded_texture[tile].addr, width, height, node);
	}

	static void import_texture_ia4(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[32768];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes * 2; i++)
		{
			u8 byte		      = rdp.loaded_texture[tile].addr[i / 2];
			u8 part		      = (byte >> (4 - (i % 2) * 4)) & 0xf;
			u8 intensity	      = part >> 1;
			u8 alpha	      = part & 1;
			u8 r		      = intensity;
			u8 g		      = intensity;
			u8 b		      = intensity;
			rgba32_buf[4 * i + 0] = SCALE_3_8(r);
			rgba32_buf[4 * i + 1] = SCALE_3_8(g);
			rgba32_buf[4 * i + 2] = SCALE_3_8(b);
			rgba32_buf[4 * i + 3] = alpha ? 255 : 0;
		}

		u32 width  = rdp.texture_tile.line_size_bytes * 2;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_ia8(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[16384];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes; i++)
		{
			u8 intensity	      = rdp.loaded_texture[tile].addr[i] >> 4;
			u8 alpha	      = rdp.loaded_texture[tile].addr[i] & 0xf;
			u8 r		      = intensity;
			u8 g		      = intensity;
			u8 b		      = intensity;
			rgba32_buf[4 * i + 0] = SCALE_4_8(r);
			rgba32_buf[4 * i + 1] = SCALE_4_8(g);
			rgba32_buf[4 * i + 2] = SCALE_4_8(b);
			rgba32_buf[4 * i + 3] = SCALE_4_8(alpha);
		}

		u32 width  = rdp.texture_tile.line_size_bytes;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_ia16(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[8192];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes / 2; i++)
		{
			u8 intensity	      = rdp.loaded_texture[tile].addr[2 * i];
			u8 alpha	      = rdp.loaded_texture[tile].addr[2 * i + 1];
			u8 r		      = intensity;
			u8 g		      = intensity;
			u8 b		      = intensity;
			rgba32_buf[4 * i + 0] = r;
			rgba32_buf[4 * i + 1] = g;
			rgba32_buf[4 * i + 2] = b;
			rgba32_buf[4 * i + 3] = alpha;
		}

		u32 width  = rdp.texture_tile.line_size_bytes / 2;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_i4(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[32768];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes * 2; i++)
		{
			u8 byte		      = rdp.loaded_texture[tile].addr[i / 2];
			u8 part		      = (byte >> (4 - (i % 2) * 4)) & 0xf;
			u8 intensity	      = part;
			u8 r		      = intensity;
			u8 g		      = intensity;
			u8 b		      = intensity;
			rgba32_buf[4 * i + 0] = SCALE_4_8(r);
			rgba32_buf[4 * i + 1] = SCALE_4_8(g);
			rgba32_buf[4 * i + 2] = SCALE_4_8(b);
			rgba32_buf[4 * i + 3] = 255;
		}

		u32 width  = rdp.texture_tile.line_size_bytes * 2;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_i8(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[16384];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes; i++)
		{
			u8 intensity	      = rdp.loaded_texture[tile].addr[i];
			u8 r		      = intensity;
			u8 g		      = intensity;
			u8 b		      = intensity;
			rgba32_buf[4 * i + 0] = r;
			rgba32_buf[4 * i + 1] = g;
			rgba32_buf[4 * i + 2] = b;
			rgba32_buf[4 * i + 3] = 255;
		}

		u32 width  = rdp.texture_tile.line_size_bytes;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_ci4(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[32768];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes * 2; i++)
		{
			u8 byte		      = rdp.loaded_texture[tile].addr[i / 2];
			u8 idx		      = (byte >> (4 - (i % 2) * 4)) & 0xf;
			u16 col16	      = (rdp.palette[idx * 2] << 8) | rdp.palette[idx * 2 + 1]; // Big endian load
			u8 a		      = col16 & 1;
			u8 r		      = col16 >> 11;
			u8 g		      = (col16 >> 6) & 0x1f;
			u8 b		      = (col16 >> 1) & 0x1f;
			rgba32_buf[4 * i + 0] = SCALE_5_8(r);
			rgba32_buf[4 * i + 1] = SCALE_5_8(g);
			rgba32_buf[4 * i + 2] = SCALE_5_8(b);
			rgba32_buf[4 * i + 3] = a ? 255 : 0;
		}

		u32 width  = rdp.texture_tile.line_size_bytes * 2;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	static void import_texture_ci8(int tile, TextureNode& node)
	{
		// u8 rgba32_buf[16384];

		for(u32 i = 0; i < rdp.loaded_texture[tile].size_bytes; i++)
		{
			u8 idx		      = rdp.loaded_texture[tile].addr[i];
			u16 col16	      = (rdp.palette[idx * 2] << 8) | rdp.palette[idx * 2 + 1]; // Big endian load
			u8 a		      = col16 & 1;
			u8 r		      = col16 >> 11;
			u8 g		      = (col16 >> 6) & 0x1f;
			u8 b		      = (col16 >> 1) & 0x1f;
			rgba32_buf[4 * i + 0] = SCALE_5_8(r);
			rgba32_buf[4 * i + 1] = SCALE_5_8(g);
			rgba32_buf[4 * i + 2] = SCALE_5_8(b);
			rgba32_buf[4 * i + 3] = a ? 255 : 0;
		}

		u32 width  = rdp.texture_tile.line_size_bytes;
		u32 height = rdp.loaded_texture[tile].size_bytes / rdp.texture_tile.line_size_bytes;

		gfx_rapi->upload_texture(rgba32_buf, width, height, node);
	}

	struct AssetHeader
	{
		u64 magic;
		u64 xxhash;

		bool isValid() const
		{
			return magic == 0x52444c5445535341;
		}
	};

	static void import_texture(int tile)
	{
		u8 fmt = rdp.texture_tile.fmt;
		u8 siz = rdp.texture_tile.siz;

		if(gfx_texture_cache_lookup(tile, &rendering_state.textures[tile], rdp.loaded_texture[tile].addr, fmt, siz))
		{
			return;
		}

#if 0
		auto asset = (const AssetHeader*)rdp.loaded_texture[tile].addr;

		if(rdp.loaded_texture[tile].addr && asset->isValid())
		{
			auto object = sm64::asset::load(asset->xxhash);

			if(object)
			{
				gfx_rapi->upload_texture(object->ptr(), object->width, object->height, *rendering_state.textures[tile]);
				return;
			}
			else
			{
				// TODO PANIC
				return;
			}
		}
		else
		{
			u64 xxhash = XXHash64::hash(rdp.loaded_texture[tile].addr, rdp.loaded_texture[tile].size_bytes, 0);

			auto object = sm64::asset::load(xxhash);

			if(object)
			{
				gfx_rapi->upload_texture(object->ptr(), object->width, object->height, *rendering_state.textures[tile]);
				return;
			}
		}
#else
#endif
		const void* ptr = rdp.loaded_texture[tile].addr;


		//u64 xxhash2 = XXHash64::hash(rdp.loaded_texture[tile].addr, rdp.loaded_texture[tile].size_bytes, 0);

		if(fmt == G_IM_FMT_RGBA)
		{
			if(siz == G_IM_SIZ_16b)
			{
				import_texture_rgba16(tile, *rendering_state.textures[tile]);
			}
			else if(siz == G_IM_SIZ_32b)
			{
				import_texture_rgba32(tile, *rendering_state.textures[tile]);
			}
			else
			{
				abort();
			}
		}
		else if(fmt == G_IM_FMT_IA)
		{
			if(siz == G_IM_SIZ_4b)
			{
				import_texture_ia4(tile, *rendering_state.textures[tile]);
			}
			else if(siz == G_IM_SIZ_8b)
			{
				import_texture_ia8(tile, *rendering_state.textures[tile]);
			}
			else if(siz == G_IM_SIZ_16b)
			{
				import_texture_ia16(tile, *rendering_state.textures[tile]);
			}
			else
			{
				abort();
			}
		}
		else if(fmt == G_IM_FMT_CI)
		{
			if(siz == G_IM_SIZ_4b)
			{
				import_texture_ci4(tile, *rendering_state.textures[tile]);
			}
			else if(siz == G_IM_SIZ_8b)
			{
				import_texture_ci8(tile, *rendering_state.textures[tile]);
			}
			else
			{
				abort();
			}
		}
		else if(fmt == G_IM_FMT_I)
		{
			if(siz == G_IM_SIZ_4b)
			{
				import_texture_i4(tile, *rendering_state.textures[tile]);
			}
			else if(siz == G_IM_SIZ_8b)
			{
				import_texture_i8(tile, *rendering_state.textures[tile]);
			}
			else
			{
				abort();
			}
		}
		else
		{
			abort();
		}
	}

	static void normalize_vector(float v[3])
	{
		float s = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		v[0] /= s;
		v[1] /= s;
		v[2] /= s;
	}

	static void transposed_matrix_mul(float res[3], const float a[3], const float b[4][4])
	{
		res[0] = a[0] * b[0][0] + a[1] * b[0][1] + a[2] * b[0][2];
		res[1] = a[0] * b[1][0] + a[1] * b[1][1] + a[2] * b[1][2];
		res[2] = a[0] * b[2][0] + a[1] * b[2][1] + a[2] * b[2][2];
	}

	static void calculate_normal_dir(const Light_t* light, float coeffs[3])
	{
		float light_dir[3] = {light->dir[0] / 127.0f, light->dir[1] / 127.0f, light->dir[2] / 127.0f};
		transposed_matrix_mul(coeffs, light_dir, rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1]);
		normalize_vector(coeffs);
	}

	static void gfx_matrix_mul(float res[4][4], const float a[4][4], const float b[4][4])
	{
		float tmp[4][4];
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				tmp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
			}
		}
		memcpy(res, tmp, sizeof(tmp));
	}

	typedef float Matrix[4][4];

	static void gfx_sp_matrix(u8 parameters, const u32* addr)
	{
		flush();
		float matrix[4][4]; 

#ifdef GBI_FLOATS
		// For a modified GBI where fixed point values are replaced with floats
        memcpy(addr, addr, sizeof(matrix));
#else
		Mtx* m_temp = (Mtx*)addr;
		Matrix_MtxToMtxF((Mtx*)addr, (MtxF*)&matrix[0][0]);
#endif


		if(parameters & G_MTX_PROJECTION)
		{
			if(parameters & G_MTX_LOAD)
			{
				if(config().game().mirror())
				{
					matrix[0][0] *= -gfx_current_dimensions.adjust_ratio;
				}
				else
				{
					matrix[0][0] *= gfx_current_dimensions.adjust_ratio;
				}

				memcpy(rsp.P_matrix, matrix, sizeof(matrix));
			}
			else
			{
				gfx_matrix_mul(rsp.P_matrix, matrix, rsp.P_matrix);
			}
		}
		else
		{ // G_MTX_MODELVIEW
			if((parameters & G_MTX_PUSH) && rsp.modelview_matrix_stack_size < 11)
			{
				++rsp.modelview_matrix_stack_size;
				memcpy(rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1], rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 2], sizeof(matrix));
			}
			if(parameters & G_MTX_LOAD)
			{
				memcpy(rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1], matrix, sizeof(matrix));
			}
			else
			{
				gfx_matrix_mul(rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1], matrix, rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1]);
			}
			rsp.lights_changed = 1;
		}

		gfx_matrix_mul(rsp.MP_matrix, rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1], rsp.P_matrix);
	}

	static void gfx_sp_pop_matrix(u32 count)
	{
		flush();
		while(count--)
		{
			if(rsp.modelview_matrix_stack_size > 0)
			{
				--rsp.modelview_matrix_stack_size;
				if(rsp.modelview_matrix_stack_size > 0)
				{
					gfx_matrix_mul(rsp.MP_matrix, rsp.modelview_matrix_stack[rsp.modelview_matrix_stack_size - 1], rsp.P_matrix);
				}
			}
		}
	}

	static void gfx_sp_vertex(size_t n_vertices, size_t dest_index, const Vtx* vertices, bool transform = false)
	{
		rdp.setTransformed(transform);
		rsp.verticies.vertices	 = vertices;
		rsp.verticies.dest_index = dest_index;
		rsp.verticies.n_vertices = n_vertices;

		const bool use_lighting	   = rsp.geoModeLighting();
		const bool use_texture_gen = rsp.geoModeTextureGen();
		const bool use_fog	   = rsp.geoModeFog();

		if(use_lighting)
		{
			if(rsp.lights_changed)
			{
				for(int i = 0; i < rsp.current_num_lights - 1; i++)
				{
					calculate_normal_dir(&rsp.current_lights[i], rsp.current_lights_coeffs[i]);
				}
				static const Light_t lookat_x = {{0, 0, 0}, 0, {0, 0, 0}, 0, {127, 0, 0}, 0};
				static const Light_t lookat_y = {{0, 0, 0}, 0, {0, 0, 0}, 0, {0, 127, 0}, 0};
				calculate_normal_dir(&lookat_x, rsp.current_lookat_coeffs[0]);
				calculate_normal_dir(&lookat_y, rsp.current_lookat_coeffs[1]);
				rsp.lights_changed = false;
			}
		}

		for(size_t i = 0; i < n_vertices; i++, dest_index++)
		{
			const Vtx_t& vertex	    = vertices[i].v;
			const Vtx_tn& vertex_normal = vertices[i].n;
			LoadedVertex& d		    = rsp.loaded_vertices[dest_index];

			short U = vertex.tc[0] * rsp.texture_scaling_factor.s >> 16;
			short V = vertex.tc[1] * rsp.texture_scaling_factor.t >> 16;

			if(use_lighting)
			{
				int r = rsp.current_lights[rsp.current_num_lights - 1].col[0];
				int g = rsp.current_lights[rsp.current_num_lights - 1].col[1];
				int b = rsp.current_lights[rsp.current_num_lights - 1].col[2];

				for(int i = 0; i < rsp.current_num_lights - 1; i++)
				{
					float intensity = 0;
					intensity += vertex_normal.n[0] * rsp.current_lights_coeffs[i][0];
					intensity += vertex_normal.n[1] * rsp.current_lights_coeffs[i][1];
					intensity += vertex_normal.n[2] * rsp.current_lights_coeffs[i][2];
					intensity /= 127.0f;
					if(intensity > 0.0f)
					{
						r += intensity * rsp.current_lights[i].col[0];
						g += intensity * rsp.current_lights[i].col[1];
						b += intensity * rsp.current_lights[i].col[2];
					}
				}

				d.color.r = r > 255 ? 255 : r;
				d.color.g = g > 255 ? 255 : g;
				d.color.b = b > 255 ? 255 : b;

				if(use_texture_gen)
				{
					float dotx = 0, doty = 0;
					dotx += vertex_normal.n[0] * rsp.current_lookat_coeffs[0][0];
					dotx += vertex_normal.n[1] * rsp.current_lookat_coeffs[0][1];
					dotx += vertex_normal.n[2] * rsp.current_lookat_coeffs[0][2];
					doty += vertex_normal.n[0] * rsp.current_lookat_coeffs[1][0];
					doty += vertex_normal.n[1] * rsp.current_lookat_coeffs[1][1];
					doty += vertex_normal.n[2] * rsp.current_lookat_coeffs[1][2];

					U = (s32)((dotx / 127.0f + 1.0f) / 4.0f * rsp.texture_scaling_factor.s);
					V = (s32)((doty / 127.0f + 1.0f) / 4.0f * rsp.texture_scaling_factor.t);
				}
			}
			else
			{
				d.color.r = vertex.cn[0];
				d.color.g = vertex.cn[1];
				d.color.b = vertex.cn[2];
			}

			d.u = U;
			d.v = V;

			if(transform)
			{
				d.x = vertex.ob[0] * rsp.MP_matrix[0][0] + vertex.ob[1] * rsp.MP_matrix[1][0] + vertex.ob[2] * rsp.MP_matrix[2][0] + rsp.MP_matrix[3][0];
				d.y = vertex.ob[0] * rsp.MP_matrix[0][1] + vertex.ob[1] * rsp.MP_matrix[1][1] + vertex.ob[2] * rsp.MP_matrix[2][1] + rsp.MP_matrix[3][1];
				d.z = vertex.ob[0] * rsp.MP_matrix[0][2] + vertex.ob[1] * rsp.MP_matrix[1][2] + vertex.ob[2] * rsp.MP_matrix[2][2] + rsp.MP_matrix[3][2];
				d.w = vertex.ob[0] * rsp.MP_matrix[0][3] + vertex.ob[1] * rsp.MP_matrix[1][3] + vertex.ob[2] * rsp.MP_matrix[2][3] + rsp.MP_matrix[3][3];

				d.clip_rej = 0;

				if(d.x < -d.w)
					d.clip_rej |= 1;
				else if(d.x > d.w)
					d.clip_rej |= 2;

				if(d.y < -d.w)
					d.clip_rej |= 4;
				else if(d.y > d.w)
					d.clip_rej |= 8;

				if(d.z < -d.w)
					d.clip_rej |= 16;
				else if(d.z > d.w)
					d.clip_rej |= 32;
			}
			else
			{
				d.x	   = vertex.ob[0];
				d.y	   = vertex.ob[1];
				d.z	   = vertex.ob[2];
				d.w	   = 1.0f;
				d.clip_rej = 0;

				rsp.saveMatrix();
			}

			if(use_fog)
			{
				/*if (transform)
				{
					if(fabsf(d.w) < 0.001f)
					{
						// To avoid division by zero
						d.w = 0.001f;
					}

					float winv = 1.0f / d.w;
					if(winv < 0.0f)
					{
						winv = 32767.0f;
					}

					float fog_z = d.z * winv * rsp.fog_mul + rsp.fog_offset;
					if(fog_z < 0) fog_z = 0;
					if(fog_z > 255) fog_z = 255;
					d.color.a = fog_z; // Use alpha variable to store fog factor
				}
				else
				{
					d.color.a = 0.001f;
					//d.color.a = vertex.cn[3];
				}*/
			}
			else
			{
				d.color.a = vertex.cn[3];
			}
		}
	}

	static void gfx_sp_tri1(u32 vtx1_idx, u32 vtx2_idx, u32 vtx3_idx)
	{
		const LoadedVertex& v1 = rsp.loaded_vertices[vtx1_idx];
		const LoadedVertex& v2 = rsp.loaded_vertices[vtx2_idx];
		const LoadedVertex& v3 = rsp.loaded_vertices[vtx3_idx];

		const LoadedVertex* v_arr[3] = {&v1, &v2, &v3};

		if(rdp.isTransformed())
		{
			if(v1.clip_rej & v2.clip_rej & v3.clip_rej)
			{
				// The whole triangle lies outside the visible area
				return;
			}

			if(rsp.geoModeCullBoth() != 0)
			{
				float dx1   = v1.x / (v1.w) - v2.x / (v2.w);
				float dy1   = v1.y / (v1.w) - v2.y / (v2.w);
				float dx2   = v3.x / (v3.w) - v2.x / (v2.w);
				float dy2   = v3.y / (v3.w) - v2.y / (v2.w);
				float cross = dx1 * dy2 - dy1 * dx2;

				if((v1.w < 0) ^ (v2.w < 0) ^ (v3.w < 0))
				{
					// If one vertex lies behind the eye, negating cross will give the correct result.
					// If all vertices lie behind the eye, the triangle will be rejected anyway.
					cross = -cross;
				}

				if(config().game().mirror())
				{
					switch(rsp.geoModeCullBoth())
					{
						case G_CULL_FRONT:
							if(cross >= 0)
								return;
							break;
						case G_CULL_BACK:
							if(cross <= 0)
								return;
							break;
						case G_CULL_BOTH:
							// Why is this even an option?
							return;
					}
				}
				else
				{
					switch(rsp.geoModeCullBoth())
					{
						case G_CULL_FRONT:
							if(cross <= 0)
								return;
							break;
						case G_CULL_BACK:
							if(cross >= 0)
								return;
							break;
						case G_CULL_BOTH:
							// Why is this even an option?
							return;
					}
				}
			}
		}
		
		rdp.checkViewport();
		rdp.refresh();
		rdp.applyTextures();

		// hmm

		bool use_texture = rdp.shader.used_textures[0] || rdp.shader.used_textures[1];
		u32 tex_width	 = (rdp.texture_tile.lrs - rdp.texture_tile.uls + 4) / 4;
		u32 tex_height	 = (rdp.texture_tile.lrt - rdp.texture_tile.ult + 4) / 4;

#ifdef ENABLE_Z_TEST
		bool z_is_from_0_to_1 = gfx_rapi->z_is_from_0_to_1();
#endif

		for(int i = 0; i < 3; i++)
		{
			float z = v_arr[i]->z;
			float w = v_arr[i]->w;
#ifdef ENABLE_Z_TEST
			if(z_is_from_0_to_1)
			{
				z = (z + w) / 2.0f;
			}
#endif
			buf_vbo[buf_vbo_len++] = v_arr[i]->x;
			buf_vbo[buf_vbo_len++] = v_arr[i]->y;
			buf_vbo[buf_vbo_len++] = z;
			buf_vbo[buf_vbo_len++] = w;

			if(use_texture)
			{
				float u = (v_arr[i]->u - rdp.texture_tile.uls * 8) / 32.0f;
				float v = (v_arr[i]->v - rdp.texture_tile.ult * 8) / 32.0f;
				if(rdp.useLinearFilter())
				{
					// Linear filter adds 0.5f to the coordinates
					u += 0.5f;
					v += 0.5f;
				}
				buf_vbo[buf_vbo_len++] = u / tex_width;
				buf_vbo[buf_vbo_len++] = v / tex_height;
			}

			/*if (rdp.useFog())
			{
				buf_vbo[buf_vbo_len++] = rdp.fog_color.r / 255.0f;
				buf_vbo[buf_vbo_len++] = rdp.fog_color.g / 255.0f;
				buf_vbo[buf_vbo_len++] = rdp.fog_color.b / 255.0f;
				buf_vbo[buf_vbo_len++] = v_arr[i]->color.a / 255.0f; // fog factor (not alpha)
			}*/

			RGBA tmp;
			for(int j = 0; j < rdp.shader.num_inputs; j++)
			{
				const RGBA* color;
				const u8 len = 1 + (rdp.useAlpha() ? 1 : 0);

				for(int k = 0; k < len; k++)
				{
					switch(rdp.comb->shader_input_mapping[k][j])
					{
						case CC_PRIM:
							color = &rdp.prim_color;
							break;
						case CC_SHADE:
							color = &v_arr[i]->color;
							break;
						case CC_ENV:
							color = &rdp.env_color;
							break;
						case CC_LOD:
							if(rdp.isTransformed())
							{
								float distance_frac = (v1.w - 3000.0f) / 3000.0f;
								if(distance_frac < 0.0f)
									distance_frac = 0.0f;
								if(distance_frac > 1.0f)
									distance_frac = 1.0f;
								tmp.r = tmp.g = tmp.b = tmp.a = distance_frac * 255.0f;
								color			      = &tmp;
								break;
							}
						default:
							memset(&tmp, 0, sizeof(tmp));
							color = &tmp;
							break;
					}

					if(k == 0)
					{
						buf_vbo[buf_vbo_len++] = color->r / 255.0f;
						buf_vbo[buf_vbo_len++] = color->g / 255.0f;
						buf_vbo[buf_vbo_len++] = color->b / 255.0f;
					}
					else
					{
						if(rdp.useFog() && color == &v_arr[i]->color)
						{
							// Shade alpha is 100% for fog
							buf_vbo[buf_vbo_len++] = 1.0f;
						}
						else
						{
							buf_vbo[buf_vbo_len++] = color->a / 255.0f;
						}
					}
				}
			}
		}
		if(++buf_vbo_num_tris == MAX_BUFFERED)
		{
			flush();
		}
	}

	static bool gfx_sp_tri_buffer2(const TriIndex* triIndex, u32 count)
	{
		bool cache	     = true;
		const u32 tex_width  = (rdp.texture_tile.lrs - rdp.texture_tile.uls + 4) / 4;
		const u32 tex_height = (rdp.texture_tile.lrt - rdp.texture_tile.ult + 4) / 4;

		rdp.refresh();

		// rdp.checkViewport();

		while(count > 0)
		{
			count--;
			const auto& index      = triIndex->index;
			const LoadedVertex& v1 = rsp.loaded_vertices[index[0]];
			const LoadedVertex& v2 = rsp.loaded_vertices[index[1]];
			const LoadedVertex& v3 = rsp.loaded_vertices[index[2]];
			triIndex++;

			const LoadedVertex* v_arr[3] = {&v1, &v2, &v3};

#ifdef ENABLE_Z_TEST
			bool z_is_from_0_to_1 = gfx_rapi->z_is_from_0_to_1();
#endif

			for(int i = 0; i < 3; i++)
			{
				float z = v_arr[i]->z;
				float w = v_arr[i]->w;
#ifdef ENABLE_Z_TEST
				if(z_is_from_0_to_1)
				{
					z = (z + w) / 2.0f;
				}
#endif
				buf_vbo[buf_vbo_len++] = v_arr[i]->x;
				buf_vbo[buf_vbo_len++] = v_arr[i]->y;
				buf_vbo[buf_vbo_len++] = z;
				buf_vbo[buf_vbo_len++] = w;

				if(rdp.shader.useTextures())
				{
					float u = (v_arr[i]->u - rdp.texture_tile.uls * 8) / 32.0f;
					float v = (v_arr[i]->v - rdp.texture_tile.ult * 8) / 32.0f;

					if(rdp.useLinearFilter())
					{
						// Linear filter adds 0.5f to the coordinates
						u += 0.5f;
						v += 0.5f;
					}

					buf_vbo[buf_vbo_len++] = u / tex_width;
					buf_vbo[buf_vbo_len++] = v / tex_height;
				}

				/*if (rdp.useFog())
				{
					buf_vbo[buf_vbo_len++] = rdp.fog_color.r / 255.0f;
					buf_vbo[buf_vbo_len++] = rdp.fog_color.g / 255.0f;
					buf_vbo[buf_vbo_len++] = rdp.fog_color.b / 255.0f;
					buf_vbo[buf_vbo_len++] = v_arr[i]->color.a / 255.0f; // fog factor (not alpha)
				}*/

				RGBA tmp;
				for(int j = 0; j < rdp.shader.num_inputs; j++)
				{
					const RGBA* color;
					const u8 len = 1 + (rdp.useAlpha() ? 1 : 0);

					for(int k = 0; k < len; k++)
					{
						switch(rdp.comb->shader_input_mapping[k][j])
						{
							case CC_PRIM:
								color = &rdp.prim_color;
								break;
							case CC_SHADE:
								color = &v_arr[i]->color;
								break;
							case CC_ENV:
								color = &rdp.env_color;
								break;
							case CC_LOD:
							{
								float distance_frac = (v1.w - 3000.0f) / 3000.0f;
								if(distance_frac < 0.0f)
									distance_frac = 0.0f;
								if(distance_frac > 1.0f)
									distance_frac = 1.0f;
								tmp.r = tmp.g = tmp.b = tmp.a = distance_frac * 255.0f;
								color			      = &tmp;
								break;
							}
							default:
								memset(&tmp, 0, sizeof(tmp));
								color = &tmp;
								break;
						}

						if(k == 0)
						{
							buf_vbo[buf_vbo_len++] = color->r / 255.0f;
							buf_vbo[buf_vbo_len++] = color->g / 255.0f;
							buf_vbo[buf_vbo_len++] = color->b / 255.0f;
						}
						else
						{
							if(rdp.useFog() && color == &v_arr[i]->color)
							{
								// Shade alpha is 100% for fog
								buf_vbo[buf_vbo_len++] = 1.0f;
							}
							else
							{
								buf_vbo[buf_vbo_len++] = color->a / 255.0f;
							}
						}
					}
				}
			}

			if(++buf_vbo_num_tris == MAX_BUFFERED)
			{
				cache = false;
				flush();
			}
		}

		return cache;
	}

	static void gfx_sp_tri_buffer(const TriIndex* triIndex, u64 count)
	{
		rdp.refresh();
		rdp.applyTextures();

		if(!rdp.isTransformed())
		{
			u64 hashes[2];
			hashes[0] = XXHash64::hash(rsp.verticies.vertices, sizeof(Vtx) * rsp.verticies.n_vertices, 0);
			hashes[1] = XXHash64::hash(triIndex, count * 3 * sizeof(float), u64(rdp.hash() + rsp.hash()));

			auto key = XXHash64::hash(&hashes, sizeof(hashes), 0);

			if(g_triCache.count(key))
			{
				flush();

				rdp.refresh();

				rdp.checkViewport();

				const auto& vbo = *g_triCache[key];
				gfx_rapi->draw_triangles(vbo.handle, vbo.num_tris, rsp.matrix());
				return;
			}

			gfx_sp_tri_buffer2(triIndex, count);

			auto handle = gfx_rapi->create_vbo(buf_vbo, buf_vbo_len);
			gfx_rapi->draw_triangles(handle, buf_vbo_num_tris, rsp.matrix());
			g_triCache[key] = std::make_shared<Vbo>(handle, buf_vbo_num_tris);

			buf_vbo_len	 = 0;
			buf_vbo_num_tris = 0;
		}
		else
		{
			gfx_sp_tri_buffer2(triIndex, count);
			flush();
			/*auto& vbo = nextVbo();
			vbo.upload(buf_vbo, buf_vbo_len);
			gfx_rapi->draw_triangles(vbo.handle, buf_vbo_num_tris, rsp.matrix());*/
		}
	}

	static void gfx_sp_geometry_mode(u32 clear, u32 set)
	{
		rsp.setGeometryMode((rsp.geometryMode() & ~clear) | set);
	}

	static void gfx_calc_and_set_viewport(const Vp_t* viewport)
	{
		// 2 bits fraction
		float width  = 2.0f * viewport->vscale[0] / 4.0f;
		float height = 2.0f * viewport->vscale[1] / 4.0f;
		float x	     = (viewport->vtrans[0] / 4.0f) - width / 2.0f;
		float y	     = SCREEN_HEIGHT - ((viewport->vtrans[1] / 4.0f) + height / 2.0f);

		width *= RATIO_X;
		height *= RATIO_Y;
		x *= RATIO_X;
		y *= RATIO_Y;

		rdp.setViewport(XYWidthHeight(x, y, width, height));
	}

	static void gfx_sp_movemem(u8 index, u8 offset, const void* data)
	{
		switch(index)
		{
			case G_MV_VIEWPORT:
				gfx_calc_and_set_viewport((const Vp_t*)data);
				break;
#if 0
		case G_MV_LOOKATY:
		case G_MV_LOOKATX:
			memcpy(rsp.current_lookat + (index - G_MV_LOOKATY) / 2, data, sizeof(Light_t));
			//rsp.lights_changed = 1;
			break;
#endif
			case G_MV_LIGHT:
			{
				int lightidx = offset / 24 - 2;
				if(lightidx >= 0 && lightidx <= MAX_LIGHTS)
				{	// skip lookat
					// NOTE: reads out of bounds if it is an ambient light
					memcpy(rsp.current_lights + lightidx, data, sizeof(Light_t));
				}
				break;
			}
		}
	}

	static void gfx_sp_moveword(u8 index, u16 offset, u32 data)
	{
		switch(index)
		{
			case G_MW_NUMLIGHT:
#ifdef F3DEX_GBI_2
				rsp.current_num_lights = data / 24 + 1; // add ambient light
#else
				// Ambient light is included
				// The 31th bit is a flag that lights should be recalculated
				rsp.current_num_lights = (data - 0x80000000U) / 32;
#endif
				rsp.lights_changed = 1;
				break;
			case G_MW_FOG:
				rsp.setFogMetrics((s16)(data >> 16), (s16)data);
				break;
		}
	}

	static void gfx_sp_texture(u16 sc, u16 tc, u8 level, u8 tile, u8 on)
	{
		rsp.texture_scaling_factor.s = sc;
		rsp.texture_scaling_factor.t = tc;
	}

	static void gfx_dp_set_scissor(u32 mode, u32 ulx, u32 uly, u32 lrx, u32 lry)
	{
		float x	     = ulx / 4.0f * RATIO_X;
		float y	     = (SCREEN_HEIGHT - lry / 4.0f) * RATIO_Y;
		float width  = (lrx - ulx) / 4.0f * RATIO_X;
		float height = (lry - uly) / 4.0f * RATIO_Y;

		rdp.setScissor(XYWidthHeight(x, y, width, height));
	}

	static void gfx_dp_set_texture_image(u32 format, u32 size, u32 width, const void* addr)
	{
		rdp.texture_to_load.addr = (const u8*)addr;
		rdp.texture_to_load.siz	 = size;
	}

	static void gfx_dp_set_tile(u8 fmt, u32 siz, u32 line, u32 tmem, u8 tile, u32 palette, u32 cmt, u32 maskt, u32 shiftt, u32 cms, u32 masks, u32 shifts)
	{
		if(tile == G_TX_RENDERTILE)
		{
			SUPPORT_CHECK(palette == 0); // palette should set upper 4 bits of color index in 4b mode
			rdp.texture_tile.fmt		 = fmt;
			rdp.texture_tile.siz		 = siz;
			rdp.texture_tile.cms		 = cms;
			rdp.texture_tile.cmt		 = cmt;
			rdp.texture_tile.line_size_bytes = line * 8;
			rdp.setTexturesChangedAB(true, true);
		}

		if(tile == G_TX_LOADTILE)
		{
			rdp.texture_to_load.tile_number = tmem / 256;
		}
	}

	static void gfx_dp_set_tile_size(u8 tile, u16 uls, u16 ult, u16 lrs, u16 lrt)
	{
		if(tile == G_TX_RENDERTILE)
		{
			rdp.texture_tile.uls = uls;
			rdp.texture_tile.ult = ult;
			rdp.texture_tile.lrs = lrs;
			rdp.texture_tile.lrt = lrt;
			rdp.setTexturesChangedAB(true, true);
		}
	}

	static void gfx_dp_load_tlut(u8 tile, u32 high_index)
	{
		SUPPORT_CHECK(tile == G_TX_LOADTILE);
		SUPPORT_CHECK(rdp.texture_to_load.siz == G_IM_SIZ_16b);
		rdp.palette = rdp.texture_to_load.addr;
	}

	static void gfx_dp_load_block(u8 tile, u32 uls, u32 ult, u32 lrs, u32 dxt)
	{
		if(tile == 1)
			return;
		SUPPORT_CHECK(tile == G_TX_LOADTILE);
		SUPPORT_CHECK(uls == 0);
		SUPPORT_CHECK(ult == 0);

		// The lrs field rather seems to be number of pixels to load
		u32 word_size_shift;
		switch(rdp.texture_to_load.siz)
		{
			case G_IM_SIZ_4b:
				word_size_shift = 0; // Or -1? It's size in SM64 anyway.
				break;
			case G_IM_SIZ_8b:
				word_size_shift = 0;
				break;
			case G_IM_SIZ_16b:
				word_size_shift = 1;
				break;
			case G_IM_SIZ_32b:
				word_size_shift = 2;
				break;
		}
		u32 size_bytes						       = (lrs + 1) << word_size_shift;
		rdp.loaded_texture[rdp.texture_to_load.tile_number].size_bytes = size_bytes;
		// assert(size_bytes <= 4096 && "bug: too big texture");
		rdp.loaded_texture[rdp.texture_to_load.tile_number].addr = rdp.texture_to_load.addr;

		rdp.setTexturesChanged(rdp.texture_to_load.tile_number, true);
	}

	static void dp_load_tile(u8 tile, u32 uls, u32 ult, u32 lrs, u32 lrt)
	{
		if(tile == 1)
			return;
		SUPPORT_CHECK(tile == G_TX_LOADTILE);
		SUPPORT_CHECK(uls == 0);
		SUPPORT_CHECK(ult == 0);

		u32 word_size_shift;
		switch(rdp.texture_to_load.siz)
		{
			case G_IM_SIZ_4b:
				word_size_shift = 0;
				break;
			case G_IM_SIZ_8b:
				word_size_shift = 0;
				break;
			case G_IM_SIZ_16b:
				word_size_shift = 1;
				break;
			case G_IM_SIZ_32b:
				word_size_shift = 2;
				break;
		}

		u32 size_bytes						       = (((lrs >> G_TEXTURE_IMAGE_FRAC) + 1) * ((lrt >> G_TEXTURE_IMAGE_FRAC) + 1)) << word_size_shift;
		rdp.loaded_texture[rdp.texture_to_load.tile_number].size_bytes = size_bytes;

		// assert(size_bytes <= 4096 && "bug: too big texture");
		rdp.loaded_texture[rdp.texture_to_load.tile_number].addr = rdp.texture_to_load.addr;
		rdp.texture_tile.uls					 = uls;
		rdp.texture_tile.ult					 = ult;
		rdp.texture_tile.lrs					 = lrs;
		rdp.texture_tile.lrt					 = lrt;

		rdp.setTexturesChanged(rdp.texture_to_load.tile_number, true);
	}

	static u8 color_comb_component(u32 v)
	{
		switch(v)
		{
			case G_CCMUX_TEXEL0:
				return CC_TEXEL0;
			case G_CCMUX_TEXEL1:
				return CC_TEXEL1;
			case G_CCMUX_PRIMITIVE:
				return CC_PRIM;
			case G_CCMUX_SHADE:
				return CC_SHADE;
			case G_CCMUX_ENVIRONMENT:
				return CC_ENV;
			case G_CCMUX_TEXEL0_ALPHA:
				return CC_TEXEL0A;
			case G_CCMUX_LOD_FRACTION:
				return CC_LOD;
			default:
				return CC_0;
		}
	}

	static inline u32 color_comb(u32 a, u32 b, u32 c, u32 d)
	{
		return color_comb_component(a) | (color_comb_component(b) << 3) | (color_comb_component(c) << 6) | (color_comb_component(d) << 9);
	}

	static void dp_set_combine_mode(u32 rgb, u32 alpha)
	{
		rdp.setCombineMode(rgb | (alpha << 12));
	}

	static void dp_set_env_color(u8 r, u8 g, u8 b, u8 a)
	{
		rdp.env_color.r = r;
		rdp.env_color.g = g;
		rdp.env_color.b = b;
		rdp.env_color.a = a;
	}

	static void dp_set_prim_color(u8 r, u8 g, u8 b, u8 a)
	{
		rdp.prim_color.r = r;
		rdp.prim_color.g = g;
		rdp.prim_color.b = b;
		rdp.prim_color.a = a;
	}

	static void dp_set_fill_color(u32 packed_color)
	{
		u16 col16	 = (u16)packed_color;
		u32 r		 = col16 >> 11;
		u32 g		 = (col16 >> 6) & 0x1f;
		u32 b		 = (col16 >> 1) & 0x1f;
		u32 a		 = col16 & 1;
		rdp.fill_color.r = SCALE_5_8(r);
		rdp.fill_color.g = SCALE_5_8(g);
		rdp.fill_color.b = SCALE_5_8(b);
		rdp.fill_color.a = a * 255;
	}

	static void draw_rectangle(s32 ulx, s32 uly, s32 lrx, s32 lry)
	{
		rdp.setTransformed(true);
		u32 saved_other_mode_h = rdp.otherModeH();
		const auto cycle_type  = rdp.cycleType();

		if(cycle_type == G_CYC_COPY)
		{
			rdp.setOtherModeH((saved_other_mode_h & ~(3U << G_MDSFT_TEXTFILT)) | G_TF_POINT);
		}

		// U10.2 coordinates
		float ulxf = ulx;
		float ulyf = uly;
		float lrxf = lrx;
		float lryf = lry;

		ulxf = ulxf / (4.0f * HALF_SCREEN_WIDTH) - 1.0f;
		ulyf = -(ulyf / (4.0f * HALF_SCREEN_HEIGHT)) + 1.0f;
		lrxf = lrxf / (4.0f * HALF_SCREEN_WIDTH) - 1.0f;
		lryf = -(lryf / (4.0f * HALF_SCREEN_HEIGHT)) + 1.0f;

		ulxf *= gfx_current_dimensions.adjust_ratio;
		lrxf *= gfx_current_dimensions.adjust_ratio;

		struct LoadedVertex* ul = &rsp.loaded_vertices[MAX_VERTICES + 0];
		struct LoadedVertex* ll = &rsp.loaded_vertices[MAX_VERTICES + 1];
		struct LoadedVertex* lr = &rsp.loaded_vertices[MAX_VERTICES + 2];
		struct LoadedVertex* ur = &rsp.loaded_vertices[MAX_VERTICES + 3];

		ul->x = ulxf;
		ul->y = ulyf;
		ul->z = -1.0f;
		ul->w = 1.0f;

		ll->x = ulxf;
		ll->y = lryf;
		ll->z = -1.0f;
		ll->w = 1.0f;

		lr->x = lrxf;
		lr->y = lryf;
		lr->z = -1.0f;
		lr->w = 1.0f;

		ur->x = lrxf;
		ur->y = ulyf;
		ur->z = -1.0f;
		ur->w = 1.0f;

		// The coordinates for texture rectangle shall bypass the viewport setting
		struct XYWidthHeight default_viewport = {0, 0, (u16)gfx_current_dimensions.width, (u16)gfx_current_dimensions.height};
		struct XYWidthHeight viewport_saved   = rdp.viewport();
		u32 geometry_mode_saved		      = rsp.geometryMode();

		rdp.setViewport(default_viewport);
		rsp.setGeometryMode(0);

		gfx_sp_tri1(MAX_VERTICES + 0, MAX_VERTICES + 1, MAX_VERTICES + 3);
		gfx_sp_tri1(MAX_VERTICES + 1, MAX_VERTICES + 2, MAX_VERTICES + 3);

		rsp.setGeometryMode(geometry_mode_saved);
		rdp.setViewport(viewport_saved);

		if(cycle_type == G_CYC_COPY)
		{
			rdp.setOtherModeH(saved_other_mode_h);
		}
	}

	static void dp_texture_rectangle(s32 ulx, s32 uly, s32 lrx, s32 lry, u8 tile, s16 uls, s16 ult, s16 dsdx, s16 dtdy, bool flip)
	{
		rdp.setTransformed(true);
		const u32 saved_combine_mode = rdp.combineMode();

		if(rdp.cycleType() == G_CYC_COPY)
		{
			// Per RDP Command Summary Set Tile's shift s and this dsdx should be set to 4 texels
			// Divide by 4 to get 1 instead
			dsdx >>= 2;

			// Color combiner is turned off in copy mode
			dp_set_combine_mode(color_comb(0, 0, 0, G_CCMUX_TEXEL0), color_comb(0, 0, 0, G_ACMUX_TEXEL0));

			// Per documentation one extra pixel is added in this modes to each edge
			lrx += 1 << 2;
			lry += 1 << 2;
		}

		// uls and ult are S10.5
		// dsdx and dtdy are S5.10
		// lrx, lry, ulx, uly are U10.2
		// lrs, lrt are S10.5
		if(flip)
		{
			dsdx = -dsdx;
			dtdy = -dtdy;
		}
		s16 width  = !flip ? lrx - ulx : lry - uly;
		s16 height = !flip ? lry - uly : lrx - ulx;
		float lrs  = ((uls << 7) + dsdx * width) >> 7;
		float lrt  = ((ult << 7) + dtdy * height) >> 7;

		struct LoadedVertex* ul = &rsp.loaded_vertices[MAX_VERTICES + 0];
		struct LoadedVertex* ll = &rsp.loaded_vertices[MAX_VERTICES + 1];
		struct LoadedVertex* lr = &rsp.loaded_vertices[MAX_VERTICES + 2];
		struct LoadedVertex* ur = &rsp.loaded_vertices[MAX_VERTICES + 3];
		ul->u			= uls;
		ul->v			= ult;
		lr->u			= lrs;
		lr->v			= lrt;
		if(!flip)
		{
			ll->u = uls;
			ll->v = lrt;
			ur->u = lrs;
			ur->v = ult;
		}
		else
		{
			ll->u = lrs;
			ll->v = ult;
			ur->u = uls;
			ur->v = lrt;
		}

		draw_rectangle(ulx, uly, lrx, lry);
		rdp.setCombineMode(saved_combine_mode);
	}

	static void dp_fill_rectangle(s32 ulx, s32 uly, s32 lrx, s32 lry)
	{
		if(rdp.color_image_address == rdp.z_buf_address)
		{
			// Don't clear Z buffer here since we already did it with glClear
			return;
		}
		u32 mode = rdp.cycleType();

		if(mode == G_CYC_COPY || mode == G_CYC_FILL)
		{
			// Per documentation one extra pixel is added in this modes to each edge
			lrx += 1 << 2;
			lry += 1 << 2;
		}

		for(int i = MAX_VERTICES; i < MAX_VERTICES + 4; i++)
		{
			rsp.loaded_vertices[i].color = rdp.fill_color;
		}

		u32 saved_combine_mode = rdp.combineMode();
		dp_set_combine_mode(color_comb(0, 0, 0, G_CCMUX_SHADE), color_comb(0, 0, 0, G_ACMUX_SHADE));
		draw_rectangle(ulx, uly, lrx, lry);
		rdp.setCombineMode(saved_combine_mode);
	}

	static void gfx_dp_set_z_image(const void* z_buf_address)
	{
		rdp.z_buf_address = z_buf_address;
	}

	static void gfx_dp_set_color_image(u32 format, u32 size, u32 width, const void* address)
	{
		rdp.color_image_address = address;
	}

	static void gfx_sp_set_other_mode(u32 shift, u32 num_bits, u64 mode)
	{
		u64 mask = (((u64)1 << num_bits) - 1) << shift;
		u64 om	 = rdp.otherModeL() | ((u64)rdp.otherModeH() << 32);
		om	 = (om & ~mask) | mode;
		rdp.setOtherModeL((u32)om);
		rdp.setOtherModeH((u32)(om >> 32));
	}

#define C0(pos, width) ((cmd->words.w0 >> (pos)) & ((1U << width) - 1))
#define C1(pos, width) ((cmd->words.w1 >> (pos)) & ((1U << width) - 1))

#define G_VTX_BUF 0x09
#define G_TRI_BUF 0x0A
#define G_VTX_BUF_PARAM 0x0B

	static void run_dl(Gfx* cmd)
	{
		int dummy = 0;
		for(;;)
		{
			u32 opcode = cmd->words.w0 >> 24;

			switch(opcode)
			{
					// RSP commands:
				case(u8)G_TRI1:
					gfx_sp_tri1(C0(16, 8) / 2, C0(8, 8) / 2, C0(0, 8) / 2);
					break;
				case(u8)G_TRI2:
					gfx_sp_tri1(C0(16, 8) / 2, C0(8, 8) / 2, C0(0, 8) / 2);
					gfx_sp_tri1(C1(16, 8) / 2, C1(8, 8) / 2, C1(0, 8) / 2);
					break;
				case G_VTX:
					gfx_sp_vertex(C0(12, 8), C0(1, 7) - C0(12, 8), (const Vtx*)cmd->words.w1, true);
					break;
				case G_MTX:
					gfx_sp_matrix(C0(0, 8) ^ G_MTX_PUSH, (const u32*)(cmd->words.w1));
					break;
				case G_POPMTX:
					gfx_sp_pop_matrix(cmd->words.w1 / 64);
					break;
				case G_TRI_BUF:
					gfx_sp_tri_buffer((const TriIndex*)(cmd->words.w1), C0(0, 24));
					break;
				case G_VTX_BUF_PARAM:
				{
					auto p	       = (u32*)&cmd->words.w1;
					g_vtx_buf_size = p[0];
					g_vtx_buf_dest = p[1];
				}
				break;
				case G_VTX_BUF:
					gfx_sp_vertex(g_vtx_buf_size, g_vtx_buf_dest, (const Vtx*)cmd->words.w1, true);

					break;
				case G_MOVEMEM:
					gfx_sp_movemem(C0(0, 8), C0(8, 8) * 8, (const void*)cmd->words.w1);
					break;
				case(u8)G_MOVEWORD:
					gfx_sp_moveword(C0(16, 8), C0(0, 16), cmd->words.w1);
					break;
				case(u8)G_TEXTURE:
					gfx_sp_texture(C1(16, 16), C1(0, 16), C0(11, 3), C0(8, 3), C0(1, 7));
					break;

				case G_DL:
					if(C0(16, 1) == 0)
					{
						// Push return address
						run_dl((Gfx*)cmd->words.w1);
					}
					else
					{
						cmd = (Gfx*)cmd->words.w1;
						--cmd; // increase after break
					}
					break;
				case(u8)G_ENDDL:
					return;
				case G_GEOMETRYMODE:
					gfx_sp_geometry_mode(~C0(0, 24), cmd->words.w1);
					break;
				case(u8)G_SETOTHERMODE_L:
					gfx_sp_set_other_mode(31 - C0(8, 8) - C0(0, 8), C0(0, 8) + 1, cmd->words.w1);
					break;
				case(u8)G_SETOTHERMODE_H:
					gfx_sp_set_other_mode(63 - C0(8, 8) - C0(0, 8), C0(0, 8) + 1, (u64)cmd->words.w1 << 32);
					break;
					// RDP Commands:
				case G_SETTIMG:
					gfx_dp_set_texture_image(C0(21, 3), C0(19, 2), C0(0, 10), (const void*)cmd->words.w1);
					break;
				case G_LOADBLOCK:
					gfx_dp_load_block(C1(24, 3), C0(12, 12), C0(0, 12), C1(12, 12), C1(0, 12));
					break;
				case G_LOADTILE:
					dp_load_tile(C1(24, 3), C0(12, 12), C0(0, 12), C1(12, 12), C1(0, 12));
					break;
				case G_SETTILE:
					gfx_dp_set_tile(C0(21, 3), C0(19, 2), C0(9, 9), C0(0, 9), C1(24, 3), C1(20, 4), C1(18, 2), C1(14, 4), C1(10, 4), C1(8, 2), C1(4, 4), C1(0, 4));
					break;
				case G_SETTILESIZE:
					gfx_dp_set_tile_size(C1(24, 3), C0(12, 12), C0(0, 12), C1(12, 12), C1(0, 12));
					break;
				case G_LOADTLUT:
					gfx_dp_load_tlut(C1(24, 3), C1(14, 10));
					break;
				case G_SETENVCOLOR:
					dp_set_env_color(C1(24, 8), C1(16, 8), C1(8, 8), C1(0, 8));
					break;
				case G_SETPRIMCOLOR:
					dp_set_prim_color(C1(24, 8), C1(16, 8), C1(8, 8), C1(0, 8));
					break;
				case G_SETFOGCOLOR:
					rdp.setFogColor(C1(24, 8), C1(16, 8), C1(8, 8), C1(0, 8));
					break;
				case G_SETFILLCOLOR:
					dp_set_fill_color(cmd->words.w1);
					break;
				case G_SETCOMBINE:
					dp_set_combine_mode(color_comb(C0(20, 4), C1(28, 4), C0(15, 5), C1(15, 3)), color_comb(C0(12, 3), C1(12, 3), C0(9, 3), C1(9, 3)));
					/*color_comb(C0(5, 4), C1(24, 4), C0(0, 5), C1(6, 3)),
					color_comb(C1(21, 3), C1(3, 3), C1(18, 3), C1(0, 3)));*/
					break;
					// G_SETPRIMCOLOR, G_CCMUX_PRIMITIVE, G_ACMUX_PRIMITIVE, is used by Goddard
					// G_CCMUX_TEXEL1, LOD_FRACTION is used in Bowser room 1
				case G_TEXRECT:
				case G_TEXRECTFLIP:
				{
					s32 lrx, lry, tile, ulx, uly;
					s32 uls, ult, dsdx, dtdy;

					lrx = (s32)(C0(0, 24) << 8) >> 8;
					lry = (s32)(C1(0, 24) << 8) >> 8;
					++cmd;
					ulx = (s32)(C0(0, 24) << 8) >> 8;
					uly = (s32)(C1(0, 24) << 8) >> 8;
					++cmd;
					uls  = C0(16, 16);
					ult  = C0(0, 16);
					dsdx = C1(16, 16);
					dtdy = C1(0, 16);

					dp_texture_rectangle(ulx, uly, lrx, lry, 0 /*tile*/, uls, ult, dsdx, dtdy, opcode == G_TEXRECTFLIP);
					break;
				}
				case G_FILLRECT:
				{
					s32 lrx, lry, ulx, uly;
					lrx = (s32)(C0(0, 24) << 8) >> 8;
					lry = (s32)(C1(0, 24) << 8) >> 8;
					++cmd;
					ulx = (s32)(C0(0, 24) << 8) >> 8;
					uly = (s32)(C1(0, 24) << 8) >> 8;
					dp_fill_rectangle(ulx, uly, lrx, lry);
					break;
				}

				case G_SETSCISSOR:
					gfx_dp_set_scissor(C1(24, 2), C0(12, 12), C0(0, 12), C1(12, 12), C1(0, 12));
					break;
				case G_SETZIMG:
					gfx_dp_set_z_image((const void*)cmd->words.w1);
					break;
				case G_SETCIMG:
					gfx_dp_set_color_image(C0(21, 3), C0(19, 2), C0(0, 11), (const void*)cmd->words.w1);
					break;
#ifdef DEBUG
				case G_RDPFULLSYNC:
				case G_RDPTILESYNC:
				case G_RDPPIPESYNC:
				case G_RDPLOADSYNC:
				case G_NOOP:
				case G_SETBLENDCOLOR:
					break;
				default:

				{
					int y = 0;
				}
#endif
			}
			++cmd;
		}
	}

	static void gfx_sp_reset()
	{
		rsp.modelview_matrix_stack_size = 1;
		rsp.current_num_lights		= 2;
		rsp.lights_changed		= true;
	}

	static void gfx_get_dimensions(u32* width, u32* height)
	{
		gfx_wapi->get_dimensions(width, height);
	}

	void Fast64::start_frame()
	{
		current_vbo = 0;
		gfx_wapi->handle_events();
		gfx_wapi->get_dimensions(&gfx_current_dimensions.width, &gfx_current_dimensions.height);
		if(gfx_current_dimensions.height == 0)
		{
			// Avoid division by zero
			gfx_current_dimensions.height = 1;
		}
		gfx_current_dimensions.aspect_ratio = (float)gfx_current_dimensions.width / (float)gfx_current_dimensions.height;
		gfx_current_dimensions.adjust_ratio = (4.0f / 3.0f) / gfx_current_dimensions.aspect_ratio;
	}

	void Fast64::run(Gfx* commands)
	{
		gfx_sp_reset();

		if(dropped_frame)
		{
			return;
		}

		if(!gfx_wapi->begin_frame())
		{
			return;
		}

		gfx_rapi->start_frame();
		run_dl(commands);
		flush();

		gfx_rapi->end_frame();
		gfx_wapi->swap_buffers_begin();
                SDL_Event e;
                SDL_PollEvent(&e);
	}

	void Fast64::end_frame()
	{
		if(!dropped_frame)
		{
			gfx_rapi->finish_render();

			const auto now	    = std::chrono::high_resolution_clock::now();
			m_lastFrameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_currentFrameStartTime);
			gfx_wapi->swap_buffers_end();
			gfx_rapi->end_frame();
			m_lastSwapDuration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - now);
		}
		current_vbo = 0;
	}

	Fast64* Fast64::createContext()
	{
		init();
		return new Fast64();
	}

	void Fast64::physics_loop()
	{
	}

	void Fast64::run_loop()
	{
		m_nextFrameTime = std::chrono::high_resolution_clock::now();
		m_refreshRate = gfx_wapi->refreshInterval();

		while(1)
		{
			if (!sm64::config().game().disableFramePacing())
			{
				run_paced_loop();
			}
			else
			{
				run_locked_loop();
			}
		}
	}

	void Fast64::run_locked_loop()
	{
		dropped_frame = false;
		start_frame();
		game_loop_one_iteration();

		int samples_left      = audio_api->buffered();
		u32 num_audio_samples = samples_left < audio_api->get_desired_buffered() ? 544 : 528;

#ifdef ENABLE_60FPS
		s16 audio_buffer[544 * 2];
		create_next_audio_buffer(audio_buffer, num_audio_samples);
		if(!config().game().disableSound())
		{
			audio_api->play((const u8*)audio_buffer, num_audio_samples * 4);
		}
#else
		s16 audio_buffer[544 * 2 * 2];
		for(int i = 0; i < 2; i++)
		{
			create_next_audio_buffer(audio_buffer + i * (num_audio_samples * 2), num_audio_samples);
		}
		if(!config().game().disableSound())
		{
			audio_api->play((const u8*)audio_buffer, 2 * num_audio_samples * 4);
		}
#endif

		end_frame();
		m_lastFrameTime = std::chrono::high_resolution_clock::now();

		m_nextFrameTime += std::chrono::microseconds(1000 * 1000 / 60);
	}

	void Fast64::run_paced_loop()
	{
		// const auto frameAlignment = (m_refreshRate - (m_lastFrameDuration % m_refreshRate)) / 2;
		// const std::chrono::time_point<std::chrono::steady_clock> targetFrameStart = m_nextFrameTime - MIN(m_lastFrameDuration + frameAlignment, m_lastSwapDuration);
		const std::chrono::time_point<std::chrono::high_resolution_clock> targetFrameStart = m_nextFrameTime - m_lastFrameDuration;

		auto timeDelta = std::chrono::duration_cast<std::chrono::microseconds>(targetFrameStart - std::chrono::high_resolution_clock::now());

		if(timeDelta <= std::chrono::microseconds(0))
		{
			dropped_frame = std::chrono::high_resolution_clock::now() > targetFrameStart + m_refreshRate + std::chrono::milliseconds(2);

#if defined(_MSC_VER) && defined(DEBUG)
			static int dropped_frames = 0;
			static u64 frame_counter  = 0;

			if(frame_counter++ % (60 * 3) == 0)
			{
				char buffer[128];
				float ms = m_lastSwapDuration.count() / 1000.0f;
				sprintf(buffer, "swap duration %2.2f ms\r\n", ms);
				OutputDebugString(buffer);
			}

			if(dropped_frame)
			{
				char buffer[128];
				int diff = (std::chrono::high_resolution_clock::now() - (targetFrameStart + m_refreshRate)).count() / 1000000;
				sprintf(buffer, "dropped frame %d, missed by %d ms\r\n", ++dropped_frames, diff);
				OutputDebugString(buffer);
			}
#endif

			if (dropped_frame)
			{
				if (timeDelta < m_refreshRate * -4)
				{
					m_lastFrameDuration = std::chrono::duration<u64, std::micro>(0);
					m_nextFrameTime = std::chrono::high_resolution_clock::now();
					return;
				}
			}

			m_currentFrameStartTime = std::chrono::high_resolution_clock::now();
			start_frame();
			game_loop_one_iteration();

			int samples_left      = audio_api->buffered();
			u32 num_audio_samples = samples_left < audio_api->get_desired_buffered() ? 544 : 528;

#ifdef ENABLE_60FPS
			s16 audio_buffer[544 * 2];
			create_next_audio_buffer(audio_buffer, num_audio_samples);
			if(!config().game().disableSound())
			{
				audio_api->play((const u8*)audio_buffer, num_audio_samples * 4);
			}
#else
			s16 audio_buffer[544 * 2 * 2];
			for(int i = 0; i < 2; i++)
			{
				create_next_audio_buffer(audio_buffer + i * (num_audio_samples * 2), num_audio_samples);
			}
			if(!config().game().disableSound())
			{
				audio_api->play((const u8*)audio_buffer, 2 * num_audio_samples * 4);
			}
#endif

			end_frame();
			m_lastFrameTime = std::chrono::high_resolution_clock::now();

			m_nextFrameTime += std::chrono::microseconds(1000 * 1000 / 60);
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::microseconds(500));
		}
	}
} // namespace sm64::gfx

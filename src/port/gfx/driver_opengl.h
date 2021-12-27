#pragma once
#include <stdint.h>
#include <stdbool.h>

//#define GL_DEBUG

#if defined(WIN32) || defined(WIN64)
#define FOR_WINDOWS 1
#else
#define FOR_WINDOWS 0
#endif

#if FOR_WINDOWS
#include <GL/glew.h>
#include <SDL2/SDL.h>
#define GL_GLEXT_PROTOTYPES 1
#include <SDL2/SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#define GL_GLEXT_PROTOTYPES 1
#include <SDL2/SDL_opengles2.h>
#endif

#ifdef _MSC_VER
#include <stdio.h>
#endif

#include "gfx_cc.h"
#include "renderer.h"

#ifndef __SWITCH__
#define ENABLE_NOISE_FILTER
#endif

#ifdef ENABLE_NOISE_FILTER
#define SHADER_VERSION "#version 110"
#else
#define SHADER_VERSION "#version 100\nprecision mediump float;"
#endif

#include "shaders.h"

#ifdef GL_DEBUG
static void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                                       const GLchar* message, const void* userParam) {
    osSyncPrintf("GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}
#endif

namespace sm64::gfx
{
	struct Fog
	{
		float color[4];
		float scaler;
		float offset;
	} fog;

	struct ShaderProgram
	{
		u32 shader_id;
		GLuint opengl_program_id;
		u8 num_inputs;
		bool used_textures[2];
		u8 num_floats;
		GLint attrib_locations[7];
		u8 attrib_sizes[7];
		u8 num_attribs;
		bool used_noise;
		bool used_fog;
		GLint frame_count_location;
		GLint window_height_location;
		GLint fog_scaler_location;
		GLint fog_offset_location;
		GLint fog_color_location;
	};
} // namespace sm64::gfx

namespace sm64::gfx::opengl
{
	class Opengl : public Renderer
	{
		public:
		ShaderProgram shader_program_pool[64];
		u8 shader_program_pool_size = 0;

		u32 frame_count	   = 0;
		u32 current_height = 0;

		Opengl()
		{
#if FOR_WINDOWS
			glewInit();
#endif

			glDepthFunc(GL_LEQUAL);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			#ifdef GL_DEBUG
                        glEnable(GL_DEBUG_OUTPUT);
                        glDebugMessageCallback(MessageCallback, 0);
			#endif
		}

		bool z_is_from_0_to_1()
		{
			return false;
		}

		void vertex_array_set_attribs(struct ShaderProgram* prg)
		{
			size_t num_floats = prg->num_floats;
			size_t pos	  = 0;

			for(int i = 0; i < prg->num_attribs; i++)
			{
				glEnableVertexAttribArray(prg->attrib_locations[i]);
				glVertexAttribPointer(prg->attrib_locations[i], prg->attrib_sizes[i], GL_FLOAT, GL_FALSE, num_floats * sizeof(float), (void*)(pos * sizeof(float)));
				pos += prg->attrib_sizes[i];
			}
		}

		void set_uniforms(struct ShaderProgram* prg)
		{
			if(prg->used_noise)
			{
				glUniform1i(prg->frame_count_location, frame_count);
				glUniform1i(prg->window_height_location, current_height);
			}

			if(prg->used_fog)
			{
				glUniform4f(prg->fog_color_location, fog.color[0], fog.color[1], fog.color[2], fog.color[3]);
				glUniform1f(prg->fog_scaler_location, fog.scaler);
				glUniform1f(prg->fog_offset_location, fog.offset);

				/*glUniform4f(prg->fog_color_location, 0.0f, 0.0f, 0.0f, 1.0f);
				glUniform1f(prg->fog_scaler_location, 1280.0f);
				glUniform1f(prg->fog_offset_location, 64512.0f);*/
			}
		}

		void unload_shader(struct ShaderProgram* old_prg)
		{
			if(old_prg != NULL)
			{
				for(int i = 0; i < old_prg->num_attribs; i++)
				{
					glDisableVertexAttribArray(old_prg->attrib_locations[i]);
				}
			}
		}

		ShaderProgram* current_program = 0;

		void reload_shader()
		{
			glUseProgram(current_program->opengl_program_id);
			vertex_array_set_attribs(current_program);
			set_uniforms(current_program);
		}

		void load_shader(ShaderProgram* new_prg)
		{
			glUseProgram(new_prg->opengl_program_id);
			vertex_array_set_attribs(new_prg);
			set_uniforms(new_prg);
			current_program = new_prg;
			// set_transformation();
		}

		void append_str(char* buf, size_t* len, const char* str)
		{
			while(*str != '\0')
				buf[(*len)++] = *str++;
		}

		void append_line(char* buf, size_t* len, const char* str)
		{
			while(*str != '\0')
				buf[(*len)++] = *str++;
			buf[(*len)++] = '\n';
		}

		const char* shader_item_to_str(u32 item, bool with_alpha, bool only_alpha, bool inputs_have_alpha, bool hint_single_element)
		{
			if(!only_alpha)
			{
				switch(item)
				{
					case SHADER_0:
						return with_alpha ? "vec4(0.0, 0.0, 0.0, 0.0)" : "vec3(0.0, 0.0, 0.0)";
					case SHADER_INPUT_1:
						return with_alpha || !inputs_have_alpha ? "vInput1" : "vInput1.rgb";
					case SHADER_INPUT_2:
						return with_alpha || !inputs_have_alpha ? "vInput2" : "vInput2.rgb";
					case SHADER_INPUT_3:
						return with_alpha || !inputs_have_alpha ? "vInput3" : "vInput3.rgb";
					case SHADER_INPUT_4:
						return with_alpha || !inputs_have_alpha ? "vInput4" : "vInput4.rgb";
					case SHADER_TEXEL0:
						return with_alpha ? "texVal0" : "texVal0.rgb";
					case SHADER_TEXEL0A:
						return hint_single_element ? "texVal0.a" : (with_alpha ? "vec4(texVal0.a, texVal0.a, texVal0.a, texVal0.a)" : "vec3(texVal0.a, texVal0.a, texVal0.a)");
					case SHADER_TEXEL1:
						return with_alpha ? "texVal1" : "texVal1.rgb";
				}
			}
			else
			{
				switch(item)
				{
					case SHADER_0:
						return "0.0";
					case SHADER_INPUT_1:
						return "vInput1.a";
					case SHADER_INPUT_2:
						return "vInput2.a";
					case SHADER_INPUT_3:
						return "vInput3.a";
					case SHADER_INPUT_4:
						return "vInput4.a";
					case SHADER_TEXEL0:
						return "texVal0.a";
					case SHADER_TEXEL0A:
						return "texVal0.a";
					case SHADER_TEXEL1:
						return "texVal1.a";
				}
			}
			return nullptr;
		}

		void append_formula(char* buf, size_t* len, u8 c[2][4], bool do_single, bool do_multiply, bool do_mix, bool with_alpha, bool only_alpha, bool opt_alpha)
		{
			if(do_single)
			{
				append_str(buf, len, shader_item_to_str(c[only_alpha][3], with_alpha, only_alpha, opt_alpha, false));
			}
			else if(do_multiply)
			{
				append_str(buf, len, shader_item_to_str(c[only_alpha][0], with_alpha, only_alpha, opt_alpha, false));
				append_str(buf, len, " * ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][2], with_alpha, only_alpha, opt_alpha, true));
			}
			else if(do_mix)
			{
				append_str(buf, len, "mix(");
				append_str(buf, len, shader_item_to_str(c[only_alpha][1], with_alpha, only_alpha, opt_alpha, false));
				append_str(buf, len, ", ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][0], with_alpha, only_alpha, opt_alpha, false));
				append_str(buf, len, ", ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][2], with_alpha, only_alpha, opt_alpha, true));
				append_str(buf, len, ")");
			}
			else
			{
				append_str(buf, len, "(");
				append_str(buf, len, shader_item_to_str(c[only_alpha][0], with_alpha, only_alpha, opt_alpha, false));
				append_str(buf, len, " - ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][1], with_alpha, only_alpha, opt_alpha, false));
				append_str(buf, len, ") * ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][2], with_alpha, only_alpha, opt_alpha, true));
				append_str(buf, len, " + ");
				append_str(buf, len, shader_item_to_str(c[only_alpha][3], with_alpha, only_alpha, opt_alpha, false));
			}
		}

		struct ShaderProgram* create_and_load_new_shader(u32 shader_id)
		{
			struct CCFeatures cc_features;
			gfx_cc_get_features(shader_id, &cc_features);

			char vs_buf[1024];
			char fs_buf[1024];
			size_t vs_len	  = 0;
			size_t fs_len	  = 0;
			size_t num_floats = 4;

			// Vertex shader
			append_line(vs_buf, &vs_len, SHADER_VERSION);
			append_line(vs_buf, &vs_len, "attribute vec4 aVtxPos;");
			append_line(vs_buf, &vs_len, "uniform mat4 MVP;");

			if(cc_features.used_textures[0] || cc_features.used_textures[1])
			{
				append_line(vs_buf, &vs_len, "attribute vec2 aTexCoord;");
				append_line(vs_buf, &vs_len, "varying vec2 vTexCoord;");
				num_floats += 2;
			}

			if(cc_features.opt_fog)
			{
				append_line(vs_buf, &vs_len, "uniform vec4 aFog;");
				append_line(vs_buf, &vs_len, "uniform float fogScaler;");
				append_line(vs_buf, &vs_len, "uniform float fogOffset;");
				append_line(vs_buf, &vs_len, "varying vec4 vFog;");
			}

			for(int i = 0; i < cc_features.num_inputs; i++)
			{
				vs_len += sprintf(vs_buf + vs_len, "attribute vec%d aInput%d;\n", cc_features.opt_alpha ? 4 : 3, i + 1);
				vs_len += sprintf(vs_buf + vs_len, "varying vec%d vInput%d;\n", cc_features.opt_alpha ? 4 : 3, i + 1);
				num_floats += cc_features.opt_alpha ? 4 : 3;
			}

			append_line(vs_buf, &vs_len, "void main() {");
			if(cc_features.used_textures[0] || cc_features.used_textures[1])
			{
				append_line(vs_buf, &vs_len, "vTexCoord = aTexCoord;");
			}

			/*if (cc_features.opt_fog)
			{
				append_line(vs_buf, &vs_len, "vFog = aFog;");
			}*/

			for(int i = 0; i < cc_features.num_inputs; i++)
			{
				vs_len += sprintf(vs_buf + vs_len, "vInput%d = aInput%d;\n", i + 1, i + 1);
			}

			append_line(vs_buf, &vs_len, "gl_Position = MVP * aVtxPos;");

			if(cc_features.opt_fog)
			{
				append_line(vs_buf, &vs_len, "vFog = aFog;");
				append_line(vs_buf, &vs_len, "float w = gl_Position.w != 0.0 ? gl_Position.w : 0.001;");
				append_line(vs_buf, &vs_len, "vFog[3] = clamp(((gl_Position.z / (w < 0.0 ? 32767.0 : w)) * fogScaler + fogOffset) / 255.0, 0.0, 1.0);");
			}
			append_line(vs_buf, &vs_len, "}");

			// Fragment shader
			append_line(fs_buf, &fs_len, SHADER_VERSION);
			// append_line(fs_buf, &fs_len, "precision mediump float;");
			if(cc_features.used_textures[0] || cc_features.used_textures[1])
			{
				append_line(fs_buf, &fs_len, "varying vec2 vTexCoord;");
			}
			if(cc_features.opt_fog)
			{
				append_line(fs_buf, &fs_len, "varying vec4 vFog;");
			}
			for(int i = 0; i < cc_features.num_inputs; i++)
			{
				fs_len += sprintf(fs_buf + fs_len, "varying vec%d vInput%d;\n", cc_features.opt_alpha ? 4 : 3, i + 1);
			}
			if(cc_features.used_textures[0])
			{
				append_line(fs_buf, &fs_len, "uniform sampler2D uTex0;");
			}
			if(cc_features.used_textures[1])
			{
				append_line(fs_buf, &fs_len, "uniform sampler2D uTex1;");
			}

			if(cc_features.opt_alpha && cc_features.opt_noise)
			{
				append_line(fs_buf, &fs_len, "uniform int frame_count;");
				append_line(fs_buf, &fs_len, "uniform int window_height;");

				append_line(fs_buf, &fs_len, "float random(in vec3 value) {");
				append_line(fs_buf, &fs_len, "    float random = dot(sin(value), vec3(12.9898, 78.233, 37.719));");
				append_line(fs_buf, &fs_len, "    return fract(sin(random) * 143758.5453);");
				append_line(fs_buf, &fs_len, "}");
			}

			append_line(fs_buf, &fs_len, "void main() {");

			if(cc_features.used_textures[0])
			{
				append_line(fs_buf, &fs_len, "vec4 texVal0 = texture2D(uTex0, vTexCoord);");
			}
			if(cc_features.used_textures[1])
			{
				append_line(fs_buf, &fs_len, "vec4 texVal1 = texture2D(uTex1, vTexCoord);");
			}

			append_str(fs_buf, &fs_len, cc_features.opt_alpha ? "vec4 texel = " : "vec3 texel = ");
			if(!cc_features.color_alpha_same && cc_features.opt_alpha)
			{
				append_str(fs_buf, &fs_len, "vec4(");
				append_formula(fs_buf, &fs_len, cc_features.c, cc_features.do_single[0], cc_features.do_multiply[0], cc_features.do_mix[0], false, false, true);
				append_str(fs_buf, &fs_len, ", ");
				append_formula(fs_buf, &fs_len, cc_features.c, cc_features.do_single[1], cc_features.do_multiply[1], cc_features.do_mix[1], true, true, true);
				append_str(fs_buf, &fs_len, ")");
			}
			else
			{
				append_formula(fs_buf, &fs_len, cc_features.c, cc_features.do_single[0], cc_features.do_multiply[0], cc_features.do_mix[0], cc_features.opt_alpha, false, cc_features.opt_alpha);
			}
			append_line(fs_buf, &fs_len, ";");

			if(cc_features.opt_texture_edge && cc_features.opt_alpha)
			{
				append_line(fs_buf, &fs_len, "if (texel.a > 0.3) texel.a = 1.0; else discard;");
			}
			// TODO discard if alpha is 0?
			if(cc_features.opt_fog)
			{
				if(cc_features.opt_alpha)
				{
					append_line(fs_buf, &fs_len, "texel = vec4(mix(texel.rgb, vFog.rgb, vFog.a), texel.a);");
				}
				else
				{
					append_line(fs_buf, &fs_len, "texel = mix(texel, vFog.rgb, vFog.a);");
				}
			}

			if(cc_features.opt_alpha && cc_features.opt_noise)
			{
				append_line(fs_buf, &fs_len, "texel.a *= floor(random(vec3(floor(gl_FragCoord.xy), float(frame_count))) + 0.5);");
			}

			if(cc_features.opt_alpha)
			{
				append_line(fs_buf, &fs_len, "gl_FragColor = texel;");
			}
			else
			{
				append_line(fs_buf, &fs_len, "gl_FragColor = vec4(texel, 1.0);");
			}
			append_line(fs_buf, &fs_len, "}");

			vs_buf[vs_len] = '\0';
			fs_buf[fs_len] = '\0';

			const GLchar* sources[2] = {vs_buf, fs_buf};
			const GLint lengths[2]	 = {vs_len, fs_len};
			GLint success;

			GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex_shader, 1, &sources[0], &lengths[0]);
			glCompileShader(vertex_shader);
			glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
			if(!success)
			{
				GLint max_length = 0;
				glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &max_length);
				char error_log[1024];
				fprintf(stderr, "Vertex shader compilation failed\n");
				glGetShaderInfoLog(vertex_shader, max_length, &max_length, &error_log[0]);
				fprintf(stderr, "%s\n", &error_log[0]);
				abort();
			}

			GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment_shader, 1, &sources[1], &lengths[1]);
			glCompileShader(fragment_shader);
			glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
			if(!success)
			{
				GLint max_length = 0;
				glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &max_length);
				char error_log[1024];
				fprintf(stderr, "Fragment shader compilation failed\n");
				glGetShaderInfoLog(fragment_shader, max_length, &max_length, &error_log[0]);
				fprintf(stderr, "%s\n", &error_log[0]);
				abort();
			}

			GLuint shader_program = glCreateProgram();
			glAttachShader(shader_program, vertex_shader);
			glAttachShader(shader_program, fragment_shader);
			glLinkProgram(shader_program);

			size_t cnt = 0;

			struct ShaderProgram* prg  = &shader_program_pool[shader_program_pool_size++];
			prg->attrib_locations[cnt] = glGetAttribLocation(shader_program, "aVtxPos");
			prg->attrib_sizes[cnt]	   = 4;
			++cnt;

			if(cc_features.used_textures[0] || cc_features.used_textures[1])
			{
				prg->attrib_locations[cnt] = glGetAttribLocation(shader_program, "aTexCoord");
				prg->attrib_sizes[cnt]	   = 2;
				++cnt;
			}

			if(cc_features.opt_fog)
			{
				prg->fog_scaler_location = glGetUniformLocation(shader_program, "fogScaler");
				prg->fog_offset_location = glGetUniformLocation(shader_program, "fogOffset");
				prg->fog_color_location	 = glGetUniformLocation(shader_program, "aFog");
				prg->used_fog		 = true;
			}
			else
			{
				prg->used_fog = false;
			}

			for(int i = 0; i < cc_features.num_inputs; i++)
			{
				char name[16];
				sprintf(name, "aInput%d", i + 1);
				prg->attrib_locations[cnt] = glGetAttribLocation(shader_program, name);
				prg->attrib_sizes[cnt]	   = cc_features.opt_alpha ? 4 : 3;
				++cnt;
			}

			prg->shader_id	       = shader_id;
			prg->opengl_program_id = shader_program;
			prg->num_inputs	       = cc_features.num_inputs;
			prg->used_textures[0]  = cc_features.used_textures[0];
			prg->used_textures[1]  = cc_features.used_textures[1];
			prg->num_floats	       = num_floats;
			prg->num_attribs       = cnt;

			load_shader(prg);

			if(cc_features.used_textures[0])
			{
				GLint sampler_location = glGetUniformLocation(shader_program, "uTex0");
				glUniform1i(sampler_location, 0);
			}
			if(cc_features.used_textures[1])
			{
				GLint sampler_location = glGetUniformLocation(shader_program, "uTex1");
				glUniform1i(sampler_location, 1);
			}

			if(cc_features.opt_alpha && cc_features.opt_noise)
			{
				prg->frame_count_location   = glGetUniformLocation(shader_program, "frame_count");
				prg->window_height_location = glGetUniformLocation(shader_program, "window_height");
				prg->used_noise		    = true;
			}
			else
			{
				prg->used_noise = false;
			}

			set_uniforms(prg);

			return prg;
		}

		ShaderProgram* lookup_shader(u32 shader_id)
		{
			for(size_t i = 0; i < shader_program_pool_size; i++)
			{
				if(shader_program_pool[i].shader_id == shader_id)
				{
					return &shader_program_pool[i];
				}
			}
			return NULL;
		}

		void shader_get_info(struct ShaderProgram* prg, u8* num_inputs, bool used_textures[2])
		{
			*num_inputs	 = prg->num_inputs;
			used_textures[0] = prg->used_textures[0];
			used_textures[1] = prg->used_textures[1];
		}

		GLuint new_texture()
		{
			GLuint ret;
			glGenTextures(1, &ret);
			return ret;
		}

		void select_texture(int tile, TextureNode& node)
		{
			glActiveTexture(GL_TEXTURE0 + tile);
			glBindTexture(GL_TEXTURE_2D, node.texture_id);
		}

#ifdef _WIN32
		//#define ENABLE_MIPMAP
#endif

		void upload_texture(const u8* rgba32_buf, int width, int height, TextureNode& node)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgba32_buf);
#ifdef ENABLE_MIPMAP
			node.mipmap = width * height > 64 * 32;
			if(node.mipmap)
			{
				glGenerateMipmap(GL_TEXTURE_2D);
			}
#endif
		}

		static u32 gfx_cm_to_opengl(u32 val)
		{
			if(val & G_TX_CLAMP)
			{
				return GL_CLAMP_TO_EDGE;
			}
			return (val & G_TX_MIRROR) ? GL_MIRRORED_REPEAT : GL_REPEAT;
		}

		void set_sampler_parameters(int tile, TextureNode& node)
		{
#ifdef ENABLE_MIPMAP
			if(node.mipmap)
			{
				const int configMipMapMaxLevel = 1000;

				// const GLenum filter = linear_filter ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_NEAREST;
				const GLenum filter = node.linear_filter ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_NEAREST;
				glActiveTexture(GL_TEXTURE0 + tile);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, configMipMapMaxLevel);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, gfx_cm_to_opengl(node.cms));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, gfx_cm_to_opengl(node.cmt));
			}
			else
			{
				glActiveTexture(GL_TEXTURE0 + tile);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, node.linear_filter ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, node.linear_filter ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, gfx_cm_to_opengl(node.cms));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, gfx_cm_to_opengl(node.cmt));
			}
#else
			glActiveTexture(GL_TEXTURE0 + tile);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, node.linear_filter ? GL_LINEAR : GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, node.linear_filter ? GL_LINEAR : GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, gfx_cm_to_opengl(node.cms));
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, gfx_cm_to_opengl(node.cmt));
#endif
		}

		void set_depth_test(bool depth_test)
		{
			if(depth_test)
			{
				glEnable(GL_DEPTH_TEST);
			}
			else
			{
				glDisable(GL_DEPTH_TEST);
			}
		}

		void set_depth_mask(bool z_upd)
		{
			glDepthMask(z_upd ? GL_TRUE : GL_FALSE);
		}

		void set_zmode_decal(bool zmode_decal)
		{
			if(zmode_decal)
			{
				glPolygonOffset(-2, -2);
				glEnable(GL_POLYGON_OFFSET_FILL);
			}
			else
			{
				glPolygonOffset(0, 0);
				glDisable(GL_POLYGON_OFFSET_FILL);
			}
		}

		void set_viewport(int x, int y, int width, int height)
		{
			glViewport(x, y, width, height);
			current_height = height;
		}

		void set_scissor(int x, int y, int width, int height)
		{
			glScissor(x, y, width, height);
		}

		void set_use_alpha(bool use_alpha)
		{
			if(use_alpha)
			{
				glEnable(GL_BLEND);
			}
			else
			{
				glDisable(GL_BLEND);
			}
		}

		u64 create_vbo()
		{
			GLuint handle = 0;
			glGenBuffers(1, &handle);

			return (u64)handle;
		}

		u64 create_vbo(float buf_vbo[], size_t buf_vbo_len)
		{
			GLuint handle = 0;
			glGenBuffers(1, &handle);

			glBindBuffer(GL_ARRAY_BUFFER, handle);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buf_vbo_len, buf_vbo, GL_STATIC_DRAW);

			return (u64)handle;
		}

		void update_vbo(u64 handle, float buf_vbo[], size_t buf_vbo_len)
		{
			glBindBuffer(GL_ARRAY_BUFFER, handle);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buf_vbo_len, buf_vbo, GL_STATIC_DRAW);
		}

		u64 delete_vbo(u64 handle)
		{
			GLuint _handle = (GLuint)handle;
			glDeleteBuffers(1, &_handle);
			return INVALID_VBO;
		}

		void setFogColor(float r, float g, float b, float a)
		{
			fog.color[0] = r;
			fog.color[1] = g;
			fog.color[2] = b;
			fog.color[3] = a;
		}

		void setFogMetrics(float scaler, float offset)
		{
			fog.scaler = scaler;
			fog.offset = offset;
		}

		void set_transformation(float* mvp)
		{
			GLint shader_id			    = glGetUniformLocation(current_program->opengl_program_id, "MVP");
			static const GLfloat identity[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};

			if(mvp)
			{
				glUniformMatrix4fv(shader_id, 1, GL_FALSE, mvp);
			}
			else
			{
				glUniformMatrix4fv(shader_id, 1, GL_FALSE, &identity[0][0]);
			}
		}

		void draw_triangles(u64 handle, size_t buf_vbo_num_tris, float* mvp)
		{
			glBindBuffer(GL_ARRAY_BUFFER, (GLuint)handle);
			reload_shader();

			set_transformation(mvp);

			glDrawArrays(GL_TRIANGLES, 0, 3 * buf_vbo_num_tris);
			// reload_shader();
		}

		void draw_triangles(float buf_vbo[], size_t buf_vbo_len, size_t buf_vbo_num_tris, float* mvp)
		{
			// printf("flushing %d tris\n", buf_vbo_num_tris);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buf_vbo_len, buf_vbo, GL_STREAM_DRAW);
			reload_shader();
			set_transformation(mvp);
			glDrawArrays(GL_TRIANGLES, 0, 3 * buf_vbo_num_tris);
		}

		void on_resize()
		{
		}

		void start_frame()
		{
			frame_count++;

			glDisable(GL_SCISSOR_TEST);
			glDepthMask(GL_TRUE); // Must be set to clear Z-buffer
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_SCISSOR_TEST);
		}

		void end_frame()
		{
			// glFinish();
		}

		static void finish_render()
		{
		}
	};
} // namespace sm64::gfx::opengl

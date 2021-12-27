#pragma once
#include "types.h"

namespace sm64::gfx
{
	struct ShaderProgram;

	const u64 INVALID_VBO = 0xFFFFFFFFFFFFFFFF;

	struct TextureNode
	{
		TextureNode() : texture_addr(nullptr), fmt(0), siz(0), texture_id(0), cms(0), cmt(0), linear_filter(0), mipmap(0)
		{
		}

		TextureNode(const u8* texture_addr, u8 fmt, u8 siz, bool linear_filter, u8 cms = 0, u8 cmy = 0) : texture_addr(texture_addr), fmt(fmt), siz(siz), texture_id(0), cms(cms), cmt(cmt), linear_filter(linear_filter), mipmap(0)
		{
		}

		bool isValid() const
		{
			return texture_addr != nullptr;
		}

		const u8* texture_addr;
		u8 fmt;
		u8 siz;

		u32 texture_id;
		u8 cms;
		u8 cmt;
		bool linear_filter;
		bool mipmap;
	};

	class Renderer
	{
		bool z_is_from_0_to_1()
		{
			return false;
		}

		void unload_shader(ShaderProgram* old_prg)
		{
		}

		void load_shader(ShaderProgram* new_prg)
		{
		}

		ShaderProgram* create_and_load_new_shader(u32 shader_id)
		{
			return nullptr;
		}

		ShaderProgram* lookup_shader(u32 shader_id)
		{
			return nullptr;
		}

		void shader_get_info(ShaderProgram* prg, u8& num_inputs, bool used_textures[2])
		{
			num_inputs = 0;
		}

		u32 new_texture()
		{
			return 0;
		}

		void select_texture(int tile, TextureNode& node)
		{
		}

		void upload_texture(const u8* rgba32_buf, int width, int height, TextureNode& node)
		{
		}

		void set_sampler_parameters(int sampler, TextureNode& node)
		{
		}

		void set_depth_test(bool depth_test)
		{
		}

		void set_depth_mask(bool z_upd)
		{
		}

		void set_zmode_decal(bool zmode_decal)
		{
		}

		void set_viewport(int x, int y, int width, int height)
		{
		}

		void set_scissor(int x, int y, int width, int height)
		{
		}

		void set_use_alpha(bool use_alpha)
		{
		}

		u64 create_vbo(float buf_vbo[], size_t buf_vbo_len, size_t buf_vbo_num_tris)
		{
			return INVALID_VBO;
		}

		u64 delete_vbo(u64 handle)
		{
			return INVALID_VBO;
		}

		void draw_triangles(u64 handle, size_t buf_vbo_num_tris)
		{
		}

		void draw_triangles(float buf_vbo[], size_t buf_vbo_len, size_t buf_vbo_num_tris)
		{
		}

		void init()
		{
		}

		void on_resize()
		{
		}

		void start_frame()
		{
		}

		void end_frame()
		{
		}

		void finish_render()
		{
		}
	};
} // namespace sm64::gfx

#pragma once

struct GameInfo;

extern "C"
{
	void gfx_init(const char* romName, OSViMode* viMode);
	void gfx_shutdown();
	bool gfx_start_frame();
	void gfx_end_frame();
	void gfx_fbe_sync(GraphicsContext* gfxCtx, GameInfo* GameInfo);
	int  gfx_fbe_is_enabled();
	void gfx_fbe_enable(int enable);
	void gfx_force_43(bool enable); // From GlideN64
	bool gfx_force_43_enabled();
	void gfx_run(OSTask_t* task, u32 sz);
	void gfx_filter_sepia_set(u8 r, u8 g, u8 b, u8 a);
	void gfx_filter_sepia_enabled();
	void gfx_filter_sepia_disable();
}



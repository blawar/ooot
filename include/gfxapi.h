#pragma once

struct GameInfo;

extern "C"
{
	void gfx_init(const char* romName, OSViMode* viMode);
	void gfx_shutdown();
	bool gfx_start_frame();
	void gfx_end_frame();
	void gfx_fbe_sync(GraphicsContext* gfxCtx, GameInfo* GameInfo);
	int gfx_fbe_is_enabled();
	void gfx_fbe_enable(int enable);
	void gfx_force_43(bool enable); // From GlideN64
	void gfx_run(OSTask_t* task, u32 sz);
}



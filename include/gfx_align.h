#pragma once
extern "C" {
	u64 gfx_width();
	u64 gfx_height();
	float gfx_ar_ratio();
}
#define GFX_DIMENSIONS_ASPECT_RATIO ((float)gfx_width() / (float)gfx_height())
#define GFX_DIMENSIONS_FROM_LEFT_EDGE(v) (SCREEN_WIDTH / 2 - SCREEN_HEIGHT / 2 * GFX_DIMENSIONS_ASPECT_RATIO + (v))
#define GFX_DIMENSIONS_FROM_RIGHT_EDGE(v) (SCREEN_WIDTH / 2 + SCREEN_HEIGHT / 2 * GFX_DIMENSIONS_ASPECT_RATIO - (v))
#define GFX_ALIGN_LEFT(v) ((int)floorf(GFX_DIMENSIONS_FROM_LEFT_EDGE(v)))
#define GFX_ALIGN_RIGHT(v) ((int)ceilf(GFX_DIMENSIONS_FROM_RIGHT_EDGE(SCREEN_WIDTH - v)))
#define GFX_ALIGN_RIGHT_F(v) ((float)GFX_DIMENSIONS_FROM_RIGHT_EDGE(SCREEN_WIDTH - v))

#define GFX_ALIGN_GUESS(v) (v < (SCREEN_WIDTH / 2) ? GFX_ALIGN_LEFT(v) : GFX_ALIGN_RIGHT(v))

#pragma once
#ifdef INTERNAL_SRC_CODE_Z_VR_BOX_DRAW_C
void SkyboxDraw_Draw(SkyboxContext* skyboxCtx, GraphicsContext* gfxCtx, s16 skyboxId, s16 blend, f32 x, f32 y, f32 z);
void SkyboxDraw_Update(SkyboxContext* skyboxCtx);
Mtx* SkyboxDraw_UpdateMatrix(SkyboxContext* skyboxCtx, f32 x, f32 y, f32 z);
#else
void SkyboxDraw_Draw(struct SkyboxContext* skyboxCtx, struct GraphicsContext* gfxCtx, s16 skyboxId, s16 blend, f32 x, f32 y, f32 z);
void SkyboxDraw_Update(struct SkyboxContext* skyboxCtx);
struct Mtx* SkyboxDraw_UpdateMatrix(struct SkyboxContext* skyboxCtx, f32 x, f32 y, f32 z);
#endif

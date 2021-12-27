#pragma once
#ifdef INTERNAL_SRC_CODE_Z_VR_BOX_C
void Skybox_Init(GameState* state, SkyboxContext* skyboxCtx, s16 skyboxId);
#else
void Skybox_Init(struct GameState* state, struct SkyboxContext* skyboxCtx, s16 skyboxId);
#endif

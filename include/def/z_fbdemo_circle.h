#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FBDEMO_CIRCLE_C
void TransitionCircle_Destroy(void* thisx);
void TransitionCircle_Draw(void* thisx, Gfx** gfxP);
void* TransitionCircle_Init(void* thisx);
s32 TransitionCircle_IsDone(void* thisx);
void TransitionCircle_SetColor(void* thisx, u32 color);
void TransitionCircle_SetEnvColor(void* thisx, u32 color);
void TransitionCircle_SetType(void* thisx, s32 type);
void TransitionCircle_Start(void* thisx);
void TransitionCircle_Update(void* thisx, s32 updateRate);
#else
void TransitionCircle_Destroy(void* thisx);
void TransitionCircle_Draw(void* thisx, Gfx** gfxP);
void* TransitionCircle_Init(void* thisx);
s32 TransitionCircle_IsDone(void* thisx);
void TransitionCircle_SetColor(void* thisx, u32 color);
void TransitionCircle_SetEnvColor(void* thisx, u32 color);
void TransitionCircle_SetType(void* thisx, s32 type);
void TransitionCircle_Start(void* thisx);
void TransitionCircle_Update(void* thisx, s32 updateRate);
#endif

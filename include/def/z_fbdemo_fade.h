#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FBDEMO_FADE_C
void TransitionFade_Destroy(void* this);
void TransitionFade_Draw(void* this, Gfx** gfxP);
void* TransitionFade_Init(void* this);
s32 TransitionFade_IsDone(void* this);
void TransitionFade_SetColor(void* this, u32 color);
void TransitionFade_SetType(void* this, s32 type);
void TransitionFade_Start(void* this);
void TransitionFade_Update(void* this, s32 updateRate);
#else
void TransitionFade_Destroy(void* this);
void TransitionFade_Draw(void* this, Gfx** gfxP);
void* TransitionFade_Init(void* this);
s32 TransitionFade_IsDone(void* this);
void TransitionFade_SetColor(void* this, u32 color);
void TransitionFade_SetType(void* this, s32 type);
void TransitionFade_Start(void* this);
void TransitionFade_Update(void* this, s32 updateRate);
#endif

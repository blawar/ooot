#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FBDEMO_WIPE1_C
void TransitionWipe_Destroy(void* this);
void TransitionWipe_Draw(void* this, Gfx** gfxP);
void* TransitionWipe_Init(void* this);
s32 TransitionWipe_IsDone(void* this);
void TransitionWipe_SetColor(void* this, u32 color);
void TransitionWipe_SetType(void* this, s32 type);
void TransitionWipe_Start(void* this);
void TransitionWipe_Update(void* this, s32 updateRate);
#else
void TransitionWipe_Destroy(void* this);
void TransitionWipe_Draw(void* this, Gfx** gfxP);
void* TransitionWipe_Init(void* this);
s32 TransitionWipe_IsDone(void* this);
void TransitionWipe_SetColor(void* this, u32 color);
void TransitionWipe_SetType(void* this, s32 type);
void TransitionWipe_Start(void* this);
void TransitionWipe_Update(void* this, s32 updateRate);
#endif

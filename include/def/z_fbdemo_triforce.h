#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FBDEMO_TRIFORCE_C
void TransitionTriforce_Destroy(void* this);
void TransitionTriforce_Draw(void* this, Gfx** gfxP);
void* TransitionTriforce_Init(void* this);
s32 TransitionTriforce_IsDone(void* this);
void TransitionTriforce_SetColor(void* this, u32 color);
void TransitionTriforce_SetType(void* this, s32 type);
void TransitionTriforce_Start(void* this);
void TransitionTriforce_Update(void* this, s32 updateRate);
#else
void TransitionTriforce_Destroy(void* this);
void TransitionTriforce_Draw(void* this, Gfx** gfxP);
void* TransitionTriforce_Init(void* this);
s32 TransitionTriforce_IsDone(void* this);
void TransitionTriforce_SetColor(void* this, u32 color);
void TransitionTriforce_SetType(void* this, s32 type);
void TransitionTriforce_Start(void* this);
void TransitionTriforce_Update(void* this, s32 updateRate);
#endif

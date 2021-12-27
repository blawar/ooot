#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FBDEMO_C
void TransitionUnk_Destroy(TransitionUnk* this);
void TransitionUnk_Draw(TransitionUnk* this, Gfx**);
TransitionUnk* TransitionUnk_Init(TransitionUnk* this, s32 row, s32 col);
void TransitionUnk_InitData(TransitionUnk* this);
void TransitionUnk_InitGraphics(TransitionUnk* this);
void TransitionUnk_SetData(TransitionUnk* this);
void func_800B23E8(TransitionUnk* this);
#else
void TransitionUnk_Destroy(struct TransitionUnk* this);
void TransitionUnk_Draw(struct TransitionUnk* this, Gfx**);
struct TransitionUnk* TransitionUnk_Init(struct TransitionUnk* this, s32 row, s32 col);
void TransitionUnk_InitData(struct TransitionUnk* this);
void TransitionUnk_InitGraphics(struct TransitionUnk* this);
void TransitionUnk_SetData(struct TransitionUnk* this);
void func_800B23E8(struct TransitionUnk* this);
#endif

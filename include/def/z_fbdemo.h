#pragma once
struct TransitionUnk;

void TransitionUnk_Destroy(TransitionUnk* pthis);
void TransitionUnk_Draw(TransitionUnk* pthis, Gfx**);
TransitionUnk* TransitionUnk_Init(TransitionUnk* pthis, s32 row, s32 col);
void TransitionUnk_InitData(TransitionUnk* pthis);
void TransitionUnk_InitGraphics(TransitionUnk* pthis);
void TransitionUnk_SetData(TransitionUnk* pthis);
void func_800B23E8(TransitionUnk* pthis);

#pragma once

void TransitionWipe_Destroy(void* pthis);
void TransitionWipe_Draw(void* pthis, Gfx** gfxP);
void* TransitionWipe_Init(void* pthis);
s32 TransitionWipe_IsDone(void* pthis);
void TransitionWipe_SetColor(void* pthis, u32 color);
void TransitionWipe_SetType(void* pthis, s32 type);
void TransitionWipe_Start(void* pthis);
void TransitionWipe_Update(void* pthis, s32 updateRate);

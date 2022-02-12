#pragma once

void TransitionFade_Destroy(void* pthis);
void TransitionFade_Draw(void* pthis, Gfx** gfxP);
void* TransitionFade_Init(void* pthis);
s32 TransitionFade_IsDone(void* pthis);
void TransitionFade_SetColor(void* pthis, u32 color);
void TransitionFade_SetType(void* pthis, s32 type);
void TransitionFade_Start(void* pthis);
void TransitionFade_Update(void* pthis, s32 updateRate);

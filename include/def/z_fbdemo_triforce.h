#pragma once

void TransitionTriforce_Destroy(void* pthis);
void TransitionTriforce_Draw(void* pthis, Gfx** gfxP);
void* TransitionTriforce_Init(void* pthis);
s32 TransitionTriforce_IsDone(void* pthis);
void TransitionTriforce_SetColor(void* pthis, u32 color);
void TransitionTriforce_SetType(void* pthis, s32 type);
void TransitionTriforce_Start(void* pthis);
void TransitionTriforce_Update(void* pthis, s32 updateRate);

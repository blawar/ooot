#pragma once

void TransitionCircle_Destroy(void* pthisx);
void TransitionCircle_Draw(void* pthisx, Gfx** gfxP);
void* TransitionCircle_Init(void* pthisx);
s32 TransitionCircle_IsDone(void* pthisx);
void TransitionCircle_SetColor(void* pthisx, u32 color);
void TransitionCircle_SetEnvColor(void* pthisx, u32 color);
void TransitionCircle_SetType(void* pthisx, s32 type);
void TransitionCircle_Start(void* pthisx);
void TransitionCircle_Update(void* pthisx, s32 updateRate);

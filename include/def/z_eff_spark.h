#pragma once
struct GraphicsContext;

void EffectSpark_Destroy(void* pthisx);
void EffectSpark_Draw(void* pthisx, GraphicsContext* gfxCtx);
void EffectSpark_Init(void* pthisx, void* initParamsx);
s32 EffectSpark_Update(void* pthisx);

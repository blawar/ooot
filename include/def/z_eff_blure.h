#pragma once
struct EffectBlure;
struct Vec3f;
struct GraphicsContext;

void EffectBlure_AddSpace(EffectBlure* pthis);
void EffectBlure_AddVertex(EffectBlure* pthis, Vec3f* p1, Vec3f* p2);
void EffectBlure_Destroy(void* pthisx);
void EffectBlure_Draw(void* pthisx, GraphicsContext* gfxCtx);
void EffectBlure_Init1(void* pthisx, void* initParamsx);
void EffectBlure_Init2(void* pthisx, void* initParamsx);
s32 EffectBlure_Update(void* pthisx);

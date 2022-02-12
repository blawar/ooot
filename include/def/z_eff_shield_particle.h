#pragma once
struct GraphicsContext;

void EffectShieldParticle_Destroy(void* pthisx);
void EffectShieldParticle_Draw(void* pthisx, GraphicsContext* gfxCtx);
void EffectShieldParticle_Init(void* pthisx, void* initParamsx);
s32 EffectShieldParticle_Update(void* pthisx);

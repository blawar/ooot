#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EFF_SHIELD_PARTICLE_C
void EffectShieldParticle_Destroy(void* thisx);
void EffectShieldParticle_Draw(void* thisx, GraphicsContext* gfxCtx);
void EffectShieldParticle_Init(void* thisx, void* initParamsx);
s32 EffectShieldParticle_Update(void* thisx);
#else
void EffectShieldParticle_Destroy(void* thisx);
void EffectShieldParticle_Draw(void* thisx, struct GraphicsContext* gfxCtx);
void EffectShieldParticle_Init(void* thisx, void* initParamsx);
s32 EffectShieldParticle_Update(void* thisx);
#endif

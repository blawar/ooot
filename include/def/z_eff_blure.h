#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EFF_BLURE_C
void EffectBlure_AddSpace(EffectBlure* this);
void EffectBlure_AddVertex(EffectBlure* this, Vec3f* p1, Vec3f* p2);
void EffectBlure_Destroy(void* thisx);
void EffectBlure_Draw(void* thisx, GraphicsContext* gfxCtx);
void EffectBlure_Init1(void* thisx, void* initParamsx);
void EffectBlure_Init2(void* thisx, void* initParamsx);
s32 EffectBlure_Update(void* thisx);
#else
void EffectBlure_AddSpace(struct EffectBlure* this);
void EffectBlure_AddVertex(struct EffectBlure* this, struct Vec3f* p1, struct Vec3f* p2);
void EffectBlure_Destroy(void* thisx);
void EffectBlure_Draw(void* thisx, struct GraphicsContext* gfxCtx);
void EffectBlure_Init1(void* thisx, void* initParamsx);
void EffectBlure_Init2(void* thisx, void* initParamsx);
s32 EffectBlure_Update(void* thisx);
#endif

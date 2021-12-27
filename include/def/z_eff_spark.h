#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EFF_SPARK_C
void EffectSpark_Destroy(void* thisx);
void EffectSpark_Draw(void* thisx, GraphicsContext* gfxCtx);
void EffectSpark_Init(void* thisx, void* initParamsx);
s32 EffectSpark_Update(void* thisx);
#else
void EffectSpark_Destroy(void* thisx);
void EffectSpark_Draw(void* thisx, struct GraphicsContext* gfxCtx);
void EffectSpark_Init(void* thisx, void* initParamsx);
s32 EffectSpark_Update(void* thisx);
#endif

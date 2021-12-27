#pragma once
#ifdef INTERNAL_SRC_CODE_Z_LIFEMETER_C
void HealthMeter_Draw(GlobalContext* globalCtx);
void HealthMeter_UpdateBeatingHeart(GlobalContext* globalCtx);
void HealthMeter_Init(GlobalContext* globalCtx);
u32 HealthMeter_IsCritical(void);
void HealthMeter_Update(GlobalContext* globalCtx);
#else
void HealthMeter_Draw(struct GlobalContext* globalCtx);
void HealthMeter_UpdateBeatingHeart(struct GlobalContext* globalCtx);
void HealthMeter_Init(struct GlobalContext* globalCtx);
u32 HealthMeter_IsCritical(void);
void HealthMeter_Update(struct GlobalContext* globalCtx);
#endif

#pragma once
struct GlobalContext;

void HealthMeter_Draw(GlobalContext* globalCtx);
void HealthMeter_Init(GlobalContext* globalCtx);
u32 HealthMeter_IsCritical(void);
void HealthMeter_Update(GlobalContext* globalCtx);
void HealthMeter_UpdateBeatingHeart(GlobalContext* globalCtx);

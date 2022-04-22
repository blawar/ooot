#pragma once
struct GlobalContext;
struct EffectSs;

void EffectSs_ClearAll(GlobalContext* globalCtx);
void EffectSs_Delete(EffectSs* effectSs);
void EffectSs_DrawAll(GlobalContext* globalCtx);
void EffectSs_InitInfo(GlobalContext* globalCtx, s32 tableSize);
void EffectSs_Insert(GlobalContext* globalCtx, EffectSs* effectSs);
void EffectSs_Reset(EffectSs* effectSs);
void EffectSs_Spawn(GlobalContext* globalCtx, s32 type, s32 priority, void* initParams);
void EffectSs_UpdateAll(GlobalContext* globalCtx);
s16 func_80027DD4(s16 arg0, s16 arg1, s32 arg2);
s16 func_80027E34(s16 arg0, s16 arg1, f32 arg2);
u8 func_80027E84(u8 arg0, u8 arg1, f32 arg2);

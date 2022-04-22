#pragma once
struct GlobalContext;

s32 Flags_GetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_SetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_UnsetAllEnv(GlobalContext* globalCtx);
void Flags_UnsetEnv(GlobalContext* globalCtx, s16 flag);

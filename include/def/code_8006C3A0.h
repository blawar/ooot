#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_8006C3A0_C
s32 Flags_GetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_SetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_UnsetAllEnv(GlobalContext* globalCtx);
void Flags_UnsetEnv(GlobalContext* globalCtx, s16 flag);
#else
s32 Flags_GetEnv(struct GlobalContext* globalCtx, s16 flag);
void Flags_SetEnv(struct GlobalContext* globalCtx, s16 flag);
void Flags_UnsetAllEnv(struct GlobalContext* globalCtx);
void Flags_UnsetEnv(struct GlobalContext* globalCtx, s16 flag);
#endif

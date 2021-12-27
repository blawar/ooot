#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_8006BA00_C
void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos, s32 duration, u16 sfxId);
void func_8006BA00(GlobalContext* globalCtx);
void func_8006BA30(GlobalContext* globalCtx);
#else
void Audio_PlaySoundAtPosition(struct GlobalContext* globalCtx, struct Vec3f* pos, s32 duration, u16 sfxId);
void func_8006BA00(struct GlobalContext* globalCtx);
void func_8006BA30(struct GlobalContext* globalCtx);
#endif

#pragma once
struct GlobalContext;
struct Vec3f;

void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos, s32 duration, u16 sfxId);
void func_8006BA00(GlobalContext* globalCtx);
void func_8006BA30(GlobalContext* globalCtx);

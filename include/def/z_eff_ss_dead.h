#pragma once
#ifdef INTERNAL_SRC_CODE_Z_EFF_SS_DEAD_C
void func_80026230(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026400(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026608(GlobalContext* globalCtx);
void func_80026690(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026860(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026A6C(GlobalContext* globalCtx);
#else
void func_80026230(struct GlobalContext* globalCtx, struct Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026400(struct GlobalContext* globalCtx, struct Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026608(struct GlobalContext* globalCtx);
void func_80026690(struct GlobalContext* globalCtx, struct Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026860(struct GlobalContext* globalCtx, struct Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026A6C(struct GlobalContext* globalCtx);
#endif

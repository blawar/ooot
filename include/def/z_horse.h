#pragma once
#ifdef INTERNAL_SRC_CODE_Z_HORSE_C
s32 func_8006CFC0(s32 scene);
void func_8006D074(GlobalContext* globalCtx);
void func_8006D0AC(GlobalContext* globalCtx);
void func_8006D0EC(GlobalContext* globalCtx, Player* player);
void func_8006D684(GlobalContext* globalCtx, Player* player);
void func_8006DC68(GlobalContext* globalCtx, Player* player);
void func_8006DD9C(Actor* actor, Vec3f* arg1, s16 arg2);
#else
s32 func_8006CFC0(s32 scene);
void func_8006D074(struct GlobalContext* globalCtx);
void func_8006D0AC(struct GlobalContext* globalCtx);
void func_8006D0EC(struct GlobalContext* globalCtx, struct Player* player);
void func_8006D684(struct GlobalContext* globalCtx, struct Player* player);
void func_8006DC68(struct GlobalContext* globalCtx, struct Player* player);
void func_8006DD9C(struct Actor* actor, struct Vec3f* arg1, s16 arg2);
#endif

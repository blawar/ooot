#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_800430A0_C
void func_80043334(CollisionContext* colCtx, Actor* actor, s32 bgId);
s32 func_800433A4(CollisionContext* colCtx, s32 bgId, Actor* actor);
#else
void func_80043334(struct CollisionContext* colCtx, struct Actor* actor, s32 bgId);
s32 func_800433A4(struct CollisionContext* colCtx, s32 bgId, struct Actor* actor);
#endif

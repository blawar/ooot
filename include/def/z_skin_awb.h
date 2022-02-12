#pragma once
struct GlobalContext;
struct PSkinAwb;
struct SkeletonHeader;
struct AnimationHeader;
struct SkinLimb;
struct Actor;

void func_800A6460(GlobalContext* globalCtx, PSkinAwb* skin, s32 arg2);
void func_800A663C(GlobalContext* globalCtx, PSkinAwb* skin, SkeletonHeader* skeletonHeader, AnimationHeader* animationHeader);
void func_800A6888(GlobalContext* globalCtx, PSkinAwb* skin);
s32 func_800A698C(PSkinAwb* skin, SkinLimb** limbs, MtxF* arg2, u8 arg3, u8 arg4);
s32 func_800A6AC4(PSkinAwb* skin, MtxF* arg1, Actor* actor, s32 arg3);

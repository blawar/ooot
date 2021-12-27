#pragma once
#ifdef INTERNAL_SRC_CODE_Z_SKIN_AWB_C
void func_800A6460(GlobalContext* globalCtx, PSkinAwb* skin, s32 arg2);
void func_800A663C(GlobalContext* globalCtx, PSkinAwb* skin, SkeletonHeader* skeletonHeader, AnimationHeader* animationHeader);
void func_800A6888(GlobalContext* globalCtx, PSkinAwb* skin);
s32 func_800A698C(PSkinAwb* skin, SkinLimb** limbs, MtxF* arg2, u8 arg3, u8 arg4);
s32 func_800A6AC4(PSkinAwb* skin, MtxF* arg1, Actor* actor, s32 arg3);
#else
void func_800A6460(struct GlobalContext* globalCtx, struct PSkinAwb* skin, s32 arg2);
void func_800A663C(struct GlobalContext* globalCtx, struct PSkinAwb* skin, struct SkeletonHeader* skeletonHeader, struct AnimationHeader* animationHeader);
void func_800A6888(struct GlobalContext* globalCtx, struct PSkinAwb* skin);
s32 func_800A698C(struct PSkinAwb* skin, struct SkinLimb** limbs, MtxF* arg2, u8 arg3, u8 arg4);
s32 func_800A6AC4(struct PSkinAwb* skin, MtxF* arg1, struct Actor* actor, s32 arg3);
#endif

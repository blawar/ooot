#pragma once
#ifdef INTERNAL_SRC_CODE_Z_SKIN_C
void func_800A57C0(MtxF* mtx, Struct_800A57C0* arg1, Struct_800A598C* arg2, Vtx* arg3, Vec3f* arg4);
void func_800A598C(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3);
void func_800A5E28(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3, s32 arg4);
void func_800A5F60(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, Gfx* arg3, s32 arg4);
void func_800A60D8(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_800A6330(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, s32 arg4);
void func_800A6360(Actor* this, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5);
void func_800A63CC(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_800A6408(PSkinAwb* skin, s32 joint, Vec3f* arg2, Vec3f* arg3);
#else
void func_800A57C0(MtxF* mtx, struct Struct_800A57C0* arg1, struct Struct_800A598C* arg2, Vtx* arg3, struct Vec3f* arg4);
void func_800A598C(struct GraphicsContext* gfxCtx, struct PSkinAwb* skin, s32 limbIndex, s32 arg3);
void func_800A5E28(struct GraphicsContext* gfxCtx, struct PSkinAwb* skin, s32 limbIndex, s32 arg3, s32 arg4);
void func_800A5F60(struct GraphicsContext* gfxCtx, struct PSkinAwb* skin, s32 limbIndex, Gfx* arg3, s32 arg4);
void func_800A60D8(struct Actor* actor, struct GlobalContext* globalCtx, struct PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_800A6330(struct Actor* actor, struct GlobalContext* globalCtx, struct PSkinAwb* skin, SkinCallback callback, s32 arg4);
void func_800A6360(struct Actor* this, struct GlobalContext* globalCtx, struct PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5);
void func_800A63CC(struct Actor* actor, struct GlobalContext* globalCtx, struct PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_800A6408(struct PSkinAwb* skin, s32 joint, struct Vec3f* arg2, struct Vec3f* arg3);
#endif

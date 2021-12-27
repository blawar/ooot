#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_80043480_C
void DynaPolyActor_Init(DynaPolyActor* dynaActor, s32 flags);
void func_800434A0(DynaPolyActor* dynaActor);
void func_800434A8(DynaPolyActor* dynaActor);
void func_800434C8(CollisionContext* colCtx, s32 floorBgId);
void func_80043508(CollisionContext* colCtx, s32 floorBgId);
void func_80043538(DynaPolyActor* dynaActor);
s32 func_80043548(DynaPolyActor* dynaActor);
s32 func_8004356C(DynaPolyActor* dynaActor);
s32 func_80043590(DynaPolyActor* dynaActor);
s32 func_800435B4(DynaPolyActor* dynaActor);
s32 func_800435D8(GlobalContext* globalCtx, DynaPolyActor* dynaActor, s16 arg2, s16 arg3, s16 arg4);
#else
void DynaPolyActor_Init(struct DynaPolyActor* dynaActor, s32 flags);
void func_800434A0(struct DynaPolyActor* dynaActor);
void func_800434A8(struct DynaPolyActor* dynaActor);
void func_800434C8(struct CollisionContext* colCtx, s32 floorBgId);
void func_80043508(struct CollisionContext* colCtx, s32 floorBgId);
void func_80043538(struct DynaPolyActor* dynaActor);
s32 func_80043548(struct DynaPolyActor* dynaActor);
s32 func_8004356C(struct DynaPolyActor* dynaActor);
s32 func_80043590(struct DynaPolyActor* dynaActor);
s32 func_800435B4(struct DynaPolyActor* dynaActor);
s32 func_800435D8(struct GlobalContext* globalCtx, struct DynaPolyActor* dynaActor, s16 arg2, s16 arg3, s16 arg4);
#endif

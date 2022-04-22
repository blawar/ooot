#pragma once
struct GameState;
struct GraphicsContext;
struct Vec3s;
struct Vec3f;

extern Mtx gMtxClear;
extern MtxF gMtxFClear;

MtxF* Matrix_CheckFloats(MtxF* mf, char* file, s32 line);
void Matrix_Get(MtxF* dest);
void Matrix_Init(GameState* gameState);
void Matrix_MtxFCopy(MtxF* dest, MtxF* src);
Mtx* Matrix_MtxFToMtx(MtxF* src, Mtx* dest);
Mtx* Matrix_MtxFToNewMtx(MtxF* src, GraphicsContext* gfxCtx);
void Matrix_MtxFToYXZRotS(MtxF* mf, Vec3s* rotDest, s32 flag);
void Matrix_MtxFToZYXRotS(MtxF* mf, Vec3s* rotDest, s32 flag);
void Matrix_MtxToMtxF(Mtx* src, MtxF* dest);
void Matrix_Mult(MtxF* mf, u8 mode);
void Matrix_MultVec3f(Vec3f* src, Vec3f* dest);
void Matrix_MultVec3fExt(Vec3f* src, Vec3f* dest, MtxF* mf);
Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx, const char* file, s32 line);
void Matrix_Pop(void);
void Matrix_Push(void);
void Matrix_Put(MtxF* src);
void Matrix_RotateAxis(f32 f, Vec3f* vec, u8 mode);
void Matrix_RotateX(f32 x, u8 mode);
void Matrix_RotateY(f32 y, u8 mode);
void Matrix_RotateZ(f32 z, u8 mode);
void Matrix_RotateZYX(s16 x, s16 y, s16 z, u8 mode);
void Matrix_Scale(f32 x, f32 y, f32 z, u8 mode);
void Matrix_ScaleTrans(Mtx* mtx, f32 scaleX, f32 scaleY, f32 scaleZ, f32 posX, f32 posY, f32 posZ);
Mtx* Matrix_ToMtx(Mtx* dest, const char* file, s32 line);
void Matrix_Translate(f32 x, f32 y, f32 z, u8 mode);
void Matrix_TranslateRotateZYX(Vec3f* translation, Vec3s* rotation);
void Matrix_Transpose(MtxF* mf);
void func_800D1694(f32 x, f32 y, f32 z, Vec3s* vec);
void func_800D1FD4(MtxF* mf);

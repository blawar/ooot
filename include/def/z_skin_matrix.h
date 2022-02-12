#pragma once
struct GraphicsContext;
struct Vec3f;

void SkinMatrix_GetClear(MtxF** mf);
s32 SkinMatrix_Invert(MtxF* src, MtxF* dest);
void SkinMatrix_MtxFCopy(MtxF* src, MtxF* dest);
void SkinMatrix_MtxFMtxFMult(MtxF* mfA, MtxF* mfB, MtxF* dest);
Mtx* SkinMatrix_MtxFToNewMtx(GraphicsContext* gfxCtx, MtxF* src);
void SkinMatrix_SetRotateZYX(MtxF* mf, s16 x, s16 y, s16 z);
void SkinMatrix_SetScale(MtxF* mf, f32 x, f32 y, f32 z);
void SkinMatrix_SetTranslate(MtxF* mf, f32 x, f32 y, f32 z);
void SkinMatrix_SetTranslateRotateYXZScale(MtxF* dest, f32 scaleX, f32 scaleY, f32 scaleZ, s16 rotX, s16 rotY, s16 rotZ, f32 translateX, f32 translateY, f32 translateZ);
void SkinMatrix_SetTranslateRotateZYX(MtxF* dest, s16 rotX, s16 rotY, s16 rotZ, f32 translateX, f32 translateY, f32 translateZ);
void SkinMatrix_Vec3fMtxFMultXYZ(MtxF* mf, Vec3f* src, Vec3f* dest);
void SkinMatrix_Vec3fMtxFMultXYZW(MtxF* mf, Vec3f* src, Vec3f* xyzDest, f32* wDest);
void func_800A7EC0(MtxF* mf, s16 a, f32 x, f32 y, f32 z);

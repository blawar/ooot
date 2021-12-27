#pragma once
#ifdef INTERNAL_SRC_CODE_Z_OLIB_C
f32 OLib_ClampMaxDist(f32 val, f32 max);
f32 OLib_ClampMinDist(f32 val, f32 min);
Vec3f* OLib_Vec3fDiffRad(Vec3f* dest, Vec3f* a, Vec3f* b);
VecSph* OLib_Vec3fDiffToVecSphGeo(VecSph* arg0, Vec3f* a, Vec3f* b);
f32 OLib_Vec3fDist(Vec3f* a, Vec3f* b);
Vec3f* OLib_Vec3fDistNormalize(Vec3f* dest, Vec3f* a, Vec3f* b);
f32 OLib_Vec3fDistXZ(Vec3f* a, Vec3f* b);
VecSph* OLib_Vec3fToVecSph(VecSph* dest, Vec3f* vec);
VecSph* OLib_Vec3fToVecSphGeo(VecSph* arg0, Vec3f* arg1);
Vec3f* OLib_VecSphGeoToVec3f(Vec3f* dest, VecSph* sph);
#else
f32 OLib_ClampMaxDist(f32 val, f32 max);
f32 OLib_ClampMinDist(f32 val, f32 min);
struct Vec3f* OLib_Vec3fDiffRad(struct Vec3f* dest, struct Vec3f* a, struct Vec3f* b);
struct VecSph* OLib_Vec3fDiffToVecSphGeo(struct VecSph* arg0, struct Vec3f* a, struct Vec3f* b);
f32 OLib_Vec3fDist(struct Vec3f* a, struct Vec3f* b);
struct Vec3f* OLib_Vec3fDistNormalize(struct Vec3f* dest, struct Vec3f* a, struct Vec3f* b);
f32 OLib_Vec3fDistXZ(struct Vec3f* a, struct Vec3f* b);
struct VecSph* OLib_Vec3fToVecSph(struct VecSph* dest, struct Vec3f* vec);
struct VecSph* OLib_Vec3fToVecSphGeo(struct VecSph* arg0, struct Vec3f* arg1);
struct Vec3f* OLib_VecSphGeoToVec3f(struct Vec3f* dest, struct VecSph* sph);
#endif

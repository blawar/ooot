#pragma once
struct Vec3f;
struct VecSph;

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

#pragma once
#ifdef INTERNAL_SRC_CODE_Z_QUAKE_C
s16 Quake_Add(Camera* cam, u32 callbackIdx);
QuakeRequest* Quake_AddImpl(Camera* cam, u32 callbackIdx);
Vec3f* Quake_AddVec(Vec3f* dst, Vec3f* arg1, VecSph* arg2);
s16 Quake_Calc(Camera* camera, QuakeCamCalc* camData);
s16 Quake_Callback1(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback2(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback3(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback4(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback5(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback6(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_GetCountdown(s16 idx);
s16 Quake_GetFreeIndex(void);
QuakeRequest* Quake_GetRequest(s16 idx);
void Quake_Init(void);
void Quake_Remove(QuakeRequest* req);
u32 Quake_RemoveFromIdx(s16 idx);
u32 Quake_SetCountdown(s16 idx, s16 value);
u32 Quake_SetQuakeValues(s16 idx, s16 y, s16 x, s16 zoom, s16 rotZ);
u32 Quake_SetSpeed(s16 idx, s16 value);
u32 Quake_SetUnkValues(s16 idx, s16 arg1, SubQuakeRequest14 arg2);
QuakeRequest* Quake_SetValue(s16 idx, s16 valueType, s16 value);
void Quake_UpdateShakeInfo(QuakeRequest* req, ShakeInfo* shake, f32 y, f32 x);
#else
s16 Quake_Add(struct Camera* cam, u32 callbackIdx);
struct QuakeRequest* Quake_AddImpl(struct Camera* cam, u32 callbackIdx);
struct Vec3f* Quake_AddVec(struct Vec3f* dst, struct Vec3f* arg1, struct VecSph* arg2);
s16 Quake_Calc(struct Camera* camera, struct QuakeCamCalc* camData);
s16 Quake_Callback1(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_Callback2(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_Callback3(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_Callback4(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_Callback5(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_Callback6(struct QuakeRequest* req, struct ShakeInfo* shake);
s16 Quake_GetCountdown(s16 idx);
s16 Quake_GetFreeIndex(void);
struct QuakeRequest* Quake_GetRequest(s16 idx);
void Quake_Init(void);
void Quake_Remove(struct QuakeRequest* req);
u32 Quake_RemoveFromIdx(s16 idx);
u32 Quake_SetCountdown(s16 idx, s16 value);
u32 Quake_SetQuakeValues(s16 idx, s16 y, s16 x, s16 zoom, s16 rotZ);
u32 Quake_SetSpeed(s16 idx, s16 value);
u32 Quake_SetUnkValues(s16 idx, s16 arg1, struct SubQuakeRequest14 arg2);
struct QuakeRequest* Quake_SetValue(s16 idx, s16 valueType, s16 value);
void Quake_UpdateShakeInfo(struct QuakeRequest* req, struct ShakeInfo* shake, f32 y, f32 x);
#endif

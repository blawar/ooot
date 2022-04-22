#pragma once
#include "unk.h"

struct Camera;
struct Actor;
struct Vec3s;
struct Vec3f;
struct View;
struct CollisionContext;
#include "globalctx.h"
struct Player;
struct CutsceneCameraPoint;

s32 Camera_AddQuake(Camera* camera, s32 arg1, s16 y, s32 countdown);
s32 Camera_ChangeDataIdx(Camera* camera, s32 camDataIdx);
s32 Camera_ChangeDoorCam(Camera* camera, Actor* doorActor, s16 camDataIdx, f32 arg3, s16 timer1, s16 timer2, s16 timer3);
s32 Camera_ChangeMode(Camera* camera, s16 mode);
s32 Camera_ChangeSetting(Camera* camera, s16 setting);
s16 Camera_ChangeStatus(Camera* camera, s16 status);
s32 Camera_CheckValidMode(Camera* camera, s16 mode);
s32 Camera_Copy(Camera* dstCamera, Camera* srcCamera);
void Camera_Finish(Camera* camera);
Vec3s* Camera_GetCamDir(Vec3s* dir, Camera* camera);
s16 Camera_GetCamDirPitch(Camera* camera);
s16 Camera_GetCamDirYaw(Camera* camera);
s16 Camera_GetInputDirYaw(Camera* camera);
Vec3f* Camera_GetSkyboxOffset(Vec3f* dst, Camera* camera);
void Camera_Init(Camera* camera, View* view, CollisionContext* colCtx, GlobalContext* globalCtx);
void Camera_InitPlayerSettings(Camera* camera, Player* player);
s32 Camera_ResetAnim(Camera* camera);
s32 Camera_SetCSParams(Camera* camera, CutsceneCameraPoint* atPoints, CutsceneCameraPoint* eyePoints, Player* player, s16 relativeToPlayer);
void Camera_SetCameraData(Camera* camera, s16 setDataFlags, void* data0, void* data1, s16 data2, s16 data3, UNK_TYPE arg6);
s32 Camera_SetParam(Camera* camera, s32 param, void* value);
Vec3s Camera_Update(Camera* camera);
s32 func_8005AC48(Camera* camera, s16 arg1);
s16 func_8005ACFC(Camera* camera, s16 arg1);
s16 func_8005AD1C(Camera* camera, s16 arg1);
s32 func_8005B198(void);
s16 func_8005B1A4(Camera* camera);

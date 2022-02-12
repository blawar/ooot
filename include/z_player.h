#pragma once
#include "z64global.h"
#include "gfx.h"
#include "z64math.h"
/*
s32 func_800902F0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090440(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);

s32 Player_IsFacingActor(struct Actor* actor, s16 angle, struct GlobalContext* globalCtx);
f32 Player_GetHeight(struct Player* player);
void Player_SetBootData(struct GlobalContext* globalCtx, struct Player* player);
s32 Player_InBlockingCsMode(struct GlobalContext* globalCtx, struct Player* player);
s32 Player_InCsMode(struct GlobalContext* globalCtx);
s32 func_8008E9C4(struct Player* player);
s32 Player_IsChildWithHylianShield(struct Player* player);
s32 Player_ActionToModelGroup(struct Player* player, s32 actionParam);
void Player_SetModelsForHoldingShield(struct Player* player);
void Player_SetModels(struct Player* player, s32 modelGroup);
void Player_SetModelGroup(struct Player* player, s32 modelGroup);
void func_8008EC70(struct Player* player);
void Player_SetEquipmentData(struct GlobalContext* globalCtx, struct Player* player);
void Player_UpdateBottleHeld(struct GlobalContext* globalCtx, struct Player* player, s32 item, s32 actionParam);
s32 Player_IsBurningStickInRange(struct GlobalContext* globalCtx, Vec3f* pos, f32 radius, f32 arg3);
s32 Player_GetStrength(void);
u8 Player_GetMask(struct GlobalContext* globalCtx);
struct Player* Player_UnsetMask(struct GlobalContext* globalCtx);
s32 Player_HasMirrorShieldEquipped(struct GlobalContext* globalCtx);
s32 Player_HasMirrorShieldSetToDraw(struct GlobalContext* globalCtx);
s32 Player_ActionToMagicSpell(struct Player* player, s32 actionParam);
s32 Player_HoldsHookshot(struct Player* player);
s32 func_8008F128(struct Player* player);
s32 Player_ActionToSword(s32 actionParam);
s32 Player_GetSwordHeld(struct Player* player);
s32 Player_HoldsTwoHandedWeapon(struct Player* player);
s32 Player_HoldsBrokenKnife(struct Player* player);
s32 Player_ActionToBottle(struct Player* player, s32 actionParam);
s32 Player_GetBottleHeld(struct Player* player);
s32 Player_ActionToExplosive(struct Player* player, s32 actionParam);
s32 Player_GetExplosiveHeld(struct Player* player);
void Player_DrawGetItem(struct GlobalContext* globalCtx, struct Player* player);


Gfx* Gameplay_SetFog(struct GlobalContext* globalCtx, Gfx* gfx);
void Gameplay_Destroy(GameState* thissx);
void Gameplay_Init(GameState* thissx);
void Gameplay_Main(GameState* thissx);
s32 Gameplay_InCsMode(struct GlobalContext* globalCtx);
f32 func_800BFCB8(struct GlobalContext* globalCtx, MtxF* mf, struct Vec3f* vec);
void* Gameplay_LoadFile(struct GlobalContext* globalCtx, RomFile* file);
void Gameplay_SpawnScene(struct GlobalContext* globalCtx, s32 sceneNum, s32 spawn);
void func_800C016C(struct GlobalContext* globalCtx, struct Vec3f* src, struct Vec3f* dest);
s16 Gameplay_CreateSubCamera(struct GlobalContext* globalCtx);
s16 Gameplay_GetActiveCamId(struct GlobalContext* globalCtx);
s16 Gameplay_ChangeCameraStatus(struct GlobalContext* globalCtx, s16 camId, s16 status);
void Gameplay_ClearCamera(struct GlobalContext* globalCtx, s16 camId);
void Gameplay_ClearAllSubCameras(struct GlobalContext* globalCtx);
Camera* Gameplay_GetCamera(struct GlobalContext* globalCtx, s16 camId);
s32 Gameplay_CameraSetAtEye(struct GlobalContext* globalCtx, s16 camId, struct Vec3f* at, struct Vec3f* eye);
s32 Gameplay_CameraSetAtEyeUp(struct GlobalContext* globalCtx, s16 camId, struct Vec3f* at, struct Vec3f* eye, struct Vec3f* up);
s32 Gameplay_CameraSetFov(struct GlobalContext* globalCtx, s16 camId, f32 fov);
s32 Gameplay_SetCameraRoll(struct GlobalContext* globalCtx, s16 camId, s16 roll);
void Gameplay_CopyCamera(struct GlobalContext* globalCtx, s16 camId1, s16 camId2);
s32 func_800C0808(struct GlobalContext* globalCtx, s16 camId, struct Player* player, s16 arg3);
s32 Gameplay_CameraChangeSetting(struct GlobalContext* globalCtx, s16 camId, s16 arg2);
void func_800C08AC(struct GlobalContext* globalCtx, s16 camId, s16 arg2);
void Gameplay_SaveSceneFlags(struct GlobalContext* globalCtx);
void Gameplay_SetupRespawnPoint(struct GlobalContext* globalCtx, s32 respawnMode, s32 playerParams);
void Gameplay_TriggerVoidOut(struct GlobalContext* globalCtx);
void Gameplay_TriggerRespawn(struct GlobalContext* globalCtx);

void func_8008F470(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic,
                   s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* thiss); // z_player_lib
s32 func_8008FCC8(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090014(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_800902F0(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090440(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
u8 func_80090480(struct GlobalContext* globalCtx, ColliderQuad* collider, struct WeaponInfo* weaponDim, Vec3f* newTip,
                 Vec3f* newBase);


void func_80090D20(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* data); // z_player_lib
u32 func_80091738(struct GlobalContext* globalCtx, u8* segment, struct SkelAnime* skelAnime); // z_player_lib

void func_8009214C(struct GlobalContext* globalCtx, u8* segment, struct SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot, f32 scale,
s32 sword, s32 tunic, s32 shield, s32 boots); // z_player_lib

void func_8008EDF0(struct Player* player); // z_player_lib
void func_8008EE08(struct Player* player);
void func_8008EEAC(struct GlobalContext* globalCtx, Actor* actor);
s32 func_8008EF44(struct GlobalContext* globalCtx, s32 ammo); // z_player_lib

s32 func_8008F2BC(struct Player* player, s32 actionParam);
s32 func_8008F2F8(struct GlobalContext* globalCtx);

*/



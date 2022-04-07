#pragma once
#include "z64animation.h"

struct Player;
struct GlobalContext;
struct Vec3f;
struct Actor;
struct Vec3s;
struct ColliderQuad;
struct WeaponInfo;
struct SkelAnime;
struct FlexSkeletonHeader;
union Gfx;

extern Gfx* D_80125DE8[];
extern Gfx* D_80125E08[];
extern Gfx* D_80125E18[];
extern Gfx* D_80125EF8[];
extern Gfx gCullBackDList[];
extern Gfx gCullFrontDList[];
extern u8 gPlayerModelTypes[][5];
extern FlexSkeletonHeader* gPlayerSkelHeaders[2];

namespace oot::pause
{
	struct Segments;
}

s32 Player_ActionToBottle(Player* player, s32 actionParam);
s32 Player_ActionToExplosive(Player* player, s32 actionParam);
s32 Player_ActionToMagicSpell(Player* player, s32 actionParam);
s32 Player_ActionToModelGroup(Player* player, s32 actionParam);
s32 Player_ActionToSword(s32 actionParam);
void Player_DrawGetItem(GlobalContext* globalCtx, Player* player);
s32 Player_GetBottleHeld(Player* player);
s32 Player_GetExplosiveHeld(Player* player);
u8 Player_GetMask(GlobalContext* globalCtx);
s32 Player_GetStrength(void);
s32 Player_GetSwordHeld(Player* player);
s32 Player_HasMirrorShieldEquipped(GlobalContext* globalCtx);
s32 Player_HasMirrorShieldSetToDraw(GlobalContext* globalCtx);
s32 Player_HoldsBrokenKnife(Player* player);
s32 Player_HoldsHookshot(Player* player);
s32 Player_HoldsTwoHandedWeapon(Player* player);
s32 Player_InBlockingCsMode(GlobalContext* globalCtx, Player* player);
s32 Player_InCsMode(GlobalContext* globalCtx);
s32 Player_IsBurningStickInRange(GlobalContext* globalCtx, Vec3f* pos, f32 radius, f32 arg3);
s32 Player_IsChildWithHylianShield(Player* player);
void Player_SetBootData(GlobalContext* globalCtx, Player* player);
void Player_SetEquipmentData(GlobalContext* globalCtx, Player* player);
void Player_SetModelGroup(Player* player, s32 modelGroup);
void Player_SetModels(Player* player, s32 modelGroup);
void Player_SetModelsForHoldingShield(Player* player);
Player* Player_UnsetMask(GlobalContext* globalCtx);
void Player_UpdateBottleHeld(GlobalContext* globalCtx, Player* player, s32 item, s32 actionParam);
s32 func_8008E9C4(Player* player);
void func_8008EC70(Player* player);
void Player_ClearZTarget(Player* player);
void func_8008EE08(Player* player);
void func_8008EEAC(GlobalContext* globalCtx, Actor* actor);
s32 func_8008EF44(GlobalContext* globalCtx, s32 ammo);
s32 func_8008F128(Player* player);
s32 func_8008F2BC(Player* player, s32 actionParam);
s32 Player_GetRoomTimer(GlobalContext* globalCtx);
void func_8008F470(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic, s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* pthis);
s32 func_8008FCC8(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090014(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_800902F0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090440(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
u8 func_80090480(GlobalContext* globalCtx, ColliderQuad* collider, WeaponInfo* weaponDim, Vec3f* newTip, Vec3f* newBase);
void func_80090D20(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* data);
u32 func_80091738(GlobalContext* globalCtx, oot::pause::Segments* segment, SkelAnime* skelAnime);
void func_8009214C(GlobalContext* globalCtx, oot::pause::Segments* segment, SkelAnime* skelAnime, Vec3f* pos, Vec3s* rot, f32 scale, s32 sword, s32 tunic, s32 shield, s32 boots);
bool Player_ToggleBoots();
bool Player_ToggleSword();
bool Player_ToggleShield();
bool Player_ToggleTunic();
bool Player_EquipOcarina();
bool Player_EquipHookshot();
bool Player_EquipBow();
bool Player_EquipLensOfTruth();

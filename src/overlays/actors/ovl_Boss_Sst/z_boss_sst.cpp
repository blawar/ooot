#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_SST_Z_BOSS_SST_C
#include "actor_common.h"
/*
 * File: z_boss_sst.c
 * Overlay: ovl_Boss_Sst
 * Description: Bongo Bongo
 */

#include "z_boss_sst.h"
#include "objects/object_sst/object_sst.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "overlays/actors/ovl_Bg_Sst_Floor/z_bg_sst_floor.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "def/code_800A9F30.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin_matrix.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_10)

#define vParity actionVar
#define vVanish actionVar

#define LEFT 0
#define RIGHT 1
#define OTHER_HAND(hand) ((BossSst*)hand->actor.child)
#define HAND_STATE(hand) sHandState[hand->actor.params]

#define ROOM_CENTER_X -50.0f
#define ROOM_CENTER_Y 0.0f
#define ROOM_CENTER_Z 0.0f

typedef enum {
    /*  0 */ HAND_WAIT,
    /*  1 */ HAND_BEAT,
    /*  2 */ HAND_RETREAT,
    /*  3 */ HAND_SLAM,
    /*  4 */ HAND_SWEEP,
    /*  5 */ HAND_PUNCH,
    /*  6 */ HAND_CLAP,
    /*  7 */ HAND_GRAB,
    /*  8 */ HAND_DAMAGED,
    /*  9 */ HAND_FROZEN,
    /* 10 */ HAND_BREAK_ICE,
    /* 11 */ HAND_DEATH
} BossSstHandState;

typedef enum {
    /* 0 */ BONGO_NULL,
    /* 1 */ BONGO_ICE,
    /* 2 */ BONGO_SHOCKWAVE,
    /* 3 */ BONGO_SHADOW
} BossSstEffectMode;

void BossSst_Init(Actor* thisx, GlobalContext* globalCtx);
void BossSst_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossSst_UpdateHand(Actor* thisx, GlobalContext* globalCtx);
void BossSst_UpdateHead(Actor* thisx, GlobalContext* globalCtx);
void BossSst_DrawHand(Actor* thisx, GlobalContext* globalCtx);
void BossSst_DrawHead(Actor* thisx, GlobalContext* globalCtx);
void BossSst_UpdateEffect(Actor* thisx, GlobalContext* globalCtx);
void BossSst_DrawEffect(Actor* thisx, GlobalContext* globalCtx);

void BossSst_HeadSfx(BossSst* pthis, u16 sfxId);

void BossSst_HeadSetupLurk(BossSst* pthis);
void BossSst_HeadLurk(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupIntro(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadIntro(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupNeutral(BossSst* pthis);
void BossSst_HeadNeutral(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadWait(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HeadSetupDamagedHand(BossSst* pthis, s32 bothHands);
void BossSst_HeadDamagedHand(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupReadyCharge(BossSst* pthis);
void BossSst_HeadReadyCharge(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupCharge(BossSst* pthis);
void BossSst_HeadCharge(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupEndCharge(BossSst* pthis);
void BossSst_HeadEndCharge(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HeadSetupFrozenHand(BossSst* pthis);
void BossSst_HeadFrozenHand(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupUnfreezeHand(BossSst* pthis);
void BossSst_HeadUnfreezeHand(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HeadStunned(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupVulnerable(BossSst* pthis);
void BossSst_HeadVulnerable(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadDamage(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupRecover(BossSst* pthis);
void BossSst_HeadRecover(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HeadDeath(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupThrash(BossSst* pthis);
void BossSst_HeadThrash(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupDarken(BossSst* pthis);
void BossSst_HeadDarken(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupFall(BossSst* pthis);
void BossSst_HeadFall(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupMelt(BossSst* pthis);
void BossSst_HeadMelt(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HeadSetupFinish(BossSst* pthis);
void BossSst_HeadFinish(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandGrabPlayer(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandReleasePlayer(BossSst* pthis, GlobalContext* globalCtx, s32 dropPlayer);
void BossSst_HandSelectAttack(BossSst* pthis);
void BossSst_HandSetDamage(BossSst* pthis, s32 damage);
void BossSst_HandSetInvulnerable(BossSst* pthis, s32 isInv);

void BossSst_HandSetupWait(BossSst* pthis);
void BossSst_HandWait(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupDownbeat(BossSst* pthis);
void BossSst_HandDownbeat(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupOffbeat(BossSst* pthis);
void BossSst_HandOffbeat(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupDownbeatEnd(BossSst* pthis);
void BossSst_HandDownbeatEnd(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupOffbeatEnd(BossSst* pthis);
void BossSst_HandOffbeatEnd(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandReadySlam(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupSlam(BossSst* pthis);
void BossSst_HandSlam(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandEndSlam(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandReadySweep(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupSweep(BossSst* pthis);
void BossSst_HandSweep(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandReadyPunch(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupPunch(BossSst* pthis);
void BossSst_HandPunch(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandReadyClap(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupClap(BossSst* pthis);
void BossSst_HandClap(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupEndClap(BossSst* pthis);
void BossSst_HandEndClap(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandReadyGrab(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupGrab(BossSst* pthis);
void BossSst_HandGrab(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupCrush(BossSst* pthis);
void BossSst_HandCrush(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupEndCrush(BossSst* pthis);
void BossSst_HandEndCrush(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupSwing(BossSst* pthis);
void BossSst_HandSwing(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandSetupRetreat(BossSst* pthis);
void BossSst_HandRetreat(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandSetupReel(BossSst* pthis);
void BossSst_HandReel(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupReadyShake(BossSst* pthis);
void BossSst_HandReadyShake(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupShake(BossSst* pthis);
void BossSst_HandShake(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupReadyCharge(BossSst* pthis);
void BossSst_HandReadyCharge(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandSetupFrozen(BossSst* pthis);
void BossSst_HandFrozen(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupReadyBreakIce(BossSst* pthis);
void BossSst_HandReadyBreakIce(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupBreakIce(BossSst* pthis);
void BossSst_HandBreakIce(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandStunned(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandDamage(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupRecover(BossSst* pthis);
void BossSst_HandRecover(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_HandSetupThrash(BossSst* pthis);
void BossSst_HandThrash(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupDarken(BossSst* pthis);
void BossSst_HandDarken(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupFall(BossSst* pthis);
void BossSst_HandFall(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupMelt(BossSst* pthis);
void BossSst_HandMelt(BossSst* pthis, GlobalContext* globalCtx);
void BossSst_HandSetupFinish(BossSst* pthis);
void BossSst_HandFinish(BossSst* pthis, GlobalContext* globalCtx);

void BossSst_SpawnHeadShadow(BossSst* pthis);
void BossSst_SpawnHandShadow(BossSst* pthis);
void BossSst_SpawnShockwave(BossSst* pthis);
void BossSst_SpawnIceCrystal(BossSst* pthis, s32 index);
void BossSst_SpawnIceShard(BossSst* pthis);
void BossSst_IceShatter(BossSst* pthis);

#include "overlays/ovl_Boss_Sst/ovl_Boss_Sst.cpp"

static BossSst* sHead;
static BossSst* sHands[2];
static BgSstFloor* sFloor;

static Vec3f sRoomCenter = { ROOM_CENTER_X, ROOM_CENTER_Y, ROOM_CENTER_Z };
static Vec3f sHandOffsets[2];
static s16 sHandYawOffsets[2];

static s16 sCutsceneCamera;
static Vec3f sCameraAt = { ROOM_CENTER_X + 50.0f, ROOM_CENTER_Y + 0.0f, ROOM_CENTER_Z + 0.0f };
static Vec3f sCameraEye = { ROOM_CENTER_X + 150.0f, ROOM_CENTER_Y + 100.0f, ROOM_CENTER_Z + 0.0f };
static Vec3f sCameraAtVel = { 0.0f, 0.0f, 0.0f };
static Vec3f sCameraEyeVel = { 0.0f, 0.0f, 0.0f };

static Vec3f sCameraAtPoints[] = {
    { ROOM_CENTER_X - 50.0f, ROOM_CENTER_Y + 300.0f, ROOM_CENTER_Z + 0.0f },
    { ROOM_CENTER_X + 150.0f, ROOM_CENTER_Y + 300.0f, ROOM_CENTER_Z + 100.0f },
    { ROOM_CENTER_X + 0.0f, ROOM_CENTER_Y + 600.0f, ROOM_CENTER_Z + 100.0f },
    { ROOM_CENTER_X + 50.0f, ROOM_CENTER_Y + 400.0f, ROOM_CENTER_Z + 200.0f },
    { ROOM_CENTER_X + 50.0f, ROOM_CENTER_Y + 200.0f, ROOM_CENTER_Z + 200.0f },
    { ROOM_CENTER_X - 50.0f, ROOM_CENTER_Y + 0.0f, ROOM_CENTER_Z + 200.0f },
    { ROOM_CENTER_X - 150.0f, ROOM_CENTER_Y + 0.0f, ROOM_CENTER_Z + 100.0f },
    { ROOM_CENTER_X - 60.0f, ROOM_CENTER_Y + 180.0f, ROOM_CENTER_Z + 730.0f },
};

static Vec3f sCameraEyePoints[] = {
    { ROOM_CENTER_X + 250.0f, ROOM_CENTER_Y + 800.0f, ROOM_CENTER_Z + 800.0f },
    { ROOM_CENTER_X - 150.0f, ROOM_CENTER_Y + 700.0f, ROOM_CENTER_Z + 1400.0f },
    { ROOM_CENTER_X + 250.0f, ROOM_CENTER_Y + 100.0f, ROOM_CENTER_Z + 750.0f },
    { ROOM_CENTER_X + 50.0f, ROOM_CENTER_Y + 200.0f, ROOM_CENTER_Z + 900.0f },
    { ROOM_CENTER_X + 50.0f, ROOM_CENTER_Y + 200.0f, ROOM_CENTER_Z + 900.0f },
    { ROOM_CENTER_X + 350.0f, ROOM_CENTER_Y + 400.0f, ROOM_CENTER_Z + 1200.0f },
    { ROOM_CENTER_X - 50.0f, ROOM_CENTER_Y + 200.0f, ROOM_CENTER_Z + 800.0f },
    { ROOM_CENTER_X - 50.0f, ROOM_CENTER_Y + 200.0f, ROOM_CENTER_Z + 800.0f },
};

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };
static u32 sBodyStatic = false;

// Unreferenced. Maybe two zero vectors?
static u32 sUnkValues[] = { 0, 0, 0, 0, 0, 0 };

static Color_RGBA8 sBodyColor = { 255, 255, 255, 255 };
static Color_RGBA8 sStaticColor = { 0, 0, 0, 255 };
static s32 sHandState[] = { HAND_WAIT, HAND_WAIT };

ActorInit Boss_Sst_InitVars = {
    ACTOR_BOSS_SST,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_SST,
    sizeof(BossSst),
    (ActorFunc)BossSst_Init,
    (ActorFunc)BossSst_Destroy,
    (ActorFunc)BossSst_UpdateHand,
    (ActorFunc)BossSst_DrawHand,
};

#include "z_boss_sst_colchk.cpp"

static AnimationHeader* sHandIdleAnims[] = { &gBongoLeftHandIdleAnim, &gBongoRightHandIdleAnim };
static AnimationHeader* sHandFlatPoses[] = { &gBongoLeftHandFlatPoseAnim, &gBongoRightHandFlatPoseAnim };
static AnimationHeader* sHandOpenPoses[] = { &gBongoLeftHandOpenPoseAnim, &gBongoRightHandOpenPoseAnim };
static AnimationHeader* sHandFistPoses[] = { &gBongoLeftHandFistPoseAnim, &gBongoRightHandFistPoseAnim };
static AnimationHeader* sHandClenchAnims[] = { &gBongoLeftHandClenchAnim, &gBongoRightHandClenchAnim };
static AnimationHeader* sHandDamagePoses[] = { &gBongoLeftHandDamagePoseAnim, &gBongoRightHandDamagePoseAnim };
static AnimationHeader* sHandPushoffPoses[] = { &gBongoLeftHandPushoffPoseAnim, &gBongoRightHandPushoffPoseAnim };
static AnimationHeader* sHandHangPoses[] = { &gBongoLeftHandHangPoseAnim, &gBongoRightHandHangPoseAnim };

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x29, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 20, ICHAIN_STOP),
};

void BossSst_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BossSst* pthis = (BossSst*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitCylinder(globalCtx, &pthis->colliderCyl);
    Collider_InitJntSph(globalCtx, &pthis->colliderJntSph);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    Flags_SetSwitch(globalCtx, 0x14);
    if (pthis->actor.params == BONGO_HEAD) {
        sFloor = (BgSstFloor*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_SST_FLOOR, sRoomCenter.x,
                                          sRoomCenter.y, sRoomCenter.z, 0, 0, 0, BONGOFLOOR_REST);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBongoHeadSkel, &gBongoHeadEyeOpenIdleAnim, pthis->jointTable,
                           pthis->morphTable, 45);
        ActorShape_Init(&pthis->actor.shape, 70000.0f, ActorShadow_DrawCircle, 95.0f);
        Collider_SetJntSph(globalCtx, &pthis->colliderJntSph, &pthis->actor, &sJntSphInitHead, pthis->colliderItems);
        Collider_SetCylinder(globalCtx, &pthis->colliderCyl, &pthis->actor, &sCylinderInitHead);
        sHead = pthis;
        pthis->actor.world.pos.x = ROOM_CENTER_X + 50.0f;
        pthis->actor.world.pos.y = ROOM_CENTER_Y + 0.0f;
        pthis->actor.world.pos.z = ROOM_CENTER_Z - 650.0f;
        pthis->actor.home.pos = pthis->actor.world.pos;
        pthis->actor.shape.rot.y = 0;
        if (Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_WARP1, ROOM_CENTER_X, ROOM_CENTER_Y,
                        ROOM_CENTER_Z + 400.0f, 0, 0, 0, WARP_DUNGEON_ADULT);
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, ROOM_CENTER_X, ROOM_CENTER_Y,
                        ROOM_CENTER_Z - 200.0f, 0, 0, 0, 0);
            Actor_Kill(&pthis->actor);
        } else {
            sHands[LEFT] =
                (BossSst*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_SST, pthis->actor.world.pos.x + 200.0f,
                                      pthis->actor.world.pos.y, pthis->actor.world.pos.z + 400.0f, 0,
                                      pthis->actor.shape.rot.y, 0, BONGO_LEFT_HAND);
            sHands[RIGHT] = (BossSst*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_SST,
                                                  pthis->actor.world.pos.x + (-200.0f), pthis->actor.world.pos.y,
                                                  pthis->actor.world.pos.z + 400.0f, 0, pthis->actor.shape.rot.y, 0,
                                                  BONGO_RIGHT_HAND);
            sHands[LEFT]->actor.child = &sHands[RIGHT]->actor;
            sHands[RIGHT]->actor.child = &sHands[LEFT]->actor;

            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actor.update = BossSst_UpdateHead;
            pthis->actor.draw = BossSst_DrawHead;
            pthis->radius = -650.0f;
            pthis->actor.targetArrowOffset = 4000.0f;
            BossSst_HeadSetupLurk(pthis);
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_BOSS);
        }
    } else {
        Collider_SetJntSph(globalCtx, &pthis->colliderJntSph, &pthis->actor, &sJntSphInitHand, pthis->colliderItems);
        Collider_SetCylinder(globalCtx, &pthis->colliderCyl, &pthis->actor, &sCylinderInitHand);
        if (pthis->actor.params == BONGO_LEFT_HAND) {
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBongoLeftHandSkel, &gBongoLeftHandIdleAnim,
                               pthis->jointTable, pthis->morphTable, 27);
            pthis->vParity = -1;
            pthis->colliderJntSph.elements[0].dim.modelSphere.center.z *= -1;
        } else {
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBongoRightHandSkel, &gBongoRightHandIdleAnim,
                               pthis->jointTable, pthis->morphTable, 27);
            pthis->vParity = 1;
        }

        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 95.0f);
        pthis->handZPosMod = -3500;
        pthis->actor.targetArrowOffset = 5000.0f;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        BossSst_HandSetupWait(pthis);
    }
}

void BossSst_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossSst* pthis = (BossSst*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->colliderJntSph);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderCyl);
    Audio_StopSfxByPos(&pthis->center);
}

void BossSst_HeadSetupLurk(BossSst* pthis) {
    pthis->actor.draw = NULL;
    sHands[LEFT]->actor.draw = NULL;
    sHands[RIGHT]->actor.draw = NULL;
    pthis->vVanish = false;
    pthis->actionFunc = BossSst_HeadLurk;
}

void BossSst_HeadLurk(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.yDistToPlayer < 1000.0f) {
        BossSst_HeadSetupIntro(pthis, globalCtx);
    }
}

void BossSst_HeadSetupIntro(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->timer = 611;
    pthis->ready = false;
    player->actor.world.pos.x = sRoomCenter.x;
    player->actor.world.pos.y = ROOM_CENTER_Y + 1000.0f;
    player->actor.world.pos.z = sRoomCenter.z;
    player->linearVelocity = player->actor.velocity.y = 0.0f;
    player->actor.shape.rot.y = -0x8000;
    player->targetYaw = -0x8000;
    player->currentYaw = -0x8000;
    player->fallStartHeight = 0;
    player->stateFlags1 |= 0x20;

    func_80064520(globalCtx, &globalCtx->csCtx);
    func_8002DF54(globalCtx, &pthis->actor, 8);
    sCutsceneCamera = Gameplay_CreateSubCamera(globalCtx);
    Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
    Gameplay_ChangeCameraStatus(globalCtx, sCutsceneCamera, CAM_STAT_ACTIVE);
    Math_Vec3f_Copy(&sCameraAt, &player->actor.world.pos);
    if (gSaveContext.eventChkInf[7] & 0x80) {
        sCameraEye.z = ROOM_CENTER_Z - 100.0f;
    }

    Gameplay_CameraSetAtEye(globalCtx, sCutsceneCamera, &sCameraAt, &sCameraEye);
    Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
    pthis->actionFunc = BossSst_HeadIntro;
}

void BossSst_HeadIntro(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 tempo;
    s32 introStateTimer;
    s32 revealStateTimer;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeCloseIdleAnim, -3.0f);
    }

    if (pthis->timer == 0) {
        sHands[RIGHT]->actor.flags |= ACTOR_FLAG_0;
        sHands[LEFT]->actor.flags |= ACTOR_FLAG_0;
        player->stateFlags1 &= ~0x20;
        func_80064534(globalCtx, &globalCtx->csCtx);
        func_8002DF54(globalCtx, &pthis->actor, 7);
        sCameraAt.y += 30.0f;
        sCameraAt.z += 300.0f;
        Gameplay_CameraSetAtEye(globalCtx, sCutsceneCamera, &sCameraAt, &sCameraEye);
        Gameplay_CopyCamera(globalCtx, MAIN_CAM, sCutsceneCamera);
        Gameplay_ChangeCameraStatus(globalCtx, sCutsceneCamera, CAM_STAT_WAIT);
        Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
        Gameplay_ClearCamera(globalCtx, sCutsceneCamera);
        gSaveContext.eventChkInf[7] |= 0x80;
        BossSst_HeadSetupNeutral(pthis);
        pthis->colliderJntSph.base.ocFlags1 |= OC1_ON;
        sHands[LEFT]->colliderJntSph.base.ocFlags1 |= OC1_ON;
        sHands[RIGHT]->colliderJntSph.base.ocFlags1 |= OC1_ON;
        pthis->timer = 112;
    } else if (pthis->timer >= 546) {
        if (player->actor.world.pos.y > 100.0f) {
            player->actor.world.pos.x = sRoomCenter.x;
            player->actor.world.pos.z = sRoomCenter.z;
            player->linearVelocity = 0;
            player->actor.shape.rot.y = -0x8000;
            player->targetYaw = -0x8000;
            player->currentYaw = -0x8000;
        }

        Math_Vec3f_Copy(&sCameraAt, &player->actor.world.pos);
        if (player->actor.bgCheckFlags & 2) {
            if (!pthis->ready) {
                sFloor->dyna.actor.params = BONGOFLOOR_HIT;
                pthis->ready = true;
                func_800AA000(pthis->actor.xyzDistToPlayerSq, 0xFF, 0x14, 0x96);
                Audio_PlayActorSound2(&sFloor->dyna.actor, NA_SE_EN_SHADEST_TAIKO_HIGH);
            } else if (gSaveContext.eventChkInf[7] & 0x80) {
                sHands[RIGHT]->actor.draw = BossSst_DrawHand;
                sHands[LEFT]->actor.draw = BossSst_DrawHand;
                pthis->actor.draw = BossSst_DrawHead;
                pthis->timer = 178;
                sCameraAt.x = ROOM_CENTER_X - 23.0f;
                sCameraAt.y = ROOM_CENTER_Y + 0.0f;
                sCameraAt.z = ROOM_CENTER_Z + 0.0f;
            } else {
                pthis->timer = 546;
            }
        }
    } else if (pthis->timer >= 478) {
        sCameraEye.x += 10.0f;
        sCameraEye.y += 10.0f;
        sCameraEye.z -= 10.0f;
    } else if (pthis->timer >= 448) {
        if (pthis->timer == 460) {
            sHands[RIGHT]->actor.draw = BossSst_DrawHand;
            sHands[LEFT]->actor.draw = BossSst_DrawHand;
            pthis->actor.draw = BossSst_DrawHead;
            player->actor.world.pos.x = sRoomCenter.x;
            player->actor.world.pos.z = sRoomCenter.z;
            BossSst_HandSetupDownbeat(sHands[RIGHT]);
        }
        if (pthis->timer > 460) {
            sCameraEye.x -= 40.0f;
            sCameraEye.y -= 40.0f;
            sCameraEye.z += 20.0f;
        } else if (pthis->timer == 460) {
            sCameraAt.x = sHands[RIGHT]->actor.home.pos.x + 0.0f;
            sCameraAt.y = sHands[RIGHT]->actor.home.pos.y - 20.0f;
            sCameraAt.z = sHands[RIGHT]->actor.home.pos.z + 10.0f;
            sCameraEye.x = sHands[RIGHT]->actor.home.pos.x + 150.0f;
            sCameraEye.y = sHands[RIGHT]->actor.home.pos.y + 100.0f;
            sCameraEye.z = sHands[RIGHT]->actor.home.pos.z + 80.0f;
        }
    } else {
        if (pthis->timer >= 372) {
            introStateTimer = pthis->timer - 372;
            tempo = 6;
            if (pthis->timer == 447) {
                sCameraAt = player->actor.world.pos;
                sCameraEye.x = ROOM_CENTER_X - 200.0f;
                sCameraEye.y = ROOM_CENTER_Y + 160.0f;
                sCameraEye.z = ROOM_CENTER_Z - 190.0f;
            } else if (introStateTimer == 11) {
                sCameraAt.x = sHands[RIGHT]->actor.home.pos.x + 30.0f;
                sCameraAt.y = sHands[RIGHT]->actor.home.pos.y + 0.0f;
                sCameraAt.z = sHands[RIGHT]->actor.home.pos.z + 20.0f;
                sCameraEye.x = sHands[RIGHT]->actor.home.pos.x + 100.0f;
                sCameraEye.y = sHands[RIGHT]->actor.home.pos.y + 10.0f;
                sCameraEye.z = sHands[RIGHT]->actor.home.pos.z - 210.0f;
            } else if (introStateTimer == 62) {
                sCameraAt.x = sHands[LEFT]->actor.home.pos.x + 0.0f;
                sCameraAt.y = sHands[LEFT]->actor.home.pos.y + 50.0f;
                sCameraAt.z = sHands[LEFT]->actor.home.pos.z + 100.0f;
                sCameraEye.x = sHands[LEFT]->actor.home.pos.x + 110.0f;
                sCameraEye.y = sHands[LEFT]->actor.home.pos.y + 180.0f;
                sCameraEye.z = sHands[LEFT]->actor.home.pos.z - 70.0f;
            }
        } else if (pthis->timer >= 304) {
            introStateTimer = pthis->timer - 304;
            tempo = 5;
            if (introStateTimer == 11) {
                sCameraAt.x = sHands[RIGHT]->actor.home.pos.x + 40.0f;
                sCameraAt.y = sHands[RIGHT]->actor.home.pos.y - 90.0f;
                sCameraAt.z = sHands[RIGHT]->actor.home.pos.z - 40.0f;
                sCameraEye.x = sHands[RIGHT]->actor.home.pos.x - 20.0f;
                sCameraEye.y = sHands[RIGHT]->actor.home.pos.y + 210.0f;
                sCameraEye.z = sHands[RIGHT]->actor.home.pos.z + 170.0f;
            } else if (pthis->timer == 368) {
                sCameraAt.x = sHands[LEFT]->actor.home.pos.x - 20.0f;
                sCameraAt.y = sHands[LEFT]->actor.home.pos.y + 0.0f;
                sCameraAt.z = sHands[LEFT]->actor.home.pos.z + 0.0f;
                sCameraEye.x = sHands[LEFT]->actor.home.pos.x - 70.0f;
                sCameraEye.y = sHands[LEFT]->actor.home.pos.y + 170.0f;
                sCameraEye.z = sHands[LEFT]->actor.home.pos.z + 150.0f;
            }
        } else if (pthis->timer >= 244) {
            introStateTimer = pthis->timer - 244;
            tempo = 4;
            if (introStateTimer == 11) {
                sCameraAt.x = sHands[RIGHT]->actor.home.pos.x + 30.0f;
                sCameraAt.y = sHands[RIGHT]->actor.home.pos.y + 70.0f;
                sCameraAt.z = sHands[RIGHT]->actor.home.pos.z + 40.0f;
                sCameraEye.x = sHands[RIGHT]->actor.home.pos.x + 110.0f;
                sCameraEye.y = sHands[RIGHT]->actor.home.pos.y - 140.0f;
                sCameraEye.z = sHands[RIGHT]->actor.home.pos.z - 10.0f;
            } else if (pthis->timer == 300) {
                sCameraAt.x = sHands[LEFT]->actor.home.pos.x - 20.0f;
                sCameraAt.y = sHands[LEFT]->actor.home.pos.y - 80.0f;
                sCameraAt.z = sHands[LEFT]->actor.home.pos.z + 320.0f;
                sCameraEye.x = sHands[LEFT]->actor.home.pos.x - 130.0f;
                sCameraEye.y = sHands[LEFT]->actor.home.pos.y + 130.0f;
                sCameraEye.z = sHands[LEFT]->actor.home.pos.z - 150.0f;
            }
        } else if (pthis->timer >= 192) {
            introStateTimer = pthis->timer - 192;
            tempo = 3;
            if (pthis->timer == 240) {
                sCameraAt.x = sHands[LEFT]->actor.home.pos.x - 190.0f;
                sCameraAt.y = sHands[LEFT]->actor.home.pos.y - 110.0f;
                sCameraAt.z = sHands[LEFT]->actor.home.pos.z + 40.0f;
                sCameraEye.x = sHands[LEFT]->actor.home.pos.x + 120.0f;
                sCameraEye.y = sHands[LEFT]->actor.home.pos.y + 130.0f;
                sCameraEye.z = sHands[LEFT]->actor.home.pos.z + 50.0f;
            } else if (introStateTimer == 12) {
                sCameraAt.x = sRoomCenter.x + 50.0f;
                sCameraAt.y = sRoomCenter.y - 90.0f;
                sCameraAt.z = sRoomCenter.z - 200.0f;
                sCameraEye.x = sRoomCenter.x + 50.0f;
                sCameraEye.y = sRoomCenter.y + 350.0f;
                sCameraEye.z = sRoomCenter.z + 150.0f;
            }
        } else if (pthis->timer >= 148) {
            introStateTimer = pthis->timer - 148;
            tempo = 2;
        } else if (pthis->timer >= 112) {
            introStateTimer = pthis->timer - 112;
            tempo = 1;
        } else {
            introStateTimer = pthis->timer % 28;
            tempo = 0;
        }
        if (pthis->timer <= 198) {
            revealStateTimer = 198 - pthis->timer;
            if ((gSaveContext.eventChkInf[7] & 0x80) && (revealStateTimer <= 44)) {
                sCameraAt.x += 492.0f * 0.01f;
                sCameraAt.y += 200.0f * 0.01f;
                sCameraEye.x -= 80.0f * 0.01f;
                sCameraEye.y -= 360.0f * 0.01f;
                sCameraEye.z += 1000.0f * 0.01f;
            } else if (pthis->timer <= 20) {
                sCameraAt.y -= 700.0f * 0.01f;
                sCameraAt.z += 900.0f * 0.01f;
                sCameraEye.x += 650.0f * 0.01f;
                sCameraEye.y += 400.0f * 0.01f;
                sCameraEye.z += 1550.0f * 0.01f;
                pthis->vVanish = true;
                pthis->actor.flags |= ACTOR_FLAG_7;
            } else if (revealStateTimer < 40) {
                sCameraAt.x += 125.0f * 0.01f;
                sCameraAt.y += 350.0f * 0.01f;
                sCameraAt.z += 500.0f * 0.01f;
                sCameraEye.x += 200.0f * 0.01f;
                sCameraEye.y -= 850.0f * 0.01f;
            } else if (revealStateTimer >= 45) {
                if (revealStateTimer < 85) {
                    sCameraAt.x -= 250.0f * 0.01f;
                    sCameraAt.y += 425.0f * 0.01f;
                    sCameraAt.z -= 1200.0f * 0.01f;
                    sCameraEye.x -= 650.0f * 0.01f;
                    sCameraEye.y += 125.0f * 0.01f;
                    sCameraEye.z -= 350.0f * 0.01f;
                } else if (revealStateTimer == 85) {
                    if (!(gSaveContext.eventChkInf[7] & 0x80)) {
                        TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx,
                                               SEGMENTED_TO_VIRTUAL(gBongoTitleCardTex), 160, 180, 128, 40);
                    }
                    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
                    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadEyeCloseAnim, -5.0f);
                    BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_DISAPPEAR);
                }
            }
        }
        if (introStateTimer == 12) {
            BossSst_HandSetupDownbeat(sHands[RIGHT]);
        }
        if ((introStateTimer != 5) && ((introStateTimer % ((tempo * 2) + 7)) == 5)) {
            BossSst_HandSetupOffbeat(sHands[LEFT]);
        }
    }

    if (pthis->actionFunc != BossSst_HeadNeutral) {
        Gameplay_CameraSetAtEye(globalCtx, sCutsceneCamera, &sCameraAt, &sCameraEye);
    }
}

void BossSst_HeadSetupWait(BossSst* pthis) {
    if (pthis->skelAnime.animation != &gBongoHeadEyeCloseIdleAnim) {
        Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeCloseIdleAnim, -5.0f);
    }
    pthis->actionFunc = BossSst_HeadWait;
}

void BossSst_HeadWait(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((HAND_STATE(sHands[LEFT]) == HAND_WAIT) && (HAND_STATE(sHands[RIGHT]) == HAND_WAIT)) {
        BossSst_HeadSetupNeutral(pthis);
    }
}

void BossSst_HeadSetupNeutral(BossSst* pthis) {
    pthis->timer = 127;
    pthis->ready = false;
    pthis->actionFunc = BossSst_HeadNeutral;
}

void BossSst_HeadNeutral(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (!pthis->ready && ((HAND_STATE(sHands[LEFT]) == HAND_BEAT) || (HAND_STATE(sHands[LEFT]) == HAND_WAIT)) &&
        ((HAND_STATE(sHands[RIGHT]) == HAND_BEAT) || (HAND_STATE(sHands[RIGHT]) == HAND_WAIT))) {
        pthis->ready = true;
    }

    if (pthis->ready) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
    }

    if (pthis->timer == 0) {
        if ((GET_PLAYER(globalCtx)->actor.world.pos.y > -50.0f) && !(GET_PLAYER(globalCtx)->stateFlags1 & 0x6080)) {
            sHands[Rand_ZeroOne() <= 0.5f]->ready = true;
            BossSst_HeadSetupWait(pthis);
        } else {
            pthis->timer = 28;
        }
    } else {
        Math_ApproachS(&pthis->actor.shape.rot.y,
                       Actor_WorldYawTowardPoint(&GET_PLAYER(globalCtx)->actor, &sRoomCenter) + 0x8000, 4, 0x400);
        if ((pthis->timer == 28) || (pthis->timer == 84)) {
            BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_PRAY);
        }
    }
}

void BossSst_HeadSetupDamagedHand(BossSst* pthis, s32 bothHands) {
    if (bothHands) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadEyeOpenAnim, -5.0f);
    } else {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadDamagedHandAnim, -5.0f);
    }
    pthis->actionFunc = BossSst_HeadDamagedHand;
}

void BossSst_HeadDamagedHand(BossSst* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if ((HAND_STATE(sHands[LEFT]) == HAND_DAMAGED) && (HAND_STATE(sHands[RIGHT]) == HAND_DAMAGED)) {
            BossSst_HeadSetupReadyCharge(pthis);
        } else if ((HAND_STATE(sHands[LEFT]) == HAND_FROZEN) || (HAND_STATE(sHands[RIGHT]) == HAND_FROZEN)) {
            BossSst_HeadSetupFrozenHand(pthis);
        } else if (pthis->skelAnime.animation == &gBongoHeadEyeOpenAnim) {
            BossSst_HeadSetupUnfreezeHand(pthis);
        } else {
            BossSst_HeadSetupWait(pthis);
        }
    }
}

void BossSst_HeadSetupReadyCharge(BossSst* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeOpenIdleAnim, -5.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->colliderCyl.base.acFlags |= AC_ON;
    pthis->actionFunc = BossSst_HeadReadyCharge;
}

void BossSst_HeadReadyCharge(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (sHands[LEFT]->ready && (sHands[LEFT]->actionFunc == BossSst_HandReadyCharge) && sHands[RIGHT]->ready &&
        (sHands[RIGHT]->actionFunc == BossSst_HandReadyCharge)) {
        BossSst_HeadSetupCharge(pthis);
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 4, 0x800, 0x400);
    }
}

void BossSst_HeadSetupCharge(BossSst* pthis) {
    Animation_Change(&pthis->skelAnime, &gBongoHeadChargeAnim, 0.5f, 0.0f, Animation_GetLastFrame(&gBongoHeadChargeAnim),
                     ANIMMODE_ONCE_INTERP, -5.0f);
    BossSst_HandSetDamage(sHands[LEFT], 0x20);
    BossSst_HandSetDamage(sHands[RIGHT], 0x20);
    pthis->colliderJntSph.base.atFlags |= AT_ON;
    pthis->actor.speedXZ = 3.0f;
    pthis->radius = -650.0f;
    pthis->ready = false;
    pthis->actionFunc = BossSst_HeadCharge;
}

void BossSst_HeadCharge(BossSst* pthis, GlobalContext* globalCtx) {
    f32 chargeDist;
    s32 animFinish = SkelAnime_Update(&pthis->skelAnime);

    if (!pthis->ready && Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        pthis->ready = true;
        pthis->actor.speedXZ = 0.25f;
        pthis->skelAnime.playSpeed = 0.2f;
    }

    pthis->actor.speedXZ *= 1.25f;
    pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 45.0f);

    if (pthis->ready) {
        if (Math_SmoothStepToF(&pthis->radius, 650.0f, 0.4f, pthis->actor.speedXZ, 1.0f) < 10.0f) {
            pthis->radius = 650.0f;
            BossSst_HeadSetupEndCharge(pthis);
        } else {
            chargeDist = (650.0f - pthis->radius) * 3.0f;
            if (chargeDist > 180.0f) {
                chargeDist = 180.0f;
            }

            pthis->actor.world.pos.y = pthis->actor.home.pos.y - chargeDist;
        }

        if (!animFinish) {
            sHandOffsets[LEFT].z += 5.0f;
            sHandOffsets[RIGHT].z += 5.0f;
        }
    } else {
        Math_ApproachF(&pthis->radius, -700.0f, 0.4f, pthis->actor.speedXZ);
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 180.0f, 20.0f);
        sHandOffsets[LEFT].y += 5.0f;
        sHandOffsets[RIGHT].y += 5.0f;
    }

    if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
        pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        sHands[LEFT]->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        sHands[RIGHT]->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        func_8002F71C(globalCtx, &pthis->actor, 10.0f, pthis->actor.shape.rot.y, 5.0f);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
    }
}

void BossSst_HeadSetupEndCharge(BossSst* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeCloseIdleAnim, -20.0f);
    pthis->targetYaw = Actor_WorldYawTowardPoint(&pthis->actor, &sRoomCenter);
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->radius *= -1.0f;
    pthis->actionFunc = BossSst_HeadEndCharge;
}

void BossSst_HeadEndCharge(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 4, 0x800, 0x100) == 0) {
        BossSst_HandSetupRetreat(sHands[LEFT]);
        BossSst_HandSetupRetreat(sHands[RIGHT]);
        BossSst_HeadSetupNeutral(pthis);
    }
}

void BossSst_HeadSetupFrozenHand(BossSst* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeOpenIdleAnim, -5.0f);
    pthis->ready = false;
    pthis->colliderCyl.base.acFlags |= AC_ON;
    pthis->actionFunc = BossSst_HeadFrozenHand;
}

void BossSst_HeadFrozenHand(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->ready) {
        BossSst_HeadSetupUnfreezeHand(pthis);
    }
}

void BossSst_HeadSetupUnfreezeHand(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadEyeCloseAnim, -5.0f);
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->actionFunc = BossSst_HeadUnfreezeHand;
}

void BossSst_HeadUnfreezeHand(BossSst* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        BossSst_HeadSetupWait(pthis);
    }
}

void BossSst_HeadSetupStunned(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadKnockoutAnim, -5.0f);
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, Animation_GetLastFrame(&gBongoHeadKnockoutAnim));
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->vVanish = false;
    pthis->actor.flags &= ~ACTOR_FLAG_7;
    BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_FREEZE);
    pthis->actionFunc = BossSst_HeadStunned;
}

void BossSst_HeadStunned(BossSst* pthis, GlobalContext* globalCtx) {
    f32 bounce;
    s32 animFinish;
    f32 currentFrame;

    Math_StepToF(&sHandOffsets[LEFT].z, 600.0f, 20.0f);
    Math_StepToF(&sHandOffsets[RIGHT].z, 600.0f, 20.0f);
    Math_StepToF(&sHandOffsets[LEFT].x, 200.0f, 20.0f);
    Math_StepToF(&sHandOffsets[RIGHT].x, -200.0f, 20.0f);
    pthis->actor.velocity.y += pthis->actor.gravity;
    animFinish = SkelAnime_Update(&pthis->skelAnime);
    currentFrame = pthis->skelAnime.curFrame;
    if (currentFrame <= 6.0f) {
        bounce = (sinf((M_PI / 11) * currentFrame) * 100.0f) + (pthis->actor.home.pos.y - 180.0f);
        if (pthis->actor.world.pos.y < bounce) {
            pthis->actor.world.pos.y = bounce;
        }
    } else if (currentFrame <= 11.0f) {
        pthis->actor.world.pos.y = (sinf((M_PI / 11) * currentFrame) * 170.0f) + (pthis->actor.home.pos.y - 250.0f);
    } else {
        pthis->actor.world.pos.y =
            (sinf((currentFrame - 11.0f) * (M_PI / 5)) * 50.0f) + (pthis->actor.home.pos.y - 250.0f);
    }

    if ((animFinish) || Animation_OnFrame(&pthis->skelAnime, 11.0f)) {
        BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_LAND);
    }

    if (pthis->radius < -500.0f) {
        Math_SmoothStepToF(&pthis->radius, -500.0f, 1.0f, 50.0f, 5.0f);
    } else {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.5f, 15.0f, 3.0f);
        pthis->radius += pthis->actor.speedXZ;
    }

    pthis->radius = CLAMP_MAX(pthis->radius, 400.0f);

    pthis->actor.world.pos.y += pthis->actor.velocity.y;
    if (animFinish) {
        BossSst_HeadSetupVulnerable(pthis);
    }
}

void BossSst_HeadSetupVulnerable(BossSst* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadStunnedAnim, -5.0f);
    pthis->colliderCyl.base.acFlags |= AC_ON;
    pthis->colliderCyl.info.bumper.dmgFlags = 0x0FC00702; // Sword-type damage
    pthis->actor.speedXZ = 0.0f;
    pthis->colliderJntSph.elements[10].info.bumperFlags |= (BUMP_ON | BUMP_HOOKABLE);
    pthis->colliderJntSph.elements[0].info.bumperFlags &= ~BUMP_ON;
    if (pthis->actionFunc != BossSst_HeadDamage) {
        pthis->timer = 50;
    }

    pthis->actionFunc = BossSst_HeadVulnerable;
}

void BossSst_HeadVulnerable(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&sHandOffsets[LEFT].z, 600.0f, 20.0f);
    Math_StepToF(&sHandOffsets[RIGHT].z, 600.0f, 20.0f);
    Math_StepToF(&sHandOffsets[LEFT].x, 200.0f, 20.0f);
    Math_StepToF(&sHandOffsets[RIGHT].x, -200.0f, 20.0f);
    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        pthis->timer += 2;
        pthis->timer = CLAMP_MAX(pthis->timer, 50);
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            BossSst_HandSetupRecover(sHands[LEFT]);
            BossSst_HandSetupRecover(sHands[RIGHT]);
            BossSst_HeadSetupRecover(pthis);
        }
    }
}

void BossSst_HeadSetupDamage(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadDamageAnim, -3.0f);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, Animation_GetLastFrame(&gBongoHeadDamageAnim));
    Actor_SetColorFilter(&sHands[LEFT]->actor, 0x4000, 0xFF, 0, Animation_GetLastFrame(&gBongoHeadDamageAnim));
    Actor_SetColorFilter(&sHands[RIGHT]->actor, 0x4000, 0xFF, 0, Animation_GetLastFrame(&gBongoHeadDamageAnim));
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_DAMAGE);
    pthis->actionFunc = BossSst_HeadDamage;
}

void BossSst_HeadDamage(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        BossSst_HeadSetupVulnerable(pthis);
    }
}

void BossSst_HeadSetupRecover(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadRecoverAnim, -5.0f);
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->colliderCyl.info.bumper.dmgFlags = 0xFFCFFFFF;
    pthis->colliderJntSph.elements[10].info.bumperFlags &= ~(BUMP_ON | BUMP_HOOKABLE);
    pthis->colliderJntSph.elements[0].info.bumperFlags |= BUMP_ON;
    pthis->vVanish = true;
    pthis->actor.speedXZ = 5.0f;
    pthis->actionFunc = BossSst_HeadRecover;
}

void BossSst_HeadRecover(BossSst* pthis, GlobalContext* globalCtx) {
    s32 animFinish;
    f32 currentFrame;
    f32 diff;

    animFinish = SkelAnime_Update(&pthis->skelAnime);
    currentFrame = pthis->skelAnime.curFrame;
    if (currentFrame < 10.0f) {
        pthis->actor.world.pos.y += 10.0f;
        sHandOffsets[LEFT].y -= 10.0f;
        sHandOffsets[RIGHT].y -= 10.0f;
        Math_SmoothStepToF(&pthis->radius, -750.0f, 1.0f, pthis->actor.speedXZ, 2.0f);
    } else {
        pthis->actor.speedXZ *= 1.25f;
        pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 50.0f);
        diff = Math_SmoothStepToF(&pthis->radius, -650.0f, 1.0f, pthis->actor.speedXZ, 2.0f);
        diff += Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 30.0f, 3.0f);
    }
    if (animFinish && (diff < 10.0f)) {
        pthis->actor.world.pos.y = pthis->actor.home.pos.y;
        pthis->radius = -650.0f;
        BossSst_HandSetupRetreat(sHands[LEFT]);
        BossSst_HandSetupRetreat(sHands[RIGHT]);
        BossSst_HeadSetupNeutral(pthis);
    }
}

void BossSst_SetCameraTargets(f32 cameraSpeedMod, s32 targetIndex) {
    Vec3f* nextAt = &sCameraAtPoints[targetIndex];
    Vec3f* nextEye = &sCameraEyePoints[targetIndex];

    if (targetIndex != 0) {
        Math_Vec3f_Copy(&sCameraAt, &sCameraAtPoints[targetIndex - 1]);
        Math_Vec3f_Copy(&sCameraEye, &sCameraEyePoints[targetIndex - 1]);
    }

    sCameraAtVel.x = (nextAt->x - sCameraAt.x) * cameraSpeedMod;
    sCameraAtVel.y = (nextAt->y - sCameraAt.y) * cameraSpeedMod;
    sCameraAtVel.z = (nextAt->z - sCameraAt.z) * cameraSpeedMod;

    sCameraEyeVel.x = (nextEye->x - sCameraEye.x) * cameraSpeedMod;
    sCameraEyeVel.y = (nextEye->y - sCameraEye.y) * cameraSpeedMod;
    sCameraEyeVel.z = (nextEye->z - sCameraEye.z) * cameraSpeedMod;
}

void BossSst_UpdateDeathCamera(BossSst* pthis, GlobalContext* globalCtx) {
    Vec3f cameraAt;
    Vec3f cameraEye;
    f32 sn;
    f32 cs;

    sCameraAt.x += sCameraAtVel.x;
    sCameraAt.y += sCameraAtVel.y;
    sCameraAt.z += sCameraAtVel.z;
    sCameraEye.x += sCameraEyeVel.x;
    sCameraEye.y += sCameraEyeVel.y;
    sCameraEye.z += sCameraEyeVel.z;

    sn = Math_SinS(pthis->actor.shape.rot.y);
    cs = Math_CosS(pthis->actor.shape.rot.y);
    cameraAt.x = pthis->actor.world.pos.x + (sCameraAt.z * sn) + (sCameraAt.x * cs);
    cameraAt.y = pthis->actor.home.pos.y - 140.0f + sCameraAt.y;
    cameraAt.z = pthis->actor.world.pos.z + (sCameraAt.z * cs) - (sCameraAt.x * sn);
    cameraEye.x = pthis->actor.world.pos.x + (sCameraEye.z * sn) + (sCameraEye.x * cs);
    cameraEye.y = pthis->actor.home.pos.y - 140.0f + sCameraEye.y;
    cameraEye.z = pthis->actor.world.pos.z + (sCameraEye.z * cs) - (sCameraEye.x * sn);
    Gameplay_CameraSetAtEye(globalCtx, sCutsceneCamera, &cameraAt, &cameraEye);
}

void BossSst_HeadSetupDeath(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Animation_MorphToLoop(&pthis->skelAnime, &gBongoHeadEyeOpenIdleAnim, -5.0f);
    BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_DEAD);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 60);
    Actor_SetColorFilter(&sHands[LEFT]->actor, 0x4000, 0xFF, 0, 60);
    Actor_SetColorFilter(&sHands[RIGHT]->actor, 0x4000, 0xFF, 0, 60);
    pthis->timer = 60;
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->colliderJntSph.base.ocFlags1 &= ~OC1_ON;
    sHands[LEFT]->colliderJntSph.base.ocFlags1 &= ~OC1_ON;
    sHands[RIGHT]->colliderJntSph.base.ocFlags1 &= ~OC1_ON;
    Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
    sCutsceneCamera = Gameplay_CreateSubCamera(globalCtx);
    Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
    Gameplay_ChangeCameraStatus(globalCtx, sCutsceneCamera, CAM_STAT_ACTIVE);
    Gameplay_CopyCamera(globalCtx, sCutsceneCamera, MAIN_CAM);
    func_8002DF54(globalCtx, &player->actor, 8);
    func_80064520(globalCtx, &globalCtx->csCtx);
    Math_Vec3f_Copy(&sCameraEye, &GET_ACTIVE_CAM(globalCtx)->eye);
    pthis->actionFunc = BossSst_HeadDeath;
}

void BossSst_HeadDeath(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 140.0f, 20.0f);
    if (pthis->timer == 0) {
        BossSst_HandSetupThrash(sHands[LEFT]);
        BossSst_HandSetupThrash(sHands[RIGHT]);
        BossSst_HeadSetupThrash(pthis);
    } else if (pthis->timer > 48) {
        Gameplay_CameraSetAtEye(globalCtx, sCutsceneCamera, &pthis->actor.focus.pos, &sCameraEye);
        Math_StepToF(&pthis->radius, -350.0f, 10.0f);
    } else if (pthis->timer == 48) {
        Player* player = GET_PLAYER(globalCtx);

        player->actor.world.pos.x = sRoomCenter.x + (400.0f * Math_SinS(pthis->actor.shape.rot.y)) +
                                    (Math_CosS(pthis->actor.shape.rot.y) * -120.0f);
        player->actor.world.pos.z = sRoomCenter.z + (400.0f * Math_CosS(pthis->actor.shape.rot.y)) -
                                    (Math_SinS(pthis->actor.shape.rot.y) * -120.0f);
        player->actor.shape.rot.y = Actor_WorldYawTowardPoint(&player->actor, &sRoomCenter);
        func_8002DBD0(&pthis->actor, &sCameraEye, &GET_ACTIVE_CAM(globalCtx)->eye);
        func_8002DBD0(&pthis->actor, &sCameraAt, &GET_ACTIVE_CAM(globalCtx)->at);
        pthis->radius = -350.0f;
        pthis->actor.world.pos.x = sRoomCenter.x - (Math_SinS(pthis->actor.shape.rot.y) * 350.0f);
        pthis->actor.world.pos.z = sRoomCenter.z - (Math_CosS(pthis->actor.shape.rot.y) * 350.0f);
        BossSst_SetCameraTargets(1.0 / 48, 0);
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    } else {
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    }
}

void BossSst_HeadSetupThrash(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBongoHeadEyeOpenIdleAnim, -5.0f);
    pthis->timer = 160;
    pthis->targetYaw = pthis->actor.shape.rot.y;
    BossSst_SetCameraTargets(1.0 / 80, 1);
    pthis->actionFunc = BossSst_HeadThrash;
}

void BossSst_HeadThrash(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if ((pthis->timer == 0) && (pthis->actor.shape.rot.y == pthis->targetYaw)) {
        BossSst_HeadSetupDarken(pthis);
    } else if (pthis->timer >= 80) {
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    }
}

void BossSst_HeadSetupDarken(BossSst* pthis) {
    pthis->timer = 160;
    BossSst_SetCameraTargets(1.0 / 80, 2);
    pthis->actionFunc = BossSst_HeadDarken;
}

void BossSst_HeadDarken(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (1) {}

    if (pthis->timer >= 80) {
        if (pthis->timer == 80) {
            sBodyStatic = true;
        }
        BossSst_UpdateDeathCamera(pthis, globalCtx);
        sBodyColor.r = sBodyColor.g = sBodyColor.b = (pthis->timer * 3) - 240;
        if (pthis->timer == 80) {
            BossSst_SetCameraTargets(1.0 / 80, 3);
        }
    } else {
        sBodyColor.b = (80 - pthis->timer) / 1.0f;
        sBodyColor.r = sBodyColor.g = sStaticColor.r = sStaticColor.g = sStaticColor.b = (80 - pthis->timer) / 8.0f;
        BossSst_UpdateDeathCamera(pthis, globalCtx);
        if (pthis->timer == 0) {
            BossSst_HeadSetupFall(pthis);
        }
    }
}

void BossSst_HeadSetupFall(BossSst* pthis) {
    pthis->actor.speedXZ = 1.0f;
    Math_Vec3f_Copy(&sCameraAt, &sCameraAtPoints[3]);
    Math_Vec3f_Copy(&sCameraEye, &sCameraEyePoints[3]);
    sCameraAtVel.x = 0.0f;
    sCameraAtVel.z = 0.0f;
    sCameraAtVel.y = -50.0f;
    Math_Vec3f_Copy(&sCameraEyeVel, &sZeroVec);
    pthis->actionFunc = BossSst_HeadFall;
}

void BossSst_HeadFall(BossSst* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ *= 1.5f;
    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 230.0f, pthis->actor.speedXZ)) {
        BossSst_HeadSetupMelt(pthis);
    }

    if (sCameraAt.y > 200.0f) {
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    }
}

void BossSst_HeadSetupMelt(BossSst* pthis) {
    BossSst_SpawnHeadShadow(pthis);
    pthis->timer = 80;
    BossSst_SetCameraTargets(1.0 / 60, 5);
    pthis->actionFunc = BossSst_HeadMelt;
}

void BossSst_HeadMelt(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.scale.y -= 0.00025f;
    pthis->actor.scale.x += 0.000075f;
    pthis->actor.scale.z += 0.000075f;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y - 11500.0f * pthis->actor.scale.y;
    if (pthis->timer == 0) {
        BossSst_HeadSetupFinish(pthis);
    } else if (pthis->timer >= 20.0f) {
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    }
}

void BossSst_HeadSetupFinish(BossSst* pthis) {
    pthis->actor.draw = BossSst_DrawEffect;
    pthis->timer = 40;
    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS_CLEAR);
    BossSst_SetCameraTargets(1.0 / 40, 6);
    pthis->actionFunc = BossSst_HeadFinish;
}

void BossSst_HeadFinish(BossSst* pthis, GlobalContext* globalCtx) {
    static Color_RGBA8 colorIndigo = { 80, 80, 150, 255 };
    static Color_RGBA8 colorDarkIndigo = { 40, 40, 80, 255 };
    static Color_RGBA8 colorUnused[2] = {
        { 0, 0, 0, 255 },
        { 100, 100, 100, 0 },
    };
    Vec3f spawnPos;
    s32 i;

    pthis->timer--;
    if (pthis->effectMode == BONGO_NULL) {
        if (pthis->timer < -170) {
            BossSst_UpdateDeathCamera(pthis, globalCtx);
            Gameplay_CopyCamera(globalCtx, MAIN_CAM, sCutsceneCamera);
            Gameplay_ChangeCameraStatus(globalCtx, sCutsceneCamera, CAM_STAT_WAIT);
            Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
            Gameplay_ClearCamera(globalCtx, sCutsceneCamera);
            func_8002DF54(globalCtx, &GET_PLAYER(globalCtx)->actor, 7);
            func_80064534(globalCtx, &globalCtx->csCtx);
            Actor_Kill(&pthis->actor);
            Actor_Kill(&sHands[LEFT]->actor);
            Actor_Kill(&sHands[RIGHT]->actor);
            Flags_SetClear(globalCtx, globalCtx->roomCtx.curRoom.num);
        }
    } else if (pthis->effects[0].alpha == 0) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_WARP1, ROOM_CENTER_X, ROOM_CENTER_Y, ROOM_CENTER_Z, 0,
                    0, 0, WARP_DUNGEON_ADULT);
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART,
                    (Math_SinS(pthis->actor.shape.rot.y) * 200.0f) + ROOM_CENTER_X, ROOM_CENTER_Y,
                    Math_CosS(pthis->actor.shape.rot.y) * 200.0f + ROOM_CENTER_Z, 0, 0, 0, 0);
        BossSst_SetCameraTargets(1.0f, 7);
        pthis->effectMode = BONGO_NULL;
    } else if (pthis->timer == 0) {
        pthis->effects[0].status = 0;
        pthis->effects[1].status = -1;
        pthis->effects[2].status = -1;
    } else if (pthis->timer > 0) {
        pthis->effects[0].status += 5;
        BossSst_UpdateDeathCamera(pthis, globalCtx);
    }

    colorIndigo.a = pthis->effects[0].alpha;
    colorDarkIndigo.a = pthis->effects[0].alpha;

    for (i = 0; i < 5; i++) {
        spawnPos.x = sRoomCenter.x + 0.0f + Rand_CenteredFloat(800.0f);
        spawnPos.y = sRoomCenter.y + (-28.0f) + (Rand_ZeroOne() * 5.0f);
        spawnPos.z = sRoomCenter.z + 0.0f + Rand_CenteredFloat(800.0f);
        EffectSsGSplash_Spawn(globalCtx, &spawnPos, &colorIndigo, &colorDarkIndigo, 0, 0x3E8);
    }
}

void BossSst_HandSetupWait(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_WAIT;
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    Animation_MorphToLoop(&pthis->skelAnime, sHandIdleAnims[pthis->actor.params], 5.0f);
    pthis->ready = false;
    pthis->timer = 20;
    pthis->actionFunc = BossSst_HandWait;
}

void BossSst_HandWait(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 20.0f);
    Math_StepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 1.0f);
    Math_StepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 1.0f);
    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        Player* player = GET_PLAYER(globalCtx);

        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if ((pthis->timer == 0) && (player->actor.world.pos.y > -50.0f) && !(player->stateFlags1 & 0x6080)) {
            BossSst_HandSelectAttack(pthis);
        }
    } else if (sHead->actionFunc == BossSst_HeadNeutral) {
        if ((pthis->actor.params == BONGO_RIGHT_HAND) && ((sHead->timer % 28) == 12)) {
            BossSst_HandSetupDownbeat(pthis);
        } else if ((pthis->actor.params == BONGO_LEFT_HAND) && ((sHead->timer % 7) == 5) && (sHead->timer < 112)) {
            BossSst_HandSetupOffbeat(pthis);
        }
    }
}

void BossSst_HandSetupDownbeat(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_BEAT;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 5.0f);
    pthis->actor.shape.rot.x = 0;
    pthis->timer = 12;
    pthis->actionFunc = BossSst_HandDownbeat;
}

void BossSst_HandDownbeat(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        BossSst_HandSetupWait(pthis);
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer >= 3) {
            pthis->actor.shape.rot.x -= 0x100;
            Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 180.0f, 20.0f);
        } else {
            pthis->actor.shape.rot.x += 0x300;
            Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 0.0f, 60.0f);
        }

        if (pthis->timer == 0) {
            sFloor->dyna.actor.params = BONGOFLOOR_HIT;
            if (sHead->actionFunc == BossSst_HeadWait) {
                if (pthis->ready) {
                    BossSst_HandSelectAttack(pthis);
                } else {
                    BossSst_HandSetupWait(pthis);
                }
            } else {
                BossSst_HandSetupDownbeatEnd(pthis);
            }
            func_800AA000(pthis->actor.xyzDistToPlayerSq, 0xFF, 0x14, 0x96);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_TAIKO_HIGH);
        }
    }
}

void BossSst_HandSetupDownbeatEnd(BossSst* pthis) {
    sFloor->dyna.actor.params = BONGOFLOOR_HIT;
    Animation_PlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params]);
    pthis->actionFunc = BossSst_HandDownbeatEnd;
}

void BossSst_HandDownbeatEnd(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        BossSst_HandSetupWait(pthis);
    } else {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 40.0f, 0.5f, 20.0f, 3.0f);
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x800, 0x100);
        Math_StepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 1.0f);
        Math_StepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 1.0f);
        if ((sHead->actionFunc != BossSst_HeadIntro) && ((sHead->timer % 28) == 12)) {
            BossSst_HandSetupDownbeat(pthis);
        }
    }
}

void BossSst_HandSetupOffbeat(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_BEAT;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 5.0f);
    pthis->actor.shape.rot.x = 0;
    pthis->timer = 5;
    pthis->actionFunc = BossSst_HandOffbeat;
}

void BossSst_HandOffbeat(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        BossSst_HandSetupWait(pthis);
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer != 0) {
            pthis->actor.shape.rot.x -= 0x140;
            Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 60.0f, 15.0f);
        } else {
            pthis->actor.shape.rot.x += 0x500;
            Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 0.0f, 60.0f);
        }

        if (pthis->timer == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_TAIKO_LOW);
            BossSst_HandSetupOffbeatEnd(pthis);
        }
    }
}

void BossSst_HandSetupOffbeatEnd(BossSst* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params]);
    pthis->actionFunc = BossSst_HandOffbeatEnd;
}

void BossSst_HandOffbeatEnd(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        BossSst_HandSetupWait(pthis);
    } else {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 40.0f, 0.5f, 20.0f, 3.0f);
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x400, 0xA0);
        Math_StepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 1.0f);
        Math_StepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 1.0f);
        if (sHead->actionFunc == BossSst_HeadWait) {
            if (pthis->ready) {
                BossSst_HandSelectAttack(pthis);
            } else {
                BossSst_HandSetupWait(pthis);
            }
        } else if ((sHead->actionFunc != BossSst_HeadIntro) && ((sHead->timer % 7) == 5) &&
                   ((sHead->timer % 28) != 5)) {
            BossSst_HandSetupOffbeat(pthis);
        }
    }
}

void BossSst_HandSetupEndSlam(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_RETREAT;
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandPushoffPoses[pthis->actor.params], 6.0f);
    pthis->actionFunc = BossSst_HandEndSlam;
}

void BossSst_HandEndSlam(BossSst* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        BossSst_HandSetupRetreat(pthis);
    }
}

void BossSst_HandSetupRetreat(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_RETREAT;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandHangPoses[pthis->actor.params], 10.0f);
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    pthis->colliderJntSph.base.acFlags |= AC_ON;
    pthis->actor.flags |= ACTOR_FLAG_0;
    BossSst_HandSetInvulnerable(pthis, false);
    pthis->timer = 0;
    pthis->actionFunc = BossSst_HandRetreat;
    pthis->actor.speedXZ = 3.0f;
}

void BossSst_HandRetreat(BossSst* pthis, GlobalContext* globalCtx) {
    f32 diff;
    s32 inPosition;

    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.speedXZ = pthis->actor.speedXZ * 1.2f;
    pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 50.0f);

    diff = Math_SmoothStepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 0.3f, pthis->actor.speedXZ, 1.0f);
    diff += Math_SmoothStepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 0.3f, pthis->actor.speedXZ, 1.0f);
    if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        pthis->actor.world.pos.y = (sinf((pthis->timer * M_PI) / 16.0f) * 250.0f) + pthis->actor.home.pos.y;
        if (pthis->timer == 0) {
            BossSst_HandSetupWait(pthis);
        } else if (pthis->timer == 4) {
            Animation_MorphToLoop(&pthis->skelAnime, sHandIdleAnims[pthis->actor.params], 4.0f);
        }
    } else {
        inPosition = Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 0x200);
        inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->actor.home.rot.z, 0x200);
        inPosition &= Math_ScaledStepToS(&pthis->handYRotMod, 0, 0x800);
        func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
        if ((Math_SmoothStepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 250.0f, 0.5f, 70.0f, 5.0f) < 1.0f) &&
            inPosition && (diff < 10.0f)) {
            pthis->timer = 8;
        }
    }
}

void BossSst_HandSetupReadySlam(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_SLAM;
    pthis->timer = 0;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 10.0f);
    pthis->actionFunc = BossSst_HandReadySlam;
}

void BossSst_HandReadySlam(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            BossSst_HandSetupSlam(pthis);
        }
    } else {
        Player* player = GET_PLAYER(globalCtx);

        if (Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 300.0f, 30.0f) &&
            (pthis->actor.xzDistToPlayer < 140.0f)) {
            pthis->timer = 20;
        }
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x1000, 0x100);
        Math_ApproachF(&pthis->actor.world.pos.x, player->actor.world.pos.x, 0.5f, 40.0f);
        Math_ApproachF(&pthis->actor.world.pos.z, player->actor.world.pos.z, 0.5f, 40.0f);
        func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
    }
}

void BossSst_HandSetupSlam(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_SLAM;
    pthis->actor.velocity.y = 1.0f;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 10.0f);
    BossSst_HandSetDamage(pthis, 0x20);
    pthis->ready = false;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_FLY_ATTACK);
    pthis->actionFunc = BossSst_HandSlam;
}

void BossSst_HandSlam(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToS(&pthis->handZPosMod, -0xDAC, 0x1F4);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x1000);
    Math_ScaledStepToS(&pthis->handYRotMod, 0, 0x1000);
    if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            if (pthis->colliderJntSph.base.acFlags & AC_ON) {
                BossSst_HandSetupEndSlam(pthis);
            } else {
                pthis->colliderJntSph.base.acFlags |= AC_ON;
                BossSst_HandSetupWait(pthis);
            }
        }
    } else {
        if (pthis->ready) {
            pthis->timer = 30;
            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        } else {
            pthis->actor.velocity.y *= 1.5f;
            if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, pthis->actor.velocity.y)) {
                pthis->ready = true;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_TAIKO_LOW);
                BossSst_SpawnShockwave(pthis);
                pthis->colliderCyl.base.atFlags |= AT_ON;
                Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCyl);
                pthis->colliderCyl.dim.radius = sCylinderInitHand.dim.radius;
            }
        }

        if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
            Player* player = GET_PLAYER(globalCtx);

            player->actor.world.pos.x = (Math_SinS(pthis->actor.yawTowardsPlayer) * 100.0f) + pthis->actor.world.pos.x;
            player->actor.world.pos.z = (Math_CosS(pthis->actor.yawTowardsPlayer) * 100.0f) + pthis->actor.world.pos.z;

            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            func_8002F71C(globalCtx, &pthis->actor, 5.0f, pthis->actor.yawTowardsPlayer, 0.0f);
        }

        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x200);
    }
}

void BossSst_HandSetupReadySweep(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_SWEEP;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 10.0f);
    pthis->radius = Actor_WorldDistXZToPoint(&pthis->actor, &sHead->actor.world.pos);
    pthis->actor.world.rot.y = Actor_WorldYawTowardPoint(&sHead->actor, &pthis->actor.world.pos);
    pthis->targetYaw = pthis->actor.home.rot.y + (pthis->vParity * 0x2000);
    pthis->actionFunc = BossSst_HandReadySweep;
}

void BossSst_HandReadySweep(BossSst* pthis, GlobalContext* globalCtx) {
    s32 inPosition;

    SkelAnime_Update(&pthis->skelAnime);
    inPosition = Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 50.0f, 4.0f);
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 0x200);
    inPosition &= Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->targetYaw, 0x400);
    inPosition &= (Math_SmoothStepToF(&pthis->radius, sHead->actor.xzDistToPlayer, 0.5f, 60.0f, 1.0f) < 10.0f);

    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.world.rot.y) * pthis->radius) + sHead->actor.world.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.world.rot.y) * pthis->radius) + sHead->actor.world.pos.z;
    if (inPosition) {
        BossSst_HandSetupSweep(pthis);
    } else {
        func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
    }
}

void BossSst_HandSetupSweep(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 5.0f);
    BossSst_HandSetDamage(pthis, 0x10);
    pthis->targetYaw = pthis->actor.home.rot.y - (pthis->vParity * 0x2000);
    pthis->handMaxSpeed = 0x300;
    pthis->handAngSpeed = 0;
    pthis->ready = false;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_FLY_ATTACK);
    pthis->actionFunc = BossSst_HandSweep;
}

void BossSst_HandSweep(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 newTargetYaw;

    SkelAnime_Update(&pthis->skelAnime);
    pthis->handAngSpeed += 0x60;
    pthis->handAngSpeed = CLAMP_MAX(pthis->handAngSpeed, pthis->handMaxSpeed);

    if (!Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 4, pthis->handAngSpeed, 0x10)) {
        pthis->colliderJntSph.base.ocFlags1 &= ~OC1_NO_PUSH;
        BossSst_HandSetupRetreat(pthis);
    } else if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
        pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        pthis->ready = true;
        func_8002F71C(globalCtx, &pthis->actor, 5.0f, pthis->actor.shape.rot.y - (pthis->vParity * 0x3800), 0.0f);
        func_8002F7DC(&player->actor, NA_SE_PL_BODY_HIT);
        newTargetYaw = pthis->actor.shape.rot.y - (pthis->vParity * 0x1400);
        if (((s16)(newTargetYaw - pthis->targetYaw) * pthis->vParity) > 0) {
            pthis->targetYaw = newTargetYaw;
        }
    }

    if (!pthis->ready && ((player->cylinder.dim.height > 40.0f) || (player->actor.world.pos.y > 1.0f))) {
        pthis->colliderJntSph.base.atFlags |= AT_ON;
        pthis->colliderJntSph.base.ocFlags1 &= ~OC1_NO_PUSH;
    } else {
        pthis->colliderJntSph.base.atFlags &= ~AT_ON;
        pthis->colliderJntSph.base.ocFlags1 |= OC1_NO_PUSH;
    }

    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.z;
}

void BossSst_HandSetupReadyPunch(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_PUNCH;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandPushoffPoses[pthis->actor.params], 10.0f);
    pthis->actionFunc = BossSst_HandReadyPunch;
}

void BossSst_HandReadyPunch(BossSst* pthis, GlobalContext* globalCtx) {
    s32 inPosition = Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x400);

    if (SkelAnime_Update(&pthis->skelAnime) && inPosition) {
        BossSst_HandSetupPunch(pthis);
    }
}

void BossSst_HandSetupPunch(BossSst* pthis) {
    pthis->actor.speedXZ = 0.5f;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFistPoses[pthis->actor.params], 5.0f);
    BossSst_HandSetInvulnerable(pthis, true);
    pthis->targetRoll = pthis->vParity * 0x3F00;
    BossSst_HandSetDamage(pthis, 0x10);
    pthis->actionFunc = BossSst_HandPunch;
}

void BossSst_HandPunch(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 80.0f, 20.0f);
    if (Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->targetRoll, 0x400)) {
        pthis->targetRoll *= -1;
    }

    pthis->actor.speedXZ *= 1.25f;
    pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 50.0f);

    pthis->actor.world.pos.x += pthis->actor.speedXZ * Math_SinS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.z += pthis->actor.speedXZ * Math_CosS(pthis->actor.shape.rot.y);
    if (pthis->actor.bgCheckFlags & 8) {
        BossSst_HandSetupRetreat(pthis);
    } else if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
        func_8002F71C(globalCtx, &pthis->actor, 10.0f, pthis->actor.shape.rot.y, 5.0f);
        BossSst_HandSetupRetreat(pthis);
    }

    func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
}

void BossSst_HandSetupReadyClap(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_CLAP;
    if (HAND_STATE(OTHER_HAND(pthis)) != HAND_CLAP) {
        BossSst_HandSetupReadyClap(OTHER_HAND(pthis));
    }

    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 10.0f);
    pthis->radius = Actor_WorldDistXZToPoint(&pthis->actor, &sHead->actor.world.pos);
    pthis->actor.world.rot.y = Actor_WorldYawTowardPoint(&sHead->actor, &pthis->actor.world.pos);
    pthis->targetYaw = pthis->actor.home.rot.y - (pthis->vParity * 0x1800);
    pthis->targetRoll = pthis->vParity * 0x4000;
    pthis->timer = 0;
    pthis->ready = false;
    OTHER_HAND(pthis)->ready = false;
    pthis->actionFunc = BossSst_HandReadyClap;
}

void BossSst_HandReadyClap(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            BossSst_HandSetupClap(pthis);
            BossSst_HandSetupClap(OTHER_HAND(pthis));
            OTHER_HAND(pthis)->radius = pthis->radius;
        }
    } else if (!pthis->ready) {
        pthis->ready = SkelAnime_Update(&pthis->skelAnime);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x600);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->targetRoll, 0x600);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 0x200);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->targetYaw, 0x400);
        pthis->ready &= Math_SmoothStepToF(&pthis->radius, sHead->actor.xzDistToPlayer, 0.5f, 50.0f, 1.0f) < 10.0f;
        pthis->ready &= Math_SmoothStepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 95.0f, 0.5f, 30.0f, 1.0f) < 1.0f;

        pthis->actor.world.pos.x = Math_SinS(pthis->actor.world.rot.y) * pthis->radius + sHead->actor.world.pos.x;
        pthis->actor.world.pos.z = Math_CosS(pthis->actor.world.rot.y) * pthis->radius + sHead->actor.world.pos.z;
    } else if (OTHER_HAND(pthis)->ready) {
        pthis->timer = 20;
    }
}

void BossSst_HandSetupClap(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 3.0f);
    pthis->timer = 0;
    pthis->handMaxSpeed = 0x240;
    pthis->handAngSpeed = 0;
    pthis->ready = false;
    BossSst_HandSetDamage(pthis, 0x20);
    pthis->actionFunc = BossSst_HandClap;
}

void BossSst_HandClap(BossSst* pthis, GlobalContext* globalCtx) {
    static s32 dropFlag = false;
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            if (dropFlag) {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos,
                                     (Rand_ZeroOne() < 0.5f) ? ITEM00_ARROWS_SMALL : ITEM00_MAGIC_SMALL);
                dropFlag = false;
            }

            BossSst_HandReleasePlayer(pthis, globalCtx, true);
            BossSst_HandSetupEndClap(pthis);
        }
    } else {
        if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            OTHER_HAND(pthis)->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            BossSst_HandGrabPlayer(pthis, globalCtx);
        }

        if (pthis->ready) {
            pthis->timer = 30;
            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            if (!(player->stateFlags2 & 0x80)) {
                dropFlag = true;
            }
        } else {
            pthis->handAngSpeed += 0x40;
            pthis->handAngSpeed = CLAMP_MAX(pthis->handAngSpeed, pthis->handMaxSpeed);

            if (Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, pthis->handAngSpeed)) {
                if (pthis->actor.params == BONGO_LEFT_HAND) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_CLAP);
                }
                pthis->ready = true;
            } else {
                func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
            }

            pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.x;
            pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.z;
        }
    }

    if (player->actor.parent == &pthis->actor) {
        player->unk_850 = 0;
        player->actor.world.pos = pthis->actor.world.pos;
    }
}

void BossSst_HandSetupEndClap(BossSst* pthis) {
    pthis->targetYaw = pthis->actor.home.rot.y - (pthis->vParity * 0x1000);
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 10.0f);
    pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    pthis->actionFunc = BossSst_HandEndClap;
}

void BossSst_HandEndClap(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.z, 0, 0x200);
    if (Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 0x100)) {
        BossSst_HandSetupRetreat(pthis);
    }
    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * pthis->radius) + sHead->actor.world.pos.z;
}

void BossSst_HandSetupReadyGrab(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_GRAB;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 10.0f);
    pthis->targetYaw = pthis->vParity * -0x5000;
    pthis->targetRoll = pthis->vParity * 0x4000;
    pthis->actionFunc = BossSst_HandReadyGrab;
}

void BossSst_HandReadyGrab(BossSst* pthis, GlobalContext* globalCtx) {
    s32 inPosition;

    SkelAnime_Update(&pthis->skelAnime);
    inPosition = Math_SmoothStepToS(&pthis->actor.shape.rot.z, pthis->targetRoll, 4, 0x800, 0x100) == 0;
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + pthis->targetYaw, 0xA00);
    Math_ApproachF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 95.0f, 0.5f, 20.0f);
    if (inPosition) {
        BossSst_HandSetupGrab(pthis);
    }
}

void BossSst_HandSetupGrab(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFistPoses[pthis->actor.params], 5.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + (pthis->vParity * 0x4000);
    pthis->targetYaw = pthis->actor.world.rot.y;
    pthis->timer = 30;
    pthis->actor.speedXZ = 0.5f;
    BossSst_HandSetDamage(pthis, 0x20);
    pthis->actionFunc = BossSst_HandGrab;
}

void BossSst_HandGrab(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.world.rot.y =
        ((1.0f - sinf(pthis->timer * (M_PI / 60.0f))) * (pthis->vParity * 0x2000)) + pthis->targetYaw;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y - (pthis->vParity * 0x4000);
    if (pthis->timer < 5) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.5f, 25.0f, 5.0f);
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            pthis->actor.speedXZ = 0.0f;
            if (player->stateFlags2 & 0x80) {
                if (Rand_ZeroOne() < 0.5f) {
                    BossSst_HandSetupCrush(pthis);
                } else {
                    BossSst_HandSetupSwing(pthis);
                }
            } else {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos,
                                     (Rand_ZeroOne() < 0.5f) ? ITEM00_ARROWS_SMALL : ITEM00_MAGIC_SMALL);
                BossSst_HandSetupRetreat(pthis);
            }
        }
    } else {
        pthis->actor.speedXZ *= 1.26f;
        pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 70.0f);
        func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
    }

    if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
        pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_CATCH);
        BossSst_HandGrabPlayer(pthis, globalCtx);
        pthis->timer = CLAMP_MAX(pthis->timer, 5);
    }

    pthis->actor.world.pos.x += pthis->actor.speedXZ * Math_SinS(pthis->actor.world.rot.y);
    pthis->actor.world.pos.z += pthis->actor.speedXZ * Math_CosS(pthis->actor.world.rot.y);
    if (player->stateFlags2 & 0x80) {
        player->unk_850 = 0;
        player->actor.world.pos = pthis->actor.world.pos;
        player->actor.shape.rot.y = pthis->actor.shape.rot.y;
    }
}

void BossSst_HandSetupCrush(BossSst* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, sHandClenchAnims[pthis->actor.params], -10.0f);
    pthis->timer = 20;
    pthis->actionFunc = BossSst_HandCrush;
}

void BossSst_HandCrush(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (!(player->stateFlags2 & 0x80)) {
        BossSst_HandReleasePlayer(pthis, globalCtx, true);
        BossSst_HandSetupEndCrush(pthis);
    } else {
        player->actor.world.pos = pthis->actor.world.pos;
        if (pthis->timer == 0) {
            pthis->timer = 20;
            if (!LINK_IS_ADULT) {
                func_8002F7DC(&player->actor, NA_SE_VO_LI_DAMAGE_S_KID);
            } else {
                func_8002F7DC(&player->actor, NA_SE_VO_LI_DAMAGE_S);
            }

            globalCtx->damagePlayer(globalCtx, -8);
        }
        if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_CATCH);
        }
    }
}

void BossSst_HandSetupEndCrush(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 10.0f);
    pthis->actionFunc = BossSst_HandEndCrush;
}

void BossSst_HandEndCrush(BossSst* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        BossSst_HandSetupRetreat(pthis);
    }
}

void BossSst_HandSetupSwing(BossSst* pthis) {
    pthis->amplitude = -0x4000;
    pthis->timer = 1;
    pthis->center.x = pthis->actor.world.pos.x - (Math_SinS(pthis->actor.shape.rot.y) * 200.0f);
    pthis->center.y = pthis->actor.world.pos.y;
    pthis->center.z = pthis->actor.world.pos.z - (Math_CosS(pthis->actor.shape.rot.y) * 200.0f);
    pthis->actionFunc = BossSst_HandSwing;
}

void BossSst_HandSwing(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 offXZ;

    if (Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->amplitude, pthis->timer * 0xE4 + 0x1C8)) {
        if (pthis->amplitude != 0) {
            pthis->amplitude = 0;
            if (pthis->timer == 4) {
                Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 4.0f);
            }
        } else {
            if (pthis->timer == 4) {
                player->actor.shape.rot.x = 0;
                player->actor.shape.rot.z = 0;
                BossSst_HandSetupRetreat(pthis);
                return;
            }
            pthis->amplitude = (pthis->timer == 3) ? -0x6000 : -0x4000;
            pthis->timer++;
        }
    }

    pthis->actor.world.pos.y = (Math_CosS(pthis->actor.shape.rot.x + 0x4000) * 200.0f) + pthis->center.y;
    offXZ = Math_SinS(pthis->actor.shape.rot.x + 0x4000) * 200.0f;
    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * offXZ) + pthis->center.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * offXZ) + pthis->center.z;
    if (pthis->timer != 4) {
        pthis->actor.shape.rot.z = (pthis->actor.shape.rot.x + 0x4000) * pthis->vParity;
    } else {
        Math_ScaledStepToS(&pthis->actor.shape.rot.z, 0, 0x800);
    }

    if (player->stateFlags2 & 0x80) {
        player->unk_850 = 0;
        Math_Vec3f_Copy(&player->actor.world.pos, &pthis->actor.world.pos);
        player->actor.shape.rot.x = pthis->actor.shape.rot.x;
        player->actor.shape.rot.z = (pthis->vParity * -0x4000) + pthis->actor.shape.rot.z;
    } else {
        Math_ScaledStepToS(&player->actor.shape.rot.x, 0, 0x600);
        Math_ScaledStepToS(&player->actor.shape.rot.z, 0, 0x600);
        player->actor.world.pos.x += 20.0f * Math_SinS(pthis->actor.shape.rot.y);
        player->actor.world.pos.z += 20.0f * Math_CosS(pthis->actor.shape.rot.y);
    }

    if ((pthis->timer == 4) && (pthis->amplitude == 0) && SkelAnime_Update(&pthis->skelAnime) &&
        (player->stateFlags2 & 0x80)) {
        BossSst_HandReleasePlayer(pthis, globalCtx, false);
        player->actor.world.pos.x += 70.0f * Math_SinS(pthis->actor.shape.rot.y);
        player->actor.world.pos.z += 70.0f * Math_CosS(pthis->actor.shape.rot.y);
        func_8002F71C(globalCtx, &pthis->actor, 15.0f, pthis->actor.shape.rot.y, 2.0f);
        func_8002F7DC(&player->actor, NA_SE_PL_BODY_HIT);
    }

    func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
}

void BossSst_HandSetupReel(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_DAMAGED;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 4.0f);
    pthis->timer = 36;
    Math_Vec3f_Copy(&pthis->center, &pthis->actor.world.pos);
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 200);
    pthis->actionFunc = BossSst_HandReel;
}

void BossSst_HandReel(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (!(pthis->timer % 4)) {
        if (pthis->timer % 8) {
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 4.0f);
        } else {
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFistPoses[pthis->actor.params], 6.0f);
        }
    }

    pthis->actor.colorFilterTimer = 200;
    pthis->actor.world.pos.x += Rand_CenteredFloat(20.0f);
    pthis->actor.world.pos.y += Rand_CenteredFloat(20.0f);
    pthis->actor.world.pos.z += Rand_CenteredFloat(20.0f);

    if (pthis->actor.world.pos.y < (pthis->actor.floorHeight + 100.0f)) {
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 100.0f, 20.0f);
    }

    if (pthis->timer == 0) {
        BossSst_HandSetupReadyShake(pthis);
    }
}

void BossSst_HandSetupReadyShake(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandDamagePoses[pthis->actor.params], 8.0f);
    pthis->actionFunc = BossSst_HandReadyShake;
}

void BossSst_HandReadyShake(BossSst* pthis, GlobalContext* globalCtx) {
    f32 diff;
    s32 inPosition;

    diff = Math_SmoothStepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 0.5f, 25.0f, 1.0f);
    diff += Math_SmoothStepToF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 0.5f, 25.0f, 1.0f);
    diff += Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 200.0f, 0.2f, 30.0f, 1.0f);
    inPosition = Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x4000, 0x400);
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.z, 0, 0x1000);
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 0x800);
    inPosition &= Math_StepToS(&pthis->handZPosMod, -0x5DC, 0x1F4);
    inPosition &= Math_ScaledStepToS(&pthis->handYRotMod, pthis->vParity * -0x2000, 0x800);
    pthis->actor.colorFilterTimer = 200;
    if ((diff < 30.0f) && inPosition) {
        BossSst_HandSetupShake(pthis);
    } else {
        func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
    }
}

void BossSst_HandSetupShake(BossSst* pthis) {
    pthis->timer = 200;
    pthis->actionFunc = BossSst_HandShake;
}

void BossSst_HandShake(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.shape.rot.x = 0x4000 + (sinf(pthis->timer * (M_PI / 5)) * 0x2000);
    pthis->handYRotMod = (pthis->vParity * -0x2000) + (sinf(pthis->timer * (M_PI / 4)) * 0x2800);

    if (!(pthis->timer % 8)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_SHAKEHAND);
    }

    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        if ((OTHER_HAND(pthis)->actionFunc == BossSst_HandShake) ||
            (OTHER_HAND(pthis)->actionFunc == BossSst_HandReadyCharge)) {
            BossSst_HandSetupReadyCharge(pthis);
        } else if (pthis->timer == 0) {
            pthis->timer = 80;
        }
    } else if (pthis->timer == 0) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        BossSst_HandSetupSlam(pthis);
    }
}

void BossSst_HandSetupReadyCharge(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFistPoses[pthis->actor.params], 10.0f);
    pthis->ready = false;
    pthis->actionFunc = BossSst_HandReadyCharge;
}

void BossSst_HandReadyCharge(BossSst* pthis, GlobalContext* globalCtx) {
    if (!pthis->ready) {
        pthis->ready = SkelAnime_Update(&pthis->skelAnime);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x800);
        pthis->ready &=
            Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y + (pthis->vParity * 0x1000), 0x800);
        pthis->ready &= Math_ScaledStepToS(&pthis->handYRotMod, 0, 0x800);
        pthis->ready &= Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->vParity * 0x2800, 0x800);
        pthis->ready &= Math_StepToS(&pthis->handZPosMod, -0xDAC, 0x1F4);
        if (pthis->ready) {
            pthis->actor.colorFilterTimer = 0;
        }
    } else if (pthis->colliderJntSph.base.atFlags & AT_HIT) {
        pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        OTHER_HAND(pthis)->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        sHead->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
        func_8002F71C(globalCtx, &pthis->actor, 10.0f, pthis->actor.shape.rot.y, 5.0f);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
    }
}

void BossSst_HandSetupStunned(BossSst* hand) {
    Animation_MorphToPlayOnce(&hand->skelAnime, sHandIdleAnims[hand->actor.params], 10.0f);
    if (hand->actionFunc != BossSst_HandDamage) {
        hand->ready = false;
    }

    hand->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
    hand->colliderJntSph.base.acFlags |= AC_ON;
    BossSst_HandSetInvulnerable(hand, true);
    Actor_SetColorFilter(&hand->actor, 0, 0xFF, 0, Animation_GetLastFrame(&gBongoHeadKnockoutAnim));
    hand->actionFunc = BossSst_HandStunned;
}

void BossSst_HandStunned(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachF(&pthis->actor.world.pos.z, (Math_CosS(sHead->actor.shape.rot.y) * 200.0f) + pthis->actor.home.pos.z,
                   0.5f, 25.0f);
    Math_ApproachF(&pthis->actor.world.pos.x, (Math_SinS(sHead->actor.shape.rot.y) * 200.0f) + pthis->actor.home.pos.x,
                   0.5f, 25.0f);
    if (!pthis->ready) {
        Math_ScaledStepToS(&pthis->handYRotMod, 0, 0x800);
        Math_StepToS(&pthis->handZPosMod, -0xDAC, 0x1F4);
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->actor.home.rot.x, 0x800);
        Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->actor.home.rot.z, 0x800);
        Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 0x800);
        if (sHead->actionFunc == BossSst_HeadVulnerable) {
            pthis->ready = true;
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandDamagePoses[pthis->actor.params], 10.0f);
        }
    } else {
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 30.0f);
    }
}

void BossSst_HandSetupDamage(BossSst* hand) {
    hand->actor.shape.rot.x = 0;
    Animation_MorphToPlayOnce(&hand->skelAnime, sHandOpenPoses[hand->actor.params], 3.0f);
    hand->timer = 6;
    hand->actionFunc = BossSst_HandDamage;
}

void BossSst_HandDamage(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer >= 2) {
        pthis->actor.shape.rot.x -= 0x200;
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 200.0f, 50.0f);
    } else {
        pthis->actor.shape.rot.x += 0x400;
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 100.0f);
    }

    if (pthis->timer == 0) {
        if (pthis->actor.floorHeight >= 0.0f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_TAIKO_HIGH);
        }
        BossSst_HandSetupStunned(pthis);
    }
}

void BossSst_HandSetupThrash(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_DEATH;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 2.0f);
    pthis->actor.shape.rot.x = 0;
    pthis->timer = 160;
    if (pthis->actor.params == BONGO_LEFT_HAND) {
        pthis->amplitude = -0x800;
    } else {
        pthis->amplitude = 0;
        pthis->actor.shape.rot.x = -0x800;
    }

    pthis->handAngSpeed = 0x180;
    pthis->actionFunc = BossSst_HandThrash;
}

void BossSst_HandThrash(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachF(&pthis->actor.world.pos.z, (Math_CosS(sHead->actor.shape.rot.y) * 200.0f) + pthis->actor.home.pos.z,
                   0.5f, 25.0f);
    Math_ApproachF(&pthis->actor.world.pos.x, (Math_SinS(sHead->actor.shape.rot.y) * 200.0f) + pthis->actor.home.pos.x,
                   0.5f, 25.0f);
    if (Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->amplitude, pthis->handAngSpeed)) {
        if (pthis->amplitude != 0) {
            pthis->amplitude = 0;
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 5.0f);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_TAIKO_HIGH);
            pthis->amplitude = -0x800;
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandOpenPoses[pthis->actor.params], 5.0f);
        }

        if (pthis->timer < 80.0f) {
            pthis->handAngSpeed -= 0x40;
            pthis->handAngSpeed = CLAMP_MIN(pthis->handAngSpeed, 0x40);
        }
    }

    pthis->actor.world.pos.y =
        (((pthis->handAngSpeed / 256.0f) + 0.5f) * 150.0f) * (-1.0f / 0x800) * pthis->actor.shape.rot.x;
    if (pthis->timer == 0) {
        BossSst_HandSetupDarken(pthis);
    }
}

void BossSst_HandSetupDarken(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 5.0f);
    pthis->actionFunc = BossSst_HandDarken;
}

void BossSst_HandDarken(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x800, pthis->handAngSpeed);
    Math_StepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 90.0f, 5.0f);
    if (sHead->actionFunc == BossSst_HeadFall) {
        BossSst_HandSetupFall(pthis);
    }
}

void BossSst_HandSetupFall(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFlatPoses[pthis->actor.params], 3.0f);
    pthis->actionFunc = BossSst_HandFall;
}

void BossSst_HandFall(BossSst* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x400);
    pthis->actor.world.pos.y = sHead->actor.world.pos.y + 230.0f;
    if (sHead->actionFunc == BossSst_HeadMelt) {
        BossSst_HandSetupMelt(pthis);
    }
}

void BossSst_HandSetupMelt(BossSst* pthis) {
    BossSst_SpawnHandShadow(pthis);
    pthis->actor.shape.shadowDraw = NULL;
    pthis->timer = 80;
    pthis->actionFunc = BossSst_HandMelt;
}

void BossSst_HandMelt(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.scale.y -= 0.00025f;
    pthis->actor.scale.x += 0.000025f;
    pthis->actor.scale.z += 0.000025f;
    pthis->actor.world.pos.y = ROOM_CENTER_Y + 0.0f;
    if (pthis->timer == 0) {
        BossSst_HandSetupFinish(pthis);
    }
}

void BossSst_HandSetupFinish(BossSst* pthis) {
    pthis->actor.draw = BossSst_DrawEffect;
    pthis->timer = 20;
    pthis->effects[0].status = 0;
    pthis->actionFunc = BossSst_HandFinish;
}

void BossSst_HandFinish(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        pthis->effectMode = BONGO_NULL;
    }
}

void BossSst_HandSetupRecover(BossSst* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandPushoffPoses[pthis->actor.params], 10.0f);
    pthis->ready = false;
    pthis->actionFunc = BossSst_HandRecover;
}

void BossSst_HandRecover(BossSst* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.world.pos.y, ROOM_CENTER_Y + 250.0f, 0.5f, 70.0f, 5.0f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (!pthis->ready) {
            Animation_MorphToPlayOnce(&pthis->skelAnime, sHandHangPoses[pthis->actor.params], 10.0f);
            pthis->ready = true;
        }
    }
    func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
}

void BossSst_HandSetupFrozen(BossSst* pthis) {
    s32 i;

    HAND_STATE(pthis) = HAND_FROZEN;
    Math_Vec3f_Copy(&pthis->center, &pthis->actor.world.pos);
    BossSst_HandSetupReadyBreakIce(OTHER_HAND(pthis));
    pthis->ready = false;
    pthis->effectMode = BONGO_ICE;
    pthis->timer = 35;
    for (i = 0; i < 18; i++) {
        pthis->effects[i].move = false;
    }

    BossSst_SpawnIceCrystal(pthis, 0);
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0xA);
    pthis->handAngSpeed = 0;
    pthis->actionFunc = BossSst_HandFrozen;
}

void BossSst_HandFrozen(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if ((pthis->timer % 2) != 0) {
        BossSst_SpawnIceCrystal(pthis, (pthis->timer >> 1) + 1);
    }

    if (pthis->ready) {
        BossSst_IceShatter(pthis);
        BossSst_HandSetupRetreat(pthis);
        sHead->ready = true;
    } else {
        pthis->actor.colorFilterTimer = 10;
        if (pthis->handAngSpeed != 0) {
            f32 offY = Math_SinS(OTHER_HAND(pthis)->actor.shape.rot.x) * 5.0f;
            f32 offXZ = Math_CosS(OTHER_HAND(pthis)->actor.shape.rot.x) * 5.0f;

            if ((pthis->handAngSpeed % 2) != 0) {
                offY *= -1.0f;
                offXZ *= -1.0f;
            }

            pthis->actor.world.pos.x = pthis->center.x + (Math_CosS(OTHER_HAND(pthis)->actor.shape.rot.y) * offXZ);
            pthis->actor.world.pos.y = pthis->center.y + offY;
            pthis->actor.world.pos.z = pthis->center.z + (Math_SinS(OTHER_HAND(pthis)->actor.shape.rot.y) * offXZ);
            pthis->handAngSpeed--;
        }
    }
}

void BossSst_HandSetupReadyBreakIce(BossSst* pthis) {
    HAND_STATE(pthis) = HAND_BREAK_ICE;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHandFistPoses[pthis->actor.params], 5.0f);
    pthis->ready = false;
    pthis->actor.colorFilterTimer = 0;
    if (pthis->effectMode == BONGO_ICE) {
        pthis->effectMode = BONGO_NULL;
    }

    pthis->radius = Actor_WorldDistXZToPoint(&pthis->actor, &OTHER_HAND(pthis)->center);
    pthis->targetYaw = Actor_WorldYawTowardPoint(&pthis->actor, &OTHER_HAND(pthis)->center);
    BossSst_HandSetInvulnerable(pthis, true);
    pthis->actionFunc = BossSst_HandReadyBreakIce;
}

void BossSst_HandReadyBreakIce(BossSst* pthis, GlobalContext* globalCtx) {
    s32 inPosition;

    inPosition = Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->targetYaw, 0x400);
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x1000, 0x400);
    inPosition &= Math_ScaledStepToS(&pthis->actor.shape.rot.z, 0, 0x800);
    inPosition &= Math_ScaledStepToS(&pthis->handYRotMod, 0, 0x400);
    inPosition &= Math_StepToF(&pthis->actor.world.pos.y, OTHER_HAND(pthis)->center.y + 200.0f, 50.0f);
    inPosition &= Math_StepToF(&pthis->radius, 400.0f, 60.0f);
    pthis->actor.world.pos.x = OTHER_HAND(pthis)->center.x - (Math_SinS(pthis->targetYaw) * pthis->radius);
    pthis->actor.world.pos.z = OTHER_HAND(pthis)->center.z - (Math_CosS(pthis->targetYaw) * pthis->radius);
    if (SkelAnime_Update(&pthis->skelAnime) && inPosition) {
        BossSst_HandSetupBreakIce(pthis);
    }
}

void BossSst_HandSetupBreakIce(BossSst* pthis) {
    pthis->timer = 9;
    pthis->actionFunc = BossSst_HandBreakIce;
    pthis->actor.speedXZ = 0.5f;
}

void BossSst_HandBreakIce(BossSst* pthis, GlobalContext* globalCtx) {
    if ((pthis->timer % 2) != 0) {
        pthis->actor.speedXZ *= 1.5f;
        pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 60.0f);

        if (Math_StepToF(&pthis->radius, 100.0f, pthis->actor.speedXZ)) {
            BossSst_SpawnIceShard(pthis);
            if (pthis->timer != 0) {
                pthis->timer--;
            }

            if (pthis->timer != 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_ICE_BROKEN);
            }

            OTHER_HAND(pthis)->handAngSpeed = 5;
        }
    } else {
        pthis->actor.speedXZ *= 0.8f;
        Math_StepToF(&pthis->radius, 500.0f, pthis->actor.speedXZ);
        if (pthis->actor.speedXZ < 2.0f) {
            if (pthis->timer != 0) {
                pthis->timer--;
            }
        }
    }

    pthis->actor.world.pos.x = OTHER_HAND(pthis)->center.x - (Math_SinS(pthis->targetYaw) * pthis->radius);
    pthis->actor.world.pos.z = OTHER_HAND(pthis)->center.z - (Math_CosS(pthis->targetYaw) * pthis->radius);
    pthis->actor.world.pos.y = OTHER_HAND(pthis)->center.y + (pthis->radius * 0.4f);
    if (pthis->timer == 0) {
        OTHER_HAND(pthis)->ready = true;
        BossSst_HandSetupRetreat(pthis);
    }

    func_8002F974(&pthis->actor, NA_SE_EN_SHADEST_HAND_FLY - SFX_FLAG);
}

void BossSst_HandGrabPlayer(BossSst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->grabPlayer(globalCtx, player)) {
        player->actor.parent = &pthis->actor;
        if (player->actor.colChkInfo.health > 0) {
            pthis->colliderJntSph.base.ocFlags1 &= ~OC1_ON;
            if (HAND_STATE(pthis) == HAND_CLAP) {
                OTHER_HAND(pthis)->colliderJntSph.base.ocFlags1 &= ~OC1_ON;
            }
        }
    }
}

void BossSst_HandReleasePlayer(BossSst* pthis, GlobalContext* globalCtx, s32 dropPlayer) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->actor.parent == &pthis->actor) {
        player->actor.parent = NULL;
        player->unk_850 = 100;
        pthis->colliderJntSph.base.ocFlags1 |= OC1_ON;
        OTHER_HAND(pthis)->colliderJntSph.base.ocFlags1 |= OC1_ON;
        if (dropPlayer) {
            func_8002F71C(globalCtx, &pthis->actor, 0.0f, pthis->actor.shape.rot.y, 0.0f);
        }
    }
}

void BossSst_MoveAround(BossSst* pthis) {
    BossSst* hand;
    Vec3f* vec;
    f32 sn;
    f32 cs;
    s32 i;

    sn = Math_SinS(pthis->actor.shape.rot.y);
    cs = Math_CosS(pthis->actor.shape.rot.y);
    if (pthis->actionFunc != BossSst_HeadEndCharge) {
        pthis->actor.world.pos.x = sRoomCenter.x + (pthis->radius * sn);
        pthis->actor.world.pos.z = sRoomCenter.z + (pthis->radius * cs);
    }

    for (i = 0; i < 2; i++) {
        hand = sHands[i];
        vec = &sHandOffsets[i];

        hand->actor.world.pos.x = pthis->actor.world.pos.x + (vec->z * sn) + (vec->x * cs);
        hand->actor.world.pos.y = pthis->actor.world.pos.y + vec->y;
        hand->actor.world.pos.z = pthis->actor.world.pos.z + (vec->z * cs) - (vec->x * sn);

        hand->actor.home.pos.x = pthis->actor.world.pos.x + (400.0f * sn) + (-200.0f * hand->vParity * cs);
        hand->actor.home.pos.y = pthis->actor.world.pos.y;
        hand->actor.home.pos.z = pthis->actor.world.pos.z + (400.0f * cs) - (-200.0f * hand->vParity * sn);

        hand->actor.home.rot.y = pthis->actor.shape.rot.y;
        hand->actor.shape.rot.y = sHandYawOffsets[i] + pthis->actor.shape.rot.y;

        if (hand->actor.world.pos.y < hand->actor.floorHeight) {
            hand->actor.world.pos.y = hand->actor.floorHeight;
        }
    }
}

void BossSst_HandSelectAttack(BossSst* pthis) {
    f32 rand = Rand_ZeroOne() * 6.0f;
    s32 randInt;

    if (HAND_STATE(OTHER_HAND(pthis)) == HAND_DAMAGED) {
        rand *= 5.0f / 6;
        if (rand > 4.0f) {
            rand = 4.0f;
        }
    }

    randInt = rand;
    if (randInt == 0) {
        BossSst_HandSetupReadySlam(pthis);
    } else if (randInt == 1) {
        BossSst_HandSetupReadySweep(pthis);
    } else if (randInt == 2) {
        BossSst_HandSetupReadyPunch(pthis);
    } else if (randInt == 5) {
        BossSst_HandSetupReadyClap(pthis);
    } else { // randInt == 3 || randInt == 4
        BossSst_HandSetupReadyGrab(pthis);
    }
}

void BossSst_HandSetDamage(BossSst* pthis, s32 damage) {
    s32 i;

    pthis->colliderJntSph.base.atFlags |= AT_ON;
    for (i = 0; i < 11; i++) {
        pthis->colliderJntSph.elements[i].info.toucher.damage = damage;
    }
}

void BossSst_HandSetInvulnerable(BossSst* pthis, s32 isInv) {
    pthis->colliderJntSph.base.acFlags &= ~AC_HIT;
    if (isInv) {
        pthis->colliderJntSph.base.colType = COLTYPE_HARD;
        pthis->colliderJntSph.base.acFlags |= AC_HARD;
    } else {
        pthis->colliderJntSph.base.colType = COLTYPE_HIT0;
        pthis->colliderJntSph.base.acFlags &= ~AC_HARD;
    }
}

void BossSst_HeadSfx(BossSst* pthis, u16 sfxId) {
    func_80078914(&pthis->center, sfxId);
}

void BossSst_HandCollisionCheck(BossSst* pthis, GlobalContext* globalCtx) {
    if ((pthis->colliderJntSph.base.acFlags & AC_HIT) && (pthis->colliderJntSph.base.colType != COLTYPE_HARD)) {
        s32 bothHands = true;

        pthis->colliderJntSph.base.acFlags &= ~AC_HIT;
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            pthis->colliderJntSph.base.atFlags &= ~(AT_ON | AT_HIT);
            pthis->colliderJntSph.base.acFlags &= ~AC_ON;
            pthis->colliderJntSph.base.ocFlags1 &= ~OC1_NO_PUSH;
            BossSst_HandReleasePlayer(pthis, globalCtx, true);
            if (HAND_STATE(OTHER_HAND(pthis)) == HAND_CLAP) {
                BossSst_HandReleasePlayer(OTHER_HAND(pthis), globalCtx, true);
                BossSst_HandSetupRetreat(OTHER_HAND(pthis));
            }

            pthis->actor.flags &= ~ACTOR_FLAG_0;
            if (pthis->actor.colChkInfo.damageEffect == 3) {
                BossSst_HandSetupFrozen(pthis);
            } else {
                BossSst_HandSetupReel(pthis);
                if (HAND_STATE(OTHER_HAND(pthis)) != HAND_DAMAGED) {
                    bothHands = false;
                }
            }

            BossSst_HeadSetupDamagedHand(sHead, bothHands);
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos,
                                 (Rand_ZeroOne() < 0.5f) ? ITEM00_ARROWS_SMALL : ITEM00_MAGIC_SMALL);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_DAMAGE_HAND);
        }
    }
}

void BossSst_HeadCollisionCheck(BossSst* pthis, GlobalContext* globalCtx) {
    if (pthis->colliderCyl.base.acFlags & AC_HIT) {
        pthis->colliderCyl.base.acFlags &= ~AC_HIT;
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (pthis->actionFunc == BossSst_HeadVulnerable) {
                if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                    BossSst_HeadSetupDeath(pthis, globalCtx);
                } else {
                    BossSst_HeadSetupDamage(pthis);
                }

                BossSst_HandSetupDamage(sHands[LEFT]);
                BossSst_HandSetupDamage(sHands[RIGHT]);
            } else {
                BossSst_HeadSetupStunned(pthis);
                if (HAND_STATE(sHands[RIGHT]) == HAND_FROZEN) {
                    BossSst_IceShatter(sHands[RIGHT]);
                } else if (HAND_STATE(sHands[LEFT]) == HAND_FROZEN) {
                    BossSst_IceShatter(sHands[LEFT]);
                }

                BossSst_HandSetupStunned(sHands[RIGHT]);
                BossSst_HandSetupStunned(sHands[LEFT]);
            }
        }
    }
}

void BossSst_UpdateHand(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossSst* pthis = (BossSst*)thisx;
    BossSstHandTrail* trail;

    if (pthis->colliderCyl.base.atFlags & AT_ON) {
        if ((pthis->effects[0].move < 5) ||
            (pthis->actor.xzDistToPlayer < ((pthis->effects[2].scale * 0.01f) * sCylinderInitHand.dim.radius)) ||
            (pthis->colliderCyl.base.atFlags & AT_HIT)) {
            pthis->colliderCyl.base.atFlags &= ~(AT_ON | AT_HIT);
        } else {
            pthis->colliderCyl.dim.radius = (pthis->effects[0].scale * 0.01f) * sCylinderInitHand.dim.radius;
        }
    }

    BossSst_HandCollisionCheck(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 130.0f, 0.0f, 5);
    Actor_SetFocus(&pthis->actor, 0.0f);
    if (pthis->colliderJntSph.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    if ((sHead->actionFunc != BossSst_HeadLurk) && (sHead->actionFunc != BossSst_HeadIntro) &&
        (pthis->colliderJntSph.base.acFlags & AC_ON)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    if (pthis->colliderJntSph.base.ocFlags1 & OC1_ON) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    if (pthis->colliderCyl.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCyl.base);
    }

    if ((HAND_STATE(pthis) != HAND_DEATH) && (HAND_STATE(pthis) != HAND_WAIT) && (HAND_STATE(pthis) != HAND_BEAT) &&
        (HAND_STATE(pthis) != HAND_FROZEN)) {
        pthis->trailCount++;
        pthis->trailCount = CLAMP_MAX(pthis->trailCount, 7);
    } else {
        pthis->trailCount--;
        pthis->trailCount = CLAMP_MIN(pthis->trailCount, 0);
    }

    trail = &pthis->handTrails[pthis->trailIndex];
    Math_Vec3f_Copy(&trail->world.pos, &pthis->actor.world.pos);
    trail->world.rot = pthis->actor.shape.rot;
    trail->zPosMod = pthis->handZPosMod;
    trail->yRotMod = pthis->handYRotMod;

    pthis->trailIndex = (pthis->trailIndex + 1) % 7;
    BossSst_UpdateEffect(&pthis->actor, globalCtx);
}

void BossSst_UpdateHead(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossSst* pthis = (BossSst*)thisx;

    func_8002DBD0(&pthis->actor, &sHandOffsets[RIGHT], &sHands[RIGHT]->actor.world.pos);
    func_8002DBD0(&pthis->actor, &sHandOffsets[LEFT], &sHands[LEFT]->actor.world.pos);

    sHandYawOffsets[LEFT] = sHands[LEFT]->actor.shape.rot.y - thisx->shape.rot.y;
    sHandYawOffsets[RIGHT] = sHands[RIGHT]->actor.shape.rot.y - thisx->shape.rot.y;

    BossSst_HeadCollisionCheck(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->vVanish) {
        if ((globalCtx->actorCtx.unk_03 == 0) || (thisx->colorFilterTimer != 0)) {
            pthis->actor.flags &= ~ACTOR_FLAG_7;
        } else {
            pthis->actor.flags |= ACTOR_FLAG_7;
        }
    }

    if (pthis->colliderJntSph.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    if ((pthis->actionFunc != BossSst_HeadLurk) && (pthis->actionFunc != BossSst_HeadIntro)) {
        if (pthis->colliderCyl.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCyl.base);
        }
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    if (pthis->colliderJntSph.base.ocFlags1 & OC1_ON) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
    }

    BossSst_MoveAround(pthis);
    if ((!pthis->vVanish || CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) &&
        ((pthis->actionFunc == BossSst_HeadReadyCharge) || (pthis->actionFunc == BossSst_HeadCharge) ||
         (pthis->actionFunc == BossSst_HeadFrozenHand) || (pthis->actionFunc == BossSst_HeadStunned) ||
         (pthis->actionFunc == BossSst_HeadVulnerable) || (pthis->actionFunc == BossSst_HeadDamage))) {
        pthis->actor.flags |= ACTOR_FLAG_0;
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }

    if (pthis->actionFunc == BossSst_HeadCharge) {
        BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_MOVE - SFX_FLAG);
    }

    BossSst_UpdateEffect(&pthis->actor, globalCtx);
}

s32 BossSst_OverrideHandDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                             void* thisx) {
    BossSst* pthis = (BossSst*)thisx;

    if (limbIndex == 1) {
        pos->z += pthis->handZPosMod;
        rot->y += pthis->handYRotMod;
    }
    return false;
}

void BossSst_PostHandDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    BossSst* pthis = (BossSst*)thisx;

    Collider_UpdateSpheres(limbIndex, &pthis->colliderJntSph);
}

s32 BossSst_OverrideHandTrailDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                  void* data, Gfx** gfx) {
    BossSstHandTrail* trail = (BossSstHandTrail*)data;

    if (limbIndex == 1) {
        pos->z += trail->zPosMod;
        rot->y += trail->yRotMod;
    }
    return false;
}

void BossSst_DrawHand(Actor* thisx, GlobalContext* globalCtx) {
    BossSst* pthis = (BossSst*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 6563);

    func_80093D18(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x80, sBodyColor.r, sBodyColor.g, sBodyColor.b, 255);

    if (!sBodyStatic) {
        gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
    } else {
        gDPSetEnvColor(POLY_OPA_DISP++, sStaticColor.r, sStaticColor.g, sStaticColor.b, 0);
        gSPSegment(POLY_OPA_DISP++, 0x08, sBodyStaticDList);
    }

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          BossSst_OverrideHandDraw, BossSst_PostHandDraw, pthis);
    if (pthis->trailCount >= 2) {
        BossSstHandTrail* trail;
        BossSstHandTrail* trail2;
        s32 i;
        s32 idx;
        s32 end;
        s32 pad;

        func_80093D84(globalCtx->state.gfxCtx);

        end = pthis->trailCount >> 1;
        idx = (pthis->trailIndex + 4) % 7;
        trail = &pthis->handTrails[idx];
        trail2 = &pthis->handTrails[(idx + 2) % 7];

        for (i = 0; i < end; i++) {
            if (Math3D_Vec3fDistSq(&trail2->world.pos, &trail->world.pos) > 900.0f) {
                func_800D1694(trail->world.pos.x, trail->world.pos.y, trail->world.pos.z, &trail->world.rot);
                Matrix_Scale(0.02f, 0.02f, 0.02f, MTXMODE_APPLY);

                gSPSegment(POLY_XLU_DISP++, 0x08, sHandTrailDList);
                gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, ((3 - i) * 10) + 20, 0, ((3 - i) * 20) + 50,
                                ((3 - i) * 30) + 70);

                POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                                   pthis->skelAnime.dListCount, BossSst_OverrideHandTrailDraw, NULL,
                                                   trail, POLY_XLU_DISP);
            }
            idx = (idx + 5) % 7;
            trail2 = trail;
            trail = &pthis->handTrails[idx];
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 6654);

    BossSst_DrawEffect(&pthis->actor, globalCtx);
}

s32 BossSst_OverrideHeadDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                             Gfx** gfx) {
    BossSst* pthis = (BossSst*)thisx;
    s32 shakeAmp;
    s32 pad;
    s32 timer12;
    f32 shakeMod;

    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7) && pthis->vVanish) {
        *dList = NULL;
    } else if (pthis->actionFunc == BossSst_HeadThrash) { // Animation modifications for death cutscene
        shakeAmp = (pthis->timer / 10) + 1;
        if ((limbIndex == 3) || (limbIndex == 39) || (limbIndex == 42)) {

            shakeMod = sinf(pthis->timer * (M_PI / 5));
            rot->x += ((0x500 * Rand_ZeroOne() + 0xA00) / 0x10) * shakeAmp * shakeMod;

            shakeMod = sinf((pthis->timer % 5) * (M_PI / 5));
            rot->z -= ((0x800 * Rand_ZeroOne() + 0x1000) / 0x10) * shakeAmp * shakeMod + 0x1000;

            if (limbIndex == 3) {

                shakeMod = sinf(pthis->timer * (M_PI / 5));
                rot->y += ((0x500 * Rand_ZeroOne() + 0xA00) / 0x10) * shakeAmp * shakeMod;
            }
        } else if ((limbIndex == 5) || (limbIndex == 6)) {

            shakeMod = sinf((pthis->timer % 5) * (M_PI / 5));
            rot->z -= ((0x280 * Rand_ZeroOne() + 0x500) / 0x10) * shakeAmp * shakeMod + 0x500;

            if (limbIndex == 5) {

                shakeMod = sinf(pthis->timer * (M_PI / 5));
                rot->x += ((0x500 * Rand_ZeroOne() + 0xA00) / 0x10) * shakeAmp * shakeMod;

                shakeMod = sinf(pthis->timer * (M_PI / 5));
                rot->y += ((0x500 * Rand_ZeroOne() + 0xA00) / 0x10) * shakeAmp * shakeMod;
            }
        } else if (limbIndex == 2) {
            shakeMod = sinf(pthis->timer * (M_PI / 5));
            rot->x += ((0x200 * Rand_ZeroOne() + 0x400) / 0x10) * shakeAmp * shakeMod;

            shakeMod = sinf(pthis->timer * (M_PI / 5));
            rot->y += ((0x200 * Rand_ZeroOne() + 0x400) / 0x10) * shakeAmp * shakeMod;

            shakeMod = sinf((pthis->timer % 5) * (M_PI / 5));
            rot->z -= ((0x100 * Rand_ZeroOne() + 0x200) / 0x10) * shakeAmp * shakeMod + 0x200;
        }
    } else if (pthis->actionFunc == BossSst_HeadDeath) {
        if (pthis->timer > 48) {
            timer12 = pthis->timer - 36;
        } else {
            pad = ((pthis->timer > 6) ? 6 : pthis->timer);
            timer12 = pad * 2;
        }

        if ((limbIndex == 3) || (limbIndex == 39) || (limbIndex == 42)) {
            rot->z -= 0x2000 * sinf(timer12 * (M_PI / 24));
        } else if ((limbIndex == 5) || (limbIndex == 6)) {
            rot->z -= 0xA00 * sinf(timer12 * (M_PI / 24));
        } else if (limbIndex == 2) {
            rot->z -= 0x400 * sinf(timer12 * (M_PI / 24));
        }
    } else if ((pthis->actionFunc == BossSst_HeadDarken) || (pthis->actionFunc == BossSst_HeadFall) ||
               (pthis->actionFunc == BossSst_HeadMelt)) {
        if ((limbIndex == 3) || (limbIndex == 39) || (limbIndex == 42)) {
            rot->z -= 0x1000;
        } else if ((limbIndex == 5) || (limbIndex == 6)) {
            rot->z -= 0x500;
        } else if (limbIndex == 2) {
            rot->z -= 0x200;
        }
    }
    return false;
}

void BossSst_PostHeadDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    static Vec3f headVec = { 1000.0f, 0.0f, 0.0f };
    BossSst* pthis = (BossSst*)thisx;
    Vec3f headPos;

    if (limbIndex == 8) {
        Matrix_MultVec3f(&zeroVec, &pthis->actor.focus.pos);
        Matrix_MultVec3f(&headVec, &headPos);
        pthis->colliderCyl.dim.pos.x = headPos.x;
        pthis->colliderCyl.dim.pos.y = headPos.y;
        pthis->colliderCyl.dim.pos.z = headPos.z;
    }

    Collider_UpdateSpheres(limbIndex, &pthis->colliderJntSph);
}

void BossSst_DrawHead(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossSst* pthis = (BossSst*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 6810);

    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        func_80093D18(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x80, sBodyColor.r, sBodyColor.g, sBodyColor.b, 255);
        if (!sBodyStatic) {
            gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
        } else {
            gDPSetEnvColor(POLY_OPA_DISP++, sStaticColor.r, sStaticColor.g, sStaticColor.b, 0);
            gSPSegment(POLY_OPA_DISP++, 0x08, sBodyStaticDList);
        }
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 255, 255, 255, 255);
        gSPSegment(POLY_XLU_DISP++, 0x08, &D_80116280[2]);
    }

    if (pthis->actionFunc == BossSst_HeadThrash) {
        f32 randPitch = Rand_ZeroOne() * (2 * M_PI);
        f32 randYaw = Rand_ZeroOne() * (2 * M_PI);

        Matrix_RotateY(randYaw, MTXMODE_APPLY);
        Matrix_RotateX(randPitch, MTXMODE_APPLY);
        Matrix_Scale((pthis->timer * 0.000375f) + 1.0f, 1.0f - (pthis->timer * 0.00075f),
                     (pthis->timer * 0.000375f) + 1.0f, MTXMODE_APPLY);
        Matrix_RotateX(-randPitch, MTXMODE_APPLY);
        Matrix_RotateY(-randYaw, MTXMODE_APPLY);
    }

    if (!CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, BossSst_OverrideHeadDraw, BossSst_PostHeadDraw,
                                           pthis, POLY_OPA_DISP);
    } else {
        POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, BossSst_OverrideHeadDraw, BossSst_PostHeadDraw,
                                           pthis, POLY_XLU_DISP);
    }

    if ((pthis->actionFunc == BossSst_HeadIntro) && (113 >= pthis->timer) && (pthis->timer > 20)) {
        s32 yOffset;
        Vec3f vanishMaskPos;
        Vec3f vanishMaskOffset;

        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 0, 0, 18, 255);

        yOffset = 113 * 8 - pthis->timer * 8;
        vanishMaskPos.x = ROOM_CENTER_X + 85.0f;
        vanishMaskPos.y = ROOM_CENTER_Y - 250.0f + yOffset;
        vanishMaskPos.z = ROOM_CENTER_Z + 190.0f;
        if (vanishMaskPos.y > 450.0f) {
            vanishMaskPos.y = 450.0f;
        }

        Matrix_MultVec3fExt(&vanishMaskPos, &vanishMaskOffset, &globalCtx->billboardMtxF);
        Matrix_Translate(pthis->actor.world.pos.x + vanishMaskOffset.x, pthis->actor.world.pos.y + vanishMaskOffset.y,
                         pthis->actor.world.pos.z + vanishMaskOffset.z, MTXMODE_NEW);
        Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);

        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_sst.c", 6934),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, sIntroVanishDList);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 6941);

    SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &pthis->actor.focus.pos, &pthis->center);
    BossSst_DrawEffect(&pthis->actor, globalCtx);
}

void BossSst_SpawnHeadShadow(BossSst* pthis) {
    static Vec3f shadowOffset[] = {
        { 0.0f, 0.0f, 340.0f },
        { -160.0f, 0.0f, 250.0f },
        { 160.0f, 0.0f, 250.0f },
    };
    s32 pad;
    s32 i;
    f32 sn;
    f32 cs;

    pthis->effectMode = BONGO_SHADOW;
    sn = Math_SinS(pthis->actor.shape.rot.y);
    cs = Math_CosS(pthis->actor.shape.rot.y);

    for (i = 0; i < 3; i++) {
        BossSstEffect* shadow = &pthis->effects[i];
        Vec3f* offset = &shadowOffset[i];

        shadow->pos.x = pthis->actor.world.pos.x + (sn * offset->z) + (cs * offset->x);
        shadow->pos.y = 0.0f;
        shadow->pos.z = pthis->actor.world.pos.z + (cs * offset->z) - (sn * offset->x);

        shadow->scale = 1450;
        shadow->alpha = 254;
        shadow->status = 65;
    }

    pthis->effects[3].status = -1;
}

void BossSst_SpawnHandShadow(BossSst* pthis) {
    pthis->effectMode = BONGO_SHADOW;
    pthis->effects[0].pos.x = pthis->actor.world.pos.x + (Math_CosS(pthis->actor.shape.rot.y) * 30.0f * pthis->vParity);
    pthis->effects[0].pos.z = pthis->actor.world.pos.z - (Math_SinS(pthis->actor.shape.rot.y) * 30.0f * pthis->vParity);
    pthis->effects[0].pos.y = pthis->actor.world.pos.y;
    pthis->effects[0].scale = 2300;
    pthis->effects[0].alpha = 254;
    pthis->effects[0].status = 5;
    pthis->effects[1].status = -1;
}

void BossSst_SpawnShockwave(BossSst* pthis) {
    s32 i;
    s32 scale = 120;
    s32 alpha = 250;

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_SHADEST_HAND_WAVE);
    pthis->effectMode = BONGO_SHOCKWAVE;

    for (i = 0; i < 3; i++) {
        BossSstEffect* shockwave = &pthis->effects[i];

        Math_Vec3f_Copy(&shockwave->pos, &pthis->actor.world.pos);
        shockwave->move = (i + 9) * 2;
        shockwave->scale = scale;
        shockwave->alpha = alpha / shockwave->move;
        scale -= 50;
        alpha -= 25;
    }
}

void BossSst_SpawnIceCrystal(BossSst* pthis, s32 index) {
    BossSstEffect* ice = &pthis->effects[index];
    Sphere16* sphere;

    if (index < 11) {
        sphere = &pthis->colliderJntSph.elements[index].dim.worldSphere;

        ice->pos.x = sphere->center.x;
        ice->pos.y = sphere->center.y;
        ice->pos.z = sphere->center.z;
        if (index == 0) {
            ice->pos.x -= 25.0f;
            ice->pos.y -= 25.0f;
            ice->pos.z -= 25.0f;
        }
    } else {
        sphere = &pthis->colliderJntSph.elements[0].dim.worldSphere;

        ice->pos.x = ((((index - 11) & 1) ? 1 : -1) * 25.0f) + sphere->center.x;
        ice->pos.y = ((((index - 11) & 2) ? 1 : -1) * 25.0f) + sphere->center.y;
        ice->pos.z = ((((index - 11) & 4) ? 1 : -1) * 25.0f) + sphere->center.z;
    }

    ice->pos.x -= pthis->actor.world.pos.x;
    ice->pos.y -= pthis->actor.world.pos.y;
    ice->pos.z -= pthis->actor.world.pos.z;

    ice->status = 0;

    ice->rot.x = Rand_ZeroOne() * 0x10000;
    ice->rot.y = Rand_ZeroOne() * 0x10000;
    ice->rot.z = Rand_ZeroOne() * 0x10000;

    ice->alpha = 120;
    ice->move = true;

    ice->vel.x = (Rand_ZeroOne() * 0.06f + 0.12f) * ice->pos.x;
    ice->vel.y = (Rand_ZeroOne() * 15.0f + 5.0f);
    ice->vel.z = (Rand_ZeroOne() * 0.06f + 0.12f) * ice->pos.z;
    ice->scale = 4000;

    if ((index % 2) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_FREEZE_S);
    }
}

void BossSst_SpawnIceShard(BossSst* pthis) {
    s32 i;
    Vec3f spawnPos;
    f32 offXZ;

    pthis->effectMode = BONGO_ICE;
    offXZ = Math_CosS(pthis->actor.shape.rot.x) * 50.0f;
    spawnPos.x = Math_CosS(pthis->actor.shape.rot.y) * offXZ + pthis->actor.world.pos.x;
    spawnPos.y = Math_SinS(pthis->actor.shape.rot.x) * 50.0f + pthis->actor.world.pos.y - 10.0f;
    spawnPos.z = Math_SinS(pthis->actor.shape.rot.y) * offXZ + pthis->actor.world.pos.z;

    for (i = 0; i < 18; i++) {
        BossSstEffect* ice = &pthis->effects[i];

        Math_Vec3f_Copy(&ice->pos, &spawnPos);
        ice->status = 1;
        ice->rot.x = Rand_ZeroOne() * 0x10000;
        ice->rot.y = Rand_ZeroOne() * 0x10000;
        ice->rot.z = Rand_ZeroOne() * 0x10000;

        ice->alpha = 120;
        ice->move = true;

        ice->vel.x = Rand_CenteredFloat(20.0f);
        ice->vel.y = Rand_ZeroOne() * 10.0f + 3.0f;
        ice->vel.z = Rand_CenteredFloat(20.0f);

        ice->scale = Rand_ZeroOne() * 200.0f + 400.0f;
    }
}

void BossSst_IceShatter(BossSst* pthis) {
    s32 i;

    pthis->effects[0].status = 1;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_ICE_BROKEN);

    for (i = 0; i < 18; i++) {
        BossSstEffect* ice = &pthis->effects[i];

        if (ice->move) {
            ice->pos.x += pthis->actor.world.pos.x;
            ice->pos.y += pthis->actor.world.pos.y;
            ice->pos.z += pthis->actor.world.pos.z;
        }
    }
}

void BossSst_UpdateEffect(Actor* thisx, GlobalContext* globalCtx) {
    BossSst* pthis = (BossSst*)thisx;
    BossSstEffect* effect;
    s32 i;

    if (pthis->effectMode != BONGO_NULL) {
        if (pthis->effectMode == BONGO_ICE) {
            if (pthis->effects[0].status) {
                for (i = 0; i < 18; i++) {
                    effect = &pthis->effects[i];

                    if (effect->move) {
                        effect->pos.x += effect->vel.x;
                        effect->pos.y += effect->vel.y;
                        effect->pos.z += effect->vel.z;
                        effect->alpha -= 3;
                        effect->vel.y -= 1.0f;
                        effect->rot.x += 0xD00;
                        effect->rot.y += 0x1100;
                        effect->rot.z += 0x1500;
                    }
                }
            }
            if (pthis->effects[0].alpha == 0) {
                pthis->effectMode = BONGO_NULL;
            }
        } else if (pthis->effectMode == BONGO_SHOCKWAVE) {
            for (i = 0; i < 3; i++) {
                BossSstEffect* effect2 = &pthis->effects[i];
                s32 scale = effect2->move * 2;

                effect2->scale += CLAMP_MAX(scale, 20) + i;
                if (effect2->move != 0) {
                    effect2->move--;
                }
            }

            if (pthis->effects[0].move == 0) {
                pthis->effectMode = BONGO_NULL;
            }
        } else if (pthis->effectMode == BONGO_SHADOW) {
            effect = &pthis->effects[0];

            if (pthis->actor.params == BONGO_HEAD) {
                SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &pthis->actor.focus.pos, &pthis->center);
                BossSst_HeadSfx(pthis, NA_SE_EN_SHADEST_LAST - SFX_FLAG);
            }
            while (effect->status != -1) {
                if (effect->status == 0) {
                    effect->alpha -= 2;
                } else {
                    effect->scale += effect->status;
                }

                effect->scale = CLAMP_MAX(effect->scale, 10000);
                effect++;
            }
        }
    }
}

void BossSst_DrawEffect(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossSst* pthis = (BossSst*)thisx;
    s32 i;
    BossSstEffect* effect;

    if (pthis->effectMode != BONGO_NULL) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 7302);

        func_80093D84(globalCtx->state.gfxCtx);
        if (pthis->effectMode == BONGO_ICE) {
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, globalCtx->gameplayFrames % 256, 0x20, 0x10, 1,
                                        0, (globalCtx->gameplayFrames * 2) % 256, 0x40, 0x20));
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 50, 100, pthis->effects[0].alpha);
            gSPDisplayList(POLY_XLU_DISP++, gBongoIceCrystalDL);

            for (i = 0; i < 18; i++) {
                effect = &pthis->effects[i];
                if (effect->move) {
                    func_8003435C(&effect->pos, globalCtx);
                    if (pthis->effects[0].status != 0) {
                        Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
                    } else {
                        Matrix_Translate(effect->pos.x + pthis->actor.world.pos.x,
                                         effect->pos.y + pthis->actor.world.pos.y,
                                         effect->pos.z + pthis->actor.world.pos.z, MTXMODE_NEW);
                    }

                    Matrix_RotateZYX(effect->rot.x, effect->rot.y, effect->rot.z, MTXMODE_APPLY);
                    Matrix_Scale(effect->scale * 0.001f, effect->scale * 0.001f, effect->scale * 0.001f, MTXMODE_APPLY);

                    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_sst.c", 7350),
                              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(POLY_XLU_DISP++, gBongoIceShardDL);
                }
            }
        } else if (pthis->effectMode == BONGO_SHOCKWAVE) {
            f32 scaleY = 0.005f;

            gDPPipeSync(POLY_XLU_DISP++);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, globalCtx->gameplayFrames % 128, 0, 0x20, 0x40, 1,
                                        0, (globalCtx->gameplayFrames * -15) % 256, 0x20, 0x40));

            for (i = 0; i < 3; i++, scaleY -= 0.001f) {
                effect = &pthis->effects[i];

                if (effect->move != 0) {
                    Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
                    Matrix_Scale(effect->scale * 0.001f, scaleY, effect->scale * 0.001f, MTXMODE_APPLY);

                    gDPPipeSync(POLY_XLU_DISP++);
                    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 30, 0, 30, effect->alpha * effect->move);
                    gDPSetEnvColor(POLY_XLU_DISP++, 30, 0, 30, 0);
                    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_sst.c", 7396),
                              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(POLY_XLU_DISP++, gEffFireCircleDL);
                }
            }
        } else if (pthis->effectMode == BONGO_SHADOW) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 10, 10, 80, 0);
            gDPSetEnvColor(POLY_XLU_DISP++, 10, 10, 10, pthis->effects[0].alpha);

            effect = &pthis->effects[0];
            while (effect->status != -1) {
                Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
                Matrix_Scale(effect->scale * 0.001f, 1.0f, effect->scale * 0.001f, MTXMODE_APPLY);

                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_sst.c", 7423),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, sShadowDList);
                effect++;
            }
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_sst.c", 7433);
    }
}

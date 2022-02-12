#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HEISHI3_Z_EN_HEISHI3_C
#include "actor_common.h"
/*
 * File: z_en_heishi3.c
 * Overlay: ovl_En_Heishi3
 * Description: Hyrule Castle Guard
 */

#include "z_en_heishi3.h"
#include "objects/object_sd/object_sd.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnHeishi3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi3_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHeishi3_SetupGuardType(EnHeishi3* pthis, GlobalContext* globalCtx);
void EnHeishi3_StandSentinelInGrounds(EnHeishi3* pthis, GlobalContext* globalCtx);
void EnHeishi3_StandSentinelInCastle(EnHeishi3* pthis, GlobalContext* globalCtx);
void EnHeishi3_CatchStart(EnHeishi3* pthis, GlobalContext* globalCtx);
void EnHeishi3_ResetAnimationToIdle(EnHeishi3* pthis, GlobalContext* globalCtx);
void func_80A55D00(EnHeishi3* pthis, GlobalContext* globalCtx);
void func_80A55BD4(EnHeishi3* pthis, GlobalContext* globalCtx);

static s16 sPlayerCaught = 0;

ActorInit En_Heishi3_InitVars = {
    ACTOR_EN_HEISHI3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi3),
    (ActorFunc)EnHeishi3_Init,
    (ActorFunc)EnHeishi3_Destroy,
    (ActorFunc)EnHeishi3_Update,
    (ActorFunc)EnHeishi3_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 15, 70, 0, { 0, 0, 0 } },
};

void EnHeishi3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi3* pthis = (EnHeishi3*)thisx;

    sPlayerCaught = 0;
    if (pthis->actor.params <= 0) {
        pthis->unk_278 = 0;
    } else {
        pthis->unk_278 = 1;
        if (pthis->actor.world.pos.x < -290.0f) {
            pthis->unk_278 = 2;
        }
    }
    Actor_SetScale(&pthis->actor, 0.01f);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gEnHeishiSkel, &gEnHeishiIdleAnim, pthis->jointTable, pthis->morphTable,
                   17);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.targetMode = 6;
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    // "Castle Gate Soldier - Power Up"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 城門兵パワーアップ ☆☆☆☆☆ \n" VT_RST);

    pthis->actor.gravity = -3.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actionFunc = EnHeishi3_SetupGuardType;
}

void EnHeishi3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi3* pthis = (EnHeishi3*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnHeishi3_SetupGuardType(EnHeishi3* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    if (pthis->unk_278 == 0) {
        pthis->actionFunc = EnHeishi3_StandSentinelInGrounds;
    } else {
        pthis->actionFunc = EnHeishi3_StandSentinelInCastle;
    }
}

/**
 * Handles the guards standing on Hyrule Castle Grounds.
 **/
void EnHeishi3_StandSentinelInGrounds(EnHeishi3* pthis, GlobalContext* globalCtx) {
    Player* player;
    s16 yawDiff;
    s16 yawDiffNew;
    f32 sightRange;

    player = GET_PLAYER(globalCtx);
    SkelAnime_Update(&pthis->skelAnime);
    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    yawDiffNew = ABS(yawDiff);
    if (yawDiffNew < 0x4300) {
        if (IS_DAY) {
            sightRange = 250.0f;
        } else {
            sightRange = 200.0f;
        }
    } else {
        if (IS_DAY) {
            sightRange = 150.0f;
        } else {
            sightRange = 100.0f;
        }
    }
    if ((pthis->actor.xzDistToPlayer < sightRange) &&
        (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 100.0f) && (sPlayerCaught == 0)) {
        sPlayerCaught = 1;
        Message_StartTextbox(globalCtx, 0x702D, &pthis->actor);
        func_80078884(NA_SE_SY_FOUND);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発見！ ☆☆☆☆☆ \n" VT_RST); // "Discovered!"
        func_8002DF54(globalCtx, &pthis->actor, 1);
        pthis->actionFunc = EnHeishi3_CatchStart;
    }
}

/**
 * Handles the guards standing in front of Hyrule Castle.
 **/
void EnHeishi3_StandSentinelInCastle(EnHeishi3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if ((player->actor.world.pos.x < -190.0f) && (player->actor.world.pos.x > -380.0f) &&
        (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 100.0f) &&
        (player->actor.world.pos.z < 1020.0f) && (player->actor.world.pos.z > 700.0f) && (sPlayerCaught == 0)) {
        if (pthis->unk_278 == 1) {
            if ((player->actor.world.pos.x < -290.0f)) {
                return;
            }
        } else {
            if (player->actor.world.pos.x > -290.0f) {
                return;
            }
        }
        sPlayerCaught = 1;
        Message_StartTextbox(globalCtx, 0x702D, &pthis->actor);
        func_80078884(NA_SE_SY_FOUND);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発見！ ☆☆☆☆☆ \n" VT_RST); // "Discovered!"
        func_8002DF54(globalCtx, &pthis->actor, 1);
        pthis->actionFunc = EnHeishi3_CatchStart;
    }
}

void EnHeishi3_CatchStart(EnHeishi3* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiWalkAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiWalkAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->caughtTimer = 20;
    pthis->actionFunc = func_80A55BD4;
    pthis->actor.speedXZ = 2.5f;
}

void func_80A55BD4(EnHeishi3* pthis, GlobalContext* globalCtx) {

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 1.0f) || Animation_OnFrame(&pthis->skelAnime, 17.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KNIGHT_WALK);
    }
    if (pthis->caughtTimer == 0) {
        pthis->actionFunc = EnHeishi3_ResetAnimationToIdle;
        pthis->actor.speedXZ = 0.0f;
    } else {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 5, 3000, 0);
    }
}

void EnHeishi3_ResetAnimationToIdle(EnHeishi3* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = func_80A55D00;
}

// This function initiates the respawn after the player gets caught.
void func_80A55D00(EnHeishi3* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx) &&
        (pthis->respawnFlag == 0)) {
        gSaveContext.eventChkInf[4] |= 0x4000;
        globalCtx->nextEntranceIndex = 0x47E; // Hyrule Castle from Guard Capture (outside)
        globalCtx->sceneLoadFlag = 0x14;
        pthis->respawnFlag = 1;
        globalCtx->fadeTransition = 0x2E;
        gSaveContext.nextTransition = 0x2E;
    }
}

void EnHeishi3_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi3* pthis = (EnHeishi3*)thisx;
    s32 pad;

    Actor_SetFocus(&pthis->actor, 60.0f);
    pthis->unk_274 += 1;
    if (pthis->caughtTimer != 0) {
        pthis->caughtTimer -= 1;
    }
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.shape.rot = pthis->actor.world.rot;
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 50.0f, 0x1C);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnHeishi3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    EnHeishi3* pthis = (EnHeishi3*)thisx;

    if (limbIndex == 9) {
        rot->x += pthis->unk_26E;
    }

    if (limbIndex == 16) {
        rot->x += pthis->unk_262;
        rot->z += pthis->unk_264;
    }

    return false;
}

void EnHeishi3_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi3* pthis = (EnHeishi3*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHeishi3_OverrideLimbDraw, NULL,
                      pthis);
}

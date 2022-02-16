#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HEISHI1_Z_EN_HEISHI1_C
#include "actor_common.h"
/*
 * File: z_en_heishi1.c
 * Overlay: ovl_En_Heishi1
 * Description: Courtyard Guards
 */

#include "z_en_heishi1.h"
#include "objects/object_sd/object_sd.h"
#include "vt.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void EnHeishi1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi1_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHeishi1_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi1_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi1_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHeishi1_SetupWait(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_SetupWalk(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_SetupMoveToLink(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_SetupTurnTowardLink(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_SetupKick(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_SetupWaitNight(EnHeishi1* pthis, GlobalContext* globalCtx);

void EnHeishi1_Wait(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_Walk(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_MoveToLink(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_TurnTowardLink(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_Kick(EnHeishi1* pthis, GlobalContext* globalCtx);
void EnHeishi1_WaitNight(EnHeishi1* pthis, GlobalContext* globalCtx);

static s32 sPlayerIsCaught = false;

ActorInit En_Heishi1_InitVars = {
    0,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi1),
    (ActorFunc)EnHeishi1_Init,
    (ActorFunc)EnHeishi1_Destroy,
    (ActorFunc)EnHeishi1_Update,
    (ActorFunc)EnHeishi1_Draw,
    (ActorFunc)EnHeishi1_Reset,
};

static f32 sAnimParamsInit[][8] = {
    { 1.0f, -10.0f, 3.0f, 0.5f, 1000.0f, 200.0f, 0.3f, 1000.0f },
    { 3.0f, -3.0f, 6.0f, 0.8f, 2000.0f, 400.0f, 0.5f, 2000.0f },
    { 1.0f, -10.0f, 3.0f, 0.5f, 1000.0f, 200.0f, 0.3f, 1000.0f },
    { 3.0f, -3.0f, 6.0f, 0.8f, 2000.0f, 400.0f, 0.5f, 2000.0f },
};

static s16 sBaseHeadTimers[] = { 20, 10, 20, 10, 13, 0 };

static Vec3f sRupeePositions[] = {
    { 0.0f, 0.0f, 90.0f },  { -55.0f, 0.0f, 90.0f }, { -55.0f, 0.0f, 30.0f }, { -55.0f, 0.0f, -30.0f },
    { 0.0f, 0.0f, -30.0f }, { 55.0f, 0.0f, -30.0f }, { 55.0f, 0.0f, 30.0f },  { 55.0f, 0.0f, 90.0f },
};

static s32 sCamDataIdxs[] = {
    7, 7, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 4, 4, 5, 6,
};

static s16 sWaypoints[] = { 0, 4, 1, 5, 2, 6, 3, 7 };

void EnHeishi1_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHeishi1* pthis = (EnHeishi1*)thisx;
    Vec3f rupeePos;
    s32 i;

    Actor_SetScale(&pthis->actor, 0.01f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gEnHeishiSkel, &gEnHeishiIdleAnim, pthis->jointTable, pthis->morphTable,
                   17);

    pthis->type = (pthis->actor.params >> 8) & 0xFF;
    pthis->path = pthis->actor.params & 0xFF;

    for (i = 0; i < ARRAY_COUNT(sAnimParamsInit[0]); i++) {
        pthis->animParams[i] = sAnimParamsInit[pthis->type][i];
    }

    // "type"
    osSyncPrintf(VT_FGCOL(GREEN) " 種類☆☆☆☆☆☆☆☆☆☆☆☆☆ %d\n" VT_RST, pthis->type);
    // "path data"
    osSyncPrintf(VT_FGCOL(YELLOW) " れえるでぇたぁ☆☆☆☆☆☆☆☆ %d\n" VT_RST, pthis->path);
    osSyncPrintf(VT_FGCOL(PURPLE) " anime_frame_speed ☆☆☆☆☆☆ %f\n" VT_RST, pthis->animSpeed);
    // "interpolation frame"
    osSyncPrintf(VT_FGCOL(PURPLE) " 補間フレーム☆☆☆☆☆☆☆☆☆ %f\n" VT_RST, pthis->transitionRate);
    // "targeted movement speed value between points"
    osSyncPrintf(VT_FGCOL(PURPLE) " point間の移動スピード目標値 ☆ %f\n" VT_RST, pthis->moveSpeedTarget);
    // "maximum movement speed value between points"
    osSyncPrintf(VT_FGCOL(PURPLE) " point間の移動スピード最大 ☆☆ %f\n" VT_RST, pthis->moveSpeedMax);
    // "(body) targeted turning angle speed value"
    osSyncPrintf(VT_FGCOL(PURPLE) " (体)反転アングルスピード目標値 %f\n" VT_RST, pthis->bodyTurnSpeedTarget);
    // "(body) maximum turning angle speed"
    osSyncPrintf(VT_FGCOL(PURPLE) " (体)反転アングルスピード最大☆ %f\n" VT_RST, pthis->bodyTurnSpeedMax);
    // "(head) targeted turning angle speed value"
    osSyncPrintf(VT_FGCOL(PURPLE) " (頭)反転アングルスピード加算値 %f\n" VT_RST, pthis->headTurnSpeedScale);
    // "(head) maximum turning angle speed"
    osSyncPrintf(VT_FGCOL(PURPLE) " (頭)反転アングルスピード最大☆ %f\n" VT_RST, pthis->headTurnSpeedMax);
    osSyncPrintf(VT_FGCOL(GREEN) " 今時間 %d\n" VT_RST, ((void)0, gSaveContext.dayTime)); // "current time"
    osSyncPrintf(VT_FGCOL(YELLOW) " チェック時間 %d\n" VT_RST, 0xBAAA);                   // "check time"
    osSyncPrintf("\n\n");

    if (pthis->path == 3) {
        for (i = 0; i < ARRAY_COUNT(sRupeePositions); i++) {
            rupeePos = sRupeePositions[i];
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_RUPPY, rupeePos.x, rupeePos.y,
                               rupeePos.z, 0, 0, 0, 3);
        }
    }

    if (pthis->type != 5) {
        if (((gSaveContext.dayTime < 0xB888) || IS_DAY) && !(gSaveContext.eventChkInf[8] & 1)) {
            pthis->actionFunc = EnHeishi1_SetupWalk;
        } else {
            Actor_Kill(&pthis->actor);
        }
    } else {
        if ((gSaveContext.dayTime >= 0xB889) || !IS_DAY || (gSaveContext.eventChkInf[8] & 1)) {
            pthis->actionFunc = EnHeishi1_SetupWaitNight;
        } else {
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnHeishi1_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnHeishi1_SetupWalk(EnHeishi1* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiWalkAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiWalkAnim, pthis->animSpeed, 0.0f, (s16)frameCount, ANIMMODE_LOOP,
                     pthis->transitionRate);
    pthis->bodyTurnSpeed = 0.0f;
    pthis->moveSpeed = 0.0f;
    pthis->headDirection = Rand_ZeroFloat(1.99f);
    pthis->actionFunc = EnHeishi1_Walk;
}

void EnHeishi1_Walk(EnHeishi1* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* pointPos;
    f32 pathDiffX;
    f32 pathDiffZ;
    s16 randOffset;

    SkelAnime_Update(&pthis->skelAnime);

    if (Animation_OnFrame(&pthis->skelAnime, 1.0f) || Animation_OnFrame(&pthis->skelAnime, 17.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_KNIGHT_WALK);
    }

    if (!sPlayerIsCaught) {
        path = &globalCtx->setupPathList[pthis->path];
        pointPos = SEGMENTED_TO_VIRTUAL(path->points);
        pointPos += pthis->waypoint;

        Math_ApproachF(&pthis->actor.world.pos.x, pointPos->x, 1.0f, pthis->moveSpeed);
        Math_ApproachF(&pthis->actor.world.pos.z, pointPos->z, 1.0f, pthis->moveSpeed);

        Math_ApproachF(&pthis->moveSpeed, pthis->moveSpeedTarget, 1.0f, pthis->moveSpeedMax);

        pathDiffX = pointPos->x - pthis->actor.world.pos.x;
        pathDiffZ = pointPos->z - pthis->actor.world.pos.z;
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, (Math_FAtan2F(pathDiffX, pathDiffZ) * (0x8000 / M_PI)), 3,
                           pthis->bodyTurnSpeed, 0);

        Math_ApproachF(&pthis->bodyTurnSpeed, pthis->bodyTurnSpeedTarget, 1.0f, pthis->bodyTurnSpeedMax);

        if (pthis->headTimer == 0) {
            pthis->headDirection++;
            pthis->headAngleTarget = 0x2000;
            // if headDirection is odd, face 45 degrees left
            if ((pthis->headDirection & 1) != 0) {
                pthis->headAngleTarget *= -1;
            }
            randOffset = Rand_ZeroFloat(30.0f);
            pthis->headTimer = sBaseHeadTimers[pthis->type] + randOffset;
        }

        Math_ApproachF(&pthis->headAngle, pthis->headAngleTarget, pthis->headTurnSpeedScale, pthis->headTurnSpeedMax);

        if ((pthis->path == BREG(1)) && (BREG(0) != 0)) {
            osSyncPrintf(VT_FGCOL(RED) " 種類  %d\n" VT_RST, pthis->path);
            osSyncPrintf(VT_FGCOL(RED) " ぱす  %d\n" VT_RST, pthis->waypoint);
            osSyncPrintf(VT_FGCOL(RED) " 反転  %d\n" VT_RST, pthis->bodyTurnSpeed);
            osSyncPrintf(VT_FGCOL(RED) " 時間  %d\n" VT_RST, pthis->waypointTimer);
            osSyncPrintf(VT_FGCOL(RED) " 点座  %d\n" VT_RST, path->count);
            osSyncPrintf("\n\n");
        }

        // when 20 units away from a middle waypoint, decide whether or not to skip it
        if ((fabsf(pathDiffX) < 20.0f) && (fabsf(pathDiffZ) < 20.0f)) {
            if (pthis->waypointTimer == 0) {
                if (pthis->type >= 2) {
                    if ((pthis->waypoint >= 4) && (Rand_ZeroFloat(1.99f) > 1.0f)) {
                        if (pthis->waypoint == 7) {
                            pthis->waypoint = 0;
                        }
                        if (pthis->waypoint >= 4) {
                            pthis->waypoint -= 3;
                        }
                        pthis->waypointTimer = 5;
                        return;
                    }
                }
                pthis->actionFunc = EnHeishi1_SetupWait;
            }
        }
    }
}

void EnHeishi1_SetupMoveToLink(EnHeishi1* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiWalkAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiWalkAnim, 3.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -3.0f);
    pthis->bodyTurnSpeed = 0.0f;
    pthis->moveSpeed = 0.0f;
    Message_StartTextbox(globalCtx, 0x702D, &pthis->actor);
    Interface_SetDoAction(globalCtx, DO_ACTION_STOP);
    pthis->actionFunc = EnHeishi1_MoveToLink;
}

void EnHeishi1_MoveToLink(EnHeishi1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachF(&pthis->actor.world.pos.x, player->actor.world.pos.x, 1.0f, pthis->moveSpeed);
    Math_ApproachF(&pthis->actor.world.pos.z, player->actor.world.pos.z, 1.0f, pthis->moveSpeed);
    Math_ApproachF(&pthis->moveSpeed, 6.0f, 1.0f, 0.4f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, pthis->bodyTurnSpeed, 0);
    Math_ApproachF(&pthis->bodyTurnSpeed, 3000.0f, 1.0f, 300.0f);
    Math_ApproachZeroF(&pthis->headAngle, 0.5f, 2000.0f);

    if (pthis->actor.xzDistToPlayer < 70.0f) {
        pthis->actionFunc = EnHeishi1_SetupTurnTowardLink;
    }
}

void EnHeishi1_SetupWait(EnHeishi1* pthis, GlobalContext* globalCtx) {
    s16 rand;
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, pthis->animSpeed, 0.0f, (s16)frameCount, ANIMMODE_LOOP,
                     pthis->transitionRate);
    pthis->headBehaviorDecided = false;
    pthis->headDirection = Rand_ZeroFloat(1.99f);
    rand = Rand_ZeroFloat(50.0f);
    pthis->waitTimer = rand + 50;
    pthis->actionFunc = EnHeishi1_Wait;
}

void EnHeishi1_Wait(EnHeishi1* pthis, GlobalContext* globalCtx) {
    s16 randOffset;
    s32 i;

    SkelAnime_Update(&pthis->skelAnime);
    if (!sPlayerIsCaught) {
        switch (pthis->headBehaviorDecided) {
            case false:
                pthis->headDirection++;
                // if headDirection is odd, face 52 degrees left
                pthis->headAngleTarget = (pthis->headDirection & 1) ? 0x2500 : -0x2500;
                randOffset = Rand_ZeroFloat(30.0f);
                pthis->headTimer = sBaseHeadTimers[pthis->type] + randOffset;
                pthis->headBehaviorDecided = true;
                break;
            case true:
                if (pthis->headTimer == 0) {
                    if (pthis->waitTimer == 0) {
                        if ((pthis->type == 0) || (pthis->type == 1)) {
                            pthis->waypoint++;
                            if (pthis->waypoint >= 4) {
                                pthis->waypoint = 0;
                            }
                        } else {
                            // waypoints are defined with corners as 0-3 and middle points as 4-7
                            // to choose the next waypoint, the order "04152637" is hardcoded in an array
                            for (i = 0; i < ARRAY_COUNT(sWaypoints); i++) {
                                if (pthis->waypoint == sWaypoints[i]) {
                                    i++;
                                    if (i >= ARRAY_COUNT(sWaypoints)) {
                                        i = 0;
                                    }
                                    pthis->waypoint = sWaypoints[i];
                                    break;
                                }
                            }
                            pthis->waypointTimer = 5;
                        }
                        pthis->actionFunc = EnHeishi1_SetupWalk;
                    } else {
                        pthis->headBehaviorDecided = false;
                    }
                }
                break;
        }
        Math_ApproachF(&pthis->headAngle, pthis->headAngleTarget, pthis->headTurnSpeedScale,
                       pthis->headTurnSpeedMax + pthis->headTurnSpeedMax);

        if ((pthis->path == BREG(1)) && (BREG(0) != 0)) {
            osSyncPrintf(VT_FGCOL(GREEN) " 種類  %d\n" VT_RST, pthis->path);
            osSyncPrintf(VT_FGCOL(GREEN) " ぱす  %d\n" VT_RST, pthis->waypoint);
            osSyncPrintf(VT_FGCOL(GREEN) " 反転  %d\n" VT_RST, pthis->bodyTurnSpeed);
            osSyncPrintf(VT_FGCOL(GREEN) " 時間  %d\n" VT_RST, pthis->waypointTimer);
            osSyncPrintf("\n\n");
        }
    }
}

void EnHeishi1_SetupTurnTowardLink(EnHeishi1* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->kickTimer = 30;
    pthis->actionFunc = EnHeishi1_TurnTowardLink;
}

void EnHeishi1_TurnTowardLink(EnHeishi1* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->type != 5) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, pthis->bodyTurnSpeed, 0);
        Math_ApproachF(&pthis->bodyTurnSpeed, 3000.0f, 1.0f, 300.0f);
        Math_ApproachZeroF(&pthis->headAngle, 0.5f, 2000.0f);
    }

    if (pthis->kickTimer == 0) {
        pthis->actionFunc = EnHeishi1_SetupKick;
    }
}

void EnHeishi1_SetupKick(EnHeishi1* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = EnHeishi1_Kick;
}

void EnHeishi1_Kick(EnHeishi1* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (!pthis->loadStarted) {
        // if dialog state is 5 and textbox has been advanced, kick player out
        if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
            Message_CloseTextbox(globalCtx);
            if (!pthis->loadStarted) {
                gSaveContext.eventChkInf[4] |= 0x4000;
                globalCtx->nextEntranceIndex = 0x4FA;
                globalCtx->sceneLoadFlag = 0x14;
                pthis->loadStarted = true;
                sPlayerIsCaught = false;
                globalCtx->fadeTransition = 0x2E;
                gSaveContext.nextTransition = 0x2E;
            }
        }
    }
}

void EnHeishi1_SetupWaitNight(EnHeishi1* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = EnHeishi1_WaitNight;
}

void EnHeishi1_WaitNight(EnHeishi1* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.xzDistToPlayer < 100.0f) {
        Message_StartTextbox(globalCtx, 0x702D, &pthis->actor);
        func_80078884(NA_SE_SY_FOUND);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発見！ ☆☆☆☆☆ \n" VT_RST); // "Discovered!"
        func_8002DF54(globalCtx, &pthis->actor, 1);
        pthis->actionFunc = EnHeishi1_SetupKick;
    }
}

void EnHeishi1_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi1* pthis = (EnHeishi1*)thisx;
    s16 path;
    u8 i;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad2;
    Camera* activeCam;

    pthis->activeTimer++;

    for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }

    if (pthis->waypointTimer != 0) {
        pthis->waypointTimer--;
    }

    activeCam = GET_ACTIVE_CAM(globalCtx);

    if (player->actor.freezeTimer == 0) {

        pthis->actionFunc(pthis, globalCtx);

        pthis->actor.uncullZoneForward = 550.0f;
        pthis->actor.uncullZoneScale = 350.0f;
        pthis->actor.uncullZoneDownward = 700.0f;

        if (pthis->type != 5) {
            path = pthis->path * 2;
            if ((sCamDataIdxs[path] == activeCam->camDataIdx) || (sCamDataIdxs[path + 1] == activeCam->camDataIdx)) {
                if (!sPlayerIsCaught) {
                    if ((pthis->actionFunc == EnHeishi1_Walk) || (pthis->actionFunc == EnHeishi1_Wait)) {
                        Vec3f searchBallVel;
                        Vec3f searchBallAccel = { 0.0f, 0.0f, 0.0f };
                        Vec3f searchBallMult = { 0.0f, 0.0f, 20.0f };
                        Vec3f searchBallPos;

                        searchBallPos.x = pthis->actor.world.pos.x;
                        searchBallPos.y = pthis->actor.world.pos.y + 60.0f;
                        searchBallPos.z = pthis->actor.world.pos.z;

                        Matrix_Push();
                        Matrix_RotateY(((pthis->actor.shape.rot.y + pthis->headAngle) / 32768.0f) * M_PI, MTXMODE_NEW);
                        searchBallMult.z = 30.0f;
                        Matrix_MultVec3f(&searchBallMult, &searchBallVel);
                        Matrix_Pop();

                        EffectSsSolderSrchBall_Spawn(globalCtx, &searchBallPos, &searchBallVel, &searchBallAccel, 2,
                                                     &pthis->linkDetected);

                        if (pthis->actor.xzDistToPlayer < 60.0f) {
                            pthis->linkDetected = true;
                        } else if (pthis->actor.xzDistToPlayer < 70.0f) {
                            // pthis case probably exists to detect link making a jump sound
                            // from slightly further away than the previous 60 unit check
                            if (player->actor.velocity.y > -4.0f) {
                                pthis->linkDetected = true;
                            }
                        }

                        if (pthis->linkDetected) {
                            //! @bug This appears to be a check to make sure that link is standing on the ground
                            // before getting caught. However pthis is an issue for two reasons:
                            // 1: When doing a backflip or falling from the upper path, links y velocity will reach
                            // less than -4.0 before even touching the ground.
                            // 2: There is one frame when landing from a sidehop where you can sidehop again without
                            // letting y velocity reach -4.0 or less. This enables the player to do frame perfect
                            // sidehops onto the next screen and prevent getting caught.
                            if (!(player->actor.velocity.y > -3.9f)) {
                                pthis->linkDetected = false;
                                // pthis 60 unit height check is so the player doesnt get caught when on the upper path
                                if (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 60.0f) {
                                    func_80078884(NA_SE_SY_FOUND);
                                    // "Discovered!"
                                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発見！ ☆☆☆☆☆ \n" VT_RST);
                                    func_8002DF54(globalCtx, &pthis->actor, 1);
                                    sPlayerIsCaught = true;
                                    pthis->actionFunc = EnHeishi1_SetupMoveToLink;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

s32 EnHeishi1_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    EnHeishi1* pthis = (EnHeishi1*)thisx;

    // turn the guards head to match the direction he is looking
    if (limbIndex == 16) {
        rot->x += (s16)pthis->headAngle;
    }

    return false;
}

void EnHeishi1_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHeishi1* pthis = (EnHeishi1*)thisx;
    Vec3f matrixScale = { 0.3f, 0.3f, 0.3f };

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHeishi1_OverrideLimbDraw, NULL,
                      pthis);
    func_80033C30(&pthis->actor.world.pos, &matrixScale, 0xFF, globalCtx);
}

void EnHeishi1_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sPlayerIsCaught = false;

    En_Heishi1_InitVars = {
        0,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_SD,
        sizeof(EnHeishi1),
        (ActorFunc)EnHeishi1_Init,
        (ActorFunc)EnHeishi1_Destroy,
        (ActorFunc)EnHeishi1_Update,
        (ActorFunc)EnHeishi1_Draw,
        (ActorFunc)EnHeishi1_Reset,
    };

}

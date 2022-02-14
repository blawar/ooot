#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_NB_Z_EN_NB_C
#include "actor_common.h"
/*
 * File: z_en_nb.c
 * Overlay: ovl_En_Nb
 * Description: Nabooru
 */

#include "z_en_nb.h"
#include "vt.h"
#include "objects/object_nb/object_nb.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

typedef enum {
    /* 0x00 */ NB_CHAMBER_INIT,
    /* 0x01 */ NB_CHAMBER_UNDERGROUND,
    /* 0x02 */ NB_CHAMBER_APPEAR,
    /* 0x03 */ NB_CHAMBER_IDLE,
    /* 0x04 */ NB_CHAMBER_RAISE_ARM,
    /* 0x05 */ NB_CHAMBER_RAISE_ARM_TRANSITION,
    /* 0x06 */ NB_GIVE_MEDALLION,
    /* 0x07 */ NB_ACTION_7,
    /* 0x08 */ NB_SEAL_HIDE,
    /* 0x09 */ NB_ACTION_9,
    /* 0x0A */ NB_KIDNAPPED,
    /* 0x0B */ NB_KIDNAPPED_LOOK_AROUND,
    /* 0x0C */ NB_PORTAL_FALLTHROUGH,
    /* 0x0D */ NB_IN_CONFRONTATION,
    /* 0x0E */ NB_ACTION_14,
    /* 0x0F */ NB_KNEEL,
    /* 0x10 */ NB_LOOK_RIGHT,
    /* 0x11 */ NB_LOOK_LEFT,
    /* 0x12 */ NB_RUN,
    /* 0x13 */ NB_CONFRONTATION_DESTROYED,
    /* 0x14 */ NB_CREDITS_INIT,
    /* 0x15 */ NB_CREDITS_FADEIN,
    /* 0x16 */ NB_CREDITS_SIT,
    /* 0x17 */ NB_CREDITS_HEAD_TURN,
    /* 0x18 */ NB_CROUCH_CRAWLSPACE,
    /* 0x19 */ NB_NOTICE_PLAYER,
    /* 0x1A */ NB_IDLE_CRAWLSPACE,
    /* 0x1B */ NB_IN_DIALOG,
    /* 0x1C */ NB_IN_PATH,
    /* 0x1D */ NB_IDLE_AFTER_TALK,
    /* 0x1E */ NB_ACTION_30
} EnNbAction;

typedef enum {
    /* 0x00 */ NB_DRAW_NOTHING,
    /* 0x01 */ NB_DRAW_DEFAULT,
    /* 0x02 */ NB_DRAW_HIDE,
    /* 0x03 */ NB_DRAW_KNEEL,
    /* 0x04 */ NB_DRAW_LOOK_DIRECTION
} EnNbDrawMode;

void EnNb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnNb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnNb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnNb_Draw(Actor* thisx, GlobalContext* globalCtx);

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
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
    { 25, 80, 0, { 0, 0, 0 } },
};

static void* sEyeTextures[] = {
    gNabooruEyeOpenTex,
    gNabooruEyeHalfTex,
    gNabooruEyeClosedTex,
};

static s32 D_80AB4318 = 0;

#include "z_en_nb_cutscene_data.cpp" EARLY

s32 EnNb_GetPath(EnNb* pthis) {
    s32 path = pthis->actor.params >> 8;

    return path & 0xFF;
}

s32 EnNb_GetType(EnNb* pthis) {
    s32 type = pthis->actor.params;

    return type & 0xFF;
}

void EnNb_UpdatePath(EnNb* pthis, GlobalContext* globalCtx) {
    Vec3s* pointPos;
    Path* pathList;
    s32 pad;
    s32 path;

    pathList = globalCtx->setupPathList;

    if (pathList != NULL) {
        path = EnNb_GetPath(pthis);
        pathList += path;
        pointPos = SEGMENTED_TO_VIRTUAL(pathList->points);
        pthis->initialPos.x = pointPos[0].x;
        pthis->initialPos.y = pointPos[0].y;
        pthis->initialPos.z = pointPos[0].z;
        pthis->finalPos.x = pointPos[1].x;
        pthis->finalPos.y = pointPos[1].y;
        pthis->finalPos.z = pointPos[1].z;
        pthis->pathYaw = (Math_FAtan2F(pthis->finalPos.x - pthis->initialPos.x, pthis->finalPos.z - pthis->initialPos.z) *
                         (0x8000 / M_PI));
        // "En_Nb_Get_path_info Rail Data Get! = %d!!!!!!!!!!!!!!"
        osSyncPrintf("En_Nb_Get_path_info レールデータをゲットだぜ = %d!!!!!!!!!!!!!!\n", path);
    } else {
        // "En_Nb_Get_path_info Rail Data Doesn't Exist!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf("En_Nb_Get_path_info レールデータが無い!!!!!!!!!!!!!!!!!!!!\n");
    }
}

void EnNb_SetupCollider(Actor* thisx, GlobalContext* globalCtx) {
    EnNb* pthis = (EnNb*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, thisx, &sCylinderInit);
}

void EnNb_UpdateCollider(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad[4];
    ColliderCylinder* collider = &pthis->collider;

    Collider_UpdateCylinder(&pthis->actor, collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &collider->base);
}

void EnNb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnNb* pthis = (EnNb*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AB0FBC(EnNb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_300.unk_18 = player->actor.world.pos;
    pthis->unk_300.unk_14 = kREG(16) + 9.0f;
    func_80034A14(&pthis->actor, &pthis->unk_300, kREG(17) + 0xC, 2);
}

void func_80AB1040(EnNb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_300.unk_18 = player->actor.world.pos;
    pthis->unk_300.unk_14 = kREG(16) + 9.0f;
    func_80034A14(&pthis->actor, &pthis->unk_300, kREG(17) + 0xC, 4);
}

void func_80AB10C4(EnNb* pthis) {
    s32 pad2[2];
    Vec3s* tempPtr;
    Vec3s* tempPtr2;

    tempPtr = &pthis->unk_300.unk_08;
    Math_SmoothStepToS(&tempPtr->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&tempPtr->y, 0, 20, 6200, 100);
    tempPtr2 = &pthis->unk_300.unk_0E;
    Math_SmoothStepToS(&tempPtr2->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&tempPtr2->y, 0, 20, 6200, 100);
}

void EnNb_UpdateEyes(EnNb* pthis) {
    s32 pad[3];
    s16* blinkTimer = &pthis->blinkTimer;
    s16* eyeIdx = &pthis->eyeIdx;

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(60, 60);
    }

    *eyeIdx = *blinkTimer;
    if (*eyeIdx >= ARRAY_COUNT(sEyeTextures)) {
        *eyeIdx = 0;
    }
}

void func_80AB11EC(EnNb* pthis) {
    pthis->action = NB_ACTION_7;
    pthis->drawMode = NB_DRAW_NOTHING;
    pthis->alpha = 0;
    pthis->flag = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->alphaTimer = 0.0f;
}

void func_80AB1210(EnNb* pthis, GlobalContext* globalCtx) {
    s32 one; // required to match

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        if (D_80AB4318) {
            if (pthis->actor.params == NB_TYPE_DEMO02) {
                func_80AB11EC(pthis);
            }

            D_80AB4318 = 0;
        }
    } else {
        one = 1;
        if (!D_80AB4318) {
            D_80AB4318 = one;
        }
    }
}

void func_80AB1284(EnNb* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 4);
}

s32 EnNb_UpdateSkelAnime(EnNb* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

CsCmdActorAction* EnNb_GetNpcCsAction(GlobalContext* globalCtx, s32 npcActionIdx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[npcActionIdx];
    }
    return NULL;
}

void EnNb_SetupCsPosRot(EnNb* pthis, GlobalContext* globalCtx, s32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, npcActionIdx);
    s16 newRotY;
    Actor* thisx = &pthis->actor;

    if (csCmdNPCAction != NULL) {
        thisx->world.pos.x = csCmdNPCAction->startPos.x;
        thisx->world.pos.y = csCmdNPCAction->startPos.y;
        thisx->world.pos.z = csCmdNPCAction->startPos.z;
        thisx->world.rot.y = thisx->shape.rot.y = csCmdNPCAction->rot.y;
    }
}

s32 func_80AB1390(EnNb* pthis, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction;

    if ((globalCtx->csCtx.state != CS_STATE_IDLE) &&
        (csCmdNPCAction = globalCtx->csCtx.npcActions[npcActionIdx], csCmdNPCAction != NULL) &&
        (csCmdNPCAction->action == arg2)) {
        return true;
    }
    return false;
}

s32 func_80AB13D8(EnNb* pthis, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction;

    if ((globalCtx->csCtx.state != CS_STATE_IDLE) &&
        (csCmdNPCAction = globalCtx->csCtx.npcActions[npcActionIdx], csCmdNPCAction != NULL) &&
        (csCmdNPCAction->action != arg2)) {
        return true;
    }
    return false;
}

void EnNb_SetInitialCsPosRot(EnNb* pthis, GlobalContext* globalCtx, s32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, npcActionIdx);
    Actor* thisx = &pthis->actor;

    if (csCmdNPCAction != NULL) {
        thisx->world.pos.x = csCmdNPCAction->startPos.x;
        thisx->world.pos.y = csCmdNPCAction->startPos.y;
        thisx->world.pos.z = csCmdNPCAction->startPos.z;
        thisx->world.rot.y = thisx->shape.rot.y = csCmdNPCAction->rot.y;
    }
}

void EnNb_SetCurrentAnim(EnNb* pthis, AnimationHeader* animation, u8 mode, f32 transitionRate, s32 arg4) {
    f32 frameCount = Animation_GetLastFrame(animation);
    f32 playbackSpeed;
    f32 unk0;
    f32 fc;

    if (!arg4) {
        unk0 = 0.0f;
        fc = frameCount;
        playbackSpeed = 1.0f;
    } else {
        unk0 = frameCount;
        fc = 0.0f;
        playbackSpeed = -1.0f;
    }

    Animation_Change(&pthis->skelAnime, animation, playbackSpeed, unk0, fc, mode, transitionRate);
}

void EnNb_SetChamberAnim(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetCurrentAnim(pthis, &gNabooruStandingHandsOnHipsChamberOfSagesAnim, 0, 0, 0);
    pthis->actor.shape.yOffset = -10000.0f;
}

void EnNb_SpawnBlueWarp(EnNb* pthis, GlobalContext* globalCtx) {
    f32 posX = pthis->actor.world.pos.x;
    f32 posY = pthis->actor.world.pos.y;
    f32 posZ = pthis->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, posX, posY, posZ, 0, 0, 0,
                       WARP_SAGES);
}

void EnNb_GiveMedallion(EnNb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 posX = player->actor.world.pos.x;
    f32 posY = player->actor.world.pos.y + 50.0f;
    f32 posZ = player->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_EFFECT, posX, posY, posZ, 0, 0, 0,
                       0xC);
    Item_Give(globalCtx, ITEM_MEDALLION_SPIRIT);
}

void EnNb_ComeUpImpl(EnNb* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.yOffset += 250.0f / 3.0f;
}

void EnNb_SetupChamberCsImpl(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Player* player;

    if ((gSaveContext.chamberCutsceneNum == 3) && (gSaveContext.sceneSetupIndex < 4)) {
        player = GET_PLAYER(globalCtx);
        pthis->action = NB_CHAMBER_UNDERGROUND;
        globalCtx->csCtx.segment = &D_80AB431C;
        gSaveContext.cutsceneTrigger = 2;
        Item_Give(globalCtx, ITEM_MEDALLION_SPIRIT);
        player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    }
}

void EnNb_SetupChamberWarpImpl(EnNb* pthis, GlobalContext* globalCtx) {
    CutsceneContext* csCtx = &globalCtx->csCtx;
    CsCmdActorAction* csCmdNPCAction;

    if (csCtx->state != CS_STATE_IDLE) {
        csCmdNPCAction = csCtx->npcActions[1];
        if (csCmdNPCAction != NULL && csCmdNPCAction->action == 2) {
            pthis->action = NB_CHAMBER_APPEAR;
            pthis->drawMode = NB_DRAW_DEFAULT;
            EnNb_SpawnBlueWarp(pthis, globalCtx);
        }
    }
}

void EnNb_SetupDefaultChamberIdle(EnNb* pthis) {
    if (pthis->actor.shape.yOffset >= 0.0f) {
        pthis->action = NB_CHAMBER_IDLE;
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void EnNb_SetupArmRaise(EnNb* pthis, GlobalContext* globalCtx) {
    AnimationHeader* animation = &gNabooruRaisingArmsGivingMedallionAnim;
    CsCmdActorAction* csCmdNPCAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        csCmdNPCAction = globalCtx->csCtx.npcActions[1];
        if (csCmdNPCAction != NULL && csCmdNPCAction->action == 3) {
            Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_ONCE,
                             0.0f);
            pthis->action = NB_CHAMBER_RAISE_ARM;
        }
    }
}

void EnNb_SetupRaisedArmTransition(EnNb* pthis, s32 animFinished) {
    AnimationHeader* animation = &gNabooruArmsRaisedGivingMedallionAnim;

    if (animFinished) {
        Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP,
                         0.0f);
        pthis->action = NB_CHAMBER_RAISE_ARM_TRANSITION;
    }
}

void EnNb_SetupMedallion(EnNb* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        csCmdNPCAction = globalCtx->csCtx.npcActions[6];
        if (csCmdNPCAction != NULL && csCmdNPCAction->action == 2) {
            pthis->action = NB_GIVE_MEDALLION;
            EnNb_GiveMedallion(pthis, globalCtx);
        }
    }
}

// Action func is never explicitly set to pthis, but it runs when the memory gets zero cleared
void EnNb_SetupChamberCs(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetupChamberCsImpl(pthis, globalCtx);
}

void EnNb_SetupChamberWarp(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetupChamberWarpImpl(pthis, globalCtx);
}

void EnNb_ComeUp(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_ComeUpImpl(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupDefaultChamberIdle(pthis);
}

void func_80AB193C(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupArmRaise(pthis, globalCtx);
}

void EnNb_RaiseArm(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    func_80AB1284(pthis, globalCtx);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupRaisedArmTransition(pthis, animFinished);
}

void func_80AB19BC(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupMedallion(pthis, globalCtx);
}

void func_80AB19FC(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
}

void EnNb_SetupLightArrowOrSealingCs(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetCurrentAnim(pthis, &gNabooruPuttingHandsTogetherCastingMagicAnim, 2, 0.0f, 0);
    pthis->action = NB_ACTION_7;
    pthis->actor.shape.shadowAlpha = 0;
}

void EnNb_PlaySealingSound(void) {
    func_800788CC(NA_SE_SY_WHITE_OUT_T);
}

void EnNb_InitializeDemo6K(EnNb* pthis, GlobalContext* globalCtx) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                       kREG(21) + 22.0f + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 7);
}

void EnNb_SetupHide(EnNb* pthis, GlobalContext* globalCtx) {
    if (func_80AB1390(pthis, globalCtx, 4, 1)) {
        pthis->action = NB_SEAL_HIDE;
        pthis->drawMode = NB_DRAW_HIDE;
        pthis->alpha = 0;
        pthis->actor.shape.shadowAlpha = 0;
        pthis->alphaTimer = 0.0f;
        EnNb_PlaySealingSound();
    }
}

void EnNb_CheckToFade(EnNb* pthis, GlobalContext* globalCtx) {
    f32* alphaTimer = &pthis->alphaTimer;
    s32 alpha;

    if (func_80AB1390(pthis, globalCtx, 4, 1)) {
        *alphaTimer += 1.0f;
        if (*alphaTimer >= kREG(5) + 10.0f) {
            pthis->action = NB_ACTION_9;
            pthis->drawMode = NB_DRAW_DEFAULT;
            *alphaTimer = kREG(5) + 10.0f;
            pthis->alpha = 255;
            pthis->actor.shape.shadowAlpha = 0xFF;
            return;
        }
    } else {
        *alphaTimer -= 1.0f;
        if (*alphaTimer <= 0.0f) {
            pthis->action = NB_ACTION_7;
            pthis->drawMode = NB_DRAW_NOTHING;
            *alphaTimer = 0.0f;
            pthis->alpha = 0;
            pthis->actor.shape.shadowAlpha = 0;
            return;
        }
    }

    alpha = (*alphaTimer / (kREG(5) + 10.0f)) * 255.0f;
    pthis->alpha = alpha;
    pthis->actor.shape.shadowAlpha = alpha;
}

void EnNb_SetupLightOrb(EnNb* pthis, GlobalContext* globalCtx) {
    if (func_80AB13D8(pthis, globalCtx, 4, 1)) {
        pthis->action = NB_SEAL_HIDE;
        pthis->drawMode = NB_DRAW_HIDE;
        pthis->alphaTimer = kREG(5) + 10.0f;
        pthis->alpha = 255;

        if (pthis->flag == 0) {
            EnNb_InitializeDemo6K(pthis, globalCtx);
            pthis->flag = 1;
        }

        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void EnNb_Hide(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetupHide(pthis, globalCtx);
    func_80AB1210(pthis, globalCtx);
}

void EnNb_Fade(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_CheckToFade(pthis, globalCtx);
    func_80AB1210(pthis, globalCtx);
}

void EnNb_CreateLightOrb(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupLightOrb(pthis, globalCtx);
    func_80AB1210(pthis, globalCtx);
}

void EnNb_DrawTransparency(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeSegIdx = pthis->eyeIdx;
    void* eyeTex = sEyeTextures[eyeSegIdx];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inKenjyanomaDemo02.c", 263);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTex));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
    gSPSegment(POLY_XLU_DISP++, 0x0C, &D_80116280[0]);
    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       NULL, NULL, NULL, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inKenjyanomaDemo02.c", 290);
}

void EnNb_InitKidnap(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetCurrentAnim(pthis, &gNabooruTrappedInVortexPushingGroundAnim, 0, 0.0f, 0);
    pthis->action = NB_KIDNAPPED;
    pthis->actor.shape.shadowAlpha = 0;
    gSaveContext.eventChkInf[9] |= 0x20;
}

void EnNb_PlayCrySFX(EnNb* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.frames == 3) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_VO_NB_CRY_0);
    }
}

void EnNb_PlayAgonySFX(EnNb* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.frames == 420) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_VO_NB_AGONY);
    }
}

void EnNb_SetPosInPortal(EnNb* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, 1);
    Vec3f* pos = &pthis->actor.world.pos;
    f32 f0;
    s32 pad;
    Vec3f startPos;
    Vec3f endPos;

    if (csCmdNPCAction != NULL) {
	    f0	       = Environment_LerpWeightAccelDecel(csCmdNPCAction->endFrame, csCmdNPCAction->startFrame, globalCtx->csCtx.frames, 4, 4);
        startPos.x = csCmdNPCAction->startPos.x;
        startPos.y = csCmdNPCAction->startPos.y;
        startPos.z = csCmdNPCAction->startPos.z;
        endPos.x = csCmdNPCAction->endPos.x;
        endPos.y = csCmdNPCAction->endPos.y;
        endPos.z = csCmdNPCAction->endPos.z;
        pos->x = ((endPos.x - startPos.x) * f0) + startPos.x;
        pos->y = ((endPos.y - startPos.y) * f0) + startPos.y;
        pos->z = ((endPos.z - startPos.z) * f0) + startPos.z;
    }
}

void EnNb_SetupCaptureCutsceneState(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetupCsPosRot(pthis, globalCtx, 1);
    pthis->action = NB_KIDNAPPED;
    pthis->drawMode = NB_DRAW_NOTHING;
    pthis->actor.shape.shadowAlpha = 0;
}

void EnNb_SetRaisedArmCaptureAnim(EnNb* pthis, s32 animFinished) {
    AnimationHeader* animation = &gNabooruSuckedByVortexAnim;

    if (animFinished) {
        Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP,
                         0.0f);
    }
}

void EnNb_SetupLookAroundInKidnap(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruTrappedInVortexPushingGroundAnim;

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP, -8.0f);
    pthis->action = NB_KIDNAPPED_LOOK_AROUND;
    pthis->drawMode = NB_DRAW_DEFAULT;
}

void EnNb_SetupKidnap(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruTrappedInVortexRaisingArmAnim;

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_ONCE, -8.0f);
    pthis->action = NB_PORTAL_FALLTHROUGH;
    pthis->drawMode = NB_DRAW_DEFAULT;
}

void EnNb_CheckKidnapCsMode(EnNb* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, 1);
    s32 action;
    s32 previousCsAction;

    if (csCmdNPCAction != NULL) {
        action = csCmdNPCAction->action;
        previousCsAction = pthis->previousCsAction;
        if (action != previousCsAction) {
            switch (action) {
                case 1:
                    EnNb_SetupCaptureCutsceneState(pthis, globalCtx);
                    break;
                case 7:
                    EnNb_SetupLookAroundInKidnap(pthis);
                    break;
                case 8:
                    EnNb_SetupKidnap(pthis);
                    break;
                case 9:
                    Actor_Kill(&pthis->actor);
                    break;
                default:
                    // "Operation Doesn't Exist!!!!!!!!"
                    osSyncPrintf("En_Nb_Kidnap_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            pthis->previousCsAction = action;
        }
    }
}

void func_80AB23A8(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_PlayCrySFX(pthis, globalCtx);
    EnNb_CheckKidnapCsMode(pthis, globalCtx);
}

void EnNb_MovingInPortal(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_PlayCrySFX(pthis, globalCtx);
    EnNb_PlayAgonySFX(pthis, globalCtx);
    EnNb_UpdateEyes(pthis);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_CheckKidnapCsMode(pthis, globalCtx);
}

void EnNb_SuckedInByPortal(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    EnNb_UpdateEyes(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_SetRaisedArmCaptureAnim(pthis, animFinished);
    EnNb_SetPosInPortal(pthis, globalCtx);
    EnNb_CheckKidnapCsMode(pthis, globalCtx);
}

void EnNb_SetupConfrontation(EnNb* pthis, GlobalContext* globalCtx) {
    AnimationHeader* animation = &gNabooruCollapseFromStandingToKneelingTransitionAnim;

    EnNb_SetCurrentAnim(pthis, animation, 0, 0.0f, 0);
    pthis->action = NB_IN_CONFRONTATION;
    pthis->actor.shape.shadowAlpha = 0;
}

void EnNb_PlayKnuckleDefeatSFX(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad[2];

    if (globalCtx->csCtx.frames == 548) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_VO_NB_CRY_0);
        func_80078914(&pthis->actor.projectedPos, NA_SE_EN_FANTOM_HIT_THUNDER);
    }
}

void EnNb_PlayKneelingOnGroundSFX(EnNb* pthis) {
    s32 pad[2];

    if ((pthis->skelAnime.mode == 2) &&
        (Animation_OnFrame(&pthis->skelAnime, 18.0f) || Animation_OnFrame(&pthis->skelAnime, 25.0f))) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_EV_HUMAN_BOUND);
    }
}

void EnNb_PlayLookRightSFX(EnNb* pthis) {
    s32 pad[2];

    if ((pthis->skelAnime.mode == 2) && Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_PL_WALK_CONCRETE);
    }
}

void EnNb_PlayLookLeftSFX(EnNb* pthis) {
    s32 pad[2];

    if (Animation_OnFrame(&pthis->skelAnime, 9.0f) || Animation_OnFrame(&pthis->skelAnime, 13.0f)) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_PL_WALK_CONCRETE);
    }
}

void EnNb_InitDemo6KInConfrontation(EnNb* pthis, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                kREG(21) + 22.0f + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0xB);
}

void func_80AB2688(EnNb* pthis, GlobalContext* globalCtx) {
    pthis->skelAnime.moveFlags |= 1;
    AnimationContext_SetMoveActor(globalCtx, &pthis->actor, &pthis->skelAnime, 1.0f);
}

void func_80AB26C8(EnNb* pthis) {
    pthis->action = NB_IN_CONFRONTATION;
    pthis->drawMode = NB_DRAW_NOTHING;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_80AB26DC(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    AnimationHeader* animation = &gNabooruCollapseFromStandingToKneelingTransitionAnim;
    f32 lastFrame = Animation_GetLastFrame(animation);

    EnNb_SetupCsPosRot(pthis, globalCtx, 1);
    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    pthis->action = NB_ACTION_14;
    pthis->drawMode = NB_DRAW_KNEEL;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void EnNb_SetupKneel(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruCollapseFromStandingToKneelingTransitionAnim;
    f32 lastFrame = Animation_GetLastFrame(animation);

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    pthis->action = NB_KNEEL;
    pthis->drawMode = NB_DRAW_KNEEL;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void EnNb_CheckIfKneeling(EnNb* pthis, s32 animFinished) {
    AnimationHeader* animation = &gNabooruOnAllFoursAnim;

    if (animFinished) {
        Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP,
                         0.0f);
        pthis->drawMode = NB_DRAW_KNEEL;
    }
}

void EnNb_SetupLookRight(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruOnAllFoursToOnOneKneeLookingRightTransitionAnim;
    f32 lastFrame = Animation_GetLastFrame(animation);

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -8.0f);
    pthis->action = NB_LOOK_RIGHT;
    pthis->drawMode = NB_DRAW_DEFAULT;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void EnNb_CheckIfLookingRight(EnNb* pthis, s32 animFinished) {
    AnimationHeader* animation = &gNabooruOnOneKneeLookingRightAnim;

    if (animFinished) {
        Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP,
                         0.0f);
        pthis->drawMode = NB_DRAW_LOOK_DIRECTION;
    }
}

void EnNb_SetupLookLeft(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruOnOneKneeTurningHeadRightToLeftTransitionAnim;
    f32 lastFrame = Animation_GetLastFrame(animation);

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -8.0f);
    pthis->action = NB_LOOK_LEFT;
    pthis->drawMode = NB_DRAW_LOOK_DIRECTION;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void EnNb_CheckIfLookLeft(EnNb* pthis, s32 animFinished) {
    AnimationHeader* animation = &gNabooruOnOneKneeLookingLeftAnim;

    if (animFinished) {
        Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_LOOP,
                         0.0f);
    }
}

void EnNb_SetupDemo6KInConfrontation(EnNb* pthis, GlobalContext* globalCtx, s32 animFinished) {
    if (!pthis->flag && animFinished) {
        EnNb_InitDemo6KInConfrontation(pthis, globalCtx);
        pthis->flag = 1;
    }
}

void EnNb_SetupRun(EnNb* pthis) {
    AnimationHeader* animation = &gNabooruKneeingToRunningToHitAnim;
    f32 lastFrame = Animation_GetLastFrame(animation);

    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, -8.0f);
    pthis->action = NB_RUN;
    pthis->drawMode = NB_DRAW_LOOK_DIRECTION;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void EnNb_SetupConfrontationDestroy(EnNb* pthis) {
    pthis->action = NB_CONFRONTATION_DESTROYED;
    pthis->drawMode = NB_DRAW_NOTHING;
    pthis->actor.shape.shadowAlpha = 0;
}

void EnNb_CheckConfrontationCsMode(EnNb* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction;
    s32 csAction;
    s32 previousCsAction;

    csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, 1);
    if (csCmdNPCAction != NULL) {
        csAction = csCmdNPCAction->action;
        previousCsAction = pthis->previousCsAction;

        if (csAction != previousCsAction) {
            switch (csAction) {
                case 1:
                    func_80AB26C8(pthis);
                    break;
                case 10:
                    func_80AB26DC(pthis, globalCtx);
                    break;
                case 11:
                    EnNb_SetupKneel(pthis);
                    break;
                case 12:
                    EnNb_SetupLookRight(pthis);
                    break;
                case 13:
                    EnNb_SetupLookLeft(pthis);
                    break;
                case 14:
                    EnNb_SetupRun(pthis);
                    break;
                case 9:
                    EnNb_SetupConfrontationDestroy(pthis);
                    break;
                default:
                    // "En_Nb_Confrontion_Check_DemoMode: Operation doesn't exist!!!!!!!!"
                    osSyncPrintf("En_Nb_Confrontion_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            pthis->previousCsAction = csAction;
        }
    }
}

void EnNb_CheckConfrontationCsModeWrapper(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void func_80AB2C18(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_UpdateEyes(pthis);
    func_80AB2688(pthis, globalCtx);
    func_80AB1284(pthis, globalCtx);
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void EnNb_Kneel(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    EnNb_UpdateEyes(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_CheckIfKneeling(pthis, animFinished);
    EnNb_PlayKneelingOnGroundSFX(pthis);
    func_80AB2688(pthis, globalCtx);
    func_80AB1284(pthis, globalCtx);
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void EnNb_LookRight(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    EnNb_UpdateEyes(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_CheckIfLookingRight(pthis, animFinished);
    EnNb_PlayLookRightSFX(pthis);
    func_80AB2688(pthis, globalCtx);
    func_80AB1284(pthis, globalCtx);
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void EnNb_LookLeft(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    EnNb_UpdateEyes(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_CheckIfLookLeft(pthis, animFinished);
    func_80AB2688(pthis, globalCtx);
    func_80AB1284(pthis, globalCtx);
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void EnNb_Run(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    EnNb_PlayKnuckleDefeatSFX(pthis, globalCtx);
    EnNb_UpdateEyes(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_PlayLookLeftSFX(pthis);
    func_80AB2688(pthis, globalCtx);
    func_80AB1284(pthis, globalCtx);
    EnNb_SetupDemo6KInConfrontation(pthis, globalCtx, animFinished);
    EnNb_CheckConfrontationCsMode(pthis, globalCtx);
}

void EnNb_ConfrontationDestroy(EnNb* pthis, GlobalContext* globalCtx) {
    pthis->timer++;

    if (pthis->timer > 60.0f) {
        Actor_Kill(&pthis->actor);
    }
}

void func_80AB2E70(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inConfrontion.c", 572);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gNabooruEyeWideTex));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gNabooruEyeWideTex));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount, NULL, NULL,
                          &pthis->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inConfrontion.c", 593);
}

s32 func_80AB2FC0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnNb* pthis = (EnNb*)thisx;

    if (limbIndex == NB_LIMB_HEAD) {
        *dList = gNabooruHeadMouthOpenDL;
    }

    return 0;
}

void func_80AB2FE4(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 eyeIdx = pthis->eyeIdx;
    SkelAnime* skelAnime = &pthis->skelAnime;
    void* eyeTexture = sEyeTextures[eyeIdx];
    s32 pad1;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inConfrontion.c", 623);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount, func_80AB2FC0,
                          NULL, &pthis->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_nb_inConfrontion.c", 644);
}

void EnNb_SetupCreditsSpawn(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetCurrentAnim(pthis, &gNabooruSittingCrossLeggedAnim, 0, 0.0f, 0);
    pthis->action = NB_CREDITS_INIT;
    pthis->drawMode = NB_DRAW_NOTHING;
    pthis->actor.shape.shadowAlpha = 0;
}

void EnNb_SetAlphaInCredits(EnNb* pthis) {
    f32* alphaTimer = &pthis->alphaTimer;
    s32 alpha;

    pthis->alphaTimer++;

    if ((kREG(17) + 10.0f) <= pthis->alphaTimer) {
        pthis->alpha = 255;
        pthis->actor.shape.shadowAlpha = 255;
    } else {
        alpha = (*alphaTimer / (kREG(17) + 10.0f)) * 255.0f;
        pthis->alpha = alpha;
        pthis->actor.shape.shadowAlpha = alpha;
    }
}

void EnNb_SetupCreditsFadeIn(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetInitialCsPosRot(pthis, globalCtx, 1);
    pthis->action = NB_CREDITS_FADEIN;
    pthis->drawMode = NB_DRAW_HIDE;
}

void EnNb_SetupCreditsSit(EnNb* pthis) {
    if (pthis->alphaTimer >= kREG(17) + 10.0f) {
        pthis->action = NB_CREDITS_SIT;
        pthis->drawMode = NB_DRAW_DEFAULT;
    }
}

void EnNb_SetupCreditsHeadTurn(EnNb* pthis) {
    EnNb_SetCurrentAnim(pthis, &gNabooruSittingCrossLeggedTurningToLookUpRightTransitionAnim, 2, -8.0f, 0);
    pthis->action = NB_CREDITS_HEAD_TURN;
}

void EnNb_CheckIfLookingUp(EnNb* pthis, s32 animFinished) {
    if (animFinished) {
        EnNb_SetCurrentAnim(pthis, &gNabooruSittingCrossLeggedLookingUpRightAnim, 0, 0.0f, 0);
    }
}

void EnNb_CheckCreditsCsModeImpl(EnNb* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdNPCAction = EnNb_GetNpcCsAction(globalCtx, 1);
    s32 action;
    s32 previousCsAction;

    if (csCmdNPCAction != NULL) {
        action = csCmdNPCAction->action;
        previousCsAction = pthis->previousCsAction;
        if (action != previousCsAction) {
            switch (action) {
                case 15:
                    EnNb_SetupCreditsFadeIn(pthis, globalCtx);
                    break;
                case 16:
                    EnNb_SetupCreditsHeadTurn(pthis);
                    break;
                default:
                    // "En_Nb_inEnding_Check_DemoMode: Operation doesn't exist!!!!!!!!"
                    osSyncPrintf("En_Nb_inEnding_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            pthis->previousCsAction = action;
        }
    }
}

void EnNb_CheckCreditsCsMode(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_CheckCreditsCsModeImpl(pthis, globalCtx);
}

void EnNb_CreditsFade(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetAlphaInCredits(pthis);
    EnNb_SetupCreditsSit(pthis);
}

void func_80AB3428(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_CheckCreditsCsModeImpl(pthis, globalCtx);
}

void EnNb_LookUp(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    func_80AB1284(pthis, globalCtx);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_CheckIfLookingUp(pthis, animFinished);
}

void EnNb_CrawlspaceSpawnCheck(EnNb* pthis, GlobalContext* globalCtx) {
    if (!(gSaveContext.eventChkInf[9] & 0x20) && LINK_IS_CHILD) {
        EnNb_UpdatePath(pthis, globalCtx);

        // looking into crawlspace
        if (!(gSaveContext.eventChkInf[9] & 0x10)) {
            EnNb_SetCurrentAnim(pthis, &gNabooruKneeingAtCrawlspaceAnim, 0, 0.0f, 0);
            pthis->action = NB_CROUCH_CRAWLSPACE;
            pthis->drawMode = NB_DRAW_DEFAULT;
        } else {
            EnNb_SetCurrentAnim(pthis, &gNabooruStandingHandsOnHipsAnim, 0, 0.0f, 0);
            pthis->headTurnFlag = 1;
            pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
            pthis->actor.world.pos = pthis->finalPos;
            pthis->action = NB_IDLE_AFTER_TALK;
            pthis->drawMode = NB_DRAW_DEFAULT;
        }
    } else {
        Actor_Kill(&pthis->actor);
    }
}

void func_80AB359C(EnNb* pthis) {
    PosRot* world = &pthis->actor.world;
    Vec3f* initialPos = &pthis->initialPos;
    Vec3f* finalPos = &pthis->finalPos;
    f32 f0;
    u16 temp_t1;
    s16 temp_2;

    pthis->movementTimer++;
    temp_2 = kREG(17);
    temp_t1 = temp_2;
    temp_t1 += 25;

    if (temp_t1 >= pthis->movementTimer) {
        f0 = Environment_LerpWeightAccelDecel(temp_t1, 0, pthis->movementTimer, 3, 3);
        world->pos.x = initialPos->x + (f0 * (finalPos->x - initialPos->x));
        world->pos.y = initialPos->y + (f0 * (finalPos->y - initialPos->y));
        world->pos.z = initialPos->z + (f0 * (finalPos->z - initialPos->z));
    }
}

void EnNb_SetNoticeSFX(EnNb* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_VO_NB_NOTICE);
}

s32 EnNb_GetNoticedStatus(EnNb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerX = player->actor.world.pos.x;
    f32 playerZ = player->actor.world.pos.z;
    f32 thisX = pthis->actor.world.pos.x;
    f32 thisZ = pthis->actor.world.pos.z;

    if (SQ(playerX - thisX) + SQ(playerZ - thisZ) < SQ(80.0f)) {
        return true;
    } else {
        return false;
    }
}

void func_80AB36DC(EnNb* pthis, GlobalContext* globalCtx) {
    u16 moveTime = pthis->movementTimer;

    if ((((u16)((u16)(kREG(17) + 25) - 4))) > moveTime) {
        s16 invScale = 4 - moveTime;

        if (invScale > 0) {
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->pathYaw, invScale, 6200, 100);
        }
    } else {
        s16 invScale = (u16)(kREG(17) + 25) - moveTime;

        if (invScale > 0) {
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, invScale, 6200, 100);
        }
    }
}

void EnNb_CheckNoticed(EnNb* pthis, GlobalContext* globalCtx) {
    if (EnNb_GetNoticedStatus(pthis, globalCtx)) {
        EnNb_SetCurrentAnim(pthis, &gNabooruStandingToWalkingTransitionAnim, 2, -8.0f, 0);
        pthis->action = NB_NOTICE_PLAYER;
        EnNb_SetNoticeSFX(pthis);
    }
}

void EnNb_SetupIdleCrawlspace(EnNb* pthis, s32 animFinished) {
    if (animFinished) {
        EnNb_SetCurrentAnim(pthis, &gNabooruStandingHandsOnHipsAnim, 0, -8.0f, 0);
        pthis->headTurnFlag = 1;
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        pthis->action = NB_IDLE_CRAWLSPACE;
    }
}

void func_80AB3838(EnNb* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->action = NB_IN_DIALOG;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;

        if (!(gSaveContext.infTable[22] & 0x1000)) {
            pthis->actor.textId = 0x601D;
        } else {
            pthis->actor.textId = 0x6024;
        }

        func_8002F2F4(&pthis->actor, globalCtx);
    }
}

void EnNb_SetupPathMovement(EnNb* pthis, GlobalContext* globalCtx) {
    EnNb_SetCurrentAnim(pthis, &gNabooruStandingToWalkingTransitionAnim, 2, -8.0f, 0);
    gSaveContext.eventChkInf[9] |= 0x10;
    pthis->action = NB_IN_PATH;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
}

void EnNb_SetTextIdAsChild(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    u8 choiceIndex;
    s32 pad1;
    u16 textId;

    textId = pthis->actor.textId;

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        if (textId == 0x6025) {
            EnNb_SetupPathMovement(pthis, globalCtx);
        } else {
            if (textId == 0x6027) {
                gSaveContext.infTable[22] |= 0x1000;
            }
            pthis->action = NB_IDLE_CRAWLSPACE;
        }
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
    } else if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        choiceIndex = globalCtx->msgCtx.choiceIndex;

        if (textId == 0x601D) {
            switch (choiceIndex) {
                case 0:
                    pthis->actor.textId = 0x601E;
                    break;
                case 1:
                    pthis->actor.textId = 0x601F;
                    break;
                default:
                    pthis->actor.textId = 0x6020;
            }
        } else if (textId == 0x6020) {
            switch (choiceIndex) {
                case 0:
                    pthis->actor.textId = 0x6021;
                    break;
                default:
                    pthis->actor.textId = 0x6022;
                    break;
            }
        } else {
            switch (choiceIndex) {
                case 0:
                    pthis->actor.textId = 0x6025;
                    break;
                default:
                    pthis->actor.textId = 0x6027;
                    break;
            }
        }

        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
    }
}

void func_80AB3A7C(EnNb* pthis, GlobalContext* globalCtx, s32 animFinished) {
    u16 movementTimer = pthis->movementTimer;

    if ((u16)(kREG(17) + 25) > movementTimer) {
        if (animFinished) {
            EnNb_SetCurrentAnim(pthis, &gNabooruWalkingAnim, 0, 0.0f, 0);
        }
    } else {
        EnNb_SetCurrentAnim(pthis, &gNabooruStandingHandsOnHipsAnim, 0, -8.0f, 0);
        pthis->action = NB_IDLE_AFTER_TALK;
    }
}

void func_80AB3B04(EnNb* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->action = NB_ACTION_30;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        pthis->actor.textId = Text_GetFaceReaction(globalCtx, 0x23);

        if ((pthis->actor.textId) == 0) {
            pthis->actor.textId = 0x6026;
        }

        func_8002F2F4(&pthis->actor, globalCtx);
    }
}

void func_80AB3B7C(EnNb* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->action = NB_IDLE_AFTER_TALK;
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
    }
}

void EnNb_WaitForNotice(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_CheckNoticed(pthis, globalCtx);
}

void EnNb_StandUpAfterNotice(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetupIdleCrawlspace(pthis, animFinished);
}

void EnNb_BlockCrawlspace(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    func_80AB0FBC(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    func_80AB3838(pthis, globalCtx);
}

void EnNb_InitCrawlspaceDialogue(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    func_80AB0FBC(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    EnNb_SetTextIdAsChild(pthis, globalCtx);
}

void EnNb_FollowPath(EnNb* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    func_80AB359C(pthis);
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    func_80AB36DC(pthis, globalCtx);
    func_80AB10C4(pthis);
    animFinished = EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    func_80AB3A7C(pthis, globalCtx, animFinished);
}

void func_80AB3DB0(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    func_80AB0FBC(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    func_80AB3B04(pthis, globalCtx);
}

void func_80AB3E10(EnNb* pthis, GlobalContext* globalCtx) {
    func_80AB1284(pthis, globalCtx);
    EnNb_UpdateCollider(pthis, globalCtx);
    func_80AB1040(pthis, globalCtx);
    EnNb_UpdateSkelAnime(pthis);
    EnNb_UpdateEyes(pthis);
    func_80AB3B7C(pthis, globalCtx);
}

static EnNbActionFunc sActionFuncs[] = {
    EnNb_SetupChamberCs,
    EnNb_SetupChamberWarp,
    EnNb_ComeUp,
    func_80AB193C,
    EnNb_RaiseArm,
    func_80AB19BC,
    func_80AB19FC,
    EnNb_Hide,
    EnNb_Fade,
    EnNb_CreateLightOrb,
    func_80AB23A8,
    EnNb_MovingInPortal,
    EnNb_SuckedInByPortal,
    EnNb_CheckConfrontationCsModeWrapper,
    func_80AB2C18,
    EnNb_Kneel,
    EnNb_LookRight,
    EnNb_LookLeft,
    EnNb_Run,
    EnNb_ConfrontationDestroy,
    EnNb_CheckCreditsCsMode,
    EnNb_CreditsFade,
    func_80AB3428,
    EnNb_LookUp,
    EnNb_WaitForNotice,
    EnNb_StandUpAfterNotice,
    EnNb_BlockCrawlspace,
    EnNb_InitCrawlspaceDialogue,
    EnNb_FollowPath,
    func_80AB3DB0,
    func_80AB3E10,
};

void EnNb_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnNb* pthis = (EnNb*)thisx;

    if (pthis->action < 0 || pthis->action > 30 || sActionFuncs[pthis->action] == NULL) {
        // "Main mode is wrong!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sActionFuncs[pthis->action](pthis, globalCtx);
}

void EnNb_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnNb* pthis = (EnNb*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    EnNb_SetupCollider(thisx, globalCtx);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gNabooruSkel, NULL, pthis->jointTable, pthis->morphTable,
                       NB_LIMB_MAX);

    switch (EnNb_GetType(pthis)) {
        case NB_TYPE_DEMO02:
            EnNb_SetupLightArrowOrSealingCs(pthis, globalCtx);
            break;
        case NB_TYPE_KIDNAPPED:
            EnNb_InitKidnap(pthis, globalCtx);
            break;
        case NB_TYPE_KNUCKLE:
            EnNb_SetupConfrontation(pthis, globalCtx);
            break;
        case NB_TYPE_CREDITS:
            EnNb_SetupCreditsSpawn(pthis, globalCtx);
            break;
        case NB_TYPE_CRAWLSPACE:
            EnNb_CrawlspaceSpawnCheck(pthis, globalCtx);
            break;
        default: // giving medallion
            EnNb_SetChamberAnim(pthis, globalCtx);
            break;
    }
}

s32 EnNb_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnNb* pthis = (EnNb*)thisx;
    struct_80034A14_arg1* unk_300 = &pthis->unk_300;
    s32 ret = false;

    if (pthis->headTurnFlag != 0) {
        if (limbIndex == NB_LIMB_TORSO) {
            rot->x += unk_300->unk_0E.y;
            rot->y -= unk_300->unk_0E.x;
            ret = false;
        } else if (limbIndex == NB_LIMB_HEAD) {
            rot->x += unk_300->unk_08.y;
            rot->z += unk_300->unk_08.x;
            ret = false;
        }
    }

    return ret;
}

void EnNb_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnNb* pthis = (EnNb*)thisx;

    if (limbIndex == NB_LIMB_HEAD) {
        Vec3f vec1 = { 0.0f, 10.0f, 0.0f };
        Vec3f vec2;

        Matrix_MultVec3f(&vec1, &vec2);
        pthis->actor.focus.pos.x = vec2.x;
        pthis->actor.focus.pos.y = vec2.y;
        pthis->actor.focus.pos.z = vec2.z;
        pthis->actor.focus.rot.x = pthis->actor.world.rot.x;
        pthis->actor.focus.rot.y = pthis->actor.world.rot.y;
        pthis->actor.focus.rot.z = pthis->actor.world.rot.z;
    }
}

void EnNb_DrawNothing(EnNb* pthis, GlobalContext* globalCtx) {
}

void EnNb_DrawDefault(EnNb* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 eyeIdx = pthis->eyeIdx;
    SkelAnime* skelAnime = &pthis->skelAnime;
    void* eyeTexture = sEyeTextures[eyeIdx];
    s32 pad1;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_nb.c", 992);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          EnNb_OverrideLimbDraw, EnNb_PostLimbDraw, &pthis->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_nb.c", 1013);
}

static EnNbDrawFunc sDrawFuncs[] = {
    EnNb_DrawNothing, EnNb_DrawDefault, EnNb_DrawTransparency, func_80AB2E70, func_80AB2FE4,
};

void EnNb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnNb* pthis = (EnNb*)thisx;

    if (pthis->drawMode < 0 || pthis->drawMode >= 5 || sDrawFuncs[pthis->drawMode] == NULL) {
        // "Draw mode is wrong!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sDrawFuncs[pthis->drawMode](pthis, globalCtx);
}

ActorInit En_Nb_InitVars = {
    ACTOR_EN_NB,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_NB,
    sizeof(EnNb),
    (ActorFunc)EnNb_Init,
    (ActorFunc)EnNb_Destroy,
    (ActorFunc)EnNb_Update,
    (ActorFunc)EnNb_Draw,
};

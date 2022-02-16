#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GE3_Z_EN_GE3_C
#include "actor_common.h"
/*
 * File: z_en_ge3.c
 * Overlay: ovl_En_Ge3
 * Description: Gerudo giving you membership card
 */

#include "z_en_ge3.h"
#include "objects/object_geldb/object_geldb.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnGe3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGe3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnGe3_WaitLookAtPlayer(EnGe3* pthis, GlobalContext* globalCtx);
void EnGe3_ForceTalk(EnGe3* pthis, GlobalContext* globalCtx);
void EnGe3_UpdateWhenNotTalking(Actor* thisx, GlobalContext* globalCtx);

static void* eyeTextures_44[] = {
    gGerudoRedEyeOpenTex,
    gGerudoRedEyeHalfTex,
    gGerudoRedEyeShutTex,
};


ActorInit En_Ge3_InitVars = {
    ACTOR_EN_GE3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GELDB,
    sizeof(EnGe3),
    (ActorFunc)EnGe3_Init,
    (ActorFunc)EnGe3_Destroy,
    (ActorFunc)EnGe3_Update,
    (ActorFunc)EnGe3_Draw,
    (ActorFunc)EnGe3_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000722, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 50, 0, { 0, 0, 0 } },
};

static EnGe3ActionFunc sActionFuncs[] = { EnGe3_WaitLookAtPlayer };
static AnimationHeader* sAnimations[] = { &gGerudoRedStandAnim }; // Idle with right hand on hip and left over mouth
static u8 sAnimationModes[] = { ANIMMODE_LOOP };

void EnGe3_ChangeAction(EnGe3* pthis, s32 i) {
    pthis->actionFunc = sActionFuncs[i];

    Animation_Change(&pthis->skelAnime, sAnimations[i], 1.0f, 0.0f, (f32)Animation_GetLastFrame(sAnimations[i]),
                     sAnimationModes[i], -8.0f);

    pthis->unk_30C &= ~2;
}

void EnGe3_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnGe3* pthis = (EnGe3*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGerudoRedSkel, NULL, pthis->jointTable, pthis->morphTable,
                       GELDB_LIMB_MAX);
    Animation_PlayLoop(&pthis->skelAnime, &gGerudoRedStandAnim);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.world.rot.z = 0;
    pthis->actor.shape.rot.z = 0;
    EnGe3_ChangeAction(pthis, 0);
    pthis->actionFunc = EnGe3_ForceTalk;
    pthis->unk_30C = 0;
    pthis->actor.targetMode = 6;
    pthis->actor.minVelocityY = -4.0f;
    pthis->actor.gravity = -1.0f;
}

void EnGe3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGe3* pthis = (EnGe3*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnGe3_TurnToFacePlayer(EnGe3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (ABS(angleDiff) <= 0x4000) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 6, 4000, 100);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->unk_306, pthis->actor.focus.pos);
    } else {
        if (angleDiff < 0) {
            Math_SmoothStepToS(&pthis->headRot.y, -0x2000, 6, 6200, 0x100);
        } else {
            Math_SmoothStepToS(&pthis->headRot.y, 0x2000, 6, 6200, 0x100);
        }

        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 12, 1000, 100);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    }
}

void EnGe3_LookAtPlayer(EnGe3* pthis, GlobalContext* globalCtx) {
    if ((ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x2300) &&
        (pthis->actor.xzDistToPlayer < 100.0f)) {
        func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->unk_306, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->headRot.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->headRot.y, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_306.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_306.y, 0, 6, 6200, 100);
    }
}

void EnGe3_Wait(EnGe3* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe3_WaitLookAtPlayer;
        pthis->actor.update = EnGe3_UpdateWhenNotTalking;
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
    EnGe3_TurnToFacePlayer(pthis, globalCtx);
}

void EnGe3_WaitLookAtPlayer(EnGe3* pthis, GlobalContext* globalCtx) {
    EnGe3_LookAtPlayer(pthis, globalCtx);
}

void EnGe3_WaitTillCardGiven(EnGe3* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnGe3_Wait;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_GERUDO_CARD, 10000.0f, 50.0f);
    }
}

void EnGe3_GiveCard(EnGe3* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->actionFunc = EnGe3_WaitTillCardGiven;
        func_8002F434(&pthis->actor, globalCtx, GI_GERUDO_CARD, 10000.0f, 50.0f);
    }
}

void EnGe3_ForceTalk(EnGe3* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe3_GiveCard;
    } else {
        if (!(pthis->unk_30C & 4)) {
            func_8002DF54(globalCtx, &pthis->actor, 7);
            pthis->unk_30C |= 4;
        }
        pthis->actor.textId = 0x6004;
        pthis->actor.flags |= ACTOR_FLAG_16;
        func_8002F1C4(&pthis->actor, globalCtx, 300.0f, 300.0f, 0);
    }
    EnGe3_LookAtPlayer(pthis, globalCtx);
}

void EnGe3_UpdateCollision(EnGe3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 40.0f, 25.0f, 40.0f, 5);

    if (!(pthis->unk_30C & 2) && SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_30C |= 2;
    }
}

void EnGe3_MoveAndBlink(EnGe3* pthis, GlobalContext* globalCtx) {

    Actor_MoveForward(&pthis->actor);

    if (DECR(pthis->blinkTimer) == 0) {
        pthis->blinkTimer = Rand_S16Offset(60, 60);
    }

    pthis->eyeIndex = pthis->blinkTimer;

    if (pthis->eyeIndex >= 3) {
        pthis->eyeIndex = 0;
    }
}

void EnGe3_UpdateWhenNotTalking(Actor* thisx, GlobalContext* globalCtx) {
    EnGe3* pthis = (EnGe3*)thisx;

    EnGe3_UpdateCollision(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe3_Wait;
        pthis->actor.update = EnGe3_Update;
    } else {
        pthis->actor.textId = 0x6005;
        if (pthis->actor.xzDistToPlayer < 100.0f) {
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
        }
    }

    EnGe3_MoveAndBlink(pthis, globalCtx);
}

void EnGe3_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGe3* pthis = (EnGe3*)thisx;

    EnGe3_UpdateCollision(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    EnGe3_MoveAndBlink(pthis, globalCtx);
}

s32 EnGe3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnGe3* pthis = (EnGe3*)thisx;

    switch (limbIndex) {
        // Hide swords and veil from object_geldb
        case GELDB_LIMB_VEIL:
        case GELDB_LIMB_R_SWORD:
        case GELDB_LIMB_L_SWORD:
            *dList = NULL;
            return false;
        // Turn head
        case GELDB_LIMB_HEAD:
            rot->x += pthis->headRot.y;

        // This is a hack to fix the color-changing clothes pthis Gerudo has on N64 versions
        default:
            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ge3.c", 547);
            switch (limbIndex) {
                case GELDB_LIMB_NECK:
                    break;
                case GELDB_LIMB_HEAD:
                    gDPPipeSync(POLY_OPA_DISP++);
                    gDPSetEnvColor(POLY_OPA_DISP++, 80, 60, 10, 255);
                    break;
                case GELDB_LIMB_R_SWORD:
                case GELDB_LIMB_L_SWORD:
                    gDPPipeSync(POLY_OPA_DISP++);
                    gDPSetEnvColor(POLY_OPA_DISP++, 140, 170, 230, 255);
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
                    break;
                default:
                    gDPPipeSync(POLY_OPA_DISP++);
                    gDPSetEnvColor(POLY_OPA_DISP++, 140, 0, 0, 255);
                    break;
            }
            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ge3.c", 566);
            break;
    }
    return false;
}

void EnGe3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnGe3* pthis = (EnGe3*)thisx;
    Vec3f D_80A351C8 = { 600.0f, 700.0f, 0.0f };

    if (limbIndex == GELDB_LIMB_HEAD) {
        Matrix_MultVec3f(&D_80A351C8, &pthis->actor.focus.pos);
    }
}

void EnGe3_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    EnGe3* pthis = (EnGe3*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ge3.c", 614);

    func_800943C8(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_44[pthis->eyeIndex]));
    func_8002EBCC(&pthis->actor, globalCtx, 0);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnGe3_OverrideLimbDraw, EnGe3_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ge3.c", 631);
}

void EnGe3_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ge3_InitVars = {
        ACTOR_EN_GE3,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_GELDB,
        sizeof(EnGe3),
        (ActorFunc)EnGe3_Init,
        (ActorFunc)EnGe3_Destroy,
        (ActorFunc)EnGe3_Update,
        (ActorFunc)EnGe3_Draw,
        (ActorFunc)EnGe3_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000722, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 50, 0, { 0, 0, 0 } },
    };

}

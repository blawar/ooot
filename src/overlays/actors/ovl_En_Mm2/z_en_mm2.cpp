#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MM2_Z_EN_MM2_C
#include "actor_common.h"
/*
 * File: z_en_mm.c
 * Overlay: ovl_En_Mm
 * Description: Running Man (adult)
 */

#include "z_en_mm2.h"
#include "vt.h"
#include "objects/object_mm/object_mm.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

typedef enum {
    /* 0 */ RM2_ANIM_RUN,
    /* 1 */ RM2_ANIM_SIT,
    /* 2 */ RM2_ANIM_SIT_WAIT,
    /* 3 */ RM2_ANIM_STAND,
    /* 4 */ RM2_ANIM_SPRINT,
    /* 5 */ RM2_ANIM_EXCITED, // plays when talking to him with bunny hood on
    /* 6 */ RM2_ANIM_HAPPY    // plays when you sell him the bunny hood
} RunningManAnimIndex;

typedef enum {
    /* 0 */ RM2_MOUTH_CLOSED,
    /* 1 */ RM2_MOUTH_OPEN
} RunningManMouthTex;

void EnMm2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80AAF3C0(EnMm2* pthis, GlobalContext* globalCtx);
void func_80AAF57C(EnMm2* pthis, GlobalContext* globalCtx);
void func_80AAF668(EnMm2* pthis, GlobalContext* globalCtx);
s32 EnMm2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx);
void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx);

ActorInit En_Mm2_InitVars = {
    ACTOR_EN_MM2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MM,
    sizeof(EnMm2),
    (ActorFunc)EnMm2_Init,
    (ActorFunc)EnMm2_Destroy,
    (ActorFunc)EnMm2_Update,
    (ActorFunc)EnMm2_Draw,
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
        { 0x00000004, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 18, 63, 0, { 0, 0, 0 } },
};

typedef struct {
    /* 0x00 */ AnimationHeader* animation;
    /* 0x04 */ f32 playSpeed;
    /* 0x08 */ u8 mode;
    /* 0x0C */ f32 morphFrames;
} EnMm2AnimEntry; // size = 0x10

static EnMm2AnimEntry sAnimationEntries[] = {
    { &gRunningManRunAnim, 1.0f, ANIMMODE_LOOP, -7.0f },     { &gRunningManSitStandAnim, -1.0f, ANIMMODE_ONCE, -7.0f },
    { &gRunningManSitWaitAnim, 1.0f, ANIMMODE_LOOP, -7.0f }, { &gRunningManSitStandAnim, 1.0f, ANIMMODE_ONCE, -7.0f },
    { &gRunningManSprintAnim, 1.0f, ANIMMODE_LOOP, -7.0f },  { &gRunningManExcitedAnim, 1.0f, ANIMMODE_LOOP, -12.0f },
    { &gRunningManHappyAnim, 1.0f, ANIMMODE_LOOP, -12.0f },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_STOP),
};

void EnMm2_ChangeAnimation(EnMm2* pthis, s32 animationIndex, s32* previousAnimation) {
    f32 phi_f0;

    if ((*previousAnimation < 0) || (animationIndex == *previousAnimation)) {
        phi_f0 = 0.0f;
    } else {
        phi_f0 = sAnimationEntries[animationIndex].morphFrames;
    }

    if (sAnimationEntries[animationIndex].playSpeed >= 0.0f) {
        Animation_Change(&pthis->skelAnime, sAnimationEntries[animationIndex].animation,
                         sAnimationEntries[animationIndex].playSpeed, 0.0f,
                         (f32)Animation_GetLastFrame(sAnimationEntries[animationIndex].animation),
                         sAnimationEntries[animationIndex].mode, phi_f0);
    } else {
        Animation_Change(&pthis->skelAnime, sAnimationEntries[animationIndex].animation,
                         sAnimationEntries[animationIndex].playSpeed,
                         (f32)Animation_GetLastFrame(sAnimationEntries[animationIndex].animation), 0.0f,
                         sAnimationEntries[animationIndex].mode, phi_f0);
    }
    *previousAnimation = animationIndex;
}

void func_80AAEF70(EnMm2* pthis, GlobalContext* globalCtx) {
    if ((gSaveContext.eventChkInf[9] & 0xF) != 0xF) {
        pthis->actor.textId = 0x6086;
    } else if (gSaveContext.infTable[23] & 0x8000) {
        if (gSaveContext.eventInf[1] & 1) {
            pthis->actor.textId = 0x6082;
        } else if (gSaveContext.timer2State != 0) {
            pthis->actor.textId = 0x6076;
        } else if (HIGH_SCORE(HS_MARATHON) == 158) {
            pthis->actor.textId = 0x607E;
        } else {
            pthis->actor.textId = 0x6081;
        }
    } else if (gSaveContext.timer2State) {
        pthis->actor.textId = 0x6076;
    } else {
        pthis->actor.textId = 0x607D;
        gSaveContext.eventInf[1] &= ~1;
        HIGH_SCORE(HS_MARATHON) = 158;
    }
}

void EnMm2_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnMm2* pthis = (EnMm2*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 21.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gRunningManSkel, NULL, pthis->jointTable, pthis->morphTable, 16);
    Animation_Change(&pthis->skelAnime, sAnimationEntries[RM2_ANIM_SIT_WAIT].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationEntries[RM2_ANIM_SIT_WAIT].animation),
                     sAnimationEntries[RM2_ANIM_SIT_WAIT].mode, sAnimationEntries[RM2_ANIM_SIT_WAIT].morphFrames);
    pthis->previousAnimation = RM2_ANIM_SIT_WAIT;
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->mouthTexIndex = RM2_MOUTH_CLOSED;
    pthis->actor.targetMode = 6;
    pthis->unk_1F4 |= 1;
    pthis->actor.gravity = -1.0f;
    if (pthis->actor.params == 1) {
        pthis->actionFunc = func_80AAF668;
    } else {
        func_80AAEF70(pthis, globalCtx);
        pthis->actionFunc = func_80AAF57C;
    }
    if (!LINK_IS_ADULT) {
        Actor_Kill(&pthis->actor);
    }
    if (pthis->actor.params == 1) {
        if (!(gSaveContext.infTable[23] & 0x8000) || !(gSaveContext.eventInf[1] & 1)) {
            osSyncPrintf(VT_FGCOL(CYAN) " マラソン 開始されていない \n" VT_RST "\n");
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnMm2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* pthis = (EnMm2*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80AAF224(EnMm2* pthis, GlobalContext* globalCtx, EnMm2ActionFunc actionFunc) {
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = actionFunc;
        return 1;
    }
    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if ((ABS(yawDiff) <= 0x4300) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    }
    return 0;
}

void func_80AAF2BC(EnMm2* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1F6 > 60) {
        Actor_Kill(&pthis->actor);
    }
    SkelAnime_Update(&pthis->skelAnime);
    pthis->unk_1F6++;
    Math_SmoothStepToF(&pthis->actor.speedXZ, 10.0f, 0.6f, 2.0f, 0.0f);
}

void func_80AAF330(EnMm2* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actionFunc = func_80AAF2BC;
        EnMm2_ChangeAnimation(pthis, 0, &pthis->previousAnimation);
        pthis->mouthTexIndex = RM2_MOUTH_OPEN;
        if (!(pthis->unk_1F4 & 2)) {
            Message_CloseTextbox(globalCtx);
        }
        gSaveContext.timer2State = 0;
        gSaveContext.eventInf[1] &= ~1;
    }
}

void func_80AAF3C0(EnMm2* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    switch (pthis->actor.textId) {
        case 0x607D:
        case 0x607E:
            if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
                switch (globalCtx->msgCtx.choiceIndex) {
                    case 0:
                        Message_ContinueTextbox(globalCtx, 0x607F);
                        pthis->actor.textId = 0x607F;
                        gSaveContext.eventInf[1] |= 1;
                        break;
                    case 1:
                        Message_ContinueTextbox(globalCtx, 0x6080);
                        pthis->actor.textId = 0x6080;
                        break;
                };
                if (pthis->unk_1F4 & 4) {
                    if (1) {}
                    pthis->unk_1F4 &= ~4;
                    HIGH_SCORE(HS_MARATHON) += 1;
                }
            }
            return;
        case 0x6081:
            if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
                pthis->unk_1F4 |= 4;
                HIGH_SCORE(HS_MARATHON) -= 1;
                Message_ContinueTextbox(globalCtx, 0x607E);
                pthis->actor.textId = 0x607E;
            }
            return;
    }

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        if (pthis->actor.textId == 0x607F) {
            func_80088AA0(0);
            pthis->actionFunc = func_80AAF57C;
        } else {
            pthis->actionFunc = func_80AAF57C;
        }
        pthis->actionFunc = func_80AAF57C;
        func_80AAEF70(pthis, globalCtx);
    }
}

void func_80AAF57C(EnMm2* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    func_80AAEF70(pthis, globalCtx);
    if ((func_80AAF224(pthis, globalCtx, func_80AAF3C0)) && (pthis->actor.textId == 0x607D)) {
        gSaveContext.infTable[23] |= 0x8000;
    }
}

void func_80AAF5EC(EnMm2* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->unk_1F4 &= ~1;
        EnMm2_ChangeAnimation(pthis, 3, &pthis->previousAnimation);
        pthis->actionFunc = func_80AAF330;
    }
}

void func_80AAF668(EnMm2* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.rot.y = -0x3E80;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    SkelAnime_Update(&pthis->skelAnime);
    if (((void)0, gSaveContext.timer2Value) < HIGH_SCORE(HS_MARATHON)) {
        pthis->actor.textId = 0x6085;
    } else {
        pthis->actor.textId = 0x6084;
    }
    if (func_80AAF224(pthis, globalCtx, func_80AAF5EC)) {
        pthis->unk_1F6 = 0;
        if (((void)0, gSaveContext.timer2Value) < HIGH_SCORE(HS_MARATHON)) {
            HIGH_SCORE(HS_MARATHON) = gSaveContext.timer2Value;
        }
    } else {
        LOG_HEX("((z_common_data.event_inf[1]) & (0x0001))", gSaveContext.eventInf[1] & 1, "../z_en_mm2.c", 541);
        if (!(gSaveContext.eventInf[1] & 1)) {
            pthis->unk_1F4 |= 2;
            pthis->unk_1F4 &= ~1;
            EnMm2_ChangeAnimation(pthis, 3, &pthis->previousAnimation);
            pthis->actionFunc = func_80AAF330;
        }
    }
}

void EnMm2_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* pthis = (EnMm2*)thisx;
    s32 pad;

    if (pthis->unk_1F4 & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->unk_1E8, &pthis->unk_1EE, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->unk_1E8.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_1E8.y, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_1EE.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_1EE.y, 0, 6, 6200, 100);
    }
    pthis->actionFunc(pthis, globalCtx);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
}

void EnMm2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* mouthTextures[] = { gRunningManMouthOpenTex, gRunningManMouthClosedTex };
    EnMm2* pthis = (EnMm2*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_mm2.c", 634);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(mouthTextures[pthis->mouthTexIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnMm2_OverrideLimbDraw, EnMm2_PostLimbDraw, pthis);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_mm2.c", 654);
}

s32 EnMm2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMm2* pthis = (EnMm2*)thisx;

    switch (limbIndex) {
        case 8:
            rot->x += pthis->unk_1EE.y;
            rot->y -= pthis->unk_1EE.x;
            break;
        case 15:
            rot->x += pthis->unk_1E8.y;
            rot->z += pthis->unk_1E8.x + 0xFA0;
            break;
    }

    return 0;
}

void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f headOffset = { 200.0f, 800.0f, 0.0f };
    EnMm2* pthis = (EnMm2*)thisx;

    if (limbIndex == 15) {
        Matrix_MultVec3f(&headOffset, &pthis->actor.focus.pos);
    }
}

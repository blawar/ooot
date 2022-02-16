#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MS_Z_EN_MS_C
#include "actor_common.h"
/*
 * File: z_en_ms.c
 * Overlay: ovl_En_Ms
 * Description: Magic Bean Salesman
 */

#include "z_en_ms.h"
#include "objects/object_ms/object_ms.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnMs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMs_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMs_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnMs_SetOfferText(EnMs* pthis, GlobalContext* globalCtx);
void EnMs_Wait(EnMs* pthis, GlobalContext* globalCtx);
void EnMs_Talk(EnMs* pthis, GlobalContext* globalCtx);
void EnMs_Sell(EnMs* pthis, GlobalContext* globalCtx);
void EnMs_TalkAfterPurchase(EnMs* pthis, GlobalContext* globalCtx);

ActorInit En_Ms_InitVars = {
    ACTOR_EN_MS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MS,
    sizeof(EnMs),
    (ActorFunc)EnMs_Init,
    (ActorFunc)EnMs_Destroy,
    (ActorFunc)EnMs_Update,
    (ActorFunc)EnMs_Draw,
    (ActorFunc)EnMs_Reset,
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 22, 37, 0, { 0 } },
};

static s16 sPrices[] = {
    10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
};

static u16 sOfferTextIDs[] = {
    0x405E, 0x405F, 0x4060, 0x4061, 0x4062, 0x4063, 0x4064, 0x4065, 0x4066, 0x4067,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 500, ICHAIN_STOP),
};

void EnMs_SetOfferText(EnMs* pthis, GlobalContext* globalCtx) {
    pthis->actor.textId = Text_GetFaceReaction(globalCtx, 0x1B);
    if (pthis->actor.textId == 0) {
        if (BEANS_BOUGHT >= 10) {
            pthis->actor.textId = 0x406B;
        } else {
            pthis->actor.textId = sOfferTextIDs[BEANS_BOUGHT];
        }
    }
}

void EnMs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMs* pthis = (EnMs*)thisx;
    s32 pad;

    if (LINK_AGE_IN_YEARS != YEARS_CHILD) {
        Actor_Kill(&pthis->actor);
        return;
    }
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gBeanSalesmanSkel, &gBeanSalesmanEatingAnim, pthis->jointTable,
                       pthis->morphTable, 9);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
    Actor_SetScale(&pthis->actor, 0.015f);

    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -1.0f;

    EnMs_SetOfferText(pthis, globalCtx);

    pthis->actionFunc = EnMs_Wait;
}

void EnMs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMs* pthis = (EnMs*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnMs_Wait(EnMs* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    EnMs_SetOfferText(pthis, globalCtx);

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) { // if talk is initiated
        pthis->actionFunc = EnMs_Talk;
    } else if ((pthis->actor.xzDistToPlayer < 90.0f) && (ABS(yawDiff) < 0x2000)) { // talk range
        func_8002F2CC(&pthis->actor, globalCtx, 90.0f);
    }
}

void EnMs_Talk(EnMs* pthis, GlobalContext* globalCtx) {
    u8 dialogState;

    dialogState = Message_GetState(&globalCtx->msgCtx);
    if (dialogState != TEXT_STATE_CHOICE) {
        if ((dialogState == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) { // advanced final textbox
            pthis->actionFunc = EnMs_Wait;
        }
    } else if (Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                if (gSaveContext.rupees < sPrices[BEANS_BOUGHT]) {
                    Message_ContinueTextbox(globalCtx, 0x4069); // not enough rupees text
                    return;
                }
                func_8002F434(&pthis->actor, globalCtx, GI_BEAN, 90.0f, 10.0f);
                pthis->actionFunc = EnMs_Sell;
                return;
            case 1: // no
                Message_ContinueTextbox(globalCtx, 0x4068);
            default:
                return;
        }
    }
}

void EnMs_Sell(EnMs* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        Rupees_ChangeBy(-sPrices[BEANS_BOUGHT]);
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnMs_TalkAfterPurchase;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_BEAN, 90.0f, 10.0f);
    }
}

void EnMs_TalkAfterPurchase(EnMs* pthis, GlobalContext* globalCtx) {
    // if dialog state is 6 and player responded to textbox
    if ((Message_GetState(&globalCtx->msgCtx)) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x406C);
        pthis->actionFunc = EnMs_Talk;
    }
}

void EnMs_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMs* pthis = (EnMs*)thisx;
    s32 pad;

    pthis->activeTimer += 1;
    Actor_SetFocus(&pthis->actor, 20.0f);
    pthis->actor.targetArrowOffset = 500.0f;
    Actor_SetScale(&pthis->actor, 0.015f);
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actionFunc(pthis, globalCtx);

    if (gSaveContext.entranceIndex == 0x157 && gSaveContext.sceneSetupIndex == 8) { // ride carpet if in credits
        Actor_MoveForward(&pthis->actor);
        osSyncPrintf("OOOHHHHHH %f\n", pthis->actor.velocity.y);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    }
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnMs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMs* pthis = (EnMs*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
}

void EnMs_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ms_InitVars = {
        ACTOR_EN_MS,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_MS,
        sizeof(EnMs),
        (ActorFunc)EnMs_Init,
        (ActorFunc)EnMs_Destroy,
        (ActorFunc)EnMs_Update,
        (ActorFunc)EnMs_Draw,
        (ActorFunc)EnMs_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
        { 22, 37, 0, { 0 } },
    };

}

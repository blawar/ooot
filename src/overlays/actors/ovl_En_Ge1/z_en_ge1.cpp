#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GE1_Z_EN_GE1_C
#include "actor_common.h"
/*
 * File: z_en_ge1.c
 * Overlay: ovl_En_Ge1
 * Description: White-clothed Gerudo
 */

#include "z_en_ge1.h"
#include "vt.h"
#include "objects/object_ge1/object_ge1.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_horse.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

#define GE1_STATE_TALKING (1 << 0)
#define GE1_STATE_GIVE_QUIVER (1 << 1)
#define GE1_STATE_IDLE_ANIM (1 << 2)
#define GE1_STATE_STOP_FIDGET (1 << 3)

typedef enum {
    /* 00 */ GE1_HAIR_BOB,
    /* 01 */ GE1_HAIR_STRAIGHT,
    /* 02 */ GE1_HAIR_SPIKY
} EnGe1Hairstyle;

void EnGe1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGe1_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnGe1_CheckCarpentersFreed(void);
void EnGe1_WatchForPlayerFrontOnly(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_SetNormalText(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_WatchForAndSensePlayer(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_GetReaction_ValleyFloor(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_CheckForCard_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_CheckGate_GateOp(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_GetReaction_GateGuard(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_TalkAfterGame_Archery(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_Wait_Archery(EnGe1* pthis, GlobalContext* globalCtx);
void EnGe1_CueUpAnimation(EnGe1* pthis);
void EnGe1_StopFidget(EnGe1* pthis);

ActorInit En_Ge1_InitVars = {
    ACTOR_EN_GE1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GE1,
    sizeof(EnGe1),
    (ActorFunc)EnGe1_Init,
    (ActorFunc)EnGe1_Destroy,
    (ActorFunc)EnGe1_Update,
    (ActorFunc)EnGe1_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000702, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 40, 0, { 0, 0, 0 } },
};

static Gfx* sHairstyleDLists[] = {
    gGerudoWhiteHairstyleBobDL,
    gGerudoWhiteHairstyleStraightFringeDL,
    gGerudoWhiteHairstyleSpikyDL,
};

static Vec3f D_80A327A8 = { 600.0f, 700.0f, 0.0f };

static void* sEyeTextures[] = {
    gGerudoWhiteEyeOpenTex,
    gGerudoWhiteEyeHalfTex,
    gGerudoWhiteEyeClosedTex,
};

void EnGe1_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGe1* pthis = (EnGe1*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGerudoWhiteSkel, &gGerudoWhiteIdleAnim, pthis->jointTable,
                       pthis->morphTable, GE1_LIMB_MAX);
    Animation_PlayOnce(&pthis->skelAnime, &gGerudoWhiteIdleAnim);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->animation = &gGerudoWhiteIdleAnim;
    pthis->animFunc = EnGe1_CueUpAnimation;
    pthis->actor.targetMode = 6;
    Actor_SetScale(&pthis->actor, 0.01f);

    // In Gerudo Valley
    pthis->actor.uncullZoneForward = ((globalCtx->sceneNum == SCENE_SPOT09) ? 1000.0f : 1200.0f);

    switch (pthis->actor.params & 0xFF) {

        case GE1_TYPE_GATE_GUARD:
            pthis->hairstyle = GE1_HAIR_SPIKY;
            pthis->actionFunc = EnGe1_GetReaction_GateGuard;
            break;

        case GE1_TYPE_GATE_OPERATOR:
            pthis->hairstyle = GE1_HAIR_STRAIGHT;

            if (EnGe1_CheckCarpentersFreed()) {
                pthis->actionFunc = EnGe1_CheckGate_GateOp;
            } else {
                pthis->actionFunc = EnGe1_WatchForPlayerFrontOnly;
            }
            break;

        case GE1_TYPE_NORMAL:
            pthis->hairstyle = GE1_HAIR_STRAIGHT;

            if (EnGe1_CheckCarpentersFreed()) {
                pthis->actionFunc = EnGe1_SetNormalText;
            } else {
                pthis->actionFunc = EnGe1_WatchForAndSensePlayer;
            }
            break;

        case GE1_TYPE_VALLEY_FLOOR:
            if (LINK_IS_ADULT) {
                // "Valley floor Gerudo withdrawal"
                osSyncPrintf(VT_FGCOL(CYAN) "谷底 ゲルド 撤退 \n" VT_RST);
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->hairstyle = GE1_HAIR_BOB;
            pthis->actionFunc = EnGe1_GetReaction_ValleyFloor;
            break;

        case GE1_TYPE_HORSEBACK_ARCHERY:
            if (INV_CONTENT(SLOT_BOW) == ITEM_NONE) {
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->actor.targetMode = 3;
            pthis->hairstyle = GE1_HAIR_BOB;
            // "Horseback archery Gerudo EVENT_INF(0) ="
            osSyncPrintf(VT_FGCOL(CYAN) "やぶさめ ゲルド EVENT_INF(0) = %x\n" VT_RST, gSaveContext.eventInf[0]);

            if (gSaveContext.eventInf[0] & 0x100) {
                pthis->actionFunc = EnGe1_TalkAfterGame_Archery;
            } else if (EnGe1_CheckCarpentersFreed()) {
                pthis->actionFunc = EnGe1_Wait_Archery;
            } else {
                pthis->actionFunc = EnGe1_WatchForPlayerFrontOnly;
            }
            break;

        case GE1_TYPE_TRAINING_GROUNDS_GUARD:
            pthis->hairstyle = GE1_HAIR_STRAIGHT;

            if (EnGe1_CheckCarpentersFreed()) {
                pthis->actionFunc = EnGe1_CheckForCard_GTGGuard;
            } else {
                pthis->actionFunc = EnGe1_WatchForPlayerFrontOnly;
            }
            break;
    }

    pthis->stateFlags = 0;
}

void EnGe1_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGe1* pthis = (EnGe1*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnGe1_SetTalkAction(EnGe1* pthis, GlobalContext* globalCtx, u16 textId, f32 arg3, EnGe1ActionFunc actionFunc) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = actionFunc;
        pthis->animFunc = EnGe1_StopFidget;
        pthis->stateFlags &= ~GE1_STATE_IDLE_ANIM;
        pthis->animation = &gGerudoWhiteIdleAnim;
        Animation_Change(&pthis->skelAnime, &gGerudoWhiteIdleAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gGerudoWhiteIdleAnim), ANIMMODE_ONCE, -8.0f);
        return true;
    }

    pthis->actor.textId = textId;

    if (pthis->actor.xzDistToPlayer < arg3) {
        func_8002F2CC(&pthis->actor, globalCtx, arg3);
    }

    return false;
}

void EnGe1_SetAnimationIdle(EnGe1* pthis) {
    Animation_Change(&pthis->skelAnime, &gGerudoWhiteIdleAnim, -1.0f, Animation_GetLastFrame(&gGerudoWhiteIdleAnim),
                     0.0f, ANIMMODE_ONCE, 8.0f);
    pthis->animation = &gGerudoWhiteIdleAnim;
    pthis->animFunc = EnGe1_CueUpAnimation;
}

s32 EnGe1_CheckCarpentersFreed(void) {
    u16 carpenterFlags = gSaveContext.eventChkInf[9];

    if (!((carpenterFlags & 1) && (carpenterFlags & 2) && (carpenterFlags & 4) && (carpenterFlags & 8))) {
        return 0;
    }
    return 1;
}

/**
 * Sends player to different places depending on if has hookshot, and if pthis is the first time captured
 */
void EnGe1_KickPlayer(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;

    if (pthis->cutsceneTimer > 0) {
        pthis->cutsceneTimer--;
    } else {
        func_8006D074(globalCtx);

        if ((INV_CONTENT(ITEM_HOOKSHOT) == ITEM_NONE) || (INV_CONTENT(ITEM_LONGSHOT) == ITEM_NONE)) {
            globalCtx->nextEntranceIndex = 0x1A5;
        } else if (gSaveContext.eventChkInf[12] & 0x80) { // Caught previously
            globalCtx->nextEntranceIndex = 0x5F8;
        } else {
            globalCtx->nextEntranceIndex = 0x3B4;
        }

        globalCtx->fadeTransition = 0x26;
        globalCtx->sceneLoadFlag = 0x14;
    }
}

void EnGe1_SpotPlayer(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->cutsceneTimer = 30;
    pthis->actionFunc = EnGe1_KickPlayer;
    func_8002DF54(globalCtx, &pthis->actor, 0x5F);
    func_80078884(NA_SE_SY_FOUND);
    Message_StartTextbox(globalCtx, 0x6000, &pthis->actor);
}

void EnGe1_WatchForPlayerFrontOnly(EnGe1* pthis, GlobalContext* globalCtx) {
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if ((ABS(angleDiff) <= 0x4300) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        EnGe1_SpotPlayer(pthis, globalCtx);
    }

    if (pthis->collider.base.acFlags & AC_HIT) {
        EnGe1_SpotPlayer(pthis, globalCtx);
    }

    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnGe1_ChooseActionFromTextId(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        switch (pthis->actor.textId) {
            case 0x6001:
                pthis->actionFunc = EnGe1_SetNormalText;
                break;

            case 0x601A:
            case 0x6019:
                pthis->actionFunc = EnGe1_GetReaction_ValleyFloor;
                break;

            case 0x6018:
                pthis->actionFunc = EnGe1_CheckGate_GateOp;
                break;

            default:
                pthis->actionFunc = EnGe1_GetReaction_ValleyFloor;
                break;
        }
    }
}

void EnGe1_SetNormalText(EnGe1* pthis, GlobalContext* globalCtx) {
    EnGe1_SetTalkAction(pthis, globalCtx, 0x6001, 100.0f, EnGe1_ChooseActionFromTextId);
}

void EnGe1_WatchForAndSensePlayer(EnGe1* pthis, GlobalContext* globalCtx) {
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if ((pthis->actor.xzDistToPlayer < 50.0f) || ((ABS(angleDiff) <= 0x4300) && (pthis->actor.xzDistToPlayer < 400.0f))) {
        EnGe1_SpotPlayer(pthis, globalCtx);
    }

    if (pthis->collider.base.acFlags & AC_HIT) {
        EnGe1_SpotPlayer(pthis, globalCtx);
    }
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnGe1_GetReaction_ValleyFloor(EnGe1* pthis, GlobalContext* globalCtx) {
    u16 reactionText = Text_GetFaceReaction(globalCtx, 0x22);

    if (reactionText == 0) {
        reactionText = 0x6019;
    }

    EnGe1_SetTalkAction(pthis, globalCtx, reactionText, 100.0f, EnGe1_ChooseActionFromTextId);
}

// Gerudo Training Ground Guard functions

void EnGe1_WaitTillOpened_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    if (pthis->cutsceneTimer > 0) {
        pthis->cutsceneTimer--;
    } else {
        EnGe1_SetAnimationIdle(pthis);
        pthis->actionFunc = EnGe1_SetNormalText;
    }

    pthis->stateFlags |= GE1_STATE_STOP_FIDGET;
}

void EnGe1_Open_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    if (pthis->stateFlags & GE1_STATE_IDLE_ANIM) {
        pthis->actionFunc = EnGe1_WaitTillOpened_GTGGuard;
        Flags_SetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F);
        pthis->cutsceneTimer = 50;
        Message_CloseTextbox(globalCtx);
    } else if ((pthis->skelAnime.curFrame == 15.0f) || (pthis->skelAnime.curFrame == 19.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_HAND_CLAP);
    }
}

void EnGe1_SetupOpen_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = EnGe1_Open_GTGGuard;
        Animation_Change(&pthis->skelAnime, &gGerudoWhiteClapAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gGerudoWhiteClapAnim), ANIMMODE_ONCE, -3.0f);
        pthis->animation = &gGerudoWhiteClapAnim;
        pthis->animFunc = EnGe1_StopFidget;
        pthis->stateFlags &= ~GE1_STATE_IDLE_ANIM;
    }
}

void EnGe1_RefuseEntryTooPoor_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->actionFunc = EnGe1_CheckForCard_GTGGuard;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_OfferOpen_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);

        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                if (gSaveContext.rupees < 10) {
                    Message_ContinueTextbox(globalCtx, 0x6016);
                    pthis->actionFunc = EnGe1_RefuseEntryTooPoor_GTGGuard;
                } else {
                    Rupees_ChangeBy(-10);
                    Message_ContinueTextbox(globalCtx, 0x6015);
                    pthis->actionFunc = EnGe1_SetupOpen_GTGGuard;
                }
                break;
            case 1:
                pthis->actionFunc = EnGe1_CheckForCard_GTGGuard;
                EnGe1_SetAnimationIdle(pthis);
                break;
        }
    }
}

void EnGe1_RefuseOpenNoCard_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_CheckForCard_GTGGuard;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_CheckForCard_GTGGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    if (CHECK_QUEST_ITEM(QUEST_GERUDO_CARD)) {
        EnGe1_SetTalkAction(pthis, globalCtx, 0x6014, 100.0f, EnGe1_OfferOpen_GTGGuard);
    } else {
        //! @bug This outcome is inaccessible in normal gameplay since pthis function it is unreachable without
        //! obtaining the card in the first place.
        EnGe1_SetTalkAction(pthis, globalCtx, 0x6013, 100.0f, EnGe1_RefuseOpenNoCard_GTGGuard);
    }
}

// Gate Operator functions

void EnGe1_WaitGateOpen_GateOp(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnGe1_CheckGate_GateOp;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_WaitUntilGateOpened_GateOp(EnGe1* pthis, GlobalContext* globalCtx) {
    if (pthis->cutsceneTimer > 0) {
        pthis->cutsceneTimer--;
    } else {
        EnGe1_SetAnimationIdle(pthis);
        pthis->actionFunc = EnGe1_CheckGate_GateOp;
    }
    pthis->stateFlags |= GE1_STATE_STOP_FIDGET;
}

void EnGe1_OpenGate_GateOp(EnGe1* pthis, GlobalContext* globalCtx) {
    if (pthis->stateFlags & GE1_STATE_IDLE_ANIM) {
        pthis->actionFunc = EnGe1_WaitUntilGateOpened_GateOp;
        Flags_SetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F);
        pthis->cutsceneTimer = 50;
        Message_CloseTextbox(globalCtx);
    } else if ((pthis->skelAnime.curFrame == 15.0f) || (pthis->skelAnime.curFrame == 19.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_HAND_CLAP);
    }
}

void EnGe1_SetupOpenGate_GateOp(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = EnGe1_OpenGate_GateOp;
        Animation_Change(&pthis->skelAnime, &gGerudoWhiteClapAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gGerudoWhiteClapAnim), ANIMMODE_ONCE, -3.0f);
        pthis->animation = &gGerudoWhiteClapAnim;
        pthis->animFunc = EnGe1_StopFidget;
        pthis->stateFlags &= ~GE1_STATE_IDLE_ANIM;
    }
}

void EnGe1_CheckGate_GateOp(EnGe1* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->actor.params >> 8) & 0x3F)) {
        EnGe1_SetTalkAction(pthis, globalCtx, 0x6018, 100.0f, EnGe1_WaitGateOpen_GateOp);
    } else {
        EnGe1_SetTalkAction(pthis, globalCtx, 0x6017, 100.0f, EnGe1_SetupOpenGate_GateOp);
    }
}

// Gate guard functions

void EnGe1_Talk_GateGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_GetReaction_GateGuard;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_GetReaction_GateGuard(EnGe1* pthis, GlobalContext* globalCtx) {
    u16 reactionText;

    reactionText = Text_GetFaceReaction(globalCtx, 0x22);

    if (reactionText == 0) {
        reactionText = 0x6069;
    }

    if (EnGe1_SetTalkAction(pthis, globalCtx, reactionText, 100.0f, EnGe1_Talk_GateGuard)) {
        pthis->animFunc = EnGe1_CueUpAnimation;
        pthis->animation = &gGerudoWhiteDismissiveAnim;
        Animation_Change(&pthis->skelAnime, &gGerudoWhiteDismissiveAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gGerudoWhiteDismissiveAnim), ANIMMODE_ONCE, -8.0f);
    }
}

// Archery functions

void EnGe1_SetupWait_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_Wait_Archery;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_WaitTillItemGiven_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    s32 getItemId;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_SetupWait_Archery;
        if (pthis->stateFlags & GE1_STATE_GIVE_QUIVER) {
            gSaveContext.itemGetInf[0] |= 0x8000;
        } else {
            gSaveContext.infTable[25] |= 1;
        }
    } else {
        if (pthis->stateFlags & GE1_STATE_GIVE_QUIVER) {
            switch (CUR_UPG_VALUE(UPG_QUIVER)) {
                //! @bug Asschest. See next function for details
                case 1:
                    getItemId = GI_QUIVER_40;
                    break;
                case 2:
                    getItemId = GI_QUIVER_50;
                    break;
            }
        } else {
            getItemId = GI_HEART_PIECE;
        }
        func_8002F434(&pthis->actor, globalCtx, getItemId, 10000.0f, 50.0f);
    }
}

void EnGe1_BeginGiveItem_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    s32 getItemId;

    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->actionFunc = EnGe1_WaitTillItemGiven_Archery;
    }

    if (pthis->stateFlags & GE1_STATE_GIVE_QUIVER) {
        switch (CUR_UPG_VALUE(UPG_QUIVER)) {
            //! @bug Asschest: the compiler inserts a default assigning *(sp+0x24) to getItemId, which is junk data left
            //! over from the previous function run in EnGe1_Update, namely EnGe1_CueUpAnimation. The top stack variable
            //! in that function is &pthis->skelAnime = thisx + 198, and depending on where pthis loads in memory, the
            //! getItemId changes.
            case 1:
                getItemId = GI_QUIVER_40;
                break;
            case 2:
                getItemId = GI_QUIVER_50;
                break;
        }
    } else {
        getItemId = GI_HEART_PIECE;
    }

    func_8002F434(&pthis->actor, globalCtx, getItemId, 10000.0f, 50.0f);
}

void EnGe1_TalkWinPrize_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_BeginGiveItem_Archery;
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 200.0f);
    }
}

void EnGe1_TalkTooPoor_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnGe1_Wait_Archery;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_WaitDoNothing(EnGe1* pthis, GlobalContext* globalCtx) {
}

void EnGe1_BeginGame_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* horse;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;

        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                if (gSaveContext.rupees < 20) {
                    Message_ContinueTextbox(globalCtx, 0x85);
                    pthis->actionFunc = EnGe1_TalkTooPoor_Archery;
                } else {
                    Rupees_ChangeBy(-20);
                    globalCtx->nextEntranceIndex = 0x129;
                    gSaveContext.nextCutsceneIndex = 0xFFF0;
                    globalCtx->fadeTransition = 0x26;
                    globalCtx->sceneLoadFlag = 0x14;
                    gSaveContext.eventInf[0] |= 0x100;
                    gSaveContext.eventChkInf[6] |= 0x100;

                    if (!(player->stateFlags1 & 0x800000)) {
                        func_8002DF54(globalCtx, &pthis->actor, 1);
                    } else {
                        horse = Actor_FindNearby(globalCtx, &player->actor, ACTOR_EN_HORSE, ACTORCAT_BG, 1200.0f);
                        player->actor.freezeTimer = 1200;

                        if (horse != NULL) {
                            horse->freezeTimer = 1200;
                        }
                    }

                    pthis->actionFunc = EnGe1_WaitDoNothing;
                }
                break;

            case 1:
                pthis->actionFunc = EnGe1_Wait_Archery;
                Message_CloseTextbox(globalCtx);
                break;
        }
    }
}

void EnGe1_TalkOfferPlay_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0x6041);
        pthis->actionFunc = EnGe1_BeginGame_Archery;
    }
}

void EnGe1_TalkNoPrize_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_TalkOfferPlay_Archery;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 300.0f);
    }
}

void EnGe1_TalkAfterGame_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    gSaveContext.eventInf[0] &= ~0x100;
    LOG_NUM("z_common_data.yabusame_total", gSaveContext.minigameScore, "../z_en_ge1.c", 1110);
    LOG_NUM("z_common_data.memory.information.room_inf[127][ 0 ]", HIGH_SCORE(HS_HBA), "../z_en_ge1.c", 1111);
    pthis->actor.flags |= ACTOR_FLAG_16;

    if (HIGH_SCORE(HS_HBA) < gSaveContext.minigameScore) {
        HIGH_SCORE(HS_HBA) = gSaveContext.minigameScore;
    }

    if (gSaveContext.minigameScore < 1000) {
        pthis->actor.textId = 0x6045;
        pthis->actionFunc = EnGe1_TalkNoPrize_Archery;
    } else if (!(gSaveContext.infTable[25] & 1)) {
        pthis->actor.textId = 0x6046;
        pthis->actionFunc = EnGe1_TalkWinPrize_Archery;
        pthis->stateFlags &= ~GE1_STATE_GIVE_QUIVER;
    } else if (gSaveContext.minigameScore < 1500) {
        pthis->actor.textId = 0x6047;
        pthis->actionFunc = EnGe1_TalkNoPrize_Archery;
    } else if (gSaveContext.itemGetInf[0] & 0x8000) {
        pthis->actor.textId = 0x6047;
        pthis->actionFunc = EnGe1_TalkNoPrize_Archery;
    } else {
        pthis->actor.textId = 0x6044;
        pthis->actionFunc = EnGe1_TalkWinPrize_Archery;
        pthis->stateFlags |= GE1_STATE_GIVE_QUIVER;
    }
}

void EnGe1_TalkNoHorse_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= GE1_STATE_TALKING;
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnGe1_Wait_Archery;
        EnGe1_SetAnimationIdle(pthis);
    }
}

void EnGe1_Wait_Archery(EnGe1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    u16 textId;

    if (!(player->stateFlags1 & 0x800000)) {
        EnGe1_SetTalkAction(pthis, globalCtx, 0x603F, 100.0f, EnGe1_TalkNoHorse_Archery);
    } else {
        if (gSaveContext.eventChkInf[6] & 0x100) {
            if (gSaveContext.infTable[25] & 1) {
                textId = 0x6042;
            } else {
                textId = 0x6043;
            }
        } else {
            textId = 0x6040;
        }
        EnGe1_SetTalkAction(pthis, globalCtx, textId, 200.0f, EnGe1_TalkOfferPlay_Archery);
    }
}

// General functions

void EnGe1_TurnToFacePlayer(EnGe1* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (ABS(angleDiff) <= 0x4000) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 6, 4000, 100);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->unk_2A2, pthis->actor.focus.pos);
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

void EnGe1_LookAtPlayer(EnGe1* pthis, GlobalContext* globalCtx) {
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if ((ABS(angleDiff) <= 0x4300) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->unk_2A2, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->headRot.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->headRot.y, 0, 6, 6200, 100);
    }
}

void EnGe1_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGe1* pthis = (EnGe1*)thisx;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 40.0f, 25.0f, 40.0f, 5);
    pthis->animFunc(pthis);
    pthis->actionFunc(pthis, globalCtx);

    if (pthis->stateFlags & GE1_STATE_TALKING) {
        EnGe1_TurnToFacePlayer(pthis, globalCtx);
        pthis->stateFlags &= ~GE1_STATE_TALKING;
    } else {
        EnGe1_LookAtPlayer(pthis, globalCtx);
    }
    pthis->unk_2A2.x = pthis->unk_2A2.y = pthis->unk_2A2.z = 0;

    if (DECR(pthis->blinkTimer) == 0) {
        pthis->blinkTimer = Rand_S16Offset(60, 60);
    }
    pthis->eyeIndex = pthis->blinkTimer;

    if (pthis->eyeIndex >= 3) {
        pthis->eyeIndex = 0;
    }
}

// Animation functions

void EnGe1_CueUpAnimation(EnGe1* pthis) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        Animation_PlayOnce(&pthis->skelAnime, pthis->animation);
    }
}

void EnGe1_StopFidget(EnGe1* pthis) {
    if (!(pthis->stateFlags & GE1_STATE_IDLE_ANIM)) {
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->stateFlags |= GE1_STATE_IDLE_ANIM;
        }
        pthis->stateFlags |= GE1_STATE_STOP_FIDGET;
    }
}

s32 EnGe1_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    s32 pad;
    EnGe1* pthis = (EnGe1*)thisx;

    if (limbIndex == GE1_LIMB_HEAD) {
        rot->x += pthis->headRot.y;
        rot->z += pthis->headRot.x;
    }

    if (pthis->stateFlags & GE1_STATE_STOP_FIDGET) {
        pthis->stateFlags &= ~GE1_STATE_STOP_FIDGET;
        return 0;
    }

    // The purpose of the state flag GE1_STATE_STOP_FIDGET is to skip pthis code, which pthis actor has in lieu of an idle
    // animation.
    if ((limbIndex == GE1_LIMB_TORSO) || (limbIndex == GE1_LIMB_L_FOREARM) || (limbIndex == GE1_LIMB_R_FOREARM)) {
        rot->y += Math_SinS((globalCtx->state.frames * (limbIndex * 50 + 0x814)).toS16()) * 200.0f;
        rot->z += Math_CosS((globalCtx->state.frames * (limbIndex * 50 + 0x940)).toS16()) * 200.0f;
    }
    return 0;
}

void EnGe1_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnGe1* pthis = (EnGe1*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 1419);

    if (limbIndex == GE1_LIMB_HEAD) {
        gSPDisplayList(POLY_OPA_DISP++, sHairstyleDLists[pthis->hairstyle]);
        Matrix_MultVec3f(&D_80A327A8, &pthis->actor.focus.pos);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 1427);
}

void EnGe1_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGe1* pthis = (EnGe1*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 1442);

    func_800943C8(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnGe1_OverrideLimbDraw, EnGe1_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ge1.c", 1459);
}

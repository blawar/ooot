#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FU_Z_EN_FU_C
#include "actor_common.h"
/*
 * File: z_en_fu.c
 * Overlay: ovl_En_Fu
 * Description: Windmill Man
 */

#include "z_en_fu.h"
#include "objects/object_fu/object_fu.h"
#include "scenes/indoors/hakasitarelay/hakasitarelay_scene.h"
#include "def/code_800EC960.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

#define FU_RESET_LOOK_ANGLE (1 << 0)
#define FU_WAIT (1 << 1)

void EnFu_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFu_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFu_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFu_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFu_WaitChild(EnFu* pthis, GlobalContext* globalCtx);
void func_80A1DA04(EnFu* pthis, GlobalContext* globalCtx);

void EnFu_WaitAdult(EnFu* pthis, GlobalContext* globalCtx);
void EnFu_TeachSong(EnFu* pthis, GlobalContext* globalCtx);
void EnFu_WaitForPlayback(EnFu* pthis, GlobalContext* globalCtx);
void func_80A1DBA0(EnFu* pthis, GlobalContext* globalCtx);
void func_80A1DBD4(EnFu* pthis, GlobalContext* globalCtx);
void func_80A1DB60(EnFu* pthis, GlobalContext* globalCtx);

ActorInit En_Fu_InitVars = {
    ACTOR_EN_FU,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FU,
    sizeof(EnFu),
    (ActorFunc)EnFu_Init,
    (ActorFunc)EnFu_Destroy,
    (ActorFunc)EnFu_Update,
    (ActorFunc)EnFu_Draw,
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
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 30, 40, 0, { 0, 0, 0 } },
};

static Vec3f sMtxSrc = {
    700.0f,
    700.0f,
    0.0f,
};

typedef enum {
    /* 0x00 */ FU_FACE_CALM,
    /* 0x01 */ FU_FACE_MAD
} EnFuFace;

void EnFu_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFu* pthis = (EnFu*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelanime, &gWindmillManSkel, &gWindmillManPlayStillAnim, pthis->jointTable,
                       pthis->morphTable, FU_LIMB_MAX);
    Animation_PlayLoop(&pthis->skelanime, &gWindmillManPlayStillAnim);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&pthis->actor, 0.01f);
    if (!LINK_IS_ADULT) {
        pthis->actionFunc = EnFu_WaitChild;
        pthis->facialExpression = FU_FACE_CALM;
    } else {
        pthis->actionFunc = EnFu_WaitAdult;
        pthis->facialExpression = FU_FACE_MAD;
        pthis->skelanime.playSpeed = 2.0f;
    }
    pthis->behaviorFlags = 0;
    pthis->actor.targetMode = 6;
}

void EnFu_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFu* pthis = (EnFu*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80A1D94C(EnFu* pthis, GlobalContext* globalCtx, u16 textID, EnFuActionFunc actionFunc) {
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = actionFunc;
        return true;
    }
    pthis->actor.textId = textID;
    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if ((ABS(yawDiff) < 0x2301) && (pthis->actor.xzDistToPlayer < 100.0f)) {
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    } else {
        pthis->behaviorFlags |= FU_RESET_LOOK_ANGLE;
    }
    return false;
}

void func_80A1DA04(EnFu* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->behaviorFlags &= ~FU_WAIT;
        pthis->actionFunc = EnFu_WaitChild;

        if (pthis->skelanime.animation == &gWindmillManPlayAndMoveHeadAnim) {
            Animation_Change(&pthis->skelanime, &gWindmillManPlayStillAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gWindmillManPlayStillAnim), ANIMMODE_ONCE, -4.0f);
        }
    }
}

void EnFu_WaitChild(EnFu* pthis, GlobalContext* globalCtx) {
    u16 textID = Text_GetFaceReaction(globalCtx, 0xB);

    if (textID == 0) {
        textID = (gSaveContext.eventChkInf[6] & 0x80) ? 0x5033 : 0x5032;
    }

    // if ACTOR_FLAG_8 is set and textID is 0x5033, change animation
    // if func_80A1D94C returns 1, actionFunc is set to func_80A1DA04
    if (func_80A1D94C(pthis, globalCtx, textID, func_80A1DA04)) {
        if (textID == 0x5033) {
            Animation_Change(&pthis->skelanime, &gWindmillManPlayAndMoveHeadAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gWindmillManPlayAndMoveHeadAnim), ANIMMODE_ONCE, -4.0f);
        }
    }
}

void func_80A1DB60(EnFu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        pthis->actionFunc = EnFu_WaitAdult;
        gSaveContext.eventChkInf[5] |= 0x800;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    }
}

void func_80A1DBA0(EnFu* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnFu_WaitAdult;
    }
}

void func_80A1DBD4(EnFu* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_04) {
        pthis->actionFunc = EnFu_WaitAdult;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        pthis->actionFunc = func_80A1DB60;
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gSongOfStormsCs);
        gSaveContext.cutsceneTrigger = 1;
        Item_Give(globalCtx, ITEM_SONG_STORMS);
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_00;
        gSaveContext.eventChkInf[6] |= 0x20;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_02) {
        player->stateFlags2 &= ~0x1000000;
        pthis->actionFunc = EnFu_WaitAdult;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
        player->stateFlags2 |= 0x800000;
    }
}

void EnFu_WaitForPlayback(EnFu* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    player->stateFlags2 |= 0x800000;
    // if dialog state is 7, player has played back the song
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_SONG_DEMO_DONE) {
        func_8010BD58(globalCtx, OCARINA_ACTION_PLAYBACK_STORMS);
        pthis->actionFunc = func_80A1DBD4;
    }
}

void EnFu_TeachSong(EnFu* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    player->stateFlags2 |= 0x800000;
    // if dialog state is 2, start song demonstration
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->behaviorFlags &= ~FU_WAIT;
        Audio_OcaSetInstrument(4); // seems to be related to setting instrument type
        func_8010BD58(globalCtx, OCARINA_ACTION_TEACH_STORMS);
        pthis->actionFunc = EnFu_WaitForPlayback;
    }
}

void EnFu_WaitAdult(EnFu* pthis, GlobalContext* globalCtx) {
    static s16 yawDiff;
    Player* player = GET_PLAYER(globalCtx);

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if ((gSaveContext.eventChkInf[5] & 0x800)) {
        func_80A1D94C(pthis, globalCtx, 0x508E, func_80A1DBA0);
    } else if (player->stateFlags2 & 0x1000000) {
        pthis->actor.textId = 0x5035;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        pthis->actionFunc = EnFu_TeachSong;
        pthis->behaviorFlags |= FU_WAIT;
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80A1DBA0;
    } else if (ABS(yawDiff) < 0x2301) {
        if (pthis->actor.xzDistToPlayer < 100.0f) {
            pthis->actor.textId = 0x5034;
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
            player->stateFlags2 |= 0x800000;
        }
    }
}

void EnFu_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFu* pthis = (EnFu*)thisx;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    if ((!(pthis->behaviorFlags & FU_WAIT)) && (SkelAnime_Update(&pthis->skelanime) != 0)) {
        Animation_Change(&pthis->skelanime, (AnimationHeader*)pthis->skelanime.animation, 1.0f, 0.0f,
                         Animation_GetLastFrame(pthis->skelanime.animation), ANIMMODE_ONCE, 0.0f);
    }
    pthis->actionFunc(pthis, globalCtx);
    if ((pthis->behaviorFlags & FU_RESET_LOOK_ANGLE)) {
        Math_SmoothStepToS(&pthis->lookAngleOffset.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->lookAngleOffset.y, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.x, 0, 6, 6200, 100);
        Math_SmoothStepToS(&pthis->unk_2A2.y, 0, 6, 6200, 100);
        pthis->behaviorFlags &= ~FU_RESET_LOOK_ANGLE;
    } else {
        func_80038290(globalCtx, &pthis->actor, &pthis->lookAngleOffset, &pthis->unk_2A2, pthis->actor.focus.pos);
    }
}

s32 EnFu_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnFu* pthis = (EnFu*)thisx;
    s32 pad;

    if (limbIndex == FU_LIMB_UNK) {
        return false;
    }
    switch (limbIndex) {
        case FU_LIMB_HEAD:
            rot->x += pthis->lookAngleOffset.y;
            rot->z += pthis->lookAngleOffset.x;
            break;
        case FU_LIMB_CHEST_MUSIC_BOX:
            break;
    }

    if (!(pthis->behaviorFlags & FU_WAIT)) {
        return false;
    }

    if (limbIndex == FU_LIMB_CHEST_MUSIC_BOX) {
        rot->y += (Math_SinS((globalCtx->state.frames * (limbIndex * 50 + 0x814)).toS16()) * 200.0f);
        rot->z += (Math_CosS((globalCtx->state.frames * (limbIndex * 50 + 0x940)).toS16()) * 200.0f);
    }
    return false;
}

void EnFu_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnFu* pthis = (EnFu*)thisx;

    if (limbIndex == FU_LIMB_HEAD) {
        Matrix_MultVec3f(&sMtxSrc, &pthis->actor.focus.pos);
    }
}

void EnFu_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* sEyesSegments[] = { gWindmillManEyeClosedTex, gWindmillManEyeAngryTex };
    static void* sMouthSegments[] = { gWindmillManMouthOpenTex, gWindmillManMouthAngryTex };
    s32 pad;
    EnFu* pthis = (EnFu*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fu.c", 773);

    func_800943C8(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyesSegments[pthis->facialExpression]));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sMouthSegments[pthis->facialExpression]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, pthis->skelanime.dListCount,
                          EnFu_OverrideLimbDraw, EnFu_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fu.c", 791);
}

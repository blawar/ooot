#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MA2_Z_EN_MA2_C
#include "actor_common.h"
#include "z_en_ma2.h"
#include "objects/object_ma2/object_ma2.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

void EnMa2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMa2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMa2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMa2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMa2_Draw(Actor* thisx, GlobalContext* globalCtx);

u16 func_80AA19A0(GlobalContext* globalCtx, Actor* pthis);
s16 func_80AA1A38(GlobalContext* globalCtx, Actor* pthis);

void func_80AA1AE4(EnMa2* pthis, GlobalContext* globalCtx);
s32 func_80AA1C68(EnMa2* pthis);
void EnMa2_UpdateEyes(EnMa2* pthis);
void func_80AA1DB4(EnMa2* pthis, GlobalContext* globalCtx);
void func_80AA2018(EnMa2* pthis, GlobalContext* globalCtx);
void func_80AA204C(EnMa2* pthis, GlobalContext* globalCtx);
void func_80AA20E4(EnMa2* pthis, GlobalContext* globalCtx);
void func_80AA21C8(EnMa2* pthis, GlobalContext* globalCtx);

static void* sMouthTextures_53[] = { gMalonAdultMouthNeutralTex, gMalonAdultMouthSadTex, gMalonAdultMouthHappyTex };

static void* sEyeTextures_53[] = { gMalonAdultEyeOpenTex, gMalonAdultEyeHalfTex, gMalonAdultEyeClosedTex };


ActorInit En_Ma2_InitVars = {
    ACTOR_EN_MA2,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MA2,
    sizeof(EnMa2),
    (ActorFunc)EnMa2_Init,
    (ActorFunc)EnMa2_Destroy,
    (ActorFunc)EnMa2_Update,
    (ActorFunc)EnMa2_Draw,
    (ActorFunc)EnMa2_Reset,
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
    { 18, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

static struct_D_80AA1678 sAnimationInfo[] = {
    { &gMalonAdultIdleAnim, 1.0f, ANIMMODE_LOOP, 0.0f },       { &gMalonAdultIdleAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gMalonAdultStandStillAnim, 1.0f, ANIMMODE_LOOP, 0.0f }, { &gMalonAdultSingAnim, 1.0f, ANIMMODE_LOOP, 0.0f },
    { &gMalonAdultSingAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
};

u16 func_80AA19A0(GlobalContext* globalCtx, Actor* thisx) {
    u16 faceReaction = Text_GetFaceReaction(globalCtx, 23);

    if (faceReaction != 0) {
        return faceReaction;
    }
    if (gSaveContext.eventChkInf[1] & 0x100) {
        return 0x2056;
    }
    if (IS_NIGHT) {
        if (gSaveContext.infTable[8] & 0x1000) {
            return 0x2052;
        } else if (gSaveContext.infTable[8] & 0x4000) {
            return 0x2051;
        } else {
            return 0x2050;
        }
    }
    return 0x204C;
}

s16 func_80AA1A38(GlobalContext* globalCtx, Actor* thisx) {
    s16 ret = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_CLOSING:
            switch (thisx->textId) {
                case 0x2051:
                    gSaveContext.infTable[8] |= 0x1000;
                    ret = 2;
                    break;
                case 0x2053:
                    gSaveContext.infTable[8] |= 0x2000;
                    ret = 0;
                    break;
                default:
                    ret = 0;
                    break;
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_CHOICE:
        case TEXT_STATE_EVENT:
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_9:
            break;
    }
    return ret;
}

void func_80AA1AE4(EnMa2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 phi_a3;

    if ((pthis->unk_1E0.unk_00 == 0) && (pthis->skelAnime.animation == &gMalonAdultSingAnim)) {
        phi_a3 = 1;
    } else {
        phi_a3 = 0;
    }

    pthis->unk_1E0.unk_18 = player->actor.world.pos;
    pthis->unk_1E0.unk_14 = 0.0f;

    func_80034A14(&pthis->actor, &pthis->unk_1E0, 0, phi_a3);
}

u16 func_80AA1B58(EnMa2* pthis, GlobalContext* globalCtx) {
    if (LINK_IS_CHILD) {
        return 0;
    }
    if (!(gSaveContext.eventChkInf[1] & 0x100) && (globalCtx->sceneNum == SCENE_MALON_STABLE) && IS_DAY &&
        (pthis->actor.shape.rot.z == 5)) {
        return 1;
    }
    if (!(gSaveContext.eventChkInf[1] & 0x100) && (globalCtx->sceneNum == SCENE_SPOT20) && IS_NIGHT &&
        (pthis->actor.shape.rot.z == 6)) {
        return 2;
    }
    if (!(gSaveContext.eventChkInf[1] & 0x100) || (globalCtx->sceneNum != SCENE_SPOT20)) {
        return 0;
    }
    if ((pthis->actor.shape.rot.z == 7) && IS_DAY) {
        return 3;
    }
    if ((pthis->actor.shape.rot.z == 8) && IS_NIGHT) {
        return 3;
    }
    return 0;
}

s32 func_80AA1C68(EnMa2* pthis) {
    if (pthis->skelAnime.animation != &gMalonAdultSingAnim) {
        return 0;
    }
    if (pthis->unk_1E0.unk_00 != 0) {
        return 0;
    }
    pthis->blinkTimer = 0;
    if (pthis->eyeIndex != 2) {
        return 0;
    }
    pthis->mouthIndex = 2;
    return 1;
}

void EnMa2_UpdateEyes(EnMa2* pthis) {
    if ((!func_80AA1C68(pthis)) && (DECR(pthis->blinkTimer) == 0)) {
        pthis->eyeIndex += 1;
        if (pthis->eyeIndex >= 3) {
            pthis->blinkTimer = Rand_S16Offset(30, 30);
            pthis->eyeIndex = 0;
        }
    }
}

void EnMa2_ChangeAnim(EnMa2* pthis, s32 idx) {
    f32 frameCount = Animation_GetLastFrame(sAnimationInfo[idx].animation);

    Animation_Change(&pthis->skelAnime, sAnimationInfo[idx].animation, 1.0f, 0.0f, frameCount, sAnimationInfo[idx].mode,
                     sAnimationInfo[idx].transitionRate);
}

void func_80AA1DB4(EnMa2* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.animation == &gMalonAdultSingAnim) {
        if (pthis->unk_1E0.unk_00 == 0) {
            if (pthis->unk_20A != 0) {
                func_800F6584(0);
                pthis->unk_20A = 0;
            }
        } else {
            if (pthis->unk_20A == 0) {
                func_800F6584(1);
                pthis->unk_20A = 1;
            }
        }
    }
}

void EnMa2_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMa2* pthis = (EnMa2*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gMalonAdultSkel, NULL, NULL, NULL, 0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(22), &sColChkInfoInit);

    switch (func_80AA1B58(pthis, globalCtx)) {
        case 1:
            EnMa2_ChangeAnim(pthis, 2);
            pthis->actionFunc = func_80AA2018;
            break;
        case 2:
            EnMa2_ChangeAnim(pthis, 3);
            pthis->actionFunc = func_80AA204C;
            break;
        case 3:
            if (gSaveContext.infTable[8] & 0x2000) {
                EnMa2_ChangeAnim(pthis, 0);
            } else {
                EnMa2_ChangeAnim(pthis, 3);
            }
            pthis->actionFunc = func_80AA2018;
            break;
        case 0:
            Actor_Kill(&pthis->actor);
            return;
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.targetMode = 6;
    pthis->unk_1E0.unk_00 = 0;
}

void EnMa2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMa2* pthis = (EnMa2*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AA2018(EnMa2* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 2) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->unk_1E0.unk_00 = 0;
    }
}

void func_80AA204C(EnMa2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->stateFlags2 & 0x1000000) {
        player->unk_6A8 = &pthis->actor;
        player->stateFlags2 |= 0x2000000;
        func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_EPONA);
        pthis->actionFunc = func_80AA20E4;
    } else if (pthis->actor.xzDistToPlayer < 30.0f + (f32)pthis->collider.dim.radius) {
        player->stateFlags2 |= 0x800000;
    }
}

void func_80AA20E4(EnMa2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_04) {
        pthis->actionFunc = func_80AA204C;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
        Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->unk_208 = 0x1E;
        gSaveContext.infTable[8] |= 0x4000;
        pthis->actionFunc = func_80AA21C8;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else {
        player->stateFlags2 |= 0x800000;
    }
}

void func_80AA21C8(EnMa2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (DECR(pthis->unk_208)) {
        player->stateFlags2 |= 0x800000;
    } else {
        if (pthis->unk_1E0.unk_00 == 0) {
            pthis->actor.flags |= ACTOR_FLAG_16;
            Message_CloseTextbox(globalCtx);
        } else {
            pthis->actor.flags &= ~ACTOR_FLAG_16;
            pthis->actionFunc = func_80AA2018;
        }
    }
}

void EnMa2_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMa2* pthis = (EnMa2*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);
    EnMa2_UpdateEyes(pthis);
    pthis->actionFunc(pthis, globalCtx);
    func_80AA1DB4(pthis, globalCtx);
    func_80AA1AE4(pthis, globalCtx);
    if (pthis->actionFunc != func_80AA20E4) {
        func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E0.unk_00, (f32)pthis->collider.dim.radius + 30.0f,
                      func_80AA19A0, func_80AA1A38);
    }
}

s32 EnMa2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMa2* pthis = (EnMa2*)thisx;
    Vec3s vec;

    if ((limbIndex == MALON_ADULT_LEFT_THIGH_LIMB) || (limbIndex == MALON_ADULT_RIGHT_THIGH_LIMB)) {
        *dList = NULL;
    }
    if (limbIndex == MALON_ADULT_HEAD_LIMB) {
        Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec = pthis->unk_1E0.unk_08;
        Matrix_RotateX((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }
    if (limbIndex == MALON_ADULT_CHEST_AND_NECK_LIMB) {
        vec = pthis->unk_1E0.unk_0E;
        Matrix_RotateY((-vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateX((-vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
    }
    if ((limbIndex == MALON_ADULT_CHEST_AND_NECK_LIMB) || (limbIndex == MALON_ADULT_LEFT_SHOULDER_LIMB) ||
        (limbIndex == MALON_ADULT_RIGHT_SHOULDER_LIMB)) {
        rot->y += Math_SinS(pthis->unk_212[limbIndex].y) * 200.0f;
        rot->z += Math_CosS(pthis->unk_212[limbIndex].z) * 200.0f;
    }
    return false;
}

void EnMa2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnMa2* pthis = (EnMa2*)thisx;
    Vec3f vec = { 900.0f, 0.0f, 0.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ma2.c", 904);

    if (limbIndex == MALON_ADULT_HEAD_LIMB) {
        Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
    }
    if ((limbIndex == MALON_ADULT_LEFT_HAND_LIMB) && (pthis->skelAnime.animation == &gMalonAdultStandStillAnim)) {
        gSPDisplayList(POLY_OPA_DISP++, gMalonAdultBasketDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ma2.c", 927);
}

void EnMa2_Draw(Actor* thisx, GlobalContext* globalCtx) {

    EnMa2* pthis = (EnMa2*)thisx;
    Camera* camera;
    f32 someFloat;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ma2.c", 955);

    camera = GET_ACTIVE_CAM(globalCtx);
    someFloat = Math_Vec3f_DistXZ(&pthis->actor.world.pos, &camera->eye);
    func_800F6268(someFloat, NA_BGM_LONLON);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sMouthTextures_53[pthis->mouthIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures_53[pthis->eyeIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnMa2_OverrideLimbDraw, EnMa2_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ma2.c", 990);
}

void EnMa2_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ma2_InitVars = {
        ACTOR_EN_MA2,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_MA2,
        sizeof(EnMa2),
        (ActorFunc)EnMa2_Init,
        (ActorFunc)EnMa2_Destroy,
        (ActorFunc)EnMa2_Update,
        (ActorFunc)EnMa2_Draw,
        (ActorFunc)EnMa2_Reset,
    };

    sCylinderInit = {
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
        { 18, 46, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

}

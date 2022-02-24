#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MA3_Z_EN_MA3_C
#include "actor_common.h"
/*
 * File: z_en_ma3.c
 * Overlay: En_Ma3
 * Description: Adult Malon (Ranch)
 */

#include "z_en_ma3.h"
#include "objects/object_ma2/object_ma2.h"
#include "def/audio.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnMa3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMa3_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMa3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMa3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMa3_Draw(Actor* thisx, GlobalContext* globalCtx);

u16 func_80AA2AA0(GlobalContext* globalCtx, Actor* pthis);
s16 func_80AA2BD4(GlobalContext* globalCtx, Actor* pthis);

void func_80AA2E54(EnMa3* pthis, GlobalContext* globalCtx);
s32 func_80AA2EC8(EnMa3* pthis, GlobalContext* globalCtx);
s32 func_80AA2F28(EnMa3* pthis);
void EnMa3_UpdateEyes(EnMa3* pthis);
void EnMa3_ChangeAnim(EnMa3* pthis, s32 arg1);
void func_80AA3200(EnMa3* pthis, GlobalContext* globalCtx);

static void* sMouthTextures_47[] = { gMalonAdultMouthNeutralTex, gMalonAdultMouthSadTex, gMalonAdultMouthHappyTex };

static void* sEyeTextures_47[] = { gMalonAdultEyeOpenTex, gMalonAdultEyeHalfTex, gMalonAdultEyeClosedTex };


ActorInit En_Ma3_InitVars = {
    ACTOR_EN_MA3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MA2,
    sizeof(EnMa3),
    (ActorFunc)EnMa3_Init,
    (ActorFunc)EnMa3_Destroy,
    (ActorFunc)EnMa3_Update,
    (ActorFunc)EnMa3_Draw,
    (ActorFunc)EnMa3_Reset,
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

u16 func_80AA2AA0(GlobalContext* globalCtx, Actor* thisx) {
    Player* player = GET_PLAYER(globalCtx);
    s16* timer1ValuePtr; // weirdness with pthis necessary to match

    if (!(gSaveContext.infTable[11] & 0x100)) {
        return 0x2000;
    }
    timer1ValuePtr = &gSaveContext.timer1Value;
    if (gSaveContext.eventInf[0] & 0x400) {
        gSaveContext.timer1Value = gSaveContext.timer1Value;
        thisx->flags |= ACTOR_FLAG_16;
        if (gSaveContext.timer1Value >= 0xD3) {
            return 0x208E;
        }
        if ((HIGH_SCORE(HS_HORSE_RACE) == 0) || (HIGH_SCORE(HS_HORSE_RACE) >= 0xB4)) {
            HIGH_SCORE(HS_HORSE_RACE) = 0xB4;
            gSaveContext.timer1Value = *timer1ValuePtr;
        }
        if (!(gSaveContext.eventChkInf[1] & 0x4000) && (gSaveContext.timer1Value < 0x32)) {
            return 0x208F;
        } else if (gSaveContext.timer1Value < HIGH_SCORE(HS_HORSE_RACE)) {
            return 0x2012;
        } else {
            return 0x2004;
        }
    }
    if ((!(player->stateFlags1 & 0x800000)) &&//Not mounted on a horse?
        (Actor_FindNearby(globalCtx, thisx, ACTOR_EN_HORSE, 1, 1200.0f) == NULL)) {
        return 0x2001;
    }
    if (!(gSaveContext.infTable[11] & 0x200)) {
        return 0x2002;
    } else {
        return 0x2003;
    }
}

s16 func_80AA2BD4(GlobalContext* globalCtx, Actor* thisx) {
    s16 ret = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx)) {
                globalCtx->nextEntranceIndex = 0x157;
                gSaveContext.nextCutsceneIndex = 0xFFF0;
                globalCtx->fadeTransition = 0x26;
                globalCtx->sceneLoadFlag = 0x14;
                gSaveContext.eventInf[0] |= 0x400;
                gSaveContext.timer1State = 0xF;
            }
            break;
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx)) {
                gSaveContext.infTable[11] |= 0x200;
                if (globalCtx->msgCtx.choiceIndex == 0) {
                    if (gSaveContext.eventChkInf[1] & 0x4000) {
                        Message_ContinueTextbox(globalCtx, 0x2091);
                    } else if (HIGH_SCORE(HS_HORSE_RACE) == 0) {
                        Message_ContinueTextbox(globalCtx, 0x2092);
                    } else {
                        Message_ContinueTextbox(globalCtx, 0x2090);
                    }
                }
            }
            break;
        case TEXT_STATE_CLOSING:
            switch (thisx->textId) {
                case 0x2000:
                    gSaveContext.infTable[11] |= 0x100;
                    ret = 0;
                    break;
                case 0x208F:
                    gSaveContext.eventChkInf[1] |= 0x4000;
                case 0x2004:
                case 0x2012:
                    if (HIGH_SCORE(HS_HORSE_RACE) > gSaveContext.timer1Value) {
                        HIGH_SCORE(HS_HORSE_RACE) = gSaveContext.timer1Value;
                    }
                case 0x208E:
                    gSaveContext.eventInf[0] &= ~0x400;
                    thisx->flags &= ~ACTOR_FLAG_16;
                    ret = 0;
                    gSaveContext.timer1State = 0xA;
                    break;
                case 0x2002:
                    gSaveContext.infTable[11] |= 0x200;
                case 0x2003:
                    if (!(gSaveContext.eventInf[0] & 0x400)) {
                        ret = 0;
                    }
                    break;
                default:
                    ret = 0;
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            break;
    }
    return ret;
}

void func_80AA2E54(EnMa3* pthis, GlobalContext* globalCtx) {
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

s32 func_80AA2EC8(EnMa3* pthis, GlobalContext* globalCtx) {
    if (LINK_IS_CHILD) {
        return 2;
    }
    if (!(gSaveContext.eventChkInf[1] & 0x100)) {
        return 2;
    }
    if (gSaveContext.eventInf[0] & 0x400) {
        return 1;
    }
    return 0;
}

s32 func_80AA2F28(EnMa3* pthis) {
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

void EnMa3_UpdateEyes(EnMa3* pthis) {
    if ((!func_80AA2F28(pthis)) && (DECR(pthis->blinkTimer) == 0)) {
        pthis->eyeIndex += 1;
        if (pthis->eyeIndex >= 3) {
            pthis->blinkTimer = Rand_S16Offset(30, 30);
            pthis->eyeIndex = 0;
        }
    }
}

void EnMa3_ChangeAnim(EnMa3* pthis, s32 idx) {
    f32 frameCount = Animation_GetLastFrame(sAnimationInfo[idx].animation);

    Animation_Change(&pthis->skelAnime, sAnimationInfo[idx].animation, 1.0f, 0.0f, frameCount, sAnimationInfo[idx].mode,
                     sAnimationInfo[idx].transitionRate);
}

void EnMa3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMa3* pthis = (EnMa3*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gMalonAdultSkel, NULL, NULL, NULL, 0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(22), &sColChkInfoInit);

    switch (func_80AA2EC8(pthis, globalCtx)) {
        case 0:
            EnMa3_ChangeAnim(pthis, 0);
            pthis->actionFunc = func_80AA3200;
            break;
        case 1:
            EnMa3_ChangeAnim(pthis, 0);
            pthis->actionFunc = func_80AA3200;
            break;
        case 2:
            Actor_Kill(&pthis->actor);
            return;
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->unk_1E0.unk_00 = (u16)0;
}

void EnMa3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMa3* pthis = (EnMa3*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AA3200(EnMa3* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 2) {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        pthis->unk_1E0.unk_00 = 0;
    }
}

void EnMa3_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMa3* pthis = (EnMa3*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);
    EnMa3_UpdateEyes(pthis);
    pthis->actionFunc(pthis, globalCtx);
    func_80AA2E54(pthis, globalCtx);
    func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E0.unk_00, (f32)pthis->collider.dim.radius + 150.0f,
                  func_80AA2AA0, func_80AA2BD4);
    if (pthis->unk_1E0.unk_00 == 0) {
        if (pthis->unk_20A != 0) {
            func_800F6584(0);
            pthis->unk_20A = 0;
        }
    } else if (pthis->unk_20A == 0) {
        func_800F6584(1);
        pthis->unk_20A = 1;
    }
}

s32 EnMa3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMa3* pthis = (EnMa3*)thisx;
    Vec3s vec;

    if ((limbIndex == MALON_ADULT_LIMB_LEFT_THIGH) || (limbIndex == MALON_ADULT_LIMB_RIGHT_THIGH)) {
        *dList = NULL;
    }
    if (limbIndex == MALON_ADULT_LIMB_HEAD) {
        Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec = pthis->unk_1E0.unk_08;
        Matrix_RotateX((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }
    if (limbIndex == MALON_ADULT_LIMB_CHEST_AND_NECK) {
        vec = pthis->unk_1E0.unk_0E;
        Matrix_RotateY((-vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateX((-vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
    }
    if ((limbIndex == MALON_ADULT_LIMB_CHEST_AND_NECK) || (limbIndex == MALON_ADULT_LIMB_LEFT_SHOULDER) ||
        (limbIndex == MALON_ADULT_LIMB_RIGHT_SHOULDER)) {
        rot->y += Math_SinS(pthis->unk_212[limbIndex].y) * 200.0f;
        rot->z += Math_CosS(pthis->unk_212[limbIndex].z) * 200.0f;
    }
    return false;
}

void EnMa3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnMa3* pthis = (EnMa3*)thisx;
    Vec3f vec = { 900.0f, 0.0f, 0.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ma3.c", 927);

    if (limbIndex == MALON_ADULT_LIMB_HEAD) {
        Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
    }

    if ((limbIndex == MALON_ADULT_LIMB_LEFT_HAND) && (pthis->skelAnime.animation == &gMalonAdultStandStillAnim)) {
        gSPDisplayList(POLY_OPA_DISP++, gMalonAdultBasketDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ma3.c", 950);
}

void EnMa3_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMa3* pthis = (EnMa3*)thisx;
    Camera* camera;
    f32 someFloat;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ma3.c", 978);

    camera = GET_ACTIVE_CAM(globalCtx);
    someFloat = Math_Vec3f_DistXZ(&pthis->actor.world.pos, &camera->eye);
    func_800F6268(someFloat, NA_BGM_LONLON);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sMouthTextures_47[pthis->mouthIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures_47[pthis->eyeIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnMa3_OverrideLimbDraw, EnMa3_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ma3.c", 1013);
}

void EnMa3_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ma3_InitVars = {
        ACTOR_EN_MA3,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_MA2,
        sizeof(EnMa3),
        (ActorFunc)EnMa3_Init,
        (ActorFunc)EnMa3_Destroy,
        (ActorFunc)EnMa3_Update,
        (ActorFunc)EnMa3_Draw,
        (ActorFunc)EnMa3_Reset,
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

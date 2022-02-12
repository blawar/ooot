#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_NIW_GIRL_Z_EN_NIW_GIRL_C
#include "actor_common.h"
/*
 * File: z_en_niw_girl.c
 * Overlay: ovl_En_Niw_Girl
 * Description: Girl that chases a cuckoo around in Hyrule Market and Kakariko Village
 */

#include "z_en_niw_girl.h"
#include "objects/object_gr/object_gr.h"
#include "vt.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnNiwGirl_Init(Actor* thisx, GlobalContext* globalCtx);
void EnNiwGirl_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnNiwGirl_Update(Actor* thisx, GlobalContext* globalCtx);
void EnNiwGirl_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnNiwGirl_Talk(EnNiwGirl* pthis, GlobalContext* globalCtx);
void func_80AB94D0(EnNiwGirl* pthis, GlobalContext* globalCtx);
void func_80AB9210(EnNiwGirl* pthis, GlobalContext* globalCtx);

ActorInit En_Niw_Girl_InitVars = {
    ACTOR_EN_NIW_GIRL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GR,
    sizeof(EnNiwGirl),
    (ActorFunc)EnNiwGirl_Init,
    (ActorFunc)EnNiwGirl_Destroy,
    (ActorFunc)EnNiwGirl_Update,
    (ActorFunc)EnNiwGirl_Draw,
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
    { 10, 30, 0, { 0, 0, 0 } },
};

void EnNiwGirl_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnNiwGirl* pthis = (EnNiwGirl*)thisx;
    s32 pad;
    Vec3f vec1;
    Vec3f vec2;
    s32 pad2;

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gNiwGirlSkel, &gNiwGirlRunAnim, pthis->jointTable, pthis->morphTable,
                       17);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->actor.targetMode = 6;
    if (pthis->actor.params < 0) {
        pthis->actor.params = 0;
    }
    pthis->path = ((pthis->actor.params >> 8) & 0xFF);
    pthis->actor.gravity = -3.0f;
    Matrix_RotateY((pthis->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_NEW);
    vec2.x = vec2.y = vec2.z = 0.0f;
    vec1.x = vec1.y = 0.0f;
    vec1.z = 50.0;
    Matrix_MultVec3f(&vec1, &vec2);
    pthis->chasedEnNiw = (EnNiw*)Actor_SpawnAsChild(
        &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_NIW, pthis->actor.world.pos.x + vec2.x,
        pthis->actor.world.pos.y + vec2.y, pthis->actor.world.pos.z + vec2.z, 0, pthis->actor.world.rot.y, 0, 0xA);
    if (pthis->chasedEnNiw != NULL) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ シツレイしちゃうわね！プンプン ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ きゃははははは、まてー ☆☆☆☆☆ %d\n" VT_RST, pthis->path);
        osSyncPrintf("\n\n");
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        pthis->actionFunc = EnNiwGirl_Talk;
    } else {
        osSyncPrintf("\n\n");
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ なぜか、セットできむぅあせん ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ んんがくく ☆☆☆☆☆ %d\n" VT_RST, pthis->path);
        osSyncPrintf("\n\n");
        Actor_Kill(&pthis->actor);
    }
}

void EnNiwGirl_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnNiwGirl_Jump(EnNiwGirl* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&gNiwGirlRunAnim);
    Animation_Change(&pthis->skelAnime, &gNiwGirlRunAnim, 1.0f, 0.0f, frameCount, 0, -10.0f);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = func_80AB9210;
}

void func_80AB9210(EnNiwGirl* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->path];
    f32 xDistBetween;
    f32 zDistBetween;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachF(&pthis->actor.speedXZ, 3.0f, 0.2f, 0.4f);

    // Find the X and Z distance between the girl and the cuckoo she is chasing
    xDistBetween = pthis->chasedEnNiw->actor.world.pos.x - pthis->actor.world.pos.x;
    zDistBetween = pthis->chasedEnNiw->actor.world.pos.z - pthis->actor.world.pos.z;
    if (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_NONE) {
        pthis->chasedEnNiw->path = 0;
    }
    if (sqrtf(SQ(xDistBetween) + SQ(zDistBetween)) < 70.0f) {
        pthis->chasedEnNiw->path = (pthis->path + 1);
        pthis->chasedEnNiw->unk_2EC = path->count;
    } else if (sqrtf(SQ(xDistBetween) + SQ(zDistBetween)) > 150.0f) {
        pthis->chasedEnNiw->path = 0;
    }

    // Change her angle so that she is always facing the cuckoo
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(xDistBetween, zDistBetween) * (0x8000 / M_PI), 3,
                       pthis->unk_27C, 0);
    Math_ApproachF(&pthis->unk_27C, 5000.0f, 30.0f, 150.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

    // Only allow Link to talk to her when she is playing the jumping animation
    if ((pthis->jumpTimer == 0) || (Player_GetMask(globalCtx) != PLAYER_MASK_NONE)) {
        pthis->jumpTimer = 60;
        pthis->actionFunc = EnNiwGirl_Talk;
    }
}

void EnNiwGirl_Talk(EnNiwGirl* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gNiwGirlJumpAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gNiwGirlJumpAnim), 0,
                     -10.0f);
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actor.textId = 0x7000;
    if ((gSaveContext.eventChkInf[8] & 1) && (pthis->unk_27A == 0)) {
        pthis->actor.textId = 0x70EA;
    }
    switch (Player_GetMask(globalCtx)) {
        case PLAYER_MASK_KEATON:
            pthis->actor.textId = 0x7118;
            break;
        case PLAYER_MASK_SPOOKY:
            pthis->actor.textId = 0x7119;
            break;
        case PLAYER_MASK_BUNNY:
        case PLAYER_MASK_ZORA:
        case PLAYER_MASK_GERUDO:
            pthis->actor.textId = 0x711A;
            break;
        case PLAYER_MASK_SKULL:
        case PLAYER_MASK_GORON:
        case PLAYER_MASK_TRUTH:
            pthis->actor.textId = 0x711B;
            break;
    }
    pthis->unk_270 = 6;
    pthis->actionFunc = func_80AB94D0;
}

void func_80AB94D0(EnNiwGirl* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_NONE) {
        pthis->chasedEnNiw->path = 0;
    }
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.8f, 0.2f);
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->actor.textId == 0x70EA) {
            pthis->unk_27A = 1;
        }
    } else {
        if ((pthis->jumpTimer == 0) && Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE) {
            pthis->jumpTimer = Rand_ZeroFloat(100.0f) + 250.0f;
            pthis->actionFunc = EnNiwGirl_Jump;
        } else {
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
        }
    }
}

void EnNiwGirl_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnNiwGirl* pthis = (EnNiwGirl*)thisx;
    EnNiwGirlActionFunc tempActionFunc;
    Player* player = GET_PLAYER(globalCtx);

    Actor_SetScale(&pthis->actor, 0.013f);
    pthis->unkUpTimer++;
    tempActionFunc = func_80AB94D0;
    if (pthis->blinkTimer == 0) {
        pthis->eyeIndex++;
        if (pthis->eyeIndex >= 3) {
            pthis->eyeIndex = 0;
            pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }
    pthis->unk_280 = 30.0f;
    Actor_SetFocus(&pthis->actor, 30.0f);
    if (tempActionFunc == pthis->actionFunc) {
        pthis->unk_2D4.unk_18 = player->actor.world.pos;
        if (!LINK_IS_ADULT) {
            pthis->unk_2D4.unk_18.y = player->actor.world.pos.y - 10.0f;
        }
        func_80034A14(&pthis->actor, &pthis->unk_2D4, 2, 4);
        pthis->unk_260 = pthis->unk_2D4.unk_08;
        pthis->unk_266 = pthis->unk_2D4.unk_0E;
    } else {
        Math_SmoothStepToS(&pthis->unk_266.y, 0, 5, 3000, 0);
        Math_SmoothStepToS(&pthis->unk_260.y, 0, 5, 3000, 0);
        Math_SmoothStepToS(&pthis->unk_260.z, 0, 5, 3000, 0);
    }
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    }
    if (pthis->jumpTimer != 0) {
        pthis->jumpTimer--;
    }
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 100.0f, 100.0f, 200.0f, 0x1C);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnNiwGirlOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                              void* thisx) {
    EnNiwGirl* pthis = (EnNiwGirl*)thisx;

    if (limbIndex == 3) {
        rot->x += pthis->unk_266.y;
    }
    if (limbIndex == 4) {
        rot->x += pthis->unk_260.y;
        rot->z += pthis->unk_260.z;
    }
    return false;
}

static Vec3f sConstVec3f = { 0.2f, 0.2f, 0.2f };

void EnNiwGirl_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = { gNiwGirlEyeOpenTex, gNiwGirlEyeHalfTex, gNiwGirlEyeClosedTex };
    EnNiwGirl* pthis = (EnNiwGirl*)thisx;
    s32 pad;
    Vec3f sp4C = sConstVec3f;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_niw_girl.c", 573);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnNiwGirlOverrideLimbDraw, NULL, pthis);
    func_80033C30(&pthis->actor.world.pos, &sp4C, 255, globalCtx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_niw_girl.c", 592);
}

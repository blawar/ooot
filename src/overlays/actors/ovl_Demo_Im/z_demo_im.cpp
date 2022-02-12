#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_IM_Z_DEMO_IM_C
#include "actor_common.h"
/*
 * File: z_demo_im.c
 * Overlay: Demo_Im
 * Description: Impa
 */

#include "z_demo_im.h"
#include "overlays/actors/ovl_En_Arrow/z_en_arrow.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "scenes/indoors/nakaniwa/nakaniwa_scene.h"
#include "objects/object_im/object_im.h"
#include "vt.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_4)

void DemoIm_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoIm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoIm_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoIm_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_809856F8(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985718(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985738(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985770(DemoIm* pthis, GlobalContext* globalCtx);
void func_809857B0(DemoIm* pthis, GlobalContext* globalCtx);
void func_809857F0(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985830(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985C10(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985C40(DemoIm* pthis, GlobalContext* globalCtx);
void func_80985C94(DemoIm* pthis, GlobalContext* globalCtx);
void DemoIm_DrawTranslucent(DemoIm* pthis, GlobalContext* globalCtx);
void func_809863BC(DemoIm* pthis, GlobalContext* globalCtx);
void func_809863DC(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986430(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986494(DemoIm* pthis, GlobalContext* globalCtx);
void func_809864D4(DemoIm* pthis, GlobalContext* globalCtx);
void func_809868E8(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986908(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986948(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986D40(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986DC8(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986E20(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986E40(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986EAC(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986F08(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986F28(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986F88(DemoIm* pthis, GlobalContext* globalCtx);
void func_80986FA8(DemoIm* pthis, GlobalContext* globalCtx);
void func_80987288(DemoIm* pthis, GlobalContext* globalCtx);
void func_809872A8(DemoIm* pthis, GlobalContext* globalCtx);
void func_809872F0(DemoIm* pthis, GlobalContext* globalCtx);
void func_80987330(DemoIm* pthis, GlobalContext* globalCtx);
void DemoIm_DrawNothing(DemoIm* pthis, GlobalContext* globalCtx);
void DemoIm_DrawSolid(DemoIm* pthis, GlobalContext* globalCtx);

static void* sEyeTextures[] = {
    gImpaEyeOpenTex,
    gImpaEyeHalfTex,
    gImpaEyeClosedTex,
};

static u32 D_8098783C = 0;

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 25, 80, 0, { 0, 0, 0 } },
};

#include "z_demo_im_cutscene_data.cpp" EARLY

static DemoImActionFunc sActionFuncs[] = {
    func_809856F8, func_80985718, func_80985738, func_80985770, func_809857B0, func_809857F0, func_80985830,
    func_80985C10, func_80985C40, func_80985C94, func_809863BC, func_809863DC, func_80986430, func_80986494,
    func_809864D4, func_809868E8, func_80986908, func_80986948, func_80986D40, func_80986DC8, func_80986E20,
    func_80986E40, func_80986EAC, func_80986F08, func_80986F28, func_80986F88, func_80986FA8, func_80987288,
    func_809872A8, func_809872F0, func_80987330,
};

static Vec3f D_809887D8 = { 0.0f, 10.0f, 0.0f };

static DemoImDrawFunc sDrawFuncs[] = {
    DemoIm_DrawNothing,
    DemoIm_DrawSolid,
    DemoIm_DrawTranslucent,
};

ActorInit Demo_Im_InitVars = {
    ACTOR_DEMO_IM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_IM,
    sizeof(DemoIm),
    (ActorFunc)DemoIm_Init,
    (ActorFunc)DemoIm_Destroy,
    (ActorFunc)DemoIm_Update,
    (ActorFunc)DemoIm_Draw,
};

void func_80984BE0(DemoIm* pthis) {
    s32 pad[3];
    s16* blinkTimer = &pthis->blinkTimer;
    s16* eyeIndex = &pthis->eyeIndex;

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(60, 60);
    }

    *eyeIndex = *blinkTimer;
    if (*eyeIndex >= 3) {
        *eyeIndex = 0;
    }
}

void func_80984C68(DemoIm* pthis) {
    pthis->action = 7;
    pthis->drawConfig = 0;
    pthis->alpha = 0;
    pthis->unk_270 = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->unk_268 = 0.0f;
}

void func_80984C8C(DemoIm* pthis, GlobalContext* globalCtx) {
    u32* something = &D_8098783C;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        if (*something != 0) {
            if (pthis->actor.params == 2) {
                func_80984C68(pthis);
            }
            *something = 0;
        }
    } else {
        if (*something == 0) {
            *something = 1;
        }
    }
}

void DemoIm_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm* pthis = (DemoIm*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
}

void DemoIm_DestroyCollider(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm* pthis = (DemoIm*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void DemoIm_UpdateCollider(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 pad[5];

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void func_80984DB8(DemoIm* pthis) {
    s32 pad[2];
    Vec3s* vec1 = &pthis->unk_2D4.unk_08;
    Vec3s* vec2 = &pthis->unk_2D4.unk_0E;

    Math_SmoothStepToS(&vec1->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&vec1->y, 0, 20, 6200, 100);

    Math_SmoothStepToS(&vec2->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&vec2->y, 0, 20, 6200, 100);
}

void func_80984E58(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff;
    s16 phi_a3;

    pthis->unk_2D4.unk_18 = player->actor.world.pos;
    pthis->unk_2D4.unk_14 = kREG(16) + 4.0f;

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    phi_a3 = (ABS(yawDiff) < 0x18E3) ? 2 : 1;
    func_80034A14(&pthis->actor, &pthis->unk_2D4, kREG(17) + 0xC, phi_a3);
}

void func_80984F10(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_2D4.unk_18 = player->actor.world.pos;
    pthis->unk_2D4.unk_14 = kREG(16) + 12.0f;

    func_80034A14(&pthis->actor, &pthis->unk_2D4, kREG(17) + 0xC, 2);
}

void func_80984F94(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_2D4.unk_18 = player->actor.world.pos;
    pthis->unk_2D4.unk_14 = kREG(16) + 4.0f;
    func_80034A14(&pthis->actor, &pthis->unk_2D4, kREG(17) + 0xC, 4);
}

void DemoIm_UpdateBgCheckInfo(DemoIm* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 DemoIm_UpdateSkelAnime(DemoIm* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

s32 DemoIm_IsCsStateIdle(GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        return true;
    } else {
        return false;
    }
}

CsCmdActorAction* DemoIm_GetNpcAction(GlobalContext* globalCtx, s32 actionIdx) {
    s32 pad[2];
    CsCmdActorAction* ret = NULL;

    if (!DemoIm_IsCsStateIdle(globalCtx)) {
        ret = globalCtx->csCtx.npcActions[actionIdx];
    }
    return ret;
}

s32 func_809850E8(DemoIm* pthis, GlobalContext* globalCtx, u16 action, s32 actionIdx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        if (npcAction->action == action) {
            return true;
        }
    }
    return false;
}

s32 func_80985134(DemoIm* pthis, GlobalContext* globalCtx, u16 action, s32 actionIdx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        if (npcAction->action != action) {
            return true;
        }
    }
    return false;
}

void func_80985180(DemoIm* pthis, GlobalContext* globalCtx, s32 actionIdx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

void func_80985200(DemoIm* pthis, GlobalContext* globalCtx, s32 actionIdx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

void DemoIm_ChangeAnim(DemoIm* pthis, AnimationHeader* animHeaderSeg, u8 animMode, f32 transitionRate,
                       s32 playBackwards) {
    f32 frameCount = Animation_GetLastFrame(animHeaderSeg);
    f32 playbackSpeed;
    f32 startFrame;
    f32 endFrame;

    if (!playBackwards) {
        startFrame = 0.0f;
        endFrame = frameCount;
        playbackSpeed = 1.0f;
    } else {
        endFrame = 0.0f;
        startFrame = frameCount;
        playbackSpeed = -1.0f;
    }

    Animation_Change(&pthis->skelAnime, animHeaderSeg, playbackSpeed, startFrame, endFrame, animMode, transitionRate);
}

void func_80985310(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->actor.shape.yOffset = -10000.0f;
}

void func_80985358(DemoIm* pthis, GlobalContext* globalCtx) {
    f32 posX = pthis->actor.world.pos.x;
    f32 posY = pthis->actor.world.pos.y;
    f32 posZ = pthis->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, posX, posY, posZ, 0, 0, 0,
                       WARP_SAGES);
}

void func_809853B4(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerX = player->actor.world.pos.x;
    f32 playerY = player->actor.world.pos.y + 80.0f;
    f32 playerZ = player->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_EFFECT, playerX, playerY, playerZ, 0,
                       0, 0, 0xD);
    Item_Give(globalCtx, ITEM_MEDALLION_SHADOW);
}

void func_80985430(DemoIm* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.yOffset += 250.0f / 3.0f;
}

void func_8098544C(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 pad[2];

    if ((gSaveContext.chamberCutsceneNum == 4) && (gSaveContext.sceneSetupIndex < 4)) {
        Player* player = GET_PLAYER(globalCtx);

        pthis->action = 1;
        globalCtx->csCtx.segment = D_8098786C;
        gSaveContext.cutsceneTrigger = 2;
        Item_Give(globalCtx, ITEM_MEDALLION_SHADOW);
        player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    }
}

void func_809854DC(DemoIm* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[5] != NULL) &&
        (globalCtx->csCtx.npcActions[5]->action == 2)) {
        Animation_Change(&pthis->skelAnime, &gImpaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        pthis->action = 2;
        pthis->drawConfig = 1;
        func_80985358(pthis, globalCtx);
    }
}

void func_8098557C(DemoIm* pthis) {
    if (pthis->actor.shape.yOffset >= 0.0f) {
        pthis->action = 3;
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void func_809855A8(DemoIm* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[5] != NULL) &&
        (globalCtx->csCtx.npcActions[5]->action == 3)) {
        Animation_Change(&pthis->skelAnime, &gImpaRaiseArmsAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaRaiseArmsAnim),
                         ANIMMODE_ONCE, 4.0f);
        pthis->action = 4;
    }
}

void func_80985640(DemoIm* pthis, s32 arg1) {
    if (arg1 != 0) {
        Animation_Change(&pthis->skelAnime, &gImpaPresentShadowMedallionAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gImpaPresentShadowMedallionAnim), ANIMMODE_LOOP, 0.0f);
        pthis->action = 5;
    }
}

void func_809856AC(DemoIm* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[6] != NULL) &&
        (globalCtx->csCtx.npcActions[6]->action == 2)) {
        pthis->action = 6;
        func_809853B4(pthis, globalCtx);
    }
}

void func_809856F8(DemoIm* pthis, GlobalContext* globalCtx) {
    func_8098544C(pthis, globalCtx);
}

void func_80985718(DemoIm* pthis, GlobalContext* globalCtx) {
    func_809854DC(pthis, globalCtx);
}

void func_80985738(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80985430(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_8098557C(pthis);
}

void func_80985770(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809855A8(pthis, globalCtx);
}

void func_809857B0(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 sp1C;

    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    sp1C = DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80985640(pthis, sp1C);
}

void func_809857F0(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809856AC(pthis, globalCtx);
}

void func_80985830(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
}

void func_80985860(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->action = 7;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_809858A8(void) {
    func_800788CC(NA_SE_SY_WHITE_OUT_T);
}

void DemoIm_SpawnLightBall(DemoIm* pthis, GlobalContext* globalCtx) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                       (kREG(17) + 24.0f) + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 6);
}

void func_80985948(DemoIm* pthis, GlobalContext* globalCtx) {
    if (func_809850E8(pthis, globalCtx, 4, 5)) {
        Animation_Change(&pthis->skelAnime, &gImpaPrepareSealGanonAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gImpaPrepareSealGanonAnim), ANIMMODE_ONCE, 0.0f);
        pthis->action = 8;
        pthis->drawConfig = 2;
        pthis->alpha = 0;
        pthis->actor.shape.shadowAlpha = 0;
        pthis->unk_268 = 0.0f;
        func_809858A8();
    }
}

void func_809859E0(DemoIm* pthis, GlobalContext* globalCtx) {
    f32* unk_268 = &pthis->unk_268;
    s32 alpha = 255;

    if (func_809850E8(pthis, globalCtx, 4, 5)) {
        *unk_268 += 1.0f;
        if (*unk_268 >= kREG(5) + 10.0f) {
            pthis->action = 9;
            pthis->drawConfig = 1;
            *unk_268 = kREG(5) + 10.0f;
            pthis->alpha = pthis->actor.shape.shadowAlpha = alpha;
            return;
        }
    } else {
        *unk_268 -= 1.0f;
        if (*unk_268 <= 0.0f) {
            pthis->action = 7;
            pthis->drawConfig = 0;
            *unk_268 = 0.0f;
            pthis->alpha = 0;
            pthis->actor.shape.shadowAlpha = 0;
            return;
        }
    }
    pthis->actor.shape.shadowAlpha = pthis->alpha = (*unk_268 / (kREG(5) + 10.0f)) * 255.0f;
}

void func_80985B34(DemoIm* pthis, GlobalContext* globalCtx) {
    if (func_80985134(pthis, globalCtx, 4, 5)) {
        Animation_Change(&pthis->skelAnime, &gImpaSealGanonAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaSealGanonAnim),
                         ANIMMODE_ONCE, -8.0f);
        pthis->action = 8;
        pthis->drawConfig = 2;
        pthis->unk_268 = kREG(5) + 10.0f;
        pthis->alpha = 255;
        if (pthis->unk_270 == 0) {
            DemoIm_SpawnLightBall(pthis, globalCtx);
            pthis->unk_270 = 1;
        }
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_80985C10(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80985948(pthis, globalCtx);
    func_80984C8C(pthis, globalCtx);
}

void func_80985C40(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809859E0(pthis, globalCtx);
    func_80984C8C(pthis, globalCtx);
}

void func_80985C94(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80985B34(pthis, globalCtx);
    func_80984C8C(pthis, globalCtx);
}

void DemoIm_DrawTranslucent(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeIndex = pthis->eyeIndex;
    void* eyeTex = sEyeTextures[eyeIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_im_inKenjyanomaDemo02.c", 281);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTex));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
    gSPSegment(POLY_XLU_DISP++, 0x0C, &D_80116280[0]);

    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       NULL, NULL, NULL, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_im_inKenjyanomaDemo02.c", 308);
}

void func_80985E60(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->action = 10;
    pthis->unk_280 = 1;
}

void func_80985EAC(DemoIm* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.frames >= 80) && (globalCtx->csCtx.frames < 243)) {
        func_80984F10(pthis, globalCtx);
    } else {
        func_80984DB8(pthis);
    }
}

void func_80985EF4(DemoIm* pthis) {
    if (!Animation_OnFrame(&pthis->skelAnime, Animation_GetLastFrame(&gImpaWhistlingAnim) - 1.0f)) {
        DemoIm_UpdateSkelAnime(pthis);
    }
}

void func_80985F54(DemoIm* pthis) {
    pthis->action = 10;
    pthis->drawConfig = 0;
}

void func_80985F64(DemoIm* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gImpaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaIdleAnim),
                     ANIMMODE_LOOP, 0.0f);
    func_80985180(pthis, globalCtx, 5);
    pthis->action = 11;
    pthis->drawConfig = 1;
}

void func_80985FE8(DemoIm* pthis, s32 arg1) {
    if (arg1 != 0) {
        Animation_Change(&pthis->skelAnime, &gImpaWhistlingAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaWhistlingAnim),
                         ANIMMODE_LOOP, -8.0f);
    }
}

void func_8098604C(DemoIm* pthis) {
    f32 frameCount = Animation_GetLastFrame(&gImpaStartWhistlingAnim);

    Animation_Change(&pthis->skelAnime, &gImpaStartWhistlingAnim, 1.0f, 0.0f, frameCount, ANIMMODE_ONCE, -8.0f);
    pthis->action = 12;
    pthis->drawConfig = 1;
    pthis->unk_2D0 = 1;
}

void func_809860C8(DemoIm* pthis) {
    pthis->action = 13;
    pthis->drawConfig = 1;
}

void func_809860DC(DemoIm* pthis, s32 arg1) {
    if (arg1 != 0) {
        Animation_Change(&pthis->skelAnime, &gImpaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaIdleAnim),
                         ANIMMODE_LOOP, -8.0f);
        pthis->unk_2D0 = 0;
    }
}

void func_80986148(DemoIm* pthis) {
    Animation_Change(&pthis->skelAnime, &gImpaStartWhistlingAnim, -1.0f,
                     Animation_GetLastFrame(&gImpaStartWhistlingAnim), 0.0f, ANIMMODE_ONCE, -8.0f);
    pthis->action = 14;
    pthis->drawConfig = 1;
}

void func_809861C4(DemoIm* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, 5);

    if (npcAction != NULL) {
        u32 action = npcAction->action;
        u32 unk_274 = pthis->unk_274;

        if (action != unk_274) {
            switch (action) {
                case 9:
                    func_80986148(pthis);
                    break;
                case 7:
                    Animation_Change(&pthis->skelAnime, &gImpaWhistlingAnim, 1.0f, 0.0f,
                                     Animation_GetLastFrame(&gImpaWhistlingAnim), ANIMMODE_LOOP, -8.0f);
                    pthis->action = 12;
                    break;
                default:
                    osSyncPrintf("Demo_Im_Ocarina_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_274 = action;
        }
    }
}

void func_8098629C(DemoIm* pthis, GlobalContext* globalCtx) {
    if (DemoIm_IsCsStateIdle(globalCtx)) {
        pthis->action = 21;
        pthis->drawConfig = 1;
        pthis->unk_280 = 1;
    }
}

void func_809862E0(DemoIm* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, 5);

    if (npcAction != NULL) {
        u32 action = npcAction->action;
        u32 unk_274 = pthis->unk_274;

        if (action != unk_274) {
            switch (action) {
                case 1:
                    func_80985F54(pthis);
                    break;
                case 2:
                    func_80985F64(pthis, globalCtx);
                    break;
                case 7:
                    func_8098604C(pthis);
                    break;
                case 8:
                    func_809860C8(pthis);
                    break;
                case 9:
                    func_80986148(pthis);
                    break;
                default:
                    osSyncPrintf("Demo_Im_Ocarina_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_274 = action;
        }
    }
}

void func_809863BC(DemoIm* pthis, GlobalContext* globalCtx) {
    func_809862E0(pthis, globalCtx);
}

void func_809863DC(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80985EAC(pthis, globalCtx);
    func_80984BE0(pthis);
    func_809862E0(pthis, globalCtx);
}

void func_80986430(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 sp24;

    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    sp24 = DemoIm_UpdateSkelAnime(pthis);
    func_80985EAC(pthis, globalCtx);
    func_80984BE0(pthis);
    func_80985FE8(pthis, sp24);
    func_809862E0(pthis, globalCtx);
}

void func_80986494(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    func_80985EF4(pthis);
    func_80984BE0(pthis);
    func_809861C4(pthis, globalCtx);
}

void func_809864D4(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 sp24;

    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    sp24 = DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809860DC(pthis, sp24);
    func_8098629C(pthis, globalCtx);
}

void func_8098652C(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->action = 15;
}

void func_80986570(DemoIm* pthis, GlobalContext* globalCtx) {
    if (Animation_OnFrame(&pthis->skelAnime, 7.0f) && (pthis->actor.bgCheckFlags & 1)) {
        u32 sfxId = SFX_FLAG;

        sfxId += SurfaceType_GetSfx(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);
        Audio_PlaySoundGeneral(sfxId, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

void func_809865F8(DemoIm* pthis, GlobalContext* globalCtx, s32 arg2) {
    s32 pad[2];

    if (arg2 != 0) {
        f32* unk_278 = &pthis->unk_278;

        if (*unk_278 >= 0.0f) {
            if (pthis->unk_27C == 0) {
                Vec3f* thisPos = &pthis->actor.world.pos;
                s16 shapeRotY = pthis->actor.shape.rot.y;
                f32 spawnPosX = thisPos->x + (Math_SinS(shapeRotY) * 30.0f);
                f32 spawnPosY = thisPos->y;
                f32 spawnPosZ = thisPos->z + (Math_CosS(shapeRotY) * 30.0f);

                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ARROW, spawnPosX, spawnPosY, spawnPosZ, 0xFA0,
                            pthis->actor.shape.rot.y, 0, ARROW_CS_NUT);
                pthis->unk_27C = 1;
            }
        } else {
            *unk_278 += 1.0f;
        }
    }
}

void func_80986700(DemoIm* pthis) {
    pthis->action = 15;
    pthis->drawConfig = 0;
}

void func_80986710(DemoIm* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gImpaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gImpaIdleAnim),
                     ANIMMODE_LOOP, 0.0f);
    func_80985180(pthis, globalCtx, 5);
    pthis->action = 16;
    pthis->drawConfig = 1;
}

void func_80986794(DemoIm* pthis) {
    Animation_Change(&pthis->skelAnime, &gImpaThrowDekuNutAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gImpaThrowDekuNutAnim), ANIMMODE_ONCE, -8.0f);
    pthis->action = 17;
    pthis->drawConfig = 1;
}

void func_8098680C(DemoIm* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, 5);

    if (npcAction != NULL) {
        u32 action = npcAction->action;
        u32 unk_274 = pthis->unk_274;

        if (action != unk_274) {
            switch (action) {
                case 1:
                    func_80986700(pthis);
                    break;
                case 2:
                    func_80986710(pthis, globalCtx);
                    break;
                case 10:
                    func_80986794(pthis);
                    break;
                case 11:
                    Actor_Kill(&pthis->actor);
                    break;
                default:
                    osSyncPrintf("Demo_Im_Spot00_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_274 = action;
        }
    }
}

void func_809868E8(DemoIm* pthis, GlobalContext* globalCtx) {
    func_8098680C(pthis, globalCtx);
}

void func_80986908(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_8098680C(pthis, globalCtx);
}

void func_80986948(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 sp24;

    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    sp24 = DemoIm_UpdateSkelAnime(pthis);
    func_80986570(pthis, globalCtx);
    func_80984BE0(pthis);
    func_809865F8(pthis, globalCtx, sp24);
    func_8098680C(pthis, globalCtx);
}

void func_809869B0(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->action = 18;
    pthis->actor.shape.shadowAlpha = 0;
}

s32 func_809869F8(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerPosX = player->actor.world.pos.x;
    f32 thisPosX = pthis->actor.world.pos.x;

    if ((thisPosX - (kREG(16) + 30.0f) > playerPosX) && !(pthis->actor.flags & ACTOR_FLAG_UNCULLED)) {
        return true;
    } else {
        return false;
    }
}

s32 func_80986A5C(DemoIm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerPosX = player->actor.world.pos.x;
    f32 thisPosX = pthis->actor.world.pos.x;

    if ((thisPosX - (kREG(17) + 130.0f) < playerPosX) && (!Gameplay_InCsMode(globalCtx))) {
        return true;
    } else {
        return false;
    }
}

s32 func_80986AD0(DemoIm* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
    if (!Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actor.textId = 0x708E;
        func_8002F2F4(&pthis->actor, globalCtx);
    } else {
        return true;
    }
    return false;
}

void func_80986B2C(GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        Player* player = GET_PLAYER(globalCtx);

        globalCtx->nextEntranceIndex = 0xCD;
        globalCtx->fadeTransition = 38;
        globalCtx->sceneLoadFlag = 0x14;
        func_8002DF54(globalCtx, &player->actor, 8);
    }
}

void func_80986BA0(DemoIm* pthis, GlobalContext* globalCtx) {
    if (func_809869F8(pthis, globalCtx)) {
        pthis->action = 21;
        pthis->drawConfig = 1;
        pthis->unk_280 = 1;
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_80986BE4(DemoIm* pthis, s32 arg1) {
    if (arg1 != 0) {
        pthis->action = 22;
    }
}

void func_80986BF8(DemoIm* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.eventChkInf[4] & 1) {
        pthis->action = 24;
        pthis->drawConfig = 1;
        pthis->unk_280 = 1;
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_80986C30(DemoIm* pthis, GlobalContext* globalCtx) {
    if (func_80986A5C(pthis, globalCtx)) {
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gZeldasCourtyardLullabyCs);
        gSaveContext.cutsceneTrigger = 1;
        gSaveContext.eventChkInf[5] |= 0x200;
        Item_Give(globalCtx, ITEM_SONG_LULLABY);
        func_80985F54(pthis);
    }
}

void func_80986CC8(DemoIm* pthis) {
    if (gSaveContext.eventChkInf[4] & 1) {
        pthis->action = 26;
        pthis->drawConfig = 1;
        pthis->unk_280 = 1;
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_80986CFC(DemoIm* pthis, GlobalContext* globalCtx) {
    if (func_80986A5C(pthis, globalCtx)) {
        gSaveContext.eventChkInf[4] |= 0x1000;
        pthis->action = 19;
    }
}

void func_80986D40(DemoIm* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.sceneSetupIndex == 6) {
        pthis->action = 19;
        pthis->drawConfig = 1;
    } else if (gSaveContext.eventChkInf[8] & 1) {
        Actor_Kill(&pthis->actor);
    } else if (!(gSaveContext.eventChkInf[5] & 0x200)) {
        pthis->action = 23;
    } else {
        pthis->action = 20;
    }
}

void func_80986DC8(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80984E58(pthis, globalCtx);
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
}

void func_80986E20(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80986BA0(pthis, globalCtx);
}

void func_80986E40(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80984E58(pthis, globalCtx);
    DemoIm_UpdateCollider(pthis, globalCtx);
    func_80986BE4(pthis, func_80986AD0(pthis, globalCtx));
}

void func_80986EAC(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80984F94(pthis, globalCtx);
    DemoIm_UpdateCollider(pthis, globalCtx);
    func_80986B2C(globalCtx);
}

void func_80986F08(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80986BF8(pthis, globalCtx);
}

void func_80986F28(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80984E58(pthis, globalCtx);
    DemoIm_UpdateCollider(pthis, globalCtx);
    func_80986C30(pthis, globalCtx);
}

void func_80986F88(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80986CC8(pthis);
}

void func_80986FA8(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80984E58(pthis, globalCtx);
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
    DemoIm_UpdateCollider(pthis, globalCtx);
    func_80986CFC(pthis, globalCtx);
}

void func_80987018(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_ChangeAnim(pthis, &gImpaIdleAnim, ANIMMODE_LOOP, 0.0f, false);
    pthis->action = 27;
    pthis->drawConfig = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_80987064(DemoIm* pthis) {
    f32* unk_268 = &pthis->unk_268;
    f32 temp;
    s32 alpha = 255;

    *unk_268 += 1.0f;
    temp = kREG(17) + 10.0f;

    if (*unk_268 >= temp) {
        pthis->actor.shape.shadowAlpha = pthis->alpha = alpha;
    } else {
        pthis->actor.shape.shadowAlpha = pthis->alpha = (*unk_268 / temp) * 255.0f;
    }
}

void func_809870F0(DemoIm* pthis, GlobalContext* globalCtx) {
    func_80985200(pthis, globalCtx, 5);
    pthis->action = 28;
    pthis->drawConfig = 2;
}

void func_80987128(DemoIm* pthis) {
    if (pthis->unk_268 >= kREG(17) + 10.0f) {
        pthis->action = 29;
        pthis->drawConfig = 1;
    }
}

void func_80987174(DemoIm* pthis) {
    DemoIm_ChangeAnim(pthis, &object_im_Anim_0101C8, ANIMMODE_ONCE, -8.0f, false);
    pthis->action = 30;
}

void func_809871B4(DemoIm* pthis, s32 arg1) {
    if (arg1 != 0) {
        DemoIm_ChangeAnim(pthis, &object_im_Anim_00FB10, ANIMMODE_LOOP, 0.0f, false);
    }
}

void func_809871E8(DemoIm* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoIm_GetNpcAction(globalCtx, 5);

    if (npcAction != NULL) {
        u32 action = npcAction->action;
        u32 unk_274 = pthis->unk_274;

        if (action != unk_274) {
            switch (action) {
                case 12:
                    func_809870F0(pthis, globalCtx);
                    break;
                case 13:
                    func_80987174(pthis);
                    break;
                default:
                    osSyncPrintf("Demo_Im_inEnding_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_274 = action;
        }
    }
}

void func_80987288(DemoIm* pthis, GlobalContext* globalCtx) {
    func_809871E8(pthis, globalCtx);
}

void func_809872A8(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_80987064(pthis);
    func_80987128(pthis);
}

void func_809872F0(DemoIm* pthis, GlobalContext* globalCtx) {
    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809871E8(pthis, globalCtx);
}

void func_80987330(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 sp1C;

    DemoIm_UpdateBgCheckInfo(pthis, globalCtx);
    sp1C = DemoIm_UpdateSkelAnime(pthis);
    func_80984BE0(pthis);
    func_809871B4(pthis, sp1C);
}

void DemoIm_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm* pthis = (DemoIm*)thisx;

    if ((pthis->action < 0) || (pthis->action >= 31) || (sActionFuncs[pthis->action] == NULL)) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->action](pthis, globalCtx);
}

void DemoIm_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm* pthis = (DemoIm*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    DemoIm_InitCollider(thisx, globalCtx);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gImpaSkel, NULL, pthis->jointTable, pthis->morphTable, 17);
    thisx->flags &= ~ACTOR_FLAG_0;

    switch (pthis->actor.params) {
        case 2:
            func_80985860(pthis, globalCtx);
            break;
        case 3:
            func_80985E60(pthis, globalCtx);
            break;
        case 4:
            func_8098652C(pthis, globalCtx);
            break;
        case 5:
            func_809869B0(pthis, globalCtx);
            break;
        case 6:
            func_80987018(pthis, globalCtx);
            break;
        default:
            func_80985310(pthis, globalCtx);
    }
}

void DemoIm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm_DestroyCollider(thisx, globalCtx);
}

s32 DemoIm_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    DemoIm* pthis = (DemoIm*)thisx;
    s32* unk_2D0 = &pthis->unk_2D0;

    if (pthis->unk_280 != 0) {
        Vec3s* unk_2D4_unk_0E = &pthis->unk_2D4.unk_0E;
        Vec3s* unk_2D4_unk_08 = &pthis->unk_2D4.unk_08;

        switch (limbIndex) {
            case IMPA_LIMB_CHEST:
                rot->x += unk_2D4_unk_0E->y;
                rot->y -= unk_2D4_unk_0E->x;
                break;
            case IMPA_LIMB_HEAD:
                rot->x += unk_2D4_unk_08->y;
                rot->z += unk_2D4_unk_08->x;
                break;
        }
    }

    if ((*unk_2D0 != 0) && (limbIndex == IMPA_LIMB_RIGHT_HAND)) {
        *dList = gImpaHandPointingDL;
    }

    return false;
}

void DemoIm_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    DemoIm* pthis = (DemoIm*)thisx;

    if (limbIndex == IMPA_LIMB_HEAD) {
        Vec3f sp28 = D_809887D8;
        Vec3f dest;

        Matrix_MultVec3f(&sp28, &dest);
        pthis->actor.focus.pos.x = dest.x;
        pthis->actor.focus.pos.y = dest.y;
        pthis->actor.focus.pos.z = dest.z;
        pthis->actor.focus.rot.x = pthis->actor.world.rot.x;
        pthis->actor.focus.rot.y = pthis->actor.world.rot.y;
        pthis->actor.focus.rot.z = pthis->actor.world.rot.z;
    }
}

void DemoIm_DrawNothing(DemoIm* pthis, GlobalContext* globalCtx) {
}

void DemoIm_DrawSolid(DemoIm* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeIndex = pthis->eyeIndex;
    void* eyeTexture = sEyeTextures[eyeIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_im.c", 904);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);

    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          DemoIm_OverrideLimbDraw, DemoIm_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_im.c", 925);
}

void DemoIm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DemoIm* pthis = (DemoIm*)thisx;

    if ((pthis->drawConfig < 0) || (pthis->drawConfig >= 3) || (sDrawFuncs[pthis->drawConfig] == NULL)) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawConfig](pthis, globalCtx);
}

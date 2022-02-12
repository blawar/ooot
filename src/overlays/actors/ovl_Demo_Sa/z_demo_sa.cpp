#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_SA_Z_DEMO_SA_C
#include "actor_common.h"
/*
 * File: z_demo_sa.c
 * Overlay: Demo_Sa
 * Description: Saria (Cutscene)
 */

#include "z_demo_sa.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "objects/object_sa/object_sa.h"

#include "vt.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void DemoSa_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoSa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoSa_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoSa_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8098EBB8(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098EBD8(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098EBF8(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098EC28(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098EC60(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098EC94(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098ECCC(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F0E8(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F118(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F16C(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F3F0(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F714(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F734(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F77C(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F7BC(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098F7FC(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098FC44(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098FC64(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098FC9C(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098FCD4(DemoSa* pthis, GlobalContext* globalCtx);
void func_8098FD0C(DemoSa* pthis, GlobalContext* globalCtx);

void DemoSa_DrawNothing(DemoSa* pthis, GlobalContext* globalCtx);
void DemoSa_DrawOpa(DemoSa* pthis, GlobalContext* globalCtx);
void DemoSa_DrawXlu(DemoSa* pthis, GlobalContext* globalCtx);

typedef enum {
    /* 0 */ SARIA_EYE_OPEN,
    /* 1 */ SARIA_EYE_HALF,
    /* 2 */ SARIA_EYE_CLOSED,
    /* 3 */ SARIA_EYE_SUPRISED,
    /* 4 */ SARIA_EYE_SAD
} SariaEyeState;

typedef enum {
    /* 0 */ SARIA_MOUTH_CLOSED2,
    /* 1 */ SARIA_MOUTH_SUPRISED,
    /* 2 */ SARIA_MOUTH_CLOSED,
    /* 3 */ SARIA_MOUTH_SMILING_OPEN,
    /* 4 */ SARIA_MOUTH_FROWNING
} SariaMouthState;

static void* sEyeTextures[] = {
    gSariaEyeOpenTex, gSariaEyeHalfTex, gSariaEyeClosedTex, gSariaEyeSuprisedTex, gSariaEyeSadTex,
};

static void* sMouthTextures[] = {
    gSariaMouthClosed2Tex,     gSariaMouthSuprisedTex, gSariaMouthClosedTex,
    gSariaMouthSmilingOpenTex, gSariaMouthFrowningTex,
};

static u32 D_80990108 = 0;

#include "z_demo_sa_cutscene_data.cpp" EARLY

static DemoSaActionFunc sActionFuncs[] = {
    func_8098EBB8, func_8098EBD8, func_8098EBF8, func_8098EC28, func_8098EC60, func_8098EC94, func_8098ECCC,
    func_8098F0E8, func_8098F118, func_8098F16C, func_8098F3F0, func_8098F714, func_8098F734, func_8098F77C,
    func_8098F7BC, func_8098F7FC, func_8098FC44, func_8098FC64, func_8098FC9C, func_8098FCD4, func_8098FD0C,
};

static DemoSaDrawFunc sDrawFuncs[] = {
    DemoSa_DrawNothing,
    DemoSa_DrawOpa,
    DemoSa_DrawXlu,
};

ActorInit Demo_Sa_InitVars = {
    ACTOR_DEMO_SA,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SA,
    sizeof(DemoSa),
    (ActorFunc)DemoSa_Init,
    (ActorFunc)DemoSa_Destroy,
    (ActorFunc)DemoSa_Update,
    (ActorFunc)DemoSa_Draw,
};

void DemoSa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoSa* pthis = (DemoSa*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
}

void func_8098E480(DemoSa* pthis) {
    s32 pad[2];
    s16* eyeIndex = &pthis->eyeIndex;
    s16* blinkTimer = &pthis->blinkTimer;

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(0x3C, 0x3C);
    }

    *eyeIndex = *blinkTimer;
    if (*eyeIndex >= 3) {
        *eyeIndex = 0;
    }
}

void DemoSa_SetEyeIndex(DemoSa* pthis, s16 eyeIndex) {
    pthis->eyeIndex = eyeIndex;
}

void DemoSa_SetMouthIndex(DemoSa* pthis, s16 mouthIndex) {
    pthis->mouthIndex = mouthIndex;
}

void func_8098E530(DemoSa* pthis) {
    pthis->action = 7;
    pthis->drawConfig = 0;
    pthis->alpha = 0;
    pthis->unk_1A8 = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->unk_1A0 = 0.0f;
}

void func_8098E554(DemoSa* pthis, GlobalContext* globalCtx) {
    u32* something = &D_80990108;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        if (*something != 0) {
            if (pthis->actor.params == 2) {
                func_8098E530(pthis);
            }
            *something = 0;
        }
    } else if (*something == 0) {
        *something = 1;
    }
}

void func_8098E5C8(DemoSa* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 DemoSa_UpdateSkelAnime(DemoSa* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

CsCmdActorAction* DemoSa_GetNpcAction(GlobalContext* globalCtx, s32 idx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[idx];
    }
    return NULL;
}

s32 func_8098E654(DemoSa* pthis, GlobalContext* globalCtx, u16 arg2, s32 arg3) {
    CsCmdActorAction* npcAction = DemoSa_GetNpcAction(globalCtx, arg3);

    if ((npcAction != NULL) && (npcAction->action == arg2)) {
        return 1;
    }
    return 0;
}

s32 func_8098E6A0(DemoSa* pthis, GlobalContext* globalCtx, u16 arg2, s32 arg3) {
    CsCmdActorAction* npcAction = DemoSa_GetNpcAction(globalCtx, arg3);

    if ((npcAction != NULL) && (npcAction->action != arg2)) {
        return 1;
    }
    return 0;
}

void func_8098E6EC(DemoSa* pthis, GlobalContext* globalCtx, s32 actionIdx) {
    CsCmdActorAction* npcAction = DemoSa_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

void func_8098E76C(DemoSa* pthis, AnimationHeader* animHeaderSeg, u8 arg2, f32 transitionRate, s32 arg4) {
    s32 pad[2];
    f32 frameCount = Animation_GetLastFrame(animHeaderSeg);
    f32 playbackSpeed;
    f32 unk0;
    f32 fc;

    if (arg4 == 0) {
        unk0 = 0.0f;
        fc = frameCount;
        playbackSpeed = 1.0f;
    } else {
        fc = 0.0f;
        unk0 = frameCount;
        playbackSpeed = -1.0f;
    }

    Animation_Change(&pthis->skelAnime, animHeaderSeg, playbackSpeed, unk0, fc, arg2, transitionRate);
}

void func_8098E7FC(DemoSa* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSariaSkel, &gSariaWaitArmsToSideAnim, NULL, NULL, 0);
    pthis->actor.shape.yOffset = -10000.0f;
    DemoSa_SetEyeIndex(pthis, SARIA_EYE_HALF);
    DemoSa_SetMouthIndex(pthis, SARIA_MOUTH_CLOSED2);
}

void func_8098E86C(DemoSa* pthis, GlobalContext* globalCtx) {
    Vec3f* world = &pthis->actor.world.pos;
    f32 posX = world->x;
    f32 posY = world->y;
    f32 posZ = world->z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, posX, posY, posZ, 0, 0, 0,
                       WARP_SAGES);
}

void func_8098E8C8(DemoSa* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 posX = player->actor.world.pos.x;
    f32 posY = player->actor.world.pos.y + 80.0f;
    f32 posZ = player->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_EFFECT, posX, posY, posZ, 0, 0, 0,
                       0xB);
    Item_Give(globalCtx, ITEM_MEDALLION_FOREST);
}

void func_8098E944(DemoSa* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.yOffset += (250.0f / 3.0f);
}

void func_8098E960(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Player* player;

    if ((gSaveContext.chamberCutsceneNum == 0) && (gSaveContext.sceneSetupIndex < 4)) {
        player = GET_PLAYER(globalCtx);
        pthis->action = 1;
        globalCtx->csCtx.segment = D_8099010C;
        gSaveContext.cutsceneTrigger = 2;
        Item_Give(globalCtx, ITEM_MEDALLION_FOREST);
        player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    }
}

void func_8098E9EC(DemoSa* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        npcAction = globalCtx->csCtx.npcActions[4];
        if ((npcAction != NULL) && (npcAction->action == 2)) {
            pthis->action = 2;
            pthis->drawConfig = 1;
            func_8098E86C(pthis, globalCtx);
        }
    }
}

void func_8098EA3C(DemoSa* pthis) {
    if (pthis->actor.shape.yOffset >= 0.0f) {
        pthis->action = 3;
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void func_8098EA68(DemoSa* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        npcAction = globalCtx->csCtx.npcActions[4];
        if ((npcAction != NULL) && (npcAction->action == 3)) {
            Animation_Change(&pthis->skelAnime, &gSariaGiveForestMedallionAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gSariaGiveForestMedallionAnim), ANIMMODE_ONCE, -4.0f);
            pthis->action = 4;
        }
    }
}

void func_8098EB00(DemoSa* pthis, s32 arg1) {
    if (arg1 != 0) {
        Animation_Change(&pthis->skelAnime, &gSariaGiveForestMedallionStandAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gSariaGiveForestMedallionStandAnim), ANIMMODE_LOOP, 0.0f);
        pthis->action = 5;
    }
}

void func_8098EB6C(DemoSa* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        npcAction = globalCtx->csCtx.npcActions[6];
        if ((npcAction != NULL) && (npcAction->action == 2)) {
            pthis->action = 6;
            func_8098E8C8(pthis, globalCtx);
        }
    }
}

void func_8098EBB8(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E960(pthis, globalCtx);
}

void func_8098EBD8(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E9EC(pthis, globalCtx);
}

void func_8098EBF8(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E944(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098EA3C(pthis);
}

void func_8098EC28(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098EA68(pthis, globalCtx);
}

void func_8098EC60(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    func_8098EB00(pthis, DemoSa_UpdateSkelAnime(pthis));
}

void func_8098EC94(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098EB6C(pthis, globalCtx);
}

void func_8098ECCC(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
}

void func_8098ECF4(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    SkelAnime* skelAnime = &pthis->skelAnime;
    f32 frameCount = Animation_GetLastFrame(&gSariaSealGanonAnim);

    SkelAnime_InitFlex(globalCtx, skelAnime, &gSariaSkel, NULL, NULL, NULL, 0);
    Animation_Change(skelAnime, &gSariaSealGanonAnim, 1.0f, 0.0f, frameCount, ANIMMODE_ONCE, 0.0f);
    pthis->action = 7;
    pthis->actor.shape.shadowAlpha = 0;
    DemoSa_SetEyeIndex(pthis, SARIA_EYE_CLOSED);
    DemoSa_SetMouthIndex(pthis, SARIA_MOUTH_CLOSED);
}

void func_8098EDB0(DemoSa* pthis) {
    f32 curFrame = pthis->skelAnime.curFrame;

    if ((pthis->skelAnime.mode == 2) && (curFrame >= 32.0f)) {
        DemoSa_SetEyeIndex(pthis, SARIA_EYE_HALF);
        DemoSa_SetMouthIndex(pthis, SARIA_MOUTH_CLOSED2);
    }
}

void func_8098EE08(void) {
    func_800788CC(NA_SE_SY_WHITE_OUT_T);
}

void func_8098EE28(DemoSa* pthis, GlobalContext* globalCtx) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                       (kREG(23) + 25.0f) + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 4);
}

void func_8098EEA8(DemoSa* pthis, GlobalContext* globalCtx) {
    if (func_8098E654(pthis, globalCtx, 4, 4)) {
        pthis->action = 8;
        pthis->drawConfig = 2;
        pthis->alpha = 0;
        pthis->actor.shape.shadowAlpha = 0;
        pthis->unk_1A0 = 0.0f;
        func_8098EE08();
    }
}

void func_8098EEFC(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 alpha = 255;
    f32* unk_1A0 = &pthis->unk_1A0;

    if (func_8098E654(pthis, globalCtx, 4, 4)) {
        *unk_1A0 += 1.0f;
        if ((kREG(5) + 10.0f) <= *unk_1A0) {
            pthis->action = 9;
            pthis->drawConfig = 1;
            *unk_1A0 = kREG(5) + 10.0f;
            pthis->alpha = alpha;
            pthis->actor.shape.shadowAlpha = alpha;
            return;
        }
    } else {
        *unk_1A0 -= 1.0f;
        if (*unk_1A0 <= 0.0f) {
            pthis->action = 7;
            pthis->drawConfig = 0;
            *unk_1A0 = 0.0f;
            pthis->alpha = 0;
            pthis->actor.shape.shadowAlpha = 0;
            return;
        }
    }
    pthis->actor.shape.shadowAlpha = pthis->alpha = (*unk_1A0 / (kREG(5) + 10.0f)) * 255.0f;
}

void func_8098F050(DemoSa* pthis, GlobalContext* globalCtx) {
    if (func_8098E6A0(pthis, globalCtx, 4, 4)) {
        pthis->action = 8;
        pthis->drawConfig = 2;
        pthis->unk_1A0 = kREG(5) + 10.0f;
        pthis->alpha = 255;
        if (pthis->unk_1A8 == 0) {
            func_8098EE28(pthis, globalCtx);
            pthis->unk_1A8 = 1;
        }
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_8098F0E8(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098EEA8(pthis, globalCtx);
    func_8098E554(pthis, globalCtx);
}

void func_8098F118(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
    func_8098EEFC(pthis, globalCtx);
    func_8098E554(pthis, globalCtx);
}

void func_8098F16C(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098EDB0(pthis);
    func_8098F050(pthis, globalCtx);
    func_8098E554(pthis, globalCtx);
}

void DemoSa_DrawXlu(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeIndex = pthis->eyeIndex;
    void* sp78 = sEyeTextures[eyeIndex];
    s16 mouthIndex = pthis->mouthIndex;
    s32 pad2;
    void* sp6C = sMouthTextures[mouthIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_sa_inKenjyanomaDemo02.c", 296);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sp78));
    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sp78));
    gSPSegment(POLY_XLU_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(sp6C));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
    gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);

    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       NULL, NULL, NULL, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_sa_inKenjyanomaDemo02.c", 325);
}

void func_8098F390(DemoSa* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSariaSkel, &gSariaWaitArmsToSideAnim, NULL, NULL, 0);
    pthis->action = 10;
    pthis->drawConfig = 1;
}

void func_8098F3F0(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
}

void func_8098F420(DemoSa* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSariaSkel, &gSariaSitting3Anim, NULL, NULL, 0);
    pthis->action = 11;
    pthis->drawConfig = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_8098F480(DemoSa* pthis) {
    s32 alpha = 255;
    f32* unk_1A0 = &pthis->unk_1A0;
    f32 temp_f0;

    *unk_1A0 += 1.0f;
    temp_f0 = kREG(17) + 10.0f;

    if (temp_f0 <= *unk_1A0) {
        pthis->actor.shape.shadowAlpha = pthis->alpha = alpha;
    } else {
        pthis->actor.shape.shadowAlpha = pthis->alpha = (*unk_1A0 / temp_f0) * 255.0f;
    }
}

void func_8098F50C(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E6EC(pthis, globalCtx, 4);
    pthis->action = 12;
    pthis->drawConfig = 2;
}

void func_8098F544(DemoSa* pthis) {
    if (pthis->unk_1A0 >= kREG(17) + 10.0f) {
        pthis->action = 13;
        pthis->drawConfig = 1;
    }
}

void func_8098F590(DemoSa* pthis) {
    func_8098E76C(pthis, &gSariaSitting1Anim, 2, -8.0f, 0);
    pthis->action = 14;
}

void func_8098F5D0(DemoSa* pthis) {
    func_8098E76C(pthis, &gSariaSitting2Anim, 2, 0.0f, 0);
    pthis->action = 15;
}

void func_8098F610(DemoSa* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_8098E76C(pthis, &gSariaSitting3Anim, 0, 0.0f, 0);
        pthis->action = 13;
    }
}

void func_8098F654(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 unk_1AC;
    s32 action;
    CsCmdActorAction* npcAction = DemoSa_GetNpcAction(globalCtx, 4);

    if (npcAction != NULL) {
        action = npcAction->action;
        unk_1AC = pthis->unk_1AC;
        if (action != unk_1AC) {
            switch (action) {
                case 7:
                    func_8098F50C(pthis, globalCtx);
                    break;
                case 8:
                    func_8098F590(pthis);
                    break;
                case 9:
                    func_8098F5D0(pthis);
                    break;
                default:
                    osSyncPrintf("Demo_Sa_inEnding_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_1AC = action;
        }
    }
}

void func_8098F714(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098F654(pthis, globalCtx);
}

void func_8098F734(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
    func_8098F480(pthis);
    func_8098F544(pthis);
}

void func_8098F77C(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
    func_8098F654(pthis, globalCtx);
}

void func_8098F7BC(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
    func_8098F654(pthis, globalCtx);
}

void func_8098F7FC(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 sp1C;

    func_8098E5C8(pthis, globalCtx);
    sp1C = DemoSa_UpdateSkelAnime(pthis);
    func_8098E480(pthis);
    func_8098F610(pthis, sp1C);
}

void func_8098F83C(DemoSa* pthis, GlobalContext* globalCtx) {
    Vec3f* thisPos = &pthis->actor.world.pos;

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSariaSkel, &gSariaWaitOnBridgeAnim, NULL, NULL, 0);
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ELF, thisPos->x, thisPos->y, thisPos->z,
                       0, 0, 0, FAIRY_KOKIRI);
    pthis->action = 16;
    pthis->drawConfig = 0;
    pthis->actor.shape.shadowAlpha = 0;
    DemoSa_SetEyeIndex(pthis, SARIA_EYE_SAD);
    DemoSa_SetMouthIndex(pthis, SARIA_MOUTH_CLOSED);
}

void func_8098F8F8(DemoSa* pthis) {
    s32 alpha = 255;
    f32* unk_1A0 = &pthis->unk_1A0;
    f32 temp_f0;

    *unk_1A0 += 1.0f;
    temp_f0 = kREG(17) + 10.0f;

    if (temp_f0 <= *unk_1A0) {
        pthis->actor.shape.shadowAlpha = pthis->alpha = alpha;
    } else {
        pthis->actor.shape.shadowAlpha = pthis->alpha = (*unk_1A0 / temp_f0) * 255.0f;
    }
}

void func_8098F984(DemoSa* pthis) {
    pthis->action = 16;
    pthis->drawConfig = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_8098F998(DemoSa* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1AC == 4) {
        func_8098E6EC(pthis, globalCtx, 1);
        pthis->action = 17;
        pthis->drawConfig = 2;
        pthis->unk_1B0 = 0;
        pthis->actor.shape.shadowAlpha = 0;
    } else {
        func_8098E76C(pthis, &gSariaWaitOnBridgeAnim, 0, 0.0f, 0);
        pthis->action = 18;
        pthis->drawConfig = 1;
        pthis->unk_1B0 = 0;
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
    DemoSa_SetEyeIndex(pthis, SARIA_EYE_SAD);
}

void func_8098FA2C(DemoSa* pthis) {
    if (pthis->unk_1A0 >= kREG(17) + 10.0f) {
        pthis->action = 18;
        pthis->drawConfig = 1;
        pthis->unk_1B0 = 0;
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_8098FA84(DemoSa* pthis) {
    func_8098E76C(pthis, &gSariaHoldOcarinaAnim, 0, 0.0f, 0);
    pthis->action = 19;
    pthis->drawConfig = 1;
    pthis->unk_1B0 = 1;
    pthis->actor.shape.shadowAlpha = 0xFF;
    DemoSa_SetEyeIndex(pthis, SARIA_EYE_CLOSED);
}

void func_8098FAE0(DemoSa* pthis) {
    func_8098E76C(pthis, &gSariaGiveLinkOcarinaAnim, 2, -8.0f, 0);
    pthis->action = 20;
    pthis->drawConfig = 1;
    pthis->unk_1B0 = 1;
    pthis->actor.shape.shadowAlpha = 0xFF;
}

void func_8098FB34(DemoSa* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_8098E76C(pthis, &gSariaHoldOutOcarinaAnim, 0, 0, 0);
    }
}

void func_8098FB68(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 unk_1AC;
    s32 action;
    CsCmdActorAction* npcAction = DemoSa_GetNpcAction(globalCtx, 1);

    if (npcAction != NULL) {
        action = npcAction->action;
        unk_1AC = pthis->unk_1AC;
        if (action != unk_1AC) {
            switch (action) {
                case 4:
                    func_8098F984(pthis);
                    break;
                case 12:
                    func_8098F998(pthis, globalCtx);
                    break;
                case 13:
                    func_8098FA84(pthis);
                    break;
                case 14:
                    func_8098FAE0(pthis);
                    break;
                default:
                    osSyncPrintf("Demo_Sa_inPresent_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_1AC = action;
        }
    }
}

void func_8098FC44(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098FB68(pthis, globalCtx);
}

void func_8098FC64(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098F8F8(pthis);
    func_8098FA2C(pthis);
}

void func_8098FC9C(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098FB68(pthis, globalCtx);
}

void func_8098FCD4(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    DemoSa_UpdateSkelAnime(pthis);
    func_8098FB68(pthis, globalCtx);
}

void func_8098FD0C(DemoSa* pthis, GlobalContext* globalCtx) {
    func_8098E5C8(pthis, globalCtx);
    func_8098FB34(pthis, DemoSa_UpdateSkelAnime(pthis));
    func_8098FB68(pthis, globalCtx);
}

void DemoSa_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoSa* pthis = (DemoSa*)thisx;

    if (pthis->action < 0 || pthis->action >= 21 || sActionFuncs[pthis->action] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->action](pthis, globalCtx);
}

void DemoSa_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoSa* pthis = (DemoSa*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);

    switch (pthis->actor.params) {
        case 2:
            func_8098ECF4(pthis, globalCtx);
            break;
        case 3:
            func_8098F390(pthis, globalCtx);
            break;
        case 4:
            func_8098F420(pthis, globalCtx);
            break;
        case 5:
            func_8098F83C(pthis, globalCtx);
            break;
        default:
            func_8098E7FC(pthis, globalCtx);
    }
}

s32 DemoSa_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    DemoSa* pthis = (DemoSa*)thisx;

    if ((limbIndex == 15) && (pthis->unk_1B0 != 0)) {
        *dList = gSariaRightHandAndOcarinaDL;
    }
    return false;
}

void DemoSa_DrawNothing(DemoSa* pthis, GlobalContext* globalCtx) {
}

void DemoSa_DrawOpa(DemoSa* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeIndex = pthis->eyeIndex;
    void* eyeTex = sEyeTextures[eyeIndex];
    s32 pad2;
    s16 mouthIndex = pthis->mouthIndex;
    void* mouthTex = sMouthTextures[mouthIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_sa.c", 602);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(mouthTex));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);

    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          DemoSa_OverrideLimbDraw, NULL, &pthis->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_sa.c", 626);
}

void DemoSa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DemoSa* pthis = (DemoSa*)thisx;

    if (pthis->drawConfig < 0 || pthis->drawConfig >= 3 || sDrawFuncs[pthis->drawConfig] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawConfig](pthis, globalCtx);
}

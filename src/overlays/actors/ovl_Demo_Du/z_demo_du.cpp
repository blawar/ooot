#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_DU_Z_DEMO_DU_C
#include "actor_common.h"
#include "z_demo_du.h"
#include "objects/object_du/object_du.h"
#include "overlays/actors/ovl_Demo_Effect/z_demo_effect.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "vt.h"

#define FLAGS ACTOR_FLAG_4

typedef void (*DemoDuActionFunc)(DemoDu*, GlobalContext*);
typedef void (*DemoDuDrawFunc)(Actor*, GlobalContext*);

void DemoDu_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoDu_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoDu_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoDu_Draw(Actor* thisx, GlobalContext* globalCtx);

static s32 sUnused = 0;

#include "z_demo_du_cutscene_data.cpp" EARLY
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

static void* sEyeTextures[] = { gDaruniaEyeOpenTex, gDaruniaEyeOpeningTex, gDaruniaEyeShutTex, gDaruniaEyeClosingTex };
static void* sMouthTextures[] = { gDaruniaMouthSeriousTex, gDaruniaMouthGrinningTex, gDaruniaMouthOpenTex,
                                  gDaruniaMouthHappyTex };

/**
 * Cs => Cutscene
 *
 * FM => Fire Medallion
 * GR => Goron's Ruby
 * AG => In the chamber of sages, just After the final blow on Ganon.
 * CR => Credits
 *
 */

// Each macro maps its argument to an index of sUpdateFuncs.
#define CS_FIREMEDALLION_SUBSCENE(x) (0 + (x))      // DEMO_DU_CS_FIREMEDALLION
#define CS_GORONSRUBY_SUBSCENE(x) (7 + (x))         // DEMO_DU_CS_GORONS_RUBY
#define CS_CHAMBERAFTERGANON_SUBSCENE(x) (21 + (x)) // DEMO_DU_CS_CHAMBER_AFTER_GANON
#define CS_CREDITS_SUBSCENE(x) (24 + (x))           // DEMO_DU_CS_CREDITS

void DemoDu_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoDu* pthis = (DemoDu*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
}

void DemoDu_UpdateEyes(DemoDu* pthis) {
    s16* blinkTimer = &pthis->blinkTimer;
    s16* eyeTexIndex = &pthis->eyeTexIndex;
    s32 pad[3];

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(60, 60);
    }

    *eyeTexIndex = *blinkTimer;
    if (*eyeTexIndex >= 3) {
        *eyeTexIndex = 0;
    }
}

void DemoDu_SetEyeTexIndex(DemoDu* pthis, s16 eyeTexIndex) {
    pthis->eyeTexIndex = eyeTexIndex;
}

void DemoDu_SetMouthTexIndex(DemoDu* pthis, s16 mouthTexIndex) {
    pthis->mouthTexIndex = mouthTexIndex;
}

// Resets all the values used in pthis cutscene.
void DemoDu_CsAfterGanon_Reset(DemoDu* pthis) {
    pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(0);
    pthis->drawIndex = 0;
    pthis->shadowAlpha = 0;
    pthis->demo6KSpawned = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->unk_1A4 = 0.0f;
}

void DemoDu_CsAfterGanon_CheckIfShouldReset(DemoDu* pthis, GlobalContext* globalCtx) {
    static s32 D_8096CE94 = false;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        if (D_8096CE94) {
            if (pthis->actor.params == DEMO_DU_CS_CHAMBER_AFTER_GANON) {
                DemoDu_CsAfterGanon_Reset(pthis);
            }
            D_8096CE94 = false;
            return;
        }
    } else if (!D_8096CE94) {
        D_8096CE94 = true;
    }
}

s32 DemoDu_UpdateSkelAnime(DemoDu* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

void DemoDu_UpdateBgCheckInfo(DemoDu* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

CsCmdActorAction* DemoDu_GetNpcAction(GlobalContext* globalCtx, s32 idx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[idx];
    }
    return NULL;
}

s32 DemoDu_IsNpcDoingThisAction(DemoDu* pthis, GlobalContext* globalCtx, u16 action, s32 idx) {
    CsCmdActorAction* npcAction = DemoDu_GetNpcAction(globalCtx, idx);

    if ((npcAction != NULL) && (npcAction->action == action)) {
        return true;
    }
    return false;
}

s32 DemoDu_IsNpcNotDoingThisAction(DemoDu* pthis, GlobalContext* globalCtx, u16 action, s32 idx) {
    CsCmdActorAction* npcAction = DemoDu_GetNpcAction(globalCtx, idx);

    if ((npcAction != NULL) && (npcAction->action != action)) {
        return true;
    }
    return false;
}

void DemoDu_MoveToNpcPos(DemoDu* pthis, GlobalContext* globalCtx, s32 idx) {
    CsCmdActorAction* npcAction = DemoDu_GetNpcAction(globalCtx, idx);
    s32 pad;

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;

        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

void func_80969DDC(DemoDu* pthis, AnimationHeader* animation, u8 mode, f32 morphFrames, s32 arg4) {
    f32 startFrame;
    s16 lastFrame = Animation_GetLastFrame(animation);
    f32 endFrame;
    f32 playSpeed;

    if (arg4 == 0) {
        startFrame = 0.0f;
        endFrame = lastFrame;
        playSpeed = 1.0f;
    } else {
        endFrame = 0.0f;
        playSpeed = -1.0f;
        startFrame = lastFrame;
    }
    Animation_Change(&pthis->skelAnime, animation, playSpeed, startFrame, endFrame, mode, morphFrames);
}

void DemoDu_InitCs_FireMedallion(DemoDu* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDaruniaSkel, &gDaruniaIdleAnim, NULL, NULL, 0);
    pthis->actor.shape.yOffset = -10000.0f;
    DemoDu_SetEyeTexIndex(pthis, 1);
    DemoDu_SetMouthTexIndex(pthis, 3);
}

// A.k.a Warp portal
void DemoDu_CsFireMedallion_SpawnDoorWarp(DemoDu* pthis, GlobalContext* globalCtx) {
    f32 posX = pthis->actor.world.pos.x;
    f32 posY = pthis->actor.world.pos.y;
    f32 posZ = pthis->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, posX, posY, posZ, 0, 0, 0,
                       WARP_SAGES);
}

// Gives the Fire Medallion to Link.
void func_80969F38(DemoDu* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 posX = player->actor.world.pos.x;
    f32 posY = player->actor.world.pos.y + 80.0f;
    f32 posZ = player->actor.world.pos.z;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_EFFECT, posX, posY, posZ, 0, 0, 0,
                       DEMO_EFFECT_MEDAL_FIRE);
    Item_Give(globalCtx, ITEM_MEDALLION_FIRE);
}

void func_80969FB4(DemoDu* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.yOffset += 250.0f / 3.0f;
}

// Gives the Fire Medallion to Link too.
void DemoDu_CsFireMedallion_AdvanceTo01(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 pad[2];

    if ((gSaveContext.chamberCutsceneNum == 1) && (gSaveContext.sceneSetupIndex < 4)) {
        Player* player = GET_PLAYER(globalCtx);

        pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(1);
        globalCtx->csCtx.segment = D_8096C1A4;
        gSaveContext.cutsceneTrigger = 2;
        Item_Give(globalCtx, ITEM_MEDALLION_FIRE);

        player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    }
}

void DemoDu_CsFireMedallion_AdvanceTo02(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 1)) {
            pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(2);
            pthis->drawIndex = 1;
            DemoDu_CsFireMedallion_SpawnDoorWarp(pthis, globalCtx);
        }
    }
}

void DemoDu_CsFireMedallion_AdvanceTo03(DemoDu* pthis) {
    if (pthis->actor.shape.yOffset >= 0.0f) {
        pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(3);
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void DemoDu_CsFireMedallion_AdvanceTo04(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 2)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaItemGiveAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gDaruniaItemGiveAnim), 2, 0.0f);
            pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(4);
        }
    }
}

void DemoDu_CsFireMedallion_AdvanceTo05(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaItemGiveIdleAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gDaruniaItemGiveIdleAnim), 0, 0.0f);
        pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(5);
    }
}

void DemoDu_CsFireMedallion_AdvanceTo06(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[6];

        if ((npcAction != NULL) && (npcAction->action == 2)) {
            pthis->updateIndex = CS_FIREMEDALLION_SUBSCENE(6);
            func_80969F38(pthis, globalCtx);
        }
    }
}

void DemoDu_UpdateCs_FM_00(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsFireMedallion_AdvanceTo01(pthis, globalCtx);
}

void DemoDu_UpdateCs_FM_01(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsFireMedallion_AdvanceTo02(pthis, globalCtx);
}

void DemoDu_UpdateCs_FM_02(DemoDu* pthis, GlobalContext* globalCtx) {
    func_80969FB4(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsFireMedallion_AdvanceTo03(pthis);
}

void DemoDu_UpdateCs_FM_03(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsFireMedallion_AdvanceTo04(pthis, globalCtx);
}

void DemoDu_UpdateCs_FM_04(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsFireMedallion_AdvanceTo05(pthis, animFinished);
}

void DemoDu_UpdateCs_FM_05(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsFireMedallion_AdvanceTo06(pthis, globalCtx);
}

void DemoDu_UpdateCs_FM_06(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
}

void DemoDu_InitCs_GoronsRuby(DemoDu* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDaruniaSkel, NULL, NULL, NULL, 0);
    pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(0);
}

// Cutscene: Darunia gives Link the Goron's Ruby.
// Sfx played when Darunia lands at the floor at the start of the cutscene.
void DemoDu_CsPlaySfx_GoronLanding(DemoDu* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_EN_GOLON_LAND_BIG);
}

// Cutscene: Darunia gives Link the Goron's Ruby.
// Sfx played when Darunia is falling at the start of the cutscene.
void DemoDu_CsPlaySfx_DaruniaFalling(GlobalContext* globalCtx) {
    if (globalCtx->csCtx.frames == 160) {
        func_800788CC(NA_SE_EV_OBJECT_FALL);
    }
}

// Cutscene: Darunia gives Link the Goron's Ruby.
void DemoDu_CsPlaySfx_DaruniaHitsLink(GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;

    func_80078914(&player->actor.projectedPos, NA_SE_EN_DARUNIA_HIT_LINK);
    Audio_PlaySoundGeneral(NA_SE_VO_LI_DAMAGE_S_KID, &player->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

// Cutscene: Darunia gives Link the Goron's Ruby.
void DemoDu_CsPlaySfx_HitBreast(DemoDu* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_EN_DARUNIA_HIT_BREAST - SFX_FLAG);
}

// Cutscene: Darunia gives Link the Goron's Ruby.
// Sfx played when Link is escaping from the gorons at the end of the scene.
void DemoDu_CsPlaySfx_LinkEscapeFromGorons(GlobalContext* globalCtx) {
    if (globalCtx->csCtx.frames == 1400) {
        Player* player = GET_PLAYER(globalCtx);

        Audio_PlaySoundGeneral(NA_SE_VO_LI_FALL_L_KID, &player->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

// Cutscene: Darunia gives Link the Goron's Ruby.
// Sfx played when Link is surprised by Darunia falling from the sky.
void DemoDu_CsPlaySfx_LinkSurprised(GlobalContext* globalCtx) {
    if (globalCtx->csCtx.frames == 174) {
        Player* player = GET_PLAYER(globalCtx);

        Audio_PlaySoundGeneral(NA_SE_VO_LI_SURPRISE_KID, &player->actor.projectedPos, 4U, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

void DemoDu_CsGoronsRuby_UpdateFaceTextures(DemoDu* pthis, GlobalContext* globalCtx) {
    auto& frames = globalCtx->csCtx.frames;

    if (frames < 260) {
        DemoDu_UpdateEyes(pthis);
        DemoDu_SetMouthTexIndex(pthis, 0);
    } else if (frames < 335) {
        DemoDu_UpdateEyes(pthis);
        DemoDu_SetMouthTexIndex(pthis, 3);
    } else if (frames < 365) {
        DemoDu_SetEyeTexIndex(pthis, 3);
        DemoDu_SetMouthTexIndex(pthis, 1);
    } else if (frames < 395) {
        DemoDu_SetEyeTexIndex(pthis, 0);
        DemoDu_SetMouthTexIndex(pthis, 3);
    } else if (frames < 410) {
        DemoDu_UpdateEyes(pthis);
        DemoDu_SetMouthTexIndex(pthis, 0);
    } else {
        DemoDu_UpdateEyes(pthis);
        DemoDu_SetMouthTexIndex(pthis, 3);
    }
}

void func_8096A630(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f pos = pthis->actor.world.pos;

    pos.y += kREG(5);
    func_80033480(globalCtx, &pos, kREG(1) + 100.0f, kREG(2) + 10, kREG(3) + 300, kREG(4), 0);
    DemoDu_CsPlaySfx_GoronLanding(pthis);
}

void DemoDu_CsGoronsRuby_SpawnDustWhenHittingLink(DemoDu* pthis, GlobalContext* globalCtx) {
    static Vec3f dustPosOffsets[] = {
        { 11.0f, -11.0f, -6.0f }, { 0.0f, 14.0f, -13.0f },  { 14.0f, -2.0f, -10.0f }, { 10.0f, -6.0f, -8.0f },
        { 8.0f, 6.0f, 8.0f },     { 13.0f, 8.0f, -10.0f },  { -14.0f, 1.0f, -14.0f }, { 5.0f, 12.0f, -9.0f },
        { 11.0f, 6.0f, -7.0f },   { 14.0f, 14.0f, -14.0f },
    };

    if (Animation_OnFrame(&pthis->skelAnime, 31.0f) || Animation_OnFrame(&pthis->skelAnime, 41.0f)) {
        s32 pad[2];
        s32 i;
        Player* player = GET_PLAYER(globalCtx);
        Vec3f* headPos = &player->bodyPartsPos[PLAYER_LIMB_HEAD];
        Vec3f velocity = { 0.0f, 0.0f, 0.0f };
        Vec3f accel = { 0.0f, 0.3f, 0.0f };
        s32 pad2;

        for (i = 4; i >= 0; --i) {
            Color_RGBA8 primColor = { 190, 150, 110, 255 };
            Color_RGBA8 envColor = { 120, 80, 40, 255 };
            s32 colorDelta;
            Vec3f position;

            if (Animation_OnFrame(&pthis->skelAnime, 31.0f)) {
                position.x = dustPosOffsets[i + 5].x + headPos->x;
                position.y = dustPosOffsets[i + 5].y + headPos->y;
                position.z = dustPosOffsets[i + 5].z + headPos->z;
            } else {
                position.x = dustPosOffsets[i + 0].x + headPos->x;
                position.y = dustPosOffsets[i + 0].y + headPos->y;
                position.z = dustPosOffsets[i + 0].z + headPos->z;
            }

            colorDelta = Rand_ZeroOne() * 20.0f - 10.0f;

            primColor.r += colorDelta;
            primColor.g += colorDelta;
            primColor.b += colorDelta;
            envColor.r += colorDelta;
            envColor.g += colorDelta;
            envColor.b += colorDelta;

            func_8002829C(globalCtx, &position, &velocity, &accel, &primColor, &envColor,
                          Rand_ZeroOne() * 40.0f + 200.0f, 0);
        }

        DemoDu_CsPlaySfx_DaruniaHitsLink(globalCtx);
    }
}

void DemoDu_CsGoronsRuby_DaruniaFalling(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 pad;
    CutsceneContext* csCtx = &globalCtx->csCtx;

    if (csCtx->state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = csCtx->npcActions[2];
        Vec3f startPos;
        Vec3f endPos;
        Vec3f* pos = &pthis->actor.world.pos;

        if (npcAction != NULL) {
		    f32 traveledPercent = Environment_LerpWeight(npcAction->endFrame, npcAction->startFrame, csCtx->frames);

            startPos.x = npcAction->startPos.x;
            startPos.y = npcAction->startPos.y;
            startPos.z = npcAction->startPos.z;

            endPos.x = npcAction->endPos.x;
            endPos.y = npcAction->endPos.y;
            endPos.z = npcAction->endPos.z;

            pos->x = ((endPos.x - startPos.x) * traveledPercent) + startPos.x;
            pos->y = ((endPos.y - startPos.y) * traveledPercent) + startPos.y;
            pos->z = ((endPos.z - startPos.z) * traveledPercent) + startPos.z;
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo01(DemoDu* pthis, GlobalContext* globalCtx) {
    pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(1);
}

void DemoDu_CsGoronsRuby_AdvanceTo02(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 1)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaStandUpAfterFallingAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gDaruniaStandUpAfterFallingAnim), 2, 0.0f);
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(2);
            pthis->drawIndex = 1;
            DemoDu_CsGoronsRuby_DaruniaFalling(pthis, globalCtx);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo03(DemoDu* pthis, GlobalContext* globalCtx) {
    CutsceneContext* csCtx = &globalCtx->csCtx;

    if (csCtx->state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = csCtx->npcActions[2];

        if ((npcAction != NULL) && (csCtx->frames >= npcAction->endFrame)) {
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(3);
            func_8096A630(pthis, globalCtx);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo04(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 2)) {
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(4);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo05(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gDaruniaIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(5);
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo06(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 3)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaHitBreastAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gDaruniaHitBreastAnim), 2, -4.0f);
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(6);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo07(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gDaruniaIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(7);
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo08(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 4)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaHitLinkAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gDaruniaHitLinkAnim), 2, 0.0f);
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(8);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo09(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaHitBreastAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gDaruniaHitBreastAnim), 2, 0.0f);
        pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(9);
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo10(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gDaruniaIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(10);
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo11(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 5)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaItemGiveAnim, 1.0f, 0.0f,
                             Animation_GetLastFrame(&gDaruniaItemGiveAnim), 2, 0.0f);
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(11);
        }
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo12(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        Animation_Change(&pthis->skelAnime, &gDaruniaItemGiveIdleAnim, 1.0f, 0.0f,
                         Animation_GetLastFrame(&gDaruniaItemGiveIdleAnim), 0, 0.0f);
        pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(12);
    }
}

void DemoDu_CsGoronsRuby_AdvanceTo13(DemoDu* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];

        if ((npcAction != NULL) && (npcAction->action != 6)) {
            Animation_Change(&pthis->skelAnime, &gDaruniaIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gDaruniaIdleAnim),
                             ANIMMODE_LOOP, 0.0f);
            pthis->updateIndex = CS_GORONSRUBY_SUBSCENE(13);
        }
    }
}

void DemoDu_UpdateCs_GR_00(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsPlaySfx_DaruniaFalling(globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo01(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_01(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsPlaySfx_DaruniaFalling(globalCtx);
    DemoDu_CsPlaySfx_LinkSurprised(globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo02(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_02(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsGoronsRuby_DaruniaFalling(pthis, globalCtx);
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_CsPlaySfx_DaruniaFalling(globalCtx);
    DemoDu_CsPlaySfx_LinkSurprised(globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo03(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_03(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_CsPlaySfx_LinkSurprised(globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo04(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_04(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo05(pthis, animFinished);
}

void DemoDu_UpdateCs_GR_05(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo06(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_06(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsPlaySfx_HitBreast(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo07(pthis, animFinished);
}

void DemoDu_UpdateCs_GR_07(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo08(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_08(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_SpawnDustWhenHittingLink(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo09(pthis, animFinished);
}

void DemoDu_UpdateCs_GR_09(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsPlaySfx_HitBreast(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo10(pthis, animFinished);
}

void DemoDu_UpdateCs_GR_10(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo11(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_11(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo12(pthis, animFinished);
}

void DemoDu_UpdateCs_GR_12(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsGoronsRuby_AdvanceTo13(pthis, globalCtx);
}

void DemoDu_UpdateCs_GR_13(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_CsGoronsRuby_UpdateFaceTextures(pthis, globalCtx);
    DemoDu_CsPlaySfx_LinkEscapeFromGorons(globalCtx);
}

void DemoDu_InitCs_AfterGanon(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 pad[3];
    f32 lastFrame = Animation_GetLastFrame(&gDaruniaSageFormationAnim);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDaruniaSkel, NULL, NULL, NULL, 0);
    Animation_Change(&pthis->skelAnime, &gDaruniaSageFormationAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(0);
    pthis->actor.shape.shadowAlpha = 0;
}

void DemoDu_CsPlaySfx_WhiteOut() {
    func_800788CC(NA_SE_SY_WHITE_OUT_T);
}

void DemoDu_CsAfterGanon_SpawnDemo6K(DemoDu* pthis, GlobalContext* globalCtx) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                       kREG(16) + 22.0f + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 3);
}

void DemoDu_CsAfterGanon_AdvanceTo01(DemoDu* pthis, GlobalContext* globalCtx) {
    if (DemoDu_IsNpcDoingThisAction(pthis, globalCtx, 4, 2)) {
        pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(1);
        pthis->drawIndex = 2;
        pthis->shadowAlpha = 0;
        pthis->actor.shape.shadowAlpha = 0;
        pthis->unk_1A4 = 0.0f;
        DemoDu_CsPlaySfx_WhiteOut();
    }
}

void DemoDu_CsAfterGanon_AdvanceTo02(DemoDu* pthis, GlobalContext* globalCtx) {
    f32* unk_1A4 = &pthis->unk_1A4;
    s32 shadowAlpha = 255;

    if (DemoDu_IsNpcDoingThisAction(pthis, globalCtx, 4, 2)) {
        *unk_1A4 += 1.0f;
        if (*unk_1A4 >= kREG(5) + 10.0f) {
            pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(2);
            pthis->drawIndex = 1;
            *unk_1A4 = kREG(5) + 10.0f;
            pthis->shadowAlpha = shadowAlpha;
            pthis->actor.shape.shadowAlpha = shadowAlpha;
            return;
        }
    } else {
        *unk_1A4 -= 1.0f;
        if (*unk_1A4 <= 0.0f) {
            pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(0);
            pthis->drawIndex = 0;
            *unk_1A4 = 0.0f;
            pthis->shadowAlpha = 0;
            pthis->actor.shape.shadowAlpha = 0;
            return;
        }
    }
    shadowAlpha = (*unk_1A4 / (kREG(5) + 10.0f)) * 255.0f;
    pthis->shadowAlpha = shadowAlpha;
    pthis->actor.shape.shadowAlpha = shadowAlpha;
}

void DemoDu_CsAfterGanon_BackTo01(DemoDu* pthis, GlobalContext* globalCtx) {
    if (DemoDu_IsNpcNotDoingThisAction(pthis, globalCtx, 4, 2)) {
        pthis->updateIndex = CS_CHAMBERAFTERGANON_SUBSCENE(1);
        pthis->drawIndex = 2;
        pthis->unk_1A4 = kREG(5) + 10.0f;
        pthis->shadowAlpha = 255;
        if (!pthis->demo6KSpawned) {
            DemoDu_CsAfterGanon_SpawnDemo6K(pthis, globalCtx);
            pthis->demo6KSpawned = 1;
        }
        pthis->actor.shape.shadowAlpha = 255;
    }
}

void DemoDu_UpdateCs_AG_00(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsAfterGanon_AdvanceTo01(pthis, globalCtx);
    DemoDu_CsAfterGanon_CheckIfShouldReset(pthis, globalCtx);
}

void DemoDu_UpdateCs_AG_01(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsAfterGanon_AdvanceTo02(pthis, globalCtx);
    DemoDu_CsAfterGanon_CheckIfShouldReset(pthis, globalCtx);
}

void DemoDu_UpdateCs_AG_02(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsAfterGanon_BackTo01(pthis, globalCtx);
    DemoDu_CsAfterGanon_CheckIfShouldReset(pthis, globalCtx);
}

// Similar to DemoDu_Draw_01, but pthis uses POLY_XLU_DISP. Also uses pthis->shadowAlpha for setting the env color.
void DemoDu_Draw_02(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    DemoDu* pthis = (DemoDu*)thisx;
    s16 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = sEyeTextures[eyeTexIndex];
    s32 pad;
    s16 mouthTexIndex = pthis->mouthTexIndex;
    void* mouthTexture = sMouthTextures[mouthTexIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_du_inKenjyanomaDemo02.c", 275);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(mouthTexture));
    gSPSegment(POLY_XLU_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(gDaruniaNoseSeriousTex));

    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->shadowAlpha);

    gSPSegment(POLY_XLU_DISP++, 0x0C, &D_80116280[0]);

    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount, 0,
                                       0, 0, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_du_inKenjyanomaDemo02.c", 304);
}

void DemoDu_InitCs_Credits(DemoDu* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDaruniaSkel, &gDaruniaCreditsIdleAnim, NULL, NULL, 0);
    pthis->updateIndex = CS_CREDITS_SUBSCENE(0);
    pthis->drawIndex = 0;
    pthis->actor.shape.shadowAlpha = 0;
    DemoDu_SetMouthTexIndex(pthis, 3);
}

void DemoDu_CsCredits_UpdateShadowAlpha(DemoDu* pthis) {
    s32 shadowAlpha = 255;
    f32 temp_f0;
    f32* unk_1A4;

    pthis->unk_1A4 += 1.0f;
    temp_f0 = kREG(17) + 10.0f;
    unk_1A4 = &pthis->unk_1A4;

    if (temp_f0 <= *unk_1A4) {
        pthis->shadowAlpha = shadowAlpha;
        pthis->actor.shape.shadowAlpha = shadowAlpha;
    } else {
        shadowAlpha = *unk_1A4 / temp_f0 * 255.0f;
        pthis->shadowAlpha = shadowAlpha;
        pthis->actor.shape.shadowAlpha = shadowAlpha;
    }
}

void DemoDu_CsCredits_AdvanceTo01(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_MoveToNpcPos(pthis, globalCtx, 2);
    pthis->updateIndex = CS_CREDITS_SUBSCENE(1);
    pthis->drawIndex = 2;
}

void DemoDu_CsCredits_AdvanceTo02(DemoDu* pthis) {
    if (pthis->unk_1A4 >= kREG(17) + 10.0f) {
        pthis->updateIndex = CS_CREDITS_SUBSCENE(2);
        pthis->drawIndex = 1;
    }
}

void DemoDu_CsCredits_AdvanceTo03(DemoDu* pthis) {
    func_80969DDC(pthis, &gDaruniaLookingUpToSariaAnim, ANIMMODE_ONCE, -8.0f, 0);
    pthis->updateIndex = CS_CREDITS_SUBSCENE(3);
}

void DemoDu_CsCredits_AdvanceTo04(DemoDu* pthis) {
    func_80969DDC(pthis, &gDaruniaCreditsHitBreastAnim, ANIMMODE_ONCE, 0.0f, 0);
    pthis->updateIndex = CS_CREDITS_SUBSCENE(4);
}

void DemoDu_CsCredits_BackTo02(DemoDu* pthis, s32 animFinished) {
    if (animFinished) {
        func_80969DDC(pthis, &gDaruniaCreditsIdleAnim, ANIMMODE_LOOP, 0.0f, 0);
        pthis->updateIndex = CS_CREDITS_SUBSCENE(2);
    }
}

void DemoDu_CsCredits_HandleSubscenesByNpcAction(DemoDu* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = DemoDu_GetNpcAction(globalCtx, 2);

    if (npcAction != NULL) {
        s32 action = npcAction->action;
        s32 lastAction = pthis->lastAction;

        if (action != lastAction) {
            switch (action) {
                case 9:
                    DemoDu_CsCredits_AdvanceTo01(pthis, globalCtx);
                    break;
                case 10:
                    DemoDu_CsCredits_AdvanceTo03(pthis);
                    break;
                case 11:
                    DemoDu_CsCredits_AdvanceTo04(pthis);
                    break;
                default:
                    // "Demo_Du_inEnding_Check_DemoMode:There is no such operation!!!!!!!!"
                    osSyncPrintf("Demo_Du_inEnding_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
                    break;
            }
            pthis->lastAction = action;
        }
    }
}

void DemoDu_UpdateCs_CR_00(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_CsCredits_HandleSubscenesByNpcAction(pthis, globalCtx);
}

void DemoDu_UpdateCs_CR_01(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsCredits_UpdateShadowAlpha(pthis);
    DemoDu_CsCredits_AdvanceTo02(pthis);
}

void DemoDu_UpdateCs_CR_02(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsCredits_HandleSubscenesByNpcAction(pthis, globalCtx);
}

void DemoDu_UpdateCs_CR_03(DemoDu* pthis, GlobalContext* globalCtx) {
    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsCredits_HandleSubscenesByNpcAction(pthis, globalCtx);
}

void DemoDu_UpdateCs_CR_04(DemoDu* pthis, GlobalContext* globalCtx) {
    s32 animFinished;

    DemoDu_UpdateBgCheckInfo(pthis, globalCtx);
    animFinished = DemoDu_UpdateSkelAnime(pthis);
    DemoDu_UpdateEyes(pthis);
    DemoDu_CsCredits_BackTo02(pthis, animFinished);
}

static DemoDuActionFunc sUpdateFuncs[] = {
    DemoDu_UpdateCs_FM_00, DemoDu_UpdateCs_FM_01, DemoDu_UpdateCs_FM_02, DemoDu_UpdateCs_FM_03, DemoDu_UpdateCs_FM_04,
    DemoDu_UpdateCs_FM_05, DemoDu_UpdateCs_FM_06, DemoDu_UpdateCs_GR_00, DemoDu_UpdateCs_GR_01, DemoDu_UpdateCs_GR_02,
    DemoDu_UpdateCs_GR_03, DemoDu_UpdateCs_GR_04, DemoDu_UpdateCs_GR_05, DemoDu_UpdateCs_GR_06, DemoDu_UpdateCs_GR_07,
    DemoDu_UpdateCs_GR_08, DemoDu_UpdateCs_GR_09, DemoDu_UpdateCs_GR_10, DemoDu_UpdateCs_GR_11, DemoDu_UpdateCs_GR_12,
    DemoDu_UpdateCs_GR_13, DemoDu_UpdateCs_AG_00, DemoDu_UpdateCs_AG_01, DemoDu_UpdateCs_AG_02, DemoDu_UpdateCs_CR_00,
    DemoDu_UpdateCs_CR_01, DemoDu_UpdateCs_CR_02, DemoDu_UpdateCs_CR_03, DemoDu_UpdateCs_CR_04,
};

void DemoDu_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoDu* pthis = (DemoDu*)thisx;

    if (pthis->updateIndex < 0 || pthis->updateIndex >= 29 || sUpdateFuncs[pthis->updateIndex] == NULL) {
        // "The main mode is abnormal!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sUpdateFuncs[pthis->updateIndex](pthis, globalCtx);
}

void DemoDu_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoDu* pthis = (DemoDu*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    switch (pthis->actor.params) {
        case DEMO_DU_CS_GORONS_RUBY:
            DemoDu_InitCs_GoronsRuby(pthis, globalCtx);
            break;

        case DEMO_DU_CS_CHAMBER_AFTER_GANON:
            DemoDu_InitCs_AfterGanon(pthis, globalCtx);
            break;

        case DEMO_DU_CS_CREDITS:
            DemoDu_InitCs_Credits(pthis, globalCtx);
            break;

        default:
            DemoDu_InitCs_FireMedallion(pthis, globalCtx);
            break;
    }
}

void DemoDu_Draw_NoDraw(Actor* thisx, GlobalContext* globalCtx2) {
}

// Similar to DemoDu_Draw_02, but pthis uses POLY_OPA_DISP. Sets the env color to 255.
void DemoDu_Draw_01(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    DemoDu* pthis = (DemoDu*)thisx;
    s16 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = sEyeTextures[eyeTexIndex];
    s32 pad;
    s16 mouthTexIndex = pthis->mouthTexIndex;
    void* mouthTexture = sMouthTextures[mouthTexIndex];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_du.c", 615);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(mouthTexture));
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(gDaruniaNoseSeriousTex));

    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);

    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount, NULL, NULL,
                          pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_du.c", 638);
}

static DemoDuDrawFunc sDrawFuncs[] = {
    DemoDu_Draw_NoDraw,
    DemoDu_Draw_01,
    DemoDu_Draw_02,
};

void DemoDu_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DemoDu* pthis = (DemoDu*)thisx;

    if (pthis->drawIndex < 0 || pthis->drawIndex >= 3 || sDrawFuncs[pthis->drawIndex] == NULL) {
        // "The drawing mode is abnormal!!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawIndex](thisx, globalCtx);
}

ActorInit Demo_Du_InitVars = {
    ACTOR_DEMO_DU,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DU,
    sizeof(DemoDu),
    (ActorFunc)DemoDu_Init,
    (ActorFunc)DemoDu_Destroy,
    (ActorFunc)DemoDu_Update,
    (ActorFunc)DemoDu_Draw,
};

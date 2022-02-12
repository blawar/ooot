#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_DY_YOSEIZO_Z_BG_DY_YOSEIZO_C
#include "actor_common.h"
/*
 * File: z_bg_dy_yoseizo.c
 * Overlay: ovl_Bg_Dy_Yoseizo
 * Description: Great Fairy
 */

#include "z_bg_dy_yoseizo.h"
#include "objects/object_dy_obj/object_dy_obj.h"
#include "vt.h"
#include "overlays/actors/ovl_Demo_Effect/z_demo_effect.h"
#include "scenes/indoors/yousei_izumi_yoko/yousei_izumi_yoko_scene.h"
#include "scenes/indoors/daiyousei_izumi/daiyousei_izumi_scene.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

typedef enum {
    /* 0 */ FAIRY_UPGRADE_MAGIC,
    /* 1 */ FAIRY_UPGRADE_DOUBLE_MAGIC,
    /* 2 */ FAIRY_UPGRADE_HALF_DAMAGE
} BgDyYoseizoRewardType;

typedef enum {
    /* 0 */ FAIRY_SPELL_FARORES_WIND,
    /* 1 */ FAIRY_SPELL_DINS_FIRE,
    /* 2 */ FAIRY_SPELL_NAYRUS_LOVE
} BgDyYoseizoSpellType;

void BgDyYoseizo_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgDyYoseizo_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgDyYoseizo_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgDyYoseizo_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgDyYoseizo_CheckMagicAcquired(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_ChooseType(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SetupSpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_CompleteSpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SetupGreetPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_GreetPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SetupHealPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_HealPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SayFarewell_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SetupSpinShrink(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SpinShrink(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_Vanish(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SetupSpinGrow_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_SpinGrowSetupGive_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_Give_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx);

void BgDyYoseizo_ParticleInit(BgDyYoseizo* pthis, Vec3f* initPos, Vec3f* initVelocity, Vec3f* accel,
                              Color_RGB8* primColor, Color_RGB8* envColor, f32 scale, s16 life, s16 type);
void BgDyYoseizo_ParticleUpdate(BgDyYoseizo* pthis, GlobalContext* globalCtx);
void BgDyYoseizo_ParticleDraw(BgDyYoseizo* pthis, GlobalContext* globalCtx);

static s32 sUnusedGetItemIds[] = { GI_FARORES_WIND, GI_NAYRUS_LOVE, GI_DINS_FIRE };

ActorInit Bg_Dy_Yoseizo_InitVars = {
    ACTOR_BG_DY_YOSEIZO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DY_OBJ,
    sizeof(BgDyYoseizo),
    (ActorFunc)BgDyYoseizo_Init,
    (ActorFunc)BgDyYoseizo_Destroy,
    (ActorFunc)BgDyYoseizo_Update,
    NULL,
};

void BgDyYoseizo_Init(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgDyYoseizo* pthis = (BgDyYoseizo*)pthisx;

    pthis->fountainType = globalCtx->curSpawn;

    if (pthis->fountainType < 0) {
        pthis->fountainType = 0;
    }

    pthis->vanishHeight = pthis->actor.world.pos.y;
    pthis->grownHeight = pthis->vanishHeight + 40.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;

    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        // "Great Fairy Fountain"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 大妖精の泉 ☆☆☆☆☆ %d\n" VT_RST, globalCtx->curSpawn);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGreatFairySkel, &gGreatFairySittingTransitionAnim,
                           pthis->jointTable, pthis->morphTable, 28);
    } else {
        // "Stone/Jewel Fairy Fountain"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 石妖精の泉 ☆☆☆☆☆ %d\n" VT_RST, globalCtx->curSpawn);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGreatFairySkel, &gGreatFairyLayingDownTransitionAnim,
                           pthis->jointTable, pthis->morphTable, 28);
    }
    pthis->actionFunc = BgDyYoseizo_CheckMagicAcquired;
}

void BgDyYoseizo_Destroy(Actor* pthis, GlobalContext* globalCtx) {
}

static Color_RGB8 sParticlePrimColors[] = {
    { 255, 255, 255 }, { 255, 255, 100 }, { 100, 255, 100 }, { 255, 100, 100 }, { 255, 255, 170 },
    { 255, 255, 100 }, { 100, 255, 100 }, { 255, 100, 100 }, { 255, 255, 170 },
};

static Color_RGB8 sParticleEnvColors[] = {
    { 155, 255, 255 }, { 255, 255, 100 }, { 100, 255, 100 }, { 255, 100, 100 }, { 255, 100, 255 },
    { 255, 255, 100 }, { 100, 255, 100 }, { 255, 100, 100 }, { 100, 255, 255 },
};

void BgDyYoseizo_SpawnParticles(BgDyYoseizo* pthis, GlobalContext* globalCtx, s16 type) {
    Vec3f particleInitVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f particleAccel;
    Vec3f particleInitPos;
    Color_RGB8 particlePrimColor;
    Color_RGB8 particleEnvColor;
    f32 spawnPosVariation;
    s32 particleType;
    f32 particleScale;
    s32 i;
    s16 particleLife;

    if (!(pthis->scale < 0.01f)) {
        spawnPosVariation = pthis->scale * 3500.0f;
        particleAccel.x = Rand_ZeroOne() - 0.5f;
        particleAccel.y = Rand_ZeroOne() - 0.5f;
        particleAccel.z = Rand_ZeroOne() - 0.5f;
        for (i = 0; i < 2; i++) {
            if (type == 0) {
                particleType = 0;
                particleScale = 0.4f;
                particleLife = 90;
                particleInitPos.x = pthis->actor.world.pos.x;
                particleInitPos.y = pthis->actor.world.pos.y + spawnPosVariation +
                                    ((Rand_ZeroOne() - 0.5f) * (spawnPosVariation * 0.5f));
                particleInitPos.z = pthis->actor.world.pos.z + 30.0f;
            } else {
                particleLife = 50;
                particleType = type;
                particleScale = 0.2f;
                particleInitPos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(10.0f);

                if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
                    particleInitPos.y = pthis->actor.world.pos.y + spawnPosVariation + 50.0f +
                                        ((Rand_ZeroOne() - 0.5f) * (spawnPosVariation * 0.1f));
                    particleInitPos.z = pthis->actor.world.pos.z + 30.0f;
                } else {
                    particleInitPos.y = pthis->actor.world.pos.y + spawnPosVariation - 30.0f +
                                        ((Rand_ZeroOne() - 0.5f) * (spawnPosVariation * 0.1f));
                    particleInitPos.z = pthis->actor.world.pos.z + 60.0f;
                }

                if (LINK_IS_ADULT) {
                    particleInitPos.y += 20.0f;
                }
            }

            particlePrimColor.r = sParticlePrimColors[particleType].r;
            particlePrimColor.g = sParticlePrimColors[particleType].g;
            particlePrimColor.b = sParticlePrimColors[particleType].b;
            particleEnvColor.r = sParticleEnvColors[particleType].r;
            particleEnvColor.g = sParticleEnvColors[particleType].g;
            particleEnvColor.b = sParticleEnvColors[particleType].b;
            BgDyYoseizo_ParticleInit(pthis, &particleInitPos, &particleInitVelocity, &particleAccel, &particlePrimColor,
                                     &particleEnvColor, particleScale, particleLife, particleType);
        }
    }
}

void BgDyYoseizo_Bob(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    pthis->targetHeight = pthis->grownHeight + pthis->bobOffset;
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetHeight, 0.1f, 10.0f);
    Math_ApproachF(&pthis->bobOffset, 10.0f, 0.1f, 0.5f);

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        pthis->actor.velocity.y = Math_SinS(pthis->bobTimer);
    } else {
        pthis->actor.velocity.y = Math_SinS(pthis->bobTimer) * 0.4f;
    }
}

void BgDyYoseizo_CheckMagicAcquired(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, 0x38)) {
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
            if (!gSaveContext.magicAcquired && (pthis->fountainType != FAIRY_UPGRADE_MAGIC)) {
                Actor_Kill(&pthis->actor);
                return;
            }
        } else {
            if (!gSaveContext.magicAcquired) {
                Actor_Kill(&pthis->actor);
                return;
            }
        }
        func_8002DF54(globalCtx, &pthis->actor, 1);
        pthis->actionFunc = BgDyYoseizo_ChooseType;
    }
}

void BgDyYoseizo_ChooseType(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    s32 givingReward;

    func_8002DF54(globalCtx, &pthis->actor, 1);
    // "Mode"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ もうど ☆☆☆☆☆ %d\n" VT_RST, globalCtx->msgCtx.ocarinaMode);
    givingReward = false;

    if (globalCtx->sceneNum != SCENE_DAIYOUSEI_IZUMI) {
        switch (pthis->fountainType) {
            case FAIRY_SPELL_FARORES_WIND:
                if (!(gSaveContext.itemGetInf[1] & 0x100)) {
                    givingReward = true;
                }
                break;
            case FAIRY_SPELL_DINS_FIRE:
                if (!(gSaveContext.itemGetInf[1] & 0x200)) {
                    givingReward = true;
                }
                break;
            case FAIRY_SPELL_NAYRUS_LOVE:
                if (!(gSaveContext.itemGetInf[1] & 0x400)) {
                    givingReward = true;
                }
                break;
        }
    } else {
        switch (pthis->fountainType) {
            case FAIRY_UPGRADE_MAGIC:
                if (!gSaveContext.magicAcquired || BREG(2)) {
                    // "Spin Attack speed UP"
                    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 回転切り速度ＵＰ ☆☆☆☆☆ \n" VT_RST);
                    pthis->givingSpell = true;
                    givingReward = true;
                }
                break;
            case FAIRY_UPGRADE_DOUBLE_MAGIC:
                if (!gSaveContext.doubleMagic) {
                    // "Magic Meter doubled"
                    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 魔法ゲージメーター倍増 ☆☆☆☆☆ \n" VT_RST);
                    pthis->givingSpell = true;
                    givingReward = true;
                }
                break;
            case FAIRY_UPGRADE_HALF_DAMAGE:
                if (!gSaveContext.doubleDefense) {
                    // "Damage halved"
                    osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ ダメージ半減 ☆☆☆☆☆ \n" VT_RST);
                    pthis->givingSpell = true;
                    givingReward = true;
                }
                break;
        }
    }

    if (givingReward) {
        if (gSaveContext.sceneSetupIndex < 4) {
            if (globalCtx->sceneNum != SCENE_DAIYOUSEI_IZUMI) {
                switch (pthis->fountainType) {
                    case FAIRY_SPELL_FARORES_WIND:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyFaroresWindCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                    case FAIRY_SPELL_DINS_FIRE:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyDinsFireCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                    case FAIRY_SPELL_NAYRUS_LOVE:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyNayrusLoveCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                }
            } else {
                switch (pthis->fountainType) {
                    case FAIRY_UPGRADE_MAGIC:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyMagicCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                    case FAIRY_UPGRADE_DOUBLE_MAGIC:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyDoubleMagicCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                    case FAIRY_UPGRADE_HALF_DAMAGE:
                        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGreatFairyDoubleDefenceCs);
                        gSaveContext.cutsceneTrigger = 1;
                        break;
                }
            }
        }
        pthis->actionFunc = BgDyYoseizo_SetupSpinGrow_Reward;
        return;
    }

    globalCtx->envCtx.unk_BF = 2;

    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        OnePointCutscene_Init(globalCtx, 8603, -99, NULL, MAIN_CAM);
    } else {
        OnePointCutscene_Init(globalCtx, 8604, -99, NULL, MAIN_CAM);
    };

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GREAT_FAIRY_APPEAR);
    pthis->actor.draw = BgDyYoseizo_Draw;
    pthis->actionFunc = BgDyYoseizo_SetupSpinGrow_NoReward;
}

// Sets animations for spingrow
void BgDyYoseizo_SetupSpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairySittingTransitionAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairySittingTransitionAnim, 1.0f, 0.0f, pthis->frameCount,
                         ANIMMODE_ONCE, -10.0f);
    } else {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairyLayingDownTransitionAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairyLayingDownTransitionAnim, 1.0f, 0.0f, pthis->frameCount,
                         ANIMMODE_ONCE, -10.0f);
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_FR_LAUGH_0);
    func_8002DF54(globalCtx, &pthis->actor, 1);
    pthis->actionFunc = BgDyYoseizo_SpinGrow_NoReward;
}

void BgDyYoseizo_SpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 1);
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->grownHeight, pthis->heightFraction, 100.0f);
    Math_ApproachF(&pthis->scale, 0.035f, pthis->scaleFraction, 0.005f);
    Math_ApproachF(&pthis->heightFraction, 0.8f, 0.1f, 0.02f);
    Math_ApproachF(&pthis->scaleFraction, 0.2f, 0.03f, 0.05f);
    // Finished growing
    if (pthis->scale >= 0.034f) {
        if ((pthis->actor.shape.rot.y > -8000) && (pthis->actor.shape.rot.y < 1000)) {
            SkelAnime_Update(&pthis->skelAnime);
            // Turn to front
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, 0, 5, 1000, 0);
            if (fabsf(pthis->actor.shape.rot.y) < 50.0f) {
                pthis->actionFunc = BgDyYoseizo_CompleteSpinGrow_NoReward;
            }
        } else {
            pthis->actor.shape.rot.y += 3000;
        }
    } else {
        pthis->actor.shape.rot.y += 3000;
    }
    BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
}

void BgDyYoseizo_CompleteSpinGrow_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    f32 curFrame = pthis->skelAnime.curFrame;

    func_8002DF54(globalCtx, &pthis->actor, 1);

    if ((pthis->frameCount * 1273.0f) <= pthis->bobTimer) {
        pthis->bobTimer = 0.0f;
    }

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->frameCount <= curFrame) && !pthis->animationChanged) {
        pthis->actionFunc = BgDyYoseizo_SetupGreetPlayer_NoReward;
    }
}

void BgDyYoseizo_SetupGreetPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 1);

    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairySittingAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairySittingAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                         -10.0f);
    } else {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairyLayingSidewaysAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairyLayingSidewaysAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                         -10.0f);
    }

    pthis->actor.textId = 0xDB;
    pthis->dialogState = TEXT_STATE_EVENT;
    Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
    BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
    pthis->actionFunc = BgDyYoseizo_GreetPlayer_NoReward;
}

void BgDyYoseizo_GreetPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    func_8002DF54(globalCtx, &pthis->actor, 1);
    pthis->bobTimer = pthis->skelAnime.curFrame * 1273.0f;

    if ((pthis->frameCount * 1273.0f) <= pthis->bobTimer) {
        pthis->bobTimer = 0.0f;
    }

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->dialogState == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        Interface_ChangeAlpha(5);
        pthis->actionFunc = BgDyYoseizo_SetupHealPlayer_NoReward;
    }

    BgDyYoseizo_Bob(pthis, globalCtx);
    BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
}

void BgDyYoseizo_SetupHealPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairyGivingUpgradeAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairyGivingUpgradeAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_ONCE,
                         -10.0f);
    } else {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAnim_005810);
        Animation_Change(&pthis->skelAnime, &gGreatFairyAnim_005810, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_ONCE,
                         -10.0f);
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_FR_SMILE_0);
    pthis->mouthState = 1;
    pthis->actionFunc = BgDyYoseizo_HealPlayer_NoReward;
}

void BgDyYoseizo_HealPlayer_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 curFrame = pthis->skelAnime.curFrame;
    Vec3f beamPos;
    s16 beamParams;

    if (pthis->animationChanged) {
        pthis->bobTimer = pthis->skelAnime.curFrame * 1300.0f;
        if ((pthis->frameCount * 1300.0f) <= pthis->bobTimer) {
            pthis->bobTimer = 0.0f;
        }
    }

    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->frameCount <= curFrame) && !(pthis->animationChanged)) {
        if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
            pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAfterUpgradeAnim);
            Animation_Change(&pthis->skelAnime, &gGreatFairyAfterUpgradeAnim, 1.0f, 0.0f, pthis->frameCount,
                             ANIMMODE_LOOP, -10.0f);
        } else {
            pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAfterSpellAnim);
            Animation_Change(&pthis->skelAnime, &gGreatFairyAfterSpellAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                             -10.0f);
        }
        pthis->healingTimer = 150;
        pthis->animationChanged = true;
        if (!pthis->givingSpell) {
            beamPos.x = player->actor.world.pos.x;
            beamPos.y = player->actor.world.pos.y + 200.0f;
            beamPos.z = player->actor.world.pos.z;

            beamParams = ((globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) ? 0 : 1);

            pthis->beam =
                (EnDyExtra*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_DY_EXTRA,
                                               beamPos.x, beamPos.y, beamPos.z, 0, 0, 0, beamParams);
        }
    }
    if (pthis->refillTimer > 1) {
        pthis->refillTimer--;
    }

    if (pthis->healingTimer >= 110) {
        pthis->healingTimer--;
    }

    if (pthis->healingTimer == 110) {
        gSaveContext.healthAccumulator = 0x140;
        Magic_Fill(globalCtx);
        pthis->refillTimer = 200;
    }

    if (((gSaveContext.healthCapacity == gSaveContext.health) && (gSaveContext.magic == gSaveContext.unk_13F4)) ||
        (pthis->refillTimer == 1)) {
        pthis->healingTimer--;
        if (pthis->healingTimer == 90) {
            if (!pthis->givingSpell) {
                pthis->beam->trigger = 1;
            }
            pthis->givingSpell = false;
        }
    }

    if (pthis->healingTimer == 1) {
        pthis->actor.textId = 0xDA;
        pthis->dialogState = TEXT_STATE_EVENT;
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->actionFunc = BgDyYoseizo_SayFarewell_NoReward;
        return;
    }
    BgDyYoseizo_Bob(pthis, globalCtx);
}

void BgDyYoseizo_SayFarewell_NoReward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    pthis->bobTimer = pthis->skelAnime.curFrame * 1400.0f;

    if (pthis->bobTimer >= (pthis->frameCount * 1400.0f)) {
        pthis->bobTimer = 0.0f;
    }

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->dialogState == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->mouthState = 0;
        pthis->actionFunc = BgDyYoseizo_SetupSpinShrink;
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
    }

    BgDyYoseizo_Bob(pthis, globalCtx);
    BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
}

void BgDyYoseizo_SetupSpinShrink(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairyJewelFountainSpinShrinkAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairyJewelFountainSpinShrinkAnim, 1.0f, 0.0f, pthis->frameCount,
                         ANIMMODE_ONCE, -10.0f);
    } else {
        pthis->frameCount = Animation_GetLastFrame(&gGreatFairySpellFountainSpinShrinkAnim);
        Animation_Change(&pthis->skelAnime, &gGreatFairySpellFountainSpinShrinkAnim, 1.0f, 0.0f, pthis->frameCount,
                         ANIMMODE_ONCE, -10.0f);
    }

    pthis->vanishTimer = 5;
    pthis->scaleFraction = 0.0f;
    pthis->heightFraction = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_FR_LAUGH_0);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GREAT_FAIRY_VANISH);
    pthis->actionFunc = BgDyYoseizo_SpinShrink;
}

void BgDyYoseizo_SpinShrink(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->vanishTimer == 0) {
        if (pthis->scale < 0.003f) {
            pthis->vanishTimer = 30;
            pthis->actionFunc = BgDyYoseizo_Vanish;
        } else {
            Math_ApproachF(&pthis->actor.world.pos.y, pthis->vanishHeight, pthis->heightFraction, 100.0f);
            Math_ApproachZeroF(&pthis->scale, pthis->scaleFraction, 0.005f);
            Math_ApproachF(&pthis->heightFraction, 0.8f, 0.1f, 0.02f);
            Math_ApproachF(&pthis->scaleFraction, 0.2f, 0.03f, 0.05f);
            pthis->actor.shape.rot.y += 3000;
            BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
        }
    }
}

void BgDyYoseizo_Vanish(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    Actor* findOcarinaSpot;

    if (pthis->vanishTimer == 0) {
        func_8002DF54(globalCtx, &pthis->actor, 7);
        globalCtx->envCtx.unk_BF = 0;
        findOcarinaSpot = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

        while (findOcarinaSpot != NULL) {
            if (findOcarinaSpot->id != ACTOR_EN_OKARINA_TAG) {
                findOcarinaSpot = findOcarinaSpot->next;
                continue;
            }
            Actor_Kill(findOcarinaSpot);
            break;
        }

        Flags_UnsetSwitch(globalCtx, 0x38);
        Actor_Kill(&pthis->actor);
    }
}

void BgDyYoseizo_SetupSpinGrow_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        if ((globalCtx->csCtx.npcActions[0] != NULL) && (globalCtx->csCtx.npcActions[0]->action == 2)) {
            pthis->actor.draw = BgDyYoseizo_Draw;
            func_8002DF54(globalCtx, &pthis->actor, 1);
            pthis->finishedSpinGrow = false;

            if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairySittingTransitionAnim);
                Animation_Change(&pthis->skelAnime, &gGreatFairySittingTransitionAnim, 1.0f, 0.0f, pthis->frameCount,
                                 ANIMMODE_ONCE, -10.0f);
            } else {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairyLayingDownTransitionAnim);
                Animation_Change(&pthis->skelAnime, &gGreatFairyLayingDownTransitionAnim, 1.0f, 0.0f, pthis->frameCount,
                                 ANIMMODE_ONCE, -10.0f);
            }

            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GREAT_FAIRY_APPEAR);
            pthis->actionFunc = BgDyYoseizo_SpinGrowSetupGive_Reward;
        }
    }
}

void BgDyYoseizo_SpinGrowSetupGive_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    f32 curFrame = pthis->skelAnime.curFrame;

    if (!pthis->finishedSpinGrow) {
        Math_ApproachF(&pthis->actor.world.pos.y, pthis->grownHeight, pthis->heightFraction, 100.0f);
        Math_ApproachF(&pthis->scale, 0.035f, pthis->scaleFraction, 0.005f);
        Math_ApproachF(&pthis->heightFraction, 0.8f, 0.1f, 0.02f);
        Math_ApproachF(&pthis->scaleFraction, 0.2f, 0.03f, 0.05f);
        // Finished growing
        if (pthis->scale >= 0.034f) {
            if ((pthis->actor.shape.rot.y > -8000) && (pthis->actor.shape.rot.y < 1000)) {
                SkelAnime_Update(&pthis->skelAnime);
                // Spin until facing front
                Math_ApproachS(&pthis->actor.shape.rot.y, 0, 5, 1000);
                if (fabsf(pthis->actor.shape.rot.y) < 50.0f) {
                    pthis->finishedSpinGrow = true;
                }
            } else {
                pthis->actor.shape.rot.y += 3000;
            }
        } else {
            pthis->actor.shape.rot.y += 3000;
        }
    } else {
        SkelAnime_Update(&pthis->skelAnime);

        if ((pthis->frameCount <= curFrame) && !pthis->animationChanged) {
            if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairySittingAnim);
                Animation_Change(&pthis->skelAnime, &gGreatFairySittingAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                                 -10.0f);
            } else {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairyLayingSidewaysAnim);
                Animation_Change(&pthis->skelAnime, &gGreatFairyLayingSidewaysAnim, 1.0f, 0.0f, pthis->frameCount,
                                 ANIMMODE_LOOP, -10.0f);
            }
            pthis->animationChanged = true;
        }

        if ((globalCtx->csCtx.state != CS_STATE_IDLE) &&
            ((globalCtx->csCtx.npcActions[0] != NULL) && (globalCtx->csCtx.npcActions[0]->action == 3))) {
            pthis->finishedSpinGrow = pthis->animationChanged = false;
            if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairyGivingUpgradeAnim);
                Animation_Change(&pthis->skelAnime, &gGreatFairyGivingUpgradeAnim, 1.0f, 0.0f, pthis->frameCount,
                                 ANIMMODE_ONCE, -10.0f);
            } else {
                pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAnim_005810);
                Animation_Change(&pthis->skelAnime, &gGreatFairyAnim_005810, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_ONCE,
                                 -10.0f);
            }
            pthis->mouthState = 1;
            pthis->actionFunc = BgDyYoseizo_Give_Reward;
        }
    }
    BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
}

static s16 sDemoEffectLightColors[] = { DEMO_EFFECT_LIGHT_GREEN, DEMO_EFFECT_LIGHT_RED, DEMO_EFFECT_LIGHT_BLUE };

static s16 sExItemTypes[] = { EXITEM_MAGIC_WIND, EXITEM_MAGIC_FIRE, EXITEM_MAGIC_DARK };

static s16 sItemGetFlags[] = { 0x100, 0x200, 0x400 };

static u8 sItemIds[] = { ITEM_FARORES_WIND, ITEM_DINS_FIRE, ITEM_NAYRUS_LOVE };

void BgDyYoseizo_Give_Reward(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    f32 curFrame = pthis->skelAnime.curFrame;
    Player* player = GET_PLAYER(globalCtx);
    s16 actionIndex;
    s16 demoEffectParams;
    Vec3f itemPos;

    if (pthis->animationChanged) {
        pthis->bobTimer = pthis->skelAnime.curFrame * 1400.0f;
        if ((pthis->frameCount * 1400.0f) <= pthis->bobTimer) {
            pthis->bobTimer = 0.0f;
        }
    }
    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->frameCount <= curFrame) && !pthis->animationChanged) {
        if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
            pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAfterUpgradeAnim);
            Animation_Change(&pthis->skelAnime, &gGreatFairyAfterUpgradeAnim, 1.0f, 0.0f, pthis->frameCount,
                             ANIMMODE_LOOP, -10.0f);
        } else {
            pthis->frameCount = Animation_GetLastFrame(&gGreatFairyAfterSpellAnim);
            Animation_Change(&pthis->skelAnime, &gGreatFairyAfterSpellAnim, 1.0f, 0.0f, pthis->frameCount, ANIMMODE_LOOP,
                             -10.0f);
        }
        pthis->animationChanged = true;
    }

    if (globalCtx->csCtx.npcActions[0]->action == 13) {
        pthis->actionFunc = BgDyYoseizo_SetupSpinShrink;
        return;
    }

    if ((globalCtx->csCtx.npcActions[0]->action >= 4) && (globalCtx->csCtx.npcActions[0]->action < 7)) {
        actionIndex = globalCtx->csCtx.npcActions[0]->action - 4;
        if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
            actionIndex++;
            BgDyYoseizo_SpawnParticles(pthis, globalCtx, actionIndex);

        } else if (!pthis->lightBallSpawned) {
            demoEffectParams = ((s16)(sDemoEffectLightColors[actionIndex] << 0xC) | DEMO_EFFECT_LIGHT);
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_EFFECT, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, (s32)demoEffectParams);
            pthis->lightBallSpawned = true;
        }
    } else {
        BgDyYoseizo_SpawnParticles(pthis, globalCtx, 0);
    }

    if ((globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) && (globalCtx->csCtx.npcActions[0]->action >= 10) &&
        (globalCtx->csCtx.npcActions[0]->action < 13)) {
        actionIndex = globalCtx->csCtx.npcActions[0]->action - 10;

        switch (actionIndex) {
            case FAIRY_UPGRADE_MAGIC:
                gSaveContext.magicAcquired = true;
                gSaveContext.unk_13F6 = 0x30;
                Interface_ChangeAlpha(9);
                break;
            case FAIRY_UPGRADE_DOUBLE_MAGIC:
                if (!gSaveContext.magicAcquired) {
                    gSaveContext.magicAcquired = true;
                }
                gSaveContext.doubleMagic = true;
                gSaveContext.unk_13F6 = 0x60;
                gSaveContext.magicLevel = 0;
                Interface_ChangeAlpha(9);
                break;
            case FAIRY_UPGRADE_HALF_DAMAGE:
                gSaveContext.doubleDefense = true;
                Interface_ChangeAlpha(9);
                break;
        }

        if (!pthis->healing) {
            gSaveContext.healthAccumulator = 0x140;
            pthis->healing = true;
            if (actionIndex == 2) {
                Magic_Fill(globalCtx);
            }
        }
    }

    if ((globalCtx->sceneNum != SCENE_DAIYOUSEI_IZUMI) && (globalCtx->csCtx.npcActions[0]->action >= 14) &&
        (globalCtx->csCtx.npcActions[0]->action < 17)) {
        actionIndex = globalCtx->csCtx.npcActions[0]->action - 14;

        if (!pthis->itemSpawned) {
            itemPos.x = player->actor.world.pos.x;
            itemPos.y = (LINK_IS_ADULT ? player->actor.world.pos.y + 73.0f : player->actor.world.pos.y + 53.0f);
            itemPos.z = player->actor.world.pos.z;

            pthis->item =
                (EnExItem*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_ITEM,
                                              itemPos.x, itemPos.y, itemPos.z, 0, 0, 0, sExItemTypes[actionIndex]);

            if (pthis->item != NULL) {
                if (gSaveContext.magicAcquired == 0) {
                    gSaveContext.magicAcquired = 1;
                } else {
                    Magic_Fill(globalCtx);
                }

                pthis->itemSpawned = true;
                gSaveContext.healthAccumulator = 0x140;
                Interface_ChangeAlpha(9);
                gSaveContext.itemGetInf[1] |= sItemGetFlags[actionIndex];
                Item_Give(globalCtx, sItemIds[actionIndex]);
            }
        } else {
            pthis->item->actor.world.pos.x = player->actor.world.pos.x;
            pthis->item->actor.world.pos.y =
                (LINK_IS_ADULT ? player->actor.world.pos.y + 73.0f : player->actor.world.pos.y + 53.0f);
            pthis->item->actor.world.pos.z = player->actor.world.pos.z;
            pthis->item->scale = 0.3f;
        }
    }

    if ((globalCtx->sceneNum != SCENE_DAIYOUSEI_IZUMI) && (globalCtx->csCtx.npcActions[0]->action == 17) &&
        (pthis->item != NULL)) {
        Actor_Kill(&pthis->item->actor);
        pthis->item = NULL;
    }

    if ((globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) && (globalCtx->csCtx.npcActions[0]->action == 18)) {
        pthis->giveDefenseHearts = true;
    }

    if (pthis->giveDefenseHearts) {
        if (gSaveContext.inventory.defenseHearts < 20) {
            gSaveContext.inventory.defenseHearts++;
        }
    }

    if ((globalCtx->csCtx.npcActions[0]->action >= 19) && (globalCtx->csCtx.npcActions[0]->action < 22) &&
        !pthis->warpEffectSpawned) {
        actionIndex = globalCtx->csCtx.npcActions[0]->action - 11;
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_WARP1, player->actor.world.pos.x,
                    player->actor.world.pos.y, player->actor.world.pos.z, 0, 0, 0, actionIndex);
        pthis->warpEffectSpawned = true;
    }
    BgDyYoseizo_Bob(pthis, globalCtx);
}

void BgDyYoseizo_Update(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgDyYoseizo* pthis = (BgDyYoseizo*)pthisx;
    s32 phi_v1;

    pthis->absoluteTimer++;

    if (pthis->vanishTimer != 0) {
        pthis->vanishTimer--;
    }
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    }
    if (pthis->unusedTimer != 0) {
        pthis->unusedTimer--;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        phi_v1 = 0;
        if (globalCtx->sceneNum == SCENE_DAIYOUSEI_IZUMI) {
            if ((globalCtx->csCtx.frames == 32) || (globalCtx->csCtx.frames == 291) ||
                (globalCtx->csCtx.frames == 426) || (globalCtx->csCtx.frames == 851)) {
                phi_v1 = 1;
            }
            if (globalCtx->csCtx.frames == 101) {
                phi_v1 = 2;
            }
        } else {
            if ((globalCtx->csCtx.frames == 35) || (globalCtx->csCtx.frames == 181) ||
                (globalCtx->csCtx.frames == 462) || (globalCtx->csCtx.frames == 795)) {
                phi_v1 = 1;
            }
            if (globalCtx->csCtx.frames == 90) {
                phi_v1 = 2;
            }
        }

        if (phi_v1 == 1) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_FR_SMILE_0);
        }
        if (phi_v1 == 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_FR_LAUGH_0);
        }
    }

    if ((pthis->blinkTimer == 0) && (pthis->actionFunc != BgDyYoseizo_HealPlayer_NoReward)) {
        pthis->eyeState++;
        pthis->eyeState2++;
        if (pthis->eyeState >= 3) {
            pthis->eyeState = pthis->eyeState2 = 0;
            pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }

    Actor_MoveForward(&pthis->actor);
    pthis->heightOffset = pthis->scale * 7500.0f;
    Actor_SetFocus(&pthis->actor, pthis->heightOffset);
    pthis->actor.focus.pos.y = pthis->heightOffset;
    func_80038290(globalCtx, &pthis->actor, &pthis->headRot, &pthis->torsoRot, pthis->actor.focus.pos);
    BgDyYoseizo_ParticleUpdate(pthis, globalCtx);
    Actor_SetScale(&pthis->actor, pthis->scale);
}

s32 BgDyYoseizo_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                 void* pthisx) {
    BgDyYoseizo* pthis = (BgDyYoseizo*)pthisx;

    if (limbIndex == 8) { // Torso
        rot->x += pthis->torsoRot.y;
    }
    if (limbIndex == 15) { // Head
        rot->x += pthis->headRot.y;
        rot->z += pthis->headRot.z;
    }
    return 0;
}

static void* sEyeTextures[] = {
    gGreatFairyEyeOpenTex,   // Open
    gGreatFairyEyeHalfTex,   // Half
    gGreatFairyEyeClosedTex, // Closed
};

static void* sMouthTextures[] = {
    gGreatFairyMouthClosedTex, // Closed
    gGreatFairyMouthOpenTex,   // Open
};

void BgDyYoseizo_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgDyYoseizo* pthis = (BgDyYoseizo*)pthisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_dy_yoseizo.c", 1609);
    if (pthis->actionFunc != BgDyYoseizo_Vanish) {
        func_80093D18(globalCtx->state.gfxCtx);

        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeState]));

        // This was probably intended to allow pthis actor to wink, but segment 09 is not used in the dList for the head,
        // so it can only blink
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeState2]));

        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(sMouthTextures[pthis->mouthState]));

        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, BgDyYoseizo_OverrideLimbDraw, NULL, pthis);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_dy_yoseizo.c", 1629);
    BgDyYoseizo_ParticleDraw(pthis, globalCtx);
}

void BgDyYoseizo_ParticleInit(BgDyYoseizo* pthis, Vec3f* initPos, Vec3f* initVelocity, Vec3f* accel,
                              Color_RGB8* primColor, Color_RGB8* envColor, f32 scale, s16 life, s16 type) {
    BgDyYoseizoParticle* particle;
    s16 i;

    particle = pthis->particles;

    for (i = 0; i < 200; i++, particle++) {
        if (particle->alive == 0) {
            particle->alive = 1;
            particle->pos = *initPos;
            particle->velocity = *initVelocity;
            particle->accel = *accel;
            particle->primColor = *primColor;
            particle->alpha = 0;
            particle->envColor = *envColor;
            particle->scale = scale;
            particle->timer = life;
            particle->type = type;
            particle->pitch = 0.0f;
            particle->yaw = Rand_CenteredFloat(30000.0f);
            particle->roll = 0.0f;
            return;
        }
    }
}

void BgDyYoseizo_ParticleUpdate(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    BgDyYoseizoParticle* particle = pthis->particles;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f sp94;
    Vec3f sp88;
    f32 goalPitch;
    f32 goalYaw;
    s16 i = 0;

    for (i = 0; i < 200; i++, particle++) {
        if (particle->alive != 0) {
            particle->roll += 3000.0f;

            if (particle->type == 0) {
                particle->pos.x += particle->velocity.x;
                particle->pos.y += particle->velocity.y;
                particle->pos.z += particle->velocity.z;
                particle->velocity.x += particle->accel.x;
                particle->velocity.y += particle->accel.y;
                particle->velocity.z += particle->accel.z;
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_HEALING - SFX_FLAG);

                sp94 = player->actor.world.pos;
                sp94.y = player->actor.world.pos.y - 150.0f;
                sp94.z = player->actor.world.pos.z - 50.0f;

                goalPitch = Math_Vec3f_Pitch(&particle->pos, &sp94);
                goalYaw = Math_Vec3f_Yaw(&particle->pos, &sp94);

                Math_ApproachF(&particle->pitch, goalPitch, 0.9f, 5000.0f);
                Math_ApproachF(&particle->yaw, goalYaw, 0.9f, 5000.0f);
                Matrix_Push();
                Matrix_RotateY(BINANG_TO_RAD(particle->yaw), MTXMODE_NEW);
                Matrix_RotateX(BINANG_TO_RAD(particle->pitch), MTXMODE_APPLY);

                sp94.x = sp94.y = sp94.z = 3.0f;

                Matrix_MultVec3f(&sp94, &sp88);
                Matrix_Pop();
                particle->pos.x += sp88.x;
                particle->pos.y += sp88.y;
                particle->pos.z += sp88.z;
            }
        }

        // fade up, fade down, vanish and reset
        if (particle->timer != 0) {
            particle->timer--;
            particle->alpha += 30;

            if (particle->alpha > 255) {
                particle->alpha = 255;
            }
        } else {
            particle->alpha -= 30;

            if (particle->alpha <= 0) {
                particle->alpha = particle->alive = 0;
            }
        }
    }
}

void BgDyYoseizo_ParticleDraw(BgDyYoseizo* pthis, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u8 phi_s3 = 0;
    BgDyYoseizoParticle* particle = pthis->particles;
    s16 i;

    OPEN_DISPS(gfxCtx, "../z_bg_dy_yoseizo.c", 1767);
    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < 200; i++, particle++) {
        if (particle->alive == 1) {
            if (phi_s3 == 0) {
                gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gGreatFairyParticleAppearDL));
                gDPPipeSync(POLY_XLU_DISP++);

                phi_s3++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, particle->primColor.r, particle->primColor.g, particle->primColor.b,
                            particle->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, particle->envColor.r, particle->envColor.g, particle->envColor.b, 0);

            Matrix_Translate(particle->pos.x, particle->pos.y, particle->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(particle->scale, particle->scale, 1.0f, MTXMODE_APPLY);
            Matrix_RotateZ(particle->roll, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_bg_dy_yoseizo.c", 1810),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gGreatFairyParticleAliveDL));
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_bg_dy_yoseizo.c", 1819);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FHG_FIRE_Z_EN_FHG_FIRE_C
#include "actor_common.h"
#include "z_kankyo.h"
/*
 * File: z_en_fhg_fire.c
 * Overlay: ovl_En_Fhg_Fire
 * Description: Phantom Ganon's Lighting Attack
 */

#include "z_en_fhg_fire.h"
#include "objects/object_fhg/object_fhg.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "overlays/actors/ovl_Boss_Ganondrof/z_boss_ganondrof.h"
#include "overlays/actors/ovl_En_fHG/z_en_fhg.h"
#include "overlays/effects/ovl_Effect_Ss_Fhg_Flash/z_eff_ss_fhg_flash.h"
#include "def/code_800A9F30.h"
#include "def/audio_bank.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)


void EnFhgFire_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFhgFire_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnFhgFire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFhgFire_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFhgFire_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFhgFire_LightningStrike(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_LightningTrail(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_LightningShock(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_LightningBurst(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_SpearLight(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_EnergyBall(EnFhgFire* pthis, GlobalContext* globalCtx);
void EnFhgFire_PhantomWarp(EnFhgFire* pthis, GlobalContext* globalCtx);

ActorInit En_Fhg_Fire_InitVars = {
    0,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FHG,
    sizeof(EnFhgFire),
    (ActorFunc)EnFhgFire_Init,
    (ActorFunc)EnFhgFire_Destroy,
    (ActorFunc)EnFhgFire_Update,
    (ActorFunc)EnFhgFire_Draw,
    (ActorFunc)EnFhgFire_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK6,
        { 0x00100700, 0x03, 0x20 },
        { 0x0D900700, 0x00, 0x00 },
        TOUCH_ON,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 30, 10, { 0, 0, 0 } },
};

void EnFhgFire_SetUpdate(EnFhgFire* pthis, EnFhgFireUpdateFunc updateFunc) {
    pthis->updateFunc = updateFunc;
}

void EnFhgFire_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFhgFire* pthis = (EnFhgFire*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
    if ((pthis->actor.params == FHGFIRE_LIGHTNING_SHOCK) || (pthis->actor.params == FHGFIRE_LIGHTNING_BURST) ||
        (pthis->actor.params == FHGFIRE_ENERGY_BALL)) {
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    }
    pthis->fwork[FHGFIRE_ALPHA] = 200.0f;
    Actor_SetScale(&pthis->actor, 0.0f);

    if (pthis->actor.params == FHGFIRE_LIGHTNING_STRIKE) {
        EnFhgFire_SetUpdate(pthis, EnFhgFire_LightningStrike);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_THUNDER);
    } else if (pthis->actor.params >= FHGFIRE_LIGHTNING_TRAIL) {
        EnFhgFire_SetUpdate(pthis, EnFhgFire_LightningTrail);
        pthis->actor.shape.rot = pthis->actor.world.rot;
    }
    if (pthis->actor.params == FHGFIRE_LIGHTNING_SHOCK) {
        pthis->actor.draw = NULL;
        EnFhgFire_SetUpdate(pthis, EnFhgFire_LightningShock);
        pthis->actor.speedXZ = 30.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_SPARK);
    } else if (pthis->actor.params == FHGFIRE_LIGHTNING_BURST) {
        EnFhgFire_SetUpdate(pthis, EnFhgFire_LightningBurst);
        pthis->fwork[FHGFIRE_ALPHA] = 255.0f;
        pthis->work[FHGFIRE_TIMER] = 32;
        pthis->work[FHGFIRE_FX_TIMER] = 50;
        pthis->lensFlareTimer = 10;

        pthis->fwork[FHGFIRE_BURST_SCALE] = pthis->actor.world.rot.x / 100.0f;
        pthis->collider.dim.radius = pthis->actor.world.rot.x * 0.13f;
        pthis->collider.dim.height = pthis->actor.world.rot.x * 0.13f;
        pthis->collider.dim.yShift = 0;
    } else if (pthis->actor.params == FHGFIRE_SPEAR_LIGHT) {
        osSyncPrintf("yari hikari ct 1\n"); // "light spear"
        EnFhgFire_SetUpdate(pthis, EnFhgFire_SpearLight);
        osSyncPrintf("yari hikari ct 2\n");
        pthis->work[FHGFIRE_TIMER] = pthis->actor.world.rot.x;
        pthis->work[FHGFIRE_FIRE_MODE] = pthis->actor.world.rot.y;
    } else if ((pthis->actor.params == FHGFIRE_WARP_EMERGE) || (pthis->actor.params == FHGFIRE_WARP_RETREAT) ||
               (pthis->actor.params == FHGFIRE_WARP_DEATH)) {
        Actor_SetScale(&pthis->actor, 7.0f);
        EnFhgFire_SetUpdate(pthis, EnFhgFire_PhantomWarp);
        if (pthis->actor.params == FHGFIRE_WARP_DEATH) {
            pthis->work[FHGFIRE_TIMER] = 440;
            pthis->actor.scale.z = 1.0f;
        } else {
            pthis->work[FHGFIRE_TIMER] = 76;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_S);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_S2);
        }
    } else if (pthis->actor.params == FHGFIRE_ENERGY_BALL) {
        f32 dxL;
        f32 dyL;
        f32 dzL;
        f32 dxzL;

        pthis->actor.speedXZ = (pthis->actor.world.rot.x == 0) ? 8.0f : 3.0f;
        EnFhgFire_SetUpdate(pthis, EnFhgFire_EnergyBall);

        pthis->work[FHGFIRE_TIMER] = 70;
        pthis->work[FHGFIRE_FX_TIMER] = 2;

        dxL = player->actor.world.pos.x - pthis->actor.world.pos.x;
        dyL = player->actor.world.pos.y + 30.0f - pthis->actor.world.pos.y;
        dzL = player->actor.world.pos.z - pthis->actor.world.pos.z;
        pthis->actor.world.rot.y = Math_FAtan2F(dxL, dzL) * (0x8000 / M_PI);
        dxzL = sqrtf(SQ(dxL) + SQ(dzL));
        pthis->actor.world.rot.x = Math_FAtan2F(dyL, dxzL) * (0x8000 / M_PI);
        pthis->collider.dim.radius = 40;
        pthis->collider.dim.height = 50;
        pthis->collider.dim.yShift = -25;
        pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                  pthis->actor.world.pos.z, 255, 255, 255, 255);
    }
}

void EnFhgFire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFhgFire* pthis = (EnFhgFire*)thisx;

    if ((pthis->actor.params == FHGFIRE_LIGHTNING_SHOCK) || (pthis->actor.params == FHGFIRE_LIGHTNING_BURST) ||
        (pthis->actor.params == FHGFIRE_ENERGY_BALL)) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }

    if (pthis->actor.params == FHGFIRE_ENERGY_BALL) {
        LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
    }
}

void EnFhgFire_LightningStrike(EnFhgFire* pthis, GlobalContext* globalCtx) {
    Camera* camera = Gameplay_GetCamera(globalCtx, 0);
    s16 i;

    switch (pthis->work[FHGFIRE_FIRE_MODE]) {
        case STRIKE_INIT:
            pthis->work[FHGFIRE_FIRE_MODE] = STRIKE_BURST;
            pthis->work[FHGFIRE_TIMER] = 7;
            break;
        case STRIKE_BURST:
            pthis->actor.shape.rot.y =
                Camera_GetInputDirYaw(camera) + 0x8000 * (pthis->work[FHGFIRE_VARIANCE_TIMER] & 0xFF);
            Math_ApproachF(&pthis->fwork[FHGFIRE_SCALE], 1.0f, 1.0f, 0.2f);

            if (pthis->work[FHGFIRE_TIMER] == 0) {
                pthis->work[FHGFIRE_FIRE_MODE] = STRIKE_TRAILS;
                pthis->actor.shape.rot.z += 0x8000;
                pthis->work[FHGFIRE_TIMER] = 37;
                pthis->actor.world.pos.y -= 200.0f;

                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                   pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 500, 0, 0,
                                   FHGFIRE_LIGHTNING_BURST);
                {
                    Vec3f sp7C;
                    Vec3f sp70 = { 0.0f, -1.0f, 0.0f };

                    for (i = 0; i < 35; i++) {
                        sp7C.x = Rand_CenteredFloat(30.f);
                        sp7C.y = Rand_ZeroFloat(5.0f) + 3.0f;
                        sp7C.z = Rand_CenteredFloat(30.f);
                        sp70.y = -0.2f;
                        EffectSsFhgFlash_SpawnLightBall(globalCtx, &pthis->actor.world.pos, &sp7C, &sp70,
                                                        (s16)(Rand_ZeroOne() * 100.0f) + 240, FHGFLASH_LIGHTBALL_GREEN);
                    }
                }
                func_80033E88(&pthis->actor, globalCtx, 4, 10);
            }

            break;
        case STRIKE_TRAILS:
            pthis->actor.shape.rot.y =
                Camera_GetInputDirYaw(camera) + (pthis->work[FHGFIRE_VARIANCE_TIMER] & 0xFF) * 0x8000;

            Math_ApproachF(&pthis->fwork[FHGFIRE_SCALE], 0.0f, 1.0f, 0.2f);
            if (pthis->work[FHGFIRE_TIMER] == 30) {
                s16 randY = (Rand_ZeroOne() < 0.5f) ? 0x1000 : 0;

                for (i = 0; i < 8; i++) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                       pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0,
                                       (i * 0x2000) + randY, 0x4000, FHGFIRE_LIGHTNING_TRAIL + i);
                }

                for (i = 0; i < 8; i++) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                       pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0,
                                       (i * 0x2000) + randY, 0, FHGFIRE_LIGHTNING_SHOCK);
                }
            }

            if (pthis->work[FHGFIRE_TIMER] == 0) {
                Actor_Kill(&pthis->actor);
            }
    }

    Actor_SetScale(&pthis->actor, pthis->fwork[FHGFIRE_SCALE]);
}

void EnFhgFire_LightningTrail(EnFhgFire* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("FF MOVE 1\n");
    pthis->actor.shape.rot.x += (s16)(Rand_ZeroOne() * 4000.0f) + 0x4000;

    switch (pthis->work[FHGFIRE_FIRE_MODE]) {
        case TRAIL_INIT:
            pthis->work[FHGFIRE_FIRE_MODE] = TRAIL_APPEAR;
            pthis->work[FHGFIRE_TIMER] = (s16)(Rand_ZeroOne() * 7.0f) + 7;
        case TRAIL_APPEAR:
            Math_ApproachF(&pthis->fwork[FHGFIRE_SCALE], 1.7f, 1.0f, 0.34f);

            if (pthis->work[FHGFIRE_TIMER] == 0) {
                pthis->work[FHGFIRE_FIRE_MODE] = TRAIL_DISSIPATE;
                pthis->work[FHGFIRE_TIMER] = 10;
                pthis->actor.world.pos.z += Math_SinS(pthis->actor.shape.rot.y) * -200.0f * pthis->fwork[FHGFIRE_SCALE];
                pthis->actor.world.pos.x += Math_CosS(pthis->actor.shape.rot.y) * 200.0f * pthis->fwork[FHGFIRE_SCALE];
                pthis->actor.shape.rot.y += 0x8000;
            }
            break;
        case TRAIL_DISSIPATE:
            Math_ApproachZeroF(&pthis->fwork[FHGFIRE_SCALE], 1.0f, 0.34f);
            if (pthis->work[FHGFIRE_TIMER] == 0) {
                Actor_Kill(&pthis->actor);
            }
            break;
    }

    Actor_SetScale(&pthis->actor, pthis->fwork[FHGFIRE_SCALE]);
    if (pthis->actor.scale.x > 1.0f) {
        pthis->actor.scale.x = 1.0f;
    }

    osSyncPrintf("FF MOVE 2\n");
}

void EnFhgFire_LightningShock(EnFhgFire* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f pos;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_HIT_THUNDER);
    }

    if (Rand_ZeroOne() < 0.5f) {
        pos = pthis->actor.world.pos;
        pos.y -= 20.0f;
        EffectSsFhgFlash_SpawnShock(globalCtx, &pthis->actor, &pos, 200, FHGFLASH_SHOCK_NO_ACTOR);
    }

    Actor_MoveForward(&pthis->actor);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    if (player->invincibilityTimer == 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 1);
    if (pthis->actor.bgCheckFlags & 8) {
        Actor_Kill(&pthis->actor);
    }
}

void EnFhgFire_LightningBurst(EnFhgFire* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    globalCtx->envCtx.fillScreen = true;
    pthis->actor.shape.rot.y += 0x1000;

    if (pthis->work[FHGFIRE_FX_TIMER] == 49) {
        globalCtx->envCtx.unk_BF = 1;
        globalCtx->envCtx.unk_D6 = 0xFF;
    }
    if (pthis->work[FHGFIRE_FX_TIMER] == 31) {
        globalCtx->envCtx.unk_BF = 0x00;
        globalCtx->envCtx.unk_D6 = 0x14;
    }
    if (pthis->work[FHGFIRE_FX_TIMER] >= 48) {
        globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] =
            globalCtx->envCtx.screenFillColor[2] = 255;

        if ((pthis->work[FHGFIRE_TIMER] % 2) != 0) {
            globalCtx->envCtx.screenFillColor[3] = 70;
        } else {
            globalCtx->envCtx.screenFillColor[3] = 0;
        }
    } else {
        globalCtx->envCtx.screenFillColor[3] = 0;
    }

    if (pthis->work[FHGFIRE_TIMER] <= 20) {
        Math_ApproachZeroF(&pthis->fwork[FHGFIRE_ALPHA], 1.0f, 45.0f);
        Math_ApproachZeroF(&pthis->fwork[FHGFIRE_SCALE], 1.0f, 0.5f);
    } else {
        Math_ApproachF(&pthis->fwork[FHGFIRE_SCALE], pthis->fwork[FHGFIRE_BURST_SCALE], 0.5f, 3.0f);
    }

    Actor_SetScale(&pthis->actor, pthis->fwork[FHGFIRE_SCALE]);
    if (pthis->fwork[FHGFIRE_BURST_SCALE] > 3.0f) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (player->invincibilityTimer == 0) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }

    if (pthis->work[FHGFIRE_TIMER] == 0) {
        Actor_Kill(&pthis->actor);
        globalCtx->envCtx.fillScreen = false;
    }

    if (pthis->lensFlareTimer != 0) {
        pthis->lensFlareTimer--;
        pthis->lensFlareOn = true;
        Math_ApproachF(&pthis->lensFlareScale, 40.0f, 0.3f, 10.0f);
    } else {
        Math_ApproachZeroF(&pthis->lensFlareScale, 1.0f, 5.0f);
        if (pthis->lensFlareScale == 0.0f) {
            pthis->lensFlareOn = false;
        }
    }

    gCustomLensFlareOn = pthis->lensFlareOn;
    gCustomLensFlarePos = pthis->actor.world.pos;
    gLensFlareScale = pthis->lensFlareScale;
    gLensFlareColorIntensity = 10.0f;
    gLensFlareScreenFillAlpha = 0;
}

void EnFhgFire_SpearLight(EnFhgFire* pthis, GlobalContext* globalCtx) {
    BossGanondrof* bossGnd;
    s16 i;

    osSyncPrintf("yari hikari 1\n");
    bossGnd = (BossGanondrof*)pthis->actor.parent;
    if ((pthis->work[FHGFIRE_VARIANCE_TIMER] % 2) != 0) {
        Actor_SetScale(&pthis->actor, 6.0f);
    } else {
        Actor_SetScale(&pthis->actor, 5.25f);
    }

    pthis->actor.world.pos = bossGnd->spearTip;
    pthis->actor.shape.rot.z += (s16)(Rand_ZeroOne() * 0x4E20) + 0x4000;

    osSyncPrintf("yari hikari 2\n");
    if (pthis->work[FHGFIRE_FIRE_MODE] == FHGFIRE_LIGHT_GREEN) {
        Vec3f ballPos;
        Vec3f ballVel = { 0.0f, 0.0f, 0.0f };
        Vec3f ballAccel = { 0.0f, 0.0f, 0.0f };

        osSyncPrintf("FLASH !!\n");

        for (i = 0; i < 2; i++) {
            ballPos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
            ballPos.y = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.y;
            ballPos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
            ballAccel.y = -0.08f;

            EffectSsFhgFlash_SpawnLightBall(globalCtx, &ballPos, &ballVel, &ballAccel,
                                            (s16)(Rand_ZeroOne() * 80.0f) + 150, FHGFLASH_LIGHTBALL_GREEN);
        }
    }

    if (pthis->work[FHGFIRE_TIMER] == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnFhgFire_EnergyBall(EnFhgFire* pthis, GlobalContext* globalCtx) {
    f32 dxL;
    f32 dyL;
    f32 dzL;
    f32 dxzL;
    f32 dxPG;
    f32 dyPG;
    f32 dzPG;
    u8 killMode = BALL_FIZZLE;
    u8 canBottleReflect1;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->work[FHGFIRE_KILL_TIMER] != 0) {
        pthis->work[FHGFIRE_KILL_TIMER]--;
        if (pthis->work[FHGFIRE_KILL_TIMER] == 0) {
            Actor_Kill(&pthis->actor);
            return;
        }
    } else {
        s32 canBottleReflect2;
        BossGanondrof* bossGnd = (BossGanondrof*)pthis->actor.parent;

        dxPG = bossGnd->targetPos.x - pthis->actor.world.pos.x;
        dyPG = bossGnd->targetPos.y - pthis->actor.world.pos.y;
        dzPG = bossGnd->targetPos.z - pthis->actor.world.pos.z;
        dxL = player->actor.world.pos.x - pthis->actor.world.pos.x;
        dyL = player->actor.world.pos.y + 40.0f - pthis->actor.world.pos.y;
        dzL = player->actor.world.pos.z - pthis->actor.world.pos.z;
        func_8002D908(&pthis->actor);
        func_8002D7EC(&pthis->actor);
        if (pthis->work[FHGFIRE_VARIANCE_TIMER] & 1) {
            Actor_SetScale(&pthis->actor, 6.0f);
        } else {
            Actor_SetScale(&pthis->actor, 5.25f);
        }
        pthis->actor.shape.rot.z += (s16)(Rand_ZeroOne() * 0x4E20) + 0x4000;
        {
            u8 lightBallColor1 = FHGFLASH_LIGHTBALL_GREEN;
            s16 i1;
            Vec3f spD4;
            Vec3f spC8 = { 0.0f, 0.0f, 0.0f };
            Vec3f spBC = { 0.0f, 0.0f, 0.0f };

            if (pthis->work[FHGFIRE_FIRE_MODE] >= FHGFIRE_LIGHT_BLUE) {
                lightBallColor1 = FHGFLASH_LIGHTBALL_LIGHTBLUE;
            }
            for (i1 = 0; i1 < 3; i1++) {
                spD4.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
                spD4.y = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.y;
                spD4.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
                spBC.y = -0.08f;
                EffectSsFhgFlash_SpawnLightBall(globalCtx, &spD4, &spC8, &spBC, (s16)(Rand_ZeroOne() * 80.0f) + 150,
                                                lightBallColor1);
            }
        }
        switch (pthis->work[FHGFIRE_FIRE_MODE]) {
            case FHGFIRE_LIGHT_GREEN:
                canBottleReflect1 =
                    ((player->stateFlags1 & 2) &&
                     (ABS((s16)(player->actor.shape.rot.y - (s16)(bossGnd->actor.yawTowardsPlayer + 0x8000))) <
                      0x2000) &&
                     (sqrtf(SQ(dxL) + SQ(dyL) + SQ(dzL)) <= 25.0f))
                        ? true
                        : false;
                if ((pthis->collider.base.acFlags & AC_HIT) || canBottleReflect1) {
                    ColliderInfo* hurtbox = pthis->collider.info.acHitInfo;
                    s16 i2;
                    Vec3f spA8;
                    Vec3f sp9C = { 0.0f, -0.5f, 0.0f };
                    s16 angleModX;
                    s16 angleModY;

                    for (i2 = 0; i2 < 30; i2++) {
                        spA8.x = Rand_CenteredFloat(20.0f);
                        spA8.y = Rand_CenteredFloat(20.0f);
                        spA8.z = Rand_CenteredFloat(20.0f);
                        EffectSsFhgFlash_SpawnLightBall(globalCtx, &pthis->actor.world.pos, &spA8, &sp9C,
                                                        (s16)(Rand_ZeroOne() * 25.0f) + 50, FHGFLASH_LIGHTBALL_GREEN);
                    }
                    canBottleReflect2 = canBottleReflect1;
                    if (!canBottleReflect2 && (hurtbox->toucher.dmgFlags & 0x00100000)) {
                        killMode = BALL_IMPACT;
                        Audio_PlaySoundGeneral(NA_SE_IT_SHIELD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                        Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xFF, 0x14, 0x96);
                    } else {
                        if (bossGnd->flyMode == GND_FLY_NEUTRAL) {
                            angleModX = Rand_CenteredFloat(0x2000);
                            angleModY = Rand_CenteredFloat(0x2000);
                            pthis->actor.speedXZ = 15.0f;
                        } else {
                            angleModX = 0;
                            angleModY = 0;
                            pthis->work[FHGFIRE_RETURN_COUNT]++;
                            if ((pthis->work[FHGFIRE_RETURN_COUNT] > 3) && (Rand_ZeroOne() < 0.5f)) {
                                pthis->work[FHGFIRE_RETURN_COUNT] = 100;
                            }

                            if (!canBottleReflect2 && (player->swordAnimation >= 24)) {
                                pthis->actor.speedXZ = 20.0f;
                                pthis->work[FHGFIRE_RETURN_COUNT] = 4;
                            } else {
                                pthis->actor.speedXZ += 1.0f;
                            }
                        }
                        pthis->actor.world.rot.y = (s16)(Math_FAtan2F(dxPG, dzPG) * (0x8000 / M_PI)) + angleModY;
                        pthis->actor.world.rot.x =
                            (s16)(Math_FAtan2F(dyPG, sqrtf((dxPG * dxPG) + (dzPG * dzPG))) * (0x8000 / M_PI)) +
                            angleModX;
                        pthis->work[FHGFIRE_FIRE_MODE] = FHGFIRE_LIGHT_BLUE;
                        pthis->work[FHGFIRE_FX_TIMER] = 2;
                        Audio_PlaySoundGeneral(NA_SE_IT_SWORD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                        Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xB4, 0x14, 0x64);
                    }
                } else if (sqrtf(SQ(dxL) + SQ(dyL) + SQ(dzL)) <= 25.0f) {
                    killMode = BALL_BURST;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_HIT_THUNDER);
                    if ((bossGnd->flyMode >= GND_FLY_VOLLEY) && (pthis->work[FHGFIRE_RETURN_COUNT] >= 2)) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_LAUGH);
                    }
                    func_8002F698(globalCtx, &pthis->actor, 3.0f, pthis->actor.world.rot.y, 0.0f, 3, 0x10);
                }
                break;
            case FHGFIRE_LIGHT_BLUE:
                if ((bossGnd->flyMode == GND_FLY_RETURN) && (pthis->work[FHGFIRE_RETURN_COUNT] < 100)) {
                    pthis->actor.world.rot.y = Math_FAtan2F(dxPG, dzPG) * (0x8000 / M_PI);
                    if ((sqrtf(SQ(dxPG) + SQ(dzPG)) < (150.0f + (pthis->actor.speedXZ * 8.0f)))) {
                        pthis->work[FHGFIRE_FIRE_MODE] = FHGFIRE_LIGHT_REFLECT;
                        bossGnd->returnSuccess = true;
                        pthis->work[FHGFIRE_TIMER] = 8;
                    }
                } else {
                    if (pthis->work[FHGFIRE_RETURN_COUNT] >= 100) {
                        if ((sqrtf(SQ(dxPG) + SQ(dyPG) + SQ(dzPG)) < 100.0f)) {
                            bossGnd->returnSuccess = true;
                        }
                        pthis->actor.world.rot.y = Math_FAtan2F(dxPG, dzPG) * (0x8000 / M_PI);
                        pthis->actor.world.rot.x = Math_FAtan2F(dyPG, sqrtf(SQ(dxPG) + SQ(dzPG))) * (0x8000 / M_PI);
                    }
                    if ((fabsf(dxPG) < 30.0f) && (fabsf(dzPG) < 30.0f) && (fabsf(dyPG) < 45.0f)) {
                        killMode = BALL_IMPACT;
                        bossGnd->returnCount = pthis->work[FHGFIRE_RETURN_COUNT] + 1;
                        Audio_PlaySoundGeneral(NA_SE_EN_FANTOM_HIT_THUNDER, &bossGnd->actor.projectedPos, 4,
                                               &D_801333E0, &D_801333E0, &gReverbAdd2);
                        Audio_PlaySoundGeneral(NA_SE_EN_FANTOM_DAMAGE, &bossGnd->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                    }
                }
                break;
            case FHGFIRE_LIGHT_REFLECT:
                if (pthis->work[FHGFIRE_TIMER] == 0) {
                    s16 i3;
                    Vec3f sp88;
                    Vec3f sp7C = { 0.0f, -0.5f, 0.0f };

                    for (i3 = 0; i3 < 30; i3++) {
                        sp88.x = Rand_CenteredFloat(20.0f);
                        sp88.y = Rand_CenteredFloat(20.0f);
                        sp88.z = Rand_CenteredFloat(20.0f);
                        EffectSsFhgFlash_SpawnLightBall(globalCtx, &pthis->actor.world.pos, &sp88, &sp7C,
                                                        (s16)(Rand_ZeroOne() * 40.0f) + 80, FHGFLASH_LIGHTBALL_GREEN);
                    }
                    pthis->actor.world.rot.y = Math_FAtan2F(dxL, dzL) * (0x8000 / M_PI);
                    dxzL = sqrtf(SQ(dxL) + SQ(dzL));
                    pthis->actor.world.rot.x = Math_FAtan2F(dyL, dxzL) * (0x8000 / M_PI);
                    pthis->work[FHGFIRE_FIRE_MODE] = FHGFIRE_LIGHT_GREEN;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SWORD_REFLECT_MG);
                    pthis->actor.speedXZ += 2.0f;
                }
                break;
        }

        osSyncPrintf("F_FIRE_MODE %d\n", pthis->work[FHGFIRE_FIRE_MODE]);
        osSyncPrintf("fly_mode    %d\n", bossGnd->flyMode);
        if (pthis->work[FHGFIRE_FX_TIMER] == 0) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 7);
            if ((pthis->actor.bgCheckFlags & 0x19) || killMode) {
                u8 lightBallColor2 = FHGFLASH_LIGHTBALL_GREEN;
                s16 i4;
                Vec3f sp6C;
                Vec3f sp60 = { 0.0f, -1.0f, 0.0f };

                if (pthis->work[FHGFIRE_FIRE_MODE] > FHGFIRE_LIGHT_GREEN) {
                    lightBallColor2 = FHGFLASH_LIGHTBALL_LIGHTBLUE;
                }
                for (i4 = 0; i4 < 30; i4++) {
                    sp6C.x = Rand_CenteredFloat(20.0f);
                    sp6C.y = Rand_CenteredFloat(20.0f);
                    sp6C.z = Rand_CenteredFloat(20.0f);
                    sp60.y = -0.1f;
                    EffectSsFhgFlash_SpawnLightBall(globalCtx, &pthis->actor.world.pos, &sp6C, &sp60,
                                                    (s16)(Rand_ZeroOne() * 50.0f) + 100, lightBallColor2);
                }
                if (killMode == BALL_BURST) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                       pthis->actor.world.pos.x, player->actor.world.pos.y + 20.0f,
                                       pthis->actor.world.pos.z, 0xC8, 0, 0, FHGFIRE_LIGHTNING_BURST);
                }
                bossGnd->flyMode = GND_FLY_NEUTRAL;
                pthis->work[FHGFIRE_KILL_TIMER] = 30;
                pthis->actor.draw = NULL;
                if (killMode == BALL_FIZZLE) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_THUNDER_GND);
                }
                return;
            } else {
                Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
                osSyncPrintf("BEFORE setAC   %d\n", pthis->collider.base.shape);
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
                osSyncPrintf("AFTER  setAC\n");
            }
        }
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, (s16)pthis->actor.world.pos.x, (s16)pthis->actor.world.pos.y,
                                  (s16)pthis->actor.world.pos.z, 255, 255, 255, 200);
        if (pthis->actor.speedXZ > 20.0f) {
            pthis->actor.speedXZ = 20.0f;
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_FIRE - SFX_FLAG);
        // "Why ah ah ah ah"
        osSyncPrintf("なぜだああああああああ      %d\n", pthis->work[FHGFIRE_VARIANCE_TIMER]);
    }
}

void EnFhgFire_PhantomWarp(EnFhgFire* pthis, GlobalContext* globalCtx) {
    EnfHG* horse = (EnfHG*)pthis->actor.parent;
    f32 scrollDirection;

    pthis->fwork[FHGFIRE_WARP_TEX_1_X] += 25.0f * pthis->fwork[FHGFIRE_WARP_TEX_SPEED];
    pthis->fwork[FHGFIRE_WARP_TEX_1_Y] -= 40.0f * pthis->fwork[FHGFIRE_WARP_TEX_SPEED];
    pthis->fwork[FHGFIRE_WARP_TEX_2_X] += 5.0f * pthis->fwork[FHGFIRE_WARP_TEX_SPEED];
    pthis->fwork[FHGFIRE_WARP_TEX_2_Y] -= 30.0f * pthis->fwork[FHGFIRE_WARP_TEX_SPEED];

    if (pthis->actor.params == FHGFIRE_WARP_DEATH) {
        if (pthis->work[FHGFIRE_TIMER] > 70) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_L - SFX_FLAG);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_L2 - SFX_FLAG);
        }

        if (pthis->work[FHGFIRE_TIMER] == 70) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_S);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FANTOM_WARP_S2);
        }
    }

    if (pthis->work[FHGFIRE_TIMER] > 50) {
        scrollDirection = 1.0f;
        if (pthis->actor.params > FHGFIRE_WARP_EMERGE) {
            scrollDirection = -1.0f;
        }
        Math_ApproachF(&pthis->fwork[FHGFIRE_WARP_TEX_SPEED], scrollDirection, 1.0f, 0.04f);
        Math_ApproachF(&pthis->fwork[FHGFIRE_WARP_ALPHA], 255.0f, 1.0f, 10.2f);
    } else if (pthis->work[FHGFIRE_TIMER] <= 25) {
        Math_ApproachZeroF(&pthis->fwork[FHGFIRE_WARP_TEX_SPEED], 1.0f, 0.04f);
        Math_ApproachZeroF(&pthis->fwork[FHGFIRE_WARP_ALPHA], 1.0f, 10.2f);
    }

    osSyncPrintf("EFC 1\n");
    if ((pthis->work[FHGFIRE_TIMER] == 0) || ((pthis->actor.params == FHGFIRE_WARP_EMERGE) && horse->fhgFireKillWarp)) {
        Actor_Kill(&pthis->actor);
    }
    osSyncPrintf("EFC 2\n");
}

void EnFhgFire_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFhgFire* pthis = (EnFhgFire*)thisx;

    pthis->work[FHGFIRE_VARIANCE_TIMER]++;

    if (pthis->work[FHGFIRE_TIMER] != 0) {
        pthis->work[FHGFIRE_TIMER]--;
    }
    if (pthis->work[FHGFIRE_FX_TIMER] != 0) {
        pthis->work[FHGFIRE_FX_TIMER]--;
    }

    pthis->updateFunc(pthis, globalCtx);
}

static void* sDustTextures[] = {
    gDust1Tex, gDust2Tex, gDust3Tex, gDust4Tex, gDust5Tex, gDust6Tex, gDust7Tex, gDust8Tex,
};

void EnFhgFire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnFhgFire* pthis = (EnFhgFire*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1723);

    if (pthis->actor.params == FHGFIRE_LIGHTNING_BURST) {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)pthis->fwork[FHGFIRE_ALPHA]);
        gDPSetEnvColor(POLY_XLU_DISP++, 165, 255, 75, 0);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1745),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gPhantomLightningBlastDL));
    } else if ((pthis->actor.params == FHGFIRE_SPEAR_LIGHT) || (pthis->actor.params == FHGFIRE_ENERGY_BALL)) {
        osSyncPrintf("yari hikari draw 1\n");
        func_800D1FD4(&globalCtx->billboardMtxF);
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)pthis->fwork[FHGFIRE_ALPHA]);

        if (pthis->work[FHGFIRE_FIRE_MODE] > FHGFIRE_LIGHT_GREEN) {
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, 0);
        } else {
            gDPSetEnvColor(POLY_XLU_DISP++, 165, 255, 75, 0);
        }
        gDPPipeSync(POLY_XLU_DISP++);
        Matrix_RotateZ((pthis->actor.shape.rot.z / (f32)0x8000) * 3.1416f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1801),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gPhantomEnergyBallDL);
    } else if ((pthis->actor.params == FHGFIRE_WARP_EMERGE) || (pthis->actor.params == FHGFIRE_WARP_RETREAT) ||
               (pthis->actor.params == FHGFIRE_WARP_DEATH)) {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, (u8)pthis->fwork[FHGFIRE_WARP_ALPHA]);
        gDPSetEnvColor(POLY_XLU_DISP++, 90, 50, 95, (s8)(pthis->fwork[FHGFIRE_WARP_ALPHA] * 0.5f));
        gDPPipeSync(POLY_XLU_DISP++);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1833),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (s16)pthis->fwork[FHGFIRE_WARP_TEX_1_X],
                                    (s16)pthis->fwork[FHGFIRE_WARP_TEX_1_Y], 0x40, 0x40, 1,
                                    (s16)pthis->fwork[FHGFIRE_WARP_TEX_2_X], (s16)pthis->fwork[FHGFIRE_WARP_TEX_2_Y],
                                    0x40, 0x40));
        gSPDisplayList(POLY_XLU_DISP++, gPhantomWarpDL);
    } else {
        osSyncPrintf("FF DRAW 1\n");
        Matrix_Translate(0.0f, -100.0f, 0.0f, MTXMODE_APPLY);
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)pthis->fwork[FHGFIRE_ALPHA]);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 30, 0);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1892),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gPhantomLightningDL);
        osSyncPrintf("FF DRAW 2\n");
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fhg_fire.c", 1900);
}

void EnFhgFire_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Fhg_Fire_InitVars = {
        0,
        ACTORCAT_BOSS,
        FLAGS,
        OBJECT_FHG,
        sizeof(EnFhgFire),
        (ActorFunc)EnFhgFire_Init,
        (ActorFunc)EnFhgFire_Destroy,
        (ActorFunc)EnFhgFire_Update,
        (ActorFunc)EnFhgFire_Draw,
        (ActorFunc)EnFhgFire_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK6,
            { 0x00100700, 0x03, 0x20 },
            { 0x0D900700, 0x00, 0x00 },
            TOUCH_ON,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 30, 10, { 0, 0, 0 } },
    };

}

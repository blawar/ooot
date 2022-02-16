#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GOMA_Z_EN_GOMA_C
#include "actor_common.h"
#include "z_en_goma.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "objects/object_gol/object_gol.h"
#include "overlays/actors/ovl_Boss_Goma/z_boss_goma.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "def/code_8006BA00.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnGoma_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGoma_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnGoma_Flee(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_EggFallToGround(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Egg(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Hatch(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Hurt(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Die(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Dead(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_PrepareJump(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Land(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Jump(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Stand(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_ChasePlayer(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Stunned(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_LookAtPlayer(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_UpdateHit(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_Debris(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_SpawnHatchDebris(EnGoma* pthis, GlobalContext* globalCtx2);
void EnGoma_BossLimb(EnGoma* pthis, GlobalContext* globalCtx);

void EnGoma_SetupFlee(EnGoma* pthis);
void EnGoma_SetupHatch(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_SetupHurt(EnGoma* pthis, GlobalContext* globalCtx);
void EnGoma_SetupDie(EnGoma* pthis);
void EnGoma_SetupDead(EnGoma* pthis);
void EnGoma_SetupStand(EnGoma* pthis);
void EnGoma_SetupChasePlayer(EnGoma* pthis);
void EnGoma_SetupPrepareJump(EnGoma* pthis);
void EnGoma_SetupLand(EnGoma* pthis);
void EnGoma_SetupJump(EnGoma* pthis);
void EnGoma_SetupStunned(EnGoma* pthis, GlobalContext* globalCtx);

static Vec3f sShieldKnockbackVel_89 = { 0.0f, 0.0f, 20.0f };

static f32 sTargetEyeEnvColors_90[][3] = {
    { 255.0f, 0.0f, 50.0f },
    { 17.0f, 255.0f, 50.0f },
    { 0.0f, 170.0f, 50.0f },
};


ActorInit En_Goma_InitVars = {
    ACTOR_BOSS_GOMA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GOL,
    sizeof(EnGoma),
    (ActorFunc)EnGoma_Init,
    (ActorFunc)EnGoma_Destroy,
    (ActorFunc)EnGoma_Update,
    (ActorFunc)EnGoma_Draw,
    (ActorFunc)EnGoma_Reset,
};

static ColliderCylinderInit D_80A4B7A0 = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static ColliderCylinderInit D_80A4B7CC = {
    {
        COLTYPE_HIT3,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static u8 sSpawnNum = 0;
static Vec3f sDeadEffectVel = { 0.0f, 0.0f, 0.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 3, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x03, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 20, ICHAIN_STOP),
};

void EnGoma_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* pthis = (EnGoma*)thisx;
    s16 params;

    pthis->eggTimer = Rand_ZeroOne() * 200.0f;
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.01f);
    params = pthis->actor.params;

    if (params >= 100) { // piece of boss goma
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_BOSS);
        pthis->actionFunc = EnGoma_BossLimb;
        pthis->gomaType = ENGOMA_BOSSLIMB;
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
        pthis->actionTimer = pthis->actor.params + 150;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    } else if (params >= 10) { // Debris when hatching
        pthis->actor.gravity = -1.3f;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actionTimer = 50;
        pthis->gomaType = ENGOMA_HATCH_DEBRIS;
        pthis->eggScale = 1.0f;
        pthis->actor.velocity.y = Rand_ZeroOne() * 5.0f + 5.0f;
        pthis->actionFunc = EnGoma_Debris;
        pthis->actor.speedXZ = Rand_ZeroOne() * 2.3f + 1.5f;
        pthis->actionTimer = 30;
        pthis->actor.scale.x = Rand_ZeroOne() * 0.005f + 0.01f;
        pthis->actor.scale.y = Rand_ZeroOne() * 0.005f + 0.01f;
        pthis->actor.scale.z = Rand_ZeroOne() * 0.005f + 0.01f;
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    } else { // Egg
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);
        SkelAnime_Init(globalCtx, &pthis->skelanime, &gObjectGolSkel, &gObjectGolStandAnim, pthis->jointTable,
                       pthis->morphTable, GOMA_LIMB_MAX);
        Animation_PlayLoop(&pthis->skelanime, &gObjectGolStandAnim);
        pthis->actor.colChkInfo.health = 2;

        if (pthis->actor.params < 3) { // Spawned by boss
            pthis->actionFunc = EnGoma_EggFallToGround;
            pthis->invincibilityTimer = 10;
            pthis->actor.speedXZ = 1.5f;
        } else if (pthis->actor.params == 8 || pthis->actor.params == 6) {
            pthis->actionFunc = EnGoma_Egg;
            pthis->spawnNum = sSpawnNum++;
        } else if (pthis->actor.params == 9 || pthis->actor.params == 7) {
            pthis->actionFunc = EnGoma_Egg;
        }

        if (pthis->actor.params >= 8) { // on ceiling
            pthis->eggYOffset = -1500.0f;
        } else {
            pthis->eggYOffset = 1500.0f;
        }

        pthis->gomaType = ENGOMA_EGG;
        pthis->eggScale = 1.0f;
        pthis->eggSquishAngle = Rand_ZeroOne() * 1000.0f;
        pthis->actionTimer = 50;
        Collider_InitCylinder(globalCtx, &pthis->colCyl1);
        Collider_SetCylinder(globalCtx, &pthis->colCyl1, &pthis->actor, &D_80A4B7A0);
        Collider_InitCylinder(globalCtx, &pthis->colCyl2);
        Collider_SetCylinder(globalCtx, &pthis->colCyl2, &pthis->actor, &D_80A4B7CC);
    }
}

void EnGoma_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* pthis = (EnGoma*)thisx;

    if (pthis->actor.params < 10) {
        Collider_DestroyCylinder(globalCtx, &pthis->colCyl1);
        Collider_DestroyCylinder(globalCtx, &pthis->colCyl2);
    }
}

void EnGoma_SetupFlee(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolRunningAnim, 2.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolRunningAnim), ANIMMODE_LOOP, -2.0f);
    pthis->actionFunc = EnGoma_Flee;
    pthis->actionTimer = 20;

    if (pthis->actor.params < 6) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_DAM2);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_DAM2);
    }
}

void EnGoma_Flee(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachF(&pthis->actor.speedXZ, 20.0f / 3.0f, 0.5f, 2.0f);
    Math_ApproachS(&pthis->actor.world.rot.y,
                   Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) + 0x8000, 3, 2000);
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 2, 3000);

    if (pthis->actionTimer == 0) {
        EnGoma_SetupStand(pthis);
    }
}

void EnGoma_EggFallToGround(EnGoma* pthis, GlobalContext* globalCtx) {
    pthis->actor.gravity = -1.3f;
    pthis->eggSquishAccel += 0.03f;
    pthis->eggSquishAngle += 1.0f + pthis->eggSquishAccel;
    Math_ApproachZeroF(&pthis->eggSquishAmount, 1.0f, 0.005f);
    Math_ApproachF(&pthis->eggYOffset, 1500.0f, 1.0f, 150.0f);

    switch (pthis->hatchState) {
        case 0:
            if (pthis->actor.bgCheckFlags & 1) { // floor
                if (pthis->actor.params < 6) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_EGG1);
                } else {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_EGG1);
                }

                if (pthis->actor.params > 5) {
                    EnGoma_SetupHatch(pthis, globalCtx);
                } else {
                    pthis->hatchState = 1;
                    pthis->actionTimer = 3;
                    Math_ApproachF(&pthis->eggScale, 1.5f, 0.5f, 1.0f);
                }
            }
            break;

        case 1:
            if (pthis->actionTimer == 0) {
                pthis->hatchState = 2;
                pthis->actionTimer = 3;
                Math_ApproachF(&pthis->eggScale, 0.75f, 0.5f, 1.0f);
                pthis->actor.velocity.y = 5.0f;
                pthis->actor.speedXZ = 2.0f;
            } else {
                Math_ApproachF(&pthis->eggScale, 1.5f, 0.5f, 1.0f);
            }
            break;

        case 2:
            if (pthis->actionTimer == 0) {
                pthis->hatchState = 3;
                pthis->actionTimer = 80;
            } else {
                Math_ApproachF(&pthis->eggScale, 0.75f, 0.5f, 1.0f);
            }
            break;

        case 3:
            Math_ApproachF(&pthis->eggScale, 1.0f, 0.1f, 0.1f);
            if (pthis->actionTimer == 0) {
                EnGoma_SetupHatch(pthis, globalCtx);
            }
            break;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&pthis->actor.speedXZ, 0.2f, 0.05f);
    }
    pthis->eggPitch += (pthis->actor.speedXZ * 0.1f);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnGoma_Egg(EnGoma* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 i;

    pthis->eggSquishAngle += 1.0f;
    Math_ApproachF(&pthis->eggSquishAmount, 0.1f, 1.0f, 0.005f);
    if (fabsf(pthis->actor.world.pos.x - player->actor.world.pos.x) < 100.0f &&
        fabsf(pthis->actor.world.pos.z - player->actor.world.pos.z) < 100.0f) {
        if (++pthis->playerDetectionTimer > 9) {
            pthis->actionFunc = EnGoma_EggFallToGround;
        }
    } else {
        pthis->playerDetectionTimer = 0;
    }

    if (!(pthis->eggTimer & 0xF) && Rand_ZeroOne() < 0.5f) {
        for (i = 0; i < 2; i++) {
            Vec3f vel = { 0.0f, 0.0f, 0.0f };
            Vec3f acc = { 0.0f, -0.5f, 0.0f };
            Vec3f pos;

            pos.x = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.x;
            pos.y = Rand_ZeroFloat(30.0f) + pthis->actor.world.pos.y;
            pos.z = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.z;
            EffectSsHahen_Spawn(globalCtx, &pos, &vel, &acc, 0, (s16)(Rand_ZeroOne() * 5.0f) + 10, HAHEN_OBJECT_DEFAULT,
                                10, NULL);
        }
    }
}

void EnGoma_SetupHatch(EnGoma* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelanime, &gObjectGolJumpHeadbuttAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolJumpHeadbuttAnim), ANIMMODE_ONCE, 0.0f);
    pthis->actionFunc = EnGoma_Hatch;
    Actor_SetScale(&pthis->actor, 0.005f);
    pthis->gomaType = ENGOMA_NORMAL;
    pthis->actionTimer = 5;
    pthis->actor.shape.rot.y = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnGoma_SpawnHatchDebris(pthis, globalCtx);
    pthis->eggScale = 1.0f;
    pthis->actor.speedXZ = 0.0f;
}

void EnGoma_Hatch(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    if (pthis->actionTimer == 0) {
        EnGoma_SetupStand(pthis);
    }
}

void EnGoma_SetupHurt(EnGoma* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelanime, &gObjectGolDamagedAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolDamagedAnim), ANIMMODE_ONCE, -2.0f);
    pthis->actionFunc = EnGoma_Hurt;

    if ((s8)pthis->actor.colChkInfo.health <= 0) {
        pthis->actionTimer = 5;
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
    } else {
        pthis->actionTimer = 10;
    }

    pthis->actor.speedXZ = 20.0f;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
    if (pthis->actor.params < 6) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_DAM1);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_DAM1);
    }
}

void EnGoma_Hurt(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 2.0f);
    }

    if (pthis->actionTimer == 0) {
        if ((s8)pthis->actor.colChkInfo.health <= 0) {
            EnGoma_SetupDie(pthis);
        } else {
            EnGoma_SetupFlee(pthis);
        }
    }
}

void EnGoma_SetupDie(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolDeathAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gObjectGolDeathAnim),
                     ANIMMODE_ONCE, -2.0f);
    pthis->actionFunc = EnGoma_Die;
    pthis->actionTimer = 30;

    if (pthis->actor.params < 6) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_DEAD);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_DEAD);
    }

    pthis->invincibilityTimer = 100;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void EnGoma_Die(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 2.0f);
    }

    if (pthis->actionTimer == 17) {
        if (pthis->actor.params < 6) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_LAND);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_LAND);
        }
    }

    if (pthis->actionTimer == 0) {
        EnGoma_SetupDead(pthis);
    }
}

void EnGoma_SetupDead(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolDeadTwitchingAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolDeadTwitchingAnim), ANIMMODE_LOOP, -2.0f);
    pthis->actionFunc = EnGoma_Dead;
    pthis->actionTimer = 3;
}

void EnGoma_Dead(EnGoma* pthis, GlobalContext* globalCtx) {
    Vec3f accel;
    Vec3f pos;

    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 2.0f);

    if (pthis->actionTimer == 2) {
        pos.x = pthis->actor.world.pos.x;
        pos.y = (pthis->actor.world.pos.y + 5.0f) - 10.0f;
        pos.z = pthis->actor.world.pos.z;
        accel = sDeadEffectVel;
        accel.y = 0.03f;
        EffectSsKFire_Spawn(globalCtx, &pos, &sDeadEffectVel, &accel, 40, 0);
    }

    if (pthis->actionTimer == 0 && Math_SmoothStepToF(&pthis->actor.scale.y, 0.0f, 0.5f, 0.00225f, 0.00001f) <= 0.001f) {
        if (pthis->actor.params < 6) {
            BossGoma* parent = (BossGoma*)pthis->actor.parent;

            parent->childrenGohmaState[pthis->actor.params] = -1;
        }
        Audio_PlaySoundGeneral(NA_SE_EN_EXTINCT, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        Actor_Kill(&pthis->actor);
        Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, 0x30);
    }
    pthis->visualState = 2;
}

void EnGoma_SetupStand(EnGoma* pthis) {
    f32 lastFrame;

    lastFrame = Animation_GetLastFrame(&gObjectGolStandAnim);
    pthis->actionTimer = Rand_S16Offset(10, 30);
    Animation_Change(&pthis->skelanime, &gObjectGolStandAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = EnGoma_Stand;
    pthis->gomaType = ENGOMA_NORMAL;
}

void EnGoma_SetupChasePlayer(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolRunningAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolRunningAnim), ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = EnGoma_ChasePlayer;
    pthis->actionTimer = Rand_S16Offset(70, 110);
}

void EnGoma_SetupPrepareJump(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolPrepareJumpAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolPrepareJumpAnim), ANIMMODE_ONCE, -5.0f);
    pthis->actionFunc = EnGoma_PrepareJump;
    pthis->actionTimer = 30;
}

void EnGoma_PrepareJump(EnGoma* pthis, GlobalContext* globalCtx) {
    s16 targetAngle;

    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);

    targetAngle = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
    Math_ApproachS(&pthis->actor.world.rot.y, targetAngle, 2, 4000);
    Math_ApproachS(&pthis->actor.shape.rot.y, targetAngle, 2, 3000);

    if (pthis->actionTimer == 0) {
        EnGoma_SetupJump(pthis);
    }
    pthis->visualState = 0;
}

void EnGoma_SetupLand(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolLandFromJumpAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolLandFromJumpAnim), ANIMMODE_ONCE, 0.0f);
    pthis->actionFunc = EnGoma_Land;
    pthis->actionTimer = 10;
}

void EnGoma_Land(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 2.0f);
    }
    if (pthis->actionTimer == 0) {
        EnGoma_SetupStand(pthis);
    }
}

void EnGoma_SetupJump(EnGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gObjectGolJumpHeadbuttAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolJumpHeadbuttAnim), ANIMMODE_ONCE, 0.0f);
    pthis->actionFunc = EnGoma_Jump;
    pthis->actor.velocity.y = 8.0f;

    if (pthis->actor.params < 6) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_CRY);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_CRY);
    }
}

void EnGoma_Jump(EnGoma* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_24;
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachF(&pthis->actor.speedXZ, 10.0f, 0.5f, 5.0f);

    if (pthis->actor.velocity.y <= 0.0f && (pthis->actor.bgCheckFlags & 1)) {
        EnGoma_SetupLand(pthis);
        if (pthis->actor.params < 6) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_LAND2);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_LAND2);
        }
    }
    pthis->visualState = 0;
}

void EnGoma_Stand(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);
    Math_ApproachS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor), 2,
                   3000);

    if (pthis->actionTimer == 0) {
        EnGoma_SetupChasePlayer(pthis);
    }
}

void EnGoma_ChasePlayer(EnGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, 1.0f) || Animation_OnFrame(&pthis->skelanime, 5.0f)) {
        if (pthis->actor.params < 6) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_WALK);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_WALK);
        }
    }

    Math_ApproachF(&pthis->actor.speedXZ, 10.0f / 3.0f, 0.5f, 2.0f);
    Math_ApproachS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 3, 2000);
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 2, 3000);

    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.velocity.y = 0.0f;
    }
    if (pthis->actor.xzDistToPlayer <= 150.0f) {
        EnGoma_SetupPrepareJump(pthis);
    }
}

void EnGoma_SetupStunned(EnGoma* pthis, GlobalContext* globalCtx) {
    pthis->actionFunc = EnGoma_Stunned;
    pthis->stunTimer = 100;
    Animation_MorphToLoop(&pthis->skelanime, &gObjectGolStandAnim, -5.0f);
    pthis->actionTimer = (s16)Rand_ZeroFloat(15.0f) + 3;

    if (pthis->actor.params < 6) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_BJR_FREEZE);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    }
}

void EnGoma_Stunned(EnGoma* pthis, GlobalContext* globalCtx) {
    Actor_SetColorFilter(&pthis->actor, 0, 180, 0, 2);
    pthis->visualState = 2;

    if (pthis->actionTimer != 0) {
        SkelAnime_Update(&pthis->skelanime);
    }

    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.velocity.y = 0.0f;
        Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);
    }

    if (pthis->stunTimer == 0) {
        EnGoma_SetupStand(pthis);
    } else if (--pthis->stunTimer < 30) {
        if (pthis->stunTimer & 1) {
            pthis->actor.world.pos.x += 1.5f;
            pthis->actor.world.pos.z += 1.5f;
        } else {
            pthis->actor.world.pos.x -= 1.5f;
            pthis->actor.world.pos.z -= 1.5f;
        }
    }
}

void EnGoma_LookAtPlayer(EnGoma* pthis, GlobalContext* globalCtx) {
    s16 eyePitch;
    s16 eyeYaw;

    eyeYaw = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.shape.rot.y;
    eyePitch = Actor_WorldPitchTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.shape.rot.x;

    if (eyeYaw > 6000) {
        eyeYaw = 6000;
    }
    if (eyeYaw < -6000) {
        eyeYaw = -6000;
    }
    Math_ApproachS(&pthis->eyeYaw, eyeYaw, 3, 2000);
    Math_ApproachS(&pthis->eyePitch, eyePitch, 3, 2000);
}

void EnGoma_UpdateHit(EnGoma* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->hurtTimer != 0) {
        pthis->hurtTimer--;
    } else {
        ColliderInfo* acHitInfo;
        u8 swordDamage;

        if ((pthis->colCyl1.base.atFlags & 2) && pthis->actionFunc == EnGoma_Jump) {
            EnGoma_SetupLand(pthis);
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.velocity.y = 0.0f;
        }

        if ((pthis->colCyl2.base.acFlags & AC_HIT) && (s8)pthis->actor.colChkInfo.health > 0) {
            acHitInfo = pthis->colCyl2.info.acHitInfo;
            pthis->colCyl2.base.acFlags &= ~AC_HIT;

            if (pthis->gomaType == ENGOMA_NORMAL) {
                u32 dmgFlags = acHitInfo->toucher.dmgFlags;

                if (dmgFlags & 0x100000) {
                    if (pthis->actionFunc == EnGoma_Jump) {
                        EnGoma_SetupLand(pthis);
                        pthis->actor.velocity.y = 0.0f;
                        pthis->actor.speedXZ = -5.0f;
                    } else {
                        Matrix_RotateY(player->actor.shape.rot.y / (f32)0x8000 * M_PI, MTXMODE_NEW);
                        Matrix_MultVec3f(&sShieldKnockbackVel_89, &pthis->shieldKnockbackVel);
                        pthis->invincibilityTimer = 5;
                    }
                } else if (dmgFlags & 1) { // stun
                    if (pthis->actionFunc != EnGoma_Stunned) {
                        EnGoma_SetupStunned(pthis, globalCtx);
                        pthis->hurtTimer = 8;
                    }
                } else {
                    swordDamage = CollisionCheck_GetSwordDamage(dmgFlags);

                    if (swordDamage) {
                        EffectSsSibuki_SpawnBurst(globalCtx, &pthis->actor.focus.pos);
                    } else {
                        swordDamage = 1;
                    }

                    pthis->actor.colChkInfo.health -= swordDamage;
                    EnGoma_SetupHurt(pthis, globalCtx);
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 5);
                    pthis->hurtTimer = 13;
                }
            } else {
                // die if still an egg
                if (pthis->actor.params <= 5) { //! BossGoma only has 3 children
                    BossGoma* parent = (BossGoma*)pthis->actor.parent;

                    parent->childrenGohmaState[pthis->actor.params] = -1;
                }

                EnGoma_SpawnHatchDebris(pthis, globalCtx);
                Actor_Kill(&pthis->actor);
            }
        }
    }
}

void EnGoma_UpdateEyeEnvColor(EnGoma* pthis) {

    Math_ApproachF(&pthis->eyeEnvColor[0], sTargetEyeEnvColors_90[0][pthis->visualState], 0.5f, 20.0f);
    Math_ApproachF(&pthis->eyeEnvColor[1], sTargetEyeEnvColors_90[1][pthis->visualState], 0.5f, 20.0f);
    Math_ApproachF(&pthis->eyeEnvColor[2], sTargetEyeEnvColors_90[2][pthis->visualState], 0.5f, 20.0f);
}

#include "hack.h"

void EnGoma_SetFloorRot(EnGoma* pthis) {
    f32 nx;
    f32 ny;
    f32 nz;

    if (pthis->actor.floorPoly != NULL) {
        nx = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.x);
        ny = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.y);
        nz = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.z);
        Math_ApproachS(&pthis->slopePitch, -Math_FAtan2F(-nz * ny, 1.0f) * (0x8000 / M_PI), 1, 1000);
        Math_ApproachS(&pthis->slopeRoll, Math_FAtan2F(-nx * ny, 1.0f) * (0x8000 / M_PI), 1, 1000);
    }
}

void EnGoma_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* pthis = (EnGoma*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (pthis->invincibilityTimer != 0) {
        pthis->invincibilityTimer--;
    }

    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    pthis->actor.world.pos.x = pthis->actor.world.pos.x + pthis->shieldKnockbackVel.x;
    pthis->actor.world.pos.z = pthis->actor.world.pos.z + pthis->shieldKnockbackVel.z;
    Math_ApproachZeroF(&pthis->shieldKnockbackVel.x, 1.0f, 3.0f);
    Math_ApproachZeroF(&pthis->shieldKnockbackVel.z, 1.0f, 3.0f);

    if (pthis->actor.params < 10) {
        pthis->eggTimer++;
        Math_SmoothStepToF(&pthis->actor.scale.x, 0.01f, 0.5f, 0.00075f, 0.000001f);
        Math_SmoothStepToF(&pthis->actor.scale.y, 0.01f, 0.5f, 0.00075f, 0.000001f);
        Math_SmoothStepToF(&pthis->actor.scale.z, 0.01f, 0.5f, 0.00075f, 0.000001f);
        EnGoma_UpdateHit(pthis, globalCtx);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 5);
        EnGoma_SetFloorRot(pthis);
        Actor_SetFocus(&pthis->actor, 20.0f);
        EnGoma_LookAtPlayer(pthis, globalCtx);
        EnGoma_UpdateEyeEnvColor(pthis);
        pthis->visualState = 1;
        if (player->swordState != 0) {
            pthis->colCyl2.dim.radius = 35;
            pthis->colCyl2.dim.height = 35;
            pthis->colCyl2.dim.yShift = 0;
        } else {
            pthis->colCyl2.dim.radius = 15;
            pthis->colCyl2.dim.height = 30;
            pthis->colCyl2.dim.yShift = 10;
        }
        if (pthis->invincibilityTimer == 0) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->colCyl1);
            Collider_UpdateCylinder(&pthis->actor, &pthis->colCyl2);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colCyl1.base);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCyl2.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colCyl1.base);
        }
    }
}

s32 EnGoma_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnGoma* pthis = (EnGoma*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 1976);
    gDPSetEnvColor(POLY_OPA_DISP++, (s16)pthis->eyeEnvColor[0], (s16)pthis->eyeEnvColor[1], (s16)pthis->eyeEnvColor[2],
                   255);

    if (limbIndex == GOMA_LIMB_EYE_IRIS_ROOT1) {
        rot->x += pthis->eyePitch;
        rot->y += pthis->eyeYaw;
    } else if (limbIndex == GOMA_LIMB_BODY && pthis->hurtTimer != 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, (s16)(Rand_ZeroOne() * 255.0f), (s16)(Rand_ZeroOne() * 255.0f),
                       (s16)(Rand_ZeroOne() * 255.0f), 255);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2011);
    return 0;
}

Gfx* EnGoma_NoBackfaceCullingDlist(GraphicsContext* gfxCtx) {
    Gfx* dListHead;
    Gfx* dList;

    dListHead = dList = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 4);
    gDPPipeSync(dListHead++);
    gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2);
    gSPClearGeometryMode(dListHead++, G_CULL_BACK);
    gSPEndDisplayList(dListHead++);
    return dList;
}

void EnGoma_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* pthis = (EnGoma*)thisx;
    s32 y;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2040);
    func_80093D18(globalCtx->state.gfxCtx);

    switch (pthis->gomaType) {
        case ENGOMA_NORMAL:
            pthis->actor.naviEnemyId = 0x03;
            Matrix_Translate(pthis->actor.world.pos.x,
                             pthis->actor.world.pos.y + ((pthis->actor.shape.yOffset * pthis->actor.scale.y) +
                                                        globalCtx->mainCamera.skyboxOffset.y),
                             pthis->actor.world.pos.z, MTXMODE_NEW);
            Matrix_RotateX(pthis->slopePitch / (f32)0x8000 * M_PI, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->slopeRoll / (f32)0x8000 * M_PI, MTXMODE_APPLY);
            Matrix_RotateY(pthis->actor.shape.rot.y / (f32)0x8000 * M_PI, MTXMODE_APPLY);
            Matrix_RotateX(pthis->actor.shape.rot.x / (f32)0x8000 * M_PI, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->actor.shape.rot.z / (f32)0x8000 * M_PI, MTXMODE_APPLY);
            Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
            SkelAnime_DrawOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, EnGoma_OverrideLimbDraw,
                              NULL, pthis);
            break;

        case ENGOMA_EGG:
            pthis->actor.naviEnemyId = 0x02;
            y = (s16)(sinf((pthis->eggTimer * 5.0f * 3.1415f) / 180.0f) * 31.9f);
            y = (s16)(y + 31);
            gSPSegment(POLY_OPA_DISP++, 0x08, func_80094E78(globalCtx->state.gfxCtx, 0, y));
            Matrix_Push();
            Matrix_Scale(pthis->eggScale, 1.0f / pthis->eggScale, pthis->eggScale, MTXMODE_APPLY);
            Matrix_RotateY(pthis->eggSquishAngle * 0.15f, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->eggSquishAngle * 0.1f, MTXMODE_APPLY);
            Matrix_Scale(0.95f - pthis->eggSquishAmount, pthis->eggSquishAmount + 1.05f, 0.95f - pthis->eggSquishAmount,
                         MTXMODE_APPLY);
            Matrix_RotateZ(-(pthis->eggSquishAngle * 0.1f), MTXMODE_APPLY);
            Matrix_RotateY(-(pthis->eggSquishAngle * 0.15f), MTXMODE_APPLY);
            Matrix_Translate(0.0f, pthis->eggYOffset, 0.0f, MTXMODE_APPLY);
            Matrix_RotateX(pthis->eggPitch, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2101),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gObjectGolEggDL);
            Matrix_Pop();
            break;

        case ENGOMA_HATCH_DEBRIS:
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2107),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gBrownFragmentDL);
            break;

        case ENGOMA_BOSSLIMB:
            if (pthis->bossLimbDl != NULL) {
                gSPSegment(POLY_OPA_DISP++, 0x08, EnGoma_NoBackfaceCullingDlist(globalCtx->state.gfxCtx));
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2114),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, pthis->bossLimbDl);
            }
            break;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2119);
}

void EnGoma_Debris(EnGoma* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += 2500;
    pthis->actor.shape.rot.x += 3500;
    if (pthis->actionTimer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnGoma_SpawnHatchDebris(EnGoma* pthis, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    s16 i;

    if (pthis->actor.params < 6) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 0x28, NA_SE_EN_GOMA_BJR_EGG2);
    } else {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 0x28, NA_SE_EN_GOMA_EGG2);
    }

    for (i = 0; i < 15; i++) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_GOMA,
                           Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.x,
                           Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y + 15.0f,
                           Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.z, 0, Rand_CenteredFloat(0x10000 - 0.01f),
                           0, i + 10);
    }
}

void EnGoma_BossLimb(EnGoma* pthis, GlobalContext* globalCtx) {
    Vec3f vel = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 1.0f, 0.0f };
    Color_RGBA8 primColor = { 255, 255, 255, 255 };
    Color_RGBA8 envColor = { 0, 100, 255, 255 };
    Vec3f pos;

    pthis->actor.world.pos.y -= 5.0f;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 4);
    pthis->actor.world.pos.y += 5.0f;

    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.velocity.y = 0.0f;
    } else if (pthis->actionTimer < 250) {
        pthis->actor.shape.rot.y += 2000;
    }

    if (pthis->actionTimer == 250) {
        pthis->actor.gravity = -1.0f;
    }

    if (pthis->actionTimer < 121) {
        if (Math_SmoothStepToF(&pthis->actor.scale.y, 0.0f, 1.0f, 0.00075f, 0) <= 0.001f) {
            Actor_Kill(&pthis->actor);
        }
        pthis->actor.scale.x = pthis->actor.scale.z = pthis->actor.scale.y;
    }

    if (pthis->actionTimer % 8 == 0 && pthis->actionTimer != 0) {
        pos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
        pos.y = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y;
        pos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
        func_8002836C(globalCtx, &pos, &vel, &accel, &primColor, &envColor, 500, 10, 10);
    }
}

void EnGoma_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sShieldKnockbackVel_89 = { 0.0f, 0.0f, 20.0f };

    En_Goma_InitVars = {
        ACTOR_BOSS_GOMA,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_GOL,
        sizeof(EnGoma),
        (ActorFunc)EnGoma_Init,
        (ActorFunc)EnGoma_Destroy,
        (ActorFunc)EnGoma_Update,
        (ActorFunc)EnGoma_Draw,
        (ActorFunc)EnGoma_Reset,
    };

    D_80A4B7A0 = {
        {
            COLTYPE_HIT3,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFDFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 15, 30, 10, { 0, 0, 0 } },
    };

    D_80A4B7CC = {
        {
            COLTYPE_HIT3,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFDFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 15, 30, 10, { 0, 0, 0 } },
    };

    sSpawnNum = 0;

    sDeadEffectVel = { 0.0f, 0.0f, 0.0f };

}

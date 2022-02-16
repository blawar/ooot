#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BILI_Z_EN_BILI_C
#include "actor_common.h"
/*
 * File: z_en_bili.c
 * Overlay: ovl_En_Bili
 * Description: Biri (small jellyfish-like enemy)
 */

#include "z_en_bili.h"
#include "objects/object_bl/object_bl.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_12 | ACTOR_FLAG_14)

void EnBili_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBili_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBili_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBili_SetupFloatIdle(EnBili* pthis);
void EnBili_SetupSpawnedFlyApart(EnBili* pthis);
void EnBili_FloatIdle(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_SpawnedFlyApart(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_DischargeLightning(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Climb(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_ApproachPlayer(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_SetNewHomeHeight(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Recoil(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Burnt(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Die(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Stunned(EnBili* pthis, GlobalContext* globalCtx);
void EnBili_Frozen(EnBili* pthis, GlobalContext* globalCtx);

static Color_RGBA8 primColor_76 = { 255, 255, 255, 255 };

static Color_RGBA8 envColor_76 = { 200, 255, 255, 255 };

static Vec3f effectVelocity_82 = { 0.0f, 0.0f, 0.0f };

static Vec3f effectAccel_82 = { 0.0f, 0.0f, 0.0f };


ActorInit En_Bili_InitVars = {
    ACTOR_EN_BILI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BL,
    sizeof(EnBili),
    (ActorFunc)EnBili_Init,
    (ActorFunc)EnBili_Destroy,
    (ActorFunc)EnBili_Update,
    (ActorFunc)EnBili_Draw,
    (ActorFunc)EnBili_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT8,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x03, 0x08 },
        { 0xFFCFFFFF, 0x01, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 9, 28, -20, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 1, 9, 28, -20, 30 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, BIRI_DMGEFF_DEKUNUT),
    /* Deku stick    */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(0, BIRI_DMGEFF_SLINGSHOT),
    /* Explosive     */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(1, BIRI_DMGEFF_NONE),
    /* Normal arrow  */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Kokiri sword  */ DMG_ENTRY(1, BIRI_DMGEFF_SWORD),
    /* Master sword  */ DMG_ENTRY(2, BIRI_DMGEFF_SWORD),
    /* Giant's Knife */ DMG_ENTRY(4, BIRI_DMGEFF_SWORD),
    /* Fire arrow    */ DMG_ENTRY(4, BIRI_DMGEFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(4, BIRI_DMGEFF_ICE),
    /* Light arrow   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(4, BIRI_DMGEFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(4, BIRI_DMGEFF_ICE),
    /* Light magic   */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    /* Shield        */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, BIRI_DMGEFF_NONE),
    /* Giant spin    */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
    /* Master spin   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Kokiri jump   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
    /* Giant jump    */ DMG_ENTRY(8, BIRI_DMGEFF_NONE),
    /* Master jump   */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
    /* Unknown 1     */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x17, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_STOP),
};

void EnBili_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBili* pthis = (EnBili*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 17.0f);
    pthis->actor.shape.shadowAlpha = 155;
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBiriSkel, &gBiriDefaultAnim, pthis->jointTable, pthis->morphTable,
                   EN_BILI_LIMB_MAX);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->playFlySound = false;

    if (pthis->actor.params == EN_BILI_TYPE_NORMAL) {
        EnBili_SetupFloatIdle(pthis);
    } else {
        EnBili_SetupSpawnedFlyApart(pthis);
    }
}

void EnBili_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBili* pthis = (EnBili*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

// Setup Action Functions

void EnBili_SetupFloatIdle(EnBili* pthis) {
    pthis->actor.speedXZ = 0.7f;
    pthis->collider.info.bumper.effect = 1; // Shock?
    pthis->timer = 32;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->collider.base.acFlags |= AC_ON;
    pthis->actionFunc = EnBili_FloatIdle;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
}

/**
 * Separates the Biri spawned by a dying EnVali.
 */
void EnBili_SetupSpawnedFlyApart(EnBili* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gBiriDefaultAnim);
    pthis->timer = 25;
    pthis->actor.velocity.y = 6.0f;
    pthis->actor.gravity = -0.3f;
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->actionFunc = EnBili_SpawnedFlyApart;
    pthis->actor.speedXZ = 3.0f;
}

/**
 * Used for both touching player/player's shield and being hit with sword. What to do next is determined by params.
 */
void EnBili_SetupDischargeLightning(EnBili* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gBiriDischargeLightningAnim);
    pthis->timer = 10;
    pthis->actionFunc = EnBili_DischargeLightning;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = -1.0f;
}

void EnBili_SetupClimb(EnBili* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gBiriClimbAnim);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->actionFunc = EnBili_Climb;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
}

void EnBili_SetupApproachPlayer(EnBili* pthis) {
    pthis->actor.speedXZ = 1.2f;
    pthis->actionFunc = EnBili_ApproachPlayer;
}

void EnBili_SetupSetNewHomeHeight(EnBili* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gBiriDefaultAnim);
    pthis->timer = 96;
    pthis->actor.speedXZ = 0.9f;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->actionFunc = EnBili_SetNewHomeHeight;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
}

void EnBili_SetupRecoil(EnBili* pthis) {
    if (pthis->skelAnime.animation != &gBiriDefaultAnim) {
        Animation_PlayLoop(&pthis->skelAnime, &gBiriDefaultAnim);
    }

    pthis->actor.world.rot.y = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->collider.base.ac->prevPos) + 0x8000;
    pthis->actor.world.rot.x = Actor_WorldPitchTowardPoint(&pthis->actor, &pthis->collider.base.ac->prevPos);
    pthis->actionFunc = EnBili_Recoil;
    pthis->actor.speedXZ = 5.0f;
}

/**
 * Used for both fire damage and generic damage
 */
void EnBili_SetupBurnt(EnBili* pthis) {
    if (pthis->actionFunc == EnBili_Climb) {
        Animation_PlayLoop(&pthis->skelAnime, &gBiriDefaultAnim);
    }

    pthis->timer = 20;
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0x2000, 0x14);
    pthis->actionFunc = EnBili_Burnt;
}

void EnBili_SetupDie(EnBili* pthis) {
    pthis->timer = 18;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnBili_Die;
    pthis->actor.speedXZ = 0.0f;
}

/**
 * Falls to ground
 */
void EnBili_SetupStunned(EnBili* pthis) {
    pthis->timer = 80;
    pthis->collider.info.bumper.effect = 0;
    pthis->actor.gravity = -1.0f;
    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 0x96, 0x2000, 0x50);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->actionFunc = EnBili_Stunned;
}

void EnBili_SetupFrozen(EnBili* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f effectPos;

    if (!(pthis->actor.flags & ACTOR_FLAG_15)) {
        pthis->actor.gravity = -1.0f;
    }

    pthis->actor.velocity.y = 0.0f;
    effectPos.y = pthis->actor.world.pos.y - 15.0f;

    for (i = 0; i < 8; i++) {

        effectPos.x = pthis->actor.world.pos.x + ((i & 1) ? 7.0f : -7.0f);
        effectPos.y += 2.5f;
        effectPos.z = pthis->actor.world.pos.z + ((i & 4) ? 7.0f : -7.0f);

        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &effectPos, 150, 150, 150, 250, 235, 245, 255,
                                       (Rand_ZeroOne() * 0.2f) + 0.7f);
    }

    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 0x96, 0x2000, 0xA);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->timer = 300;
    pthis->actionFunc = EnBili_Frozen;
}

// Miscellaneous

/**
 * Changes the texture displayed on the oral arms limb using the current frame.
 */
void EnBili_UpdateTentaclesIndex(EnBili* pthis) {
    s16 curFrame = pthis->skelAnime.curFrame;
    s16 temp; // Not strictly necessary, but avoids a few s16 casts

    if (pthis->actionFunc == EnBili_DischargeLightning) {
        temp = 3 - curFrame;
        pthis->tentaclesTexIndex = (ABS(temp) + 5) % 8;
    } else if (pthis->actionFunc == EnBili_Climb) {
        if (curFrame <= 9) {
            temp = curFrame >> 1;
            pthis->tentaclesTexIndex = CLAMP_MAX(temp, 3);
        } else if (curFrame <= 18) {
            temp = 17 - curFrame;
            pthis->tentaclesTexIndex = CLAMP_MIN(temp, 0) >> 1;
        } else if (curFrame <= 36) {
            pthis->tentaclesTexIndex = ((36 - curFrame) / 3) + 2;
        } else {
            pthis->tentaclesTexIndex = (40 - curFrame) >> 1;
        }
    } else {
        pthis->tentaclesTexIndex = curFrame >> 1;
    }
}

/**
 * Tracks Player height, with oscillation, and moves away from walls
 */
void EnBili_UpdateFloating(EnBili* pthis) {
    f32 playerHeight = pthis->actor.world.pos.y + pthis->actor.yDistToPlayer;
    f32 heightOffset = ((pthis->actionFunc == EnBili_SetNewHomeHeight) ? 100.0f : 40.0f);
    f32 baseHeight = CLAMP_MIN(pthis->actor.floorHeight, playerHeight);

    Math_StepToF(&pthis->actor.home.pos.y, baseHeight + heightOffset, 1.0f);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (sinf(pthis->timer * (M_PI / 16)) * 3.0f);

    // Turn around if touching wall
    if (pthis->actor.bgCheckFlags & 8) {
        pthis->actor.world.rot.y = pthis->actor.wallYaw;
    }
}

// Action functions

void EnBili_FloatIdle(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (!(pthis->timer % 4)) {
        pthis->actor.world.rot.y += Rand_CenteredFloat(1820.0f);
    }

    EnBili_UpdateFloating(pthis);

    if (pthis->timer == 0) {
        pthis->timer = 32;
    }

    if ((pthis->actor.xzDistToPlayer < 160.0f) && (fabsf(pthis->actor.yDistToPlayer) < 45.0f)) {
        EnBili_SetupApproachPlayer(pthis);
    }
}

void EnBili_SpawnedFlyApart(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        EnBili_SetupFloatIdle(pthis);
    }
}

void EnBili_DischargeLightning(EnBili* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f effectPos;
    s16 effectYaw;

    for (i = 0; i < 4; i++) {
        if (!((pthis->timer + (i << 1)) % 4)) {
            effectYaw = (s16)Rand_CenteredFloat(12288.0f) + (i * 0x4000) + 0x2000;
            effectPos.x = Rand_CenteredFloat(5.0f) + pthis->actor.world.pos.x;
            effectPos.y = (Rand_ZeroOne() * 5.0f) + pthis->actor.world.pos.y + 2.5f;
            effectPos.z = Rand_CenteredFloat(5.0f) + pthis->actor.world.pos.z;
            EffectSsLightning_Spawn(globalCtx, &effectPos, &primColor_76, &envColor_76, 15, effectYaw, 6, 2);
        }
    }

    SkelAnime_Update(&pthis->skelAnime);
    func_8002F974(&pthis->actor, NA_SE_EN_BIRI_SPARK - SFX_FLAG);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.velocity.y *= -1.0f;

    if ((pthis->timer == 0) && Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        if (pthis->actor.params == EN_BILI_TYPE_DYING) {
            EnBili_SetupDie(pthis);
        } else {
            EnBili_SetupClimb(pthis);
        }
    }
}

void EnBili_Climb(EnBili* pthis, GlobalContext* globalCtx) {
    s32 skelAnimeUpdate = SkelAnime_Update(&pthis->skelAnime);
    f32 curFrame = pthis->skelAnime.curFrame;

    if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIRI_JUMP);
    }

    if (curFrame > 9.0f) {
        Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.world.pos.y + pthis->actor.yDistToPlayer + 100.0f, 0.5f,
                       5.0f);
    }

    if (skelAnimeUpdate) {
        EnBili_SetupSetNewHomeHeight(pthis);
    }
}

void EnBili_ApproachPlayer(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 2, 1820);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    EnBili_UpdateFloating(pthis);

    if (pthis->timer == 0) {
        pthis->timer = 32;
    }

    if (pthis->actor.xzDistToPlayer > 200.0f) {
        EnBili_SetupFloatIdle(pthis);
    }
}

void EnBili_SetNewHomeHeight(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, (s16)(pthis->actor.yawTowardsPlayer + 0x8000), 910);
    EnBili_UpdateFloating(pthis);

    if (pthis->timer == 0) {
        EnBili_SetupFloatIdle(pthis);
    }
}

void EnBili_Recoil(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.3f)) {
        pthis->actor.world.rot.y += 0x8000;
        EnBili_SetupFloatIdle(pthis);
    }
}

void EnBili_Burnt(EnBili* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.flags & ACTOR_FLAG_15) {
        pthis->actor.colorFilterTimer = 20;
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            EnBili_SetupDie(pthis);
        }
    }
}

void EnBili_Die(EnBili* pthis, GlobalContext* globalCtx) {
    s16 effectScale;
    Vec3f effectPos;
    s32 i;

    if (pthis->actor.draw != NULL) {
        if (pthis->actor.flags & ACTOR_FLAG_15) {
            return;
        }
        pthis->actor.draw = NULL;
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x50);
    }

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer != 0) {
        for (i = 0; i < 2; i++) {
            effectPos.x = ((Rand_ZeroOne() * 10.0f) + pthis->actor.world.pos.x) - 5.0f;
            effectPos.y = ((Rand_ZeroOne() * 5.0f) + pthis->actor.world.pos.y) - 2.5f;
            effectPos.z = ((Rand_ZeroOne() * 10.0f) + pthis->actor.world.pos.z) - 5.0f;

            effectVelocity_82.y = Rand_ZeroOne() + 1.0f;
            effectScale = Rand_S16Offset(40, 40);

            if (Rand_ZeroOne() < 0.7f) {
                EffectSsDtBubble_SpawnColorProfile(globalCtx, &effectPos, &effectVelocity_82, &effectAccel_82, effectScale,
                                                   25, 2, 1);
            } else {
                EffectSsDtBubble_SpawnColorProfile(globalCtx, &effectPos, &effectVelocity_82, &effectAccel_82, effectScale,
                                                   25, 0, 1);
            }
        }
    } else {
        Actor_Kill(&pthis->actor);
    }

    if (pthis->timer == 14) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_BIRI_BUBLE);
    }
}

void EnBili_Stunned(EnBili* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    }

    if (pthis->timer == 0) {
        EnBili_SetupFloatIdle(pthis);
    }
}

void EnBili_Frozen(EnBili* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (!(pthis->actor.flags & ACTOR_FLAG_15)) {
        pthis->actor.gravity = -1.0f;
    }

    if ((pthis->actor.bgCheckFlags & 1) || (pthis->actor.floorHeight == BGCHECK_Y_MIN)) {
        pthis->actor.colorFilterTimer = 0;
        EnBili_SetupDie(pthis);
    } else {
        pthis->actor.colorFilterTimer = 10;
    }
}

void EnBili_UpdateDamage(EnBili* pthis, GlobalContext* globalCtx) {
    u8 damageEffect;

    if ((pthis->actor.colChkInfo.health != 0) && (pthis->collider.base.acFlags & AC_HIT)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);

        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIRI_DEAD);
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            }

            damageEffect = pthis->actor.colChkInfo.damageEffect;

            if (damageEffect == BIRI_DMGEFF_DEKUNUT) {
                if (pthis->actionFunc != EnBili_Stunned) {
                    EnBili_SetupStunned(pthis);
                }
            } else if (damageEffect == BIRI_DMGEFF_SWORD) {
                if (pthis->actionFunc != EnBili_Stunned) {
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0x2000, 0xA);

                    if (pthis->actor.colChkInfo.health == 0) {
                        pthis->actor.params = EN_BILI_TYPE_DYING;
                    }
                    EnBili_SetupDischargeLightning(pthis);
                } else {
                    EnBili_SetupBurnt(pthis);
                }
            } else if (damageEffect == BIRI_DMGEFF_FIRE) {
                EnBili_SetupBurnt(pthis);
                pthis->timer = 2;
            } else if (damageEffect == BIRI_DMGEFF_ICE) {
                EnBili_SetupFrozen(pthis, globalCtx);
            } else if (damageEffect == BIRI_DMGEFF_SLINGSHOT) {
                EnBili_SetupRecoil(pthis);
            } else {
                EnBili_SetupBurnt(pthis);
            }

            if (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x1F820) { // DMG_ARROW
                pthis->actor.flags |= ACTOR_FLAG_4;
            }
        }
    }
}

void EnBili_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnBili* pthis = (EnBili*)thisx;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        EnBili_SetupDischargeLightning(pthis);
    }

    EnBili_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actionFunc != EnBili_Die) {
        EnBili_UpdateTentaclesIndex(pthis);
        if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
            if ((pthis->actionFunc == EnBili_FloatIdle) || (pthis->actionFunc == EnBili_SetNewHomeHeight) ||
                (pthis->actionFunc == EnBili_ApproachPlayer) || (pthis->actionFunc == EnBili_Recoil)) {
                if (pthis->playFlySound) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BIRI_FLY);
                    pthis->playFlySound = false;
                } else {
                    pthis->playFlySound = true;
                }
            }
        }
        if (pthis->actionFunc == EnBili_Recoil) {
            func_8002D97C(&pthis->actor);
        } else {
            Actor_MoveForward(&pthis->actor);
        }

        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, pthis->collider.dim.radius, pthis->collider.dim.height, 7);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

        if (pthis->collider.base.atFlags & AT_ON) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        Actor_SetFocus(&pthis->actor, 0.0f);
    }
}

// Draw and associated functions

void EnBili_PulseLimb3(EnBili* pthis, f32 frame, Vec3f* arg2) {
    f32 cos;
    f32 sin;

    if (pthis->actionFunc == EnBili_DischargeLightning) {
        arg2->y = 1.0f - (sinf((M_PI * 0.16667f) * frame) * 0.26f);
    } else if (pthis->actionFunc == EnBili_Climb) {
        if (frame <= 8.0f) {
            arg2->y = (cosf((M_PI * 0.125f) * frame) * 0.15f) + 0.85f;
        } else if (frame <= 18.0f) {
            cos = cosf((frame - 8.0f) * (M_PI * 0.1f));
            arg2->y = 1.0f - (0.3f * cos);
            arg2->x = (0.2f * cos) + 0.8f;
        } else {
            cos = cosf((frame - 18.0f) * (M_PI * 0.0227f));
            arg2->y = (0.31f * cos) + 1.0f;
            arg2->x = 1.0f - (0.4f * cos);
        }

        arg2->z = arg2->x;
    } else if (pthis->actionFunc == EnBili_Stunned) {
        sin = sinf((M_PI * 0.1f) * pthis->timer) * 0.08f;
        arg2->x -= sin;
        arg2->y += sin;
        arg2->z -= sin;
    } else {
        arg2->y = (cosf((M_PI * 0.125f) * frame) * 0.13f) + 0.87f;
    }
}

void EnBili_PulseLimb2(EnBili* pthis, f32 frame, Vec3f* arg2) {
    f32 cos;
    f32 sin;

    if (pthis->actionFunc == EnBili_DischargeLightning) {
        arg2->y = (sinf((M_PI * 0.16667f) * frame) * 0.2f) + 1.0f;
    } else if (pthis->actionFunc == EnBili_Climb) {
        if (frame <= 8.0f) {
            arg2->x = 1.125f - (cosf((M_PI * 0.125f) * frame) * 0.125f);
        } else if (frame <= 18.0f) {
            cos = cosf((frame - 8.0f) * (M_PI * 0.1f));
            arg2->x = (0.275f * cos) + 0.975f;
            arg2->y = 1.25f - (0.25f * cos);
        } else {
            cos = cosf((frame - 18.0f) * (M_PI * 0.0227f));
            arg2->x = 1.0f - (0.3f * cos);
            arg2->y = (0.48f * cos) + 1.0f;
        }
        arg2->z = arg2->x;
    } else if (pthis->actionFunc == EnBili_Stunned) {
        sin = sinf((M_PI * 0.1f) * pthis->timer) * 0.08f;
        arg2->x += sin;
        arg2->y -= sin;
        arg2->z += sin;
    } else {
        arg2->y = 1.1f - (cosf((M_PI * 0.125f) * frame) * 0.1f);
    }
}

void EnBili_PulseLimb4(EnBili* pthis, f32 frame, Vec3f* arg2) {
    f32 cos;

    if (pthis->actionFunc == EnBili_Climb) {
        if (frame <= 8.0f) {
            cos = cosf((M_PI * 0.125f) * frame);
            arg2->x = 1.125f - (0.125f * cos);
            arg2->y = (0.3f * cos) + 0.7f;
        } else if (frame <= 18.0f) {
            cos = cosf((frame - 8.0f) * (M_PI * 0.1f));
            arg2->x = (0.325f * cos) + 0.925f;
            arg2->y = 0.95f - (0.55f * cos);
        } else {
            cos = cosf((frame - 18.0f) * (M_PI * 0.0227f));
            arg2->x = 1.0f - (0.4f * cos);
            arg2->y = (0.52f * cos) + 1.0f;
        }
        arg2->z = arg2->x;
    }
}

s32 EnBili_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                            Gfx** gfx) {
    EnBili* pthis = (EnBili*)thisx;
    Vec3f limbScale = { 1.0f, 1.0f, 1.0f };
    f32 curFrame = pthis->skelAnime.curFrame;

    if (limbIndex == EN_BILI_LIMB_OUTER_HOOD) {
        EnBili_PulseLimb3(pthis, curFrame, &limbScale);
    } else if (limbIndex == EN_BILI_LIMB_INNER_HOOD) {
        EnBili_PulseLimb2(pthis, curFrame, &limbScale);
    } else if (limbIndex == EN_BILI_LIMB_TENTACLES) {
        EnBili_PulseLimb4(pthis, curFrame, &limbScale);
        rot->y = (Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - pthis->actor.shape.rot.y) + 0x8000;
    }

    Matrix_Scale(limbScale.x, limbScale.y, limbScale.z, MTXMODE_APPLY);
    return false;
}

static void* sTentaclesTextures[] = {
    gBiriTentacles0Tex, gBiriTentacles1Tex, gBiriTentacles2Tex, gBiriTentacles3Tex,
    gBiriTentacles4Tex, gBiriTentacles5Tex, gBiriTentacles6Tex, gBiriTentacles7Tex,
};

#include "overlays/ovl_En_Bili/ovl_En_Bili.cpp"

void EnBili_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBili* pthis = (EnBili*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bili.c", 1521);
    func_80093D84(globalCtx->state.gfxCtx);

    pthis->tentaclesTexIndex = CLAMP_MAX(pthis->tentaclesTexIndex, 7);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTentaclesTextures[pthis->tentaclesTexIndex]));

    if ((pthis->actionFunc == EnBili_DischargeLightning) && ((pthis->timer & 1) != 0)) {
        gSPSegment(POLY_XLU_DISP++, 0x09, D_809C16F0);
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x09, D_809C1700);
    }

    POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                   EnBili_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bili.c", 1552);
}

void EnBili_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    primColor_76 = { 255, 255, 255, 255 };

    envColor_76 = { 200, 255, 255, 255 };

    effectVelocity_82 = { 0.0f, 0.0f, 0.0f };

    effectAccel_82 = { 0.0f, 0.0f, 0.0f };

    En_Bili_InitVars = {
        ACTOR_EN_BILI,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_BL,
        sizeof(EnBili),
        (ActorFunc)EnBili_Init,
        (ActorFunc)EnBili_Destroy,
        (ActorFunc)EnBili_Update,
        (ActorFunc)EnBili_Draw,
        (ActorFunc)EnBili_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT8,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x03, 0x08 },
            { 0xFFCFFFFF, 0x01, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 9, 28, -20, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 1, 9, 28, -20, 30 };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, BIRI_DMGEFF_DEKUNUT),
        /* Deku stick    */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(0, BIRI_DMGEFF_SLINGSHOT),
        /* Explosive     */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(1, BIRI_DMGEFF_NONE),
        /* Normal arrow  */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Hookshot      */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Kokiri sword  */ DMG_ENTRY(1, BIRI_DMGEFF_SWORD),
        /* Master sword  */ DMG_ENTRY(2, BIRI_DMGEFF_SWORD),
        /* Giant's Knife */ DMG_ENTRY(4, BIRI_DMGEFF_SWORD),
        /* Fire arrow    */ DMG_ENTRY(4, BIRI_DMGEFF_FIRE),
        /* Ice arrow     */ DMG_ENTRY(4, BIRI_DMGEFF_ICE),
        /* Light arrow   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Unk arrow 1   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(4, BIRI_DMGEFF_FIRE),
        /* Ice magic     */ DMG_ENTRY(4, BIRI_DMGEFF_ICE),
        /* Light magic   */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
        /* Shield        */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, BIRI_DMGEFF_NONE),
        /* Giant spin    */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
        /* Master spin   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Kokiri jump   */ DMG_ENTRY(2, BIRI_DMGEFF_NONE),
        /* Giant jump    */ DMG_ENTRY(8, BIRI_DMGEFF_NONE),
        /* Master jump   */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
        /* Unknown 1     */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, BIRI_DMGEFF_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, BIRI_DMGEFF_NONE),
    };

}

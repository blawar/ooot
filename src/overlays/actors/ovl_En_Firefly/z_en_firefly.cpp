#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FIREFLY_Z_EN_FIREFLY_C
#include "actor_common.h"
/*
 * File: z_en_firefly.c
 * Overlay: ovl_En_Firefly
 * Description: Keese (Normal, Fire, Ice)
 */

#include "z_en_firefly.h"
#include "objects/object_firefly/object_firefly.h"
#include "overlays/actors/ovl_Obj_Syokudai/z_obj_syokudai.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_12 | ACTOR_FLAG_14)

void EnFirefly_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnFirefly_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFirefly_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFirefly_DrawInvisible(Actor* thisx, GlobalContext* globalCtx);

void EnFirefly_FlyIdle(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_Fall(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_Die(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_DiveAttack(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_Rebound(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_FlyAway(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_Stunned(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_FrozenFall(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_Perch(EnFirefly* pthis, GlobalContext* globalCtx);
void EnFirefly_DisturbDiveAttack(EnFirefly* pthis, GlobalContext* globalCtx);

static Color_RGBA8 fireAuraPrimColor_75 = { 255, 255, 100, 255 };

static Color_RGBA8 fireAuraEnvColor_75 = { 255, 50, 0, 0 };

static Color_RGBA8 iceAuraPrimColor_75 = { 100, 200, 255, 255 };

static Color_RGBA8 iceAuraEnvColor_75 = { 0, 0, 255, 0 };

static Vec3f effVelocity_75 = { 0.0f, 0.5f, 0.0f };

static Vec3f effAccel_75 = { 0.0f, 0.5f, 0.0f };

static Vec3f limbSrc_75 = { 0.0f, 0.0f, 0.0f };


ActorInit En_Firefly_InitVars = {
    ACTOR_EN_FIREFLY,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FIREFLY,
    sizeof(EnFirefly),
    (ActorFunc)EnFirefly_Init,
    (ActorFunc)EnFirefly_Destroy,
    (ActorFunc)EnFirefly_Update,
    (ActorFunc)EnFirefly_Draw,
    (ActorFunc)EnFirefly_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 1000, 0 }, 15 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 1, 10, 10, 30 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(1, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0xF),
    /* Ice arrow     */ DMG_ENTRY(4, 0x3),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x2),
    /* Ice magic     */ DMG_ENTRY(4, 0x3),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 5, ICHAIN_CONTINUE),  ICHAIN_F32_DIV1000(gravity, -500, ICHAIN_CONTINUE),
    ICHAIN_F32(minVelocityY, -4, ICHAIN_CONTINUE),    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 4000, ICHAIN_STOP),
};

void EnFirefly_Extinguish(EnFirefly* pthis) {
    pthis->actor.params += 2;
    pthis->collider.elements[0].info.toucher.effect = 0; // None
    pthis->auraType = KEESE_AURA_NONE;
    pthis->onFire = false;
    pthis->actor.naviEnemyId = 0x12; // Keese
}

void EnFirefly_Ignite(EnFirefly* pthis) {
    if (pthis->actor.params == KEESE_ICE_FLY) {
        pthis->actor.params = KEESE_FIRE_FLY;
    } else {
        pthis->actor.params -= 2;
    }
    pthis->collider.elements[0].info.toucher.effect = 1; // Fire
    pthis->auraType = KEESE_AURA_FIRE;
    pthis->onFire = true;
    pthis->actor.naviEnemyId = 0x11; // Fire Keese
}

void EnFirefly_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* pthis = (EnFirefly*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gKeeseSkeleton, &gKeeseFlyAnim, pthis->jointTable, pthis->morphTable,
                   28);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);

    if ((pthis->actor.params & 0x8000) != 0) {
        pthis->actor.flags |= ACTOR_FLAG_7;
        if (1) {}
        pthis->actor.draw = EnFirefly_DrawInvisible;
        pthis->actor.params &= 0x7FFF;
    }

    if (pthis->actor.params <= KEESE_FIRE_PERCH) {
        pthis->onFire = true;
    } else {
        pthis->onFire = false;
    }

    if (pthis->onFire) {
        pthis->actionFunc = EnFirefly_FlyIdle;
        pthis->timer = Rand_S16Offset(20, 60);
        pthis->actor.shape.rot.x = 0x1554;
        pthis->auraType = KEESE_AURA_FIRE;
        pthis->actor.naviEnemyId = 0x11; // Fire Keese
        pthis->maxAltitude = pthis->actor.home.pos.y;
    } else {
        if (pthis->actor.params == KEESE_NORMAL_PERCH) {
            pthis->actionFunc = EnFirefly_Perch;
        } else {
            pthis->actionFunc = EnFirefly_FlyIdle;
        }

        if (pthis->actor.params == KEESE_ICE_FLY) {
            pthis->collider.elements[0].info.toucher.effect = 2; // Ice
            pthis->actor.naviEnemyId = 0x56;                     // Ice Keese
        } else {
            pthis->collider.elements[0].info.toucher.effect = 0; // Nothing
            pthis->actor.naviEnemyId = 0x12;                     // Keese
        }

        pthis->maxAltitude = pthis->actor.home.pos.y + 100.0f;

        if (pthis->actor.params == KEESE_ICE_FLY) {
            pthis->auraType = KEESE_AURA_ICE;
        } else {
            pthis->auraType = KEESE_AURA_NONE;
        }
    }

    pthis->collider.elements[0].dim.worldSphere.radius = sJntSphInit.elements[0].dim.modelSphere.radius;
}

void EnFirefly_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* pthis = (EnFirefly*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnFirefly_SetupFlyIdle(EnFirefly* pthis) {
    pthis->timer = Rand_S16Offset(70, 100);
    pthis->actor.speedXZ = (Rand_ZeroOne() * 1.5f) + 1.5f;
    Math_ScaledStepToS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos), 0x300);
    pthis->targetPitch = ((pthis->maxAltitude < pthis->actor.world.pos.y) ? 0xC00 : -0xC00) + 0x1554;
    pthis->skelAnime.playSpeed = 1.0f;
    pthis->actionFunc = EnFirefly_FlyIdle;
}

void EnFirefly_SetupFall(EnFirefly* pthis) {
    pthis->timer = 40;
    pthis->actor.velocity.y = 0.0f;
    Animation_Change(&pthis->skelAnime, &gKeeseFlyAnim, 0.5f, 0.0f, 0.0f, ANIMMODE_LOOP_INTERP, -3.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FFLY_DEAD);
    pthis->actor.flags |= ACTOR_FLAG_4;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 40);
    pthis->actionFunc = EnFirefly_Fall;
}

void EnFirefly_SetupDie(EnFirefly* pthis) {
    pthis->timer = 15;
    pthis->actor.speedXZ = 0.0f;
    pthis->actionFunc = EnFirefly_Die;
}

void EnFirefly_SetupRebound(EnFirefly* pthis) {
    pthis->actor.world.rot.x = 0x7000;
    pthis->timer = 18;
    pthis->skelAnime.playSpeed = 1.0f;
    pthis->actor.speedXZ = 2.5f;
    pthis->actionFunc = EnFirefly_Rebound;
}

void EnFirefly_SetupDiveAttack(EnFirefly* pthis) {
    pthis->timer = Rand_S16Offset(70, 100);
    pthis->skelAnime.playSpeed = 1.0f;
    pthis->targetPitch = ((pthis->actor.yDistToPlayer > 0.0f) ? -0xC00 : 0xC00) + 0x1554;
    pthis->actionFunc = EnFirefly_DiveAttack;
}

void EnFirefly_SetupFlyAway(EnFirefly* pthis) {
    pthis->timer = 150;
    pthis->skelAnime.playSpeed = 1.0f;
    pthis->targetPitch = 0x954;
    pthis->actionFunc = EnFirefly_FlyAway;
}

void EnFirefly_SetupStunned(EnFirefly* pthis) {
    pthis->timer = 80;
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 80);
    pthis->auraType = KEESE_AURA_NONE;
    pthis->actor.velocity.y = 0.0f;
    pthis->skelAnime.playSpeed = 3.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actionFunc = EnFirefly_Stunned;
}

void EnFirefly_SetupFrozenFall(EnFirefly* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f iceParticlePos;

    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->auraType = KEESE_AURA_NONE;
    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0xFF);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FFLY_DEAD);

    for (i = 0; i <= 7; i++) {
        iceParticlePos.x = (i & 1 ? 7.0f : -7.0f) + pthis->actor.world.pos.x;
        iceParticlePos.y = (i & 2 ? 7.0f : -7.0f) + pthis->actor.world.pos.y;
        iceParticlePos.z = (i & 4 ? 7.0f : -7.0f) + pthis->actor.world.pos.z;
        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &iceParticlePos, 150, 150, 150, 250, 235, 245, 255,
                                       (Rand_ZeroOne() * 0.15f) + 0.85f);
    }

    pthis->actionFunc = EnFirefly_FrozenFall;
}

void EnFirefly_SetupPerch(EnFirefly* pthis) {
    pthis->timer = 1;
    pthis->actor.speedXZ = 0.0f;
    pthis->actionFunc = EnFirefly_Perch;
}

void EnFirefly_SetupDisturbDiveAttack(EnFirefly* pthis) {
    pthis->skelAnime.playSpeed = 3.0f;
    pthis->actor.shape.rot.x = 0x1554;
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->actor.speedXZ = 3.0f;
    pthis->timer = 50;
    pthis->actionFunc = EnFirefly_DisturbDiveAttack;
}

s32 EnFirefly_ReturnToPerch(EnFirefly* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 distFromHome;

    if (pthis->actor.params != KEESE_NORMAL_PERCH) {
        return 0;
    }

    if (Actor_WorldDistXZToPoint(&player->actor, &pthis->actor.home.pos) > 300.0f) {
        distFromHome = Actor_WorldDistXYZToPoint(&pthis->actor, &pthis->actor.home.pos);

        if (distFromHome < 5.0f) {
            EnFirefly_SetupPerch(pthis);
            return 1;
        }

        distFromHome *= 0.05f;

        if (distFromHome < 1.0f) {
            pthis->actor.speedXZ *= distFromHome;
        }

        Math_ScaledStepToS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos),
                           0x300);
        Math_ScaledStepToS(&pthis->actor.shape.rot.x,
                           Actor_WorldPitchTowardPoint(&pthis->actor, &pthis->actor.home.pos) + 0x1554, 0x100);
        return 1;
    }

    return 0;
}

s32 EnFirefly_SeekTorch(EnFirefly* pthis, GlobalContext* globalCtx) {
    ObjSyokudai* findTorch;
    ObjSyokudai* closestTorch;
    f32 torchDist;
    f32 currentMinDist;
    Vec3f flamePos;

    findTorch = (ObjSyokudai*)globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
    closestTorch = NULL;
    currentMinDist = 35000.0f;

    while (findTorch != NULL) {
        if ((findTorch->actor.id == ACTOR_OBJ_SYOKUDAI) && (findTorch->litTimer != 0)) {
            torchDist = Actor_WorldDistXYZToActor(&pthis->actor, &findTorch->actor);
            if (torchDist < currentMinDist) {
                currentMinDist = torchDist;
                closestTorch = findTorch;
            }
        }
        findTorch = (ObjSyokudai*)findTorch->actor.next;
    }

    if (closestTorch != NULL) {
        flamePos.x = closestTorch->actor.world.pos.x;
        flamePos.y = closestTorch->actor.world.pos.y + 52.0f + 15.0f;
        flamePos.z = closestTorch->actor.world.pos.z;
        if (Actor_WorldDistXYZToPoint(&pthis->actor, &flamePos) < 15.0f) {
            EnFirefly_Ignite(pthis);
            return 1;
        } else {
            Math_ScaledStepToS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardActor(&pthis->actor, &closestTorch->actor),
                               0x300);
            Math_ScaledStepToS(&pthis->actor.shape.rot.x, Actor_WorldPitchTowardPoint(&pthis->actor, &flamePos) + 0x1554,
                               0x100);
            return 1;
        }
    }
    return 0;
}

void EnFirefly_FlyIdle(EnFirefly* pthis, GlobalContext* globalCtx) {
    s32 skelanimeUpdated;
    f32 rand;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    skelanimeUpdated = Animation_OnFrame(&pthis->skelAnime, 0.0f);
    pthis->actor.speedXZ = (Rand_ZeroOne() * 1.5f) + 1.5f;
    if (pthis->onFire || (pthis->actor.params == KEESE_ICE_FLY) ||
        ((EnFirefly_ReturnToPerch(pthis, globalCtx) == 0) && (EnFirefly_SeekTorch(pthis, globalCtx) == 0))) {
        if (skelanimeUpdated) {
            rand = Rand_ZeroOne();
            if (rand < 0.5f) {
                Math_ScaledStepToS(&pthis->actor.shape.rot.y,
                                   Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos), 0x300);
            } else if (rand < 0.8f) {
                pthis->actor.shape.rot.y += Rand_CenteredFloat(1536.0f);
            }
            // Climb if too close to ground
            if (pthis->actor.world.pos.y < (pthis->actor.floorHeight + 20.0f)) {
                pthis->targetPitch = 0x954;
                // Descend if above maxAltitude
            } else if (pthis->maxAltitude < pthis->actor.world.pos.y) {
                pthis->targetPitch = 0x2154;
                // Otherwise ascend or descend at random, biased towards ascending
            } else if (0.35f < Rand_ZeroOne()) {
                pthis->targetPitch = 0x954;
            } else {
                pthis->targetPitch = 0x2154;
            }
        } else {
            if (pthis->actor.bgCheckFlags & 1) {
                pthis->targetPitch = 0x954;
            } else if ((pthis->actor.bgCheckFlags & 0x10) || (pthis->maxAltitude < pthis->actor.world.pos.y)) {
                pthis->targetPitch = 0x2154;
            }
        }
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->targetPitch, 0x100);
    }
    if (pthis->actor.bgCheckFlags & 8) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.wallYaw, 2, 0xC00, 0x300);
    }
    if ((pthis->timer == 0) && (pthis->actor.xzDistToPlayer < 200.0f) &&
        (Player_GetMask(globalCtx) != PLAYER_MASK_SKULL)) {
        EnFirefly_SetupDiveAttack(pthis);
    }
}

// Fall to the ground after being hit
void EnFirefly_Fall(EnFirefly* pthis, GlobalContext* globalCtx) {
    if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        pthis->skelAnime.playSpeed = 0.0f;
    }
    pthis->actor.colorFilterTimer = 40;
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    if (pthis->actor.flags & ACTOR_FLAG_15) {
        pthis->actor.colorFilterTimer = 40;
    } else {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x6800, 0x200);
        pthis->actor.shape.rot.y = pthis->actor.shape.rot.y - 0x300;
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if ((pthis->actor.bgCheckFlags & 1) || (pthis->timer == 0)) {
            EnFirefly_SetupDie(pthis);
        }
    }
}

// Hit the ground or burn up, spawn drops
void EnFirefly_Die(EnFirefly* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.00034f);
    pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;
    if (pthis->timer == 0) {
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xE0);
        Actor_Kill(&pthis->actor);
    }
}

void EnFirefly_DiveAttack(EnFirefly* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f preyPos;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    Math_StepToF(&pthis->actor.speedXZ, 4.0f, 0.5f);
    if (pthis->actor.bgCheckFlags & 8) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.wallYaw, 2, 0xC00, 0x300);
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->targetPitch, 0x100);
    } else if (Actor_IsFacingPlayer(&pthis->actor, 0x2800)) {
        if (Animation_OnFrame(&pthis->skelAnime, 4.0f)) {
            pthis->skelAnime.playSpeed = 0.0f;
            pthis->skelAnime.curFrame = 4.0f;
        }
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xC00, 0x300);
        preyPos.x = player->actor.world.pos.x;
        preyPos.y = player->actor.world.pos.y + 20.0f;
        preyPos.z = player->actor.world.pos.z;
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, Actor_WorldPitchTowardPoint(&pthis->actor, &preyPos) + 0x1554, 2,
                           0x400, 0x100);
    } else {
        pthis->skelAnime.playSpeed = 1.5f;
        if (pthis->actor.xzDistToPlayer > 80.0f) {
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xC00, 0x300);
        }
        if (pthis->actor.bgCheckFlags & 1) {
            pthis->targetPitch = 0x954;
        }
        if ((pthis->actor.bgCheckFlags & 0x10) || (pthis->maxAltitude < pthis->actor.world.pos.y)) {
            pthis->targetPitch = 0x2154;
        } else {
            pthis->targetPitch = 0x954;
        }
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->targetPitch, 0x100);
    }
    if ((pthis->timer == 0) || (Player_GetMask(globalCtx) == PLAYER_MASK_SKULL)) {
        EnFirefly_SetupFlyAway(pthis);
    }
}

// Knockback after hitting player
void EnFirefly_Rebound(EnFirefly* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x100);
    Math_StepToF(&pthis->actor.velocity.y, 0.0f, 0.4f);
    if (Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.15f)) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if (pthis->timer == 0) {
            EnFirefly_SetupFlyAway(pthis);
        }
    }
}

void EnFirefly_FlyAway(EnFirefly* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (((fabsf(pthis->actor.world.pos.y - pthis->maxAltitude) < 10.0f) &&
         (Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) < 20.0f)) ||
        (pthis->timer == 0)) {
        EnFirefly_SetupFlyIdle(pthis);
        return;
    }
    Math_StepToF(&pthis->actor.speedXZ, 3.0f, 0.3f);
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->targetPitch = 0x954;
    } else if ((pthis->actor.bgCheckFlags & 0x10) || (pthis->maxAltitude < pthis->actor.world.pos.y)) {
        pthis->targetPitch = 0x2154;
    } else {
        pthis->targetPitch = 0x954;
    }
    if (pthis->actor.bgCheckFlags & 8) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.wallYaw, 2, 0xC00, 0x300);
    } else {
        Math_ScaledStepToS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos),
                           0x300);
    }
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->targetPitch, 0x100);
}

void EnFirefly_Stunned(EnFirefly* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x1554, 0x100);
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        if (pthis->onFire) {
            pthis->auraType = KEESE_AURA_FIRE;
        } else if (pthis->actor.params == KEESE_ICE_FLY) {
            pthis->auraType = KEESE_AURA_ICE;
        }
        EnFirefly_SetupFlyIdle(pthis);
    }
}

void EnFirefly_FrozenFall(EnFirefly* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.bgCheckFlags & 1) || (pthis->actor.floorHeight == BGCHECK_Y_MIN)) {
        pthis->actor.colorFilterTimer = 0;
        EnFirefly_SetupDie(pthis);
    } else {
        pthis->actor.colorFilterTimer = 255;
    }
}

// When perching, sit on collision and flap at random intervals
void EnFirefly_Perch(EnFirefly* pthis, GlobalContext* globalCtx) {
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x100);

    if (pthis->timer != 0) {
        SkelAnime_Update(&pthis->skelAnime);
        if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
            pthis->timer--;
        }
    } else if (Rand_ZeroOne() < 0.02f) {
        pthis->timer = 1;
    }

    if (pthis->actor.xzDistToPlayer < 120.0f) {
        EnFirefly_SetupDisturbDiveAttack(pthis);
    }
}

void EnFirefly_DisturbDiveAttack(EnFirefly* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f preyPos;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer < 40) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0xAAC, 0x100);
    } else {
        preyPos.x = player->actor.world.pos.x;
        preyPos.y = player->actor.world.pos.y + 20.0f;
        preyPos.z = player->actor.world.pos.z;
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, Actor_WorldPitchTowardPoint(&pthis->actor, &preyPos) + 0x1554,
                           0x100);
        Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x300);
    }

    if (pthis->timer == 0) {
        EnFirefly_SetupFlyIdle(pthis);
    }
}

void EnFirefly_Combust(EnFirefly* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i <= 2; i++) {
        EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &pthis->actor.world.pos, 40, 0, 0, i);
    }

    pthis->auraType = KEESE_AURA_NONE;
}

void EnFirefly_UpdateDamage(EnFirefly* pthis, GlobalContext* globalCtx) {
    u8 damageEffect;

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.elements[0].info, 1);

        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            }

            damageEffect = pthis->actor.colChkInfo.damageEffect;

            if (damageEffect == 2) { // Din's Fire
                if (pthis->actor.params == KEESE_ICE_FLY) {
                    pthis->actor.colChkInfo.health = 0;
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                    EnFirefly_Combust(pthis, globalCtx);
                    EnFirefly_SetupFall(pthis);
                } else if (!pthis->onFire) {
                    EnFirefly_Ignite(pthis);
                    if (pthis->actionFunc == EnFirefly_Perch) {
                        EnFirefly_SetupFlyIdle(pthis);
                    }
                }
            } else if (damageEffect == 3) { // Ice Arrows or Ice Magic
                if (pthis->actor.params == KEESE_ICE_FLY) {
                    EnFirefly_SetupFall(pthis);
                } else {
                    EnFirefly_SetupFrozenFall(pthis, globalCtx);
                }
            } else if (damageEffect == 1) { // Deku Nuts
                if (pthis->actionFunc != EnFirefly_Stunned) {
                    EnFirefly_SetupStunned(pthis);
                }
            } else { // Fire Arrows
                if ((damageEffect == 0xF) && (pthis->actor.params == KEESE_ICE_FLY)) {
                    EnFirefly_Combust(pthis, globalCtx);
                }
                EnFirefly_SetupFall(pthis);
            }
        }
    }
}

void EnFirefly_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnFirefly* pthis = (EnFirefly*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FFLY_ATTACK);
        if (pthis->onFire) {
            EnFirefly_Extinguish(pthis);
        }
        if (pthis->actionFunc != EnFirefly_DisturbDiveAttack) {
            EnFirefly_SetupRebound(pthis);
        }
    }

    EnFirefly_UpdateDamage(pthis, globalCtx);

    pthis->actionFunc(pthis, globalCtx);

    if (!(pthis->actor.flags & ACTOR_FLAG_15)) {
        if ((pthis->actor.colChkInfo.health == 0) || (pthis->actionFunc == EnFirefly_Stunned)) {
            Actor_MoveForward(&pthis->actor);
        } else {
            if (pthis->actionFunc != EnFirefly_Rebound) {
                pthis->actor.world.rot.x = 0x1554 - pthis->actor.shape.rot.x;
            }
            func_8002D97C(&pthis->actor);
        }
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 15.0f, 7);
    pthis->collider.elements[0].dim.worldSphere.center.x = pthis->actor.world.pos.x;
    pthis->collider.elements[0].dim.worldSphere.center.y = pthis->actor.world.pos.y + 10.0f;
    pthis->collider.elements[0].dim.worldSphere.center.z = pthis->actor.world.pos.z;

    if ((pthis->actionFunc == EnFirefly_DiveAttack) || (pthis->actionFunc == EnFirefly_DisturbDiveAttack)) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->actor.colChkInfo.health != 0) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        if (Animation_OnFrame(&pthis->skelAnime, 5.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FFLY_FLY);
        }
    }

    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    pthis->actor.focus.pos.x =
        (10.0f * Math_SinS(pthis->actor.shape.rot.x) * Math_SinS(pthis->actor.shape.rot.y)) + pthis->actor.world.pos.x;
    pthis->actor.focus.pos.y = (10.0f * Math_CosS(pthis->actor.shape.rot.x)) + pthis->actor.world.pos.y;
    pthis->actor.focus.pos.z =
        (10.0f * Math_SinS(pthis->actor.shape.rot.x) * Math_CosS(pthis->actor.shape.rot.y)) + pthis->actor.world.pos.z;
}

s32 EnFirefly_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx, Gfx** gfx) {
    EnFirefly* pthis = (EnFirefly*)thisx;

    if ((pthis->actor.draw == EnFirefly_DrawInvisible) && (globalCtx->actorCtx.unk_03 == 0)) {
        *dList = NULL;
    } else if (limbIndex == 1) {
        pos->y += 2300.0f;
    }
    return false;
}

void EnFirefly_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    Vec3f effPos;
    Vec3f* limbDest;
    Color_RGBA8* effPrimColor;
    Color_RGBA8* effEnvColor;
    MtxF mtx;
    s16 effScaleStep;
    s16 effLife;
    EnFirefly* pthis = (EnFirefly*)thisx;

    if (!pthis->onFire && (limbIndex == 27)) {
        gSPDisplayList((*gfx)++, gKeeseEyesDL);
    } else {
        if ((pthis->auraType == KEESE_AURA_FIRE) || (pthis->auraType == KEESE_AURA_ICE)) {
            if ((limbIndex == 15) || (limbIndex == 21)) {
                if (pthis->actionFunc != EnFirefly_Die) {
                    Matrix_Get(&mtx);
                    effPos.x = (Rand_ZeroOne() * 5.0f) + mtx.xw;
                    effPos.y = (Rand_ZeroOne() * 5.0f) + mtx.yw;
                    effPos.z = (Rand_ZeroOne() * 5.0f) + mtx.zw;
                    effScaleStep = -40;
                    effLife = 3;
                } else {
                    if (limbIndex == 15) {
                        effPos.x = (Math_SinS(9100 * pthis->timer) * pthis->timer) + pthis->actor.world.pos.x;
                        effPos.z = (Math_CosS(9100 * pthis->timer) * pthis->timer) + pthis->actor.world.pos.z;
                    } else {
                        effPos.x = pthis->actor.world.pos.x - (Math_SinS(9100 * pthis->timer) * pthis->timer);
                        effPos.z = pthis->actor.world.pos.z - (Math_CosS(9100 * pthis->timer) * pthis->timer);
                    }

                    effPos.y = pthis->actor.world.pos.y + ((15 - pthis->timer) * 1.5f);
                    effScaleStep = -5;
                    effLife = 10;
                }

                if (pthis->auraType == KEESE_AURA_FIRE) {
                    effPrimColor = &fireAuraPrimColor_75;
                    effEnvColor = &fireAuraEnvColor_75;
                } else {
                    effPrimColor = &iceAuraPrimColor_75;
                    effEnvColor = &iceAuraEnvColor_75;
                }

                func_8002843C(globalCtx, &effPos, &effVelocity_75, &effAccel_75, effPrimColor, effEnvColor, 250, effScaleStep,
                              effLife);
            }
        }
    }
    if ((limbIndex == 15) || (limbIndex == 21) || (limbIndex == 10)) {
        if (limbIndex == 15) {
            limbDest = &pthis->bodyPartsPos[0];
        } else if (limbIndex == 21) {
            limbDest = &pthis->bodyPartsPos[1];
        } else {
            limbDest = &pthis->bodyPartsPos[2];
        }

        Matrix_MultVec3f(&limbSrc_75, limbDest);
        limbDest->y -= 5.0f;
    }
}

void EnFirefly_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* pthis = (EnFirefly*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 1733);
    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->onFire) {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
    } else {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    }

    POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                   EnFirefly_OverrideLimbDraw, EnFirefly_PostLimbDraw, &pthis->actor, POLY_OPA_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 1763);
}

void EnFirefly_DrawInvisible(Actor* thisx, GlobalContext* globalCtx) {
    EnFirefly* pthis = (EnFirefly*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 1775);
    func_80093D84(globalCtx->state.gfxCtx);

    if (pthis->onFire) {
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 0);
    } else {
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 255);
    }

    POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                   EnFirefly_OverrideLimbDraw, EnFirefly_PostLimbDraw, pthis, POLY_XLU_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_firefly.c", 1805);
}

void EnFirefly_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    fireAuraPrimColor_75 = { 255, 255, 100, 255 };

    fireAuraEnvColor_75 = { 255, 50, 0, 0 };

    iceAuraPrimColor_75 = { 100, 200, 255, 255 };

    iceAuraEnvColor_75 = { 0, 0, 255, 0 };

    effVelocity_75 = { 0.0f, 0.5f, 0.0f };

    effAccel_75 = { 0.0f, 0.5f, 0.0f };

    limbSrc_75 = { 0.0f, 0.0f, 0.0f };

    En_Firefly_InitVars = {
        ACTOR_EN_FIREFLY,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_FIREFLY,
        sizeof(EnFirefly),
        (ActorFunc)EnFirefly_Init,
        (ActorFunc)EnFirefly_Destroy,
        (ActorFunc)EnFirefly_Update,
        (ActorFunc)EnFirefly_Draw,
        (ActorFunc)EnFirefly_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_HIT3,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

    sColChkInfoInit = { 1, 10, 10, 30 };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x1),
        /* Deku stick    */ DMG_ENTRY(2, 0x0),
        /* Slingshot     */ DMG_ENTRY(1, 0x0),
        /* Explosive     */ DMG_ENTRY(2, 0x0),
        /* Boomerang     */ DMG_ENTRY(1, 0x0),
        /* Normal arrow  */ DMG_ENTRY(2, 0x0),
        /* Hammer swing  */ DMG_ENTRY(2, 0x0),
        /* Hookshot      */ DMG_ENTRY(2, 0x0),
        /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
        /* Master sword  */ DMG_ENTRY(2, 0x0),
        /* Giant's Knife */ DMG_ENTRY(4, 0x0),
        /* Fire arrow    */ DMG_ENTRY(2, 0xF),
        /* Ice arrow     */ DMG_ENTRY(4, 0x3),
        /* Light arrow   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x2),
        /* Ice magic     */ DMG_ENTRY(4, 0x3),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
        /* Giant spin    */ DMG_ENTRY(4, 0x0),
        /* Master spin   */ DMG_ENTRY(2, 0x0),
        /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
        /* Giant jump    */ DMG_ENTRY(8, 0x0),
        /* Master jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 1     */ DMG_ENTRY(0, 0x0),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

}

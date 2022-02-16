#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_CROW_Z_EN_CROW_C
#include "actor_common.h"
#include "z_en_crow.h"
#include "objects/object_crow/object_crow.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
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

void EnCrow_Init(Actor* thisx, GlobalContext* globalCtx);
void EnCrow_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnCrow_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnCrow_Update(Actor* thisx, GlobalContext* globalCtx);
void EnCrow_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnCrow_SetupFlyIdle(EnCrow* pthis);
void EnCrow_FlyIdle(EnCrow* pthis, GlobalContext* globalCtx);
void EnCrow_Respawn(EnCrow* pthis, GlobalContext* globalCtx);
void EnCrow_DiveAttack(EnCrow* pthis, GlobalContext* globalCtx);
void EnCrow_Die(EnCrow* pthis, GlobalContext* globalCtx);
void EnCrow_TurnAway(EnCrow* pthis, GlobalContext* globalCtx);
void EnCrow_Damaged(EnCrow* pthis, GlobalContext* globalCtx);

static Vec3f sZeroVecAccel = { 0.0f, 0.0f, 0.0f };

ActorInit En_Crow_InitVars = {
    ACTOR_EN_CROW,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_CROW,
    sizeof(EnCrow),
    (ActorFunc)EnCrow_Init,
    (ActorFunc)EnCrow_Destroy,
    (ActorFunc)EnCrow_Update,
    (ActorFunc)EnCrow_Draw,
    (ActorFunc)EnCrow_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 0, 0 }, 20 }, 100 },
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

static CollisionCheckInfoInit sColChkInfoInit = { 1, 15, 30, 30 };

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
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(2, 0x3),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
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

static u32 sDeathCount = 0;

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 3000, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x58, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -200, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_STOP),
};

static Vec3f sHeadVec = { 2500.0f, 0.0f, 0.0f };

void EnCrow_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnCrow* pthis = (EnCrow*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGuaySkel, &gGuayFlyAnim, pthis->jointTable, pthis->morphTable, 9);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    pthis->collider.elements[0].dim.worldSphere.radius = sJntSphInit.elements[0].dim.modelSphere.radius;
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    ActorShape_Init(&pthis->actor.shape, 2000.0f, ActorShadow_DrawCircle, 20.0f);
    sDeathCount = 0;
    EnCrow_SetupFlyIdle(pthis);
}

void EnCrow_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnCrow* pthis = (EnCrow*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

// Setup Action functions

void EnCrow_SetupFlyIdle(EnCrow* pthis) {
    pthis->timer = 100;
    pthis->collider.base.acFlags |= AC_ON;
    pthis->actionFunc = EnCrow_FlyIdle;
    pthis->skelAnime.playSpeed = 1.0f;
}

void EnCrow_SetupDiveAttack(EnCrow* pthis) {
    pthis->timer = 300;
    pthis->actor.speedXZ = 4.0f;
    pthis->skelAnime.playSpeed = 2.0f;
    pthis->actionFunc = EnCrow_DiveAttack;
}

void EnCrow_SetupDamaged(EnCrow* pthis, GlobalContext* globalCtx) {
    s32 i;
    f32 scale;
    Vec3f iceParticlePos;

    pthis->actor.speedXZ *= Math_CosS(pthis->actor.world.rot.x);
    pthis->actor.velocity.y = 0.0f;
    Animation_Change(&pthis->skelAnime, &gGuayFlyAnim, 0.4f, 0.0f, 0.0f, ANIMMODE_LOOP_INTERP, -3.0f);
    scale = pthis->actor.scale.x * 100.0f;
    pthis->actor.world.pos.y += 20.0f * scale;
    pthis->actor.bgCheckFlags &= ~1;
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actor.targetArrowOffset = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KAICHO_DEAD);

    if (pthis->actor.colChkInfo.damageEffect == 3) { // Ice arrows
        Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 40);
        for (i = 0; i < 8; i++) {
            iceParticlePos.x = ((i & 1 ? 7.0f : -7.0f) * scale) + pthis->actor.world.pos.x;
            iceParticlePos.y = ((i & 2 ? 7.0f : -7.0f) * scale) + pthis->actor.world.pos.y;
            iceParticlePos.z = ((i & 4 ? 7.0f : -7.0f) * scale) + pthis->actor.world.pos.z;
            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &iceParticlePos, 150, 150, 150, 250, 235, 245, 255,
                                           ((Rand_ZeroOne() * 0.15f) + 0.85f) * scale);
        }
    } else if (pthis->actor.colChkInfo.damageEffect == 2) { // Fire arrows and Din's Fire
        Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 40);

        for (i = 0; i < 4; i++) {
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &pthis->actor.world.pos, 50.0f * scale, 0, 0, i);
        }
    } else {
        Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 40);
    }

    if (pthis->actor.flags & ACTOR_FLAG_15) {
        pthis->actor.speedXZ = 0.0f;
    }

    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.flags |= ACTOR_FLAG_4;

    pthis->actionFunc = EnCrow_Damaged;
}

void EnCrow_SetupDie(EnCrow* pthis) {
    pthis->actor.colorFilterTimer = 0;
    pthis->actionFunc = EnCrow_Die;
}

void EnCrow_SetupTurnAway(EnCrow* pthis) {
    pthis->timer = 100;
    pthis->actor.speedXZ = 3.5f;
    pthis->aimRotX = -0x1000;
    pthis->aimRotY = pthis->actor.yawTowardsPlayer + 0x8000;
    pthis->skelAnime.playSpeed = 2.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 255, 0, 5);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actionFunc = EnCrow_TurnAway;
}

void EnCrow_SetupRespawn(EnCrow* pthis) {
    if (sDeathCount == 10) {
        pthis->actor.params = 1;
        sDeathCount = 0;
        pthis->collider.elements[0].dim.worldSphere.radius =
            sJntSphInit.elements[0].dim.modelSphere.radius * 0.03f * 100.0f;
    } else {
        pthis->actor.params = 0;
        pthis->collider.elements[0].dim.worldSphere.radius = sJntSphInit.elements[0].dim.modelSphere.radius;
    }

    Animation_PlayLoop(&pthis->skelAnime, &gGuayFlyAnim);
    Math_Vec3f_Copy(&pthis->actor.world.pos, &pthis->actor.home.pos);
    pthis->actor.shape.rot.x = 0;
    pthis->actor.shape.rot.z = 0;
    pthis->timer = 300;
    pthis->actor.shape.yOffset = 2000;
    pthis->actor.targetArrowOffset = 2000.0f;
    pthis->actor.draw = NULL;
    pthis->actionFunc = EnCrow_Respawn;
}

// Action functions

void EnCrow_FlyIdle(EnCrow* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 skelanimeUpdated;
    s16 var;

    SkelAnime_Update(&pthis->skelAnime);
    skelanimeUpdated = Animation_OnFrame(&pthis->skelAnime, 0.0f);
    pthis->actor.speedXZ = (Rand_ZeroOne() * 1.5f) + 3.0f;

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->aimRotY = pthis->actor.wallYaw;
    } else if (Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) > 300.0f) {
        pthis->aimRotY = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
    }

    if ((Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->aimRotY, 5, 0x300, 0x10) == 0) && skelanimeUpdated &&
        (Rand_ZeroOne() < 0.1f)) {
        var = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos) - pthis->actor.shape.rot.y;
        if (var > 0) {
            pthis->aimRotY += 0x1000 + (0x1000 * Rand_ZeroOne());
        } else {
            pthis->aimRotY -= 0x1000 + (0x1000 * Rand_ZeroOne());
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KAICHO_CRY);
    }

    if (pthis->actor.yDistToWater > -40.0f) {
        pthis->aimRotX = -0x1000;
    } else if (pthis->actor.world.pos.y < (pthis->actor.home.pos.y - 50.0f)) {
        pthis->aimRotX = -0x800 - (Rand_ZeroOne() * 0x800);
    } else if (pthis->actor.world.pos.y > (pthis->actor.home.pos.y + 50.0f)) {
        pthis->aimRotX = 0x800 + (Rand_ZeroOne() * 0x800);
    }

    if ((Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->aimRotX, 10, 0x100, 8) == 0) && (skelanimeUpdated) &&
        (Rand_ZeroOne() < 0.1f)) {
        if (pthis->actor.home.pos.y < pthis->actor.world.pos.y) {
            pthis->aimRotX -= (0x400 * Rand_ZeroOne()) + 0x400;
        } else {
            pthis->aimRotX += (0x400 * Rand_ZeroOne()) + 0x400;
        }
        pthis->aimRotX = CLAMP(pthis->aimRotX, -0x1000, 0x1000);
    }

    if (pthis->actor.bgCheckFlags & 1) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x100, 0x400);
    }

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if ((pthis->timer == 0) && (pthis->actor.xzDistToPlayer < 300.0f) && !(player->stateFlags1 & 0x00800000) &&
        (pthis->actor.yDistToWater < -40.0f) && (Player_GetMask(globalCtx) != PLAYER_MASK_SKULL)) {
        EnCrow_SetupDiveAttack(pthis);
    }
}

void EnCrow_DiveAttack(EnCrow* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 facingPlayer;
    Vec3f pos;
    s16 target;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    facingPlayer = Actor_IsFacingPlayer(&pthis->actor, 0x2800);

    if (facingPlayer) {
        pos.x = player->actor.world.pos.x;
        pos.y = player->actor.world.pos.y + 20.0f;
        pos.z = player->actor.world.pos.z;
        target = Actor_WorldPitchTowardPoint(&pthis->actor, &pos);
        if (target > 0x3000) {
            target = 0x3000;
        }
        Math_ApproachS(&pthis->actor.shape.rot.x, target, 2, 0x400);
    } else {
        Math_ApproachS(&pthis->actor.shape.rot.x, -0x1000, 2, 0x100);
    }

    if (facingPlayer || (pthis->actor.xzDistToPlayer > 80.0f)) {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 4, 0xC00);
    }

    if ((pthis->timer == 0) || (Player_GetMask(globalCtx) == PLAYER_MASK_SKULL) ||
        (pthis->collider.base.atFlags & AT_HIT) || (pthis->actor.bgCheckFlags & 9) ||
        (player->stateFlags1 & 0x00800000) || (pthis->actor.yDistToWater > -40.0f)) {
        if (pthis->collider.base.atFlags & AT_HIT) {
            pthis->collider.base.atFlags &= ~AT_HIT;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KAICHO_ATTACK);
        }

        EnCrow_SetupFlyIdle(pthis);
    }
}

void EnCrow_Damaged(EnCrow* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    pthis->actor.colorFilterTimer = 40;

    if (!(pthis->actor.flags & ACTOR_FLAG_15)) {
        if (pthis->actor.colorFilterParams & 0x4000) {
            Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x4000, 0x200);
            pthis->actor.shape.rot.z += 0x1780;
        }
        if ((pthis->actor.bgCheckFlags & 1) || (pthis->actor.floorHeight == BGCHECK_Y_MIN)) {
            EffectSsDeadDb_Spawn(globalCtx, &pthis->actor.world.pos, &sZeroVecAccel, &sZeroVecAccel,
                                 pthis->actor.scale.x * 10000.0f, 0, 255, 255, 255, 255, 255, 0, 0, 1, 9, 1);
            EnCrow_SetupDie(pthis);
        }
    }
}

void EnCrow_Die(EnCrow* pthis, GlobalContext* globalCtx) {
    f32 step;

    if (pthis->actor.params != 0) {
        step = 0.006f;
    } else {
        step = 0.002f;
    }

    if (Math_StepToF(&pthis->actor.scale.x, 0.0f, step)) {
        if (pthis->actor.params == 0) {
            sDeathCount++;
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0);
        } else {
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_RUPEE_RED);
        }
        EnCrow_SetupRespawn(pthis);
    }

    pthis->actor.scale.z = pthis->actor.scale.y = pthis->actor.scale.x;
}

void EnCrow_TurnAway(EnCrow* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->aimRotY = pthis->actor.wallYaw;
    } else {
        pthis->aimRotY = pthis->actor.yawTowardsPlayer + 0x8000;
    }

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->aimRotY, 3, 0xC00);
    Math_ApproachS(&pthis->actor.shape.rot.x, pthis->aimRotX, 5, 0x100);

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        EnCrow_SetupFlyIdle(pthis);
    }
}

void EnCrow_Respawn(EnCrow* pthis, GlobalContext* globalCtx) {
    f32 target;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        SkelAnime_Update(&pthis->skelAnime);
        pthis->actor.draw = EnCrow_Draw;
        if (pthis->actor.params != 0) {
            target = 0.03f;
        } else {
            target = 0.01f;
        }
        if (Math_StepToF(&pthis->actor.scale.x, target, target * 0.1f)) {
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->actor.flags &= ~ACTOR_FLAG_4;
            pthis->actor.colChkInfo.health = 1;
            EnCrow_SetupFlyIdle(pthis);
        }
        pthis->actor.scale.z = pthis->actor.scale.y = pthis->actor.scale.x;
    }
}

void EnCrow_UpdateDamage(EnCrow* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.elements[0].info, 1);
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (pthis->actor.colChkInfo.damageEffect == 1) { // Deku Nuts
                EnCrow_SetupTurnAway(pthis);
            } else {
                Actor_ApplyDamage(&pthis->actor);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                EnCrow_SetupDamaged(pthis, globalCtx);
            }
        }
    }
}

void EnCrow_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnCrow* pthis = (EnCrow*)thisx;
    f32 pad;
    f32 height;
    f32 scale;

    EnCrow_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    scale = pthis->actor.scale.x * 100.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.world.rot.x = -pthis->actor.shape.rot.x;

    if (pthis->actionFunc != EnCrow_Respawn) {
        if (pthis->actor.colChkInfo.health != 0) {
            height = 20.0f * scale;
            func_8002D97C(&pthis->actor);
        } else {
            height = 0.0f;
            Actor_MoveForward(&pthis->actor);
        }
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 12.0f * scale, 25.0f * scale, 50.0f * scale, 7);
    } else {
        height = 0.0f;
    }

    pthis->collider.elements[0].dim.worldSphere.center.x = pthis->actor.world.pos.x;
    pthis->collider.elements[0].dim.worldSphere.center.y = pthis->actor.world.pos.y + height;
    pthis->collider.elements[0].dim.worldSphere.center.z = pthis->actor.world.pos.z;

    if (pthis->actionFunc == EnCrow_DiveAttack) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->actionFunc != EnCrow_Respawn) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    Actor_SetFocus(&pthis->actor, height);

    if (pthis->actor.colChkInfo.health != 0 && Animation_OnFrame(&pthis->skelAnime, 3.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KAICHO_FLUTTER);
    }
}

s32 EnCrow_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnCrow* pthis = (EnCrow*)thisx;

    if (pthis->actor.colChkInfo.health != 0) {
        if (limbIndex == 7) {
            rot->y += 0xC00 * sinf(pthis->skelAnime.curFrame * (M_PI / 4));
        } else if (limbIndex == 8) {
            rot->y += 0x1400 * sinf((pthis->skelAnime.curFrame + 2.5f) * (M_PI / 4));
        }
    }
    return false;
}

void EnCrow_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnCrow* pthis = (EnCrow*)thisx;
    Vec3f* vec;

    if (limbIndex == 2) {
        Matrix_MultVec3f(&sHeadVec, &pthis->bodyPartsPos[0]);
        pthis->bodyPartsPos[0].y -= 20.0f;
    } else if ((limbIndex == 4) || (limbIndex == 6) || (limbIndex == 8)) {
        vec = &pthis->bodyPartsPos[(limbIndex >> 1) - 1];
        Matrix_MultVec3f(&sZeroVecAccel, vec);
        vec->y -= 20.0f;
    }
}

void EnCrow_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnCrow* pthis = (EnCrow*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnCrow_OverrideLimbDraw, EnCrow_PostLimbDraw, pthis);
}

void EnCrow_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sZeroVecAccel = { 0.0f, 0.0f, 0.0f };

    En_Crow_InitVars = {
        ACTOR_EN_CROW,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_CROW,
        sizeof(EnCrow),
        (ActorFunc)EnCrow_Init,
        (ActorFunc)EnCrow_Destroy,
        (ActorFunc)EnCrow_Update,
        (ActorFunc)EnCrow_Draw,
        (ActorFunc)EnCrow_Reset,
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

    sColChkInfoInit = { 1, 15, 30, 30 };

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
        /* Fire arrow    */ DMG_ENTRY(4, 0x2),
        /* Ice arrow     */ DMG_ENTRY(2, 0x3),
        /* Light arrow   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(4, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
        /* Fire magic    */ DMG_ENTRY(4, 0x2),
        /* Ice magic     */ DMG_ENTRY(0, 0x0),
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

    sDeathCount = 0;

    sHeadVec = { 2500.0f, 0.0f, 0.0f };

}

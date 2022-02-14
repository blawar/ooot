#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FZ_Z_EN_FZ_C
#include "actor_common.h"
#include "z_en_fz.h"
#include "objects/object_fz/object_fz.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_10)

void EnFz_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFz_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFz_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFz_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFz_UpdateTargetPos(EnFz* pthis, GlobalContext* globalCtx);

// Stationary Freezard
void EnFz_SetupBlowSmokeStationary(EnFz* pthis);
void EnFz_BlowSmokeStationary(EnFz* pthis, GlobalContext* globalCtx);

// Moving Freezard that can vanish and reappear
void EnFz_Wait(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupAppear(EnFz* pthis);
void EnFz_Appear(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupAimForMove(EnFz* pthis);
void EnFz_AimForMove(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupMoveTowardsPlayer(EnFz* pthis);
void EnFz_MoveTowardsPlayer(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupAimForFreeze(EnFz* pthis);
void EnFz_AimForFreeze(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupBlowSmoke(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_BlowSmoke(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupDisappear(EnFz* pthis);
void EnFz_Disappear(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_SetupWait(EnFz* pthis);

// Killed with fire source
void EnFz_SetupMelt(EnFz* pthis);
void EnFz_Melt(EnFz* pthis, GlobalContext* globalCtx);

// Death
void EnFz_SetupDespawn(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_Despawn(EnFz* pthis, GlobalContext* globalCtx);

// Ice Smoke Effects
void EnFz_SpawnIceSmokeNoFreeze(EnFz* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 xyScale);
void EnFz_SpawnIceSmokeFreeze(EnFz* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 xyScale, f32 xyScaleTarget,
                              s16 primAlpha, u8 isTimerMod8);
void EnFz_UpdateIceSmoke(EnFz* pthis, GlobalContext* globalCtx);
void EnFz_DrawIceSmoke(EnFz* pthis, GlobalContext* globalCtx);

ActorInit En_Fz_InitVars = {
    ACTOR_EN_FZ,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FZ,
    sizeof(EnFz),
    (ActorFunc)EnFz_Init,
    (ActorFunc)EnFz_Destroy,
    (ActorFunc)EnFz_Update,
    (ActorFunc)EnFz_Draw,
};

static ColliderCylinderInitType1 sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCE0FDB, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 30, 80, 0, { 0, 0, 0 } },
};

static ColliderCylinderInitType1 sCylinderInit2 = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0x0001F024, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 35, 80, 0, { 0, 0, 0 } },
};

static ColliderCylinderInitType1 sCylinderInit3 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x02, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 20, 30, -15, { 0, 0, 0 } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0xF),
    /* Slingshot     */ DMG_ENTRY(0, 0xF),
    /* Explosive     */ DMG_ENTRY(2, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0xF),
    /* Normal arrow  */ DMG_ENTRY(0, 0xF),
    /* Hammer swing  */ DMG_ENTRY(2, 0xF),
    /* Hookshot      */ DMG_ENTRY(2, 0xF),
    /* Kokiri sword  */ DMG_ENTRY(0, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(0, 0xF),
    /* Light arrow   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0xF),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0xF),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(0, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(0, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x3B, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

void EnFz_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFz* pthis = (EnFz*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    pthis->actor.colChkInfo.health = 6;

    Collider_InitCylinder(globalCtx, &pthis->collider1);
    Collider_SetCylinderType1(globalCtx, &pthis->collider1, &pthis->actor, &sCylinderInit1);

    Collider_InitCylinder(globalCtx, &pthis->collider2);
    Collider_SetCylinderType1(globalCtx, &pthis->collider2, &pthis->actor, &sCylinderInit2);

    Collider_InitCylinder(globalCtx, &pthis->collider3);
    Collider_SetCylinderType1(globalCtx, &pthis->collider3, &pthis->actor, &sCylinderInit3);

    Actor_SetScale(&pthis->actor, 0.008f);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->unusedTimer1 = 0;
    pthis->unusedCounter = 0;
    pthis->updateBgInfo = true;
    pthis->isMoving = false;
    pthis->isFreezing = false;
    pthis->isActive = true;
    pthis->isDespawning = false;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->posOrigin.y = pthis->actor.world.pos.y;
    pthis->iceSmokeFreezingSpawnHeight = pthis->actor.world.pos.y;
    pthis->posOrigin.x = pthis->actor.world.pos.x;
    pthis->posOrigin.z = pthis->actor.world.pos.z;
    pthis->unusedFloat = 135.0f;

    if (pthis->actor.params < 0) {
        pthis->envAlpha = 0;
        pthis->actor.scale.y = 0.0f;
        EnFz_SetupWait(pthis);
    } else {
        pthis->envAlpha = 255;
        EnFz_SetupBlowSmokeStationary(pthis);
    }

    EnFz_UpdateTargetPos(pthis, globalCtx);
}

void EnFz_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFz* pthis = (EnFz*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider1);
    Collider_DestroyCylinder(globalCtx, &pthis->collider2);
    Collider_DestroyCylinder(globalCtx, &pthis->collider3);
}

void EnFz_UpdateTargetPos(EnFz* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f hitPos;
    Vec3f vec1;
    s32 bgId;
    CollisionPoly* hitPoly;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 20.0f;
    pos.z = pthis->actor.world.pos.z;

    Matrix_Translate(pos.x, pos.y, pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, MTXMODE_APPLY);
    vec1.x = vec1.y = 0.0f;
    vec1.z = 220.0f;
    Matrix_MultVec3f(&vec1, &pthis->wallHitPos);

    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pos, &pthis->wallHitPos, &hitPos, &hitPoly, true, false, false,
                                true, &bgId)) {
        Math_Vec3f_Copy(&pthis->wallHitPos, &hitPos);
    }

    pos.x = pthis->actor.world.pos.x - pthis->wallHitPos.x;
    pos.z = pthis->actor.world.pos.z - pthis->wallHitPos.z;

    pthis->distToTargetSq = SQ(pos.x) + SQ(pos.z);
}

s32 EnFz_ReachedTarget(EnFz* pthis, Vec3f* vec) {
    if (pthis->distToTargetSq <= (SQ(pthis->actor.world.pos.x - vec->x) + SQ(pthis->actor.world.pos.z - vec->z))) {
        return true;
    } else {
        return false;
    }
}

void EnFz_Damaged(EnFz* pthis, GlobalContext* globalCtx, Vec3f* vec, s32 numEffects, f32 unkFloat) {
    s32 i;
    Vec3f pos;
    Vec3f vel;
    Vec3f accel;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    f32 scale;
    s32 life;

    primColor.r = 155;
    primColor.g = 255;
    primColor.b = 255;
    primColor.a = 255;
    envColor.r = 200;
    envColor.g = 200;
    envColor.b = 200;
    accel.x = accel.z = 0.0f;
    accel.y = -1.0f;

    for (i = 0; i < numEffects; i++) {
        scale = Rand_CenteredFloat(0.3f) + 0.6f;
        life = (s32)Rand_CenteredFloat(5.0f) + 12;
        pos.x = Rand_CenteredFloat(unkFloat) + vec->x;
        pos.y = Rand_ZeroFloat(unkFloat) + vec->y;
        pos.z = Rand_CenteredFloat(unkFloat) + vec->z;
        vel.x = Rand_CenteredFloat(10.0f);
        vel.y = Rand_ZeroFloat(10.0f) + 2.0f;
        vel.z = Rand_CenteredFloat(10.0f);
        EffectSsEnIce_Spawn(globalCtx, &pos, scale, &vel, &accel, &primColor, &envColor, life);
    }

    CollisionCheck_SpawnShieldParticles(globalCtx, vec);
}

void EnFz_SpawnIceSmokeHiddenState(EnFz* pthis) {
}

// Fully grown
void EnFz_SpawnIceSmokeGrowingState(EnFz* pthis) {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;

    if ((pthis->counter % 16) == 0) {
        pos.x = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.x;
        pos.y = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.y + 30.0f;
        pos.z = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.z;
        accel.x = accel.z = 0.0f;
        accel.y = 0.1f;
        velocity.x = velocity.y = velocity.z = 0.0f;
        EnFz_SpawnIceSmokeNoFreeze(pthis, &pos, &velocity, &accel, Rand_ZeroFloat(7.5f) + 15.0f);
    }
}

// (2) Growing or Shrinking to/from hiding or (3) melting from fire
void EnFz_SpawnIceSmokeActiveState(EnFz* pthis) {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;

    if ((pthis->counter % 4) == 0) {
        pos.x = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.x;
        pos.y = pthis->iceSmokeFreezingSpawnHeight;
        pos.z = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.z;
        accel.x = accel.z = 0.0f;
        accel.y = 0.1f;
        velocity.x = velocity.y = velocity.z = 0.0f;
        EnFz_SpawnIceSmokeNoFreeze(pthis, &pos, &velocity, &accel, Rand_ZeroFloat(7.5f) + 15.0f);
    }
}

void EnFz_ApplyDamage(EnFz* pthis, GlobalContext* globalCtx) {
    Vec3f vec;

    if (pthis->isMoving &&
        ((pthis->actor.bgCheckFlags & 8) ||
         (Actor_TestFloorInDirection(&pthis->actor, globalCtx, 60.0f, pthis->actor.world.rot.y) == 0))) {
        pthis->actor.bgCheckFlags &= ~8;
        pthis->isMoving = false;
        pthis->speedXZ = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }

    if (pthis->isFreezing) {
        if ((pthis->actor.params < 0) && (pthis->collider1.base.atFlags & 2)) {
            pthis->isMoving = false;
            pthis->collider1.base.acFlags &= ~2;
            pthis->actor.speedXZ = pthis->speedXZ = 0.0f;
            pthis->timer = 10;
            EnFz_SetupDisappear(pthis);
        } else if (pthis->collider2.base.acFlags & 0x80) {
            pthis->collider2.base.acFlags &= ~0x80;
            pthis->collider1.base.acFlags &= ~2;
        } else if (pthis->collider1.base.acFlags & 2) {
            pthis->collider1.base.acFlags &= ~2;
            if (pthis->actor.colChkInfo.damageEffect != 2) {
                if (pthis->actor.colChkInfo.damageEffect == 0xF) {
                    Actor_ApplyDamage(&pthis->actor);
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 8);
                    if (pthis->actor.colChkInfo.health) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FREEZAD_DAMAGE);
                        vec.x = pthis->actor.world.pos.x;
                        vec.y = pthis->actor.world.pos.y;
                        vec.z = pthis->actor.world.pos.z;
                        EnFz_Damaged(pthis, globalCtx, &vec, 10, 0.0f);
                        pthis->unusedCounter++;
                    } else {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FREEZAD_DEAD);
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_ICE_BROKEN);
                        vec.x = pthis->actor.world.pos.x;
                        vec.y = pthis->actor.world.pos.y;
                        vec.z = pthis->actor.world.pos.z;
                        EnFz_Damaged(pthis, globalCtx, &vec, 30, 10.0f);
                        EnFz_SetupDespawn(pthis, globalCtx);
                    }
                }
            } else {
                Actor_ApplyDamage(&pthis->actor);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0x2000, 8);
                if (pthis->actor.colChkInfo.health == 0) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FREEZAD_DEAD);
                    EnFz_SetupMelt(pthis);
                } else {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FREEZAD_DAMAGE);
                }
            }
        }
    }
}

void EnFz_SetYawTowardsPlayer(EnFz* pthis) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 10, 2000, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
}

void EnFz_SetupDisappear(EnFz* pthis) {
    pthis->state = 2;
    pthis->isFreezing = false;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnFz_Disappear;
}

void EnFz_Disappear(EnFz* pthis, GlobalContext* globalCtx) {
    pthis->envAlpha -= 16;

    if (pthis->envAlpha > 255) {
        pthis->envAlpha = 0;
    }

    if (Math_SmoothStepToF(&pthis->actor.scale.y, 0.0f, 1.0f, 0.0005f, 0) == 0.0f) {
        EnFz_SetupWait(pthis);
    }
}

void EnFz_SetupWait(EnFz* pthis) {
    pthis->state = 0;
    pthis->unusedNum2 = 0;
    pthis->unusedNum1 = 0;
    pthis->timer = 100;
    pthis->actionFunc = EnFz_Wait;
    pthis->actor.world.pos.x = pthis->posOrigin.x;
    pthis->actor.world.pos.y = pthis->posOrigin.y;
    pthis->actor.world.pos.z = pthis->posOrigin.z;
}

void EnFz_Wait(EnFz* pthis, GlobalContext* globalCtx) {
    if ((pthis->timer == 0) && (pthis->actor.xzDistToPlayer < 400.0f)) {
        EnFz_SetupAppear(pthis);
    }
}

void EnFz_SetupAppear(EnFz* pthis) {
    pthis->state = 2;
    pthis->timer = 20;
    pthis->unusedNum2 = 4000;
    pthis->actionFunc = EnFz_Appear;
}

void EnFz_Appear(EnFz* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        pthis->envAlpha += 8;
        if (pthis->envAlpha > 255) {
            pthis->envAlpha = 255;
        }

        if (Math_SmoothStepToF(&pthis->actor.scale.y, 0.008f, 1.0f, 0.0005f, 0.0f) == 0.0f) {
            EnFz_SetupAimForMove(pthis);
        }
    }
}

void EnFz_SetupAimForMove(EnFz* pthis) {
    pthis->state = 1;
    pthis->timer = 40;
    pthis->updateBgInfo = true;
    pthis->isFreezing = true;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = EnFz_AimForMove;
    pthis->actor.gravity = -1.0f;
}

void EnFz_AimForMove(EnFz* pthis, GlobalContext* globalCtx) {
    EnFz_SetYawTowardsPlayer(pthis);

    if (pthis->timer == 0) {
        EnFz_SetupMoveTowardsPlayer(pthis);
    }
}

void EnFz_SetupMoveTowardsPlayer(EnFz* pthis) {
    pthis->state = 1;
    pthis->isMoving = true;
    pthis->timer = 100;
    pthis->actionFunc = EnFz_MoveTowardsPlayer;
    pthis->speedXZ = 4.0f;
}

void EnFz_MoveTowardsPlayer(EnFz* pthis, GlobalContext* globalCtx) {
    if ((pthis->timer == 0) || !pthis->isMoving) {
        EnFz_SetupAimForFreeze(pthis);
    }
}

void EnFz_SetupAimForFreeze(EnFz* pthis) {
    pthis->state = 1;
    pthis->timer = 40;
    pthis->actionFunc = EnFz_AimForFreeze;
    pthis->speedXZ = 0.0f;
    pthis->actor.speedXZ = 0.0f;
}

void EnFz_AimForFreeze(EnFz* pthis, GlobalContext* globalCtx) {
    EnFz_SetYawTowardsPlayer(pthis);

    if (pthis->timer == 0) {
        EnFz_SetupBlowSmoke(pthis, globalCtx);
    }
}

void EnFz_SetupBlowSmoke(EnFz* pthis, GlobalContext* globalCtx) {
    pthis->state = 1;
    pthis->timer = 80;
    pthis->actionFunc = EnFz_BlowSmoke;
    EnFz_UpdateTargetPos(pthis, globalCtx);
}

void EnFz_BlowSmoke(EnFz* pthis, GlobalContext* globalCtx) {
    Vec3f vec1;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    u8 isTimerMod8;
    s16 primAlpha;

    if (pthis->timer == 0) {
        EnFz_SetupDisappear(pthis);
    } else if (pthis->timer >= 11) {
        isTimerMod8 = false;
        primAlpha = 150;
        func_8002F974(&pthis->actor, NA_SE_EN_FREEZAD_BREATH - SFX_FLAG);

        if ((pthis->timer - 10) < 16) { // t < 26
            primAlpha = (pthis->timer * 10) - 100;
        }

        accel.x = accel.z = 0.0f;
        accel.y = 0.6f;

        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + 20.0f;
        pos.z = pthis->actor.world.pos.z;

        Matrix_RotateY((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_NEW);

        vec1.x = 0.0f;
        vec1.y = -2.0f;
        vec1.z = 20.0f; // xz velocity

        Matrix_MultVec3f(&vec1, &velocity);

        if ((pthis->timer % 8) == 0) {
            isTimerMod8 = true;
        }

        EnFz_SpawnIceSmokeFreeze(pthis, &pos, &velocity, &accel, 2.0f, 25.0f, primAlpha, isTimerMod8);

        pos.x += (velocity.x * 0.5f);
        pos.y += (velocity.y * 0.5f);
        pos.z += (velocity.z * 0.5f);

        EnFz_SpawnIceSmokeFreeze(pthis, &pos, &velocity, &accel, 2.0f, 25.0f, primAlpha, false);
    }
}

void EnFz_SetupDespawn(EnFz* pthis, GlobalContext* globalCtx) {
    pthis->state = 0;
    pthis->updateBgInfo = true;
    pthis->isFreezing = false;
    pthis->isDespawning = true;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->isActive = false;
    pthis->timer = 60;
    pthis->speedXZ = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 0.0f;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x60);
    pthis->actionFunc = EnFz_Despawn;
}

void EnFz_Despawn(EnFz* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnFz_SetupMelt(EnFz* pthis) {
    pthis->state = 3;
    pthis->isFreezing = false;
    pthis->isDespawning = true;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnFz_Melt;
    pthis->actor.speedXZ = 0.0f;
    pthis->speedXZ = 0.0f;
}

void EnFz_Melt(EnFz* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.scale.y, 0.0006f, 0.0002f);

    if (pthis->actor.scale.y < 0.006f) {
        pthis->actor.scale.x += 0.0004f;
        pthis->actor.scale.z += 0.0004f;
    }

    if (pthis->actor.scale.y < 0.004f) {
        pthis->envAlpha -= 8;
        if (pthis->envAlpha > 255) {
            pthis->envAlpha = 0;
        }
    }

    if (pthis->envAlpha == 0) {
        EnFz_SetupDespawn(pthis, globalCtx);
    }
}

void EnFz_SetupBlowSmokeStationary(EnFz* pthis) {
    pthis->state = 1;
    pthis->timer = 40;
    pthis->updateBgInfo = true;
    pthis->isFreezing = true;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = EnFz_BlowSmokeStationary;
    pthis->actor.gravity = -1.0f;
}

void EnFz_BlowSmokeStationary(EnFz* pthis, GlobalContext* globalCtx) {
    Vec3f vec1;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    u8 isTimerMod8;
    s16 primAlpha;

    if (pthis->counter & 0xC0) {
        EnFz_SetYawTowardsPlayer(pthis);
        EnFz_UpdateTargetPos(pthis, globalCtx);
    } else {
        isTimerMod8 = false;
        primAlpha = 150;
        func_8002F974(&pthis->actor, NA_SE_EN_FREEZAD_BREATH - SFX_FLAG);

        if ((pthis->counter & 0x3F) >= 48) {
            primAlpha = 630 - ((pthis->counter & 0x3F) * 10);
        }

        accel.x = accel.z = 0.0f;
        accel.y = 0.6f;

        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + 20.0f;
        pos.z = pthis->actor.world.pos.z;

        Matrix_RotateY((pthis->actor.shape.rot.y / (f32)0x8000) * M_PI, MTXMODE_NEW);

        vec1.x = 0.0f;
        vec1.y = -2.0f;
        vec1.z = 20.0f;

        Matrix_MultVec3f(&vec1, &velocity);

        if ((pthis->counter % 8) == 0) {
            isTimerMod8 = true;
        }

        EnFz_SpawnIceSmokeFreeze(pthis, &pos, &velocity, &accel, 2.0f, 25.0f, primAlpha, isTimerMod8);

        pos.x += (velocity.x * 0.5f);
        pos.y += (velocity.y * 0.5f);
        pos.z += (velocity.z * 0.5f);

        EnFz_SpawnIceSmokeFreeze(pthis, &pos, &velocity, &accel, 2.0f, 25.0f, primAlpha, false);
    }
}

static EnFzSpawnIceSmokeFunc iceSmokeSpawnFuncs[] = {
    EnFz_SpawnIceSmokeHiddenState,
    EnFz_SpawnIceSmokeGrowingState,
    EnFz_SpawnIceSmokeActiveState,
    EnFz_SpawnIceSmokeActiveState,
};

void EnFz_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFz* pthis = (EnFz*)thisx;
    s32 pad;

    pthis->counter++;

    if (pthis->unusedTimer1 != 0) {
        pthis->unusedTimer1--;
    }

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->unusedTimer2 != 0) {
        pthis->unusedTimer2--;
    }

    Actor_SetFocus(&pthis->actor, 50.0f);
    EnFz_ApplyDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->isDespawning == false) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider1);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider2);
        if (pthis->isFreezing) {
            if (pthis->actor.colorFilterTimer == 0) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
            }
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        }
    }

    Math_StepToF(&pthis->actor.speedXZ, pthis->speedXZ, 0.2f);
    Actor_MoveForward(&pthis->actor);

    if (pthis->updateBgInfo) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 20.0f, 5);
    }

    iceSmokeSpawnFuncs[pthis->state](pthis);
    EnFz_UpdateIceSmoke(pthis, globalCtx);
}

void EnFz_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* displayLists[] = {
        gFreezardIntactDL,              // Body fully intact           (5 or 6 health)
        gFreezardTopRightHornChippedDL, // Top right horn chipped off  (from Freezards perspective)   (3 or 4 health)
        gFreezardHeadChippedDL,         // Entire head chipped off     (1 or 2 health)
    };
    EnFz* pthis = (EnFz*)thisx;
    s32 pad;
    s32 index;

    index = (6 - pthis->actor.colChkInfo.health) >> 1;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fz.c", 1167);

    if (1) {}

    if (pthis->actor.colChkInfo.health == 0) {
        index = 2;
    }

    if (pthis->isActive) {
        func_8002ED80(&pthis->actor, globalCtx, 0);
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, globalCtx->state.frames & 0x7F, 32, 32, 1, 0,
                                    (globalCtx->state.frames * 2) & 0x7F, 32, 32));
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fz.c", 1183),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetCombineLERP(POLY_XLU_DISP++, TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0,
                          PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 128, 155, 255, 255, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 200, 200, pthis->envAlpha);
        gSPDisplayList(POLY_XLU_DISP++, displayLists[index]);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fz.c", 1200);
    EnFz_DrawIceSmoke(pthis, globalCtx);
}

void EnFz_SpawnIceSmokeNoFreeze(EnFz* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 xyScale) {
    EnFzEffectSsIceSmoke* iceSmoke = pthis->iceSmoke;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->iceSmoke); i++) {
        if (iceSmoke->type == 0) {
            iceSmoke->type = 1;
            iceSmoke->pos = *pos;
            iceSmoke->velocity = *velocity;
            iceSmoke->accel = *accel;
            iceSmoke->primAlphaState = 0;
            iceSmoke->xyScale = xyScale / 1000.0f;
            iceSmoke->primAlpha = 0;
            iceSmoke->timer = 0;
            break;
        }

        iceSmoke++;
    }
}

void EnFz_SpawnIceSmokeFreeze(EnFz* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 xyScale, f32 xyScaleTarget,
                              s16 primAlpha, u8 isTimerMod8) {
    EnFzEffectSsIceSmoke* iceSmoke = pthis->iceSmoke;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->iceSmoke); i++) {
        if (iceSmoke->type == 0) {
            iceSmoke->type = 2;
            iceSmoke->pos = *pos;
            iceSmoke->velocity = *velocity;
            iceSmoke->accel = *accel;
            iceSmoke->primAlphaState = 0;
            iceSmoke->xyScale = xyScale / 1000.0f;
            iceSmoke->xyScaleTarget = xyScaleTarget / 1000.0f;
            iceSmoke->primAlpha = primAlpha;
            iceSmoke->timer = 0;
            iceSmoke->isTimerMod8 = isTimerMod8;
            break;
        }

        iceSmoke++;
    }
}

void EnFz_UpdateIceSmoke(EnFz* pthis, GlobalContext* globalCtx) {
    EnFzEffectSsIceSmoke* iceSmoke = pthis->iceSmoke;
    s16 i;
    Vec3f pos;

    for (i = 0; i < ARRAY_COUNT(pthis->iceSmoke); i++) {
        if (iceSmoke->type) {
            iceSmoke->pos.x += iceSmoke->velocity.x;
            iceSmoke->pos.y += iceSmoke->velocity.y;
            iceSmoke->pos.z += iceSmoke->velocity.z;
            iceSmoke->timer++;
            iceSmoke->velocity.x += iceSmoke->accel.x;
            iceSmoke->velocity.y += iceSmoke->accel.y;
            iceSmoke->velocity.z += iceSmoke->accel.z;
            if (iceSmoke->type == 1) {
                if (iceSmoke->primAlphaState == 0) { // Becoming more opaque
                    iceSmoke->primAlpha += 10;
                    if (iceSmoke->primAlpha >= 100) {
                        iceSmoke->primAlphaState++;
                    }
                } else { // Becoming more transparent
                    iceSmoke->primAlpha -= 3;
                    if (iceSmoke->primAlpha <= 0) {
                        iceSmoke->primAlpha = 0;
                        iceSmoke->type = 0;
                    }
                }
            } else if (iceSmoke->type == 2) { // Freezing
                Math_ApproachF(&iceSmoke->xyScale, iceSmoke->xyScaleTarget, 0.1f, iceSmoke->xyScaleTarget / 10.0f);
                if (iceSmoke->primAlphaState == 0) { // Becoming more opaque
                    if (iceSmoke->timer >= 7) {
                        iceSmoke->primAlphaState++;
                    }
                } else { // Becoming more transparent, slows down
                    iceSmoke->accel.y = 2.0f;
                    iceSmoke->primAlpha -= 17;
                    iceSmoke->velocity.x *= 0.75f;
                    iceSmoke->velocity.z *= 0.75f;
                    if (iceSmoke->primAlpha <= 0) {
                        iceSmoke->primAlpha = 0;
                        iceSmoke->type = 0;
                    }
                }

                if ((pthis->unusedTimer2 == 0) && (iceSmoke->primAlpha >= 101) && iceSmoke->isTimerMod8) {
                    pthis->collider3.dim.pos.x = (s16)iceSmoke->pos.x;
                    pthis->collider3.dim.pos.y = (s16)iceSmoke->pos.y;
                    pthis->collider3.dim.pos.z = (s16)iceSmoke->pos.z;
                    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider3.base);
                }

                pos.x = iceSmoke->pos.x;
                pos.y = iceSmoke->pos.y + 10.0f;
                pos.z = iceSmoke->pos.z;

                if ((iceSmoke->primAlphaState != 2) && EnFz_ReachedTarget(pthis, &pos)) {
                    iceSmoke->primAlphaState = 2;
                    iceSmoke->velocity.x = 0.0f;
                    iceSmoke->velocity.z = 0.0f;
                }
            }
        }
        iceSmoke++;
    }
}

void EnFz_DrawIceSmoke(EnFz* pthis, GlobalContext* globalCtx) {
    EnFzEffectSsIceSmoke* iceSmoke = pthis->iceSmoke;
    s16 i;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u8 texLoaded = false;

    OPEN_DISPS(gfxCtx, "../z_en_fz.c", 1384);

    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(pthis->iceSmoke); i++) {
        if (iceSmoke->type > 0) {
            gDPPipeSync(POLY_XLU_DISP++);

            if (!texLoaded) {
                gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamStartDL));
                texLoaded++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 225, 235, iceSmoke->primAlpha);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 3 * (iceSmoke->timer + (3 * i)),
                                        15 * (iceSmoke->timer + (3 * i)), 32, 64, 1, 0, 0, 32, 32));
            Matrix_Translate(iceSmoke->pos.x, iceSmoke->pos.y, iceSmoke->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(iceSmoke->xyScale, iceSmoke->xyScale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_fz.c", 1424),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamDL));
        }

        iceSmoke++;
    }

    CLOSE_DISPS(gfxCtx, "../z_en_fz.c", 1430);
}

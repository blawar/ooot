#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_AM_Z_EN_AM_C
#include "actor_common.h"
/*
 * File: z_en_am.c
 * Overlay: ovl_En_Am
 * Description: Armos
 */

#include "z_en_am.h"
#include "objects/object_am/object_am.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "def/code_80043480.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_26)

void EnAm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAm_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnAm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAm_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAm_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnAm_SetupStatue(EnAm* pthis);
void EnAm_SetupSleep(EnAm* pthis);
void EnAm_Statue(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_Sleep(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_Lunge(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_RotateToHome(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_MoveToHome(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_RotateToInit(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_Cooldown(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_Ricochet(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_Stunned(EnAm* pthis, GlobalContext* globalCtx);
void EnAm_RecoilFromDamage(EnAm* pthis, GlobalContext* globalCtx);

static Vec3f velocity_52 = { 0.0f, -1.5f, 0.0f };

static Vec3f accel_52 = { 0.0f, -0.2f, 0.0f };

static Vec3f D_809B0074_81 = { 2500.0f, 7000.0f, 0.0f };

static Vec3f D_809B0080_81 = { -2500.0f, 0.0f, 0.0f };

static Vec3f D_809B008C_81 = { 2500.0f, 7000.0f, 4000.0f };

static Vec3f D_809B0098_81 = { -2500.0f, 0.0f, 4000.0f };

static Vec3f zeroVec_83 = { 0.0f, 0.0f, 0.0f };

static Color_RGBA8 dustPrimColor_83 = { 150, 150, 150, 255 };

static Color_RGBA8 dustEnvColor_83 = { 100, 100, 100, 150 };


ActorInit En_Am_InitVars = {
    ACTOR_EN_AM,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_AM,
    sizeof(EnAm),
    (ActorFunc)EnAm_Init,
    (ActorFunc)EnAm_Destroy,
    (ActorFunc)EnAm_Update,
    (ActorFunc)EnAm_Draw,
    (ActorFunc)EnAm_Reset,
};

static ColliderCylinderInit sHurtCylinderInit = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 15, 70, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sBlockCylinderInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00400106, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 15, 70, 0, { 0, 0, 0 } },
};

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, AM_DMGEFF_NUT),
    /* Deku stick    */ DMG_ENTRY(2, AM_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(1, AM_DMGEFF_NONE),
    /* Explosive     */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Boomerang     */ DMG_ENTRY(0, AM_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Hammer swing  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Hookshot      */ DMG_ENTRY(0, AM_DMGEFF_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, AM_DMGEFF_NONE),
    /* Master sword  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Giant's Knife */ DMG_ENTRY(4, AM_DMGEFF_KILL),
    /* Fire arrow    */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Ice arrow     */ DMG_ENTRY(4, AM_DMGEFF_ICE),
    /* Light arrow   */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Unk arrow 1   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(0, AM_DMGEFF_MAGIC_FIRE_LIGHT),
    /* Ice magic     */ DMG_ENTRY(3, AM_DMGEFF_ICE),
    /* Light magic   */ DMG_ENTRY(0, AM_DMGEFF_MAGIC_FIRE_LIGHT),
    /* Shield        */ DMG_ENTRY(0, AM_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, AM_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, AM_DMGEFF_NONE),
    /* Giant spin    */ DMG_ENTRY(4, AM_DMGEFF_KILL),
    /* Master spin   */ DMG_ENTRY(2, AM_DMGEFF_KILL),
    /* Kokiri jump   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
    /* Giant jump    */ DMG_ENTRY(8, AM_DMGEFF_KILL),
    /* Master jump   */ DMG_ENTRY(4, AM_DMGEFF_KILL),
    /* Unknown 1     */ DMG_ENTRY(0, AM_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, AM_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, AM_DMGEFF_KILL),
    /* Unknown 2     */ DMG_ENTRY(0, AM_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x13, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -4000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 5300, ICHAIN_STOP),
};

void EnAm_SetupAction(EnAm* pthis, EnAmActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

/**
 * Checks bgCheckFlags in the direction of current yaw at the specified distance.
 *
 * Returns true if the armos would land on the ground in the resulting position.
 *
 * If it won't land on the ground, it will return true anyway if the floor the armos will be on
 * is no more than 20 units lower than the home position. This prevents the armos from going down steep slopes.
 */
s32 EnAm_CanMove(EnAm* pthis, GlobalContext* globalCtx, f32 distance, s16 yaw) {
    s16 ret;
    s16 curBgCheckFlags;
    f32 sin;
    f32 cos;
    Vec3f curPos;

    // save current position and bgCheckFlags to restore later
    curPos = pthis->dyna.actor.world.pos;
    curBgCheckFlags = pthis->dyna.actor.bgCheckFlags;

    sin = Math_SinS(yaw) * distance;
    cos = Math_CosS(yaw) * distance;

    pthis->dyna.actor.world.pos.x += sin;
    pthis->dyna.actor.world.pos.z += cos;

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 0.0f, 0.0f, 0.0f, 4);
    pthis->dyna.actor.world.pos = curPos;
    ret = pthis->dyna.actor.bgCheckFlags & 1;

    if (!ret && (pthis->dyna.actor.floorHeight >= (pthis->dyna.actor.home.pos.y - 20.0f))) {
        ret = true;
    }

    pthis->dyna.actor.bgCheckFlags = curBgCheckFlags;

    return ret;
}

void EnAm_Init(Actor* thisx, GlobalContext* globalCtx) {
    CollisionHeader* colHeader = NULL;
    s32 pad;
    EnAm* pthis = (EnAm*)thisx;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 48.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gArmosSkel, &gArmosRicochetAnim, pthis->jointTable, pthis->morphTable,
                   14);
    Actor_SetScale(&pthis->dyna.actor, 0.01f);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    Collider_InitCylinder(globalCtx, &pthis->hurtCollider);
    Collider_InitCylinder(globalCtx, &pthis->blockCollider);
    Collider_SetCylinder(globalCtx, &pthis->hurtCollider, &pthis->dyna.actor, &sHurtCylinderInit);

    if (pthis->dyna.actor.params == ARMOS_STATUE) {
        pthis->dyna.actor.colChkInfo.health = 1;
        Collider_SetCylinder(globalCtx, &pthis->blockCollider, &pthis->dyna.actor, &sHurtCylinderInit);
        pthis->hurtCollider.base.ocFlags1 = (OC1_ON | OC1_NO_PUSH | OC1_TYPE_1 | OC1_TYPE_2);
        pthis->blockCollider.base.ocFlags1 = (OC1_ON | OC1_NO_PUSH | OC1_TYPE_PLAYER);
        CollisionHeader_GetVirtual(&gArmosCol, &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->dyna.actor, ACTORCAT_BG);
        EnAm_SetupStatue(pthis);
    } else {
        Collider_SetCylinder(globalCtx, &pthis->blockCollider, &pthis->dyna.actor, &sBlockCylinderInit);
        Collider_InitQuad(globalCtx, &pthis->hitCollider);
        Collider_SetQuad(globalCtx, &pthis->hitCollider, &pthis->dyna.actor, &sQuadInit);
        pthis->dyna.actor.colChkInfo.health = 1;
        pthis->dyna.actor.colChkInfo.damageTable = &sDamageTable;
        EnAm_SetupSleep(pthis);
        pthis->unk_258 = 0;
    }

    pthis->dyna.actor.colChkInfo.mass = MASS_HEAVY;
}

void EnAm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnAm* pthis = (EnAm*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->hurtCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->blockCollider);
    //! @bug Quad collider is not destroyed (though destroy doesnt really do anything anyway)
}

void EnAm_SpawnEffects(EnAm* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f pos;
    Color_RGBA8 primColor = { 100, 100, 100, 0 };
    Color_RGBA8 envColor = { 40, 40, 40, 0 };
    s32 pad;

    for (i = 4; i > 0; i--) {
        pos.x = pthis->dyna.actor.world.pos.x + ((Rand_ZeroOne() - 0.5f) * 65.0f);
        pos.y = (pthis->dyna.actor.world.pos.y + 40.0f) + ((Rand_ZeroOne() - 0.5f) * 10.0f);
        pos.z = pthis->dyna.actor.world.pos.z + ((Rand_ZeroOne() - 0.5f) * 65.0f);

        EffectSsKiraKira_SpawnSmall(globalCtx, &pos, &velocity_52, &accel_52, &primColor, &envColor);
    }

    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_WALK);
    Actor_SpawnFloorDustRing(globalCtx, &pthis->dyna.actor, &pthis->dyna.actor.world.pos, 4.0f, 3, 8.0f, 0x12C, 0xF, 0);
}

void EnAm_SetupSleep(EnAm* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gArmosRicochetAnim);

    Animation_Change(&pthis->skelAnime, &gArmosRicochetAnim, 0.0f, lastFrame, lastFrame, ANIMMODE_LOOP, 0.0f);
    pthis->behavior = AM_BEHAVIOR_DO_NOTHING;
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->unk_258 = (pthis->textureBlend == 255) ? 0 : 1;
    EnAm_SetupAction(pthis, EnAm_Sleep);
}

void EnAm_SetupStatue(EnAm* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gArmosRicochetAnim);

    Animation_Change(&pthis->skelAnime, &gArmosRicochetAnim, 0.0f, lastFrame, lastFrame, ANIMMODE_LOOP, 0.0f);
    pthis->dyna.actor.flags &= ~ACTOR_FLAG_0;
    pthis->behavior = AM_BEHAVIOR_DO_NOTHING;
    pthis->dyna.actor.speedXZ = 0.0f;
    EnAm_SetupAction(pthis, EnAm_Statue);
}

void EnAm_SetupLunge(EnAm* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gArmosHopAnim, 4.0f);
    pthis->unk_258 = 3;
    pthis->behavior = AM_BEHAVIOR_AGGRO;
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.shape.rot.y;
    EnAm_SetupAction(pthis, EnAm_Lunge);
}

void EnAm_SetupCooldown(EnAm* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gArmosHopAnim, 4.0f);
    pthis->unk_258 = 3;
    pthis->cooldownTimer = 40;
    pthis->behavior = AM_BEHAVIOR_AGGRO;
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.shape.rot.y;
    EnAm_SetupAction(pthis, EnAm_Cooldown);
}

void EnAm_SetupMoveToHome(EnAm* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gArmosHopAnim, 4.0f);
    pthis->behavior = AM_BEHAVIOR_GO_HOME;
    pthis->unk_258 = 1;
    pthis->dyna.actor.speedXZ = 0.0f;
    EnAm_SetupAction(pthis, EnAm_MoveToHome);
}

void EnAm_SetupRotateToInit(EnAm* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gArmosHopAnim, 4.0f);
    pthis->behavior = AM_BEHAVIOR_GO_HOME;
    pthis->unk_258 = 1;
    pthis->dyna.actor.speedXZ = 0.0f;
    EnAm_SetupAction(pthis, EnAm_RotateToInit);
}

void EnAm_SetupRotateToHome(EnAm* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gArmosHopAnim, 4.0f);
    pthis->behavior = AM_BEHAVIOR_GO_HOME;
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.shape.rot.y;
    EnAm_SetupAction(pthis, EnAm_RotateToHome);
}

void EnAm_SetupRecoilFromDamage(EnAm* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gArmosDamagedAnim, 1.0f, 4.0f,
                     Animation_GetLastFrame(&gArmosDamagedAnim) - 6.0f, ANIMMODE_ONCE, 0.0f);
    pthis->behavior = AM_BEHAVIOR_DAMAGED;
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.yawTowardsPlayer;
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_DAMAGE);

    if (EnAm_CanMove(pthis, globalCtx, -6.0f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = -6.0f;
    }

    pthis->dyna.actor.colorFilterTimer = 0;
    Enemy_StartFinishingBlow(globalCtx, &pthis->dyna.actor);
    EnAm_SetupAction(pthis, EnAm_RecoilFromDamage);
}

void EnAm_SetupRicochet(EnAm* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gArmosRicochetAnim, 1.0f, 0.0f, 8.0f, ANIMMODE_ONCE, 0.0f);
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.yawTowardsPlayer;

    if (EnAm_CanMove(pthis, globalCtx, -6.0f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = -6.0f;
    }

    pthis->unk_264 = 0;
    pthis->unk_258 = 0;
    pthis->cooldownTimer = 5;
    pthis->behavior = AM_BEHAVIOR_RICOCHET;
    EnAm_SetupAction(pthis, EnAm_Ricochet);
}

void EnAm_Sleep(EnAm* pthis, GlobalContext* globalCtx) {
    f32 cos;
    s32 pad;
    f32 rand;
    f32 sin;
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->unk_258 != 0) ||
        ((pthis->hurtCollider.base.ocFlags1 & OC1_HIT) && (pthis->hurtCollider.base.oc == &player->actor)) ||
        (pthis->hurtCollider.base.acFlags & AC_HIT)) {
        pthis->hurtCollider.base.acFlags &= ~AC_HIT;

        if (pthis->textureBlend == 0) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_WAVE);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_VOICE);
            Actor_SetColorFilter(&pthis->dyna.actor, 0x4000, 255, 0, 8);
        }

        if (pthis->textureBlend >= 240) {
            pthis->attackTimer = 200;
            pthis->textureBlend = 255;
            pthis->dyna.actor.flags |= ACTOR_FLAG_0;
            pthis->dyna.actor.shape.yOffset = 0.0f;
            EnAm_SetupLunge(pthis);
        } else {
            // shake randomly about the origin while waking up
            rand = (Rand_ZeroOne() - 0.5f) * 10.0f;

            cos = Math_CosS(pthis->dyna.actor.shape.rot.y) * rand;
            sin = Math_SinS(pthis->dyna.actor.shape.rot.y) * rand;

            pthis->dyna.actor.world.pos.x = pthis->shakeOrigin.x + cos;
            pthis->dyna.actor.world.pos.z = pthis->shakeOrigin.z + sin;

            pthis->textureBlend += 20;
            pthis->unk_258 = 1;
        }
    } else {
        if (pthis->textureBlend > 10) {
            pthis->textureBlend -= 10;
        } else {
            pthis->textureBlend = 0;
            pthis->dyna.actor.flags &= ~ACTOR_FLAG_0;

            if (pthis->dyna.bgId < 0) {
                pthis->unk_264 = 0;
            }

            pthis->dyna.actor.speedXZ += pthis->dyna.unk_150;
            pthis->shakeOrigin = pthis->dyna.actor.world.pos;
            pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;
            pthis->dyna.actor.speedXZ = CLAMP(pthis->dyna.actor.speedXZ, -2.5f, 2.5f);
            Math_SmoothStepToF(&pthis->dyna.actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);

            if (pthis->dyna.actor.speedXZ != 0.0f) {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
            }

            pthis->dyna.unk_154 = 0.0f;
            pthis->dyna.unk_150 = 0.0f;
        }
    }
}

/**
 * Spin toward the direction of the home position to start moving back to it.
 */
void EnAm_RotateToHome(EnAm* pthis, GlobalContext* globalCtx) {
    s16 yawToHome = Math_Vec3f_Yaw(&pthis->dyna.actor.world.pos, &pthis->dyna.actor.home.pos);

    if (pthis->skelAnime.curFrame == 8.0f) {
        Math_SmoothStepToS(&pthis->dyna.actor.world.rot.y, yawToHome, 1, 0x1F40, 0);
        pthis->dyna.actor.velocity.y = 12.0f;
    } else if (pthis->skelAnime.curFrame > 11.0f) {
        if (!(pthis->dyna.actor.bgCheckFlags & 1)) {
            pthis->skelAnime.curFrame = 11;
        } else {
            EnAm_SpawnEffects(pthis, globalCtx);

            if (pthis->dyna.actor.world.rot.y == yawToHome) {
                pthis->unk_258 = 0;
            }

            pthis->dyna.actor.velocity.y = 0.0f;
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        }
    }

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_258 == 0) {
        EnAm_SetupMoveToHome(pthis);
    }

    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
}

/**
 * After reaching the home position, spin back to the starting rotation.
 */
void EnAm_RotateToInit(EnAm* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame == 8.0f) {
        if ((pthis->dyna.actor.world.pos.x == pthis->dyna.actor.home.pos.x) &&
            (pthis->dyna.actor.world.pos.z == pthis->dyna.actor.home.pos.z)) {
            Math_SmoothStepToS(&pthis->dyna.actor.world.rot.y, pthis->dyna.actor.home.rot.y, 1, 0x1F40, 0);
        }
        pthis->unk_258 = 2;
        pthis->dyna.actor.velocity.y = 12.0f;
    } else if (pthis->skelAnime.curFrame > 11.0f) {
        if (!(pthis->dyna.actor.bgCheckFlags & 1)) {
            pthis->skelAnime.curFrame = 11;
        } else {
            pthis->unk_258 = 1;
            EnAm_SpawnEffects(pthis, globalCtx);

            if (pthis->dyna.actor.home.rot.y == pthis->dyna.actor.world.rot.y) {
                pthis->unk_258 = 0;
            }

            pthis->dyna.actor.velocity.y = 0.0f;
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        }
    }

    if (pthis->unk_258 == 2) {
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.x, pthis->dyna.actor.home.pos.x, 1.0f, 8.0f, 0.0f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.z, pthis->dyna.actor.home.pos.z, 1.0f, 8.0f, 0.0f);
    }

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_258 == 0) {
        EnAm_SetupSleep(pthis);
    }

    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
}

void EnAm_MoveToHome(EnAm* pthis, GlobalContext* globalCtx) {
    s16 yawToHome = Math_Vec3f_Yaw(&pthis->dyna.actor.world.pos, &pthis->dyna.actor.home.pos);

    if (pthis->skelAnime.curFrame == 8.0f) {
        pthis->dyna.actor.velocity.y = 12.0f;
        pthis->dyna.actor.speedXZ = 6.0f;
    } else if (pthis->skelAnime.curFrame > 11.0f) {
        if (!(pthis->dyna.actor.bgCheckFlags & 1)) {
            pthis->skelAnime.curFrame = 11;
        } else {
            Math_SmoothStepToS(&pthis->dyna.actor.world.rot.y, yawToHome, 1, 0xBB8, 0);

            if (pthis->dyna.actor.bgCheckFlags & 2) {
                pthis->unk_258--;
            }

            pthis->dyna.actor.velocity.y = 0.0f;
            pthis->dyna.actor.speedXZ = 0.0f;
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
            EnAm_SpawnEffects(pthis, globalCtx);

            if (Actor_WorldDistXYZToPoint(&pthis->dyna.actor, &pthis->dyna.actor.home.pos) < 80.0f) {
                EnAm_SetupRotateToInit(pthis);
            }
        }
    }

    // turn away from a wall if touching one
    if ((pthis->dyna.actor.speedXZ != 0.0f) && (pthis->dyna.actor.bgCheckFlags & 8)) {
        pthis->dyna.actor.world.rot.y = pthis->dyna.actor.wallYaw;
        Actor_MoveForward(&pthis->dyna.actor);
    }

    SkelAnime_Update(&pthis->skelAnime);

    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
}

void EnAm_RecoilFromDamage(EnAm* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.speedXZ < 0.0f) {
        pthis->dyna.actor.speedXZ += 0.5f;
    }

    if ((pthis->dyna.actor.velocity.y <= 0.0f) && !EnAm_CanMove(pthis, globalCtx, -8.0f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnAm_SetupLunge(pthis);
        pthis->deathTimer = 64;
        pthis->panicSpinRot = 0;
    }
}

/**
 * After doing 3 lunges, wait for 2 seconds before attacking again.
 * Turn toward the player before lunging again.
 */
void EnAm_Cooldown(EnAm* pthis, GlobalContext* globalCtx) {
    s16 yawDiff = pthis->dyna.actor.yawTowardsPlayer - pthis->dyna.actor.world.rot.y;

    yawDiff = ABS(yawDiff);

    if (pthis->cooldownTimer != 0) {
        pthis->cooldownTimer--;
    } else {
        if (pthis->skelAnime.curFrame == 8.0f) {
            Math_SmoothStepToS(&pthis->dyna.actor.world.rot.y, pthis->dyna.actor.yawTowardsPlayer, 1, 0x1F40, 0);
            pthis->dyna.actor.velocity.y = 12.0f;
        } else if (pthis->skelAnime.curFrame > 11.0f) {
            if (!(pthis->dyna.actor.bgCheckFlags & 1)) {
                pthis->skelAnime.curFrame = 11;
            } else {
                if (yawDiff < 3500) {
                    pthis->unk_258 = 0;
                }
                pthis->dyna.actor.velocity.y = 0.0f;
                pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
                EnAm_SpawnEffects(pthis, globalCtx);
            }
        }

        SkelAnime_Update(&pthis->skelAnime);

        if (pthis->unk_258 == 0) {
            EnAm_SetupLunge(pthis);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_VOICE);
        }

        pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
    }
}

/**
 * Lunge toward the player in an attempt to deal damage. Hop 3 times.
 * Used for both normal attacks and the death sequence.
 */
void EnAm_Lunge(EnAm* pthis, GlobalContext* globalCtx) {
    if (pthis->deathTimer < 52) {
        if (pthis->skelAnime.curFrame == 8.0f) {
            pthis->dyna.actor.velocity.y = 12.0f;

            if (EnAm_CanMove(pthis, globalCtx, 80.0f, pthis->dyna.actor.world.rot.y)) {
                pthis->dyna.actor.speedXZ = 6.0f;
            } else {
                pthis->dyna.actor.speedXZ = 0.0f;
            }

            pthis->unk_264 = 1;
            pthis->hitCollider.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
        } else if (pthis->skelAnime.curFrame > 11.0f) {
            if (!(pthis->dyna.actor.bgCheckFlags & 1)) {
                pthis->skelAnime.curFrame = 11;
            } else {
                Math_SmoothStepToS(&pthis->dyna.actor.world.rot.y, pthis->dyna.actor.yawTowardsPlayer, 1, 0x1770, 0);

                if (pthis->dyna.actor.bgCheckFlags & 2) {
                    pthis->unk_258--;
                }

                pthis->dyna.actor.velocity.y = 0.0f;
                pthis->dyna.actor.speedXZ = 0.0f;
                pthis->unk_264 = 0;
                pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
                EnAm_SpawnEffects(pthis, globalCtx);

                if (((Actor_WorldDistXZToPoint(&pthis->dyna.actor, &pthis->dyna.actor.home.pos) > 240.0f) ||
                     (pthis->attackTimer == 0)) &&
                    (pthis->deathTimer == 0)) {
                    EnAm_SetupRotateToHome(pthis);
                }
            }
        }

        // turn and move away from a wall if contact is made with one
        if ((pthis->dyna.actor.speedXZ != 0.0f) && (pthis->dyna.actor.bgCheckFlags & 8)) {
            pthis->dyna.actor.world.rot.y =
                (pthis->dyna.actor.wallYaw - pthis->dyna.actor.world.rot.y) + pthis->dyna.actor.wallYaw;
            Actor_MoveForward(&pthis->dyna.actor);
            pthis->dyna.actor.bgCheckFlags &= ~8;
        }

        SkelAnime_Update(&pthis->skelAnime);

        if ((pthis->unk_258 == 0) && (pthis->deathTimer == 0)) {
            EnAm_SetupCooldown(pthis);
        }

        if (pthis->deathTimer == 0) {
            pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
        } else {
            if (pthis->panicSpinRot < 8000) {
                pthis->panicSpinRot += 800;
            }
            pthis->dyna.actor.shape.rot.y += pthis->panicSpinRot;
        }
    }
}

void EnAm_Statue(EnAm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 temp158f = pthis->dyna.unk_158;
    s16 moveDir = 0;

    if (pthis->unk_258 == 0) {
        if (pthis->dyna.unk_150 != 0.0f) {
            pthis->unk_258 = 0x8000;
        }
    } else {
        pthis->unk_258 -= 0x800;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);

        if (pthis->dyna.unk_150 < 0.0f) {
            temp158f = pthis->dyna.unk_158 + 0x8000;
        }

        if (pthis->hurtCollider.base.ocFlags1 & OC1_HIT) {
            moveDir = Math_Vec3f_Yaw(&pthis->dyna.actor.world.pos, &pthis->hurtCollider.base.oc->world.pos) - temp158f;
        }

        if ((pthis->dyna.unk_150 == 0.0f) || (pthis->unk_258 == 0) || !(pthis->dyna.actor.bgCheckFlags & 1) ||
            !func_800435D8(globalCtx, &pthis->dyna, 0x14,
                           (Math_SinS(pthis->unk_258) * (pthis->dyna.unk_150 * 0.5f)) + 40.0f, 0xA) ||
            ((pthis->hurtCollider.base.ocFlags1 & OC1_HIT) && (ABS(moveDir) <= 0x2000))) {

            pthis->unk_258 = 0;
            player->stateFlags2 &= ~0x151;
            player->actor.speedXZ = 0.0f;
            pthis->dyna.unk_150 = pthis->dyna.unk_154 = 0.0f;
        }

        pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;
        pthis->dyna.actor.speedXZ = Math_SinS(pthis->unk_258) * (pthis->dyna.unk_150 * 0.5f);
    }

    if (pthis->dyna.actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
    }

    pthis->dyna.unk_150 = pthis->dyna.unk_154 = 0.0f;
}

void EnAm_SetupStunned(EnAm* pthis, GlobalContext* globalCtx) {
    // animation is set but SkelAnime_Update is not called in the action
    // likely copy pasted from EnAm_SetupRecoilFromDamage
    Animation_Change(&pthis->skelAnime, &gArmosDamagedAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gArmosDamagedAnim),
                     ANIMMODE_ONCE, 0.0f);

    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.yawTowardsPlayer;

    if (EnAm_CanMove(pthis, globalCtx, -6.0f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = -6.0f;
    }

    Actor_SetColorFilter(&pthis->dyna.actor, 0, 120, 0, 100);

    if (pthis->damageEffect == AM_DMGEFF_ICE) {
        pthis->iceTimer = 48;
    }

    pthis->behavior = AM_BEHAVIOR_STUNNED;
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnAm_SetupAction(pthis, EnAm_Stunned);
}

void EnAm_Stunned(EnAm* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->dyna.actor.shape.rot.y, pthis->dyna.actor.world.rot.y, 1, 0xFA0, 0);

    if (pthis->dyna.actor.speedXZ < 0.0f) {
        pthis->dyna.actor.speedXZ += 0.5f;
    }

    if ((pthis->dyna.actor.velocity.y <= 0.0f) && !EnAm_CanMove(pthis, globalCtx, -9.0f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = 0.0f;
    }

    if (pthis->dyna.actor.colorFilterTimer == 0) {
        if (pthis->dyna.actor.colChkInfo.health != 0) {
            EnAm_SetupLunge(pthis);
        } else {
            EnAm_SetupRecoilFromDamage(pthis, globalCtx);
        }
    }
}

void EnAm_Ricochet(EnAm* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.speedXZ < 0.0f) {
        pthis->dyna.actor.speedXZ += 0.5f;
    }

    if ((pthis->dyna.actor.velocity.y <= 0.0f) &&
        !EnAm_CanMove(pthis, globalCtx, pthis->dyna.actor.speedXZ * 1.5f, pthis->dyna.actor.world.rot.y)) {
        pthis->dyna.actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->dyna.actor.speedXZ = 0.0f;
        EnAm_SetupLunge(pthis);
    }
}

void EnAm_TransformSwordHitbox(Actor* thisx, GlobalContext* globalCtx) {
    EnAm* pthis = (EnAm*)thisx;

    Matrix_MultVec3f(&D_809B0074_81, &pthis->hitCollider.dim.quad[1]);
    Matrix_MultVec3f(&D_809B0080_81, &pthis->hitCollider.dim.quad[0]);
    Matrix_MultVec3f(&D_809B008C_81, &pthis->hitCollider.dim.quad[3]);
    Matrix_MultVec3f(&D_809B0098_81, &pthis->hitCollider.dim.quad[2]);

    Collider_SetQuadVertices(&pthis->hitCollider, &pthis->hitCollider.dim.quad[0], &pthis->hitCollider.dim.quad[1],
                             &pthis->hitCollider.dim.quad[2], &pthis->hitCollider.dim.quad[3]);
}

void EnAm_UpdateDamage(EnAm* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f sparkPos;

    if (pthis->deathTimer == 0) {
        if (pthis->blockCollider.base.acFlags & AC_BOUNCED) {
            pthis->blockCollider.base.acFlags &= ~(AC_HIT | AC_BOUNCED);
            pthis->hurtCollider.base.acFlags &= ~AC_HIT;

            if (pthis->behavior >= AM_BEHAVIOR_5) {
                EnAm_SetupRicochet(pthis, globalCtx);
            }
        } else if ((pthis->hurtCollider.base.acFlags & AC_HIT) && (pthis->behavior >= AM_BEHAVIOR_5)) {
            pthis->hurtCollider.base.acFlags &= ~AC_HIT;

            if (pthis->dyna.actor.colChkInfo.damageEffect != AM_DMGEFF_MAGIC_FIRE_LIGHT) {
                pthis->unk_264 = 0;
                pthis->damageEffect = pthis->dyna.actor.colChkInfo.damageEffect;
                Actor_SetDropFlag(&pthis->dyna.actor, &pthis->hurtCollider.info, 0);

                if ((pthis->dyna.actor.colChkInfo.damageEffect == AM_DMGEFF_NUT) ||
                    (pthis->dyna.actor.colChkInfo.damageEffect == AM_DMGEFF_STUN) ||
                    (pthis->dyna.actor.colChkInfo.damageEffect == AM_DMGEFF_ICE)) {
                    if (pthis->behavior != AM_BEHAVIOR_STUNNED) {
                        EnAm_SetupStunned(pthis, globalCtx);

                        if (pthis->dyna.actor.colChkInfo.damage != 0) {
                            pthis->dyna.actor.colChkInfo.health = 0;
                        }
                    } else if (pthis->dyna.actor.colChkInfo.damageEffect == AM_DMGEFF_STUN) {
                        sparkPos = pthis->dyna.actor.world.pos;
                        sparkPos.y += 50.0f;
                        CollisionCheck_SpawnShieldParticlesMetal(globalCtx, &sparkPos);
                    }
                } else if ((pthis->dyna.actor.colChkInfo.damageEffect == AM_DMGEFF_KILL) ||
                           (pthis->behavior == AM_BEHAVIOR_STUNNED)) {
                    pthis->dyna.actor.colChkInfo.health = 0;

                    EnAm_SetupRecoilFromDamage(pthis, globalCtx);
                } else {
                    EnAm_SetupRicochet(pthis, globalCtx);
                }
            }
        }
    }
}

void EnAm_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnAm* pthis = (EnAm*)thisx;
    EnBom* bomb;
    Vec3f dustPos;
    s32 i;
    f32 dustPosScale;
    s32 pad1;

    if (pthis->dyna.actor.params != ARMOS_STATUE) {
        EnAm_UpdateDamage(pthis, globalCtx);
    }

    if (pthis->dyna.actor.colChkInfo.damageEffect != AM_DMGEFF_MAGIC_FIRE_LIGHT) {
        if (pthis->attackTimer != 0) {
            pthis->attackTimer--;
        }

        pthis->actionFunc(pthis, globalCtx);

        if (pthis->deathTimer != 0) {
            pthis->deathTimer--;

            if (pthis->deathTimer == 0) {
                dustPosScale = globalCtx->gameplayFrames * 10;

                EnAm_SpawnEffects(pthis, globalCtx);
                bomb =
                    (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->dyna.actor.world.pos.x,
                                        pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, 0, 2, BOMB_BODY);
                if (bomb != NULL) {
                    bomb->timer = 0;
                }

                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_AMOS_DEAD);
                Item_DropCollectibleRandom(globalCtx, &pthis->dyna.actor, &pthis->dyna.actor.world.pos, 0xA0);

                for (i = 9; i >= 0; i--) {
                    dustPos.x = (sinf(dustPosScale) * 7.0f) + pthis->dyna.actor.world.pos.x;
                    dustPos.y = (Rand_CenteredFloat(10.0f) * 6.0f) + (pthis->dyna.actor.world.pos.y + 40.0f);
                    dustPos.z = (cosf(dustPosScale) * 7.0f) + pthis->dyna.actor.world.pos.z;

                    func_8002836C(globalCtx, &dustPos, &zeroVec_83, &zeroVec_83, &dustPrimColor_83, &dustEnvColor_83, 200, 45, 12);
                    dustPosScale += 60.0f;
                }

                Actor_Kill(&pthis->dyna.actor);
                return;
            }

            if ((pthis->deathTimer % 4) == 0) {
                Actor_SetColorFilter(&pthis->dyna.actor, 0x4000, 255, 0, 4);
            }
        }

        Actor_MoveForward(&pthis->dyna.actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 20.0f, 28.0f, 80.0f, 0x1D);
    }

    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->hurtCollider);
    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->blockCollider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->hurtCollider.base);

    if (pthis->dyna.actor.params != ARMOS_STATUE) {
        Actor_SetFocus(&pthis->dyna.actor, pthis->dyna.actor.scale.x * 4500.0f);

        if (pthis->dyna.actor.colorFilterTimer == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->blockCollider.base);
        }

        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->hurtCollider.base);

        if ((pthis->behavior >= 4) && (pthis->unk_264 > 0)) {
            if (!(pthis->hitCollider.base.atFlags & AT_BOUNCED)) {
                if (pthis->hitCollider.base.atFlags & AT_HIT) {
                    Player* player = GET_PLAYER(globalCtx);

                    if (pthis->hitCollider.base.at == &player->actor) {
                        Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
                    }
                }
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->hitCollider.base);
            } else {
                pthis->hitCollider.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
                pthis->hitCollider.base.at = NULL;
                EnAm_SetupRicochet(pthis, globalCtx);
            }
        }
    } else {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->blockCollider.base);
    }
}

static Vec3f sUnused1 = { 1100.0f, -700.0f, 0.0f };
static Vec3f sUnused2 = { 0.0f, 0.0f, 0.0f };

void EnAm_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnAm* pthis = (EnAm*)thisx;

    if ((limbIndex == 1) && (pthis->unk_264 != 0)) {
        EnAm_TransformSwordHitbox(&pthis->dyna.actor, globalCtx);
    }
}

static Vec3f sIcePosOffsets[] = {
    { 20.0f, 40.0f, 0.0f },   { 10.0f, 60.0f, 10.0f },   { -10.0f, 60.0f, 10.0f }, { -20.0f, 40.0f, 0.0f },
    { 10.0f, 60.0f, -10.0f }, { -10.0f, 60.0f, -10.0f }, { 0.0f, 40.0f, -20.0f },  { 10.0f, 20.0f, 10.0f },
    { 10.0f, 20.0f, -10.0f }, { 0.0f, 40.0f, 20.0f },    { -10.0f, 20.0f, 10.0f }, { -10.0f, 20.0f, -10.0f },
};

void EnAm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f sp68;
    EnAm* pthis = (EnAm*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_am.c", 1580);

    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, pthis->textureBlend);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, EnAm_PostLimbDraw, pthis);

    if (pthis->iceTimer != 0) {
        pthis->dyna.actor.colorFilterTimer++;
        if (1) {};
        pthis->iceTimer--;

        if ((pthis->iceTimer % 4) == 0) {
            s32 index;

            index = pthis->iceTimer >> 2;

            sp68.x = pthis->dyna.actor.world.pos.x + sIcePosOffsets[index].x;
            sp68.y = pthis->dyna.actor.world.pos.y + sIcePosOffsets[index].y;
            sp68.z = pthis->dyna.actor.world.pos.z + sIcePosOffsets[index].z;

            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->dyna.actor, &sp68, 150, 150, 150, 250, 235, 245, 255,
                                           1.4f);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_am.c", 1605);
}

void EnAm_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    velocity_52 = { 0.0f, -1.5f, 0.0f };

    accel_52 = { 0.0f, -0.2f, 0.0f };

    D_809B0074_81 = { 2500.0f, 7000.0f, 0.0f };

    D_809B0080_81 = { -2500.0f, 0.0f, 0.0f };

    D_809B008C_81 = { 2500.0f, 7000.0f, 4000.0f };

    D_809B0098_81 = { -2500.0f, 0.0f, 4000.0f };

    zeroVec_83 = { 0.0f, 0.0f, 0.0f };

    dustPrimColor_83 = { 150, 150, 150, 255 };

    dustEnvColor_83 = { 100, 100, 100, 150 };

    En_Am_InitVars = {
        ACTOR_EN_AM,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_AM,
        sizeof(EnAm),
        (ActorFunc)EnAm_Init,
        (ActorFunc)EnAm_Destroy,
        (ActorFunc)EnAm_Update,
        (ActorFunc)EnAm_Draw,
        (ActorFunc)EnAm_Reset,
    };

    sHurtCylinderInit = {
        {
            COLTYPE_HIT5,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, 70, 0, { 0, 0, 0 } },
    };

    sBlockCylinderInit = {
        {
            COLTYPE_METAL,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00400106, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 15, 70, 0, { 0, 0, 0 } },
    };

    sQuadInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, AM_DMGEFF_NUT),
        /* Deku stick    */ DMG_ENTRY(2, AM_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(1, AM_DMGEFF_NONE),
        /* Explosive     */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Boomerang     */ DMG_ENTRY(0, AM_DMGEFF_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Hammer swing  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Hookshot      */ DMG_ENTRY(0, AM_DMGEFF_STUN),
        /* Kokiri sword  */ DMG_ENTRY(1, AM_DMGEFF_NONE),
        /* Master sword  */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Giant's Knife */ DMG_ENTRY(4, AM_DMGEFF_KILL),
        /* Fire arrow    */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Ice arrow     */ DMG_ENTRY(4, AM_DMGEFF_ICE),
        /* Light arrow   */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Unk arrow 1   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(0, AM_DMGEFF_MAGIC_FIRE_LIGHT),
        /* Ice magic     */ DMG_ENTRY(3, AM_DMGEFF_ICE),
        /* Light magic   */ DMG_ENTRY(0, AM_DMGEFF_MAGIC_FIRE_LIGHT),
        /* Shield        */ DMG_ENTRY(0, AM_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, AM_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, AM_DMGEFF_NONE),
        /* Giant spin    */ DMG_ENTRY(4, AM_DMGEFF_KILL),
        /* Master spin   */ DMG_ENTRY(2, AM_DMGEFF_KILL),
        /* Kokiri jump   */ DMG_ENTRY(2, AM_DMGEFF_NONE),
        /* Giant jump    */ DMG_ENTRY(8, AM_DMGEFF_KILL),
        /* Master jump   */ DMG_ENTRY(4, AM_DMGEFF_KILL),
        /* Unknown 1     */ DMG_ENTRY(0, AM_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, AM_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, AM_DMGEFF_KILL),
        /* Unknown 2     */ DMG_ENTRY(0, AM_DMGEFF_NONE),
    };

    sUnused1 = { 1100.0f, -700.0f, 0.0f };

    sUnused2 = { 0.0f, 0.0f, 0.0f };

}

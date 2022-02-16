#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_VALI_Z_EN_VALI_C
#include "actor_common.h"
/*
 * File: z_en_vali.c
 * Overlay: ovl_En_Vali
 * Description: Bari (Big Jellyfish)
 */

#include "z_en_vali.h"
#include "objects/object_vali/object_vali.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_12)

void EnVali_Init(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnVali_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Update(Actor* thisx, GlobalContext* globalCtx);
void EnVali_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnVali_SetupLurk(EnVali* pthis);
void EnVali_SetupDropAppear(EnVali* pthis);

void EnVali_Lurk(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_DropAppear(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_FloatIdle(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_Attacked(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_Retaliate(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_MoveArmsDown(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_Burnt(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_DivideAndDie(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_Stunned(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_Frozen(EnVali* pthis, GlobalContext* globalCtx);
void EnVali_ReturnToLurk(EnVali* pthis, GlobalContext* globalCtx);

static Color_RGBA8 primColor_61 = { 255, 255, 255, 255 };

static Color_RGBA8 envColor_61 = { 200, 255, 255, 255 };

static Vec3f velocity_69 = { 0.0f, 0.0f, 0.0f };

static Vec3f accel_69 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80B28970_80 = { 3000.0f, 0.0f, 0.0f };

static Vec3f D_80B2897C_80 = { -1000.0f, 0.0f, 0.0f };


ActorInit En_Vali_InitVars = {
    ACTOR_EN_VALI,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_VALI,
    sizeof(EnVali),
    (ActorFunc)EnVali_Init,
    (ActorFunc)EnVali_Destroy,
    (ActorFunc)EnVali_Update,
    (ActorFunc)EnVali_Draw,
    (ActorFunc)EnVali_Reset,
};

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x07, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
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
        { 0xFFCFFFFF, 0x07, 0x08 },
        { 0xFFCFFFFF, 0x01, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 17, 35, -15, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 2, 18, 32, MASS_HEAVY };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, BARI_DMGEFF_STUN),
    /* Deku stick    */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(0, BARI_DMGEFF_SLINGSHOT),
    /* Explosive     */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(0, BARI_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Kokiri sword  */ DMG_ENTRY(1, BARI_DMGEFF_SWORD),
    /* Master sword  */ DMG_ENTRY(2, BARI_DMGEFF_SWORD),
    /* Giant's Knife */ DMG_ENTRY(4, BARI_DMGEFF_SWORD),
    /* Fire arrow    */ DMG_ENTRY(4, BARI_DMGEFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(4, BARI_DMGEFF_ICE),
    /* Light arrow   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(4, BARI_DMGEFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(4, BARI_DMGEFF_ICE),
    /* Light magic   */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    /* Shield        */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, BARI_DMGEFF_NONE),
    /* Giant spin    */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
    /* Master spin   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Kokiri jump   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
    /* Giant jump    */ DMG_ENTRY(8, BARI_DMGEFF_NONE),
    /* Master jump   */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
    /* Unknown 1     */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x18, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 5000, ICHAIN_STOP),
};

void EnVali_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnVali* pthis = (EnVali*)thisx;
    s32 bgId;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 27.0f);
    pthis->actor.shape.shadowAlpha = 155;
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gBariSkel, &gBariLurkingAnim, pthis->jointTable, pthis->morphTable,
                   EN_VALI_LIMB_MAX);

    Collider_InitQuad(globalCtx, &pthis->leftArmCollider);
    Collider_SetQuad(globalCtx, &pthis->leftArmCollider, &pthis->actor, &sQuadInit);
    Collider_InitQuad(globalCtx, &pthis->rightArmCollider);
    Collider_SetQuad(globalCtx, &pthis->rightArmCollider, &pthis->actor, &sQuadInit);
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);

    EnVali_SetupLurk(pthis);

    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                          &pthis->actor, &pthis->actor.world.pos);
    pthis->actor.params = BARI_TYPE_NORMAL;

    if (pthis->actor.floorHeight == BGCHECK_Y_MIN) {
        Actor_Kill(&pthis->actor);
    }
}

void EnVali_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnVali* pthis = (EnVali*)thisx;

    Collider_DestroyQuad(globalCtx, &pthis->leftArmCollider);
    Collider_DestroyQuad(globalCtx, &pthis->rightArmCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
}

void EnVali_SetupLurk(EnVali* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gBariLurkingAnim);
    pthis->actor.draw = NULL;
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnVali_Lurk;
}

void EnVali_SetupDropAppear(EnVali* pthis) {
    pthis->actor.draw = EnVali_Draw;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actor.velocity.y = 1.0f;
    pthis->actionFunc = EnVali_DropAppear;
}

void EnVali_SetupFloatIdle(EnVali* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gBariWaitingAnim, -3.0f);
    pthis->leftArmCollider.dim.quad[2] = pthis->leftArmCollider.dim.quad[3] = pthis->rightArmCollider.dim.quad[2] =
        pthis->rightArmCollider.dim.quad[3] = pthis->leftArmCollider.dim.quad[0] = pthis->leftArmCollider.dim.quad[1] =
            pthis->rightArmCollider.dim.quad[0] = pthis->rightArmCollider.dim.quad[1] = pthis->actor.world.pos;

    pthis->leftArmCollider.dim.quad[2].y = pthis->leftArmCollider.dim.quad[3].y = pthis->rightArmCollider.dim.quad[2].y =
        pthis->rightArmCollider.dim.quad[3].y = pthis->leftArmCollider.dim.quad[0].y =
            pthis->leftArmCollider.dim.quad[1].y = pthis->rightArmCollider.dim.quad[0].y =
                pthis->rightArmCollider.dim.quad[1].y = pthis->actor.world.pos.y - 10.0f;

    pthis->actor.flags &= ~ACTOR_FLAG_4;
    pthis->bodyCollider.base.acFlags |= AC_ON;
    pthis->slingshotReactionTimer = 0;
    pthis->floatHomeHeight = pthis->actor.world.pos.y;
    pthis->actionFunc = EnVali_FloatIdle;
}

/**
 * Used for both touching player/player's shield and being hit with sword. What to do next is determined by params.
 */
void EnVali_SetupAttacked(EnVali* pthis) {
    pthis->lightningTimer = 20;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnVali_Attacked;
}

void EnVali_SetupRetaliate(EnVali* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBariRetaliatingAnim, -5.0f);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 150, 0x2000, 30);
    pthis->actor.params = BARI_TYPE_NORMAL;
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnVali_Retaliate;
}

void EnVali_SetupMoveArmsDown(EnVali* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gBariMovingArmsDownAnim);
    pthis->actionFunc = EnVali_MoveArmsDown;
}

void EnVali_SetupBurnt(EnVali* pthis) {
    pthis->timer = 2;
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 150, 0x2000, 30);
    pthis->actionFunc = EnVali_Burnt;
}

void EnVali_SetupDivideAndDie(EnVali* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BILI, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                    pthis->actor.world.pos.z, 0, pthis->actor.world.rot.y, 0, 0);

        pthis->actor.world.rot.y += 0x10000 / 3;
    }

    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x50);
    pthis->timer = Rand_S16Offset(10, 10);
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_BARI_SPLIT);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.draw = NULL;
    pthis->actionFunc = EnVali_DivideAndDie;
}

void EnVali_SetupStunned(EnVali* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBariWaitingAnim, 10.0f);
    pthis->timer = 80;
    pthis->actor.velocity.y = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 255, 0x2000, 80);
    pthis->bodyCollider.info.bumper.effect = 0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actor.velocity.y = 1.0f;
    pthis->actionFunc = EnVali_Stunned;
}

void EnVali_SetupFrozen(EnVali* pthis) {
    pthis->actor.velocity.y = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 255, 0x2000, 36);
    pthis->bodyCollider.base.acFlags &= ~AC_ON;
    pthis->timer = 36;
    pthis->actionFunc = EnVali_Frozen;
}

void EnVali_SetupReturnToLurk(EnVali* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gBariLurkingAnim, 10.0f);
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnVali_ReturnToLurk;
}

void EnVali_DischargeLightning(EnVali* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    s32 i;
    f32 cos;
    f32 sin;
    s16 yaw;

    for (i = 0; i < 4; i++) {
        cos = -Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)));
        sin = Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)));
        if (!((pthis->lightningTimer + (i << 1)) % 4)) {
            yaw = (s16)Rand_CenteredFloat(12288.0f) + (i * 0x4000) + 0x2000;
            pos.x = pthis->actor.world.pos.x + (Math_SinS(yaw) * 12.0f * cos);
            pos.y = pthis->actor.world.pos.y - (Math_CosS(yaw) * 12.0f) + 10.0f;
            pos.z = pthis->actor.world.pos.z + (Math_SinS(yaw) * 12.0f * sin);

            EffectSsLightning_Spawn(globalCtx, &pos, &primColor_61, &envColor_61, 17, yaw, 6, 2);
        }
    }

    func_8002F974(&pthis->actor, NA_SE_EN_BIRI_SPARK - SFX_FLAG);
}

void EnVali_Lurk(EnVali* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer < 150.0f) {
        EnVali_SetupDropAppear(pthis);
    }
}

void EnVali_DropAppear(EnVali* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.velocity.y *= 1.5f;
    pthis->actor.velocity.y = CLAMP_MAX(pthis->actor.velocity.y, 40.0f);

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, pthis->actor.velocity.y)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        EnVali_SetupFloatIdle(pthis);
    }
}

void EnVali_FloatIdle(EnVali* pthis, GlobalContext* globalCtx) {
    s32 curFrame;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->slingshotReactionTimer != 0) {
        pthis->slingshotReactionTimer--;
    }

    curFrame = pthis->skelAnime.curFrame;

    Math_StepToF(&pthis->floatHomeHeight, pthis->actor.floorHeight + 40.0f, 1.2f);
    pthis->actor.world.pos.y = pthis->floatHomeHeight - (sinf(curFrame * M_PI * 0.0125f) * 8.0f);

    if (pthis->slingshotReactionTimer) {
        pthis->actor.shape.rot.y += 0x800;

        if (((pthis->slingshotReactionTimer % 6) == 0) && (curFrame > 15) && (curFrame <= 55)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BARI_ROLL);
        }
    } else if ((curFrame == 16) || (curFrame == 30) || (curFrame == 42) || (curFrame == 55)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BARI_ROLL);
    }

    curFrame = ((curFrame > 40) ? (80 - curFrame) : curFrame);

    pthis->actor.shape.rot.y += (s16)((curFrame + 4) * 0.4f * (0x10000 / 360.0f));
    if (pthis->actor.xzDistToPlayer > 250.0f) {
        EnVali_SetupReturnToLurk(pthis);
    }
}

void EnVali_Attacked(EnVali* pthis, GlobalContext* globalCtx) {
    if (pthis->lightningTimer != 0) {
        pthis->lightningTimer--;
    }

    EnVali_DischargeLightning(pthis, globalCtx);

    if (pthis->lightningTimer == 0) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->bodyCollider.base.acFlags |= AC_ON;
        if (pthis->actor.params == BARI_TYPE_SWORD_DAMAGE) {
            EnVali_SetupRetaliate(pthis);
        } else {
            pthis->actionFunc = EnVali_FloatIdle;
        }
    } else if ((pthis->lightningTimer % 2) != 0) {
        pthis->actor.world.pos.y += 1.0f;
    } else {
        pthis->actor.world.pos.y -= 1.0f;
    }
}

void EnVali_Retaliate(EnVali* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.colChkInfo.health != 0) {
            EnVali_SetupMoveArmsDown(pthis);
        } else {
            EnVali_SetupDivideAndDie(pthis, globalCtx);
        }
    }
}

void EnVali_MoveArmsDown(EnVali* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnVali_SetupFloatIdle(pthis);
    }
}

void EnVali_Burnt(EnVali* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        EnVali_SetupDivideAndDie(pthis, globalCtx);
    }
}

void EnVali_DivideAndDie(EnVali* pthis, GlobalContext* globalCtx) {
    s16 scale;
    Vec3f pos;
    s32 i;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    for (i = 0; i < 2; i++) {
        pos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(20.0f);
        pos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(8.0f);
        pos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(20.0f);
        velocity_69.y = (Rand_ZeroOne() + 1.0f);
        scale = Rand_S16Offset(40, 40);

        if (Rand_ZeroOne() < 0.7f) {
            EffectSsDtBubble_SpawnColorProfile(globalCtx, &pos, &velocity_69, &accel_69, scale, 25, 2, 1);
        } else {
            EffectSsDtBubble_SpawnColorProfile(globalCtx, &pos, &velocity_69, &accel_69, scale, 25, 0, 1);
        }
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnVali_Stunned(EnVali* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->actor.velocity.y != 0.0f) {
        if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, pthis->actor.velocity.y)) {
            pthis->actor.velocity.y = 0.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        } else {
            pthis->actor.velocity.y += 1.0f;
        }
    }

    if (pthis->timer == 0) {
        pthis->bodyCollider.info.bumper.effect = 1; // Shock?
        EnVali_SetupFloatIdle(pthis);
    }
}

void EnVali_Frozen(EnVali* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    s32 temp_v0;
    s32 temp_v1;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    temp_v1 = pthis->timer - 20;
    pthis->actor.colorFilterTimer = 36;

    if (temp_v1 > 0) {
        temp_v0 = temp_v1 >> 1;

        if ((pthis->timer % 2) != 0) {
            pos.y = pthis->actor.world.pos.y - 20.0f + (-temp_v0 * 5 + 40);
            pos.x = pthis->actor.world.pos.x + ((temp_v0 & 2) ? 12.0f : -12.0f);
            pos.z = pthis->actor.world.pos.z + ((temp_v0 & 1) ? 12.0f : -12.0f);

            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &pos, 150, 150, 150, 250, 235, 245, 255,
                                           (Rand_ZeroOne() * 0.2f) + 1.3f);
        }
    } else if (pthis->timer == 0) {
        pthis->actor.velocity.y += 1.0f;
        if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, pthis->actor.velocity.y)) {
            EnVali_SetupDivideAndDie(pthis, globalCtx);
            pthis->actor.colorFilterTimer = 0;
        }
    }
}

void EnVali_ReturnToLurk(EnVali* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.5f, 15.0f, 0.1f) < 0.01f) {
        EnVali_SetupLurk(pthis);
    }
}

void EnVali_UpdateDamage(EnVali* pthis, GlobalContext* globalCtx) {
    if (pthis->bodyCollider.base.acFlags & AC_HIT) {
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->bodyCollider.info, 1);

        if ((pthis->actor.colChkInfo.damageEffect != BARI_DMGEFF_NONE) || (pthis->actor.colChkInfo.damage != 0)) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BARI_DEAD);
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            } else if ((pthis->actor.colChkInfo.damageEffect != BARI_DMGEFF_STUN) &&
                       (pthis->actor.colChkInfo.damageEffect != BARI_DMGEFF_SLINGSHOT)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BARI_DAMAGE);
            }

            if (pthis->actor.colChkInfo.damageEffect == BARI_DMGEFF_STUN) {
                if (pthis->actionFunc != EnVali_Stunned) {
                    EnVali_SetupStunned(pthis);
                }
            } else if (pthis->actor.colChkInfo.damageEffect == BARI_DMGEFF_SWORD) {
                if (pthis->actionFunc != EnVali_Stunned) {
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 150, 0x2000, 30);
                    pthis->actor.params = BARI_TYPE_SWORD_DAMAGE;
                    EnVali_SetupAttacked(pthis);
                } else {
                    EnVali_SetupRetaliate(pthis);
                }
            } else if (pthis->actor.colChkInfo.damageEffect == BARI_DMGEFF_FIRE) {
                EnVali_SetupBurnt(pthis);
            } else if (pthis->actor.colChkInfo.damageEffect == BARI_DMGEFF_ICE) {
                EnVali_SetupFrozen(pthis);
            } else if (pthis->actor.colChkInfo.damageEffect == BARI_DMGEFF_SLINGSHOT) {
                if (pthis->slingshotReactionTimer == 0) {
                    pthis->slingshotReactionTimer = 20;
                }
            } else {
                EnVali_SetupRetaliate(pthis);
            }
        }
    }
}

void EnVali_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnVali* pthis = (EnVali*)thisx;

    if ((pthis->bodyCollider.base.atFlags & AT_HIT) || (pthis->leftArmCollider.base.atFlags & AT_HIT) ||
        (pthis->rightArmCollider.base.atFlags & AT_HIT)) {
        pthis->leftArmCollider.base.atFlags &= ~AT_HIT;
        pthis->rightArmCollider.base.atFlags &= ~AT_HIT;
        pthis->bodyCollider.base.atFlags &= ~AT_HIT;
        EnVali_SetupAttacked(pthis);
    }

    EnVali_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if ((pthis->actionFunc != EnVali_DivideAndDie) && (pthis->actionFunc != EnVali_Lurk)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);

        if (pthis->actionFunc == EnVali_FloatIdle) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->leftArmCollider.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->rightArmCollider.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
        }

        if (pthis->bodyCollider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
        }

        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
        Actor_SetFocus(&pthis->actor, 0.0f);
    }
}

// Draw and associated functions

void EnVali_PulseOutside(EnVali* pthis, f32 curFrame, Vec3f* scale) {
    f32 scaleChange;

    if (pthis->actionFunc == EnVali_Attacked) {
        s32 scalePhase = 20 - (pthis->lightningTimer % 20);

        if (scalePhase >= 10) {
            scalePhase -= 10;
        }

        scale->y -= 0.2f * sinf((M_PI / 10) * scalePhase);
    } else if (pthis->actionFunc == EnVali_Retaliate) {
        scaleChange = sinf((M_PI / 10) * curFrame);
        scale->y -= 0.24f * scaleChange;
        scale->x -= 0.13f * scaleChange;
        scale->z = scale->x;
    } else if (pthis->actionFunc == EnVali_MoveArmsDown) {
        scaleChange = cosf((M_PI / 50) * curFrame);
        scale->y -= 0.24f * scaleChange;
        scale->x -= 0.13f * scaleChange;
        scale->z = scale->x;
    } else if (pthis->actionFunc == EnVali_Stunned) {
        scaleChange = sinf((M_PI / 10) * pthis->timer) * 0.08f;
        scale->x += scaleChange;
        scale->y -= scaleChange;
        scale->z += scaleChange;
    } else {
        if (curFrame >= 40.0f) {
            curFrame -= 40.0f;
        }

        scale->y -= 0.2f * sinf((M_PI / 40) * curFrame);
    }
}

void EnVali_PulseInsides(EnVali* pthis, f32 curFrame, Vec3f* scale) {
    f32 scaleChange;

    if (pthis->actionFunc == EnVali_Attacked) {
        s32 scalePhase = 20 - (pthis->lightningTimer % 20);

        if (scalePhase >= 10) {
            scalePhase -= 10;
        }

        scale->y -= 0.13f * sinf((M_PI / 10) * scalePhase);
    } else if (pthis->actionFunc == EnVali_Retaliate) {
        scaleChange = sinf((M_PI / 10) * curFrame);
        scale->y -= 0.18f * scaleChange;
        scale->x -= 0.1f * scaleChange;
        scale->z = scale->x;
    } else if (pthis->actionFunc == EnVali_MoveArmsDown) {
        scaleChange = cosf((M_PI / 50) * curFrame);
        scale->y -= 0.18f * scaleChange;
        scale->x -= 0.1f * scaleChange;
        scale->z = scale->x;
    } else if (pthis->actionFunc == EnVali_Stunned) {
        scaleChange = sinf((M_PI / 10) * pthis->timer) * 0.08f;
        scale->x -= scaleChange;
        scale->y += scaleChange;
        scale->z -= scaleChange;
    } else {
        if (curFrame >= 40.0f) {
            curFrame -= 40.0f;
        }

        scale->y -= 0.13f * sinf((M_PI / 40) * curFrame);
    }
}

s32 EnVali_SetArmLength(EnVali* pthis, f32 curFrame) {
    f32 targetArmScale;

    if (pthis->actionFunc == EnVali_FloatIdle) {
        if (curFrame <= 10.0f) {
            targetArmScale = curFrame * 0.05f + 1.0f;
        } else if (curFrame > 70.0f) {
            targetArmScale = (80.0f - curFrame) * 0.05f + 1.0f;
        } else {
            targetArmScale = 1.5f;
        }
    } else if (pthis->actionFunc == EnVali_Retaliate) {
        targetArmScale = 1.0f - sinf((M_PI / 10) * curFrame) * 0.35f;
    } else if (pthis->actionFunc == EnVali_MoveArmsDown) {
        targetArmScale = 1.0f - cosf((M_PI / 50) * curFrame) * 0.35f;
    } else if ((pthis->actionFunc == EnVali_Attacked) || (pthis->actionFunc == EnVali_Frozen)) {
        targetArmScale = pthis->armScale;
    } else {
        targetArmScale = 1.0f;
    }

    Math_StepToF(&pthis->armScale, targetArmScale, 0.1f);

    if (pthis->armScale == 1.0f) {
        return false;
    } else {
        return true;
    }
}

s32 EnVali_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                            Gfx** gfx) {
    EnVali* pthis = (EnVali*)thisx;
    f32 curFrame;

    if ((limbIndex == EN_VALI_LIMB_NUCLEUS) || (limbIndex == EN_VALI_LIMB_OUTER_HOOD) ||
        (limbIndex == EN_VALI_LIMB_INNER_HOOD)) {
        *dList = NULL;
        return false;
    } else {
        curFrame = pthis->skelAnime.curFrame;

        if ((limbIndex == EN_VALI_LIMB_LEFT_ARM_BASE) || (limbIndex == EN_VALI_LIMB_RIGHT_ARM_BASE)) {
            if (EnVali_SetArmLength(pthis, curFrame)) {
                Matrix_Scale(pthis->armScale, 1.0f, 1.0f, MTXMODE_APPLY);
            }
        }

        return false;
    }
}

void EnVali_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    Vec3f sp3C;
    Vec3f sp30;
    EnVali* pthis = (EnVali*)thisx;

    if (pthis->actionFunc == EnVali_FloatIdle) {
        if ((limbIndex == EN_VALI_LIMB_LEFT_FOREARM_BASE) || (limbIndex == EN_VALI_LIMB_RIGHT_FOREARM_BASE)) {
            Matrix_MultVec3f(&D_80B28970_80, &sp3C);
            Matrix_MultVec3f(&D_80B2897C_80, &sp30);

            if (limbIndex == EN_VALI_LIMB_LEFT_FOREARM_BASE) {
                Collider_SetQuadVertices(&pthis->leftArmCollider, &sp30, &sp3C, &pthis->leftArmCollider.dim.quad[0],
                                         &pthis->leftArmCollider.dim.quad[1]);
            } else {
                Collider_SetQuadVertices(&pthis->rightArmCollider, &sp30, &sp3C, &pthis->rightArmCollider.dim.quad[0],
                                         &pthis->rightArmCollider.dim.quad[1]);
            }
        }
    }
}

void EnVali_DrawBody(EnVali* pthis, GlobalContext* globalCtx) {
    MtxF mtx;
    f32 cos;
    f32 sin;
    f32 curFrame;
    Vec3f scale = { 1.0f, 1.0f, 1.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 1428);

    Matrix_Get(&mtx);
    curFrame = pthis->skelAnime.curFrame;
    EnVali_PulseInsides(pthis, curFrame, &scale);
    Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 1436),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBariInnerHoodDL);

    Matrix_Put(&mtx);
    Matrix_RotateY(-pthis->actor.shape.rot.y * (M_PI / 32768.0f), MTXMODE_APPLY);

    cos = Math_CosS(pthis->actor.shape.rot.y);
    sin = Math_SinS(pthis->actor.shape.rot.y);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 1446),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBariNucleusDL);

    Matrix_Translate((506.0f * cos) + (372.0f * sin), 1114.0f, (372.0f * cos) - (506.0f * sin), MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 1455),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBariNucleusDL);

    Matrix_Translate((-964.0f * cos) - (804.0f * sin), -108.0f, (-804.0f * cos) + (964.0f * sin), MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 1463),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBariNucleusDL);

    Matrix_Put(&mtx);

    scale.x = scale.y = scale.z = 1.0f;

    EnVali_PulseOutside(pthis, curFrame, &scale);
    Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_vali.c", 1471),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBariOuterHoodDL);

    Matrix_Put(&mtx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 1477);
}

static Gfx D_80B28998[] = {
    gsDPSetCombineLERP(1, TEXEL0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0, TEXEL1, 0,
                       PRIM_LOD_FRAC, COMBINED),
    gsSPEndDisplayList(),
};

static Gfx D_80B289A8[] = {
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0, TEXEL1, 0,
                       PRIM_LOD_FRAC, COMBINED),
    gsSPEndDisplayList(),
};

void EnVali_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnVali* pthis = (EnVali*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 1505);
    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TexScroll(globalCtx->state.gfxCtx, 0, (127 - (globalCtx->gameplayFrames * 12)) % 128, 32, 32));

    if ((pthis->lightningTimer % 2) != 0) {
        gSPSegment(POLY_XLU_DISP++, 0x09, D_80B28998);
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x09, D_80B289A8);
    }

    EnVali_DrawBody(pthis, globalCtx);

    POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                   EnVali_OverrideLimbDraw, EnVali_PostLimbDraw, pthis, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_vali.c", 1538);
}

void EnVali_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    primColor_61 = { 255, 255, 255, 255 };

    envColor_61 = { 200, 255, 255, 255 };

    velocity_69 = { 0.0f, 0.0f, 0.0f };

    accel_69 = { 0.0f, 0.0f, 0.0f };

    D_80B28970_80 = { 3000.0f, 0.0f, 0.0f };

    D_80B2897C_80 = { -1000.0f, 0.0f, 0.0f };

    En_Vali_InitVars = {
        ACTOR_EN_VALI,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_VALI,
        sizeof(EnVali),
        (ActorFunc)EnVali_Init,
        (ActorFunc)EnVali_Destroy,
        (ActorFunc)EnVali_Update,
        (ActorFunc)EnVali_Draw,
        (ActorFunc)EnVali_Reset,
    };

    sQuadInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_NONE,
            OC2_TYPE_1,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x07, 0x08 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
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
            { 0xFFCFFFFF, 0x07, 0x08 },
            { 0xFFCFFFFF, 0x01, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 17, 35, -15, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 2, 18, 32, MASS_HEAVY };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, BARI_DMGEFF_STUN),
        /* Deku stick    */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(0, BARI_DMGEFF_SLINGSHOT),
        /* Explosive     */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(0, BARI_DMGEFF_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Hookshot      */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Kokiri sword  */ DMG_ENTRY(1, BARI_DMGEFF_SWORD),
        /* Master sword  */ DMG_ENTRY(2, BARI_DMGEFF_SWORD),
        /* Giant's Knife */ DMG_ENTRY(4, BARI_DMGEFF_SWORD),
        /* Fire arrow    */ DMG_ENTRY(4, BARI_DMGEFF_FIRE),
        /* Ice arrow     */ DMG_ENTRY(4, BARI_DMGEFF_ICE),
        /* Light arrow   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Unk arrow 1   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(4, BARI_DMGEFF_FIRE),
        /* Ice magic     */ DMG_ENTRY(4, BARI_DMGEFF_ICE),
        /* Light magic   */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
        /* Shield        */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, BARI_DMGEFF_NONE),
        /* Giant spin    */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
        /* Master spin   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Kokiri jump   */ DMG_ENTRY(2, BARI_DMGEFF_NONE),
        /* Giant jump    */ DMG_ENTRY(8, BARI_DMGEFF_NONE),
        /* Master jump   */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
        /* Unknown 1     */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, BARI_DMGEFF_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, BARI_DMGEFF_NONE),
    };

}

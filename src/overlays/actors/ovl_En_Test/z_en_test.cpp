#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TEST_Z_EN_TEST_C
#include "actor_common.h"
/*
 * File: z_en_test.c
 * Overlay: ovl_En_Test
 * Description: Stalfos
 */

#include "z_en_test.h"
#include "objects/object_sk2/object_sk2.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnTest_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTest_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTest_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTest_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnTest_SetupWaitGround(EnTest* pthis);
void EnTest_SetupWaitAbove(EnTest* pthis);
void EnTest_SetupJumpBack(EnTest* pthis);
void EnTest_SetupSlashDownEnd(EnTest* pthis);
void EnTest_SetupSlashUp(EnTest* pthis);
void EnTest_SetupJumpslash(EnTest* pthis);
void EnTest_SetupWalkAndBlock(EnTest* pthis);
void func_80860EC0(EnTest* pthis);
void EnTest_SetupSlashDown(EnTest* pthis);
void func_80860BDC(EnTest* pthis);
void EnTest_SetupIdleFromBlock(EnTest* pthis);
void EnTest_SetupRecoil(EnTest* pthis);
void func_80862398(EnTest* pthis);
void func_80862154(EnTest* pthis);
void EnTest_SetupStopAndBlock(EnTest* pthis);
void func_808627C4(EnTest* pthis, GlobalContext* globalCtx);

void EnTest_WaitGround(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_WaitAbove(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Fall(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Land(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Rise(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Idle(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_WalkAndBlock(EnTest* pthis, GlobalContext* globalCtx);
void func_80860C24(EnTest* pthis, GlobalContext* globalCtx);
void func_80860F84(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_SlashDown(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_SlashDownEnd(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_SlashUp(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_JumpBack(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Jumpslash(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_JumpUp(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_StopAndBlock(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_IdleFromBlock(EnTest* pthis, GlobalContext* globalCtx);
void func_808621D4(EnTest* pthis, GlobalContext* globalCtx);
void func_80862418(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Stunned(EnTest* pthis, GlobalContext* globalCtx);
void func_808628C8(EnTest* pthis, GlobalContext* globalCtx);
void func_80862E6C(EnTest* pthis, GlobalContext* globalCtx);
void func_80863044(EnTest* pthis, GlobalContext* globalCtx);
void func_8086318C(EnTest* pthis, GlobalContext* globalCtx);
void EnTest_Recoil(EnTest* pthis, GlobalContext* globalCtx);
void func_808633E8(EnTest* pthis, GlobalContext* globalCtx);
void func_80862FA8(EnTest* pthis, GlobalContext* globalCtx);

s32 EnTest_ReactToProjectile(GlobalContext* globalCtx, EnTest* pthis);

static u8 sJointCopyFlags[] = {
    false, // STALFOS_LIMB_NONE
    false, // STALFOS_LIMB_ROOT
    false, // STALFOS_LIMB_UPPERBODY_ROOT
    false, // STALFOS_LIMB_CORE_LOWER_ROOT
    true,  // STALFOS_LIMB_CORE_UPPER_ROOT
    true,  // STALFOS_LIMB_NECK_ROOT
    true,  // STALFOS_LIMB_HEAD_ROOT
    true,  // STALFOS_LIMB_7
    true,  // STALFOS_LIMB_8
    true,  // STALFOS_LIMB_JAW_ROOT
    true,  // STALFOS_LIMB_JAW
    true,  // STALFOS_LIMB_HEAD
    true,  // STALFOS_LIMB_NECK_UPPER
    true,  // STALFOS_LIMB_NECK_LOWER
    true,  // STALFOS_LIMB_CORE_UPPER
    true,  // STALFOS_LIMB_CHEST
    true,  // STALFOS_LIMB_SHOULDER_R_ROOT
    true,  // STALFOS_LIMB_SHOULDER_ARMOR_R_ROOT
    true,  // STALFOS_LIMB_SHOULDER_ARMOR_R
    true,  // STALFOS_LIMB_SHOULDER_L_ROOT
    true,  // STALFOS_LIMB_SHOULDER_ARMOR_L_ROOT
    true,  // STALFOS_LIMB_SHOULDER_ARMOR_L
    true,  // STALFOS_LIMB_ARM_L_ROOT
    true,  // STALFOS_LIMB_UPPERARM_L_ROOT
    true,  // STALFOS_LIMB_FOREARM_L_ROOT
    true,  // STALFOS_LIMB_HAND_L_ROOT
    true,  // STALFOS_LIMB_HAND_L
    true,  // STALFOS_LIMB_SHIELD
    true,  // STALFOS_LIMB_FOREARM_L
    true,  // STALFOS_LIMB_UPPERARM_L
    true,  // STALFOS_LIMB_ARM_R_ROOT
    true,  // STALFOS_LIMB_UPPERARM_R_ROOT
    true,  // STALFOS_LIMB_FOREARM_R_ROOT
    true,  // STALFOS_LIMB_HAND_R_ROOT
    true,  // STALFOS_LIMB_SWORD
    true,  // STALFOS_LIMB_HAND_R
    true,  // STALFOS_LIMB_FOREARM_R
    true,  // STALFOS_LIMB_UPPERARM_R
    true,  // STALFOS_LIMB_CORE_LOWER
    false, // STALFOS_LIMB_LOWERBODY_ROOT
    false, // STALFOS_LIMB_WAIST_ROOT
    false, // STALFOS_LIMB_LEGS_ROOT
    false, // STALFOS_LIMB_LEG_L_ROOT
    false, // STALFOS_LIMB_THIGH_L_ROOT
    false, // STALFOS_LIMB_LOWERLEG_L_ROOT
    false, // STALFOS_LIMB_ANKLE_L_ROOT
    false, // STALFOS_LIMB_ANKLE_L
    false, // STALFOS_LIMB_FOOT_L_ROOT
    false, // STALFOS_LIMB_FOOT_L
    false, // STALFOS_LIMB_LOWERLEG_L
    false, // STALFOS_LIMB_THIGH_L
    false, // STALFOS_LIMB_LEG_R_ROOT
    false, // STALFOS_LIMB_THIGH_R_ROOT
    false, // STALFOS_LIMB_LOWERLEG_R_ROOT
    false, // STALFOS_LIMB_ANKLE_R_ROOT
    false, // STALFOS_LIMB_ANKLE_R
    false, // STALFOS_LIMB_FOOT_R_ROOT
    false, // STALFOS_LIMB_FOOT_R
    false, // STALFOS_LIMB_LOWERLEG_R
    false, // STALFOS_LIMB_THIGH_R
    false, // STALFOS_LIMB_WAIST
};

ActorInit En_Test_InitVars = {
    ACTOR_EN_TEST,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SK2,
    sizeof(EnTest),
    (ActorFunc)EnTest_Init,
    (ActorFunc)EnTest_Destroy,
    (ActorFunc)EnTest_Update,
    (ActorFunc)EnTest_Draw,
};

static ColliderCylinderInit sBodyColliderInit = {
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
    { 25, 65, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sShieldColliderInit = {
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
        { 0xFFC1FFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 20, 70, -50, { 0, 0, 0 } },
};

static ColliderQuadInit sSwordColliderInit = {
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
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

typedef enum {
    /* 0x0 */ STALFOS_DMGEFF_NORMAL,
    /* 0x1 */ STALFOS_DMGEFF_STUN,
    /* 0x6 */ STALFOS_DMGEFF_FIREMAGIC = 6,
    /* 0xD */ STALFOS_DMGEFF_SLING = 0xD,
    /* 0xE */ STALFOS_DMGEFF_LIGHT,
    /* 0xF */ STALFOS_DMGEFF_FREEZE
} StalfosDamageEffect;

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, STALFOS_DMGEFF_STUN),
    /* Deku stick    */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Slingshot     */ DMG_ENTRY(1, STALFOS_DMGEFF_SLING),
    /* Explosive     */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Boomerang     */ DMG_ENTRY(0, STALFOS_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Hammer swing  */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Hookshot      */ DMG_ENTRY(0, STALFOS_DMGEFF_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, STALFOS_DMGEFF_NORMAL),
    /* Master sword  */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Giant's Knife */ DMG_ENTRY(4, STALFOS_DMGEFF_NORMAL),
    /* Fire arrow    */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Ice arrow     */ DMG_ENTRY(4, STALFOS_DMGEFF_FREEZE),
    /* Light arrow   */ DMG_ENTRY(2, STALFOS_DMGEFF_LIGHT),
    /* Unk arrow 1   */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Unk arrow 2   */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Unk arrow 3   */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Fire magic    */ DMG_ENTRY(0, STALFOS_DMGEFF_FIREMAGIC),
    /* Ice magic     */ DMG_ENTRY(3, STALFOS_DMGEFF_FREEZE),
    /* Light magic   */ DMG_ENTRY(0, STALFOS_DMGEFF_LIGHT),
    /* Shield        */ DMG_ENTRY(0, STALFOS_DMGEFF_NORMAL),
    /* Mirror Ray    */ DMG_ENTRY(0, STALFOS_DMGEFF_NORMAL),
    /* Kokiri spin   */ DMG_ENTRY(1, STALFOS_DMGEFF_NORMAL),
    /* Giant spin    */ DMG_ENTRY(4, STALFOS_DMGEFF_NORMAL),
    /* Master spin   */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Kokiri jump   */ DMG_ENTRY(2, STALFOS_DMGEFF_NORMAL),
    /* Giant jump    */ DMG_ENTRY(8, STALFOS_DMGEFF_NORMAL),
    /* Master jump   */ DMG_ENTRY(4, STALFOS_DMGEFF_NORMAL),
    /* Unknown 1     */ DMG_ENTRY(0, STALFOS_DMGEFF_NORMAL),
    /* Unblockable   */ DMG_ENTRY(0, STALFOS_DMGEFF_NORMAL),
    /* Hammer jump   */ DMG_ENTRY(4, STALFOS_DMGEFF_NORMAL),
    /* Unknown 2     */ DMG_ENTRY(0, STALFOS_DMGEFF_NORMAL),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x1B, ICHAIN_CONTINUE),    ICHAIN_F32(targetArrowOffset, 500, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 15, ICHAIN_CONTINUE), ICHAIN_F32(scale.y, 0, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -1500, ICHAIN_STOP),
};

void EnTest_SetupAction(EnTest* pthis, EnTestActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnTest_Init(Actor* thisx, GlobalContext* globalCtx) {
    EffectBlureInit1 slashBlure;
    EnTest* pthis = (EnTest*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gStalfosSkel, &gStalfosMiddleGuardAnim, pthis->jointTable,
                   pthis->morphTable, STALFOS_LIMB_MAX);
    SkelAnime_Init(globalCtx, &pthis->upperSkelanime, &gStalfosSkel, &gStalfosMiddleGuardAnim, pthis->upperJointTable,
                   pthis->upperMorphTable, STALFOS_LIMB_MAX);

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawFeet, 90.0f);

    pthis->actor.colChkInfo.cylRadius = 40;
    pthis->actor.colChkInfo.cylHeight = 100;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 45.0f;
    pthis->actor.colChkInfo.damageTable = &sDamageTable;

    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, &pthis->actor, &sBodyColliderInit);

    Collider_InitCylinder(globalCtx, &pthis->shieldCollider);
    Collider_SetCylinder(globalCtx, &pthis->shieldCollider, &pthis->actor, &sShieldColliderInit);

    Collider_InitQuad(globalCtx, &pthis->swordCollider);
    Collider_SetQuad(globalCtx, &pthis->swordCollider, &pthis->actor, &sSwordColliderInit);

    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.health = 10;

    slashBlure.p1StartColor[0] = slashBlure.p1StartColor[1] = slashBlure.p1StartColor[2] = slashBlure.p1StartColor[3] =
        slashBlure.p2StartColor[0] = slashBlure.p2StartColor[1] = slashBlure.p2StartColor[2] =
            slashBlure.p1EndColor[0] = slashBlure.p1EndColor[1] = slashBlure.p1EndColor[2] = slashBlure.p2EndColor[0] =
                slashBlure.p2EndColor[1] = slashBlure.p2EndColor[2] = 255;

    slashBlure.p1EndColor[3] = 0;
    slashBlure.p2EndColor[3] = 0;
    slashBlure.p2StartColor[3] = 64;

    slashBlure.elemDuration = 4;
    slashBlure.unkFlag = 0;
    slashBlure.calcMode = 2;

    Effect_Add(globalCtx, &pthis->effectIndex, EFFECT_BLURE1, 0, 0, &slashBlure);

    if (pthis->actor.params != STALFOS_TYPE_CEILING) {
        EnTest_SetupWaitGround(pthis);
    } else {
        EnTest_SetupWaitAbove(pthis);
    }

    if (pthis->actor.params == STALFOS_TYPE_INVISIBLE) {
        pthis->actor.flags |= ACTOR_FLAG_7;
    }
}

void EnTest_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTest* pthis = (EnTest*)thisx;

    if ((pthis->actor.params != STALFOS_TYPE_2) &&
        !Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_TEST, ACTORCAT_ENEMY, 8000.0f)) {
        func_800F5B58();
    }

    Effect_Delete(globalCtx, pthis->effectIndex);
    Collider_DestroyCylinder(globalCtx, &pthis->shieldCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyQuad(globalCtx, &pthis->swordCollider);
}

/**
 * If EnTest_ChooseAction failed to pick a new action, pthis function will unconditionally pick
 * a new action as a last resort
 */
void EnTest_ChooseRandomAction(EnTest* pthis, GlobalContext* globalCtx) {
    switch ((u32)(Rand_ZeroOne() * 10.0f)) {
        case 0:
        case 1:
        case 5:
        case 6:
            if ((pthis->actor.xzDistToPlayer < 220.0f) && (pthis->actor.xzDistToPlayer > 170.0f) &&
                Actor_IsFacingPlayer(&pthis->actor, 0x71C) && Actor_IsTargeted(globalCtx, &pthis->actor)) {
                EnTest_SetupJumpslash(pthis);
                break;
            }
            // fallthrough
        case 8:
            EnTest_SetupWalkAndBlock(pthis);
            break;

        case 3:
        case 4:
        case 7:
            func_808627C4(pthis, globalCtx);
            break;

        case 2:
        case 9:
        case 10:
            EnTest_SetupStopAndBlock(pthis);
            break;
    }
}

void EnTest_ChooseAction(EnTest* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

    yawDiff = ABS(yawDiff);

    if (yawDiff >= 0x61A8) {
        switch ((u32)(Rand_ZeroOne() * 10.0f)) {
            case 0:
            case 3:
            case 7:
                EnTest_SetupStopAndBlock(pthis);
                break;

            case 1:
            case 5:
            case 6:
            case 8:
                func_808627C4(pthis, globalCtx);
                break;

            case 2:
            case 4:
            case 9:
                if (pthis->actor.params != STALFOS_TYPE_CEILING) {
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                    EnTest_SetupJumpBack(pthis);
                }
                break;
        }
    } else if (yawDiff <= 0x3E80) {
        if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) > 0x3E80) {
            if (((globalCtx->gameplayFrames % 2) != 0) && (pthis->actor.params != STALFOS_TYPE_CEILING)) {
                pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                EnTest_SetupJumpBack(pthis);
            } else if ((pthis->actor.xzDistToPlayer < 220.0f) && (pthis->actor.xzDistToPlayer > 170.0f)) {
                if (Actor_IsFacingPlayer(&pthis->actor, 0x71C) && !Actor_IsTargeted(globalCtx, &pthis->actor)) {
                    EnTest_SetupJumpslash(pthis);
                }
            } else {
                EnTest_SetupWalkAndBlock(pthis);
            }
        } else {
            if (pthis->actor.xzDistToPlayer < 110.0f) {
                if (Rand_ZeroOne() > 0.2f) {
                    if (player->stateFlags1 & 0x10) {
                        if (pthis->actor.isTargeted) {
                            EnTest_SetupSlashDown(pthis);
                        } else {
                            func_808627C4(pthis, globalCtx);
                        }
                    } else {
                        EnTest_SetupSlashDown(pthis);
                    }
                }
            } else {
                EnTest_ChooseRandomAction(pthis, globalCtx);
            }
        }
    } else {
        EnTest_ChooseRandomAction(pthis, globalCtx);
    }
}

void EnTest_SetupWaitGround(EnTest* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosMiddleGuardAnim);
    pthis->unk_7C8 = 0;
    pthis->timer = 15;
    pthis->actor.scale.y = 0.0f;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y - 3.5f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnTest_SetupAction(pthis, EnTest_WaitGround);
}

void EnTest_WaitGround(EnTest* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->timer == 0) && (ABS(pthis->actor.yDistToPlayer) < 150.0f)) {
        pthis->unk_7C8 = 3;
        EnTest_SetupAction(pthis, EnTest_Rise);
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;

        if (pthis->actor.params != STALFOS_TYPE_2) {
            func_800F5ACC(NA_BGM_MINI_BOSS);
        }
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        pthis->actor.world.pos.y = pthis->actor.home.pos.y - 3.5f;
    }
}

void EnTest_SetupWaitAbove(EnTest* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosMiddleGuardAnim);
    pthis->unk_7C8 = 0;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 150.0f;
    Actor_SetScale(&pthis->actor, 0.0f);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnTest_SetupAction(pthis, EnTest_WaitAbove);
}

void EnTest_WaitAbove(EnTest* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 150.0f;

    if ((pthis->actor.xzDistToPlayer < 200.0f) && (ABS(pthis->actor.yDistToPlayer) < 450.0f)) {
        EnTest_SetupAction(pthis, EnTest_Fall);
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        Actor_SetScale(&pthis->actor, 0.015f);
    }
}

void EnTest_SetupIdle(EnTest* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosMiddleGuardAnim);
    pthis->unk_7C8 = 0xA;
    pthis->timer = (Rand_ZeroOne() * 10.0f) + 5.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnTest_SetupAction(pthis, EnTest_Idle);
}

void EnTest_Idle(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff;

    SkelAnime_Update(&pthis->skelAnime);

    if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
        yawDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

        if (pthis->actor.xzDistToPlayer < 100.0f) {
            if ((player->swordState != 0) && (ABS(yawDiff) >= 0x1F40)) {
                pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

                if (Rand_ZeroOne() > 0.7f && player->swordAnimation != 0x11) {
                    EnTest_SetupJumpBack(pthis);
                } else {
                    func_808627C4(pthis, globalCtx);
                }
                return;
            }
        }

        if (pthis->timer != 0) {
            pthis->timer--;
        } else {
            if (Actor_IsFacingPlayer(&pthis->actor, 0x1555)) {
                if ((pthis->actor.xzDistToPlayer < 220.0f) && (pthis->actor.xzDistToPlayer > 160.0f) &&
                    (Rand_ZeroOne() < 0.3f)) {
                    if (Actor_IsTargeted(globalCtx, &pthis->actor)) {
                        EnTest_SetupJumpslash(pthis);
                    } else {
                        func_808627C4(pthis, globalCtx);
                    }
                } else {
                    if (Rand_ZeroOne() > 0.3f) {
                        EnTest_SetupWalkAndBlock(pthis);
                    } else {
                        func_808627C4(pthis, globalCtx);
                    }
                }
            } else {
                if (Rand_ZeroOne() > 0.7f) {
                    func_80860BDC(pthis);
                } else {
                    EnTest_ChooseAction(pthis, globalCtx);
                }
            }
        }
    }
}

void EnTest_Fall(EnTest* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gStalfosLandFromLeapAnim, 0.0f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.world.pos.y <= pthis->actor.floorHeight) {
        pthis->skelAnime.playSpeed = 1.0f;
        pthis->unk_7C8 = 0xC;
        pthis->timer = pthis->unk_7E4 * 0.15f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        EnTest_SetupAction(pthis, EnTest_Land);
    }
}

void EnTest_Land(EnTest* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnTest_SetupIdle(pthis);
        pthis->timer = (Rand_ZeroOne() * 10.0f) + 5.0f;
    }
}

void EnTest_SetupWalkAndBlock(EnTest* pthis) {
    Animation_Change(&pthis->upperSkelanime, &gStalfosBlockWithShieldAnim, 2.0f, 0.0f,
                     Animation_GetLastFrame(&gStalfosBlockWithShieldAnim), 2, 2.0f);
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosSlowAdvanceAnim);
    pthis->timer = (s16)(Rand_ZeroOne() * 5.0f);
    pthis->unk_7C8 = 0xD;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnTest_SetupAction(pthis, EnTest_WalkAndBlock);
}

void EnTest_WalkAndBlock(EnTest* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 checkDist = 0.0f;
    s32 pad1;
    s32 prevFrame;
    s32 temp_f16;
    f32 playSpeed;
    Player* player = GET_PLAYER(globalCtx);
    s32 absPlaySpeed;
    s16 yawDiff;

    if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
        pthis->timer++;

        if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            checkDist = 150.0f;
        }

        if (pthis->actor.xzDistToPlayer <= (80.0f + checkDist)) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, -5.0f, 1.0f, 0.8f, 0.0f);
        } else if (pthis->actor.xzDistToPlayer > (110.0f + checkDist)) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 5.0f, 1.0f, 0.8f, 0.0f);
        }

        if (pthis->actor.speedXZ >= 5.0f) {
            pthis->actor.speedXZ = 5.0f;
        } else if (pthis->actor.speedXZ < -5.0f) {
            pthis->actor.speedXZ = -5.0f;
        }

        if ((pthis->actor.params == STALFOS_TYPE_CEILING) &&
            !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.world.rot.y)) {
            pthis->actor.speedXZ *= -1.0f;
        }

        if (ABS(pthis->actor.speedXZ) < 3.0f) {
            Animation_Change(&pthis->skelAnime, &gStalfosSlowAdvanceAnim, 0.0f, pthis->skelAnime.curFrame,
                             Animation_GetLastFrame(&gStalfosSlowAdvanceAnim), 0, -6.0f);
            playSpeed = pthis->actor.speedXZ * 10.0f;
        } else {
            Animation_Change(&pthis->skelAnime, &gStalfosFastAdvanceAnim, 0.0f, pthis->skelAnime.curFrame,
                             Animation_GetLastFrame(&gStalfosFastAdvanceAnim), 0, -4.0f);
            playSpeed = pthis->actor.speedXZ * 10.0f * 0.02f;
        }

        if (pthis->actor.speedXZ >= 0.0f) {
            if (pthis->unk_7DE == 0) {
                pthis->unk_7DE++;
            }

            playSpeed = CLAMP_MAX(playSpeed, 2.5f);
            pthis->skelAnime.playSpeed = playSpeed;
        } else {
            playSpeed = CLAMP_MIN(playSpeed, -2.5f);
            pthis->skelAnime.playSpeed = playSpeed;
        }

        yawDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

        if ((pthis->actor.xzDistToPlayer < 100.0f) && (player->swordState != 0)) {
            if (ABS(yawDiff) >= 0x1F40) {
                pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

                if ((Rand_ZeroOne() > 0.7f) && (player->swordAnimation != 0x11)) {
                    EnTest_SetupJumpBack(pthis);
                } else {
                    EnTest_SetupStopAndBlock(pthis);
                }

                return;
            }
        }

        prevFrame = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);

        temp_f16 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        absPlaySpeed = (f32)ABS(pthis->skelAnime.playSpeed);

        if ((s32)pthis->skelAnime.curFrame != prevFrame) {
            s32 temp_v0_2 = absPlaySpeed + prevFrame;

            if (((temp_v0_2 > 1) && (temp_f16 <= 0)) || ((temp_f16 < 7) && (temp_v0_2 >= 8))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WALK);
            }
        }

        if ((pthis->timer % 32) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WARAU);
            pthis->timer += (s16)(Rand_ZeroOne() * 5.0f);
        }

        if ((pthis->actor.xzDistToPlayer < 220.0f) && (pthis->actor.xzDistToPlayer > 160.0f) &&
            (Actor_IsFacingPlayer(&pthis->actor, 0x71C))) {
            if (Actor_IsTargeted(globalCtx, &pthis->actor)) {
                if (Rand_ZeroOne() < 0.1f) {
                    EnTest_SetupJumpslash(pthis);
                    return;
                }
            } else if (player->heldItemActionParam != PLAYER_AP_NONE) {
                if (pthis->actor.isTargeted) {
                    if ((globalCtx->gameplayFrames % 2) != 0) {
                        func_808627C4(pthis, globalCtx);
                        return;
                    }

                    EnTest_ChooseAction(pthis, globalCtx);
                } else {
                    func_80860EC0(pthis);
                }
            }
        }

        if (Rand_ZeroOne() < 0.4f) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        }

        if (!Actor_IsFacingPlayer(&pthis->actor, 0x11C7)) {
            EnTest_SetupIdle(pthis);
            pthis->timer = (Rand_ZeroOne() * 10.0f) + 10.0f;
            return;
        }

        if (pthis->actor.xzDistToPlayer < 110.0f) {
            if (Rand_ZeroOne() > 0.2f) {
                if (player->stateFlags1 & 0x10) {
                    if (pthis->actor.isTargeted) {
                        EnTest_SetupSlashDown(pthis);
                    } else {
                        func_808627C4(pthis, globalCtx);
                    }
                } else {
                    EnTest_SetupSlashDown(pthis);
                }
            } else {
                EnTest_SetupStopAndBlock(pthis);
            }
        } else if (Rand_ZeroOne() < 0.1f) {
            pthis->actor.speedXZ = 5.0f;
        }
    }
}

// a variation of sidestep
void func_80860BDC(EnTest* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosSidestepAnim);
    pthis->unk_7C8 = 0xE;
    EnTest_SetupAction(pthis, func_80860C24);
}

// a variation of sidestep
void func_80860C24(EnTest* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;
    s16 yawChange;
    f32 playSpeed;
    s32 prevFrame;
    s32 temp1;
    s32 temp2;
    s32 absPlaySpeed;

    if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
        yawDiff = pthis->actor.yawTowardsPlayer;
        yawDiff -= pthis->actor.shape.rot.y;

        if (yawDiff > 0) {
            yawChange = (yawDiff / 42.0f) + 300.0f;
            pthis->actor.shape.rot.y += yawChange * 2;
        } else {
            yawChange = (yawDiff / 42.0f) - 300.0f;
            pthis->actor.shape.rot.y += yawChange * 2;
        }

        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

        if (yawDiff > 0) {
            playSpeed = yawChange * 0.02f;
            playSpeed = CLAMP_MAX(playSpeed, 1.0f);
            pthis->skelAnime.playSpeed = playSpeed;
        } else {
            playSpeed = yawChange * 0.02f;
            playSpeed = CLAMP_MIN(playSpeed, -1.0f);
            pthis->skelAnime.playSpeed = playSpeed;
        }

        prevFrame = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);
        temp1 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        absPlaySpeed = (f32)ABS(pthis->skelAnime.playSpeed);

        if ((s32)pthis->skelAnime.curFrame != prevFrame) {
            temp2 = absPlaySpeed + prevFrame;

            if (((temp2 > 2) && (temp1 <= 0)) || ((temp1 < 7) && (temp2 >= 9))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WALK);
            }
        }

        if (Actor_IsFacingPlayer(&pthis->actor, 0x71C)) {
            if (Rand_ZeroOne() > 0.8f) {
                if ((Rand_ZeroOne() > 0.7f)) {
                    func_80860EC0(pthis);
                } else {
                    EnTest_ChooseAction(pthis, globalCtx);
                }
            } else {
                EnTest_SetupWalkAndBlock(pthis);
            }
        }
    }
}

// a variation of sidestep
void func_80860EC0(EnTest* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gStalfosSidestepAnim);
    pthis->unk_7C8 = 0xF;
    pthis->actor.speedXZ = (Rand_ZeroOne() > 0.5f) ? -0.5f : 0.5f;
    pthis->timer = (s16)((Rand_ZeroOne() * 15.0f) + 25.0f);
    pthis->unk_7EC = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnTest_SetupAction(pthis, func_80860F84);
}

// a variation of sidestep
void func_80860F84(EnTest* pthis, GlobalContext* globalCtx) {
    s16 playerYaw180;
    s32 pad;
    s32 prevFrame;
    s32 temp_f16;
    s16 yawDiff;
    Player* player = GET_PLAYER(globalCtx);
    f32 checkDist = 0.0f;
    s16 newYaw;
    s32 absPlaySpeed;

    if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3E80;
        playerYaw180 = player->actor.shape.rot.y + 0x8000;

        if (pthis->actor.speedXZ >= 0.0f) {
            if (pthis->actor.speedXZ < 6.0f) {
                pthis->actor.speedXZ += 0.5f;
            } else {
                pthis->actor.speedXZ = 6.0f;
            }
        } else {
            if (pthis->actor.speedXZ > -6.0f) {
                pthis->actor.speedXZ -= 0.5f;
            } else {
                pthis->actor.speedXZ = -6.0f;
            }
        }

        if ((pthis->actor.bgCheckFlags & 8) ||
            ((pthis->actor.params == STALFOS_TYPE_CEILING) &&
             !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.world.rot.y))) {
            if (pthis->actor.bgCheckFlags & 8) {
                if (pthis->actor.speedXZ >= 0.0f) {
                    newYaw = pthis->actor.shape.rot.y + 0x3FFF;
                } else {
                    newYaw = pthis->actor.shape.rot.y - 0x3FFF;
                }

                newYaw = pthis->actor.wallYaw - newYaw;
            } else {
                pthis->actor.speedXZ *= -0.8f;
                newYaw = 0;
            }

            if (ABS(newYaw) > 0x4000) {
                pthis->actor.speedXZ *= -0.8f;

                if (pthis->actor.speedXZ < 0.0f) {
                    pthis->actor.speedXZ -= 0.5f;
                } else {
                    pthis->actor.speedXZ += 0.5f;
                }
            }
        }

        if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            checkDist = 200.0f;
        }

        if (pthis->actor.xzDistToPlayer <= (80.0f + checkDist)) {
            Math_SmoothStepToF(&pthis->unk_7EC, -2.5f, 1.0f, 0.8f, 0.0f);
        } else if (pthis->actor.xzDistToPlayer > (110.0f + checkDist)) {
            Math_SmoothStepToF(&pthis->unk_7EC, 2.5f, 1.0f, 0.8f, 0.0f);
        } else {
            Math_SmoothStepToF(&pthis->unk_7EC, 0.0f, 1.0f, 6.65f, 0.0f);
        }

        if (pthis->unk_7EC != 0.0f) {
            pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->unk_7EC;
            pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->unk_7EC;
        }

        pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.5f;

        prevFrame = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);
        temp_f16 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        absPlaySpeed = (f32)ABS(pthis->skelAnime.playSpeed);

        if ((s32)pthis->skelAnime.curFrame != prevFrame) {
            s32 temp_v0_2 = absPlaySpeed + prevFrame;

            if (((temp_v0_2 > 1) && (temp_f16 <= 0)) || ((temp_f16 < 7) && (temp_v0_2 >= 8))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WALK);
            }
        }

        if ((globalCtx->gameplayFrames & 95) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WARAU);
        }

        yawDiff = playerYaw180 - pthis->actor.shape.rot.y;
        yawDiff = ABS(yawDiff);

        if ((yawDiff > 0x6800) || (pthis->timer == 0)) {
            EnTest_ChooseAction(pthis, globalCtx);
        } else if (pthis->timer != 0) {
            pthis->timer--;
        }
    }
}

void EnTest_SetupSlashDown(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosDownSlashAnim);
    Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_STAL_WARAU);
    pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
    pthis->unk_7C8 = 0x10;
    pthis->actor.speedXZ = 0.0f;
    EnTest_SetupAction(pthis, EnTest_SlashDown);
    pthis->swordCollider.info.toucher.damage = 16;

    if (pthis->unk_7DE != 0) {
        pthis->unk_7DE = 3;
    }
}

void EnTest_SlashDown(EnTest* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;

    if ((s32)pthis->skelAnime.curFrame < 4) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xBB8, 0);
    }

    if ((s32)pthis->skelAnime.curFrame == 7) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_SAKEBI);
    }

    if ((pthis->skelAnime.curFrame > 7.0f) && (pthis->skelAnime.curFrame < 11.0f)) {
        pthis->swordState = 1;
    } else {
        pthis->swordState = 0;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if ((globalCtx->gameplayFrames % 2) != 0) {
            EnTest_SetupSlashDownEnd(pthis);
        } else {
            EnTest_SetupSlashUp(pthis);
        }
    }
}

void EnTest_SetupSlashDownEnd(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosRecoverFromDownSlashAnim);
    pthis->unk_7C8 = 0x12;
    pthis->actor.speedXZ = 0.0f;
    EnTest_SetupAction(pthis, EnTest_SlashDownEnd);
}

void EnTest_SlashDownEnd(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->swordCollider.base.atFlags & AT_HIT) {
            pthis->swordCollider.base.atFlags &= ~AT_HIT;
            if (pthis->actor.params != STALFOS_TYPE_CEILING) {
                EnTest_SetupJumpBack(pthis);
                return;
            }
        }

        if (Rand_ZeroOne() > 0.7f) {
            EnTest_SetupIdle(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
            return;
        }

        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, &player->actor);

        if (Rand_ZeroOne() > 0.7f) {
            if (pthis->actor.params != STALFOS_TYPE_CEILING) {
                EnTest_SetupJumpBack(pthis);
                return;
            }
        }

        yawDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

        if (ABS(yawDiff) <= 0x2710) {
            yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

            if ((ABS(yawDiff) > 0x3E80) && (pthis->actor.params != STALFOS_TYPE_CEILING)) {
                pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                EnTest_SetupJumpBack(pthis);
            } else if (player->stateFlags1 & 0x10) {
                if (pthis->actor.isTargeted) {
                    EnTest_SetupSlashDown(pthis);
                } else if ((globalCtx->gameplayFrames % 2) != 0) {
                    func_808627C4(pthis, globalCtx);
                } else {
                    EnTest_SetupJumpBack(pthis);
                }
            } else {
                EnTest_SetupSlashDown(pthis);
            }
        } else {
            func_808627C4(pthis, globalCtx);
        }
    }
}

void EnTest_SetupSlashUp(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosUpSlashAnim);
    pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
    pthis->unk_7C8 = 0x11;
    pthis->swordCollider.info.toucher.damage = 16;
    pthis->actor.speedXZ = 0.0f;
    EnTest_SetupAction(pthis, EnTest_SlashUp);

    if (pthis->unk_7DE != 0) {
        pthis->unk_7DE = 3;
    }
}

void EnTest_SlashUp(EnTest* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;

    if ((s32)pthis->skelAnime.curFrame == 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_SAKEBI);
    }

    if ((pthis->skelAnime.curFrame > 1.0f) && (pthis->skelAnime.curFrame < 8.0f)) {
        pthis->swordState = 1;
    } else {
        pthis->swordState = 0;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnTest_SetupSlashDown(pthis);
    }
}

void EnTest_SetupJumpBack(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosJumpBackwardsAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->unk_7C8 = 0x14;
    pthis->timer = 5;
    EnTest_SetupAction(pthis, EnTest_JumpBack);

    if (pthis->unk_7DE != 0) {
        pthis->unk_7DE = 3;
    }

    if (pthis->actor.params != STALFOS_TYPE_CEILING) {
        pthis->actor.speedXZ = -11.0f;
    } else {
        pthis->actor.speedXZ = -7.0f;
    }
}

void EnTest_JumpBack(EnTest* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xBB8, 1);

    if (pthis->timer == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WARAU);
    } else {
        pthis->timer--;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
            if (pthis->actor.xzDistToPlayer <= 100.0f) {
                if (Actor_IsFacingPlayer(&pthis->actor, 0x1555)) {
                    EnTest_SetupSlashDown(pthis);
                } else {
                    EnTest_SetupIdle(pthis);
                    pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
                }
            } else {
                if ((pthis->actor.xzDistToPlayer <= 220.0f) && Actor_IsFacingPlayer(&pthis->actor, 0xE38)) {
                    EnTest_SetupJumpslash(pthis);
                } else {
                    EnTest_SetupIdle(pthis);
                    pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
                }
            }
            pthis->actor.flags |= ACTOR_FLAG_0;
        }
    } else if (pthis->skelAnime.curFrame == (pthis->skelAnime.endFrame - 4.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    }
}

void EnTest_SetupJumpslash(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosJumpAnim);
    Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_STAL_WARAU);
    pthis->timer = 0;
    pthis->unk_7C8 = 0x17;
    pthis->actor.velocity.y = 10.0f;
    pthis->actor.speedXZ = 8.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
    EnTest_SetupAction(pthis, EnTest_Jumpslash);
    pthis->swordCollider.info.toucher.damage = 32;

    if (pthis->unk_7DE != 0) {
        pthis->unk_7DE = 3;
    }
}

void EnTest_Jumpslash(EnTest* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer == 0) {
            Animation_PlayOnce(&pthis->skelAnime, &gStalfosJumpslashAnim);
            pthis->timer = 1;
            pthis->swordState = 1;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_SAKEBI);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
        } else {
            pthis->actor.speedXZ = 0.0f;
            EnTest_SetupIdle(pthis);
        }
    }

    if ((pthis->timer != 0) && (pthis->skelAnime.curFrame >= 5.0f)) {
        pthis->swordState = 0;
    }

    if (pthis->actor.world.pos.y <= pthis->actor.floorHeight) {
        if (pthis->actor.speedXZ != 0.0f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        }

        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }
}

void EnTest_SetupJumpUp(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosJumpAnim);
    pthis->timer = 0;
    pthis->unk_7C8 = 4;
    pthis->actor.velocity.y = 14.0f;
    pthis->actor.speedXZ = 6.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnTest_SetupAction(pthis, EnTest_JumpUp);
}

void EnTest_JumpUp(EnTest* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.world.pos.y <= pthis->actor.floorHeight) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->unk_7E4 = -(s32)pthis->actor.velocity.y;

        if (pthis->unk_7E4 == 0) {
            pthis->unk_7E4 = 1;
        }

        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
        pthis->unk_7C8 = 0xC;
        pthis->timer = 4;
        Animation_Change(&pthis->skelAnime, &gStalfosLandFromLeapAnim, 0.0f, 0.0f, 0.0f, 2, 0.0f);
        EnTest_SetupAction(pthis, EnTest_Land);
    }
}

void EnTest_SetupStopAndBlock(EnTest* pthis) {
    Animation_Change(&pthis->skelAnime, &gStalfosBlockWithShieldAnim, 2.0f, 0.0f,
                     Animation_GetLastFrame(&gStalfosBlockWithShieldAnim), 2, 2.0f);
    pthis->unk_7C8 = 0x15;
    pthis->actor.speedXZ = 0.0f;
    pthis->timer = (Rand_ZeroOne() * 10.0f) + 11.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->unk_7DE = 5;
    EnTest_SetupAction(pthis, EnTest_StopAndBlock);
}

void EnTest_StopAndBlock(EnTest* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    SkelAnime_Update(&pthis->skelAnime);

    if ((ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) > 0x3E80) &&
        (pthis->actor.params != STALFOS_TYPE_CEILING) && ((globalCtx->gameplayFrames % 2) != 0)) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        EnTest_SetupJumpBack(pthis);
    }

    if (pthis->timer == 0) {
        EnTest_SetupIdleFromBlock(pthis);
    } else {
        pthis->timer--;
    }
}

void EnTest_SetupIdleFromBlock(EnTest* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gStalfosMiddleGuardAnim, -4.0f);
    pthis->unk_7C8 = 0x16;
    EnTest_SetupAction(pthis, EnTest_IdleFromBlock);
}

void EnTest_IdleFromBlock(EnTest* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.5f, 0.0f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->skelAnime.morphWeight == 0.0f) {
        pthis->actor.speedXZ = 0.0f;
        pthis->unk_7DE = 0;

        if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
            if (pthis->actor.xzDistToPlayer < 500.0f) {
                EnTest_ChooseAction(pthis, globalCtx);
            } else {
                func_808627C4(pthis, globalCtx);
            }
        }
    }
}

void func_80862154(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosFlinchFromHitFrontAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DAMAGE);
    pthis->unk_7C8 = 8;
    pthis->actor.speedXZ = -2.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
    EnTest_SetupAction(pthis, func_808621D4);
}

void func_808621D4(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.1f, 0.0f);

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.speedXZ = 0.0f;

        if ((pthis->actor.bgCheckFlags & 8) && ((ABS((s16)(pthis->actor.wallYaw - pthis->actor.shape.rot.y)) < 0x38A4) &&
                                               (pthis->actor.xzDistToPlayer < 80.0f))) {
            EnTest_SetupJumpUp(pthis);
        } else if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
            EnTest_ChooseAction(pthis, globalCtx);
        } else {
            return;
        }
    }

    if (player->swordState != 0) {
        if ((pthis->actor.bgCheckFlags & 8) && ((ABS((s16)(pthis->actor.wallYaw - pthis->actor.shape.rot.y)) < 0x38A4) &&
                                               (pthis->actor.xzDistToPlayer < 80.0f))) {
            EnTest_SetupJumpUp(pthis);
        } else if ((Rand_ZeroOne() > 0.7f) && (pthis->actor.params != STALFOS_TYPE_CEILING) &&
                   (player->swordAnimation != 0x11)) {
            EnTest_SetupJumpBack(pthis);
        } else {
            EnTest_SetupStopAndBlock(pthis);
        }

        pthis->unk_7C8 = 8;
    }
}

void func_80862398(EnTest* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosFlinchFromHitBehindAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DAMAGE);
    pthis->unk_7C8 = 9;
    pthis->actor.speedXZ = -2.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
    EnTest_SetupAction(pthis, func_80862418);
}

void func_80862418(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.1f, 0.0f);

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.speedXZ = 0.0f;

        if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
            EnTest_ChooseAction(pthis, globalCtx);
        } else {
            return;
        }
    }

    if (player->swordState != 0) {
        if ((pthis->actor.bgCheckFlags & 8) && ((ABS((s16)(pthis->actor.wallYaw - pthis->actor.shape.rot.y)) < 0x38A4) &&
                                               (pthis->actor.xzDistToPlayer < 80.0f))) {
            EnTest_SetupJumpUp(pthis);
        } else if ((Rand_ZeroOne() > 0.7f) && (pthis->actor.params != STALFOS_TYPE_CEILING) &&
                   (player->swordAnimation != 0x11)) {
            EnTest_SetupJumpBack(pthis);
        } else {
            EnTest_SetupStopAndBlock(pthis);
        }

        pthis->unk_7C8 = 8;
    }
}

void EnTest_SetupStunned(EnTest* pthis) {
    pthis->unk_7C8 = 0xB;
    pthis->unk_7DE = 0;
    pthis->swordState = 0;
    pthis->skelAnime.playSpeed = 0.0f;
    pthis->actor.speedXZ = -4.0f;

    if (pthis->lastDamageEffect == STALFOS_DMGEFF_LIGHT) {
        Actor_SetColorFilter(&pthis->actor, -0x8000, 0x78, 0, 0x50);
    } else {
        Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);

        if (pthis->lastDamageEffect == STALFOS_DMGEFF_FREEZE) {
            pthis->iceTimer = 36;
        } else {
            Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gStalfosFlinchFromHitFrontAnim, 0.0f);
        }
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnTest_SetupAction(pthis, EnTest_Stunned);
}

void EnTest_Stunned(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);

    if (pthis->actor.colorFilterTimer == 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            func_80862FA8(pthis, globalCtx);
        } else if (player->swordState != 0) {
            if ((pthis->actor.bgCheckFlags & 8) &&
                ((ABS((s16)(pthis->actor.wallYaw - pthis->actor.shape.rot.y)) < 0x38A4) &&
                 (pthis->actor.xzDistToPlayer < 80.0f))) {
                EnTest_SetupJumpUp(pthis);
            } else if ((Rand_ZeroOne() > 0.7f) && (player->swordAnimation != 0x11)) {
                EnTest_SetupJumpBack(pthis);
            } else {
                EnTest_SetupStopAndBlock(pthis);
            }

            pthis->unk_7C8 = 8;
        } else {
            pthis->actor.speedXZ = 0.0f;
            if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
                EnTest_ChooseAction(pthis, globalCtx);
            }
        }
    }
}

// a variation of sidestep
void func_808627C4(EnTest* pthis, GlobalContext* globalCtx) {
    if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
        func_80860EC0(pthis);
        return;
    }

    Animation_MorphToLoop(&pthis->skelAnime, &gStalfosSidestepAnim, -2.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    pthis->actor.speedXZ = ((globalCtx->gameplayFrames % 2) != 0) ? -4.0f : 4.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
    pthis->timer = (Rand_ZeroOne() * 20.0f) + 20.0f;
    pthis->unk_7C8 = 0x18;
    EnTest_SetupAction(pthis, func_808628C8);
    pthis->unk_7EC = 0.0f;
}

// a variation of sidestep
void func_808628C8(EnTest* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad1;
    s32 prevFrame;
    s32 temp_f16;
    s32 pad2;
    f32 checkDist = 0.0f;
    s16 newYaw;
    f32 absPlaySpeed;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);

    if (pthis->unk_7DE == 0) {
        pthis->unk_7DE++;
    }

    if (pthis->actor.speedXZ >= 0.0f) {
        if (pthis->actor.speedXZ < 6.0f) {
            pthis->actor.speedXZ += 0.125f;
        } else {
            pthis->actor.speedXZ = 6.0f;
        }
    } else {
        if (pthis->actor.speedXZ > -6.0f) {
            pthis->actor.speedXZ -= 0.125f;
        } else {
            pthis->actor.speedXZ = -6.0f;
        }
    }

    if ((pthis->actor.bgCheckFlags & 8) ||
        ((pthis->actor.params == STALFOS_TYPE_CEILING) &&
         !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.shape.rot.y + 0x3FFF))) {
        if (pthis->actor.bgCheckFlags & 8) {
            if (pthis->actor.speedXZ >= 0.0f) {
                newYaw = (pthis->actor.shape.rot.y + 0x3FFF);
            } else {
                newYaw = (pthis->actor.shape.rot.y - 0x3FFF);
            }

            newYaw = pthis->actor.wallYaw - newYaw;
        } else {
            pthis->actor.speedXZ *= -0.8f;
            newYaw = 0;
        }

        if (ABS(newYaw) > 0x4000) {
            pthis->actor.speedXZ *= -0.8f;

            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ -= 0.5f;
            } else {
                pthis->actor.speedXZ += 0.5f;
            }
        }
    }

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;

    if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
        checkDist = 200.0f;
    }

    if (pthis->actor.xzDistToPlayer <= (80.0f + checkDist)) {
        Math_SmoothStepToF(&pthis->unk_7EC, -2.5f, 1.0f, 0.8f, 0.0f);
    } else if (pthis->actor.xzDistToPlayer > (110.0f + checkDist)) {
        Math_SmoothStepToF(&pthis->unk_7EC, 2.5f, 1.0f, 0.8f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->unk_7EC, 0.0f, 1.0f, 6.65f, 0.0f);
    }

    if (pthis->unk_7EC != 0.0f) {
        pthis->actor.world.pos.x += (Math_SinS(pthis->actor.shape.rot.y) * pthis->unk_7EC);
        pthis->actor.world.pos.z += (Math_CosS(pthis->actor.shape.rot.y) * pthis->unk_7EC);
    }

    pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.5f;
    prevFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);

    temp_f16 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
    absPlaySpeed = ABS(pthis->skelAnime.playSpeed);

    if ((pthis->timer % 32) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WARAU);
    }
    if ((s32)pthis->skelAnime.curFrame != prevFrame) {
        s32 temp_v0_2 = (s32)absPlaySpeed + prevFrame;

        if (((temp_v0_2 > 1) && (temp_f16 <= 0)) || ((temp_f16 < 7) && (temp_v0_2 >= 8))) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_WALK);
        }
    }

    if (pthis->timer == 0) {
        if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            EnTest_SetupIdle(pthis);
        } else if (Actor_IsTargeted(globalCtx, &pthis->actor)) {
            if (!EnTest_ReactToProjectile(globalCtx, pthis)) {
                EnTest_ChooseAction(pthis, globalCtx);
            }
        } else if (player->heldItemActionParam != PLAYER_AP_NONE) {
            if ((globalCtx->gameplayFrames % 2) != 0) {
                EnTest_SetupIdle(pthis);
            } else {
                EnTest_SetupWalkAndBlock(pthis);
            }
        } else {
            EnTest_SetupWalkAndBlock(pthis);
        }

    } else {
        pthis->timer--;
    }
}

void func_80862DBC(EnTest* pthis, GlobalContext* globalCtx) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DAMAGE);
    pthis->unk_7C8 = 2;
    BodyBreak_Alloc(&pthis->bodyBreak, 60, globalCtx);
    pthis->actor.home.rot.x = 0;

    if (pthis->swordState >= 0) {
	    EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->effectIndex));
        pthis->swordState = -1;
    }

    pthis->actor.flags &= ~ACTOR_FLAG_0;

    if (pthis->actor.params == STALFOS_TYPE_5) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
    }

    EnTest_SetupAction(pthis, func_80862E6C);
}

void func_80862E6C(EnTest* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.child == NULL) {
        if (pthis->actor.home.rot.x == 0) {
            pthis->actor.home.rot.x = pthis->bodyBreak.count;
        }

        if (BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, pthis->actor.params + 8)) {
            pthis->actor.child = &pthis->actor;
        }
    } else {
        if (pthis->actor.home.rot.x == 0) {
            pthis->actor.colChkInfo.health = 10;

            if (pthis->actor.params == STALFOS_TYPE_4) {
                pthis->actor.params = -1;
            } else {
                Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
            }

            pthis->actor.child = NULL;
            pthis->actor.flags |= ACTOR_FLAG_0;
            EnTest_SetupJumpBack(pthis);
        } else if ((pthis->actor.params == STALFOS_TYPE_5) &&
                   !Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_TEST, ACTORCAT_ENEMY, 8000.0f)) {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xD0);

            if (pthis->actor.parent != NULL) {
                pthis->actor.parent->home.rot.z--;
            }

            Actor_Kill(&pthis->actor);
        }
    }
}

void func_80862FA8(EnTest* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosFallOverBackwardsAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DEAD);
    pthis->unk_7DE = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.colorFilterTimer = 0;
    pthis->actor.speedXZ = 0.0f;

    if (pthis->actor.params <= STALFOS_TYPE_CEILING) {
        pthis->unk_7C8 = 5;
        EnTest_SetupAction(pthis, func_80863044);
    } else {
        func_80862DBC(pthis, globalCtx);
    }
}

void func_80863044(EnTest* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->timer = (Rand_ZeroOne() * 10.0f) + 10.0f;
        pthis->unk_7C8 = 7;
        EnTest_SetupAction(pthis, func_808633E8);
        BodyBreak_Alloc(&pthis->bodyBreak, 60, globalCtx);
    }

    if ((s32)pthis->skelAnime.curFrame == 15) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
    }
}

void func_808630F0(EnTest* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnime, &gStalfosFallOverForwardsAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_DEAD);
    pthis->unk_7C8 = 6;
    pthis->actor.colorFilterTimer = 0;
    pthis->unk_7DE = 0;
    pthis->actor.speedXZ = 0.0f;

    if (pthis->actor.params <= STALFOS_TYPE_CEILING) {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        EnTest_SetupAction(pthis, func_8086318C);
    } else {
        func_80862DBC(pthis, globalCtx);
    }
}

void func_8086318C(EnTest* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->timer = (Rand_ZeroOne() * 10.0f) + 10.0f;
        pthis->unk_7C8 = 7;
        EnTest_SetupAction(pthis, func_808633E8);
        BodyBreak_Alloc(&pthis->bodyBreak, 60, globalCtx);
    }

    if (((s32)pthis->skelAnime.curFrame == 10) || ((s32)pthis->skelAnime.curFrame == 25)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
    }
}

void EnTest_SetupRecoil(EnTest* pthis) {
    pthis->swordState = 0;
    pthis->skelAnime.moveFlags = 2;
    pthis->unk_7C8 = 0x13;
    pthis->skelAnime.playSpeed = -1.0f;
    pthis->skelAnime.startFrame = pthis->skelAnime.curFrame;
    pthis->skelAnime.endFrame = 0.0f;
    EnTest_SetupAction(pthis, EnTest_Recoil);
}

void EnTest_Recoil(EnTest* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (Rand_ZeroOne() > 0.7f) {
            EnTest_SetupIdle(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
        } else if (((globalCtx->gameplayFrames % 2) != 0) && (pthis->actor.params != STALFOS_TYPE_CEILING)) {
            EnTest_SetupJumpBack(pthis);
        } else {
            func_808627C4(pthis, globalCtx);
        }
    }
}

void EnTest_Rise(EnTest* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.scale.y < 0.015f) {
        pthis->actor.scale.y += 0.002f;
        pthis->actor.world.pos.y = pthis->actor.home.pos.y - 3.5f;
    } else {
        pthis->actor.world.pos.y = pthis->actor.home.pos.y;
        EnTest_SetupJumpBack(pthis);
    }
}

void func_808633E8(EnTest* pthis, GlobalContext* globalCtx) {
    pthis->actor.params = STALFOS_TYPE_1;

    if (BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, pthis->actor.params)) {
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xD0);

        if (pthis->actor.parent != NULL) {
            pthis->actor.parent->home.rot.z--;
        }

        Actor_Kill(&pthis->actor);
    }
}

void EnTest_UpdateHeadRot(EnTest* pthis, GlobalContext* globalCtx) {
    s16 lookAngle = pthis->actor.yawTowardsPlayer;

    lookAngle -= (s16)(pthis->headRot.y + pthis->actor.shape.rot.y);

    pthis->headRotOffset.y = CLAMP(lookAngle, -0x7D0, 0x7D0);
    pthis->headRot.y += pthis->headRotOffset.y;
    pthis->headRot.y = CLAMP(pthis->headRot.y, -0x382F, 0x382F);
}

void EnTest_UpdateDamage(EnTest* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->shieldCollider.base.acFlags & AC_BOUNCED) {
        pthis->shieldCollider.base.acFlags &= ~AC_BOUNCED;
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;

        if (pthis->unk_7C8 >= 0xA) {
            pthis->actor.speedXZ = -4.0f;
        }
    } else if (pthis->bodyCollider.base.acFlags & AC_HIT) {
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;

        if ((pthis->actor.colChkInfo.damageEffect != STALFOS_DMGEFF_SLING) &&
            (pthis->actor.colChkInfo.damageEffect != STALFOS_DMGEFF_FIREMAGIC)) {
            pthis->lastDamageEffect = pthis->actor.colChkInfo.damageEffect;
            if (pthis->swordState >= 1) {
                pthis->swordState = 0;
            }
            pthis->unk_7DC = player->unk_845;
            pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            Actor_SetDropFlag(&pthis->actor, &pthis->bodyCollider.info, false);
            Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_STAL_WARAU);

            if ((pthis->actor.colChkInfo.damageEffect == STALFOS_DMGEFF_STUN) ||
                (pthis->actor.colChkInfo.damageEffect == STALFOS_DMGEFF_FREEZE) ||
                (pthis->actor.colChkInfo.damageEffect == STALFOS_DMGEFF_LIGHT)) {
                if (pthis->unk_7C8 != 0xB) {
                    Actor_ApplyDamage(&pthis->actor);
                    EnTest_SetupStunned(pthis);
                }
            } else {
                if (Actor_IsFacingPlayer(&pthis->actor, 0x4000)) {
                    if (Actor_ApplyDamage(&pthis->actor) == 0) {
                        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                        func_80862FA8(pthis, globalCtx);
                    } else {
                        func_80862154(pthis);
                    }
                } else if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    func_808630F0(pthis, globalCtx);
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                } else {
                    func_80862398(pthis);
                }
            }
        }
    }
}

void EnTest_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnTest* pthis = (EnTest*)thisx;
    f32 oldWeight;
    u32 floorProperty;
    s32 pad;

    EnTest_UpdateDamage(pthis, globalCtx);

    if (pthis->actor.colChkInfo.damageEffect != STALFOS_DMGEFF_FIREMAGIC) {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 0x1D);

        if (pthis->actor.params == STALFOS_TYPE_1) {
            if (pthis->actor.world.pos.y <= pthis->actor.home.pos.y) {
                pthis->actor.world.pos.y = pthis->actor.home.pos.y;
                pthis->actor.velocity.y = 0.0f;
            }

            if (pthis->actor.floorHeight <= pthis->actor.home.pos.y) {
                pthis->actor.floorHeight = pthis->actor.home.pos.y;
            }
        } else if (pthis->actor.bgCheckFlags & 2) {
            floorProperty = func_80041EA4(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);

            if ((floorProperty == 5) || (floorProperty == 0xC) ||
                func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId) == 9) {
                Actor_Kill(&pthis->actor);
                return;
            }
        }

        pthis->actionFunc(pthis, globalCtx);

        switch (pthis->unk_7DE) {
            case 0:
                break;

            case 1:
                Animation_Change(&pthis->upperSkelanime, &gStalfosBlockWithShieldAnim, 2.0f, 0.0f,
                                 Animation_GetLastFrame(&gStalfosBlockWithShieldAnim), 2, 2.0f);
                AnimationContext_SetCopyTrue(globalCtx, pthis->skelAnime.limbCount, pthis->skelAnime.jointTable,
                                             pthis->upperSkelanime.jointTable, sJointCopyFlags);
                pthis->unk_7DE++;
                break;

            case 2:
                SkelAnime_Update(&pthis->upperSkelanime);
                SkelAnime_CopyFrameTableTrue(&pthis->skelAnime, pthis->skelAnime.jointTable,
                                             pthis->upperSkelanime.jointTable, sJointCopyFlags);
                break;

            case 3:
                pthis->unk_7DE++;
                pthis->upperSkelanime.morphWeight = 4.0f;
                // fallthrough
            case 4:
                oldWeight = pthis->upperSkelanime.morphWeight;
                pthis->upperSkelanime.morphWeight -= 1.0f;

                if (pthis->upperSkelanime.morphWeight <= 0.0f) {
                    pthis->unk_7DE = 0;
                }

                SkelAnime_InterpFrameTable(pthis->skelAnime.limbCount, pthis->upperSkelanime.jointTable,
                                           pthis->upperSkelanime.jointTable, pthis->skelAnime.jointTable,
                                           1.0f - (pthis->upperSkelanime.morphWeight / oldWeight));
                SkelAnime_CopyFrameTableTrue(&pthis->skelAnime, pthis->skelAnime.jointTable,
                                             pthis->upperSkelanime.jointTable, sJointCopyFlags);
                break;
        }

        if ((pthis->actor.colorFilterTimer == 0) && (pthis->actor.colChkInfo.health != 0)) {
            if ((pthis->unk_7C8 != 0x10) && (pthis->unk_7C8 != 0x17)) {
                EnTest_UpdateHeadRot(pthis, globalCtx);
            } else {
                Math_SmoothStepToS(&pthis->headRot.y, 0, 1, 0x3E8, 0);
            }
        }
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);

    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 45.0f;

    if ((pthis->actor.colChkInfo.health > 0) || (pthis->actor.colorFilterTimer != 0)) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);

        if ((pthis->unk_7C8 >= 0xA) &&
            ((pthis->actor.colorFilterTimer == 0) || (!(pthis->actor.colorFilterParams & 0x4000)))) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
        }

        if (pthis->unk_7DE != 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->shieldCollider.base);
        }
    }

    if (pthis->swordState >= 1) {
        if (!(pthis->swordCollider.base.atFlags & AT_BOUNCED)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->swordCollider.base);
        } else {
            pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
            EnTest_SetupRecoil(pthis);
        }
    }

    if (pthis->actor.params == STALFOS_TYPE_INVISIBLE) {
        if (globalCtx->actorCtx.unk_03 != 0) {
            pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_7;
            pthis->actor.shape.shadowDraw = ActorShadow_DrawFeet;
        } else {
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_7);
            pthis->actor.shape.shadowDraw = NULL;
        }
    }
}

s32 EnTest_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnTest* pthis = (EnTest*)thisx;
    s32 pad;

    if (limbIndex == STALFOS_LIMB_HEAD_ROOT) {
        rot->x += pthis->headRot.y;
        rot->y -= pthis->headRot.x;
        rot->z += pthis->headRot.z;
    } else if (limbIndex == STALFOS_LIMB_HEAD) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_test.c", 3582);

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 80 + ABS((s16)(Math_SinS(globalCtx->gameplayFrames * 2000) * 175.0f)), 0, 0,
                       255);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_test.c", 3587);
    }

    if ((pthis->actor.params == STALFOS_TYPE_INVISIBLE) && !CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        *dList = NULL;
    }

    return false;
}

void EnTest_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f unused1 = { 1100.0f, -700.0f, 0.0f };
    static Vec3f D_80864658 = { 300.0f, 0.0f, 0.0f };
    static Vec3f D_80864664 = { 3400.0f, 0.0f, 0.0f };
    static Vec3f D_80864670 = { 0.0f, 0.0f, 0.0f };
    static Vec3f D_8086467C = { 7000.0f, 1000.0f, 0.0f };
    static Vec3f D_80864688 = { 3000.0f, -2000.0f, -1000.0f };
    static Vec3f D_80864694 = { 3000.0f, -2000.0f, 1000.0f };
    static Vec3f D_808646A0 = { -1300.0f, 1100.0f, 0.0f };
    static Vec3f unused2 = { -3000.0f, 1900.0f, 800.0f };
    static Vec3f unused3 = { -3000.0f, -1100.0f, 800.0f };
    static Vec3f unused4 = { 1900.0f, 1900.0f, 800.0f };
    static Vec3f unused5 = { -3000.0f, -1100.0f, 800.0f };
    static Vec3f unused6 = { 1900.0f, -1100.0f, 800.0f };
    static Vec3f unused7 = { 1900.0f, 1900.0f, 800.0f };
    s32 bodyPart = -1;
    Vec3f sp70;
    Vec3f sp64;
    EnTest* pthis = (EnTest*)thisx;
    s32 pad;
    Vec3f sp50;

    BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 0, 60, 60, dList, BODYBREAK_OBJECT_DEFAULT);

    if (limbIndex == STALFOS_LIMB_SWORD) {
        Matrix_MultVec3f(&D_8086467C, &pthis->swordCollider.dim.quad[1]);
        Matrix_MultVec3f(&D_80864688, &pthis->swordCollider.dim.quad[0]);
        Matrix_MultVec3f(&D_80864694, &pthis->swordCollider.dim.quad[3]);
        Matrix_MultVec3f(&D_808646A0, &pthis->swordCollider.dim.quad[2]);

        Collider_SetQuadVertices(&pthis->swordCollider, &pthis->swordCollider.dim.quad[0],
                                 &pthis->swordCollider.dim.quad[1], &pthis->swordCollider.dim.quad[2],
                                 &pthis->swordCollider.dim.quad[3]);

        Matrix_MultVec3f(&D_80864664, &sp70);
        Matrix_MultVec3f(&D_80864670, &sp64);

        if ((pthis->swordState >= 1) &&
            ((pthis->actor.params != STALFOS_TYPE_INVISIBLE) || (globalCtx->actorCtx.unk_03 != 0))) {
            EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->effectIndex), &sp70, &sp64);
        } else if (pthis->swordState >= 0) {
            EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->effectIndex));
            pthis->swordState = -1;
        }

    } else if ((limbIndex == STALFOS_LIMB_SHIELD) && (pthis->unk_7DE != 0)) {
        Matrix_MultVec3f(&D_80864670, &sp64);

        pthis->shieldCollider.dim.pos.x = sp64.x;
        pthis->shieldCollider.dim.pos.y = sp64.y;
        pthis->shieldCollider.dim.pos.z = sp64.z;
    } else {
        Actor_SetFeetPos(&pthis->actor, limbIndex, STALFOS_LIMB_FOOT_L, &D_80864658, STALFOS_LIMB_ANKLE_R, &D_80864658);

        if ((limbIndex == STALFOS_LIMB_FOOT_L) || (limbIndex == STALFOS_LIMB_ANKLE_R)) {
            if ((pthis->unk_7C8 == 0x15) || (pthis->unk_7C8 == 0x16)) {
                if (pthis->actor.speedXZ != 0.0f) {
                    Matrix_MultVec3f(&D_80864658, &sp64);
                    Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &sp64, 10.0f, 1, 8.0f, 0x64, 0xF, 0);
                }
            }
        }
    }

    if (pthis->iceTimer != 0) {
        switch (limbIndex) {
            case STALFOS_LIMB_HEAD:
                bodyPart = 0;
                break;
            case STALFOS_LIMB_CHEST:
                bodyPart = 1;
                break;
            case STALFOS_LIMB_SWORD:
                bodyPart = 2;
                break;
            case STALFOS_LIMB_SHIELD:
                bodyPart = 3;
                break;
            case STALFOS_LIMB_UPPERARM_R:
                bodyPart = 4;
                break;
            case STALFOS_LIMB_UPPERARM_L:
                bodyPart = 5;
                break;
            case STALFOS_LIMB_WAIST:
                bodyPart = 6;
                break;
            case STALFOS_LIMB_FOOT_L:
                bodyPart = 7;
                break;
            case STALFOS_LIMB_FOOT_R:
                bodyPart = 8;
                break;
        }

        if (bodyPart >= 0) {
            Matrix_MultVec3f(&D_80864670, &sp50);

            pthis->bodyPartsPos[bodyPart].x = sp50.x;
            pthis->bodyPartsPos[bodyPart].y = sp50.y;
            pthis->bodyPartsPos[bodyPart].z = sp50.z;
        }
    }
}

void EnTest_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnTest* pthis = (EnTest*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    func_8002EBCC(&pthis->actor, globalCtx, 1);

    if ((thisx->params <= STALFOS_TYPE_CEILING) || (thisx->child == NULL)) {
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnTest_OverrideLimbDraw,
                          EnTest_PostLimbDraw, pthis);
    }

    if (pthis->iceTimer != 0) {
        thisx->colorFilterTimer++;
        pthis->iceTimer--;

        if ((pthis->iceTimer % 4) == 0) {
            s32 iceIndex = pthis->iceTimer >> 2;

            EffectSsEnIce_SpawnFlyingVec3s(globalCtx, thisx, &pthis->bodyPartsPos[iceIndex], 150, 150, 150, 250, 235,
                                           245, 255, 1.5f);
        }
    }
}

// a variation of sidestep
void func_80864158(EnTest* pthis, f32 xzSpeed) {
    Animation_MorphToLoop(&pthis->skelAnime, &gStalfosSidestepAnim, -2.0f);
    pthis->actor.speedXZ = xzSpeed;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
    pthis->timer = (Rand_ZeroOne() * 20.0f) + 15.0f;
    pthis->unk_7C8 = 0x18;
    EnTest_SetupAction(pthis, func_808628C8);
}

/**
 * Check if a projectile actor is within 300 units and react accordingly.
 * Returns true if the projectile test passes and a new action is performed.
 */
s32 EnTest_ReactToProjectile(GlobalContext* globalCtx, EnTest* pthis) {
    Actor* projectileActor;
    s16 yawToProjectile;
    s16 wallYawDiff;
    s16 touchingWall;
    s16 directionFlag;

    projectileActor = Actor_GetProjectileActor(globalCtx, &pthis->actor, 300.0f);

    if (projectileActor != NULL) {
        yawToProjectile = Actor_WorldYawTowardActor(&pthis->actor, projectileActor) - (u16)pthis->actor.shape.rot.y;

        if ((u8)(pthis->actor.bgCheckFlags & 8)) {
            wallYawDiff = ((u16)pthis->actor.wallYaw - (u16)pthis->actor.shape.rot.y);
            touchingWall = true;
        } else {
            touchingWall = false;
        }

        if (Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &projectileActor->world.pos) < 200.0f) {
            if (Actor_IsTargeted(globalCtx, &pthis->actor) && (projectileActor->id == ACTOR_ARMS_HOOK)) {
                EnTest_SetupJumpUp(pthis);
            } else if (ABS(yawToProjectile) < 0x2000) {
                EnTest_SetupStopAndBlock(pthis);
            } else if (ABS(yawToProjectile) < 0x6000) {
                EnTest_SetupJumpBack(pthis);
            } else {
                EnTest_SetupJumpUp(pthis);
            }

            return true;
        }

        if (Actor_IsTargeted(globalCtx, &pthis->actor) && (projectileActor->id == ACTOR_ARMS_HOOK)) {
            EnTest_SetupJumpUp(pthis);
            return true;
        }

        if ((ABS(yawToProjectile) < 0x2000) || (ABS(yawToProjectile) > 0x6000)) {
            directionFlag = globalCtx->gameplayFrames % 2;

            if (touchingWall && (wallYawDiff > 0x2000) && (wallYawDiff < 0x6000)) {
                directionFlag = false;
            } else if (touchingWall && (wallYawDiff < -0x2000) && (wallYawDiff > -0x6000)) {
                directionFlag = true;
            }

            if (directionFlag) {
                func_80864158(pthis, 4.0f);
            } else {
                func_80864158(pthis, -4.0f);
            }
        } else if (ABS(yawToProjectile) < 0x6000) {
            directionFlag = globalCtx->gameplayFrames % 2;

            if (touchingWall && (ABS(wallYawDiff) > 0x6000)) {
                directionFlag = false;
            } else if (touchingWall && (ABS(wallYawDiff) < 0x2000)) {
                directionFlag = true;
            }

            if (directionFlag) {
                EnTest_SetupJumpBack(pthis);
            } else {
                EnTest_SetupJumpUp(pthis);
            }
        }

        return true;
    }

    return false;
}

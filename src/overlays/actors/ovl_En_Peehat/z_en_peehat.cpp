#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PEEHAT_Z_EN_PEEHAT_C
#include "actor_common.h"
#include "z_en_peehat.h"
#include "objects/object_peehat/object_peehat.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_24)

#define GROUND_HOVER_HEIGHT 75.0f
#define MAX_LARVA 3

void EnPeehat_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnPeehat_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnPeehat_Ground_SetStateGround(EnPeehat* pthis);
void EnPeehat_Flying_SetStateGround(EnPeehat* pthis);
void EnPeehat_Larva_SetStateSeekPlayer(EnPeehat* pthis);
void EnPeehat_Ground_StateGround(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_SetStateRise(EnPeehat* pthis);
void EnPeehat_Flying_StateGrounded(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Flying_SetStateRise(EnPeehat* pthis);
void EnPeehat_Flying_StateFly(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Flying_SetStateLanding(EnPeehat* pthis);
void EnPeehat_Ground_StateRise(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_SetStateHover(EnPeehat* pthis);
void EnPeehat_Flying_StateRise(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_StateSeekPlayer(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_SetStateReturnHome(EnPeehat* pthis);
void EnPeehat_Ground_SetStateLanding(EnPeehat* pthis);
void EnPeehat_Larva_StateSeekPlayer(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_SetStateAttackRecoil(EnPeehat* pthis);
void EnPeehat_Ground_StateLanding(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Flying_StateLanding(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_StateHover(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Ground_StateReturnHome(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_StateAttackRecoil(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_StateBoomerangStunned(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_Adult_StateDie(EnPeehat* pthis, GlobalContext* globalCtx);
void EnPeehat_SetStateExplode(EnPeehat* pthis);
void EnPeehat_StateExplode(EnPeehat* pthis, GlobalContext* globalCtx);

static Vec3f peahatBladeTip_101[] = { { 0.0f, 0.0f, 5500.0f }, { 0.0f, 0.0f, -5500.0f } };

static Vec3f D_80AD285C_102[] = {
    { 0.0f, 0.0f, -4500.0f }, { -4500.0f, 0.0f, 0.0f }, { 4500.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 4500.0f }
};


ActorInit En_Peehat_InitVars = {
    ACTOR_EN_PEEHAT,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_PEEHAT,
    sizeof(EnPeehat),
    (ActorFunc)EnPeehat_Init,
    (ActorFunc)EnPeehat_Destroy,
    (ActorFunc)EnPeehat_Update,
    (ActorFunc)EnPeehat_Draw,
    (ActorFunc)EnPeehat_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_WOOD,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 50, 160, -70, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElemInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElemInit,
};

static ColliderQuadInit sQuadInit = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, PEAHAT_DMG_EFF_NUT),
    /* Deku stick    */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Slingshot     */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
    /* Explosive     */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Boomerang     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_BOOMERANG),
    /* Normal arrow  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Hammer swing  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Hookshot      */ DMG_ENTRY(2, PEAHAT_DMG_EFF_HOOKSHOT),
    /* Kokiri sword  */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
    /* Master sword  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Giant's Knife */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
    /* Fire arrow    */ DMG_ENTRY(4, PEAHAT_DMG_EFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Light arrow   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Unk arrow 1   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Unk arrow 2   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Unk arrow 3   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Fire magic    */ DMG_ENTRY(3, PEAHAT_DMG_EFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_LIGHT_ICE_ARROW),
    /* Light magic   */ DMG_ENTRY(0, PEAHAT_DMG_EFF_LIGHT_ICE_ARROW),
    /* Shield        */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
    /* Mirror Ray    */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
    /* Kokiri spin   */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
    /* Giant spin    */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
    /* Master spin   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Kokiri jump   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
    /* Giant jump    */ DMG_ENTRY(8, PEAHAT_DMG_EFF_ATTACK),
    /* Master jump   */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
    /* Unknown 1     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
    /* Unblockable   */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
    /* Hammer jump   */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
    /* Unknown 2     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 700, ICHAIN_STOP),
};

void EnPeehat_SetupAction(EnPeehat* pthis, EnPeehatActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnPeehat_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat* pthis = (EnPeehat*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 36.0f * 0.001f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gPeehatSkel, &gPeehatRisingAnim, pthis->jointTable, pthis->morphTable,
                   24);
    ActorShape_Init(&pthis->actor.shape, 100.0f, ActorShadow_DrawCircle, 27.0f);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->unk2D4 = 0;
    pthis->actor.world.rot.y = 0;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.health = 6;
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    pthis->actor.floorHeight = pthis->actor.world.pos.y;
    Collider_InitCylinder(globalCtx, &pthis->colCylinder);
    Collider_SetCylinder(globalCtx, &pthis->colCylinder, &pthis->actor, &sCylinderInit);
    Collider_InitQuad(globalCtx, &pthis->colQuad);
    Collider_SetQuad(globalCtx, &pthis->colQuad, &pthis->actor, &sQuadInit);
    Collider_InitJntSph(globalCtx, &pthis->colJntSph);
    Collider_SetJntSph(globalCtx, &pthis->colJntSph, &pthis->actor, &sJntSphInit, pthis->colJntSphItemList);

    pthis->actor.naviEnemyId = 0x48;
    pthis->xzDistToRise = 740.0f;
    pthis->xzDistMax = 1200.0f;
    pthis->actor.uncullZoneForward = 4000.0f;
    pthis->actor.uncullZoneScale = 800.0f;
    pthis->actor.uncullZoneDownward = 1800.0f;
    switch (pthis->actor.params) {
        case PEAHAT_TYPE_GROUNDED:
            EnPeehat_Ground_SetStateGround(pthis);
            break;
        case PEAHAT_TYPE_FLYING:
            pthis->actor.uncullZoneForward = 4200.0f;
            pthis->xzDistToRise = 2800.0f;
            pthis->xzDistMax = 1400.0f;
            EnPeehat_Flying_SetStateGround(pthis);
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            break;
        case PEAHAT_TYPE_LARVA:
            pthis->actor.scale.x = pthis->actor.scale.z = 0.006f;
            pthis->actor.scale.y = 0.003f;
            pthis->colCylinder.dim.radius = 25;
            pthis->colCylinder.dim.height = 15;
            pthis->colCylinder.dim.yShift = -5;
            pthis->colCylinder.info.bumper.dmgFlags = 0x1F824;
            pthis->colQuad.base.atFlags = AT_ON | AT_TYPE_ENEMY;
            pthis->colQuad.base.acFlags = AC_ON | AC_TYPE_PLAYER;
            pthis->actor.naviEnemyId = 0x49; // Larva
            EnPeehat_Larva_SetStateSeekPlayer(pthis);
            break;
    }
}

void EnPeehat_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat* pthis = (EnPeehat*)thisx;
    EnPeehat* parent;

    Collider_DestroyCylinder(globalCtx, &pthis->colCylinder);
    Collider_DestroyJntSph(globalCtx, &pthis->colJntSph);

    // If PEAHAT_TYPE_LARVA, decrement total larva spawned
    if (pthis->actor.params > 0) {
        parent = (EnPeehat*)pthis->actor.parent;
        if (parent != NULL && parent->actor.update != NULL) {
            parent->unk2FA--;
        }
    }
}

void EnPeehat_SpawnDust(GlobalContext* globalCtx, EnPeehat* pthis, Vec3f* pos, f32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    Vec3f dustPos;
    Vec3f dustVel = { 0.0f, 8.0f, 0.0f };
    Vec3f dustAccel = { 0.0f, -1.5f, 0.0f };
    f32 rot; // radians
    s32 pScale;

    rot = (Rand_ZeroOne() - 0.5f) * 6.28f;
    dustPos.y = pthis->actor.floorHeight;
    dustPos.x = Math_SinF(rot) * arg3 + pos->x;
    dustPos.z = Math_CosF(rot) * arg3 + pos->z;
    dustAccel.x = (Rand_ZeroOne() - 0.5f) * arg5;
    dustAccel.z = (Rand_ZeroOne() - 0.5f) * arg5;
    dustVel.y += (Rand_ZeroOne() - 0.5f) * 4.0f;
    pScale = (Rand_ZeroOne() * 5 + 12) * arg6;
    EffectSsHahen_Spawn(globalCtx, &dustPos, &dustVel, &dustAccel, arg4, pScale, HAHEN_OBJECT_DEFAULT, 10, NULL);
}

/**
 * Handles being hit when on the ground
 */
void EnPeehat_HitWhenGrounded(EnPeehat* pthis, GlobalContext* globalCtx) {
    pthis->colCylinder.base.acFlags &= ~AC_HIT;
    if ((globalCtx->gameplayFrames & 0xF) == 0) {
        Vec3f itemDropPos = pthis->actor.world.pos;

        itemDropPos.y += 70.0f;
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &itemDropPos, 0x40);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &itemDropPos, 0x40);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &itemDropPos, 0x40);
        pthis->unk2D4 = 240;
    } else {
        s32 i;

        pthis->colCylinder.base.acFlags &= ~AC_HIT;
        for (i = MAX_LARVA - pthis->unk2FA; i > 0; i--) {
            Actor* larva =
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_PEEHAT,
                                   Rand_CenteredFloat(25.0f) + pthis->actor.world.pos.x,
                                   Rand_CenteredFloat(25.0f) + (pthis->actor.world.pos.y + 50.0f),
                                   Rand_CenteredFloat(25.0f) + pthis->actor.world.pos.z, 0, 0, 0, PEAHAT_TYPE_LARVA);

            if (larva != NULL) {
                larva->velocity.y = 6.0f;
                larva->shape.rot.y = larva->world.rot.y = Rand_CenteredFloat(0xFFFF);
                pthis->unk2FA++;
            }
        }
        pthis->unk2D4 = 8;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_DAMAGE);
}

void EnPeehat_Ground_SetStateGround(EnPeehat* pthis) {
    Animation_Change(&pthis->skelAnime, &gPeehatRisingAnim, 0.0f, 3.0f, Animation_GetLastFrame(&gPeehatRisingAnim),
                     ANIMMODE_ONCE, 0.0f);
    pthis->seekPlayerTimer = 600;
    pthis->unk2D4 = 0;
    pthis->unk2FA = 0;
    pthis->state = PEAHAT_STATE_3;
    pthis->colCylinder.base.acFlags &= ~AC_HIT;
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateGround);
}

void EnPeehat_Ground_StateGround(EnPeehat* pthis, GlobalContext* globalCtx) {
    if (IS_DAY) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        if (pthis->riseDelayTimer == 0) {
            if (pthis->actor.xzDistToPlayer < pthis->xzDistToRise) {
                EnPeehat_Ground_SetStateRise(pthis);
            }
        } else {
            Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 10.0f, 0.0f);
            pthis->riseDelayTimer--;
        }
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 50.0f, 0.0f);
        if (pthis->unk2D4 != 0) {
            pthis->unk2D4--;
            if (pthis->unk2D4 & 4) {
                Math_SmoothStepToF(&pthis->scaleShift, 0.205f, 1.0f, 0.235f, 0.0f);
            } else {
                Math_SmoothStepToF(&pthis->scaleShift, 0.0f, 1.0f, 0.005f, 0.0f);
            }
        } else if (pthis->colCylinder.base.acFlags & AC_HIT) {
            EnPeehat_HitWhenGrounded(pthis, globalCtx);
        }
    }
}

void EnPeehat_Flying_SetStateGround(EnPeehat* pthis) {
    Animation_Change(&pthis->skelAnime, &gPeehatRisingAnim, 0.0f, 3.0f, Animation_GetLastFrame(&gPeehatRisingAnim),
                     ANIMMODE_ONCE, 0.0f);
    pthis->seekPlayerTimer = 400;
    pthis->unk2D4 = 0;
    pthis->unk2FA = 0; //! @bug: overwrites number of child larva spawned, allowing for more than MAX_LARVA spawns
    pthis->state = PEAHAT_STATE_4;
    EnPeehat_SetupAction(pthis, EnPeehat_Flying_StateGrounded);
}

void EnPeehat_Flying_StateGrounded(EnPeehat* pthis, GlobalContext* globalCtx) {
    if (IS_DAY) {
        if (pthis->actor.xzDistToPlayer < pthis->xzDistToRise) {
            EnPeehat_Flying_SetStateRise(pthis);
        }
    } else {
        Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 50.0f, 0.0f);
        if (pthis->unk2D4 != 0) {
            pthis->unk2D4--;
            if (pthis->unk2D4 & 4) {
                Math_SmoothStepToF(&pthis->scaleShift, 0.205f, 1.0f, 0.235f, 0.0f);
            } else {
                Math_SmoothStepToF(&pthis->scaleShift, 0.0f, 1.0f, 0.005f, 0.0f);
            }
        } else if (pthis->colCylinder.base.acFlags & AC_HIT) {
            EnPeehat_HitWhenGrounded(pthis, globalCtx);
        }
    }
}

void EnPeehat_Flying_SetStateFly(EnPeehat* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPeehatFlyingAnim);
    pthis->state = PEAHAT_STATE_FLY;
    EnPeehat_SetupAction(pthis, EnPeehat_Flying_StateFly);
}

void EnPeehat_Flying_StateFly(EnPeehat* pthis, GlobalContext* globalCtx) {
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_FLY - SFX_FLAG);
    SkelAnime_Update(&pthis->skelAnime);
    if (!IS_DAY || pthis->xzDistToRise < pthis->actor.xzDistToPlayer) {
        EnPeehat_Flying_SetStateLanding(pthis);
    } else if (pthis->actor.xzDistToPlayer < pthis->xzDistMax) {
        if (pthis->unk2FA < MAX_LARVA && (globalCtx->gameplayFrames & 7) == 0) {
            Actor* larva = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_PEEHAT,
                                              Rand_CenteredFloat(25.0f) + pthis->actor.world.pos.x,
                                              Rand_CenteredFloat(5.0f) + pthis->actor.world.pos.y,
                                              Rand_CenteredFloat(25.0f) + pthis->actor.world.pos.z, 0, 0, 0, 1);
            if (larva != NULL) {
                larva->shape.rot.y = larva->world.rot.y = Rand_CenteredFloat(0xFFFF);
                pthis->unk2FA++;
            }
        }
    }
    pthis->bladeRot += pthis->bladeRotVel;
}

void EnPeehat_Ground_SetStateRise(EnPeehat* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gPeehatRisingAnim);

    if (pthis->state != PEAHAT_STATE_STUNNED) {
        Animation_Change(&pthis->skelAnime, &gPeehatRisingAnim, 0.0f, 3.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    }
    pthis->state = PEAHAT_STATE_8;
    pthis->animTimer = lastFrame;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_UP);
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateRise);
}

void EnPeehat_Ground_StateRise(EnPeehat* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0.0f, 1.0f, 50.0f, 0.0f);
    if (Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 800, 0) == 0) {
        if (pthis->animTimer != 0) {
            pthis->animTimer--;
            if (pthis->skelAnime.playSpeed == 0.0f) {
                if (pthis->animTimer == 0) {
                    pthis->animTimer = 40;
                    pthis->skelAnime.playSpeed = 1.0f;
                }
            }
        }
        if (SkelAnime_Update(&pthis->skelAnime) || pthis->animTimer == 0) {
            EnPeehat_Ground_SetStateHover(pthis);
        } else {
            pthis->actor.world.pos.y += 6.5f;
        }
        if (pthis->actor.world.pos.y - pthis->actor.floorHeight < 80.0f) {
            Vec3f pos = pthis->actor.world.pos;
            pos.y = pthis->actor.floorHeight;
            func_80033480(globalCtx, &pos, 90.0f, 1, 0x96, 100, 1);
        }
    }
    EnPeehat_SpawnDust(globalCtx, pthis, &pthis->actor.world.pos, 75.0f, 2, 1.05f, 2.0f);
    Math_SmoothStepToF(&pthis->scaleShift, 0.075f, 1.0f, 0.005f, 0.0f);
    pthis->bladeRot += pthis->bladeRotVel;
}

void EnPeehat_Flying_SetStateRise(EnPeehat* pthis) {
    f32 lastFrame;

    lastFrame = Animation_GetLastFrame(&gPeehatRisingAnim);
    if (pthis->state != PEAHAT_STATE_STUNNED) {
        Animation_Change(&pthis->skelAnime, &gPeehatRisingAnim, 0.0f, 3.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    }
    pthis->state = PEAHAT_STATE_9;
    pthis->animTimer = lastFrame;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_UP);
    EnPeehat_SetupAction(pthis, EnPeehat_Flying_StateRise);
}

void EnPeehat_Flying_StateRise(EnPeehat* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.shape.yOffset, 0.0f, 1.0f, 50.0f, 0.0f);
    if (Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 800, 0) == 0) {
        if (pthis->animTimer != 0) {
            pthis->animTimer--;
            if (pthis->skelAnime.playSpeed == 0.0f) {
                if (pthis->animTimer == 0) {
                    pthis->animTimer = 40;
                    pthis->skelAnime.playSpeed = 1.0f;
                }
            }
        }
        if (SkelAnime_Update(&pthis->skelAnime) || pthis->animTimer == 0) {
            //! @bug: overwrites number of child larva spawned, allowing for more than MAX_LARVA spawns
            pthis->unk2FA = 0;
            EnPeehat_Flying_SetStateFly(pthis);
        } else {
            pthis->actor.world.pos.y += 18.0f;
        }
        if (pthis->actor.world.pos.y - pthis->actor.floorHeight < 80.0f) {
            Vec3f pos = pthis->actor.world.pos;
            pos.y = pthis->actor.floorHeight;
            func_80033480(globalCtx, &pos, 90.0f, 1, 0x96, 100, 1);
        }
    }
    EnPeehat_SpawnDust(globalCtx, pthis, &pthis->actor.world.pos, 75.0f, 2, 1.05f, 2.0f);
    Math_SmoothStepToF(&pthis->scaleShift, 0.075f, 1.0f, 0.005f, 0.0f);
    pthis->bladeRot += pthis->bladeRotVel;
}

void EnPeehat_Ground_SetStateSeekPlayer(EnPeehat* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPeehatFlyingAnim);
    pthis->state = PEAHAT_STATE_SEEK_PLAYER;
    pthis->unk2E0 = 0.0f;
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateSeekPlayer);
}

void EnPeehat_Ground_StateSeekPlayer(EnPeehat* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 3.0f, 1.0f, 0.25f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 80.0f, 1.0f, 3.0f, 0.0f);
    if (pthis->seekPlayerTimer <= 0) {
        EnPeehat_Ground_SetStateLanding(pthis);
        pthis->riseDelayTimer = 40;
    } else {
        pthis->seekPlayerTimer--;
    }
    if (IS_DAY && (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < pthis->xzDistMax)) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 1000, 0);
        if (pthis->unk2FA != 0) {
            pthis->actor.shape.rot.y += 0x1C2;
        } else {
            pthis->actor.shape.rot.y -= 0x1C2;
        }
    } else {
        EnPeehat_Ground_SetStateReturnHome(pthis);
    }
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 500, 0);
    pthis->bladeRot += pthis->bladeRotVel;
    Math_SmoothStepToF(&pthis->scaleShift, 0.075f, 1.0f, 0.005f, 0.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_FLY - SFX_FLAG);
}

void EnPeehat_Larva_SetStateSeekPlayer(EnPeehat* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPeehatFlyingAnim);
    pthis->state = PEAHAT_STATE_SEEK_PLAYER;
    pthis->unk2D4 = 0;
    EnPeehat_SetupAction(pthis, EnPeehat_Larva_StateSeekPlayer);
}

void EnPeehat_Larva_StateSeekPlayer(EnPeehat* pthis, GlobalContext* globalCtx) {
    f32 speedXZ = 5.3f;

    if (pthis->actor.xzDistToPlayer <= 5.3f) {
        speedXZ = pthis->actor.xzDistToPlayer + 0.0005f;
    }
    if (pthis->actor.parent != NULL && pthis->actor.parent->update == NULL) {
        pthis->actor.parent = NULL;
    }
    pthis->actor.speedXZ = speedXZ;
    if (pthis->actor.world.pos.y - pthis->actor.floorHeight >= 70.0f) {
        Math_SmoothStepToF(&pthis->actor.velocity.y, -1.3f, 1.0f, 0.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->actor.velocity.y, -0.135f, 1.0f, 0.05f, 0.0f);
    }
    if (pthis->unk2D4 == 0) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 830, 0);
    } else {
        pthis->unk2D4--;
    }
    pthis->actor.shape.rot.y += 0x15E;
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 500, 0);
    pthis->bladeRot += pthis->bladeRotVel;
    Math_SmoothStepToF(&pthis->scaleShift, 0.075f, 1.0f, 0.005f, 0.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_SM_FLY - SFX_FLAG);
    if (pthis->colQuad.base.atFlags & AT_BOUNCED) {
        pthis->actor.colChkInfo.health = 0;
        pthis->colQuad.base.acFlags = pthis->colQuad.base.acFlags & ~AC_BOUNCED;
        EnPeehat_SetStateAttackRecoil(pthis);
    } else if ((pthis->colQuad.base.atFlags & AT_HIT) || (pthis->colCylinder.base.acFlags & AC_HIT) ||
               (pthis->actor.bgCheckFlags & 1)) {
        Player* player = GET_PLAYER(globalCtx);
        pthis->colQuad.base.atFlags &= ~AT_HIT;
        if (!(pthis->colCylinder.base.acFlags & AC_HIT) && &player->actor == pthis->colQuad.base.at) {
            if (Rand_ZeroOne() > 0.5f) {
                pthis->actor.world.rot.y += 0x2000;
            } else {
                pthis->actor.world.rot.y -= 0x2000;
            }
            pthis->unk2D4 = 40;
        } else if (pthis->colCylinder.base.acFlags & AC_HIT || pthis->actor.bgCheckFlags & 1) {
            Vec3f zeroVec = { 0, 0, 0 };
            s32 i;
            for (i = 4; i >= 0; i--) {
                Vec3f pos;
                pos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
                pos.y = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y;
                pos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
                EffectSsDeadDb_Spawn(globalCtx, &pos, &zeroVec, &zeroVec, 40, 7, 255, 255, 255, 255, 255, 0, 0, 1, 9,
                                     1);
            }
        }
        if (&player->actor != pthis->colQuad.base.at || pthis->colCylinder.base.acFlags & AC_HIT) {
            if (!(pthis->actor.bgCheckFlags & 1)) {
                EffectSsDeadSound_SpawnStationary(globalCtx, &pthis->actor.projectedPos, NA_SE_EN_PIHAT_SM_DEAD, 1, 1,
                                                  40);
            }
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x20);
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnPeehat_Ground_SetStateLanding(EnPeehat* pthis) {
    pthis->state = PEAHAT_STATE_LANDING;
    Animation_PlayOnce(&pthis->skelAnime, &gPeehatLandingAnim);
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateLanding);
}

void EnPeehat_Ground_StateLanding(EnPeehat* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 50.0f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 50, 0);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnPeehat_Ground_SetStateGround(pthis);
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_LAND);
    } else if (pthis->actor.floorHeight < pthis->actor.world.pos.y) {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 0.3f, 3.5f, 0.25f);
        if (pthis->actor.world.pos.y - pthis->actor.floorHeight < 60.0f) {
            Vec3f pos = pthis->actor.world.pos;
            pos.y = pthis->actor.floorHeight;
            func_80033480(globalCtx, &pos, 80.0f, 1, 150, 100, 1);
            EnPeehat_SpawnDust(globalCtx, pthis, &pos, 75.0f, 2, 1.05f, 2.0f);
        }
    }
    Math_SmoothStepToS(&pthis->bladeRotVel, 0, 1, 100, 0);
    pthis->bladeRot += pthis->bladeRotVel;
}

void EnPeehat_Flying_SetStateLanding(EnPeehat* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gPeehatLandingAnim);
    pthis->state = PEAHAT_STATE_LANDING;
    EnPeehat_SetupAction(pthis, EnPeehat_Flying_StateLanding);
}

void EnPeehat_Flying_StateLanding(EnPeehat* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.shape.yOffset, -1000.0f, 1.0f, 50.0f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 50, 0);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnPeehat_Flying_SetStateGround(pthis);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_LAND);
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
    } else if (pthis->actor.floorHeight < pthis->actor.world.pos.y) {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 0.3f, 13.5f, 0.25f);
        if (pthis->actor.world.pos.y - pthis->actor.floorHeight < 60.0f) {
            Vec3f pos = pthis->actor.world.pos;
            pos.y = pthis->actor.floorHeight;
            func_80033480(globalCtx, &pos, 80.0f, 1, 150, 100, 1);
            EnPeehat_SpawnDust(globalCtx, pthis, &pos, 75.0f, 2, 1.05f, 2.0f);
        }
    }
    Math_SmoothStepToS(&pthis->bladeRotVel, 0, 1, 100, 0);
    pthis->bladeRot += pthis->bladeRotVel;
}

void EnPeehat_Ground_SetStateHover(EnPeehat* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPeehatFlyingAnim);
    pthis->actor.speedXZ = Rand_ZeroOne() * 0.5f + 2.5f;
    pthis->unk2D4 = Rand_ZeroOne() * 10 + 10;
    pthis->state = PEAHAT_STATE_15;
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateHover);
}

void EnPeehat_Ground_StateHover(EnPeehat* pthis, GlobalContext* globalCtx) {
    f32 cos;
    Player* player = GET_PLAYER(globalCtx);

    // hover but don't gain altitude
    if (pthis->actor.world.pos.y - pthis->actor.floorHeight > 75.0f) {
        pthis->actor.world.pos.y -= 1.0f;
    }
    pthis->actor.world.pos.y += Math_CosF(pthis->unk2E0) * 1.4f;
    cos = Math_CosF(pthis->unk2E0) * 0.18f;
    pthis->unk2E0 += ((0.0f <= cos) ? cos : -cos) + 0.07f;
    pthis->unk2D4--;
    if (pthis->unk2D4 <= 0) {
        pthis->actor.speedXZ = Rand_ZeroOne() * 0.5f + 2.5f;
        pthis->unk2D4 = Rand_ZeroOne() * 10.0f + 10.0f;
        pthis->unk2F4 = (Rand_ZeroOne() - 0.5f) * 1000.0f;
    }
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.world.rot.y += pthis->unk2F4;
    if (pthis->seekPlayerTimer <= 0) {
        EnPeehat_Ground_SetStateLanding(pthis);
        pthis->riseDelayTimer = 40;
    } else {
        pthis->seekPlayerTimer--;
    }
    pthis->actor.shape.rot.y += 0x15E;
    // if daytime, and the player is close to the initial spawn position
    if (IS_DAY && Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < pthis->xzDistMax) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        EnPeehat_Ground_SetStateSeekPlayer(pthis);
        pthis->unk2FA = globalCtx->gameplayFrames & 1;
    } else {
        EnPeehat_Ground_SetStateReturnHome(pthis);
    }
    Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 500, 0);
    pthis->bladeRot += pthis->bladeRotVel;
    Math_SmoothStepToF(&pthis->scaleShift, 0.075f, 1.0f, 0.005f, 0.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_FLY - SFX_FLAG);
}

void EnPeehat_Ground_SetStateReturnHome(EnPeehat* pthis) {
    pthis->state = PEAHAT_STATE_RETURN_HOME;
    pthis->actor.speedXZ = 2.5f;
    EnPeehat_SetupAction(pthis, EnPeehat_Ground_StateReturnHome);
}

void EnPeehat_Ground_StateReturnHome(EnPeehat* pthis, GlobalContext* globalCtx) {
    f32 cos;
    s16 yRot;
    Player* player;

    player = GET_PLAYER(globalCtx);
    if (pthis->actor.world.pos.y - pthis->actor.floorHeight > 75.0f) {
        pthis->actor.world.pos.y -= 1.0f;
    } else {
        pthis->actor.world.pos.y += 1.0f;
    }
    pthis->actor.world.pos.y += Math_CosF(pthis->unk2E0) * 1.4f;
    cos = Math_CosF(pthis->unk2E0) * 0.18f;
    pthis->unk2E0 += ((0.0f <= cos) ? cos : -cos) + 0.07f;
    yRot = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
    Math_SmoothStepToS(&pthis->actor.world.rot.y, yRot, 1, 600, 0);
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 4500, 1, 600, 0);
    pthis->actor.shape.rot.y += 0x15E;
    pthis->bladeRot += pthis->bladeRotVel;
    if (Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) < 2.0f) {
        EnPeehat_Ground_SetStateLanding(pthis);
        pthis->riseDelayTimer = 60;
    }
    if (IS_DAY && Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < pthis->xzDistMax) {
        pthis->seekPlayerTimer = 400;
        EnPeehat_Ground_SetStateSeekPlayer(pthis);
        pthis->unk2FA = (globalCtx->gameplayFrames & 1);
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_FLY - SFX_FLAG);
}

void EnPeehat_SetStateAttackRecoil(EnPeehat* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gPeehatRecoilAnim, -4.0f);
    pthis->state = PEAHAT_STATE_ATTACK_RECOIL;
    pthis->actor.speedXZ = -9.0f;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    EnPeehat_SetupAction(pthis, EnPeehat_StateAttackRecoil);
}

void EnPeehat_StateAttackRecoil(EnPeehat* pthis, GlobalContext* globalCtx) {
    pthis->bladeRot += pthis->bladeRotVel;
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.speedXZ += 0.5f;
    if (pthis->actor.speedXZ == 0.0f) {
        // Is PEAHAT_TYPE_LARVA
        if (pthis->actor.params > 0) {
            Vec3f zeroVec = { 0, 0, 0 };
            s32 i;
            for (i = 4; i >= 0; i--) {
                Vec3f pos;
                pos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
                pos.y = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y;
                pos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
                EffectSsDeadDb_Spawn(globalCtx, &pos, &zeroVec, &zeroVec, 40, 7, 255, 255, 255, 255, 255, 0, 0, 1, 9,
                                     1);
            }
            Actor_Kill(&pthis->actor);
        } else {
            EnPeehat_Ground_SetStateSeekPlayer(pthis);
            // Is PEAHAT_TYPE_GROUNDED
            if (pthis->actor.params < 0) {
                pthis->unk2FA = (pthis->unk2FA != 0) ? 0 : 1;
            }
        }
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_FLY - SFX_FLAG);
}

void EnPeehat_SetStateBoomerangStunned(EnPeehat* pthis) {
    pthis->state = PEAHAT_STATE_STUNNED;
    if (pthis->actor.floorHeight < pthis->actor.world.pos.y) {
        pthis->actor.speedXZ = -9.0f;
    }
    pthis->bladeRotVel = 0;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    Actor_SetColorFilter(&pthis->actor, 0, 200, 0, 80);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnPeehat_SetupAction(pthis, EnPeehat_StateBoomerangStunned);
}

void EnPeehat_StateBoomerangStunned(EnPeehat* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight, 1.0f, 8.0f, 0.0f);
    if (pthis->actor.colorFilterTimer == 0) {
        EnPeehat_Ground_SetStateRise(pthis);
    }
}

void EnPeehat_Adult_SetStateDie(EnPeehat* pthis) {
    pthis->bladeRotVel = 0;
    pthis->isStateDieFirstUpdate = 1;
    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 8);
    pthis->state = PEAHAT_STATE_DYING;
    pthis->scaleShift = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    EnPeehat_SetupAction(pthis, EnPeehat_Adult_StateDie);
}

void EnPeehat_Adult_StateDie(EnPeehat* pthis, GlobalContext* globalCtx) {
    if (pthis->isStateDieFirstUpdate) {
        pthis->unk2D4--;
        if (pthis->unk2D4 <= 0 || pthis->actor.colChkInfo.health == 0) {
            Animation_MorphToPlayOnce(&pthis->skelAnime, &gPeehatRecoilAnim, -4.0f);
            pthis->bladeRotVel = 4000;
            pthis->unk2D4 = 14;
            pthis->actor.speedXZ = 0;
            pthis->actor.velocity.y = 6;
            pthis->isStateDieFirstUpdate = 0;
            pthis->actor.shape.rot.z = pthis->actor.shape.rot.x = 0;
        } else if (pthis->actor.colorFilterTimer & 4) {
            Math_SmoothStepToF(&pthis->scaleShift, 0.205f, 1.0f, 0.235f, 0);
        } else {
            Math_SmoothStepToF(&pthis->scaleShift, 0, 1.0f, 0.005f, 0);
        }
    } else {
        SkelAnime_Update(&pthis->skelAnime);
        pthis->bladeRot += pthis->bladeRotVel;
        Math_SmoothStepToS(&pthis->bladeRotVel, 4000, 1, 250, 0);
        if (pthis->actor.colChkInfo.health == 0) {
            pthis->actor.scale.x -= 0.0015f;
            Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
        }
        if (Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 88.5f, 1.0f, 3.0f, 0.0f) == 0.0f &&
            pthis->actor.world.pos.y - pthis->actor.floorHeight < 59.0f) {
            Vec3f pos = pthis->actor.world.pos;
            pos.y = pthis->actor.floorHeight;
            func_80033480(globalCtx, &pos, 80.0f, 1, 150, 100, 1);
            EnPeehat_SpawnDust(globalCtx, pthis, &pos, 75.0f, 2, 1.05f, 2.0f);
        }
        if (pthis->actor.speedXZ < 0) {
            pthis->actor.speedXZ += 0.25f;
        }
        pthis->unk2D4--;
        if (pthis->unk2D4 <= 0) {
            if (pthis->actor.colChkInfo.health == 0) {
                EnPeehat_SetStateExplode(pthis);
                // if PEAHAT_TYPE_GROUNDED
            } else if (pthis->actor.params < 0) {
                EnPeehat_Ground_SetStateHover(pthis);
                pthis->riseDelayTimer = 60;
            } else {
                EnPeehat_Flying_SetStateFly(pthis);
            }
        }
    }
}

void EnPeehat_SetStateExplode(EnPeehat* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPeehatFlyingAnim);
    pthis->state = PEAHAT_STATE_EXPLODE;
    pthis->animTimer = 5;
    pthis->unk2E0 = 0.0f;
    EnPeehat_SetupAction(pthis, EnPeehat_StateExplode);
}

void EnPeehat_StateExplode(EnPeehat* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;
    s32 pad[2];

    if (pthis->animTimer == 5) {
        bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                   pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0x602, 0);
        if (bomb != NULL) {
            bomb->timer = 0;
        }
    }
    pthis->animTimer--;
    if (pthis->animTimer == 0) {
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x40);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x40);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x40);
        Actor_Kill(&pthis->actor);
    }
}

void EnPeehat_Adult_CollisionCheck(EnPeehat* pthis, GlobalContext* globalCtx) {
    if ((pthis->colCylinder.base.acFlags & AC_BOUNCED) || (pthis->colQuad.base.acFlags & AC_BOUNCED)) {
        pthis->colQuad.base.acFlags &= ~AC_BOUNCED;
        pthis->colCylinder.base.acFlags &= ~AC_BOUNCED;
        pthis->colJntSph.base.acFlags &= ~AC_HIT;
    } else if (pthis->colJntSph.base.acFlags & AC_HIT) {
        pthis->colJntSph.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlagJntSph(&pthis->actor, &pthis->colJntSph, 1);
        if (pthis->actor.colChkInfo.damageEffect == PEAHAT_DMG_EFF_NUT ||
            pthis->actor.colChkInfo.damageEffect == PEAHAT_DMG_EFF_LIGHT_ICE_ARROW) {
            return;
        }
        if (pthis->actor.colChkInfo.damageEffect == PEAHAT_DMG_EFF_HOOKSHOT) {
            pthis->actor.colChkInfo.health = 0;
        } else if (pthis->actor.colChkInfo.damageEffect == PEAHAT_DMG_EFF_BOOMERANG) {
            if (pthis->state != PEAHAT_STATE_STUNNED) {
                EnPeehat_SetStateBoomerangStunned(pthis);
            }
            return;
        } else {
            Actor_ApplyDamage(&pthis->actor);
            Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 8);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PIHAT_DAMAGE);
        }

        if (pthis->actor.colChkInfo.damageEffect == PEAHAT_DMG_EFF_FIRE) {
            Vec3f pos;
            s32 i;
            for (i = 4; i >= 0; i--) {
                pos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
                pos.y = Rand_ZeroOne() * 25.0f + pthis->actor.world.pos.y;
                pos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
                EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &pos, 70, 0, 0, -1);
            }
            Actor_SetColorFilter(&pthis->actor, 0x4000, 200, 0, 100);
        }
        if (pthis->actor.colChkInfo.health == 0) {
            EnPeehat_Adult_SetStateDie(pthis);
        }
    }
}

void EnPeehat_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat* pthis = (EnPeehat*)thisx;
    s32 i;
    Player* player = GET_PLAYER(globalCtx);

    // If Adult Peahat
    if (thisx->params <= 0) {
        EnPeehat_Adult_CollisionCheck(pthis, globalCtx);
    }
    if (thisx->colChkInfo.damageEffect != PEAHAT_DMG_EFF_LIGHT_ICE_ARROW) {
        if (thisx->speedXZ != 0.0f || thisx->velocity.y != 0.0f) {
            Actor_MoveForward(thisx);
            Actor_UpdateBgCheckInfo(globalCtx, thisx, 25.0f, 30.0f, 30.0f, 5);
        }

        pthis->actionFunc(pthis, globalCtx);
        if ((globalCtx->gameplayFrames & 0x7F) == 0) {
            pthis->jiggleRotInc = (Rand_ZeroOne() * 0.25f) + 0.5f;
        }
        pthis->jiggleRot += pthis->jiggleRotInc;
    }
    // if PEAHAT_TYPE_GROUNDED
    if (thisx->params < 0) {
        // Set the Z-Target point on the Peahat's weak point
        thisx->focus.pos.x = pthis->colJntSph.elements[0].dim.worldSphere.center.x;
        thisx->focus.pos.y = pthis->colJntSph.elements[0].dim.worldSphere.center.y;
        thisx->focus.pos.z = pthis->colJntSph.elements[0].dim.worldSphere.center.z;
        if (pthis->state == PEAHAT_STATE_SEEK_PLAYER) {
            Math_SmoothStepToS(&thisx->shape.rot.x, 6000, 1, 300, 0);
        } else {
            Math_SmoothStepToS(&thisx->shape.rot.x, 0, 1, 300, 0);
        }
    } else {
        thisx->focus.pos = thisx->world.pos;
    }
    Collider_UpdateCylinder(thisx, &pthis->colCylinder);
    if (thisx->colChkInfo.health > 0) {
        // If Adult Peahat
        if (thisx->params <= 0) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colJntSph.base);
            if (thisx->colorFilterTimer == 0 || !(thisx->colorFilterParams & 0x4000)) {
                if (pthis->state != PEAHAT_STATE_EXPLODE) {
                    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colJntSph.base);
                }
            }
        }
        if (thisx->params != PEAHAT_TYPE_FLYING && pthis->colQuad.base.atFlags & AT_HIT) {
            pthis->colQuad.base.atFlags &= ~AT_HIT;
            if (&player->actor == pthis->colQuad.base.at) {
                EnPeehat_SetStateAttackRecoil(pthis);
            }
        }
    }
    if (pthis->state == PEAHAT_STATE_15 || pthis->state == PEAHAT_STATE_SEEK_PLAYER || pthis->state == PEAHAT_STATE_FLY ||
        pthis->state == PEAHAT_STATE_RETURN_HOME || pthis->state == PEAHAT_STATE_EXPLODE) {
        if (thisx->params != PEAHAT_TYPE_FLYING) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colQuad.base);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colQuad.base);
        }
        // if PEAHAT_TYPE_GROUNDED
        if (thisx->params < 0 && (thisx->flags & ACTOR_FLAG_UNCULLED)) {
            for (i = 1; i >= 0; i--) {
                Vec3f posResult;
                CollisionPoly* poly = NULL;
                s32 bgId;
                Vec3f* posB = &pthis->bladeTip[i];

                if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &thisx->world.pos, posB, &posResult, &poly, true, true,
                                            false, true, &bgId) == true) {
                    func_80033480(globalCtx, &posResult, 0.0f, 1, 300, 150, 1);
                    EnPeehat_SpawnDust(globalCtx, pthis, &posResult, 0.0f, 3, 1.05f, 1.5f);
                }
            }
        } else if (thisx->params != PEAHAT_TYPE_FLYING) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder.base);
        }
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder.base);
    }
    Math_SmoothStepToF(&pthis->scaleShift, 0.0f, 1.0f, 0.001f, 0.0f);
}

s32 EnPeehat_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                              void* thisx) {
    EnPeehat* pthis = (EnPeehat*)thisx;

    if (limbIndex == 4) {
        rot->x = -pthis->bladeRot;
    }
    if (limbIndex == 3 || (limbIndex == 23 && (pthis->state == PEAHAT_STATE_DYING || pthis->state == PEAHAT_STATE_3 ||
                                               pthis->state == PEAHAT_STATE_4))) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1946);
        Matrix_Push();
        Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
        Matrix_RotateX(pthis->jiggleRot * 0.115f, MTXMODE_APPLY);
        Matrix_RotateY(pthis->jiggleRot * 0.13f, MTXMODE_APPLY);
        Matrix_RotateZ(pthis->jiggleRot * 0.1f, MTXMODE_APPLY);
        Matrix_Scale(1.0f - pthis->scaleShift, pthis->scaleShift + 1.0f, 1.0f - pthis->scaleShift, MTXMODE_APPLY);
        Matrix_RotateZ(-(pthis->jiggleRot * 0.1f), MTXMODE_APPLY);
        Matrix_RotateY(-(pthis->jiggleRot * 0.13f), MTXMODE_APPLY);
        Matrix_RotateX(-(pthis->jiggleRot * 0.115f), MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1959),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, *dList);
        Matrix_Pop();
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1963);
        return true;
    }
    return false;
}

void EnPeehat_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {

    EnPeehat* pthis = (EnPeehat*)thisx;
    f32 damageYRot;

    if (limbIndex == 4) {
        Matrix_MultVec3f(&peahatBladeTip_101[0], &pthis->bladeTip[0]);
        Matrix_MultVec3f(&peahatBladeTip_101[1], &pthis->bladeTip[1]);
        return;
    }
    // is Adult Peahat
    if (limbIndex == 3 && pthis->actor.params <= 0) {
        damageYRot = 0.0f;
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1981);
        Matrix_Push();
        Matrix_Translate(-1000.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        Collider_UpdateSpheres(0, &pthis->colJntSph);
        Matrix_Translate(500.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        if (pthis->actor.colorFilterTimer != 0 && (pthis->actor.colorFilterParams & 0x4000)) {
            damageYRot = Math_SinS(pthis->actor.colorFilterTimer * 0x4E20) * 0.35f;
        }
        Matrix_RotateY(3.2f + damageYRot, MTXMODE_APPLY);
        Matrix_Scale(0.3f, 0.2f, 0.2f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1990),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, *dList);
        Matrix_Pop();
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_peehat.c", 1994);
    }
}

void EnPeehat_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat* pthis = (EnPeehat*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnPeehat_OverrideLimbDraw,
                      EnPeehat_PostLimbDraw, pthis);
    if (pthis->actor.speedXZ != 0.0f || pthis->actor.velocity.y != 0.0f) {
        Matrix_MultVec3f(&D_80AD285C_102[0], &pthis->colQuad.dim.quad[1]);
        Matrix_MultVec3f(&D_80AD285C_102[1], &pthis->colQuad.dim.quad[0]);
        Matrix_MultVec3f(&D_80AD285C_102[2], &pthis->colQuad.dim.quad[3]);
        Matrix_MultVec3f(&D_80AD285C_102[3], &pthis->colQuad.dim.quad[2]);
        Collider_SetQuadVertices(&pthis->colQuad, &pthis->colQuad.dim.quad[0], &pthis->colQuad.dim.quad[1],
                                 &pthis->colQuad.dim.quad[2], &pthis->colQuad.dim.quad[3]);
    }
}

void EnPeehat_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Peehat_InitVars = {
        ACTOR_EN_PEEHAT,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_PEEHAT,
        sizeof(EnPeehat),
        (ActorFunc)EnPeehat_Init,
        (ActorFunc)EnPeehat_Destroy,
        (ActorFunc)EnPeehat_Update,
        (ActorFunc)EnPeehat_Draw,
        (ActorFunc)EnPeehat_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_WOOD,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 50, 160, -70, { 0, 0, 0 } },
    };

    sJntSphInit = {
        {
            COLTYPE_HIT6,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElemInit,
    };

    sQuadInit = {
        {
            COLTYPE_METAL,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x10 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, PEAHAT_DMG_EFF_NUT),
        /* Deku stick    */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Slingshot     */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
        /* Explosive     */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Boomerang     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_BOOMERANG),
        /* Normal arrow  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Hammer swing  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Hookshot      */ DMG_ENTRY(2, PEAHAT_DMG_EFF_HOOKSHOT),
        /* Kokiri sword  */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
        /* Master sword  */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Giant's Knife */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
        /* Fire arrow    */ DMG_ENTRY(4, PEAHAT_DMG_EFF_FIRE),
        /* Ice arrow     */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Light arrow   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Unk arrow 1   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Unk arrow 2   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Unk arrow 3   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Fire magic    */ DMG_ENTRY(3, PEAHAT_DMG_EFF_FIRE),
        /* Ice magic     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_LIGHT_ICE_ARROW),
        /* Light magic   */ DMG_ENTRY(0, PEAHAT_DMG_EFF_LIGHT_ICE_ARROW),
        /* Shield        */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
        /* Mirror Ray    */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
        /* Kokiri spin   */ DMG_ENTRY(1, PEAHAT_DMG_EFF_ATTACK),
        /* Giant spin    */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
        /* Master spin   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Kokiri jump   */ DMG_ENTRY(2, PEAHAT_DMG_EFF_ATTACK),
        /* Giant jump    */ DMG_ENTRY(8, PEAHAT_DMG_EFF_ATTACK),
        /* Master jump   */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
        /* Unknown 1     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
        /* Unblockable   */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
        /* Hammer jump   */ DMG_ENTRY(4, PEAHAT_DMG_EFF_ATTACK),
        /* Unknown 2     */ DMG_ENTRY(0, PEAHAT_DMG_EFF_ATTACK),
    };

}

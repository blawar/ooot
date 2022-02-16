#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DH_Z_EN_DH_C
#include "actor_common.h"
#include "z_en_dh.h"
#include "objects/object_dh/object_dh.h"
#include "def/code_800EC960.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_10)


void EnDh_Init(Actor* pthis, GlobalContext* globalCtx);
void EnDh_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDh_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDh_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDh_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDh_SetupWait(EnDh* pthis);
void EnDh_SetupWalk(EnDh* pthis);
void EnDh_SetupAttack(EnDh* pthis);
void EnDh_SetupBurrow(EnDh* pthis);

void EnDh_Wait(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Walk(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Retreat(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Attack(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Burrow(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Damage(EnDh* pthis, GlobalContext* globalCtx);
void EnDh_Death(EnDh* pthis, GlobalContext* globalCtx);

ActorInit En_Dh_InitVars = {
    ACTOR_EN_DH,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DH,
    sizeof(EnDh),
    (ActorFunc)EnDh_Init,
    (ActorFunc)EnDh_Destroy,
    (ActorFunc)EnDh_Update,
    (ActorFunc)EnDh_Draw,
    (ActorFunc)EnDh_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000008, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 35, 70, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON | OCELEM_UNK3,
        },
        { 1, { { 0, 0, 0 }, 20 }, 100 },
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
    sJntSphElementsInit,
};

static DamageTable D_809EC620 = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0xF),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(0, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(2, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(2, 0xF),
    /* Giant spin    */ DMG_ENTRY(4, 0xF),
    /* Master spin   */ DMG_ENTRY(2, 0xF),
    /* Kokiri jump   */ DMG_ENTRY(4, 0xF),
    /* Giant jump    */ DMG_ENTRY(8, 0xF),
    /* Master jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xF),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x2F, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3500, ICHAIN_STOP),
};

void EnDh_SetupAction(EnDh* pthis, EnDhActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnDh_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDh* pthis = (EnDh*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.colChkInfo.damageTable = &D_809EC620;
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_dh_Skel_007E88, &object_dh_Anim_005880, pthis->jointTable,
                       pthis->limbRotTable, 16);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 64.0f);
    pthis->actor.params = ENDH_WAIT_UNDERGROUND;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.health = LINK_IS_ADULT ? 14 : 20;
    pthis->alpha = pthis->unk_258 = 255;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    Collider_InitCylinder(globalCtx, &pthis->collider1);
    Collider_SetCylinder(globalCtx, &pthis->collider1, &pthis->actor, &sCylinderInit);
    Collider_InitJntSph(globalCtx, &pthis->collider2);
    Collider_SetJntSph(globalCtx, &pthis->collider2, &pthis->actor, &sJntSphInit, pthis->elements);
    EnDh_SetupWait(pthis);
}

void EnDh_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDh* pthis = (EnDh*)thisx;

    func_800F5B58();
    Collider_DestroyCylinder(globalCtx, &pthis->collider1);
    Collider_DestroyJntSph(globalCtx, &pthis->collider2);
}

void EnDh_SpawnDebris(GlobalContext* globalCtx, EnDh* pthis, Vec3f* spawnPos, f32 spread, s32 arg4, f32 accelXZ,
                      f32 scale) {
    Vec3f pos;
    Vec3f vel = { 0.0f, 8.0f, 0.0f };
    Vec3f accel = { 0.0f, -1.5f, 0.0f };
    f32 spreadAngle;
    f32 scaleMod;

    spreadAngle = (Rand_ZeroOne() - 0.5f) * 6.28f;
    pos.y = pthis->actor.floorHeight;
    pos.x = (Math_SinF(spreadAngle) * spread) + spawnPos->x;
    pos.z = (Math_CosF(spreadAngle) * spread) + spawnPos->z;
    accel.x = (Rand_ZeroOne() - 0.5f) * accelXZ;
    accel.z = (Rand_ZeroOne() - 0.5f) * accelXZ;
    vel.y += (Rand_ZeroOne() - 0.5f) * 4.0f;
    scaleMod = (Rand_ZeroOne() * 5.0f) + 12.0f;
    EffectSsHahen_Spawn(globalCtx, &pos, &vel, &accel, arg4, scaleMod * scale, -1, 10, NULL);
}

void EnDh_SetupWait(EnDh* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_dh_Anim_003A8C);
    pthis->curAction = DH_WAIT;
    pthis->actor.world.pos.x = Rand_CenteredFloat(600.0f) + pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = Rand_CenteredFloat(600.0f) + pthis->actor.home.pos.z;
    pthis->actor.shape.yOffset = -15000.0f;
    pthis->dirtWaveSpread = pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.flags |= ACTOR_FLAG_7;
    pthis->dirtWavePhase = pthis->actionState = pthis->actor.params = ENDH_WAIT_UNDERGROUND;
    EnDh_SetupAction(pthis, EnDh_Wait);
}

void EnDh_Wait(EnDh* pthis, GlobalContext* globalCtx) {
    if ((s32)pthis->skelAnime.curFrame == 5) {
        func_800F5ACC(NA_BGM_MINI_BOSS);
    }
    if (Actor_GetCollidedExplosive(globalCtx, &pthis->collider1.base)) {
        pthis->actor.params = ENDH_START_ATTACK_BOMB;
    }
    if ((pthis->actor.params >= ENDH_START_ATTACK_GRAB) || (pthis->actor.params <= ENDH_HANDS_KILLED_4)) {
        switch (pthis->actionState) {
            case 0:
                pthis->actor.flags |= ACTOR_FLAG_0;
                pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
                pthis->actor.flags &= ~ACTOR_FLAG_7;
                pthis->actionState++;
                pthis->drawDirtWave++;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_HIDE);
            case 1:
                pthis->dirtWavePhase += 0x3A7;
                Math_SmoothStepToF(&pthis->dirtWaveSpread, 300.0f, 1.0f, 5.0f, 0.0f);
                pthis->dirtWaveHeight = Math_SinS(pthis->dirtWavePhase) * 55.0f;
                pthis->dirtWaveAlpha = (s16)(Math_SinS(pthis->dirtWavePhase) * 255.0f);
                EnDh_SpawnDebris(globalCtx, pthis, &pthis->actor.world.pos, pthis->dirtWaveSpread, 4, 2.05f, 1.2f);
                if (pthis->actor.shape.yOffset == 0.0f) {
                    pthis->drawDirtWave = false;
                    pthis->actionState++;
                } else if (pthis->dirtWavePhase > 0x12C0) {
                    pthis->actor.shape.yOffset += 500.0f;
                }
                break;
            case 2:
                EnDh_SetupWalk(pthis);
                break;
        }
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x7D0, 0);
        SkelAnime_Update(&pthis->skelAnime);
        if (pthis->actor.params != ENDH_START_ATTACK_BOMB) {
            func_8008EEAC(globalCtx, &pthis->actor);
        }
    }
}

void EnDh_SetupWalk(EnDh* pthis) {
    Animation_Change(&pthis->skelAnime, &object_dh_Anim_003A8C, 1.0f, 0.0f,
                     Animation_GetLastFrame(&object_dh_Anim_003A8C) - 3.0f, ANIMMODE_LOOP, -6.0f);
    pthis->curAction = DH_WALK;
    pthis->timer = 300;
    pthis->actor.speedXZ = 1.0f;
    EnDh_SetupAction(pthis, EnDh_Walk);
}

void EnDh_Walk(EnDh* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    SkelAnime_Update(&pthis->skelAnime);
    if (((s32)pthis->skelAnime.curFrame % 8) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_WALK);
    }
    if ((globalCtx->gameplayFrames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_LAUGH);
    }
    if (pthis->actor.xzDistToPlayer <= 100.0f) {
        pthis->actor.speedXZ = 0.0f;
        if (Actor_IsFacingPlayer(&pthis->actor, 60 * 0x10000 / 360)) {
            EnDh_SetupAttack(pthis);
        }
    } else if (--pthis->timer == 0) {
        EnDh_SetupBurrow(pthis);
    }
}

void EnDh_SetupRetreat(EnDh* pthis, GlobalContext* globalCtx) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_dh_Anim_005880, -4.0f);
    pthis->curAction = DH_RETREAT;
    pthis->timer = 70;
    pthis->actor.speedXZ = 1.0f;
    EnDh_SetupAction(pthis, EnDh_Retreat);
}

void EnDh_Retreat(EnDh* pthis, GlobalContext* globalCtx) {
    pthis->timer--;
    if (pthis->timer == 0) {
        pthis->retreat = false;
        EnDh_SetupBurrow(pthis);
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, (s16)(pthis->actor.yawTowardsPlayer + 0x8000), 1, 0xBB8, 0);
    }
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    SkelAnime_Update(&pthis->skelAnime);
}

void EnDh_SetupAttack(EnDh* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_dh_Anim_004658, -6.0f);
    pthis->timer = pthis->actionState = 0;
    pthis->curAction = DH_ATTACK;
    pthis->actor.speedXZ = 0.0f;
    EnDh_SetupAction(pthis, EnDh_Attack);
}

void EnDh_Attack(EnDh* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actionState++;
    } else if ((pthis->actor.xzDistToPlayer > 100.0f) || !Actor_IsFacingPlayer(&pthis->actor, 60 * 0x10000 / 360)) {
        Animation_Change(&pthis->skelAnime, &object_dh_Anim_004658, -1.0f, pthis->skelAnime.curFrame, 0.0f, ANIMMODE_ONCE,
                         -4.0f);
        pthis->actionState = 4;
        pthis->collider2.base.atFlags = pthis->collider2.elements[0].info.toucherFlags = AT_NONE; // also TOUCH_NONE
        pthis->collider2.elements[0].info.toucher.dmgFlags = pthis->collider2.elements[0].info.toucher.damage = 0;
    }
    switch (pthis->actionState) {
        case 1:
            Animation_PlayOnce(&pthis->skelAnime, &object_dh_Anim_001A3C);
            pthis->actionState++;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_BITE);
        case 0:
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x5DC, 0);
            break;
        case 2:
            if (pthis->skelAnime.curFrame >= 4.0f) {
                pthis->collider2.base.atFlags = pthis->collider2.elements[0].info.toucherFlags =
                    AT_ON | AT_TYPE_ENEMY; // also TOUCH_ON | TOUCH_SFX_WOOD
                pthis->collider2.elements[0].info.toucher.dmgFlags = 0xFFCFFFFF;
                pthis->collider2.elements[0].info.toucher.damage = 8;
            }
            if (pthis->collider2.base.atFlags & AT_BOUNCED) {
                pthis->collider2.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
                pthis->collider2.base.atFlags = pthis->collider2.elements[0].info.toucherFlags =
                    AT_NONE; // also TOUCH_NONE
                pthis->collider2.elements[0].info.toucher.dmgFlags = pthis->collider2.elements[0].info.toucher.damage = 0;
                pthis->actionState++;
            } else if (pthis->collider2.base.atFlags & AT_HIT) {
                pthis->collider2.base.atFlags &= ~AT_HIT;
                func_8002F71C(globalCtx, &pthis->actor, 8.0f, pthis->actor.shape.rot.y, 8.0f);
            }
            break;
        case 3:
            if ((pthis->actor.xzDistToPlayer <= 100.0f) && (Actor_IsFacingPlayer(&pthis->actor, 60 * 0x10000 / 360))) {
                Animation_Change(&pthis->skelAnime, &object_dh_Anim_004658, 1.0f, 20.0f,
                                 Animation_GetLastFrame(&object_dh_Anim_004658), ANIMMODE_ONCE, -6.0f);
                pthis->actionState = 0;
            } else {
                Animation_Change(&pthis->skelAnime, &object_dh_Anim_004658, -1.0f,
                                 Animation_GetLastFrame(&object_dh_Anim_004658), 0.0f, ANIMMODE_ONCE, -4.0f);
                pthis->actionState++;
                pthis->collider2.base.atFlags = pthis->collider2.elements[0].info.toucherFlags =
                    AT_NONE; // also TOUCH_NONE
                pthis->collider2.elements[0].info.toucher.dmgFlags = pthis->collider2.elements[0].info.toucher.damage = 0;
            }
            break;
        case 5:
            EnDh_SetupWalk(pthis);
            break;
        case 4:
            break;
    }
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
}

void EnDh_SetupBurrow(EnDh* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_dh_Anim_002148, -6.0f);
    pthis->curAction = DH_BURROW;
    pthis->dirtWaveSpread = pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->dirtWavePhase = 0;
    pthis->actionState = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_HIDE);
    EnDh_SetupAction(pthis, EnDh_Burrow);
}

void EnDh_Burrow(EnDh* pthis, GlobalContext* globalCtx) {
    switch (pthis->actionState) {
        case 0:
            pthis->actionState++;
            pthis->drawDirtWave++;
            pthis->collider1.base.atFlags = pthis->collider1.info.toucherFlags =
                AT_ON | AT_TYPE_ENEMY; // also TOUCH_ON | TOUCH_SFX_WOOD
            pthis->collider1.info.toucher.dmgFlags = 0xFFCFFFFF;
            pthis->collider1.info.toucher.damage = 4;
        case 1:
            pthis->dirtWavePhase += 0x47E;
            Math_SmoothStepToF(&pthis->dirtWaveSpread, 300.0f, 1.0f, 8.0f, 0.0f);
            pthis->dirtWaveHeight = Math_SinS(pthis->dirtWavePhase) * 55.0f;
            pthis->dirtWaveAlpha = (s16)(Math_SinS(pthis->dirtWavePhase) * 255.0f);
            EnDh_SpawnDebris(globalCtx, pthis, &pthis->actor.world.pos, pthis->dirtWaveSpread, 4, 2.05f, 1.2f);
            pthis->collider1.dim.radius = pthis->dirtWaveSpread * 0.6f;
            if (SkelAnime_Update(&pthis->skelAnime)) {
                pthis->actionState++;
            }
            break;
        case 2:
            pthis->drawDirtWave = false;
            pthis->collider1.dim.radius = 35;
            pthis->collider1.base.atFlags = pthis->collider1.info.toucherFlags = AT_NONE; // Also TOUCH_NONE
            pthis->collider1.info.toucher.dmgFlags = pthis->collider1.info.toucher.damage = 0;
            EnDh_SetupWait(pthis);
            break;
    }
}

void EnDh_SetupDamage(EnDh* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_dh_Anim_003D6C, -6.0f);
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.speedXZ = -1.0f;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_DAMAGE);
    pthis->curAction = DH_DAMAGE;
    EnDh_SetupAction(pthis, EnDh_Damage);
}

void EnDh_Damage(EnDh* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.speedXZ < 0.0f) {
        pthis->actor.speedXZ += 0.15f;
    }
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        if (pthis->retreat) {
            EnDh_SetupRetreat(pthis, globalCtx);
        } else if ((pthis->actor.xzDistToPlayer <= 105.0f) && Actor_IsFacingPlayer(&pthis->actor, 60 * 0x10000 / 360)) {
            f32 frames = Animation_GetLastFrame(&object_dh_Anim_004658);

            EnDh_SetupAttack(pthis);
            Animation_Change(&pthis->skelAnime, &object_dh_Anim_004658, 1.0f, 20.0f, frames, ANIMMODE_ONCE, -6.0f);
        } else {
            EnDh_SetupWalk(pthis);
        }
        pthis->unk_258 = 255;
    }
}

void EnDh_SetupDeath(EnDh* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_dh_Anim_0032BC, -1.0f);
    pthis->curAction = DH_DEATH;
    pthis->timer = 300;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    func_800F5B58();
    pthis->actor.params = ENDH_DEATH;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEADHAND_DEAD);
    EnDh_SetupAction(pthis, EnDh_Death);
}

void EnDh_Death(EnDh* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) || (pthis->timer != 300)) {
        if (pthis->timer == 300) {
            Animation_PlayLoop(&pthis->skelAnime, &object_dh_Anim_00375C);
        }
        pthis->timer--;
        if (pthis->timer < 150) {
            if (pthis->alpha != 0) {
                pthis->actor.scale.y -= 0.000075f;
                pthis->actor.shape.shadowAlpha = pthis->alpha -= 5;
            } else {
                Actor_Kill(&pthis->actor);
                return;
            }
        }
    } else {
        if (((s32)pthis->skelAnime.curFrame == 53) || ((s32)pthis->skelAnime.curFrame == 56) ||
            ((s32)pthis->skelAnime.curFrame == 61)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        }
        if ((s32)pthis->skelAnime.curFrame == 61) {
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
        }
    }
}

void EnDh_CollisionCheck(EnDh* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 lastHealth;

    if ((pthis->collider2.base.acFlags & AC_HIT) && !pthis->retreat) {
        pthis->collider2.base.acFlags &= ~AC_HIT;
        if ((pthis->actor.colChkInfo.damageEffect != 0) && (pthis->actor.colChkInfo.damageEffect != 6)) {
            pthis->collider2.base.atFlags = pthis->collider2.elements[0].info.toucherFlags = AT_NONE; // also TOUCH_NONE
            pthis->collider2.elements[0].info.toucher.dmgFlags = pthis->collider2.elements[0].info.toucher.damage = 0;
            if (player->unk_844 != 0) {
                pthis->unk_258 = player->unk_845;
            }
            Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
            lastHealth = pthis->actor.colChkInfo.health;
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                EnDh_SetupDeath(pthis);
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x90);
            } else {
                if (((lastHealth >= 15) && (pthis->actor.colChkInfo.health < 15)) ||
                    ((lastHealth >= 9) && (pthis->actor.colChkInfo.health < 9)) ||
                    ((lastHealth >= 3) && (pthis->actor.colChkInfo.health < 3))) {

                    pthis->retreat++;
                }
                EnDh_SetupDamage(pthis);
            }
        }
    }
}

void EnDh_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDh* pthis = (EnDh*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad40;

    EnDh_CollisionCheck(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 45.0f, 45.0f, 0x1D);
    pthis->actor.focus.pos = pthis->headPos;
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider1);
    if (pthis->actor.colChkInfo.health > 0) {
        if (pthis->curAction == DH_WAIT) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        } else {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        }
        if (((pthis->curAction != DH_DAMAGE) && (pthis->actor.shape.yOffset == 0.0f)) ||
            ((player->unk_844 != 0) && (player->unk_845 != pthis->unk_258))) {

            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        }
    } else {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider1.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider2.base);
    }
}

void EnDh_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    Vec3f headOffset = { 2000.0f, 1000.0f, 0.0f };
    EnDh* pthis = (EnDh*)thisx;

    if (limbIndex == 13) {
        Matrix_MultVec3f(&headOffset, &pthis->headPos);
        Matrix_Push();
        Matrix_Translate(headOffset.x, headOffset.y, headOffset.z, MTXMODE_APPLY);
        Collider_UpdateSpheres(1, &pthis->collider2);
        Matrix_Pop();
    }
}

void EnDh_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDh* pthis = (EnDh*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dh.c", 1099);
    if (pthis->alpha == 255) {
        func_80093D18(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, pthis->alpha);
        gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
        POLY_OPA_DISP =
            SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                               pthis->skelAnime.dListCount, NULL, EnDh_PostLimbDraw, &pthis->actor, POLY_OPA_DISP);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
        gSPSegment(POLY_XLU_DISP++, 0x08, &D_80116280[0]);
        POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, NULL, NULL, &pthis->actor, POLY_XLU_DISP);
    }
    if (pthis->drawDirtWave) {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, 85, 55, 0, 130);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->state.frames * -3) % 0x80, 0, 0x20, 0x40, 1,
                                    (globalCtx->state.frames * -10) % 0x80, (globalCtx->state.frames * -20) % 0x100,
                                    0x20, 0x40));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 0, 0, 0, pthis->dirtWaveAlpha);

        Matrix_Translate(0.0f, -pthis->actor.shape.yOffset, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(pthis->dirtWaveSpread * 0.01f, pthis->dirtWaveHeight * 0.01f, pthis->dirtWaveSpread * 0.01f,
                     MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dh.c", 1160),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, object_dh_DL_007FC0);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dh.c", 1166);
}

void EnDh_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dh_InitVars = {
        ACTOR_EN_DH,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_DH,
        sizeof(EnDh),
        (ActorFunc)EnDh_Init,
        (ActorFunc)EnDh_Destroy,
        (ActorFunc)EnDh_Update,
        (ActorFunc)EnDh_Draw,
        (ActorFunc)EnDh_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT0,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000008, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 35, 70, 0, { 0, 0, 0 } },
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
        sJntSphElementsInit,
    };

    D_809EC620 = {
        /* Deku nut      */ DMG_ENTRY(0, 0x0),
        /* Deku stick    */ DMG_ENTRY(2, 0xF),
        /* Slingshot     */ DMG_ENTRY(0, 0x0),
        /* Explosive     */ DMG_ENTRY(0, 0x0),
        /* Boomerang     */ DMG_ENTRY(0, 0x0),
        /* Normal arrow  */ DMG_ENTRY(0, 0x0),
        /* Hammer swing  */ DMG_ENTRY(0, 0x0),
        /* Hookshot      */ DMG_ENTRY(0, 0x0),
        /* Kokiri sword  */ DMG_ENTRY(2, 0xF),
        /* Master sword  */ DMG_ENTRY(2, 0xF),
        /* Giant's Knife */ DMG_ENTRY(4, 0xF),
        /* Fire arrow    */ DMG_ENTRY(0, 0x0),
        /* Ice arrow     */ DMG_ENTRY(0, 0x0),
        /* Light arrow   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x0),
        /* Ice magic     */ DMG_ENTRY(0, 0x0),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(2, 0xF),
        /* Giant spin    */ DMG_ENTRY(4, 0xF),
        /* Master spin   */ DMG_ENTRY(2, 0xF),
        /* Kokiri jump   */ DMG_ENTRY(4, 0xF),
        /* Giant jump    */ DMG_ENTRY(8, 0xF),
        /* Master jump   */ DMG_ENTRY(4, 0xF),
        /* Unknown 1     */ DMG_ENTRY(0, 0x0),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0xF),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

}

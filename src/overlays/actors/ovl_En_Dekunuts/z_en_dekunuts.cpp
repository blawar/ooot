#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DEKUNUTS_Z_EN_DEKUNUTS_C
#include "actor_common.h"
/*
 * File: z_en_dekunuts.c
 * Overlay: ovl_En_Dekunuts
 * Description: Mad Scrub
 */

#include "z_en_dekunuts.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "objects/object_dekunuts/object_dekunuts.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

#define DEKUNUTS_FLOWER 10

void EnDekunuts_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDekunuts_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDekunuts_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDekunuts_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDekunuts_SetupWait(EnDekunuts* pthis);
void EnDekunuts_Wait(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_LookAround(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_Stand(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_ThrowNut(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_Burrow(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_BeginRun(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_Run(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_Gasp(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_BeDamaged(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_BeStunned(EnDekunuts* pthis, GlobalContext* globalCtx);
void EnDekunuts_Die(EnDekunuts* pthis, GlobalContext* globalCtx);

ActorInit En_Dekunuts_InitVars = {
    ACTOR_EN_DEKUNUTS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUNUTS,
    sizeof(EnDekunuts),
    (ActorFunc)EnDekunuts_Init,
    (ActorFunc)EnDekunuts_Destroy,
    (ActorFunc)EnDekunuts_Update,
    (ActorFunc)EnDekunuts_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
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
    { 18, 32, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 0x01, 0x0012, 0x0020, MASS_IMMOVABLE };

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
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
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

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x4D, ICHAIN_CONTINUE),
    ICHAIN_F32(gravity, -1, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2600, ICHAIN_STOP),
};

void EnDekunuts_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDekunuts* pthis = (EnDekunuts*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    if (thisx->params == DEKUNUTS_FLOWER) {
        thisx->flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
    } else {
        ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDekuNutsSkel, &gDekuNutsStandAnim, pthis->jointTable,
                       pthis->morphTable, 25);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        CollisionCheck_SetInfo(&thisx->colChkInfo, &sDamageTable, &sColChkInfoInit);
        pthis->shotsPerRound = ((thisx->params >> 8) & 0xFF);
        thisx->params &= 0xFF;
        if ((pthis->shotsPerRound == 0xFF) || (pthis->shotsPerRound == 0)) {
            pthis->shotsPerRound = 1;
        }
        EnDekunuts_SetupWait(pthis);
        Actor_SpawnAsChild(&globalCtx->actorCtx, thisx, globalCtx, ACTOR_EN_DEKUNUTS, thisx->world.pos.x,
                           thisx->world.pos.y, thisx->world.pos.z, 0, thisx->world.rot.y, 0, DEKUNUTS_FLOWER);
    }
}

void EnDekunuts_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDekunuts* pthis = (EnDekunuts*)thisx;

    if (pthis->actor.params != DEKUNUTS_FLOWER) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnDekunuts_SetupWait(EnDekunuts* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gDekuNutsUpAnim, 0.0f);
    pthis->animFlagAndTimer = Rand_S16Offset(100, 50);
    pthis->collider.dim.height = 5;
    Math_Vec3f_Copy(&pthis->actor.world.pos, &pthis->actor.home.pos);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnDekunuts_Wait;
}

void EnDekunuts_SetupLookAround(EnDekunuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gDekuNutsLookAroundAnim);
    pthis->animFlagAndTimer = 2;
    pthis->actionFunc = EnDekunuts_LookAround;
}

void EnDekunuts_SetupThrowNut(EnDekunuts* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gDekuNutsSpitAnim);
    pthis->animFlagAndTimer = pthis->shotsPerRound;
    pthis->actionFunc = EnDekunuts_ThrowNut;
}

void EnDekunuts_SetupStand(EnDekunuts* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gDekuNutsStandAnim, -3.0f);
    if (pthis->actionFunc == EnDekunuts_ThrowNut) {
        pthis->animFlagAndTimer = 2 | 0x1000; // sets timer and flag
    } else {
        pthis->animFlagAndTimer = 1;
    }
    pthis->actionFunc = EnDekunuts_Stand;
}

void EnDekunuts_SetupBurrow(EnDekunuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDekuNutsBurrowAnim, -5.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DOWN);
    pthis->actionFunc = EnDekunuts_Burrow;
}

void EnDekunuts_SetupBeginRun(EnDekunuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDekuNutsUnburrowAnim, -3.0f);
    pthis->collider.dim.height = 37;
    pthis->actor.colChkInfo.mass = 0x32;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnDekunuts_BeginRun;
}

void EnDekunuts_SetupRun(EnDekunuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gDekuNutsRunAnim);
    pthis->animFlagAndTimer = 2;
    pthis->playWalkSound = false;
    pthis->collider.base.acFlags |= AC_ON;
    pthis->actionFunc = EnDekunuts_Run;
}

void EnDekunuts_SetupGasp(EnDekunuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gDekuNutsGaspAnim);
    pthis->animFlagAndTimer = 3;
    pthis->actor.speedXZ = 0.0f;
    if (pthis->runAwayCount != 0) {
        pthis->runAwayCount--;
    }
    pthis->actionFunc = EnDekunuts_Gasp;
}

void EnDekunuts_SetupBeDamaged(EnDekunuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDekuNutsDamageAnim, -3.0f);
    if ((pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x1F824) != 0) {
        pthis->actor.world.rot.y = pthis->collider.base.ac->world.rot.y;
    } else {
        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, pthis->collider.base.ac) + 0x8000;
    }
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnDekunuts_BeDamaged;
    pthis->actor.speedXZ = 10.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_CUTBODY);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, Animation_GetLastFrame(&gDekuNutsDamageAnim));
}

void EnDekunuts_SetupBeStunned(EnDekunuts* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gDekuNutsDamageAnim, -3.0f);
    pthis->animFlagAndTimer = 5;
    pthis->actionFunc = EnDekunuts_BeStunned;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0,
                         Animation_GetLastFrame(&gDekuNutsDamageAnim) * pthis->animFlagAndTimer);
}

void EnDekunuts_SetupDie(EnDekunuts* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gDekuNutsDieAnim);
    pthis->actionFunc = EnDekunuts_Die;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DEAD);
}

void EnDekunuts_Wait(EnDekunuts* pthis, GlobalContext* globalCtx) {
    s32 hasSlowPlaybackSpeed = false;

    if (pthis->skelAnime.playSpeed < 0.5f) {
        hasSlowPlaybackSpeed = true;
    }
    if (hasSlowPlaybackSpeed && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
        pthis->collider.base.acFlags |= AC_ON;
    } else if (Animation_OnFrame(&pthis->skelAnime, 8.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    }

    pthis->collider.dim.height = ((CLAMP(pthis->skelAnime.curFrame, 9.0f, 12.0f) - 9.0f) * 9.0f) + 5.0f;
    if (!hasSlowPlaybackSpeed && (pthis->actor.xzDistToPlayer < 120.0f)) {
        EnDekunuts_SetupBurrow(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.xzDistToPlayer < 120.0f) {
            EnDekunuts_SetupBurrow(pthis);
        } else if ((pthis->animFlagAndTimer == 0) && (pthis->actor.xzDistToPlayer > 320.0f)) {
            EnDekunuts_SetupLookAround(pthis);
        } else {
            EnDekunuts_SetupStand(pthis);
        }
    }
    if (hasSlowPlaybackSpeed &&
        ((pthis->actor.xzDistToPlayer > 160.0f) && (fabsf(pthis->actor.yDistToPlayer) < 120.0f)) &&
        ((pthis->animFlagAndTimer == 0) || (pthis->actor.xzDistToPlayer < 480.0f))) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnDekunuts_LookAround(EnDekunuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if ((pthis->actor.xzDistToPlayer < 120.0f) || (pthis->animFlagAndTimer == 0)) {
        EnDekunuts_SetupBurrow(pthis);
    }
}

void EnDekunuts_Stand(EnDekunuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (!(pthis->animFlagAndTimer & 0x1000)) {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    }
    if (pthis->animFlagAndTimer == 0x1000) {
        if ((pthis->actor.xzDistToPlayer > 480.0f) || (pthis->actor.xzDistToPlayer < 120.0f)) {
            EnDekunuts_SetupBurrow(pthis);
        } else {
            EnDekunuts_SetupThrowNut(pthis);
        }
    } else if (pthis->animFlagAndTimer == 0) {
        EnDekunuts_SetupThrowNut(pthis);
    }
}

void EnDekunuts_ThrowNut(EnDekunuts* pthis, GlobalContext* globalCtx) {
    Vec3f spawnPos;

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDekunuts_SetupStand(pthis);
    } else if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        spawnPos.x = pthis->actor.world.pos.x + (Math_SinS(pthis->actor.shape.rot.y) * 23.0f);
        spawnPos.y = pthis->actor.world.pos.y + 12.0f;
        spawnPos.z = pthis->actor.world.pos.z + (Math_CosS(pthis->actor.shape.rot.y) * 23.0f);
        if (Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NUTSBALL, spawnPos.x, spawnPos.y, spawnPos.z,
                        pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 0) != NULL) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
        }
    } else if ((pthis->animFlagAndTimer > 1) && Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gDekuNutsSpitAnim, -3.0f);
        if (pthis->animFlagAndTimer != 0) {
            pthis->animFlagAndTimer--;
        }
    }
}

void EnDekunuts_Burrow(EnDekunuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDekunuts_SetupWait(pthis);
    } else {
        pthis->collider.dim.height = ((3.0f - CLAMP(pthis->skelAnime.curFrame, 1.0f, 3.0f)) * 12.0f) + 5.0f;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 4.0f)) {
        pthis->collider.base.acFlags &= ~AC_ON;
    }
    Math_ApproachF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 0.5f, 3.0f);
    Math_ApproachF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 0.5f, 3.0f);
}

void EnDekunuts_BeginRun(EnDekunuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->runDirection = pthis->actor.yawTowardsPlayer + 0x8000;
        pthis->runAwayCount = 3;
        EnDekunuts_SetupRun(pthis);
    }
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
}

void EnDekunuts_Run(EnDekunuts* pthis, GlobalContext* globalCtx) {
    s16 diffRotInit;
    s16 diffRot;
    f32 phi_f0;

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (pthis->playWalkSound) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
        pthis->playWalkSound = false;
    } else {
        pthis->playWalkSound = true;
    }

    Math_StepToF(&pthis->actor.speedXZ, 7.5f, 1.0f);
    if (Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->runDirection, 1, 0xE38, 0xB6) == 0) {
        if (pthis->actor.bgCheckFlags & 0x20) {
            pthis->runDirection = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
        } else if (pthis->actor.bgCheckFlags & 8) {
            pthis->runDirection = pthis->actor.wallYaw;
        } else if (pthis->runAwayCount == 0) {
            diffRotInit = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
            diffRot = diffRotInit - pthis->actor.yawTowardsPlayer;
            if (ABS(diffRot) > 0x2000) {
                pthis->runDirection = diffRotInit;
            } else {
                phi_f0 = (diffRot >= 0.0f) ? 1.0f : -1.0f;
                pthis->runDirection = (phi_f0 * -0x2000) + pthis->actor.yawTowardsPlayer;
            }
        } else {
            pthis->runDirection = pthis->actor.yawTowardsPlayer + 0x8000;
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    if ((pthis->runAwayCount == 0) && Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) < 20.0f &&
        fabsf(pthis->actor.world.pos.y - pthis->actor.home.pos.y) < 2.0f) {
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        pthis->actor.speedXZ = 0.0f;
        EnDekunuts_SetupBurrow(pthis);
    } else if (pthis->animFlagAndTimer == 0) {
        EnDekunuts_SetupGasp(pthis);
    }
}

void EnDekunuts_Gasp(EnDekunuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (pthis->animFlagAndTimer == 0) {
        EnDekunuts_SetupRun(pthis);
    }
}

void EnDekunuts_BeDamaged(EnDekunuts* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 1.0f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDekunuts_SetupDie(pthis);
    }
}

void EnDekunuts_BeStunned(EnDekunuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        if (pthis->animFlagAndTimer != 0) {
            pthis->animFlagAndTimer--;
        }
        if (pthis->animFlagAndTimer == 0) {
            EnDekunuts_SetupRun(pthis);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_FAINT);
        }
    }
}

void EnDekunuts_Die(EnDekunuts* pthis, GlobalContext* globalCtx) {
    static Vec3f effectVelAndAccel = { 0.0f, 0.0f, 0.0f };

    s32 pad;
    Vec3f effectPos;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        effectPos.x = pthis->actor.world.pos.x;
        effectPos.y = pthis->actor.world.pos.y + 18.0f;
        effectPos.z = pthis->actor.world.pos.z;
        EffectSsDeadDb_Spawn(globalCtx, &effectPos, &effectVelAndAccel, &effectVelAndAccel, 200, 0, 255, 255, 255, 255,
                             150, 150, 150, 1, 13, 1);
        effectPos.y = pthis->actor.world.pos.y + 10.0f;
        EffectSsHahen_SpawnBurst(globalCtx, &effectPos, 3.0f, 0, 12, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x30);
        if (pthis->actor.child != NULL) {
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, pthis->actor.child, ACTORCAT_PROP);
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnDekunuts_ColliderCheck(EnDekunuts* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if (pthis->actor.colChkInfo.mass == 0x32) {
            if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
                if (pthis->actor.colChkInfo.damageEffect != 1) {
                    if (pthis->actor.colChkInfo.damageEffect == 2) {
                        EffectSsFCircle_Spawn(globalCtx, &pthis->actor, &pthis->actor.world.pos, 40, 50);
                    }
                    EnDekunuts_SetupBeDamaged(pthis);
                    if (Actor_ApplyDamage(&pthis->actor) == 0) {
                        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                    }
                } else if (pthis->actionFunc != EnDekunuts_BeStunned) {
                    EnDekunuts_SetupBeStunned(pthis);
                }
            }
        } else {
            EnDekunuts_SetupBeginRun(pthis);
        }
    } else if ((pthis->actor.colChkInfo.mass == MASS_IMMOVABLE) && (globalCtx->actorCtx.unk_02 != 0)) {
        EnDekunuts_SetupBeginRun(pthis);
    }
}

void EnDekunuts_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDekunuts* pthis = (EnDekunuts*)thisx;
    s32 pad;

    if (pthis->actor.params != DEKUNUTS_FLOWER) {
        EnDekunuts_ColliderCheck(pthis, globalCtx);
        pthis->actionFunc(pthis, globalCtx);
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, pthis->collider.dim.radius, pthis->collider.dim.height,
                                0x1D);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        if (pthis->actionFunc == EnDekunuts_Wait) {
            Actor_SetFocus(&pthis->actor, pthis->skelAnime.curFrame);
        } else if (pthis->actionFunc == EnDekunuts_Burrow) {
            Actor_SetFocus(&pthis->actor,
                           20.0f - ((pthis->skelAnime.curFrame * 20.0f) / Animation_GetLastFrame(&gDekuNutsBurrowAnim)));
        } else {
            Actor_SetFocus(&pthis->actor, 20.0f);
        }
    }
}

s32 EnDekunuts_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    EnDekunuts* pthis = (EnDekunuts*)thisx;
    f32 x;
    f32 y;
    f32 z;
    f32 curFrame;

    if ((limbIndex == 7) && (pthis->actionFunc == EnDekunuts_ThrowNut)) {
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame <= 6.0f) {
            x = 1.0f - (curFrame * 0.0833f);
            z = 1.0f + (curFrame * 0.1167f);
            y = 1.0f + (curFrame * 0.1167f);
        } else if (curFrame <= 7.0f) {
            curFrame -= 6.0f;
            x = 0.5f + curFrame;
            z = 1.7f - (curFrame * 0.7f);
            y = 1.7f - (curFrame * 0.7f);
        } else if (curFrame <= 10.0f) {
            x = 1.5f - ((curFrame - 7.0f) * 0.1667f);
            z = 1.0f;
            y = 1.0f;
        } else {
            return false;
        }
        Matrix_Scale(x, y, z, MTXMODE_APPLY);
    }
    return false;
}

void EnDekunuts_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDekunuts* pthis = (EnDekunuts*)thisx;

    if (pthis->actor.params == DEKUNUTS_FLOWER) {
        Gfx_DrawDListOpa(globalCtx, gDekuNutsFlowerDL);
    } else {
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnDekunuts_OverrideLimbDraw,
                          NULL, pthis);
    }
}

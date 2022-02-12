#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_EIYER_Z_EN_EIYER_C
#include "actor_common.h"
#include "z_en_eiyer.h"
#include "objects/object_ei/object_ei.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnEiyer_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEiyer_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnEiyer_Update(Actor* thisx, GlobalContext* globalCtx);
void EnEiyer_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnEiyer_SetupAppearFromGround(EnEiyer* pthis);
void EnEiyer_SetupUnderground(EnEiyer* pthis);
void EnEiyer_SetupInactive(EnEiyer* pthis);
void EnEiyer_SetupAmbush(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_SetupGlide(EnEiyer* pthis);
void EnEiyer_SetupStartAttack(EnEiyer* pthis);
void EnEiyer_SetupDiveAttack(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_SetupLand(EnEiyer* pthis);
void EnEiyer_SetupHurt(EnEiyer* pthis);
void EnEiyer_SetupDie(EnEiyer* pthis);
void EnEiyer_SetupDead(EnEiyer* pthis);
void EnEiyer_SetupStunned(EnEiyer* pthis);

void EnEiyer_AppearFromGround(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_WanderUnderground(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_CircleUnderground(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Inactive(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Ambush(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Glide(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_StartAttack(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_DiveAttack(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Land(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Hurt(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Die(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Dead(EnEiyer* pthis, GlobalContext* globalCtx);
void EnEiyer_Stunned(EnEiyer* pthis, GlobalContext* globalCtx);

ActorInit En_Eiyer_InitVars = {
    ACTOR_EN_EIYER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EI,
    sizeof(EnEiyer),
    (ActorFunc)EnEiyer_Init,
    (ActorFunc)EnEiyer_Destroy,
    (ActorFunc)EnEiyer_Update,
    (ActorFunc)EnEiyer_Draw,
};

static ColliderCylinderInit sColCylInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x04, 0x08 },
        { 0x00000019, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_ON,
        OCELEM_ON,
    },
    { 27, 17, -10, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 2, 45, 15, 100 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(4, 0x0),
    /* Light magic   */ DMG_ENTRY(4, 0x0),
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
    ICHAIN_S8(naviEnemyId, 0x19, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 5, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2500, ICHAIN_STOP),
};

/**
 * params    0: Spawn 3 clones and circle around spawn point
 * params  1-3: Clone, spawn another clone for the main Eiyer if params < 3
 * params   10: Normal Eiyer, wander around spawn point
 */
void EnEiyer_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnEiyer* pthis = (EnEiyer*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 600.0f, ActorShadow_DrawCircle, 65.0f);
    SkelAnime_Init(globalCtx, &pthis->skelanime, &gStingerSkel, &gStingerIdleAnim, pthis->jointTable, pthis->morphTable,
                   19);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sColCylInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);

    if (pthis->actor.params < 3) {
        // Each clone spawns another clone
        if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EIYER, pthis->actor.home.pos.x,
                               pthis->actor.home.pos.y, pthis->actor.home.pos.z, 0, pthis->actor.shape.rot.y + 0x4000, 0,
                               pthis->actor.params + 1) == NULL) {
            Actor_Kill(&pthis->actor);
            return;
        }

        if (pthis->actor.params == 0) {
            Actor* child = pthis->actor.child;
            s32 clonesSpawned;

            for (clonesSpawned = 0; clonesSpawned != 3; clonesSpawned++) {
                if (child == NULL) {
                    break;
                }
                child = child->child;
            }

            if (clonesSpawned != 3) {
                for (child = &pthis->actor; child != NULL; child = child->child) {
                    Actor_Kill(child);
                }
                return;
            } else {
                pthis->actor.child->parent = &pthis->actor;
                pthis->actor.child->child->parent = &pthis->actor;
                pthis->actor.child->child->child->parent = &pthis->actor;
            }
        }
    }

    if (pthis->actor.params == 0 || pthis->actor.params == 10) {
        EnEiyer_SetupAppearFromGround(pthis);
    } else {
        EnEiyer_SetupInactive(pthis);
    }
}

void EnEiyer_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnEiyer* pthis = (EnEiyer*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnEiyer_RotateAroundHome(EnEiyer* pthis) {
    pthis->actor.world.pos.x = Math_SinS(pthis->actor.world.rot.y) * 80.0f + pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = Math_CosS(pthis->actor.world.rot.y) * 80.0f + pthis->actor.home.pos.z;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x4000;
}

void EnEiyer_SetupAppearFromGround(EnEiyer* pthis) {
    pthis->collider.info.bumper.dmgFlags = 0x19;
    Animation_PlayLoop(&pthis->skelanime, &gStingerIdleAnim);

    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y - 40.0f;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 0.0f;

    if (pthis->actor.params != 0xA) {
        if (pthis->actor.params == 0) {
            pthis->actor.world.rot.y = Rand_ZeroOne() * 0x10000;
        } else {
            pthis->actor.world.rot.y = pthis->actor.parent->world.rot.y + pthis->actor.params * 0x4000;
        }
        EnEiyer_RotateAroundHome(pthis);
    } else {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = Rand_ZeroOne() * 0x10000;
    }

    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_12);
    pthis->actor.shape.shadowScale = 0.0f;
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actionFunc = EnEiyer_AppearFromGround;
}

void EnEiyer_SetupUnderground(EnEiyer* pthis) {
    if (pthis->actor.params == 0xA) {
        pthis->actor.speedXZ = -0.5f;
        pthis->actionFunc = EnEiyer_WanderUnderground;
    } else {
        pthis->actionFunc = EnEiyer_CircleUnderground;
    }

    pthis->collider.base.acFlags |= AC_ON;
    pthis->actor.flags &= ~ACTOR_FLAG_4;
    pthis->actor.flags |= ACTOR_FLAG_0;
}

void EnEiyer_SetupInactive(EnEiyer* pthis) {
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actionFunc = EnEiyer_Inactive;
}

void EnEiyer_SetupAmbush(EnEiyer* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    Animation_PlayOnce(&pthis->skelanime, &gStingerBackflipAnim);
    pthis->collider.info.bumper.dmgFlags = ~0x00300000;
    pthis->basePos = pthis->actor.world.pos;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.flags |= ACTOR_FLAG_12;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.shape.shadowScale = 65.0f;
    pthis->actor.shape.yOffset = 600.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_JUMP);
    EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 1, 700);
    pthis->actionFunc = EnEiyer_Ambush;
}

void EnEiyer_SetupGlide(EnEiyer* pthis) {
    pthis->targetYaw = pthis->actor.shape.rot.y;
    pthis->basePos.y = (cosf(-M_PI / 8) * 5.0f) + pthis->actor.world.pos.y;
    Animation_MorphToLoop(&pthis->skelanime, &gStingerHitAnim, -5.0f);
    pthis->timer = 60;
    pthis->actionFunc = EnEiyer_Glide;
}

void EnEiyer_SetupStartAttack(EnEiyer* pthis) {
    pthis->actionFunc = EnEiyer_StartAttack;
}

void EnEiyer_SetupDiveAttack(EnEiyer* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.velocity.y = 0.0f;
    pthis->basePos.y = player->actor.world.pos.y + 15.0f;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->collider.base.atFlags &= ~AT_HIT;
    pthis->actionFunc = EnEiyer_DiveAttack;
}

void EnEiyer_SetupLand(EnEiyer* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelanime, &gStingerDiveAnim, -3.0f);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->actor.flags |= ACTOR_FLAG_4;

    // Update BgCheck info, play sound, and spawn effect on the first frame of the land action
    pthis->timer = -1;
    pthis->actor.gravity = 0.0f;
    pthis->collider.dim.height = sColCylInit.dim.height;
    pthis->actionFunc = EnEiyer_Land;
}

void EnEiyer_SetupHurt(EnEiyer* pthis) {
    pthis->basePos.y = pthis->actor.world.pos.y;
    Animation_Change(&pthis->skelanime, &gStingerHitAnim, 2.0f, 0.0f, 0.0f, 0, -3.0f);
    pthis->timer = 40;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 5.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 200, 0, 40);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnEiyer_Hurt;
}

void EnEiyer_SetupDie(EnEiyer* pthis) {
    pthis->timer = 20;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 200, 0, 40);

    if (pthis->collider.info.bumper.dmgFlags != 0x19) {
        pthis->actor.speedXZ = 6.0f;
        Animation_MorphToLoop(&pthis->skelanime, &gStingerHitAnim, -3.0f);
    } else {
        pthis->actor.speedXZ -= 6.0f;
    }

    pthis->collider.info.bumper.dmgFlags = ~0x00300000;
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnEiyer_Die;
}

void EnEiyer_SetupDead(EnEiyer* pthis) {
    pthis->actor.colorFilterParams |= 0x2000;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actionFunc = EnEiyer_Dead;
}

void EnEiyer_SetupStunned(EnEiyer* pthis) {
    Animation_Change(&pthis->skelanime, &gStingerPopOutAnim, 2.0f, 0.0f, 0.0f, 0, -8.0f);
    pthis->timer = 80;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -1.0f;
    pthis->collider.dim.height = sColCylInit.dim.height + 8;
    Actor_SetColorFilter(&pthis->actor, 0, 200, 0, 80);
    pthis->collider.base.atFlags &= ~AT_ON;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actionFunc = EnEiyer_Stunned;
}

void EnEiyer_AppearFromGround(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.75f)) {
        EnEiyer_SetupUnderground(pthis);
    }
}

void EnEiyer_CheckPlayerCollision(EnEiyer* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
        pthis->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
        EnEiyer_SetupAmbush(pthis, globalCtx);
    }
}

void EnEiyer_CircleUnderground(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    pthis->actor.world.rot.y += -0x60;
    EnEiyer_RotateAroundHome(pthis);
    EnEiyer_CheckPlayerCollision(pthis, globalCtx);

    // Clones disappear when the main Eiyer leaves the ground
    if (pthis->actor.params != 0 && ((EnEiyer*)pthis->actor.parent)->actionFunc != EnEiyer_CircleUnderground) {
        EnEiyer_SetupInactive(pthis);
    }
}

void EnEiyer_WanderUnderground(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) > 100.0f) {
        pthis->targetYaw = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos) + 0x8000;
    } else if (pthis->targetYaw == pthis->actor.world.rot.y && Rand_ZeroOne() > 0.99f) {
        pthis->targetYaw =
            pthis->actor.world.rot.y + (Rand_ZeroOne() < 0.5f ? -1 : 1) * (Rand_ZeroOne() * 0x2000 + 0x2000);
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->targetYaw, 0xB6);
    EnEiyer_CheckPlayerCollision(pthis, globalCtx);
}

void EnEiyer_Inactive(EnEiyer* pthis, GlobalContext* globalCtx) {
    EnEiyer* parent;

    if (pthis->actor.home.pos.y - 50.0f < pthis->actor.world.pos.y) {
        pthis->actor.world.pos.y -= 0.5f;
    }

    parent = (EnEiyer*)pthis->actor.parent;
    if (parent->actionFunc == EnEiyer_Dead) {
        Actor_Kill(&pthis->actor);
    } else if (parent->actionFunc == EnEiyer_AppearFromGround) {
        EnEiyer_SetupAppearFromGround(pthis);
    }
}

void EnEiyer_Ambush(EnEiyer* pthis, GlobalContext* globalCtx) {
    s32 animFinished;
    f32 curFrame;
    f32 xzOffset;
    s32 bgId;

    animFinished = SkelAnime_Update(&pthis->skelanime);
    curFrame = pthis->skelanime.curFrame;

    if (pthis->skelanime.curFrame < 12.0f) {
        pthis->actor.world.pos.y = ((1.0f - cosf((0.996f * M_PI / 12.0f) * curFrame)) * 40.0f) + pthis->actor.home.pos.y;
        xzOffset = sinf((0.996f * M_PI / 12.0f) * curFrame) * -40.0f;
        pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y) * xzOffset) + pthis->basePos.x;
        pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y) * xzOffset) + pthis->basePos.z;
    } else {
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 80.0f, 0.5f);
        pthis->actor.speedXZ = 0.8f;
    }

    if (animFinished) {
        pthis->collider.base.acFlags |= AC_ON;
        EnEiyer_SetupGlide(pthis);
    } else {
        pthis->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                              &pthis->actor, &pthis->actor.world.pos);
    }
}

void EnEiyer_Glide(EnEiyer* pthis, GlobalContext* globalCtx) {
    f32 curFrame;
    s32 pad;
    s16 yawChange;

    SkelAnime_Update(&pthis->skelanime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    curFrame = pthis->skelanime.curFrame;
    Math_ApproachF(&pthis->basePos.y, pthis->actor.floorHeight + 80.0f + 5.0f, 0.3f, pthis->actor.speedXZ);
    pthis->actor.world.pos.y = pthis->basePos.y - cosf((curFrame - 5.0f) * (M_PI / 40)) * 5.0f;

    if (curFrame <= 45.0f) {
        Math_StepToF(&pthis->actor.speedXZ, 1.0f, 0.03f);
    } else {
        Math_StepToF(&pthis->actor.speedXZ, 1.5f, 0.03f);
    }

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->targetYaw = pthis->actor.wallYaw;
    }

    if (Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->targetYaw, 0xB6)) {
        if (pthis->timer != 0 || Rand_ZeroOne() > 0.05f) {
            pthis->actor.world.rot.y += 0x100;
        } else {
            yawChange = Rand_S16Offset(0x2000, 0x2000);
            pthis->targetYaw = (Rand_ZeroOne() < 0.5f ? -1 : 1) * yawChange + pthis->actor.world.rot.y;
        }
    }

    if (pthis->timer == 0 && pthis->actor.yDistToPlayer < 0.0f && pthis->actor.xzDistToPlayer < 120.0f) {
        EnEiyer_SetupStartAttack(pthis);
    }

    func_8002F974(&pthis->actor, NA_SE_EN_EIER_FLY - SFX_FLAG);
}

void EnEiyer_StartAttack(EnEiyer* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f focus;

    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.shape.rot.x > 0 && pthis->actor.shape.rot.x < 0x8000) {
        focus.x = player->actor.world.pos.x;
        focus.y = player->actor.world.pos.y + 20.0f;
        focus.z = player->actor.world.pos.z;

        if (Math_ScaledStepToS(&pthis->actor.shape.rot.x, Actor_WorldPitchTowardPoint(&pthis->actor, &focus), 0x1000)) {
            EnEiyer_SetupDiveAttack(pthis, globalCtx);
        }
    } else {
        pthis->actor.shape.rot.x -= 0x1000;
    }

    pthis->actor.world.rot.x = -pthis->actor.shape.rot.x;
    Math_StepToF(&pthis->actor.speedXZ, 5.0f, 0.3f);
    Math_ApproachS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 2, 0x71C);
    func_8002F974(&pthis->actor, NA_SE_EN_EIER_FLY - SFX_FLAG);
}

void EnEiyer_DiveAttack(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    pthis->actor.speedXZ *= 1.1f;

    if (pthis->actor.bgCheckFlags & 8 || pthis->actor.bgCheckFlags & 1) {
        EnEiyer_SetupLand(pthis);
    }

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~(AT_ON | AT_HIT);
    }

    func_8002F974(&pthis->actor, NA_SE_EN_EIER_FLY - SFX_FLAG);
}

void EnEiyer_Land(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ScaledStepToS(&pthis->actor.world.rot.x, -0x4000, 0x450);
    Math_StepToF(&pthis->actor.speedXZ, 7.0f, 1.0f);

    if (pthis->timer == -1) {
        if (pthis->actor.bgCheckFlags & 8 || pthis->actor.bgCheckFlags & 1) {
            pthis->timer = 10;
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 30, NA_SE_EN_OCTAROCK_SINK);

            if (pthis->actor.bgCheckFlags & 1) {
                EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 1, 700);
            }
        }
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            pthis->actor.shape.rot.x = 0;
            pthis->actor.world.rot.x = 0;
            EnEiyer_SetupAppearFromGround(pthis);
        }
    }
}

void EnEiyer_Hurt(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_ApproachF(&pthis->basePos.y, pthis->actor.floorHeight + 80.0f + 5.0f, 0.5f, pthis->actor.speedXZ);
    pthis->actor.world.pos.y = pthis->basePos.y - 5.0f;

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->targetYaw = pthis->actor.wallYaw;
    } else {
        pthis->targetYaw = pthis->actor.yawTowardsPlayer + 0x8000;
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->targetYaw, 0x38E);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x200);
    pthis->actor.shape.rot.z = sinf(pthis->timer * (M_PI / 5)) * 5120.0f;

    if (pthis->timer == 0) {
        pthis->actor.shape.rot.x = 0;
        pthis->actor.shape.rot.z = 0;
        pthis->collider.base.acFlags |= AC_ON;
        EnEiyer_SetupGlide(pthis);
    }
    pthis->actor.world.rot.x = -pthis->actor.shape.rot.x;
}

void EnEiyer_Die(EnEiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->actor.speedXZ > 0.0f) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x4000, 0x400);
    } else {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x4000, 0x400);
    }

    pthis->actor.shape.rot.z += 0x1000;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.world.rot.x = -pthis->actor.shape.rot.x;

    if (pthis->timer == 0 || pthis->actor.bgCheckFlags & 0x10) {
        EnEiyer_SetupDead(pthis);
    }
}

void EnEiyer_Dead(EnEiyer* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.shadowAlpha = CLAMP_MIN((s16)(pthis->actor.shape.shadowAlpha - 5), 0);
    pthis->actor.world.pos.y -= 2.0f;

    if (pthis->actor.shape.shadowAlpha == 0) {
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 80);
        Actor_Kill(&pthis->actor);
    }
}

void EnEiyer_Stunned(EnEiyer* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x200);
    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_FLUTTER);
    }

    if (pthis->actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
    }

    if (pthis->timer == 0) {
        pthis->actor.gravity = 0.0f;
        pthis->actor.velocity.y = 0.0f;
        pthis->collider.dim.height = sColCylInit.dim.height;
        EnEiyer_SetupGlide(pthis);
    }
}

void EnEiyer_UpdateDamage(EnEiyer* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);

        if (pthis->actor.colChkInfo.damageEffect != 0 || pthis->actor.colChkInfo.damage != 0) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_DEAD);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            }

            // If underground, one hit kill
            if (pthis->collider.info.bumper.dmgFlags == 0x19) {
                if (pthis->actor.colChkInfo.damage == 0) {
                    EnEiyer_SetupAmbush(pthis, globalCtx);
                } else {
                    EnEiyer_SetupDie(pthis);
                }
            } else if (pthis->actor.colChkInfo.damageEffect == 1) {
                if (pthis->actionFunc != EnEiyer_Stunned) {
                    EnEiyer_SetupStunned(pthis);
                }
            } else if (pthis->actor.colChkInfo.health != 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_DAMAGE);
                EnEiyer_SetupHurt(pthis);
            } else {
                pthis->collider.dim.height = sColCylInit.dim.height;
                EnEiyer_SetupDie(pthis);
            }
        }
    }
}

void EnEiyer_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnEiyer* pthis = (EnEiyer*)thisx;
    s32 pad;

    EnEiyer_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.world.rot.x == 0 || pthis->actionFunc == EnEiyer_Stunned) {
        Actor_MoveForward(&pthis->actor);
    } else {
        func_8002D97C(&pthis->actor);
    }

    if (pthis->actionFunc == EnEiyer_Glide || pthis->actionFunc == EnEiyer_DiveAttack ||
        pthis->actionFunc == EnEiyer_Stunned || pthis->actionFunc == EnEiyer_Die || pthis->actionFunc == EnEiyer_Hurt ||
        (pthis->actionFunc == EnEiyer_Land && pthis->timer == -1)) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 27.0f, 30.0f, 7);
    }

    if (pthis->actor.params == 0xA ||
        (pthis->actionFunc != EnEiyer_AppearFromGround && pthis->actionFunc != EnEiyer_CircleUnderground)) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    // only the main Eiyer can ambush the player
    if (pthis->actor.params == 0 || pthis->actor.params == 0xA) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (pthis->collider.base.atFlags & AT_ON) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->actionFunc != EnEiyer_Ambush) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }

    if (pthis->actor.flags & ACTOR_FLAG_0) {
        pthis->actor.focus.pos.x = pthis->actor.world.pos.x + Math_SinS(pthis->actor.shape.rot.y) * 12.5f;
        pthis->actor.focus.pos.z = pthis->actor.world.pos.z + Math_CosS(pthis->actor.shape.rot.y) * 12.5f;
        pthis->actor.focus.pos.y = pthis->actor.world.pos.y;
    }
}

s32 EnEiyer_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                             Gfx** gfx) {
    EnEiyer* pthis = (EnEiyer*)thisx;

    if (limbIndex == 1) {
        pos->z += 2500.0f;
    }

    if (pthis->collider.info.bumper.dmgFlags == 0x19 && limbIndex != 9 && limbIndex != 10) {
        *dList = NULL;
    }
    return 0;
}

void EnEiyer_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnEiyer* pthis = (EnEiyer*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_eiyer.c", 1494);
    if (pthis->actionFunc != EnEiyer_Dead) {
        func_80093D18(globalCtx->state.gfxCtx);

        gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);

        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable,
                                       EnEiyer_OverrideLimbDraw, NULL, pthis, POLY_OPA_DISP);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08, D_80116280);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, pthis->actor.shape.shadowAlpha);

        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable,
                                       EnEiyer_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_eiyer.c", 1541);
}

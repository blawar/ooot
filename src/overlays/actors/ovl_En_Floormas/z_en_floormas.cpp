#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FLOORMAS_Z_EN_FLOORMAS_C
#include "actor_common.h"
/*
 * File: z_en_floormas
 * Overlay: En_Floormas
 * Description: Floormaster
 */

#include "z_en_floormas.h"
#include "objects/object_wallmaster/object_wallmaster.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_eff_ss_dead.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_10)

#define SPAWN_INVISIBLE 0x8000
#define SPAWN_SMALL 0x10

#define MERGE_MASTER 0x40
#define MERGE_SLAVE 0x20

void EnFloormas_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFloormas_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFloormas_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFloormas_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFloormas_GrabLink(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Split(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Recover(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_DrawHighlighted(Actor* pthis, GlobalContext* globalCtx);
void EnFloormas_SmWait(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_SetupBigDecideAction(EnFloormas* pthis);
void EnFloormas_Freeze(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_TakeDamage(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Merge(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_JumpAtLink(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_SmSlaveJumpAtMaster(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_SmShrink(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_SmDecideAction(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_SmWalk(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Land(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Hover(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Turn(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Run(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_BigStopWalk(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_BigWalk(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Stand(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_BigDecideAction(EnFloormas* pthis, GlobalContext* globalCtx);
void EnFloormas_Charge(EnFloormas* pthis, GlobalContext* globalCtx);

ActorInit En_Floormas_InitVars = {
    ACTOR_EN_FLOORMAS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_WALLMASTER,
    sizeof(EnFloormas),
    (ActorFunc)EnFloormas_Init,
    (ActorFunc)EnFloormas_Destroy,
    (ActorFunc)EnFloormas_Update,
    (ActorFunc)EnFloormas_Draw,
};

static ColliderCylinderInit sCylinderInit = {
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
        { 0xFFCFFFFF, 0x04, 0x10 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 25, 40, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 4, 30, 40, 150 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(4, 0x2),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(4, 0x4),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(4, 0x2),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(4, 0x4),
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
    ICHAIN_S8(naviEnemyId, 0x31, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 5500, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -1000, ICHAIN_STOP),
};

void EnFloormas_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnFloormas* pthis = (EnFloormas*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 invisble;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 50.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gWallmasterSkel, &gWallmasterWaitAnim, pthis->jointTable,
                       pthis->morphTable, 25);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->zOffset = -1600;
    invisble = pthis->actor.params & SPAWN_INVISIBLE;

    // s16 cast needed
    pthis->actor.params &= (s16) ~(SPAWN_INVISIBLE);
    if (invisble) {
        pthis->actor.flags |= ACTOR_FLAG_7;
        pthis->actor.draw = EnFloormas_DrawHighlighted;
    }

    if (pthis->actor.params == SPAWN_SMALL) {
        pthis->actor.draw = NULL;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actionFunc = EnFloormas_SmWait;
    } else {
        // spawn first small floormaster
        pthis->actor.parent =
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_FLOORMAS, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, invisble + SPAWN_SMALL);
        if (pthis->actor.parent == NULL) {
            Actor_Kill(&pthis->actor);
            return;
        }
        // spawn 2nd small floormaster
        pthis->actor.child =
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_FLOORMAS, pthis->actor.world.pos.x,
                        pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, invisble + SPAWN_SMALL);
        if (pthis->actor.child == NULL) {
            Actor_Kill(pthis->actor.parent);
            Actor_Kill(&pthis->actor);
            return;
        }

        // link floormasters together
        pthis->actor.parent->child = &pthis->actor;
        pthis->actor.parent->parent = pthis->actor.child;
        pthis->actor.child->parent = &pthis->actor;
        pthis->actor.child->child = pthis->actor.parent;
        EnFloormas_SetupBigDecideAction(pthis);
    }
}

void EnFloormas_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFloormas* pthis = (EnFloormas*)thisx;
    ColliderCylinder* col = &pthis->collider;
    Collider_DestroyCylinder(globalCtx, col);
}

void EnFloormas_MakeInvulnerable(EnFloormas* pthis) {
    pthis->collider.base.colType = COLTYPE_HARD;
    pthis->collider.base.acFlags |= AC_HARD;
    pthis->actionTarget = 0x28;
}

void EnFloormas_MakeVulnerable(EnFloormas* pthis) {
    pthis->collider.base.colType = COLTYPE_HIT0;
    pthis->actionTarget = 0;
    pthis->collider.base.acFlags &= ~AC_HARD;
}

void EnFloormas_SetupBigDecideAction(EnFloormas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterWaitAnim);
    pthis->actionFunc = EnFloormas_BigDecideAction;
    pthis->actor.speedXZ = 0.0f;
}

void EnFloormas_SetupStand(EnFloormas* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gWallmasterStandUpAnim, -3.0f);
    pthis->actionFunc = EnFloormas_Stand;
}

void EnFloormas_SetupBigWalk(EnFloormas* pthis) {
    if (pthis->actionFunc != EnFloormas_Run) {
        Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gWallmasterWalkAnim, 1.5f);
    } else {
        pthis->skelAnime.playSpeed = 1.5f;
    }

    pthis->actionTimer = Rand_S16Offset(2, 4);
    pthis->actionFunc = EnFloormas_BigWalk;
    pthis->actor.speedXZ = 1.5f;
}

void EnFloormas_SetupBigStopWalk(EnFloormas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterStopWalkAnim);
    pthis->actionFunc = EnFloormas_BigStopWalk;
    pthis->actor.speedXZ = 0.0f;
}

void EnFloormas_SetupRun(EnFloormas* pthis) {
    pthis->actionTimer = 0;
    pthis->actionFunc = EnFloormas_Run;
    pthis->actor.speedXZ = 5.0f;
    pthis->skelAnime.playSpeed = 3.0f;
}

void EnFloormas_SetupTurn(EnFloormas* pthis) {
    s16 rotDelta = pthis->actionTarget - pthis->actor.shape.rot.y;

    pthis->actor.speedXZ = 0.0f;
    if (rotDelta > 0) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gFloormasterTurnAnim, -3.0f);
    } else {
        Animation_Change(&pthis->skelAnime, &gFloormasterTurnAnim, -1.0f, Animation_GetLastFrame(&gFloormasterTurnAnim),
                         0.0f, ANIMMODE_ONCE, -3.0f);
    }

    if (pthis->actor.scale.x > 0.004f) {
        pthis->actionTarget = (rotDelta * (2.0f / 30.0f));
    } else {
        pthis->skelAnime.playSpeed = pthis->skelAnime.playSpeed + pthis->skelAnime.playSpeed;
        pthis->actionTarget = rotDelta * (2.0f / 15.0f);
    }
    pthis->actionFunc = EnFloormas_Turn;
}

void EnFloormas_SetupHover(EnFloormas* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gWallmasterHoverAnim, 3.0f, 0, Animation_GetLastFrame(&gWallmasterHoverAnim),
                     ANIMMODE_ONCE, -3.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.gravity = 0.0f;
    EnFloormas_MakeInvulnerable(pthis);
    Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 15.0f, 6, 20.0f, 0x12C, 0x64, 1);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_ATTACK);
    pthis->actionFunc = EnFloormas_Hover;
}

void EnFloormas_SetupCharge(EnFloormas* pthis) {
    pthis->actionTimer = 25;
    pthis->actor.gravity = -0.15f;
    pthis->actionFunc = EnFloormas_Charge;
    pthis->actor.speedXZ = 0.5f;
}

void EnFloormas_SetupLand(EnFloormas* pthis) {
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 1.0f, 41.0f, 42.0f, ANIMMODE_ONCE, 5.0f);
    if ((pthis->actor.speedXZ < 0.0f) || (pthis->actionFunc != EnFloormas_Charge)) {
        pthis->actionTimer = 30;
    } else {
        pthis->actionTimer = 45;
    }
    pthis->actor.gravity = -1.0f;
    pthis->actionFunc = EnFloormas_Land;
}

void EnFloormas_SetupSplit(EnFloormas* pthis) {

    Actor_SetScale(&pthis->actor, 0.004f);
    pthis->actor.flags |= ACTOR_FLAG_4;
    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_7)) {
        pthis->actor.draw = EnFloormas_DrawHighlighted;
    } else {
        pthis->actor.draw = EnFloormas_Draw;
    }
    pthis->actor.shape.rot.y = pthis->actor.parent->shape.rot.y + 0x5555;
    pthis->actor.world.pos = pthis->actor.parent->world.pos;
    pthis->actor.params = 0x10;
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 1.0f, 41.0f, Animation_GetLastFrame(&gWallmasterJumpAnim),
                     ANIMMODE_ONCE, 0.0f);
    pthis->collider.dim.radius = sCylinderInit.dim.radius * 0.6f;
    pthis->collider.dim.height = sCylinderInit.dim.height * 0.6f;
    pthis->collider.info.bumperFlags &= ~BUMP_HOOKABLE;
    pthis->actor.speedXZ = 4.0f;
    pthis->actor.velocity.y = 7.0f;
    // using div creates a signed check.
    pthis->actor.colChkInfo.health = sColChkInfoInit.health >> 1;
    pthis->actionFunc = EnFloormas_Split;
}

void EnFloormas_SetupSmWalk(EnFloormas* pthis) {
    Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gWallmasterWalkAnim, 4.5f);
    pthis->actionFunc = EnFloormas_SmWalk;
    pthis->actor.speedXZ = 5.0f;
}

void EnFloormas_SetupSmDecideAction(EnFloormas* pthis) {
    if (pthis->actionFunc != EnFloormas_SmWalk) {
        Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gWallmasterWalkAnim, 4.5f);
    }
    pthis->actionFunc = EnFloormas_SmDecideAction;
    pthis->actor.speedXZ = 5.0f;
}

void EnFloormas_SetupSmShrink(EnFloormas* pthis, GlobalContext* globalCtx) {
    static Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    static Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;

    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 15.0f;
    pos.z = pthis->actor.world.pos.z;
    EffectSsDeadDb_Spawn(globalCtx, &pos, &velocity, &accel, 150, -10, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
    pthis->actionFunc = EnFloormas_SmShrink;
}

void EnFloormas_SetupSlaveJumpAtMaster(EnFloormas* pthis) {
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 2.0f, 0.0f, 41.0f, ANIMMODE_ONCE, 0.0f);
    pthis->actionFunc = EnFloormas_SmSlaveJumpAtMaster;
    pthis->actor.speedXZ = 0.0f;
}

void EnFloormas_SetupJumpAtLink(EnFloormas* pthis) {
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 2.0f, 0.0f, 41.0f, ANIMMODE_ONCE, 0.0f);
    pthis->actionFunc = EnFloormas_JumpAtLink;
    pthis->actor.speedXZ = 0.0f;
}

void EnFloormas_SetupGrabLink(EnFloormas* pthis, Player* player) {
    f32 yDelta;
    f32 xzDelta;

    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 1.0f, 36.0f, 45.0f, ANIMMODE_ONCE, -3.0f);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    EnFloormas_MakeInvulnerable(pthis);
    if (!LINK_IS_ADULT) {
        yDelta = CLAMP(-pthis->actor.yDistToPlayer, 20.0f, 30.0f);
        xzDelta = -10.0f;
    } else {
        yDelta = CLAMP(-pthis->actor.yDistToPlayer, 25.0f, 45.0f);
        xzDelta = -70.0f;
    }
    pthis->actor.world.pos.y = player->actor.world.pos.y + yDelta;
    pthis->actor.world.pos.x = Math_SinS(pthis->actor.shape.rot.y) * (xzDelta * 0.1f) + player->actor.world.pos.x;
    pthis->actor.world.pos.z = Math_CosS(pthis->actor.shape.rot.y) * (xzDelta * 0.1f) + player->actor.world.pos.z;
    pthis->actor.shape.rot.x = -0x4CE0;
    pthis->actionFunc = EnFloormas_GrabLink;
}

void EnFloormas_SetupMerge(EnFloormas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterWaitAnim);
    pthis->actionTimer = 0;
    pthis->smActionTimer += 1500;
    EnFloormas_MakeInvulnerable(pthis);
    pthis->actionFunc = EnFloormas_Merge;
}

void EnFloormas_SetupSmWait(EnFloormas* pthis) {
    EnFloormas* parent = (EnFloormas*)pthis->actor.parent;
    EnFloormas* child = (EnFloormas*)pthis->actor.child;

    // if pthis is the last remaining small floor master, kill all.
    if ((parent->actionFunc == EnFloormas_SmWait) && (child->actionFunc == EnFloormas_SmWait)) {
        Actor_Kill(&parent->actor);
        Actor_Kill(&child->actor);
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->actor.draw = NULL;
    pthis->actionFunc = EnFloormas_SmWait;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_4);
}

void EnFloormas_SetupTakeDamage(EnFloormas* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gWallmasterDamageAnim, -3.0f);
    if (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x1F824) {
        pthis->actor.world.rot.y = pthis->collider.base.ac->world.rot.y;
    } else {
        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, pthis->collider.base.ac) + 0x8000;
    }
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x14);
    pthis->actionFunc = EnFloormas_TakeDamage;
    pthis->actor.speedXZ = 5.0f;
    pthis->actor.velocity.y = 5.5f;
}

void EnFloormas_SetupRecover(EnFloormas* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gWallmasterRecoverFromDamageAnim);
    pthis->actor.velocity.y = pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actionFunc = EnFloormas_Recover;
}

void EnFloormas_SetupFreeze(EnFloormas* pthis) {
    Animation_Change(&pthis->skelAnime, &gWallmasterJumpAnim, 1.5f, 0, 20.0f, ANIMMODE_ONCE, -3.0f);
    pthis->actor.speedXZ = 0.0f;
    if (pthis->actor.colChkInfo.damageEffect == 4) {
        Actor_SetColorFilter(&pthis->actor, -0x8000, 0xFF, 0, 0x50);
    } else {
        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
        if (pthis->actor.scale.x > 0.004f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
        }
    }
    pthis->actionTimer = 80;
    pthis->actionFunc = EnFloormas_Freeze;
}

void EnFloormas_Die(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.scale.x > 0.004f) {
        // split
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
        EnFloormas_SetupSplit((EnFloormas*)pthis->actor.child);
        EnFloormas_SetupSplit((EnFloormas*)pthis->actor.parent);
        EnFloormas_SetupSplit(pthis);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SPLIT);
    } else {
        // Die
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x90);
        EnFloormas_SetupSmShrink(pthis, globalCtx);
    }
}

void EnFloormas_BigDecideAction(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        // within 400 units of link and within 90 degrees rotation of him
        if (pthis->actor.xzDistToPlayer < 400.0f && !Actor_IsFacingPlayer(&pthis->actor, 0x4000)) {
            pthis->actionTarget = pthis->actor.yawTowardsPlayer;
            EnFloormas_SetupTurn(pthis);
            // within 280 units of link and within 45 degrees rotation of him
        } else if (pthis->actor.xzDistToPlayer < 280.0f && Actor_IsFacingPlayer(&pthis->actor, 0x2000)) {
            EnFloormas_SetupHover(pthis, globalCtx);
        } else {
            EnFloormas_SetupStand(pthis);
        }
    }
}

void EnFloormas_Stand(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.scale.x > 0.004f) {
            EnFloormas_SetupBigWalk(pthis);
        } else if (pthis->actor.params == MERGE_SLAVE) {
            EnFloormas_SetupSmDecideAction(pthis);
        } else {
            EnFloormas_SetupSmWalk(pthis);
        }
    }
}

void EnFloormas_BigWalk(EnFloormas* pthis, GlobalContext* globalCtx) {
    s32 animPastFrame;

    SkelAnime_Update(&pthis->skelAnime);
    animPastFrame = Animation_OnFrame(&pthis->skelAnime, 0.0f);
    if (animPastFrame) {
        if (pthis->actionTimer != 0) {
            pthis->actionTimer--;
        }
    }
    if (((animPastFrame || (Animation_OnFrame(&pthis->skelAnime, 12.0f))) ||
         (Animation_OnFrame(&pthis->skelAnime, 24.0f) != 0)) ||
        (Animation_OnFrame(&pthis->skelAnime, 36.0f) != 0)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_WALK);
    }

    if ((pthis->actor.xzDistToPlayer < 320.0f) && (Actor_IsFacingPlayer(&pthis->actor, 0x4000))) {
        EnFloormas_SetupRun(pthis);
    } else if (pthis->actor.bgCheckFlags & 8) {
        // set target rotation to the colliding wall's rotation
        pthis->actionTarget = pthis->actor.wallYaw;
        EnFloormas_SetupTurn(pthis);
    } else if ((pthis->actor.xzDistToPlayer < 400.0f) && !Actor_IsFacingPlayer(&pthis->actor, 0x4000)) {
        // set target rotation to link.
        pthis->actionTarget = pthis->actor.yawTowardsPlayer;
        EnFloormas_SetupTurn(pthis);
    } else if (pthis->actionTimer == 0) {
        EnFloormas_SetupBigStopWalk(pthis);
    }
}

void EnFloormas_BigStopWalk(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnFloormas_SetupBigDecideAction(pthis);
    }
}

void EnFloormas_Run(EnFloormas* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f) ||
        Animation_OnFrame(&pthis->skelAnime, 24.0f) || Animation_OnFrame(&pthis->skelAnime, 36.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_WALK);
    }

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x71C);

    if ((pthis->actor.xzDistToPlayer < 280.0f) && Actor_IsFacingPlayer(&pthis->actor, 0x2000) &&
        !(pthis->actor.bgCheckFlags & 8)) {
        EnFloormas_SetupHover(pthis, globalCtx);
    } else if (pthis->actor.xzDistToPlayer > 400.0f) {
        EnFloormas_SetupBigWalk(pthis);
    }
}

void EnFloormas_Turn(EnFloormas* pthis, GlobalContext* globalCtx) {
    char pad[4];
    f32 sp30;
    f32 sp2C;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnFloormas_SetupStand(pthis);
    }

    if (((pthis->skelAnime.playSpeed > 0.0f) && Animation_OnFrame(&pthis->skelAnime, 21.0f)) ||
        ((pthis->skelAnime.playSpeed < 0.0f) && Animation_OnFrame(&pthis->skelAnime, 6.0f))) {
        if (pthis->actor.scale.x > 0.004f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_WALK);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_WALK);
        }
    }
    // Needed to match
    if (!pthis->skelAnime.curFrame) {}
    if (pthis->skelAnime.curFrame >= 7.0f && pthis->skelAnime.curFrame < 22.0f) {
        sp30 = Math_SinS(pthis->actor.shape.rot.y + 0x4268);
        sp2C = Math_CosS(pthis->actor.shape.rot.y + 0x4268);
        pthis->actor.shape.rot.y += pthis->actionTarget;
        pthis->actor.world.pos.x -=
            (pthis->actor.scale.x * 2700.0f) * (Math_SinS(pthis->actor.shape.rot.y + 0x4268) - sp30);
        pthis->actor.world.pos.z -=
            (pthis->actor.scale.x * 2700.0f) * (Math_CosS(pthis->actor.shape.rot.y + 0x4268) - sp2C);
    }
}

void EnFloormas_Hover(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnFloormas_SetupCharge(pthis);
    }
    pthis->actor.shape.rot.x += 0x140;
    pthis->actor.world.pos.y += 10.0f;
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 2730);
    Math_StepToS(&pthis->zOffset, 1200, 100);
}

void EnFloormas_Slide(EnFloormas* pthis, GlobalContext* globalCtx) {
    static Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Vec3f velocity;

    pos.x = pthis->actor.world.pos.x;
    pos.z = pthis->actor.world.pos.z;
    pos.y = pthis->actor.floorHeight;

    velocity.y = 2.0f;
    velocity.x = Math_SinS(pthis->actor.shape.rot.y + 0x6000) * 7.0f;
    velocity.z = Math_CosS(pthis->actor.shape.rot.y + 0x6000) * 7.0f;

    func_800286CC(globalCtx, &pos, &velocity, &accel, 450, 100);

    velocity.x = Math_SinS(pthis->actor.shape.rot.y - 0x6000) * 7.0f;
    velocity.z = Math_CosS(pthis->actor.shape.rot.y - 0x6000) * 7.0f;

    func_800286CC(globalCtx, &pos, &velocity, &accel, 450, 100);

    func_8002F974(&pthis->actor, NA_SE_EN_FLOORMASTER_SLIDING);
}

void EnFloormas_Charge(EnFloormas* pthis, GlobalContext* globalCtx) {
    f32 distFromGround;

    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }

    Math_StepToF(&pthis->actor.speedXZ, 15.0f, SQ(pthis->actor.speedXZ) * (1.0f / 3.0f));
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x1680, 0x140);

    distFromGround = pthis->actor.world.pos.y - pthis->actor.floorHeight;
    if (distFromGround < 10.0f) {
        pthis->actor.world.pos.y = pthis->actor.floorHeight + 10.0f;
        pthis->actor.gravity = 0.0f;
        pthis->actor.velocity.y = 0.0f;
    }

    if (distFromGround < 12.0f) {
        EnFloormas_Slide(pthis, globalCtx);
    }

    if ((pthis->actor.bgCheckFlags & 8) || (pthis->actionTimer == 0)) {
        EnFloormas_SetupLand(pthis);
    }
}

void EnFloormas_Land(EnFloormas* pthis, GlobalContext* globalCtx) {
    s32 isOnGround;

    isOnGround = pthis->actor.bgCheckFlags & 1;
    if (pthis->actor.bgCheckFlags & 2) {
        if (pthis->actor.params != MERGE_MASTER) {
            EnFloormas_MakeVulnerable(pthis);
        }

        if (pthis->actor.velocity.y < -4.0f) {
            if (pthis->actor.scale.x > 0.004f) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_LAND);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_LAND);
            }
        }
    }
    if (pthis->actor.bgCheckFlags & 8) {
        pthis->actor.speedXZ = 0.0f;
    }

    if (isOnGround) {
        Math_StepToF(&pthis->actor.speedXZ, 0.0f, 2.0f);
    }

    if ((pthis->actor.speedXZ > 0.0f) && ((pthis->actor.world.pos.y - pthis->actor.floorHeight) < 12.0f)) {
        EnFloormas_Slide(pthis, globalCtx);
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actionTimer != 0) {
            pthis->actionTimer--;
        }

        if (pthis->actionTimer == 0 && isOnGround) {
            if (pthis->skelAnime.endFrame < 45.0f) {
                pthis->skelAnime.endFrame = Animation_GetLastFrame(&gWallmasterJumpAnim);
            } else if (pthis->actor.params == MERGE_MASTER) {
                EnFloormas_SetupMerge(pthis);
            } else {
                EnFloormas_SetupStand(pthis);
                pthis->smActionTimer = 50;
            }
        }
    }

    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x140);
    Math_StepToS(&pthis->zOffset, -1600, 100);
}

void EnFloormas_Split(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1) {
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->smActionTimer = 50;
            EnFloormas_SetupStand(pthis);
        }
        Math_StepToF(&pthis->actor.speedXZ, 0.0f, 1.0f);
    }

    if (pthis->actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_LAND);
    }
}

void EnFloormas_SmWalk(EnFloormas* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    DECR(pthis->smActionTimer);

    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 18.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_WALK);
    }

    if (pthis->smActionTimer == 0) {
        EnFloormas_SetupSmDecideAction(pthis);
    } else if (pthis->actor.bgCheckFlags & 8) {
        pthis->actionTarget = pthis->actor.wallYaw;
        EnFloormas_SetupTurn(pthis);
    } else if (pthis->actor.xzDistToPlayer < 120.0f) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 0x38E);
    }
}

void EnFloormas_SmDecideAction(EnFloormas* pthis, GlobalContext* globalCtx) {
    Actor* primaryFloormas;
    s32 isAgainstWall;

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 18.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_WALK);
    }
    isAgainstWall = pthis->actor.bgCheckFlags & 8;
    if (isAgainstWall) {
        pthis->actionTarget = pthis->actor.wallYaw;
        EnFloormas_SetupTurn(pthis);
        return;
    }

    if (pthis->actor.params == MERGE_SLAVE) {
        if (pthis->actor.parent->params == MERGE_MASTER) {
            primaryFloormas = pthis->actor.parent;
        } else if (pthis->actor.child->params == MERGE_MASTER) {
            primaryFloormas = pthis->actor.child;
        } else {
            pthis->actor.params = 0x10;
            return;
        }

        Math_ScaledStepToS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardActor(&pthis->actor, primaryFloormas), 0x38E);
        if (Actor_WorldDistXZToActor(&pthis->actor, primaryFloormas) < 80.0f) {
            EnFloormas_SetupSlaveJumpAtMaster(pthis);
        }
    } else {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x71C);
        if (pthis->actor.xzDistToPlayer < 80.0f) {
            EnFloormas_SetupJumpAtLink(pthis);
        }
    }
}

void EnFloormas_SmShrink(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.0015f)) {
        EnFloormas_SetupSmWait(pthis);
    }
    pthis->actor.scale.z = pthis->actor.scale.x;
    pthis->actor.scale.y = pthis->actor.scale.x;
}

void EnFloormas_JumpAtLink(EnFloormas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->skelAnime.curFrame < 20.0f) {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    } else if (Animation_OnFrame(&pthis->skelAnime, 20.0f)) {
        pthis->actor.speedXZ = 5.0f;
        pthis->actor.velocity.y = 7.0f;
    } else if (pthis->actor.bgCheckFlags & 2) {
        pthis->actionTimer = 0x32;
        pthis->actor.speedXZ = 0.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_LAND);
        EnFloormas_SetupLand(pthis);
    } else if ((pthis->actor.yDistToPlayer < -10.0f) && (pthis->collider.base.ocFlags1 & OC1_HIT) &&
               (&player->actor == pthis->collider.base.oc)) {
        globalCtx->grabPlayer(globalCtx, player);
        EnFloormas_SetupGrabLink(pthis, player);
    }
}

void EnFloormas_GrabLink(EnFloormas* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    EnFloormas* parent;
    EnFloormas* child;
    f32 yDelta;
    f32 xzDelta;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->skelAnime.playSpeed > 0.0f) {
            pthis->skelAnime.playSpeed = -1.0f;
            pthis->skelAnime.endFrame = 36.0f;
            pthis->skelAnime.startFrame = 45.0f;
        } else {
            pthis->skelAnime.playSpeed = 1.0f;
            pthis->skelAnime.endFrame = 45.0f;
            pthis->skelAnime.startFrame = 36.0f;
        }
    }

    if (!LINK_IS_ADULT) {
        yDelta = CLAMP(-pthis->actor.yDistToPlayer, 20.0f, 30.0f);
        xzDelta = -10.0f;
    } else {
        yDelta = CLAMP(-pthis->actor.yDistToPlayer, 25.0f, 45.0f);
        xzDelta = -30.0f;
    }

    pthis->actor.world.pos.y = player->actor.world.pos.y + yDelta;
    pthis->actor.world.pos.x = Math_SinS(pthis->actor.shape.rot.y) * (xzDelta * 0.1f) + player->actor.world.pos.x;
    pthis->actor.world.pos.z = Math_CosS(pthis->actor.shape.rot.y) * (xzDelta * 0.1f) + player->actor.world.pos.z;

    // let go
    if (!(player->stateFlags2 & 0x80) || (player->invincibilityTimer < 0)) {
        parent = (EnFloormas*)pthis->actor.parent;
        child = (EnFloormas*)pthis->actor.child;

        if (((parent->actionFunc == EnFloormas_GrabLink) || parent->actionFunc == EnFloormas_SmWait) &&
            (child->actionFunc == EnFloormas_GrabLink || child->actionFunc == EnFloormas_SmWait)) {

            parent->actor.params = MERGE_SLAVE;
            child->actor.params = MERGE_SLAVE;
            pthis->actor.params = MERGE_MASTER;
        }

        pthis->actor.shape.rot.x = 0;
        pthis->actor.velocity.y = 6.0f;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.speedXZ = -3.0f;
        EnFloormas_SetupLand(pthis);
    } else {
        // Damage link every 20 frames
        if ((pthis->actionTarget % 20) == 0) {
            if (!LINK_IS_ADULT) {
                func_8002F7DC(&player->actor, NA_SE_VO_LI_DAMAGE_S_KID);
            } else {
                func_8002F7DC(&player->actor, NA_SE_VO_LI_DAMAGE_S);
            }
            globalCtx->damagePlayer(globalCtx, -8);
        }
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_STICK);
}

void EnFloormas_SmSlaveJumpAtMaster(EnFloormas* pthis, GlobalContext* globalCtx) {
    Actor* primFloormas;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.parent->params == MERGE_MASTER) {
        primFloormas = pthis->actor.parent;
    } else if (pthis->actor.child->params == MERGE_MASTER) {
        primFloormas = pthis->actor.child;
    } else {
        if (pthis->actor.bgCheckFlags & 2) {
            pthis->actor.params = 0x10;
            EnFloormas_SetupLand(pthis);
        }
        return;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 20.0f)) {
        pthis->actor.speedXZ = 5.0f;
        pthis->actor.velocity.y = 7.0f;
    } else if (pthis->skelAnime.curFrame < 20.0f) {
        Math_ApproachS(&pthis->actor.shape.rot.y, Actor_WorldYawTowardActor(&pthis->actor, primFloormas), 2, 0xE38);
    } else if ((((primFloormas->world.pos.y - pthis->actor.world.pos.y) < -10.0f) &&
                (fabsf(pthis->actor.world.pos.x - primFloormas->world.pos.x) < 10.0f)) &&
               (fabsf(pthis->actor.world.pos.z - primFloormas->world.pos.z) < 10.0f)) {
        EnFloormas_SetupSmWait(pthis);
        pthis->collider.base.ocFlags1 |= OC1_ON;
    } else if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_LAND);
        EnFloormas_SetupLand(pthis);
    }

    if (fabsf(pthis->actor.world.pos.x - primFloormas->world.pos.x) < 5.0f &&
        fabsf(pthis->actor.world.pos.z - primFloormas->world.pos.z) < 5.0f) {
        Math_StepToF(&pthis->actor.speedXZ, 0, 2.0f);
    }
}

void EnFloormas_Merge(EnFloormas* pthis, GlobalContext* globalCtx) {
    EnFloormas* parent;
    EnFloormas* child;
    s32 mergeCnt;
    f32 prevScale;
    f32 curScale;

    mergeCnt = 0;

    DECR(pthis->smActionTimer);

    parent = (EnFloormas*)pthis->actor.parent;
    child = (EnFloormas*)pthis->actor.child;

    if (pthis->smActionTimer == 0) {
        if (parent->actionFunc != EnFloormas_SmWait) {
            EnFloormas_SetupSmShrink(parent, globalCtx);
        }

        if (child->actionFunc != EnFloormas_SmWait) {
            EnFloormas_SetupSmShrink(child, globalCtx);
        }
    } else {
        if ((parent->actionFunc != EnFloormas_SmWait) && (parent->actionFunc != EnFloormas_SmShrink)) {
            mergeCnt++;
        }

        if ((child->actionFunc != EnFloormas_SmWait) && (child->actionFunc != EnFloormas_SmShrink)) {
            mergeCnt++;
        }
    }

    prevScale = pthis->actor.scale.x;

    if (mergeCnt == 1) {
        Math_StepToF(&pthis->actor.scale.x, 0.007f, 0.0005f);
    } else if (mergeCnt == 0) {
        Math_StepToF(&pthis->actor.scale.x, 0.01f, 0.0005f);
    }

    curScale = pthis->actor.scale.x;
    pthis->actor.scale.y = pthis->actor.scale.z = curScale;

    if (((prevScale == 0.007f) || (prevScale == 0.004f)) && (prevScale != pthis->actor.scale.x)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_EXPAND);
    }

    pthis->collider.dim.radius = (sCylinderInit.dim.radius * 100.0f) * pthis->actor.scale.x;
    pthis->collider.dim.height = (sCylinderInit.dim.height * 100.0f) * pthis->actor.scale.x;

    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->actor.scale.x >= 0.01f) {
            pthis->actor.flags &= ~ACTOR_FLAG_4;
            EnFloormas_MakeVulnerable(pthis);
            pthis->actor.params = 0;
            pthis->collider.info.bumperFlags |= BUMP_HOOKABLE;
            pthis->actor.colChkInfo.health = sColChkInfoInit.health;
            EnFloormas_SetupStand(pthis);
        } else {
            if (pthis->actionTimer == 0) {
                Animation_PlayOnce(&pthis->skelAnime, &gFloormasterTapFingerAnim);
                pthis->actionTimer = 1;
            } else {
                Animation_PlayOnce(&pthis->skelAnime, &gWallmasterWaitAnim);
                pthis->actionTimer = 0;
            }
        }
    }
    func_8002F974(&pthis->actor, NA_SE_EN_FLOORMASTER_RESTORE - SFX_FLAG);
}

void EnFloormas_SmWait(EnFloormas* pthis, GlobalContext* globalCtx) {
}

void EnFloormas_TakeDamage(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnFloormas_Die(pthis, globalCtx);
        } else {
            EnFloormas_SetupRecover(pthis);
        }
    }

    if (Animation_OnFrame(&pthis->skelAnime, 13.0f)) {
        if (pthis->actor.scale.x > 0.004f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        }
    }
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.2f);
}

void EnFloormas_Recover(EnFloormas* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnFloormas_SetupStand(pthis);
    }
}

void EnFloormas_Freeze(EnFloormas* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (pthis->actionTimer == 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnFloormas_Die(pthis, globalCtx);
            return;
        }
        EnFloormas_SetupStand(pthis);
    }
}

void EnFloormas_ColliderCheck(EnFloormas* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 isSmall;

    if ((pthis->collider.base.acFlags & AC_HIT) != 0) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (pthis->collider.base.colType != COLTYPE_HARD) {
                isSmall = 0;
                if (pthis->actor.scale.x < 0.01f) {
                    isSmall = 1;
                }
                if (isSmall && pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x80) {
                    pthis->actor.colChkInfo.damage = 2;
                    pthis->actor.colChkInfo.damageEffect = 0;
                }
                if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    if (isSmall) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLOORMASTER_SM_DEAD);
                    } else {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_DEAD);
                    }
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                    pthis->actor.flags &= ~ACTOR_FLAG_0;
                } else if (pthis->actor.colChkInfo.damage != 0) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FALL_DAMAGE);
                }

                if ((pthis->actor.colChkInfo.damageEffect == 4) || (pthis->actor.colChkInfo.damageEffect == 1)) {
                    if (pthis->actionFunc != EnFloormas_Freeze) {
                        EnFloormas_SetupFreeze(pthis);
                    }
                } else {
                    if (pthis->actor.colChkInfo.damageEffect == 2) {
                        EffectSsFCircle_Spawn(globalCtx, &pthis->actor, &pthis->actor.world.pos,
                                              pthis->actor.scale.x * 4000.0f, pthis->actor.scale.x * 4000.0f);
                    }
                    EnFloormas_SetupTakeDamage(pthis);
                }
            }
        }
    }
}

void EnFloormas_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFloormas* pthis = (EnFloormas*)thisx;
    s32 pad;

    if (pthis->actionFunc != EnFloormas_SmWait) {
        if (pthis->collider.base.atFlags & AT_HIT) {
            pthis->collider.base.atFlags &= ~AT_HIT;
            pthis->actor.speedXZ *= -0.5f;

            if (-5.0f < pthis->actor.speedXZ) {
                pthis->actor.speedXZ = -5.0f;
            } else {
                pthis->actor.speedXZ = pthis->actor.speedXZ;
            }

            pthis->actor.velocity.y = 5.0f;

            EnFloormas_SetupLand(pthis);
        }
        EnFloormas_ColliderCheck(pthis, globalCtx);
        pthis->actionFunc(pthis, globalCtx);

        if (pthis->actionFunc != EnFloormas_TakeDamage) {
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        }

        if (pthis->actionFunc != EnFloormas_GrabLink) {
            Actor_MoveForward(&pthis->actor);
        }

        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, pthis->actor.scale.x * 3000.0f, 0.0f, 0x1D);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (pthis->actionFunc == EnFloormas_Charge) {
            pthis->actor.flags |= ACTOR_FLAG_24;
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->actionFunc != EnFloormas_GrabLink) {
            if (pthis->actionFunc != EnFloormas_Split && pthis->actionFunc != EnFloormas_TakeDamage &&
                pthis->actor.freezeTimer == 0) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }

            if ((pthis->actionFunc != EnFloormas_SmSlaveJumpAtMaster) || (pthis->skelAnime.curFrame < 20.0f)) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }

        Actor_SetFocus(&pthis->actor, pthis->actor.scale.x * 2500.0f);

        if (pthis->collider.base.colType == COLTYPE_HARD) {
            if (pthis->actionTarget != 0) {
                pthis->actionTarget--;
            }

            if (pthis->actionTarget == 0) {
                pthis->actionTarget = 0x28;
            }
        }
    }
}

s32 EnFloormas_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx, Gfx** gfx) {
    EnFloormas* pthis = (EnFloormas*)thisx;

    if (limbIndex == 1) {
        pos->z += pthis->zOffset;
    }
    return false;
}

void EnFloormas_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    if (limbIndex == 2) {
        Matrix_Push();
        Matrix_Translate(1600.0f, -700.0f, -1700.0f, MTXMODE_APPLY);
        Matrix_RotateY(DEGTORAD(60.0f), MTXMODE_APPLY);
        Matrix_RotateZ(DEGTORAD(15.0f), MTXMODE_APPLY);
        Matrix_Scale(2.0f, 2.0f, 2.0f, MTXMODE_APPLY);
        gSPMatrix((*gfx)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_floormas.c", 2299), G_MTX_LOAD);
        gSPDisplayList((*gfx)++, gWallmasterFingerDL);
        Matrix_Pop();
    }
}

static Color_RGBA8 sMergeColor = { 0, 255, 0, 0 };

void EnFloormas_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFloormas* pthis = (EnFloormas*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_floormas.c", 2318);

    func_80093D18(globalCtx->state.gfxCtx);
    if (pthis->collider.base.colType == COLTYPE_HARD) {
        func_80026230(globalCtx, &sMergeColor, pthis->actionTarget % 0x28, 0x28);
    }

    POLY_OPA_DISP =
        SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                           EnFloormas_OverrideLimbDraw, EnFloormas_PostLimbDraw, pthis, POLY_OPA_DISP);
    if (pthis->collider.base.colType == COLTYPE_HARD) {
        func_80026608(globalCtx);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_floormas.c", 2340);
}

void EnFloormas_DrawHighlighted(Actor* thisx, GlobalContext* globalCtx) {
    EnFloormas* pthis = (EnFloormas*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_floormas.c", 2352);

    func_80093D84(globalCtx->state.gfxCtx);
    if (pthis->collider.base.colType == COLTYPE_HARD) {
        func_80026690(globalCtx, &sMergeColor, pthis->actionTarget % 0x28, 0x28);
    }
    POLY_XLU_DISP =
        SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                           EnFloormas_OverrideLimbDraw, EnFloormas_PostLimbDraw, pthis, POLY_XLU_DISP);
    if (pthis->collider.base.colType == COLTYPE_HARD) {
        func_80026A6C(globalCtx);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_floormas.c", 2374);
}

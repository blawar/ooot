#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FD_Z_EN_FD_C
#include "actor_common.h"
/*
 * File: z_en_fd.c
 * Overlay: ovl_En_Fd
 * Description: Flare Dancer (enflamed form)
 */

#include "z_en_fd.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_fw/object_fw.h"
#include "def/code_800EC960.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_9)

#define FLG_COREDEAD (0x4000)
#define FLG_COREDONE (0x8000)

void EnFd_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFd_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFd_Draw(Actor* thisx, GlobalContext* globalCtx);
void EnFd_Run(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_SpinAndSpawnFire(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_Reappear(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_SpinAndGrow(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_JumpToGround(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_WaitForCore(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_UpdateFlames(EnFd* pthis);
void EnFd_UpdateDots(EnFd* pthis);
void EnFd_AddEffect(EnFd*, u8, Vec3f*, Vec3f*, Vec3f*, u8, f32, f32);
void EnFd_DrawDots(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_DrawFlames(EnFd* pthis, GlobalContext* globalCtx);
void EnFd_Land(EnFd* pthis, GlobalContext* globalCtx);

ActorInit En_Fd_InitVars = {
    ACTOR_EN_FD,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_FW,
    sizeof(EnFd),
    (ActorFunc)EnFd_Init,
    (ActorFunc)EnFd_Destroy,
    (ActorFunc)EnFd_Update,
    (ActorFunc)EnFd_Draw,
};

static ColliderJntSphElementInit sJntSphElementsInit[12] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040088, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 21, { { 1600, 0, 0 }, 5 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 12, { { 1600, 0, 0 }, 5 }, 400 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 14, { { 800, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, { { 1600, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 16, { { 2000, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 17, { { 800, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 18, { { 1600, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 19, { { 2000, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 4, { { 2200, 0, 0 }, 4 }, 400 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 4, { { 5000, 0, 0 }, 4 }, 300 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 8, { { 2200, 0, 0 }, 4 }, 400 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00040008, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 8, { { 5000, 0, 0 }, 4 }, 300 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    12,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit2 sColChkInit = { 24, 2, 25, 25, MASS_IMMOVABLE };

static struct_80034EC0_Entry sAnimations[] = {
    { &gFlareDancerCastingFireAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, 0.0f },
    { &gFlareDancerBackflipAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -10.0f },
    { &gFlareDancerGettingUpAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -10.0f },
    { &gFlareDancerChasingAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP_INTERP, -10.0f },
    { &gFlareDancerTwirlAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_ONCE_INTERP, -10.0f },
};

s32 EnFd_SpawnCore(EnFd* pthis, GlobalContext* globalCtx) {
    if (pthis->invincibilityTimer != 0) {
        return false;
    }

    if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FW, pthis->corePos.x, pthis->corePos.y,
                           pthis->corePos.z, 0, pthis->actor.shape.rot.y, 0, pthis->runDir) == NULL) {
        return false;
    }

    pthis->actor.child->colChkInfo.health = pthis->actor.colChkInfo.health % 8;

    if (pthis->actor.child->colChkInfo.health == 0) {
        pthis->actor.child->colChkInfo.health = 8;
    }

    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        func_8002DE04(globalCtx, &pthis->actor, pthis->actor.child);
    }

    pthis->coreActive = true;

    return true;
}

void EnFd_SpawnChildFire(EnFd* pthis, GlobalContext* globalCtx, s16 fireCnt, s16 color) {
    s32 i;

    for (i = 0; i < fireCnt; i++) {
        s16 angle = (s16)((((i * 360.0f) / fireCnt) * (0x10000 / 360.0f))) + pthis->actor.yawTowardsPlayer;
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FD_FIRE, pthis->actor.world.pos.x,
                           pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, angle, 0, (color << 0xF) | i);
    }
}

void EnFd_SpawnDot(EnFd* pthis, GlobalContext* globalCtx) {
    Vec3f pos = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };

    if (pthis->actionFunc == EnFd_Run || pthis->actionFunc == EnFd_SpinAndSpawnFire) {
        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.floorHeight + 4.0f;
        pos.z = pthis->actor.world.pos.z;
        accel.x = (Rand_ZeroOne() - 0.5f) * 2.0f;
        accel.y = ((Rand_ZeroOne() - 0.5f) * 0.2f) + 0.3f;
        accel.z = (Rand_ZeroOne() - 0.5f) * 2.0f;
        EnFd_AddEffect(pthis, FD_EFFECT_FLAME, &pos, &velocity, &accel, 8, 0.6f, 0.2f);
    }
}

/**
 * Checks to see if the hammer effect is active, and if it should be applied
 */
s32 EnFd_CheckHammer(EnFd* pthis, GlobalContext* globalCtx) {
    if (pthis->actionFunc == EnFd_Reappear || pthis->actionFunc == EnFd_SpinAndGrow ||
        pthis->actionFunc == EnFd_JumpToGround || pthis->actionFunc == EnFd_WaitForCore) {
        return false;
    } else if (globalCtx->actorCtx.unk_02 != 0 && pthis->actor.xzDistToPlayer < 300.0f &&
               pthis->actor.yDistToPlayer < 60.0f) {
        return true;
    } else {
        return false;
    }
}

s32 EnFd_ColliderCheck(EnFd* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    ColliderInfo* info;

    if (pthis->collider.base.acFlags & AC_HIT || EnFd_CheckHammer(pthis, globalCtx)) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (pthis->invincibilityTimer != 0) {
            return false;
        }
        info = &pthis->collider.elements[0].info;
        if (info->acHitInfo != NULL && (info->acHitInfo->toucher.dmgFlags & 0x80)) {
            return false;
        }

        if (!EnFd_SpawnCore(pthis, globalCtx)) {
            return false;
        }
        pthis->invincibilityTimer = 30;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_DAMAGE);
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
        return true;
    } else if (DECR(pthis->attackTimer) == 0 && pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        if (pthis->invincibilityTimer != 0) {
            return false;
        }

        if (pthis->collider.base.atFlags & AT_BOUNCED) {
            return false;
        }
        pthis->attackTimer = 30;
        Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
        func_8002F71C(globalCtx, &pthis->actor, pthis->actor.speedXZ + 2.0f, pthis->actor.yawTowardsPlayer, 6.0f);
    }
    return false;
}

/**
 * Determines if `actor` is within an acceptable range for `pthis` to be able to "see" `actor`
 * `actor` must be within 400 units of `pthis`, `actor` must be within +/- 40 degrees facing angle
 * towards `actor`, and there must not be a collision poly between `pthis` and `actor`
 */
s32 EnFd_CanSeeActor(EnFd* pthis, Actor* actor, GlobalContext* globalCtx) {
    CollisionPoly* colPoly;
    s32 bgId;
    Vec3f colPoint;
    s16 angle;
    s32 pad;

    // Check to see if `actor` is within 400 units of `pthis`
    if (Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &actor->world.pos) > 400.0f) {
        return false;
    }

    // Check to see if the angle between pthis facing angle and `actor` is withing ~40 degrees
    angle = (f32)Math_Vec3f_Yaw(&pthis->actor.world.pos, &actor->world.pos) - pthis->actor.shape.rot.y;
    if (ABS(angle) > 0x1C70) {
        return false;
    }

    // check to see if the line between `pthis` and `actor` does not intersect a collision poly
    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->actor.world.pos, &actor->world.pos, &colPoint, &colPoly,
                                true, false, false, true, &bgId)) {
        return false;
    }

    return true;
}

Actor* EnFd_FindBomb(EnFd* pthis, GlobalContext* globalCtx) {
    Actor* actor = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;

    while (actor != NULL) {
        if (actor->params != 0 || actor->parent != NULL) {
            actor = actor->next;
            continue;
        }

        if (actor->id != ACTOR_EN_BOM) {
            actor = actor->next;
            continue;
        }

        if (EnFd_CanSeeActor(pthis, actor, globalCtx) != 1) {
            actor = actor->next;
            continue;
        }

        return actor;
    }
    return NULL;
}

Actor* EnFd_FindPotentialTheat(EnFd* pthis, GlobalContext* globalCtx) {
    Player* player;
    Actor* bomb = EnFd_FindBomb(pthis, globalCtx);

    if (bomb != NULL) {
        return bomb;
    }

    if (pthis->attackTimer != 0) {
        return NULL;
    }

    player = GET_PLAYER(globalCtx);
    if (!EnFd_CanSeeActor(pthis, &player->actor, globalCtx)) {
        return NULL;
    }

    return &player->actor;
}

/**
 * Creates a delta in `dst` for the position from `pthis`'s current position to the next
 * position in a circle formed by `radius` with center at `pthis`'s initial position.
 */
Vec3f* EnFd_GetPosAdjAroundCircle(Vec3f* dst, EnFd* pthis, f32 radius, s16 dir) {
    s16 angle;
    Vec3f newPos;

    angle = Math_Vec3f_Yaw(&pthis->actor.home.pos, &pthis->actor.world.pos) + (dir * 0x1554); // ~30 degrees
    newPos.x = (Math_SinS(angle) * radius) + pthis->actor.home.pos.x;
    newPos.z = (Math_CosS(angle) * radius) + pthis->actor.home.pos.z;
    newPos.x -= pthis->actor.world.pos.x;
    newPos.z -= pthis->actor.world.pos.z;
    *dst = newPos;
    return dst;
}

s32 EnFd_ShouldStopRunning(EnFd* pthis, GlobalContext* globalCtx, f32 radius, s16* runDir) {
    CollisionPoly* poly;
    s32 bgId;
    Vec3f colPoint;
    Vec3f pos;

    // Check to see if the next position on the rotation around the circle
    // will result in a background collision
    EnFd_GetPosAdjAroundCircle(&pos, pthis, radius, *runDir);

    pos.x += pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y;
    pos.z += pthis->actor.world.pos.z;

    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &pthis->actor.world.pos, &pos, &colPoint, &poly, true, false, false,
                                true, &bgId)) {
        *runDir = -*runDir;
        return true;
    }

    if (pthis->circlesToComplete != 0 || DECR(pthis->spinTimer) != 0) {
        return false;
    }

    if (Rand_ZeroOne() > 0.5f) {
        *runDir = -*runDir;
    }
    return true;
}

void EnFd_Fade(EnFd* pthis, GlobalContext* globalCtx) {
    if (pthis->invincibilityTimer != 0) {
        Math_SmoothStepToF(&pthis->fadeAlpha, 0.0f, 0.3f, 10.0f, 0.0f);
        pthis->actor.shape.shadowAlpha = pthis->fadeAlpha;
        if (!(pthis->fadeAlpha >= 0.9f)) {
            pthis->invincibilityTimer = 0;
            pthis->spinTimer = 0;
            pthis->actionFunc = EnFd_WaitForCore;
            pthis->actor.speedXZ = 0.0f;
        }
    }
}

void EnFd_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFd* pthis = (EnFd*)thisx;

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gFlareDancerSkel, NULL, pthis->jointTable, pthis->morphTable, 27);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 32.0f);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colSphs);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(0xF), &sColChkInit);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.flags |= ACTOR_FLAG_24;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->firstUpdateFlag = true;
    pthis->actor.gravity = -1.0f;
    pthis->runDir = Rand_ZeroOne() < 0.5f ? -1 : 1;
    pthis->actor.naviEnemyId = 0x22;
    pthis->actionFunc = EnFd_Reappear;
}

void EnFd_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFd* pthis = (EnFd*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnFd_Reappear(EnFd* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.pos = pthis->actor.home.pos;
    pthis->actor.params = 0;
    pthis->actor.shape.shadowAlpha = 0xFF;
    pthis->coreActive = false;
    pthis->actor.scale.y = 0.0f;
    pthis->fadeAlpha = 255.0f;
    func_80034EC0(&pthis->skelAnime, sAnimations, 0);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_LAUGH);
    pthis->actionFunc = EnFd_SpinAndGrow;
}

void EnFd_SpinAndGrow(EnFd* pthis, GlobalContext* globalCtx) {
    if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
        pthis->actor.velocity.y = 6.0f;
        pthis->actor.scale.y = 0.01f;
        pthis->actor.world.rot.y ^= 0x8000;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.speedXZ = 8.0f;
        func_80034EC0(&pthis->skelAnime, sAnimations, 1);
        pthis->actionFunc = EnFd_JumpToGround;
    } else {
        pthis->actor.scale.y = pthis->skelAnime.curFrame * (0.01f / pthis->skelAnime.animLength);
        pthis->actor.shape.rot.y += 0x2000;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    }
}

void EnFd_JumpToGround(EnFd* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.bgCheckFlags & 1) && !(pthis->actor.velocity.y > 0.0f)) {
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        func_80034EC0(&pthis->skelAnime, sAnimations, 2);
        pthis->actionFunc = EnFd_Land;
    }
}

void EnFd_Land(EnFd* pthis, GlobalContext* globalCtx) {
    Vec3f adjPos;

    Math_SmoothStepToF(&pthis->skelAnime.playSpeed, 1.0f, 0.1f, 1.0f, 0.0f);
    if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
        pthis->spinTimer = Rand_S16Offset(60, 90);
        pthis->runRadius = Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->actor.home.pos);
        EnFd_GetPosAdjAroundCircle(&adjPos, pthis, pthis->runRadius, pthis->runDir);
        pthis->actor.world.rot.y = Math_FAtan2F(adjPos.x, adjPos.z) * (0x8000 / M_PI);
        func_80034EC0(&pthis->skelAnime, sAnimations, 4);
        pthis->actionFunc = EnFd_SpinAndSpawnFire;
    }
}

void EnFd_SpinAndSpawnFire(EnFd* pthis, GlobalContext* globalCtx) {
    f32 deceleration;
    f32 tgtSpeed;
    f32 rotSpeed;

    if ((pthis->spinTimer < 31) && (pthis->invincibilityTimer == 0)) {
        func_8002F974(&pthis->actor, NA_SE_EN_FLAME_FIRE_ATTACK - SFX_FLAG);
    } else {
        func_8002F974(&pthis->actor, NA_SE_EN_FLAME_ROLL - SFX_FLAG);
    }

    if (DECR(pthis->spinTimer) != 0) {
        pthis->actor.shape.rot.y += (pthis->runDir * 0x2000);
        if (pthis->spinTimer == 30 && pthis->invincibilityTimer == 0) {
            if (pthis->actor.xzDistToPlayer > 160.0f) {
                // orange flames
                EnFd_SpawnChildFire(pthis, globalCtx, 8, 0);
            } else {
                // blue flames
                EnFd_SpawnChildFire(pthis, globalCtx, 8, 1);
            }
        }
    } else {
        // slow shape rotation down to meet `pthis` rotation within ~1.66 degrees
        deceleration = pthis->actor.world.rot.y;
        deceleration -= pthis->actor.shape.rot.y;
        rotSpeed = 0.0f;
        tgtSpeed = fabsf(deceleration);
        deceleration /= tgtSpeed;
        Math_ApproachF(&rotSpeed, tgtSpeed, 0.6f, 0x2000);
        rotSpeed *= deceleration;
        pthis->actor.shape.rot.y += (s16)rotSpeed;
        rotSpeed = fabsf(rotSpeed);
        if ((s32)rotSpeed <= 300) {
            // ~1.6 degrees
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        }

        if (pthis->actor.shape.rot.y == pthis->actor.world.rot.y) {
            pthis->initYawToInitPos = Math_Vec3f_Yaw(&pthis->actor.home.pos, &pthis->actor.world.pos);
            pthis->curYawToInitPos = pthis->runDir < 0 ? 0xFFFF : 0;
            pthis->circlesToComplete = (globalCtx->state.frames & 7) + 2;
            pthis->spinTimer = Rand_S16Offset(30, 120);
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
            pthis->actionFunc = EnFd_Run;
        }
    }
}

/**
 * Run around in a circle with the center being the initial position, and
 * the radius being the distance from the initial postion to the nearest
 * threat (bomb or player).
 */
void EnFd_Run(EnFd* pthis, GlobalContext* globalCtx) {
    Actor* potentialThreat;
    s16 yawToYawTarget;
    f32 runRadiusTarget;
    Vec3f adjPos;

    if (EnFd_ShouldStopRunning(pthis, globalCtx, pthis->runRadius, &pthis->runDir)) {
        if (pthis->invincibilityTimer == 0) {
            pthis->actor.world.rot.y ^= 0x8000;
            pthis->actor.velocity.y = 6.0f;
            pthis->actor.speedXZ = 0.0f;
            func_80034EC0(&pthis->skelAnime, sAnimations, 1);
            pthis->actionFunc = EnFd_JumpToGround;
            return;
        }
    }

    yawToYawTarget = Math_Vec3f_Yaw(&pthis->actor.home.pos, &pthis->actor.world.pos) - pthis->initYawToInitPos;
    if (pthis->runDir > 0) {
        if ((u16)pthis->curYawToInitPos > (u16)(yawToYawTarget)) {
            pthis->circlesToComplete--;
        }
    } else if ((u16)pthis->curYawToInitPos < (u16)(yawToYawTarget)) {
        pthis->circlesToComplete--;
    }

    if (pthis->circlesToComplete < 0) {
        pthis->circlesToComplete = 0;
    }
    pthis->curYawToInitPos = yawToYawTarget;

    // If there is a bomb out, or if the player exists, set radius to
    // the distance to that threat, otherwise default to 200.
    potentialThreat = EnFd_FindPotentialTheat(pthis, globalCtx);
    if ((potentialThreat != NULL) && (pthis->invincibilityTimer == 0)) {
        runRadiusTarget = Math_Vec3f_DistXYZ(&pthis->actor.home.pos, &potentialThreat->world.pos);
    } else {
        runRadiusTarget = 200.0f;
    }
    Math_SmoothStepToF(&pthis->runRadius, runRadiusTarget, 0.3f, 100.0f, 0.0f);
    EnFd_GetPosAdjAroundCircle(&adjPos, pthis, pthis->runRadius, pthis->runDir);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(adjPos.x, adjPos.z) * (0x8000 / M_PI), 4, 0xFA0, 1);
    pthis->actor.world.rot = pthis->actor.shape.rot;
    func_8002F974(&pthis->actor, NA_SE_EN_FLAME_RUN - SFX_FLAG);
    if (pthis->skelAnime.curFrame == 6.0f || pthis->skelAnime.curFrame == 13.0f || pthis->skelAnime.curFrame == 28.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_KICK);
    }
    Math_SmoothStepToF(&pthis->actor.speedXZ, 8.0f, 0.1f, 1.0f, 0.0f);
}

/**
 * En_Fw will set `pthis` params when it is done with its action.
 * It will set FLG_COREDONE when the core has returned to `pthis`'s initial
 * position, and FLG_COREDEAD when there is no health left
 */
void EnFd_WaitForCore(EnFd* pthis, GlobalContext* globalCtx) {
    if (pthis->spinTimer != 0) {
        pthis->spinTimer--;
        if (pthis->spinTimer == 0) {
            Actor_Kill(&pthis->actor);
        }
    } else if (pthis->actor.params & FLG_COREDONE) {
        pthis->actionFunc = EnFd_Reappear;
    } else if (pthis->actor.params & FLG_COREDEAD) {
        pthis->actor.params = 0;
        pthis->spinTimer = 30;
    }
}

void EnFd_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFd* pthis = (EnFd*)thisx;
    s32 pad;

    if (pthis->firstUpdateFlag) {
        func_800F5ACC(NA_BGM_MINI_BOSS);
        pthis->firstUpdateFlag = false;
    }

    if (pthis->actionFunc != EnFd_Reappear) {
        SkelAnime_Update(&pthis->skelAnime);
        EnFd_SpawnDot(pthis, globalCtx);
    }

    if (CHECK_FLAG_ALL(pthis->actor.flags, ACTOR_FLAG_13)) {
        // has been hookshoted
        if (EnFd_SpawnCore(pthis, globalCtx)) {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->invincibilityTimer = 30;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FLAME_DAMAGE);
            Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
        } else {
            pthis->actor.flags &= ~ACTOR_FLAG_13;
        }
    } else if (pthis->actionFunc != EnFd_WaitForCore) {
        EnFd_ColliderCheck(pthis, globalCtx);
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    EnFd_Fade(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    EnFd_UpdateDots(pthis);
    EnFd_UpdateFlames(pthis);
    if (pthis->actionFunc != EnFd_Reappear && pthis->actionFunc != EnFd_SpinAndGrow &&
        pthis->actionFunc != EnFd_WaitForCore) {
        if (pthis->attackTimer == 0 && pthis->invincibilityTimer == 0) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        if ((pthis->actionFunc == EnFd_Run) || (pthis->actionFunc == EnFd_SpinAndSpawnFire)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

s32 EnFd_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfxP) {
    EnFd* pthis = (EnFd*)thisx;

    if (pthis->invincibilityTimer != 0) {
        switch (limbIndex) {
            case 13:
            case 21:
                *dList = NULL;
                break;
        }
    }

    return false;
}

void EnFd_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfxP) {
    EnFd* pthis = (EnFd*)thisx;
    Vec3f unused0 = { 6800.0f, 0.0f, 0.0f };
    Vec3f unused1 = { 6800.0f, 0.0f, 0.0f };
    Vec3f initialPos = { 0.0f, 0.0f, 0.0f };
    Vec3f pos = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    s32 i;

    if (limbIndex == 21) {
        Matrix_MultVec3f(&initialPos, &pthis->corePos);
    }

    if (limbIndex == 13) {
        Matrix_MultVec3f(&initialPos, &pthis->actor.focus.pos);
    }

    if (limbIndex == 3 || limbIndex == 6 || limbIndex == 7 || limbIndex == 10 || limbIndex == 14 || limbIndex == 15 ||
        limbIndex == 17 || limbIndex == 18 || limbIndex == 20 || limbIndex == 22 || limbIndex == 23 ||
        limbIndex == 24 || limbIndex == 25 || limbIndex == 26) {
        if ((globalCtx->state.frames % 2) != 0) {
            for (i = 0; i < 1; i++) {
                Matrix_MultVec3f(&initialPos, &pos);
                pos.x += (Rand_ZeroOne() - 0.5f) * 20.0f;
                pos.y += (Rand_ZeroOne() - 0.5f) * 40.0f;
                pos.z += (Rand_ZeroOne() - 0.5f) * 20.0f;
                accel.x = (Rand_ZeroOne() - 0.5f) * 0.4f;
                accel.y = ((Rand_ZeroOne() - 0.5f) * 0.2f) + 0.6f;
                accel.z = (Rand_ZeroOne() - 0.5f) * 0.4f;
                EnFd_AddEffect(pthis, FD_EFFECT_DOT, &pos, &velocity, &accel, 0, 0.006f, 0.0f);
            }
        }
    }

    Collider_UpdateSpheres(limbIndex, &pthis->collider);
}

void EnFd_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFd* pthis = (EnFd*)thisx;
    s32 clampedHealth;
    Color_RGBA8 primColors[] = {
        { 255, 255, 200, 255 },
        { 200, 200, 200, 255 },
        { 255, 255, 0, 255 },
    };
    Color_RGBA8 envColors[] = {
        { 0, 255, 0, 255 },
        { 0, 0, 255, 255 },
        { 255, 0, 0, 255 },
    };
    const auto& frames = globalCtx->state.frames;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 1751);

    Matrix_Push();
    EnFd_DrawDots(pthis, globalCtx);
    EnFd_DrawFlames(pthis, globalCtx);
    Matrix_Pop();
    if (pthis->actionFunc != EnFd_Reappear && !(pthis->fadeAlpha < 0.9f)) {
        if (1) {}
        func_80093D84(globalCtx->state.gfxCtx);
        clampedHealth = CLAMP(thisx->colChkInfo.health - 1, 0, 23);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 128, primColors[clampedHealth / 8].r, primColors[clampedHealth / 8].g,
                        primColors[clampedHealth / 8].b, (u8)pthis->fadeAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, envColors[clampedHealth / 8].r, envColors[clampedHealth / 8].g,
                       envColors[clampedHealth / 8].b, (u8)pthis->fadeAlpha);
        gSPSegment(
            POLY_XLU_DISP++, 0x8,
            Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, 0xFF - (u8)(frames.whole() * 6), 8, 0x40));
        gDPPipeSync(POLY_XLU_DISP++);
        gSPSegment(POLY_XLU_DISP++, 0x9, D_80116280);

        POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, EnFd_OverrideLimbDraw, EnFd_PostLimbDraw, pthis,
                                           POLY_XLU_DISP);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 1822);
}

void EnFd_AddEffect(EnFd* pthis, u8 type, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u8 timer, f32 scale,
                    f32 scaleStep) {
    EnFdEffect* eff = pthis->effects;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type != FD_EFFECT_NONE) {
            continue;
        }
        eff->scale = scale;
        eff->scaleStep = scaleStep;
        eff->initialTimer = eff->timer = timer;
        eff->type = type;
        eff->pos = *pos;
        eff->accel = *accel;
        eff->velocity = *velocity;
        if (eff->type == FD_EFFECT_DOT) {
            eff->color.a = 255;
            eff->timer = (s16)(Rand_ZeroOne() * 10.0f);
        }
        return;
    }
}

void EnFd_UpdateFlames(EnFd* pthis) {
    s16 i;
    EnFdEffect* eff = pthis->effects;

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type == FD_EFFECT_FLAME) {
            eff->timer--;
            if (eff->timer == 0) {
                eff->type = FD_EFFECT_NONE;
            }
            eff->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
            eff->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;
            eff->pos.x += eff->velocity.x;
            eff->pos.y += eff->velocity.y;
            eff->pos.z += eff->velocity.z;
            eff->velocity.x += eff->accel.x;
            eff->velocity.y += eff->accel.y;
            eff->velocity.z += eff->accel.z;
            eff->scale += eff->scaleStep;
        }
    }
}

void EnFd_UpdateDots(EnFd* pthis) {
    EnFdEffect* eff = pthis->effects;
    s16 i;
    Color_RGBA8 dotColors[] = {
        { 255, 128, 0, 0 },
        { 255, 0, 0, 0 },
        { 255, 255, 0, 0 },
        { 255, 0, 0, 0 },
    };

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type == FD_EFFECT_DOT) {
            eff->pos.x += eff->velocity.x;
            eff->pos.y += eff->velocity.y;
            eff->pos.z += eff->velocity.z;
            eff->timer++;
            eff->velocity.x += eff->accel.x;
            eff->velocity.y += eff->accel.y;
            eff->velocity.z += eff->accel.z;

            eff->color.r = dotColors[eff->timer % 4].r;
            eff->color.g = dotColors[eff->timer % 4].g;
            eff->color.b = dotColors[eff->timer % 4].b;
            if (eff->color.a > 30) {
                eff->color.a -= 30;
            } else {
                eff->color.a = 0;
                eff->type = FD_EFFECT_NONE;
            }
        }
    }
}

void EnFd_DrawFlames(EnFd* pthis, GlobalContext* globalCtx) {
    static void* dustTextures[] = {
        gDust8Tex, gDust7Tex, gDust6Tex, gDust5Tex, gDust4Tex, gDust3Tex, gDust2Tex, gDust1Tex,
    };
    s32 firstDone;
    s16 i;
    s16 idx;
    EnFdEffect* eff = pthis->effects;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 1969);
    firstDone = false;
    if (1) {}
    func_80093D84(globalCtx->state.gfxCtx);
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type == FD_EFFECT_FLAME) {
            if (!firstDone) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
                gSPDisplayList(POLY_XLU_DISP++, gFlareDancerDL_7928);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 10, 0, (u8)((pthis->fadeAlpha / 255.0f) * 255));
                firstDone = true;
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 0, (u8)((pthis->fadeAlpha / 255.0f) * 255));
            gDPPipeSync(POLY_XLU_DISP++);
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fd.c", 2006),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            idx = eff->timer * (8.0f / eff->initialTimer);
            gSPSegment(POLY_XLU_DISP++, 0x8, SEGMENTED_TO_VIRTUAL(dustTextures[idx]));
            gSPDisplayList(POLY_XLU_DISP++, gFlareDancerSquareParticleDL);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 2020);
}

void EnFd_DrawDots(EnFd* pthis, GlobalContext* globalCtx) {
    s16 i;
    s16 firstDone;
    EnFdEffect* eff = pthis->effects;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 2034);

    firstDone = false;
    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++, eff++) {
        if (eff->type == FD_EFFECT_DOT) {
            if (!firstDone) {
                func_80093D84(globalCtx->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gFlareDancerDL_79F8);
                firstDone = true;
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, eff->color.r, eff->color.g, eff->color.b,
                            (u8)(eff->color.a * (pthis->fadeAlpha / 255.0f)));
            gDPPipeSync(POLY_XLU_DISP++);
            if (1) {}
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fd.c", 2064),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gFlareDancerTriangleParticleDL);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fd.c", 2071);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FISH_Z_EN_FISH_C
#include "actor_common.h"
/*
 * File: z_en_fish.c
 * Overlay: ovl_En_Fish
 * Description: Fish
 */

#include "z_en_fish.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "vt.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnFish_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnFish_Respawning_SetupSlowDown(EnFish* pthis);
void EnFish_Respawning_SlowDown(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Respawning_SetupFollowChild(EnFish* pthis);
void EnFish_Respawning_FollowChild(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Respawning_SetupFleePlayer(EnFish* pthis);
void EnFish_Respawning_FleePlayer(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Respawning_SetupApproachPlayer(EnFish* pthis);
void EnFish_Respawning_ApproachPlayer(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Dropped_SetupFall(EnFish* pthis);
void EnFish_Dropped_Fall(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Dropped_SetupFlopOnGround(EnFish* pthis);
void EnFish_Dropped_FlopOnGround(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Dropped_SetupSwimAway(EnFish* pthis);
void EnFish_Dropped_SwimAway(EnFish* pthis, GlobalContext* globalCtx);
void EnFish_Unique_SetupSwimIdle(EnFish* pthis);
void EnFish_Unique_SwimIdle(EnFish* pthis, GlobalContext* globalCtx);

// Used in the cutscene functions
static Actor* D_80A17010 = NULL;
static f32 D_80A17014 = 0.0f;
static f32 D_80A17018 = 0.0f;

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 5 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

ActorInit En_Fish_InitVars = {
    ACTOR_EN_FISH,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnFish),
    (ActorFunc)EnFish_Init,
    (ActorFunc)EnFish_Destroy,
    (ActorFunc)EnFish_Update,
    (ActorFunc)EnFish_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 900, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 40, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 700, ICHAIN_STOP),
};

f32 EnFish_XZDistanceSquared(Vec3f* v1, Vec3f* v2) {
    return SQ(v1->x - v2->x) + SQ(v1->z - v2->z);
}

void EnFish_SetInWaterAnimation(EnFish* pthis) {
    Animation_Change(&pthis->skelAnime, &gFishInWaterAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gFishInWaterAnim),
                     ANIMMODE_LOOP_INTERP, 2.0f);
}

void EnFish_SetOutOfWaterAnimation(EnFish* pthis) {
    Animation_Change(&pthis->skelAnime, &gFishOutOfWaterAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gFishOutOfWaterAnim),
                     ANIMMODE_LOOP_INTERP, 2.0f);
}

void EnFish_BeginRespawn(EnFish* pthis) {
    pthis->respawnTimer = 400;
    Actor_SetScale(&pthis->actor, 0.001f);
    pthis->actor.draw = NULL;
}

void EnFish_SetCutsceneData(EnFish* pthis) {
    Actor* thisx = &pthis->actor;

    if (D_80A17010 == NULL) {
        D_80A17010 = thisx;
        Actor_SetScale(thisx, 0.01f);
        thisx->draw = EnFish_Draw;
        thisx->shape.rot.x = 0;
        thisx->shape.rot.y = -0x6410;
        thisx->shape.rot.z = 0x4000;
        thisx->shape.yOffset = 600.0f;
        D_80A17014 = 10.0f;
        D_80A17018 = 0.0f;
        thisx->flags |= ACTOR_FLAG_4;
        EnFish_SetOutOfWaterAnimation(pthis);
    }
}

void EnFish_ClearCutsceneData(EnFish* pthis) {
    D_80A17010 = NULL;
    D_80A17014 = 0.0f;
    D_80A17018 = 0.0f;
}

void EnFish_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFish* pthis = (EnFish*)thisx;
    s16 params = pthis->actor.params;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gFishSkel, &gFishInWaterAnim, pthis->jointTable, pthis->morphTable,
                       7);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    pthis->actor.colChkInfo.mass = 50;
    pthis->slowPhase = Rand_ZeroOne() * (0xFFFF + 0.5f);
    pthis->fastPhase = Rand_ZeroOne() * (0xFFFF + 0.5f);

    if (params == FISH_DROPPED) {
        pthis->actor.flags |= ACTOR_FLAG_4;
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 8.0f);
        EnFish_Dropped_SetupFall(pthis);
    } else if (params == FISH_SWIMMING_UNIQUE) {
        EnFish_Unique_SetupSwimIdle(pthis);
    } else {
        EnFish_Respawning_SetupSlowDown(pthis);
    }
}

void EnFish_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnFish* pthis = (EnFish*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnFish_SetYOffset(EnFish* pthis) {
    pthis->actor.shape.yOffset += (Math_SinS(pthis->slowPhase) * 10.0f + Math_SinS(pthis->fastPhase) * 5.0f);
    pthis->actor.shape.yOffset = CLAMP(pthis->actor.shape.yOffset, -200.0f, 200.0f);
}

s32 EnFish_InBottleRange(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f sp1C;

    if (pthis->actor.xzDistToPlayer < 32.0f) {
        sp1C.x = (Math_SinS(pthis->actor.yawTowardsPlayer + 0x8000) * 16.0f) + player->actor.world.pos.x;
        sp1C.y = player->actor.world.pos.y;
        sp1C.z = (Math_CosS(pthis->actor.yawTowardsPlayer + 0x8000) * 16.0f) + player->actor.world.pos.z;

        //! @bug: pthis check is superfluous: it is automatically satisfied if the coarse check is satisfied. It may have
        //! been intended to check the actor is in front of Player, but yawTowardsPlayer does not depend on Player's
        //! world rotation.
        if (EnFish_XZDistanceSquared(&sp1C, &pthis->actor.world.pos) <= SQ(20.0f)) {
            return true;
        }
    }

    return false;
}

s32 EnFish_CheckXZDistanceToPlayer(EnFish* pthis, GlobalContext* globalCtx) {
    return (pthis->actor.xzDistToPlayer < 60.0f);
}

// Respawning type functions

void EnFish_Respawning_SetupSlowDown(EnFish* pthis) {
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    pthis->timer = Rand_S16Offset(5, 35);
    pthis->unk_250 = 0;
    EnFish_SetInWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Respawning_SlowDown;
}

void EnFish_Respawning_SlowDown(EnFish* pthis, GlobalContext* globalCtx) {
    EnFish_SetYOffset(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.05f, 0.3f, 0.0f);
    pthis->skelAnime.playSpeed = CLAMP_MAX(pthis->actor.speedXZ * 1.4f + 0.8f, 2.0f);
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->timer <= 0) {
        EnFish_Respawning_SetupFollowChild(pthis);
    } else if (&pthis->actor == pthis->actor.child) {
        EnFish_Respawning_SetupApproachPlayer(pthis);
    } else if (EnFish_CheckXZDistanceToPlayer(pthis, globalCtx)) {
        EnFish_Respawning_SetupFleePlayer(pthis);
    }
}

// The three following actionfunctions also turn the yaw to home if the fish is too far from it.

void EnFish_Respawning_SetupFollowChild(EnFish* pthis) {
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    pthis->timer = Rand_S16Offset(15, 45);
    pthis->unk_250 = 0;
    EnFish_SetInWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Respawning_FollowChild;
}

void EnFish_Respawning_FollowChild(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;

    EnFish_SetYOffset(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 1.8f, 0.08f, 0.4f, 0.0f);

    if ((EnFish_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > SQ(80.0f)) || (pthis->timer < 4)) {
        Math_StepToAngleS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos),
                          3000);
    } else if ((pthis->actor.child != NULL) && (&pthis->actor != pthis->actor.child)) {
        Math_StepToAngleS(&pthis->actor.world.rot.y,
                          Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.child->world.pos), 3000);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->skelAnime.playSpeed = CLAMP_MAX(pthis->actor.speedXZ * 1.5f + 0.8f, 4.0f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        EnFish_Respawning_SetupSlowDown(pthis);
    } else if (&pthis->actor == pthis->actor.child) {
        EnFish_Respawning_SetupApproachPlayer(pthis);
    } else if (EnFish_CheckXZDistanceToPlayer(pthis, globalCtx)) {
        EnFish_Respawning_SetupFleePlayer(pthis);
    }
}

void EnFish_Respawning_SetupFleePlayer(EnFish* pthis) {
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    pthis->timer = Rand_S16Offset(10, 40);
    pthis->unk_250 = 0;
    EnFish_SetInWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Respawning_FleePlayer;
}

void EnFish_Respawning_FleePlayer(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 pad2;
    const auto& frames = globalCtx->state.frames;
    s16 yaw;
    s16 playerClose;

    EnFish_SetYOffset(pthis);
    playerClose = EnFish_CheckXZDistanceToPlayer(pthis, globalCtx);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 4.2f, 0.08f, 1.4f, 0.0f);

    if (EnFish_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > SQ(160.0f)) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        Math_StepToAngleS(&pthis->actor.world.rot.y, yaw, 3000);
    } else if ((pthis->actor.child != NULL) && (&pthis->actor != pthis->actor.child)) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.child->world.pos);
        Math_StepToAngleS(&pthis->actor.world.rot.y, yaw, 2000);
    } else if (playerClose) {
        yaw = pthis->actor.yawTowardsPlayer + 0x8000;

        if (frames & 0x10) {
            if (frames & 0x20) {
                yaw += 0x2000;
            }
        } else {
            if (frames & 0x20) {
                yaw -= 0x2000;
            }
        }
        if (globalCtx) {}
        Math_StepToAngleS(&pthis->actor.world.rot.y, yaw, 2000);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->skelAnime.playSpeed = CLAMP_MAX(pthis->actor.speedXZ * 1.5f + 0.8f, 4.0f);

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->timer <= 0) || !playerClose) {
        EnFish_Respawning_SetupSlowDown(pthis);
    } else if (&pthis->actor == pthis->actor.child) {
        EnFish_Respawning_SetupApproachPlayer(pthis);
    }
}

void EnFish_Respawning_SetupApproachPlayer(EnFish* pthis) {
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    EnFish_SetInWaterAnimation(pthis);
    pthis->timer = Rand_S16Offset(10, 40);
    pthis->unk_250 = 0;
    pthis->actionFunc = EnFish_Respawning_ApproachPlayer;
}

void EnFish_Respawning_ApproachPlayer(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad2;
    Vec3f sp38;
    s16 yaw;
    s16 temp_a0_2;

    EnFish_SetYOffset(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 1.8f, 0.1f, 0.5f, 0.0f);

    if (EnFish_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > SQ(80.0f)) {
        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        Math_StepToAngleS(&pthis->actor.world.rot.y, yaw, 3000);
    } else {
        if (globalCtx->state.frames & 0x40) {
            temp_a0_2 = (pthis->actor.yawTowardsPlayer + 0x9000);
        } else {
            temp_a0_2 = (pthis->actor.yawTowardsPlayer + 0x7000);
        }

        sp38.x = player->actor.world.pos.x + (Math_SinS(temp_a0_2) * 20.0f);
        sp38.y = player->actor.world.pos.y;
        sp38.z = player->actor.world.pos.z + (Math_CosS(temp_a0_2) * 20.0f);

        yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &sp38);
        Math_StepToAngleS(&pthis->actor.world.rot.y, yaw, 3000);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->skelAnime.playSpeed = CLAMP_MAX((pthis->actor.speedXZ * 1.5f) + 0.8f, 4.0f);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        EnFish_Respawning_SetupSlowDown(pthis);
    }
}

// Dropped type functions

void EnFish_Dropped_SetupFall(EnFish* pthis) {
    pthis->actor.gravity = -1.0f;
    pthis->actor.minVelocityY = -10.0f;
    pthis->actor.shape.yOffset = 0.0f;
    EnFish_SetOutOfWaterAnimation(pthis);
    pthis->unk_250 = 5;
    pthis->actionFunc = EnFish_Dropped_Fall;
    pthis->timer = 300;
}

void EnFish_Dropped_Fall(EnFish* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.1f, 0.1f, 0.0f);
    Math_StepToAngleS(&pthis->actor.world.rot.x, 0x4000, 100);
    Math_StepToAngleS(&pthis->actor.world.rot.z, -0x4000, 100);
    pthis->actor.shape.rot.x = pthis->actor.world.rot.x;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    pthis->actor.shape.rot.z = pthis->actor.world.rot.z;
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.bgCheckFlags & 1) { // On floor
        pthis->timer = 400;
        EnFish_Dropped_SetupFlopOnGround(pthis);
    } else if (pthis->actor.bgCheckFlags & 0x20) { // In water
        EnFish_Dropped_SetupSwimAway(pthis);
    } else if ((pthis->timer <= 0) && (pthis->actor.params == FISH_DROPPED) &&
               (pthis->actor.floorHeight < BGCHECK_Y_MIN + 10.0f)) {
        osSyncPrintf(VT_COL(YELLOW, BLACK));
        // "BG missing? Running Actor_delete"
        osSyncPrintf("BG 抜け？ Actor_delete します(%s %d)\n", "../z_en_sakana.c", 822);
        osSyncPrintf(VT_RST);
        Actor_Kill(&pthis->actor);
    }
}

/**
 * If the fish is on a floor, pthis function is looped back to by EnFish_Dropped_FlopOnGround to set a new flopping
 * height and whether the sound should play again.
 */
void EnFish_Dropped_SetupFlopOnGround(EnFish* pthis) {
    s32 pad;
    f32 randomFloat;
    s32 playSound;

    pthis->actor.gravity = -1.0f;
    pthis->actor.minVelocityY = -10.0f;
    randomFloat = Rand_ZeroOne();

    if (randomFloat < 0.1f) {
        pthis->actor.velocity.y = (Rand_ZeroOne() * 3.0f) + 2.5f;
        playSound = true;
    } else if (randomFloat < 0.2f) {
        pthis->actor.velocity.y = (Rand_ZeroOne() * 1.2f) + 0.2f;
        playSound = true;
    } else {
        pthis->actor.velocity.y = 0.0f;

        if (Rand_ZeroOne() < 0.2f) {
            playSound = true;
        } else {
            playSound = false;
        }
    }

    pthis->actor.shape.yOffset = 300.0f;
    EnFish_SetOutOfWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Dropped_FlopOnGround;
    pthis->unk_250 = 5;

    if (playSound && (pthis->actor.draw != NULL)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FISH_LEAP);
    }
}

void EnFish_Dropped_FlopOnGround(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    const auto& frames = globalCtx->state.frames;
    s16 targetXRot;

    Math_SmoothStepToF(&pthis->actor.speedXZ, Rand_ZeroOne() * 0.2f, 0.1f, 0.1f, 0.0f);

    targetXRot = (s16)((((frames.whole() >> 5) & 2) | ((frames.whole() >> 2) & 1)) << 0xB) * 0.3f;

    if (frames & 4) {
        targetXRot = -targetXRot;
    }

    Math_StepToAngleS(&pthis->actor.world.rot.x, targetXRot, 4000);
    Math_StepToAngleS(&pthis->actor.world.rot.z, 0x4000, 1000);
    pthis->actor.world.rot.y +=
        (s16)(((Math_SinS(pthis->slowPhase) * 2000.0f) + (Math_SinS(pthis->fastPhase) * 1000.0f)) * Rand_ZeroOne());
    pthis->actor.shape.rot = pthis->actor.world.rot;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->timer <= 60) {
        // Blink when about to disappear
        if (frames & 4) {
            pthis->actor.draw = EnFish_Draw;
        } else {
            pthis->actor.draw = NULL;
        }
    } else if (pthis->actor.bgCheckFlags & 0x20) { // In water
        EnFish_Dropped_SetupSwimAway(pthis);
    } else if (pthis->actor.bgCheckFlags & 1) { // On floor
        EnFish_Dropped_SetupFlopOnGround(pthis);
    }
}

void EnFish_Dropped_SetupSwimAway(EnFish* pthis) {
    pthis->actor.home.pos = pthis->actor.world.pos;
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->timer = 200;
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    pthis->actor.shape.yOffset = 0.0f;
    EnFish_SetInWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Dropped_SwimAway;
    pthis->unk_250 = 5;
}

void EnFish_Dropped_SwimAway(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 2.8f, 0.1f, 0.4f, 0.0f);

    // If touching wall or not in water, turn back and slow down for one frame.
    if ((pthis->actor.bgCheckFlags & 8) || !(pthis->actor.bgCheckFlags & 0x20)) {
        pthis->actor.home.rot.y = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        pthis->actor.speedXZ *= 0.5f;
    }

    Math_StepToAngleS(&pthis->actor.world.rot.x, 0, 1500);
    Math_StepToAngleS(&pthis->actor.world.rot.y, pthis->actor.home.rot.y, 3000);
    Math_StepToAngleS(&pthis->actor.world.rot.z, 0, 1000);

    pthis->actor.shape.rot = pthis->actor.world.rot;

    // Raise if on a floor.
    if (pthis->actor.bgCheckFlags & 1) {
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 4.0f, 2.0f);
    } else {
        Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 10.0f, 2.0f);
    }

    // Shrink when close to disappearing.
    if (pthis->timer < 100) {
        Actor_SetScale(&pthis->actor, pthis->actor.scale.x * 0.982f);
    }

    pthis->skelAnime.playSpeed = CLAMP_MAX((pthis->actor.speedXZ * 1.5f) + 1.0f, 4.0f);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

// Unique type functions

void EnFish_Unique_SetupSwimIdle(EnFish* pthis) {
    pthis->actor.gravity = 0.0f;
    pthis->actor.minVelocityY = 0.0f;
    pthis->timer = Rand_S16Offset(5, 35);
    pthis->unk_250 = 0;
    EnFish_SetInWaterAnimation(pthis);
    pthis->actionFunc = EnFish_Unique_SwimIdle;
}

void EnFish_Unique_SwimIdle(EnFish* pthis, GlobalContext* globalCtx) {
    static f32 speedStopping[] = { 0.0f, 0.04f, 0.09f };
    static f32 speedMoving[] = { 0.5f, 0.1f, 0.15f };
    f32 playSpeed;
    u32 frames = globalCtx->gameplayFrames;
    f32* speed;
    s32 pad2;
    f32 extraPlaySpeed;
    s32 pad3;

    if (pthis->actor.xzDistToPlayer < 60.0f) {
        if (pthis->timer < 12) {
            speed = speedMoving;
        } else {
            speed = speedStopping;
        }
    } else {
        if (pthis->timer < 4) {
            speed = speedMoving;
        } else {
            speed = speedStopping;
        }
    }

    EnFish_SetYOffset(pthis);
    Math_SmoothStepToF(&pthis->actor.speedXZ, speed[0], speed[1], speed[2], 0.0f);

    extraPlaySpeed = 0.0f;

    if ((EnFish_XZDistanceSquared(&pthis->actor.world.pos, &pthis->actor.home.pos) > SQ(15.0f))) {
        if (!Math_ScaledStepToS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos),
                                200)) {
            extraPlaySpeed = 0.5f;
        }
    } else if ((pthis->timer < 4) && !Math_ScaledStepToS(&pthis->actor.world.rot.y, frames * 0x80, 100)) {
        extraPlaySpeed = 0.5f;
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    playSpeed = (pthis->actor.speedXZ * 1.2f) + 0.2f + extraPlaySpeed;
    pthis->skelAnime.playSpeed = CLAMP(playSpeed, 1.5f, 0.5);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer <= 0) {
        pthis->timer = Rand_S16Offset(5, 80);
    }
}

// Cutscene functions

void EnFish_Cutscene_FlopOnGround(EnFish* pthis, GlobalContext* globalCtx) {
    f32 sp24 = Math_SinS(pthis->slowPhase);
    f32 sp20 = Math_SinS(pthis->fastPhase);

    D_80A17014 += D_80A17018;

    if (D_80A17014 <= 1.0f) {
        D_80A17014 = 1.0f;

        if (Rand_ZeroOne() < 0.1f) {
            D_80A17018 = (Rand_ZeroOne() * 3.0f) + 2.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FISH_LEAP);
        } else {
            D_80A17018 = 0.0f;
        }
    } else {
        D_80A17018 -= 0.4f;
    }

    pthis->skelAnime.playSpeed = ((sp24 + sp20) * 0.5f) + 2.0f;
    SkelAnime_Update(&pthis->skelAnime);
}

void EnFish_Cutscene_WiggleFlyingThroughAir(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 sp28 = Math_SinS(pthis->slowPhase);
    f32 sp24 = Math_SinS(pthis->fastPhase);

    pthis->actor.shape.rot.x -= 500;
    pthis->actor.shape.rot.z += 100;
    Math_StepToF(&D_80A17014, 0.0f, 1.0f);
    pthis->skelAnime.playSpeed = ((sp28 + sp24) * 0.5f) + 2.0f;
    SkelAnime_Update(&pthis->skelAnime);
}

void EnFish_UpdateCutscene(EnFish* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    CsCmdActorAction* csAction = globalCtx->csCtx.npcActions[1];
    Vec3f startPos;
    Vec3f endPos;
    f32 progress;
    s32 bgId;

    if (csAction == NULL) {
        // "Warning : DEMO ended without dousa (action) 3 termination being called"
        osSyncPrintf("Warning : dousa 3 消滅 が呼ばれずにデモが終了した(%s %d)(arg_data 0x%04x)\n", "../z_en_sakana.c",
                     1169, pthis->actor.params);
        EnFish_ClearCutsceneData(pthis);
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->slowPhase += 0x111;
    pthis->fastPhase += 0x500;

    switch (csAction->action) {
        case 1:
            EnFish_Cutscene_FlopOnGround(pthis, globalCtx);
            break;
        case 2:
            EnFish_Cutscene_WiggleFlyingThroughAir(pthis, globalCtx);
            break;
        case 3:
            // "DEMO fish termination"
            osSyncPrintf("デモ魚消滅\n");
            EnFish_ClearCutsceneData(pthis);
            Actor_Kill(&pthis->actor);
            return;
        default:
            // "Improper DEMO action"
            osSyncPrintf("不正なデモ動作(%s %d)(arg_data 0x%04x)\n", "../z_en_sakana.c", 1200, pthis->actor.params);
            break;
    }

    startPos.x = csAction->startPos.x;
    startPos.y = csAction->startPos.y;
    startPos.z = csAction->startPos.z;
    endPos.x = csAction->endPos.x;
    endPos.y = csAction->endPos.y;
    endPos.z = csAction->endPos.z;

    progress = Environment_LerpWeight(csAction->endFrame, csAction->startFrame, globalCtx->csCtx.frames);

    pthis->actor.world.pos.x = (endPos.x - startPos.x) * progress + startPos.x;
    pthis->actor.world.pos.y = (endPos.y - startPos.y) * progress + startPos.y + D_80A17014;
    pthis->actor.world.pos.z = (endPos.z - startPos.z) * progress + startPos.z;

    pthis->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                          &pthis->actor, &pthis->actor.world.pos);
}

// Update functions and Draw

void EnFish_OrdinaryUpdate(EnFish* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
    }

    pthis->slowPhase += 0x111;
    pthis->fastPhase += 0x500;

    if ((pthis->actor.child != NULL) && (pthis->actor.child->update == NULL) && (&pthis->actor != pthis->actor.child)) {
        pthis->actor.child = NULL;
    }

    if ((pthis->actionFunc == NULL) || (pthis->actionFunc(pthis, globalCtx), (pthis->actor.update != NULL))) {
        Actor_MoveForward(&pthis->actor);

        if (pthis->unk_250 != 0) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 17.5f, 4.0f, 0.0f, pthis->unk_250);
        }

        if (pthis->actor.xzDistToPlayer < 70.0f) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        Actor_SetFocus(&pthis->actor, pthis->actor.shape.yOffset * 0.01f);

        if (Actor_HasParent(&pthis->actor, globalCtx)) {
            pthis->actor.parent = NULL;

            if (pthis->actor.params == FISH_DROPPED) {
                Actor_Kill(&pthis->actor);
                return;
            }

            EnFish_BeginRespawn(pthis);
        } else if (EnFish_InBottleRange(pthis, globalCtx)) {
            // GI_MAX in pthis case allows the player to catch the actor in a bottle
            func_8002F434(&pthis->actor, globalCtx, GI_MAX, 80.0f, 20.0f);
        }
    }
}

void EnFish_RespawningUpdate(EnFish* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params == FISH_SWIMMING_UNIQUE) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if ((pthis->actor.child != NULL) && (pthis->actor.child->update == NULL) && (&pthis->actor != pthis->actor.child)) {
        pthis->actor.child = NULL;
    }

    if ((pthis->actionFunc == NULL) || (pthis->actionFunc(pthis, globalCtx), (pthis->actor.update != NULL))) {
        Actor_MoveForward(&pthis->actor);

        if (pthis->respawnTimer == 20) {
            pthis->actor.draw = EnFish_Draw;
        } else if (pthis->respawnTimer == 0) {
            Actor_SetScale(&pthis->actor, 0.01f);
        } else if (pthis->respawnTimer < 20) {
            Actor_SetScale(&pthis->actor, CLAMP_MAX(pthis->actor.scale.x + 0.001f, 0.01f));
        }
    }
}

void EnFish_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFish* pthis = (EnFish*)thisx;

    if ((D_80A17010 == NULL) && (pthis->actor.params == FISH_DROPPED) && (globalCtx->csCtx.state != 0) &&
        (globalCtx->csCtx.npcActions[1] != NULL)) {
        EnFish_SetCutsceneData(pthis);
    }

    if ((D_80A17010 != NULL) && (&pthis->actor == D_80A17010)) {
        EnFish_UpdateCutscene(pthis, globalCtx);
    } else if (pthis->respawnTimer > 0) {
        pthis->respawnTimer--;
        EnFish_RespawningUpdate(pthis, globalCtx);
    } else {
        EnFish_OrdinaryUpdate(pthis, globalCtx);
    }
}

void EnFish_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFish* pthis = (EnFish*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, NULL);
    Collider_UpdateSpheres(0, &pthis->collider);
}

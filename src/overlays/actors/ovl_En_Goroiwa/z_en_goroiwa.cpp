#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GOROIWA_Z_EN_GOROIWA_C
#include "actor_common.h"
/*
 * File: z_en_goroiwa.c
 * Overlay: ovl_En_Goroiwa
 * Description: Rolling boulders
 */

#include "z_en_goroiwa.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_goroiwa/object_goroiwa.h"
#include "vt.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_quake.h"

#define FLAGS ACTOR_FLAG_4

typedef s32 (*EnGoroiwaUnkFunc1)(EnGoroiwa* pthis, GlobalContext* globalCtx);
typedef void (*EnGoroiwaUnkFunc2)(EnGoroiwa* pthis);

#define ENGOROIWA_ENABLE_AT (1 << 0)
#define ENGOROIWA_ENABLE_OC (1 << 1)
#define ENGOROIWA_PLAYER_IN_THE_WAY (1 << 2)
#define ENGOROIWA_RETAIN_ROT_SPEED (1 << 3)
#define ENGOROIWA_IN_WATER (1 << 4)

#define ENGOROIWA_LOOPMODE_ONEWAY 0
/* same as ENGOROIWA_LOOPMODE_ONEWAY but display rock fragments as if the boulder broke at the end of the path*/
#define ENGOROIWA_LOOPMODE_ONEWAY_BREAK 1
#define ENGOROIWA_LOOPMODE_ROUNDTRIP 3

void EnGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnGoroiwa_SetupRoll(EnGoroiwa* pthis);
void EnGoroiwa_Roll(EnGoroiwa* pthis, GlobalContext* globalCtx);
void EnGoroiwa_SetupMoveAndFallToGround(EnGoroiwa* pthis);
void EnGoroiwa_MoveAndFallToGround(EnGoroiwa* pthis, GlobalContext* globalCtx);
void EnGoroiwa_SetupWait(EnGoroiwa* pthis);
void EnGoroiwa_Wait(EnGoroiwa* pthis, GlobalContext* globalCtx);
void EnGoroiwa_SetupMoveUp(EnGoroiwa* pthis);
void EnGoroiwa_MoveUp(EnGoroiwa* pthis, GlobalContext* globalCtx);
void EnGoroiwa_SetupMoveDown(EnGoroiwa* pthis);
void EnGoroiwa_MoveDown(EnGoroiwa* pthis, GlobalContext* globalCtx);

static f32 yOffsets_54[] = { 0.0f, 59.5f };

static Vec3f velocity_68 = { 0.0f, 0.0f, 0.0f };

static Vec3f accel_68 = { 0.0f, 0.3f, 0.0f };

static Vec3f unitY_74 = { 0.0f, 1.0f, 0.0f };

static f32 yOffsets_76[] = { 0.0f, 59.5f };

static f32 yOffsets_78[] = { 0.0f, 595.0f };

static EnGoroiwaUnkFunc2 onHitSetupFuncs_81[] = { EnGoroiwa_SetupWait, EnGoroiwa_SetupMoveAndFallToGround };

static s16 waitDurations_84[] = { 20, 6 };


ActorInit En_Goroiwa_InitVars = {
    ACTOR_EN_GOROIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GOROIWA,
    sizeof(EnGoroiwa),
    (ActorFunc)EnGoroiwa_Init,
    (ActorFunc)EnGoroiwa_Destroy,
    (ActorFunc)EnGoroiwa_Update,
    (ActorFunc)EnGoroiwa_Draw,
    (ActorFunc)EnGoroiwa_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x00, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 58 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 12, 60, MASS_HEAVY };

static f32 sUnused[] = { 10.0f, 9.2f };

void EnGoroiwa_UpdateCollider(EnGoroiwa* pthis) {
    Sphere16* worldSphere = &pthis->collider.elements[0].dim.worldSphere;

    worldSphere->center.x = pthis->actor.world.pos.x;
    worldSphere->center.y = pthis->actor.world.pos.y + yOffsets_54[(pthis->actor.params >> 10) & 1];
    worldSphere->center.z = pthis->actor.world.pos.z;
}

void EnGoroiwa_InitCollider(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);
    EnGoroiwa_UpdateCollider(pthis);
    pthis->collider.elements[0].dim.worldSphere.radius = 58;
}

void EnGoroiwa_UpdateFlags(EnGoroiwa* pthis, u8 setFlags) {
    pthis->stateFlags &= ~(ENGOROIWA_ENABLE_AT | ENGOROIWA_ENABLE_OC);
    pthis->stateFlags |= setFlags;
}

s32 EnGoroiwa_Vec3fNormalize(Vec3f* ret, Vec3f* a) {
    f32 magnitude = Math3D_Vec3fMagnitude(a);
    f32 scale;

    if (magnitude < 0.001f) {
        return false;
    }

    scale = 1.0f / magnitude;

    ret->x = a->x * scale;
    ret->y = a->y * scale;
    ret->z = a->z * scale;

    return true;
}

void EnGoroiwa_SetSpeed(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_SPOT04) {
        pthis->isInKokiri = true;
        R_EN_GOROIWA_SPEED = 920;
    } else {
        pthis->isInKokiri = false;
        R_EN_GOROIWA_SPEED = 1000;
    }
}

void EnGoroiwa_FaceNextWaypoint(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    Vec3s* nextPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;
    Vec3f nextPosF;

    nextPosF.x = nextPos->x;
    nextPosF.y = nextPos->y;
    nextPosF.z = nextPos->z;

    pthis->actor.world.rot.y = Math_Vec3f_Yaw(&pthis->actor.world.pos, &nextPosF);
}

void EnGoroiwa_GetPrevWaypointDiff(EnGoroiwa* pthis, GlobalContext* globalCtx, Vec3f* dest) {
    s16 loopMode = (pthis->actor.params >> 8) & 3;
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    s16 prevWaypoint = pthis->currentWaypoint - pthis->pathDirection;
    Vec3s* prevPointPos;
    Vec3s* currentPointPos;

    if (prevWaypoint < 0) {
        if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY || loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK) {
            prevWaypoint = pthis->endWaypoint;
        } else if (loopMode == ENGOROIWA_LOOPMODE_ROUNDTRIP) {
            prevWaypoint = 1;
        }
    } else if (prevWaypoint > pthis->endWaypoint) {
        if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY || loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK) {
            prevWaypoint = 0;
        } else if (loopMode == ENGOROIWA_LOOPMODE_ROUNDTRIP) {
            prevWaypoint = pthis->endWaypoint - 1;
        }
    }

    currentPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->currentWaypoint;
    prevPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + prevWaypoint;
    dest->x = currentPointPos->x - prevPointPos->x;
    dest->y = currentPointPos->x - prevPointPos->y;
    dest->z = currentPointPos->x - prevPointPos->z;
}

void EnGoroiw_CheckEndOfPath(EnGoroiwa* pthis) {
    s16 loopMode = (pthis->actor.params >> 8) & 3;

    if (pthis->nextWaypoint < 0) {
        if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY || loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK) {
            pthis->currentWaypoint = pthis->endWaypoint;
            pthis->nextWaypoint = pthis->endWaypoint - 1;
            pthis->pathDirection = -1;
        } else if (loopMode == ENGOROIWA_LOOPMODE_ROUNDTRIP) {
            pthis->currentWaypoint = 0;
            pthis->nextWaypoint = 1;
            pthis->pathDirection = 1;
        }
    } else if (pthis->nextWaypoint > pthis->endWaypoint) {
        if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY || loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK) {
            pthis->currentWaypoint = 0;
            pthis->nextWaypoint = 1;
            pthis->pathDirection = 1;
        } else if (loopMode == ENGOROIWA_LOOPMODE_ROUNDTRIP) {
            pthis->currentWaypoint = pthis->endWaypoint;
            pthis->nextWaypoint = pthis->endWaypoint - 1;
            pthis->pathDirection = -1;
        }
    }
}

void EnGoroiwa_SetNextWaypoint(EnGoroiwa* pthis) {
    pthis->currentWaypoint = pthis->nextWaypoint;
    pthis->nextWaypoint += pthis->pathDirection;
    EnGoroiw_CheckEndOfPath(pthis);
}

void EnGoroiwa_ReverseDirection(EnGoroiwa* pthis) {
    pthis->pathDirection *= -1;
    pthis->currentWaypoint = pthis->nextWaypoint;
    pthis->nextWaypoint += pthis->pathDirection;
}

void EnGoroiwa_InitPath(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    pthis->endWaypoint = globalCtx->setupPathList[pthis->actor.params & 0xFF].count - 1;
    pthis->currentWaypoint = 0;
    pthis->nextWaypoint = 1;
    pthis->pathDirection = 1;
}

void EnGoroiwa_TeleportToWaypoint(EnGoroiwa* pthis, GlobalContext* globalCtx, s32 waypoint) {
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    Vec3s* pointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + waypoint;

    pthis->actor.world.pos.x = pointPos->x;
    pthis->actor.world.pos.y = pointPos->y;
    pthis->actor.world.pos.z = pointPos->z;
}

void EnGoroiwa_InitRotation(EnGoroiwa* pthis) {
    pthis->prevUnitRollAxis.x = 1.0f;
    pthis->rollRotSpeed = 1.0f;
}

s32 EnGoroiwa_GetAscendDirection(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    Vec3s* nextPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;
    Vec3s* currentPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->currentWaypoint;

    if (nextPointPos->x == currentPointPos->x && nextPointPos->z == currentPointPos->z) {
        if (nextPointPos->y == currentPointPos->y) {
            // "Error: Invalid path data (points overlap)"
            osSyncPrintf("Error : レールデータ不正(点が重なっている)");
            osSyncPrintf("(%s %d)(arg_data 0x%04x)\n", "../z_en_gr.c", 559, pthis->actor.params);
        }

        if (nextPointPos->y > currentPointPos->y) {
            return 1;
        } else {
            return -1;
        }
    }

    return 0;
}

void EnGoroiwa_SpawnDust(GlobalContext* globalCtx, Vec3f* pos) {
    Vec3f randPos;
    s32 i;
    s16 angle = 0;

    for (i = 0; i < 8; i++) {
        angle += 0x4E20;
        randPos.x = pos->x + (47.0f * (Rand_ZeroOne() * 0.5f + 0.5f)) * Math_SinS(angle);
        randPos.y = pos->y + (Rand_ZeroOne() - 0.5f) * 40.0f;
        randPos.z = pos->z + ((47.0f * (Rand_ZeroOne() * 0.5f + 0.5f))) * Math_CosS(angle);
        func_800286CC(globalCtx, &randPos, &velocity_68, &accel_68, (s16)(Rand_ZeroOne() * 30.0f) + 100, 80);
        func_800286CC(globalCtx, &randPos, &velocity_68, &accel_68, (s16)(Rand_ZeroOne() * 20.0f) + 80, 80);
    }
}

void EnGoroiwa_SpawnWaterEffects(GlobalContext* globalCtx, Vec3f* contactPos) {
    Vec3f splashPos;
    s32 i;
    s16 angle = 0;

    for (i = 0; i < 11; i++) {
        angle += 0x1746;
        splashPos.x = contactPos->x + (Math_SinS(angle) * 55.0f);
        splashPos.y = contactPos->y;
        splashPos.z = contactPos->z + (Math_CosS(angle) * 55.0f);
        EffectSsGSplash_Spawn(globalCtx, &splashPos, 0, 0, 0, 350);
    }

    EffectSsGRipple_Spawn(globalCtx, contactPos, 300, 700, 0);
    EffectSsGRipple_Spawn(globalCtx, contactPos, 500, 900, 4);
    EffectSsGRipple_Spawn(globalCtx, contactPos, 500, 1300, 8);
}

s32 EnGoroiwa_MoveAndFall(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    Path* path;
    s32 result;
    s32 pad;
    Vec3s* nextPointPos;

    Math_StepToF(&pthis->actor.speedXZ, R_EN_GOROIWA_SPEED * 0.01f, 0.3f);
    func_8002D868(&pthis->actor);
    path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    nextPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;
    result = true;
    result &= Math_StepToF(&pthis->actor.world.pos.x, nextPointPos->x, fabsf(pthis->actor.velocity.x));
    result &= Math_StepToF(&pthis->actor.world.pos.z, nextPointPos->z, fabsf(pthis->actor.velocity.z));
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
    return result;
}

s32 EnGoroiwa_Move(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    s32 pad;
    Vec3s* nextPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;
    Vec3s* currentPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->currentWaypoint;
    s32 nextPointReached;
    Vec3f posDiff;
    Vec3f nextPointPosF;

    nextPointPosF.x = nextPointPos->x;
    nextPointPosF.y = nextPointPos->y;
    nextPointPosF.z = nextPointPos->z;
    Math_StepToF(&pthis->actor.speedXZ, R_EN_GOROIWA_SPEED * 0.01f, 0.3f);
    if (Math3D_Vec3fDistSq(&nextPointPosF, &pthis->actor.world.pos) < SQ(5.0f)) {
        Math_Vec3f_Diff(&nextPointPosF, &pthis->actor.world.pos, &posDiff);
    } else {
        posDiff.x = nextPointPosF.x - currentPointPos->x;
        posDiff.y = nextPointPosF.y - currentPointPos->y;
        posDiff.z = nextPointPosF.z - currentPointPos->z;
    }
    EnGoroiwa_Vec3fNormalize(&pthis->actor.velocity, &posDiff);
    pthis->actor.velocity.x *= pthis->actor.speedXZ;
    pthis->actor.velocity.y *= pthis->actor.speedXZ;
    pthis->actor.velocity.z *= pthis->actor.speedXZ;
    nextPointReached = true;
    nextPointReached &= Math_StepToF(&pthis->actor.world.pos.x, nextPointPosF.x, fabsf(pthis->actor.velocity.x));
    nextPointReached &= Math_StepToF(&pthis->actor.world.pos.y, nextPointPosF.y, fabsf(pthis->actor.velocity.y));
    nextPointReached &= Math_StepToF(&pthis->actor.world.pos.z, nextPointPosF.z, fabsf(pthis->actor.velocity.z));
    return nextPointReached;
}

s32 EnGoroiwa_MoveUpToNextWaypoint(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    Vec3s* nextPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;

    Math_StepToF(&pthis->actor.velocity.y, (R_EN_GOROIWA_SPEED * 0.01f) * 0.5f, 0.18f);
    pthis->actor.world.pos.x = nextPointPos->x;
    pthis->actor.world.pos.z = nextPointPos->z;
    return Math_StepToF(&pthis->actor.world.pos.y, nextPointPos->y, fabsf(pthis->actor.velocity.y));
}

s32 EnGoroiwa_MoveDownToNextWaypoint(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Path* path = &globalCtx->setupPathList[pthis->actor.params & 0xFF];
    Vec3s* nextPointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->nextWaypoint;
    f32 nextPointY;
    f32 thisY;
    f32 yDistToFloor;
    s32 quakeIdx;
    CollisionPoly* floorPoly;
    Vec3f raycastFrom;
    f32 floorY;
    s32 pad2;
    s32 floorBgId;
    Vec3f dustPos;
    WaterBox* waterBox;
    f32 ySurface;
    Vec3f waterHitPos;

    nextPointY = nextPointPos->y;
    Math_StepToF(&pthis->actor.velocity.y, -14.0f, 1.0f);
    pthis->actor.world.pos.x = nextPointPos->x;
    pthis->actor.world.pos.z = nextPointPos->z;
    thisY = pthis->actor.world.pos.y;
    if (1) {}
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
    if (pthis->actor.velocity.y < 0.0f && pthis->actor.world.pos.y <= nextPointY) {
        if (pthis->bounceCount == 0) {
            if (pthis->actor.xzDistToPlayer < 600.0f) {
                quakeIdx = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
                Quake_SetSpeed(quakeIdx, -0x3CB0);
                Quake_SetQuakeValues(quakeIdx, 3, 0, 0, 0);
                Quake_SetCountdown(quakeIdx, 7);
            }
            pthis->rollRotSpeed = 0.0f;
            if (!(pthis->stateFlags & ENGOROIWA_IN_WATER)) {
                raycastFrom.x = pthis->actor.world.pos.x;
                raycastFrom.y = pthis->actor.world.pos.y + 50.0f;
                raycastFrom.z = pthis->actor.world.pos.z;
                floorY = BgCheck_EntityRaycastFloor5(globalCtx, &globalCtx->colCtx, &floorPoly, &floorBgId,
                                                     &pthis->actor, &raycastFrom);
                yDistToFloor = floorY - (pthis->actor.world.pos.y - 59.5f);
                if (fabsf(yDistToFloor) < 15.0f) {
                    dustPos.x = pthis->actor.world.pos.x;
                    dustPos.y = floorY + 10.0f;
                    dustPos.z = pthis->actor.world.pos.z;
                    EnGoroiwa_SpawnDust(globalCtx, &dustPos);
                }
            }
        }
        if (pthis->bounceCount >= 1) {
            return true;
        }
        pthis->bounceCount++;
        pthis->actor.velocity.y *= -0.3f;
        pthis->actor.world.pos.y = nextPointY - ((pthis->actor.world.pos.y - nextPointY) * 0.3f);
    }
    if (pthis->bounceCount == 0 &&
        WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                &ySurface, &waterBox) &&
        pthis->actor.world.pos.y <= ySurface) {
        pthis->stateFlags |= ENGOROIWA_IN_WATER;
        if (ySurface < thisY) {
            waterHitPos.x = pthis->actor.world.pos.x;
            waterHitPos.y = ySurface;
            waterHitPos.z = pthis->actor.world.pos.z;
            EnGoroiwa_SpawnWaterEffects(globalCtx, &waterHitPos);
            pthis->actor.velocity.y *= 0.2f;
        }
        if (pthis->actor.velocity.y < -8.0f) {
            pthis->actor.velocity.y = -8.0f;
        }
    }
    return false;
}

void EnGoroiwa_UpdateRotation(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f* rollAxisPtr;
    f32 rollAngleDiff;
    Vec3f rollAxis;
    Vec3f unitRollAxis;
    MtxF mtx;
    Vec3f unusedDiff;

    if (pthis->stateFlags & ENGOROIWA_RETAIN_ROT_SPEED) {
        rollAngleDiff = pthis->prevRollAngleDiff;
    } else {
        pthis->prevRollAngleDiff = Math3D_Vec3f_DistXYZ(&pthis->actor.world.pos, &pthis->actor.prevPos) * (1.0f / 59.5f);
        rollAngleDiff = pthis->prevRollAngleDiff;
    }
    rollAngleDiff *= pthis->rollRotSpeed;
    rollAxisPtr = &rollAxis;
    if (pthis->stateFlags & ENGOROIWA_RETAIN_ROT_SPEED) {
        /*
         * EnGoroiwa_GetPrevWaypointDiff has no side effects and its result goes unused,
         * its result was probably meant to be used instead of the actor's velocity in the
         * Math3D_Vec3f_Cross call.
         */
        EnGoroiwa_GetPrevWaypointDiff(pthis, globalCtx, &unusedDiff);
        Math3D_Vec3f_Cross(&unitY_74, &pthis->actor.velocity, rollAxisPtr);
    } else {
        Math3D_Vec3f_Cross(&unitY_74, &pthis->actor.velocity, rollAxisPtr);
    }

    if (EnGoroiwa_Vec3fNormalize(&unitRollAxis, rollAxisPtr)) {
        pthis->prevUnitRollAxis = unitRollAxis;
    } else {
        unitRollAxis = pthis->prevUnitRollAxis;
    }

    Matrix_RotateAxis(rollAngleDiff, &unitRollAxis, MTXMODE_NEW);
    Matrix_RotateY(pthis->actor.shape.rot.y * (2.0f * M_PI / 0x10000), MTXMODE_APPLY);
    Matrix_RotateX(pthis->actor.shape.rot.x * (2.0f * M_PI / 0x10000), MTXMODE_APPLY);
    Matrix_RotateZ(pthis->actor.shape.rot.z * (2.0f * M_PI / 0x10000), MTXMODE_APPLY);
    Matrix_Get(&mtx);
    Matrix_MtxFToYXZRotS(&mtx, &pthis->actor.shape.rot, 0);
}

void EnGoroiwa_NextWaypoint(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s16 loopMode = (pthis->actor.params >> 8) & 3;

    EnGoroiwa_SetNextWaypoint(pthis);

    if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY || loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK) {
        if (pthis->currentWaypoint == 0 || pthis->currentWaypoint == pthis->endWaypoint) {
            EnGoroiwa_TeleportToWaypoint(pthis, globalCtx, pthis->currentWaypoint);
        }
    }

    EnGoroiwa_FaceNextWaypoint(pthis, globalCtx);
}

void EnGoroiwa_SpawnFragments(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    s16 angle1;
    s16 angle2;
    s32 pad;
    Vec3f* thisPos = &pthis->actor.world.pos;
    Vec3f effectPos;
    Vec3f fragmentVelocity;
    f32 cos1;
    f32 sin1;
    f32 sin2;
    s16 yOffsetIdx = (pthis->actor.params >> 10) & 1;
    s32 i;

    for (i = 0, angle1 = 0; i < 16; i++, angle1 += 0x4E20) {
        sin1 = Math_SinS(angle1);
        cos1 = Math_CosS(angle1);
        angle2 = Rand_ZeroOne() * 0xFFFF;
        effectPos.x = Rand_ZeroOne() * 50.0f * sin1 * Math_SinS(angle2);
        sin2 = Math_SinS(angle2);
        effectPos.y = (Rand_ZeroOne() - 0.5f) * 100.0f * sin2 + yOffsets_76[yOffsetIdx];
        effectPos.z = Rand_ZeroOne() * 50.0f * cos1 * Math_SinS(angle2);
        fragmentVelocity.x = effectPos.x * 0.2f;
        fragmentVelocity.y = Rand_ZeroOne() * 15.0f + 2.0f;
        fragmentVelocity.z = effectPos.z * 0.2f;
        Math_Vec3f_Sum(&effectPos, thisPos, &effectPos);
        EffectSsKakera_Spawn(globalCtx, &effectPos, &fragmentVelocity, &effectPos, -340, 33, 28, 2, 0,
                             Rand_ZeroOne() * 7.0f + 1.0f, 1, 0, 70, KAKERA_COLOR_NONE, 1, gBoulderFragmentsDL);
    }

    effectPos.x = thisPos->x;
    effectPos.y = thisPos->y + yOffsets_76[yOffsetIdx];
    effectPos.z = thisPos->z;
    func_80033480(globalCtx, &effectPos, 80.0f, 5, 70, 110, 1);
    func_80033480(globalCtx, &effectPos, 90.0f, 5, 110, 160, 1);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -860, ICHAIN_CONTINUE), ICHAIN_F32_DIV1000(minVelocityY, -15000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),  ICHAIN_F32(uncullZoneForward, 1500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 150, ICHAIN_CONTINUE),  ICHAIN_F32(uncullZoneDownward, 1500, ICHAIN_STOP),
};

void EnGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGoroiwa* pthis = (EnGoroiwa*)thisx;
    s32 pathIdx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    EnGoroiwa_InitCollider(pthis, globalCtx);
    pathIdx = pthis->actor.params & 0xFF;
    if (pathIdx == 0xFF) {
        // "Error: Invalid arg_data"
        osSyncPrintf("Ｅｒｒｏｒ : arg_data が不正(%s %d)(arg_data 0x%04x)\n", "../z_en_gr.c", 1033,
                     pthis->actor.params);
        Actor_Kill(&pthis->actor);
        return;
    }
    if (globalCtx->setupPathList[pathIdx].count < 2) {
        // "Error: Invalid Path Data"
        osSyncPrintf("Ｅｒｒｏｒ : レールデータ が不正(%s %d)\n", "../z_en_gr.c", 1043);
        Actor_Kill(&pthis->actor);
        return;
    }
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    ActorShape_Init(&pthis->actor.shape, yOffsets_78[(pthis->actor.params >> 10) & 1], ActorShadow_DrawCircle, 9.4f);
    pthis->actor.shape.shadowAlpha = 200;
    EnGoroiwa_SetSpeed(pthis, globalCtx);
    EnGoroiwa_InitPath(pthis, globalCtx);
    EnGoroiwa_TeleportToWaypoint(pthis, globalCtx, 0);
    EnGoroiwa_InitRotation(pthis);
    EnGoroiwa_FaceNextWaypoint(pthis, globalCtx);
    EnGoroiwa_SetupRoll(pthis);
    // "(Goroiwa)"
    osSyncPrintf("(ごろ岩)(arg 0x%04x)(rail %d)(end %d)(bgc %d)(hit %d)\n", pthis->actor.params,
                 pthis->actor.params & 0xFF, (pthis->actor.params >> 8) & 3, (pthis->actor.params >> 10) & 1,
                 pthis->actor.home.rot.z & 1);
}

void EnGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnGoroiwa* pthis = (EnGoroiwa*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnGoroiwa_SetupRoll(EnGoroiwa* pthis) {
    pthis->actionFunc = EnGoroiwa_Roll;
    EnGoroiwa_UpdateFlags(pthis, ENGOROIWA_ENABLE_AT | ENGOROIWA_ENABLE_OC);
    pthis->rollRotSpeed = 1.0f;
}

static const EnGoroiwaUnkFunc1 moveFuncs_81[] = {EnGoroiwa_Move, EnGoroiwa_MoveAndFall};

void EnGoroiwa_Roll(EnGoroiwa* pthis, GlobalContext* globalCtx) {

    s32 ascendDirection;
    s16 yawDiff;
    s16 loopMode;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        pthis->stateFlags &= ~ENGOROIWA_PLAYER_IN_THE_WAY;
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y;
        if (yawDiff > -0x4000 && yawDiff < 0x4000) {
            pthis->stateFlags |= ENGOROIWA_PLAYER_IN_THE_WAY;
            if (((pthis->actor.params >> 10) & 1) || (pthis->actor.home.rot.z & 1) != 1) {
                EnGoroiwa_ReverseDirection(pthis);
                EnGoroiwa_FaceNextWaypoint(pthis, globalCtx);
            }
        }
        func_8002F6D4(globalCtx, &pthis->actor, 2.0f, pthis->actor.yawTowardsPlayer, 0.0f, 0);
        osSyncPrintf(VT_FGCOL(CYAN));
        osSyncPrintf("Player ぶっ飛ばし\n"); // "Player knocked down"
        osSyncPrintf(VT_RST);
        onHitSetupFuncs_81[(pthis->actor.params >> 10) & 1](pthis);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
        if ((pthis->actor.home.rot.z & 1) == 1) {
            pthis->collisionDisabledTimer = 50;
        }
    } else if (moveFuncs_81[(pthis->actor.params >> 10) & 1](pthis, globalCtx)) {
        loopMode = (pthis->actor.params >> 8) & 3;
        if (loopMode == ENGOROIWA_LOOPMODE_ONEWAY_BREAK &&
            (pthis->nextWaypoint == 0 || pthis->nextWaypoint == pthis->endWaypoint)) {
            EnGoroiwa_SpawnFragments(pthis, globalCtx);
        }
        EnGoroiwa_NextWaypoint(pthis, globalCtx);
        if ((loopMode == ENGOROIWA_LOOPMODE_ROUNDTRIP) &&
            (pthis->currentWaypoint == 0 || pthis->currentWaypoint == pthis->endWaypoint)) {
            EnGoroiwa_SetupWait(pthis);
        } else if (!((pthis->actor.params >> 10) & 1) && pthis->currentWaypoint != 0 &&
                   pthis->currentWaypoint != pthis->endWaypoint) {
            ascendDirection = EnGoroiwa_GetAscendDirection(pthis, globalCtx);
            if (ascendDirection > 0) {
                EnGoroiwa_SetupMoveUp(pthis);
            } else if (ascendDirection < 0) {
                EnGoroiwa_SetupMoveDown(pthis);
            } else {
                EnGoroiwa_SetupRoll(pthis);
            }
        } else {
            EnGoroiwa_SetupRoll(pthis);
        }
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_BIGBALL_ROLL - SFX_FLAG);
}

void EnGoroiwa_SetupMoveAndFallToGround(EnGoroiwa* pthis) {
    pthis->actionFunc = EnGoroiwa_MoveAndFallToGround;
    EnGoroiwa_UpdateFlags(pthis, ENGOROIWA_ENABLE_OC);
    pthis->actor.gravity = -0.86f;
    pthis->actor.minVelocityY = -15.0f;
    pthis->actor.speedXZ *= 0.15f;
    pthis->actor.velocity.y = 5.0f;
    pthis->rollRotSpeed = 1.0f;
}

void EnGoroiwa_MoveAndFallToGround(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    EnGoroiwa_MoveAndFall(pthis, globalCtx);
    if ((pthis->actor.bgCheckFlags & 1) && pthis->actor.velocity.y < 0.0f) {
        if ((pthis->stateFlags & ENGOROIWA_PLAYER_IN_THE_WAY) && (pthis->actor.home.rot.z & 1) == 1) {
            EnGoroiwa_ReverseDirection(pthis);
            EnGoroiwa_FaceNextWaypoint(pthis, globalCtx);
        }
        EnGoroiwa_SetupWait(pthis);
    }
}

void EnGoroiwa_SetupWait(EnGoroiwa* pthis) {

    pthis->actionFunc = EnGoroiwa_Wait;
    pthis->actor.speedXZ = 0.0f;
    EnGoroiwa_UpdateFlags(pthis, ENGOROIWA_ENABLE_OC);
    pthis->waitTimer = waitDurations_84[pthis->actor.home.rot.z & 1];
    pthis->rollRotSpeed = 0.0f;
}

void EnGoroiwa_Wait(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    if (pthis->waitTimer > 0) {
        pthis->waitTimer--;
    } else {
        pthis->collider.base.atFlags &= ~AT_HIT;
        EnGoroiwa_SetupRoll(pthis);
    }
}

void EnGoroiwa_SetupMoveUp(EnGoroiwa* pthis) {
    pthis->actionFunc = EnGoroiwa_MoveUp;
    EnGoroiwa_UpdateFlags(pthis, ENGOROIWA_ENABLE_AT | ENGOROIWA_ENABLE_OC);
    pthis->rollRotSpeed = 0.0f;
    pthis->actor.velocity.y = fabsf(pthis->actor.speedXZ) * 0.1f;
}

void EnGoroiwa_MoveUp(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        func_8002F6D4(globalCtx, &pthis->actor, 2.0f, pthis->actor.yawTowardsPlayer, 0.0f, 4);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
        if ((pthis->actor.home.rot.z & 1) == 1) {
            pthis->collisionDisabledTimer = 50;
        }
    } else if (EnGoroiwa_MoveUpToNextWaypoint(pthis, globalCtx)) {
        EnGoroiwa_NextWaypoint(pthis, globalCtx);
        EnGoroiwa_SetupRoll(pthis);
        pthis->actor.speedXZ = 0.0f;
    }
}

void EnGoroiwa_SetupMoveDown(EnGoroiwa* pthis) {
    pthis->actionFunc = EnGoroiwa_MoveDown;
    EnGoroiwa_UpdateFlags(pthis, ENGOROIWA_ENABLE_AT | ENGOROIWA_ENABLE_OC);
    pthis->rollRotSpeed = 0.3f;
    pthis->bounceCount = 0;
    pthis->actor.velocity.y = fabsf(pthis->actor.speedXZ) * -0.3f;
    pthis->stateFlags |= ENGOROIWA_RETAIN_ROT_SPEED;
    pthis->stateFlags &= ~ENGOROIWA_IN_WATER;
}

void EnGoroiwa_MoveDown(EnGoroiwa* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        func_8002F6D4(globalCtx, &pthis->actor, 2.0f, pthis->actor.yawTowardsPlayer, 0.0f, 4);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);
        if ((pthis->actor.home.rot.z & 1) == 1) {
            pthis->collisionDisabledTimer = 50;
        }
    } else if (EnGoroiwa_MoveDownToNextWaypoint(pthis, globalCtx)) {
        EnGoroiwa_NextWaypoint(pthis, globalCtx);
        EnGoroiwa_SetupRoll(pthis);
        pthis->stateFlags &= ~ENGOROIWA_RETAIN_ROT_SPEED;
        pthis->actor.speedXZ = 0.0f;
    }
}

void EnGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGoroiwa* pthis = (EnGoroiwa*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s32 sp30;

    if (!(player->stateFlags1 & 0x300000C0)) {
        if (pthis->collisionDisabledTimer > 0) {
            pthis->collisionDisabledTimer--;
        }
        pthis->actionFunc(pthis, globalCtx);
        switch ((pthis->actor.params >> 10) & 1) {
            case 1:
                Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 0x1C);
                break;
            case 0:
                pthis->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &sp30,
                                                                      &pthis->actor, &pthis->actor.world.pos);
                break;
        }
        EnGoroiwa_UpdateRotation(pthis, globalCtx);
        if (pthis->actor.xzDistToPlayer < 300.0f) {
            EnGoroiwa_UpdateCollider(pthis);
            if ((pthis->stateFlags & ENGOROIWA_ENABLE_AT) && pthis->collisionDisabledTimer <= 0) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
            if ((pthis->stateFlags & ENGOROIWA_ENABLE_OC) && pthis->collisionDisabledTimer <= 0) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
    }
}

void EnGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gRollingRockDL);
}

void EnGoroiwa_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    velocity_68 = { 0.0f, 0.0f, 0.0f };

    accel_68 = { 0.0f, 0.3f, 0.0f };

    unitY_74 = { 0.0f, 1.0f, 0.0f };

    En_Goroiwa_InitVars = {
        ACTOR_EN_GOROIWA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GOROIWA,
        sizeof(EnGoroiwa),
        (ActorFunc)EnGoroiwa_Init,
        (ActorFunc)EnGoroiwa_Destroy,
        (ActorFunc)EnGoroiwa_Update,
        (ActorFunc)EnGoroiwa_Draw,
        (ActorFunc)EnGoroiwa_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

    sColChkInfoInit = { 0, 12, 60, MASS_HEAVY };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TRAP_Z_EN_TRAP_C
#include "actor_common.h"
/*
 * File: z_en_trap.c
 * Overlay: ovl_En_Trap
 * Description: Metal Spike Trap
 */

#include "z_en_trap.h"
#include "objects/object_trap/object_trap.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

#define BEGIN_MOVE_OUT 65535.0f

#define DIR_FWD 0
#define DIR_LEFT 0x4000
#define DIR_BACK -0x8000
#define DIR_RIGHT -0x4000

// Linear motion
#define vLinearVel upperParams
#define vContinue genericVar2

// Circular motion
#define vAngularVel upperParams
#define vAngularPos genericVar1
#define vRadius genericVar2

// Four-way motion
#define vClosestDirection genericVar1 // relative to spike trap's facing angle if moving out, absolute if moving in
#define vMovementMetric genericVar2

void EnTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTrap_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Trap_InitVars = {
    ACTOR_EN_TRAP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TRAP,
    sizeof(EnTrap),
    (ActorFunc)EnTrap_Init,
    (ActorFunc)EnTrap_Destroy,
    (ActorFunc)EnTrap_Update,
    (ActorFunc)EnTrap_Draw,
    (ActorFunc)EnTrap_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_NO_PUSH | OC1_TYPE_1 | OC1_TYPE_2,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0x00001000, 0x00, 0x00 }, TOUCH_NONE, BUMP_ON, OCELEM_ON },
    { 30, 20, 0, { 0, 0, 0 } },
};

void EnTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    f32 trapDist;
    f32 trapSpeed;
    s16 zSpeed;
    s16 xSpeed;
    EnTrap* pthis = (EnTrap*)thisx;
    ColliderCylinder* unused = &pthis->collider; // required to match

    pthis->upperParams = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    Actor_SetScale(thisx, 0.1f);
    thisx->gravity = -2.0f;
    if (thisx->params & SPIKETRAP_MODE_LINEAR) {
        thisx->speedXZ = pthis->moveSpeedForwardBack.z = pthis->upperParams & 0xF;
        Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
    } else if (thisx->params & SPIKETRAP_MODE_CIRCULAR) {
        pthis->vRadius = (pthis->upperParams & 0xF) * 40.0f;
        pthis->vAngularVel = ((pthis->upperParams & 0xF0) + 0x10) << 5;
        thisx->world.pos.x = thisx->home.pos.x + (Math_SinS(0) * pthis->vRadius);
        thisx->world.pos.z = thisx->home.pos.z + (Math_CosS(0) * pthis->vRadius);
    } else { // Four-way motion
        if (pthis->upperParams != 0) {
            trapDist = (pthis->upperParams >> 4) * 40;
            trapSpeed = (pthis->upperParams & 0xF);
        } else {
            trapDist = 200.0f;
            trapSpeed = 10.0f;
            thisx->params = 0xF;
        }
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 10.0f, 20.0f, 20.0f, 0x1D);
        thisx->home.pos = thisx->world.pos;
        pthis->targetPosLeft.x = thisx->world.pos.x + (trapDist * Math_CosS(thisx->world.rot.y));
        pthis->targetPosLeft.z = thisx->world.pos.z - (trapDist * Math_SinS(thisx->world.rot.y));
        pthis->targetPosRight.x = thisx->world.pos.x + (trapDist * Math_CosS(thisx->world.rot.y + 0x8000));
        pthis->targetPosRight.z = thisx->world.pos.z - (trapDist * Math_SinS(thisx->world.rot.y + 0x8000));
        pthis->targetPosFwd.x = thisx->world.pos.x + (trapDist * Math_SinS(thisx->world.rot.y));
        pthis->targetPosFwd.z = thisx->world.pos.z + (trapDist * Math_CosS(thisx->world.rot.y));
        pthis->targetPosBack.x = thisx->world.pos.x + (trapDist * Math_SinS(thisx->world.rot.y + 0x8000));
        pthis->targetPosBack.z = thisx->world.pos.z + (trapDist * Math_CosS(thisx->world.rot.y + 0x8000));

        zSpeed = trapSpeed * Math_CosS(thisx->world.rot.y);
        xSpeed = trapSpeed * Math_SinS(thisx->world.rot.y);
        zSpeed = ABS(zSpeed);
        xSpeed = ABS(xSpeed);
        pthis->moveSpeedLeftRight.x = pthis->moveSpeedForwardBack.z = zSpeed;
        pthis->moveSpeedLeftRight.z = pthis->moveSpeedForwardBack.x = xSpeed;
    }
    thisx->focus.pos = thisx->world.pos;
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    thisx->targetMode = 3;
    thisx->colChkInfo.mass = 0xFF;
}

void EnTrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTrap* pthis = (EnTrap*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnTrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnTrap* pthis = (EnTrap*)thisx;
    Vec3f posTemp;
    s16 angleToKnockPlayer;
    s16 angleToCollidedActor;
    s16 touchingActor;
    s16 blockedOnReturn;
    s32 pad;
    s16 angleToWall;
    Vec3f icePos;
    Vec3f posAhead;
    Vec3f colPoint;         // unused return value from function
    CollisionPoly* colPoly; // unused return value from function
    s32 bgId;               // unused return value from function
    f32 temp_cond;

    touchingActor = false;
    blockedOnReturn = false;
    angleToWall = thisx->wallYaw - thisx->world.rot.y;
    if (pthis->collider.base.ocFlags1 & OC1_HIT) {
        pthis->collider.base.ocFlags1 &= ~OC1_HIT;
        angleToCollidedActor =
            thisx->world.rot.y + Math_Vec3f_Yaw(&pthis->collider.base.oc->world.pos, &thisx->world.pos);
        touchingActor = true;
    }
    // Freeze the trap if hit by ice arrows:
    if ((pthis->collider.base.acFlags & AC_HIT) != 0) {
        icePos = thisx->world.pos;
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetColorFilter(thisx, 0, 250, 0, 250);
        icePos.y += 10.0f;
        icePos.z += 10.0f;
        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, thisx, &icePos, 150, 150, 150, 250, 235, 245, 255, 1.8f);
        icePos.x += 10.0f;
        icePos.z -= 20.0f;
        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, thisx, &icePos, 150, 150, 150, 250, 235, 245, 255, 1.8f);
        icePos.x -= 20.0f;
        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, thisx, &icePos, 150, 150, 150, 250, 235, 245, 255, 1.8f);
    }
    // If not frozen:
    if (thisx->colorFilterTimer == 0) {
        DECR(pthis->playerDmgTimer);
        // Handles damaging player:
        //! @bug there is no yDistToPlayer check for player being below. Therefore hitbox extends down infinitely
        if ((thisx->xzDistToPlayer <= 40.0f) && (pthis->playerDmgTimer == 0) && (thisx->yDistToPlayer <= 20.0f)) {
            if (!(thisx->params & (SPIKETRAP_MODE_LINEAR | SPIKETRAP_MODE_CIRCULAR))) { // if in 4-way mode:
                if ((s16)(pthis->vClosestDirection - thisx->yawTowardsPlayer) >= 0) {
                    angleToKnockPlayer = pthis->vClosestDirection - 0x4000;
                } else {
                    angleToKnockPlayer = pthis->vClosestDirection + 0x4000;
                }
            } else {
                angleToKnockPlayer = thisx->yawTowardsPlayer;
            }
            globalCtx->damagePlayer(globalCtx, -4);
            func_8002F7A0(globalCtx, thisx, 6.0f, angleToKnockPlayer, 6.0f);
            pthis->playerDmgTimer = 15;
        }
        if (thisx->params & SPIKETRAP_MODE_LINEAR) {
            pthis->vContinue = 1.0f;
            // If physically touching a wall and wall faces towards spike trap
            if ((thisx->bgCheckFlags & 8) && (ABS(angleToWall) >= 0x6000)) {
                pthis->vContinue = 0.0f;
            }
            // If there is a collision poly between current position and a position 30 units ahead of spike trap
            if (pthis->vContinue != 0.0f) {
                posAhead.x = (Math_SinS(thisx->world.rot.y) * 30.0f) + thisx->world.pos.x;
                posAhead.z = (Math_CosS(thisx->world.rot.y) * 30.0f) + thisx->world.pos.z;
                posAhead.y = thisx->world.pos.y;
                if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &thisx->world.pos, &posAhead, &colPoint, &colPoly, true,
                                            true, false, true, &bgId) == true) {
                    pthis->vContinue = 0.0f;
                }
            }
            // If spike trap is touching an actor which is in the path of the spike trap
            if (touchingActor && (pthis->vContinue != 0.0f)) {
                angleToCollidedActor =
                    Math_Vec3f_Yaw(&thisx->world.pos, &pthis->collider.base.oc->world.pos) - thisx->world.rot.y;
                if (ABS(angleToCollidedActor) < 0x1000) {
                    pthis->vContinue = 0.0f;
                }
            }
            // If any of the above three conditions are met, turn around
            if (pthis->vContinue == 0.0f) {
                thisx->world.rot.y += 0x8000;
                Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
            }
        } else if (thisx->params & SPIKETRAP_MODE_CIRCULAR) {
            temp_cond = Math_SinS(pthis->vAngularPos);
            pthis->vAngularPos += pthis->vAngularVel;
            // Every full circle make a sound:
            if ((temp_cond < 0.0f) && (Math_SinS(pthis->vAngularPos) >= 0.0f)) {
                Audio_PlayActorSound2(thisx, NA_SE_EV_ROUND_TRAP_MOVE);
            }
            thisx->world.pos.x = (pthis->vRadius * Math_SinS(pthis->vAngularPos)) + thisx->home.pos.x;
            thisx->world.pos.z = (pthis->vRadius * Math_CosS(pthis->vAngularPos)) + thisx->home.pos.z;
            thisx->world.pos.y = thisx->floorHeight;
            thisx->prevPos = thisx->world.pos;
        } else { // 4 way movement
            // if moving outwards:
            if (pthis->vMovementMetric != 0.0f) {
                switch (pthis->vClosestDirection) { // movement direction relative to spike trap
                    case DIR_FWD:
                        if (!(thisx->params & SPIKETRAP_FOURWAY_FWD_ALLOWED)) {
                            pthis->vMovementMetric = 0.0f;
                        } else if ((thisx->bgCheckFlags & 8) && (ABS(angleToWall) > 0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                        }
                        if (touchingActor && (pthis->vMovementMetric != 0.0f) && (ABS(angleToCollidedActor) > 0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                        }
                        if (pthis->vMovementMetric != 0.0f) {
                            if (pthis->vMovementMetric == BEGIN_MOVE_OUT) {
                                Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
                            }
                            pthis->vMovementMetric = Math_SmoothStepToF(&thisx->world.pos.z, pthis->targetPosFwd.z, 1.0f,
                                                                       pthis->moveSpeedForwardBack.z, 0.0f);
                            pthis->vMovementMetric += Math_SmoothStepToF(&thisx->world.pos.x, pthis->targetPosFwd.x, 1.0f,
                                                                        pthis->moveSpeedForwardBack.x, 0.0f);
                        }
                        break;
                    case DIR_LEFT:
                        if (!(thisx->params & SPIKETRAP_FOURWAY_LEFT_ALLOWED)) {
                            pthis->vMovementMetric = 0.0f;
                        } else if ((thisx->bgCheckFlags & 8) && (angleToWall < -0x2000) && (angleToWall > -0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (touchingActor && (pthis->vMovementMetric != 0.0f) && (angleToCollidedActor <= -0x2000) &&
                            (angleToCollidedActor > -0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (pthis->vMovementMetric != 0.0f) {
                            if (pthis->vMovementMetric == BEGIN_MOVE_OUT) {
                                Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
                            }
                            pthis->vMovementMetric = Math_SmoothStepToF(&thisx->world.pos.x, pthis->targetPosLeft.x, 1.0f,
                                                                       pthis->moveSpeedLeftRight.x, 0.0f);
                            pthis->vMovementMetric += Math_SmoothStepToF(&thisx->world.pos.z, pthis->targetPosLeft.z,
                                                                        1.0f, pthis->moveSpeedLeftRight.z, 0.0f);
                        }
                        break;
                    case DIR_BACK:
                        if (!(thisx->params & SPIKETRAP_FOURWAY_BACK_ALLOWED)) {
                            pthis->vMovementMetric = 0.0f;
                        } else if ((thisx->bgCheckFlags & 8) && (ABS(angleToWall) < 0x2000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (touchingActor && (pthis->vMovementMetric != 0.0f) && (ABS(angleToCollidedActor) < 0x2000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (pthis->vMovementMetric != 0.0f) {
                            if (pthis->vMovementMetric == BEGIN_MOVE_OUT) {
                                Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
                            }
                            pthis->vMovementMetric = Math_SmoothStepToF(&thisx->world.pos.z, pthis->targetPosBack.z, 1.0f,
                                                                       pthis->moveSpeedForwardBack.z, 0.0f);
                            pthis->vMovementMetric += Math_SmoothStepToF(&thisx->world.pos.x, pthis->targetPosBack.x,
                                                                        1.0f, pthis->moveSpeedForwardBack.x, 0.0f);
                        }
                        break;
                    case DIR_RIGHT:
                        if (!(thisx->params & SPIKETRAP_FOURWAY_RIGHT_ALLOWED)) {
                            pthis->vMovementMetric = 0.0f;
                        } else if ((thisx->bgCheckFlags & 8) && (angleToWall > 0x2000) && (angleToWall < 0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (touchingActor && (pthis->vMovementMetric != 0.0f) && (angleToCollidedActor > 0x2000) &&
                            (angleToCollidedActor < 0x6000)) {
                            pthis->vMovementMetric = 0.0f;
                            break;
                        }
                        if (pthis->vMovementMetric != 0.0f) {
                            if (pthis->vMovementMetric == BEGIN_MOVE_OUT) {
                                Audio_PlayActorSound2(thisx, NA_SE_EV_SPINE_TRAP_MOVE);
                            }
                            pthis->vMovementMetric = Math_SmoothStepToF(&thisx->world.pos.x, pthis->targetPosRight.x,
                                                                       1.0f, pthis->moveSpeedLeftRight.x, 0.0f);
                            pthis->vMovementMetric += Math_SmoothStepToF(&thisx->world.pos.z, pthis->targetPosRight.z,
                                                                        1.0f, pthis->moveSpeedLeftRight.z, 0.0f);
                        }
                        break;
                }
                if (!Actor_TestFloorInDirection(thisx, globalCtx, 50.0f, pthis->vClosestDirection)) {
                    pthis->vMovementMetric = 0.0f;
                }
                // if in initial position:
            } else if ((thisx->world.pos.x == thisx->home.pos.x) && (thisx->world.pos.z == thisx->home.pos.z)) {
                // of the available 4-way directions, get the one which is closest to the direction of player:
                pthis->vClosestDirection = ((thisx->yawTowardsPlayer - thisx->world.rot.y) + 0x2000) & 0xC000;
                pthis->vMovementMetric = 0.0f;
                if (thisx->xzDistToPlayer < 200.0f) {
                    pthis->vMovementMetric = BEGIN_MOVE_OUT;
                }
                // If returning to origin:
            } else {
                // Of the four real world compass directions, get the one which is closest to the movement direction of
                // the returning spike. Note that pthis is different from the previous usages of vClosestDirection
                pthis->vClosestDirection = (Math_Vec3f_Yaw(&thisx->world.pos, &thisx->home.pos) + 0x2000) & 0xC000;
                switch (pthis->vClosestDirection) {
                    case 0: // movement is closest to +z direction
                        if (thisx->bgCheckFlags & 8) {
                            if (ABS(thisx->wallYaw) > 0x6000) {
                                blockedOnReturn = true;
                            }
                        } else if (touchingActor && (ABS(angleToCollidedActor) > 0x6000)) {
                            blockedOnReturn = true;
                        }
                        break;
                    case 0x4000: // movement is closest to +x direction
                        if (thisx->bgCheckFlags & 8) {
                            if ((thisx->wallYaw < -0x2000) && (thisx->wallYaw > -0x6000)) {
                                blockedOnReturn = true;
                            }
                        } else if (touchingActor && (angleToCollidedActor < -0x2000) &&
                                   (angleToCollidedActor > -0x6000)) {
                            blockedOnReturn = true;
                        }
                        break;
                    case -0x8000: // movement is closest to -z direction
                        if (thisx->bgCheckFlags & 8) {
                            if (ABS(thisx->wallYaw) < 0x2000) {
                                blockedOnReturn = true;
                            }
                        } else if (touchingActor && (ABS(angleToCollidedActor) < 0x2000)) {
                            blockedOnReturn = true;
                        }
                        break;
                    case -0x4000: // movement is closest to -x direction
                        if (thisx->bgCheckFlags & 8) {
                            if ((thisx->wallYaw > 0x2000) && (thisx->wallYaw < 0x6000)) {
                                blockedOnReturn = true;
                            }
                        } else if (touchingActor && (angleToCollidedActor > 0x2000) &&
                                   (angleToCollidedActor < 0x6000)) {
                            blockedOnReturn = true;
                        }
                        break;
                }
                if (!blockedOnReturn) {
                    Math_SmoothStepToF(&thisx->world.pos.x, thisx->home.pos.x, 1.0f, 3.0f, 0.0f);
                    Math_SmoothStepToF(&thisx->world.pos.z, thisx->home.pos.z, 1.0f, 3.0f, 0.0f);
                }
            }
        }
        Actor_MoveForward(thisx); // Only used by straight line logic
        // Adjust position using bgcheck, but do not adjust x, z position if in straight line mode:
        if (thisx->params & SPIKETRAP_MODE_LINEAR) {
            posTemp = thisx->world.pos;
        }
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 25.0f, 20.0f, 20.0f, 0x1D);
        if (thisx->params & SPIKETRAP_MODE_LINEAR) {
            thisx->world.pos.x = posTemp.x;
            thisx->world.pos.z = posTemp.z;
        }
    }
    Collider_UpdateCylinder(thisx, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    if (thisx->colorFilterTimer == 0) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnTrap_Draw(Actor* thisx, GlobalContext* globalCtx) {
    func_8002EBCC(thisx, globalCtx, 1);
    Gfx_DrawDListOpa(globalCtx, gSlidingBladeTrapDL);
}

void EnTrap_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Trap_InitVars = {
        ACTOR_EN_TRAP,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_TRAP,
        sizeof(EnTrap),
        (ActorFunc)EnTrap_Init,
        (ActorFunc)EnTrap_Destroy,
        (ActorFunc)EnTrap_Update,
        (ActorFunc)EnTrap_Draw,
        (ActorFunc)EnTrap_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT0,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_NO_PUSH | OC1_TYPE_1 | OC1_TYPE_2,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        { ELEMTYPE_UNK0, { 0x00000000, 0x00, 0x00 }, { 0x00001000, 0x00, 0x00 }, TOUCH_NONE, BUMP_ON, OCELEM_ON },
        { 30, 20, 0, { 0, 0, 0 } },
    };

}

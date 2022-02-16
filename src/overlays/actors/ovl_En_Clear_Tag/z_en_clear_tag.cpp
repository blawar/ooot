#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_CLEAR_TAG_Z_EN_CLEAR_TAG_C
#include "actor_common.h"
#include "z64bgcheck.h"
#include "z_en_clear_tag.h"
#include "def/code_8006BA00.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_demo.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnClearTag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnClearTag_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnClearTag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnClearTag_Update(Actor* thisx, GlobalContext* globalCtx);
void EnClearTag_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnClearTag_UpdateEffects(GlobalContext* globalCtx);
void EnClearTag_DrawEffects(GlobalContext* globalCtx);

void EnClearTag_CreateDebrisEffect(GlobalContext* globalCtx, Vec3f* position, Vec3f* velocity, Vec3f* acceleration,
                                   f32 scale, f32 floorHeight);
void EnClearTag_CreateFireEffect(GlobalContext* globalCtx, Vec3f* pos, f32 scale);
void EnClearTag_CreateSmokeEffect(GlobalContext* globalCtx, Vec3f* position, f32 scale);
void EnClearTag_CreateFlashEffect(GlobalContext* globalCtx, Vec3f* position, f32 scale, f32 floorHeight,
                                  Vec3f* floorTangent);

void EnClearTag_CalculateFloorTangent(EnClearTag* pthis);

ActorInit En_Clear_Tag_InitVars = {
    ACTOR_EN_CLEAR_TAG,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnClearTag),
    (ActorFunc)EnClearTag_Init,
    (ActorFunc)EnClearTag_Destroy,
    (ActorFunc)EnClearTag_Update,
    (ActorFunc)EnClearTag_Draw,
    (ActorFunc)EnClearTag_Reset,
};

static u8 sIsEffectsInitialized = false;

static Vec3f sZeroVector = { 0.0f, 0.0f, 0.0f };

static ColliderCylinderInit sArwingCylinderInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static ColliderCylinderInit sLaserCylinderInit = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static UNK_TYPE4 D_809D5C98 = 0; // unused
static UNK_TYPE4 D_809D5C9C = 0; // unused

static EnClearTagEffect sClearTagEffects[CLEAR_TAG_EFFECT_MAX_COUNT];

#include "overlays/ovl_En_Clear_Tag/ovl_En_Clear_Tag.cpp"

/**
 * Creates a debris effect.
 * Debris effects are spawned when the Arwing dies. It spawns fire effects.
 */
void EnClearTag_CreateDebrisEffect(GlobalContext* globalCtx, Vec3f* position, Vec3f* velocity, Vec3f* acceleration,
                                   f32 scale, f32 floorHeight) {
    s16 i;
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;

    // Look for an available effect to allocate a Debris effect to.
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->type = CLEAR_TAG_EFFECT_DEBRIS;

            effect->position = *position;
            effect->velocity = *velocity;
            effect->acceleration = *acceleration;

            effect->scale = scale;

            // Set the debris effects to spawn in a circle.
            effect->rotationY = Rand_ZeroFloat(M_PI * 2);
            effect->rotationX = Rand_ZeroFloat(M_PI * 2);

            effect->timer = effect->bounces = 0;

            effect->floorHeight = floorHeight;

            effect->random = (s16)Rand_ZeroFloat(10.0f);

            return;
        }
    }
}

/**
 * Creates a fire effect.
 * Fire effects are spawned by debris effects. Fire effects spawn smoke effects
 */
void EnClearTag_CreateFireEffect(GlobalContext* globalCtx, Vec3f* pos, f32 scale) {
    s16 i;
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;

    // Look for an available effect to allocate a fire effect to.
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->random = (s16)Rand_ZeroFloat(100.0f);
            effect->type = CLEAR_TAG_EFFECT_FIRE;

            effect->position = *pos;
            effect->velocity = sZeroVector;
            effect->acceleration = sZeroVector;
            effect->acceleration.y = 0.15f;

            effect->scale = scale;

            effect->primColor.a = 200.0f;

            return;
        }
    }
}

/**
 * Creates a smoke effect.
 * Smoke effects are spawned by fire effects.
 */
void EnClearTag_CreateSmokeEffect(GlobalContext* globalCtx, Vec3f* position, f32 scale) {
    s16 i;
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;

    // Look for an available effect to allocate a smoke effect to.
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->random = (s16)Rand_ZeroFloat(100.0f);
            effect->type = CLEAR_TAG_EFFECT_SMOKE;

            effect->position = *position;
            effect->velocity = sZeroVector;
            effect->acceleration = sZeroVector;

            effect->scale = scale;
            effect->maxScale = scale * 2.0f;

            effect->primColor.r = 200.0f;
            effect->primColor.g = 20.0f;
            effect->primColor.b = 0.0f;
            effect->primColor.a = 255.0f;
            effect->envColor.r = 255.0f;
            effect->envColor.g = 215.0f;
            effect->envColor.b = 255.0f;

            return;
        }
    }
}

/**
 * Creates a flash effect.
 * Flash effects are spawned when the Arwing dies.
 * Flash effects two components: 1) a billboard flash, and 2) a light effect on the ground.
 */
void EnClearTag_CreateFlashEffect(GlobalContext* globalCtx, Vec3f* position, f32 scale, f32 floorHeight,
                                  Vec3f* floorTangent) {
    s16 i;
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;

    // Look for an available effect to allocate a flash effect to.
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->type = CLEAR_TAG_EFFECT_FLASH;

            effect->position = *position;
            effect->velocity = sZeroVector;
            effect->acceleration = sZeroVector;

            effect->scale = 0.0f;
            effect->maxScale = scale * 2.0f;

            effect->floorHeight = floorHeight;
            effect->floorTangent = *floorTangent;

            effect->primColor.a = 180.0f;

            return;
        }
    }
}

/**
 * EnClear_Tag destructor.
 * This just destroys the collider.
 */
void EnClearTag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnClearTag* pthis = (EnClearTag*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

/**
 * EnClear_Tag constructor.
 * This allocates a collider, initializes effects, and sets up ClearTag instance data.
 */
void EnClearTag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnClearTag* pthis = (EnClearTag*)thisx;
    s32 defaultCutsceneTimer = 100;
    s16 i;
    s16 j;

    Collider_InitCylinder(globalCtx, &pthis->collider);

    // Initialize the Arwing laser.
    if (pthis->actor.params == CLEAR_TAG_LASER) {
        pthis->state = CLEAR_TAG_STATE_LASER;
        pthis->timers[CLEAR_TAG_TIMER_LASER_DEATH] = 70;
        pthis->actor.speedXZ = 35.0f;
        func_8002D908(&pthis->actor);
        for (j = 0; j <= 0; j++) {
            func_8002D7EC(&pthis->actor);
        }
        pthis->actor.scale.x = 0.4f;
        pthis->actor.scale.y = 0.4f;
        pthis->actor.scale.z = 2.0f;
        pthis->actor.speedXZ = 70.0f;
        pthis->actor.shape.rot.x = -pthis->actor.shape.rot.x;

        func_8002D908(&pthis->actor);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sLaserCylinderInit);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SWORD_REFLECT_MG);
    } else { // Initialize the Arwing.
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.targetMode = 5;
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sArwingCylinderInit);
        pthis->actor.colChkInfo.health = 3;

        // Update the Arwing to play the intro cutscene.
        if (pthis->actor.params == CLEAR_TAG_CUTSCENE_ARWING) {
            pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_STATE] = 70;
            pthis->timers[CLEAR_TAG_TIMER_ARWING_ENTER_LOCKED_ON] = 250;
            pthis->state = CLEAR_TAG_STATE_DEMO;
            pthis->actor.world.rot.x = 0x4000;
            pthis->cutsceneMode = CLEAR_TAG_CUTSCENE_MODE_SETUP;
            pthis->cutsceneTimer = defaultCutsceneTimer;
            pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_BG_INFO] = 20;
        }

        // Initialize all effects to available if effects have not been initialized.
        if (!sIsEffectsInitialized) {
            sIsEffectsInitialized = true;
            globalCtx->specialEffects = &sClearTagEffects[0];
            for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++) {
                sClearTagEffects[i].type = CLEAR_TAG_EFFECT_AVAILABLE;
            }
            pthis->drawMode = CLEAR_TAG_DRAW_MODE_ALL;
        }
    }
}

#include "hack.h"

/**
 * Calculate a floor tangent.
 * This is used for the ground flash display lists and Arwing shadow display lists to snap onto the floor.
 */
void EnClearTag_CalculateFloorTangent(EnClearTag* pthis) {
    // If there is a floor poly below the Arwing, calculate the floor tangent.
    if (pthis->actor.floorPoly != NULL) {
        f32 x = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.x);
        f32 y = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.y);
        f32 z = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.z);

        pthis->floorTangent.x = -Math_FAtan2F(-z * y, 1.0f);
        pthis->floorTangent.z = Math_FAtan2F(-x * y, 1.0f);
    }
}

/**
 * EnClear_Tag update function.
 *
 * ClearTag has three variants:
 * CLEAR_TAG_CUTSCENE_ARWING which is the regular Arwing and plays a cutscene on spawn.
 * CLEAR_TAG_ARWING which is a regular Arwing.
 * CLEAR_TAG_LASER which are the lasers fired by the Arwing.
 *
 * This function controls the Arwing flying. A target position is set and the Arwing flies toward it based on
 * calculated directions from the current position.
 * This function fires Arwing lasers when the state is CLEAR_TAG_STATE_TARGET_LOCKED.
 * This function controls the cutscene that plays when the Arwing has params for
 * cutscene. The cutscene stops playing when the Arwing is a specified distance from the starting point.
 */
void EnClearTag_Update(Actor* thisx, GlobalContext* globalCtx2) {
    u8 hasAtHit = false;
    s16 i;
    s16 xRotationTarget;
    s16 rotationScale;
    GlobalContext* globalCtx = globalCtx2;
    EnClearTag* pthis = (EnClearTag*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    pthis->frameCounter++;

    if (pthis->drawMode != CLEAR_TAG_DRAW_MODE_EFFECT) {
        for (i = 0; i < 3; i++) {
            if (pthis->timers[i] != 0) {
                pthis->timers[i]--;
            }
        }

        if (pthis->cutsceneTimer != 0) {
            pthis->cutsceneTimer--;
        }

        switch (pthis->state) {
            case CLEAR_TAG_STATE_DEMO:
            case CLEAR_TAG_STATE_TARGET_LOCKED:
            case CLEAR_TAG_STATE_FLYING: {
                f32 vectorToTargetX;
                f32 vectorToTargetY;
                f32 vectorToTargetZ;
                s16 worldRotationTargetX;
                s16 worldRotationTargetY;
                f32 loseTargetLockDistance;
                s16 worldRotationTargetZ;
                s32 pad;

                // Check if the Arwing should crash.
                if (pthis->collider.base.acFlags & AC_HIT) {

                    pthis->collider.base.acFlags &= ~AC_HIT;
                    pthis->crashingTimer = 20;
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 5);
                    pthis->acceleration.x = Rand_CenteredFloat(15.0f);
                    pthis->acceleration.y = Rand_CenteredFloat(15.0f);
                    pthis->acceleration.z = Rand_CenteredFloat(15.0f);

                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_THUNDER_GND);
                    pthis->actor.colChkInfo.health--;
                    if ((s8)pthis->actor.colChkInfo.health <= 0) {
                        pthis->state = CLEAR_TAG_STATE_CRASHING;
                        pthis->actor.velocity.y = 0.0f;
                        goto state_crashing;
                    }
                }
                Actor_SetScale(&pthis->actor, 0.2f);
                pthis->actor.speedXZ = 7.0f;

                if (pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_STATE] == 0) {
                    if (pthis->timers[CLEAR_TAG_TIMER_ARWING_ENTER_LOCKED_ON] == 0) {
                        pthis->state = CLEAR_TAG_STATE_TARGET_LOCKED;
                        pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_STATE] = 300;
                    } else {
                        pthis->state = CLEAR_TAG_STATE_FLYING;
                        pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_STATE] = (s16)Rand_ZeroFloat(50.0f) + 20;

                        if (pthis->actor.params == CLEAR_TAG_ARWING) {
                            // Set the Arwing to fly in a circle around the player.
                            f32 targetCircleX = Math_SinS(player->actor.shape.rot.y) * 400.0f;
                            f32 targetCircleZ = Math_CosS(player->actor.shape.rot.y) * 400.0f;

                            pthis->targetPosition.x =
                                Rand_CenteredFloat(700.0f) + (player->actor.world.pos.x + targetCircleX);
                            pthis->targetPosition.y = Rand_ZeroFloat(200.0f) + player->actor.world.pos.y + 150.0f;
                            pthis->targetPosition.z =
                                Rand_CenteredFloat(700.0f) + (player->actor.world.pos.z + targetCircleZ);
                        } else {
                            // Set the Arwing to fly to a random position.
                            pthis->targetPosition.x = Rand_CenteredFloat(700.0f);
                            pthis->targetPosition.y = Rand_ZeroFloat(200.0f) + 150.0f;
                            pthis->targetPosition.z = Rand_CenteredFloat(700.0f);
                        }
                    }

                    pthis->targetDirection.x = pthis->targetDirection.y = pthis->targetDirection.z = 0.0f;
                }

                rotationScale = 10;
                xRotationTarget = 0x800;
                loseTargetLockDistance = 100.0f;
                if (pthis->state == CLEAR_TAG_STATE_TARGET_LOCKED) {
                    // Set the Arwing to fly towards the player.
                    pthis->targetPosition.x = player->actor.world.pos.x;
                    pthis->targetPosition.y = player->actor.world.pos.y + 40.0f;
                    pthis->targetPosition.z = player->actor.world.pos.z;
                    rotationScale = 7;
                    xRotationTarget = 0x1000;
                    loseTargetLockDistance = 150.0f;
                } else if (pthis->state == CLEAR_TAG_STATE_DEMO) {
                    // Move the Arwing for the intro cutscene.

                    // Do a Barrel Roll!
                    pthis->roll += 0.5f;
                    if (pthis->roll > M_PI * 2) {
                        pthis->roll -= M_PI * 2;
                    }

                    // Set the Arwing to fly to a hardcoded position.
                    pthis->targetPosition.x = 0.0f;
                    pthis->targetPosition.y = 300.0f;
                    pthis->targetPosition.z = 0.0f;
                    loseTargetLockDistance = 100.0f;
                }

                // If the Arwing is not in cutscene state, smoothly update the roll to zero.
                // This will reset the Arwing to be right side up after the cutscene is done.
                // The cutscene will set the Arwing to do a barrel roll and doesn't end on right side up.
                if (pthis->state != CLEAR_TAG_STATE_DEMO) {
                    Math_ApproachZeroF(&pthis->roll, 0.1f, 0.2f);
                }

                // Calculate a vector towards the targetted position.
                vectorToTargetX = pthis->targetPosition.x - pthis->actor.world.pos.x;
                vectorToTargetY = pthis->targetPosition.y - pthis->actor.world.pos.y;
                vectorToTargetZ = pthis->targetPosition.z - pthis->actor.world.pos.z;

                // If the Arwing is within a certain distance to the target position, it will be updated to flymode
                if (sqrtf(SQ(vectorToTargetX) + SQ(vectorToTargetY) + SQ(vectorToTargetZ)) < loseTargetLockDistance) {
                    pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_STATE] = 0;
                    if (pthis->state == CLEAR_TAG_STATE_TARGET_LOCKED) {
                        pthis->timers[CLEAR_TAG_TIMER_ARWING_ENTER_LOCKED_ON] = (s16)Rand_ZeroFloat(100.0f) + 100;
                    }
                    pthis->state = CLEAR_TAG_STATE_FLYING;
                }

                // Calculate the direction for the Arwing to fly and the rotation for the Arwing
                // based on the Arwing's direction, and current rotation.
                worldRotationTargetY = Math_FAtan2F(vectorToTargetX, vectorToTargetZ) * (0x8000 / M_PI);
                worldRotationTargetX =
                    Math_FAtan2F(vectorToTargetY, sqrtf(SQ(vectorToTargetX) + SQ(vectorToTargetZ))) * (0x8000 / M_PI);
                if ((worldRotationTargetX < 0) && (pthis->actor.world.pos.y < pthis->actor.floorHeight + 20.0f)) {
                    worldRotationTargetX = 0;
                }
                Math_ApproachS(&pthis->actor.world.rot.x, worldRotationTargetX, rotationScale, pthis->targetDirection.x);
                worldRotationTargetZ = Math_SmoothStepToS(&pthis->actor.world.rot.y, worldRotationTargetY, rotationScale,
                                                          pthis->targetDirection.y, 0);
                Math_ApproachF(&pthis->targetDirection.x, xRotationTarget, 1.0f, 0x100);
                pthis->targetDirection.y = pthis->targetDirection.x;
                if (ABS(worldRotationTargetZ) < 0x1000) {
                    Math_ApproachS(&pthis->actor.world.rot.z, 0, 15, pthis->targetDirection.z);
                    Math_ApproachF(&pthis->targetDirection.z, 0x500, 1.0f, 0x100);

                    // Check if the Arwing should fire its laser.
                    if ((pthis->frameCounter % 4) == 0 && (Rand_ZeroOne() < 0.75f) &&
                        (pthis->state == CLEAR_TAG_STATE_TARGET_LOCKED)) {
                        pthis->shouldShootLaser = true;
                    }
                } else {
                    worldRotationTargetZ = worldRotationTargetZ > 0 ? -0x2500 : 0x2500;
                    Math_ApproachS(&pthis->actor.world.rot.z, worldRotationTargetZ, rotationScale,
                                   pthis->targetDirection.z);
                    Math_ApproachF(&pthis->targetDirection.z, 0x1000, 1.0f, 0x200);
                }
                pthis->actor.shape.rot = pthis->actor.world.rot;
                pthis->actor.shape.rot.x = -pthis->actor.shape.rot.x;

                // Update the Arwing's velocity.
                func_8002D908(&pthis->actor);
                pthis->actor.velocity.x += pthis->acceleration.x;
                pthis->actor.velocity.y += pthis->acceleration.y;
                pthis->actor.velocity.z += pthis->acceleration.z;
                Math_ApproachZeroF(&pthis->acceleration.x, 1.0f, 1.0f);
                Math_ApproachZeroF(&pthis->acceleration.y, 1.0f, 1.0f);
                Math_ApproachZeroF(&pthis->acceleration.z, 1.0f, 1.0f);

                // Fire the Arwing laser.
                if (pthis->shouldShootLaser) {
                    pthis->shouldShootLaser = false;
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_CLEAR_TAG, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, pthis->actor.world.rot.x,
                                pthis->actor.world.rot.y, pthis->actor.world.rot.z, CLEAR_TAG_STATE_LASER);
                }
            }
            case CLEAR_TAG_STATE_CRASHING:
            state_crashing:
                if (pthis->crashingTimer != 0) {
                    pthis->crashingTimer--;
                }

                func_8002D7EC(&pthis->actor);

                Actor_SetFocus(&pthis->actor, 0.0f);

                // Update Arwing collider to better match a ground collision.
                pthis->collider.dim.radius = 20;
                pthis->collider.dim.height = 15;
                pthis->collider.dim.yShift = -5;
                Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

                if (pthis->timers[CLEAR_TAG_TIMER_ARWING_UPDATE_BG_INFO] == 0) {
                    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 30.0f, 100.0f, 5);
                    EnClearTag_CalculateFloorTangent(pthis);
                }

                if (pthis->state == CLEAR_TAG_STATE_CRASHING) {
                    // Create fire effects while the Arwing crashes.
                    EnClearTag_CreateFireEffect(globalCtx, &pthis->actor.world.pos, 1.0f);

                    // Causes the Arwing to roll around seemingly randomly while crashing.
                    pthis->roll -= 0.5f;
                    pthis->actor.velocity.y -= 0.2f;
                    pthis->actor.shape.rot.x += 0x10;

                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_K_BREATH - SFX_FLAG);

                    // Check if the Arwing has hit the ground.
                    if (pthis->actor.bgCheckFlags & 9) {
                        pthis->shouldExplode = true;

                        if (pthis->drawMode != CLEAR_TAG_DRAW_MODE_ARWING) {
                            pthis->drawMode = CLEAR_TAG_DRAW_MODE_EFFECT;
                            pthis->deathTimer = 70;
                            pthis->actor.flags &= ~ACTOR_FLAG_0;
                        } else {
                            Actor_Kill(&pthis->actor);
                        }
                    }
                }
                break;

            case CLEAR_TAG_STATE_LASER:
                func_8002D7EC(&pthis->actor);

                // Check if the laser has hit a target.
                if (pthis->collider.base.atFlags & AT_HIT) {
                    hasAtHit = true;
                }

                // Set laser collider properties.
                pthis->collider.dim.radius = 23;
                pthis->collider.dim.height = 25;
                pthis->collider.dim.yShift = -10;
                Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
                Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 80.0f, 100.0f, 5);

                // Check if the laser has hit a target, timed out, or hit the ground.
                if (pthis->actor.bgCheckFlags & 9 || hasAtHit || pthis->timers[CLEAR_TAG_TIMER_LASER_DEATH] == 0) {
                    // Kill the laser.
                    Actor_Kill(&pthis->actor);
                    // Player laser sound effect if the laser did not time out.
                    if (pthis->timers[CLEAR_TAG_TIMER_LASER_DEATH] != 0) {
                        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_FANTOM_THUNDER_GND);
                    }
                }
                break;
        }

        if (pthis->state < CLEAR_TAG_STATE_LASER) {
            // Play the Arwing cutscene.
            osSyncPrintf("DEMO_MODE %d\n", pthis->cutsceneMode);
            osSyncPrintf("CAMERA_NO %d\n", pthis->cameraId);

            if (pthis->cutsceneMode != CLEAR_TAG_CUTSCENE_MODE_NONE) {
                f32 cutsceneCameraCircleX;
                f32 cutsceneCameraCircleZ;
                s16 cutsceneTimer;
                Vec3f cutsceneCameraAtTarget;
                Vec3f cutsceneCameraEyeTarget;

                switch (pthis->cutsceneMode) {
                    case CLEAR_TAG_CUTSCENE_MODE_SETUP:
                        // Initializes Arwing cutscene camera data.
                        pthis->cutsceneMode = CLEAR_TAG_CUTSCENE_MODE_PLAY;
                        func_80064520(globalCtx, &globalCtx->csCtx);
                        pthis->cameraId = Gameplay_CreateSubCamera(globalCtx);
                        Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
                        Gameplay_ChangeCameraStatus(globalCtx, pthis->cameraId, CAM_STAT_ACTIVE);
                    case CLEAR_TAG_CUTSCENE_MODE_PLAY:
                        // Update the Arwing cutscene camera to spin around in a circle.
                        cutsceneTimer = pthis->frameCounter * 128;
                        cutsceneCameraCircleX = Math_SinS(cutsceneTimer) * 200.0f;
                        cutsceneCameraCircleZ = Math_CosS(cutsceneTimer) * 200.0f;
                        cutsceneCameraAtTarget.x = pthis->actor.world.pos.x + cutsceneCameraCircleX;
                        cutsceneCameraAtTarget.y = 200.0f;
                        cutsceneCameraAtTarget.z = pthis->actor.world.pos.z + cutsceneCameraCircleZ;
                        cutsceneCameraEyeTarget = pthis->actor.world.pos;
                        break;
                }

                // Make the Arwing cutscene camera approach the target.
                if (pthis->cameraId != SUBCAM_FREE) {
                    Math_ApproachF(&pthis->cutsceneCameraAt.x, cutsceneCameraAtTarget.x, 0.1f, 500.0f);
                    Math_ApproachF(&pthis->cutsceneCameraAt.y, cutsceneCameraAtTarget.y, 0.1f, 500.0f);
                    Math_ApproachF(&pthis->cutsceneCameraAt.z, cutsceneCameraAtTarget.z, 0.1f, 500.0f);
                    Math_ApproachF(&pthis->cutsceneCameraEye.x, cutsceneCameraEyeTarget.x, 0.2f, 500.0f);
                    Math_ApproachF(&pthis->cutsceneCameraEye.y, cutsceneCameraEyeTarget.y, 0.2f, 500.0f);
                    Math_ApproachF(&pthis->cutsceneCameraEye.z, cutsceneCameraEyeTarget.z, 0.2f, 500.0f);
                    Gameplay_CameraSetAtEye(globalCtx, pthis->cameraId, &pthis->cutsceneCameraEye,
                                            &pthis->cutsceneCameraAt);
                }

                // Cutscene has finished.
                if (pthis->cutsceneTimer == 1) {
                    func_800C08AC(globalCtx, pthis->cameraId, 0);
                    pthis->cutsceneMode = pthis->cameraId = SUBCAM_FREE;
                    func_80064534(globalCtx, &globalCtx->csCtx);
                }
            }
        }
    }

    // Explode the Arwing
    if (pthis->shouldExplode) {
        Vec3f crashEffectLocation;
        Vec3f crashEffectVelocity;
        Vec3f debrisEffectAcceleration;

        pthis->shouldExplode = false;
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_IT_BOMB_EXPLOSION);

        // Spawn flash effect.
        crashEffectLocation.x = pthis->actor.world.pos.x;
        crashEffectLocation.y = (pthis->actor.world.pos.y + 40.0f) - 30.0f;
        crashEffectLocation.z = pthis->actor.world.pos.z;
        EnClearTag_CreateFlashEffect(globalCtx, &crashEffectLocation, 6.0f, pthis->actor.floorHeight,
                                     &pthis->floorTangent);

        // Spawn smoke effect.
        crashEffectLocation.y = (pthis->actor.world.pos.y + 30.0f) - 50.0f;
        EnClearTag_CreateSmokeEffect(globalCtx, &crashEffectLocation, 3.0f);
        crashEffectLocation.y = pthis->actor.world.pos.y;

        // Spawn debris effects.
        for (i = 0; i < 15; i++) {
            crashEffectVelocity.x = sinf(i * 1.65f) * i * 0.3f;
            crashEffectVelocity.z = cosf(i * 1.65f) * i * 0.3f;
            crashEffectVelocity.y = Rand_ZeroFloat(6.0f) + 5.0f;
            crashEffectVelocity.x += Rand_CenteredFloat(0.5f);
            crashEffectVelocity.z += Rand_CenteredFloat(0.5f);

            debrisEffectAcceleration.x = 0.0f;
            debrisEffectAcceleration.y = -1.0f;
            debrisEffectAcceleration.z = 0.0f;

            EnClearTag_CreateDebrisEffect(globalCtx, &crashEffectLocation, &crashEffectVelocity,
                                          &debrisEffectAcceleration, Rand_ZeroFloat(0.15f) + 0.075f,
                                          pthis->actor.floorHeight);
        }
    }

    if (pthis->drawMode != CLEAR_TAG_DRAW_MODE_ARWING) {
        // Check if the Arwing should be removed.
        if ((pthis->drawMode == CLEAR_TAG_DRAW_MODE_EFFECT) && (DECR(pthis->deathTimer) == 0)) {
            Actor_Kill(&pthis->actor);
        }

        EnClearTag_UpdateEffects(globalCtx);
    }
}

/**
 * EnClear_Tag draw function.
 * Laser clear tag type will draw two lasers.
 * Arwing clear tage types will draw the Arwing, the backfire, and a shadow.
 */
void EnClearTag_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnClearTag* pthis = (EnClearTag*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 983);
    if (pthis->drawMode != CLEAR_TAG_DRAW_MODE_EFFECT) {
        func_80093D84(globalCtx->state.gfxCtx);

        if (pthis->state >= CLEAR_TAG_STATE_LASER) {
            // Draw Arwing lasers.
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 255, 0, 255);

            Matrix_Translate(25.0f, 0.0f, 0.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1004),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingLaserDL);

            Matrix_Translate(-50.0f, 0.0f, 0.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1011),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingLaserDL);
        } else {
            // Draw the Arwing itself.
            func_80093D18(globalCtx->state.gfxCtx);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
            if (pthis->crashingTimer != 0) {
                f32 xRotation;
                f32 yRotation;
                f32 scaledCrashingTimer = pthis->crashingTimer * 0.05f;

                xRotation = Math_SinS(pthis->frameCounter * 0x3000) * scaledCrashingTimer;
                yRotation = Math_SinS(pthis->frameCounter * 0x3700) * scaledCrashingTimer;
                Matrix_RotateX(xRotation, MTXMODE_APPLY);
                Matrix_RotateY(yRotation, MTXMODE_APPLY);
            }
            Matrix_RotateZ(pthis->roll, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1030),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gArwingDL);

            // Draw the Arwing Backfire
            Matrix_Translate(0.0f, 0.0f, -60.0f, MTXMODE_APPLY);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(2.5f, 1.3f, 0.0f, MTXMODE_APPLY);
            if ((pthis->frameCounter % 2) != 0) {
                Matrix_Scale(1.15f, 1.15f, 1.15f, MTXMODE_APPLY);
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 200, 155);
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 50, 0, 0);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1067),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingBackfireDL);

            // Draw the Arwing shadow.
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 130);
            Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.floorHeight, pthis->actor.world.pos.z, MTXMODE_NEW);
            Matrix_RotateX(pthis->floorTangent.x, MTXMODE_APPLY);
            Matrix_RotateZ(pthis->floorTangent.z, MTXMODE_APPLY);
            Matrix_Scale(pthis->actor.scale.x + 0.35f, 0.0f, pthis->actor.scale.z + 0.35f, MTXMODE_APPLY);
            Matrix_RotateY((pthis->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_APPLY);
            Matrix_RotateX((pthis->actor.shape.rot.x / 32768.0f) * M_PI, MTXMODE_APPLY);
            Matrix_RotateZ((pthis->actor.shape.rot.z / 32768.0f) * M_PI, MTXMODE_APPLY);
            if (pthis->crashingTimer != 0) {
                f32 xRotation;
                f32 yRotation;
                f32 scaledCrashingTimer = pthis->crashingTimer * 0.05f;

                xRotation = Math_SinS(pthis->frameCounter * 0x3000) * scaledCrashingTimer;
                yRotation = Math_SinS(pthis->frameCounter * 0x3700) * scaledCrashingTimer;
                Matrix_RotateX(xRotation, MTXMODE_APPLY);
                Matrix_RotateY(yRotation, MTXMODE_APPLY);
            }
            Matrix_RotateZ(pthis->roll, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1104),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingShadowDL);
        }
    }

    if (pthis->drawMode != CLEAR_TAG_DRAW_MODE_ARWING) {
        EnClearTag_DrawEffects(globalCtx);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_clear_tag.c", 1119);
}

/**
 * Updates the Arwing effects.
 * Performs effect physics.
 * Moves and bounces debris effects.
 * Fades most effects out of view. When effects are completely faded away they are removed.
 */
void EnClearTag_UpdateEffects(GlobalContext* globalCtx) {
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;
    s16 i;
    f32 originalYPosition;
    Vec3f sphereCenter;

    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type != CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->random++;

            // Perform effect physics.
            effect->position.x += effect->velocity.x;
            originalYPosition = effect->position.y;
            effect->position.y += effect->velocity.y;
            effect->position.z += effect->velocity.z;
            effect->velocity.x += effect->acceleration.x;
            effect->velocity.y += effect->acceleration.y;
            effect->velocity.z += effect->acceleration.z;

            if (effect->type == CLEAR_TAG_EFFECT_DEBRIS) {
                // Clamp the velocity to -5.0
                if (effect->velocity.y < -5.0f) {
                    effect->velocity.y = -5.0f;
                }

                // While the effect is falling check if it has hit the ground.
                if (effect->velocity.y < 0.0f) {
                    sphereCenter = effect->position;
                    sphereCenter.y += 5.0f;

                    // Check if the debris has hit the ground.
                    if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &sphereCenter, 11.0f)) {
                        effect->position.y = originalYPosition;

                        // Bounce the debris effect.
                        if (effect->bounces <= 0) {
                            effect->bounces++;
                            effect->velocity.y *= -0.5f;
                            effect->timer = ((s16)Rand_ZeroFloat(20)) + 25;
                        } else {
                            // The Debris effect is done bouncing. Set its velocity and acceleration to 0.
                            effect->velocity.x = effect->velocity.z = effect->acceleration.y = effect->velocity.y =
                                0.0f;
                        }
                    }
                }

                // Rotate the debris effect.
                if (effect->acceleration.y != 0.0f) {
                    effect->rotationY += 0.5f;
                    effect->rotationX += 0.35f;
                }

                // If the timer is completed, unload the debris effect.
                if (effect->timer == 1) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }

                // Spawn a fire effect every 3 frames.
                if (effect->random >= 3) {
                    effect->random = 0;
                    EnClearTag_CreateFireEffect(globalCtx, &effect->position, effect->scale * 8.0f);
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_FIRE) {
                // Fade the fire effect.
                Math_ApproachZeroF(&effect->primColor.a, 1.0f, 15.0f);
                // If the fire effect is fully faded, unload it.
                if (effect->primColor.a <= 0.0f) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_SMOKE) {
                // Fade the smoke effects.
                Math_ApproachZeroF(&effect->primColor.r, 1.0f, 20.0f);
                Math_ApproachZeroF(&effect->primColor.g, 1.0f, 2.0f);
                Math_ApproachZeroF(&effect->envColor.r, 1.0f, 25.5f);
                Math_ApproachZeroF(&effect->envColor.g, 1.0f, 21.5f);
                Math_ApproachZeroF(&effect->envColor.b, 1.0f, 25.5f);

                // Smooth scale the smoke effects.
                Math_ApproachF(&effect->scale, effect->maxScale, 0.05f, 0.1f);

                if (effect->primColor.r == 0.0f) {
                    // Fade the smoke effects.
                    Math_ApproachZeroF(&effect->primColor.a, 1.0f, 3.0f);

                    // If the smoke effect has fully faded, unload it.
                    if (effect->primColor.a <= 0.0f) {
                        effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                    }
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
                // Smooth scale the flash effects.
                Math_ApproachF(&effect->scale, effect->maxScale, 1.0f, 3.0f);
                // Fade the flash effects.
                Math_ApproachZeroF(&effect->primColor.a, 1.0f, 10.0f);

                // If the flash effect has fully faded, unload it.
                if (effect->primColor.a <= 0.0f) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
            }

            if (effect->timer != 0) {
                effect->timer--;
            }
        }
    }
}

/**
 * Draws the Arwing effects.
 * Each effect type is drawn before the next. The function will apply a material that applies to all effects of that
 * type while drawing the first effect of that type.
 */
void EnClearTag_DrawEffects(GlobalContext* globalCtx) {
    s16 i;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u8 isMaterialApplied = false;
    EnClearTagEffect* effect = (EnClearTagEffect*)globalCtx->specialEffects;
    EnClearTagEffect* firstEffect = effect;

    OPEN_DISPS(gfxCtx, "../z_en_clear_tag.c", 1288);
    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    // Draw all Debris effects.
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_DEBRIS) {
            // Apply the debris effect material if it has not already been applied.
            if (!isMaterialApplied) {
                isMaterialApplied++;
                gSPDisplayList(POLY_OPA_DISP++, gArwingDebrisEffectMaterialDL);
            }

            // Draw the debris effect.
            Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
            Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
            Matrix_RotateY(effect->rotationY, MTXMODE_APPLY);
            Matrix_RotateX(effect->rotationX, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_clear_tag.c", 1307),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gArwingDebrisEffectDL);
        }
    }

    // Draw all ground flash effects.
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
            // Apply the flash ground effect material if it has not already been applied.
            if (!isMaterialApplied) {
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 200, 0);
                isMaterialApplied++;
            }

            // Draw the ground flash effect.
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 200, (s8)effect->primColor.a);
            Matrix_Translate(effect->position.x, effect->floorHeight, effect->position.z, MTXMODE_NEW);
            Matrix_RotateX(effect->floorTangent.x, MTXMODE_APPLY);
            Matrix_RotateZ(effect->floorTangent.z, MTXMODE_APPLY);
            Matrix_Scale(effect->scale + effect->scale, 1.0f, effect->scale * 2.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_clear_tag.c", 1342),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingFlashEffectGroundDL);
        }
    }

    // Draw all smoke effects.
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_SMOKE) {
            // Apply the smoke effect material if it has not already been applied.
            if (!isMaterialApplied) {
                gSPDisplayList(POLY_XLU_DISP++, gArwingFireEffectMaterialDL);
                isMaterialApplied++;
            }

            // Draw the smoke effect.
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetEnvColor(POLY_XLU_DISP++, (s8)effect->envColor.r, (s8)effect->envColor.g, (s8)effect->envColor.b,
                           128);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (s8)effect->primColor.r, (s8)effect->primColor.g,
                            (s8)effect->primColor.b, (s8)effect->primColor.a);
            gSPSegment(POLY_XLU_DISP++, 8,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, effect->random * -5, 32, 64, 1, 0, 0, 32, 32));
            Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);
            Matrix_Translate(0.0f, 20.0f, 0.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_clear_tag.c", 1392),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingFireEffectDL);
        }
    }

    // Draw all fire effects.
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_FIRE) {
            // Apply the fire effect material if it has not already been applied.
            if (!isMaterialApplied) {
                gSPDisplayList(POLY_XLU_DISP++, gArwingFireEffectMaterialDL);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
                isMaterialApplied++;
            }

            // Draw the fire effect.
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, (s8)effect->primColor.a);
            gSPSegment(POLY_XLU_DISP++, 8,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, (effect->random * -15) & 0xFF, 32, 64, 1, 0, 0,
                                        32, 32));
            Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_clear_tag.c", 1439),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingFireEffectDL);
        }
    }

    // Draw all flash billboard effects.
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < CLEAR_TAG_EFFECT_MAX_COUNT; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
            // Apply the flash billboard effect material if it has not already been applied.
            if (!isMaterialApplied) {
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 200, 0);
                isMaterialApplied++;
            }

            // Draw the flash billboard effect.
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 200, (s8)effect->primColor.a);
            Matrix_Translate(effect->position.x, effect->position.y, effect->position.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_clear_tag.c", 1470),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gArwingFlashEffectDL);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_en_clear_tag.c", 1477);
}

void EnClearTag_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Clear_Tag_InitVars = {
        ACTOR_EN_CLEAR_TAG,
        ACTORCAT_BOSS,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnClearTag),
        (ActorFunc)EnClearTag_Init,
        (ActorFunc)EnClearTag_Destroy,
        (ActorFunc)EnClearTag_Update,
        (ActorFunc)EnClearTag_Draw,
        (ActorFunc)EnClearTag_Reset,
    };

    sIsEffectsInitialized = false;

    sZeroVector = { 0.0f, 0.0f, 0.0f };

    sArwingCylinderInit = {
        {
            COLTYPE_HIT3,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0xFFDFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, 30, 10, { 0, 0, 0 } },
    };

    sLaserCylinderInit = {
        {
            COLTYPE_METAL,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x04 },
            { 0xFFDFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, 30, 10, { 0, 0, 0 } },
    };

    D_809D5C98 = 0;

    D_809D5C9C = 0;

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DOG_Z_EN_DOG_C
#include "actor_common.h"
/*
 * File: z_en_dog.c
 * Overlay: ovl_En_Dog
 * Description: Dog
 */

#include "z_en_dog.h"
#include "objects/object_dog/object_dog.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_path.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

void EnDog_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDog_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDog_FollowPath(EnDog* pthis, GlobalContext* globalCtx);
void EnDog_ChooseMovement(EnDog* pthis, GlobalContext* globalCtx);
void EnDog_FollowPlayer(EnDog* pthis, GlobalContext* globalCtx);
void EnDog_RunAway(EnDog* pthis, GlobalContext* globalCtx);
void EnDog_FaceLink(EnDog* pthis, GlobalContext* globalCtx);
void EnDog_Wait(EnDog* pthis, GlobalContext* globalCtx);

ActorInit En_Dog_InitVars = {
    ACTOR_EN_DOG,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DOG,
    sizeof(EnDog),
    (ActorFunc)EnDog_Init,
    (ActorFunc)EnDog_Destroy,
    (ActorFunc)EnDog_Update,
    (ActorFunc)EnDog_Draw,
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
    { 16, 20, 0, { 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, 50 };

static struct_80034EC0_Entry sAnimations[] = {
    { &gDogWalkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gDogWalkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogRunAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogBarkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
    { &gDogSitAnim, 1.0f, 0.0f, 4.0f, ANIMMODE_ONCE, -6.0f },
    { &gDogSitAnim, 1.0f, 5.0f, 25.0f, ANIMMODE_LOOP_PARTIAL, -6.0f },
    { &gDogBowAnim, 1.0f, 0.0f, 6.0f, ANIMMODE_ONCE, -6.0f },
    { &gDogBow2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -6.0f },
};

typedef enum {
    /* 0x00 */ DOG_WALK,
    /* 0x01 */ DOG_RUN,
    /* 0x02 */ DOG_BARK,
    /* 0x03 */ DOG_SIT,
    /* 0x04 */ DOG_SIT_2,
    /* 0x05 */ DOG_BOW,
    /* 0x06 */ DOG_BOW_2
} DogBehavior;

void EnDog_PlayWalkSFX(EnDog* pthis) {
    AnimationHeader* walk = &gDogWalkAnim;

    if (pthis->skelAnime.animation == walk) {
        if ((pthis->skelAnime.curFrame == 1.0f) || (pthis->skelAnime.curFrame == 7.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHIBI_WALK);
        }
    }
}

void EnDog_PlayRunSFX(EnDog* pthis) {
    AnimationHeader* run = &gDogRunAnim;

    if (pthis->skelAnime.animation == run) {
        if ((pthis->skelAnime.curFrame == 2.0f) || (pthis->skelAnime.curFrame == 4.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHIBI_WALK);
        }
    }
}

void EnDog_PlayBarkSFX(EnDog* pthis) {
    AnimationHeader* bark = &gDogBarkAnim;

    if (pthis->skelAnime.animation == bark) {
        if ((pthis->skelAnime.curFrame == 13.0f) || (pthis->skelAnime.curFrame == 19.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_SMALL_DOG_BARK);
        }
    }
}

s32 EnDog_PlayAnimAndSFX(EnDog* pthis) {
    s32 animation;

    if (pthis->behavior != pthis->nextBehavior) {
        if (pthis->nextBehavior == DOG_SIT_2) {
            pthis->nextBehavior = DOG_SIT;
        }
        if (pthis->nextBehavior == DOG_BOW_2) {
            pthis->nextBehavior = DOG_BOW;
        }

        pthis->behavior = pthis->nextBehavior;
        switch (pthis->behavior) {
            case DOG_WALK:
                animation = 1;
                break;
            case DOG_RUN:
                animation = 2;
                break;
            case DOG_BARK:
                animation = 3;
                break;
            case DOG_SIT:
                animation = 4;
                break;
            case DOG_BOW:
                animation = 6;
                break;
        }
        func_80034EC0(&pthis->skelAnime, sAnimations, animation);
    }

    switch (pthis->behavior) {
        case DOG_SIT:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 5);
                pthis->behavior = pthis->nextBehavior = DOG_SIT_2;
            }
            break;
        case DOG_BOW:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 7);
                pthis->behavior = pthis->nextBehavior = DOG_BOW_2;
            }
            break;
        case DOG_WALK:
            EnDog_PlayWalkSFX(pthis);
            break;
        case DOG_RUN:
            EnDog_PlayRunSFX(pthis);
            break;
        case DOG_BARK:
            EnDog_PlayBarkSFX(pthis);
            break;
    }
    return 0;
}

s8 EnDog_CanFollow(EnDog* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        return 2;
    }

    if (globalCtx->sceneNum == SCENE_MARKET_DAY) {
        return 0;
    }

    if (pthis->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
        pthis->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
        if (gSaveContext.dogParams != 0) {
            return 0;
        }
        gSaveContext.dogParams = (pthis->actor.params & 0x7FFF);
        return 1;
    }

    return 0;
}

s32 EnDog_UpdateWaypoint(EnDog* pthis, GlobalContext* globalCtx) {
    s32 change;

    if (pthis->path == NULL) {
        return 0;
    }

    if (pthis->reverse) {
        change = -1;
    } else {
        change = 1;
    }

    pthis->waypoint += change;

    if (pthis->reverse) {
        if (pthis->waypoint < 0) {
            pthis->waypoint = pthis->path->count - 1;
        }
    } else {
        if ((pthis->path->count - 1) < pthis->waypoint) {
            pthis->waypoint = 0;
        }
    }

    return 1;
}

s32 EnDog_Orient(EnDog* pthis, GlobalContext* globalCtx) {
    s16 targetYaw;
    f32 waypointDistSq;

    waypointDistSq = Path_OrientAndGetDistSq(&pthis->actor, pthis->path, pthis->waypoint, &targetYaw);
    Math_SmoothStepToS(&pthis->actor.world.rot.y, targetYaw, 10, 1000, 1);

    if ((waypointDistSq > 0.0f) && (waypointDistSq < 1000.0f)) {
        return EnDog_UpdateWaypoint(pthis, globalCtx);
    } else {
        return 0;
    }
}

void EnDog_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* pthis = (EnDog*)thisx;
    s16 followingDog;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDogSkel, NULL, pthis->jointTable, pthis->morphTable, 13);
    func_80034EC0(&pthis->skelAnime, sAnimations, 0);

    if ((pthis->actor.params & 0x8000) == 0) {
        pthis->actor.params = (pthis->actor.params & 0xF0FF) | ((((pthis->actor.params & 0x0F00) >> 8) + 1) << 8);
    }

    followingDog = ((gSaveContext.dogParams & 0x0F00) >> 8);
    if (followingDog == ((pthis->actor.params & 0x0F00) >> 8) && ((pthis->actor.params & 0x8000) == 0)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, 0, &sColChkInfoInit);
    Actor_SetScale(&pthis->actor, 0.0075f);
    pthis->waypoint = 0;
    pthis->actor.gravity = -1.0f;
    pthis->path = Path_GetByIndex(globalCtx, (pthis->actor.params & 0x00F0) >> 4, 0xF);

    switch (globalCtx->sceneNum) {
        case SCENE_MARKET_NIGHT:
            if ((!gSaveContext.dogIsLost) && (((pthis->actor.params & 0x0F00) >> 8) == 1)) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case SCENE_IMPA: // Richard's Home
            if (!(pthis->actor.params & 0x8000)) {
                if (!gSaveContext.dogIsLost) {
                    pthis->nextBehavior = DOG_SIT;
                    pthis->actionFunc = EnDog_Wait;
                    pthis->actor.speedXZ = 0.0f;
                    return;
                } else {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            }
            break;
    }

    if (pthis->actor.params & 0x8000) {
        pthis->nextBehavior = DOG_WALK;
        pthis->actionFunc = EnDog_FollowPlayer;
    } else {
        pthis->nextBehavior = DOG_SIT;
        pthis->actionFunc = EnDog_ChooseMovement;
    }
}

void EnDog_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* pthis = (EnDog*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnDog_FollowPath(EnDog* pthis, GlobalContext* globalCtx) {
    s32 behaviors[] = { DOG_SIT, DOG_BOW, DOG_BARK };
    s32 unused[] = { 40, 80, 20 };
    f32 speed;
    s32 frame;

    if (EnDog_CanFollow(pthis, globalCtx) == 1) {
        pthis->actionFunc = EnDog_FollowPlayer;
    }

    if (DECR(pthis->behaviorTimer) != 0) {
        if (pthis->nextBehavior == DOG_WALK) {
            speed = 1.0f;
        } else {
            speed = 4.0f;
        }
        Math_SmoothStepToF(&pthis->actor.speedXZ, speed, 0.4f, 1.0f, 0.0f);
        EnDog_Orient(pthis, globalCtx);
        pthis->actor.shape.rot = pthis->actor.world.rot;

        // Used to change between two text boxes for Richard's owner in the Market Day scene
        // depending on where he is on his path. En_Hy checks these event flags.
        if (pthis->waypoint < 9) {
            // Richard is close to her, text says something about his coat
            gSaveContext.eventInf[3] |= 1;
        } else {
            // Richard is far, text says something about running fast
            gSaveContext.eventInf[3] &= ~1;
        }
    } else {
        frame = globalCtx->state.frames % 3;
        pthis->nextBehavior = behaviors[frame];
        // no clue why they're using the behavior id to calculate timer. possibly meant to use the unused array?
        pthis->behaviorTimer = Rand_S16Offset(60, behaviors[frame]);
        pthis->actionFunc = EnDog_ChooseMovement;
    }
}

void EnDog_ChooseMovement(EnDog* pthis, GlobalContext* globalCtx) {
    if (EnDog_CanFollow(pthis, globalCtx) == 1) {
        pthis->actionFunc = EnDog_FollowPlayer;
    }

    if (DECR(pthis->behaviorTimer) == 0) {
        pthis->behaviorTimer = Rand_S16Offset(200, 100);
        if (globalCtx->state.frames % 2) {
            pthis->nextBehavior = DOG_WALK;
        } else {
            pthis->nextBehavior = DOG_RUN;
        }

        if (pthis->nextBehavior == DOG_RUN) {
            pthis->behaviorTimer /= 2;
        }
        pthis->actionFunc = EnDog_FollowPath;
    }
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.4f, 1.0f, 0.0f);
}

void EnDog_FollowPlayer(EnDog* pthis, GlobalContext* globalCtx) {
    f32 speed;

    if (gSaveContext.dogParams == 0) {
        pthis->nextBehavior = DOG_SIT;
        pthis->actionFunc = EnDog_Wait;
        pthis->actor.speedXZ = 0.0f;
        return;
    }

    if (pthis->actor.xzDistToPlayer > 400.0f) {
        if (pthis->nextBehavior != DOG_SIT && pthis->nextBehavior != DOG_SIT_2) {
            pthis->nextBehavior = DOG_BOW;
        }
        gSaveContext.dogParams = 0;
        speed = 0.0f;
    } else if (pthis->actor.xzDistToPlayer > 100.0f) {
        pthis->nextBehavior = DOG_RUN;
        speed = 4.0f;
    } else if (pthis->actor.xzDistToPlayer < 40.0f) {
        if (pthis->nextBehavior != DOG_BOW && pthis->nextBehavior != DOG_BOW_2) {
            pthis->nextBehavior = DOG_BOW;
        }
        speed = 0.0f;
    } else {
        pthis->nextBehavior = DOG_WALK;
        speed = 1.0f;
    }

    Math_ApproachF(&pthis->actor.speedXZ, speed, 0.6f, 1.0f);

    if (!(pthis->actor.xzDistToPlayer > 400.0f)) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 10, 1000, 1);
        pthis->actor.shape.rot = pthis->actor.world.rot;
    }
}

void EnDog_RunAway(EnDog* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer < 200.0f) {
        Math_ApproachF(&pthis->actor.speedXZ, 4.0f, 0.6f, 1.0f);
        Math_SmoothStepToS(&pthis->actor.world.rot.y, (pthis->actor.yawTowardsPlayer ^ 0x8000), 10, 1000, 1);
    } else {
        pthis->actionFunc = EnDog_FaceLink;
    }
    pthis->actor.shape.rot = pthis->actor.world.rot;
}

void EnDog_FaceLink(EnDog* pthis, GlobalContext* globalCtx) {
    s16 rotTowardLink;
    s16 prevRotY;
    f32 absAngleDiff;

    // if the dog is more than 200 units away from Link, turn to face him then wait
    if (200.0f <= pthis->actor.xzDistToPlayer) {
        pthis->nextBehavior = DOG_WALK;

        Math_ApproachF(&pthis->actor.speedXZ, 1.0f, 0.6f, 1.0f);

        rotTowardLink = pthis->actor.yawTowardsPlayer;
        prevRotY = pthis->actor.world.rot.y;
        Math_SmoothStepToS(&pthis->actor.world.rot.y, rotTowardLink, 10, 1000, 1);

        absAngleDiff = pthis->actor.world.rot.y;
        absAngleDiff -= prevRotY;
        absAngleDiff = fabsf(absAngleDiff);
        if (absAngleDiff < 200.0f) {
            pthis->nextBehavior = DOG_SIT;
            pthis->actionFunc = EnDog_Wait;
            pthis->actor.speedXZ = 0.0f;
        }
    } else {
        pthis->nextBehavior = DOG_RUN;
        pthis->actionFunc = EnDog_RunAway;
    }
    pthis->actor.shape.rot = pthis->actor.world.rot;
}

void EnDog_Wait(EnDog* pthis, GlobalContext* globalCtx) {
    pthis->unusedAngle = (pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y);

    // If another dog is following Link and he gets within 200 units of waiting dog, run away
    if ((gSaveContext.dogParams != 0) && (pthis->actor.xzDistToPlayer < 200.0f)) {
        pthis->nextBehavior = DOG_RUN;
        pthis->actionFunc = EnDog_RunAway;
    }
}

void EnDog_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* pthis = (EnDog*)thisx;
    s32 pad;

    EnDog_PlayAnimAndSFX(pthis);
    SkelAnime_Update(&pthis->skelAnime);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, pthis->collider.dim.radius, pthis->collider.dim.height * 0.5f, 0.0f,
                            5);
    Actor_MoveForward(&pthis->actor);
    pthis->actionFunc(pthis, globalCtx);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnDog_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    return false;
}

void EnDog_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
}

void EnDog_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDog* pthis = (EnDog*)thisx;
    Color_RGBA8 colors[] = { { 255, 255, 200, 0 }, { 150, 100, 50, 0 } };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dog.c", 972);

    func_80093D18(globalCtx->state.gfxCtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, colors[pthis->actor.params & 0xF].r, colors[pthis->actor.params & 0xF].g,
                   colors[pthis->actor.params & 0xF].b, colors[pthis->actor.params & 0xF].a);

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDog_OverrideLimbDraw, EnDog_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dog.c", 994);
}

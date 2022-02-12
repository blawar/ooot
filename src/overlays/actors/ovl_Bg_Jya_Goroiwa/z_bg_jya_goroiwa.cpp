#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_GOROIWA_Z_BG_JYA_GOROIWA_C
#include "actor_common.h"
/*
 *  File: z_bg_jya_goroiwa.c
 *  Overlay: ovl_Bg_Jya_Goroiwa
 *  Description: Rolling Boulder
 *  moves very slowly in some cases
 */

#include "z_bg_jya_goroiwa.h"
#include "objects/object_goroiwa/object_goroiwa.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void BgJyaGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJyaGoroiwa_Wait(BgJyaGoroiwa* pthis, GlobalContext* globalCtx);
void BgJyaGoroiwa_Move(BgJyaGoroiwa* pthis, GlobalContext* globalCtx);

void BgJyaGoroiwa_SetupWait(BgJyaGoroiwa* pthis);
void BgJyaGoroiwa_SetupMove(BgJyaGoroiwa* pthis);
void BgJyaGoroiwa_UpdateRotation(BgJyaGoroiwa* pthis);
void BgJyaGoroiwa_UpdateCollider(BgJyaGoroiwa* pthis);

ActorInit Bg_Jya_Goroiwa_InitVars = {
    ACTOR_BG_JYA_GOROIWA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GOROIWA,
    sizeof(BgJyaGoroiwa),
    (ActorFunc)BgJyaGoroiwa_Init,
    (ActorFunc)BgJyaGoroiwa_Destroy,
    (ActorFunc)BgJyaGoroiwa_Update,
    (ActorFunc)BgJyaGoroiwa_Draw,
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

static CollisionCheckInfoInit sColChkInfoInit = { 1, 15, 0, MASS_HEAVY };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgJyaGoroiwa_UpdateCollider(BgJyaGoroiwa* pthis) {
    Sphere16* worldSphere = &pthis->collider.elements[0].dim.worldSphere;

    worldSphere->center.x = pthis->actor.world.pos.x;
    worldSphere->center.y = pthis->actor.world.pos.y + 59.5f;
    worldSphere->center.z = pthis->actor.world.pos.z;
}

void BgJyaGoroiwa_InitCollider(BgJyaGoroiwa* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, &pthis->colliderItem);
    BgJyaGoroiwa_UpdateCollider(pthis);
    pthis->collider.elements[0].dim.worldSphere.radius = 58;
}

void BgJyaGoroiwa_UpdateRotation(BgJyaGoroiwa* pthis) {
    f32 xDiff = pthis->actor.world.pos.x - pthis->actor.prevPos.x;

    pthis->actor.shape.rot.z -= 0x10000 / (119 * M_PI) * xDiff;
}

void BgJyaGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaGoroiwa* pthis = (BgJyaGoroiwa*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    BgJyaGoroiwa_InitCollider(pthis, globalCtx);
    pthis->actor.shape.rot.x = pthis->actor.shape.rot.y = pthis->actor.shape.rot.z = 0;
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    ActorShape_Init(&pthis->actor.shape, 595.0f, ActorShadow_DrawCircle, 9.0f);
    pthis->actor.shape.shadowAlpha = 128;
    BgJyaGoroiwa_SetupMove(pthis);
}

void BgJyaGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaGoroiwa* pthis = (BgJyaGoroiwa*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void BgJyaGoroiwa_SetupMove(BgJyaGoroiwa* pthis) {
    pthis->actionFunc = BgJyaGoroiwa_Move;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->hasHit = false;
    pthis->speedFactor = 1.0f;
}

void BgJyaGoroiwa_Move(BgJyaGoroiwa* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->actor;
    s16 relYawTowardsPlayer;
    f32 speedXZsqBase = (-100.0f - thisx->world.pos.y) * 2.5f;
    f32 posYfac;

    if (speedXZsqBase < 0.01f) {
        speedXZsqBase = 0.01f;
    }

    thisx->speedXZ = sqrtf(speedXZsqBase) * pthis->speedFactor;
    thisx->velocity.x = Math_SinS(thisx->world.rot.y) * thisx->speedXZ;
    thisx->velocity.z = Math_CosS(thisx->world.rot.y) * thisx->speedXZ;

    thisx->world.pos.x = thisx->world.pos.x + thisx->velocity.x;
    thisx->world.pos.z = thisx->world.pos.z + thisx->velocity.z;

    if ((thisx->world.pos.x > 1466.0f) && (thisx->world.pos.x < 1673.0f)) {
        thisx->world.pos.y = -129.5f;
    } else {
        posYfac = 1569.0f - thisx->world.pos.x;
        posYfac = fabsf(posYfac) - 103.0f;
        thisx->world.pos.y = ((35.0f / 92.0f) * posYfac) - 129.5f;
    }

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT & ~AT_ON;

        relYawTowardsPlayer = thisx->yawTowardsPlayer - thisx->world.rot.y;
        if ((relYawTowardsPlayer > -0x4000) && (relYawTowardsPlayer < 0x4000)) {
            thisx->world.rot.y += 0x8000;
        }

        func_8002F6D4(globalCtx, thisx, 2.0f, thisx->yawTowardsPlayer, 0.0f, 0);
        func_8002F7DC(&GET_PLAYER(globalCtx)->actor, NA_SE_PL_BODY_HIT);

        pthis->yOffsetSpeed = 10.0f;
        pthis->speedFactor = 0.5f;
        pthis->hasHit = true;
    }

    if (pthis->hasHit) {
        pthis->yOffsetSpeed -= 1.5f;
        thisx->shape.yOffset += pthis->yOffsetSpeed * 10.0f;
        if (thisx->shape.yOffset < 595.0f) {
            thisx->shape.yOffset = 595.0f;
            BgJyaGoroiwa_SetupWait(pthis);
        }
    } else {
        Math_StepToF(&pthis->speedFactor, 1.0f, 0.04f);
    }

    if (thisx->world.pos.x > 1745.0f) {
        thisx->world.rot.y = -0x4000;
    } else if (thisx->world.pos.x < 1393.0f) {
        thisx->world.rot.y = 0x4000;
    }

    Audio_PlayActorSound2(thisx, NA_SE_EV_BIGBALL_ROLL - SFX_FLAG);
}

void BgJyaGoroiwa_SetupWait(BgJyaGoroiwa* pthis) {
    pthis->actionFunc = BgJyaGoroiwa_Wait;
    pthis->waitTimer = 0;
}

void BgJyaGoroiwa_Wait(BgJyaGoroiwa* pthis, GlobalContext* globalCtx) {
    pthis->waitTimer++;
    if (pthis->waitTimer > 60) {
        BgJyaGoroiwa_SetupMove(pthis);
        pthis->speedFactor = 0.1f;
    }
}

void BgJyaGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgJyaGoroiwa* pthis = (BgJyaGoroiwa*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s32 bgId;
    Vec3f pos;

    if (!(player->stateFlags1 & 0x300000C0)) {
        pthis->actionFunc(pthis, globalCtx);
        BgJyaGoroiwa_UpdateRotation(pthis);
        pos.x = pthis->actor.world.pos.x;
        pos.y = pthis->actor.world.pos.y + 59.5f;
        pos.z = pthis->actor.world.pos.z;
        pthis->actor.floorHeight =
            BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId, &pthis->actor, &pos);
        BgJyaGoroiwa_UpdateCollider(pthis);
        if (pthis->collider.base.atFlags & AT_ON) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgJyaGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gRollingRockDL);
}

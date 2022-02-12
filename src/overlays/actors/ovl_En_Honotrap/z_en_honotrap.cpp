#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HONOTRAP_Z_EN_HONOTRAP_C
#include "actor_common.h"
/**
 * File: z_en_honotrap.c
 * Overlay: ovl_En_Honotrap
 * Description: Fake eye switches and Dampe flames
 */

#include "z_en_honotrap.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

#define HONOTRAP_AT_ACTIVE (1 << 0)
#define HONOTRAP_AC_ACTIVE (1 << 1)
#define HONOTRAP_OC_ACTIVE (1 << 2)

typedef enum {
    /* 0 */ HONOTRAP_EYE_OPEN,
    /* 1 */ HONOTRAP_EYE_HALF,
    /* 2 */ HONOTRAP_EYE_CLOSE,
    /* 3 */ HONOTRAP_EYE_SHUT
} EnHonotrapEyeState;

void EnHonotrap_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHonotrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHonotrap_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHonotrap_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHonotrap_SetupEyeIdle(EnHonotrap* pthis);
void EnHonotrap_EyeIdle(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupEyeOpen(EnHonotrap* pthis);
void EnHonotrap_EyeOpen(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupEyeAttack(EnHonotrap* pthis);
void EnHonotrap_EyeAttack(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupEyeClose(EnHonotrap* pthis);
void EnHonotrap_EyeClose(EnHonotrap* pthis, GlobalContext* globalCtx);

void EnHonotrap_SetupFlame(EnHonotrap* pthis);
void EnHonotrap_Flame(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupFlameDrop(EnHonotrap* pthis);
void EnHonotrap_FlameDrop(EnHonotrap* pthis, GlobalContext* globalCtx);

void EnHonotrap_SetupFlameMove(EnHonotrap* pthis);
void EnHonotrap_FlameMove(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupFlameChase(EnHonotrap* pthis);
void EnHonotrap_FlameChase(EnHonotrap* pthis, GlobalContext* globalCtx);
void EnHonotrap_SetupFlameVanish(EnHonotrap* pthis);
void EnHonotrap_FlameVanish(EnHonotrap* pthis, GlobalContext* globalCtx);

ActorInit En_Honotrap_InitVars = {
    ACTOR_EN_HONOTRAP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(EnHonotrap),
    (ActorFunc)EnHonotrap_Init,
    (ActorFunc)EnHonotrap_Destroy,
    (ActorFunc)EnHonotrap_Update,
    (ActorFunc)EnHonotrap_Draw,
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK4,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F824, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 0.0f, 23.0f, 8.5f }, { -23.0f, 0.0f, 8.5f }, { 0.0f, -23.0f, 8.5f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F824, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 0.0f, 23.0f, 8.5f }, { 0.0f, -23.0f, 8.5f }, { 23.0f, 0.0f, 8.5f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    2,
    sTrisElementsInit,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x04 },
        { 0x00100000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 10, 25, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 9, 23, 1 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void EnHonotrap_FlameCollisionCheck(EnHonotrap* pthis, GlobalContext* globalCtx) {
    s32 pad[3];

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider.cyl);
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.cyl.base);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.cyl.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.cyl.base);
    pthis->colChkFlags |= HONOTRAP_AT_ACTIVE;
    pthis->colChkFlags |= HONOTRAP_AC_ACTIVE;
    pthis->colChkFlags |= HONOTRAP_OC_ACTIVE;
}

void EnHonotrap_GetNormal(Vec3f* normal, Vec3f* vec) {
    f32 mag = Math3D_Vec3fMagnitude(vec);

    if (mag < 0.001f) {
        osSyncPrintf("Warning : vector size zero (%s %d)\n", "../z_en_honotrap.c", 328, normal);

        normal->x = normal->y = 0.0f;
        normal->z = 1.0f;
    } else {
        normal->x = vec->x * (1.0f / mag);
        normal->y = vec->y * (1.0f / mag);
        normal->z = vec->z * (1.0f / mag);
    }
}

void EnHonotrap_InitEye(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHonotrap* pthis = (EnHonotrap*)thisx;
    s32 i;
    s32 j;
    Vec3f* vtx;
    Vec3f triangle[3];
    f32 cos;
    f32 sin;

    Actor_SetScale(thisx, 0.1f);
    sin = Math_SinS(thisx->home.rot.y);
    cos = Math_CosS(thisx->home.rot.y);
    Collider_InitTris(globalCtx, &pthis->collider.tris);
    Collider_SetTris(globalCtx, &pthis->collider.tris, thisx, &sTrisInit, pthis->collider.elements);

    for (i = 0; i < 2; i++) {
        for (j = 0, vtx = triangle; j < 3; j++, vtx++) {
            Vec3f* baseVtx = &sTrisInit.elements[i].dim.vtx[j];

            vtx->x = baseVtx->z * sin + baseVtx->x * cos;
            vtx->y = baseVtx->y;
            vtx->z = baseVtx->z * cos - baseVtx->x * sin;
            Math_Vec3f_Sum(vtx, &thisx->world.pos, vtx);
        }
        Collider_SetTrisVertices(&pthis->collider.tris, i, &triangle[0], &triangle[1], &triangle[2]);
    }
    EnHonotrap_SetupEyeIdle(pthis);
    Actor_SetFocus(thisx, 0.0f);
}

void EnHonotrap_InitFlame(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHonotrap* pthis = (EnHonotrap*)thisx;

    Actor_SetScale(&pthis->actor, 0.0001f);
    Collider_InitCylinder(globalCtx, &pthis->collider.cyl);
    Collider_SetCylinder(globalCtx, &pthis->collider.cyl, &pthis->actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider.cyl);
    pthis->actor.minVelocityY = -1.0f;
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->actor.shape.shadowAlpha = 128;
    pthis->targetPos = GET_PLAYER(globalCtx)->actor.world.pos;
    pthis->targetPos.y += 10.0f;
    pthis->flameScroll = Rand_ZeroOne() * 511.0f;
    EnHonotrap_SetupFlame(pthis);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FLAME_IGNITION);
    if (pthis->actor.params == HONOTRAP_FLAME_DROP) {
        pthis->actor.room = -1;
        pthis->collider.cyl.dim.radius = 12;
        pthis->collider.cyl.dim.height = 30;
        pthis->actor.shape.yOffset = -1000.0f;
    }
}

void EnHonotrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    Actor_ProcessInitChain(thisx, sInitChain);
    if (thisx->params == HONOTRAP_EYE) {
        EnHonotrap_InitEye(thisx, globalCtx);
    } else {
        EnHonotrap_InitFlame(thisx, globalCtx);
    }
}

void EnHonotrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHonotrap* pthis = (EnHonotrap*)thisx;

    if (pthis->actor.params == HONOTRAP_EYE) {
        Collider_DestroyTris(globalCtx, &pthis->collider.tris);
    } else {
        Collider_DestroyCylinder(globalCtx, &pthis->collider.cyl);
    }
}

void EnHonotrap_SetupEyeIdle(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_EyeIdle;
    pthis->eyeState = HONOTRAP_EYE_SHUT;
}

void EnHonotrap_EyeIdle(EnHonotrap* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.child != NULL) {
        pthis->timer = 200;
    } else if ((pthis->timer <= 0) && (pthis->actor.xzDistToPlayer < 750.0f) && (0.0f > pthis->actor.yDistToPlayer) &&
               (pthis->actor.yDistToPlayer > -700.0f) &&
               (-0x4000 < (pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) &&
               ((pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) < 0x4000)) {
        EnHonotrap_SetupEyeOpen(pthis);
    }
}

void EnHonotrap_SetupEyeOpen(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_EyeOpen;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x28);
    pthis->timer = 30;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_RED_EYE);
}

void EnHonotrap_EyeOpen(EnHonotrap* pthis, GlobalContext* globalCtx) {
    f32 cos;
    f32 sin;

    pthis->eyeState--;
    if (pthis->eyeState <= HONOTRAP_EYE_OPEN) {
        EnHonotrap_SetupEyeAttack(pthis);
        sin = Math_SinS(pthis->actor.shape.rot.y);
        cos = Math_CosS(pthis->actor.shape.rot.y);
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_HONOTRAP,
                           (sin * 12.0f) + pthis->actor.home.pos.x, pthis->actor.home.pos.y - 10.0f,
                           (cos * 12.0f) + pthis->actor.home.pos.z, pthis->actor.home.rot.x, pthis->actor.home.rot.y,
                           pthis->actor.home.rot.z, HONOTRAP_FLAME_MOVE);
    }
}

void EnHonotrap_SetupEyeAttack(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_EyeAttack;
    pthis->eyeState = HONOTRAP_EYE_OPEN;
}

void EnHonotrap_EyeAttack(EnHonotrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer <= 0) {
        EnHonotrap_SetupEyeClose(pthis);
    }
}

void EnHonotrap_SetupEyeClose(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_EyeClose;
}

void EnHonotrap_EyeClose(EnHonotrap* pthis, GlobalContext* globalCtx) {
    pthis->eyeState++;
    if (pthis->eyeState >= HONOTRAP_EYE_SHUT) {
        EnHonotrap_SetupEyeIdle(pthis);
        pthis->timer = 200;
    }
}

void EnHonotrap_SetupFlame(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_Flame;
}

void EnHonotrap_Flame(EnHonotrap* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 ready =
        Math_StepToF(&pthis->actor.scale.x, (pthis->actor.params == HONOTRAP_FLAME_MOVE) ? 0.004f : 0.0048f, 0.0006f);

    pthis->actor.scale.z = pthis->actor.scale.y = pthis->actor.scale.x;
    if (ready) {
        if (pthis->actor.params == HONOTRAP_FLAME_MOVE) {
            EnHonotrap_SetupFlameMove(pthis);
        } else {
            EnHonotrap_SetupFlameDrop(pthis);
        }
    }
}

void EnHonotrap_SetupFlameDrop(EnHonotrap* pthis) {
    pthis->timer = 40;
    pthis->actor.velocity.y = 1.0f;
    pthis->actor.velocity.x = 2.0f * Math_SinS(pthis->actor.world.rot.y);
    pthis->actor.velocity.z = 2.0f * Math_CosS(pthis->actor.world.rot.y);
    pthis->actionFunc = EnHonotrap_FlameDrop;
}

void EnHonotrap_FlameDrop(EnHonotrap* pthis, GlobalContext* globalCtx) {
    if ((pthis->collider.cyl.base.atFlags & AT_HIT) || (pthis->timer <= 0)) {
        if ((pthis->collider.cyl.base.atFlags & AT_HIT) && !(pthis->collider.cyl.base.atFlags & AT_BOUNCED)) {
            func_8002F71C(globalCtx, &pthis->actor, 5.0f, pthis->actor.yawTowardsPlayer, 0.0f);
        }
        pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = 0.0f;
        EnHonotrap_SetupFlameVanish(pthis);
    } else {
        if (pthis->actor.velocity.y > 0.0f) {
            pthis->actor.world.pos.x += pthis->actor.velocity.x;
            pthis->actor.world.pos.z += pthis->actor.velocity.z;
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.0f, 12.0f, 0.0f, 5);
        }
        if (!Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 1.0f, pthis->actor.velocity.y)) {
            pthis->actor.velocity.y += 1.0f;
        } else {
            pthis->actor.velocity.y = 0.0f;
        }
        EnHonotrap_FlameCollisionCheck(pthis, globalCtx);
    }
}

void EnHonotrap_SetupFlameMove(EnHonotrap* pthis) {
    f32 distFrac;

    pthis->actionFunc = EnHonotrap_FlameMove;

    distFrac = 1.0f / (Actor_WorldDistXYZToPoint(&pthis->actor, &pthis->targetPos) + 1.0f);
    pthis->actor.velocity.x = (pthis->targetPos.x - pthis->actor.world.pos.x) * distFrac;
    pthis->actor.velocity.y = (pthis->targetPos.y - pthis->actor.world.pos.y) * distFrac;
    pthis->actor.velocity.z = (pthis->targetPos.z - pthis->actor.world.pos.z) * distFrac;
    pthis->speedMod = 0.0f;

    pthis->timer = 160;
}

void EnHonotrap_FlameMove(EnHonotrap* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f speed;
    s32 ready;

    Math_StepToF(&pthis->speedMod, 13.0f, 0.5f);
    speed.x = fabsf(pthis->speedMod * pthis->actor.velocity.x);
    speed.y = fabsf(pthis->speedMod * pthis->actor.velocity.y);
    speed.z = fabsf(pthis->speedMod * pthis->actor.velocity.z);
    ready = true;
    ready &= Math_StepToF(&pthis->actor.world.pos.x, pthis->targetPos.x, speed.x);
    ready &= Math_StepToF(&pthis->actor.world.pos.y, pthis->targetPos.y, speed.y);
    ready &= Math_StepToF(&pthis->actor.world.pos.z, pthis->targetPos.z, speed.z);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.0f, 10.0f, 0.0f, 0x1D);

    if (pthis->collider.tris.base.atFlags & AT_BOUNCED) {
        Player* player = GET_PLAYER(globalCtx);
        Vec3f shieldNorm;
        Vec3f tempVel;
        Vec3f shieldVec;

        shieldVec.x = -player->shieldMf.xz;
        shieldVec.y = -player->shieldMf.yz;
        shieldVec.z = -player->shieldMf.zz;
        EnHonotrap_GetNormal(&shieldNorm, &shieldVec);

        tempVel = pthis->actor.velocity;
        Math3D_Vec3fReflect(&tempVel, &shieldNorm, &pthis->actor.velocity);
        pthis->actor.speedXZ = pthis->speedMod * 0.5f;
        pthis->actor.world.rot.y = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);
        EnHonotrap_SetupFlameVanish(pthis);
    } else if (pthis->collider.tris.base.atFlags & AT_HIT) {
        pthis->actor.velocity.y = pthis->actor.speedXZ = 0.0f;
        EnHonotrap_SetupFlameVanish(pthis);
    } else if (pthis->timer <= 0) {
        EnHonotrap_SetupFlameVanish(pthis);
    } else {
        EnHonotrap_FlameCollisionCheck(pthis, globalCtx);
        if (ready) {
            EnHonotrap_SetupFlameChase(pthis);
        }
    }
}

void EnHonotrap_SetupFlameChase(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_FlameChase;

    pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.x = pthis->actor.world.rot.y = pthis->actor.world.rot.z = 0;

    pthis->timer = 100;
}

void EnHonotrap_FlameChase(EnHonotrap* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0x300);
    Math_StepToF(&pthis->actor.speedXZ, 3.0f, 0.1f);
    pthis->actor.gravity = (-pthis->actor.yDistToPlayer < 10.0f) ? 0.08f : -0.08f;
    func_8002D868(&pthis->actor);
    if (pthis->actor.velocity.y > 1.0f) {
        pthis->actor.velocity.y = 1.0f;
    }
    pthis->actor.velocity.y *= 0.95f;
    func_8002D7EC(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.0f, 10.0f, 0.0f, 0x1D);
    if (pthis->collider.cyl.base.atFlags & AT_BOUNCED) {
        Player* player = GET_PLAYER(globalCtx);
        Vec3s shieldRot;

        Matrix_MtxFToYXZRotS(&player->shieldMf, &shieldRot, false);
        pthis->actor.world.rot.y = ((shieldRot.y * 2) - pthis->actor.world.rot.y) + 0x8000;
        EnHonotrap_SetupFlameVanish(pthis);
    } else if (pthis->collider.cyl.base.atFlags & AT_HIT) {
        pthis->actor.speedXZ *= 0.1f;
        pthis->actor.velocity.y *= 0.1f;
        EnHonotrap_SetupFlameVanish(pthis);
    } else if ((pthis->actor.bgCheckFlags & 8) || (pthis->timer <= 0)) {
        EnHonotrap_SetupFlameVanish(pthis);
    } else {
        EnHonotrap_FlameCollisionCheck(pthis, globalCtx);
    }
}

void EnHonotrap_SetupFlameVanish(EnHonotrap* pthis) {
    pthis->actionFunc = EnHonotrap_FlameVanish;
}

void EnHonotrap_FlameVanish(EnHonotrap* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 ready = Math_StepToF(&pthis->actor.scale.x, 0.0001f, 0.00015f);

    pthis->actor.scale.z = pthis->actor.scale.y = pthis->actor.scale.x;
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.0f, 10.0f, 0.0f, 0x1D);
    if (ready) {
        Actor_Kill(&pthis->actor);
    }
}

void EnHonotrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    static Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    static Vec3f accel = { 0.0f, 0.1f, 0.0f };
    s32 pad;
    EnHonotrap* pthis = (EnHonotrap*)thisx;

    if (pthis->timer > 0) {
        pthis->timer--;
    }
    if (pthis->actor.params == HONOTRAP_EYE) {
        if ((pthis->actor.child != NULL) && (pthis->actor.child->update == NULL)) {
            pthis->actor.child = NULL;
        }
    } else {
        pthis->colChkFlags = 0;
        pthis->bobPhase += 0x640;
        pthis->actor.shape.yOffset = (Math_SinS(pthis->bobPhase) * 1000.0f) + 600.0f;
        Actor_SetFocus(&pthis->actor, 5.0f);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_BURN_OUT - SFX_FLAG);
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actor.params == HONOTRAP_EYE) {
        if (pthis->collider.tris.base.acFlags & AC_HIT) {
            EffectSsBomb2_SpawnLayered(globalCtx, &pthis->actor.world.pos, &velocity, &accel, 15, 8);
            Actor_Kill(&pthis->actor);
        } else if (pthis->eyeState < HONOTRAP_EYE_SHUT) {
            pthis->collider.tris.base.acFlags &= ~AC_HIT;
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.tris.base);
        }
    }
}

void EnHonotrap_DrawEye(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = {
        gEyeSwitchSilverOpenTex,
        gEyeSwitchSilverHalfTex,
        gEyeSwitchSilverClosedTex,
        gEyeSwitchSilverClosedTex,
    };
    EnHonotrap* pthis = (EnHonotrap*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 982);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeState]));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 987),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gEyeSwitch2DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 991);
}

void EnHonotrap_DrawFlame(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnHonotrap* pthis = (EnHonotrap*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 1000);

    func_80093D84(globalCtx->state.gfxCtx);
    pthis->flameScroll -= 20;
    pthis->flameScroll &= 0x1FF;
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, pthis->flameScroll, 0x20, 0x80));
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 200, 0, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - pthis->actor.shape.rot.y + 0x8000) *
                       (M_PI / 0x8000),
                   MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 1024),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_honotrap.c", 1028);
}

void EnHonotrap_Draw(Actor* thisx, GlobalContext* globalCtx) {
    switch (thisx->params) {
        case HONOTRAP_EYE:
            EnHonotrap_DrawEye(thisx, globalCtx);
            break;
        case HONOTRAP_FLAME_MOVE:
        case HONOTRAP_FLAME_DROP:
            EnHonotrap_DrawFlame(thisx, globalCtx);
            break;
    }
}

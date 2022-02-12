#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT08_ICEBLOCK_Z_BG_SPOT08_ICEBLOCK_C
#include "actor_common.h"
/*
 * File: z_bg_spot08_iceblock.c
 * Overlay: ovl_Bg_Spot08_Iceblock
 * Description: Floating ice platforms
 */

#include "z_bg_spot08_iceblock.h"
#include "objects/object_spot08_obj/object_spot08_obj.h"
#include "def/code_80043480.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS 0

void BgSpot08Iceblock_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot08Iceblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgSpot08Iceblock_SetupFloatNonrotating(BgSpot08Iceblock* pthis);
void BgSpot08Iceblock_FloatNonrotating(BgSpot08Iceblock* pthis, GlobalContext* globalCtx);
void BgSpot08Iceblock_SetupFloatRotating(BgSpot08Iceblock* pthis);
void BgSpot08Iceblock_FloatRotating(BgSpot08Iceblock* pthis, GlobalContext* globalCtx);
void BgSpot08Iceblock_SetupFloatOrbitingTwins(BgSpot08Iceblock* pthis);
void BgSpot08Iceblock_FloatOrbitingTwins(BgSpot08Iceblock* pthis, GlobalContext* globalCtx);
void BgSpot08Iceblock_SetupNoAction(BgSpot08Iceblock* pthis);

ActorInit Bg_Spot08_Iceblock_InitVars = {
    ACTOR_BG_SPOT08_ICEBLOCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT08_OBJ,
    sizeof(BgSpot08Iceblock),
    (ActorFunc)BgSpot08Iceblock_Init,
    (ActorFunc)BgSpot08Iceblock_Destroy,
    (ActorFunc)BgSpot08Iceblock_Update,
    (ActorFunc)BgSpot08Iceblock_Draw,
};

void BgSpot08Iceblock_SetupAction(BgSpot08Iceblock* pthis, BgSpot08IceblockActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgSpot08Iceblock_InitDynaPoly(BgSpot08Iceblock* pthis, GlobalContext* globalCtx, CollisionHeader* collision,
                                   s32 flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning: move BG registration failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot08_iceblock.c", 0xD9,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

// Sets params to 0x10 (medium, nonrotating) if not in the cases listed.
void BgSpot08Iceblock_CheckParams(BgSpot08Iceblock* pthis) {
    switch (pthis->dyna.actor.params & 0xFF) {
        case 0xFF:
            pthis->dyna.actor.params = 0x10;
            break;
        default:
            // "Error: arg_data setting error"
            osSyncPrintf("Error : arg_data 設定ミスです。(%s %d)(arg_data 0x%04x)\n", "../z_bg_spot08_iceblock.c", 0xF6,
                         pthis->dyna.actor.params);
            pthis->dyna.actor.params = 0x10;
            break;
        case 1:
        case 4:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x14:
        case 0x20:
        case 0x23:
        case 0x24:
            break;
    }
}

void BgSpot08Iceblock_Bobbing(BgSpot08Iceblock* pthis) {
    pthis->bobOffset = (Math_SinS(pthis->bobPhaseSlow) * 4.0f) + (Math_SinS(pthis->bobPhaseFast) * 3.0f);
}

void BgSpot08Iceblock_SinkUnderPlayer(BgSpot08Iceblock* pthis) {
    f32 target;
    f32 step;

    switch (pthis->dyna.actor.params & 0xF0) {
        case 0:
            step = 0.15f;
            break;
        case 0x10:
            step = 0.2f;
            break;
        case 0x20:
            step = 0.4f;
            break;
    }

    // Sink under Player's weight if standing on it
    target = (func_80043548(&pthis->dyna) ? -4.0f : 0.0f);

    Math_StepToF(&pthis->sinkOffset, target, step);
}

void BgSpot08Iceblock_SetWaterline(BgSpot08Iceblock* pthis) {
    pthis->dyna.actor.world.pos.y = pthis->sinkOffset + pthis->bobOffset + pthis->dyna.actor.home.pos.y;
}

void BgSpot08Iceblock_MultVectorScalar(Vec3f* dest, Vec3f* v, f32 scale) {
    dest->x = v->x * scale;
    dest->y = v->y * scale;
    dest->z = v->z * scale;
}

void BgSpot08Iceblock_CrossProduct(Vec3f* dest, Vec3f* v1, Vec3f* v2) {
    dest->x = (v1->y * v2->z) - (v1->z * v2->y);
    dest->y = (v1->z * v2->x) - (v1->x * v2->z);
    dest->z = (v1->x * v2->y) - (v1->y * v2->x);
}

s32 BgSpot08Iceblock_NormalizeVector(Vec3f* dest, Vec3f* v) {
    f32 magnitude;

    magnitude = Math3D_Vec3fMagnitude(v);
    if (magnitude < 0.001f) {
        dest->x = dest->y = 0.0f;
        dest->z = 1.0f;
        return false;
    } else {
        dest->x = v->x * (1.0f / magnitude);
        dest->y = v->y * (1.0f / magnitude);
        dest->z = v->z * (1.0f / magnitude);
        return true;
    }
}

static Vec3f sVerticalVector = { 0.0f, 1.0f, 0.0f };
static Vec3f sZeroVector = { 0.0f, 0.0f, 0.0f };
static f32 sInertias[] = { 1.0f / 70000000, 1.0f / 175000000, 1.0f / 700000000 };
static f32 sDampingFactors[] = { 0.96f, 0.96f, 0.98f };

static f32 sRollSins[] = {
    0.22495104f, // sin(13 degrees)
    0.22495104f, // sin(13 degrees)
    0.03489947f, // sin(2 degrees)
};

static f32 sRollCoss[] = {
    0.97437006f, // cos(13 degrees)
    0.97437006f, // cos(13 degrees)
    0.99939084f, // cos(2 degrees)
};

/**
 *  Handles all the factors that influence rolling: inertia, random oscillations, and most significantly, player weight,
 * and combines them to produce a matrix that rotates the actor to match the surface normal
 */
void BgSpot08Iceblock_Roll(BgSpot08Iceblock* pthis, GlobalContext* globalCtx) {
    f32 deviationFromVertSq;
    f32 stabilityCorrection;
    Vec3f surfaceNormalHorizontal;
    Vec3f playerCentroidDiff;
    Vec3f playerMoment;
    Vec3f surfaceNormalHorizontalScaled;
    Vec3f randomNutation;
    Vec3f tempVec; // reused with different meanings
    Vec3f torqueDirection;
    f32 playerCentroidDist;
    s32 rollDataIndex;
    MtxF mtx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    switch (pthis->dyna.actor.params & 0xFF) {
        case 0x11: // Medium nonrotating
            rollDataIndex = 0;
            break;
        case 1:
            rollDataIndex = 1; // Large nonrotating
            break;
        default:
            rollDataIndex = 2;
            break;
    }

    Math_Vec3f_Diff(&player->actor.world.pos, &pthis->dyna.actor.world.pos, &playerCentroidDiff);
    playerCentroidDiff.y -= (150.0f * pthis->dyna.actor.scale.y);
    playerCentroidDist = Math3D_Vec3fMagnitude(&playerCentroidDiff);

    randomNutation.x = (Rand_ZeroOne() - 0.5f) * (1.0f / 625);
    randomNutation.y = 0.0f;
    randomNutation.z = (Rand_ZeroOne() - 0.5f) * (1.0f / 625);

    surfaceNormalHorizontal.x = pthis->surfaceNormal.x;
    surfaceNormalHorizontal.y = 0.0f;
    surfaceNormalHorizontal.z = pthis->surfaceNormal.z;

    // If player is standing on it or holding the edge
    if (func_8004356C(&pthis->dyna) && (playerCentroidDist > 3.0f)) {
        Math_Vec3f_Diff(&playerCentroidDiff, &surfaceNormalHorizontal, &playerMoment);
        BgSpot08Iceblock_MultVectorScalar(&playerMoment, &playerMoment,
                                          (sInertias[rollDataIndex] * playerCentroidDist) / pthis->dyna.actor.scale.x);
    } else {
        playerMoment = sZeroVector;
    }

    BgSpot08Iceblock_MultVectorScalar(&surfaceNormalHorizontalScaled, &surfaceNormalHorizontal, -0.01f);

    // Add all three deviations
    Math_Vec3f_Sum(&pthis->normalDelta, &playerMoment, &pthis->normalDelta);
    Math_Vec3f_Sum(&pthis->normalDelta, &surfaceNormalHorizontalScaled, &pthis->normalDelta);
    Math_Vec3f_Sum(&pthis->normalDelta, &randomNutation, &pthis->normalDelta);

    pthis->normalDelta.y = 0.0f;

    Math_Vec3f_Sum(&pthis->surfaceNormal, &pthis->normalDelta, &tempVec);

    tempVec.x *= sDampingFactors[rollDataIndex];
    tempVec.z *= sDampingFactors[rollDataIndex];

    // Set up roll axis and final new angle
    if (BgSpot08Iceblock_NormalizeVector(&pthis->surfaceNormal, &tempVec)) {
        deviationFromVertSq = Math3D_Dist1DSq(pthis->surfaceNormal.z, pthis->surfaceNormal.x);

        // Prevent overrolling
        if (sRollSins[rollDataIndex] < deviationFromVertSq) {
            stabilityCorrection = sRollSins[rollDataIndex] / deviationFromVertSq;

            pthis->surfaceNormal.x *= stabilityCorrection;
            pthis->surfaceNormal.y = sRollCoss[rollDataIndex];
            pthis->surfaceNormal.z *= stabilityCorrection;
        }

        BgSpot08Iceblock_CrossProduct(&tempVec, &sVerticalVector, &pthis->surfaceNormal);

        if (BgSpot08Iceblock_NormalizeVector(&torqueDirection, &tempVec)) {
            pthis->rotationAxis = torqueDirection;
        }
    } else {
        pthis->surfaceNormal = sVerticalVector;
    }

    // Rotation by the angle between surfaceNormal and the vertical about rotationAxis
    Matrix_RotateAxis(Math_FAcosF(Math3D_Cos(&sVerticalVector, &pthis->surfaceNormal)), &pthis->rotationAxis,
                      MTXMODE_NEW);
    Matrix_RotateY(pthis->dyna.actor.shape.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_Get(&mtx);
    Matrix_MtxFToYXZRotS(&mtx, &pthis->dyna.actor.shape.rot, 0);
}

void BgSpot08Iceblock_SpawnTwinFloe(BgSpot08Iceblock* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    f32 sin;
    f32 cos;

    sin = Math_SinS(pthis->dyna.actor.home.rot.y) * 100.0f;
    cos = Math_CosS(pthis->dyna.actor.home.rot.y) * 100.0f;

    if (!(pthis->dyna.actor.params & 0x100)) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_SPOT08_ICEBLOCK,
                           pthis->dyna.actor.home.pos.x, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.home.pos.z,
                           pthis->dyna.actor.home.rot.x, pthis->dyna.actor.home.rot.y, pthis->dyna.actor.home.rot.z,
                           0x123);

        pthis->dyna.actor.world.pos.x += sin;
        pthis->dyna.actor.world.pos.z += cos;
    } else {
        pthis->dyna.actor.world.pos.x -= sin;
        pthis->dyna.actor.world.pos.z -= cos;
    }
    BgSpot08Iceblock_SetupFloatOrbitingTwins(pthis);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 3000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2200, ICHAIN_STOP),
};

void BgSpot08Iceblock_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot08Iceblock* pthis = (BgSpot08Iceblock*)thisx;
    CollisionHeader* colHeader = NULL;

    // "spot08 ice floe"
    osSyncPrintf("(spot08 流氷)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
    BgSpot08Iceblock_CheckParams(pthis);

    switch (pthis->dyna.actor.params & 0x200) {
        case 0:
            colHeader = &gZorasFountainIcebergCol;
            break;
        case 0x200:
            colHeader = &gZorasFountainIceRampCol;
            break;
    }

    switch (pthis->dyna.actor.params & 0xF) {
        case 2:
        case 3:
            BgSpot08Iceblock_InitDynaPoly(pthis, globalCtx, colHeader, DPM_UNK3);
            break;
        default:
            BgSpot08Iceblock_InitDynaPoly(pthis, globalCtx, colHeader, DPM_UNK);
            break;
    }

    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    switch (pthis->dyna.actor.params & 0xF0) {
        case 0:
            Actor_SetScale(&pthis->dyna.actor, 0.2f);
            break;
        case 0x10:
            Actor_SetScale(&pthis->dyna.actor, 0.1f);
            break;
        case 0x20:
            Actor_SetScale(&pthis->dyna.actor, 0.05f);
            break;
    }

    pthis->bobPhaseSlow = (s32)(Rand_ZeroOne() * (0xFFFF + 0.5f));
    pthis->bobPhaseFast = (s32)(Rand_ZeroOne() * (0xFFFF + 0.5f));
    pthis->surfaceNormal.y = 1.0f;
    pthis->rotationAxis.x = 1.0f;

    switch (pthis->dyna.actor.params & 0xF) {
        case 0:
        case 1:
            BgSpot08Iceblock_SetupFloatNonrotating(pthis);
            break;
        case 2:
            BgSpot08Iceblock_SetupFloatRotating(pthis);
            break;
        case 3:
            BgSpot08Iceblock_SpawnTwinFloe(pthis, globalCtx);
            break;
        case 4:
            BgSpot08Iceblock_SetupNoAction(pthis);
            break;
    }
}

void BgSpot08Iceblock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot08Iceblock* pthis = (BgSpot08Iceblock*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgSpot08Iceblock_SetupFloatNonrotating(BgSpot08Iceblock* pthis) {
    BgSpot08Iceblock_SetupAction(pthis, BgSpot08Iceblock_FloatNonrotating);
}

void BgSpot08Iceblock_FloatNonrotating(BgSpot08Iceblock* pthis, GlobalContext* globalCtx) {
    BgSpot08Iceblock_Bobbing(pthis);
    BgSpot08Iceblock_SinkUnderPlayer(pthis);
    BgSpot08Iceblock_SetWaterline(pthis);
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.home.rot.y;
    BgSpot08Iceblock_Roll(pthis, globalCtx);
}

void BgSpot08Iceblock_SetupFloatRotating(BgSpot08Iceblock* pthis) {
    BgSpot08Iceblock_SetupAction(pthis, BgSpot08Iceblock_FloatRotating);
}

void BgSpot08Iceblock_FloatRotating(BgSpot08Iceblock* pthis, GlobalContext* globalCtx) {
    BgSpot08Iceblock_Bobbing(pthis);
    BgSpot08Iceblock_SinkUnderPlayer(pthis);
    BgSpot08Iceblock_SetWaterline(pthis);
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.world.rot.y + 0x190;
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y;
    BgSpot08Iceblock_Roll(pthis, globalCtx);
}

void BgSpot08Iceblock_SetupFloatOrbitingTwins(BgSpot08Iceblock* pthis) {
    BgSpot08Iceblock_SetupAction(pthis, BgSpot08Iceblock_FloatOrbitingTwins);
}

void BgSpot08Iceblock_FloatOrbitingTwins(BgSpot08Iceblock* pthis, GlobalContext* globalCtx) {
    f32 cos;
    f32 sin;

    BgSpot08Iceblock_Bobbing(pthis);
    BgSpot08Iceblock_SinkUnderPlayer(pthis);
    BgSpot08Iceblock_SetWaterline(pthis);

    // parent handles rotations of both
    if (!(pthis->dyna.actor.params & 0x100)) {
        pthis->dyna.actor.world.rot.y += 0x190;
        sin = Math_SinS(pthis->dyna.actor.world.rot.y) * 100.0f;
        cos = Math_CosS(pthis->dyna.actor.world.rot.y) * 100.0f;

        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x + sin;
        pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z + cos;

        if (pthis->dyna.actor.child != NULL) {
            pthis->dyna.actor.child->world.pos.x = pthis->dyna.actor.home.pos.x - sin;
            pthis->dyna.actor.child->world.pos.z = pthis->dyna.actor.home.pos.z - cos;
        }
    }

    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.home.rot.y;
    BgSpot08Iceblock_Roll(pthis, globalCtx);
}

void BgSpot08Iceblock_SetupNoAction(BgSpot08Iceblock* pthis) {
    BgSpot08Iceblock_SetupAction(pthis, NULL);
}

void BgSpot08Iceblock_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot08Iceblock* pthis = (BgSpot08Iceblock*)thisx;

    if (Rand_ZeroOne() < 0.05f) {
        pthis->bobIncrSlow = Rand_S16Offset(300, 100);
        pthis->bobIncrFast = Rand_S16Offset(800, 400);
    }

    pthis->bobPhaseSlow += pthis->bobIncrSlow;
    pthis->bobPhaseFast += pthis->bobIncrFast;
    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgSpot08Iceblock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx* dList = NULL;
    BgSpot08Iceblock* pthis = (BgSpot08Iceblock*)thisx;

    switch (pthis->dyna.actor.params & 0x200) {
        case 0:
            dList = gZorasFountainIcebergDL;
            break;
        case 0x200:
            dList = gZorasFountainIceRampDL;
            break;
    }

    Gfx_DrawDListOpa(globalCtx, dList);
}

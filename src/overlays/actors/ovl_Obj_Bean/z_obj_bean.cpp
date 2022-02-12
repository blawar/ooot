#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_BEAN_Z_OBJ_BEAN_C
#include "actor_common.h"
/*
 * File: z_obj_bean.c
 * Overlay: ovl_Obj_Bean
 * Description: Bean plant spot
 */

#include "z_obj_bean.h"
#include "objects/object_mamenoki/object_mamenoki.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/code_8006C3A0.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS ACTOR_FLAG_22

void ObjBean_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjBean_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjBean_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjBean_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjBean_WaitForPlayer(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_Fly(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupFly(ObjBean* pthis);
void ObjBean_WaitForWater(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupWaitForWater(ObjBean* pthis);
void ObjBean_SetupGrowWaterPhase1(ObjBean* pthis);
void ObjBean_GrowWaterPhase1(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_GrowWaterPhase2(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupGrowWaterPhase2(ObjBean* pthis);
void ObjBean_GrowWaterPhase3(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupGrowWaterPhase3(ObjBean* pthis);
void ObjBean_SetupGrown(ObjBean* pthis);
void ObjBean_FlattenLeaves(ObjBean* pthis);
void ObjBean_Grown(ObjBean* pthis);
void ObjBean_LeavesStill(ObjBean* pthis);
void ObjBean_SetupShakeLeaves(ObjBean* pthis);
void ObjBean_ShakeLeaves(ObjBean* pthis);
void ObjBean_SetupWaitForBean(ObjBean* pthis);
void ObjBean_WaitForBean(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B8FE3C(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B8FE00(ObjBean* pthis);
void func_80B8FE6C(ObjBean* pthis);
void func_80B8FEAC(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B8FF50(ObjBean* pthis);
void ObjBean_SetupGrowWaterPhase4(ObjBean* pthis);
void func_80B8FF8C(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B90050(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B90010(ObjBean* pthis);
void func_80B908EC(ObjBean* pthis);
void func_80B90918(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B90970(ObjBean* pthis);
void func_80B909B0(ObjBean* pthis, GlobalContext* globalCtx);
void func_80B909F8(ObjBean* pthis);
void func_80B90A34(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupWaitForPlayer(ObjBean* pthis);
void ObjBean_GrowWaterPhase4(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_GrowWaterPhase5(ObjBean* pthis, GlobalContext* globalCtx);
void ObjBean_SetupGrowWaterPhase5(ObjBean* pthis);
void ObjBean_SetupShakeLeavesFast(ObjBean* pthis);
void ObjBean_ShakeLeavesFast(ObjBean* pthis);
void ObjBean_Grow(ObjBean* pthis);
void ObjBean_SetupGrow(ObjBean* pthis);
void ObjBean_SetupWaitForStepOff(ObjBean* pthis);
void ObjBean_WaitForStepOff(ObjBean* pthis, GlobalContext* globalCtx);

#define BEAN_STATE_DRAW_LEAVES (1 << 0)
#define BEAN_STATE_DRAW_SOIL (1 << 1)
#define BEAN_STATE_DRAW_PLANT (1 << 2)
#define BEAN_STATE_DRAW_STALK (1 << 3)
#define BEAN_STATE_COLLIDER_SET (1 << 4)
#define BEAN_STATE_DYNAPOLY_SET (1 << 5)
#define BEAN_STATE_BEEN_WATERED (1 << 6)
#define BEAN_STATE_PLAYER_ON_TOP (1 << 7)

static ObjBean* D_80B90E30 = NULL;

ActorInit Obj_Bean_InitVars = {
    ACTOR_OBJ_BEAN,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MAMENOKI,
    sizeof(ObjBean),
    (ActorFunc)ObjBean_Init,
    (ActorFunc)ObjBean_Destroy,
    (ActorFunc)ObjBean_Update,
    (ActorFunc)ObjBean_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 64, 30, -31, { 0, 0, 0 } },
};

typedef struct {
    f32 velocity;
    f32 accel;
} BeenSpeedInfo;

static BeenSpeedInfo sBeanSpeeds[] = {
    { 3.0f, 0.3f },
    { 10.0f, 0.5f },
    { 30.0f, 0.5f },
    { 3.0f, 0.3f },
};

static Gfx* sBreakDlists[] = { gCuttableShrubStalkDL, gCuttableShrubTipDL };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1600, ICHAIN_STOP),
};

void ObjBean_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    ObjBean* pthis = (ObjBean*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
}

void ObjBean_InitDynaPoly(ObjBean* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader;
    s32 pad2;

    colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_bean.c", 374,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void ObjBean_FindFloor(ObjBean* pthis, GlobalContext* globalCtx) {
    Vec3f vec;
    s32 sp20;

    vec.x = pthis->dyna.actor.world.pos.x;
    vec.y = pthis->dyna.actor.world.pos.y + 29.999998f;
    vec.z = pthis->dyna.actor.world.pos.z;
    pthis->dyna.actor.floorHeight =
        BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly, &sp20, &pthis->dyna.actor, &vec);
}

void func_80B8EBC8(ObjBean* pthis) {
    pthis->unk_1B6.x = pthis->unk_1B6.y = pthis->unk_1B6.z = 0;
    pthis->unk_1E4 = 0.0f;
}

void ObjBean_UpdatePosition(ObjBean* pthis) {
    f32 temp_f20;

    pthis->unk_1B6.x += 0xB6;
    pthis->unk_1B6.y += 0xFB;
    pthis->unk_1B6.z += 0x64;

    Math_StepToF(&pthis->unk_1E4, 2.0f, 0.1f);
    temp_f20 = Math_SinS(pthis->unk_1B6.x * 3);
    pthis->posOffsetX = (Math_SinS(((pthis->unk_1B6.y * 3))) + temp_f20) * pthis->unk_1E4;
    temp_f20 = Math_CosS(pthis->unk_1B6.x * 4);
    pthis->posOffsetZ = (Math_CosS((pthis->unk_1B6.y * 4)) + temp_f20) * pthis->unk_1E4;
    temp_f20 = Math_SinS(pthis->unk_1B6.z * 5);

    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z =
        ((Math_SinS((pthis->unk_1B6.y * 8)) * 0.01f) + (temp_f20 * 0.06f) + 1.07f) * 0.1f;

    pthis->dyna.actor.scale.y = ((Math_CosS(((pthis->unk_1B6.z * 10))) * 0.2f) + 1.0f) * 0.1f;
    temp_f20 = Math_SinS(pthis->unk_1B6.x * 3);
    pthis->dyna.actor.shape.rot.y =
        (Math_SinS((s16)(pthis->unk_1B6.z * 2)) * 2100.0f) + ((f32)pthis->dyna.actor.home.rot.y + (temp_f20 * 1000.0f));
}

void func_80B8EDF4(ObjBean* pthis) {
    pthis->unk_1B6.x = pthis->unk_1B6.y = pthis->unk_1B6.z = 0;

    Actor_SetScale(&pthis->dyna.actor, 0.0f);
}

void func_80B8EE24(ObjBean* pthis) {
    pthis->unk_1B6.x += 0x384;
    if (pthis->unk_1B6.x > 0x5FFF) {
        pthis->unk_1B6.x = 0x5FFF;
    }
    pthis->unk_1B6.y += 0x258;
    if (pthis->unk_1B6.y > 0x4000) {
        pthis->unk_1B6.y = 0x4000;
    }
    pthis->dyna.actor.scale.y = Math_SinS(pthis->unk_1B6.x) * 0.16970563f;

    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_SinS(pthis->unk_1B6.y) * 0.10700001f;

    Math_StepToF(&pthis->posOffsetX, 0.0f, 0.1f);
    Math_StepToF(&pthis->posOffsetZ, 0.0f, 0.1f);
    Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.y, pthis->dyna.actor.home.rot.y, 0x64);
}

void ObjBean_Move(ObjBean* pthis) {
    pthis->dyna.actor.world.pos.x = pthis->pathPoints.x + pthis->posOffsetX;
    pthis->dyna.actor.world.pos.y = pthis->pathPoints.y;
    pthis->dyna.actor.world.pos.z = pthis->pathPoints.z + pthis->posOffsetZ;
}

void ObjBean_SetDrawMode(ObjBean* pthis, u8 drawFlag) {
    pthis->stateFlags &=
        ~(BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_PLANT | BEAN_STATE_DRAW_STALK | BEAN_STATE_DRAW_SOIL);
    pthis->stateFlags |= drawFlag;
}

void ObjBean_SetupPathCount(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->pathCount = globalCtx->setupPathList[(pthis->dyna.actor.params >> 8) & 0x1F].count - 1;
    pthis->currentPointIndex = 0;
    pthis->nextPointIndex = 1;
}

void ObjBean_SetupPath(ObjBean* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[(pthis->dyna.actor.params >> 8) & 0x1F];
    Math_Vec3s_ToVec3f(&pthis->pathPoints, SEGMENTED_TO_VIRTUAL(path->points));
}

void ObjBean_FollowPath(ObjBean* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3f acell;
    Vec3f pathPointsFloat;
    f32 speed;
    Vec3s* nextPathPoint;
    Vec3s* currentPoint;
    Vec3s* sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    f32 mag;

    Math_StepToF(&pthis->dyna.actor.speedXZ, sBeanSpeeds[pthis->unk_1F6].velocity, sBeanSpeeds[pthis->unk_1F6].accel);
    path = &globalCtx->setupPathList[(pthis->dyna.actor.params >> 8) & 0x1F];
    nextPathPoint = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pthis->nextPointIndex];

    Math_Vec3s_ToVec3f(&pathPointsFloat, nextPathPoint);

    Math_Vec3f_Diff(&pathPointsFloat, &pthis->pathPoints, &acell);
    mag = Math3D_Vec3fMagnitude(&acell);
    speed = CLAMP_MIN(pthis->dyna.actor.speedXZ, 0.5f);
    if (speed > mag) {
        currentPoint = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pthis->currentPointIndex];

        Math_Vec3f_Copy(&pthis->pathPoints, &pathPointsFloat);
        pthis->currentPointIndex = pthis->nextPointIndex;

        if (pthis->pathCount <= pthis->currentPointIndex) {
            pthis->nextPointIndex = 0;
        } else {
            pthis->nextPointIndex++;
        }
        sp4C = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pthis->nextPointIndex];
        Math_Vec3s_DiffToVec3f(&sp40, nextPathPoint, currentPoint);
        Math_Vec3s_DiffToVec3f(&sp34, sp4C, nextPathPoint);
        if (Math3D_CosOut(&sp40, &sp34, &sp30)) {
            pthis->dyna.actor.speedXZ = 0.0f;
        } else {
            pthis->dyna.actor.speedXZ *= (sp30 + 1.0f) * 0.5f;
        }
    } else {
        Math_Vec3f_Scale(&acell, pthis->dyna.actor.speedXZ / mag);
        pthis->pathPoints.x += acell.x;
        pthis->pathPoints.y += acell.y;
        pthis->pathPoints.z += acell.z;
    }
}

s32 ObjBean_CheckForHorseTrample(ObjBean* pthis, GlobalContext* globalCtx) {
    Actor* currentActor = globalCtx->actorCtx.actorLists[ACTORCAT_BG].head;

    while (currentActor != NULL) {
        if ((currentActor->id == ACTOR_EN_HORSE) &&
            (Math3D_Vec3fDistSq(&currentActor->world.pos, &pthis->dyna.actor.world.pos) < 10000.0f)) {
            return true;
        }
        currentActor = currentActor->next;
    }

    return false;
}

void ObjBean_Break(ObjBean* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f velocity;
    f32 temp_f20;
    s16 angle;
    s32 scale;
    s32 i;
    s16 gravity;
    s16 arg5;

    angle = 0;
    for (i = 0; i < 36; i++) {
        angle += 0x4E20;
        temp_f20 = Rand_ZeroOne() * 60.0f;

        pos.x = (Math_SinS(angle) * temp_f20) + pthis->dyna.actor.world.pos.x;
        pos.y = pthis->dyna.actor.world.pos.y;
        pos.z = (Math_CosS(angle) * temp_f20) + pthis->dyna.actor.world.pos.z;

        velocity.x = Math_SinS(angle) * 3.5f;
        velocity.y = Rand_ZeroOne() * 13.0f;
        velocity.z = Math_CosS(angle) * 3.5f;

        velocity.x += pthis->dyna.actor.world.pos.x - pthis->dyna.actor.prevPos.x;
        velocity.y += pthis->dyna.actor.world.pos.y - pthis->dyna.actor.prevPos.y;
        velocity.z += pthis->dyna.actor.world.pos.z - pthis->dyna.actor.prevPos.z;

        scale = (s32)(Rand_ZeroOne() * 180.0f) + 30;
        if (scale < 90) {
            if (Rand_ZeroOne() < 0.1f) {
                gravity = -80;
                arg5 = 96;
            } else {
                gravity = -80;
                arg5 = 64;
            }
        } else {
            gravity = -100;
            arg5 = 64;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, gravity, arg5, 40, 3, 0, scale, 0, 0,
                             (s16)((scale >> 3) + 40), -1, 1, sBreakDlists[i & 1]);
    }
}

void ObjBean_UpdateLeaves(ObjBean* pthis) {
    Math_StepToS(&pthis->unk_1C2, pthis->unk_1C4, pthis->unk_1C6);
    Math_StepToS(&pthis->unk_1C8, pthis->unk_1CA, pthis->unk_1CC);
    pthis->unk_1CE += pthis->unk_1C8;
    pthis->leafRotFactor = 6372.0f - Math_SinS(pthis->unk_1CE) * (f32)pthis->unk_1C2;
    pthis->dyna.actor.scale.y = Math_SinS(pthis->leafRotFactor) * 0.17434467f;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_CosS(pthis->leafRotFactor) * 0.12207746f;
}

void ObjBean_SetupLeavesStill(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_LeavesStill;
    pthis->unk_1C0 = Rand_S16Offset(12, 40);
    pthis->unk_1C4 = Rand_S16Offset(0xC8, 0x190);
    pthis->unk_1C6 = 0x14;
    pthis->unk_1CA = Rand_S16Offset(0x64, 0x320);
    pthis->unk_1CC = 0x14;
}

void ObjBean_LeavesStill(ObjBean* pthis) {
    pthis->unk_1C0--;
    ObjBean_UpdateLeaves(pthis);
    if (pthis->unk_1C0 < 0) {
        ObjBean_SetupShakeLeaves(pthis);
    }
}

void ObjBean_SetupShakeLeaves(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_ShakeLeaves;
    pthis->unk_1C0 = Rand_S16Offset(30, 4);
    pthis->unk_1C4 = Rand_S16Offset(0x7D0, 0x3E8);
    pthis->unk_1C6 = 0xC8;
    pthis->unk_1CA = Rand_S16Offset(0x36B0, 0x1770);
    pthis->unk_1CC = 0xFA0;
    pthis->leafRotFactor = 0x18E4;
}

void ObjBean_ShakeLeaves(ObjBean* pthis) {
    pthis->unk_1C0 += -1;
    if (pthis->unk_1C0 == 14) {
        pthis->unk_1C4 = Rand_S16Offset(0xC8, 0x190);
        pthis->unk_1CA = Rand_S16Offset(0x64, 0x1F4);
        pthis->unk_1CC = 0x7D0;
    }
    ObjBean_UpdateLeaves(pthis);
    if (pthis->unk_1C0 < 0) {
        ObjBean_SetupLeavesStill(pthis);
    }
}

void ObjBean_SetupShakeLeavesFast(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_ShakeLeavesFast;
    pthis->unk_1C0 = 0x28;
    pthis->unk_1C4 = 0xBB8;
    pthis->unk_1C6 = 0x12C;
    pthis->unk_1CA = 0x3A98;
    pthis->unk_1CC = 0xFA0;
    pthis->leafRotFactor = 0x18E4;
}

void ObjBean_ShakeLeavesFast(ObjBean* pthis) {
    pthis->unk_1C0 += -1;
    if (Rand_ZeroOne() < 0.1f) {
        pthis->unk_1C4 = Rand_S16Offset(0x898, 0x3E8);
        pthis->unk_1CA = Rand_S16Offset(0x2EE0, 0x1F40);
    }
    ObjBean_UpdateLeaves(pthis);
    if ((s32)pthis->unk_1C0 < 0) {
        ObjBean_SetupGrow(pthis);
    }
}

void ObjBean_SetupGrow(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_Grow;
}

void ObjBean_Grow(ObjBean* pthis) {
    Math_StepToS(&pthis->leafRotFactor, 0x33E9, 0x168);
    pthis->dyna.actor.scale.y = Math_SinS(pthis->leafRotFactor) * 0.17434467f;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_CosS(pthis->leafRotFactor) * 0.12207746f;
    ;
}

void ObjBean_SetupFlattenLeaves(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_FlattenLeaves;
    pthis->leafRotFactor = 0x33E9;
}

void ObjBean_FlattenLeaves(ObjBean* pthis) {
    pthis->leafRotFactor -= 0x960;
    pthis->dyna.actor.scale.y = Math_SinS(pthis->leafRotFactor) * 0.17434467f;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_CosS(pthis->leafRotFactor) * 0.12207746f;

    if (pthis->leafRotFactor < 0x18E4) {
        ObjBean_SetupGrown(pthis);
    }
}

void ObjBean_SetupGrown(ObjBean* pthis) {
    pthis->transformFunc = ObjBean_Grown;
    pthis->unk_1C2 = 0xBB8;
    pthis->unk_1C4 = 0;
    pthis->unk_1C6 = 0xC8;
    pthis->unk_1C8 = 0x3E80;
    pthis->unk_1CA = 0x1F4;
    pthis->unk_1CC = 0;
    pthis->unk_1C0 = 0x10;
}

void ObjBean_Grown(ObjBean* pthis) {
    pthis->unk_1C0--;
    if (pthis->unk_1C0 == 6) {
        pthis->unk_1CC = 0x7D0;
    }
    ObjBean_UpdateLeaves(pthis);
    if (pthis->unk_1C2 <= 0) {
        ObjBean_SetupLeavesStill(pthis);
    }
}

void ObjBean_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 path;
    s32 linkAge;
    ObjBean* pthis = (ObjBean*)thisx;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
        if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F) || (mREG(1) == 1)) {
            path = (pthis->dyna.actor.params >> 8) & 0x1F;
            if (path == 0x1F) {
                osSyncPrintf(VT_COL(RED, WHITE));
                // "No path data?"
                osSyncPrintf("パスデータが無い？(%s %d)(arg_data %xH)\n", "../z_obj_bean.c", 909,
                             pthis->dyna.actor.params);
                osSyncPrintf(VT_RST);
                Actor_Kill(&pthis->dyna.actor);
                return;
            }
            if (globalCtx->setupPathList[path].count < 3) {
                osSyncPrintf(VT_COL(RED, WHITE));
                // "Incorrect number of path data"
                osSyncPrintf("パスデータ数が不正(%s %d)(arg_data %xH)\n", "../z_obj_bean.c", 921,
                             pthis->dyna.actor.params);
                osSyncPrintf(VT_RST);
                Actor_Kill(&pthis->dyna.actor);
                return;
            }
            ObjBean_SetupPathCount(pthis, globalCtx);
            ObjBean_SetupPath(pthis, globalCtx);
            ObjBean_Move(pthis);
            ObjBean_SetupWaitForPlayer(pthis);

            ObjBean_InitDynaPoly(pthis, globalCtx, &gMagicBeanPlatformCol, DPM_UNK3);
            pthis->stateFlags |= BEAN_STATE_DYNAPOLY_SET;
            ObjBean_InitCollider(&pthis->dyna.actor, globalCtx);
            pthis->stateFlags |= BEAN_STATE_COLLIDER_SET;

            ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 8.8f);
            ObjBean_FindFloor(pthis, globalCtx);
            pthis->unk_1F6 = pthis->dyna.actor.home.rot.z & 3;
        } else {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
    } else if ((Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F) != 0) || (mREG(1) == 1)) {
        ObjBean_SetupWaitForWater(pthis);
    } else {
        ObjBean_SetupWaitForBean(pthis);
    }
    pthis->dyna.actor.world.rot.z = pthis->dyna.actor.home.rot.z = pthis->dyna.actor.shape.rot.z = 0;
    // "Magic bean tree lift"
    osSyncPrintf("(魔法の豆の木リフト)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void ObjBean_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjBean* pthis = (ObjBean*)thisx;

    if (pthis->stateFlags & BEAN_STATE_DYNAPOLY_SET) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
    if (pthis->stateFlags & BEAN_STATE_COLLIDER_SET) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
    if (D_80B90E30 == pthis) {
        D_80B90E30 = NULL;
    }
}

void ObjBean_SetupWaitForBean(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_WaitForBean;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES);
    pthis->dyna.actor.textId = 0x2F;
}

void ObjBean_WaitForBean(ObjBean* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->dyna.actor, globalCtx)) {
        if (func_8002F368(globalCtx) == EXCH_ITEM_BEAN) {
            func_80B8FE00(pthis);
            Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
        }
    } else {
        func_8002F298(&pthis->dyna.actor, globalCtx, 40.0f, EXCH_ITEM_BEAN);
    }
}

void func_80B8FE00(ObjBean* pthis) {
    pthis->actionFunc = func_80B8FE3C;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES);
    pthis->timer = 60;
}

// Link is looking at the soft soil
void func_80B8FE3C(ObjBean* pthis, GlobalContext* globalCtx) {
    if (pthis->timer <= 0) {
        func_80B8FE6C(pthis);
    }
}

void func_80B8FE6C(ObjBean* pthis) {
    pthis->actionFunc = func_80B8FEAC;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    Actor_SetScale(&pthis->dyna.actor, 0.01f);
}

// The leaves are visable and growing
void func_80B8FEAC(ObjBean* pthis, GlobalContext* globalCtx) {
    s32 temp_v1 = true;

    temp_v1 &= Math_StepToF(&pthis->dyna.actor.scale.y, 0.16672663f, 0.01f);
    temp_v1 &= Math_StepToF(&pthis->dyna.actor.scale.x, 0.03569199f, 0.00113f);

    pthis->dyna.actor.scale.z = pthis->dyna.actor.scale.x;
    if (temp_v1) {
        if (pthis->timer <= 0) {
            func_80B8FF50(pthis);
        }
    } else {
        pthis->timer = 1;
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_PL_PLANT_GROW_UP - SFX_FLAG);
}

void func_80B8FF50(ObjBean* pthis) {
    pthis->actionFunc = func_80B8FF8C;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    pthis->unk_1B6.x = 0x33E9;
}

void func_80B8FF8C(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->unk_1B6.x -= 0x960;
    pthis->dyna.actor.scale.y = Math_SinS(pthis->unk_1B6.x) * 0.17434467f;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_CosS(pthis->unk_1B6.x) * 0.12207746f;
    if (pthis->unk_1B6.x < 0x18E4) {
        func_80B90010(pthis);
    }
}

void func_80B90010(ObjBean* pthis) {
    pthis->actionFunc = func_80B90050;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    pthis->unk_1B6.x = 0;
    pthis->unk_1B6.y = 0xBB8;
}

// Control is returned to the player and the leaves start to flatten out
void func_80B90050(ObjBean* pthis, GlobalContext* globalCtx) {
    s16 temp_a0;
    f32 temp_f2;

    pthis->unk_1B6.x += 0x3E80;
    pthis->unk_1B6.y += -0xC8;
    temp_a0 = 6372.0f - Math_SinS(pthis->unk_1B6.x) * pthis->unk_1B6.y;

    pthis->dyna.actor.scale.y = Math_SinS(temp_a0) * 0.17434467f;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.z = Math_CosS(temp_a0) * 0.12207746f;
    if (pthis->unk_1B6.y < 0) {
        ObjBean_SetupWaitForWater(pthis);
    }
}

void ObjBean_SetupWaitForWater(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_WaitForWater;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    Actor_SetScale(&pthis->dyna.actor, 0.1f);
    ObjBean_SetupLeavesStill(pthis);
}

void ObjBean_WaitForWater(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->transformFunc(pthis);

    if (!(pthis->stateFlags & BEAN_STATE_BEEN_WATERED) && Flags_GetEnv(globalCtx, 5) && (D_80B90E30 == NULL) &&
        (pthis->dyna.actor.xzDistToPlayer < 50.0f)) {
        ObjBean_SetupGrowWaterPhase1(pthis);
        D_80B90E30 = pthis;
        OnePointCutscene_Init(globalCtx, 2210, -99, &pthis->dyna.actor, MAIN_CAM);
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
        return;
    }

    if ((D_80B90E30 == pthis) && !Flags_GetEnv(globalCtx, 5)) {
        D_80B90E30 = NULL;
        if (D_80B90E30) {}
    }
}

void ObjBean_SetupGrowWaterPhase1(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_GrowWaterPhase1;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    ObjBean_SetupShakeLeavesFast(pthis);
    pthis->timer = 50;
}

// Camera moves and leaves move quickly
void ObjBean_GrowWaterPhase1(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->transformFunc(pthis);
    if (pthis->timer <= 0) {
        ObjBean_SetupGrowWaterPhase2(pthis);
    }
}

void ObjBean_SetupGrowWaterPhase2(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_GrowWaterPhase2;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_SOIL | BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_STALK);
    pthis->stalkSizeMultiplier = 0.0f;
}

// BeanStalk is visable and is growing
void ObjBean_GrowWaterPhase2(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->transformFunc(pthis);
    pthis->stalkSizeMultiplier += 0.001f;
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.home.rot.y + (s16)(pthis->stalkSizeMultiplier * 700000.0f);
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + pthis->stalkSizeMultiplier * 800.0f;
    if (pthis->stalkSizeMultiplier >= 0.1f) { // 100 Frames
        ObjBean_SetupGrowWaterPhase3(pthis);
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_PL_PLANT_TALLER - SFX_FLAG);
}

void ObjBean_SetupGrowWaterPhase3(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_GrowWaterPhase3;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_SOIL | BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_STALK);
    pthis->timer = 60;
}

// Fully grown and drops items
void ObjBean_GrowWaterPhase3(ObjBean* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f itemDropPos;

    pthis->transformFunc(pthis);
    if (pthis->timer == 40) {
        ObjBean_SetupFlattenLeaves(pthis);
    } else if (pthis->timer == 30) {
        if (!(pthis->stateFlags & BEAN_STATE_BEEN_WATERED)) {
            itemDropPos.x = pthis->dyna.actor.world.pos.x;
            itemDropPos.y = pthis->dyna.actor.world.pos.y - 25.0f;
            itemDropPos.z = pthis->dyna.actor.world.pos.z;
            for (i = 0; i < 3; i++) {
                Item_DropCollectible(globalCtx, &itemDropPos, ITEM00_FLEXIBLE);
            }
            pthis->stateFlags |= BEAN_STATE_BEEN_WATERED;
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUTTERFRY_TO_FAIRY);
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        }
    } else if (pthis->timer <= 0) {
        ObjBean_SetupGrowWaterPhase4(pthis);
    }
}

void ObjBean_SetupGrowWaterPhase4(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_GrowWaterPhase4;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_SOIL | BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_STALK);
    ObjBean_SetupGrow(pthis);
}

// Return control back to the player and start to shrink back down
void ObjBean_GrowWaterPhase4(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->transformFunc(pthis);
    pthis->stalkSizeMultiplier -= 0.001f;
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.home.rot.y + (s16)(pthis->stalkSizeMultiplier * 700000.0f);
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + (pthis->stalkSizeMultiplier * 800.0f);
    if (pthis->stalkSizeMultiplier <= 0.0f) {
        pthis->stalkSizeMultiplier = 0.0f;
        pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.home.rot.y;
        ObjBean_SetupGrowWaterPhase5(pthis);
    }
}

void ObjBean_SetupGrowWaterPhase5(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_GrowWaterPhase5;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_LEAVES | BEAN_STATE_DRAW_SOIL);
    pthis->timer = 30;
}

void ObjBean_GrowWaterPhase5(ObjBean* pthis, GlobalContext* globalCtx) {
    pthis->transformFunc(pthis);
    if (pthis->timer <= 0) {
        func_80B8FF50(pthis);
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
    }
}

void ObjBean_SetupWaitForPlayer(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_WaitForPlayer;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_PLANT);
}

void ObjBean_WaitForPlayer(ObjBean* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) { // Player is standing on
        ObjBean_SetupFly(pthis);
        if (globalCtx->sceneNum == SCENE_SPOT10) { // Lost woods
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BEAN_LOST_WOODS);
        } else {
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BEAN_GENERIC);
        }
    }
    ObjBean_UpdatePosition(pthis);
}

void ObjBean_SetupFly(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_Fly;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_PLANT);
    pthis->dyna.actor.speedXZ = 0.0f;
    pthis->dyna.actor.flags |= ACTOR_FLAG_4; // Never stop updating
}

void ObjBean_Fly(ObjBean* pthis, GlobalContext* globalCtx) {
    Camera* camera;

    ObjBean_FollowPath(pthis, globalCtx);
    if (pthis->currentPointIndex == pthis->pathCount) {
        ObjBean_SetupPathCount(pthis, globalCtx);
        ObjBean_SetupPath(pthis, globalCtx);
        ObjBean_SetupWaitForStepOff(pthis);

        pthis->dyna.actor.flags &= ~ACTOR_FLAG_4; // Never stop updating (disable)
        camera = globalCtx->cameraPtrs[MAIN_CAM];

        if ((camera->setting == CAM_SET_BEAN_LOST_WOODS) || (camera->setting == CAM_SET_BEAN_GENERIC)) {
            Camera_ChangeSetting(camera, CAM_SET_NORMAL0);
        }

    } else if (func_8004356C(&pthis->dyna) != 0) { // Player is on top

        func_8002F974(&pthis->dyna.actor, NA_SE_PL_PLANT_MOVE - SFX_FLAG);

        if (globalCtx->sceneNum == SCENE_SPOT10) {
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BEAN_LOST_WOODS);
        } else {
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BEAN_GENERIC);
        }
    } else if (pthis->stateFlags & BEAN_STATE_PLAYER_ON_TOP) {
        camera = globalCtx->cameraPtrs[MAIN_CAM];

        if ((camera->setting == CAM_SET_BEAN_LOST_WOODS) || (camera->setting == CAM_SET_BEAN_GENERIC)) {
            Camera_ChangeSetting(camera, CAM_SET_NORMAL0);
        }
    }

    ObjBean_UpdatePosition(pthis);
}

void ObjBean_SetupWaitForStepOff(ObjBean* pthis) {
    pthis->actionFunc = ObjBean_WaitForStepOff;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_PLANT);
}

void ObjBean_WaitForStepOff(ObjBean* pthis, GlobalContext* globalCtx) {
    if (!func_80043590(&pthis->dyna)) {
        ObjBean_SetupWaitForPlayer(pthis);
    }
    ObjBean_UpdatePosition(pthis);
}

void func_80B908EC(ObjBean* pthis) {
    pthis->actionFunc = func_80B90918;
    ObjBean_SetDrawMode(pthis, 0);
}

void func_80B90918(ObjBean* pthis, GlobalContext* globalCtx) {
    if (!func_8004356C(&pthis->dyna)) {
        ObjBean_SetupPathCount(pthis, globalCtx);
        ObjBean_SetupPath(pthis, globalCtx);
        ObjBean_Move(pthis);
        func_80B90970(pthis);
    }
}

void func_80B90970(ObjBean* pthis) {
    pthis->actionFunc = func_80B909B0;
    ObjBean_SetDrawMode(pthis, 0);
    pthis->timer = 100;
    func_80B8EDF4(pthis);
}

void func_80B909B0(ObjBean* pthis, GlobalContext* globalCtx) {
    if (ObjBean_CheckForHorseTrample(pthis, globalCtx)) {
        pthis->timer = 100;
    } else if (pthis->timer <= 0) {
        func_80B909F8(pthis);
    }
}

void func_80B909F8(ObjBean* pthis) {
    pthis->actionFunc = func_80B90A34;
    ObjBean_SetDrawMode(pthis, BEAN_STATE_DRAW_PLANT);
    pthis->timer = 30;
}

void func_80B90A34(ObjBean* pthis, GlobalContext* globalCtx) {
    s32 trampled = ObjBean_CheckForHorseTrample(pthis, globalCtx);

    func_80B8EE24(pthis);
    if (trampled) {
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    } else {
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
    if ((pthis->timer <= 0) && (!trampled)) {
        func_80B8EBC8(pthis);
        ObjBean_SetupWaitForPlayer(pthis);
    }
}
void ObjBean_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjBean* pthis = (ObjBean*)thisx;

    if (pthis->timer > 0) {
        pthis->timer--;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->stateFlags & BEAN_STATE_DRAW_PLANT) {
        ObjBean_Move(pthis);
        if (pthis->dyna.actor.xzDistToPlayer < 150.0f) {
            pthis->collider.dim.radius = pthis->dyna.actor.scale.x * 640.0f + 0.5f;
            Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        ObjBean_FindFloor(pthis, globalCtx);

        pthis->dyna.actor.shape.shadowDraw = ActorShadow_DrawCircle;
        pthis->dyna.actor.shape.shadowScale = pthis->dyna.actor.scale.x * 88.0f;

        if (ObjBean_CheckForHorseTrample(pthis, globalCtx)) {
            osSyncPrintf(VT_FGCOL(CYAN));
            // "Horse and bean tree lift collision"
            osSyncPrintf("馬と豆の木リフト衝突！！！\n");
            osSyncPrintf(VT_RST);
            ObjBean_Break(pthis, globalCtx);
            func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            func_80B908EC(pthis);
        }
    } else {
        pthis->dyna.actor.shape.shadowDraw = NULL;
    }
    Actor_SetFocus(&pthis->dyna.actor, 6.0f);
    if (pthis->stateFlags & BEAN_STATE_DYNAPOLY_SET) {
        if (func_8004356C(&pthis->dyna)) {
            pthis->stateFlags |= BEAN_STATE_PLAYER_ON_TOP;
        } else {
            pthis->stateFlags &= ~BEAN_STATE_PLAYER_ON_TOP;
        }
    }
}

void ObjBean_DrawSoftSoilSpot(ObjBean* pthis, GlobalContext* globalCtx) {
    Matrix_Translate(pthis->dyna.actor.home.pos.x, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.home.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->dyna.actor.home.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, gMagicBeanSoftSoilDL);
}

void ObjBean_DrawBeanstalk(ObjBean* pthis, GlobalContext* globalCtx) {
    Matrix_Translate(pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->dyna.actor.shape.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_Scale(0.1f, pthis->stalkSizeMultiplier, 0.1f, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, gMagicBeanStemDL);
}

void ObjBean_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ObjBean* pthis = (ObjBean*)thisx;

    if (pthis->stateFlags & BEAN_STATE_DRAW_SOIL) {
        Gfx_DrawDListOpa(globalCtx, gMagicBeanSeedlingDL);
    }
    if (pthis->stateFlags & BEAN_STATE_DRAW_PLANT) {
        Gfx_DrawDListOpa(globalCtx, gMagicBeanPlatformDL);
    }
    if (pthis->stateFlags & BEAN_STATE_DRAW_LEAVES) {
        ObjBean_DrawSoftSoilSpot(pthis, globalCtx);
    }
    if (pthis->stateFlags & BEAN_STATE_DRAW_STALK) {
        ObjBean_DrawBeanstalk(pthis, globalCtx);
    }
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_DDAN_KD_Z_BG_DDAN_KD_C
#include "actor_common.h"
/*
 * File: z_bg_ddan_kd.c
 * Overlay: ovl_Bg_Ddan_Kd
 * Description: Falling stairs in Dodongo's Cavern
 */

#include "z_bg_ddan_kd.h"
#include "objects/object_ddan_objects/object_ddan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS ACTOR_FLAG_4

void BgDdanKd_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanKd_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanKd_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanKd_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanKd_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgDdanKd_CheckForExplosions(BgDdanKd* pthis, GlobalContext* globalCtx);
void BgDdanKd_LowerStairs(BgDdanKd* pthis, GlobalContext* globalCtx);
void BgDdanKd_DoNothing(BgDdanKd* pthis, GlobalContext* globalCtx);

ActorInit Bg_Ddan_Kd_InitVars = {
    ACTOR_BG_DDAN_KD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DDAN_OBJECTS,
    sizeof(BgDdanKd),
    (ActorFunc)BgDdanKd_Init,
    (ActorFunc)BgDdanKd_Destroy,
    (ActorFunc)BgDdanKd_Update,
    (ActorFunc)BgDdanKd_Draw,
    (ActorFunc)BgDdanKd_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ALL,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 245, 180, -400, { 0, 0, 0 } },
};

static Vec3f velocity = { 0.0f, 5.0f, 0.0f };
static Vec3f accel = { 0.0f, -0.45f, 0.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 32767, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 32767, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 32767, ICHAIN_STOP),
};

void BgDdanKd_SetupAction(BgDdanKd* pthis, BgDdanKdActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgDdanKd_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgDdanKd* pthis = (BgDdanKd*)pthisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    pthis->prevExplosive = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
    CollisionHeader_GetVirtual(&gDodongoFallingStairsCol, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (!Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
        BgDdanKd_SetupAction(pthis, BgDdanKd_CheckForExplosions);
    } else {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 200.0f - 20.0f;
        BgDdanKd_SetupAction(pthis, BgDdanKd_DoNothing);
    }
}

void BgDdanKd_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgDdanKd* pthis = (BgDdanKd*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void BgDdanKd_CheckForExplosions(BgDdanKd* pthis, GlobalContext* globalCtx) {
    Actor* explosive;

    explosive = Actor_GetCollidedExplosive(globalCtx, &pthis->collider.base);
    if (explosive != NULL) {
        osSyncPrintf("dam    %d\n", pthis->dyna.actor.colChkInfo.damage);
        explosive->params = 2;
    }

    if ((explosive != NULL) && (pthis->prevExplosive != NULL) && (explosive != pthis->prevExplosive) &&
        (Math_Vec3f_DistXZ(&pthis->prevExplosivePos, &explosive->world.pos) > 80.0f)) {
        BgDdanKd_SetupAction(pthis, BgDdanKd_LowerStairs);
        OnePointCutscene_Init(globalCtx, 3050, 999, &pthis->dyna.actor, MAIN_CAM);
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        } else {
            pthis->prevExplosive = explosive;
            if (explosive != NULL) {
                pthis->timer = 13;
                pthis->prevExplosivePos = explosive->world.pos;
            }
        }
        Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void BgDdanKd_LowerStairs(BgDdanKd* pthis, GlobalContext* globalCtx) {
    Vec3f pos1;
    Vec3f pos2;
    f32 effectStrength;

    Math_SmoothStepToF(&pthis->dyna.actor.speedXZ, 4.0f, 0.5f, 0.025f, 0.0f);
    func_800AA000(500.0f, 0x78, 0x14, 0xA);

    if (Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 200.0f - 20.0f, 0.075f,
                           pthis->dyna.actor.speedXZ, 0.0075f) == 0.0f) {
        Flags_SetSwitch(globalCtx, pthis->dyna.actor.params);
        BgDdanKd_SetupAction(pthis, BgDdanKd_DoNothing);
    } else {
        effectStrength =
            (pthis->dyna.actor.prevPos.y - pthis->dyna.actor.world.pos.y) + (pthis->dyna.actor.speedXZ * 0.25f);

        if (globalCtx->state.frames & 1) {
            pos1 = pos2 = pthis->dyna.actor.world.pos;

            if (globalCtx->state.frames & 2) {
                pos1.z += 210.0f + Rand_ZeroOne() * 230.0f;
                pos2.z += 210.0f + Rand_ZeroOne() * 230.0f;
            } else {
                pos1.z += 330.0f + Rand_ZeroOne() * 240.0f;
                pos2.z += 330.0f + Rand_ZeroOne() * 240.0f;
            }
            pos1.x += 80.0f + Rand_ZeroOne() * 10.0f;
            pos2.x -= 80.0f + Rand_ZeroOne() * 10.0f;
            pos1.y = pthis->dyna.actor.floorHeight + 20.0f + Rand_ZeroOne();
            pos2.y = pthis->dyna.actor.floorHeight + 20.0f + Rand_ZeroOne();

            func_80033480(globalCtx, &pos1, 20.0f, 1, effectStrength * 135.0f, 60, 1);
            func_80033480(globalCtx, &pos2, 20.0f, 1, effectStrength * 135.0f, 60, 1);

            velocity.x = Rand_CenteredFloat(3.0f);
            velocity.z = Rand_CenteredFloat(3.0f);

            func_8003555C(globalCtx, &pos1, &velocity, &accel);
            func_8003555C(globalCtx, &pos2, &velocity, &accel);

            pos1 = pthis->dyna.actor.world.pos;
            pos1.z += 560.0f + Rand_ZeroOne() * 5.0f;
            pos1.x += (Rand_ZeroOne() - 0.5f) * 160.0f;
            pos1.y = Rand_ZeroOne() * 3.0f + (pthis->dyna.actor.floorHeight + 20.0f);

            func_80033480(globalCtx, &pos1, 20.0f, 1, effectStrength * 135.0f, 60, 1);
            func_8003555C(globalCtx, &pos1, &velocity, &accel);
        }
        Camera_AddQuake(&globalCtx->mainCamera, 0, effectStrength * 0.6f, 3);
        Audio_PlaySoundGeneral(NA_SE_EV_PILLAR_SINK - SFX_FLAG, &pthis->dyna.actor.projectedPos, 4, &D_801333E0,
                               &D_801333E0, &D_801333E8);
    }
}

void BgDdanKd_DoNothing(BgDdanKd* pthis, GlobalContext* globalCtx) {
}

void BgDdanKd_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgDdanKd* pthis = (BgDdanKd*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgDdanKd_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gDodongoFallingStairsDL);
}

void BgDdanKd_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Ddan_Kd_InitVars = {
        ACTOR_BG_DDAN_KD,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_DDAN_OBJECTS,
        sizeof(BgDdanKd),
        (ActorFunc)BgDdanKd_Init,
        (ActorFunc)BgDdanKd_Destroy,
        (ActorFunc)BgDdanKd_Update,
        (ActorFunc)BgDdanKd_Draw,
        (ActorFunc)BgDdanKd_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_ALL,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 245, 180, -400, { 0, 0, 0 } },
    };

    velocity = { 0.0f, 5.0f, 0.0f };

    accel = { 0.0f, -0.45f, 0.0f };

}

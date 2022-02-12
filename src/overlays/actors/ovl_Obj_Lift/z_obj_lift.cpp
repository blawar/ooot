#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_LIFT_Z_OBJ_LIFT_C
#include "actor_common.h"
/*
 * File: z_obj_lift.c
 * Overlay: ovl_Obj_Lift
 * Description: Square, collapsing platform
 */

#include "z_obj_lift.h"
#include "objects/object_d_lift/object_d_lift.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_quake.h"

#define FLAGS ACTOR_FLAG_4

void ObjLift_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjLift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjLift_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjLift_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B9651C(ObjLift* pthis);
void func_80B9664C(ObjLift* pthis);
void func_80B967C0(ObjLift* pthis);

void func_80B96560(ObjLift* pthis, GlobalContext* globalCtx);
void func_80B96678(ObjLift* pthis, GlobalContext* globalCtx);
void func_80B96840(ObjLift* pthis, GlobalContext* globalCtx);

ActorInit Obj_Lift_InitVars = {
    ACTOR_OBJ_LIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_LIFT,
    sizeof(ObjLift),
    (ActorFunc)ObjLift_Init,
    (ActorFunc)ObjLift_Destroy,
    (ActorFunc)ObjLift_Update,
    (ActorFunc)ObjLift_Draw,
};

static s16 sFallTimerDurations[] = { 0, 10, 20, 30, 40, 50, 60 };

typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
} ObjLiftFramgentScale; // size = 0x4

static ObjLiftFramgentScale sFragmentScales[] = {
    { 120, -120 }, { 120, 0 },     { 120, 120 }, { 0, -120 },   { 0, 0 },
    { 0, 120 },    { -120, -120 }, { -120, 0 },  { -120, 120 },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -600, ICHAIN_CONTINUE),   ICHAIN_F32_DIV1000(minVelocityY, -15000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2000, ICHAIN_STOP),
};

static f32 sScales[] = { 0.1f, 0.05f };
static f32 sMaxFallDistances[] = { -18.0f, -9.0f };

void ObjLift_SetupAction(ObjLift* pthis, ObjLiftActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void ObjLift_InitDynaPoly(ObjLift* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_lift.c", 188,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void func_80B96160(ObjLift* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f velocity;
    Vec3f* temp_s3;
    s32 pad0;
    s32 i;

    temp_s3 = &pthis->dyna.actor.world.pos;

    for (i = 0; i < ARRAY_COUNT(sFragmentScales); i++) {
        pos.x = sFragmentScales[i].x * pthis->dyna.actor.scale.x + temp_s3->x;
        pos.y = temp_s3->y;
        pos.z = sFragmentScales[i].z * pthis->dyna.actor.scale.z + temp_s3->z;
        velocity.x = sFragmentScales[i].x * pthis->dyna.actor.scale.x * 0.8f;
        velocity.y = Rand_ZeroOne() * 10.0f + 6.0f;
        velocity.z = sFragmentScales[i].z * pthis->dyna.actor.scale.z * 0.8f;
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, temp_s3, -256, (Rand_ZeroOne() < 0.5f) ? 64 : 32, 15, 15, 0,
                             (Rand_ZeroOne() * 50.0f + 50.0f) * pthis->dyna.actor.scale.x, 0, 32, 50, KAKERA_COLOR_NONE,
                             OBJECT_D_LIFT, gCollapsingPlatformDL);
    }

    if (((pthis->dyna.actor.params >> 1) & 1) == 0) {
        func_80033480(globalCtx, &pthis->dyna.actor.world.pos, 120.0f, 12, 120, 100, 1);
    } else if (((pthis->dyna.actor.params >> 1) & 1) == 1) {
        func_80033480(globalCtx, &pthis->dyna.actor.world.pos, 60.0f, 8, 60, 100, 1);
    }
}

void ObjLift_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjLift* pthis = (ObjLift*)thisx;

    ObjLift_InitDynaPoly(pthis, globalCtx, &gCollapsingPlatformCol, DPM_PLAYER);

    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 2) & 0x3F)) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }

    Actor_SetScale(&pthis->dyna.actor, sScales[(pthis->dyna.actor.params >> 1) & 1]);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->unk168.x = Rand_ZeroOne() * 65535.5f;
    pthis->unk168.y = Rand_ZeroOne() * 65535.5f;
    pthis->unk168.z = Rand_ZeroOne() * 65535.5f;
    func_80B9651C(pthis);
    osSyncPrintf("(Dungeon Lift)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void ObjLift_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjLift* pthis = (ObjLift*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80B9651C(ObjLift* pthis) {
    pthis->timer = sFallTimerDurations[(pthis->dyna.actor.params >> 8) & 7];
    ObjLift_SetupAction(pthis, func_80B96560);
}

void func_80B96560(ObjLift* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 quakeIndex;

    if (func_8004356C(&pthis->dyna)) {
        if (pthis->timer <= 0) {
            if (((pthis->dyna.actor.params >> 8) & 7) == 7) {
                func_80B967C0(pthis);
            } else {
                quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 1);
                Quake_SetSpeed(quakeIndex, 10000);
                Quake_SetQuakeValues(quakeIndex, 2, 0, 0, 0);
                Quake_SetCountdown(quakeIndex, 20);
                func_80B9664C(pthis);
            }
        }
    } else {
        pthis->timer = sFallTimerDurations[(pthis->dyna.actor.params >> 8) & 7];
    }
}

void func_80B9664C(ObjLift* pthis) {
    pthis->timer = 20;
    ObjLift_SetupAction(pthis, func_80B96678);
}

void func_80B96678(ObjLift* pthis, GlobalContext* globalCtx) {
    if (pthis->timer <= 0) {
        func_80B967C0(pthis);
    } else {
        pthis->unk168.x += 10000;
        pthis->dyna.actor.world.rot.x = (s16)(Math_SinS(pthis->unk168.x) * 300.0f) + pthis->dyna.actor.home.rot.x;
        pthis->dyna.actor.world.rot.z = (s16)(Math_CosS(pthis->unk168.x) * 300.0f) + pthis->dyna.actor.home.rot.z;
        pthis->dyna.actor.shape.rot.x = pthis->dyna.actor.world.rot.x;
        pthis->dyna.actor.shape.rot.z = pthis->dyna.actor.world.rot.z;
        pthis->unk168.y += 18000;
        pthis->dyna.actor.world.pos.y = Math_SinS(pthis->unk168.y) + pthis->dyna.actor.home.pos.y;
        pthis->unk168.z += 18000;
        pthis->dyna.actor.world.pos.x = Math_SinS(pthis->unk168.z) * 3.0f + pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.world.pos.z = Math_CosS(pthis->unk168.z) * 3.0f + pthis->dyna.actor.home.pos.z;
    }

    if ((pthis->timer & 3) == 3) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 16, NA_SE_EV_BLOCK_SHAKE);
    }
}

void func_80B967C0(ObjLift* pthis) {
    ObjLift_SetupAction(pthis, func_80B96840);
    Math_Vec3f_Copy(&pthis->dyna.actor.world.pos, &pthis->dyna.actor.home.pos);
    pthis->dyna.actor.shape.rot = pthis->dyna.actor.world.rot = pthis->dyna.actor.home.rot;
}

void func_80B96840(ObjLift* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 bgId;
    Vec3f sp2C;

    Actor_MoveForward(&pthis->dyna.actor);
    Math_Vec3f_Copy(&sp2C, &pthis->dyna.actor.prevPos);
    sp2C.y += sMaxFallDistances[(pthis->dyna.actor.params >> 1) & 1];
    pthis->dyna.actor.floorHeight =
        BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly, &bgId, &pthis->dyna.actor, &sp2C);

    if ((pthis->dyna.actor.floorHeight - pthis->dyna.actor.world.pos.y) >=
        (sMaxFallDistances[(pthis->dyna.actor.params >> 1) & 1] - 0.001f)) {
        func_80B96160(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 20, NA_SE_EV_BOX_BREAK);
        Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 2) & 0x3F);
        Actor_Kill(&pthis->dyna.actor);
    }
}

void ObjLift_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjLift* pthis = (ObjLift*)thisx;

    if (pthis->timer > 0) {
        pthis->timer--;
    }

    pthis->actionFunc(pthis, globalCtx);
}

void ObjLift_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gCollapsingPlatformDL);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MIZU_SHUTTER_Z_BG_MIZU_SHUTTER_C
#include "actor_common.h"
#include "z_bg_mizu_shutter.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

#define SIZE_PARAM (((u16)pthis->dyna.actor.params >> 0xC) & 0xF)
#define TIMER_PARAM (((u16)pthis->dyna.actor.params >> 6) & 0x3F)

void BgMizuShutter_Init(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMizuShutter_Destroy(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_Update(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_Draw(BgMizuShutter* pthis, GlobalContext* globalCtx);

void BgMizuShutter_WaitForTimer(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_WaitForSwitch(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_Move(BgMizuShutter* pthis, GlobalContext* globalCtx);
void BgMizuShutter_WaitForCutscene(BgMizuShutter* pthis, GlobalContext* globalCtx);

ActorInit Bg_Mizu_Shutter_InitVars = {
    ACTOR_BG_MIZU_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuShutter),
    (ActorFunc)BgMizuShutter_Init,
    (ActorFunc)BgMizuShutter_Destroy,
    (ActorFunc)BgMizuShutter_Update,
    (ActorFunc)BgMizuShutter_Draw,
    (ActorFunc)BgMizuShutter_Reset,
};

static Gfx* sDisplayLists[] = { gObjectMizuObjectsShutterDL_007130, gObjectMizuObjectsShutterDL_0072D0 };

static CollisionHeader* sCollisionHeaders[] = {
    &gObjectMizuObjectsShutterCol_007250,
    &gObjectMizuObjectsShutterCol_0073F0,
};

static Vec3f sDisplacements[] = {
    { 0.0f, 100.0f, 0.0f },
    { 0.0f, 140.0f, 0.0f },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgMizuShutter_Init(BgMizuShutter* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMizuShutter* pthis = (BgMizuShutter*)thisx;
    s32 pad2;
    CollisionHeader* sp30 = NULL;
    s32 pad3;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->displayList = sDisplayLists[SIZE_PARAM];
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(sCollisionHeaders[SIZE_PARAM], &sp30);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, sp30);
    if ((SIZE_PARAM == BGMIZUSHUTTER_SMALL) || (SIZE_PARAM == BGMIZUSHUTTER_LARGE)) {
        pthis->closedPos = pthis->dyna.actor.world.pos;
        pthis->timer = 0;
        pthis->timerMax = TIMER_PARAM * 20;
        Matrix_RotateY(pthis->dyna.actor.world.rot.y * (M_PI / 0x8000), MTXMODE_NEW);
        Matrix_RotateX(pthis->dyna.actor.world.rot.x * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_RotateZ(pthis->dyna.actor.world.rot.z * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_MultVec3f(&sDisplacements[SIZE_PARAM], &pthis->openPos);
        pthis->openPos.x += pthis->dyna.actor.world.pos.x;
        pthis->openPos.y += pthis->dyna.actor.world.pos.y;
        pthis->openPos.z += pthis->dyna.actor.world.pos.z;
        if (pthis->timerMax != 0x3F * 20) {
            Flags_UnsetSwitch(globalCtx, (u16)pthis->dyna.actor.params & 0x3F);
            pthis->dyna.actor.world.pos = pthis->closedPos;
        }
        if (Flags_GetSwitch(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
            pthis->dyna.actor.world.pos = pthis->openPos;
            pthis->actionFunc = BgMizuShutter_WaitForTimer;
        } else {
            pthis->actionFunc = BgMizuShutter_WaitForSwitch;
        }
    }
}

void BgMizuShutter_Destroy(BgMizuShutter* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMizuShutter* pthis = (BgMizuShutter*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgMizuShutter_WaitForSwitch(BgMizuShutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
        if (ABS(pthis->dyna.actor.world.rot.x) > 0x2C60) {
            OnePointCutscene_Init(globalCtx, 4510, -99, &pthis->dyna.actor, MAIN_CAM);
        } else {
            OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        }
        pthis->actionFunc = BgMizuShutter_WaitForCutscene;
        pthis->timer = 30;
    }
}

void BgMizuShutter_WaitForCutscene(BgMizuShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->timer-- == 0) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_OPEN);
        pthis->actionFunc = BgMizuShutter_Move;
    }
}

void BgMizuShutter_Move(BgMizuShutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.x, pthis->openPos.x, 1.0f, 4.0f, 0.1f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->openPos.y, 1.0f, 4.0f, 0.1f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.z, pthis->openPos.z, 1.0f, 4.0f, 0.1f);
        if ((pthis->dyna.actor.world.pos.x == pthis->openPos.x) && (pthis->dyna.actor.world.pos.y == pthis->openPos.y) &&
            (pthis->dyna.actor.world.pos.z == pthis->openPos.z)) {
            pthis->timer = pthis->timerMax;
            pthis->actionFunc = BgMizuShutter_WaitForTimer;
        }
    } else {
        Math_SmoothStepToF(&pthis->maxSpeed, 20.0f, 1.0f, 3.0f, 0.1f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.x, pthis->closedPos.x, 1.0f, pthis->maxSpeed, 0.1f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->closedPos.y, 1.0f, pthis->maxSpeed, 0.1f);
        Math_SmoothStepToF(&pthis->dyna.actor.world.pos.z, pthis->closedPos.z, 1.0f, pthis->maxSpeed, 0.1f);
        if ((pthis->dyna.actor.world.pos.x == pthis->closedPos.x) &&
            (pthis->dyna.actor.world.pos.y == pthis->closedPos.y) &&
            (pthis->dyna.actor.world.pos.z == pthis->closedPos.z)) {
            func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0x78, 0x14, 0xA);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
            pthis->actionFunc = BgMizuShutter_WaitForSwitch;
        }
    }
}

void BgMizuShutter_WaitForTimer(BgMizuShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->timerMax != 0x3F * 20) {
        pthis->timer--;
        func_8002F994(&pthis->dyna.actor, pthis->timer);
        if (pthis->timer == 0) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_CLOSE);
            Flags_UnsetSwitch(globalCtx, (u16)pthis->dyna.actor.params & 0x3F);
            pthis->actionFunc = BgMizuShutter_Move;
        }
    }
}

void BgMizuShutter_Update(BgMizuShutter* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMizuShutter* pthis = (BgMizuShutter*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgMizuShutter_Draw(BgMizuShutter* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMizuShutter* pthis = (BgMizuShutter*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_shutter.c", 410);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mizu_shutter.c", 415),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (pthis->displayList != NULL) {
        gSPDisplayList(POLY_OPA_DISP++, pthis->displayList);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_shutter.c", 422);
}

void BgMizuShutter_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Mizu_Shutter_InitVars = {
        ACTOR_BG_MIZU_SHUTTER,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_MIZU_OBJECTS,
        sizeof(BgMizuShutter),
        (ActorFunc)BgMizuShutter_Init,
        (ActorFunc)BgMizuShutter_Destroy,
        (ActorFunc)BgMizuShutter_Update,
        (ActorFunc)BgMizuShutter_Draw,
        (ActorFunc)BgMizuShutter_Reset,
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_KOUSI_Z_BG_HIDAN_KOUSI_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_kousi.c
 * Overlay: ovl_Bg_Hidan_Kousi
 * Description:
 */

#include "z_bg_hidan_kousi.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgHidanKousi_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanKousi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanKousi_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanKousi_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80889ACC(BgHidanKousi* pthis);
void func_80889B5C(BgHidanKousi* pthis, GlobalContext* globalCtx);
void func_80889BC0(BgHidanKousi* pthis, GlobalContext* globalCtx);
void func_80889C18(BgHidanKousi* pthis, GlobalContext* globalCtx);
void func_80889C90(BgHidanKousi* pthis, GlobalContext* globalCtx);
void func_80889D28(BgHidanKousi* pthis, GlobalContext* globalCtx);

static f32 D_80889E40[] = { 120.0f, 150.0f, 150.0f };

ActorInit Bg_Hidan_Kousi_InitVars = {
    ACTOR_BG_HIDAN_KOUSI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanKousi),
    (ActorFunc)BgHidanKousi_Init,
    (ActorFunc)BgHidanKousi_Destroy,
    (ActorFunc)BgHidanKousi_Update,
    (ActorFunc)BgHidanKousi_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static CollisionHeader* sMetalFencesCollisions[] = {
    &gFireTempleMetalFenceWithSlantCol,
    &gFireTempleMetalFenceCol,
    &gFireTempleMetalFence2Col,
};

static s16 D_80889E7C[] = {
    0x4000,
    0xC000,
    0xC000,
    0x0000,
};

static Gfx* sMetalFencesDLs[] = {
    gFireTempleMetalFenceWithSlantDL,
    gFireTempleMetalFenceDL,
    gFireTempleMetalFence2DL,
};

void BgHidanKousi_SetupAction(BgHidanKousi* pthis, BgHidanKousiActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgHidanKousi_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanKousi* pthis = (BgHidanKousi*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    Actor_SetFocus(thisx, 50.0f);
    osSyncPrintf("◯◯◯炎の神殿オブジェクト【格子(arg_data : %0x)】出現 (%d %d)\n", thisx->params, thisx->params & 0xFF,
                 ((s32)thisx->params >> 8) & 0xFF);

    Actor_ProcessInitChain(thisx, sInitChain);
    if (((thisx->params & 0xFF) < 0) || ((thisx->params & 0xFF) >= 3)) {
        osSyncPrintf("arg_data おかしい 【格子】\n");
    }

    CollisionHeader_GetVirtual(sMetalFencesCollisions[thisx->params & 0xFF], &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    thisx->world.rot.y = D_80889E7C[pthis->dyna.actor.params & 0xFF] + thisx->shape.rot.y;
    if (Flags_GetSwitch(globalCtx, (thisx->params >> 8) & 0xFF)) {
        func_80889ACC(pthis);
        BgHidanKousi_SetupAction(pthis, func_80889D28);
    } else {
        BgHidanKousi_SetupAction(pthis, func_80889B5C);
    }
}

void BgHidanKousi_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanKousi* pthis = (BgHidanKousi*)thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80889ACC(BgHidanKousi* pthis) {
    s32 pad[2];
    Vec3s* rot = &pthis->dyna.actor.world.rot;
    f32 temp1 = D_80889E40[pthis->dyna.actor.params & 0xFF] * Math_SinS(rot->y);
    f32 temp2 = D_80889E40[pthis->dyna.actor.params & 0xFF] * Math_CosS(rot->y);

    pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x + temp1;
    pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z + temp2;
}

void func_80889B5C(BgHidanKousi* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0xFF)) {
        BgHidanKousi_SetupAction(pthis, func_80889BC0);
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        pthis->unk_168 = 0xC8;
    }
}

void func_80889BC0(BgHidanKousi* pthis, GlobalContext* globalCtx) {
    pthis->unk_168 -= 1;
    if (pthis->dyna.actor.category == func_8005B198() || (pthis->unk_168 <= 0)) {
        BgHidanKousi_SetupAction(pthis, func_80889C18);
    }
}

void func_80889C18(BgHidanKousi* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.speedXZ += 0.2f;
    if (pthis->dyna.actor.speedXZ > 2.0f) {
        pthis->dyna.actor.speedXZ = 2.0f;
        BgHidanKousi_SetupAction(pthis, func_80889C90);
    }
    Actor_MoveForward(&pthis->dyna.actor);
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
}

void func_80889C90(BgHidanKousi* pthis, GlobalContext* globalCtx) {
    func_8002D7EC(&pthis->dyna.actor);
    if (D_80889E40[pthis->dyna.actor.params & 0xFF] <
        Math_Vec3f_DistXYZ(&pthis->dyna.actor.home.pos, &pthis->dyna.actor.world.pos)) {
        func_80889ACC(pthis);
        BgHidanKousi_SetupAction(pthis, func_80889D28);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
    }
}

void func_80889D28(BgHidanKousi* pthis, GlobalContext* globalCtx) {
}

void BgHidanKousi_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanKousi* pthis = (BgHidanKousi*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHidanKousi_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_kousi.c", 350);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_kousi.c", 354),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, sMetalFencesDLs[thisx->params & 0xFF]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_kousi.c", 359);
}

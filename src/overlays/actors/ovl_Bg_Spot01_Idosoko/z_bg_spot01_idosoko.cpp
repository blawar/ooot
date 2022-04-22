#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT01_IDOSOKO_Z_BG_SPOT01_IDOSOKO_C
#include "actor_common.h"
/*
 * File: z_bg_spot01_idosoko.c
 * Overlay: ovl_Bg_Spot01_Idosoko
 * Description: Stone that blocks the entrance to Bottom of the Well
 */

#include "z_bg_spot01_idosoko.h"
#include "objects/object_spot01_matoya/object_spot01_matoya.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgSpot01Idosoko_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idosoko_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot01Idosoko_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idosoko_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idosoko_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808ABF54(BgSpot01Idosoko* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot01_Idosoko_InitVars = {
    ACTOR_BG_SPOT01_IDOSOKO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT01_MATOYA,
    sizeof(BgSpot01Idosoko),
    (ActorFunc)BgSpot01Idosoko_Init,
    (ActorFunc)BgSpot01Idosoko_Destroy,
    (ActorFunc)BgSpot01Idosoko_Update,
    (ActorFunc)BgSpot01Idosoko_Draw,
    (ActorFunc)BgSpot01Idosoko_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot01Idosoko_SetupAction(BgSpot01Idosoko* pthis, BgSpot01IdosokoActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgSpot01Idosoko_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot01Idosoko* pthis = (BgSpot01Idosoko*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    CollisionHeader_GetVirtual(&gKakarikoBOTWStoneCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (!LINK_IS_ADULT) {
        Actor_Kill(&pthis->dyna.actor);
    } else {
        BgSpot01Idosoko_SetupAction(pthis, func_808ABF54);
    }
}

void BgSpot01Idosoko_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idosoko* pthis = (BgSpot01Idosoko*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808ABF54(BgSpot01Idosoko* pthis, GlobalContext* globalCtx) {
}

void BgSpot01Idosoko_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idosoko* pthis = (BgSpot01Idosoko*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot01Idosoko_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_idosoko.c", 162);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot01_idosoko.c", 166),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gKakarikoBOTWStoneDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_idosoko.c", 171);
}

void BgSpot01Idosoko_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot01_Idosoko_InitVars = {
        ACTOR_BG_SPOT01_IDOSOKO,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SPOT01_MATOYA,
        sizeof(BgSpot01Idosoko),
        (ActorFunc)BgSpot01Idosoko_Init,
        (ActorFunc)BgSpot01Idosoko_Destroy,
        (ActorFunc)BgSpot01Idosoko_Update,
        (ActorFunc)BgSpot01Idosoko_Draw,
        (ActorFunc)BgSpot01Idosoko_Reset,
    };

}

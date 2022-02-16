#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT07_TAKI_Z_BG_SPOT07_TAKI_C
#include "actor_common.h"
/*
 * File: z_bg_spot07_taki.c
 * Overlay: ovl_Bg_Spot07_Taki
 * Description: Zora's Domain Waterfall and Ice
 */

#include "z_bg_spot07_taki.h"
#include "objects/object_spot07_object/object_spot07_object.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSpot07Taki_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot07Taki_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot07Taki_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot07Taki_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot07Taki_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgSpot07Taki_DoNothing(BgSpot07Taki* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot07_Taki_InitVars = {
    ACTOR_BG_SPOT07_TAKI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT07_OBJECT,
    sizeof(BgSpot07Taki),
    (ActorFunc)BgSpot07Taki_Init,
    (ActorFunc)BgSpot07Taki_Destroy,
    (ActorFunc)BgSpot07Taki_Update,
    (ActorFunc)BgSpot07Taki_Draw,
    (ActorFunc)BgSpot07Taki_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot07Taki_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot07Taki* pthis = (BgSpot07Taki*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    if (LINK_IS_ADULT) {
        if (pthis->dyna.actor.params == 0) {
            CollisionHeader_GetVirtual(&object_spot07_object_Col_002590, &colHeader);
        } else {
            CollisionHeader_GetVirtual(&object_spot07_object_Col_0038FC, &colHeader);
        }
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    }
    pthis->actionFunc = BgSpot07Taki_DoNothing;
}

void BgSpot07Taki_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot07Taki* pthis = (BgSpot07Taki*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgSpot07Taki_DoNothing(BgSpot07Taki* pthis, GlobalContext* globalCtx) {
}

void BgSpot07Taki_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot07Taki* pthis = (BgSpot07Taki*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot07Taki_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot07Taki* pthis = (BgSpot07Taki*)thisx;
    u32 frames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot07_taki.c", 169);
    frames = globalCtx->gameplayFrames;
    if (LINK_IS_ADULT) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot07_taki.c", 177),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (pthis->dyna.actor.params == 0) {
            gSPDisplayList(POLY_OPA_DISP++, object_spot07_object_DL_001CF0);
        } else {
            gSPDisplayList(POLY_OPA_DISP++, object_spot07_object_DL_003210);
        }
    }
    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot07_taki.c", 191),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, ((frames * -1) & 0x7F), ((frames * 1) & 0x7F), 32, 32, 1,
                                ((frames * 1) & 0x7F), ((frames * 1) & 0x7F), 32, 32));

    if (!LINK_IS_ADULT) {
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);
        if (pthis->dyna.actor.params == 0) {
            gSPSegment(POLY_XLU_DISP++, 0x09,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, ((frames * -1) & 0x7F), ((frames * -3) & 0xFF), 64,
                                        64, 1, ((frames * 1) & 0x7F), ((frames * -3) & 0xFF), 64, 64));
            gSPSegment(POLY_XLU_DISP++, 0x0A,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, frames * 0, ((frames * 3) & 0x1FF), 32, 128, 1,
                                        frames * 0, ((frames * 3) & 0x1FF), 32, 128));
            gSPDisplayList(POLY_XLU_DISP++, object_spot07_object_DL_000460);
        } else {
            gSPSegment(POLY_XLU_DISP++, 0x09,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, frames * 0, ((frames * -1) & 0x7F), 32, 32, 1,
                                        frames * 0, ((frames * -1) & 0x7F), 32, 32));
            gSPSegment(POLY_XLU_DISP++, 0x0A,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, frames * 0, ((frames * 3) & 0x1FF), 32, 128, 1,
                                        frames * 0, ((frames * 3) & 0x1FF), 32, 128));
            gSPDisplayList(POLY_XLU_DISP++, object_spot07_object_DL_000BE0);
        }
    } else if (pthis->dyna.actor.params == 0) {
        gSPDisplayList(POLY_XLU_DISP++, object_spot07_object_DL_001F68);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, object_spot07_object_DL_0032D8);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot07_taki.c", 272);
}

void BgSpot07Taki_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot07_Taki_InitVars = {
        ACTOR_BG_SPOT07_TAKI,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SPOT07_OBJECT,
        sizeof(BgSpot07Taki),
        (ActorFunc)BgSpot07Taki_Init,
        (ActorFunc)BgSpot07Taki_Destroy,
        (ActorFunc)BgSpot07Taki_Update,
        (ActorFunc)BgSpot07Taki_Draw,
        (ActorFunc)BgSpot07Taki_Reset,
    };

}

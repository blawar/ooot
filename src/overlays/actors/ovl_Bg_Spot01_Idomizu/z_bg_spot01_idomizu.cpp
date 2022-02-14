#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT01_IDOMIZU_Z_BG_SPOT01_IDOMIZU_C
#include "actor_common.h"
/*
 * File: z_bg_spot01_idomizu.c
 * Overlay: ovl_Bg_Spot01_Idomizu
 * Description: Kakariko Village Well Water
 */

#include "z_bg_spot01_idomizu.h"
#include "objects/object_spot01_objects/object_spot01_objects.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_5

void BgSpot01Idomizu_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idomizu_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idomizu_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idomizu_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808ABB84(BgSpot01Idomizu* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot01_Idomizu_InitVars = {
    ACTOR_BG_SPOT01_IDOMIZU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT01_OBJECTS,
    sizeof(BgSpot01Idomizu),
    (ActorFunc)BgSpot01Idomizu_Init,
    (ActorFunc)BgSpot01Idomizu_Destroy,
    (ActorFunc)BgSpot01Idomizu_Update,
    (ActorFunc)BgSpot01Idomizu_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot01Idomizu_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idomizu* pthis = (BgSpot01Idomizu*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    if (gSaveContext.eventChkInf[6] & 0x80 || LINK_AGE_IN_YEARS == YEARS_ADULT) {
        pthis->waterHeight = -550.0f;
    } else {
        pthis->waterHeight = 52.0f;
    }
    pthis->actionFunc = func_808ABB84;
    pthis->actor.world.pos.y = pthis->waterHeight;
}

void BgSpot01Idomizu_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_808ABB84(BgSpot01Idomizu* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.eventChkInf[6] & 0x80) {
        pthis->waterHeight = -550.0f;
    }
    globalCtx->colCtx.colHeader->waterBoxes[0].ySurface = pthis->actor.world.pos.y;
    if (pthis->waterHeight < pthis->actor.world.pos.y) {
        Audio_PlaySoundGeneral(NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
    Math_ApproachF(&pthis->actor.world.pos.y, pthis->waterHeight, 1.0f, 2.0f);
}

void BgSpot01Idomizu_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idomizu* pthis = (BgSpot01Idomizu*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot01Idomizu_Draw(Actor* thisx, GlobalContext* globalCtx) {
    const auto& frames = globalCtx->state.frames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_idomizu.c", 228);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot01_idomizu.c", 232),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 127 - frames % 128, frames & 0x7F, 32, 32, 1, frames % 128,
                                frames & 0x7F, 32, 32));

    gSPDisplayList(POLY_XLU_DISP++, gKakarikoWellWaterDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_idomizu.c", 244);
}

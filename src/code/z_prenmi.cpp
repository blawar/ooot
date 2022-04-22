#define INTERNAL_SRC_CODE_Z_PRENMI_C
#include "global.h"
#include "z_prenmi_buff.h"
#include "vt.h"
#include "def/z_prenmi.h"
#include "def/z_rcp.h"
#include "def/graph.h" // FORCE

void func_80092320(PreNMIContext* pthis) {
    pthis->state.running = false;
    pthis->state.init = NULL;
    pthis->state.size = 0;
}

void PreNMI_Update(PreNMIContext* pthis) {
    osSyncPrintf(VT_COL(YELLOW, BLACK) "prenmi_move\n" VT_RST);

    // Strings existing only in rodata
    if (0) {
        osSyncPrintf("../z_prenmi.c");
        osSyncPrintf("(int)volume = %d\n");
    }

    if (pthis->timer == 0) {
        func_80092320(pthis);
        return;
    }

    pthis->timer--;
}

void PreNMI_Draw(PreNMIContext* pthis) {
    GraphicsContext* gfxCtx = pthis->state.gfxCtx;

    osSyncPrintf(VT_COL(YELLOW, BLACK) "prenmi_draw\n" VT_RST);

    OPEN_DISPS(gfxCtx, "../z_prenmi.c", 96);

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    Gfx_ClearDisplay(gfxCtx, 0, 0, 0);
    func_800940B0(gfxCtx);
    gDPSetFillColor(POLY_OPA_DISP++, (GPACK_RGBA5551(255, 255, 255, 1) << 16) | GPACK_RGBA5551(255, 255, 255, 1));
    gDPFillRectangle(POLY_OPA_DISP++, 0, pthis->timer + 100, SCREEN_WIDTH - 1, pthis->timer + 100);

    CLOSE_DISPS(gfxCtx, "../z_prenmi.c", 112);
}

void PreNMI_Main(GameState* pthisx) {
    PreNMIContext* pthis = (PreNMIContext*)pthisx;

    PreNMI_Update(pthis);
    PreNMI_Draw(pthis);

    pthis->state.unk_A0 = 1;
}

void PreNMI_Destroy(GameState* pthisx) {
}

void PreNMI_Init(GameState* pthisx) {
    PreNMIContext* pthis = (PreNMIContext*)pthisx;

    pthis->state.main = PreNMI_Main;
    pthis->state.destroy = PreNMI_Destroy;
    pthis->timer = 30;
    pthis->unk_A8 = 10;

    R_UPDATE_RATE = 1;
}

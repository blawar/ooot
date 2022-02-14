#define INTERNAL_SRC_CODE_Z_SAMPLE_C
#include "global.h"
#include "gfx.h"
#include "framerate.h"
#include "segment_symbols.h"
#include "textures/title_static/title_static.h"
#include "z_sample.h"
#include "padmgr.h"
#include "z_player.h"
#include "def/game.h"
#include "def/graph.h"
#include "def/position.h"
#include "def/z_rcp.h"
#include "def/z_sample.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"
#include "def/z_play.h" // FORCE

void Sample_HandleStateChange(SampleContext* pthis) {
    if (CHECK_BTN_ALL(pthis->state.input[0].press.button, BTN_START)) {
        SET_NEXT_GAMESTATE(&pthis->state, Gameplay_Init, GlobalContext);
        pthis->state.running = false;
    }
}

void Sample_Draw(SampleContext* pthis) {
    GraphicsContext* gfxCtx = pthis->state.gfxCtx;
    View* view = &pthis->view;

    OPEN_DISPS(gfxCtx, "../z_sample.c", 62);

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    gSPSegment(POLY_OPA_DISP++, 0x01, pthis->staticSegment);

    Gfx_ClearDisplay(gfxCtx, 0, 0, 0);

    view->flags = 1 | 2 | 4;
    func_800AAA50(view, 15);

    {
        Mtx* mtx = (Mtx*)Graph_Alloc(gfxCtx, sizeof(Mtx));

        guPosition(mtx, SREG(37), SREG(38), SREG(39), 1.0f, SREG(40), SREG(41), SREG(42));
        gSPMatrix(POLY_OPA_DISP++, mtx, G_MTX_LOAD);
    }

    POLY_OPA_DISP = Gfx_SetFog2(POLY_OPA_DISP, 255, 255, 255, 0, 0, 0);
    func_80093D18(gfxCtx);

    gDPSetCycleType(POLY_OPA_DISP++, G_CYC_1CYCLE);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 0, 0);

    CLOSE_DISPS(gfxCtx, "../z_sample.c", 111);
}

void Sample_Main(GameState* pthisx) {
    SampleContext* pthis = (SampleContext*)pthisx;

    Sample_Draw(pthis);
    Sample_HandleStateChange(pthis);
}

void Sample_Destroy(GameState* pthisx) {
}

void Sample_SetupView(SampleContext* pthis) {
    View* view = &pthis->view;
    GraphicsContext* gfxCtx = pthis->state.gfxCtx;

    View_Init(view, gfxCtx);
    SET_FULLSCREEN_VIEWPORT(view);
    func_800AA460(view, 60.0f, 10.0f, 12800.0f);

    {
        Vec3f eye;
        Vec3f lookAt;
        Vec3f up;

        eye.x = 0.0f;
        eye.y = 0.0f;
        eye.z = 3000.0f;
        lookAt.x = 0.0f;
        lookAt.y = 0.0f;
        lookAt.z = 0.0f;
        up.x = 0.0f;
        up.z = 0.0f;
        up.y = 1.0f;

        func_800AA358(view, &eye, &lookAt, &up);
    }
}

void Sample_LoadTitleStatic(SampleContext* pthis) {
    u32 size = _title_staticSegmentRomEnd - _title_staticSegmentRomStart;

    pthis->staticSegment = (u8*)GameState_Alloc(&pthis->state, size, "../z_sample.c", 163);
    DmaMgr_SendRequest1(pthis->staticSegment, _title_staticSegmentRomStart, size, "../z_sample.c", 164);
}

void Sample_Init(GameState* pthisx) {
    SampleContext* pthis = (SampleContext*)pthisx;

    pthis->state.main = Sample_Main;
    pthis->state.destroy = Sample_Destroy;
    framerate_set_profile(PROFILE_SAMPLE);
    Sample_SetupView(pthis);
    Sample_LoadTitleStatic(pthis);

    SREG(37) = 0;
    SREG(38) = 0;
    SREG(39) = 0;
    SREG(40) = 0;
    SREG(41) = 0;
    SREG(42) = 0;
}

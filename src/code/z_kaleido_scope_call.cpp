#define INTERNAL_SRC_CODE_Z_KALEIDO_SCOPE_CALL_C
#include "global.h"
#include "z64global.h"
#include "kaleido.h"
#include "vt.h"
#include "def/shrink_window.h"
#include "def/z_kaleido_manager.h"
#include "def/z_kaleido_scope_call.h"
#include "def/z_kaleido_setup.h"

void (*sKaleidoScopeUpdateFunc)(GlobalContext* globalCtx);
void (*sKaleidoScopeDrawFunc)(GlobalContext* globalCtx);
f32 gBossMarkScale;
u32 D_8016139C;
PauseMapMarksData* gLoadedPauseMarkDataTable;

extern KaleidoMgrOverlay gKaleidoMgrOverlayTable[];
extern KaleidoMgrOverlay* gKaleidoMgrCurOvl;

extern void KaleidoScope_Update(GlobalContext* globalCtx);
extern void KaleidoScope_Draw(GlobalContext* globalCtx);

void KaleidoScopeCall_LoadPlayer() {
    KaleidoMgrOverlay* playerActorOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_PLAYER_ACTOR];

    if (gKaleidoMgrCurOvl != playerActorOvl) {
        if (gKaleidoMgrCurOvl != NULL) {
            osSyncPrintf(VT_FGCOL(GREEN));
            osSyncPrintf("Kaleido area forced exclusion\n"); // "Kaleido area forced exclusion"
            osSyncPrintf(VT_RST);

            KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
        }

        osSyncPrintf(VT_FGCOL(GREEN));
        osSyncPrintf("Player actor import\n"); // "Player actor import"
        osSyncPrintf(VT_RST);

        KaleidoManager_LoadOvl(playerActorOvl);
    }
}

void KaleidoScopeCall_Init(GlobalContext* globalCtx) {
    // "Kaleidoscope replacement construction"
    osSyncPrintf("Kaleidoscope replacement construction \n");

    sKaleidoScopeUpdateFunc = (void (*)(GlobalContext *))KaleidoManager_GetRamAddr(KaleidoScope_Update);
    sKaleidoScopeDrawFunc   = (void (*)(GlobalContext*))KaleidoManager_GetRamAddr(KaleidoScope_Draw);

    KaleidoSetup_Init(globalCtx);
}

void KaleidoScopeCall_Destroy(GlobalContext* globalCtx) {
    // "Kaleidoscope replacement destruction"
    osSyncPrintf("Kaleidoscope replacement destruction \n");

    KaleidoSetup_Destroy(globalCtx);
}

void KaleidoScopeCall_Update(GlobalContext* globalCtx) {
    KaleidoMgrOverlay* kaleidoScopeOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_KALEIDO_SCOPE];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;

    if ((pauseCtx->state != 0) || (pauseCtx->debugState != 0)) {
        if (pauseCtx->state == 1) {
            if (ShrinkWindow_GetCurrentVal() == 0) {
                HREG(80) = 7;
                HREG(82) = 3;
                R_PAUSE_MENU_MODE = 1;
                pauseCtx->unk_1E4 = 0;
                pauseCtx->unk_1EC = 0;
                pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
            }
        } else if (pauseCtx->state == 8) {
            HREG(80) = 7;
            HREG(82) = 3;
            R_PAUSE_MENU_MODE = 1;
            pauseCtx->unk_1E4 = 0;
            pauseCtx->unk_1EC = 0;
            pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
        } else if ((pauseCtx->state == 2) || (pauseCtx->state == 9)) {
            osSyncPrintf("PR_KAREIDOSCOPE_MODE=%d\n", R_PAUSE_MENU_MODE);

            if (R_PAUSE_MENU_MODE >= 3) {
                pauseCtx->state++;
            }
        } else if (pauseCtx->state != 0) {
            if (gKaleidoMgrCurOvl != kaleidoScopeOvl) {
                if (gKaleidoMgrCurOvl != NULL) {
                    osSyncPrintf(VT_FGCOL(GREEN));
                    // "Kaleido area Player Forced Elimination"
                    osSyncPrintf("Kaleido area Player Forced Elimination\n");
                    osSyncPrintf(VT_RST);

                    KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
                }

                osSyncPrintf(VT_FGCOL(GREEN));
                // "Kaleido area Kaleidoscope loading"
                osSyncPrintf("Kaleido area Kaleidoscope loading\n");
                osSyncPrintf(VT_RST);

                KaleidoManager_LoadOvl(kaleidoScopeOvl);
            }

            if (gKaleidoMgrCurOvl == kaleidoScopeOvl) {
                sKaleidoScopeUpdateFunc(globalCtx);

                if ((globalCtx->pauseCtx.state == 0) && (globalCtx->pauseCtx.debugState == 0)) {
                    osSyncPrintf(VT_FGCOL(GREEN));
                    // "Kaleido area Kaleidoscope Emission"
                    osSyncPrintf("Kaleido area Kaleidoscope Emission\n");
                    osSyncPrintf(VT_RST);

                    KaleidoManager_ClearOvl(kaleidoScopeOvl);
                    KaleidoScopeCall_LoadPlayer();
                }
            }
        }
    }
}

void KaleidoScopeCall_Draw(GlobalContext* globalCtx) {
    KaleidoMgrOverlay* kaleidoScopeOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_KALEIDO_SCOPE];

    if (R_PAUSE_MENU_MODE >= 3) {
        if (((globalCtx->pauseCtx.state >= 4) && (globalCtx->pauseCtx.state <= 7)) ||
            ((globalCtx->pauseCtx.state >= 11) && (globalCtx->pauseCtx.state <= 18))) {
            if (gKaleidoMgrCurOvl == kaleidoScopeOvl) {
                sKaleidoScopeDrawFunc(globalCtx);
            }
        }
    }
}

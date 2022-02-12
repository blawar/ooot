#define INTERNAL_SRC_CODE_Z_KALEIDO_MANAGER_C
#include "global.h"
#include "segment_symbols.h"
#include "z64global.h"
#include "include/kaleido.h"
#include "vt.h"
#include <string.h>
#include "def/code_800FC620.h"
#include "def/game.h"
#include "def/logutils.h"
#include "def/z_kaleido_manager.h"

#define KALEIDO_OVERLAY(name)                                                                                \
    {                                                                                                        \
        NULL, (uintptr_t)_ovl_##name##SegmentRomStart, (uintptr_t)_ovl_##name##SegmentRomEnd, _ovl_##name##SegmentStart, \
            _ovl_##name##SegmentEnd, 0, #name,                                                               \
    }

KaleidoMgrOverlay gKaleidoMgrOverlayTable[] = {
    KALEIDO_OVERLAY(kaleido_scope),
    KALEIDO_OVERLAY(player_actor),
};

void* sKaleidoAreaPtr = NULL;
KaleidoMgrOverlay* gKaleidoMgrCurOvl = NULL;
u8 gBossMarkState = 0;

void KaleidoManager_LoadOvl(KaleidoMgrOverlay* ovl) {
    ovl->loadedRamAddr = (void*)ovl->vromStart;
    Overlay_Load(ovl->vromStart, ovl->vromEnd, ovl->vramStart, ovl->vramEnd, ovl->loadedRamAddr);

    ovl->offset = 0; // POINTER_SUB(ovl->loadedRamAddr, ovl->vramStart);
    gKaleidoMgrCurOvl = ovl;
}

void KaleidoManager_ClearOvl(KaleidoMgrOverlay* ovl) {
    if (ovl->loadedRamAddr != NULL) {
        ovl->offset = 0;
        ovl->loadedRamAddr = NULL;
        gKaleidoMgrCurOvl = NULL;
    }
}

void KaleidoManager_Init(GlobalContext* globalCtx) {
    s32 largestSize = 0;
    s32 size;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(gKaleidoMgrOverlayTable); i++) {
        size = POINTER_SUB(gKaleidoMgrOverlayTable[i].vramEnd, gKaleidoMgrOverlayTable[i].vramStart);
        if (size > largestSize) {
            largestSize = size;
        }
    }

    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("The maximum size of a KaleidoArea should be %d bytes\n", largestSize);
    osSyncPrintf(VT_RST);

    /*sKaleidoAreaPtr = GameState_Alloc(&globalCtx->state, largestSize, "../z_kaleido_manager.c", 150);
    LogUtils_CheckNullPointer("KaleidoArea_allocp", sKaleidoAreaPtr, "../z_kaleido_manager.c", 151);

    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("KaleidoArea %08x - %08x\n", sKaleidoAreaPtr, (uintptr_t)sKaleidoAreaPtr + largestSize);
    osSyncPrintf(VT_RST);*/

    gKaleidoMgrCurOvl = 0;
}

void KaleidoManager_Destroy() {
    if (gKaleidoMgrCurOvl != NULL) {
        KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
        gKaleidoMgrCurOvl = NULL;
    }

    sKaleidoAreaPtr = NULL;
}

void* KaleidoManager_GetRamAddr(void* vram) {
    return vram;
}

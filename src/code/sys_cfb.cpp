#define INTERNAL_SRC_CODE_SYS_CFB_C
#include "global.h"
#include "def/sys_cfb.h"
#include <stdlib.h>

#define osMemSize 0x800000

uintptr_t sSysCfbFbPtr[2];
uintptr_t sSysCfbEnd;

static void* cfbBuffer = NULL;

void SysCfb_Init(s32 n64dd) {
    uintptr_t screenSize;
    uintptr_t tmpFbEnd;

    cfbBuffer = malloc(osMemSize);
    sSysCfbEnd = POINTER_ADD(cfbBuffer, osMemSize);

    screenSize = SCREEN_WIDTH * SCREEN_HEIGHT;
    sSysCfbEnd &= ~0x3F;
    // "The final address used by the system is %08x"
    osSyncPrintf("The final address used by the system is %08x\n", sSysCfbEnd);
    sSysCfbFbPtr[0] = sSysCfbEnd - (screenSize * 4);
    sSysCfbFbPtr[1] = sSysCfbEnd - (screenSize * 2);
    // "Frame buffer addresses are %08x and %08x"
    osSyncPrintf("Frame buffer addresses are %08x and %08x\n", sSysCfbFbPtr[0], sSysCfbFbPtr[1]);
}

void SysCfb_Reset() {
    sSysCfbFbPtr[0] = 0;
    sSysCfbFbPtr[1] = 0;
    sSysCfbEnd = 0;
}

uintptr_t SysCfb_GetFbPtr(s32 idx) {
    if (idx < 2) {
        return sSysCfbFbPtr[idx];
    }
    return 0;
}

uintptr_t SysCfb_GetFbEnd() {
    return sSysCfbEnd;
}

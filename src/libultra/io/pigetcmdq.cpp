#define INTERNAL_SRC_LIBULTRA_IO_PIGETCMDQ_C
#include "global.h"
#include "ultra64/internal.h"
#include "def/pigetcmdq.h"

OSMesgQueue* osPiGetCmdQueue(void) {
    if (!__osPiDevMgr.initialized) {
        return NULL;
    }

    return __osPiDevMgr.cmdQueue;
}

#define INTERNAL_SRC_LIBULTRA_IO_PIMGR_C
#include "global.h"
#include "ultra64/internal.h"
#include "def/pimgr.h"

OSMgrArgs __osPiDevMgr = { 0 };

OSPiHandle __Dom1SpeedParam;
OSPiHandle __Dom2SpeedParam;
OSThread piThread;
u8 piStackThread[0x1000];
OSMesgQueue piEventQueue;
OSMesg piEventBuf[2];
OSThread __osThreadSave;

OSPiHandle* __osPiTable = NULL;
OSPiHandle* __osCurrentHandle[] = {
    &__Dom1SpeedParam,
    &__Dom2SpeedParam,
};

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
}

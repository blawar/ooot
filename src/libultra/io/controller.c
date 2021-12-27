#define INTERNAL_SRC_LIBULTRA_IO_CONTROLLER_C
#include "global.h"
#include "ultra64/controller.h"
#include "ultra64/time.h"
#include "def/controller.h"

OSPifRam __osPifInternalBuff;
u8 __osContLastPoll;
u8 __osMaxControllers; // always 4

OSTimer __osEepromTimer;
OSMesgQueue __osEepromTimerMsgQ;
OSMesg __osEepromTimerMsg;

u32 gOSContInitialized = 0;

#define HALF_SECOND OS_USEC_TO_CYCLES(500000)

s32 osContInit(OSMesgQueue* mq, u8* ctlBitfield, OSContStatus* status) {
    return 0;
}

void __osContGetInitData(u8* ctlBitfield, OSContStatus* status) {
}

void __osPackRequestData(u8 poll) {
}

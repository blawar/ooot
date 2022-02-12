#define INTERNAL_SRC_LIBULTRA_IO_VIMGR_C
#include "global.h"
#include "ultra64/internal.h"
#include "def/vimgr.h"

OSThread viThread;
u8 viThreadStack[0x1000];
OSMesgQueue viEventQueue;
OSMesg viEventBuf[6];
OSIoMesg viRetraceMsg;
OSIoMesg viCounterMsg;
OSMgrArgs __osViDevMgr = { 0 };
u32 __additional_scanline = 0;

void viMgrMain(void*);

void viMgrMain(void* vargs) {
}

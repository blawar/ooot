#define INTERNAL_SRC_LIBULTRA_IO_VIMGR_C
#include "global.h"
#include "ultra64/internal.h"

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
    /*static u16 viRetrace;
    OSMgrArgs* args;
    u32 addTime;
    OSIoMesg* mesg = NULL;
    u32 temp = 0; // always 0

    viRetrace = __osViGetCurrentContext()->retraceCount;
    if (viRetrace == 0) {
        viRetrace = 1;
    }

    args = (OSMgrArgs*)vargs;

    while (true) {
        osRecvMesg(args->eventQueue, (OSMesg)&mesg, OS_MESG_BLOCK);
        switch (mesg->hdr.type) {
        case OS_MESG_TYPE_VRETRACE:
            __osViSwapContext();
            viRetrace--;
            if (!viRetrace) {
                OSViContext* ctx = __osViGetCurrentContext();
                if (ctx->mq) {
                    osSendMesg(ctx->mq, ctx->msg, OS_MESG_NOBLOCK);
                }
                viRetrace = ctx->retraceCount;
            }

            __osViIntrCount++;

            // block optimized out since temp is always 0,
            // but it changes register allocation and ordering for __osCurrentTime
            if (temp != 0) {
                addTime = osGetCount();
                __osCurrentTime = addTime;
                temp = 0;
            }

            addTime = __osBaseCounter;
            __osBaseCounter = osGetCount();
            addTime = __osBaseCounter - addTime;
            __osCurrentTime = __osCurrentTime + addTime;
            break;
        case OS_MESG_TYPE_COUNTER:
            __osTimerInterrupt();
            break;
        }
    }*/
}
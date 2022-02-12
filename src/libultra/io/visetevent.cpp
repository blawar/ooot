#define INTERNAL_SRC_LIBULTRA_IO_VISETEVENT_C
#include "global.h"
#include "def/vi.h"
#include "def/visetevent.h"

extern OSViContext* __osViNext;

void osViSetEvent(OSMesgQueue* mq, OSMesg msg, u32 retraceCount) {
    register u32 prevInt = __osDisableInt();

    __osViNext->mq = mq;
    __osViNext->msg = msg;
    __osViNext->retraceCount = retraceCount;

    __osRestoreInt(prevInt);
}

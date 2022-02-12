#define INTERNAL_SRC_CODE_IRQMGR_C
#include "global.h"
#include "vt.h"
#include "sched.h"
#include "ultra64/exception.h"
#include <stdbool.h>
#include "def/irqmgr.h"

vu32 gIrqMgrResetStatus = 0;
volatile OSTime sIrqMgrResetTime = 0;
volatile OSTime gIrqMgrRetraceTime = 0;
u32 sIrqMgrRetraceCount = 0;

#define RETRACE_MSG 666
#define PRE_NMI_MSG 669
#define PRENMI450_MSG 671
#define PRENMI480_MSG 672
#define PRENMI500_MSG 673

#define STATUS_IDLE 0
#define STATUS_PRENMI 1
#define STATUS_NMI 2

void IrqMgr_AddClient(IrqMgr* pthis, IrqMgrClient* c, OSMesgQueue* msgQ) {
}

void IrqMgr_RemoveClient(IrqMgr* pthis, IrqMgrClient* c) {
}

void IrqMgr_SendMesgForClient(IrqMgr* pthis, OSMesg msg) {
}

void IrqMgr_JamMesgForClient(IrqMgr* pthis, OSMesg msg) {
}

void IrqMgr_HandlePreNMI(IrqMgr* pthis) {
}

void IrqMgr_CheckStack() {
}

void IrqMgr_HandlePRENMI450(IrqMgr* pthis) {
}

void IrqMgr_HandlePRENMI480(IrqMgr* pthis) {
}

void IrqMgr_HandlePRENMI500(IrqMgr* pthis) {
}

void IrqMgr_HandleRetrace(IrqMgr* pthis) {
}

void IrqMgr_ThreadEntry(void* arg0) {
}

void IrqMgr_Init(IrqMgr* pthis, void* stack, OSPri pri, u8 retraceCount) {
}

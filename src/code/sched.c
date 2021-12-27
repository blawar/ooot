#define INTERNAL_SRC_CODE_SCHED_C
#include "global.h"
#include "ultra64/time.h"

#include "z64game.h"
#include "z_play.h"
#include "sched.h"
#include "regs.h"
#include "speedmeter.h"
#include "ultra64/vi.h"
#include "def/sched.h"

#define RSP_DONE_MSG 667
#define RDP_DONE_MSG 668
#define ENTRY_MSG 670

// data
vs32 sLogScheduler = false;

// bss
OSTime sRSPGFXStartTime;
OSTime sRSPAudioStartTime;
OSTime sRSPOtherStartTime;
OSTime sRDPStartTime;

void Sched_SwapFrameBuffer(CfbInfo* cfbInfo) {
}

void func_800C84E4(SchedContext* sc, CfbInfo* cfbInfo) {
}

void Sched_HandleReset(SchedContext* sc) {
}

void Sched_HandleStart(SchedContext* sc) {
}

void Sched_QueueTask(SchedContext* sc, OSScTask* task) {
}

void Sched_Yield(SchedContext* sc) {
}

OSScTask* func_800C89D4(SchedContext* sc, OSScTask* task) {
    return 0;
}

s32 Sched_Schedule(SchedContext* sc, OSScTask** sp, OSScTask** dp, s32 state) {
    return 0;
}

void func_800C8BC4(SchedContext* sc, OSScTask* task) {
}

u32 Sched_IsComplete(SchedContext* sc, OSScTask* task) {
    return 0;
}

void Sched_RunTask(SchedContext* sc, OSScTask* spTask, OSScTask* dpTask) {
}

void Sched_HandleEntry(SchedContext* sc) {
}

void Sched_HandleRetrace(SchedContext* sc) {
}

void Sched_HandleRSPDone(SchedContext* sc) {
}

void Sched_HandleRDPDone(SchedContext* sc) {
}

void Sched_SendEntryMsg(SchedContext* sc) {
}

void Sched_ThreadEntry(void* arg) {
}

void Sched_Init(SchedContext* sc, void* stack, OSPri priority, UNK_TYPE arg3, UNK_TYPE arg4, IrqMgr* irqMgr) {
}

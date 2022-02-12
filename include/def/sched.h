#pragma once
struct SchedContext;
struct IrqMgr;
struct OSScTask;
struct CfbInfo;

void Sched_HandleEntry(SchedContext* sc);
void Sched_HandleRDPDone(SchedContext* sc);
void Sched_HandleRSPDone(SchedContext* sc);
void Sched_HandleReset(SchedContext* sc);
void Sched_HandleRetrace(SchedContext* sc);
void Sched_HandleStart(SchedContext* sc);
void Sched_Init(SchedContext* sc, void* stack, OSPri priority, UNK_TYPE arg3, UNK_TYPE arg4, IrqMgr* irqMgr);
u32 Sched_IsComplete(SchedContext* sc, OSScTask* task);
void Sched_QueueTask(SchedContext* sc, OSScTask* task);
void Sched_RunTask(SchedContext* sc, OSScTask* spTask, OSScTask* dpTask);
s32 Sched_Schedule(SchedContext* sc, OSScTask** sp, OSScTask** dp, s32 state);
void Sched_SendEntryMsg(SchedContext* sc);
void Sched_SwapFrameBuffer(CfbInfo* cfbInfo);
void Sched_ThreadEntry(void* arg);
void Sched_Yield(SchedContext* sc);
void func_800C84E4(SchedContext* sc, CfbInfo* cfbInfo);
OSScTask* func_800C89D4(SchedContext* sc, OSScTask* task);
void func_800C8BC4(SchedContext* sc, OSScTask* task);

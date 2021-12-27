#pragma once
#ifdef INTERNAL_SRC_CODE_SCHED_C
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
#else
void Sched_HandleEntry(struct SchedContext* sc);
void Sched_HandleRDPDone(struct SchedContext* sc);
void Sched_HandleRSPDone(struct SchedContext* sc);
void Sched_HandleReset(struct SchedContext* sc);
void Sched_HandleRetrace(struct SchedContext* sc);
void Sched_HandleStart(struct SchedContext* sc);
void Sched_Init(struct SchedContext* sc, void* stack, OSPri priority, UNK_TYPE arg3, UNK_TYPE arg4, struct IrqMgr* irqMgr);
u32 Sched_IsComplete(struct SchedContext* sc, struct OSScTask* task);
void Sched_QueueTask(struct SchedContext* sc, struct OSScTask* task);
void Sched_RunTask(struct SchedContext* sc, struct OSScTask* spTask, struct OSScTask* dpTask);
s32 Sched_Schedule(struct SchedContext* sc, struct OSScTask** sp, struct OSScTask** dp, s32 state);
void Sched_SendEntryMsg(struct SchedContext* sc);
void Sched_SwapFrameBuffer(struct CfbInfo* cfbInfo);
void Sched_ThreadEntry(void* arg);
void Sched_Yield(struct SchedContext* sc);
void func_800C84E4(struct SchedContext* sc, struct CfbInfo* cfbInfo);
struct OSScTask* func_800C89D4(struct SchedContext* sc, struct OSScTask* task);
void func_800C8BC4(struct SchedContext* sc, struct OSScTask* task);
#endif

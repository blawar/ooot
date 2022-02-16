#pragma once
struct AudioTask;

void Audio_InitMesgQueues(void);
u32 Audio_NextRandom(void);
void Audio_PreNMIInternal(void);
void Audio_QueueCmdF32(u32 arg0, f32 arg1);
void Audio_QueueCmdS32(u32 arg0, s32 arg1);
void Audio_QueueCmdS8(u32 arg0, s8 arg1);
void Audio_QueueCmdU16(u32 arg0, u16 arg1);
s32 Audio_ScheduleProcessCmds(void);
AudioTask* func_800E4FE0(void);
u32 func_800E5E20(u32* arg0);
u8* func_800E5E84(s32 arg0, u32* arg1);
s32 func_800E5EDC(void);
s32 func_800E5F88(s32 arg0);
s32 func_800E6680(void);
u32 osGetCount(void);

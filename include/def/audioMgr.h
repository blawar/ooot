#pragma once
struct AudioMgr;
struct SchedContext;
struct IrqMgr;

void AudioMgr_HandlePRENMI(AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(AudioMgr* audioMgr);
void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(AudioMgr* audioMgr);
void func_800C3C80(AudioMgr* audioMgr);

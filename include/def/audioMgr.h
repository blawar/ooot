#pragma once
#include "ultra64/thread.h"

struct AudioMgr;
struct SchedContext;
struct IrqMgr;

void AudioMgr_HandlePRENMI(AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(AudioMgr* audioMgr);
void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(AudioMgr* audioMgr);
void AudioMgr_Shutdown();
void AudioMgr_Pause(bool pauseOn);
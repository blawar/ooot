#pragma once
#ifdef INTERNAL_SRC_CODE_AUDIOMGR_C
void AudioMgr_HandlePRENMI(AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(AudioMgr* audioMgr);
void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(AudioMgr* audioMgr);
void func_800C3C80(AudioMgr* audioMgr);
#else
void AudioMgr_HandlePRENMI(struct AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(struct AudioMgr* audioMgr);
void AudioMgr_Init(struct AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, struct SchedContext* sched, struct IrqMgr* irqMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(struct AudioMgr* audioMgr);
void func_800C3C80(struct AudioMgr* audioMgr);
#endif

#define INTERNAL_SRC_CODE_AUDIOMGR_C
#include "global.h"
#include "z64audio.h"
#include "audiomgr.h"
#include "sched.h"
#include "ultra64/message.h"
#include "speedmeter.h"
#include "regs.h"
#include "z64game.h"
#include "def/audioMgr.h"
#include "def/code_800EC960.h"
#include "def/code_800E4FE0.h"
#include "def/audio_playback.h"

static AudioMgr* g_audioMgr = NULL;

void AudioMgr_HandleRetrace(AudioMgr* audioMgr);

void func_800C3C80(AudioMgr* audioMgr) {
    return;
}

void AudioMgr_HandleRetraceNULL() {
    AudioMgr_HandleRetrace(NULL);
}

void AudioMgr_HandleRetrace(AudioMgr* audioMgr) {
    if(!audioMgr)
    {
        audioMgr = g_audioMgr;
    }

    if(!audioMgr)
    {
        return;
    }

    AudioTask* task = func_800E4FE0();

    return;
}

void AudioMgr_HandlePRENMI(AudioMgr* audioMgr) {
}

void AudioMgr_ThreadEntry(void* arg0) {
}

void AudioMgr_Unlock(AudioMgr* audioMgr) {
}

void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr) {
	bzero(audioMgr, sizeof(AudioMgr));
    g_audioMgr = audioMgr;

    IrqMgrClient irqClient;
    s16* msg = NULL;

    Audio_Init();
    //AudioLoad_SetDmaHandler(DmaMgr_DmaHandler);
    Audio_InitSound();
}

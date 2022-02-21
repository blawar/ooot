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
#include "def/audio.h"
#include "def/audio_rsp.h"
#include "def/audio_playback.h"
#include "../../AziAudio/AziAudio/AudioSpec.h"
#include <thread>
#include <memory>
#include "ultra64/rcp.h"
#include "redef_msgqueue.h"

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

void audio_int()
{
	/*
	 *AudioInfo.AI_STATUS_REG = AI_STATUS_DMA_BUSY;
	 *AudioInfo.AI_STATUS_REG &= ~AI_STATUS_FIFO_FULL;
	 *AudioInfo.MI_INTR_REG |= MI_INTR_AI;
	 */
	/*
	uint32_t mi_intr_reg = HW_REG(MI_INTR_REG, u32), status_register;

		mi_intr_reg &= ~MI_INTR_AI;
		mi_intr_reg |= (m_AudioIntrReg & MI_INTR_AI);

	mi_intr_reg |= (m_RspIntrReg & MI_INTR_SP);
	mi_intr_reg |= (m_GfxIntrReg & MI_INTR_DP);
	if((MI_INTR_MASK_REG & mi_intr_reg) != 0)
	{
		FAKE_CAUSE_REGISTER |= CAUSE_IP2;
	}
	else
	{
		FAKE_CAUSE_REGISTER &= ~CAUSE_IP2;
	}
	HW_REG(MI_INTR_REG, u32) = mi_intr_reg;
	status_register = HW_REG(AI_STATUS_REG, u32);

	if((status_register & STATUS_IE) == 0)
	{
		return;
	}
	if((status_register & STATUS_EXL) != 0)
	{
		return;
	}
	if((status_register & STATUS_ERL) != 0)
	{
		return;
	}

	if((status_register & FAKE_CAUSE_REGISTER & 0xFF00) != 0)
	{
		if(m_FirstInterupt)
		{
			m_FirstInterupt = false;
		}
	}*/
	return;
}

static AudioTask* g_currentAudioTask = nullptr;

void bah()
{
}

void audio_thread()
{
	SREG(20);
	s16* msg = NULL;
	auto audioMgr = g_audioMgr;

	const auto interval = std::chrono::microseconds(1000 * 1000 / 60);
	auto targetTime	    = std::chrono::high_resolution_clock::now() + interval;
	while(true)
	{
		if(std::chrono::high_resolution_clock::now() > targetTime)
		{
			auto task = getAudioTask();

			if(task)
			{
				HLEStart((AZI_OSTask*)&task->task.t);
				AiUpdate(false);
			}

            targetTime += interval;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}

std::unique_ptr<std::thread> t1;

static bool g_aziInit = false;

void azi_init()
{
	if(g_aziInit)
	{
		return;
	}
	g_aziInit = true;
	AUDIO_INFO Audio_Info;
	memset(&Audio_Info, 0, sizeof(Audio_Info));

	HW_REG(AI_CONTROL_REG, u32) = 1;
	HW_REG(AI_DACRATE_REG, u32) = 0x3FFF;
	HW_REG(AI_BITRATE_REG, u32) = 0xF;

	Audio_Info.hwnd		    = GetActiveWindow();
	Audio_Info.AI_DRAM_ADDR_REG = &HW_REG(AI_DRAM_ADDR_REG, u32);
	Audio_Info.AI_LEN_REG	    = &HW_REG(AI_LEN_REG, u32);
	Audio_Info.AI_CONTROL_REG   = &HW_REG(AI_CONTROL_REG, u32);
	Audio_Info.AI_STATUS_REG    = &HW_REG(AI_STATUS_REG, u32);
	Audio_Info.AI_DACRATE_REG   = &HW_REG(AI_DACRATE_REG, u32);
	Audio_Info.AI_BITRATE_REG   = &HW_REG(AI_BITRATE_REG, u32);
	Audio_Info.MI_INTR_REG	    = &HW_REG(MI_INTR_REG, u32);
	Audio_Info.CheckInterrupts  = audio_int;

	InitiateAudio(Audio_Info);
}

void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr) {
	bzero(audioMgr, sizeof(AudioMgr));
    g_audioMgr = audioMgr;
	azi_init();

    IrqMgrClient irqClient;
    s16* msg = NULL;

    Audio_Init();
    //AudioLoad_SetDmaHandler(DmaMgr_DmaHandler);
    Audio_InitSound();

    t1 = std::make_unique<std::thread>(audio_thread);
}

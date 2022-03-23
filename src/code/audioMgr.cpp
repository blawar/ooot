#define INTERNAL_SRC_CODE_AUDIOMGR_C
#include "global.h"
#include "z64audio.h"
#include "audiomgr.h"
#include "ultra64/sched.h"
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
#include <string.h>
#include "ultra64/rcp.h"
#include "redef_msgqueue.h"

static AudioMgr* g_audioMgr = NULL;

void AudioMgr_HandleRetrace(AudioMgr* audioMgr);

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

void audio_int()
{
	/*
	 *AudioInfo.AI_STATUS_REG = AI_STATUS_DMA_BUSY;
	 *AudioInfo.AI_STATUS_REG &= ~AI_STATUS_FIFO_FULL;
	 *AudioInfo.MI_INTR_REG |= MI_INTR_AI;
	 */
	/*
	uint32_t mi_intr_reg = hw_regs.MI_INTR_REG, status_register;

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
	hw_regs.MI_INTR_REG = mi_intr_reg;
	status_register = hw_regs.AI_STATUS_REG;

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
static bool g_aziInit = false;

void audio_thread()
{
	SREG(20);
	s16* msg = NULL;
	auto audioMgr = g_audioMgr;

	const auto interval = std::chrono::microseconds(1000 * 1000 / 60);
	auto targetTime	    = std::chrono::high_resolution_clock::now() + interval;
	while(g_aziInit)
	{
		if(std::chrono::high_resolution_clock::now() > targetTime)
		{
			auto task = getAudioTask();

			if(task)
			{
				//HLEStart((AZI_OSTask*)&task->task.t);
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

std::thread t1;

void azi_init()
{
	if(g_aziInit)
	{
		return;
	}
	g_aziInit = true;
	AUDIO_INFO Audio_Info;
	memset(&Audio_Info, 0, sizeof(Audio_Info));

	hw_regs.AI_CONTROL_REG = 1;
	hw_regs.AI_DACRATE_REG = 0x3FFF;
	hw_regs.AI_BITRATE_REG = 0xF;

#ifdef _MSC_VER
	Audio_Info.hwnd		    = GetActiveWindow();
#else
	Audio_Info.hwnd = NULL;
#endif
	Audio_Info.AI_DRAM_ADDR_REG = &hw_regs.AI_DRAM_ADDR_REG;
	Audio_Info.AI_LEN_REG	    = &hw_regs.AI_LEN_REG;
	Audio_Info.AI_CONTROL_REG   = &hw_regs.AI_CONTROL_REG;
	Audio_Info.AI_STATUS_REG    = (u32*)&hw_regs.AI_STATUS_REG;
	Audio_Info.AI_DACRATE_REG   = &hw_regs.AI_DACRATE_REG;
	Audio_Info.AI_BITRATE_REG   = &hw_regs.AI_BITRATE_REG;
	Audio_Info.MI_INTR_REG	    = &hw_regs.MI_INTR_REG;
	Audio_Info.CheckInterrupts  = audio_int;

	InitiateAudio(Audio_Info);
}

void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr) {
	memset(audioMgr, 0, sizeof(AudioMgr));
    g_audioMgr = audioMgr;
	azi_init();

    IrqMgrClient irqClient;
    s16* msg = NULL;

    Audio_Init();
    //AudioLoad_SetDmaHandler(DmaMgr_DmaHandler);
    Audio_InitSound();

    t1 = std::thread(audio_thread);
}

void AudioMgr_Shutdown()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Wait until the audio buffer finishes playing

	CloseDLL();//Shut down Azi

	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Keep the audio thread open a bit longer

	g_aziInit = false;//Thread closes now

	if (t1.joinable())
		t1.join();
}

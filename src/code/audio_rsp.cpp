#define INTERNAL_SRC_CODE_CODE_800E4FE0_C
#include "global.h"
#include "rsp.h"
#include <string.h>
#include "z64audio.h"
#include "ultra64/abi.h"
#include "ultra64/mbi.h"
#include "def/aigetlen.h"
#include "def/aisetnextbuf.h"
#include "def/audio_data.h"
#include "def/audio_heap.h"
#include "def/audio_load.h"
#include "def/audio_playback.h"
#include "def/audio_seqplayer.h"
#include "def/audio_synthesis.h"
#include "def/audio_rsp.h"
#include "def/audio_bank.h"
#include "def/createmesgqueue.h"
#include "def/recvmesg.h"

#include "redef_msgqueue.h"

static const int16_t RESAMPLE_LUT[64 * 4] = {
    (int16_t)0x0c39, (int16_t)0x66ad, (int16_t)0x0d46, (int16_t)0xffdf, (int16_t)0x0b39, (int16_t)0x6696, (int16_t)0x0e5f, (int16_t)0xffd8, (int16_t)0x0a44, (int16_t)0x6669, (int16_t)0x0f83, (int16_t)0xffd0, (int16_t)0x095a, (int16_t)0x6626,
    (int16_t)0x10b4, (int16_t)0xffc8, (int16_t)0x087d, (int16_t)0x65cd, (int16_t)0x11f0, (int16_t)0xffbf, (int16_t)0x07ab, (int16_t)0x655e, (int16_t)0x1338, (int16_t)0xffb6, (int16_t)0x06e4, (int16_t)0x64d9, (int16_t)0x148c, (int16_t)0xffac,
    (int16_t)0x0628, (int16_t)0x643f, (int16_t)0x15eb, (int16_t)0xffa1, (int16_t)0x0577, (int16_t)0x638f, (int16_t)0x1756, (int16_t)0xff96, (int16_t)0x04d1, (int16_t)0x62cb, (int16_t)0x18cb, (int16_t)0xff8a, (int16_t)0x0435, (int16_t)0x61f3,
    (int16_t)0x1a4c, (int16_t)0xff7e, (int16_t)0x03a4, (int16_t)0x6106, (int16_t)0x1bd7, (int16_t)0xff71, (int16_t)0x031c, (int16_t)0x6007, (int16_t)0x1d6c, (int16_t)0xff64, (int16_t)0x029f, (int16_t)0x5ef5, (int16_t)0x1f0b, (int16_t)0xff56,
    (int16_t)0x022a, (int16_t)0x5dd0, (int16_t)0x20b3, (int16_t)0xff48, (int16_t)0x01be, (int16_t)0x5c9a, (int16_t)0x2264, (int16_t)0xff3a, (int16_t)0x015b, (int16_t)0x5b53, (int16_t)0x241e, (int16_t)0xff2c, (int16_t)0x0101, (int16_t)0x59fc,
    (int16_t)0x25e0, (int16_t)0xff1e, (int16_t)0x00ae, (int16_t)0x5896, (int16_t)0x27a9, (int16_t)0xff10, (int16_t)0x0063, (int16_t)0x5720, (int16_t)0x297a, (int16_t)0xff02, (int16_t)0x001f, (int16_t)0x559d, (int16_t)0x2b50, (int16_t)0xfef4,
    (int16_t)0xffe2, (int16_t)0x540d, (int16_t)0x2d2c, (int16_t)0xfee8, (int16_t)0xffac, (int16_t)0x5270, (int16_t)0x2f0d, (int16_t)0xfedb, (int16_t)0xff7c, (int16_t)0x50c7, (int16_t)0x30f3, (int16_t)0xfed0, (int16_t)0xff53, (int16_t)0x4f14,
    (int16_t)0x32dc, (int16_t)0xfec6, (int16_t)0xff2e, (int16_t)0x4d57, (int16_t)0x34c8, (int16_t)0xfebd, (int16_t)0xff0f, (int16_t)0x4b91, (int16_t)0x36b6, (int16_t)0xfeb6, (int16_t)0xfef5, (int16_t)0x49c2, (int16_t)0x38a5, (int16_t)0xfeb0,
    (int16_t)0xfedf, (int16_t)0x47ed, (int16_t)0x3a95, (int16_t)0xfeac, (int16_t)0xfece, (int16_t)0x4611, (int16_t)0x3c85, (int16_t)0xfeab, (int16_t)0xfec0, (int16_t)0x4430, (int16_t)0x3e74, (int16_t)0xfeac, (int16_t)0xfeb6, (int16_t)0x424a,
    (int16_t)0x4060, (int16_t)0xfeaf, (int16_t)0xfeaf, (int16_t)0x4060, (int16_t)0x424a, (int16_t)0xfeb6, (int16_t)0xfeac, (int16_t)0x3e74, (int16_t)0x4430, (int16_t)0xfec0, (int16_t)0xfeab, (int16_t)0x3c85, (int16_t)0x4611, (int16_t)0xfece,
    (int16_t)0xfeac, (int16_t)0x3a95, (int16_t)0x47ed, (int16_t)0xfedf, (int16_t)0xfeb0, (int16_t)0x38a5, (int16_t)0x49c2, (int16_t)0xfef5, (int16_t)0xfeb6, (int16_t)0x36b6, (int16_t)0x4b91, (int16_t)0xff0f, (int16_t)0xfebd, (int16_t)0x34c8,
    (int16_t)0x4d57, (int16_t)0xff2e, (int16_t)0xfec6, (int16_t)0x32dc, (int16_t)0x4f14, (int16_t)0xff53, (int16_t)0xfed0, (int16_t)0x30f3, (int16_t)0x50c7, (int16_t)0xff7c, (int16_t)0xfedb, (int16_t)0x2f0d, (int16_t)0x5270, (int16_t)0xffac,
    (int16_t)0xfee8, (int16_t)0x2d2c, (int16_t)0x540d, (int16_t)0xffe2, (int16_t)0xfef4, (int16_t)0x2b50, (int16_t)0x559d, (int16_t)0x001f, (int16_t)0xff02, (int16_t)0x297a, (int16_t)0x5720, (int16_t)0x0063, (int16_t)0xff10, (int16_t)0x27a9,
    (int16_t)0x5896, (int16_t)0x00ae, (int16_t)0xff1e, (int16_t)0x25e0, (int16_t)0x59fc, (int16_t)0x0101, (int16_t)0xff2c, (int16_t)0x241e, (int16_t)0x5b53, (int16_t)0x015b, (int16_t)0xff3a, (int16_t)0x2264, (int16_t)0x5c9a, (int16_t)0x01be,
    (int16_t)0xff48, (int16_t)0x20b3, (int16_t)0x5dd0, (int16_t)0x022a, (int16_t)0xff56, (int16_t)0x1f0b, (int16_t)0x5ef5, (int16_t)0x029f, (int16_t)0xff64, (int16_t)0x1d6c, (int16_t)0x6007, (int16_t)0x031c, (int16_t)0xff71, (int16_t)0x1bd7,
    (int16_t)0x6106, (int16_t)0x03a4, (int16_t)0xff7e, (int16_t)0x1a4c, (int16_t)0x61f3, (int16_t)0x0435, (int16_t)0xff8a, (int16_t)0x18cb, (int16_t)0x62cb, (int16_t)0x04d1, (int16_t)0xff96, (int16_t)0x1756, (int16_t)0x638f, (int16_t)0x0577,
    (int16_t)0xffa1, (int16_t)0x15eb, (int16_t)0x643f, (int16_t)0x0628, (int16_t)0xffac, (int16_t)0x148c, (int16_t)0x64d9, (int16_t)0x06e4, (int16_t)0xffb6, (int16_t)0x1338, (int16_t)0x655e, (int16_t)0x07ab, (int16_t)0xffbf, (int16_t)0x11f0,
    (int16_t)0x65cd, (int16_t)0x087d, (int16_t)0xffc8, (int16_t)0x10b4, (int16_t)0x6626, (int16_t)0x095a, (int16_t)0xffd0, (int16_t)0x0f83, (int16_t)0x6669, (int16_t)0x0a44, (int16_t)0xffd8, (int16_t)0x0e5f, (int16_t)0x6696, (int16_t)0x0b39,
    (int16_t)0xffdf, (int16_t)0x0d46, (int16_t)0x66ad, (int16_t)0x0c39};

u32 osGetCount(void);

#define SAMPLES_TO_OVERPRODUCE 0x10
#define EXTRA_BUFFERED_AI_SAMPLES_TARGET 0x80

typedef enum {
    CHAN_UPD_UNK_0,           // 0
    CHAN_UPD_VOL_SCALE,       // 1
    CHAN_UPD_VOL,             // 2
    CHAN_UPD_PAN_SIGNED,      // 3
    CHAN_UPD_FREQ_SCALE,      // 4
    CHAN_UPD_REVERB,          // 5
    CHAN_UPD_SCRIPT_IO,       // 6
    CHAN_UPD_PAN_UNSIGNED,    // 7
    CHAN_UPD_STOP_SOMETHING2, // 8
    CHAN_UPD_MUTE_BEHAVE,     // 9
    CHAN_UPD_VIBE_X8,         // 10
    CHAN_UPD_VIBE_X32,        // 11
    CHAN_UPD_UNK_0F,          // 12
    CHAN_UPD_UNK_20,          // 13
    CHAN_UPD_STEREO           // 14
} ChannelUpdateType;

void func_800E6300(SequenceChannel* channel, AudioCmd* arg1);
void func_800E59AC(s32 playerIdx, s32 fadeTimer);
void Audio_InitMesgQueues(void);
AudioTask* func_800E5000(void);
void Audio_ProcessCmds(u32);
void func_800E6128(SequencePlayer* seqPlayer, AudioCmd* arg1);
void func_800E5958(s32 playerIdx, s32 fadeTimer);
s32 func_800E66C0(s32 arg0);

// AudioMgr_Retrace
AudioTask* func_800E4FE0(void) {
    return func_800E5000();
}

extern u64 rspAspMainDataStart[0x5C];

static inline int16_t clamp_s16(int32_t v)
{
	return v < -32768 ? -32768 : v > 32767 ? 32767 : v;
}

static inline int16_t sample_mix(int16_t dst, int16_t src, int16_t gain)
{
	int32_t src_modified = (src * gain) >> 15;
	return clamp_s16(dst + src_modified);
}

static const u32 MAX_MEMORY_SIZE = 0xFFFF;
static u8 m_memory[MAX_MEMORY_SIZE];

class AudioRsp
{
	typedef void (AudioRsp::*AbiHandler)(const Acmd& cmds);
	public:

	constexpr AudioRsp()
	{
	}

	void execute(Acmd* cmds, size_t len)
	{
		for(size_t i = 0; i < len; i++)
		{
			const auto& cmd = cmds[i];
			u8 op		= _SHIFTR(cmd.words.w0, 24, 8);

			if(op >= sizeof(m_abiHandlers))
			{
				break;
			}

			(*this.*m_abiHandlers[op])(cmd);
		}
	}

	protected:
	void cmd_SPNOOP(const Acmd& cmd)
	{
	}

	void cmd_ADPCM(const Acmd& cmd)
	{
		return;
	}

	void cmd_CLEARBUFF(const Acmd& cmd)
	{
		DMem addr = _SHIFTR(cmd.words.w0, 0, 16);
		u16 count = _SHIFTR(cmd.words.w1, 0, 16);

        memset(addr, 0, count);
		return;
	}

	void cmd_UNK3(const Acmd& cmd)
	{
	}

	void cmd_ADDMIXER(const Acmd& cmd)
	{
	}

	void cmd_RESAMPLE(const Acmd& cmd)
	{
		u8 flags		   = _SHIFTR(cmd.words.w0, 16, 8);
		uintptr_t s		   = cmd.words.w1;
		u16 p			   = _SHIFTR(cmd.words.w0, 0, 16);
		/*_a->words.w0		   = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16));
		_a->words.w1		   = (uintptr_t)(s);

		int16_t* dst		   = (int16_t*)(alist_buffer + alist_audio.out);
		int16_t* src		   = (int16_t*)(alist_buffer + alist_audio.in);
		size_t count		   = alist_audio.count >> 1;
		uint32_t pitch_accumulator = 0;

		count = align(count, 8);

		src -= 4;

		if(flags & A_INIT)
		{
			memset(src, 0, 4 * sizeof(int16_t));
		}
		else
		{
			memcpy(src, state_addr, 4 * sizeof(int16_t));
			pitch_accumulator = state_addr[4];
		}

		while(count != 0)
		{
			const int16_t* lut = RESAMPLE_LUT + ((pitch_accumulator & 0xfc00) >> 8);

			*dst++ = clamp_s16((src[0] * lut[0] + src[1] * lut[1] + src[2] * lut[2] + src[3] * lut[3]) >> 15);
			pitch_accumulator += (pitch << 1);
			src += pitch_accumulator >> 16;
			pitch_accumulator &= 0xffff;
			--count;
		}

		memcpy(state_addr, src, 4 * sizeof(int16_t));
		state_addr[4] = pitch_accumulator;*/
		return;
	}

	void cmd_RESAMPLE_ZOH(const Acmd& cmd)
	{
	}

	void cmd_FILTER(const Acmd& cmd)
	{
	}

	void cmd_SETBUFF(const Acmd& cmd)
	{
		return;
	}

	void cmd_DUPLICATE(const Acmd& cmd)
	{
		return;
	}

	void cmd_DMEMMOVE(const Acmd& cmd)
	{
		return;
	}

	void cmd_LOADADPCM(const Acmd& cmd)
	{
		return;
	}

	void cmd_MIXER(const Acmd& cmd)
	{
		u16 count = _SHIFTR(cmd.words.w0, 16, 8);
		s16 gain = _SHIFTR(cmd.words.w0, 0, 16);
		DMem _src  = _SHIFTR(cmd.words.w1, 16, 16);
		DMem _dest = _SHIFTR(cmd.words.w1, 0, 16);


		int16_t* dst	   = (int16_t*)_dest.buffer();
		const int16_t* src = (const int16_t*)_src.buffer();

		while(count != 0)
		{
			*dst = sample_mix(*dst, *src, gain);
			++dst;
			++src;
			--count;
		}
		return;
	}

	void cmd_INTERLEAVE(const Acmd& cmd)
	{
		u16 count = _SHIFTR(cmd.words.w0, 16, 8) << 4;
		DMem dest  = _SHIFTR(cmd.words.w0, 0, 16);
		DMem L  = _SHIFTR(cmd.words.w1, 16, 16);
		DMem R	  = _SHIFTR(cmd.words.w1, 0, 16);

        int16_t* dst  = (int16_t*)dest.buffer();
		int16_t* srcL = (int16_t*)L.buffer();
		int16_t* srcR = (int16_t*)R.buffer();

		// Unroll a bit
		while(count != 0)
		{
			int16_t l1 = *srcL++;
			int16_t l2 = *srcL++;
			int16_t r1 = *srcR++;
			int16_t r2 = *srcR++;

			*dst++ = l1;
			*dst++ = r1;
			*dst++ = l2;
			*dst++ = r2;

			--count;
		}

		return;
	}

	void cmd_HILOGAIN(const Acmd& cmd)
	{
	}

	void cmd_SETLOOP(const Acmd& cmd)
	{
	}

	void cmd_UNK16(const Acmd& cmd)
	{
	}

	void cmd_INTERL(const Acmd& cmd)
	{
	}

	void cmd_ENVSETUP1(const Acmd& cmd)
	{
	}

	void cmd_ENVMIXER(const Acmd& cmd)
	{
	}

	void cmd_LOADBUFF(const Acmd& cmd)
	{
		auto addr = (void*)cmd.words.w1;
		size_t len       = _SHIFTR(cmd.words.w0, 16, 8) << 4;
		DMem arg2   = _SHIFTR(cmd.words.w0, 0, 16);
		memcpy(addr, arg2, len);

		return;
	}

	void cmd_SAVEBUFF(const Acmd& cmd)
	{
		size_t len = _SHIFTR(cmd.words.w0, 16, 8) << 4;
		auto addr = (void*)cmd.words.w1;
		DMem arg2       = _SHIFTR(cmd.words.w0, 0, 16);
		memcpy(arg2, addr, len);
		return;
	}

	void cmd_ENVSETUP2(const Acmd& cmd)
	{
	}

	void cmd_UNK17(const Acmd& cmd)
	{
	}

    AbiHandler m_abiHandlers[24] = {&AudioRsp::cmd_SPNOOP,   &AudioRsp::cmd_ADPCM,     &AudioRsp::cmd_CLEARBUFF, &AudioRsp::cmd_UNK3,	  &AudioRsp::cmd_ADDMIXER,  &AudioRsp::cmd_RESAMPLE,
				       &AudioRsp::cmd_RESAMPLE_ZOH, &AudioRsp::cmd_FILTER,   &AudioRsp::cmd_SETBUFF,   &AudioRsp::cmd_DUPLICATE, &AudioRsp::cmd_DMEMMOVE, &AudioRsp::cmd_LOADADPCM, &AudioRsp::cmd_MIXER,
				       &AudioRsp::cmd_INTERLEAVE,   &AudioRsp::cmd_HILOGAIN, &AudioRsp::cmd_SETLOOP,   &AudioRsp::cmd_UNK16,	 &AudioRsp::cmd_INTERL,	  &AudioRsp::cmd_ENVSETUP1, &AudioRsp::cmd_ENVMIXER,
				       &AudioRsp::cmd_LOADBUFF,	    &AudioRsp::cmd_SAVEBUFF, &AudioRsp::cmd_ENVSETUP2, &AudioRsp::cmd_UNK17};

 
    class DMem
    {
	    public:
	    DMem(u16 addr)
	    {
		    m_address = (uintptr_t)m_memory + addr;
	    }

        void* buffer()
	    {
		return (void*)m_address;
	    }

        operator uintptr_t()
	    {
		return m_address;
	    }

        operator u8*()
	    {
		    return (u8*)m_address;
	    }

        /*operator int16_t*()
	    {
		    return (int16_t*)m_address;
	    }*/

	    protected:
	    uintptr_t m_address;
    };
};

static AudioRsp rsp;

AudioTask* func_800E5000(void) {
    static s32 sMaxAbiCmdCnt = 0x80;
    static AudioTask* sWaitingAudioTask = NULL;
    u32 samplesRemainingInAi;
    s32 abiCmdCnt;
    s32 pad;
    s32 j;
    s32 sp5C;
    s16* currAiBuffer;
    OSTask_t* task;
    s32 index;
    u32 sp4C = 0;
    s32 sp48;
    s32 i;

    gAudioContext.totalTaskCnt++;
    if (gAudioContext.totalTaskCnt % (gAudioContext.audioBufferParameters.specUnk4) != 0) {
        if (D_801755D0 != NULL) {
            D_801755D0();
        }

        if ((gAudioContext.totalTaskCnt % gAudioContext.audioBufferParameters.specUnk4) + 1 ==
            gAudioContext.audioBufferParameters.specUnk4) {
            return sWaitingAudioTask;
        } else {
            return NULL;
        }
    }

    osSendMesg(gAudioContext.taskStartQueueP, (OSMesg)gAudioContext.totalTaskCnt, OS_MESG_NOBLOCK);
    gAudioContext.rspTaskIdx ^= 1;
    gAudioContext.curAIBufIdx++;
    gAudioContext.curAIBufIdx %= 3;
    index = (gAudioContext.curAIBufIdx - 2 + 3) % 3;
    samplesRemainingInAi = osAiGetLength() / 4;

    if (gAudioContext.resetTimer < 16) {
        if (gAudioContext.aiBufLengths[index] != 0) {
            osAiSetNextBuffer(gAudioContext.aiBuffers[index], gAudioContext.aiBufLengths[index] * 4);
            if (gAudioContext.aiBuffers[index]) {}
            if (gAudioContext.aiBufLengths[index]) {}
        }
    }

    if (D_801755D0 != NULL) {
        D_801755D0();
    }

    sp5C = gAudioContext.curAudioFrameDmaCount;
    for (i = 0; i < gAudioContext.curAudioFrameDmaCount; i++) {
        if (osRecvMesg(&gAudioContext.currAudioFrameDmaQueue, NULL, OS_MESG_NOBLOCK) == 0) {
            sp5C--;
        }
    }

    if (sp5C != 0) {
        for (i = 0; i < sp5C; i++) {
            osRecvMesg(&gAudioContext.currAudioFrameDmaQueue, NULL, OS_MESG_BLOCK);
        }
    }

    sp48 = gAudioContext.currAudioFrameDmaQueue.validCount;
    if (sp48 != 0) {
        for (i = 0; i < sp48; i++) {
            osRecvMesg(&gAudioContext.currAudioFrameDmaQueue, NULL, OS_MESG_NOBLOCK);
        }
    }

    gAudioContext.curAudioFrameDmaCount = 0;
    AudioLoad_DecreaseSampleDmaTtls();
    AudioLoad_ProcessLoads(gAudioContext.resetStatus);
    AudioLoad_ProcessScriptLoads();

    if (gAudioContext.resetStatus != 0) {
        if (AudioHeap_ResetStep() == 0) {
            if (gAudioContext.resetStatus == 0) {
                osSendMesg(gAudioContext.audioResetQueueP, (OSMesg)gAudioContext.audioResetSpecIdToLoad, OS_MESG_NOBLOCK);
            }

            sWaitingAudioTask = NULL;
            return NULL;
        }
    }

    if (gAudioContext.resetTimer > 16) {
        return NULL;
    }
    if (gAudioContext.resetTimer != 0) {
        gAudioContext.resetTimer++;
    }

    gAudioContext.currTask = &gAudioContext.rspTask[gAudioContext.rspTaskIdx];
    gAudioContext.curAbiCmdBuf = gAudioContext.abiCmdBufs[gAudioContext.rspTaskIdx];

    index = gAudioContext.curAIBufIdx;
    currAiBuffer = gAudioContext.aiBuffers[index];

    gAudioContext.aiBufLengths[index] =
        (s16)((((gAudioContext.audioBufferParameters.samplesPerFrameTarget - samplesRemainingInAi) +
                EXTRA_BUFFERED_AI_SAMPLES_TARGET) &
               ~0xF) +
              SAMPLES_TO_OVERPRODUCE);
    if (gAudioContext.aiBufLengths[index] < gAudioContext.audioBufferParameters.minAiBufferLength) {
        gAudioContext.aiBufLengths[index] = gAudioContext.audioBufferParameters.minAiBufferLength;
    }

    if (gAudioContext.aiBufLengths[index] > gAudioContext.audioBufferParameters.maxAiBufferLength) {
        gAudioContext.aiBufLengths[index] = gAudioContext.audioBufferParameters.maxAiBufferLength;
    }

    j = 0;
    if (gAudioContext.resetStatus == 0) {
        // msg = 0000RREE R = read pos, E = End Pos
        while (osRecvMesg(gAudioContext.cmdProcQueueP, (OSMesg*)&sp4C, OS_MESG_NOBLOCK) != -1) {
            Audio_ProcessCmds(sp4C);
            j++;
        }
        if ((j == 0) && (gAudioContext.cmdQueueFinished)) {
            Audio_ScheduleProcessCmds();
        }
    }

    gAudioContext.curAbiCmdBuf =
        AudioSynth_Update(gAudioContext.curAbiCmdBuf, &abiCmdCnt, currAiBuffer, gAudioContext.aiBufLengths[index]);
    gAudioContext.audioRandom = (gAudioContext.audioRandom + gAudioContext.totalTaskCnt) * osGetCount();
    gAudioContext.audioRandom =
        gAudioContext.aiBuffers[index][gAudioContext.totalTaskCnt & 0xFF] + gAudioContext.audioRandom;
    gWaveSamples[8] = (s16*)(((u8*)func_800E4FE0) + (gAudioContext.audioRandom & 0xFFF0));

    index = gAudioContext.rspTaskIdx;
    gAudioContext.currTask->taskQueue = NULL;
    gAudioContext.currTask->unk_44 = NULL;

    task = &gAudioContext.currTask->task.t;
    task->type = M_AUDTASK;
    task->flags = 0;
    task->ucode_boot = D_801120C0;
    task->ucode_boot_size = 0x1000;
    task->ucode_data_size = (sizeof(rspAspMainDataStart) * sizeof(u64)) - 1;
    task->ucode = D_801120C0;
    task->ucode_data = rspAspMainDataStart;
    task->ucode_size = 0x1000;
    task->dram_stack = NULL;
    task->dram_stack_size = 0;
    task->output_buff = NULL;
    task->output_buff_size = NULL;

    task->data_ptr = (u64*)gAudioContext.abiCmdBufs[index];
    task->data_size = abiCmdCnt * sizeof(Acmd);
    task->yield_data_ptr = NULL;
    task->yield_data_size = 0;

    rsp.execute(gAudioContext.abiCmdBufs[index], abiCmdCnt);

    if (sMaxAbiCmdCnt < abiCmdCnt) {
        sMaxAbiCmdCnt = abiCmdCnt;
    }

    if (gAudioContext.audioBufferParameters.specUnk4 == 1) {
        return gAudioContext.currTask;
    } else {
        sWaitingAudioTask = gAudioContext.currTask;
        return NULL;
    }
}

#define ACMD_SND_MDE ((u32)0xF0000000)
#define ACMD_MUTE ((u32)0xF1000000)

void func_800E5584(AudioCmd* cmd) {
    s32 i;
    s32 pad;
    s32 pad2;
    u32 temp_a1_5;
    u32 temp_t7;

    switch (cmd->op) {
        case 0x81:
            AudioLoad_SyncLoadSeqParts(cmd->arg1, cmd->arg2);
            return;
        case 0x82:
            AudioLoad_SyncInitSeqPlayer(cmd->arg0, cmd->arg1, cmd->arg2);
            func_800E59AC(cmd->arg0, (s32)cmd->data);
            return;
        case 0x85:
		AudioLoad_SyncInitSeqPlayerSkipTicks(cmd->arg0, cmd->arg1, (s32)cmd->data);
            return;
        case 0x83:
            if (gAudioContext.seqPlayers[cmd->arg0].enabled) {
                if (cmd->asInt == 0) {
                    AudioSeq_SequencePlayerDisableAsFinished(&gAudioContext.seqPlayers[cmd->arg0]);
                } else {
                    func_800E5958(cmd->arg0, cmd->asInt);
                }
            }
            return;
        case 0xF0:
            gAudioContext.soundMode = cmd->asUInt;
            return;
        case 0xF1:
            for (i = 0; i < gAudioContext.audioBufferParameters.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[i];
                seqPlayer->muted = 1;
                seqPlayer->recalculateVolume = 1;
            }
            return;
        case 0xF2:
            if (cmd->asUInt == 1) {
                for (i = 0; i < gAudioContext.numNotes; i++) {
                    Note* note = &gAudioContext.notes[i];
                    NoteSubEu* subEu = &note->noteSubEu;
                    if (subEu->bitField0.enabled && note->playbackState.unk_04 == 0) {
                        if (note->playbackState.parentLayer->channel->muteBehavior & 8) {
                            subEu->bitField0.finished = 1;
                        }
                    }
                }
            }

            for (i = 0; i < gAudioContext.audioBufferParameters.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[i];
                seqPlayer->muted = 0;
                seqPlayer->recalculateVolume = 1;
            }

            return;
        case 0xF3:
            AudioLoad_SyncLoadInstrument(cmd->arg0, cmd->arg1, cmd->arg2);
            return;
        case 0xF4:
            AudioLoad_AsyncLoadSampleBank(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioContext.externalLoadQueue);
            return;
        case 0xF5:
            AudioLoad_AsyncLoadFont(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioContext.externalLoadQueue);
            return;
        case 0xFC:
            AudioLoad_AsyncLoadSeq(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioContext.externalLoadQueue);
            return;
        case 0xF6:
            AudioLoad_DiscardSeqFonts(cmd->arg1);
            return;
        case 0x90:
            gAudioContext.unk_5BDC[cmd->arg0] = cmd->asUShort;
            return;
        case 0xF9:
            gAudioContext.resetStatus = 5;
            gAudioContext.audioResetSpecIdToLoad = cmd->asUInt;
            return;
        case 0xFB:
            D_801755D0 = (void (*)(void))cmd->asUInt;
            return;
        case 0xE0:
        case 0xE1:
        case 0xE2:
            Audio_SetFontInstrument(cmd->op - 0xE0, cmd->arg0, cmd->arg1, cmd->data);
            return;
        case 0xFE:
            temp_t7 = cmd->asUInt;
            if (temp_t7 == 1) {
                for (i = 0; i < gAudioContext.audioBufferParameters.numSequencePlayers; i++) {
                    SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[i];
                    if (seqPlayer->enabled) {
                        AudioSeq_SequencePlayerDisableAsFinished(seqPlayer);
                    }
                }
            }
            func_800E66C0(temp_t7);
            return;
        case 0xE3:
            AudioHeap_PopCache(cmd->asInt);
            return;
        default:
            return;
    }
}

// SetFadeOutTimer
void func_800E5958(s32 playerIdx, s32 fadeTimer) {
    SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[playerIdx];

    if (fadeTimer == 0) {
        fadeTimer = 1;
    }

    seqPlayer->fadeVelocity = -(seqPlayer->fadeVolume / fadeTimer);
    seqPlayer->state = 2;
    seqPlayer->fadeTimer = fadeTimer;
}

// SetFadeInTimer
void func_800E59AC(s32 playerIdx, s32 fadeTimer) {
    SequencePlayer* seqPlayer;
    if (fadeTimer != 0) {
        seqPlayer = &gAudioContext.seqPlayers[playerIdx];
        seqPlayer->state = 1;
        seqPlayer->fadeTimerUnkEu = fadeTimer;
        seqPlayer->fadeTimer = fadeTimer;
        seqPlayer->fadeVolume = 0.0f;
        seqPlayer->fadeVelocity = 0.0f;
    }
}

void Audio_InitMesgQueuesInternal(void) {
    gAudioContext.cmdWrPos = 0;
    gAudioContext.cmdRdPos = 0;
    gAudioContext.cmdQueueFinished = 0;
    gAudioContext.taskStartQueueP = &gAudioContext.taskStartQueue;
    gAudioContext.cmdProcQueueP = &gAudioContext.cmdProcQueue;
    gAudioContext.audioResetQueueP = &gAudioContext.audioResetQueue;
    osCreateMesgQueue(gAudioContext.taskStartQueueP, gAudioContext.taskStartMsgs,
                      ARRAY_COUNT(gAudioContext.taskStartMsgs));
    osCreateMesgQueue(gAudioContext.cmdProcQueueP, gAudioContext.cmdProcMsgs, ARRAY_COUNT(gAudioContext.cmdProcMsgs));
    osCreateMesgQueue(gAudioContext.audioResetQueueP, gAudioContext.audioResetMesgs,
                      ARRAY_COUNT(gAudioContext.audioResetMesgs));
}

void Audio_QueueCmd(u32 opArgs, void** data) {
    AudioCmd* cmd = &gAudioContext.cmdBuf[gAudioContext.cmdWrPos & 0xFF];

    cmd->opArgs = opArgs; // BE32(opArgs);
    cmd->data = *data; // BE32((u32)*data); // TODO FIX broke in 64 bit

    gAudioContext.cmdWrPos++;

    if (gAudioContext.cmdWrPos == gAudioContext.cmdRdPos) {
        gAudioContext.cmdWrPos--;
    }
}

void Audio_QueueCmdF32(u32 opArgs, f32 data) {
    Audio_QueueCmd(opArgs, (void**)&data);
}

void Audio_QueueCmdS32(u32 opArgs, s32 data) {
    Audio_QueueCmd(opArgs, (void**)&data);
}

void Audio_QueueCmdS8(u32 opArgs, s8 data) {
    u32 uData = data << 0x18;

    Audio_QueueCmd(opArgs, (void**)&uData);
}

void Audio_QueueCmdU16(u32 opArgs, u16 data) {
    u32 uData = data << 0x10;

    Audio_QueueCmd(opArgs, (void**)&uData);
}

s32 Audio_ScheduleProcessCmds(void) {
    static s32 D_801304E8 = 0;
    s32 ret;

    if (D_801304E8 < (u8)((gAudioContext.cmdWrPos - gAudioContext.cmdRdPos) + 0x100)) {
        D_801304E8 = (u8)((gAudioContext.cmdWrPos - gAudioContext.cmdRdPos) + 0x100);
    }

    ret =
        osSendMesg(gAudioContext.cmdProcQueueP,
                   (void*)(((gAudioContext.cmdRdPos & 0xFF) << 8) | (gAudioContext.cmdWrPos & 0xFF)), OS_MESG_NOBLOCK);
    if (ret != -1) {
        gAudioContext.cmdRdPos = gAudioContext.cmdWrPos;
        ret = 0;
    } else {
        return -1;
    }

    return ret;
}

void Audio_ResetCmdQueue(void) {
    gAudioContext.cmdQueueFinished = 0;
    gAudioContext.cmdRdPos = gAudioContext.cmdWrPos;
}

void Audio_ProcessCmd(AudioCmd* cmd) {
    SequencePlayer* seqPlayer;
    u16 phi_v0;
    s32 i;

    if ((cmd->op & 0xF0) == 0xF0) {
        func_800E5584(cmd);
        return;
    }

    if (cmd->arg0 < gAudioContext.audioBufferParameters.numSequencePlayers) {
        seqPlayer = &gAudioContext.seqPlayers[cmd->arg0];
        if (cmd->op & 0x80) {
            func_800E5584(cmd);
            return;
        }
        if (cmd->op & 0x40) {
            func_800E6128(seqPlayer, cmd);
            return;
        }

        if (cmd->arg1 < 0x10) {
            func_800E6300(seqPlayer->channels[cmd->arg1], cmd);
            return;
        }
        if (cmd->arg1 == 0xFF) {
            phi_v0 = gAudioContext.unk_5BDC[cmd->arg0];
            for (i = 0; i < 0x10; i++) {
                if (phi_v0 & 1) {
                    func_800E6300(seqPlayer->channels[i], cmd);
                }
                phi_v0 = phi_v0 >> 1;
            }
        }
    }
}

void Audio_ProcessCmds(u32 msg) {
    static u8 curCmdRdPos = 0;
    AudioCmd* cmd;
    u8 endPos;

    if (!gAudioContext.cmdQueueFinished) {
        curCmdRdPos = msg >> 8;
    }

    while (true) {
        endPos = msg & 0xFF;
        if (curCmdRdPos == endPos) {
            gAudioContext.cmdQueueFinished = 0;
            return;
        }

        cmd = &gAudioContext.cmdBuf[curCmdRdPos++ & 0xFF];
        if (cmd->op == 0xF8) {
            gAudioContext.cmdQueueFinished = 1;
            return;
        }

        Audio_ProcessCmd(cmd);
        cmd->op = 0;
    }
}

u32 func_800E5E20(u32* out) {
    u32 sp1C = 0;

    if (osRecvMesg(&gAudioContext.externalLoadQueue, (OSMesg*)&sp1C, OS_MESG_NOBLOCK) == -1) {
        *out = 0;
        return 0;
    }
    *out = sp1C & 0xFFFFFF;
    return sp1C >> 0x18;
}

u8* func_800E5E84(s32 arg0, u32* arg1) {
    return AudioLoad_GetFontsForSequence(arg0, arg1);
}

void func_800E5EA4(s32 arg0, u32* arg1, u32* arg2) {
    *arg1 = gAudioContext.soundFonts[arg0].sampleBankId1;
    *arg2 = gAudioContext.soundFonts[arg0].sampleBankId2;
}

s32 func_800E5EDC(void) {
    s32 pad;
    s32 sp18 = 0;

    if (osRecvMesg(gAudioContext.audioResetQueueP, (OSMesg*)&sp18, OS_MESG_NOBLOCK) == -1) {
        return 0;
    } else if (gAudioContext.audioResetSpecIdToLoad != sp18) {
        return -1;
    } else {
        return 1;
    }
}

void func_800E5F34(void) {
    return; // TODO FIX HACK IGNORE
    // macro?
    // clang-format off
    s32 chk = -1; s32 sp28; do {} while (osRecvMesg(gAudioContext.audioResetQueueP, (OSMesg*)&sp28, OS_MESG_NOBLOCK) != chk);
    // clang-format on
}

s32 func_800E5F88(s32 resetPreloadID) {
    s32 resetStatus;
    OSMesg msg;
    s32 pad;

    func_800E5F34();
    resetStatus = gAudioContext.resetStatus;
    if (resetStatus != 0) {
        Audio_ResetCmdQueue();
        if (gAudioContext.audioResetSpecIdToLoad == resetPreloadID) {
            return -2;
        } else if (resetStatus > 2) {
            gAudioContext.audioResetSpecIdToLoad = resetPreloadID;
            return -3;
        } else {
            osRecvMesg(gAudioContext.audioResetQueueP, &msg, OS_MESG_BLOCK);
        }
    }

    func_800E5F34();
    Audio_QueueCmdS32(0xF9000000, resetPreloadID);

    return Audio_ScheduleProcessCmds();
}

void Audio_PreNMIInternal(void) {
    gAudioContext.resetTimer = 1;
    if (gAudioContextInitalized) {
        func_800E5F88(0);
        gAudioContext.resetStatus = 0;
    }
}

s8 func_800E6070(s32 playerIdx, s32 channelIdx, s32 scriptIdx) {
    SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[playerIdx];
    SequenceChannel* channel;
    if (seqPlayer->enabled) {
        channel = seqPlayer->channels[channelIdx];
        return channel->soundScriptIO[scriptIdx];
    } else {
        return -1;
    }
}

s8 func_800E60C4(s32 playerIdx, s32 arg1) {
    return gAudioContext.seqPlayers[playerIdx].soundScriptIO[arg1];
}

void Audio_InitExternalPool(void* mem, u32 size) {
    AudioHeap_AllocPoolInit(&gAudioContext.externalPool, mem, size);
}

void Audio_DestroyExternalPool(void) {
    gAudioContext.externalPool.start = NULL;
}

void func_800E6128(SequencePlayer* seqPlayer, AudioCmd* cmd) {
    f32 fadeVolume;
    switch (cmd->op) {
        case 0x41:
            if (seqPlayer->fadeVolumeScale != cmd->asFloat) {
                seqPlayer->fadeVolumeScale = cmd->asFloat;
                seqPlayer->recalculateVolume = 1;
            }
            return;
        case 0x47:
            seqPlayer->tempo = cmd->asInt * 0x30;
            return;
        case 0x49:
            seqPlayer->unk_0C = cmd->asInt * 0x30;
            return;
        case 0x4E:
            seqPlayer->unk_0C = cmd->asInt;
            return;
        case 0x48:
            seqPlayer->transposition = cmd->asSbyte;
            return;
        case 0x46:
            seqPlayer->soundScriptIO[cmd->arg2] = cmd->asSbyte;
            return;
        case 0x4A:
            fadeVolume = (s32)cmd->arg1 / 127.0f;
            goto block_11;
        case 0x4B:
            fadeVolume = ((s32)cmd->arg1 / 100.0f) * seqPlayer->fadeVolume;
        block_11:
            if (seqPlayer->state != 2) {
                seqPlayer->volume = seqPlayer->fadeVolume;
                if (cmd->asInt == 0) {
                    seqPlayer->fadeVolume = fadeVolume;
                } else {
                    s32 tmp = cmd->asInt;
                    seqPlayer->state = 0;
                    seqPlayer->fadeTimer = tmp;
                    seqPlayer->fadeVelocity = (fadeVolume - seqPlayer->fadeVolume) / tmp;
                }
            }
            return;
        case 0x4C:
            if (seqPlayer->state != 2) {
                if (cmd->asInt == 0) {
                    seqPlayer->fadeVolume = seqPlayer->volume;
                } else {
                    s32 tmp = cmd->asInt;
                    seqPlayer->state = 0;
                    seqPlayer->fadeTimer = tmp;
                    seqPlayer->fadeVelocity = (seqPlayer->volume - seqPlayer->fadeVolume) / tmp;
                }
            }
            return;
        case 0x4D:
            seqPlayer->unk_34 = cmd->asFloat;
            if (seqPlayer->unk_34 == 1.0f) {
                seqPlayer->unk_0b1 = 0;
            } else {
                seqPlayer->unk_0b1 = 1;
            }
    }
}

void func_800E6300(SequenceChannel* channel, AudioCmd* cmd) {
    switch (cmd->op) {
        case CHAN_UPD_VOL_SCALE:
            if (channel->volumeScale != cmd->asFloat) {
                channel->volumeScale = cmd->asFloat;
                channel->changes.s.volume = 1;
            }
            return;
        case CHAN_UPD_VOL:
            if (channel->volume != cmd->asFloat) {
                channel->volume = cmd->asFloat;
                channel->changes.s.volume = 1;
            }
            return;
        case CHAN_UPD_PAN_SIGNED:
            if (channel->newPan != cmd->asSbyte) {
                channel->newPan = cmd->asSbyte;
                channel->changes.s.pan = 1;
            }
            return;
        case CHAN_UPD_PAN_UNSIGNED:
            if (channel->newPan != cmd->asSbyte) {
                channel->panChannelWeight = cmd->asSbyte;
                channel->changes.s.pan = 1;
            }
            return;
        case CHAN_UPD_FREQ_SCALE:
            if (channel->freqScale != cmd->asFloat) {
                channel->freqScale = cmd->asFloat;
                channel->changes.s.freqScale = 1;
            }
            return;
        case CHAN_UPD_REVERB:
            if (channel->reverb != cmd->asSbyte) {
                channel->reverb = cmd->asSbyte;
            }
            return;
        case CHAN_UPD_SCRIPT_IO:
            if (cmd->arg2 < 8) {
                channel->soundScriptIO[cmd->arg2] = cmd->asSbyte;
            }
            return;
        case CHAN_UPD_STOP_SOMETHING2:
            channel->stopSomething2 = cmd->asSbyte;
            return;
        case CHAN_UPD_MUTE_BEHAVE:
            channel->muteBehavior = cmd->asSbyte;
            return;
        case CHAN_UPD_VIBE_X8:
            channel->vibratoExtentTarget = cmd->asUbyte * 8;
            channel->vibratoExtentChangeDelay = 1;
            return;
        case CHAN_UPD_VIBE_X32:
            channel->vibratoRateTarget = cmd->asUbyte * 32;
            channel->vibratoRateChangeDelay = 1;
            return;
        case CHAN_UPD_UNK_0F:
            channel->unk_0F = cmd->asUbyte;
            return;
        case CHAN_UPD_UNK_20:
            channel->unk_20 = cmd->asUShort;
            return;
        case CHAN_UPD_STEREO:
            channel->stereo.asByte = cmd->asUbyte;
            return;
    }
}

void func_800E64B0(s32 arg0, s32 arg1, s32 arg2) {
    Audio_QueueCmdS32(((arg0 & 0xFF) << 0x10) | 0xFA000000 | ((arg1 & 0xFF) << 8) | (arg2 & 0xFF), 1);
}

void func_800E64F8(void) {
    Audio_QueueCmdS32(0xFA000000, 0);
}

void func_800E651C(u32 arg0, s32 arg1) {
    Audio_QueueCmdS32((arg1 & 0xFF) | 0xFD000000, arg0);
}

void Audio_WaitForAudioTask(void) {
    osRecvMesg(gAudioContext.taskStartQueueP, NULL, OS_MESG_NOBLOCK);
    osRecvMesg(gAudioContext.taskStartQueueP, NULL, OS_MESG_BLOCK);
}

s32 func_800E6590(s32 playerIdx, s32 arg1, s32 arg2) {
    SequencePlayer* seqPlayer;
    SequenceLayer* layer;
    Note* note;
    SoundFontSound* sound;
    s32 loopEnd;
    s32 samplePos;

    seqPlayer = &gAudioContext.seqPlayers[playerIdx];
    if (seqPlayer->enabled && seqPlayer->channels[arg1]->enabled) {
        layer = seqPlayer->channels[arg1]->layers[arg2];
        if (layer == NULL) {
            return 0;
        }

        if (layer->enabled) {
            if (layer->note == NULL) {
                return 0;
            }

            if (!layer->bit3) {
                return 0;
            }

            note = layer->note;
            if (layer == note->playbackState.parentLayer) {
                sound = note->noteSubEu.sound.soundFontSound;
                if (sound == NULL) {
                    return 0;
                }
                loopEnd = sound->sample->loop->end;
                samplePos = note->synthesisState.samplePosInt;
                return loopEnd - samplePos;
            }
            return 0;
        }
    }
    return 0;
}

s32 func_800E6680(void) {
    return func_800E66C0(0);
}

void func_800E66A0(void) {
    func_800E66C0(2);
}

s32 func_800E66C0(s32 arg0) {
    s32 phi_v1;
    NotePlaybackState* temp_a2;
    NoteSubEu* temp_a3;
    s32 i;
    Note* note;
    SoundFontSound* sound;

    phi_v1 = 0;
    for (i = 0; i < gAudioContext.numNotes; i++) {
        note = &gAudioContext.notes[i];
        temp_a2 = &note->playbackState;
        if (note->noteSubEu.bitField0.enabled) {
            temp_a3 = &note->noteSubEu;
            if (temp_a2->adsr.action.s.state != 0) {
                if (arg0 >= 2) {
                    sound = temp_a3->sound.soundFontSound;
                    if (sound == NULL || temp_a3->bitField1.isSyntheticWave) {
                        continue;
                    }
                    if (sound->sample->medium == MEDIUM_RAM) {
                        continue;
                    }
                }

                phi_v1++;
                if ((arg0 & 1) == 1) {
                    temp_a2->adsr.fadeOutVel = gAudioContext.audioBufferParameters.updatesPerFrameInv;
                    temp_a2->adsr.action.s.release = 1;
                }
            }
        }
    }
    return phi_v1;
}

u32 Audio_NextRandom(void) {
    static u32 audRand = 0x12345678;

    audRand = ((osGetCount() + 0x1234567) * (audRand + gAudioContext.totalTaskCnt));
    audRand += gAudioContext.audioRandom;
    return audRand;
}

void Audio_InitMesgQueues(void) {
    Audio_InitMesgQueuesInternal();
}

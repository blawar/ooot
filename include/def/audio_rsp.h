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
s32 Audio_Sync(void);
s32 func_800E5F88(s32 arg0);
s32 func_800E6680(void);
u32 osGetCount(void);
AudioTask* getAudioTask();

enum ChannelUpdateType
{
	CHAN_UPD_UNK_0,		  // 0
	CHAN_UPD_VOL_SCALE,	  // 1
	CHAN_UPD_VOL,		  // 2
	CHAN_UPD_PAN_SIGNED,	  // 3
	CHAN_UPD_FREQ_SCALE,	  // 4
	CHAN_UPD_REVERB,	  // 5
	CHAN_UPD_SCRIPT_IO,	  // 6
	CHAN_UPD_PAN_UNSIGNED,	  // 7
	CHAN_UPD_STOP_SOMETHING2, // 8
	CHAN_UPD_MUTE_BEHAVE,	  // 9
	CHAN_UPD_VIBE_X8,	  // 10
	CHAN_UPD_VIBE_X32,	  // 11
	CHAN_UPD_UNK_0F,	  // 12
	CHAN_UPD_UNK_20,	  // 13
	CHAN_UPD_STEREO		  // 14
};

enum LoadChannelType
{
	CHAN_LOAD_SET_SOUND_MODE	       = 0xF0,
	CHAN_LOAD_UKN_F1	       = 0xF1,
	CHAN_LOAD_UKN_F2	       = 0xF2,
	CHAN_LOAD_INSTRUMENT_ASYNC	       = 0xF3,
	CHAN_LOAD_BANK_ASYNC	       = 0xF4,
	CHAN_LOAD_FONT_ASYNC	       = 0xF5,
	CHAN_LOAD_DISCARD_SEQ_FONTS	       = 0xF6,
	CHAN_LOAD_UKN_FC	       = 0xFC,
	CHAN_LOAD_UKN_81	       = 0x81,
	CHAN_LOAD_UKN_82	       = 0x82,
	CHAN_LOAD_DISABLE_SEQUENCE	       = 0x83,
	CHAN_LOAD_UKN_85	       = 0x85,
	CHAN_LOAD_UKN_90	       = 0x90,
	CHAN_LOAD_SET_FONT_INSTRUMENT0 = 0xE0,
	CHAN_LOAD_SET_FONT_INSTRUMENT1 = 0xE1,
	CHAN_LOAD_SET_FONT_INSTRUMENT  = 0xE2,
	CHAN_LOAD_POP_CACHE	       = 0xE3,
	CHAN_LOAD_RESET_LOAD_SPECID    = 0xF9,
	CHAN_LOAD_UKN_FB_CALLBACK      = 0xFB,
	CHAN_LOAD_UKN_FE	       = 0xFE
};

enum SequenceCommandType
{
	SEQ_CMD_UKN_41 = 0x41,
	SEQ_CMD_UKN_46 = 0x46,
	SEQ_CMD_SET_TEMPO = 0x47,
	SEQ_CMD_UKN_48 = 0x48,
	SEQ_CMD_UKN_49 = 0x49,
	SEQ_CMD_UKN_4A = 0x4A,
	SEQ_CMD_UKN_4B = 0x4B,
	SEQ_CMD_UKN_4C = 0x4C,
	SEQ_CMD_UKN_4D = 0x4D,
	SEQ_CMD_UKN_4E = 0x4E
};

const u8 QUEUE_FINISHED = 0xF8;
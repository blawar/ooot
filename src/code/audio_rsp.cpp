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
#include "AziAudio/AziAudio/AudioSpec.h"

#include "redef_msgqueue.h"

u32 osGetCount(void);

#define SAMPLES_TO_OVERPRODUCE 0x10
#define EXTRA_BUFFERED_AI_SAMPLES_TARGET 0x80

void Audio_ProcessChannelCmd(SequenceChannel* channel, AudioCmd* arg1);
void Audio_LoadSetFadeInTimer(s32 playerIdx, s32 fadeTimer);
void Audio_InitMesgQueues(void);
AudioTask* getAudioTask(void);
void Audio_ProcessCmds(u32);
void Audio_ProcessSequenceCmd(SequencePlayer* seqPlayer, AudioCmd* arg1);
void Audio_LoadSetFadeOutTimer(s32 playerIdx, s32 fadeTimer);
s32 func_800E66C0(s32 arg0);

// AudioMgr_Retrace
AudioTask* func_800E4FE0(void) {
    return getAudioTask();
}

extern u32 rspAspMainDataStart[0x5C * 2];

AudioTask* getAudioTask() {
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
        }
    }

    if (D_801755D0 != NULL) {
        D_801755D0();
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
    task->ucode_data = (u64*)rspAspMainDataStart;
    task->ucode_size = 0x1000;
    task->dram_stack = NULL;
    task->dram_stack_size = 0;
    task->output_buff = NULL;
    task->output_buff_size = NULL;

    task->data_ptr = (u64*)gAudioContext.abiCmdBufs[index];
    task->data_size = abiCmdCnt * sizeof(Acmd);
    task->yield_data_ptr = NULL;
    task->yield_data_size = 0;

    //HLEStart((AZI_OSTask*)task);

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

void Audio_ProcessLoadCmd(AudioCmd* cmd) {
    s32 i;
    s32 pad;
    s32 pad2;
    u32 temp_a1_5;
    u32 temp_t7;

    switch (cmd->op) {
	    case CHAN_LOAD_UKN_81:
            AudioLoad_SyncLoadSeqParts(cmd->arg1, cmd->arg2);
            return;
	    case CHAN_LOAD_UKN_82:
            AudioLoad_SyncInitSeqPlayer(cmd->arg0, cmd->arg1, cmd->arg2);
            Audio_LoadSetFadeInTimer(cmd->arg0, (s32)cmd->data);
            return;
	    case CHAN_LOAD_UKN_85:
		AudioLoad_SyncInitSeqPlayerSkipTicks(cmd->arg0, cmd->arg1, (s32)cmd->data);
            return;
	    case CHAN_LOAD_DISABLE_SEQUENCE:
            if (gAudioContext.seqPlayers[cmd->arg0].enabled) {
                if (cmd->asInt == 0) {
                    AudioSeq_SequencePlayerDisableAsFinished(&gAudioContext.seqPlayers[cmd->arg0]);
                } else {
                    Audio_LoadSetFadeOutTimer(cmd->arg0, cmd->asInt);
                }
            }
            return;
        case CHAN_LOAD_SET_SOUND_MODE:
            gAudioContext.soundMode = cmd->asUInt;
            return;
        case CHAN_LOAD_UKN_F1:
            for (i = 0; i < gAudioContext.audioBufferParameters.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[i];
                seqPlayer->muted = 1;
                seqPlayer->recalculateVolume = 1;
            }
            return;
        case CHAN_LOAD_UKN_F2:
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
        case CHAN_LOAD_INSTRUMENT_ASYNC:
            AudioLoad_SyncLoadInstrument(cmd->arg0, cmd->arg1, cmd->arg2);
            return;
        case CHAN_LOAD_BANK_ASYNC:
            AudioLoad_AsyncLoadSampleBank(cmd->arg0, cmd->arg1, cmd->arg2, nullptr);
            return;
        case CHAN_LOAD_FONT_ASYNC:
            AudioLoad_AsyncLoadFont(cmd->arg0, cmd->arg1, cmd->arg2, nullptr);
            return;
        case CHAN_LOAD_UKN_FC:
            AudioLoad_AsyncLoadSeq(cmd->arg0, cmd->arg1, cmd->arg2, nullptr);
            return;
        case CHAN_LOAD_DISCARD_SEQ_FONTS:
            AudioLoad_DiscardSeqFonts(cmd->arg1);
            return;
        case CHAN_LOAD_UKN_90:
            gAudioContext.unk_5BDC[cmd->arg0] = cmd->asUShort;
            return;
        case CHAN_LOAD_RESET_LOAD_SPECID:
            gAudioContext.resetStatus = 5;
            gAudioContext.audioResetSpecIdToLoad = cmd->asUInt;
            return;
        case CHAN_LOAD_UKN_FB_CALLBACK:
            D_801755D0 = (void (*)(void))cmd->asUInt;
            return;
        case CHAN_LOAD_SET_FONT_INSTRUMENT0:
        case CHAN_LOAD_SET_FONT_INSTRUMENT1:
        case CHAN_LOAD_SET_FONT_INSTRUMENT:
            Audio_SetFontInstrument(cmd->op - 0xE0, cmd->arg0, cmd->arg1, cmd->data);
            return;
        case CHAN_LOAD_UKN_FE:
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
        case CHAN_LOAD_POP_CACHE:
            AudioHeap_PopCache(cmd->asInt);
            return;
        default:
            return;
    }
}

// SetFadeOutTimer
void Audio_LoadSetFadeOutTimer(s32 playerIdx, s32 fadeTimer) {
    SequencePlayer* seqPlayer = &gAudioContext.seqPlayers[playerIdx];

    if (fadeTimer == 0) {
        fadeTimer = 1;
    }

    seqPlayer->fadeVelocity = -(seqPlayer->fadeVolume / fadeTimer);
    seqPlayer->state = 2;
    seqPlayer->fadeTimer = fadeTimer;
}

// SetFadeInTimer
void Audio_LoadSetFadeInTimer(s32 playerIdx, s32 fadeTimer) {
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
    s32 ret =
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
        Audio_ProcessLoadCmd(cmd);
        return;
    }

    if (cmd->arg0 < gAudioContext.audioBufferParameters.numSequencePlayers) {
        seqPlayer = &gAudioContext.seqPlayers[cmd->arg0];
        if (cmd->op & 0x80) {
            Audio_ProcessLoadCmd(cmd);
            return;
        }
        if (cmd->op & 0x40) {
            Audio_ProcessSequenceCmd(seqPlayer, cmd);
            return;
        }

        if (cmd->arg1 < 0x10) {
            Audio_ProcessChannelCmd(seqPlayer->channels[cmd->arg1], cmd);
            return;
        }
        if (cmd->arg1 == 0xFF) {
            phi_v0 = gAudioContext.unk_5BDC[cmd->arg0];
            for (i = 0; i < 0x10; i++) {
                if (phi_v0 & 1) {
                    Audio_ProcessChannelCmd(seqPlayer->channels[i], cmd);
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
        if (cmd->op == QUEUE_FINISHED) {
            gAudioContext.cmdQueueFinished = 1;
            return;
        }

        Audio_ProcessCmd(cmd);
        cmd->op = 0;
    }
}

u32 func_800E5E20(u32* out) {
    u32 sp1C = 0;

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

s32 Audio_Sync(void) {
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
    //return; // TODO FIX HACK IGNORE
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
    Audio_QueueCmdS32(CHAN_LOAD_RESET_LOAD_SPECID << 24, resetPreloadID);

    return Audio_ScheduleProcessCmds();
}

void Audio_PreNMIInternal(void) {
    gAudioContext.resetTimer = 1;
    if (gAudioContextInitalized) {
        func_800E5F88(0);
        gAudioContext.resetStatus = 0;
    }
}

s8 Audio_GetScriptIO_Value(s32 playerIdx, s32 channelIdx, s32 scriptIdx) {
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

void Audio_ProcessSequenceCmd(SequencePlayer* seqPlayer, AudioCmd* cmd) {
    f32 fadeVolume;
    switch (cmd->op) {
        case SEQ_CMD_UKN_41:
            if (seqPlayer->fadeVolumeScale != cmd->asFloat) {
                seqPlayer->fadeVolumeScale = cmd->asFloat;
                seqPlayer->recalculateVolume = 1;
            }
            return;
        case SEQ_CMD_SET_TEMPO:
            seqPlayer->tempo = cmd->asInt * 0x30;
            return;
        case SEQ_CMD_UKN_49:
            seqPlayer->unk_0C = cmd->asInt * 0x30;
            return;
        case SEQ_CMD_UKN_4E:
            seqPlayer->unk_0C = cmd->asInt;
            return;
        case SEQ_CMD_UKN_48:
            seqPlayer->transposition = cmd->asSbyte;
            return;
        case SEQ_CMD_UKN_46:
            seqPlayer->soundScriptIO[cmd->arg2] = cmd->asSbyte;
            return;
        case SEQ_CMD_UKN_4A:
            fadeVolume = (s32)cmd->arg1 / 127.0f;
            goto block_11;
        case SEQ_CMD_UKN_4B:
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
        case SEQ_CMD_UKN_4C:
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
        case SEQ_CMD_UKN_4D:
            seqPlayer->unk_34 = cmd->asFloat;
            if (seqPlayer->unk_34 == 1.0f) {
                seqPlayer->unk_0b1 = 0;
            } else {
                seqPlayer->unk_0b1 = 1;
            }
    }
}

void Audio_ProcessChannelCmd(SequenceChannel* channel, AudioCmd* cmd) {
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

#define INTERNAL_SRC_CODE_CODE_800F9280_C
#include "ultra64.h"
#include "global.h"
#include "z64audio.h"
#include "sequence.h"
#include "ultra64/abi.h"
#include "def/audio_rsp.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"

u8 sSeqCmdWrPos = 0;
u8 sSeqCmdRdPos = 0;
u8 gAudioDisable	= 0;
u8 D_8013340C	= 1;
u8 D_80133410[] = {0, 1, 2, 3};
u8 gAudioSpecId = 0;
u8 D_80133418	= 0;

// TODO: clean up these macros. They are similar to ones in audio.c but without casts.
#define Audio_StartSeq(playerIdx, fadeTimer, seqId) \
    Audio_QueueSeqCmd(0x00000000 | ((playerIdx) << 24) | ((fadeTimer) << 16) | (seqId))
#define Audio_SeqSetChannelStopMask(playerIdx, a) Audio_QueueSeqCmd(0xA0000000 | ((playerIdx) << 24) | (a))
#define Audio_SeqCmdB30(playerIdx, a, b) Audio_QueueSeqCmd(0xB0003000 | ((playerIdx) << 24) | ((a) << 16) | (b))
#define Audio_SeqUpdateTempo2(playerIdx, a, b) Audio_QueueSeqCmd(0xB0004000 | ((playerIdx) << 24) | ((a) << 16) | (b))
#define Audio_SeqCmd3(playerIdx, a) Audio_QueueSeqCmd(0x30000000 | ((playerIdx) << 24) | (a))
#define Audio_SeqCmd5(playerIdx, a, b) Audio_QueueSeqCmd(0x50000000 | ((playerIdx) << 24) | ((a) << 16) | (b))
#define Audio_SeqCmd_Trans_Volume(playerIdx, a, b) Audio_QueueSeqCmd(0x40000000 | ((playerIdx) << 24) | ((a) << 16) | (b))
#define Audio_SetVolScaleNow(playerIdx, volFadeTimer, volScale) \
    Audio_ProcessSeqCmd(0x40000000 | ((u8)playerIdx << 24) | ((u8)volFadeTimer << 16) | ((u8)(volScale * 127.0f)));

void Audio_PlaySequenceInternal(u8 playerIdx, u8 seqId, u8 seqFlags, u16 fadeTimer) {
    u8 i;
    u16 dur;
    s32 pad;

    if (gAudioDisable == 0 || playerIdx == SEQ_PLAYER_SFX) {
        seqFlags &= 0x7F;
        if (seqFlags == 0x7F) {
            dur = (fadeTimer >> 3) * 60 * gAudioContext.audioBufferParameters.updatesPerFrame;
            Audio_QueueCmdS32(CHAN_LOAD_UKN_85 << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(seqId, 8, 8), dur);
        } else {
            Audio_QueueCmdS32(CHAN_LOAD_UKN_82 << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(seqId, 8, 8),
                              (fadeTimer * (u16)gAudioContext.audioBufferParameters.updatesPerFrame) / 4);
        }

        gAudioPlayers[playerIdx].seqAndFlags = seqId | (seqFlags << 8);
        gAudioPlayers[playerIdx].unk_256 = seqId | (seqFlags << 8);

        if (gAudioPlayers[playerIdx].volCur != 1.0f) {
            Audio_QueueCmdF32(SEQ_CMD_UKN_41 << 24 | _SHIFTL(playerIdx, 16, 8), gAudioPlayers[playerIdx].volCur);
        }

        gAudioPlayers[playerIdx].unk_28 = 0;
        gAudioPlayers[playerIdx].unk_18 = 0;
        gAudioPlayers[playerIdx].unk_14 = 0;

        for (i = 0; i < 0x10; i++) {
            gAudioPlayers[playerIdx].unk_50[i].unk_00 = 1.0f;
            gAudioPlayers[playerIdx].unk_50[i].unk_0C = 0;
            gAudioPlayers[playerIdx].unk_50[i].unk_10 = 1.0f;
            gAudioPlayers[playerIdx].unk_50[i].unk_1C = 0;
        }

        gAudioPlayers[playerIdx].unk_250 = 0;
        gAudioPlayers[playerIdx].unk_252 = 0;
    }
}

void Audio_SendDisableSequence(u8 playerIdx, u16 arg1) {
	Audio_QueueCmdS32(CHAN_LOAD_DISABLE_SEQUENCE << 24 | ((u8)playerIdx << 16),
                      (arg1 * (u16)gAudioContext.audioBufferParameters.updatesPerFrame) / 4);
    gAudioPlayers[playerIdx].seqAndFlags = NA_BGM_DISABLED;
}

typedef enum {
    SEQ_START,
    CMD1,
    CMD2,
    CMD3,
    SEQ_VOL_UPD,
    CMD5,
    CMD6,
    CMD7,
    CMD8,
    CMD9,
    CMDA,
    CMDB,
    CMDC,
    CMDD,
    CMDE,
    CMDF
} SeqCmdType;

typedef struct {
    u8 unk_0;
    u8 unk_1; // importance?
} AudioPlayerInfo;

#define MAX_PLAYERS 4
AudioPlayerInfo gAudioPlayerInfo[MAX_PLAYERS][5]; // sorted by unk_1, descending

void Audio_ProcessSeqCmd(u32 cmd) {
    s32 pad[2];
    u16 fadeTimer;
    u16 channelMask;
    u16 val;
    u8 oldSpec;
    u8 spec;
    u8 op;
    u8 subOp;
    u8 playerIdx;
    u8 seqId;
    u8 seqArgs;
    u8 found;
    u8 port;
    u8 duration;
    u8 chanIdx;
    u8 i;
    s32 new_var;
    f32 freqScale;

    if (D_8013340C && (cmd & 0xF0000000) != 0x70000000) {
        AudioDebug_ScrPrt((const s8*)D_80133390, (cmd >> 16) & 0xFFFF); // "SEQ H"
        AudioDebug_ScrPrt((const s8*)D_80133398, cmd & 0xFFFF);         // "    L"
    }

    op = cmd >> 28;
    playerIdx = (cmd & 0xF000000) >> 24;

    switch (op) {
	    case AUDIO_CMD_SEQUENCE_PLAY:
            // play sequence immediately
            seqId = cmd & 0xFF;
            seqArgs = (cmd & 0xFF00) >> 8;
            fadeTimer = (cmd & 0xFF0000) >> 13;
            if ((gAudioPlayers[playerIdx].unk_260 == 0) && (seqArgs < 0x80)) {
                Audio_PlaySequenceInternal(playerIdx, seqId, seqArgs, fadeTimer);
            }
            break;

        case AUDIO_CMD_DISABLE_PLAYER:
            // disable seq player
            fadeTimer = (cmd & 0xFF0000) >> 13;
            Audio_SendDisableSequence(playerIdx, fadeTimer);
            break;

        case AUDIO_CMD_SEQUENCE_QUEUE:
            // queue sequence
            seqId = cmd & 0xFF;
            seqArgs = (cmd & 0xFF00) >> 8;
            fadeTimer = (cmd & 0xFF0000) >> 13;
            new_var = seqArgs;
            for (i = 0; i < gAudioPlayerInfoNum[playerIdx]; i++) {
                if (gAudioPlayerInfo[playerIdx][i].unk_0 == seqId) {
                    if (i == 0) {
                        Audio_PlaySequenceInternal(playerIdx, seqId, seqArgs, fadeTimer);
                    }
                    return;
                }
            }

            found = gAudioPlayerInfoNum[playerIdx];
            for (i = 0; i < gAudioPlayerInfoNum[playerIdx]; i++) {
                if (gAudioPlayerInfo[playerIdx][i].unk_1 <= new_var) {
                    found = i;
                    i = gAudioPlayerInfoNum[playerIdx]; // "break;"
                }
            }

            if (gAudioPlayerInfoNum[playerIdx] < 5) {
                gAudioPlayerInfoNum[playerIdx]++;
            }
            for (i = gAudioPlayerInfoNum[playerIdx] - 1; i != found; i--) {
                gAudioPlayerInfo[playerIdx][i].unk_1 = gAudioPlayerInfo[playerIdx][i - 1].unk_1;
                gAudioPlayerInfo[playerIdx][i].unk_0 = gAudioPlayerInfo[playerIdx][i - 1].unk_0;
            }
            gAudioPlayerInfo[playerIdx][found].unk_1 = seqArgs;
            gAudioPlayerInfo[playerIdx][found].unk_0 = seqId;

            if (found == 0) {
                Audio_PlaySequenceInternal(playerIdx, seqId, seqArgs, fadeTimer);
            }
            break;

        case AUDIO_CMD_SEQUENCE_STOP:
            // unqueue/stop sequence
            seqId = cmd & 0xFF;
            fadeTimer = (cmd & 0xFF0000) >> 13;

            found = gAudioPlayerInfoNum[playerIdx];
            for (i = 0; i < gAudioPlayerInfoNum[playerIdx]; i++) {
                if (gAudioPlayerInfo[playerIdx][i].unk_0 == seqId) {
                    found = i;
                    i = gAudioPlayerInfoNum[playerIdx]; // "break;"
                }
            }

            if (found != gAudioPlayerInfoNum[playerIdx]) {
                for (i = found; i < gAudioPlayerInfoNum[playerIdx] - 1; i++) {
                    gAudioPlayerInfo[playerIdx][i].unk_1 = gAudioPlayerInfo[playerIdx][i + 1].unk_1;
                    gAudioPlayerInfo[playerIdx][i].unk_0 = gAudioPlayerInfo[playerIdx][i + 1].unk_0;
                }
                gAudioPlayerInfoNum[playerIdx]--;
            }

            if (found == 0) {
                Audio_SendDisableSequence(playerIdx, fadeTimer);
                if (gAudioPlayerInfoNum[playerIdx] != 0) {
                    Audio_PlaySequenceInternal(playerIdx, gAudioPlayerInfo[playerIdx][0].unk_0, gAudioPlayerInfo[playerIdx][0].unk_1, fadeTimer);
                }
            }
            break;

        case AUDIO_CMD_SEQUENCE_TRANS_VOLUME:
            // transition seq volume
            duration = (cmd & 0xFF0000) >> 15;
            val = cmd & 0xFF;
            if (duration == 0) {
                duration++;
            }
            gAudioPlayers[playerIdx].volTarget = (f32)val / 127.0f;
            if (gAudioPlayers[playerIdx].volCur != gAudioPlayers[playerIdx].volTarget) {
                gAudioPlayers[playerIdx].unk_08 =
                    (gAudioPlayers[playerIdx].volCur - gAudioPlayers[playerIdx].volTarget) / (f32)duration;
                gAudioPlayers[playerIdx].unk_0C = duration;
            }
            break;

        case AUDIO_CMD_SEQUENCE_TRANS_FREQ_SCALE_ALL:
            // transition freq scale for all channels
            duration = (cmd & 0xFF0000) >> 15;
            val = cmd & 0xFFFF;
            if (duration == 0) {
                duration++;
            }
            freqScale = (f32)val / 1000.0f;
            for (i = 0; i < 16; i++) {
                gAudioPlayers[playerIdx].unk_50[i].unk_14 = freqScale;
                gAudioPlayers[playerIdx].unk_50[i].unk_1C = duration;
                gAudioPlayers[playerIdx].unk_50[i].unk_18 =
                    (gAudioPlayers[playerIdx].unk_50[i].unk_10 - freqScale) / (f32)duration;
            }
            gAudioPlayers[playerIdx].unk_250 = 0xFFFF;
            break;

        case AUDIO_CMD_SEQUENCE_TRANS_FREQ_SCALE:
            // transition freq scale
            duration = (cmd & 0xFF0000) >> 15;
            chanIdx = (cmd & 0xF000) >> 12;
            val = cmd & 0xFFF;
            if (duration == 0) {
                duration++;
            }
            freqScale = (f32)val / 1000.0f;
            gAudioPlayers[playerIdx].unk_50[chanIdx].unk_14 = freqScale;
            gAudioPlayers[playerIdx].unk_50[chanIdx].unk_18 =
                (gAudioPlayers[playerIdx].unk_50[chanIdx].unk_10 - freqScale) / (f32)duration;
            gAudioPlayers[playerIdx].unk_50[chanIdx].unk_1C = duration;
            gAudioPlayers[playerIdx].unk_250 |= 1 << chanIdx;
            break;

        case AUDIO_CMD_SEQUENCE_TRANS_VOL_SCALE:
            // transition vol scale
            duration = (cmd & 0xFF0000) >> 15;
            chanIdx = (cmd & 0xF00) >> 8;
            val = cmd & 0xFF;
            if (duration == 0) {
                duration++;
            }
            gAudioPlayers[playerIdx].unk_50[chanIdx].unk_04 = (f32)val / 127.0f;
            if (gAudioPlayers[playerIdx].unk_50[chanIdx].unk_00 != gAudioPlayers[playerIdx].unk_50[chanIdx].unk_04) {
                gAudioPlayers[playerIdx].unk_50[chanIdx].unk_08 =
                    (gAudioPlayers[playerIdx].unk_50[chanIdx].unk_00 - gAudioPlayers[playerIdx].unk_50[chanIdx].unk_04) /
                    (f32)duration;
                gAudioPlayers[playerIdx].unk_50[chanIdx].unk_0C = duration;
                gAudioPlayers[playerIdx].unk_252 |= 1 << chanIdx;
            }
            break;

        case AUDIO_CMD_SET_IO_PORT_GLOBAL:
            // set global io port
            port = (cmd & 0xFF0000) >> 16;
            val = cmd & 0xFF;
            Audio_QueueCmdS8(SEQ_CMD_UKN_46 << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(port, 0, 8), val);
            break;

        case AUDIO_CMD_SET_IO_PORT_MASKED:
            // set io port if channel masked
            chanIdx = (cmd & 0xF00) >> 8;
            port = (cmd & 0xFF0000) >> 16;
            val = cmd & 0xFF;
            if ((gAudioPlayers[playerIdx].unk_258 & (1 << chanIdx)) == 0) {
                Audio_QueueCmdS8(CHAN_UPD_SCRIPT_IO << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(chanIdx, 8, 8) | _SHIFTL(port, 0, 8),
                                 val);
            }
            break;

        case AUDIO_CMD_SET_IO_PORT_MASK:
            // set channel mask for command 0x8
            gAudioPlayers[playerIdx].unk_258 = cmd & 0xFFFF;
            break;

        case AUDIO_CMD_SET_CHANNEL_STOP_MASK:
            // set channel stop mask
            channelMask = cmd & 0xFFFF;
            if (channelMask != 0) {
                // with channel mask channelMask...
                Audio_QueueCmdU16(0x90 << 24 | _SHIFTL(playerIdx, 16, 8), channelMask);
                // stop channels
                Audio_QueueCmdS8(CHAN_UPD_STOP_SOMETHING2 << 24 | _SHIFTL(playerIdx, 16, 8) | 0xFF00, 1);
            }
            if ((channelMask ^ 0xFFFF) != 0) {
                // with channel mask ~channelMask...
                Audio_QueueCmdU16(0x90 << 24 | _SHIFTL(playerIdx, 16, 8), (channelMask ^ 0xFFFF));
                // unstop channels
                Audio_QueueCmdS8(CHAN_UPD_STOP_SOMETHING2 << 24 | _SHIFTL(playerIdx, 16, 8) | 0xFF00, 0);
            }
            break;

        case AUDIO_CMD_UPDATE_TEMPO:
            // update tempo
            gAudioPlayers[playerIdx].unk_14 = cmd;
            break;

        case AUDIO_CMD_SEQUENCE_START_WITH_SETUP:
            // start sequence with setup commands
            subOp = (cmd & 0xF00000) >> 20;
            if (subOp != 0xF) {
                if (gAudioPlayers[playerIdx].unk_4D < 7) {
                    found = gAudioPlayers[playerIdx].unk_4D++;
                    if (found < 8) {
                        gAudioPlayers[playerIdx].unk_2C[found] = cmd;
                        gAudioPlayers[playerIdx].unk_4C = 2;
                    }
                }
            } else {
                gAudioPlayers[playerIdx].unk_4D = 0;
            }
            break;

        case AUDIO_CMD_0E:
            subOp = (cmd & 0xF00) >> 8;
            val = cmd & 0xFF;
            switch (subOp) {
                case 0:
                    // set sound mode
                    Audio_QueueCmdS32(CHAN_LOAD_SET_SOUND_MODE << 24, D_80133410[val]);
                    break;
                case 1:
                    // set sequence starting disabled?
                    gAudioDisable = val & 1;
                    break;
            }
            break;

        case AUDIO_CMD_CHANGE_SPEC:
            // change spec
            spec = cmd & 0xFF;
            gSfxChannelLayout = (cmd & 0xFF00) >> 8;
            oldSpec = gAudioSpecId;
            gAudioSpecId = spec;
            func_800E5F88(spec);
            func_800F71BC(oldSpec);
            Audio_QueueCmdS32(QUEUE_FINISHED << 24, 0);
            break;
    }
}

void Audio_QueueSeqCmd(u32 cmd) {
    sAudioSeqCmds[sSeqCmdWrPos++] = cmd;
}

void Audio_ProcessSeqCmds(void) {
    while (sSeqCmdWrPos != sSeqCmdRdPos) {
        Audio_ProcessSeqCmd(sAudioSeqCmds[sSeqCmdRdPos++]);
    }
}

u16 Audio_GetSequenceBeingPlayed(u8 playerIdx) {
    if (!gAudioContext.seqPlayers[playerIdx].enabled) {
        return NA_BGM_DISABLED;
    }
    return gAudioPlayers[playerIdx].seqAndFlags;
}

s32 Audio_IsCommandNotIssued(u32 arg0, u32 arg1) {
    u8 i;

    for (i = sSeqCmdRdPos; i != sSeqCmdWrPos; i++) {
        if (arg0 == (sAudioSeqCmds[i] & arg1)) {
            return false;
        }
    }

    return true;
}

void func_800FA174(u8 playerIdx) {
    gAudioPlayerInfoNum[playerIdx] = 0;
}

void func_800FA18C(u8 playerIdx, u8 arg1) {
    u8 i;

    for (i = 0; i < gAudioPlayers[playerIdx].unk_4D; i++) {
        u8 unkb = (gAudioPlayers[playerIdx].unk_2C[i] & 0xF00000) >> 20;

        if (unkb == arg1) {
            gAudioPlayers[playerIdx].unk_2C[i] = 0xFF000000;
        }
    }
}

void Audio_SetVolScale(u8 playerIdx, u8 scaleIdx, u8 targetVol, u8 volFadeTimer) {
    f32 volScale;
    u8 i;

    gAudioPlayers[playerIdx].volScales[scaleIdx] = targetVol & 0x7F;

    if (volFadeTimer != 0) {
        gAudioPlayers[playerIdx].fadeVolUpdate = 1;
        gAudioPlayers[playerIdx].volFadeTimer = volFadeTimer;
    } else {
        for (i = 0, volScale = 1.0f; i < 4; i++) {
            volScale *= gAudioPlayers[playerIdx].volScales[i] / 127.0f;
        }

        Audio_SetVolScaleNow(playerIdx, volFadeTimer, volScale);
    }
}

void func_800FA3DC(void) {
    u32 temp_a1;
    u16 temp_lo;
    u16 temp_v1;
    u16 phi_a2;
    u8 temp_v0_4;
    u8 temp_a0;
    u8 temp_s1;
    u8 temp_s0_3;
    u8 temp_a3_3;
    s32 pad[3];
    u32 dummy;
    f32 phi_f0;
    u8 phi_t0;
    u8 playerIdx;
    u8 j;
    u8 k;

    for (playerIdx = 0; playerIdx < 4; playerIdx++) {
        if (gAudioPlayers[playerIdx].unk_260 != 0) {
            switch (func_800E5E20(&dummy)) {
                case 1:
                case 2:
                case 3:
                case 4:
                    gAudioPlayers[playerIdx].unk_260 = 0;
                    Audio_ProcessSeqCmd(gAudioPlayers[playerIdx].unk_25C);
                    break;
            }
        }

        if (gAudioPlayers[playerIdx].fadeVolUpdate) {
            phi_f0 = 1.0f;
            for (j = 0; j < 4; j++) {
                phi_f0 *= (gAudioPlayers[playerIdx].volScales[j] / 127.0f);
            }
            Audio_SeqCmd_Trans_Volume(playerIdx, gAudioPlayers[playerIdx].volFadeTimer, (u8)(phi_f0 * 127.0f));
            gAudioPlayers[playerIdx].fadeVolUpdate = 0;
        }

        if (gAudioPlayers[playerIdx].unk_0C != 0) {
            gAudioPlayers[playerIdx].unk_0C--;

            if (gAudioPlayers[playerIdx].unk_0C != 0) {
                gAudioPlayers[playerIdx].volCur = gAudioPlayers[playerIdx].volCur - gAudioPlayers[playerIdx].unk_08;
            } else {
                gAudioPlayers[playerIdx].volCur = gAudioPlayers[playerIdx].volTarget;
            }

            Audio_QueueCmdF32(SEQ_CMD_UKN_41 << 24 | _SHIFTL(playerIdx, 16, 8), gAudioPlayers[playerIdx].volCur);
        }

        if (gAudioPlayers[playerIdx].unk_14 != 0) {
            temp_a1 = gAudioPlayers[playerIdx].unk_14;
            phi_t0 = (temp_a1 & 0xFF0000) >> 15;
            phi_a2 = temp_a1 & 0xFFF;
            if (phi_t0 == 0) {
                phi_t0++;
            }

            if (gAudioContext.seqPlayers[playerIdx].enabled) {
                temp_lo = gAudioContext.seqPlayers[playerIdx].tempo / 0x30;
                temp_v0_4 = (temp_a1 & 0xF000) >> 12;
                switch (temp_v0_4) {
                    case 1:
                        phi_a2 += temp_lo;
                        break;
                    case 2:
                        if (phi_a2 < temp_lo) {
                            phi_a2 = temp_lo - phi_a2;
                        }
                        break;
                    case 3:
                        phi_a2 = temp_lo * (phi_a2 / 100.0f);
                        break;
                    case 4:
                        if (gAudioPlayers[playerIdx].unk_18) {
                            phi_a2 = gAudioPlayers[playerIdx].unk_18;
                        } else {
                            phi_a2 = temp_lo;
                        }
                        break;
                }

                if (phi_a2 > 300) {
                    phi_a2 = 300;
                }

                if (gAudioPlayers[playerIdx].unk_18 == 0) {
                    gAudioPlayers[playerIdx].unk_18 = temp_lo;
                }

                gAudioPlayers[playerIdx].unk_20 = phi_a2;
                gAudioPlayers[playerIdx].tempo = gAudioContext.seqPlayers[playerIdx].tempo / 0x30;
                gAudioPlayers[playerIdx].unk_24 = (gAudioPlayers[playerIdx].tempo - gAudioPlayers[playerIdx].unk_20) / phi_t0;
                gAudioPlayers[playerIdx].unk_28 = phi_t0;
                gAudioPlayers[playerIdx].unk_14 = 0;
            }
        }

        if (gAudioPlayers[playerIdx].unk_28 != 0) {
            gAudioPlayers[playerIdx].unk_28--;
            if (gAudioPlayers[playerIdx].unk_28 != 0) {
                gAudioPlayers[playerIdx].tempo = gAudioPlayers[playerIdx].tempo - gAudioPlayers[playerIdx].unk_24;
            } else {
                gAudioPlayers[playerIdx].tempo = gAudioPlayers[playerIdx].unk_20;
            }
            // set tempo
            Audio_QueueCmdS32(SEQ_CMD_SET_TEMPO << 24 | _SHIFTL(playerIdx, 16, 8), gAudioPlayers[playerIdx].tempo);
        }

        if (gAudioPlayers[playerIdx].unk_252 != 0) {
            for (k = 0; k < 0x10; k++) {
                if (gAudioPlayers[playerIdx].unk_50[k].unk_0C != 0) {
                    gAudioPlayers[playerIdx].unk_50[k].unk_0C--;
                    if (gAudioPlayers[playerIdx].unk_50[k].unk_0C != 0) {
                        gAudioPlayers[playerIdx].unk_50[k].unk_00 -= gAudioPlayers[playerIdx].unk_50[k].unk_08;
                    } else {
                        gAudioPlayers[playerIdx].unk_50[k].unk_00 = gAudioPlayers[playerIdx].unk_50[k].unk_04;
                        gAudioPlayers[playerIdx].unk_252 ^= (1 << k);
                    }
                    // CHAN_UPD_VOL_SCALE (playerIdx = seq, k = chan)
                    Audio_QueueCmdF32(CHAN_UPD_VOL_SCALE << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(k, 8, 8),
                                      gAudioPlayers[playerIdx].unk_50[k].unk_00);
                }
            }
        }

        if (gAudioPlayers[playerIdx].unk_250 != 0) {
            for (k = 0; k < 0x10; k++) {
                if (gAudioPlayers[playerIdx].unk_50[k].unk_1C != 0) {
                    gAudioPlayers[playerIdx].unk_50[k].unk_1C--;
                    if (gAudioPlayers[playerIdx].unk_50[k].unk_1C != 0) {
                        gAudioPlayers[playerIdx].unk_50[k].unk_10 -= gAudioPlayers[playerIdx].unk_50[k].unk_18;
                    } else {
                        gAudioPlayers[playerIdx].unk_50[k].unk_10 = gAudioPlayers[playerIdx].unk_50[k].unk_14;
                        gAudioPlayers[playerIdx].unk_250 ^= (1 << k);
                    }
                    // CHAN_UPD_FREQ_SCALE
                    Audio_QueueCmdF32(CHAN_UPD_FREQ_SCALE << 24 | _SHIFTL(playerIdx, 16, 8) | _SHIFTL(k, 8, 8),
                                      gAudioPlayers[playerIdx].unk_50[k].unk_10);
                }
            }
        }

        if (gAudioPlayers[playerIdx].unk_4D != 0) {
            if (Audio_IsCommandNotIssued(0xF0000000, 0xF0000000) == 0) {
                gAudioPlayers[playerIdx].unk_4D = 0;
                return;
            }

            if (gAudioPlayers[playerIdx].unk_4C != 0) {
                gAudioPlayers[playerIdx].unk_4C--;
                continue;
            }

            if (gAudioContext.seqPlayers[playerIdx].enabled) {
                continue;
            }

            for (j = 0; j < gAudioPlayers[playerIdx].unk_4D; j++) {
                temp_a0 = (gAudioPlayers[playerIdx].unk_2C[j] & 0x00F00000) >> 20;
                temp_s1 = (gAudioPlayers[playerIdx].unk_2C[j] & 0x000F0000) >> 16;
                temp_s0_3 = (gAudioPlayers[playerIdx].unk_2C[j] & 0xFF00) >> 8;
                temp_a3_3 = gAudioPlayers[playerIdx].unk_2C[j] & 0xFF;

                switch (temp_a0) {
                    case 0:
                        Audio_SetVolScale(temp_s1, 1, 0x7F, temp_a3_3);
                        break;
                    case 7:
                        if (gAudioPlayerInfoNum[playerIdx] == temp_a3_3) {
                            Audio_SetVolScale(temp_s1, 1, 0x7F, temp_s0_3);
                        }
                        break;
                    case 1:
                        Audio_SeqCmd3(playerIdx, gAudioPlayers[playerIdx].seqAndFlags);
                        break;
                    case 2:
                        Audio_StartSeq(temp_s1, 1, gAudioPlayers[temp_s1].seqAndFlags);
                        gAudioPlayers[temp_s1].fadeVolUpdate = 1;
                        gAudioPlayers[temp_s1].volScales[1] = 0x7F;
                        break;
                    case 3:
                        Audio_SeqCmdB30(temp_s1, temp_s0_3, temp_a3_3);
                        break;
                    case 4:
                        Audio_SeqUpdateTempo2(temp_s1, temp_a3_3, 0);
                        break;
                    case 5:
                        temp_v1 = gAudioPlayers[playerIdx].unk_2C[j] & 0xFFFF;
                        Audio_StartSeq(temp_s1, gAudioPlayers[temp_s1].unk_4E, temp_v1);
                        Audio_SetVolScale(temp_s1, 1, 0x7F, 0);
                        gAudioPlayers[temp_s1].unk_4E = 0;
                        break;
                    case 6:
                        gAudioPlayers[playerIdx].unk_4E = temp_s0_3;
                        break;
                    case 8:
                        Audio_SetVolScale(temp_s1, temp_s0_3, 0x7F, temp_a3_3);
                        break;
                    case 14:
                        if (temp_a3_3 & 1) {
                            Audio_QueueCmdS32(CHAN_LOAD_POP_CACHE << 24, SEQUENCE_TABLE);
                        }
                        if (temp_a3_3 & 2) {
                            Audio_QueueCmdS32(CHAN_LOAD_POP_CACHE << 24, FONT_TABLE);
                        }
                        if (temp_a3_3 & 4) {
                            Audio_QueueCmdS32(CHAN_LOAD_POP_CACHE << 24, SAMPLE_TABLE);
                        }
                        break;
                    case 9:
                        temp_v1 = gAudioPlayers[playerIdx].unk_2C[j] & 0xFFFF;
                        Audio_SeqSetChannelStopMask(temp_s1, temp_v1);
                        break;
                    case 10:
                        Audio_SeqCmd5(temp_s1, temp_s0_3, (temp_a3_3 * 10) & 0xFFFF);
                        break;
                }
            }

            gAudioPlayers[playerIdx].unk_4D = 0;
        }
    }
}

u8 func_800FAD34(void) {
    if (D_80133418 != 0) {
        if (D_80133418 == 1) {
            if (func_800E5EDC() == 1) {
                D_80133418 = 0;
                Audio_QueueCmdS8(SEQ_CMD_UKN_46 << 24 | 0x00020000, gSfxChannelLayout);
                func_800F7170();
            }
        } else if (D_80133418 == 2) {
            while (func_800E5EDC() != 1) {}
            D_80133418 = 0;
            Audio_QueueCmdS8(SEQ_CMD_UKN_46 << 24 | 0x00020000, gSfxChannelLayout);
            func_800F7170();
        }
    }

    return D_80133418;
}

void Audio_ResetPlayers(void) {
    u8 playerIdx, j;

    for (playerIdx = 0; playerIdx < 4; playerIdx++) {
        gAudioPlayerInfoNum[playerIdx] = 0;
        gAudioPlayers[playerIdx].seqAndFlags = NA_BGM_DISABLED;
        gAudioPlayers[playerIdx].unk_256 = NA_BGM_DISABLED;
        gAudioPlayers[playerIdx].unk_28 = 0;
        gAudioPlayers[playerIdx].unk_18 = 0;
        gAudioPlayers[playerIdx].unk_14 = 0;
        gAudioPlayers[playerIdx].unk_258 = 0;
        gAudioPlayers[playerIdx].unk_4D = 0;
        gAudioPlayers[playerIdx].unk_4E = 0;
        gAudioPlayers[playerIdx].unk_250 = 0;
        gAudioPlayers[playerIdx].unk_252 = 0;
        for (j = 0; j < 4; j++) {
            gAudioPlayers[playerIdx].volScales[j] = 0x7F;
        }
        gAudioPlayers[playerIdx].volFadeTimer = 1;
        gAudioPlayers[playerIdx].fadeVolUpdate = 1;
    }
}

void Audio_ResetVolume(void) {
    u8 playerIdx, j;

    for (playerIdx = 0; playerIdx < 4; playerIdx++) {
        gAudioPlayers[playerIdx].volCur = 1.0f;
        gAudioPlayers[playerIdx].unk_0C = 0;
        gAudioPlayers[playerIdx].fadeVolUpdate = 0;
        for (j = 0; j < 4; j++) {
            gAudioPlayers[playerIdx].volScales[j] = 0x7F;
        }
    }
    Audio_ResetPlayers();
}

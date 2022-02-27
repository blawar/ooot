#pragma once

void Audio_ProcessSeqCmd(u32);
void Audio_ProcessSeqCmds(void);
void Audio_QueueSeqCmd(u32 bgmID);
void Audio_SetVolScale(u8 playerIdx, u8 scaleIdx, u8 targetVol, u8 volFadeTimer);
void Audio_PlaySequenceInternal(u8 playerIdx, u8 seqId, u8 arg2, u16 fadeTimer);
void Audio_SendDisableSequence(u8, u16);
u16 Audio_GetSequenceBeingPlayed(u8 a0);
s32 Audio_IsCommandNotIssued(u32 arg0, u32 arg1);
void func_800FA174(u8);
void func_800FA18C(u8, u8);
void func_800FA3DC(void);
u8 func_800FAD34(void);
void func_800FADF8(void);
void func_800FAEB4(void);

#pragma once
struct OSMesgQueue;

extern s32 gAudioContextInitalized;

void AudioLoad_AsyncLoadFont(s32 fontId, s32 arg1, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_AsyncLoadSampleBank(s32 sampleBankId, s32 arg1, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_AsyncLoadSeq(s32 seqId, s32 arg1, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_DecreaseSampleDmaTtls(void);
void AudioLoad_DiscardSeqFonts(s32 seqId);
void* AudioLoad_DmaSampleData(Pointer devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium);
u8* AudioLoad_GetFontsForSequence(s32 seqId, u32* arg1);
void AudioLoad_Init(void* heap, u32 heapSize);
void AudioLoad_InitAsyncLoads(void);
void AudioLoad_InitSampleDmaBuffers(s32 arg0);
void AudioLoad_InitScriptLoads(void);
void AudioLoad_InitSlowLoads(void);
s32 AudioLoad_IsFontLoadComplete(s32 fontId);
s32 AudioLoad_IsSeqLoadComplete(s32 seqId);
void AudioLoad_LoadPermanentSamples(void);
void AudioLoad_ProcessLoads(s32 resetStatus);
void AudioLoad_ProcessScriptLoads(void);
void AudioLoad_ScriptLoad(s32 tableType, s32 arg1, s8* arg2);
void AudioLoad_SetDmaHandler(DmaHandler callback);
void AudioLoad_SetFontLoadStatus(s32 fontId, s32 status);
void AudioLoad_SetSeqLoadStatus(s32 seqId, s32 status);
s32 AudioLoad_SlowLoadSample(s32 arg0, s32 arg1, s8* arg2);
s32 AudioLoad_SlowLoadSeq(s32 playerIdx, u8* ramAddr, s8* arg2);
s32 AudioLoad_SyncInitSeqPlayer(s32 playerIdx, s32 seqId, s32 arg2);
s32 AudioLoad_SyncInitSeqPlayerSkipTicks(s32 playerIdx, s32 seqId, s32 arg2);
s32 AudioLoad_SyncLoadInstrument(s32 fontId, s32 instId, s32 drumId);
void AudioLoad_SyncLoadSeqParts(s32 seqId, s32 arg1);

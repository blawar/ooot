#pragma once
struct AudioAllocPool;
struct AudioPersistentCache;
struct AudioTemporaryCache;

void* AudioHeap_Alloc(AudioAllocPool* pool, u32 size);
void* AudioHeap_AllocAttemptExternal(AudioAllocPool* pool, u32 size);
void* AudioHeap_AllocCached(s32 tableType, s32 size, s32 cache, s32 id);
void* AudioHeap_AllocDmaMemory(AudioAllocPool* pool, u32 size);
void* AudioHeap_AllocDmaMemoryZeroed(AudioAllocPool* pool, u32 size);
void* AudioHeap_AllocPermanent(s32 tableType, s32 id, u32 size);
void AudioHeap_AllocPoolInit(AudioAllocPool* pool, void* mem, u32 size);
void* AudioHeap_AllocSampleCache(u32 size, s32 fontId, void* sampleAddr, s8 medium, s32 cache);
void* AudioHeap_AllocZeroed(AudioAllocPool* pool, u32 size);
void* AudioHeap_AllocZeroedAttemptExternal(AudioAllocPool* pool, u32 size);
void AudioHeap_ApplySampleBankCache(s32 sampleBankId);
void AudioHeap_DiscardFont(s32 fontId);
void AudioHeap_DiscardSequence(s32 seqId);
void AudioHeap_Init(void);
void AudioHeap_InitMainPools(s32 sizeForAudioInitPool);
void AudioHeap_LoadFilter(s16* filter, s32 filter1, s32 filter2);
void AudioHeap_PersistentCacheClear(AudioPersistentCache* persistent);
void AudioHeap_PopCache(s32 tableType);
s32 AudioHeap_ResetStep(void);
void* AudioHeap_SearchCaches(s32 tableType, s32 arg1, s32 id);
void* AudioHeap_SearchPermanentCache(s32 tableType, s32 id);
void* AudioHeap_SearchRegularCaches(s32 tableType, s32 cache, s32 id);
void AudioHeap_TemporaryCacheClear(AudioTemporaryCache* temporary);
void AudioHeap_WritebackDCache(void* mem, u32 size);

#pragma once
#ifdef INTERNAL_SRC_CODE_CODE_800E6840_C
void Audio_InvalDCache(void* buf, s32 size);
void Audio_WritebackDCache(void* mem, s32 size);
#else
void Audio_InvalDCache(void* buf, s32 size);
void Audio_WritebackDCache(void* mem, s32 size);
#endif

#pragma once
#ifdef INTERNAL_SRC_CODE_GAMEALLOC_C
void GameAlloc_Cleanup(GameAlloc* this);
void GameAlloc_Free(GameAlloc* this, void* data);
void GameAlloc_Init(GameAlloc* this);
void* GameAlloc_Malloc(GameAlloc* this, u32 size);
void* GameAlloc_MallocDebug(GameAlloc* this, u32 size, const char* file, s32 line);
#else
void GameAlloc_Cleanup(struct GameAlloc* this);
void GameAlloc_Free(struct GameAlloc* this, void* data);
void GameAlloc_Init(struct GameAlloc* this);
void* GameAlloc_Malloc(struct GameAlloc* this, u32 size);
void* GameAlloc_MallocDebug(struct GameAlloc* this, u32 size, const char* file, s32 line);
#endif

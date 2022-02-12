#pragma once
struct GameAlloc;

void GameAlloc_Cleanup(GameAlloc* pthis);
void GameAlloc_Free(GameAlloc* pthis, void* data);
void GameAlloc_Init(GameAlloc* pthis);
void* GameAlloc_Malloc(GameAlloc* pthis, u32 size);
void* GameAlloc_MallocDebug(GameAlloc* pthis, u32 size, const char* file, s32 line);

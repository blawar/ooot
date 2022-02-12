#pragma once
struct Arena;

extern Arena gSystemArena;
extern s32 gSystemArenaLogSeverity;

void* SystemArena_Calloc(u32 num, u32 size);
void SystemArena_Check(void);
void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void SystemArena_Cleanup(void);
void SystemArena_Display(void);
void SystemArena_Free(void* ptr);
void SystemArena_FreeDebug(void* ptr, const char* file, s32 line);
void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void SystemArena_Init(void* start, u32 size);
u8 SystemArena_IsInitalized(void);
void* SystemArena_Malloc(u32 size);
void* SystemArena_MallocDebug(u32 size, const char* file, s32 line);
void* SystemArena_MallocR(u32 size);
void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line);
void* SystemArena_Realloc(void* ptr, u32 newSize);
void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);

#pragma once

void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* SystemArena_Malloc(u32 size);
void* SystemArena_MallocDebug(u32 size, const char* file, s32 line);
void* SystemArena_MallocR(u32 size);
void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line);
void* SystemArena_Realloc(void* ptr, u32 newSize);
void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void SystemArena_Free(void* ptr);
void SystemArena_FreeDebug(void* ptr, const char* file, s32 line);
void* SystemArena_Calloc(u32 num, u32 size);
void SystemArena_Display(void);
void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void SystemArena_Check(void);
void SystemArena_Init(void* start, u32 size);
void SystemArena_Cleanup(void);
u8 SystemArena_IsInitalized(void);

void* z_memset(void* ptr, s32 val, size_t size);

void oot_assert(const char* exp, const char* file, s32 line);

f32 LogUtils_CheckFloatRange(const char* exp, s32 line, const char* valueName, f32 value, const char* minName, f32 min,
                             const char* maxName, f32 max);
s32 LogUtils_CheckIntRange(const char* exp, s32 line, const char* valueName, s32 value, const char* minName, s32 min,
                           const char* maxName, s32 max);
void LogUtils_LogHexDump(void* ptr, s32 size0);
void LogUtils_LogPointer(s32 value, u32 max, void* ptr, const char* name, const char* file, s32 line);
void LogUtils_CheckBoundary(const char* name, s32 value, s32 unk, const char* file, s32 line);
void LogUtils_CheckNullPointer(const char* exp, void* ptr, const char* file, s32 line);
void LogUtils_CheckValidPointer(const char* exp, void* ptr, const char* file, s32 line);
void LogUtils_LogThreadId(const char* name, s32 line);
void LogUtils_HungupThread(const char* name, s32 line);
void LogUtils_ResetHungup(void);


void GameState_FaultPrint(void);
void GameState_SetFBFilter(Gfx** gfx);
// ? func_800C4344(?);
void GameState_DrawInputDisplay(u16 input, Gfx** gfx);
void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx);
void GameState_SetFrameBuffer(GraphicsContext* gfxCtx);
// ? func_800C49F4(?);
void GameState_ReqPadData(GameState* gameState);
void GameState_Update(GameState* gameState);
void GameState_InitArena(GameState* gameState, size_t size);
void GameState_Realloc(GameState* gameState, size_t size);
void GameState_Init(GameState* gameState, GameStateFunc init, GraphicsContext* gfxCtx);
void GameState_Destroy(GameState* gameState);
GameStateFunc GameState_GetInit(GameState* gameState);
u32 GameState_IsRunning(GameState* gameState);
void* GameState_Alloc(GameState* gameState, size_t size, char* file, s32 line);
void func_800C55D0(GameAlloc* thiss);
void* GameAlloc_MallocDebug(GameAlloc* thiss, u32 size, const char* file, s32 line);
void* GameAlloc_Malloc(GameAlloc* thiss, u32 size);
void GameAlloc_Free(GameAlloc* thiss, void* data);
void GameAlloc_Cleanup(GameAlloc* thiss);
void GameAlloc_Init(GameAlloc* thiss);


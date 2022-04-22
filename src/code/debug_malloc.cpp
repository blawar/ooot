#define INTERNAL_SRC_CODE_DEBUG_MALLOC_C
#include "global.h"
#include "def/__osMalloc.h"
#include "def/debug_malloc.h"
#include <stdlib.h>
#include <string.h>

#define LOG_SEVERITY_NOLOG 0
#define LOG_SEVERITY_ERROR 2
#define LOG_SEVERITY_VERBOSE 3

s32 gDebugArenaLogSeverity = LOG_SEVERITY_ERROR;

void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
}

void* DebugArena_Malloc(u32 size) {
    return malloc(size);
}

void* DebugArena_MallocDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* DebugArena_MallocR(u32 size) {
    return malloc(size);
}

void* DebugArena_MallocRDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* DebugArena_Realloc(void* ptr, u32 newSize) {
    return realloc(ptr, newSize);
}

void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
    return realloc(ptr, newSize);
}

void DebugArena_Free(void* ptr) {
    free(ptr);
}

void DebugArena_FreeDebug(void* ptr, const char* file, s32 line) {
    free(ptr);
}

void* DebugArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

    ret = malloc(n);
    if (ret != NULL) {
        memset(ret, 0, n);
    }
    return ret;
}

void DebugArena_Display(void) {
}

void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
}

void DebugArena_Check(void) {
}

void DebugArena_Init(void* start, u32 size) {
}

void DebugArena_Cleanup(void) {
}

u8 DebugArena_IsInitalized(void) {
    return 0;
}

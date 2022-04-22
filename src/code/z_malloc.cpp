#define INTERNAL_SRC_CODE_Z_MALLOC_C
#include "global.h"
#include <string.h>
#include "def/__osMalloc.h"
#include "def/z_malloc.h"
#include <stdlib.h>

#define LOG_SEVERITY_NOLOG 0
#define LOG_SEVERITY_ERROR 2
#define LOG_SEVERITY_VERBOSE 3

s32 gZeldaArenaLogSeverity = LOG_SEVERITY_ERROR;

void ZeldaArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
}

void* ZeldaArena_Malloc(u32 size) {
    return malloc(size);
}

void* ZeldaArena_MallocDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* ZeldaArena_MallocR(u32 size) {
    return malloc(size);
}

void* ZeldaArena_MallocRDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* ZeldaArena_Realloc(void* ptr, u32 newSize) {
    return realloc(ptr, newSize);
}

void* ZeldaArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
    return realloc(ptr, newSize);
}

void ZeldaArena_Free(void* ptr) {
    return free(ptr);
}

void ZeldaArena_FreeDebug(void* ptr, const char* file, s32 line) {
    if((uintptr_t)ptr == 1)
    {
        return;
    }
    free(ptr);
}

void* ZeldaArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

    ret = malloc(n);

    if (ret != NULL) {
	    memset(ret, 0, n);
    }

    ZeldaArena_CheckPointer(ret, n, "zelda_calloc", "確保");
    return ret;
}

void ZeldaArena_Display() {
}

void ZeldaArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
}

void ZeldaArena_Check() {
}

void ZeldaArena_Init(void* start, u32 size) {
    return;
}

void ZeldaArena_Cleanup() {
}

u8 ZeldaArena_IsInitalized() {
    return 0;
}

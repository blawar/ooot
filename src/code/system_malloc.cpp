#define INTERNAL_SRC_CODE_SYSTEM_MALLOC_C
#include "global.h"
#include <stdlib.h>
#include <string.h>
#include "def/__osMalloc.h"
#include "def/system_malloc.h"

#define LOG_SEVERITY_NOLOG 0
#define LOG_SEVERITY_ERROR 2
#define LOG_SEVERITY_VERBOSE 3

s32 gSystemArenaLogSeverity = LOG_SEVERITY_NOLOG;


void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
}

void* SystemArena_Malloc(u32 size) {
    return malloc(size);
}

void* SystemArena_MallocDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* SystemArena_MallocR(u32 size) {
    return malloc(size);
}

void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line) {
    return malloc(size);
}

void* SystemArena_Realloc(void* ptr, u32 newSize) {
    return realloc(ptr, newSize);
}

void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
    return realloc(ptr, newSize);
}

void SystemArena_Free(void* ptr) {
    free(ptr);
}

void SystemArena_FreeDebug(void* ptr, const char* file, s32 line) {
    free(ptr);
}

void* SystemArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

    ret = malloc(n);

    if (ret != NULL) {
        memset(ret, 0, n);
    }

    SystemArena_CheckPointer(ret, n, "calloc", "Secure");
    return ret;
}

void SystemArena_Display(void) {
}

void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
}

void SystemArena_Check(void) {
}

void SystemArena_Init(void* start, u32 size) {
    return;
}

void SystemArena_Cleanup(void) {
}

u8 SystemArena_IsInitalized(void) {
    return 1;
}

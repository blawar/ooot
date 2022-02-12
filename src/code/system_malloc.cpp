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

#ifndef USE_NATIVE_MALLOC
Arena gSystemArena;
#endif

void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
#ifndef USE_NATIVE_MALLOC
    if (ptr == NULL) {
        if (gSystemArenaLogSeverity >= LOG_SEVERITY_ERROR) {
            // "%s: %u bytes %s failed\n"
            osSyncPrintf("%s: %u bytes %s failed\n", name, size, action);
            __osDisplayArena(&gSystemArena);
            return;
        }
    } else if (gSystemArenaLogSeverity >= LOG_SEVERITY_VERBOSE) {
        // "%s: %u bytes %s succeeded\n"
        osSyncPrintf("%s: %u bytes %s succeeded\n", name, size, action);
    }
#endif
}

void* SystemArena_Malloc(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMalloc(&gSystemArena, size);

    SystemArena_CheckPointer(ptr, size, "malloc", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* SystemArena_MallocDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocDebug(&gSystemArena, size, file, line);

    SystemArena_CheckPointer(ptr, size, "malloc_DEBUG", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* SystemArena_MallocR(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocR(&gSystemArena, size);

    SystemArena_CheckPointer(ptr, size, "malloc_r", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocRDebug(&gSystemArena, size, file, line);

    SystemArena_CheckPointer(ptr, size, "malloc_r_DEBUG", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* SystemArena_Realloc(void* ptr, u32 newSize) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osRealloc(&gSystemArena, ptr, newSize);
    SystemArena_CheckPointer(ptr, newSize, "realloc", "Re-securing"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osReallocDebug(&gSystemArena, ptr, newSize, file, line);
    SystemArena_CheckPointer(ptr, newSize, "realloc_DEBUG", "Re-securing"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void SystemArena_Free(void* ptr) {
#ifndef USE_NATIVE_MALLOC
    __osFree(&gSystemArena, ptr);
#else
    free(ptr);
#endif
}

void SystemArena_FreeDebug(void* ptr, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    __osFreeDebug(&gSystemArena, ptr, file, line);
#else
    free(ptr);
#endif
}

void* SystemArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

#ifndef USE_NATIVE_MALLOC
    ret = __osMalloc(&gSystemArena, n);
#else
    ret = malloc(n);
#endif

    if (ret != NULL) {
        bzero(ret, n);
    }

    SystemArena_CheckPointer(ret, n, "calloc", "Secure");
    return ret;
}

void SystemArena_Display(void) {
#ifndef USE_NATIVE_MALLOC
    osSyncPrintf("システムヒープ表示\n"); // "System heap display"
    __osDisplayArena(&gSystemArena);
#endif
}

void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
#ifndef USE_NATIVE_MALLOC
    ArenaImpl_GetSizes(&gSystemArena, outMaxFree, outFree, outAlloc);
#else
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
#endif
}

void SystemArena_Check(void) {
#ifndef USE_NATIVE_MALLOC
    __osCheckArena(&gSystemArena);
#endif
}

void SystemArena_Init(void* start, u32 size) {
#ifndef USE_NATIVE_MALLOC
    gSystemArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocInit(&gSystemArena, start, size);
#else
    return;
#endif
}

void SystemArena_Cleanup(void) {
#ifndef USE_NATIVE_MALLOC
    gSystemArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocCleanup(&gSystemArena);
#endif
}

u8 SystemArena_IsInitalized(void) {
#ifndef USE_NATIVE_MALLOC
    return __osMallocIsInitalized(&gSystemArena);
#else
    return 1;
#endif
}

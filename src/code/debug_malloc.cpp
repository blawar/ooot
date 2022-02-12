#define INTERNAL_SRC_CODE_DEBUG_MALLOC_C
#include "global.h"
#include "def/__osMalloc.h"
#include "def/debug_malloc.h"
#include <stdlib.h>

#define LOG_SEVERITY_NOLOG 0
#define LOG_SEVERITY_ERROR 2
#define LOG_SEVERITY_VERBOSE 3

s32 gDebugArenaLogSeverity = LOG_SEVERITY_ERROR;
#ifndef USE_NATIVE_MALLOC
Arena sDebugArena;
#endif

void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
#ifndef USE_NATIVE_MALLOC
    if (ptr == NULL) {
        if (gDebugArenaLogSeverity >= LOG_SEVERITY_ERROR) {
            // "%s: %u bytes %s failed\n"
            osSyncPrintf("%s: %u bytes %s failed\n", name, size, action);
            __osDisplayArena(&sDebugArena);
            return;
        }
    } else if (gDebugArenaLogSeverity >= LOG_SEVERITY_VERBOSE) {
        // "%s: %u bytes %s succeeded\n"
        osSyncPrintf("%s: %u bytes %s succeeded\n", name, size, action);
    }
#endif
}

void* DebugArena_Malloc(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMalloc(&sDebugArena, size);

    DebugArena_CheckPointer(ptr, size, "debug_malloc", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* DebugArena_MallocDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocDebug(&sDebugArena, size, file, line);

    DebugArena_CheckPointer(ptr, size, "debug_malloc_DEBUG", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* DebugArena_MallocR(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocR(&sDebugArena, size);

    DebugArena_CheckPointer(ptr, size, "debug_malloc_r", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* DebugArena_MallocRDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocRDebug(&sDebugArena, size, file, line);

    DebugArena_CheckPointer(ptr, size, "debug_malloc_r_DEBUG", "Secure"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* DebugArena_Realloc(void* ptr, u32 newSize) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osRealloc(&sDebugArena, ptr, newSize);
    DebugArena_CheckPointer(ptr, newSize, "debug_realloc", "Re-securing"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osReallocDebug(&sDebugArena, ptr, newSize, file, line);
    DebugArena_CheckPointer(ptr, newSize, "debug_realloc_DEBUG", "Re-securing"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void DebugArena_Free(void* ptr) {
#ifndef USE_NATIVE_MALLOC
    __osFree(&sDebugArena, ptr);
#else
    free(ptr);
#endif
}

void DebugArena_FreeDebug(void* ptr, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    __osFreeDebug(&sDebugArena, ptr, file, line);
#else
    free(ptr);
#endif
}

void* DebugArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

#ifndef USE_NATIVE_MALLOC
    ret = __osMalloc(&sDebugArena, n);
    
    DebugArena_CheckPointer(ret, n, "debug_calloc", "Secure");
#else
    ret = malloc(n);
#endif
    if (ret != NULL) {
        bzero(ret, n);
    }
    return ret;
}

void DebugArena_Display(void) {
#ifndef USE_NATIVE_MALLOC
    // "Zelda heap display" ("Zelda" should probably have been changed to "Debug")
    osSyncPrintf("Debug heap display\n");
    __osDisplayArena(&sDebugArena);
#endif
}

void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
#ifndef USE_NATIVE_MALLOC
    ArenaImpl_GetSizes(&sDebugArena, outMaxFree, outFree, outAlloc);
#else
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
#endif
}

void DebugArena_Check(void) {
#ifndef USE_NATIVE_MALLOC
    __osCheckArena(&sDebugArena);
#endif
}

void DebugArena_Init(void* start, u32 size) {
#ifndef USE_NATIVE_MALLOC
    gDebugArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocInit(&sDebugArena, start, size);
#endif
}

void DebugArena_Cleanup(void) {
#ifndef USE_NATIVE_MALLOC
    gDebugArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocCleanup(&sDebugArena);
#endif
}

u8 DebugArena_IsInitalized(void) {
#ifndef USE_NATIVE_MALLOC
    return __osMallocIsInitalized(&sDebugArena);
#else
    return 0;
#endif
}

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
#ifndef USE_NATIVE_MALLOC
Arena sZeldaArena;
#endif

void ZeldaArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
#ifndef USE_NATIVE_MALLOC
    if (ptr == NULL) {
        if (gZeldaArenaLogSeverity >= LOG_SEVERITY_ERROR) {
            // "%s: %u bytes %s failed\n"
            osSyncPrintf("%s: %u バイトの%sに失敗しました\n", name, size, action);
            __osDisplayArena(&sZeldaArena);
        }
    } else if (gZeldaArenaLogSeverity >= LOG_SEVERITY_VERBOSE) {
        // "%s: %u bytes %s succeeded\n"
        osSyncPrintf("%s: %u バイトの%sに成功しました\n", name, size, action);
    }
#endif
}

void* ZeldaArena_Malloc(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMalloc(&sZeldaArena, size);

    ZeldaArena_CheckPointer(ptr, size, "zelda_malloc", "確保"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* ZeldaArena_MallocDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocDebug(&sZeldaArena, size, file, line);

    ZeldaArena_CheckPointer(ptr, size, "zelda_malloc_DEBUG", "確保"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* ZeldaArena_MallocR(u32 size) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocR(&sZeldaArena, size);

    ZeldaArena_CheckPointer(ptr, size, "zelda_malloc_r", "確保"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* ZeldaArena_MallocRDebug(u32 size, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    void* ptr = __osMallocRDebug(&sZeldaArena, size, file, line);

    ZeldaArena_CheckPointer(ptr, size, "zelda_malloc_r_DEBUG", "確保"); // "Secure"
    return ptr;
#else
    return malloc(size);
#endif
}

void* ZeldaArena_Realloc(void* ptr, u32 newSize) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osRealloc(&sZeldaArena, ptr, newSize);
    ZeldaArena_CheckPointer(ptr, newSize, "zelda_realloc", "再確保"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void* ZeldaArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    ptr = __osReallocDebug(&sZeldaArena, ptr, newSize, file, line);
    ZeldaArena_CheckPointer(ptr, newSize, "zelda_realloc_DEBUG", "再確保"); // "Re-securing"
    return ptr;
#else
    return realloc(ptr, newSize);
#endif
}

void ZeldaArena_Free(void* ptr) {
#ifndef USE_NATIVE_MALLOC
    __osFree(&sZeldaArena, ptr);
#else
    return free(ptr);
#endif
}

void ZeldaArena_FreeDebug(void* ptr, const char* file, s32 line) {
#ifndef USE_NATIVE_MALLOC
    __osFreeDebug(&sZeldaArena, ptr, file, line);
#else
    if((uintptr_t)ptr == 1)
    {
        return;
    }
    free(ptr);
#endif
}

void* ZeldaArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

#ifndef USE_NATIVE_MALLOC
    ret = __osMalloc(&sZeldaArena, n);
#else
    ret = malloc(n);
#endif

    if (ret != NULL) {
        bzero(ret, n);
    }

    ZeldaArena_CheckPointer(ret, n, "zelda_calloc", "確保");
    return ret;
}

void ZeldaArena_Display() {
#ifndef USE_NATIVE_MALLOC
    osSyncPrintf("ゼルダヒープ表示\n"); // "Zelda heap display"
    __osDisplayArena(&sZeldaArena);
#endif
}

void ZeldaArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
#ifndef USE_NATIVE_MALLOC
    ArenaImpl_GetSizes(&sZeldaArena, outMaxFree, outFree, outAlloc);
#else
    *outFree = (u32)-1;
    *outMaxFree = (u32)-1;
    *outAlloc = 0;
#endif
}

void ZeldaArena_Check() {
#ifndef USE_NATIVE_MALLOC
    __osCheckArena(&sZeldaArena);
#endif
}

void ZeldaArena_Init(void* start, u32 size) {
#ifndef USE_NATIVE_MALLOC
    gZeldaArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocInit(&sZeldaArena, start, size);
#else
    return;
#endif
}

void ZeldaArena_Cleanup() {
#ifndef USE_NATIVE_MALLOC
    gZeldaArenaLogSeverity = LOG_SEVERITY_NOLOG;
    __osMallocCleanup(&sZeldaArena);
#endif
}

u8 ZeldaArena_IsInitalized() {
#ifndef USE_NATIVE_MALLOC
    return __osMallocIsInitalized(&sZeldaArena);
#else
    return 0;
#endif
}

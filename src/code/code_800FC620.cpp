#define INTERNAL_SRC_CODE_CODE_800FC620_C
#include "global.h"
#include "z64scene.h"
#include "def/__osMalloc.h"
#include "def/code_800FC620.h"
#include "def/system_malloc.h"

typedef void (*arg3_800FC868)(void*);
typedef void (*arg3_800FC8D8)(void*, u32);
typedef void (*arg3_800FC948)(void*, u32, u32, u32, u32, u32, u32, u32, u32);
typedef void (*arg3_800FCA18)(void*, u32);

typedef struct InitFunc {
    s32 nextOffset;
    void (*func)(void);
} InitFunc;

// .data
void* sInitFuncs = NULL;

char sNew[] = { 'n', 'e', 'w' };

char D_80134488[0x18] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00,
    0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
};

s32 Overlay_Load(Pointer vRomStart, Pointer vRomEnd, Pointer vRamStart, Pointer vRamEnd, Pointer allocatedVRamAddr)
{
    return 0;
}

// possibly some kind of new() function
void* func_800FC800(u32 size) {
    if (size == 0) {
        size = 1;
    }
#ifndef USE_NATIVE_MALLOC
    return __osMallocDebug(&gSystemArena, size, sNew, 0);
#else
    return malloc(size);
#endif
}

// possible some kind of delete() function
void func_800FC83C(void* ptr) {
    if (ptr != NULL) {
#ifndef USE_NATIVE_MALLOC
        __osFree(&gSystemArena, ptr);
#else
        free(ptr);
#endif
    }
}

void func_800FC868(void* blk, u32 nBlk, u32 blkSize, arg3_800FC868 arg3) {
    uintptr_t pos;

    for (pos = (uintptr_t)blk; pos < (uintptr_t)blk + (nBlk * blkSize); pos = (uintptr_t)pos + (blkSize & ~0)) {
        arg3((void*)pos);
    }
}

void func_800FC8D8(void* blk, u32 nBlk, s32 blkSize, arg3_800FC8D8 arg3) {
    uintptr_t pos;

    for (pos = (uintptr_t)blk; pos < (uintptr_t)blk + (nBlk * blkSize); pos = (uintptr_t)pos + (blkSize & ~0)) {
        arg3((void*)pos, 2);
    }
}

void* func_800FC948(void* blk, u32 nBlk, u32 blkSize, arg3_800FC948 arg3) {
    uintptr_t pos;

    if (blk == NULL) {
        blk = func_800FC800(nBlk * blkSize);
    }

    if (blk != NULL && arg3 != NULL) {
        pos = (uintptr_t)blk;
        while (pos < (uintptr_t)blk + (nBlk * blkSize)) {
            arg3((void*)pos, 0, 0, 0, 0, 0, 0, 0, 0);
            pos = (uintptr_t)pos + (blkSize & ~0);
        }
    }
    return blk;
}

void func_800FCA18(void* blk, u32 nBlk, u32 blkSize, arg3_800FCA18 arg3, s32 arg4) {
    uintptr_t pos;
    uintptr_t end;
    s32 masked_arg2;

    if (blk == 0) {
        return;
    }
    if (arg3 != 0) {
        end = (uintptr_t)blk;
        masked_arg2 = (s32)(blkSize & ~0);
        pos = (uintptr_t)end + (nBlk * blkSize);

        while (pos > end) {
            pos -= masked_arg2;
            arg3((void*)pos, 2);
            if (1) {}
        }
    }

    if (arg4 != 0) {
        func_800FC83C(blk);
    }
}

void func_800FCB34(void) {
    InitFunc* initFunc = (InitFunc*)&sInitFuncs;
    u32 nextOffset = initFunc->nextOffset;
    InitFunc* prev = NULL;

    while (nextOffset != 0) {
        initFunc = (InitFunc*)((u8*)initFunc + nextOffset);

        if (initFunc->func != NULL) {
            (*initFunc->func)();
        }

        nextOffset = initFunc->nextOffset;
        initFunc->nextOffset = (s32)prev;
        prev = initFunc;
    }

    sInitFuncs = prev;
}

void SystemHeap_Init(void* start, u32 size) {
#ifndef USE_NATIVE_MALLOC
    SystemArena_Init(start, size);
#endif
    func_800FCB34();
}

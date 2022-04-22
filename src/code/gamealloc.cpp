#define INTERNAL_SRC_CODE_GAMEALLOC_C
#include "global.h"
#include "z64game.h"
#include "def/gamealloc.h"
#include "def/logutils.h"
#include "def/system_malloc.h"

void GameAlloc_Log(GameAlloc* pthis) {
    GameAllocEntry* iter;

    osSyncPrintf("pthis = %08x\n", pthis);

    iter = pthis->base.next;
    while (iter != &pthis->base) {
        osSyncPrintf("ptr = %08x size = %d\n", iter, iter->size);
        iter = iter->next;
    }
}

void* GameAlloc_MallocDebug(GameAlloc* pthis, u32 size, const char* file, s32 line) {
    GameAllocEntry* ptr = (GameAllocEntry*)SystemArena_MallocDebug(size + sizeof(GameAllocEntry), file, line);

    if (ptr != NULL) {
        ptr->size = size;
        ptr->prev = pthis->head;
        pthis->head->next = ptr;
        pthis->head = ptr;
        ptr->next = &pthis->base;
        pthis->base.prev = pthis->head;
        return ptr + 1;
    } else {
        return NULL;
    }
}

void* GameAlloc_Malloc(GameAlloc* pthis, u32 size) {
    GameAllocEntry* ptr = (GameAllocEntry*)SystemArena_MallocDebug(size + sizeof(GameAllocEntry), "../gamealloc.c", 93);

    if (ptr != NULL) {
        ptr->size = size;
        ptr->prev = pthis->head;
        pthis->head->next = ptr;
        pthis->head = ptr;
        ptr->next = &pthis->base;
        pthis->base.prev = pthis->head;
        return ptr + 1;
    } else {
        return NULL;
    }
}

void GameAlloc_Free(GameAlloc* pthis, void* data) {
    GameAllocEntry* ptr;

    if (data != NULL) {
        ptr = &((GameAllocEntry*)data)[-1];
        LogUtils_CheckNullPointer("ptr->prev", ptr->prev, "../gamealloc.c", 120);
        LogUtils_CheckNullPointer("ptr->next", ptr->next, "../gamealloc.c", 121);
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        pthis->head = pthis->base.prev;
        SystemArena_FreeDebug(ptr, "../gamealloc.c", 125);
    }
}

void GameAlloc_Cleanup(GameAlloc* pthis) {
    GameAllocEntry* next = pthis->base.next;
    GameAllocEntry* cur;

    while (&pthis->base != next) {
        cur = next;
        next = next->next;
        SystemArena_FreeDebug(cur, "../gamealloc.c", 145);
    }

    pthis->head = &pthis->base;
    pthis->base.next = &pthis->base;
    pthis->base.prev = &pthis->base;
}

void GameAlloc_Init(GameAlloc* pthis) {
    pthis->head = &pthis->base;
    pthis->base.next = &pthis->base;
    pthis->base.prev = &pthis->base;
}

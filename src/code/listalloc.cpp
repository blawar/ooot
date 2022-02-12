#define INTERNAL_SRC_CODE_LISTALLOC_C
#include "global.h"
#include "listalloc.h"
#include "def/listalloc.h"
#include "def/system_malloc.h"

ListAlloc* ListAlloc_Init(ListAlloc* pthis) {
    pthis->prev = NULL;
    pthis->next = NULL;
    return pthis;
}

void* ListAlloc_Alloc(ListAlloc* pthis, u32 size) {
    ListAlloc* ptr = (ListAlloc*)SystemArena_MallocDebug(size + sizeof(ListAlloc), "../listalloc.c", 40);
    ListAlloc* next;

    if (ptr == NULL) {
        return NULL;
    }

    next = pthis->next;
    if (next != NULL) {
        next->next = ptr;
    }

    ptr->prev = next;
    ptr->next = NULL;
    pthis->next = ptr;

    if (pthis->prev == NULL) {
        pthis->prev = ptr;
    }

    return (u8*)ptr + sizeof(ListAlloc);
}

void ListAlloc_Free(ListAlloc* pthis, void* data) {
    ListAlloc* ptr = &((ListAlloc*)data)[-1];

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    if (pthis->prev == ptr) {
        pthis->prev = ptr->next;
    }

    if (pthis->next == ptr) {
        pthis->next = ptr->prev;
    }

    SystemArena_FreeDebug(ptr, "../listalloc.c", 72);
}

void ListAlloc_FreeAll(ListAlloc* pthis) {
    ListAlloc* iter = pthis->prev;

    while (iter != NULL) {
        ListAlloc_Free(pthis, (u8*)iter + sizeof(ListAlloc));
        iter = pthis->prev;
    }
}

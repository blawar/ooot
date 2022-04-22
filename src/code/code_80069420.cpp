#define INTERNAL_SRC_CODE_CODE_80069420_C
#include "global.h"
#include "def/code_80069420.h"

void* MemCopy(void* dest, void* src, s32 size) {
    u8* destu = (u8*)dest;
    u8* srcu = (u8*)src;

    while (size > 0) {
        *destu++ = *srcu++;
        size--;
    }

    return dest;
}

void* MemSet(void* dest, s32 val, s32 size) {
    u8* destu = (u8*)dest;
    s32 s = size;

    while (s > 0) {
        *destu++ = val;
        s--;
    }

    return dest;
}

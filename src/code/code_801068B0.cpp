#define INTERNAL_SRC_CODE_CODE_801068B0_C
#include "global.h"
#include "def/code_801068B0.h"

// memmove used in __osMalloc.c
void* func_801068B0(void* dst, void* src, size_t size) {
    u8* spC = (u8*)dst;
	u8* sp8 = (u8*)src;
    register s32 a3;

    if (spC == sp8) {
        return dst;
    }
    if (spC < sp8) {
        for (a3 = size--; a3 != 0; a3 = size--) {
            *spC++ = *sp8++;
        }
    } else {
        spC += size - 1;
        sp8 += size - 1;
        for (a3 = size--; a3 != 0; a3 = size--) {
            *spC-- = *sp8--;
        }
    }
    return dst;
}

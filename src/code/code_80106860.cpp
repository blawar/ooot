#define INTERNAL_SRC_CODE_CODE_80106860_C
#include "global.h"
#include "def/code_80106860.h"

// memset used in __osMalloc, z_quake, z_view, and z_camera
void* z_memset(void* ptr, s32 val, size_t size) {
    u8* sp4 = (u8*)ptr;
    register s32 a3;

    for (a3 = size--; a3 != 0; a3 = size--) {
        *sp4++ = val;
    }
    return ptr;
}

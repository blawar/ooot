#define INTERNAL_SRC_LIBULTRA_IO_VIEXTEND_C
#include "global.h"
#include "def/viextend.h"

extern u32 __additional_scanline;

void osViExtendVStart(u32 arg0) {
    __additional_scanline = arg0;
}
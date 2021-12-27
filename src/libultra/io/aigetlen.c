#define INTERNAL_SRC_LIBULTRA_IO_AIGETLEN_C
#include "global.h"
#include "regs.h"
#include "ultra64/rcp.h"
#include "def/aigetlen.h"

u32 osAiGetLength(void) {
    return HW_REG(AI_LEN_REG, u32);
}

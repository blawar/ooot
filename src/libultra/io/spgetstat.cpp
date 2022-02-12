#define INTERNAL_SRC_LIBULTRA_IO_SPGETSTAT_C
#include "global.h"
#include "ultra64/rcp.h"
#include "def/spgetstat.h"

u32 __osSpGetStatus(void) {
    return HW_REG(SP_STATUS_REG, u32);
}

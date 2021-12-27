#define INTERNAL_SRC_LIBULTRA_IO_SPSETSTAT_C
#include "global.h"
#include "ultra64/rcp.h"
#include "def/spsetstat.h"

void __osSpSetStatus(u32 status) {
    HW_REG(SP_STATUS_REG, u32) = status;
}

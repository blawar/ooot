#define INTERNAL_SRC_LIBULTRA_GU_COSS_C
#include "global.h"
#include "def/coss.h"
#include "def/sins.h"

s16 coss(u16 angle) {
    return sins(angle + 0x4000);
}

#define INTERNAL_SRC_LIBULTRA_IO_VIBLACK_C
#include "global.h"
#include "def/vi.h"
#include "def/viblack.h"

// TODO: name magic constants
void osViBlack(u8 active) {
    register u32 prevInt = __osDisableInt();

    if (active) {
        __osViNext->state |= 0x20;
    } else {
        __osViNext->state &= ~0x20;
    }
    __osRestoreInt(prevInt);
}

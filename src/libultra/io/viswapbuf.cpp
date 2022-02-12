#define INTERNAL_SRC_LIBULTRA_IO_VISWAPBUF_C
#include "global.h"
#include "def/vi.h"
#include "def/viswapbuf.h"

void osViSwapBuffer(void* vaddr) {
    u32 prevInt = __osDisableInt();

    __osViNext->buffer = vaddr;
    __osViNext->state |= 0x10; // TODO: figure out what this flag means

    __osRestoreInt(prevInt);
}

#define INTERNAL_SRC_LIBULTRA_IO_VISETYSCALE_C
#include "global.h"
#include "def/visetyscale.h"
#include "ultra64/vi.h"

extern OSViContext* __osViNext;

void osViSetYScale(f32 scale) {
    //register u32 prevInt = __osDisableInt();

    __osViNext->y.factor = scale;
    __osViNext->state |= 4;

    //__osRestoreInt(prevInt);
}
#define INTERNAL_SRC_LIBULTRA_IO_VISETXSCALE_C
#include "global.h"
#include "def/visetxscale.h"
#include "ultra64/vi.h"

extern OSViContext* __osViNext;

void osViSetXScale(f32 value) {
    register u32 nomValue;
    //register u32 prevInt = __osDisableInt();

    __osViNext->x.factor = value;
    __osViNext->state |= 0x2;

    nomValue = __osViNext->modep->comRegs.xScale & 0xFFF;
    __osViNext->x.scale = (u32)(__osViNext->x.factor * nomValue) & 0xFFF;

    //__osRestoreInt(prevInt);
}

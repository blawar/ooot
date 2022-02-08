#define INTERNAL_SRC_LIBULTRA_IO_VI_C
#include "global.h"
#include "ultra64/vi.h"
#include "regs.h"
#include "ultra64/rcp.h"
#include "def/vi.h"
#include "def/vimodempallan1.h"
#include "def/vimodentsclan1.h"
#include "def/vimodepallan1.h"
#include "def/viswapcontext.h"

extern u32 osTvType;
extern OSViMode osViModePalLan1;
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeFpalLan1;

OSViContext vi[2] = { 0 };
OSViContext* __osViCurr = &vi[0];
OSViContext* __osViNext = &vi[1];

void __osViInit(void) {
    bzero(vi, sizeof(vi));
    __osViCurr = &vi[0];
    __osViNext = &vi[1];

    __osViNext->retraceCount = 1;
    __osViCurr->retraceCount = 1;
    __osViNext->buffer = (void*)0x80000000;
    __osViCurr->buffer = (void*)0x80000000;

    if (osTvType == OS_TV_PAL) {
        __osViNext->modep = &osViModePalLan1;
    } else if (osTvType == OS_TV_MPAL) {
        __osViNext->modep = &osViModeMpalLan1;
    } else {
        __osViNext->modep = &osViModeNtscLan1;
    }

    __osViNext->state = 0x20;
    __osViNext->features = __osViNext->modep->comRegs.ctrl;


    HW_REG(VI_CONTROL_REG, u32) = 0;
    __osViSwapContext();
}

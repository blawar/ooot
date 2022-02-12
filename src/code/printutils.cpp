#define INTERNAL_SRC_CODE_PRINTUTILS_C
#include "global.h"
#include "ultra64/printf.h"
#include "def/printutils.h"
#include "def/xprintf.h"

s32 PrintUtils_VPrintf(PrintCallback* pfn, const char* fmt, va_list args) {
    return _Printf(*pfn, pfn, fmt, args);
}

s32 PrintUtils_Printf(PrintCallback* pfn, const char* fmt, ...) {
    s32 ret;
    va_list args = 0;
    va_start(args, fmt);

    ret = PrintUtils_VPrintf(pfn, fmt, args);

    va_end(args);

    return ret;
}

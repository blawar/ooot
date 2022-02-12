#define INTERNAL_SRC_LIBULTRA_RMON_SPRINTF_C
#include "global.h"
#include <string.h>

void* proutSprintf(void* dst, const char* fmt, u32 size) {
    return (void*)((uintptr_t)memcpy(dst, fmt, size) + size);
}

/*s32 vsprintf(char* dst, const char* fmt, va_list args) {
    s32 ret = _Printf(proutSprintf, dst, fmt, args);
    if (ret > -1) {
        dst[ret] = '\0';
    }
    return ret;
}*/

/*s32 sprintf(char* dst, const char* fmt, ...) {
    s32 ret;
    va_list args;
    va_start(args, fmt);

    ret = _Printf(proutSprintf, dst, fmt, args);
    if (ret > -1) {
        dst[ret] = '\0';
    }

    va_end(args);

    return ret;
}*/


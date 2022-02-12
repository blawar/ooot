#define INTERNAL_SRC_BOOT_ASSERT_C
#include "global.h"
#include "def/assert.h"
#include <stdio.h>

void __assert(const char* exp, const char* file, s32 line) {
    char msg[256];

    osSyncPrintf("Assertion failed: %s, file %s, line %d, thread %d\n", exp, file, line, 0);
    sprintf(msg, "ASSERT: %s:%d(%d)", file, line, 0);

    while(true)
    {
    }
}

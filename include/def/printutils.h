#pragma once
#include "ultra64/printf.h"

s32 PrintUtils_Printf(PrintCallback* pfn, const char* fmt, ...);
s32 PrintUtils_VPrintf(PrintCallback* pfn, const char* fmt, va_list args);

#pragma once
#ifdef INTERNAL_SRC_CODE_PRINTUTILS_C
s32 PrintUtils_Printf(PrintCallback* pfn, const char* fmt, ...);
s32 PrintUtils_VPrintf(PrintCallback* pfn, const char* fmt, va_list args);
#else
s32 PrintUtils_Printf(PrintCallback* pfn, const char* fmt, ...);
s32 PrintUtils_VPrintf(PrintCallback* pfn, const char* fmt, va_list args);
#endif

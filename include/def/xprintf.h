#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_RMON_XPRINTF_C
s32 _Printf(PrintCallback, void* arg, const char* fmt, va_list ap);
#else
s32 _Printf(PrintCallback, void* arg, const char* fmt, va_list ap);
#endif

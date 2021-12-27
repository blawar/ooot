#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_RMON_SPRINTF_C
s32 sprintf(char* dst, const char* fmt, ...);
s32 vsprintf(char* dst, const char* fmt, va_list args);
#else
s32 sprintf(char* dst, const char* fmt, ...);
s32 vsprintf(char* dst, const char* fmt, va_list args);
#endif

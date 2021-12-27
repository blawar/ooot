#pragma once
#ifdef INTERNAL_SRC_BOOT_ASSERT_C
void __assert(const char* exp, const char* file, s32 line);
#else
void __assert(const char* exp, const char* file, s32 line);
#endif

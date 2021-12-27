#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_LIBC_BAK_STRING_C
u32 bcmp(void* __sl, void* __s2, u32 __n);
void* memcpy(void* dst, const void* src, u32 size);
u32 strlen(const char* str);
#else
u32 bcmp(void* __sl, void* __s2, u32 __n);
void* memcpy(void* dst, const void* src, u32 size);
u32 strlen(const char* str);
#endif

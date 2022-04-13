#pragma once
#include <stddef.h>
#include <string.h>
#include "porting_defs.h"
#include "z64.h"

#ifdef __cplusplus
#define _LANGUAGE_C_PLUS_PLUS
#endif

#include "macros.h"

#include <stdarg.h>
void osSyncPrintf(const char* fmt, ...);

#if defined(_MSC_VER)
void bzero(void* __s, size_t __n);
void bcopy(void* __s, void* __d, size_t __n);
#endif

u64 osGetTime();
void oot_assert(const char* exp, const char* file, s32 line);

#include "z_debug_display.h"


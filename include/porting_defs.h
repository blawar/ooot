#pragma once
#include <stdint.h>
#include "ultra64/types.h"

#define LITTLE_ENDIAN

#define SWAP16(data) \
( (((data) >> 8) & 0x00FF) | (((data) << 8) & 0xFF00) ) 

#define SWAP32(data)   \
( (((data) >> 24) & 0x000000FF) | (((data) >>  8) & 0x0000FF00) | \
  (((data) <<  8) & 0x00FF0000) | (((data) << 24) & 0xFF000000) ) 

#if UINTPTR_MAX == 0xffffffff
#define WORD_BITS 32
#elif UINTPTR_MAX == 0xffffffffffffffff
#define IS_64_BIT 1
#define WORD_BITS 64
#else
/* wtf */
#define WORD_BITS 32
#endif

#ifdef IS_64_BIT
#define word u64
#else
#define word u32
#endif

#ifdef BIG_ENDIAN
#define BE32(x) (x)
#define LE32(x) SWAP32(x)
#define BE16(x) (x)
#define LE16(x) SWAP16(x)
#else
#define BE32(x) SWAP32(x)
#define LE32(x) (x)
#define BE16(x) SWAP16(x)
#define LE16(x) (x)
#endif

#define POINTER_ADD(a, b) ((uintptr_t)a + (uintptr_t)b)
#define POINTER_SUB(a, b) (MAX((uintptr_t)a, (uintptr_t)b) - MIN((uintptr_t)a, (uintptr_t)b))
#define POINTER_SUB2(a, b) (MAX((uintptr_t)a.get(), (uintptr_t)b.get()) - MIN((uintptr_t)a.get(), (uintptr_t)b.get()))

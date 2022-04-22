#pragma once
#include <stdint.h>
#include "ultra64/types.h"

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN
#endif

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

struct s16be
{
	s16be() : value(0)
	{
	}

	s16be(s16 v) : value((s16)BE16((u16)v))
	{
	}

	operator s16() const
	{
		return (s16)BE16((u16)value);
	}

	s16 value;
};

struct u16be
{
	u16be() : value(0)
	{
	}

	u16be(u16 v) : value((u16)BE16((u16)v))
	{
	}

	operator u16() const
	{
		return (u16)BE16((u16)value);
	}

	u16 value;
};

struct s32be
{
	s32be() : value(0)
	{
	}

	s32be(s32 v) : value((s32)BE32((u32)v))
	{
	}

	operator s32() const
	{
		return (s32)BE32((u32)value);
	}

	s32 value;
};

struct u32be
{
	u32be() : value(0)
	{
	}

	u32be(u32 v) : value((u32)BE32((u32)v))
	{
	}

	operator u32() const
	{
		return (u32)BE32((u32)value);
	}

	u32 value;
};

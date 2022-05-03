#pragma once
#include <stdint.h>
#include "ultra64/types.h"

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN
#endif

#define SWAP16(data) ((((data) >> 8) & 0x00FF) | (((data) << 8) & 0xFF00))

#define SWAP32(data) ((((data) >> 24) & 0x000000FF) | (((data) >> 8) & 0x0000FF00) | (((data) << 8) & 0x00FF0000) | (((data) << 24) & 0xFF000000))

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

template <typename T> static constexpr const T byteswap(T value);

template <>
static constexpr const s16 byteswap<s16>(s16 value)
{
	return (s16)((u16)value >> 8) | ((u16)value << 8);
}

template <>
static constexpr const u16 byteswap<u16>(u16 value)
{
	return (value >> 8) | (value << 8);
}

template <>
static constexpr const u32 byteswap<u32>(u32 value)
{
	return u32(byteswap<u16>(value) << 16) | byteswap<u16>(value >> 16);
}

template <>
constexpr const s32 byteswap<s32>(s32 value)
{
	return s32(byteswap<u16>(value) << 16) | byteswap<u16>(value >> 16);
}

template <>
constexpr const f32 byteswap<f32>(f32 value)
{
	u8* ptr = (u8*)&value;
	const u8 r[4] = {ptr[3], ptr[2], ptr[1], ptr[0]};
	return *(f32*)r;
}

template<class T>
struct BE
{
	BE() : m_value(0)
	{
	}

	BE(T v) : m_value(byteswap<T>(v))
	{
	}

	BE& operator-=(T v)
	{
		*this = value() - v;
		return *this;
	}

	BE& operator+=(T v)
	{
		*this = value() + v;
		return *this;
	}

	BE& operator^=(T v)
	{
		*this = value() ^ v;
		return *this;
	}

	BE& operator|=(T v)
	{
		*this = value() | v;
		return *this;
	}

	BE& operator&=(T v)
	{
		*this = value() & v;
		return *this;
	}

	BE& operator++()
	{
		return operator+=(1);
	}

	BE operator++(int)
	{
		T s = value();
		operator+=(1);
		return s;
	}

	BE& operator--()
	{
		return operator-=(1);
	}

	BE operator--(int)
	{
		T s = value();
		operator-=(1);
		return s;
	}

	operator T() const
	{
		return (T)byteswap<T>(m_value);
	}

	T value() const
	{
		return m_value;
	}

	T m_value;
};

typedef BE<u16> u16be;
typedef BE<s16> s16be;
typedef BE<u32> u32be;
typedef BE<s32> s32be;
typedef BE<f32> f32be;


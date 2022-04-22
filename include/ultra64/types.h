#pragma once

#pragma warning (error: 4715)
#pragma warning (error: 4716)
#pragma warning (error: 4013)

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef signed char            s8;
typedef unsigned char          u8;
typedef signed short int       s16;
typedef unsigned short int     u16;
typedef signed int             s32;
typedef unsigned int           u32;
typedef signed long long int   s64;
typedef unsigned long long int u64;

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float  f32;
typedef double f64;


#ifndef GBI_FLOATS
typedef s32 Mtx_t[4][4];
typedef union {
    Mtx_t m;
    struct {
        u16 intPart[4][4];
        u16 fracPart[4][4];
    };
    long long int forc_structure_alignment;
} Mtx;
#else
struct Mtx {
    float m[4][4];
};
#endif

typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

class Pointer
{
	public:
	constexpr Pointer() : m_address(0)
	{
	}

    constexpr Pointer(uintptr_t address) : m_address(address)
	{
	}

	constexpr Pointer(int address) : m_address(address)
	{
	}

	constexpr Pointer(const void* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(void* address) : m_address((uintptr_t)address)
	{
	}

    constexpr Pointer(const s8* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(s8* address) : m_address((uintptr_t)address)
	{
	}

    constexpr Pointer(const u8* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(u8* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(const s16* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(s16* address) : m_address((uintptr_t)address)
	{
	}

    constexpr Pointer(const u16* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(u16* address) : m_address((uintptr_t)address)
	{
	}

    constexpr Pointer(const s32* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(s32* address) : m_address((uintptr_t)address)
	{
	}

    constexpr Pointer(const u32* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer(u32* address) : m_address((uintptr_t)address)
	{
	}

	constexpr Pointer operator + (const Pointer& b) const
	{
		return Pointer(m_address + b.m_address);
	}

	constexpr Pointer operator-(const Pointer& b) const
	{
		return Pointer(m_address - b.m_address);
	}

	Pointer& operator+=(const Pointer& b)
	{
		m_address += b.m_address;
		return *this;
	}

	Pointer& operator+=(const uintptr_t b)
	{
		m_address += b;
		return *this;
	}

	Pointer& operator-=(const Pointer& b)
	{
		m_address -= b.m_address;
		return *this;
	}

	Pointer& operator-=(const uintptr_t b)
	{
		m_address -= b;
		return *this;
	}

	bool operator==(uintptr_t n) const
	{
		return n == m_address;
	}

	bool operator==(int n) const
	{
		return n == m_address;
	}

	bool operator!=(uintptr_t n) const
	{
		return n != m_address;
	}

	bool operator!=(int n) const
	{
		return n != m_address;
	}

	uintptr_t size()
	{
		return m_address;
	}

    uintptr_t get()
	{
	    return m_address;
	}

	void* buffer()
	{
		return (void*)m_address;
	}

	void* c_str()
	{
		return (char*)m_address;
	}
	private:
	uintptr_t m_address;
};

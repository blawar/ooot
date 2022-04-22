#define INTERNAL_SRC_LIBULTRA_GU_SINS_C
#include "sintable.cpp"
#include "ultra64.h"
#include "def/sins.h"

s16 sins(u16 x)
{
	s16 value;

	x >>= 4;

	if(x & 0x400)
	{
		value = sintable[0x3FF - (x & 0x3FF)];
	}
	else
	{
		value = sintable[x & 0x3FF];
	}

	if(x & 0x800)
	{
		return -value;
	}
	else
	{
		return value;
	}
}

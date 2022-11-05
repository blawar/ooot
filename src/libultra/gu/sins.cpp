#define INTERNAL_SRC_LIBULTRA_GU_SINS_C
#include "ultra64.h"
#include "def/sins.h"
#include "macros.h"

s16 sins(s16 x)
{
	return (s16)(sin(DEGTORAD(((x & 0xFFFC) / SHT_MAX) * 180.0f)) * SHT_MAX);
}

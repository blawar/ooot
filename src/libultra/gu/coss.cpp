#define INTERNAL_SRC_LIBULTRA_GU_COSS_C
#include "ultra64.h"
#include "def/coss.h"
#include "macros.h"

s16 coss(s16 x)
{
	return (s16)(cos(DEGTORAD(((x & 0xFFFC) / SHT_MAX) * 180.0f)) * SHT_MAX);
}

#pragma once
#define Z_END_TITLE_H

#include "global.h"
#include "ultra64.h"

struct EndTitle;

struct EndTitle
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ u8 endAlpha;
	/* 0x014D */ u8 tlozAlpha;
	/* 0x014E */ u8 ootAlpha;
};

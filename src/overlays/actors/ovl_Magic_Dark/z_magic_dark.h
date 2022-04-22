#pragma once
#define Z_MAGIC_DARK_H

#include "global.h"
#include "ultra64.h"

struct MagicDark;

struct MagicDark
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ Timer timer;
	/* 0x014E */ u8 primAlpha;
	/* 0x0150 */ Vec3f orbOffset;
	/* 0x015C */ f32 scale;
	/* 0x0160 */ char unk_160[0x4];
};

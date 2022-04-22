#pragma once
#define Z_OBJ_DEKUJR_H

#include "global.h"
#include "ultra64.h"

struct ObjDekujr;

struct ObjDekujr
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ char unk_198[0x3];
	/* 0x019B */ u8 unk_19B;
	/* 0x019C */ u8 unk_19C;
	/* 0x019D */ char unk_19D[0x3];
	/* 0x01A0 */ s32 unk_1A0;
};

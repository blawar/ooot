#ifndef Z_EFF_SS_FCIRCLE_H
#define Z_EFF_SS_FCIRCLE_H

#include "global.h"
#include "ultra64.h"

typedef struct
{
	/* 0x00 */ Actor* actor;
	/* 0x04 */ Vec3f pos;
	/* 0x10 */ s16 radius;
	/* 0x12 */ s16 height;
} EffectSsFcircleInitParams; // size = 0x14

#endif

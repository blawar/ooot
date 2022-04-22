#pragma once
#define Z_EN_DEKUNUTS_H

#include "global.h"
#include "ultra64.h"

struct EnDekunuts;

typedef void (*EnDekunutsActionFunc)(struct EnDekunuts*, GlobalContext*);

struct EnDekunuts
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnDekunutsActionFunc actionFunc;
	/* 0x0194 */ u8 playWalkSound;
	/* 0x0195 */ Timer runAwayCount;
	/* 0x0196 */ Timer animFlagAndTimer;
	/* 0x0198 */ s16 runDirection;
	/* 0x019A */ s16 shotsPerRound;
	/* 0x019C */ Vec3s jointTable[25];
	/* 0x0232 */ Vec3s morphTable[25];
	/* 0x02C8 */ ColliderCylinder collider;
};

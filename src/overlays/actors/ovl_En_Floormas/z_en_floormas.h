#pragma once
#define Z_EN_FLOORMAS_H

#include "global.h"
#include "ultra64.h"

struct EnFloormas;
struct GlobalContext;

typedef void (*EnFloormasActionFunc)(EnFloormas* pthis, GlobalContext* globalCtx);

struct EnFloormas
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnFloormasActionFunc actionFunc;
	/* 0x0194 */ Timer actionTimer;
	/* 0x0196 */ s16 actionTarget;
	/* 0x0198 */ s16 zOffset;
	/* 0x019A */ Timer smActionTimer;
	/* 0x019C */ Vec3s jointTable[25];
	/* 0x0232 */ Vec3s morphTable[25];
	/* 0x02C8 */ ColliderCylinder collider;
};

#pragma once
#define Z_EN_MK_H

#include "global.h"
#include "ultra64.h"

struct EnMk;

typedef void (*EnMkActionFunc)(struct EnMk*, GlobalContext*);

struct EnMk
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ SkelAnime skelAnime;
	/* 0x01DC */ Vec3s jointTable[13];
	/* 0x022A */ Vec3s morphTable[13];
	/* 0x0278 */ Vec3s headRotation; // Used to rotate the man's head towards Link
	/* 0x027E */ u16 flags;
	/* 0x0280 */ s16 swimFlag;
	/* 0x0282 */ TimerU16 timer;
	/* 0x0284 */ EnMkActionFunc actionFunc;
};

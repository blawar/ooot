#pragma once
#define Z_EN_STH_H

#include "global.h"
#include "ultra64.h"

struct EnSth;

typedef void (*EnSthActionFunc)(struct EnSth*, GlobalContext*);

struct EnSth
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ SkelAnime skelAnime;
	/* 0x01DC */ Vec3s jointTable[16];
	/* 0x023C */ Vec3s morphTable[16];
	/* 0x029C */ u16 eventFlag;
	/* 0x02A0 */ ActorFunc drawFunc;
	/* 0x02A4 */ u8 objectBankIdx;
	/* 0x02A6 */ Vec3s headRot;//VecRot
	/* 0x02AC */ Vec3s pos;//VecPos
	/* 0x02B2 */ u16 unk_2B2;
	/* 0x02B4 */ s16 unk_2B4;
	/* 0x02B6 */ Timer unk_2B6;
	/* 0x02B8 */ EnSthActionFunc actionFunc;
};

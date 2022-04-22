#pragma once
#define Z_EN_PO_SISTERS_H

#include "global.h"
#include "ultra64.h"

struct EnPoSisters;

typedef void (*EnPoSistersActionFunc)(struct EnPoSisters*, GlobalContext*);

struct EnPoSisters
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnPoSistersActionFunc actionFunc;
	/* 0x0194 */ u8 unk_194;//index?
	/* 0x0195 */ u8 unk_195;//index?
	/* 0x0196 */ TimerU8 unk_196;///fire timer?
	/* 0x0197 */ TimerU8 unk_197;//moving timer?
	/* 0x0198 */ TimerU8 unk_198;
	/* 0x0199 */ u8 unk_199;
	/* 0x019A */ TimerS16 unk_19A;
	/* 0x019A */ TimerS16 unk_19C;
	/* 0x019E */ Vec3s jointTable[12];
	/* 0x01E6 */ Vec3s morphTable[12];
	/* 0x022E */ Color_RGBA8 unk_22E;
	/* 0x0234 */ Vec3f unk_234[8];
	/* 0x0294 */ f32 unk_294;
	/* 0x0298 */ LightNode* lightNode;
	/* 0x029C */ LightInfo lightInfo;
	/* 0x02AC */ ColliderCylinder collider;
	/* 0x02F8 */ MtxF unk_2F8;
};

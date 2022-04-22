#pragma once
#define Z_EN_HS2_H

#include "global.h"
#include "ultra64.h"

struct EnHs2;

typedef void (*EnHs2ActionFunc)(struct EnHs2*, GlobalContext*);

struct EnHs2
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ SkelAnime skelAnime;
	/* 0x01DC */ Vec3s jointTable[16];
	/* 0x023C */ Vec3s morphTable[16];
	/* 0x029C */ Vec3s unk_29C;
	/* 0x02A2 */ Vec3s unk_2A2;
	/* 0x02A8 */ u16 unk_2A8;
	/* 0x02AC */ EnHs2ActionFunc actionFunc;
};

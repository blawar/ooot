#pragma once
#define Z_EN_GUEST_H

#include "global.h"
#include "ultra64.h"

struct EnGuest;

typedef void (*EnGuestActionFunc)(struct EnGuest* pthis, GlobalContext* globalCtx);

struct EnGuest
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ Vec3s jointTable[16];
	/* 0x01F0 */ Vec3s morphTable[16];
	/* 0x0250 */ EnGuestActionFunc actionFunc;
	/* 0x0254 */ ColliderCylinder collider;
	/* 0x02A0 */ struct_80034A14_arg1 unk_2A0;
	/* 0x02C8 */ s16 unk_2C8;
	/* 0x02CA */ s16 unk_2CA;
	/* 0x02CC */ s16 unk_2CC[16];
	/* 0x02EC */ s16 unk_2EC[16];
	/* 0x030C */ s32 osAnimeBankIndex;
	/* 0x0300 */ u8 unk_30D;
	/* 0x0304 */ u8 unk_30E;
};

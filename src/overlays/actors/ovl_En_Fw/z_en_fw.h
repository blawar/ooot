#pragma once
#define Z_EN_FW_H

#include "global.h"
#include "ultra64.h"

struct EnFw;

typedef void (*EnFwActionFunc)(struct EnFw* pthis, GlobalContext* globalCtx);

struct EnFwEffect
{
	/* 0x0000 */ u8 type;
	/* 0x0001 */ u8 timer;
	/* 0x0002 */ u8 initialTimer;
	/* 0x0004 */ f32 scale;
	/* 0x0008 */ f32 scaleStep;
	/* 0x000C */ Color_RGBA8 color;
	/* 0x0010 */ char unk_10[4];
	/* 0x0014 */ Vec3f pos;
	/* 0x0020 */ Vec3f velocity;
	/* 0x002C */ Vec3f accel;
};

struct EnFw
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnFwActionFunc actionFunc;
	/* 0x0194 */ ColliderJntSph collider;
	/* 0x01B4 */ ColliderJntSphElement sphs[1];
	/* 0x01F4 */ Vec3f bompPos;
	/* 0x0200 */ u8 lastDmgHook;
	/* 0x0202 */ s16 runDirection;
	/* 0x0204 */ s16 bounceCnt;
	/* 0x0206 */ char unk_206[0x2];
	/* 0x0208 */ Timer damageTimer;
	/* 0x020A */ Timer explosionTimer;
	/* 0x020C */ char unk_20C[0x2];
	/* 0x020E */ Timer slideTimer;
	/* 0x0210 */ Timer slideSfxTimer;
	/* 0x0212 */ Timer returnToParentTimer;
	/* 0x0214 */ s16 turnAround;
	/* 0x0218 */ f32 runRadius;
	/* 0x021C */ Vec3s jointTable[11];
	/* 0x025E */ Vec3s morphTable[11];
	/* 0x02A0 */ EnFwEffect effects[20];
};

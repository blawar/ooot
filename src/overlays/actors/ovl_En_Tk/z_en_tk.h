#pragma once
#define Z_EN_TK_H

#include "global.h"
#include "ultra64.h"

/* Dirt particle effect */
struct EnTkEff;

struct EnTkEff
{
	/* 0x0000 */ u8 active;
	/* 0x0001 */ u8 timeLeft;
	/* 0x0002 */ u8 timeTotal;
	/* 0x0004 */ f32 size;
	/* 0x0008 */ f32 growth;
	/* 0x000C */ char unk_C[0x8];
	/* 0x0014 */ Vec3f pos;
	/* 0x0020 */ Vec3f speed;
	/* 0x002C */ Vec3f accel;
};

struct EnTk;

typedef void (*EnTkActionFunc)(struct EnTk*, GlobalContext*);

struct EnTk
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnTkActionFunc actionFunc;
	/* 0x0194 */ ColliderCylinder collider;
	/* 0x01E0 */ s16 h_1E0;
	/* 0x01E2 */ char unk_1E2[0x26];
	/* 0x0208 */ u8 validDigHere;
	/* 0x0209 */ u8 rewardCount[4];
	/* 0x0210 */ Actor* currentSpot;
	/* 0x0214 */ s32 currentReward;
	/* 0x0218 */ s16 blinkCycles;
	/* 0x021A */ Timer rewardTimer;
	/* 0x021C */ Timer actionCountdown;
	/* 0x021E */ s16 h_21E;
	/* 0x0220 */ char unk_220[0x2];
	/* 0x0222 */ s16 eyeTextureIdx;
	/* 0x0224 */ Timer blinkCountdown;
	/* 0x0226 */ s16 headRot;
	/* 0x0228 */ s16 currentWaypoint;
	/* 0x022A */ Vec3s jointTable[18];
	/* 0x0296 */ Vec3s morphTable[18];
	/* 0x0304 */ Vec3f v3f_304;
	/* 0x0310 */ EnTkEff eff[20];
};

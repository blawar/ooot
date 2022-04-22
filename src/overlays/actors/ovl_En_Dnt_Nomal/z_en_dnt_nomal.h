#pragma once
#define Z_EN_DNT_NOMAL_H

#include "global.h"
#include "ultra64.h"

struct EnDntNomal;

typedef void (*EnDntNomalActionFunc)(struct EnDntNomal*, GlobalContext*);

struct EnDntNomal
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ Vec3s jointTable[11];
	/* 0x01D2 */ Vec3s morphTable[11];
	/* 0x0214 */ EnDntNomalActionFunc actionFunc;
	/* 0x0218 */ u8 isSolid;
	/* 0x0219 */ Vec3f flowerPos;
	/* 0x0228 */ Vec3f targetVtx[4];
	/* 0x0258 */ Timer timer1;
	/* 0x025A */ Timer timer2;
	/* 0x025C */ Timer timer4;
	/* 0x025E */ Timer timer5;
	/* 0x0260 */ Timer blinkTimer;
	/* 0x0262 */ s16 unkCounter;
	/* 0x0264 */ Timer timer3;
	/* 0x0266 */ s16 objId;
	/* 0x0268 */ s16 eyeState;
	/* 0x026A */ s16 type;
	/* 0x026C */ s16 hitCounter;
	/* 0x026E */ s16 endFrame;
	/* 0x0270 */ s16 stageSignal;
	/* 0x0272 */ s16 rotDirection;
	/* 0x0274 */ s16 action;
	/* 0x0276 */ u8 ignore;
	/* 0x0277 */ u8 spawnedItem;
	/* 0x0278 */ u8 stagePrize;
	/* 0x0279 */ s32 objIndex;
	/* 0x027C */ Vec3f mouthPos;
	/* 0x0288 */ Vec3f targetPos;
	/* 0x0294 */ ColliderQuad targetQuad;
	/* 0x0314 */ ColliderCylinder bodyCyl;
};

#define ENDNTNOMAL_TARGET 0
#define ENDNTNOMAL_STAGE 1

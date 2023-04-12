#pragma once
#define Z_EN_BDFIRE_H

#include "global.h"
#include "overlays/actors/ovl_Boss_Dodongo/z_boss_dodongo.h"
#include "ultra64.h"

struct EnBdfire;

typedef void (*EnBdfireActionFunc)(struct EnBdfire*, GlobalContext*);
typedef void (*EnBdfireDrawFunc)(struct EnBdfire*, GlobalContext*);

struct EnBdfire
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnBdfireActionFunc actionFunc;
	/* 0x0150 */ EnBdfireDrawFunc drawFunc;
	/* 0x0154 */ TimerS16 timer;//how long the fire ball will last
	/* 0x0156 */ TimerS16 animTimer;//timer for animation speed
	/* 0x0158 */ s16 unk_158;
	/* 0x0188 */ f32 unk_188;
	/* 0x018C */ f32 unk_18C;
	/* 0x0190 */ f32 unk_190;
	/* 0x0194 */ f32 unk_194;
	/* 0x01D0 */ LightNode* lightNode;
	/* 0x01D4 */ LightInfo lightInfoNoGlow;
};

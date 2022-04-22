#pragma once
#define Z_EN_BOM_H

#include "global.h"
#include "ultra64.h"

struct EnBom;

typedef void (*EnBomActionFunc)(struct EnBom*, GlobalContext*);

struct EnBom
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder bombCollider;
	/* 0x0198 */ ColliderJntSph explosionCollider;
	/* 0x01B8 */ ColliderJntSphElement explosionColliderItems[1];
	/* 0x01F8 */ Timer timer;
	/* 0x01FA */ s16 flashSpeedScale;
	/* 0x01FC */ f32 flashIntensity;
	/* 0x0200 */ u8 bumpOn;
	/* 0x0204 */ EnBomActionFunc actionFunc;
};

enum EnBomType
{
	/* 0x00 */ BOMB_BODY,
	/* 0x01 */ BOMB_EXPLOSION
};

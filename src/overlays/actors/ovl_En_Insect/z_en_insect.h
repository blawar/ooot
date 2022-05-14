#pragma once
#define Z_EN_INSECT_H

#include "global.h"
#include "overlays/actors/ovl_Obj_Makekinsuta/z_obj_makekinsuta.h"
#include "ultra64.h"

struct EnInsect;

typedef void (*EnInsectActionFunc)(struct EnInsect*, GlobalContext*);

struct EnInsect
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderJntSph collider;
	/* 0x016C */ ColliderJntSphElement colliderItem;
	/* 0x01AC */ SkelAnime skelAnime;
	/* 0x01F0 */ Vec3s jointTable[24];
	/* 0x0280 */ Vec3s morphTable[24];
	/* 0x0310 */ EnInsectActionFunc actionFunc;
	/* 0x0314 */ u16 flags;
	/* 0x0316 */ s16 unk_316;
	/* 0x0318 */ s16 unk_318;
	/* 0x031A */ TimerS16 unk_31A;
	/* 0x031C */ TimerS16 unk_31C;
	/* 0x031E */ TimerS16 unk_31E;
	/* 0x0320 */ ObjMakekinsuta* soilActor;
	/* 0x0324 */ f32 unk_324;
	/* 0x0328 */ s16 unk_328;
	/* 0x032A */ u8 unk_32A;
};

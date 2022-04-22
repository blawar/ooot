#pragma once
#define Z_EN_JS_H

#include "global.h"
#include "ultra64.h"

struct EnJs;

typedef void (*EnJsActionFunc)(struct EnJs*, GlobalContext*);

struct EnJs
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ ColliderCylinder collider;
	/* 0x0198 */ SkelAnime skelAnime;
	/* 0x01DC */ Vec3s jointTable[13];
	/* 0x022A */ Vec3s morphTable[13];
	/* 0x0278 */ Vec3s unk_278;
	/* 0x027E */ Vec3s unk_27E;
	/* 0x0284 */ u16 unk_284;
	/* 0x0286 */ s16 unk_286;
	/* 0x0288 */ Timer unk_288;
	/* 0x028C */ EnJsActionFunc actionFunc;
};

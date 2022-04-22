#pragma once
#define Z_DEMO_IK_H

#include "global.h"
#include "ultra64.h"

struct DemoIk;

typedef void (*DemoIkActionFunc)(struct DemoIk* pthis, GlobalContext* globalCtx);
typedef void (*DemoIkDrawFunc)(struct DemoIk* pthis, GlobalContext* globalCtx);

struct DemoIk
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ Vec3s jointTable[2];
	/* 0x019C */ Vec3s morphTable[2];
	/* 0x01A8 */ s32 actionMode;
	/* 0x01AC */ s32 drawMode;
	/* 0x01B0 */ s32 csAction;
};

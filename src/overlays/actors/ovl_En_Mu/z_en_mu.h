#pragma once
#define Z_EN_MU_H

#include "global.h"
#include "ultra64.h"

struct EnMu;

typedef void (*EnMuActionFunc)(struct EnMu*, GlobalContext*);

struct EnMu
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ EnMuActionFunc actionFunc;
	/* 0x0194 */ ColliderCylinder collider;
	/* 0x01E0 */ struct_80034A14_arg1 npcInfo;
	/* 0x0208 */ u16 defFaceReaction;
	/* 0x020A */ s16 unk_20A[16];
	/* 0x022A */ s16 unk_22A[17];
};

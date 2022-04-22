#pragma once
#define Z_EN_VIEWER_H

#include "global.h"
#include "ultra64.h"

struct EnViewer;

typedef void (*EnViewerActionFunc)(struct EnViewer*, GlobalContext*);
typedef void (*EnViewerDrawFunc)(struct EnViewer*, GlobalContext*);
typedef void (*EnViewerInitAnimFunc)(struct EnViewer*, GlobalContext*, void*, AnimationHeader*);

enum EnViewerType
{
	/* 0 */ ENVIEWER_TYPE_0_HORSE_ZELDA,
	/* 1 */ ENVIEWER_TYPE_1_IMPA,
	/* 2 */ ENVIEWER_TYPE_2_ZELDA,
	/* 3 */ ENVIEWER_TYPE_3_GANONDORF,
	/* 4 */ ENVIEWER_TYPE_4_HORSE_GANONDORF,
	/* 5 */ ENVIEWER_TYPE_5_GANONDORF,
	/* 6 */ ENVIEWER_TYPE_6_HORSE_GANONDORF,
	/* 7 */ ENVIEWER_TYPE_7_GANONDORF,
	/* 8 */ ENVIEWER_TYPE_8_GANONDORF,
	/* 9 */ ENVIEWER_TYPE_9_GANONDORF
};

enum EnViewerDrawType
{
	/* 0 */ ENVIEWER_DRAW_GANONDORF,
	/* 1 */ ENVIEWER_DRAW_HORSE,
	/* 2 */ ENVIEWER_DRAW_ZELDA,
	/* 3 */ ENVIEWER_DRAW_IMPA
};

enum EnViewerShadowType
{
	/* 0 */ ENVIEWER_SHADOW_NONE,
	/* 1 */ ENVIEWER_SHADOW_CIRCLE,
	/* 2 */ ENVIEWER_SHADOW_HORSE
};

struct EnViewerInitData
{
	/* 0x00 */ s16 skeletonObject;
	/* 0x02 */ s16 animObject;
	/* 0x04 */ u8 scale;   // divided by 100.0f
	/* 0x05 */ s8 yOffset; // multiplied by 100
	/* 0x06 */ u8 shadowType;
	/* 0x07 */ u8 shadowScale;
	/* 0x08 */ u8 drawType;
	/* 0x0C */ void* skeletonHeaderSeg;
	/* 0x10 */ AnimationHeader* anim;
};

struct EnViewerFireEffect
{
	/* 0x00 */ Vec3f startPos;
	/* 0x0C */ Vec3f endPos;
	/* 0x18 */ Vec3f pos;
	/* 0x24 */ f32 lerpFactorSpeed;
	/* 0x28 */ f32 scale;
	/* 0x2C */ f32 lerpFactor;
	/* 0x30 */ u8 state;
};

struct EnViewer
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ PSkinAwb skin;
	/* 0x01DC */ s32 animObjBankIndex;
	/* 0x01DD */ u8 drawFuncIndex;
	/* 0x01E0 */ EnViewerActionFunc actionFunc;
	/* 0x01E4 */ u8 unused;
	/* 0x01E5 */ u8 state;
	/* 0x01E6 */ u8 isVisible;
	/* 0x01E8 */ EnViewerFireEffect fireEffects[20];
};

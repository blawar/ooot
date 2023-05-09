#ifndef Z64TRANSITION_H
#define Z64TRANSITION_H

#include "color.h"
#include "ultra64.h"

struct TransitionUnkData
{
	f32 unk_0;
	f32 unk_4;
};

struct TransitionUnk
{
	/* 0x00 */ s32 row;
	/* 0x04 */ s32 col;
	/* 0x08 */ s32 frame;
	/* 0x0C */ TransitionUnkData* unk_0C;
	/* 0x10 */ Vtx* vtxFrame1;
	/* 0x14 */ Vtx* vtxFrame2;
	/* 0x18 */ Mtx projection;
	/* 0x58 */ Mtx modelView;
	/* 0x98 */ Mtx unk_98;
	/* 0xD8 */ Gfx* gfx; // "gfxtbl"
	/* 0xDC */ u16* zBuffer;
}; // size = 0xE0

struct TransitionWipe
{
	/* 0x000 */ Color_RGBA8 color;
	/* 0x004 */ Color_RGBA8 altColor;
	/* 0x008 */ u8 direction;
	/* 0x009 */ u8 frame;
	/* 0x00A */ u8 isDone;
	/* 0x00C */ u16 texX;
	/* 0x00E */ u16 texY;
	/* 0x010 */ u16 normal;
	/* 0x018 */ Mtx projection;
	/* 0x058 */ Mtx lookAt;
	/* 0x098 */ Mtx modelView[2][3];
}; // size = 0x218

struct TransitionFade
{
	/* 0x000 */ u8 fadeType;
	/* 0x001 */ u8 isDone;
	/* 0x002 */ u8 fadeDirection;
	/* 0x004 */ Color_RGBA8 fadeColor;
	/* 0x008 */ u16 fadeTimer;
}; // size = 0xC

struct TransitionCircle
{
	/* 0x000 */ Color_RGBA8 color;
	/* 0x004 */ Color_RGBA8 envColor;
	/* 0x008 */ s32 texX;
	/* 0x00C */ s32 texY;
	/* 0x010 */ s32 step;
	/* 0x014 */ u8 unk_14;
	/* 0x015 */ u8 typeColor;
	/* 0x016 */ u8 speed;
	/* 0x017 */ u8 effect;
	/* 0x018 */ u8 isDone;
	/* 0x019 */ u8 frame;
	/* 0x01A */ u16 normal;
	/* 0x020 */ Mtx projection;
	/* 0x060 */ Mtx lookAt;
	/* 0x0A0 */ void* texture;
	/* 0x0A8 */ Mtx modelView[2][3];
}; // size = 0x228;

struct TransitionTriforce
{
	/* 0x000 */ Color_RGBA8 color;
	/* 0x004 */ f32 transPos;
	/* 0x008 */ f32 step;
	/* 0x00C */ s32 state;
	/* 0x010 */ s32 fadeDirection;
	/* 0x018 */ Mtx projection;
	/* 0x058 */ s32 frame;
	/* 0x060 */ Mtx modelView[2][3];
}; // size = 0x1E0;

#endif

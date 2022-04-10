#pragma once
#include "gfx.h"
#include "framerate.h"
#include "padmgr.h"
#include "regs.h"
#include "ultra64/types.h"

struct GameAllocEntry
{
	/* 0x00 */ struct GameAllocEntry* next;
	/* 0x04 */ struct GameAllocEntry* prev;
	/* 0x08 */ u32 size;
	/* 0x0C */ u32 unk_0C;
}; // size = 0x10

struct GameAlloc
{
	/* 0x00 */ GameAllocEntry base;
	/* 0x10 */ GameAllocEntry* head;
}; // size = 0x14

enum GameOverState
{
	/* 00 */ GAMEOVER_INACTIVE,
	/* 01 */ GAMEOVER_DEATH_START,
	/* 02 */ GAMEOVER_DEATH_WAIT_GROUND, // wait for link to fall and hit the ground
	/* 03 */ GAMEOVER_DEATH_DELAY_MENU,  // wait for 1 second before showing the game over menu
	/* 04 */ GAMEOVER_DEATH_MENU,	     // do nothing while kaliedoscope handles the game over menu
	/* 20 */ GAMEOVER_REVIVE_START = 20,
	/* 21 */ GAMEOVER_REVIVE_RUMBLE,
	/* 22 */ GAMEOVER_REVIVE_WAIT_GROUND, // wait for link to fall and hit the ground
	/* 23 */ GAMEOVER_REVIVE_WAIT_FAIRY,  // wait for the fairy to rise all the way up out of links body
	/* 24 */ GAMEOVER_REVIVE_FADE_OUT     // fade out the game over lights as link is revived and gets back up
};

struct GameOverContext
{
	/* 0x00 */ u16 state;
}; // size = 0x2

struct HorseStruct
{
	/* 0x00 */ char unk[0x4];
	/* 0x04 */ MtxF mf;
};

// Game Info aka. Static Context (dbg ram start: 80210A10)
// Data normally accessed through REG macros (see regs.h)
struct GameInfo
{
	/* 0x00 */ s32 regPage;	 // 1 is first page
	/* 0x04 */ s32 regGroup; // "register" group (R, RS, RO, RP etc.)
	/* 0x08 */ s32 regCur;	 // selected register within page
	/* 0x0C */ s32 dpadLast;
	/* 0x10 */ s32 repeat;
	/* 0x14 */ s16 data[REG_GROUPS * REG_PER_GROUP]; // 0xAE0 entries
};							 // size = 0x15D4

extern GameInfo* gGameInfo;

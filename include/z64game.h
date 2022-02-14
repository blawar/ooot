#pragma once
#include "ultra64/types.h"
#include "gfx.h"
#include "padmgr.h"
#include "regs.h"
#include "framerate.h"

struct GameState;

typedef void (*GameStateFunc)(struct GameState* gameState);

struct GameAllocEntry {
    /* 0x00 */ struct GameAllocEntry* next;
    /* 0x04 */ struct GameAllocEntry* prev;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unk_0C;
}; // size = 0x10

struct GameAlloc {
    /* 0x00 */ GameAllocEntry base;
    /* 0x10 */ GameAllocEntry* head;
}; // size = 0x14

struct GameState {
    /* 0x00 */ GraphicsContext* gfxCtx;
    /* 0x04 */ GameStateFunc main;
    /* 0x08 */ GameStateFunc destroy; // "cleanup"
    /* 0x0C */ GameStateFunc init;
    /* 0x10 */ u32 size;
    /* 0x14 */ Input input[4];
    /* 0x74 */ TwoHeadArena tha;
    /* 0x84 */ GameAlloc alloc;
    /* 0x98 */ u32 running;
    /* 0x9C */ Counter frames;
    /* 0xA0 */ u32 unk_A0;
}; // size = 0xA4

enum GameOverState {
    /* 00 */ GAMEOVER_INACTIVE,
    /* 01 */ GAMEOVER_DEATH_START,
    /* 02 */ GAMEOVER_DEATH_WAIT_GROUND, // wait for link to fall and hit the ground
    /* 03 */ GAMEOVER_DEATH_DELAY_MENU,  // wait for 1 second before showing the game over menu
    /* 04 */ GAMEOVER_DEATH_MENU,        // do nothing while kaliedoscope handles the game over menu
    /* 20 */ GAMEOVER_REVIVE_START = 20,
    /* 21 */ GAMEOVER_REVIVE_RUMBLE,
    /* 22 */ GAMEOVER_REVIVE_WAIT_GROUND, // wait for link to fall and hit the ground
    /* 23 */ GAMEOVER_REVIVE_WAIT_FAIRY,  // wait for the fairy to rise all the way up out of links body
    /* 24 */ GAMEOVER_REVIVE_FADE_OUT     // fade out the game over lights as link is revived and gets back up
};

struct GameOverContext {
    /* 0x00 */ u16 state;
}; // size = 0x2

struct HorseStruct {
    /* 0x00 */ char unk[0x4];
    /* 0x04 */ MtxF mf;
};

// Game Info aka. Static Context (dbg ram start: 80210A10)
// Data normally accessed through REG macros (see regs.h)
struct GameInfo {
    /* 0x00 */ s32 regPage;  // 1 is first page
    /* 0x04 */ s32 regGroup; // "register" group (R, RS, RO, RP etc.)
    /* 0x08 */ s32 regCur;   // selected register within page
    /* 0x0C */ s32 dpadLast;
    /* 0x10 */ s32 repeat;
    /* 0x14 */ s16 data[REG_GROUPS * REG_PER_GROUP]; // 0xAE0 entries
};                                          // size = 0x15D4

struct GameStateOverlay {
	/* 0x00 */ Pointer loadedRamAddr;
    /* 0x04 */ Pointer vromStart; // if applicable
    /* 0x08 */ Pointer vromEnd;	  // if applicable
    /* 0x0C */ Pointer vramStart; // if applicable
    /* 0x10 */ Pointer vramEnd;	  // if applicable
    /* 0x14 */ UNK_PTR unk_14;
    /* 0x18 */ void* init;    // initializes and executes the given context
    /* 0x1C */ void* destroy; // deconstructs the context, and sets the next context to load
    /* 0x20 */ UNK_PTR unk_20;
    /* 0x24 */ UNK_PTR unk_24;
    /* 0x28 */ UNK_TYPE4 unk_28;
    /* 0x2C */ u32 instanceSize;
}; // size = 0x30

extern GameInfo* gGameInfo;

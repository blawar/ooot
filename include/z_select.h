#pragma once
#include "view.h"

struct SelectContext;

struct SceneSelectEntry {
    /* 0x00 */ const char* name;
    /* 0x04 */ void (*loadFunc)(struct SelectContext*, s32);
    /* 0x08 */ s32 entranceIndex;
}; // size = 0xC

struct SelectContext {
    /* 0x0000 */ GameState state;
    /* 0x00A8 */ View view;
    /* 0x01D0 */ s32 count;
    /* 0x01D4 */ SceneSelectEntry* scenes;
    /* 0x01D8 */ s32 currentScene;
    /* 0x01DC */ s32 pageDownIndex; // Index of pageDownStops
    /* 0x01E0 */ s32 pageDownStops[7];
    /* 0x01FC */ char unk_1FC[0x0C];
    /* 0x0208 */ s32 opt;
    /* 0x020C */ s32 topDisplayedScene; // The scene which is currently at the top of the screen
    /* 0x0210 */ char unk_210[0x0C];
    /* 0x021C */ s32 verticalInputAccumulator;
    /* 0x0220 */ s32 verticalInput;
    /* 0x0224 */ s32 timerUp;
    /* 0x0228 */ s32 timerDown;
    /* 0x022C */ s32 lockUp;
    /* 0x0230 */ s32 lockDown;
    /* 0x0234 */ s32 unk_234; // unused
    /* 0x0238 */ u8* staticSegment;
}; // size = 0x240

void Select_Init(GameState* thissx);
void Select_Destroy(GameState* thissx);


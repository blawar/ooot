#pragma once
#include "ultra64/time.h"
#include "z64game.h"

struct PreNmiBuff {
    /* 0x00 */ u32 resetting;
    /* 0x04 */ u32 resetCount;
    /* 0x08 */ OSTime duration;
    /* 0x10 */ OSTime resetTime;
}; // size = 0x18 (actually osAppNmiBuffer is 0x40 bytes large but the rest is unused)

struct PreNMIContext {
    /* 0x00 */ GameState state;
    /* 0xA4 */ u32 timer;
    /* 0xA8 */ UNK_TYPE4 unk_A8;
}; // size = 0xAC

void Audio_PreNMIInternal(void);
void Audio_PreNMI();

void PreNMI_Init(GameState* thissx);



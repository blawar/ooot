#pragma once
#define Z_BG_HIDAN_FWBIG_H

#include "ultra64.h"
#include "global.h"

struct BgHidanFwbig;

typedef void (*BgHidanFwbigActionFunc)(struct BgHidanFwbig*, GlobalContext*);


enum HidanFwbigMoveState {
    /* 0 */ FWBIG_MOVE,
    /* 1 */ FWBIG_RESET,
    /* 2 */ FWBIG_KILL
};
struct BgHidanFwbig {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ BgHidanFwbigActionFunc actionFunc;
    /* 0x0150 */ s8 direction;
    /* 0x0151 */ u8 moveState;
    /* 0x0152 */ Timer timer;
    /* 0x0154 */ ColliderCylinder collider;
}; 



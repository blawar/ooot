#pragma once
#define Z_EN_LIGHT_H

#include "ultra64.h"
#include "global.h"

struct EnLight;



struct FlameParams {
    /* 0x00 */ Color_RGBA8 primColor;
    /* 0x04 */ Color_RGB8 envColor;
    /* 0x07 */ u8 scale;
};
struct EnLight {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ u8 timer;
    /* 0x0150 */ LightNode* lightNode;
    /* 0x0154 */ LightInfo lightInfo;
}; 



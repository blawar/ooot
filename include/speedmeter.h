#pragma once
#include "ultra64/types.h"
#include "ultra64/time.h"

struct SpeedMeter {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 y;
}; // size = 0x20

struct SpeedMeterAllocEntry {
    /* 0x00 */ s32 maxval;
    /* 0x04 */ s32 val;
    /* 0x08 */ u16 backColor;
    /* 0x0A */ u16 foreColor;
    /* 0x0C */ s32 ulx;
    /* 0x10 */ s32 lrx;
    /* 0x14 */ s32 uly;
    /* 0x18 */ s32 lry;
}; // size = 0x1C

struct SpeedMeterTimeEntry {
    /* 0x00 */ volatile OSTime* time;
    /* 0x04 */ u8 x;
    /* 0x05 */ u8 y;
    /* 0x06 */ u16 color;
}; // size = 0x08

extern volatile OSTime D_8016A520;
extern volatile OSTime D_8016A528;
extern volatile OSTime D_8016A530;
extern volatile OSTime D_8016A538;
extern volatile OSTime D_8016A540;
extern volatile OSTime D_8016A548;
extern volatile OSTime D_8016A550;
extern volatile OSTime D_8016A558;
extern volatile OSTime gRSPAudioTotalTime;
extern volatile OSTime gRSPGFXTotalTime;
extern volatile OSTime gRSPOtherTotalTime;
extern volatile OSTime gRDPTotalTime;


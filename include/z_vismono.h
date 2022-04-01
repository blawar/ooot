#pragma once
#include "z64math.h"
#include "color.h"
#include "gfx.h"

struct VisMono {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 setScissor;
    /* 0x08 */ Color_RGBA8 primColor;
    /* 0x0C */ Color_RGBA8 envColor;
    /* 0x10 */ u16* tlut;
    /* 0x14 */ Gfx* dList;
}; // size = 0x18

struct struct_80166500 {
    /* 0x00 */ u32 useRgba;
    /* 0x04 */ u32 setScissor;
    /* 0x08 */ Color_RGBA8 primColor;
    /* 0x08 */ Color_RGBA8 envColor;
}; // size = 0x10

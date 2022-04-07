#pragma once
#define Z_OBJ_TIMEBLOCK_H

#include "ultra64.h"
#include "global.h"

struct ObjTimeblock;

typedef s32 (*ObjTimeblockSongObserverFunc)(struct ObjTimeblock*, GlobalContext*);
typedef void (*ObjTimeblockActionFunc)(struct ObjTimeblock*, GlobalContext*);



struct ObjTimeblockSizeOptions {
    /* 0x00 */ f32 scale;
    /* 0x04 */ f32 height;
    /* 0x08 */ s16 demoEffectParams;
};
struct ObjTimeblock {

    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ObjTimeblockActionFunc actionFunc;
    /* 0x0168 */ ObjTimeblockSongObserverFunc songObserverFunc;
    /* 0x016C */ Timer demoEffectTimer;
    /* 0x016E */ Timer songEndTimer;
    /* 0x0170 */ Timer demoEffectFirstPartTimer;
    /* 0x0172 */ u16 unk_172;
    /* 0x0174 */ u8 unk_174;
    /* 0x0175 */ u8 unk_175;
    /* 0x0176 */ u8 unk_176;
    /* 0x0177 */ u8 unk_177;
    /* 0x0178 */ u8 isVisible;
}; 



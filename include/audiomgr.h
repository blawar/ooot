#pragma once
#include "z64audio.h"
#include "sched.h"
#include "z64math.h"

struct SoundSource {
    /* 0x00 */ u16 countdown;
    /* 0x04 */ Vec3f originPos;
    /* 0x10 */ Vec3f relativePos;
}; // size = 0x1C

struct AudioMgr {
    /* 0x0000 */ IrqMgr* irqMgr;
    /* 0x0004 */ SchedContext* sched;
    /* 0x0008 */ OSScTask audioTask;
    /* 0x0060 */ char unk_60[0x10];
    /* 0x0070 */ AudioTask* rspTask;
    /* 0x0074 */ OSMesgQueue unk_74;
    /* 0x008C */ OSMesg unk_8C;
    /* 0x0090 */ OSMesgQueue unk_90;
    /* 0x00A8 */ OSMesg unk_A8;
    /* 0x00AC */ OSMesgQueue unk_AC;
    /* 0x00C4 */ OSMesg unk_C4;
    /* 0x00C8 */ OSMesgQueue unk_C8;
    /* 0x00E0 */ OSMesg unk_E0;
    /* 0x00E4 */ char unk_E4[0x04];
    /* 0x00E8 */ OSThread unk_E8;
}; // size = 0x298

extern Vec3f D_801333D4;
extern f32 D_801333E0;
extern s8 D_801333E8;
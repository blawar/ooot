#pragma once
#include "sched.h"
#include "ultra64/controller.h"
#include "ultra64/pfs.h"

struct Input {
    /* 0x00 */ OSContPad cur;
    /* 0x06 */ OSContPad prev;
    /* 0x0C */ OSContPad press; // X/Y store delta from last frame
    /* 0x12 */ OSContPad rel;   // X/Y store adjusted
};                        // size = 0x18

struct PadMgr {
    /* 0x0000 */ OSContStatus padStatus[4];
    /* 0x0010 */ OSMesg serialMsgBuf[1];
    /* 0x0014 */ OSMesg lockMsgBuf[1];
    /* 0x0018 */ OSMesg interruptMsgBuf[4];
    /* 0x0028 */ OSMesgQueue serialMsgQ;
    /* 0x0040 */ OSMesgQueue lockMsgQ;
    /* 0x0058 */ OSMesgQueue interruptMsgQ;
    /* 0x0070 */ IrqMgrClient irqClient;
    /* 0x0078 */ IrqMgr* irqMgr;
    /* 0x0080 */ OSThread thread;
    /* 0x0230 */ Input inputs[4];
    /* 0x0290 */ OSContPad pads[4];
    /* 0x02A8 */ vu8 validCtrlrsMask;
    /* 0x02A9 */ u8 nControllers;
    /* 0x02AA */ u8 ctrlrIsConnected[4]; // "Key_switch" originally
    /* 0x02AE */ u8 pakType[4];          // 1 if rumble pack, 2 if mempak?
    /* 0x02B2 */ vu8 rumbleEnable[4];
    /* 0x02B6 */ u8 rumbleCounter[4]; // not clear exact meaning
    /* 0x02BC */ OSPfs pfs[4];
    /* 0x045C */ vu8 rumbleOffFrames;
    /* 0x045D */ vu8 rumbleOnFrames;
    /* 0x045E */ u8 preNMIShutdown;
    /* 0x0460 */ void (*retraceCallback)(struct PadMgr* padmgr, s32 unk464);
    /* 0x0464 */ u32 retraceCallbackValue;
}; // size = 0x468

struct UnkRumbleStruct {
    /* 0x000 */ u8 rumbleEnable[4];
    /* 0x004 */ u8 unk_04[0x40];
    /* 0x044 */ u8 unk_44[0x40];
    /* 0x084 */ u8 unk_84[0x40];
    /* 0x0C4 */ u8 unk_C4[0x40];
    /* 0x104 */ u8 unk_104;
    /* 0x105 */ u8 unk_105;
    /* 0x106 */ u16 unk_106;
    /* 0x108 */ u16 unk_108;
    /* 0x10A */ u8 unk_10A;
    /* 0x10B */ u8 unk_10B;
    /* 0x10C */ u8 unk_10C;
    /* 0x10D */ u8 unk_10D;
}; // size = 0x10E

extern PadMgr gPadMgr;
extern u32 gIsCtrlr2Valid;


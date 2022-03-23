#pragma once
#include <functional>
#include "ultra64/sched.h"
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
    /* 0x02B2 */ vu8 rumbleOn[4];
    /* 0x02B6 */ u8 rumbleCounter[4]; // not clear exact meaning
    /* 0x02BC */ OSPfs pfs[4];
    /* 0x045C */ vu8 rumbleOffFrames;
    /* 0x045D */ vu8 rumbleOnFrames;
    /* 0x045E */ u8 preNMIShutdown;
    /* 0x0460 */ void (*retraceCallback)(struct PadMgr* padmgr, s32 unk464);
    /* 0x0464 */ u32 retraceCallbackValue;
}; // size = 0x468

struct RumbleStruct {
    std::function<void(uint8_t, uint8_t, uint8_t)> onVibrate;//Callback, takes strength, length, decay

    /* 0x000 */ u8 rumbleOn[4];//0 or 1 depending if rumble is happening right now
    /* 0x004 */ u8 strengthList[0x40];//rumble pattern
    /* 0x044 */ u8 lengthList[0x40];//rumble pattern
    /* 0x084 */ u8 decayList[0x40];//rumble pattern
    /* 0x0C4 */ u8 strengthList_easing[0x40];//Used internally to make the decay in more quadratic instead of linear

    /* 0x104 */ u8 state;//set to 0 for a clear of all rumble data (rumble stops), set to 1 to continue operation, set to 2 for a full rumble device clear
    /* 0x105 */ u8 reset;//set to zero to reset pakType of pad manager
    /* 0x106 */ u16 timer1;//Counts up for each frame there is rumble, after 7200 frames ~ 6 minutes clears the rumble data
    /* 0x108 */ u16 timer2;//Resets timer1 when there is no rumble

    /* 0x10A */ u8 strength;
    /* 0x10B */ u8 length;
    /* 0x10C */ u8 decay;
    /* 0x10D */ u8 strength_easing;
}; // size = 0x10E

extern PadMgr gPadMgr;
extern u32 gIsCtrlr2Valid;
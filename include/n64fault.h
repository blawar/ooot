#pragma once
#include "ultra64/types.h"
#include "sched.h"
#include "padmgr.h"

struct FaultClient {
    /* 0x00 */ struct FaultClient* next;
    /* 0x04 */ u32 callback;
    /* 0x08 */ u32 param1;
    /* 0x0C */ u32 param2;
}; // size = 0x10

struct FaultAddrConvClient {
    /* 0x00 */ struct FaultAddrConvClient* next;
    /* 0x04 */ u32 callback;
    /* 0x08 */ u32 param;
}; // size = 0xC

struct FaultClientContext {
    /* 0x00 */ u32 (*callback)(u32, u32);
    /* 0x04 */ u32 param0;
    /* 0x08 */ u32 param1;
    /* 0x0C */ u32 ret;
    /* 0x10 */ OSMesgQueue* queue;
    /* 0x14 */ OSMesg msg;
}; // size = 0x18

struct FaultThreadStruct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ u8 unk_1B0[0x600];
    /* 0x7B0 */ OSMesgQueue queue;
    /* 0x7C8 */ OSMesg msg;
    /* 0x7CC */ u8 exitDebugger;
    /* 0x7CD */ u8 msgId;
    /* 0x7CE */ u8 faultHandlerEnabled;
    /* 0x7CF */ u8 faultActive;
    /* 0x7D0 */ OSThread* faultedThread;
    /* 0x7D4 */ void (*padCallback)(Input*);
    /* 0x7D8 */ FaultClient* clients;
    /* 0x7DC */ FaultAddrConvClient* addrConvClients;
    /* 0x7E0 */ u8 unk_7E0[4];
    /* 0x7E4 */ Input padInput;
    /* 0x7FC */ u16 colors[36];
    /* 0x844 */ void* fb;
    /* 0x848 */ u32 currClientThreadSp;
    /* 0x84C */ u8 unk_84C[4];
}; // size = 0x850

struct FaultDrawer {
    /* 0x00 */ u16* fb;
    /* 0x04 */ u16 w;
    /* 0x08 */ u16 h;
    /* 0x0A */ u16 yStart;
    /* 0x0C */ u16 yEnd;
    /* 0x0E */ u16 xStart;
    /* 0x10 */ u16 xEnd;
    /* 0x12 */ u16 foreColor;
    /* 0x14 */ u16 backColor;
    /* 0x14 */ u16 cursorX;
    /* 0x16 */ u16 cursorY;
    /* 0x18 */ const u32* fontData;
    /* 0x1C */ u8 charW;
    /* 0x1D */ u8 charH;
    /* 0x1E */ s8 charWPad;
    /* 0x1F */ s8 charHPad;
    /* 0x20 */ u16 printColors[10];
    /* 0x34 */ u8 escCode; // bool
    /* 0x35 */ u8 osSyncPrintfEnabled;
    /* 0x38 */ void (*inputCallback)();
}; // size = 0x3C

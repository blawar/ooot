#pragma once
#include "ultra64/types.h"
#include "ultra64/sptask.h"
#include "ultra64/message.h"
#include "ultra64/time.h"
#include "unk.h"

#define OS_SC_RETRACE_MSG 1
#define OS_SC_DONE_MSG 2
#define OS_SC_NMI_MSG 3 // name is made up, 3 is OS_SC_RDP_DONE_MSG in the original sched.c
#define OS_SC_PRE_NMI_MSG 4

#define OS_SC_DP 0x0001
#define OS_SC_SP 0x0002
#define OS_SC_YIELD 0x0010
#define OS_SC_YIELDED 0x0020

#define OS_SC_NEEDS_RDP 0x0001
#define OS_SC_NEEDS_RSP 0x0002
#define OS_SC_DRAM_DLIST 0x0004
#define OS_SC_PARALLEL_TASK 0x0010
#define OS_SC_LAST_TASK 0x0020
#define OS_SC_SWAPBUFFER 0x0040

#define OS_SC_RCP_MASK 0x0003
#define OS_SC_TYPE_MASK 0x0007

struct OSScMsg {
    /* 0x00 */ s16 type;
    /* 0x02 */ char misc[0x1E];
}; // size = 0x20

struct IrqMgrClient {
    /* 0x00 */ struct IrqMgrClient* prev;
    /* 0x04 */ OSMesgQueue* queue;
};

struct IrqMgr {
    /* 0x000 */ OSScMsg retraceMsg; // this apparently got moved from OSSched
    /* 0x020 */ OSScMsg prenmiMsg;  // this apparently got moved from OSSched
    /* 0x040 */ OSScMsg nmiMsg;
    /* 0x060 */ OSMesgQueue queue;
    /* 0x078 */ OSMesg msgBuf[8];
    /* 0x098 */ OSThread thread;
    /* 0x248 */ IrqMgrClient* clients;
    /* 0x24C */ u8 resetStatus;
    /* 0x250 */ OSTime resetTime;
    /* 0x258 */ OSTimer timer;
    /* 0x278 */ OSTime retraceTime;
}; // size = 0x280

struct CfbInfo {
    /* 0x00 */ u16* fb1;
    /* 0x04 */ u16* swapBuffer;
    /* 0x08 */ struct OSViMode* viMode;
    /* 0x0C */ u32 features;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ s8 updateRate;
    /* 0x12 */ s8 updateRate2;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ f32 xScale;
    /* 0x18 */ f32 yScale;
}; // size = 0x1C

struct OSScTask {
    /* 0x00 */ struct OSScTask* next;
    /* 0x04 */ u32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ CfbInfo* framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ OSMesgQueue* msgQ;
    /* 0x54 */ OSMesg msg;
};

struct SchedContext {
    /* 0x0000 */ OSMesgQueue interruptQ;
    /* 0x0018 */ OSMesg intBuf[8];
    /* 0x0038 */ OSMesgQueue cmdQ;
    /* 0x0050 */ OSMesg cmdMsgBuf[8];
    /* 0x0070 */ OSThread thread;
    /* 0x0220 */ OSScTask* audioListHead;
    /* 0x0224 */ OSScTask* gfxListHead;
    /* 0x0228 */ OSScTask* audioListTail;
    /* 0x022C */ OSScTask* gfxListTail;
    /* 0x0230 */ OSScTask* curRSPTask;
    /* 0x0234 */ OSScTask* curRDPTask;
    /* 0x0238 */ s32 retraceCnt;
    /* 0x023C */ s32 doAudio;
    /* 0x0240 */ CfbInfo* curBuf;
    /* 0x0244 */ CfbInfo* pendingSwapBuf1;
    /* 0x0220 */ CfbInfo* pendingSwapBuf2;
    /* 0x0220 */ UNK_TYPE4 unk_24C;
    /* 0x0250 */ IrqMgrClient irqClient;
}; // size = 0x258

extern SchedContext gSchedContext;


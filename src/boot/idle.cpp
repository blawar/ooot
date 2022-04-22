#define INTERNAL_SRC_BOOT_IDLE_C
#include "global.h"
#include "vt.h"
#include "sched.h"
#include "ultra64/vi.h"
#include "def/game.h"
#include "def/gettime.h"
#include "def/heaps.h"
#include "def/idle.h"
#include "def/pimgr.h"
#include "def/setthreadpri.h"
#include "def/stackcheck.h"
#include "def/startthread.h"
#include "def/viblack.h"
#include "def/vimodefpallan1.h"
#include "def/vimodempallan1.h"
#include "def/vimodentsclan1.h"
#include "def/visetmode.h"
#include "def/viswapbuf.h"
#include "def/z_std_dma.h"

OSThread gMainThread;
u8 sMainStack[0x900];
StackEntry sMainStackInfo;
OSMesg sPiMgrCmdBuff[50];
OSMesgQueue gPiMgrCmdQ;
OSViMode gViConfigMode;
u8 D_80013960;

s8 D_80009430 = 1;
vu8 gViConfigUseDefault = 1;
u8 gViConfigAdditionalScanLines = 0;
u32 gViConfigFeatures = OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF;
f32 gViConfigXScale = 1.0;
f32 gViConfigYScale = 1.0;

void Main_ThreadEntry(void* arg) {
    OSTime time;

    osSyncPrintf("mainx execution start\n");
    DmaMgr_Init();
    osSyncPrintf("code segment loading...");
    time = osGetTime();

    time -= osGetTime();
    osSyncPrintf("\rcode segment loading... complete\n");
    osSyncPrintf("transfer time %6.3f\n");
    osSyncPrintf("code segment BBS clear complete\n");
    //Main(arg);
    osSyncPrintf("mainx execution end\n");
}

void Idle_ThreadEntry(void* arg) {
    osSyncPrintf("idle thread (idleproc) execution start\n");
    osSyncPrintf("creator : %s\n", gBuildTeam);
    osSyncPrintf("creation date : %s\n", gBuildDate);
    osSyncPrintf("MAKEOPTION: %s\n", gBuildMakeOption);
    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("RAM size is %d kilobytes (osMemSize/osGetMemSize)\n", (s32)osMemSize / 1024);
    osSyncPrintf("Z buffer size is %d kilobytes\n", 0x96);
    osSyncPrintf("dynamic buffer size is %d kilobytes\n", 0x92);
    osSyncPrintf("FIFO buffer size is %d kilobytes\n", 0x60);
    osSyncPrintf("YIELD buffer size is %d kilobytes\n", 3);
    osSyncPrintf("audio heap size is %d kilobytes\n", ((s32)gSystemHeap - (s32)gAudioHeap) / 1024);
    osSyncPrintf(VT_RST);

    osCreateViManager(OS_PRIORITY_VIMGR);

    gViConfigFeatures = OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON;
    gViConfigXScale = 1.0f;
    gViConfigYScale = 1.0f;

    switch (osTvType) {
        case OS_TV_NTSC:
            D_80013960 = 2;
            gViConfigMode = osViModeNtscLan1;
            break;

        case OS_TV_MPAL:
            D_80013960 = 0x1E;
            gViConfigMode = osViModeMpalLan1;
            break;

        case OS_TV_PAL:
            D_80013960 = 0x2C;
            gViConfigMode = osViModeFpalLan1;
            gViConfigYScale = 0.833f;
            break;
    }

    D_80009430 = 1;
    osViSetMode(&gViConfigMode);
    ViConfig_UpdateVi(1);
    osViBlack(1);
    osViSwapBuffer(0x803DA80); //! @bug Invalid vram address (probably intended to be 0x803DA800)
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPiMgrCmdQ, sPiMgrCmdBuff, 50);
    StackCheck_Init(&sMainStackInfo, sMainStack, sMainStack + sizeof(sMainStack), 0, 0x400, "main");
    osCreateThread(&gMainThread, 3, Main_ThreadEntry, arg, sMainStack + sizeof(sMainStack), Z_PRIORITY_MAIN);
    osStartThread(&gMainThread);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (1) {
        ;
    }
}

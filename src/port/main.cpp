#include <string>
#include <vector>
#include "global.h"
#include "options.h"
#include "controller/tas.h"
#include "ultra64/types.h"
#include "ultra64/vi.h"
#include "z64audio.h"
#include "audiomgr.h"
#include "z_prenmi_buff.h"
#include "ultra64/rcp.h"
#include "ultra64/exception.h"
#include "def/sys_cfb.h"
#include "def/z_debug.h"
#include "audiomgr.h"
#include "def/audio.h"
#include "def/audioMgr.h"

//f32 qNaN0x3FFFFF;
f32 qNaN0x10000;
//f32 sNaN0x3FFFFF;

PreNmiBuff* gAppNmiBufferPtr;
SchedContext gSchedContext;
PadMgr gPadMgr;
uintptr_t gSegments[NUM_SEGMENTS];

AudioMgr gAudioMgr;

u8 osAppNmiBuffer[0x40];
UNK_TYPE D_06000000;
u32 osResetType = 0;

//u64 osClockRate = OS_CLOCK_RATE;
s32 osViClock = VI_NTSC_CLOCK;
u32 __osShutdown = 0;
OSHWIntr __OSGlobalIntMask = OS_IM_ALL;

u32 osRomBase;

u32 osMemSize = 0x800000;

//void (*D_801755D0)(void) = NULL;

void xxxDebugDisplay_Init(void)
{
}

struct DebugDispObject* xxxDebugDisplay_AddObject(f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, f32 scaleX, f32 scaleY, f32 scaleZ, u8 red, u8 green, u8 blue, u8 alpha, s16 type, struct GraphicsContext* gfxCtx)
{
    return NULL;
}

void xxxDebugDisplay_DrawObjects(struct GlobalContext* globalCtx)
{
}



__osHwInt __osHwIntTable[4] = { 0 };

s32 __osDisableInt(void) {
    return 0;
}

void __osRestoreInt(s32 a) {
}

void osInvalICache(void* vaddr, s32 nbytes) {
}

void osInvalDCache(void* vaddr, s32 nbytes) {
}

void __osEnqueueAndYield(OSThread** a) {
}

void __osEnqueueThread(OSThread** a, OSThread* b) {
}

OSThread* __osPopThread(OSThread** a) {
    return NULL;
}

void __osDispatchThread() {
}

void __osCleanupThread(void) {
}

void __osSetWatchLo(u32 a) {
}

void osUnmapTLBAll(void) {
}

void __osSetFpcCsr(u32 a) {
}

u32 __osGetFpcCsr() {
    return 0;
}

void osWritebackDCache(void* vaddr, s32 nbytes) {
}

void __osSetSR(u32 a) {
}

u32 __osGetSR() {
    return 0;
}

OSIntMask osSetIntMask(OSIntMask a) {
    return 0;
}

s32 osSetTimer(OSTimer* timer, OSTime countdown, OSTime interval, OSMesgQueue* mq, OSMesg msg) {
    return 0;
}

s32 osStopTimer(OSTimer* timer) {
    return 0;
}

void __osSetCompare(u32 a) {
}

void main_func(void);

extern f32 gViConfigXScale;
extern f32 gViConfigYScale;
extern u32 gViConfigFeatures;



void ParseCommandLineArguments(const std::vector<std::string>& commands)
{
    auto size_left = commands.size();
    for (size_t i = 0; i < commands.size(); i++)
    {
        auto& cmd = commands[i];
        size_left--;

        if (cmd == "-tas" && size_left > 0)
        {
            auto tas_filename = std::move(commands[++i]);
            oot::hid::tas::setTasFileName(tas_filename);
            oot::hid::tas::playTas(true);
        }

        else if (cmd == "-no-graphics")
            oot::config().game().disableGraphics();

        else if (cmd == "-fast-forward")
            oot::config().game().disableFramePacing();
    }
}

void run()
{
    s16* msg;


    gViConfigFeatures = OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON;
    gViConfigXScale = 1.0f;
    gViConfigYScale = 1.0f;



    osSyncPrintf("mainproc execution start\n"); // "Start running"
    gAppNmiBufferPtr = (PreNmiBuff*)osAppNmiBuffer;
    SysCfb_Init(0);

    func_800636C0();

    R_ENABLE_ARENA_DBG = 0;

    AudioMgr_Init(&gAudioMgr, NULL, NULL, 0xA, NULL, NULL);

    main_func();
}

int main(int argc, char** argv)
{
	std::vector<std::string> commands;
	for(int i = 1; i < argc; i++)
		commands.push_back(argv[i]);

	ParseCommandLineArguments(commands);
	run();
}

#if defined(_MSC_VER)
#include <string.h>

void bzero(void* __s, size_t __n)
{
    memset(__s, '\0', __n);
}

void bcopy(void* __s, void* __d, size_t __n)
{
    memmove(__d, __s, __n);
}
#endif

#define INTERNAL_SRC_BOOT_Z_STD_DMA_C
#include "global.h"
#include "vt.h"
#include "sched.h"
#include "ultra64/pi.h"
#include "z64dma.h"

StackEntry sDmaMgrStackInfo;
OSMesgQueue sDmaMgrMsgQueue;
OSMesg sDmaMgrMsgs[0x20];
OSThread sDmaMgrThread;
u8 sDmaMgrStack[0x500];
const char* sDmaMgrCurFileName;
s32 sDmaMgrCurFileLine;

u32 D_80009460 = 0;
u32 gDmaMgrDmaBuffSize = 0x2000;
u32 sDmaMgrDataExistError = 0;

// dmadata filenames
#define DEFINE_DMA_ENTRY(name) #name,

#undef DEFINE_DMA_ENTRY

#include <string.h>
#include "def/string.h"
#include "def/z_std_dma.h"

s32 DmaMgr_CompareName(const char* name1, const char* name2) {
    return strcmp(name1, name2);
}

s32 DmaMgr_DmaRomToRam(void* rom, void* ram, uintptr_t size) {
    memcpy(ram, rom, size);
    return 0;
}

s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction) {
    return 0;
}

void DmaMgr_DmaFromDriveRom(void* ram, void* rom, u32 size) {
    return;
}

void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc) {
}

const char* DmaMgr_GetFileNameImpl(void* vrom) {
    return NULL;
}

const char* DmaMgr_GetFileName(void* vrom) {
    return NULL;
}

void DmaMgr_ProcessMsg(DmaRequest* req) {
}

void DmaMgr_ThreadEntry(void* arg0) {
}

s32 DmaMgr_SendRequestImpl(DmaRequest* req, void* ram, void* vrom, uintptr_t size, u32 unk, OSMesgQueue* queue,
                           OSMesg msg) {
    memcpy(ram, vrom, size);
    return 0;
}

s32 DmaMgr_SendRequest0(void* ram, void* vrom, uintptr_t size) {
    memcpy(ram, vrom, size);
    return 0;
}

void DmaMgr_Init(void) {
}

s32 DmaMgr_SendRequest2(DmaRequest* req, void* ram, void* vrom, uintptr_t size, u32 unk5, OSMesgQueue* queue,
                        OSMesg msg,
                        const char* file, s32 line) {
    memcpy(ram, vrom, size);
    return 0;
}

s32 DmaMgr_SendRequest1(void* ram0, void* vrom, uintptr_t size, const char* file, s32 line) {
    memcpy(ram0, vrom, size);
    return 0;
}

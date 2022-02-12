#define INTERNAL_SRC_CODE_Z_SS_SRAM_C
#include "ultra64.h"
#include "global.h"
#include "def/createmesgqueue.h"
#include "def/epidma.h"
#include "def/pimgr.h"
#include "def/recvmesg.h"
#include "def/z_sram.h"
#include "def/z_ss_sram.h"

typedef struct {
    /* 0x00 */ OSPiHandle piHandle;
    /* 0x74 */ OSIoMesg ioMesg;
    /* 0x8C */ OSMesgQueue mesgQ;
} SsSramContext; // size = 0xA4

SsSramContext sSsSramContext = { 0 };

void SsSram_Init(void* addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration,
                 u8 handlePulse, u32 handleSpeed) {
}

void SsSram_Dma(void* dramAddr, size_t size, s32 direction) {
}

/*
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction) {
}
*/

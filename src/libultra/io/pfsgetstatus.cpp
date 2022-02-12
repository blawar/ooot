#define INTERNAL_SRC_LIBULTRA_IO_PFSGETSTATUS_C
#include "ultra64.h"
#include "global.h"
#include "def/pfsgetstatus.h"

OSPifRam gPifMempakBuf;

s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel) {
    return 0;
}

void __osPfsRequestOneChannel(s32 channel, u8 poll) {
}

void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData) {
}

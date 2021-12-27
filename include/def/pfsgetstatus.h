#pragma once

extern OSPifRam gPifMempakBuf;

#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSGETSTATUS_C
void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData);
s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
#else
void __osPfsGetOneChannelData(s32 channel, struct OSContStatus* contData);
s32 __osPfsGetStatus(struct OSMesgQueue* queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
#endif

#pragma once
struct OSContStatus;
struct OSMesgQueue;
struct OSPifRam;

extern OSPifRam gPifMempakBuf;

void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData);
s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);

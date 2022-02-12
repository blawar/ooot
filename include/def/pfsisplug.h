#pragma once
struct OSContStatus;
struct OSMesgQueue;

void __osPfsGetInitData(u8* pattern, OSContStatus* contData);
void __osPfsRequestData(u8 poll);
s32 osPfsIsPlug(OSMesgQueue* mq, u8* pattern);

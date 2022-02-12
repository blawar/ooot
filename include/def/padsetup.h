#pragma once
struct OSMesgQueue;
struct OSContStatus;

s32 PadSetup_Init(OSMesgQueue* mq, u8* outMask, OSContStatus* status);

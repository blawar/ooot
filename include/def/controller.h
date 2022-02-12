#pragma once
struct OSContStatus;
struct OSMesgQueue;
struct OSPifRam;

extern u8 __osContLastPoll;
extern u8 __osMaxControllers;
extern OSPifRam __osPifInternalBuff;

void __osContGetInitData(u8* ctl_present_bitfield, OSContStatus* status);
void __osPackRequestData(u8 poll);
s32 osContInit(OSMesgQueue* mq, u8* ctl_present_bitfield, OSContStatus* status);

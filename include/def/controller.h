#pragma once

extern u8 __osContLastPoll;
extern u8 __osMaxControllers;
extern OSPifRam __osPifInternalBuff;

#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTROLLER_C
void __osContGetInitData(u8* ctl_present_bitfield, OSContStatus* status);
void __osPackRequestData(u8 poll);
s32 osContInit(OSMesgQueue* mq, u8* ctl_present_bitfield, OSContStatus* status);
#else
void __osContGetInitData(u8* ctl_present_bitfield, struct OSContStatus* status);
void __osPackRequestData(u8 poll);
s32 osContInit(struct OSMesgQueue* mq, u8* ctl_present_bitfield, struct OSContStatus* status);
#endif

#pragma once
struct OSMesgQueue;

extern s32 __osPfsLastChannel;

s32 __osContRamRead(OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);

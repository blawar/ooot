#pragma once
struct OSPfs;
struct OSMesgQueue;

s32 __osPfsCheckRamArea(OSPfs* pfs);
s32 osPfsInitPak(OSMesgQueue* mq, OSPfs* pfs, s32 channel);

#pragma once
struct OSMesgQueue;
struct OSPiHandle;

extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern OSPiHandle* __osCurrentHandle[];
extern OSPiHandle* __osPiTable;

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);

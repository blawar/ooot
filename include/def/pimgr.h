#pragma once

extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern OSPiHandle* __osCurrentHandle[];
extern OSPiHandle* __osPiTable;

#ifdef INTERNAL_SRC_LIBULTRA_IO_PIMGR_C
void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
#else
void osCreatePiManager(OSPri pri, struct OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
#endif

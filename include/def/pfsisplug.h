#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSISPLUG_C
void __osPfsGetInitData(u8* pattern, OSContStatus* contData);
void __osPfsRequestData(u8 poll);
s32 osPfsIsPlug(OSMesgQueue* mq, u8* pattern);
#else
void __osPfsGetInitData(u8* pattern, struct OSContStatus* contData);
void __osPfsRequestData(u8 poll);
s32 osPfsIsPlug(struct OSMesgQueue* mq, u8* pattern);
#endif

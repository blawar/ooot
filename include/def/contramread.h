#pragma once

extern s32 __osPfsLastChannel;

#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTRAMREAD_C
s32 __osContRamRead(OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);
#else
s32 __osContRamRead(struct OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);
#endif

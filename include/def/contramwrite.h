#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTRAMWRITE_C
s32 __osContRamWrite(OSMesgQueue* mq, s32 channel, u16 address, u8* buffer, s32 force);
#else
s32 __osContRamWrite(struct OSMesgQueue* mq, s32 channel, u16 address, u8* buffer, s32 force);
#endif

#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_CRC_C
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8* data);
#else
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8* data);
#endif

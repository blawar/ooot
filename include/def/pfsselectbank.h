#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSSELECTBANK_C
s32 __osPfsSelectBank(OSPfs* pfs, u8 bank);
#else
s32 __osPfsSelectBank(struct OSPfs* pfs, u8 bank);
#endif

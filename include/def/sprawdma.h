#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_SPRAWDMA_C
s32 __osSpRawStartDma(s32 direction, void* devAddr, void* dramAddr, u32 size);
#else
s32 __osSpRawStartDma(s32 direction, void* devAddr, void* dramAddr, u32 size);
#endif

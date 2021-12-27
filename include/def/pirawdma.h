#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PIRAWDMA_C
s32 __osPiRawStartDma(s32 dir, u32 cartAddr, void* dramAddr, size_t size);
#else
s32 __osPiRawStartDma(s32 dir, u32 cartAddr, void* dramAddr, size_t size);
#endif

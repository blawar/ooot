#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_EPIRAWDMA_C
s32 __osEPiRawStartDma(OSPiHandle* handle, s32 direction, u32 cartAddr, void* dramAddr, size_t size);
#else
s32 __osEPiRawStartDma(struct OSPiHandle* handle, s32 direction, u32 cartAddr, void* dramAddr, size_t size);
#endif

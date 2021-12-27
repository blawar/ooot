#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_EPIDMA_C
s32 osEPiStartDma(OSPiHandle* handle, OSIoMesg* mb, s32 direction);
#else
s32 osEPiStartDma(struct OSPiHandle* handle, struct OSIoMesg* mb, s32 direction);
#endif

#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_EPIRAWWRITE_C
s32 __osEPiRawWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
#else
s32 __osEPiRawWriteIo(struct OSPiHandle* handle, u32 devAddr, u32 data);
#endif

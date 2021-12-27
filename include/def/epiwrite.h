#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_EPIWRITE_C
s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
#else
s32 osEPiWriteIo(struct OSPiHandle* handle, u32 devAddr, u32 data);
#endif

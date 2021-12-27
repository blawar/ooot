#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_EPIRAWREAD_C
s32 __osEPiRawReadIo(OSPiHandle* handle, u32 devAddr, u32* data);
#else
s32 __osEPiRawReadIo(struct OSPiHandle* handle, u32 devAddr, u32* data);
#endif

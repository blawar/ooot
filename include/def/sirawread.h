#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_SIRAWREAD_C
s32 __osSiRawReadIo(void* devAddr, u32* dst);
#else
s32 __osSiRawReadIo(void* devAddr, u32* dst);
#endif

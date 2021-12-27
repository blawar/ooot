#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_CARTROMINIT_C
OSPiHandle* osCartRomInit(void);
#else
struct OSPiHandle* osCartRomInit(void);
#endif

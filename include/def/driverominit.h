#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_DRIVEROMINIT_C
OSPiHandle* osDriveRomInit(void);
#else
struct OSPiHandle* osDriveRomInit(void);
#endif

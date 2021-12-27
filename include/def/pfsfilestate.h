#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSFILESTATE_C
s32 osPfsFileState(OSPfs* pfs, s32 fileNo, OSPfsState* state);
#else
s32 osPfsFileState(struct OSPfs* pfs, s32 fileNo, struct OSPfsState* state);
#endif

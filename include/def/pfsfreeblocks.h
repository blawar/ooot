#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSFREEBLOCKS_C
s32 osPfsFreeBlocks(OSPfs* pfs, s32* leftoverBytes);
#else
s32 osPfsFreeBlocks(struct OSPfs* pfs, s32* leftoverBytes);
#endif

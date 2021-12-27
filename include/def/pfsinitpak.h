#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSINITPAK_C
s32 __osPfsCheckRamArea(OSPfs* pfs);
s32 osPfsInitPak(OSMesgQueue* mq, OSPfs* pfs, s32 channel);
#else
s32 __osPfsCheckRamArea(struct OSPfs* pfs);
s32 osPfsInitPak(struct OSMesgQueue* mq, struct OSPfs* pfs, s32 channel);
#endif

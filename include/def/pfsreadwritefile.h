#pragma once

extern __OSInode __osPfsInodeCache;

#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSREADWRITEFILE_C
s32 __osPfsGetNextPage(OSPfs* pfs, u8* bank, __OSInode* inode, __OSInodeUnit* page);
s32 osPfsReadWriteFile(OSPfs* pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8* data);
#else
s32 __osPfsGetNextPage(struct OSPfs* pfs, u8* bank, struct __OSInode* inode, __OSInodeUnit* page);
s32 osPfsReadWriteFile(struct OSPfs* pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8* data);
#endif

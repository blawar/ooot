#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSDELETEFILE_C
s32 __osPfsReleasePages(OSPfs* pfs, __OSInode* inode, u8 initialPage, u8 bank, __OSInodeUnit* finalPage);
s32 osPfsDeleteFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName);
#else
s32 __osPfsReleasePages(struct OSPfs* pfs, struct __OSInode* inode, u8 initialPage, u8 bank, __OSInodeUnit* finalPage);
s32 osPfsDeleteFile(struct OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName);
#endif

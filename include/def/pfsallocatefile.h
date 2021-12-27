#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSALLOCATEFILE_C
s32 __osPfsDeclearPage(OSPfs* pfs, __OSInode* inode, s32 fileSizeInPages, s32* startPage, u8 bank, s32* decleared, s32* finalPage);
s32 osPfsAllocateFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo);
#else
s32 __osPfsDeclearPage(struct OSPfs* pfs, struct __OSInode* inode, s32 fileSizeInPages, s32* startPage, u8 bank, s32* decleared, s32* finalPage);
s32 osPfsAllocateFile(struct OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo);
#endif

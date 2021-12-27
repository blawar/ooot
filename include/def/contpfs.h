#pragma once

extern u8 __osPfsInodeCacheBank;

#ifdef INTERNAL_SRC_LIBULTRA_IO_CONTPFS_C
s32 __osCheckId(OSPfs* pfs);
s32 __osCheckPackId(OSPfs* pfs, __OSPackId* check);
s32 __osGetId(OSPfs* pfs);
s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum);
s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank);
s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid);
u16 __osSumcalc(u8* ptr, s32 length);
#else
s32 __osCheckId(struct OSPfs* pfs);
s32 __osCheckPackId(struct OSPfs* pfs, struct __OSPackId* check);
s32 __osGetId(struct OSPfs* pfs);
s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum);
s32 __osPfsRWInode(struct OSPfs* pfs, struct __OSInode* inode, u8 flag, u8 bank);
s32 __osRepairPackId(struct OSPfs* pfs, struct __OSPackId* badid, struct __OSPackId* newid);
u16 __osSumcalc(u8* ptr, s32 length);
#endif

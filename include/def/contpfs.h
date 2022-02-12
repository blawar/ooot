#pragma once
struct OSPfs;
struct __OSPackId;
struct __OSInode;

extern u8 __osPfsInodeCacheBank;

s32 __osCheckId(OSPfs* pfs);
s32 __osCheckPackId(OSPfs* pfs, __OSPackId* check);
s32 __osGetId(OSPfs* pfs);
s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum);
s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank);
s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid);
u16 __osSumcalc(u8* ptr, s32 length);

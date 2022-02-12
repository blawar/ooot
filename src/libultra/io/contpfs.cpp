#define INTERNAL_SRC_LIBULTRA_IO_CONTPFS_C
#include "ultra64.h"
#include "global.h"
#include "def/contpfs.h"
#include "def/pfsreadwritefile.h"

s32 __osPfsInodeCacheChannel = -1;
u8 __osPfsInodeCacheBank = 250;

u16 __osSumcalc(u8* ptr, s32 length) {
    return 0xFFFF;
}

s32 __osIdCheckSum(u16* ptr, u16* checkSum, u16* idSum) {
    return 0;
}

s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid) {
    return 0;
}

s32 __osCheckPackId(OSPfs* pfs, __OSPackId* check) {
    return 0;
}

s32 __osGetId(OSPfs* pfs) {
    return 0;
}

s32 __osCheckId(OSPfs* pfs) {
    return 0;
}

s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank) {
    return 0;
}

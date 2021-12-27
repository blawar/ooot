#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSFINDFILE_C
s32 osPfsFindFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* fileNo);
#else
s32 osPfsFindFile(struct OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* fileNo);
#endif

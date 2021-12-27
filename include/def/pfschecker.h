#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_IO_PFSCHECKER_C
s32 func_80105788(OSPfs* pfs, __OSInodeCache* cache);
s32 func_80105A60(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache);
s32 osPfsChecker(OSPfs* pfs);
#else
s32 func_80105788(struct OSPfs* pfs, struct __OSInodeCache* cache);
s32 func_80105A60(struct OSPfs* pfs, __OSInodeUnit fpage, struct __OSInodeCache* cache);
s32 osPfsChecker(struct OSPfs* pfs);
#endif

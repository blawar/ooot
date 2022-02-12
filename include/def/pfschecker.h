#pragma once
struct OSPfs;
struct __OSInodeCache;

s32 func_80105788(OSPfs* pfs, __OSInodeCache* cache);
s32 func_80105A60(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache);
s32 osPfsChecker(OSPfs* pfs);

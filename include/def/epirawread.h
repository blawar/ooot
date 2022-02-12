#pragma once
struct OSPiHandle;

s32 __osEPiRawReadIo(OSPiHandle* handle, u32 devAddr, u32* data);

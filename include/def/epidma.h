#pragma once
struct OSPiHandle;
struct OSIoMesg;

s32 osEPiStartDma(OSPiHandle* handle, OSIoMesg* mb, s32 direction);

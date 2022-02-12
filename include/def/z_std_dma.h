#pragma once
struct OSPiHandle;
struct OSIoMesg;
struct DmaRequest;
struct OSMesgQueue;

extern u32 D_80009460;
extern u32 gDmaMgrDmaBuffSize;

s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
s32 DmaMgr_DmaRomToRam(Pointer rom, Pointer ram, size_t size);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileName(Pointer vrom);
const char* DmaMgr_GetFileNameImpl(Pointer vrom);
void DmaMgr_Init(void);
void DmaMgr_ProcessMsg(DmaRequest* req);
s32 DmaMgr_SendRequest0(Pointer ram, Pointer vrom, u32 size);
s32 DmaMgr_SendRequest1(Pointer ram0, Pointer vrom, size_t size, const char* file, s32 line);
s32 DmaMgr_SendRequest2(DmaRequest* req, Pointer ram, Pointer vrom, size_t size, u32 unk5, OSMesgQueue* queue, OSMesg msg, const char* file, s32 line);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, Pointer ram, Pointer vrom, size_t size, u32 unk, OSMesgQueue* queue, OSMesg msg);
void DmaMgr_ThreadEntry(void* arg0);

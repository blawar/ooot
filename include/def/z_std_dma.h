#pragma once

extern u32 D_80009460;
extern u32 gDmaMgrDmaBuffSize;

#ifdef INTERNAL_SRC_BOOT_Z_STD_DMA_C
s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
s32 DmaMgr_DmaRomToRam(u32 rom, u32 ram, u32 size);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileName(u32 vrom);
const char* DmaMgr_GetFileNameImpl(u32 vrom);
void DmaMgr_Init(void);
void DmaMgr_ProcessMsg(DmaRequest* req);
s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size);
s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line);
s32 DmaMgr_SendRequest2(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, OSMesgQueue* queue, OSMesg msg, const char* file, s32 line);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, OSMesgQueue* queue, OSMesg msg);
void DmaMgr_ThreadEntry(void* arg0);
#else
s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DmaHandler(struct OSPiHandle* pihandle, struct OSIoMesg* mb, s32 direction);
s32 DmaMgr_DmaRomToRam(u32 rom, u32 ram, u32 size);
void DmaMgr_Error(struct DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileName(u32 vrom);
const char* DmaMgr_GetFileNameImpl(u32 vrom);
void DmaMgr_Init(void);
void DmaMgr_ProcessMsg(struct DmaRequest* req);
s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size);
s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line);
s32 DmaMgr_SendRequest2(struct DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, struct OSMesgQueue* queue, OSMesg msg, const char* file, s32 line);
s32 DmaMgr_SendRequestImpl(struct DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, struct OSMesgQueue* queue, OSMesg msg);
void DmaMgr_ThreadEntry(void* arg0);
#endif

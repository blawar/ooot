#ifndef ULTRA64_PI_H
#define ULTRA64_PI_H

#include "message.h"

struct __OSBlockInfo {
    /* 0x00 */ u32 errStatus;
    /* 0x04 */ void* dramAddr;
    /* 0x08 */ void* C2Addr;
    /* 0x0C */ u32 sectorSize;
    /* 0x10 */ u32 C1ErrNum;
    /* 0x14 */ u32 C1ErrSector[4];
}; // size = 0x24

struct __OSTranxInfo {
    /* 0x00 */ u32 cmdType;
    /* 0x04 */ u16 transferMode;
    /* 0x06 */ u16 blockNum;
    /* 0x08 */ s32 sectorNum;
    /* 0x0C */ Pointer devAddr;
    /* 0x10 */ u32 bmCtlShadow;
    /* 0x14 */ u32 seqCtlShadow;
    /* 0x18 */ __OSBlockInfo block[2];
}; // size = 0x60

struct OSPiHandle {
    /* 0x00 */ struct OSPiHandle* next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 relDuration;
    /* 0x08 */ u8 pulse;
    /* 0x09 */ u8 domain;
    /* 0x0C */ Pointer baseAddress;
    /* 0x10 */ u32 speed;
    /* 0x14 */ __OSTranxInfo transferInfo;
}; // size = 0x74

struct OSPiInfo {
    /* 0x00 */ u8 type;
    /* 0x04 */ Pointer address;
}; // size = 0x08

struct OSIoMesgHdr {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8 pri;
    /* 0x03 */ u8 status;
    /* 0x04 */ OSMesgQueue* retQueue;
}; // size = 0x08

struct OSIoMesg {
    /* 0x00 */ OSIoMesgHdr hdr;
	/* 0x08 */ Pointer dramAddr;
    /* 0x0C */ Pointer devAddr;
    /* 0x10 */ size_t size;
    /* 0x14 */ OSPiHandle* piHandle;
}; // size = 0x18

#define OS_READ     0 // device -> RDRAM
#define OS_WRITE    1 // device <- RDRAM
#define OS_OTHERS   2 // for disk drive transfers

#define PI_DOMAIN1  0
#define PI_DOMAIN2  1

#define OS_MESG_TYPE_LOOPBACK   10
#define OS_MESG_TYPE_DMAREAD    11
#define OS_MESG_TYPE_DMAWRITE   12
#define OS_MESG_TYPE_VRETRACE   13
#define OS_MESG_TYPE_COUNTER    14
#define OS_MESG_TYPE_EDMAREAD   15
#define OS_MESG_TYPE_EDMAWRITE  16

#define OS_MESG_PRI_NORMAL  0
#define OS_MESG_PRI_HIGH    1

#define DEVICE_TYPE_CART    0   /* ROM cartridge */
#define DEVICE_TYPE_BULK    1   /* ROM bulk */
#define DEVICE_TYPE_64DD    2   /* 64 Disk Drive */
#define DEVICE_TYPE_SRAM    3   /* SRAM */
#define DEVICE_TYPE_INIT    7   /* initial value */

#endif

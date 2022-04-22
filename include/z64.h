#pragma once

#include "global.h"
#include "ultra64/types.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define REGION_NULL 0
#define REGION_US 1
#define REGION_JP 2
#define REGION_EU 3

/*
#define Z_PRIORITY_MAIN        10
#define Z_PRIORITY_GRAPH       11
#define Z_PRIORITY_AUDIOMGR    12
#define Z_PRIORITY_PADMGR      14
#define Z_PRIORITY_SCHED       15
#define Z_PRIORITY_DMAMGR      16
#define Z_PRIORITY_IRQMGR      17
*/

// NOTE: Once we start supporting other builds, this can be changed with an ifdef
#define REGION_NATIVE REGION_EU


struct SequenceContext {
    /* 0x00 */ u8   seqId;
    /* 0x01 */ u8   natureAmbienceId;
}; // size = 0x2



struct ElfMessage {
    /* 0x00 */ u8 byte0;
    /* 0x01 */ u8 byte1;
    /* 0x02 */ u8 byte2;
    /* 0x03 */ u8 byte3;
}; // size = 0x4


struct StackEntry {
    /* 0x00 */ struct StackEntry* next;
    /* 0x04 */ struct StackEntry* prev;
    /* 0x08 */ uintptr_t head;
    /* 0x0C */ uintptr_t tail;
    /* 0x10 */ u32 initValue;
    /* 0x14 */ s32 minSpace;
    /* 0x18 */ const char* name;
};

enum StackStatus {
    STACK_STATUS_OK = 0,
    STACK_STATUS_WARNING = 1,
    STACK_STATUS_OVERFLOW = 2
};

struct ISVDbg {
    /* 0x00 */ u32 magic; // IS64
    /* 0x04 */ u32 get;
    /* 0x08 */ u8 unk_08[0x14-0x08];
    /* 0x14 */ u32 put;
    /* 0x18 */ u8 unk_18[0x20-0x18];
    /* 0x20 */ u8 data[0x10000-0x20];
};

typedef struct {
    /* 0x00 */ char name[0x18];
    /* 0x18 */ u32 mediaFormat;
    /* 0x1C */ union {
        struct {
            u16 cartId;
            u8 countryCode;
            u8 version;
        };
        u32 regionInfo;
    };
} LocaleCartInfo; // size = 0x20



// ========================



struct OverlayRelocationSection {
    /* 0x00 */ u32 textSize;
    /* 0x04 */ u32 dataSize;
    /* 0x08 */ u32 rodataSize;
    /* 0x0C */ u32 bssSize;
    /* 0x10 */ u32 nRelocations;
    /* 0x14 */ u32 relocations[1];
}; // size >= 0x18

#define NUM_SEGMENTS        (16)
extern uintptr_t gSegments[NUM_SEGMENTS];

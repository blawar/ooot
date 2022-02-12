#pragma once

#define DEFINE_OBJECT(_0, enum) enum,
#define DEFINE_OBJECT_NULL(_0, enum) enum,
#define DEFINE_OBJECT_UNSET(enum) enum,

enum ObjectID {
    #include "tables/object_table.h"
    /* 0x0192 */ OBJECT_ID_MAX
};

#undef DEFINE_OBJECT
#undef DEFINE_OBJECT_NULL
#undef DEFINE_OBJECT_UNSET

struct ObjectContext {
    void* spaceStart;
    void* spaceEnd; // original name: "endSegment"
    u8 num;         // number of objects in bank
    u8 unk_09;
    u8 mainKeepIndex; // "gameplay_keep" index in bank
    u8 subKeepIndex;  // "gameplay_field_keep" or "gameplay_dangeon_keep" index in bank
    s16* objectEntry;
}; // size = 0x518

extern u32 gObjectTableSize;
extern RomFile gObjectTable[OBJECT_ID_MAX];

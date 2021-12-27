#pragma once

typedef struct {
    /* 0x00 */ void* vromStart;
    /* 0x04 */ void* vromEnd;
} RomFile; // size = 0x8

typedef struct {
    /* 0x00 */ RomFile file;
    /* 0x08 */ RomFile palette;
} SkyboxFile; // size = 0x10

#define ROM_FILE(name) \
    { (uintptr_t) name, (uintptr_t)name + sizeof(name) }
#define ROM_FILE_EMPTY(name) \
    { (uintptr_t) _##name##SegmentRomStart, (uintptr_t)_##name##SegmentRomStart }
#define ROM_FILE_UNSET \
    { 0 }

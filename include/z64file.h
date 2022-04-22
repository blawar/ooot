#pragma once

struct RomFile {
    /* 0x00 */ Pointer vromStart;
    /* 0x04 */ Pointer vromEnd;
}; // size = 0x8

struct SkyboxFile {
    /* 0x00 */ RomFile file;
    /* 0x08 */ RomFile palette;
}; // size = 0x10

#define ROM_FILE(name) \
    { (uintptr_t) name, (uintptr_t)name + sizeof(name) }
#define ROM_FILE_EMPTY(name) \
    { (uintptr_t) _##name##SegmentRomStart, (uintptr_t)_##name##SegmentRomStart }
#define ROM_FILE_UNSET \
    { 0 }

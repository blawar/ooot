#pragma once

struct Color_RGB8 {
    u8 r, g, b;
};

struct Color_RGBA8 {
    u8 r, g, b, a;
};

// only use when necessary for alignment purposes
typedef union {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Color_RGBA8_u32;

struct Color_RGBAf {
    f32 r, g, b, a;
};

typedef union {
    struct {
        u16 r : 5;
        u16 g : 5;
        u16 b : 5;
        u16 a : 1;
    };
    u16 rgba;
} Color_RGBA16;


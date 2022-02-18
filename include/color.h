#pragma once
#include "macros.h"

struct Color_RGB8 {
    u8 r, g, b;
};

struct Color_RGBA8 {
    Color_RGBA8() = default;
    Color_RGBA8(u8 r_, u8 g_, u8 b_, u8 a_) : r(r_), g(g_), b(b_), a(a_) {}

    explicit operator u32 () {
        return BE32(RGBA8(r, g, b, a));
    }

    u8 r, g, b, a;
};

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


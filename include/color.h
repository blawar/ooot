#pragma once

struct Color_RGB8 {
    u8 r, g, b;
};

struct Color_RGBA8 {
    u8 r, g, b, a;
};

// only use when necessary for alignment purposes
union Color_RGBA8_u32 {
    Color_RGBA8_u32() = default;
    Color_RGBA8_u32(u32 color) : abgr(SWAP32(color)) {}

    void operator = (u32 color) {
        abgr = SWAP32(color);
    }

    operator u32 () const {
        return abgr;
    }

    struct {
        u8 a, b, g, r;
    };
private:
    u32 abgr;
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


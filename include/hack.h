#pragma once

struct CollisionPoly // TODO FIX HACK, remove this when converting to c++
{
    /* 0x00 */ u16 type;
    union
    {
        u16 vtxData[3];
        struct
        {
            /* 0x02 */ u16 flags_vIA; // 0xE000 is poly exclusion flags (xpFlags), 0x1FFF is vtxId
            /* 0x04 */ u16 flags_vIB; // 0xE000 is flags, 0x1FFF is vtxId
                                      // 0x2000 = poly IsConveyor surface
            /* 0x06 */ u16 vIC;
        };
    };
    /* 0x08 */ Vec3s normal; // Unit normal vector
                             // Value ranges from -0x7FFF to 0x7FFF, representing -1.0 to 1.0; 0x8000 is invalid

    /* 0x0E */ s16 dist; // Plane distance from origin along the normal
}; // size = 0x10

struct OcarinaStaff
{
    u8 noteIdx;
    u8 state;   // original name: "status"
    u8 pos;     // original name: "locate"
};

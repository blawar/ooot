#pragma once
#include "ultra64/types.h"
#include "z64math.h"
#include "ultra64/gbi.h"

struct Viewport {
   /* 0x0000 */ s32 topY;    // uly (upper left y)
   /* 0x0004 */ s32 bottomY; // lry (lower right y)
   /* 0x0008 */ s32 leftX;   // ulx (upper left x)
   /* 0x000C */ s32 rightX;  // lrx (lower right x)
}; // size = 0x10

struct View {
    /* 0x0000 */ s32    magic; // string literal "VIEW" / 0x56494557
    /* 0x0004 */ struct GraphicsContext* gfxCtx;
    /* 0x0008 */ Viewport viewport;
    /* 0x0018 */ f32    fovy;  // vertical field of view in degrees
    /* 0x001C */ f32    zNear; // distance to near clipping plane
    /* 0x0020 */ f32    zFar;  // distance to far clipping plane
    /* 0x0024 */ f32    scale; // scale for matrix elements
    /* 0x0028 */ Vec3f  eye;
    /* 0x0034 */ Vec3f  lookAt;
    /* 0x0040 */ Vec3f  up;
    /* 0x0050 */ Vp     vp;
    /* 0x0060 */ Mtx    projection;
    /* 0x00A0 */ Mtx    viewing;
    /* 0x00E0 */ Mtx*   projectionPtr;
    /* 0x00E4 */ Mtx*   viewingPtr;
    /* 0x00E8 */ Vec3f  unk_E8;
    /* 0x00F4 */ Vec3f  unk_F4;
    /* 0x0100 */ f32    unk_100;
    /* 0x0104 */ Vec3f  unk_104;
    /* 0x0110 */ Vec3f  unk_110;
    /* 0x011C */ u16    normal; // used to normalize the projection matrix
    /* 0x0120 */ s32    flags;
    /* 0x0124 */ s32    unk_124;
}; // size = 0x128

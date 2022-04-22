#pragma once
#include "ultra64/gbi.h"
#include "ultra64/types.h"
#include "z64math.h"

struct Viewport
{
	/* 0x0000 */ s32 topY = 0;	  // uly (upper left y)
	/* 0x0004 */ s32 bottomY = 0; // lry (lower right y)
	/* 0x0008 */ s32 leftX = 0;	  // ulx (upper left x)
	/* 0x000C */ s32 rightX = 0;  // lrx (lower right x)
};				  // size = 0x10

struct View
{
	/* 0x0000 */ s32 magic = 0; // string literal "VIEW" / 0x56494557
	/* 0x0004 */ GraphicsContext* gfxCtx = nullptr;
	/* 0x0008 */ Viewport viewport;
	/* 0x0018 */ f32 fovy = 0;	// vertical field of view in degrees
	/* 0x001C */ f32 zNear = 0; // distance to near clipping plane
	/* 0x0020 */ f32 zFar = 0;	// distance to far clipping plane
	/* 0x0024 */ f32 scale = 0; // scale for matrix elements
	/* 0x0028 */ Vec3f eye = {0};
	/* 0x0034 */ Vec3f lookAt = {0};
	/* 0x0040 */ Vec3f up = {0};
	/* 0x0050 */ Vp vp = {0};
	/* 0x0060 */ Mtx projection = {0};
	/* 0x00A0 */ Mtx viewing = {0};
	/* 0x00E0 */ Mtx* projectionPtr = nullptr;
	/* 0x00E4 */ Mtx* viewingPtr = nullptr;
	/* 0x00E8 */ Vec3f unk_E8 = {0};
	/* 0x00F4 */ Vec3f unk_F4 = {0};
	/* 0x0100 */ f32 unk_100 = 0;
	/* 0x0104 */ Vec3f unk_104 = {0};
	/* 0x0110 */ Vec3f unk_110 = {0};
	/* 0x011C */ u16 normal = 0; // used to normalize the projection matrix
	/* 0x0120 */ s32 flags = 0;
	/* 0x0124 */ s32 unk_124 = 0;
}; // size = 0x128

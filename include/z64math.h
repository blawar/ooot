#pragma once
#include <math.h>
#include "framerate.h"
#include "ultra64/types.h"
#include "globalctx.h"

#define VEC_SET(V, X, Y, Z)                                                                                                                                                                                                                                    \
	(V).x = (X);                                                                                                                                                                                                                                           \
	(V).y = (Y);                                                                                                                                                                                                                                           \
	(V).z = (Z)

enum MatrixMode
{
	MTXMODE_NEW,  // generates a new matrix
	MTXMODE_APPLY // applies transformation to the current matrix
};

struct Vec2f
{
	f32 x, y;
}; // size = 0x08

struct Vec3f
{
	f32 x, y, z;	
}; // size = 0x0C

struct Vec3us
{
	u16 x, y, z;
}; // size = 0x06

struct Vec3s
{
	s16 x, y, z;
}; // size = 0x06

struct Vec3i
{
	s32 x, y, z;
}; // size = 0x0C

struct VecRot
{
	VecRot();
	VecRot(const Rotation& x, const Rotation& y, const Rotation& z);
	VecRot(const VecRot& vec);
	VecRot(const Vec3s& vec);
	VecRot(const Vec3f& vec);
	operator Vec3s() const;
	operator Vec3f() const;
	Rotation x, y, z;
};
/*
struct VecPosF
{
	VecPosF();
	VecPosF(const Rotation& x, const Rotation& y, const Rotation& z);
	VecPosF(const VecPosF& vec);
	VecPosF(const Vec3s& vec);
	VecPosF(const Vec3f& vec);
	operator Vec3s() const;
	operator Vec3f() const;
	CounterF x, y, z;
};
*/
struct VecCounterF
{
	VecCounterF();
	VecCounterF(const CounterF& x, const CounterF& y, const CounterF& z);
	VecCounterF(const Vec3s& vec);
	VecCounterF(const Vec3f& vec);
	VecCounterF(Vec3f* vec);
	VecCounterF(const Vec3f* vec);
	//Vec3f* operator&();
	//VecPosF(const Vec3f* vec);
	operator Vec3s() const;
	operator Vec3f() const;
	operator Vec3f*();
	operator Vec3f*() const;
	CounterF x, y, z;
 };

typedef VecRot VecPos;
typedef Vec3f VecRotF;
typedef Vec3f VecPosF;

struct Sphere16
{
	Vec3s center;
	s16 radius;
}; // size = 0x08

struct Spheref
{
	Vec3f center;
	f32 radius;
}; // size = 0x10

struct Plane
{
	Vec3f normal;
	f32 originDist;
}; // size = 0x10

struct TriNorm
{
	Vec3f vtx[3];
	Plane plane;
}; // size = 0x34

struct Cylinder16
{
	/* 0x0000 */ s16 radius;
	/* 0x0002 */ s16 height;
	/* 0x0004 */ s16 yShift;
	/* 0x0006 */ Vec3s pos;
}; // size = 0x0C

struct Cylinderf
{
	/* 0x00 */ f32 radius;
	/* 0x04 */ f32 height;
	/* 0x08 */ f32 yShift;
	/* 0x0C */ Vec3f pos;
}; // size = 0x18

struct InfiniteLine
{
	/* 0x0000 */ Vec3f point;
	/* 0x000C */ Vec3f dir;
}; // size = 0x18

struct Linef
{
	/* 0x0000 */ Vec3f a;
	/* 0x000C */ Vec3f b;
}; // size = 0x18

// Defines a point in the spherical coordinate system
struct VecSph
{
	/* 0x00 */ f32 r;     // radius
	/* 0x04 */ s16 pitch; // polar (zenith) angle
	/* 0x06 */ s16 yaw;   // azimuthal angle
};			      // size = 0x08

struct PosRot
{
	VecPosF pos;
	VecRot rot;
}; // size = 0x14

#define LERP(x, y, scale) (((y) - (x)) * (scale) + (x))
#define LERP32(x, y, scale) ((s32)(((y) - (x)) * (scale)) + (x))
#define LERP16(x, y, scale) ((s16)(((y) - (x)) * (scale)) + (x))
#define F32_LERP(v0, v1, t) ((v0) * (1.0f - (t)) + (v1) * (t))
#define F32_LERPIMP(v0, v1, t) (v0 + ((v1 - v0) * t))
#define F32_LERPIMPINV(v0, v1, t) ((v0) + (((v1) - (v0)) / (t)))
#define BINANG_LERPIMP(v0, v1, t) ((v0) + (s16)(BINANG_SUB((v1), (v0)) * (t)))
#define BINANG_LERPIMPINV(v0, v1, t) ((v0) + BINANG_SUB((v1), (v0)) / (t))

#define VEC3F_LERPIMPDST(dst, v0, v1, t)                                                                                                                                                                                                                       \
	{                                                                                                                                                                                                                                                      \
		(dst)->x = (v0)->x + (((v1)->x - (v0)->x) * t);                                                                                                                                                                                                \
		(dst)->y = (v0)->y + (((v1)->y - (v0)->y) * t);                                                                                                                                                                                                \
		(dst)->z = (v0)->z + (((v1)->z - (v0)->z) * t);                                                                                                                                                                                                \
	}

#define IS_ZERO(f) (fabsf(f) < 0.008f)

// Trig macros
#define DEGF_TO_BINANG(degreesf) (s16)(degreesf * 182.04167f + .5f)
#define RADF_TO_BINANG(radf) (s16)(radf * (32768.0f / M_PI))
#define RADF_TO_DEGF(radf) (radf * (180.0f / M_PI))
#define DEGF_TO_RADF(degf) (degf * (M_PI / 180.0f))
#define BINANG_ROT180(angle) ((s16)(angle - 0x7FFF))
#define BINANG_SUB(a, b) ((s16)(a - b))
#define DEG_TO_RAD(degrees) ((degrees) * (M_PI / 180.0f))
#define BINANG_TO_DEGF(binang) ((f32)binang * (360.0001525f / 65535.0f))
#define BINANG_TO_RAD(binang) (((f32)binang / 32768.0f) * M_PI)

// Vector macros
#define SQXZ(vec) ((vec.x) * (vec.x) + (vec.z) * (vec.z))
#define DOTXZ(vec1, vec2) ((vec1.x) * (vec2.x) + (vec1.z) * (vec2.z))
#define SQXYZ(vec) ((vec.x) * (vec.x) + (vec.y) * (vec.y) + (vec.z) * (vec.z))
#define DOTXYZ(vec1, vec2) ((vec1.x) * (vec2.x) + (vec1.y) * (vec2.y) + (vec1.z) * (vec2.z))

extern Mtx gMtxClear;
extern MtxF gMtxFClear;

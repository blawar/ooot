#define INTERNAL_SRC_LIBULTRA_GU_TRANSLATE_C
#include "global.h"
#include "def/mtxf2l.h"
#include "def/translate.h"

void guTranslateF(f32 m[4][4], f32 x, f32 y, f32 z)
{
	guMtxIdentF(m);
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
}

void guTranslateF(F32 m[4][4], f32 x, f32 y, f32 z)
{
	guMtxIdentF(m);
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
}

void guTranslate(Mtx* m, f32 x, f32 y, f32 z)
{
	MtxF mf;
	guTranslateF(mf.mf, x, y, z);
	guMtxF2L(&mf, m);
}

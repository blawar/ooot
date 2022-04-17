#define INTERNAL_SRC_LIBULTRA_GU_SCALE_C
#include "global.h"
#include "def/mtxf2l.h"
#include "def/scale.h"

void guScaleF(F32 mf[4][4], f32 x, f32 y, f32 z)
{
	guMtxIdentF(mf);
	mf[0][0] = x;
	mf[1][1] = y;
	mf[2][2] = z;
	mf[3][3] = 1.0;
}

void guScale(Mtx* m, f32 x, f32 y, f32 z)
{
	MtxF mf;
	guScaleF(mf.mf, x, y, z);
	guMtxF2L(&mf, m);
}

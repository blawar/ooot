#define INTERNAL_SRC_LIBULTRA_GU_TRANSLATE_C
#include "global.h"
#include "def/mtxf2l.h"
#include "def/translate.h"

void guTranslateF(float m[4][4], float x, float y, float z) {
    guMtxIdentF(m);
    m[3][0] = x;
    m[3][1] = y;
    m[3][2] = z;
}
void guTranslate(Mtx *m, float x, float y, float z) {
    MtxF mf;
    guTranslateF(mf.mf, x, y, z);
    guMtxF2L(&mf, m);
}

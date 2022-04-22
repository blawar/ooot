#define INTERNAL_SRC_LIBULTRA_GU_MTXF2L_C
#include "global.h"
#include "def/mtxf2l.h"
#include "def/string.h"
#include "def/sys_matrix.h"

#ifndef GBI_FLOATS
void guMtxF2L(MtxF* mf, Mtx* m) {
    Matrix_MtxFToMtx(mf, m);
}

void guMtxL2F(MtxF* mf, Mtx* m) {
    Matrix_MtxToMtxF(m, mf);
}
#else
void guMtxF2L(float mf[4][4], Mtx* m) {
    memcpy(m, mf, sizeof(Mtx));
}
#endif

void guMtxIdentF(float mf[4][4]) {
    int r, c;
    for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
            if (r == c) {
                mf[r][c] = 1.0f;
            } else {
                mf[r][c] = 0.0f;
            }
        }
    }
}

void guMtxIdent(Mtx* m) {
#ifndef GBI_FLOATS
    MtxF mf;
    guMtxIdentF(mf.mf);
    guMtxF2L(&mf, m);
#else
    guMtxIdentF(m->m);
#endif
}
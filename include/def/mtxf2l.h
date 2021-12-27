#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_MTXF2L_C
void guMtxF2L(MtxF* m1, Mtx* m2);
void guMtxIdent(Mtx*);
void guMtxIdentF(f32 mf[4][4]);
void guMtxL2F(MtxF* m1, Mtx* m2);
#else
void guMtxF2L(MtxF* m1, struct Mtx* m2);
void guMtxIdent(struct Mtx*);
void guMtxIdentF(f32 mf[4][4]);
void guMtxL2F(MtxF* m1, struct Mtx* m2);
#endif

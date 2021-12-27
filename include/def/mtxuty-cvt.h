#pragma once
#ifdef INTERNAL_SRC_CODE_MTXUTY_CVT_C
void MtxConv_F2L(Mtx* m1, MtxF* m2);
#else
void MtxConv_F2L(struct Mtx* m1, MtxF* m2);
#endif

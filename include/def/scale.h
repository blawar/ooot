#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_SCALE_C
void guScale(Mtx* m, f32 x, f32 y, f32 z);
#else
void guScale(struct Mtx* m, f32 x, f32 y, f32 z);
#endif

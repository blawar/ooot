#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_TRANSLATE_C
void guTranslate(Mtx* m, f32 x, f32 y, f32 z);
#else
void guTranslate(struct Mtx* m, f32 x, f32 y, f32 z);
#endif

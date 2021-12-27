#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_ORTHO_C
void guOrtho(Mtx*, f32, f32, f32, f32, f32, f32, f32);
void guOrthoF(f32[4][4], f32, f32, f32, f32, f32, f32, f32);
#else
void guOrtho(struct Mtx*, f32, f32, f32, f32, f32, f32, f32);
void guOrthoF(f32[4][4], f32, f32, f32, f32, f32, f32, f32);
#endif

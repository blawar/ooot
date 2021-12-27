#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_ROTATE_C
void guRotate(Mtx*, f32 angle, f32 x, f32 y, f32 z);
void guRotateF(f32 m[4][4], f32 a, f32 x, f32 y, f32 z);
#else
void guRotate(struct Mtx*, f32 angle, f32 x, f32 y, f32 z);
void guRotateF(f32 m[4][4], f32 a, f32 x, f32 y, f32 z);
#endif

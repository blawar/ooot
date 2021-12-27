#pragma once
#ifdef INTERNAL_SRC_LIBULTRA_GU_POSITION_C
void guPosition(Mtx*, f32, f32, f32, f32, f32, f32, f32);
void guPositionF(f32 mf[4][4], f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
#else
void guPosition(struct Mtx*, f32, f32, f32, f32, f32, f32, f32);
void guPositionF(f32 mf[4][4], f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
#endif

#pragma once
#include "z64math.h"

void guPerspectiveF(f32 mf[4][4], u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guPerspective(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guMtxIdentF(f32 mf[4][4]);
void guLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guLookAt(Mtx*, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);

void guLookAtHiliteF(f32 mf[4][4], LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                     f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 hiliteWidth,
                     s32 hiliteHeight);
void guLookAtHilite(Mtx* m, LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                    f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 hiliteWidth,
                    s32 hiliteHeight);

void guMtxIdent(Mtx*);
void guPositionF(f32 mf[4][4], f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
void guPosition(Mtx*, f32, f32, f32, f32, f32, f32, f32);

void guRotateF(f32 m[4][4], f32 a, f32 x, f32 y, f32 z);
void guRotate(Mtx*, f32 angle, f32 x, f32 y, f32 z);

void guNormalize(f32* x, f32* y, f32* z);

void guOrthoF(f32[4][4], f32, f32, f32, f32, f32, f32, f32);
void guOrtho(Mtx*, f32, f32, f32, f32, f32, f32, f32);

void guTranslate(Mtx* m, f32 x, f32 y, f32 z);

void guMtxF2L(MtxF* m1, Mtx* m2);
void guMtxL2F(MtxF* m1, Mtx* m2);
void guScale(Mtx* m, f32 x, f32 y, f32 z);


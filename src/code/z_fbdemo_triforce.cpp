#define INTERNAL_SRC_CODE_Z_FBDEMO_TRIFORCE_C
#include "global.h"
#include "z64transition.h"
#include "code/fbdemo_triforce/z_fbdemo_triforce.cpp"
#include "def/ortho.h"
#include "def/rotate.h"
#include "def/scale.h"
#include "def/translate.h"
#include "def/z_fbdemo_triforce.h"

void TransitionTriforce_Start(void* pthisx) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    switch (pthis->state) {
        case 1:
        case 2:
            pthis->transPos = 1.0f;
            return;
    }
    pthis->transPos = 0.03f;
}

void* TransitionTriforce_Init(void* pthisx) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    bzero(pthis, sizeof(*pthis));
    guOrtho(&pthis->projection, -160.0f, 160.0f, -120.0f, 120.0f, -1000.0f, 1000.0f, 1.0f);
    pthis->transPos = 1.0f;
    pthis->state = 2;
    pthis->step = 0.015f;
    pthis->fadeDirection = 1;
    return pthis;
}

void TransitionTriforce_Destroy(void* pthisx) {
}

void TransitionTriforce_Update(void* pthisx, s32 updateRate) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;
    f32 temp_f0;
    s32 i;

    for (i = updateRate; i > 0; i--) {
        if (pthis->state == 1) {
            pthis->transPos = CLAMP_MIN(pthis->transPos * (1.0f - pthis->step), 0.03f);
        } else if (pthis->state == 2) {
            pthis->transPos = CLAMP_MIN(pthis->transPos - pthis->step, 0.03f);
        } else if (pthis->state == 3) {
            pthis->transPos = CLAMP_MAX(pthis->transPos / (1.0f - pthis->step), 1.0f);
        } else if (pthis->state == 4) {
            pthis->transPos = CLAMP_MAX(pthis->transPos + pthis->step, 1.0f);
        }
    }
}

void TransitionTriforce_SetColor(void* pthisx, u32 color) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    pthis->color.rgba = color;
}

void TransitionTriforce_SetType(void* pthisx, s32 type) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    pthis->fadeDirection = type;
}

// unused
void TransitionTriforce_SetState(void* pthisx, s32 state) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    pthis->state = state;
}

void TransitionTriforce_Draw(void* pthisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    Mtx* modelView;
    f32 scale;
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;
    s32 pad;
    f32 rotation = pthis->transPos * 360.0f;

    modelView = pthis->modelView[pthis->frame];
    scale = pthis->transPos * 0.625f;
    pthis->frame ^= 1;
    osSyncPrintf("rate=%f tx=%f ty=%f rotate=%f\n", pthis->transPos, 0.0f, 0.0f, rotation);
    guScale(&modelView[0], scale, scale, 1.0f);
    guRotate(&modelView[1], rotation, 0.0f, 0.0f, 1.0f);
    guTranslate(&modelView[2], 0.0f, 0.0f, 0.0f);
    gDPPipeSync(gfx++);
    gSPDisplayList(gfx++, sTriforceWipeDL);
    gDPSetColor(gfx++, G_SETPRIMCOLOR, pthis->color.rgba);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gSPMatrix(gfx++, &pthis->projection, G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &modelView[0], G_MTX_LOAD);
    gSPMatrix(gfx++, &modelView[1], G_MTX_NOPUSH | G_MTX_MODELVIEW | G_MTX_MUL);
    gSPMatrix(gfx++, &modelView[2], G_MTX_NOPUSH | G_MTX_MODELVIEW | G_MTX_MUL);
    gSPVertex(gfx++, sTriforceWipeVtx, 10, 0);
    if (!TransitionTriforce_IsDone(pthis)) {
        switch (pthis->fadeDirection) {
            case 1:
                gSP2Triangles(gfx++, 0, 4, 5, 0, 4, 1, 3, 0);
                gSP1Triangle(gfx++, 5, 3, 2, 0);
                break;
            case 2:
                gSP2Triangles(gfx++, 3, 4, 5, 0, 0, 2, 6, 0);
                gSP2Triangles(gfx++, 0, 6, 7, 0, 1, 0, 7, 0);
                gSP2Triangles(gfx++, 1, 7, 8, 0, 1, 8, 9, 0);
                gSP2Triangles(gfx++, 1, 9, 2, 0, 2, 9, 6, 0);
                break;
        }
    } else {
        switch (pthis->fadeDirection) {
            case 1:
                break;
            case 2:
                gSP1Quadrangle(gfx++, 6, 7, 8, 9, 0);
                break;
        }
    }
    gDPPipeSync(gfx++);
    *gfxP = gfx;
}

s32 TransitionTriforce_IsDone(void* pthisx) {
    TransitionTriforce* pthis = (TransitionTriforce*)pthisx;

    s32 ret = 0;

    if (pthis->state == 1 || pthis->state == 2) {
        return pthis->transPos <= 0.03f;

    } else if (pthis->state == 3 || pthis->state == 4) {
        return pthis->transPos >= 1.0f;
    }
    return ret;
}

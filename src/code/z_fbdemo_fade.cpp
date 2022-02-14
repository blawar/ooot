#define INTERNAL_SRC_CODE_Z_FBDEMO_FADE_C
#include "global.h"
#include "gfx.h"
#include "z64transition.h"
#include "framerate.h"
#include "vt.h"
#include "regs.h"
#include "z64game.h"
#include "z64save.h"
#include "z_play.h"
#include "def/z_common_data.h"
#include "def/z_fbdemo_fade.h"
#include "def/z_lib.h"

static Gfx sRCPSetupFade[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsDPSetOtherMode(G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE |
                         G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_1PRIMITIVE,
                     G_AC_NONE | G_ZS_PIXEL | G_RM_CLD_SURF | G_RM_CLD_SURF2),
    gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE),
    gsSPEndDisplayList(),
};

void TransitionFade_Start(void* pthisx) {
    TransitionFade* pthis = (TransitionFade*)pthisx;

    switch (pthis->fadeType) {
        case 0:
            break;
        case 1:
            pthis->fadeTimer = 0;
            pthis->fadeColor.a = pthis->fadeDirection != 0 ? 0xFF : 0;
            break;
        case 2:
            pthis->fadeColor.a = 0;
            break;
    }
    pthis->isDone = 0;
}

void* TransitionFade_Init(void* pthisx) {
    TransitionFade* pthis = (TransitionFade*)pthisx;

    bzero(pthis, sizeof(*pthis));
    return pthis;
}

void TransitionFade_Destroy(void* pthisx) {
}

void TransitionFade_Update(void* pthisx, s32 updateRate) {
    s32 alpha;
    s16 newAlpha;
    TransitionFade* pthis = (TransitionFade*)pthisx;

    switch (pthis->fadeType) {
        case 0:
            break;
        case 1:
            pthis->fadeTimer += updateRate;
            if (pthis->fadeTimer >= gSaveContext.fadeDuration) {
                pthis->fadeTimer = gSaveContext.fadeDuration;
                pthis->isDone = 1;

            }
            if (!gSaveContext.fadeDuration) {
                // "Divide by 0! Zero is included in ZCommonGet fade_speed"
                osSyncPrintf(VT_COL(RED, WHITE) "０除算! ZCommonGet fade_speed に０がはいってる" VT_RST);
            }

            alpha = (255.0f * pthis->fadeTimer) / ((void)0, gSaveContext.fadeDuration);
            pthis->fadeColor.a = (pthis->fadeDirection != 0) ? 255 - alpha : alpha;
            break;
        case 2:
            newAlpha = pthis->fadeColor.a;
            if (iREG(50) != 0) {
                if (iREG(50) < 0) {
                    if (Math_StepToS(&newAlpha, 255, 255)) {
                        iREG(50) = 150;
                    }
                } else {
                    Math_StepToS(&iREG(50), 20, 60);
                    if (Math_StepToS(&newAlpha, 0, iREG(50))) {
                        iREG(50) = 0;
                        pthis->isDone = 1;
                    }
                }
            }
            pthis->fadeColor.a = newAlpha;
            break;
    }
}

void TransitionFade_Draw(void* pthisx, Gfx** gfxP) {
    TransitionFade* pthis = (TransitionFade*)pthisx;
    Gfx* gfx;
    Color_RGBA8_u32* color = &pthis->fadeColor;

    if (color->a > 0) {
        gfx = *gfxP;
        gSPDisplayList(gfx++, sRCPSetupFade);
        gDPSetPrimColor(gfx++, 0, 0, color->r, color->g, color->b, color->a);
        gDPFillRectangle(gfx++, 0, 0, gScreenWidth - 1, gScreenHeight - 1);
        gDPPipeSync(gfx++);
        *gfxP = gfx;
    }
}

s32 TransitionFade_IsDone(void* pthisx) {
    TransitionFade* pthis = (TransitionFade*)pthisx;

    return pthis->isDone;
}

void TransitionFade_SetColor(void* pthisx, u32 color) {
    TransitionFade* pthis = (TransitionFade*)pthisx;

    pthis->fadeColor.rgba = color;
}

void TransitionFade_SetType(void* pthisx, s32 type) {
    TransitionFade* pthis = (TransitionFade*)pthisx;

    if (type == 1) {
        pthis->fadeType = 1;
        pthis->fadeDirection = 1;
    } else if (type == 2) {
        pthis->fadeType = 1;
        pthis->fadeDirection = 0;
    } else if (type == 3) {
        pthis->fadeType = 2;
    } else {
        pthis->fadeType = 0;
    }
}

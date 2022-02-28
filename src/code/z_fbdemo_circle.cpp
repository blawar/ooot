#define INTERNAL_SRC_CODE_Z_FBDEMO_CIRCLE_C
#include "global.h"
#include "gfx.h"
#include "z64transition.h"
#include "z64audio.h"
#include "sfx.h"
#include "gfx_align.h"

// unused
Gfx sCircleNullDList[] = {
    gsSPEndDisplayList(),
};

#include "code/fbdemo_circle/z_fbdemo_circle.cpp"
#include "def/audio_bank.h"
#include "def/lookat.h"
#include "def/perspective.h"
#include "def/rotate.h"
#include "def/scale.h"
#include "def/translate.h"
#include "def/z_fbdemo_circle.h"
#include "def/z_rcp.h"

Gfx sCircleDList[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsDPSetOtherMode(G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE |
                         G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
                     G_AC_NONE | G_ZS_PIXEL | G_RM_XLU_SURF | G_RM_XLU_SURF2),
    gsDPSetCombineMode(G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(SEGMENT_ADDRESS(0x08000000), G_IM_FMT_I, G_IM_SIZ_8b, 16, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 4, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPDisplayListSEG(SEGMENT_ADDRESS(0x09000000)),
    gsSPVertex(sCircleWipeVtx, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 9, 11, 12, 0),
    gsSP2Triangles(11, 13, 14, 0, 13, 15, 16, 0),
    gsSP2Triangles(15, 17, 18, 0, 17, 19, 20, 0),
    gsSP2Triangles(19, 21, 22, 0, 21, 23, 24, 0),
    gsSP2Triangles(23, 25, 26, 0, 25, 27, 28, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(&sCircleWipeVtx[31], 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};

void TransitionCircle_Start(void* thisx) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    pthis->isDone = 0;

    switch (pthis->effect) {
        case 1:
            pthis->texture = sCircleWipeWaveTex;
            break;
        case 2:
            pthis->texture = sCircleWipeRippleTex;
            break;
        case 3:
            pthis->texture = sCircleWipeStarburstTex;
            break;
        default:
            pthis->texture = sCircleWipeDefaultTex;
            break;
    }

    if (pthis->speed == 0) {
        pthis->step = 0x14;
    } else {
        pthis->step = 0xA;
    }

    if (pthis->typeColor == 0) {
        pthis->color = Color_RGBA8(0, 0, 0, 255);
    } else if (pthis->typeColor == 1) {
        pthis->color = Color_RGBA8(160, 160, 160, 255);
    } else if (pthis->typeColor == 2) {
        // yes, really.
        pthis->color.r = 100;
        pthis->color.g = 100;
        pthis->color.b = 100;
        pthis->color.a = 255;
    } else {
        pthis->step = 0x28;
        pthis->color = pthis->effect == 1 ? Color_RGBA8(0, 0, 0, 255) : Color_RGBA8(160, 160, 160, 255);
    }
    if (pthis->unk_14 != 0) {
        pthis->texY = 0;
        if (pthis->typeColor == 3) {
            pthis->texY = 0xFA;
        }
    } else {
        pthis->texY = 0x1F4;
        if (pthis->effect == 2) {
            Audio_PlaySoundGeneral(NA_SE_OC_SECRET_WARP_OUT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        }
    }
    guPerspective(&pthis->projection, &pthis->normal, 60.0f, (4.0f / 3.0f), 10.0f, 12800.0f, 1.0f);
    guLookAt(&pthis->lookAt, 0.0f, 0.0f, 400.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void* TransitionCircle_Init(void* thisx) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    bzero(pthis, sizeof(*pthis));
    return pthis;
}

void TransitionCircle_Destroy(void* thisx) {
}

void TransitionCircle_Update(void* thisx, s32 updateRate) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;
    s32 temp_t2;
    s32 temp_t3;

    if (pthis->unk_14 != 0) {
        if (pthis->texY == 0) {
            if (pthis->effect == 2) {
                Audio_PlaySoundGeneral(NA_SE_OC_SECRET_WARP_IN, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            }
        }
        pthis->texY += pthis->step * 3 / updateRate;
        if (pthis->texY >= 0x1F4) {
            pthis->texY = 0x1F4;
            pthis->isDone = 1;
        }
    } else {
        pthis->texY -= pthis->step * 3 / updateRate;
        if (pthis->typeColor != 3) {
            if (pthis->texY <= 0) {
                pthis->texY = 0;
                pthis->isDone = 1;
            }
        } else {
            if (pthis->texY < 0xFB) {
                pthis->texY = 0xFA;
                pthis->isDone = 1;
            }
        }
    }
}

void TransitionCircle_Draw(void* thisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    Mtx* modelView;
    TransitionCircle* pthis = (TransitionCircle*)thisx;
    Gfx* texScroll;
    // These variables are a best guess based on the other transition types.
    f32 tPos = 0.0f;
    f32 rot = 0.0f;
    const float correction_factor = (gfx_width() * 3.0f) / (gfx_height() * 4.0f); // Should be 1 on a 4:3 display
    f32 scale = 14.8f * correction_factor;

    modelView = pthis->modelView[pthis->frame];

    pthis->frame ^= 1;
    gDPPipeSync(gfx++);
    texScroll = Gfx_BranchTexScroll(&gfx, pthis->texX, pthis->texY, 0x10, 0x40);
    gSPSegment(gfx++, 9, texScroll);
    gSPSegment(gfx++, 8, pthis->texture);
    gDPSetColor(gfx++, G_SETPRIMCOLOR, pthis->color.r, pthis->color.g, pthis->color.b, pthis->color.a);
    gDPSetColor(gfx++, G_SETENVCOLOR,  pthis->color.r, pthis->color.g, pthis->color.b, pthis->color.a);
    gSPMatrix(gfx++, &pthis->projection, G_MTX_PROJECTION | G_MTX_LOAD);
    gSPPerspNormalize(gfx++, pthis->normal);
    gSPMatrix(gfx++, &pthis->lookAt, G_MTX_PROJECTION | G_MTX_NOPUSH | G_MTX_MUL);

    if (scale != 1.0f) {
        guScale(&modelView[0], scale, scale, 1.0f);
        gSPMatrix(gfx++, &modelView[0], G_MTX_LOAD);
    }

    if (rot != 0.0f) {
        guRotate(&modelView[1], rot, 0.0f, 0.0f, 1.0f);
        gSPMatrix(gfx++, &modelView[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }

    if ((tPos != 0.0f) || (tPos != 0.0f)) {
        guTranslate(&modelView[2], tPos, tPos, 0.0f);
        gSPMatrix(gfx++, &modelView[2], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }
    gSPDisplayList(gfx++, sCircleDList);
    gDPPipeSync(gfx++);
    *gfxP = gfx;
}

s32 TransitionCircle_IsDone(void* thisx) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    return pthis->isDone;
}

void TransitionCircle_SetType(void* thisx, s32 type) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    if (type & 0x80) {
        pthis->unk_14 = (type >> 5) & 0x1;
        pthis->typeColor = (type >> 3) & 0x3;
        pthis->speed = type & 0x1;
        pthis->effect = (type >> 1) & 0x3;
    } else if (type == 1) {
        pthis->unk_14 = 1;
    } else {
        pthis->unk_14 = 0;
    }
}

void TransitionCircle_SetColor(void* thisx, Color_RGBA8 color) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    pthis->color = color;
}

void TransitionCircle_SetEnvColor(void* thisx, Color_RGBA8 envColor) {
    TransitionCircle* pthis = (TransitionCircle*)thisx;

    pthis->envColor = envColor;
}

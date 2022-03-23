#define INTERNAL_SRC_CODE_Z_FBDEMO_C
#include "global.h"
#include "gfx.h"
#include <string.h>
#include "z64transition.h"
#include "def/mtxf2l.h"
#include "def/ortho.h"
#include "def/sleep.h"
#include "def/system_malloc.h"
#include "def/z_fbdemo.h"

Gfx D_8012AFB0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x0F000000),
    gsDPSetFillColor((GPACK_RGBA5551(65, 65, 65, 1) << 16) | GPACK_RGBA5551(65, 65, 65, 1)),
    gsDPFillRectangle(0, 0, 319, 239),
    gsDPPipeSync(),
    gsDPSetFillColor((GPACK_RGBA5551(65, 65, 255, 1) << 16) | GPACK_RGBA5551(65, 65, 255, 1)),
    gsDPFillRectangle(20, 20, 300, 220),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8012B000[] = {
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetOtherMode(G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE |
                         G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE | G_PM_1PRIMITIVE,
                     G_AC_NONE | G_ZS_PIXEL | G_RM_AA_OPA_SURF | G_RM_AA_OPA_SURF2),
    gsSPEndDisplayList(),
};

void TransitionUnk_InitGraphics(TransitionUnk* pthis) {
    s32 row2;
    s32 pad2;
    s32 pad3;
    Vtx_t* vtx2;
    s32 frame;
    s32 rowTex;
    s32 row;
    Gfx* gfx;
    Vtx* vtx;
    s32 col;
    s32 colTex;

    guMtxIdent(&pthis->modelView);
    guMtxIdent(&pthis->unk_98);
    guOrtho(&pthis->projection, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -1000.0f, 1000.0f, 1.0f);

    for (frame = 0; frame < 2; frame++) {
        pthis->frame = frame;
        vtx = (pthis->frame == 0) ? pthis->vtxFrame1 : pthis->vtxFrame2;
        for (colTex = 0, col = 0; col < pthis->col + 1; colTex += 0x20, col++) {
            for (rowTex = 0, row = 0; row < pthis->row + 1; row++) {
                vtx2 = &vtx->v;
                vtx++;

                vtx2->tc[0] = rowTex << 6;
                vtx2->ob[0] = row * 0x20;
                vtx2->ob[1] = col * 0x20;
                vtx2->ob[2] = -5;
                vtx2->flag = 0;
                vtx2->tc[1] = colTex << 6;
                vtx2->cn[0] = 0;
                vtx2->cn[1] = 0;
                vtx2->cn[2] = 120;
                vtx2->cn[3] = 255;
                rowTex += 0x20;
            }
        }
    }

    gfx = pthis->gfx;
    for (colTex = 0, col = 0; col < pthis->col; colTex += 0x20, col++) {

        gSPVertex(gfx++, SEGMENT_ADDR(0xA, (u32)col * (pthis->row + 1) * sizeof(Vtx)), 2 * (pthis->row + 1), 0);

        for (rowTex = 0, row = 0, row2 = 0; row < pthis->row;) {
            gDPPipeSync(gfx++);

            gDPLoadTextureTile(gfx++, SEGMENT_ADDR(0xB, 0), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                               rowTex, colTex, rowTex + 0x20, colTex + 0x20, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSP1Quadrangle(gfx++, row, row + 1, row2 + pthis->row + 2, pthis->row + row2 + 1, 0);

            rowTex += 0x20;
            row2++;
            row++;
        }
    }

    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);

    LOG_NUM("pthis->col * (1 + pthis->row * (1 + 7 + 1)) + 1 + 1", pthis->col * (1 + pthis->row * 9) + 2, "../z_fbdemo.c",
            144);
    LOG_NUM("gp - pthis->gfxtbl", gfx - pthis->gfx, "../z_fbdemo.c", 145);
}

void TransitionUnk_InitData(TransitionUnk* pthis) {
    s32 col;
    s32 row;

    for (col = 0; col < pthis->col + 1; col++) {
        for (row = 0; row < pthis->row + 1; row++) {
            (pthis->unk_0C + row + col * (pthis->row + 1))->unk_0 = row * 32;
            (pthis->unk_0C + row + col * (pthis->row + 1))->unk_4 = col * 32;
        }
    }
}

void TransitionUnk_Destroy(TransitionUnk* pthis) {
    osSyncPrintf("fbdemo_cleanup(%08x)\n", pthis);
    osSyncPrintf("msleep(100);\n");
    Sleep_Msec(100);

    if (pthis->unk_0C != NULL) {
        SystemArena_FreeDebug(pthis->unk_0C, "../z_fbdemo.c", 180);
        pthis->unk_0C = NULL;
    }
    if (pthis->vtxFrame1 != NULL) {
        SystemArena_FreeDebug(pthis->vtxFrame1, "../z_fbdemo.c", 181);
        pthis->vtxFrame1 = NULL;
    }
    if (pthis->vtxFrame2 != NULL) {
        SystemArena_FreeDebug(pthis->vtxFrame2, "../z_fbdemo.c", 182);
        pthis->vtxFrame2 = NULL;
    }
    if (pthis->gfx != NULL) {
        SystemArena_FreeDebug(pthis->gfx, "../z_fbdemo.c", 183);
        pthis->gfx = NULL;
    }
}

TransitionUnk* TransitionUnk_Init(TransitionUnk* pthis, s32 row, s32 col) {
    osSyncPrintf("fbdemo_init(%08x, %d, %d)\n", pthis, row, col);
    memset(pthis, 0, sizeof(*pthis));
    pthis->frame = 0;
    pthis->row = row;
    pthis->col = col;
    pthis->unk_0C = (TransitionUnkData*)SystemArena_MallocDebug((row + 1) * sizeof(TransitionUnkData) * (col + 1), "../z_fbdemo.c", 195);
    pthis->vtxFrame1 = (Vtx*)SystemArena_MallocDebug((row + 1) * sizeof(Vtx) * (col + 1), "../z_fbdemo.c", 196);
    pthis->vtxFrame2 = (Vtx*)SystemArena_MallocDebug((row + 1) * sizeof(Vtx) * (col + 1), "../z_fbdemo.c", 197);
    pthis->gfx = (Gfx*)SystemArena_MallocDebug((pthis->col * (1 + pthis->row * 9) + 2) * sizeof(Gfx), "../z_fbdemo.c", 198);

    if (pthis->unk_0C == NULL || pthis->vtxFrame1 == NULL || pthis->vtxFrame2 == NULL || pthis->gfx == NULL) {
        osSyncPrintf("fbdemo_init allocation error\n");
        if (pthis->unk_0C != NULL) {
            SystemArena_FreeDebug(pthis->unk_0C, "../z_fbdemo.c", 202);
            pthis->unk_0C = NULL;
        }
        if (pthis->vtxFrame1 != NULL) {
            SystemArena_FreeDebug(pthis->vtxFrame1, "../z_fbdemo.c", 203);
            pthis->vtxFrame1 = NULL;
        }
        if (pthis->vtxFrame2 != NULL) {
            SystemArena_FreeDebug(pthis->vtxFrame2, "../z_fbdemo.c", 204);
            pthis->vtxFrame2 = NULL;
        }
        if (pthis->gfx != NULL) {
            SystemArena_FreeDebug(pthis->gfx, "../z_fbdemo.c", 205);
            pthis->gfx = NULL;
        }
        return NULL;
    }
    TransitionUnk_InitGraphics(pthis);
    TransitionUnk_InitData(pthis);
    pthis->frame = 0;

    return pthis;
}

void TransitionUnk_SetData(TransitionUnk* pthis) {
    s32 col;
    Vtx* vtx;
    s32 row;

    for (col = 0; col < pthis->col + 1; col++) {
        for (row = 0; row < pthis->row + 1; row++) {
            vtx = (pthis->frame == 0) ? pthis->vtxFrame1 : pthis->vtxFrame2;
            (vtx + row + col * (pthis->row + 1))->v.ob[0] = (pthis->unk_0C + row + col * (pthis->row + 1))->unk_0;
            vtx = (pthis->frame == 0) ? pthis->vtxFrame1 : pthis->vtxFrame2;
            (vtx + row + col * (pthis->row + 1))->v.ob[1] = (pthis->unk_0C + row + col * (pthis->row + 1))->unk_4;
        }
    }
}

void TransitionUnk_Draw(TransitionUnk* pthis, Gfx** gfxP) {
    Gfx* gfx = *gfxP;

    gSPDisplayList(gfx++, D_8012B000);
    TransitionUnk_SetData(pthis);
    gSPMatrix(gfx++, &pthis->projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &pthis->modelView, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(gfx++, 0xA, pthis->frame == 0 ? pthis->vtxFrame1 : pthis->vtxFrame2);
    gSPSegment(gfx++, 0xB, pthis->zBuffer);
    gSPDisplayList(gfx++, D_8012B000);
    gSPDisplayList(gfx++, pthis->gfx);
    gDPPipeSync(gfx++);
    pthis->frame ^= 1;
    *gfxP = gfx;
}

void TransitionUnk_Update(TransitionUnk* pthis) {
    f32 temp_f00;
    f32 temp_f12;
    s32 col;
    f32 phi_f14;
    s32 row;

    for (col = 0; col < pthis->col + 1; col++) {
        for (row = 0; row < pthis->row + 1; row++) {
            temp_f00 =
                (pthis->unk_0C + row + col * (pthis->row + 1))->unk_0 - (pthis->unk_0C + 5 + 4 * (pthis->row + 1))->unk_0;
            temp_f12 =
                (pthis->unk_0C + row + col * (pthis->row + 1))->unk_4 - (pthis->unk_0C + 5 + 4 * (pthis->row + 1))->unk_4;
            phi_f14 = (SQ(temp_f00) + SQ(temp_f12)) / 100.0f;
            if (phi_f14 != 0.0f) {
                if (phi_f14 < 1.0f) {
                    phi_f14 = 1.0f;
                }
                (pthis->unk_0C + row + col * (pthis->row + 1))->unk_0 -= temp_f00 / phi_f14;
                (pthis->unk_0C + row + col * (pthis->row + 1))->unk_4 -= temp_f12 / phi_f14;
            }
        }
    }
}

void func_800B23E8(TransitionUnk* pthis) {
}

s32 func_800B23F0(TransitionUnk* pthis) {
    return 0;
}

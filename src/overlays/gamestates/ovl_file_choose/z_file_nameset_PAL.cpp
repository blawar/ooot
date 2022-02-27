#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_FILE_CHOOSE_Z_FILE_NAMESET_PAL_C
#include "actor_common.h"
#include "file_choose.h"
#include "z_file_choose.h"
#include "textures/title_static/title_static.h"
#include "overlays/ovl_File_Choose/ovl_file_choose.h"
#include "def/code_800A9F30.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_rcp.h"
#include "def/z_sram.h"

static s16 D_808124C0[] = {
    0x0002, 0x0003, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0001, 0x0002, 0x0000, 0x0001,
    0x0001, 0x0002, 0x0001, 0x0001, 0x0004, 0x0002, 0x0002, 0x0002, 0x0001, 0x0001, 0x0000, 0x0002, 0x0000, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003,
    0x0002, 0x0002, 0x0004, 0x0003, 0x0002, 0x0004, 0x0001, 0x0002, 0x0002, 0x0001, 0x0001, 0x0002, 0x0002, 0x0003,
    0x0002, 0x0002, 0x0000, 0x0002, 0x0002, 0x0002, 0x0000, 0x0003, 0x0001, 0x0000,
};

static s16 D_80812544[] = {
    0x0001, 0x0002, 0x0000, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0004, 0x0002, 0x0002, 0x0002, 0x0001,
    0x0001, 0x0000, 0x0002, 0x0000, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0001, 0x0001, 0x0001,
    0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003, 0x0002, 0x0002, 0x0004, 0x0003, 0x0002, 0x0004, 0x0001,
    0x0002, 0x0002, 0x0001, 0x0001, 0x0002, 0x0002, 0x0003, 0x0002, 0x0002, 0x0000, 0x0002, 0x0002, 0x0002,
    0x0003, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0001, 0x0003,
};

void FileChoose_DrawCharacter(GraphicsContext* gfxCtx, void* texture, s16 vtx) {
    OPEN_DISPS(gfxCtx, "../z_file_nameset_PAL.c", 110);

    gDPLoadTextureBlock_4b(POLY_OPA_DISP++, texture, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);

    CLOSE_DISPS(gfxCtx, "../z_file_nameset_PAL.c", 119);
}

void FileChoose_SetKeyboardVtx(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 val;
    s16 phi_t2;
    s16 phi_t0;
    s16 phi_t3;
    s16 phi_s1;
    s16 phi_t1;
    s16 phi_s2;

    pthis->keyboardVtx = (Vtx*)Graph_Alloc(pthis->state.gfxCtx, sizeof(Vtx) * 4 * 5 * 13);

    phi_s1 = 0x26;

    for (phi_t2 = 0, phi_s2 = 0, phi_t3 = 0; phi_s2 < 5; phi_s2++) {
        phi_t0 = -0x60;

        for (phi_t1 = 0; phi_t1 < 13; phi_t1++, phi_t3 += 4, phi_t2++) {
            /* Avoid Overflow in final loop */
            phi_t2 = phi_t2 & 0x3F;

            pthis->keyboardVtx[phi_t3].v.ob[0] = pthis->keyboardVtx[phi_t3 + 2].v.ob[0] = D_80812544[phi_t2] + phi_t0;

            pthis->keyboardVtx[phi_t3 + 1].v.ob[0] = pthis->keyboardVtx[phi_t3 + 3].v.ob[0] =
                D_80812544[phi_t2] + phi_t0 + 12;

            pthis->keyboardVtx[phi_t3].v.ob[1] = pthis->keyboardVtx[phi_t3 + 1].v.ob[1] = phi_s1;

            pthis->keyboardVtx[phi_t3 + 2].v.ob[1] = pthis->keyboardVtx[phi_t3 + 3].v.ob[1] = phi_s1 - 12;

            pthis->keyboardVtx[phi_t3].v.ob[2] = pthis->keyboardVtx[phi_t3 + 1].v.ob[2] =
                pthis->keyboardVtx[phi_t3 + 2].v.ob[2] = pthis->keyboardVtx[phi_t3 + 3].v.ob[2] = 0;

            pthis->keyboardVtx[phi_t3].v.flag = pthis->keyboardVtx[phi_t3 + 1].v.flag =
                pthis->keyboardVtx[phi_t3 + 2].v.flag = pthis->keyboardVtx[phi_t3 + 3].v.flag = 0;

            pthis->keyboardVtx[phi_t3].v.tc[0] = pthis->keyboardVtx[phi_t3].v.tc[1] =
                pthis->keyboardVtx[phi_t3 + 1].v.tc[1] = pthis->keyboardVtx[phi_t3 + 2].v.tc[0] = 0;

            pthis->keyboardVtx[phi_t3 + 1].v.tc[0] = pthis->keyboardVtx[phi_t3 + 2].v.tc[1] =
                pthis->keyboardVtx[phi_t3 + 3].v.tc[0] = pthis->keyboardVtx[phi_t3 + 3].v.tc[1] = 0x200;

            pthis->keyboardVtx[phi_t3].v.cn[0] = pthis->keyboardVtx[phi_t3 + 1].v.cn[0] =
                pthis->keyboardVtx[phi_t3 + 2].v.cn[0] = pthis->keyboardVtx[phi_t3 + 3].v.cn[0] =
                    pthis->keyboardVtx[phi_t3].v.cn[1] = pthis->keyboardVtx[phi_t3 + 1].v.cn[1] =
                        pthis->keyboardVtx[phi_t3 + 2].v.cn[1] = pthis->keyboardVtx[phi_t3 + 3].v.cn[1] =
                            pthis->keyboardVtx[phi_t3].v.cn[2] = pthis->keyboardVtx[phi_t3 + 1].v.cn[2] =
                                pthis->keyboardVtx[phi_t3 + 2].v.cn[2] = pthis->keyboardVtx[phi_t3 + 3].v.cn[2] =
                                    pthis->keyboardVtx[phi_t3].v.cn[3] = pthis->keyboardVtx[phi_t3 + 1].v.cn[3] =
                                        pthis->keyboardVtx[phi_t3 + 2].v.cn[3] = pthis->keyboardVtx[phi_t3 + 3].v.cn[3] =
                                            255;

            phi_t0 += 0x10;
        }

        phi_s1 -= 0x10;
    }
}

static void* sNameLabelTextures[] = { gFileSelNameENGTex, gFileSelNameENGTex, gFileSelNameFRATex };

static void* sBackspaceEndTextures[][2] = {
    { gFileSelBackspaceButtonTex, gFileSelENDButtonENGTex },
    { gFileSelBackspaceButtonTex, gFileSelENDButtonGERTex },
    { gFileSelBackspaceButtonTex, gFileSelENDButtonFRATex },
};

static u16 sBackspaceEndWidths[] = { 28, 44 };

static s16 D_808125EC[] = {
    0xFFE2, 0xFFF0, 0xFFFA, 0x0004, 0x000E, 0x0018, 0x0022, 0x002C, 0x0036, 0xFFF0, 0xFFF0,
};

static s16 D_80812604[] = {
    0x0048, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045, 0x0045,
};

/**
 * Set vertices used by all elements of the name entry screen that are NOT the keyboard.
 * This includes the cursor highlight, the name entry plate and characters, and the buttons.
 */
void FileChoose_SetNameEntryVtx(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Font* font = &pthis->font;
    s16 phi_s0;
    s16 phi_t1;
    u8 temp;
    s16 phi_v0;

    if (1) {}
    if (1) {}

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 205);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
    gSPVertex(POLY_OPA_DISP++, D_80811BB0, 24, 0);
    gDPLoadTextureBlock(POLY_OPA_DISP++, sNameLabelTextures[gSaveContext.language], G_IM_FMT_IA, G_IM_SIZ_8b, 56, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    gDPPipeSync(POLY_OPA_DISP++);

    phi_s0 = 0x10;
    for (phi_t1 = 0; phi_t1 < 2; phi_t1++, phi_s0 += 4) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2], 255);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
        gDPLoadTextureBlock(POLY_OPA_DISP++, sBackspaceEndTextures[gSaveContext.language][phi_t1], G_IM_FMT_IA,
                            G_IM_SIZ_16b, sBackspaceEndWidths[phi_t1], 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, phi_s0, phi_s0 + 2, phi_s0 + 3, phi_s0 + 1, 0);
    }

    pthis->nameEntryVtx = (Vtx*)Graph_Alloc(pthis->state.gfxCtx, 44 * sizeof(Vtx));

    for (phi_s0 = 0, phi_t1 = 0; phi_t1 < 44; phi_t1 += 4, phi_s0++) {
        if ((phi_s0 > 0) && (phi_s0 < 9)) {
            temp = pthis->fileNames[pthis->buttonIndex][phi_s0 - 1];

            pthis->nameEntryVtx[phi_t1].v.ob[0] = pthis->nameEntryVtx[phi_t1 + 2].v.ob[0] =
                D_808125EC[phi_s0] + pthis->nameEntryBoxPosX + D_808124C0[temp];

            pthis->nameEntryVtx[phi_t1 + 1].v.ob[0] = pthis->nameEntryVtx[phi_t1 + 3].v.ob[0] =
                pthis->nameEntryVtx[phi_t1].v.ob[0] + 0xA;
        } else {
            pthis->nameEntryVtx[phi_t1].v.ob[0] = pthis->nameEntryVtx[phi_t1 + 2].v.ob[0] =
                D_808125EC[phi_s0] + pthis->nameEntryBoxPosX;

            pthis->nameEntryVtx[phi_t1 + 1].v.ob[0] = pthis->nameEntryVtx[phi_t1 + 3].v.ob[0] =
                pthis->nameEntryVtx[phi_t1].v.ob[0] + 0xA;
        }

        pthis->nameEntryVtx[phi_t1].v.ob[1] = pthis->nameEntryVtx[phi_t1 + 1].v.ob[1] = D_80812604[phi_s0];

        pthis->nameEntryVtx[phi_t1 + 2].v.ob[1] = pthis->nameEntryVtx[phi_t1 + 3].v.ob[1] =
            pthis->nameEntryVtx[phi_t1].v.ob[1] - 0xA;

        pthis->nameEntryVtx[phi_t1].v.ob[2] = pthis->nameEntryVtx[phi_t1 + 1].v.ob[2] =
            pthis->nameEntryVtx[phi_t1 + 2].v.ob[2] = pthis->nameEntryVtx[phi_t1 + 3].v.ob[2] = 0;

        pthis->nameEntryVtx[phi_t1].v.flag = pthis->nameEntryVtx[phi_t1 + 1].v.flag =
            pthis->nameEntryVtx[phi_t1 + 2].v.flag = pthis->nameEntryVtx[phi_t1 + 3].v.flag = 0;

        pthis->nameEntryVtx[phi_t1].v.tc[0] = pthis->nameEntryVtx[phi_t1].v.tc[1] =
            pthis->nameEntryVtx[phi_t1 + 1].v.tc[1] = pthis->nameEntryVtx[phi_t1 + 2].v.tc[0] = 0;

        pthis->nameEntryVtx[phi_t1 + 1].v.tc[0] = pthis->nameEntryVtx[phi_t1 + 2].v.tc[1] =
            pthis->nameEntryVtx[phi_t1 + 3].v.tc[0] = pthis->nameEntryVtx[phi_t1 + 3].v.tc[1] = 0x200;

        pthis->nameEntryVtx[phi_t1].v.cn[0] = pthis->nameEntryVtx[phi_t1 + 1].v.cn[0] =
            pthis->nameEntryVtx[phi_t1 + 2].v.cn[0] = pthis->nameEntryVtx[phi_t1 + 3].v.cn[0] =
                pthis->nameEntryVtx[phi_t1].v.cn[1] = pthis->nameEntryVtx[phi_t1 + 1].v.cn[1] =
                    pthis->nameEntryVtx[phi_t1 + 2].v.cn[1] = pthis->nameEntryVtx[phi_t1 + 3].v.cn[1] =
                        pthis->nameEntryVtx[phi_t1].v.cn[2] = pthis->nameEntryVtx[phi_t1 + 1].v.cn[2] =
                            pthis->nameEntryVtx[phi_t1 + 2].v.cn[2] = pthis->nameEntryVtx[phi_t1 + 3].v.cn[2] =
                                pthis->nameEntryVtx[phi_t1].v.cn[3] = pthis->nameEntryVtx[phi_t1 + 1].v.cn[3] =
                                    pthis->nameEntryVtx[phi_t1 + 2].v.cn[3] = pthis->nameEntryVtx[phi_t1 + 3].v.cn[3] =
                                        0xFF;
    }

    pthis->nameEntryVtx[1].v.ob[0] = pthis->nameEntryVtx[3].v.ob[0] = pthis->nameEntryVtx[0].v.ob[0] + 0x6C;
    pthis->nameEntryVtx[2].v.ob[1] = pthis->nameEntryVtx[3].v.ob[1] = pthis->nameEntryVtx[0].v.ob[1] - 0x10;
    pthis->nameEntryVtx[1].v.tc[0] = pthis->nameEntryVtx[3].v.tc[0] = 0xD80;

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->windowColor[0], pthis->windowColor[1], pthis->windowColor[2],
                    pthis->nameEntryBoxAlpha);
    gSPVertex(POLY_OPA_DISP++, pthis->nameEntryVtx, 4, 0);
    gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelNameBoxTex, G_IM_FMT_IA, G_IM_SIZ_16b, 108, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                      PRIMITIVE, 0);
    gSPVertex(POLY_OPA_DISP++, pthis->nameEntryVtx + 4, 32, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->nameEntryBoxAlpha);

    for (phi_v0 = 0, phi_s0 = 0; phi_s0 < 0x20; phi_s0 += 4, phi_v0++) {
        FileChoose_DrawCharacter(pthis->state.gfxCtx,
                                 font->fontBuf + pthis->fileNames[pthis->buttonIndex][phi_v0] * FONT_CHAR_TEX_SIZE,
                                 phi_s0);
    }

    pthis->nameEntryVtx[0x25].v.tc[0] = pthis->nameEntryVtx[0x26].v.tc[1] = pthis->nameEntryVtx[0x27].v.tc[0] =
        pthis->nameEntryVtx[0x27].v.tc[1] = pthis->nameEntryVtx[0x29].v.tc[0] = pthis->nameEntryVtx[0x2A].v.tc[1] =
            pthis->nameEntryVtx[0x2B].v.tc[0] = pthis->nameEntryVtx[0x2B].v.tc[1] = 0x300;

    if ((pthis->kbdButton == 0) || (pthis->kbdButton == 1) || (pthis->kbdButton == 4)) {
        pthis->nameEntryVtx[0x29].v.tc[0] = pthis->nameEntryVtx[0x2B].v.tc[0] = 0x700;
    } else if ((pthis->kbdButton == 2) || (pthis->kbdButton == 3)) {
        pthis->nameEntryVtx[0x29].v.tc[0] = pthis->nameEntryVtx[0x2B].v.tc[0] = 0x500;
    }

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 307);
}

void FileChoose_DrawKeyboard(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Font* font = &pthis->font;
    s16 i = 0;
    s16 tmp;
    s16 vtx = 0;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 324);

    func_800949A8(pthis->state.gfxCtx);
    gDPSetCycleType(POLY_OPA_DISP++, G_CYC_2CYCLE);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_XLU_SURF2);
    gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, PRIMITIVE, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, COMBINED, 0,
                      0, 0, COMBINED);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, pthis->charBgAlpha, 255, 255, 255, 255);

    while (vtx < 0x100) {
        gSPVertex(POLY_OPA_DISP++, &pthis->keyboardVtx[vtx], 32, 0);

        for (tmp = 0; tmp < 32; i++, tmp += 4) {
            FileChoose_DrawCharacter(pthis->state.gfxCtx, font->fontBuf + D_808123F0[i] * FONT_CHAR_TEX_SIZE, tmp);
        }

        vtx += 32;
    }

    gSPVertex(POLY_OPA_DISP++, &pthis->keyboardVtx[0x100], 4, 0);
    FileChoose_DrawCharacter(pthis->state.gfxCtx, font->fontBuf + D_808123F0[i] * FONT_CHAR_TEX_SIZE, 0);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 347);
}

void FileChoose_DrawNameEntry(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    Font* font = &pthis->font;
    Input* input = &pthis->state.input[0];
    s16 i;
    s16 tmp;
    u16 dayTime;
    s16 validName;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 368);

    FileChoose_SetKeyboardVtx(&pthis->state);
    FileChoose_SetNameEntryVtx(&pthis->state);
    FileChoose_PulsateCursor(&pthis->state);

    tmp = (pthis->newFileNameCharCount * 4) + 4;
    pthis->nameEntryVtx[36].v.ob[0] = pthis->nameEntryVtx[38].v.ob[0] = pthis->nameEntryVtx[tmp].v.ob[0] - 6;
    pthis->nameEntryVtx[37].v.ob[0] = pthis->nameEntryVtx[39].v.ob[0] = pthis->nameEntryVtx[36].v.ob[0] + 24;
    pthis->nameEntryVtx[36].v.ob[1] = pthis->nameEntryVtx[37].v.ob[1] = pthis->nameEntryVtx[tmp].v.ob[1] + 7;
    pthis->nameEntryVtx[38].v.ob[1] = pthis->nameEntryVtx[39].v.ob[1] = pthis->nameEntryVtx[36].v.ob[1] - 24;

    if ((pthis->kbdButton == FS_KBD_BTN_HIRA) || (pthis->kbdButton == FS_KBD_BTN_KATA) ||
        (pthis->kbdButton == FS_KBD_BTN_END)) {
        if (pthis->kbdX != pthis->kbdButton) {
            osSyncPrintf("014 xpos=%d  contents=%d\n", pthis->kbdX, pthis->kbdButton);
        }
        pthis->nameEntryVtx[40].v.ob[0] = pthis->nameEntryVtx[42].v.ob[0] = D_80811BB0[(pthis->kbdX + 1) * 4].v.ob[0] - 4;
        pthis->nameEntryVtx[41].v.ob[0] = pthis->nameEntryVtx[43].v.ob[0] = pthis->nameEntryVtx[40].v.ob[0] + 52;
        pthis->nameEntryVtx[40].v.ob[1] = pthis->nameEntryVtx[41].v.ob[1] = D_80811BB0[(pthis->kbdX + 1) * 4].v.ob[1] + 4;

    } else if ((pthis->kbdButton == FS_KBD_BTN_ENG) || (pthis->kbdButton == FS_KBD_BTN_BACKSPACE)) {
        if (pthis->kbdX != pthis->kbdButton) {
            osSyncPrintf("23 xpos=%d  contents=%d\n", pthis->kbdX, pthis->kbdButton);
        }
        pthis->nameEntryVtx[40].v.ob[0] = pthis->nameEntryVtx[42].v.ob[0] = D_80811BB0[(pthis->kbdX + 1) * 4].v.ob[0] - 4;
        pthis->nameEntryVtx[41].v.ob[0] = pthis->nameEntryVtx[43].v.ob[0] = pthis->nameEntryVtx[40].v.ob[0] + 40;
        pthis->nameEntryVtx[40].v.ob[1] = pthis->nameEntryVtx[41].v.ob[1] = D_80811BB0[(pthis->kbdX + 1) * 4].v.ob[1] + 4;
    } else {
        if (pthis->charIndex >= 65) {
            osSyncPrintf("mjp=%d  xpos=%d  ypos=%d  name_contents=%d\n", pthis->charIndex, pthis->kbdX, pthis->kbdY,
                         pthis->kbdButton);
        }

        pthis->nameEntryVtx[40].v.ob[0] = pthis->nameEntryVtx[42].v.ob[0] =
            pthis->keyboardVtx[pthis->charIndex * 4].v.ob[0] - D_80812544[pthis->charIndex] - 6;
        pthis->nameEntryVtx[41].v.ob[0] = pthis->nameEntryVtx[43].v.ob[0] = pthis->nameEntryVtx[40].v.ob[0] + 24;
        pthis->nameEntryVtx[40].v.ob[1] = pthis->nameEntryVtx[41].v.ob[1] =
            pthis->keyboardVtx[pthis->charIndex * 4].v.ob[1] + 6;
    }

    pthis->nameEntryVtx[42].v.ob[1] = pthis->nameEntryVtx[43].v.ob[1] = pthis->nameEntryVtx[40].v.ob[1] - 24;

    gSPVertex(POLY_OPA_DISP++, &pthis->nameEntryVtx[36], 8, 0);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->highlightColor[0], pthis->highlightColor[1], pthis->highlightColor[2],
                    pthis->highlightColor[3]);
    gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelCharHighlightTex, G_IM_FMT_I, G_IM_SIZ_8b, 24, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

    if ((pthis->kbdButton == FS_KBD_BTN_HIRA) || (pthis->kbdButton == FS_KBD_BTN_KATA) ||
        (pthis->kbdButton == FS_KBD_BTN_END)) {
        gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelMediumButtonHighlightTex, G_IM_FMT_I, G_IM_SIZ_8b, 56, 24, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

    } else if ((pthis->kbdButton == FS_KBD_BTN_ENG) || (pthis->kbdButton == FS_KBD_BTN_BACKSPACE)) {
        gDPLoadTextureBlock(POLY_OPA_DISP++, gFileSelSmallButtonHighlightTex, G_IM_FMT_I, G_IM_SIZ_8b, 40, 24, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    }

    gSP1Quadrangle(POLY_OPA_DISP++, 4, 6, 7, 5, 0);

    FileChoose_DrawKeyboard(&pthis->state);
    gDPPipeSync(POLY_OPA_DISP++);
    func_800949A8(pthis->state.gfxCtx);

    gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

    if (pthis->configMode == CM_NAME_ENTRY) {
        if (CHECK_BTN_ALL(input->press.button, BTN_START)) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            // place cursor on END button
            pthis->kbdY = 5;
            pthis->kbdX = 4;
        } else if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
            if ((pthis->newFileNameCharCount == 7) && (pthis->fileNames[pthis->buttonIndex][7] != 0x3E)) {
                for (i = pthis->newFileNameCharCount; i < 7; i++) {
                    pthis->fileNames[pthis->buttonIndex][i] = pthis->fileNames[pthis->buttonIndex][i + 1];
                }

                pthis->fileNames[pthis->buttonIndex][i] = 0x3E;
                Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_S, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            } else {
                pthis->newFileNameCharCount--;

                if (pthis->newFileNameCharCount < 0) {
                    pthis->newFileNameCharCount = 0;
                    pthis->configMode = CM_NAME_ENTRY_TO_MAIN;
                } else {
                    for (i = pthis->newFileNameCharCount; i < 7; i++) {
                        pthis->fileNames[pthis->buttonIndex][i] = pthis->fileNames[pthis->buttonIndex][i + 1];
                    }

                    pthis->fileNames[pthis->buttonIndex][i] = 0x3E;
                    Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_S, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                           &gReverbAdd2);
                }
            }
        } else {
            if (pthis->charPage <= FS_CHAR_PAGE_ENG) {
                if (pthis->kbdY != 5) {
                    // draw the character the cursor is hovering over in yellow
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 0, 255);
                    gSPVertex(POLY_OPA_DISP++, &pthis->keyboardVtx[pthis->charIndex * 4], 4, 0);

                    FileChoose_DrawCharacter(pthis->state.gfxCtx,
                                             font->fontBuf + D_808123F0[pthis->charIndex] * FONT_CHAR_TEX_SIZE, 0);

                    if (CHECK_BTN_ALL(input->press.button, BTN_A)) {
                        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_S, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &gReverbAdd2);
                        pthis->fileNames[pthis->buttonIndex][pthis->newFileNameCharCount] = D_808123F0[pthis->charIndex];
                        pthis->newFileNameCharCount++;

                        if (pthis->newFileNameCharCount > 7) {
                            pthis->newFileNameCharCount = 7;
                        }
                    }
                } else if (CHECK_BTN_ALL(input->press.button, BTN_A) && (pthis->charPage != pthis->kbdButton)) {
                    if (pthis->kbdButton == FS_KBD_BTN_BACKSPACE) {
                        if ((pthis->newFileNameCharCount == 7) && (pthis->fileNames[pthis->buttonIndex][7] != 0x3E)) {
                            for (i = pthis->newFileNameCharCount; i < 7; i++) {
                                pthis->fileNames[pthis->buttonIndex][i] = pthis->fileNames[pthis->buttonIndex][i + 1];
                            }

                            pthis->fileNames[pthis->buttonIndex][i] = 0x3E;
                            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_S, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &gReverbAdd2);
                        } else {
                            pthis->newFileNameCharCount--;

                            if (pthis->newFileNameCharCount < 0) {
                                pthis->newFileNameCharCount = 0;
                            }

                            for (i = pthis->newFileNameCharCount; i < 7; i++) {
                                pthis->fileNames[pthis->buttonIndex][i] = pthis->fileNames[pthis->buttonIndex][i + 1];
                            }

                            pthis->fileNames[pthis->buttonIndex][i] = 0x3E;
                            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_S, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &gReverbAdd2);
                        }
                    } else if (pthis->kbdButton == FS_KBD_BTN_END) {
                        validName = false;

                        for (i = 0; i < 8; i++) {
                            if (pthis->fileNames[pthis->buttonIndex][i] != 0x3E) {
                                validName = true;
                                break;
                            }
                        }

                        if (validName) {
                            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &gReverbAdd2);
                            gSaveContext.fileNum = pthis->buttonIndex;
                            dayTime = ((void)0, gSaveContext.dayTime);
                            Sram_InitSave(pthis, &pthis->sramCtx);
                            gSaveContext.dayTime = dayTime;
                            pthis->configMode = CM_NAME_ENTRY_TO_MAIN;
                            pthis->nameBoxAlpha[pthis->buttonIndex] = pthis->nameAlpha[pthis->buttonIndex] = 200;
                            pthis->connectorAlpha[pthis->buttonIndex] = 255;
                            Rumble_Shake(300.0f, 0xB4, 0x14, 0x64);
                        } else {
                            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &gReverbAdd2);
                        }
                    }
                }

                if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
                    Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
                    pthis->newFileNameCharCount++;

                    if (pthis->newFileNameCharCount > 7) {
                        pthis->newFileNameCharCount = 7;
                    }
                } else if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
                    Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
                    pthis->newFileNameCharCount--;

                    if (pthis->newFileNameCharCount < 0) {
                        pthis->newFileNameCharCount = 0;
                    }
                }
            }
        }
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 550);
}

/**
 * Fade in the name entry box and slide it to the center of the screen from the right side.
 * After the name entry box is in place, init the keyboard/cursor and change modes.
 * Update function for `CM_START_NAME_ENTRY`
 */
void FileChoose_StartNameEntry(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->nameEntryBoxAlpha += 25;

    if (pthis->nameEntryBoxAlpha >= 255) {
        pthis->nameEntryBoxAlpha = 255;
    }

    pthis->nameEntryBoxPosX -= 30;

    if (pthis->nameEntryBoxPosX <= 0) {
        pthis->nameEntryBoxPosX = 0;
        pthis->nameEntryBoxAlpha = 255;
        pthis->kbdX = 0;
        pthis->kbdY = 0;
        pthis->kbdButton = 99;
        pthis->configMode = CM_NAME_ENTRY;
    }
}

/**
 * Update the keyboard cursor and play sounds at the appropriate times.
 * There are many special cases for warping the cursor depending on where
 * the cursor currently is.
 * Update function for `CM_NAME_ENTRY`
 */
void FileChoose_UpdateKeyboardCursor(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 prevKbdX;

    pthis->kbdButton = 99;

    if (pthis->kbdY != 5) {
        if (pthis->stickRelX < -30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            pthis->charIndex--;
            pthis->kbdX--;
            if (pthis->kbdX < 0) {
                pthis->kbdX = 12;
                pthis->charIndex = (pthis->kbdY * 13) + pthis->kbdX;
            }
        } else if (pthis->stickRelX > 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            pthis->charIndex++;
            pthis->kbdX++;
            if (pthis->kbdX > 12) {
                pthis->kbdX = 0;
                pthis->charIndex = (pthis->kbdY * 13) + pthis->kbdX;
            }
        }
    } else {
        if (pthis->stickRelX < -30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            pthis->kbdX--;
            if (pthis->kbdX < 3) {
                pthis->kbdX = 4;
            }
        } else if (pthis->stickRelX > 30) {
            Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            pthis->kbdX++;
            if (pthis->kbdX > 4) {
                pthis->kbdX = 3;
            }
        }
    }

    if (pthis->stickRelY > 30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->kbdY--;

        if (pthis->kbdY < 0) {
            // dont go to bottom row
            if (pthis->kbdX < 8) {
                pthis->kbdY = 4;
                pthis->charIndex = (s32)(pthis->kbdX + 52);
            } else {
                pthis->kbdY = 5;
                pthis->charIndex += 52;
                prevKbdX = pthis->kbdX;

                if (pthis->kbdX < 10) {
                    pthis->kbdX = 3;
                } else if (pthis->kbdX < 13) {
                    pthis->kbdX = 4;
                }

                pthis->unk_1CAD6[pthis->kbdX] = prevKbdX;
            }
        } else {
            pthis->charIndex -= 13;

            if (pthis->kbdY == 4) {
                pthis->charIndex = 52;
                pthis->kbdX = pthis->unk_1CAD6[pthis->kbdX];
                pthis->charIndex += pthis->kbdX;
            }
        }
    } else if (pthis->stickRelY < -30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->kbdY++;

        if (pthis->kbdY > 5) {
            pthis->kbdY = 0;
            pthis->kbdX = pthis->unk_1CAD6[pthis->kbdX];
            pthis->charIndex = pthis->kbdX;
        } else {
            pthis->charIndex += 13;

            if (pthis->kbdY == 5) {
                if (pthis->kbdX < 8) {
                    pthis->kbdY = 0;
                    pthis->charIndex = pthis->kbdX;
                } else {
                    prevKbdX = pthis->kbdX;

                    if (pthis->kbdX < 3) {
                        pthis->kbdX = 0;
                    } else if (pthis->kbdX < 6) {
                        pthis->kbdX = 1;
                    } else if (pthis->kbdX < 8) {
                        pthis->kbdX = 2;
                    } else if (pthis->kbdX < 10) {
                        pthis->kbdX = 3;
                    } else if (pthis->kbdX < 13) {
                        pthis->kbdX = 4;
                    }

                    pthis->unk_1CAD6[pthis->kbdX] = prevKbdX;
                }
            }
        }
    }

    if (pthis->kbdY == 5) {
        pthis->kbdButton = pthis->kbdX;
    }
}

/**
 * This function is mostly a copy paste of `FileChoose_StartNameEntry`.
 * The name entry box fades and slides in even though it is not visible.
 * After pthis is complete, change to the options config mode.
 * Update function for `CM_START_OPTIONS`
 */
void FileChoose_StartOptions(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;

    pthis->nameEntryBoxAlpha += 25;

    if (pthis->nameEntryBoxAlpha >= 255) {
        pthis->nameEntryBoxAlpha = 255;
    }

    pthis->nameEntryBoxPosX -= 30;

    if (pthis->nameEntryBoxPosX <= 0) {
        pthis->nameEntryBoxPosX = 0;
        pthis->nameEntryBoxAlpha = 255;
        pthis->configMode = CM_OPTIONS_MENU;
    }
}

static u8 sSelectedSetting;

/**
 * Update the cursor and appropriate settings for the options menu.
 * If the player presses B, write the selected options to the SRAM header
 * and set config mode to rotate back to the main menu.
 * Update function for `CM_OPTIONS_MENU`
 */
void FileChoose_UpdateOptionsMenu(GameState* thisx) {
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    SramContext* sramCtx = &pthis->sramCtx;
    Input* input = &pthis->state.input[0];

    if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->configMode = CM_OPTIONS_TO_MAIN;
        sramCtx->readBuff[0] = gSaveContext.audioSetting;
        sramCtx->readBuff[1] = gSaveContext.zTargetSetting;
        osSyncPrintf("SAVE");
        Sram_WriteSramHeader(sramCtx);
        osSyncPrintf(VT_FGCOL(YELLOW));
        osSyncPrintf("sram->read_buff[2] = J_N = %x\n", sramCtx->readBuff[2]);
        osSyncPrintf("sram->read_buff[2] = J_N = %x\n", &sramCtx->readBuff[2]);
        osSyncPrintf("Na_SetSoundOutputMode = %d\n", gSaveContext.audioSetting);
        osSyncPrintf("Na_SetSoundOutputMode = %d\n", gSaveContext.audioSetting);
        osSyncPrintf("Na_SetSoundOutputMode = %d\n", gSaveContext.audioSetting);
        osSyncPrintf(VT_RST);
        Audio_SetSettings(gSaveContext.audioSetting);
		osSyncPrintf("Done!!!\n");
        return;
    }

    if (pthis->stickRelX < -30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);

        if (sSelectedSetting == FS_SETTING_AUDIO) {
            gSaveContext.audioSetting--;

            // because audio setting is unsigned, can't check for < 0
            if (gSaveContext.audioSetting > 0xF0) {
                gSaveContext.audioSetting = FS_AUDIO_SURROUND;
            }
        } else {
            gSaveContext.zTargetSetting ^= 1;
        }
    } else if (pthis->stickRelX > 30) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);

        if (sSelectedSetting == FS_SETTING_AUDIO) {
            gSaveContext.audioSetting++;

            if (gSaveContext.audioSetting > FS_AUDIO_SURROUND) {
                gSaveContext.audioSetting = FS_AUDIO_STEREO;
            }
        } else {
            gSaveContext.zTargetSetting ^= 1;
        }
    }

    if ((pthis->stickRelY < -30) || (pthis->stickRelY > 30)) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        sSelectedSetting ^= 1;
    } else if (CHECK_BTN_ALL(input->press.button, BTN_A)) {
        Audio_PlaySoundGeneral(NA_SE_SY_FSEL_DECIDE_L, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        sSelectedSetting ^= 1;
    }
}

typedef struct {
    /* 0x00 */ void* texture[3];
    /* 0x0C */ u16 width[3];
    /* 0x12 */ u16 height;
} OptionsMenuTextureInfo; // size = 0x14

/* AddressSanitizer: global-buffer-overflow on address*/
static u16 gOptionsMenuHeadersHeight = 16;

static OptionsMenuTextureInfo gOptionsMenuHeaders[] = {
    {
        { gFileSelOptionsENGTex, gFileSelOptionsGERTex, gFileSelOptionsENGTex },
        { 128, 128, 128 },
        16,
    },
    {
        { gFileSelSOUNDENGTex, gFileSelSOUNDENGTex, gFileSelSOUNDFRATex },
        { 64, 64, 64 },
        16,
    },
    {
        { gFileSelLTargetingENGTex, gFileSelLTargetingGERTex, gFileSelLTargetingFRATex },
        { 64, 144, 64 },
        16,
    },
    {
        { gFileSelCheckBrightnessENGTex, gFileSelCheckBrightnessGERTex, gFileSelCheckBrightnessFRATex },
        { 128, 128, 128 },
        16,
    },
};

static OptionsMenuTextureInfo gOptionsMenuSettings[] = {
    {
        { gFileSelStereoENGTex, gFileSelStereoENGTex, gFileSelStereoFRATex },
        { 48, 48, 48 },
        16,
    },
    {
        { gFileSelMonoENGTex, gFileSelMonoENGTex, gFileSelMonoENGTex },
        { 48, 48, 48 },
        16,
    },
    {
        { gFileSelHeadsetENGTex, gFileSelHeadsetGERTex, gFileSelHeadsetFRATex },
        { 48, 48, 48 },
        16,
    },
    {
        { gFileSelSurroundENGTex, gFileSelSurroundENGTex, gFileSelSurroundENGTex },
        { 48, 48, 48 },
        16,
    },
    {
        { gFileSelSwitchENGTex, gFileSelSwitchGERTex, gFileSelSwitchFRATex },
        { 48, 80, 48 },
        16,
    },
    {
        { gFileSelHoldENGTex, gFileSelHoldGERTex, gFileSelHoldFRATex },
        { 48, 80, 48 },
        16,
    },
};

void FileChoose_DrawOptionsImpl(GameState* thisx) {
    static s16 cursorPrimRed = 255;
    static s16 cursorPrimGreen = 255;
    static s16 cursorPrimBlue = 255;
    static s16 cursorEnvRed = 0;
    static s16 cursorEnvGreen = 0;
    static s16 cursorEnvBlue = 0;
    static s16 cursorPulseDir = 1;
    static s16 cursorFlashTimer = 20;
    static s16 cursorPrimColors[][3] = {
        { 255, 255, 255 },
        { 0, 255, 255 },
    };
    static s16 cursorEnvColors[][3] = {
        { 0, 0, 0 },
        { 0, 150, 150 },
    };
    FileChooseContext* pthis = (FileChooseContext*)thisx;
    s16 cursorRed;
    s16 cursorGreen;
    s16 cursorBlue;
    s16 i;
    s16 j;
    s16 vtx;

    OPEN_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 848);

    cursorRed = ABS(cursorPrimRed - cursorPrimColors[cursorPulseDir][0]) / cursorFlashTimer;
    cursorGreen = ABS(cursorPrimGreen - cursorPrimColors[cursorPulseDir][1]) / cursorFlashTimer;
    cursorBlue = ABS(cursorPrimBlue - cursorPrimColors[cursorPulseDir][2]) / cursorFlashTimer;

    if (cursorPrimRed >= cursorPrimColors[cursorPulseDir][0]) {
        cursorPrimRed -= cursorRed;
    } else {
        cursorPrimRed += cursorRed;
    }

    if (cursorPrimGreen >= cursorPrimColors[cursorPulseDir][1]) {
        cursorPrimGreen -= cursorGreen;
    } else {
        cursorPrimGreen += cursorGreen;
    }

    if (cursorPrimBlue >= cursorPrimColors[cursorPulseDir][2]) {
        cursorPrimBlue -= cursorBlue;
    } else {
        cursorPrimBlue += cursorBlue;
    }

    cursorRed = ABS(cursorEnvRed - cursorEnvColors[cursorPulseDir][0]) / cursorFlashTimer;
    cursorGreen = ABS(cursorEnvGreen - cursorEnvColors[cursorPulseDir][1]) / cursorFlashTimer;
    cursorBlue = ABS(cursorEnvBlue - cursorEnvColors[cursorPulseDir][2]) / cursorFlashTimer;

    if (cursorEnvRed >= cursorEnvColors[cursorPulseDir][0]) {
        cursorEnvRed -= cursorRed;
    } else {
        cursorEnvRed += cursorRed;
    }

    if (cursorEnvGreen >= cursorEnvColors[cursorPulseDir][1]) {
        cursorEnvGreen -= cursorGreen;
    } else {
        cursorEnvGreen += cursorGreen;
    }

    if (cursorEnvBlue >= cursorEnvColors[cursorPulseDir][2]) {
        cursorEnvBlue -= cursorBlue;
    } else {
        cursorEnvBlue += cursorBlue;
    }

    if (--cursorFlashTimer == 0) {
        cursorPrimRed = cursorPrimColors[cursorPulseDir][0];
        cursorPrimGreen = cursorPrimColors[cursorPulseDir][1];
        cursorPrimBlue = cursorPrimColors[cursorPulseDir][2];

        cursorEnvRed = cursorEnvColors[cursorPulseDir][0];
        cursorEnvGreen = cursorEnvColors[cursorPulseDir][1];
        cursorEnvBlue = cursorEnvColors[cursorPulseDir][2];

        cursorFlashTimer = 20;

        if (++cursorPulseDir > 1) {
            cursorPulseDir = 0;
        }
    }

#ifndef RETAIL
    if (gSaveContext.language == LANGUAGE_GER) {
        gSPVertex(POLY_OPA_DISP++, D_80811E30, 32, 0);
    } else {
        gSPVertex(POLY_OPA_DISP++, D_80811D30, 32, 0);
    }
#else
    if(gSaveContext.language == LANGUAGE_GER)
    {
	    gSPVertex(POLY_OPA_DISP++, &gOptionsMenuVtx[16], 32, 0);
    }
    else
    {
	    gSPVertex(POLY_OPA_DISP++, &gOptionsMenuVtx[0], 32, 0);
    }
#endif

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

    for (i = 0, vtx = 0; i < 4; i++, vtx += 4) {
        gDPLoadTextureBlock(POLY_OPA_DISP++, gOptionsMenuHeaders[i].texture[gSaveContext.language], G_IM_FMT_IA,
                            G_IM_SIZ_8b, gOptionsMenuHeaders[i].width[gSaveContext.language],
                            gOptionsMenuHeaders[i].height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);
    }

#ifndef RETAIL
    if (gSaveContext.language == LANGUAGE_GER) {
        gSPVertex(POLY_OPA_DISP++, D_80812130, 32, 0);
    } else {
        gSPVertex(POLY_OPA_DISP++, D_80811F30, 32, 0);
    }
#else
    if(gSaveContext.language == LANGUAGE_GER)
    {
	    gSPVertex(POLY_OPA_DISP++, &gOptionsMenuVtx[64], 32, 0);
    }
    else
    {
	    gSPVertex(POLY_OPA_DISP++, &gOptionsMenuVtx[24], 32, 0);
    }
#endif

    for (i = 0, vtx = 0; i < 4; i++, vtx += 4) {
        gDPPipeSync(POLY_OPA_DISP++);
        if (i == gSaveContext.audioSetting) {
            if (sSelectedSetting == FS_SETTING_AUDIO) {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, cursorPrimRed, cursorPrimGreen, cursorPrimBlue,
                                pthis->titleAlpha[0]);
                gDPSetEnvColor(POLY_OPA_DISP++, cursorEnvRed, cursorEnvGreen, cursorEnvBlue, 255);
            } else {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[0]);
                gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
            }
        } else {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 120, 120, 120, pthis->titleAlpha[0]);
            gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
        }

        gDPLoadTextureBlock(POLY_OPA_DISP++, gOptionsMenuSettings[i].texture[gSaveContext.language], G_IM_FMT_IA,
                            G_IM_SIZ_8b, gOptionsMenuSettings[i].width[gSaveContext.language],
                            gOptionsMenuHeadersHeight, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);
    }

    for (; i < 6; i++, vtx += 4) {
        gDPPipeSync(POLY_OPA_DISP++);

        if (i == (gSaveContext.zTargetSetting + 4)) {
            if (sSelectedSetting != FS_SETTING_AUDIO) {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, cursorPrimRed, cursorPrimGreen, cursorPrimBlue,
                                pthis->titleAlpha[0]);
                gDPSetEnvColor(POLY_OPA_DISP++, cursorEnvRed, cursorEnvGreen, cursorEnvBlue, 0xFF);
            } else {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pthis->titleAlpha[0]);
                gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
            }
        } else {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 120, 120, 120, pthis->titleAlpha[0]);
            gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
        }

        gDPLoadTextureBlock(POLY_OPA_DISP++, gOptionsMenuSettings[i].texture[gSaveContext.language], G_IM_FMT_IA,
                            G_IM_SIZ_8b, gOptionsMenuSettings[i].width[gSaveContext.language],
                            gOptionsMenuHeadersHeight, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);
    }

    gDPPipeSync(POLY_OPA_DISP++);

    // check brightness bars
    gDPLoadTextureBlock_4b(POLY_OPA_DISP++, gFileSelBrightnessCheckTex, G_IM_FMT_IA, 96, 16, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 55, 55, 55, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 40, 40, 40, 255);
    gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);

    vtx += 4;

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 30, 30, 30, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSP1Quadrangle(POLY_OPA_DISP++, vtx, vtx + 2, vtx + 3, vtx + 1, 0);

    vtx += 4;

    // blue divider lines
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 255, 255, pthis->titleAlpha[0]);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

    gDPLoadTextureBlock_4b(POLY_OPA_DISP++, gFileSelOptionsDividerTex, G_IM_FMT_IA, 256, 2, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

    Matrix_Push();
    Matrix_Translate(0.0f, 0.1f, 0.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 1009),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(POLY_OPA_DISP++, gOptionsDividerTopVtx, 4, 0);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    Matrix_Pop();

    Matrix_Push();
    Matrix_Translate(0.0f, 0.2f, 0.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 1021),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(POLY_OPA_DISP++, gOptionsDividerMiddleVtx, 4, 0);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    Matrix_Pop();

    Matrix_Push();
    Matrix_Translate(0.0f, 0.4f, 0.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 1033),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(POLY_OPA_DISP++, gOptionsDividerBottomVtx, 4, 0);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    Matrix_Pop();

    CLOSE_DISPS(pthis->state.gfxCtx, "../z_file_nameset_PAL.c", 1040);
}

void FileChoose_DrawOptions(GameState* thisx) {
    FileChoose_DrawOptionsImpl(thisx);
}

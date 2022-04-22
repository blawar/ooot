#define INTERNAL_SRC_CODE_Z_MOJI_C
/**
 * Unused. A very simple utility for drawing text on screen.
 */

#include "global.h"
#include "z64global.h"
#include "def/z_moji.h"
#include "def/graph.h" // FORCE

u64 gMojiFontTLUTs[4][4] = { { 0x0000FFFF0000FFFF, 0x0000FFFF0000FFFF, 0x0000FFFF0000FFFF, 0x0000FFFF0000FFFF },
                             { 0x00000000FFFFFFFF, 0x00000000FFFFFFFF, 0x00000000FFFFFFFF, 0x00000000FFFFFFFF },
                             { 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF },
                             { 0x0000000000000000, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF } };

u64 gMojiFontTex[0x80] = {
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000,
    0x0000000000000000, 0x0000000000000000, 0x04C22C40028D5020, 0x0CCAACC021F91710, 0x04C22C4012493400,
    0x0082080001975110, 0x088A888004615241, 0x0080080043117530, 0x00A2080060055600, 0x0000000004400040,
    0x0022110000000080, 0x000FB00000000880, 0x040DA40000008800, 0x08CDE880022AA220, 0x08CDE88002AA2220,
    0x040DA4000CD10000, 0x000FB0008C510000, 0x0022110081100000, 0x00DFFD000AEEFFA0, 0x0DF22DD006611DC0,
    0x01122DD006719900, 0x011EED10077EF700, 0x0156299005589760, 0x0DD2299005599770, 0x04DFFD40026EF700,
    0x0000000000000000, 0x0033330004489980, 0x033CC33000CD1088, 0x033CC33002BF62A8, 0x0033332001104C80,
    0x011003300015C800, 0x033CC33002673220, 0x003FF30004409900, 0x0088000000000000, 0x05DFFD1007FFFF60,
    0x1CE00EC10FF00990, 0x1EE116610FF00110, 0x1EF456210FF66710, 0x1EF236610FF08990, 0x1EF10FE10FF00990,
    0x16ECCE2107FBBB20, 0x0111111000000000, 0x09B66FD027D88E60, 0x0992ED102FF02EE0, 0x099AE5102FF62EE0,
    0x099B75102FD64EE0, 0x0DDAE5102FD04EE0, 0x0DD2ED102FD00EE0, 0x09F66F9027D99F70, 0x0000000000000000,
    0x07FFFF008F711FF0, 0x2FD00FF08F711FF0, 0x2FD007708E611EE0, 0x27DDDF608E691EE0, 0x27764AA08EE99EE0,
    0x2FD06E808AE7FEA0, 0x07FA8E6088277A80, 0x0000000000000000, 0x077CCFF013266011, 0x077CCFF003766510,
    0x0239D72004533540, 0x002FF20001133110, 0x005FB10000033000, 0x055EE55001133110, 0x055EEDD002233000,
    0x000888808AABB888, 0x0000110000044510, 0x0462332000440110, 0x04C89AA000EEAB10, 0x0CE667200EF55FB0,
    0x0EE006600BF62B90, 0x0EE0066003FC8990, 0x04EEEEA000773BB0, 0x0000000008888800, 0x0990000000111000,
    0x0992244000011000, 0x0990880026EFDE20, 0x099BB5402EC33CE2, 0x0D9A25502EC33CE2, 0x0DDAA5502EC33CE2,
    0x09D6ED1026CBBC62, 0x0000000000000000, 0x0000000000000000, 0x0000000000011000, 0x05FBFFE08E6116E8,
    0x0FF403308F7117F8, 0x07FC8B308E6996E8, 0x05733BA08A6DD6A8, 0x0DD88A2008A779B2, 0x0110022000000000,
    0x000000808A011000, 0x0000080080A11000, 0x07744F7080A99000, 0x0231DF2084E60004, 0x0027DA20C8AA4C40,
    0x00573B2000A11800, 0x05546F5000A99800, 0x0222208002001888
};

// how big to draw the characters on screen
#define DISP_CHAR_WIDTH 8
#define DISP_CHAR_HEIGHT 8

// gMojiFontTex is a TEX_CHAR_COLS x TEX_CHAR_ROWS grid of characters,
// each character being TEX_CHAR_WIDTH x TEX_CHAR_HEIGHT in size.
// Each spot on the grid contains 4 characters, which are revealed by using different TLUTs.

#define TEX_CHAR_WIDTH 8
#define TEX_CHAR_HEIGHT 8

#define TEX_CHAR_COLS 2
#define TEX_CHAR_ROWS 16

// A character `c = 0bRRRRRCTT` maps to row 0bRRRRR, column 0bC and TLUT 0bTT.
#define GET_CHAR_TLUT_INDEX(c) (c & 3)
// `/ 4` matches the `& 4` (`(c & 4) / 4` is the column the character is in)
#define GET_TEX_CHAR_S(c) ((u16)(c & 4) * ((1 << 5) * TEX_CHAR_WIDTH / 4))
#define GET_TEX_CHAR_T(c) ((u16)(c >> 3) * ((1 << 5) * TEX_CHAR_HEIGHT))

u32 sFontColorRed = 255;
u32 sFontColorGreen = 255;
u32 sFontColorBlue = 255;
u32 sFontColorAlpha = 255;

s32 sScreenPosX = 0;
s32 sScreenPosY = 0;

s32 sCurTLUTIndex;

void Moji_SetColor(u32 red, u32 green, u32 blue, u32 alpha) {
    sFontColorRed = red;
    sFontColorGreen = green;
    sFontColorBlue = blue;
    sFontColorAlpha = alpha;
}

void Moji_SetPosition(s32 gridX, s32 gridY) {
    if (gridX >= SCREEN_WIDTH / DISP_CHAR_WIDTH) {
        sScreenPosX = SCREEN_WIDTH - DISP_CHAR_WIDTH;
    } else if (gridX < 0) {
        sScreenPosX = 0;
    } else {
        sScreenPosX = gridX * DISP_CHAR_WIDTH;
    }

    if (gridY >= SCREEN_HEIGHT / DISP_CHAR_HEIGHT) {
        sScreenPosY = SCREEN_HEIGHT - DISP_CHAR_HEIGHT;
    } else if (gridY < 0) {
        sScreenPosY = 0;
    } else {
        sScreenPosY = gridY * DISP_CHAR_HEIGHT;
    }
}

void Moji_DrawChar(GraphicsContext* gfxCtx, char c) {
    s32 pad[2];

    OPEN_DISPS(gfxCtx, "../z_moji.c", 86);

    if ((u32)gMojiFontTLUTs & 0xF) {
        osSyncPrintf("moji_tlut --> %X\n", gMojiFontTLUTs);
    }

    if (sCurTLUTIndex != GET_CHAR_TLUT_INDEX(c)) {
        gDPLoadTLUT(POLY_OPA_DISP++, 16, 256, gMojiFontTLUTs[GET_CHAR_TLUT_INDEX(c)]);
        sCurTLUTIndex = GET_CHAR_TLUT_INDEX(c);
    }
    gSPTextureRectangle(POLY_OPA_DISP++, sScreenPosX << 2, sScreenPosY << 2, (sScreenPosX + DISP_CHAR_WIDTH) << 2,
                        (sScreenPosY + DISP_CHAR_HEIGHT) << 2, G_TX_RENDERTILE, GET_TEX_CHAR_S(c), GET_TEX_CHAR_T(c),
                        (1 << 10) * TEX_CHAR_WIDTH / DISP_CHAR_WIDTH, (1 << 10) * TEX_CHAR_HEIGHT / DISP_CHAR_HEIGHT);

    CLOSE_DISPS(gfxCtx, "../z_moji.c", 123);
}

/**
 * Does not work as is in most cases.
 * Can work if the render mode, combiner and possibly other settings are set correctly.
 * For example this works with the render mode used in `GfxPrint_Setup`,
 * and `G_CC_MODULATEI_PRIM` for both combiner cycles.
 */
void Moji_DrawString(GraphicsContext* gfxCtx, const char* str) {
    s32 i;

    OPEN_DISPS(gfxCtx, "../z_moji.c", 137);

    if ((u32)gMojiFontTex & 0xF) {
        osSyncPrintf("font_ff --> %X\n", gMojiFontTex);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sFontColorRed, sFontColorGreen, sFontColorBlue, sFontColorAlpha);

    gDPLoadTextureBlock_4b(POLY_OPA_DISP++, (s32)gMojiFontTex, G_IM_FMT_CI, TEX_CHAR_COLS * TEX_CHAR_WIDTH,
                           TEX_CHAR_ROWS * TEX_CHAR_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    sCurTLUTIndex = -1;

    for (i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case '\t':
                sScreenPosX = (((sScreenPosX / DISP_CHAR_WIDTH) / 8) + 1) * DISP_CHAR_WIDTH * 8;
                if (sScreenPosX >= SCREEN_WIDTH) {
                    sScreenPosX = 0;
                    sScreenPosY += DISP_CHAR_HEIGHT;
                    if (sScreenPosY >= SCREEN_HEIGHT) {
                        sScreenPosY = 0;
                    }
                }
                break;
            case '\n':
            case '\r':
                sScreenPosX = 0;
                sScreenPosY += DISP_CHAR_HEIGHT;
                if (sScreenPosY >= SCREEN_HEIGHT) {
                    sScreenPosY = 0;
                }
                break;
            default:
                Moji_DrawChar(gfxCtx, str[i]);
                sScreenPosX += DISP_CHAR_WIDTH;
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_moji.c", 181);
}

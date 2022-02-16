#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MAG_Z_EN_MAG_C
#include "actor_common.h"
/*
 * File: z_en_mag.c
 * Overlay: ovl_En_Mag
 * Description: Title Screen Manager & Logo
 */

#include "z_en_mag.h"
#include "objects/object_mag/object_mag.h"
#include "def/code_8006C3A0.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/graph.h"
#include "def/z_common_data.h"
#include "def/z_kanfont.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnMag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMag_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMag_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMag_Draw(Actor* thisx, GlobalContext* globalCtx);

static s16 textAlpha_28 = 0;

static s16 textFadeDirection_28 = 0;

static s16 textFadeTimer_28 = 0;

static u8 noControllerFontIndexes_28[] = {
    0x17, 0x18, 0x0C, 0x18, 0x17, 0x1D, 0x1B, 0x18, 0x15, 0x15, 0x0E, 0x1B,
};

static u8 pressStartFontIndexes_28[] = {
    0x19, 0x1B, 0x0E, 0x1C, 0x1C, 0x1C, 0x1D, 0x0A, 0x1B, 0x1D,
};

static void* effectMaskTextures_28[] = {
    gTitleEffectMask00Tex, gTitleEffectMask01Tex, gTitleEffectMask02Tex,
    gTitleEffectMask10Tex, gTitleEffectMask11Tex, gTitleEffectMask12Tex,
    gTitleEffectMask20Tex, gTitleEffectMask21Tex, gTitleEffectMask22Tex,
};


ActorInit En_Mag_InitVars = {
    ACTOR_EN_MAG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_MAG,
    sizeof(EnMag),
    (ActorFunc)EnMag_Init,
    (ActorFunc)EnMag_Destroy,
    (ActorFunc)EnMag_Update,
    (ActorFunc)EnMag_Draw,
    (ActorFunc)EnMag_Reset,
};

static s16 sDelayTimer = 0;

void EnMag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMag* pthis = (EnMag*)thisx;

    YREG(1) = 63;
    YREG(3) = 80;
    YREG(4) = 255;
    YREG(5) = 30;
    YREG(6) = 30;
    YREG(7) = 119;
    YREG(8) = 7;
    YREG(9) = 5;
    YREG(10) = 3;

    VREG(4) = 1;
    VREG(5) = 6;
    VREG(6) = 2;

    pthis->copyrightAlphaStep = 6;
    pthis->fadeOutAlphaStep = 10;

    VREG(19) = 99;
    VREG(21) = 9;
    VREG(23) = 10;
    VREG(24) = 8;

    pthis->effectScroll = 0;
    pthis->unk_E30C = 0;

    pthis->effectPrimColor[0] = 0.0f;
    pthis->effectPrimColor[1] = 100.0f;
    pthis->effectPrimColor[2] = 170.0f;
    pthis->effectEnvColor[0] = 0.0f;
    pthis->effectEnvColor[1] = 100.0f;
    pthis->effectEnvColor[2] = 0.0f;

    pthis->effectFadeInTimer = 40;

    pthis->effectFadeInState = pthis->effectPrimLodFrac = pthis->globalState = pthis->effectAlpha = pthis->mainAlpha =
        pthis->subAlpha = pthis->copyrightAlpha = 0.0f;

    if (gSaveContext.unk_13E7 != 0) {
        pthis->mainAlpha = 210;
        pthis->subAlpha = 255;
        pthis->copyrightAlpha = 255;

        pthis->effectPrimLodFrac = 128.0f;
        pthis->effectAlpha = 255.0f;

        pthis->effectPrimColor[0] = 170;
        pthis->effectPrimColor[1] = 255.0f;
        pthis->effectPrimColor[2] = 255.0f;
        pthis->effectEnvColor[0] = 200.0f;
        pthis->effectEnvColor[1] = 255.0f;
        pthis->effectEnvColor[2] = 0;

        gSaveContext.unk_13E7 = 0;
        pthis->globalState = MAG_STATE_DISPLAY;
        sDelayTimer = 20;
        gSaveContext.fadeDuration = 1;
        gSaveContext.unk_1419 = 255;
    }

    Font_LoadOrderedFont(&pthis->font);

    pthis->unk_E316 = 0;
    pthis->unk_E318 = 0;
    pthis->unk_E31C = 0;
    pthis->unk_E320 = 0;
}

void EnMag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnMag_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad[2];
    EnMag* pthis = (EnMag*)thisx;

    if (gSaveContext.fileNum != 0xFEDC) {
        if (pthis->globalState < MAG_STATE_DISPLAY) {
            if (CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_START) ||
                CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_A) ||
                CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_B)) {

                Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

                pthis->mainAlpha = 210;
                pthis->subAlpha = 255;
                pthis->copyrightAlpha = 255;

                pthis->effectPrimLodFrac = 128.0f;
                pthis->effectAlpha = 255.0f;

                pthis->effectPrimColor[0] = 170;
                pthis->effectPrimColor[1] = 255.0f;
                pthis->effectPrimColor[2] = 255.0f;
                pthis->effectEnvColor[0] = 200.0f;
                pthis->effectEnvColor[1] = 255.0f;
                pthis->effectEnvColor[2] = 0;

                pthis->globalState = MAG_STATE_DISPLAY;
                sDelayTimer = 20;
                gSaveContext.fadeDuration = 1;
                gSaveContext.unk_1419 = 255;
            }
        } else if (pthis->globalState >= MAG_STATE_DISPLAY) {
            if (sDelayTimer == 0) {
                if (CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_START) ||
                    CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_A) ||
                    CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_B)) {

                    if (globalCtx->sceneLoadFlag != 20) {
                        Audio_SetCutsceneFlag(0);

                        Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);

                        gSaveContext.gameMode = 2;
                        globalCtx->sceneLoadFlag = 20;
                        globalCtx->fadeTransition = 2;
                    }

                    pthis->copyrightAlphaStep = 15;
                    pthis->fadeOutAlphaStep = 25;
                    pthis->globalState = MAG_STATE_FADE_OUT;
                }
            } else {
                sDelayTimer--;
            }
        }
    }

    if (pthis->globalState == MAG_STATE_FADE_IN) {
        if (pthis->effectFadeInState == 0) {
            pthis->effectAlpha += 6.375f;
            pthis->effectPrimLodFrac += 0.8f;

            pthis->effectPrimColor[0] += 6.375f;
            pthis->effectPrimColor[1] += 3.875f;
            pthis->effectPrimColor[2] += 2.125f;
            pthis->effectEnvColor[0] += 6.375f;
            pthis->effectEnvColor[1] += 3.875f;

            pthis->effectFadeInTimer--;

            if (pthis->effectFadeInTimer == 0) {
                pthis->effectPrimLodFrac = 32.0f;
                pthis->effectAlpha = 255.0f;

                pthis->effectPrimColor[0] = 255.0f;
                pthis->effectPrimColor[1] = 255.0f;
                pthis->effectPrimColor[2] = 255.0f;
                pthis->effectEnvColor[0] = 255.0f;
                pthis->effectEnvColor[1] = 255.0f;

                pthis->effectFadeInTimer = 40;
                pthis->effectFadeInState = 1;
            }
        } else if (pthis->effectFadeInState == 1) {
            pthis->effectPrimColor[0] += -2.125f;
            pthis->effectEnvColor[0] += -1.375f;

            pthis->effectPrimLodFrac += 2.4f;

            pthis->effectFadeInTimer--;

            if (pthis->effectFadeInTimer == 0) {
                pthis->effectPrimLodFrac = 128.0f;

                pthis->effectPrimColor[0] = 170.0f;
                pthis->effectEnvColor[0] = 200.0f;

                pthis->effectFadeInTimer = 32;
                pthis->effectFadeInState = 2;
            }
        }

        if (pthis->effectAlpha > 160) {
            pthis->mainAlpha += VREG(5);
            if (pthis->mainAlpha >= 210.0f) {
                pthis->mainAlpha = 210.0f;
            }

            if (pthis->mainAlpha >= 210) {
                pthis->subAlpha += VREG(6);
                if (pthis->subAlpha >= 255.0f) {
                    pthis->subAlpha = 255.0f;
                }

                if (pthis->subAlpha >= 200) {
                    pthis->copyrightAlpha += pthis->copyrightAlphaStep;
                    if (pthis->copyrightAlpha >= 255.0f) {
                        pthis->copyrightAlpha = 255.0f;
                        pthis->globalState = MAG_STATE_DISPLAY;
                        sDelayTimer = 20;
                    }
                }
            }
        }
    } else if (pthis->globalState == MAG_STATE_FADE_OUT) {
        pthis->effectAlpha -= pthis->fadeOutAlphaStep;
        if (pthis->effectAlpha < 0.0f) {
            pthis->effectAlpha = 0.0f;
        }

        pthis->mainAlpha -= pthis->fadeOutAlphaStep;
        if (pthis->mainAlpha < 0.0f) {
            pthis->mainAlpha = 0.0f;
        }

        pthis->subAlpha -= pthis->fadeOutAlphaStep;
        if (pthis->subAlpha < 0.0f) {
            pthis->subAlpha = 0.0f;
        }

        pthis->copyrightAlpha -= pthis->copyrightAlphaStep;
        if (pthis->copyrightAlpha < 0.0f) {
            pthis->copyrightAlpha = 0.0f;
            pthis->globalState = MAG_STATE_POST_DISPLAY;
        }
    }

    if (pthis->globalState == MAG_STATE_INITIAL) {
        if (Flags_GetEnv(globalCtx, 3)) {
            pthis->effectFadeInTimer = 40;
            pthis->globalState = MAG_STATE_FADE_IN;
        }
    } else if (pthis->globalState == MAG_STATE_DISPLAY) {
        if (Flags_GetEnv(globalCtx, 4)) {
            pthis->globalState = MAG_STATE_FADE_OUT;
        }
    }
}

void EnMag_DrawTextureI8(Gfx** gfxp, void* texture, s16 texWidth, s16 texHeight, s16 rectLeft, s16 rectTop,
                         s16 rectWidth, s16 rectHeight, u16 dsdx, u16 dtdy) {
    Gfx* gfx = *gfxp;

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, texWidth, texHeight, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + rectWidth) << 2, (rectTop + rectHeight) << 2,
                        G_TX_RENDERTILE, 0, 0, dsdx, dtdy);

    *gfxp = gfx;
}

void EnMag_DrawEffectTextures(Gfx** gfxp, void* maskTex, void* effectTex, s16 maskWidth, s16 maskHeight,
                              s16 effectWidth, s16 effectHeight, s16 rectLeft, s16 rectTop, s16 rectWidth,
                              s16 rectHeight, u16 dsdx, u16 dtdy, u16 shifts, u16 shiftt, u16 flag, EnMag* pthis) {
    Gfx* gfx = *gfxp;

    gDPLoadMultiBlock_4b(gfx++, maskTex, 0x0000, 0, G_IM_FMT_I, maskWidth, maskHeight, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (!flag) {
        gDPLoadMultiBlock(gfx++, effectTex, 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, effectWidth, effectHeight, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, shifts, shiftt);

        gDPSetTileSize(gfx++, 1, 0, pthis->effectScroll & 0x7F, 0x7C, (pthis->effectScroll & 0x7F) + 0x7C);
    }

    gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + rectWidth) << 2, (rectTop + rectHeight) << 2,
                        G_TX_RENDERTILE, 0, 0, dsdx, dtdy);

    *gfxp = gfx;
}

void EnMag_DrawImageRGBA32(Gfx** gfxp, s16 centerX, s16 centerY, u8* source, u32 width, u32 height) {
    Gfx* gfx = *gfxp;
    u8* curTexture;
    s32 textureCount;
    u32 rectLeft;
    u32 rectTop;
    u32 textureHeight;
    s32 remainingSize;
    s32 textureSize;
    s32 pad;
    s32 i;

    func_80094D28(&gfx);

    curTexture = source;
    rectLeft = centerX - (width / 2);
    rectTop = centerY - (height / 2);
    textureHeight = 4096 / (width << 2);
    remainingSize = (width * height) << 2;
    textureSize = (width * textureHeight) << 2;
    textureCount = remainingSize / textureSize;
    if ((remainingSize % textureSize) != 0) {
        textureCount += 1;
    }

    gDPSetTileCustom(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, textureHeight, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                     G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    remainingSize -= textureSize;

    for (i = 0; i < textureCount; i++) {
        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, curTexture);

        gDPLoadSync(gfx++);
        gDPLoadTile(gfx++, G_TX_LOADTILE, 0, 0, (width - 1) << 2, (textureHeight - 1) << 2);

        gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + (s32)width) << 2,
                            (rectTop + textureHeight) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

        curTexture += textureSize;
        rectTop += textureHeight;

        if ((remainingSize - textureSize) < 0) {
            if (remainingSize > 0) {
                textureHeight = remainingSize / (s32)(width << 2);
                remainingSize -= textureSize;

                gDPSetTileCustom(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, textureHeight, 0,
                                 G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                 G_TX_NOLOD, G_TX_NOLOD);
            }
        } else {
            remainingSize -= textureSize;
        }
    }

    *gfxp = gfx;
}

void EnMag_DrawCharTexture(Gfx** gfxp, void* texture, s32 rectLeft, s32 rectTop) {
    Gfx* gfx = *gfxp;

    YREG(0) = 1024.0f / (YREG(1) / 100.0f);
    YREG(2) = 16.0f * (YREG(1) / 100.0f);

    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + YREG(2)) << 2, (rectTop + YREG(2)) << 2,
                        G_TX_RENDERTILE, 0, 0, YREG(0), YREG(0));

    *gfxp = gfx;
}

void EnMag_DrawInner(Actor* thisx, GlobalContext* globalCtx, Gfx** gfxp) {
    EnMag* pthis = (EnMag*)thisx;
    Font* font = &pthis->font;
    s32 pad;
    Gfx* gfx = *gfxp;
    u16 i, j, k;
    u16 rectLeft;
    u16 rectTop;

    gSPSegment(gfx++, 0x06, gObjectTable[pthis->actor.objBankIndex].vromStart.get());

    func_8009457C(&gfx);

    pthis->effectScroll -= 2;

    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_CLD_SURF2);
    gDPSetCombineLERP(gfx++, TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, 1, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);

    gDPSetPrimColor(gfx++, 0, (s16)pthis->effectPrimLodFrac, (s16)pthis->effectPrimColor[0],
                    (s16)pthis->effectPrimColor[1], (s16)pthis->effectPrimColor[2], (s16)pthis->effectAlpha);
    gDPSetEnvColor(gfx++, (s16)pthis->effectEnvColor[0], (s16)pthis->effectEnvColor[1], (s16)pthis->effectEnvColor[2],
                   255);

    if ((s16)pthis->effectPrimLodFrac != 0) {
        for (k = 0, i = 0, rectTop = 0; i < 3; i++, rectTop += 64) {
            for (j = 0, rectLeft = 56; j < 3; j++, k++, rectLeft += 64) {
                EnMag_DrawEffectTextures(&gfx, effectMaskTextures_28[k], gTitleFlameEffectTex, 64, 64, 32, 32, rectLeft,
                                         rectTop, 64, 64, 1024, 1024, 1, 1, k, pthis);
            }
        }
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (s16)pthis->mainAlpha);

    if ((s16)pthis->mainAlpha != 0) {
        EnMag_DrawImageRGBA32(&gfx, 152, 100, (u8*)gTitleZeldaShieldLogoMQTex, 160, 160);
    }

    func_8009457C(&gfx);

    gDPPipeSync(gfx++);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

    if ((s16)pthis->mainAlpha < 100) {
        gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    } else {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    }

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (s16)pthis->mainAlpha);
    gDPSetEnvColor(gfx++, 0, 0, 100, 255);

    if ((s16)pthis->mainAlpha != 0) {
        EnMag_DrawTextureI8(&gfx, gTitleTheLegendOfTextTex, 72, 8, 146, 73, 72, 8, 1024, 1024);
        EnMag_DrawTextureI8(&gfx, gTitleOcarinaOfTimeTMTextTex, 96, 8, 144, 127, 96, 8, 1024, 1024);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 100, 150, 255, (s16)pthis->mainAlpha);
        gDPSetEnvColor(gfx++, 20, 80, 160, 255);

        EnMag_DrawTextureI8(&gfx, gTitleTheLegendOfTextTex, 72, 8, 145, 72, 72, 8, 1024, 1024);
        EnMag_DrawTextureI8(&gfx, gTitleOcarinaOfTimeTMTextTex, 96, 8, 143, 126, 96, 8, 1024, 1024);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (s16)pthis->subAlpha);

        EnMag_DrawImageRGBA32(&gfx, 174, 145, (u8*)gTitleMasterQuestSubtitleTex, 128, 32);
    }

    func_8009457C(&gfx);

    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    gDPSetPrimColor(gfx++, 0, 0, (s16)pthis->copyrightAlpha, (s16)pthis->copyrightAlpha, (s16)pthis->copyrightAlpha,
                    (s16)pthis->copyrightAlpha);

    if ((s16)pthis->copyrightAlpha != 0) {
        gDPLoadTextureBlock(gfx++, gTitleCopyright19982003Tex, G_IM_FMT_IA, G_IM_SIZ_8b, 160, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, 312, 792, 952, 856, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    if (gSaveContext.fileNum == 0xFEDC) {
        // Draw "NO CONTROLLER" Text
        textAlpha_28 = textFadeTimer_28 * 10;
        if (textAlpha_28 >= 255) {
            textAlpha_28 = 255;
        }

        // Text Shadow
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                          0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, textAlpha_28);

        rectLeft = VREG(19) + 1;
        for (i = 0; i < ARRAY_COUNT(noControllerFontIndexes_28); i++) {
            EnMag_DrawCharTexture(&gfx, font->fontBuf + noControllerFontIndexes_28[i] * FONT_CHAR_TEX_SIZE, rectLeft,
                                  YREG(10) + 172);
            rectLeft += VREG(21);
            if (i == 1) {
                rectLeft += VREG(23);
            }
        }

        // Actual Text
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 100, 255, 255, textAlpha_28);

        rectLeft = VREG(19);
        for (i = 0; i < ARRAY_COUNT(noControllerFontIndexes_28); i++) {
            EnMag_DrawCharTexture(&gfx, font->fontBuf + noControllerFontIndexes_28[i] * FONT_CHAR_TEX_SIZE, rectLeft,
                                  YREG(10) + 171);
            rectLeft += VREG(21);
            if (i == 1) {
                rectLeft += VREG(23);
            }
        }
    } else if (pthis->copyrightAlpha >= 200.0f) {
        // Draw "PRESS START" Text
        textAlpha_28 = textFadeTimer_28 * 10;
        if (textAlpha_28 >= 255) {
            textAlpha_28 = 255;
        }

        // Text Shadow
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                          0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, textAlpha_28);

        rectLeft = YREG(7) + 1;
        for (i = 0; i < ARRAY_COUNT(pressStartFontIndexes_28); i++) {
            EnMag_DrawCharTexture(&gfx, font->fontBuf + pressStartFontIndexes_28[i] * FONT_CHAR_TEX_SIZE, rectLeft,
                                  YREG(10) + 172);
            rectLeft += YREG(8);
            if (i == 4) {
                rectLeft += YREG(9);
            }
        }

        // Actual Text
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, YREG(4), YREG(5), YREG(6), textAlpha_28);

        rectLeft = YREG(7);
        for (i = 0; i < ARRAY_COUNT(pressStartFontIndexes_28); i++) {
            EnMag_DrawCharTexture(&gfx, font->fontBuf + pressStartFontIndexes_28[i] * FONT_CHAR_TEX_SIZE, rectLeft,
                                  YREG(10) + 171);
            rectLeft += YREG(8);
            if (i == 4) {
                rectLeft += YREG(9);
            }
        }
    }

    if (textFadeDirection_28 != 0) {
        if (--textFadeTimer_28 == 0) {
            textFadeDirection_28 = 0;
        }
    } else {
        if (++textFadeTimer_28 >= 26) {
            textFadeDirection_28 = 1;
        }
    }

    *gfxp = gfx;
}

void EnMag_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    Gfx* gfx;
    Gfx* gfxRef;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_mag.c", 1151);

    gfxRef = POLY_OPA_DISP;
    gfx = Graph_GfxPlusOne(gfxRef);
    gSPDisplayList(OVERLAY_DISP++, gfx);

    EnMag_DrawInner(thisx, globalCtx, &gfx);

    gSPEndDisplayList(gfx++);
    Graph_BranchDlist(gfxRef, gfx);
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_mag.c", 1161);
}

void EnMag_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    textAlpha_28 = 0;

    textFadeDirection_28 = 0;

    textFadeTimer_28 = 0;

    En_Mag_InitVars = {
        ACTOR_EN_MAG,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_MAG,
        sizeof(EnMag),
        (ActorFunc)EnMag_Init,
        (ActorFunc)EnMag_Destroy,
        (ActorFunc)EnMag_Update,
        (ActorFunc)EnMag_Draw,
        (ActorFunc)EnMag_Reset,
    };

    sDelayTimer = 0;

}

#define INTERNAL_SRC_CODE_Z_LIFEMETER_C
#include "global.h"
#include "z64interface.h"
#include "z64global.h"
#include "framerate.h"
#include "z64save.h"
#include "sfx.h"
#include "gfx_align.h""
#include "textures/parameter_static/parameter_static.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_lifemeter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

static s16 sHeartsPrimColors[3][3] = {
    { HEARTS_PRIM_R, HEARTS_PRIM_G, HEARTS_PRIM_B },
    { HEARTS_BURN_PRIM_R, HEARTS_BURN_PRIM_G, HEARTS_BURN_PRIM_B },    // unused
    { HEARTS_DROWN_PRIM_R, HEARTS_DROWN_PRIM_G, HEARTS_DROWN_PRIM_B }, // unused
};

static s16 sHeartsEnvColors[3][3] = {
    { HEARTS_ENV_R, HEARTS_ENV_G, HEARTS_ENV_B },
    { HEARTS_BURN_ENV_R, HEARTS_BURN_ENV_G },                       // unused
    { HEARTS_DROWN_ENV_R, HEARTS_DROWN_ENV_G, HEARTS_DROWN_ENV_B }, // unused
};

static s16 sHeartsPrimFactors[3][3] = {
    {
        HEARTS_PRIM_R - HEARTS_PRIM_R,
        HEARTS_PRIM_G - HEARTS_PRIM_G,
        HEARTS_PRIM_B - HEARTS_PRIM_B,
    },
    // unused
    {
        HEARTS_BURN_PRIM_R - HEARTS_PRIM_R,
        HEARTS_BURN_PRIM_G - HEARTS_PRIM_G,
        HEARTS_BURN_PRIM_B - HEARTS_PRIM_B,
    },
    // unused
    {
        HEARTS_DROWN_PRIM_R - HEARTS_PRIM_R,
        HEARTS_DROWN_PRIM_G - HEARTS_PRIM_G,
        HEARTS_DROWN_PRIM_B - HEARTS_PRIM_B,
    },
};

static s16 sHeartsEnvFactors[3][3] = {
    {
        HEARTS_ENV_R - HEARTS_ENV_R,
        HEARTS_ENV_G - HEARTS_ENV_G,
        HEARTS_ENV_B - HEARTS_ENV_B,
    },
    // unused
    {
        HEARTS_BURN_ENV_R - HEARTS_ENV_R,
        HEARTS_BURN_ENV_G - HEARTS_ENV_G,
        HEARTS_BURN_ENV_B - HEARTS_ENV_B,
    },
    // unused
    {
        HEARTS_DROWN_ENV_R - HEARTS_ENV_R,
        HEARTS_DROWN_ENV_G - HEARTS_ENV_G,
        HEARTS_DROWN_ENV_B - HEARTS_ENV_B,
    },
};

static s16 sHeartsDDPrimColors[3][3] = {
    { HEARTS_DD_PRIM_R, HEARTS_DD_PRIM_G, HEARTS_DD_PRIM_B },
    { HEARTS_BURN_PRIM_R, HEARTS_BURN_PRIM_G, HEARTS_BURN_PRIM_B },    // unused
    { HEARTS_DROWN_PRIM_R, HEARTS_DROWN_PRIM_G, HEARTS_DROWN_PRIM_B }, // unused
};

static s16 sHeartsDDEnvColors[3][3] = {
    { HEARTS_DD_ENV_R, HEARTS_DD_ENV_G, HEARTS_DD_ENV_B },
    { HEARTS_BURN_ENV_R, HEARTS_BURN_ENV_G, HEARTS_BURN_ENV_B },    // unused
    { HEARTS_DROWN_ENV_R, HEARTS_DROWN_ENV_G, HEARTS_DROWN_ENV_B }, // unused
};

static s16 sHeartsDDPrimFactors[3][3] = {
    {
        HEARTS_DD_PRIM_R - HEARTS_DD_PRIM_R,
        HEARTS_DD_PRIM_G - HEARTS_DD_PRIM_G,
        HEARTS_DD_PRIM_B - HEARTS_DD_PRIM_B,
    },
    // unused
    {
        HEARTS_BURN_PRIM_R - HEARTS_DD_PRIM_R,
        HEARTS_BURN_PRIM_G - HEARTS_DD_PRIM_G,
        HEARTS_BURN_PRIM_B - HEARTS_DD_PRIM_B,
    },
    // unused
    {
        HEARTS_DROWN_PRIM_R - HEARTS_DD_PRIM_R,
        HEARTS_DROWN_PRIM_G - HEARTS_DD_PRIM_G,
        HEARTS_DROWN_PRIM_B - HEARTS_DD_PRIM_B,
    },
};

static s16 sHeartsDDEnvFactors[3][3] = {
    {
        HEARTS_DD_ENV_R - HEARTS_DD_ENV_R,
        HEARTS_DD_ENV_G - HEARTS_DD_ENV_G,
        HEARTS_DD_ENV_B - HEARTS_DD_ENV_B,
    },
    // unused
    {
        HEARTS_BURN_ENV_R - HEARTS_DD_ENV_R,
        HEARTS_BURN_ENV_G - HEARTS_DD_ENV_G,
        HEARTS_BURN_ENV_B - HEARTS_DD_ENV_B,
    },
    // unused
    {
        HEARTS_DROWN_ENV_R - HEARTS_DD_ENV_R,
        HEARTS_DROWN_ENV_G - HEARTS_DD_ENV_G,
        HEARTS_DROWN_ENV_B - HEARTS_DD_ENV_B,
    },
};

// Current colors for the double defense hearts
s16 sBeatingHeartsDDPrim[3];
s16 sBeatingHeartsDDEnv[3];
s16 sHeartsDDPrim[2][3];
s16 sHeartsDDEnv[2][3];

void HealthMeter_Init(GlobalContext* globalCtx) {
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    interfaceCtx->beatingHeartOscillator = interfaceCtx->heartColorOscillator = 0;
    interfaceCtx->beatingHeartOscillatorDirection = interfaceCtx->heartColorOscillatorDirection = 0;

    interfaceCtx->heartsPrimR[0] = HEARTS_PRIM_R;
    interfaceCtx->heartsPrimG[0] = HEARTS_PRIM_G;
    interfaceCtx->heartsPrimB[0] = HEARTS_PRIM_B;

    interfaceCtx->heartsEnvR[0] = HEARTS_ENV_R;
    interfaceCtx->heartsEnvG[0] = HEARTS_ENV_G;
    interfaceCtx->heartsEnvB[0] = HEARTS_ENV_B;

    interfaceCtx->heartsPrimR[1] = HEARTS_PRIM_R;
    interfaceCtx->heartsPrimG[1] = HEARTS_PRIM_G;
    interfaceCtx->heartsPrimB[1] = HEARTS_PRIM_B;

    interfaceCtx->heartsEnvR[1] = HEARTS_ENV_R;
    interfaceCtx->heartsEnvG[1] = HEARTS_ENV_G;
    interfaceCtx->heartsEnvB[1] = HEARTS_ENV_B;

    sHeartsDDPrim[0][0] = sHeartsDDPrim[1][0] = HEARTS_DD_PRIM_R;
    sHeartsDDPrim[0][1] = sHeartsDDPrim[1][1] = HEARTS_DD_PRIM_G;
    sHeartsDDPrim[0][2] = sHeartsDDPrim[1][2] = HEARTS_DD_PRIM_B;

    sHeartsDDEnv[0][0] = sHeartsDDEnv[1][0] = HEARTS_DD_ENV_R;
    sHeartsDDEnv[0][1] = sHeartsDDEnv[1][1] = HEARTS_DD_ENV_G;
    sHeartsDDEnv[0][2] = sHeartsDDEnv[1][2] = HEARTS_DD_ENV_B;
}

void HealthMeter_Update(GlobalContext* globalCtx) {
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    f32 factor = interfaceCtx->heartColorOscillator * 0.1f;
    f32 ddFactor;
    s32 type = 0;
    s32 ddType;
    s16 rFactor;
    s16 gFactor;
    s16 bFactor;

    if (interfaceCtx) {}

    if (interfaceCtx->heartColorOscillatorDirection != 0) {
        interfaceCtx->heartColorOscillator--;
        if (interfaceCtx->heartColorOscillator <= 0) {
            interfaceCtx->heartColorOscillator = 0;
            interfaceCtx->heartColorOscillatorDirection = 0;
        }
    } else {
        interfaceCtx->heartColorOscillator++;
        if (interfaceCtx->heartColorOscillator >= 10) {
            interfaceCtx->heartColorOscillator = 10;
            interfaceCtx->heartColorOscillatorDirection = 1;
        }
    }

    ddFactor = factor;

    interfaceCtx->heartsPrimR[0] = HEARTS_PRIM_R;
    interfaceCtx->heartsPrimG[0] = HEARTS_PRIM_G;
    interfaceCtx->heartsPrimB[0] = HEARTS_PRIM_B;

    interfaceCtx->heartsEnvR[0] = HEARTS_ENV_R;
    interfaceCtx->heartsEnvG[0] = HEARTS_ENV_G;
    interfaceCtx->heartsEnvB[0] = HEARTS_ENV_B;

    interfaceCtx->heartsPrimR[1] = sHeartsPrimColors[type][0];
    interfaceCtx->heartsPrimG[1] = sHeartsPrimColors[type][1];
    interfaceCtx->heartsPrimB[1] = sHeartsPrimColors[type][2];

    interfaceCtx->heartsEnvR[1] = sHeartsEnvColors[type][0];
    interfaceCtx->heartsEnvG[1] = sHeartsEnvColors[type][1];
    interfaceCtx->heartsEnvB[1] = sHeartsEnvColors[type][2];

    rFactor = sHeartsPrimFactors[0][0] * factor;
    gFactor = sHeartsPrimFactors[0][1] * factor;
    bFactor = sHeartsPrimFactors[0][2] * factor;

    interfaceCtx->beatingHeartPrim[0] = (u8)(rFactor + HEARTS_PRIM_R) & 0xFF;
    interfaceCtx->beatingHeartPrim[1] = (u8)(gFactor + HEARTS_PRIM_G) & 0xFF;
    interfaceCtx->beatingHeartPrim[2] = (u8)(bFactor + HEARTS_PRIM_B) & 0xFF;

    rFactor = sHeartsEnvFactors[0][0] * factor;
    gFactor = sHeartsEnvFactors[0][1] * factor;
    bFactor = sHeartsEnvFactors[0][2] * factor;

    ddType = type;

    interfaceCtx->beatingHeartEnv[0] = (u8)(rFactor + HEARTS_ENV_R) & 0xFF;
    interfaceCtx->beatingHeartEnv[1] = (u8)(gFactor + HEARTS_ENV_G) & 0xFF;
    interfaceCtx->beatingHeartEnv[2] = (u8)(bFactor + HEARTS_ENV_B) & 0xFF;

    sHeartsDDPrim[0][0] = HEARTS_DD_PRIM_R;
    sHeartsDDPrim[0][1] = HEARTS_DD_PRIM_G;
    sHeartsDDPrim[0][2] = HEARTS_DD_PRIM_B;

    sHeartsDDEnv[0][0] = HEARTS_DD_ENV_R;
    sHeartsDDEnv[0][1] = HEARTS_DD_ENV_G;
    sHeartsDDEnv[0][2] = HEARTS_DD_ENV_B;

    sHeartsDDPrim[1][0] = sHeartsDDPrimColors[ddType][0];
    sHeartsDDPrim[1][1] = sHeartsDDPrimColors[ddType][1];
    sHeartsDDPrim[1][2] = sHeartsDDPrimColors[ddType][2];

    sHeartsDDEnv[1][0] = sHeartsDDEnvColors[ddType][0];
    sHeartsDDEnv[1][1] = sHeartsDDEnvColors[ddType][1];
    sHeartsDDEnv[1][2] = sHeartsDDEnvColors[ddType][2];

    rFactor = sHeartsDDPrimFactors[ddType][0] * ddFactor;
    gFactor = sHeartsDDPrimFactors[ddType][1] * ddFactor;
    bFactor = sHeartsDDPrimFactors[ddType][2] * ddFactor;

    sBeatingHeartsDDPrim[0] = (u8)(rFactor + HEARTS_DD_PRIM_R) & 0xFF;
    sBeatingHeartsDDPrim[1] = (u8)(gFactor + HEARTS_DD_PRIM_G) & 0xFF;
    sBeatingHeartsDDPrim[2] = (u8)(bFactor + HEARTS_DD_PRIM_B) & 0xFF;

    rFactor = sHeartsDDEnvFactors[ddType][0] * ddFactor;
    gFactor = sHeartsDDEnvFactors[ddType][1] * ddFactor;
    bFactor = sHeartsDDEnvFactors[ddType][2] * ddFactor;

    sBeatingHeartsDDEnv[0] = (u8)(rFactor + HEARTS_DD_ENV_R) & 0xFF;
    sBeatingHeartsDDEnv[1] = (u8)(gFactor + HEARTS_DD_ENV_G) & 0xFF;
    sBeatingHeartsDDEnv[2] = (u8)(bFactor + HEARTS_DD_ENV_B) & 0xFF;
}

static void* sHeartTextures[] = {
    gHeartFullTex,         gHeartQuarterTex,      gHeartQuarterTex,      gHeartQuarterTex,
    gHeartQuarterTex,      gHeartQuarterTex,      gHeartHalfTex,         gHeartHalfTex,
    gHeartHalfTex,         gHeartHalfTex,         gHeartHalfTex,         gHeartThreeQuarterTex,
    gHeartThreeQuarterTex, gHeartThreeQuarterTex, gHeartThreeQuarterTex, gHeartThreeQuarterTex,
};

static void* sHeartDDTextures[] = {
    gDefenseHeartFullTex,         gDefenseHeartQuarterTex,      gDefenseHeartQuarterTex,
    gDefenseHeartQuarterTex,      gDefenseHeartQuarterTex,      gDefenseHeartQuarterTex,
    gDefenseHeartHalfTex,         gDefenseHeartHalfTex,         gDefenseHeartHalfTex,
    gDefenseHeartHalfTex,         gDefenseHeartHalfTex,         gDefenseHeartThreeQuarterTex,
    gDefenseHeartThreeQuarterTex, gDefenseHeartThreeQuarterTex, gDefenseHeartThreeQuarterTex,
    gDefenseHeartThreeQuarterTex,
};

void HealthMeter_Draw(GlobalContext* globalCtx) {
    s32 pad[5];
    void* heartBgImg;
    u32 curColorSet;
    f32 offsetX;
    f32 offsetY;
    s32 heartIndex;
    f32 halfHeartLength;
    f32 heartCenterX;
    f32 heartCenterY;
    f32 heartTexCoordPerPixel;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    Vtx* beatingHeartVtx = interfaceCtx->beatingHeartVtx;
    s32 curHeartFraction = gSaveContext.health % 0x10;
    s16 totalHeartCount = gSaveContext.healthCapacity / 0x10;
    s16 fullHeartCount = gSaveContext.health / 0x10;
    s32 pad2;
    f32 beatingHeartPulsingSize = interfaceCtx->beatingHeartOscillator.toFloat() * 0.1f;
    s32 curCombineModeSet = 0;
    u8* curBgImgLoaded = NULL;
    s32 ddHeartCountMinusOne = gSaveContext.inventory.defenseHearts - 1;

    OPEN_DISPS(gfxCtx, "../z_lifemeter.c", 353);

    if (!(gSaveContext.health % 0x10)) {
        fullHeartCount--;
    }

    curColorSet = -1;
    offsetY = 0.0f;
    offsetX = GFX_ALIGN_LEFT(0);

    for (heartIndex = 0; heartIndex < totalHeartCount; heartIndex++) {
        if ((ddHeartCountMinusOne < 0) || (heartIndex > ddHeartCountMinusOne)) {
            if (heartIndex < fullHeartCount) {
                if (curColorSet != 0) {
                    curColorSet = 0;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[0], interfaceCtx->heartsPrimG[0],
                                    interfaceCtx->heartsPrimB[0], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[0], interfaceCtx->heartsEnvG[0],
                                   interfaceCtx->heartsEnvB[0], 255);
                }
            } else if (heartIndex == fullHeartCount) {
                if (curColorSet != 1) {
                    curColorSet = 1;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->beatingHeartPrim[0],
                                    interfaceCtx->beatingHeartPrim[1], interfaceCtx->beatingHeartPrim[2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->beatingHeartEnv[0], interfaceCtx->beatingHeartEnv[1],
                                   interfaceCtx->beatingHeartEnv[2], 255);
                }
            } else if (heartIndex > fullHeartCount) {
                if (curColorSet != 2) {
                    curColorSet = 2;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[0], interfaceCtx->heartsPrimG[0],
                                    interfaceCtx->heartsPrimB[0], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[0], interfaceCtx->heartsEnvG[0],
                                   interfaceCtx->heartsEnvB[0], 255);
                }
            } else {
                if (curColorSet != 3) {
                    curColorSet = 3;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[1], interfaceCtx->heartsPrimG[1],
                                    interfaceCtx->heartsPrimB[1], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[1], interfaceCtx->heartsEnvG[1],
                                   interfaceCtx->heartsEnvB[1], 255);
                }
            }

            if (heartIndex < fullHeartCount) {
                heartBgImg = gHeartFullTex;
            } else if (heartIndex == fullHeartCount) {
                heartBgImg = sHeartTextures[curHeartFraction];
            } else {
                heartBgImg = gHeartEmptyTex;
            }
        } else {
            if (heartIndex < fullHeartCount) {
                if (curColorSet != 4) {
                    curColorSet = 4;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[0][0], sHeartsDDPrim[0][1], sHeartsDDPrim[0][2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[0][0], sHeartsDDEnv[0][1], sHeartsDDEnv[0][2], 255);
                }
            } else if (heartIndex == fullHeartCount) {
                if (curColorSet != 5) {
                    curColorSet = 5;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sBeatingHeartsDDPrim[0], sBeatingHeartsDDPrim[1],
                                    sBeatingHeartsDDPrim[2], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sBeatingHeartsDDEnv[0], sBeatingHeartsDDEnv[1],
                                   sBeatingHeartsDDEnv[2], 255);
                }
            } else if (heartIndex > fullHeartCount) {
                if (curColorSet != 6) {
                    curColorSet = 6;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[0][0], sHeartsDDPrim[0][1], sHeartsDDPrim[0][2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[0][0], sHeartsDDEnv[0][1], sHeartsDDEnv[0][2], 255);
                }
            } else {
                if (curColorSet != 7) {
                    curColorSet = 7;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[1][0], sHeartsDDPrim[1][1], sHeartsDDPrim[1][2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[1][0], sHeartsDDEnv[1][1], sHeartsDDEnv[1][2], 255);
                }
            }

            if (heartIndex < fullHeartCount) {
                heartBgImg = gDefenseHeartFullTex;
            } else if (heartIndex == fullHeartCount) {
                heartBgImg = sHeartDDTextures[curHeartFraction];
            } else {
                heartBgImg = gDefenseHeartEmptyTex;
            }
        }

        if (curBgImgLoaded != heartBgImg) {
            curBgImgLoaded = (u8*)heartBgImg;
            gDPLoadTextureBlock(OVERLAY_DISP++, heartBgImg, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
        }

        if (heartIndex != fullHeartCount) {
            if ((ddHeartCountMinusOne < 0) || (heartIndex > ddHeartCountMinusOne)) {
                if (curCombineModeSet != 1) {
                    curCombineModeSet = 1;
                    func_80094520(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                }
            } else {
                if (curCombineModeSet != 3) {
                    curCombineModeSet = 3;
                    func_80094520(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                                      0, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                }
            }

            heartCenterY = 26.0f + offsetY;
            heartCenterX = 30.0f + offsetX;
            heartTexCoordPerPixel = 1.0f;
            heartTexCoordPerPixel /= 0.68f;
            heartTexCoordPerPixel *= 1 << 10;
            halfHeartLength = 8.0f;
            halfHeartLength *= 0.68f;
            gSPTextureRectangle(OVERLAY_DISP++, (s32)((heartCenterX - halfHeartLength) * 4), (s32)((heartCenterY - halfHeartLength) * 4),
                                (s32)((heartCenterX + halfHeartLength) * 4), (s32)((heartCenterY + halfHeartLength) * 4), G_TX_RENDERTILE, 0, 0,
                                (s32)heartTexCoordPerPixel, (s32)heartTexCoordPerPixel);
        } else {
            if ((ddHeartCountMinusOne < 0) || (heartIndex > ddHeartCountMinusOne)) {
                if (curCombineModeSet != 2) {
                    curCombineModeSet = 2;
                    func_80094A14(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                }
            } else {
                if (curCombineModeSet != 4) {
                    curCombineModeSet = 4;
                    func_80094A14(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                                      0, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                }
            }

            {
                //Calculate the matrix for the beating heart
                //The code below is an optimized way of calling Matrix_Translate() and Matrix_Scale()
                Mtx* matrix = (Mtx*)Graph_Alloc(gfxCtx, sizeof(Mtx));
                Matrix_ScaleTrans(matrix, 1.0f - (0.32f * beatingHeartPulsingSize), 1.0f - (0.32f * beatingHeartPulsingSize), 1.0f - (0.32f * beatingHeartPulsingSize),
                    -130.0f + offsetX, 94.5f - offsetY, 0.0f);
                gSPMatrix(OVERLAY_DISP++, matrix, G_MTX_MODELVIEW | G_MTX_LOAD);
                gSPVertex(OVERLAY_DISP++, beatingHeartVtx, 4, 0);
                gSP1Quadrangle(OVERLAY_DISP++, 0, 2, 3, 1, 0);
            }
        }

        offsetX += 10.0f;
        if (heartIndex == 9) {
            offsetY += 10.0f;
            offsetX = GFX_ALIGN_LEFT(0);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_lifemeter.c", 606);
}

void HealthMeter_UpdateBeatingHeart(GlobalContext* globalCtx) {
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    if (interfaceCtx->beatingHeartOscillatorDirection != 0) {
	    interfaceCtx->beatingHeartOscillator--;
        if (interfaceCtx->beatingHeartOscillator <= 0) {
            interfaceCtx->beatingHeartOscillator = 0;
            interfaceCtx->beatingHeartOscillatorDirection = 0;
            if (!Player_InCsMode(globalCtx) && (globalCtx->pauseCtx.state == 0) &&
                (globalCtx->pauseCtx.debugState == 0) && HealthMeter_IsCritical() && !Gameplay_InCsMode(globalCtx)) {
                Common_PlaySfx(NA_SE_SY_HITPOINT_ALARM);
            }
        }
    } else {
	    interfaceCtx->beatingHeartOscillator++;
        if (interfaceCtx->beatingHeartOscillator >= 10.0f) {
            interfaceCtx->beatingHeartOscillator = 10.0f;
            interfaceCtx->beatingHeartOscillatorDirection = 1;
        }
    }
}

u32 HealthMeter_IsCritical(void) {
    s32 var;

    if (gSaveContext.healthCapacity <= 0x50) {
        var = 0x10;
    } else if (gSaveContext.healthCapacity <= 0xA0) {
        var = 0x18;
    } else if (gSaveContext.healthCapacity <= 0xF0) {
        var = 0x20;
    } else {
        var = 0x2C;
    }

    if ((var >= gSaveContext.health) && (gSaveContext.health > 0)) {
        return true;
    } else {
        return false;
    }
}

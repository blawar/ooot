#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DT_BUBBLE_Z_EFF_SS_DT_BUBBLE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_dt_bubble.c
 * Overlay: ovl_Effect_Ss_Dt_Bubble
 * Description: Bubbles (a random mix of translucent and opaque)
 */

#include "z_eff_ss_dt_bubble.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorB regs[2]
#define rPrimColorA regs[3]
#define rEnvColorR regs[4]
#define rEnvColorG regs[5]
#define rEnvColorB regs[6]
#define rEnvColorA regs[7]
#define rRandXZ regs[8]
#define rScale regs[9]
#define rLifespan regs[10]

u32 EffectSsDtBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDtBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDtBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

static Color_RGBA8 sPrimColors[] = { { 255, 255, 100, 255 }, { 150, 255, 255, 255 }, { 100, 255, 255, 255 } };
static Color_RGBA8 sEnvColors[] = { { 170, 0, 0, 255 }, { 0, 100, 0, 255 }, { 0, 0, 255, 255 } };

EffectSsInit Effect_Ss_Dt_Bubble_InitVars = {
    EFFECT_SS_DT_BUBBLE,
    EffectSsDtBubble_Init,
};

u32 EffectSsDtBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsDtBubbleInitParams* initParams = (EffectSsDtBubbleInitParams*)initParamsx;

    //! @bug Rand_ZeroOne in the macro means a random number is generated for both parts of the macro.
    // In the base game pthis works out because both addresses are segment 4, but it may break if
    // the addresses were changed to refer to different segments
    pthis->gfx = SEGMENTED_TO_VIRTUAL(Rand_ZeroOne() < 0.5f ? gEffBubble1Tex : gEffBubble2Tex);
    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = initParams->life;

    if (!initParams->customColor) {
        pthis->rPrimColorR = sPrimColors[initParams->colorProfile].r;
        pthis->rPrimColorG = sPrimColors[initParams->colorProfile].g;
        pthis->rPrimColorB = sPrimColors[initParams->colorProfile].b;
        pthis->rPrimColorA = sPrimColors[initParams->colorProfile].a;
        pthis->rEnvColorR = sEnvColors[initParams->colorProfile].r;
        pthis->rEnvColorG = sEnvColors[initParams->colorProfile].g;
        pthis->rEnvColorB = sEnvColors[initParams->colorProfile].b;
        pthis->rEnvColorA = sEnvColors[initParams->colorProfile].a;
    } else {
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorB = initParams->primColor.b;
        pthis->rPrimColorA = initParams->primColor.a;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorB = initParams->envColor.b;
        pthis->rEnvColorA = initParams->envColor.a;
    }

    pthis->rRandXZ = initParams->randXZ;
    pthis->rScale = initParams->scale;
    pthis->rLifespan = initParams->life;
    pthis->draw = EffectSsDtBubble_Draw;
    pthis->update = EffectSsDtBubble_Update;

    return 1;
}

void EffectSsDtBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_dt_bubble.c", 201);

    scale = pthis->rScale * 0.004f;
    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_dt_bubble.c", 213),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093C14(gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                    (pthis->rPrimColorA * pthis->life) / pthis->rLifespan);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB,
                   (pthis->rEnvColorA * pthis->life) / pthis->rLifespan);
    gSPSegment(POLY_XLU_DISP++, 0x08, pthis->gfx);
    gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gEffBubbleDL));

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_dt_bubble.c", 236);
}

void EffectSsDtBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    f32 rand;

    if (pthis->rRandXZ == 1) {
        rand = Rand_ZeroOne();
        pthis->pos.x += (rand * 2.0f) - 1.0f;

        rand = Rand_ZeroOne();
        pthis->pos.z += (rand * 2.0f) - 1.0f;
    }
}

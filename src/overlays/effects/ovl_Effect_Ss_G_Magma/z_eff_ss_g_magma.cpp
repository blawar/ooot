#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_MAGMA_Z_EFF_SS_G_MAGMA_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_magma.c
 * Overlay: ovl_Effect_Ss_G_Magma
 * Description: Magma Bubbles
 */

#include "z_eff_ss_g_magma.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/z_effect_soft_sprite_old_init.h"

u32 EffectSsGMagma_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsGMagma_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGMagma_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_G_Magma_InitVars = {
    EFFECT_SS_G_MAGMA,
    EffectSsGMagma_Init,
};

u32 EffectSsGMagma_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsGMagmaInitParams* initParams = (EffectSsGMagmaInitParams*)initParamsx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    pthis->velocity = pthis->accel = zeroVec;
    pthis->pos = initParams->pos;
    pthis->draw = EffectSsGMagma_Draw;
    pthis->update = EffectSsGMagma_Update;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffMagmaBubbleDL);
    pthis->life = 16;
    pthis->rgScale = (s16)(Rand_ZeroOne() * 100.0f) + 200;
    pthis->rgTexIdx = 0;
    pthis->rgTexIdxStep = 50;
    pthis->rgPrimColorR = 255;
    pthis->rgPrimColorG = 255;
    pthis->rgPrimColorB = 0;
    pthis->rgPrimColorA = 255;
    pthis->rgEnvColorR = 255;
    pthis->rgEnvColorG = 0;
    pthis->rgEnvColorB = 0;
    pthis->rgEnvColorA = 0;

    return 1;
}

static void* sTextures[] = {
    gEffMagmaBubble1Tex, gEffMagmaBubble2Tex, gEffMagmaBubble3Tex, gEffMagmaBubble4Tex,
    gEffMagmaBubble5Tex, gEffMagmaBubble6Tex, gEffMagmaBubble7Tex, gEffMagmaBubble8Tex,
};

void EffectSsGMagma_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s16 texIdx = pthis->rgTexIdx / 100;

    if (texIdx > 7) {
        texIdx = 7;
    }

    EffectSs_DrawGEffect(globalCtx, pthis, sTextures[texIdx]);
}

void EffectSsGMagma_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rgTexIdx += pthis->rgTexIdxStep;
}

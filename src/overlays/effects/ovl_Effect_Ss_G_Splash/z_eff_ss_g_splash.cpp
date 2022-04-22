#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_SPLASH_Z_EFF_SS_G_SPLASH_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_splash.c
 * Overlay: ovl_Effect_Ss_G_Splash
 * Description: Splash
 */

#include "z_eff_ss_g_splash.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/z_effect_soft_sprite_old_init.h"

//! @bug the reuse of regs[11] means that EffectSs_DrawGEffect will treat the type as an object bank index
// pthis ends up having no effect because the texture provided does not use segment 6
#define rType regs[11]

u32 EffectSsGSplash_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParams);
void EffectSsGSplash_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGSplash_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_G_Splash_InitVars = {
    EFFECT_SS_G_SPLASH,
    EffectSsGSplash_Init,
};

u32 EffectSsGSplash_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsGSplashInitParams* initParams = (EffectSsGSplashInitParams*)initParamsx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    pthis->velocity = pthis->accel = zeroVec;
    pthis->pos = initParams->pos;
    pthis->draw = EffectSsGSplash_Draw;
    pthis->update = EffectSsGSplash_Update;

    if (initParams->scale == 0) {
        initParams->scale = 600;
    }

    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffWaterSplashDL);
    pthis->life = 8;
    pthis->rgScale = initParams->scale;
    pthis->rgTexIdx = 0;
    pthis->rgTexIdxStep = 100;

    if (initParams->customColor) {
        pthis->rgPrimColorR = initParams->primColor.r;
        pthis->rgPrimColorG = initParams->primColor.g;
        pthis->rgPrimColorB = initParams->primColor.b;
        pthis->rgPrimColorA = initParams->primColor.a;
        pthis->rgEnvColorR = initParams->envColor.r;
        pthis->rgEnvColorG = initParams->envColor.g;
        pthis->rgEnvColorB = initParams->envColor.b;
        pthis->rgEnvColorA = initParams->envColor.a;
        pthis->rType = initParams->type;
    } else {
        switch (initParams->type) {
            case 0:
                pthis->rgPrimColorR = 255;
                pthis->rgPrimColorG = 255;
                pthis->rgPrimColorB = 255;
                pthis->rgPrimColorA = 200;
                pthis->rgEnvColorR = 255;
                pthis->rgEnvColorG = 255;
                pthis->rgEnvColorB = 255;
                pthis->rgEnvColorA = 200;
                pthis->rType = 0;
                break;
            case 1:
                pthis->rgPrimColorR = 255;
                pthis->rgPrimColorG = 255;
                pthis->rgPrimColorB = 255;
                pthis->rgPrimColorA = 255;
                pthis->rgEnvColorR = 255;
                pthis->rgEnvColorG = 255;
                pthis->rgEnvColorB = 255;
                pthis->rgEnvColorA = 255;
                pthis->rType = 1;
                break;
            case 2:
                pthis->rgPrimColorR = 255;
                pthis->rgPrimColorG = 255;
                pthis->rgPrimColorB = 255;
                pthis->rgPrimColorA = 200;
                pthis->rgEnvColorR = 255;
                pthis->rgEnvColorG = 255;
                pthis->rgEnvColorB = 255;
                pthis->rgEnvColorA = 200;
                pthis->rType = 2;
                break;
        }
    }
    return 1;
}

void EffectSsGSplash_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* waterSplashTextures[] = {
        gEffWaterSplash1Tex, gEffWaterSplash2Tex, gEffWaterSplash3Tex, gEffWaterSplash4Tex,
        gEffWaterSplash5Tex, gEffWaterSplash6Tex, gEffWaterSplash7Tex, gEffWaterSplash8Tex,
    };
    s16 texIdx;

    switch (pthis->rType) {
        case 0:
            texIdx = pthis->rgTexIdx / 100;
            if (texIdx > 7) {
                texIdx = 7;
            }
            EffectSs_DrawGEffect(globalCtx, pthis, waterSplashTextures[texIdx]);
            break;

        case 1:
            texIdx = pthis->rgTexIdx / 100;
            if (texIdx > 7) {
                texIdx = 7;
            }
            EffectSs_DrawGEffect(globalCtx, pthis, waterSplashTextures[texIdx]);
            break;

        case 2:
            texIdx = pthis->rgTexIdx / 100;
            if (texIdx > 7) {
                texIdx = 7;
            }
            EffectSs_DrawGEffect(globalCtx, pthis, waterSplashTextures[texIdx]);
            break;

        default:
            break;
    }
}

void EffectSsGSplash_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    Vec3f newSplashPos;

    if ((pthis->rType == 1) && (pthis->life == 5)) {
        newSplashPos = pthis->pos;
        newSplashPos.y += ((pthis->rgScale * 20) * 0.002f);
        EffectSsGSplash_Spawn(globalCtx, &newSplashPos, 0, 0, 2, pthis->rgScale / 2);
    }

    pthis->rgTexIdx += pthis->rgTexIdxStep;
}

#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_FIRE_Z_EFF_SS_G_FIRE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_fire.c
 * Overlay: ovl_Effect_Ss_G_Fire
 * Description: Flame Footprints
 */

#include "z_eff_ss_g_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/z_effect_soft_sprite_old_init.h"

u32 EffectSsGFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsGFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_G_Fire_InitVars = {
    EFFECT_SS_G_FIRE,
    EffectSsGFire_Init,
};

u32 EffectSsGFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsGFireInitParams* initParams = (EffectSsGFireInitParams*)initParamsx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    pthis->velocity = pthis->accel = zeroVec;
    pthis->pos = initParams->pos;
    pthis->draw = EffectSsGFire_Draw;
    pthis->update = EffectSsGFire_Update;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffFireFootprintDL);
    pthis->life = 8;
    pthis->flags = 0;
    pthis->rgScale = 200;
    pthis->rgTexIdx = 0;
    pthis->rgTexIdxStep = 50;
    pthis->rgPrimColorR = 255;
    pthis->rgPrimColorG = 220;
    pthis->rgPrimColorB = 80;
    pthis->rgPrimColorA = 255;
    pthis->rgEnvColorR = 130;
    pthis->rgEnvColorG = 30;
    pthis->rgEnvColorB = 0;
    pthis->rgEnvColorA = 0;

    return 1;
}

void EffectSsGFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    void* fireFootprintTextures[] = {
        gEffFireFootprint1Tex, gEffFireFootprint2Tex, gEffFireFootprint3Tex, gEffFireFootprint4Tex,
        gEffFireFootprint5Tex, gEffFireFootprint6Tex, gEffFireFootprint7Tex, gEffFireFootprint8Tex,
    };
    s16 texIdx = (pthis->rgTexIdx / 100) % 7;

    EffectSs_DrawGEffect(globalCtx, pthis, fireFootprintTextures[texIdx]);
}

void EffectSsGFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rgTexIdx += pthis->rgTexIdxStep;
}

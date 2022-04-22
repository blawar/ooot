#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_RIPPLE_Z_EFF_SS_G_RIPPLE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_ripple.c
 * Overlay: ovl_Effect_Ss_G_Ripple
 * Description: Water Ripple
 */

#include "z_eff_ss_g_ripple.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rWaterBoxNum regs[0]
#define rRadius regs[1]
#define rRadiusMax regs[2]
#define rPrimColorR regs[3]
#define rPrimColorG regs[4]
#define rPrimColorB regs[5]
#define rPrimColorA regs[6]
#define rEnvColorR regs[7]
#define rEnvColorG regs[8]
#define rEnvColorB regs[9]
#define rEnvColorA regs[10]
#define rLifespan regs[11]

u32 EffectSsGRipple_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsGRipple_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGRipple_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_G_Ripple_InitVars = {
    EFFECT_SS_G_RIPPLE,
    EffectSsGRipple_Init,
};

u32 EffectSsGRipple_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    s32 pad;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    WaterBox* waterBox;
    EffectSsGRippleInitParams* initParams = (EffectSsGRippleInitParams*)initParamsx;

    waterBox = NULL;
    pthis->velocity = pthis->accel = zeroVec;
    pthis->pos = initParams->pos;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffWaterRippleDL);
    pthis->life = initParams->life + 20;
    pthis->flags = 0;
    pthis->draw = EffectSsGRipple_Draw;
    pthis->update = EffectSsGRipple_Update;
    pthis->rRadius = initParams->radius;
    pthis->rRadiusMax = initParams->radiusMax;
    pthis->rLifespan = initParams->life;
    pthis->rPrimColorR = 255;
    pthis->rPrimColorG = 255;
    pthis->rPrimColorB = 255;
    pthis->rPrimColorA = 255;
    pthis->rEnvColorR = 255;
    pthis->rEnvColorG = 255;
    pthis->rEnvColorB = 255;
    pthis->rEnvColorA = 255;
    pthis->rWaterBoxNum = WaterBox_GetSurface2(globalCtx, &globalCtx->colCtx, &initParams->pos, 3.0f, &waterBox);

    return 1;
}

void EffectSsGRipple_DrawRipple(GlobalContext* globalCtx, EffectSs* pthis, void* segment) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 radius;
    s32 pad;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    Mtx* mtx;
    f32 yPos;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_g_ripple.c", 199);

    if (globalCtx) {}

    radius = pthis->rRadius * 0.0025f;

    if ((pthis->rWaterBoxNum != -1) && (pthis->rWaterBoxNum < globalCtx->colCtx.colHeader->numWaterBoxes)) {
        yPos = (pthis->rWaterBoxNum + globalCtx->colCtx.colHeader->waterBoxes)->ySurface;
    } else {
        yPos = pthis->pos.y;
    }

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, yPos, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, radius, radius, radius);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80094BC4(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                        pthis->rPrimColorA);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
        gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
        gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_g_ripple.c", 247);
}

void EffectSsGRipple_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->rLifespan == 0) {
        EffectSsGRipple_DrawRipple(globalCtx, pthis, gEffWaterRippleTex);
    }
}

void EffectSsGRipple_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    f32 radius;
    f32 primAlpha;
    f32 envAlpha;

    if (DECR(pthis->rLifespan) == 0) {
        radius = pthis->rRadius;
        Math_SmoothStepToF(&radius, pthis->rRadiusMax, 0.2f, 30.0f, 1.0f);
        pthis->rRadius = radius;

        primAlpha = pthis->rPrimColorA;
        envAlpha = pthis->rEnvColorA;

        Math_SmoothStepToF(&primAlpha, 0.0f, 0.2f, 15.0f, 7.0f);
        Math_SmoothStepToF(&envAlpha, 0.0f, 0.2f, 15.0f, 7.0f);

        pthis->rPrimColorA = primAlpha;
        pthis->rEnvColorA = envAlpha;
    }
}

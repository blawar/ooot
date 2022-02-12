#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DEAD_DD_Z_EFF_SS_DEAD_DD_C
#include "actor_common.h"
#include "z_kankyo.h"
/*
 * File: z_eff_ss_dead_dd.c
 * Overlay: ovl_Effect_Ss_Dead_Dd
 * Description:
 */

#include "z_eff_ss_dead_dd.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_object_kankyo.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rScale regs[0]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rAlpha regs[5]
#define rEnvColorR regs[6]
#define rEnvColorG regs[7]
#define rEnvColorB regs[8]
#define rScaleStep regs[9]
#define rAlphaStep regs[10]
#define rAlphaMode regs[11] // if mode is 0 alpha decreases over time, otherwise it increases

u32 EffectSsDeadDd_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDeadDd_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDeadDd_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Dead_Dd_InitVars = {
    EFFECT_SS_DEAD_DD,
    EffectSsDeadDd_Init,
};

u32 EffectSsDeadDd_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    s32 i;
    EffectSsDeadDdInitParams* initParams = (EffectSsDeadDdInitParams*)initParamsx;

    if (initParams->type == 0) {
        pthis->pos = initParams->pos;
        pthis->velocity = initParams->velocity;
        pthis->accel = initParams->accel;
        pthis->life = initParams->life;
        pthis->rScaleStep = initParams->scaleStep;
        pthis->rAlphaMode = initParams->alphaStep;

        if (initParams->alphaStep != 0) {
            pthis->rAlphaStep = initParams->alphaStep;
        } else {
            pthis->rAlphaStep = initParams->alpha / initParams->life;
        }

        pthis->draw = EffectSsDeadDd_Draw;
        pthis->update = EffectSsDeadDd_Update;
        pthis->rScale = initParams->scale;
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorB = initParams->primColor.b;
        pthis->rAlpha = initParams->alpha;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorB = initParams->envColor.b;

    } else if (initParams->type == 1) {
        pthis->life = initParams->life;
        pthis->rScaleStep = initParams->scaleStep;
        pthis->rAlphaMode = 0;
        pthis->rAlphaStep = 155 / initParams->life;
        pthis->rScale = initParams->scale;
        pthis->rPrimColorR = 255;
        pthis->rPrimColorG = 255;
        pthis->rPrimColorB = 155;
        pthis->rAlpha = 155;
        pthis->rEnvColorR = 250;
        pthis->rEnvColorG = 180;
        pthis->rEnvColorB = 0;
        pthis->draw = EffectSsDeadDd_Draw;
        pthis->update = EffectSsDeadDd_Update;

        for (i = initParams->randIter; i > 0; i--) {
            pthis->pos.x = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.x;
            pthis->pos.y = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.y;
            pthis->pos.z = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.z;
            pthis->accel.x = pthis->velocity.x = (Rand_ZeroOne() - 0.5f) * 2.0f;
            pthis->accel.y = pthis->velocity.y = (Rand_ZeroOne() - 0.5f) * 2.0f;
            pthis->accel.z = pthis->velocity.z = (Rand_ZeroOne() - 0.5f) * 2.0f;
        }
    } else {
        osSyncPrintf("Effect_SS_Dd_disp_mode():mode_swが変です。\n");
        return 0;
    }

    return 1;
}

void EffectSsDeadDd_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    Mtx* mtx;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_dead_dd.c", 214);

    scale = pthis->rScale * 0.01f;
    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, scale);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        func_80094BC4(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, pthis->rAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rAlpha);
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(POLY_XLU_DISP++, &D_01000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetCombineLERP(POLY_XLU_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                          PRIMITIVE, 0);
        gSPDisplayList(POLY_XLU_DISP++, gLensFlareCircleDL);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_dead_dd.c", 259);
}

void EffectSsDeadDd_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {

    pthis->rScale += pthis->rScaleStep;

    if (pthis->rScale < 0) {
        pthis->rScale = 0;
    }

    if (pthis->rAlphaMode != 0) {
        pthis->rAlpha += pthis->rAlphaStep;
        if (pthis->rAlpha > 255) {
            pthis->rAlpha = 255;
        }
    } else {
        if (pthis->rAlpha < pthis->rAlphaStep) {
            pthis->rAlpha = 0;
        } else {
            pthis->rAlpha -= pthis->rAlphaStep;
        }
    }
}

#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_KIRAKIRA_Z_EFF_SS_KIRAKIRA_C
#include "actor_common.h"
/*
 * File: z_eff_ss_kirakira.c
 * Overlay: ovl_Effect_Ss_KiraKira
 * Description: Sparkles
 */

#include "z_eff_ss_kirakira.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rRotSpeed regs[0]
#define rYaw regs[1]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rPrimColorA regs[5]
#define rEnvColorR regs[6]
#define rEnvColorG regs[7]
#define rEnvColorB regs[8]
#define rEnvColorA regs[9]
#define rAlphaStep regs[10]
#define rScale regs[11]
#define rLifespan regs[12]

u32 EffectSsKiraKira_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsKiraKira_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void func_809AABF0(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void func_809AACAC(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void func_809AAD6C(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_KiraKira_InitVars = {
    EFFECT_SS_KIRAKIRA,
    EffectSsKiraKira_Init,
};

u32 EffectSsKiraKira_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsKiraKiraInitParams* initParams = (EffectSsKiraKiraInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;

    if ((pthis->life = initParams->life) < 0) {
        pthis->life = -pthis->life;
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffSparklesDL);
        pthis->update = func_809AAD6C;
        pthis->rEnvColorA = initParams->scale;
        pthis->rScale = 0;
    } else {
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffSparklesDL);

        if (initParams->updateMode == 0) {
            pthis->update = func_809AABF0;
        } else {
            pthis->update = func_809AACAC;
        }

        pthis->rEnvColorA = initParams->envColor.a;
        pthis->rScale = initParams->scale;
    }

    pthis->draw = EffectSsKiraKira_Draw;
    pthis->rRotSpeed = initParams->rotSpeed;
    pthis->rYaw = initParams->yaw;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;
    pthis->rAlphaStep = initParams->alphaStep;
    pthis->rLifespan = initParams->life;

    return 1;
}

void EffectSsKiraKira_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx;
    f32 scale;
    s32 pad;
    MtxF mfTrans;
    MtxF mfRotY;
    MtxF mfScale;
    MtxF mfTrans11DA0;
    MtxF mfTrans11DA0RotY;
    MtxF mfResult;
    Mtx* mtx;

    scale = pthis->rScale / 10000.0f;
    gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_kirakira.c", 257);

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetRotateZYX(&mfRotY, 0, 0, pthis->rYaw);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfRotY, &mfTrans11DA0RotY);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0RotY, &mfScale, &mfResult);
    gSPMatrix(POLY_XLU_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80093C14(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                        (((s8)((55.0f / pthis->rLifespan) * pthis->life) + 200)));
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_kirakira.c", 301);
}

void func_809AABF0(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
    pthis->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;
    pthis->rEnvColorA += pthis->rAlphaStep;

    if (pthis->rEnvColorA < 0) {
        pthis->rEnvColorA = 0;
        pthis->rAlphaStep = -pthis->rAlphaStep;
    } else if (pthis->rEnvColorA > 255) {
        pthis->rEnvColorA = 255;
        pthis->rAlphaStep = -pthis->rAlphaStep;
    }

    pthis->rYaw += pthis->rRotSpeed;
}

void func_809AACAC(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->velocity.x *= 0.95f;
    pthis->velocity.z *= 0.95f;
    pthis->accel.x = Rand_CenteredFloat(0.2f);
    pthis->accel.z = Rand_CenteredFloat(0.2f);
    pthis->rEnvColorA += pthis->rAlphaStep;

    if (pthis->rEnvColorA < 0) {
        pthis->rEnvColorA = 0;
        pthis->rAlphaStep = -pthis->rAlphaStep;
    } else if (pthis->rEnvColorA > 255) {
        pthis->rEnvColorA = 255;
        pthis->rAlphaStep = -pthis->rAlphaStep;
    }

    pthis->rYaw += pthis->rRotSpeed;
}

void func_809AAD6C(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rScale = pthis->rEnvColorA * Math_SinS((32768.0f / pthis->rLifespan) * pthis->life);
}

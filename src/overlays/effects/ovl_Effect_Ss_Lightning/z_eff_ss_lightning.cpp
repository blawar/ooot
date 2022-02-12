#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_LIGHTNING_Z_EFF_SS_LIGHTNING_C
#include "actor_common.h"
/*
 * File: z_eff_ss_lightning.c
 * Overlay: ovl_Effect_Ss_Lightning
 * Description: Lightning
 */

#include "z_eff_ss_lightning.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_camera.h"
#include "def/z_effect_soft_sprite.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorB regs[2]
#define rPrimColorA regs[3]
#define rEnvColorR regs[4]
#define rEnvColorG regs[5]
#define rEnvColorB regs[6]
#define rEnvColorA regs[7]
#define rNumBolts regs[8]
#define rScale regs[9]
#define rYaw regs[10]
#define rLifespan regs[11]

u32 EffectSsLightning_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsLightning_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsLightning_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Lightning_InitVars = {
    EFFECT_SS_LIGHTNING,
    EffectSsLightning_Init,
};

u32 EffectSsLightning_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsLightningInitParams* initParams = (EffectSsLightningInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffLightningDL);
    pthis->life = initParams->life;
    pthis->draw = EffectSsLightning_Draw;
    pthis->update = EffectSsLightning_Update;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;
    pthis->rEnvColorA = initParams->envColor.a;
    pthis->rNumBolts = initParams->numBolts;
    pthis->rScale = initParams->scale;
    pthis->rYaw = initParams->yaw;
    pthis->rLifespan = initParams->life;

    return 1;
}

void EffectSsLightning_NewLightning(GlobalContext* globalCtx, Vec3f* pos, s16 yaw, EffectSs* pthis) {
    EffectSs newLightning;

    EffectSs_Delete(&newLightning);
    newLightning = *pthis;
    newLightning.pos = *pos;
    newLightning.rNumBolts--;
    newLightning.rYaw = yaw;
    newLightning.life = newLightning.rLifespan;

    EffectSs_Insert(globalCtx, &newLightning);
}

void EffectSsLightning_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* lightningTextures[] = {
        gEffLightning1Tex, gEffLightning2Tex, gEffLightning3Tex, gEffLightning4Tex,
        gEffLightning5Tex, gEffLightning6Tex, gEffLightning7Tex, gEffLightning8Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfResult;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfRotate;
    MtxF mfTrans11DA0;
    MtxF mfTrans11DA0Rotate;
    Mtx* mtx;
    f32 yScale;
    s16 texIdx;
    f32 xzScale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_lightning.c", 233);

    yScale = pthis->rScale * 0.01f;
    texIdx = pthis->rLifespan - pthis->life;

    if (texIdx > 7) {
        texIdx = 7;
    }

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    xzScale = yScale * 0.6f;
    SkinMatrix_SetScale(&mfScale, xzScale, yScale, xzScale);
    SkinMatrix_SetRotateZYX(&mfRotate, pthis->vec.x, pthis->vec.y, pthis->rYaw);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfRotate, &mfTrans11DA0Rotate);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0Rotate, &mfScale, &mfResult);

    gSPMatrix(POLY_XLU_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80094C50(gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(lightningTextures[texIdx]));
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                        pthis->rPrimColorA);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_lightning.c", 281);
}

void EffectSsLightning_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad;
    Vec3f pos;
    s16 yaw;
    f32 scale;

    if ((pthis->rNumBolts != 0) && ((pthis->life + 1) == pthis->rLifespan)) {

        yaw = pthis->rYaw + (((Rand_ZeroOne() < 0.5f) ? -1 : 1) * ((s16)((Rand_ZeroOne() * 3640.0f)) + 0xE38));

        scale = (pthis->rScale * 0.01f) * 80.0f;
        pos.y = pthis->pos.y + (Math_SinS(pthis->rYaw - 0x4000) * scale);

        scale = Math_CosS(pthis->rYaw - 0x4000) * scale;
        pos.x = pthis->pos.x - (Math_CosS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(globalCtx))) * scale);
        pos.z = pthis->pos.z + (Math_SinS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(globalCtx))) * scale);

        EffectSsLightning_NewLightning(globalCtx, &pos, yaw, pthis);

        if (Rand_ZeroOne() < 0.1f) {
            EffectSsLightning_NewLightning(globalCtx, &pos, (pthis->rYaw * 2) - yaw, pthis);
        }
    }
}

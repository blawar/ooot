#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DUST_Z_EFF_SS_DUST_C
#include "actor_common.h"
/*
 * File: z_eff_ss_dust.c
 * Overlay: ovl_Effect_Ss_Dust
 * Description: Dust Particle Effect
 */

#include "z_eff_ss_dust.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
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
#define rTexIdx regs[8] // pthis reg is also used to set specific colors in the fire update function
#define rScale regs[9]
#define rScaleStep regs[10]
#define rDrawFlags regs[11]
#define rLifespan regs[12]

u32 EffectSsDust_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDust_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBlast_UpdateFire(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDust_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Dust_InitVars = {
    EFFECT_SS_DUST,
    EffectSsDust_Init,
};

static EffectSsUpdateFunc sUpdateFuncs[] = {
    EffectSsDust_Update,
    EffectSsBlast_UpdateFire,
};

u32 EffectSsDust_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    s32 randColorOffset;
    EffectSsDustInitParams* initParams = (EffectSsDustInitParams*)initParamsx;

    Math_Vec3f_Copy(&pthis->pos, &initParams->pos);
    Math_Vec3f_Copy(&pthis->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&pthis->accel, &initParams->accel);
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffDustDL);
    pthis->life = initParams->life;
    pthis->update = sUpdateFuncs[initParams->updateMode];
    pthis->draw = EffectSsDust_Draw;

    if (initParams->drawFlags & 4) {
        randColorOffset = Rand_ZeroOne() * 20.0f - 10.0f;
        pthis->rPrimColorR = initParams->primColor.r + randColorOffset;
        pthis->rPrimColorG = initParams->primColor.g + randColorOffset;
        pthis->rPrimColorB = initParams->primColor.b + randColorOffset;
        pthis->rEnvColorR = initParams->envColor.r + randColorOffset;
        pthis->rEnvColorG = initParams->envColor.g + randColorOffset;
        pthis->rEnvColorB = initParams->envColor.b + randColorOffset;
    } else {
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorB = initParams->primColor.b;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorB = initParams->envColor.b;
    }

    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorA = initParams->envColor.a;
    pthis->rTexIdx = 0;
    pthis->rScale = initParams->scale;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->rLifespan = initParams->life;
    pthis->rDrawFlags = initParams->drawFlags;

    return 1;
}

void EffectSsDust_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* dustTextures[] = {
        gDust1Tex, gDust2Tex, gDust3Tex, gDust4Tex, gDust5Tex, gDust6Tex, gDust7Tex, gDust8Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    s32 pad;
    Mtx* mtx;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_dust.c", 321);

    scale = pthis->rScale * 0.0025f;
    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);
    gSPMatrix(POLY_XLU_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(dustTextures[pthis->rTexIdx]));
        POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
        gDPPipeSync(POLY_XLU_DISP++);

        if (pthis->rDrawFlags & 1) {
            gDPSetCombineLERP(POLY_XLU_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                              COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
            gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_ZB_CLD_SURF2);
            gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
        } else if (pthis->rDrawFlags & 2) {
            gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
            gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
        } else {
            gSPClearGeometryMode(POLY_XLU_DISP++, G_LIGHTING);
        }

        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_dust.c", 389);
}

void EffectSsDust_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
    pthis->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;

    if ((pthis->life <= pthis->rLifespan) && (pthis->life >= (pthis->rLifespan - 7))) {
        if (pthis->rLifespan >= 5) {
            pthis->rTexIdx = pthis->rLifespan - pthis->life;
        } else {
            pthis->rTexIdx = ((pthis->rLifespan - pthis->life) * (8 / pthis->rLifespan));
        }
    } else {
        pthis->rTexIdx = 7;
    }

    pthis->rScale += pthis->rScaleStep;
}

// pthis update mode is unused in the original game
void EffectSsBlast_UpdateFire(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
    pthis->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;

    switch (pthis->rTexIdx) {
        case 0:
            pthis->rPrimColorR = 255;
            pthis->rPrimColorG = 150;
            pthis->rPrimColorB = 0;
            pthis->rEnvColorR = 150;
            pthis->rEnvColorG = 50;
            pthis->rEnvColorB = 0;
            break;
        case 1:
            pthis->rPrimColorR = 200;
            pthis->rPrimColorG = 50;
            pthis->rPrimColorB = 0;
            pthis->rEnvColorR = 100;
            pthis->rEnvColorG = 0;
            pthis->rEnvColorB = 0;
            break;
        case 2:
            pthis->rPrimColorR = 50;
            pthis->rPrimColorG = 0;
            pthis->rPrimColorB = 0;
            pthis->rEnvColorR = 0;
            pthis->rEnvColorG = 0;
            pthis->rEnvColorB = 0;
            break;
        case 3:
            pthis->rPrimColorR = 50;
            pthis->rEnvColorR = pthis->rPrimColorG = pthis->rEnvColorG = pthis->rPrimColorB = pthis->rEnvColorB = 0;
            break;
    }

    if (pthis->rTexIdx < 7) {
        pthis->rTexIdx++;
    }

    pthis->rScale += pthis->rScaleStep;
}

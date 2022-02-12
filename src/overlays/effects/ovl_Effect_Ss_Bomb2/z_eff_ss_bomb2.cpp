#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_BOMB2_Z_EFF_SS_BOMB2_C
#include "actor_common.h"
/*
 * File: z_eff_ss_bomb2.c
 * Overlay: ovl_Effect_Ss_Bomb2
 * Description: Bomb Blast
 */

#include "z_eff_ss_bomb2.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_effect_soft_sprite.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rScale regs[0]
#define rTexIdx regs[1]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rPrimColorA regs[5]
#define rEnvColorR regs[6]
#define rEnvColorG regs[7]
#define rEnvColorB regs[8]
#define rScaleStep regs[9]
#define rDepth regs[10]

u32 EffectSsBomb2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsBomb2_DrawFade(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBomb2_DrawLayered(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBomb2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Bomb2_InitVars = {
    EFFECT_SS_BOMB2,
    EffectSsBomb2_Init,
};

static EffectSsDrawFunc sDrawFuncs[] = {
    EffectSsBomb2_DrawFade,
    EffectSsBomb2_DrawLayered,
};

u32 EffectSsBomb2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {

    EffectSsBomb2InitParams* initParams = (EffectSsBomb2InitParams*)initParamsx;

    Math_Vec3f_Copy(&pthis->pos, &initParams->pos);
    Math_Vec3f_Copy(&pthis->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&pthis->accel, &initParams->accel);
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffBombExplosion1DL);
    pthis->life = 24;
    pthis->update = EffectSsBomb2_Update;
    pthis->draw = sDrawFuncs[initParams->drawMode];
    pthis->rScale = initParams->scale;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->rPrimColorR = 255;
    pthis->rPrimColorG = 255;
    pthis->rPrimColorB = 255;
    pthis->rPrimColorA = 255;
    pthis->rEnvColorR = 0;
    pthis->rEnvColorG = 0;
    pthis->rEnvColorB = 200;

    return 1;
}

// unused in the original game. looks like EffectSsBomb but with color
void EffectSsBomb2_DrawFade(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* textures[] = {
        gEffBombExplosion1Tex, gEffBombExplosion2Tex, gEffBombExplosion3Tex, gEffBombExplosion4Tex,
        gEffBombExplosion5Tex, gEffBombExplosion6Tex, gEffBombExplosion7Tex, gEffBombExplosion8Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    Mtx* mtx;
    s32 pad;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_bomb2.c", 298);

    scale = pthis->rScale * 0.01f;
    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80094BC4(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                        pthis->rPrimColorA);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, 0);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(textures[pthis->rTexIdx]));
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    if (1) {}
    if (1) {}

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_bomb2.c", 345);
}

void EffectSsBomb2_DrawLayered(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* textures[] = {
        gEffBombExplosion1Tex, gEffBombExplosion2Tex, gEffBombExplosion3Tex, gEffBombExplosion4Tex,
        gEffBombExplosion5Tex, gEffBombExplosion6Tex, gEffBombExplosion7Tex, gEffBombExplosion8Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    MtxF mtx2F;
    Mtx* mtx2;
    Mtx* mtx;
    s32 pad[3];
    f32 scale;
    f32 depth;
    f32 layer2Scale = 0.925f;
    s32 i;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_bomb2.c", 386);

    depth = pthis->rDepth;
    scale = pthis->rScale * 0.01f;
    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        mtx2 = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

        if (mtx2 != NULL) {
            func_80094BC4(gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                            pthis->rPrimColorA);
            gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, 0);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(textures[pthis->rTexIdx]));
            gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion2DL);
            gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion3DL);

            Matrix_MtxToMtxF(mtx2, &mtx2F);
            Matrix_Put(&mtx2F);

            for (i = 1; i >= 0; i--) {
                Matrix_Translate(0.0f, 0.0f, depth, MTXMODE_APPLY);
                Matrix_RotateZ((pthis->life * 0.02f) + 180.0f, MTXMODE_APPLY);
                Matrix_Scale(layer2Scale, layer2Scale, layer2Scale, MTXMODE_APPLY);
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_ss_bomb2.c", 448),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, gEffBombExplosion3DL);
                layer2Scale -= 0.15f;
            }
        }
    }

    if (1) {}
    if (1) {}

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_bomb2.c", 456);
}

void EffectSsBomb2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 divisor;

    pthis->rTexIdx = (23 - pthis->life) / 3;
    pthis->rScale += pthis->rScaleStep;

    if (pthis->rScaleStep == 30) {
        pthis->rDepth += 4.0f;
    } else {
        pthis->rDepth += 2.0f;
    }

    if ((pthis->life < 23) && (pthis->life > 13)) {
        divisor = pthis->life - 13;
        pthis->rPrimColorR = func_80027DD4(pthis->rPrimColorR, 255, divisor);
        pthis->rPrimColorG = func_80027DD4(pthis->rPrimColorG, 255, divisor);
        pthis->rPrimColorB = func_80027DD4(pthis->rPrimColorB, 150, divisor);
        pthis->rPrimColorA = func_80027DD4(pthis->rPrimColorA, 255, divisor);
        pthis->rEnvColorR = func_80027DD4(pthis->rEnvColorR, 150, divisor);
        pthis->rEnvColorG = func_80027DD4(pthis->rEnvColorG, 0, divisor);
        pthis->rEnvColorB = func_80027DD4(pthis->rEnvColorB, 0, divisor);
    } else if ((pthis->life < 14) && (pthis->life > -1)) {
        divisor = pthis->life + 1;
        pthis->rPrimColorR = func_80027DD4(pthis->rPrimColorR, 50, divisor);
        pthis->rPrimColorG = func_80027DD4(pthis->rPrimColorG, 50, divisor);
        pthis->rPrimColorB = func_80027DD4(pthis->rPrimColorB, 50, divisor);
        pthis->rPrimColorA = func_80027DD4(pthis->rPrimColorA, 150, divisor);
        pthis->rEnvColorR = func_80027DD4(pthis->rEnvColorR, 10, divisor);
        pthis->rEnvColorG = func_80027DD4(pthis->rEnvColorG, 10, divisor);
        pthis->rEnvColorB = func_80027DD4(pthis->rEnvColorB, 10, divisor);
    }
}

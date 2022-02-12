#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_HITMARK_Z_EFF_SS_HITMARK_C
#include "actor_common.h"
/*
 * File: z_eff_ss_hitmark.c
 * Overlay: ovl_Effect_Ss_HitMark
 * Description: Hit Marks
 */

#include "z_eff_ss_hitmark.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_effect_soft_sprite.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rTexIdx regs[0]
#define rType regs[1]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rEnvColorR regs[5]
#define rEnvColorG regs[6]
#define rEnvColorB regs[7]
#define rScale regs[8]

u32 EffectSsHitMark_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsHitMark_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsHitMark_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

static Color_RGB8 sColors[] = {
    { 255, 255, 255 }, { 255, 255, 0 }, { 255, 255, 255 }, { 255, 0, 0 },   { 255, 200, 100 }, { 200, 150, 0 },
    { 150, 100, 0 },   { 100, 50, 0 },  { 255, 255, 255 }, { 255, 0, 0 },   { 255, 255, 0 },   { 255, 0, 0 },
    { 255, 255, 255 }, { 0, 255, 200 }, { 255, 255, 255 }, { 150, 0, 255 },
};

static void* sTextures[] = {
    gEffHitMark1Tex,  gEffHitMark2Tex,  gEffHitMark3Tex,  gEffHitMark4Tex,  gEffHitMark5Tex,  gEffHitMark6Tex,
    gEffHitMark7Tex,  gEffHitMark8Tex,  gEffHitMark9Tex,  gEffHitMark10Tex, gEffHitMark11Tex, gEffHitMark12Tex,
    gEffHitMark13Tex, gEffHitMark14Tex, gEffHitMark15Tex, gEffHitMark16Tex, gEffHitMark17Tex, gEffHitMark18Tex,
    gEffHitMark19Tex, gEffHitMark20Tex, gEffHitMark21Tex, gEffHitMark22Tex, gEffHitMark23Tex, gEffHitMark24Tex,
    gEffHitMark1Tex,  gEffHitMark2Tex,  gEffHitMark3Tex,  gEffHitMark4Tex,  gEffHitMark5Tex,  gEffHitMark6Tex,
    gEffHitMark7Tex,  gEffHitMark8Tex,
};

EffectSsInit Effect_Ss_HitMark_InitVars = {
    EFFECT_SS_HITMARK,
    EffectSsHitMark_Init,
};

u32 EffectSsHitMark_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    s32 colorIdx;
    EffectSsHitMarkInitParams* initParams = (EffectSsHitMarkInitParams*)initParamsx;
    pthis->pos = initParams->pos;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffHitMarkDL);

    if (initParams->type == EFFECT_HITMARK_DUST) {
        pthis->life = 16;
    } else {
        pthis->life = 8;
    }

    pthis->draw = EffectSsHitMark_Draw;
    pthis->update = EffectSsHitMark_Update;
    colorIdx = initParams->type * 4;
    pthis->rTexIdx = 0;
    pthis->rType = initParams->type;
    pthis->rPrimColorR = sColors[colorIdx].r;
    pthis->rPrimColorG = sColors[colorIdx].g;
    pthis->rPrimColorB = sColors[colorIdx].b;
    pthis->rEnvColorR = sColors[colorIdx + 1].r;
    pthis->rEnvColorG = sColors[colorIdx + 1].g;
    pthis->rEnvColorB = sColors[colorIdx + 1].b;
    pthis->rScale = initParams->scale;

    return 1;
}

void EffectSsHitMark_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    Mtx* mtx;
    f32 scale;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_hitmark.c", 297);

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    scale = pthis->rScale / 100.0f;
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);
    gSPMatrix(POLY_XLU_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTextures[(pthis->rType * 8) + (pthis->rTexIdx)]));
        func_80094C50(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, 0);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }
    CLOSE_DISPS(gfxCtx, "../z_eff_ss_hitmark.c", 341);
}

void EffectSsHitMark_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 colorIdx;

    if (pthis->rType == EFFECT_HITMARK_DUST) {
        pthis->rTexIdx = (15 - pthis->life) / 2;
    } else {
        pthis->rTexIdx = 7 - pthis->life;
    }

    if (pthis->rTexIdx != 0) {
        colorIdx = pthis->rType * 4 + 2;
        pthis->rPrimColorR = func_80027DD4(pthis->rPrimColorR, sColors[colorIdx].r, pthis->life + 1);
        pthis->rPrimColorG = func_80027DD4(pthis->rPrimColorG, sColors[colorIdx].g, pthis->life + 1);
        pthis->rPrimColorB = func_80027DD4(pthis->rPrimColorB, sColors[colorIdx].b, pthis->life + 1);
        pthis->rEnvColorR = func_80027DD4(pthis->rEnvColorR, sColors[colorIdx + 1].r, pthis->life + 1);
        pthis->rEnvColorG = func_80027DD4(pthis->rEnvColorG, sColors[colorIdx + 1].g, pthis->life + 1);
        pthis->rEnvColorB = func_80027DD4(pthis->rEnvColorB, sColors[colorIdx + 1].b, pthis->life + 1);
    }
}

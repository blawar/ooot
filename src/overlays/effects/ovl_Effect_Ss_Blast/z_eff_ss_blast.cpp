#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_BLAST_Z_EFF_SS_BLAST_C
#include "actor_common.h"
/*
 * File: z_eff_ss_blast.c
 * Overlay: ovl_Effect_Ss_Blast
 * Description: Shockwave Effect
 */

#include "z_eff_ss_blast.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorB regs[2]
#define rPrimColorA regs[3]
#define rEnvColorR regs[4]
#define rEnvColorG regs[5]
#define rEnvColorB regs[6]
#define rEnvColorA regs[7]
#define rAlphaTarget regs[8]
#define rScale regs[9]
#define rScaleStep regs[10]
#define rScaleStepDecay regs[11]

u32 EffectSsBlast_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsBlast_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBlast_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Blast_InitVars = {
    EFFECT_SS_BLAST,
    EffectSsBlast_Init,
};

u32 EffectSsBlast_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsBlastParams* initParams = (EffectSsBlastParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->pos.y += 5.0f;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffShockwaveDL);
    pthis->life = initParams->life;
    pthis->draw = EffectSsBlast_Draw;
    pthis->update = EffectSsBlast_Update;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;
    pthis->rEnvColorA = initParams->envColor.a;
    pthis->rAlphaTarget = initParams->primColor.a / initParams->life;
    pthis->rScale = initParams->scale;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->rScaleStepDecay = initParams->sclaeStepDecay;
    return 1;
}

void EffectSsBlast_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mf;
    s32 pad;
    f32 radius;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_blast.c", 170);

    radius = pthis->rScale * 0.0025f;

    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
    func_800BFCB8(globalCtx, &mf, &pthis->pos);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, pthis->rPrimColorA);
    Matrix_Put(&mf);
    Matrix_Scale(radius, radius, radius, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_blast.c", 199),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_blast.c", 204);
}

void EffectSsBlast_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    Math_StepToS((s16*)&pthis->rPrimColorA, 0, pthis->rAlphaTarget);
    pthis->rScale += pthis->rScaleStep;

    if (pthis->rScaleStep != 0) {
        pthis->rScaleStep -= pthis->rScaleStepDecay;
    }
}

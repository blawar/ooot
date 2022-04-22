#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_SIBUKI2_Z_EFF_SS_SIBUKI2_C
#include "actor_common.h"
/*
 * File: z_eff_ss_sibuki2.c
 * Overlay: ovl_Effect_Ss_Sibuki2
 * Description: Unfinished and unused bubble effect
 */

#include "z_eff_ss_sibuki2.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorB regs[2]
#define rPrimColorA regs[3]
#define rEnvColorR regs[4]
#define rEnvColorG regs[5]
#define rEnvColorB regs[6]
#define rEnvColorA regs[7]
#define rTexIdx regs[8]
#define rScale regs[9]

u32 EffectSsSibuki2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsSibuki2_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsSibuki2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Sibuki2_InitVars = {
    EFFECT_SS_SIBUKI2,
    EffectSsSibuki2_Init,
};

u32 EffectSsSibuki2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsSibuki2InitParams* initParams = (EffectSsSibuki2InitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = 10;
    pthis->draw = EffectSsSibuki2_Draw;
    pthis->update = EffectSsSibuki2_Update;
    pthis->rScale = initParams->scale;
    pthis->rPrimColorR = 255;
    pthis->rPrimColorG = 255;
    pthis->rPrimColorB = 255;
    pthis->rPrimColorA = 255;
    pthis->rEnvColorR = 100;
    pthis->rEnvColorG = 100;
    pthis->rEnvColorB = 100;
    pthis->rEnvColorA = 255;
    pthis->rTexIdx = 0;

    return 1;
}

void EffectSsSibuki2_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* bubbleTextures[] = {
        gEffUnusedBubbles1Tex, gEffUnusedBubbles1Tex, gEffUnusedBubbles2Tex,
        gEffUnusedBubbles3Tex, gEffUnusedBubbles4Tex, gEffUnusedBubbles5Tex,
        gEffUnusedBubbles6Tex, gEffUnusedBubbles7Tex, gEffUnusedBubbles8Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale = pthis->rScale / 100.0f;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_sibuki2.c", 158);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_sibuki2.c", 171),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, pthis->rPrimColorA);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(bubbleTextures[pthis->rTexIdx]));
    gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gEffUnusedBubblesDL));

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_sibuki2.c", 198);
}

void EffectSsSibuki2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->rTexIdx < 8) {
        pthis->rTexIdx++;
    }
}

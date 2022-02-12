#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_BOMB_Z_EFF_SS_BOMB_C
#include "actor_common.h"
/*
 * File: z_eff_ss_bomb.c
 * Overlay: ovl_Effect_Ss_Bomb
 * Description: Bomb Blast. Unused in the orignal game.
 */

#include "z_eff_ss_bomb.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rScale regs[0]
#define rTexIdx regs[1]

u32 EffectSsBomb_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsBomb_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBomb_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Bomb_InitVars = {
    EFFECT_SS_BOMB,
    EffectSsBomb_Init,
};

u32 EffectSsBomb_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsBombInitParams* initParams = (EffectSsBombInitParams*)initParamsx;

    Math_Vec3f_Copy(&pthis->pos, &initParams->pos);
    Math_Vec3f_Copy(&pthis->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&pthis->accel, &initParams->accel);
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffBombExplosion1DL);
    pthis->life = 20;
    pthis->draw = EffectSsBomb_Draw;
    pthis->update = EffectSsBomb_Update;
    pthis->rScale = 100;
    pthis->rTexIdx = 0;

    return 1;
}

void EffectSsBomb_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* explosionTextures[] = {
        gEffBombExplosion1Tex,
        gEffBombExplosion2Tex,
        gEffBombExplosion3Tex,
        gEffBombExplosion4Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    Mtx* mtx;
    s32 pad;
    f32 scale;
    s16 color;

    if (1) {}

    OPEN_DISPS(gfxCtx, "../z_eff_ss_bomb.c", 168);

    scale = pthis->rScale / 100.0f;

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);

    gSPMatrix(POLY_XLU_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(explosionTextures[pthis->rTexIdx]));
        gDPPipeSync(POLY_XLU_DISP++);
        func_80094C50(gfxCtx);
        color = pthis->life * 12.75f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, color, color, color, color);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
        gDPPipeSync(POLY_XLU_DISP++);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_bomb.c", 214);
}

void EffectSsBomb_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if ((pthis->life < 21) && (pthis->life > 16)) {
        pthis->rTexIdx = (20 - pthis->life);
    } else {
        pthis->rScale += 0;
        pthis->rTexIdx = 3;
    }

    pthis->accel.x = ((Rand_ZeroOne() * 0.4f) - 0.2f);
    pthis->accel.z = ((Rand_ZeroOne() * 0.4f) - 0.2f);
}

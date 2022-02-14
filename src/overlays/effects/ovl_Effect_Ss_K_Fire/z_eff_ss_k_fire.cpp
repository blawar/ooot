#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_K_FIRE_Z_EFF_SS_K_FIRE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_k_fire.c
 * Overlay: ovl_Effect_Ss_K_Fire
 * Description:
 */

#include "z_eff_ss_k_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_rcp.h"

#define rAlpha regs[0]
#define rScroll regs[2]
#define rType regs[3]
#define rYScale regs[4]
#define rXZScale regs[5]
#define rScaleMax regs[6]

u32 EffectSsKFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsKFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsKFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_K_Fire_InitVars = {
    EFFECT_SS_K_FIRE,
    EffectSsKFire_Init,
};

u32 EffectSsKFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsKFireInitParams* initParams = (EffectSsKFireInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = 100;
    pthis->rScaleMax = initParams->scaleMax;
    pthis->rAlpha = 255;
    pthis->rScroll = (s16)Rand_ZeroFloat(5.0f) - 0x19;
    pthis->rType = initParams->type;
    pthis->draw = EffectSsKFire_Draw;
    pthis->update = EffectSsKFire_Update;

    return 1;
}

void EffectSsKFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 xzScale;
    f32 yScale;

    xzScale = pthis->rXZScale / 10000.0f;
    yScale = pthis->rYScale / 10000.0f;

    OPEN_DISPS(gfxCtx, "../z_eff_k_fire.c", 152);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(xzScale, yScale, xzScale, MTXMODE_APPLY);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                (globalCtx->state.frames * pthis->rScroll).whole(), 0x20, 0x80));

    if (pthis->rType >= 100) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, pthis->rAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 10, 0, 0);
    } else {
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, pthis->rAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, 0);
    }

    if (1) {}

    gDPPipeSync(POLY_XLU_DISP++);
    func_800D1FD4(&globalCtx->billboardMtxF);

    if ((index & 1) != 0) {
        Matrix_RotateY(M_PI, MTXMODE_APPLY);
    }

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_k_fire.c", 215),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(gfxCtx, "../z_eff_k_fire.c", 220);
}

void EffectSsKFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->rXZScale < pthis->rScaleMax) {
        pthis->rXZScale += 4;
        pthis->rYScale += 4;

        if (pthis->rXZScale > pthis->rScaleMax) {
            pthis->rXZScale = pthis->rScaleMax;

            if (pthis->rType != 3) {
                pthis->rYScale = pthis->rScaleMax;
            }
        }
    } else {
        if (pthis->rAlpha > 0) {
            pthis->rAlpha -= 10;
            if (pthis->rAlpha <= 0) {
                pthis->rAlpha = 0;
                pthis->life = 0;
            }
        }
    }

    if (pthis->rType == 3) {
        pthis->rYScale++;
    }
}

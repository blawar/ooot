#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_FCIRCLE_Z_EFF_SS_FCIRCLE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_fcircle.c
 * Overlay: ovl_Effect_Ss_Fcircle
 * Description: Fire Circle
 */

#include "z_eff_ss_fcircle.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define rUnused regs[3] // probably supposed to be an alpha
#define rRadius regs[8]
#define rHeight regs[9]
#define rYaw regs[10]
#define rScale regs[11]

u32 EffectSsFcircle_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsFcircle_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsFcircle_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Fcircle_InitVars = {
    EFFECT_SS_FCIRCLE,
    EffectSsFcircle_Init,
};

u32 EffectSsFcircle_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsFcircleInitParams* initParams = (EffectSsFcircleInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->actor = initParams->actor;
    pthis->vec.x = initParams->pos.x - initParams->actor->world.pos.x;
    pthis->vec.y = initParams->pos.y - initParams->actor->world.pos.y;
    pthis->vec.z = initParams->pos.z - initParams->actor->world.pos.z;
    pthis->gfx = gEffFireCircleDL;
    pthis->life = 20;
    pthis->draw = EffectSsFcircle_Draw;
    pthis->update = EffectSsFcircle_Update;
    pthis->rUnused = 255;
    pthis->rRadius = initParams->radius;
    pthis->rHeight = initParams->height;
    pthis->rYaw = initParams->actor->shape.rot.y;

    return 1;
}

void EffectSsFcircle_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 yScale;
    f32 xzScale;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_fcircle.c", 149);

    scale = (pthis->rScale * (0.5f + (pthis->life * 0.025f))) * 0.01f;
    yScale = (pthis->rHeight * 0.001f) * scale;
    xzScale = (pthis->rRadius * 0.001f) * scale;

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(xzScale, yScale, xzScale, MTXMODE_APPLY);
    Matrix_RotateY(pthis->rYaw * (M_PI / 0x8000), MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_fcircle.c", 163),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, globalCtx->gameplayFrames % 128, 0, 32, 64, 1, 0,
                                ((globalCtx->gameplayFrames) * -0xF) % 256, 32, 64));
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 220, 0, (pthis->life * 12.75f));
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_fcircle.c", 186);
}

void EffectSsFcircle_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    Actor* actor = pthis->actor;

    if (actor != NULL) {
        if (actor->update != NULL) {
            pthis->pos.x = actor->world.pos.x + pthis->vec.x;
            pthis->pos.y = actor->world.pos.y + pthis->vec.y;
            pthis->pos.z = actor->world.pos.z + pthis->vec.z;
            pthis->rYaw = actor->shape.rot.y;

            if (actor->colorFilterTimer > 20) {
                pthis->life = 20;
            } else {
                pthis->life = actor->colorFilterTimer;
            }

            Math_StepToS((s16*)&pthis->rScale, 100, 20);
        } else {
            pthis->actor = NULL;
        }
    }
}

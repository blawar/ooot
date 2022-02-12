#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DEAD_DS_Z_EFF_SS_DEAD_DS_C
#include "actor_common.h"
/*
 * File: z_eff_ss_dead_ds.c
 * Overlay: ovl_Effect_Ss_Dead_Ds
 * Description: Burn mark on the floor
 */

#include "z_eff_ss_dead_ds.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_rcp.h"

#define rScale regs[0]
#define rTimer regs[1]
#define rRoll regs[2]
#define rPitch regs[3]
#define rYaw regs[4]
#define rAlpha regs[5]
#define rScaleStep regs[9]
#define rAlphaStep regs[10]
#define rHalfOfLife regs[11]

u32 EffectSsDeadDs_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDeadDs_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDeadDs_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Dead_Ds_InitVars = {
    EFFECT_SS_DEAD_DS,
    EffectSsDeadDs_Init,
};

u32 EffectSsDeadDs_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsDeadDsInitParams* initParams = (EffectSsDeadDsInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = initParams->life;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->rHalfOfLife = initParams->life / 2;
    pthis->rAlphaStep = initParams->alpha / pthis->rHalfOfLife;
    pthis->draw = EffectSsDeadDs_Draw;
    pthis->update = EffectSsDeadDs_Update;
    pthis->rScale = initParams->scale;
    pthis->rAlpha = initParams->alpha;
    pthis->rTimer = 0;

    return 1;
}

void EffectSsDeadDs_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad;
    f32 scale;
    s32 pad1;
    s32 pad2;
    MtxF mf;
    f32 temp;
    Vec3f pos;
    CollisionPoly* floorPoly;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_dead_ds.c", 157);

    scale = pthis->rScale * 0.01f;
    func_80094BC4(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, pthis->rAlpha);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 0);
    pos = pthis->pos;

    if (pthis->rTimer == 0) {
        Vec3s rpy;
        Vec3f sp44;

        sp44.x = pos.x - pthis->velocity.x;
        sp44.y = pos.y - pthis->velocity.y;
        sp44.z = pos.z - pthis->velocity.z;

        if (BgCheck_EntitySphVsWall1(&globalCtx->colCtx, &pthis->pos, &pos, &sp44, 1.5f, &floorPoly, 1.0f)) {
            func_80038A28(floorPoly, pthis->pos.x, pthis->pos.y, pthis->pos.z, &mf);
            Matrix_Put(&mf);
        } else {
            pos.y++;
            temp = BgCheck_EntityRaycastFloor1(&globalCtx->colCtx, &floorPoly, &pos);

            if (floorPoly != NULL) {
                func_80038A28(floorPoly, pthis->pos.x, temp + 1.5f, pthis->pos.z, &mf);
                Matrix_Put(&mf);
            } else {
                Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
                Matrix_Get(&mf);
            }
        }

        Matrix_MtxFToZYXRotS(&mf, &rpy, 0);
        pthis->rRoll = rpy.x;
        pthis->rPitch = rpy.y;
        pthis->rYaw = rpy.z;
        pthis->pos.y = mf.yw;
        pthis->rTimer++;
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->rRoll, pthis->rPitch, pthis->rYaw, MTXMODE_APPLY);
    Matrix_RotateX(1.57f, MTXMODE_APPLY);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_ss_dead_ds.c", 246),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetCombineLERP(POLY_XLU_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                      PRIMITIVE, 0);
    gSPDisplayList(POLY_XLU_DISP++, gLensFlareCircleDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_dead_ds.c", 255);
}

void EffectSsDeadDs_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->life < pthis->rHalfOfLife) {

        pthis->rScale += pthis->rScaleStep;
        if (pthis->rScale < 0) {
            pthis->rScale = 0;
        }

        pthis->rAlpha -= pthis->rAlphaStep;
        if (pthis->rAlpha < 0) {
            pthis->rAlpha = 0;
        }
    }
}

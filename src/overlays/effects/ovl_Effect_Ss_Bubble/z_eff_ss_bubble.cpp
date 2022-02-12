#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_BUBBLE_Z_EFF_SS_BUBBLE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_bubble.c
 * Overlay: ovl_Effect_Ss_Bubble
 * Description:
 */

#include "z_eff_ss_bubble.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define rScale regs[0]

u32 EffectSsBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Bubble_InitVars = {
    EFFECT_SS_BUBBLE,
    EffectSsBubble_Init,
};

u32 EffectSsBubble_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsBubbleInitParams* initParams = (EffectSsBubbleInitParams*)initParamsx;

    //! @bug Rand_ZeroOne in the macro means a random number is generated for both parts of the macro.
    // In the base game pthis works out because both addresses are segment 4, but it may break if
    // the addresses were changed to refer to different segments
    pthis->gfx = SEGMENTED_TO_VIRTUAL(Rand_ZeroOne() < 0.5f ? gEffBubble1Tex : gEffBubble2Tex);
    pthis->pos.x = ((Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.x;
    pthis->pos.y = (((Rand_ZeroOne() - 0.5f) * initParams->yPosRandScale) + initParams->yPosOffset) + initParams->pos.y;
    pthis->pos.z = ((Rand_ZeroOne() - 0.5f) * initParams->xzPosRandScale) + initParams->pos.z;
    Math_Vec3f_Copy(&pthis->vec, &pthis->pos);
    pthis->life = 1;
    pthis->rScale = (((Rand_ZeroOne() * 0.5f) + 1.0f) * initParams->scale) * 100;
    pthis->draw = EffectSsBubble_Draw;
    pthis->update = EffectSsBubble_Update;

    return 1;
}

void EffectSsBubble_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale = pthis->rScale / 100.0f;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_bubble.c", 154);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_bubble.c", 167),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 150, 150, 150, 0);
    gSPSegment(POLY_OPA_DISP++, 0x08, pthis->gfx);
    gSPDisplayList(POLY_OPA_DISP++, SEGMENTED_TO_VIRTUAL(gEffBubbleDL));

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_bubble.c", 179);
}

void EffectSsBubble_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    WaterBox* waterBox;
    f32 waterSurfaceY;
    Vec3f ripplePos;

    waterSurfaceY = pthis->pos.y;

    // kill bubble if it's out of range of a water box
    if (!WaterBox_GetSurface1(globalCtx, &globalCtx->colCtx, pthis->pos.x, pthis->pos.z, &waterSurfaceY, &waterBox)) {
        pthis->life = -1;
        return;
    }

    if (waterSurfaceY < pthis->pos.y) {
        ripplePos.x = pthis->pos.x;
        ripplePos.y = waterSurfaceY;
        ripplePos.z = pthis->pos.z;
        EffectSsGRipple_Spawn(globalCtx, &ripplePos, 0, 80, 0);
        pthis->life = -1;
    } else {
        pthis->life++;
        pthis->pos.x = ((Rand_ZeroOne() * 0.5f) - 0.25f) + pthis->vec.x;
        pthis->accel.y = (Rand_ZeroOne() - 0.3f) * 0.2f;
        pthis->pos.z = ((Rand_ZeroOne() * 0.5f) - 0.25f) + pthis->vec.z;
    }
}

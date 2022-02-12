#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_SPK_Z_EFF_SS_G_SPK_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_spk.c
 * Overlay: ovl_Effect_Ss_G_Spk
 * Description: Sparks
 */

#include "z_eff_ss_g_spk.h"
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
#define rTexIdx regs[8]
#define rScale regs[9]
#define rScaleStep regs[10]

u32 EffectSsGSpk_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsGSpk_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGSpk_UpdateNoAccel(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGSpk_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_G_Spk_InitVars = {
    EFFECT_SS_G_SPK,
    EffectSsGSpk_Init,
};

u32 EffectSsGSpk_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsGSpkInitParams* initParams = (EffectSsGSpkInitParams*)initParamsx;

    Math_Vec3f_Copy(&pthis->pos, &initParams->pos);
    Math_Vec3f_Copy(&pthis->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&pthis->accel, &initParams->accel);
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffSparkDL);

    if (initParams->updateMode == 0) {
        pthis->life = 10;
        pthis->vec.x = initParams->pos.x - initParams->actor->world.pos.x;
        pthis->vec.y = initParams->pos.y - initParams->actor->world.pos.y;
        pthis->vec.z = initParams->pos.z - initParams->actor->world.pos.z;
        pthis->update = EffectSsGSpk_Update;
    } else {
        pthis->life = 5;
        pthis->update = EffectSsGSpk_UpdateNoAccel;
    }

    pthis->draw = EffectSsGSpk_Draw;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;
    pthis->rEnvColorA = initParams->envColor.a;
    pthis->rTexIdx = 0;
    pthis->rScale = initParams->scale;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->actor = initParams->actor;

    return 1;
}

void EffectSsGSpk_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static void* sparkTextures[] = {
        gEffSpark1Tex,
        gEffSpark2Tex,
        gEffSpark3Tex,
        gEffSpark4Tex,
    };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    Mtx* mtx;
    f32 scale;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_g_spk.c", 208);

    scale = pthis->rScale * 0.0025f;
    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
    SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sparkTextures[pthis->rTexIdx]));
        func_80094BC4(gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    if (1) {}
    if (1) {}

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_g_spk.c", 255);
}

void EffectSsGSpk_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {

    pthis->accel.x = (Rand_ZeroOne() - 0.5f) * 3.0f;
    pthis->accel.z = (Rand_ZeroOne() - 0.5f) * 3.0f;

    if (pthis->actor != NULL) {
        if ((pthis->actor->category == ACTORCAT_EXPLOSIVE) && (pthis->actor->update != NULL)) {
            pthis->pos.x = pthis->actor->world.pos.x + pthis->vec.x;
            pthis->pos.y = pthis->actor->world.pos.y + pthis->vec.y;
            pthis->pos.z = pthis->actor->world.pos.z + pthis->vec.z;
        }
    }

    pthis->vec.x += pthis->accel.x;
    pthis->vec.z += pthis->accel.z;

    pthis->rTexIdx++;
    pthis->rTexIdx &= 3;
    pthis->rScale += pthis->rScaleStep;
}

// pthis update mode is unused in the original game
// with pthis update mode, the sparks dont move randomly in the xz plane, appearing to be on top of each other
void EffectSsGSpk_UpdateNoAccel(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->actor != NULL) {
        if ((pthis->actor->category == ACTORCAT_EXPLOSIVE) && (pthis->actor->update != NULL)) {
            pthis->pos.x += (Math_SinS(pthis->actor->world.rot.y) * pthis->actor->speedXZ);
            pthis->pos.z += (Math_CosS(pthis->actor->world.rot.y) * pthis->actor->speedXZ);
        }
    }

    pthis->rTexIdx++;
    pthis->rTexIdx &= 3;
    pthis->rScale += pthis->rScaleStep;
}

#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_D_FIRE_Z_EFF_SS_D_FIRE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_d_fire.c
 * Overlay: ovl_Effect_Ss_D_Fire
 * Description: Dodongo Fire
 */

#include "z_eff_ss_d_fire.h"
#include "objects/object_dodongo/object_dodongo.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skin_matrix.h"

#define rScale regs[0]
#define rTexIdx regs[1]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rPrimColorA regs[5]
#define rFadeDelay regs[6]
#define rScaleStep regs[9]
#define rObjBankIdx regs[10]
#define rYAccelStep regs[11] // has no effect due to how it's implemented

u32 EffectSsDFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_D_Fire_InitVars = {
    EFFECT_SS_D_FIRE,
    EffectSsDFire_Init,
};

u32 EffectSsDFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsDFireInitParams* initParams = (EffectSsDFireInitParams*)initParamsx;
    s32 objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_DODONGO);

    if (objBankIndex >= 0) {
        pthis->pos = initParams->pos;
        pthis->velocity = initParams->velocity;
        pthis->accel = initParams->accel;
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gDodongoFireDL);
        pthis->life = initParams->life;
        pthis->rScale = initParams->scale;
        pthis->rScaleStep = initParams->scaleStep;
        pthis->rYAccelStep = 0;
        pthis->rObjBankIdx = objBankIndex;
        pthis->draw = EffectSsDFire_Draw;
        pthis->update = EffectSsDFire_Update;
        pthis->rTexIdx = ((s16)(globalCtx->state.frames % 4) ^ 3);
        pthis->rPrimColorR = 255;
        pthis->rPrimColorG = 255;
        pthis->rPrimColorB = 50;
        pthis->rPrimColorA = initParams->alpha;
        pthis->rFadeDelay = initParams->fadeDelay;

        return 1;
    }

    return 0;
}

static void* sTextures[] = { gDodongoFire0Tex, gDodongoFire1Tex, gDodongoFire2Tex, gDodongoFire3Tex };

void EffectSsDFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    MtxF mfTrans11DA0;
    s32 pad;
    void* object;
    Mtx* mtx;
    f32 scale;

    object = gObjectTable[pthis->rObjBankIdx].vromStart.buffer();

    OPEN_DISPS(gfxCtx, "../z_eff_ss_d_fire.c", 276);

    if (Object_GetIndex(&globalCtx->objectCtx, OBJECT_DODONGO) > -1) {
        gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
        gSPSegment(POLY_XLU_DISP++, 0x06, object);
        scale = pthis->rScale / 100.0f;
        SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
        SkinMatrix_SetScale(&mfScale, scale, scale, 1.0f);
        SkinMatrix_MtxFMtxFMult(&mfTrans, &globalCtx->billboardMtxF, &mfTrans11DA0);
        SkinMatrix_MtxFMtxFMult(&mfTrans11DA0, &mfScale, &mfResult);

        mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

        if (mtx != NULL) {
            gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            func_80094BC4(gfxCtx);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                            pthis->rPrimColorA);
            gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTextures[pthis->rTexIdx]));
            gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_d_fire.c", 330);
}

void EffectSsDFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rTexIdx++;
    pthis->rTexIdx &= 3;
    pthis->rScale += pthis->rScaleStep;

    if (pthis->rFadeDelay >= pthis->life) {
        pthis->rPrimColorA -= 5;
        if (pthis->rPrimColorA < 0) {
            pthis->rPrimColorA = 0;
        }
    } else {
        pthis->rPrimColorA += 15;
        if (pthis->rPrimColorA > 255) {
            pthis->rPrimColorA = 255;
        }
    }

    if (pthis->accel.y < 0.0f) {
        pthis->accel.y += pthis->rYAccelStep * 0.01f;
    }

    if (pthis->life <= 0) {
        pthis->rYAccelStep += 0;
    }
}

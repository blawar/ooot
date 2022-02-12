#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_G_MAGMA2_Z_EFF_SS_G_MAGMA2_C
#include "actor_common.h"
/*
 * File: z_eff_ss_g_magma2.c
 * Overlay: ovl_Effect_Ss_G_Magma2
 * Description:
 */

#include "z_eff_ss_g_magma2.h"
#include "objects/object_kingdodongo/object_kingdodongo.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorA regs[2]
#define rEnvColorR regs[3]
#define rEnvColorG regs[4]
#define rEnvColorA regs[5]
#define rTexIdx regs[6]
#define rTimer regs[7]
#define rUpdateRate regs[8]
#define rDrawMode regs[9]
#define rObjBankIdx regs[10]
#define rScale regs[11]

u32 EffectSsGMagma2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsGMagma2_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsGMagma2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

static void* sTextures[] = {
    object_kingdodongo_Tex_02E4E0, object_kingdodongo_Tex_02E8E0, object_kingdodongo_Tex_02ECE0,
    object_kingdodongo_Tex_02F0E0, object_kingdodongo_Tex_02F4E0, object_kingdodongo_Tex_02F8E0,
    object_kingdodongo_Tex_02FCE0, object_kingdodongo_Tex_0300E0, object_kingdodongo_Tex_0304E0,
    object_kingdodongo_Tex_0308E0, object_kingdodongo_Tex_0308E0, object_kingdodongo_Tex_0308E0,
    object_kingdodongo_Tex_0308E0,
};

EffectSsInit Effect_Ss_G_Magma2_InitVars = {
    EFFECT_SS_G_MAGMA2,
    EffectSsGMagma2_Init,
};

u32 EffectSsGMagma2_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    s32 objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_KINGDODONGO);
    s32 pad;

    if ((objBankIndex >= 0) && Object_IsLoaded(&globalCtx->objectCtx, objBankIndex)) {
        Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
        EffectSsGMagma2InitParams* initParams = (EffectSsGMagma2InitParams*)initParamsx;

        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[objBankIndex].vromStart.get());
        pthis->rObjBankIdx = objBankIndex;
        pthis->pos = initParams->pos;
        pthis->velocity = zeroVec;
        pthis->accel = zeroVec;
        pthis->life = 100;
        pthis->draw = EffectSsGMagma2_Draw;
        pthis->update = EffectSsGMagma2_Update;
        pthis->gfx = SEGMENTED_TO_VIRTUAL(object_kingdodongo_DL_025A90);
        pthis->rTexIdx = 0;
        pthis->rDrawMode = initParams->drawMode;
        pthis->rUpdateRate = initParams->updateRate;
        pthis->rScale = initParams->scale;
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorA = initParams->primColor.a;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorA = initParams->envColor.a;

        return 1;
    }

    return 0;
}

void EffectSsGMagma2_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;
    void* object;

    scale = pthis->rScale / 100.0f;
    object = gObjectTable[pthis->rObjBankIdx].vromStart.buffer();

    OPEN_DISPS(gfxCtx, "../z_eff_ss_g_magma2.c", 261);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
    gSPSegment(POLY_XLU_DISP++, 0x06, object);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_g_magma2.c", 282),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (pthis->rDrawMode == 0) {
        POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0x3D);
    } else {
        POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
    }

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, 0, pthis->rPrimColorA);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, 0, pthis->rEnvColorA);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTextures[pthis->rTexIdx]));
    gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_g_magma2.c", 311);
}

void EffectSsGMagma2_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rTimer += pthis->rUpdateRate;

    if (pthis->rTimer >= 10) {
        pthis->rTimer -= 10;
        pthis->rTexIdx++;

        if (pthis->rTexIdx >= 10) {
            pthis->life = 0;
        }

        if (pthis->rDrawMode == 0) {
            pthis->rPrimColorG -= 26;

            if (pthis->rPrimColorG <= 0) {
                pthis->rPrimColorG = 0;
            }

            pthis->rEnvColorR -= 26;

            if (pthis->rEnvColorR <= 0) {
                pthis->rEnvColorR = 0;
            }
        }
    }
}

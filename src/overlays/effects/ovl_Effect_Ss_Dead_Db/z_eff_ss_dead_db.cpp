#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DEAD_DB_Z_EFF_SS_DEAD_DB_C
#include "actor_common.h"
/*
 * File: z_eff_ss_dead_db.c
 * Overlay: ovl_Effect_Ss_Dead_Db
 * Description: Flames and sound used when an enemy dies
 */

#include "z_eff_ss_dead_db.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define rScale regs[0]
#define rTextIdx regs[1]
#define rPrimColorR regs[2]
#define rPrimColorG regs[3]
#define rPrimColorB regs[4]
#define rPrimColorA regs[5]
#define rEnvColorR regs[6]
#define rEnvColorG regs[7]
#define rEnvColorB regs[8]
#define rScaleStep regs[9]
#define rPlaySound regs[10]
#define rReg11 regs[11]

u32 EffectSsDeadDb_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDeadDb_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsDeadDb_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Dead_Db_InitVars = {
    EFFECT_SS_DEAD_DB,
    EffectSsDeadDb_Init,
};

u32 EffectSsDeadDb_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsDeadDbInitParams* initParams = (EffectSsDeadDbInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffEnemyDeathFlameDL);
    pthis->life = initParams->unk_34;
    pthis->flags = 4;
    pthis->rScaleStep = initParams->scaleStep;
    pthis->rReg11 = initParams->unk_34;
    pthis->draw = EffectSsDeadDb_Draw;
    pthis->update = EffectSsDeadDb_Update;
    pthis->rScale = initParams->scale;
    pthis->rTextIdx = 0;
    pthis->rPlaySound = initParams->playSound;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rPrimColorA = initParams->primColor.a;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;

    return 1;
}

static void* sTextures[] = {
    gEffEnemyDeathFlame1Tex, gEffEnemyDeathFlame2Tex,  gEffEnemyDeathFlame3Tex, gEffEnemyDeathFlame4Tex,
    gEffEnemyDeathFlame5Tex, gEffEnemyDeathFlame6Tex,  gEffEnemyDeathFlame7Tex, gEffEnemyDeathFlame8Tex,
    gEffEnemyDeathFlame9Tex, gEffEnemyDeathFlame10Tex,
};

void EffectSsDeadDb_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    MtxF mfTrans;
    MtxF mfScale;
    MtxF mfResult;
    Mtx* mtx;
    f32 scale;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_dead_db.c", 201);

    scale = pthis->rScale * 0.01f;

    SkinMatrix_SetTranslate(&mfTrans, pthis->pos.x, pthis->pos.y, pthis->pos.z);
    SkinMatrix_SetScale(&mfScale, scale, scale, scale);
    SkinMatrix_MtxFMtxFMult(&mfTrans, &mfScale, &mfResult);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &mfResult);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80094BC4(gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, 0);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                        pthis->rPrimColorA);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTextures[pthis->rTextIdx]));
        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_dead_db.c", 247);
}

void EffectSsDeadDb_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    f32 w;
    f32 pad;

    pthis->rTextIdx = (f32)((pthis->rReg11 - pthis->life) * 9) / pthis->rReg11;
    pthis->rScale += pthis->rScaleStep;

    pthis->rPrimColorR -= 10;
    if (pthis->rPrimColorR < 0) {
        pthis->rPrimColorR = 0;
    }

    pthis->rPrimColorG -= 10;
    if (pthis->rPrimColorG < 0) {
        pthis->rPrimColorG = 0;
    }

    pthis->rPrimColorB -= 10;
    if (pthis->rPrimColorB < 0) {
        pthis->rPrimColorB = 0;
    }

    pthis->rEnvColorR -= 10;
    if (pthis->rEnvColorR < 0) {
        pthis->rEnvColorR = 0;
    }

    pthis->rEnvColorG -= 10;
    if (pthis->rEnvColorG < 0) {
        pthis->rEnvColorG = 0;
    }

    pthis->rEnvColorB -= 10;
    if (pthis->rEnvColorB < 0) {
        pthis->rEnvColorB = 0;
    }

    if (pthis->rPlaySound && (pthis->rTextIdx == 1)) {
        SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &pthis->pos, &pthis->vec, &w);
        Audio_PlaySoundGeneral(NA_SE_EN_EXTINCT, &pthis->vec, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

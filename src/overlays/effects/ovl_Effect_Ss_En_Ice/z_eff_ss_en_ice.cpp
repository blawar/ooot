#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_EN_ICE_Z_EFF_SS_EN_ICE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_en_ice.c
 * Overlay: ovl_Effect_Ss_En_Ice
 * Description: Ice clumps
 */

#include "z_eff_ss_en_ice.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define rLifespan regs[0]
#define rYaw regs[1]
#define rPitch regs[2]
#define rRotSpeed regs[3]
#define rPrimColorR regs[4]
#define rPrimColorG regs[5]
#define rPrimColorB regs[6]
#define rPrimColorA regs[7]
#define rEnvColorR regs[8]
#define rEnvColorG regs[9]
#define rEnvColorB regs[10]
#define rAlphaMode regs[11]
#define rScale regs[12]

u32 EffectSsEnIce_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsEnIce_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsEnIce_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsEnIce_UpdateFlying(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_En_Ice_InitVars = {
    EFFECT_SS_EN_ICE,
    EffectSsEnIce_Init,
};

u32 EffectSsEnIce_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsEnIceInitParams* initParams = (EffectSsEnIceInitParams*)initParamsx;

    if (initParams->type == 0) {
        Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

        pthis->pos = initParams->pos;
        pthis->vec.x = pthis->pos.x - initParams->actor->world.pos.x;
        pthis->vec.y = pthis->pos.y - initParams->actor->world.pos.y;
        pthis->vec.z = pthis->pos.z - initParams->actor->world.pos.z;
        pthis->velocity = zeroVec;
        pthis->accel = zeroVec;
        pthis->life = 10;
        pthis->actor = initParams->actor;
        pthis->draw = EffectSsEnIce_Draw;
        pthis->update = EffectSsEnIce_UpdateFlying;
        pthis->rScale = initParams->scale * 100.0f;
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorB = initParams->primColor.b;
        pthis->rPrimColorA = initParams->primColor.a;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorB = initParams->envColor.b;
        pthis->rAlphaMode = 1;
        pthis->rPitch = Rand_CenteredFloat(65536.0f);
    } else if (initParams->type == 1) {
        pthis->pos = initParams->pos;
        pthis->vec = initParams->pos;
        pthis->velocity = initParams->velocity;
        pthis->accel = initParams->accel;
        pthis->life = initParams->life;
        pthis->draw = EffectSsEnIce_Draw;
        pthis->update = EffectSsEnIce_Update;
        pthis->rLifespan = initParams->life;
        pthis->rScale = initParams->scale * 100.0f;
        pthis->rYaw = Math_Atan2S(initParams->velocity.z, initParams->velocity.x);
        pthis->rPitch = 0;
        pthis->rPrimColorR = initParams->primColor.r;
        pthis->rPrimColorG = initParams->primColor.g;
        pthis->rPrimColorB = initParams->primColor.b;
        pthis->rPrimColorA = initParams->primColor.a;
        pthis->rEnvColorR = initParams->envColor.r;
        pthis->rEnvColorG = initParams->envColor.g;
        pthis->rEnvColorB = initParams->envColor.b;
        pthis->rAlphaMode = 0;
    } else {
        osSyncPrintf("Effect_Ss_En_Ice_ct():pid->mode_swがエラーです。\n");
        return 0;
    }

    return 1;
}

void EffectSsEnIce_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;
    Vec3f hiliteLightDir;
    u32 gameplayFrames;
    f32 alpha;

    scale = pthis->rScale * 0.01f;
    gameplayFrames = globalCtx->gameplayFrames;

    OPEN_DISPS(gfxCtx, "../z_eff_en_ice.c", 235);

    if (pthis->rAlphaMode != 0) {
        alpha = pthis->life * 12;
    } else {
        if ((pthis->rLifespan > 0) && (pthis->life < (pthis->rLifespan >> 1))) {
            alpha = ((pthis->life * 2.0f) / pthis->rLifespan);
            alpha *= 255.0f;
        } else {
            alpha = 255.0f;
        }
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_RotateY(pthis->rYaw * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_RotateX(pthis->rPitch * (M_PI / 0x8000), MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_en_ice.c", 261),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    hiliteLightDir.x = 89.8f;
    hiliteLightDir.y = 0.0f;
    hiliteLightDir.z = 89.8f;

    func_80093D84(globalCtx->state.gfxCtx);
    func_8002EB44(&pthis->pos, &globalCtx->view.eye, &hiliteLightDir, globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, gameplayFrames & 0xFF, 0x20, 0x10, 1, 0,
                                (gameplayFrames * 2) & 0xFF, 0x40, 0x20));
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB,
                    pthis->rPrimColorA);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, (u32)alpha);
    gSPDisplayList(POLY_XLU_DISP++, gEffIceFragment2DL);

    CLOSE_DISPS(gfxCtx, "../z_eff_en_ice.c", 294);
}

void EffectSsEnIce_UpdateFlying(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s16 rand;

    if ((pthis->actor != NULL) && (pthis->actor->update != NULL)) {
        if ((pthis->life >= 9) && (pthis->actor->colorFilterTimer != 0) && (!(pthis->actor->colorFilterParams & 0xC000))) {
            pthis->pos.x = pthis->actor->world.pos.x + pthis->vec.x;
            pthis->pos.y = pthis->actor->world.pos.y + pthis->vec.y;
            pthis->pos.z = pthis->actor->world.pos.z + pthis->vec.z;
            pthis->life++;
        } else if (pthis->life == 9) {
            pthis->accel.x = Math_SinS(Math_Vec3f_Yaw(&pthis->actor->world.pos, &pthis->pos)) * (Rand_ZeroOne() + 1.0f);
            pthis->accel.z = Math_CosS(Math_Vec3f_Yaw(&pthis->actor->world.pos, &pthis->pos)) * (Rand_ZeroOne() + 1.0f);
            pthis->accel.y = -1.5f;
            pthis->velocity.y = 5.0f;
        }
    } else {
        if (pthis->life >= 9) {
            rand = Rand_CenteredFloat(65535.0f);
            pthis->accel.x = Math_SinS(rand) * (Rand_ZeroOne() + 1.0f);
            pthis->accel.z = Math_CosS(rand) * (Rand_ZeroOne() + 1.0f);
            pthis->life = 8;
            pthis->accel.y = -1.5f;
            pthis->velocity.y = 5.0f;
        }
    }
}

void EffectSsEnIce_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rPitch += pthis->rRotSpeed; // rRotSpeed is not initialized so pthis does nothing
}

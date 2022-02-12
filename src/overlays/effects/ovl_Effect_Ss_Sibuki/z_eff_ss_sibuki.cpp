#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_SIBUKI_Z_EFF_SS_SIBUKI_C
#include "actor_common.h"
/*
 * File: z_eff_ss_sibuki.c
 * Overlay: ovl_Effect_Ss_Sibuki
 * Description: Bubbles (only used by gohma and gohmalings in the original game)
 */

#include "z_eff_ss_sibuki.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define rPrimColorR regs[0]
#define rPrimColorG regs[1]
#define rPrimColorB regs[2]
#define rPrimColorA regs[3]
#define rEnvColorR regs[4]
#define rEnvColorG regs[5]
#define rEnvColorB regs[6]
#define rEnvColorA regs[7]
#define rMoveDelay regs[8]
#define rDirection regs[9]
#define rScale regs[10]

u32 EffectSsSibuki_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsSibuki_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsSibuki_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Sibuki_InitVars = {
    EFFECT_SS_SIBUKI,
    EffectSsSibuki_Init,
};

u32 EffectSsSibuki_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsSibukiInitParams* initParams = (EffectSsSibukiInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;

    if (KREG(2) != 0) {
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffBubble2Tex);
    } else {
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffBubble1Tex);
    }

    pthis->life = ((s16)((Rand_ZeroOne() * (500.0f + KREG(64))) * 0.01f)) + KREG(65) + 10;
    pthis->rMoveDelay = initParams->moveDelay + 1;
    pthis->draw = EffectSsSibuki_Draw;
    pthis->update = EffectSsSibuki_Update;
    pthis->rDirection = initParams->direction;
    pthis->rScale = initParams->scale;
    pthis->rPrimColorR = 100;
    pthis->rPrimColorG = 100;
    pthis->rPrimColorB = 100;
    pthis->rPrimColorA = 100;
    pthis->rEnvColorR = 255;
    pthis->rEnvColorG = 255;
    pthis->rEnvColorB = 255;
    pthis->rEnvColorA = 255;

    return 1;
}

void EffectSsSibuki_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale = pthis->rScale / 100.0f;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_sibuki.c", 163);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_sibuki.c", 176),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, pthis->rPrimColorA);
    gDPSetEnvColor(POLY_OPA_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, pthis->rEnvColorA);
    gSPSegment(POLY_OPA_DISP++, 0x08, pthis->gfx);
    gSPDisplayList(POLY_OPA_DISP++, SEGMENTED_TO_VIRTUAL(gEffBubbleDL));

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_sibuki.c", 198);
}

void EffectSsSibuki_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad[3];
    f32 xzVelScale;
    s16 yaw;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->pos.y <= player->actor.floorHeight) {
        pthis->life = 0;
    }

    if (pthis->rMoveDelay != 0) {
        pthis->rMoveDelay--;

        if (pthis->rMoveDelay == 0) {
            yaw = Camera_GetInputDirYaw(Gameplay_GetCamera(globalCtx, 0));
            xzVelScale = ((200.0f + KREG(20)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * (KREG(23) + 20.0f));

            if (pthis->rDirection != 0) {
                xzVelScale *= -1.0f;
            }

            pthis->velocity.x = Math_CosS(yaw) * xzVelScale;
            pthis->velocity.z = -Math_SinS(yaw) * xzVelScale;

            pthis->velocity.y = ((700.0f + KREG(21)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * (KREG(24) + 20.0f));
            pthis->accel.y = ((-100.0f + KREG(22)) * 0.01f) + ((0.1f * Rand_ZeroOne()) * KREG(25));

            if (KREG(3) != 0) {
                pthis->velocity.x *= (KREG(3) * 0.01f);
                pthis->velocity.y *= (KREG(3) * 0.01f);
                pthis->velocity.z *= (KREG(3) * 0.01f);
                pthis->accel.y *= (KREG(4) * 0.01f);
            }
        }
    } else {
        if (pthis->rScale != 0) {
            pthis->rScale = (pthis->rScale - KREG(26)) - 3;
        }
    }
}

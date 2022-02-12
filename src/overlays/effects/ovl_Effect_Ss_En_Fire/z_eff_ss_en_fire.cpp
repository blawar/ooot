#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_EN_FIRE_Z_EFF_SS_EN_FIRE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_en_fire.c
 * Overlay: ovl_Effect_Ss_En_Fire
 * Description:
 */

#include "z_eff_ss_en_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define rScaleMax regs[0]
#define rScale regs[1]
#define rLifespan regs[2]
#define rUnused regs[3]
#define rPitch regs[4]
#define rYaw regs[5]
#define rReg6 regs[6]
#define rBodyPart regs[7]
#define rFlags regs[8]
#define rScroll regs[9]

u32 EffectSsEnFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsEnFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsEnFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_En_Fire_InitVars = {
    EFFECT_SS_EN_FIRE,
    EffectSsEnFire_Init,
};

u32 EffectSsEnFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsEnFireInitParams* initParams = (EffectSsEnFireInitParams*)initParamsx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    pthis->pos = initParams->pos;
    pthis->velocity = pthis->accel = zeroVec;
    pthis->life = 20;
    pthis->rLifespan = pthis->life;
    pthis->actor = initParams->actor;
    pthis->rScroll = Rand_ZeroOne() * 20.0f;
    pthis->draw = EffectSsEnFire_Draw;
    pthis->update = EffectSsEnFire_Update;
    pthis->rUnused = -15;

    if (initParams->bodyPart < 0) {
        pthis->rYaw = Math_Vec3f_Yaw(&initParams->actor->world.pos, &initParams->pos) - initParams->actor->shape.rot.y;
        pthis->rPitch =
            Math_Vec3f_Pitch(&initParams->actor->world.pos, &initParams->pos) - initParams->actor->shape.rot.x;
        pthis->vec.z = Math_Vec3f_DistXYZ(&initParams->pos, &initParams->actor->world.pos);
    }

    pthis->rScaleMax = initParams->scale;

    if ((initParams->unk_12 & 0x8000) != 0) {
        pthis->rScale = initParams->scale;
    } else {
        pthis->rScale = 0;
    }

    pthis->rReg6 = initParams->unk_12 & 0x7FFF;
    pthis->rBodyPart = initParams->bodyPart;
    pthis->rFlags = initParams->flags;

    return 1;
}

void EffectSsEnFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 scale;
    s16 camYaw;
    s32 pad[3];
    s16 redGreen;

    OPEN_DISPS(gfxCtx, "../z_eff_en_fire.c", 169);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    camYaw = (Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000);
    Matrix_RotateY(camYaw * (M_PI / 0x8000), MTXMODE_APPLY);

    scale = Math_SinS(pthis->life * 0x333) * (pthis->rScale * 0.00005f);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_en_fire.c", 180),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    redGreen = pthis->life - 5;

    if (redGreen < 0) {
        redGreen = 0;
    }

    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, redGreen * 12.7f, 0, 0, 0);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x0, 0x80, redGreen * 12.7f, redGreen * 12.7f, 0, 255);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, (pthis->rScroll * -0x14) & 0x1FF,
                                0x20, 0x80));

    if (((pthis->rFlags & 0x7FFF) != 0) || (pthis->life < 18)) {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire2DL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_en_fire.c", 213);
}

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x14C */ Vec3f firePos[10];
} FireActorF;

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x14C */ Vec3s firePos[10];
} FireActorS;

void EffectSsEnFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {

    pthis->rScroll++;

    if (pthis->actor != NULL) {
        if (pthis->actor->colorFilterTimer >= 22) {
            pthis->life++;
        }
        if (pthis->actor->update != NULL) {
            Math_SmoothStepToS((s16*)&pthis->rScale, pthis->rScaleMax, 1, pthis->rScaleMax >> 3, 0);

            if (pthis->rBodyPart < 0) {
                Matrix_Translate(pthis->actor->world.pos.x, pthis->actor->world.pos.y, pthis->actor->world.pos.z,
                                 MTXMODE_NEW);
                Matrix_RotateY((pthis->rYaw + pthis->actor->shape.rot.y) * (M_PI / 0x8000), MTXMODE_APPLY);
                Matrix_RotateX((pthis->rPitch + pthis->actor->shape.rot.x) * (M_PI / 0x8000), MTXMODE_APPLY);
                Matrix_MultVec3f(&pthis->vec, &pthis->pos);
            } else {
                if ((pthis->rFlags & 0x8000)) {
                    pthis->pos.x = ((FireActorS*)pthis->actor)->firePos[pthis->rBodyPart].x;
                    pthis->pos.y = ((FireActorS*)pthis->actor)->firePos[pthis->rBodyPart].y;
                    pthis->pos.z = ((FireActorS*)pthis->actor)->firePos[pthis->rBodyPart].z;
                } else {
                    pthis->pos.x = ((FireActorF*)pthis->actor)->firePos[pthis->rBodyPart].x;
                    pthis->pos.y = ((FireActorF*)pthis->actor)->firePos[pthis->rBodyPart].y;
                    pthis->pos.z = ((FireActorF*)pthis->actor)->firePos[pthis->rBodyPart].z;
                }
            }
        } else if (pthis->rReg6 != 0) {
            pthis->life = 0;
        } else {
            pthis->actor = NULL;
        }
    }
}

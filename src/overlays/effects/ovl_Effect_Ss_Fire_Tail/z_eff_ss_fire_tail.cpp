#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_FIRE_TAIL_Z_EFF_SS_FIRE_TAIL_C
#include "actor_common.h"
/*
 * File: z_eff_ss_fire_tail.c
 * Overlay: ovl_Effect_Ss_Fire_Tail
 * Description: Fire (burned by something)
 */

#include "z_eff_ss_fire_tail.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define rScale regs[0]
#define rLifespan regs[1]
#define rReg2 regs[2]
#define rReg3 regs[3]
#define rPrimColorR regs[4]
#define rPrimColorG regs[5]
#define rPrimColorB regs[6]
#define rEnvColorR regs[7]
#define rEnvColorG regs[8]
#define rEnvColorB regs[9]
#define rReg10 regs[10]
#define rBodyPart regs[11]
#define rType regs[12]

u32 EffectSsFireTail_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsFireTail_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsFireTail_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Fire_Tail_InitVars = {
    EFFECT_SS_FIRE_TAIL,
    EffectSsFireTail_Init,
};

u32 EffectSsFireTail_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsFireTailInitParams* initParams = (EffectSsFireTailInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->vec = initParams->unk_14;
    pthis->velocity.x = 0.0f;
    pthis->velocity.y = 0.0f;
    pthis->velocity.z = 0.0f;
    pthis->accel.x = 0.0f;
    pthis->accel.y = 0.0f;
    pthis->accel.z = 0.0f;
    pthis->life = initParams->life;
    pthis->actor = initParams->actor;
    pthis->draw = EffectSsFireTail_Draw;
    pthis->update = EffectSsFireTail_Update;
    pthis->rScale = initParams->scale * 1000.0f;
    pthis->rLifespan = initParams->life;
    pthis->rReg2 = -0xA;
    pthis->rReg3 = -0xF;
    if (initParams->unk_20 == 0) {
        initParams->unk_20 = 1;
    }
    pthis->rReg10 = initParams->unk_20;
    pthis->rPrimColorR = initParams->primColor.r;
    pthis->rPrimColorG = initParams->primColor.g;
    pthis->rPrimColorB = initParams->primColor.b;
    pthis->rEnvColorR = initParams->envColor.r;
    pthis->rEnvColorG = initParams->envColor.g;
    pthis->rEnvColorB = initParams->envColor.b;
    pthis->rBodyPart = initParams->bodyPart;
    pthis->rType = initParams->type;

    return 1;
}

void EffectSsFireTail_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    s16 yaw;
    Vec3f scale;
    f32 temp1;
    f32 temp2;
    f32 dist;

    OPEN_DISPS(gfxCtx, "../z_eff_fire_tail.c", 182);

    scale.x = scale.y = scale.z = 0.0f;

    if (pthis->actor != NULL) {

        pthis->vec = pthis->actor->velocity;

        if (pthis->rBodyPart < 0) {
            Matrix_Translate(pthis->pos.x + pthis->actor->world.pos.x, pthis->pos.y + pthis->actor->world.pos.y,
                             pthis->pos.z + pthis->actor->world.pos.z, MTXMODE_NEW);
        } else {
            Player* player = GET_PLAYER(globalCtx);
            s16 bodyPart = pthis->rBodyPart;

            pthis->pos.x =
                player->bodyPartsPos[bodyPart].x - (Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx))) * 5.0f);
            pthis->pos.y = player->bodyPartsPos[bodyPart].y;
            pthis->pos.z =
                player->bodyPartsPos[bodyPart].z - (Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx))) * 5.0f);

            Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
        }
    } else {
        Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    }

    yaw = Math_Vec3f_Yaw(&scale, &pthis->vec) - Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx));
    temp1 = fabsf(Math_CosS(yaw));
    temp2 = Math_SinS(yaw);
    dist = Math_Vec3f_DistXZ(&scale, &pthis->vec) / (pthis->rReg10 * 0.1f);
    Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_RotateZ(temp2 * pthis->rReg2 * dist * (M_PI / 180.0f), MTXMODE_APPLY);
    temp2 = 1.0f - ((f32)(pthis->life + 1) / pthis->rLifespan);
    temp2 = 1.0f - SQ(temp2);
    scale.x = scale.y = scale.z = temp2 * (pthis->rScale * 0.000010000001f);
    Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);
    temp1 = (pthis->rReg3 * 0.01f * temp1 * dist) + 1.0f;

    if (temp1 < 0.1f) {
        temp1 = 0.1f;
    }

    Matrix_Scale(1.0f, temp1, 1.0f / temp1, MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_fire_tail.c", 238),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, pthis->rPrimColorR, pthis->rPrimColorG, pthis->rPrimColorB, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, pthis->rEnvColorR, pthis->rEnvColorG, pthis->rEnvColorB, 0);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0,
                                (globalCtx->state.frames * -0x14) & 0x1FF, 32, 128));

    if (pthis->rType != 0) {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire2DL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_fire_tail.c", 273);
}

void EffectSsFireTail_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rScale *= 0.9f;
}

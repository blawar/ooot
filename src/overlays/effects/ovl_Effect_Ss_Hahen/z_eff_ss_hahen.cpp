#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_HAHEN_Z_EFF_SS_HAHEN_C
#include "actor_common.h"
/*
 * File: z_eff_ss_hahen.c
 * Overlay: ovl_Effect_Ss_Hahen
 * Description: Fragments
 */

#include "z_eff_ss_hahen.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rPitch regs[0]
#define rYaw regs[1]
#define rUnused regs[2]
#define rScale regs[3]
#define rObjId regs[4]
#define rObjBankIdx regs[5]
#define rMinLife regs[6]

u32 EffectSsHahen_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsHahen_DrawGray(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsHahen_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsHahen_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Hahen_InitVars = {
    EFFECT_SS_HAHEN,
    EffectSsHahen_Init,
};

void EffectSsHahen_CheckForObject(EffectSs* pthis, GlobalContext* globalCtx) {
    if (((pthis->rObjBankIdx = Object_GetIndex(&globalCtx->objectCtx, pthis->rObjId)) < 0) ||
        !Object_IsLoaded(&globalCtx->objectCtx, pthis->rObjBankIdx)) {
        pthis->life = -1;
        pthis->draw = NULL;
    }
}

u32 EffectSsHahen_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsHahenInitParams* initParams = (EffectSsHahenInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = 200;

    if (initParams->dList != NULL) {
        pthis->gfx = initParams->dList;
        pthis->rObjId = initParams->objId;
        EffectSsHahen_CheckForObject(pthis, globalCtx);
    } else {
        pthis->gfx = SEGMENTED_TO_VIRTUAL(gEffFragments1DL);
        pthis->rObjId = -1;
    }

    if ((pthis->rObjId == OBJECT_HAKA_OBJECTS) && (pthis->gfx == gEffFragments2DL)) {
        pthis->draw = EffectSsHahen_DrawGray;
    } else {
        pthis->draw = EffectSsHahen_Draw;
    }

    pthis->update = EffectSsHahen_Update;
    pthis->rUnused = initParams->unused;
    pthis->rScale = initParams->scale;
    pthis->rPitch = Rand_ZeroOne() * 314.0f;
    pthis->rYaw = Rand_ZeroOne() * 314.0f;
    pthis->rMinLife = 200 - initParams->life;

    return 1;
}

void EffectSsHahen_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale = pthis->rScale * 0.001f;

    OPEN_DISPS(gfxCtx, "../z_eff_hahen.c", 208);

    if (pthis->rObjId != -1) {
        gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->rObjBankIdx].vromStart.get());
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_RotateY(pthis->rYaw * 0.01f, MTXMODE_APPLY);
    Matrix_RotateX(pthis->rPitch * 0.01f, MTXMODE_APPLY);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_hahen.c", 228),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_hahen.c", 236);
}

// in the original game pthis function is hardcoded to be used only by the skull pots in Shadow Temple
void EffectSsHahen_DrawGray(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale = pthis->rScale * 0.001f;

    OPEN_DISPS(gfxCtx, "../z_eff_hahen.c", 253);

    if (pthis->rObjId != -1) {
        gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->rObjBankIdx].vromStart.get());
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_RotateY(pthis->rYaw * 0.01f, MTXMODE_APPLY);
    Matrix_RotateX(pthis->rPitch * 0.01f, MTXMODE_APPLY);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_hahen.c", 271),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetCombineLERP(POLY_OPA_DISP++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0x0, 0x01, 100, 100, 120, 255);
    gSPDisplayList(POLY_OPA_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_hahen.c", 288);
}

void EffectSsHahen_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->rPitch += 55;
    pthis->rYaw += 10;

    if ((pthis->pos.y <= player->actor.floorHeight) && (pthis->life < pthis->rMinLife)) {
        pthis->life = 0;
    }

    if (pthis->rObjId != -1) {
        EffectSsHahen_CheckForObject(pthis, globalCtx);
    }
}

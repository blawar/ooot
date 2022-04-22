#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_ICE_SMOKE_Z_EFF_SS_ICE_SMOKE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_ice_smoke.c
 * Overlay: ovl_Effect_Ss_Ice_Smoke
 * Description: Ice Smoke
 */

#include "z_eff_ss_ice_smoke.h"
#include "objects/object_fz/object_fz.h"
#include "def/sys_matrix.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rObjBankIdx regs[0]
#define rAlpha regs[1]
#define rScale regs[2]

u32 EffectSsIceSmoke_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsIceSmoke_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsIceSmoke_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Ice_Smoke_InitVars = {
    EFFECT_SS_ICE_SMOKE,
    EffectSsIceSmoke_Init,
};

u32 EffectSsIceSmoke_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsIceSmokeInitParams* initParams = (EffectSsIceSmokeInitParams*)initParamsx;
    s32 pad;
    s32 objBankIdx;
    void* oldSeg6;

    objBankIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_FZ);

    if ((objBankIdx > -1) && Object_IsLoaded(&globalCtx->objectCtx, objBankIdx)) {
        oldSeg6 = (void*)gSegments[6];
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[objBankIdx].vromStart.get());
        Math_Vec3f_Copy(&pthis->pos, &initParams->pos);
        Math_Vec3f_Copy(&pthis->velocity, &initParams->velocity);
        Math_Vec3f_Copy(&pthis->accel, &initParams->accel);
        pthis->rObjBankIdx = objBankIdx;
        pthis->rAlpha = 0;
        pthis->rScale = initParams->scale;
        pthis->life = 50;
        pthis->draw = EffectSsIceSmoke_Draw;
        pthis->update = EffectSsIceSmoke_Update;
        gSegments[6] = (uintptr_t)oldSeg6;

        return 1;
    }

    osSyncPrintf("Effect_SS_Ice_Smoke_ct():バンク Object_Bank_Fzが有りません。\n");

    return 0;
}

void EffectSsIceSmoke_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad;
    void* object;
    Mtx* mtx;
    f32 scale;
    s32 objBankIdx;

    object = gObjectTable[pthis->rObjBankIdx].vromStart.buffer();

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_ice_smoke.c", 155);

    objBankIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_FZ);

    if ((objBankIdx > -1) && Object_IsLoaded(&globalCtx->objectCtx, objBankIdx)) {
        gDPPipeSync(POLY_XLU_DISP++);
        func_80093D84(globalCtx->state.gfxCtx);
        gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
        gSPSegment(POLY_XLU_DISP++, 0x06, object);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamStartDL));
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 235, 235, pthis->rAlpha);
        gSPSegment(
            POLY_XLU_DISP++, 0x08,
            Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->life * 3, pthis->life * 15, 32, 64, 1, 0, 0, 32, 32));
        Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);
        scale = pthis->rScale * 0.0001f;
        Matrix_Scale(scale, scale, 1.0f, MTXMODE_APPLY);

        mtx = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_ss_ice_smoke.c", 196);

        if (mtx != NULL) {
            gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamDL));
        }
    } else {
        pthis->life = -1;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_ice_smoke.c", 210);
}

void EffectSsIceSmoke_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 objBankIdx;

    objBankIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_FZ);

    if ((objBankIdx > -1) && Object_IsLoaded(&globalCtx->objectCtx, objBankIdx)) {
        if (pthis->rAlpha < 100) {
            pthis->rAlpha += 10;
        }
    } else {
        pthis->life = -1;
    }
}

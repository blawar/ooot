#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_EXTRA_Z_EFF_SS_EXTRA_C
#include "actor_common.h"
/*
 * File: z_eff_ss_extra.c
 * Overlay: ovl_Effect_Ss_Extra
 * Description: Minigame Score Points
 */

#include "z_eff_ss_extra.h"
#include "objects/object_yabusame_point/object_yabusame_point.h"
#include "def/sys_matrix.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rObjBankIdx regs[0]
#define rTimer regs[1]
#define rScoreIdx regs[2]
#define rScale regs[3]

u32 EffectSsExtra_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsExtra_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsExtra_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

static s16 sScores[] = { 30, 60, 100 };

EffectSsInit Effect_Ss_Extra_InitVars = {
    EFFECT_SS_EXTRA,
    EffectSsExtra_Init,
};

u32 EffectSsExtra_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsExtraInitParams* initParams = (EffectSsExtraInitParams*)initParamsx;
    s32 pad;
    s32 objBankIndex;
    u32 oldSeg6;

    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_YABUSAME_POINT);

    if ((objBankIndex >= 0) && Object_IsLoaded(&globalCtx->objectCtx, objBankIndex)) {
        oldSeg6 = gSegments[6];
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[objBankIndex].vromStart.get());
        pthis->pos = initParams->pos;
        pthis->velocity = initParams->velocity;
        pthis->accel = initParams->accel;
        pthis->draw = EffectSsExtra_Draw;
        pthis->update = EffectSsExtra_Update;
        pthis->life = 50;
        pthis->rScoreIdx = initParams->scoreIdx;
        pthis->rScale = initParams->scale;
        pthis->rTimer = 5;
        pthis->rObjBankIdx = objBankIndex;
        gSegments[6] = oldSeg6;

        return 1;
    }

    return 0;
}

static void* sTextures[] = {
    object_yabusame_point_Tex_000000,
    object_yabusame_point_Tex_000480,
    object_yabusame_point_Tex_000900,
};

void EffectSsExtra_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad;
    f32 scale = pthis->rScale / 100.0f;
    void* object = gObjectTable[pthis->rObjBankIdx].vromStart.buffer();

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_extra.c", 168);

    gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
    gSPSegment(POLY_XLU_DISP++, 0x06, object);
    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    func_80093D84(globalCtx->state.gfxCtx);
    func_800D1FD4(&globalCtx->billboardMtxF);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_eff_ss_extra.c", 186),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sTextures[pthis->rScoreIdx]));
    gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_yabusame_point_DL_000DC0));

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_eff_ss_extra.c", 194);
}

void EffectSsExtra_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    if (pthis->rTimer != 0) {
        pthis->rTimer -= 1;
    } else {
        pthis->velocity.y = 0.0f;
    }

    if (pthis->rTimer == 1) {
        globalCtx->interfaceCtx.unk_23C = sScores[pthis->rScoreIdx];
    }
}

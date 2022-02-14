#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_STICK_Z_EFF_SS_STICK_C
#include "actor_common.h"
extern Gfx gCullBackDList[];
/*
 * File: z_eff_ss_stick.c
 * Overlay: ovl_Effect_Ss_Stick
 * Description: Broken stick as child, broken sword as adult
 */

#include "z_eff_ss_stick.h"
#include "objects/object_link_boy/object_link_boy.h"
#include "objects/object_link_child/object_link_child.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rObjBankIdx regs[0]
#define rYaw regs[1]

u32 EffectSsStick_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsStick_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsStick_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Stick_InitVars = {
    EFFECT_SS_STICK,
    EffectSsStick_Init,
};

typedef struct {
    /* 0x00 */ s16 objectID;
    /* 0x04 */ Gfx* displayList;
} StickDrawInfo;

u32 EffectSsStick_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    StickDrawInfo drawInfo[] = {
        { OBJECT_LINK_BOY, gLinkAdultBrokenGiantsKnifeBladeDL },   // adult, broken sword
        { OBJECT_LINK_CHILD, gLinkChildLinkDekuStickDL }, // child, broken stick
    };
    StickDrawInfo* ageInfoEntry = gSaveContext.linkAge + drawInfo;
    EffectSsStickInitParams* initParams = (EffectSsStickInitParams*)initParamsx;

    pthis->rObjBankIdx = Object_GetIndex(&globalCtx->objectCtx, ageInfoEntry->objectID);
    pthis->gfx = ageInfoEntry->displayList;
    pthis->vec = pthis->pos = initParams->pos;
    pthis->rYaw = initParams->yaw;
    pthis->velocity.x = Math_SinS(initParams->yaw) * 6.0f;
    pthis->velocity.z = Math_CosS(initParams->yaw) * 6.0f;
    pthis->life = 20;
    pthis->draw = EffectSsStick_Draw;
    pthis->update = EffectSsStick_Update;
    pthis->velocity.y = 26.0f;
    pthis->accel.y = -4.0f;

    return 1;
}

void EffectSsStick_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_eff_ss_stick.c", 153);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);

    if (!LINK_IS_ADULT) {
        Matrix_Scale(0.01f, 0.0025f, 0.01f, MTXMODE_APPLY);
        Matrix_RotateZYX(0, pthis->rYaw, 0, MTXMODE_APPLY);
    } else {
        Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
        Matrix_RotateZYX(0, pthis->rYaw, (globalCtx->state.frames * 10000).whole(), MTXMODE_APPLY);
    }

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ss_stick.c", 176),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D18(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->rObjBankIdx].vromStart.get());
    gSPSegment(POLY_OPA_DISP++, 0x0C, gCullBackDList);
    gSPDisplayList(POLY_OPA_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_ss_stick.c", 188);
}

void EffectSsStick_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
}

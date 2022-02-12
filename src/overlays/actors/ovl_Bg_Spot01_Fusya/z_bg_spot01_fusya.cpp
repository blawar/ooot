#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT01_FUSYA_Z_BG_SPOT01_FUSYA_C
#include "actor_common.h"
/*
 * File: z_bg_spot01_fusya.c
 * Overlay: Bg_Spot01_Fusya
 * Description: Windmill Sails
 */

#include "z_bg_spot01_fusya.h"
#include "objects/object_spot01_objects/object_spot01_objects.h"
#include "def/code_800EC960.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgSpot01Fusya_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Fusya_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Fusya_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Fusya_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808AAA50(BgSpot01Fusya* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot01_Fusya_InitVars = {
    ACTOR_BG_SPOT01_FUSYA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT01_OBJECTS,
    sizeof(BgSpot01Fusya),
    (ActorFunc)BgSpot01Fusya_Init,
    (ActorFunc)BgSpot01Fusya_Destroy,
    (ActorFunc)BgSpot01Fusya_Update,
    (ActorFunc)BgSpot01Fusya_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 12800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1300, ICHAIN_STOP),
};

void BgSpot01Fusya_SetupAction(BgSpot01Fusya* pthis, BgSpot01FusyaActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgSpot01Fusya_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Fusya* pthis = (BgSpot01Fusya*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->unk_154 = 100.0f;
    pthis->unk_158 = 100.0f;
    pthis->unk_15C = 0.5f;
    if (gSaveContext.sceneSetupIndex < 4) {
        gSaveContext.eventChkInf[6] &= 0xFFDF;
    }
    BgSpot01Fusya_SetupAction(pthis, func_808AAA50);
}

void BgSpot01Fusya_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_808AAA50(BgSpot01Fusya* pthis, GlobalContext* globalCtx) {
    f32 temp;
    Actor* thisx = &pthis->actor;

    if (gSaveContext.eventChkInf[6] & 0x20) {
        pthis->unk_158 = 1800.0f;
    }
    thisx->shape.rot.z += pthis->unk_154;
    temp = ((pthis->unk_154 - 100.0f) / 1700.0f) + 1.0f;
    func_800F436C(&thisx->projectedPos, 0x2085, temp);
    Math_ApproachF(&pthis->unk_154, pthis->unk_158, pthis->unk_15C, 100.0f);
}

void BgSpot01Fusya_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Fusya* pthis = (BgSpot01Fusya*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot01Fusya_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_fusya.c", 210);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot01_fusya.c", 214),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gKakarikoWindmillSailsDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot01_fusya.c", 219);
}

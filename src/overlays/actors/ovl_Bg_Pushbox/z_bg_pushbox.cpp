#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_PUSHBOX_Z_BG_PUSHBOX_C
#include "actor_common.h"
/*
 * File: z_bg_pushbox.c
 * Overlay: ovl_Bg_Pushbox
 * Description: Unused (and non functional) pushable block
 */

#include "z_bg_pushbox.h"
#include "objects/object_pu_box/object_pu_box.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgPushbox_Init(Actor* thisx, GlobalContext* globalCtx);
void BgPushbox_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgPushbox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgPushbox_Update(Actor* thisx, GlobalContext* globalCtx);
void BgPushbox_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgPushbox_UpdateImpl(BgPushbox* pthis, GlobalContext* globalCtx);

ActorInit Bg_Pushbox_InitVars = {
    ACTOR_BG_PUSHBOX,
    ACTORCAT_BG,
    FLAGS,
    //! @bug fixing pthis actor would involve using OBJECT_PU_BOX
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(BgPushbox),
    (ActorFunc)BgPushbox_Init,
    (ActorFunc)BgPushbox_Destroy,
    (ActorFunc)BgPushbox_Update,
    (ActorFunc)BgPushbox_Draw,
    (ActorFunc)BgPushbox_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_STOP),
};

void BgPushbox_SetupAction(BgPushbox* pthis, BgPushboxActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgPushbox_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgPushbox* pthis = (BgPushbox*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gBlockSmallCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, NULL, 0.0f);
    BgPushbox_SetupAction(pthis, BgPushbox_UpdateImpl);
}

void BgPushbox_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgPushbox* pthis = (BgPushbox*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgPushbox_UpdateImpl(BgPushbox* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.speedXZ += pthis->dyna.unk_150 * 0.2f;
    pthis->dyna.actor.speedXZ = (pthis->dyna.actor.speedXZ < -1.0f)
                                   ? -1.0f
                                   : ((pthis->dyna.actor.speedXZ > 1.0f) ? 1.0f : pthis->dyna.actor.speedXZ);
    Math_StepToF(&pthis->dyna.actor.speedXZ, 0.0f, 0.2f);
    pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;
    Actor_MoveForward(&pthis->dyna.actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 20.0f, 40.0f, 40.0f, 0x1D);
}

void BgPushbox_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgPushbox* pthis = (BgPushbox*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    func_8002DF90(&pthis->dyna);
}

void BgPushbox_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_pushbox.c", 263);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_pushbox.c", 269),
              G_MTX_NOPUSH | G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, gBlockSmallDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_pushbox.c", 272);
}

void BgPushbox_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Pushbox_InitVars = {
        ACTOR_BG_PUSHBOX,
        ACTORCAT_BG,
        FLAGS,
        //! @bug fixing pthis actor would involve using OBJECT_PU_BOX
        OBJECT_GAMEPLAY_DANGEON_KEEP,
        sizeof(BgPushbox),
        (ActorFunc)BgPushbox_Init,
        (ActorFunc)BgPushbox_Destroy,
        (ActorFunc)BgPushbox_Update,
        (ActorFunc)BgPushbox_Draw,
        (ActorFunc)BgPushbox_Reset,
    };

}

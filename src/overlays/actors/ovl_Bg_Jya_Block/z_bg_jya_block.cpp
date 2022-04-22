#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_BLOCK_Z_BG_JYA_BLOCK_C
#include "actor_common.h"
/*
 * File: z_bg_jya_block.c
 * Overlay: ovl_Bg_Jya_Block
 * Description: Silver Block (Child Link)
 */

#include "z_bg_jya_block.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgJyaBlock_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBlock_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaBlock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBlock_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBlock_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Jya_Block_InitVars = {
    ACTOR_BG_JYA_BLOCK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(BgJyaBlock),
    (ActorFunc)BgJyaBlock_Init,
    (ActorFunc)BgJyaBlock_Destroy,
    (ActorFunc)BgJyaBlock_Update,
    (ActorFunc)BgJyaBlock_Draw,
    (ActorFunc)BgJyaBlock_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 333, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1500, ICHAIN_STOP),
};

void BgJyaBlock_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgJyaBlock* pthis = (BgJyaBlock*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, 0);
    CollisionHeader_GetVirtual(&gPushBlockCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    if ((LINK_AGE_IN_YEARS != YEARS_CHILD) || !Flags_GetSwitch(globalCtx, thisx->params & 0x3F)) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgJyaBlock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBlock* pthis = (BgJyaBlock*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgJyaBlock_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBlock* pthis = (BgJyaBlock*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    player->stateFlags2 &= ~0x10;
    pthis->dyna.unk_150 = 0.0f;
}

void BgJyaBlock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_jya_block.c", 145);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gPushBlockGrayTex));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_jya_block.c", 153),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetEnvColor(POLY_OPA_DISP++, 232, 210, 176, 255);
    gSPDisplayList(POLY_OPA_DISP++, gPushBlockDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_jya_block.c", 158);
}

void BgJyaBlock_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Jya_Block_InitVars = {
        ACTOR_BG_JYA_BLOCK,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_DANGEON_KEEP,
        sizeof(BgJyaBlock),
        (ActorFunc)BgJyaBlock_Init,
        (ActorFunc)BgJyaBlock_Destroy,
        (ActorFunc)BgJyaBlock_Update,
        (ActorFunc)BgJyaBlock_Draw,
        (ActorFunc)BgJyaBlock_Reset,
    };

}

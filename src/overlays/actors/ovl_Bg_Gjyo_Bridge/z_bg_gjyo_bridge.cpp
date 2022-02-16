#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GJYO_BRIDGE_Z_BG_GJYO_BRIDGE_C
#include "actor_common.h"
/*
 * File: z_bg_gjyo_bridge.c
 * Overlay: ovl_Bg_Gjyo_Bridge
 * Description: Rainbow Bridge outside Ganon's Castle
 */

#include "z_bg_gjyo_bridge.h"
#include "objects/object_gjyo_objects/object_gjyo_objects.h"
#include "scenes/dungeons/ganon_tou/ganon_tou_scene.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgGjyoBridge_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgGjyoBridge_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgGjyoBridge_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgGjyoBridge_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgGjyoBridge_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_808787A4(BgGjyoBridge* pthis, GlobalContext* globalCtx);
void BgGjyoBridge_TriggerCutscene(BgGjyoBridge* pthis, GlobalContext* globalCtx);
void BgGjyoBridge_SpawnBridge(BgGjyoBridge* pthis, GlobalContext* globalCtx);

ActorInit Bg_Gjyo_Bridge_InitVars = {
    ACTOR_BG_GJYO_BRIDGE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GJYO_OBJECTS,
    sizeof(BgGjyoBridge),
    (ActorFunc)BgGjyoBridge_Init,
    (ActorFunc)BgGjyoBridge_Destroy,
    (ActorFunc)BgGjyoBridge_Update,
    (ActorFunc)BgGjyoBridge_Draw,
    (ActorFunc)BgGjyoBridge_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 800, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgGjyoBridge_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgGjyoBridge* pthis = (BgGjyoBridge*)pthisx;
    s32 pad;
    CollisionHeader* colHeader;

    colHeader = NULL;

    Actor_ProcessInitChain(pthisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gRainbowBridgeCol, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);

    if (gSaveContext.eventChkInf[4] & 0x2000) {
        pthis->actionFunc = func_808787A4;
    } else {
        pthis->dyna.actor.draw = NULL;
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->actionFunc = BgGjyoBridge_TriggerCutscene;
    }
}

void BgGjyoBridge_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgGjyoBridge* pthis = (BgGjyoBridge*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808787A4(BgGjyoBridge* pthis, GlobalContext* globalCtx) {
}

void BgGjyoBridge_TriggerCutscene(BgGjyoBridge* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT) && CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW) &&
        (INV_CONTENT(ITEM_ARROW_LIGHT) == ITEM_ARROW_LIGHT) && (player->actor.world.pos.x > -70.0f) &&
        (player->actor.world.pos.x < 300.0f) && (player->actor.world.pos.y > 1340.0f) &&
        (player->actor.world.pos.z > 1340.0f) && (player->actor.world.pos.z < 1662.0f) &&
        !Gameplay_InCsMode(globalCtx)) {
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gRainbowBridgeCs);
        gSaveContext.cutsceneTrigger = 1;
        pthis->actionFunc = BgGjyoBridge_SpawnBridge;
    }
}

void BgGjyoBridge_SpawnBridge(BgGjyoBridge* pthis, GlobalContext* globalCtx) {
    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[2] != NULL) &&
        (globalCtx->csCtx.npcActions[2]->action == 2)) {
        pthis->dyna.actor.draw = BgGjyoBridge_Draw;
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        gSaveContext.eventChkInf[4] |= 0x2000;
    }
}

void BgGjyoBridge_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgGjyoBridge* pthis = (BgGjyoBridge*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgGjyoBridge_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgGjyoBridge* pthis = (BgGjyoBridge*)pthisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_gjyo_bridge.c", 260);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 8,
               Gfx_TexScroll(globalCtx->state.gfxCtx, globalCtx->gameplayFrames & 127,
                             globalCtx->gameplayFrames * -3 & 127, 32, 32));

    gSPSegment(POLY_XLU_DISP++, 9,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, -globalCtx->gameplayFrames & 127, 32, 32, 1, 0,
                                globalCtx->gameplayFrames & 127, 32, 32));

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_gjyo_bridge.c", 281),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_XLU_DISP++, gRainbowBridgeDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_gjyo_bridge.c", 285);
}

void BgGjyoBridge_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Gjyo_Bridge_InitVars = {
        ACTOR_BG_GJYO_BRIDGE,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GJYO_OBJECTS,
        sizeof(BgGjyoBridge),
        (ActorFunc)BgGjyoBridge_Init,
        (ActorFunc)BgGjyoBridge_Destroy,
        (ActorFunc)BgGjyoBridge_Update,
        (ActorFunc)BgGjyoBridge_Draw,
        (ActorFunc)BgGjyoBridge_Reset,
    };

}

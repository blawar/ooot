#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_HASHIRA4_Z_BG_MORI_HASHIRA4_C
#include "actor_common.h"
/*
 * File: z_bg_mori_hashira4
 * Overlay: ovl_Bg_Mori_Hashira4
 * Description: Forest Temple gates and rotating pillars
 */

#include "z_bg_mori_hashira4.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void BgMoriHashira4_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashira4_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashira4_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashira4_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriHashira4_SetupWaitForMoriTex(BgMoriHashira4* pthis);
void BgMoriHashira4_WaitForMoriTex(BgMoriHashira4* pthis, GlobalContext* globalCtx);
void BgMoriHashira4_SetupPillarsRotate(BgMoriHashira4* pthis);
void BgMoriHashira4_PillarsRotate(BgMoriHashira4* pthis, GlobalContext* globalCtx);
void BgMoriHashira4_GateWait(BgMoriHashira4* pthis, GlobalContext* globalCtx);
void BgMoriHashira4_GateOpen(BgMoriHashira4* pthis, GlobalContext* globalCtx);

ActorInit Bg_Mori_Hashira4_InitVars = {
    ACTOR_BG_MORI_HASHIRA4,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriHashira4),
    (ActorFunc)BgMoriHashira4_Init,
    (ActorFunc)BgMoriHashira4_Destroy,
    (ActorFunc)BgMoriHashira4_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 700, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

static Gfx* sDisplayLists[] = { gMoriHashiraPlatformsDL, gMoriHashiraGateDL };

static s16 sUnkTimer; // seems to be unused

void BgMoriHashira4_SetupAction(BgMoriHashira4* pthis, BgMoriHashira4ActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgMoriHashira4_InitDynaPoly(BgMoriHashira4* pthis, GlobalContext* globalCtx, CollisionHeader* collision,
                                 s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader;
    s32 pad2;

    colHeader = NULL;
    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG login failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_mori_hashira4.c", 155,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgMoriHashira4_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashira4* pthis = (BgMoriHashira4*)thisx;

    pthis->switchFlag = (pthis->dyna.actor.params >> 8) & 0x3F;
    pthis->dyna.actor.params &= 0xFF;

    if (pthis->dyna.actor.params == 0) {
        BgMoriHashira4_InitDynaPoly(pthis, globalCtx, &gMoriHashira1Col, DPM_UNK3);
    } else {
        BgMoriHashira4_InitDynaPoly(pthis, globalCtx, &gMoriHashira2Col, DPM_UNK);
    }
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        Actor_Kill(&pthis->dyna.actor);
        // "Bank danger!"
        osSyncPrintf("Error : バンク危険！(arg_data 0x%04x)(%s %d)\n", pthis->dyna.actor.params,
                     "../z_bg_mori_hashira4.c", 196);
        return;
    }
    if ((pthis->dyna.actor.params != 0) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    Actor_SetFocus(&pthis->dyna.actor, 50.0f);
    BgMoriHashira4_SetupWaitForMoriTex(pthis);
    // "(4 pillars of the Forest Temple) Bank danger"
    osSyncPrintf("(森の神殿 ４本柱)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
    sUnkTimer = 0;
}

void BgMoriHashira4_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashira4* pthis = (BgMoriHashira4*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgMoriHashira4_SetupWaitForMoriTex(BgMoriHashira4* pthis) {
    BgMoriHashira4_SetupAction(pthis, BgMoriHashira4_WaitForMoriTex);
}

void BgMoriHashira4_WaitForMoriTex(BgMoriHashira4* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        pthis->gateTimer = 0;
        if (pthis->dyna.actor.params == 0) {
            BgMoriHashira4_SetupPillarsRotate(pthis);
        } else {
            BgMoriHashira4_SetupAction(pthis, BgMoriHashira4_GateWait);
        }
        pthis->dyna.actor.draw = BgMoriHashira4_Draw;
    }
}

void BgMoriHashira4_SetupPillarsRotate(BgMoriHashira4* pthis) {
    BgMoriHashira4_SetupAction(pthis, BgMoriHashira4_PillarsRotate);
}

void BgMoriHashira4_PillarsRotate(BgMoriHashira4* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.world.rot.y += 0x96;
    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ROLL_STAND_2 - SFX_FLAG);
}

void BgMoriHashira4_GateWait(BgMoriHashira4* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag) || (pthis->gateTimer != 0)) {
        pthis->gateTimer++;
        if (pthis->gateTimer > 30) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_OPEN);
            BgMoriHashira4_SetupAction(pthis, BgMoriHashira4_GateOpen);
            OnePointCutscene_Init(globalCtx, 6010, 20, &pthis->dyna.actor, MAIN_CAM);
            sUnkTimer++;
        }
    }
}

void BgMoriHashira4_GateOpen(BgMoriHashira4* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 120.0f, 10.0f)) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgMoriHashira4_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashira4* pthis = (BgMoriHashira4*)thisx;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgMoriHashira4_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashira4* pthis = (BgMoriHashira4*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_hashira4.c", 339);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hashira4.c", 344),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[pthis->dyna.actor.params]);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_hashira4.c", 348);
}

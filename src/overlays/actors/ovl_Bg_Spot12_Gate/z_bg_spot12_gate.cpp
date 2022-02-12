#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT12_GATE_Z_BG_SPOT12_GATE_C
#include "actor_common.h"
/*
 * File: z_bg_spot12_gate.c
 * Overlay: ovl_Bg_Spot12_Gate
 * Description: Haunted Wasteland Gate
 */

#include "z_bg_spot12_gate.h"
#include "objects/object_spot12_obj/object_spot12_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_quake.h"

#define FLAGS 0

void BgSpot12Gate_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B30C0(BgSpot12Gate* pthis);
void func_808B30D8(BgSpot12Gate* pthis, GlobalContext* globalCtx);
void func_808B3134(BgSpot12Gate* pthis);
void func_808B314C(BgSpot12Gate* pthis, GlobalContext* globalCtx);
void func_808B317C(BgSpot12Gate* pthis);
void func_808B318C(BgSpot12Gate* pthis, GlobalContext* globalCtx);
void func_808B3274(BgSpot12Gate* pthis);
void func_808B3298(BgSpot12Gate* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot12_Gate_InitVars = {
    ACTOR_BG_SPOT12_GATE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT12_OBJ,
    sizeof(BgSpot12Gate),
    (ActorFunc)BgSpot12Gate_Init,
    (ActorFunc)BgSpot12Gate_Destroy,
    (ActorFunc)BgSpot12Gate_Update,
    (ActorFunc)BgSpot12Gate_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_STOP),
};

void BgSpot12Gate_InitDynaPoly(BgSpot12Gate* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot12_gate.c", 145,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgSpot12Gate_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* pthis = (BgSpot12Gate*)thisx;

    BgSpot12Gate_InitDynaPoly(pthis, globalCtx, &gGerudoFortressWastelandGateCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_808B3274(pthis);
    } else {
        func_808B30C0(pthis);
    }
}

void BgSpot12Gate_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* pthis = (BgSpot12Gate*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808B30C0(BgSpot12Gate* pthis) {
    pthis->actionFunc = func_808B30D8;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
}

void func_808B30D8(BgSpot12Gate* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_808B3134(pthis);
        OnePointCutscene_Init(globalCtx, 4160, -99, &pthis->dyna.actor, MAIN_CAM);
    }
}

void func_808B3134(BgSpot12Gate* pthis) {
    pthis->actionFunc = func_808B314C;
    pthis->unk_168 = 40;
}

void func_808B314C(BgSpot12Gate* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_168 <= 0) {
        func_808B317C(pthis);
    }
}

void func_808B317C(BgSpot12Gate* pthis) {
    pthis->actionFunc = func_808B318C;
}

void func_808B318C(BgSpot12Gate* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 var;

    Math_StepToF(&pthis->dyna.actor.velocity.y, 1.6f, 0.03f);
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 200.0f,
                     pthis->dyna.actor.velocity.y)) {
        func_808B3274(pthis);
        var = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
        Quake_SetSpeed(var, -0x3CB0);
        Quake_SetQuakeValues(var, 3, 0, 0, 0);
        Quake_SetCountdown(var, 0xC);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BRIDGE_OPEN_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
    }
}

void func_808B3274(BgSpot12Gate* pthis) {
    pthis->actionFunc = func_808B3298;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + 200.0f;
}

void func_808B3298(BgSpot12Gate* pthis, GlobalContext* globalCtx) {
}

void BgSpot12Gate_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* pthis = (BgSpot12Gate*)thisx;

    if (pthis->unk_168 > 0) {
        pthis->unk_168--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot12Gate_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gGerudoFortressWastelandGateDL);
}

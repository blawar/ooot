#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT12_SAKU_Z_BG_SPOT12_SAKU_C
#include "actor_common.h"
/*
 * File: z_bg_spot12_saku.c
 * Overlay: ovl_Bg_Spot12_Saku
 * Description:
 */

#include "z_bg_spot12_saku.h"
#include "objects/object_spot12_obj/object_spot12_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS 0

void BgSpot12Saku_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Saku_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot12Saku_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Saku_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Saku_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B3550(BgSpot12Saku* pthis);
void func_808B357C(BgSpot12Saku* pthis, GlobalContext* globalCtx);
void func_808B35E4(BgSpot12Saku* pthis);
void func_808B3604(BgSpot12Saku* pthis, GlobalContext* globalCtx);
void func_808B3714(BgSpot12Saku* pthis);
void func_808B37AC(BgSpot12Saku* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot12_Saku_InitVars = {
    ACTOR_BG_SPOT12_SAKU,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT12_OBJ,
    sizeof(BgSpot12Saku),
    (ActorFunc)BgSpot12Saku_Init,
    (ActorFunc)BgSpot12Saku_Destroy,
    (ActorFunc)BgSpot12Saku_Update,
    (ActorFunc)BgSpot12Saku_Draw,
    (ActorFunc)BgSpot12Saku_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void func_808B3420(BgSpot12Saku* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot12_saku.c", 140,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgSpot12Saku_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Saku* pthis = (BgSpot12Saku*)thisx;

    func_808B3420(pthis, globalCtx, &gGerudoFortressGTGShutterCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_808B3714(pthis);
    } else {
        func_808B3550(pthis);
    }
}

void BgSpot12Saku_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Saku* pthis = (BgSpot12Saku*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808B3550(BgSpot12Saku* pthis) {
    pthis->actionFunc = func_808B357C;
    pthis->dyna.actor.scale.x = 0.1f;
    pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z;
}

void func_808B357C(BgSpot12Saku* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_808B35E4(pthis);
        pthis->timer = 20;
        OnePointCutscene_Init(globalCtx, 4170, -99, &pthis->dyna.actor, MAIN_CAM);
    }
}

void func_808B35E4(BgSpot12Saku* pthis) {
    if (pthis->timer == 0) {
        pthis->actionFunc = func_808B3604;
    }
}

void func_808B3604(BgSpot12Saku* pthis, GlobalContext* globalCtx) {
    f32 temp_ret = Math_SmoothStepToF(&pthis->dyna.actor.scale.x, 0.001f / 0.14f, 0.16f, 0.0022f, 0.001f);
    f32 temp_f18 = ((0.1f - pthis->dyna.actor.scale.x) * 840.0f);

    pthis->dyna.actor.world.pos.x =
        pthis->dyna.actor.home.pos.x - (Math_SinS(pthis->dyna.actor.shape.rot.y + 0x4000) * temp_f18);
    pthis->dyna.actor.world.pos.z =
        pthis->dyna.actor.home.pos.z - (Math_CosS(pthis->dyna.actor.shape.rot.y + 0x4000) * temp_f18);
    if (fabsf(temp_ret) < 0.0001f) {
        func_808B3714(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BRIDGE_OPEN_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
    }
}

void func_808B3714(BgSpot12Saku* pthis) {
    pthis->actionFunc = func_808B37AC;
    pthis->dyna.actor.scale.x = 0.001f / 0.14f;
    pthis->dyna.actor.world.pos.x =
        pthis->dyna.actor.home.pos.x - (Math_SinS(pthis->dyna.actor.shape.rot.y + 0x4000) * 78.0f);
    pthis->dyna.actor.world.pos.z =
        pthis->dyna.actor.home.pos.z - (Math_CosS(pthis->dyna.actor.shape.rot.y + 0x4000) * 78.0f);
}

void func_808B37AC(BgSpot12Saku* pthis, GlobalContext* globalCtx) {
}

void BgSpot12Saku_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Saku* pthis = (BgSpot12Saku*)thisx;

    if (pthis->timer > 0) {
        pthis->timer--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot12Saku_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gGerudoFortressGTGShutterDL);
}

void BgSpot12Saku_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot12_Saku_InitVars = {
        ACTOR_BG_SPOT12_SAKU,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SPOT12_OBJ,
        sizeof(BgSpot12Saku),
        (ActorFunc)BgSpot12Saku_Init,
        (ActorFunc)BgSpot12Saku_Destroy,
        (ActorFunc)BgSpot12Saku_Update,
        (ActorFunc)BgSpot12Saku_Draw,
        (ActorFunc)BgSpot12Saku_Reset,
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_AMISHUTTER_Z_BG_JYA_AMISHUTTER_C
#include "actor_common.h"
/*
 * File: z_bg_jya_amishutter.c
 * Overlay: Bg_Jya_Amishutter
 * Description: Circular metal grate. Lifts up when you get close to it.
 */

#include "z_bg_jya_amishutter.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS 0

void BgJyaAmishutter_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaAmishutter_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaAmishutter_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaAmishutter_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJyaAmishutter_SetupWaitForPlayer(BgJyaAmishutter* pthis);
void BgJyaAmishutter_WaitForPlayer(BgJyaAmishutter* pthis);
void func_80893428(BgJyaAmishutter* pthis);
void func_80893438(BgJyaAmishutter* pthis);
void func_808934B0(BgJyaAmishutter* pthis);
void func_808934C0(BgJyaAmishutter* pthis);
void func_808934FC(BgJyaAmishutter* pthis);
void func_8089350C(BgJyaAmishutter* pthis);

ActorInit Bg_Jya_Amishutter_InitVars = {
    ACTOR_BG_JYA_AMISHUTTER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaAmishutter),
    (ActorFunc)BgJyaAmishutter_Init,
    (ActorFunc)BgJyaAmishutter_Destroy,
    (ActorFunc)BgJyaAmishutter_Update,
    (ActorFunc)BgJyaAmishutter_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgJyaAmishutter_InitDynaPoly(BgJyaAmishutter* pthis, GlobalContext* globalCtx, CollisionHeader* collision,
                                  s32 flag) {
    s32 pad1;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_jya_amishutter.c", 129,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgJyaAmishutter_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaAmishutter* pthis = (BgJyaAmishutter*)thisx;

    BgJyaAmishutter_InitDynaPoly(pthis, globalCtx, &gAmishutterCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    BgJyaAmishutter_SetupWaitForPlayer(pthis);
}

void BgJyaAmishutter_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaAmishutter* pthis = (BgJyaAmishutter*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgJyaAmishutter_SetupWaitForPlayer(BgJyaAmishutter* pthis) {
    pthis->actionFunc = BgJyaAmishutter_WaitForPlayer;
}

void BgJyaAmishutter_WaitForPlayer(BgJyaAmishutter* pthis) {
    if ((pthis->dyna.actor.xzDistToPlayer < 60.0f) && (fabsf(pthis->dyna.actor.yDistToPlayer) < 30.0f)) {
        func_80893428(pthis);
    }
}

void func_80893428(BgJyaAmishutter* pthis) {
    pthis->actionFunc = func_80893438;
}

void func_80893438(BgJyaAmishutter* pthis) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 100.0f, 3.0f)) {
        func_808934B0(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
    }
}

void func_808934B0(BgJyaAmishutter* pthis) {
    pthis->actionFunc = func_808934C0;
}

void func_808934C0(BgJyaAmishutter* pthis) {
    if (pthis->dyna.actor.xzDistToPlayer > 300.0f) {
        func_808934FC(pthis);
    }
}

void func_808934FC(BgJyaAmishutter* pthis) {
    pthis->actionFunc = func_8089350C;
}

void func_8089350C(BgJyaAmishutter* pthis) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 3.0f)) {
        BgJyaAmishutter_SetupWaitForPlayer(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
    }
}

void BgJyaAmishutter_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaAmishutter* pthis = (BgJyaAmishutter*)thisx;

    pthis->actionFunc(pthis);
}

void BgJyaAmishutter_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gAmishutterDL);
}

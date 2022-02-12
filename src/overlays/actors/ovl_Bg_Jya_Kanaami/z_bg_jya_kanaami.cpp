#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_KANAAMI_Z_BG_JYA_KANAAMI_C
#include "actor_common.h"
/*
 * File: z_bg_jya_kanaami.c
 * Overlay: ovl_Bg_Jya_Kanaami
 * Description: Climbable grating/bridge (Spirit Temple)
 */

#include "z_bg_jya_kanaami.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_quake.h"

#define FLAGS 0

void BgJyaKanaami_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaKanaami_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaKanaami_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaKanaami_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80899880(BgJyaKanaami* pthis);
void func_80899894(BgJyaKanaami* pthis, GlobalContext* globalCtx);
void func_8089993C(BgJyaKanaami* pthis);
void func_80899950(BgJyaKanaami* pthis, GlobalContext* globalCtx);
void func_80899A08(BgJyaKanaami* pthis);

ActorInit Bg_Jya_Kanaami_InitVars = {
    ACTOR_BG_JYA_KANAAMI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaKanaami),
    (ActorFunc)BgJyaKanaami_Init,
    (ActorFunc)BgJyaKanaami_Destroy,
    (ActorFunc)BgJyaKanaami_Update,
    (ActorFunc)BgJyaKanaami_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 700, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgJyaKanaami_InitDynaPoly(BgJyaKanaami* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flag) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_jya_kanaami.c", 145,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgJyaKanaami_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaKanaami* pthis = (BgJyaKanaami*)thisx;

    BgJyaKanaami_InitDynaPoly(pthis, globalCtx, &gKanaamiCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        func_80899A08(pthis);
    } else {
        func_80899880(pthis);
    }
    osSyncPrintf("(jya 金網)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void BgJyaKanaami_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaKanaami* pthis = (BgJyaKanaami*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80899880(BgJyaKanaami* pthis) {
    pthis->actionFunc = func_80899894;
    pthis->unk_16A = 0;
}

void func_80899894(BgJyaKanaami* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F) || pthis->unk_16A > 0) {
        if (pthis->dyna.actor.world.pos.x > -1000.0f && pthis->unk_16A == 0) {
            OnePointCutscene_Init(globalCtx, 3450, -99, &pthis->dyna.actor, MAIN_CAM);
        }
        pthis->unk_16A += 1;
        if (pthis->unk_16A >= 0xA) {
            func_8089993C(pthis);
        }
    }
}

void func_8089993C(BgJyaKanaami* pthis) {
    pthis->actionFunc = func_80899950;
    pthis->unk_168 = 0;
}

void func_80899950(BgJyaKanaami* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s32 quakeId;

    pthis->unk_168 += 0x20;
    if (Math_ScaledStepToS(&pthis->dyna.actor.world.rot.x, 0x4000, pthis->unk_168)) {
        func_80899A08(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_TRAP_BOUND);
        quakeId = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
        Quake_SetSpeed(quakeId, 25000);
        Quake_SetQuakeValues(quakeId, 2, 0, 0, 0);
        Quake_SetCountdown(quakeId, 16);
    }
}

void func_80899A08(BgJyaKanaami* pthis) {
    pthis->actionFunc = 0;
    pthis->dyna.actor.world.rot.x = 0x4000;
}

void BgJyaKanaami_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaKanaami* pthis = (BgJyaKanaami*)thisx;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
    pthis->dyna.actor.shape.rot.x = pthis->dyna.actor.world.rot.x;
}

void BgJyaKanaami_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gKanaamiDL);
}

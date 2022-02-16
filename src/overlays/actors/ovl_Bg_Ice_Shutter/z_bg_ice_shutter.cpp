#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_ICE_SHUTTER_Z_BG_ICE_SHUTTER_C
#include "actor_common.h"
/*
 * File: z_bg_ice_shutter.c
 * Overlay: ovl_Bg_Ice_Shutter
 * Description: Vertical Ice Bars (Doors) in Ice Cavern
 */

#include "z_bg_ice_shutter.h"
#include "objects/object_ice_objects/object_ice_objects.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS ACTOR_FLAG_4

void BgIceShutter_Init(Actor* thisx, GlobalContext* globalCtx);
void BgIceShutter_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgIceShutter_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgIceShutter_Update(Actor* thisx, GlobalContext* globalCtx);
void BgIceShutter_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80891CF4(BgIceShutter* thisx, GlobalContext* globalCtx);
void func_80891D6C(BgIceShutter* thisx, GlobalContext* globalCtx);
void func_80891DD4(BgIceShutter* thisx, GlobalContext* globalCtx);

ActorInit Bg_Ice_Shutter_InitVars = {
    ACTOR_BG_ICE_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_ICE_OBJECTS,
    sizeof(BgIceShutter),
    (ActorFunc)BgIceShutter_Init,
    (ActorFunc)BgIceShutter_Destroy,
    (ActorFunc)BgIceShutter_Update,
    (ActorFunc)BgIceShutter_Draw,
    (ActorFunc)BgIceShutter_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void func_80891AC0(BgIceShutter* pthis) {
    f32 sp24;

    sp24 = Math_SinS(pthis->dyna.actor.shape.rot.x) * pthis->dyna.actor.velocity.y;
    pthis->dyna.actor.world.pos.y =
        (Math_CosS(pthis->dyna.actor.shape.rot.x) * pthis->dyna.actor.velocity.y) + pthis->dyna.actor.home.pos.y;
    pthis->dyna.actor.world.pos.x = (Math_SinS(pthis->dyna.actor.shape.rot.y) * sp24) + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = (Math_CosS(pthis->dyna.actor.shape.rot.y) * sp24) + pthis->dyna.actor.home.pos.z;
}

void BgIceShutter_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgIceShutter* pthis = (BgIceShutter*)thisx;
    f32 sp24;
    CollisionHeader* colHeader;
    s32 sp28;
    f32 temp_f6;

    colHeader = NULL;
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    sp28 = pthis->dyna.actor.params & 0xFF;
    pthis->dyna.actor.params = (pthis->dyna.actor.params >> 8) & 0xFF;
    CollisionHeader_GetVirtual(&object_ice_objects_Col_002854, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    if (sp28 == 2) {
        pthis->dyna.actor.shape.rot.x = -0x4000;
    }

    if (sp28 != 1) {
        if (Flags_GetClear(globalCtx, pthis->dyna.actor.room)) {
            Actor_Kill(&pthis->dyna.actor);
        } else {
            pthis->actionFunc = func_80891CF4;
        }

    } else {
        if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
            Actor_Kill(&pthis->dyna.actor);
        } else {
            pthis->actionFunc = func_80891D6C;
        }
    }

    if (sp28 == 2) {
        temp_f6 = Math_SinS(pthis->dyna.actor.shape.rot.x) * 50.0f;
        pthis->dyna.actor.focus.pos.x =
            (Math_SinS(pthis->dyna.actor.shape.rot.y) * temp_f6) + pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.focus.pos.y = pthis->dyna.actor.home.pos.y;
        pthis->dyna.actor.focus.pos.z =
            pthis->dyna.actor.home.pos.z + (Math_CosS(pthis->dyna.actor.shape.rot.y) * temp_f6);
    } else {
        Actor_SetFocus(&pthis->dyna.actor, 50.0f);
    }
}

void BgIceShutter_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgIceShutter* pthis = (BgIceShutter*)thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80891CF4(BgIceShutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetTempClear(globalCtx, pthis->dyna.actor.room)) {
        Flags_SetClear(globalCtx, pthis->dyna.actor.room);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 30, NA_SE_EV_SLIDE_DOOR_OPEN);
        pthis->actionFunc = func_80891DD4;
        if (pthis->dyna.actor.shape.rot.x == 0) {
            OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        }
    }
}

void func_80891D6C(BgIceShutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 30, NA_SE_EV_SLIDE_DOOR_OPEN);
        pthis->actionFunc = func_80891DD4;
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
    }
}

void func_80891DD4(BgIceShutter* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->dyna.actor.speedXZ, 30.0f, 2.0f);
    if (Math_StepToF(&pthis->dyna.actor.velocity.y, 210.0f, pthis->dyna.actor.speedXZ)) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }

    func_80891AC0(pthis);
}

void BgIceShutter_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgIceShutter* pthis = (BgIceShutter*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgIceShutter_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, object_ice_objects_DL_002740);
}

void BgIceShutter_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Ice_Shutter_InitVars = {
        ACTOR_BG_ICE_SHUTTER,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_ICE_OBJECTS,
        sizeof(BgIceShutter),
        (ActorFunc)BgIceShutter_Init,
        (ActorFunc)BgIceShutter_Destroy,
        (ActorFunc)BgIceShutter_Update,
        (ActorFunc)BgIceShutter_Draw,
        (ActorFunc)BgIceShutter_Reset,
    };

}

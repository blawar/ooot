#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT18_SHUTTER_Z_BG_SPOT18_SHUTTER_C
#include "actor_common.h"
/*
 * File: z_bg_spot18_shutter.c
 * Overlay: Bg_Spot18_Shutter
 * Description:
 */

#include "z_bg_spot18_shutter.h"
#include "objects/object_spot18_obj/object_spot18_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSpot18Shutter_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Shutter_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Shutter_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Shutter_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B95AC(BgSpot18Shutter* pthis, GlobalContext* globalCtx);
void func_808B95B8(BgSpot18Shutter* pthis, GlobalContext* globalCtx);
void func_808B9618(BgSpot18Shutter* pthis, GlobalContext* globalCtx);
void func_808B9698(BgSpot18Shutter* pthis, GlobalContext* globalCtx);
void func_808B971C(BgSpot18Shutter* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot18_Shutter_InitVars = {
    ACTOR_BG_SPOT18_SHUTTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Shutter),
    (ActorFunc)BgSpot18Shutter_Init,
    (ActorFunc)BgSpot18Shutter_Destroy,
    (ActorFunc)BgSpot18Shutter_Update,
    (ActorFunc)BgSpot18Shutter_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot18Shutter_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot18Shutter* pthis = (BgSpot18Shutter*)thisx;
    s32 param = (pthis->dyna.actor.params >> 8) & 1;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    if (param == 0) {
        if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
            if (gSaveContext.infTable[16] & 0x200) {
                pthis->actionFunc = func_808B95AC;
                pthis->dyna.actor.world.pos.y += 180.0f;
            } else {
                pthis->actionFunc = func_808B9618;
            }
        } else {
            if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
                pthis->actionFunc = func_808B95AC;
                pthis->dyna.actor.world.pos.y += 180.0f;
            } else {
                pthis->actionFunc = func_808B95B8;
            }
        }
    } else {
        if (gSaveContext.infTable[16] & 0x200) {
            pthis->dyna.actor.world.pos.x += 125.0f * Math_CosS(pthis->dyna.actor.world.rot.y);
            pthis->dyna.actor.world.pos.z -= 125.0f * Math_SinS(pthis->dyna.actor.world.rot.y);
            pthis->actionFunc = func_808B95AC;
        } else {
            pthis->actionFunc = func_808B9618;
        }
    }

    CollisionHeader_GetVirtual(&gGoronCityDoorCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void BgSpot18Shutter_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Shutter* pthis = (BgSpot18Shutter*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808B95AC(BgSpot18Shutter* pthis, GlobalContext* globalCtx) {
}

void func_808B95B8(BgSpot18Shutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        Actor_SetFocus(&pthis->dyna.actor, 70.0f);
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        pthis->actionFunc = func_808B9698;
    }
}

void func_808B9618(BgSpot18Shutter* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.infTable[16] & 0x200) {
        Actor_SetFocus(&pthis->dyna.actor, 70.0f);
        if (((pthis->dyna.actor.params >> 8) & 1) == 0) {
            pthis->actionFunc = func_808B9698;
        } else {
            pthis->actionFunc = func_808B971C;
            OnePointCutscene_Init(globalCtx, 4221, 140, &pthis->dyna.actor, MAIN_CAM);
        }
    }
}

void func_808B9698(BgSpot18Shutter* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 180.0f, 1.44f)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONEDOOR_STOP);
        pthis->actionFunc = func_808B95AC;
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG);
    }
}

void func_808B971C(BgSpot18Shutter* pthis, GlobalContext* globalCtx) {
    f32 sin = Math_SinS(pthis->dyna.actor.world.rot.y);
    f32 cos = Math_CosS(pthis->dyna.actor.world.rot.y);
    s32 flag = true;

    flag &= Math_StepToF(&pthis->dyna.actor.world.pos.x, pthis->dyna.actor.home.pos.x + (125.0f * cos), fabsf(cos));
    flag &= Math_StepToF(&pthis->dyna.actor.world.pos.z, pthis->dyna.actor.home.pos.z - (125.0f * sin), fabsf(sin));

    if (flag) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONEDOOR_STOP);
        pthis->actionFunc = func_808B95AC;
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG);
    }
}

void BgSpot18Shutter_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Shutter* pthis = (BgSpot18Shutter*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot18Shutter_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gGoronCityDoorDL);
}

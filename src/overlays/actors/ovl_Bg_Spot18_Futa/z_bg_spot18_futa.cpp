#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT18_FUTA_Z_BG_SPOT18_FUTA_C
#include "actor_common.h"
/*
 * File: z_bg_spot18_futa.c
 * Overlay: ovl_Bg_Spot18_Futa
 * Description: The lid to the spinning goron vase.
 */

#include "z_bg_spot18_futa.h"
#include "objects/object_spot18_obj/object_spot18_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS 0

void BgSpot18Futa_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Futa_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot18Futa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Futa_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Futa_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit Bg_Spot18_Futa_InitVars = {
    ACTOR_BG_SPOT18_FUTA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Futa),
    (ActorFunc)BgSpot18Futa_Init,
    (ActorFunc)BgSpot18Futa_Destroy,
    (ActorFunc)BgSpot18Futa_Update,
    (ActorFunc)BgSpot18Futa_Draw,
    (ActorFunc)BgSpot18Futa_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgSpot18Futa_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Futa* pthis = (BgSpot18Futa*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gGoronCityVaseLidCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
}

void BgSpot18Futa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Futa* pthis = (BgSpot18Futa*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgSpot18Futa_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Futa* pthis = (BgSpot18Futa*)thisx;
    s32 iVar1;

    if (pthis->dyna.actor.parent == NULL) {
        iVar1 = Math_StepToF(&pthis->dyna.actor.scale.x, 0, 0.005);

        if (iVar1 != 0) {
            Actor_Kill(&pthis->dyna.actor);
        } else {
            pthis->dyna.actor.scale.z = pthis->dyna.actor.scale.x;
            pthis->dyna.actor.scale.y = pthis->dyna.actor.scale.x;
        }
    }
}

void BgSpot18Futa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gGoronCityVaseLidDL);
}

void BgSpot18Futa_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Spot18_Futa_InitVars = {
        ACTOR_BG_SPOT18_FUTA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_SPOT18_OBJ,
        sizeof(BgSpot18Futa),
        (ActorFunc)BgSpot18Futa_Init,
        (ActorFunc)BgSpot18Futa_Destroy,
        (ActorFunc)BgSpot18Futa_Update,
        (ActorFunc)BgSpot18Futa_Draw,
        (ActorFunc)BgSpot18Futa_Reset,
    };

}

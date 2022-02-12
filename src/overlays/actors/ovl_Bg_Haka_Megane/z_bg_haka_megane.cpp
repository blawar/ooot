#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_MEGANE_Z_BG_HAKA_MEGANE_C
#include "actor_common.h"
/*
 * File: z_bg_haka_megane.c
 * Overlay: ovl_Bg_Haka_Megane
 * Description: Shadow Temple Fake Walls
 */

#include "z_bg_haka_megane.h"
#include "objects/object_hakach_objects/object_hakach_objects.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_7)

void BgHakaMegane_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMegane_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMegane_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMegane_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8087DB24(BgHakaMegane* pthis, GlobalContext* globalCtx);
void func_8087DBF0(BgHakaMegane* pthis, GlobalContext* globalCtx);
void BgHakaMegane_DoNothing(BgHakaMegane* pthis, GlobalContext* globalCtx);

ActorInit Bg_Haka_Megane_InitVars = {
    ACTOR_BG_HAKA_MEGANE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHakaMegane),
    (ActorFunc)BgHakaMegane_Init,
    (ActorFunc)BgHakaMegane_Destroy,
    (ActorFunc)BgHakaMegane_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static CollisionHeader* sCollisionHeaders[] = {
    &gBotw1Col,
    &gBotw2Col,
    NULL,
    &object_haka_objects_Col_004330,
    &object_haka_objects_Col_0044D0,
    NULL,
    &object_haka_objects_Col_004780,
    &object_haka_objects_Col_004940,
    NULL,
    &object_haka_objects_Col_004B00,
    NULL,
    &object_haka_objects_Col_004CC0,
    NULL,
};

static Gfx* sDLists[] = {
    gBotwFakeWallsAndFloorsDL,     gBotwThreeFakeFloorsDL,        gBotwHoleTrap2DL,
    object_haka_objects_DL_0040F0, object_haka_objects_DL_0043B0, object_haka_objects_DL_001120,
    object_haka_objects_DL_0045A0, object_haka_objects_DL_0047F0, object_haka_objects_DL_0018F0,
    object_haka_objects_DL_0049B0, object_haka_objects_DL_003CF0, object_haka_objects_DL_004B70,
    object_haka_objects_DL_002ED0,
};

void BgHakaMegane_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMegane* pthis = (BgHakaMegane*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);

    if (thisx->params < 3) {
        pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_HAKACH_OBJECTS);
    } else {
        pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_HAKA_OBJECTS);
    }

    if (pthis->objBankIndex < 0) {
        Actor_Kill(thisx);
    } else {
        pthis->actionFunc = func_8087DB24;
    }
}

void BgHakaMegane_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMegane* pthis = (BgHakaMegane*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8087DB24(BgHakaMegane* pthis, GlobalContext* globalCtx) {
    CollisionHeader* colHeader;
    CollisionHeader* collision;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        pthis->dyna.actor.objBankIndex = pthis->objBankIndex;
        pthis->dyna.actor.draw = BgHakaMegane_Draw;
        Actor_SetObjectDependency(globalCtx, &pthis->dyna.actor);
        if (globalCtx->roomCtx.curRoom.showInvisActors) {
            pthis->actionFunc = func_8087DBF0;
            collision = sCollisionHeaders[pthis->dyna.actor.params];
            if (collision != NULL) {
                CollisionHeader_GetVirtual(collision, &colHeader);
                pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            }
        } else {
            pthis->actionFunc = BgHakaMegane_DoNothing;
        }
    }
}

void func_8087DBF0(BgHakaMegane* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;

    if (globalCtx->actorCtx.unk_03 != 0) {
        thisx->flags |= ACTOR_FLAG_7;
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    } else {
        thisx->flags &= ~ACTOR_FLAG_7;
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void BgHakaMegane_DoNothing(BgHakaMegane* pthis, GlobalContext* globalCtx) {
}

void BgHakaMegane_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMegane* pthis = (BgHakaMegane*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHakaMegane_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMegane* pthis = (BgHakaMegane*)thisx;

    if (CHECK_FLAG_ALL(thisx->flags, ACTOR_FLAG_7)) {
        Gfx_DrawDListXlu(globalCtx, sDLists[thisx->params]);
    } else {
        Gfx_DrawDListOpa(globalCtx, sDLists[thisx->params]);
    }

    if (thisx->params == 0) {
        Gfx_DrawDListXlu(globalCtx, gBotwBloodSplatterDL);
    }
}

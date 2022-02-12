#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_BLOCKSTOP_Z_OBJ_BLOCKSTOP_C
#include "actor_common.h"
/*
 * File: z_obj_blockstop.c
 * Overlay: ovl_Obj_Blockstop
 * Description: Stops blocks and sets relevant flags when the block is in position.
 */

#include "z_obj_blockstop.h"
#include "overlays/actors/ovl_Obj_Oshihiki/z_obj_oshihiki.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"

#define FLAGS 0

void ObjBlockstop_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjBlockstop_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjBlockstop_Update(Actor* thisx, GlobalContext* globalCtx);

ActorInit Obj_Blockstop_InitVars = {
    ACTOR_OBJ_BLOCKSTOP,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjBlockstop),
    (ActorFunc)ObjBlockstop_Init,
    (ActorFunc)ObjBlockstop_Destroy,
    (ActorFunc)ObjBlockstop_Update,
    NULL,
};

void ObjBlockstop_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjBlockstop* pthis = (ObjBlockstop*)thisx;

    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        Actor_Kill(&pthis->actor);
    } else {
        pthis->actor.world.pos.y++;
    }
}

void ObjBlockstop_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void ObjBlockstop_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjBlockstop* pthis = (ObjBlockstop*)thisx;
    DynaPolyActor* dynaPolyActor;
    Vec3f sp4C;
    s32 bgId;
    s32 pad;

    if (BgCheck_EntityLineTest2(&globalCtx->colCtx, &pthis->actor.home.pos, &pthis->actor.world.pos, &sp4C,
                                &pthis->actor.floorPoly, false, false, true, true, &bgId, &pthis->actor)) {
        dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, bgId);

        if (dynaPolyActor != NULL && dynaPolyActor->actor.id == ACTOR_OBJ_OSHIHIKI) {
            if ((dynaPolyActor->actor.params & 0x000F) == PUSHBLOCK_HUGE_START_ON ||
                (dynaPolyActor->actor.params & 0x000F) == PUSHBLOCK_HUGE_START_OFF) {
                func_80078884(NA_SE_SY_CORRECT_CHIME);
            } else {
                func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
            }

            Flags_SetSwitch(globalCtx, pthis->actor.params);
            Actor_Kill(&pthis->actor);
        }
    }
}

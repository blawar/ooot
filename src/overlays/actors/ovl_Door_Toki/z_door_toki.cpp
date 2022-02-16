#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DOOR_TOKI_Z_DOOR_TOKI_C
#include "actor_common.h"
/*
 * File: z_door_toki.c
 * Overlay: ovl_Door_Toki
 * Description: Door of Time Collision
 */

#include "z_door_toki.h"
#include "objects/object_toki_objects/object_toki_objects.h"
#include "def/code_80043480.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"

#define FLAGS 0

void DoorToki_Init(Actor* thisx, GlobalContext* globalCtx);
void DoorToki_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DoorToki_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DoorToki_Update(Actor* thisx, GlobalContext* globalCtx);

ActorInit Door_Toki_InitVars = {
    ACTOR_DOOR_TOKI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TOKI_OBJECTS,
    sizeof(DoorToki),
    (ActorFunc)DoorToki_Init,
    (ActorFunc)DoorToki_Destroy,
    (ActorFunc)DoorToki_Update,
    NULL,
    (ActorFunc)DoorToki_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void DoorToki_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    DoorToki* pthis = (DoorToki*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gDoorTokiCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void DoorToki_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DoorToki* pthis = (DoorToki*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void DoorToki_Update(Actor* thisx, GlobalContext* globalCtx) {
    DoorToki* pthis = (DoorToki*)thisx;

    if (gSaveContext.eventChkInf[4] & 0x800) {
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    } else {
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void DoorToki_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Door_Toki_InitVars = {
        ACTOR_DOOR_TOKI,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_TOKI_OBJECTS,
        sizeof(DoorToki),
        (ActorFunc)DoorToki_Init,
        (ActorFunc)DoorToki_Destroy,
        (ActorFunc)DoorToki_Update,
        NULL,
        (ActorFunc)DoorToki_Reset,
    };

}

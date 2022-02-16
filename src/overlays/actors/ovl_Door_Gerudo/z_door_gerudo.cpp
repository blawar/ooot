#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DOOR_GERUDO_Z_DOOR_GERUDO_C
#include "actor_common.h"
/*
 * File: z_door_gerudo.c
 * Overlay: ovl_Door_Gerudo
 * Description: Metal grate door
 */

#include "z_door_gerudo.h"
#include "objects/object_door_gerudo/object_door_gerudo.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void DoorGerudo_Init(Actor* thisx, GlobalContext* globalCtx);
void DoorGerudo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DoorGerudo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DoorGerudo_Update(Actor* thisx, GlobalContext* globalCtx);
void DoorGerudo_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8099485C(DoorGerudo* pthis, GlobalContext* globalCtx);
s32 func_80994750(DoorGerudo* pthis, GlobalContext* globalCtx);
void func_8099496C(DoorGerudo* pthis, GlobalContext* globalCtx);
void func_809949C8(DoorGerudo* pthis, GlobalContext* globalCtx);

ActorInit Door_Gerudo_InitVars = {
    ACTOR_DOOR_GERUDO,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_DOOR_GERUDO,
    sizeof(DoorGerudo),
    (ActorFunc)DoorGerudo_Init,
    (ActorFunc)DoorGerudo_Destroy,
    (ActorFunc)DoorGerudo_Update,
    (ActorFunc)DoorGerudo_Draw,
    (ActorFunc)DoorGerudo_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_STOP),
};

void DoorGerudo_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    DoorGerudo* pthis = (DoorGerudo*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    CollisionHeader_GetVirtual(&gGerudoCellDoorCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);

    if (Flags_GetSwitch(globalCtx, thisx->params & 0x3F)) {
        pthis->actionFunc = func_8099485C;
        thisx->world.pos.y = thisx->home.pos.y + 200.0f;
    } else {
        pthis->actionFunc = func_8099485C;
        pthis->unk_166 = 10;
    }
}

void DoorGerudo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DoorGerudo* pthis = (DoorGerudo*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

f32 func_809946BC(GlobalContext* globalCtx, DoorGerudo* pthis, f32 arg2, f32 arg3, f32 arg4) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f playerPos;
    Vec3f sp1C;

    playerPos.x = player->actor.world.pos.x;
    playerPos.y = player->actor.world.pos.y + arg2;
    playerPos.z = player->actor.world.pos.z;
    func_8002DBD0(&pthis->dyna.actor, &sp1C, &playerPos);

    if ((arg3 < fabsf(sp1C.x)) || (arg4 < fabsf(sp1C.y))) {
        return FLT_MAX;
    } else {
        return sp1C.z;
    }
}

s32 func_80994750(DoorGerudo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 temp_f0;
    s16 rotYDiff;

    if (!Player_InCsMode(globalCtx)) {
        temp_f0 = func_809946BC(globalCtx, pthis, 0.0f, 20.0f, 15.0f);
        if (fabsf(temp_f0) < 40.0f) {
            rotYDiff = player->actor.shape.rot.y - pthis->dyna.actor.shape.rot.y;
            if (temp_f0 > 0.0f) {
                rotYDiff = 0x8000 - rotYDiff;
            }
            if (ABS(rotYDiff) < 0x2000) {
                return (temp_f0 >= 0.0f) ? 1.0f : -1.0f;
            }
        }
    }
    return 0;
}

void func_8099485C(DoorGerudo* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_164 != 0) {
        pthis->actionFunc = func_8099496C;
        gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex] -= 1;
        Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK);
    } else {
        s32 direction = func_80994750(pthis, globalCtx);

        if (direction != 0) {
            Player* player = GET_PLAYER(globalCtx);

            if (gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex] <= 0) {
                player->naviTextId = -0x203;
            } else if (!Flags_GetCollectible(globalCtx, (pthis->dyna.actor.params >> 8) & 0x1F)) {
                player->naviTextId = -0x225;
            } else {
                player->doorType = PLAYER_DOORTYPE_SLIDING;
                player->doorDirection = direction;
                player->doorActor = &pthis->dyna.actor;
                player->doorTimer = 10;
            }
        }
    }
}

void func_8099496C(DoorGerudo* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->unk_166) == 0) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
        pthis->actionFunc = func_809949C8;
    }
}

void func_809949C8(DoorGerudo* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->dyna.actor.velocity.y, 15.0f, 3.0f);
    Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 200.0f, pthis->dyna.actor.velocity.y);
}

void DoorGerudo_Update(Actor* thisx, GlobalContext* globalCtx) {
    DoorGerudo* pthis = (DoorGerudo*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void DoorGerudo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DoorGerudo* pthis = (DoorGerudo*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_door_gerudo.c", 361);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_door_gerudo.c", 365),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gGerudoCellDoorDL);

    if (pthis->unk_166 != 0) {
        Matrix_Scale(0.01f, 0.01f, 0.025f, MTXMODE_APPLY);
        Actor_DrawDoorLock(globalCtx, pthis->unk_166, DOORLOCK_NORMAL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_door_gerudo.c", 377);
}

void DoorGerudo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Door_Gerudo_InitVars = {
        ACTOR_DOOR_GERUDO,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_DOOR_GERUDO,
        sizeof(DoorGerudo),
        (ActorFunc)DoorGerudo_Init,
        (ActorFunc)DoorGerudo_Destroy,
        (ActorFunc)DoorGerudo_Update,
        (ActorFunc)DoorGerudo_Draw,
        (ActorFunc)DoorGerudo_Reset,
    };

}

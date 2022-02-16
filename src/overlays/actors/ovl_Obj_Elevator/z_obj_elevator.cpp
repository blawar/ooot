#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_ELEVATOR_Z_OBJ_ELEVATOR_C
#include "actor_common.h"
/*
 * File: z_obj_elevator.c
 * Overlay: Obj_Elevator
 * Description: Stone Elevator
 */

#include "z_obj_elevator.h"
#include "objects/object_d_elevator/object_d_elevator.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS 0

void ObjElevator_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjElevator_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjElevator_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjElevator_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjElevator_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B92C5C(ObjElevator* pthis);
void func_80B92C80(ObjElevator* pthis, GlobalContext* globalCtx);
void func_80B92D20(ObjElevator* pthis);
void func_80B92D44(ObjElevator* pthis, GlobalContext* globalCtx);

ActorInit Obj_Elevator_InitVars = {
    ACTOR_OBJ_ELEVATOR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_D_ELEVATOR,
    sizeof(ObjElevator),
    (ActorFunc)ObjElevator_Init,
    (ActorFunc)ObjElevator_Destroy,
    (ActorFunc)ObjElevator_Update,
    (ActorFunc)ObjElevator_Draw,
    (ActorFunc)ObjElevator_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 600, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2000, ICHAIN_STOP),
};

static f32 sScales[] = { 0.1f, 0.05f };

void ObjElevator_SetupAction(ObjElevator* pthis, ObjElevatorActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void func_80B92B08(ObjElevator* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flag) {
    s16 pad1;
    CollisionHeader* colHeader = NULL;
    s16 pad2;
    Actor* thisx = &pthis->dyna.actor;

    DynaPolyActor_Init(&pthis->dyna, flag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_elevator.c", 136,
                     thisx->id, thisx->params);
    }
}

void ObjElevator_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjElevator* pthis = (ObjElevator*)thisx;
    f32 temp_f0;

    func_80B92B08(pthis, globalCtx, &object_d_elevator_Col_000360, DPM_PLAYER);
    Actor_SetScale(thisx, sScales[thisx->params & 1]);
    Actor_ProcessInitChain(thisx, sInitChain);
    temp_f0 = (thisx->params >> 8) & 0xF;
    pthis->unk_16C = temp_f0 + temp_f0;
    func_80B92C5C(pthis);
    osSyncPrintf("(Dungeon Elevator)(arg_data 0x%04x)\n", thisx->params);
}

void ObjElevator_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjElevator* pthis = (ObjElevator*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80B92C5C(ObjElevator* pthis) {
    ObjElevator_SetupAction(pthis, func_80B92C80);
}

void func_80B92C80(ObjElevator* pthis, GlobalContext* globalCtx) {
    f32 sub;
    Actor* thisx = &pthis->dyna.actor;

    if ((pthis->dyna.unk_160 & 2) && !(pthis->unk_170 & 2)) {
        sub = thisx->world.pos.y - thisx->home.pos.y;
        if (fabsf(sub) < 0.1f) {
            pthis->unk_168 = thisx->home.pos.y + ((thisx->params >> 0xC) & 0xF) * 80.0f;
        } else {
            pthis->unk_168 = thisx->home.pos.y;
        }
        func_80B92D20(pthis);
    }
}

void func_80B92D20(ObjElevator* pthis) {
    ObjElevator_SetupAction(pthis, func_80B92D44);
}

void func_80B92D44(ObjElevator* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;

    if (fabsf(Math_SmoothStepToF(&thisx->world.pos.y, pthis->unk_168, 1.0f, pthis->unk_16C, 0.0f)) < 0.001f) {
        Audio_PlayActorSound2(thisx, NA_SE_EV_FOOT_SWITCH);
        func_80B92C5C(pthis);
    } else {
        Audio_PlayActorSound2(thisx, NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG);
    }
}

void ObjElevator_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjElevator* pthis = (ObjElevator*)thisx;

    if (pthis->actionFunc) {
        pthis->actionFunc(pthis, globalCtx);
    }
    pthis->unk_170 = pthis->dyna.unk_160;
}

void ObjElevator_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, object_d_elevator_DL_000180);
}

void ObjElevator_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Elevator_InitVars = {
        ACTOR_OBJ_ELEVATOR,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_D_ELEVATOR,
        sizeof(ObjElevator),
        (ActorFunc)ObjElevator_Init,
        (ActorFunc)ObjElevator_Destroy,
        (ActorFunc)ObjElevator_Update,
        (ActorFunc)ObjElevator_Draw,
        (ActorFunc)ObjElevator_Reset,
    };

}

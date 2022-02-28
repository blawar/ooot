#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_ROOMTIMER_Z_OBJ_ROOMTIMER_C
#include "actor_common.h"
/*
 * File: z_obj_roomtimer.c
 * Overlay: ovl_Obj_Roomtimer
 * Description: Starts Timer 1 with a value specified in params
 */

#include "z_obj_roomtimer.h"
#include "def/audio_bank.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_play.h"

#define FLAGS ACTOR_FLAG_4

void ObjRoomtimer_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjRoomtimer_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjRoomtimer_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjRoomtimer_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B9D054(ObjRoomtimer* pthis, GlobalContext* globalCtx);
void func_80B9D0B0(ObjRoomtimer* pthis, GlobalContext* globalCtx);

ActorInit Obj_Roomtimer_InitVars = {
    ACTOR_OBJ_ROOMTIMER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjRoomtimer),
    (ActorFunc)ObjRoomtimer_Init,
    (ActorFunc)ObjRoomtimer_Destroy,
    (ActorFunc)ObjRoomtimer_Update,
    (ActorFunc)NULL,
    (ActorFunc)ObjRoomtimer_Reset,
};

void ObjRoomtimer_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjRoomtimer* pthis = (ObjRoomtimer*)thisx;
    s16 params = pthis->actor.params;

    pthis->switchFlag = (params >> 10) & 0x3F;
    pthis->actor.params = params & 0x3FF;
    params = pthis->actor.params;

    if (params != 0x3FF) {
        if (params > 600) {
            pthis->actor.params = 600;
        } else {
            pthis->actor.params = params;
        }
    }

    pthis->actionFunc = func_80B9D054;
}

void ObjRoomtimer_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjRoomtimer* pthis = (ObjRoomtimer*)thisx;

    if ((pthis->actor.params != 0x3FF) && (gSaveContext.timer1Value > 0)) {
        gSaveContext.timer1State = 10;
    }
}

void func_80B9D054(ObjRoomtimer* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params != 0x3FF) {
        func_80088B34(pthis->actor.params);
    }

    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
    pthis->actionFunc = func_80B9D0B0;
}

void func_80B9D0B0(ObjRoomtimer* pthis, GlobalContext* globalCtx) {
    if (Flags_GetTempClear(globalCtx, pthis->actor.room)) {
        if (pthis->actor.params != 0x3FF) {
            gSaveContext.timer1State = 10;
        }
        Flags_SetClear(globalCtx, pthis->actor.room);
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        Actor_Kill(&pthis->actor);
    } else {
        if ((pthis->actor.params != 0x3FF) && (gSaveContext.timer1Value == 0)) {
            Audio_PlaySoundGeneral(NA_SE_OC_ABYSS, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
            Gameplay_TriggerVoidOut(globalCtx);
            Actor_Kill(&pthis->actor);
        }
    }
}

void ObjRoomtimer_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjRoomtimer* pthis = (ObjRoomtimer*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ObjRoomtimer_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Roomtimer_InitVars = {
        ACTOR_OBJ_ROOMTIMER,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(ObjRoomtimer),
        (ActorFunc)ObjRoomtimer_Init,
        (ActorFunc)ObjRoomtimer_Destroy,
        (ActorFunc)ObjRoomtimer_Update,
        (ActorFunc)NULL,
        (ActorFunc)ObjRoomtimer_Reset,
    };

}

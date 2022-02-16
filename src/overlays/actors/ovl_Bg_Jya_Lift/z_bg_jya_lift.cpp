#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_LIFT_Z_BG_JYA_LIFT_C
#include "actor_common.h"
/*
 * File: z_bg_jya_lift.c
 * Overlay: ovl_Bg_Jya_Lift
 * Description: Chain Platform (Spirit Temple)
 */

#include "z_bg_jya_lift.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS ACTOR_FLAG_4

void BgJyaLift_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaLift_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaLift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaLift_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaLift_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJyaLift_SetFinalPosY(BgJyaLift* pthis);
void BgJyaLift_SetInitPosY(BgJyaLift* pthis);
void BgJyaLift_DelayMove(BgJyaLift* pthis, GlobalContext* globalCtx);
void BgJyaLift_SetupMove(BgJyaLift* pthis);
void BgJyaLift_Move(BgJyaLift* pthis, GlobalContext* globalCtx);

static s16 sIsSpawned = false;

ActorInit Bg_Jya_Lift_InitVars = {
    ACTOR_BG_JYA_LIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaLift),
    (ActorFunc)BgJyaLift_Init,
    (ActorFunc)BgJyaLift_Destroy,
    (ActorFunc)BgJyaLift_Update,
    (ActorFunc)BgJyaLift_Draw,
    (ActorFunc)BgJyaLift_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 2500, ICHAIN_STOP),
};

void BgJyaLift_InitDynapoly(BgJyaLift* pthis, GlobalContext* globalCtx, CollisionHeader* collisionHeader, s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collisionHeader, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void BgJyaLift_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaLift* pthis = (BgJyaLift*)thisx;

    pthis->isSpawned = false;
    if (sIsSpawned) {
        Actor_Kill(thisx);
        return;
    }

    // "Goddess lift CT"
    osSyncPrintf("女神リフト CT\n");
    BgJyaLift_InitDynapoly(pthis, globalCtx, &gLiftCol, DPM_UNK);
    Actor_ProcessInitChain(thisx, sInitChain);
    if (Flags_GetSwitch(globalCtx, (thisx->params & 0x3F))) {
        BgJyaLift_SetFinalPosY(pthis);
    } else {
        BgJyaLift_SetInitPosY(pthis);
    }
    thisx->room = -1;
    sIsSpawned = true;
    pthis->isSpawned = true;
}

void BgJyaLift_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaLift* pthis = (BgJyaLift*)thisx;

    if (pthis->isSpawned) {

        // "Goddess Lift DT"
        osSyncPrintf("女神リフト DT\n");
        sIsSpawned = false;
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void BgJyaLift_SetInitPosY(BgJyaLift* pthis) {
    pthis->actionFunc = BgJyaLift_DelayMove;
    pthis->dyna.actor.world.pos.y = 1613.0f;
    pthis->moveDelay = 0;
}

void BgJyaLift_DelayMove(BgJyaLift* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F) || (pthis->moveDelay > 0)) {
        pthis->moveDelay++;
        if (pthis->moveDelay >= 20) {
            OnePointCutscene_Init(globalCtx, 3430, -99, &pthis->dyna.actor, MAIN_CAM);
            BgJyaLift_SetupMove(pthis);
        }
    }
}

void BgJyaLift_SetupMove(BgJyaLift* pthis) {
    pthis->actionFunc = BgJyaLift_Move;
}

void BgJyaLift_Move(BgJyaLift* pthis, GlobalContext* globalCtx) {
    f32 distFromBottom;
    f32 tempVelocity;

    Math_SmoothStepToF(&pthis->dyna.actor.velocity.y, 4.0f, 0.1f, 1.0f, 0.0f);
    tempVelocity = (pthis->dyna.actor.velocity.y < 0.2f) ? 0.2f : pthis->dyna.actor.velocity.y;
    distFromBottom = Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, 973.0f, 0.1f, tempVelocity, 0.2f);
    if ((pthis->dyna.actor.world.pos.y < 1440.0f) && (1440.0f <= pthis->dyna.actor.prevPos.y)) {
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
    }
    if (fabsf(distFromBottom) < 0.001f) {
        BgJyaLift_SetFinalPosY(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_BRIDGE_OPEN - SFX_FLAG);
    }
}

void BgJyaLift_SetFinalPosY(BgJyaLift* pthis) {
    pthis->actionFunc = NULL;
    pthis->dyna.actor.world.pos.y = 973.0f;
}

void BgJyaLift_Update(Actor* thisx, GlobalContext* globalCtx2) {
    BgJyaLift* pthis = (BgJyaLift*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
    if ((pthis->dyna.unk_160 & 4) && ((pthis->unk_16B & 4) == 0)) {
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DIRECTED_YAW);
    } else if (((pthis->dyna.unk_160) & 4) == 0 && ((pthis->unk_16B & 4)) &&
               (globalCtx->cameraPtrs[MAIN_CAM]->setting == CAM_SET_DIRECTED_YAW)) {
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
    }
    pthis->unk_16B = pthis->dyna.unk_160;

    // Spirit Temple room 5 is the main room with the statue room 25 is directly above room 5
    if ((globalCtx->roomCtx.curRoom.num != 5) && (globalCtx->roomCtx.curRoom.num != 25)) {
        Actor_Kill(thisx);
    }
}

void BgJyaLift_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gLiftDL);
}

void BgJyaLift_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sIsSpawned = false;

    Bg_Jya_Lift_InitVars = {
        ACTOR_BG_JYA_LIFT,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_JYA_OBJ,
        sizeof(BgJyaLift),
        (ActorFunc)BgJyaLift_Init,
        (ActorFunc)BgJyaLift_Destroy,
        (ActorFunc)BgJyaLift_Update,
        (ActorFunc)BgJyaLift_Draw,
        (ActorFunc)BgJyaLift_Reset,
    };

}

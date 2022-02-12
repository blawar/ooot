#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_1FLIFT_Z_BG_JYA_1FLIFT_C
#include "actor_common.h"
/*
 * File: z_bg_jya_1flift.c
 * Overlay: ovl_Bg_Jya_1flift
 * Description: Shortcut Elevator used in the vanilla version of the Spirit Temple
 */

#include "z_bg_jya_1flift.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void BgJya1flift_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJya1flift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJya1flift_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJya1flift_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgJya1flift_SetupWaitForSwitch(BgJya1flift* pthis);
void BgJya1flift_WaitForSwitch(BgJya1flift* pthis, GlobalContext* globalCtx);
void BgJya1flift_DoNothing(BgJya1flift* pthis, GlobalContext* globalCtx);
void BgJya1flift_ChangeDirection(BgJya1flift* pthis);
void BgJya1flift_Move(BgJya1flift* pthis, GlobalContext* globalCtx);
void BgJya1flift_SetupDoNothing(BgJya1flift* pthis);
void BgJya1flift_ResetMoveDelay(BgJya1flift* pthis);
void BgJya1flift_DelayMove(BgJya1flift* pthis, GlobalContext* globalCtx);

static u8 sIsSpawned = false;

ActorInit Bg_Jya_1flift_InitVars = {
    ACTOR_BG_JYA_1FLIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJya1flift),
    (ActorFunc)BgJya1flift_Init,
    (ActorFunc)BgJya1flift_Destroy,
    (ActorFunc)BgJya1flift_Update,
    (ActorFunc)BgJya1flift_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 70, 80, -82, { 0, 0, 0 } },
};

static f32 sFinalPositions[] = { 443.0f, -50.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_STOP),
};

void BgJya1flift_InitDynapoly(BgJya1flift* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG login failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_jya_1flift.c", 179,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgJya1flift_InitCollision(Actor* thisx, GlobalContext* globalCtx) {
    BgJya1flift* pthis = (BgJya1flift*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
    pthis->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
}

void BgJya1flift_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJya1flift* pthis = (BgJya1flift*)thisx;
    // "1 F lift"
    osSyncPrintf("(１Ｆリフト)(flag %d)(room %d)\n", sIsSpawned, globalCtx->roomCtx.curRoom.num);
    pthis->hasInitialized = false;
    if (sIsSpawned) {
        Actor_Kill(thisx);
        return;
    }
    BgJya1flift_InitDynapoly(pthis, globalCtx, &g1fliftCol, 0);
    Actor_ProcessInitChain(thisx, sInitChain);
    BgJya1flift_InitCollision(thisx, globalCtx);
    if (Flags_GetSwitch(globalCtx, (thisx->params & 0x3F))) {
        LINK_AGE_IN_YEARS == YEARS_ADULT ? BgJya1flift_ChangeDirection(pthis) : BgJya1flift_SetupDoNothing(pthis);
    } else {
        BgJya1flift_SetupWaitForSwitch(pthis);
    }
    thisx->room = -1;
    sIsSpawned = true;
    pthis->hasInitialized = true;
}

void BgJya1flift_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJya1flift* pthis = (BgJya1flift*)thisx;

    if (pthis->hasInitialized) {
        sIsSpawned = false;
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void BgJya1flift_SetupWaitForSwitch(BgJya1flift* pthis) {
    pthis->actionFunc = BgJya1flift_WaitForSwitch;
    pthis->dyna.actor.world.pos.y = sFinalPositions[0];
}

void BgJya1flift_WaitForSwitch(BgJya1flift* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params & 0x3F))) {
        BgJya1flift_ChangeDirection(pthis);
    }
}

void BgJya1flift_SetupDoNothing(BgJya1flift* pthis) {
    pthis->actionFunc = BgJya1flift_DoNothing;
    pthis->dyna.actor.world.pos.y = sFinalPositions[0];
}

void BgJya1flift_DoNothing(BgJya1flift* pthis, GlobalContext* globalCtx) {
}

void BgJya1flift_ChangeDirection(BgJya1flift* pthis) {
    pthis->actionFunc = BgJya1flift_Move;
    pthis->isMovingDown ^= true;
    pthis->dyna.actor.velocity.y = 0.0f;
}

void BgJya1flift_Move(BgJya1flift* pthis, GlobalContext* globalCtx) {
    f32 tempVelocity;

    Math_StepToF(&pthis->dyna.actor.velocity.y, 6.0f, 0.4f);
    if (pthis->dyna.actor.velocity.y < 1.0f) {
        tempVelocity = 1.0f;
    } else {
        tempVelocity = pthis->dyna.actor.velocity.y;
    }
    if (fabsf(Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, (sFinalPositions[pthis->isMovingDown]), 0.5f,
                                 tempVelocity, 1.0f)) < 0.001f) {
        pthis->dyna.actor.world.pos.y = sFinalPositions[pthis->isMovingDown];
        BgJya1flift_ResetMoveDelay(pthis);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);
    }
}

void BgJya1flift_ResetMoveDelay(BgJya1flift* pthis) {
    pthis->actionFunc = BgJya1flift_DelayMove;
    pthis->moveDelay = 0;
}

void BgJya1flift_DelayMove(BgJya1flift* pthis, GlobalContext* globalCtx) {
    pthis->moveDelay++;
    if (pthis->moveDelay >= 21) {
        BgJya1flift_ChangeDirection(pthis);
    }
}

void BgJya1flift_Update(Actor* thisx, GlobalContext* globalCtx2) {
    BgJya1flift* pthis = (BgJya1flift*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 tempIsRiding;

    // Room 0 is the first room and 6 is the room that the lift starts on
    if (globalCtx->roomCtx.curRoom.num == 6 || globalCtx->roomCtx.curRoom.num == 0) {
        pthis->actionFunc(pthis, globalCtx);
        tempIsRiding = func_8004356C(&pthis->dyna) ? true : false;
        if ((pthis->actionFunc == BgJya1flift_Move) || (pthis->actionFunc == BgJya1flift_DelayMove)) {
            if (tempIsRiding) {
                Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FIRE_PLATFORM);
            } else if (!tempIsRiding && pthis->isLinkRiding) {
                Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
            }
        }
        pthis->isLinkRiding = tempIsRiding;
        Collider_UpdateCylinder(thisx, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    } else {
        Actor_Kill(thisx);
    }
}

void BgJya1flift_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, g1fliftDL);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_DDAN_JD_Z_BG_DDAN_JD_C
#include "actor_common.h"
/*
 * File: z_bg_ddan_jd.c
 * Overlay: ovl_Bg_Ddan_Jd
 * Description: Rising stone platform (Dodongo's Cavern)
 */

#include "z_bg_ddan_jd.h"
#include "objects/object_ddan_objects/object_ddan_objects.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgDdanJd_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanJd_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanJd_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgDdanJd_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgDdanJd_Idle(BgDdanJd* pthis, GlobalContext* globalCtx);
void BgDdanJd_Move(BgDdanJd* pthis, GlobalContext* globalCtx);

ActorInit Bg_Ddan_Jd_InitVars = {
    ACTOR_BG_DDAN_JD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DDAN_OBJECTS,
    sizeof(BgDdanJd),
    (ActorFunc)BgDdanJd_Init,
    (ActorFunc)BgDdanJd_Destroy,
    (ActorFunc)BgDdanJd_Update,
    (ActorFunc)BgDdanJd_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

typedef enum {
    /* 0 */ STATE_GO_BOTTOM,
    /* 1 */ STATE_GO_MIDDLE_FROM_BOTTOM,
    /* 2 */ STATE_GO_MIDDLE_FROM_TOP,
    /* 3 */ STATE_GO_TOP
} BgDdanJdState;

#define MOVE_HEIGHT_MIDDLE 140.0f
#define MOVE_HEIGHT_TOP 700.0f

#define IDLE_FRAMES 100

// Since ySpeed is used to determine if the platform should rise to the top of the dungeon, these must be assigned
// different values in order for the shortcut to work correctly
#define DEFAULT_Y_SPEED 1
#define SHORTCUT_Y_SPEED 5

void BgDdanJd_Init(Actor* pthisx, GlobalContext* globalCtx) {
    s32 pad;
    BgDdanJd* pthis = (BgDdanJd*)pthisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gDodongoRisingPlatformCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->idleTimer = IDLE_FRAMES;
    pthis->state = STATE_GO_BOTTOM;

    // Missing check for actor.params < 0x40. This will cause inconsistent behavior if params >= 0x40 and the bound
    // switch state is turned on while in the same room, as the shortcut behavior won't become enabled until the actor
    // is reloaded.
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
        pthis->ySpeed = SHORTCUT_Y_SPEED;
    } else {
        pthis->ySpeed = DEFAULT_Y_SPEED;
    }
    pthis->actionFunc = BgDdanJd_Idle;
}

void BgDdanJd_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgDdanJd* pthis = (BgDdanJd*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgDdanJd_Idle(BgDdanJd* pthis, GlobalContext* globalCtx) {
    if (pthis->idleTimer != 0) {
        pthis->idleTimer--;
    }

    // if pthis is the platform that rises all the way to the top, and the switch state has just changed to on
    if (pthis->ySpeed == DEFAULT_Y_SPEED && pthis->dyna.actor.params < 0x40 &&
        Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
        pthis->ySpeed = SHORTCUT_Y_SPEED;
        pthis->state = STATE_GO_MIDDLE_FROM_BOTTOM;
        pthis->idleTimer = 0;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_MIDDLE;
        OnePointCutscene_Init(globalCtx, 3060, -99, &pthis->dyna.actor, MAIN_CAM);
    }
    if (pthis->idleTimer == 0) {
        pthis->idleTimer = IDLE_FRAMES;
        if (pthis->state == STATE_GO_BOTTOM) {
            pthis->state = STATE_GO_MIDDLE_FROM_BOTTOM;
            pthis->targetY = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_MIDDLE;
        } else if (pthis->state == STATE_GO_MIDDLE_FROM_BOTTOM) {
            // If the platform has been activated as a shortcut
            if (pthis->ySpeed != DEFAULT_Y_SPEED) {
                pthis->state = STATE_GO_TOP;
                pthis->targetY = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_TOP;
            } else {
                pthis->state = STATE_GO_BOTTOM;
                pthis->targetY = pthis->dyna.actor.home.pos.y;
            }
        } else if (pthis->state == STATE_GO_MIDDLE_FROM_TOP) {
            // If the platform has been activated as a shortcut
            if (pthis->ySpeed != DEFAULT_Y_SPEED) {
                pthis->state = STATE_GO_TOP;
                pthis->targetY = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_TOP;
            } else {
                pthis->state = STATE_GO_BOTTOM;
                pthis->targetY = pthis->dyna.actor.home.pos.y;
            }
        } else if (pthis->state == STATE_GO_TOP) {
            pthis->state = STATE_GO_MIDDLE_FROM_TOP;
            pthis->targetY = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_MIDDLE;
        }
        pthis->actionFunc = BgDdanJd_Move;
    }
}

// Handles dust particles and sfx when moving
void BgDdanJd_MoveEffects(BgDdanJd* pthis, GlobalContext* globalCtx) {
    Vec3f dustPos;

    // Generate random dust particles at the platform's base.
    dustPos.y = pthis->dyna.actor.home.pos.y;
    if (globalCtx->gameplayFrames & 1) {
        dustPos.x = pthis->dyna.actor.world.pos.x + 65.0f;
        dustPos.z = Rand_CenteredFloat(110.0f) + pthis->dyna.actor.world.pos.z;
        func_80033480(globalCtx, &dustPos, 5.0f, 1, 20, 60, 1);
        dustPos.x = pthis->dyna.actor.world.pos.x - 65.0f;
        dustPos.z = Rand_CenteredFloat(110.0f) + pthis->dyna.actor.world.pos.z;
        func_80033480(globalCtx, &dustPos, 5.0f, 1, 20, 60, 1);
    } else {
        dustPos.x = Rand_CenteredFloat(110.0f) + pthis->dyna.actor.world.pos.x;
        dustPos.z = pthis->dyna.actor.world.pos.z + 65.0f;
        func_80033480(globalCtx, &dustPos, 5.0f, 1, 20, 60, 1);
        dustPos.x = Rand_CenteredFloat(110.0f) + pthis->dyna.actor.world.pos.x;
        dustPos.z = pthis->dyna.actor.world.pos.z - 65.0f;
        func_80033480(globalCtx, &dustPos, 5.0f, 1, 20, 60, 1);
    }
    if (pthis->ySpeed == SHORTCUT_Y_SPEED) {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
    }
}

// Implements the platform's movement state
void BgDdanJd_Move(BgDdanJd* pthis, GlobalContext* globalCtx) {
    // if pthis is the platform that rises all the way to the top, and the switch state has just changed to on
    if (pthis->ySpeed == DEFAULT_Y_SPEED && pthis->dyna.actor.params < 0x40 &&
        Flags_GetSwitch(globalCtx, pthis->dyna.actor.params)) {
        pthis->ySpeed = SHORTCUT_Y_SPEED;
        pthis->state = STATE_GO_MIDDLE_FROM_BOTTOM;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + MOVE_HEIGHT_MIDDLE;
        pthis->idleTimer = 0;
        pthis->actionFunc = BgDdanJd_Idle;
        OnePointCutscene_Init(globalCtx, 3060, -99, &pthis->dyna.actor, MAIN_CAM);
    } else if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->targetY, pthis->ySpeed)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_PILLAR_MOVE_STOP);
        pthis->actionFunc = BgDdanJd_Idle;
    }
    BgDdanJd_MoveEffects(pthis, globalCtx);
}

void BgDdanJd_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgDdanJd* pthis = (BgDdanJd*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgDdanJd_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gDodongoRisingPlatformDL);
}

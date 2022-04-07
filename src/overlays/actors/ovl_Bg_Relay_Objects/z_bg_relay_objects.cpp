#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_RELAY_OBJECTS_Z_BG_RELAY_OBJECTS_C
#include "actor_common.h"
/*
 * File: z_bg_relay_objects.c
 * Overlay: ovl_Bg_Relay_Objects
 * Description: Windmill Setpieces
 */

#include "z_bg_relay_objects.h"
#include "objects/object_relay_objects/object_relay_objects.h"
#include "def/code_80043480.h"
#include "def/environment_flags.h"
#include "def/code_800A9F30.h"
#include "def/audio.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"

#define FLAGS ACTOR_FLAG_4


void BgRelayObjects_Init(Actor* thisx, GlobalContext* globalCtx);
void BgRelayObjects_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgRelayObjects_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgRelayObjects_Update(Actor* thisx, GlobalContext* globalCtx);
void BgRelayObjects_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808A90F4(BgRelayObjects* pthis, GlobalContext* globalCtx);
void func_808A91AC(BgRelayObjects* pthis, GlobalContext* globalCtx);
void func_808A9234(BgRelayObjects* pthis, GlobalContext* globalCtx);
void BgRelayObjects_DoNothing(BgRelayObjects* pthis, GlobalContext* globalCtx);
void func_808A932C(BgRelayObjects* pthis, GlobalContext* globalCtx);
void func_808A939C(BgRelayObjects* pthis, GlobalContext* globalCtx);

ActorInit Bg_Relay_Objects_InitVars = {
    ACTOR_BG_RELAY_OBJECTS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_RELAY_OBJECTS,
    sizeof(BgRelayObjects),
    (ActorFunc)BgRelayObjects_Init,
    (ActorFunc)BgRelayObjects_Destroy,
    (ActorFunc)BgRelayObjects_Update,
    (ActorFunc)BgRelayObjects_Draw,
    (ActorFunc)BgRelayObjects_Reset,
};

static u32 D_808A9508 = 0;

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(gravity, 5, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgRelayObjects_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgRelayObjects* pthis = (BgRelayObjects*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    pthis->switchFlag = thisx->params & 0x3F;
    thisx->params = (thisx->params >> 8) & 0xFF;
    DynaPolyActor_Init(&pthis->dyna, 3);
    if (thisx->params == WINDMILL_ROTATING_GEAR) {
        CollisionHeader_GetVirtual(&gWindmillRotatingPlatformCol, &colHeader);
        if (gSaveContext.eventChkInf[6] & 0x20) {
            thisx->world.rot.y = 0x400;
        } else {
            thisx->world.rot.y = 0x80;
        }
        Audio_PlayWindmill();
        thisx->room = -1;
        thisx->flags |= ACTOR_FLAG_5;
        if (D_808A9508 & 2) {
            thisx->params = 0xFF;
            Actor_Kill(thisx);
        } else {
            D_808A9508 |= 2;
            pthis->actionFunc = func_808A939C;
        }
    } else {
        CollisionHeader_GetVirtual(&gDampeRaceDoorCol, &colHeader);
        if (thisx->room == 0) {
            pthis->unk_169 = pthis->switchFlag - 0x33;
        } else {
            pthis->unk_169 = thisx->room + 1;
        }
        thisx->room = -1;
        pthis->timer = 1;
        if (pthis->unk_169 >= 6) {
            if (D_808A9508 & 1) {
                Actor_Kill(thisx);
            } else {
                D_808A9508 |= 1;
                pthis->actionFunc = BgRelayObjects_DoNothing;
            }
        } else if (pthis->unk_169 != 5) {
            Flags_UnsetSwitch(globalCtx, pthis->switchFlag);
            if (D_808A9508 & (1 << pthis->unk_169)) {
                Actor_Kill(thisx);
            } else {
                D_808A9508 |= (1 << pthis->unk_169);
                pthis->actionFunc = func_808A90F4;
            }
        } else {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
            pthis->actionFunc = func_808A91AC;
            thisx->world.pos.y += 120.0f;
            D_808A9508 |= 1;
        }
    }
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
}

void BgRelayObjects_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgRelayObjects* pthis = (BgRelayObjects*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    if ((pthis->dyna.actor.params == WINDMILL_ROTATING_GEAR) && (gSaveContext.cutsceneIndex < 0xFFF0)) {
        gSaveContext.eventChkInf[6] &= ~0x20;
    }
}

void func_808A90F4(BgRelayObjects* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if (pthis->timer != 0) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
            if (INV_CONTENT(ITEM_HOOKSHOT) != ITEM_NONE) {
                pthis->timer = 120;
            } else {
                pthis->timer = 160;
            }
        }
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 120.0f, 12.0f)) {
            pthis->actionFunc = func_808A91AC;
        }
    }
}

void func_808A91AC(BgRelayObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_169 != 5) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        func_8002F994(&pthis->dyna.actor, pthis->timer);
    }
    if ((pthis->timer == 0) || (pthis->unk_169 == globalCtx->roomCtx.curRoom.num)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_CLOSE);
        pthis->actionFunc = func_808A9234;
    }
}

void func_808A9234(BgRelayObjects* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.velocity.y += pthis->dyna.actor.gravity;
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.velocity.y)) {
        Rumble_Shake(pthis->dyna.actor.xyzDistToPlayerSq, 180, 20, 100);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
        if (pthis->unk_169 != globalCtx->roomCtx.curRoom.num) {
            Common_PlaySfx2(NA_SE_EN_PO_LAUGH);
            pthis->timer = 5;
            pthis->actionFunc = func_808A932C;
            return;
        }
        Flags_UnsetSwitch(globalCtx, pthis->switchFlag);
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
        if (globalCtx->roomCtx.curRoom.num == 4) {
            gSaveContext.timer1State = 0xF;
        }
        pthis->actionFunc = BgRelayObjects_DoNothing;
    }
}

void BgRelayObjects_DoNothing(BgRelayObjects* pthis, GlobalContext* globalCtx) {
}

void func_808A932C(BgRelayObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        if (!Player_InCsMode(globalCtx)) {
            Common_PlaySfx(NA_SE_OC_ABYSS);
            Gameplay_TriggerRespawn(globalCtx);
            pthis->actionFunc = BgRelayObjects_DoNothing;
        }
    }
}

void func_808A939C(BgRelayObjects* pthis, GlobalContext* globalCtx) {
    if (Flags_GetEnv(globalCtx, 5)) {
        gSaveContext.eventChkInf[6] |= 0x20;
    }
    if (gSaveContext.eventChkInf[6] & 0x20) {
        Math_ScaledStepToS(&pthis->dyna.actor.world.rot.y, 0x400, 8);
    } else {
        Math_ScaledStepToS(&pthis->dyna.actor.world.rot.y, 0x80, 8);
    }
    pthis->dyna.actor.shape.rot.y += pthis->dyna.actor.world.rot.y;
    func_800F436C(&pthis->dyna.actor.projectedPos, NA_SE_EV_WOOD_GEAR - SFX_FLAG,
                  ((pthis->dyna.actor.world.rot.y - 0x80) * (1.0f / 0x380)) + 1.0f);
}

void BgRelayObjects_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgRelayObjects* pthis = (BgRelayObjects*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgRelayObjects_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgRelayObjects* pthis = (BgRelayObjects*)thisx;

    if (pthis->dyna.actor.params == WINDMILL_ROTATING_GEAR) {
        Gfx_DrawDListOpa(globalCtx, gWindmillRotatingPlatformDL);
    } else {
        Gfx_DrawDListOpa(globalCtx, gDampeRaceDoorDL);
    }
}

void BgRelayObjects_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Relay_Objects_InitVars = {
        ACTOR_BG_RELAY_OBJECTS,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_RELAY_OBJECTS,
        sizeof(BgRelayObjects),
        (ActorFunc)BgRelayObjects_Init,
        (ActorFunc)BgRelayObjects_Destroy,
        (ActorFunc)BgRelayObjects_Update,
        (ActorFunc)BgRelayObjects_Draw,
        (ActorFunc)BgRelayObjects_Reset,
    };

    D_808A9508 = 0;

}

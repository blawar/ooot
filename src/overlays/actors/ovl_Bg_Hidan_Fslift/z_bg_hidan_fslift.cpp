#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_FSLIFT_Z_BG_HIDAN_FSLIFT_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_fslift.c
 * Overlay: ovl_Bg_Hidan_Fslift
 * Description: Hookshot Elevator
 */

#include "z_bg_hidan_fslift.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void BgHidanFslift_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFslift_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHidanFslift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFslift_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFslift_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80886FCC(BgHidanFslift* pthis, GlobalContext* globalCtx);
void func_8088706C(BgHidanFslift* pthis, GlobalContext* globalCtx);
void func_808870D8(BgHidanFslift* pthis, GlobalContext* globalCtx);

ActorInit Bg_Hidan_Fslift_InitVars = {
    ACTOR_BG_HIDAN_FSLIFT,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanFslift),
    (ActorFunc)BgHidanFslift_Init,
    (ActorFunc)BgHidanFslift_Destroy,
    (ActorFunc)BgHidanFslift_Update,
    (ActorFunc)BgHidanFslift_Draw,
    (ActorFunc)BgHidanFslift_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 350, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_STOP),
};

void BgHidanFslift_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad1;
    BgHidanFslift* pthis = (BgHidanFslift*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gFireTempleHookshotElevatorCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_OBJ_HSBLOCK,
                           pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y + 40.0f,
                           pthis->dyna.actor.world.pos.z + -28.0f, 0, 0, 0, 2) == NULL) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    pthis->actionFunc = func_80886FCC;
}

void func_80886F24(BgHidanFslift* pthis) {
    if (pthis->dyna.actor.child != NULL && pthis->dyna.actor.child->update != NULL) {
        pthis->dyna.actor.child->world.pos.x = pthis->dyna.actor.world.pos.x;
        pthis->dyna.actor.child->world.pos.y = pthis->dyna.actor.world.pos.y + 40.0f;
        pthis->dyna.actor.child->world.pos.z = pthis->dyna.actor.world.pos.z + -28.0f;
    } else {
        pthis->dyna.actor.child = NULL;
    }
}

void BgHidanFslift_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFslift* pthis = (BgHidanFslift*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80886FB4(BgHidanFslift* pthis) {
    pthis->timer = 40;
    pthis->actionFunc = func_80886FCC;
}

void func_80886FCC(BgHidanFslift* pthis, GlobalContext* globalCtx) {
    s32 heightBool;

    if (pthis->timer) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        heightBool = false;
        if ((pthis->dyna.actor.world.pos.y - pthis->dyna.actor.home.pos.y) < 0.5f) {
            heightBool = true;
        }
        if (func_80043590(&pthis->dyna) && (heightBool)) {
            pthis->actionFunc = func_808870D8;
        } else if (!heightBool) {
            pthis->actionFunc = func_8088706C;
        }
    }
}

void func_8088706C(BgHidanFslift* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 4.0f)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        func_80886FB4(pthis);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);
    }
    func_80886F24(pthis);
}

void func_808870D8(BgHidanFslift* pthis, GlobalContext* globalCtx) {
    if (func_80043590(&pthis->dyna)) {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 790.0f, 4.0f)) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
            func_80886FB4(pthis);
        } else {
            func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);
        }
    } else {
        func_80886FB4(pthis);
    }
    func_80886F24(pthis);
}

void BgHidanFslift_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFslift* pthis = (BgHidanFslift*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (func_8004356C(&pthis->dyna)) {
        if (pthis->unk_16A == 0) {
            pthis->unk_16A = 3;
        }
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FIRE_PLATFORM);
    } else if (!func_8004356C(&pthis->dyna)) {
        if (pthis->unk_16A != 0) {
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
        }
        pthis->unk_16A = 0;
    }
}

void BgHidanFslift_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gFireTempleHookshotElevatorDL);
}

void BgHidanFslift_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Hidan_Fslift_InitVars = {
        ACTOR_BG_HIDAN_FSLIFT,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HIDAN_OBJECTS,
        sizeof(BgHidanFslift),
        (ActorFunc)BgHidanFslift_Init,
        (ActorFunc)BgHidanFslift_Destroy,
        (ActorFunc)BgHidanFslift_Update,
        (ActorFunc)BgHidanFslift_Draw,
        (ActorFunc)BgHidanFslift_Reset,
    };

}

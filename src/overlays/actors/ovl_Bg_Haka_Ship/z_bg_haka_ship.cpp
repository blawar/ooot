#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_SHIP_Z_BG_HAKA_SHIP_C
#include "actor_common.h"
/*
 * File: z_bg_haka_ship.c
 * Overlay: ovl_Bg_Haka_Ship
 * Description: Shadow Temple Ship
 */

#include "z_bg_haka_ship.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/code_800F7260.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgHakaShip_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Draw(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_ChildUpdatePosition(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_WaitForSong(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_CutsceneStationary(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_Move(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_SetupCrash(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_CrashShake(BgHakaShip* pthis, GlobalContext* globalCtx);
void BgHakaShip_CrashFall(BgHakaShip* pthis, GlobalContext* globalCtx);

ActorInit Bg_Haka_Ship_InitVars = {
    ACTOR_BG_HAKA_SHIP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaShip),
    (ActorFunc)BgHakaShip_Init,
    (ActorFunc)BgHakaShip_Destroy,
    (ActorFunc)BgHakaShip_Update,
    (ActorFunc)BgHakaShip_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaShip_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* pthis = (BgHakaShip*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, 1);
    pthis->switchFlag = (thisx->params >> 8) & 0xFF;
    pthis->dyna.actor.params &= 0xFF;

    if (pthis->dyna.actor.params == 0) {
        CollisionHeader_GetVirtual(&object_haka_objects_Col_00E408, &colHeader);
        pthis->counter = 8;
        pthis->actionFunc = BgHakaShip_WaitForSong;
    } else {
        CollisionHeader_GetVirtual(&object_haka_objects_Col_00ED7C, &colHeader);
        pthis->actionFunc = BgHakaShip_ChildUpdatePosition;
    }
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.shape.rot.y - 0x4000;
    pthis->yOffset = 0;
    if (pthis->dyna.actor.params == 0 &&
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_HAKA_SHIP,
                           pthis->dyna.actor.world.pos.x + -10.0f, pthis->dyna.actor.world.pos.y + 82.0f,
                           pthis->dyna.actor.world.pos.z, 0, 0, 0, 1) == NULL) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgHakaShip_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* pthis = (BgHakaShip*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Audio_StopSfxByPos(&pthis->bellSoundPos);
}

void BgHakaShip_ChildUpdatePosition(BgHakaShip* pthis, GlobalContext* globalCtx) {
    Actor* parent = pthis->dyna.actor.parent;

    if (parent != NULL && parent->update != NULL) {
        pthis->dyna.actor.world.pos.x = parent->world.pos.x + -10.0f;
        pthis->dyna.actor.world.pos.y = parent->world.pos.y + 82.0f;
        pthis->dyna.actor.world.pos.z = parent->world.pos.z;
    } else {
        pthis->dyna.actor.parent = NULL;
    }
}

void BgHakaShip_WaitForSong(BgHakaShip* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if (pthis->counter) {
            pthis->counter--;
        }
        if (pthis->counter == 0) {
            pthis->counter = 130;
            pthis->actionFunc = BgHakaShip_CutsceneStationary;
            osSyncPrintf("シーン 外輪船 ...  アァクション！！\n");
            OnePointCutscene_Init(globalCtx, 3390, 999, &pthis->dyna.actor, MAIN_CAM);
        }
    }
}

void BgHakaShip_CutsceneStationary(BgHakaShip* pthis, GlobalContext* globalCtx) {
    if (pthis->counter) {
        pthis->counter--;
    }
    pthis->yOffset = sinf(pthis->counter * (M_PI / 25)) * 6144.0f;
    if (pthis->counter == 0) {
        pthis->counter = 50;
        pthis->actionFunc = BgHakaShip_Move;
    }
}

void BgHakaShip_Move(BgHakaShip* pthis, GlobalContext* globalCtx) {
    f32 distanceFromHome;
    Actor* child;

    if (pthis->counter) {
        pthis->counter--;
    }
    if (pthis->counter == 0) {
        pthis->counter = 50;
    }
    pthis->dyna.actor.world.pos.y = (sinf(pthis->counter * (M_PI / 25)) * 50.0f) + pthis->dyna.actor.home.pos.y;

    distanceFromHome = pthis->dyna.actor.home.pos.x - pthis->dyna.actor.world.pos.x;
    if (distanceFromHome > 7650.0f) {
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x - 7650.0f;
        pthis->dyna.actor.speedXZ = 0.0f;
    }
    if (distanceFromHome > 7600.0f && !Gameplay_InCsMode(globalCtx)) {
        pthis->counter = 40;
        pthis->dyna.actor.speedXZ = 0.0f;
        Message_StartTextbox(globalCtx, 0x5071, NULL);
        pthis->actionFunc = BgHakaShip_SetupCrash;
    } else {
        Math_StepToF(&pthis->dyna.actor.speedXZ, 4.0f, 0.2f);
    }
    child = pthis->dyna.actor.child;
    if (child != NULL && child->update != NULL) {
        child->shape.rot.z += ((655.0f / 13.0f) * pthis->dyna.actor.speedXZ);
    } else {
        pthis->dyna.actor.child = NULL;
    }
    pthis->yOffset = sinf(pthis->counter * (M_PI / 25)) * 6144.0f;
}

void BgHakaShip_SetupCrash(BgHakaShip* pthis, GlobalContext* globalCtx) {
    if (pthis->counter) {
        pthis->counter--;
    }
    if (pthis->counter == 0) {
        pthis->counter = 40;
        pthis->actionFunc = BgHakaShip_CrashShake;
    }
    Math_ScaledStepToS(&pthis->yOffset, 0, 128);
}

void BgHakaShip_CrashShake(BgHakaShip* pthis, GlobalContext* globalCtx) {
    if (pthis->counter != 0) {
        pthis->counter--;
    }
    pthis->dyna.actor.world.pos.y = pthis->counter % 4 * 3 - 6 + pthis->dyna.actor.home.pos.y;
    if (!pthis->counter) {
        pthis->dyna.actor.gravity = -1.0f;
        pthis->actionFunc = BgHakaShip_CrashFall;
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_BLOCKSINK - SFX_FLAG);
}

void BgHakaShip_CrashFall(BgHakaShip* pthis, GlobalContext* globalCtx) {
    Actor* child;

    if (pthis->dyna.actor.home.pos.y - pthis->dyna.actor.world.pos.y > 2000.0f) {
        Actor_Kill(&pthis->dyna.actor);
        child = pthis->dyna.actor.child;
        if (child != NULL && child->update != NULL) {
            Actor_Kill(child);
        }
    } else {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCKSINK - SFX_FLAG);
        if ((pthis->dyna.actor.home.pos.y - pthis->dyna.actor.world.pos.y > 500.0f) && func_8004356C(&pthis->dyna)) {
            Gameplay_TriggerVoidOut(globalCtx);
        }
    }
}

void BgHakaShip_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* pthis = (BgHakaShip*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->dyna.actor.params == 0) {
        Actor_MoveForward(&pthis->dyna.actor);
    }
}

void BgHakaShip_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* pthis = (BgHakaShip*)thisx;
    f32 angleTemp;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 528);
    func_80093D18(globalCtx->state.gfxCtx);
    if (pthis->dyna.actor.params == 0) {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 534),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_00D330);
        angleTemp = pthis->yOffset * (M_PI / 0x8000);
        Matrix_Translate(-3670.0f, 620.0f, 1150.0f, MTXMODE_APPLY);
        Matrix_RotateZ(angleTemp, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 547),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_005A70);
        Matrix_Translate(0.0f, 0.0f, -2300.0f, MTXMODE_APPLY);
        Matrix_RotateZ(-(2.0f * angleTemp), MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 556),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_005A70);
    } else {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 562),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_00E910);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 568);
    if (pthis->actionFunc == BgHakaShip_CutsceneStationary || pthis->actionFunc == BgHakaShip_Move) {
        s32 pad;
        Vec3f sp2C;

        sp2C.x = pthis->dyna.actor.world.pos.x + -367.0f;
        sp2C.y = pthis->dyna.actor.world.pos.y + 62.0f;
        sp2C.z = pthis->dyna.actor.world.pos.z;

        SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &sp2C, &pthis->bellSoundPos);
        func_80078914(&pthis->bellSoundPos, NA_SE_EV_SHIP_BELL - SFX_FLAG);
    }
}

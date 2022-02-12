#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_RAKKATENJO_Z_BG_MORI_RAKKATENJO_C
#include "actor_common.h"
/*
 * File: z_bg_mori_rakkatenjo.c
 * Overlay: ovl_Bg_Mori_Rakkatenjo
 * Description: Falling ceiling in Forest Temple
 */

#include "z_bg_mori_rakkatenjo.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgMoriRakkatenjo_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriRakkatenjo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriRakkatenjo_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriRakkatenjo_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriRakkatenjo_SetupWaitForMoriTex(BgMoriRakkatenjo* pthis);
void BgMoriRakkatenjo_WaitForMoriTex(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx);
void BgMoriRakkatenjo_SetupWait(BgMoriRakkatenjo* pthis);
void BgMoriRakkatenjo_Wait(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx);
void BgMoriRakkatenjo_SetupFall(BgMoriRakkatenjo* pthis);
void BgMoriRakkatenjo_Fall(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx);
void BgMoriRakkatenjo_SetupRest(BgMoriRakkatenjo* pthis);
void BgMoriRakkatenjo_Rest(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx);
void BgMoriRakkatenjo_SetupRise(BgMoriRakkatenjo* pthis);
void BgMoriRakkatenjo_Rise(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx);

static s16 sCamSetting = 0;

ActorInit Bg_Mori_Rakkatenjo_InitVars = {
    ACTOR_BG_MORI_RAKKATENJO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriRakkatenjo),
    (ActorFunc)BgMoriRakkatenjo_Init,
    (ActorFunc)BgMoriRakkatenjo_Destroy,
    (ActorFunc)BgMoriRakkatenjo_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(gravity, -1, ICHAIN_CONTINUE),
    ICHAIN_F32(minVelocityY, -11, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgMoriRakkatenjo_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriRakkatenjo* pthis = (BgMoriRakkatenjo*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    // "Forest Temple obj. Falling Ceiling"
    osSyncPrintf("森の神殿 obj. 落下天井 (home posY %f)\n", pthis->dyna.actor.home.pos.y);
    if ((fabsf(1991.0f - pthis->dyna.actor.home.pos.x) > 0.001f) ||
        (fabsf(683.0f - pthis->dyna.actor.home.pos.y) > 0.001f) ||
        (fabsf(-2520.0f - pthis->dyna.actor.home.pos.z) > 0.001f)) {
        // "The set position has been changed. Let's fix the program."
        osSyncPrintf("Warning : セット位置が変更されています。プログラムを修正しましょう。\n");
    }
    if (pthis->dyna.actor.home.rot.y != 0x8000) {
        // "The set Angle has changed. Let's fix the program."
        osSyncPrintf("Warning : セット Angle が変更されています。プログラムを修正しましょう。\n");
    }
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        // "Forest Temple obj Falling Ceiling Bank Danger!"
        osSyncPrintf("Error : 森の神殿 obj 落下天井 バンク危険！(%s %d)\n", "../z_bg_mori_rakkatenjo.c", 205);
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    CollisionHeader_GetVirtual(&gMoriRakkatenjoCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    BgMoriRakkatenjo_SetupWaitForMoriTex(pthis);
    sCamSetting = 0;
}

void BgMoriRakkatenjo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriRakkatenjo* pthis = (BgMoriRakkatenjo*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

s32 BgMoriRakkatenjo_IsLinkUnder(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    Vec3f* pos = &GET_PLAYER(globalCtx)->actor.world.pos;

    return (-3300.0f < pos->z) && (pos->z < -1840.0f) && (1791.0f < pos->x) && (pos->x < 2191.0f);
}

s32 BgMoriRakkatenjo_IsLinkClose(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    Vec3f* pos = &GET_PLAYER(globalCtx)->actor.world.pos;

    return (-3360.0f < pos->z) && (pos->z < -1840.0f) && (1791.0f < pos->x) && (pos->x < 2191.0f);
}

void BgMoriRakkatenjo_SetupWaitForMoriTex(BgMoriRakkatenjo* pthis) {
    pthis->actionFunc = BgMoriRakkatenjo_WaitForMoriTex;
}

void BgMoriRakkatenjo_WaitForMoriTex(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        BgMoriRakkatenjo_SetupWait(pthis);
        pthis->dyna.actor.draw = BgMoriRakkatenjo_Draw;
    }
}

void BgMoriRakkatenjo_SetupWait(BgMoriRakkatenjo* pthis) {
    pthis->timer = (pthis->fallCount > 0) ? 100 : 21;
    pthis->dyna.actor.world.pos.y = 683.0f;
    pthis->actionFunc = BgMoriRakkatenjo_Wait;
}

void BgMoriRakkatenjo_Wait(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    if (pthis->fallCount == 0) {
        if (BgMoriRakkatenjo_IsLinkClose(pthis, globalCtx) || (pthis->timer < 20)) {
            if (pthis->timer <= 0) {
                BgMoriRakkatenjo_SetupFall(pthis);
            }
        } else {
            pthis->timer = 21;
        }
    } else {
        if (BgMoriRakkatenjo_IsLinkUnder(pthis, globalCtx) || (pthis->timer < 20)) {
            if (pthis->timer <= 0) {
                BgMoriRakkatenjo_SetupFall(pthis);
            }
        } else {
            pthis->timer = 100;
        }
    }
    if (pthis->timer < 20) {
        func_800788CC(NA_SE_EV_BLOCKSINK - SFX_FLAG);
    }
}

void BgMoriRakkatenjo_SetupFall(BgMoriRakkatenjo* pthis) {
    pthis->actionFunc = BgMoriRakkatenjo_Fall;
    pthis->bounceCount = 0;
    pthis->dyna.actor.velocity.y = 0.0f;
}

void BgMoriRakkatenjo_Fall(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    static f32 bounceVel[] = { 4.0f, 1.5f, 0.4f, 0.1f };
    s32 pad;
    Actor* thisx = &pthis->dyna.actor;
    s32 quake;

    Actor_MoveForward(thisx);
    if ((thisx->velocity.y < 0.0f) && (thisx->world.pos.y <= 403.0f)) {
        if (pthis->bounceCount >= ARRAY_COUNT(bounceVel)) {
            BgMoriRakkatenjo_SetupRest(pthis);
        } else {
            if (pthis->bounceCount == 0) {
                pthis->fallCount++;
                func_800788CC(NA_SE_EV_STONE_BOUND);
                func_800AA000(SQ(thisx->yDistToPlayer), 0xFF, 0x14, 0x96);
            }
            thisx->world.pos.y =
                403.0f - (thisx->world.pos.y - 403.0f) * bounceVel[pthis->bounceCount] / fabsf(thisx->velocity.y);
            thisx->velocity.y = bounceVel[pthis->bounceCount];
            pthis->bounceCount++;
            quake = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
            Quake_SetSpeed(quake, 50000);
            Quake_SetQuakeValues(quake, 5, 0, 0, 0);
            Quake_SetCountdown(quake, 5);
        }
    }
}

void BgMoriRakkatenjo_SetupRest(BgMoriRakkatenjo* pthis) {
    pthis->actionFunc = BgMoriRakkatenjo_Rest;
    pthis->dyna.actor.world.pos.y = 403.0f;
    pthis->timer = 20;
}

void BgMoriRakkatenjo_Rest(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    if (pthis->timer <= 0) {
        BgMoriRakkatenjo_SetupRise(pthis);
    }
}

void BgMoriRakkatenjo_SetupRise(BgMoriRakkatenjo* pthis) {
    pthis->actionFunc = BgMoriRakkatenjo_Rise;
    pthis->dyna.actor.velocity.y = -0.1f;
}

void BgMoriRakkatenjo_Rise(BgMoriRakkatenjo* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->dyna.actor.velocity.y, 5.0f, 0.06f, 0.1f, 0.0f);
    pthis->dyna.actor.world.pos.y += pthis->dyna.actor.velocity.y;
    if (pthis->dyna.actor.world.pos.y >= 683.0f) {
        BgMoriRakkatenjo_SetupWait(pthis);
    }
}

void BgMoriRakkatenjo_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriRakkatenjo* pthis = (BgMoriRakkatenjo*)thisx;

    if (pthis->timer > 0) {
        pthis->timer--;
    }
    pthis->actionFunc(pthis, globalCtx);
    if (BgMoriRakkatenjo_IsLinkUnder(pthis, globalCtx)) {
        if (sCamSetting == CAM_SET_NONE) {
            osSyncPrintf("camera changed (mori rakka tenjyo) ... \n");
            sCamSetting = globalCtx->cameraPtrs[MAIN_CAM]->setting;
            Camera_SetCameraData(globalCtx->cameraPtrs[MAIN_CAM], 1, &pthis->dyna.actor, NULL, 0, 0, 0);
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FOREST_BIRDS_EYE);
        }
    } else if (sCamSetting != CAM_SET_NONE) {
        osSyncPrintf("camera changed (previous) ... \n");
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON1);
        sCamSetting = 0;
    }
}

void BgMoriRakkatenjo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriRakkatenjo* pthis = (BgMoriRakkatenjo*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_rakkatenjo.c", 497);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_rakkatenjo.c", 502),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gMoriRakkatenjoDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_rakkatenjo.c", 506);
}

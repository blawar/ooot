#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_BIGST_Z_BG_MORI_BIGST_C
#include "actor_common.h"
/*
 * File: z_bg_mori_bigst.c
 * Overlay: ovl_Bg_Mori_Bigst
 * Description: Forest Temple falling platform and Stalfos fight
 */

#include "z_bg_mori_bigst.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void BgMoriBigst_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriBigst_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriBigst_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriBigst_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriBigst_SetupWaitForMoriTex(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_WaitForMoriTex(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupNoop(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupStalfosFight(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_StalfosFight(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupFall(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_Fall(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupLanding(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_Landing(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupStalfosPairFight(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_StalfosPairFight(BgMoriBigst* pthis, GlobalContext* globalCtx);
void BgMoriBigst_SetupDone(BgMoriBigst* pthis, GlobalContext* globalCtx);

ActorInit Bg_Mori_Bigst_InitVars = {
    ACTOR_BG_MORI_BIGST,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriBigst),
    (ActorFunc)BgMoriBigst_Init,
    (ActorFunc)BgMoriBigst_Destroy,
    (ActorFunc)BgMoriBigst_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 3000, ICHAIN_CONTINUE),      ICHAIN_F32(uncullZoneScale, 3000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 3000, ICHAIN_CONTINUE),     ICHAIN_F32_DIV1000(gravity, -500, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(minVelocityY, -12000, ICHAIN_CONTINUE), ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgMoriBigst_SetupAction(BgMoriBigst* pthis, BgMoriBigstActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgMoriBigst_InitDynapoly(BgMoriBigst* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG login failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_mori_bigst.c", 190,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgMoriBigst_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriBigst* pthis = (BgMoriBigst*)thisx;

    // "mori (bigST.keyceiling)"
    osSyncPrintf("mori (bigST.鍵型天井)(arg : %04x)(sw %d)(noE %d)(roomC %d)(playerPosY %f)\n", pthis->dyna.actor.params,
                 Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F),
                 Flags_GetTempClear(globalCtx, pthis->dyna.actor.room), Flags_GetClear(globalCtx, pthis->dyna.actor.room),
                 GET_PLAYER(globalCtx)->actor.world.pos.y);
    BgMoriBigst_InitDynapoly(pthis, globalCtx, &gMoriBigstCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        // "【Big Stalfos key ceiling】 bank danger!"
        osSyncPrintf("【ビッグスタルフォス鍵型天井】 バンク危険！\n");
        osSyncPrintf("%s %d\n", "../z_bg_mori_bigst.c", 234);
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
    } else {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + 270.0f;
    }
    Actor_SetFocus(&pthis->dyna.actor, 50.0f);
    BgMoriBigst_SetupWaitForMoriTex(pthis, globalCtx);
}

void BgMoriBigst_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriBigst* pthis = (BgMoriBigst*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgMoriBigst_SetupWaitForMoriTex(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    BgMoriBigst_SetupAction(pthis, BgMoriBigst_WaitForMoriTex);
}

void BgMoriBigst_WaitForMoriTex(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        thisx->draw = BgMoriBigst_Draw;
        if (Flags_GetClear(globalCtx, thisx->room) && (GET_PLAYER(globalCtx)->actor.world.pos.y > 700.0f)) {
            if (Flags_GetSwitch(globalCtx, (thisx->params >> 8) & 0x3F)) {
                BgMoriBigst_SetupDone(pthis, globalCtx);
            } else {
                BgMoriBigst_SetupStalfosFight(pthis, globalCtx);
            }
        } else {
            BgMoriBigst_SetupNoop(pthis, globalCtx);
        }
    }
}

void BgMoriBigst_SetupNoop(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    BgMoriBigst_SetupAction(pthis, NULL);
}

void BgMoriBigst_SetupStalfosFight(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    Actor* stalfos;

    BgMoriBigst_SetupAction(pthis, BgMoriBigst_StalfosFight);
    Flags_UnsetClear(globalCtx, pthis->dyna.actor.room);
    stalfos = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_TEST, 209.0f, 827.0f,
                                 -3320.0f, 0, 0, 0, 1);
    if (stalfos != NULL) {
        pthis->dyna.actor.child = NULL;
        pthis->dyna.actor.home.rot.z++;
    } else {
        // "Second Stalfos failure"
        osSyncPrintf("Warning : 第２スタルフォス発生失敗\n");
    }
    Flags_SetClear(globalCtx, pthis->dyna.actor.room);
}

void BgMoriBigst_StalfosFight(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->dyna.actor.home.rot.z == 0) &&
        ((pthis->dyna.actor.home.pos.y - 5.0f) <= GET_PLAYER(globalCtx)->actor.world.pos.y)) {
        BgMoriBigst_SetupFall(pthis, globalCtx);
        OnePointCutscene_Init(globalCtx, 3220, 72, &pthis->dyna.actor, MAIN_CAM);
    }
}

void BgMoriBigst_SetupFall(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    BgMoriBigst_SetupAction(pthis, BgMoriBigst_Fall);
}

void BgMoriBigst_Fall(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    Actor_MoveForward(&pthis->dyna.actor);
    if (pthis->dyna.actor.world.pos.y <= pthis->dyna.actor.home.pos.y) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
        BgMoriBigst_SetupLanding(pthis, globalCtx);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
        OnePointCutscene_Init(globalCtx, 1020, 8, &pthis->dyna.actor, MAIN_CAM);
        func_8002DF38(globalCtx, NULL, 0x3C);
    }
}

void BgMoriBigst_SetupLanding(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 quake;

    BgMoriBigst_SetupAction(pthis, BgMoriBigst_Landing);
    pthis->waitTimer = 18;
    quake = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
    Quake_SetSpeed(quake, 25000);
    Quake_SetQuakeValues(quake, 5, 0, 0, 0);
    Quake_SetCountdown(quake, 16);
}

void BgMoriBigst_Landing(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    if (pthis->waitTimer <= 0) {
        BgMoriBigst_SetupStalfosPairFight(pthis, globalCtx);
    }
}

void BgMoriBigst_SetupStalfosPairFight(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    Actor* stalfos1;
    Actor* stalfos2;

    BgMoriBigst_SetupAction(pthis, BgMoriBigst_StalfosPairFight);
    Flags_UnsetClear(globalCtx, pthis->dyna.actor.room);
    stalfos1 = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_TEST, 70.0f, 827.0f,
                                  -3383.0f, 0, 0, 0, 5);
    if (stalfos1 != NULL) {
        pthis->dyna.actor.child = NULL;
        pthis->dyna.actor.home.rot.z++;
    } else {
        // "Warning: 3-1 Stalfos failure"
        osSyncPrintf("Warning : 第３-1スタルフォス発生失敗\n");
    }
    stalfos2 = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_TEST, 170.0f, 827.0f,
                                  -3260.0f, 0, 0, 0, 5);
    if (stalfos2 != NULL) {
        pthis->dyna.actor.child = NULL;
        pthis->dyna.actor.home.rot.z++;
    } else {
        // "Warning: 3-2 Stalfos failure"
        osSyncPrintf("Warning : 第３-2スタルフォス発生失敗\n");
    }
    Flags_SetClear(globalCtx, pthis->dyna.actor.room);
}

void BgMoriBigst_StalfosPairFight(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    if ((pthis->dyna.actor.home.rot.z == 0) && !Player_InCsMode(globalCtx)) {
        Flags_SetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F);
        BgMoriBigst_SetupDone(pthis, globalCtx);
    }
}

void BgMoriBigst_SetupDone(BgMoriBigst* pthis, GlobalContext* globalCtx) {
    BgMoriBigst_SetupAction(pthis, NULL);
}

void BgMoriBigst_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriBigst* pthis = (BgMoriBigst*)thisx;

    Actor_SetFocus(&pthis->dyna.actor, 50.0f);
    if (pthis->waitTimer > 0) {
        pthis->waitTimer--;
    }
    if (func_80043590(&pthis->dyna)) {
        func_80074CE8(globalCtx, 6);
    }
    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgMoriBigst_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriBigst* pthis = (BgMoriBigst*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_bigst.c", 541);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_bigst.c", 548),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gMoriBigstDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_bigst.c", 553);
}

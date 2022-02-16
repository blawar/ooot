#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SYATEKI_ITM_Z_EN_SYATEKI_ITM_C
#include "actor_common.h"
#include "z_en_syateki_itm.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Syateki_Man/z_en_syateki_man.h"
#include "overlays/actors/ovl_En_Ex_Ruppy/z_en_ex_ruppy.h"
#include "overlays/actors/ovl_En_G_Switch/z_en_g_switch.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"

#define FLAGS ACTOR_FLAG_4


void EnSyatekiItm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiItm_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnSyatekiItm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiItm_Update(Actor* thisx, GlobalContext* globalCtx);

void EnSyatekiItm_Idle(EnSyatekiItm* pthis, GlobalContext* globalCtx);
void EnSyatekiItm_StartRound(EnSyatekiItm* pthis, GlobalContext* globalCtx);
void EnSyatekiItm_SpawnTargets(EnSyatekiItm* pthis, GlobalContext* globalCtx);
void EnSyatekiItm_CheckTargets(EnSyatekiItm* pthis, GlobalContext* globalCtx);
void EnSyatekiItm_CleanupGame(EnSyatekiItm* pthis, GlobalContext* globalCtx);
void EnSyatekiItm_EndGame(EnSyatekiItm* pthis, GlobalContext* globalCtx);

ActorInit En_Syateki_Itm_InitVars = {
    ACTOR_EN_SYATEKI_ITM,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnSyatekiItm),
    (ActorFunc)EnSyatekiItm_Init,
    (ActorFunc)EnSyatekiItm_Destroy,
    (ActorFunc)EnSyatekiItm_Update,
    NULL,
    (ActorFunc)EnSyatekiItm_Reset,
};

static Vec3f sGreenAppearHome = { 0.0f, -10.0f, -270.0f };
static Vec3f sBlueSeqHome1 = { -220.0f, 66.0f, -320.0f };
static Vec3f sBlueSeqHome2 = { 260.0f, 66.0f, -320.0f };
static Vec3f sGreenThrowHome = { 0.0f, -10.0f, -270.0f };
static Vec3f sBlueSimulHome1 = { -220.0f, 66.0f, -320.0f };
static Vec3f sBlueSimulHome2 = { 260.0f, 66.0f, -320.0f };
static Vec3f sRedLeftHome1 = { 260.0f, 100.0f, -320.0f };
static Vec3f sRedLeftHome2 = { 360.0f, 100.0f, -320.0f };
static Vec3f sRedRightHome1 = { -230.0f, 94.0f, -360.0f };
static Vec3f sRedRightHome2 = { -400.0f, 94.0f, -360.0f };
static Vec3f sGreenAppearFinal = { 0.0f, 53.0f, -270.0f };
static Vec3f sBlueSeqFinal1 = { -60.0f, 63.0f, -320.0f };
static Vec3f sBlueSeqFinal2 = { 60.0f, 63.0f, -320.0f };
static Vec3f sGreenThrowFinal = { 0.0f, 0.0f, 0.0f };
static Vec3f sBlueSimulFinal1 = { -60.0f, 63.0f, -320.0f };
static Vec3f sBlueSimulFinal2 = { 60.0f, 63.0f, -320.0f };
static Vec3f sRedLeftFinal1 = { -230.0f, 0.0f, 0.0f };
static Vec3f sRedLeftFinal2 = { -230.0f, 0.0f, 0.0f };
static Vec3f sRedRightFinal1 = { 260.0f, 0.0f, 0.0f };
static Vec3f sRedRightFinal2 = { 260.0f, 0.0f, 0.0f };
static s16 sTargetColors[] = { 0, 1, 0, 1, 2, 2 };
static s16 sRupeeTypes[] = { 0, 1, 1, 0, 1, 1, 4, 4, 4, 4 };
static Vec3f sRupeePos[] = {
    { -40.0f, 0.0f, -90.0f }, { -20.0f, 0.0f, -90.0f }, { 0.0f, 0.0f, -90.0f },   { 20.0f, 0.0f, -90.0f },
    { 40.0f, 0.0f, -90.0f },  { -40.0f, 0.0f, -60.0f }, { -20.0f, 0.0f, -60.0f }, { 0.0f, 0.0f, -60.0f },
    { 20.0f, 0.0f, -60.0f },  { 40.0f, 0.0f, -60.0f },
};

void EnSyatekiItm_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnSyatekiItm* pthis = (EnSyatekiItm*)thisx;
    s32 i;

    pthis->man = (EnSyatekiMan*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_SYATEKI_MAN,
                                                  140.0f, 0.0f, 255.0f, 0, -0x4000, 0, 0);
    if (pthis->man == NULL) {
        // "Spawn error"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ エラー原 ☆☆☆☆ \n" VT_RST);
        Actor_Kill(&pthis->actor);
        return;
    }
    for (i = 0; i < 10; i++) {
        pthis->markers[i] =
            (EnExRuppy*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_RUPPY,
                                           sRupeePos[i].x, sRupeePos[i].y, sRupeePos[i].z, 0, 0, 0, 4);
        if (pthis->markers[i] == NULL) {
            // "Second spawn error"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ エラー原セカンド ☆☆☆☆ \n" VT_RST);
            Actor_Kill(&pthis->actor);
            return;
        }
        pthis->markers[i]->colorIdx = sRupeeTypes[i];
    }
    pthis->actionFunc = EnSyatekiItm_Idle;
}

void EnSyatekiItm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnSyatekiItm_Idle(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    s32 i;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->signal == ENSYATEKI_START) {
        player->actor.world.pos.x = -12.0f;
        player->actor.world.pos.y = 20.0f;
        player->actor.world.pos.z = 182.0f;
        player->currentYaw = player->actor.world.rot.y = player->actor.shape.rot.y = 0x7F03;
        player->actor.world.rot.x = player->actor.shape.rot.x = player->actor.world.rot.z = player->actor.shape.rot.z =
            0;
        func_8008EF44(globalCtx, 15);
        pthis->roundNum = pthis->hitCount = 0;
        for (i = 0; i < 6; i++) {
            pthis->roundFlags[i] = false;
        }
        for (i = 0; i < 10; i++) {
            pthis->markers[i]->galleryFlag = false;
        }
        pthis->actionFunc = EnSyatekiItm_StartRound;
    }
}

void EnSyatekiItm_StartRound(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 j;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->unkTimer == 0) {
        if (LINK_IS_ADULT) {
            for (i = 0, j = 0; i < SYATEKI_ROUND_MAX; i++) {
                if (pthis->roundFlags[i]) {
                    j++;
                }
            }
            if (j >= SYATEKI_ROUND_MAX) {
                player->actor.freezeTimer = 10;
                pthis->signal = ENSYATEKI_END;
                pthis->actionFunc = EnSyatekiItm_CleanupGame;
                return;
            }
            i = Rand_ZeroFloat(5.99f);
            while (pthis->roundFlags[i]) {
                i = Rand_ZeroFloat(5.99f);
                if (1) {}
            }
            pthis->roundNum = i + 1;
            pthis->roundFlags[i] = true;
        } else {
            pthis->roundNum++;
            if (pthis->roundNum > SYATEKI_ROUND_MAX) {
                player->actor.freezeTimer = 10;
                pthis->signal = ENSYATEKI_END;
                pthis->actionFunc = EnSyatekiItm_CleanupGame;
                return;
            }
        }

        pthis->timer = (pthis->roundNum == 1) ? 50 : 30;

        func_80078884(NA_SE_SY_FOUND);
        pthis->actionFunc = EnSyatekiItm_SpawnTargets;
    }
}

void EnSyatekiItm_SpawnTargets(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    s32 i;
    s32 roundIdx;

    if (globalCtx->shootingGalleryStatus == -1) {
        player->actor.freezeTimer = 10;
        pthis->signal = ENSYATEKI_END;
        pthis->actionFunc = EnSyatekiItm_CleanupGame;
        return;
    }
    if (pthis->timer == 0) {
        for (i = 0; i < 2; i++) {
            Math_Vec3f_Copy(&pthis->targetHome[i], &zeroVec);
            Math_Vec3f_Copy(&pthis->targetFinal[i], &zeroVec);
            pthis->targets[i] = NULL;
        }
        pthis->numTargets = 2;
        pthis->curMarkers[0] = pthis->curMarkers[1] = NULL;
        roundIdx = pthis->roundNum - 1;

        switch (roundIdx) {
            case SYATEKI_ROUND_GREEN_APPEAR:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sGreenAppearHome);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sGreenAppearFinal);
                pthis->curMarkers[0] = pthis->markers[0];
                pthis->numTargets = 1;
                break;
            case SYATEKI_ROUND_BLUE_SEQUENTIAL:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sBlueSeqHome1);
                Math_Vec3f_Copy(&pthis->targetHome[1], &sBlueSeqHome2);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sBlueSeqFinal1);
                Math_Vec3f_Copy(&pthis->targetFinal[1], &sBlueSeqFinal2);
                pthis->curMarkers[0] = pthis->markers[1];
                pthis->curMarkers[1] = pthis->markers[2];
                break;
            case SYATEKI_ROUND_GREEN_THROW:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sGreenThrowHome);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sGreenThrowFinal);
                pthis->curMarkers[0] = pthis->markers[3];
                pthis->numTargets = 1;
                break;
            case SYATEKI_ROUND_BLUE_SIMUL:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sBlueSimulHome1);
                Math_Vec3f_Copy(&pthis->targetHome[1], &sBlueSimulHome2);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sBlueSimulFinal1);
                Math_Vec3f_Copy(&pthis->targetFinal[1], &sBlueSimulFinal2);
                pthis->curMarkers[0] = pthis->markers[4];
                pthis->curMarkers[1] = pthis->markers[5];
                break;
            case SYATEKI_ROUND_RED_LEFT:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sRedLeftHome1);
                Math_Vec3f_Copy(&pthis->targetHome[1], &sRedLeftHome2);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sRedLeftFinal1);
                Math_Vec3f_Copy(&pthis->targetFinal[1], &sRedLeftFinal2);
                pthis->curMarkers[0] = pthis->markers[6];
                pthis->curMarkers[1] = pthis->markers[7];
                break;
            case SYATEKI_ROUND_RED_RIGHT:
                Math_Vec3f_Copy(&pthis->targetHome[0], &sRedRightHome1);
                Math_Vec3f_Copy(&pthis->targetHome[1], &sRedRightHome2);
                Math_Vec3f_Copy(&pthis->targetFinal[0], &sRedRightFinal1);
                Math_Vec3f_Copy(&pthis->targetFinal[1], &sRedRightFinal2);
                pthis->curMarkers[0] = pthis->markers[8];
                pthis->curMarkers[1] = pthis->markers[9];
                break;
        }

        for (i = 0; i < pthis->numTargets; i++) {
            pthis->targets[i] = (EnGSwitch*)Actor_SpawnAsChild(
                &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_G_SWITCH, pthis->targetHome[i].x,
                pthis->targetHome[i].y, pthis->targetHome[i].z, 0, 0, 0, (ENGSWITCH_TARGET_RUPEE << 0xC) | 0x3F);
            if (pthis->targets[i] == NULL) {
                // "Rupee spawn error"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ルピーでエラー原 ☆☆☆☆ \n" VT_RST);
                Actor_Kill(&pthis->actor);
                return;
            }
            pthis->targets[i]->index = i;
            pthis->targets[i]->colorIdx = sTargetColors[roundIdx];
            Math_Vec3f_Copy(&pthis->targets[i]->targetPos, &pthis->targetFinal[i]);
            switch (roundIdx) {
                case SYATEKI_ROUND_BLUE_SEQUENTIAL:
                    if (i == 1) {
                        pthis->targets[i]->delayTimer = 60;
                    }
                    break;
                case SYATEKI_ROUND_GREEN_THROW:
                    pthis->targets[i]->actor.velocity.y = 15.0f;
                    pthis->targets[i]->actor.gravity = -1.0f;
                    pthis->targets[i]->moveMode = GSWITCH_THROW;
                    break;
                case SYATEKI_ROUND_RED_LEFT:
                    pthis->targets[i]->actor.velocity.x = -5.0f;
                    pthis->targets[i]->moveMode = GSWITCH_LEFT;
                    break;
                case SYATEKI_ROUND_RED_RIGHT:
                    pthis->targets[i]->actor.velocity.x = 7.0f;
                    pthis->targets[i]->moveMode = GSWITCH_RIGHT;
                    break;
            }
        }
        pthis->targetState[0] = pthis->targetState[1] = ENSYATEKIHIT_NONE;
        pthis->actionFunc = EnSyatekiItm_CheckTargets;
    }
}

void EnSyatekiItm_CheckTargets(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 i;
    s16 j;

    if (globalCtx->shootingGalleryStatus == -1) {
        player->actor.freezeTimer = 10;
        pthis->signal = ENSYATEKI_END;
        pthis->actionFunc = EnSyatekiItm_CleanupGame;
    } else {
        for (i = 0, j = 0; i < 2; i++) {
            if (pthis->targetState[i] != ENSYATEKIHIT_NONE) {
                if (pthis->targetState[i] == ENSYATEKIHIT_HIT) {
                    pthis->curMarkers[i]->galleryFlag = true;
                }
                j++;
            }
        }
        if (j == pthis->numTargets) {
            pthis->actionFunc = EnSyatekiItm_StartRound;
        }
    }
}

void EnSyatekiItm_CleanupGame(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((pthis->targetState[i] == ENSYATEKIHIT_NONE) && (pthis->targets[i] != NULL)) {
            Actor_Kill(&pthis->targets[i]->actor);
        }
    }
    pthis->actionFunc = EnSyatekiItm_EndGame;
}

void EnSyatekiItm_EndGame(EnSyatekiItm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    player->actor.freezeTimer = 10;
    if (pthis->signal == ENSYATEKI_RESULTS) {
        pthis->signal = ENSYATEKI_NONE;
        pthis->actionFunc = EnSyatekiItm_Idle;
    }
    if (pthis->signal == ENSYATEKI_START) {
        // "1 frame attack and defense!"
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ １フレームの攻防！ ☆☆☆☆ \n" VT_RST);
        pthis->signal = ENSYATEKI_NONE;
        pthis->actionFunc = EnSyatekiItm_Idle;
    }
}

void EnSyatekiItm_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSyatekiItm* pthis = (EnSyatekiItm*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->unkTimer != 0) {
        pthis->unkTimer--;
    }
}

void EnSyatekiItm_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Syateki_Itm_InitVars = {
        ACTOR_EN_SYATEKI_ITM,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnSyatekiItm),
        (ActorFunc)EnSyatekiItm_Init,
        (ActorFunc)EnSyatekiItm_Destroy,
        (ActorFunc)EnSyatekiItm_Update,
        NULL,
        (ActorFunc)EnSyatekiItm_Reset,
    };

    sGreenAppearHome = { 0.0f, -10.0f, -270.0f };

    sBlueSeqHome1 = { -220.0f, 66.0f, -320.0f };

    sBlueSeqHome2 = { 260.0f, 66.0f, -320.0f };

    sGreenThrowHome = { 0.0f, -10.0f, -270.0f };

    sBlueSimulHome1 = { -220.0f, 66.0f, -320.0f };

    sBlueSimulHome2 = { 260.0f, 66.0f, -320.0f };

    sRedLeftHome1 = { 260.0f, 100.0f, -320.0f };

    sRedLeftHome2 = { 360.0f, 100.0f, -320.0f };

    sRedRightHome1 = { -230.0f, 94.0f, -360.0f };

    sRedRightHome2 = { -400.0f, 94.0f, -360.0f };

    sGreenAppearFinal = { 0.0f, 53.0f, -270.0f };

    sBlueSeqFinal1 = { -60.0f, 63.0f, -320.0f };

    sBlueSeqFinal2 = { 60.0f, 63.0f, -320.0f };

    sGreenThrowFinal = { 0.0f, 0.0f, 0.0f };

    sBlueSimulFinal1 = { -60.0f, 63.0f, -320.0f };

    sBlueSimulFinal2 = { 60.0f, 63.0f, -320.0f };

    sRedLeftFinal1 = { -230.0f, 0.0f, 0.0f };

    sRedLeftFinal2 = { -230.0f, 0.0f, 0.0f };

    sRedRightFinal1 = { 260.0f, 0.0f, 0.0f };

    sRedRightFinal2 = { 260.0f, 0.0f, 0.0f };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BOWL_WALL_Z_BG_BOWL_WALL_C
#include "actor_common.h"
/*
 * File: z_bg_bowl_wall.c
 * Overlay: Bg_Bowl_Wall
 * Description: Bombchu Bowling Alley Wall
 */

#include "z_bg_bowl_wall.h"
#include "overlays/actors/ovl_En_Wall_Tubo/z_en_wall_tubo.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "objects/object_bowl/object_bowl.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgBowlWall_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBowlWall_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBowlWall_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgBowlWall_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgBowlWall_SpawnBullseyes(BgBowlWall* pthis, GlobalContext* globalCtx);
void BgBowlWall_WaitForHit(BgBowlWall* pthis, GlobalContext* globalCtx);
void BgBowlWall_FallDoEffects(BgBowlWall* pthis, GlobalContext* globalCtx);
void BgBowlWall_FinishFall(BgBowlWall* pthis, GlobalContext* globalCtx);
void BgBowlWall_Reset(BgBowlWall* pthis, GlobalContext* globalCtx);

ActorInit Bg_Bowl_Wall_InitVars = {
    ACTOR_BG_BOWL_WALL,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_BOWL,
    sizeof(BgBowlWall),
    (ActorFunc)BgBowlWall_Init,
    (ActorFunc)BgBowlWall_Destroy,
    (ActorFunc)BgBowlWall_Update,
    (ActorFunc)BgBowlWall_Draw,
};

static Vec3f sBullseyeOffset[] = {
    { 0.0f, 210.0f, -20.0f },
    { 0.0f, 170.0f, -20.0f },
    { -170.0f, 0.0f, -20.0f },
    { 170.0f, 0.0f, -20.0f },
};

static s16 sTargetRot[] = { 0x0000, 0x0000, 0x3FFF, -0x3FFF };

void BgBowlWall_Init(Actor* pthisx, GlobalContext* globalCtx) {
    BgBowlWall* pthis = (BgBowlWall*)pthisx;
    s32 pad1;
    s32 pad2;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);

    if (pthis->dyna.actor.params == 0) {
        CollisionHeader_GetVirtual(&gBowlingFirstAndFinalRoundCol, &colHeader);
    } else {
        CollisionHeader_GetVirtual(&gBowlingSecondRoundCol, &colHeader);
    }

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->initPos = pthis->dyna.actor.world.pos;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ ボーリングおじゃま壁発生 ☆☆☆☆☆ %d\n" VT_RST, pthis->dyna.actor.params);
    pthis->actionFunc = BgBowlWall_SpawnBullseyes;
    pthis->dyna.actor.scale.x = pthis->dyna.actor.scale.y = pthis->dyna.actor.scale.z = 1.0f;
}

void BgBowlWall_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgBowlWall* pthis = (BgBowlWall*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgBowlWall_SpawnBullseyes(BgBowlWall* pthis, GlobalContext* globalCtx) {
    s32 pad;
    EnWallTubo* bullseye;
    Actor* lookForGirl;
    s16 type;

    type = pthis->dyna.actor.params;
    if (type != 0) {
        type += (s16)Rand_ZeroFloat(2.99f);
        pthis->dyna.actor.shape.rot.z = pthis->dyna.actor.world.rot.z = sTargetRot[type];
        osSyncPrintf("\n\n");
    }
    pthis->bullseyeCenter.x = sBullseyeOffset[type].x + pthis->dyna.actor.world.pos.x;
    pthis->bullseyeCenter.y = sBullseyeOffset[type].y + pthis->dyna.actor.world.pos.y;
    pthis->bullseyeCenter.z = sBullseyeOffset[type].z + pthis->dyna.actor.world.pos.z;
    if (1) {}
    bullseye = (EnWallTubo*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_WALL_TUBO,
                                               pthis->bullseyeCenter.x, pthis->bullseyeCenter.y, pthis->bullseyeCenter.z,
                                               0, 0, 0, pthis->dyna.actor.params);
    if (bullseye != NULL) {
        bullseye->explosionCenter = pthis->bullseyeCenter;
        if (type != 0) {
            bullseye->explosionCenter = pthis->bullseyeCenter = pthis->dyna.actor.world.pos;
        }
        if (pthis->chuGirl == NULL) {
            lookForGirl = globalCtx->actorCtx.actorLists[ACTORCAT_NPC].head;
            while (lookForGirl != NULL) {
                if (lookForGirl->id != ACTOR_EN_BOM_BOWL_MAN) {
                    lookForGirl = lookForGirl->next;
                } else {
                    pthis->chuGirl = (EnBomBowlMan*)lookForGirl;
                    break;
                }
            }
        }
        pthis->actionFunc = BgBowlWall_WaitForHit;
    }
}

void BgBowlWall_WaitForHit(BgBowlWall* pthis, GlobalContext* globalCtx) {
    if (pthis->isHit) {
        pthis->actionFunc = BgBowlWall_FallDoEffects;
    }
}

void BgBowlWall_FallDoEffects(BgBowlWall* pthis, GlobalContext* globalCtx) {
    s16 pad;
    Vec3f effectAccel = { 0.0f, 0.1f, 0.0f };
    Vec3f effectVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f effectPos;
    s16 quakeIndex;
    s32 wallFallen;
    s32 i;

    wallFallen = false;

    if (pthis->dyna.actor.params == 0) { // wall collapses backwards
        Math_SmoothStepToS(&pthis->dyna.actor.shape.rot.x, -0x3E80, 3, 500, 0);
        pthis->dyna.actor.world.rot.x = pthis->dyna.actor.shape.rot.x;
        if (pthis->dyna.actor.shape.rot.x < -0x3C1E) {
            wallFallen = true;
        }
    } else { // wall slides downwards
        Math_ApproachF(&pthis->dyna.actor.world.pos.y, pthis->initPos.y - 450.0f, 0.3f, 10.0f);
        if (pthis->dyna.actor.world.pos.y < (pthis->initPos.y - 400.0f)) {
            wallFallen = true;
        }
    }

    if (wallFallen) {
        for (i = 0; i < 15; i++) {
            effectPos.x = Rand_CenteredFloat(300.0f) + pthis->bullseyeCenter.x;
            effectPos.y = -100.0f;
            effectPos.z = Rand_CenteredFloat(400.0f) + pthis->bullseyeCenter.z;
            EffectSsBomb2_SpawnLayered(globalCtx, &effectPos, &effectVelocity, &effectAccel, 100, 30);
            effectPos.y = -50.0f;
            EffectSsHahen_SpawnBurst(globalCtx, &effectPos, 10.0f, 0, 50, 15, 3, HAHEN_OBJECT_DEFAULT, 10, NULL);
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_IT_BOMB_EXPLOSION);
        }
        quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 1);
        Quake_SetSpeed(quakeIndex, 0x7FFF);
        Quake_SetQuakeValues(quakeIndex, 300, 0, 0, 0);
        Quake_SetCountdown(quakeIndex, 30);
        pthis->timer = 20;
        pthis->actionFunc = BgBowlWall_FinishFall;
    }
}

void BgBowlWall_FinishFall(BgBowlWall* pthis, GlobalContext* globalCtx) {
    if (pthis->timer >= 2) {
        if (pthis->dyna.actor.params == 0) {
            Math_SmoothStepToS(&pthis->dyna.actor.shape.rot.x, -0x3E80, 1, 200, 0);
        } else {
            Math_ApproachF(&pthis->dyna.actor.world.pos.y, pthis->initPos.y - 450.0f, 0.3f, 10.0f);
        }
    } else if (pthis->timer == 1) {
        pthis->dyna.actor.world.rot.x = pthis->dyna.actor.shape.rot.x = 0;
        pthis->dyna.actor.world.pos.y = pthis->initPos.y - 450.0f;
        pthis->chuGirl->wallStatus[pthis->dyna.actor.params] = 2;
        pthis->actionFunc = BgBowlWall_Reset;
    }
}

void BgBowlWall_Reset(BgBowlWall* pthis, GlobalContext* globalCtx) {
    if (pthis->chuGirl->wallStatus[pthis->dyna.actor.params] != 2) {
        Math_ApproachF(&pthis->dyna.actor.world.pos.y, pthis->initPos.y, 0.3f, 50.0f);
        if (fabsf(pthis->dyna.actor.world.pos.y - pthis->initPos.y) <= 10.0f) {
            pthis->dyna.actor.world.pos.y = pthis->initPos.y;
            pthis->isHit = false;
            pthis->actionFunc = BgBowlWall_SpawnBullseyes;
        }
    }
}

void BgBowlWall_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgBowlWall* pthis = (BgBowlWall*)pthisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actionFunc(pthis, globalCtx);
}

void BgBowlWall_Draw(Actor* pthisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgBowlWall* pthis = (BgBowlWall*)pthisx;
    const auto& frames = globalCtx->state.frames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 441);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x8,
               Gfx_TexScroll(globalCtx->state.gfxCtx, 0, (frames * -2).whole(), 16, 16));
    gDPPipeSync(POLY_OPA_DISP++);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 453),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (pthis->dyna.actor.params == 0) {
        gSPDisplayList(POLY_OPA_DISP++, gBowlingRound1WallDL);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, gBowlingRound2WallDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_bowl_wall.c", 464);
}

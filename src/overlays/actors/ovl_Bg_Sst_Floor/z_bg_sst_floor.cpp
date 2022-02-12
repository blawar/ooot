#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SST_FLOOR_Z_BG_SST_FLOOR_C
#include "actor_common.h"
/*
 * File: z_bg_sst_floor.c
 * Overlay: ovl_Bg_Sst_Floor
 * Description: Bongo Bongo's drum
 */

#include "z_bg_sst_floor.h"
#include "objects/object_sst/object_sst.h"
#include "def/code_80043480.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSstFloor_Init(BgSstFloor* pthis, GlobalContext* globalCtx);
void BgSstFloor_Destroy(BgSstFloor* pthis, GlobalContext* globalCtx);
void BgSstFloor_Update(BgSstFloor* pthis, GlobalContext* globalCtx);
void BgSstFloor_Draw(BgSstFloor* pthis, GlobalContext* globalCtx);

static s32 sUnkValues[] = { 0, 0, 0 }; // Unused, probably a zero vector

ActorInit Bg_Sst_Floor_InitVars = {
    ACTOR_BG_SST_FLOOR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SST,
    sizeof(BgSstFloor),
    (ActorFunc)BgSstFloor_Init,
    (ActorFunc)BgSstFloor_Destroy,
    (ActorFunc)BgSstFloor_Update,
    (ActorFunc)BgSstFloor_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale.x, 100, ICHAIN_STOP),
};

void BgSstFloor_Init(BgSstFloor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSstFloor* pthis = (BgSstFloor*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gBongoDrumCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void BgSstFloor_Destroy(BgSstFloor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSstFloor* pthis = (BgSstFloor*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgSstFloor_Update(BgSstFloor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSstFloor* pthis = (BgSstFloor*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    CollisionHeader* colHeader = &gBongoDrumCol;

    colHeader->vtxList = colHeader->vtxList;

    if (1) {}

    if (func_80043590(&pthis->dyna) && (pthis->dyna.actor.yDistToPlayer < 1000.0f)) {
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BOSS_BONGO);
    } else {
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
    }

    if (func_8004356C(&pthis->dyna) && (player->fallDistance > 1000.0f)) {
        pthis->dyna.actor.params = 1;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EN_SHADEST_TAIKO_HIGH);
    }

    if (pthis->dyna.actor.params == BONGOFLOOR_HIT) {
        Actor* item00 = globalCtx->actorCtx.actorLists[ACTORCAT_MISC].head;
        f32 distFromRim;
        f32 xzDist;

        pthis->drumAmp = 80;
        pthis->dyna.actor.params = BONGOFLOOR_REST;
        pthis->drumPhase = 28;

        if (func_8004356C(&pthis->dyna) && !(player->stateFlags1 & 0x6000)) {
            distFromRim = 600.0f - pthis->dyna.actor.xzDistToPlayer;
            if (distFromRim > 0.0f) {
                if (distFromRim > 350.0f) {
                    distFromRim = 350.0f;
                }
                player->actor.bgCheckFlags &= ~1;
                player->actor.velocity.y = 9.0f * distFromRim * (1.0f / 350.0f);
            }
        }

        while (item00 != NULL) {
            if ((item00->id == ACTOR_EN_ITEM00) && (item00->world.pos.y == 0.0f)) {
                xzDist = Actor_WorldDistXZToActor(&pthis->dyna.actor, item00);
                distFromRim = 600.0f - xzDist;
                if (xzDist < 600.0f) {
                    if (distFromRim > 350.0f) {
                        distFromRim = 350.0f;
                    }
                    item00->bgCheckFlags &= ~3;
                    item00->velocity.y = 9.0f * distFromRim * (1.0f / 350.0f);
                }
            }
            item00 = item00->next;
        }
    }
    pthis->drumHeight = sinf(pthis->drumPhase * (M_PI / 2)) * (-pthis->drumAmp);
    Math_StepToS(&pthis->drumAmp, 0, 5);

    colHeader->vtxList[1].y = colHeader->vtxList[0].y = colHeader->vtxList[2].y = colHeader->vtxList[3].y =
        colHeader->vtxList[4].y = colHeader->vtxList[7].y = colHeader->vtxList[9].y = colHeader->vtxList[11].y =
            colHeader->vtxList[13].y = pthis->dyna.actor.home.pos.y + pthis->drumHeight;

    if (pthis->drumPhase != 0) {
        pthis->drumPhase--;
    }
    if (1) {}
    func_8003EE6C(globalCtx, &globalCtx->colCtx.dyna);
}

void BgSstFloor_Draw(BgSstFloor* thisx, GlobalContext* globalCtx) {
    BgSstFloor* pthis = (BgSstFloor*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_sst_floor.c", 277);
    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_Scale(1.0f, pthis->drumHeight * -0.0025f, 1.0f, MTXMODE_APPLY);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_sst_floor.c", 283),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gBongoDrumDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_sst_floor.c", 287);
}

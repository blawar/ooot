#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT06_OBJECTS_Z_BG_SPOT06_OBJECTS_C
#include "actor_common.h"
/*
 * File: z_bg_spot06_objects.c
 * Overlay: ovl_Bg_Spot06_Objects
 * Description: Lake Hylia Objects
 */

#include "z_bg_spot06_objects.h"
#include "objects/object_spot06_objects/object_spot06_objects.h"
#include "def/code_80043480.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_9

typedef enum {
    /* 0x0 */ LHO_WATER_TEMPLE_ENTRACE_GATE,
    /* 0x1 */ LHO_WATER_TEMPLE_ENTRANCE_LOCK,
    /* 0x2 */ LHO_WATER_PLANE,
    /* 0x3 */ LHO_ICE_BLOCK
} LakeHyliaObjectsType;

typedef enum {
    /* 0x0 */ LHWB_GERUDO_VALLEY_RIVER_UPPER, // entrance from Gerudo Valley
    /* 0x1 */ LHWB_GERUDO_VALLEY_RIVER_LOWER, // river flowing from Gerudo Valley
    /* 0x2 */ LHWB_MAIN_1,                    // main water box
    /* 0x3 */ LHWB_MAIN_2                     // extension of main water box
} LakeHyliaWaterBoxIndices;

// Lake Hylia water plane levels
#define WATER_LEVEL_RAISED (-1313)
#define WATER_LEVEL_RIVER_RAISED (WATER_LEVEL_RAISED + 200)
#define WATER_LEVEL_LOWERED (WATER_LEVEL_RAISED - 680)
#define WATER_LEVEL_RIVER_LOWERED (WATER_LEVEL_RIVER_RAISED - 80)

void BgSpot06Objects_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot06Objects_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot06Objects_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot06Objects_Draw(Actor* thisx, GlobalContext* globalCtx);
void BgSpot06Objects_GateWaitForSwitch(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_GateWaitToOpen(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_GateOpen(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_DoNothing(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_LockWait(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_LockPullOutward(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_LockSwimToSurface(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_LockFloat(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_WaterPlaneCutsceneWait(BgSpot06Objects* pthis, GlobalContext* globalCtx);
void BgSpot06Objects_WaterPlaneCutsceneRise(BgSpot06Objects* pthis, GlobalContext* globalCtx);

ActorInit Bg_Spot06_Objects_InitVars = {
    ACTOR_BG_SPOT06_OBJECTS,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT06_OBJECTS,
    sizeof(BgSpot06Objects),
    (ActorFunc)BgSpot06Objects_Init,
    (ActorFunc)BgSpot06Objects_Destroy,
    (ActorFunc)BgSpot06Objects_Update,
    (ActorFunc)BgSpot06Objects_Draw,
};

static ColliderJntSphElementInit sJntSphItemsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000080, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 1, { { 0, 0, -160 }, 18 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphItemsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static InitChainEntry sInitChainWaterPlane[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgSpot06Objects_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot06Objects* pthis = (BgSpot06Objects*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    pthis->switchFlag = thisx->params & 0xFF;
    thisx->params = (thisx->params >> 8) & 0xFF;

    osSyncPrintf("spot06 obj nthisx->arg_data=[%d]", thisx->params);

    switch (thisx->params) {
        case LHO_WATER_TEMPLE_ENTRACE_GATE:
            Actor_ProcessInitChain(thisx, sInitChain);
            DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
            CollisionHeader_GetVirtual(&gLakeHyliaWaterTempleGateCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);

            if (LINK_IS_ADULT && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                thisx->world.pos.y = thisx->home.pos.y + 120.0f;
                pthis->actionFunc = BgSpot06Objects_DoNothing;

            } else {
                pthis->actionFunc = BgSpot06Objects_GateWaitForSwitch;
            }

            break;
        case LHO_WATER_TEMPLE_ENTRANCE_LOCK:
            Actor_ProcessInitChain(thisx, sInitChain);
            Collider_InitJntSph(globalCtx, &pthis->collider);
            Collider_SetJntSph(globalCtx, &pthis->collider, thisx, &sJntSphInit, pthis->colliderItem);

            if (LINK_IS_ADULT && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                if (!(gSaveContext.eventChkInf[6] & 0x200)) {
                    thisx->home.pos.y = thisx->world.pos.y = WATER_LEVEL_LOWERED;
                } else {
                    thisx->home.pos.y = thisx->world.pos.y = WATER_LEVEL_RAISED;
                }

                pthis->actionFunc = BgSpot06Objects_LockFloat;
                thisx->world.pos.z -= 100.0f;
                thisx->home.pos.z = thisx->world.pos.z + 16.0f;
                pthis->collider.elements[0].dim.worldSphere.radius =
                    pthis->collider.elements[0].dim.modelSphere.radius * 2;
                pthis->collider.elements[0].dim.worldSphere.center.z = thisx->world.pos.z + 16.0f;
            } else {
                pthis->actionFunc = BgSpot06Objects_LockWait;
                pthis->collider.elements[0].dim.worldSphere.radius = pthis->collider.elements[0].dim.modelSphere.radius;
                pthis->collider.elements[0].dim.worldSphere.center.z = thisx->world.pos.z;
            }

            pthis->collider.elements[0].dim.worldSphere.center.x = thisx->world.pos.x;
            pthis->collider.elements[0].dim.worldSphere.center.y = thisx->world.pos.y;
            thisx->colChkInfo.mass = MASS_IMMOVABLE;
            break;
        case LHO_WATER_PLANE:
            Actor_ProcessInitChain(thisx, sInitChainWaterPlane);
            thisx->flags = ACTOR_FLAG_4 | ACTOR_FLAG_5;

            if (LINK_IS_ADULT && !(gSaveContext.eventChkInf[6] & 0x200)) {
                if (gSaveContext.sceneSetupIndex < 4) {
                    pthis->lakeHyliaWaterLevel = -681.0f;
                    globalCtx->colCtx.colHeader->waterBoxes[LHWB_GERUDO_VALLEY_RIVER_LOWER].ySurface =
                        WATER_LEVEL_RIVER_LOWERED;
                    globalCtx->colCtx.colHeader->waterBoxes[LHWB_GERUDO_VALLEY_RIVER_LOWER].zMin -= 50;
                    globalCtx->colCtx.colHeader->waterBoxes[LHWB_MAIN_1].ySurface = WATER_LEVEL_LOWERED;
                    globalCtx->colCtx.colHeader->waterBoxes[LHWB_MAIN_2].ySurface = WATER_LEVEL_LOWERED;
                    pthis->actionFunc = BgSpot06Objects_DoNothing;
                } else {
                    thisx->world.pos.y = pthis->lakeHyliaWaterLevel = -681.0f;
                    thisx->world.pos.y += WATER_LEVEL_RAISED;
                    pthis->actionFunc = BgSpot06Objects_WaterPlaneCutsceneWait;
                }
            } else {
                pthis->lakeHyliaWaterLevel = 0.0f;
                pthis->actionFunc = BgSpot06Objects_DoNothing;
            }
            break;
        case LHO_ICE_BLOCK:
            Actor_ProcessInitChain(thisx, sInitChain);
            DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
            CollisionHeader_GetVirtual(&gLakeHyliaZoraShortcutIceblockCol, &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
            pthis->actionFunc = BgSpot06Objects_DoNothing;

            if (!LINK_IS_ADULT) {
                Actor_Kill(thisx);
            }
            break;
    }
}

void BgSpot06Objects_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot06Objects* pthis = (BgSpot06Objects*)thisx;

    switch (pthis->dyna.actor.params) {
        case LHO_WATER_TEMPLE_ENTRACE_GATE:
        case LHO_ICE_BLOCK:
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            break;
        case LHO_WATER_TEMPLE_ENTRANCE_LOCK:
            Collider_DestroyJntSph(globalCtx, &pthis->collider);
            break;
        case LHO_WATER_PLANE:
            break;
    }
}

/**
 * Water Temple entrance gate effect functions
 */
void BgSpot06Objects_GateSpawnBubbles(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    Vec3f sp34;
    f32 tmp;

    if ((globalCtx->gameplayFrames % 3) == 0) {
        tmp = Rand_CenteredFloat(160.0f);
        sp34.x = (Math_SinS(pthis->dyna.actor.shape.rot.y + 0x4000) * tmp) + pthis->dyna.actor.world.pos.x;
        sp34.y = pthis->dyna.actor.world.pos.y;
        sp34.z = (Math_CosS(pthis->dyna.actor.shape.rot.y + 0x4000) * tmp) + pthis->dyna.actor.world.pos.z;
        EffectSsBubble_Spawn(globalCtx, &sp34, 50.0f, 70.0f, 10.0f, (Rand_ZeroOne() * 0.05f) + 0.175f);
    }
}

/**
 * This is where the gate waits for the switch to be set by the fish shaped lock.
 */
void BgSpot06Objects_GateWaitForSwitch(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    s32 i;

    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        pthis->timer = 100;
        pthis->dyna.actor.world.pos.y += 3.0f;
        pthis->actionFunc = BgSpot06Objects_GateWaitToOpen;

        for (i = 0; i < 15; i++) {
            BgSpot06Objects_GateSpawnBubbles(pthis, globalCtx);
        }
    }
}

/**
 * This is where the gate waits a few frames before rising after the switch is set.
 */
void BgSpot06Objects_GateWaitToOpen(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        pthis->actionFunc = BgSpot06Objects_GateOpen;
    }
}

/**
 * This is where the gate finally rises upward.
 */
void BgSpot06Objects_GateOpen(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    BgSpot06Objects_GateSpawnBubbles(pthis, globalCtx);

    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 120.0f, 0.6f)) {
        pthis->actionFunc = BgSpot06Objects_DoNothing;
        pthis->timer = 0;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_STOP);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
    }
}

void BgSpot06Objects_DoNothing(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
}

/**
 * Fish shaped lock effect functions
 */
void BgSpot06Objects_LockSpawnWaterRipples(BgSpot06Objects* pthis, GlobalContext* globalCtx, s32 flag) {
    if (flag || !(globalCtx->gameplayFrames % 7)) {
        EffectSsGRipple_Spawn(globalCtx, &pthis->dyna.actor.home.pos, 300, 700, 0);
    }
}

void BgSpot06Objects_LockSpawnBubbles(BgSpot06Objects* pthis, GlobalContext* globalCtx, s32 flag) {
    if (!(globalCtx->gameplayFrames % 7) || flag) {
        EffectSsBubble_Spawn(globalCtx, &pthis->dyna.actor.world.pos, 0.0f, 40.0f, 30.0f,
                             (Rand_ZeroOne() * 0.05f) + 0.175f);
    }
}

/**
 * This is where the fish shaped lock waits to be pulled out by the hookshot. Once it does it will spawn bubbles.
 */
void BgSpot06Objects_LockWait(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 i;
    s32 pad2;
    Vec3f effectPos;
    f32 sin;
    f32 cos;

    if (pthis->collider.base.acFlags & 2) {
        pthis->timer = 130;
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
        sin = Math_SinS(pthis->dyna.actor.world.rot.y);
        cos = Math_CosS(pthis->dyna.actor.world.rot.y);
        pthis->dyna.actor.world.pos.x += (3.0f * sin);
        pthis->dyna.actor.world.pos.z += (3.0f * cos);

        for (i = 0; i < 20; i++) {
            BgSpot06Objects_LockSpawnBubbles(pthis, globalCtx, 1);
        }

        effectPos.x = pthis->dyna.actor.world.pos.x + (5.0f * sin);
        effectPos.y = pthis->dyna.actor.world.pos.y;
        effectPos.z = pthis->dyna.actor.world.pos.z + (5.0f * cos);

        for (i = 0; i < 3; i++) {
            EffectSsBubble_Spawn(globalCtx, &effectPos, 0.0f, 20.0f, 20.0f, (Rand_ZeroOne() * 0.1f) + 0.7f);
        }

        EffectSsGSplash_Spawn(globalCtx, &pthis->dyna.actor.world.pos, NULL, NULL, 1, 700);
        pthis->collider.elements->dim.worldSphere.radius = 45;
        pthis->actionFunc = BgSpot06Objects_LockPullOutward;
        Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        OnePointCutscene_Init(globalCtx, 4120, 170, &pthis->dyna.actor, MAIN_CAM);
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

/**
 * Once the fish shaped lock is pulled out from the Hookshot it will move outward.
 */
void BgSpot06Objects_LockPullOutward(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.world.pos.x += (0.3f * Math_SinS(pthis->dyna.actor.world.rot.y));
    pthis->dyna.actor.world.pos.z += (0.3f * Math_CosS(pthis->dyna.actor.world.rot.y));
    BgSpot06Objects_LockSpawnBubbles(pthis, globalCtx, 0);

    if (pthis->timer == 0) {
        pthis->dyna.actor.velocity.y = 0.5f;
        pthis->dyna.actor.flags &= ~ACTOR_FLAG_13;

        pthis->actionFunc = BgSpot06Objects_LockSwimToSurface;
    }
}

/**
 * After being pulled all the way out the fish shaped lock will rise to the surface, creating bubbles in the water as it
 * does so.
 */
void BgSpot06Objects_LockSwimToSurface(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    f32 cos;
    f32 pad;

    pthis->dyna.actor.world.pos.y += pthis->dyna.actor.velocity.y;

    if (pthis->dyna.actor.velocity.y <= 0.0f) {
        cos = Math_CosS(pthis->dyna.actor.shape.rot.x) * 4.3f;
        pthis->dyna.actor.world.pos.x += (cos * Math_SinS(pthis->dyna.actor.shape.rot.y));
        pthis->dyna.actor.world.pos.z += (cos * Math_CosS(pthis->dyna.actor.shape.rot.y));
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.world.pos.y - 1.3f;
        BgSpot06Objects_LockSpawnWaterRipples(pthis, globalCtx, 0);

        if (Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.x, 0, 0x260) != 0) {
            pthis->dyna.actor.home.pos.x =
                pthis->dyna.actor.world.pos.x - (Math_SinS(pthis->dyna.actor.shape.rot.y) * 16.0f);
            pthis->dyna.actor.home.pos.z =
                pthis->dyna.actor.world.pos.z - (Math_CosS(pthis->dyna.actor.shape.rot.y) * 16.0f);
            pthis->dyna.actor.world.pos.y = -1993.0f;
            pthis->timer = 32;
            pthis->dyna.actor.flags &= ~ACTOR_FLAG_4;
            pthis->collider.elements[0].dim.worldSphere.radius = pthis->collider.elements[0].dim.modelSphere.radius * 2;
            pthis->actionFunc = BgSpot06Objects_LockFloat;
        }
    } else {
        if (pthis->dyna.actor.world.pos.y >= -1973.0f) {
            pthis->dyna.actor.velocity.y = 0.0f;
            BgSpot06Objects_LockSpawnWaterRipples(pthis, globalCtx, 1);
            EffectSsGSplash_Spawn(globalCtx, &pthis->dyna.actor.home.pos, NULL, NULL, 1, 700);
        } else if (pthis->dyna.actor.shape.rot.x == -0x4000) {
            pthis->dyna.actor.velocity.y += 0.02f;
            pthis->dyna.actor.world.pos.x = Rand_CenteredFloat(1.0f) + pthis->dyna.actor.home.pos.x;
            pthis->dyna.actor.world.pos.z = Rand_CenteredFloat(1.0f) + pthis->dyna.actor.home.pos.z;
            pthis->dyna.actor.velocity.y =
                (pthis->dyna.actor.velocity.y > 10.0f) ? (10.0f) : (pthis->dyna.actor.velocity.y);
            BgSpot06Objects_LockSpawnBubbles(pthis, globalCtx, 0);
        } else {
            BgSpot06Objects_LockSpawnBubbles(pthis, globalCtx, 0);

            if (Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.x, -0x4000, 0x30)) {
                pthis->dyna.actor.home.pos.x = pthis->dyna.actor.world.pos.x;
                pthis->dyna.actor.home.pos.y = -1993.0f;
                pthis->dyna.actor.home.pos.z = pthis->dyna.actor.world.pos.z;
            }
        }
    }
}

/**
 * Once the fish shaped lock finishes rising to the surface it will float and create ripples in the water every few
 * frames.
 */
void BgSpot06Objects_LockFloat(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    BgSpot06Objects_LockSpawnWaterRipples(pthis, globalCtx, 0);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.world.pos.y = (2.0f * sinf(pthis->timer * (M_PI / 16.0f))) + pthis->dyna.actor.home.pos.y;

    if (pthis->timer == 0) {
        pthis->timer = 32;
    }
}

void BgSpot06Objects_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot06Objects* pthis = (BgSpot06Objects*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (thisx->params == LHO_WATER_TEMPLE_ENTRANCE_LOCK) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

/**
 * Draw the Lake Hylia water plane, and scroll its texture
 */
void BgSpot06Objects_DrawLakeHyliaWater(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    s32 pad;
    const auto& gameplayFrames = globalCtx->state.frames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot06_objects.c", 844);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot06_objects.c", 850),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -gameplayFrames.whole(), gameplayFrames.whole(), 32, 32, 1, gameplayFrames.whole(),
                                gameplayFrames.whole(), 32, 32));
    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -gameplayFrames.whole(), (gameplayFrames * 6).whole(), 32, 32, 1,
                                gameplayFrames.whole(), (gameplayFrames * 6).whole(), 32, 32));

    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);

    if ((pthis->lakeHyliaWaterLevel < -680.0f) && (gSaveContext.sceneSetupIndex < 4)) {
        gSPDisplayList(POLY_XLU_DISP++, gLakeHyliaLowWaterDL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, gLakeHyliaHighWaterDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot06_objects.c", 879);
}

void BgSpot06Objects_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot06Objects* pthis = (BgSpot06Objects*)thisx;

    switch (pthis->dyna.actor.params) {
        case LHO_WATER_TEMPLE_ENTRACE_GATE:
            Gfx_DrawDListOpa(globalCtx, gLakeHyliaWaterTempleGateDL);
            break;
        case LHO_WATER_TEMPLE_ENTRANCE_LOCK:
            Gfx_DrawDListOpa(globalCtx, gLakeHyliaWaterTempleKeyDL);

            if (pthis->actionFunc == BgSpot06Objects_LockSwimToSurface) {
                Collider_UpdateSpheres(1, &pthis->collider);
            }
            break;
        case LHO_WATER_PLANE:
            BgSpot06Objects_DrawLakeHyliaWater(pthis, globalCtx);
            break;
        case LHO_ICE_BLOCK:
            Gfx_DrawDListOpa(globalCtx, gLakeHyliaZoraShortcutIceblockDL);
            break;
    }
}

/**
 * This is where the Lake Hylia water plane waits for the cutscene to set the water risen flag after the Water Temple is
 * cleared.
 */
void BgSpot06Objects_WaterPlaneCutsceneWait(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.eventChkInf[6] & 0x200) {
        pthis->actionFunc = BgSpot06Objects_WaterPlaneCutsceneRise;
    }
}

/**
 * This is where the Lake Hylia water plane rises in the cutscene after the Water Temple is cleared.
 */
void BgSpot06Objects_WaterPlaneCutsceneRise(BgSpot06Objects* pthis, GlobalContext* globalCtx) {
    s32 pad;

    pthis->dyna.actor.world.pos.y = pthis->lakeHyliaWaterLevel + WATER_LEVEL_RAISED;

    if (pthis->lakeHyliaWaterLevel >= 0.0001f) {
        pthis->dyna.actor.world.pos.y = WATER_LEVEL_RAISED;
        pthis->actionFunc = BgSpot06Objects_DoNothing;
    } else {
        Math_SmoothStepToF(&pthis->lakeHyliaWaterLevel, 1.0f, 0.1f, 1.0f, 0.001f);
        globalCtx->colCtx.colHeader->waterBoxes[LHWB_GERUDO_VALLEY_RIVER_LOWER].ySurface = WATER_LEVEL_RIVER_LOWERED;
        globalCtx->colCtx.colHeader->waterBoxes[LHWB_MAIN_1].ySurface = pthis->dyna.actor.world.pos.y;
        globalCtx->colCtx.colHeader->waterBoxes[LHWB_MAIN_2].ySurface = pthis->dyna.actor.world.pos.y;
    }

    func_8002F948(&pthis->dyna.actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
}

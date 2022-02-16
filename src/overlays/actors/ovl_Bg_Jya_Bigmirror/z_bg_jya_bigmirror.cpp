#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_BIGMIRROR_Z_BG_JYA_BIGMIRROR_C
#include "actor_common.h"
/*
 * File: z_bg_jya_bigmirror.c
 * Overlay: ovl_Bg_Jya_Bigmirror
 * Description: Ceiling mirror and puzzle in Spirit Temple top rooms
 */

#include "z_bg_jya_bigmirror.h"
#include "objects/object_jya_obj/object_jya_obj.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgJyaBigmirror_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaBigmirror_Draw(Actor* thisx, GlobalContext* globalCtx);

static u8 cobraPuzzleFlags_22[] = { BIGMIR_PUZZLE_COBRA1_SOLVED, BIGMIR_PUZZLE_COBRA2_SOLVED };

static s16 sMirRayParamss_24[] = { 0x0005, 0x0007, 0x0008 };

static Vec3f sMirRayPoss_24[] = {
    { 60.0f, 1802.0f, -1102.0f },
    { -560.0f, 1800.0f, -310.0f },
    { 60.0f, 1800.0f, -310.0f },
};

static Vec3s D_80893F4C_28 = { 0, 0, 0 };


static u8 sIsSpawned = false;

ActorInit Bg_Jya_Bigmirror_InitVars = {
    ACTOR_BG_JYA_BIGMIRROR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_JYA_OBJ,
    sizeof(BgJyaBigmirror),
    (ActorFunc)BgJyaBigmirror_Init,
    (ActorFunc)BgJyaBigmirror_Destroy,
    (ActorFunc)BgJyaBigmirror_Update,
    (ActorFunc)BgJyaBigmirror_Draw,
    (ActorFunc)BgJyaBigmirror_Reset,
}; 

static BigMirrorDataEntry sCobraSpawnData[] = {
    { { -560.0f, 1743.0f, -310.0f }, 0xFF01, 0x4000, 0x8000 },
    { { 60.0f, 1743.0f, -310.0f }, 0xFF02, 0x8000, 0xA000 },
};

void BgJyaBigmirror_SetRoomFlag(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;

    pthis->puzzleFlags &=
        ~(BIGMIR_PUZZLE_IN_STATUE_ROOM | BIGMIR_PUZZLE_IN_1ST_TOP_ROOM | BIGMIR_PUZZLE_IN_2ND_TOP_ROOM);
    if (globalCtx->roomCtx.curRoom.num == 5) {
        pthis->puzzleFlags |= BIGMIR_PUZZLE_IN_STATUE_ROOM;
    } else if (globalCtx->roomCtx.curRoom.num == 0x19) {
        pthis->puzzleFlags |= BIGMIR_PUZZLE_IN_1ST_TOP_ROOM;
    } else if (globalCtx->roomCtx.curRoom.num == 0x1A) {
        pthis->puzzleFlags |= BIGMIR_PUZZLE_IN_2ND_TOP_ROOM;
    }
}

void BgJyaBigmirror_HandleCobra(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;
    BigMirrorDataEntry* curSpawnData;
    BigmirrorCobra* curCobraInfo;
    s32 i;

    if (pthis->puzzleFlags & (BIGMIR_PUZZLE_IN_1ST_TOP_ROOM | BIGMIR_PUZZLE_IN_2ND_TOP_ROOM)) {
        for (i = 0; i < 2; i++) {
            curSpawnData = &sCobraSpawnData[i];
            curCobraInfo = &pthis->cobraInfo[i];
            if (curCobraInfo->cobra != NULL) {
                curCobraInfo->rotY = curCobraInfo->cobra->dyna.actor.shape.rot.y;

                if (curCobraInfo->rotY == curSpawnData->solvedRotY) {
                    pthis->puzzleFlags |= cobraPuzzleFlags_22[i];
                } else {
                    pthis->puzzleFlags &= ~cobraPuzzleFlags_22[i];
                }

                if (curCobraInfo->cobra->dyna.actor.update == NULL) {
                    // "Cobra deleted"
                    osSyncPrintf("Error : コブラ削除された (%s %d)\n", "../z_bg_jya_bigmirror.c", 203);
                }
            } else {
                curCobraInfo->cobra = (BgJyaCobra*)Actor_SpawnAsChild(
                    &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BG_JYA_COBRA, curSpawnData->pos.x,
                    curSpawnData->pos.y, curSpawnData->pos.z, 0, curCobraInfo->rotY, 0, curSpawnData->params);
                pthis->actor.child = NULL;

                if (&curCobraInfo->cobra->dyna.actor == NULL) {
                    // "Cobra generation failed"
                    osSyncPrintf("Error : コブラ発生失敗 (%s %d)\n", "../z_bg_jya_bigmirror.c", 221);
                }
            }
        }
    } else {

        for (i = 0; i < 2; i++) {
            curCobraInfo = &pthis->cobraInfo[i];
            if (curCobraInfo->cobra != NULL) {
                if (curCobraInfo->cobra->dyna.actor.child != NULL) {
                    Actor_Kill(curCobraInfo->cobra->dyna.actor.child);
                    curCobraInfo->cobra->dyna.actor.child = NULL;
                }
                Actor_Kill(&curCobraInfo->cobra->dyna.actor);
                curCobraInfo->cobra = NULL;
            }
        }
    }
}

void BgJyaBigmirror_SetBombiwaFlag(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;

    if (Flags_GetSwitch(globalCtx, 0x29)) {
        pthis->puzzleFlags |= BIGMIR_PUZZLE_BOMBIWA_DESTROYED;
    } else {
        pthis->puzzleFlags &= ~(BIGMIR_PUZZLE_BOMBIWA_DESTROYED);
    }
}

void BgJyaBigmirror_HandleMirRay(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;
    s32 puzzleSolved;
    s32 lightBeamToggles[3];
    s32 i;
    s32 objBankIndex;

    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MIR_RAY);

    if ((objBankIndex < 0) || (objBankIndex != pthis->mirRayObjIndex)) {
        pthis->lightBeams[2] = NULL;
        pthis->lightBeams[1] = NULL;
        pthis->lightBeams[0] = NULL;
    } else {
        puzzleSolved = !!(pthis->puzzleFlags & (BIGMIR_PUZZLE_IN_STATUE_ROOM | BIGMIR_PUZZLE_IN_1ST_TOP_ROOM));

        if (puzzleSolved) {
            puzzleSolved = !!(pthis->puzzleFlags & BIGMIR_PUZZLE_COBRA2_SOLVED);

            if (puzzleSolved) {
                puzzleSolved = !!(pthis->puzzleFlags & BIGMIR_PUZZLE_COBRA1_SOLVED);
            }
        }
        lightBeamToggles[0] = puzzleSolved; // Only spawn if puzzle solved
        if (1) {}
        lightBeamToggles[1] = lightBeamToggles[2] =
            pthis->puzzleFlags & (BIGMIR_PUZZLE_IN_1ST_TOP_ROOM | BIGMIR_PUZZLE_IN_2ND_TOP_ROOM);

        for (i = 0; i < 3; i++) {
            if (lightBeamToggles[i]) {
                if ((pthis->lightBeams[i] == NULL) && Object_IsLoaded(&globalCtx->objectCtx, objBankIndex)) {
                    pthis->lightBeams[i] = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_MIR_RAY, sMirRayPoss_24[i].x,
                                                      sMirRayPoss_24[i].y, sMirRayPoss_24[i].z, 0, 0, 0, sMirRayParamss_24[i]);

                    if (pthis->lightBeams[i] == NULL) {
                        // "Mir Ray generation failed"
                        osSyncPrintf("Error : Mir Ray 発生失敗 (%s %d)\n", "../z_bg_jya_bigmirror.c", 310);
                    }
                }
            } else {
                if (pthis->lightBeams[i] != NULL) {
                    Actor_Kill(pthis->lightBeams[i]);
                    pthis->lightBeams[i] = NULL;
                }
            }
        }
    }
    pthis->mirRayObjIndex = objBankIndex;
}

void BgJyaBigmirror_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;

    if (sIsSpawned) {
        Actor_Kill(&pthis->actor);
        return;
    }

    Actor_SetScale(&pthis->actor, 0.1f);
    pthis->cobraInfo[0].rotY = sCobraSpawnData[0].initRotY;
    pthis->cobraInfo[1].rotY = sCobraSpawnData[1].initRotY;
    pthis->actor.room = -1;
    sIsSpawned = true;
    pthis->spawned = true;
    pthis->mirRayObjIndex = -1;

    // "jya Bigmirror"
    osSyncPrintf("(jya 大鏡)(arg_data 0x%04x)\n", pthis->actor.params);
}

void BgJyaBigmirror_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;

    if (pthis->spawned) {
        sIsSpawned = false;
    }
}

void BgJyaBigmirror_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror_SetRoomFlag(thisx, globalCtx);
    BgJyaBigmirror_HandleCobra(thisx, globalCtx);
    BgJyaBigmirror_SetBombiwaFlag(thisx, globalCtx);
    BgJyaBigmirror_HandleMirRay(thisx, globalCtx);
}

void BgJyaBigmirror_DrawLightBeam(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;
    Actor* lift;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_jya_bigmirror.c", 435);
    func_80093D84(globalCtx->state.gfxCtx);
    lift = Actor_Find(&globalCtx->actorCtx, ACTOR_BG_JYA_LIFT, ACTORCAT_BG);
    if (lift != NULL) {
        pthis->liftHeight = lift->world.pos.y;
    }
    func_800D1694(pthis->actor.world.pos.x, pthis->actor.world.pos.y + 40.0f, pthis->actor.world.pos.z,
                  &pthis->actor.shape.rot);
    Matrix_Scale(0.1f, (pthis->liftHeight * -(1.0f / 1280.0f)) + (1779.4f / 1280.0f), 0.1f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_jya_bigmirror.c", 457),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gBigMirror1DL);

    if (lift != NULL) {
        if (1) {}
        func_800D1694(lift->world.pos.x, lift->world.pos.y, lift->world.pos.z, &D_80893F4C_28);
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_jya_bigmirror.c", 467),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gBigMirror2DL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_jya_bigmirror.c", 476);
}

void BgJyaBigmirror_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaBigmirror* pthis = (BgJyaBigmirror*)thisx;

    if (pthis->puzzleFlags & BIGMIR_PUZZLE_IN_1ST_TOP_ROOM) {
        Gfx_DrawDListOpa(globalCtx, gBigMirror3DL);
        Gfx_DrawDListXlu(globalCtx, gBigMirror4DL);
    }

    if ((pthis->puzzleFlags &
         (BIGMIR_PUZZLE_IN_STATUE_ROOM | BIGMIR_PUZZLE_IN_1ST_TOP_ROOM | BIGMIR_PUZZLE_IN_2ND_TOP_ROOM)) &&
        (pthis->puzzleFlags & BIGMIR_PUZZLE_COBRA2_SOLVED) && (pthis->puzzleFlags & BIGMIR_PUZZLE_COBRA1_SOLVED)) {
        BgJyaBigmirror_DrawLightBeam(&pthis->actor, globalCtx);
    }
}

void BgJyaBigmirror_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_80893F4C_28 = { 0, 0, 0 };

    sIsSpawned = false;

    Bg_Jya_Bigmirror_InitVars = {
        ACTOR_BG_JYA_BIGMIRROR,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_JYA_OBJ,
        sizeof(BgJyaBigmirror),
        (ActorFunc)BgJyaBigmirror_Init,
        (ActorFunc)BgJyaBigmirror_Destroy,
        (ActorFunc)BgJyaBigmirror_Update,
        (ActorFunc)BgJyaBigmirror_Draw,
        (ActorFunc)BgJyaBigmirror_Reset,
    };

}

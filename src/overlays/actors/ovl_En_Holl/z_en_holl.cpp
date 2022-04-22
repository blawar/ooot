#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HOLL_Z_EN_HOLL_C
#include "actor_common.h"
#include "z_en_holl.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera_data.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_room.h"

#define FLAGS ACTOR_FLAG_4

// Horizontal Plane parameters

#define PLANE_Y_MIN -50.0f
#define PLANE_Y_MAX 200.0f

#define PLANE_HALFWIDTH 100.0f
#define PLANE_HALFWIDTH_2 200.0f

void EnHoll_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHoll_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHoll_NextAction(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A58DD4(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A59014(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A591C0(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A593A4(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A59520(EnHoll* pthis, GlobalContext* globalCtx);
void func_80A59618(EnHoll* pthis, GlobalContext* globalCtx);

ActorInit En_Holl_InitVars = {
    ACTOR_EN_HOLL,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnHoll),
    (ActorFunc)EnHoll_Init,
    (ActorFunc)EnHoll_Destroy,
    (ActorFunc)EnHoll_Update,
    (ActorFunc)EnHoll_Draw,
    (ActorFunc)EnHoll_Reset,
};

static EnHollActionFunc sActionFuncs[] = {
    func_80A58DD4, func_80A591C0, func_80A59520, func_80A59618, func_80A59014, func_80A593A4, func_80A59014,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 400, ICHAIN_STOP),
};

/**
 * These are all absolute distances in the relative z direction. That is, moving
 *   towards or away from the "face" of the loading plane regardless of orientation.
 * Moving within these distances of the load plane have the following effects:
 * [0] : Load the room on pthis side of the loading plane if not already loaded
 * [1] : Load the room on the other side of the loading plane
 * [2] : Fade Region (opaque -> transparent if approaching, transparent -> opaque if receding)
 * [3] : Transparent Region
 *
 * When traversing a loading plane of pthis kind, it attempts to:
 *   Load Current Room (fails as it is already loaded)
 *   Load Next Room
 *   Load Previous Room
 *   Load Next Room
 *
 *  @bug The striped nature of loading planes can cause some actors to unload due to
 *      conflicting Object Lists between the two rooms
 *
 *  @bug If you can get around to the other side of the loading plane without triggering it,
 *      you can load the room on the other side multiple times
 */
static f32 sHorizTriggerDists[2][4] = {
    { 200.0f, 150.0f, 100.0f, 50.0f },
    { 100.0f, 75.0f, 50.0f, 25.0f },
};

void EnHoll_SetupAction(EnHoll* pthis, EnHollActionFunc func) {
    pthis->actionFunc = func;
}

s32 EnHoll_IsKokiriSetup8() {
    return gSaveContext.entranceIndex == 0x00EE && gSaveContext.sceneSetupIndex == 8;
}

void EnHoll_ChooseAction(EnHoll* pthis) {
    s32 action;

    action = (pthis->actor.params >> 6) & 7;
    EnHoll_SetupAction(pthis, sActionFuncs[action]);
    if (action != 0) {
        pthis->actor.draw = NULL;
    } else {
        pthis->planeAlpha = 255;
    }
}

void EnHoll_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHoll* pthis = (EnHoll*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    EnHoll_ChooseAction(pthis);
    pthis->unk_14F = 0;
}

void EnHoll_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 transitionActorIdx = (u16)thisx->params >> 0xA;
    TransitionActorEntry* transitionEntry = &globalCtx->transiActorCtx.list[transitionActorIdx];

    transitionEntry->id = -transitionEntry->id;
}

void EnHoll_SwapRooms(GlobalContext* globalCtx) {
    Room tempRoom;
    RoomContext* roomCtx = &globalCtx->roomCtx;

    tempRoom = roomCtx->curRoom;
    roomCtx->curRoom = roomCtx->prevRoom;
    roomCtx->prevRoom = tempRoom;
    globalCtx->roomCtx.unk_30 ^= 1;
}

// Horizontal Planes
void func_80A58DD4(EnHoll* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 phi_t0 = ((globalCtx->sceneNum == SCENE_JYASINZOU) ? 1 : 0) & 0xFFFFFFFF;
    Vec3f vec;
    f32 absZ;
    s32 transitionActorIdx;

    func_8002DBD0(&pthis->actor, &vec, &player->actor.world.pos);
    pthis->side = (vec.z < 0.0f) ? 0 : 1;
    absZ = fabsf(vec.z);
    if (vec.y > PLANE_Y_MIN && vec.y < PLANE_Y_MAX && fabsf(vec.x) < PLANE_HALFWIDTH &&
        absZ < sHorizTriggerDists[phi_t0][0]) {
        transitionActorIdx = (u16)pthis->actor.params >> 0xA;
        if (absZ > sHorizTriggerDists[phi_t0][1]) {
            if (globalCtx->roomCtx.prevRoom.num >= 0 && globalCtx->roomCtx.status == 0) {
                pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[pthis->side].room;
                EnHoll_SwapRooms(globalCtx);
                func_80097534(globalCtx, &globalCtx->roomCtx);
            }
        } else {
            pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[pthis->side ^ 1].room;
            if (globalCtx->roomCtx.prevRoom.num < 0) {
                func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room);
            } else {
                pthis->planeAlpha = (255.0f / (sHorizTriggerDists[phi_t0][2] - sHorizTriggerDists[phi_t0][3])) *
                                   (absZ - sHorizTriggerDists[phi_t0][3]);
                pthis->planeAlpha = CLAMP(pthis->planeAlpha, 0, 255);
                if (globalCtx->roomCtx.curRoom.num != pthis->actor.room) {
                    EnHoll_SwapRooms(globalCtx);
                }
            }
        }
    }
}

// Horizontal Planes
void func_80A59014(EnHoll* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 useViewEye = gDbgCamEnabled || globalCtx->csCtx.state != CS_STATE_IDLE;
    Vec3f vec;
    s32 temp;
    f32 planeHalfWidth;
    f32 absZ;

    func_8002DBD0(&pthis->actor, &vec, (useViewEye) ? &globalCtx->view.eye : &player->actor.world.pos);
    planeHalfWidth = (((pthis->actor.params >> 6) & 7) == 6) ? PLANE_HALFWIDTH : PLANE_HALFWIDTH_2;

    temp = EnHoll_IsKokiriSetup8();
    if (temp || (PLANE_Y_MIN < vec.y && vec.y < PLANE_Y_MAX && fabsf(vec.x) < planeHalfWidth &&
                 (absZ = fabsf(vec.z), 100.0f > absZ && absZ > 50.0f))) {
        s32 transitionActorIdx = (u16)pthis->actor.params >> 0xA;
        s32 side = (vec.z < 0.0f) ? 0 : 1;
        TransitionActorEntry* transitionEntry = &globalCtx->transiActorCtx.list[transitionActorIdx];
        s32 room = transitionEntry->sides[side].room;

        pthis->actor.room = room;
        if (temp) {}
        if (pthis->actor.room != globalCtx->roomCtx.curRoom.num) {
            if (room) {}
            if (func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room)) {
                EnHoll_SetupAction(pthis, EnHoll_NextAction);
            }
        }
    }
}

// Vertical Planes
void func_80A591C0(EnHoll* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 absY = fabsf(pthis->actor.yDistToPlayer);
    s32 transitionActorIdx;

    if (pthis->actor.xzDistToPlayer < 500.0f && absY < 700.0f) {
        transitionActorIdx = (u16)pthis->actor.params >> 0xA;
        if (absY < 95.0f) {
            globalCtx->unk_11E18 = 0xFF;
        } else if (absY > 605.0f) {
            globalCtx->unk_11E18 = 0;
        } else {
            globalCtx->unk_11E18 = (s16)(605.0f - absY) * 0.5f;
        }
        if (absY < 95.0f) {
            pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[1].room;
            Math_SmoothStepToF(&player->actor.world.pos.x, pthis->actor.world.pos.x, 1.0f, 50.0f, 10.0f);
            Math_SmoothStepToF(&player->actor.world.pos.z, pthis->actor.world.pos.z, 1.0f, 50.0f, 10.0f);
            if (pthis->actor.room != globalCtx->roomCtx.curRoom.num &&
                func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room) != 0) {
                EnHoll_SetupAction(pthis, EnHoll_NextAction);
                pthis->unk_14F = 1;
                player->actor.speedXZ = 0.0f;
            }
        }
    } else if (pthis->unk_14F != 0) {
        globalCtx->unk_11E18 = 0;
        pthis->unk_14F = 0;
    }
}

// Vertical Planes
void func_80A593A4(EnHoll* pthis, GlobalContext* globalCtx) {
    f32 absY;
    s32 side;
    s32 transitionActorIdx;

    if ((pthis->actor.xzDistToPlayer < 120.0f) && (absY = fabsf(pthis->actor.yDistToPlayer), absY < 200.0f)) {
        if (absY < 50.0f) {
            globalCtx->unk_11E18 = 0xFF;
        } else {
            globalCtx->unk_11E18 = (200.0f - absY) * 1.7f;
        }
        if (absY > 50.0f) {
            transitionActorIdx = (u16)pthis->actor.params >> 0xA;
            side = (0.0f < pthis->actor.yDistToPlayer) ? 0 : 1;
            pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[side].room;
            if (pthis->actor.room != globalCtx->roomCtx.curRoom.num &&
                func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room) != 0) {
                EnHoll_SetupAction(pthis, EnHoll_NextAction);
                pthis->unk_14F = 1;
            }
        }
    } else if (pthis->unk_14F != 0) {
        pthis->unk_14F = 0;
        globalCtx->unk_11E18 = 0;
    }
}

// Vertical Planes
void func_80A59520(EnHoll* pthis, GlobalContext* globalCtx) {
    f32 absY;
    s8 side;
    s32 transitionActorIdx;

    if (pthis->actor.xzDistToPlayer < 120.0f) {
        absY = fabsf(pthis->actor.yDistToPlayer);
        if (absY < 200.0f && absY > 50.0f) {
            transitionActorIdx = (u16)pthis->actor.params >> 0xA;
            side = (0.0f < pthis->actor.yDistToPlayer) ? 0 : 1;
            pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[side].room;
            if (pthis->actor.room != globalCtx->roomCtx.curRoom.num &&
                func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room) != 0) {
                EnHoll_SetupAction(pthis, EnHoll_NextAction);
            }
        }
    }
}

// Horizontal Planes
void func_80A59618(EnHoll* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f vec;
    f32 absZ;
    s32 side;
    s32 transitionActorIdx;

    if (!Flags_GetSwitch(globalCtx, pthis->actor.params & 0x3F)) {
        if (pthis->unk_14F != 0) {
            globalCtx->unk_11E18 = 0;
            pthis->unk_14F = 0;
        }
    } else {
        func_8002DBD0(&pthis->actor, &vec, &player->actor.world.pos);
        absZ = fabsf(vec.z);
        if (PLANE_Y_MIN < vec.y && vec.y < PLANE_Y_MAX && fabsf(vec.x) < PLANE_HALFWIDTH_2 && absZ < 100.0f) {
            pthis->unk_14F = 1;
            transitionActorIdx = (u16)pthis->actor.params >> 0xA;
            globalCtx->unk_11E18 = 0xFF - (s32)((absZ - 50.0f) * 5.9f);
            if (globalCtx->unk_11E18 >= 0x100) {
                globalCtx->unk_11E18 = 0xFF;
            } else if (globalCtx->unk_11E18 < 0) {
                globalCtx->unk_11E18 = 0;
            }
            if (absZ < 50.0f) {
                side = (vec.z < 0.0f) ? 0 : 1;
                pthis->actor.room = globalCtx->transiActorCtx.list[transitionActorIdx].sides[side].room;
                if (pthis->actor.room != globalCtx->roomCtx.curRoom.num &&
                    func_8009728C(globalCtx, &globalCtx->roomCtx, pthis->actor.room) != 0) {
                    EnHoll_SetupAction(pthis, EnHoll_NextAction);
                }
            }
        } else if (pthis->unk_14F != 0) {
            globalCtx->unk_11E18 = 0;
            pthis->unk_14F = 0;
        }
    }
}

void EnHoll_NextAction(EnHoll* pthis, GlobalContext* globalCtx) {
    if (!EnHoll_IsKokiriSetup8() && globalCtx->roomCtx.status == 0) {
        func_80097534(globalCtx, &globalCtx->roomCtx);
        if (globalCtx->unk_11E18 == 0) {
            pthis->unk_14F = 0;
        }
        EnHoll_ChooseAction(pthis);
    }
}

void EnHoll_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHoll* pthis = (EnHoll*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

#include "overlays/ovl_En_Holl/ovl_En_Holl.cpp"

void EnHoll_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHoll* pthis = (EnHoll*)thisx;
    Gfx* gfxP;
    u32 setupDlIdx;

    // Only draw the plane if not invisible
    if (pthis->planeAlpha != 0) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_holl.c", 805);

        if (pthis->planeAlpha == 255) {
            gfxP = POLY_OPA_DISP;
            setupDlIdx = 37;
        } else {
            gfxP = POLY_XLU_DISP;
            setupDlIdx = 0;
        }
        gfxP = Gfx_CallSetupDL(gfxP, setupDlIdx);
        if (pthis->side == 0) {
            Matrix_RotateY(M_PI, MTXMODE_APPLY);
        }

        gSPMatrix(gfxP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_holl.c", 824),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(gfxP++, 0, 0, 0, 0, 0, (u8)pthis->planeAlpha);
        gSPDisplayList(gfxP++, sPlaneDL);

        if (pthis->planeAlpha == 255) {
            POLY_OPA_DISP = gfxP;
        } else {
            POLY_XLU_DISP = gfxP;
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_holl.c", 831);
    }
}

void EnHoll_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Holl_InitVars = {
        ACTOR_EN_HOLL,
        ACTORCAT_DOOR,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnHoll),
        (ActorFunc)EnHoll_Init,
        (ActorFunc)EnHoll_Destroy,
        (ActorFunc)EnHoll_Update,
        (ActorFunc)EnHoll_Draw,
        (ActorFunc)EnHoll_Reset,
    };

}

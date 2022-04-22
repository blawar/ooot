#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MIZU_MOVEBG_Z_BG_MIZU_MOVEBG_C
#include "actor_common.h"
/*
 * File: z_bg_mizu_movebg.c
 * Overlay: ovl_Bg_Mizu_Movebg
 * Description: Kakariko Village Well Water
 */

#include "z_bg_mizu_movebg.h"
#include "overlays/actors/ovl_Bg_Mizu_Water/z_bg_mizu_water.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

#define MOVEBG_TYPE(params) (((u16)(params) >> 0xC) & 0xF)
#define MOVEBG_FLAGS(params) ((u16)(params)&0x3F)
#define MOVEBG_PATH_ID(params) (((u16)(params) >> 0x8) & 0xF)
#define MOVEBG_POINT_ID(params) ((u16)(params)&0xF)
#define MOVEBG_SPEED(params) (((u16)(params) >> 0x4) & 0xF)

void BgMizuMovebg_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMizuMovebg_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8089E318(BgMizuMovebg* pthis, GlobalContext* globalCtx);
void func_8089E650(BgMizuMovebg* pthis, GlobalContext* globalCtx);
s32 func_8089E108(Path* pathList, Vec3f* pos, s32 pathId, s32 pointId);

ActorInit Bg_Mizu_Movebg_InitVars = {
    ACTOR_BG_MIZU_MOVEBG,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuMovebg),
    (ActorFunc)BgMizuMovebg_Init,
    (ActorFunc)BgMizuMovebg_Destroy,
    (ActorFunc)BgMizuMovebg_Update,
    (ActorFunc)BgMizuMovebg_Draw,
    (ActorFunc)BgMizuMovebg_Reset,
};

static f32 D_8089EB40[] = { -115.200005f, -115.200005f, -115.200005f, 0.0f };

static Gfx* D_8089EB50[] = {
    gObjectMizuObjectsMovebgDL_000190, gObjectMizuObjectsMovebgDL_000680, gObjectMizuObjectsMovebgDL_000C20,
    gObjectMizuObjectsMovebgDL_002E10, gObjectMizuObjectsMovebgDL_002E10, gObjectMizuObjectsMovebgDL_002E10,
    gObjectMizuObjectsMovebgDL_002E10, gObjectMizuObjectsMovebgDL_0011F0,
};

static CollisionHeader* D_8089EB70[] = {
    &gObjectMizuObjectsMovebgCol_0003F0, &gObjectMizuObjectsMovebgCol_000998, &gObjectMizuObjectsMovebgCol_000ED0,
    &gObjectMizuObjectsMovebgCol_003590, &gObjectMizuObjectsMovebgCol_003590, &gObjectMizuObjectsMovebgCol_003590,
    &gObjectMizuObjectsMovebgCol_003590, &gObjectMizuObjectsMovebgCol_0015F8,
};

static InitChainEntry D_8089EB90[] = {
    ICHAIN_F32(uncullZoneScale, 1500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static Vec3f D_8089EBA0 = { 0.0f, 80.0f, 23.0f };
static Vec3f D_8089EBAC = { 0.0f, 80.0f, 23.0f };

static u8 D_8089EE40;

s32 func_8089DC30(GlobalContext* globalCtx) {
    s32 result;

    if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F1_FLAG)) {
        result = 1;
    } else if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F2_FLAG)) {
        result = 2;
    } else if (Flags_GetSwitch(globalCtx, WATER_TEMPLE_WATER_F3_FLAG)) {
        result = 3;
    } else {
        result = 1;
    }
    return result;
}

void BgMizuMovebg_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 type;
    s32 waypointId;
    WaterBox* waterBoxes = globalCtx->colCtx.colHeader->waterBoxes;
    f32 temp;
    CollisionHeader* colHeader = NULL;
    Vec3f sp48;

    Actor_ProcessInitChain(thisx, D_8089EB90);
    ((BgMizuMovebg*)thisx)->homeY = thisx->world.pos.y;
    ((BgMizuMovebg*)thisx)->dlist = D_8089EB50[MOVEBG_TYPE(thisx->params)];
    DynaPolyActor_Init(&((BgMizuMovebg*)thisx)->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(D_8089EB70[MOVEBG_TYPE(thisx->params)], &colHeader);
    ((BgMizuMovebg*)thisx)->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);

    type = MOVEBG_TYPE(thisx->params);
    switch (type) {
        case 0:
            temp = waterBoxes[2].ySurface + 15.0f;
            if (temp < ((BgMizuMovebg*)thisx)->homeY - 700.0f) {
                thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY - 700.0f;
            } else {
                thisx->world.pos.y = temp;
            }
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E318;
            break;
        case 1:
            temp = waterBoxes[2].ySurface + 15.0f;
            if (temp < ((BgMizuMovebg*)thisx)->homeY - 710.0f) {
                thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY - 710.0f;
            } else {
                thisx->world.pos.y = temp;
            }
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E318;
            break;
        case 2:
            temp = waterBoxes[2].ySurface + 15.0f;
            if (temp < ((BgMizuMovebg*)thisx)->homeY - 700.0f) {
                thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY - 700.0f;
            } else {
                thisx->world.pos.y = temp;
            }
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E318;
            break;
        case 3:
            thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY + D_8089EB40[func_8089DC30(globalCtx)];
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E318;
            break;
        case 4:
        case 5:
        case 6:
            if (Flags_GetSwitch(globalCtx, MOVEBG_FLAGS(thisx->params))) {
                thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY + 115.19999999999999;
            } else {
                thisx->world.pos.y = ((BgMizuMovebg*)thisx)->homeY;
            }
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E318;
            break;
        case 7:
            ((BgMizuMovebg*)thisx)->scrollAlpha1 = 160;
            ((BgMizuMovebg*)thisx)->scrollAlpha2 = 160;
            ((BgMizuMovebg*)thisx)->scrollAlpha3 = 160;
            ((BgMizuMovebg*)thisx)->scrollAlpha4 = 160;
            waypointId = MOVEBG_POINT_ID(thisx->params);
            ((BgMizuMovebg*)thisx)->waypointId = waypointId;
            func_8089E108(globalCtx->setupPathList, &thisx->world.pos, MOVEBG_PATH_ID(thisx->params), waypointId);
            ((BgMizuMovebg*)thisx)->actionFunc = func_8089E650;
            break;
    }

    type = MOVEBG_TYPE(thisx->params);
    switch (type) {
        case 3:
        case 4:
        case 5:
        case 6:
            Matrix_RotateY(thisx->world.rot.y * (M_PI / 32768), MTXMODE_NEW);
            Matrix_MultVec3f(&D_8089EBA0, &sp48);

            if (Actor_SpawnAsChild(&globalCtx->actorCtx, thisx, globalCtx, ACTOR_OBJ_HSBLOCK,
                                   thisx->world.pos.x + sp48.x, thisx->world.pos.y + sp48.y,
                                   thisx->world.pos.z + sp48.z, thisx->world.rot.x, thisx->world.rot.y,
                                   thisx->world.rot.z, 2) == NULL) {
                Actor_Kill(thisx);
            }
            break;
    }
}

void BgMizuMovebg_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuMovebg* pthis = (BgMizuMovebg*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    switch (MOVEBG_TYPE(thisx->params)) {
        case 3:
        case 4:
        case 5:
        case 6:
            if (pthis->sfxFlags & 2) {
                D_8089EE40 &= ~2;
            }
            break;
        case 7:
            if (pthis->sfxFlags & 1) {
                D_8089EE40 &= ~1;
            }
            break;
    }
}

s32 func_8089E108(Path* pathList, Vec3f* pos, s32 pathId, s32 pointId) {
    Path* path = pathList;
    Vec3s* point;

    path += pathId;
    point = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pointId];

    pos->x = point->x;
    pos->y = point->y;
    pos->z = point->z;

    return 0;
}

void func_8089E198(BgMizuMovebg* pthis, GlobalContext* globalCtx) {
    f32 waterLevel = globalCtx->colCtx.colHeader->waterBoxes[2].ySurface;

    if (waterLevel < WATER_TEMPLE_WATER_F1_Y) {
        pthis->scrollAlpha1 = 255;
    } else if (waterLevel < WATER_TEMPLE_WATER_F2_Y) {
        pthis->scrollAlpha1 = 255 - (s32)((waterLevel - WATER_TEMPLE_WATER_F1_Y) /
                                         (WATER_TEMPLE_WATER_F2_Y - WATER_TEMPLE_WATER_F1_Y) * (255 - 160));
    } else {
        pthis->scrollAlpha1 = 160;
    }

    if (waterLevel < WATER_TEMPLE_WATER_F2_Y) {
        pthis->scrollAlpha2 = 255;
    } else if (waterLevel < WATER_TEMPLE_WATER_F3_Y) {
        pthis->scrollAlpha2 = 255 - (s32)((waterLevel - WATER_TEMPLE_WATER_F2_Y) /
                                         (WATER_TEMPLE_WATER_F3_Y - WATER_TEMPLE_WATER_F2_Y) * (255 - 160));
    } else {
        pthis->scrollAlpha2 = 160;
    }

    if (waterLevel < WATER_TEMPLE_WATER_B1_Y) {
        pthis->scrollAlpha3 = 255;
    } else if (waterLevel < WATER_TEMPLE_WATER_F1_Y) {
        pthis->scrollAlpha3 = 255 - (s32)((waterLevel - WATER_TEMPLE_WATER_B1_Y) /
                                         (WATER_TEMPLE_WATER_F1_Y - WATER_TEMPLE_WATER_B1_Y) * (255 - 160));
    } else {
        pthis->scrollAlpha3 = 160;
    }

    pthis->scrollAlpha4 = pthis->scrollAlpha3;
}

void func_8089E318(BgMizuMovebg* pthis, GlobalContext* globalCtx) {
    WaterBox* waterBoxes = globalCtx->colCtx.colHeader->waterBoxes;
    f32 phi_f0;
    s32 type;
    Vec3f sp28;

    func_8089E198(pthis, globalCtx);

    type = MOVEBG_TYPE(pthis->dyna.actor.params);
    switch (type) {
        case 0:
        case 2:
            phi_f0 = waterBoxes[2].ySurface + 15.0f;
            if (phi_f0 < pthis->homeY - 700.0f) {
                pthis->dyna.actor.world.pos.y = pthis->homeY - 700.0f;
            } else {
                pthis->dyna.actor.world.pos.y = phi_f0;
            }
            break;
        case 1:
            phi_f0 = waterBoxes[2].ySurface + 15.0f;
            if (phi_f0 < pthis->homeY - 710.0f) {
                pthis->dyna.actor.world.pos.y = pthis->homeY - 710.0f;
            } else {
                pthis->dyna.actor.world.pos.y = phi_f0;
            }
            break;
        case 3:
            phi_f0 = pthis->homeY + D_8089EB40[func_8089DC30(globalCtx)];
            if (!Math_StepToF(&pthis->dyna.actor.world.pos.y, phi_f0, 1.0f)) {
                if (!(D_8089EE40 & 2) && MOVEBG_SPEED(pthis->dyna.actor.params) != 0) {
                    D_8089EE40 |= 2;
                    pthis->sfxFlags |= 2;
                }
                if (pthis->sfxFlags & 2) {
                    if (pthis->dyna.actor.room == 0) {
                        func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
                    } else {
                        func_8002F948(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
                    }
                }
            }
            break;
        case 4:
        case 5:
        case 6:
            if (Flags_GetSwitch(globalCtx, MOVEBG_FLAGS(pthis->dyna.actor.params))) {
                phi_f0 = pthis->homeY + 115.200005f;
            } else {
                phi_f0 = pthis->homeY;
            }
            if (!Math_StepToF(&pthis->dyna.actor.world.pos.y, phi_f0, 1.0f)) {
                if (!(D_8089EE40 & 2) && MOVEBG_SPEED(pthis->dyna.actor.params) != 0) {
                    D_8089EE40 |= 2;
                    pthis->sfxFlags |= 2;
                }
                if (pthis->sfxFlags & 2) {
                    func_8002F948(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
                }
            }
            break;
    }

    type = MOVEBG_TYPE(pthis->dyna.actor.params);
    switch (type) {
        case 3:
        case 4:
        case 5:
        case 6:
            if (globalCtx->roomCtx.curRoom.num == pthis->dyna.actor.room) {
                Matrix_RotateY(pthis->dyna.actor.world.rot.y * (M_PI / 32768), MTXMODE_NEW);
                Matrix_MultVec3f(&D_8089EBAC, &sp28);
                pthis->dyna.actor.child->world.pos.x = pthis->dyna.actor.world.pos.x + sp28.x;
                pthis->dyna.actor.child->world.pos.y = pthis->dyna.actor.world.pos.y + sp28.y;
                pthis->dyna.actor.child->world.pos.z = pthis->dyna.actor.world.pos.z + sp28.z;
                pthis->dyna.actor.child->flags &= ~ACTOR_FLAG_0;
            }
            break;
    }
}

void func_8089E650(BgMizuMovebg* pthis, GlobalContext* globalCtx) {
    Vec3f waypoint;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 dz;

    pthis->dyna.actor.speedXZ = MOVEBG_SPEED(pthis->dyna.actor.params) * 0.1f;
    func_8089E108(globalCtx->setupPathList, &waypoint, MOVEBG_PATH_ID(pthis->dyna.actor.params), pthis->waypointId);
    dist = Actor_WorldDistXYZToPoint(&pthis->dyna.actor, &waypoint);
    if (dist < pthis->dyna.actor.speedXZ) {
        pthis->dyna.actor.speedXZ = dist;
    }
    func_80035844(&pthis->dyna.actor.world.pos, &waypoint, &pthis->dyna.actor.world.rot, 1);
    func_8002D97C(&pthis->dyna.actor);
    dx = waypoint.x - pthis->dyna.actor.world.pos.x;
    dy = waypoint.y - pthis->dyna.actor.world.pos.y;
    dz = waypoint.z - pthis->dyna.actor.world.pos.z;
    if (fabsf(dx) < 2.0f && fabsf(dy) < 2.0f && fabsf(dz) < 2.0f) {
        pthis->waypointId++;
        if (pthis->waypointId >= globalCtx->setupPathList[MOVEBG_PATH_ID(pthis->dyna.actor.params)].count) {
            pthis->waypointId = 0;
            func_8089E108(globalCtx->setupPathList, &pthis->dyna.actor.world.pos,
                          MOVEBG_PATH_ID(pthis->dyna.actor.params), 0);
        }
    }
    if (!(D_8089EE40 & 1) && MOVEBG_SPEED(pthis->dyna.actor.params) != 0) {
        D_8089EE40 |= 1;
        pthis->sfxFlags |= 1;
    }
    if (pthis->sfxFlags & 1) {
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_ROLL_STAND_2 - SFX_FLAG);
    }
}

void BgMizuMovebg_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuMovebg* pthis = (BgMizuMovebg*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgMizuMovebg_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    BgMizuMovebg* pthis = (BgMizuMovebg*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    u32 frames;

    if (1) {}

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_movebg.c", 754);

    frames = globalCtx->gameplayFrames;
    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScrollEnvColor(globalCtx->state.gfxCtx, 0, frames * 1, 0, 32, 32, 1, 0, 0, 32, 32, 0, 0, 0,
                                        pthis->scrollAlpha1));

    gSPSegment(POLY_OPA_DISP++, 0x09,
               Gfx_TwoTexScrollEnvColor(globalCtx->state.gfxCtx, 0, frames * 1, 0, 32, 32, 1, 0, 0, 32, 32, 0, 0, 0,
                                        pthis->scrollAlpha2));

    gSPSegment(POLY_OPA_DISP++, 0x0A,
               Gfx_TwoTexScrollEnvColor(globalCtx->state.gfxCtx, 0, frames * 1, 0, 32, 32, 1, 0, 0, 32, 32, 0, 0, 0,
                                        pthis->scrollAlpha3));

    gSPSegment(POLY_OPA_DISP++, 0x0B,
               Gfx_TwoTexScrollEnvColor(globalCtx->state.gfxCtx, 0, frames * 3, 0, 32, 32, 1, 0, 0, 32, 32, 0, 0, 0,
                                        pthis->scrollAlpha4));

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mizu_movebg.c", 788),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (pthis->dlist != NULL) {
        gSPDisplayList(POLY_OPA_DISP++, pthis->dlist);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mizu_movebg.c", 795);
}

void BgMizuMovebg_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Mizu_Movebg_InitVars = {
        ACTOR_BG_MIZU_MOVEBG,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_MIZU_OBJECTS,
        sizeof(BgMizuMovebg),
        (ActorFunc)BgMizuMovebg_Init,
        (ActorFunc)BgMizuMovebg_Destroy,
        (ActorFunc)BgMizuMovebg_Update,
        (ActorFunc)BgMizuMovebg_Draw,
        (ActorFunc)BgMizuMovebg_Reset,
    };

    D_8089EBA0 = { 0.0f, 80.0f, 23.0f };

    D_8089EBAC = { 0.0f, 80.0f, 23.0f };

    D_8089EE40 = 0;

}

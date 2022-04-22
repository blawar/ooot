#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_OSHIHIKI_Z_OBJ_OSHIHIKI_C
#include "actor_common.h"
/*
 * File: z_obj_oshihiki.c
 * Overlay: ovl_Obj_Oshihiki
 * Description: Push Block
 */

#include "z_obj_oshihiki.h"
#include "overlays/actors/ovl_Obj_Switch/z_obj_switch.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void ObjOshihiki_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjOshihiki_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjOshihiki_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjOshihiki_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjOshihiki_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjOshihiki_SetupOnScene(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_OnScene(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_SetupOnActor(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_OnActor(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_SetupPush(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_Push(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_SetupFall(ObjOshihiki* pthis, GlobalContext* globalCtx);
void ObjOshihiki_Fall(ObjOshihiki* pthis, GlobalContext* globalCtx);

ActorInit Obj_Oshihiki_InitVars = {
    ACTOR_OBJ_OSHIHIKI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(ObjOshihiki),
    (ActorFunc)ObjOshihiki_Init,
    (ActorFunc)ObjOshihiki_Destroy,
    (ActorFunc)ObjOshihiki_Update,
    (ActorFunc)ObjOshihiki_Draw,
    (ActorFunc)ObjOshihiki_Reset,
};

static f32 sScales[] = {
    (1 / 10.0f), (1 / 6.0f), (1 / 5.0f), (1 / 3.0f), (1 / 10.0f), (1 / 6.0f), (1 / 5.0f), (1 / 3.0f),
};

static Color_RGB8 sColors[][4] = {
    { { 110, 86, 40 }, { 110, 86, 40 }, { 110, 86, 40 }, { 110, 86, 40 } },         // deku tree
    { { 106, 120, 110 }, { 104, 80, 20 }, { 0, 0, 0 }, { 0, 0, 0 } },               // dodongos cavern
    { { 142, 99, 86 }, { 72, 118, 96 }, { 0, 0, 0 }, { 0, 0, 0 } },                 // forest temple
    { { 210, 150, 80 }, { 210, 170, 80 }, { 0, 0, 0 }, { 0, 0, 0 } },               // fire temple
    { { 102, 144, 182 }, { 176, 167, 100 }, { 100, 167, 100 }, { 117, 97, 96 } },   // water temple
    { { 232, 210, 176 }, { 232, 210, 176 }, { 232, 210, 176 }, { 232, 210, 176 } }, // spirit temple
    { { 135, 125, 95 }, { 135, 125, 95 }, { 135, 125, 95 }, { 135, 125, 95 } },     // shadow temple
    { { 255, 255, 255 }, { 255, 255, 255 }, { 255, 255, 255 }, { 255, 255, 255 } }, // ganons castle
    { { 232, 210, 176 }, { 232, 210, 176 }, { 232, 210, 176 }, { 232, 210, 176 } }, // gerudo training grounds
};

static s16 sScenes[] = {
    SCENE_YDAN,      SCENE_DDAN,    SCENE_BMORI1, SCENE_HIDAN, SCENE_MIZUSIN,
    SCENE_JYASINZOU, SCENE_HAKADAN, SCENE_GANON,  SCENE_MEN,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1500, ICHAIN_STOP),
};

// The vertices and center of the bottom face
static Vec3f sColCheckPoints[5] = {
    { 29.99f, 1.01f, -29.99f }, { -29.99f, 1.01f, -29.99f }, { -29.99f, 1.01f, 29.99f },
    { 29.99f, 1.01f, 29.99f },  { 0.0f, 1.01f, 0.0f },
};

static Vec2f sFaceVtx[] = {
    { -30.0f, 0.0f },
    { 30.0f, 0.0f },
    { -30.0f, 60.0f },
    { 30.0f, 60.0f },
};

static Vec2f sFaceDirection[] = {
    { 1.0f, 1.0f },
    { -1.0f, 1.0f },
    { 1.0f, -1.0f },
    { -1.0f, -1.0f },
};

void ObjOshihiki_InitDynapoly(ObjOshihiki* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG registration failure"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_obj_oshihiki.c", 280,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void ObjOshihiki_RotateXZ(Vec3f* out, Vec3f* in, f32 sn, f32 cs) {
    out->x = (in->z * sn) + (in->x * cs);
    out->y = in->y;
    out->z = (in->z * cs) - (in->x * sn);
}

s32 ObjOshihiki_StrongEnough(ObjOshihiki* pthis) {
    s32 strength;

    if (pthis->cantMove) {
        return 0;
    }
    strength = Player_GetStrength();
    switch (pthis->dyna.actor.params & 0xF) {
        case PUSHBLOCK_SMALL_START_ON:
        case PUSHBLOCK_MEDIUM_START_ON:
        case PUSHBLOCK_SMALL_START_OFF:
        case PUSHBLOCK_MEDIUM_START_OFF:
            return 1;
            break;
        case PUSHBLOCK_LARGE_START_ON:
        case PUSHBLOCK_LARGE_START_OFF:
            return strength >= PLAYER_STR_BRACELET;
            break;
        case PUSHBLOCK_HUGE_START_ON:
        case PUSHBLOCK_HUGE_START_OFF:
            return strength >= PLAYER_STR_SILVER_G;
            break;
    }
    return 0;
}

void ObjOshihiki_ResetFloors(ObjOshihiki* pthis) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(pthis->floorBgIds); i++) {
        pthis->floorBgIds[i] = BGCHECK_SCENE;
    }
}

ObjOshihiki* ObjOshihiki_GetBlockUnder(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    DynaPolyActor* dynaPolyActor;

    if ((pthis->floorBgIds[pthis->highestFloor] != BGCHECK_SCENE) &&
        (fabsf(pthis->dyna.actor.floorHeight - pthis->dyna.actor.world.pos.y) < 0.001f)) {
        dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, pthis->floorBgIds[pthis->highestFloor]);
        if ((dynaPolyActor != NULL) && (dynaPolyActor->actor.id == ACTOR_OBJ_OSHIHIKI)) {
            return (ObjOshihiki*)dynaPolyActor;
        }
    }
    return NULL;
}

void ObjOshihiki_UpdateInitPos(ObjOshihiki* pthis) {
    if (pthis->dyna.actor.home.pos.x < pthis->dyna.actor.world.pos.x) {
        while ((pthis->dyna.actor.world.pos.x - pthis->dyna.actor.home.pos.x) >= 20.0f) {
            pthis->dyna.actor.home.pos.x += 20.0f;
        }
    } else {
        while ((pthis->dyna.actor.home.pos.x - pthis->dyna.actor.world.pos.x) >= 20.0f) {
            pthis->dyna.actor.home.pos.x -= 20.0f;
        }
    }
    if (pthis->dyna.actor.home.pos.z < pthis->dyna.actor.world.pos.z) {
        while ((pthis->dyna.actor.world.pos.z - pthis->dyna.actor.home.pos.z) >= 20.0f) {
            pthis->dyna.actor.home.pos.z += 20.0f;
        }
    } else {
        while ((pthis->dyna.actor.home.pos.z - pthis->dyna.actor.world.pos.z) >= 20.0f) {
            pthis->dyna.actor.home.pos.z -= 20.0f;
        }
    }
}

s32 ObjOshihiki_NoSwitchPress(ObjOshihiki* pthis, DynaPolyActor* dyna, GlobalContext* globalCtx) {
    s16 dynaSwitchFlag;

    if (dyna == NULL) {
        return 1;
    } else if (dyna->actor.id == ACTOR_OBJ_SWITCH) {
        dynaSwitchFlag = (dyna->actor.params >> 8) & 0x3F;
        switch (dyna->actor.params & 0x33) {
            case 0x20: // Normal blue switch
                if ((dynaSwitchFlag == ((pthis->dyna.actor.params >> 8) & 0x3F)) &&
                    Flags_GetSwitch(globalCtx, dynaSwitchFlag)) {
                    return 0;
                }
                break;
            case 0x30: // Inverse blue switch
                if ((dynaSwitchFlag == ((pthis->dyna.actor.params >> 8) & 0x3F)) &&
                    !Flags_GetSwitch(globalCtx, dynaSwitchFlag)) {
                    return 0;
                }
                break;
        }
    }
    return 1;
}

void ObjOshihiki_CheckType(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xF) {
        case PUSHBLOCK_SMALL_START_ON:
        case PUSHBLOCK_MEDIUM_START_ON:
        case PUSHBLOCK_LARGE_START_ON:
        case PUSHBLOCK_HUGE_START_ON:
        case PUSHBLOCK_SMALL_START_OFF:
        case PUSHBLOCK_MEDIUM_START_OFF:
        case PUSHBLOCK_LARGE_START_OFF:
        case PUSHBLOCK_HUGE_START_OFF:
            ObjOshihiki_InitDynapoly(pthis, globalCtx, &gPushBlockCol, 1);
            break;
        default:
            // "Error : type cannot be determined"
            osSyncPrintf("Error : タイプが判別できない(%s %d)(arg_data 0x%04x)\n", "../z_obj_oshihiki.c", 444,
                         pthis->dyna.actor.params);
            break;
    }
}

void ObjOshihiki_SetScale(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    Actor_SetScale(&pthis->dyna.actor, sScales[pthis->dyna.actor.params & 0xF]);
}

void ObjOshihiki_SetTexture(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    switch (pthis->dyna.actor.params & 0xF) {
        case PUSHBLOCK_SMALL_START_ON:
        case PUSHBLOCK_MEDIUM_START_ON:
        case PUSHBLOCK_SMALL_START_OFF:
        case PUSHBLOCK_MEDIUM_START_OFF:
            pthis->texture = gPushBlockSilverTex;
            break;
        case PUSHBLOCK_LARGE_START_ON:
        case PUSHBLOCK_LARGE_START_OFF:
            pthis->texture = gPushBlockBaseTex;
            break;
        case PUSHBLOCK_HUGE_START_ON:
        case PUSHBLOCK_HUGE_START_OFF:
            pthis->texture = gPushBlockGrayTex;
            break;
    }
}

void ObjOshihiki_SetColor(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    Color_RGB8* src;
    Color_RGB8* color = &pthis->color;
    s16 paramsColorIdx;
    s32 i;

    paramsColorIdx = (pthis->dyna.actor.params >> 6) & 3;

    for (i = 0; i < ARRAY_COUNT(sScenes); i++) {
        if (sScenes[i] == globalCtx->sceneNum) {
            break;
        }
    }

    if (i >= ARRAY_COUNT(sColors)) {
        // "Error : scene_data_ID cannot be determined"
        osSyncPrintf("Error : scene_data_ID が判別できない。(%s %d)\n", "../z_obj_oshihiki.c", 579);
        color->r = color->g = color->b = 255;
    } else {
        src = &sColors[i][paramsColorIdx];
        color->r = src->r;
        color->g = src->g;
        color->b = src->b;
    }
}

void ObjOshihiki_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    ObjOshihiki* pthis = (ObjOshihiki*)thisx;

    ObjOshihiki_CheckType(pthis, globalCtx);

    if ((((pthis->dyna.actor.params >> 8) & 0xFF) >= 0) && (((pthis->dyna.actor.params >> 8) & 0xFF) <= 0x3F)) {
        if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
            switch (pthis->dyna.actor.params & 0xF) {
                case PUSHBLOCK_SMALL_START_ON:
                case PUSHBLOCK_MEDIUM_START_ON:
                case PUSHBLOCK_LARGE_START_ON:
                case PUSHBLOCK_HUGE_START_ON:
                    Actor_Kill(&pthis->dyna.actor);
                    return;
            }
        } else {
            switch (pthis->dyna.actor.params & 0xF) {
                case PUSHBLOCK_SMALL_START_OFF:
                case PUSHBLOCK_MEDIUM_START_OFF:
                case PUSHBLOCK_LARGE_START_OFF:
                case PUSHBLOCK_HUGE_START_OFF:
                    Actor_Kill(&pthis->dyna.actor);
                    return;
            }
        }
    }

    ObjOshihiki_SetScale(pthis, globalCtx);
    ObjOshihiki_SetTexture(pthis, globalCtx);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    ObjOshihiki_SetColor(pthis, globalCtx);
    ObjOshihiki_ResetFloors(pthis);
    ObjOshihiki_SetupOnActor(pthis, globalCtx);
    // "(dungeon keep push-pull block)"
    osSyncPrintf("(dungeon keep 押し引きブロック)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void ObjOshihiki_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjOshihiki* pthis = (ObjOshihiki*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void ObjOshihiki_SetFloors(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 5; i++) {
        Vec3f colCheckPoint;
        Vec3f colCheckOffset;
        CollisionPoly** floorPoly;
        s32* floorBgId;

        colCheckOffset.x = sColCheckPoints[i].x * (pthis->dyna.actor.scale.x * 10.0f);
        colCheckOffset.y = sColCheckPoints[i].y * (pthis->dyna.actor.scale.y * 10.0f);
        colCheckOffset.z = sColCheckPoints[i].z * (pthis->dyna.actor.scale.z * 10.0f);
        ObjOshihiki_RotateXZ(&colCheckPoint, &colCheckOffset, pthis->yawSin, pthis->yawCos);
        colCheckPoint.x += pthis->dyna.actor.world.pos.x;
        colCheckPoint.y += pthis->dyna.actor.prevPos.y;
        colCheckPoint.z += pthis->dyna.actor.world.pos.z;

        floorPoly = &pthis->floorPolys[i];
        floorBgId = &pthis->floorBgIds[i];
        pthis->floorHeights[i] = BgCheck_EntityRaycastFloor6(&globalCtx->colCtx, floorPoly, floorBgId, &pthis->dyna.actor,
                                                            &colCheckPoint, 0.0f);
    }
}

s16 ObjOshihiki_GetHighestFloor(ObjOshihiki* pthis) {
    s16 highestFloor = 0;
    s16 temp = 1;
    f32 phi_f0 = pthis->floorHeights[temp];

    if (phi_f0 > pthis->floorHeights[highestFloor]) {
        highestFloor = temp;
    } else if ((pthis->floorBgIds[temp] == BGCHECK_SCENE) && ((phi_f0 - pthis->floorHeights[highestFloor]) > -0.001f)) {
        highestFloor = temp;
    }
    if (pthis->floorHeights[temp + 1] > pthis->floorHeights[highestFloor]) {
        highestFloor = temp + 1;
    } else if ((pthis->floorBgIds[temp + 1] == BGCHECK_SCENE) &&
               ((pthis->floorHeights[temp + 1] - pthis->floorHeights[highestFloor]) > -0.001f)) {
        highestFloor = temp + 1;
    }
    if (pthis->floorHeights[temp + 2] > pthis->floorHeights[highestFloor]) {
        highestFloor = temp + 2;
    } else if ((pthis->floorBgIds[temp + 2] == BGCHECK_SCENE) &&
               ((pthis->floorHeights[temp + 2] - pthis->floorHeights[highestFloor]) > -0.001f)) {
        highestFloor = temp + 2;
    }
    if (pthis->floorHeights[temp + 3] > pthis->floorHeights[highestFloor]) {
        highestFloor = temp + 3;
    } else if ((pthis->floorBgIds[temp + 3] == BGCHECK_SCENE) &&
               ((pthis->floorHeights[temp + 3] - pthis->floorHeights[highestFloor]) > -0.001f)) {
        highestFloor = temp + 3;
    }
    return highestFloor;
}

void ObjOshihiki_SetGround(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    ObjOshihiki_ResetFloors(pthis);
    ObjOshihiki_SetFloors(pthis, globalCtx);
    pthis->highestFloor = ObjOshihiki_GetHighestFloor(pthis);
    pthis->dyna.actor.floorHeight = pthis->floorHeights[pthis->highestFloor];
}

s32 ObjOshihiki_CheckFloor(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    ObjOshihiki_SetGround(pthis, globalCtx);

    if ((pthis->dyna.actor.floorHeight - pthis->dyna.actor.world.pos.y) >= -0.001f) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        return 1;
    }

    return 0;
}

s32 ObjOshihiki_CheckGround(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.world.pos.y <= BGCHECK_Y_MIN + 10.0f) {
        // "Warning : Push-pull block fell too much"
        osSyncPrintf("Warning : 押し引きブロック落ちすぎた(%s %d)(arg_data 0x%04x)\n", "../z_obj_oshihiki.c", 809,
                     pthis->dyna.actor.params);
        Actor_Kill(&pthis->dyna.actor);
        return 0;
    }
    if ((pthis->dyna.actor.floorHeight - pthis->dyna.actor.world.pos.y) >= -0.001f) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        return 1;
    }
    return 0;
}

s32 ObjOshihiki_CheckWall(GlobalContext* globalCtx, s16 angle, f32 direction, ObjOshihiki* pthis) {
    f32 maxDist = ((direction >= 0.0f) ? 1.0f : -1.0f) * (300.0f * pthis->dyna.actor.scale.x + 20.0f - 0.5f);
    f32 sn = Math_SinS(angle);
    f32 cs = Math_CosS(angle);
    s32 i;

    for (i = 0; i < 4; i++) {
        Vec3f faceVtx;
        Vec3f faceVtxNext;
        Vec3f posResult;
        Vec3f faceVtxOffset;
        s32 bgId;
        CollisionPoly* outPoly;

        faceVtxOffset.x = (sFaceVtx[i].x * pthis->dyna.actor.scale.x * 10.0f) + sFaceDirection[i].x;
        faceVtxOffset.y = (sFaceVtx[i].y * pthis->dyna.actor.scale.y * 10.0f) + sFaceDirection[i].y;
        faceVtxOffset.z = 0.0f;
        ObjOshihiki_RotateXZ(&faceVtx, &faceVtxOffset, sn, cs);
        faceVtx.x += pthis->dyna.actor.world.pos.x;
        faceVtx.y += pthis->dyna.actor.world.pos.y;
        faceVtx.z += pthis->dyna.actor.world.pos.z;
        faceVtxNext.x = faceVtx.x + maxDist * sn;
        faceVtxNext.y = faceVtx.y;
        faceVtxNext.z = faceVtx.z + maxDist * cs;
        if (BgCheck_EntityLineTest3(&globalCtx->colCtx, &faceVtx, &faceVtxNext, &posResult, &outPoly, true, false,
                                    false, true, &bgId, &pthis->dyna.actor, 0.0f)) {
            return true;
        }
    }
    return false;
}

s32 ObjOshihiki_MoveWithBlockUnder(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    s32 pad;
    ObjOshihiki* blockUnder = ObjOshihiki_GetBlockUnder(pthis, globalCtx);

    if ((blockUnder != NULL) && (blockUnder->stateFlags & PUSHBLOCK_SETUP_PUSH) &&
        !ObjOshihiki_CheckWall(globalCtx, blockUnder->dyna.unk_158, blockUnder->direction, pthis)) {
        pthis->blockUnder = blockUnder;
    }

    if ((pthis->stateFlags & PUSHBLOCK_MOVE_UNDER) && (pthis->blockUnder != NULL)) {
        if (pthis->blockUnder->stateFlags & PUSHBLOCK_PUSH) {
            pthis->underDistX = pthis->blockUnder->dyna.actor.world.pos.x - pthis->blockUnder->dyna.actor.prevPos.x;
            pthis->underDistZ = pthis->blockUnder->dyna.actor.world.pos.z - pthis->blockUnder->dyna.actor.prevPos.z;
            pthis->dyna.actor.world.pos.x += pthis->underDistX;
            pthis->dyna.actor.world.pos.z += pthis->underDistZ;
            ObjOshihiki_UpdateInitPos(pthis);
            return true;
        } else if (!(pthis->blockUnder->stateFlags & PUSHBLOCK_SETUP_PUSH)) {
            pthis->blockUnder = NULL;
        }
    }
    return false;
}

void ObjOshihiki_SetupOnScene(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= PUSHBLOCK_SETUP_ON_SCENE;
    pthis->actionFunc = ObjOshihiki_OnScene;
    pthis->dyna.actor.gravity = 0.0f;
    pthis->dyna.actor.velocity.x = pthis->dyna.actor.velocity.y = pthis->dyna.actor.velocity.z = 0.0f;
}

void ObjOshihiki_OnScene(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    pthis->stateFlags |= PUSHBLOCK_ON_SCENE;
    if ((pthis->timer <= 0) && (fabsf(pthis->dyna.unk_150) > 0.001f)) {
        if (ObjOshihiki_StrongEnough(pthis) &&
            !ObjOshihiki_CheckWall(globalCtx, pthis->dyna.unk_158, pthis->dyna.unk_150, pthis)) {
            pthis->direction = pthis->dyna.unk_150;
            ObjOshihiki_SetupPush(pthis, globalCtx);
        } else {
            player->stateFlags2 &= ~0x10;
            pthis->dyna.unk_150 = 0.0f;
        }
    } else {
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
    }
}

void ObjOshihiki_SetupOnActor(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= PUSHBLOCK_SETUP_ON_ACTOR;
    pthis->actionFunc = ObjOshihiki_OnActor;
    pthis->dyna.actor.velocity.x = pthis->dyna.actor.velocity.y = pthis->dyna.actor.velocity.z = 0.0f;
    pthis->dyna.actor.gravity = -1.0f;
}

void ObjOshihiki_OnActor(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    s32 bgId;
    Player* player = GET_PLAYER(globalCtx);
    DynaPolyActor* dynaPolyActor;

    pthis->stateFlags |= PUSHBLOCK_ON_ACTOR;
    Actor_MoveForward(&pthis->dyna.actor);

    if (ObjOshihiki_CheckFloor(pthis, globalCtx)) {
        bgId = pthis->floorBgIds[pthis->highestFloor];
        if (bgId == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(pthis, globalCtx);
        } else {
            dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, bgId);
            if (dynaPolyActor != NULL) {
                func_800434A8(dynaPolyActor);
                func_80043538(dynaPolyActor);

                if ((pthis->timer <= 0) && (fabsf(pthis->dyna.unk_150) > 0.001f)) {
                    if (ObjOshihiki_StrongEnough(pthis) && ObjOshihiki_NoSwitchPress(pthis, dynaPolyActor, globalCtx) &&
                        !ObjOshihiki_CheckWall(globalCtx, pthis->dyna.unk_158, pthis->dyna.unk_150, pthis)) {

                        pthis->direction = pthis->dyna.unk_150;
                        ObjOshihiki_SetupPush(pthis, globalCtx);
                    } else {
                        player->stateFlags2 &= ~0x10;
                        pthis->dyna.unk_150 = 0.0f;
                    }
                } else {
                    player->stateFlags2 &= ~0x10;
                    pthis->dyna.unk_150 = 0.0f;
                }
            } else {
                ObjOshihiki_SetupOnScene(pthis, globalCtx);
            }
        }
    } else {
        bgId = pthis->floorBgIds[pthis->highestFloor];
        if (bgId == BGCHECK_SCENE) {
            ObjOshihiki_SetupFall(pthis, globalCtx);
        } else {
            dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, bgId);

            if ((dynaPolyActor != NULL) && (dynaPolyActor->unk_15C & 1)) {
                func_800434A8(dynaPolyActor);
                func_80043538(dynaPolyActor);
                pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
            } else {
                ObjOshihiki_SetupFall(pthis, globalCtx);
            }
        }
    }
}

void ObjOshihiki_SetupPush(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= PUSHBLOCK_SETUP_PUSH;
    pthis->actionFunc = ObjOshihiki_Push;
    pthis->dyna.actor.gravity = 0.0f;
}

void ObjOshihiki_Push(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;
    Player* player = GET_PLAYER(globalCtx);
    f32 pushDistSigned;
    s32 stopFlag;

    pthis->pushSpeed += 0.5f;
    pthis->stateFlags |= PUSHBLOCK_PUSH;
    pthis->pushSpeed = CLAMP_MAX(pthis->pushSpeed, 2.0f);
    stopFlag = Math_StepToF(&pthis->pushDist, 20.0f, pthis->pushSpeed);
    pushDistSigned = ((pthis->direction >= 0.0f) ? 1.0f : -1.0f) * pthis->pushDist;
    thisx->world.pos.x = thisx->home.pos.x + (pushDistSigned * pthis->yawSin);
    thisx->world.pos.z = thisx->home.pos.z + (pushDistSigned * pthis->yawCos);

    if (!ObjOshihiki_CheckFloor(pthis, globalCtx)) {
        thisx->home.pos.x = thisx->world.pos.x;
        thisx->home.pos.z = thisx->world.pos.z;
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
        pthis->pushDist = 0.0f;
        pthis->pushSpeed = 0.0f;
        ObjOshihiki_SetupFall(pthis, globalCtx);
    } else if (stopFlag) {
        player = GET_PLAYER(globalCtx);
        if (ObjOshihiki_CheckWall(globalCtx, pthis->dyna.unk_158, pthis->dyna.unk_150, pthis)) {
            Audio_PlayActorSound2(thisx, NA_SE_EV_BLOCK_BOUND);
        }

        thisx->home.pos.x = thisx->world.pos.x;
        thisx->home.pos.z = thisx->world.pos.z;
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
        pthis->pushDist = 0.0f;
        pthis->pushSpeed = 0.0f;
        pthis->timer = 10;
        if (pthis->floorBgIds[pthis->highestFloor] == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(pthis, globalCtx);
        } else {
            ObjOshihiki_SetupOnActor(pthis, globalCtx);
        }
    }
    Audio_PlayActorSound2(thisx, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}

void ObjOshihiki_SetupFall(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    pthis->stateFlags |= PUSHBLOCK_SETUP_FALL;
    pthis->dyna.actor.velocity.x = pthis->dyna.actor.velocity.y = pthis->dyna.actor.velocity.z = 0.0f;
    pthis->dyna.actor.gravity = -1.0f;
    ObjOshihiki_SetGround(pthis, globalCtx);
    pthis->actionFunc = ObjOshihiki_Fall;
}

void ObjOshihiki_Fall(ObjOshihiki* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->stateFlags |= PUSHBLOCK_FALL;
    if (fabsf(pthis->dyna.unk_150) > 0.001f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }
    Actor_MoveForward(&pthis->dyna.actor);
    if (ObjOshihiki_CheckGround(pthis, globalCtx)) {
        if (pthis->floorBgIds[pthis->highestFloor] == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(pthis, globalCtx);
        } else {
            ObjOshihiki_SetupOnActor(pthis, globalCtx);
        }
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        Audio_PlayActorSound2(&pthis->dyna.actor,
                              SurfaceType_GetSfx(&globalCtx->colCtx, pthis->floorPolys[pthis->highestFloor],
                                                 pthis->floorBgIds[pthis->highestFloor]) +
                                  SFX_FLAG);
    }
}

void ObjOshihiki_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjOshihiki* pthis = (ObjOshihiki*)thisx;

    pthis->stateFlags &=
        ~(PUSHBLOCK_SETUP_FALL | PUSHBLOCK_FALL | PUSHBLOCK_SETUP_PUSH | PUSHBLOCK_PUSH | PUSHBLOCK_SETUP_ON_ACTOR |
          PUSHBLOCK_ON_ACTOR | PUSHBLOCK_SETUP_ON_SCENE | PUSHBLOCK_ON_SCENE);
    pthis->stateFlags |= PUSHBLOCK_MOVE_UNDER;

    if (pthis->timer > 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;

    pthis->yawSin = Math_SinS(pthis->dyna.actor.world.rot.y);
    pthis->yawCos = Math_CosS(pthis->dyna.actor.world.rot.y);

    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void ObjOshihiki_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjOshihiki* pthis = (ObjOshihiki*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_oshihiki.c", 1289);
    if (ObjOshihiki_MoveWithBlockUnder(pthis, globalCtx)) {
        Matrix_Translate(pthis->underDistX * 10.0f, 0.0f, pthis->underDistZ * 10.0f, MTXMODE_APPLY);
    }
    pthis->stateFlags &= ~PUSHBLOCK_MOVE_UNDER;
    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(pthis->texture));

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_oshihiki.c", 1308),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    switch (globalCtx->sceneNum) {
        case SCENE_YDAN:
        case SCENE_DDAN:
        case SCENE_BMORI1:
        case SCENE_HIDAN:
        case SCENE_MIZUSIN:
        case SCENE_JYASINZOU:
        case SCENE_HAKADAN:
        case SCENE_MEN:
            gDPSetEnvColor(POLY_OPA_DISP++, pthis->color.r, pthis->color.g, pthis->color.b, 255);
            break;
        default:
            gDPSetEnvColor(POLY_OPA_DISP++, mREG(13), mREG(14), mREG(15), 255);
            break;
    }

    gSPDisplayList(POLY_OPA_DISP++, gPushBlockDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_oshihiki.c", 1334);
}

void ObjOshihiki_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Oshihiki_InitVars = {
        ACTOR_OBJ_OSHIHIKI,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_DANGEON_KEEP,
        sizeof(ObjOshihiki),
        (ActorFunc)ObjOshihiki_Init,
        (ActorFunc)ObjOshihiki_Destroy,
        (ActorFunc)ObjOshihiki_Update,
        (ActorFunc)ObjOshihiki_Draw,
        (ActorFunc)ObjOshihiki_Reset,
    };

}

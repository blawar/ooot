#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DOOR_SHUTTER_Z_DOOR_SHUTTER_C
#include "actor_common.h"
/*
 * File: z_door_shutter.c
 * Overlay: ovl_Door_Shutter
 * Description: Sliding doors, Phantom Ganon room bars, Gohma room rock slab
 */

#include "z_door_shutter.h"
#include "overlays/actors/ovl_Boss_Goma/z_boss_goma.h"

#include "objects/object_gnd/object_gnd.h"
#include "objects/object_goma/object_goma.h"
#include "objects/object_ydan_objects/object_ydan_objects.h"
#include "objects/object_ddan_objects/object_ddan_objects.h"
#include "objects/object_bdan_objects/object_bdan_objects.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_bdoor/object_bdoor.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "objects/object_ganon_objects/object_ganon_objects.h"
#include "objects/object_jya_door/object_jya_door.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "objects/object_haka_door/object_haka_door.h"
#include "objects/object_ice_objects/object_ice_objects.h"
#include "objects/object_menkuri_objects/object_menkuri_objects.h"
#include "objects/object_demo_kekkai/object_demo_kekkai.h"
#include "objects/object_ouke_haka/object_ouke_haka.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"
#include "def/z_room.h"
#include "def/z_scene.h"

#define FLAGS ACTOR_FLAG_4

void DoorShutter_Init(Actor* thisx, GlobalContext* globalCtx);
void DoorShutter_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DoorShutter_Update(Actor* thisx, GlobalContext* globalCtx);
void DoorShutter_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8099803C(GlobalContext* globalCtx, s16 y, s16 countdown, s16 arg3);
void DoorShutter_SetupType(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80996A54(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80996B00(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80996B0C(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80996EE8(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80996F98(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80997004(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80997150(DoorShutter* pthis, GlobalContext* globalCtx);
void func_809973E8(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80997528(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80997568(DoorShutter* pthis, GlobalContext* globalCtx);
void func_809975C0(DoorShutter* pthis, GlobalContext* globalCtx);
void func_809976B8(DoorShutter* pthis, GlobalContext* globalCtx);
void func_80997744(DoorShutter* pthis, GlobalContext* globalCtx);

ActorInit Door_Shutter_InitVars = {
    ACTOR_DOOR_SHUTTER,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DoorShutter),
    (ActorFunc)DoorShutter_Init,
    (ActorFunc)DoorShutter_Destroy,
    (ActorFunc)DoorShutter_Update,
    (ActorFunc)DoorShutter_Draw,
};

typedef struct {
    s16 objectId;
    u8 index1;
    u8 index2;
} ShutterObjectInfo;

static ShutterObjectInfo sObjectInfo[] = {
    { OBJECT_GND, 4, 4 },
    { OBJECT_GOMA, 5, 5 },
    { OBJECT_YDAN_OBJECTS, 0, 1 },
    { OBJECT_DDAN_OBJECTS, 2, 2 },
    { OBJECT_BDAN_OBJECTS, 3, 3 },
    { OBJECT_GAMEPLAY_KEEP, 8, 8 },
    { OBJECT_BDOOR, 7, 7 },
    { OBJECT_GAMEPLAY_KEEP, 8, 8 },
    { OBJECT_HIDAN_OBJECTS, 9, 10 },
    { OBJECT_GANON_OBJECTS, 11, 11 },
    { OBJECT_JYA_DOOR, 6, 6 },
    { OBJECT_MIZU_OBJECTS, 12, 13 },
    { OBJECT_HAKA_DOOR, 14, 15 },
    { OBJECT_ICE_OBJECTS, 16, 16 },
    { OBJECT_MENKURI_OBJECTS, 17, 17 },
    { OBJECT_DEMO_KEKKAI, 18, 18 },
    { OBJECT_OUKE_HAKA, 19, 19 },
};

typedef struct {
    /* 0x0000 */ Gfx* a;
    /* 0x0004 */ Gfx* b;
    /* 0x0008 */ u8 c;
    /* 0x0009 */ u8 translateZ;
    /* 0x000A */ u8 e;
    /* 0x000B */ u8 f;
} ShutterInfo;

static ShutterInfo sShutterInfo[] = {
    { gDTDungeonDoor1DL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gDTDungeonDoor2DL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gDodongoDoorDL, gDodongoBarsDL, 240, 14, 70, 15 },
    { gJabuDoorSection1DL, gJabuWebDoorDL, 0, 110, 50, 15 },
    { gPhantomGanonBarsDL, NULL, 130, 12, 50, 15 },
    { gGohmaDoorDL, NULL, 130, 12, 50, 15 },
    { gSpiritDoorDL, gJyaDoorMetalBarsDL, 240, 14, 50, 15 },
    { object_bdoor_DL_0010C0, NULL, 130, 12, 50, 15 },
    { gDungeonDoorDL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gFireTempleDoorFrontDL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gFireTempleDoorBackDL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { object_ganon_objects_DL_0000C0, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gObjectMizuObjectsDoorShutterDL_005D90, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gObjectMizuObjectsDoorShutterDL_007000, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { object_haka_door_DL_002620, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { object_haka_door_DL_003890, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { object_ice_objects_DL_001D10, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gGTGDoorDL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { gGanonsCastleDoorDL, gDoorMetalBarsDL, 130, 12, 20, 15 },
    { object_ouke_haka_DL_0000C0, gDoorMetalBarsDL, 130, 12, 20, 15 },
};

static s8 D_80998224[] = {
    -1, -1, -1, -1, 0, 6, 1, -1, 0, -1, -1, -1,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 400, ICHAIN_STOP),
};

typedef struct {
    s16 sceneNum;
    u8 index;
} ShutterSceneInfo;

static ShutterSceneInfo sSceneInfo[] = {
    { SCENE_YDAN, 0x02 },       { SCENE_DDAN, 0x03 },         { SCENE_DDAN_BOSS, 0x03 },
    { SCENE_BDAN, 0x04 },       { SCENE_BMORI1, 0x05 },       { SCENE_HIDAN, 0x08 },
    { SCENE_GANON, 0x09 },      { SCENE_GANON_BOSS, 0x09 },   { SCENE_JYASINZOU, 0x0A },
    { SCENE_JYASINBOSS, 0x0A }, { SCENE_MIZUSIN, 0x0B },      { SCENE_HAKADAN, 0x0C },
    { SCENE_HAKADANCH, 0x0C },  { SCENE_ICE_DOUKUTO, 0x0D },  { SCENE_MEN, 0x0E },
    { SCENE_GANONTIKA, 0x0F },  { SCENE_HAKAANA_OUKE, 0x10 }, { -1, 0x07 },
};

typedef struct {
    s16 dungeonScene;
    s16 bossScene;
    u8 index;
} BossDoorInfo;

static BossDoorInfo D_80998288[] = {
    { SCENE_HIDAN, SCENE_FIRE_BS, 0x01 },
    { SCENE_MIZUSIN, SCENE_MIZUSIN_BS, 0x02 },
    { SCENE_HAKADAN, SCENE_HAKADAN_BS, 0x03 },
    { SCENE_GANON, SCENE_GANON_BOSS, 0x04 },
    { SCENE_BMORI1, SCENE_MORIBOSSROOM, 0x05 },
    { SCENE_JYASINZOU, SCENE_JYASINBOSS, 0x06 },
    { -1, -1, 0x00 },
};

static Gfx* sJabuDoorDLists[] = {
    gJabuDoorSection1DL, gJabuDoorSection2DL, gJabuDoorSection7DL, gJabuDoorSection4DL,
    gJabuDoorSection5DL, gJabuDoorSection4DL, gJabuDoorSection3DL, gJabuDoorSection2DL,
};

static void* D_809982D4[] = {
    object_bdoor_Tex_0065C0, object_bdoor_Tex_0035C0, object_bdoor_Tex_0055C0, object_bdoor_Tex_0045C0,
    object_bdoor_Tex_000000, object_bdoor_Tex_0025C0, object_bdoor_Tex_0015C0,
};

void DoorShutter_SetupAction(DoorShutter* pthis, DoorShutterActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
    pthis->unk_16F = 0;
}

s32 DoorShutter_SetupDoor(DoorShutter* pthis, GlobalContext* globalCtx) {
    TransitionActorEntry* transitionEntry = &globalCtx->transiActorCtx.list[(u16)pthis->dyna.actor.params >> 0xA];
    s8 frontRoom = transitionEntry->sides[0].room;
    s32 doorType = pthis->doorType;
    ShutterObjectInfo* temp_t0 = &sObjectInfo[pthis->unk_16B];

    if (doorType != SHUTTER_KEY_LOCKED) {
        if (frontRoom == transitionEntry->sides[1].room) {
            if (ABS((s16)(pthis->dyna.actor.shape.rot.y - pthis->dyna.actor.yawTowardsPlayer)) < 0x4000) {
                frontRoom = -1;
            }
        }
        if (frontRoom == pthis->dyna.actor.room) {
            if (doorType == SHUTTER_FRONT_SWITCH_BACK_CLEAR) { // Swap the back clear to the front clear
                doorType = SHUTTER_FRONT_CLEAR;
            } else {
                doorType = (doorType == SHUTTER_BOSS) ? SHUTTER_BACK_LOCKED : SHUTTER;
            }
        }
    }
    pthis->unk_16C = (doorType == SHUTTER) ? temp_t0->index1 : temp_t0->index2;

    if (doorType == SHUTTER_FRONT_CLEAR) {
        if (!Flags_GetClear(globalCtx, pthis->dyna.actor.room)) {
            DoorShutter_SetupAction(pthis, func_80996A54);
            pthis->unk_170 = 1.0f;
            return true;
        }
    } else if (doorType == SHUTTER_FRONT_SWITCH || doorType == SHUTTER_FRONT_SWITCH_BACK_CLEAR) {
        if (!Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
            DoorShutter_SetupAction(pthis, func_80996EE8);
            pthis->unk_170 = 1.0f;
            return true;
        }
        DoorShutter_SetupAction(pthis, func_80996F98);
        return false;
    } else if (doorType == SHUTTER_BACK_LOCKED) {
        DoorShutter_SetupAction(pthis, func_80996B00);
        return false;
    }
    DoorShutter_SetupAction(pthis, func_80996B0C);
    return false;
}

void DoorShutter_Init(Actor* thisx, GlobalContext* globalCtx2) {
    DoorShutter* pthis = (DoorShutter*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 phi_a3;
    s32 pad;
    s32 objectIndex;
    s32 i;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->dyna.actor.home.pos.z = pthis->dyna.actor.shape.yOffset;
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    pthis->doorType = (pthis->dyna.actor.params >> 6) & 0xF;
    phi_a3 = D_80998224[pthis->doorType];
    if (phi_a3 < 0) {
        ShutterSceneInfo* phi_v1;

        for (phi_v1 = &sSceneInfo[0], i = 0; i < ARRAY_COUNT(sSceneInfo) - 1; i++, phi_v1++) {
            if (globalCtx->sceneNum == phi_v1->sceneNum) {
                break;
            }
        }
        phi_a3 = phi_v1->index;
    } else if (phi_a3 == 6) {
        BossDoorInfo* phi_v1_2;

        for (phi_v1_2 = &D_80998288[0], i = 0; i < ARRAY_COUNT(D_80998288) - 1; i++, phi_v1_2++) {
            if (globalCtx->sceneNum == phi_v1_2->dungeonScene || globalCtx->sceneNum == phi_v1_2->bossScene) {
                break;
            }
        }
        pthis->unk_168 = phi_v1_2->index;
    } else {
        pthis->dyna.actor.room = -1;
    }
    //if (pthis->requiredObjBankIndex = objectIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectInfo[phi_a3].objectId),
    //   (s8)objectIndex < 0) {
    //    Actor_Kill(&pthis->dyna.actor);
    //    return;
    //}
    DoorShutter_SetupAction(pthis, DoorShutter_SetupType);
    pthis->unk_16B = phi_a3;
    if (pthis->doorType == SHUTTER_KEY_LOCKED || pthis->doorType == SHUTTER_BOSS) {
        if (!Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
            pthis->unk_16E = 10;
        }
        Actor_SetFocus(&pthis->dyna.actor, 60.0f);
    } else if (phi_a3 == 4) {
        Actor_SetScale(&pthis->dyna.actor, 0.1f);
        pthis->unk_166 = 100;
        pthis->dyna.actor.uncullZoneScale = 200.0f;
        Actor_SetFocus(&pthis->dyna.actor, 0.0f);
    } else {
        Actor_SetFocus(&pthis->dyna.actor, 60.0f);
    }
}

void DoorShutter_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DoorShutter* pthis = (DoorShutter*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    if (pthis->dyna.actor.room >= 0) {
        s32 transitionActorId = (u16)pthis->dyna.actor.params >> 0xA;

        globalCtx->transiActorCtx.list[transitionActorId].id *= -1;
    }
}

void DoorShutter_SetupType(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->requiredObjBankIndex)) {
        pthis->dyna.actor.objBankIndex = pthis->requiredObjBankIndex;
        if (pthis->doorType == SHUTTER_PG_BARS || pthis->doorType == SHUTTER_GOHMA_BLOCK) {
            // Init dynapoly for shutters of the type that uses it
            CollisionHeader* colHeader = NULL;

            Actor_SetObjectDependency(globalCtx, &pthis->dyna.actor);
            pthis->unk_16C = sObjectInfo[pthis->unk_16B].index1;
            CollisionHeader_GetVirtual((pthis->doorType == SHUTTER_GOHMA_BLOCK) ? &gGohmaDoorCol : &gPhantomGanonBarsCol,
                                       &colHeader);
            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
            if (pthis->doorType == SHUTTER_GOHMA_BLOCK) {
                pthis->dyna.actor.velocity.y = 0.0f;
                pthis->dyna.actor.gravity = -2.0f;
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_CLOSE);
                DoorShutter_SetupAction(pthis, func_809975C0);
            } else {
                DoorShutter_SetupAction(pthis, func_80997744);
                pthis->unk_164 = 7;
            }
        } else {
            DoorShutter_SetupDoor(pthis, globalCtx);
        }
    }
}

f32 func_80996840(GlobalContext* globalCtx, DoorShutter* pthis, f32 arg2, f32 arg3, f32 arg4) {
    s32 pad;
    Vec3f sp28;
    Vec3f sp1C;
    Player* player = GET_PLAYER(globalCtx);

    sp28.x = player->actor.world.pos.x;
    sp28.y = player->actor.world.pos.y + arg2;
    sp28.z = player->actor.world.pos.z;
    func_8002DBD0(&pthis->dyna.actor, &sp1C, &sp28);
    if (arg3 < fabsf(sp1C.x) || arg4 < fabsf(sp1C.y)) {
        return FLT_MAX;
    } else {
        return sp1C.z;
    }
}

s32 func_809968D4(DoorShutter* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!Player_InCsMode(globalCtx)) {
        ShutterInfo* temp_v1 = &sShutterInfo[pthis->unk_16C];
        f32 temp_f2 = func_80996840(globalCtx, pthis, (pthis->unk_16C != 3) ? 0.0f : 80.0f, temp_v1->e, temp_v1->f);

        if (fabsf(temp_f2) < 50.0f) {
            s16 phi_v0 = player->actor.shape.rot.y - pthis->dyna.actor.shape.rot.y;

            if (temp_f2 > 0.0f) {
                phi_v0 = 0x8000 - phi_v0;
            }
            if (ABS(phi_v0) < 0x3000) {
                return (temp_f2 >= 0.0f) ? 1.0f : -1.0f;
            }
        }
    }
    return 0.0f;
}

void func_80996A54(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (Flags_GetClear(globalCtx, pthis->dyna.actor.room) || Flags_GetTempClear(globalCtx, pthis->dyna.actor.room)) {
        Flags_SetClear(globalCtx, pthis->dyna.actor.room);
        DoorShutter_SetupAction(pthis, func_80997150);
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        OnePointCutscene_Attention(globalCtx, &GET_PLAYER(globalCtx)->actor);
        pthis->unk_16F = -100;
    } else if (func_809968D4(pthis, globalCtx) != 0) {
        Player* player = GET_PLAYER(globalCtx);

        player->naviTextId = -0x202;
    }
}

void func_80996B00(DoorShutter* pthis, GlobalContext* globalCtx) {
}

void func_80996B0C(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_164 != 0) {
        DoorShutter_SetupAction(pthis, func_80997004);
        pthis->dyna.actor.velocity.y = 0.0f;
        if (pthis->unk_16E != 0) {
            Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
            if (pthis->doorType != SHUTTER_BOSS) {
                gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex]--;
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK);
            } else {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK_B);
            }
        }
    } else {
        s32 doorDirection = func_809968D4(pthis, globalCtx);

        if (doorDirection != 0) {
            Player* player = GET_PLAYER(globalCtx);

            if (pthis->unk_16E != 0) {
                if (pthis->doorType == SHUTTER_BOSS) {
                    if (!CHECK_DUNGEON_ITEM(DUNGEON_KEY_BOSS, gSaveContext.mapIndex)) {
                        player->naviTextId = -0x204;
                        return;
                    }
                } else if (gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex] <= 0) {
                    player->naviTextId = -0x203;
                    return;
                }
                player->doorTimer = 10;
            }
            player->doorType = PLAYER_DOORTYPE_SLIDING;
            player->doorDirection = doorDirection;
            player->doorActor = &pthis->dyna.actor;
        }
    }
}

void func_80996C60(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->dyna.actor.category == ACTORCAT_DOOR) {
        Player* player = GET_PLAYER(globalCtx);
        s32 sp38 = pthis->unk_16C;
        s32 sp34 = 0xF;

        if (DoorShutter_SetupDoor(pthis, globalCtx)) {
            sp34 = 0x20;
        }
        DoorShutter_SetupAction(pthis, func_80997004);
        pthis->unk_16C = sp38;
        pthis->unk_170 = 0.0f;
        Camera_ChangeDoorCam(globalCtx->cameraPtrs[MAIN_CAM], &pthis->dyna.actor, player->unk_46A, 0.0f, 12, sp34, 10);
    }
}

s32 func_80996D14(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_16C != 3) {
        if (pthis->dyna.actor.velocity.y == 0.0f) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
            func_80996C60(pthis, globalCtx);
        }
        Math_StepToF(&pthis->dyna.actor.velocity.y, 15.0f, 3.0f);
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 200.0f,
                         pthis->dyna.actor.velocity.y)) {
            return true;
        }
    } else {
        if (pthis->unk_166 == 100) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYODOOR_OPEN);
            func_80996C60(pthis, globalCtx);
        }
        if (Math_StepToS(&pthis->unk_166, 0, 10)) {
            return true;
        }
    }
    return false;
}

s32 func_80996E08(DoorShutter* pthis, GlobalContext* globalCtx, f32 arg2) {
    if (pthis->unk_170 == 1.0f - arg2) {
        if (pthis->unk_16C != 3) {
            if (arg2 == 1.0f) {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_CLOSE);
            } else {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_METALDOOR_OPEN);
            }
        } else {
            if (arg2 == 1.0f) {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSHUTTER_CLOSE);
            } else {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSHUTTER_OPEN);
            }
        }
    }
    if (Math_StepToF(&pthis->unk_170, arg2, 0.2f)) {
        return true;
    }
    return false;
}

void func_80996EE8(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (func_80996E08(pthis, globalCtx, 1.0f)) {
        if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
            DoorShutter_SetupAction(pthis, func_80997150);
            OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
            pthis->unk_16F = -100;
        } else if (func_809968D4(pthis, globalCtx)) {
            Player* player = GET_PLAYER(globalCtx);
            // Jabu navi text for switch doors is different
            player->naviTextId = (globalCtx->sceneNum == SCENE_BDAN) ? -0x20B : -0x202;
        }
    }
}

void func_80996F98(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_164 == 0 && !Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
        DoorShutter_SetupAction(pthis, func_80996EE8);
    } else {
        func_80996B0C(pthis, globalCtx);
    }
}

void func_80997004(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->unk_16E) == 0 && globalCtx->roomCtx.status == 0 && func_80996D14(pthis, globalCtx) != 0) {
        if (((pthis->doorType == SHUTTER_BOSS) ? 20.0f : 50.0f) < pthis->dyna.actor.xzDistToPlayer) {
            if (DoorShutter_SetupDoor(pthis, globalCtx)) {
                pthis->dyna.actor.velocity.y = 30.0f;
            }
            if (pthis->unk_16C != 3) {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_SLIDE_DOOR_CLOSE);
                DoorShutter_SetupAction(pthis, func_809973E8);
            } else {
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYODOOR_CLOSE);
                if ((pthis->doorType == SHUTTER_FRONT_SWITCH || pthis->doorType == SHUTTER_FRONT_SWITCH_BACK_CLEAR) &&
                    !Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
                    Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSHUTTER_CLOSE);
                }
                DoorShutter_SetupAction(pthis, func_80997528);
            }
        }
    }
}

void func_80997150(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_16F != 0) {
        if (pthis->unk_16F < 0) {
            if (globalCtx->state.frames % 2 != 0) {
                pthis->unk_16F++;
            }
            if (pthis->dyna.actor.category == func_8005B198() || pthis->unk_16F == 0) {
                pthis->unk_16F = 5;
            }
        } else {
            pthis->unk_16F--;
        }
    } else if (func_80996E08(pthis, globalCtx, 0.0f)) {
        if (!(pthis->doorType == SHUTTER || pthis->doorType == SHUTTER_FRONT_CLEAR)) {
            DoorShutter_SetupAction(pthis, func_80996F98);
        } else {
            DoorShutter_SetupAction(pthis, func_80996B0C);
        }
        func_800F5B58();
    }
}

void func_80997220(DoorShutter* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s8 room = pthis->dyna.actor.room;

    if (pthis->dyna.actor.room >= 0) {
        Vec3f vec;

        func_8002DBD0(&pthis->dyna.actor, &vec, &player->actor.world.pos);
        pthis->dyna.actor.room =
            globalCtx->transiActorCtx.list[(u16)pthis->dyna.actor.params >> 0xA].sides[(vec.z < 0.0f) ? 0 : 1].room;
        if (room != pthis->dyna.actor.room) {
            Room tempRoom = globalCtx->roomCtx.curRoom;

            globalCtx->roomCtx.curRoom = globalCtx->roomCtx.prevRoom;
            globalCtx->roomCtx.prevRoom = tempRoom;
            globalCtx->roomCtx.unk_30 ^= 1;
        }
        func_80097534(globalCtx, &globalCtx->roomCtx);
        Gameplay_SetupRespawnPoint(globalCtx, RESPAWN_MODE_DOWN, 0x0EFF);
    }
    pthis->unk_164 = 0;
    pthis->dyna.actor.velocity.y = 0.0f;
    if (DoorShutter_SetupDoor(pthis, globalCtx) && !(player->stateFlags1 & 0x800)) {
        DoorShutter_SetupAction(pthis, func_80997568);
        func_8002DF54(globalCtx, NULL, 2);
    }
}

void func_809973E8(DoorShutter* pthis, GlobalContext* globalCtx) {
    s32 quakeId;

    if (pthis->dyna.actor.velocity.y < 20.0f) {
        Math_StepToF(&pthis->dyna.actor.velocity.y, 20.0f, 8.0f);
    }
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.velocity.y)) {
        if (pthis->dyna.actor.velocity.y > 20.0f) {
            pthis->dyna.actor.floorHeight = pthis->dyna.actor.home.pos.y;
            Actor_SpawnFloorDustRing(globalCtx, &pthis->dyna.actor, &pthis->dyna.actor.world.pos, 45.0f, 0xA, 8.0f, 0x1F4,
                                     0xA, 0);
        }
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
        quakeId = Quake_Add(Gameplay_GetCamera(globalCtx, 0), 3);
        Quake_SetSpeed(quakeId, -32536);
        Quake_SetQuakeValues(quakeId, 2, 0, 0, 0);
        Quake_SetCountdown(quakeId, 10);
        func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0xB4, 0x14, 0x64);
        func_80997220(pthis, globalCtx);
    }
}

void func_80997528(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (Math_StepToS(&pthis->unk_166, 0x64, 0xA)) {
        func_80997220(pthis, globalCtx);
    }
}

void func_80997568(DoorShutter* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_16F++ > 30) {
        func_8002DF54(globalCtx, NULL, 7);
        DoorShutter_SetupDoor(pthis, globalCtx);
    }
}

void func_809975C0(DoorShutter* pthis, GlobalContext* globalCtx) {
    Actor_MoveForward(&pthis->dyna.actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 0.0f, 0.0f, 0.0f, 4);
    if (pthis->dyna.actor.bgCheckFlags & 1) {
        DoorShutter_SetupAction(pthis, func_809976B8);
        if (!(gSaveContext.eventChkInf[7] & 1)) {
            BossGoma* parent = (BossGoma*)pthis->dyna.actor.parent;

            pthis->unk_164 = 10;
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONE_BOUND);
            func_8099803C(globalCtx, 2, 10, parent->subCameraId);
            Actor_SpawnFloorDustRing(globalCtx, &pthis->dyna.actor, &pthis->dyna.actor.world.pos, 70.0f, 20, 8.0f, 500,
                                     10, 1);
        }
    }
}

void func_809976B8(DoorShutter* pthis, GlobalContext* globalCtx) {
    f32 mult;

    if (pthis->unk_164 != 0) {
        pthis->unk_164--;
        mult = sinf(pthis->unk_164 * 250.0f / 100.0f);
        pthis->dyna.actor.shape.yOffset = pthis->unk_164 * 3.0f / 10.0f * mult;
    }
}

void func_80997744(DoorShutter* pthis, GlobalContext* globalCtx) {
    f32 phi_f0;

    osSyncPrintf("FHG SAKU START !!\n");
    if (pthis->unk_164 != 0) {
        pthis->unk_164--;
    }
    phi_f0 = (pthis->unk_164 % 2 != 0) ? -3.0f : 0.0f;
    Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, -34.0f + phi_f0, 1.0f, 20.0f, 0.0f);
    osSyncPrintf("FHG SAKU END !!\n");
}

void DoorShutter_Update(Actor* thisx, GlobalContext* globalCtx) {
    DoorShutter* pthis = (DoorShutter*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    if (!(player->stateFlags1 & 0x100004C0) || (pthis->actionFunc == DoorShutter_SetupType)) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

Gfx* func_80997838(GlobalContext* globalCtx, DoorShutter* pthis, Gfx* p) {
    MtxF mtx;
    f32 angle = 0.0f;
    f32 yScale = pthis->unk_166 * 0.01f;
    s32 i;

    Matrix_Get(&mtx);
    for (i = 0; i < ARRAY_COUNT(sJabuDoorDLists); i++) {
        Matrix_RotateZ(angle, MTXMODE_APPLY);
        if (i % 2 == 0) {
            Matrix_Translate(0.0f, 800.0f, 0.0f, MTXMODE_APPLY);
        } else if (i == 1 || i == 7) {
            Matrix_Translate(0.0f, 848.52f, 0.0f, MTXMODE_APPLY);
        } else {
            Matrix_Translate(0.0f, 989.94f, 0.0f, MTXMODE_APPLY);
        }
        if (pthis->unk_166 != 100) {
            Matrix_Scale(1.0f, yScale, 1.0f, MTXMODE_APPLY);
        }
        gSPMatrix(p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_door_shutter.c", 1991),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(p++, sJabuDoorDLists[i]);
        angle -= M_PI / 4;
        Matrix_Put(&mtx);
    }
    return p;
}

s32 func_80997A34(DoorShutter* pthis, GlobalContext* globalCtx) {
    s32 phi_a1;
    s32 phi_a0;

    if (Player_InCsMode(globalCtx)) {
        return true;
    }
    phi_a0 = (s16)(Actor_WorldYawTowardPoint(&pthis->dyna.actor, &globalCtx->view.eye) - pthis->dyna.actor.shape.rot.y);
    phi_a1 = (s16)(pthis->dyna.actor.yawTowardsPlayer - pthis->dyna.actor.shape.rot.y);
    phi_a0 = ABS(phi_a0);
    phi_a1 = ABS(phi_a1);
    if ((phi_a1 < 0x4000 && phi_a0 > 0x4000) || (phi_a1 > 0x4000 && phi_a0 < 0x4000)) {
        return false;
    }
    return true;
}

void DoorShutter_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DoorShutter* pthis = (DoorShutter*)thisx;

    //! @bug This actor is not fully initialized until the required object dependency is loaded.
    //! In most cases, the check for objBankIndex to equal requiredObjBankIndex prevents the actor
    //! from drawing until initialization is complete. However if the required object is the same as the
    //! object dependency listed in init vars (gameplay_keep in pthis case), the check will pass even though
    //! initialization has not completed. When pthis happens, it will try to draw the display list of the
    //! first entry in `sShutterInfo`, which will likely crash the game.
    //! This only matters in very specific scenarios, when the door is unculled on the first possible frame
    //! after spawning. It will try to draw without having run update yet.
    //!
    //! The best way to fix pthis issue (and what was done in Majora's Mask) is to null out the draw function in
    //! the init vars for the actor, and only set draw after initialization is complete.

    if (pthis->dyna.actor.objBankIndex == pthis->requiredObjBankIndex &&
        (pthis->unk_16B == 0 || func_80997A34(pthis, globalCtx) != 0)) {
        s32 pad[2];
        ShutterInfo* sp70 = &sShutterInfo[pthis->unk_16C];

        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_door_shutter.c", 2048);

        func_80093D18(globalCtx->state.gfxCtx);

        if (pthis->unk_16C == 3) {
            POLY_OPA_DISP = func_80997838(globalCtx, pthis, POLY_OPA_DISP);
            if (pthis->unk_170 != 0.0f) {
                f32 sp58 = (pthis->unk_166 * 0.01f) * pthis->unk_170;

                func_80093D18(globalCtx->state.gfxCtx);
                gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255.0f * sp58);
                Matrix_Translate(0, 0, sp70->translateZ, MTXMODE_APPLY);
                Matrix_Scale(sp58, sp58, sp58, MTXMODE_APPLY);
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_door_shutter.c", 2069),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, sp70->b);
            }
        } else {
            if (sp70->b != NULL) {
                TransitionActorEntry* transitionEntry =
                    &globalCtx->transiActorCtx.list[(u16)pthis->dyna.actor.params >> 0xA];

                if (globalCtx->roomCtx.prevRoom.num >= 0 ||
                    transitionEntry->sides[0].room == transitionEntry->sides[1].room) {
                    s32 yaw = Math_Vec3f_Yaw(&globalCtx->view.eye, &pthis->dyna.actor.world.pos);

                    if (ABS((s16)(pthis->dyna.actor.shape.rot.y - yaw)) < 0x4000) {
                        Matrix_RotateY(M_PI, MTXMODE_APPLY);
                    }
                } else if (pthis->dyna.actor.room == transitionEntry->sides[0].room) {
                    Matrix_RotateY(M_PI, MTXMODE_APPLY);
                }
            } else if (pthis->doorType == SHUTTER_BOSS) {
                gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_809982D4[pthis->unk_168]));
            }
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_door_shutter.c", 2109),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, sp70->a);
            if (pthis->unk_170 != 0.0f && sp70->b != NULL) {
                Matrix_Translate(0, sp70->c * (1.0f - pthis->unk_170), sp70->translateZ, MTXMODE_APPLY);
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_door_shutter.c", 2119),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, sp70->b);
            }
        }

        if (pthis->unk_16E != 0) {
            Matrix_Scale(0.01f, 0.01f, 0.025f, MTXMODE_APPLY);
            Actor_DrawDoorLock(globalCtx, pthis->unk_16E,
                               (pthis->doorType == SHUTTER_BOSS)
                                   ? DOORLOCK_BOSS
                                   : ((pthis->unk_16C == 6) ? DOORLOCK_NORMAL_SPIRIT : DOORLOCK_NORMAL));
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_door_shutter.c", 2135);
    }
}

void func_8099803C(GlobalContext* globalCtx, s16 y, s16 countdown, s16 camId) {
    s16 quakeId = Quake_Add(Gameplay_GetCamera(globalCtx, camId), 3);

    func_800A9F6C(0.0f, 180, 20, 100);
    Quake_SetSpeed(quakeId, 20000);
    Quake_SetQuakeValues(quakeId, y, 0, 0, 0);
    Quake_SetCountdown(quakeId, countdown);
}

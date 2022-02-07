#define INTERNAL_SRC_CODE_Z_SCENE_C
#include "global.h"
#include "segment_symbols.h"
#include "vt.h"
#include "z64global.h"
#include "z64scene.h"
#include "z64scene_asserts.h"
#include "z_scene_assets.h"
#include "z64save.h"
#include "z_kankyo.h"
#include "z64item.h"
#include "sfx.h"
#include "sequence.h"
#include "def/code_80097A00.h"
#include "def/code_800F9280.h"
#include "def/createmesgqueue.h"
#include "def/game.h"
#include "def/recvmesg.h"
#include "def/z_actor.h"
#include "def/z_actor_dlftbls.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_play.h"
#include "def/z_scene.h"
#include "def/z_std_dma.h"

#ifdef ROM_FILE
#undef ROM_FILE
#define ROM_FILE(name) \
    { (uintptr_t) name, (uintptr_t)name + sizeof(name) }
#endif

<<<<<<< HEAD
static bool (*gSceneCmdHandlers[26])(GlobalContext*, SceneCmd*);
=======
#define OBJECT_EXCHANGE_BANK_MAX 64 /* This is pretty large, original was only 19 */
#define OBJECT_INVALID 0

typedef struct ObjectStatus {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 load_state; /* 0x0 Need Load, 0x1 Loaded */
} ObjectStatus;                // size = 0x04

static ObjectStatus objectStatus[OBJECT_EXCHANGE_BANK_MAX];

static bool (*gSceneCmdHandlers[26])(GlobalContext*, const SceneCmd*);
>>>>>>> 93920ae36... feat: reimplement dma timing offset for loading objects

RomFile sNaviMsgFiles[];

s32 Object_Spawn(ObjectContext* objectCtx, s16 objectId) {
    objectStatus[objectCtx->num].id = objectId;

    osSyncPrintf("OBJECT[%d] ", objectId);
    osSyncPrintf("num= %d \n", objectCtx->num);

    ASSERT((objectCtx->num < OBJECT_EXCHANGE_BANK_MAX), "this->num < OBJECT_EXCHANGE_BANK_MAX", "../z_scene.c", 142);

    objectCtx->num++;
    objectCtx->unk_09 = objectCtx->num;

    return objectCtx->num - 1;
}

void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx) {
    GlobalContext* globalCtx2 = globalCtx; // Needs to be a new variable to match (possibly a sub struct?)
    u32 spaceSize;
    s32 i;

    if (globalCtx2->sceneNum == SCENE_SPOT00) {
        spaceSize = 1024000;
    } else if (globalCtx2->sceneNum == SCENE_GANON_DEMO) {
        if (gSaveContext.sceneSetupIndex != 4) {
            spaceSize = 1177600;
        } else {
            spaceSize = 1024000;
        }
    } else if (globalCtx2->sceneNum == SCENE_JYASINBOSS) {
        spaceSize = 1075200;
    } else if (globalCtx2->sceneNum == SCENE_KENJYANOMA) {
        spaceSize = 1075200;
    } else if (globalCtx2->sceneNum == SCENE_GANON_BOSS) {
        spaceSize = 1075200;
    } else {
        spaceSize = 1024000;
    }

    objectCtx->num = objectCtx->unk_09 = 0;
    objectCtx->mainKeepIndex = objectCtx->subKeepIndex = 0;

    for (i = 0; i < OBJECT_EXCHANGE_BANK_MAX; i++) {
        objectStatus[i].id = OBJECT_INVALID;
    }

    osSyncPrintf(VT_FGCOL(GREEN));
    // "Object exchange bank data %8.3fKB"
    osSyncPrintf("オブジェクト入れ替えバンク情報 %8.3fKB\n", spaceSize / 1024.0f);
    osSyncPrintf(VT_RST);

    objectCtx->spaceStart = GameState_Alloc(&globalCtx->state, spaceSize, "../z_scene.c", 219);
    objectCtx->spaceEnd = (void*)((s32)objectCtx->spaceStart + spaceSize);

    objectCtx->mainKeepIndex = Object_Spawn(objectCtx, OBJECT_GAMEPLAY_KEEP);
}

void Object_UpdateBank(ObjectContext* objectCtx) {
    s32 i;
    ObjectStatus* status = &objectStatus[0];

    for (i = 0; i < objectCtx->num; i++) {
        if (status->id < 0) {
            if (status->load_state == 0) {
                /* osCreateMesgQueue(&status->loadQueue, &status->loadMsg, 1); */
                status->load_state = 1;
                /* DmaMgr_SendRequest2(&status->dmaRequest, status->segment, objectFile->vromStart, size, 0,
                                    &status->loadQueue, NULL, "../z_scene.c", 266); */
            } else if (status->load_state == 1 /* !osRecvMesg(&status->loadQueue, NULL, OS_MESG_NOBLOCK) */) {
                status->id = -status->id;
            }
        }
        status++;
    }
}

s32 Object_GetIndex(ObjectContext* objectCtx, s32 objectId) {
    s32 i;

    for (i = 0; i < objectCtx->num; i++) {
        if (abs(objectStatus[i].id) == objectId) {
            return i;
        }
    }

    return -1;
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex) {
    if (objectStatus[bankIndex].id > 0) {
        return true;
    } else {
        return false;
    }
}

void func_800981B8(ObjectContext* objectCtx) {
    s32 i;
    s32 id;
    u32 size;

    for (i = 0; i < objectCtx->num; i++) {
        id = objectStatus[i].id;
        size = gObjectTable[id].vromEnd - gObjectTable[id].vromStart;
        osSyncPrintf("OBJECT[%d] SIZE %fK SEG=%x\n", objectStatus[i].id, size / 1024.0f,
                     0x0);
        osSyncPrintf("num=%d adrs=%x end=%x\n", objectCtx->num, (s32)size,
                     objectCtx->spaceEnd);
        /*DmaMgr_SendRequest1(objectCtx->status[i].segment, gObjectTable[id].vromStart, size, "../z_scene.c", 342);*/
    }
}

void* func_800982FC(ObjectContext* objectCtx, s32 bankIndex, s16 objectId) {
    ObjectStatus* status = &objectStatus[bankIndex];
    void* nextPtr;

    status->id = -objectId;
    status->load_state = 0;

    return nextPtr;
}

s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd) {
    u32 cmdCode;

    while (true) {
        cmdCode = sceneCmd->base.code;
        osSyncPrintf("*** Scene_Word = { code=%d, data1=%02x, data2=%04x } ***\n", cmdCode, sceneCmd->base.data1,
                     sceneCmd->base.data2);

        if (cmdCode == 0x14) {
            break;
        }

        if (cmdCode <= 0x19) {
            if (!(gSceneCmdHandlers[cmdCode](globalCtx, sceneCmd))) {
                break;
            }
        } else {
            osSyncPrintf(VT_FGCOL(RED));
            osSyncPrintf("code の値が異常です\n"); // "code variable is abnormal"
            osSyncPrintf(VT_RST);
        }
        sceneCmd++;
    }
    return 0;
}

bool cmd_00_unknown(GlobalContext* globalCtx, const SceneCmd* cmd) {
    ActorEntry* linkEntry = globalCtx->linkActorEntry = (ActorEntry*)SEGMENTED_TO_VIRTUAL(cmd->spawnList.segment) +
                                                        globalCtx->setupEntranceList[globalCtx->curSpawn].spawn;
    s16 linkObjectId;

    globalCtx->linkAgeOnLoad = ((void)0, gSaveContext.linkAge);

    linkObjectId = gLinkObjectIds[((void)0, gSaveContext.linkAge)];

    gActorOverlayTable[linkEntry->id].initInfo->objectId = linkObjectId;
    Object_Spawn(&globalCtx->objectCtx, linkObjectId);
    return true;
}

// Scene Command 0x01: Actor List
bool cmd_actor_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->numSetupActors = cmd->actorList.num;
    globalCtx->setupActorList = SEGMENTED_TO_VIRTUAL(cmd->actorList.segment);
    return true;
}

// Scene Command 0x02: Unused 02
bool cmd_02_unused(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->unk_11DFC = SEGMENTED_TO_VIRTUAL(cmd->unused02.segment);
    return true;
}

// Scene Command 0x03: Collision Header
bool cmd_collision_header(GlobalContext* globalCtx, const SceneCmd* cmd) {
    CollisionHeader* colHeader = SEGMENTED_TO_VIRTUAL(cmd->colHeader.segment);

    colHeader->vtxList = SEGMENTED_TO_VIRTUAL(colHeader->vtxList);
    colHeader->polyList = SEGMENTED_TO_VIRTUAL(colHeader->polyList);
    colHeader->surfaceTypeList = SEGMENTED_TO_VIRTUAL(colHeader->surfaceTypeList);
    colHeader->cameraDataList = SEGMENTED_TO_VIRTUAL(colHeader->cameraDataList);
    colHeader->waterBoxes = SEGMENTED_TO_VIRTUAL(colHeader->waterBoxes);

    BgCheck_Allocate(&globalCtx->colCtx, globalCtx, colHeader);
    return true;
}

// Scene Command 0x04: Room List
bool cmd_room_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->numRooms = cmd->roomList.num;
    globalCtx->roomList = SEGMENTED_TO_VIRTUAL(cmd->roomList.segment);
    return true;
}

// Scene Command 0x06: Entrance List
bool cmd_entrance_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->setupEntranceList = SEGMENTED_TO_VIRTUAL(cmd->entranceList.segment);
    return true;
}

// Scene Command 0x07: Special Files
bool cmd_special_files(GlobalContext* globalCtx, const SceneCmd* cmd) {
    if (cmd->specialFiles.keepObjectId != 0) {
        globalCtx->objectCtx.subKeepIndex = Object_Spawn(&globalCtx->objectCtx, cmd->specialFiles.keepObjectId);
        gSegments[5] = gObjectTable[globalCtx->objectCtx.subKeepIndex].vromStart;
    }

    if (cmd->specialFiles.cUpElfMsgNum != 0) {
        globalCtx->cUpElfMsgs = Gameplay_LoadFile(globalCtx, &sNaviMsgFiles[cmd->specialFiles.cUpElfMsgNum - 1]);
    }
    return true;
}

// Scene Command 0x08: Room Behavior
bool cmd_room_behavior(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->roomCtx.curRoom.unk_03 = cmd->roomBehavior.gpFlag1;
    globalCtx->roomCtx.curRoom.unk_02 = cmd->roomBehavior.gpFlag2 & 0xFF;
    globalCtx->roomCtx.curRoom.showInvisActors = (cmd->roomBehavior.gpFlag2 >> 8) & 1;
    globalCtx->msgCtx.disableWarpSongs = (cmd->roomBehavior.gpFlag2 >> 0xA) & 1;
    return true;
}

// Scene Command 0x0A: Mesh Header
bool cmd_mesh_header(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->roomCtx.curRoom.mesh = SEGMENTED_TO_VIRTUAL(cmd->mesh.segment);
    return true;
}

// Scene Command 0x0B: Object List
bool cmd_object_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    s32 i;
    s32 j;
    s32 k;
    ObjectStatus* status;
    ObjectStatus* status2;
    ObjectStatus* firstStatus;
    s16* objectEntry = SEGMENTED_TO_VIRTUAL(cmd->objectList.segment);
    void* nextPtr;

    k = 0;
    i = globalCtx->objectCtx.unk_09;
    firstStatus = &objectStatus[0];
    status = &objectStatus[i];

    while (i < globalCtx->objectCtx.num) {
        if (status->id != *objectEntry) {
            status2 = &objectStatus[i];
            for (j = i; j < globalCtx->objectCtx.num; j++) {
                status2->id = OBJECT_INVALID;
                status2++;
            }
            globalCtx->objectCtx.num = i;
            func_80031A28(globalCtx, &globalCtx->actorCtx);

            continue;
        }

        i++;
        k++;
        objectEntry++;
        status++;
    }

    ASSERT(cmd->objectList.num <= OBJECT_EXCHANGE_BANK_MAX, "scene_info->object_bank.num <= OBJECT_EXCHANGE_BANK_MAX",
           "../z_scene.c", 705);

    while (k < cmd->objectList.num) {
        nextPtr = func_800982FC(&globalCtx->objectCtx, i, *objectEntry);
        i++;
        k++;
        objectEntry++;
    }

    globalCtx->objectCtx.num = i;
    return true;
}

// Scene Command 0x0C: Light List
bool cmd_light_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    s32 i;
    LightInfo* lightInfo = SEGMENTED_TO_VIRTUAL(cmd->lightList.segment);

    for (i = 0; i < cmd->lightList.num; i++) {
        LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, lightInfo);
        lightInfo++;
    }
    return true;
}

// Scene Command 0x0D: Path List
bool cmd_path_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->setupPathList = SEGMENTED_TO_VIRTUAL(cmd->pathList.segment);
    return true;
}

// Scene Command 0x0E: Transition Actor List
bool cmd_transition_actor_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->transiActorCtx.numActors = cmd->transiActorList.num;
    globalCtx->transiActorCtx.list = SEGMENTED_TO_VIRTUAL(cmd->transiActorList.segment);
    return true;
}

void TransitionActor_InitContext(GameState* state, TransitionActorContext* transiActorCtx) {
    transiActorCtx->numActors = 0;
    return true;
}

// Scene Command 0x0F: Light Setting List
bool cmd_light_setting_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->envCtx.numLightSettings = cmd->lightSettingList.num;
    globalCtx->envCtx.lightSettingsList = SEGMENTED_TO_VIRTUAL(cmd->lightSettingList.segment);
    return true;
}

// Scene Command 0x11: Skybox Settings
bool cmd_skybox_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->skyboxId = cmd->skyboxSettings.skyboxId;
    globalCtx->envCtx.unk_17 = globalCtx->envCtx.unk_18 = cmd->skyboxSettings.unk_05;
    globalCtx->envCtx.indoors = cmd->skyboxSettings.unk_06;
    return true;
}

// Scene Command 0x12: Skybox Disables
bool cmd_skybox_disables(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->envCtx.skyboxDisabled = cmd->skyboxDisables.unk_04;
    globalCtx->envCtx.sunMoonDisabled = cmd->skyboxDisables.unk_05;
    return true;
}

// Scene Command 0x10: Time Settings
bool cmd_time_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    if ((cmd->timeSettings.hour != 0xFF) && (cmd->timeSettings.min != 0xFF)) {
        gSaveContext.skyboxTime = gSaveContext.dayTime =
            ((cmd->timeSettings.hour + (cmd->timeSettings.min / 60.0f)) * 60.0f) / ((f32)(24 * 60) / 0x10000);
    }

    if (cmd->timeSettings.unk_06 != 0xFF) {
        globalCtx->envCtx.timeIncrement = cmd->timeSettings.unk_06;
    } else {
        globalCtx->envCtx.timeIncrement = 0;
    }

    if (gSaveContext.sunsSongState == SUNSSONG_INACTIVE) {
        gTimeIncrement = globalCtx->envCtx.timeIncrement;
    }

    globalCtx->envCtx.sunPos.x = -(Math_SinS(((void)0, gSaveContext.dayTime) - 0x8000) * 120.0f) * 25.0f;
    globalCtx->envCtx.sunPos.y = (Math_CosS(((void)0, gSaveContext.dayTime) - 0x8000) * 120.0f) * 25.0f;
    globalCtx->envCtx.sunPos.z = (Math_CosS(((void)0, gSaveContext.dayTime) - 0x8000) * 20.0f) * 25.0f;

    if (((globalCtx->envCtx.timeIncrement == 0) && (gSaveContext.cutsceneIndex < 0xFFF0)) ||
        (gSaveContext.entranceIndex == 0x0604)) {
        gSaveContext.skyboxTime = ((void)0, gSaveContext.dayTime);
        if ((gSaveContext.skyboxTime >= 0x2AAC) && (gSaveContext.skyboxTime < 0x4555)) {
            gSaveContext.skyboxTime = 0x3556;
        } else if ((gSaveContext.skyboxTime >= 0x4555) && (gSaveContext.skyboxTime < 0x5556)) {
            gSaveContext.skyboxTime = 0x5556;
        } else if ((gSaveContext.skyboxTime >= 0xAAAB) && (gSaveContext.skyboxTime < 0xB556)) {
            gSaveContext.skyboxTime = 0xB556;
        } else if ((gSaveContext.skyboxTime >= 0xC001) && (gSaveContext.skyboxTime < 0xCAAC)) {
            gSaveContext.skyboxTime = 0xCAAC;
        }
    }
    return true;
}

// Scene Command 0x05: Wind Settings
bool cmd_wind_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    s8 x = cmd->windSettings.x;
    s8 y = cmd->windSettings.y;
    s8 z = cmd->windSettings.z;

    globalCtx->envCtx.windDirection.x = x;
    globalCtx->envCtx.windDirection.y = y;
    globalCtx->envCtx.windDirection.z = z;

    globalCtx->envCtx.windSpeed = cmd->windSettings.unk_07;
    return true;
}

// Scene Command 0x13: Exit List
bool cmd_exit_list(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->setupExitList = SEGMENTED_TO_VIRTUAL(cmd->exitList.segment);
    return true;
}

// Scene Command 0x09: Undefined
bool cmd_09_unused(GlobalContext* globalCtx, const SceneCmd* cmd) {
    return true;
}

// Scene Command 0x15: Sound Settings
bool cmd_sound_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->sequenceCtx.seqId = cmd->soundSettings.seqId;
    globalCtx->sequenceCtx.natureAmbienceId = cmd->soundSettings.natureAmbienceId;

    if (gSaveContext.seqId == (u8)NA_BGM_DISABLED) {
        Audio_QueueSeqCmd(cmd->soundSettings.specId | 0xF0000000);
    }
    return true;
}

// Scene Command 0x16: Echo Setting
bool cmd_echo_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    globalCtx->roomCtx.curRoom.echo = cmd->echoSettings.echo;
    return true;
}

// Scene Command 0x18: Alternate Headers
bool cmd_alternate_headers(GlobalContext* globalCtx, const SceneCmd* cmd) {
    s32 pad;
    SceneCmd* altHeader;

    osSyncPrintf("\n[ZU]sceneset age    =[%X]", ((void)0, gSaveContext.linkAge));
    osSyncPrintf("\n[ZU]sceneset time   =[%X]", ((void)0, gSaveContext.cutsceneIndex));
    osSyncPrintf("\n[ZU]sceneset counter=[%X]", ((void)0, gSaveContext.sceneSetupIndex));

    if (gSaveContext.sceneSetupIndex != 0) {
        altHeader = ((SceneCmd**)SEGMENTED_TO_VIRTUAL(cmd->altHeaders.segment))[gSaveContext.sceneSetupIndex - 1];

        if (1) {}

        if (altHeader != NULL) {
            Scene_ExecuteCommands(globalCtx, SEGMENTED_TO_VIRTUAL(altHeader));
            return false;
        } else {
            // "Coughh! There is no specified dataaaaa!"
            osSyncPrintf("\nげぼはっ！ 指定されたデータがないでええっす！");

            if (gSaveContext.sceneSetupIndex == 3) {
                altHeader =
                    ((SceneCmd**)SEGMENTED_TO_VIRTUAL(cmd->altHeaders.segment))[gSaveContext.sceneSetupIndex - 2];

                // "Using adult day data there!"
                osSyncPrintf("\nそこで、大人の昼データを使用するでええっす！！");

                if (altHeader != NULL) {
                    Scene_ExecuteCommands(globalCtx, SEGMENTED_TO_VIRTUAL(altHeader));
                    return false;
                }
            }
        }
    }
    return true;
}

// Scene Command 0x17: Cutscene Data
bool cmd_cutscene_data(GlobalContext* globalCtx, const SceneCmd* cmd) {
    osSyncPrintf("\ngame_play->demo_play.data=[%x]", globalCtx->csCtx.segment);
    globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(cmd->cutsceneData.segment);
    return true;
}

// Scene Command 0x19: Misc. Settings (Camera & World Map Area)
bool cmd_misc_settings(GlobalContext* globalCtx, const SceneCmd* cmd) {
    YREG(15) = cmd->miscSettings.cameraMovement;
    gSaveContext.worldMapArea = cmd->miscSettings.area;

    if ((globalCtx->sceneNum == SCENE_SHOP1) || (globalCtx->sceneNum == SCENE_SYATEKIJYOU)) {
        if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
            gSaveContext.worldMapArea = 1;
        }
    }

    if (((globalCtx->sceneNum >= SCENE_SPOT00) && (globalCtx->sceneNum <= SCENE_GANON_TOU)) ||
        ((globalCtx->sceneNum >= SCENE_ENTRA) && (globalCtx->sceneNum <= SCENE_SHRINE_R))) {
        if (gSaveContext.cutsceneIndex < 0xFFF0) {
            gSaveContext.worldMapAreaData |= gBitFlags[gSaveContext.worldMapArea];
            osSyncPrintf("０００  ａｒｅａ＿ａｒｒｉｖａｌ＝%x (%d)\n", gSaveContext.worldMapAreaData,
                         gSaveContext.worldMapArea);
        }
    }
    return true;
}

static bool (*gSceneCmdHandlers[])(GlobalContext*, const SceneCmd*) = {
    cmd_00_unknown,         cmd_actor_list,    cmd_02_unused,
    cmd_collision_header,   cmd_room_list,     cmd_wind_settings,
    cmd_entrance_list,      cmd_special_files, cmd_room_behavior,
    cmd_09_unused,          cmd_mesh_header,   cmd_object_list,
    cmd_light_list,         cmd_path_list,     cmd_transition_actor_list,
    cmd_light_setting_list, cmd_time_settings, cmd_skybox_settings,
    cmd_skybox_disables,    cmd_exit_list,     NULL,
    cmd_sound_settings,     cmd_echo_settings, cmd_cutscene_data,
    cmd_alternate_headers,  cmd_misc_settings,
};

RomFile sNaviMsgFiles[] = {
    ROM_FILE(elf_message_field),
    ROM_FILE(elf_message_ydan),
    ROM_FILE_UNSET,
};

s16 gLinkObjectIds[] = { OBJECT_LINK_BOY, OBJECT_LINK_CHILD };

u32 gObjectTableSize = ARRAY_COUNT(gObjectTable);

// Object linker symbol declarations (used in the table below)
#define DEFINE_OBJECT(name, _1) DECLARE_ROM_SEGMENT(name)
#define DEFINE_OBJECT_NULL(_0, _1)
#define DEFINE_OBJECT_UNSET(_0)

#include "tables/object_table.h"

#undef DEFINE_OBJECT
#undef DEFINE_OBJECT_NULL
#undef DEFINE_OBJECT_UNSET

// Object Table definition
#define DEFINE_OBJECT(name, _1) ROM_FILE(name),
#define DEFINE_OBJECT_NULL(name, _1) ROM_FILE_EMPTY(name),
#define DEFINE_OBJECT_UNSET(_0) { 0 },

RomFile gObjectTable[] = {
#include "tables/object_table.h"
};

#undef DEFINE_OBJECT
#undef DEFINE_OBJECT_NULL
#undef DEFINE_OBJECT_UNSET

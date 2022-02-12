#pragma once
#include "ultra64/types.h"
#include "command_macros_base.h"
#include "z64file.h"
#include "z64math.h"
#include "z64dma.h"

//struct Gfx;

#pragma pack(push, 4)

struct SCmdBase {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ uintptr_t data2;
};

struct SCmdSpawnList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdActorList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdUnused02 {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdColHeader {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdRoomList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdWindSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  x;
    /* 0x05 */ u8  y;
    /* 0x06 */ u8  z;
    /* 0x07 */ u8  unk_07;
};

struct SCmdEntranceList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdSpecialFiles {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  cUpElfMsgNum;
    /* 0x04 */ uintptr_t keepObjectId;
};

struct SCmdRoomBehavior {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  gpFlag1;
    /* 0x04 */ uintptr_t gpFlag2;
};

struct SCmdMesh {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdObjectList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdLightList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdPathList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdTransiActorList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdLightSettingList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ void* segment;
};

struct SCmdTimeSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  hour;
    /* 0x05 */ u8  min;
    /* 0x06 */ u8  unk_06;
};

struct SCmdSkyboxSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  skyboxId;
    /* 0x05 */ u8  unk_05;
    /* 0x06 */ u8  unk_06;
};

struct SCmdSkyboxDisables {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  unk_04;
    /* 0x05 */ u8  unk_05;
};

struct SCmdEndMarker {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ uintptr_t data2;
};

struct SCmdExitList {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdSoundSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  specId;
    /* 0x02 */ char pad[4];
    /* 0x06 */ u8  natureAmbienceId;
    /* 0x07 */ u8  seqId;
};

struct SCmdEchoSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[5];
    /* 0x07 */ u8  echo;
};

struct SCmdCutsceneData {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdAltHeaders {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ void* segment;
};

struct SCmdMiscSettings {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  cameraMovement;
    /* 0x04 */ uintptr_t area;
};

struct MeshHeaderBase {
    u8 headerType;
};

struct MeshHeader0 {
    MeshHeaderBase base;
    u8 numEntries;
    Gfx* dListStart;
    Gfx* dListEnd;
};

struct MeshEntry0 {
    Gfx* opaqueDList;
    Gfx* translucentDList;
};

struct MeshHeader1Base {
    MeshHeaderBase base;
    u8 format;
    Pointer entryRecord;
};

struct MeshHeader1Single {
    MeshHeader1Base base;
    void* imagePtr; // 0x08
    u32 unknown; // 0x0C
    u32 unknown2; // 0x10
    u16 bgWidth; // 0x14
    u16 bgHeight; // 0x16
    u8 imageFormat; // 0x18
    u8 imageSize; // 0x19
    u16 imagePal; // 0x1A
    u16 imageFlip; // 0x1C
};

struct MeshHeader1Multi {
    MeshHeader1Base base;
    u8 bgCnt;
    void* bgRecordPtr;
};

struct BackgroundRecord {
    u16 unknown; // 0x00
    s8 bgID; // 0x02
    void* imagePtr; // 0x04
    u32 unknown2; // 0x08
    u32 unknown3; // 0x0C
    u16 bgWidth; // 0x10
    u16 bgHeight; // 0x12
    u8 imageFmt; // 0x14
    u8 imageSize; // 0x15
    u16 imagePal; // 0x16
    u16 imageFlip; // 0x18
};

struct MeshEntry2 {
    s16 playerXMax, playerZMax;
    s16 playerXMin, playerZMin;
    Gfx* opaqueDList;
    Gfx* translucentDList;
};

struct MeshHeader2 {
    MeshHeaderBase base;
    u8 numEntries;
    Gfx* dListStart;
    Gfx* dListEnd;
};

struct LightSettings {
    /* 0x00 */ u8 ambientColor[3];
    /* 0x03 */ s8 diffuseDir1[3];
    /* 0x06 */ u8 diffuseColor1[3];
    /* 0x09 */ s8 diffuseDir2[3];
    /* 0x0C */ u8 diffuseColor2[3];
    /* 0x0F */ u8 fogColor[3];
    /* 0x12 */ u16 fogNear;
    /* 0x14 */ u16 fogFar;
}; // size = 0x16

struct Path {
    /* 0x00 */ u8 count; // number of points in the path
    /* 0x04 */ struct Vec3s* points; // Segment Address to the array of points
}; // size = 0x8

union SceneCmd {
    SCmdBase              base;
    SCmdSpawnList         spawnList;
    SCmdActorList         actorList;
    SCmdUnused02          unused02;
    SCmdRoomList          roomList;
    SCmdEntranceList      entranceList;
    SCmdObjectList        objectList;
    SCmdLightList         lightList;
    SCmdPathList          pathList;
    SCmdTransiActorList   transiActorList;
    SCmdLightSettingList  lightSettingList;
    SCmdExitList          exitList;
    SCmdColHeader         colHeader;
    SCmdMesh              mesh;
    SCmdSpecialFiles      specialFiles;
    SCmdCutsceneData      cutsceneData;
    SCmdRoomBehavior      roomBehavior;
    SCmdWindSettings      windSettings;
    SCmdTimeSettings      timeSettings;
    SCmdSkyboxSettings    skyboxSettings;
    SCmdSkyboxDisables    skyboxDisables;
    SCmdEndMarker         endMarker;
    SCmdSoundSettings     soundSettings;
    SCmdEchoSettings      echoSettings;
    SCmdMiscSettings      miscSettings;
    SCmdAltHeaders        altHeaders;
}; // size = 0x8

enum SceneID {
    /* 0x00 */ SCENE_YDAN,
    /* 0x01 */ SCENE_DDAN,
    /* 0x02 */ SCENE_BDAN,
    /* 0x03 */ SCENE_BMORI1,
    /* 0x04 */ SCENE_HIDAN,
    /* 0x05 */ SCENE_MIZUSIN,
    /* 0x06 */ SCENE_JYASINZOU,
    /* 0x07 */ SCENE_HAKADAN,
    /* 0x08 */ SCENE_HAKADANCH,
    /* 0x09 */ SCENE_ICE_DOUKUTO,
    /* 0x0A */ SCENE_GANON,
    /* 0x0B */ SCENE_MEN,
    /* 0x0C */ SCENE_GERUDOWAY,
    /* 0x0D */ SCENE_GANONTIKA,
    /* 0x0E */ SCENE_GANON_SONOGO,
    /* 0x0F */ SCENE_GANONTIKA_SONOGO,
    /* 0x10 */ SCENE_TAKARAYA,
    /* 0x11 */ SCENE_YDAN_BOSS,
    /* 0x12 */ SCENE_DDAN_BOSS,
    /* 0x13 */ SCENE_BDAN_BOSS,
    /* 0x14 */ SCENE_MORIBOSSROOM,
    /* 0x15 */ SCENE_FIRE_BS,
    /* 0x16 */ SCENE_MIZUSIN_BS,
    /* 0x17 */ SCENE_JYASINBOSS,
    /* 0x18 */ SCENE_HAKADAN_BS,
    /* 0x19 */ SCENE_GANON_BOSS,
    /* 0x1A */ SCENE_GANON_FINAL,
    /* 0x1B */ SCENE_ENTRA,
    /* 0x1C */ SCENE_ENTRA_N,
    /* 0x1D */ SCENE_ENRUI,
    /* 0x1E */ SCENE_MARKET_ALLEY,
    /* 0x1F */ SCENE_MARKET_ALLEY_N,
    /* 0x20 */ SCENE_MARKET_DAY,
    /* 0x21 */ SCENE_MARKET_NIGHT,
    /* 0x22 */ SCENE_MARKET_RUINS,
    /* 0x23 */ SCENE_SHRINE,
    /* 0x24 */ SCENE_SHRINE_N,
    /* 0x25 */ SCENE_SHRINE_R,
    /* 0x26 */ SCENE_KOKIRI_HOME,
    /* 0x27 */ SCENE_KOKIRI_HOME3,
    /* 0x28 */ SCENE_KOKIRI_HOME4,
    /* 0x29 */ SCENE_KOKIRI_HOME5,
    /* 0x2A */ SCENE_KAKARIKO,
    /* 0x2B */ SCENE_KAKARIKO3,
    /* 0x2C */ SCENE_SHOP1,
    /* 0x2D */ SCENE_KOKIRI_SHOP,
    /* 0x2E */ SCENE_GOLON,
    /* 0x2F */ SCENE_ZOORA,
    /* 0x30 */ SCENE_DRAG,
    /* 0x31 */ SCENE_ALLEY_SHOP,
    /* 0x32 */ SCENE_NIGHT_SHOP,
    /* 0x33 */ SCENE_FACE_SHOP,
    /* 0x34 */ SCENE_LINK_HOME,
    /* 0x35 */ SCENE_IMPA,
    /* 0x36 */ SCENE_MALON_STABLE,
    /* 0x37 */ SCENE_LABO,
    /* 0x38 */ SCENE_HYLIA_LABO,
    /* 0x39 */ SCENE_TENT,
    /* 0x3A */ SCENE_HUT,
    /* 0x3B */ SCENE_DAIYOUSEI_IZUMI,
    /* 0x3C */ SCENE_YOUSEI_IZUMI_TATE,
    /* 0x3D */ SCENE_YOUSEI_IZUMI_YOKO,
    /* 0x3E */ SCENE_KAKUSIANA,
    /* 0x3F */ SCENE_HAKAANA,
    /* 0x40 */ SCENE_HAKAANA2,
    /* 0x41 */ SCENE_HAKAANA_OUKE,
    /* 0x42 */ SCENE_SYATEKIJYOU,
    /* 0x43 */ SCENE_TOKINOMA,
    /* 0x44 */ SCENE_KENJYANOMA,
    /* 0x45 */ SCENE_HAIRAL_NIWA,
    /* 0x46 */ SCENE_HAIRAL_NIWA_N,
    /* 0x47 */ SCENE_HIRAL_DEMO,
    /* 0x48 */ SCENE_HAKASITARELAY,
    /* 0x49 */ SCENE_TURIBORI,
    /* 0x4A */ SCENE_NAKANIWA,
    /* 0x4B */ SCENE_BOWLING,
    /* 0x4C */ SCENE_SOUKO,
    /* 0x4D */ SCENE_MIHARIGOYA,
    /* 0x4E */ SCENE_MAHOUYA,
    /* 0x4F */ SCENE_GANON_DEMO,
    /* 0x50 */ SCENE_KINSUTA,
    /* 0x51 */ SCENE_SPOT00,
    /* 0x52 */ SCENE_SPOT01,
    /* 0x53 */ SCENE_SPOT02,
    /* 0x54 */ SCENE_SPOT03,
    /* 0x55 */ SCENE_SPOT04,
    /* 0x56 */ SCENE_SPOT05,
    /* 0x57 */ SCENE_SPOT06,
    /* 0x58 */ SCENE_SPOT07,
    /* 0x59 */ SCENE_SPOT08,
    /* 0x5A */ SCENE_SPOT09,
    /* 0x5B */ SCENE_SPOT10,
    /* 0x5C */ SCENE_SPOT11,
    /* 0x5D */ SCENE_SPOT12,
    /* 0x5E */ SCENE_SPOT13,
    /* 0x5F */ SCENE_SPOT15,
    /* 0x60 */ SCENE_SPOT16,
    /* 0x61 */ SCENE_SPOT17,
    /* 0x62 */ SCENE_SPOT18,
    /* 0x63 */ SCENE_SPOT20,
    /* 0x64 */ SCENE_GANON_TOU,
    // Debug only scenes
    /* 0x65 */ SCENE_TEST01,
    /* 0x66 */ SCENE_BESITU,
    /* 0x67 */ SCENE_DEPTH_TEST,
    /* 0x68 */ SCENE_SYOTES,
    /* 0x69 */ SCENE_SYOTES2,
    /* 0x6A */ SCENE_SUTARU,
    /* 0x6B */ SCENE_HAIRAL_NIWA2,
    /* 0x6C */ SCENE_SASATEST,
    /* 0x6D */ SCENE_TESTROOM,
    /* 0x6E */ SCENE_ID_MAX
};

// Scene commands

enum SceneCommandTypeID {
    /* 0x00 */ SCENE_CMD_ID_SPAWN_LIST,
    /* 0x01 */ SCENE_CMD_ID_ACTOR_LIST,
    /* 0x02 */ SCENE_CMD_ID_UNUSED_02,
    /* 0x03 */ SCENE_CMD_ID_COL_HEADER,
    /* 0x04 */ SCENE_CMD_ID_ROOM_LIST,
    /* 0x05 */ SCENE_CMD_ID_WIND_SETTINGS,
    /* 0x06 */ SCENE_CMD_ID_ENTRANCE_LIST,
    /* 0x07 */ SCENE_CMD_ID_SPECIAL_FILES,
    /* 0x08 */ SCENE_CMD_ID_ROOM_BEHAVIOR,
    /* 0x09 */ SCENE_CMD_ID_UNK_09,
    /* 0x0A */ SCENE_CMD_ID_MESH,
    /* 0x0B */ SCENE_CMD_ID_OBJECT_LIST,
    /* 0x0C */ SCENE_CMD_ID_LIGHT_LIST,
    /* 0x0D */ SCENE_CMD_ID_PATH_LIST,
    /* 0x0E */ SCENE_CMD_ID_TRANSI_ACTOR_LIST,
    /* 0x0F */ SCENE_CMD_ID_ENV_LIGHT_SETTINGS,
    /* 0x10 */ SCENE_CMD_ID_TIME_SETTINGS,
    /* 0x11 */ SCENE_CMD_ID_SKYBOX_SETTINGS,
    /* 0x12 */ SCENE_CMD_ID_SKYBOX_DISABLES,
    /* 0x13 */ SCENE_CMD_ID_EXIT_LIST,
    /* 0x14 */ SCENE_CMD_ID_END,
    /* 0x15 */ SCENE_CMD_ID_SOUND_SETTINGS,
    /* 0x16 */ SCENE_CMD_ID_ECHO_SETTINGS,
    /* 0x17 */ SCENE_CMD_ID_CUTSCENE_DATA,
    /* 0x18 */ SCENE_CMD_ID_ALTERNATE_HEADER_LIST,
    /* 0x19 */ SCENE_CMD_ID_MISC_SETTINGS
};

#define SCENE_CMD_SPAWN_LIST(numSpawns, spawnList) \
    { SCENE_CMD_ID_SPAWN_LIST, numSpawns, CMD_PTR(spawnList) }

#define SCENE_CMD_ACTOR_LIST(numActors, actorList) \
    { SCENE_CMD_ID_ACTOR_LIST, numActors, CMD_PTR(actorList) }

#define SCENE_CMD_UNUSED_02(unk, data) \
    { SCENE_CMD_ID_UNUSED_02, unk, CMD_PTR(data) }

#define SCENE_CMD_COL_HEADER(colHeader) \
    { SCENE_CMD_ID_COL_HEADER, 0, CMD_PTR(colHeader) }

#define SCENE_CMD_ROOM_LIST(numRooms, roomList) \
    { SCENE_CMD_ID_ROOM_LIST, numRooms, CMD_PTR(roomList) }

#define SCENE_CMD_WIND_SETTINGS(xDir, yDir, zDir, strength) \
    { SCENE_CMD_ID_WIND_SETTINGS, 0, CMD_BBBB(xDir, yDir, zDir, strength) }

#define SCENE_CMD_ENTRANCE_LIST(entranceList) \
    { SCENE_CMD_ID_ENTRANCE_LIST, 0, CMD_PTR(entranceList) }

#define SCENE_CMD_SPECIAL_FILES(elfMessageFile, keepObjectId) \
    { SCENE_CMD_ID_SPECIAL_FILES, elfMessageFile, CMD_W(keepObjectId) }

#define SCENE_CMD_ROOM_BEHAVIOR(curRoomUnk3, curRoomUnk2, showInvisActors, disableWarpSongs) \
    { SCENE_CMD_ID_ROOM_BEHAVIOR, curRoomUnk3, \
        curRoomUnk2 | _SHIFTL(showInvisActors, 8, 1) | _SHIFTL(disableWarpSongs, 10, 1) }

#define SCENE_CMD_UNK_09() \
    { SCENE_CMD_ID_UNK_09, 0, CMD_W(0) }

#define SCENE_CMD_MESH(meshHeader) \
    { SCENE_CMD_ID_MESH, 0, CMD_PTR(meshHeader) }

#define SCENE_CMD_OBJECT_LIST(numObjects, objectList) \
    { SCENE_CMD_ID_OBJECT_LIST, numObjects, CMD_PTR(objectList) }

#define SCENE_CMD_LIGHT_LIST(numLights, lightList) \
    { SCENE_CMD_ID_POS_LIGHT_LIST, numLights, CMD_PTR(lightList) } 

#define SCENE_CMD_PATH_LIST(pathList) \
    { SCENE_CMD_ID_PATH_LIST, 0, CMD_PTR(pathList) }

#define SCENE_CMD_TRANSITION_ACTOR_LIST(numActors, list) \
    { SCENE_CMD_ID_TRANSI_ACTOR_LIST, numActors, CMD_PTR(list) } 

#define SCENE_CMD_ENV_LIGHT_SETTINGS(numLightSettings, lightSettingsList) \
    { SCENE_CMD_ID_ENV_LIGHT_SETTINGS, numLightSettings, CMD_PTR(lightSettingsList) }

#define SCENE_CMD_TIME_SETTINGS(hour, min, speed) \
    { SCENE_CMD_ID_TIME_SETTINGS, 0, CMD_BBBB(hour, min, speed, 0) }

#define SCENE_CMD_SKYBOX_SETTINGS(skyboxId, weather, isIndoors) \
    { SCENE_CMD_ID_SKYBOX_SETTINGS, 0, CMD_BBBB(skyboxId, weather, isIndoors, 0) }

#define SCENE_CMD_SKYBOX_DISABLES(disableSky, disableSunMoon) \
    { SCENE_CMD_ID_SKYBOX_DISABLES, 0, CMD_BBBB(disableSky, disableSunMoon, 0, 0) }

#define SCENE_CMD_EXIT_LIST(exitList) \
    { SCENE_CMD_ID_EXIT_LIST, 0, CMD_PTR(exitList) }

#define SCENE_CMD_END() \
    { SCENE_CMD_ID_END, 0, CMD_W(0) }

#define SCENE_CMD_SOUND_SETTINGS(specId, natureAmbienceId, seqId) \
    { SCENE_CMD_ID_SOUND_SETTINGS, specId, CMD_BBBB(0, 0, natureAmbienceId, seqId) }

#define SCENE_CMD_ECHO_SETTINGS(echo) \
    { SCENE_CMD_ID_ECHO_SETTINGS, 0, CMD_BBBB(0, 0, 0, echo) }

#define SCENE_CMD_CUTSCENE_DATA(cutsceneData) \
    { SCENE_CMD_ID_CUTSCENE_DATA, 0, CMD_PTR(cutsceneData) }

#define SCENE_CMD_ALTERNATE_HEADER_LIST(alternateHeaderList) \
    { SCENE_CMD_ID_ALTERNATE_HEADER_LIST, 0, CMD_PTR(alternateHeaderList) }

#define SCENE_CMD_MISC_SETTINGS(camMode, worldMapLocation) \
    { SCENE_CMD_ID_MISC_SETTINGS, camMode, CMD_W(worldMapLocation) }


struct SceneTableEntry {
    RomFile sceneFile;
    RomFile titleFile;
    u8 unk_10;
    u8 config;
    u8 unk_12;
    u8 unk_13;
    SceneCmd* cmds;
}; // size = 0x14

#pragma pack(pop)

struct PolygonDlist {
    /* 0x00 */ Gfx* opa;
    /* 0x04 */ Gfx* xlu;
}; // size = 0x8

struct ZPolygon {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 num; // number of dlist entries
    /* 0x04 */ void* start;
    /* 0x08 */ void* end;
}; // size = 0xC

struct PolygonType0 {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 num; // number of dlist entries
    /* 0x04 */ void* start;
    /* 0x08 */ void* end;
}; // size = 0xC

struct BgImage {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 id;
    /* 0x04 */ Pointer source;
    /* 0x08 */ u32 unk_0C;
    /* 0x0C */ Pointer tlut;
    /* 0x10 */ u16 width;
    /* 0x12 */ u16 height;
    /* 0x14 */ u8 fmt;
    /* 0x15 */ u8 siz;
    /* 0x16 */ u16 mode0;
    /* 0x18 */ u16 tlutCount;
}; // size = 0x1C

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 format; // 1 = single, 2 = multi
    /* 0x04 */ Gfx* dlist;
    union {
        struct {
            /* 0x08 */ void* source;
            /* 0x0C */ u32 unk_0C;
            /* 0x10 */ void* tlut;
            /* 0x14 */ u16 width;
            /* 0x16 */ u16 height;
            /* 0x18 */ u8 fmt;
            /* 0x19 */ u8 siz;
            /* 0x1A */ u16 mode0;
            /* 0x1C */ u16 tlutCount;
        } single;
        struct {
            /* 0x08 */ u8 count;
            /* 0x0C */ BgImage* list;
        } multi;
    };
} PolygonType1;

struct PolygonDlist2 {
    /* 0x00 */ Vec3s pos;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Gfx* opa;
    /* 0x0C */ Gfx* xlu;
}; // size = 0x8

struct PolygonType2 {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 num; // number of dlist entries
    /* 0x04 */ void* start;
    /* 0x08 */ void* end;
}; // size = 0xC

union Mesh {
    ZPolygon polygon;
    PolygonType0 polygon0;
    PolygonType1 polygon1;
    PolygonType2 polygon2;
}; // "Ground Shape"

struct Room {
    /* 0x00 */ s8 num;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s8 echo;
    /* 0x05 */ u8 showInvisActors;
    /* 0x08 */ Mesh* mesh; // original name: "ground_shape"
    /* 0x0C */ void* segment;
    /* 0x10 */ char unk_10[0x4];
}; // size = 0x14

struct RoomContext {
    /* 0x00 */ Room curRoom;
    /* 0x14 */ Room prevRoom;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ s8 status;
    /* 0x34 */ void* unk_34;
    /* 0x38 */ DmaRequest dmaRequest;
    /* 0x58 */ OSMesgQueue loadQueue;
    /* 0x70 */ OSMesg loadMsg;
    /* 0x74 */ s16 unk_74[2]; // context-specific data used by the current scene draw config
};                // size = 0x78

typedef struct {
    struct {
        s8 room;           // Room to switch to
        s8 effects;        // How the camera reacts during the transition
    } /* 0x00 */ sides[2]; // 0 = front, 1 = back
    /* 0x04 */ s16 id;
    /* 0x06 */ Vec3s pos;
    /* 0x0C */ s16 rotY;
    /* 0x0E */ s16 params;
} TransitionActorEntry; // size = 0x10

struct TransitionActorContext {
    /* 0x00 */ u8 numActors;
    /* 0x04 */ TransitionActorEntry* list;
};

struct EntranceEntry {
    /* 0x00 */ u8 spawn;
    /* 0x01 */ u8 room;
};


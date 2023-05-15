#pragma once

#include "framerate.h"
#include "ultra64.h"
#include "z64math.h"
#include "globalctx.h"
#include "def/z_file_choose.h"

struct FileChooseContext;

#define SLOT_SIZE 0x1450

struct ItemEquips
{
	/* 0x00 */ u8 buttonItems[4];
	/* 0x04 */ u8 cButtonSlots[3];
	/* 0x08 */ u16 equipment;
}; // size = 0x0A

struct Inventory
{
	/* 0x00 */ u8 items[24];
	/* 0x18 */ s8 ammo[16];
	/* 0x28 */ u16 equipment;
	// u16 equipmentPadding;
	/* 0x2C */ u32 upgrades;
	/* 0x30 */ u32 questItems;
	/* 0x34 */ u8 dungeonItems[20];
	/* 0x48 */ s8 dungeonKeys[19];
	/* 0x5B */ s8 defenseHearts;
	/* 0x5C */ s16 gsTokens;
	// s16 gsTokensPadding;
}; // size = 0x60

static_assert(sizeof(Inventory) == 0x60, "Save Inventory incorrect size");

struct SavedSceneFlags
{
	/* 0x00 */ u32 chest;
	/* 0x04 */ u32 swch;
	/* 0x08 */ u32 clear;
	/* 0x0C */ u32 collect;
	/* 0x10 */ u32 unk;
	/* 0x14 */ u32 rooms;
	/* 0x18 */ u32 floors;
}; // size = 0x1C

struct HorseData
{
	/* 0x00 */ s16 scene;
	/* 0x02 */ Vec3s pos;
	/* 0x08 */ s16 angle;
}; // size = 0x0A

struct RespawnData
{
	/* 0x00 */ Vec3f pos;
	/* 0x0C */ s16 yaw;
	/* 0x0E */ s16 playerParams;
	/* 0x10 */ s16 entranceIndex;
	/* 0x12 */ u8 roomIndex;
	/* 0x13 */ s8 data;
	/* 0x14 */ u32 tempSwchFlags;
	/* 0x18 */ u32 tempCollectFlags;
}; // size = 0x1C

struct FaroresWindData
{
	/* 0x00 */ Vec3i pos;
	/* 0x0C */ s32 yaw;
	/* 0x10 */ s32 playerParams;
	/* 0x14 */ s32 entranceIndex;
	/* 0x18 */ s32 roomIndex;
	/* 0x1C */ s32 set;
	/* 0x20 */ s32 tempSwchFlags;
	/* 0x24 */ s32 tempCollectFlags;
}; // size = 0x28

namespace oot::save
{
	static const u8 MAX_SLOTS = 3;

	struct PlayerData
	{
		/* 0x00 */ char newf[6]; // string "ZELDAZ"
		/* 0x06 */ s16 deaths;
		/* 0x08 */ char playerName[8];
		/* 0x10 */ s16 n64ddFlag;
		/* 0x12 */ s16 healthCapacity; // "max_life"
		/* 0x14 */ s16 health;	       // "now_life"
		/* 0x16 */ s8 magicLevel;
		/* 0x17 */ s8 magic;
		/* 0x18 */ s16 rupees;
		/* 0x1A */ u16 swordHealth;
		/* 0x1C */ u16 naviTimer;
		/* 0x1E */ u8 magicAcquired;
		/* 0x1F */ u8 unk_3B;
		/* 0x20 */ u8 doubleMagic;
		/* 0x21 */ u8 doubleDefense;
		/* 0x22 */ u8 bgsFlag;
		/* 0x23 */ u8 ocarinaGameRoundNum;
		/* 0x24 */ ItemEquips childEquips;
		/* 0x2E */ ItemEquips adultEquips;
		/* 0x38 */ u32 unk_54; // this may be incorrect, currently used for alignement
		/* 0x3C */ char unk_58[0x0E];
		/* 0x4A */ s16 savedSceneNum;

		void setMagic();
		bool isMagicValid() const;
	}; // size = 0x4C

	static_assert(sizeof(PlayerData) == 0x4C, "Save PlayerData incorrect size");

	struct Info
	{
		/* 0x0000 */ PlayerData playerData; // "S_Private" substruct name
		/* 0x004C */ ItemEquips equips;
		/* 0x0058 */ Inventory inventory;
		/* 0x00B8 */ SavedSceneFlags sceneFlags[124];
		/* 0x0E48 */ FaroresWindData fw;
		/* 0x0E70 */ char unk_E8C[0x10];
		/* 0x0E80 */ s32 gsFlags[6];
		/* 0x0E98 */ char unk_EB4[0x4];
		/* 0x0EA8 */ s32 highScores[7];
		/* 0x0EB8 */ u16 eventChkInf[14]; // "event_chk_inf"
		/* 0x0ED4 */ u16 itemGetInf[4];	  // "item_get_inf"
		/* 0x0EDC */ u16 infTable[30];	  // "inf_table"
		/* 0x0F18 */ char unk_F34[0x04];
		/* 0x0F1C */ u32 worldMapAreaData; // "area_arrival"
		/* 0x0F20 */ char unk_F3C[0x4];
		/* 0x0F24 */ u8 scarecrowCustomSongSet;
		/* 0x0F25 */ u8 scarecrowCustomSong[0x360];
		/* 0x1285 */ char unk_12A1[0x24];
		/* 0x12A9 */ u8 scarecrowSpawnSongSet;
		/* 0x12AA */ u8 scarecrowSpawnSong[0x80];
		/* 0x132A */ char unk_1346[0x02];
		/* 0x132C */ HorseData horseData;
		/* 0x1336 */ u16 checksum; // "check_sum"
	};

	static_assert(offsetof(Info, inventory) == 0x58, "Inventory out of alignment");
	static_assert(sizeof(Info) == 0x1338, "Save Info incorrect size");

	struct Save
	{
		/* 0x00 */ s32 entranceIndex;
		/* 0x04 */ s32 linkAge; // 0: Adult; 1: Child
		/* 0x08 */ s32 cutsceneIndex;
		/* 0x0C */ u16 dayTime; // "zelda_time"
		// u16 dayTimePadding;
		/* 0x10 */ s32 nightFlag;
		/* 0x14 */ s32 totalDays;
		/* 0x18 */ s32 bgsDayCount; // increments with totalDays, gets reset by goron for bgs and one other use
		/* 0x1C */ Info info;	    // "information"

		u16 checksum();
	};

	static_assert(offsetof(Save, dayTime) == 0x0C, "dayTime out of alignment");
	static_assert(offsetof(Save, nightFlag) == 0x10, "nightFlag out of alignment");
	static_assert(sizeof(Save) == 0x1C + sizeof(Info), "Save incorrect size");

	struct Slot
	{
		Save save;

		/* 0x1354 */ s32 fileNum; // "file_no"
		/* 0x1358 */ char unk_1358[0x0004];
		/* 0x135C */ s32 gameMode;
		/* 0x1360 */ s32 sceneSetupIndex;
		/* 0x1364 */ s32 respawnFlag;	     // "restart_flag"
		/* 0x1368 */ RespawnData respawn[3]; // "restart_data"
		/* 0x13BC */ f32 entranceSpeed;
		/* 0x13C0 */ u16 entranceSound;
		/* 0x13C2 */ char unk_13C2[0x0001];
		/* 0x13C3 */ u8 unk_13C3;
		/* 0x13C4 */ s16 dogParams;
		/* 0x13C6 */ u8 textTriggerFlags;
		/* 0x13C7 */ u8 showTitleCard;
		/* 0x13C8 */ s16 nayrusLoveTimer;
		/* 0x13CA */ char unk_13CA[0x0002];
		/* 0x13CC */ s16 rupeeAccumulator;
		/* 0x13CE */ s16 timer1State;
		/* 0x13D0 */ s16 timer1Value;
		/* 0x13D2 */ s16 timer2State;
		/* 0x13D4 */ s16 timer2Value;
		/* 0x13D6 */ s16 timerX[2];
		/* 0x13DA */ s16 timerY[2];
		/* 0x13DE */ char unk_13DE[0x0002];
		/* 0x13E0 */ u8 seqId;
		/* 0x13E1 */ u8 natureAmbienceId;
		/* 0x13E2 */ u8 buttonStatus[5];
		/* 0x13E7 */ u8 startDemo;    // alpha related
		/* 0x13E8 */ u16 unk_13E8;    // alpha type?
		/* 0x13EA */ u16 unk_13EA;    // also alpha type?
		/* 0x13EC */ u16 unk_13EC;    // alpha type counter?
		/* 0x13EE */ u16 unk_13EE;    // previous alpha type?
		/* 0x13F0 */ s16 unk_13F0;    // magic related
		/* 0x13F2 */ s16 unk_13F2;    // magic related
		/* 0x13F4 */ s16 unk_13F4;    // magic related
		/* 0x13F6 */ s16 unk_13F6;    // magic related
		/* 0x13F8 */ s16 unk_13F8;    // magic related
		/* 0x13FA */ u16 eventInf[4]; // "event_inf"
		/* 0x1402 */ u16 mapIndex;    // intended for maps/minimaps but commonly used as the dungeon index
		/* 0x1404 */ u16 minigameState;
		/* 0x1406 */ u16 minigameScore; // "yabusame_total"
		/* 0x1408 */ char unk_1408[0x0001];
		/* 0x1409 */ u8 language; // NTSC 0: Japanese; 1: English | PAL 0: English; 1: German; 2: French
		/* 0x140A */ u8 audioSetting;
		/* 0x140B */ char unk_140B[0x0001];
		/* 0x140C */ u8 zTargetSetting; // 0: Switch; 1: Hold
		/* 0x140E */ u16 forcedSeqId;	// immediately start playing the sequence if set
		/* 0x1410 */ u8 unk_1410;	// transition related
		/* 0x1411 */ char unk_1411[0x0001];
		/* 0x1412 */ u16 nextCutsceneIndex;
		/* 0x1414 */ u8 cutsceneTrigger;
		/* 0x1415 */ u8 chamberCutsceneNum;
		/* 0x1416 */ u16 nextDayTime; // "next_zelda_time"
		/* 0x1418 */ u8 fadeDuration;
		/* 0x1419 */ u8 wipeSpeed; // transition related
		/* 0x141A */ u16 skyboxTime;
		/* 0x141C */ u8 dogIsLost;
		/* 0x141D */ u8 nextTransition;
		/* 0x141E */ char unk_141E[0x0002];
		/* 0x1420 */ s16 worldMapArea;
		/* 0x1422 */ s16 sunsSongState; // controls the effects of suns song
		/* 0x1424 */ s16 healthAccumulator;
		u8 padding[0x28];
	}; // size = 0x1428

	static_assert(sizeof(Slot) == SLOT_SIZE, "Save Slot incorrect size");
	static_assert(offsetof(Slot, healthAccumulator) == 0x1424, "healthAccumulator out of alignment");
	static_assert(offsetof(Slot, fileNum) == 0x1354, "healthAccumulator out of alignment");

	struct Header
	{
		u8 sound;
		u8 ztarget;
		u8 language;
		u8 magic[13];
	};

	static_assert(sizeof(Header) == 0x10, "Save Header incorrect size");

	struct File
	{
		Header header;
		u8 ukn[0x10];
		Slot slots[MAX_SLOTS * 2];

		bool isValidMagic() const;
		bool isValidMagicSwapped() const;
		void init(GameState* gameState, u32 depth = 0);
		void save();
		void saveHeader();
		void load();
	};

	static_assert(sizeof(File) == 0x20 + SLOT_SIZE * (MAX_SLOTS * 2), "Save File incorrect size");

	struct Context
	{
		Context();
		void create();
		void createDebug();
		void copy(const u8 selectedFileIndex, const u8 copyDestFileIndex);
		void open(const u8 index);
		void save();
		void loadAllSaves(gamestate::FileChoose* fileChooseCtx);
		void initialize(gamestate::FileChoose* fileChooseCtx, const u8 slotId);
		void erase(const u8 slotId);
		void init();
		const s32& fileNumber() const;
		s32& fileNumber();

		/* 0x0000 */ s32 entranceIndex; // start of `save` substruct, originally called "memory"
		/* 0x0004 */ s32 linkAge;	// 0: Adult; 1: Child
		/* 0x0008 */ s32 cutsceneIndex;
		/* 0x000C */ Counter dayTime; // "zelda_time"
		// u16 dayTimePadding;
		/* 0x0010 */ s32 nightFlag;
		/* 0x0014 */ s32 totalDays;
		/* 0x0018 */ s32 bgsDayCount; // increments with totalDays, can be cleared with `Environment_ClearBgsDayCount`
		/* 0x001C */ char newf[6];    // string "ZELDAZ". start of `info` substruct, originally called "information"
		/* 0x0022 */ u16 deaths;
		/* 0x0024 */ char playerName[8];
		/* 0x002C */ s16 n64ddFlag;
		/* 0x002E */ s16 healthCapacity; // "max_life"
		/* 0x0030 */ s16 health;	 // "now_life"
		/* 0x0032 */ s8 magicLevel;
		/* 0x0033 */ s8 magic;
		/* 0x0034 */ s16 rupees;
		/* 0x0036 */ u16 swordHealth;
		/* 0x0038 */ u16 naviTimer;
		/* 0x003A */ u8 magicAcquired;
		/* 0x003B */ char unk_3B;
		/* 0x003C */ u8 doubleMagic;
		/* 0x003D */ u8 doubleDefense;
		/* 0x003E */ u8 bgsFlag;
		/* 0x003F */ u8 ocarinaGameRoundNum;
		/* 0x0040 */ ItemEquips childEquips;
		/* 0x004A */ ItemEquips adultEquips;
		/* 0x0054 */ u32 unk_54; // this may be incorrect, currently used for alignement
		/* 0x0058 */ char unk_58[0x0E];
		/* 0x0066 */ s16 savedSceneNum;
		/* 0x0068 */ ItemEquips equips;
		/* 0x0074 */ Inventory inventory;
		/* 0x00D4 */ SavedSceneFlags sceneFlags[124];
		/* 0x0E64 */ FaroresWindData fw;
		/* 0x0E8C */ char unk_E8C[0x10];
		/* 0x0E9C */ s32 gsFlags[6];
		/* 0x0EB4 */ char unk_EB4[0x4];
		/* 0x0EB8 */ s32 highScores[7];
		/* 0x0ED4 */ u16 eventChkInf[14]; // "event_chk_inf"
		/* 0x0EF0 */ u16 itemGetInf[4];	  // "item_get_inf"
		/* 0x0EF8 */ u16 infTable[30];	  // "inf_table"
		/* 0x0F34 */ char unk_F34[0x04];
		/* 0x0F38 */ u32 worldMapAreaData; // "area_arrival"
		/* 0x0F3C */ char unk_F3C[0x4];
		/* 0x0F40 */ u8 scarecrowCustomSongSet;
		/* 0x0F41 */ u8 scarecrowCustomSong[0x360];
		/* 0x12A1 */ char unk_12A1[0x24];
		/* 0x12C5 */ u8 scarecrowSpawnSongSet;
		/* 0x12C6 */ u8 scarecrowSpawnSong[0x80];
		/* 0x1346 */ char unk_1346[0x02];
		/* 0x1348 */ HorseData horseData;
		/* 0x1352 */ u16 checksum; // "check_sum"
		/* 0x1354 */ s32 fileNum;  // "file_no"
		/* 0x1358 */ char unk_1358[0x0004];
		/* 0x135C */ s32 gameMode;
		/* 0x1360 */ s32 sceneSetupIndex;
		/* 0x1364 */ s32 respawnFlag;	     // "restart_flag"
		/* 0x1368 */ RespawnData respawn[3]; // "restart_data"
		/* 0x13BC */ f32 entranceSpeed;
		/* 0x13C0 */ u16 entranceSound;
		/* 0x13C2 */ char unk_13C2[0x0001];
		/* 0x13C3 */ u8 unk_13C3;
		/* 0x13C4 */ s16 dogParams;
		/* 0x13C6 */ u8 textTriggerFlags;
		/* 0x13C7 */ u8 showTitleCard;
		/* 0x13C8 */ s16 nayrusLoveTimer;
		/* 0x13CA */ char unk_13CA[0x0002];
		/* 0x13CC */ s16 rupeeAccumulator;
		/* 0x13CE */ s16 timer1State;
		/* 0x13D0 */ TimerS16 timer1Value;
		/* 0x13D2 */ s16 timer2State;
		/* 0x13D4 */ TimerS16 timer2Value;
		/* 0x13D6 */ TimerS16 timerX[2];
		/* 0x13DA */ TimerS16 timerY[2];
		/* 0x13DE */ char unk_13DE[0x0002];
		/* 0x13E0 */ u8 seqId;
		/* 0x13E1 */ u8 natureAmbienceId;
		/* 0x13E2 */ u8 buttonStatus[5];
		/* 0x13E7 */ u8 startDemo;    // alpha related
		/* 0x13E8 */ u16 unk_13E8;    // alpha type?
		/* 0x13EA */ u16 unk_13EA;    // also alpha type?
		/* 0x13EC */ u16 unk_13EC;    // alpha type counter?
		/* 0x13EE */ u16 unk_13EE;    // previous alpha type?
		/* 0x13F0 */ s16 unk_13F0;    // magic related
		/* 0x13F2 */ s16 unk_13F2;    // magic related
		/* 0x13F4 */ s16 unk_13F4;    // magic related
		/* 0x13F6 */ s16 magicMax;    // magic related
		/* 0x13F8 */ s16 unk_13F8;    // magic related
		/* 0x13FA */ u16 eventInf[4]; // "event_inf"
		/* 0x1402 */ u16 mapIndex;    // intended for maps/minimaps but commonly used as the dungeon index
		/* 0x1404 */ u16 minigameState;
		/* 0x1406 */ u16 minigameScore; // "yabusame_total"
		/* 0x1408 */ char unk_1408[0x0001];
		/* 0x1409 */ u8 language;     // NTSC 0: Japanese; 1: English | PAL 0: English; 1: German; 2: French
		/* 0x1409 */ u8 saveLanguage; // NTSC 0: Japanese; 1: English | PAL 0: English; 1: German; 2: French
		/* 0x140A */ u8 audioSetting;
		/* 0x140B */ char unk_140B[0x0001];
		/* 0x140C */ u8 zTargetSetting; // 0: Switch; 1: Hold
		/* 0x140E */ u16 forcedSeqId;	// immediately start playing the sequence if set
		/* 0x1410 */ u8 unk_1410;	// transition related
		/* 0x1411 */ char unk_1411[0x0001];
		/* 0x1412 */ u16 nextCutsceneIndex;
		/* 0x1414 */ u8 cutsceneTrigger;
		/* 0x1415 */ u8 chamberCutsceneNum;
		/* 0x1416 */ u16 nextDayTime; // "next_zelda_time"
		/* 0x1418 */ u8 fadeDuration;
		/* 0x1419 */ u8 wipeSpeed; // transition related
		/* 0x141A */ TimerU16 skyboxTime;
		/* 0x141C */ u8 dogIsLost;
		/* 0x141D */ u8 nextTransition;
		/* 0x141E */ char unk_141E[0x0002];
		/* 0x1420 */ s16 worldMapArea;
		/* 0x1422 */ s16 sunsSongState; // controls the effects of suns song
		/* 0x1424 */ s16 healthAccumulator;

		File file;

		protected:
		Slot slot();
		Slot& currentSlot();
		Slot& currentBackupSlot();
		void load(const u8 slotId);
		void load(const Slot& save);
		void setFileChooseData(gamestate::FileChoose* fileChooseCtx, const u8 slotId = 0);
	};
} // namespace oot::save

enum RespawnMode
{
	/* 0x00 */ RESPAWN_MODE_DOWN,	/* Normal Void Outs */
	/* 0x01 */ RESPAWN_MODE_RETURN, /* Grotto Returnpoints */
	/* 0x02 */ RESPAWN_MODE_TOP	/* Farore's Wind */
};

enum ButtonStatus
{
	/* 0x00 */ BTN_ENABLED,
	/* 0xFF */ BTN_DISABLED = 0xFF
};

enum ChamberCutsceneNum
{
	/* 0x00 */ CHAMBER_CS_FOREST,
	/* 0x01 */ CHAMBER_CS_FIRE,
	/* 0x02 */ CHAMBER_CS_WATER,
	/* 0x03 */ CHAMBER_CS_SPIRIT,
	/* 0x04 */ CHAMBER_CS_SHADOW,
	/* 0x05 */ CHAMBER_CS_LIGHT
};

enum HighScores
{
	/* 0x00 */ HS_HBA, // horseback archery
	/* 0x01 */ HS_POE_POINTS,
	/* 0x02 */ HS_FISHING,
	/* 0x03 */ HS_HORSE_RACE,
	/* 0x04 */ HS_MARATHON,
	/* 0x05 */ HS_UNK_05,
	/* 0x06 */ HS_DAMPE_RACE
};

enum SunsSongState
{
	/* 0 */ SUNSSONG_INACTIVE,
	/* 1 */ SUNSSONG_START,	     // the suns ocarina effect signals that the song has finished playing
	/* 2 */ SUNSSONG_SPEED_TIME, // suns was played where time passes, speed up the advancement of time
	/* 3 */ SUNSSONG_SPECIAL     // time does not advance, but signals the song was played. used for freezing redeads
};

#define LINK_IS_ADULT (gSaveContext.linkAge == 0)
#define LINK_IS_CHILD (gSaveContext.linkAge == 1)

#define LINK_AGE_ADULT 0
#define LINK_AGE_CHILD 1

#define YEARS_CHILD 5
#define YEARS_ADULT 17
#define LINK_AGE_IN_YEARS (!LINK_IS_ADULT ? YEARS_CHILD : YEARS_ADULT)

#define IS_DAY (gSaveContext.nightFlag == 0)
#define IS_NIGHT (gSaveContext.nightFlag == 1)

#define SLOT(item) gItemSlots[item]
#define INV_CONTENT(item) gSaveContext.inventory.items[SLOT(item)]
#define AMMO(item) gSaveContext.inventory.ammo[SLOT(item)]
#define BEANS_BOUGHT AMMO(ITEM_BEAN + 1)

#define ALL_EQUIP_VALUE(equip) ((s32)(gSaveContext.inventory.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CUR_EQUIP_VALUE(equip) ((s32)(gSaveContext.equips.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CHECK_OWNED_EQUIP(equip, value) ((gBitFlags[value] << gEquipShifts[equip]) & gSaveContext.inventory.equipment)

#define CUR_UPG_VALUE(upg) ((s32)(gSaveContext.inventory.upgrades & gUpgradeMasks[upg]) >> gUpgradeShifts[upg])
#define CAPACITY(upg, value) gUpgradeCapacities[upg][value]
#define CUR_CAPACITY(upg) CAPACITY(upg, CUR_UPG_VALUE(upg))

#define CHECK_QUEST_ITEM(item) (gBitFlags[item] & gSaveContext.inventory.questItems)
#define CHECK_DUNGEON_ITEM(item, dungeonIndex) (gSaveContext.inventory.dungeonItems[dungeonIndex] & gBitFlags[item])

#define GET_GS_FLAGS(index) ((gSaveContext.gsFlags[(index) >> 2] & gGsFlagsMasks[(index)&3]) >> gGsFlagsShifts[(index)&3])
#define SET_GS_FLAGS(index, value) (gSaveContext.gsFlags[(index) >> 2] |= (value) << gGsFlagsShifts[(index)&3])

#define HIGH_SCORE(score) (gSaveContext.highScores[score])

#define B_BTN_ITEM ((gSaveContext.buttonStatus[0] == ITEM_NONE) ? ITEM_NONE : (gSaveContext.equips.buttonItems[0] == ITEM_SWORD_KNIFE) ? ITEM_SWORD_BGS : gSaveContext.equips.buttonItems[0])

#define C_BTN_ITEM(button) ((gSaveContext.buttonStatus[(button) + 1] != BTN_DISABLED) ? gSaveContext.equips.buttonItems[(button) + 1] : ITEM_NONE)

extern oot::save::Context gSaveContext;
extern u32 gBitFlags[32];
extern u32 gGsFlagsShifts[4];
extern u32 gGsFlagsMasks[4];

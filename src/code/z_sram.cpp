#define INTERNAL_SRC_CODE_Z_SRAM_C
#include "global.h"
#include "z64global.h"
#include "port/options.h"
#include "sequence.h"
#include "vt.h"
#include "z64audio.h"
#include "z64game.h"
#include "z64item.h"
#include "z64save.h"
#include "z64scene.h"
#include "z64sram.h"
#include "def/audio.h"
#include "def/code_80069420.h"
#include "def/game.h"
#include "def/inventory.h"
#include "def/z_file_choose.h"
#include "def/z_parameter.h"

oot::save::Context gSaveContext;

namespace oot::save
{
#define SAVE_PLAYER_DATA (*((SavePlayerData*)&gSaveFile.newf))
#define SAVE_INFO (*((SaveInfo*)&gSaveFile.newf))

#define SLOT_SIZE (sizeof(SaveSlot) + 0x28)
#define CHECKSUM_SIZE (sizeof(Save) / 2)

	static char sZeldaMagic[] = {'\0', '\0', '\0', '\x98', '\x09', '\x10', '\x21', 'Z', 'E', 'L', 'D', 'A'};
	static char sZeldaMagicSwapped[] = {'\x98', '\0', '\0', '\0', 'Z', '\x21', '\x10', '\x09', 'A', 'D', 'L', 'E'};
	static_assert(sizeof(sZeldaMagic) == 12, "sZeldaMagic incorrect size");

	bool File::isValidMagic() const
	{
		return memcmp(sZeldaMagic + 3, header.magic, sizeof(sZeldaMagic) - 3) == 0;
	}

	bool File::isValidMagicSwapped() const
	{
		return memcmp(sZeldaMagicSwapped + 3, header.magic, sizeof(sZeldaMagicSwapped) - 3) == 0;
	}

	static PlayerData sNewSavePlayerData = {
	    {'\0', '\0', '\0', '\0', '\0', '\0'},	      // newf
	    0,						      // deaths
	    {0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E}, // playerName
	    0,						      // n64ddFlag
	    0x30,					      // healthCapacity
	    0x30,					      // defense
	    0,						      // magicLevel
	    0x30,					      // magic
	    0,						      // rupees
	    0,						      // swordHealth
	    0,						      // naviTimer
	    0,						      // magicAcquired
	    0,						      // unk_1F
	    0,						      // doubleMagic
	    0,						      // doubleDefense
	    0,						      // bgsFlag
	    0,						      // ocarinaGameRoundNum
	    {
		{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE}, // buttonItems
		{SLOT_NONE, SLOT_NONE, SLOT_NONE},	      // cButtonSlots
		0,					      // equipment
	    },						      // childEquips
	    {
		{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE}, // buttonItems
		{SLOT_NONE, SLOT_NONE, SLOT_NONE},	      // cButtonSlots
		0,					      // equipment
	    },						      // adultEquips
	    0,						      // unk_38
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	      // unk_3C
	    0x34,					      // savedSceneNum
	};

	static ItemEquips sNewSaveEquips = {
	    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE}, // buttonItems
	    {SLOT_NONE, SLOT_NONE, SLOT_NONE},		  // cButtonSlots
	    0x1100,					  // equipment
	};

	static Inventory sNewSaveInventory = {
	    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, // items
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},												      // ammo
	    0x1100,																	      // equipment
	    0,																		      // upgrades
	    0,																		      // questItems
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},										      // dungeonItems
	    {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	    }, // dungeonKeys
	    0, // defenseHearts
	    0, // gsTokens
	};

	static u16 sNewSaveChecksum = 0;

	Context::Context()
	{
		memset(this, 0, sizeof(*this));
		this->fileNum = 0xFF;
		file.load();
	}

	/**
	 *  Initialize new save.
	 *  This save has an empty inventory with 3 hearts and single magic.
	 */
	void Context::create()
	{
		memset(this->newf, 0, sizeof(Info));
		this->totalDays = 0;
		this->bgsDayCount = 0;

		auto playerData = (PlayerData*)this->newf;
		*playerData = sNewSavePlayerData;
		this->equips = sNewSaveEquips;
		this->inventory = sNewSaveInventory;

		this->checksum = slot().save.checksum();
		this->horseData.scene = SCENE_SPOT00;
		this->horseData.pos.x = -1840;
		this->horseData.pos.y = 72;
		this->horseData.pos.z = 5497;
		this->horseData.angle = -0x6AD9;
		this->magicLevel = 0;
		this->infTable[29] = 1;
		this->sceneFlags[5].swch = 0x40000000;
	}

	static PlayerData sDebugSavePlayerData = {
	    {'Z', 'E', 'L', 'D', 'A', 'Z'},		      // newf
	    0,						      // deaths
	    {0x15, 0x12, 0x17, 0x14, 0x3E, 0x3E, 0x3E, 0x3E}, // playerName ( "LINK" )
	    0,						      // n64ddFlag
	    0xE0,					      // healthCapacity
	    0xE0,					      // health
	    0,						      // magicLevel
	    0x30,					      // magic
	    150,					      // rupees
	    8,						      // swordHealth
	    0,						      // naviTimer
	    1,						      // magicAcquired
	    0,						      // unk_1F
	    0,						      // doubleMagic
	    0,						      // doubleDefense
	    0,						      // bgsFlag
	    0,						      // ocarinaGameRoundNum
	    {
		{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE}, // buttonItems
		{SLOT_NONE, SLOT_NONE, SLOT_NONE},	      // cButtonSlots
		0,					      // equipment
	    },						      // childEquips
	    {
		{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE}, // buttonItems
		{SLOT_NONE, SLOT_NONE, SLOT_NONE},	      // cButtonSlots
		0,					      // equipment
	    },						      // adultEquips
	    0,						      // unk_38
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	      // unk_3C
	    0x51,					      // savedSceneNum
	};

	void PlayerData::setMagic()
	{
		newf[0] = 'Z';
		newf[1] = 'E';
		newf[2] = 'L';
		newf[3] = 'D';
		newf[4] = 'A';
		newf[5] = 'Z';
	}

	bool PlayerData::isMagicValid() const
	{
		return newf[0] == 'Z' && newf[1] == 'E' && newf[2] == 'L' && newf[3] == 'D' && newf[4] == 'A' && newf[5] == 'Z';
	}

	static ItemEquips sDebugSaveEquips = {
	    {ITEM_SWORD_MASTER, ITEM_BOW, ITEM_BOMB, ITEM_OCARINA_FAIRY}, // buttonItems
	    {SLOT_BOW, SLOT_BOMB, SLOT_OCARINA},			  // cButtonSlots
	    0x1122,							  // equipment
	};

	static Inventory sDebugSaveInventory = {
	    {
		ITEM_STICK,	ITEM_NUT,  ITEM_BOMB, ITEM_BOW,	   ITEM_ARROW_FIRE,  ITEM_DINS_FIRE,   ITEM_SLINGSHOT, ITEM_OCARINA_FAIRY, ITEM_BOMBCHU,      ITEM_HOOKSHOT,	ITEM_ARROW_ICE,	 ITEM_FARORES_WIND,
		ITEM_BOOMERANG, ITEM_LENS, ITEM_BEAN, ITEM_HAMMER, ITEM_ARROW_LIGHT, ITEM_NAYRUS_LOVE, ITEM_BOTTLE,    ITEM_POTION_RED,	   ITEM_POTION_GREEN, ITEM_POTION_BLUE, ITEM_POCKET_EGG, ITEM_WEIRD_EGG,
	    },								  // items
	    {50, 50, 10, 30, 1, 1, 30, 1, 50, 1, 1, 1, 1, 1, 1, 1},	  // ammo
	    0x7777,							  // equipment
	    0x125249,							  // upgrades
	    0x1E3FFFF,							  // questItems
	    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // dungeonItems
	    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},	  // dungeonKeys
	    0,								  // defenseHearts
	    0,								  // gsTokens
	};

	static u16 sDebugSaveChecksum = 0;

	/**
	 *  Initialize debug save. This is also used on the Title Screen
	 *  This save has a mostly full inventory with 10 hearts and single magic.
	 *
	 *  Some noteable flags that are set:
	 *  Showed Mido sword/shield, met Deku Tree, Deku Tree mouth opened,
	 *  used blue warp in Gohmas room, Zelda fled castle, light arrow cutscene watched,
	 *  and set water level in Water Temple to lowest level.
	 */
	void Context::createDebug()
	{
		memset(this->newf, 0, sizeof(Info));
		this->totalDays = 0;
		this->bgsDayCount = 0;

		auto playerData = (PlayerData*)this->newf;
		*playerData = sDebugSavePlayerData;
		this->equips = sDebugSaveEquips;
		this->inventory = sDebugSaveInventory;

		this->checksum = slot().save.checksum();
		this->horseData.scene = SCENE_SPOT00;
		this->horseData.pos.x = -1840;
		this->horseData.pos.y = 72;
		this->horseData.pos.z = 5497;
		this->horseData.angle = -0x6AD9;
		this->infTable[0] |= 0x5009;
		this->eventChkInf[0] |= 0x123F;
		this->eventChkInf[8] |= 1;
		this->eventChkInf[12] |= 0x10;

		if(this->linkAge == LINK_AGE_CHILD)
		{
			this->equips.buttonItems[0] = ITEM_SWORD_KOKIRI;
			Inventory_ChangeEquipment(EQUIP_SWORD, 1);
			if(this->fileNumber() == 0xFF)
			{
				this->equips.buttonItems[1] = ITEM_SLINGSHOT;
				this->equips.cButtonSlots[0] = SLOT_SLINGSHOT;
				Inventory_ChangeEquipment(EQUIP_SHIELD, 1);
			}
		}

		Inventory_ChangeUpgrade(UPG_STRENGTH, 3);

		this->entranceIndex = 0xCD;
		this->magicLevel = 0;
		this->sceneFlags[5].swch = 0x40000000;
	}

	/**
	 *  Copy save currently on the buffer to Save Context and complete various tasks to open the save.
	 *  This includes:
	 *  - Set proper entrance depending on where the game was saved
	 *  - If health is less than 3 hearts, give 3 hearts
	 *  - If either scarecrow song is set, copy them from save context to the proper location
	 *  - Handle a case where the player saved and quit after zelda cutscene but didnt get the song
	 *  - Give and equip master sword if player is adult and doesnt have kokiri sword (bug?)
	 *  - Revert any trade items that spoil
	 */
	void Context::open(const u8 index)
	{
		static s16 dungeonEntrances[] = {
		    0x0000, 0x0004, 0x0028, 0x0169, 0x0165, 0x0010, 0x0082, 0x0037, 0x0098, 0x0088, 0x041B, 0x0008, 0x0486, 0x0467, 0x0179, 0x056C,
		};
		this->fileNumber() = index;
		this->load(index);

		switch(savedSceneNum)
		{
			case SCENE_YDAN:
			case SCENE_DDAN:
			case SCENE_BDAN:
			case SCENE_BMORI1:
			case SCENE_HIDAN:
			case SCENE_MIZUSIN:
			case SCENE_JYASINZOU:
			case SCENE_HAKADAN:
			case SCENE_HAKADANCH:
			case SCENE_ICE_DOUKUTO:
			case SCENE_GANON:
			case SCENE_MEN:
			case SCENE_GERUDOWAY:
			case SCENE_GANONTIKA:
				entranceIndex = dungeonEntrances[savedSceneNum];
				break;
			case SCENE_YDAN_BOSS:
				entranceIndex = 0;
				break;
			case SCENE_DDAN_BOSS:
				entranceIndex = 4;
				break;
			case SCENE_BDAN_BOSS:
				entranceIndex = 0x28;
				break;
			case SCENE_MORIBOSSROOM:
				entranceIndex = 0x169;
				break;
			case SCENE_FIRE_BS:
				entranceIndex = 0x165;
				break;
			case SCENE_MIZUSIN_BS:
				entranceIndex = 0x10;
				break;
			case SCENE_JYASINBOSS:
				entranceIndex = 0x82;
				break;
			case SCENE_HAKADAN_BS:
				entranceIndex = 0x37;
				break;
			case SCENE_GANON_SONOGO:
			case SCENE_GANONTIKA_SONOGO:
			case SCENE_GANON_BOSS:
			case SCENE_GANON_FINAL:
			case SCENE_GANON_DEMO:
				entranceIndex = 0x41B;
				break;

			default:
				if(savedSceneNum != SCENE_LINK_HOME)
				{
					entranceIndex = (LINK_AGE_IN_YEARS == YEARS_CHILD) ? 0xBB : 0x5F4;
				}
				else
				{
					entranceIndex = 0xBB;
				}
				break;
		}

		if(health < 0x30)
		{
			health = 0x30;
		}

		if(scarecrowCustomSongSet)
		{
			memcpy(gScarecrowCustomSongPtr, scarecrowCustomSong, sizeof(scarecrowCustomSong));
		}

		if(scarecrowSpawnSongSet)
		{
			memcpy(gScarecrowSpawnSongPtr, scarecrowSpawnSong, sizeof(scarecrowSpawnSong));
		}

		// if zelda cutscene has been watched but lullaby was not obtained, restore cutscene and take away letter
		if((eventChkInf[4] & 1) && !CHECK_QUEST_ITEM(QUEST_SONG_LULLABY))
		{
			eventChkInf[4] &= ~1;

			inventory.items[SLOT(ITEM_LETTER_ZELDA)] = ITEM_CHICKEN;

			for(u8 j = 1; j < 4; j++)
			{
				if(equips.buttonItems[j] == ITEM_LETTER_ZELDA)
				{
					equips.buttonItems[j] = ITEM_CHICKEN;
				}
			}
		}

		// check for owning kokiri sword.. to restore master sword? bug or debug feature?
		if(LINK_AGE_IN_YEARS == YEARS_ADULT && !CHECK_OWNED_EQUIP(EQUIP_SWORD, 1))
		{
			inventory.equipment |= gBitFlags[1] << gEquipShifts[EQUIP_SWORD];
			equips.buttonItems[0] = ITEM_SWORD_MASTER;
			equips.equipment &= ~0xF;
			equips.equipment |= 2;
		}

		for(int i = 0; i < ARRAY_COUNT(gSpoilingItems); i++)
		{
			if(INV_CONTENT(ITEM_TRADE_ADULT) == gSpoilingItems[i])
			{
				INV_CONTENT(gSpoilingItemReverts[i]) = gSpoilingItemReverts[i];

				for(u8 j = 1; j < 4; j++)
				{
					if(equips.buttonItems[j] == gSpoilingItems[i])
					{
						equips.buttonItems[j] = gSpoilingItemReverts[i];
					}
				}
			}
		}

		magicLevel = 0;
	}

	u16 Save::checksum()
	{
		auto ptr = (u16*)this;
		u16 currentChecksum = info.checksum;
		u16 val = 0;

		info.checksum = 0;

		for(u16 offset = 0; offset < sizeof(*this) / sizeof(u16); offset++)
		{
			val += *ptr++;
		}

		info.checksum = currentChecksum;
		return val;
	}

	/**
	 *  Write the contents of the Save Context to a main and backup slot in SRAM.
	 *  Note: The whole Save Context is written even though only the `save` substruct is read back later
	 */
	void Context::save()
	{
		currentSlot() = currentBackupSlot() = slot();
		file.save();
	}

	/**
	 *  For all 3 slots, verify that the checksum is correct. If corrupted, attempt to load a backup save.
	 *  If backup is also corrupted, default to a new save (or debug save for slot 0 on debug rom).
	 *
	 *  After verifying all 3 saves, pass relevant data to File Select to be displayed.
	 */
	void Context::loadAllSaves(gamestate::FileChoose* fileChooseCtx)
	{
		for(u8 slotNum = 0; slotNum < MAX_SLOTS; slotNum++)
		{
			load(file.slots[slotNum]);

			if(checksum != slot().save.checksum())
			{
				// checksum didnt match, try backup save
				osSyncPrintf("ERROR!!! ＝ (%d)\n", slotNum);

				load(slotNum + MAX_SLOTS);

				if(checksum != slot().save.checksum())
				{
					// backup save didnt work, make new save
					entranceIndex = 0;
					linkAge = 0;
					cutsceneIndex = 0;

					// note that gSaveFile.dayTime is not actually the sizeof(s32)
					dayTime = 0;
					nightFlag = 0;
					totalDays = 0;
					bgsDayCount = 0;

					if(!slotNum && oot::config().game().enablDebugLevelSelect())
					{
						createDebug();
						newf[0] = 'Z';
						newf[1] = 'E';
						newf[2] = 'L';
						newf[3] = 'D';
						newf[4] = 'A';
						newf[5] = 'Z';
					}
					else
					{
						create();
					}

					checksum = slot().save.checksum();

					file.slots[slotNum] = file.slots[slotNum + MAX_SLOTS] = slot();
					file.save();
				}

				file.save();
			}
			else
			{
				osSyncPrintf("\nSAVE data OK!!!!\n"); // "SAVE data OK! ! ! !"
			}
		}

		for(u8 i = 0; i < 3; i++)
		{
			setFileChooseData(fileChooseCtx, i);
		}
	}

	void Context::setFileChooseData(gamestate::FileChoose* fileChooseCtx, const u8 slotId)
	{
		// const u8 slotId = fileChooseCtx->buttonIndex;
		auto& slot = file.slots[slotId];
		fileChooseCtx->deaths[slotId] = slot.save.info.playerData.deaths;
		fileChooseCtx->healthCapacities[slotId] = slot.save.info.playerData.healthCapacity;
		fileChooseCtx->questItems[slotId] = slot.save.info.inventory.questItems;
		fileChooseCtx->n64ddFlags[slotId] = slot.save.info.playerData.n64ddFlag;
		fileChooseCtx->defense[slotId] = slot.save.info.inventory.defenseHearts;
		fileChooseCtx->health[slotId] = slot.save.info.playerData.health;

		MemCopy(&fileChooseCtx->fileNames[slotId], slot.save.info.playerData.playerName, sizeof(fileChooseCtx->fileNames[0]));
	}

	void Context::initialize(gamestate::FileChoose* fileChooseCtx, const u8 slotId)
	{
		if(fileChooseCtx->buttonIndex != 0 || !oot::config().game().enablDebugLevelSelect())
		{
			create();
		}
		else
		{
			createDebug();
		}

		entranceIndex = 0xBB;
		linkAge = 1;
		dayTime = 0x6AAB;
		cutsceneIndex = 0xFFF1;

		if(oot::config().game().enablDebugLevelSelect())
		{
			if(fileChooseCtx->buttonIndex == 0)
			{
				cutsceneIndex = 0; // Skip cutscene
			}
		}

		for(u8 offset = 0; offset < 8; offset++)
		{
			playerName[offset] = fileChooseCtx->fileNames[fileChooseCtx->buttonIndex][offset];
		}

		this->newf[0] = 'Z';
		this->newf[1] = 'E';
		this->newf[2] = 'L';
		this->newf[3] = 'D';
		this->newf[4] = 'A';
		this->newf[5] = 'Z';

		n64ddFlag = fileChooseCtx->n64ddFlag;

		this->save();

		setFileChooseData(fileChooseCtx, slotId);
	}

	void Context::erase(const u8 slotId)
	{
		auto currentSlot = fileNumber();
		fileNumber() = slotId;
		create();
		save();
		fileNumber() = currentSlot;
	}

	void Context::copy(const u8 selectedFileIndex, const u8 copyDestFileIndex)
	{
		s32 offset;

		file.slots[copyDestFileIndex] = file.slots[selectedFileIndex];
		file.slots[copyDestFileIndex + MAX_SLOTS] = file.slots[selectedFileIndex];
		file.save();
	}

	void File::init(GameState* gameState, u32 depth)
	{
		load();

		auto& slot = slots[0];

		if(!isValidMagic() && isValidMagicSwapped())
		{
			u32* p = (u32*)this;

			for(u32 i = 0; i < sizeof(File) / sizeof(u32); i++, p++)
			{
				*p = SWAP32(*p);
			}
		}

		if(!isValidMagic())
		{
			osSyncPrintf("SRAM Destruction!!!!!!\n"); // "SRAM destruction! ! ! ! ! !"
			memcpy(header.magic, sZeldaMagic + 3, sizeof(sZeldaMagic) - 3);
			header.language = slot.language;
			save();
		}

		slot.audioSetting = header.sound & 3;
		slot.zTargetSetting = header.ztarget & 1;

		if(slot.language >= LANGUAGE_MAX)
		{
			header.language = slot.language;
			save();
		}

		Audio_SetSettings(slot.audioSetting);

		// gSaveContext.load(slot);
	}

	static FILE* openf(bool write, bool rw = false)
	{
		const char* mode = rw ? "r+" : (write ? "wb" : "rb");
#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
		mountSaveData();
		FILE* fp = fopen("sv:/oot.sav", mode);

		if(fp == NULL)
		{
			fp = fopen("sdmc:/oot.sav", mode);
		}
		return fp;
#else
		return fopen("oot.sav", mode);
#endif
	}

	static void closef(FILE* fp)
	{
#if defined(__SWITCH__) && !defined(_MSC_VER) && !defined(BUILD_NRO)
		if(fp)
		{
			fclose(fp);
			commitSave();
		}
		unmountSaveData();
#else
		if(fp)
		{
			fclose(fp);
		}
#endif
	}

	void File::save()
	{
		auto f = openf(true);

		if(f)
		{
			fseek(f, 0, SEEK_SET);
			fwrite(this, sizeof(*this), 1, f);
		}

		closef(f);
	}

	void File::saveHeader()
	{
		auto f = openf(true, true);

		if(f)
		{
			fseek(f, 0, SEEK_SET);
			fwrite(&header, sizeof(header), 1, f);
		}

		closef(f);
	}

	void File::load()
	{
		auto f = openf(false);

		if(f)
		{
			fseek(f, 0, SEEK_SET);
			fread(this, sizeof(*this), 1, f);
		}

		closef(f);
	}

	Slot Context::slot()
	{
		Slot s;
		memset(&s, 0, sizeof(s));
		s.save.entranceIndex = this->entranceIndex;
		s.save.linkAge = this->linkAge;
		s.save.cutsceneIndex = this->cutsceneIndex;
		s.save.dayTime = this->dayTime;
		// s.save.dayTimePadding = this->dayTimePadding;
		s.save.nightFlag = this->nightFlag;
		s.save.totalDays = this->totalDays;
		s.save.bgsDayCount = this->bgsDayCount;

		memcpy(s.save.info.playerData.newf, this->newf, sizeof(newf));
		s.save.info.playerData.deaths = this->deaths;
		memcpy(s.save.info.playerData.playerName, this->playerName, sizeof(playerName));
		s.save.info.playerData.n64ddFlag = this->n64ddFlag;
		s.save.info.playerData.healthCapacity = this->healthCapacity;
		s.save.info.playerData.health = this->health;
		s.save.info.playerData.magicLevel = this->magicLevel;
		s.save.info.playerData.magic = this->magic;
		s.save.info.playerData.rupees = this->rupees;
		s.save.info.playerData.swordHealth = this->swordHealth;
		s.save.info.playerData.naviTimer = this->naviTimer;
		s.save.info.playerData.magicAcquired = this->magicAcquired;
		s.save.info.playerData.unk_3B = this->unk_3B;
		s.save.info.playerData.doubleMagic = this->doubleMagic;
		s.save.info.playerData.doubleDefense = this->doubleDefense;
		s.save.info.playerData.bgsFlag = this->bgsFlag;
		s.save.info.playerData.ocarinaGameRoundNum = this->ocarinaGameRoundNum;
		s.save.info.playerData.childEquips = this->childEquips;
		s.save.info.playerData.adultEquips = this->adultEquips;
		s.save.info.playerData.unk_54 = this->unk_54;
		memcpy(s.save.info.playerData.unk_58, this->unk_58, sizeof(unk_58));
		s.save.info.playerData.savedSceneNum = this->savedSceneNum;

		s.save.info.equips = this->equips;
		s.save.info.inventory = this->inventory;
		memcpy(s.save.info.sceneFlags, this->sceneFlags, sizeof(sceneFlags));
		s.save.info.fw = this->fw;
		memcpy(s.save.info.unk_E8C, this->unk_E8C, sizeof(unk_E8C));
		memcpy(s.save.info.gsFlags, this->gsFlags, sizeof(gsFlags));
		memcpy(s.save.info.unk_EB4, this->unk_EB4, sizeof(unk_EB4));
		memcpy(s.save.info.highScores, this->highScores, sizeof(highScores));
		memcpy(s.save.info.eventChkInf, this->eventChkInf, sizeof(eventChkInf));
		memcpy(s.save.info.itemGetInf, this->itemGetInf, sizeof(itemGetInf));
		memcpy(s.save.info.infTable, this->infTable, sizeof(infTable));
		memcpy(s.save.info.unk_F34, this->unk_F34, sizeof(unk_F34));
		s.save.info.worldMapAreaData = this->worldMapAreaData;
		memcpy(s.save.info.unk_F3C, this->unk_F3C, sizeof(unk_F3C));
		s.save.info.scarecrowCustomSongSet = this->scarecrowCustomSongSet;
		memcpy(s.save.info.scarecrowCustomSong, this->scarecrowCustomSong, sizeof(scarecrowCustomSong));
		memcpy(s.save.info.unk_12A1, this->unk_12A1, sizeof(unk_12A1));
		s.save.info.scarecrowSpawnSongSet = this->scarecrowSpawnSongSet;
		memcpy(s.save.info.scarecrowSpawnSong, this->scarecrowSpawnSong, sizeof(scarecrowSpawnSong));
		memcpy(s.save.info.unk_1346, this->unk_1346, sizeof(unk_1346));
		s.save.info.horseData = this->horseData;
		s.save.info.checksum = this->checksum;

		s.fileNum = this->fileNum;
		memcpy(s.unk_1358, this->unk_1358, sizeof(unk_1358));
		s.gameMode = this->gameMode;
		s.sceneSetupIndex = this->sceneSetupIndex;
		s.respawnFlag = this->respawnFlag;
		memcpy(s.respawn, this->respawn, sizeof(respawn));
		s.entranceSpeed = this->entranceSpeed;
		s.entranceSound = this->entranceSound;
		memcpy(s.unk_13C2, this->unk_13C2, sizeof(unk_13C2));
		s.unk_13C3 = this->unk_13C3;
		s.dogParams = this->dogParams;
		s.textTriggerFlags = this->textTriggerFlags;
		s.showTitleCard = this->showTitleCard;
		s.nayrusLoveTimer = this->nayrusLoveTimer;
		memcpy(s.unk_13CA, this->unk_13CA, sizeof(unk_13CA));
		s.rupeeAccumulator = this->rupeeAccumulator;
		s.timer1State = this->timer1State;
		s.timer1Value = this->timer1Value;
		s.timer2State = this->timer2State;
		s.timer2Value = this->timer2Value;
		memcpy(s.timerX, this->timerX, sizeof(timerX));
		memcpy(s.timerY, this->timerY, sizeof(timerY));
		memcpy(s.unk_13DE, this->unk_13DE, sizeof(unk_13DE));
		s.seqId = this->seqId;
		s.natureAmbienceId = this->natureAmbienceId;
		memcpy(s.buttonStatus, this->buttonStatus, sizeof(buttonStatus));
		s.startDemo = this->startDemo;
		s.unk_13E8 = this->unk_13E8;
		s.unk_13EA = this->unk_13EA;
		s.unk_13EC = this->unk_13EC;
		s.unk_13EE = this->unk_13EE;
		s.unk_13F0 = this->unk_13F0;
		s.unk_13F2 = this->unk_13F2;
		s.unk_13F4 = this->unk_13F4;
		s.unk_13F6 = this->magicMax;
		s.unk_13F8 = this->unk_13F8;
		memcpy(eventInf, this->eventInf, sizeof(eventInf));
		s.mapIndex = this->mapIndex;
		s.minigameState = this->minigameState;
		s.minigameScore = this->minigameScore;
		memcpy(s.unk_1408, this->unk_1408, sizeof(unk_1408));
		s.language = this->saveLanguage;
		s.audioSetting = this->audioSetting;
		memcpy(s.unk_140B, this->unk_140B, sizeof(unk_140B));
		s.zTargetSetting = this->zTargetSetting;
		s.forcedSeqId = this->forcedSeqId;
		s.unk_1410 = this->unk_1410;
		memcpy(s.unk_1411, this->unk_1411, sizeof(unk_1411));
		s.nextCutsceneIndex = this->nextCutsceneIndex;
		s.cutsceneTrigger = this->cutsceneTrigger;
		s.chamberCutsceneNum = this->chamberCutsceneNum;
		s.nextDayTime = this->nextDayTime;
		s.fadeDuration = this->fadeDuration;
		s.wipeSpeed = this->wipeSpeed;
		s.skyboxTime = this->skyboxTime;
		s.dogIsLost = this->dogIsLost;
		s.nextTransition = this->nextTransition;
		memcpy(s.unk_141E, this->unk_141E, sizeof(unk_141E));
		s.worldMapArea = this->worldMapArea;
		s.sunsSongState = this->sunsSongState;
		s.healthAccumulator = this->healthAccumulator;

		s.save.info.checksum = s.save.checksum();
		return s;
	}

	Slot& Context::currentSlot()
	{
		return file.slots[fileNumber()];
	}

	Slot& Context::currentBackupSlot()
	{
		return file.slots[fileNumber() + MAX_SLOTS];
	}

	void Context::load(const u8 slotId)
	{
		fileNumber() = slotId;
		load(file.slots[slotId]);
	}

	void Context::load(const Slot& s)
	{
		this->entranceIndex = s.save.entranceIndex;
		this->linkAge = s.save.linkAge;
		this->cutsceneIndex = s.save.cutsceneIndex;
		this->dayTime = s.save.dayTime;
		this->nightFlag = s.save.nightFlag;
		this->totalDays = s.save.totalDays;
		this->bgsDayCount = s.save.bgsDayCount;
		memcpy(this->newf, s.save.info.playerData.newf, sizeof(newf));
		this->deaths = s.save.info.playerData.deaths;
		memcpy(this->playerName, s.save.info.playerData.playerName, sizeof(playerName));
		this->n64ddFlag = s.save.info.playerData.n64ddFlag;
		this->healthCapacity = s.save.info.playerData.healthCapacity;
		this->health = s.save.info.playerData.health;
		this->magicLevel = s.save.info.playerData.magicLevel;
		this->magic = s.save.info.playerData.magic;
		this->rupees = s.save.info.playerData.rupees;
		this->swordHealth = s.save.info.playerData.swordHealth;
		this->naviTimer = s.save.info.playerData.naviTimer;
		this->magicAcquired = s.save.info.playerData.magicAcquired;
		this->unk_3B = s.save.info.playerData.unk_3B;
		this->doubleMagic = s.save.info.playerData.doubleMagic;
		this->doubleDefense = s.save.info.playerData.doubleDefense;
		this->bgsFlag = s.save.info.playerData.bgsFlag;
		this->ocarinaGameRoundNum = s.save.info.playerData.ocarinaGameRoundNum;
		this->childEquips = s.save.info.playerData.childEquips;
		this->adultEquips = s.save.info.playerData.adultEquips;
		this->unk_54 = s.save.info.playerData.unk_54;
		memcpy(this->unk_58, s.save.info.playerData.unk_58, sizeof(unk_58));
		this->savedSceneNum = s.save.info.playerData.savedSceneNum;
		this->equips = s.save.info.equips;
		this->inventory = s.save.info.inventory;
		memcpy(this->sceneFlags, s.save.info.sceneFlags, sizeof(sceneFlags));
		this->fw = s.save.info.fw;
		memcpy(this->unk_E8C, s.save.info.unk_E8C, sizeof(unk_E8C));
		memcpy(this->gsFlags, s.save.info.gsFlags, sizeof(gsFlags));
		memcpy(this->unk_EB4, s.save.info.unk_EB4, sizeof(unk_EB4));
		memcpy(this->highScores, s.save.info.highScores, sizeof(highScores));
		memcpy(this->eventChkInf, s.save.info.eventChkInf, sizeof(eventChkInf));
		memcpy(this->itemGetInf, s.save.info.itemGetInf, sizeof(itemGetInf));
		memcpy(this->infTable, s.save.info.infTable, sizeof(infTable));
		memcpy(this->unk_F34, s.save.info.unk_F34, sizeof(unk_F34));
		this->worldMapAreaData = s.save.info.worldMapAreaData;
		memcpy(this->unk_F3C, s.save.info.unk_F3C, sizeof(unk_F3C));
		this->scarecrowCustomSongSet = s.save.info.scarecrowCustomSongSet;
		memcpy(this->scarecrowCustomSong, s.save.info.scarecrowCustomSong, sizeof(scarecrowCustomSong));
		memcpy(this->unk_12A1, s.save.info.unk_12A1, sizeof(unk_12A1));
		this->scarecrowSpawnSongSet = s.save.info.scarecrowSpawnSongSet;
		memcpy(this->scarecrowSpawnSong, s.save.info.scarecrowSpawnSong, sizeof(scarecrowSpawnSong));
		memcpy(this->unk_1346, s.save.info.unk_1346, sizeof(unk_1346));
		this->horseData = s.save.info.horseData;
		this->checksum = s.save.info.checksum;

		this->fileNum = s.fileNum;
		memcpy(this->unk_1358, s.unk_1358, sizeof(unk_1358));
		this->gameMode = s.gameMode;
		this->sceneSetupIndex = s.sceneSetupIndex;
		this->respawnFlag = s.respawnFlag;
		memcpy(this->respawn, s.respawn, sizeof(respawn));
		this->entranceSpeed = s.entranceSpeed;
		this->entranceSound = s.entranceSound;
		memcpy(this->unk_13C2, s.unk_13C2, sizeof(unk_13C2));
		this->unk_13C3 = s.unk_13C3;
		this->dogParams = s.dogParams;
		this->textTriggerFlags = s.textTriggerFlags;
		this->showTitleCard = s.showTitleCard;
		this->nayrusLoveTimer = s.nayrusLoveTimer;
		memcpy(this->unk_13CA, s.unk_13CA, sizeof(unk_13CA));
		this->rupeeAccumulator = s.rupeeAccumulator;
		this->timer1State = s.timer1State;
		this->timer1Value = s.timer1Value;
		this->timer2State = s.timer2State;
		this->timer2Value = s.timer2Value;
		memcpy(this->timerX, s.timerX, sizeof(timerX));
		memcpy(this->timerY, s.timerY, sizeof(timerY));
		memcpy(this->unk_13DE, s.unk_13DE, sizeof(unk_13DE));
		this->seqId = s.seqId;
		this->natureAmbienceId = s.natureAmbienceId;
		memcpy(this->buttonStatus, s.buttonStatus, sizeof(buttonStatus));
		this->startDemo = s.startDemo;
		this->unk_13E8 = s.unk_13E8;
		this->unk_13EA = s.unk_13EA;
		this->unk_13EC = s.unk_13EC;
		this->unk_13EE = s.unk_13EE;
		this->unk_13F0 = s.unk_13F0;
		this->unk_13F2 = s.unk_13F2;
		this->unk_13F4 = s.unk_13F4;
		this->magicMax = s.unk_13F6;
		this->unk_13F8 = s.unk_13F8;
		memcpy(this->eventInf, eventInf, sizeof(eventInf));
		this->mapIndex = s.mapIndex;
		this->minigameState = s.minigameState;
		this->minigameScore = s.minigameScore;
		memcpy(this->unk_1408, s.unk_1408, sizeof(unk_1408));
		this->saveLanguage = s.language;
		this->audioSetting = s.audioSetting;
		memcpy(this->unk_140B, s.unk_140B, sizeof(unk_140B));
		this->zTargetSetting = s.zTargetSetting;
		this->forcedSeqId = s.forcedSeqId;
		this->unk_1410 = s.unk_1410;
		memcpy(this->unk_1411, s.unk_1411, sizeof(unk_1411));
		this->nextCutsceneIndex = s.nextCutsceneIndex;
		this->cutsceneTrigger = s.cutsceneTrigger;
		this->chamberCutsceneNum = s.chamberCutsceneNum;
		this->nextDayTime = s.nextDayTime;
		this->fadeDuration = s.fadeDuration;
		this->wipeSpeed = s.wipeSpeed;
		this->skyboxTime = s.skyboxTime;
		this->dogIsLost = s.dogIsLost;
		this->nextTransition = s.nextTransition;
		memcpy(this->unk_141E, s.unk_141E, sizeof(unk_141E));
		this->worldMapArea = s.worldMapArea;
		this->sunsSongState = s.sunsSongState;
		this->healthAccumulator = s.healthAccumulator;
	}

	const s32& Context::fileNumber() const
	{
		return fileNum;
	}

	s32& Context::fileNumber()
	{
		return fileNum;
	}

	void Context::init()
	{
		Slot emptySlot;
		memset(&emptySlot, 0, sizeof(emptySlot));
		load(emptySlot);
		seqId = (u8)NA_BGM_DISABLED;
		natureAmbienceId = 0xFF;
		forcedSeqId = NA_BGM_GENERAL_SFX;
		nextCutsceneIndex = 0xFFEF;
		cutsceneTrigger = 0;
		chamberCutsceneNum = 0;
		nextDayTime = 0xFFFF;
		skyboxTime = 0;
		dogIsLost = true;
		nextTransition = 0xFF;
		unk_13EE = 50;
		language = oot::config().game().language();
	}
} // namespace oot::save

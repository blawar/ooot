#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_SELECT_Z_SELECT_C
#include <malloc.h>
#include "actor_common.h"
#include "framerate.h"
#include "gfxprint.h"
#include "z_kankyo.h"
#include "def/z_title.h"
/*
 * File: z_select.c
 * Overlay: ovl_select
 * Description: Debug Scene Select Menu
 */

#include "global.h"
#include "segment_symbols.h"
#include "ultra64.h"
#include "vt.h"
#include "z64alloca.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/game.h"
#include "def/gfxprint.h"
#include "def/random.h"
#include "def/xprintf.h"
#include "def/z_kankyo.h"
#include "def/z_play.h" // FORCE
#include "def/z_rcp.h"
#include "def/z_select.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"

namespace oot::gamestate
{
	// "Translation" (Actual name)
	static SceneSelectEntry sScenes[] = {
	    // "1: SPOT00" (Hyrule Field)
	    {" 1: Hyrule Field", SceneType::GAME, 0x00CD},
	    // "2: SPOT01" (Kakariko Village)
	    {" 2: Kakariko Village", SceneType::GAME, 0x00DB},
	    // "3: SPOT02" (Graveyard)
	    {" 3: Graveyard", SceneType::GAME, 0x00E4},
	    // "4: SPOT03" (Zora's River)
	    {" 4: Zoras River", SceneType::GAME, 0x00EA},
	    // "5: SPOT04" (Kokiri Forest)
	    {" 5: Kokiri Forest", SceneType::GAME, 0x00EE},
	    // "6: SPOT05" (Sacred Forest Meadow)
	    {" 6: Sacred Forest Meadow", SceneType::GAME, 0x00FC},
	    // "7: SPOT06" (Lake Hylia)
	    {" 7: Lake Hylia", SceneType::GAME, 0x0102},
	    // "8: SPOT07" (Zora's Domain)
	    {" 8: Zoras Domain", SceneType::GAME, 0x0108},
	    // "9: SPOT08" (Zora's Fountain)
	    {" 9: Zoras Fountain", SceneType::GAME, 0x010E},
	    // "10: SPOT09" (Gerudo Valley)
	    {"10: Gerudo Valley", SceneType::GAME, 0x0117},
	    // "11: SPOT10" (Lost Woods)
	    {"11: Lost Woods", SceneType::GAME, 0x011E},
	    // "12: SPOT11" (Desert Colossus)
	    {"12: Desert Colossus", SceneType::GAME, 0x0123},
	    // "13: SPOT12" (Gerudo's Fortress)
	    {"13: Gerudos Fortress", SceneType::GAME, 0x0129},
	    // "14: SPOT13" (Haunted Wasteland)
	    {"14: Haunted Wasteland", SceneType::GAME, 0x0130},
	    // "15: SPOT15" (Hyrule Castle)
	    {"15: Hyrule Castle", SceneType::GAME, 0x0138},
	    // "16: SPOT16" (Death Mountain Trail)
	    {"16: Death Mountain Trail", SceneType::GAME, 0x013D},
	    // "17: SPOT17" (Death Mountain Crater)
	    {"17: Death Mountain Crater", SceneType::GAME, 0x0147},
	    // "18: SPOT18" (Goron City)
	    {"18: Goron City", SceneType::GAME, 0x014D},
	    // "19: SPOT20" (Lon Lon Ranch)
	    {"19: Lon Lon Ranch", SceneType::GAME, 0x0157},
	    // "20: Chamber of Time" (Temple Of Time)
	    {"20: Temple Of Time", SceneType::GAME, 0x0053},
	    // "21: Chamber of the Sages" (Chamber of the Sages)
	    {"21: Chamber of the Sages", SceneType::GAME, 0x006B},
	    // "22: Target Range" (Shooting Gallery)
	    {"22: Shooting Gallery", SceneType::GAME, 0x003B},
	    // "23: Hyrule Garden Game" (Hyrule Garden Minigame)
	    {"23: Hyrule Garden Minigame", SceneType::GAME, 0x007A},
	    // "24: Grave Dive Hole" (Grave (Redead))
	    {"24: Graveyard Hole", SceneType::GAME, 0x031C},
	    // "25: Grave Dive Hole 2" (Grave (Fairy's Fountain))
	    {"25: Graveyard Hole 2", SceneType::GAME, 0x004B},
	    // "26: Royal Family's Grave" (Royal Family's Tomb)
	    {"26: Royal Familys Tomb", SceneType::GAME, 0x002D},
	    // "27: Great Fairy's Fountain" (Great Fairy's Fountain (Upgrades))
	    {"27: Great Fairys Fountain - Upgrades", SceneType::GAME, 0x0315},
	    // "28: Fairy Dive Hole" (Fairy's Fountain (Healing Fairies))
	    {"28: Fairy Fountain", SceneType::GAME, 0x036D},
	    // "29: Magic Stone Fairy's Fountain" (Great Fairy's Fountain (Spells))
	    {"29: Great Fairys Fountain - Spells", SceneType::GAME, 0x0371},
	    // "30: Final Battle With Ganon" (Battle With Ganon)
	    {"30: Battle With Ganon", SceneType::GAME, 0x043F},
	    // "31: Hyrule Inner Garden" (Castle Courtyard)
	    {"31: Castle Courtyard", SceneType::GAME, 0x0400},
	    // "32: Fishing" (Fishing Pond)
	    {"32: Fishing Pond", SceneType::GAME, 0x045F},
	    // "33: Bombchu Bowling" (Bombchu Bowling Alley)
	    {"33: Bombchu Bowling Alleyﾞ", SceneType::GAME, 0x0507},
	    // "34: Lon Lon Ranch - Storehouse 1" (Talon's House)
	    {"34: Talons House", SceneType::GAME, 0x004F},
	    // "35: Lon Lon Ranch - Storehouse 2" (Ranch Silo)
	    {"35: Ranch Silo", SceneType::GAME, 0x05D0},
	    // "36: Lookout Hut" (Guard House)
	    {"36: Guard House", SceneType::GAME, 0x007E},
	    // "37: Magic Potion Shop" (Granny's Potion Shop)
	    {"37: Grannys Potion Shop", SceneType::GAME, 0x0072},
	    // "38: Treasure Chest Shop" (Treasure Chest Game)
	    {"38: Treasure Chest Game", SceneType::GAME, 0x0063},
	    // "39: Gold Skulltula House" (House of Skulltula)
	    {"39: House of Skulltula", SceneType::GAME, 0x0550},
	    // "40: Castle Town - Entrance" (Market Entrance)
	    {"40: Market Entrance", SceneType::GAME, 0x0033},
	    // "41: Castle Town" (Market)
	    {"41: Market", SceneType::GAME, 0x00B1},
	    // "42: Back Alley" (Back Alley)
	    {"42: Back Alley", SceneType::GAME, 0x00AD},
	    // "43: In Front of the Temple of Time" (Temple of Time Exterior)
	    {"43: Temple of Time Exterior", SceneType::GAME, 0x0171},
	    // "44: Link's House" (Link's House)
	    {"44: Links House", SceneType::GAME, 0x00BB},
	    // "45: Kakariko Village Row House" (Carpenter Boss's House)
	    {"45: Carpenter Bosss House", SceneType::GAME, 0x02FD},
	    // "46: Back Alley House" (Back Alley House (Man in Green))
	    {"46: Back Alley House", SceneType::GAME, 0x043B},
	    // "47: Kokiri Village - Know-It-All Brothers' House" (Know-It-All Brothers' House)
	    {"47: Know-It-All Brothers House", SceneType::GAME, 0x00C9},
	    // "48: Kokiri Village - Twins' House" (Twins' House)
	    {"48: Twins House", SceneType::GAME, 0x009C},
	    // "49: Kokiri Village - Mido's House" (Mido's House)
	    {"49: Midos House", SceneType::GAME, 0x0433},
	    // "50: Kokiri Village - Saria's House" (Saria's House)
	    {"50: Sarias House", SceneType::GAME, 0x0437},
	    // "51: Stable" (Stable)
	    {"51: Stable", SceneType::GAME, 0x02F9},
	    // "52: Grave Keeper's House" (Gravekeeper's Hut)
	    {"52: Gravekeepers Hut", SceneType::GAME, 0x030D},
	    // "53: Back Alley - Dog Lady's House" (Back Alley House)
	    {"53: Back Alley House", SceneType::GAME, 0x0398},
	    // "54: Kakariko Village - Impa's House" (Impa's House)
	    {"54: Impas House", SceneType::GAME, 0x039C},
	    // "55: Hylia Laboratory" (Lakeside Laboratory)
	    {"55: Lakeside Laboratory", SceneType::GAME, 0x0043},
	    // "56: Tent" (Carpenters' Tent)
	    {"56: Carpenters Tent", SceneType::GAME, 0x03A0},
	    // "57: Shield Shop" (Bazaar)
	    {"57: Bazaar", SceneType::GAME, 0x00B7},
	    // "58: Kokiri Shop" (Kokiri Shop)
	    {"58: Kokiri Shop", SceneType::GAME, 0x00C1},
	    // "59: Goron Shop" (Goron Shop)
	    {"59: Goron Shop", SceneType::GAME, 0x037C},
	    // "60: Zora Shop" (Zora Shop)
	    {"60: Zora Shop", SceneType::GAME, 0x0380},
	    // "61: Kakariko Village - Potion Shop" (Kakariko Potion Shop)
	    {"61: Kakariko Potion Shop", SceneType::GAME, 0x0384},
	    // "62: Castle Town - Potion Shop" (Market Potion Shop)
	    {"62: Market Potion Shop", SceneType::GAME, 0x0388},
	    // "63: Back Alley - Night Shop" (Bombchu Shop)
	    {"63: Bombchu Shop", SceneType::GAME, 0x0390},
	    // "64: Mask Shop" (Happy Mask Shop)
	    {"64: Happy Mask Shop", SceneType::GAME, 0x0530},
	    // "65: Gerudo Training Area" (Gerudo Training Ground)
	    {"65: Gerudo Training Ground", SceneType::GAME, 0x0008},
	    // "66: Fairy Tree Dungeon" (Inside the Deku Tree)
	    {"66: Inside the Deku Tree", SceneType::GAME, 0x0000},
	    // "67: Fairy Tree Dungeon - Boss" (Gohma's Lair)
	    {"67: Gohmas Lair", SceneType::GAME, 0x040F},
	    // "68: Dondogo Dungeon" (Dodongo's Cavern)
	    {"68: Dodongos Cavern", SceneType::GAME, 0x0004},
	    // "69: Dondogo Dungeon - Boss" (King Dodongo's Lair)
	    {"69: King Dodongos Lair", SceneType::GAME, 0x040B},
	    // "70: Giant Fish Dungeon" (Inside Jabu-Jabu's Belly)
	    {"70: Inside Jabu-Jabus Belly", SceneType::GAME, 0x0028},
	    // "71: Giant Fish Dungeon - Boss" (Barinade's Lair)
	    {"71: Barinades Lair", SceneType::GAME, 0x0301},
	    // "72: Forest Temple" (Forest Temple)
	    {"72: Forest Temple", SceneType::GAME, 0x0169},
	    // "73: Forest Temple - Boss" (Phantom Ganon's Lair)
	    {"73: Phantom Ganons Lair", SceneType::GAME, 0x000C},
	    // "74: Dungeon Below the Well" (Bottom of the Well)
	    {"74: Bottom of the Well", SceneType::GAME, 0x0098},
	    // "75: Dungeon Beneath the Graves" (Shadow Temple)
	    {"75: Shadow Temple", SceneType::GAME, 0x0037},
	    // "76: Dungeon Beneath the Graves - Boss" (Bongo Bongo's Lair)
	    {"76: Bongo Bongos Lair", SceneType::GAME, 0x0413},
	    // "77: Fire Temple" (Fire Temple)
	    {"77: Fire Temple", SceneType::GAME, 0x0165},
	    // "78: Fire Temple - Boss" (Volvagia's Lair)
	    {"78: Volvagia's Lair", SceneType::GAME, 0x0305},
	    // "79: Water Temple" (Water Temple)
	    {"79: Water Temple", SceneType::GAME, 0x0010},
	    // "80: Water Temple - Boss" (Morpha's Lair)
	    {"80: Morphas Lair", SceneType::GAME, 0x0417},
	    // "81: Evil Goddess Statue Dungeon" (Spirit Temple)
	    {"81: Spirit Temple", SceneType::GAME, 0x0082},
	    // "82: Evil Goddess Statue Dungeon - Iron Knuckle" (Iron Knuckle's Lair)
	    {"82: Iron Knuckles Lair", SceneType::GAME, 0x008D},
	    // "83: Evil Goddess Statue Dungeon - Boss" (Twinrova's Lair)
	    {"83: Twinrovas Lair", SceneType::GAME, 0x05EC},
	    // "84: Ganon's Tower" (Ganon's Tower)
	    {"84: Ganons Tower", SceneType::GAME, 0x041B},
	    // "85: Ganon's Tower - Boss" (Ganondorf's Lair)
	    {"85: Ganondorfs Lair", SceneType::GAME, 0x041F},
	    // "86: Ice Cavern" (Ice Cavern)
	    {"86: Ice Cavern", SceneType::GAME, 0x0088},
	    // "87: Relay Beneath the Graves" (Dampé's Grave)
	    {"87: Dampes Grave", SceneType::GAME, 0x044F},
	    // "88: Ganon's Basement Dungeon" (Inside Ganon's Castle)
	    {"88: Inside Ganons Castle", SceneType::GAME, 0x0467},
	    // "89: Final Battle With Ganon - Cutscene & Battle" (Ganondorf's Death Scene & Tower Escape Exterior)
	    {"89: Final Battle With Ganon", SceneType::GAME, 0x0517},
	    // "90: Ganon's Tower Aftermath 1" (Escaping Ganon's Tower 1)
	    {"90: Escaping Ganons Tower 1", SceneType::GAME, 0x0179},
	    // "91: Ganon's Tower Aftermath 2" (Escaping Ganon's Tower 2)
	    {"91: Escaping Ganons Tower 2", SceneType::GAME, 0x01B5},
	    // "92: Ganon's Tower Aftermath 3" (Escaping Ganon's Tower 3)
	    {"92: Escaping Ganons Tower 3", SceneType::GAME, 0x03DC},
	    // "93: Ganon's Tower Aftermath 4" (Escaping Ganon's Tower 4)
	    {"93: Escaping Ganons Tower 4", SceneType::GAME, 0x03E4},
	    // "94: Ganon's Basement Aftermath" (Escaping Ganon's Castle)
	    {"94: Escaping Ganons Castle", SceneType::GAME, 0x056C},
	    // "95: Gerudo Passage 1-2" (Thieves' Hideout 1)
	    {"95: Thieves Hideout 1", SceneType::GAME, 0x0486},
	    // "96: Gerudo Passage 3-4 9-10" (Thieves' Hideout 2)
	    {"96: Thieves Hideout 2", SceneType::GAME, 0x048E},
	    // "97: Gerudo Passage 5-6" (Thieves' Hideout 3)
	    {"97: Thieves Hideout 3", SceneType::GAME, 0x0496},
	    // "98: Gerudo Passage 7-8" (Thieves' Hideout 4)
	    {"98: Thieves Hideout 4", SceneType::GAME, 0x049E},
	    // "99: Gerudo Passage 11-12" (Thieves' Hideout 5)
	    {"99: Thieves Hideout 5", SceneType::GAME, 0x04AE},
	    // "100: Gerudo Passage 13" (Thieves' Hideout 6)
	    {"100: Thieves Hideout 6", SceneType::GAME, 0x0570},
	    // "101: Hidden Dive Hole 0" (Grotto 0 - Gossip Stone & Chest)
	    {"101: Grotto 0", SceneType::GAME, 0x003F},
	    // "102: Hidden Dive Hole 1" (Grotto 1 - Skulltula & Gold Skulltula)
	    {"102: Grotto 1", SceneType::GAME, 0x0598},
	    // "103: Hidden Dive Hole 2" (Grotto 2 - Business Scrub & Heart Piece)
	    {"103: Grotto 2", SceneType::GAME, 0x059C},
	    // "104: Hidden Dive Hole 3" (Grotto 3 - Redeads)
	    {"104: Grotto 3", SceneType::GAME, 0x05A0},
	    // "105: Hidden Dive Hole 4" (Grotto 4 - 3 Business Scrubs)
	    {"105: Grotto 4", SceneType::GAME, 0x05A4},
	    // "106: Hidden Dive Hole 5" (Grotto 5 - Gossip Stone, Skulltula, Cow)
	    {"106: Grotto 5", SceneType::GAME, 0x05A8},
	    // "107: Hidden Dive Hole 6" (Grotto 6 - Octorok)
	    {"107: Grotto 6", SceneType::GAME, 0x05AC},
	    // "108: Hidden Dive Hole 7" (Grotto 7 - Business Scrub & Deku Nut Upgrade)
	    {"108: Grotto 7", SceneType::GAME, 0x05B0},
	    // "109: Hidden Dive Hole 8" (Grotto 8 - 2 Wolfos)
	    {"109: Grotto 8", SceneType::GAME, 0x05B4},
	    // "110: Hidden Dive Hole 9" (Grotto 9 - Bombable Walls)
	    {"110: Grotto 9", SceneType::GAME, 0x05B8},
	    // "111: Hidden Dive Hole 10" (Grotto 10 - 2 Business Scrubs)
	    {"111: Grotto 10", SceneType::GAME, 0x05BC},
	    // "112: Hidden Dive Hole 11" (Grotto 11 - Tektite & Heart Piece)
	    {"112: Grotto 11", SceneType::GAME, 0x05C0},
	    // "113: Hidden Dive Hole 12" (Grotto 12 - Deku Stage)
	    {"113: Grotto 12", SceneType::GAME, 0x05C4},
	    // "114: Hidden Dive Hole 13" (Grotto 13 - Rupees & Cow)
	    {"114: Grotto 13", SceneType::GAME, 0x05FC},
	    // "115: Hyrule Cutscenes" (Cutscene Map)
	    {"115: Cutscene Map", SceneType::GAME, 0x00A0},
	    // "116: Special Room (Treasure Chest Warp)" (Ganondorf Test Room)
	    {"116: Ganondorf Test Room", SceneType::GAME, 0x0520},
	    // "117: Sasaki Test" (Sasa Test)
	    {"117: Sasa Test", SceneType::GAME, 0x0018},
	    // "118: Test Map" (Jungle Gym)
	    {"118: Jungle Gym", SceneType::GAME, 0x0094},
	    // "119: Test Room" (Treasure Chest Room)
	    {"119: Treasure Chest Room", SceneType::GAME, 0x0024},
	    // "120: Stalfos Miniboss Room" (Stalfos Miniboss Room)
	    {"120: Stalfos Miniboss Room", SceneType::GAME, 0x001C},
	    // "121: Boss Stalfos Room" (Stalfos Boss Room)
	    {"121: Stalfos Boss Room", SceneType::GAME, 0x0020},
	    // "122: Stal" (Sutaru)
	    {"122: Sutaru", SceneType::GAME, 0x0047},
	    // "123: Test Area" (Shooting Gallery)
	    {"123: Shooting Gallery Test", SceneType::GAME, 0x02EA},
	    // "124: Depth Test" (Depth Test)
	    {"124: Depth Test", SceneType::GAME, 0x00B6},
	    // "125: Hyrule Garden Game 2" (Early Hyrule Garden Game)
	    {"125: Early Hyrule Garden Game", SceneType::GAME, 0x0076},
	    // "title" (Title Screen)
	    {"title", SceneType::TITLE, 0x0000},
	};

	Select::Select(GraphicsContext* gfxCtx) : Base(gfxCtx)
	{
	}

	void Select::init()
	{
		u32 size;
		s32 pad;

		this->topDisplayedScene = 0;
		this->currentScene = 0;
		this->pageDownStops[0] = 0;  // Hyrule Field
		this->pageDownStops[1] = 19; // Temple Of Time
		this->pageDownStops[2] = 37; // Treasure Chest Game
		this->pageDownStops[3] = 51; // Gravekeeper's Hut
		this->pageDownStops[4] = 59; // Zora Shop
		this->pageDownStops[5] = 73; // Bottom of the Well
		this->pageDownStops[6] = 91; // Escaping Ganon's Tower 3
		this->pageDownIndex = 0;
		this->opt = 0;
		View_Init(&this->view, this->gfxCtx);
		this->view.flags = (0x08 | 0x02);
		this->verticalInputAccumulator = 0;
		this->verticalInput = 0;
		this->timerUp = 0;
		this->timerDown = 0;
		this->lockUp = 0;
		this->lockDown = 0;
		this->unk_234 = 0;

		size = POINTER_SUB(_z_select_staticSegmentRomEnd, _z_select_staticSegmentRomStart);

		if((dREG(80) >= 0) && (dREG(80) < ARRAY_COUNT(sScenes)))
		{
			this->currentScene = dREG(80);
			this->topDisplayedScene = dREG(81);
			this->pageDownIndex = dREG(82);
		}
		framerate_set_profile(PROFILE_SELECT);

		gSaveContext.cutsceneIndex = 0x8000;
		gSaveContext.linkAge = 1;
	}

	Select::~Select()
	{
		osSyncPrintf("%c", '\a'); // ASCII BEL character, plays an alert tone
		// "view_cleanup will hang, so it won't be called"
		osSyncPrintf("*** view_cleanup will hang, so it won't be called ***\n");
	}

	void Select::loadTitle(s32 entranceIndex)
	{
		running = false;
		Graph_SetNextGameState(new Title(gfxCtx));
	}

	void Select::loadGame(s32 entranceIndex)
	{
		osSyncPrintf(VT_FGCOL(BLUE));
		osSyncPrintf("\n\n\nFILE_NO=%x\n\n\n", gSaveContext.fileNum);
		osSyncPrintf(VT_RST);
		if(gSaveContext.fileNum == 0xFF)
		{
			gSaveContext.createDebug();
			gSaveContext.magicMax = gSaveContext.magic;
			gSaveContext.magic = 0;
			gSaveContext.unk_13F4 = 0;
			gSaveContext.magicLevel = gSaveContext.magic;
		}
		gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = gSaveContext.buttonStatus[4] = BTN_ENABLED;
		gSaveContext.startDemo = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC = 0;
		Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
		gSaveContext.entranceIndex = entranceIndex;
		gSaveContext.respawnFlag = 0;
		gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = -1;
		gSaveContext.seqId = (u8)NA_BGM_DISABLED;
		gSaveContext.natureAmbienceId = 0xFF;
		gSaveContext.showTitleCard = true;
		gWeatherMode = 0;
		this->running = false;

		Graph_SetNextGameState(new Global(gfxCtx));
	}

	void Select::updateMenu()
	{
		Input* input = &this->input[0];
		s32 pad;
		SceneSelectEntry* selectedScene;

		if(this->verticalInputAccumulator == 0)
		{
			if(CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START))
			{
				const auto& scene = sScenes[this->currentScene];

				switch(scene.type)
				{
					case SceneType::TITLE:
						loadTitle(scene.entranceIndex);
						break;
					case SceneType::GAME:
						loadGame(scene.entranceIndex);
						break;
				}
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_B))
			{
				if(LINK_AGE_IN_YEARS == YEARS_ADULT)
				{
					gSaveContext.linkAge = 1;
				}
				else
				{
					gSaveContext.linkAge = 0;
				}
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_Z))
			{
				if(gSaveContext.cutsceneIndex == 0x8000)
				{
					gSaveContext.cutsceneIndex = 0;
				}
				else if(gSaveContext.cutsceneIndex == 0)
				{
					gSaveContext.cutsceneIndex = 0xFFF0;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF0)
				{
					gSaveContext.cutsceneIndex = 0xFFF1;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF1)
				{
					gSaveContext.cutsceneIndex = 0xFFF2;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF2)
				{
					gSaveContext.cutsceneIndex = 0xFFF3;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF3)
				{
					gSaveContext.cutsceneIndex = 0xFFF4;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF4)
				{
					gSaveContext.cutsceneIndex = 0xFFF5;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF5)
				{
					gSaveContext.cutsceneIndex = 0xFFF6;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF6)
				{
					gSaveContext.cutsceneIndex = 0xFFF7;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF7)
				{
					gSaveContext.cutsceneIndex = 0xFFF8;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF8)
				{
					gSaveContext.cutsceneIndex = 0xFFF9;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF9)
				{
					gSaveContext.cutsceneIndex = 0xFFFA;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFFA)
				{
					gSaveContext.cutsceneIndex = 0x8000;
				}
			}
			else if(CHECK_BTN_ALL(input->press.button, BTN_R))
			{
				if(gSaveContext.cutsceneIndex == 0x8000)
				{
					gSaveContext.cutsceneIndex = 0xFFFA;
				}
				else if(gSaveContext.cutsceneIndex == 0)
				{
					gSaveContext.cutsceneIndex = 0x8000;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF0)
				{
					gSaveContext.cutsceneIndex = 0;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF1)
				{
					gSaveContext.cutsceneIndex = 0xFFF0;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF2)
				{
					gSaveContext.cutsceneIndex = 0xFFF1;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF3)
				{
					gSaveContext.cutsceneIndex = 0xFFF2;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF4)
				{
					gSaveContext.cutsceneIndex = 0xFFF3;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF5)
				{
					gSaveContext.cutsceneIndex = 0xFFF4;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF6)
				{
					gSaveContext.cutsceneIndex = 0xFFF5;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF7)
				{
					gSaveContext.cutsceneIndex = 0xFFF6;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF8)
				{
					gSaveContext.cutsceneIndex = 0xFFF7;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFF9)
				{
					gSaveContext.cutsceneIndex = 0xFFF8;
				}
				else if(gSaveContext.cutsceneIndex == 0xFFFA)
				{
					gSaveContext.cutsceneIndex = 0xFFF9;
				}
			}

			gSaveContext.nightFlag = 0;
			if(gSaveContext.cutsceneIndex == 0)
			{
				gSaveContext.nightFlag = 1;
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_CUP))
			{
				if(this->lockUp == true)
				{
					this->timerUp = 0;
				}
				if(this->timerUp == 0)
				{
					this->timerUp = 20;
					this->lockUp = true;
					Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					this->verticalInput = FRAMERATE_RATE_SCALED;
				}
			}

			if(CHECK_BTN_ALL(input->cur.button, BTN_CUP) && this->timerUp == 0)
			{
				Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				this->verticalInput = FRAMERATE_RATE_SCALE(R_UPDATE_RATE * 3);
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_CDOWN))
			{
				if(this->lockDown == true)
				{
					this->timerDown = 0;
				}
				if(this->timerDown == 0)
				{
					this->timerDown = 20;
					this->lockDown = true;
					Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					this->verticalInput = -FRAMERATE_RATE_SCALED;
				}
			}

			if(CHECK_BTN_ALL(input->cur.button, BTN_CDOWN) && (this->timerDown == 0))
			{
				Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				this->verticalInput = -FRAMERATE_RATE_SCALE(R_UPDATE_RATE * 3);
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_CLEFT) || CHECK_BTN_ALL(input->cur.button, BTN_CLEFT))
			{
				Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				this->verticalInput = FRAMERATE_RATE_SCALED;
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_CRIGHT) || CHECK_BTN_ALL(input->cur.button, BTN_CRIGHT))
			{
				Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
				this->verticalInput = -FRAMERATE_RATE_SCALED;
			}
		}

		if(CHECK_BTN_ALL(input->press.button, BTN_L))
		{
			this->pageDownIndex++;
			this->pageDownIndex = (this->pageDownIndex + ARRAY_COUNT(this->pageDownStops)) % ARRAY_COUNT(this->pageDownStops);
			this->currentScene = this->topDisplayedScene = this->pageDownStops[this->pageDownIndex];
		}

		this->verticalInputAccumulator += this->verticalInput;

		if(this->verticalInputAccumulator < -7)
		{
			this->verticalInput = 0;
			this->verticalInputAccumulator = 0;

			this->currentScene++;
			this->currentScene = (this->currentScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);

			if(this->currentScene == ((this->topDisplayedScene + ARRAY_COUNT(sScenes) + 19) % ARRAY_COUNT(sScenes)))
			{
				this->topDisplayedScene++;
				this->topDisplayedScene = (this->topDisplayedScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);
			}
		}

		if(this->verticalInputAccumulator > 7)
		{
			this->verticalInput = 0;
			this->verticalInputAccumulator = 0;

			if(this->currentScene == this->topDisplayedScene)
			{
				this->topDisplayedScene -= 2;
				this->topDisplayedScene = (this->topDisplayedScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);
			}

			this->currentScene--;
			this->currentScene = (this->currentScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);

			if(this->currentScene == ((this->topDisplayedScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes)))
			{
				this->topDisplayedScene--;
				this->topDisplayedScene = (this->topDisplayedScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);
			}
		}

		this->currentScene = (this->currentScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);
		this->topDisplayedScene = (this->topDisplayedScene + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);

		dREG(80) = this->currentScene;
		dREG(81) = this->topDisplayedScene;
		dREG(82) = this->pageDownIndex;

		if(this->timerUp != 0)
		{
			this->timerUp--;
		}

		if(this->timerUp == 0)
		{
			this->lockUp = false;
		}

		if(this->timerDown != 0)
		{
			this->timerDown--;
		}

		if(this->timerDown == 0)
		{
			this->lockDown = false;
		}
	}

	void Select::printMenu(GfxPrint* printer)
	{
		s32 scene;
		s32 i;
		const char* name;

		GfxPrint_SetColor(printer, 255, 155, 150, 255);
		GfxPrint_SetPos(printer, 12, 2);
		GfxPrint_Printf(printer, "ZELDA MAP SELECT");
		GfxPrint_SetColor(printer, 255, 255, 255, 255);

		for(i = 0; i < 20; i++)
		{
			GfxPrint_SetPos(printer, 9, i + 4);

			scene = (this->topDisplayedScene + i + ARRAY_COUNT(sScenes)) % ARRAY_COUNT(sScenes);
			if(scene == this->currentScene)
			{
				GfxPrint_SetColor(printer, 255, 20, 20, 255);
			}
			else
			{
				GfxPrint_SetColor(printer, 200, 200, 55, 255);
			}

			name = sScenes[scene].name;
			if(name == NULL)
			{
				name = "**Null**";
			}

			GfxPrint_Printf(printer, "%s", name);
		};
	}

	static const char* sLoadingMessages[] = {
	    // "Please wait a minute"
	    "Please wait a minute",
	    // "Hold on a sec"
	    "Hold on a sec",
	    // "Wait a moment"
	    "Wait a moment",
	    // "Loading"
	    "Loading",
	    // "Now working"
	    "Now working",
	    // "Now creating"
	    "Now creating",
	    // "It's not broken"
	    "It's not broken",
	    // "Coffee Break"
	    "Coffee Break",
	    // "Please set B side"
	    "Please set B side",
	    // "Be patient, now"
	    "Be patient, now",
	    // "Please wait just a minute"
	    "Please wait just a minute",
	    // "Don't worry, don't worry. Take a break, take a break."
	    "Don't worry, don't worry. Take a break, take a break.",
	};

	void Select::printLoadingMessage(GfxPrint* printer)
	{
		s32 randomMsg;

		GfxPrint_SetPos(printer, 10, 15);
		GfxPrint_SetColor(printer, 255, 255, 255, 255);
		randomMsg = Rand_ZeroOne() * ARRAY_COUNT(sLoadingMessages);
		GfxPrint_Printf(printer, "%s", sLoadingMessages[randomMsg]);
	}

	static const char* sAgeLabels[] = {
	    "17(Adult)",
	    "5(Young)",
	};

	void Select::printAgeSetting(GfxPrint* printer, s32 age)
	{
		GfxPrint_SetPos(printer, 4, 26);
		GfxPrint_SetColor(printer, 255, 255, 55, 255);
		GfxPrint_Printf(printer, "Age:%s", sAgeLabels[age]);
	}

	void Select::printCutsceneSetting(GfxPrint* printer, u16 csIndex)
	{
		const char* label = NULL;

		GfxPrint_SetPos(printer, 4, 25);
		GfxPrint_SetColor(printer, 255, 255, 55, 255);

		switch(csIndex)
		{
			case 0:
				gSaveContext.dayTime = 0;
				label = "Night";
				break;
			case 0x8000:
				gSaveContext.dayTime = 0x8000;
				label = "Day";
				break;
			case 0xFFF0:
				gSaveContext.dayTime = 0x8000;
				label = "Demo00";
				break;
			case 0xFFF1:
				label = "Demo01";
				break;
			case 0xFFF2:
				label = "Demo02";
				break;
			case 0xFFF3:
				label = "Demo03";
				break;
			case 0xFFF4:
				label = "Demo04";
				break;
			case 0xFFF5:
				label = "Demo05";
				break;
			case 0xFFF6:
				label = "Demo06";
				break;
			case 0xFFF7:
				label = "Demo07";
				break;
			case 0xFFF8:
				label = "Demo08";
				break;
			case 0xFFF9:
				label = "Demo09";
				break;
			case 0xFFFA:
				label = "Demo0A";
				break;
		};

		gSaveContext.skyboxTime = gSaveContext.dayTime;
		GfxPrint_Printf(printer, "Stage:" GFXP_KATAKANA "%s", label);
	}

	void Select::drawMenu()
	{
		GraphicsContext* gfxCtx = this->gfxCtx;
		GfxPrint* printer;

		OPEN_DISPS(gfxCtx, "../z_select.c", 930);

		gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
		Gfx_ClearDisplay(gfxCtx, 0, 0, 0);
		SET_FULLSCREEN_VIEWPORT(&this->view);
		func_800AAA50(&this->view, 0xF);
		func_80094140(gfxCtx);

		printer = (GfxPrint*)alloca(sizeof(GfxPrint));
		GfxPrint_Init(printer);
		GfxPrint_Open(printer, POLY_OPA_DISP);
		printMenu(printer);
		printAgeSetting(printer, ((void)0, gSaveContext.linkAge));
		printCutsceneSetting(printer, ((void)0, gSaveContext.cutsceneIndex));
		POLY_OPA_DISP = GfxPrint_Close(printer);
		GfxPrint_Destroy(printer);

		CLOSE_DISPS(gfxCtx, "../z_select.c", 966);
	}

	void Select::drawLoadingScreen()
	{
		GraphicsContext* gfxCtx = this->gfxCtx;
		GfxPrint* printer;

		OPEN_DISPS(gfxCtx, "../z_select.c", 977);

		gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
		Gfx_ClearDisplay(gfxCtx, 0, 0, 0);
		SET_FULLSCREEN_VIEWPORT(&this->view);
		func_800AAA50(&this->view, 0xF);
		func_80094140(gfxCtx);

		printer = (GfxPrint*)alloca(sizeof(GfxPrint));
		GfxPrint_Init(printer);
		GfxPrint_Open(printer, POLY_OPA_DISP);
		printLoadingMessage(printer);
		POLY_OPA_DISP = GfxPrint_Close(printer);
		GfxPrint_Destroy(printer);

		CLOSE_DISPS(gfxCtx, "../z_select.c", 1006);
	}

	void Select::draw()
	{
		GraphicsContext* gfxCtx = this->gfxCtx;

		OPEN_DISPS(gfxCtx, "../z_select.c", 1013);

		gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
		Gfx_ClearDisplay(gfxCtx, 0, 0, 0);
		SET_FULLSCREEN_VIEWPORT(&this->view);
		func_800AAA50(&this->view, 0xF);

		if(!this->running)
		{
			drawLoadingScreen();
		}
		else
		{
			drawMenu();
		}

		CLOSE_DISPS(gfxCtx, "../z_select.c", 1037);
	}

	Base* Select::next()
	{
		return new Select(gfxCtx);
	}

	void Select::main()
	{
		updateMenu();
		draw();
	}

	namespace factory
	{
		Base* Select(GraphicsContext* gfxCtx)
		{
			return new gamestate::Select(gfxCtx);
		}
	} // namespace factory
} // namespace oot::gamestate

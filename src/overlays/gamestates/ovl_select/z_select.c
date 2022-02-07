#define INTERNAL_SRC_OVERLAYS_GAMESTATES_OVL_SELECT_Z_SELECT_C
#include "actor_common.h"
#include "z_select.h"
#include "z_title.h"
#include "z_kankyo.h"
#include "z_player.h"
#include "gfxprint.h"
/*
 * File: z_select.c
 * Overlay: ovl_select
 * Description: Debug Scene Select Menu
 */

#include "ultra64.h"
#include "global.h"
#include "segment_symbols.h"
#include "vt.h"
#include "alloca.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/code_800FD970.h"
#include "def/game.h"
#include "def/gfxprint.h"
#include "def/xprintf.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_rcp.h"
#include "def/z_select.h"
#include "def/z_sram.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"
#include "def/z_play.h" // FORCE

void Select_LoadTitle(SelectContext* this) {
    this->state.running = false;
    SET_NEXT_GAMESTATE(&this->state, Title_Init, TitleContext);
}

void Select_LoadGame(SelectContext* this, s32 entranceIndex) {
    osSyncPrintf(VT_FGCOL(BLUE));
    osSyncPrintf("\n\n\nFILE_NO=%x\n\n\n", gSaveContext.fileNum);
    osSyncPrintf(VT_RST);
    if (gSaveContext.fileNum == 0xFF) {
        Sram_InitDebugSave();
        gSaveContext.unk_13F6 = gSaveContext.magic;
        gSaveContext.magic = 0;
        gSaveContext.unk_13F4 = 0;
        gSaveContext.magicLevel = gSaveContext.magic;
    }
    gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
        gSaveContext.buttonStatus[3] = gSaveContext.buttonStatus[4] = BTN_ENABLED;
    gSaveContext.unk_13E7 = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC = 0;
    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_STOP);
    gSaveContext.entranceIndex = entranceIndex;
    gSaveContext.respawnFlag = 0;
    gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = -1;
    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
    gSaveContext.natureAmbienceId = 0xFF;
    gSaveContext.showTitleCard = true;
    gWeatherMode = 0;
    this->state.running = false;
    SET_NEXT_GAMESTATE(&this->state, Gameplay_Init, GlobalContext);
}

// "Translation" (Actual name)
static SceneSelectEntry sScenes[] = {
    // "1: SPOT00" (Hyrule Field)
    { " 1:SPOT00", Select_LoadGame, 0x00CD },
    // "2: SPOT01" (Kakariko Village)
    { " 2:SPOT01", Select_LoadGame, 0x00DB },
    // "3: SPOT02" (Graveyard)
    { " 3:SPOT02", Select_LoadGame, 0x00E4 },
    // "4: SPOT03" (Zora's River)
    { " 4:SPOT03", Select_LoadGame, 0x00EA },
    // "5: SPOT04" (Kokiri Forest)
    { " 5:SPOT04", Select_LoadGame, 0x00EE },
    // "6: SPOT05" (Sacred Forest Meadow)
    { " 6:SPOT05", Select_LoadGame, 0x00FC },
    // "7: SPOT06" (Lake Hylia)
    { " 7:SPOT06", Select_LoadGame, 0x0102 },
    // "8: SPOT07" (Zora's Domain)
    { " 8:SPOT07", Select_LoadGame, 0x0108 },
    // "9: SPOT08" (Zora's Fountain)
    { " 9:SPOT08", Select_LoadGame, 0x010E },
    // "10: SPOT09" (Gerudo Valley)
    { "10:SPOT09", Select_LoadGame, 0x0117 },
    // "11: SPOT10" (Lost Woods)
    { "11:SPOT10", Select_LoadGame, 0x011E },
    // "12: SPOT11" (Desert Colossus)
    { "12:SPOT11", Select_LoadGame, 0x0123 },
    // "13: SPOT12" (Gerudo's Fortress)
    { "13:SPOT12", Select_LoadGame, 0x0129 },
    // "14: SPOT13" (Haunted Wasteland)
    { "14:SPOT13", Select_LoadGame, 0x0130 },
    // "15: SPOT15" (Hyrule Castle)
    { "15:SPOT15", Select_LoadGame, 0x0138 },
    // "16: SPOT16" (Death Mountain Trail)
    { "16:SPOT16", Select_LoadGame, 0x013D },
    // "17: SPOT17" (Death Mountain Crater)
    { "17:SPOT17", Select_LoadGame, 0x0147 },
    // "18: SPOT18" (Goron City)
    { "18:SPOT18", Select_LoadGame, 0x014D },
    // "19: SPOT20" (Lon Lon Ranch)
    { "19:SPOT20", Select_LoadGame, 0x0157 },
    // "20: Chamber of Time" (Temple Of Time)
    { "20:" GFXP_HIRAGANA "ﾄｷﾉﾏ", Select_LoadGame, 0x0053 },
    // "21: Chamber of the Sages" (Chamber of the Sages)
    { "21:" GFXP_HIRAGANA "ｹﾝｼﾞｬﾉﾏ", Select_LoadGame, 0x006B },
    // "22: Target Range" (Shooting Gallery)
    { "22:" GFXP_HIRAGANA "ｼｬﾃｷｼﾞｮｳ", Select_LoadGame, 0x003B },
    // "23: Hyrule Garden Game" (Hyrule Garden Minigame)
    { "23:" GFXP_KATAKANA "ﾊｲﾗﾙ" GFXP_HIRAGANA "ﾆﾜ" GFXP_KATAKANA "ｹﾞｰﾑ", Select_LoadGame, 0x007A },
    // "24: Grave Dive Hole" (Grave (Redead))
    { "24:" GFXP_HIRAGANA "ﾊｶｼﾀﾄﾋﾞｺﾐｱﾅ", Select_LoadGame, 0x031C },
    // "25: Grave Dive Hole 2" (Grave (Fairy's Fountain))
    { "25:" GFXP_HIRAGANA "ﾊｶｼﾀﾄﾋﾞｺﾐｱﾅ 2", Select_LoadGame, 0x004B },
    // "26: Royal Family's Grave" (Royal Family's Tomb)
    { "26:" GFXP_HIRAGANA "ｵｳｹ ﾉ ﾊｶｱﾅ", Select_LoadGame, 0x002D },
    // "27: Great Fairy's Fountain" (Great Fairy's Fountain (Upgrades))
    { "27:" GFXP_HIRAGANA "ﾀﾞｲﾖｳｾｲﾉｲｽﾞﾐ", Select_LoadGame, 0x0315 },
    // "28: Fairy Dive Hole" (Fairy's Fountain (Healing Fairies))
    { "28:" GFXP_HIRAGANA "ﾄﾋﾞｺﾐ ﾖｳｾｲ ｱﾅ", Select_LoadGame, 0x036D },
    // "29: Magic Stone Fairy's Fountain" (Great Fairy's Fountain (Spells))
    { "29:" GFXP_HIRAGANA "ﾏﾎｳｾｷ ﾖｳｾｲﾉｲｽﾞﾐ", Select_LoadGame, 0x0371 },
    // "30: Final Battle With Ganon" (Battle With Ganon)
    { "30:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ｻｲｼｭｳｾﾝ", Select_LoadGame, 0x043F },
    // "31: Hyrule Inner Garden" (Castle Courtyard)
    { "31:" GFXP_KATAKANA "ﾊｲﾗﾙ" GFXP_HIRAGANA "ﾅｶﾆﾜ", Select_LoadGame, 0x0400 },
    // "32: Fishing" (Fishing Pond)
    { "32:" GFXP_HIRAGANA "ﾂﾘﾎﾞﾘ", Select_LoadGame, 0x045F },
    // "33: Bombchu Bowling" (Bombchu Bowling Alley)
    { "33:" GFXP_KATAKANA "ﾎﾞﾑﾁｭｳﾎﾞｰﾘﾝｸﾞ", Select_LoadGame, 0x0507 },
    // "34: Lon Lon Ranch - Storehouse 1" (Talon's House)
    { "34:" GFXP_KATAKANA "ﾛﾝﾛﾝ" GFXP_HIRAGANA "ﾎﾞｸｼﾞｮｳ ｿｳｺ 1", Select_LoadGame, 0x004F },
    // "35: Lon Lon Ranch - Storehouse 2" (Ranch Silo)
    { "35:" GFXP_KATAKANA "ﾛﾝﾛﾝ" GFXP_HIRAGANA "ﾎﾞｸｼﾞｮｳ ｿｳｺ 2", Select_LoadGame, 0x05D0 },
    // "36: Lookout Hut" (Guard House)
    { "36:" GFXP_HIRAGANA "ﾐﾊﾘ ｺﾞﾔ", Select_LoadGame, 0x007E },
    // "37: Magic Potion Shop" (Granny's Potion Shop)
    { "37:" GFXP_HIRAGANA "ﾏﾎｳ ﾉ ｸｽﾘﾔ", Select_LoadGame, 0x0072 },
    // "38: Treasure Chest Shop" (Treasure Chest Game)
    { "38:" GFXP_HIRAGANA "ﾀｶﾗﾊﾞｺﾔ", Select_LoadGame, 0x0063 },
    // "39: Gold Skulltula House" (House of Skulltula)
    { "39:" GFXP_HIRAGANA "ｷﾝ " GFXP_KATAKANA "ｽﾀﾙﾁｭﾗ ﾊｳｽ", Select_LoadGame, 0x0550 },
    // "40: Castle Town - Entrance" (Market Entrance)
    { "40:" GFXP_HIRAGANA "ｼﾞｮｳｶﾏﾁ ｲﾘｸﾞﾁ", Select_LoadGame, 0x0033 },
    // "41: Castle Town" (Market)
    { "41:" GFXP_HIRAGANA "ｼﾞｮｳｶﾏﾁ", Select_LoadGame, 0x00B1 },
    // "42: Back Alley" (Back Alley)
    { "42:" GFXP_HIRAGANA "ｳﾗﾛｼﾞ", Select_LoadGame, 0x00AD },
    // "43: In Front of the Temple of Time" (Temple of Time Exterior)
    { "43:" GFXP_HIRAGANA "ﾄｷﾉｼﾝﾃﾞﾝ ﾏｴ", Select_LoadGame, 0x0171 },
    // "44: Link's House" (Link's House)
    { "44:" GFXP_HIRAGANA "ﾘﾝｸﾉｲｴ", Select_LoadGame, 0x00BB },
    // "45: Kakariko Village Row House" (Carpenter Boss's House)
    { "45:" GFXP_KATAKANA "ｶｶﾘｺ" GFXP_HIRAGANA "ﾑﾗﾉﾅｶﾞﾔ", Select_LoadGame, 0x02FD },
    // "46: Back Alley House" (Back Alley House (Man in Green))
    { "46:" GFXP_HIRAGANA "ｳﾗﾛｼﾞﾉ ｲｴ", Select_LoadGame, 0x043B },
    // "47: Kokiri Village - Know-It-All Brothers' House" (Know-It-All Brothers' House)
    { "47:" GFXP_HIRAGANA "ｺｷﾘﾉﾑﾗ ﾓﾉｼﾘｷｮｳﾀﾞｲﾉｲｴ", Select_LoadGame, 0x00C9 },
    // "48: Kokiri Village - Twins' House" (Twins' House)
    { "48:" GFXP_HIRAGANA "ｺｷﾘﾉﾑﾗ ﾌﾀｺﾞﾉｲｴ", Select_LoadGame, 0x009C },
    // "49: Kokiri Village - Mido's House" (Mido's House)
    { "49:" GFXP_HIRAGANA "ｺｷﾘﾉﾑﾗ " GFXP_KATAKANA "ﾐﾄﾞ" GFXP_HIRAGANA "ﾉｲｴ", Select_LoadGame, 0x0433 },
    // "50: Kokiri Village - Saria's House" (Saria's House)
    { "50:" GFXP_HIRAGANA "ｺｷﾘﾉﾑﾗ " GFXP_KATAKANA "ｻﾘｱ" GFXP_HIRAGANA "ﾉｲｴ", Select_LoadGame, 0x0437 },
    // "51: Stable" (Stable)
    { "51:" GFXP_HIRAGANA "ｳﾏｺﾞﾔ", Select_LoadGame, 0x02F9 },
    // "52: Grave Keeper's House" (Gravekeeper's Hut)
    { "52:" GFXP_HIRAGANA "ﾊｶﾓﾘﾉｲｴ", Select_LoadGame, 0x030D },
    // "53: Back Alley - Dog Lady's House" (Back Alley House)
    { "53:" GFXP_HIRAGANA "ｳﾗﾛｼﾞ ｲﾇｵﾊﾞｻﾝﾉｲｴ", Select_LoadGame, 0x0398 },
    // "54: Kakariko Village - Impa's House" (Impa's House)
    { "54:" GFXP_HIRAGANA "ｶｶﾘｺﾑﾗ " GFXP_KATAKANA "ｲﾝﾊﾟ" GFXP_HIRAGANA "ﾉｲｴ", Select_LoadGame, 0x039C },
    // "55: Hylia Laboratory" (Lakeside Laboratory)
    { "55:" GFXP_KATAKANA "ﾊｲﾘｱ" GFXP_HIRAGANA " ｹﾝｷｭｳｼﾞｮ", Select_LoadGame, 0x0043 },
    // "56: Tent" (Carpenters' Tent)
    { "56:" GFXP_KATAKANA "ﾃﾝﾄ", Select_LoadGame, 0x03A0 },
    // "57: Shield Shop" (Bazaar)
    { "57:" GFXP_HIRAGANA "ﾀﾃﾉﾐｾ", Select_LoadGame, 0x00B7 },
    // "58: Kokiri Shop" (Kokiri Shop)
    { "58:" GFXP_HIRAGANA "ｺｷﾘｿﾞｸﾉﾐｾ", Select_LoadGame, 0x00C1 },
    // "59: Goron Shop" (Goron Shop)
    { "59:" GFXP_KATAKANA "ｺﾞﾛﾝ" GFXP_HIRAGANA "ﾉﾐｾ", Select_LoadGame, 0x037C },
    // "60: Zora Shop" (Zora Shop)
    { "60:" GFXP_KATAKANA "ｿﾞｰﾗ" GFXP_HIRAGANA "ﾉﾐｾ", Select_LoadGame, 0x0380 },
    // "61: Kakariko Village - Potion Shop" (Kakariko Potion Shop)
    { "61:" GFXP_KATAKANA "ｶｶﾘｺ" GFXP_HIRAGANA "ﾑﾗ  ｸｽﾘﾔ", Select_LoadGame, 0x0384 },
    // "62: Castle Town - Potion Shop" (Market Potion Shop)
    { "62:" GFXP_HIRAGANA "ｼﾞｮｳｶﾏﾁ ｸｽﾘﾔ", Select_LoadGame, 0x0388 },
    // "63: Back Alley - Night Shop" (Bombchu Shop)
    { "63:" GFXP_HIRAGANA "ｳﾗﾛｼﾞ ﾖﾙﾉﾐｾ", Select_LoadGame, 0x0390 },
    // "64: Mask Shop" (Happy Mask Shop)
    { "64:" GFXP_HIRAGANA "ｵﾒﾝﾔ", Select_LoadGame, 0x0530 },
    // "65: Gerudo Training Area" (Gerudo Training Ground)
    { "65:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾉｼｭｳﾚﾝｼﾞｮｳ", Select_LoadGame, 0x0008 },
    // "66: Fairy Tree Dungeon" (Inside the Deku Tree)
    { "66:" GFXP_HIRAGANA "ﾖｳｾｲﾉｷﾉ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0000 },
    // "67: Fairy Tree Dungeon - Boss" (Gohma's Lair)
    { "67:" GFXP_HIRAGANA "ﾖｳｾｲﾉｷﾉ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ ﾎﾞｽ", Select_LoadGame, 0x040F },
    // "68: Dondogo Dungeon" (Dodongo's Cavern)
    { "68:" GFXP_KATAKANA "ﾄﾞﾄﾞﾝｺﾞ ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0004 },
    // "69: Dondogo Dungeon - Boss" (King Dodongo's Lair)
    { "69:" GFXP_KATAKANA "ﾄﾞﾄﾞﾝｺﾞ ﾀﾞﾝｼﾞｮﾝ ﾎﾞｽ", Select_LoadGame, 0x040B },
    // "70: Giant Fish Dungeon" (Inside Jabu-Jabu's Belly)
    { "70:" GFXP_HIRAGANA "ｷｮﾀﾞｲｷﾞｮ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0028 },
    // "71: Giant Fish Dungeon - Boss" (Barinade's Lair)
    { "71:" GFXP_HIRAGANA "ｷｮﾀﾞｲｷﾞｮ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ ﾎﾞｽ", Select_LoadGame, 0x0301 },
    // "72: Forest Temple" (Forest Temple)
    { "72:" GFXP_HIRAGANA "ﾓﾘﾉｼﾝﾃﾞﾝ", Select_LoadGame, 0x0169 },
    // "73: Forest Temple - Boss" (Phantom Ganon's Lair)
    { "73:" GFXP_HIRAGANA "ﾓﾘﾉｼﾝﾃﾞﾝ " GFXP_KATAKANA "ﾎﾞｽ", Select_LoadGame, 0x000C },
    // "74: Dungeon Below the Well" (Bottom of the Well)
    { "74:" GFXP_HIRAGANA "ｲﾄﾞｼﾀ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0098 },
    // "75: Dungeon Beneath the Graves" (Shadow Temple)
    { "75:" GFXP_HIRAGANA "ﾊｶｼﾀ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0037 },
    // "76: Dungeon Beneath the Graves - Boss" (Bongo Bongo's Lair)
    { "76:" GFXP_HIRAGANA "ﾊｶｼﾀ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ ﾎﾞｽ", Select_LoadGame, 0x0413 },
    // "77: Fire Temple" (Fire Temple)
    { "77:" GFXP_HIRAGANA "ﾋﾉｼﾝﾃﾞﾝ", Select_LoadGame, 0x0165 },
    // "78: Fire Temple - Boss" (Volvagia's Lair)
    { "78:" GFXP_HIRAGANA "ﾋﾉｼﾝﾃﾞﾝ " GFXP_KATAKANA "ﾎﾞｽ", Select_LoadGame, 0x0305 },
    // "79: Water Temple" (Water Temple)
    { "79:" GFXP_HIRAGANA "ﾐｽﾞﾉｼﾝﾃﾞﾝ", Select_LoadGame, 0x0010 },
    // "80: Water Temple - Boss" (Morpha's Lair)
    { "80:" GFXP_HIRAGANA "ﾐｽﾞﾉｼﾝﾃﾞﾝ " GFXP_KATAKANA "ﾎﾞｽ", Select_LoadGame, 0x0417 },
    // "81: Evil Goddess Statue Dungeon" (Spirit Temple)
    { "81:" GFXP_HIRAGANA "ｼﾞｬｼﾝｿﾞｳ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0082 },
    // "82: Evil Goddess Statue Dungeon - Iron Knuckle" (Iron Knuckle's Lair)
    { "82:" GFXP_HIRAGANA "ｼﾞｬｼﾝｿﾞｳ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ ｱｲｱﾝﾅｯｸ", Select_LoadGame, 0x008D },
    // "83: Evil Goddess Statue Dungeon - Boss" (Twinrova's Lair)
    { "83:" GFXP_HIRAGANA "ｼﾞｬｼﾝｿﾞｳ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ ﾎﾞｽ", Select_LoadGame, 0x05EC },
    // "84: Ganon's Tower" (Ganon's Tower)
    { "84:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ", Select_LoadGame, 0x041B },
    // "85: Ganon's Tower - Boss" (Ganondorf's Lair)
    { "85:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ" GFXP_KATAKANA "ﾎﾞｽ", Select_LoadGame, 0x041F },
    // "86: Ice Cavern" (Ice Cavern)
    { "86:" GFXP_HIRAGANA "ｺｵﾘﾉﾄﾞｳｸﾂ", Select_LoadGame, 0x0088 },
    // "87: Relay Beneath the Graves" (Dampé's Grave)
    { "87:" GFXP_HIRAGANA "ﾊｶｼﾀ" GFXP_KATAKANA "ﾘﾚｰ", Select_LoadGame, 0x044F },
    // "88: Ganon's Basement Dungeon" (Inside Ganon's Castle)
    { "88:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾁｶ " GFXP_KATAKANA "ﾀﾞﾝｼﾞｮﾝ", Select_LoadGame, 0x0467 },
    // "89: Final Battle With Ganon - Cutscene & Battle" (Ganondorf's Death Scene & Tower Escape Exterior)
    { "89:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ｻｲｼｭｳｾﾝ " GFXP_KATAKANA "ﾃﾞﾓ & ﾊﾞﾄﾙ", Select_LoadGame, 0x0517 },
    // "90: Ganon's Tower Aftermath 1" (Escaping Ganon's Tower 1)
    { "90:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ ｿﾉｺﾞ 1", Select_LoadGame, 0x0179 },
    // "91: Ganon's Tower Aftermath 2" (Escaping Ganon's Tower 2)
    { "91:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ ｿﾉｺﾞ 2", Select_LoadGame, 0x01B5 },
    // "92: Ganon's Tower Aftermath 3" (Escaping Ganon's Tower 3)
    { "92:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ ｿﾉｺﾞ 3", Select_LoadGame, 0x03DC },
    // "93: Ganon's Tower Aftermath 4" (Escaping Ganon's Tower 4)
    { "93:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾉﾄｳ ｿﾉｺﾞ 4", Select_LoadGame, 0x03E4 },
    // "94: Ganon's Basement Aftermath" (Escaping Ganon's Castle)
    { "94:" GFXP_KATAKANA "ｶﾞﾉﾝ" GFXP_HIRAGANA "ﾁｶ ｿﾉｺﾞ", Select_LoadGame, 0x056C },
    // "95: Gerudo Passage 1-2" (Thieves' Hideout 1)
    { "95:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 1-2", Select_LoadGame, 0x0486 },
    // "96: Gerudo Passage 3-4 9-10" (Thieves' Hideout 2)
    { "96:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 3-4 9-10", Select_LoadGame, 0x048E },
    // "97: Gerudo Passage 5-6" (Thieves' Hideout 3)
    { "97:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 5-6", Select_LoadGame, 0x0496 },
    // "98: Gerudo Passage 7-8" (Thieves' Hideout 4)
    { "98:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 7-8", Select_LoadGame, 0x049E },
    // "99: Gerudo Passage 11-12" (Thieves' Hideout 5)
    { "99:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 11-12", Select_LoadGame, 0x04AE },
    // "100: Gerudo Passage 13" (Thieves' Hideout 6)
    { "100:" GFXP_KATAKANA "ｹﾞﾙﾄﾞ" GFXP_HIRAGANA "ﾂｳﾛ 13", Select_LoadGame, 0x0570 },
    // "101: Hidden Dive Hole 0" (Grotto 0 - Gossip Stone & Chest)
    { "101:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 0", Select_LoadGame, 0x003F },
    // "102: Hidden Dive Hole 1" (Grotto 1 - Skulltula & Gold Skulltula)
    { "102:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 1", Select_LoadGame, 0x0598 },
    // "103: Hidden Dive Hole 2" (Grotto 2 - Business Scrub & Heart Piece)
    { "103:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 2", Select_LoadGame, 0x059C },
    // "104: Hidden Dive Hole 3" (Grotto 3 - Redeads)
    { "104:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 3", Select_LoadGame, 0x05A0 },
    // "105: Hidden Dive Hole 4" (Grotto 4 - 3 Business Scrubs)
    { "105:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 4", Select_LoadGame, 0x05A4 },
    // "106: Hidden Dive Hole 5" (Grotto 5 - Gossip Stone, Skulltula, Cow)
    { "106:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 5", Select_LoadGame, 0x05A8 },
    // "107: Hidden Dive Hole 6" (Grotto 6 - Octorok)
    { "107:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 6", Select_LoadGame, 0x05AC },
    // "108: Hidden Dive Hole 7" (Grotto 7 - Business Scrub & Deku Nut Upgrade)
    { "108:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 7", Select_LoadGame, 0x05B0 },
    // "109: Hidden Dive Hole 8" (Grotto 8 - 2 Wolfos)
    { "109:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 8", Select_LoadGame, 0x05B4 },
    // "110: Hidden Dive Hole 9" (Grotto 9 - Bombable Walls)
    { "110:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 9", Select_LoadGame, 0x05B8 },
    // "111: Hidden Dive Hole 10" (Grotto 10 - 2 Business Scrubs)
    { "111:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 10", Select_LoadGame, 0x05BC },
    // "112: Hidden Dive Hole 11" (Grotto 11 - Tektite & Heart Piece)
    { "112:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 11", Select_LoadGame, 0x05C0 },
    // "113: Hidden Dive Hole 12" (Grotto 12 - Deku Stage)
    { "113:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 12", Select_LoadGame, 0x05C4 },
    // "114: Hidden Dive Hole 13" (Grotto 13 - Rupees & Cow)
    { "114:" GFXP_HIRAGANA "ｶｸｼﾄﾋﾞｺﾐｱﾅ 13", Select_LoadGame, 0x05FC },
    // "115: Hyrule Cutscenes" (Cutscene Map)
    { "115:" GFXP_KATAKANA "ﾊｲﾗﾙ ﾃﾞﾓ", Select_LoadGame, 0x00A0 },
    // "116: Special Room (Treasure Chest Warp)" (Ganondorf Test Room)
    { "116:" GFXP_HIRAGANA "ﾍﾞｯｼﾂ (ﾀｶﾗﾊﾞｺ" GFXP_KATAKANA "ﾜｰﾌﾟ)", Select_LoadGame, 0x0520 },
    // "117: Sasaki Test" (Sasa Test)
    { "117:" GFXP_HIRAGANA "ｻｻ" GFXP_KATAKANA "ﾃｽﾄ", Select_LoadGame, 0x0018 },
    // "118: Test Map" (Jungle Gym)
    { "118:" GFXP_KATAKANA "ﾃｽﾄﾏｯﾌﾟ", Select_LoadGame, 0x0094 },
    // "119: Test Room" (Treasure Chest Room)
    { "119:" GFXP_KATAKANA "ﾃｽﾄﾙｰﾑ", Select_LoadGame, 0x0024 },
    // "120: Stalfos Miniboss Room" (Stalfos Miniboss Room)
    { "120:" GFXP_HIRAGANA "ﾁｭｳ" GFXP_KATAKANA "ｽﾀﾛﾌｫｽ" GFXP_HIRAGANA "ﾍﾞﾔ", Select_LoadGame, 0x001C },
    // "121: Boss Stalfos Room" (Stalfos Boss Room)
    { "121:" GFXP_KATAKANA "ﾎﾞｽｽﾀﾛﾌｫｽ" GFXP_HIRAGANA "ﾍﾞﾔ", Select_LoadGame, 0x0020 },
    // "122: Stal" (Sutaru)
    { "122:Sutaru", Select_LoadGame, 0x0047 },
    // "123: Test Area" (Shooting Gallery)
    { "123:jikkenjyou", Select_LoadGame, 0x02EA },
    // "124: Depth Test" (Depth Test)
    { "124:depth" GFXP_KATAKANA "ﾃｽﾄ", Select_LoadGame, 0x00B6 },
    // "125: Hyrule Garden Game 2" (Early Hyrule Garden Game)
    { "125:" GFXP_KATAKANA "ﾊｲﾗﾙ" GFXP_HIRAGANA "ﾆﾜ" GFXP_KATAKANA "ｹﾞｰﾑ2", Select_LoadGame, 0x0076 },
    // "title" (Title Screen)
    { "title", (void*)Select_LoadTitle, 0x0000 },
};

void Select_UpdateMenu(SelectContext* this) {
    Input* input = &this->state.input[0];
    s32 pad;
    SceneSelectEntry* selectedScene;

    if (this->verticalInputAccumulator == 0) {
        if (CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START)) {
            selectedScene = &this->scenes[this->currentScene];
            if (selectedScene->loadFunc != NULL) {
                selectedScene->loadFunc(this, selectedScene->entranceIndex);
            }
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
            if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
                gSaveContext.linkAge = 1;
            } else {
                gSaveContext.linkAge = 0;
            }
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_Z)) {
            if (gSaveContext.cutsceneIndex == 0x8000) {
                gSaveContext.cutsceneIndex = 0;
            } else if (gSaveContext.cutsceneIndex == 0) {
                gSaveContext.cutsceneIndex = 0xFFF0;
            } else if (gSaveContext.cutsceneIndex == 0xFFF0) {
                gSaveContext.cutsceneIndex = 0xFFF1;
            } else if (gSaveContext.cutsceneIndex == 0xFFF1) {
                gSaveContext.cutsceneIndex = 0xFFF2;
            } else if (gSaveContext.cutsceneIndex == 0xFFF2) {
                gSaveContext.cutsceneIndex = 0xFFF3;
            } else if (gSaveContext.cutsceneIndex == 0xFFF3) {
                gSaveContext.cutsceneIndex = 0xFFF4;
            } else if (gSaveContext.cutsceneIndex == 0xFFF4) {
                gSaveContext.cutsceneIndex = 0xFFF5;
            } else if (gSaveContext.cutsceneIndex == 0xFFF5) {
                gSaveContext.cutsceneIndex = 0xFFF6;
            } else if (gSaveContext.cutsceneIndex == 0xFFF6) {
                gSaveContext.cutsceneIndex = 0xFFF7;
            } else if (gSaveContext.cutsceneIndex == 0xFFF7) {
                gSaveContext.cutsceneIndex = 0xFFF8;
            } else if (gSaveContext.cutsceneIndex == 0xFFF8) {
                gSaveContext.cutsceneIndex = 0xFFF9;
            } else if (gSaveContext.cutsceneIndex == 0xFFF9) {
                gSaveContext.cutsceneIndex = 0xFFFA;
            } else if (gSaveContext.cutsceneIndex == 0xFFFA) {
                gSaveContext.cutsceneIndex = 0x8000;
            }
        } else if (CHECK_BTN_ALL(input->press.button, BTN_R)) {
            if (gSaveContext.cutsceneIndex == 0x8000) {
                gSaveContext.cutsceneIndex = 0xFFFA;
            } else if (gSaveContext.cutsceneIndex == 0) {
                gSaveContext.cutsceneIndex = 0x8000;
            } else if (gSaveContext.cutsceneIndex == 0xFFF0) {
                gSaveContext.cutsceneIndex = 0;
            } else if (gSaveContext.cutsceneIndex == 0xFFF1) {
                gSaveContext.cutsceneIndex = 0xFFF0;
            } else if (gSaveContext.cutsceneIndex == 0xFFF2) {
                gSaveContext.cutsceneIndex = 0xFFF1;
            } else if (gSaveContext.cutsceneIndex == 0xFFF3) {
                gSaveContext.cutsceneIndex = 0xFFF2;
            } else if (gSaveContext.cutsceneIndex == 0xFFF4) {
                gSaveContext.cutsceneIndex = 0xFFF3;
            } else if (gSaveContext.cutsceneIndex == 0xFFF5) {
                gSaveContext.cutsceneIndex = 0xFFF4;
            } else if (gSaveContext.cutsceneIndex == 0xFFF6) {
                gSaveContext.cutsceneIndex = 0xFFF5;
            } else if (gSaveContext.cutsceneIndex == 0xFFF7) {
                gSaveContext.cutsceneIndex = 0xFFF6;
            } else if (gSaveContext.cutsceneIndex == 0xFFF8) {
                gSaveContext.cutsceneIndex = 0xFFF7;
            } else if (gSaveContext.cutsceneIndex == 0xFFF9) {
                gSaveContext.cutsceneIndex = 0xFFF8;
            } else if (gSaveContext.cutsceneIndex == 0xFFFA) {
                gSaveContext.cutsceneIndex = 0xFFF9;
            }
        }

        gSaveContext.nightFlag = 0;
        if (gSaveContext.cutsceneIndex == 0) {
            gSaveContext.nightFlag = 1;
        }

        // user can change "opt", but it doesn't do anything
        if (CHECK_BTN_ALL(input->press.button, BTN_CUP)) {
            this->opt--;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
            this->opt++;
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_DUP)) {
            if (this->lockUp == true) {
                this->timerUp = 0;
            }
            if (this->timerUp == 0) {
                this->timerUp = 20;
                this->lockUp = true;
                Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                this->verticalInput = R_UPDATE_RATE;
            }
        }

        if (CHECK_BTN_ALL(input->cur.button, BTN_DUP) && this->timerUp == 0) {
            Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            this->verticalInput = R_UPDATE_RATE * 3;
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN)) {
            if (this->lockDown == true) {
                this->timerDown = 0;
            }
            if (this->timerDown == 0) {
                this->timerDown = 20;
                this->lockDown = true;
                Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                this->verticalInput = -R_UPDATE_RATE;
            }
        }

        if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN) && (this->timerDown == 0)) {
            Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            this->verticalInput = -R_UPDATE_RATE * 3;
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_DLEFT) || CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
            Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            this->verticalInput = R_UPDATE_RATE;
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_DRIGHT) || CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
            Audio_PlaySoundGeneral(NA_SE_IT_SWORD_IMPACT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            this->verticalInput = -R_UPDATE_RATE;
        }
    }

    if (CHECK_BTN_ALL(input->press.button, BTN_L)) {
        this->pageDownIndex++;
        this->pageDownIndex =
            (this->pageDownIndex + ARRAY_COUNT(this->pageDownStops)) % ARRAY_COUNT(this->pageDownStops);
        this->currentScene = this->topDisplayedScene = this->pageDownStops[this->pageDownIndex];
    }

    this->verticalInputAccumulator += this->verticalInput;

    if (this->verticalInputAccumulator < -7) {
        this->verticalInput = 0;
        this->verticalInputAccumulator = 0;

        this->currentScene++;
        this->currentScene = (this->currentScene + this->count) % this->count;

        if (this->currentScene == ((this->topDisplayedScene + this->count + 19) % this->count)) {
            this->topDisplayedScene++;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }
    }

    if (this->verticalInputAccumulator > 7) {
        this->verticalInput = 0;
        this->verticalInputAccumulator = 0;

        if (this->currentScene == this->topDisplayedScene) {
            this->topDisplayedScene -= 2;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }

        this->currentScene--;
        this->currentScene = (this->currentScene + this->count) % this->count;

        if (this->currentScene == ((this->topDisplayedScene + this->count) % this->count)) {
            this->topDisplayedScene--;
            this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;
        }
    }

    this->currentScene = (this->currentScene + this->count) % this->count;
    this->topDisplayedScene = (this->topDisplayedScene + this->count) % this->count;

    dREG(80) = this->currentScene;
    dREG(81) = this->topDisplayedScene;
    dREG(82) = this->pageDownIndex;

    if (this->timerUp != 0) {
        this->timerUp--;
    }

    if (this->timerUp == 0) {
        this->lockUp = false;
    }

    if (this->timerDown != 0) {
        this->timerDown--;
    }

    if (this->timerDown == 0) {
        this->lockDown = false;
    }
}

void Select_PrintMenu(SelectContext* this, GfxPrint* printer) {
    s32 scene;
    s32 i;
    char* name;

    GfxPrint_SetColor(printer, 255, 155, 150, 255);
    GfxPrint_SetPos(printer, 12, 2);
    GfxPrint_Printf(printer, "ZELDA MAP SELECT");
    GfxPrint_SetColor(printer, 255, 255, 255, 255);

    for (i = 0; i < 20; i++) {
        GfxPrint_SetPos(printer, 9, i + 4);

        scene = (this->topDisplayedScene + i + this->count) % this->count;
        if (scene == this->currentScene) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 200, 200, 55, 255);
        }

        name = this->scenes[scene].name;
        if (name == NULL) {
            name = "**Null**";
        }

        GfxPrint_Printf(printer, "%s", name);
    };

    GfxPrint_SetColor(printer, 155, 55, 150, 255);
    GfxPrint_SetPos(printer, 20, 26);
    GfxPrint_Printf(printer, "OPT=%d", this->opt);
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

void Select_PrintLoadingMessage(SelectContext* this, GfxPrint* printer) {
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

void Select_PrintAgeSetting(SelectContext* this, GfxPrint* printer, s32 age) {
    GfxPrint_SetPos(printer, 4, 26);
    GfxPrint_SetColor(printer, 255, 255, 55, 255);
    GfxPrint_Printf(printer, "Age:%s", sAgeLabels[age]);
}

void Select_PrintCutsceneSetting(SelectContext* this, GfxPrint* printer, u16 csIndex) {
    char* label = NULL;

    GfxPrint_SetPos(printer, 4, 25);
    GfxPrint_SetColor(printer, 255, 255, 55, 255);

    switch (csIndex) {
        case 0:
            gSaveContext.dayTime = 0; label = "Day";
            break;
        case 0x8000:
            gSaveContext.dayTime = 0x8000; label = "Night";
            break;
        case 0xFFF0:
            gSaveContext.dayTime = 0x8000; label = "Demo00";
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

void Select_DrawMenu(SelectContext* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    GfxPrint* printer;

    OPEN_DISPS(gfxCtx, "../z_select.c", 930);

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    func_80095248(gfxCtx, 0, 0, 0);
    SET_FULLSCREEN_VIEWPORT(&this->view);
    func_800AAA50(&this->view, 0xF);
    func_80094140(gfxCtx);

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, POLY_OPA_DISP);
    Select_PrintMenu(this, printer);
    Select_PrintAgeSetting(this, printer, ((void)0, gSaveContext.linkAge));
    Select_PrintCutsceneSetting(this, printer, ((void)0, gSaveContext.cutsceneIndex));
    POLY_OPA_DISP = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(gfxCtx, "../z_select.c", 966);
}

void Select_DrawLoadingScreen(SelectContext* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    GfxPrint* printer;

    OPEN_DISPS(gfxCtx, "../z_select.c", 977);

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    func_80095248(gfxCtx, 0, 0, 0);
    SET_FULLSCREEN_VIEWPORT(&this->view);
    func_800AAA50(&this->view, 0xF);
    func_80094140(gfxCtx);

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, POLY_OPA_DISP);
    Select_PrintLoadingMessage(this, printer);
    POLY_OPA_DISP = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(gfxCtx, "../z_select.c", 1006);
}

void Select_Draw(SelectContext* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_select.c", 1013);

    gSPSegment(POLY_OPA_DISP++, 0x00, NULL);
    func_80095248(gfxCtx, 0, 0, 0);
    SET_FULLSCREEN_VIEWPORT(&this->view);
    func_800AAA50(&this->view, 0xF);

    if (!this->state.running) {
        Select_DrawLoadingScreen(this);
    } else {
        Select_DrawMenu(this);
    }

    CLOSE_DISPS(gfxCtx, "../z_select.c", 1037);
}

void Select_Main(GameState* thisx) {
    SelectContext* this = (SelectContext*)thisx;

    Select_UpdateMenu(this);
    Select_Draw(this);
}

void Select_Destroy(GameState* thisx) {
    osSyncPrintf("%c", '\a'); // ASCII BEL character, plays an alert tone
    // "view_cleanup will hang, so it won't be called"
    osSyncPrintf("*** view_cleanup will hang, so it won't be called ***\n");
}

void Select_Init(GameState* thisx) {
    SelectContext* this = (SelectContext*)thisx;
    u32 size;
    s32 pad;

    this->state.main = Select_Main;
    this->state.destroy = Select_Destroy;
    this->scenes = sScenes;
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
    this->count = ARRAY_COUNT(sScenes);
    View_Init(&this->view, this->state.gfxCtx);
    this->view.flags = (0x08 | 0x02);
    this->verticalInputAccumulator = 0;
    this->verticalInput = 0;
    this->timerUp = 0;
    this->timerDown = 0;
    this->lockUp = 0;
    this->lockDown = 0;
    this->unk_234 = 0;

    size = POINTER_SUB(_z_select_staticSegmentRomEnd, _z_select_staticSegmentRomStart);

    if ((dREG(80) >= 0) && (dREG(80) < this->count)) {
        this->currentScene = dREG(80);
        this->topDisplayedScene = dREG(81);
        this->pageDownIndex = dREG(82);
    }
    R_UPDATE_RATE = 1;

    this->staticSegment = GameState_Alloc(&this->state, size, "../z_select.c", 1114);
    DmaMgr_SendRequest1(this->staticSegment, _z_select_staticSegmentRomStart, size, "../z_select.c", 1115);
    gSaveContext.cutsceneIndex = 0x8000;
    gSaveContext.linkAge = 1;
}

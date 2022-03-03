#define INTERNAL_SRC_CODE_Z_MAP_EXP_C
#include "global.h"
#include "segment_symbols.h"
#include "z64global.h"
#include "n64mapdata.h"
#include "z64player.h"
#include "z64save.h"
#include "z64item.h"
#include "sfx.h"
#include "vt.h"
#include "gfx_align.h"
#include "asset.h"
#include "def/inventory.h"
#include "def/audio_bank.h"
#include "def/game.h"
#include "def/sys_matrix.h"
#include "def/z_common_data.h"
#include "def/z_map_data.h"
#include "def/z_map_exp.h"
#include "def/z_map_mark.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_std_dma.h"
#include "def/graph.h" // FORCE

static void* map_grand_static_lut[] = {
    oot::asset::texture::load(symbol::gHyruleFieldMinimapTex),
    oot::asset::texture::load(symbol::gKakarikoVillageMinimapTex),
    oot::asset::texture::load(symbol::gGraveyardMinimapTex),
    oot::asset::texture::load(symbol::gZorasRiverMinimapTex),
    oot::asset::texture::load(symbol::gKokiriForestMinimapTex),
    oot::asset::texture::load(symbol::gSacredMeadowMinimapTex),
    oot::asset::texture::load(symbol::gLakeHyliaMinimapTex),
    oot::asset::texture::load(symbol::gZorasDomainMinimapTex),
    oot::asset::texture::load(symbol::gZorasFountainMinimapTex),
    oot::asset::texture::load(symbol::gGerudoValleyMinimapTex),
    oot::asset::texture::load(symbol::gHauntedWastelandMinimapTex),
    oot::asset::texture::load(symbol::gDesertColossusMinimapTex),
    oot::asset::texture::load(symbol::gGerudosFortessMinimapTex),
    oot::asset::texture::load(symbol::gLostWoodsMinimapTex),
    oot::asset::texture::load(symbol::gHyruleCastleAreaMinimapTex),
    oot::asset::texture::load(symbol::gDeathMountainTrailMinimapTex),
    oot::asset::texture::load(symbol::gDeathMountainCraterMinimapTex),
    oot::asset::texture::load(symbol::gGoronCityMinimapTex),
    oot::asset::texture::load(symbol::gLonLonRanchMinimapTex),
    oot::asset::texture::load(symbol::gOutsideGanonsCastleMinimapTex),
    oot::asset::texture::load(symbol::gExploredShadowGraveyardMinimapTex),
    oot::asset::texture::load(symbol::gDrainedLakeHyliaMinimapTex),
    oot::asset::texture::load(symbol::gGerudoValleyWithBrokenBridgeMinimapTex),
    oot::asset::texture::load(symbol::gGerudosFortressMinimapTex)};

static void* map_i_static_lut[] = {
    oot::asset::texture::load(symbol::gDekuTreeRoom0Floor1MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom1MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom2MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom3MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom4MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom5MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom6MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom7MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom8MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom9MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom10MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom0Floor2MinimapTex),
    oot::asset::texture::load(symbol::gDekuTreeRoom0Floor3MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom0MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom1MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom2MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom3MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom4MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom5MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom6MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom7MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom8MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom9MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom10MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom11MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom12MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom13MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom14MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom15MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom0Floor3MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom2Floor3MinimapTex),
    oot::asset::texture::load(symbol::gDodongosCavernRoom3Floor3MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom0MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom1MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom2MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom3MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom4MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom5MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom6MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom7MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom8MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom9MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom10MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom11MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom12MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom13MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom14MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom1Basement1MinimapTex),
    oot::asset::texture::load(symbol::gJabuRoom6Basement1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom0Floor1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom2MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom3MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom4MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom5MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom6Floor1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom7Floor1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom8Floor1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom9MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom10MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom11Floor1MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom12MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom13MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom14MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom15MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom16MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom17MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom18MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom19MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom20MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom21MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom0Floor3MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom6Floor3MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom7Floor3MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom8Floor3MinimapTex),
    oot::asset::texture::load(symbol::gForestTempleRoom11Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom0MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom2MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom4Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom5Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom6Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom7Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom8MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom9MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom10Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom11Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom12Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom13Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom14MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom15MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom16MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom17MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom18MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom19MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom20MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom21Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom22MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom23MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom24Floor1MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom25MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom4Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom5Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom6Floor2MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom6Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom7Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom10Floor2MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom10Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom11Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom12Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom13Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom21Floor3MinimapTex),
    oot::asset::texture::load(symbol::gFireTempleRoom24Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom0Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom1Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom3Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom4Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom5Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom6MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom7MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom8Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom9Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom10Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom11MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom12Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom13MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom14Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom15Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom16MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom17Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom18MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom19MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom20Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom21Floor3MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom0Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom0Floor1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom0Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom1Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom1Floor1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom1Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom3Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom4Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom5Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom5Floor1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom6Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom8Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom9Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom10Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom12Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom14Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom15Basement1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom17Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom17Floor1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom20Floor2MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom21Floor1MinimapTex),
    oot::asset::texture::load(symbol::gWaterTempleRoom5Basement1MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom0MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom1MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom2MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom3MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom4Floor1MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom5Floor2MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom6MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom7MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom8MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom9MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom10MinimapTex),
    oot::asset::texture::load(symbol::gBlankSpiritTempleRoom11MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom12MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom13MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom14MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom15Floor1MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom16MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom17MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom18MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom19MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom20MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom21MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom22MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom23Floor3MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom24MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom25MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom26MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom27MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom4Floor2MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom5Floor3MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom15Floor2MinimapTex),
    oot::asset::texture::load(symbol::gSpiritTempleRoom23Floor4MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom0MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom1MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom2MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom4MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom5MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom6MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom7MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom8Basement2MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom9Basement3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom10MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom11MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom12Basement3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom13MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom14Basement3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom15MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom16MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom17MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom18MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom19MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom20MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom21Basement3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom8Basement3MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom9Basement4MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom12Basement4MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom14Basement4MinimapTex),
    oot::asset::texture::load(symbol::gShadowTempleRoom21Basement4MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom0Basement1MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom1Basement1MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom2MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom3MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom4MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom5MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom6MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom0Basement2MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom1Basement2MinimapTex),
    oot::asset::texture::load(symbol::gBottomOfTheWellRoom1Basement3MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom0MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom1MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom2MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom3MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom4MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom5MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom6MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom7MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom8MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom9MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom10MinimapTex),
    oot::asset::texture::load(symbol::gIceCavernRoom11MinimapTex)};

MapData* gMapData;
extern MapData gMapDataTable;

s16 sPlayerInitialPosX = 0;
s16 sPlayerInitialPosZ = 0;
s16 sPlayerInitialDirection = 0;
s16 sEntranceIconMapIndex = 0;

void Map_SavePlayerInitialInfo(GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    sPlayerInitialPosX = player->actor.world.pos.x;
    sPlayerInitialPosZ = player->actor.world.pos.z;
    sPlayerInitialDirection = (s16)((0x7FFF - player->actor.shape.rot.y) / 0x400);
}

void Map_SetPaletteData(GlobalContext* globalCtx, s16 room) {
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    s16 paletteIndex = gMapData->roomPalette[mapIndex][room];

    if (interfaceCtx->mapRoomNum == room) {
        interfaceCtx->mapPaletteIndex = paletteIndex;
    }

    osSyncPrintf(VT_FGCOL(YELLOW));
    // "PALETE Set"
    osSyncPrintf("ＰＡＬＥＴＥセット 【 i=%x : room=%x 】Room_Inf[%d][4]=%x  ( map_palete_no = %d )\n", paletteIndex,
                 room, mapIndex, gSaveContext.sceneFlags[mapIndex].rooms, interfaceCtx->mapPaletteIndex);
    osSyncPrintf(VT_RST);

    interfaceCtx->mapPalette[paletteIndex * 2] = 2;
    interfaceCtx->mapPalette[paletteIndex * 2 + 1] = 0xBF;
}

void Map_SetFloorPalettesData(GlobalContext* globalCtx, s16 floor) {
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    s16 room;
    s16 i;

    for (i = 0; i < 16; i++) {
        interfaceCtx->mapPalette[i] = 0;
        interfaceCtx->mapPalette[i + 16] = 0;
    }

    if (CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex)) {
        interfaceCtx->mapPalette[30] = 0;
        interfaceCtx->mapPalette[31] = 1;
    }

    switch (globalCtx->sceneNum) {
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
        case SCENE_YDAN_BOSS:
        case SCENE_DDAN_BOSS:
        case SCENE_BDAN_BOSS:
        case SCENE_MORIBOSSROOM:
        case SCENE_FIRE_BS:
        case SCENE_MIZUSIN_BS:
        case SCENE_JYASINBOSS:
        case SCENE_HAKADAN_BS:
            for (i = 0; i < gMapData->maxPaletteCount[mapIndex]; i++) {
                room = gMapData->paletteRoom[mapIndex][floor][i];
                if ((room != 0xFF) && (gSaveContext.sceneFlags[mapIndex].rooms & gBitFlags[room])) {
                    Map_SetPaletteData(globalCtx, room);
                }
            }
            break;
    }
}

void Map_InitData(GlobalContext* globalCtx, s16 room) {
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    s16 extendedMapIndex;

    switch (globalCtx->sceneNum) {
        case SCENE_SPOT00:
        case SCENE_SPOT01:
        case SCENE_SPOT02:
        case SCENE_SPOT03:
        case SCENE_SPOT04:
        case SCENE_SPOT05:
        case SCENE_SPOT06:
        case SCENE_SPOT07:
        case SCENE_SPOT08:
        case SCENE_SPOT09:
        case SCENE_SPOT10:
        case SCENE_SPOT11:
        case SCENE_SPOT12:
        case SCENE_SPOT13:
        case SCENE_SPOT15:
        case SCENE_SPOT16:
        case SCENE_SPOT17:
        case SCENE_SPOT18:
        case SCENE_SPOT20:
        case SCENE_GANON_TOU:
            extendedMapIndex = mapIndex;
            if (globalCtx->sceneNum == SCENE_SPOT02) {
                if (CHECK_QUEST_ITEM(QUEST_SONG_NOCTURNE)) {
                    extendedMapIndex = 0x14;
                }
            } else if (globalCtx->sceneNum == SCENE_SPOT06) {
                if ((LINK_AGE_IN_YEARS == YEARS_ADULT) && !CHECK_QUEST_ITEM(QUEST_MEDALLION_WATER)) {
                    extendedMapIndex = 0x15;
                }
            } else if (globalCtx->sceneNum == SCENE_SPOT09) {
                if ((LINK_AGE_IN_YEARS == YEARS_ADULT) && !((gSaveContext.eventChkInf[9] & 0xF) == 0xF)) {
                    extendedMapIndex = 0x16;
                }
            } else if (globalCtx->sceneNum == SCENE_SPOT12) {
                if ((gSaveContext.eventChkInf[9] & 0xF) == 0xF) {
                    extendedMapIndex = 0x17;
                }
            }
            osSyncPrintf(VT_FGCOL(BLUE));
            osSyncPrintf("ＫＫＫ＝%d\n", extendedMapIndex);
            osSyncPrintf(VT_RST);
            sEntranceIconMapIndex = extendedMapIndex;

            interfaceCtx->mapSegment1 = (u8*)POINTER_ADD(_map_grand_staticSegmentRomStart, gMapData->owMinimapTexOffset[extendedMapIndex]);

            //interfaceCtx->mapSegment = map_grand_static_lut[extendedMapIndex];
            interfaceCtx->unk_258 = mapIndex;
            break;
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
        case SCENE_YDAN_BOSS:
        case SCENE_DDAN_BOSS:
        case SCENE_BDAN_BOSS:
        case SCENE_MORIBOSSROOM:
        case SCENE_FIRE_BS:
        case SCENE_MIZUSIN_BS:
        case SCENE_JYASINBOSS:
        case SCENE_HAKADAN_BS:
            osSyncPrintf(VT_FGCOL(YELLOW));
            // "Deku Tree Dungeon MAP Texture DMA"
            osSyncPrintf("デクの樹ダンジョンＭＡＰ テクスチャＤＭＡ(%x) scene_id_offset=%d  VREG(30)=%d\n", room,
                         mapIndex, VREG(30));
            osSyncPrintf(VT_RST);
            globalCtx->interfaceCtx.mapSegment1 = (u8*)map_i_static_lut[gMapData->dgnMinimapTexIndexOffset[mapIndex] + room];
            R_COMPASS_OFFSET_X = gMapData->roomCompassOffsetX[mapIndex][room];
            R_COMPASS_OFFSET_Y = gMapData->roomCompassOffsetY[mapIndex][room];
            Map_SetFloorPalettesData(globalCtx, VREG(30));
            osSyncPrintf("ＭＡＰ 各階ＯＮチェック\n"); // "MAP Individual Floor ON Check"
            break;
    }
}

void Map_InitRoomData(GlobalContext* globalCtx, s16 room) {
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    osSyncPrintf("＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊\nroom_no=%d (%d)(%d)\n＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊\n", room,
                 mapIndex, globalCtx->sceneNum);

    if (room >= 0) {
        switch (globalCtx->sceneNum) {
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
            case SCENE_YDAN_BOSS:
            case SCENE_DDAN_BOSS:
            case SCENE_BDAN_BOSS:
            case SCENE_MORIBOSSROOM:
            case SCENE_FIRE_BS:
            case SCENE_MIZUSIN_BS:
            case SCENE_JYASINBOSS:
            case SCENE_HAKADAN_BS:
                gSaveContext.sceneFlags[mapIndex].rooms |= gBitFlags[room];
                osSyncPrintf("ＲＯＯＭ＿ＩＮＦ＝%d\n", gSaveContext.sceneFlags[mapIndex].rooms);
                interfaceCtx->mapRoomNum = room;
                interfaceCtx->unk_25A = mapIndex;
                Map_SetPaletteData(globalCtx, room);
                osSyncPrintf(VT_FGCOL(YELLOW));
                osSyncPrintf("部屋部屋＝%d\n", room); // "Room Room = %d"
                osSyncPrintf(VT_RST);
                Map_InitData(globalCtx, room);
                break;
        }
    } else {
        interfaceCtx->mapRoomNum = 0;
    }

    if (gSaveContext.sunsSongState != SUNSSONG_SPEED_TIME) {
        gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
    }
}

void Map_Destroy(GlobalContext* globalCtx) {
    MapMark_ClearPointers(globalCtx);
    gMapData = NULL;
}

void Map_Init(GlobalContext* globalCtx) {
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    gMapData = &gMapDataTable;

    interfaceCtx->unk_258 = -1;
    interfaceCtx->unk_25A = -1;

    interfaceCtx->mapSegment1 = NULL;
    interfaceCtx->mapSegment2 = NULL;

    switch (globalCtx->sceneNum) {
        case SCENE_SPOT00:
        case SCENE_SPOT01:
        case SCENE_SPOT02:
        case SCENE_SPOT03:
        case SCENE_SPOT04:
        case SCENE_SPOT05:
        case SCENE_SPOT06:
        case SCENE_SPOT07:
        case SCENE_SPOT08:
        case SCENE_SPOT09:
        case SCENE_SPOT10:
        case SCENE_SPOT11:
        case SCENE_SPOT12:
        case SCENE_SPOT13:
        case SCENE_SPOT15:
        case SCENE_SPOT16:
        case SCENE_SPOT17:
        case SCENE_SPOT18:
        case SCENE_SPOT20:
        case SCENE_GANON_TOU:
            mapIndex = globalCtx->sceneNum - SCENE_SPOT00;
            R_MAP_INDEX = gSaveContext.mapIndex = mapIndex;
            R_COMPASS_SCALE_X = gMapData->owCompassInfo[mapIndex][0];
            R_COMPASS_SCALE_Y = gMapData->owCompassInfo[mapIndex][1];
            R_COMPASS_OFFSET_X = gMapData->owCompassInfo[mapIndex][2];
            R_COMPASS_OFFSET_Y = gMapData->owCompassInfo[mapIndex][3];
            Map_InitData(globalCtx, mapIndex);
            R_OW_MINIMAP_X = gMapData->owMinimapPosX[mapIndex];
            R_OW_MINIMAP_Y = gMapData->owMinimapPosY[mapIndex];
            break;
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
        case SCENE_GANON_SONOGO:
        case SCENE_GANONTIKA_SONOGO:
        case SCENE_TAKARAYA:
        case SCENE_YDAN_BOSS:
        case SCENE_DDAN_BOSS:
        case SCENE_BDAN_BOSS:
        case SCENE_MORIBOSSROOM:
        case SCENE_FIRE_BS:
        case SCENE_MIZUSIN_BS:
        case SCENE_JYASINBOSS:
        case SCENE_HAKADAN_BS:
            mapIndex =
                (globalCtx->sceneNum >= SCENE_YDAN_BOSS) ? globalCtx->sceneNum - SCENE_YDAN_BOSS : globalCtx->sceneNum;
            R_MAP_INDEX = gSaveContext.mapIndex = mapIndex;
            if ((globalCtx->sceneNum <= SCENE_ICE_DOUKUTO) || (globalCtx->sceneNum >= SCENE_YDAN_BOSS)) {
                R_COMPASS_SCALE_X = gMapData->dgnCompassInfo[mapIndex][0];
                R_COMPASS_SCALE_Y = gMapData->dgnCompassInfo[mapIndex][1];
                R_COMPASS_OFFSET_X = gMapData->dgnCompassInfo[mapIndex][2];
                R_COMPASS_OFFSET_Y = gMapData->dgnCompassInfo[mapIndex][3];
                R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE = gMapData->dgnMinimapTexIndexBase[mapIndex];
                Map_InitRoomData(globalCtx, globalCtx->roomCtx.curRoom.num);
                MapMark_Init(globalCtx);
            }
            break;
    }
}

void Minimap_DrawCompassIcons(GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s16 tempX, tempZ;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_map_exp.c", 565);

    if (globalCtx->interfaceCtx.minimapAlpha >= 0xAA) {
        func_80094A14(globalCtx->state.gfxCtx);

        gSPMatrix(OVERLAY_DISP++, &gMtxClear, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);
        gDPSetCombineMode(OVERLAY_DISP++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

        tempX = player->actor.world.pos.x;
        tempZ = player->actor.world.pos.z;
        tempX /= R_COMPASS_SCALE_X;
        tempZ /= R_COMPASS_SCALE_Y;
        Matrix_Translate(GFX_ALIGN_RIGHT_F((R_COMPASS_OFFSET_X + tempX) / 10.0f), (R_COMPASS_OFFSET_Y - tempZ) / 10.0f, 0.0f, MTXMODE_NEW);
        Matrix_Scale(0.4f, 0.4f, 0.4f, MTXMODE_APPLY);
        Matrix_RotateX(-1.6f, MTXMODE_APPLY);
        tempX = (0x7FFF - player->actor.shape.rot.y) / 0x400;
        Matrix_RotateY(tempX / 10.0f, MTXMODE_APPLY);
        gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_map_exp.c", 585),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 200, 255, 0, 255);
        gSPDisplayList(OVERLAY_DISP++, oot::asset::gfx::load(symbol::gCompassArrowDL));

        tempX = sPlayerInitialPosX;
        tempZ = sPlayerInitialPosZ;
        tempX /= R_COMPASS_SCALE_X;
        tempZ /= R_COMPASS_SCALE_Y;
        Matrix_Translate(GFX_ALIGN_RIGHT_F((R_COMPASS_OFFSET_X + tempX) / 10.0f), (R_COMPASS_OFFSET_Y - tempZ) / 10.0f, 0.0f, MTXMODE_NEW);
        Matrix_Scale(VREG(9) / 100.0f, VREG(9) / 100.0f, VREG(9) / 100.0f, MTXMODE_APPLY);
        Matrix_RotateX(VREG(52) / 10.0f, MTXMODE_APPLY);
        Matrix_RotateY(sPlayerInitialDirection / 10.0f, MTXMODE_APPLY);
        gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_map_exp.c", 603),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDPSetPrimColor(OVERLAY_DISP++, 0, 0xFF, 200, 0, 0, 255);
        gSPDisplayList(OVERLAY_DISP++, oot::asset::gfx::load(symbol::gCompassArrowDL));
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_map_exp.c", 607);
}

void Minimap_Draw(GlobalContext* globalCtx) {
    s32 pad[2];
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    s32 mapIndex = gSaveContext.mapIndex;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_map_exp.c", 626);

    if (globalCtx->pauseCtx.state < 4) {
        switch (globalCtx->sceneNum) {
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
                if (!R_MINIMAP_DISABLED) {
                    func_80094520(globalCtx->state.gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0,
                                      TEXEL0, 0, PRIMITIVE, 0);

                    if (CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex)) {
                        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 100, 255, 255, interfaceCtx->minimapAlpha);

                        gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->mapSegment1, G_IM_FMT_I, 96, 85, 0,
                                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                        gSPTextureRectangle(OVERLAY_DISP++, GFX_ALIGN_RIGHT(R_DGN_MINIMAP_X) << 2, R_DGN_MINIMAP_Y << 2,
                                            (GFX_ALIGN_RIGHT(R_DGN_MINIMAP_X) + 96) << 2, (R_DGN_MINIMAP_Y + 85) << 2, G_TX_RENDERTILE,
                                            0, 0, 1 << 10, 1 << 10);
                    }

                    if (CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, mapIndex)) {
                        Minimap_DrawCompassIcons(globalCtx); // Draw icons for the player spawn and current position
                        func_80094520(globalCtx->state.gfxCtx);
                        MapMark_Draw(globalCtx);
                    }
                }

                if (CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_L) && !Gameplay_InCsMode(globalCtx)) {
                    osSyncPrintf("Game_play_demo_mode_check=%d\n", Gameplay_InCsMode(globalCtx));
                    // clang-format off
                    if (!R_MINIMAP_DISABLED) { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_UP, &gAudioDefaultPos, 4,
                                                                      &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    else { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_DOWN, &gAudioDefaultPos, 4,
                                                  &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    // clang-format on
                    R_MINIMAP_DISABLED ^= 1;
                }

                break;
            case SCENE_SPOT00:
            case SCENE_SPOT01:
            case SCENE_SPOT02:
            case SCENE_SPOT03:
            case SCENE_SPOT04:
            case SCENE_SPOT05:
            case SCENE_SPOT06:
            case SCENE_SPOT07:
            case SCENE_SPOT08:
            case SCENE_SPOT09:
            case SCENE_SPOT10:
            case SCENE_SPOT11:
            case SCENE_SPOT12:
            case SCENE_SPOT13:
            case SCENE_SPOT15:
            case SCENE_SPOT16:
            case SCENE_SPOT17:
            case SCENE_SPOT18:
            case SCENE_SPOT20:
            case SCENE_GANON_TOU:
                if (!R_MINIMAP_DISABLED) {
                    func_80094520(globalCtx->state.gfxCtx);

                    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, R_MINIMAP_COLOR(0), R_MINIMAP_COLOR(1), R_MINIMAP_COLOR(2),
                                    interfaceCtx->minimapAlpha);

                    gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->mapSegment1, G_IM_FMT_IA,
                                           gMapData->owMinimapWidth[mapIndex], gMapData->owMinimapHeight[mapIndex], 0,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    gSPTextureRectangle(OVERLAY_DISP++, GFX_ALIGN_RIGHT(R_OW_MINIMAP_X) << 2, R_OW_MINIMAP_Y << 2,
                                        (GFX_ALIGN_RIGHT(R_OW_MINIMAP_X) + gMapData->owMinimapWidth[mapIndex]) << 2,
                                        (R_OW_MINIMAP_Y + gMapData->owMinimapHeight[mapIndex]) << 2, G_TX_RENDERTILE, 0,
                                        0, 1 << 10, 1 << 10);

                    if (((globalCtx->sceneNum != SCENE_SPOT01) && (globalCtx->sceneNum != SCENE_SPOT04) &&
                         (globalCtx->sceneNum != SCENE_SPOT08)) ||
                        (LINK_AGE_IN_YEARS != YEARS_ADULT)) {
                        if ((gMapData->owEntranceFlag[sEntranceIconMapIndex] == 0xFFFF) ||
                            ((gMapData->owEntranceFlag[sEntranceIconMapIndex] != 0xFFFF) &&
                             (gSaveContext.infTable[26] & gBitFlags[gMapData->owEntranceFlag[mapIndex]]))) {

                            gDPLoadTextureBlock(OVERLAY_DISP++, oot::asset::texture::load(symbol::gMapDungeonEntranceIconTex), G_IM_FMT_RGBA, G_IM_SIZ_16b,
                                                8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            gSPTextureRectangle(OVERLAY_DISP++,
                                                GFX_ALIGN_RIGHT(gMapData->owEntranceIconPosX[sEntranceIconMapIndex]) << 2,
                                                gMapData->owEntranceIconPosY[sEntranceIconMapIndex] << 2,
                                                GFX_ALIGN_RIGHT(gMapData->owEntranceIconPosX[sEntranceIconMapIndex] + 8) << 2,
                                                (gMapData->owEntranceIconPosY[sEntranceIconMapIndex] + 8) << 2,
                                                G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                        }
                    }

                    if ((globalCtx->sceneNum == SCENE_SPOT08) && (gSaveContext.infTable[26] & gBitFlags[9])) {
                        gDPLoadTextureBlock(OVERLAY_DISP++, oot::asset::texture::load(symbol::gMapDungeonEntranceIconTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 8,
                                            8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                        gSPTextureRectangle(OVERLAY_DISP++, GFX_ALIGN_RIGHT(270) << 2, 616, 1112, 648, G_TX_RENDERTILE, 0, 0, 1 << 10,
                                            1 << 10);
                    }

                    Minimap_DrawCompassIcons(globalCtx); // Draw icons for the player spawn and current position
                }

                if (CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_L) && !Gameplay_InCsMode(globalCtx)) {
                    // clang-format off
                    if (!R_MINIMAP_DISABLED) { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_UP, &gAudioDefaultPos, 4,
                                                                      &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    else { Audio_PlaySoundGeneral(NA_SE_SY_CAMERA_ZOOM_DOWN, &gAudioDefaultPos, 4,
                                                  &D_801333E0, &D_801333E0, &gReverbAdd2); }
                    // clang-format on
                    R_MINIMAP_DISABLED ^= 1;
                }

                break;
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_map_exp.c", 782);
}

s16 Map_GetFloorTextIndexOffset(s32 mapIndex, s32 floor) {
    return gMapData->floorTexIndexOffset[mapIndex][floor];
}

void Map_Update(GlobalContext* globalCtx) {
    static s16 sLastRoomNum = 99;
    Player* player = GET_PLAYER(globalCtx);
    s32 mapIndex = gSaveContext.mapIndex;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    s16 floor;
    s16 i;

    if ((globalCtx->pauseCtx.state == 0) && (globalCtx->pauseCtx.debugState == 0)) {
        switch (globalCtx->sceneNum) {
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
                interfaceCtx->mapPalette[30] = 0;
                if (CHECK_DUNGEON_ITEM(DUNGEON_MAP, mapIndex)) {
                    interfaceCtx->mapPalette[31] = 1;
                } else {
                    interfaceCtx->mapPalette[31] = 0;
                }

                for (floor = 0; floor < 8; floor++) {
                    if (player->actor.world.pos.y > gMapData->floorCoordY[mapIndex][floor]) {
                        break;
                    }
                }

                gSaveContext.sceneFlags[mapIndex].floors |= gBitFlags[floor];
                VREG(30) = floor;
                if (R_MAP_TEX_INDEX != (R_MAP_TEX_INDEX_BASE + Map_GetFloorTextIndexOffset(mapIndex, floor))) {
                    R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE + Map_GetFloorTextIndexOffset(mapIndex, floor);
                }
                if (1) {} // Appears to be necessary to match

                if (interfaceCtx->mapRoomNum != sLastRoomNum) {
                    // "Current floor = %d Current room = %x Number of rooms = %d"
                    osSyncPrintf("現在階＝%d  現在部屋＝%x  部屋数＝%d\n", floor, interfaceCtx->mapRoomNum,
                                 gMapData->switchEntryCount[mapIndex]);
                    sLastRoomNum = interfaceCtx->mapRoomNum;
                }

                for (i = 0; i < gMapData->switchEntryCount[mapIndex]; i++) {
                    if ((interfaceCtx->mapRoomNum == gMapData->switchFromRoom[mapIndex][i]) &&
                        (floor == gMapData->switchFromFloor[mapIndex][i])) {
                        interfaceCtx->mapRoomNum = gMapData->switchToRoom[mapIndex][i];
                        osSyncPrintf(VT_FGCOL(YELLOW));
                        // "Layer switching = %x"
                        osSyncPrintf("階層切替＝%x\n", interfaceCtx->mapRoomNum);
                        osSyncPrintf(VT_RST);
                        Map_InitData(globalCtx, interfaceCtx->mapRoomNum);
                        gSaveContext.sunsSongState = SUNSSONG_INACTIVE;
                        Map_SavePlayerInitialInfo(globalCtx);
                    }
                }

                VREG(10) = interfaceCtx->mapRoomNum;
                break;
            case SCENE_YDAN_BOSS:
            case SCENE_DDAN_BOSS:
            case SCENE_BDAN_BOSS:
            case SCENE_MORIBOSSROOM:
            case SCENE_FIRE_BS:
            case SCENE_MIZUSIN_BS:
            case SCENE_JYASINBOSS:
            case SCENE_HAKADAN_BS:
                VREG(30) = gMapData->bossFloor[globalCtx->sceneNum - SCENE_YDAN_BOSS];
                R_MAP_TEX_INDEX = R_MAP_TEX_INDEX_BASE +
                                  gMapData->floorTexIndexOffset[globalCtx->sceneNum - SCENE_YDAN_BOSS][VREG(30)];
                break;
        }
    }
}

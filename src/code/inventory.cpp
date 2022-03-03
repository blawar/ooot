#define INTERNAL_SRC_CODE_CODE_80097A00_C
#include "global.h"
#include "z64save.h"
#include "z64item.h"
#include "z64global.h"
#include "z64player.h"
#include "asset.h"
#include "gfx.h"
#include "def/inventory.h"
#include "def/z_common_data.h"
#include "def/z_player_lib.h"


// Bit Flag array in which gBitFlags[n] is literally (1 << n)
u32 gBitFlags[] = {
    (1 << 0),  (1 << 1),  (1 << 2),  (1 << 3),  (1 << 4),  (1 << 5),  (1 << 6),  (1 << 7),
    (1 << 8),  (1 << 9),  (1 << 10), (1 << 11), (1 << 12), (1 << 13), (1 << 14), (1 << 15),
    (1 << 16), (1 << 17), (1 << 18), (1 << 19), (1 << 20), (1 << 21), (1 << 22), (1 << 23),
    (1 << 24), (1 << 25), (1 << 26), (1 << 27), (1 << 28), (1 << 29), (1 << 30), (1 << 31),
};

u16 gEquipMasks[] = { 0x000F, 0x00F0, 0x0F00, 0xF000 };
u16 gEquipNegMasks[] = { 0xFFF0, 0xFF0F, 0xF0FF, 0x0FFF };
u32 gUpgradeMasks[] = {
    0x00000007, 0x00000038, 0x000001C0, 0x00000E00, 0x00003000, 0x0001C000, 0x000E0000, 0x00700000,
};
u32 gUpgradeNegMasks[] = {
    0xFFFFFFF8, 0xFFFFFFC7, 0xFFFFFE3F, 0xFFFFF1FF, 0xFFFFCFFF, 0xFFFE3FFF, 0xFFF1FFFF, 0xFF8FFFFF,
};
u8 gEquipShifts[] = { 0, 4, 8, 12 };
u8 gUpgradeShifts[] = { 0, 3, 6, 9, 12, 14, 17, 20 };

u16 gUpgradeCapacities[][4] = {
    { 0, 30, 40, 50 },     // Quivers
    { 0, 20, 30, 40 },     // Bomb Bags
    { 0, 0, 0, 0 },        // Unused (Scale)
    { 0, 0, 0, 0 },        // Unused (Strength)
    { 99, 200, 500, 500 }, // Wallets
    { 0, 30, 40, 50 },     // Deku Seed Bullet Bags
    { 0, 10, 20, 30 },     // Deku Stick Upgrades
    { 0, 20, 30, 40 },     // Deku Nut Upgrades
};

u32 gGsFlagsMasks[] = { 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000 };
u32 gGsFlagsShifts[] = { 0, 8, 16, 24 };

static void* gItemIcons[] = {
    oot::asset::texture::load(symbol::gDekuStickIconTex),
    oot::asset::texture::load(symbol::gDekuNutIconTex),
    oot::asset::texture::load(symbol::gBombIconTex),
    oot::asset::texture::load(symbol::gFairyBowIconTex),
    oot::asset::texture::load(symbol::gFireArrowIconTex),
    oot::asset::texture::load(symbol::gDinsFireIconTex),
    oot::asset::texture::load(symbol::gFairySlingshotIconTex),
    oot::asset::texture::load(symbol::gFairyOcarinaIconTex),
    oot::asset::texture::load(symbol::gOcarinaofTimeIconTex),
    oot::asset::texture::load(symbol::gBombchuIconTex),
    oot::asset::texture::load(symbol::gHookshotIconTex),
    oot::asset::texture::load(symbol::gLongshotIconTex),
    oot::asset::texture::load(symbol::gIceArrowIconTex),
    oot::asset::texture::load(symbol::gFaroresWindIconTex),
    oot::asset::texture::load(symbol::gBoomerangIconTex),
    oot::asset::texture::load(symbol::gLensofTruthIconTex),
    oot::asset::texture::load(symbol::gMagicBeansIconTex),
    oot::asset::texture::load(symbol::gMegatonHammerIconTex),
    oot::asset::texture::load(symbol::gLightArrowIconTex),
    oot::asset::texture::load(symbol::gNayrusLoveIconTex),
    oot::asset::texture::load(symbol::gEmptyBottleIconTex),
    oot::asset::texture::load(symbol::gRedPotionIconTex),
    oot::asset::texture::load(symbol::gGreenPotionIconTex),
    oot::asset::texture::load(symbol::gBluePotionIconTex),
    oot::asset::texture::load(symbol::gBottledFairyIconTex),
    oot::asset::texture::load(symbol::gFishIconTex),
    oot::asset::texture::load(symbol::gMilkFullIconTex),
    oot::asset::texture::load(symbol::gRutosLetterIconTex),
    oot::asset::texture::load(symbol::gBlueFireIconTex),
    oot::asset::texture::load(symbol::gBugIconTex),
    oot::asset::texture::load(symbol::gBigPoeIconTex),
    oot::asset::texture::load(symbol::gMilkhalfIconTex),
    oot::asset::texture::load(symbol::gPoeIconTex),
    oot::asset::texture::load(symbol::gWeirdEggIconTex),
    oot::asset::texture::load(symbol::gCuccoIconTex),
    oot::asset::texture::load(symbol::gZeldasLetterIconTex),
    oot::asset::texture::load(symbol::gKeatonMaskIconTex),
    oot::asset::texture::load(symbol::gSkullMaskIconTex),
    oot::asset::texture::load(symbol::gSpookyMaskIconTex),
    oot::asset::texture::load(symbol::gBunnyHoodIconTex),
    oot::asset::texture::load(symbol::gGoronMaskIconTex),
    oot::asset::texture::load(symbol::gZoraMaskIconTex),
    oot::asset::texture::load(symbol::gGerudoMaskIconTex),
    oot::asset::texture::load(symbol::gMaskofTruthIconTex),
    oot::asset::texture::load(symbol::gSoldOutIconTex),
    oot::asset::texture::load(symbol::gPocketEggIconTex),
    oot::asset::texture::load(symbol::gPocketCuccoIconTex),
    oot::asset::texture::load(symbol::gCojiroIconTex),
    oot::asset::texture::load(symbol::gOddMushroomIconTex),
    oot::asset::texture::load(symbol::gOddPotionIconTex),
    oot::asset::texture::load(symbol::gPoachersSawIconTex),
    oot::asset::texture::load(symbol::gBrokenBiggoronSwordIconTex),
    oot::asset::texture::load(symbol::gPrescriptionIconTex),
    oot::asset::texture::load(symbol::gEyeBallFrogIconTex),
    oot::asset::texture::load(symbol::gEyeDropsIconTex),
    oot::asset::texture::load(symbol::gClaimCheckIconTex),
    oot::asset::texture::load(symbol::gFairyBowFireIconTex),
    oot::asset::texture::load(symbol::gFairyBowIceIconTex),
    oot::asset::texture::load(symbol::gFairyBowLightIconTex),
    oot::asset::texture::load(symbol::gKokiriSwordIconTex),
    oot::asset::texture::load(symbol::gMasterSwordIconTex),
    oot::asset::texture::load(symbol::gBiggoronSwordIconTex),
    oot::asset::texture::load(symbol::gDekuShieldIconTex),
    oot::asset::texture::load(symbol::gHylianShieldIconTex),
    oot::asset::texture::load(symbol::gMirrorShieldIconTex),
    oot::asset::texture::load(symbol::gKokiriTunicIconTex),
    oot::asset::texture::load(symbol::gGoronTunicIconTex),
    oot::asset::texture::load(symbol::gZoraTunicIconTex),
    oot::asset::texture::load(symbol::gKokiriBootsIconTex),
    oot::asset::texture::load(symbol::gIronBootsIconTex),
    oot::asset::texture::load(symbol::gHoverBootsIconTex),
    oot::asset::texture::load(symbol::gBulletBag30IconTex),
    oot::asset::texture::load(symbol::gBulletBag40IconTex),
    oot::asset::texture::load(symbol::gBulletBag50IconTex),
    oot::asset::texture::load(symbol::gQuiver30IconTex),
    oot::asset::texture::load(symbol::gQuiver40IconTex),
    oot::asset::texture::load(symbol::gQuiver50IconTex),
    oot::asset::texture::load(symbol::gBombBag20IconTex),
    oot::asset::texture::load(symbol::gBombBag30IconTex),
    oot::asset::texture::load(symbol::gBombBag40IconTex),
    oot::asset::texture::load(symbol::gGoronsBraceletIconTex),
    oot::asset::texture::load(symbol::gSilverGauntletsIconTex),
    oot::asset::texture::load(symbol::gGoldenGauntletsIconTex),
    oot::asset::texture::load(symbol::gSilverScaleIconTex),
    oot::asset::texture::load(symbol::gGoldenScaleIconTex),
    oot::asset::texture::load(symbol::gBrokenGiantsKnifeIconTex),
    oot::asset::texture::load(symbol::gAdultsWalletIconTex),
    oot::asset::texture::load(symbol::gGiantsWalletIconTex),
    oot::asset::texture::load(symbol::gDekuSeedsIconTex),
    oot::asset::texture::load(symbol::gFishingPoleIconTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gSongNoteTex),
    oot::asset::texture::load(symbol::gForestMedallionIconTex),
    oot::asset::texture::load(symbol::gFireMedallionIconTex),
    oot::asset::texture::load(symbol::gWaterMedallionIconTex),
    oot::asset::texture::load(symbol::gSpiritMedallionIconTex),
    oot::asset::texture::load(symbol::gShadowMedallionIconTex),
    oot::asset::texture::load(symbol::gLightMedallionIconTex),
    oot::asset::texture::load(symbol::gKokiriEmeraldIconTex),
    oot::asset::texture::load(symbol::gGoronRubyIconTex),
    oot::asset::texture::load(symbol::gZoraSapphireIconTex),
    oot::asset::texture::load(symbol::gStoneOfAgonyIconTex),
    oot::asset::texture::load(symbol::gGerudosCardIconTex),
    oot::asset::texture::load(symbol::gGoldSkulltulaIconTex),
    oot::asset::texture::load(symbol::gHeartContainerIconTex),
    oot::asset::texture::load(symbol::gUnusedPieceOfHeartIconTex),
    oot::asset::texture::load(symbol::gBossKeyIconTex),
    oot::asset::texture::load(symbol::gDungeonMapIconTex),
    oot::asset::texture::load(symbol::gCompassIconTex),
    oot::asset::texture::load(symbol::gBossKeyIconTex),
    oot::asset::texture::load(symbol::gSmallMagicJarIconTex),
    oot::asset::texture::load(symbol::gBigMagicJarIconTex),
    oot::asset::texture::load(symbol::gHeartPieceIcon1Tex),
    oot::asset::texture::load(symbol::gHeartPieceIcon2Tex),
    oot::asset::texture::load(symbol::gHeartPieceIcon3Tex),
    oot::asset::texture::load(symbol::gOcarinaCUpTex),
    oot::asset::texture::load(symbol::gOcarinaCDownTex),
    oot::asset::texture::load(symbol::gOcarinaCLeftTex),
    oot::asset::texture::load(symbol::gOcarinaCRightTex),
    oot::asset::texture::load(symbol::gOcarinaATex),
};

//Copy of all the icons in grayscale version.
//The textures here will be generated on runtime via KaleidoScope_GrayOutTextureRGBA32() in KaleidoScope_SetupGrayIcons()
#ifndef N64_VERSION
void* gItemIconsGray[86][32*32];
void* gItemIconsCurrent[86];
#endif

// Used to map item IDs to inventory slots
u8 gItemSlots[] = {
    SLOT_STICK,       SLOT_NUT,          SLOT_BOMB,        SLOT_BOW,         SLOT_ARROW_FIRE,  SLOT_DINS_FIRE,
    SLOT_SLINGSHOT,   SLOT_OCARINA,      SLOT_OCARINA,     SLOT_BOMBCHU,     SLOT_HOOKSHOT,    SLOT_HOOKSHOT,
    SLOT_ARROW_ICE,   SLOT_FARORES_WIND, SLOT_BOOMERANG,   SLOT_LENS,        SLOT_BEAN,        SLOT_HAMMER,
    SLOT_ARROW_LIGHT, SLOT_NAYRUS_LOVE,  SLOT_BOTTLE_1,    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,
    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,     SLOT_BOTTLE_1,    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,
    SLOT_BOTTLE_1,    SLOT_BOTTLE_1,     SLOT_BOTTLE_1,    SLOT_TRADE_CHILD, SLOT_TRADE_CHILD, SLOT_TRADE_CHILD,
    SLOT_TRADE_CHILD, SLOT_TRADE_CHILD,  SLOT_TRADE_CHILD, SLOT_TRADE_CHILD, SLOT_TRADE_CHILD, SLOT_TRADE_CHILD,
    SLOT_TRADE_CHILD, SLOT_TRADE_CHILD,  SLOT_TRADE_CHILD, SLOT_TRADE_ADULT, SLOT_TRADE_ADULT, SLOT_TRADE_ADULT,
    SLOT_TRADE_ADULT, SLOT_TRADE_ADULT,  SLOT_TRADE_ADULT, SLOT_TRADE_ADULT, SLOT_TRADE_ADULT, SLOT_TRADE_ADULT,
    SLOT_TRADE_ADULT, SLOT_TRADE_ADULT,
};

void Inventory_ChangeEquipment(s16 equipment, u16 value) {
    gSaveContext.equips.equipment &= gEquipNegMasks[equipment];
    gSaveContext.equips.equipment |= value << gEquipShifts[equipment];
}

u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    u16 sp26 = gSaveContext.equips.equipment & gEquipMasks[equipment];

    // "Erasing equipment item = %d  zzz=%d"
    osSyncPrintf("Erasing equipment item = %d  zzz=%d\n", equipment, sp26);

    if (sp26) {
        sp26 >>= gEquipShifts[equipment];

        gSaveContext.equips.equipment &= gEquipNegMasks[equipment];
        gSaveContext.inventory.equipment ^= gBitFlags[sp26 - 1] << gEquipShifts[equipment];

        if (equipment == EQUIP_TUNIC) {
            gSaveContext.equips.equipment |= 0x0100;
        }

        if (equipment == EQUIP_SWORD) {
            gSaveContext.equips.buttonItems[0] = ITEM_NONE;
            gSaveContext.infTable[29] = 1;
        }

        Player_SetEquipmentData(globalCtx, player);
        globalCtx->pauseCtx.cursorSpecialPos = PAUSE_CURSOR_PAGE_LEFT;
    }

    return sp26;
}

void Inventory_ChangeUpgrade(s16 upgrade, s16 value) {
    gSaveContext.inventory.upgrades &= gUpgradeNegMasks[upgrade];
    gSaveContext.inventory.upgrades |= value << gUpgradeShifts[upgrade];
}

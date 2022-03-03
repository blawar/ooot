#define INTERNAL_SRC_CODE_Z_DRAW_C
#include "global.h"
#include "z64global.h"
#include "gfx.h"
#include "asset.h"
#include "def/sys_matrix.h"
#include "def/z_draw.h"
#include "def/z_rcp.h"
#include "def/graph.h" // FORCE

// "Get Item" Model Draw Functions
void GetItem_DrawMaskOrBombchu(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawSoldOut(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawBlueFire(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawPoes(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawFairy(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawMirrorShield(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawSkullToken(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawEggOrMedallion(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawCompass(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawPotion(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawGoronSword(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawDekuNuts(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawRecoveryHeart(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawFish(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawOpa0(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawOpa0Xlu1(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawXlu01(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawOpa10Xlu2(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawMagicArrow(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawMagicSpell(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawOpa1023(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawOpa10Xlu32(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawSmallRupee(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawScale(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawBulletBag(GlobalContext* globalCtx, s16 drawId);
void GetItem_DrawWallet(GlobalContext* globalCtx, s16 drawId);

typedef struct {
    /* 0x00 */ void (*drawFunc)(GlobalContext*, s16);
    /* 0x04 */ Gfx* dlists[8];
} DrawItemTableEntry; // size = 0x24

DrawItemTableEntry sDrawItemTable[] = {
    // bottle, OBJECT_GI_BOTTLE
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiBottleStopperDL), oot::asset::gfx::load(symbol::gGiBottleDL) } },
    // small key, OBJECT_GI_KEY
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSmallKeyDL) } },
    // minuet of forest, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiMinuetColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // bolero of fire, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiBoleroColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // serenade of water, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiSerenadeColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // requiem of spirit, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiRequiemColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // nocturne of shadow, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiNocturneColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // prelude of light, OBJECT_GI_MELODY
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiPreludeColorDL), oot::asset::gfx::load(symbol::gGiSongNoteDL) } },
    // recovery heart, OBJECT_GI_HEART
    { GetItem_DrawRecoveryHeart, { oot::asset::gfx::load(symbol::gGiRecoveryHeartDL) } },
    // boss key, OBJECT_GI_BOSSKEY
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiBossKeyDL), oot::asset::gfx::load(symbol::gGiBossKeyGemDL) } },
    // compass, OBJECT_GI_COMPASS
    { GetItem_DrawCompass, { oot::asset::gfx::load(symbol::gGiCompassDL), oot::asset::gfx::load(symbol::gGiCompassGlassDL) } },
    // forest medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiForestMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // fire medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiFireMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // water medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiWaterMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // spirit medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiSpiritMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // shadow medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiShadowMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // light medallion, OBJECT_GI_MEDAL
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiLightMedallionFaceDL), oot::asset::gfx::load(symbol::gGiMedallionDL) } },
    // deku nuts, OBJECT_GI_NUTS
    { GetItem_DrawDekuNuts, { oot::asset::gfx::load(symbol::gGiNutDL) } },
    // heart container, OBJECT_GI_HEARTS
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiHeartBorderDL), oot::asset::gfx::load(symbol::gGiHeartContainerDL) } },
    // heart piece, OBJECT_GI_HEARTS
    { GetItem_DrawXlu01, { oot::asset::gfx::load(symbol::gGiHeartBorderDL), oot::asset::gfx::load(symbol::gGiHeartPieceDL) } },
    // quiver 30, OBJECT_GI_ARROWCASE
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiQuiverInnerDL), oot::asset::gfx::load(symbol::gGiQuiver30InnerColorDL), oot::asset::gfx::load(symbol::gGiQuiver30OuterColorDL), oot::asset::gfx::load(symbol::gGiQuiverOuterDL) } },
    // quiver 40, OBJECT_GI_ARROWCASE
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiQuiverInnerDL), oot::asset::gfx::load(symbol::gGiQuiver40InnerColorDL), oot::asset::gfx::load(symbol::gGiQuiver40OuterColorDL), oot::asset::gfx::load(symbol::gGiQuiverOuterDL) } },
    // quiver 50, OBJECT_GI_ARROWCASE
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiQuiverInnerDL), oot::asset::gfx::load(symbol::gGiQuiver50InnerColorDL), oot::asset::gfx::load(symbol::gGiQuiver50OuterColorDL), oot::asset::gfx::load(symbol::gGiQuiverOuterDL) } },
    // bomb bag 20, OBJECT_GI_BOMBPOUCH
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiBombBagDL), oot::asset::gfx::load(symbol::gGiBombBag20BagColorDL), oot::asset::gfx::load(symbol::gGiBombBag20RingColorDL), oot::asset::gfx::load(symbol::gGiBombBagRingDL) } },
    // bomb bag 30, OBJECT_GI_BOMBPOUCH
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiBombBagDL), oot::asset::gfx::load(symbol::gGiBombBag30BagColorDL), oot::asset::gfx::load(symbol::gGiBombBag30RingColorDL), oot::asset::gfx::load(symbol::gGiBombBagRingDL) } },
    // bomb bag 40, OBJECT_GI_BOMBPOUCH
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiBombBagDL), oot::asset::gfx::load(symbol::gGiBombBag40BagColorDL), oot::asset::gfx::load(symbol::gGiBombBag40RingColorDL), oot::asset::gfx::load(symbol::gGiBombBagRingDL) } },
    // stick, OBJECT_GI_STICK
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiStickDL) } },
    // dungeon map, OBJECT_GI_MAP
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiDungeonMapDL) } },
    // deku shield, OBJECT_GI_SHIELD_1
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiDekuShieldDL) } },
    // small magic jar, OBJECT_GI_MAGICPOT
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiMagicJarSmallDL) } },
    // large magic jar, OBJECT_GI_MAGICPOT
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiMagicJarLargeDL) } },
    // bombs, OBJECT_GI_BOMB_1
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiBombDL) } },
    // stone of agony, OBJECT_GI_MAP
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiStoneOfAgonyDL) } },
    // adult's wallet, OBJECT_GI_PURSE
    { GetItem_DrawWallet,
      { oot::asset::gfx::load(symbol::gGiWalletDL), oot::asset::gfx::load(symbol::gGiAdultWalletColorDL), oot::asset::gfx::load(symbol::gGiAdultWalletRupeeOuterColorDL), oot::asset::gfx::load(symbol::gGiWalletRupeeOuterDL),
        oot::asset::gfx::load(symbol::gGiAdultWalletStringColorDL), oot::asset::gfx::load(symbol::gGiWalletStringDL), oot::asset::gfx::load(symbol::gGiAdultWalletRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiWalletRupeeInnerDL) } },
    // giant's wallet, OBJECT_GI_PURSE
    { GetItem_DrawWallet,
      { oot::asset::gfx::load(symbol::gGiWalletDL), oot::asset::gfx::load(symbol::gGiGiantsWalletColorDL), oot::asset::gfx::load(symbol::gGiGiantsWalletRupeeOuterColorDL), oot::asset::gfx::load(symbol::gGiWalletRupeeOuterDL),
        oot::asset::gfx::load(symbol::gGiGiantsWalletStringColorDL), oot::asset::gfx::load(symbol::gGiWalletStringDL), oot::asset::gfx::load(symbol::gGiGiantsWalletRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiWalletRupeeInnerDL) } },
    // gerudo card, OBJECT_GI_GERUDO
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiGerudoCardDL) } },
    // arrows (small), OBJECT_GI_ARROW
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiArrowSmallDL) } },
    // arrows (medium), OBJECT_GI_ARROW
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiArrowMediumDL) } },
    // arrows (large), OBJECT_GI_ARROW
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiArrowLargeDL) } },
    // bombchus, OBJECT_GI_BOMB_2
    { GetItem_DrawMaskOrBombchu, { oot::asset::gfx::load(symbol::gGiBombchuDL) } },
    // egg, OBJECT_GI_EGG
    { GetItem_DrawEggOrMedallion, { oot::asset::gfx::load(symbol::gGiEggMaterialDL), oot::asset::gfx::load(symbol::gGiEggDL) } },
    // silver scale, OBJECT_GI_SCALE
    { GetItem_DrawScale, { oot::asset::gfx::load(symbol::gGiScaleWaterDL), oot::asset::gfx::load(symbol::gGiSilverScaleWaterColorDL), oot::asset::gfx::load(symbol::gGiSilverScaleColorDL), oot::asset::gfx::load(symbol::gGiScaleDL) } },
    // gold scale, OBJECT_GI_SCALE
    { GetItem_DrawScale, { oot::asset::gfx::load(symbol::gGiScaleWaterDL), oot::asset::gfx::load(symbol::gGiGoldenScaleWaterColorDL), oot::asset::gfx::load(symbol::gGiGoldenScaleColorDL), oot::asset::gfx::load(symbol::gGiScaleDL) } },
    // hylian shield, OBJECT_GI_SHIELD_2
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiHylianShieldDL) } },
    // hookshot, OBJECT_GI_HOOKSHOT
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiHookshotDL) } },
    // longshot, OBJECT_GI_HOOKSHOT
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiLongshotDL) } },
    // ocarina of time, OBJECT_GI_OCARINA
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiOcarinaTimeDL), oot::asset::gfx::load(symbol::gGiOcarinaTimeHolesDL) } },
    // milk, OBJECT_GI_MILK
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiMilkBottleContentsDL), oot::asset::gfx::load(symbol::gGiMilkBottleDL) } },
    // keaton mask, OBJECT_GI_KI_TAN_MASK
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiKeatonMaskDL), oot::asset::gfx::load(symbol::gGiKeatonMaskEyesDL) } },
    // spooky mask, OBJECT_GI_REDEAD_MASK
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSpookyMaskDL) } },
    // slingshot, OBJECT_GI_PACHINKO
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSlingshotDL) } },
    // boomerang, OBJECT_GI_BOOMERANG
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiBoomerangDL) } },
    // bow, OBJECT_GI_BOW
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiBowDL) } },
    // lens, OBJECT_GI_GLASSES
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiLensDL), oot::asset::gfx::load(symbol::gGiLensGlassDL) } },
    // green potion, OBJECT_GI_LIQUID
    { GetItem_DrawPotion,
      { oot::asset::gfx::load(symbol::gGiPotionPotDL), oot::asset::gfx::load(symbol::gGiGreenPotColorDL), oot::asset::gfx::load(symbol::gGiGreenLiquidColorDL), oot::asset::gfx::load(symbol::gGiPotionLiquidDL), oot::asset::gfx::load(symbol::gGiGreenPatternColorDL),
        oot::asset::gfx::load(symbol::gGiPotionPatternDL) } },
    // red potion, OBJECT_GI_LIQUID
    { GetItem_DrawPotion,
      { oot::asset::gfx::load(symbol::gGiPotionPotDL), oot::asset::gfx::load(symbol::gGiRedPotColorDL), oot::asset::gfx::load(symbol::gGiRedLiquidColorDL), oot::asset::gfx::load(symbol::gGiPotionLiquidDL), oot::asset::gfx::load(symbol::gGiRedPatternColorDL),
        oot::asset::gfx::load(symbol::gGiPotionPatternDL) } },
    // blue potion, OBJECT_GI_LIQUID
    { GetItem_DrawPotion,
      { oot::asset::gfx::load(symbol::gGiPotionPotDL), oot::asset::gfx::load(symbol::gGiBluePotColorDL), oot::asset::gfx::load(symbol::gGiBlueLiquidColorDL), oot::asset::gfx::load(symbol::gGiPotionLiquidDL), oot::asset::gfx::load(symbol::gGiBluePatternColorDL),
        oot::asset::gfx::load(symbol::gGiPotionPatternDL) } },
    // mirror shield, OBJECT_GI_SHIELD_3
    { GetItem_DrawMirrorShield, { oot::asset::gfx::load(symbol::gGiMirrorShieldDL), oot::asset::gfx::load(symbol::gGiMirrorShieldSymbolDL) } },
    // zelda's letter, OBJECT_GI_LETTER
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiLetterDL), oot::asset::gfx::load(symbol::gGiLetterWritingDL) } },
    // goron tunic, OBJECT_GI_CLOTHES
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiTunicCollarDL), oot::asset::gfx::load(symbol::gGiGoronCollarColorDL), oot::asset::gfx::load(symbol::gGiGoronTunicColorDL), oot::asset::gfx::load(symbol::gGiTunicDL) } },
    // zora tunic, OBJECT_GI_CLOTHES
    { GetItem_DrawOpa1023, { oot::asset::gfx::load(symbol::gGiTunicCollarDL), oot::asset::gfx::load(symbol::gGiZoraCollarColorDL), oot::asset::gfx::load(symbol::gGiZoraTunicColorDL), oot::asset::gfx::load(symbol::gGiTunicDL) } },
    // beans, OBJECT_GI_BEAN
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiBeanDL) } },
    // fish, OBJECT_GI_FISH
    { GetItem_DrawFish, { oot::asset::gfx::load(symbol::gGiFishDL) } },
    // saw, OBJECT_GI_SAW
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSawDL) } },
    // hammer, OBJECT_GI_HAMMER
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiHammerDL) } },
    // grass, OBJECT_GI_GRASS
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiGrassDL) } },
    // biggorons sword, OBJECT_GI_LONGSWORD
    { GetItem_DrawGoronSword, { oot::asset::gfx::load(symbol::gGiBiggoronSwordDL) } },
    // chicken, OBJECT_GI_NIWATORI
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiChickenDL), oot::asset::gfx::load(symbol::gGiChickenColorDL), oot::asset::gfx::load(symbol::gGiChickenEyesDL) } },
    // ruto's letter, OBJECT_GI_BOTTLE_LETTER
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiLetterBottleContentsDL), oot::asset::gfx::load(symbol::gGiLetterBottleDL) } },
    // fairy ocarina, OBJECT_GI_OCARINA_0
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiOcarinaFairyDL), oot::asset::gfx::load(symbol::gGiOcarinaFairyHolesDL) } },
    // iron boots, OBJECT_GI_BOOTS_2
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiIronBootsDL), oot::asset::gfx::load(symbol::gGiIronBootsRivetsDL) } },
    // seeds, OBJECT_GI_SEED
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSeedDL) } },
    // silver gauntlets, OBJECT_GI_GLOVES
    { GetItem_DrawOpa10Xlu32,
      { oot::asset::gfx::load(symbol::gGiGauntletsDL), oot::asset::gfx::load(symbol::gGiSilverGauntletsColorDL), oot::asset::gfx::load(symbol::gGiGauntletsPlateDL), oot::asset::gfx::load(symbol::gGiSilverGauntletsPlateColorDL) } },
    // golden gauntlets, OBJECT_GI_GLOVES
    { GetItem_DrawOpa10Xlu32,
      { oot::asset::gfx::load(symbol::gGiGauntletsDL), oot::asset::gfx::load(symbol::gGiGoldenGauntletsColorDL), oot::asset::gfx::load(symbol::gGiGauntletsPlateDL), oot::asset::gfx::load(symbol::gGiGoldenGauntletsPlateColorDL) } },
    // yellow n coin, OBJECT_GI_COIN
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiCoinDL), oot::asset::gfx::load(symbol::gGiYellowCoinColorDL), oot::asset::gfx::load(symbol::gGiNDL) } },
    // red n coin, OBJECT_GI_COIN
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiCoinDL), oot::asset::gfx::load(symbol::gGiRedCoinColorDL), oot::asset::gfx::load(symbol::gGiNDL) } },
    // green n coin, OBJECT_GI_COIN
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiCoinDL), oot::asset::gfx::load(symbol::gGiGreenCoinColorDL), oot::asset::gfx::load(symbol::gGiNDL) } },
    // blue n coin, OBJECT_GI_COIN
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiCoinDL), oot::asset::gfx::load(symbol::gGiBlueCoinColorDL), oot::asset::gfx::load(symbol::gGiNDL) } },
    // skull mask, OBJECT_GI_SKJ_MASK
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiSkullMaskDL) } },
    // bunny hood OBJECT_GI_RABIT_MASK
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiBunnyHoodDL), oot::asset::gfx::load(symbol::gGiBunnyHoodEyesDL) } },
    // mask of truth, OBJECT_GI_TRUTH_MASK
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiMaskOfTruthDL), oot::asset::gfx::load(symbol::gGiMaskOfTruthAccentsDL) } },
    // eyedrops, OBJECT_GI_EYE_LOTION
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiEyeDropsCapDL), oot::asset::gfx::load(symbol::gGiEyeDropsBottleDL) } },
    // odd potion, OBJECT_GI_POWDER
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiOddPotionDL) } },
    // odd mushroom, OBJECT_GI_MUSHROOM
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiOddMushroomDL) } },
    // claim check, OBJECT_GI_TICKETSTONE
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiClaimCheckDL), oot::asset::gfx::load(symbol::gGiClaimCheckWritingDL) } },
    // broken goron's sword, OBJECT_GI_BROKENSWORD
    { GetItem_DrawGoronSword, { oot::asset::gfx::load(symbol::gGiBrokenGoronSwordDL) } },
    // prescription, OBJECT_GI_PRESCRIPTION
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiPrescriptionDL), oot::asset::gfx::load(symbol::gGiPrescriptionWritingDL) } },
    // goron bracelet, OBJECT_GI_BRACELET
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiGoronBraceletDL) } },
    // sold out, OBJECT_GI_SOLDOUT
    { GetItem_DrawSoldOut, { oot::asset::gfx::load(symbol::gGiSoldOutDL) } },
    // frog, OBJECT_GI_FROG
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiFrogDL), oot::asset::gfx::load(symbol::gGiFrogEyesDL) } },
    // goron mask, OBJECT_GI_GOLONMASK
    { GetItem_DrawMaskOrBombchu, { oot::asset::gfx::load(symbol::gGiGoronMaskDL) } },
    // zora mask, OBJECT_GI_ZORAMASK
    { GetItem_DrawMaskOrBombchu, { oot::asset::gfx::load(symbol::gGiZoraMaskDL) } },
    // gerudo mask, OBJECT_GI_GERUDOMASK
    { GetItem_DrawMaskOrBombchu, { oot::asset::gfx::load(symbol::gGiGerudoMaskDL) } },
    // cojiro, OBJECT_GI_NIWATORI
    { GetItem_DrawOpa10Xlu2, { oot::asset::gfx::load(symbol::gGiChickenDL), oot::asset::gfx::load(symbol::gGiCojiroColorDL), oot::asset::gfx::load(symbol::gGiChickenEyesDL) } },
    // hover boots, OBJECT_GI_HOVERBOOTS
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiHoverBootsDL) } },
    // fire arrows, OBJECT_GI_M_ARROW
    { GetItem_DrawMagicArrow, { oot::asset::gfx::load(symbol::gGiMagicArrowDL), oot::asset::gfx::load(symbol::gGiFireArrowColorDL), oot::asset::gfx::load(symbol::gGiArrowMagicDL) } },
    // ice arrows, OBJECT_GI_M_ARROW
    { GetItem_DrawMagicArrow, { oot::asset::gfx::load(symbol::gGiMagicArrowDL), oot::asset::gfx::load(symbol::gGiIceArrowColorDL), oot::asset::gfx::load(symbol::gGiArrowMagicDL) } },
    // light arrows, OBJECT_GI_M_ARROW
    { GetItem_DrawMagicArrow, { oot::asset::gfx::load(symbol::gGiMagicArrowDL), oot::asset::gfx::load(symbol::gGiLightArrowColorDL), oot::asset::gfx::load(symbol::gGiArrowMagicDL) } },
    // skulltula token, OBJECT_GI_SUTARU
    { GetItem_DrawSkullToken, { oot::asset::gfx::load(symbol::gGiSkulltulaTokenDL), oot::asset::gfx::load(symbol::gGiSkulltulaTokenFlameDL) } },
    // din's fire, OBJECT_GI_GODDESS
    { GetItem_DrawMagicSpell, { oot::asset::gfx::load(symbol::gGiMagicSpellDiamondDL), oot::asset::gfx::load(symbol::gGiDinsFireColorDL), oot::asset::gfx::load(symbol::gGiMagicSpellOrbDL) } },
    // farore's wind, OBJECT_GI_GODDESS
    { GetItem_DrawMagicSpell, { oot::asset::gfx::load(symbol::gGiMagicSpellDiamondDL), oot::asset::gfx::load(symbol::gGiFaroresWindColorDL), oot::asset::gfx::load(symbol::gGiMagicSpellOrbDL) } },
    // nayru's Love, OBJECT_GI_GODDESS
    { GetItem_DrawMagicSpell, { oot::asset::gfx::load(symbol::gGiMagicSpellDiamondDL), oot::asset::gfx::load(symbol::gGiNayrusLoveColorDL), oot::asset::gfx::load(symbol::gGiMagicSpellOrbDL) } },
    // blue fire, OBJECT_GI_FIRE
    { GetItem_DrawBlueFire, { oot::asset::gfx::load(symbol::gGiBlueFireChamberstickDL), oot::asset::gfx::load(symbol::gGiBlueFireFlameDL) } },
    // bugs, OBJECT_GI_INSECT
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiBugsContainerDL), oot::asset::gfx::load(symbol::gGiBugsGlassDL) } },
    // butterfly, OBJECT_GI_BUTTERFLY
    { GetItem_DrawOpa0Xlu1, { oot::asset::gfx::load(symbol::gGiButterflyContainerDL), oot::asset::gfx::load(symbol::gGiButterflyGlassDL) } },
    // poe, OBJECT_GI_GHOST
    { GetItem_DrawPoes,
      { oot::asset::gfx::load(symbol::gGiGhostContainerLidDL), oot::asset::gfx::load(symbol::gGiGhostContainerGlassDL), oot::asset::gfx::load(symbol::gGiGhostContainerContentsDL), oot::asset::gfx::load(symbol::gGiPoeColorDL) } },
    // fairy, OBJECT_GI_SOUL
    { GetItem_DrawFairy, { oot::asset::gfx::load(symbol::gGiFairyContainerBaseCapDL), oot::asset::gfx::load(symbol::gGiFairyContainerGlassDL), oot::asset::gfx::load(symbol::gGiFairyContainerContentsDL) } },
    // bullet bag 40, OBJECT_GI_DEKUPOUCH
    { GetItem_DrawBulletBag,
      { oot::asset::gfx::load(symbol::gGiBulletBagDL), oot::asset::gfx::load(symbol::gGiBulletBagColorDL), oot::asset::gfx::load(symbol::gGiBulletBagStringDL), oot::asset::gfx::load(symbol::gGiBulletBagStringColorDL), oot::asset::gfx::load(symbol::gGiBulletBagWritingDL) } },
    // green rupee, OBJECT_GI_RUPY
    { GetItem_DrawSmallRupee,
      { oot::asset::gfx::load(symbol::gGiRupeeInnerDL), oot::asset::gfx::load(symbol::gGiGreenRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiRupeeOuterDL), oot::asset::gfx::load(symbol::gGiGreenRupeeOuterColorDL) } },
    // blue rupee, OBJECT_GI_RUPY
    { GetItem_DrawSmallRupee,
      { oot::asset::gfx::load(symbol::gGiRupeeInnerDL), oot::asset::gfx::load(symbol::gGiBlueRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiRupeeOuterDL), oot::asset::gfx::load(symbol::gGiBlueRupeeOuterColorDL) } },
    // red rupee, OBJECT_GI_RUPY
    { GetItem_DrawSmallRupee, { oot::asset::gfx::load(symbol::gGiRupeeInnerDL), oot::asset::gfx::load(symbol::gGiRedRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiRupeeOuterDL), oot::asset::gfx::load(symbol::gGiRedRupeeOuterColorDL) } },
    // big poe, OBJECT_GI_GHOST
    { GetItem_DrawPoes,
      { oot::asset::gfx::load(symbol::gGiGhostContainerLidDL), oot::asset::gfx::load(symbol::gGiGhostContainerGlassDL), oot::asset::gfx::load(symbol::gGiGhostContainerContentsDL), oot::asset::gfx::load(symbol::gGiBigPoeColorDL) } },
    // purple rupee, OBJECT_GI_RUPY
    { GetItem_DrawOpa10Xlu32,
      { oot::asset::gfx::load(symbol::gGiRupeeInnerDL), oot::asset::gfx::load(symbol::gGiPurpleRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiRupeeOuterDL), oot::asset::gfx::load(symbol::gGiPurpleRupeeOuterColorDL) } },
    // gold rupee, OBJECT_GI_RUPY
    { GetItem_DrawOpa10Xlu32,
      { oot::asset::gfx::load(symbol::gGiRupeeInnerDL), oot::asset::gfx::load(symbol::gGiGoldRupeeInnerColorDL), oot::asset::gfx::load(symbol::gGiRupeeOuterDL), oot::asset::gfx::load(symbol::gGiGoldRupeeOuterColorDL) } },
    // bullet bag 50, OBJECT_GI_DEKUPOUCH
    { GetItem_DrawBulletBag,
      { oot::asset::gfx::load(symbol::gGiBulletBagDL), oot::asset::gfx::load(symbol::gGiBulletBag50ColorDL), oot::asset::gfx::load(symbol::gGiBulletBagStringDL), oot::asset::gfx::load(symbol::gGiBulletBag50StringColorDL),
        oot::asset::gfx::load(symbol::gGiBulletBagWritingDL) } },
    // kokiri sword, OBJECT_GI_SWORD_1
    { GetItem_DrawOpa0, { oot::asset::gfx::load(symbol::gGiKokiriSwordDL) } },
    // gold skulltula token, OBJECT_ST
    { GetItem_DrawSkullToken, { oot::asset::gfx::load(symbol::object_st_DL_004DB0), oot::asset::gfx::load(symbol::object_st_DL_004EB8) } },
};

/**
 * Draw "Get Item" Model
 * Calls the corresponding draw function for the given draw ID
 */
void GetItem_Draw(GlobalContext* globalCtx, s16 drawId) {
    sDrawItemTable[drawId].drawFunc(globalCtx, drawId);
}

// All remaining functions in this file are draw functions referenced in the table and called by the function above

void GetItem_DrawMaskOrBombchu(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 556);

    func_80093BA8(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 560),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 565);
}

void GetItem_DrawSoldOut(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 572);

    POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 5);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 576),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 581);
}

void GetItem_DrawBlueFire(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 588);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 592),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 0).whole(),
                                0 * (globalCtx->state.frames * 0).whole(), 16, 32, 1, 1 * (globalCtx->state.frames * 1).whole(),
                                1 * -(globalCtx->state.frames * 8).whole(), 16, 32));
    Matrix_Push();
    Matrix_Translate(-8.0f, -2.0f, 0.0f, MTXMODE_APPLY);
    func_800D1FD4(&globalCtx->billboardMtxF);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 615),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 621);
}

void GetItem_DrawPoes(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 628);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 632),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 641),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 0).whole(),
                                0 * (globalCtx->state.frames * 0).whole(), 16, 32, 1, 1 * (globalCtx->state.frames * 1).whole(),
                                1 * -(globalCtx->state.frames * 6).whole(), 16, 32));
    Matrix_Push();
    func_800D1FD4(&globalCtx->billboardMtxF);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 656),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 663);
}

void GetItem_DrawFairy(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 670);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 674),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 683),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 0).whole(),
                                0 * (globalCtx->state.frames * 0).whole(), 32, 32, 1, 1 * (globalCtx->state.frames * 1).whole(),
                                1 * -(globalCtx->state.frames * 6).whole(), 32, 32));
    Matrix_Push();
    func_800D1FD4(&globalCtx->billboardMtxF);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 698),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 704);
}

void GetItem_DrawMirrorShield(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 712);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->state.frames * 0) % 256,
                                (globalCtx->state.frames * 2) % 256, 64, 64, 1,
                                (globalCtx->state.frames * 0) % 128, (globalCtx->state.frames * 1) % 128, 32,
                                32));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 723),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 730),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 735);
}

void GetItem_DrawSkullToken(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 742);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 746),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 0).whole(),
                                1 * -(globalCtx->state.frames * 5).whole(), 32, 32, 1, 0 * (globalCtx->state.frames * 0).whole(),
                                0 * (globalCtx->state.frames * 0).whole(), 32, 64));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 760),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 765);
}

void GetItem_DrawEggOrMedallion(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 772);

    func_80093BA8(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 776),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 783);
}

void GetItem_DrawCompass(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 811);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 815),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 5);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 822),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 827);
}

void GetItem_DrawPotion(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 834);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, -1 * (globalCtx->state.frames * 1).whole(),
                                1 * (globalCtx->state.frames * 1).whole(), 32, 32, 1, -1 * (globalCtx->state.frames * 1).whole(),
                                1 * (globalCtx->state.frames * 1).whole(), 32, 32));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 845),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[2]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[3]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 855),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[4]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[5]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 861);
}

void GetItem_DrawGoronSword(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 868);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 1 * (globalCtx->state.frames * 1).whole(),
                                0 * (globalCtx->state.frames * 1).whole(), 32, 32, 1, 0 * (globalCtx->state.frames * 1).whole(),
                                0 * (globalCtx->state.frames * 1).whole(), 32, 32));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 878),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 883);
}

void GetItem_DrawDekuNuts(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 890);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 1 * (globalCtx->state.frames * 6).whole(),
                                1 * (globalCtx->state.frames * 6).whole(), 32, 32, 1, 1 * (globalCtx->state.frames * 6).whole(),
                                1 * (globalCtx->state.frames * 6).whole(), 32, 32));
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 901),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 906);
}

void GetItem_DrawRecoveryHeart(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 913);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 1).whole(),
                                1 * -(globalCtx->state.frames * 3).whole(), 32, 32, 1, 0 * (globalCtx->state.frames * 1).whole(),
                                1 * -(globalCtx->state.frames * 2).whole(), 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 924),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 929);
}

void GetItem_DrawFish(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 936);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0 * (globalCtx->state.frames * 0).whole(),
                                1 * (globalCtx->state.frames * 1).whole(), 32, 32, 1, 0 * (globalCtx->state.frames * 0).whole(),
                                1 * (globalCtx->state.frames * 1).whole(), 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 947),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 952);
}

void GetItem_DrawOpa0(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 959);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 963),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 968);
}

void GetItem_DrawOpa0Xlu1(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 975);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 979),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 986),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 991);
}

void GetItem_DrawXlu01(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 998);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1002),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1008);
}

void GetItem_DrawOpa10Xlu2(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1015);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1019),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1027),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1032);
}

void GetItem_DrawMagicArrow(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1039);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1043),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1050),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1056);
}

void GetItem_DrawMagicSpell(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1063);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 1 * (globalCtx->state.frames * 2).whole(),
                                1 * -(globalCtx->state.frames * 6).whole(), 32, 32, 1, 1 * (globalCtx->state.frames * 1).whole(),
                                -1 * (globalCtx->state.frames * 2).whole(), 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1074),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1081);
}

void GetItem_DrawOpa1023(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1088);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1092),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[2]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[3]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1100);
}

void GetItem_DrawOpa10Xlu32(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1108);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1112),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1120),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1126);
}

void GetItem_DrawSmallRupee(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1133);

    Matrix_Scale(0.7f, 0.7f, 0.7f, MTXMODE_APPLY);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1140),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1148),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1154);
}

void GetItem_DrawScale(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1162);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 1 * (globalCtx->state.frames * 2).whole(),
                                (globalCtx->state.frames * -2).whole(), 64, 64, 1, 1 * (globalCtx->state.frames * 4).whole(),
                                (globalCtx->state.frames * -4).whole(), 32, 32));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1173),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[0]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1181);
}

void GetItem_DrawBulletBag(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1188);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1192),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1200),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[2]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].dlists[4]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1207);
}

void GetItem_DrawWallet(GlobalContext* globalCtx, s16 drawId) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1214);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_draw.c", 1218),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[0]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[2]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[3]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[4]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[5]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[6]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].dlists[7]);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_draw.c", 1230);
}

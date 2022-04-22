#pragma once
#define Z_EN_GIRLA_H

#include "ultra64.h"
#include "global.h"

struct EnGirlA;

typedef void (*EnGirlAActionFunc)(struct EnGirlA*, GlobalContext*);
typedef void (*EnGirlA2Func)(GlobalContext*, struct EnGirlA*);
typedef void (*EnGirlA3Func)(Actor*, GlobalContext*, s32);
typedef s32 (*EnGirlA4Func)(GlobalContext*, struct EnGirlA*);



struct ShopItemEntry {
    /* 0x00 */ s16 objID;
    /* 0x02 */ s16 giDrawId;
    /* 0x04 */ void (*hiliteFunc)(Actor*, GlobalContext*, s32);
    /* 0x08 */ s16 price;
    /* 0x0A */ s16 count;
    /* 0x0C */ u16 itemDescTextId;
    /* 0x0C */ u16 itemBuyPromptTextId;
    /* 0x10 */ s32 getItemId;
    /* 0x14 */ s32 (*canBuyFunc)(GlobalContext*, EnGirlA*);
    /* 0x18 */ void (*itemGiveFunc)(GlobalContext*, EnGirlA*);
    /* 0x1C */ void (*buyEventFunc)(GlobalContext*, EnGirlA*);
};
struct EnGirlA {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnGirlAActionFunc actionFunc;
    /* 0x0194 */ s32 objBankIndex;
    /* 0x0198 */ EnGirlAActionFunc actionFunc2;
    /* 0x019C */ s32 isInitialized;
    /* 0x01A0 */ s16 itemBuyPromptTextId;
    /* 0x01A4 */ s32 getItemId;
    /* 0x01A8 */ s16 isInvisible;
    /* 0x01AC */ EnGirlA2Func setOutOfStockFunc;
    /* 0x01B0 */ EnGirlA2Func updateStockedItemFunc;
    /* 0x01B4 */ s16 isSelected;
    /* 0x01B6 */ s16 yRotationInit;
    /* 0x01B8 */ s16 yRotation;
    /* 0x01BC */ EnGirlA4Func canBuyFunc;
    /* 0x01C0 */ EnGirlA2Func itemGiveFunc;
    /* 0x01C4 */ EnGirlA2Func buyEventFunc;
    /* 0x01C8 */ s16 basePrice;
    /* 0x01CA */ s16 itemCount;
    /* 0x01CC */ s16 giDrawId;
    /* 0x01D0 */ EnGirlA3Func hiliteFunc;
}; 

enum EnGirlAShopItem {
    /* 0x00 */ SI_DEKU_NUTS_5,
    /* 0x01 */ SI_ARROWS_30,
    /* 0x02 */ SI_ARROWS_50,
    /* 0x03 */ SI_BOMBS_5_R25,
    /* 0x04 */ SI_DEKU_NUTS_10,
    /* 0x05 */ SI_DEKU_STICK,
    /* 0x06 */ SI_BOMBS_10,
    /* 0x07 */ SI_FISH,
    /* 0x08 */ SI_RED_POTION_R30,
    /* 0x09 */ SI_GREEN_POTION,
    /* 0x0A */ SI_BLUE_POTION,
    /* 0x0B */ SI_LONGSWORD,
    /* 0x0C */ SI_HYLIAN_SHIELD,
    /* 0x0D */ SI_DEKU_SHIELD,
    /* 0x0E */ SI_GORON_TUNIC,
    /* 0x0F */ SI_ZORA_TUNIC,
    /* 0x10 */ SI_HEART,
    /* 0x11 */ SI_MILK_BOTTLE,
    /* 0x12 */ SI_WEIRD_EGG,
    /* 0x13 */ SI_19,
    /* 0x14 */ SI_20,
    /* 0x15 */ SI_BOMBCHU_10_1,
    /* 0x16 */ SI_BOMBCHU_20_1,
    /* 0x17 */ SI_BOMBCHU_20_2,
    /* 0x18 */ SI_BOMBCHU_10_2,
    /* 0x19 */ SI_BOMBCHU_10_3,
    /* 0x1A */ SI_BOMBCHU_20_3,
    /* 0x1B */ SI_BOMBCHU_20_4,
    /* 0x1C */ SI_BOMBCHU_10_4,
    /* 0x1D */ SI_DEKU_SEEDS_30,
    /* 0x1E */ SI_KEATON_MASK,
    /* 0x1F */ SI_SPOOKY_MASK,
    /* 0x20 */ SI_SKULL_MASK,
    /* 0x21 */ SI_BUNNY_HOOD,
    /* 0x22 */ SI_MASK_OF_TRUTH,
    /* 0x23 */ SI_ZORA_MASK,
    /* 0x24 */ SI_GORON_MASK,
    /* 0x25 */ SI_GERUDO_MASK,
    /* 0x26 */ SI_SOLD_OUT,
    /* 0x27 */ SI_BLUE_FIRE,
    /* 0x28 */ SI_BUGS,
    /* 0x29 */ SI_BIG_POE,
    /* 0x2A */ SI_POE,
    /* 0x2B */ SI_FAIRY,
    /* 0x2C */ SI_ARROWS_10,
    /* 0x2D */ SI_BOMBS_20,
    /* 0x2E */ SI_BOMBS_30,
    /* 0x2F */ SI_BOMBS_5_R35,
    /* 0x30 */ SI_RED_POTION_R40,
    /* 0x31 */ SI_RED_POTION_R50,
    /* 0x32 */ SI_MAX
};

enum EnGirlACanBuyResult {
    /* 0 */ CANBUY_RESULT_SUCCESS_FANFARE,
    /* 1 */ CANBUY_RESULT_SUCCESS,
    /* 2 */ CANBUY_RESULT_CANT_GET_NOW,
    /* 3 */ CANBUY_RESULT_NEED_BOTTLE,
    /* 4 */ CANBUY_RESULT_NEED_RUPEES,
    /* 5 */ CANBUY_RESULT_CANT_GET_NOW_5
};



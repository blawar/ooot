#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_OSSAN_Z_EN_OSSAN_C
#include "actor_common.h"
#include "z_en_ossan.h"
#include "vt.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_ossan/object_ossan.h"
#include "objects/object_oF1d_map/object_oF1d_map.h"
#include "objects/object_os/object_os.h"
#include "objects/object_zo/object_zo.h"
#include "objects/object_rs/object_rs.h"
#include "objects/object_ds2/object_ds2.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "objects/object_masterkokiri/object_masterkokiri.h"
#include "objects/object_km1/object_km1.h"
#include "objects/object_mastergolon/object_mastergolon.h"
#include "objects/object_masterzoora/object_masterzoora.h"
#include "objects/object_masterkokirihead/object_masterkokirihead.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnOssan_Init(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnOssan_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_Update(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawKokiriShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawPotionShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawBombchuShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawBazaarShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawZoraShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawGoronShopkeeper(Actor* thisx, GlobalContext* globalCtx);
void EnOssan_DrawHappyMaskShopkeeper(Actor* thisx, GlobalContext* globalCtx);

void EnOssan_InitActionFunc(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_MainActionFunc(EnOssan* pthis, GlobalContext* globalCtx);

void EnOssan_TalkDefaultShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkKokiriShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkKakarikoPotionShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkBombchuShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkMarketPotionShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkBazaarShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkZoraShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkGoronShopkeeper(GlobalContext* globalCtx);
void EnOssan_TalkHappyMaskShopkeeper(GlobalContext* globalCtx);

s16 ShopItemDisp_Default(s16 v);
s16 ShopItemDisp_SpookyMask(s16 v);
s16 ShopItemDisp_SkullMask(s16 v);
s16 ShopItemDisp_BunnyHood(s16 v);
s16 ShopItemDisp_ZoraMask(s16 v);
s16 ShopItemDisp_GoronMask(s16 v);
s16 ShopItemDisp_GerudoMask(s16 v);

void EnOssan_InitKokiriShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitPotionShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitBombchuShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitBazaarShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitZoraShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitGoronShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);
void EnOssan_InitHappyMaskShopkeeper(EnOssan* pthis, GlobalContext* globalCtx);

void EnOssan_State_Idle(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_StartConversation(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_FacingShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_TalkingToShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_LookToLeftShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_LookToRightShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_BrowseLeftShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_BrowseRightShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_LookFromShelfToShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_ItemSelected(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_SelectMilkBottle(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_SelectWeirdEgg(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_SelectUnimplementedItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_SelectBombs(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_CantGetItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_GiveItemWithFanfare(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_ItemPurchased(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_ContinueShoppingPrompt(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_GiveLonLonMilk(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_DisplayOnlyBombDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_WaitForDisplayOnlyBombDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_21(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_22(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_QuickBuyDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_SelectMaskItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_LendMaskOfTruth(EnOssan* pthis, GlobalContext* globalCtx, Player* player);
void EnOssan_State_GiveDiscountDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player);

void EnOssan_Obj3ToSeg6(EnOssan* pthis, GlobalContext* globalCtx);

void EnOssan_StartShopping(GlobalContext* globalCtx, EnOssan* pthis);

void EnOssan_WaitForBlink(EnOssan* pthis);
void EnOssan_Blink(EnOssan* pthis);

u16 EnOssan_SetupHelloDialog(EnOssan* pthis);

s32 EnOssan_TakeItemOffShelf(EnOssan* pthis);
s32 EnOssan_ReturnItemToShelf(EnOssan* pthis);
void EnOssan_ResetItemPosition(EnOssan* pthis);
void EnOssan_SetStateGiveDiscountDialog(GlobalContext* globalCtx, EnOssan* pthis);

static void* sBazaarShopkeeperEyeTextures_238[] = { gOssanEyeOpenTex, gOssanEyeHalfTex, gOssanEyeClosedTex };

static void* sKokiriShopkeeperEyeTextures_239[] = {
    gKokiriShopkeeperEyeDefaultTex,
    gKokiriShopkeeperEyeHalfTex,
    gKokiriShopkeeperEyeOpenTex,
};

static void* sGoronShopkeeperEyeTextures_243[] = { gGoronCsEyeOpenTex, gGoronCsEyeHalfTex, gGoronCsEyeClosedTex };

static void* sZoraShopkeeperEyeTextures_245[] = { gZoraEyeOpenTex, gZoraEyeHalfTex, gZoraEyeClosedTex };

static void* sPotionShopkeeperEyeTextures_246[] = { gPotionShopkeeperEyeOpenTex, gPotionShopkeeperEyeHalfTex,
                                                gPotionShopkeeperEyeClosedTex };

static void* sHappyMaskShopkeeperEyeTextures_247[] = { gOsEyeClosedTex, gOsEyeOpenTex };

static void* sBombchuShopkeeperEyeTextures_248[] = { gBombchuShopkeeperEyeOpenTex, gBombchuShopkeeperEyeHalfTex,
                                                 gBombchuShopkeeperEyeClosedTex };


#define CURSOR_INVALID 0xFF

ActorInit En_Ossan_InitVars = {
    ACTOR_EN_OSSAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnOssan),
    (ActorFunc)EnOssan_Init,
    (ActorFunc)EnOssan_Destroy,
    (ActorFunc)EnOssan_Update,
    NULL,
    (ActorFunc)EnOssan_Reset,
};

// Unused collider
static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 30, 80, 0, { 0, 0, 0 } },
};

// Rupees to pay back to Happy Mask Shop
static s16 sMaskPaymentPrice[] = { 10, 30, 20, 50 };

// item yaw offsets
static s16 sItemShelfRot[] = { 0xEAAC, 0xEAAC, 0xEAAC, 0xEAAC, 0x1554, 0x1554, 0x1554, 0x1554 };

// unused values?
static s16 D_80AC8904[] = { 0x001E, 0x001F, 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025 };

static const char* sShopkeeperPrintName[] = {
    "コキリの店  ", // "Kokiri Shop"
    "薬屋        ", // "Potion Shop"
    "夜の店      ", // "Night Shop"
    "路地裏の店  ", // "Back Alley Shop"
    "盾の店      ", // "Shield Shop"
    "大人の店    ", // "Adult Shop"
    "タロンの店  ", // "Talon Shop"
    "ゾーラの店  ", // "Zora Shop"
    "ゴロン夜の店", // "Goron Night Shop"
    "インゴーの店", // "Ingo Store"
    "お面屋      ", // "Mask Shop"
};

static s16 sShopkeeperObjectIds[][3] = {
    { OBJECT_KM1, OBJECT_MASTERKOKIRIHEAD, OBJECT_MASTERKOKIRI },
    { OBJECT_DS2, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_RS, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_DS2, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_OSSAN, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_OSSAN, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_OSSAN, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_ZO, OBJECT_ID_MAX, OBJECT_MASTERZOORA },
    { OBJECT_OF1D_MAP, OBJECT_ID_MAX, OBJECT_MASTERGOLON },
    { OBJECT_OSSAN, OBJECT_ID_MAX, OBJECT_ID_MAX },
    { OBJECT_OS, OBJECT_ID_MAX, OBJECT_ID_MAX },
};

static EnOssanTalkOwnerFunc sShopkeeperTalkOwner[] = {
    EnOssan_TalkKokiriShopkeeper,       EnOssan_TalkKakarikoPotionShopkeeper, EnOssan_TalkBombchuShopkeeper,
    EnOssan_TalkMarketPotionShopkeeper, EnOssan_TalkBazaarShopkeeper,         EnOssan_TalkDefaultShopkeeper,
    EnOssan_TalkDefaultShopkeeper,      EnOssan_TalkZoraShopkeeper,           EnOssan_TalkGoronShopkeeper,
    EnOssan_TalkDefaultShopkeeper,      EnOssan_TalkHappyMaskShopkeeper,
};

static f32 sShopkeeperScale[] = {
    0.01f, 0.011f, 0.0105f, 0.011f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f,
}; 

ShopItem sShopkeeperStores[][8] = {
    { { SI_DEKU_SHIELD, 50, 52, -20 },
      { SI_DEKU_NUTS_5, 50, 76, -20 },
      { SI_DEKU_NUTS_10, 80, 52, -3 },
      { SI_DEKU_STICK, 80, 76, -3 },
      { SI_DEKU_SEEDS_30, -50, 52, -20 },
      { SI_ARROWS_10, -50, 76, -20 },
      { SI_ARROWS_30, -80, 52, -3 },
      { SI_HEART, -80, 76, -3 } },

    { { SI_GREEN_POTION, 50, 52, -20 },
      { SI_BLUE_FIRE, 50, 76, -20 },
      { SI_RED_POTION_R30, 80, 52, -3 },
      { SI_FAIRY, 80, 76, -3 },
      { SI_DEKU_NUTS_5, -50, 52, -20 },
      { SI_BUGS, -50, 76, -20 },
      { SI_POE, -80, 52, -3 },
      { SI_FISH, -80, 76, -3 } },

    { { SI_BOMBCHU_10_2, 50, 52, -20 },
      { SI_BOMBCHU_10_4, 50, 76, -20 },
      { SI_BOMBCHU_10_3, 80, 52, -3 },
      { SI_BOMBCHU_10_1, 80, 76, -3 },
      { SI_BOMBCHU_20_3, -50, 52, -20 },
      { SI_BOMBCHU_20_1, -50, 76, -20 },
      { SI_BOMBCHU_20_4, -80, 52, -3 },
      { SI_BOMBCHU_20_2, -80, 76, -3 } },

    { { SI_GREEN_POTION, 50, 52, -20 },
      { SI_BLUE_FIRE, 50, 76, -20 },
      { SI_RED_POTION_R30, 80, 52, -3 },
      { SI_FAIRY, 80, 76, -3 },
      { SI_DEKU_NUTS_5, -50, 52, -20 },
      { SI_BUGS, -50, 76, -20 },
      { SI_POE, -80, 52, -3 },
      { SI_FISH, -80, 76, -3 } },

    { { SI_HYLIAN_SHIELD, 50, 52, -20 },
      { SI_BOMBS_5_R35, 50, 76, -20 },
      { SI_DEKU_NUTS_5, 80, 52, -3 },
      { SI_HEART, 80, 76, -3 },
      { SI_ARROWS_10, -50, 52, -20 },
      { SI_ARROWS_50, -50, 76, -20 },
      { SI_DEKU_STICK, -80, 52, -3 },
      { SI_ARROWS_30, -80, 76, -3 } },

    { { SI_HYLIAN_SHIELD, 50, 52, -20 },
      { SI_BOMBS_5_R25, 50, 76, -20 },
      { SI_DEKU_NUTS_5, 80, 52, -3 },
      { SI_HEART, 80, 76, -3 },
      { SI_ARROWS_10, -50, 52, -20 },
      { SI_ARROWS_50, -50, 76, -20 },
      { SI_DEKU_STICK, -80, 52, -3 },
      { SI_ARROWS_30, -80, 76, -3 } },

    { { SI_MILK_BOTTLE, 50, 52, -20 },
      { SI_DEKU_NUTS_5, 50, 76, -20 },
      { SI_DEKU_NUTS_10, 80, 52, -3 },
      { SI_HEART, 80, 76, -3 },
      { SI_WEIRD_EGG, -50, 52, -20 },
      { SI_DEKU_STICK, -50, 76, -20 },
      { SI_HEART, -80, 52, -3 },
      { SI_HEART, -80, 76, -3 } },

    { { SI_ZORA_TUNIC, 50, 52, -20 },
      { SI_ARROWS_10, 50, 76, -20 },
      { SI_HEART, 80, 52, -3 },
      { SI_ARROWS_30, 80, 76, -3 },
      { SI_DEKU_NUTS_5, -50, 52, -20 },
      { SI_ARROWS_50, -50, 76, -20 },
      { SI_FISH, -80, 52, -3 },
      { SI_RED_POTION_R50, -80, 76, -3 } },

    { { SI_BOMBS_5_R25, 50, 52, -20 },
      { SI_BOMBS_10, 50, 76, -20 },
      { SI_BOMBS_20, 80, 52, -3 },
      { SI_BOMBS_30, 80, 76, -3 },
      { SI_GORON_TUNIC, -50, 52, -20 },
      { SI_HEART, -50, 76, -20 },
      { SI_RED_POTION_R40, -80, 52, -3 },
      { SI_HEART, -80, 76, -3 } },

    { { SI_19, 50, 52, -20 },
      { SI_19, 50, 76, -20 },
      { SI_19, 80, 52, -3 },
      { SI_19, 80, 76, -3 },
      { SI_20, -50, 52, -20 },
      { SI_20, -50, 76, -20 },
      { SI_20, -80, 52, -3 },
      { SI_20, -80, 76, -3 } },

    { { SI_GERUDO_MASK, 50, 52, -20 },
      { SI_ZORA_MASK, 50, 76, -20 },
      { SI_MASK_OF_TRUTH, 80, 52, -3 },
      { SI_GORON_MASK, 80, 76, -3 },
      { SI_SKULL_MASK, -50, 52, -20 },
      { SI_KEATON_MASK, -50, 76, -20 },
      { SI_BUNNY_HOOD, -80, 52, -3 },
      { SI_SPOOKY_MASK, -80, 76, -3 } },
};
static EnOssanGetGirlAParamsFunc sShopItemReplaceFunc[] = {
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_SpookyMask,
    ShopItemDisp_SkullMask, ShopItemDisp_BunnyHood,  ShopItemDisp_Default, ShopItemDisp_ZoraMask,
    ShopItemDisp_GoronMask, ShopItemDisp_GerudoMask, ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,    ShopItemDisp_Default, ShopItemDisp_Default,
    ShopItemDisp_Default,   ShopItemDisp_Default,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 500, ICHAIN_STOP),
};

// When selecting an item to buy, pthis is the position the item moves to
static Vec3f sSelectedItemPosition[] = { { 17.0f, 58.0f, 30.0f }, { -17.0f, 58.0f, 30.0f } };

static EnOssanInitFunc sInitFuncs[] = {
    EnOssan_InitKokiriShopkeeper, EnOssan_InitPotionShopkeeper,    EnOssan_InitBombchuShopkeeper,
    EnOssan_InitPotionShopkeeper, EnOssan_InitBazaarShopkeeper,    EnOssan_InitBazaarShopkeeper,
    EnOssan_InitBazaarShopkeeper, EnOssan_InitZoraShopkeeper,      EnOssan_InitGoronShopkeeper,
    EnOssan_InitBazaarShopkeeper, EnOssan_InitHappyMaskShopkeeper,
};

static Vec3f sShopkeeperPositionOffsets[] = {
    { 0.0f, 0.0f, 33.0f }, { 0.0f, 0.0f, 31.0f }, { 0.0f, 0.0f, 31.0f }, { 0.0f, 0.0f, 31.0f },
    { 0.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 36.0f },
    { 0.0f, 0.0f, 15.0f }, { 0.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 26.0f },
};

static EnOssanStateFunc sStateFunc[] = {
    EnOssan_State_Idle,
    EnOssan_State_StartConversation,
    EnOssan_State_FacingShopkeeper,
    EnOssan_State_TalkingToShopkeeper,
    EnOssan_State_LookToLeftShelf,
    EnOssan_State_LookToRightShelf,
    EnOssan_State_BrowseLeftShelf,
    EnOssan_State_BrowseRightShelf,
    EnOssan_State_LookFromShelfToShopkeeper,
    EnOssan_State_ItemSelected,
    EnOssan_State_SelectMilkBottle,
    EnOssan_State_SelectWeirdEgg,
    EnOssan_State_SelectUnimplementedItem,
    EnOssan_State_SelectBombs,
    EnOssan_State_CantGetItem,
    EnOssan_State_GiveItemWithFanfare,
    EnOssan_State_ItemPurchased,
    EnOssan_State_ContinueShoppingPrompt,
    EnOssan_State_GiveLonLonMilk,
    EnOssan_State_DisplayOnlyBombDialog,
    EnOssan_State_WaitForDisplayOnlyBombDialog,
    EnOssan_State_21,
    EnOssan_State_22,
    EnOssan_State_QuickBuyDialog,
    EnOssan_State_SelectMaskItem,
    EnOssan_State_LendMaskOfTruth,
    EnOssan_State_GiveDiscountDialog,
};

void EnOssan_SetupAction(EnOssan* pthis, EnOssanActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

s16 ShopItemDisp_Default(s16 v) {
    return v;
}

s16 ShopItemDisp_SpookyMask(s16 v) {
    // Sold Skull Mask
    if (gSaveContext.itemGetInf[3] & 0x200) {
        return v;
    }
    return -1;
}

s16 ShopItemDisp_SkullMask(s16 v) {
    // Sold Keaton Mask
    if (gSaveContext.itemGetInf[3] & 0x100) {
        return v;
    }
    return -1;
}

s16 ShopItemDisp_BunnyHood(s16 v) {
    // Sold Spooky Mask
    if (gSaveContext.itemGetInf[3] & 0x400) {
        return v;
    }
    return -1;
}

s16 ShopItemDisp_ZoraMask(s16 v) {
    // Obtained Mask of Truth
    if (gSaveContext.itemGetInf[3] & 0x8000) {
        return v;
    }
    return -1;
}

s16 ShopItemDisp_GoronMask(s16 v) {
    // Obtained Mask of Truth
    if (gSaveContext.itemGetInf[3] & 0x8000) {
        return v;
    }
    return -1;
}

s16 ShopItemDisp_GerudoMask(s16 v) {
    // Obtained Mask of Truth
    if (gSaveContext.itemGetInf[3] & 0x8000) {
        return v;
    }
    return -1;
}

void EnOssan_SpawnItemsOnShelves(EnOssan* pthis, GlobalContext* globalCtx, ShopItem* shopItems) {
    EnTana* shelves;
    s16 itemParams;
    s32 i;

    for (i = 0; i < 8; i++, shopItems++) {
        if (shopItems->shopItemIndex < 0) {
            pthis->shelfSlots[i] = NULL;
        } else {
            itemParams = sShopItemReplaceFunc[shopItems->shopItemIndex](shopItems->shopItemIndex);

            if (itemParams < 0) {
                pthis->shelfSlots[i] = NULL;
            } else {
                shelves = pthis->shelves;
                pthis->shelfSlots[i] = (EnGirlA*)Actor_Spawn(
                    &globalCtx->actorCtx, globalCtx, ACTOR_EN_GIRLA, shelves->actor.world.pos.x + shopItems->xOffset,
                    shelves->actor.world.pos.y + shopItems->yOffset, shelves->actor.world.pos.z + shopItems->zOffset,
                    shelves->actor.shape.rot.x, shelves->actor.shape.rot.y + sItemShelfRot[i],
                    shelves->actor.shape.rot.z, itemParams);
            }
        }
    }
}

void EnOssan_UpdateShopOfferings(EnOssan* pthis, GlobalContext* globalCtx) {
    s32 i;
    ShopItem* storeItems;
    ShopItem* shopItem;

    if (pthis->actor.params == OSSAN_TYPE_MASK) {
        storeItems = sShopkeeperStores[pthis->actor.params];
        if (1) {}
        for (i = 0; i < 8; i++) {
            shopItem = &storeItems[i];
            if (shopItem->shopItemIndex >= 0 && pthis->shelfSlots[i] == NULL) {
                s16 params = sShopItemReplaceFunc[shopItem->shopItemIndex](shopItem->shopItemIndex);

                if (params >= 0) {
                    pthis->shelfSlots[i] = (EnGirlA*)Actor_Spawn(
                        &globalCtx->actorCtx, globalCtx, ACTOR_EN_GIRLA,
                        pthis->shelves->actor.world.pos.x + shopItem->xOffset,
                        pthis->shelves->actor.world.pos.y + shopItem->yOffset,
                        pthis->shelves->actor.world.pos.z + shopItem->zOffset, pthis->shelves->actor.shape.rot.x,
                        pthis->shelves->actor.shape.rot.y + sItemShelfRot[i], pthis->shelves->actor.shape.rot.z, params);
                }
            }
        }
    }
}

void EnOssan_TalkDefaultShopkeeper(GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x9E);
}

void EnOssan_TalkKakarikoPotionShopkeeper(GlobalContext* globalCtx) {
    if (globalCtx->curSpawn == 0) {
        Message_ContinueTextbox(globalCtx, 0x5046);
    } else {
        Message_ContinueTextbox(globalCtx, 0x504E);
    }
}

void EnOssan_TalkMarketPotionShopkeeper(GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x504E);
}

void EnOssan_TalkKokiriShopkeeper(GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x10BA);
}

void EnOssan_TalkBazaarShopkeeper(GlobalContext* globalCtx) {
    if (globalCtx->curSpawn == 0) {
        Message_ContinueTextbox(globalCtx, 0x9D);
    } else {
        Message_ContinueTextbox(globalCtx, 0x9C);
    }
}

void EnOssan_TalkBombchuShopkeeper(GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x7076);
}

void EnOssan_TalkZoraShopkeeper(GlobalContext* globalCtx) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        Message_ContinueTextbox(globalCtx, 0x403A);
    } else {
        Message_ContinueTextbox(globalCtx, 0x403B);
    }
}

// Goron City, Goron
void EnOssan_TalkGoronShopkeeper(GlobalContext* globalCtx) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        if (gSaveContext.eventChkInf[2] & 0x20) {
            Message_ContinueTextbox(globalCtx, 0x3028);
        } else if (CUR_UPG_VALUE(UPG_STRENGTH) != 0) {
            Message_ContinueTextbox(globalCtx, 0x302D);
        } else {
            Message_ContinueTextbox(globalCtx, 0x300F);
        }
    } else if (!CHECK_QUEST_ITEM(QUEST_MEDALLION_FIRE)) {
        Message_ContinueTextbox(globalCtx, 0x3057);
    } else {
        Message_ContinueTextbox(globalCtx, 0x305B);
    }
}

// Happy Mask Shop
void EnOssan_TalkHappyMaskShopkeeper(GlobalContext* globalCtx) {
    if ((gSaveContext.itemGetInf[3] & 0x100)       // Sold Keaton Mask
        && (gSaveContext.itemGetInf[3] & 0x200)    // Sold Skull Mask
        && (gSaveContext.itemGetInf[3] & 0x400)    // Sold Spooky Mask
        && (gSaveContext.itemGetInf[3] & 0x800)) { // Sold Bunny Hood
        Message_ContinueTextbox(globalCtx, 0x70AE);
    } else {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 1:
                Message_ContinueTextbox(globalCtx, 0x70A4);
                break;
            case 0:
                Message_ContinueTextbox(globalCtx, 0x70A3);
                break;
        }
    }
}

void EnOssan_UpdateCameraDirection(EnOssan* pthis, GlobalContext* globalCtx, f32 cameraFaceAngle) {
    pthis->cameraFaceAngle = cameraFaceAngle;
    Camera_SetCameraData(GET_ACTIVE_CAM(globalCtx), 0xC, NULL, NULL, cameraFaceAngle, 0, 0);
}

s32 EnOssan_TryGetObjBankIndexes(EnOssan* pthis, GlobalContext* globalCtx, s16* objectIds) {
    if (objectIds[1] != OBJECT_ID_MAX) {
        pthis->objBankIndex2 = Object_GetIndex(&globalCtx->objectCtx, objectIds[1]);
        if (pthis->objBankIndex2 < 0) {
            return false;
        }
    } else {
        pthis->objBankIndex2 = -1;
    }
    if (objectIds[2] != OBJECT_ID_MAX) {
        pthis->objBankIndex3 = Object_GetIndex(&globalCtx->objectCtx, objectIds[2]);
        if (pthis->objBankIndex3 < 0) {
            return false;
        }
    } else {
        pthis->objBankIndex3 = -1;
    }
    return true;
}

void EnOssan_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;
    s16* objectIds;

    if (pthis->actor.params == OSSAN_TYPE_TALON && (LINK_AGE_IN_YEARS != YEARS_CHILD)) {
        pthis->actor.params = OSSAN_TYPE_INGO;
    }

    //! @bug This check will always evaluate to false, it should be || not &&
    if (pthis->actor.params > OSSAN_TYPE_MASK && pthis->actor.params < OSSAN_TYPE_KOKIRI) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("引数がおかしいよ(arg_data=%d)！！\n", pthis->actor.params);
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_oB1.c", 1246);
        return;
    }

    // If you've given Zelda's Letter to the Kakariko Guard
    if (pthis->actor.params == OSSAN_TYPE_MASK && !(gSaveContext.infTable[7] & 0x40)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->actor.params == OSSAN_TYPE_KAKARIKO_POTION && (LINK_AGE_IN_YEARS == YEARS_CHILD)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    // Completed Dodongo's Cavern
    if (pthis->actor.params == OSSAN_TYPE_BOMBCHUS && !(gSaveContext.eventChkInf[2] & 0x20)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    objectIds = sShopkeeperObjectIds[pthis->actor.params];
    pthis->objBankIndex1 = Object_GetIndex(&globalCtx->objectCtx, objectIds[0]);

    if (pthis->objBankIndex1 < 0) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("バンクが無いよ！！(%s)\n", sShopkeeperPrintName[pthis->actor.params]);
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_oB1.c", 1284);
        return;
    }

    if (EnOssan_TryGetObjBankIndexes(pthis, globalCtx, objectIds) == 0) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("予備バンクが無いよ！！(%s)\n", sShopkeeperPrintName[pthis->actor.params]);
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_oB1.c", 1295);
        return;
    }

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    EnOssan_SetupAction(pthis, EnOssan_InitActionFunc);
}

void EnOssan_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnOssan_UpdateCursorPos(GlobalContext* globalCtx, EnOssan* pthis) {
    s16 x;
    s16 y;

    Actor_GetScreenPos(globalCtx, &pthis->shelfSlots[pthis->cursorIndex]->actor, &x, &y);
    pthis->cursorX = x;
    pthis->cursorY = y;
}

void EnOssan_EndInteraction(GlobalContext* globalCtx, EnOssan* pthis) {
    Player* player = GET_PLAYER(globalCtx);

    // "End of conversation!"
    osSyncPrintf(VT_FGCOL(YELLOW) "%s[%d]:★★★ 会話終了！！ ★★★" VT_RST "\n", "../z_en_oB1.c", 1337);
    YREG(31) = 0;
    Actor_ProcessTalkRequest(&pthis->actor, globalCtx);
    globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
    globalCtx->msgCtx.stateTimer = 4;
    player->stateFlags2 &= ~0x20000000;
    func_800BC490(globalCtx, 1);
    Interface_ChangeAlpha(50);
    pthis->drawCursor = 0;
    pthis->stickLeftPrompt.isEnabled = false;
    pthis->stickRightPrompt.isEnabled = false;
    EnOssan_UpdateCameraDirection(pthis, globalCtx, 0.0f);
    pthis->actor.textId = EnOssan_SetupHelloDialog(pthis);
    pthis->stateFlag = OSSAN_STATE_IDLE;
}

s32 EnOssan_TestEndInteraction(EnOssan* pthis, GlobalContext* globalCtx, Input* input) {
    if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
        EnOssan_EndInteraction(globalCtx, pthis);
        return true;
    } else {
        return false;
    }
}

s32 EnOssan_TestCancelOption(EnOssan* pthis, GlobalContext* globalCtx, Input* input) {
    if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
        pthis->stateFlag = pthis->tempStateFlag;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
        return true;
    } else {
        return false;
    }
}

void EnOssan_SetStateStartShopping(GlobalContext* globalCtx, EnOssan* pthis, u8 skipHelloState) {
    YREG(31) = 1;
    pthis->headRot = pthis->headTargetRot = 0;
    Interface_SetDoAction(globalCtx, DO_ACTION_NEXT);
    EnOssan_UpdateCameraDirection(pthis, globalCtx, 0);

    if (!skipHelloState) {
        pthis->stateFlag = OSSAN_STATE_START_CONVERSATION;
    } else {
        EnOssan_StartShopping(globalCtx, pthis);
    }
}

void EnOssan_StartShopping(GlobalContext* globalCtx, EnOssan* pthis) {
    pthis->stateFlag = OSSAN_STATE_FACING_SHOPKEEPER;

    if (pthis->actor.params == OSSAN_TYPE_MASK) {
        // if all masks have been sold, give the option to ask about the mask of truth
        if ((gSaveContext.itemGetInf[3] & 0x100) && (gSaveContext.itemGetInf[3] & 0x200) &&
            (gSaveContext.itemGetInf[3] & 0x400) && (gSaveContext.itemGetInf[3] & 0x800)) {
            Message_ContinueTextbox(globalCtx, 0x70AD);
        } else {
            Message_ContinueTextbox(globalCtx, 0x70A2);
        }
    } else {
        Message_ContinueTextbox(globalCtx, 0x83);
    }

    Interface_SetDoAction(globalCtx, DO_ACTION_DECIDE);
    pthis->stickRightPrompt.isEnabled = true;
    pthis->stickLeftPrompt.isEnabled = true;
    EnOssan_UpdateCameraDirection(pthis, globalCtx, 0.0f);
}

void EnOssan_ChooseTalkToOwner(GlobalContext* globalCtx, EnOssan* pthis) {
    pthis->stateFlag = OSSAN_STATE_TALKING_TO_SHOPKEEPER;
    sShopkeeperTalkOwner[pthis->actor.params](globalCtx);
    Interface_SetDoAction(globalCtx, DO_ACTION_DECIDE);
    pthis->stickLeftPrompt.isEnabled = false;
    pthis->stickRightPrompt.isEnabled = false;
}

void EnOssan_SetLookToShopkeeperFromShelf(GlobalContext* globalCtx, EnOssan* pthis) {
    func_80078884(NA_SE_SY_CURSOR);
    pthis->drawCursor = 0;
    pthis->stateFlag = OSSAN_STATE_LOOK_SHOPKEEPER;
}

void EnOssan_State_Idle(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    pthis->headTargetRot = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        // "Start conversation!!"
        osSyncPrintf(VT_FGCOL(YELLOW) "★★★ 会話開始！！ ★★★" VT_RST "\n");
        player->stateFlags2 |= 0x20000000;
        func_800BC590(globalCtx);
        EnOssan_SetStateStartShopping(globalCtx, pthis, false);
    } else if (pthis->actor.xzDistToPlayer < 100.0f) {
        func_8002F2CC(&pthis->actor, globalCtx, 100);
    }
}

void EnOssan_UpdateJoystickInputState(GlobalContext* globalCtx, EnOssan* pthis) {
    Input* input = &globalCtx->state.input[0];
    s8 stickX = input->rel.stick_x;
    s8 stickY = input->rel.stick_y;

    pthis->moveHorizontal = pthis->moveVertical = false;

    if (pthis->stickAccumX == 0) {
        if (stickX > 30 || stickX < -30) {
            pthis->stickAccumX = stickX;
            pthis->moveHorizontal = true;
        }
    } else if (stickX <= 30 && stickX >= -30) {
        pthis->stickAccumX = 0;
    } else if (pthis->stickAccumX * stickX < 0) { // Stick has swapped directions
        pthis->stickAccumX = stickX;
        pthis->moveHorizontal = true;
    } else {
        pthis->stickAccumX += stickX;

        if (pthis->stickAccumX > 2000) {
            pthis->stickAccumX = 2000;
        } else if (pthis->stickAccumX < -2000) {
            pthis->stickAccumX = -2000;
        }
    }

    if (pthis->stickAccumY == 0) {
        if (stickY > 30 || stickY < -30) {
            pthis->stickAccumY = stickY;
            pthis->moveVertical = true;
        }
    } else if (stickY <= 30 && stickY >= -30) {
        pthis->stickAccumY = 0;
    } else if (pthis->stickAccumY * stickY < 0) { // Stick has swapped directions
        pthis->stickAccumY = stickY;
        pthis->moveVertical = true;
    } else {
        pthis->stickAccumY += stickY;

        if (pthis->stickAccumY > 2000) {
            pthis->stickAccumY = 2000;
        } else if (pthis->stickAccumY < -2000) {
            pthis->stickAccumY = -2000;
        }
    }
}

u8 EnOssan_SetCursorIndexFromNeutral(EnOssan* pthis, u8 shelfOffset) {
    u8 i;

    // if cursor is on the top shelf
    if (pthis->cursorIndex & 1) {
        // scan top shelf for non-null item
        for (i = shelfOffset + 1; i < shelfOffset + 4; i += 2) {
            if (pthis->shelfSlots[i] != NULL) {
                return i;
            }
        }
        // scan bottom shelf for non-null item
        for (i = shelfOffset; i < shelfOffset + 4; i += 2) {
            if (pthis->shelfSlots[i] != NULL) {
                return i;
            }
        }
    } else {
        // scan bottom shelf for non-null item
        for (i = shelfOffset; i < shelfOffset + 4; i += 2) {
            if (pthis->shelfSlots[i] != NULL) {
                return i;
            }
        }
        // scan top shelf for non-null item
        for (i = shelfOffset + 1; i < shelfOffset + 4; i += 2) {
            if (pthis->shelfSlots[i] != NULL) {
                return i;
            }
        }
    }
    return CURSOR_INVALID;
}

u8 EnOssan_CursorRight(EnOssan* pthis, u8 cursorIndex, u8 shelfSlotMin) {
    u8 c = shelfSlotMin + 4;

    while (cursorIndex >= shelfSlotMin && cursorIndex < c) {
        cursorIndex -= 2;
        if (cursorIndex >= shelfSlotMin && cursorIndex < c) {
            if (pthis->shelfSlots[cursorIndex] != NULL) {
                return cursorIndex;
            }
        }
    }
    return CURSOR_INVALID;
}

u8 EnOssan_CursorLeft(EnOssan* pthis, u8 cursorIndex, u8 shelfSlotMax) {

    while (cursorIndex < shelfSlotMax) {
        cursorIndex += 2;
        if ((cursorIndex < shelfSlotMax) && pthis->shelfSlots[cursorIndex] != NULL) {
            return cursorIndex;
        }
    }
    return CURSOR_INVALID;
}

// pay salesman back
void EnOssan_TryPaybackMask(EnOssan* pthis, GlobalContext* globalCtx) {
    s16 price = sMaskPaymentPrice[pthis->happyMaskShopState];

    if (gSaveContext.rupees < price) {
        Message_ContinueTextbox(globalCtx, 0x70A8);
        pthis->happyMaskShopkeeperEyeIdx = 1;
        pthis->happyMaskShopState = OSSAN_HAPPY_STATE_ANGRY;
    } else {
        Rupees_ChangeBy(-price);

        if (pthis->happyMaskShopState == OSSAN_HAPPY_STATE_REQUEST_PAYMENT_BUNNY_HOOD) {
            gSaveContext.eventChkInf[8] |= 0x8000;
            Message_ContinueTextbox(globalCtx, 0x70A9);
            pthis->happyMaskShopState = OSSAN_HAPPY_STATE_ALL_MASKS_SOLD;
            return;
        }

        if (pthis->happyMaskShopState == OSSAN_HAPPY_STATE_REQUEST_PAYMENT_KEATON_MASK) {
            gSaveContext.eventChkInf[8] |= 0x1000;
        } else if (pthis->happyMaskShopState == OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SPOOKY_MASK) {
            gSaveContext.eventChkInf[8] |= 0x4000;
        } else if (pthis->happyMaskShopState == OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SKULL_MASK) {
            gSaveContext.eventChkInf[8] |= 0x2000;
        }

        Message_ContinueTextbox(globalCtx, 0x70A7);
        pthis->happyMaskShopState = OSSAN_HAPPY_STATE_NONE;
    }
    pthis->stateFlag = OSSAN_STATE_START_CONVERSATION;
}

void EnOssan_State_StartConversation(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    u8 dialogState = Message_GetState(&globalCtx->msgCtx);

    if (pthis->actor.params == OSSAN_TYPE_MASK && dialogState == TEXT_STATE_CHOICE) {
        if (!EnOssan_TestEndInteraction(pthis, globalCtx, &globalCtx->state.input[0]) &&
            Message_ShouldAdvance(globalCtx)) {
            switch (globalCtx->msgCtx.choiceIndex) {
                case 0:
                    EnOssan_StartShopping(globalCtx, pthis);
                    break;
                case 1:
                    EnOssan_EndInteraction(globalCtx, pthis);
                    break;
            }
        }
    } else if (dialogState == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        func_80078884(NA_SE_SY_MESSAGE_PASS);

        switch (pthis->happyMaskShopState) {
            case OSSAN_HAPPY_STATE_ALL_MASKS_SOLD:
                Message_ContinueTextbox(globalCtx, 0x70AA);
                pthis->stateFlag = OSSAN_STATE_LEND_MASK_OF_TRUTH;
                return;
            case OSSAN_HAPPY_STATE_BORROWED_FIRST_MASK:
                EnOssan_EndInteraction(globalCtx, pthis);
                return;
            case OSSAN_HAPPY_STATE_REQUEST_PAYMENT_KEATON_MASK:
            case OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SPOOKY_MASK:
            case OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SKULL_MASK:
            case OSSAN_HAPPY_STATE_REQUEST_PAYMENT_BUNNY_HOOD:
                EnOssan_TryPaybackMask(pthis, globalCtx);
                return;
            case OSSAN_HAPPY_STATE_ANGRY:
                globalCtx->nextEntranceIndex = 0x1D1;
                globalCtx->sceneLoadFlag = 0x14;
                globalCtx->fadeTransition = 0x2E;
                return;
        }

        if (!EnOssan_TestEndInteraction(pthis, globalCtx, &globalCtx->state.input[0])) {
            // "Shop around by moving the stick left and right"
            osSyncPrintf("「スティック左右で品物みてくれ！」\n");
            EnOssan_StartShopping(globalCtx, pthis);
        }
    }

    if (1) {}
}

s32 EnOssan_FacingShopkeeperDialogResult(EnOssan* pthis, GlobalContext* globalCtx) {
    switch (globalCtx->msgCtx.choiceIndex) {
        case 0:
            EnOssan_ChooseTalkToOwner(globalCtx, pthis);
            return true;
        case 1:
            EnOssan_EndInteraction(globalCtx, pthis);
            return true;
        default:
            return false;
    }
}

void EnOssan_State_FacingShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    u8 nextIndex;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) &&
        !EnOssan_TestEndInteraction(pthis, globalCtx, &globalCtx->state.input[0])) {
        if (Message_ShouldAdvance(globalCtx) && EnOssan_FacingShopkeeperDialogResult(pthis, globalCtx)) {
            func_80078884(NA_SE_SY_DECIDE);
            return;
        }
        // Stick Left
        if (pthis->stickAccumX < 0) {
            nextIndex = EnOssan_SetCursorIndexFromNeutral(pthis, 4);
            if (nextIndex != CURSOR_INVALID) {
                pthis->cursorIndex = nextIndex;
                pthis->stateFlag = OSSAN_STATE_LOOK_SHELF_LEFT;
                Interface_SetDoAction(globalCtx, DO_ACTION_DECIDE);
                pthis->stickLeftPrompt.isEnabled = false;
                func_80078884(NA_SE_SY_CURSOR);
            }
        } else if (pthis->stickAccumX > 0) {
            nextIndex = EnOssan_SetCursorIndexFromNeutral(pthis, 0);
            if (nextIndex != CURSOR_INVALID) {
                pthis->cursorIndex = nextIndex;
                pthis->stateFlag = OSSAN_STATE_LOOK_SHELF_RIGHT;
                Interface_SetDoAction(globalCtx, DO_ACTION_DECIDE);
                pthis->stickRightPrompt.isEnabled = false;
                func_80078884(NA_SE_SY_CURSOR);
            }
        }
    }
}

void EnOssan_State_TalkingToShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        EnOssan_StartShopping(globalCtx, pthis);
    }
}

void EnOssan_State_LookToLeftShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    Math_ApproachF(&pthis->cameraFaceAngle, 30.0f, 0.5f, 10.0f);

    if (pthis->cameraFaceAngle > 29.5f) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, 30.0f);
    }

    EnOssan_UpdateCameraDirection(pthis, globalCtx, pthis->cameraFaceAngle);

    if (pthis->cameraFaceAngle >= 30.0f) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, 30.0f);
        EnOssan_UpdateCursorPos(globalCtx, pthis);
        pthis->stateFlag = OSSAN_STATE_BROWSE_LEFT_SHELF;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
    } else {
        pthis->stickAccumX = 0;
    }
}

void EnOssan_State_LookToRightShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    Math_ApproachF(&pthis->cameraFaceAngle, -30.0f, 0.5f, 10.0f);

    if (pthis->cameraFaceAngle < -29.5f) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, -30.0f);
    }

    EnOssan_UpdateCameraDirection(pthis, globalCtx, pthis->cameraFaceAngle);

    if (pthis->cameraFaceAngle <= -30.0f) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, -30.0f);
        EnOssan_UpdateCursorPos(globalCtx, pthis);
        pthis->stateFlag = OSSAN_STATE_BROWSE_RIGHT_SHELF;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
    } else {
        pthis->stickAccumX = 0;
    }
}

void EnOssan_CursorUpDown(EnOssan* pthis) {
    u8 curTemp = pthis->cursorIndex;
    u8 curScanTemp;

    if (pthis->stickAccumY < 0) {
        curTemp &= 0xFE;
        if (pthis->shelfSlots[curTemp] != NULL) {
            pthis->cursorIndex = curTemp;
            return;
        }
        // cursorIndex on right shelf
        if (curTemp < 4) {
            curScanTemp = curTemp + 2;
            if (curScanTemp >= 4) {
                curScanTemp = 0;
            }
            while (curScanTemp != curTemp) {
                if (pthis->shelfSlots[curScanTemp] != NULL) {
                    pthis->cursorIndex = curScanTemp;
                    return;
                }
                curScanTemp += 2;
                if (curScanTemp >= 4) {
                    curScanTemp = 0;
                }
            }
        } else {
            // cursorIndex on left shelf
            curScanTemp = curTemp + 2;
            if (curScanTemp >= 8) {
                curScanTemp = 4;
            }
            while (curScanTemp != curTemp) {
                if (pthis->shelfSlots[curScanTemp] != NULL) {
                    pthis->cursorIndex = curScanTemp;
                    return;
                }
                curScanTemp += 2;
                if (curScanTemp >= 8) {
                    curScanTemp = 4;
                }
            }
        }
    } else if (pthis->stickAccumY > 0) {
        curTemp |= 1;
        if (pthis->shelfSlots[curTemp] != NULL) {
            pthis->cursorIndex = curTemp;
            return;
        }
        // cursorIndex on right shelf
        if (curTemp < 4) {
            curScanTemp = curTemp + 2;
            if (curScanTemp >= 4) {
                curScanTemp = 1;
            }
            while (curScanTemp != curTemp) {
                if (pthis->shelfSlots[curScanTemp] != NULL) {
                    pthis->cursorIndex = curScanTemp;
                    return;
                }
                curScanTemp += 2;
                if (curScanTemp >= 4) {
                    curScanTemp = 1;
                }
            }
        } else {
            // cursorIndex on left shelf
            curScanTemp = curTemp + 2;
            if (curScanTemp >= 8) {
                curScanTemp = 5;
            }
            while (curScanTemp != curTemp) {
                if (pthis->shelfSlots[curScanTemp] != NULL) {
                    pthis->cursorIndex = curScanTemp;
                    return;
                }
                curScanTemp += 2;
                if (curScanTemp >= 8) {
                    curScanTemp = 5;
                }
            }
        }
    }
}

s32 EnOssan_HasPlayerSelectedItem(GlobalContext* globalCtx, EnOssan* pthis, Input* input) {
    EnGirlA* selectedItem = pthis->shelfSlots[pthis->cursorIndex];

    if (EnOssan_TestEndInteraction(pthis, globalCtx, input)) {
        return true;
    }
    if (Message_ShouldAdvance(globalCtx)) {
        if (selectedItem->actor.params != SI_SOLD_OUT && selectedItem->isInvisible == 0) {
            pthis->tempStateFlag = pthis->stateFlag;
            Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->itemBuyPromptTextId);
            pthis->stickLeftPrompt.isEnabled = false;
            pthis->stickRightPrompt.isEnabled = false;
            switch (selectedItem->actor.params) {
                case SI_KEATON_MASK:
                case SI_SPOOKY_MASK:
                case SI_SKULL_MASK:
                case SI_BUNNY_HOOD:
                case SI_MASK_OF_TRUTH:
                case SI_ZORA_MASK:
                case SI_GORON_MASK:
                case SI_GERUDO_MASK:
                    func_80078884(NA_SE_SY_DECIDE);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM_MASK;
                    return true;
                case SI_MILK_BOTTLE:
                    func_80078884(NA_SE_SY_DECIDE);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM_MILK_BOTTLE;
                    return true;
                case SI_WEIRD_EGG:
                    func_80078884(NA_SE_SY_DECIDE);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM_WEIRD_EGG;
                    return true;
                case SI_19:
                case SI_20:
                    func_80078884(NA_SE_SY_ERROR);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM_UNIMPLEMENTED;
                    return true;
                case SI_BOMBS_5_R25:
                case SI_BOMBS_10:
                case SI_BOMBS_20:
                case SI_BOMBS_30:
                case SI_BOMBS_5_R35:
                    func_80078884(NA_SE_SY_DECIDE);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM_BOMBS;
                    return true;
                default:
                    func_80078884(NA_SE_SY_DECIDE);
                    pthis->drawCursor = 0;
                    pthis->stateFlag = OSSAN_STATE_SELECT_ITEM;
                    return true;
            }
        }
        func_80078884(NA_SE_SY_ERROR);
        return true;
    }
    return false;
}

void EnOssan_State_BrowseLeftShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    s32 a;
    s32 b;
    u8 prevIndex = pthis->cursorIndex;
    s32 c;
    s32 d;

    if (!EnOssan_ReturnItemToShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2152);
        pthis->delayTimer = 3;
        return;
    }
    if (pthis->delayTimer != 0) {
        pthis->delayTimer--;
        return;
    }
    pthis->drawCursor = 0xFF;
    pthis->stickRightPrompt.isEnabled = true;
    EnOssan_UpdateCursorPos(globalCtx, pthis);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) &&
        !EnOssan_HasPlayerSelectedItem(globalCtx, pthis, &globalCtx->state.input[0])) {
        if (pthis->moveHorizontal) {
            if (pthis->stickAccumX > 0) {
                a = EnOssan_CursorRight(pthis, pthis->cursorIndex, 4);
                if (a != CURSOR_INVALID) {
                    pthis->cursorIndex = a;
                } else {
                    EnOssan_SetLookToShopkeeperFromShelf(globalCtx, pthis);
                    return;
                }
            } else if (pthis->stickAccumX < 0) {
                b = EnOssan_CursorLeft(pthis, pthis->cursorIndex, 8);
                if (b != CURSOR_INVALID) {
                    pthis->cursorIndex = b;
                }
            }
        } else {
            if (pthis->stickAccumX > 0 && pthis->stickAccumX > 500) {
                c = EnOssan_CursorRight(pthis, pthis->cursorIndex, 4);
                if (c != CURSOR_INVALID) {
                    pthis->cursorIndex = c;
                } else {
                    EnOssan_SetLookToShopkeeperFromShelf(globalCtx, pthis);
                    return;
                }
            } else if (pthis->stickAccumX < 0 && pthis->stickAccumX < -500) {
                d = EnOssan_CursorLeft(pthis, pthis->cursorIndex, 8);
                if (d != CURSOR_INVALID) {
                    pthis->cursorIndex = d;
                }
            }
        }
        EnOssan_CursorUpDown(pthis);
        if (pthis->cursorIndex != prevIndex) {
            Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
            func_80078884(NA_SE_SY_CURSOR);
        }
    }
}

void EnOssan_State_BrowseRightShelf(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    s32 pad[2];
    u8 prevIndex;
    u8 nextIndex;

    prevIndex = pthis->cursorIndex;
    if (!EnOssan_ReturnItemToShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2244);
        pthis->delayTimer = 3;
        return;
    }
    if (pthis->delayTimer != 0) {
        pthis->delayTimer--;
        return;
    }
    pthis->drawCursor = 0xFF;
    pthis->stickLeftPrompt.isEnabled = true;
    EnOssan_UpdateCursorPos(globalCtx, pthis);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) &&
        !EnOssan_HasPlayerSelectedItem(globalCtx, pthis, &globalCtx->state.input[0])) {
        if (pthis->moveHorizontal) {
            if (pthis->stickAccumX < 0) {
                nextIndex = EnOssan_CursorRight(pthis, pthis->cursorIndex, 0);
                if (nextIndex != CURSOR_INVALID) {
                    pthis->cursorIndex = nextIndex;
                } else {
                    EnOssan_SetLookToShopkeeperFromShelf(globalCtx, pthis);
                    return;
                }
            } else if (pthis->stickAccumX > 0) {
                nextIndex = EnOssan_CursorLeft(pthis, pthis->cursorIndex, 4);
                if (nextIndex != CURSOR_INVALID) {
                    pthis->cursorIndex = nextIndex;
                }
            }
        } else {
            if (pthis->stickAccumX < 0 && pthis->stickAccumX < -500) {
                nextIndex = EnOssan_CursorRight(pthis, pthis->cursorIndex, 0);
                if (nextIndex != CURSOR_INVALID) {
                    pthis->cursorIndex = nextIndex;
                } else {
                    EnOssan_SetLookToShopkeeperFromShelf(globalCtx, pthis);
                    return;
                }
            } else if (pthis->stickAccumX > 0 && pthis->stickAccumX > 500) {
                nextIndex = EnOssan_CursorLeft(pthis, pthis->cursorIndex, 4);
                if (nextIndex != CURSOR_INVALID) {
                    pthis->cursorIndex = nextIndex;
                }
            }
        }
        EnOssan_CursorUpDown(pthis);
        if (pthis->cursorIndex != prevIndex) {
            Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
            func_80078884(NA_SE_SY_CURSOR);
        }
    }
}

void EnOssan_State_LookFromShelfToShopkeeper(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    Math_ApproachF(&pthis->cameraFaceAngle, 0.0f, 0.5f, 10.0f);
    if ((pthis->cameraFaceAngle < 0.5f) && (pthis->cameraFaceAngle > -0.5f)) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, 0.0f);
    }
    EnOssan_UpdateCameraDirection(pthis, globalCtx, pthis->cameraFaceAngle);
    if (pthis->cameraFaceAngle == 0.0f) {
        EnOssan_StartShopping(globalCtx, pthis);
    }
}

void EnOssan_State_DisplayOnlyBombDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (!EnOssan_ReturnItemToShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2355);
        return;
    }
    Math_ApproachF(&pthis->cameraFaceAngle, 0.0f, 0.5f, 10.0f);
    if (pthis->cameraFaceAngle < 0.5f && pthis->cameraFaceAngle > -0.5f) {
        EnOssan_UpdateCameraDirection(pthis, globalCtx, 0.0f);
    }
    EnOssan_UpdateCameraDirection(pthis, globalCtx, pthis->cameraFaceAngle);
    if (pthis->cameraFaceAngle == 0.0f) {
        Message_ContinueTextbox(globalCtx, 0x3010);
        pthis->stateFlag = OSSAN_STATE_WAIT_FOR_DISPLAY_ONLY_BOMB_DIALOG;
    }
}

void EnOssan_GiveItemWithFanfare(GlobalContext* globalCtx, EnOssan* pthis) {
    Player* player = GET_PLAYER(globalCtx);

    osSyncPrintf("\n" VT_FGCOL(YELLOW) "初めて手にいれた！！" VT_RST "\n\n");
    func_8002F434(&pthis->actor, globalCtx, pthis->shelfSlots[pthis->cursorIndex]->getItemId, 120.0f, 120.0f);
    globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
    globalCtx->msgCtx.stateTimer = 4;
    player->stateFlags2 &= ~0x20000000;
    func_800BC490(globalCtx, 1);
    Interface_ChangeAlpha(50);
    pthis->drawCursor = 0;
    EnOssan_UpdateCameraDirection(pthis, globalCtx, 0.0f);
    pthis->stateFlag = OSSAN_STATE_GIVE_ITEM_FANFARE;
    osSyncPrintf(VT_FGCOL(YELLOW) "持ち上げ開始！！" VT_RST "\n\n");
}

void EnOssan_SetStateCantGetItem(GlobalContext* globalCtx, EnOssan* pthis, u16 textId) {
    Message_ContinueTextbox(globalCtx, textId);
    pthis->stateFlag = OSSAN_STATE_CANT_GET_ITEM;
}

void EnOssan_SetStateQuickBuyDialog(GlobalContext* globalCtx, EnOssan* pthis, u16 textId) {
    Message_ContinueTextbox(globalCtx, textId);
    pthis->stateFlag = OSSAN_STATE_QUICK_BUY;
}

void EnOssan_HandleCanBuyItem(GlobalContext* globalCtx, EnOssan* pthis) {
    EnGirlA* selectedItem = pthis->shelfSlots[pthis->cursorIndex];

    switch (selectedItem->canBuyFunc(globalCtx, selectedItem)) {
        case CANBUY_RESULT_SUCCESS_FANFARE:
            if (selectedItem->actor.params == SI_HYLIAN_SHIELD && gSaveContext.infTable[7] & 0x40) {
                EnOssan_SetStateGiveDiscountDialog(globalCtx, pthis);
            } else {
                EnOssan_GiveItemWithFanfare(globalCtx, pthis);
                pthis->drawCursor = 0;
                pthis->shopItemSelectedTween = 0.0f;
                selectedItem->setOutOfStockFunc(globalCtx, selectedItem);
            }
            break;
        case CANBUY_RESULT_SUCCESS:
            selectedItem->itemGiveFunc(globalCtx, selectedItem);
            EnOssan_SetStateQuickBuyDialog(globalCtx, pthis, 0x84);
            pthis->drawCursor = 0;
            pthis->shopItemSelectedTween = 0.0f;
            selectedItem->setOutOfStockFunc(globalCtx, selectedItem);
            break;
        case CANBUY_RESULT_CANT_GET_NOW:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x86);
            break;
        case CANBUY_RESULT_NEED_BOTTLE:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x96);
            break;
        case CANBUY_RESULT_NEED_RUPEES:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x85);
            break;
        case CANBUY_RESULT_CANT_GET_NOW_5:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x86);
            break;
    }
}

void EnOssan_HandleCanBuyLonLonMilk(GlobalContext* globalCtx, EnOssan* pthis) {
    EnGirlA* item = pthis->shelfSlots[pthis->cursorIndex];

    switch (item->canBuyFunc(globalCtx, item)) {
        case CANBUY_RESULT_SUCCESS_FANFARE:
            Message_ContinueTextbox(globalCtx, 0x9C);
            pthis->stateFlag = OSSAN_STATE_GIVE_LON_LON_MILK;
            pthis->drawCursor = 0;
            break;
        case CANBUY_RESULT_SUCCESS:
            item->itemGiveFunc(globalCtx, item);
            EnOssan_SetStateQuickBuyDialog(globalCtx, pthis, 0x98);
            pthis->drawCursor = 0;
            pthis->shopItemSelectedTween = 0.0f;
            item->setOutOfStockFunc(globalCtx, item);
            break;
        case CANBUY_RESULT_NEED_BOTTLE:
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x96);
            break;
        case CANBUY_RESULT_NEED_RUPEES:
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x85);
            break;
    }
}

void EnOssan_HandleCanBuyWeirdEgg(GlobalContext* globalCtx, EnOssan* pthis) {
    EnGirlA* item = pthis->shelfSlots[pthis->cursorIndex];

    switch (item->canBuyFunc(globalCtx, item)) {
        case CANBUY_RESULT_SUCCESS_FANFARE:
            EnOssan_GiveItemWithFanfare(globalCtx, pthis);
            pthis->drawCursor = 0;
            pthis->shopItemSelectedTween = 0.0f;
            item->setOutOfStockFunc(globalCtx, item);
            break;
        case CANBUY_RESULT_SUCCESS:
            item->itemGiveFunc(globalCtx, item);
            EnOssan_SetStateQuickBuyDialog(globalCtx, pthis, 0x9A);
            pthis->drawCursor = 0;
            pthis->shopItemSelectedTween = 0.0f;
            item->setOutOfStockFunc(globalCtx, item);
            break;
        case CANBUY_RESULT_CANT_GET_NOW:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x9D);
            break;
        case CANBUY_RESULT_NEED_RUPEES:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x85);
            break;
    }
}

void EnOssan_HandleCanBuyBombs(GlobalContext* globalCtx, EnOssan* pthis) {
    EnGirlA* item = pthis->shelfSlots[pthis->cursorIndex];

    switch (item->canBuyFunc(globalCtx, item)) {
        case CANBUY_RESULT_SUCCESS_FANFARE:
        case CANBUY_RESULT_SUCCESS:
            item->itemGiveFunc(globalCtx, item);
            EnOssan_SetStateQuickBuyDialog(globalCtx, pthis, 0x84);
            pthis->drawCursor = 0;
            pthis->shopItemSelectedTween = 0.0f;
            item->setOutOfStockFunc(globalCtx, item);
            break;
        case CANBUY_RESULT_CANT_GET_NOW:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x86);
            break;
        case CANBUY_RESULT_NEED_RUPEES:
            func_80078884(NA_SE_SY_ERROR);
            EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x85);
            break;
    }
}

void EnOssan_BuyGoronCityBombs(GlobalContext* globalCtx, EnOssan* pthis) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        if (!(gSaveContext.eventChkInf[2] & 0x20)) {
            if (gSaveContext.infTable[15] & 0x1000) {
                EnOssan_SetStateCantGetItem(globalCtx, pthis, 0x302E);
            } else {
                pthis->stickLeftPrompt.isEnabled = false;
                pthis->stickRightPrompt.isEnabled = false;
                pthis->drawCursor = 0;
                pthis->stateFlag = OSSAN_STATE_DISPLAY_ONLY_BOMB_DIALOG;
            }
        } else {
            EnOssan_HandleCanBuyBombs(globalCtx, pthis);
        }
    } else {
        EnOssan_HandleCanBuyBombs(globalCtx, pthis);
    }
}

void EnOssan_State_ItemSelected(EnOssan* pthis, GlobalContext* globalCtx2, Player* player) {
    GlobalContext* globalCtx = globalCtx2; // Necessary for OKs

    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2654);
        return;
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE &&
        !EnOssan_TestCancelOption(pthis, globalCtx, &globalCtx->state.input[0]) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                EnOssan_HandleCanBuyItem(globalCtx, pthis);
                break;
            case 1:
                pthis->stateFlag = pthis->tempStateFlag;
                Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
                break;
        }
    }
}

void EnOssan_State_SelectMilkBottle(EnOssan* pthis, GlobalContext* globalCtx2, Player* player) {
    GlobalContext* globalCtx = globalCtx2; // Need for OK

    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2693);
        return;
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE &&
        !EnOssan_TestCancelOption(pthis, globalCtx, &globalCtx->state.input[0]) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                EnOssan_HandleCanBuyLonLonMilk(globalCtx, pthis);
                break;
            case 1:
                pthis->stateFlag = pthis->tempStateFlag;
                Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
                break;
        }
    }
}

void EnOssan_State_SelectWeirdEgg(EnOssan* pthis, GlobalContext* globalCtx2, Player* player) {
    GlobalContext* globalCtx = globalCtx2; // Needed for OK

    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2732);
        return;
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE &&
        !EnOssan_TestCancelOption(pthis, globalCtx, &globalCtx->state.input[0]) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                EnOssan_HandleCanBuyWeirdEgg(globalCtx, pthis);
                break;
            case 1:
                pthis->stateFlag = pthis->tempStateFlag;
                Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
                break;
        }
    }
}

void EnOssan_State_SelectUnimplementedItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2771);
        return;
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        pthis->stateFlag = pthis->tempStateFlag;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
    }
}

void EnOssan_State_SelectBombs(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2798);
        return;
    }
    osSyncPrintf("店主の依頼 ( %d )\n", gSaveContext.infTable[15] & 0x1000);
    if (pthis->actor.params != OSSAN_TYPE_GORON) {
        EnOssan_State_ItemSelected(pthis, globalCtx, player);
        return;
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE &&
        !EnOssan_TestCancelOption(pthis, globalCtx, &globalCtx->state.input[0]) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                EnOssan_BuyGoronCityBombs(globalCtx, pthis);
                break;
            case 1:
                pthis->stateFlag = pthis->tempStateFlag;
                Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
                break;
        }
    }
}

void EnOssan_State_SelectMaskItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    u8 talkState = Message_GetState(&globalCtx->msgCtx);
    EnGirlA* item = pthis->shelfSlots[pthis->cursorIndex];

    if (!EnOssan_TakeItemOffShelf(pthis)) {
        osSyncPrintf("%s[%d]:" VT_FGCOL(GREEN) "ズーム中！！" VT_RST "\n", "../z_en_oB1.c", 2845);
        return;
    }
    if (talkState == TEXT_STATE_EVENT) {
        if (Message_ShouldAdvance(globalCtx)) {
            pthis->stateFlag = pthis->tempStateFlag;
            Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
        }
    } else if (talkState == TEXT_STATE_CHOICE &&
               !EnOssan_TestCancelOption(pthis, globalCtx, &globalCtx->state.input[0]) &&
               Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0:
                switch (item->actor.params) {
                    case SI_KEATON_MASK:
                        gSaveContext.itemGetInf[2] |= 0x08;
                        break;
                    case SI_SPOOKY_MASK:
                        gSaveContext.itemGetInf[2] |= 0x20;
                        break;
                    case SI_SKULL_MASK:
                        gSaveContext.itemGetInf[2] |= 0x10;
                        break;
                    case SI_BUNNY_HOOD:
                        gSaveContext.itemGetInf[2] |= 0x40;
                        break;
                    case SI_MASK_OF_TRUTH:
                    case SI_ZORA_MASK:
                    case SI_GORON_MASK:
                    case SI_GERUDO_MASK:
                        break;
                }
                EnOssan_GiveItemWithFanfare(globalCtx, pthis);
                pthis->drawCursor = 0;
                pthis->shopItemSelectedTween = 0.0f;
                item->setOutOfStockFunc(globalCtx, item);
                break;
            case 1:
                pthis->stateFlag = pthis->tempStateFlag;
                Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
                break;
        }
    }
}

void EnOssan_State_CantGetItem(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        pthis->stateFlag = pthis->tempStateFlag;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
    }
}

void EnOssan_State_QuickBuyDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    EnGirlA* item;

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        pthis->shopItemSelectedTween = 0.0f;
        EnOssan_ResetItemPosition(pthis);
        item = pthis->shelfSlots[pthis->cursorIndex];
        item->updateStockedItemFunc(globalCtx, item);
        pthis->stateFlag = pthis->tempStateFlag;
        Message_ContinueTextbox(globalCtx, pthis->shelfSlots[pthis->cursorIndex]->actor.textId);
    }
}

void EnOssan_State_GiveItemWithFanfare(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    // The player sets itself as the parent actor to signal that it has obtained the give item request
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->stateFlag = OSSAN_STATE_ITEM_PURCHASED;
        return;
    }
    func_8002F434(&pthis->actor, globalCtx, pthis->shelfSlots[pthis->cursorIndex]->getItemId, 120.0f, 120.0f);
}

void EnOssan_State_ItemPurchased(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    EnGirlA* item;
    EnGirlA* itemTemp;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->actor.params == OSSAN_TYPE_MASK) {
            itemTemp = pthis->shelfSlots[pthis->cursorIndex];
            EnOssan_ResetItemPosition(pthis);
            item = pthis->shelfSlots[pthis->cursorIndex];
            item->updateStockedItemFunc(globalCtx, item);
            if (itemTemp->actor.params == SI_MASK_OF_TRUTH && !(gSaveContext.itemGetInf[3] & 0x8000)) {
                gSaveContext.itemGetInf[3] |= 0x8000;
                Message_ContinueTextbox(globalCtx, 0x70AB);
                pthis->happyMaskShopState = OSSAN_HAPPY_STATE_BORROWED_FIRST_MASK;
                EnOssan_UpdateShopOfferings(pthis, globalCtx);
                pthis->stateFlag = OSSAN_STATE_START_CONVERSATION;
                return;
            } else {
                EnOssan_EndInteraction(globalCtx, pthis);
                return;
            }
        }
        item = pthis->shelfSlots[pthis->cursorIndex];
        item->buyEventFunc(globalCtx, item);
        pthis->stateFlag = OSSAN_STATE_CONTINUE_SHOPPING_PROMPT;
        Message_ContinueTextbox(globalCtx, 0x6B);
    }
}

void EnOssan_State_ContinueShoppingPrompt(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    EnGirlA* selectedItem;
    u8 talkState = Message_GetState(&globalCtx->msgCtx);

    if (talkState == TEXT_STATE_CHOICE) {
        if (Message_ShouldAdvance(globalCtx)) {
            EnOssan_ResetItemPosition(pthis);
            selectedItem = pthis->shelfSlots[pthis->cursorIndex];
            selectedItem->updateStockedItemFunc(globalCtx, selectedItem);
            if (!EnOssan_TestEndInteraction(pthis, globalCtx, &globalCtx->state.input[0])) {
                switch (globalCtx->msgCtx.choiceIndex) {
                    case 0:
                        osSyncPrintf(VT_FGCOL(YELLOW) "★★★ 続けるよ！！ ★★★" VT_RST "\n");
                        player->actor.shape.rot.y += 0x8000;
                        player->stateFlags2 |= 0x20000000;
                        func_800BC490(globalCtx, 2);
                        Message_StartTextbox(globalCtx, pthis->actor.textId, &pthis->actor);
                        EnOssan_SetStateStartShopping(globalCtx, pthis, true);
                        func_8002F298(&pthis->actor, globalCtx, 100.0f, -1);
                        break;
                    case 1:
                    default:
                        osSyncPrintf(VT_FGCOL(YELLOW) "★★★ やめるよ！！ ★★★" VT_RST "\n");
                        EnOssan_EndInteraction(globalCtx, pthis);
                        break;
                }
            }
        }
    } else if (talkState == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        EnOssan_ResetItemPosition(pthis);
        selectedItem = pthis->shelfSlots[pthis->cursorIndex];
        selectedItem->updateStockedItemFunc(globalCtx, selectedItem);
        player->actor.shape.rot.y += 0x8000;
        player->stateFlags2 |= 0x20000000;
        func_800BC490(globalCtx, 2);
        Message_StartTextbox(globalCtx, pthis->actor.textId, &pthis->actor);
        EnOssan_SetStateStartShopping(globalCtx, pthis, true);
        func_8002F298(&pthis->actor, globalCtx, 100.0f, -1);
    }
}

void EnOssan_State_WaitForDisplayOnlyBombDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        gSaveContext.infTable[15] |= 0x1000;
        EnOssan_StartShopping(globalCtx, pthis);
    }
}

// Unreachable
void EnOssan_State_21(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE_HAS_NEXT && Message_ShouldAdvance(globalCtx)) {
        pthis->stateFlag = OSSAN_STATE_22;
        Message_ContinueTextbox(globalCtx, 0x3012);
        gSaveContext.infTable[15] |= 0x1000;
    }
}

// Unreachable
void EnOssan_State_22(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        EnOssan_StartShopping(globalCtx, pthis);
    }
}

void EnOssan_State_GiveLonLonMilk(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        EnOssan_GiveItemWithFanfare(globalCtx, pthis);
    }
}

// For giving Mask of Truth when you first sell all masks
void EnOssan_State_LendMaskOfTruth(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT && Message_ShouldAdvance(globalCtx)) {
        gSaveContext.itemGetInf[2] |= 0x400;
        pthis->cursorIndex = 2;
        EnOssan_GiveItemWithFanfare(globalCtx, pthis);
    }
}

// Hylian Shield discount dialog
void EnOssan_SetStateGiveDiscountDialog(GlobalContext* globalCtx, EnOssan* pthis) {
    Message_ContinueTextbox(globalCtx, 0x71B2);
    pthis->stateFlag = OSSAN_STATE_DISCOUNT_DIALOG;
}

void EnOssan_State_GiveDiscountDialog(EnOssan* pthis, GlobalContext* globalCtx, Player* player) {
    EnGirlA* selectedItem;

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        selectedItem = pthis->shelfSlots[pthis->cursorIndex];
        EnOssan_GiveItemWithFanfare(globalCtx, pthis);
        pthis->drawCursor = 0;
        pthis->shopItemSelectedTween = 0.0f;
        selectedItem->setOutOfStockFunc(globalCtx, selectedItem);
    }
}

void EnOssan_PositionSelectedItem(EnOssan* pthis) {
    EnGirlA* item;
    u8 i;
    u8 i2;
    ShopItem* shopItem;
    f32 tx;
    f32 ty;
    f32 tz;

    i = pthis->cursorIndex;
    shopItem = &sShopkeeperStores[pthis->actor.params][i];
    item = pthis->shelfSlots[i];

    i2 = i >> 2;
    tx = (sSelectedItemPosition[i2].x - shopItem->xOffset) * pthis->shopItemSelectedTween + shopItem->xOffset;
    ty = (sSelectedItemPosition[i2].y - shopItem->yOffset) * pthis->shopItemSelectedTween + shopItem->yOffset;
    tz = (sSelectedItemPosition[i2].z - shopItem->zOffset) * pthis->shopItemSelectedTween + shopItem->zOffset;

    item->actor.world.pos.x = pthis->shelves->actor.world.pos.x + tx;
    item->actor.world.pos.y = pthis->shelves->actor.world.pos.y + ty;
    item->actor.world.pos.z = pthis->shelves->actor.world.pos.z + tz;
}

void EnOssan_ResetItemPosition(EnOssan* pthis) {
    pthis->shopItemSelectedTween = 0.0f;
    EnOssan_PositionSelectedItem(pthis);
}

// returns true if animation has completed
s32 EnOssan_TakeItemOffShelf(EnOssan* pthis) {
    Math_ApproachF(&pthis->shopItemSelectedTween, 1.0f, 1.0f, 0.15f);
    if (pthis->shopItemSelectedTween >= 0.85f) {
        pthis->shopItemSelectedTween = 1.0f;
    }
    EnOssan_PositionSelectedItem(pthis);
    if (pthis->shopItemSelectedTween == 1.0f) {
        return true;
    } else {
        return false;
    }
}

// returns true if animation has completed
s32 EnOssan_ReturnItemToShelf(EnOssan* pthis) {
    Math_ApproachF(&pthis->shopItemSelectedTween, 0.0f, 1.0f, 0.15f);
    if (pthis->shopItemSelectedTween <= 0.15f) {
        pthis->shopItemSelectedTween = 0.0f;
    }
    EnOssan_PositionSelectedItem(pthis);
    if (pthis->shopItemSelectedTween == 0.0f) {
        return true;
    } else {
        return false;
    }
}

void EnOssan_UpdateItemSelectedProperty(EnOssan* pthis) {
    EnGirlA** temp_a1 = pthis->shelfSlots;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (temp_a1[0] != NULL) {
            if (pthis->stateFlag != OSSAN_STATE_SELECT_ITEM && pthis->stateFlag != OSSAN_STATE_SELECT_ITEM_MILK_BOTTLE &&
                pthis->stateFlag != OSSAN_STATE_SELECT_ITEM_WEIRD_EGG &&
                pthis->stateFlag != OSSAN_STATE_SELECT_ITEM_UNIMPLEMENTED &&
                pthis->stateFlag != OSSAN_STATE_SELECT_ITEM_BOMBS && pthis->stateFlag != OSSAN_STATE_SELECT_ITEM_MASK &&
                pthis->stateFlag != OSSAN_STATE_CANT_GET_ITEM && pthis->drawCursor == 0) {
                temp_a1[0]->isSelected = false;
            } else {
                if (pthis->cursorIndex == i) {
                    temp_a1[0]->isSelected = true;
                } else {
                    temp_a1[0]->isSelected = false;
                }
            }
        }
        temp_a1++;
    }
}

void EnOssan_UpdateCursorAnim(EnOssan* pthis) {
    f32 t;

    t = pthis->cursorAnimTween;
    if (pthis->cursorAnimState == 0) {
        t += 0.05f;
        if (t >= 1.0f) {
            t = 1.0f;
            pthis->cursorAnimState = 1;
        }
    } else {
        t -= 0.05f;
        if (t <= 0.0f) {
            t = 0.0f;
            pthis->cursorAnimState = 0;
        }
    }
    pthis->cursorColorR = ColChanMix(0, 0.0f, t);
    pthis->cursorColorG = ColChanMix(80, 0.0f, t);
    pthis->cursorColorB = ColChanMix(255, 80.0f, t);
    pthis->cursorColorA = ColChanMix(255, 0.0f, t);
    pthis->cursorAnimTween = t;
}

void EnOssan_UpdateStickDirectionPromptAnim(EnOssan* pthis) {
    f32 arrowAnimTween;
    f32 new_var3;       // likely fake temp
    s32 new_var2 = 255; // likely fake temp
    f32 stickAnimTween;

    arrowAnimTween = pthis->arrowAnimTween;
    stickAnimTween = pthis->stickAnimTween;
    if (pthis->arrowAnimState == 0) {
        arrowAnimTween += 0.05f;
        if (arrowAnimTween > 1.0f) {
            arrowAnimTween = 1.0f;
            pthis->arrowAnimState = 1;
        }

    } else {
        arrowAnimTween -= 0.05f;
        if (arrowAnimTween < 0.0f) {
            arrowAnimTween = 0.0f;
            pthis->arrowAnimState = 0;
        }
    }

    pthis->arrowAnimTween = arrowAnimTween;
    if (pthis->stickAnimState == 0) {
        stickAnimTween += 0.1f;
        if (stickAnimTween > 1.0f) {
            stickAnimTween = 1.0f;
            pthis->stickAnimState = 1;
        }

    } else {
        stickAnimTween = 0.0f;
        pthis->stickAnimState = 0;
    }

    pthis->stickAnimTween = stickAnimTween;
    pthis->stickLeftPrompt.arrowColorR = (u8)(255 - ((s32)(155.0f * arrowAnimTween)));
    pthis->stickLeftPrompt.arrowColorG = (u8)(new_var2 - (s32)(155.0f * arrowAnimTween));
    new_var3 = (155.0f * arrowAnimTween);
    pthis->stickLeftPrompt.arrowColorB = (u8)(0 - ((s32)((-100.0f) * arrowAnimTween)));
    pthis->stickLeftPrompt.arrowColorA = (u8)(200 - ((s32)(50.0f * arrowAnimTween)));
    pthis->stickRightPrompt.arrowColorR = (u8)(new_var2 - (s32)new_var3);
    pthis->stickRightPrompt.arrowColorG = (u8)(255 - (s32)new_var3);
    pthis->stickRightPrompt.arrowColorB = (u8)(0 - ((s32)((-100.0f) * arrowAnimTween)));
    pthis->stickRightPrompt.arrowColorA = (u8)(200 - ((s32)(50.0f * arrowAnimTween)));
    pthis->stickRightPrompt.arrowTexX = 290.0f;
    pthis->stickLeftPrompt.arrowTexX = 33.0f;
    pthis->stickRightPrompt.stickTexX = 274.0f;
    pthis->stickLeftPrompt.stickTexX = 49.0f;
    pthis->stickRightPrompt.stickTexX += (8.0f * stickAnimTween);
    pthis->stickLeftPrompt.stickTexX -= (8.0f * stickAnimTween);
    pthis->stickLeftPrompt.arrowTexY = pthis->stickRightPrompt.arrowTexY = 91.0f;
    pthis->stickLeftPrompt.stickTexY = pthis->stickRightPrompt.stickTexY = 95.0f;
}

void EnOssan_WaitForBlink(EnOssan* pthis) {
    s16 decr = pthis->blinkTimer - 1;

    if (decr != 0) {
        pthis->blinkTimer = decr;
    } else {
        pthis->blinkFunc = EnOssan_Blink;
    }
}

void EnOssan_Blink(EnOssan* pthis) {
    s16 decr;
    s16 eyeTextureIdxTemp;

    decr = pthis->blinkTimer - 1;
    if (decr != 0) {
        pthis->blinkTimer = decr;
        return;
    }
    eyeTextureIdxTemp = pthis->eyeTextureIdx + 1;
    if (eyeTextureIdxTemp > 2) {
        pthis->eyeTextureIdx = 0;
        pthis->blinkTimer = (s32)(Rand_ZeroOne() * 60.0f) + 20;
        pthis->blinkFunc = EnOssan_WaitForBlink;
    } else {
        pthis->eyeTextureIdx = eyeTextureIdxTemp;
        pthis->blinkTimer = 1;
    }
}

s32 EnOssan_AreShopkeeperObjectsLoaded(EnOssan* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex1)) {
        if (pthis->objBankIndex2 >= 0 && !Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex2)) {
            return false;
        }
        if (pthis->objBankIndex3 >= 0 && !Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex3)) {
            return false;
        }
        return true;
    }
    return false;
}

void EnOssan_InitBazaarShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gObjectOssanSkel, &gObjectOssanAnim_000338, NULL, NULL, 0);
    pthis->actor.draw = EnOssan_DrawBazaarShopkeeper;
    pthis->obj3ToSeg6Func = NULL;
}

void EnOssan_InitKokiriShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gKm1Skel, NULL, NULL, NULL, 0);
    gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[pthis->objBankIndex3].vromStart.get());
    Animation_Change(&pthis->skelAnime, &object_masterkokiri_Anim_0004A8, 1.0f, 0.0f,
                     Animation_GetLastFrame(&object_masterkokiri_Anim_0004A8), 0, 0.0f);
    pthis->actor.draw = EnOssan_DrawKokiriShopkeeper;
    pthis->obj3ToSeg6Func = EnOssan_Obj3ToSeg6;
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ELF, pthis->actor.world.pos.x,
                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, FAIRY_KOKIRI);
}

void EnOssan_InitGoronShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGoronSkel, NULL, NULL, NULL, 0);
    gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[pthis->objBankIndex3].vromStart.get());
    Animation_Change(&pthis->skelAnime, &gGoronShopkeeperAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGoronShopkeeperAnim),
                     0, 0.0f);
    pthis->actor.draw = EnOssan_DrawGoronShopkeeper;
    pthis->obj3ToSeg6Func = EnOssan_Obj3ToSeg6;
}

void EnOssan_InitZoraShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gZoraSkel, NULL, NULL, NULL, 0);
    gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[pthis->objBankIndex3].vromStart.get());
    Animation_Change(&pthis->skelAnime, &gZoraShopkeeperAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gZoraShopkeeperAnim),
                     0, 0.0f);
    pthis->actor.draw = EnOssan_DrawZoraShopkeeper;
    pthis->obj3ToSeg6Func = EnOssan_Obj3ToSeg6;
}

void EnOssan_InitPotionShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ds2_Skel_004258, &object_ds2_Anim_0002E4, 0, 0, 0);
    pthis->actor.draw = EnOssan_DrawPotionShopkeeper;
    pthis->obj3ToSeg6Func = NULL;
}

void EnOssan_InitHappyMaskShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_os_Skel_004658, &object_os_Anim_0002E4, NULL, NULL, 0);
    pthis->actor.draw = EnOssan_DrawHappyMaskShopkeeper;
    pthis->obj3ToSeg6Func = NULL;
}

void EnOssan_InitBombchuShopkeeper(EnOssan* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_rs_Skel_004868, &object_rs_Anim_00065C, 0, 0, 0);
    pthis->actor.draw = EnOssan_DrawBombchuShopkeeper;
    pthis->obj3ToSeg6Func = NULL;
}

u16 EnOssan_SetupHelloDialog(EnOssan* pthis) {
    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_NONE;
    // mask shop messages
    if (pthis->actor.params == OSSAN_TYPE_MASK) {
        if (INV_CONTENT(ITEM_TRADE_CHILD) == ITEM_SOLD_OUT) {
            if (gSaveContext.itemGetInf[3] & 0x800) {
                if (!(gSaveContext.eventChkInf[8] & 0x8000)) {
                    // Pay back Bunny Hood
                    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_REQUEST_PAYMENT_BUNNY_HOOD;
                    return 0x70C6;
                } else {
                    return 0x70AC;
                }
            }
            if (gSaveContext.itemGetInf[3] & 0x400) {
                if (!(gSaveContext.eventChkInf[8] & 0x4000)) {
                    // Pay back Spooky Mask
                    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SPOOKY_MASK;
                    return 0x70C5;
                } else {
                    return 0x70AC;
                }
            }
            if (gSaveContext.itemGetInf[3] & 0x200) {
                if (!(gSaveContext.eventChkInf[8] & 0x2000)) {
                    // Pay back Skull Mask
                    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_REQUEST_PAYMENT_SKULL_MASK;
                    return 0x70C4;
                } else {
                    return 0x70AC;
                }
            }
            if (gSaveContext.itemGetInf[3] & 0x100) {
                if (!(gSaveContext.eventChkInf[8] & 0x1000)) {
                    // Pay back Keaton Mask
                    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_REQUEST_PAYMENT_KEATON_MASK;
                    return 0x70A5;
                } else {
                    return 0x70AC;
                }
            }
        } else {
            if (gSaveContext.itemGetInf[3] & 0x800) {
                return 0x70AC;
            } else if (!(gSaveContext.itemGetInf[3] & 0x400) && !(gSaveContext.itemGetInf[2] & 0x10) &&
                       !(gSaveContext.itemGetInf[3] & 0x100)) {
                // Haven't borrowed the Keaton Mask
                if (!(gSaveContext.itemGetInf[2] & 0x8)) {
                    return 0x70A1;
                } else {
                    // Haven't sold the Keaton Mask
                    pthis->happyMaskShopState = OSSAN_HAPPY_STATE_BORROWED_FIRST_MASK;
                    return 0x70A6;
                }
            } else {
                return 0x70C7;
            }
        }
    }

    return 0x9E;
}

void EnOssan_InitActionFunc(EnOssan* pthis, GlobalContext* globalCtx) {
    ShopItem* items;

    if (EnOssan_AreShopkeeperObjectsLoaded(pthis, globalCtx)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.objBankIndex = pthis->objBankIndex1;
        Actor_SetObjectDependency(globalCtx, &pthis->actor);

        pthis->shelves = (EnTana*)Actor_Find(&globalCtx->actorCtx, ACTOR_EN_TANA, ACTORCAT_PROP);

        if (pthis->shelves == NULL) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "Warning!! There are no shelves!!"
            osSyncPrintf("★★★ 警告！！ 棚がないよ！！ ★★★\n");
            osSyncPrintf(VT_RST);
            return;
        }

        // "Shopkeeper (params) init"
        osSyncPrintf(VT_FGCOL(YELLOW) "◇◇◇ 店のおやじ( %d ) 初期設定 ◇◇◇" VT_RST "\n", pthis->actor.params);

        pthis->actor.world.pos.x += sShopkeeperPositionOffsets[pthis->actor.params].x;
        pthis->actor.world.pos.y += sShopkeeperPositionOffsets[pthis->actor.params].y;
        pthis->actor.world.pos.z += sShopkeeperPositionOffsets[pthis->actor.params].z;

        items = sShopkeeperStores[pthis->actor.params];

        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
        sInitFuncs[pthis->actor.params](pthis, globalCtx);
        pthis->actor.textId = EnOssan_SetupHelloDialog(pthis);
        pthis->cursorY = pthis->cursorX = 100.0f;
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        pthis->actor.colChkInfo.cylRadius = 50;
        pthis->stateFlag = OSSAN_STATE_IDLE;
        pthis->stickAccumX = pthis->stickAccumY = 0;

        pthis->cursorIndex = 0;
        pthis->cursorZ = 1.5f;
        pthis->cursorColorR = 0;
        pthis->cursorColorG = 255;
        pthis->cursorColorB = 80;
        pthis->cursorColorA = 255;
        pthis->cursorAnimTween = 0;

        pthis->cursorAnimState = 0;
        pthis->drawCursor = 0;
        pthis->happyMaskShopkeeperEyeIdx = 0;

        pthis->stickLeftPrompt.stickColorR = 200;
        pthis->stickLeftPrompt.stickColorG = 200;
        pthis->stickLeftPrompt.stickColorB = 200;
        pthis->stickLeftPrompt.stickColorA = 180;
        pthis->stickLeftPrompt.stickTexX = 49;
        pthis->stickLeftPrompt.stickTexY = 95;
        pthis->stickLeftPrompt.arrowColorR = 255;
        pthis->stickLeftPrompt.arrowColorG = 255;
        pthis->stickLeftPrompt.arrowColorB = 0;
        pthis->stickLeftPrompt.arrowColorA = 200;
        pthis->stickLeftPrompt.arrowTexX = 33;
        pthis->stickLeftPrompt.arrowTexY = 91;
        pthis->stickLeftPrompt.z = 1;
        pthis->stickLeftPrompt.isEnabled = false;

        pthis->stickRightPrompt.stickColorR = 200;
        pthis->stickRightPrompt.stickColorG = 200;
        pthis->stickRightPrompt.stickColorB = 200;
        pthis->stickRightPrompt.stickColorA = 180;
        pthis->stickRightPrompt.stickTexX = 274;
        pthis->stickRightPrompt.stickTexY = 95;
        pthis->stickRightPrompt.arrowColorR = 255;
        pthis->stickRightPrompt.arrowColorG = 255;
        pthis->stickRightPrompt.arrowColorB = 0;
        pthis->stickRightPrompt.arrowColorA = 200;
        pthis->stickRightPrompt.arrowTexX = 290;
        pthis->stickRightPrompt.arrowTexY = 91;
        pthis->stickRightPrompt.z = 1;
        pthis->stickRightPrompt.isEnabled = false;

        pthis->arrowAnimState = 0;
        pthis->stickAnimState = 0;
        pthis->arrowAnimTween = 0;
        pthis->stickAnimTween = 0;
        pthis->shopItemSelectedTween = 0;
        Actor_SetScale(&pthis->actor, sShopkeeperScale[pthis->actor.params]);
        EnOssan_SpawnItemsOnShelves(pthis, globalCtx, items);
        pthis->headRot = pthis->headTargetRot = 0;
        pthis->blinkTimer = 20;
        pthis->eyeTextureIdx = 0;
        pthis->blinkFunc = EnOssan_WaitForBlink;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        EnOssan_SetupAction(pthis, EnOssan_MainActionFunc);
    }
}

void EnOssan_Obj3ToSeg6(EnOssan* pthis, GlobalContext* globalCtx) {
    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndex3].vromStart.get());
}

void EnOssan_MainActionFunc(EnOssan* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->blinkFunc(pthis);
    EnOssan_UpdateJoystickInputState(globalCtx, pthis);
    EnOssan_UpdateItemSelectedProperty(pthis);
    EnOssan_UpdateStickDirectionPromptAnim(pthis);
    EnOssan_UpdateCursorAnim(pthis);
    Math_StepToS(&pthis->headRot, pthis->headTargetRot, 0x190);

    if (player != NULL) {
        sStateFunc[pthis->stateFlag](pthis, globalCtx, player);
    }

    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 26.0f, 10.0f, 0.0f, 5);
    Actor_SetFocus(&pthis->actor, 90.0f);
    Actor_SetScale(&pthis->actor, sShopkeeperScale[pthis->actor.params]);

    // use animation object if needed
    if (pthis->obj3ToSeg6Func != NULL) {
        pthis->obj3ToSeg6Func(pthis, globalCtx);
    }

    SkelAnime_Update(&pthis->skelAnime);
}

void EnOssan_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;

    pthis->timer++;
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnOssan_OverrideLimbDrawDefaultShopkeeper(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos,
                                              Vec3s* rot, void* thisx) {
    EnOssan* pthis = (EnOssan*)thisx;

    if (limbIndex == 8) {
        rot->x += pthis->headRot;
    }
    return 0;
}

void EnOssan_DrawCursor(GlobalContext* globalCtx, EnOssan* pthis, f32 x, f32 y, f32 z, u8 drawCursor) {
    s32 ulx, uly, lrx, lry;
    f32 w;
    s32 dsdx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4192);
    if (drawCursor != 0) {
        func_80094520(globalCtx->state.gfxCtx);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, pthis->cursorColorR, pthis->cursorColorG, pthis->cursorColorB,
                        pthis->cursorColorA);
        gDPLoadTextureBlock_4b(OVERLAY_DISP++, gSelectionCursorTex, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP,
                               G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
        w = 16.0f * z;
        ulx = (x - w) * 4.0f;
        uly = (y - w) * 4.0f;
        lrx = (x + w) * 4.0f;
        lry = (y + w) * 4.0f;
        dsdx = (1.0f / z) * 1024.0f;
        gSPTextureRectangle(OVERLAY_DISP++, ulx, uly, lrx, lry, G_TX_RENDERTILE, 0, 0, dsdx, dsdx);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4215);
}

void EnOssan_DrawTextRec(GlobalContext* globalCtx, s32 r, s32 g, s32 b, s32 a, f32 x, f32 y, f32 z, s32 s, s32 t,
                         f32 dx, f32 dy) {
    f32 unk;
    s32 ulx, uly, lrx, lry;
    f32 w, h;
    s32 dsdx, dtdy;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4228);
    gDPPipeSync(OVERLAY_DISP++);
    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, r, g, b, a);

    w = 8.0f * z;
    h = 12.0f * z;
    unk = (1.0f / z) * 1024;
    dsdx = unk * dx;
    dtdy = dy * unk;

    ulx = (x - w) * 4.0f;
    uly = (y - h) * 4.0f;
    lrx = (x + w) * 4.0f;
    lry = (y + h) * 4.0f;
    gSPTextureRectangle(OVERLAY_DISP++, ulx, uly, lrx, lry, G_TX_RENDERTILE, s, t, dsdx, dtdy);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4242);
}

void EnOssan_DrawStickDirectionPrompts(GlobalContext* globalCtx, EnOssan* pthis) {
    s32 drawStickLeftPrompt = pthis->stickLeftPrompt.isEnabled;
    s32 drawStickRightPrompt = pthis->stickRightPrompt.isEnabled;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4252);
    if (drawStickLeftPrompt || drawStickRightPrompt) {
        func_80094520(globalCtx->state.gfxCtx);
        gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPLoadTextureBlock(OVERLAY_DISP++, gArrowCursorTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 24, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        if (drawStickLeftPrompt) {
            EnOssan_DrawTextRec(globalCtx, pthis->stickLeftPrompt.arrowColorR, pthis->stickLeftPrompt.arrowColorG,
                                pthis->stickLeftPrompt.arrowColorB, pthis->stickLeftPrompt.arrowColorA,
                                pthis->stickLeftPrompt.arrowTexX, pthis->stickLeftPrompt.arrowTexY,
                                pthis->stickLeftPrompt.z, 0, 0, -1.0f, 1.0f);
        }
        if (drawStickRightPrompt) {
            EnOssan_DrawTextRec(globalCtx, pthis->stickRightPrompt.arrowColorR, pthis->stickRightPrompt.arrowColorG,
                                pthis->stickRightPrompt.arrowColorB, pthis->stickRightPrompt.arrowColorA,
                                pthis->stickRightPrompt.arrowTexX, pthis->stickRightPrompt.arrowTexY,
                                pthis->stickRightPrompt.z, 0, 0, 1.0f, 1.0f);
        }
        gDPLoadTextureBlock(OVERLAY_DISP++, gControlStickTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        if (drawStickLeftPrompt) {
            EnOssan_DrawTextRec(globalCtx, pthis->stickLeftPrompt.stickColorR, pthis->stickLeftPrompt.stickColorG,
                                pthis->stickLeftPrompt.stickColorB, pthis->stickLeftPrompt.stickColorA,
                                pthis->stickLeftPrompt.stickTexX, pthis->stickLeftPrompt.stickTexY,
                                pthis->stickLeftPrompt.z, 0, 0, -1.0f, 1.0f);
        }
        if (drawStickRightPrompt) {
            EnOssan_DrawTextRec(globalCtx, pthis->stickRightPrompt.stickColorR, pthis->stickRightPrompt.stickColorG,
                                pthis->stickRightPrompt.stickColorB, pthis->stickRightPrompt.stickColorA,
                                pthis->stickRightPrompt.stickTexX, pthis->stickRightPrompt.stickTexY,
                                pthis->stickRightPrompt.z, 0, 0, 1.0f, 1.0f);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4300);
}

void EnOssan_DrawBazaarShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4320);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sBazaarShopkeeperEyeTextures_238[pthis->eyeTextureIdx]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnOssan_OverrideLimbDrawDefaultShopkeeper, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4340);
}

s32 EnOssan_OverrideLimbDrawKokiriShopkeeper(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos,
                                             Vec3s* rot, void* thisx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4354);

    if (limbIndex == 15) {
        gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->objBankIndex2].vromStart.get());
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objBankIndex2].vromStart.get());
        *dList = gKokiriShopkeeperHeadDL;
        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(sKokiriShopkeeperEyeTextures_239[pthis->eyeTextureIdx]));
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4374);

    return 0;
}

Gfx* EnOssan_EndDList(GraphicsContext* gfxCtx) {
    Gfx* disp = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx));

    gSPEndDisplayList(disp);
    return disp;
}

Gfx* EnOssan_SetEnvColor(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b, u8 a) {
	Gfx* disp = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 2);

    gDPSetEnvColor(disp, r, g, b, a);
    gSPEndDisplayList(disp + 1);
    return disp;
}

void EnOssan_DrawKokiriShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4409);

    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x08, EnOssan_SetEnvColor(globalCtx->state.gfxCtx, 0, 130, 70, 255));
    gSPSegment(POLY_OPA_DISP++, 0x09, EnOssan_SetEnvColor(globalCtx->state.gfxCtx, 110, 170, 20, 255));
    gSPSegment(POLY_OPA_DISP++, 0x0C, EnOssan_EndDList(globalCtx->state.gfxCtx));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnOssan_OverrideLimbDrawKokiriShopkeeper, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4434);
}

void EnOssan_DrawGoronShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4455);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sGoronShopkeeperEyeTextures_243[pthis->eyeTextureIdx]));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gGoronCsMouthNeutralTex));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4476);
}

s32 EnOssan_OverrideLimbDrawZoraShopkeeper(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                           void* thisx) {
    EnOssan* pthis = (EnOssan*)thisx;

    if (limbIndex == 15) {
        rot->x += pthis->headRot;
    }
    return 0;
}

void EnOssan_DrawZoraShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4506);

    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, EnOssan_EndDList(globalCtx->state.gfxCtx));
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sZoraShopkeeperEyeTextures_245[pthis->eyeTextureIdx]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnOssan_OverrideLimbDrawZoraShopkeeper, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4531);
}

void EnOssan_DrawPotionShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4544);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sPotionShopkeeperEyeTextures_246[pthis->eyeTextureIdx]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4564);
}

void EnOssan_DrawHappyMaskShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4578);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08,
               SEGMENTED_TO_VIRTUAL(sHappyMaskShopkeeperEyeTextures_247[pthis->happyMaskShopkeeperEyeIdx]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4598);
}

void EnOssan_DrawBombchuShopkeeper(Actor* thisx, GlobalContext* globalCtx) {
    EnOssan* pthis = (EnOssan*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4611);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sBombchuShopkeeperEyeTextures_248[pthis->eyeTextureIdx]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, pthis);
    EnOssan_DrawCursor(globalCtx, pthis, pthis->cursorX, pthis->cursorY, pthis->cursorZ, pthis->drawCursor);
    EnOssan_DrawStickDirectionPrompts(globalCtx, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_oB1.c", 4631);
}

void EnOssan_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Ossan_InitVars = {
        ACTOR_EN_OSSAN,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnOssan),
        (ActorFunc)EnOssan_Init,
        (ActorFunc)EnOssan_Destroy,
        (ActorFunc)EnOssan_Update,
        NULL,
        (ActorFunc)EnOssan_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 30, 80, 0, { 0, 0, 0 } },
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GIRLA_Z_EN_GIRLA_C
#include "actor_common.h"
/*
 * File: z_en_girla.c
 * Overlay: En_GirlA
 * Description: Shop Items
 */

#include "z_en_girla.h"
#include "vt.h"
#include "def/code_80097A00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_draw.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnGirlA_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGirlA_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGirlA_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGirlA_Update(Actor* thisx, GlobalContext* globalCtx);

void EnGirlA_SetItemOutOfStock(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_UpdateStockedItem(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_InitializeItemAction(EnGirlA* pthis, GlobalContext* globalCtx);
void EnGirlA_Update2(EnGirlA* pthis, GlobalContext* globalCtx);
void func_80A3C498(Actor* thisx, GlobalContext* globalCtx, s32 flags);
void EnGirlA_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnGirlA_CanBuy_Arrows(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Bombs(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_DekuNuts(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_DekuSticks(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Fish(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_RedPotion(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_GreenPotion(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_BluePotion(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Longsword(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_HylianShield(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_DekuShield(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Health(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_MilkBottle(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_WeirdEgg(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Unk19(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Unk20(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Bombchus(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_DekuSeeds(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_SoldOut(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_BlueFire(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Bugs(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Poe(GlobalContext* globalCtx, EnGirlA* pthis);
s32 EnGirlA_CanBuy_Fairy(GlobalContext* globalCtx, EnGirlA* pthis);

void EnGirlA_ItemGive_DekuNuts(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Arrows(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Bombs(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_DekuSticks(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_BottledItem(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Longsword(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_HylianShield(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_DekuShield(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Health(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_MilkBottle(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_WeirdEgg(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Unk19(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_Unk20(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_ItemGive_DekuSeeds(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_BuyEvent_ShieldDiscount(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_BuyEvent_ObtainBombchuPack(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_BuyEvent_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis);
void EnGirlA_BuyEvent_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis);

ActorInit En_GirlA_InitVars = {
    ACTOR_EN_GIRLA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnGirlA),
    (ActorFunc)EnGirlA_Init,
    (ActorFunc)EnGirlA_Destroy,
    (ActorFunc)EnGirlA_Update,
    NULL,
    (ActorFunc)EnGirlA_Reset,
};

static const char* sShopItemDescriptions[] = {
    "デクの実×5   ",  // "Deku nut x5"
    "矢×30        ",  // "Arrow x30"
    "矢×50        ",  // "Arrow x50"
    "爆弾×5       ",  // "bomb"
    "デクの実×10  ",  // "Deku nut x10"
    "デクの棒      ", // "Deku stick"
    "爆弾×10      ",  // "Bomb x10"
    "さかな        ", // "Fish"
    "赤クスリ      ", // "Red medicine"
    "緑クスリ      ", // "Green medicine"
    "青クスリ      ", // "Blue medicine"
    "巨人のナイフ  ", // "Giant knife"
    "ハイリアの盾  ", // "Hyria Shield"
    "デクの盾      ", // "Deku Shield"
    "ゴロンの服    ", // "Goron's clothes"
    "ゾ─ラの服    ",  // "Zora's clothes"
    "回復のハート  ", // "Heart of recovery"
    "ロンロン牛乳  ", // "Ron Ron milk"
    "鶏の卵        ", // "Chicken egg"
    "インゴー牛乳  ", // "Ingo milk"
    "インゴー卵    ", // "Ingo egg"
    "もだえ石      ", // "Modae stone"
    "大人の財布    ", // "Adult wallet"
    "ハートの欠片  ", // "Heart fragment"
    "ボムチュウ    ", // "Bombchu"
    "ボムチュウ    ", // "Bombchu"
    "ボムチュウ    ", // "Bombchu"
    "ボムチュウ    ", // "Bombchu"
    "ボムチュウ    ", // "Bombchu"
    "デクのタネ    ", // "Deku seeds"
    "キータンのお面", // "Ketan's mask"
    "こわそなお面  ", // "Scary face"
    "ドクロのお面  ", // "Skull mask"
    "ウサギずきん  ", // "Rabbit hood"
    "まことの仮面  ", // "True mask"
    "ゾーラのお面  ", // "Zora's mask"
    "ゴロンのお面  ", // "Goron's mask"
    "ゲルドのお面  ", // "Gerd's mask"
    "ＳＯＬＤＯＵＴ",
    "炎            ", // "Flame"
    "虫            ", // "Bugs"
    "チョウチョ    ", // "Butterfly"
    "ポウ          ", // "Poe"
    "妖精の魂      ", // "Fairy soul"
    "矢×10        ",  // "Arrow"
    "爆弾×20      ",  // "Bomb x20"
    "爆弾×30      ",  // "Bomb x30"
    "爆弾×5       ",  // "Bomb x5"
    "赤クスリ      ", // "Red medicine"
    "赤クスリ      "  // "Red medicine"
};

static s16 sMaskShopItems[8] = {
    ITEM_MASK_KEATON, ITEM_MASK_SPOOKY, ITEM_MASK_SKULL, ITEM_MASK_BUNNY,
    ITEM_MASK_TRUTH,  ITEM_MASK_ZORA,   ITEM_MASK_GORON, ITEM_MASK_GERUDO,
};

static u16 sMaskShopFreeToBorrowTextIds[5] = { 0x70B6, 0x70B5, 0x70B4, 0x70B7, 0x70BB }; 

static ShopItemEntry shopItemEntries[] = {
    // SI_DEKU_NUTS_5
    { OBJECT_GI_NUTS, GID_NUTS, func_8002ED80, 15, 5, 0x00B2, 0x007F, GI_NUTS_5_2, EnGirlA_CanBuy_DekuNuts,
      EnGirlA_ItemGive_DekuNuts, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_ARROWS_30 */
    { OBJECT_GI_ARROW, GID_ARROWS_MEDIUM, func_8002EBCC, 60, 30, 0x00C1, 0x009B, GI_ARROWS_MEDIUM,
      EnGirlA_CanBuy_Arrows, EnGirlA_ItemGive_Arrows, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_ARROWS_50 */
    { OBJECT_GI_ARROW, GID_ARROWS_LARGE, func_8002EBCC, 90, 50, 0x00B0, 0x007D, GI_ARROWS_LARGE, EnGirlA_CanBuy_Arrows,
      EnGirlA_ItemGive_Arrows, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBS_5_R25 */
    { OBJECT_GI_BOMB_1, GID_BOMB, func_8002EBCC, 25, 5, 0x00A3, 0x008B, GI_BOMBS_5, EnGirlA_CanBuy_Bombs,
      EnGirlA_ItemGive_Bombs, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_DEKU_NUTS_10 */
    { OBJECT_GI_NUTS, GID_NUTS, func_8002ED80, 30, 10, 0x00A2, 0x0087, GI_NUTS_10, EnGirlA_CanBuy_DekuNuts,
      EnGirlA_ItemGive_DekuNuts, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_DEKU_STICK */
    { OBJECT_GI_STICK, GID_STICK, NULL, 10, 1, 0x00A1, 0x0088, GI_STICKS_1, EnGirlA_CanBuy_DekuSticks,
      EnGirlA_ItemGive_DekuSticks, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBS_10 */
    { OBJECT_GI_BOMB_1, GID_BOMB, func_8002EBCC, 50, 10, 0x00B1, 0x007C, GI_BOMBS_10, EnGirlA_CanBuy_Bombs,
      EnGirlA_ItemGive_Bombs, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_FISH */
    { OBJECT_GI_FISH, GID_FISH, func_8002ED80, 200, 1, 0x00B3, 0x007E, GI_FISH, EnGirlA_CanBuy_Fish, NULL,
      EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_RED_POTION_R30 */
    { OBJECT_GI_LIQUID, GID_POTION_RED, func_8002EBCC, 30, 1, 0x00A5, 0x008E, GI_POTION_RED, EnGirlA_CanBuy_RedPotion,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_GREEN_POTION */
    { OBJECT_GI_LIQUID, GID_POTION_GREEN, func_8002EBCC, 30, 1, 0x00A6, 0x008F, GI_POTION_GREEN,
      EnGirlA_CanBuy_GreenPotion, EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BLUE_POTION */
    { OBJECT_GI_LIQUID, GID_POTION_BLUE, func_8002EBCC, 60, 1, 0x00A7, 0x0090, GI_POTION_BLUE,
      EnGirlA_CanBuy_BluePotion, EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_LONGSWORD */
    { OBJECT_GI_LONGSWORD, GID_SWORD_BGS, func_8002EBCC, 1000, 1, 0x00A8, 0x0091, GI_SWORD_KNIFE,
      EnGirlA_CanBuy_Longsword, EnGirlA_ItemGive_Longsword, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_HYLIAN_SHIELD */
    { OBJECT_GI_SHIELD_2, GID_SHIELD_HYLIAN, func_8002EBCC, 80, 1, 0x00A9, 0x0092, GI_SHIELD_HYLIAN,
      EnGirlA_CanBuy_HylianShield, EnGirlA_ItemGive_HylianShield, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_DEKU_SHIELD */
    { OBJECT_GI_SHIELD_1, GID_SHIELD_DEKU, func_8002EBCC, 40, 1, 0x009F, 0x0089, GI_SHIELD_DEKU,
      EnGirlA_CanBuy_DekuShield, EnGirlA_ItemGive_DekuShield, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_GORON_TUNIC */
    { OBJECT_GI_CLOTHES, GID_TUNIC_GORON, NULL, 200, 1, 0x00AA, 0x0093, GI_TUNIC_GORON, EnGirlA_CanBuy_GoronTunic,
      EnGirlA_ItemGive_GoronTunic, EnGirlA_BuyEvent_GoronTunic },
    /* SI_ZORA_TUNIC */
    { OBJECT_GI_CLOTHES, GID_TUNIC_ZORA, NULL, 300, 1, 0x00AB, 0x0094, GI_TUNIC_ZORA, EnGirlA_CanBuy_ZoraTunic,
      EnGirlA_ItemGive_ZoraTunic, EnGirlA_BuyEvent_ZoraTunic },
    /* SI_HEART */
    { OBJECT_GI_HEART, GID_HEART, NULL, 10, 16, 0x00AC, 0x0095, GI_HEART, EnGirlA_CanBuy_Health,
      EnGirlA_ItemGive_Health, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_MILK_BOTTLE */
    { OBJECT_GI_MILK, GID_MILK, func_80A3C498, 100, 1, 0x00AD, 0x0097, GI_MILK_BOTTLE, EnGirlA_CanBuy_MilkBottle,
      EnGirlA_ItemGive_MilkBottle, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_WEIRD_EGG */
    { OBJECT_GI_EGG, GID_EGG, func_8002EBCC, 100, 1, 0x00AE, 0x0099, GI_WEIRD_EGG, EnGirlA_CanBuy_WeirdEgg,
      EnGirlA_ItemGive_WeirdEgg, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_19 */
    { OBJECT_GI_MILK, GID_MILK, func_80A3C498, 10000, 1, 0x00B4, 0x0085, GI_NONE, EnGirlA_CanBuy_Unk19,
      EnGirlA_ItemGive_Unk19, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_20 */
    { OBJECT_GI_EGG, GID_EGG, func_8002EBCC, 10000, 1, 0x00B5, 0x0085, GI_NONE, EnGirlA_CanBuy_Unk20,
      EnGirlA_ItemGive_Unk20, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBCHU_10_1 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 100, 10, 0x00BC, 0x008C, GI_BOMBCHUS_10, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_20_1 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 180, 20, 0x0061, 0x002A, GI_BOMBCHUS_20, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_20_2 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 180, 20, 0x0061, 0x002A, GI_BOMBCHUS_20, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_10_2 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 100, 10, 0x00BC, 0x008C, GI_BOMBCHUS_10, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_10_3 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 100, 10, 0x00BC, 0x008C, GI_BOMBCHUS_10, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_20_3 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 180, 20, 0x0061, 0x002A, GI_BOMBCHUS_20, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_20_4 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 180, 20, 0x0061, 0x002A, GI_BOMBCHUS_20, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_BOMBCHU_10_4 */
    { OBJECT_GI_BOMB_2, GID_BOMBCHU, func_8002EBCC, 100, 10, 0x00BC, 0x008C, GI_BOMBCHUS_10, EnGirlA_CanBuy_Bombchus,
      NULL, EnGirlA_BuyEvent_ObtainBombchuPack },
    /* SI_DEKU_SEEDS_30 */
    { OBJECT_GI_SEED, GID_SEEDS, func_8002EBCC, 30, 30, 0x00DF, 0x00DE, GI_SEEDS_30, EnGirlA_CanBuy_DekuSeeds,
      EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_KEATON_MASK */
    { OBJECT_GI_KI_TAN_MASK, GID_MASK_KEATON, func_8002EBCC, 0, 1, 0x70B2, 0x70BE, GI_MASK_KEATON,
      EnGirlA_CanBuy_DekuSeeds, EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_SPOOKY_MASK */
    { OBJECT_GI_REDEAD_MASK, GID_MASK_SPOOKY, func_8002EBCC, 0, 1, 0x70B1, 0x70BD, GI_MASK_SPOOKY,
      EnGirlA_CanBuy_DekuSeeds, EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_SKULL_MASK */
    { OBJECT_GI_SKJ_MASK, GID_MASK_SKULL, func_8002EBCC, 0, 1, 0x70B0, 0x70BC, GI_MASK_SKULL, EnGirlA_CanBuy_DekuSeeds,
      EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BUNNY_HOOD */
    { OBJECT_GI_RABIT_MASK, GID_MASK_BUNNY, func_8002EBCC, 0, 1, 0x70B3, 0x70BF, GI_MASK_BUNNY,
      EnGirlA_CanBuy_DekuSeeds, EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_MASK_OF_TRUTH */
    { OBJECT_GI_TRUTH_MASK, GID_MASK_TRUTH, func_80A3C498, 0, 1, 0x70AF, 0x70C3, GI_MASK_TRUTH,
      EnGirlA_CanBuy_DekuSeeds, EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_ZORA_MASK */
    { OBJECT_GI_ZORAMASK, GID_MASK_ZORA, NULL, 0, 1, 0x70B9, 0x70C1, GI_MASK_ZORA, EnGirlA_CanBuy_DekuSeeds,
      EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_GORON_MASK */
    { OBJECT_GI_GOLONMASK, GID_MASK_GORON, NULL, 0, 1, 0x70B8, 0x70C0, GI_MASK_GORON, EnGirlA_CanBuy_DekuSeeds,
      EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_GERUDO_MASK */
    { OBJECT_GI_GERUDOMASK, GID_MASK_GERUDO, NULL, 0, 1, 0x70BA, 0x70C2, GI_MASK_GERUDO, EnGirlA_CanBuy_DekuSeeds,
      EnGirlA_ItemGive_DekuSeeds, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_SOLD_OUT */
    { OBJECT_GI_SOLDOUT, GID_SOLDOUT, func_8002EBCC, 0, 0, 0x00BD, 0x70C2, GI_MASK_GERUDO, EnGirlA_CanBuy_SoldOut, NULL,
      NULL },
    /* SI_BLUE_FIRE */
    { OBJECT_GI_FIRE, GID_BLUE_FIRE, func_8002EBCC, 300, 1, 0x00B9, 0x00B8, GI_BLUE_FIRE, EnGirlA_CanBuy_BlueFire,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BUGS */
    { OBJECT_GI_INSECT, GID_BUG, func_80A3C498, 50, 1, 0x00BB, 0x00BA, GI_BUGS, EnGirlA_CanBuy_Bugs,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BIG_POE */
    { OBJECT_GI_GHOST, GID_BIG_POE, func_80A3C498, 50, 1, 0x506F, 0x5070, GI_BIG_POE, EnGirlA_CanBuy_Poe,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_POE */
    { OBJECT_GI_GHOST, GID_POE, func_80A3C498, 30, 1, 0x506D, 0x506E, GI_POE, EnGirlA_CanBuy_Poe,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_FAIRY */
    { OBJECT_GI_SOUL, GID_FAIRY, func_80A3C498, 50, 1, 0x00B7, 0x00B6, GI_FAIRY, EnGirlA_CanBuy_Fairy,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_ARROWS_10 */
    { OBJECT_GI_ARROW, GID_ARROWS_SMALL, func_8002EBCC, 20, 10, 0x00A0, 0x008A, GI_ARROWS_SMALL, EnGirlA_CanBuy_Arrows,
      EnGirlA_ItemGive_Arrows, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBS_20 */
    { OBJECT_GI_BOMB_1, GID_BOMB, func_8002EBCC, 80, 20, 0x001C, 0x0006, GI_BOMBS_20, EnGirlA_CanBuy_Bombs,
      EnGirlA_ItemGive_Bombs, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBS_30 */
    { OBJECT_GI_BOMB_1, GID_BOMB, func_8002EBCC, 120, 30, 0x001D, 0x001E, GI_BOMBS_30, EnGirlA_CanBuy_Bombs,
      EnGirlA_ItemGive_Bombs, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_BOMBS_5_R35 */
    { OBJECT_GI_BOMB_1, GID_BOMB, func_8002EBCC, 35, 5, 0x00CB, 0x00CA, GI_BOMBS_5, EnGirlA_CanBuy_Bombs,
      EnGirlA_ItemGive_Bombs, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_RED_POTION_R40 */
    { OBJECT_GI_LIQUID, GID_POTION_RED, func_8002EBCC, 40, 1, 0x0064, 0x0062, GI_POTION_RED, EnGirlA_CanBuy_RedPotion,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount },
    /* SI_RED_POTION_R50 */
    { OBJECT_GI_LIQUID, GID_POTION_RED, func_8002EBCC, 50, 1, 0x0065, 0x0063, GI_POTION_RED, EnGirlA_CanBuy_RedPotion,
      EnGirlA_ItemGive_BottledItem, EnGirlA_BuyEvent_ShieldDiscount }
};

// Defines the Hylian Shield discount amount
static s16 sShieldDiscounts[] = { 5, 10, 15, 20, 25, 30, 35, 40 };

void EnGirlA_SetupAction(EnGirlA* pthis, EnGirlAActionFunc func) {
    pthis->actionFunc = func;
}

s32 EnGirlA_TryChangeShopItem(EnGirlA* pthis) {
    switch (pthis->actor.params) {
        case SI_MILK_BOTTLE:
            if (gSaveContext.itemGetInf[0] & 0x4) {
                pthis->actor.params = SI_HEART;
                return true;
            }
            break;
        case SI_BOMBCHU_10_2:
            if (gSaveContext.itemGetInf[0] & 0x40) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_10_3:
            if (gSaveContext.itemGetInf[0] & 0x80) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_20_3:
            if (gSaveContext.itemGetInf[0] & 0x100) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_20_4:
            if (gSaveContext.itemGetInf[0] & 0x200) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_10_4:
            if (gSaveContext.itemGetInf[0] & 0x400) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_10_1:
            if (gSaveContext.itemGetInf[0] & 0x8) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_20_1:
            if (gSaveContext.itemGetInf[0] & 0x10) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
        case SI_BOMBCHU_20_2:
            if (gSaveContext.itemGetInf[0] & 0x20) {
                pthis->actor.params = SI_SOLD_OUT;
                return true;
            }
            break;
    }
    return false;
}

void EnGirlA_InitItem(EnGirlA* pthis, GlobalContext* globalCtx) {
    s16 params = pthis->actor.params;

    osSyncPrintf("%s(%2d)初期設定\n", sShopItemDescriptions[params], params);

    if ((params >= SI_MAX) && (params < 0)) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("引数がおかしいよ(arg_data=%d)！！\n", pthis->actor.params);
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_girlA.c", 1421);
        return;
    }

    pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, shopItemEntries[params].objID);

    if (pthis->objBankIndex < 0) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("バンクが無いよ！！(%s)\n", sShopItemDescriptions[params]);
        osSyncPrintf(VT_RST);
        ASSERT(0, "0", "../z_en_girlA.c", 1434);
        return;
    }

    pthis->actor.params = params;
    pthis->actionFunc2 = EnGirlA_InitializeItemAction;
}

void EnGirlA_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGirlA* pthis = (EnGirlA*)thisx;

    EnGirlA_TryChangeShopItem(pthis);
    EnGirlA_InitItem(pthis, globalCtx);
    osSyncPrintf("%s(%2d)初期設定\n", sShopItemDescriptions[pthis->actor.params], pthis->actor.params);
}

void EnGirlA_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGirlA* pthis = (EnGirlA*)thisx;

    if (pthis->isInitialized) {
        SkelAnime_Free(&pthis->skelAnime, globalCtx);
    }
}

s32 EnGirlA_CanBuy_Arrows(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (Item_CheckObtainability(ITEM_BOW) == ITEM_NONE) {
        return CANBUY_RESULT_CANT_GET_NOW_5;
    }
    if (AMMO(ITEM_BOW) >= CUR_CAPACITY(UPG_QUIVER)) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Bombs(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (AMMO(ITEM_BOMB) >= CUR_CAPACITY(UPG_BOMB_BAG)) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_DekuNuts(GlobalContext* globalCtx, EnGirlA* pthis) {
    if ((CUR_CAPACITY(UPG_NUTS) != 0) && (AMMO(ITEM_NUT) >= CUR_CAPACITY(UPG_NUTS))) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_NUT) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_DekuSticks(GlobalContext* globalCtx, EnGirlA* pthis) {
    if ((CUR_CAPACITY(UPG_STICKS) != 0) && (AMMO(ITEM_STICK) >= CUR_CAPACITY(UPG_STICKS))) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_STICK) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Fish(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_FISH) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_RedPotion(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_POTION_RED) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_GreenPotion(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_POTION_GREEN) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_BluePotion(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_POTION_BLUE) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Longsword(GlobalContext* globalCtx, EnGirlA* pthis) {
    if ((gBitFlags[2] & gSaveContext.inventory.equipment) && !(gBitFlags[3] & gSaveContext.inventory.equipment)) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_SWORD_BGS) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_HylianShield(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (gBitFlags[5] & gSaveContext.inventory.equipment) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_SHIELD_HYLIAN) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_DekuShield(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (gBitFlags[4] & gSaveContext.inventory.equipment) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_SHIELD_DEKU) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gBitFlags[9] & gSaveContext.inventory.equipment) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_TUNIC_GORON) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gBitFlags[10] & gSaveContext.inventory.equipment) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_TUNIC_ZORA) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Health(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (gSaveContext.healthCapacity == gSaveContext.health) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_MilkBottle(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_MILK_BOTTLE) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_WeirdEgg(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_LETTER_ZELDA) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Unk19(GlobalContext* globalCtx, EnGirlA* pthis) {
    return CANBUY_RESULT_NEED_RUPEES;
}

s32 EnGirlA_CanBuy_Unk20(GlobalContext* globalCtx, EnGirlA* pthis) {
    return CANBUY_RESULT_NEED_RUPEES;
}

s32 EnGirlA_CanBuy_Bombchus(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (AMMO(ITEM_BOMBCHU) >= 50) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_BOMBCHU) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_DekuSeeds(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (AMMO(ITEM_SLINGSHOT) >= CUR_CAPACITY(UPG_BULLET_BAG)) {
        return CANBUY_RESULT_CANT_GET_NOW;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_SEEDS) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_SoldOut(GlobalContext* globalCtx, EnGirlA* pthis) {
    return CANBUY_RESULT_CANT_GET_NOW_5;
}

s32 EnGirlA_CanBuy_BlueFire(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_BLUE_FIRE) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Bugs(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_BUG) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Poe(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_POE) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

s32 EnGirlA_CanBuy_Fairy(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_BOTTLE;
    }
    if (gSaveContext.rupees < pthis->basePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_FAIRY) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_FANFARE;
    }
    return CANBUY_RESULT_SUCCESS;
}

void EnGirlA_ItemGive_Arrows(GlobalContext* globalCtx, EnGirlA* pthis) {
    Inventory_ChangeAmmo(ITEM_BOW, pthis->itemCount);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_Bombs(GlobalContext* globalCtx, EnGirlA* pthis) {
    switch (pthis->itemCount) {
        case 5:
            Item_Give(globalCtx, ITEM_BOMBS_5);
            break;
        case 10:
            Item_Give(globalCtx, ITEM_BOMBS_10);
            break;
        case 20:
            Item_Give(globalCtx, ITEM_BOMBS_20);
            break;
        case 30:
            Item_Give(globalCtx, ITEM_BOMBS_30);
            break;
    }
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_DekuNuts(GlobalContext* globalCtx, EnGirlA* pthis) {
    switch (pthis->itemCount) {
        case 5:
            Item_Give(globalCtx, ITEM_NUTS_5);
            break;
        case 10:
            Item_Give(globalCtx, ITEM_NUTS_10);
            break;
    }
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_DekuSticks(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_STICK);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_Longsword(GlobalContext* globalCtx, EnGirlA* pthis) {
    func_800849EC(globalCtx);
    gSaveContext.swordHealth = 8;
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_HylianShield(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_SHIELD_HYLIAN);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_DekuShield(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_SHIELD_DEKU);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_TUNIC_GORON);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_TUNIC_ZORA);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_Health(GlobalContext* globalCtx, EnGirlA* pthis) {
    Health_ChangeBy(globalCtx, pthis->itemCount);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_MilkBottle(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_MILK_BOTTLE);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_WeirdEgg(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_WEIRD_EGG);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_Unk19(GlobalContext* globalCtx, EnGirlA* pthis) {
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_Unk20(GlobalContext* globalCtx, EnGirlA* pthis) {
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_DekuSeeds(GlobalContext* globalCtx, EnGirlA* pthis) {
    Item_Give(globalCtx, ITEM_SEEDS_30);
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_ItemGive_BottledItem(GlobalContext* globalCtx, EnGirlA* pthis) {
    switch (pthis->actor.params) {
        case SI_FISH:
            Item_Give(globalCtx, ITEM_FISH);
            break;
        case SI_RED_POTION_R30:
            Item_Give(globalCtx, ITEM_POTION_RED);
            break;
        case SI_GREEN_POTION:
            Item_Give(globalCtx, ITEM_POTION_GREEN);
            break;
        case SI_BLUE_POTION:
            Item_Give(globalCtx, ITEM_POTION_BLUE);
            break;
        case SI_BLUE_FIRE:
            Item_Give(globalCtx, ITEM_BLUE_FIRE);
            break;
        case SI_BUGS:
            Item_Give(globalCtx, ITEM_BUG);
            break;
        case SI_BIG_POE:
            Item_Give(globalCtx, ITEM_BIG_POE);
            break;
        case SI_POE:
            Item_Give(globalCtx, ITEM_POE);
            break;
        case SI_FAIRY:
            Item_Give(globalCtx, ITEM_FAIRY);
            break;
    }
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_BuyEvent_ShieldDiscount(GlobalContext* globalCtx, EnGirlA* pthis) {
    if (pthis->actor.params == SI_HYLIAN_SHIELD) {
        if (gSaveContext.infTable[7] & 0x40) {
            Rupees_ChangeBy(-(pthis->basePrice - sShieldDiscounts[(s32)Rand_ZeroFloat(7.9f)]));
            return;
        }
    }
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_BuyEvent_GoronTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_BuyEvent_ZoraTunic(GlobalContext* globalCtx, EnGirlA* pthis) {
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_BuyEvent_ObtainBombchuPack(GlobalContext* globalCtx, EnGirlA* pthis) {
    switch (pthis->actor.params) {
        case SI_BOMBCHU_10_2:
            gSaveContext.itemGetInf[0] |= 0x40;
            break;
        case SI_BOMBCHU_10_3:
            gSaveContext.itemGetInf[0] |= 0x80;
            break;
        case SI_BOMBCHU_20_3:
            gSaveContext.itemGetInf[0] |= 0x100;
            break;
        case SI_BOMBCHU_20_4:
            gSaveContext.itemGetInf[0] |= 0x200;
            break;
        case SI_BOMBCHU_10_4:
            gSaveContext.itemGetInf[0] |= 0x400;
            break;
        case SI_BOMBCHU_10_1:
            gSaveContext.itemGetInf[0] |= 0x8;
            break;
        case SI_BOMBCHU_20_1:
            gSaveContext.itemGetInf[0] |= 0x10;
            break;
        case SI_BOMBCHU_20_2:
            gSaveContext.itemGetInf[0] |= 0x20;
            break;
    }
    Rupees_ChangeBy(-pthis->basePrice);
}

void EnGirlA_Noop(EnGirlA* pthis, GlobalContext* globalCtx) {
}

void EnGirlA_SetItemDescription(GlobalContext* globalCtx, EnGirlA* pthis) {
    ShopItemEntry* tmp = &shopItemEntries[pthis->actor.params];
    s32 params = pthis->actor.params;
    s32 maskId;
    s32 isMaskFreeToBorrow;

    if ((pthis->actor.params >= SI_KEATON_MASK) && (pthis->actor.params <= SI_MASK_OF_TRUTH)) {
        maskId = pthis->actor.params - SI_KEATON_MASK;
        isMaskFreeToBorrow = false;
        switch (pthis->actor.params) {
            case SI_KEATON_MASK:
                if (gSaveContext.itemGetInf[3] & 0x100) {
                    isMaskFreeToBorrow = true;
                }
                break;
            case SI_SPOOKY_MASK:
                if (gSaveContext.itemGetInf[3] & 0x400) {
                    isMaskFreeToBorrow = true;
                }
                break;
            case SI_SKULL_MASK:
                if (gSaveContext.itemGetInf[3] & 0x200) {
                    isMaskFreeToBorrow = true;
                }
                break;
            case SI_BUNNY_HOOD:
                if (gSaveContext.itemGetInf[3] & 0x800) {
                    isMaskFreeToBorrow = true;
                }
                break;
            case SI_MASK_OF_TRUTH:
                if (gSaveContext.itemGetInf[3] & 0x800) {
                    isMaskFreeToBorrow = true;
                }
                break;
        }
        if (isMaskFreeToBorrow) {
            pthis->actor.textId = sMaskShopFreeToBorrowTextIds[maskId];
        } else {
            pthis->actor.textId = tmp->itemDescTextId;
        }
    } else {
        pthis->actor.textId = tmp->itemDescTextId;
    }
    pthis->isInvisible = false;
    pthis->actor.draw = EnGirlA_Draw;
}

void EnGirlA_SetItemOutOfStock(GlobalContext* globalCtx, EnGirlA* pthis) {
    pthis->isInvisible = true;
    pthis->actor.draw = NULL;
    if ((pthis->actor.params >= SI_KEATON_MASK) && (pthis->actor.params <= SI_GERUDO_MASK)) {
        pthis->actor.textId = 0xBD;
    }
}

void EnGirlA_UpdateStockedItem(GlobalContext* globalCtx, EnGirlA* pthis) {
    ShopItemEntry* itemEntry;

    if (EnGirlA_TryChangeShopItem(pthis)) {
        EnGirlA_InitItem(pthis, globalCtx);
        itemEntry = &shopItemEntries[pthis->actor.params];
        pthis->actor.textId = itemEntry->itemDescTextId;
    } else {
        pthis->isInvisible = false;
        pthis->actor.draw = EnGirlA_Draw;
    }
}

s32 EnGirlA_TrySetMaskItemDescription(EnGirlA* pthis, GlobalContext* globalCtx) {
    s32 params;

    if ((pthis->actor.params >= SI_KEATON_MASK) && (pthis->actor.params <= SI_GERUDO_MASK)) {
        params = pthis->actor.params - SI_KEATON_MASK;
        if (INV_CONTENT(ITEM_TRADE_CHILD) == sMaskShopItems[params]) {
            EnGirlA_SetItemOutOfStock(globalCtx, pthis);
        } else {
            EnGirlA_SetItemDescription(globalCtx, pthis);
        }
        return true;
    }
    return false;
}

void EnGirlA_InitializeItemAction(EnGirlA* pthis, GlobalContext* globalCtx) {
    s16 params = pthis->actor.params;
    ShopItemEntry* itemEntry = &shopItemEntries[params];

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.objBankIndex = pthis->objBankIndex;
        switch (pthis->actor.params) {
            case SI_KEATON_MASK:
                if (gSaveContext.itemGetInf[3] & 0x100) {
                    pthis->actor.textId = 0x70B6;
                } else {
                    pthis->actor.textId = itemEntry->itemDescTextId;
                }
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_SPOOKY_MASK:
                if (gSaveContext.itemGetInf[3] & 0x400) {
                    pthis->actor.textId = 0x70B5;
                } else {
                    pthis->actor.textId = itemEntry->itemDescTextId;
                }
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_SKULL_MASK:
                if (gSaveContext.itemGetInf[3] & 0x200) {
                    pthis->actor.textId = 0x70B4;
                } else {
                    pthis->actor.textId = itemEntry->itemDescTextId;
                }
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_BUNNY_HOOD:
                if (gSaveContext.itemGetInf[3] & 0x800) {
                    pthis->actor.textId = 0x70B7;
                } else {
                    pthis->actor.textId = itemEntry->itemDescTextId;
                }
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_MASK_OF_TRUTH:
                if (gSaveContext.itemGetInf[3] & 0x800) {
                    pthis->actor.textId = 0x70BB;
                    pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                } else {
                    pthis->actor.textId = itemEntry->itemDescTextId;
                    pthis->itemBuyPromptTextId = 0xEB;
                }
                break;
            case SI_ZORA_MASK:
                pthis->actor.textId = itemEntry->itemDescTextId;
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_GORON_MASK:
                pthis->actor.textId = itemEntry->itemDescTextId;
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            case SI_GERUDO_MASK:
                pthis->actor.textId = itemEntry->itemDescTextId;
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
            default:
                pthis->actor.textId = itemEntry->itemDescTextId;
                pthis->itemBuyPromptTextId = itemEntry->itemBuyPromptTextId;
                break;
        }
        if (!EnGirlA_TrySetMaskItemDescription(pthis, globalCtx)) {
            EnGirlA_SetItemDescription(globalCtx, pthis);
        }

        pthis->setOutOfStockFunc = EnGirlA_SetItemOutOfStock;
        pthis->updateStockedItemFunc = EnGirlA_UpdateStockedItem;
        pthis->getItemId = itemEntry->getItemId;
        pthis->canBuyFunc = itemEntry->canBuyFunc;
        pthis->itemGiveFunc = itemEntry->itemGiveFunc;
        pthis->buyEventFunc = itemEntry->buyEventFunc;
        pthis->basePrice = itemEntry->price;
        pthis->itemCount = itemEntry->count;
        pthis->hiliteFunc = itemEntry->hiliteFunc;
        pthis->giDrawId = itemEntry->giDrawId;
        osSyncPrintf("%s(%2d)\n", sShopItemDescriptions[params], params);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        Actor_SetScale(&pthis->actor, 0.25f);
        pthis->actor.shape.yOffset = 24.0f;
        pthis->actor.shape.shadowScale = 4.0f;
        pthis->actor.floorHeight = pthis->actor.home.pos.y;
        pthis->actor.gravity = 0.0f;
        EnGirlA_SetupAction(pthis, EnGirlA_Noop);
        pthis->isInitialized = true;
        pthis->actionFunc2 = EnGirlA_Update2;
        pthis->isSelected = false;
        pthis->yRotation = 0;
        pthis->yRotationInit = pthis->actor.shape.rot.y;
    }
}

void EnGirlA_Update2(EnGirlA* pthis, GlobalContext* globalCtx) {
    Actor_SetScale(&pthis->actor, 0.25f);
    pthis->actor.shape.yOffset = 24.0f;
    pthis->actor.shape.shadowScale = 4.0f;
    EnGirlA_TrySetMaskItemDescription(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 5.0f);
    pthis->actor.shape.rot.x = 0.0f;
    if (pthis->actor.params != SI_SOLD_OUT) {
        if (pthis->isSelected) {
            pthis->yRotation += 0x1F4;
        } else {
            Math_SmoothStepToS(&pthis->yRotation, 0, 10, 0x7D0, 0);
        }
    }
}

void EnGirlA_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGirlA* pthis = (EnGirlA*)thisx;

    pthis->actionFunc2(pthis, globalCtx);
}

void func_80A3C498(Actor* thisx, GlobalContext* globalCtx, s32 flags) {
    func_8002EBCC(thisx, globalCtx, 0);
    func_8002ED80(thisx, globalCtx, 0);
}

void EnGirlA_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGirlA* pthis = (EnGirlA*)thisx;

    Matrix_RotateY(((pthis->yRotation * 360.0f) / 65536.0f) * (M_PI / 180.0f), MTXMODE_APPLY);
    if (pthis->hiliteFunc != NULL) {
        pthis->hiliteFunc(thisx, globalCtx, 0);
    }
    GetItem_Draw(globalCtx, pthis->giDrawId);
}

void EnGirlA_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_GirlA_InitVars = {
        ACTOR_EN_GIRLA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnGirlA),
        (ActorFunc)EnGirlA_Init,
        (ActorFunc)EnGirlA_Destroy,
        (ActorFunc)EnGirlA_Update,
        NULL,
        (ActorFunc)EnGirlA_Reset,
    };

}

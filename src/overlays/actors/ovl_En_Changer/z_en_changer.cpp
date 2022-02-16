#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_CHANGER_Z_EN_CHANGER_C
#include "actor_common.h"
/*
 * File: z_en_changer.c
 * Overlay: ovl_En_Changer
 * Description: Treasure Box Shop Minigame
 */

#include "z_en_changer.h"
#include "vt.h"
#include "overlays/actors/ovl_Item_Etcetera/z_item_etcetera.h"
#include "overlays/actors/ovl_En_Ex_Item/z_en_ex_item.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"

#define FLAGS 0


void EnChanger_Init(Actor* thisx, GlobalContext* globalCtx);
void EnChanger_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnChanger_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnChanger_Update(Actor* thisx, GlobalContext* globalCtx);

void EnChanger_Wait(EnChanger* pthis, GlobalContext* globalCtx);
void EnChanger_OpenChests(EnChanger* pthis, GlobalContext* globalCtx);
void EnChanger_SetHeartPieceFlag(EnChanger* pthis, GlobalContext* globalCtx);

ActorInit En_Changer_InitVars = {
    ACTOR_EN_CHANGER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnChanger),
    (ActorFunc)EnChanger_Init,
    (ActorFunc)EnChanger_Destroy,
    (ActorFunc)EnChanger_Update,
    NULL,
    (ActorFunc)EnChanger_Reset,
};

static Vec3f sLeftChestPos[] = {
    { 0.0f, 0.0f, 0.0f },         { -100.0f, 20.0f, -245.0f },  { -100.0f, 20.0f, -685.0f },
    { -100.0f, 20.0f, -1125.0f }, { -100.0f, 20.0f, -1565.0f }, { -100.0f, 20.0f, -2005.0f },
};

static Vec3f sRightChestPos[] = {
    { 0.0f, 0.0f, 0.0f },        { 140.0f, 20.0f, -245.0f },  { 140.0f, 20.0f, -685.0f },
    { 140.0f, 20.0f, -1125.0f }, { 140.0f, 20.0f, -1565.0f }, { 140.0f, 20.0f, -2005.0f },
};

static s32 sLoserGetItemIds[] = {
    GI_NONE, GI_RUPEE_GREEN_LOSE, GI_RUPEE_GREEN_LOSE, GI_RUPEE_BLUE_LOSE, GI_RUPEE_BLUE_LOSE, GI_RUPEE_RED_LOSE,
};

static s32 sItemEtcTypes[] = {
    0,
    ITEM_ETC_RUPEE_GREEN_CHEST_GAME,
    ITEM_ETC_RUPEE_GREEN_CHEST_GAME,
    ITEM_ETC_RUPEE_BLUE_CHEST_GAME,
    ITEM_ETC_RUPEE_BLUE_CHEST_GAME,
    ITEM_ETC_RUPEE_RED_CHEST_GAME,
};

static s32 sTreasureFlags[] = { 0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A };

void EnChanger_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnChanger_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnChanger* pthis = (EnChanger*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s16 leftChestParams;
    s16 rightChestParams;
    s16 rewardChestParams;
    s16 minigameRoomNum;
    s16 rightChestItem;
    s16 leftChestItem;
    s16 temp_v1_3;
    s16 new_var;
    s32 rewardParams;

    if (1) {}

    minigameRoomNum = globalCtx->roomCtx.curRoom.num - 1;
    if (minigameRoomNum < 0) {
        minigameRoomNum = 0;
    }
    if (Flags_GetTreasure(globalCtx, sTreasureFlags[minigameRoomNum])) {
        pthis->roomChestsOpened = true;
    }

    osSyncPrintf("\n\n");
    // "Treasure generation (which room is it?)"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 宝発生(部屋はどれ？) %d\n" VT_RST, globalCtx->roomCtx.curRoom.num);
    // "How is the Bit?"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ビットは？ \t     %x\n" VT_RST, globalCtx->actorCtx.flags.chest);
    // "How is the Save BIT?"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ セーブＢＩＴは？     %x\n" VT_RST, sTreasureFlags[minigameRoomNum]);
    // "Is it already a zombie?"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ もう、ゾンビ？\t     %d\n" VT_RST, pthis->roomChestsOpened);
    osSyncPrintf("\n\n");

    minigameRoomNum *= 2;
    // Spawn Heart Piece in chest (or Purple Rupee if won Heart Piece)
    if (globalCtx->roomCtx.curRoom.num >= 6) {
        rewardChestParams = ((gSaveContext.itemGetInf[1] & 0x800) ? (0x4EA0) : (0x4EC0));
        rewardChestParams = sTreasureFlags[5] | rewardChestParams;
        pthis->finalChest = (EnBox*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_BOX,
                                                      20.0f, 20.0f, -2500.0f, 0, 0x7FFF, 0, rewardChestParams);
        if (pthis->finalChest != NULL) {
            if (pthis->roomChestsOpened) {
                Flags_SetTreasure(globalCtx, rewardChestParams & 0x1F);
                Actor_Kill(&pthis->actor);
                return;
            } else {
                rewardParams = ((gSaveContext.itemGetInf[1] & 0x800) ? (ITEM_ETC_RUPEE_PURPLE_CHEST_GAME)
                                                                     : (ITEM_ETC_HEART_PIECE_CHEST_GAME)) &
                               0xFF;
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_ETCETERA, 20.0f, 20.0f, -2500.0f, 0, 0, 0,
                            ((sTreasureFlags[5] & 0x1F) << 8) + rewardParams);
                // "Central treasure instance/occurrence (GREAT)"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 中央宝発生(ＧＲＥＡＴ) ☆☆☆☆☆ %x\n" VT_RST, rewardChestParams);
                pthis->actionFunc = EnChanger_SetHeartPieceFlag;
                return;
            }
        }
    }

    temp_v1_3 = minigameRoomNum;
    // Set up items in chests, swap them round with probability 1/2
    leftChestParams = (sLoserGetItemIds[globalCtx->roomCtx.curRoom.num] << 5) | 0x4000;
    new_var = temp_v1_3;
    pthis->leftChestNum = new_var;
    pthis->leftChestGetItemId = sLoserGetItemIds[globalCtx->roomCtx.curRoom.num];
    leftChestItem = sItemEtcTypes[globalCtx->roomCtx.curRoom.num];
    leftChestParams |= new_var;
    rightChestParams = new_var | 0x4E21;
    pthis->rightChestNum = new_var | 1;
    pthis->rightChestGetItemId = GI_DOOR_KEY;
    rightChestItem = ITEM_ETC_KEY_SMALL_CHEST_GAME;

    if (Rand_ZeroFloat(1.99f) < 1.0f) {
        rightChestParams = (sLoserGetItemIds[globalCtx->roomCtx.curRoom.num] << 5) | 0x4000;
        pthis->rightChestNum = new_var;
        pthis->rightChestGetItemId = sLoserGetItemIds[globalCtx->roomCtx.curRoom.num];
        rightChestItem = sItemEtcTypes[globalCtx->roomCtx.curRoom.num];
        leftChestParams = new_var | 0x4E21;
        rightChestParams |= new_var;
        pthis->leftChestNum = temp_v1_3 | 1;
        pthis->leftChestGetItemId = GI_DOOR_KEY;
        leftChestItem = ITEM_ETC_KEY_SMALL_CHEST_GAME;
    }

    pthis->leftChest = (EnBox*)Actor_SpawnAsChild(
        &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_BOX, sLeftChestPos[globalCtx->roomCtx.curRoom.num].x,
        sLeftChestPos[globalCtx->roomCtx.curRoom.num].y, sLeftChestPos[globalCtx->roomCtx.curRoom.num].z, 0, -0x3FFF, 0,
        leftChestParams);

    if (pthis->leftChest != NULL) {
        // "Left treasure generation (what does it contain?)"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 左宝発生(ナニがはいってるの？) ☆☆☆☆☆ %x\n" VT_RST, leftChestParams);
        // "What is the room number?"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 部屋番号は？  %x\n" VT_RST, globalCtx->roomCtx.curRoom.num);
        // "What is the bit?"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ ビットはなぁに？  %x\n" VT_RST, pthis->rightChestNum);
        // "Sukesuke-kun" (something to do with being invisible)
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ すけすけ君？ %x\n" VT_RST, rightChestItem);
        osSyncPrintf("\n\n");
        if (pthis->roomChestsOpened) {
            Flags_SetTreasure(globalCtx, pthis->leftChestNum & 0x1F);
        } else {
            Actor_Spawn(
                &globalCtx->actorCtx, globalCtx, ACTOR_ITEM_ETCETERA, sLeftChestPos[globalCtx->roomCtx.curRoom.num].x,
                sLeftChestPos[globalCtx->roomCtx.curRoom.num].y, sLeftChestPos[globalCtx->roomCtx.curRoom.num].z, 0, 0,
                0, ((pthis->leftChestNum & 0x1F) << 8) + (leftChestItem & 0xFF));
        }
    }

    pthis->rightChest = (EnBox*)Actor_SpawnAsChild(
        &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_BOX, sRightChestPos[globalCtx->roomCtx.curRoom.num].x,
        sRightChestPos[globalCtx->roomCtx.curRoom.num].y, sRightChestPos[globalCtx->roomCtx.curRoom.num].z, 0, 0x3FFF,
        0, rightChestParams);

    if (pthis->rightChest != NULL) {
        // "Right treasure generation (what does it contain?)"
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 右宝発生(ナニがはいってるの？) ☆☆☆☆☆ %x\n" VT_RST, rightChestParams);
        // "What is the room number?"
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 部屋番号は？  %d\n" VT_RST, globalCtx->roomCtx.curRoom.num);
        // "What is the bit?"
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ ビットはなぁに？  %x\n" VT_RST, pthis->leftChestNum);
        // "Sukesuke-kun" (something to do with being invisible)
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ すけすけ君？ %x\n" VT_RST, leftChestItem);
        osSyncPrintf("\n\n");

        if (pthis->roomChestsOpened) {
            Flags_SetTreasure(globalCtx, pthis->rightChestNum & 0x1F);
            Actor_Kill(&pthis->actor);
            return;
        }

        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_ETCETERA,
                    sRightChestPos[globalCtx->roomCtx.curRoom.num].x, sRightChestPos[globalCtx->roomCtx.curRoom.num].y,
                    sRightChestPos[globalCtx->roomCtx.curRoom.num].z, 0, 0, 0,
                    ((pthis->rightChestNum & 0x1F) << 8) + (rightChestItem & 0xFF));
    }

    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnChanger_Wait;
}

void EnChanger_Wait(EnChanger* pthis, GlobalContext* globalCtx) {
    if (pthis->leftChest->unk_1F4 != 0) {
        pthis->timer = 80;
        Flags_SetTreasure(globalCtx, pthis->rightChestNum & 0x1F);
        pthis->actionFunc = EnChanger_OpenChests;
    } else if (pthis->rightChest->unk_1F4 != 0) {
        pthis->chestOpened = CHEST_RIGHT;
        pthis->timer = 80;
        Flags_SetTreasure(globalCtx, pthis->leftChestNum & 0x1F);
        pthis->actionFunc = EnChanger_OpenChests;
    }
}

// Spawns the EnExItem showing what was in the other chest
void EnChanger_OpenChests(EnChanger* pthis, GlobalContext* globalCtx) {
    f32 zPos;
    f32 yPos;
    f32 xPos;
    s16 temp_s0;
    s16 temp_s0_2;
    EnBox* left;
    EnBox* right;

    left = pthis->leftChest;
    right = pthis->rightChest;

    if (pthis->timer == 0) {
        temp_s0_2 = temp_s0 = pthis->chestOpened; // Required to use the right registers

        switch (temp_s0_2) {
            case CHEST_LEFT:
                xPos = right->dyna.actor.world.pos.x;
                yPos = right->dyna.actor.world.pos.y;
                zPos = right->dyna.actor.world.pos.z;

                if (pthis->rightChestGetItemId == GI_DOOR_KEY) {
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EX_ITEM, xPos, yPos, zPos, 0, 0, 0, 0xF);
                    Flags_SetSwitch(globalCtx, 0x32);
                } else {
                    temp_s0_2 = (s16)(pthis->rightChestGetItemId - GI_RUPEE_GREEN_LOSE) + EXITEM_CHEST;
                    // "Open right treasure (chest)"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 右宝開く ☆☆☆☆☆ %d\n" VT_RST, temp_s0_2);
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EX_ITEM, xPos, yPos, zPos, 0, 0, 0,
                                temp_s0_2);
                }
                break;
            case CHEST_RIGHT:
                xPos = left->dyna.actor.world.pos.x;
                yPos = left->dyna.actor.world.pos.y;
                zPos = left->dyna.actor.world.pos.z;

                if (pthis->leftChestGetItemId == GI_DOOR_KEY) {
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EX_ITEM, xPos, yPos, zPos, 0, 0, 0, 0xF);
                    Flags_SetSwitch(globalCtx, 0x32);
                } else {
                    temp_s0_2 = (s16)(pthis->leftChestGetItemId - 0x72) + 0xA;
                    // "Open left treasure (chest)"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 左宝開く ☆☆☆☆☆ %d\n" VT_RST, temp_s0_2);
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EX_ITEM, xPos, yPos, zPos, 0, 0, 0,
                                temp_s0_2);
                }
                break;
        }

        Actor_Kill(&pthis->actor);
    }
}

void EnChanger_SetHeartPieceFlag(EnChanger* pthis, GlobalContext* globalCtx) {
    if (pthis->finalChest->unk_1F4 != 0) {
        if (!(gSaveContext.itemGetInf[1] & 0x800)) {
            gSaveContext.itemGetInf[1] |= 0x800;
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnChanger_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnChanger* pthis = (EnChanger*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }
}

void EnChanger_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Changer_InitVars = {
        ACTOR_EN_CHANGER,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnChanger),
        (ActorFunc)EnChanger_Init,
        (ActorFunc)EnChanger_Destroy,
        (ActorFunc)EnChanger_Update,
        NULL,
        (ActorFunc)EnChanger_Reset,
    };

}

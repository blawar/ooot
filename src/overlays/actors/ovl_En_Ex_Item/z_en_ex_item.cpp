#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_EX_ITEM_Z_EN_EX_ITEM_C
#include "actor_common.h"
/*
 * File: z_en_ex_item.c
 * Overlay: ovl_En_Ex_Item
 * Description: Minigame prize items
 */

#include "z_en_ex_item.h"
#include "overlays/actors/ovl_En_Bom_Bowl_Pit/z_en_bom_bowl_pit.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "vt.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_draw.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnExItem_Init(Actor* thisx, GlobalContext* globalCtx);
void EnExItem_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnExItem_Update(Actor* thisx, GlobalContext* globalCtx);
void EnExItem_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnExItem_DrawItems(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_DrawHeartPiece(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_DrawRupee(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_DrawKey(EnExItem* pthis, GlobalContext* globalCtx, s32 index);
void EnExItem_DrawMagic(EnExItem* pthis, GlobalContext* globalCtx, s16 magicIndex);

void EnExItem_WaitForObject(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_BowlPrize(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_SetupBowlCounter(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_BowlCounter(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_ExitChest(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_FairyMagic(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_TargetPrizeApproach(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_TargetPrizeGive(EnExItem* pthis, GlobalContext* globalCtx);
void EnExItem_TargetPrizeFinish(EnExItem* pthis, GlobalContext* globalCtx);

ActorInit En_Ex_Item_InitVars = {
    ACTOR_EN_EX_ITEM,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnExItem),
    (ActorFunc)EnExItem_Init,
    (ActorFunc)EnExItem_Destroy,
    (ActorFunc)EnExItem_Update,
    (ActorFunc)EnExItem_Draw,
};

void EnExItem_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnExItem_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnExItem* pthis = (EnExItem*)thisx;

    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->type = pthis->actor.params & 0xFF;
    pthis->unusedParam = (pthis->actor.params >> 8) & 0xFF;
    osSyncPrintf("\n\n");
    // "What will come out?"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ なにがでるかな？ ☆☆☆☆☆ %d\n" VT_RST, pthis->type);
    // "What will come out?"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ なにがでるかな？ ☆☆☆☆☆ %d\n" VT_RST, pthis->unusedParam);
    pthis->initPos = pthis->actor.world.pos;
    pthis->getItemObjId = -1;
    switch (pthis->type) {
        case EXITEM_BOMB_BAG_BOWLING:
        case EXITEM_BOMB_BAG_COUNTER:
            pthis->getItemObjId = OBJECT_GI_BOMBPOUCH;
            break;
        case EXITEM_HEART_PIECE_BOWLING:
        case EXITEM_HEART_PIECE_COUNTER:
            pthis->getItemObjId = OBJECT_GI_HEARTS;
            break;
        case EXITEM_BOMBCHUS_BOWLING:
        case EXITEM_BOMBCHUS_COUNTER:
            pthis->getItemObjId = OBJECT_GI_BOMB_2;
            break;
        case EXITEM_BOMBS_BOWLING:
        case EXITEM_BOMBS_COUNTER:
            pthis->getItemObjId = OBJECT_GI_BOMB_1;
            break;
        case EXITEM_PURPLE_RUPEE_BOWLING:
        case EXITEM_PURPLE_RUPEE_COUNTER:
        case EXITEM_GREEN_RUPEE_CHEST:
        case EXITEM_BLUE_RUPEE_CHEST:
        case EXITEM_RED_RUPEE_CHEST:
        case EXITEM_13:
        case EXITEM_14:
            pthis->getItemObjId = OBJECT_GI_RUPY;
            break;
        case EXITEM_SMALL_KEY_CHEST:
            pthis->scale = 0.05f;
            pthis->actor.velocity.y = 10.0f;
            pthis->timer = 7;
            pthis->actionFunc = EnExItem_ExitChest;
            break;
        case EXITEM_MAGIC_FIRE:
        case EXITEM_MAGIC_WIND:
        case EXITEM_MAGIC_DARK:
            pthis->getItemObjId = OBJECT_GI_GODDESS;
            break;
        case EXITEM_BULLET_BAG:
            pthis->getItemObjId = OBJECT_GI_DEKUPOUCH;
    }

    if (pthis->getItemObjId >= 0) {
        pthis->objectIdx = Object_GetIndex(&globalCtx->objectCtx, pthis->getItemObjId);
        pthis->actor.draw = NULL;
        if (pthis->objectIdx < 0) {
            Actor_Kill(&pthis->actor);
            // "What?"
            osSyncPrintf("なにみの？ %d\n", pthis->actor.params);
            // "bank is funny"
            osSyncPrintf(VT_FGCOL(PURPLE) " バンクおかしいしぞ！%d\n" VT_RST "\n", pthis->actor.params);
            return;
        }
        pthis->actionFunc = EnExItem_WaitForObject;
    }
}

void EnExItem_WaitForObject(EnExItem* pthis, GlobalContext* globalCtx) {
    s32 onCounter;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objectIdx)) {
        // "End of transfer"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 転送終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params, pthis);
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 転送終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params, pthis);
        osSyncPrintf(VT_FGCOL(BLUE) "☆☆☆☆☆ 転送終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params, pthis);
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 転送終了 ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.params, pthis);
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 転送終了 ☆☆☆☆☆ %d\n\n" VT_RST, pthis->actor.params, pthis);
        pthis->actor.objBankIndex = pthis->objectIdx;
        pthis->actor.draw = EnExItem_Draw;
        pthis->stopRotate = false;
        onCounter = false;
        switch (pthis->type) {
            case EXITEM_BOMB_BAG_COUNTER:
                onCounter = true;
            case EXITEM_BOMB_BAG_BOWLING:
                pthis->unk_17C = func_8002EBCC;
                pthis->giDrawId = GID_BOMB_BAG_30;
                pthis->timer = 65;
                pthis->prizeRotateTimer = 35;
                pthis->scale = 0.5f;
                if (onCounter == 0) {
                    pthis->actionFunc = EnExItem_BowlPrize;
                } else {
                    pthis->actionFunc = EnExItem_SetupBowlCounter;
                    pthis->actor.shape.yOffset = -18.0f;
                }
                break;
            case EXITEM_HEART_PIECE_COUNTER:
                onCounter = true;
            case EXITEM_HEART_PIECE_BOWLING:
                pthis->unk_17C = func_8002ED80;
                pthis->timer = 65;
                pthis->prizeRotateTimer = 35;
                pthis->scale = 0.5f;
                if (!onCounter) {
                    func_80078884(NA_SE_SY_PIECE_OF_HEART);
                    pthis->actionFunc = EnExItem_BowlPrize;
                } else {
                    pthis->actionFunc = EnExItem_SetupBowlCounter;
                    pthis->actor.shape.yOffset = -10.0f;
                }
                break;
            case EXITEM_BOMBCHUS_COUNTER:
                onCounter = true;
            case EXITEM_BOMBCHUS_BOWLING:
                pthis->unk_17C = func_8002EBCC;
                pthis->giDrawId = GID_BOMBCHU;
                pthis->timer = 65;
                pthis->prizeRotateTimer = 35;
                pthis->scale = 0.5f;
                if (!onCounter) {
                    pthis->actionFunc = EnExItem_BowlPrize;
                } else {
                    pthis->actionFunc = EnExItem_SetupBowlCounter;
                }
                break;
            case EXITEM_BOMBS_BOWLING:
            case EXITEM_BOMBS_COUNTER:
                pthis->unk_17C = func_8002EBCC;
                pthis->giDrawId = GID_BOMB;
                pthis->timer = 65;
                pthis->prizeRotateTimer = 35;
                pthis->scale = 0.5f;
                pthis->unkFloat = 0.5f;
                if (pthis->type == EXITEM_BOMBS_BOWLING) {
                    pthis->actionFunc = EnExItem_BowlPrize;
                } else {
                    pthis->actionFunc = EnExItem_SetupBowlCounter;
                    pthis->actor.shape.yOffset = 10.0f;
                }
                break;
            case EXITEM_PURPLE_RUPEE_BOWLING:
            case EXITEM_PURPLE_RUPEE_COUNTER:
                pthis->unk_17C = func_8002EBCC;
                pthis->unk_180 = func_8002ED80;
                pthis->giDrawId = GID_RUPEE_PURPLE;
                pthis->timer = 65;
                pthis->prizeRotateTimer = 35;
                pthis->scale = 0.5f;
                pthis->unkFloat = 0.5f;
                if (pthis->type == EXITEM_PURPLE_RUPEE_BOWLING) {
                    pthis->actionFunc = EnExItem_BowlPrize;
                } else {
                    pthis->actionFunc = EnExItem_SetupBowlCounter;
                    pthis->actor.shape.yOffset = 40.0f;
                }
                break;
            case EXITEM_GREEN_RUPEE_CHEST:
            case EXITEM_BLUE_RUPEE_CHEST:
            case EXITEM_RED_RUPEE_CHEST:
            case EXITEM_13:
            case EXITEM_14:
                pthis->unk_17C = func_8002EBCC;
                pthis->unk_180 = func_8002ED80;
                pthis->timer = 7;
                pthis->scale = 0.5f;
                pthis->unkFloat = 0.5f;
                pthis->actor.velocity.y = 10.0f;
                switch (pthis->type) {
                    case EXITEM_GREEN_RUPEE_CHEST:
                        pthis->giDrawId = GID_RUPEE_GREEN;
                        break;
                    case EXITEM_BLUE_RUPEE_CHEST:
                        pthis->giDrawId = GID_RUPEE_BLUE;
                        break;
                    case EXITEM_RED_RUPEE_CHEST:
                        pthis->giDrawId = GID_RUPEE_RED;
                        break;
                    case EXITEM_14:
                        pthis->giDrawId = GID_RUPEE_PURPLE;
                        break;
                }
                pthis->actionFunc = EnExItem_ExitChest;
                break;
            case EXITEM_MAGIC_FIRE:
            case EXITEM_MAGIC_WIND:
            case EXITEM_MAGIC_DARK:
                pthis->scale = 0.35f;
                pthis->actionFunc = EnExItem_FairyMagic;
                break;
            case EXITEM_BULLET_BAG:
                pthis->unk_17C = func_8002EBCC;
                pthis->giDrawId = GID_BULLET_BAG;
                pthis->scale = 0.1f;
                pthis->timer = 80;
                pthis->prizeRotateTimer = 35;
                pthis->actionFunc = EnExItem_TargetPrizeApproach;
                break;
            case EXITEM_SMALL_KEY_CHEST:
                break;
        }
    }
}

void EnExItem_BowlPrize(EnExItem* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 tmpf1;
    f32 tmpf2;
    f32 tmpf3;
    f32 tmpf4;
    f32 tmpf5;
    f32 tmpf6;
    f32 tmpf7;
    f32 sp3C;

    if (!pthis->stopRotate) {
        pthis->actor.shape.rot.y += 0x1000;
        if ((pthis->prizeRotateTimer == 0) && ((pthis->actor.shape.rot.y & 0xFFFF) == 0x9000)) {
            pthis->stopRotate++;
        }
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, 0, 5, 0x1000, 0);
    }
    if (pthis->timer != 0) {
        if (pthis->prizeRotateTimer != 0) {
            sp3C = 250.0f;
            if (pthis->type == EXITEM_BOMBCHUS_BOWLING) {
                sp3C = 220.0f;
            }
            tmpf1 = globalCtx->view.lookAt.x - globalCtx->view.eye.x;
            tmpf2 = globalCtx->view.lookAt.y - globalCtx->view.eye.y;
            tmpf3 = globalCtx->view.lookAt.z + sp3C - globalCtx->view.eye.z;
            tmpf4 = sqrtf(SQ(tmpf1) + SQ(tmpf2) + SQ(tmpf3));

            tmpf5 = (tmpf1 / tmpf4) * 5.0f;
            tmpf6 = (tmpf2 / tmpf4) * 5.0f;
            tmpf7 = (tmpf3 / tmpf4) * 5.0f;

            tmpf1 = globalCtx->view.eye.x + tmpf5 - pthis->actor.world.pos.x;
            tmpf2 = globalCtx->view.eye.y + tmpf6 - pthis->actor.world.pos.y;
            tmpf3 = globalCtx->view.eye.z + tmpf7 - pthis->actor.world.pos.z;

            pthis->actor.world.pos.x += (tmpf1 / tmpf4) * 5.0f;
            pthis->actor.world.pos.y += (tmpf2 / tmpf4) * 5.0f;
            pthis->actor.world.pos.z += (tmpf3 / tmpf4) * 5.0f;
        }
    } else {
        // "parent"
        osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 母親ー？     ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.parent);
        // "Can it move?"
        osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 動いてねー？ ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.parent->update);
        if ((pthis->actor.parent != NULL) && (pthis->actor.parent->update != NULL)) {
            ((EnBomBowlPit*)pthis->actor.parent)->exItemDone = 1;
            // "It can't move!"
            osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ さぁきえるぞ！ ☆☆☆☆☆ \n" VT_RST);
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnExItem_SetupBowlCounter(EnExItem* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = 0x4268;
    pthis->actionFunc = EnExItem_BowlCounter;
}

void EnExItem_BowlCounter(EnExItem* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += 0x800;
    if (pthis->killItem) {
        Actor_Kill(&pthis->actor);
    }
}

void EnExItem_ExitChest(EnExItem* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += 0x1000;
    if (pthis->timer != 0) {
        if (pthis->timer == 1) {
            pthis->chestKillTimer = 20;
        }
    } else {
        pthis->actor.velocity.y = 0.0f;
        if (pthis->chestKillTimer == 0) {
            Actor_Kill(&pthis->actor);
        }
    }
    Actor_MoveForward(&pthis->actor);
}

void EnExItem_FairyMagic(EnExItem* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.rot.y += 0x800;
}

void EnExItem_TargetPrizeApproach(EnExItem* pthis, GlobalContext* globalCtx) {
    f32 tmpf1;
    f32 tmpf2;
    f32 tmpf3;
    f32 tmpf4;
    f32 tmpf5;
    f32 tmpf6;
    f32 tmpf7;

    Math_ApproachF(&pthis->scale, 0.8f, 0.1f, 0.02f);
    if (!pthis->stopRotate) {
        pthis->actor.shape.rot.y += 0x1000;
        if ((pthis->prizeRotateTimer == 0) && ((pthis->actor.shape.rot.y & 0xFFFF) == 0x9000)) {
            pthis->stopRotate++;
        }
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, -0x4000, 5, 0x1000, 0);
    }

    if (pthis->timer != 0) {
        if (pthis->prizeRotateTimer != 0) {
            tmpf1 = globalCtx->view.lookAt.x - globalCtx->view.eye.x;
            tmpf2 = globalCtx->view.lookAt.y - 10.0f - globalCtx->view.eye.y;
            tmpf3 = globalCtx->view.lookAt.z + 10.0f - globalCtx->view.eye.z;
            tmpf4 = sqrtf(SQ(tmpf1) + SQ(tmpf2) + SQ(tmpf3));

            tmpf5 = (tmpf1 / tmpf4) * 5.0f;
            tmpf6 = (tmpf2 / tmpf4) * 5.0f;
            tmpf7 = (tmpf3 / tmpf4) * 5.0f;

            tmpf1 = globalCtx->view.eye.x + tmpf5 - pthis->actor.world.pos.x;
            tmpf2 = globalCtx->view.eye.y - 10.0f + tmpf6 - pthis->actor.world.pos.y;
            tmpf3 = globalCtx->view.eye.z + 10.0f + tmpf7 - pthis->actor.world.pos.z;

            pthis->actor.world.pos.x += (tmpf1 / tmpf4) * 5.0f;
            pthis->actor.world.pos.y += (tmpf2 / tmpf4) * 5.0f;
            pthis->actor.world.pos.z += (tmpf3 / tmpf4) * 5.0f;
        }
    } else {
        s32 getItemId;

        pthis->actor.draw = NULL;
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actor.parent = NULL;
        if (CUR_UPG_VALUE(UPG_BULLET_BAG) == 1) {
            getItemId = GI_BULLET_BAG_40;
        } else {
            getItemId = GI_BULLET_BAG_50;
        }
        func_8002F434(&pthis->actor, globalCtx, getItemId, 2000.0f, 1000.0f);
        pthis->actionFunc = EnExItem_TargetPrizeGive;
    }
}

void EnExItem_TargetPrizeGive(EnExItem* pthis, GlobalContext* globalCtx) {
    s32 getItemId;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnExItem_TargetPrizeFinish;
    } else {
        getItemId = (CUR_UPG_VALUE(UPG_BULLET_BAG) == 2) ? GI_BULLET_BAG_50 : GI_BULLET_BAG_40;

        func_8002F434(&pthis->actor, globalCtx, getItemId, 2000.0f, 1000.0f);
    }
}

void EnExItem_TargetPrizeFinish(EnExItem* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        // "Successful completion"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n" VT_RST);
        gSaveContext.itemGetInf[1] |= 0x2000;
        Actor_Kill(&pthis->actor);
    }
}

void EnExItem_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnExItem* pthis = (EnExItem*)thisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->chestKillTimer != 0) {
        pthis->chestKillTimer--;
    }
    if (pthis->prizeRotateTimer != 0) {
        pthis->prizeRotateTimer--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void EnExItem_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnExItem* pthis = (EnExItem*)thisx;
    s32 magicType;

    Actor_SetScale(&pthis->actor, pthis->scale);
    switch (pthis->type) {
        case EXITEM_BOMB_BAG_BOWLING:
        case EXITEM_BOMBCHUS_BOWLING:
        case EXITEM_BOMBS_BOWLING:
        case EXITEM_BOMB_BAG_COUNTER:
        case EXITEM_BOMBCHUS_COUNTER:
        case EXITEM_BOMBS_COUNTER:
        case EXITEM_BULLET_BAG:
            EnExItem_DrawItems(pthis, globalCtx);
            break;
        case EXITEM_HEART_PIECE_BOWLING:
        case EXITEM_HEART_PIECE_COUNTER:
            EnExItem_DrawHeartPiece(pthis, globalCtx);
            break;
        case EXITEM_PURPLE_RUPEE_BOWLING:
        case EXITEM_PURPLE_RUPEE_COUNTER:
        case EXITEM_GREEN_RUPEE_CHEST:
        case EXITEM_BLUE_RUPEE_CHEST:
        case EXITEM_RED_RUPEE_CHEST:
        case EXITEM_13:
        case EXITEM_14:
            EnExItem_DrawRupee(pthis, globalCtx);
            break;
        case EXITEM_SMALL_KEY_CHEST:
            EnExItem_DrawKey(pthis, globalCtx, 0);
            break;
        case EXITEM_MAGIC_FIRE:
        case EXITEM_MAGIC_WIND:
        case EXITEM_MAGIC_DARK:
            magicType = pthis->type - EXITEM_MAGIC_FIRE;
            EnExItem_DrawMagic(pthis, globalCtx, magicType);
            break;
    }
}

void EnExItem_DrawItems(EnExItem* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_17C != NULL) {
        pthis->unk_17C(&pthis->actor, globalCtx, 0);
    }
    if (pthis) {}
    func_8002ED80(&pthis->actor, globalCtx, 0);
    GetItem_Draw(globalCtx, pthis->giDrawId);
}

void EnExItem_DrawHeartPiece(EnExItem* pthis, GlobalContext* globalCtx) {
    func_8002ED80(&pthis->actor, globalCtx, 0);
    GetItem_Draw(globalCtx, GID_HEART_PIECE);
}

void EnExItem_DrawMagic(EnExItem* pthis, GlobalContext* globalCtx, s16 magicIndex) {
    static s16 sgiDrawIds[] = { GID_DINS_FIRE, GID_FARORES_WIND, GID_NAYRUS_LOVE };

    func_8002ED80(&pthis->actor, globalCtx, 0);
    GetItem_Draw(globalCtx, sgiDrawIds[magicIndex]);
}

void EnExItem_DrawKey(EnExItem* pthis, GlobalContext* globalCtx, s32 index) {
    static void* keySegments[] = { gDropKeySmallTex };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ex_item.c", 880);

    func_8009460C(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ex_item.c", 887),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(keySegments[index]));
    gSPDisplayList(POLY_OPA_DISP++, gItemDropDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ex_item.c", 893);
}

void EnExItem_DrawRupee(EnExItem* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_17C != NULL) {
        pthis->unk_17C(&pthis->actor, globalCtx, 0);
    }
    if (pthis->unk_180 != NULL) {
        pthis->unk_180(&pthis->actor, globalCtx, 0);
    }
    GetItem_Draw(globalCtx, pthis->giDrawId);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BOM_BOWL_PIT_Z_EN_BOM_BOWL_PIT_C
#include "actor_common.h"
#include "z_en_bom_bowl_pit.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Bom_Chu/z_en_bom_chu.h"
#include "overlays/actors/ovl_En_Ex_Item/z_en_ex_item.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"

#define FLAGS ACTOR_FLAG_4

void EnBomBowlPit_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlPit_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBomBowlPit_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBomBowlPit_Update(Actor* thisx, GlobalContext* globalCtx);

void EnBomBowlPit_SetupDetectHit(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_DetectHit(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_CameraDollyIn(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_SpawnPrize(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_SetupGivePrize(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_GivePrize(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_WaitTillPrizeGiven(EnBomBowlPit* pthis, GlobalContext* globalCtx);
void EnBomBowlPit_Reset(EnBomBowlPit* pthis, GlobalContext* globalCtx);

static s32 sGetItemIds[] = { GI_BOMB_BAG_30, GI_HEART_PIECE, GI_BOMBCHUS_10, GI_BOMBS_1, GI_RUPEE_PURPLE };

ActorInit En_Bom_Bowl_Pit_InitVars = {
    ACTOR_EN_BOM_BOWL_PIT,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnBomBowlPit),
    (ActorFunc)EnBomBowlPit_Init,
    (ActorFunc)EnBomBowlPit_Destroy,
    (ActorFunc)EnBomBowlPit_Update,
    NULL,
    (ActorFunc)EnBomBowlPit_Reset,
};

void EnBomBowlPit_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBomBowlPit* pthis = (EnBomBowlPit*)thisx;

    pthis->actionFunc = EnBomBowlPit_SetupDetectHit;
}

void EnBomBowlPit_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnBomBowlPit_SetupDetectHit(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if (pthis->start != 0) {
        pthis->start = pthis->status = 0;
        pthis->actionFunc = EnBomBowlPit_DetectHit;
    }
}

void EnBomBowlPit_DetectHit(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    EnBomChu* chu;
    Vec3f chuPosDiff;

    if (globalCtx->cameraPtrs[MAIN_CAM]->setting == CAM_SET_CHU_BOWLING) {
        chu = (EnBomChu*)globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;

        while (chu != NULL) {
            if ((&chu->actor == &pthis->actor) || (chu->actor.id != ACTOR_EN_BOM_CHU)) {
                chu = (EnBomChu*)chu->actor.next;
                continue;
            }

            chuPosDiff.x = chu->actor.world.pos.x - pthis->actor.world.pos.x;
            chuPosDiff.y = chu->actor.world.pos.y - pthis->actor.world.pos.y;
            chuPosDiff.z = chu->actor.world.pos.z - pthis->actor.world.pos.z;

            if (((fabsf(chuPosDiff.x) < 40.0f) || (BREG(2))) && ((fabsf(chuPosDiff.y) < 40.0f) || (BREG(2))) &&
                ((fabsf(chuPosDiff.z) < 40.0f) || (BREG(2)))) {
                func_8002DF54(globalCtx, NULL, 8);
                chu->timer = 1;

                pthis->camId = Gameplay_CreateSubCamera(globalCtx);
                Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
                Gameplay_ChangeCameraStatus(globalCtx, pthis->camId, CAM_STAT_ACTIVE);

                pthis->unk_1C8.x = pthis->unk_1C8.y = pthis->unk_1C8.z = 0.1f;
                pthis->unk_1A4.x = pthis->unk_1A4.y = pthis->unk_1A4.z = 0.1f;

                pthis->unk_180.x = pthis->unk_168.x = globalCtx->view.lookAt.x;
                pthis->unk_180.y = pthis->unk_168.y = globalCtx->view.lookAt.y;
                pthis->unk_180.z = pthis->unk_168.z = globalCtx->view.lookAt.z;

                pthis->unk_18C.x = pthis->unk_174.x = globalCtx->view.eye.x;
                pthis->unk_18C.y = pthis->unk_174.y = globalCtx->view.eye.y;
                pthis->unk_18C.z = pthis->unk_174.z = globalCtx->view.eye.z;

                pthis->unk_1BC.x = 20.0f;
                pthis->unk_1BC.y = 100.0f;
                pthis->unk_1BC.z = -800.0f;

                pthis->unk_198.x = 20.0f;
                pthis->unk_198.y = 50.0f;
                pthis->unk_198.z = -485.0f;

                pthis->unk_1B0.x = fabsf(pthis->unk_18C.x - pthis->unk_198.x) * 0.02f;
                pthis->unk_1B0.y = fabsf(pthis->unk_18C.y - pthis->unk_198.y) * 0.02f;
                pthis->unk_1B0.z = fabsf(pthis->unk_18C.z - pthis->unk_198.z) * 0.02f;

                pthis->unk_1D4.x = fabsf(pthis->unk_180.x - pthis->unk_1BC.x) * 0.02f;
                pthis->unk_1D4.y = fabsf(pthis->unk_180.y - pthis->unk_1BC.y) * 0.02f;
                pthis->unk_1D4.z = fabsf(pthis->unk_180.z - pthis->unk_1BC.z) * 0.02f;

                Gameplay_CameraSetAtEye(globalCtx, pthis->camId, &pthis->unk_180, &pthis->unk_18C);
                pthis->actor.textId = 0xF;
                Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
                pthis->unk_154 = TEXT_STATE_EVENT;
                func_80078884(NA_SE_EV_HIT_SOUND);
                func_8002DF54(globalCtx, NULL, 8);
                pthis->status = 1;
                pthis->actionFunc = EnBomBowlPit_CameraDollyIn;
                break;
            } else {
                chu = (EnBomChu*)chu->actor.next;
            }
        }
    }
}

void EnBomBowlPit_CameraDollyIn(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if (pthis->camId != SUBCAM_FREE) {
        Math_ApproachF(&pthis->unk_180.x, pthis->unk_1BC.x, pthis->unk_1C8.x, pthis->unk_1D4.x);
        Math_ApproachF(&pthis->unk_180.y, pthis->unk_1BC.y, pthis->unk_1C8.y, pthis->unk_1D4.y);
        Math_ApproachF(&pthis->unk_180.z, pthis->unk_1BC.z, pthis->unk_1C8.z, pthis->unk_1D4.z);
        Math_ApproachF(&pthis->unk_18C.x, pthis->unk_198.x, pthis->unk_1A4.x, pthis->unk_1B0.x);
        Math_ApproachF(&pthis->unk_18C.y, pthis->unk_198.y, pthis->unk_1A4.y, pthis->unk_1B0.y);
        Math_ApproachF(&pthis->unk_18C.z, pthis->unk_198.z, pthis->unk_1A4.z, pthis->unk_1B0.z);
    }

    Gameplay_CameraSetAtEye(globalCtx, pthis->camId, &pthis->unk_180, &pthis->unk_18C);

    if ((pthis->unk_154 == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
    }

    if ((fabsf(pthis->unk_18C.x - pthis->unk_198.x) < 5.0f) && (fabsf(pthis->unk_18C.y - pthis->unk_198.y) < 5.0f) &&
        (fabsf(pthis->unk_18C.z - pthis->unk_198.z) < 5.0f) && (fabsf(pthis->unk_180.x - pthis->unk_1BC.x) < 5.0f) &&
        (fabsf(pthis->unk_180.y - pthis->unk_1BC.y) < 5.0f) && (fabsf(pthis->unk_180.z - pthis->unk_1BC.z) < 5.0f)) {
        Message_CloseTextbox(globalCtx);
        pthis->timer = 30;
        pthis->actionFunc = EnBomBowlPit_SpawnPrize;
    }
}

void EnBomBowlPit_SpawnPrize(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        pthis->exItem = (EnExItem*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_ITEM,
                                                     pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                                     pthis->actor.world.pos.z - 70.0f, 0, 0, 0, pthis->prizeIndex);
        if (pthis->exItem != NULL) {
            pthis->actionFunc = EnBomBowlPit_SetupGivePrize;
        }
    }
}

void EnBomBowlPit_SetupGivePrize(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if (pthis->exItemDone != 0) {
        switch (pthis->prizeIndex) {
            case EXITEM_BOMB_BAG_BOWLING:
                gSaveContext.itemGetInf[1] |= 2;
                break;
            case EXITEM_HEART_PIECE_BOWLING:
                gSaveContext.itemGetInf[1] |= 4;
                break;
        }

        Gameplay_ClearCamera(globalCtx, pthis->camId);
        Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = EnBomBowlPit_GivePrize;
    }
}

void EnBomBowlPit_GivePrize(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    func_8002DF54(globalCtx, NULL, 7);
    pthis->getItemId = sGetItemIds[pthis->prizeIndex];

    if ((pthis->getItemId == GI_BOMB_BAG_30) && (CUR_CAPACITY(UPG_BOMB_BAG) == 30)) {
        pthis->getItemId = GI_BOMB_BAG_40;
    }

    player->stateFlags1 &= ~0x20000000;
    pthis->actor.parent = NULL;
    func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 2000.0f, 1000.0f);
    player->stateFlags1 |= 0x20000000;
    pthis->actionFunc = EnBomBowlPit_WaitTillPrizeGiven;
}

void EnBomBowlPit_WaitTillPrizeGiven(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnBomBowlPit_Reset;
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 2000.0f, 1000.0f);
    }
}

void EnBomBowlPit_Reset(EnBomBowlPit* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        // "Normal termination"/"completion"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n" VT_RST);
        if (pthis->getItemId == GI_HEART_PIECE) {
            gSaveContext.healthAccumulator = 0x140;
            // "Ah recovery!" (?)
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ あぁ回復！ ☆☆☆☆☆ \n" VT_RST);
        }
        pthis->exItemDone = 0;
        pthis->status = 2;
        pthis->actionFunc = EnBomBowlPit_SetupDetectHit;
    }
}

void EnBomBowlPit_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBomBowlPit* pthis = (EnBomBowlPit*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }
}

void EnBomBowlPit_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Bom_Bowl_Pit_InitVars = {
        ACTOR_EN_BOM_BOWL_PIT,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnBomBowlPit),
        (ActorFunc)EnBomBowlPit_Init,
        (ActorFunc)EnBomBowlPit_Destroy,
        (ActorFunc)EnBomBowlPit_Update,
        NULL,
        (ActorFunc)EnBomBowlPit_Reset,
    };

}

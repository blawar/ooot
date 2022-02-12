#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DS_Z_EN_DS_C
#include "actor_common.h"
/*
 * File: z_en_ds.c
 * Overlay: ovl_En_Ds
 * Description: Potion Shop Granny
 */

#include "z_en_ds.h"
#include "objects/object_ds/object_ds.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnDs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDs_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDs_Wait(EnDs* pthis, GlobalContext* globalCtx);

ActorInit En_Ds_InitVars = {
    ACTOR_EN_DS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DS,
    sizeof(EnDs),
    (ActorFunc)EnDs_Init,
    (ActorFunc)EnDs_Destroy,
    (ActorFunc)EnDs_Update,
    (ActorFunc)EnDs_Draw,
};

void EnDs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDs* pthis = (EnDs*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 36.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gPotionShopLadySkel, &gPotionShopLadyAnim, pthis->jointTable,
                       pthis->morphTable, 6);
    Animation_PlayOnce(&pthis->skelAnime, &gPotionShopLadyAnim);

    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;

    Actor_SetScale(&pthis->actor, 0.013f);

    pthis->actionFunc = EnDs_Wait;
    pthis->actor.targetMode = 1;
    pthis->unk_1E8 = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->unk_1E4 = 0.0f;
}

void EnDs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnDs_Talk(EnDs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDs_Wait;
        pthis->actor.flags &= ~ACTOR_FLAG_16;
    }
    pthis->unk_1E8 |= 1;
}

void EnDs_TalkNoEmptyBottle(EnDs* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnDs_Wait;
    }
    pthis->unk_1E8 |= 1;
}

void EnDs_TalkAfterGiveOddPotion(EnDs* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDs_Talk;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_16;
        func_8002F2CC(&pthis->actor, globalCtx, 1000.0f);
    }
}

void EnDs_DisplayOddPotionText(EnDs* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actor.textId = 0x504F;
        pthis->actionFunc = EnDs_TalkAfterGiveOddPotion;
        pthis->actor.flags &= ~ACTOR_FLAG_8;
        gSaveContext.itemGetInf[3] |= 1;
    }
}

void EnDs_GiveOddPotion(EnDs* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnDs_DisplayOddPotionText;
        gSaveContext.timer2State = 0;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_ODD_POTION, 10000.0f, 50.0f);
    }
}

void EnDs_TalkAfterBrewOddPotion(EnDs* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnDs_GiveOddPotion;
        func_8002F434(&pthis->actor, globalCtx, GI_ODD_POTION, 10000.0f, 50.0f);
    }
}

void EnDs_BrewOddPotion3(EnDs* pthis, GlobalContext* globalCtx) {
    if (pthis->brewTimer > 0) {
        pthis->brewTimer -= 1;
    } else {
        pthis->actionFunc = EnDs_TalkAfterBrewOddPotion;
        Message_ContinueTextbox(globalCtx, 0x504D);
    }

    Math_StepToF(&pthis->unk_1E4, 0, 0.03f);
    Environment_AdjustLights(globalCtx, pthis->unk_1E4 * (2.0f - pthis->unk_1E4), 0.0f, 0.1f, 1.0f);
}

void EnDs_BrewOddPotion2(EnDs* pthis, GlobalContext* globalCtx) {
    if (pthis->brewTimer > 0) {
        pthis->brewTimer -= 1;
    } else {
        pthis->actionFunc = EnDs_BrewOddPotion3;
        pthis->brewTimer = 60;
        Flags_UnsetSwitch(globalCtx, 0x3F);
    }
}

void EnDs_BrewOddPotion1(EnDs* pthis, GlobalContext* globalCtx) {
    if (pthis->brewTimer > 0) {
        pthis->brewTimer -= 1;
    } else {
        pthis->actionFunc = EnDs_BrewOddPotion2;
        pthis->brewTimer = 20;
    }

    Math_StepToF(&pthis->unk_1E4, 1.0f, 0.01f);
    Environment_AdjustLights(globalCtx, pthis->unk_1E4 * (2.0f - pthis->unk_1E4), 0.0f, 0.1f, 1.0f);
}

void EnDs_OfferOddPotion(EnDs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                pthis->actionFunc = EnDs_BrewOddPotion1;
                pthis->brewTimer = 60;
                Flags_SetSwitch(globalCtx, 0x3F);
                globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
                player->exchangeItemId = EXCH_ITEM_NONE;
                break;
            case 1: // no
                Message_ContinueTextbox(globalCtx, 0x504C);
                pthis->actionFunc = EnDs_Talk;
        }
    }
}

s32 EnDs_CheckRupeesAndBottle() {
    if (gSaveContext.rupees < 100) {
        return 0;
    } else if (Inventory_HasEmptyBottle() == 0) {
        return 1;
    } else {
        return 2;
    }
}

void EnDs_GiveBluePotion(EnDs* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnDs_Talk;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_POTION_BLUE, 10000.0f, 50.0f);
    }
}

void EnDs_OfferBluePotion(EnDs* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                switch (EnDs_CheckRupeesAndBottle()) {
                    case 0: // have less than 100 rupees
                        Message_ContinueTextbox(globalCtx, 0x500E);
                        break;
                    case 1: // have 100 rupees but no empty bottle
                        Message_ContinueTextbox(globalCtx, 0x96);
                        pthis->actionFunc = EnDs_TalkNoEmptyBottle;
                        return;
                    case 2: // have 100 rupees and empty bottle
                        Rupees_ChangeBy(-100);
                        pthis->actor.flags &= ~ACTOR_FLAG_16;
                        func_8002F434(&pthis->actor, globalCtx, GI_POTION_BLUE, 10000.0f, 50.0f);
                        pthis->actionFunc = EnDs_GiveBluePotion;
                        return;
                }
                break;
            case 1: // no
                Message_ContinueTextbox(globalCtx, 0x500D);
        }
        pthis->actionFunc = EnDs_Talk;
    }
}

void EnDs_Wait(EnDs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (func_8002F368(globalCtx) == EXCH_ITEM_ODD_MUSHROOM) {
            Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            player->actor.textId = 0x504A;
            pthis->actionFunc = EnDs_OfferOddPotion;
        } else if (gSaveContext.itemGetInf[3] & 1) {
            player->actor.textId = 0x500C;
            pthis->actionFunc = EnDs_OfferBluePotion;
        } else {
            if (INV_CONTENT(ITEM_ODD_MUSHROOM) == ITEM_ODD_MUSHROOM) {
                player->actor.textId = 0x5049;
            } else {
                player->actor.textId = 0x5048;
            }
            pthis->actionFunc = EnDs_Talk;
        }
    } else {
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        pthis->actor.textId = 0x5048;

        if ((ABS(yawDiff) < 0x2151) && (pthis->actor.xzDistToPlayer < 200.0f)) {
            func_8002F298(&pthis->actor, globalCtx, 100.0f, EXCH_ITEM_ODD_MUSHROOM);
            pthis->unk_1E8 |= 1;
        }
    }
}

void EnDs_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDs* pthis = (EnDs*)thisx;

    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        pthis->skelAnime.curFrame = 0.0f;
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->unk_1E8 & 1) {
        func_80038290(globalCtx, &pthis->actor, &pthis->unk_1D8, &pthis->unk_1DE, pthis->actor.focus.pos);
    } else {
        Math_SmoothStepToS(&pthis->unk_1D8.x, 0, 6, 0x1838, 100);
        Math_SmoothStepToS(&pthis->unk_1D8.y, 0, 6, 0x1838, 100);
        Math_SmoothStepToS(&pthis->unk_1DE.x, 0, 6, 0x1838, 100);
        Math_SmoothStepToS(&pthis->unk_1DE.y, 0, 6, 0x1838, 100);
    }
}

s32 EnDs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnDs* pthis = (EnDs*)thisx;

    if (limbIndex == 5) {
        rot->x += pthis->unk_1D8.y;
        rot->z += pthis->unk_1D8.x;
    }
    return false;
}

void EnDs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f sMultVec = { 1100.0f, 500.0f, 0.0f };
    EnDs* pthis = (EnDs*)thisx;

    if (limbIndex == 5) {
        Matrix_MultVec3f(&sMultVec, &pthis->actor.focus.pos);
    }
}

void EnDs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDs* pthis = (EnDs*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDs_OverrideLimbDraw, EnDs_PostLimbDraw, pthis);
}

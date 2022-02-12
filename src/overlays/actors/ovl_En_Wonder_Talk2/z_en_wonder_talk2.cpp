#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WONDER_TALK2_Z_EN_WONDER_TALK2_C
#include "actor_common.h"
/*
 * File: z_en_wonder_talk2.c
 * Overlay: ovl_En_Wonder_Talk2
 * Description: Dialog spot
 */

#include "z_en_wonder_talk2.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_27)

void EnWonderTalk2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWonderTalk2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWonderTalk2_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B3A10C(EnWonderTalk2* pthis, GlobalContext* globalCtx);
void func_80B3A4F8(EnWonderTalk2* pthis, GlobalContext* globalCtx);
void func_80B3A15C(EnWonderTalk2* pthis, GlobalContext* globalCtx);
void func_80B3A3D4(EnWonderTalk2* pthis, GlobalContext* globalCtx);
void EnWonderTalk2_DoNothing(EnWonderTalk2* pthis, GlobalContext* globalCtx);

ActorInit En_Wonder_Talk2_InitVars = {
    ACTOR_EN_WONDER_TALK2,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWonderTalk2),
    (ActorFunc)EnWonderTalk2_Init,
    (ActorFunc)EnWonderTalk2_Destroy,
    (ActorFunc)EnWonderTalk2_Update,
    NULL,
};

static s16 D_80B3A8E0[] = { 6, 0, 1, 2, 3, 4, 5 };

void EnWonderTalk2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnWonderTalk2_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnWonderTalk2* pthis = (EnWonderTalk2*)thisx;

    osSyncPrintf("\n\n");
    // "Transparent message"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 透明メッセージ君 ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
    pthis->baseMsgId = (pthis->actor.params >> 6) & 0xFF;
    if (pthis->actor.world.rot.z > 0) {
        s32 rangeIndex = 0;
        s16 rotZmod10 = pthis->actor.world.rot.z;

        while (rotZmod10 > 10) {
            rotZmod10 -= 10;
            rangeIndex++;
        }
        // rangeIndex = rot.z/10 here
        pthis->triggerRange = rotZmod10 * 40.0f;
        if (rangeIndex > 6) {
            rangeIndex = 0;
        }

        pthis->actor.targetMode = D_80B3A8E0[rangeIndex];

        osSyncPrintf("\n\n");
        // "originally?"
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 元は？       ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.world.rot.z);
        // "The range is?"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ レンジは？   ☆☆☆☆☆ %d\n" VT_RST, pthis->actor.targetMode);
        // "Is the range?"
        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ は、範囲わ？ ☆☆☆☆☆ %f\n" VT_RST, pthis->triggerRange);
        osSyncPrintf("\n\n");
        osSyncPrintf("\n\n");
        osSyncPrintf("\n\n");
    }

    pthis->initPos = pthis->actor.world.pos;
    pthis->switchFlag = (pthis->actor.params & 0x3F);
    pthis->talkMode = ((pthis->actor.params >> 0xE) & 3);

    if (pthis->switchFlag == 0x3F) {
        pthis->switchFlag = -1;
    }
    if (pthis->switchFlag >= 0 && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Ｙｏｕ ａｒｅ Ｓｈｏｃｋ！  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
        Actor_Kill(&pthis->actor);
        return;
    }
    if ((pthis->talkMode == 1) && (globalCtx->sceneNum == SCENE_MEN) && (pthis->switchFlag != 0x08) &&
        (pthis->switchFlag != 0x16) && (pthis->switchFlag != 0x2F)) {

        pthis->unk_15A = false;
        pthis->talkMode = 4;
    }
    if (pthis->talkMode == 3) {
        pthis->actor.flags &= ~ACTOR_FLAG_27;
        pthis->actionFunc = EnWonderTalk2_DoNothing;
    } else {
        pthis->actionFunc = func_80B3A10C;
    }
}

void func_80B3A10C(EnWonderTalk2* pthis, GlobalContext* globalCtx) {
    pthis->actor.textId = 0x200;
    pthis->actor.textId |= pthis->baseMsgId;
    if (pthis->talkMode == 1 || pthis->talkMode == 4) {
        pthis->actionFunc = func_80B3A4F8;
    } else {
        pthis->actionFunc = func_80B3A15C;
    }
}

void func_80B3A15C(EnWonderTalk2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_158++;
    if ((pthis->switchFlag >= 0) && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if (!pthis->unk_15A) {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->unk_15A = true;
        }
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if ((pthis->switchFlag >= 0) && (pthis->talkMode != 2)) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
            // "I saved it! All of it!"
            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ セーブしたよ！おもいっきり！ %x\n" VT_RST, pthis->switchFlag);
        }

        pthis->actionFunc = func_80B3A10C;
    } else {
        s16 yawDiff = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y));

        if (!((pthis->actor.xzDistToPlayer > 40.0f + pthis->triggerRange) ||
              (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) > 100.0f) || (yawDiff >= 0x4000))) {
            if (pthis->unk_158 >= 2) {
                osSyncPrintf("\n\n");
                // "Transparent Message Kimi Set"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 透明メッセージ君せっと %x\n" VT_RST, pthis->actor.params);
                // "Save Information"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ セーブ情報 \t           %x\n" VT_RST, pthis->switchFlag);
                // "Specified message type"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 指定メッセージ種類     %x\n" VT_RST, pthis->baseMsgId);
                // "Actual message type"
                osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 実質メッセージ種類     %x\n" VT_RST, pthis->actor.textId);
                // "Specified range"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 指定範囲               %d\n" VT_RST, pthis->actor.world.rot.z);
                // "Processing range"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 処理範囲               %f\n" VT_RST, pthis->triggerRange);
                switch (pthis->talkMode) {
                    case 0:
                        // "Normal"
                        osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆ 通常 ☆☆ \n" VT_RST);
                        break;
                    case 2:
                        // "Check only"
                        osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆ チェックのみ ☆☆ \n" VT_RST);
                        break;
                    case 3:
                        // "Lock only"
                        osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆ ロックのみ ☆☆ \n" VT_RST);
                        break;
                }
            }

            pthis->unk_158 = 0;
            func_8002F1C4(&pthis->actor, globalCtx, pthis->triggerRange + 50.0f, 100.0f, EXCH_ITEM_NONE);
        }
    }
}

void func_80B3A3D4(EnWonderTalk2* pthis, GlobalContext* globalCtx) {
    if (BREG(2) != 0) {
        // "Oh"
        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ わー %d\n" VT_RST, Message_GetState(&globalCtx->msgCtx));
    }

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_EVENT:
        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(globalCtx)) {
                if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) {
                    Message_CloseTextbox(globalCtx);
                }
            } else {
                break;
            }
        case TEXT_STATE_NONE:
            if ((pthis->switchFlag >= 0) && (pthis->talkMode != 4)) {
                Flags_SetSwitch(globalCtx, pthis->switchFlag);
                // "(Forced) I saved it! All of it!"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ (強制)セーブしたよ！おもいっきり！ %x\n" VT_RST, pthis->switchFlag);
            }

            if (pthis->talkMode == 4) {
                pthis->unk_15A = true;
            }
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_4);
            func_8002DF54(globalCtx, NULL, 7);
            pthis->unk_156 = true;
            pthis->actionFunc = func_80B3A4F8;
            break;
    }
}

void func_80B3A4F8(EnWonderTalk2* pthis, GlobalContext* globalCtx) {
    Player* player;

    player = GET_PLAYER(globalCtx);
    pthis->unk_158++;
    if (pthis->switchFlag >= 0 && Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if (!pthis->unk_15A) {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->unk_15A = true;
        }
    } else if ((pthis->talkMode != 4) || !pthis->unk_15A) {
        if (BREG(2) != 0) {
            // "distance"
            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ きょり %f\n" VT_RST, pthis->actor.xzDistToPlayer);
        }
        if (((pthis->actor.xzDistToPlayer < (40.0f + pthis->triggerRange)) &&
             (fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) < 100.0f)) &&
            !Gameplay_InCsMode(globalCtx)) {
            if (pthis->unk_158 >= 2) {
                osSyncPrintf("\n\n");
                // "Transparent Message Kimi Seto"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 透明メッセージ君せっと %x\n" VT_RST, pthis->actor.params);
                // "Save Information"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ セーブ情報 \t           %x\n" VT_RST, pthis->switchFlag);
                // "Specified message type"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 指定メッセージ種類     %x\n" VT_RST, pthis->baseMsgId);
                // "Real message type"
                osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 実質メッセージ種類     %x\n" VT_RST, pthis->actor.textId);
                // "Specified range"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 指定範囲               %d\n" VT_RST, pthis->actor.world.rot.z);
                // "Processing range"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 処理範囲               %f\n" VT_RST, pthis->triggerRange);
                // "What is your range?"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ レンジは？ \t\t   %d\n" VT_RST, pthis->actor.targetMode);
                osSyncPrintf("\n\n");
                osSyncPrintf("\n\n");
                switch (pthis->talkMode) {
                    case 1:
                        // "Compulsion"
                        osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆ 強制 ☆☆ \n" VT_RST);
                        break;
                    case 4:
                        // "Gerudo Training Grounds Forced Check Only"
                        osSyncPrintf(VT_FGCOL(RED) " ☆☆ ゲルドの修練場強制チェックのみ ☆☆ \n" VT_RST);
                        break;
                }

                osSyncPrintf("\n\n");
            }
            pthis->unk_158 = 0;
            if (!pthis->unk_156) {
                Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
                func_8002DF54(globalCtx, NULL, 8);
                pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_4;
                pthis->actionFunc = func_80B3A3D4;
            }

        } else {
            pthis->unk_156 = false;
        }
    }
}

void EnWonderTalk2_DoNothing(EnWonderTalk2* pthis, GlobalContext* globalCtx) {
}

void EnWonderTalk2_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnWonderTalk2* pthis = (EnWonderTalk2*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.world.pos.y = pthis->initPos.y;

    Actor_SetFocus(&pthis->actor, pthis->height);
}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WONDER_TALK_Z_EN_WONDER_TALK_C
#include "actor_common.h"
/*
 * File: z_en_wonder_talk.c
 * Overlay: ovl_En_Wonder_Talk
 * Description: Checkable spot (Green Navi)
 */

#include "z_en_wonder_talk.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_message_PAL.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_27)

void EnWonderTalk_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWonderTalk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWonderTalk_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B391CC(EnWonderTalk* pthis, GlobalContext* globalCtx);
void func_80B395F0(EnWonderTalk* pthis, GlobalContext* globalCtx);
void func_80B3943C(EnWonderTalk* pthis, GlobalContext* globalCtx);

ActorInit En_Wonder_Talk_InitVars = {
    ACTOR_EN_WONDER_TALK,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWonderTalk),
    (ActorFunc)EnWonderTalk_Init,
    (ActorFunc)EnWonderTalk_Destroy,
    (ActorFunc)EnWonderTalk_Update,
    NULL,
};

void EnWonderTalk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnWonderTalk_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnWonderTalk* pthis = (EnWonderTalk*)thisx;

    osSyncPrintf("\n\n");
    // "Special conversation"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 特殊会話くん ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);

    pthis->unk_150 = (pthis->actor.params >> 0xB) & 0x1F;
    pthis->unk_152 = (pthis->actor.params >> 6) & 0x1F;
    pthis->switchFlag = pthis->actor.params & 0x3F;
    if (pthis->switchFlag == 0x3F) {
        pthis->switchFlag = -1;
    }
    pthis->actor.targetMode = 1;
    if (pthis->switchFlag >= 0) {
        if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Ｙｏｕ ａｒｅ Ｓｈｏｃｋ！  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
            Actor_Kill(&pthis->actor);
            return;
        }
    }
    pthis->actionFunc = func_80B391CC;
    pthis->unk_15C = 40.0f;
}

void func_80B391CC(EnWonderTalk* pthis, GlobalContext* globalCtx) {
    if (pthis->switchFlag < 0 || !Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        switch (pthis->unk_150) {
            case 1:
                // "Slate GO!"
                osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 石板ＧＯ！ ☆☆☆☆☆ \n" VT_RST);
                pthis->height = 0.0f;
                pthis->unk_15C = 80.0f;
                // "Attention coordinates"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 注目座標\t       \t☆☆☆☆☆ %f\n" VT_RST, 0.0f);
                if (!LINK_IS_ADULT) {
                    pthis->actor.textId = 0x7040;
                    // "Children"
                    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ こども ☆☆☆☆☆ \n" VT_RST);
                } else {
                    // "Adult"
                    osSyncPrintf(VT_FGCOL(CYAN) " ☆☆☆☆☆ おとな ☆☆☆☆☆ \n" VT_RST);
                    pthis->actor.textId = 0x7088;
                }

                pthis->unk_156 = TEXT_STATE_EVENT;
                osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ pthis->actor.talk_message    ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.textId);
                break;
            case 2:
                // "Diary start!"
                osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 日記帳スタート！ ☆☆☆☆☆ \n" VT_RST);
                pthis->actor.textId = 0x5002;
                pthis->unk_156 = TEXT_STATE_CHOICE;
                pthis->height = 30.0f;
                pthis->unk_15C = 40.0f;
                // "Attention coordinates"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 注目座標\t       \t☆☆☆☆☆ %f\n" VT_RST, 30.0f);
                break;
            case 3:
                pthis->actor.textId = 0x501E;
                pthis->unk_156 = TEXT_STATE_EVENT;
                pthis->height = 0.0f;
                pthis->unk_15C = 110.0f;
                // "Attention coordinates"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 注目座標\t       \t☆☆☆☆☆ %f\n" VT_RST, 0.0f);
                break;
            case 4:
                pthis->actor.textId = 0x5020;
                pthis->unk_156 = TEXT_STATE_DONE;
                pthis->height = 0.0f;
                // "Attention coordinates"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 注目座標\t       \t☆☆☆☆☆ %f\n" VT_RST, 0.0f);
                pthis->unk_15C = 120.0f;
                if (gSaveContext.eventChkInf[1] & 0x2000) {
                    Actor_Kill(&pthis->actor);
                }
                break;
            case 5:
                pthis->actor.textId = 0x501F;
                pthis->unk_156 = TEXT_STATE_EVENT;
                pthis->height = 0.0f;
                pthis->unk_15C = 110.0f;
                // "Attention coordinates"
                osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 注目座標\t       \t☆☆☆☆☆ %f\n" VT_RST, 0.0f);
                break;
            default:
                pthis->actor.textId = 0x7072;
                pthis->unk_156 = TEXT_STATE_EVENT;
                break;
        }

        osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ pthis->actor.talk_message    ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.textId);
        pthis->actionFunc = func_80B3943C;
    }
}

void func_80B3943C(EnWonderTalk* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;
    s16 yawDiffTemp;

    pthis->unk_15A++;
    if (pthis->unk_150 == 4 && (gSaveContext.eventChkInf[1] & 0x2000)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->switchFlag < 0 || !Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        if ((Actor_ProcessTalkRequest(&pthis->actor, globalCtx))) {
            if (pthis->unk_156 != TEXT_STATE_DONE) {
                pthis->actionFunc = func_80B395F0;
            } else {
                if (pthis->switchFlag >= 0) {
                    pthis->actor.flags &= ~ACTOR_FLAG_0;
                    Flags_SetSwitch(globalCtx, pthis->switchFlag);
                }
                pthis->actionFunc = func_80B391CC;
            }
        } else if (!(pthis->unk_15C < pthis->actor.xzDistToPlayer)) {
            yawDiffTemp = (pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y);
            yawDiff = ABS(yawDiffTemp);

            if (yawDiff < 0x4000) {
                if (pthis->unk_15A >= 2) {
                    osSyncPrintf("\n\n");
                    // "Save information"
                    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ セーブ情報\t\t☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
                    // "Type index"
                    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 種類インデックス\t☆☆☆☆☆ %d\n" VT_RST, pthis->unk_150);
                    // "Actual message type"
                    osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 実質メッセージ種類     %x\n" VT_RST, pthis->actor.textId);
                    // "Specified range"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 指定範囲               %d\n" VT_RST, pthis->actor.world.rot.z);
                    osSyncPrintf("\n\n");
                }
                pthis->unk_15A = 0;
                func_8002F2CC(&pthis->actor, globalCtx, pthis->unk_15C);
            }
        }
    }
}

void func_80B395F0(EnWonderTalk* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_156 == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        if (pthis->switchFlag >= 0) {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        switch (pthis->unk_150) {
            case 1:
                Message_CloseTextbox(globalCtx);
                pthis->actionFunc = func_80B391CC;
                break;
            case 2:
                switch (globalCtx->msgCtx.choiceIndex) {
                    case 0:
                        if (!LINK_IS_ADULT) {
                            // "I'm still a child!"
                            osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ まだコドモなの！ ☆☆☆☆☆ \n" VT_RST);
                            pthis->actor.textId = 0x5001;
                        } else {
                            // "I'm an adult. .. .."
                            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ アダルトなの。。。 ☆☆☆☆☆ \n" VT_RST);
                            pthis->actor.textId = 0x5003;
                        }
                        break;
                    case 1:
                        // "Out!"
                        osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ はずれ！ ☆☆☆☆☆ \n" VT_RST);
                        pthis->actor.textId = 0x5004;
                        break;
                }

                pthis->unk_156 = TEXT_STATE_DONE;
                Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                pthis->actionFunc = func_80B391CC;
                break;
            case 3:
                Message_CloseTextbox(globalCtx);
                if (pthis->unk_164 == 0) {
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_POH, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 2);
                    pthis->unk_164 = 1;
                }

                pthis->actionFunc = func_80B391CC;
                break;
            case 5:
                Message_CloseTextbox(globalCtx);
                if (pthis->unk_164 == 0) {
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_POH, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 3);
                    pthis->unk_164 = 1;
                }
                pthis->actionFunc = func_80B391CC;
                break;
        }
    }
}

void EnWonderTalk_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnWonderTalk* pthis = (EnWonderTalk*)thisx;

    if (pthis->unk_158 != 0) {
        pthis->unk_158--;
    }
    pthis->actionFunc(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, pthis->height);
}

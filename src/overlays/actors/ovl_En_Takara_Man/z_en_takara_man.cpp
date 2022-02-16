#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TAKARA_MAN_Z_EN_TAKARA_MAN_C
#include "actor_common.h"
/*
 * File: z_en_takara_man.c
 * Overlay: ovl_En_Takara_Man
 * Description: Treasure Chest Game Man
 */

#include "z_en_takara_man.h"
#include "vt.h"
#include "objects/object_ts/object_ts.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_27)

void EnTakaraMan_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTakaraMan_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnTakaraMan_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTakaraMan_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTakaraMan_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B176E0(EnTakaraMan* pthis, GlobalContext* globalCtx);
void func_80B1778C(EnTakaraMan* pthis, GlobalContext* globalCtx);
void func_80B17B14(EnTakaraMan* pthis, GlobalContext* globalCtx);
void func_80B17934(EnTakaraMan* pthis, GlobalContext* globalCtx);
void func_80B17A6C(EnTakaraMan* pthis, GlobalContext* globalCtx);
void func_80B17AC4(EnTakaraMan* pthis, GlobalContext* globalCtx);

static void* eyeTextures_37[] = {
    object_ts_Tex_000970,
    object_ts_Tex_000D70,
};


ActorInit En_Takara_Man_InitVars = {
    ACTOR_EN_TAKARA_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TS,
    sizeof(EnTakaraMan),
    (ActorFunc)EnTakaraMan_Init,
    (ActorFunc)EnTakaraMan_Destroy,
    (ActorFunc)EnTakaraMan_Update,
    (ActorFunc)EnTakaraMan_Draw,
    (ActorFunc)EnTakaraMan_Reset,
};

static u8 sTakaraIsInitialized = false;

void EnTakaraMan_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnTakaraMan_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnTakaraMan* pthis = (EnTakaraMan*)thisx;

    if (sTakaraIsInitialized) {
        Actor_Kill(&pthis->actor);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ もういてる原 ☆☆☆☆☆ \n" VT_RST); // "Already initialized"
        return;
    }

    sTakaraIsInitialized = true;
    osSyncPrintf("\n\n");
    // "Bun! %x" (needs a better translation)
    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ ばぅん！ ☆☆☆☆☆ %x\n" VT_RST, globalCtx->actorCtx.flags.chest);
    globalCtx->actorCtx.flags.chest = 0;
    gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex] = -1;
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_ts_Skel_004FE0, &object_ts_Anim_000498, pthis->jointTable,
                       pthis->morphTable, 10);
    thisx->focus.pos = thisx->world.pos;
    pthis->pos = thisx->world.pos;
    thisx->world.pos.x = 133.0f;
    thisx->world.pos.y = -12.0f;
    thisx->world.pos.z = 102.0f;
    Actor_SetScale(&pthis->actor, 0.013f);
    pthis->height = 90.0f;
    pthis->originalRoomNum = thisx->room;
    thisx->room = -1;
    thisx->world.rot.y = thisx->shape.rot.y = -0x4E20;
    thisx->targetMode = 1;
    pthis->actionFunc = func_80B176E0;
}

void func_80B176E0(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    f32 frameCount = Animation_GetLastFrame(&object_ts_Anim_000498);

    Animation_Change(&pthis->skelAnime, &object_ts_Anim_000498, 1.0f, 0.0f, (s16)frameCount, ANIMMODE_LOOP, -10.0f);
    if (!pthis->unk_214) {
        pthis->actor.textId = 0x6D;
        pthis->dialogState = TEXT_STATE_CHOICE;
    }
    pthis->actionFunc = func_80B1778C;
}

void func_80B1778C(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    s16 absYawDiff;
    s16 yawDiff;

    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx) && pthis->dialogState != TEXT_STATE_DONE) {
        if (!pthis->unk_214) {
            pthis->actionFunc = func_80B17934;
        } else {
            pthis->actionFunc = func_80B17B14;
        }
    } else {
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        if (globalCtx->roomCtx.curRoom.num == 6 && !pthis->unk_21A) {
            pthis->actor.textId = 0x6E;
            pthis->unk_21A = 1;
            pthis->dialogState = TEXT_STATE_DONE;
        }

        if (!pthis->unk_21A && pthis->unk_214) {
            if (Flags_GetSwitch(globalCtx, 0x32)) {
                pthis->actor.textId = 0x84;
                pthis->dialogState = TEXT_STATE_EVENT;
            } else {
                pthis->actor.textId = 0x704C;
                pthis->dialogState = TEXT_STATE_DONE;
            }
        }

        absYawDiff = ABS(yawDiff);
        if (absYawDiff < 0x4300) {
            if (globalCtx->roomCtx.curRoom.num != pthis->originalRoomNum) {
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                pthis->unk_218 = 0;
            } else {
                if (!pthis->unk_218) {
                    pthis->actor.flags |= ACTOR_FLAG_0;
                    pthis->unk_218 = 1;
                }
                func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
            }
        }
    }
}

void func_80B17934(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    if (pthis->dialogState == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // Yes
                if (gSaveContext.rupees >= 10) {
                    Message_CloseTextbox(globalCtx);
                    Rupees_ChangeBy(-10);
                    pthis->unk_214 = 1;
                    pthis->actor.parent = NULL;
                    func_8002F434(&pthis->actor, globalCtx, GI_DOOR_KEY, 2000.0f, 1000.0f);
                    pthis->actionFunc = func_80B17A6C;
                } else {
                    Message_CloseTextbox(globalCtx);
                    pthis->actor.textId = 0x85;
                    Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                    pthis->dialogState = TEXT_STATE_EVENT;
                    pthis->actionFunc = func_80B17B14;
                }
                break;
            case 1: // No
                Message_CloseTextbox(globalCtx);
                pthis->actor.textId = 0x2D;
                Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                pthis->dialogState = TEXT_STATE_EVENT;
                pthis->actionFunc = func_80B17B14;
                break;
        }
    }
}

void func_80B17A6C(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = func_80B17AC4;
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_DOOR_KEY, 2000.0f, 1000.0f);
    }
}

void func_80B17AC4(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = func_80B176E0;
    }
}

void func_80B17B14(EnTakaraMan* pthis, GlobalContext* globalCtx) {
    if (pthis->dialogState == Message_GetState(&globalCtx->msgCtx) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = func_80B176E0;
    }
}

void EnTakaraMan_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnTakaraMan* pthis = (EnTakaraMan*)thisx;

    if (pthis->eyeTimer != 0) {
        pthis->eyeTimer--;
    }

    Actor_SetFocus(&pthis->actor, pthis->height);
    func_80038290(globalCtx, &pthis->actor, &pthis->unk_22C, &pthis->unk_232, pthis->actor.focus.pos);
    if (pthis->eyeTimer == 0) {
        pthis->eyeTextureIdx++;
        if (pthis->eyeTextureIdx >= 2) {
            pthis->eyeTextureIdx = 0;
            pthis->eyeTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }
    pthis->unk_212++;
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnTakaraMan_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                 void* thisx) {
    EnTakaraMan* pthis = (EnTakaraMan*)thisx;

    if (limbIndex == 1) {
        rot->x += pthis->unk_232.y;
    }
    if (limbIndex == 8) {
        rot->x += pthis->unk_22C.y;
        rot->z += pthis->unk_22C.z;
    }
    return false;
}

void EnTakaraMan_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnTakaraMan* pthis = (EnTakaraMan*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_takara_man.c", 528);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_37[pthis->eyeTextureIdx]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnTakaraMan_OverrideLimbDraw, NULL, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_takara_man.c", 544);
}

void EnTakaraMan_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Takara_Man_InitVars = {
        ACTOR_EN_TAKARA_MAN,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_TS,
        sizeof(EnTakaraMan),
        (ActorFunc)EnTakaraMan_Init,
        (ActorFunc)EnTakaraMan_Destroy,
        (ActorFunc)EnTakaraMan_Update,
        (ActorFunc)EnTakaraMan_Draw,
        (ActorFunc)EnTakaraMan_Reset,
    };

    sTakaraIsInitialized = false;

}

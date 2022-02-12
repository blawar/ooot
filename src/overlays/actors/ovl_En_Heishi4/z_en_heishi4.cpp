#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HEISHI4_Z_EN_HEISHI4_C
#include "actor_common.h"
#include "z_en_heishi4.h"
#include "objects/object_sd/object_sd.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnHeishi4_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi4_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi4_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHeishi4_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A56544(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A5673C(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56328(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A563BC(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56B40(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56614(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56874(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56900(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56994(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56A50(EnHeishi4* pthis, GlobalContext* globalCtx);
void func_80A56ACC(EnHeishi4* pthis, GlobalContext* globalCtx);

ActorInit En_Heishi4_InitVars = {
    ACTOR_EN_HEISHI4,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SD,
    sizeof(EnHeishi4),
    (ActorFunc)EnHeishi4_Init,
    (ActorFunc)EnHeishi4_Destroy,
    (ActorFunc)EnHeishi4_Update,
    (ActorFunc)EnHeishi4_Draw,
};

static u32 sFaceReactionSets[] = { 6, 7 };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 33, 40, 0, { 0, 0, 0 } },
};

void EnHeishi4_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi4* pthis = (EnHeishi4*)thisx;

    Actor_SetScale(thisx, 0.01f);
    pthis->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    pthis->pos = thisx->world.pos;
    thisx->targetMode = 6;
    if (pthis->type == HEISHI4_AT_MARKET_DYING) {
        pthis->height = 30.0f;
        ActorShape_Init(&thisx->shape, 0.0f, NULL, 30.0f);
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gEnHeishiSkel, &gEnHeishiDyingGuardAnim_00C444, pthis->jointTable,
                       pthis->morphTable, 17);
    } else {
        pthis->height = 60.0f;
        ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gEnHeishiSkel, &gEnHeishiIdleAnim, pthis->jointTable,
                       pthis->morphTable, 17);
    }
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);
    pthis->collider.dim.yShift = 0;
    pthis->collider.dim.radius = 15;
    pthis->collider.dim.height = 70;
    switch (pthis->type) {
        case HEISHI4_AT_KAKRIKO_ENTRANCE:
        case HEISHI4_AT_IMPAS_HOUSE:
            pthis->actionFunc = func_80A56328;
            break;
        case HEISHI4_AT_MARKET_DYING:
            pthis->collider.dim.radius = 28;
            pthis->collider.dim.height = 5;
            pthis->actionFunc = func_80A5673C;
            break;
        case HEISHI4_AT_MARKET_NIGHT:
            pthis->actionFunc = func_80A56544;
            break;
    }
    pthis->unk_27C = ((thisx->params >> 8) & 0xFF);
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, pthis->type);
    osSyncPrintf(VT_FGCOL(PURPLE) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnHeishi4_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi4* pthis = (EnHeishi4*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80A56328(EnHeishi4* pthis, GlobalContext* globalCtx) {
    f32 frames = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = func_80A563BC;
}

void func_80A563BC(EnHeishi4* pthis, GlobalContext* globalCtx) {
    s16 reactionOffset;

    pthis->unk_2B4 = 0;
    reactionOffset = pthis->type - 4;
    if (reactionOffset < 0) {
        reactionOffset = 0;
    }
    if (reactionOffset >= 3) {
        reactionOffset = 1;
    }
    if (Text_GetFaceReaction(globalCtx, sFaceReactionSets[reactionOffset]) != 0) {
        pthis->actor.textId = Text_GetFaceReaction(globalCtx, sFaceReactionSets[reactionOffset]);
        pthis->unk_2B4 = 1;
        pthis->actionFunc = func_80A56B40;
    } else {
        if (gSaveContext.eventChkInf[8] & 1) {
            pthis->actor.textId = 0x5065;
            pthis->actionFunc = func_80A56B40;
            return;
        }
        if (gSaveContext.eventChkInf[4] & 0x20) {
            pthis->actor.textId = 0x5068;
            pthis->actionFunc = func_80A56B40;
            return;
        }
        if (pthis->type == HEISHI4_AT_IMPAS_HOUSE) {
            if (pthis->unk_284 == 0) {
                pthis->actor.textId = 0x5079;
            } else {
                pthis->actor.textId = 0x507A;
            }
        } else if (IS_DAY) {
            if (pthis->unk_284 == 0) {
                pthis->actor.textId = 0x5063;
            } else {
                pthis->actor.textId = 0x5064;
            }
        } else if (pthis->unk_284 == 0) {
            pthis->actor.textId = 0x5066;
        } else {
            pthis->actor.textId = 0x5067;
        }

        pthis->actionFunc = func_80A56B40;
    }
}

void func_80A56544(EnHeishi4* pthis, GlobalContext* globalCtx) {
    f32 frames = Animation_GetLastFrame(&gEnHeishiIdleAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    if (LINK_AGE_IN_YEARS != YEARS_CHILD) {
        osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ ぎゃぁ！オトナだー ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&pthis->actor);
    } else {
        pthis->actionFunc = func_80A56614;
    }
}

void func_80A56614(EnHeishi4* pthis, GlobalContext* globalCtx) {
    s16 reactionOffset;

    reactionOffset = pthis->type - 4;
    pthis->unk_2B4 = 0;
    if (reactionOffset < 0) {
        reactionOffset = 0;
    }
    if (reactionOffset >= 3) {
        reactionOffset = 1;
    }
    if (Text_GetFaceReaction(globalCtx, sFaceReactionSets[reactionOffset]) != 0) {
        pthis->actor.textId = Text_GetFaceReaction(globalCtx, sFaceReactionSets[reactionOffset]);
        pthis->unk_2B4 = 1;
        pthis->actionFunc = func_80A56B40;
        return;
    }
    if (globalCtx->sceneNum == SCENE_MIHARIGOYA) {
        if (IS_DAY) {
            pthis->actor.textId = 0x7004;
        } else {
            pthis->actor.textId = 0x709A;
        }
    } else if (globalCtx->sceneNum != SCENE_MARKET_NIGHT) {
        if (IS_DAY) {
            pthis->actor.textId = 0x7002;
        } else {
            pthis->actor.textId = 0x7003;
        }
    } else {
        pthis->actor.textId = 0x7003;
    }

    pthis->actionFunc = func_80A56B40;
}

void func_80A5673C(EnHeishi4* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.eventChkInf[4] & 0x20) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->unk_284 = 0;
    if (gSaveContext.eventChkInf[8] & 1) {
        if (!(gSaveContext.infTable[6] & 0x1000)) {
            f32 frames = Animation_GetLastFrame(&gEnHeishiDyingGuardAnim_00C444);
            Animation_Change(&pthis->skelAnime, &gEnHeishiDyingGuardAnim_00C444, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            pthis->actor.textId = 0x7007;
            pthis->unk_282 = TEXT_STATE_EVENT;
            pthis->unk_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            pthis->actor.textId = 0x7008;
            pthis->unk_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        pthis->actionFunc = func_80A56874;
    } else {
        Actor_Kill(&pthis->actor);
    }
}

void func_80A56874(EnHeishi4* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_284 != 0) {
        SkelAnime_Update(&pthis->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->unk_284 == 0) {
            pthis->actionFunc = func_80A5673C;

        } else {
            pthis->actionFunc = func_80A56900;
        }
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
    }
}

void func_80A56900(EnHeishi4* pthis, GlobalContext* globalCtx) {
    f32 frames = Animation_GetLastFrame(&gEnHeishiDyingGuardTalkAnim);

    Animation_Change(&pthis->skelAnime, &gEnHeishiDyingGuardTalkAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = func_80A56994;
}

void func_80A56994(EnHeishi4* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    func_80038290(globalCtx, &pthis->actor, &pthis->unk_260, &pthis->unk_266, pthis->actor.focus.pos);
    if ((pthis->unk_282 == Message_GetState(&globalCtx->msgCtx)) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        gSaveContext.infTable[6] |= 0x1000;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = func_80A56A50;
    }
}

void func_80A56A50(EnHeishi4* pthis, GlobalContext* globalCtx) {
    f32 frames = Animation_GetLastFrame(&gEnHeishiDyingGuardDieAnim);

    pthis->unk_288 = frames;
    Animation_Change(&pthis->skelAnime, &gEnHeishiDyingGuardDieAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = func_80A56ACC;
}

void func_80A56ACC(EnHeishi4* pthis, GlobalContext* globalCtx) {
    f32 currentFrame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_288 <= currentFrame) {
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actionFunc = func_80A5673C;
    }
}

void func_80A56B40(EnHeishi4* pthis, GlobalContext* globalCtx) {
    s16 reactionOffset;

    SkelAnime_Update(&pthis->skelAnime);
    reactionOffset = (pthis->type - 4);
    if (reactionOffset < 0) {
        reactionOffset = 0;
    }
    if (reactionOffset >= 3) {
        reactionOffset = 1;
    }
    if (Text_GetFaceReaction(globalCtx, sFaceReactionSets[reactionOffset]) != 0) {
        if (pthis->unk_2B4 == 0) {
            if ((pthis->type == HEISHI4_AT_KAKRIKO_ENTRANCE) || (pthis->type == HEISHI4_AT_IMPAS_HOUSE)) {
                pthis->actionFunc = func_80A563BC;
                return;
            }
            if (pthis->type == HEISHI4_AT_MARKET_NIGHT) {
                pthis->actionFunc = func_80A56614;
                return;
            }
        }
    } else {
        if (pthis->unk_2B4 != 0) {
            if ((pthis->type == HEISHI4_AT_KAKRIKO_ENTRANCE) || (pthis->type == HEISHI4_AT_IMPAS_HOUSE)) {
                pthis->actionFunc = func_80A563BC;
                return;
            }
            if (pthis->type == HEISHI4_AT_MARKET_NIGHT) {
                pthis->actionFunc = func_80A56614;
                return;
            }
        }
    }
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if ((pthis->type == HEISHI4_AT_KAKRIKO_ENTRANCE) || (pthis->type == HEISHI4_AT_IMPAS_HOUSE)) {
            pthis->unk_284 = 1;
            pthis->actionFunc = func_80A563BC;
            return;
        }
        if (pthis->type == HEISHI4_AT_MARKET_NIGHT) {
            pthis->actionFunc = func_80A56614;
            return;
        }
    }
    func_8002F2F4(&pthis->actor, globalCtx);
}

void EnHeishi4_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi4* pthis = (EnHeishi4*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    thisx->world.pos.x = pthis->pos.x;
    thisx->world.pos.y = pthis->pos.y;
    thisx->world.pos.z = pthis->pos.z;
    Actor_SetFocus(thisx, pthis->height);
    if (pthis->type != HEISHI4_AT_MARKET_DYING) {
        pthis->unk_28C.unk_18 = player->actor.world.pos;
        if (!LINK_IS_ADULT) {
            pthis->unk_28C.unk_18.y = (player->actor.world.pos.y - 10.0f);
        }
        func_80034A14(thisx, &pthis->unk_28C, 2, 4);
        pthis->unk_260 = pthis->unk_28C.unk_08;
        pthis->unk_266 = pthis->unk_28C.unk_0E;
    }
    pthis->unk_27E += 1;
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(thisx);
    Actor_UpdateBgCheckInfo(globalCtx, thisx, 10.0f, 10.0f, 30.0f, 0x1D);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnHeishi_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                              void* thisx) {
    EnHeishi4* pthis = (EnHeishi4*)thisx;

    if (limbIndex == 9) {
        rot->x += pthis->unk_266.y;
    }
    if (limbIndex == 16) {
        rot->x += pthis->unk_260.y;
        rot->z += pthis->unk_260.z;
    }
    return false;
}

void EnHeishi4_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHeishi4* pthis = (EnHeishi4*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHeishi_OverrideLimbDraw, NULL,
                      pthis);
}

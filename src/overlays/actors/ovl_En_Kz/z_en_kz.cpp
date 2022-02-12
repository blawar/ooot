#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KZ_Z_EN_KZ_C
#include "actor_common.h"
/*
 * File: z_en_kz.c
 * Overlay: ovl_En_Kz
 * Description: King Zora
 */

#include "z_en_kz.h"
#include "objects/object_kz/object_kz.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnKz_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKz_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKz_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKz_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnKz_PreMweepWait(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_SetupMweep(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_Mweep(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_StopMweep(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_Wait(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_SetupGetItem(EnKz* pthis, GlobalContext* globalCtx);
void EnKz_StartTimer(EnKz* pthis, GlobalContext* globalCtx);

ActorInit En_Kz_InitVars = {
    ACTOR_EN_KZ,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KZ,
    sizeof(EnKz),
    (ActorFunc)EnKz_Init,
    (ActorFunc)EnKz_Destroy,
    (ActorFunc)EnKz_Update,
    (ActorFunc)EnKz_Draw,
};

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
    { 80, 120, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

static struct_80034EC0_Entry sAnimations[] = {
    { &gKzIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gKzIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gKzMweepAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
};

u16 EnKz_GetTextNoMaskChild(GlobalContext* globalCtx, EnKz* pthis) {
    Player* player = GET_PLAYER(globalCtx);

    if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
        return 0x402B;
    } else if (gSaveContext.eventChkInf[3] & 8) {
        return 0x401C;
    } else {
        player->exchangeItemId = EXCH_ITEM_LETTER_RUTO;
        return 0x401A;
    }
}

u16 EnKz_GetTextNoMaskAdult(GlobalContext* globalCtx, EnKz* pthis) {
    Player* player = GET_PLAYER(globalCtx);

    if (INV_CONTENT(ITEM_TRADE_ADULT) >= ITEM_FROG) {
        if (!(gSaveContext.infTable[19] & 0x200)) {
            if (CHECK_OWNED_EQUIP(EQUIP_TUNIC, 2)) {
                return 0x401F;
            } else {
                return 0x4012;
            }
        } else {
            return CHECK_QUEST_ITEM(QUEST_SONG_SERENADE) ? 0x4045 : 0x401A;
        }
    } else {
        player->exchangeItemId = EXCH_ITEM_PRESCRIPTION;
        return 0x4012;
    }
}

u16 EnKz_GetText(GlobalContext* globalCtx, Actor* thisx) {
    EnKz* pthis = (EnKz*)thisx;
    u16 reactionText = Text_GetFaceReaction(globalCtx, 0x1E);

    if (reactionText != 0) {
        return reactionText;
    }

    if (LINK_IS_ADULT) {
        return EnKz_GetTextNoMaskAdult(globalCtx, pthis);
    } else {
        return EnKz_GetTextNoMaskChild(globalCtx, pthis);
    }
}

s16 func_80A9C6C0(GlobalContext* globalCtx, Actor* thisx) {
    EnKz* pthis = (EnKz*)thisx;
    s16 ret = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_DONE:
            ret = 0;
            switch (pthis->actor.textId) {
                case 0x4012:
                    gSaveContext.infTable[19] |= 0x200;
                    ret = 2;
                    break;
                case 0x401B:
                    ret = !Message_ShouldAdvance(globalCtx) ? 1 : 2;
                    break;
                case 0x401F:
                    gSaveContext.infTable[19] |= 0x200;
                    break;
            }
            break;
        case TEXT_STATE_DONE_FADING:
            if (pthis->actor.textId != 0x4014) {
                if (pthis->actor.textId == 0x401B && !pthis->sfxPlayed) {
                    Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                           &D_801333E8);
                    pthis->sfxPlayed = true;
                }
            } else if (!pthis->sfxPlayed) {
                Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                pthis->sfxPlayed = true;
            }
            break;
        case TEXT_STATE_CHOICE:
            if (!Message_ShouldAdvance(globalCtx)) {
                break;
            }
            if (pthis->actor.textId == 0x4014) {
                if (globalCtx->msgCtx.choiceIndex == 0) {
                    EnKz_SetupGetItem(pthis, globalCtx);
                    ret = 2;
                } else {
                    pthis->actor.textId = 0x4016;
                    Message_ContinueTextbox(globalCtx, pthis->actor.textId);
                }
            }
            break;
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx)) {
                ret = 2;
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_CLOSING:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            break;
    }
    return ret;
}

void EnKz_UpdateEyes(EnKz* pthis) {
    if (DECR(pthis->blinkTimer) == 0) {
        pthis->eyeIdx += 1;
        if (pthis->eyeIdx >= 3) {
            pthis->blinkTimer = Rand_S16Offset(30, 30);
            pthis->eyeIdx = 0;
        }
    }
}

s32 func_80A9C95C(GlobalContext* globalCtx, EnKz* pthis, s16* arg2, f32 unkf, callback1_800343CC callback1,
                  callback2_800343CC callback2) {
    Player* player = GET_PLAYER(globalCtx);
    s16 sp32;
    s16 sp30;
    f32 xzDistToPlayer;
    f32 yaw;

    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        *arg2 = 1;
        return 1;
    }

    if (*arg2 != 0) {
        *arg2 = callback2(globalCtx, &pthis->actor);
        return 0;
    }

    yaw = Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos);
    yaw -= pthis->actor.shape.rot.y;
    if ((fabsf(yaw) > 1638.0f) || (pthis->actor.xzDistToPlayer < 265.0f)) {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        return 0;
    }

    pthis->actor.flags |= ACTOR_FLAG_0;

    Actor_GetScreenPos(globalCtx, &pthis->actor, &sp32, &sp30);
    if (!((sp32 >= -30) && (sp32 < 361) && (sp30 >= -10) && (sp30 < 241))) {
        return 0;
    }

    xzDistToPlayer = pthis->actor.xzDistToPlayer;
    pthis->actor.xzDistToPlayer = Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos);
    if (func_8002F2CC(&pthis->actor, globalCtx, unkf) == 0) {
        pthis->actor.xzDistToPlayer = xzDistToPlayer;
        return 0;
    }
    pthis->actor.xzDistToPlayer = xzDistToPlayer;
    pthis->actor.textId = callback1(globalCtx, &pthis->actor);

    return 0;
}

void func_80A9CB18(EnKz* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (func_80A9C95C(globalCtx, pthis, &pthis->unk_1E0.unk_00, 340.0f, EnKz_GetText, func_80A9C6C0)) {
        if ((pthis->actor.textId == 0x401A) && !(gSaveContext.eventChkInf[3] & 8)) {
            if (func_8002F368(globalCtx) == EXCH_ITEM_LETTER_RUTO) {
                pthis->actor.textId = 0x401B;
                pthis->sfxPlayed = false;
            } else {
                pthis->actor.textId = 0x401A;
            }
            player->actor.textId = pthis->actor.textId;
            return;
        }

        if (LINK_IS_ADULT) {
            if ((INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_PRESCRIPTION) &&
                (func_8002F368(globalCtx) == EXCH_ITEM_PRESCRIPTION)) {
                pthis->actor.textId = 0x4014;
                pthis->sfxPlayed = false;
                player->actor.textId = pthis->actor.textId;
                pthis->isTrading = true;
                return;
            }

            pthis->isTrading = false;
            if (gSaveContext.infTable[19] & 0x200) {
                pthis->actor.textId = CHECK_QUEST_ITEM(QUEST_SONG_SERENADE) ? 0x4045 : 0x401A;
                player->actor.textId = pthis->actor.textId;
            } else {
                pthis->actor.textId = CHECK_OWNED_EQUIP(EQUIP_TUNIC, 2) ? 0x401F : 0x4012;
                player->actor.textId = pthis->actor.textId;
            }
        }
    }
}

s32 EnKz_FollowPath(EnKz* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* pointPos;
    f32 pathDiffX;
    f32 pathDiffZ;

    if ((pthis->actor.params & 0xFF00) == 0xFF00) {
        return 0;
    }

    path = &globalCtx->setupPathList[(pthis->actor.params & 0xFF00) >> 8];
    pointPos = SEGMENTED_TO_VIRTUAL(path->points);
    pointPos += pthis->waypoint;

    pathDiffX = pointPos->x - pthis->actor.world.pos.x;
    pathDiffZ = pointPos->z - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.world.rot.y, (Math_FAtan2F(pathDiffX, pathDiffZ) * (0x8000 / M_PI)), 0xA, 0x3E8, 1);

    if ((SQ(pathDiffX) + SQ(pathDiffZ)) < 10.0f) {
        pthis->waypoint++;
        if (pthis->waypoint >= path->count) {
            pthis->waypoint = 0;
        }
        return 1;
    }
    return 0;
}

s32 EnKz_SetMovedPos(EnKz* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* lastPointPos;

    if ((pthis->actor.params & 0xFF00) == 0xFF00) {
        return 0;
    }

    path = &globalCtx->setupPathList[(pthis->actor.params & 0xFF00) >> 8];
    lastPointPos = SEGMENTED_TO_VIRTUAL(path->points);
    lastPointPos += path->count - 1;

    pthis->actor.world.pos.x = lastPointPos->x;
    pthis->actor.world.pos.y = lastPointPos->y;
    pthis->actor.world.pos.z = lastPointPos->z;

    return 1;
}

void EnKz_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKz* pthis = (EnKz*)thisx;
    s32 pad;

    SkelAnime_InitFlex(globalCtx, &pthis->skelanime, &gKzSkel, NULL, pthis->jointTable, pthis->morphTable,
                       12);
    ActorShape_Init(&pthis->actor.shape, 0.0, NULL, 0.0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    Actor_SetScale(&pthis->actor, 0.01);
    pthis->actor.targetMode = 3;
    pthis->unk_1E0.unk_00 = 0;
    func_80034EC0(&pthis->skelanime, sAnimations, 0);

    if (gSaveContext.eventChkInf[3] & 8) {
        EnKz_SetMovedPos(pthis, globalCtx);
    }

    if (LINK_IS_ADULT) {
        if (!(gSaveContext.infTable[19] & 0x100)) {
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BG_ICE_SHELTER,
                               pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0,
                               0x04FF);
        }
        pthis->actionFunc = EnKz_Wait;
    } else {
        pthis->actionFunc = EnKz_PreMweepWait;
    }
}

void EnKz_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnKz* pthis = (EnKz*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnKz_PreMweepWait(EnKz* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 2) {
        func_80034EC0(&pthis->skelanime, sAnimations, 2);
        pthis->unk_1E0.unk_00 = 0;
        pthis->actionFunc = EnKz_SetupMweep;
    } else {
        func_80034F54(globalCtx, pthis->unk_2A6, pthis->unk_2BE, 12);
    }
}

void EnKz_SetupMweep(EnKz* pthis, GlobalContext* globalCtx) {
    Vec3f unused = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Vec3f initPos;

    pthis->cutsceneCamera = Gameplay_CreateSubCamera(globalCtx);
    pthis->gameplayCamera = globalCtx->activeCamera;
    Gameplay_ChangeCameraStatus(globalCtx, pthis->gameplayCamera, CAM_STAT_WAIT);
    Gameplay_ChangeCameraStatus(globalCtx, pthis->cutsceneCamera, CAM_STAT_ACTIVE);
    pos = pthis->actor.world.pos;
    initPos = pthis->actor.home.pos;
    pos.y += 60.0f;
    initPos.y += -100.0f;
    initPos.z += 260.0f;
    Gameplay_CameraSetAtEye(globalCtx, pthis->cutsceneCamera, &pos, &initPos);
    func_8002DF54(globalCtx, &pthis->actor, 8);
    pthis->actor.speedXZ = 0.1f;
    pthis->actionFunc = EnKz_Mweep;
}

void EnKz_Mweep(EnKz* pthis, GlobalContext* globalCtx) {
    Vec3f unused = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Vec3f initPos;

    pos = pthis->actor.world.pos;
    initPos = pthis->actor.home.pos;
    pos.y += 60.0f;
    initPos.y += -100.0f;
    initPos.z += 260.0f;
    Gameplay_CameraSetAtEye(globalCtx, pthis->cutsceneCamera, &pos, &initPos);
    if ((EnKz_FollowPath(pthis, globalCtx) == 1) && (pthis->waypoint == 0)) {
        func_80034EC0(&pthis->skelanime, sAnimations, 1);
        Inventory_ReplaceItem(globalCtx, ITEM_LETTER_RUTO, ITEM_BOTTLE);
        EnKz_SetMovedPos(pthis, globalCtx);
        gSaveContext.eventChkInf[3] |= 8;
        pthis->actor.speedXZ = 0.0;
        pthis->actionFunc = EnKz_StopMweep;
    }
    if (pthis->skelanime.curFrame == 13.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_VO_KZ_MOVE);
    }
}

void EnKz_StopMweep(EnKz* pthis, GlobalContext* globalCtx) {
    Gameplay_ChangeCameraStatus(globalCtx, pthis->gameplayCamera, CAM_STAT_ACTIVE);
    Gameplay_ClearCamera(globalCtx, pthis->cutsceneCamera);
    func_8002DF54(globalCtx, &pthis->actor, 7);
    pthis->actionFunc = EnKz_Wait;
}

void EnKz_Wait(EnKz* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 2) {
        pthis->actionFunc = EnKz_SetupGetItem;
        EnKz_SetupGetItem(pthis, globalCtx);
    } else {
        func_80034F54(globalCtx, pthis->unk_2A6, pthis->unk_2BE, 12);
    }
}

void EnKz_SetupGetItem(EnKz* pthis, GlobalContext* globalCtx) {
    s32 getItemId;
    f32 xzRange;
    f32 yRange;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->unk_1E0.unk_00 = 1;
        pthis->actionFunc = EnKz_StartTimer;
    } else {
        getItemId = pthis->isTrading == true ? GI_FROG : GI_TUNIC_ZORA;
        yRange = fabsf(pthis->actor.yDistToPlayer) + 1.0f;
        xzRange = pthis->actor.xzDistToPlayer + 1.0f;
        func_8002F434(&pthis->actor, globalCtx, getItemId, xzRange, yRange);
    }
}

void EnKz_StartTimer(EnKz* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_FROG) {
            func_80088AA0(180); // start timer2 with 3 minutes
            gSaveContext.eventInf[1] &= ~1;
        }
        pthis->unk_1E0.unk_00 = 0;
        pthis->actionFunc = EnKz_Wait;
    }
}

void EnKz_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnKz* pthis = (EnKz*)thisx;
    s32 pad;

    if (LINK_IS_ADULT && !(gSaveContext.infTable[19] & 0x100)) {
        gSaveContext.infTable[19] |= 0x100;
    }
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelanime);
    EnKz_UpdateEyes(pthis);
    Actor_MoveForward(&pthis->actor);
    if (pthis->actionFunc != EnKz_StartTimer) {
        func_80A9CB18(pthis, globalCtx);
    }
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnKz_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnKz* pthis = (EnKz*)thisx;

    if (limbIndex == 8 || limbIndex == 9 || limbIndex == 10) {
        rot->y += Math_SinS(pthis->unk_2A6[limbIndex]) * 200.0f;
        rot->z += Math_CosS(pthis->unk_2BE[limbIndex]) * 200.0f;
    }
    if (limbIndex) {}
    return false;
}

void EnKz_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnKz* pthis = (EnKz*)thisx;
    Vec3f mult = { 2600.0f, 0.0f, 0.0f };

    if (limbIndex == 11) {
        Matrix_MultVec3f(&mult, &pthis->actor.focus.pos);
    }
}

void EnKz_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* sEyeSegments[] = {
        gKzEyeOpenTex,
        gKzEyeHalfTex,
        gKzEyeClosedTex,
    };
    EnKz* pthis = (EnKz*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_kz.c", 1259);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeSegments[pthis->eyeIdx]));
    func_800943C8(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, pthis->skelanime.dListCount,
                          EnKz_OverrideLimbDraw, EnKz_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_kz.c", 1281);
}

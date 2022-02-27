#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MD_Z_EN_MD_C
#include "actor_common.h"
/*
 * File: z_en_md.c
 * Overlay: ovl_En_Md
 * Description: Mido
 */

#include "z_en_md.h"
#include "objects/object_md/object_md.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "def/audio_bank.h"
#include "def/math_float.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera_data.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMd_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AAB874(EnMd* pthis, GlobalContext* globalCtx);
void func_80AAB8F8(EnMd* pthis, GlobalContext* globalCtx);
void func_80AAB948(EnMd* pthis, GlobalContext* globalCtx);
void func_80AABC10(EnMd* pthis, GlobalContext* globalCtx);
void func_80AABD0C(EnMd* pthis, GlobalContext* globalCtx);

static void* sEyeTextures_70[] = {
    gMidoEyeOpenTex,
    gMidoEyeHalfTex,
    gMidoEyeClosedTex,
};


ActorInit En_Md_InitVars = {
    ACTOR_EN_MD,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MD,
    sizeof(EnMd),
    (ActorFunc)EnMd_Init,
    (ActorFunc)EnMd_Destroy,
    (ActorFunc)EnMd_Update,
    (ActorFunc)EnMd_Draw,
    (ActorFunc)EnMd_Reset,
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
    { 36, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

static struct_80034EC0_Entry sAnimations[] = {
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gMidoRaiseHand1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoHaltAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoPutHandDownAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoAnnoyedPointedHeadIdle1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoAnnoyedPointedHeadIdle2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoAnim_92B0, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoWalkingAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoHandsOnHipsTransitionAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gMidoSlamAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoRaiseHand2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoAngryHeadTurnAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
};

void func_80AAA250(EnMd* pthis) {
    f32 startFrame;

    startFrame = pthis->skelAnime.startFrame;
    pthis->skelAnime.startFrame = pthis->skelAnime.endFrame;
    pthis->skelAnime.curFrame = pthis->skelAnime.endFrame;
    pthis->skelAnime.endFrame = startFrame;
    pthis->skelAnime.playSpeed = -1.0f;
}

void func_80AAA274(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 2);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 3);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA308(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 4);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 5);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA39C(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 2);
            func_80AAA250(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 7);
                pthis->unk_20A++;
            } else {
                break;
            }
        case 2:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 8);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA474(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 7);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 10);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA508(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 2);
            func_80AAA250(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 10);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA5A4(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 9);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 6);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA638(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 9);
            func_80AAA250(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 10);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA6D4(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 11);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 6);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA768(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 12);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 3);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA7FC(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 13);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 6);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA890(EnMd* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 7);
            func_80AAA250(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 10);
                pthis->unk_20A++;
            }
    }
}

void func_80AAA92C(EnMd* pthis, u8 arg1) {
    pthis->unk_20B = arg1;
    pthis->unk_20A = 0;
}

void func_80AAA93C(EnMd* pthis) {
    switch (pthis->unk_20B) {
        case 1:
            func_80AAA274(pthis);
            break;
        case 2:
            func_80AAA308(pthis);
            break;
        case 3:
            func_80AAA39C(pthis);
            break;
        case 4:
            func_80AAA474(pthis);
            break;
        case 5:
            func_80AAA508(pthis);
            break;
        case 6:
            func_80AAA5A4(pthis);
            break;
        case 7:
            func_80AAA638(pthis);
            break;
        case 8:
            func_80AAA6D4(pthis);
            break;
        case 9:
            func_80AAA768(pthis);
            break;
        case 10:
            func_80AAA7FC(pthis);
            break;
        case 11:
            func_80AAA890(pthis);
    }
}

void func_80AAAA24(EnMd* pthis) {
    if (pthis->unk_1E0.unk_00 != 0) {
        switch (pthis->actor.textId) {
            case 0x102F:
                if ((pthis->unk_208 == 0) && (pthis->unk_20B != 1)) {
                    func_80AAA92C(pthis, 1);
                }
                if ((pthis->unk_208 == 2) && (pthis->unk_20B != 2)) {
                    func_80AAA92C(pthis, 2);
                }
                if ((pthis->unk_208 == 5) && (pthis->unk_20B != 8)) {
                    func_80AAA92C(pthis, 8);
                }
                if ((pthis->unk_208 == 11) && (pthis->unk_20B != 9)) {
                    func_80AAA92C(pthis, 9);
                }
                break;
            case 0x1033:
                if ((pthis->unk_208 == 0) && (pthis->unk_20B != 1)) {
                    func_80AAA92C(pthis, 1);
                }
                if ((pthis->unk_208 == 1) && (pthis->unk_20B != 2)) {
                    func_80AAA92C(pthis, 2);
                }
                if ((pthis->unk_208 == 5) && (pthis->unk_20B != 10)) {
                    func_80AAA92C(pthis, 10);
                }
                if ((pthis->unk_208 == 7) && (pthis->unk_20B != 9)) {
                    func_80AAA92C(pthis, 9);
                }
                break;
            case 0x1030:
            case 0x1034:
            case 0x1045:
                if ((pthis->unk_208 == 0) && (pthis->unk_20B != 1)) {
                    func_80AAA92C(pthis, 1);
                }
                break;
            case 0x1046:
                if ((pthis->unk_208 == 0) && (pthis->unk_20B != 6)) {
                    func_80AAA92C(pthis, 6);
                }
                break;
        }
    } else if (pthis->skelAnime.animation != &gMidoHandsOnHipsIdleAnim) {
        func_80034EC0(&pthis->skelAnime, sAnimations, 10);
        func_80AAA92C(pthis, 0);
    }

    func_80AAA93C(pthis);
}

s16 func_80AAAC78(EnMd* pthis, GlobalContext* globalCtx) {
    s16 dialogState = Message_GetState(&globalCtx->msgCtx);

    if ((pthis->unk_209 == TEXT_STATE_AWAITING_NEXT) || (pthis->unk_209 == TEXT_STATE_EVENT) ||
        (pthis->unk_209 == TEXT_STATE_CLOSING) || (pthis->unk_209 == TEXT_STATE_DONE_HAS_NEXT)) {
        if (pthis->unk_209 != dialogState) {
            pthis->unk_208++;
        }
    }

    pthis->unk_209 = dialogState;
    return dialogState;
}

u16 EnMd_GetTextKokiriForest(GlobalContext* globalCtx, EnMd* pthis) {
    u16 reactionText = Text_GetFaceReaction(globalCtx, 0x11);

    if (reactionText != 0) {
        return reactionText;
    }

    pthis->unk_208 = 0;
    pthis->unk_209 = TEXT_STATE_NONE;

    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        return 0x1045;
    }

    if (gSaveContext.eventChkInf[0] & 0x10) {
        return 0x1034;
    }

    if ((CUR_EQUIP_VALUE(EQUIP_SHIELD) == 1) && (CUR_EQUIP_VALUE(EQUIP_SWORD) == 1)) {
        return 0x1033;
    }

    if (gSaveContext.infTable[0] & 0x1000) {
        return 0x1030;
    }

    return 0x102F;
}

u16 EnMd_GetTextKokiriHome(GlobalContext* globalCtx, EnMd* pthis) {
    pthis->unk_208 = 0;
    pthis->unk_209 = TEXT_STATE_NONE;

    if (gSaveContext.eventChkInf[4] & 1) {
        return 0x1028;
    }

    return 0x1046;
}

u16 EnMd_GetTextLostWoods(GlobalContext* globalCtx, EnMd* pthis) {
    pthis->unk_208 = 0;
    pthis->unk_209 = TEXT_STATE_NONE;

    if (gSaveContext.eventChkInf[4] & 0x100) {
        if (gSaveContext.infTable[1] & 0x200) {
            return 0x1071;
        }
        return 0x1070;
    }

    if (gSaveContext.eventChkInf[0] & 0x400) {
        return 0x1068;
    }

    if (gSaveContext.infTable[1] & 0x20) {
        return 0x1061;
    }

    return 0x1060;
}

u16 EnMd_GetText(GlobalContext* globalCtx, Actor* thisx) {
    EnMd* pthis = (EnMd*)thisx;

    switch (globalCtx->sceneNum) {
        case SCENE_SPOT04:
            return EnMd_GetTextKokiriForest(globalCtx, pthis);
        case SCENE_KOKIRI_HOME4:
            return EnMd_GetTextKokiriHome(globalCtx, pthis);
        case SCENE_SPOT10:
            return EnMd_GetTextLostWoods(globalCtx, pthis);
        default:
            return 0;
    }
}

s16 func_80AAAF04(GlobalContext* globalCtx, Actor* thisx) {
    EnMd* pthis = (EnMd*)thisx;
    switch (func_80AAAC78(pthis, globalCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_CHOICE:
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            return 1;
        case TEXT_STATE_CLOSING:
            switch (pthis->actor.textId) {
                case 0x1028:
                    gSaveContext.eventChkInf[0] |= 0x8000;
                    break;
                case 0x102F:
                    gSaveContext.eventChkInf[0] |= 4;
                    gSaveContext.infTable[0] |= 0x1000;
                    break;
                case 0x1060:
                    gSaveContext.infTable[1] |= 0x20;
                    break;
                case 0x1070:
                    gSaveContext.infTable[1] |= 0x200;
                    break;
                case 0x1033:
                case 0x1067:
                    return 2;
            }
            return 0;
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx)) {
                return 2;
            }
        default:
            return 1;
    }
}

u8 EnMd_ShouldSpawn(EnMd* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_SPOT04) {
        if (!(gSaveContext.eventChkInf[1] & 0x1000) && !(gSaveContext.eventChkInf[4] & 1)) {
            return 1;
        }
    }

    if (globalCtx->sceneNum == SCENE_KOKIRI_HOME4) {
        if (((gSaveContext.eventChkInf[1] & 0x1000) != 0) || ((gSaveContext.eventChkInf[4] & 1) != 0)) {
            if (!LINK_IS_ADULT) {
                return 1;
            }
        }
    }

    if (globalCtx->sceneNum == SCENE_SPOT10) {
        return 1;
    }

    return 0;
}

void EnMd_UpdateEyes(EnMd* pthis) {
    if (DECR(pthis->blinkTimer) == 0) {
        pthis->eyeIdx++;
        if (pthis->eyeIdx > 2) {
            pthis->blinkTimer = Rand_S16Offset(30, 30);
            pthis->eyeIdx = 0;
        }
    }
}

void func_80AAB158(EnMd* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 absYawDiff;
    s16 temp;
    s16 temp2;
    s16 yawDiff;

    if (pthis->actor.xzDistToPlayer < 170.0f) {
        yawDiff = (f32)pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        absYawDiff = ABS(yawDiff);

        temp = (absYawDiff <= func_800347E8(2)) ? 2 : 1;
        temp2 = 1;
    } else {
        temp = 1;
        temp2 = 0;
    }

    if (pthis->unk_1E0.unk_00 != 0) {
        temp = 4;
    }

    if (pthis->actionFunc == func_80AABD0C) {
        temp = 1;
        temp2 = 0;
    }
    if (pthis->actionFunc == func_80AAB8F8) {
        temp = 4;
        temp2 = 1;
    }

    if ((globalCtx->csCtx.state != CS_STATE_IDLE) || gDbgCamEnabled) {
        pthis->unk_1E0.unk_18 = globalCtx->view.eye;
        pthis->unk_1E0.unk_14 = 40.0f;
        temp = 2;
    } else {
        pthis->unk_1E0.unk_18 = player->actor.world.pos;
        pthis->unk_1E0.unk_14 = (gSaveContext.linkAge > 0) ? 0.0f : -18.0f;
    }

    func_80034A14(&pthis->actor, &pthis->unk_1E0, 2, temp);
    if (pthis->actionFunc != func_80AABC10) {
        if (temp2) {
            func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E0.unk_00, pthis->collider.dim.radius + 30.0f,
                          EnMd_GetText, func_80AAAF04);
        }
    }
}

u8 EnMd_FollowPath(EnMd* pthis, GlobalContext* globalCtx) {
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
    Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_FAtan2F(pathDiffX, pathDiffZ) * (65536.0f / (2 * M_PI)), 4, 4000,
                       1);

    if ((SQ(pathDiffX) + SQ(pathDiffZ)) < 100.0f) {
        pthis->waypoint++;
        if (pthis->waypoint >= path->count) {
            pthis->waypoint = 0;
        }
        return 1;
    }
    return 0;
}

u8 EnMd_SetMovedPos(EnMd* pthis, GlobalContext* globalCtx) {
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

void func_80AAB5A4(EnMd* pthis, GlobalContext* globalCtx) {
    f32 temp;

    if (globalCtx->sceneNum != SCENE_KOKIRI_HOME4) {
        temp = (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !(gSaveContext.eventChkInf[1] & 0x1000) &&
                (globalCtx->sceneNum == SCENE_SPOT04))
                   ? 100.0f
                   : 400.0f;
        pthis->alpha = func_80034DD4(&pthis->actor, globalCtx, pthis->alpha, temp);
        pthis->actor.shape.shadowAlpha = pthis->alpha;
    } else {
        pthis->alpha = 255;
        pthis->actor.shape.shadowAlpha = pthis->alpha;
    }
}

void EnMd_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* pthis = (EnMd*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gMidoSkel, NULL, pthis->jointTable, pthis->morphTable, 17);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    if (!EnMd_ShouldSpawn(pthis, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    func_80034EC0(&pthis->skelAnime, sAnimations, 0);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.targetMode = 6;
    pthis->alpha = 255;
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ELF, pthis->actor.world.pos.x,
                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, FAIRY_KOKIRI);

    if (((globalCtx->sceneNum == SCENE_SPOT04) && !(gSaveContext.eventChkInf[0] & 0x10)) ||
        ((globalCtx->sceneNum == SCENE_SPOT04) && (gSaveContext.eventChkInf[0] & 0x10) &&
         CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) ||
        ((globalCtx->sceneNum == SCENE_SPOT10) && !(gSaveContext.eventChkInf[0] & 0x400))) {
        pthis->actor.home.pos = pthis->actor.world.pos;
        pthis->actionFunc = func_80AAB948;
        return;
    }

    if (globalCtx->sceneNum != SCENE_KOKIRI_HOME4) {
        EnMd_SetMovedPos(pthis, globalCtx);
    }

    pthis->actionFunc = func_80AAB874;
}

void EnMd_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* pthis = (EnMd*)thisx;
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AAB874(EnMd* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(globalCtx, pthis->unk_214, pthis->unk_236, 17);
    } else if ((pthis->unk_1E0.unk_00 == 0) && (pthis->unk_20B != 7)) {
        func_80AAA92C(pthis, 7);
    }

    func_80AAAA24(pthis);
}

void func_80AAB8F8(EnMd* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(globalCtx, pthis->unk_214, pthis->unk_236, 17);
    }
    func_80AAA93C(pthis);
}

void func_80AAB948(EnMd* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 temp;
    Actor* actorToBlock = &GET_PLAYER(globalCtx)->actor;
    s16 yaw;

    func_80AAAA24(pthis);

    if (pthis->unk_1E0.unk_00 == 0) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;

        yaw = Math_Vec3f_Yaw(&pthis->actor.home.pos, &actorToBlock->world.pos);

        pthis->actor.world.pos.x = pthis->actor.home.pos.x;
        pthis->actor.world.pos.x += 60.0f * Math_SinS(yaw);

        pthis->actor.world.pos.z = pthis->actor.home.pos.z;
        pthis->actor.world.pos.z += 60.0f * Math_CosS(yaw);

        temp = fabsf((f32)pthis->actor.yawTowardsPlayer - yaw) * 0.001f * 3.0f;
        pthis->skelAnime.playSpeed = CLAMP(temp, 1.0f, 3.0f);
    }

    if (pthis->unk_1E0.unk_00 == 2) {
        if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !(gSaveContext.eventChkInf[1] & 0x1000) &&
            (globalCtx->sceneNum == SCENE_SPOT04)) {
            globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        }

        if (globalCtx->sceneNum == SCENE_SPOT04) {
            gSaveContext.eventChkInf[0] |= 0x10;
        }
        if (globalCtx->sceneNum == SCENE_SPOT10) {
            gSaveContext.eventChkInf[0] |= 0x400;
        }

        func_80AAA92C(pthis, 3);
        func_80AAA93C(pthis);
        pthis->waypoint = 1;
        pthis->unk_1E0.unk_00 = 0;
        pthis->actionFunc = func_80AABD0C;
        pthis->actor.speedXZ = 1.5f;
        return;
    }

    if (pthis->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(globalCtx, pthis->unk_214, pthis->unk_236, 17);
    }

    if ((pthis->unk_1E0.unk_00 == 0) && (globalCtx->sceneNum == SCENE_SPOT10)) {
        if (player->stateFlags2 & 0x1000000) {
            player->stateFlags2 |= 0x2000000;
            player->unk_6A8 = &pthis->actor;
            func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_SARIA);
            pthis->actionFunc = func_80AABC10;
            return;
        }

        if (pthis->actor.xzDistToPlayer < (30.0f + pthis->collider.dim.radius)) {
            player->stateFlags2 |= 0x800000;
        }
    }
}

void func_80AABC10(EnMd* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_04) {
        pthis->actionFunc = func_80AAB948;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
        Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &D_801333D4, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        pthis->actor.textId = 0x1067;
        func_8002F2CC(&pthis->actor, globalCtx, pthis->collider.dim.radius + 30.0f);

        pthis->actionFunc = func_80AAB948;
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else {
        player->stateFlags2 |= 0x800000;
    }
}

void func_80AABD0C(EnMd* pthis, GlobalContext* globalCtx) {
    func_80034F54(globalCtx, pthis->unk_214, pthis->unk_236, 17);
    func_80AAA93C(pthis);

    if (!(EnMd_FollowPath(pthis, globalCtx)) || (pthis->waypoint != 0)) {
        pthis->actor.shape.rot = pthis->actor.world.rot;
        return;
    }

    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !(gSaveContext.eventChkInf[1] & 0x1000) &&
        (globalCtx->sceneNum == SCENE_SPOT04)) {
        Message_CloseTextbox(globalCtx);
        gSaveContext.eventChkInf[1] |= 0x1000;
        Actor_Kill(&pthis->actor);
        return;
    }

    func_80AAA92C(pthis, 11);

    pthis->skelAnime.playSpeed = 0.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.home.pos = pthis->actor.world.pos;
    pthis->actionFunc = func_80AAB8F8;
}

void EnMd_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* pthis = (EnMd*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);
    EnMd_UpdateEyes(pthis);
    func_80AAB5A4(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    func_80AAB158(pthis, globalCtx);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnMd_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnMd* pthis = (EnMd*)thisx;
    Vec3s vec;

    if (limbIndex == 16) {
        Matrix_Translate(1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec = pthis->unk_1E0.unk_08;
        Matrix_RotateX((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(-1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }
    if (limbIndex == 9) {
        vec = pthis->unk_1E0.unk_0E;
        Matrix_RotateX((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateY((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
    }

    if (((limbIndex == 9) || (limbIndex == 10)) || (limbIndex == 13)) {
        rot->y += Math_SinS(pthis->unk_214[limbIndex]) * 200.0f;
        rot->z += Math_CosS(pthis->unk_236[limbIndex]) * 200.0f;
    }

    return false;
}

void EnMd_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnMd* pthis = (EnMd*)thisx;
    Vec3f vec = { 400.0f, 0.0f, 0.0f };

    if (limbIndex == 16) {
        Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
    }
}

void EnMd_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMd* pthis = (EnMd*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_md.c", 1280);

    if (pthis->alpha == 255) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures_70[pthis->eyeIdx]));
        func_80034BA0(globalCtx, &pthis->skelAnime, EnMd_OverrideLimbDraw, EnMd_PostLimbDraw, &pthis->actor, pthis->alpha);
    } else if (pthis->alpha != 0) {
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures_70[pthis->eyeIdx]));
        func_80034CC4(globalCtx, &pthis->skelAnime, EnMd_OverrideLimbDraw, EnMd_PostLimbDraw, &pthis->actor, pthis->alpha);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_md.c", 1317);
}

void EnMd_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Md_InitVars = {
        ACTOR_EN_MD,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_MD,
        sizeof(EnMd),
        (ActorFunc)EnMd_Init,
        (ActorFunc)EnMd_Destroy,
        (ActorFunc)EnMd_Update,
        (ActorFunc)EnMd_Draw,
        (ActorFunc)EnMd_Reset,
    };

    sCylinderInit = {
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
        { 36, 46, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

}

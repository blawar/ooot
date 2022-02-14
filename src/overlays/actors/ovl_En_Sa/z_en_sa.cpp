#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SA_Z_EN_SA_C
#include "actor_common.h"
#include "z_en_sa.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "objects/object_sa/object_sa.h"
#include "scenes/overworld/spot04/spot04_scene.h"
#include "scenes/overworld/spot05/spot05_scene.h"
#include "def/code_800F7260.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnSa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSa_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AF6448(EnSa* pthis, GlobalContext* globalCtx);
void func_80AF67D0(EnSa* pthis, GlobalContext* globalCtx);
void func_80AF683C(EnSa* pthis, GlobalContext* globalCtx);
void func_80AF68E4(EnSa* pthis, GlobalContext* globalCtx);
void func_80AF6B20(EnSa* pthis, GlobalContext* globalCtx);

typedef enum {
    /* 0 */ SARIA_EYE_OPEN,
    /* 1 */ SARIA_EYE_HALF,
    /* 2 */ SARIA_EYE_CLOSED,
    /* 3 */ SARIA_EYE_SUPRISED,
    /* 4 */ SARIA_EYE_SAD
} SariaEyeState;

typedef enum {
    /* 0 */ SARIA_MOUTH_CLOSED2,
    /* 1 */ SARIA_MOUTH_SUPRISED,
    /* 2 */ SARIA_MOUTH_CLOSED,
    /* 3 */ SARIA_MOUTH_SMILING_OPEN,
    /* 4 */ SARIA_MOUTH_FROWNING
} SariaMouthState;

ActorInit En_Sa_InitVars = {
    ACTOR_EN_SA,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SA,
    sizeof(EnSa),
    (ActorFunc)EnSa_Init,
    (ActorFunc)EnSa_Destroy,
    (ActorFunc)EnSa_Update,
    (ActorFunc)EnSa_Draw,
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
    { 20, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = {
    0, 0, 0, 0, MASS_IMMOVABLE,
};

static struct_D_80AA1678 sAnimationInfo[] = {
    { &gSariaWaitArmsToSideAnim, 1.0f, ANIMMODE_LOOP, 0.0f },
    { &gSariaLookUpArmExtendedAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gSariaWaveAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gSariaRunAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gSariaWaitArmsToSideAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gSariaLookOverShoulderAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gSariaPlayingOcarinaAnim, 1.0f, ANIMMODE_LOOP, -10.0f },
    { &gSariaStopPlayingOcarinaAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gSariaOcarinaToMouthAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gSariaLinkLearnedSariasSongAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gSariaReturnToOcarinaAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gSariaPlayingOcarinaAnim, 1.0f, ANIMMODE_LOOP, 0.0f },
};

static struct_80034EC0_Entry sAnimations[] = {
    { &gSariaTransitionHandsSideToChestToSideAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gSariaTransitionHandsSideToBackAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -4.0f },
    { &gSariaRightArmExtendedWaitAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gSariaHandsOutAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gSariaStandHandsOnHipsAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gSariaExtendRightArmAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gSariaTransitionHandsSideToHipsAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gSariaHandsBehindBackWaitAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gSariaHandsOnFaceAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gSariaWaitArmsToSideAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
};

s16 func_80AF5560(EnSa* pthis, GlobalContext* globalCtx) {
    s16 textState = Message_GetState(&globalCtx->msgCtx);

    if (pthis->unk_209 == TEXT_STATE_AWAITING_NEXT || pthis->unk_209 == TEXT_STATE_EVENT ||
        pthis->unk_209 == TEXT_STATE_CLOSING || pthis->unk_209 == TEXT_STATE_DONE_HAS_NEXT) {
        if (textState != pthis->unk_209) {
            pthis->unk_208++;
        }
    }
    pthis->unk_209 = textState;
    return textState;
}

u16 func_80AF55E0(GlobalContext* globalCtx, Actor* thisx) {
    EnSa* pthis = (EnSa*)thisx;
    u16 reaction = Text_GetFaceReaction(globalCtx, 0x10);

    if (reaction != 0) {
        return reaction;
    }
    if (CHECK_QUEST_ITEM(QUEST_SONG_SARIA)) {
        return 0x10AD;
    }
    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        pthis->unk_208 = 0;
        pthis->unk_209 = TEXT_STATE_NONE;
        if (gSaveContext.infTable[0] & 0x20) {
            return 0x1048;
        } else {
            return 0x1047;
        }
    }
    if (gSaveContext.eventChkInf[0] & 4) {
        pthis->unk_208 = 0;
        pthis->unk_209 = TEXT_STATE_NONE;
        if (gSaveContext.infTable[0] & 8) {
            return 0x1032;
        } else {
            return 0x1031;
        }
    }
    if (gSaveContext.infTable[0] & 1) {
        pthis->unk_208 = 0;
        pthis->unk_209 = TEXT_STATE_NONE;
        if (gSaveContext.infTable[0] & 2) {
            return 0x1003;
        } else {
            return 0x1002;
        }
    }
    return 0x1001;
}

s16 func_80AF56F4(GlobalContext* globalCtx, Actor* thisx) {
    s16 ret = 1;
    EnSa* pthis = (EnSa*)thisx;

    switch (func_80AF5560(pthis, globalCtx)) {
        case TEXT_STATE_CLOSING:
            switch (pthis->actor.textId) {
                case 0x1002:
                    gSaveContext.infTable[0] |= 2;
                    ret = 0;
                    break;
                case 0x1031:
                    gSaveContext.eventChkInf[0] |= 8;
                    gSaveContext.infTable[0] |= 8;
                    ret = 0;
                    break;
                case 0x1047:
                    gSaveContext.infTable[0] |= 0x20;
                    ret = 0;
                    break;
                default:
                    ret = 0;
                    break;
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_CHOICE:
        case TEXT_STATE_EVENT:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            break;
    }
    return ret;
}

void func_80AF57D8(EnSa* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum != SCENE_SPOT05 ||
        ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) < 0x1555 || pthis->unk_1E0.unk_00 != 0) {
        func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E0.unk_00, pthis->collider.dim.radius + 30.0f, func_80AF55E0,
                      func_80AF56F4);
    }
}

f32 func_80AF5894(EnSa* pthis) {
    f32 endFrame = pthis->skelAnime.endFrame;
    f32 startFrame = pthis->skelAnime.startFrame;

    pthis->skelAnime.startFrame = endFrame;
    pthis->skelAnime.curFrame = endFrame;
    pthis->skelAnime.endFrame = startFrame;
    pthis->skelAnime.playSpeed = -1.0f;
    return startFrame;
}

void func_80AF58B8(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 3);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 2);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF594C(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 8);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 9);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF59E0(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 1);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 7);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF5A74(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 1);
            func_80AF5894(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 9);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF5B10(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 6);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 4);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF5BA4(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 6);
            func_80AF5894(pthis);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 9);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF5C40(EnSa* pthis) {
    switch (pthis->unk_20A) {
        case 0:
            func_80034EC0(&pthis->skelAnime, sAnimations, 5);
            pthis->unk_20A++;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
                func_80034EC0(&pthis->skelAnime, sAnimations, 0);
                pthis->unk_20A++;
            }
            break;
    }
}

void func_80AF5CD4(EnSa* pthis, u8 arg1) {
    pthis->unk_20B = arg1;
    pthis->unk_20A = 0;
}

void func_80AF5CE4(EnSa* pthis) {
    switch (pthis->unk_20B) {
        case 1:
            func_80AF58B8(pthis);
            break;
        case 2:
            func_80AF594C(pthis);
            break;
        case 3:
            func_80AF59E0(pthis);
            break;
        case 4:
            func_80AF5A74(pthis);
            break;
        case 5:
            func_80AF5B10(pthis);
            break;
        case 6:
            func_80AF5BA4(pthis);
            break;
        case 7:
            func_80AF5C40(pthis);
            break;
    }
}

void EnSa_ChangeAnim(EnSa* pthis, s32 action) {
    Animation_Change(&pthis->skelAnime, sAnimationInfo[action].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationInfo[action].animation), sAnimationInfo[action].mode,
                     sAnimationInfo[action].transitionRate);
}

s32 func_80AF5DFC(EnSa* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.cutsceneIndex >= 0xFFF0 && gSaveContext.cutsceneIndex != 0xFFFD) {
        if (globalCtx->sceneNum == SCENE_SPOT04) {
            return 4;
        }
        if (globalCtx->sceneNum == SCENE_SPOT05) {
            return 5;
        }
    }
    if (globalCtx->sceneNum == SCENE_KOKIRI_HOME5 && !LINK_IS_ADULT &&
        INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY && !(gSaveContext.eventChkInf[4] & 1)) {
        return 1;
    }
    if (globalCtx->sceneNum == SCENE_SPOT05 && (gSaveContext.eventChkInf[4] & 1)) {
        return CHECK_QUEST_ITEM(QUEST_SONG_SARIA) ? 2 : 5;
    }
    if (globalCtx->sceneNum == SCENE_SPOT04 && !CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        if (gSaveContext.infTable[0] & 1) {
            return 1;
        }
        return 4;
    }
    return 0;
}

void func_80AF5F34(EnSa* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 phi_a3 = 0;

    if (globalCtx->sceneNum == SCENE_SPOT04) {
        phi_a3 = (pthis->actionFunc == func_80AF68E4) ? 1 : 4;
    }
    if (globalCtx->sceneNum == SCENE_SPOT05) {
        phi_a3 = (pthis->skelAnime.animation == &gSariaPlayingOcarinaAnim) ? 1 : 3;
    }
    if (globalCtx->sceneNum == SCENE_SPOT05 && pthis->actionFunc == func_80AF6448 &&
        pthis->skelAnime.animation == &gSariaStopPlayingOcarinaAnim) {
        phi_a3 = 1;
    }
    if (globalCtx->sceneNum == SCENE_SPOT05 && pthis->actionFunc == func_80AF68E4 &&
        pthis->skelAnime.animation == &gSariaOcarinaToMouthAnim) {
        phi_a3 = 1;
    }
    pthis->unk_1E0.unk_18 = player->actor.world.pos;
    pthis->unk_1E0.unk_14 = 4.0f;
    func_80034A14(&pthis->actor, &pthis->unk_1E0, 2, phi_a3);
}

s32 func_80AF603C(EnSa* pthis) {
    if (pthis->skelAnime.animation != &gSariaPlayingOcarinaAnim &&
        pthis->skelAnime.animation != &gSariaOcarinaToMouthAnim) {
        return 0;
    }
    if (pthis->unk_1E0.unk_00 != 0) {
        return 0;
    }
    pthis->unk_20E = 0;
    if (pthis->rightEyeIndex != SARIA_EYE_CLOSED) {
        return 0;
    }
    return 1;
}

void func_80AF609C(EnSa* pthis) {
    s16 phi_v1;

    if (func_80AF603C(pthis) == 0) {
        if (pthis->unk_20E == 0) {
            phi_v1 = 0;
        } else {
            pthis->unk_20E--;
            phi_v1 = pthis->unk_20E;
        }
        if (phi_v1 == 0) {
            pthis->rightEyeIndex++;
            if (pthis->rightEyeIndex < SARIA_EYE_SUPRISED) {
                pthis->leftEyeIndex = pthis->rightEyeIndex;
            } else {
                pthis->unk_20E = Rand_S16Offset(30, 30);
                pthis->leftEyeIndex = SARIA_EYE_OPEN;
                pthis->rightEyeIndex = pthis->leftEyeIndex;
            }
        }
    }
}

void func_80AF6130(CsCmdActorAction* csAction, Vec3f* dst) {
    dst->x = csAction->startPos.x;
    dst->y = csAction->startPos.y;
    dst->z = csAction->startPos.z;
}

void func_80AF6170(CsCmdActorAction* csAction, Vec3f* dst) {
    dst->x = csAction->endPos.x;
    dst->y = csAction->endPos.y;
    dst->z = csAction->endPos.z;
}

void EnSa_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSa* pthis = (EnSa*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 12.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSariaSkel, NULL, pthis->jointTable, pthis->morphTable, 17);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);

    switch (func_80AF5DFC(pthis, globalCtx)) {
        case 2:
            EnSa_ChangeAnim(pthis, 0xB);
            pthis->actionFunc = func_80AF6448;
            break;
        case 5:
            EnSa_ChangeAnim(pthis, 0xB);
            pthis->actionFunc = func_80AF683C;
            break;
        case 1:
            pthis->actor.gravity = -1.0f;
            EnSa_ChangeAnim(pthis, 0);
            pthis->actionFunc = func_80AF6448;
            break;
        case 4:
            pthis->unk_210 = 0;
            pthis->actor.gravity = -1.0f;
            globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gSpot04Cs_10E20);
            gSaveContext.cutsceneTrigger = 1;
            EnSa_ChangeAnim(pthis, 4);
            pthis->actionFunc = func_80AF68E4;
            break;
        case 3:
            pthis->unk_210 = 0;
            pthis->actor.gravity = -1.0f;
            EnSa_ChangeAnim(pthis, 0);
            pthis->actionFunc = func_80AF68E4;
            break;
        case 0:
            Actor_Kill(&pthis->actor);
            return;
    }

    Actor_SetScale(&pthis->actor, 0.01f);

    pthis->actor.targetMode = 6;
    pthis->unk_1E0.unk_00 = 0;
    pthis->alpha = 255;
    pthis->unk_21A = pthis->actor.shape.rot;

    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ELF, pthis->actor.world.pos.x,
                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, FAIRY_KOKIRI);
}

void EnSa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSa* pthis = (EnSa*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AF6448(EnSa* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_SPOT04) {
        if (pthis->unk_1E0.unk_00 != 0) {
            switch (pthis->actor.textId) {
                case 0x1002:
                    if (pthis->unk_208 == 0 && pthis->unk_20B != 1) {
                        func_80AF5CD4(pthis, 1);
                        pthis->mouthIndex = 1;
                    }
                    if (pthis->unk_208 == 2 && pthis->unk_20B != 2) {
                        func_80AF5CD4(pthis, 2);
                        pthis->mouthIndex = 1;
                    }
                    if (pthis->unk_208 == 5) {
                        pthis->mouthIndex = 0;
                    }
                    break;
                case 0x1003:
                    if (pthis->unk_208 == 0 && pthis->unk_20B != 4) {
                        func_80AF5CD4(pthis, 4);
                    }
                    break;
                case 0x1031:
                    if (pthis->unk_208 == 0 && pthis->unk_20B != 4 &&
                        pthis->skelAnime.animation == &gSariaHandsBehindBackWaitAnim) {
                        func_80AF5CD4(pthis, 4);
                        pthis->mouthIndex = 3;
                    }
                    if (pthis->unk_208 == 2 && pthis->unk_20B != 5) {
                        func_80AF5CD4(pthis, 5);
                        pthis->mouthIndex = 2;
                    }
                    if (pthis->unk_208 == 4 && pthis->unk_20B != 6) {
                        func_80AF5CD4(pthis, 6);
                        pthis->mouthIndex = 0;
                    }
                    break;
                case 0x1032:
                    if (pthis->unk_208 == 0 && pthis->unk_20B != 4 &&
                        pthis->skelAnime.animation == &gSariaHandsBehindBackWaitAnim) {
                        func_80AF5CD4(pthis, 4);
                    }
                    break;
                case 0x1047:
                    if (pthis->unk_208 == 1 && pthis->unk_20B != 7) {
                        func_80AF5CD4(pthis, 7);
                    }
                    break;
                case 0x1048:
                    if (pthis->unk_208 == 0 && pthis->unk_20B != 7) {
                        func_80AF5CD4(pthis, 7);
                    }
                    break;
            }
        } else if (!CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) &&
                   ((gSaveContext.infTable[0] & 2) || (gSaveContext.infTable[0] & 8))) {
            if (pthis->unk_20B != 3) {
                func_80AF5CD4(pthis, 3);
            }
        } else {
            func_80AF5CD4(pthis, 0);
        }
        func_80AF5CE4(pthis);
    }
    if (pthis->skelAnime.animation == &gSariaStopPlayingOcarinaAnim) {
        pthis->skelAnime.playSpeed = -1.0f;
        if ((s32)pthis->skelAnime.curFrame == 0) {
            EnSa_ChangeAnim(pthis, 6);
        }
    }
    if (pthis->unk_1E0.unk_00 != 0 && globalCtx->sceneNum == SCENE_SPOT05) {
        Animation_Change(&pthis->skelAnime, &gSariaStopPlayingOcarinaAnim, 1.0f, 0.0f, 10.0f, ANIMMODE_ONCE, -10.0f);
        pthis->actionFunc = func_80AF67D0;
    }
}

void func_80AF67D0(EnSa* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 0) {
        Animation_Change(&pthis->skelAnime, &gSariaStopPlayingOcarinaAnim, 0.0f, 10.0f, 0.0f, ANIMMODE_ONCE, -10.0f);
        pthis->actionFunc = func_80AF6448;
    }
}

void func_80AF683C(EnSa* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!(player->actor.world.pos.z >= -2220.0f) && !Gameplay_InCsMode(globalCtx)) {
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(spot05_scene_Cs_005730);
        gSaveContext.cutsceneTrigger = 1;
        pthis->actionFunc = func_80AF68E4;
    }
}

void func_80AF68E4(EnSa* pthis, GlobalContext* globalCtx) {
    s16 phi_v0 = 0;
    Vec3f startPos;
    Vec3f endPos;
    Vec3f D_80AF7448 = { 0.0f, 0.0f, 0.0f };
    CsCmdActorAction* csAction;
    f32 temp_f0;
    f32 gravity;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        pthis->actionFunc = func_80AF6B20;
        return;
    }
    csAction = globalCtx->csCtx.npcActions[1];
    if (csAction != NULL) {
        func_80AF6130(csAction, &startPos);
        func_80AF6170(csAction, &endPos);

        if (pthis->unk_210 == 0) {
            pthis->actor.world.pos = startPos;
        }
        if (pthis->unk_210 != csAction->action) {
            switch (csAction->action) {
                case 2:
                    pthis->mouthIndex = 1;
                    break;
                case 9:
                    pthis->mouthIndex = 1;
                    break;
                default:
                    pthis->mouthIndex = 0;
                    break;
            }
            EnSa_ChangeAnim(pthis, csAction->action);
            pthis->unk_210 = csAction->action;
        }
        if (phi_v0) {}
        if (csAction->action == 3) {
            if (pthis->unk_20C == 0) {
                phi_v0 = 0;
            } else {
                pthis->unk_20C--;
                phi_v0 = pthis->unk_20C;
            }
            if (phi_v0 == 0) {
                Audio_PlaySoundGeneral(NA_SE_PL_WALK_GROUND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
                pthis->unk_20C = 8;
            }
        }
        pthis->actor.shape.rot.x = csAction->urot.x;
        pthis->actor.shape.rot.y = csAction->urot.y;
        pthis->actor.shape.rot.z = csAction->urot.z;
        pthis->actor.velocity = D_80AF7448;

        if (globalCtx->csCtx.frames < csAction->endFrame) {
            temp_f0 = (csAction->endFrame - csAction->startFrame);
            pthis->actor.velocity.x = (endPos.x - startPos.x) / temp_f0;
            pthis->actor.velocity.y = (endPos.y - startPos.y) / temp_f0;
            gravity = pthis->actor.gravity;
            if (globalCtx->sceneNum == SCENE_SPOT05) {
                gravity = 0.0f;
            }
            pthis->actor.velocity.y += gravity;
            if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
                pthis->actor.velocity.y = pthis->actor.minVelocityY;
            }
            pthis->actor.velocity.z = (endPos.z - startPos.z) / temp_f0;
        }
    }
}

void func_80AF6B20(EnSa* pthis, GlobalContext* globalCtx) {
    if (globalCtx->sceneNum == SCENE_SPOT05) {
        Item_Give(globalCtx, ITEM_SONG_SARIA);
        EnSa_ChangeAnim(pthis, 6);
    }

    if (globalCtx->sceneNum == SCENE_SPOT04) {
        EnSa_ChangeAnim(pthis, 4);
        pthis->actor.world.pos = pthis->actor.home.pos;
        pthis->actor.world.rot = pthis->unk_21A;
        pthis->mouthIndex = 0;
        gSaveContext.infTable[0] |= 1;
    }

    pthis->actionFunc = func_80AF6448;
}

void EnSa_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSa* pthis = (EnSa*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->skelAnime.animation == &gSariaOcarinaToMouthAnim &&
        pthis->skelAnime.curFrame >= Animation_GetLastFrame(&gSariaOcarinaToMouthAnim)) {
        EnSa_ChangeAnim(pthis, 6);
    }

    if (pthis->actionFunc != func_80AF68E4) {
        pthis->alpha = func_80034DD4(&pthis->actor, globalCtx, pthis->alpha, 400.0f);
    } else {
        pthis->alpha = 255;
    }

    pthis->actor.shape.shadowAlpha = pthis->alpha;

    if (pthis->actionFunc == func_80AF68E4) {
        pthis->actor.world.pos.x += pthis->actor.velocity.x;
        pthis->actor.world.pos.y += pthis->actor.velocity.y;
        pthis->actor.world.pos.z += pthis->actor.velocity.z;
    } else {
        func_8002D7EC(&pthis->actor);
    }

    if (globalCtx->sceneNum != SCENE_SPOT05) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    }

    func_80AF609C(pthis);
    pthis->actionFunc(pthis, globalCtx);
    func_80AF57D8(pthis, globalCtx);
    func_80AF5F34(pthis, globalCtx);
}

s32 EnSa_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnSa* pthis = (EnSa*)thisx;
    s32 pad;
    Vec3s sp18;

    if (limbIndex == 16) {
        Matrix_Translate(900.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        sp18 = pthis->unk_1E0.unk_08;
        Matrix_RotateX(BINANG_TO_RAD(sp18.y), MTXMODE_APPLY);
        Matrix_RotateZ(BINANG_TO_RAD(sp18.x), MTXMODE_APPLY);
        Matrix_Translate(-900.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }

    if (limbIndex == 9) {
        sp18 = pthis->unk_1E0.unk_0E;
        Matrix_RotateY(BINANG_TO_RAD(sp18.y), MTXMODE_APPLY);
        Matrix_RotateX(BINANG_TO_RAD(sp18.x), MTXMODE_APPLY);
    }

    if (globalCtx->sceneNum == SCENE_SPOT05 && limbIndex == 15) {
        *dList = gSariaRightHandAndOcarinaDL;
    }

    return 0;
}

void EnSa_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnSa* pthis = (EnSa*)thisx;
    Vec3f D_80AF7454 = { 400.0, 0.0f, 0.0f };

    if (limbIndex == 16) {
        Matrix_MultVec3f(&D_80AF7454, &pthis->actor.focus.pos);
    }
}

void EnSa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* mouthTextures[] = {
        gSariaMouthClosed2Tex,  gSariaMouthSmilingOpenTex, gSariaMouthFrowningTex,
        gSariaMouthSuprisedTex, gSariaMouthClosedTex,
    };
    static void* eyeTextures[] = {
        gSariaEyeOpenTex, gSariaEyeHalfTex, gSariaEyeClosedTex, gSariaEyeSuprisedTex, gSariaEyeSadTex,
    };
    EnSa* pthis = (EnSa*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_sa.c", 1444);

    if (pthis->alpha == 255) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->rightEyeIndex]));
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->leftEyeIndex]));
        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(mouthTextures[pthis->mouthIndex]));
        func_80034BA0(globalCtx, &pthis->skelAnime, EnSa_OverrideLimbDraw, EnSa_PostLimbDraw, &pthis->actor, pthis->alpha);
    } else if (pthis->alpha != 0) {
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->rightEyeIndex]));
        gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->leftEyeIndex]));
        gSPSegment(POLY_XLU_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(mouthTextures[pthis->mouthIndex]));
        func_80034CC4(globalCtx, &pthis->skelAnime, EnSa_OverrideLimbDraw, EnSa_PostLimbDraw, &pthis->actor, pthis->alpha);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_sa.c", 1497);
}

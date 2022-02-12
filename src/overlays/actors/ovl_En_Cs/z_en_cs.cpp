#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_CS_Z_EN_CS_C
#include "actor_common.h"
#include "z_en_cs.h"
#include "objects/object_cs/object_cs.h"
#include "objects/object_link_child/object_link_child.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnCs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnCs_Walk(EnCs* pthis, GlobalContext* globalCtx);
void EnCs_Talk(EnCs* pthis, GlobalContext* globalCtx);
void EnCs_Wait(EnCs* pthis, GlobalContext* globalCtx);
s32 EnCs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx);
void EnCs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx);

ActorInit En_Cs_InitVars = {
    ACTOR_EN_CS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_CS,
    sizeof(EnCs),
    (ActorFunc)EnCs_Init,
    (ActorFunc)EnCs_Destroy,
    (ActorFunc)EnCs_Update,
    (ActorFunc)EnCs_Draw,
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
    { 18, 63, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit2 = { 0, 0, 0, 0, MASS_IMMOVABLE };

static DamageTable sDamageTable[] = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(0, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(0, 0x0),
    /* Master sword  */ DMG_ENTRY(0, 0x0),
    /* Giant's Knife */ DMG_ENTRY(0, 0x0),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(0, 0x0),
    /* Giant spin    */ DMG_ENTRY(0, 0x0),
    /* Master spin   */ DMG_ENTRY(0, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(0, 0x0),
    /* Giant jump    */ DMG_ENTRY(0, 0x0),
    /* Master jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static struct_D_80AA1678 sAnimations[] = {
    { &gGraveyardKidWalkAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gGraveyardKidSwingStickUpAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gGraveyardKidGrabStickTwoHandsAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
    { &gGraveyardKidIdleAnim, 1.0f, ANIMMODE_ONCE, -10.0f },
};

void EnCs_SetAnimFromIndex(EnCs* pthis, s32 animIndex, s32* currentAnimIndex) {
    f32 morphFrames;

    if ((*currentAnimIndex < 0) || (animIndex == *currentAnimIndex)) {
        morphFrames = 0.0f;
    } else {
        morphFrames = sAnimations[animIndex].transitionRate;
    }

    if (sAnimations[animIndex].frameCount >= 0.0f) {
        Animation_Change(&pthis->skelAnime, sAnimations[animIndex].animation, sAnimations[animIndex].frameCount, 0.0f,
                         Animation_GetLastFrame(sAnimations[animIndex].animation), sAnimations[animIndex].mode,
                         morphFrames);
    } else {
        Animation_Change(&pthis->skelAnime, sAnimations[animIndex].animation, sAnimations[animIndex].frameCount,
                         Animation_GetLastFrame(sAnimations[animIndex].animation), 0.0f, sAnimations[animIndex].mode,
                         morphFrames);
    }

    *currentAnimIndex = animIndex;
}

void EnCs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnCs* pthis = (EnCs*)thisx;
    s32 pad;

    if (!IS_DAY) {
        Actor_Kill(&pthis->actor);
        return;
    }

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 19.0f);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGraveyardKidSkel, NULL, pthis->jointTable, pthis->morphTable, 16);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, sDamageTable, &sColChkInfoInit2);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    Animation_Change(&pthis->skelAnime, sAnimations[0].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimations[0].animation), sAnimations[0].mode,
                     sAnimations[0].transitionRate);

    pthis->actor.targetMode = 6;
    pthis->path = pthis->actor.params & 0xFF;
    pthis->unk_1EC = 0; // This variable is unused anywhere else
    pthis->talkState = 0;
    pthis->currentAnimIndex = -1;
    pthis->actor.gravity = -1.0f;

    EnCs_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);

    pthis->actionFunc = EnCs_Walk;
    pthis->walkSpeed = 1.0f;
}

void EnCs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnCs* pthis = (EnCs*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnCs_GetTalkState(EnCs* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    s32 talkState = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx)) {
                if (globalCtx->msgCtx.choiceIndex == 0) {
                    pthis->actor.textId = 0x2026;
                    EnCs_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
                    talkState = 2;
                } else {
                    pthis->actor.textId = 0x2024;
                    EnCs_SetAnimFromIndex(pthis, 1, &pthis->currentAnimIndex);
                    talkState = 2;
                }
            }
            break;
        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(globalCtx)) {
                if (pthis->actor.textId == 0x2026) {
                    Player_UnsetMask(globalCtx);
                    Item_Give(globalCtx, ITEM_SOLD_OUT);
                    gSaveContext.itemGetInf[3] |= 0x400;
                    Rupees_ChangeBy(30);
                    pthis->actor.textId = 0x2027;
                    talkState = 2;
                } else {
                    talkState = 0;
                }
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_CLOSING:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_EVENT:
            break;
    }

    return talkState;
}

s32 EnCs_GetTextID(EnCs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 textId = Text_GetFaceReaction(globalCtx, 15);

    if (gSaveContext.itemGetInf[3] & 0x400) {
        if (textId == 0) {
            textId = 0x2028;
        }
    } else if (player->currentMask == PLAYER_MASK_SPOOKY) {
        textId = 0x2023;
    } else {
        if (textId == 0) {
            textId = 0x2022;
        }
    }

    return textId;
}

void EnCs_HandleTalking(EnCs* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 sp2A;
    s16 sp28;

    if (pthis->talkState == 2) {
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->talkState = 1;
    } else if (pthis->talkState == 1) {
        pthis->talkState = EnCs_GetTalkState(pthis, globalCtx);
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if ((pthis->actor.textId == 0x2022) || ((pthis->actor.textId != 0x2022) && (pthis->actor.textId != 0x2028))) {
            EnCs_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
        }

        if ((pthis->actor.textId == 0x2023) || (pthis->actor.textId == 0x2028)) {
            EnCs_SetAnimFromIndex(pthis, 1, &pthis->currentAnimIndex);
        }

        if (pthis->actor.textId == 0x2023) {
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        }

        pthis->talkState = 1;
    } else {
        Actor_GetScreenPos(globalCtx, &pthis->actor, &sp2A, &sp28);

        if ((sp2A >= 0) && (sp2A <= 320) && (sp28 >= 0) && (sp28 <= 240) &&
            (func_8002F2CC(&pthis->actor, globalCtx, 100.0f))) {
            pthis->actor.textId = EnCs_GetTextID(pthis, globalCtx);
        }
    }
}

s32 EnCs_GetwaypointCount(Path* pathList, s32 pathIndex) {
    Path* path = &pathList[pathIndex];

    return path->count;
}

s32 EnCs_GetPathPoint(Path* pathList, Vec3f* dest, s32 pathIndex, s32 waypoint) {
    Path* path = pathList;
    Vec3s* pathPos;

    path += pathIndex;
    pathPos = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[waypoint];

    dest->x = pathPos->x;
    dest->y = pathPos->y;
    dest->z = pathPos->z;

    return 0;
}

s32 EnCs_HandleWalking(EnCs* pthis, GlobalContext* globalCtx) {
    f32 xDiff;
    f32 zDiff;
    Vec3f pathPos;
    s32 waypointCount;
    s16 walkAngle1;
    s16 walkAngle2;

    EnCs_GetPathPoint(globalCtx->setupPathList, &pathPos, pthis->path, pthis->waypoint);
    xDiff = pathPos.x - pthis->actor.world.pos.x;
    zDiff = pathPos.z - pthis->actor.world.pos.z;
    walkAngle1 = Math_FAtan2F(xDiff, zDiff) * (32768.0f / M_PI);
    pthis->walkAngle = walkAngle1;
    pthis->walkDist = sqrtf((xDiff * xDiff) + (zDiff * zDiff));

    while (pthis->walkDist <= 10.44f) {
        pthis->waypoint++;
        waypointCount = EnCs_GetwaypointCount(globalCtx->setupPathList, pthis->path);

        if ((pthis->waypoint < 0) || (!(pthis->waypoint < waypointCount))) {
            pthis->waypoint = 0;
        }

        EnCs_GetPathPoint(globalCtx->setupPathList, &pathPos, pthis->path, pthis->waypoint);
        xDiff = pathPos.x - pthis->actor.world.pos.x;
        zDiff = pathPos.z - pthis->actor.world.pos.z;
        walkAngle2 = Math_FAtan2F(xDiff, zDiff) * (32768.0f / M_PI);
        pthis->walkAngle = walkAngle2;
        pthis->walkDist = sqrtf((xDiff * xDiff) + (zDiff * zDiff));
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->walkAngle, 1, 2500, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.speedXZ = pthis->walkSpeed;
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    return 0;
}

void EnCs_Walk(EnCs* pthis, GlobalContext* globalCtx) {
    s32 rnd;
    s32 animIndex;
    s32 curAnimFrame;

    if (pthis->talkState != 0) {
        pthis->actionFunc = EnCs_Talk;
        return;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        animIndex = pthis->currentAnimIndex;

        if (pthis->talkState == 0) {
            if (gSaveContext.itemGetInf[3] & 0x400) {
                rnd = Rand_ZeroOne() * 10.0f;
            } else {
                rnd = Rand_ZeroOne() * 5.0f;
            }

            if (rnd == 0) {
                if (gSaveContext.itemGetInf[3] & 0x400) {
                    animIndex = 2.0f * Rand_ZeroOne();
                    animIndex = (animIndex == 0) ? 2 : 1;
                } else {
                    animIndex = 2;
                }

                pthis->actionFunc = EnCs_Wait;
            } else {
                animIndex = 0;
            }
        }

        EnCs_SetAnimFromIndex(pthis, animIndex, &pthis->currentAnimIndex);
    }

    if (pthis->talkState == 0) {
        curAnimFrame = pthis->skelAnime.curFrame;

        if (((curAnimFrame >= 8) && (curAnimFrame < 16)) || ((curAnimFrame >= 23) && (curAnimFrame < 30)) ||
            (curAnimFrame == 0)) {
            pthis->walkSpeed = 0.0f;
        } else {
            pthis->walkSpeed = 1.0f;
        }

        EnCs_HandleWalking(pthis, globalCtx);
    }
}

void EnCs_Wait(EnCs* pthis, GlobalContext* globalCtx) {
    s32 animIndex;

    if (pthis->talkState != 0) {
        pthis->actionFunc = EnCs_Talk;
        return;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        animIndex = pthis->currentAnimIndex;

        if (pthis->talkState == 0) {
            if (pthis->animLoopCount > 0) {
                pthis->animLoopCount--;
                animIndex = pthis->currentAnimIndex;
            } else {
                animIndex = 0;
                pthis->actionFunc = EnCs_Walk;
            }
        }

        EnCs_SetAnimFromIndex(pthis, animIndex, &pthis->currentAnimIndex);
    }
}

void EnCs_Talk(EnCs* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        EnCs_SetAnimFromIndex(pthis, pthis->currentAnimIndex, &pthis->currentAnimIndex);
    }

    pthis->flag |= 1;
    pthis->npcInfo.unk_18.x = player->actor.focus.pos.x;
    pthis->npcInfo.unk_18.y = player->actor.focus.pos.y;
    pthis->npcInfo.unk_18.z = player->actor.focus.pos.z;
    func_80034A14(&pthis->actor, &pthis->npcInfo, 0, 4);

    if (pthis->talkState == 0) {
        EnCs_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
        pthis->actionFunc = EnCs_Walk;
        pthis->flag &= ~1;
    }
}

void EnCs_Update(Actor* thisx, GlobalContext* globalCtx) {
    static s32 eyeBlinkFrames[] = { 70, 1, 1 };
    EnCs* pthis = (EnCs*)thisx;
    s32 pad;

    if (pthis->currentAnimIndex == 0) {
        if (((s32)pthis->skelAnime.curFrame == 9) || ((s32)pthis->skelAnime.curFrame == 23)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHIBI_WALK);
        }
    } else if (pthis->currentAnimIndex == 1) {
        if (((s32)pthis->skelAnime.curFrame == 10) || ((s32)pthis->skelAnime.curFrame == 25)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHIBI_WALK);
        }
    } else if ((pthis->currentAnimIndex == 2) && ((s32)pthis->skelAnime.curFrame == 20)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHIBI_WALK);
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    pthis->actionFunc(pthis, globalCtx);

    EnCs_HandleTalking(pthis, globalCtx);

    pthis->eyeBlinkTimer--;

    if (pthis->eyeBlinkTimer < 0) {
        pthis->eyeIndex++;

        if (pthis->eyeIndex >= 3) {
            pthis->eyeIndex = 0;
        }

        pthis->eyeBlinkTimer = eyeBlinkFrames[pthis->eyeIndex];
    }
}

void EnCs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* eyeTextures[] = {
        gGraveyardKidEyesOpenTex,
        gGraveyardKidEyesHalfTex,
        gGraveyardKidEyesClosedTex,
    };
    EnCs* pthis = (EnCs*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_cs.c", 968);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnCs_OverrideLimbDraw, EnCs_PostLimbDraw, &pthis->actor);

    if (gSaveContext.itemGetInf[3] & 0x400) {
        s32 childLinkObjectIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_LINK_CHILD);

        // Handle attaching the Spooky Mask to the boy's face
        if (childLinkObjectIndex >= 0) {
            Mtx* mtx;

            Matrix_Put(&pthis->spookyMaskMtx);
            mtx = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_cs.c", 1000);
            gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[childLinkObjectIndex].vromStart.get());
            gSPSegment(POLY_OPA_DISP++, 0x0D, mtx - 7);
            gSPDisplayList(POLY_OPA_DISP++, gLinkChildSpookyMaskDL);
            gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->actor.objBankIndex].vromStart.get());
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_cs.c", 1015);
}

s32 EnCs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnCs* pthis = (EnCs*)thisx;

    if (pthis->flag & 1) {
        switch (limbIndex) {
            case 8:
                rot->x += pthis->npcInfo.unk_0E.y;
                rot->y -= pthis->npcInfo.unk_0E.x;
                break;
            case 15:
                rot->x += pthis->npcInfo.unk_08.y;
                rot->z += pthis->npcInfo.unk_08.x;
                break;
        }
    }

    return 0;
}

void EnCs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f D_809E2970 = { 500.0f, 800.0f, 0.0f };
    EnCs* pthis = (EnCs*)thisx;

    if (limbIndex == 15) {
        Matrix_MultVec3f(&D_809E2970, &pthis->actor.focus.pos);
        Matrix_Translate(0.0f, -200.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateY(0.0f, MTXMODE_APPLY);
        Matrix_RotateX(0.0f, MTXMODE_APPLY);
        Matrix_RotateZ(5.0 * M_PI / 9.0, MTXMODE_APPLY);
        Matrix_Get(&pthis->spookyMaskMtx);
    }
}

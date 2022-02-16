#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MM_Z_EN_MM_C
#include "actor_common.h"
/*
 * File: z_en_mm.c
 * Overlay: ovl_En_Mm
 * Description: Running Man (child)
 */

#include "z_en_mm.h"
#include "objects/object_mm/object_mm.h"
#include "objects/object_link_child/object_link_child.h"
#include "hack.h"
#include "def/code_800FCE80.h"
#include "def/graph.h"
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

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)


void EnMm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AAE598(EnMm* pthis, GlobalContext* globalCtx);
void func_80AAE294(EnMm* pthis, GlobalContext* globalCtx);
void func_80AAE50C(EnMm* pthis, GlobalContext* globalCtx);
void func_80AAE224(EnMm* pthis, GlobalContext* globalCtx);
s32 func_80AADA70(void);

s32 EnMm_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx);
void EnMm_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void*);

static void* mouthTextures_61[] = { gRunningManMouthOpenTex, gRunningManMouthClosedTex };

static Vec3f headOffset_63 = { 200.0f, 800.0f, 0.0f };


ActorInit En_Mm_InitVars = {
    ACTOR_EN_MM,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MM,
    sizeof(EnMm),
    (ActorFunc)EnMm_Init,
    (ActorFunc)EnMm_Destroy,
    (ActorFunc)EnMm_Update,
    (ActorFunc)EnMm_Draw,
    (ActorFunc)EnMm_Reset,
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

static CollisionCheckInfoInit2 sColChkInfoInit[] = { 0, 0, 0, 0, MASS_IMMOVABLE };

static DamageTable sDamageTable = {
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

static EnMmAnimEntry sAnimationEntries[] = {
    { &gRunningManRunAnim, 1.0f, ANIMMODE_LOOP, -7.0f },     { &gRunningManSitStandAnim, -1.0f, ANIMMODE_ONCE, -7.0f },
    { &gRunningManSitWaitAnim, 1.0f, ANIMMODE_LOOP, -7.0f }, { &gRunningManSitStandAnim, 1.0f, ANIMMODE_ONCE, -7.0f },
    { &gRunningManSprintAnim, 1.0f, ANIMMODE_LOOP, -7.0f },  { &gRunningManExcitedAnim, 1.0f, ANIMMODE_LOOP, -12.0f },
    { &gRunningManHappyAnim, 1.0f, ANIMMODE_LOOP, -12.0f },
};

static EnMmPathInfo sPathInfo[] = {
    { 0, 1, 0, 0 },
    { 1, 1, 0, 1 },
    { 1, 3, 2, 1 },
    { -1, 0, 2, 0 },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_STOP),
};

void EnMm_ChangeAnimation(EnMm* pthis, s32 newAnimIndex, s32* curAnimIndex) {
    f32 morphFrames;

    if ((*curAnimIndex < 0) || (newAnimIndex == *curAnimIndex)) {
        morphFrames = 0.0f;
    } else {
        morphFrames = sAnimationEntries[newAnimIndex].morphFrames;
    }

    if (sAnimationEntries[newAnimIndex].playSpeed >= 0.0f) {
        Animation_Change(&pthis->skelAnime, sAnimationEntries[newAnimIndex].animation,
                         sAnimationEntries[newAnimIndex].playSpeed, 0.0f,
                         Animation_GetLastFrame(sAnimationEntries[newAnimIndex].animation),
                         sAnimationEntries[newAnimIndex].mode, morphFrames);
    } else {
        Animation_Change(&pthis->skelAnime, sAnimationEntries[newAnimIndex].animation,
                         sAnimationEntries[newAnimIndex].playSpeed,
                         Animation_GetLastFrame(sAnimationEntries[newAnimIndex].animation), 0.0f,
                         sAnimationEntries[newAnimIndex].mode, morphFrames);
    }

    *curAnimIndex = newAnimIndex;
}

void EnMm_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnMm* pthis = (EnMm*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 21.0f);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gRunningManSkel, NULL, pthis->jointTable, pthis->morphTable, 16);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, &sDamageTable, sColChkInfoInit);

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    Animation_Change(&pthis->skelAnime, sAnimationEntries[RM_ANIM_RUN].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationEntries[RM_ANIM_RUN].animation),
                     sAnimationEntries[RM_ANIM_RUN].mode, sAnimationEntries[RM_ANIM_RUN].morphFrames);

    pthis->path = pthis->actor.params & 0xFF;
    pthis->unk_1F0 = 2;
    pthis->unk_1E8 = 0;
    pthis->actor.targetMode = 2;
    pthis->actor.gravity = -1.0f;
    pthis->speedXZ = 3.0f;
    pthis->unk_204 = pthis->actor.objBankIndex;

    if (func_80AADA70() == 1) {
        pthis->mouthTexIndex = RM_MOUTH_OPEN;
        EnMm_ChangeAnimation(pthis, RM_ANIM_RUN, &pthis->curAnimIndex);
        pthis->actionFunc = func_80AAE598;
    } else {
        pthis->mouthTexIndex = RM_MOUTH_CLOSED;
        EnMm_ChangeAnimation(pthis, RM_ANIM_SIT_WAIT, &pthis->curAnimIndex);
        pthis->actionFunc = func_80AAE294;
    }
}

void EnMm_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnMm* pthis = (EnMm*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 func_80AADA70(void) {
    s32 isDay = false;

    if ((gSaveContext.dayTime > 0x3555) && (gSaveContext.dayTime <= 0xD556)) {
        isDay = true;
    }

    return isDay;
}

s32 func_80AADAA0(EnMm* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 sp1C = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_CLOSING:
        case TEXT_STATE_DONE_FADING:
            break;
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx)) {
                if (globalCtx->msgCtx.choiceIndex == 0) {
                    player->actor.textId = 0x202D;
                    pthis->unk_254 &= ~1;
                    EnMm_ChangeAnimation(pthis, RM_ANIM_HAPPY, &pthis->curAnimIndex);
                } else {
                    player->actor.textId = 0x202C;
                    gSaveContext.infTable[23] |= 0x1000;
                }
                sp1C = 2;
            }
            break;
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx)) {
                Player_UnsetMask(globalCtx);
                Item_Give(globalCtx, ITEM_SOLD_OUT);
                gSaveContext.itemGetInf[3] |= 0x800;
                Rupees_ChangeBy(500);
                player->actor.textId = 0x202E;
                sp1C = 2;
            }
            break;
        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(globalCtx)) {
                if ((player->actor.textId == 0x202E) || (player->actor.textId == 0x202C)) {
                    pthis->unk_254 |= 1;
                    EnMm_ChangeAnimation(pthis, RM_ANIM_SIT_WAIT, &pthis->curAnimIndex);
                }
                sp1C = 0;
            }
            break;
    }

    return sp1C;
}

s32 EnMm_GetTextId(EnMm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 textId;

    textId = Text_GetFaceReaction(globalCtx, 0x1C);

    if (gSaveContext.itemGetInf[3] & 0x800) {
        if (textId == 0) {
            textId = 0x204D;
        }
    } else if (player->currentMask == PLAYER_MASK_BUNNY) {
        textId = (gSaveContext.infTable[23] & 0x1000) ? 0x202B : 0x202A;
    } else if (textId == 0) {
        textId = 0x2029;
    }

    return textId;
}

void func_80AADCD0(EnMm* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 yawDiff;
    s16 sp26;
    s16 sp24;

    if (pthis->unk_1E0 == 2) {
        Message_ContinueTextbox(globalCtx, player->actor.textId);
        pthis->unk_1E0 = 1;
    } else if (pthis->unk_1E0 == 1) {
        pthis->unk_1E0 = func_80AADAA0(pthis, globalCtx);
    } else {
        if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
            pthis->unk_1E0 = 1;

            if (pthis->curAnimIndex != 5) {
                if ((pthis->actor.textId == 0x202A) || (pthis->actor.textId == 0x202B)) {
                    EnMm_ChangeAnimation(pthis, RM_ANIM_EXCITED, &pthis->curAnimIndex);
                    func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
                }
            }
        } else {
            Actor_GetScreenPos(globalCtx, &pthis->actor, &sp26, &sp24);
            yawDiff = ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y));

            if ((sp26 >= 0) && (sp26 <= 0x140) && (sp24 >= 0) && (sp24 <= 0xF0) && (yawDiff <= 17152.0f) &&
                (pthis->unk_1E0 != 3) && func_8002F2CC(&pthis->actor, globalCtx, 100.0f)) {
                pthis->actor.textId = EnMm_GetTextId(pthis, globalCtx);
            }
        }
    }
}

s32 EnMm_GetPointCount(Path* pathList, s32 pathNum) {
    return (pathList + pathNum)->count;
}

s32 func_80AADE60(Path* pathList, Vec3f* pos, s32 pathNum, s32 waypoint) {
    Vec3s* pointPos;
    pointPos = &((Vec3s*)SEGMENTED_TO_VIRTUAL((pathList + pathNum)->points))[waypoint];

    pos->x = pointPos->x;
    pos->y = pointPos->y;
    pos->z = pointPos->z;

    return 0;
}

s32 func_80AADEF0(EnMm* pthis, GlobalContext* globalCtx) {
    f32 xDiff;
    f32 zDiff;
    Vec3f waypointPos;
    s32 phi_a2;
    s32 phi_v1;

    func_80AADE60(globalCtx->setupPathList, &waypointPos, pthis->path, pthis->waypoint);

    xDiff = waypointPos.x - pthis->actor.world.pos.x;
    zDiff = waypointPos.z - pthis->actor.world.pos.z;

    pthis->yawToWaypoint = (s32)(Math_FAtan2F(xDiff, zDiff) * (0x8000 / M_PI));
    pthis->distToWaypoint = sqrtf(SQ(xDiff) + SQ(zDiff));

    while ((pthis->distToWaypoint <= 10.44f) && (pthis->unk_1E8 != 0)) {
        pthis->waypoint += sPathInfo[pthis->unk_1E8].unk_00;

        phi_a2 = sPathInfo[pthis->unk_1E8].unk_08;

        switch (phi_a2) {
            case 0:
                phi_a2 = 0;
                break;
            case 1:
                phi_a2 = EnMm_GetPointCount(globalCtx->setupPathList, pthis->path) - 1;
                break;
            case 2:
                phi_a2 = pthis->unk_1F0;
                break;
        }

        phi_v1 = sPathInfo[pthis->unk_1E8].unk_0C;

        switch (phi_v1) {
            case 0:
                phi_v1 = 0;
                break;
            case 1:
                phi_v1 = EnMm_GetPointCount(globalCtx->setupPathList, pthis->path) - 1;
                break;
            case 2:
                phi_v1 = pthis->unk_1F0;
                break;
        }

        if ((sPathInfo[pthis->unk_1E8].unk_00 >= 0 && (pthis->waypoint < phi_a2 || phi_v1 < pthis->waypoint)) ||
            (sPathInfo[pthis->unk_1E8].unk_00 < 0 && (phi_a2 < pthis->waypoint || pthis->waypoint < phi_v1))) {
            pthis->unk_1E8 = sPathInfo[pthis->unk_1E8].unk_04;
            pthis->waypoint = sPathInfo[pthis->unk_1E8].unk_08;
        }

        func_80AADE60(globalCtx->setupPathList, &waypointPos, pthis->path, pthis->waypoint);

        xDiff = waypointPos.x - pthis->actor.world.pos.x;
        zDiff = waypointPos.z - pthis->actor.world.pos.z;

        pthis->yawToWaypoint = (s32)(Math_FAtan2F(xDiff, zDiff) * (0x8000 / M_PI));
        pthis->distToWaypoint = sqrtf(SQ(xDiff) + SQ(zDiff));
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->yawToWaypoint, 1, 2500, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->speedXZ, 0.6f, pthis->distToWaypoint, 0.0f);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    return 0;
}

void func_80AAE224(EnMm* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actionFunc = func_80AAE598;
        pthis->unk_1E8 = 0;
        pthis->mouthTexIndex = RM_MOUTH_CLOSED;
        pthis->unk_254 |= 1;
        pthis->unk_1E0 = 0;
        pthis->actor.speedXZ = 0.0f;
        EnMm_ChangeAnimation(pthis, RM_ANIM_SIT_WAIT, &pthis->curAnimIndex);
    }
}

void func_80AAE294(EnMm* pthis, GlobalContext* globalCtx) {
    f32 floorYNorm;
    Vec3f dustPos;

    if (!Player_InCsMode(globalCtx)) {
        SkelAnime_Update(&pthis->skelAnime);

        if (pthis->curAnimIndex == 0) {
            if (((s32)pthis->skelAnime.curFrame == 1) || ((s32)pthis->skelAnime.curFrame == 6)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_WALK_GROUND);
            }
        }

        if (pthis->curAnimIndex == 4) {
            if (((pthis->skelAnime.curFrame - pthis->skelAnime.playSpeed < 9.0f) && (pthis->skelAnime.curFrame >= 9.0f)) ||
                ((pthis->skelAnime.curFrame - pthis->skelAnime.playSpeed < 19.0f) &&
                 (pthis->skelAnime.curFrame >= 19.0f))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
            }
        }

        if (gSaveContext.itemGetInf[3] & 0x800) {
            pthis->speedXZ = 10.0f;
            pthis->skelAnime.playSpeed = 2.0f;
        } else {
            pthis->speedXZ = 3.0f;
            pthis->skelAnime.playSpeed = 1.0f;
        }

        func_80AADEF0(pthis, globalCtx);

        if (func_80AADA70() == 0) {
            if (pthis->actor.floorPoly != NULL) {
                floorYNorm = COLPOLY_GET_NORMAL(pthis->actor.floorPoly->normal.y);

                if ((floorYNorm > 0.9848f) || (floorYNorm < -0.9848f)) {
                    if (pthis->sitTimer > 30) {
                        EnMm_ChangeAnimation(pthis, RM_ANIM_SIT, &pthis->curAnimIndex);
                        pthis->actionFunc = func_80AAE224;
                    } else {
                        pthis->sitTimer++;
                    }
                } else {
                    pthis->sitTimer = 0;
                }
            }
        }

        if (gSaveContext.itemGetInf[3] & 0x800) {
            dustPos.x = pthis->actor.world.pos.x;
            dustPos.y = pthis->actor.world.pos.y;
            dustPos.z = pthis->actor.world.pos.z;

            if (gSaveContext.gameMode != 3) {
                func_80033480(globalCtx, &dustPos, 50.0f, 2, 350, 20, 0);
            }

            if (pthis->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
                func_8002F71C(globalCtx, &pthis->actor, 3.0f, pthis->actor.yawTowardsPlayer, 4.0f);
            }
        }
    }
}

void func_80AAE50C(EnMm* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->sitTimer = 0;
        pthis->actionFunc = func_80AAE294;

        if (gSaveContext.itemGetInf[3] & 0x800) {
            EnMm_ChangeAnimation(pthis, RM_ANIM_SPRINT, &pthis->curAnimIndex);
            pthis->mouthTexIndex = RM_MOUTH_CLOSED;
        } else {
            EnMm_ChangeAnimation(pthis, RM_ANIM_RUN, &pthis->curAnimIndex);
            pthis->mouthTexIndex = RM_MOUTH_OPEN;
        }

        pthis->unk_1E8 = 1;
    }
}

void func_80AAE598(EnMm* pthis, GlobalContext* globalCtx) {
    func_80038290(globalCtx, &pthis->actor, &pthis->unk_248, &pthis->unk_24E, pthis->actor.focus.pos);
    SkelAnime_Update(&pthis->skelAnime);

    if ((func_80AADA70() != 0) && (pthis->unk_1E0 == 0)) {
        pthis->unk_1E0 = 3;
        pthis->actionFunc = func_80AAE50C;
        pthis->unk_254 &= ~1;
        EnMm_ChangeAnimation(pthis, RM_ANIM_STAND, &pthis->curAnimIndex);
    }
}

void EnMm_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnMm* pthis = (EnMm*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    func_80AADCD0(pthis, globalCtx);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnMm_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnMm* pthis = (EnMm*)thisx;

    if (0) {}

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_mm.c", 1065);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(mouthTextures_61[pthis->mouthTexIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnMm_OverrideLimbDraw, EnMm_PostLimbDraw, pthis);

    if (gSaveContext.itemGetInf[3] & 0x800) {
        s32 linkChildObjBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_LINK_CHILD);

        if (linkChildObjBankIndex >= 0) {
            Mtx* mtx;
            Vec3s sp50;
            Mtx* mtx2;

            mtx = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx) * 2);

            Matrix_Put(&pthis->unk_208);
            mtx2 = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_mm.c", 1111);

            gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[linkChildObjBankIndex].vromStart.get());
            gSPSegment(POLY_OPA_DISP++, 0x0B, mtx);
            gSPSegment(POLY_OPA_DISP++, 0x0D, mtx2 - 7);

            sp50.x = 994;
            sp50.y = 3518;
            sp50.z = -13450;

            func_800D1694(97.0f, -1203.0f, -240.0f, &sp50);
            Matrix_ToMtx(mtx++, "../z_en_mm.c", 1124);

            sp50.x = -994;
            sp50.y = -3518;
            sp50.z = -13450;

            func_800D1694(97.0f, -1203.0f, 240.0f, &sp50);
            Matrix_ToMtx(mtx, "../z_en_mm.c", 1131);

            gSPDisplayList(POLY_OPA_DISP++, gLinkChildBunnyHoodDL);
            gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->actor.objBankIndex].vromStart.get());
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_mm.c", 1141);
}

s32 EnMm_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMm* pthis = (EnMm*)thisx;

    if (pthis->unk_254 & 1) {
        switch (limbIndex) {
            case 8:
                rot->x += pthis->unk_24E.y;
                rot->y -= pthis->unk_24E.x;
                break;
            case 15:
                rot->x += pthis->unk_248.y;
                rot->z += (pthis->unk_248.x + 0xFA0);
                break;
            default:
                break;
        }
    }

    return 0;
}

void EnMm_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnMm* pthis = (EnMm*)thisx;

    if (limbIndex == 15) {
        Matrix_MultVec3f(&headOffset_63, &pthis->actor.focus.pos);
        Matrix_Translate(260.0f, 20.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateY(0.0f, MTXMODE_APPLY);
        Matrix_RotateX(0.0f, MTXMODE_APPLY);
        Matrix_RotateZ(4.0f * M_PI / 5.0f, MTXMODE_APPLY);
        Matrix_Translate(-260.0f, 58.0f, 10.0f, MTXMODE_APPLY);
        Matrix_Get(&pthis->unk_208);
    }
}

void EnMm_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    headOffset_63 = { 200.0f, 800.0f, 0.0f };

    En_Mm_InitVars = {
        ACTOR_EN_MM,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_MM,
        sizeof(EnMm),
        (ActorFunc)EnMm_Init,
        (ActorFunc)EnMm_Destroy,
        (ActorFunc)EnMm_Update,
        (ActorFunc)EnMm_Draw,
        (ActorFunc)EnMm_Reset,
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
        { 18, 63, 0, { 0, 0, 0 } },
    };

    sDamageTable = {
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

}

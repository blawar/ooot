#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DAIKU_Z_EN_DAIKU_C
#include "actor_common.h"
#include "z_en_daiku.h"
#include "overlays/actors/ovl_En_GeldB/z_en_geldb.h"
#include "objects/object_daiku/object_daiku.h"
#include "def/code_800EC960.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)


// state flags

// probably related to animating torso and head to look towards the player
#define ENDAIKU_STATEFLAG_1 (1 << 1)
// same
#define ENDAIKU_STATEFLAG_2 (1 << 2)
// the gerudo guard appeared (after talking to the carpenter)
#define ENDAIKU_STATEFLAG_GERUDOFIGHTING (1 << 3)
// the gerudo guard was defeated
#define ENDAIKU_STATEFLAG_GERUDODEFEATED (1 << 4)


void EnDaiku_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDaiku_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDaiku_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDaiku_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDaiku_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDaiku_TentIdle(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_Jailed(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_WaitFreedom(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_InitEscape(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_EscapeRotate(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_InitSubCamera(EnDaiku* pthis, GlobalContext* globalCtx);
void EnDaiku_EscapeRun(EnDaiku* pthis, GlobalContext* globalCtx);
s32 EnDaiku_OverrideLimbDraw(GlobalContext* globalCtx, s32 limb, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx);
void EnDaiku_PostLimbDraw(GlobalContext* globalCtx, s32 limb, Gfx** dList, Vec3s* rot, void* thisx);

static Vec3f D_809E4148_73 = { 0.0f, 0.0f, 120.0f };

static Gfx* hairDLists_80[] = { object_daiku_DL_005BD0, object_daiku_DL_005AC0, object_daiku_DL_005990,
                             object_daiku_DL_005880 };

static Vec3f targetPosHeadLocal_80 = { 700, 1100, 0 };


ActorInit En_Daiku_InitVars = {
    ACTOR_EN_DAIKU,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DAIKU,
    sizeof(EnDaiku),
    (ActorFunc)EnDaiku_Init,
    (ActorFunc)EnDaiku_Destroy,
    (ActorFunc)EnDaiku_Update,
    (ActorFunc)EnDaiku_Draw,
    (ActorFunc)EnDaiku_Reset,
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
    { 18, 66, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit2 = { 0, 0, 0, 0, MASS_IMMOVABLE };

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

static EnDaikuAnimation sAnimations[] = {
    { &object_daiku_Anim_001AB0, 1.0f, 0, 0 }, { &object_daiku_Anim_007DE0, 1.0f, 0, 0 },
    { &object_daiku_Anim_00885C, 1.0f, 0, 0 }, { &object_daiku_Anim_000C44, 1.0f, 0, 0 },
    { &object_daiku_Anim_008164, 1.0f, 0, 0 },
};

static EnDaikuEscapeSubCamParam sEscapeSubCamParams[] = {
    { { 0, 130, 220 }, 100 },
    { { -20, 22, 280 }, 110 },
    { { 50, 180, 350 }, 100 },
    { { -40, 60, 60 }, 120 },
};

void EnDaiku_Change(EnDaiku* pthis, s32 animIndex, s32* currentAnimIndex) {
    f32 transitionRate;

    if (*currentAnimIndex < 0 || *currentAnimIndex == animIndex) {
        transitionRate = 0.0f;
    } else {
        transitionRate = sAnimations[animIndex].transitionRate;
    }

    Animation_Change(&pthis->skelAnime, sAnimations[animIndex].anim, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimations[animIndex].anim), sAnimations[animIndex].mode, transitionRate);

    *currentAnimIndex = animIndex;
}

void EnDaiku_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDaiku* pthis = (EnDaiku*)thisx;
    s32 pad;
    s32 noKill = true;
    s32 isFree = false;

    if ((pthis->actor.params & 3) == 0 && (gSaveContext.eventChkInf[9] & 1)) {
        isFree = true;
    } else if ((pthis->actor.params & 3) == 1 && (gSaveContext.eventChkInf[9] & 2)) {
        isFree = true;
    } else if ((pthis->actor.params & 3) == 2 && (gSaveContext.eventChkInf[9] & 4)) {
        isFree = true;
    } else if ((pthis->actor.params & 3) == 3 && (gSaveContext.eventChkInf[9] & 8)) {
        isFree = true;
    }

    if (isFree == true && globalCtx->sceneNum == SCENE_GERUDOWAY) {
        noKill = false;
    } else if (isFree == false && globalCtx->sceneNum == SCENE_TENT) {
        noKill = false;
    }

    pthis->startFightSwitchFlag = pthis->actor.shape.rot.z & 0x3F;
    pthis->actor.shape.rot.z = 0;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_daiku_Skel_007958, NULL, pthis->jointTable, pthis->morphTable,
                       17);

    if (!noKill) {
        Actor_Kill(&pthis->actor);
        return;
    }

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit2);

    Animation_Change(&pthis->skelAnime, sAnimations[0].anim, 1.0f, 0.0f, Animation_GetLastFrame(sAnimations[0].anim),
                     sAnimations[0].mode, sAnimations[0].transitionRate);

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    pthis->actor.targetMode = 6;
    pthis->currentAnimIndex = -1;
    pthis->runSpeed = 5.0f;
    pthis->initRot = pthis->actor.world.rot;
    pthis->initPos = pthis->actor.world.pos;

    if (globalCtx->sceneNum == SCENE_GERUDOWAY) {
        EnDaiku_Change(pthis, ENDAIKU_ANIM_STAND, &pthis->currentAnimIndex);
        pthis->stateFlags |= ENDAIKU_STATEFLAG_1 | ENDAIKU_STATEFLAG_2;
        pthis->actionFunc = EnDaiku_Jailed;
    } else {
        if ((pthis->actor.params & 3) == 1 || (pthis->actor.params & 3) == 3) {
            EnDaiku_Change(pthis, ENDAIKU_ANIM_SIT, &pthis->currentAnimIndex);
            pthis->stateFlags |= ENDAIKU_STATEFLAG_1;
        } else {
            EnDaiku_Change(pthis, ENDAIKU_ANIM_SHOUT, &pthis->currentAnimIndex);
            pthis->stateFlags |= ENDAIKU_STATEFLAG_1 | ENDAIKU_STATEFLAG_2;
        }

        pthis->skelAnime.curFrame = (s32)(Rand_ZeroOne() * pthis->skelAnime.endFrame);
        pthis->actionFunc = EnDaiku_TentIdle;
    }
}

void EnDaiku_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDaiku* pthis = (EnDaiku*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnDaiku_UpdateTalking(EnDaiku* pthis, GlobalContext* globalCtx) {
    s32 newTalkState = ENDAIKU_STATE_TALKING;

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) {
        if (globalCtx->sceneNum == SCENE_GERUDOWAY) {
            if (Message_ShouldAdvance(globalCtx)) {
                if (pthis->actor.textId == 0x6007) {
                    Flags_SetSwitch(globalCtx, pthis->startFightSwitchFlag);
                    newTalkState = ENDAIKU_STATE_CAN_TALK;
                } else {
                    pthis->actionFunc = EnDaiku_InitEscape;
                    newTalkState = ENDAIKU_STATE_NO_TALK;
                }
            }
        } else if (globalCtx->sceneNum == SCENE_TENT) {
            if (Message_ShouldAdvance(globalCtx)) {
                switch (pthis->actor.textId) {
                    case 0x6061:
                        gSaveContext.infTable[23] |= 0x40;
                        break;
                    case 0x6064:
                        gSaveContext.infTable[23] |= 0x100;
                        break;
                }

                newTalkState = ENDAIKU_STATE_CAN_TALK;
            }
        }
    }

    return newTalkState;
}

void EnDaiku_UpdateText(EnDaiku* pthis, GlobalContext* globalCtx) {
    s32 carpenterType;
    s32 freedCount;
    s16 sp2E;
    s16 sp2C;

    if (pthis->talkState == ENDAIKU_STATE_TALKING) {
        pthis->talkState = EnDaiku_UpdateTalking(pthis, globalCtx);
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->talkState = ENDAIKU_STATE_TALKING;
    } else {
        Actor_GetScreenPos(globalCtx, &pthis->actor, &sp2E, &sp2C);
        if (sp2E >= 0 && sp2E <= 320 && sp2C >= 0 && sp2C <= 240 && pthis->talkState == ENDAIKU_STATE_CAN_TALK &&
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f) == 1) {
            if (globalCtx->sceneNum == SCENE_GERUDOWAY) {
                if (pthis->stateFlags & ENDAIKU_STATEFLAG_GERUDODEFEATED) {
                    freedCount = 0;
                    for (carpenterType = 0; carpenterType < 4; carpenterType++) {
                        if (gSaveContext.eventChkInf[9] & (1 << carpenterType)) {
                            freedCount++;
                        }
                    }

                    switch (freedCount) {
                        case 0:
                            pthis->actor.textId = 0x605B;
                            break;
                        case 1:
                            pthis->actor.textId = 0x605C;
                            break;
                        case 2:
                            pthis->actor.textId = 0x605D;
                            break;
                        case 3:
                            pthis->actor.textId = 0x605E;
                            break;
                    }
                } else if (!(pthis->stateFlags &
                             (ENDAIKU_STATEFLAG_GERUDOFIGHTING | ENDAIKU_STATEFLAG_GERUDODEFEATED))) {
                    pthis->actor.textId = 0x6007;
                }
            } else if (globalCtx->sceneNum == SCENE_TENT) {
                switch (pthis->actor.params & 3) {
                    case 0:
                        if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT)) {
                            pthis->actor.textId = 0x6060;
                        } else {
                            pthis->actor.textId = 0x605F;
                        }
                        break;
                    case 1:
                        if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT)) {
                            pthis->actor.textId = 0x6063;
                        } else {
                            if (!(gSaveContext.infTable[23] & 0x40)) {
                                pthis->actor.textId = 0x6061;
                            } else {
                                pthis->actor.textId = 0x6062;
                            }
                        }
                        break;
                    case 2:
                        if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT)) {
                            pthis->actor.textId = 0x6066;
                        } else {
                            if (!(gSaveContext.infTable[23] & 0x100)) {
                                pthis->actor.textId = 0x6064;
                            } else {
                                pthis->actor.textId = 0x6065;
                            }
                        }
                        break;
                    case 3:
                        if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT)) {
                            pthis->actor.textId = 0x6068;
                        } else {
                            pthis->actor.textId = 0x6067;
                        }
                        break;
                }
            }
        }
    }
}

/**
 * The carpenter is idling in the tent.
 */
void EnDaiku_TentIdle(EnDaiku* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    EnDaiku_UpdateText(pthis, globalCtx);
}

/**
 * The carpenter is jailed in a Gerudo fortress cell, talking to him starts a fight against a gerudo guard
 */
void EnDaiku_Jailed(EnDaiku* pthis, GlobalContext* globalCtx) {
    EnGeldB* gerudo;
    s32 temp_t9;
    s32 temp_v1;

    if (!(pthis->stateFlags & ENDAIKU_STATEFLAG_GERUDOFIGHTING)) {
        EnDaiku_UpdateText(pthis, globalCtx);
    }
    SkelAnime_Update(&pthis->skelAnime);

    gerudo = (EnGeldB*)Actor_Find(&globalCtx->actorCtx, ACTOR_EN_GELDB, ACTORCAT_ENEMY);
    if (gerudo == NULL) {
        pthis->stateFlags |= ENDAIKU_STATEFLAG_GERUDODEFEATED;
        pthis->stateFlags &= ~ENDAIKU_STATEFLAG_GERUDOFIGHTING;
        EnDaiku_Change(pthis, ENDAIKU_ANIM_CELEBRATE, &pthis->currentAnimIndex);
        pthis->actionFunc = EnDaiku_WaitFreedom;
    } else if (!(pthis->stateFlags & ENDAIKU_STATEFLAG_GERUDOFIGHTING) && !gerudo->invisible) {
        pthis->stateFlags |= ENDAIKU_STATEFLAG_GERUDOFIGHTING;
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
    }
}

/**
 * The player defeated the gerudo guard and the carpenter is waiting for the cell door to be opened, and for the player
 * to then talk to him
 */
void EnDaiku_WaitFreedom(EnDaiku* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (Flags_GetSwitch(globalCtx, pthis->actor.params >> 8 & 0x3F)) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        EnDaiku_UpdateText(pthis, globalCtx);
    }
}

/**
 * The carpenter is free, initializes his running away animation
 */
void EnDaiku_InitEscape(EnDaiku* pthis, GlobalContext* globalCtx) {
    Path* path;
    f32 dxz;
    f32 dx;
    f32 dz;
    Vec3s* pointPos;
    s32 exitLoop;

    Audio_PlayFanfare(NA_BGM_APPEAR);
    EnDaiku_Change(pthis, ENDAIKU_ANIM_RUN, &pthis->currentAnimIndex);
    pthis->stateFlags &= ~(ENDAIKU_STATEFLAG_1 | ENDAIKU_STATEFLAG_2);

    gSaveContext.eventChkInf[9] |= 1 << (pthis->actor.params & 3);

    pthis->actor.gravity = -1.0f;
    pthis->escapeSubCamTimer = sEscapeSubCamParams[pthis->actor.params & 3].maxFramesActive;
    EnDaiku_InitSubCamera(pthis, globalCtx);

    exitLoop = false;
    path = &globalCtx->setupPathList[pthis->actor.params >> 4 & 0xF];
    while (!exitLoop) {
        pointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->waypoint;
        dx = pointPos->x - pthis->actor.world.pos.x;
        dz = pointPos->z - pthis->actor.world.pos.z;
        pthis->rotYtowardsPath = Math_FAtan2F(dx, dz) * (0x8000 / M_PI);
        dxz = sqrtf(SQ(dx) + SQ(dz));
        if (dxz > 10.0f) {
            exitLoop = true;
        } else {
            pthis->waypoint++;
        }
    }

    pthis->actionFunc = EnDaiku_EscapeRotate;
}

/**
 * The carpenter is rotating towards where he is going next
 */
void EnDaiku_EscapeRotate(EnDaiku* pthis, GlobalContext* globalCtx) {
    s16 diff;

    diff = Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->rotYtowardsPath, 1, 0x1388, 0);
    SkelAnime_Update(&pthis->skelAnime);
    if (diff == 0) {
        pthis->actionFunc = EnDaiku_EscapeRun;
        pthis->actionFunc(pthis, globalCtx);
    }
}

void EnDaiku_InitSubCamera(EnDaiku* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f eyePosDeltaLocal;
    Vec3f eyePosDeltaWorld;

    pthis->subCamActive = true;
    pthis->escapeSubCamTimer = sEscapeSubCamParams[pthis->actor.params & 3].maxFramesActive;

    eyePosDeltaLocal.x = sEscapeSubCamParams[pthis->actor.params & 3].eyePosDeltaLocal.x;
    eyePosDeltaLocal.y = sEscapeSubCamParams[pthis->actor.params & 3].eyePosDeltaLocal.y;
    eyePosDeltaLocal.z = sEscapeSubCamParams[pthis->actor.params & 3].eyePosDeltaLocal.z;
    Matrix_RotateY(pthis->actor.world.rot.y * (M_PI / 0x8000), MTXMODE_NEW);
    Matrix_MultVec3f(&eyePosDeltaLocal, &eyePosDeltaWorld);

    pthis->subCamEyeInit.x = pthis->subCamEye.x = pthis->actor.world.pos.x + eyePosDeltaWorld.x;
    pthis->subCamEyeInit.y = pthis->subCamEye.y = pthis->actor.world.pos.y + eyePosDeltaWorld.y;
    if (1) {}
    pthis->subCamEyeInit.z = pthis->subCamEye.z = pthis->actor.world.pos.z + eyePosDeltaWorld.z;

    if (1) {}
    pthis->subCamAtTarget.x = pthis->subCamAt.x = pthis->actor.world.pos.x;
    pthis->subCamAtTarget.y = pthis->subCamAt.y = pthis->actor.world.pos.y + 60.0f;
    if (1) {}
    pthis->subCamAtTarget.z = pthis->subCamAt.z = pthis->actor.world.pos.z;

    pthis->subCamId = Gameplay_CreateSubCamera(globalCtx);
    Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
    Gameplay_ChangeCameraStatus(globalCtx, pthis->subCamId, CAM_STAT_ACTIVE);

    Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt, &pthis->subCamEye);
    Gameplay_CameraSetFov(globalCtx, pthis->subCamId, globalCtx->mainCamera.fov);
    func_8002DF54(globalCtx, &pthis->actor, 1);
}

void EnDaiku_UpdateSubCamera(EnDaiku* pthis, GlobalContext* globalCtx) {
    s32 pad;

    pthis->subCamAtTarget.x = pthis->actor.world.pos.x;
    pthis->subCamAtTarget.y = pthis->actor.world.pos.y + 60.0f;
    pthis->subCamAtTarget.z = pthis->actor.world.pos.z;

    Math_SmoothStepToF(&pthis->subCamAt.x, pthis->subCamAtTarget.x, 1.0f, 1000.0f, 0.0f);
    Math_SmoothStepToF(&pthis->subCamAt.y, pthis->subCamAtTarget.y, 1.0f, 1000.0f, 0.0f);
    Math_SmoothStepToF(&pthis->subCamAt.z, pthis->subCamAtTarget.z, 1.0f, 1000.0f, 0.0f);

    Gameplay_CameraSetAtEye(globalCtx, pthis->subCamId, &pthis->subCamAt, &pthis->subCamEye);
}

void EnDaiku_EscapeSuccess(EnDaiku* pthis, GlobalContext* globalCtx) {
    Actor* gerudoGuard;
    Vec3f vec;

    Gameplay_ClearCamera(globalCtx, pthis->subCamId);
    Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_ACTIVE);
    pthis->subCamActive = false;

    if ((gSaveContext.eventChkInf[9] & 0xF) == 0xF) {
        Matrix_RotateY(pthis->initRot.y * (M_PI / 0x8000), MTXMODE_NEW);
        Matrix_MultVec3f(&D_809E4148_73, &vec);
        gerudoGuard =
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_GE3, pthis->initPos.x + vec.x, pthis->initPos.y + vec.y,
                        pthis->initPos.z + vec.z, 0, Math_FAtan2F(-vec.x, -vec.z) * (0x8000 / M_PI), 0, 2);

        if (gerudoGuard == NULL) {
            Actor_Kill(&pthis->actor);
        }
    } else {
        func_8002DF54(globalCtx, &pthis->actor, 7);
    }
}

/**
 * The carpenter is running away
 */
void EnDaiku_EscapeRun(EnDaiku* pthis, GlobalContext* globalCtx) {
    s32 pad1;
    Path* path;
    s16 ry;
    f32 dx;
    f32 dz;
    s32 pad2;
    f32 dxz;
    Vec3s* pointPos;

    path = &globalCtx->setupPathList[pthis->actor.params >> 4 & 0xF];
    pointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->waypoint;
    dx = pointPos->x - pthis->actor.world.pos.x;
    dz = pointPos->z - pthis->actor.world.pos.z;
    ry = Math_FAtan2F(dx, dz) * (0x8000 / M_PI);
    dxz = sqrtf(SQ(dx) + SQ(dz));
    if (dxz <= 20.88f) {
        pthis->waypoint++;
        if (pthis->waypoint >= path->count) {
            if (pthis->subCamActive) {
                EnDaiku_EscapeSuccess(pthis, globalCtx);
            }
            Actor_Kill(&pthis->actor);
            return;
        }
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, ry, 1, 0xFA0, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->runSpeed, 0.6f, dxz, 0.0f);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    if (pthis->subCamActive) {
        EnDaiku_UpdateSubCamera(pthis, globalCtx);
        if (pthis->escapeSubCamTimer-- <= 0) {
            EnDaiku_EscapeSuccess(pthis, globalCtx);
        }
    }

    SkelAnime_Update(&pthis->skelAnime);
}

void EnDaiku_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDaiku* pthis = (EnDaiku*)thisx;
    s32 curFrame;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->currentAnimIndex == ENDAIKU_ANIM_RUN) {
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame == 6 || curFrame == 15) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
        }
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->stateFlags & ENDAIKU_STATEFLAG_1) {
        pthis->unk_244.unk_18.x = player->actor.focus.pos.x;
        pthis->unk_244.unk_18.y = player->actor.focus.pos.y;
        pthis->unk_244.unk_18.z = player->actor.focus.pos.z;

        if (pthis->stateFlags & ENDAIKU_STATEFLAG_2) {
            func_80034A14(&pthis->actor, &pthis->unk_244, 0, 4);
        } else {
            func_80034A14(&pthis->actor, &pthis->unk_244, 0, 2);
        }
    }
}

void EnDaiku_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDaiku* pthis = (EnDaiku*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku.c", 1227);

    func_80093D18(globalCtx->state.gfxCtx);

    if ((thisx->params & 3) == 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, 170, 10, 70, 255);
    } else if ((thisx->params & 3) == 1) {
        gDPSetEnvColor(POLY_OPA_DISP++, 170, 200, 255, 255);
    } else if ((thisx->params & 3) == 2) {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 230, 70, 255);
    } else if ((thisx->params & 3) == 3) {
        gDPSetEnvColor(POLY_OPA_DISP++, 200, 0, 150, 255);
    }

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDaiku_OverrideLimbDraw, EnDaiku_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku.c", 1255);
}

s32 EnDaiku_OverrideLimbDraw(GlobalContext* globalCtx, s32 limb, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnDaiku* pthis = (EnDaiku*)thisx;

    switch (limb) {
        case 8: // torso
            rot->x += pthis->unk_244.unk_0E.y;
            rot->y -= pthis->unk_244.unk_0E.x;
            break;
        case 15: // head
            rot->x += pthis->unk_244.unk_08.y;
            rot->z += pthis->unk_244.unk_08.x;
            break;
    }

    return false;
}

void EnDaiku_PostLimbDraw(GlobalContext* globalCtx, s32 limb, Gfx** dList, Vec3s* rot, void* thisx) {
    EnDaiku* pthis = (EnDaiku*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku.c", 1323);

    if (limb == 15) { // head
        Matrix_MultVec3f(&targetPosHeadLocal_80, &pthis->actor.focus.pos);
        gSPDisplayList(POLY_OPA_DISP++, hairDLists_80[pthis->actor.params & 3]);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku.c", 1330);
}

void EnDaiku_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_809E4148_73 = { 0.0f, 0.0f, 120.0f };

    targetPosHeadLocal_80 = { 700, 1100, 0 };

    En_Daiku_InitVars = {
        ACTOR_EN_DAIKU,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_DAIKU,
        sizeof(EnDaiku),
        (ActorFunc)EnDaiku_Init,
        (ActorFunc)EnDaiku_Destroy,
        (ActorFunc)EnDaiku_Update,
        (ActorFunc)EnDaiku_Draw,
        (ActorFunc)EnDaiku_Reset,
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
        { 18, 66, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit2 = { 0, 0, 0, 0, MASS_IMMOVABLE };

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

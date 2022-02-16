#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DAIKU_KAKARIKO_Z_EN_DAIKU_KAKARIKO_C
#include "actor_common.h"
/*
 * File: z_en_daiku_kakariko.c
 * Overlay: ovl_En_Daiku_Kakariko
 * Description: Kakariko Village Carpenters
 */

#include "z_en_daiku_kakariko.h"
#include "objects/object_daiku/object_daiku.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)


void EnDaikuKakariko_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDaikuKakariko_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDaikuKakariko_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDaikuKakariko_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDaikuKakariko_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDaikuKakariko_Wait(EnDaikuKakariko* pthis, GlobalContext* globalCtx);
void EnDaikuKakariko_Run(EnDaikuKakariko* pthis, GlobalContext* globalCtx);

static u16 initFlags_32[] = { 0x0080, 0x00B0, 0x0070, 0x0470 };

static s32 maskReactionSets_35[] = { 1, 2, 3, 4 };

static Gfx* carpenterHeadDLists_42[] = { object_daiku_DL_005BD0, object_daiku_DL_005AC0, object_daiku_DL_005990,
                                      object_daiku_DL_005880 };

static Vec3f unkVec_42 = { 700.0f, 1100.0f, 0.0f };


ActorInit En_Daiku_Kakariko_InitVars = {
    ACTOR_EN_DAIKU_KAKARIKO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DAIKU,
    sizeof(EnDaikuKakariko),
    (ActorFunc)EnDaikuKakariko_Init,
    (ActorFunc)EnDaikuKakariko_Destroy,
    (ActorFunc)EnDaikuKakariko_Update,
    (ActorFunc)EnDaikuKakariko_Draw,
    (ActorFunc)EnDaikuKakariko_Reset,
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

static CollisionCheckInfoInit2 sColChkInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

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

static struct_D_80AA1678 sAnimations[] = {
    { &object_daiku_Anim_001AB0, 1.0f, 2, -7.0f }, { &object_daiku_Anim_007DE0, 1.0f, 0, -7.0f },
    { &object_daiku_Anim_00885C, 1.0f, 0, -7.0f }, { &object_daiku_Anim_000C44, 1.0f, 0, -7.0f },
    { &object_daiku_Anim_000600, 1.0f, 0, -7.0f }, { &object_daiku_Anim_008164, 1.0f, 0, -7.0f },
};

void EnDaikuKakariko_SetAnimFromIndex(EnDaikuKakariko* pthis, s32 animIndex, s32* currentAnimIndex) {
    f32 morphFrames;

    if ((*currentAnimIndex < 0) || (animIndex == *currentAnimIndex)) {
        morphFrames = 0.0f;
    } else {
        morphFrames = sAnimations[animIndex].transitionRate;
    }

    Animation_Change(&pthis->skelAnime, sAnimations[animIndex].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimations[animIndex].animation), sAnimations[animIndex].mode,
                     morphFrames);

    *currentAnimIndex = animIndex;
}

void EnDaikuKakariko_Init(Actor* thisx, GlobalContext* globalCtx) {
    static u16 initFlags_32[] = { 0x0080, 0x00B0, 0x0070, 0x0470 }; // List of inital values for pthis->flags
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;
    s32 pad;

    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        switch (globalCtx->sceneNum) {
            case SCENE_SPOT01:
                if (IS_DAY) {
                    pthis->flags |= 1;
                    pthis->flags |= initFlags_32[pthis->actor.params & 3];
                }
                break;
            case SCENE_KAKARIKO:
                if (IS_NIGHT) {
                    pthis->flags |= 2;
                }
                break;
            case SCENE_DRAG:
                pthis->flags |= 4;
                break;
        }
    }

    if (!(pthis->flags & 7)) {
        Actor_Kill(&pthis->actor);
    }

    if (IS_NIGHT) {
        pthis->flags |= 8;
    }

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_daiku_Skel_007958, NULL, pthis->jointTable, pthis->morphTable,
                       17);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInit);

    Animation_Change(&pthis->skelAnime, sAnimations->animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimations->animation), sAnimations->mode, sAnimations->transitionRate);

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);

    pthis->actor.gravity = 0.0f;
    pthis->runSpeed = 3.0f;
    pthis->actor.uncullZoneForward = 1200.0f;
    pthis->actor.targetMode = 6;
    pthis->currentAnimIndex = -1;

    if (pthis->flags & 0x40) {
        pthis->actor.gravity = -1.0f;
    }

    if (pthis->flags & 0x10) {
        EnDaikuKakariko_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
        pthis->actionFunc = EnDaikuKakariko_Run;
    } else {
        if (pthis->flags & 8) {
            if (((pthis->actor.params & 3) == CARPENTER_SABOORO) || ((pthis->actor.params & 3) == CARPENTER_SHIRO)) {
                EnDaikuKakariko_SetAnimFromIndex(pthis, 5, &pthis->currentAnimIndex);
                pthis->flags |= 0x800;
            } else {
                EnDaikuKakariko_SetAnimFromIndex(pthis, 1, &pthis->currentAnimIndex);
            }

            pthis->skelAnime.curFrame = (s32)(Rand_ZeroOne() * pthis->skelAnime.endFrame);
        } else {
            EnDaikuKakariko_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
            pthis->skelAnime.curFrame = (s32)(Rand_ZeroOne() * pthis->skelAnime.endFrame);
        }

        pthis->flags |= 0x100;
        pthis->actionFunc = EnDaikuKakariko_Wait;
    }
}

void EnDaikuKakariko_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnDaikuKakariko_GetTalkState(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    s32 talkState = 2;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        switch (pthis->actor.textId) {
            case 0x6061:
                gSaveContext.infTable[23] |= 0x40;
                break;
            case 0x6064:
                gSaveContext.infTable[23] |= 0x100;
                break;
        }
        talkState = 0;
    }
    return talkState;
}

void EnDaikuKakariko_HandleTalking(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    s16 sp26;
    s16 sp24;

    if (pthis->talkState == 2) {
        pthis->talkState = EnDaikuKakariko_GetTalkState(pthis, globalCtx);
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->talkState = 2;
    } else {
        Actor_GetScreenPos(globalCtx, &pthis->actor, &sp26, &sp24);

        if ((sp26 >= 0) && (sp26 <= 320) && (sp24 >= 0) && (sp24 <= 240) && (pthis->talkState == 0) &&
            (func_8002F2CC(&pthis->actor, globalCtx, 100.0f) == 1)) {
            pthis->actor.textId = Text_GetFaceReaction(globalCtx, maskReactionSets_35[pthis->actor.params & 3]);

            if (pthis->actor.textId == 0) {
                switch (pthis->actor.params & 3) {
                    case 0:
                        if (pthis->flags & 8) {
                            pthis->actor.textId = 0x5076;
                        } else {
                            pthis->actor.textId = 0x5075;
                        }
                        break;
                    case 1:
                        if (pthis->flags & 1) {
                            pthis->actor.textId = 0x502A;
                        } else {
                            pthis->actor.textId = 0x5074;
                        }
                        break;
                    case 2:
                        if (pthis->flags & 1) {
                            pthis->actor.textId = 0x506A;
                        } else {
                            pthis->actor.textId = 0x506B;
                        }
                        break;
                    case 3:
                        if (pthis->flags & 1) {
                            pthis->actor.textId = 0x5077;
                        } else {
                            pthis->actor.textId = 0x5078;
                        }
                        break;
                }
            }
        }
    }
}

void EnDaikuKakariko_Talk(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDaikuKakariko_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
    }

    EnDaikuKakariko_HandleTalking(pthis, globalCtx);

    if (pthis->talkState == 0) {
        if (pthis->flags & 0x10) {
            EnDaikuKakariko_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
            pthis->flags &= ~0x0300;
            pthis->actionFunc = EnDaikuKakariko_Run;
            return;
        }

        if (!(pthis->flags & 8)) {
            EnDaikuKakariko_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
        }

        if ((pthis->flags & 0x800) == 0) {
            pthis->flags &= ~0x0200;
            pthis->flags |= 0x100;
        }

        pthis->actionFunc = EnDaikuKakariko_Wait;
    }
}

void EnDaikuKakariko_Wait(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    EnDaikuKakariko_HandleTalking(pthis, globalCtx);

    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDaikuKakariko_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
    }

    if (pthis->talkState != 0) {
        if (!(pthis->flags & 8)) {
            EnDaikuKakariko_SetAnimFromIndex(pthis, 4, &pthis->currentAnimIndex);
        }

        if (!(pthis->flags & 0x800)) {
            pthis->flags |= 0x200;
            pthis->flags &= ~0x0100;
        }

        pthis->actionFunc = EnDaikuKakariko_Talk;
    }
}

void EnDaikuKakariko_StopRunning(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->timer--;

        if (pthis->timer <= 0) {
            EnDaikuKakariko_SetAnimFromIndex(pthis, 3, &pthis->currentAnimIndex);
            pthis->actionFunc = EnDaikuKakariko_Run;
        } else {
            pthis->skelAnime.curFrame = pthis->skelAnime.startFrame;
        }
    }

    EnDaikuKakariko_HandleTalking(pthis, globalCtx);

    if (pthis->talkState != 0) {
        pthis->flags |= 0x200;
        EnDaikuKakariko_SetAnimFromIndex(pthis, 4, &pthis->currentAnimIndex);
        pthis->actionFunc = EnDaikuKakariko_Talk;
    }
}

void EnDaikuKakariko_Run(EnDaikuKakariko* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Path* path;
    Vec3s* pathPos;
    f32 xDist;
    f32 zDist;
    s16 runAngle;
    f32 runDist;
    s16 angleStepDiff;
    s32 run;

    do {
        path = &globalCtx->setupPathList[(pthis->actor.params >> 8) & 0xFF];
        pathPos = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[pthis->waypoint];
        xDist = pathPos->x - pthis->actor.world.pos.x;
        zDist = pathPos->z - pthis->actor.world.pos.z;
        runAngle = Math_FAtan2F(xDist, zDist) * (32768.0f / M_PI);
        runDist = sqrtf((xDist * xDist) + (zDist * zDist));

        run = false;

        if (runDist <= 10.0f) {
            if (pthis->pathContinue == false) {
                pthis->waypoint++;

                if (pthis->waypoint >= path->count) {
                    if (pthis->flags & 0x20) {
                        pthis->waypoint = path->count - 2;
                        pthis->pathContinue = true;
                        pthis->run = run = false;

                        if (pthis->flags & 0x400) {
                            pthis->timer = 2;
                            EnDaikuKakariko_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
                            pthis->actionFunc = EnDaikuKakariko_StopRunning;
                            return;
                        }
                    } else {
                        pthis->waypoint = 0;
                        run = true;
                    }
                } else {
                    pthis->run = run = true;
                }
            } else {
                pthis->waypoint--;

                if (pthis->waypoint < 0) {
                    pthis->waypoint = 1;
                    pthis->pathContinue = false;
                    pthis->run = run = false;

                    if (pthis->flags & 0x400) {
                        pthis->timer = 2;
                        EnDaikuKakariko_SetAnimFromIndex(pthis, 0, &pthis->currentAnimIndex);
                        pthis->actionFunc = EnDaikuKakariko_StopRunning;
                        return;
                    }
                } else {
                    run = true;
                }
            }
        }
    } while (run);

    angleStepDiff = Math_SmoothStepToS(&pthis->actor.shape.rot.y, runAngle, 1, 5000, 0);

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

    if (pthis->run == false) {
        if (angleStepDiff == 0) {
            pthis->run = true;
        } else {
            pthis->actor.speedXZ = 0.0f;
        }
    }

    if (pthis->run == true) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->runSpeed, 0.8f, runDist, 0.0f);
    }

    Actor_MoveForward(&pthis->actor);

    if (pthis->flags & 0x40) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    } else if (pthis->flags & 0x80) {
        pthis->runFlag |= 1;
        pthis->flags &= ~0x0080;
    } else if (pthis->runFlag & 1) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
        pthis->runFlag &= ~1;
    }

    SkelAnime_Update(&pthis->skelAnime);
    EnDaikuKakariko_HandleTalking(pthis, globalCtx);

    if (pthis->talkState != 0) {
        pthis->flags |= 0x200;
        EnDaikuKakariko_SetAnimFromIndex(pthis, 4, &pthis->currentAnimIndex);
        pthis->actionFunc = EnDaikuKakariko_Talk;
    }
}

void EnDaikuKakariko_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad2;

    if (pthis->currentAnimIndex == 3) {
        if (((s32)pthis->skelAnime.curFrame == 6) || ((s32)pthis->skelAnime.curFrame == 15)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
        }
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if (pthis->flags & 4) {
        pthis->collider.dim.pos.x -= 27;
        pthis->collider.dim.pos.z -= 27;
        pthis->collider.dim.radius = 63;
    }

    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    pthis->actionFunc(pthis, globalCtx);

    pthis->npcInfo.unk_18.x = player->actor.focus.pos.x;
    pthis->npcInfo.unk_18.y = player->actor.focus.pos.y;
    pthis->npcInfo.unk_18.z = player->actor.focus.pos.z;

    if (pthis->flags & 0x100) {
        pthis->neckAngleTarget.x = 5900;
        pthis->flags |= 0x1000;
        func_80034A14(&pthis->actor, &pthis->npcInfo, 0, 2);
    } else if (pthis->flags & 0x200) {
        pthis->neckAngleTarget.x = 5900;
        pthis->flags |= 0x1000;
        func_80034A14(&pthis->actor, &pthis->npcInfo, 0, 4);
    }

    Math_SmoothStepToS(&pthis->neckAngle.x, pthis->neckAngleTarget.x, 1, 1820, 0);
}

s32 EnDaikuKakariko_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                     void* thisx) {
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;
    Vec3s angle;

    switch (limbIndex) {
        case 8:
            angle = pthis->npcInfo.unk_0E;
            Matrix_RotateX(-(angle.y * (M_PI / 32768.0f)), MTXMODE_APPLY);
            Matrix_RotateZ(-(angle.x * (M_PI / 32768.0f)), MTXMODE_APPLY);
            break;
        case 15:
            Matrix_Translate(1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
            angle = pthis->npcInfo.unk_08;

            if (pthis->flags & 0x1000) {
                osSyncPrintf("<%d>\n", pthis->neckAngle.x);
                Matrix_RotateX((angle.y + pthis->neckAngle.y) * (M_PI / 32768.0f), MTXMODE_APPLY);
                Matrix_RotateZ((angle.x + pthis->neckAngle.x) * (M_PI / 32768.0f), MTXMODE_APPLY);
            } else {
                Matrix_RotateX(angle.y * (M_PI / 32768.0f), MTXMODE_APPLY);
                Matrix_RotateZ(angle.x * (M_PI / 32768.0f), MTXMODE_APPLY);
            }

            Matrix_Translate(-1400.0f, 0.0f, 0.0f, MTXMODE_APPLY);
            break;
    }

    return 0;
}

void EnDaikuKakariko_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku_kakariko.c", 1104);

    if (limbIndex == 15) {
        Matrix_MultVec3f(&unkVec_42, &pthis->actor.focus.pos);
        gSPDisplayList(POLY_OPA_DISP++, carpenterHeadDLists_42[pthis->actor.params & 3]);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku_kakariko.c", 1113);
}

void EnDaikuKakariko_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDaikuKakariko* pthis = (EnDaikuKakariko*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku_kakariko.c", 1124);

    func_80093D18(globalCtx->state.gfxCtx);

    if ((thisx->params & 3) == CARPENTER_ICHIRO) {
        gDPSetEnvColor(POLY_OPA_DISP++, 170, 10, 70, 255);
    } else if ((thisx->params & 3) == CARPENTER_SABOORO) {
        gDPSetEnvColor(POLY_OPA_DISP++, 170, 200, 255, 255);
    } else if ((thisx->params & 3) == CARPENTER_JIRO) {
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 230, 70, 255);
    } else if ((thisx->params & 3) == CARPENTER_SHIRO) {
        gDPSetEnvColor(POLY_OPA_DISP++, 200, 0, 150, 255);
    }

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnDaikuKakariko_OverrideLimbDraw, EnDaikuKakariko_PostLimbDraw, thisx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_daiku_kakariko.c", 1151);
}

void EnDaikuKakariko_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    unkVec_42 = { 700.0f, 1100.0f, 0.0f };

    En_Daiku_Kakariko_InitVars = {
        ACTOR_EN_DAIKU_KAKARIKO,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_DAIKU,
        sizeof(EnDaikuKakariko),
        (ActorFunc)EnDaikuKakariko_Init,
        (ActorFunc)EnDaikuKakariko_Destroy,
        (ActorFunc)EnDaikuKakariko_Update,
        (ActorFunc)EnDaikuKakariko_Draw,
        (ActorFunc)EnDaikuKakariko_Reset,
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

    sColChkInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

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

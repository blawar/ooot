#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TK_Z_EN_TK_C
#include "actor_common.h"
/*
 * File: z_en_tk.c
 * Overlay: ovl_En_Tk
 * Description: Dampe NPC from "Dampe's Heart-Pounding Gravedigging Tour"
 */

#include "z_en_tk.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_tk/object_tk.h"
#include "def/audio_bank.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_en_item00.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnTk_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTk_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnTk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTk_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTk_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnTk_CheckNextSpot(EnTk* pthis, GlobalContext* globalCtx);
void EnTk_Rest(EnTk* pthis, GlobalContext* globalCtx);
void EnTk_Walk(EnTk* pthis, GlobalContext* globalCtx);
void EnTk_Dig(EnTk* pthis, GlobalContext* globalCtx);

static void* dustTextures_34[] = {
    gDust8Tex, gDust7Tex, gDust6Tex, gDust5Tex, gDust4Tex, gDust3Tex, gDust2Tex, gDust1Tex,
};

static void* sEyesSegments_62[] = {
    gDampeEyeOpenTex,
    gDampeEyeHalfTex,
    gDampeEyeClosedTex,
};


ActorInit En_Tk_InitVars = {
    ACTOR_EN_TK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TK,
    sizeof(EnTk),
    (ActorFunc)EnTk_Init,
    (ActorFunc)EnTk_Destroy,
    (ActorFunc)EnTk_Update,
    (ActorFunc)EnTk_Draw,
    (ActorFunc)EnTk_Reset,
};

void EnTkEff_Create(EnTk* pthis, Vec3f* pos, Vec3f* speed, Vec3f* accel, u8 duration, f32 size, f32 growth) {
    s16 i;
    EnTkEff* eff = pthis->eff;

    for (i = 0; i < ARRAY_COUNT(pthis->eff); i++) {
        if (eff->active != 1) {
            eff->size = size;
            eff->growth = growth;
            eff->timeTotal = eff->timeLeft = duration;
            eff->active = 1;
            eff->pos = *pos;
            eff->accel = *accel;
            eff->speed = *speed;
            break;
        }
        eff++;
    }
}

void EnTkEff_Update(EnTk* pthis) {
    s16 i;
    EnTkEff* eff;

    eff = pthis->eff;
    for (i = 0; i < ARRAY_COUNT(pthis->eff); i++) {
        if (eff->active != 0) {
            eff->timeLeft--;
            if (eff->timeLeft == 0) {
                eff->active = 0;
            }
            eff->accel.x = Rand_ZeroOne() * 0.4f - 0.2f;
            eff->accel.z = Rand_ZeroOne() * 0.4f - 0.2f;
            eff->pos.x += eff->speed.x;
            eff->pos.y += eff->speed.y;
            eff->pos.z += eff->speed.z;
            eff->speed.x += eff->accel.x;
            eff->speed.y += eff->accel.y;
            eff->speed.z += eff->accel.z;
            eff->size += eff->growth;
        }
        eff++;
    }
}

void EnTkEff_Draw(EnTk* pthis, GlobalContext* globalCtx) {

    EnTkEff* eff = pthis->eff;
    s16 imageIdx;
    s16 gfxSetup;
    s16 alpha;
    s16 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_tk_eff.c", 114);

    gfxSetup = 0;

    func_80093D84(globalCtx->state.gfxCtx);

    if (1) {}

    for (i = 0; i < ARRAY_COUNT(pthis->eff); i++) {
        if (eff->active != 0) {
            if (gfxSetup == 0) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
                gSPDisplayList(POLY_XLU_DISP++, gDampeEff1DL);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 60, 20, 0);
                gfxSetup = 1;
            }

            alpha = eff->timeLeft * (255.0f / eff->timeTotal);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 170, 130, 90, alpha);

            gDPPipeSync(POLY_XLU_DISP++);
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->size, eff->size, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_tk_eff.c", 140),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            imageIdx = eff->timeLeft * ((f32)ARRAY_COUNT(dustTextures_34) / eff->timeTotal);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(dustTextures_34[imageIdx]));

            gSPDisplayList(POLY_XLU_DISP++, gDampeEff2DL);
        }
        eff++;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_tk_eff.c", 154);
}

s32 EnTkEff_CreateDflt(EnTk* pthis, Vec3f* pos, u8 duration, f32 size, f32 growth, f32 yAccelMax) {
    Vec3f speed = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };

    accel.y += Rand_ZeroOne() * yAccelMax;

    EnTkEff_Create(pthis, pos, &speed, &accel, duration, size, growth);

    return 0;
}

/** z_en_tk_eff.c ends here probably **/

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
    { 30, 52, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

void EnTk_RestAnim(EnTk* pthis, GlobalContext* globalCtx) {
    AnimationHeader* anim = &gDampeRestAnim;

    Animation_Change(&pthis->skelAnime, anim, 1.0f, 0.0f, Animation_GetLastFrame(&gDampeRestAnim), ANIMMODE_LOOP,
                     -10.0f);

    pthis->actionCountdown = Rand_S16Offset(60, 60);
    pthis->actor.speedXZ = 0.0f;
}

void EnTk_WalkAnim(EnTk* pthis, GlobalContext* globalCtx) {
    AnimationHeader* anim = &gDampeWalkAnim;

    Animation_Change(&pthis->skelAnime, anim, 1.0f, 0.0f, Animation_GetLastFrame(&gDampeRestAnim), ANIMMODE_LOOP,
                     -10.0f);

    pthis->actionCountdown = Rand_S16Offset(240, 240);
}

void EnTk_DigAnim(EnTk* pthis, GlobalContext* globalCtx) {
    AnimationHeader* anim = &gDampeDigAnim;

    Animation_Change(&pthis->skelAnime, anim, 1.0f, 0.0f, Animation_GetLastFrame(&gDampeDigAnim), ANIMMODE_LOOP, -10.0f);

    if (EnTk_CheckNextSpot(pthis, globalCtx) >= 0) {
        pthis->validDigHere = 1;
    }
}

void EnTk_UpdateEyes(EnTk* pthis) {
    if (DECR(pthis->blinkCountdown) == 0) {
        pthis->eyeTextureIdx++;
        if (pthis->eyeTextureIdx > 2) {
            pthis->blinkCycles--;
            if (pthis->blinkCycles < 0) {
                pthis->blinkCountdown = Rand_S16Offset(30, 30);
                pthis->blinkCycles = 2;
                if (Rand_ZeroOne() > 0.5f) {
                    pthis->blinkCycles++;
                }
            }
            pthis->eyeTextureIdx = 0;
        }
    }
}

s32 EnTk_CheckFacingPlayer(EnTk* pthis) {
    s16 v0;
    s16 v1;

    if (pthis->actor.xyzDistToPlayerSq > 10000.0f) {
        return 0;
    }

    v0 = pthis->actor.shape.rot.y;
    v0 -= pthis->h_21E;
    v0 -= pthis->headRot;

    v1 = pthis->actor.yawTowardsPlayer - v0;
    if (ABS(v1) < 0x1554) {
        return 1;
    } else {
        return 0;
    }
}

s32 EnTk_CheckNextSpot(EnTk* pthis, GlobalContext* globalCtx) {
    Actor* prop;
    f32 dxz;
    f32 dy;

    prop = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

    while (prop != NULL) {
        if (prop->id != ACTOR_EN_IT) {
            prop = prop->next;
            continue;
        }

        if (prop == pthis->currentSpot) {
            prop = prop->next;
            continue;
        }

        dy = prop->world.pos.y - pthis->actor.floorHeight;
        dxz = Actor_WorldDistXZToActor(&pthis->actor, prop);
        if (dxz > 40.0f || dy > 10.0f) {
            prop = prop->next;
            continue;
        }

        pthis->currentSpot = prop;
        return prop->params;
    }

    return -1;
}

void EnTk_CheckCurrentSpot(EnTk* pthis) {
    f32 dxz;
    f32 dy;

    if (pthis->currentSpot != NULL) {
        dy = pthis->currentSpot->world.pos.y - pthis->actor.floorHeight;
        dxz = Actor_WorldDistXZToActor(&pthis->actor, pthis->currentSpot);
        if (dxz > 40.0f || dy > 10.0f) {
            pthis->currentSpot = NULL;
        }
    }
}

f32 EnTk_Step(EnTk* pthis, GlobalContext* globalCtx) {
    f32 stepFrames[] = { 36.0f, 10.0f };
    f32 a1_;
    s32 i;

    if (pthis->skelAnime.curFrame == 0.0f || pthis->skelAnime.curFrame == 25.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
    }

    if (pthis->skelAnime.animation != &gDampeWalkAnim) {
        return 0.0f;
    }

    a1_ = pthis->skelAnime.curFrame;
    for (i = 0; i < ARRAY_COUNT(stepFrames); i++) {
        if (a1_ < stepFrames[i] + 12.0f && a1_ >= stepFrames[i]) {
            break;
        }
    }
    if (i >= ARRAY_COUNT(stepFrames)) {
        return 0.0f;
    } else {
        a1_ = (0x8000 / 12.0f) * (a1_ - stepFrames[i]);
        return Math_SinS(a1_) * 2.0f;
    }
}

s32 EnTk_Orient(EnTk* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* point;
    f32 dx;
    f32 dz;

    if (pthis->actor.params < 0) {
        return 1;
    }

    path = &globalCtx->setupPathList[0];
    point = SEGMENTED_TO_VIRTUAL(path->points);
    point += pthis->currentWaypoint;

    dx = point->x - pthis->actor.world.pos.x;
    dz = point->z - pthis->actor.world.pos.z;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 10, 1000, 1);
    pthis->actor.world.rot = pthis->actor.shape.rot;

    if (SQ(dx) + SQ(dz) < 10.0f) {
        pthis->currentWaypoint++;
        if (pthis->currentWaypoint >= path->count) {
            pthis->currentWaypoint = 0;
        }

        return 0;
    } else {
        return 1;
    }
}

u16 func_80B1C54C(GlobalContext* globalCtx, Actor* thisx) {
    u16 ret;

    ret = Text_GetFaceReaction(globalCtx, 14);
    if (ret != 0) {
        return ret;
    }

    if (gSaveContext.infTable[13] & 0x0200) {
        /* "Do you want me to dig here? ..." */
        return 0x5019;
    } else {
        /* "Hey kid! ..." */
        return 0x5018;
    }
}

s16 func_80B1C5A0(GlobalContext* globalCtx, Actor* thisx) {
    s32 ret = 1;

    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
            break;
        case TEXT_STATE_CLOSING:
            /* "I am the boss of the carpenters ..." (wtf?) */
            if (thisx->textId == 0x5028) {
                gSaveContext.infTable[13] |= 0x0100;
            }
            ret = 0;
            break;
        case TEXT_STATE_DONE_FADING:
            break;
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx) && (thisx->textId == 0x5018 || thisx->textId == 0x5019)) {
                if (globalCtx->msgCtx.choiceIndex == 1) {
                    /* "Thanks a lot!" */
                    thisx->textId = 0x0084;
                } else if (gSaveContext.rupees < 10) {
                    /* "You don't have enough Rupees!" */
                    thisx->textId = 0x0085;
                } else {
                    globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
                    Rupees_ChangeBy(-10);
                    gSaveContext.infTable[13] |= 0x0200;
                    return 2;
                }
                Message_ContinueTextbox(globalCtx, thisx->textId);
                gSaveContext.infTable[13] |= 0x0200;
            }
            break;
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx) && (thisx->textId == 0x0084 || thisx->textId == 0x0085)) {
                Message_CloseTextbox(globalCtx);
                ret = 0;
            }
            break;
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            break;
    }

    return ret;
}

s32 EnTk_ChooseReward(EnTk* pthis) {
    f32 luck;
    s32 reward;

    luck = Rand_ZeroOne();

    if (luck < 0.4f) {
        reward = 0;
    } else if (luck < 0.7) {
        reward = 1;
    } else if (luck < 0.9) {
        reward = 2;
    } else {
        reward = 3;
    }

    switch (reward) {
        case 0:
            if (pthis->rewardCount[0] < 8) {
                pthis->rewardCount[0] += 1;
                return reward;
            }
            break;
        case 1:
            if (pthis->rewardCount[1] < 4) {
                pthis->rewardCount[1] += 1;
                return reward;
            }
            break;
        case 2:
            if (pthis->rewardCount[2] < 2) {
                pthis->rewardCount[2] += 1;
                return reward;
            }
            break;
        case 3:
            if (pthis->rewardCount[3] < 1) {
                pthis->rewardCount[3] += 1;
                return reward;
            }
            break;
    }

    if (pthis->rewardCount[0] < 8) {
        pthis->rewardCount[0] += 1;
        reward = 0;
    } else if (pthis->rewardCount[1] < 4) {
        pthis->rewardCount[1] += 1;
        reward = 1;
    } else if (pthis->rewardCount[2] < 2) {
        pthis->rewardCount[2] += 1;
        reward = 2;
    } else if (pthis->rewardCount[3] < 1) {
        pthis->rewardCount[3] += 1;
        reward = 3;
    } else {
        reward = 0;
        pthis->rewardCount[0] = 1;
        pthis->rewardCount[1] = 0;
        pthis->rewardCount[2] = 0;
        pthis->rewardCount[3] = 0;
    }

    return reward;
}

void EnTk_DigEff(EnTk* pthis) {
    Vec3f pos = { 0.0f, 0.0f, 0.0f };
    Vec3f speed = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };

    if (pthis->skelAnime.curFrame >= 32.0f && pthis->skelAnime.curFrame < 40.0f) {
        pos.x = (Rand_ZeroOne() - 0.5f) * 12.0f + pthis->v3f_304.x;
        pos.y = (Rand_ZeroOne() - 0.5f) * 8.0f + pthis->v3f_304.y;
        pos.z = (Rand_ZeroOne() - 0.5f) * 12.0f + pthis->v3f_304.z;
        EnTkEff_CreateDflt(pthis, &pos, 12, 0.2f, 0.1f, 0.0f);
    }
}

void EnTk_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnTk* pthis = (EnTk*)thisx;
    s32 pad;

    ActorShape_Init(&pthis->actor.shape, 0, ActorShadow_DrawCircle, 24.0f);

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDampeSkel, NULL, pthis->jointTable, pthis->morphTable, 18);
    Animation_Change(&pthis->skelAnime, &gDampeRestAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gDampeRestAnim),
                     ANIMMODE_LOOP, 0.0f);

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);

    if (gSaveContext.dayTime <= 0xC000 || gSaveContext.dayTime >= 0xE000 || !!LINK_IS_ADULT ||
        globalCtx->sceneNum != SCENE_SPOT02) {
        Actor_Kill(&pthis->actor);
        return;
    }

    Actor_SetScale(&pthis->actor, 0.01f);

    pthis->actor.targetMode = 6;
    pthis->actor.gravity = -0.1f;
    pthis->currentReward = -1;
    pthis->currentSpot = NULL;
    pthis->actionFunc = EnTk_Rest;
}

void EnTk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTk* pthis = (EnTk*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnTk_Rest(EnTk* pthis, GlobalContext* globalCtx) {
    s16 v1;
    s16 a1_;

    if (pthis->h_1E0 != 0) {
        v1 = pthis->actor.shape.rot.y;
        v1 -= pthis->h_21E;
        v1 = pthis->actor.yawTowardsPlayer - v1;

        if (pthis->h_1E0 == 2) {
            EnTk_DigAnim(pthis, globalCtx);
            pthis->h_1E0 = 0;
            pthis->actionFunc = EnTk_Dig;
            return;
        }

        func_800343CC(globalCtx, &pthis->actor, &pthis->h_1E0, pthis->collider.dim.radius + 30.0f, func_80B1C54C,
                      func_80B1C5A0);
    } else if (EnTk_CheckFacingPlayer(pthis)) {
        v1 = pthis->actor.shape.rot.y;
        v1 -= pthis->h_21E;
        v1 = pthis->actor.yawTowardsPlayer - v1;

        pthis->actionCountdown = 0;
        func_800343CC(globalCtx, &pthis->actor, &pthis->h_1E0, pthis->collider.dim.radius + 30.0f, func_80B1C54C,
                      func_80B1C5A0);
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        v1 = pthis->actor.shape.rot.y;
        v1 -= pthis->h_21E;
        v1 = pthis->actor.yawTowardsPlayer - v1;

        pthis->actionCountdown = 0;
        pthis->h_1E0 = 1;
    } else if (DECR(pthis->actionCountdown) == 0) {
        EnTk_WalkAnim(pthis, globalCtx);
        pthis->actionFunc = EnTk_Walk;

        /*! @bug v1 is uninitialized past pthis branch */
        v1 = 0;
    } else {
        v1 = 0;
    }

    a1_ = CLAMP(-v1, 1270, 10730);
    Math_SmoothStepToS(&pthis->headRot, a1_, 6, 1000, 1);
}

void EnTk_Walk(EnTk* pthis, GlobalContext* globalCtx) {
    if (pthis->h_1E0 == 2) {
        EnTk_DigAnim(pthis, globalCtx);
        pthis->h_1E0 = 0;
        pthis->actionFunc = EnTk_Dig;
    } else {
        pthis->actor.speedXZ = EnTk_Step(pthis, globalCtx);
        EnTk_Orient(pthis, globalCtx);
        Math_SmoothStepToS(&pthis->headRot, 0, 6, 1000, 1);
        EnTk_CheckCurrentSpot(pthis);

        DECR(pthis->actionCountdown);
        if (EnTk_CheckFacingPlayer(pthis) || pthis->actionCountdown == 0) {
            EnTk_RestAnim(pthis, globalCtx);
            pthis->actionFunc = EnTk_Rest;
        }
    }
}

void EnTk_Dig(EnTk* pthis, GlobalContext* globalCtx) {
    Vec3f rewardOrigin;
    Vec3f rewardPos;
    s32 rewardParams[] = {
        ITEM00_RUPEE_GREEN, ITEM00_RUPEE_BLUE, ITEM00_RUPEE_RED, ITEM00_RUPEE_PURPLE, ITEM00_HEART_PIECE,
    };

    EnTk_DigEff(pthis);

    if (pthis->skelAnime.curFrame == 32.0f) {
        /* What's gonna come out? */
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_DIG_UP);

        pthis->rewardTimer = 0;

        if (pthis->validDigHere == 1) {
            rewardOrigin.x = 0.0f;
            rewardOrigin.y = 0.0f;
            rewardOrigin.z = -40.0f;

            Matrix_RotateY(pthis->actor.shape.rot.y, MTXMODE_NEW);
            Matrix_MultVec3f(&rewardOrigin, &rewardPos);

            rewardPos.x += pthis->actor.world.pos.x;
            rewardPos.y += pthis->actor.world.pos.y;
            rewardPos.z += pthis->actor.world.pos.z;

            pthis->currentReward = EnTk_ChooseReward(pthis);
            if (pthis->currentReward == 3) {
                /*
                 * Upgrade the purple rupee reward to the heart piece if this
                 * is the first grand prize dig.
                 */
                if (!(gSaveContext.itemGetInf[1] & 0x1000)) {
                    gSaveContext.itemGetInf[1] |= 0x1000;
                    pthis->currentReward = 4;
                }
            }

            Item_DropCollectible(globalCtx, &rewardPos, rewardParams[pthis->currentReward]);
        }
    }

    if (pthis->skelAnime.curFrame >= 32.0f && pthis->rewardTimer == 10) {
        /* Play a reward sound shortly after digging */
        if (pthis->validDigHere == 0) {
            /* Bad dig spot */
            Audio_PlayActorSound2(&pthis->actor, NA_SE_SY_ERROR);
        } else if (pthis->currentReward == 4) {
            /* Heart piece */
            Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
        } else {
            /* Rupee */
            Audio_PlayActorSound2(&pthis->actor, NA_SE_SY_TRE_BOX_APPEAR);
        }
    }
    pthis->rewardTimer++;

    if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
        if (pthis->currentReward < 0) {
            /* "Nope, nothing here!" */
            Message_StartTextbox(globalCtx, 0x501A, NULL);
        } else {
            Message_CloseTextbox(globalCtx);
        }

        EnTk_RestAnim(pthis, globalCtx);

        pthis->currentReward = -1;
        pthis->validDigHere = 0;
        pthis->actionFunc = EnTk_Rest;
    }
}

void EnTk_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnTk* pthis = (EnTk*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    SkelAnime_Update(&pthis->skelAnime);

    Actor_MoveForward(&pthis->actor);

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 40.0f, 10.0f, 0.0f, 5);

    pthis->actionFunc(pthis, globalCtx);

    EnTkEff_Update(pthis);

    EnTk_UpdateEyes(pthis);
}

void func_80B1D200(GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_tk.c", 1188);

    gSPDisplayList(POLY_OPA_DISP++, gDampeShovelDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_tk.c", 1190);
}

s32 EnTk_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnTk* pthis = (EnTk*)thisx;

    switch (limbIndex) {
        /* Limb 15 - Head */
        case 15:
            pthis->h_21E = rot->y;
            break;
        /* Limb 16 - Jaw */
        case 16:
            pthis->h_21E += rot->y;
            rot->y += pthis->headRot;
            break;
    }

    return false;
}

void EnTk_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnTk* pthis = (EnTk*)thisx;
    Vec3f sp28 = { 0.0f, 0.0f, 4600.0f };
    Vec3f sp1C = { 0.0f, 0.0f, 0.0f };

    /* Limb 16 - Jaw */
    if (limbIndex == 16) {
        Matrix_MultVec3f(&sp1C, &pthis->actor.focus.pos);
    }

    /* Limb 14 - Neck */
    if (limbIndex == 14) {
        Matrix_MultVec3f(&sp28, &pthis->v3f_304);
        func_80B1D200(globalCtx);
    }
}

void EnTk_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnTk* pthis = (EnTk*)thisx;

    Matrix_Push();
    EnTkEff_Draw(pthis, globalCtx);
    Matrix_Pop();

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_tk.c", 1294);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyesSegments_62[pthis->eyeTextureIdx]));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnTk_OverrideLimbDraw, EnTk_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_tk.c", 1312);
}

void EnTk_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Tk_InitVars = {
        ACTOR_EN_TK,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_TK,
        sizeof(EnTk),
        (ActorFunc)EnTk_Init,
        (ActorFunc)EnTk_Destroy,
        (ActorFunc)EnTk_Update,
        (ActorFunc)EnTk_Draw,
        (ActorFunc)EnTk_Reset,
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
        { 30, 52, 0, { 0, 0, 0 } },
    };

    sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

}

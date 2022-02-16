#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DNT_JIJI_Z_EN_DNT_JIJI_C
#include "actor_common.h"
/*
 * File: z_en_dnt_jiji.c
 * Overlay: ovl_En_Dnt_Jiji
 * Description: Forest Stage scrub leader
 */

#include "z_en_dnt_jiji.h"
#include "objects/object_dns/object_dns.h"
#include "overlays/actors/ovl_En_Dnt_Demo/z_en_dnt_demo.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "vt.h"
#include "def/code_800F9280.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void EnDntJiji_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDntJiji_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDntJiji_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDntJiji_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDntJiji_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDntJiji_SetFlower(EnDntJiji* pthis, GlobalContext* globalCtx);

void EnDntJiji_SetupWait(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupUnburrow(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupWalk(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupCower(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupGivePrize(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupHide(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupReturn(EnDntJiji* pthis, GlobalContext* globalCtx);

void EnDntJiji_Wait(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Up(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Unburrow(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Walk(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Burrow(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Cower(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_SetupTalk(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Talk(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_GivePrize(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Hide(EnDntJiji* pthis, GlobalContext* globalCtx);
void EnDntJiji_Return(EnDntJiji* pthis, GlobalContext* globalCtx);

static void* blinkTex_74[] = { gDntJijiEyeOpenTex, gDntJijiEyeHalfTex, gDntJijiEyeShutTex };


ActorInit En_Dnt_Jiji_InitVars = {
    ACTOR_EN_DNT_JIJI,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DNS,
    sizeof(EnDntJiji),
    (ActorFunc)EnDntJiji_Init,
    (ActorFunc)EnDntJiji_Destroy,
    (ActorFunc)EnDntJiji_Update,
    (ActorFunc)EnDntJiji_Draw,
    (ActorFunc)EnDntJiji_Reset,
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
    { 30, 80, 0, { 0, 0, 0 } },
};

void EnDntJiji_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDntJiji* pthis = (EnDntJiji*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDntJijiSkel, &gDntJijiBurrowAnim, pthis->jointTable, pthis->morphTable,
                   13);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->stage = (EnDntDemo*)pthis->actor.parent;
    osSyncPrintf("\n\n");
    // "Deku Scrub mask show elder"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ デグナッツお面品評会長老 ☆☆☆☆☆ %x\n" VT_RST, pthis->stage);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.colChkInfo.mass = 0xFF;
    pthis->actor.targetMode = 6;
    pthis->actionFunc = EnDntJiji_SetFlower;
    pthis->actor.gravity = -2.0f;
}

void EnDntJiji_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntJiji* pthis = (EnDntJiji*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnDntJiji_SetFlower(EnDntJiji* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->flowerPos = pthis->actor.world.pos;
        pthis->actionFunc = EnDntJiji_SetupWait;
    }
}

void EnDntJiji_SetupWait(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiBurrowAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiBurrowAnim, 0.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->skelAnime.curFrame = 8.0f;
    pthis->isSolid = pthis->action = DNT_LEADER_ACTION_NONE;
    pthis->actionFunc = EnDntJiji_Wait;
}

void EnDntJiji_Wait(EnDntJiji* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->timer == 1) && (pthis->actor.xzDistToPlayer < 150.0f) && !Gameplay_InCsMode(globalCtx) &&
        !(player->stateFlags1 & 0x800)) {
        OnePointCutscene_Init(globalCtx, 2230, -99, &pthis->actor, MAIN_CAM);
        pthis->timer = 0;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = EnDntJiji_SetupUnburrow;
    }
}

void EnDntJiji_SetupUp(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiUpAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiUpAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 6.0f, 0, 15, 5, 20, HAHEN_OBJECT_DEFAULT, 10, NULL);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    pthis->actionFunc = EnDntJiji_Up;
}

void EnDntJiji_Up(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    if (pthis->actor.xzDistToPlayer < 150.0f) {
        pthis->actionFunc = EnDntJiji_SetupCower;
    }
}

void EnDntJiji_SetupUnburrow(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiUnburrowAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiUnburrowAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 6.0f, 0, 15, 5, 20, HAHEN_OBJECT_DEFAULT, 10, NULL);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    pthis->actionFunc = EnDntJiji_Unburrow;
}

void EnDntJiji_Unburrow(EnDntJiji* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->endFrame <= frame) {
        if (pthis->action != DNT_LEADER_ACTION_ATTACK) {
            pthis->actionFunc = EnDntJiji_SetupWalk;
        } else {
            pthis->actionFunc = EnDntJiji_SetupReturn;
        }
    }
}

void EnDntJiji_SetupWalk(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiWalkAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiWalkAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.speedXZ = 1.0f;
    pthis->isSolid = true;
    pthis->unburrow = true;
    pthis->actionFunc = EnDntJiji_Walk;
}

void EnDntJiji_Walk(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x3E8, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    Math_ApproachF(&pthis->actor.speedXZ, 1.0f, 0.2f, 0.4f);
    if (pthis->sfxTimer == 0) {
        pthis->sfxTimer = 5;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if ((pthis->actor.bgCheckFlags & 8) && (pthis->actor.bgCheckFlags & 1)) {
        pthis->actor.velocity.y = 9.0f;
        pthis->actor.speedXZ = 3.0f;
    }
    if (pthis->actor.xzDistToPlayer < 100.0f) {
        if (CUR_UPG_VALUE(UPG_STICKS) == 1) {
            pthis->getItemId = GI_STICK_UPGRADE_20;
        } else {
            pthis->getItemId = GI_STICK_UPGRADE_30;
        }
        pthis->actor.textId = 0x104D;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        pthis->actor.speedXZ = 0.0f;
        pthis->unused = 5;
        pthis->actionFunc = EnDntJiji_Talk;
    }
}

void EnDntJiji_SetupBurrow(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiBurrowAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiBurrowAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 6.0f, 0, 15, 5, 20, HAHEN_OBJECT_DEFAULT, 10, NULL);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DOWN);
    pthis->actionFunc = EnDntJiji_Burrow;
}

void EnDntJiji_Burrow(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
}

void EnDntJiji_SetupCower(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiCowerAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiCowerAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 3.0f, 0, 9, 3, 10, HAHEN_OBJECT_DEFAULT, 10, NULL);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);

    if ((CUR_UPG_VALUE(UPG_NUTS) == 1) || (CUR_UPG_VALUE(UPG_NUTS) == 0)) {
        pthis->getItemId = GI_NUT_UPGRADE_30;
    } else {
        pthis->getItemId = GI_NUT_UPGRADE_40;
    }
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actor.textId = 0x10DB;
    pthis->unused = 5;
    pthis->actionFunc = EnDntJiji_Cower;
}

void EnDntJiji_Cower(EnDntJiji* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    if (frame >= pthis->endFrame) {
        if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
            pthis->actionFunc = EnDntJiji_SetupTalk;
        } else {
            func_8002F2CC(&pthis->actor, globalCtx, 100.0f);
        }
    }
}

void EnDntJiji_SetupTalk(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiTalkAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiTalkAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = EnDntJiji_Talk;
}

void EnDntJiji_Talk(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
        Message_CloseTextbox(globalCtx);
        func_8002DF54(globalCtx, NULL, 7);
        pthis->actor.parent = NULL;
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 400.0f, 200.0f);
        pthis->actionFunc = EnDntJiji_SetupGivePrize;
    }
}

void EnDntJiji_SetupGivePrize(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDntJiji_GivePrize;
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 400.0f, 200.0f);
    }
}

void EnDntJiji_GivePrize(EnDntJiji* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        if ((pthis->getItemId == GI_NUT_UPGRADE_30) || (pthis->getItemId == GI_NUT_UPGRADE_40)) {
            // "nut"
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            osSyncPrintf("実 \n");
            gSaveContext.itemGetInf[1] |= 0x8000;
        } else {
            // "stick"
            osSyncPrintf("棒 \n");
            osSyncPrintf("棒 \n");
            osSyncPrintf("棒 \n");
            osSyncPrintf("棒 \n");
            osSyncPrintf("棒 \n");
            osSyncPrintf("棒 \n");
            gSaveContext.itemGetInf[1] |= 0x4000;
        }
        pthis->actor.textId = 0;
        if ((pthis->stage != NULL) && (pthis->stage->actor.update != NULL)) {
            pthis->stage->action = DNT_ACTION_NONE;
            if (!pthis->unburrow) {
                pthis->stage->leaderSignal = DNT_SIGNAL_HIDE;
            } else {
                pthis->stage->leaderSignal = DNT_SIGNAL_RETURN;
            }
        }
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        if (!pthis->unburrow) {
            pthis->actionFunc = EnDntJiji_SetupHide;
        } else {
            pthis->actionFunc = EnDntJiji_SetupReturn;
        }
    }
}

void EnDntJiji_SetupHide(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiHideAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiHideAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = EnDntJiji_Hide;
}

void EnDntJiji_Hide(EnDntJiji* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->endFrame <= frame) {
        pthis->actionFunc = EnDntJiji_SetupWait;
    }
}

void EnDntJiji_SetupReturn(EnDntJiji* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntJijiWalkAnim);
    Animation_Change(&pthis->skelAnime, &gDntJijiWalkAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.speedXZ = 2.0f;
    pthis->isSolid = pthis->unburrow = true;
    pthis->actionFunc = EnDntJiji_Return;
}

void EnDntJiji_Return(EnDntJiji* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;

    SkelAnime_Update(&pthis->skelAnime);
    dx = pthis->flowerPos.x - pthis->actor.world.pos.x;
    dz = pthis->flowerPos.z - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 1, 0xBB8, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if ((pthis->actor.bgCheckFlags & 8) && (pthis->actor.bgCheckFlags & 1)) {
        pthis->actor.velocity.y = 9.0f;
        pthis->actor.speedXZ = 3.0f;
    }
    if (pthis->sfxTimer == 0) {
        pthis->sfxTimer = 3;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if ((fabsf(dx) < 5.0f) && (fabsf(dz) < 5.0f)) {
        pthis->actor.world.pos.x = pthis->flowerPos.x;
        pthis->actor.world.pos.z = pthis->flowerPos.z;
        if (pthis->attackFlag) {
            if ((pthis->stage->actor.update != NULL) && (pthis->stage->leaderSignal == DNT_SIGNAL_NONE)) {
                pthis->stage->leaderSignal = DNT_SIGNAL_HIDE;
                pthis->stage->action = DNT_ACTION_ATTACK;
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_ENEMY | 0x800);
            }
        }
        pthis->actor.speedXZ = 0.0f;
        pthis->isSolid = 0;
        pthis->actionFunc = EnDntJiji_SetupBurrow;
    }
}

void EnDntJiji_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntJiji* pthis = (EnDntJiji*)thisx;

    Actor_SetScale(&pthis->actor, 0.015f);
    pthis->unkTimer++;
    if (BREG(0)) {
        // "time"
        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 時間 ☆☆☆☆☆ %d\n" VT_RST, pthis->timer);
    }
    if ((pthis->timer > 1) && (pthis->timer != 0)) {
        pthis->timer--;
    }
    if (pthis->sfxTimer != 0) {
        pthis->sfxTimer--;
    }
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    }
    switch (pthis->stageSignal) {
        case DNT_LEADER_SIGNAL_UP:
            pthis->isSolid = true;
            pthis->action = DNT_LEADER_ACTION_UP;
            pthis->actionFunc = EnDntJiji_SetupUp;
            break;
        case DNT_LEADER_SIGNAL_BURROW:
            pthis->isSolid = false;
            pthis->action = DNT_LEADER_ACTION_NONE;
            pthis->actionFunc = EnDntJiji_SetupBurrow;
            break;
        case DNT_LEADER_SIGNAL_RETURN:
            pthis->actionFunc = EnDntJiji_SetupReturn;
            break;
        case DNT_LEADER_SIGNAL_NONE:
            break;
    }
    if (pthis->actor.textId != 0) {
        Actor_SetFocus(&pthis->actor, 30.0f);
    }
    if (pthis->stageSignal != DNT_LEADER_SIGNAL_NONE) {
        pthis->stageSignal = DNT_LEADER_SIGNAL_NONE;
    }
    if (pthis->blinkTimer == 0) {
        pthis->eyeState++;
        if (pthis->eyeState > 2) {
            pthis->eyeState = 0;
            pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 0x1D);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    if (pthis->isSolid != 0) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnDntJiji_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDntJiji* pthis = (EnDntJiji*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_jiji.c", 1019);
    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_Push();
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(blinkTex_74[pthis->eyeState]));
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, NULL, pthis);
    Matrix_Pop();
    Matrix_Translate(pthis->flowerPos.x, pthis->flowerPos.y, pthis->flowerPos.z, MTXMODE_NEW);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dnt_jiji.c", 1040),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDntJijiFlowerDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_jiji.c", 1043);
}

void EnDntJiji_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dnt_Jiji_InitVars = {
        ACTOR_EN_DNT_JIJI,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_DNS,
        sizeof(EnDntJiji),
        (ActorFunc)EnDntJiji_Init,
        (ActorFunc)EnDntJiji_Destroy,
        (ActorFunc)EnDntJiji_Update,
        (ActorFunc)EnDntJiji_Draw,
        (ActorFunc)EnDntJiji_Reset,
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
        { 30, 80, 0, { 0, 0, 0 } },
    };

}

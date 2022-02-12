#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HINTNUTS_Z_EN_HINTNUTS_C
#include "actor_common.h"
/*
 * File: z_en_hintnuts.c
 * Overlay: ovl_En_Hintnuts
 * Description: Hint Deku Scrubs (Deku Tree)
 */

#include "z_en_hintnuts.h"
#include "objects/object_hintnuts/object_hintnuts.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnHintnuts_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHintnuts_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHintnuts_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHintnuts_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHintnuts_SetupWait(EnHintnuts* pthis);
void EnHintnuts_Wait(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_LookAround(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Stand(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_ThrowNut(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Burrow(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_BeginRun(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_BeginFreeze(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Run(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Talk(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Leave(EnHintnuts* pthis, GlobalContext* globalCtx);
void EnHintnuts_Freeze(EnHintnuts* pthis, GlobalContext* globalCtx);

ActorInit En_Hintnuts_InitVars = {
    ACTOR_EN_HINTNUTS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_HINTNUTS,
    sizeof(EnHintnuts),
    (ActorFunc)EnHintnuts_Init,
    (ActorFunc)EnHintnuts_Destroy,
    (ActorFunc)EnHintnuts_Update,
    (ActorFunc)EnHintnuts_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 18, 32, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 1, 18, 32, MASS_HEAVY };

static s16 sPuzzleCounter = 0;

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(gravity, -1, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x0A, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2600, ICHAIN_STOP),
};

void EnHintnuts_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHintnuts* pthis = (EnHintnuts*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    if (pthis->actor.params == 0xA) {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
    } else {
        ActorShape_Init(&pthis->actor.shape, 0x0, ActorShadow_DrawCircle, 35.0f);
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gHintNutsSkel, &gHintNutsStandAnim, pthis->jointTable,
                       pthis->morphTable, 10);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
        CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
        Actor_SetTextWithPrefix(globalCtx, &pthis->actor, (pthis->actor.params >> 8) & 0xFF);
        pthis->textIdCopy = pthis->actor.textId;
        pthis->actor.params &= 0xFF;
        sPuzzleCounter = 0;
        if (pthis->actor.textId == 0x109B) {
            if (Flags_GetClear(globalCtx, 0x9) != 0) {
                Actor_Kill(&pthis->actor);
                return;
            }
        }
        EnHintnuts_SetupWait(pthis);
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_HINTNUTS, pthis->actor.world.pos.x,
                           pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, pthis->actor.world.rot.y, 0, 0xA);
    }
}

void EnHintnuts_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHintnuts* pthis = (EnHintnuts*)thisx;

    if (pthis->actor.params != 0xA) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnHintnuts_HitByScrubProjectile1(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.textId != 0 && pthis->actor.category == ACTORCAT_ENEMY &&
        ((pthis->actor.params == 0) || (sPuzzleCounter == 2))) {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_BG);
    }
}

void EnHintnuts_SetupWait(EnHintnuts* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gHintNutsUpAnim, 0.0f);
    pthis->animFlagAndTimer = Rand_S16Offset(100, 50);
    pthis->collider.dim.height = 5;
    pthis->actor.world.pos = pthis->actor.home.pos;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnHintnuts_Wait;
}

void EnHintnuts_SetupLookAround(EnHintnuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gHintNutsLookAroundAnim);
    pthis->animFlagAndTimer = 2;
    pthis->actionFunc = EnHintnuts_LookAround;
}

void EnHintnuts_SetupThrowScrubProjectile(EnHintnuts* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gHintNutsSpitAnim);
    pthis->actionFunc = EnHintnuts_ThrowNut;
}

void EnHintnuts_SetupStand(EnHintnuts* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gHintNutsStandAnim, -3.0f);
    if (pthis->actionFunc == EnHintnuts_ThrowNut) {
        pthis->animFlagAndTimer = 2 | 0x1000; // sets timer and flag
    } else {
        pthis->animFlagAndTimer = 1;
    }
    pthis->actionFunc = EnHintnuts_Stand;
}

void EnHintnuts_SetupBurrow(EnHintnuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gHintNutsBurrowAnim, -5.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DOWN);
    pthis->actionFunc = EnHintnuts_Burrow;
}

void EnHintnuts_HitByScrubProjectile2(EnHintnuts* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gHintNutsUnburrowAnim, -3.0f);
    pthis->collider.dim.height = 37;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
    pthis->collider.base.acFlags &= ~AC_ON;

    if (pthis->actor.params > 0 && pthis->actor.params < 4 && pthis->actor.category == ACTORCAT_ENEMY) {
        if (sPuzzleCounter == -4) {
            sPuzzleCounter = 0;
        }
        if (pthis->actor.params == sPuzzleCounter + 1) {
            sPuzzleCounter++;
        } else {
            if (sPuzzleCounter > 0) {
                sPuzzleCounter = -sPuzzleCounter;
            }
            sPuzzleCounter--;
        }
        pthis->actor.flags |= ACTOR_FLAG_4;
        pthis->actionFunc = EnHintnuts_BeginFreeze;
    } else {
        pthis->actionFunc = EnHintnuts_BeginRun;
    }
}

void EnHintnuts_SetupRun(EnHintnuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gHintNutsRunAnim);
    pthis->animFlagAndTimer = 5;
    pthis->actionFunc = EnHintnuts_Run;
}

void EnHintnuts_SetupTalk(EnHintnuts* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gHintNutsTalkAnim, -5.0f);
    pthis->actionFunc = EnHintnuts_Talk;
    pthis->actor.speedXZ = 0.0f;
}

void EnHintnuts_SetupLeave(EnHintnuts* pthis, GlobalContext* globalCtx) {
    Animation_MorphToLoop(&pthis->skelAnime, &gHintNutsRunAnim, -5.0f);
    pthis->actor.speedXZ = 3.0f;
    pthis->animFlagAndTimer = 100;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->collider.base.ocFlags1 &= ~OC1_ON;
    pthis->actor.flags |= ACTOR_FLAG_4;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ITEM00, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                pthis->actor.world.pos.z, 0x0, 0x0, 0x0, 0x3); // recovery heart
    pthis->actionFunc = EnHintnuts_Leave;
}

void EnHintnuts_SetupFreeze(EnHintnuts* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gHintNutsFreezeAnim);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 100);
    pthis->actor.colorFilterTimer = 1;
    pthis->animFlagAndTimer = 0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_FAINT);
    if (sPuzzleCounter == -3) {
        func_80078884(NA_SE_SY_ERROR);
        sPuzzleCounter = -4;
    }
    pthis->actionFunc = EnHintnuts_Freeze;
}

void EnHintnuts_Wait(EnHintnuts* pthis, GlobalContext* globalCtx) {
    s32 hasSlowPlaybackSpeed = false;

    if (pthis->skelAnime.playSpeed < 0.5f) {
        hasSlowPlaybackSpeed = true;
    }
    if (hasSlowPlaybackSpeed && (pthis->animFlagAndTimer != 0)) {
        pthis->animFlagAndTimer--;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
        pthis->collider.base.acFlags |= AC_ON;
    } else if (Animation_OnFrame(&pthis->skelAnime, 8.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
    }

    pthis->collider.dim.height = 5.0f + ((CLAMP(pthis->skelAnime.curFrame, 9.0f, 12.0f) - 9.0f) * 9.0f);
    if (!hasSlowPlaybackSpeed && (pthis->actor.xzDistToPlayer < 120.0f)) {
        EnHintnuts_SetupBurrow(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.xzDistToPlayer < 120.0f) {
            EnHintnuts_SetupBurrow(pthis);
        } else if ((pthis->animFlagAndTimer == 0) && (pthis->actor.xzDistToPlayer > 320.0f)) {
            EnHintnuts_SetupLookAround(pthis);
        } else {
            EnHintnuts_SetupStand(pthis);
        }
    }
    if (hasSlowPlaybackSpeed && 160.0f < pthis->actor.xzDistToPlayer && fabsf(pthis->actor.yDistToPlayer) < 120.0f &&
        ((pthis->animFlagAndTimer == 0) || (pthis->actor.xzDistToPlayer < 480.0f))) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnHintnuts_LookAround(EnHintnuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->animFlagAndTimer != 0) {
        pthis->animFlagAndTimer--;
    }
    if ((pthis->actor.xzDistToPlayer < 120.0f) || (pthis->animFlagAndTimer == 0)) {
        EnHintnuts_SetupBurrow(pthis);
    }
}

void EnHintnuts_Stand(EnHintnuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->animFlagAndTimer != 0) {
        pthis->animFlagAndTimer--;
    }
    if (!(pthis->animFlagAndTimer & 0x1000)) {
        Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    }
    if (pthis->actor.xzDistToPlayer < 120.0f || pthis->animFlagAndTimer == 0x1000) {
        EnHintnuts_SetupBurrow(pthis);
    } else if (pthis->animFlagAndTimer == 0) {
        EnHintnuts_SetupThrowScrubProjectile(pthis);
    }
}

void EnHintnuts_ThrowNut(EnHintnuts* pthis, GlobalContext* globalCtx) {
    Vec3f nutPos;

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
    if (pthis->actor.xzDistToPlayer < 120.0f) {
        EnHintnuts_SetupBurrow(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        EnHintnuts_SetupStand(pthis);
    } else if (Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        nutPos.x = pthis->actor.world.pos.x + (Math_SinS(pthis->actor.shape.rot.y) * 23.0f);
        nutPos.y = pthis->actor.world.pos.y + 12.0f;
        nutPos.z = pthis->actor.world.pos.z + (Math_CosS(pthis->actor.shape.rot.y) * 23.0f);
        if (Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NUTSBALL, nutPos.x, nutPos.y, nutPos.z,
                        pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 1) != NULL) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
        }
    }
}

void EnHintnuts_Burrow(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnHintnuts_SetupWait(pthis);
    } else {
        pthis->collider.dim.height = 5.0f + ((3.0f - CLAMP(pthis->skelAnime.curFrame, 1.0f, 3.0f)) * 12.0f);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 4.0f)) {
        pthis->collider.base.acFlags &= ~AC_ON;
    }

    Math_ApproachF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 0.5f, 3.0f);
    Math_ApproachF(&pthis->actor.world.pos.z, pthis->actor.home.pos.z, 0.5f, 3.0f);
}

void EnHintnuts_BeginRun(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_196 = pthis->actor.yawTowardsPlayer + 0x8000;
        EnHintnuts_SetupRun(pthis);
    }
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0xE38);
}

void EnHintnuts_BeginFreeze(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnHintnuts_SetupFreeze(pthis);
    }
}

void EnHintnuts_CheckProximity(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.category != ACTORCAT_ENEMY) {
        if ((pthis->collider.base.ocFlags1 & OC1_HIT) || pthis->actor.isTargeted) {
            pthis->actor.flags |= ACTOR_FLAG_16;
        } else {
            pthis->actor.flags &= ~ACTOR_FLAG_16;
        }
        if (pthis->actor.xzDistToPlayer < 130.0f) {
            pthis->actor.textId = pthis->textIdCopy;
            func_8002F2F4(&pthis->actor, globalCtx);
        }
    }
}

void EnHintnuts_Run(EnHintnuts* pthis, GlobalContext* globalCtx) {
    s32 temp_ret;
    s16 diffRotInit;
    s16 diffRot;
    f32 phi_f0;

    SkelAnime_Update(&pthis->skelAnime);
    temp_ret = Animation_OnFrame(&pthis->skelAnime, 0.0f);
    if (temp_ret != 0 && pthis->animFlagAndTimer != 0) {
        pthis->animFlagAndTimer--;
    }
    if ((temp_ret != 0) || (Animation_OnFrame(&pthis->skelAnime, 6.0f))) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }

    Math_StepToF(&pthis->actor.speedXZ, 7.5f, 1.0f);
    if (Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->unk_196, 1, 0xE38, 0xB6) == 0) {
        if (pthis->actor.bgCheckFlags & 0x20) {
            pthis->unk_196 = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
        } else if (pthis->actor.bgCheckFlags & 8) {
            pthis->unk_196 = pthis->actor.wallYaw;
        } else if (pthis->animFlagAndTimer == 0) {
            diffRotInit = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
            diffRot = diffRotInit - pthis->actor.yawTowardsPlayer;
            if (ABS(diffRot) >= 0x2001) {
                pthis->unk_196 = diffRotInit;
            } else {
                phi_f0 = (0.0f <= (f32)diffRot) ? 1.0f : -1.0f;
                pthis->unk_196 = (s16)((phi_f0 * -8192.0f) + (f32)pthis->actor.yawTowardsPlayer);
            }
        } else {
            pthis->unk_196 = (s16)(pthis->actor.yawTowardsPlayer + 0x8000);
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        EnHintnuts_SetupTalk(pthis);
    } else if (pthis->animFlagAndTimer == 0 && Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) < 20.0f &&
               fabsf(pthis->actor.world.pos.y - pthis->actor.home.pos.y) < 2.0f) {
        pthis->actor.speedXZ = 0.0f;
        if (pthis->actor.category == ACTORCAT_BG) {
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_16);
            pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
        }
        EnHintnuts_SetupBurrow(pthis);
    } else {
        EnHintnuts_CheckProximity(pthis, globalCtx);
    }
}

void EnHintnuts_Talk(EnHintnuts* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0x3, 0x400, 0x100);
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) {
        EnHintnuts_SetupLeave(pthis, globalCtx);
    }
}

void EnHintnuts_Leave(EnHintnuts* pthis, GlobalContext* globalCtx) {
    s16 temp_a1;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->animFlagAndTimer != 0) {
        pthis->animFlagAndTimer--;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if (pthis->actor.bgCheckFlags & 8) {
        temp_a1 = pthis->actor.wallYaw;
    } else {
        temp_a1 = pthis->actor.yawTowardsPlayer - Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - 0x8000;
        if (ABS(temp_a1) >= 0x4001) {
            temp_a1 = Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000;
        } else {
            temp_a1 = Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - (temp_a1 >> 1) + 0x8000;
        }
    }
    Math_ScaledStepToS(&pthis->actor.shape.rot.y, temp_a1, 0x800);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if ((pthis->animFlagAndTimer == 0) || (pthis->actor.projectedPos.z < 0.0f)) {
        Message_CloseTextbox(globalCtx);
        if (pthis->actor.params == 3) {
            Flags_SetClear(globalCtx, pthis->actor.room);
            sPuzzleCounter = 3;
        }
        if (pthis->actor.child != NULL) {
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, pthis->actor.child, ACTORCAT_PROP);
        }
        Actor_Kill(&pthis->actor);
    }
}

void EnHintnuts_Freeze(EnHintnuts* pthis, GlobalContext* globalCtx) {
    pthis->actor.colorFilterTimer = 1;
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_FAINT);
    }
    if (pthis->animFlagAndTimer == 0) {
        if (sPuzzleCounter == 3) {
            if (pthis->actor.child != NULL) {
                Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, pthis->actor.child, ACTORCAT_PROP);
            }
            pthis->animFlagAndTimer = 1;
        } else if (sPuzzleCounter == -4) {
            pthis->animFlagAndTimer = 2;
        }
    } else if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - 35.0f, 7.0f) != 0) {
        if (pthis->animFlagAndTimer == 1) {
            Actor_Kill(&pthis->actor);
        } else {
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->actor.flags &= ~ACTOR_FLAG_4;
            pthis->actor.colChkInfo.health = sColChkInfoInit.health;
            pthis->actor.colorFilterTimer = 0;
            EnHintnuts_SetupWait(pthis);
        }
    }
}

void EnHintnuts_ColliderCheck(EnHintnuts* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if (pthis->collider.base.ac->id != ACTOR_EN_NUTSBALL) {
            EnHintnuts_SetupBurrow(pthis);
        } else {
            EnHintnuts_HitByScrubProjectile1(pthis, globalCtx);
            EnHintnuts_HitByScrubProjectile2(pthis);
        }
    } else if (globalCtx->actorCtx.unk_02 != 0) {
        EnHintnuts_HitByScrubProjectile1(pthis, globalCtx);
        EnHintnuts_HitByScrubProjectile2(pthis);
    }
}

void EnHintnuts_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHintnuts* pthis = (EnHintnuts*)thisx;
    s32 pad;

    if (pthis->actor.params != 0xA) {
        EnHintnuts_ColliderCheck(pthis, globalCtx);
        pthis->actionFunc(pthis, globalCtx);
        if (pthis->actionFunc != EnHintnuts_Freeze && pthis->actionFunc != EnHintnuts_BeginFreeze) {
            Actor_MoveForward(&pthis->actor);
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, pthis->collider.dim.radius,
                                    pthis->collider.dim.height, 0x1D);
        }
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        if (pthis->actionFunc == EnHintnuts_Wait) {
            Actor_SetFocus(&pthis->actor, pthis->skelAnime.curFrame);
        } else if (pthis->actionFunc == EnHintnuts_Burrow) {
            Actor_SetFocus(&pthis->actor,
                           20.0f - ((pthis->skelAnime.curFrame * 20.0f) / Animation_GetLastFrame(&gHintNutsBurrowAnim)));
        } else {
            Actor_SetFocus(&pthis->actor, 20.0f);
        }
    }
}

s32 EnHintnuts_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    Vec3f vec;
    f32 curFrame;
    EnHintnuts* pthis = (EnHintnuts*)thisx;

    if (limbIndex == 5 && pthis->actionFunc == EnHintnuts_ThrowNut) {
        curFrame = pthis->skelAnime.curFrame;
        if (curFrame <= 6.0f) {
            vec.y = 1.0f - (curFrame * 0.0833f);
            vec.z = 1.0f + (curFrame * 0.1167f);
            vec.x = 1.0f + (curFrame * 0.1167f);
        } else if (curFrame <= 7.0f) {
            curFrame -= 6.0f;
            vec.y = 0.5f + curFrame;
            vec.z = 1.7f - (curFrame * 0.7f);
            vec.x = 1.7f - (curFrame * 0.7f);
        } else if (curFrame <= 10.0f) {
            vec.y = 1.5f - ((curFrame - 7.0f) * 0.1667f);
            vec.z = 1.0f;
            vec.x = 1.0f;
        } else {
            return false;
        }
        Matrix_Scale(vec.x, vec.y, vec.z, MTXMODE_APPLY);
    }
    return false;
}

void EnHintnuts_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHintnuts* pthis = (EnHintnuts*)thisx;

    if (pthis->actor.params == 0xA) {
        Gfx_DrawDListOpa(globalCtx, gHintNutsFlowerDL);
    } else {
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnHintnuts_OverrideLimbDraw,
                          NULL, pthis);
    }
}

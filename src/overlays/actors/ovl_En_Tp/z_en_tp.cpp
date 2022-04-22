#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_TP_Z_EN_TP_C
#include "actor_common.h"
/*
 * File: z_en_tp.c
 * Overlay: ovl_En_Tp
 * Description: Electric Tailpasaran
 */

#include "z_en_tp.h"
#include "objects/object_tp/object_tp.h"
#include "def/audio_bank.h"
#include "def/random.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void EnTp_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnTp_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Update(Actor* thisx, GlobalContext* globalCtx);
void EnTp_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnTp_Tail_SetupFollowHead(EnTp* pthis);
void EnTp_Tail_FollowHead(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_Head_SetupApproachPlayer(EnTp* pthis);
void EnTp_Head_ApproachPlayer(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_SetupDie(EnTp* pthis);
void EnTp_Die(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_Fragment_SetupFade(EnTp* pthis);
void EnTp_Fragment_Fade(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_Head_SetupTakeOff(EnTp* pthis);
void EnTp_Head_TakeOff(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_Head_SetupWait(EnTp* pthis);
void EnTp_Head_Wait(EnTp* pthis, GlobalContext* globalCtx);
void EnTp_Head_SetupBurrowReturnHome(EnTp* pthis);
void EnTp_Head_BurrowReturnHome(EnTp* pthis, GlobalContext* globalCtx);

static Vec3f bubbleAccel_65 = { 0.0f, -0.5f, 0.0f };

static Color_RGBA8 bubblePrimColor_65 = { 255, 255, 255, 255 };

static Color_RGBA8 bubbleEnvColor_65 = { 150, 150, 150, 0 };


ActorInit En_Tp_InitVars = {
    ACTOR_EN_TP,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_TP,
    sizeof(EnTp),
    (ActorFunc)EnTp_Init,
    (ActorFunc)EnTp_Destroy,
    (ActorFunc)EnTp_Update,
    (ActorFunc)EnTp_Draw,
    (ActorFunc)EnTp_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x03, 0x08 },
            { 0xFFCFFFFF, 0x01, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 0, { { 0, 0, 0 }, 4 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT1,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_DEKUNUT),
    /* Deku stick    */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_INSULATING),
    /* Slingshot     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Explosive     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_INSULATING),
    /* Normal arrow  */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
    /* Hookshot      */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Kokiri sword  */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_SHOCKING),
    /* Master sword  */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
    /* Giant's Knife */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
    /* Fire arrow    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Ice arrow     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Light arrow   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Ice magic     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Light magic   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Shield        */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_SHOCKING),
    /* Giant spin    */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
    /* Master spin   */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
    /* Kokiri jump   */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
    /* Giant jump    */ DMG_ENTRY(8, TAILPASARAN_DMGEFF_SHOCKING),
    /* Master jump   */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
    /* Unknown 1     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
    /* Unknown 2     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 10, ICHAIN_STOP),
};

void EnTp_SetupAction(EnTp* pthis, EnTpActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnTp_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnTp* pthis = (EnTp*)thisx;
    EnTp* now;
    EnTp* next;
    s32 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.targetMode = 3;
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.14f);
    pthis->unk_150 = 0;
    pthis->actor.colChkInfo.health = 1;
    now = pthis;
    pthis->alpha = 255;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderItems);

    if (pthis->actor.params <= TAILPASARAN_HEAD) {
        pthis->actor.naviEnemyId = 0x06;
        pthis->timer = 0;
        pthis->collider.base.acFlags |= AC_HARD;
        pthis->collider.elements->dim.modelSphere.radius = pthis->collider.elements->dim.worldSphere.radius = 8;
        EnTp_Head_SetupWait(pthis);
        pthis->actor.focus.pos = pthis->actor.world.pos;
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4;
        Actor_SetScale(&pthis->actor, 1.5f);

        for (i = 0; i <= 6; i++) {
            next = (EnTp*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_TP, pthis->actor.world.pos.x,
                                      pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0 * i);

            if (0 * i) {} // Very fake, but needed to get the s registers right
            if (next != NULL) {
                now->actor.child = &next->actor;
                next->actor.parent = &now->actor;
                next->kiraSpawnTimer = i + 1;
                next->head = pthis;
                Actor_SetScale(&next->actor, 0.3f);

                if (i == 2) {
                    next->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4;
                    next->unk_150 = 1; // Why?
                }

                next->timer = next->unk_15C = i * -5;
                next->horizontalVariation = 6.0f - (i * 0.75f);
                now = next;
                if (0 * i) {}
            }
        }
    } else if (pthis->actor.params == TAILPASARAN_TAIL) {
        EnTp_Tail_SetupFollowHead(pthis);
    } else {
        EnTp_Fragment_SetupFade(pthis);
    }
}

void EnTp_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTp* pthis = (EnTp*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnTp_Tail_SetupFollowHead(EnTp* pthis) {
    pthis->actionIndex = TAILPASARAN_ACTION_TAIL_FOLLOWHEAD;
    EnTp_SetupAction(pthis, EnTp_Tail_FollowHead);
}

void EnTp_Tail_FollowHead(EnTp* pthis, GlobalContext* globalCtx) {
    s16 angle;
    s16 phase;

    if (pthis->actor.params == TAILPASARAN_TAIL_DYING) {
        pthis->actionIndex = TAILPASARAN_ACTION_DIE;

        if (pthis->actor.parent == NULL) {
            EnTp_SetupDie(pthis);
        }
    } else {
        if (pthis->unk_150 != 0) {
            pthis->actor.flags |= ACTOR_FLAG_0;
        }

        if (pthis->head->unk_150 != 0) {
            pthis->actor.speedXZ = pthis->red = pthis->actor.velocity.y = pthis->heightPhase = 0.0f;
            if (pthis->actor.world.pos.y < pthis->head->actor.home.pos.y) {
                pthis->actor.flags &= ~ACTOR_FLAG_0;
            }

            pthis->actor.world.pos = pthis->actor.parent->prevPos;
        } else {
            Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.parent->world.pos.y - 4.0f, 1.0f, 1.0f, 0.0f);
            angle = pthis->head->actor.shape.rot.y + 0x4000;
            phase = 2000 * (pthis->head->unk_15C + pthis->timer);
            pthis->actor.world.pos.x =
                pthis->actor.home.pos.x + Math_SinS(phase) * (Math_SinS(angle) * pthis->horizontalVariation);
            pthis->actor.world.pos.z =
                pthis->actor.home.pos.z + Math_SinS(phase) * (Math_CosS(angle) * pthis->horizontalVariation);
        }
    }
}

void EnTp_Head_SetupApproachPlayer(EnTp* pthis) {
    pthis->actionIndex = TAILPASARAN_ACTION_HEAD_APPROACHPLAYER;
    pthis->timer = 200;
    EnTp_SetupAction(pthis, EnTp_Head_ApproachPlayer);
}

void EnTp_Head_ApproachPlayer(EnTp* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.world.pos.y, player->actor.world.pos.y + 30.0f, 1.0f, 0.5f, 0.0f);
    Audio_PlaySoundGeneral(NA_SE_EN_TAIL_FLY - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &gReverbAdd2);

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        if (&player->actor == pthis->collider.base.at) {
            pthis->timer = 1;
        }
    }

    if (pthis->red < 255) {
        pthis->red += 15;
    }

    if (Math_CosF(pthis->heightPhase) == 0.0f) {
        pthis->extraHeightVariation = 2.0f * Rand_ZeroOne();
    }

    pthis->actor.world.pos.y += Math_CosF(pthis->heightPhase) * (2.0f + pthis->extraHeightVariation);
    pthis->heightPhase += 0.2f;
    Math_SmoothStepToF(&pthis->actor.speedXZ, 2.5f, 0.1f, 0.2f, 0.0f);
    pthis->timer--;

    if (pthis->timer != 0) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 750, 0);
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    } else {
        EnTp_Head_SetupBurrowReturnHome(pthis);
    }
}

void EnTp_SetupDie(EnTp* pthis) {
    Actor* now;

    pthis->timer = 2;

    if (pthis->actor.params <= TAILPASARAN_HEAD) {
        for (now = pthis->actor.child; now != NULL; now = now->child) {
            now->params = TAILPASARAN_TAIL_DYING;
            now->colChkInfo.health = 0;
        }

        pthis->timer = 13;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TAIL_DEAD);
    }
    pthis->actionIndex = TAILPASARAN_ACTION_DIE;
    EnTp_SetupAction(pthis, EnTp_Die);
}

/**
 * Spawns effects and smaller tail segment-like fragments
 */
void EnTp_Die(EnTp* pthis, GlobalContext* globalCtx) {
    EnTp* now;
    s16 i;
    s32 pad;
    Vec3f effectVelAccel = { 0.0f, 0.5f, 0.0f };
    Vec3f effectPos = { 0.0f, 0.0f, 0.0f };

    pthis->timer--;

    if (pthis->timer <= 0) {
        if (pthis->actor.params == TAILPASARAN_HEAD_DYING) {
            effectPos.x = ((Rand_ZeroOne() - 0.5f) * 15.0f) + pthis->actor.world.pos.x;
            effectPos.z = ((Rand_ZeroOne() - 0.5f) * 15.0f) + pthis->actor.world.pos.z;
            effectPos.y = ((Rand_ZeroOne() - 0.5f) * 5.0f) + pthis->actor.world.pos.y;
            EffectSsDeadDb_Spawn(globalCtx, &effectPos, &effectVelAccel, &effectVelAccel, 100, 0, 255, 255, 255, 255, 0,
                                 0, 255, 1, 9, 1);

            effectPos.x = ((Rand_ZeroOne() - 0.5f) * 15.0f) + pthis->actor.world.pos.x;
            effectPos.z = ((Rand_ZeroOne() - 0.5f) * 15.0f) + pthis->actor.world.pos.z;
            effectPos.y = ((Rand_ZeroOne() - 0.5f) * 5.0f) + pthis->actor.world.pos.y;
            EffectSsDeadDb_Spawn(globalCtx, &effectPos, &effectVelAccel, &effectVelAccel, 100, 0, 255, 255, 255, 255, 0,
                                 0, 255, 1, 9, 1);
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x50);
        } else {
            for (i = 0; i < 1; i++) {
                now =
                    (EnTp*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_TP, pthis->actor.world.pos.x,
                                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, TAILPASARAN_FRAGMENT);

                if (now != NULL) {
                    Actor_SetScale(&now->actor, pthis->actor.scale.z * 0.5f);
                    now->red = pthis->red;
                }
            }
        }

        if (pthis->actor.child != NULL) {
            pthis->actor.child->parent = NULL;
            pthis->actor.child->params = TAILPASARAN_TAIL_DYING;
            pthis->actor.child->colChkInfo.health = 0;
        }

        pthis->unk_150 = 2;
        Actor_Kill(&pthis->actor);
    }
}

void EnTp_Fragment_SetupFade(EnTp* pthis) {
    pthis->actionIndex = TAILPASARAN_ACTION_FRAGMENT_FADE;
    pthis->actor.world.pos.x += ((Rand_ZeroOne() - 0.5f) * 5.0f);
    pthis->actor.world.pos.y += ((Rand_ZeroOne() - 0.5f) * 5.0f);
    pthis->actor.world.pos.z += ((Rand_ZeroOne() - 0.5f) * 5.0f);
    pthis->actor.velocity.x = (Rand_ZeroOne() - 0.5f) * 1.5f;
    pthis->actor.velocity.y = (Rand_ZeroOne() - 0.5f) * 1.5f;
    pthis->actor.velocity.z = (Rand_ZeroOne() - 0.5f) * 1.5f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnTp_SetupAction(pthis, EnTp_Fragment_Fade);
}

void EnTp_Fragment_Fade(EnTp* pthis, GlobalContext* globalCtx) {
    func_8002D7EC(&pthis->actor);
    pthis->alpha -= 20;

    if (pthis->alpha < 20) {
        pthis->alpha = 0;
        Actor_Kill(&pthis->actor);
    }
}

void EnTp_Head_SetupTakeOff(EnTp* pthis) {
    pthis->timer = (Rand_ZeroOne() * 15.0f) + 40.0f;
    pthis->actionIndex = TAILPASARAN_ACTION_HEAD_TAKEOFF;
    EnTp_SetupAction(pthis, EnTp_Head_TakeOff);
}

/**
 * Flies up and loops around until it makes for Player
 */
void EnTp_Head_TakeOff(EnTp* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 2.5f, 0.1f, 0.2f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.world.pos.y, player->actor.world.pos.y + 85.0f + pthis->horizontalVariation, 1.0f,
                       pthis->actor.speedXZ * 0.25f, 0.0f);
    Audio_PlaySoundGeneral(NA_SE_EN_TAIL_FLY - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &gReverbAdd2);

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        if (&player->actor == pthis->collider.base.at) {
            pthis->unk_15C = 1;
        }
    }

    if (pthis->red != 0) {
        pthis->red -= 15;
    }

    if (Math_CosF(pthis->heightPhase) == 0.0f) {
        pthis->extraHeightVariation = Rand_ZeroOne() * 4.0f;
    }

    pthis->actor.world.pos.y +=
        Math_CosF(pthis->heightPhase) * ((pthis->actor.speedXZ * 0.25f) + pthis->extraHeightVariation);
    pthis->actor.world.rot.y += pthis->unk_164;
    pthis->heightPhase += 0.2f;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos), 1, 750,
                       0);

    if (pthis->timer == 0) {
        EnTp_Head_SetupApproachPlayer(pthis);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnTp_Head_SetupWait(EnTp* pthis) {
    pthis->actionIndex = TAILPASARAN_ACTION_HEAD_WAIT;
    pthis->unk_150 = 0;
    pthis->actor.shape.rot.x = -0x4000;
    pthis->timer = 60;
    pthis->unk_15C = 0;
    pthis->actor.speedXZ = 0.0f;
    EnTp_SetupAction(pthis, EnTp_Head_Wait);
}

/**
 * Awaken and rise from the ground when Player is closer than 200
 */
void EnTp_Head_Wait(EnTp* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 yaw;

    pthis->unk_15C--;

    if (pthis->actor.xzDistToPlayer < 200.0f) {
        if (pthis->collider.base.atFlags & AT_HIT) {
            pthis->collider.base.atFlags &= ~AT_HIT;
            if (&player->actor == pthis->collider.base.at) {
                pthis->timer = 0;
            }
        }

        if (pthis->timer != 0) {
            pthis->timer--;

            Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0, 1, 500, 0);
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 1500, 0);

            yaw = Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos) + 0x4000;
            Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y + 30.0f, 0.3f, 1.0f, 0.3f);
            pthis->actor.world.pos.x = pthis->actor.home.pos.x +
                                      (Math_SinS(2000 * pthis->unk_15C) * (Math_SinS(yaw) * pthis->horizontalVariation));
            pthis->actor.world.pos.z = pthis->actor.home.pos.z +
                                      (Math_SinS(2000 * pthis->unk_15C) * (Math_CosS(yaw) * pthis->horizontalVariation));
        } else {
            pthis->actor.shape.rot.x = 0;
            pthis->unk_150 = 1;
            EnTp_Head_SetupTakeOff(pthis);
        }
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, -0x4000, 1, 500, 0);

        if (Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.3f, 1.5f, 0.3f) == 0.0f) {
            pthis->timer = 60;
        } else {
            yaw = Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos);
            pthis->actor.world.pos.x =
                pthis->actor.home.pos.x + (Math_SinS(2000 * pthis->unk_15C) * (Math_SinS(yaw) * 6.0f));
            pthis->actor.world.pos.z =
                pthis->actor.home.pos.z + (Math_SinS(2000 * pthis->unk_15C) * (Math_CosS(yaw) * 6.0f));
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->actor.world.pos.y != pthis->actor.home.pos.y) {
        Audio_PlaySoundGeneral(NA_SE_EN_TAIL_FLY - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    }
}

void EnTp_Head_SetupBurrowReturnHome(EnTp* pthis) {
    pthis->actionIndex = TAILPASARAN_ACTION_HEAD_BURROWRETURNHOME;
    pthis->timer = 0;
    EnTp_SetupAction(pthis, EnTp_Head_BurrowReturnHome);
}

void EnTp_Head_BurrowReturnHome(EnTp* pthis, GlobalContext* globalCtx) {
    Vec3f bubbleVelocity;
    Vec3f bubblePos;
    s32 closeToFloor;
    EnTp* now;
    s16 temp_v0; // Required to match, usage can maybe be improved

    closeToFloor = false;
    temp_v0 = pthis->timer;
    pthis->unk_15C--;

    if ((temp_v0 != 0) || ((pthis->actor.home.pos.y - pthis->actor.world.pos.y) > 60.0f)) {
        pthis->timer = temp_v0 - 1;
        temp_v0 = pthis->timer;

        if (temp_v0 == 0) {
            EnTp_Head_SetupWait(pthis);

            for (now = (EnTp*)pthis->actor.child; now != NULL; now = (EnTp*)now->actor.child) {
                now->unk_15C = now->timer;
            }
        } else {
            if (pthis->actor.shape.rot.x != -0x4000) {
                pthis->timer = 80;
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.speedXZ = 0.0f;
                pthis->actor.world.pos = pthis->actor.home.pos;
                pthis->actor.shape.rot.x = -0x4000;

                for (now = (EnTp*)pthis->actor.child; now != NULL; now = (EnTp*)now->actor.child) {
                    now->actor.velocity.y = 0.0f;
                    now->actor.speedXZ = 0.0f;
                    now->actor.world.pos = pthis->actor.home.pos;
                    now->actor.world.pos.y = pthis->actor.home.pos.y - 80.0f;
                }
            }

            pthis->actor.world.pos.y = pthis->actor.home.pos.y - pthis->timer;
        }
    } else {
        if (pthis->actor.shape.rot.x != 0x4000) {
            pthis->actor.shape.rot.x -= 0x400;
        }

        if (pthis->red != 0) {
            pthis->red -= 15;
        }

        pthis->actor.speedXZ = 2.0f * Math_CosS(pthis->actor.shape.rot.x);
        pthis->actor.velocity.y = Math_SinS(pthis->actor.shape.rot.x) * -2.0f;

        if ((pthis->actor.world.pos.y - pthis->actor.floorHeight) < 20.0f) {
            closeToFloor = true;
        }

        if (pthis->actor.world.pos.y != pthis->actor.home.pos.y) {
            Audio_PlaySoundGeneral(NA_SE_EN_TAIL_FLY - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &gReverbAdd2);
        }

        if (closeToFloor && ((globalCtx->gameplayFrames & 1) != 0)) {
            bubblePos = pthis->actor.world.pos;
            bubblePos.y = pthis->actor.floorHeight;

            bubbleVelocity.x = Rand_CenteredFloat(5.0f);
            bubbleVelocity.y = (Rand_ZeroOne() * 3.5f) + 1.5f;
            bubbleVelocity.z = Rand_CenteredFloat(5.0f);

            EffectSsDtBubble_SpawnCustomColor(globalCtx, &bubblePos, &bubbleVelocity, &bubbleAccel_65, &bubblePrimColor_65,
                                              &bubbleEnvColor_65, Rand_S16Offset(100, 50), 20, 0);
        }
    }
}

void EnTp_UpdateDamage(EnTp* pthis, GlobalContext* globalCtx) {
    s32 phi_s2;
    s32 phi_s4;
    EnTp* head; // Can eliminate pthis and just use now, but they're used differently
    EnTp* now;

    if ((pthis->collider.base.acFlags & AC_HIT) && (pthis->actionIndex >= TAILPASARAN_ACTION_TAIL_FOLLOWHEAD)) {
        phi_s4 = phi_s2 = 0;

        if (pthis->actor.params <= TAILPASARAN_HEAD) {
            phi_s2 = 1;
        }

        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlagJntSph(&pthis->actor, &pthis->collider, 1);
        pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;

        if (pthis->actor.colChkInfo.damageEffect != TAILPASARAN_DMGEFF_NONE) {
            if (pthis->actor.colChkInfo.damageEffect == TAILPASARAN_DMGEFF_DEKUNUT) {
                phi_s4 = 1;
            }

            // Head is invincible
            if (phi_s2 == 0) {
                Actor_ApplyDamage(&pthis->actor);
            }

            if (pthis->actor.colChkInfo.health == 0) {
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                head = pthis->head;

                if (head->actor.params <= TAILPASARAN_HEAD) {
                    EnTp_SetupDie(head);
                    head->damageEffect = pthis->actor.colChkInfo.damageEffect;
                    head->actor.params = TAILPASARAN_HEAD_DYING;
                }
            } else {
                if (phi_s4 != 0) {
                    pthis->actor.freezeTimer = 80;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
                    if (phi_s2 != 0) {
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0, 0x50);
                    } else {
                        Actor_SetColorFilter(&pthis->actor, 0, 0xFF, 0x2000, 0x50);
                    }
                }

                for (now = (EnTp*)pthis->actor.parent; now != NULL; now = (EnTp*)now->actor.parent) {
                    now->collider.base.acFlags &= ~AC_HIT;

                    if (phi_s4 != 0) {
                        now->actor.freezeTimer = 80;
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);

                        if (phi_s2 != 0) {
                            Actor_SetColorFilter(&now->actor, 0, 0xFF, 0, 0x50);
                        } else {
                            Actor_SetColorFilter(&now->actor, 0, 0xFF, 0x2000, 0x50);
                        }
                    }
                }

                for (now = (EnTp*)pthis->actor.child; now != NULL; now = (EnTp*)now->actor.child) {
                    now->collider.base.acFlags &= ~AC_HIT;
                    if (phi_s4 != 0) {
                        now->actor.freezeTimer = 80;

                        if (phi_s2 != 0) {
                            Actor_SetColorFilter(&now->actor, 0, 0xFF, 0, 0x50);
                        } else {
                            Actor_SetColorFilter(&now->actor, 0, 0xFF, 0x2000, 0x50);
                        }
                    }
                }
            }
        }
    }
}

void EnTp_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnTp* pthis = (EnTp*)thisx;
    Vec3f kiraVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f kiraAccel = { 0.0f, -0.6f, 0.0f };
    Vec3f kiraPos;
    Color_RGBA8 kiraPrimColor = { 0, 0, 255, 255 };
    Color_RGBA8 kiraEnvColor = { 0, 0, 0, 0 };
    Player* player = GET_PLAYER(globalCtx);
    s16 yawToWall;

    if (player->stateFlags1 & 0x4000000) { // Shielding
        pthis->damageEffect = TAILPASARAN_DMGEFF_NONE;
    }

    if (pthis->actor.colChkInfo.health != 0) {
        EnTp_UpdateDamage(pthis, globalCtx);
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.params <= TAILPASARAN_HEAD) {
        Actor_MoveForward(&pthis->actor);

        if (pthis->actionIndex != TAILPASARAN_ACTION_HEAD_BURROWRETURNHOME) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 15.0f, 10.0f, 5);
        }

        // Turn away from wall
        if ((pthis->actor.speedXZ != 0.0f) && (pthis->actor.bgCheckFlags & 8)) {
            yawToWall = pthis->actor.wallYaw - pthis->actor.world.rot.y;

            if (ABS(yawToWall) > 0x4000) {
                if (yawToWall >= 0) {
                    pthis->actor.world.rot.y -= 500;
                } else {
                    pthis->actor.world.rot.y += 500;
                }

                pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
            }
        }

        pthis->actor.shape.rot.z += 0x800;

        if (pthis->actor.shape.rot.z == 0) {
            Audio_PlaySoundGeneral(NA_SE_EN_TAIL_CRY, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &gReverbAdd2);
        }

        if (pthis->actionIndex >= TAILPASARAN_ACTION_TAIL_FOLLOWHEAD) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }

    if (pthis->actor.params != TAILPASARAN_TAIL_DYING) {
        pthis->kiraSpawnTimer--;
        pthis->kiraSpawnTimer &= 7;
    }

    pthis->actor.focus.pos = pthis->actor.world.pos;

    if (pthis->damageEffect == TAILPASARAN_DMGEFF_SHOCKING) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if ((pthis->kiraSpawnTimer & 7) == 0) {
        kiraPrimColor.r = pthis->red;
        kiraAccel.x = -pthis->actor.velocity.x * 0.25f;
        kiraAccel.y = -pthis->actor.velocity.y * 0.25f;
        kiraAccel.z = -pthis->actor.velocity.z * 0.25f;
        kiraPos.x = ((Rand_ZeroOne() - 0.5f) * 25.0f) + pthis->actor.world.pos.x;
        kiraPos.y = ((Rand_ZeroOne() - 0.5f) * 20.0f) + pthis->actor.world.pos.y;
        kiraPos.z = ((Rand_ZeroOne() - 0.5f) * 25.0f) + pthis->actor.world.pos.z;
        EffectSsKiraKira_SpawnSmall(globalCtx, &kiraPos, &kiraVelocity, &kiraAccel, &kiraPrimColor, &kiraEnvColor);
    }

    if ((pthis->actionIndex >= TAILPASARAN_ACTION_TAIL_FOLLOWHEAD) && (pthis->actor.colChkInfo.health != 0)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnTp_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnTp* pthis = (EnTp*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_tp.c", 1451);

    if (pthis->unk_150 != 2) {
        if ((thisx->params <= TAILPASARAN_HEAD) || (thisx->params == TAILPASARAN_HEAD_DYING)) {
            func_80093D18(globalCtx->state.gfxCtx);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_tp.c", 1459),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gTailpasaranHeadDL);

            Matrix_Translate(0.0f, 0.0f, 8.0f, MTXMODE_APPLY);
        } else {
            func_80093D84(globalCtx->state.gfxCtx);
            func_800D1FD4(&globalCtx->billboardMtxF);

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, pthis->red, 0, 255, pthis->alpha);
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetCombineLERP(POLY_XLU_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT,
                              TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT,
                              TEXEL0, ENVIRONMENT);
            gDPPipeSync(POLY_XLU_DISP++);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gTailpasaranTailSegmentTex));
            gDPPipeSync(POLY_XLU_DISP++);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_tp.c", 1480),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gTailpasaranTailSegmentDL);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_tp.c", 1495);

    if ((thisx->params <= TAILPASARAN_TAIL) || (thisx->params == TAILPASARAN_TAIL_DYING)) {
        Collider_UpdateSpheres(0, &pthis->collider);
    }
}

void EnTp_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    bubbleAccel_65 = { 0.0f, -0.5f, 0.0f };

    bubblePrimColor_65 = { 255, 255, 255, 255 };

    bubbleEnvColor_65 = { 150, 150, 150, 0 };

    En_Tp_InitVars = {
        ACTOR_EN_TP,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_TP,
        sizeof(EnTp),
        (ActorFunc)EnTp_Init,
        (ActorFunc)EnTp_Destroy,
        (ActorFunc)EnTp_Update,
        (ActorFunc)EnTp_Draw,
        (ActorFunc)EnTp_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_HIT1,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_DEKUNUT),
        /* Deku stick    */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_INSULATING),
        /* Slingshot     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Explosive     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_INSULATING),
        /* Normal arrow  */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
        /* Hookshot      */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Kokiri sword  */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_SHOCKING),
        /* Master sword  */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
        /* Giant's Knife */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
        /* Fire arrow    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Ice arrow     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Light arrow   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Unk arrow 1   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Ice magic     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Light magic   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Shield        */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, TAILPASARAN_DMGEFF_SHOCKING),
        /* Giant spin    */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
        /* Master spin   */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
        /* Kokiri jump   */ DMG_ENTRY(2, TAILPASARAN_DMGEFF_SHOCKING),
        /* Giant jump    */ DMG_ENTRY(8, TAILPASARAN_DMGEFF_SHOCKING),
        /* Master jump   */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
        /* Unknown 1     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, TAILPASARAN_DMGEFF_SHOCKING),
        /* Unknown 2     */ DMG_ENTRY(0, TAILPASARAN_DMGEFF_NONE),
    };

}

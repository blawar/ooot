#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BB_Z_EN_BB_C
#include "actor_common.h"
/*
 * File: z_en_bb.c
 * Overlay: ovl_En_Bb
 * Description: Bubble (Flying Skull Enemy)
 */

#include "z_en_bb.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_Bb/object_Bb.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_24)

#define vBombHopPhase actionVar1
#define vTrailIdx actionVar1
#define vTrailMaxAlpha actionVar2
#define vMoveAngleY actionVar2
#define vFlameTimer actionVar2


// Main functions

void EnBb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBb_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBb_Update(Actor* pthis, GlobalContext* globalCtx);
void EnBb_Draw(Actor* pthis, GlobalContext* globalCtx);

// Helper functions

void EnBb_FaceWaypoint(EnBb* pthis);
void EnBb_SetWaypoint(EnBb* pthis, GlobalContext* globalCtx);

// Action functions

void EnBb_SetupFlameTrail(EnBb* pthis);
void EnBb_FlameTrail(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_SetupDeath(EnBb* pthis, GlobalContext* globalCtx);
void EnBb_Death(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_Damage(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_SetupBlue(EnBb* pthis);
void EnBb_Blue(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_SetupDown(EnBb* pthis);
void EnBb_Down(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_SetupRed(GlobalContext* globalCtx, EnBb* pthis);
void EnBb_Red(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_SetupWhite(GlobalContext* globalCtx, EnBb* pthis);
void EnBb_White(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_InitGreen(EnBb* pthis, GlobalContext* globalCtx);
void EnBb_Green(EnBb* pthis, GlobalContext* globalCtx);

void EnBb_Stunned(EnBb* pthis, GlobalContext* globalCtx);

static DamageTable sDamageTableBlueGreen = {
    /* Deku nut      */ DMG_ENTRY(0, 0xF),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0xA),
    /* Boomerang     */ DMG_ENTRY(0, 0xF),
    /* Normal arrow  */ DMG_ENTRY(2, 0xE),
    /* Hammer swing  */ DMG_ENTRY(2, 0xA),
    /* Hookshot      */ DMG_ENTRY(0, 0xF),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0xE),
    /* Ice arrow     */ DMG_ENTRY(4, 0xC),
    /* Light arrow   */ DMG_ENTRY(4, 0xB),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x6),
    /* Ice magic     */ DMG_ENTRY(3, 0x9),
    /* Light magic   */ DMG_ENTRY(3, 0x8),
    /* Shield        */ DMG_ENTRY(0, 0xA),
    /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x6),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xA),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static DamageTable sDamageTableRed = {
    /* Deku nut      */ DMG_ENTRY(0, 0xD),
    /* Deku stick    */ DMG_ENTRY(0, 0xD),
    /* Slingshot     */ DMG_ENTRY(0, 0xD),
    /* Explosive     */ DMG_ENTRY(2, 0xA),
    /* Boomerang     */ DMG_ENTRY(0, 0xD),
    /* Normal arrow  */ DMG_ENTRY(2, 0xE),
    /* Hammer swing  */ DMG_ENTRY(2, 0xA),
    /* Hookshot      */ DMG_ENTRY(0, 0xD),
    /* Kokiri sword  */ DMG_ENTRY(0, 0xD),
    /* Master sword  */ DMG_ENTRY(2, 0xE),
    /* Giant's Knife */ DMG_ENTRY(4, 0xE),
    /* Fire arrow    */ DMG_ENTRY(2, 0xE),
    /* Ice arrow     */ DMG_ENTRY(4, 0x9),
    /* Light arrow   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
    /* Fire magic    */ DMG_ENTRY(0, 0x6),
    /* Ice magic     */ DMG_ENTRY(3, 0x9),
    /* Light magic   */ DMG_ENTRY(0, 0x6),
    /* Shield        */ DMG_ENTRY(0, 0xA),
    /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0xE),
    /* Master spin   */ DMG_ENTRY(2, 0xE),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0xE),
    /* Master jump   */ DMG_ENTRY(4, 0xE),
    /* Unknown 1     */ DMG_ENTRY(0, 0x6),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xA),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static DamageTable sDamageTableWhite = {
    /* Deku nut      */ DMG_ENTRY(0, 0xF),
    /* Deku stick    */ DMG_ENTRY(2, 0xE),
    /* Slingshot     */ DMG_ENTRY(1, 0xE),
    /* Explosive     */ DMG_ENTRY(2, 0xA),
    /* Boomerang     */ DMG_ENTRY(0, 0xF),
    /* Normal arrow  */ DMG_ENTRY(2, 0xE),
    /* Hammer swing  */ DMG_ENTRY(2, 0xA),
    /* Hookshot      */ DMG_ENTRY(0, 0xF),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
    /* Master sword  */ DMG_ENTRY(2, 0xE),
    /* Giant's Knife */ DMG_ENTRY(4, 0xE),
    /* Fire arrow    */ DMG_ENTRY(4, 0x5),
    /* Ice arrow     */ DMG_ENTRY(2, 0xE),
    /* Light arrow   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
    /* Fire magic    */ DMG_ENTRY(4, 0x7),
    /* Ice magic     */ DMG_ENTRY(0, 0x6),
    /* Light magic   */ DMG_ENTRY(0, 0x6),
    /* Shield        */ DMG_ENTRY(0, 0xA),
    /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
    /* Kokiri spin   */ DMG_ENTRY(1, 0xE),
    /* Giant spin    */ DMG_ENTRY(4, 0xE),
    /* Master spin   */ DMG_ENTRY(2, 0xE),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xE),
    /* Giant jump    */ DMG_ENTRY(8, 0xE),
    /* Master jump   */ DMG_ENTRY(4, 0xE),
    /* Unknown 1     */ DMG_ENTRY(0, 0x6),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0xA),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

ActorInit En_Bb_InitVars = {
    ACTOR_EN_BB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BB,
    sizeof(EnBb),
    (ActorFunc)EnBb_Init,
    (ActorFunc)EnBb_Destroy,
    (ActorFunc)EnBb_Update,
    (ActorFunc)EnBb_Draw,
    (ActorFunc)EnBb_Reset,
};

static ColliderJntSphElementInit sJntSphElementInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, -120, 0 }, 4 }, 300 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 10, ICHAIN_STOP),
};

void EnBb_SetupAction(EnBb* pthis, EnBbActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

Actor* EnBb_FindExplosive(GlobalContext* globalCtx, EnBb* pthis, f32 range) {
    Actor* explosive = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;
    f32 dist;

    while (explosive != NULL) {
        if (explosive->params != 0) {
            explosive = explosive->next;
            continue;
        }
        dist = Actor_WorldDistXYZToActor(&pthis->actor, explosive);
        if ((explosive->params == 0) && (dist <= range)) {
            return explosive;
        }
        explosive = explosive->next;
    }
    return NULL;
}

void EnBb_SpawnFlameTrail(GlobalContext* globalCtx, EnBb* pthis, s16 startAtZero) {
    EnBb* now = pthis;
    EnBb* next;
    s32 i;

    for (i = 0; i < 5; i++) {
        next = (EnBb*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BB, pthis->actor.world.pos.x,
                                  pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
        if (next != NULL) {
            now->actor.child = &next->actor;
            next->actor.parent = &now->actor;
            next->targetActor = &pthis->actor;
            next->vTrailIdx = i + 1;
            next->actor.scale.x = 1.0f;
            next->vTrailMaxAlpha = next->flamePrimAlpha = 255 - (i * 40);
            next->flameScaleY = next->actor.scale.y = 0.8f - (i * 0.075f);
            next->flameScaleX = next->actor.scale.z = 1.0f - (i * 0.094f);
            if (startAtZero) {
                next->flamePrimAlpha = 0;
                next->flameScaleY = next->flameScaleX = 0.0f;
            }
            next->flameScrollMod = i + 1;
            next->timer = 2 * i + 2;
            next->flameEnvColor.r = 255;
            now = next;
        }
    }
}

void EnBb_KillFlameTrail(EnBb* pthis) {
    Actor* actor = &pthis->actor;

    while (actor->child != NULL) {
        Actor* nextActor = actor->child;

        if (nextActor->id == ACTOR_EN_BB) {
            nextActor->parent = NULL;
            actor->child = NULL;
            nextActor->params = ENBB_KILL_TRAIL;
        }
        actor = nextActor;
    }
    pthis->actor.child = NULL;
}

void EnBb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EffectBlureInit1 blureInit;
    s32 pad;
    EnBb* pthis = (EnBb*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &object_Bb_Skel_001A30, &object_Bb_Anim_000444, pthis->jointTable,
                   pthis->morphTable, 16);
    pthis->unk_254 = 0;
    thisx->colChkInfo.health = 4;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, thisx, &sJntSphInit, pthis->elements);

    pthis->actionState = thisx->params >> 8;

    if (thisx->params & 0x80) {
        thisx->params |= 0xFF00;
    }
    if (thisx->params <= ENBB_BLUE) {
        ActorShape_Init(&thisx->shape, 200.0f, ActorShadow_DrawCircle, 35.0f);
    }
    if (thisx->params & 0xFF00) {
        pthis->timer = 0;
        pthis->flameScaleY = 80.0f;
        pthis->flameScaleX = 100.0f;
        pthis->collider.elements[0].info.toucherFlags = TOUCH_ON | TOUCH_SFX_HARD;
        pthis->collider.elements[0].info.toucher.dmgFlags = 0xFFCFFFFF;
        pthis->collider.elements[0].info.toucher.damage = 8;
        pthis->bobSize = pthis->actionState * 20.0f;
        pthis->flamePrimAlpha = 255;
        pthis->moveMode = BBMOVE_NORMAL;
        Actor_SetScale(thisx, 0.01f);
        switch (thisx->params) {
            case ENBB_BLUE:
                thisx->naviEnemyId = 0x1C;
                thisx->colChkInfo.damageTable = &sDamageTableBlueGreen;
                pthis->flamePrimBlue = pthis->flameEnvColor.b = 255;
                thisx->world.pos.y += 50.0f;
                EnBb_SetupBlue(pthis);
                thisx->flags |= ACTOR_FLAG_14;
                break;
            case ENBB_RED:
                thisx->naviEnemyId = 0x24;
                thisx->colChkInfo.damageTable = &sDamageTableRed;
                pthis->flameEnvColor.r = 255;
                pthis->collider.elements[0].info.toucher.effect = 1;
                EnBb_SetupRed(globalCtx, pthis);
                break;
            case ENBB_WHITE:
                thisx->naviEnemyId = 0x1D;
                thisx->colChkInfo.damageTable = &sDamageTableWhite;
                pthis->path = pthis->actionState;
                blureInit.p1StartColor[0] = blureInit.p1StartColor[1] = blureInit.p1StartColor[2] =
                    blureInit.p1StartColor[3] = blureInit.p2StartColor[0] = blureInit.p2StartColor[1] =
                        blureInit.p2StartColor[2] = blureInit.p2StartColor[3] = blureInit.p1EndColor[0] =
                            blureInit.p1EndColor[1] = blureInit.p1EndColor[2] = blureInit.p2EndColor[0] =
                                blureInit.p2EndColor[1] = blureInit.p2EndColor[2] = 255;

                blureInit.p1EndColor[3] = 0;
                blureInit.p2EndColor[3] = 0;
                blureInit.elemDuration = 16;
                blureInit.unkFlag = 0;
                blureInit.calcMode = 2;

                Effect_Add(globalCtx, &pthis->blureIdx, EFFECT_BLURE1, 0, 0, &blureInit);
                EnBb_SetupWhite(globalCtx, pthis);
                EnBb_SetWaypoint(pthis, globalCtx);
                EnBb_FaceWaypoint(pthis);
                thisx->flags |= ACTOR_FLAG_14;
                break;
            case ENBB_GREEN_BIG:
                pthis->path = pthis->actionState >> 4;
                pthis->collider.elements[0].dim.modelSphere.radius = 0x16;
                Actor_SetScale(thisx, 0.03f);
            case ENBB_GREEN:
                thisx->naviEnemyId = 0x1E;
                pthis->bobSize = (pthis->actionState & 0xF) * 20.0f;
                thisx->colChkInfo.damageTable = &sDamageTableBlueGreen;
                pthis->flameEnvColor.g = 255;
                thisx->colChkInfo.health = 1;

                EnBb_InitGreen(pthis, globalCtx);
                break;
        }
        thisx->focus.pos = thisx->world.pos;
    } else {
        EnBb_SetupFlameTrail(pthis);
    }
    pthis->collider.elements[0].dim.worldSphere.radius =
        pthis->collider.elements[0].dim.modelSphere.radius * pthis->collider.elements[0].dim.scale;
}

void EnBb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBb* pthis = (EnBb*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnBb_SetupFlameTrail(EnBb* pthis) {
    pthis->action = BB_FLAME_TRAIL;
    pthis->moveMode = BBMOVE_NOCLIP;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.speedXZ = 0.0f;
    EnBb_SetupAction(pthis, EnBb_FlameTrail);
}

void EnBb_FlameTrail(EnBb* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params == ENBB_KILL_TRAIL) {
        if (pthis->actor.parent == NULL) {
            EnBb_SetupDeath(pthis, globalCtx);
        }
    } else {
        if (pthis->timer == 0) {
            if (((EnBb*)pthis->targetActor)->flameScaleY != 0.0f) {
                Math_SmoothStepToF(&pthis->flameScaleY, pthis->actor.scale.y, 1.0f, pthis->actor.scale.y * 0.1f, 0.0f);
                Math_SmoothStepToF(&pthis->flameScaleX, pthis->actor.scale.z, 1.0f, pthis->actor.scale.z * 0.1f, 0.0f);
                if (pthis->flamePrimAlpha != pthis->vTrailMaxAlpha) {
                    pthis->flamePrimAlpha += 10;
                    if (pthis->vTrailMaxAlpha < pthis->flamePrimAlpha) {
                        pthis->flamePrimAlpha = pthis->vTrailMaxAlpha;
                    }
                }
            } else {
                if (!pthis->flamePrimAlpha) {
                    Actor_Kill(&pthis->actor);
                    return;
                } else if (pthis->flamePrimAlpha <= 20) {
                    pthis->flamePrimAlpha = 0;
                } else {
                    pthis->flamePrimAlpha -= 20;
                }
            }
            pthis->actor.world.pos = pthis->actor.parent->prevPos;
        } else {
            pthis->timer--;
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.parent->world.rot.y;
        }
    }
    if (pthis->actor.parent != NULL) {
        pthis->actor.velocity.y = pthis->actor.parent->velocity.y;
    }
}

void EnBb_SetupDeath(EnBb* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params <= ENBB_BLUE) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.speedXZ = -7.0f;
        pthis->timer = 5;
        pthis->actor.shape.rot.x += 0x4E20;
        EffectSsDeadSound_SpawnStationary(globalCtx, &pthis->actor.projectedPos, NA_SE_EN_BUBLE_DEAD, 1, 1, 0x28);
    }
    pthis->action = BB_KILL;
    EnBb_SetupAction(pthis, EnBb_Death);
}

void EnBb_Death(EnBb* pthis, GlobalContext* globalCtx) {
    s16 enpartType = 3;
    Vec3f sp40 = { 0.0f, 0.5f, 0.0f };
    Vec3f sp34 = { 0.0f, 0.0f, 0.0f };

    if (pthis->actor.params <= ENBB_BLUE) {
        Math_SmoothStepToF(&pthis->flameScaleY, 0.0f, 1.0f, 30.0f, 0.0f);
        Math_SmoothStepToF(&pthis->flameScaleX, 0.0f, 1.0f, 30.0f, 0.0f);
        if (pthis->timer != 0) {
            pthis->timer--;
            pthis->actor.shape.rot.x -= 0x4E20;
            return;
        }

        if (pthis->bodyBreak.val == BODYBREAK_STATUS_FINISHED) {
            BodyBreak_Alloc(&pthis->bodyBreak, 12, globalCtx);
        }

        if ((pthis->dmgEffect == 7) || (pthis->dmgEffect == 5)) {
            enpartType = 11;
        }

        if (!BodyBreak_SpawnParts(&pthis->actor, &pthis->bodyBreak, globalCtx, enpartType)) {
            return;
        }
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xD0);
    } else {
        if (pthis->flamePrimAlpha) {
            if (pthis->flamePrimAlpha <= 20) {
                pthis->flamePrimAlpha = 0;
            } else {
                pthis->flamePrimAlpha -= 20;
            }
            return;
        }
    }
    Actor_Kill(&pthis->actor);
}

void EnBb_SetupDamage(EnBb* pthis) {
    pthis->action = BB_DAMAGE;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_DAMAGE);
    if (pthis->actor.params > ENBB_GREEN) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        if ((pthis->actor.bgCheckFlags & 8) == 0) {
            pthis->actor.speedXZ = -7.0f;
        }
        pthis->actor.shape.yOffset = 1500.0f;
    }
    if (pthis->actor.params == ENBB_RED) {
        EnBb_KillFlameTrail(pthis);
    }
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0xC);
    pthis->timer = 5;
    EnBb_SetupAction(pthis, EnBb_Damage);
}

void EnBb_Damage(EnBb* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    if (pthis->actor.speedXZ == 0.0f) {
        pthis->actor.shape.yOffset = 200.0f;
        EnBb_SetupDown(pthis);
    }
}

void EnBb_SetupBlue(EnBb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
    pthis->actor.speedXZ = (Rand_ZeroOne() * 0.5f) + 0.5f;
    pthis->timer = (Rand_ZeroOne() * 20.0f) + 40.0f;
    pthis->unk_264 = (Rand_ZeroOne() * 30.0f) + 180.0f;
    pthis->targetActor = NULL;
    pthis->action = BB_BLUE;
    EnBb_SetupAction(pthis, EnBb_Blue);
}

void EnBb_Blue(EnBb* pthis, GlobalContext* globalCtx) {
    Actor* explosive;
    s16 moveYawToWall;
    s16 thisYawToWall;
    s16 afterHitAngle;

    Math_SmoothStepToF(&pthis->flameScaleY, 80.0f, 1.0f, 10.0f, 0.0f);
    Math_SmoothStepToF(&pthis->flameScaleX, 100.0f, 1.0f, 10.0f, 0.0f);
    if (pthis->actor.floorHeight > BGCHECK_Y_MIN) {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 50.0f + pthis->flyHeightMod, 1.0f, 0.5f,
                           0.0f);
    }
    SkelAnime_Update(&pthis->skelAnime);
    if (Math_CosF(pthis->bobPhase) == 0.0f) {
        if (pthis->charge) {
            pthis->bobSpeedMod = Rand_ZeroOne() * 2.0f;
        } else {
            pthis->bobSpeedMod = Rand_ZeroOne() * 4.0f;
        }
    }
    pthis->actor.world.pos.y += Math_CosF(pthis->bobPhase) * (1.0f + pthis->bobSpeedMod);
    pthis->bobPhase += 0.2f;
    Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->maxSpeed, 1.0f, 0.5f, 0.0f);

    if (Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) > 300.0f) {
        pthis->vMoveAngleY = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->vMoveAngleY, 1, 0x7D0, 0);
    } else {
        pthis->timer--;
        if (pthis->timer <= 0) {
            pthis->charge ^= true;
            pthis->flyHeightMod = (s16)(Math_CosF(pthis->bobPhase) * 10.0f);
            pthis->actor.speedXZ = 0.0f;
            if (pthis->charge && (pthis->targetActor == NULL)) {
                pthis->vMoveAngleY = pthis->actor.world.rot.y;
                if (pthis->actor.xzDistToPlayer < 200.0f) {
                    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000184);
                    pthis->vMoveAngleY = pthis->actor.yawTowardsPlayer;
                }
                pthis->maxSpeed = (Rand_ZeroOne() * 1.5f) + 6.0f;
                pthis->timer = (Rand_ZeroOne() * 5.0f) + 20.0f;
                pthis->actionState = BBBLUE_NORMAL;
            } else {
                Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
                pthis->maxSpeed = (Rand_ZeroOne() * 1.5f) + 1.0f;
                pthis->timer = (Rand_ZeroOne() * 20.0f) + 40.0f;
                pthis->vMoveAngleY = Math_SinF(pthis->bobPhase) * 65535.0f;
            }
        }
        if ((pthis->actor.xzDistToPlayer < 150.0f) && (pthis->actionState != BBBLUE_NORMAL)) {
            if (!pthis->charge) {
                Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000184);
                pthis->maxSpeed = (Rand_ZeroOne() * 1.5f) + 6.0f;
                pthis->timer = (Rand_ZeroOne() * 5.0f) + 20.0f;
                pthis->vMoveAngleY = pthis->actor.yawTowardsPlayer;
                pthis->actionState = pthis->charge = true; // Sets actionState to BBBLUE_AGGRO
            }
        } else if (pthis->actor.xzDistToPlayer < 200.0f) {
            pthis->vMoveAngleY = pthis->actor.yawTowardsPlayer;
        }
        if (pthis->targetActor == NULL) {
            explosive = EnBb_FindExplosive(globalCtx, pthis, 300.0f);
        } else if (pthis->targetActor->params == 0) {
            explosive = pthis->targetActor;
        } else {
            explosive = NULL;
        }
        if (explosive != NULL) {
            pthis->vMoveAngleY = Actor_WorldYawTowardActor(&pthis->actor, explosive);
            if ((pthis->vBombHopPhase == 0) && (explosive != pthis->targetActor)) {
                pthis->vBombHopPhase = -0x8000;
                pthis->targetActor = explosive;
                pthis->actor.speedXZ *= 0.5f;
            }
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->vMoveAngleY, 1, 0x1388, 0);
            Math_SmoothStepToF(&pthis->actor.world.pos.x, explosive->world.pos.x, 1.0f, 1.5f, 0.0f);
            Math_SmoothStepToF(&pthis->actor.world.pos.y, explosive->world.pos.y + 40.0f, 1.0f, 1.5f, 0.0f);
            Math_SmoothStepToF(&pthis->actor.world.pos.z, explosive->world.pos.z, 1.0f, 1.5f, 0.0f);
        } else {
            pthis->targetActor = NULL;
        }
        if (pthis->vBombHopPhase != 0) {
            pthis->actor.world.pos.y += -Math_CosS(pthis->vBombHopPhase) * 10.0f;
            pthis->vBombHopPhase += 0x1000;
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->vMoveAngleY, 1, 0x7D0, 0);
        }
        thisYawToWall = pthis->actor.wallYaw - pthis->actor.world.rot.y;
        moveYawToWall = pthis->actor.wallYaw - pthis->vMoveAngleY;
        if ((pthis->targetActor == NULL) && (pthis->actor.bgCheckFlags & 8) &&
            (ABS(thisYawToWall) > 0x4000 || ABS(moveYawToWall) > 0x4000)) {
            pthis->vMoveAngleY = pthis->actor.wallYaw + pthis->actor.wallYaw - pthis->actor.world.rot.y - 0x8000;
            Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->vMoveAngleY, 1, 0xBB8, 0);
        }
    }
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->vMoveAngleY, 1, 0x3E8, 0);
    if ((pthis->collider.base.acFlags & AC_HIT) || (pthis->collider.base.atFlags & AT_HIT)) {
        pthis->vMoveAngleY = pthis->actor.yawTowardsPlayer + 0x8000;
        if (pthis->collider.base.acFlags & AC_HIT) {
            afterHitAngle = -0x8000;
        } else {
            afterHitAngle = 0x4000;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_BITE);
            if (globalCtx->gameplayFrames & 1) {
                afterHitAngle = -0x4000;
            }
        }
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + afterHitAngle;
        pthis->collider.base.acFlags &= ~AC_HIT;
        pthis->collider.base.atFlags &= ~AT_HIT;
    }

    if (pthis->maxSpeed >= 6.0f) {
        if ((s32)pthis->skelAnime.curFrame == 0 || (s32)pthis->skelAnime.curFrame == 5) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_MOUTH);
        } else if ((s32)pthis->skelAnime.curFrame == 2 || (s32)pthis->skelAnime.curFrame == 7) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_WING);
        }
    } else {
        if ((s32)pthis->skelAnime.curFrame == 5) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_WING);
        }
    }
    if (((s32)pthis->skelAnime.curFrame == 0) && (Rand_ZeroOne() < 0.1f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_LAUGH);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnBb_SetupDown(EnBb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
    pthis->action = BB_DOWN;
    pthis->timer = 200;
    pthis->actor.colorFilterTimer = 0;
    pthis->actor.bgCheckFlags &= ~1;
    pthis->actor.speedXZ = 3.0f;
    pthis->flameScaleX = 0.0f;
    pthis->flameScaleY = 0.0f;
    pthis->actor.gravity = -2.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_DOWN);
    EnBb_SetupAction(pthis, EnBb_Down);
}

void EnBb_Down(EnBb* pthis, GlobalContext* globalCtx) {
    s16 yawDiff = pthis->actor.world.rot.y - pthis->actor.wallYaw;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.bgCheckFlags & 8) {
        if (ABS(yawDiff) > 0x4000) {
            pthis->actor.world.rot.y = pthis->actor.wallYaw + pthis->actor.wallYaw - pthis->actor.world.rot.y - 0x8000;
        }
        pthis->actor.bgCheckFlags &= ~8;
    }
    if (pthis->actor.bgCheckFlags & 3) {
        if (pthis->actor.params == ENBB_RED) {
            s32 floorType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);

            if ((floorType == 2) || (floorType == 3) || (floorType == 9)) {
                pthis->moveMode = BBMOVE_HIDDEN;
                pthis->timer = 10;
                pthis->actionState++;
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                pthis->action = BB_RED;
                EnBb_SetupAction(pthis, EnBb_Red);
                return;
            }
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        if (pthis->actor.velocity.y < -14.0f) {
            pthis->actor.velocity.y *= -0.7f;
        } else {
            pthis->actor.velocity.y = 10.0f;
        }
        pthis->actor.bgCheckFlags &= ~1;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 7.0f, 2, 2.0f, 0, 0, 0);
        Math_SmoothStepToS(&pthis->actor.world.rot.y, -pthis->actor.yawTowardsPlayer, 1, 0xBB8, 0);
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if ((s32)pthis->skelAnime.curFrame == 5) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_WING);
    }
    if (pthis->timer == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_UP);
        switch (pthis->actor.params) {
            case ENBB_BLUE:
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.gravity = 0.0f;
                EnBb_SetupBlue(pthis);
                break;
            case ENBB_RED:
                if (pthis->actor.velocity.y == 10.0f) {
                    EnBb_SetupRed(globalCtx, pthis);
                    EnBb_SpawnFlameTrail(globalCtx, pthis, true);
                }
                break;
            case ENBB_WHITE:
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.gravity = 0.0f;
                EnBb_SetupWhite(globalCtx, pthis);
                pthis->actor.world.pos.y -= 60.0f;
                break;
        }
    } else {
        pthis->timer--;
    }
}

void EnBb_SetupRed(GlobalContext* globalCtx, EnBb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000184);
    if (pthis->action == BB_DOWN) {
        pthis->actor.speedXZ = 5.0f;
        pthis->actor.gravity = -1.0f;
        pthis->actor.velocity.y = 16.0f;
        pthis->actionState = BBRED_ATTACK;
        pthis->timer = 0;
        pthis->moveMode = BBMOVE_NORMAL;
        pthis->actor.bgCheckFlags &= ~1;
    } else {
        pthis->actor.colChkInfo.health = 4;
        pthis->timer = 0;
        pthis->actionState = BBRED_WAIT;
        pthis->moveMode = BBMOVE_HIDDEN;
        pthis->actor.world.pos.y -= 80.0f;
        pthis->actor.home.pos = pthis->actor.world.pos;
        pthis->actor.velocity.y = pthis->actor.gravity = pthis->actor.speedXZ = 0.0f;
        pthis->actor.bgCheckFlags &= ~1;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }
    pthis->action = BB_RED;
    EnBb_SetupAction(pthis, EnBb_Red);
}

void EnBb_Red(EnBb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 floorType;
    s16 yawDiff;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    switch (pthis->actionState) {
        case BBRED_WAIT:
            if ((Actor_WorldDistXYZToActor(&pthis->actor, &player->actor) <= 250.0f) && (ABS(yawDiff) <= 0x4000) &&
                (pthis->timer == 0)) {
                pthis->actor.speedXZ = 5.0f;
                pthis->actor.gravity = -1.0f;
                pthis->actor.velocity.y = 18.0f;
                pthis->moveMode = BBMOVE_NOCLIP;
                pthis->timer = 7;
                pthis->actor.bgCheckFlags &= ~1;
                pthis->actionState++;
                EnBb_SpawnFlameTrail(globalCtx, pthis, false);
            }
            break;
        case BBRED_ATTACK:
            if (pthis->timer == 0) {
                pthis->moveMode = BBMOVE_NORMAL;
                pthis->actor.flags |= ACTOR_FLAG_0;
            }
            pthis->bobPhase += Rand_ZeroOne();
            Math_SmoothStepToF(&pthis->flameScaleY, 80.0f, 1.0f, 10.0f, 0.0f);
            Math_SmoothStepToF(&pthis->flameScaleX, 100.0f, 1.0f, 10.0f, 0.0f);
            if (pthis->actor.bgCheckFlags & 8) {
                yawDiff = pthis->actor.world.rot.y - pthis->actor.wallYaw;
                if (ABS(yawDiff) > 0x4000) {
                    pthis->actor.world.rot.y =
                        pthis->actor.wallYaw + pthis->actor.wallYaw - pthis->actor.world.rot.y - 0x8000;
                }
                pthis->actor.bgCheckFlags &= ~8;
            }
            if (pthis->actor.bgCheckFlags & 1) {
                floorType = func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);
                if ((floorType == 2) || (floorType == 3) || (floorType == 9)) {
                    pthis->moveMode = BBMOVE_HIDDEN;
                    pthis->timer = 10;
                    pthis->actionState++;
                    pthis->actor.flags &= ~ACTOR_FLAG_0;
                } else {
                    pthis->actor.velocity.y *= -1.06f;
                    if (pthis->actor.velocity.y > 13.0f) {
                        pthis->actor.velocity.y = 13.0f;
                    }
                    pthis->actor.world.rot.y = Math_SinF(pthis->bobPhase) * 65535.0f;
                }
                pthis->actor.bgCheckFlags &= ~1;
            }
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
            if (Actor_GetCollidedExplosive(globalCtx, &pthis->collider.base) != NULL) {
                EnBb_SetupDown(pthis);
            }
            break;
        case BBRED_HIDE:
            if (pthis->timer == 0) {
                pthis->actor.speedXZ = 0.0f;
                pthis->actor.gravity = 0.0f;
                pthis->actor.velocity.y = 0.0f;
                pthis->actionState = BBRED_WAIT;
                pthis->timer = 120;
                pthis->actor.world.pos = pthis->actor.home.pos;
                pthis->actor.shape.rot = pthis->actor.world.rot = pthis->actor.home.rot;
                EnBb_KillFlameTrail(pthis);
            }
            break;
    }
    if (pthis->actionState != BBRED_WAIT) {
        if (((s32)pthis->skelAnime.curFrame == 0) || ((s32)pthis->skelAnime.curFrame == 5)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_MOUTH);
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLEFALL_FIRE - SFX_FLAG);
    }
}

void EnBb_FaceWaypoint(EnBb* pthis) {
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->waypointPos);
}

void EnBb_SetWaypoint(EnBb* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->path];
    Vec3s* point;

    if (pthis->waypoint == (s16)(path->count - 1)) {
        pthis->waypoint = 0;
    } else {
        pthis->waypoint++;
    }
    point = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->waypoint;
    pthis->waypointPos.x = point->x;
    pthis->waypointPos.y = point->y;
    pthis->waypointPos.z = point->z;
}

void EnBb_SetupWhite(GlobalContext* globalCtx, EnBb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.pos.y += 60.0f;
    pthis->flameScaleX = 100.0f;
    pthis->action = BB_WHITE;
    pthis->waypoint = 0;
    pthis->timer = (Rand_ZeroOne() * 30.0f) + 40.0f;
    pthis->maxSpeed = 7.0f;
    EnBb_SetupAction(pthis, EnBb_White);
}

void EnBb_White(EnBb* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.speedXZ == 0.0f) {
        f32 distL1;
        f32 vx;
        f32 vz;
        s16 pitch = Math_Vec3f_Pitch(&pthis->actor.world.pos, &pthis->waypointPos);
        f32 vy = Math_SinS(pitch) * pthis->maxSpeed;
        f32 vxz = Math_CosS(pitch) * pthis->maxSpeed;

        vx = Math_SinS(pthis->actor.shape.rot.y) * vxz;
        vz = Math_CosS(pthis->actor.shape.rot.y) * vxz;
        distL1 = Math_SmoothStepToF(&pthis->actor.world.pos.x, pthis->waypointPos.x, 1.0f, ABS(vx), 0.0f);
        distL1 += Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->waypointPos.y, 1.0f, ABS(vy), 0.0f);
        distL1 += Math_SmoothStepToF(&pthis->actor.world.pos.z, pthis->waypointPos.z, 1.0f, ABS(vz), 0.0f);
        pthis->bobPhase += (0.05f + (Rand_ZeroOne() * 0.01f));
        if (distL1 == 0.0f) {
            pthis->timer--;
            if (pthis->timer == 0) {
                EnBb_SetWaypoint(pthis, globalCtx);
                EnBb_FaceWaypoint(pthis);
                Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000184);
                pthis->timer = Rand_ZeroOne() * 30.0f + 40.0f;
            } else {
                if (pthis->moveMode != BBMOVE_NORMAL) {
                    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
                }
                pthis->actor.world.rot.y += 0x1F40;
            }
            pthis->moveMode = BBMOVE_NORMAL;
            pthis->maxSpeed = 0.0f;
        } else {
            pthis->moveMode = BBMOVE_NOCLIP;
            pthis->maxSpeed = 10.0f;
        }
        if (pthis->collider.base.atFlags & AT_HIT) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_BITE);
            pthis->collider.base.atFlags &= ~AT_HIT;
        }
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    } else if (Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f) == 0.0f) {
        EnBb_FaceWaypoint(pthis);
    }
    SkelAnime_Update(&pthis->skelAnime);
    if (((s32)pthis->skelAnime.curFrame == 0) && (Rand_ZeroOne() <= 0.1f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_LAUGH);
    }

    if ((pthis->maxSpeed != 0.0f) && (((s32)pthis->skelAnime.curFrame == 0) || ((s32)pthis->skelAnime.curFrame == 5))) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_MOUTH);
    } else if (((s32)pthis->skelAnime.curFrame == 2) || ((s32)pthis->skelAnime.curFrame == 7)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_WING);
    }
}

void EnBb_InitGreen(EnBb* pthis, GlobalContext* globalCtx) {
    Vec3f bobOffset = { 0.0f, 0.0f, 0.0f };

    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
    pthis->moveMode = BBMOVE_NOCLIP;
    pthis->actionState = BBGREEN_FLAME_ON;
    pthis->bobPhase = Rand_ZeroOne();
    pthis->actor.shape.rot.x = pthis->actor.shape.rot.z = 0;
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    if (pthis->actor.params == ENBB_GREEN_BIG) {
        EnBb_SetWaypoint(pthis, globalCtx);
        EnBb_FaceWaypoint(pthis);
    }
    Matrix_Translate(pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, 0, MTXMODE_APPLY);
    Matrix_RotateZ(pthis->bobPhase, MTXMODE_APPLY);
    bobOffset.y = pthis->bobSize;
    Matrix_MultVec3f(&bobOffset, &pthis->actor.world.pos);
    pthis->targetActor = NULL;
    pthis->action = BB_GREEN;
    pthis->actor.speedXZ = 0.0f;
    pthis->vFlameTimer = (Rand_ZeroOne() * 30.0f) + 180.0f;
    EnBb_SetupAction(pthis, EnBb_Green);
}

void EnBb_SetupGreen(EnBb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_Bb_Anim_000444);
    pthis->moveMode = BBMOVE_NOCLIP;
    pthis->actionState = BBGREEN_FLAME_ON;
    pthis->targetActor = NULL;
    pthis->action = BB_GREEN;
    pthis->actor.speedXZ = 0.0f;
    pthis->vFlameTimer = (Rand_ZeroOne() * 30.0f) + 180.0f;
    pthis->actor.shape.rot.z = 0;
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    EnBb_SetupAction(pthis, EnBb_Green);
}

void EnBb_Green(EnBb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f bobOffset = { 0.0f, 0.0f, 0.0f };
    Vec3f nextPos = player->actor.world.pos;

    nextPos.y += 30.0f;
    if (pthis->actor.params == ENBB_GREEN_BIG) {
        if (pthis->actor.speedXZ == 0.0f) {
            s16 pitch = Math_Vec3f_Pitch(&pthis->actor.home.pos, &pthis->waypointPos);
            s16 yaw = Math_Vec3f_Yaw(&pthis->actor.home.pos, &pthis->waypointPos);
            f32 vy = Math_SinS(pitch) * pthis->maxSpeed;
            f32 vxz = Math_CosS(pitch) * pthis->maxSpeed;
            f32 vz;
            f32 vx;
            f32 distL1;

            Math_SmoothStepToS(&pthis->actor.world.rot.y, yaw, 1, 0x3E8, 0);
            vx = Math_SinS(pthis->actor.world.rot.y) * vxz;
            distL1 = Math_CosS(pthis->actor.world.rot.y) * vxz;
            vz = Math_SmoothStepToF(&pthis->actor.home.pos.x, pthis->waypointPos.x, 1.0f, ABS(vx), 0.0f);
            vz += Math_SmoothStepToF(&pthis->actor.home.pos.y, pthis->waypointPos.y, 1.0f, ABS(vy), 0.0f);
            vz += Math_SmoothStepToF(&pthis->actor.home.pos.z, pthis->waypointPos.z, 1.0f, ABS(distL1), 0.0f);
            pthis->bobPhase += (0.05f + (Rand_ZeroOne() * 0.01f));
            if (vz == 0.0f) {
                EnBb_SetWaypoint(pthis, globalCtx);
            }
            pthis->moveMode = BBMOVE_NOCLIP;
            pthis->maxSpeed = 10.0f;
            if (pthis->collider.base.atFlags & AT_HIT) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_BITE);
                pthis->collider.base.atFlags &= ~AT_HIT;
            }
            if (Math_CosF(pthis->bobPhase) == 0.0f) {
                if (pthis->charge) {
                    pthis->bobSpeedMod = Rand_ZeroOne();
                } else {
                    pthis->bobSpeedMod = Rand_ZeroOne() * 3.0f;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_LAUGH);
                }
            }
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        } else if (Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f) == 0.0f) {
            EnBb_FaceWaypoint(pthis);
        }
    } else {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 0);
        Math_SmoothStepToS(&pthis->actor.shape.rot.x, Math_Vec3f_Pitch(&pthis->actor.world.pos, &nextPos), 1, 0xFA0, 0);
    }
    SkelAnime_Update(&pthis->skelAnime);
    if (Math_CosF(pthis->bobPhase) <= 0.002f) {
        pthis->bobSpeedMod = Rand_ZeroOne() * 0.05f;
    }
    Matrix_Translate(pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, 0, MTXMODE_APPLY);
    Matrix_RotateZ(pthis->bobPhase, MTXMODE_APPLY);
    bobOffset.y = pthis->bobSize;
    Matrix_MultVec3f(&bobOffset, &nextPos);
    Math_SmoothStepToF(&pthis->actor.world.pos.x, nextPos.x, 1.0f, pthis->bobPhase * 0.75f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.world.pos.y, nextPos.y, 1.0f, pthis->bobPhase * 0.75f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.world.pos.z, nextPos.z, 1.0f, pthis->bobPhase * 0.75f, 0.0f);
    pthis->bobPhase += 0.1f + pthis->bobSpeedMod;
    if (Actor_GetCollidedExplosive(globalCtx, &pthis->collider.base) || (--pthis->vFlameTimer == 0)) {
        pthis->actionState++;
        pthis->timer = (Rand_ZeroOne() * 30.0f) + 60.0f;
        if (pthis->vFlameTimer != 0) {
            pthis->collider.base.acFlags &= ~AC_HIT;
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_DOWN);
    }
    if (pthis->actionState != BBGREEN_FLAME_ON) {
        pthis->timer--;
        if (pthis->timer == 0) {
            pthis->actionState = BBGREEN_FLAME_ON;
            pthis->vFlameTimer = (Rand_ZeroOne() * 30.0f) + 180.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_UP);
        }
        Math_SmoothStepToF(&pthis->flameScaleY, 0.0f, 1.0f, 10.0f, 0.0f);
        Math_SmoothStepToF(&pthis->flameScaleX, 0.0f, 1.0f, 10.0f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->flameScaleY, 80.0f, 1.0f, 10.0f, 0.0f);
        Math_SmoothStepToF(&pthis->flameScaleX, 100.0f, 1.0f, 10.0f, 0.0f);
    }
    if ((s32)pthis->skelAnime.curFrame == 5) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_WING);
    }
    if (((s32)pthis->skelAnime.curFrame == 0) && (Rand_ZeroOne() < 0.1f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_LAUGH);
    }
}

void EnBb_SetupStunned(EnBb* pthis) {
    pthis->action = BB_STUNNED;
    if (pthis->actor.params != ENBB_WHITE) {
        if (pthis->actor.params != ENBB_RED) {
            if (pthis->actor.params > ENBB_GREEN) {
                pthis->actor.gravity = -2.0f;
                pthis->actor.shape.yOffset = 1500.0f;
            }
            pthis->actor.speedXZ = 0.0f;
            pthis->flameScaleX = 0.0f;
            pthis->flameScaleY = 0.0f;
        } else {
            EnBb_KillFlameTrail(pthis);
        }
    }
    switch (pthis->dmgEffect) {
        case 8:
            Actor_SetColorFilter(&pthis->actor, -0x8000, 0xC8, 0, 0x50);
            break;
        case 9:
            pthis->fireIceTimer = 0x30;
        case 15:
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
            Actor_SetColorFilter(&pthis->actor, 0, 0xB4, 0, 0x50);
            break;
    }
    pthis->actor.bgCheckFlags &= ~1;
    EnBb_SetupAction(pthis, EnBb_Stunned);
}

void EnBb_Stunned(EnBb* pthis, GlobalContext* globalCtx) {
    s16 yawDiff = pthis->actor.world.rot.y - pthis->actor.wallYaw;

    if (pthis->actor.bgCheckFlags & 8) {
        if (ABS(yawDiff) > 0x4000) {
            pthis->actor.world.rot.y = pthis->actor.wallYaw + pthis->actor.wallYaw - pthis->actor.world.rot.y - 0x8000;
        }
        pthis->actor.bgCheckFlags &= ~8;
    }
    if (pthis->actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        if (pthis->actor.velocity.y < -14.0f) {
            pthis->actor.velocity.y *= -0.4f;
        } else {
            pthis->actor.velocity.y = 0.0f;
        }
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 7.0f, 2, 2.0f, 0, 0, 0);
    }
    if (pthis->actor.colorFilterTimer == 0) {
        pthis->actor.shape.yOffset = 200.0f;
        if (pthis->actor.colChkInfo.health != 0) {
            if ((pthis->actor.params == ENBB_GREEN) || (pthis->actor.params == ENBB_GREEN_BIG)) {
                EnBb_SetupGreen(pthis);
            } else if (pthis->actor.params == ENBB_WHITE) {
                pthis->action = BB_WHITE;
                EnBb_SetupAction(pthis, EnBb_White);
            } else {
                EnBb_SetupDown(pthis);
            }
        } else {
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            EnBb_SetupDeath(pthis, globalCtx);
        }
    }
}

void EnBb_CollisionCheck(EnBb* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.atFlags & AT_BOUNCED) {
        pthis->collider.base.atFlags &= ~AT_BOUNCED;
        if (pthis->action != BB_DOWN) {
            if (pthis->actor.params >= ENBB_RED) {
                pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
                if (pthis->actor.params == ENBB_RED) {
                    EnBb_KillFlameTrail(pthis);
                }
                EnBb_SetupDown(pthis);
                return;
            }
            pthis->actionVar2 = 1;
        }
    }
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        pthis->dmgEffect = pthis->actor.colChkInfo.damageEffect;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.elements[0].info, 0);
        switch (pthis->dmgEffect) {
            case 7:
                pthis->actor.freezeTimer = pthis->collider.elements[0].info.acHitInfo->toucher.damage;
            case 5:
                pthis->fireIceTimer = 0x30;
                //! @bug
                //! Setting fireIceTimer here without calling Actor_SetColorFilter causes a crash if the bubble is
                //! killed in a single hit by an attack with damage effect 5 or 7 while actor updating is halted. Using
                //! Din's Fire on a white bubble will do just that. The mechanism is complex and described below.
                goto block_15;
            case 6:
                pthis->actor.freezeTimer = pthis->collider.elements[0].info.acHitInfo->toucher.damage;
                break;
            case 8:
            case 9:
            case 15:
                if (pthis->action != BB_STUNNED) {
                    Actor_ApplyDamage(&pthis->actor);
                    EnBb_SetupStunned(pthis);
                }
                break;
            default:
            block_15:
                if ((pthis->dmgEffect == 14) || (pthis->dmgEffect == 12) || (pthis->dmgEffect == 11) ||
                    (pthis->dmgEffect == 10) || (pthis->dmgEffect == 7) || (pthis->dmgEffect == 5)) {
                    if ((pthis->action != BB_DOWN) || (pthis->timer < 190)) {
                        Actor_ApplyDamage(&pthis->actor);
                    }
                    if ((pthis->action != BB_DOWN) && (pthis->actor.params != ENBB_WHITE)) {
                        EnBb_SetupDown(pthis);
                    }
                } else {
                    if (((pthis->action == BB_DOWN) && (pthis->timer < 190)) ||
                        ((pthis->actor.params != ENBB_WHITE) && (pthis->flameScaleX < 20.0f))) {
                        Actor_ApplyDamage(&pthis->actor);
                    } else {
                        pthis->collider.base.acFlags |= AC_HIT;
                    }
                }
                if (pthis->actor.colChkInfo.health == 0) {
                    pthis->actor.flags &= ~ACTOR_FLAG_0;
                    if (pthis->actor.params == ENBB_RED) {
                        EnBb_KillFlameTrail(pthis);
                    }
                    EnBb_SetupDeath(pthis, globalCtx);
                    //! @bug
                    //! Because Din's Fire kills the bubble in a single hit, Actor_SetColorFilter is never called and
                    //! colorFilterParams is never set. And because Din's Fire halts updating during its cutscene,
                    //! EnBb_Death doesn't kill the bubble on the next frame like it should. This combines with
                    //! the bug in EnBb_Draw below to crash the game.
                } else if ((pthis->actor.params == ENBB_WHITE) &&
                           ((pthis->action == BB_WHITE) || (pthis->action == BB_STUNNED))) {
                    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0xC);
                    pthis->actor.speedXZ = -8.0f;
                    pthis->maxSpeed = 0.0f;
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_BUBLE_DAMAGE);
                } else if (((pthis->action == BB_DOWN) && (pthis->timer < 190)) ||
                           ((pthis->actor.params != ENBB_WHITE) && (pthis->flameScaleX < 20.0f))) {
                    EnBb_SetupDamage(pthis);
                }
            case 13:
                break;
        }
    }
}

void EnBb_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnBb* pthis = (EnBb*)thisx;
    Vec3f sp4C = { 0.0f, 0.0f, 0.0f };
    Vec3f sp40 = { 0.0f, -0.6f, 0.0f };
    Color_RGBA8 sp3C = { 0, 0, 255, 255 };
    Color_RGBA8 sp38 = { 0, 0, 0, 0 };
    f32 sp34 = -15.0f;

    if (pthis->actor.params <= ENBB_BLUE) {
        EnBb_CollisionCheck(pthis, globalCtx);
    }
    if (pthis->actor.colChkInfo.damageEffect != 0xD) {
        pthis->actionFunc(pthis, globalCtx);
        if ((pthis->actor.params <= ENBB_BLUE) && (pthis->actor.speedXZ >= -6.0f) &&
            ((pthis->actor.flags & ACTOR_FLAG_15) == 0)) {
            Actor_MoveForward(&pthis->actor);
        }
        if (pthis->moveMode == BBMOVE_NORMAL) {
            if ((pthis->actor.world.pos.y - 20.0f) <= pthis->actor.floorHeight) {
                sp34 = 20.0f;
            }
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, sp34, 25.0f, 20.0f, 5);
        }
        pthis->actor.focus.pos = pthis->actor.world.pos;
        pthis->collider.elements->dim.worldSphere.center.x = pthis->actor.world.pos.x;
        pthis->collider.elements->dim.worldSphere.center.y =
            pthis->actor.world.pos.y + (pthis->actor.shape.yOffset * pthis->actor.scale.y);
        pthis->collider.elements->dim.worldSphere.center.z = pthis->actor.world.pos.z;

        if ((pthis->action > BB_KILL) && ((pthis->actor.speedXZ != 0.0f) || (pthis->action == BB_GREEN))) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if ((pthis->action > BB_FLAME_TRAIL) &&
            ((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000)) &&
            (pthis->moveMode != BBMOVE_HIDDEN)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

void EnBb_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnBb* pthis = (EnBb*)thisx;

    BodyBreak_SetInfo(&pthis->bodyBreak, limbIndex, 4, 15, 15, dList, BODYBREAK_OBJECT_DEFAULT);
}

static Vec3f sFireIceOffsets[] = {
    { 13.0f, 10.0f, 0.0f }, { 5.0f, 25.0f, 5.0f },   { -5.0f, 25.0f, 5.0f },  { -13.0f, 10.0f, 0.0f },
    { 5.0f, 25.0f, -5.0f }, { -5.0f, 25.0f, -5.0f }, { 0.0f, 10.0f, -13.0f }, { 5.0f, 0.0f, 5.0f },
    { 5.0f, 0.0f, -5.0f },  { 0.0f, 10.0f, 13.0f },  { -5.0f, 0.0f, 5.0f },   { -5.0f, 0.0f, -5.0f },
};

void EnBb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBb* pthis = (EnBb*)thisx;
    Vec3f blureBase1 = { 0.0f, 5000.0f, 0.0f };
    Vec3f blureBase2 = { 0.0f, 2000.0f, 0.0f };
    Vec3f blureVtx1;
    Vec3f blureVtx2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bb.c", 2044);

    blureBase1.z = pthis->maxSpeed * 80.0f;
    blureBase2.z = pthis->maxSpeed * 80.0f;
    if (pthis->moveMode != BBMOVE_HIDDEN) {
        if (pthis->actor.params <= ENBB_BLUE) {
            func_80093D18(globalCtx->state.gfxCtx);
            SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, EnBb_PostLimbDraw,
                              pthis);

            if (pthis->fireIceTimer != 0) {
                pthis->actor.colorFilterTimer++;
                //! @bug:
                //! The purpose of pthis is to counteract Actor_UpdateAll decrementing colorFilterTimer. However,
                //! the above bugs mean unk_2A8 can be nonzero without damage effects ever having been set.
                //! This routine will then increment colorFilterTimer, and on the next frame Actor_Draw will try
                //! to draw the unset colorFilterParams. This causes a divide-by-zero error, crashing the game.
                if (1) {}
                pthis->fireIceTimer--;
                if ((pthis->fireIceTimer % 4) == 0) {
                    Vec3f sp70;
                    s32 index = pthis->fireIceTimer >> 2;

                    sp70.x = pthis->actor.world.pos.x + sFireIceOffsets[index].x;
                    sp70.y = pthis->actor.world.pos.y + sFireIceOffsets[index].y;
                    sp70.z = pthis->actor.world.pos.z + sFireIceOffsets[index].z;

                    if ((pthis->dmgEffect != 7) && (pthis->dmgEffect != 5)) {
                        EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &sp70, 0x96, 0x96, 0x96, 0xFA, 0xEB,
                                                       0xF5, 0xFF, 0.8f);
                    } else {
                        sp70.y -= 17.0f;
                        EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &sp70, 0x28, 1, 0, -1);
                    }
                }
            }
            Matrix_Translate(0.0f, pthis->flameScaleX * -40.0f, 0.0f, MTXMODE_APPLY);
        } else {
            Matrix_Translate(0.0f, -40.0f, 0.0f, MTXMODE_APPLY);
        }
        if (pthis->actor.params != ENBB_WHITE) {
            func_80093D84(globalCtx->state.gfxCtx);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                        ((globalCtx->gameplayFrames + (pthis->flameScrollMod * 10)) *
                                         (-20 - (pthis->flameScrollMod * -2))) %
                                            0x200,
                                        0x20, 0x80));
            gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, pthis->flamePrimBlue, pthis->flamePrimAlpha);
            gDPSetEnvColor(POLY_XLU_DISP++, pthis->flameEnvColor.r, pthis->flameEnvColor.g, pthis->flameEnvColor.b, 0);
            Matrix_RotateY(((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) - pthis->actor.shape.rot.y + 0x8000)) *
                               (M_PI / 0x8000),
                           MTXMODE_APPLY);
            Matrix_Scale(pthis->flameScaleX * 0.01f, pthis->flameScaleY * 0.01f, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bb.c", 2106),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
        } else {
            Matrix_MultVec3f(&blureBase1, &blureVtx1);
            Matrix_MultVec3f(&blureBase2, &blureVtx2);
            if ((pthis->maxSpeed != 0.0f) && (pthis->action == BB_WHITE) && !(globalCtx->gameplayFrames & 1) &&
                (pthis->actor.colChkInfo.health != 0)) {
                EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIdx), &blureVtx1, &blureVtx2);
            } else if (pthis->action != BB_WHITE) {
                EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIdx));
            }
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bb.c", 2127);
}

void EnBb_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sDamageTableBlueGreen = {
        /* Deku nut      */ DMG_ENTRY(0, 0xF),
        /* Deku stick    */ DMG_ENTRY(2, 0x0),
        /* Slingshot     */ DMG_ENTRY(1, 0x0),
        /* Explosive     */ DMG_ENTRY(2, 0xA),
        /* Boomerang     */ DMG_ENTRY(0, 0xF),
        /* Normal arrow  */ DMG_ENTRY(2, 0xE),
        /* Hammer swing  */ DMG_ENTRY(2, 0xA),
        /* Hookshot      */ DMG_ENTRY(0, 0xF),
        /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
        /* Master sword  */ DMG_ENTRY(2, 0x0),
        /* Giant's Knife */ DMG_ENTRY(4, 0x0),
        /* Fire arrow    */ DMG_ENTRY(2, 0xE),
        /* Ice arrow     */ DMG_ENTRY(4, 0xC),
        /* Light arrow   */ DMG_ENTRY(4, 0xB),
        /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x6),
        /* Ice magic     */ DMG_ENTRY(3, 0x9),
        /* Light magic   */ DMG_ENTRY(3, 0x8),
        /* Shield        */ DMG_ENTRY(0, 0xA),
        /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
        /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
        /* Giant spin    */ DMG_ENTRY(4, 0x0),
        /* Master spin   */ DMG_ENTRY(2, 0x0),
        /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
        /* Giant jump    */ DMG_ENTRY(8, 0x0),
        /* Master jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 1     */ DMG_ENTRY(0, 0x6),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0xA),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    sDamageTableRed = {
        /* Deku nut      */ DMG_ENTRY(0, 0xD),
        /* Deku stick    */ DMG_ENTRY(0, 0xD),
        /* Slingshot     */ DMG_ENTRY(0, 0xD),
        /* Explosive     */ DMG_ENTRY(2, 0xA),
        /* Boomerang     */ DMG_ENTRY(0, 0xD),
        /* Normal arrow  */ DMG_ENTRY(2, 0xE),
        /* Hammer swing  */ DMG_ENTRY(2, 0xA),
        /* Hookshot      */ DMG_ENTRY(0, 0xD),
        /* Kokiri sword  */ DMG_ENTRY(0, 0xD),
        /* Master sword  */ DMG_ENTRY(2, 0xE),
        /* Giant's Knife */ DMG_ENTRY(4, 0xE),
        /* Fire arrow    */ DMG_ENTRY(2, 0xE),
        /* Ice arrow     */ DMG_ENTRY(4, 0x9),
        /* Light arrow   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
        /* Fire magic    */ DMG_ENTRY(0, 0x6),
        /* Ice magic     */ DMG_ENTRY(3, 0x9),
        /* Light magic   */ DMG_ENTRY(0, 0x6),
        /* Shield        */ DMG_ENTRY(0, 0xA),
        /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
        /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
        /* Giant spin    */ DMG_ENTRY(4, 0xE),
        /* Master spin   */ DMG_ENTRY(2, 0xE),
        /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
        /* Giant jump    */ DMG_ENTRY(8, 0xE),
        /* Master jump   */ DMG_ENTRY(4, 0xE),
        /* Unknown 1     */ DMG_ENTRY(0, 0x6),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0xA),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    sDamageTableWhite = {
        /* Deku nut      */ DMG_ENTRY(0, 0xF),
        /* Deku stick    */ DMG_ENTRY(2, 0xE),
        /* Slingshot     */ DMG_ENTRY(1, 0xE),
        /* Explosive     */ DMG_ENTRY(2, 0xA),
        /* Boomerang     */ DMG_ENTRY(0, 0xF),
        /* Normal arrow  */ DMG_ENTRY(2, 0xE),
        /* Hammer swing  */ DMG_ENTRY(2, 0xA),
        /* Hookshot      */ DMG_ENTRY(0, 0xF),
        /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
        /* Master sword  */ DMG_ENTRY(2, 0xE),
        /* Giant's Knife */ DMG_ENTRY(4, 0xE),
        /* Fire arrow    */ DMG_ENTRY(4, 0x5),
        /* Ice arrow     */ DMG_ENTRY(2, 0xE),
        /* Light arrow   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 1   */ DMG_ENTRY(4, 0xE),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0xE),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0xE),
        /* Fire magic    */ DMG_ENTRY(4, 0x7),
        /* Ice magic     */ DMG_ENTRY(0, 0x6),
        /* Light magic   */ DMG_ENTRY(0, 0x6),
        /* Shield        */ DMG_ENTRY(0, 0xA),
        /* Mirror Ray    */ DMG_ENTRY(0, 0xA),
        /* Kokiri spin   */ DMG_ENTRY(1, 0xE),
        /* Giant spin    */ DMG_ENTRY(4, 0xE),
        /* Master spin   */ DMG_ENTRY(2, 0xE),
        /* Kokiri jump   */ DMG_ENTRY(2, 0xE),
        /* Giant jump    */ DMG_ENTRY(8, 0xE),
        /* Master jump   */ DMG_ENTRY(4, 0xE),
        /* Unknown 1     */ DMG_ENTRY(0, 0x6),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(4, 0xA),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    En_Bb_InitVars = {
        ACTOR_EN_BB,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_BB,
        sizeof(EnBb),
        (ActorFunc)EnBb_Init,
        (ActorFunc)EnBb_Destroy,
        (ActorFunc)EnBb_Update,
        (ActorFunc)EnBb_Draw,
        (ActorFunc)EnBb_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_HIT3,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementInit,
    };

}

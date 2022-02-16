#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GELDB_Z_EN_GELDB_C
#include "actor_common.h"
/*
 * File: z_en_geldb.c
 * Overlay: ovl_En_GeldB
 * Description: Gerudo fighter
 */

#include "z_en_geldb.h"
#include "objects/object_geldb/object_geldb.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)


void EnGeldB_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGeldB_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGeldB_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGeldB_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGeldB_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnGeldB_DodgeRanged(GlobalContext* globalCtx, EnGeldB* pthis);

void EnGeldB_SetupWait(EnGeldB* pthis);
void EnGeldB_SetupReady(EnGeldB* pthis);
void EnGeldB_SetupAdvance(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_SetupPivot(EnGeldB* pthis);
void EnGeldB_SetupRollForward(EnGeldB* pthis);
void EnGeldB_SetupCircle(EnGeldB* pthis);
void EnGeldB_SetupSpinDodge(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_SetupSlash(EnGeldB* pthis);
void EnGeldB_SetupSpinAttack(EnGeldB* pthis);
void EnGeldB_SetupRollBack(EnGeldB* pthis);
void EnGeldB_SetupJump(EnGeldB* pthis);
void EnGeldB_SetupBlock(EnGeldB* pthis);
void EnGeldB_SetupSidestep(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_SetupDefeated(EnGeldB* pthis);

void EnGeldB_Wait(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Flee(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Ready(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Advance(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_RollForward(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Pivot(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Circle(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_SpinDodge(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Slash(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_SpinAttack(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_RollBack(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Stunned(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Damaged(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Jump(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Block(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Sidestep(EnGeldB* pthis, GlobalContext* globalCtx);
void EnGeldB_Defeated(EnGeldB* pthis, GlobalContext* globalCtx);

static Vec3f footOffset_111 = { 300.0f, 0.0f, 0.0f };

static Vec3f swordTipOffset_111 = { 0.0f, -3000.0f, 0.0f };

static Vec3f swordHiltOffset_111 = { 400.0f, 0.0f, 0.0f };

static Vec3f swordQuadOffset1_111 = { 1600.0f, -4000.0f, 0.0f };

static Vec3f swordQuadOffset0_111 = { -3000.0f, -2000.0f, 1300.0f };

static Vec3f swordQuadOffset3_111 = { -3000.0f, -2000.0f, -1300.0f };

static Vec3f swordQuadOffset2_111 = { 1000.0f, 1000.0f, 0.0f };

static Vec3f zeroVec_111 = { 0.0f, 0.0f, 0.0f };

static Vec3f blockTrisOffsets0_112[3] = {
    { -3000.0f, 6000.0f, 1600.0f },
    { -3000.0f, 0.0f, 1600.0f },
    { 3000.0f, 6000.0f, 1600.0f },
};

static Vec3f blockTrisOffsets1_112[3] = {
    { -3000.0f, 0.0f, 1600.0f },
    { 3000.0f, 0.0f, 1600.0f },
    { 3000.0f, 6000.0f, 1600.0f },
};

static void* eyeTextures_112[] = { gGerudoRedEyeOpenTex, gGerudoRedEyeHalfTex, gGerudoRedEyeShutTex,
                               gGerudoRedEyeHalfTex };


ActorInit En_GeldB_InitVars = {
    ACTOR_EN_GELDB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GELDB,
    sizeof(EnGeldB),
    (ActorFunc)EnGeldB_Init,
    (ActorFunc)EnGeldB_Destroy,
    (ActorFunc)EnGeldB_Update,
    (ActorFunc)EnGeldB_Draw,
    (ActorFunc)EnGeldB_Reset,
};

static ColliderCylinderInit sBodyCylInit = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 50, 0, { 0, 0, 0 } },
};

static ColliderTrisElementInit sBlockTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC1FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { -10.0f, 14.0f, 2.0f }, { -10.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFC1FFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
};

static ColliderTrisInit sBlockTrisInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    2,
    sBlockTrisElementsInit,
};

static ColliderQuadInit sSwordQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, GELDB_DMG_STUN),
    /* Deku stick    */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Slingshot     */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
    /* Explosive     */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Boomerang     */ DMG_ENTRY(0, GELDB_DMG_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Hammer swing  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Hookshot      */ DMG_ENTRY(0, GELDB_DMG_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
    /* Master sword  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Giant's Knife */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
    /* Fire arrow    */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Ice arrow     */ DMG_ENTRY(2, GELDB_DMG_FREEZE),
    /* Light arrow   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Unk arrow 1   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Unk arrow 2   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Unk arrow 3   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Fire magic    */ DMG_ENTRY(4, GELDB_DMG_UNK_E),
    /* Ice magic     */ DMG_ENTRY(0, GELDB_DMG_UNK_6),
    /* Light magic   */ DMG_ENTRY(3, GELDB_DMG_UNK_D),
    /* Shield        */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
    /* Mirror Ray    */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
    /* Kokiri spin   */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
    /* Giant spin    */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
    /* Master spin   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Kokiri jump   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
    /* Giant jump    */ DMG_ENTRY(8, GELDB_DMG_NORMAL),
    /* Master jump   */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
    /* Unknown 1     */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
    /* Unblockable   */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
    /* Hammer jump   */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
    /* Unknown 2     */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3000, ICHAIN_STOP),
};

static Vec3f sUnusedOffset = { 1100.0f, -700.0f, 0.0f };

void EnGeldB_SetupAction(EnGeldB* pthis, EnGeldBActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnGeldB_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EffectBlureInit1 blureInit;
    EnGeldB* pthis = (EnGeldB*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    thisx->colChkInfo.damageTable = &sDamageTable;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawFeet, 0.0f);
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    thisx->colChkInfo.health = 20;
    thisx->colChkInfo.cylRadius = 50;
    thisx->colChkInfo.cylHeight = 100;
    thisx->naviEnemyId = 0x54;
    pthis->keyFlag = thisx->params & 0xFF00;
    thisx->params &= 0xFF;
    pthis->blinkState = 0;
    pthis->unkFloat = 10.0f;
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGerudoRedSkel, &gGerudoRedNeutralAnim, pthis->jointTable,
                       pthis->morphTable, GELDB_LIMB_MAX);
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, thisx, &sBodyCylInit);
    Collider_InitTris(globalCtx, &pthis->blockCollider);
    Collider_SetTris(globalCtx, &pthis->blockCollider, thisx, &sBlockTrisInit, pthis->blockElements);
    Collider_InitQuad(globalCtx, &pthis->swordCollider);
    Collider_SetQuad(globalCtx, &pthis->swordCollider, thisx, &sSwordQuadInit);
    blureInit.p1StartColor[0] = blureInit.p1StartColor[1] = blureInit.p1StartColor[2] = blureInit.p1StartColor[3] =
        blureInit.p2StartColor[0] = blureInit.p2StartColor[1] = blureInit.p2StartColor[2] = blureInit.p1EndColor[0] =
            blureInit.p1EndColor[1] = blureInit.p1EndColor[2] = blureInit.p2EndColor[0] = blureInit.p2EndColor[1] =
                blureInit.p2EndColor[2] = 255;
    blureInit.p2StartColor[3] = 64;
    blureInit.p1EndColor[3] = blureInit.p2EndColor[3] = 0;
    blureInit.elemDuration = 8;
    blureInit.unkFlag = 0;
    blureInit.calcMode = 2;

    Effect_Add(globalCtx, &pthis->blureIndex, EFFECT_BLURE1, 0, 0, &blureInit);
    Actor_SetScale(thisx, 0.012499999f);
    EnGeldB_SetupWait(pthis);
    if ((pthis->keyFlag != 0) && Flags_GetCollectible(globalCtx, pthis->keyFlag >> 8)) {
        Actor_Kill(thisx);
    }
}

void EnGeldB_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGeldB* pthis = (EnGeldB*)thisx;

    func_800F5B58();
    Effect_Delete(globalCtx, pthis->blureIndex);
    Collider_DestroyTris(globalCtx, &pthis->blockCollider);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyQuad(globalCtx, &pthis->swordCollider);
}

s32 EnGeldB_ReactToPlayer(GlobalContext* globalCtx, EnGeldB* pthis, s16 arg2) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* thisx = &pthis->actor;
    s16 angleToWall;
    s16 angleToLink;
    Actor* bomb;

    angleToWall = thisx->wallYaw - thisx->shape.rot.y;
    angleToWall = ABS(angleToWall);
    angleToLink = thisx->yawTowardsPlayer - thisx->shape.rot.y;
    angleToLink = ABS(angleToLink);

    if (func_800354B4(globalCtx, thisx, 100.0f, 0x2710, 0x3E80, thisx->shape.rot.y)) {
        if (player->swordAnimation == 0x11) {
            EnGeldB_SetupSpinDodge(pthis, globalCtx);
            return true;
        } else if (globalCtx->gameplayFrames & 1) {
            EnGeldB_SetupBlock(pthis);
            return true;
        }
    }
    if (func_800354B4(globalCtx, thisx, 100.0f, 0x5DC0, 0x2AA8, thisx->shape.rot.y)) {
        thisx->shape.rot.y = thisx->world.rot.y = thisx->yawTowardsPlayer;
        if ((thisx->bgCheckFlags & 8) && (ABS(angleToWall) < 0x2EE0) && (thisx->xzDistToPlayer < 90.0f)) {
            EnGeldB_SetupJump(pthis);
            return true;
        } else if (player->swordAnimation == 0x11) {
            EnGeldB_SetupSpinDodge(pthis, globalCtx);
            return true;
        } else if ((thisx->xzDistToPlayer < 90.0f) && (globalCtx->gameplayFrames & 1)) {
            EnGeldB_SetupBlock(pthis);
            return true;
        } else {
            EnGeldB_SetupRollBack(pthis);
            return true;
        }
    } else if ((bomb = Actor_FindNearby(globalCtx, thisx, -1, ACTORCAT_EXPLOSIVE, 80.0f)) != NULL) {
        thisx->shape.rot.y = thisx->world.rot.y = thisx->yawTowardsPlayer;
        if (((thisx->bgCheckFlags & 8) && (angleToWall < 0x2EE0)) || (bomb->id == ACTOR_EN_BOM_CHU)) {
            if ((bomb->id == ACTOR_EN_BOM_CHU) && (Actor_WorldDistXYZToActor(thisx, bomb) < 80.0f) &&
                ((s16)(thisx->shape.rot.y - (bomb->world.rot.y - 0x8000)) < 0x3E80)) {
                EnGeldB_SetupJump(pthis);
                return true;
            } else {
                EnGeldB_SetupSidestep(pthis, globalCtx);
                return true;
            }
        } else {
            EnGeldB_SetupRollBack(pthis);
            return true;
        }
    } else if (arg2) {
        if (angleToLink >= 0x1B58) {
            EnGeldB_SetupSidestep(pthis, globalCtx);
            return true;
        } else {
            s16 angleToFacingLink = player->actor.shape.rot.y - thisx->shape.rot.y;

            if ((thisx->xzDistToPlayer <= 45.0f) && !Actor_OtherIsTargeted(globalCtx, thisx) &&
                ((globalCtx->gameplayFrames & 7) || (ABS(angleToFacingLink) < 0x38E0))) {
                EnGeldB_SetupSlash(pthis);
                return true;
            } else {
                EnGeldB_SetupCircle(pthis);
                return true;
            }
        }
    }
    return false;
}

void EnGeldB_SetupWait(EnGeldB* pthis) {
    Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gGerudoRedJumpAnim, 0.0f);
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 120.0f;
    pthis->timer = 10;
    pthis->invisible = true;
    pthis->action = GELDB_WAIT;
    pthis->actor.bgCheckFlags &= ~3;
    pthis->actor.gravity = -2.0f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnGeldB_SetupAction(pthis, EnGeldB_Wait);
}

void EnGeldB_Wait(EnGeldB* pthis, GlobalContext* globalCtx) {
    if ((pthis->invisible && !Flags_GetSwitch(globalCtx, pthis->actor.home.rot.z)) ||
        pthis->actor.xzDistToPlayer > 300.0f) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.world.pos.y = pthis->actor.floorHeight + 120.0f;
    } else {
        pthis->invisible = false;
        pthis->actor.shape.shadowScale = 90.0f;
        func_800F5ACC(NA_BGM_MINI_BOSS);
    }
    if (pthis->actor.bgCheckFlags & 2) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        pthis->skelAnime.playSpeed = 1.0f;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.focus.pos = pthis->actor.world.pos;
        pthis->actor.bgCheckFlags &= ~2;
        pthis->actor.velocity.y = 0.0f;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnGeldB_SetupReady(pthis);
    }
}

void EnGeldB_SetupFlee(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedJumpAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedJumpAnim, -2.0f, lastFrame, 0.0f, ANIMMODE_ONCE_INTERP, -4.0f);
    pthis->timer = 20;
    pthis->invisible = false;
    pthis->action = GELDB_WAIT;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    EnGeldB_SetupAction(pthis, EnGeldB_Flee);
}

void EnGeldB_Flee(EnGeldB* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame == 10.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    }
    if (pthis->skelAnime.curFrame == 2.0f) {
        pthis->actor.gravity = 0.0f;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        Math_SmoothStepToF(&pthis->actor.world.pos.y, pthis->actor.floorHeight + 300.0f, 1.0f, 20.5f, 0.0f);
        pthis->timer--;
        if (pthis->timer == 0) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnGeldB_SetupReady(EnGeldB* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gGerudoRedNeutralAnim, -4.0f);
    pthis->action = GELDB_READY;
    pthis->timer = Rand_ZeroOne() * 10.0f + 5.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnGeldB_SetupAction(pthis, EnGeldB_Ready);
}

void EnGeldB_Ready(EnGeldB* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s16 angleToLink;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->lookTimer != 0) {
        angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y - pthis->headRot.y;
        if (ABS(angleToLink) > 0x2000) {
            pthis->lookTimer--;
            return;
        }
        pthis->lookTimer = 0;
    }
    angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    if (!EnGeldB_DodgeRanged(globalCtx, pthis)) {
        if (pthis->unkTimer != 0) {
            pthis->unkTimer--;

            if (ABS(angleToLink) >= 0x1FFE) {
                return;
            }
            pthis->unkTimer = 0;
        } else if (EnGeldB_ReactToPlayer(globalCtx, pthis, 0)) {
            return;
        }
        angleToLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
        if ((pthis->actor.xzDistToPlayer < 100.0f) && (player->swordState != 0) && (ABS(angleToLink) >= 0x1F40)) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            EnGeldB_SetupCircle(pthis);
        } else if (--pthis->timer == 0) {
            if (Actor_IsFacingPlayer(&pthis->actor, 30 * 0x10000 / 360)) {
                if ((210.0f > pthis->actor.xzDistToPlayer) && (pthis->actor.xzDistToPlayer > 150.0f) &&
                    (Rand_ZeroOne() < 0.3f)) {
                    if (Actor_OtherIsTargeted(globalCtx, &pthis->actor) || (Rand_ZeroOne() > 0.5f) ||
                        (ABS(angleToLink) < 0x38E0)) {
                        EnGeldB_SetupRollForward(pthis);
                    } else {
                        EnGeldB_SetupSpinAttack(pthis);
                    }
                } else if (Rand_ZeroOne() > 0.3f) {
                    EnGeldB_SetupAdvance(pthis, globalCtx);
                } else {
                    EnGeldB_SetupCircle(pthis);
                }
            } else {
                EnGeldB_SetupPivot(pthis);
            }
            if ((globalCtx->gameplayFrames & 0x5F) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
            }
        }
    }
}

void EnGeldB_SetupAdvance(EnGeldB* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedWalkAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedWalkAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, -4.0f);
    pthis->action = GELDB_ADVANCE;
    EnGeldB_SetupAction(pthis, EnGeldB_Advance);
}

void EnGeldB_Advance(EnGeldB* pthis, GlobalContext* globalCtx) {
    s32 thisKeyFrame;
    s32 prevKeyFrame;
    s32 playSpeed;
    s16 facingAngletoLink;
    Player* player = GET_PLAYER(globalCtx);

    if (!EnGeldB_DodgeRanged(globalCtx, pthis)) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x2EE, 0);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        if (pthis->actor.xzDistToPlayer <= 40.0f) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, -8.0f, 1.0f, 1.5f, 0.0f);
        } else if (pthis->actor.xzDistToPlayer > 55.0f) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 8.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 6.65f, 0.0f);
        }
        pthis->skelAnime.playSpeed = pthis->actor.speedXZ / 8.0f;
        facingAngletoLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
        facingAngletoLink = ABS(facingAngletoLink);
        if ((pthis->actor.xzDistToPlayer < 150.0f) && (player->swordState != 0) && (facingAngletoLink >= 0x1F40)) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            if (Rand_ZeroOne() > 0.7f) {
                EnGeldB_SetupCircle(pthis);
                return;
            }
        }
        thisKeyFrame = (s32)pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);
        prevKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        playSpeed = (f32)ABS(pthis->skelAnime.playSpeed);
        if (!Actor_IsFacingPlayer(&pthis->actor, 0x11C7)) {
            if (Rand_ZeroOne() > 0.5f) {
                EnGeldB_SetupCircle(pthis);
            } else {
                EnGeldB_SetupReady(pthis);
            }
        } else if (pthis->actor.xzDistToPlayer < 90.0f) {
            if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor) &&
                (Rand_ZeroOne() > 0.03f || (pthis->actor.xzDistToPlayer <= 45.0f && facingAngletoLink < 0x38E0))) {
                EnGeldB_SetupSlash(pthis);
            } else if (Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (Rand_ZeroOne() > 0.5f)) {
                EnGeldB_SetupRollBack(pthis);
            } else {
                EnGeldB_SetupCircle(pthis);
            }
        }
        if (!EnGeldB_ReactToPlayer(globalCtx, pthis, 0)) {
            if ((210.0f > pthis->actor.xzDistToPlayer) && (pthis->actor.xzDistToPlayer > 150.0f) &&
                Actor_IsFacingPlayer(&pthis->actor, 0x71C)) {
                if (Actor_IsTargeted(globalCtx, &pthis->actor)) {
                    if (Rand_ZeroOne() > 0.5f) {
                        EnGeldB_SetupRollForward(pthis);
                    } else {
                        EnGeldB_SetupSpinAttack(pthis);
                    }
                } else {
                    EnGeldB_SetupCircle(pthis);
                    return;
                }
            }
            if ((globalCtx->gameplayFrames & 0x5F) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
            }
            if (thisKeyFrame != (s32)pthis->skelAnime.curFrame) {
                s32 temp = playSpeed + thisKeyFrame;

                if (((prevKeyFrame < 0) && (temp > 0)) || ((prevKeyFrame < 4) && (temp > 4))) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_LAND);
                }
            }
        }
    }
}

void EnGeldB_SetupRollForward(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedFlipAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedFlipAnim, -1.0f, lastFrame, 0.0f, ANIMMODE_ONCE, -3.0f);
    pthis->timer = 0;
    pthis->invisible = true;
    pthis->action = GELDB_ROLL_FORWARD;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->actor.speedXZ = 10.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    EnGeldB_SetupAction(pthis, EnGeldB_RollForward);
}

void EnGeldB_RollForward(EnGeldB* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 facingAngleToLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->invisible = false;
        pthis->actor.speedXZ = 0.0f;
        if (!Actor_IsFacingPlayer(&pthis->actor, 0x1554)) {
            EnGeldB_SetupReady(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
            if (ABS(facingAngleToLink) < 0x38E0) {
                pthis->lookTimer = 20;
            }
        } else if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor) &&
                   (Rand_ZeroOne() > 0.5f || (ABS(facingAngleToLink) < 0x3FFC))) {
            EnGeldB_SetupSlash(pthis);
        } else {
            EnGeldB_SetupAdvance(pthis, globalCtx);
        }
    }
    if ((globalCtx->gameplayFrames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
    }
}

void EnGeldB_SetupPivot(EnGeldB* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gGerudoRedSidestepAnim, -4.0f);
    pthis->action = GELDB_PIVOT;
    EnGeldB_SetupAction(pthis, EnGeldB_Pivot);
}

void EnGeldB_Pivot(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 angleToLink;
    s16 turnRate;
    f32 playSpeed;

    if (!EnGeldB_DodgeRanged(globalCtx, pthis) && !EnGeldB_ReactToPlayer(globalCtx, pthis, 0)) {
        angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        turnRate = (angleToLink > 0) ? ((angleToLink * 0.25f) + 2000.0f) : ((angleToLink * 0.25f) - 2000.0f);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y += turnRate;
        if (angleToLink > 0) {
            playSpeed = turnRate * 0.5f;
            playSpeed = CLAMP_MAX(playSpeed, 1.0f);
        } else {
            playSpeed = turnRate * 0.5f;
            playSpeed = CLAMP_MIN(playSpeed, -1.0f);
        }
        pthis->skelAnime.playSpeed = -playSpeed;
        SkelAnime_Update(&pthis->skelAnime);
        if (Actor_IsFacingPlayer(&pthis->actor, 30 * 0x10000 / 360)) {
            if (Rand_ZeroOne() > 0.8f) {
                EnGeldB_SetupCircle(pthis);
            } else {
                EnGeldB_SetupAdvance(pthis, globalCtx);
            }
        }
        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
        }
    }
}

void EnGeldB_SetupCircle(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedSidestepAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedSidestepAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, 0.0f);
    pthis->actor.speedXZ = Rand_CenteredFloat(12.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
    pthis->timer = Rand_ZeroOne() * 30.0f + 30.0f;
    pthis->action = GELDB_CIRCLE;
    pthis->approachRate = 0.0f;
    EnGeldB_SetupAction(pthis, EnGeldB_Circle);
}

void EnGeldB_Circle(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 angleBehindLink;
    s16 phi_v1;
    s32 nextKeyFrame;
    s32 thisKeyFrame;
    s32 pad;
    s32 prevKeyFrame;
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    if (!EnGeldB_DodgeRanged(globalCtx, pthis) && !EnGeldB_ReactToPlayer(globalCtx, pthis, 0)) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3A98;
        angleBehindLink = player->actor.shape.rot.y + 0x8000;
        if (Math_SinS(angleBehindLink - pthis->actor.shape.rot.y) >= 0.0f) {
            pthis->actor.speedXZ -= 0.25f;
            if (pthis->actor.speedXZ < -8.0f) {
                pthis->actor.speedXZ = -8.0f;
            }
        } else if (Math_SinS(angleBehindLink - pthis->actor.shape.rot.y) < 0.0f) {
            pthis->actor.speedXZ += 0.25f;
            if (pthis->actor.speedXZ > 8.0f) {
                pthis->actor.speedXZ = 8.0f;
            }
        }
        if ((pthis->actor.bgCheckFlags & 8) || !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ,
                                                                          pthis->actor.shape.rot.y + 0x3E80)) {
            if (pthis->actor.bgCheckFlags & 8) {
                if (pthis->actor.speedXZ >= 0.0f) {
                    phi_v1 = pthis->actor.shape.rot.y + 0x3E80;
                } else {
                    phi_v1 = pthis->actor.shape.rot.y - 0x3E80;
                }
                phi_v1 = pthis->actor.wallYaw - phi_v1;
            } else {
                pthis->actor.speedXZ *= -0.8f;
                phi_v1 = 0;
            }
            if (ABS(phi_v1) > 0x4000) {
                pthis->actor.speedXZ *= -0.8f;
                if (pthis->actor.speedXZ < 0.0f) {
                    pthis->actor.speedXZ -= 0.5f;
                } else {
                    pthis->actor.speedXZ += 0.5f;
                }
            }
        }
        if (pthis->actor.xzDistToPlayer <= 45.0f) {
            Math_SmoothStepToF(&pthis->approachRate, -4.0f, 1.0f, 1.5f, 0.0f);
        } else if (pthis->actor.xzDistToPlayer > 40.0f) {
            Math_SmoothStepToF(&pthis->approachRate, 4.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&pthis->approachRate, 0.0f, 1.0f, 6.65f, 0.0f);
        }
        if (pthis->approachRate != 0.0f) {
            pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->approachRate;
            pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->approachRate;
        }
        if (ABS(pthis->approachRate) < ABS(pthis->actor.speedXZ)) {
            pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
        } else {
            pthis->skelAnime.playSpeed = -pthis->approachRate * 0.5f;
        }
        pthis->skelAnime.playSpeed = CLAMP(pthis->skelAnime.playSpeed, -3.0f, 3.0f);

        thisKeyFrame = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);

        prevKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        nextKeyFrame = (s32)ABS(pthis->skelAnime.playSpeed) + thisKeyFrame;
        if ((thisKeyFrame != (s32)pthis->skelAnime.curFrame) &&
            ((prevKeyFrame < 0 && 0 < nextKeyFrame) || (prevKeyFrame < 5 && 5 < nextKeyFrame))) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_LAND);
        }
        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
        }
        if ((Math_CosS(angleBehindLink - pthis->actor.shape.rot.y) < -0.85f) &&
            !Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (pthis->actor.xzDistToPlayer <= 45.0f)) {
            EnGeldB_SetupSlash(pthis);
        } else if (--pthis->timer == 0) {
            if (Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (Rand_ZeroOne() > 0.5f)) {
                EnGeldB_SetupRollBack(pthis);
            } else {
                EnGeldB_SetupReady(pthis);
            }
        }
    }
}

void EnGeldB_SetupSpinDodge(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 sp3E;
    Player* player = GET_PLAYER(globalCtx);
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedSidestepAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedSidestepAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, 0.0f);
    sp3E = player->actor.shape.rot.y;
    if (Math_SinS(sp3E - pthis->actor.shape.rot.y) > 0.0f) {
        pthis->actor.speedXZ = -10.0f;
    } else if (Math_SinS(sp3E - pthis->actor.shape.rot.y) < 0.0f) {
        pthis->actor.speedXZ = 10.0f;
    } else if (Rand_ZeroOne() > 0.5f) {
        pthis->actor.speedXZ = 10.0f;
    } else {
        pthis->actor.speedXZ = -10.0f;
    }
    pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->timer = 6;
    pthis->approachRate = 0.0f;
    pthis->unkFloat = 0.0f;
    pthis->action = GELDB_SPIN_DODGE;

    EnGeldB_SetupAction(pthis, EnGeldB_SpinDodge);
}

void EnGeldB_SpinDodge(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 phi_v1;
    s32 thisKeyFrame;
    s32 pad;
    s32 lastKeyFrame;
    s32 nextKeyFrame;

    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x3A98;
    if ((pthis->actor.bgCheckFlags & 8) ||
        !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.shape.rot.y + 0x3E80)) {
        if (pthis->actor.bgCheckFlags & 8) {
            if (pthis->actor.speedXZ >= 0.0f) {
                phi_v1 = pthis->actor.shape.rot.y + 0x3E80;
            } else {
                phi_v1 = pthis->actor.shape.rot.y - 0x3E80;
            }
            phi_v1 = pthis->actor.wallYaw - phi_v1;
        } else {
            pthis->actor.speedXZ *= -0.8f;
            phi_v1 = 0;
        }
        if (ABS(phi_v1) > 0x4000) {
            EnGeldB_SetupJump(pthis);
            return;
        }
    }
    if (pthis->actor.xzDistToPlayer <= 45.0f) {
        Math_SmoothStepToF(&pthis->approachRate, -4.0f, 1.0f, 1.5f, 0.0f);
    } else if (pthis->actor.xzDistToPlayer > 40.0f) {
        Math_SmoothStepToF(&pthis->approachRate, 4.0f, 1.0f, 1.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->approachRate, 0.0f, 1.0f, 6.65f, 0.0f);
    }
    if (pthis->approachRate != 0.0f) {
        pthis->actor.world.pos.x += Math_SinS(pthis->actor.yawTowardsPlayer) * pthis->approachRate;
        pthis->actor.world.pos.z += Math_CosS(pthis->actor.yawTowardsPlayer) * pthis->approachRate;
    }
    if (ABS(pthis->approachRate) < ABS(pthis->actor.speedXZ)) {
        pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
    } else {
        pthis->skelAnime.playSpeed = -pthis->approachRate * 0.5f;
    }
    pthis->skelAnime.playSpeed = CLAMP(pthis->skelAnime.playSpeed, -3.0f, 3.0f);
    thisKeyFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);
    lastKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
    nextKeyFrame = (s32)ABS(pthis->skelAnime.playSpeed) + thisKeyFrame;
    if ((thisKeyFrame != (s32)pthis->skelAnime.curFrame) &&
        ((lastKeyFrame < 0 && 0 < nextKeyFrame) || (lastKeyFrame < 5 && 5 < nextKeyFrame))) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_LAND);
    }
    if ((globalCtx->gameplayFrames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
    }
    pthis->timer--;
    if (pthis->timer == 0) {
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
        if (!EnGeldB_DodgeRanged(globalCtx, pthis)) {
            if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (pthis->actor.xzDistToPlayer <= 70.0f)) {
                EnGeldB_SetupSlash(pthis);
            } else {
                EnGeldB_SetupRollBack(pthis);
            }
        }
    } else {
        if (pthis->actor.speedXZ >= 0.0f) {
            pthis->actor.shape.rot.y += 0x4000;
        } else {
            pthis->actor.shape.rot.y -= 0x4000;
        }
    }
}

void EnGeldB_SetupSlash(EnGeldB* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gGerudoRedSlashAnim);
    pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
    pthis->action = GELDB_SLASH;
    pthis->spinAttackState = 0;
    pthis->actor.speedXZ = 0.0f;
    Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_GERUDOFT_BREATH);
    EnGeldB_SetupAction(pthis, EnGeldB_Slash);
}

void EnGeldB_Slash(EnGeldB* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 angleFacingLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
    s16 angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    angleFacingLink = ABS(angleFacingLink);
    angleToLink = ABS(angleToLink);

    pthis->actor.speedXZ = 0.0f;
    if ((s32)pthis->skelAnime.curFrame == 1) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_ATTACK);
        pthis->swordState = 1;
    } else if ((s32)pthis->skelAnime.curFrame == 6) {
        pthis->swordState = -1;
    }
    if (pthis->swordCollider.base.atFlags & AT_BOUNCED) {
        pthis->swordState = -1;
        pthis->swordCollider.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
        EnGeldB_SetupRollBack(pthis);
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        if (!Actor_IsFacingPlayer(&pthis->actor, 0x1554)) {
            EnGeldB_SetupReady(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
            if (angleToLink > 0x4000) {
                pthis->lookTimer = 20;
            }
        } else if (Rand_ZeroOne() > 0.7f || (pthis->actor.xzDistToPlayer >= 120.0f)) {
            EnGeldB_SetupReady(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
        } else {
            pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            if (Rand_ZeroOne() > 0.7f) {
                EnGeldB_SetupSidestep(pthis, globalCtx);
            } else if (angleFacingLink <= 0x2710) {
                if (angleToLink > 0x3E80) {
                    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                    EnGeldB_SetupCircle(pthis);
                } else {
                    EnGeldB_ReactToPlayer(globalCtx, pthis, 1);
                }
            } else {
                EnGeldB_SetupCircle(pthis);
            }
        }
    }
}

void EnGeldB_SetupSpinAttack(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedSpinAttackAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedSpinAttackAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_ONCE_INTERP, 0.0f);
    pthis->swordCollider.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
    pthis->action = GELDB_SPIN_ATTACK;
    pthis->spinAttackState = 0;
    pthis->actor.speedXZ = 0.0f;
    EnGeldB_SetupAction(pthis, EnGeldB_SpinAttack);
}

void EnGeldB_SpinAttack(EnGeldB* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 angleFacingLink;
    s16 angleToLink;

    if (pthis->spinAttackState < 2) {
        if (pthis->swordCollider.base.atFlags & AT_BOUNCED) {
            pthis->swordCollider.base.atFlags &= ~(AT_HIT | AT_BOUNCED);
            pthis->spinAttackState = 1;
            pthis->skelAnime.playSpeed = 1.5f;
        } else if (pthis->swordCollider.base.atFlags & AT_HIT) {
            pthis->swordCollider.base.atFlags &= ~AT_HIT;
            if (&player->actor == pthis->swordCollider.base.at) {
                func_8002F71C(globalCtx, &pthis->actor, 6.0f, pthis->actor.yawTowardsPlayer, 6.0f);
                pthis->spinAttackState = 2;
                func_8002DF54(globalCtx, &pthis->actor, 0x18);
                Message_StartTextbox(globalCtx, 0x6003, &pthis->actor);
                pthis->timer = 30;
                pthis->actor.speedXZ = 0.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_TWINROBA_YOUNG_LAUGH);
                return;
            }
        }
    }
    if ((s32)pthis->skelAnime.curFrame < 9) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    } else if ((s32)pthis->skelAnime.curFrame == 13) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
        pthis->swordState = 1;
        pthis->actor.speedXZ = 10.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_ATTACK);
    } else if ((s32)pthis->skelAnime.curFrame == 21) {
        pthis->actor.speedXZ = 0.0f;
    } else if ((s32)pthis->skelAnime.curFrame == 24) {
        pthis->swordState = -1;
    }
    if (SkelAnime_Update(&pthis->skelAnime) && (pthis->spinAttackState < 2)) {
        if (!Actor_IsFacingPlayer(&pthis->actor, 0x1554)) {
            EnGeldB_SetupReady(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
            pthis->lookTimer = 46;
        } else if (pthis->spinAttackState != 0) {
            EnGeldB_SetupRollBack(pthis);
        } else if (Rand_ZeroOne() > 0.7f || (pthis->actor.xzDistToPlayer >= 120.0f)) {
            EnGeldB_SetupReady(pthis);
            pthis->timer = (Rand_ZeroOne() * 5.0f) + 5.0f;
        } else {
            pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            if (Rand_ZeroOne() > 0.7f) {
                EnGeldB_SetupSidestep(pthis, globalCtx);
            } else {
                angleFacingLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
                angleFacingLink = ABS(angleFacingLink);
                if (angleFacingLink <= 0x2710) {
                    angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
                    angleToLink = ABS(angleToLink);
                    if (angleToLink > 0x3E80) {
                        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                        EnGeldB_SetupCircle(pthis);
                    } else {
                        EnGeldB_ReactToPlayer(globalCtx, pthis, 1);
                    }
                } else {
                    EnGeldB_SetupCircle(pthis);
                }
            }
        }
    }
}

void EnGeldB_SetupRollBack(EnGeldB* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gGerudoRedFlipAnim, -3.0f);
    pthis->timer = 0;
    pthis->invisible = true;
    pthis->action = GELDB_ROLL_BACK;
    pthis->actor.speedXZ = -8.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    EnGeldB_SetupAction(pthis, EnGeldB_RollBack);
}

void EnGeldB_RollBack(EnGeldB* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor) && (pthis->actor.xzDistToPlayer < 170.0f) &&
            (pthis->actor.xzDistToPlayer > 140.0f) && (Rand_ZeroOne() < 0.2f)) {
            EnGeldB_SetupSpinAttack(pthis);
        } else if (globalCtx->gameplayFrames & 1) {
            EnGeldB_SetupSidestep(pthis, globalCtx);
        } else {
            EnGeldB_SetupReady(pthis);
        }
    }
    if ((globalCtx->state.frames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
    }
}

void EnGeldB_SetupStunned(EnGeldB* pthis) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.speedXZ = 0.0f;
    }
    if ((pthis->damageEffect != GELDB_DMG_FREEZE) || (pthis->action == GELDB_SPIN_ATTACK)) {
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gGerudoRedDamageAnim, 0.0f);
    }
    if (pthis->damageEffect == GELDB_DMG_FREEZE) {
        pthis->iceTimer = 36;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->action = GELDB_STUNNED;
    EnGeldB_SetupAction(pthis, EnGeldB_Stunned);
}

void EnGeldB_Stunned(EnGeldB* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 0.05f;
        }
        pthis->invisible = false;
    }
    if ((pthis->actor.colorFilterTimer == 0) && (pthis->actor.bgCheckFlags & 1)) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnGeldB_SetupDefeated(pthis);
        } else {
            EnGeldB_ReactToPlayer(globalCtx, pthis, 1);
        }
    }
}

void EnGeldB_SetupDamaged(EnGeldB* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gGerudoRedDamageAnim, -4.0f);
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->invisible = false;
        pthis->actor.speedXZ = -4.0f;
    } else {
        pthis->invisible = true;
    }
    pthis->lookTimer = 0;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_DAMAGE);
    pthis->action = GELDB_DAMAGED;
    EnGeldB_SetupAction(pthis, EnGeldB_Damaged);
}

void EnGeldB_Damaged(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 angleToWall;

    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 0.05f;
        }
        pthis->invisible = false;
    }
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x1194, 0);
    if (!EnGeldB_DodgeRanged(globalCtx, pthis) && !EnGeldB_ReactToPlayer(globalCtx, pthis, 0) &&
        SkelAnime_Update(&pthis->skelAnime) && (pthis->actor.bgCheckFlags & 1)) {
        angleToWall = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
        if ((pthis->actor.bgCheckFlags & 8) && (ABS(angleToWall) < 0x2EE0) && (pthis->actor.xzDistToPlayer < 90.0f)) {
            EnGeldB_SetupJump(pthis);
        } else if (!EnGeldB_DodgeRanged(globalCtx, pthis)) {
            if ((pthis->actor.xzDistToPlayer <= 45.0f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) &&
                (globalCtx->gameplayFrames & 7)) {
                EnGeldB_SetupSlash(pthis);
            } else {
                EnGeldB_SetupRollBack(pthis);
            }
        }
    }
}

void EnGeldB_SetupJump(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedFlipAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedFlipAnim, -1.0f, lastFrame, 0.0f, ANIMMODE_ONCE, -3.0f);
    pthis->timer = 0;
    pthis->invisible = false;
    pthis->action = GELDB_JUMP;
    pthis->actor.speedXZ = 6.5f;
    pthis->actor.velocity.y = 15.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnGeldB_SetupAction(pthis, EnGeldB_Jump);
}

void EnGeldB_Jump(EnGeldB* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    if (pthis->actor.velocity.y >= 5.0f) {
        func_800355B8(globalCtx, &pthis->leftFootPos);
        func_800355B8(globalCtx, &pthis->rightFootPos);
    }
    if (SkelAnime_Update(&pthis->skelAnime) && (pthis->actor.bgCheckFlags & 3)) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->actor.shape.rot.x = 0;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            EnGeldB_SetupSlash(pthis);
        } else {
            EnGeldB_SetupReady(pthis);
        }
    }
}

void EnGeldB_SetupBlock(EnGeldB* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedBlockAnim);

    if (pthis->swordState != 0) {
        pthis->swordState = -1;
    }
    pthis->actor.speedXZ = 0.0f;
    pthis->action = GELDB_BLOCK;
    pthis->timer = (s32)Rand_CenteredFloat(10.0f) + 10;
    Animation_Change(&pthis->skelAnime, &gGerudoRedBlockAnim, 0.0f, 0.0f, lastFrame, ANIMMODE_ONCE, 0.0f);
    EnGeldB_SetupAction(pthis, EnGeldB_Block);
}

void EnGeldB_Block(EnGeldB* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s16 angleToLink;
    s16 angleFacingLink;

    if (pthis->timer != 0) {
        pthis->timer--;
    } else {
        pthis->skelAnime.playSpeed = 1.0f;
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        angleToLink = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        if ((ABS(angleToLink) <= 0x4000) && (pthis->actor.xzDistToPlayer < 40.0f) &&
            (ABS(pthis->actor.yDistToPlayer) < 50.0f)) {
            if (func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x2710, 0x4000, pthis->actor.shape.rot.y)) {
                if (player->swordAnimation == 0x11) {
                    EnGeldB_SetupSpinDodge(pthis, globalCtx);
                } else if (globalCtx->gameplayFrames & 1) {
                    EnGeldB_SetupBlock(pthis);
                } else {
                    EnGeldB_SetupRollBack(pthis);
                }
            } else {
                angleFacingLink = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
                if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor) &&
                    ((globalCtx->gameplayFrames & 1) || (ABS(angleFacingLink) < 0x38E0))) {
                    EnGeldB_SetupSlash(pthis);
                } else {
                    EnGeldB_SetupCircle(pthis);
                }
            }
        } else {
            EnGeldB_SetupCircle(pthis);
        }
    } else if ((pthis->timer == 0) &&
               func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x2710, 0x4000, pthis->actor.shape.rot.y)) {
        if (player->swordAnimation == 0x11) {
            EnGeldB_SetupSpinDodge(pthis, globalCtx);
        } else if (!EnGeldB_DodgeRanged(globalCtx, pthis)) {
            if ((globalCtx->gameplayFrames & 1)) {
                if ((pthis->actor.xzDistToPlayer < 100.0f) && (Rand_ZeroOne() > 0.7f)) {
                    EnGeldB_SetupJump(pthis);
                } else {
                    EnGeldB_SetupRollBack(pthis);
                }
            } else {
                EnGeldB_SetupBlock(pthis);
            }
        }
    }
}

void EnGeldB_SetupSidestep(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 linkAngle;
    Player* player;
    f32 lastFrame = Animation_GetLastFrame(&gGerudoRedSidestepAnim);

    Animation_Change(&pthis->skelAnime, &gGerudoRedSidestepAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP, 0.0f);
    player = GET_PLAYER(globalCtx);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xFA0, 1);
    linkAngle = player->actor.shape.rot.y;
    if (Math_SinS(linkAngle - pthis->actor.shape.rot.y) > 0.0f) {
        pthis->actor.speedXZ = -6.0f;
    } else if (Math_SinS(linkAngle - pthis->actor.shape.rot.y) < 0.0f) {
        pthis->actor.speedXZ = 6.0f;
    } else {
        pthis->actor.speedXZ = Rand_CenteredFloat(12.0f);
    }
    pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
    pthis->approachRate = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
    pthis->timer = Rand_ZeroOne() * 10.0f + 5.0f;
    pthis->action = GELDB_SIDESTEP;
    EnGeldB_SetupAction(pthis, EnGeldB_Sidestep);
}

void EnGeldB_Sidestep(EnGeldB* pthis, GlobalContext* globalCtx) {
    s16 behindLinkAngle;
    s16 phi_v1;
    Player* player = GET_PLAYER(globalCtx);
    s32 thisKeyFrame;
    s32 prevKeyFrame;
    f32 playSpeed;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xBB8, 1);
    behindLinkAngle = player->actor.shape.rot.y + 0x8000;
    if (Math_SinS(behindLinkAngle - pthis->actor.shape.rot.y) > 0.0f) {
        pthis->actor.speedXZ += 0.125f;
    } else if (Math_SinS(behindLinkAngle - pthis->actor.shape.rot.y) <= 0.0f) {
        pthis->actor.speedXZ -= 0.125f;
    }

    if ((pthis->actor.bgCheckFlags & 8) ||
        !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ, pthis->actor.shape.rot.y + 0x3E80)) {
        if (pthis->actor.bgCheckFlags & 8) {
            if (pthis->actor.speedXZ >= 0.0f) {
                phi_v1 = pthis->actor.shape.rot.y + 0x3E80;
            } else {
                phi_v1 = pthis->actor.shape.rot.y - 0x3E80;
            }
            phi_v1 = pthis->actor.wallYaw - phi_v1;
        } else {
            pthis->actor.speedXZ *= -0.8f;
            phi_v1 = 0;
        }
        if (ABS(phi_v1) > 0x4000) {
            pthis->actor.speedXZ *= -0.8f;
            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ -= 0.5f;
            } else {
                pthis->actor.speedXZ += 0.5f;
            }
        }
    }
    if (pthis->actor.speedXZ >= 0.0f) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3E80;
    } else {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y - 0x3E80;
    }
    if (pthis->actor.xzDistToPlayer <= 45.0f) {
        Math_SmoothStepToF(&pthis->approachRate, -4.0f, 1.0f, 1.5f, 0.0f);
    } else if (pthis->actor.xzDistToPlayer > 40.0f) {
        Math_SmoothStepToF(&pthis->approachRate, 4.0f, 1.0f, 1.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->approachRate, 0.0f, 1.0f, 6.65f, 0.0f);
    }
    if (pthis->approachRate != 0.0f) {
        pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->approachRate;
        pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->approachRate;
    }
    if (ABS(pthis->approachRate) < ABS(pthis->actor.speedXZ)) {
        pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.5f;
    } else {
        pthis->skelAnime.playSpeed = -pthis->approachRate * 0.5f;
    }
    pthis->skelAnime.playSpeed = CLAMP(pthis->skelAnime.playSpeed, -3.0f, 3.0f);
    thisKeyFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);
    prevKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);

    playSpeed = ((void)0, ABS(pthis->skelAnime.playSpeed)); // Needed to match for some reason

    if (!EnGeldB_DodgeRanged(globalCtx, pthis) && !EnGeldB_ReactToPlayer(globalCtx, pthis, 0)) {
        if (--pthis->timer == 0) {
            s16 angleFacingPlayer = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

            angleFacingPlayer = ABS(angleFacingPlayer);
            if (angleFacingPlayer >= 0x3A98) {
                EnGeldB_SetupReady(pthis);
                pthis->timer = (Rand_ZeroOne() * 5.0f) + 1.0f;
            } else {
                Player* player2 = GET_PLAYER(globalCtx);
                s16 angleFacingPlayer2 = player2->actor.shape.rot.y - pthis->actor.shape.rot.y;

                pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
                if ((pthis->actor.xzDistToPlayer <= 45.0f) && !Actor_OtherIsTargeted(globalCtx, &pthis->actor) &&
                    (!(globalCtx->gameplayFrames & 3) || (ABS(angleFacingPlayer2) < 0x38E0))) {
                    EnGeldB_SetupSlash(pthis);
                } else if ((210.0f > pthis->actor.xzDistToPlayer) && (pthis->actor.xzDistToPlayer > 150.0f) &&
                           !(globalCtx->gameplayFrames & 1)) {
                    if (Actor_OtherIsTargeted(globalCtx, &pthis->actor) || (Rand_ZeroOne() > 0.5f) ||
                        (ABS(angleFacingPlayer2) < 0x38E0)) {
                        EnGeldB_SetupRollForward(pthis);
                    } else {
                        EnGeldB_SetupSpinAttack(pthis);
                    }
                } else {
                    EnGeldB_SetupAdvance(pthis, globalCtx);
                }
            }
        }
        if ((thisKeyFrame != (s32)pthis->skelAnime.curFrame) &&
            (((prevKeyFrame < 0) && (((s32)playSpeed + thisKeyFrame) > 0)) ||
             ((prevKeyFrame < 5) && (((s32)playSpeed + thisKeyFrame) > 5)))) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MUSI_LAND);
        }
        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_BREATH);
        }
    }
}

void EnGeldB_SetupDefeated(EnGeldB* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gGerudoRedDefeatAnim, -4.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->invisible = false;
        pthis->actor.speedXZ = -6.0f;
    } else {
        pthis->invisible = true;
    }
    pthis->action = GELDB_DEFEAT;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GERUDOFT_DEAD);
    EnGeldB_SetupAction(pthis, EnGeldB_Defeated);
}

void EnGeldB_Defeated(EnGeldB* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
        pthis->invisible = false;
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnGeldB_SetupFlee(pthis);
    } else if ((s32)pthis->skelAnime.curFrame == 10) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        func_800F5B58();
    }
}

void EnGeldB_TurnHead(EnGeldB* pthis, GlobalContext* globalCtx) {
    if ((pthis->action == GELDB_READY) && (pthis->lookTimer != 0)) {
        pthis->headRot.y = Math_SinS(pthis->lookTimer * 0x1068) * 8920.0f;
    } else if (pthis->action != GELDB_STUNNED) {
        if ((pthis->action != GELDB_SLASH) && (pthis->action != GELDB_SPIN_ATTACK)) {
            Math_SmoothStepToS(&pthis->headRot.y, pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y, 1, 0x1F4, 0);
            pthis->headRot.y = CLAMP(pthis->headRot.y, -0x256F, 0x256F);
        } else {
            pthis->headRot.y = 0;
        }
    }
}

void EnGeldB_CollisionCheck(EnGeldB* pthis, GlobalContext* globalCtx) {
    s32 pad;
    EnItem00* key;

    if (pthis->blockCollider.base.acFlags & AC_BOUNCED) {
        pthis->blockCollider.base.acFlags &= ~AC_BOUNCED;
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;
    } else if ((pthis->bodyCollider.base.acFlags & AC_HIT) && (pthis->action >= GELDB_READY) &&
               (pthis->spinAttackState < 2)) {
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != GELDB_DMG_UNK_6) {
            pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
            Actor_SetDropFlag(&pthis->actor, &pthis->bodyCollider.info, 1);
            Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_GERUDOFT_BREATH);
            if ((pthis->actor.colChkInfo.damageEffect == GELDB_DMG_STUN) ||
                (pthis->actor.colChkInfo.damageEffect == GELDB_DMG_FREEZE)) {
                if (pthis->action != GELDB_STUNNED) {
                    Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);
                    Actor_ApplyDamage(&pthis->actor);
                    EnGeldB_SetupStunned(pthis);
                }
            } else {
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
                if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    if (pthis->keyFlag != 0) {
                        key = Item_DropCollectible(globalCtx, &pthis->actor.world.pos, pthis->keyFlag | ITEM00_SMALL_KEY);
                        if (key != NULL) {
                            key->actor.world.rot.y = Math_Vec3f_Yaw(&key->actor.world.pos, &pthis->actor.home.pos);
                            key->actor.speedXZ = 6.0f;
                            Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &D_801333E8);
                        }
                    }
                    EnGeldB_SetupDefeated(pthis);
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                } else {
                    EnGeldB_SetupDamaged(pthis);
                }
            }
        }
    }
}

void EnGeldB_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGeldB* pthis = (EnGeldB*)thisx;

    EnGeldB_CollisionCheck(pthis, globalCtx);
    if (pthis->actor.colChkInfo.damageEffect != GELDB_DMG_UNK_6) {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 15.0f, 30.0f, 60.0f, 0x1D);
        pthis->actionFunc(pthis, globalCtx);
        pthis->actor.focus.pos = pthis->actor.world.pos;
        pthis->actor.focus.pos.y += 40.0f;
        EnGeldB_TurnHead(pthis, globalCtx);
    }
    Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    if ((pthis->action >= GELDB_READY) && (pthis->spinAttackState < 2) &&
        ((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000))) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
    }
    if ((pthis->action == GELDB_BLOCK) && (pthis->skelAnime.curFrame == 0.0f)) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->blockCollider.base);
    }
    if (pthis->swordState > 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->swordCollider.base);
    }
    if (pthis->blinkState == 0) {
        if ((Rand_ZeroOne() < 0.1f) && ((globalCtx->gameplayFrames % 4) == 0)) {
            pthis->blinkState++;
        }
    } else {
        pthis->blinkState = (pthis->blinkState + 1) & 3;
    }
}

s32 EnGeldB_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                             void* thisx) {
    EnGeldB* pthis = (EnGeldB*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_geldB.c", 2507);
    if (limbIndex == GELDB_LIMB_NECK) {
        rot->z += pthis->headRot.x;
        rot->x += pthis->headRot.y;
        rot->y += pthis->headRot.z;
    } else if (limbIndex == GELDB_LIMB_HEAD) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 80, 60, 10, 255);
    } else if ((limbIndex == GELDB_LIMB_R_SWORD) || (limbIndex == GELDB_LIMB_L_SWORD)) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 140, 170, 230, 255);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    } else {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 140, 0, 0, 255);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_geldB.c", 2529);
    return false;
}

void EnGeldB_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    Vec3f swordTip;
    Vec3f swordHilt;
    EnGeldB* pthis = (EnGeldB*)thisx;
    s32 bodyPart = -1;

    if (limbIndex == GELDB_LIMB_R_SWORD) {
        Matrix_MultVec3f(&swordQuadOffset1_111, &pthis->swordCollider.dim.quad[1]);
        Matrix_MultVec3f(&swordQuadOffset0_111, &pthis->swordCollider.dim.quad[0]);
        Matrix_MultVec3f(&swordQuadOffset3_111, &pthis->swordCollider.dim.quad[3]);
        Matrix_MultVec3f(&swordQuadOffset2_111, &pthis->swordCollider.dim.quad[2]);
        Collider_SetQuadVertices(&pthis->swordCollider, &pthis->swordCollider.dim.quad[0],
                                 &pthis->swordCollider.dim.quad[1], &pthis->swordCollider.dim.quad[2],
                                 &pthis->swordCollider.dim.quad[3]);
        Matrix_MultVec3f(&swordTipOffset_111, &swordTip);
        Matrix_MultVec3f(&swordHiltOffset_111, &swordHilt);

        if ((pthis->swordState < 0) || ((pthis->action != GELDB_SLASH) && (pthis->action != GELDB_SPIN_ATTACK))) {
            EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIndex));
            pthis->swordState = 0;
        } else if (pthis->swordState > 0) {
            EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIndex), &swordTip, &swordHilt);
        }
    } else {
        Actor_SetFeetPos(&pthis->actor, limbIndex, GELDB_LIMB_L_FOOT, &footOffset_111, GELDB_LIMB_R_FOOT, &footOffset_111);
    }

    if (limbIndex == GELDB_LIMB_L_FOOT) {
        Matrix_MultVec3f(&footOffset_111, &pthis->leftFootPos);
    } else if (limbIndex == GELDB_LIMB_R_FOOT) {
        Matrix_MultVec3f(&footOffset_111, &pthis->rightFootPos);
    }

    if (pthis->iceTimer != 0) {
        switch (limbIndex) {
            case GELDB_LIMB_NECK:
                bodyPart = 0;
                break;
            case GELDB_LIMB_L_SWORD:
                bodyPart = 1;
                break;
            case GELDB_LIMB_R_SWORD:
                bodyPart = 2;
                break;
            case GELDB_LIMB_L_UPPER_ARM:
                bodyPart = 3;
                break;
            case GELDB_LIMB_R_UPPER_ARM:
                bodyPart = 4;
                break;
            case GELDB_LIMB_TORSO:
                bodyPart = 5;
                break;
            case GELDB_LIMB_WAIST:
                bodyPart = 6;
                break;
            case GELDB_LIMB_L_FOOT:
                bodyPart = 7;
                break;
            case GELDB_LIMB_R_FOOT:
                bodyPart = 8;
                break;
            default:
                break;
        }

        if (bodyPart >= 0) {
            Vec3f limbPos;

            Matrix_MultVec3f(&zeroVec_111, &limbPos);
            pthis->bodyPartsPos[bodyPart].x = limbPos.x;
            pthis->bodyPartsPos[bodyPart].y = limbPos.y;
            pthis->bodyPartsPos[bodyPart].z = limbPos.z;
        }
    }
}

void EnGeldB_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGeldB* pthis = (EnGeldB*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_geldB.c", 2672);
    if (1) {}

    if ((pthis->spinAttackState >= 2) && SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->spinAttackState == 2) {
            Animation_Change(&pthis->skelAnime, &gGerudoRedSpinAttackAnim, 0.5f, 0.0f, 12.0f, ANIMMODE_ONCE_INTERP,
                             4.0f);
            pthis->spinAttackState++;
            thisx->world.rot.y = thisx->shape.rot.y = thisx->yawTowardsPlayer;
        } else {
            pthis->timer--;
            if (pthis->timer == 0) {
                if ((INV_CONTENT(ITEM_HOOKSHOT) == ITEM_NONE) || (INV_CONTENT(ITEM_LONGSHOT) == ITEM_NONE)) {
                    globalCtx->nextEntranceIndex = 0x1A5;
                } else if (gSaveContext.eventChkInf[12] & 0x80) {
                    globalCtx->nextEntranceIndex = 0x5F8;
                } else {
                    globalCtx->nextEntranceIndex = 0x3B4;
                }
                globalCtx->fadeTransition = 0x26;
                globalCtx->sceneLoadFlag = 0x14;
            }
        }
    }

    if ((pthis->action != GELDB_WAIT) || !pthis->invisible) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_112[pthis->blinkState]));
        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, EnGeldB_OverrideLimbDraw, EnGeldB_PostLimbDraw, pthis);
        if (pthis->action == GELDB_BLOCK) {
            s32 i;
            Vec3f blockTrisVtx0[3];
            Vec3f blockTrisVtx1[3];

            for (i = 0; i < 3; i++) {
                Matrix_MultVec3f(&blockTrisOffsets0_112[i], &blockTrisVtx0[i]);
                Matrix_MultVec3f(&blockTrisOffsets1_112[i], &blockTrisVtx1[i]);
            }
            Collider_SetTrisVertices(&pthis->blockCollider, 0, &blockTrisVtx0[0], &blockTrisVtx0[1], &blockTrisVtx0[2]);
            Collider_SetTrisVertices(&pthis->blockCollider, 1, &blockTrisVtx1[0], &blockTrisVtx1[1], &blockTrisVtx1[2]);
        }

        if (pthis->iceTimer != 0) {
            thisx->colorFilterTimer++;
            pthis->iceTimer--;
            if ((pthis->iceTimer % 4) == 0) {
                s32 iceIndex = pthis->iceTimer >> 2;

                EffectSsEnIce_SpawnFlyingVec3s(globalCtx, thisx, &pthis->bodyPartsPos[iceIndex], 150, 150, 150, 250, 235,
                                               245, 255, 1.5f);
            }
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_geldB.c", 2744);
}

s32 EnGeldB_DodgeRanged(GlobalContext* globalCtx, EnGeldB* pthis) {
    Actor* actor = Actor_GetProjectileActor(globalCtx, &pthis->actor, 800.0f);

    if (actor != NULL) {
        s16 angleToFacing;
        s16 pad18;
        f32 dist;

        angleToFacing = Actor_WorldYawTowardActor(&pthis->actor, actor) - pthis->actor.shape.rot.y;
        pthis->actor.world.rot.y = (u16)pthis->actor.shape.rot.y & 0xFFFF;
        dist = Actor_WorldDistXYZToPoint(&pthis->actor, &actor->world.pos);
        //! @bug
        // Actor_WorldDistXYZToPoint already sqrtfs the distance, so pthis actually checks for a
        // distance of 360000. Also it's a double calculation because no f on sqrt.
        if ((ABS(angleToFacing) < 0x2EE0) && (sqrt(dist) < 600.0)) {
            if (actor->id == ACTOR_ARMS_HOOK) {
                EnGeldB_SetupJump(pthis);
            } else {
                EnGeldB_SetupBlock(pthis);
            }
        } else {
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
            if ((ABS(angleToFacing) < 0x2000) || (ABS(angleToFacing) > 0x5FFF)) {
                EnGeldB_SetupSidestep(pthis, globalCtx);
                pthis->actor.speedXZ *= 3.0f;
            } else if (ABS(angleToFacing) < 0x5FFF) {
                EnGeldB_SetupRollBack(pthis);
            }
        }
        return true;
    }
    return false;
}

void EnGeldB_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    footOffset_111 = { 300.0f, 0.0f, 0.0f };

    swordTipOffset_111 = { 0.0f, -3000.0f, 0.0f };

    swordHiltOffset_111 = { 400.0f, 0.0f, 0.0f };

    swordQuadOffset1_111 = { 1600.0f, -4000.0f, 0.0f };

    swordQuadOffset0_111 = { -3000.0f, -2000.0f, 1300.0f };

    swordQuadOffset3_111 = { -3000.0f, -2000.0f, -1300.0f };

    swordQuadOffset2_111 = { 1000.0f, 1000.0f, 0.0f };

    zeroVec_111 = { 0.0f, 0.0f, 0.0f };

    En_GeldB_InitVars = {
        ACTOR_EN_GELDB,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_GELDB,
        sizeof(EnGeldB),
        (ActorFunc)EnGeldB_Init,
        (ActorFunc)EnGeldB_Destroy,
        (ActorFunc)EnGeldB_Update,
        (ActorFunc)EnGeldB_Draw,
        (ActorFunc)EnGeldB_Reset,
    };

    sBodyCylInit = {
        {
            COLTYPE_HIT5,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK1,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 50, 0, { 0, 0, 0 } },
    };

    sBlockTrisInit = {
        {
            COLTYPE_METAL,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_TRIS,
        },
        2,
        sBlockTrisElementsInit,
    };

    sSwordQuadInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, GELDB_DMG_STUN),
        /* Deku stick    */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Slingshot     */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
        /* Explosive     */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Boomerang     */ DMG_ENTRY(0, GELDB_DMG_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Hammer swing  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Hookshot      */ DMG_ENTRY(0, GELDB_DMG_STUN),
        /* Kokiri sword  */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
        /* Master sword  */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Giant's Knife */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
        /* Fire arrow    */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Ice arrow     */ DMG_ENTRY(2, GELDB_DMG_FREEZE),
        /* Light arrow   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Unk arrow 1   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Unk arrow 2   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Unk arrow 3   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Fire magic    */ DMG_ENTRY(4, GELDB_DMG_UNK_E),
        /* Ice magic     */ DMG_ENTRY(0, GELDB_DMG_UNK_6),
        /* Light magic   */ DMG_ENTRY(3, GELDB_DMG_UNK_D),
        /* Shield        */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
        /* Mirror Ray    */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
        /* Kokiri spin   */ DMG_ENTRY(1, GELDB_DMG_NORMAL),
        /* Giant spin    */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
        /* Master spin   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Kokiri jump   */ DMG_ENTRY(2, GELDB_DMG_NORMAL),
        /* Giant jump    */ DMG_ENTRY(8, GELDB_DMG_NORMAL),
        /* Master jump   */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
        /* Unknown 1     */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
        /* Unblockable   */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
        /* Hammer jump   */ DMG_ENTRY(4, GELDB_DMG_NORMAL),
        /* Unknown 2     */ DMG_ENTRY(0, GELDB_DMG_NORMAL),
    };

    sUnusedOffset = { 1100.0f, -700.0f, 0.0f };

}

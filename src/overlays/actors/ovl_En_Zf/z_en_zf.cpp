#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ZF_Z_EN_ZF_C
#include "actor_common.h"
/*
 * File: z_en_zf.c
 * Overlay: ovl_En_Zf
 * Description: Lizalfos and Dinolfos
 */

#include "z_en_zf.h"
#include "objects/object_zf/object_zf.h"
#include "def/code_800EC960.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnZf_Init(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnZf_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Update(Actor* thisx, GlobalContext* globalCtx);
void EnZf_Draw(Actor* thisx, GlobalContext* globalCtx);

s16 EnZf_FindPlatform(Vec3f* pos, s16 preferredIndex);
void EnZf_SetupDropIn(EnZf* pthis);
void EnZf_DropIn(EnZf* pthis, GlobalContext* globalCtx);
void func_80B45384(EnZf* pthis);
void func_80B4543C(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupApproachPlayer(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_ApproachPlayer(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupJumpForward(EnZf* pthis);
void EnZf_JumpForward(EnZf* pthis, GlobalContext* globalCtx);
void func_80B4604C(EnZf* pthis);
void func_80B46098(EnZf* pthis, GlobalContext* globalCtx);
void func_80B462E4(EnZf* pthis, GlobalContext* globalCtx);
void func_80B463E4(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupSlash(EnZf* pthis);
void EnZf_Slash(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_RecoilFromBlockedSlash(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupJumpBack(EnZf* pthis);
void EnZf_JumpBack(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_Stunned(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupSheatheSword(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SheatheSword(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_HopAndTaunt(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupHopAway(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_HopAway(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_DrawSword(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_Damaged(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupJumpUp(EnZf* pthis);
void EnZf_JumpUp(EnZf* pthis, GlobalContext* globalCtx);
void func_80B483E4(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_CircleAroundPlayer(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupDie(EnZf* pthis);
void EnZf_Die(EnZf* pthis, GlobalContext* globalCtx);
void EnZf_SetupCircleAroundPlayer(EnZf* pthis, f32 speed);
s32 EnZf_DodgeRangedEngaging(GlobalContext* globalCtx, EnZf* pthis);
s32 EnZf_DodgeRangedWaiting(GlobalContext* globalCtx, EnZf* pthis);

static Vec3f sUnused_144 = { 1100.0f, -700.0f, 0.0f };

static Vec3f footOffset_144 = { 300.0f, 0.0f, 0.0f };

static Vec3f D_80B4A2A4_144 = { 300.0f, -1700.0f, 0.0f };

static Vec3f D_80B4A2B0_144 = { -600.0f, 300.0f, 0.0f };

static Vec3f swordQuadOffset1_144 = { 0.0f, 1500.0f, 0.0f };

static Vec3f swordQuadOffset0_144 = { -600.0f, -3000.0f, 1000.0f };

static Vec3f swordQuadOffset3_144 = { -600.0f, -3000.0f, -1000.0f };

static Vec3f swordQuadOffset2_144 = { 1500.0f, -3000.0f, 0.0f };

static Vec3f zeroVec_144 = { 0.0f, 0.0f, 0.0f };


#define PLATFORM_INDEX_DOWNSTAIRS_MIN 0
#define PLATFORM_INDEX_DOWNSTAIRS_INNER_MAX 5
#define PLATFORM_INDEX_DOWNSTAIRS_MAX 7
#define PLATFORM_INDEX_UPSTAIRS_MIN (PLATFORM_INDEX_DOWNSTAIRS_MAX + 1)
#define PLATFORM_INDEX_UPSTAIRS_INNER_MAX 15

/**
 * Array of platform positions in Dodongo's Cavern miniboss room.
 *  0 -  7 : Downstairs
 *  8 - 15 : Upstairs inner platforms
 * 16 - 23 : Upstairs outer platforms (including several points on the long thin one)
 */
static Vec3f sPlatformPositions[] = {
    // Downstairs
    { 3560.0f, 100.0f, -1517.0f },
    { 3170.0f, 100.0f, -1767.0f },
    { 3165.0f, 100.0f, -2217.0f },
    { 3563.0f, 100.0f, -2437.0f },
    { 3946.0f, 100.0f, -2217.0f },
    { 3942.0f, 100.0f, -1765.0f },
    // Westmost downstairs two
    { 2861.0f, 100.0f, -2394.0f },
    { 2776.0f, 100.0f, -1987.0f },

    // Upstairs inner
    { 4527.0f, 531.0f, -1146.0f },
    { 4442.0f, 531.0f, -1405.0f },
    { 4170.0f, 531.0f, -1395.0f },
    { 4030.0f, 531.0f, -1162.0f },
    { 4010.0f, 531.0f, -883.0f },
    { 4270.0f, 531.0f, -810.0f },
    { 4520.0f, 531.0f, -880.0f },
    { 4260.0f, 531.0f, -1035.0f },

    // Upstairs outer
    { 4757.0f, 531.0f, -1146.0f },
    { 3850.0f, 531.0f, -883.0f },
    { 4380.0f, 531.0f, -690.0f },
    { 4197.0f, 531.0f, -646.0f },
    { 4070.0f, 531.0f, -1575.0f },
    { 3930.0f, 531.0f, -1705.0f },
    { 3780.0f, 531.0f, -1835.0f },
    { 3560.0f, 531.0f, -1985.0f },
};

// These seem to relate to the tagging in/out the minibosses do
static s16 D_80B4A1B0 = 0;
static s16 D_80B4A1B4 = 1;

ActorInit En_Zf_InitVars = {
    ACTOR_EN_ZF,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ZF,
    sizeof(EnZf),
    (ActorFunc)EnZf_Init,
    (ActorFunc)EnZf_Destroy,
    (ActorFunc)EnZf_Update,
    (ActorFunc)EnZf_Draw,
    (ActorFunc)EnZf_Reset,
};

static ColliderCylinderInit sBodyCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
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
    { 20, 70, 0, { 0, 0, 0 } },
};

static ColliderQuadInit sSwordQuadInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
    /* Deku stick    */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(1, ENZF_DMGEFF_PROJECTILE),
    /* Explosive     */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, ENZF_DMGEFF_NONE),
    /* Master sword  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Giant's Knife */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
    /* Fire arrow    */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
    /* Ice arrow     */ DMG_ENTRY(4, ENZF_DMGEFF_ICE),
    /* Light arrow   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
    /* Unk arrow 1   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
    /* Unk arrow 2   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
    /* Unk arrow 3   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
    /* Fire magic    */ DMG_ENTRY(0, ENZF_DMGEFF_IMMUNE),
    /* Ice magic     */ DMG_ENTRY(3, ENZF_DMGEFF_ICE),
    /* Light magic   */ DMG_ENTRY(0, ENZF_DMGEFF_IMMUNE),
    /* Shield        */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, ENZF_DMGEFF_NONE),
    /* Giant spin    */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
    /* Master spin   */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Kokiri jump   */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
    /* Giant jump    */ DMG_ENTRY(8, ENZF_DMGEFF_NONE),
    /* Master jump   */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
    /* Unknown 1     */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 15, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -3500, ICHAIN_STOP),
};

static AnimationHeader* sHoppingAnims[] = { &gZfHopCrouchingAnim, &gZfHopLeapingAnim, &gZfHopLandingAnim };

static s32 D_80B4AB30; // Set to 0 and incremented in EnZf_HopAway, but not actually used

void EnZf_SetupAction(EnZf* pthis, EnZfActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

/**
 * Tests if it will still be on a floor after moving forwards a distance determined by dist, in the shape forward
 * direction. If `dist` is 0, it defaults to a dist depending on speed direction, and params.
 */
s32 EnZf_PrimaryFloorCheck(EnZf* pthis, GlobalContext* globalCtx, f32 dist) {
    s16 ret;
    s16 curBgCheckFlags;
    f32 sin;
    f32 cos;
    Vec3f curPos;

    if (dist == 0.0f) {
        dist = ((pthis->actor.speedXZ >= 0.0f) ? 1.0f : -1.0f);
        dist = ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) ? dist * 45.0f : dist * 30.0f);
    }

    // Save currents to restore later
    curPos = pthis->actor.world.pos;
    curBgCheckFlags = pthis->actor.bgCheckFlags;

    sin = Math_SinS(pthis->actor.world.rot.y) * dist;
    cos = Math_CosS(pthis->actor.world.rot.y) * dist;

    pthis->actor.world.pos.x += sin;
    pthis->actor.world.pos.z += cos;

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 0x1C);
    pthis->actor.world.pos = curPos;
    ret = !(pthis->actor.bgCheckFlags & 1);
    pthis->actor.bgCheckFlags = curBgCheckFlags;
    return ret;
}

/**
 * Supplementary floor test.
 */
s16 EnZf_SecondaryFloorCheck(EnZf* pthis, GlobalContext* globalCtx, f32 dist) {
    s16 ret;
    s16 curBgCheckFlags;
    f32 sin;
    f32 cos;
    Vec3f curPos;

    if ((pthis->actor.speedXZ != 0.0f) && EnZf_PrimaryFloorCheck(pthis, globalCtx, pthis->actor.speedXZ)) {
        return true;
    }

    // Save currents to restore later
    curPos = pthis->actor.world.pos;
    curBgCheckFlags = pthis->actor.bgCheckFlags;

    sin = Math_SinS(pthis->actor.shape.rot.y) * dist;
    cos = Math_CosS(pthis->actor.shape.rot.y) * dist;

    pthis->actor.world.pos.x += sin;
    pthis->actor.world.pos.z += cos;

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 0x1C);
    pthis->actor.world.pos = curPos;
    ret = !(pthis->actor.bgCheckFlags & 1);
    pthis->actor.bgCheckFlags = curBgCheckFlags;
    return ret;
}

void EnZf_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnZf* pthis = (EnZf*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    EffectBlureInit1 blureInit;
    f32 posDiff;

    Actor_ProcessInitChain(thisx, sInitChain);
    thisx->targetMode = 3;
    pthis->clearFlag = (thisx->params & 0xFF00) >> 8;
    /* Strip the top byte of params */
    thisx->params &= 0xFF;

    /* Return the params to their original value if they were originally negative, i.e. 0xFFFF or 0xFFFE */
    if (thisx->params & 0x80) {
        thisx->params |= 0xFF00;
    }

    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawFeet, 90.0f);
    pthis->unk_3E0 = 0;
    thisx->colChkInfo.mass = MASS_HEAVY;
    thisx->colChkInfo.damageTable = &sDamageTable;

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

    Actor_UpdateBgCheckInfo(globalCtx, thisx, 75.0f, 45.0f, 45.0f, 0x1D);

    pthis->alpha = 255;
    thisx->colChkInfo.cylRadius = 40;
    thisx->colChkInfo.cylHeight = 100;
    Collider_InitCylinder(globalCtx, &pthis->bodyCollider);
    Collider_SetCylinder(globalCtx, &pthis->bodyCollider, thisx, &sBodyCylinderInit);
    Collider_InitQuad(globalCtx, &pthis->swordCollider);
    Collider_SetQuad(globalCtx, &pthis->swordCollider, thisx, &sSwordQuadInit);

    if (thisx->params == ENZF_TYPE_DINOLFOS) {
        thisx->colChkInfo.health = 12;
        thisx->naviEnemyId = 0x10;
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gZfDinolfosSkel, &gZfCryingAnim, pthis->jointTable,
                       pthis->morphTable, ENZF_LIMB_MAX);
    } else { // Lizalfos
        thisx->colChkInfo.health = 6;
        thisx->naviEnemyId = 0x0F;
        SkelAnime_Init(globalCtx, &pthis->skelAnime, &gZfLizalfosSkel, &gZfCryingAnim, pthis->jointTable,
                       pthis->morphTable, ENZF_LIMB_MAX);
    }

    if (thisx->params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // Not minibosses
        pthis->homePlatform = pthis->curPlatform = -1;
        D_80B4A1B4 = -1;
        pthis->hopAnimIndex = 1;
        if (thisx->params == ENZF_TYPE_LIZALFOS_LONE) {
            EnZf_SetupDropIn(pthis);
        } else { // Dinolfos
            func_80B45384(pthis);
        }
    } else { // Minibosses
        posDiff = player->actor.world.pos.y - thisx->world.pos.y;

        if ((ABS(posDiff) <= 100.0f) && !Flags_GetSwitch(globalCtx, pthis->clearFlag)) {
            pthis->homePlatform = pthis->curPlatform = EnZf_FindPlatform(&thisx->world.pos, 0);
            EnZf_SetupDropIn(pthis);
            D_80B4A1B4 = 1;
        } else {
            Actor_Kill(thisx);
        }
    }
}

void EnZf_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnZf* pthis = (EnZf*)thisx;

    if ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* miniboss */ &&
        (Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_ZF, ACTORCAT_ENEMY, 10000.0f) == NULL)) {
        func_800F5B58();
    }

    Effect_Delete(globalCtx, pthis->blureIndex);
    Collider_DestroyCylinder(globalCtx, &pthis->bodyCollider);
    Collider_DestroyQuad(globalCtx, &pthis->swordCollider);
}

/**
 * Finds the index of the platform position in `sPlatformPositions` that is sufficiently close to `pos`.
 * Returns `preferedIndex` if the associated position is close enough.
 */
s16 EnZf_FindPlatform(Vec3f* pos, s16 preferredIndex) {
    f32 rangeXZ;
    s16 i;

    rangeXZ = 210.0f;

    // Upstairs has a smaller range
    if (pos->y >= 420.0f) {
        rangeXZ = 110.0f;
    }

    if (preferredIndex != -1) {
        i = preferredIndex;
        if (((sPlatformPositions[i].y - 150.0f) <= pos->y) && (pos->y <= (sPlatformPositions[i].y + 150.0f)) &&
            ((sPlatformPositions[i].x - rangeXZ) <= pos->x) && (pos->x <= (sPlatformPositions[i].x + rangeXZ)) &&
            ((sPlatformPositions[i].z - rangeXZ) <= pos->z) && (pos->z <= (sPlatformPositions[i].z + rangeXZ))) {
            return preferredIndex;
        }
    }

    for (i = ARRAY_COUNT(sPlatformPositions) - 1; i > -1; i--) {
        if (((sPlatformPositions[i].y - 150.0f) <= pos->y) && (pos->y <= (sPlatformPositions[i].y + 150.0f)) &&
            ((sPlatformPositions[i].x - rangeXZ) <= pos->x) && (pos->x <= (sPlatformPositions[i].x + rangeXZ)) &&
            ((sPlatformPositions[i].z - rangeXZ) <= pos->z) && (pos->z <= (sPlatformPositions[i].z + rangeXZ))) {
            break;
        }
    }
    return i;
}

s16 EnZf_FindNextPlatformAwayFromPlayer(Vec3f* pos, s16 curPlatform, s16 arg2, GlobalContext* globalCtx) {
    f32 distToCurLoopPlatform;
    f32 platformMinDist = 585.0f;
    Player* player = GET_PLAYER(globalCtx);
    s16 initialPlatform = curPlatform;
    f32 playerMaxDist = 400.0f;
    f32 smallMaxRange = 99998.0f;
    s16 curLoopPlatform = PLATFORM_INDEX_DOWNSTAIRS_INNER_MAX; // Will never retreat to the last two
    s16 minIndex = PLATFORM_INDEX_DOWNSTAIRS_MIN;
    f32 largeMaxRange = 99999.0f;
    s16 altNextPlatform = -1;
    s16 nextPlatform = -1;
    s16 playerPlatform = EnZf_FindPlatform(&player->actor.world.pos, initialPlatform);

    // Set up search constraints
    // Upstairs
    if (pos->y > 420.0f) {
        minIndex = PLATFORM_INDEX_UPSTAIRS_MIN;
        playerMaxDist = 50.0f;

        // Upstairs outer
        if (initialPlatform >= PLATFORM_INDEX_UPSTAIRS_INNER_MAX) {
            curLoopPlatform = ARRAY_COUNT(sPlatformPositions) - 1;
            platformMinDist = 400.0f;
        } else { // upstairs inner
            curLoopPlatform = PLATFORM_INDEX_UPSTAIRS_INNER_MAX - 1;
            platformMinDist = 380.0f;
        }
    }

    for (; curLoopPlatform >= minIndex; curLoopPlatform--) {
        if ((curLoopPlatform == initialPlatform) || (curLoopPlatform == playerPlatform)) {
            continue;
        }
        if ((playerPlatform == -1) &&
            (Math_Vec3f_DistXYZ(&player->actor.world.pos, &sPlatformPositions[curLoopPlatform]) < playerMaxDist)) {
            continue;
        }
        distToCurLoopPlatform = Math_Vec3f_DistXYZ(pos, &sPlatformPositions[curLoopPlatform]);

        if (platformMinDist < distToCurLoopPlatform) {
            continue;
        }
        if (distToCurLoopPlatform < smallMaxRange) {
            largeMaxRange = smallMaxRange;
            altNextPlatform = nextPlatform;
            smallMaxRange = distToCurLoopPlatform;
            nextPlatform = curLoopPlatform;
        } else if (distToCurLoopPlatform < largeMaxRange) {
            largeMaxRange = distToCurLoopPlatform;
            altNextPlatform = curLoopPlatform;
        }
    }

    // These functions have no side effects, so these two calls do nothing
    Math_Vec3f_DistXYZ(&player->actor.world.pos, &sPlatformPositions[nextPlatform]);
    Math_Vec3f_DistXYZ(&player->actor.world.pos, &sPlatformPositions[altNextPlatform]);

    if (altNextPlatform > 0) {
        s16 nextPlatformToPlayerYaw =
            Math_Vec3f_Yaw(pos, &sPlatformPositions[nextPlatform]) - Math_Vec3f_Yaw(pos, &player->actor.world.pos);

        if (ABS(nextPlatformToPlayerYaw) < 0x36B0) {
            nextPlatform = altNextPlatform;
        }
    }

    if (nextPlatform < 0) {
        nextPlatform = arg2;
    }
    return nextPlatform;
}

s16 EnZf_FindNextPlatformTowardsPlayer(Vec3f* pos, s16 curPlatform, s16 arg2, GlobalContext* globalCtx) {
    s16 curLoopPlatform = PLATFORM_INDEX_DOWNSTAIRS_MAX;
    s16 minIndex = PLATFORM_INDEX_DOWNSTAIRS_MIN;
    Player* player = GET_PLAYER(globalCtx);
    s16 nextPlatform = EnZf_FindPlatform(&player->actor.world.pos, -1);
    f32 minRange = 500.0f;
    f32 smallMaxRange = 99998.0f;
    f32 largeMaxRange = 99999.0f;
    s16 phi_s2 = curPlatform;
    s16 phi_s3 = arg2;

    // Upstairs
    if (pos->y > 200.0f) {
        curLoopPlatform = ARRAY_COUNT(sPlatformPositions) - 1;
        minIndex = PLATFORM_INDEX_UPSTAIRS_MIN;
        minRange = 290.0f;
    }

    for (; curLoopPlatform >= minIndex; curLoopPlatform--) {
        if (minRange < Math_Vec3f_DistXYZ(pos, &sPlatformPositions[curLoopPlatform])) {
            continue;
        }
        if (curLoopPlatform != nextPlatform) {
            f32 curPlatformDistToPlayer =
                Math_Vec3f_DistXYZ(&player->actor.world.pos, &sPlatformPositions[curLoopPlatform]);

            if (curPlatformDistToPlayer < smallMaxRange) {
                largeMaxRange = smallMaxRange;
                phi_s3 = phi_s2;
                smallMaxRange = curPlatformDistToPlayer;
                phi_s2 = curLoopPlatform;
            } else if (curPlatformDistToPlayer < largeMaxRange) {
                largeMaxRange = curPlatformDistToPlayer;
                phi_s3 = curLoopPlatform;
            }
        } else {
            phi_s2 = nextPlatform;
            break;
        }
    }

    if (phi_s3 != nextPlatform) {
        nextPlatform = phi_s2;
    } else {
        nextPlatform = phi_s3;
    }

    return nextPlatform;
}

// Player not targeting pthis or another EnZf?
s32 EnZf_CanAttack(GlobalContext* globalCtx, EnZf* pthis) {
    Actor* targetedActor;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
        if (player->stateFlags1 & 0x6000) {                    // Hanging or climbing
            return false;
        } else {
            return true;
        }
    } else {
        if (!Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            return true;
        }
        if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
            targetedActor = player->unk_664;
            if (targetedActor == NULL) {
                return false;
            } else {
                if (targetedActor->category != ACTORCAT_ENEMY) {
                    return true;
                }
                if (targetedActor->id != ACTOR_EN_ZF) {
                    return false;
                } else if (targetedActor->colorFilterTimer != 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

void func_80B44DC4(EnZf* pthis, GlobalContext* globalCtx) {
    s16 angleDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (angleDiff < 0) {
        angleDiff = -angleDiff;
    }

    if (angleDiff >= 0x1B58) {
        func_80B483E4(pthis, globalCtx);
    } else if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 8) != 0) &&
               EnZf_CanAttack(globalCtx, pthis)) {
        EnZf_SetupSlash(pthis);
    } else {
        func_80B45384(pthis);
    }
}

s32 EnZf_ChooseAction(GlobalContext* globalCtx, EnZf* pthis) {
    s16 angleToWall;
    Actor* explosive;

    angleToWall = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
    angleToWall = ABS(angleToWall);

    if (func_800354B4(globalCtx, &pthis->actor, 100.0f, 0x5DC0, 0x2AA8, pthis->actor.shape.rot.y)) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

        if ((pthis->actor.bgCheckFlags & 8) && (ABS(angleToWall) < 0x2EE0) && (pthis->actor.xzDistToPlayer < 80.0f)) {
            EnZf_SetupJumpUp(pthis);
            return true;
        } else if ((pthis->actor.xzDistToPlayer < 90.0f) && ((globalCtx->gameplayFrames % 2) != 0)) {
            EnZf_SetupJumpUp(pthis);
            return true;
        } else {
            EnZf_SetupJumpBack(pthis);
            return true;
        }
    }

    explosive = Actor_FindNearby(globalCtx, &pthis->actor, -1, ACTORCAT_EXPLOSIVE, 80.0f);

    if (explosive != NULL) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
        if (((pthis->actor.bgCheckFlags & 8) && (angleToWall < 0x2EE0)) || (explosive->id == ACTOR_EN_BOM_CHU)) {
            if ((explosive->id == ACTOR_EN_BOM_CHU) && (Actor_WorldDistXYZToActor(&pthis->actor, explosive) < 80.0f) &&
                ((s16)((pthis->actor.shape.rot.y - explosive->world.rot.y) + 0x8000) < 0x3E80)) {
                EnZf_SetupJumpUp(pthis);
                return true;
            } else {
                EnZf_SetupCircleAroundPlayer(pthis, 4.0f);
                return true;
            }
        } else {
            EnZf_SetupJumpBack(pthis);
            return true;
        }
    }
    return false;
}

// Setup functions and action functions

/**
 * Set position 300 units above ground and invisible, fade in and drop to ground, fully solid when on ground
 */
void EnZf_SetupDropIn(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfJumpingAnim, 0.0f, 9.0f, Animation_GetLastFrame(&gZfJumpingAnim),
                     ANIMMODE_LOOP, 0.0f);

    pthis->actor.world.pos.y = pthis->actor.floorHeight + 300.0f;
    pthis->alpha = pthis->actor.shape.shadowAlpha = 0;
    pthis->unk_3F0 = 10;
    pthis->hopAnimIndex = 1;
    pthis->action = ENZF_ACTION_DROP_IN;
    pthis->actor.bgCheckFlags &= ~2;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    EnZf_SetupAction(pthis, EnZf_DropIn);
}

void EnZf_DropIn(EnZf* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_3F0 == 1) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        pthis->actor.flags |= ACTOR_FLAG_0;

        if (pthis->actor.params == ENZF_TYPE_LIZALFOS_MINIBOSS_A) {
            func_800F5ACC(0x38); // Miniboss theme
        }
    }

    if (pthis->unk_3F0 != 0) {
        if (pthis->actor.params != ENZF_TYPE_LIZALFOS_LONE) {
            pthis->unk_3F0--;
        } else if (pthis->actor.xzDistToPlayer <= 160.0f) {
            pthis->unk_3F0 = 0;
            pthis->actor.flags |= ACTOR_FLAG_0;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        }

        pthis->actor.world.pos.y = pthis->actor.floorHeight + 300.0f;
    } else if (pthis->alpha < 255) {
        pthis->alpha += 255 / 5;
    }

    if ((pthis->actor.bgCheckFlags & 3) && (pthis->hopAnimIndex != 0)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_ONGND);
        Animation_Change(&pthis->skelAnime, &gZfLandingAnim, 1.0f, 0.0f, 17.0f, ANIMMODE_ONCE, 0.0f);
        pthis->hopAnimIndex = 0;
        pthis->actor.bgCheckFlags &= ~2;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->actor.velocity.y = 0.0f;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->alpha = 255;
        if (pthis->actor.params > ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // Only miniboss B
            EnZf_SetupSheatheSword(pthis, globalCtx);
        } else {
            func_80B45384(pthis);
        }
    }
    pthis->actor.shape.shadowAlpha = pthis->alpha;
}

// stop? and choose an action
void func_80B45384(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfCryingAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gZfCryingAnim),
                     ANIMMODE_LOOP_INTERP, -4.0f);
    pthis->action = ENZF_ACTION_3;
    pthis->unk_3F0 = Rand_ZeroOne() * 10.0f + 5.0f;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnZf_SetupAction(pthis, func_80B4543C);
}

void func_80B4543C(EnZf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s16 angleToPlayer = (pthis->actor.yawTowardsPlayer - pthis->headRot) - pthis->actor.shape.rot.y;

    angleToPlayer = ABS(angleToPlayer);
    SkelAnime_Update(&pthis->skelAnime);

    if (!EnZf_DodgeRangedEngaging(globalCtx, pthis)) {
        if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
            if (pthis->unk_3F4 != 0) {
                pthis->unk_3F4--;
                if (angleToPlayer >= 0x1FFE) {
                    return;
                }
                pthis->unk_3F4 = 0;

            } else if (EnZf_ChooseAction(globalCtx, pthis)) {
                return;
            }
        }
        angleToPlayer = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
        angleToPlayer = ABS(angleToPlayer);

        if ((pthis->actor.xzDistToPlayer < 100.0f) && (player->swordState != 0) && (angleToPlayer >= 0x1F40)) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            func_80B483E4(pthis, globalCtx);
        } else if (pthis->unk_3F0 != 0) {
            pthis->unk_3F0--;
        } else {
            if (Actor_IsFacingPlayer(&pthis->actor, 30 * 0x10000 / 360)) {
                if ((pthis->actor.xzDistToPlayer < 200.0f) && (pthis->actor.xzDistToPlayer > 100.0f) &&
                    (Rand_ZeroOne() < 0.3f)) {
                    if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
                        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
                        EnZf_SetupJumpForward(pthis);
                    } else {
                        func_80B483E4(pthis, globalCtx);
                    }
                } else if (Rand_ZeroOne() > 0.3f) {
                    EnZf_SetupApproachPlayer(pthis, globalCtx);
                } else {
                    func_80B483E4(pthis, globalCtx);
                }
            } else {
                func_80B4604C(pthis);
            }

            if ((globalCtx->gameplayFrames & 0x5F) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
            }
        }
    }
}

void EnZf_SetupApproachPlayer(EnZf* pthis, GlobalContext* globalCtx) {
    Animation_MorphToLoop(&pthis->skelAnime, &gZfWalkingAnim, -4.0f);
    pthis->action = ENZF_ACTION_APPROACH_PLAYER;

    if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
        pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
        pthis->nextPlatform = EnZf_FindNextPlatformTowardsPlayer(&pthis->actor.world.pos, pthis->curPlatform,
                                                                pthis->homePlatform, globalCtx);
        pthis->hopAnimIndex = 0;
    }
    pthis->actor.speedXZ = 0.0f;
    EnZf_SetupAction(pthis, EnZf_ApproachPlayer);
}

void EnZf_ApproachPlayer(EnZf* pthis, GlobalContext* globalCtx) {
    s32 sp54;
    s32 sp50;
    s32 temp;
    s16 temp_v1;
    s16 sp48 = -1;
    f32 sp44 = 350.0f;
    f32 sp40 = 0.0f;
    Player* player = GET_PLAYER(globalCtx);
    s32 sp30;

    if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
        sp48 = EnZf_FindPlatform(&player->actor.world.pos, sp48);
        pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, sp48);

        if (pthis->actor.world.pos.y >= 420.0f) {
            sp44 = 270.0f;
        }
    }

    if (!EnZf_DodgeRangedEngaging(globalCtx, pthis)) {
        if (sp48 != pthis->curPlatform) {
            pthis->nextPlatform = EnZf_FindNextPlatformTowardsPlayer(&pthis->actor.world.pos, pthis->curPlatform,
                                                                    pthis->homePlatform, globalCtx);

            if ((sp48 < 0) && (pthis->nextPlatform == pthis->curPlatform)) {
                sp48 = pthis->curPlatform;
                pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
            } else {
                pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer =
                    Actor_WorldYawTowardPoint(&pthis->actor, &sPlatformPositions[pthis->nextPlatform]);

                temp_v1 = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
                temp_v1 = ABS(temp_v1);

                if ((pthis->unk_3F8 && (pthis->actor.speedXZ > 0.0f)) ||
                    ((pthis->actor.bgCheckFlags & 8) && (temp_v1 >= 0x5C19))) {
                    if ((Actor_WorldDistXZToPoint(&pthis->actor, &sPlatformPositions[pthis->nextPlatform]) < sp44) &&
                        !EnZf_PrimaryFloorCheck(pthis, globalCtx, 191.9956f)) {
                        EnZf_SetupJumpForward(pthis);

                        if (pthis->actor.bgCheckFlags & 8) {
                            pthis->actor.velocity.y = 20.0f;
                        }

                        return;
                    } else {
                        pthis->actor.world.rot.y =
                            Actor_WorldYawTowardPoint(&pthis->actor, &sPlatformPositions[pthis->curPlatform]);
                    }
                } else {
                    pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                    Math_SmoothStepToF(&pthis->actor.speedXZ, 8.0f, 1.0f, 1.5f, 0.0f);
                }
            }
        }

        if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            sp40 = 100.0f;
        }

        if (pthis->actor.xzDistToPlayer <= (70.0f + sp40)) {
            Math_SmoothStepToF(&pthis->actor.speedXZ, -8.0f, 1.0f, 0.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&pthis->actor.speedXZ, 8.0f, 1.0f, 0.5f, 0.0f);
        }

        pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 1.2f;

        temp_v1 = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
        temp_v1 = ABS(temp_v1);

        if ((sp48 == pthis->curPlatform) && (pthis->actor.xzDistToPlayer < 150.0f) && (player->swordState != 0) &&
            (temp_v1 >= 0x1F40)) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

            if (Rand_ZeroOne() > 0.7f) {
                func_80B483E4(pthis, globalCtx);
                return;
            }
        }

        sp54 = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);
        sp50 = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        sp30 = (f32)ABS(pthis->skelAnime.playSpeed);

        if (sp48 == pthis->curPlatform) {
            if (!Actor_IsFacingPlayer(&pthis->actor, 0x11C7)) {
                if (Rand_ZeroOne() > 0.5f) {
                    func_80B462E4(pthis, globalCtx);
                } else {
                    func_80B45384(pthis);
                }
            } else if (pthis->actor.xzDistToPlayer < 100.0f) {
                if ((Rand_ZeroOne() > 0.05f) && EnZf_CanAttack(globalCtx, pthis)) {
                    EnZf_SetupSlash(pthis);
                } else if (Rand_ZeroOne() > 0.5f) {
                    func_80B483E4(pthis, globalCtx);
                } else {
                    func_80B45384(pthis);
                }
            } else {
                if (pthis->unk_3F8) {
                    func_80B462E4(pthis, globalCtx);
                } else if (Rand_ZeroOne() < 0.1f) {
                    func_80B45384(pthis);
                }
            }
        }

        if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
            if (EnZf_ChooseAction(globalCtx, pthis)) {
                return;
            }

            if ((pthis->actor.xzDistToPlayer < 180.0f) && (pthis->actor.xzDistToPlayer > 160.0f) &&
                Actor_IsFacingPlayer(&pthis->actor, 0x71C)) {
                if (Actor_IsTargeted(globalCtx, &pthis->actor)) {
                    if (Rand_ZeroOne() < 0.1f) {
                        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
                        EnZf_SetupJumpForward(pthis);
                        return;
                    }
                } else {
                    func_80B483E4(pthis, globalCtx);
                    return;
                }
            }
        }

        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        }

        if (sp54 != (s32)pthis->skelAnime.curFrame) {
            temp = sp30 + sp54;

            if (((sp50 < 2) && (temp >= 4)) || ((sp50 < 32) && (temp >= 34))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
            }
        }
    }
}

void EnZf_SetupJumpForward(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfJumpingAnim, 1.0f, 0.0f, 3.0f, ANIMMODE_ONCE, -3.0f);
    pthis->unk_3F0 = 0;
    pthis->hopAnimIndex = 1;
    pthis->actor.velocity.y = 15.0f;

    if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
        pthis->actor.speedXZ = 16.0f;
    } else {
        pthis->actor.speedXZ = 10.0f;
    }

    pthis->action = ENZF_ACTION_JUMP_FORWARD;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_JUMP);
    EnZf_SetupAction(pthis, EnZf_JumpForward);
}

void EnZf_JumpForward(EnZf* pthis, GlobalContext* globalCtx) {
    if ((pthis->unk_3F0 != 0) && (pthis->actor.world.pos.y <= pthis->actor.floorHeight)) {
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->hopAnimIndex = 0;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->unk_3F0 == 0) {
            Animation_Change(&pthis->skelAnime, &gZfLandingAnim, 3.0f, 0.0f, 17.0f, ANIMMODE_ONCE, -3.0f);
            pthis->unk_3F0 = 10;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_JUMP);
        } else {
            pthis->actor.speedXZ = 0.0f;
            pthis->hopAnimIndex = 0;
            EnZf_SetupApproachPlayer(pthis, globalCtx);
        }
    }
    if ((globalCtx->gameplayFrames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
    }

    if ((pthis->actor.params == ENZF_TYPE_DINOLFOS) && (pthis->actor.bgCheckFlags & 3)) {
        if (EnZf_CanAttack(globalCtx, pthis)) {
            EnZf_SetupSlash(pthis);
        } else {
            func_80B483E4(pthis, globalCtx);
        }
    }
}

void func_80B4604C(EnZf* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gZfWalkingAnim, -4.0f);
    pthis->action = ENZF_ACTION_6;
    EnZf_SetupAction(pthis, func_80B46098);
}

void func_80B46098(EnZf* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 phi_f2;
    Player* player = GET_PLAYER(globalCtx);
    s16 temp_v0;
    s16 phi_v1;

    if (!EnZf_DodgeRangedEngaging(globalCtx, pthis)) {
        if ((pthis->actor.params != ENZF_TYPE_DINOLFOS) || !EnZf_ChooseAction(globalCtx, pthis)) {
            temp_v0 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

            if (temp_v0 > 0) {
                phi_v1 = temp_v0 * 0.25f + 2000.0f;
            } else {
                phi_v1 = temp_v0 * 0.25f - 2000.0f;
            }

            pthis->actor.shape.rot.y += phi_v1;
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

            if (temp_v0 > 0) {
                phi_f2 = phi_v1 * 1.5f;
                if (phi_f2 > 2.0f) {
                    phi_f2 = 2.0f;
                }
            } else {
                phi_f2 = phi_v1 * 1.5f;
                if (phi_f2 < -2.0f) {
                    phi_f2 = -2.0f;
                }
            }

            pthis->skelAnime.playSpeed = -phi_f2;
            SkelAnime_Update(&pthis->skelAnime);

            if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
                pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
                if (pthis->curPlatform != EnZf_FindPlatform(&player->actor.world.pos, -1)) {
                    EnZf_SetupApproachPlayer(pthis, globalCtx);
                    return;
                }
            }

            if (Actor_IsFacingPlayer(&pthis->actor, 30 * 0x10000 / 360)) {
                if (Rand_ZeroOne() > 0.8f) {
                    func_80B462E4(pthis, globalCtx);
                } else {
                    EnZf_SetupApproachPlayer(pthis, globalCtx);
                }
            }
            if ((globalCtx->gameplayFrames & 0x5F) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
            }
        }
    }
}

// Conditional setup function
void func_80B462E4(EnZf* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* miniboss */ ||
        Actor_TestFloorInDirection(&pthis->actor, globalCtx, 40.0f, (s16)(pthis->actor.shape.rot.y + 0x3FFF)) ||
        Actor_TestFloorInDirection(&pthis->actor, globalCtx, -40.0f, (s16)(pthis->actor.shape.rot.y + 0x3FFF))) {
        Animation_PlayLoop(&pthis->skelAnime, &gZfSidesteppingAnim);
        pthis->actor.speedXZ = Rand_CenteredFloat(12.0f);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        pthis->unk_3F0 = Rand_ZeroOne() * 10.0f + 20.0f;
        pthis->hopAnimIndex = 0;
        pthis->action = ENZF_ACTION_7;
        pthis->unk_408 = 0.0f;
        EnZf_SetupAction(pthis, func_80B463E4);
    } else {
        EnZf_SetupApproachPlayer(pthis, globalCtx);
    }
}

void func_80B463E4(EnZf* pthis, GlobalContext* globalCtx) {
    s16 angleBehindPlayer;
    s16 phi_v0_3;
    s32 pad;
    s32 curKeyFrame;
    s32 prevKeyFrame;
    s32 playSpeed;
    Player* player = GET_PLAYER(globalCtx);
    f32 baseRange = 0.0f;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4000, 1);

    if (!EnZf_DodgeRangedEngaging(globalCtx, pthis) &&
        ((pthis->actor.params != ENZF_TYPE_DINOLFOS) || !EnZf_ChooseAction(globalCtx, pthis))) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3A98;
        angleBehindPlayer = player->actor.shape.rot.y + 0x8000;

        if (Math_SinS(angleBehindPlayer - pthis->actor.shape.rot.y) >= 0.0f) {
            pthis->actor.speedXZ -= 0.25f;
            if (pthis->actor.speedXZ < -8.0f) {
                pthis->actor.speedXZ = -8.0f;
            }
        } else if (Math_SinS(angleBehindPlayer - pthis->actor.shape.rot.y) < 0.0f) { // Superfluous check
            pthis->actor.speedXZ += 0.25f;
            if (pthis->actor.speedXZ > 8.0f) {
                pthis->actor.speedXZ = 8.0f;
            }
        }

        if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
            if (pthis->unk_3F8) {
                pthis->actor.speedXZ = -pthis->actor.speedXZ;
            }
        } else if ((pthis->actor.bgCheckFlags & 8) ||
                   !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ,
                                               pthis->actor.shape.rot.y + 0x3FFF)) {
            if (pthis->actor.bgCheckFlags & 8) {
                if (pthis->actor.speedXZ >= 0.0f) {
                    phi_v0_3 = pthis->actor.shape.rot.y + 0x3FFF;
                } else {
                    phi_v0_3 = pthis->actor.shape.rot.y - 0x3FFF;
                }
                phi_v0_3 = pthis->actor.wallYaw - phi_v0_3;
            } else {
                pthis->actor.speedXZ *= -0.8f;
                phi_v0_3 = 0;
            }

            if (ABS(phi_v0_3) > 0x4000) {
                pthis->actor.speedXZ *= -0.8f;
                if (pthis->actor.speedXZ < 0.0f) {
                    pthis->actor.speedXZ -= 0.5f;
                } else {
                    pthis->actor.speedXZ += 0.5f;
                }
            }
        }

        if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
            baseRange = 100.0f;
        }

        if (pthis->actor.xzDistToPlayer <= (70.0f + baseRange)) {
            Math_SmoothStepToF(&pthis->unk_408, -4.0f, 1.0f, 1.5f, 0.0f);
        } else if ((90.0f + baseRange) < pthis->actor.xzDistToPlayer) {
            Math_SmoothStepToF(&pthis->unk_408, 4.0f, 1.0f, 1.5f, 0.0f);
        } else {
            Math_SmoothStepToF(&pthis->unk_408, 0.0f, 1.0f, 5.65f, 0.0f);
        }

        if ((pthis->unk_408 != 0.0f) && !EnZf_SecondaryFloorCheck(pthis, globalCtx, pthis->unk_408)) {
            pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->unk_408;
            pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->unk_408;
        }

        if (ABS(pthis->actor.speedXZ) >= ABS(pthis->unk_408)) {
            pthis->skelAnime.playSpeed = pthis->actor.speedXZ * 0.75f;
        } else if (pthis->skelAnime.playSpeed < 0.0f) {
            pthis->skelAnime.playSpeed = pthis->unk_408 * -0.75f;
        } else {
            pthis->skelAnime.playSpeed = pthis->unk_408 * 0.75f;
        }

        curKeyFrame = pthis->skelAnime.curFrame;
        SkelAnime_Update(&pthis->skelAnime);
        prevKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
        playSpeed = (f32)ABS(pthis->skelAnime.playSpeed);

        if (curKeyFrame != (s32)pthis->skelAnime.curFrame) {
            s32 nextKeyFrame = playSpeed + curKeyFrame;

            if (((prevKeyFrame < 14) && (nextKeyFrame > 15)) || ((prevKeyFrame < 27) && (nextKeyFrame > 28))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
            }
        }

        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        }

        if ((Math_CosS(angleBehindPlayer - pthis->actor.shape.rot.y) < -0.85f) || (pthis->unk_3F0 == 0)) {
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

            if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) == 0) &&
                EnZf_CanAttack(globalCtx, pthis)) {
                EnZf_SetupSlash(pthis);
            } else {
                func_80B45384(pthis);
            }
        } else if (pthis->unk_3F0 != 0) {
            pthis->unk_3F0--;
        }
    }
}

void EnZf_SetupSlash(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfSlashAnim, 1.25f, 0.0f, Animation_GetLastFrame(&gZfSlashAnim), ANIMMODE_ONCE,
                     -4.0f);

    if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
        pthis->skelAnime.playSpeed = 1.75f;
    }

    pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
    pthis->action = ENZF_ACTION_SLASH;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
    pthis->actor.speedXZ = 0.0f;
    EnZf_SetupAction(pthis, EnZf_Slash);
}

void EnZf_Slash(EnZf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 rotDiff;
    s16 yawDiff;

    pthis->actor.speedXZ = 0.0f;

    if ((s32)pthis->skelAnime.curFrame == 10) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_ATTACK);
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIndex));

        if ((pthis->actor.params == ENZF_TYPE_DINOLFOS) && !Actor_IsFacingPlayer(&pthis->actor, 5460)) {
            func_80B45384(pthis);
            pthis->unk_3F0 = Rand_ZeroOne() * 5.0f + 5.0f;
            pthis->unk_3F4 = Rand_ZeroOne() * 20.0f + 100.0f;
        } else if ((Rand_ZeroOne() > 0.7f) || (pthis->actor.xzDistToPlayer >= 120.0f)) {
            func_80B45384(pthis);
            pthis->unk_3F0 = Rand_ZeroOne() * 5.0f + 5.0f;
        } else {
            pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;

            if (Rand_ZeroOne() > 0.7f) {
                func_80B483E4(pthis, globalCtx);
            } else {
                rotDiff = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
                rotDiff = ABS(rotDiff);

                if (rotDiff <= 10000) {
                    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
                    yawDiff = ABS(yawDiff);

                    if (yawDiff > 16000) {
                        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
                        func_80B483E4(pthis, globalCtx);
                    } else if (player->stateFlags1 & 0x6010) {
                        if (pthis->actor.isTargeted) {
                            EnZf_SetupSlash(pthis);
                        } else {
                            func_80B483E4(pthis, globalCtx);
                        }
                    } else {
                        EnZf_SetupSlash(pthis);
                    }
                } else {
                    func_80B483E4(pthis, globalCtx);
                }
            }
        }
    }
}

void EnZf_SetupRecoilFromBlockedSlash(EnZf* pthis) {
    f32 frame = pthis->skelAnime.curFrame - 3.0f;

    Animation_Change(&pthis->skelAnime, &gZfSlashAnim, -1.0f, frame, 0.0f, ANIMMODE_ONCE, 0.0f);
    pthis->action = ENZF_ACTION_RECOIL_FROM_BLOCKED_SLASH;
    EnZf_SetupAction(pthis, EnZf_RecoilFromBlockedSlash);
}

void EnZf_RecoilFromBlockedSlash(EnZf* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (Rand_ZeroOne() > 0.7f) {
            func_80B45384(pthis);
        } else if ((Rand_ZeroOne() > 0.2f) && EnZf_CanAttack(globalCtx, pthis)) {
            EnZf_SetupSlash(pthis);
        } else {
            func_80B483E4(pthis, globalCtx);
        }
    }
}

void EnZf_SetupJumpBack(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfJumpingAnim, -1.0f, 3.0f, 0.0f, ANIMMODE_ONCE, -3.0f);
    pthis->unk_3F0 = 0;
    pthis->hopAnimIndex = 1;
    pthis->action = ENZF_ACTION_JUMP_BACK;
    pthis->actor.velocity.y = 15.0f;
    pthis->actor.speedXZ = -15.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_JUMP);
    EnZf_SetupAction(pthis, EnZf_JumpBack);
}

void EnZf_JumpBack(EnZf* pthis, GlobalContext* globalCtx) {
    if ((pthis->unk_3F0 != 0) && (pthis->actor.world.pos.y <= pthis->actor.floorHeight)) {
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        pthis->hopAnimIndex = 0;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->unk_3F0 == 0) {
            Animation_Change(&pthis->skelAnime, &gZfLandingAnim, 3.0f, 0.0f, 17.0f, ANIMMODE_ONCE, -3.0f);
            pthis->unk_3F0 = 10;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_JUMP);
        } else if ((globalCtx->gameplayFrames % 2) != 0) {
            func_80B483E4(pthis, globalCtx);
        } else {
            func_80B45384(pthis);
        }
    }

    if ((globalCtx->state.frames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
    }
}

void EnZf_SetupStunned(EnZf* pthis) {
    if ((pthis->actor.bgCheckFlags & 1) && ((pthis->actor.velocity.y == 0.0f) || (pthis->actor.velocity.y == -4.0f))) {
        pthis->actor.speedXZ = 0.0f;
        pthis->hopAnimIndex = 0;
    } else {
        pthis->hopAnimIndex = 1;
    }

    if (pthis->damageEffect == ENZF_DMGEFF_ICE) {
        pthis->iceTimer = 36;
    } else {
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gZfKnockedBackAnim, 0.0f);
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->action = ENZF_ACTION_STUNNED;
    EnZf_SetupAction(pthis, EnZf_Stunned);
}

void EnZf_Stunned(EnZf* pthis, GlobalContext* globalCtx) {
    s16 angleToWall;

    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 0.05f;
        }
        pthis->hopAnimIndex = 0;
    }

    if ((pthis->actor.colorFilterTimer == 0) && (pthis->actor.bgCheckFlags & 1)) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnZf_SetupDie(pthis);
        } else if ((pthis->actor.params != ENZF_TYPE_DINOLFOS) || !EnZf_ChooseAction(globalCtx, pthis)) {
            if (D_80B4A1B4 != -1) {
                func_80B44DC4(pthis, globalCtx);
            } else {
                angleToWall = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
                angleToWall = ABS(angleToWall);

                if ((pthis->actor.params == ENZF_TYPE_DINOLFOS) && (pthis->actor.bgCheckFlags & 8) &&
                    (ABS(angleToWall) < 0x2EE0) && (pthis->actor.xzDistToPlayer < 90.0f)) {
                    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
                    EnZf_SetupJumpUp(pthis);
                } else if (!EnZf_DodgeRangedEngaging(globalCtx, pthis)) {
                    if (pthis->actor.params != ENZF_TYPE_DINOLFOS) {
                        func_80B44DC4(pthis, globalCtx);
                    } else if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) != 0) &&
                               EnZf_CanAttack(globalCtx, pthis)) {
                        EnZf_SetupSlash(pthis);
                    } else {
                        func_80B44DC4(pthis, globalCtx);
                    }
                }
            }
        }
    }
}

void EnZf_SetupSheatheSword(EnZf* pthis, GlobalContext* globalCtx) {
    f32 morphFrames = 0.0f;
    f32 lastFrame = Animation_GetLastFrame(&gZfSheathingSwordAnim);

    if (pthis->action <= ENZF_ACTION_DAMAGED) {
        morphFrames = -4.0f;
    }

    Animation_Change(&pthis->skelAnime, &gZfSheathingSwordAnim, 2.0f, 0.0f, lastFrame, ANIMMODE_ONCE, morphFrames);
    pthis->action = ENZF_ACTION_SHEATHE_SWORD;
    pthis->actor.speedXZ = 0.0f;
    pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
    pthis->nextPlatform =
        EnZf_FindNextPlatformAwayFromPlayer(&pthis->actor.world.pos, pthis->curPlatform, pthis->homePlatform, globalCtx);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnZf_SetupAction(pthis, EnZf_SheatheSword);
}

void EnZf_SheatheSword(EnZf* pthis, GlobalContext* globalCtx) {
    s16 yaw = Actor_WorldYawTowardPoint(&pthis->actor, &sPlatformPositions[pthis->nextPlatform]) + 0x8000;

    Math_SmoothStepToS(&pthis->actor.world.rot.y, yaw, 1, 1000, 0);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.world.rot.y = yaw - 0x8000;
        EnZf_SetupHopAway(pthis, globalCtx);
        pthis->swordSheathed = true;
    }
}

void EnZf_SetupHopAndTaunt(EnZf* pthis) {
    pthis->hopAnimIndex = 0;
    Animation_MorphToPlayOnce(&pthis->skelAnime, sHoppingAnims[0], -4.0f);
    pthis->action = ENZF_ACTION_HOP_AND_TAUNT;
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_40C = 0.0f;
    pthis->unk_408 = 0.0f;
    EnZf_SetupAction(pthis, EnZf_HopAndTaunt);
}

void EnZf_HopAndTaunt(EnZf* pthis, GlobalContext* globalCtx) {
    f32 lastFrame;
    f32 maxDist = 400.0f;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 1, 4000, 0);

    // Upstairs
    if (pthis->actor.world.pos.y >= 420.0f) {
        maxDist = 250.0f;
    }

    // If player gets too close, run away
    if ((pthis->actor.xzDistToPlayer < maxDist) && (pthis->hopAnimIndex != 1)) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        EnZf_SetupSheatheSword(pthis, globalCtx);
    } else {
        if (pthis->hopAnimIndex != 1) {
            EnZf_DodgeRangedWaiting(globalCtx, pthis);
        }

        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->hopAnimIndex++; // move on to next animation

            // Loop back to beginning
            if (pthis->hopAnimIndex >= ARRAY_COUNT(sHoppingAnims)) {
                pthis->hopAnimIndex = 0;
            }

            if ((pthis->unk_408 != 0.0f) || (pthis->unk_40C != 0.0f)) {
                pthis->hopAnimIndex = 1;
            }

            lastFrame = Animation_GetLastFrame(sHoppingAnims[pthis->hopAnimIndex]);

            switch (pthis->hopAnimIndex) {
                case 0:
                    pthis->actor.velocity.y = 0.0f;
                    pthis->actor.world.pos.y = pthis->actor.floorHeight;
                    break;

                case 1:
                    pthis->actor.velocity.y = pthis->unk_40C + 10.0f;
                    pthis->actor.speedXZ = pthis->unk_408;
                    pthis->unk_408 = 0.0f;
                    pthis->unk_40C = 0.0f;
                    break;

                case 2:
                    pthis->actor.world.pos.y = pthis->actor.floorHeight;
                    lastFrame = 3.0f;
                    break;

                default:
                    break;
            }

            Animation_Change(&pthis->skelAnime, sHoppingAnims[pthis->hopAnimIndex], 1.5f, 0.0f, lastFrame, ANIMMODE_ONCE,
                             0.0f);
        }

        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        }
    }
}

void EnZf_SetupHopAway(EnZf* pthis, GlobalContext* globalCtx) {
    pthis->hopAnimIndex = 0;
    Animation_PlayOnce(&pthis->skelAnime, sHoppingAnims[0]);
    pthis->action = ENZF_ACTION_HOP_AWAY;
    pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
    pthis->nextPlatform =
        EnZf_FindNextPlatformAwayFromPlayer(&pthis->actor.world.pos, pthis->curPlatform, pthis->homePlatform, globalCtx);
    EnZf_SetupAction(pthis, EnZf_HopAway);
}

void EnZf_HopAway(EnZf* pthis, GlobalContext* globalCtx) {
    f32 sp74;
    f32 sp70 = 1.0f;
    f32 phi_f20 = 550.0f;
    s32 pad;
    f32 phi_f20_2;
    f32 phi_f0;
    s32 pad2;
    s16 sp5A;
    s32 sp54;
    s32 temp_v1_2;
    s32 phi_v1;

    sp74 = Actor_WorldDistXZToPoint(&pthis->actor, &sPlatformPositions[pthis->nextPlatform]);
    sp54 = pthis->hopAnimIndex;

    if ((globalCtx->gameplayFrames & 0x5F) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
    }

    // Upstairs
    if (pthis->actor.world.pos.y >= 420.0f) {
        phi_f20 = 280.0f;
    }

    sp5A = Actor_WorldYawTowardPoint(&pthis->actor, &sPlatformPositions[pthis->nextPlatform]);

    switch (pthis->hopAnimIndex) {
        case 0:
            pthis->actor.world.rot.y = sp5A;
            pthis->actor.shape.rot.y = sp5A + 0x8000;
            D_80B4AB30 = 0;
            pthis->homePlatform = pthis->curPlatform;
            temp_v1_2 = !EnZf_PrimaryFloorCheck(pthis, globalCtx, 107.0f);
            temp_v1_2 |= !EnZf_PrimaryFloorCheck(pthis, globalCtx, 220.0f) << 1;
            pthis->hopAnimIndex++;

            switch (temp_v1_2) {
                case 1:
                case 1 | 2:
                    pthis->actor.velocity.y = 12.0f;
                    if (pthis->actor.bgCheckFlags & 8) {
                        pthis->actor.velocity.y += 8.0f;
                    }

                    pthis->actor.speedXZ = 8.0f;
                    break;

                case 2:
                    pthis->actor.velocity.y = 15.0f;
                    pthis->actor.speedXZ = 20.0f;
                    break;

                default: // 0
                    phi_f20_2 = 107.0f;
                    phi_f20_2 += 10.0f;
                    phi_f0 = 8.0f;
                    phi_f0 += 1.2f;

                    for (phi_v1 = 20; phi_v1 >= 0; phi_v1--, phi_f20_2 += 10.0f, phi_f0 += 1.2f) {

                        if (!EnZf_PrimaryFloorCheck(pthis, globalCtx, phi_f20_2)) {
                            pthis->actor.speedXZ = phi_f0;
                            pthis->actor.velocity.y = 12.0f;
                            break;
                        }
                    }
                    if (pthis->actor.speedXZ == 0.0f) {
                        EnZf_SetupHopAndTaunt(pthis);
                    }
            }
            break;

        case 1:
            if ((pthis->actor.bgCheckFlags & 2) || (pthis->actor.bgCheckFlags & 1)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_ONGND);
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.world.pos.y = pthis->actor.floorHeight;
                pthis->actor.speedXZ = 0.0f;
                Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 3.0f, 2, 2.0f, 0, 0, 0);
                Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 3.0f, 2, 2.0f, 0, 0, 0);

                if (phi_f20 <= pthis->actor.xzDistToPlayer) {
                    EnZf_SetupHopAndTaunt(pthis);
                } else if (sp74 < 80.0f) {
                    pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
                    pthis->nextPlatform = EnZf_FindNextPlatformAwayFromPlayer(&pthis->actor.world.pos, pthis->curPlatform,
                                                                             pthis->homePlatform, globalCtx);
                }

                pthis->hopAnimIndex = 0;
                sp70 = 2.0f;
            } else {
                Math_SmoothStepToS(&pthis->actor.world.rot.y, sp5A, 1, 0xFA0, 0);
                pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
                D_80B4AB30++;
            }
            break;

        case 2:
            if (pthis->skelAnime.curFrame == pthis->skelAnime.endFrame) {
                pthis->hopAnimIndex = 0;
            }
            break;
    }

    if (sp54 != pthis->hopAnimIndex) {
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, sHoppingAnims[pthis->hopAnimIndex], sp70);
    }

    SkelAnime_Update(&pthis->skelAnime);
}

void EnZf_SetupDrawSword(EnZf* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnime, &gZfDrawingSwordAnim);
    pthis->actor.world.rot.y += 0x8000;
    pthis->action = ENZF_ACTION_DRAW_SWORD;
    pthis->actor.speedXZ = 0.0f;
    pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);
    pthis->nextPlatform =
        EnZf_FindNextPlatformAwayFromPlayer(&pthis->actor.world.pos, pthis->curPlatform, pthis->homePlatform, globalCtx);
    EnZf_SetupAction(pthis, EnZf_DrawSword);
}

void EnZf_DrawSword(EnZf* pthis, GlobalContext* globalCtx) {
    s16 yawTowardsPlayer = pthis->actor.yawTowardsPlayer;

    if (pthis->skelAnime.curFrame >= 26.0f) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, yawTowardsPlayer, 1, 6000, 0);
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        pthis->actor.world.rot.y = yawTowardsPlayer;
        pthis->hopAnimIndex = -1;
        func_80B45384(pthis);
    }

    if (pthis->skelAnime.curFrame == 22.0f) {
        pthis->swordSheathed = false;
    }
}

void EnZf_SetupDamaged(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfKnockedBackAnim, 1.5f, 0.0f, Animation_GetLastFrame(&gZfKnockedBackAnim),
                     ANIMMODE_ONCE, -4.0f);

    if ((pthis->actor.bgCheckFlags & 1) && ((pthis->actor.velocity.y == 0.0f) || (pthis->actor.velocity.y == -4.0f))) {
        pthis->actor.speedXZ = -4.0f;
        pthis->hopAnimIndex = 0;
    } else {
        pthis->hopAnimIndex = 1;
    }

    if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
        pthis->skelAnime.playSpeed = 4.5f;
    }

    if (pthis->actor.params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // not miniboss
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DAMAGE);
    pthis->action = ENZF_ACTION_DAMAGED;
    EnZf_SetupAction(pthis, EnZf_Damaged);
}

void EnZf_Damaged(EnZf* pthis, GlobalContext* globalCtx) {
    s16 wallYawDiff;

    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ += 0.05f;
        }
        pthis->hopAnimIndex = 0;
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4500, 0);

    if (((pthis->actor.params != ENZF_TYPE_DINOLFOS) || !EnZf_ChooseAction(globalCtx, pthis)) &&
        SkelAnime_Update(&pthis->skelAnime) && (pthis->actor.bgCheckFlags & 1)) {

        if (D_80B4A1B4 != -1) {
            if (pthis->damageEffect == ENZF_DMGEFF_PROJECTILE) {
                D_80B4A1B0++;
            } else {
                pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

                if (!EnZf_PrimaryFloorCheck(pthis, globalCtx, 135.0f) && (pthis->actor.xzDistToPlayer < 90.0f)) {
                    EnZf_SetupJumpUp(pthis);
                } else if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) == 0)) {
                    EnZf_SetupSlash(pthis);
                } else {
                    func_80B44DC4(pthis, globalCtx);
                }
            }
        } else {

            wallYawDiff = pthis->actor.wallYaw - pthis->actor.shape.rot.y;
            wallYawDiff = ABS(wallYawDiff);

            if ((pthis->actor.params == ENZF_TYPE_DINOLFOS) && (pthis->actor.bgCheckFlags & 8) &&
                (ABS(wallYawDiff) < 12000) && (pthis->actor.xzDistToPlayer < 90.0f)) {
                EnZf_SetupJumpUp(pthis);
            } else if (!EnZf_DodgeRangedEngaging(globalCtx, pthis)) {
                if (pthis->actor.params != ENZF_TYPE_DINOLFOS) {
                    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

                    if (!EnZf_PrimaryFloorCheck(pthis, globalCtx, 135.0f) && (pthis->actor.xzDistToPlayer < 90.0f)) {
                        EnZf_SetupJumpUp(pthis);
                    } else if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) == 0)) {
                        EnZf_SetupSlash(pthis);
                    } else {
                        func_80B44DC4(pthis, globalCtx);
                    }
                } else if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) == 0) &&
                           EnZf_CanAttack(globalCtx, pthis)) {
                    EnZf_SetupSlash(pthis);
                } else {
                    func_80B44DC4(pthis, globalCtx);
                }
            }
        }
    }
}

void EnZf_SetupJumpUp(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfJumpingAnim, 1.0f, 0.0f, 3.0f, ANIMMODE_ONCE, 0.0f);
    pthis->unk_3F0 = 0;
    pthis->hopAnimIndex = 1;
    pthis->action = ENZF_ACTION_JUMP_UP;
    pthis->actor.velocity.y = 22.0f;
    pthis->actor.speedXZ = 7.5f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_JUMP);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    EnZf_SetupAction(pthis, EnZf_JumpUp);
}

void EnZf_JumpUp(EnZf* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4000, 1);
    if (pthis->actor.velocity.y >= 5.0f) {
        func_800355B8(globalCtx, &pthis->leftFootPos);
        func_800355B8(globalCtx, &pthis->rightFootPos);
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->unk_3F0 == 0) {
            Animation_Change(&pthis->skelAnime, &gZfSlashAnim, 3.0f, 0.0f, 13.0f, ANIMMODE_ONCE, -4.0f);
            pthis->unk_3F0 = 10;
        } else if (pthis->actor.bgCheckFlags & 3) {
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.world.pos.y = pthis->actor.floorHeight;
            EnZf_SetupSlash(pthis);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_ATTACK);
            pthis->skelAnime.curFrame = 13.0f;
        }
    }
}

// Conditional setup function
void func_80B483E4(EnZf* pthis, GlobalContext* globalCtx) {
    s16 playerRotY;
    Player* player;

    if ((pthis->actor.params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* not miniboss */ ||
        Actor_TestFloorInDirection(&pthis->actor, globalCtx, 40.0f, (s16)(pthis->actor.shape.rot.y + 0x3FFF)) ||
        Actor_TestFloorInDirection(&pthis->actor, globalCtx, -40.0f, (s16)(pthis->actor.shape.rot.y + 0x3FFF))) {
        Animation_PlayLoop(&pthis->skelAnime, &gZfSidesteppingAnim);
        player = GET_PLAYER(globalCtx);
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 4000, 1);
        playerRotY = player->actor.shape.rot.y;

        if (Math_SinS(playerRotY - pthis->actor.shape.rot.y) >= 0.0f) {
            pthis->actor.speedXZ = -6.0f;
        } else if (Math_SinS(playerRotY - pthis->actor.shape.rot.y) < 0.0f) { // Superfluous check
            pthis->actor.speedXZ = 6.0f;
        }

        pthis->unk_408 = 0.0f;
        pthis->hopAnimIndex = 0;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
        pthis->unk_3F0 = Rand_ZeroOne() * 10.0f + 5.0f;
        pthis->action = ENZF_ACTION_CIRCLE_AROUND_PLAYER;
        EnZf_SetupAction(pthis, EnZf_CircleAroundPlayer);
    } else {
        EnZf_SetupApproachPlayer(pthis, globalCtx);
    }
}

void EnZf_CircleAroundPlayer(EnZf* pthis, GlobalContext* globalCtx) {
    s16 playerRot;
    s16 phi_v0_4;
    Player* player = GET_PLAYER(globalCtx);
    s32 curKeyFrame;
    s32 prevKeyFrame;
    s32 playSpeed;
    f32 baseRange = 0.0f;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xBB8, 1);
    playerRot = player->actor.shape.rot.y;

    if (pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) { // miniboss
        if (pthis->unk_3F8) {
            pthis->actor.speedXZ = -pthis->actor.speedXZ;
        }
    } else if ((pthis->actor.bgCheckFlags & 8) ||
               !Actor_TestFloorInDirection(&pthis->actor, globalCtx, pthis->actor.speedXZ,
                                           pthis->actor.shape.rot.y + 0x3FFF)) {
        if (pthis->actor.bgCheckFlags & 8) {
            if (pthis->actor.speedXZ >= 0.0f) {
                phi_v0_4 = pthis->actor.shape.rot.y + 0x3FFF;
            } else {
                phi_v0_4 = pthis->actor.shape.rot.y - 0x3FFF;
            }

            phi_v0_4 = pthis->actor.wallYaw - phi_v0_4;
        } else {
            pthis->actor.speedXZ *= -0.8f;
            phi_v0_4 = 0;
        }

        if (ABS(phi_v0_4) > 0x4000) {
            pthis->actor.speedXZ *= -0.8f;
            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ -= 0.5f;
            } else {
                pthis->actor.speedXZ += 0.5f;
            }
        }
    }

    if (Math_SinS(playerRot - pthis->actor.shape.rot.y) >= 0.0f) {
        pthis->actor.speedXZ += 0.125f;
    } else {
        pthis->actor.speedXZ -= 0.125f;
    }

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x4000;

    if (Actor_OtherIsTargeted(globalCtx, &pthis->actor)) {
        baseRange = 100.0f;
    }

    if (pthis->actor.xzDistToPlayer <= (70.0f + baseRange)) {
        Math_SmoothStepToF(&pthis->unk_408, -4.0f, 1.0f, 1.5f, 0.0f);
    } else if ((90.0f + baseRange) < pthis->actor.xzDistToPlayer) {
        Math_SmoothStepToF(&pthis->unk_408, 4.0f, 1.0f, 1.5f, 0.0f);
    } else {
        Math_SmoothStepToF(&pthis->unk_408, 0.0f, 1.0f, 5.65f, 0.0f);
    }

    if ((pthis->unk_408 != 0.0f) && !EnZf_SecondaryFloorCheck(pthis, globalCtx, pthis->unk_408)) {
        pthis->actor.world.pos.x += Math_SinS(pthis->actor.shape.rot.y) * pthis->unk_408;
        pthis->actor.world.pos.z += Math_CosS(pthis->actor.shape.rot.y) * pthis->unk_408;
    }

    if (ABS(pthis->actor.speedXZ) >= ABS(pthis->unk_408)) {
        pthis->skelAnime.playSpeed = -pthis->actor.speedXZ * 0.75f;
    } else if (pthis->skelAnime.playSpeed < 0.0f) {
        pthis->skelAnime.playSpeed = pthis->unk_408 * -0.75f;
    } else {
        pthis->skelAnime.playSpeed = pthis->unk_408 * 0.75f;
    }

    curKeyFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);
    prevKeyFrame = pthis->skelAnime.curFrame - ABS(pthis->skelAnime.playSpeed);
    playSpeed = (f32)ABS(pthis->skelAnime.playSpeed);

    pthis->curPlatform = EnZf_FindPlatform(&pthis->actor.world.pos, pthis->curPlatform);

    if (EnZf_FindPlatform(&player->actor.world.pos, -1) != pthis->curPlatform) {
        pthis->actor.speedXZ = 0.0f;

        if ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* miniboss */ &&
            (D_80B4A1B4 == pthis->actor.params)) {
            EnZf_SetupHopAndTaunt(pthis);
        } else {
            EnZf_SetupApproachPlayer(pthis, globalCtx);
        }
    } else if ((pthis->actor.params != ENZF_TYPE_DINOLFOS) || !EnZf_ChooseAction(globalCtx, pthis)) {
        if (pthis->unk_3F0 == 0) {
            phi_v0_4 = player->actor.shape.rot.y - pthis->actor.shape.rot.y;

            phi_v0_4 = ABS(phi_v0_4);

            if (phi_v0_4 >= 0x3A98) {
                if ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) && (D_80B4A1B4 == pthis->actor.params)) {
                    EnZf_SetupHopAndTaunt(pthis);
                } else {
                    func_80B45384(pthis);
                    pthis->unk_3F0 = Rand_ZeroOne() * 5.0f + 1.0f;
                }
            } else if ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) && (D_80B4A1B4 == pthis->actor.params)) {
                EnZf_SetupHopAndTaunt(pthis);
            } else {
                pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

                if ((pthis->actor.xzDistToPlayer <= 100.0f) && ((globalCtx->gameplayFrames % 4) == 0) &&
                    EnZf_CanAttack(globalCtx, pthis)) {
                    EnZf_SetupSlash(pthis);
                } else if ((pthis->actor.xzDistToPlayer < 280.0f) && (pthis->actor.xzDistToPlayer > 240.0f) &&
                           !EnZf_PrimaryFloorCheck(pthis, globalCtx, 191.9956f) &&
                           ((globalCtx->gameplayFrames % 2) == 0)) {
                    EnZf_SetupJumpForward(pthis);
                } else {
                    EnZf_SetupApproachPlayer(pthis, globalCtx);
                }
            }
        } else {
            pthis->unk_3F0--;
        }
        if (curKeyFrame != (s32)pthis->skelAnime.curFrame) {
            s32 nextKeyFrame = playSpeed + curKeyFrame;
            if (((prevKeyFrame < 14) && (nextKeyFrame >= 16)) || ((prevKeyFrame < 27) && (nextKeyFrame >= 29))) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_WALK);
            }
        }
        if ((globalCtx->gameplayFrames & 0x5F) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
        }
    }
}

void EnZf_SetupDie(EnZf* pthis) {
    Animation_Change(&pthis->skelAnime, &gZfDyingAnim, 1.5f, 0.0f, Animation_GetLastFrame(&gZfDyingAnim), ANIMMODE_ONCE,
                     -4.0f);

    if ((pthis->actor.bgCheckFlags & 1) && ((pthis->actor.velocity.y == 0.0f) || (pthis->actor.velocity.y == -4.0f))) {
        pthis->actor.speedXZ = 0.0f;
        pthis->hopAnimIndex = 0;
    } else {
        pthis->hopAnimIndex = 1;
    }

    pthis->action = ENZF_ACTION_DIE;
    pthis->actor.flags &= ~ACTOR_FLAG_0;

    if (D_80B4A1B4 != -1) {
        if (pthis->actor.prev != NULL) {
            ((EnZf*)pthis->actor.prev)->unk_3F4 = 90;

            if (pthis->actor.prev->colChkInfo.health < 3) {
                pthis->actor.prev->colChkInfo.health = 3;
            }
        } else {
            ((EnZf*)pthis->actor.next)->unk_3F4 = 90;

            if (pthis->actor.next->colChkInfo.health < 3) {
                pthis->actor.next->colChkInfo.health = 3;
            }
        }
    }

    D_80B4A1B0 = 0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DEAD);
    EnZf_SetupAction(pthis, EnZf_Die);
}

void EnZf_Die(EnZf* pthis, GlobalContext* globalCtx) {

    if (pthis->actor.bgCheckFlags & 2) {
        pthis->actor.speedXZ = 0.0f;
    }

    if (pthis->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.15f, 0.0f);
        pthis->hopAnimIndex = 0;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.category != ACTORCAT_PROP) {
            if ((pthis->actor.params >= ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* miniboss */ && (D_80B4A1B4 == -1)) {
                Flags_SetSwitch(globalCtx, pthis->clearFlag);
                func_800F5B58();
            } else {
                D_80B4A1B4 = -1;
            }
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
        }

        if (pthis->alpha != 0) {
            pthis->actor.shape.shadowAlpha = pthis->alpha -= 5;

        } else {
            Actor_Kill(&pthis->actor);
        }
    } else {
        s32 curFrame = pthis->skelAnime.curFrame;

        if ((curFrame == 10) || (curFrame == 18)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        }
    }
}

void EnZf_UpdateHeadRotation(EnZf* pthis, GlobalContext* globalCtx) {
    s16 angleTemp;

    if ((pthis->actor.params == ENZF_TYPE_DINOLFOS) && (pthis->action == ENZF_ACTION_3) && (pthis->unk_3F4 != 0)) {
        pthis->headRot = Math_SinS(pthis->unk_3F4 * 1400) * 0x2AA8;
    } else {
        angleTemp = pthis->actor.yawTowardsPlayer;
        angleTemp -= (s16)(pthis->headRot + pthis->actor.shape.rot.y);
        pthis->headRotTemp = CLAMP(angleTemp, -0x7D0, 0x7D0);
        pthis->headRot += pthis->headRotTemp;
        pthis->headRot = CLAMP(pthis->headRot, -0x1CD7, 0x1CD7);
    }
}

void EnZf_UpdateDamage(EnZf* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 dropParams;

    if ((pthis->bodyCollider.base.acFlags & AC_HIT) && (pthis->action <= ENZF_ACTION_STUNNED)) {
        pthis->bodyCollider.base.acFlags &= ~AC_HIT;

        if (((pthis->actor.params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* not miniboss */ ||
             (D_80B4A1B4 != pthis->actor.params)) &&
            (pthis->actor.colChkInfo.damageEffect != ENZF_DMGEFF_IMMUNE)) {
            pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
            Actor_SetDropFlag(&pthis->actor, &pthis->bodyCollider.info, 0);

            if ((pthis->actor.colChkInfo.damageEffect == ENZF_DMGEFF_STUN) ||
                (pthis->actor.colChkInfo.damageEffect == ENZF_DMGEFF_ICE)) {
                if (pthis->action != ENZF_ACTION_STUNNED) {
                    Actor_SetColorFilter(&pthis->actor, 0, 120, 0, 80);
                    Actor_ApplyDamage(&pthis->actor);
                    EnZf_SetupStunned(pthis);
                }
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_CRY);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 8);

                if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    dropParams = 0x40;
                    EnZf_SetupDie(pthis);

                    if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
                        dropParams = 0xE0;
                    }

                    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, dropParams);
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                } else {
                    if ((D_80B4A1B4 != -1) && ((pthis->actor.colChkInfo.health + pthis->actor.colChkInfo.damage) >= 4) &&
                        (pthis->actor.colChkInfo.health < 4)) {
                        pthis->damageEffect = ENZF_DMGEFF_PROJECTILE;
                    }

                    EnZf_SetupDamaged(pthis);
                }
            }
        }
    }
}

void EnZf_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnZf* pthis = (EnZf*)thisx;
    s32 pad2;

    EnZf_UpdateDamage(pthis, globalCtx);
    if (pthis->actor.colChkInfo.damageEffect != ENZF_DMGEFF_IMMUNE) {
        pthis->unk_3F8 = false;
        if ((pthis->hopAnimIndex != 1) && (pthis->action != ENZF_ACTION_HOP_AWAY)) {
            if (pthis->actor.speedXZ != 0.0f) {
                pthis->unk_3F8 = EnZf_PrimaryFloorCheck(pthis, globalCtx, pthis->actor.speedXZ * 1.5f);
            }
            if (!pthis->unk_3F8) {
                pthis->unk_3F8 = EnZf_PrimaryFloorCheck(pthis, globalCtx, 0.0f);
            }
        }

        if (!pthis->unk_3F8) {
            Actor_MoveForward(&pthis->actor);
        }

        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 25.0f, 30.0f, 60.0f, 0x1D);

        if (!(pthis->actor.bgCheckFlags & 1)) {
            pthis->hopAnimIndex = 1;
        }

        pthis->actionFunc(pthis, globalCtx);
    }

    if (pthis->actor.colChkInfo.health > 0) {
        if ((pthis->action != ENZF_ACTION_SLASH) && (pthis->action != ENZF_ACTION_STUNNED)) {
            EnZf_UpdateHeadRotation(pthis, globalCtx);
        }

        if ((D_80B4A1B0 != 0) && (D_80B4A1B4 != pthis->actor.params)) {
            EnZf_SetupSheatheSword(pthis, globalCtx);
            D_80B4A1B4 = pthis->actor.params;
            D_80B4A1B0 = 0;

            if (pthis->actor.prev != NULL) {
                ((EnZf*)pthis->actor.prev)->unk_3F4 = 90;
            } else {
                ((EnZf*)pthis->actor.next)->unk_3F4 = 90;
            }
        }
    }

    if (pthis->action >= ENZF_ACTION_DIE) {
        Math_SmoothStepToS(&pthis->headRot, 0, 1, 2000, 0);

        if (pthis->action <= ENZF_ACTION_HOP_AND_TAUNT) {
            if ((pthis->unk_3F4 == 1) && (pthis->actor.bgCheckFlags & 1)) {
                if (pthis->actor.colChkInfo.health > 0) {
                    EnZf_SetupDrawSword(pthis, globalCtx);
                }
                pthis->unk_3F4--;
            }
        }

        if (pthis->unk_3F4 >= 2) {
            pthis->unk_3F4--;
        }
    }

    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 40.0f;

    if ((pthis->actor.colChkInfo.health > 0) && (pthis->alpha == 255)) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCollider);

        if ((pthis->actor.world.pos.y == pthis->actor.floorHeight) && (pthis->action <= ENZF_ACTION_DAMAGED)) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
        }

        if ((pthis->actor.params < ENZF_TYPE_LIZALFOS_MINIBOSS_A) /* not miniboss */ ||
            (D_80B4A1B4 != pthis->actor.params)) {
            if ((pthis->actor.colorFilterTimer == 0) || !(pthis->actor.colorFilterParams & 0x4000)) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCollider.base);
            }
        }
    }

    if ((pthis->action == ENZF_ACTION_SLASH) && (pthis->skelAnime.curFrame >= 14.0f) &&
        (pthis->skelAnime.curFrame <= 20.0f)) {
        if (!(pthis->swordCollider.base.atFlags & AT_BOUNCED) && !(pthis->swordCollider.base.acFlags & AC_HIT)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->swordCollider.base);
        } else {
            pthis->swordCollider.base.atFlags &= ~AT_BOUNCED;
            pthis->swordCollider.base.acFlags &= ~AC_HIT;
            EnZf_SetupRecoilFromBlockedSlash(pthis);
        }
    }
}

s32 EnZf_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnZf* pthis = (EnZf*)thisx;

    switch (limbIndex) {
        case ENZF_LIMB_HEAD_ROOT:
            rot->y -= pthis->headRot;
            break;
        case ENZF_LIMB_SWORD:
            if (pthis->swordSheathed) {
                *dList = gZfEmptyHandDL;
            }
            break;
        case ENZF_LIMB_SCABBARD:
            if (pthis->swordSheathed) {
                *dList = gZfSheathedSwordDL;
            }
            break;
        default:
            break;
    }

    return false;
}

void EnZf_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    static Vec3f D_80B4A2A4_144 = { 300.0f, -1700.0f, 0.0f }; // Sword tip?
    static Vec3f D_80B4A2B0_144 = { -600.0f, 300.0f, 0.0f };  // Sword hilt?
    Vec3f sp54;
    Vec3f sp48;
    EnZf* pthis = (EnZf*)thisx;
    s32 bodyPart = -1;

    if (limbIndex == ENZF_LIMB_SWORD) {
        Matrix_MultVec3f(&swordQuadOffset1_144, &pthis->swordCollider.dim.quad[1]);
        Matrix_MultVec3f(&swordQuadOffset0_144, &pthis->swordCollider.dim.quad[0]);
        Matrix_MultVec3f(&swordQuadOffset3_144, &pthis->swordCollider.dim.quad[3]);
        Matrix_MultVec3f(&swordQuadOffset2_144, &pthis->swordCollider.dim.quad[2]);
        Collider_SetQuadVertices(&pthis->swordCollider, &pthis->swordCollider.dim.quad[0],
                                 &pthis->swordCollider.dim.quad[1], &pthis->swordCollider.dim.quad[2],
                                 &pthis->swordCollider.dim.quad[3]);
        Matrix_MultVec3f(&D_80B4A2A4_144, &sp54);
        Matrix_MultVec3f(&D_80B4A2B0_144, &sp48);

        if (pthis->action == ENZF_ACTION_SLASH) {
            if (pthis->skelAnime.curFrame < 14.0f) {
                EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIndex));
            } else if (pthis->skelAnime.curFrame < 20.0f) {
                EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIndex), &sp54, &sp48);
            }
        }
    } else {
        Actor_SetFeetPos(&pthis->actor, limbIndex, ENZF_LIMB_LEFT_FOOT, &footOffset_144, ENZF_LIMB_RIGHT_FOOT, &footOffset_144);
    }

    switch (limbIndex) {
        case ENZF_LIMB_LEFT_FOOT:
            Matrix_MultVec3f(&footOffset_144, &pthis->leftFootPos);
            break;
        case ENZF_LIMB_RIGHT_FOOT:
            Matrix_MultVec3f(&footOffset_144, &pthis->rightFootPos);
            break;
    }

    if (pthis->iceTimer != 0) {
        switch (limbIndex) {
            case ENZF_LIMB_HEAD:
                bodyPart = 0;
                break;
            case ENZF_LIMB_NECK:
                bodyPart = 1;
                break;
            case ENZF_LIMB_CHEST_ARMOR:
                bodyPart = 2;
                break;
            case ENZF_LIMB_RIGHT_FOREARM:
                bodyPart = 3;
                break;
            case ENZF_LIMB_LEFT_FOREARM:
                bodyPart = 4;
                break;
            case ENZF_LIMB_TRUNK:
                bodyPart = 5;
                break;
            case ENZF_LIMB_SWORD_ROOT:
                bodyPart = 6;
                break;
            case ENZF_LIMB_RIGHT_SHIN:
                bodyPart = 7;
                break;
            case ENZF_LIMB_LEFT_SHIN_ROOT:
                bodyPart = 8;
                break;
            default:
                break;
        }
        if (bodyPart >= 0) {
            Matrix_MultVec3f(&zeroVec_144, &pthis->bodyPartsPos[bodyPart]);
        }
    }
}

static Gfx D_80B4A2F8[] = {
    gsSPTexture(0x0A00, 0x0A00, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

void EnZf_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnZf* pthis = (EnZf*)thisx;
    ; // Extra ";" required for matching. Cannot be if (1) {} or the like. Typo?

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zf.c", 3533);

    func_8002EBCC(thisx, globalCtx, 1);

    gSPTexture(D_80B4A2F8, IREG(0), IREG(1), 0, G_TX_RENDERTILE, G_ON);

    gSPSegment(POLY_OPA_DISP++, 0x08, D_80B4A2F8);

    if (pthis->alpha == 255) {
        func_80093D18(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, pthis->alpha);
        gSPSegment(POLY_OPA_DISP++, 0x09, &D_80116280[2]);

        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnZf_OverrideLimbDraw, EnZf_PostLimbDraw, pthis, POLY_OPA_DISP);

        if (pthis->iceTimer != 0) {
            thisx->colorFilterTimer++;
            pthis->iceTimer--;

            if ((pthis->iceTimer % 4) == 0) {
                s32 icePosIndex = pthis->iceTimer >> 2;

                EffectSsEnIce_SpawnFlyingVec3f(globalCtx, thisx, &pthis->bodyPartsPos[icePosIndex], 150, 150, 150, 250,
                                               235, 245, 255, 1.4f);
            }
            if (1) {}
        }
    } else { // fades out when dead
        func_80093D84(globalCtx->state.gfxCtx);
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
        gSPSegment(POLY_XLU_DISP++, 0x09, &D_80116280[0]);
        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnZf_OverrideLimbDraw, EnZf_PostLimbDraw, pthis, POLY_XLU_DISP);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zf.c", 3601);
}

void EnZf_SetupCircleAroundPlayer(EnZf* pthis, f32 speed) {
    Animation_MorphToLoop(&pthis->skelAnime, &gZfSidesteppingAnim, -1.0f);
    pthis->unk_3F0 = Rand_ZeroOne() * 10.0f + 8.0f;

    if (pthis->actor.params == ENZF_TYPE_DINOLFOS) {
        pthis->actor.speedXZ = 2.0f * speed;
        pthis->unk_3F0 /= 2;
    } else {
        pthis->actor.speedXZ = speed;
    }

    pthis->hopAnimIndex = 0;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;
    pthis->action = ENZF_ACTION_CIRCLE_AROUND_PLAYER;
    EnZf_SetupAction(pthis, EnZf_CircleAroundPlayer);
}

s32 EnZf_DodgeRangedEngaging(GlobalContext* globalCtx, EnZf* pthis) {
    Actor* projectileActor;
    s16 yawToProjectile;
    s16 phi_t0;
    s16 phi_v1;

    projectileActor = Actor_GetProjectileActor(globalCtx, &pthis->actor, 600.0f);

    if (projectileActor != NULL) {
        yawToProjectile =
            Actor_WorldYawTowardActor(&pthis->actor, projectileActor) - (s16)(u16)(pthis->actor.shape.rot.y);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;

        phi_t0 = 0;

        if (EnZf_PrimaryFloorCheck(pthis, globalCtx, -8.0f)) {
            phi_t0 = 1;
        }

        if (EnZf_PrimaryFloorCheck(pthis, globalCtx, 8.0f)) {
            phi_t0 |= 2;
        }

        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

        if ((((pthis->actor.xzDistToPlayer < 90.0f) || (phi_t0 == 3)) &&
             !EnZf_PrimaryFloorCheck(pthis, globalCtx, 135.0f)) ||
            (projectileActor->id == ACTOR_ARMS_HOOK)) {
            EnZf_SetupJumpUp(pthis);
            return true;
        }

        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF;

        if (phi_t0 == 0) {
            phi_v1 = globalCtx->gameplayFrames % 2;
        } else {
            phi_v1 = phi_t0;
        }

        if ((ABS(yawToProjectile) < 0x2000) || (ABS(yawToProjectile) >= 0x6000)) {
            if (phi_v1 & 1) {
                EnZf_SetupCircleAroundPlayer(pthis, 8.0f);
                return true;
            }
            EnZf_SetupCircleAroundPlayer(pthis, -8.0f);
            return true;
        }
        if (ABS(yawToProjectile) < 0x5FFF) {
            if (phi_v1 & 1) {
                EnZf_SetupCircleAroundPlayer(pthis, 4.0f);
                return true;
            }
            EnZf_SetupCircleAroundPlayer(pthis, -4.0f);
        }
        return true;
    }
    return false;
}

s32 EnZf_DodgeRangedWaiting(GlobalContext* globalCtx, EnZf* pthis) {
    Actor* projectileActor;
    s16 yawToProjectile;
    s16 phi_t0;
    s16 sp1E;
    s16 sp1C = 0;

    projectileActor = Actor_GetProjectileActor(globalCtx, &pthis->actor, 600.0f);
    if (projectileActor != NULL) {
        yawToProjectile = Actor_WorldYawTowardActor(&pthis->actor, projectileActor) - (s16)(u16)pthis->actor.shape.rot.y;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x3FFF; // Set to move sideways

        phi_t0 = 0;

        if (EnZf_PrimaryFloorCheck(pthis, globalCtx, -70.0f)) {
            phi_t0 = 1;
        }

        if (EnZf_PrimaryFloorCheck(pthis, globalCtx, 70.0f)) {
            phi_t0 |= 2;
        }

        pthis->actor.speedXZ = 0.0f;

        if ((ABS(yawToProjectile) < 0x2000) || (ABS(yawToProjectile) >= 0x6000)) {
            if (phi_t0 == 0) {
                if ((globalCtx->gameplayFrames % 2) != 0) {
                    sp1E = 6;
                } else {
                    sp1E = -6;
                }
            } else {
                switch (phi_t0) {
                    case 1:
                        sp1E = 6;
                        break;
                    case 2:
                        sp1E = -6;
                        break;
                    case 1 | 2:
                        sp1C = 5;
                        sp1E = 0;
                        break;
                }
            }
        } else if (ABS(yawToProjectile) < 0x5FFF) {
            if (phi_t0 == 0) {
                if ((globalCtx->gameplayFrames % 2) != 0) {
                    sp1E = 6;
                } else {
                    sp1E = -6;
                }
            } else {
                switch (phi_t0) {
                    case 1:
                        sp1E = 6;
                        break;
                    case 2:
                        sp1E = -6;
                        break;
                    case 1 | 2:
                        sp1C = 10;
                        sp1E = 0;
                        break;
                }
            }
        }

        pthis->unk_408 = sp1E;
        pthis->unk_40C = sp1C;
        return true;
    }
    return false;
}

void EnZf_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sUnused_144 = { 1100.0f, -700.0f, 0.0f };

    footOffset_144 = { 300.0f, 0.0f, 0.0f };

    D_80B4A2A4_144 = { 300.0f, -1700.0f, 0.0f };

    D_80B4A2B0_144 = { -600.0f, 300.0f, 0.0f };

    swordQuadOffset1_144 = { 0.0f, 1500.0f, 0.0f };

    swordQuadOffset0_144 = { -600.0f, -3000.0f, 1000.0f };

    swordQuadOffset3_144 = { -600.0f, -3000.0f, -1000.0f };

    swordQuadOffset2_144 = { 1500.0f, -3000.0f, 0.0f };

    zeroVec_144 = { 0.0f, 0.0f, 0.0f };

    D_80B4A1B0 = 0;

    D_80B4A1B4 = 1;

    En_Zf_InitVars = {
        ACTOR_EN_ZF,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_ZF,
        sizeof(EnZf),
        (ActorFunc)EnZf_Init,
        (ActorFunc)EnZf_Destroy,
        (ActorFunc)EnZf_Update,
        (ActorFunc)EnZf_Draw,
        (ActorFunc)EnZf_Reset,
    };

    sBodyCylinderInit = {
        {
            COLTYPE_HIT0,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
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
        { 20, 70, 0, { 0, 0, 0 } },
    };

    sSwordQuadInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_QUAD,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
        /* Deku stick    */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(1, ENZF_DMGEFF_PROJECTILE),
        /* Explosive     */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Hookshot      */ DMG_ENTRY(0, ENZF_DMGEFF_STUN),
        /* Kokiri sword  */ DMG_ENTRY(1, ENZF_DMGEFF_NONE),
        /* Master sword  */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Giant's Knife */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
        /* Fire arrow    */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
        /* Ice arrow     */ DMG_ENTRY(4, ENZF_DMGEFF_ICE),
        /* Light arrow   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
        /* Unk arrow 1   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
        /* Unk arrow 2   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
        /* Unk arrow 3   */ DMG_ENTRY(2, ENZF_DMGEFF_PROJECTILE),
        /* Fire magic    */ DMG_ENTRY(0, ENZF_DMGEFF_IMMUNE),
        /* Ice magic     */ DMG_ENTRY(3, ENZF_DMGEFF_ICE),
        /* Light magic   */ DMG_ENTRY(0, ENZF_DMGEFF_IMMUNE),
        /* Shield        */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, ENZF_DMGEFF_NONE),
        /* Giant spin    */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
        /* Master spin   */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Kokiri jump   */ DMG_ENTRY(2, ENZF_DMGEFF_NONE),
        /* Giant jump    */ DMG_ENTRY(8, ENZF_DMGEFF_NONE),
        /* Master jump   */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
        /* Unknown 1     */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, ENZF_DMGEFF_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, ENZF_DMGEFF_NONE),
    };

    D_80B4AB30 = 0;

}

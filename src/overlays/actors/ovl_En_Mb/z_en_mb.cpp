#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_MB_Z_EN_MB_C
#include "actor_common.h"
/*
 * File: z_en_mb.c
 * Overlay: ovl_En_Mb
 * Description: Moblins
 */

#include "z_en_mb.h"
#include "objects/object_mb/object_mb.h"
#include "def/code_800A9F30.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

/*
 * This actor can have three behaviors:
 * - "Spear Guard" (variable -1): uses a spear, walks around home point, charges player if too close
 * - "Club" (variable 0): uses a club, stands still and smashes its club on the ground when the player approaches
 * - "Spear Patrol" (variable 0xPP00 PP=pathId): uses a spear, patrols following a path, charges
 */

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)


#define ENMB_ATTACK_NONE 0
#define ENMB_ATTACK_SPEAR 1
#define ENMB_ATTACK_CLUB_RIGHT 1
#define ENMB_ATTACK_CLUB_MIDDLE 2
#define ENMB_ATTACK_CLUB_LEFT 3

/* Spear and Club moblins use a different skeleton but the limbs are organized the same */

void EnMb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMb_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnMb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMb_Draw(Actor* thisx, GlobalContext* globalCtx);

ActorInit En_Mb_InitVars = {
    ACTOR_EN_MB,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_MB,
    sizeof(EnMb),
    (ActorFunc)EnMb_Init,
    (ActorFunc)EnMb_Destroy,
    (ActorFunc)EnMb_Update,
    (ActorFunc)EnMb_Draw,
    (ActorFunc)EnMb_Reset,
};

void EnMb_SetupSpearPatrolTurnTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SetupClubWaitPlayerNear(EnMb* pthis);
void EnMb_SpearGuardLookAround(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SetupSpearGuardLookAround(EnMb* pthis);
void EnMb_SetupSpearDamaged(EnMb* pthis);
void EnMb_SpearGuardWalk(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearGuardPrepareAndCharge(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearPatrolPrepareAndCharge(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearEndChargeQuick(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_Stunned(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubDead(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubDamagedWhileKneeling(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubWaitPlayerNear(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubAttack(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearDead(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearDamaged(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SetupSpearDead(EnMb* pthis);
void EnMb_SpearPatrolTurnTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearPatrolWalkTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearPatrolEndCharge(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_SpearPatrolImmediateCharge(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubWaitAfterAttack(EnMb* pthis, GlobalContext* globalCtx);
void EnMb_ClubDamaged(EnMb* pthis, GlobalContext* globalCtx);

static Vec3f quadModel_124[] = { { 1000.0f, 0.0f, 0.0f },
                             { 1000.0f, 0.0f, 0.0f },
                             { 1000.0f, -8000.0f, -1500.0f },
                             { 1000.0f, -9000.0f, 2000.0f } };

static Vec3f unused_127 = { 1100.0f, -700.0f, 0.0f };

static Vec3f feetPos_127 = { 0.0f, 0.0f, 0.0f };

static Vec3f effSpawnPosModel_127 = { 0.0f, -8000.0f, 0.0f };

static Vec3f zeroVec_127 = { 0.0f, 0.0f, 0.0f };

static Vec3f frontShieldingTriModel0_128[] = {
    { 4000.0f, 7000.0f, 3500.0f },
    { 4000.0f, 0.0f, 3500.0f },
    { -4000.0f, 7000.0f, 3500.0f },
};

static Vec3f frontShieldingTriModel1_128[] = {
    { -4000.0f, 7000.0f, 3500.0f },
    { -4000.0f, 0.0f, 3500.0f },
    { 4000.0f, 0.0f, 3500.0f },
};


static ColliderCylinderInit sHitboxInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
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

static ColliderTrisElementInit sFrontShieldingTrisInit[2] = {
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, 14.0f, 2.0f }, { -10.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
};

static ColliderTrisInit sFrontShieldingInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    2,
    sFrontShieldingTrisInit,
};

static ColliderQuadInit sAttackColliderInit = {
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
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sSpearMoblinDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Deku stick    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Slingshot     */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
    /* Explosive     */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Boomerang     */ DMG_ENTRY(0, ENMB_DMGEFF_STUN),
    /* Normal arrow  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Hammer swing  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Hookshot      */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Kokiri sword  */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
    /* Master sword  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Giant's Knife */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Fire arrow    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Ice arrow     */ DMG_ENTRY(4, ENMB_DMGEFF_STUN_ICE),
    /* Light arrow   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 1   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 2   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 3   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Fire magic    */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Ice magic     */ DMG_ENTRY(3, ENMB_DMGEFF_STUN_ICE),
    /* Light magic   */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Shield        */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Mirror Ray    */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Kokiri spin   */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
    /* Giant spin    */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Master spin   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Kokiri jump   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Giant jump    */ DMG_ENTRY(8, ENMB_DMGEFF_DEFAULT),
    /* Master jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unknown 1     */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Unblockable   */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Hammer jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unknown 2     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
};

static DamageTable sClubMoblinDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Deku stick    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Slingshot     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Explosive     */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Boomerang     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Normal arrow  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Hammer swing  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Hookshot      */ DMG_ENTRY(0, ENMB_DMGEFF_STUN),
    /* Kokiri sword  */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
    /* Master sword  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Giant's Knife */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Fire arrow    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Ice arrow     */ DMG_ENTRY(4, ENMB_DMGEFF_STUN_ICE),
    /* Light arrow   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 1   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 2   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Unk arrow 3   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Fire magic    */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Ice magic     */ DMG_ENTRY(3, ENMB_DMGEFF_STUN_ICE),
    /* Light magic   */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Shield        */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Mirror Ray    */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Kokiri spin   */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
    /* Giant spin    */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Master spin   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Kokiri jump   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
    /* Giant jump    */ DMG_ENTRY(8, ENMB_DMGEFF_DEFAULT),
    /* Master jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unknown 1     */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
    /* Unblockable   */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    /* Hammer jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
    /* Unknown 2     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x4A, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -1000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 5300, ICHAIN_STOP),
};

void EnMb_SetupAction(EnMb* pthis, EnMbActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnMb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMb* pthis = (EnMb*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s16 relYawFromPlayer;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 46.0f);
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    pthis->actor.colChkInfo.damageTable = &sSpearMoblinDamageTable;
    Collider_InitCylinder(globalCtx, &pthis->hitbox);
    Collider_SetCylinder(globalCtx, &pthis->hitbox, &pthis->actor, &sHitboxInit);
    Collider_InitTris(globalCtx, &pthis->frontShielding);
    Collider_SetTris(globalCtx, &pthis->frontShielding, &pthis->actor, &sFrontShieldingInit, pthis->frontShieldingTris);
    Collider_InitQuad(globalCtx, &pthis->attackCollider);
    Collider_SetQuad(globalCtx, &pthis->attackCollider, &pthis->actor, &sAttackColliderInit);

    switch (pthis->actor.params) {
        case ENMB_TYPE_SPEAR_GUARD:
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gEnMbSpearSkel, &gEnMbSpearStandStillAnim,
                               pthis->jointTable, pthis->morphTable, 28);
            pthis->actor.colChkInfo.health = 2;
            pthis->actor.colChkInfo.mass = MASS_HEAVY;
            pthis->maxHomeDist = 1000.0f;
            pthis->playerDetectionRange = 1750.0f;
            EnMb_SetupSpearGuardLookAround(pthis);
            break;
        case ENMB_TYPE_CLUB:
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gEnMbClubSkel, &gEnMbClubStandStillClubDownAnim,
                               pthis->jointTable, pthis->morphTable, 28);

            pthis->actor.colChkInfo.health = 6;
            pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
            pthis->actor.colChkInfo.damageTable = &sClubMoblinDamageTable;
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->hitbox.dim.height = 170;
            pthis->hitbox.dim.radius = 45;
            pthis->actor.uncullZoneForward = 4000.0f;
            pthis->actor.uncullZoneScale = 800.0f;
            pthis->actor.uncullZoneDownward = 1800.0f;
            pthis->playerDetectionRange = 710.0f;
            pthis->attackCollider.info.toucher.dmgFlags = 0x20000000;

            relYawFromPlayer =
                pthis->actor.world.rot.y - Math_Vec3f_Yaw(&pthis->actor.world.pos, &player->actor.world.pos);
            if (ABS(relYawFromPlayer) > 0x4000) {
                pthis->actor.world.rot.y = thisx->world.rot.y + 0x8000;
                pthis->actor.shape.rot.y = thisx->world.rot.y;
                pthis->actor.world.pos.z = thisx->world.pos.z + 600.0f;
            }

            ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawFeet, 90.0f);
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actor.naviEnemyId += 1;
            EnMb_SetupClubWaitPlayerNear(pthis);
            break;
        default: /* Spear Patrol */
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gEnMbSpearSkel, &gEnMbSpearStandStillAnim,
                               pthis->jointTable, pthis->morphTable, 28);

            Actor_SetScale(&pthis->actor, 0.014f);
            pthis->path = (thisx->params & 0xFF00) >> 8;
            pthis->actor.params = ENMB_TYPE_SPEAR_PATROL;
            pthis->waypoint = 0;
            pthis->actor.colChkInfo.health = 1;
            pthis->actor.colChkInfo.mass = MASS_HEAVY;
            pthis->maxHomeDist = 350.0f;
            pthis->playerDetectionRange = 1750.0f;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            EnMb_SetupSpearPatrolTurnTowardsWaypoint(pthis, globalCtx);
            break;
    }
}

void EnMb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMb* pthis = (EnMb*)thisx;

    Collider_DestroyTris(globalCtx, &pthis->frontShielding);
    Collider_DestroyCylinder(globalCtx, &pthis->hitbox);
    Collider_DestroyQuad(globalCtx, &pthis->attackCollider);
}

void EnMb_FaceWaypoint(EnMb* pthis, GlobalContext* globalCtx) {
    s16 yawToWaypoint = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->waypointPos);

    pthis->actor.shape.rot.y = yawToWaypoint;
    pthis->actor.world.rot.y = yawToWaypoint;
}

void EnMb_NextWaypoint(EnMb* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* waypointPos;

    path = &globalCtx->setupPathList[pthis->path];

    if (pthis->waypoint == 0) {
        pthis->direction = 1;
    } else if (pthis->waypoint == (s8)(path->count - 1)) {
        pthis->direction = -1;
    }

    pthis->waypoint += pthis->direction;
    waypointPos = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + pthis->waypoint;
    pthis->waypointPos.x = waypointPos->x;
    pthis->waypointPos.y = waypointPos->y;
    pthis->waypointPos.z = waypointPos->z;
}

/**
 * Checks if the player is in a 800*74 units XZ area centered on pthis actor,
 * the area being directed along its line of sight snapped to a cardinal angle.
 * Note: the longest corridor in Sacred Forest Meadows is 800 units long,
 *       and they all are 100 units wide.
 */
s32 EnMb_IsPlayerInCorridor(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 xFromPlayer;
    f32 zFromPlayer;
    f32 cos;
    f32 sin;
    f32 xFromPlayerAbs;
    f32 zFromPlayerAbs;
    s16 alignedYaw = 0;

    if ((pthis->actor.world.rot.y < -0x62A2) || (pthis->actor.world.rot.y > 0x62A2)) {
        alignedYaw = -0x8000;
    } else if (pthis->actor.world.rot.y < -0x20E0) {
        alignedYaw = -0x4000;
    } else if (pthis->actor.world.rot.y > 0x20E0) {
        alignedYaw = 0x4000;
    }

    cos = Math_CosS(alignedYaw);
    sin = Math_SinS(alignedYaw);
    cos = ABS(cos);
    sin = ABS(sin);
    xFromPlayer = pthis->actor.world.pos.x - player->actor.world.pos.x;
    zFromPlayer = pthis->actor.world.pos.z - player->actor.world.pos.z;
    xFromPlayerAbs = ABS(xFromPlayer);
    if (xFromPlayerAbs < (cos * 37.0f + sin * 400.0f)) {
        zFromPlayerAbs = ABS(zFromPlayer);
        if (zFromPlayerAbs < (sin * 37.0f + cos * 400.0f)) {
            return true;
        }
    }
    return false;
}

void EnMb_FindWaypointTowardsPlayer(EnMb* pthis, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[pthis->path];
    s16 yawToWaypoint;
    Vec3f waypointPosF;
    Vec3s* waypointPosS;
    s16 yawPlayerToWaypoint;
    s32 i;
    s32 waypoint;

    for (waypoint = 0, i = path->count - 1; i >= 0; i--, waypoint++) {
        waypointPosS = (Vec3s*)SEGMENTED_TO_VIRTUAL(path->points) + waypoint;
        waypointPosF.x = waypointPosS->x;
        waypointPosF.y = waypointPosS->y;
        waypointPosF.z = waypointPosS->z;
        yawToWaypoint = Math_Vec3f_Yaw(&pthis->actor.world.pos, &waypointPosF);
        yawPlayerToWaypoint = yawToWaypoint - pthis->actor.yawTowardsPlayer;
        if (ABS(yawPlayerToWaypoint) <= 0x1770) {
            pthis->actor.world.rot.y = yawToWaypoint;
            if (waypoint == pthis->waypoint) {
                pthis->direction = -pthis->direction;
            }
            pthis->waypointPos = waypointPosF;
            pthis->waypoint = waypoint;
            break;
        }
    }
}

void EnMb_SetupSpearGuardLookAround(EnMb* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gEnMbSpearLookLeftAndRightAnim, -4.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->timer1 = Rand_S16Offset(30, 50);
    pthis->state = ENMB_STATE_IDLE;
    EnMb_SetupAction(pthis, EnMb_SpearGuardLookAround);
}

void EnMb_SetupClubWaitPlayerNear(EnMb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gEnMbClubStandStillClubDownAnim);
    pthis->actor.speedXZ = 0.0f;
    pthis->timer1 = Rand_S16Offset(30, 50);
    pthis->state = ENMB_STATE_IDLE;
    EnMb_SetupAction(pthis, EnMb_ClubWaitPlayerNear);
}

void EnMb_SetupSpearPatrolTurnTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx) {
    Animation_MorphToLoop(&pthis->skelAnime, &gEnMbSpearLookLeftAndRightAnim, -4.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->timer1 = Rand_S16Offset(40, 80);
    pthis->state = ENMB_STATE_IDLE;
    EnMb_NextWaypoint(pthis, globalCtx);
    EnMb_SetupAction(pthis, EnMb_SpearPatrolTurnTowardsWaypoint);
}

void EnMb_SetupSpearGuardWalk(EnMb* pthis) {
    Animation_Change(&pthis->skelAnime, &gEnMbSpearWalkAnim, 0.0f, 0.0f, Animation_GetLastFrame(&gEnMbSpearWalkAnim),
                     ANIMMODE_LOOP, -4.0f);
    pthis->actor.speedXZ = 0.59999996f;
    pthis->timer1 = Rand_S16Offset(50, 70);
    pthis->unk_332 = 1;
    pthis->state = ENMB_STATE_WALK;
    EnMb_SetupAction(pthis, EnMb_SpearGuardWalk);
}

void EnMb_SetupSpearPatrolWalkTowardsWaypoint(EnMb* pthis) {
    f32 frameCount = Animation_GetLastFrame(&gEnMbSpearWalkAnim);

    pthis->actor.speedXZ = 0.59999996f;
    pthis->timer1 = Rand_S16Offset(50, 70);
    pthis->unk_332 = 1;
    pthis->state = ENMB_STATE_WALK;
    Animation_Change(&pthis->skelAnime, &gEnMbSpearWalkAnim, 0.0f, 0.0f, frameCount, ANIMMODE_LOOP_INTERP, -4.0f);
    EnMb_SetupAction(pthis, EnMb_SpearPatrolWalkTowardsWaypoint);
}

void EnMb_SetupSpearPrepareAndCharge(EnMb* pthis) {
    f32 frameCount = Animation_GetLastFrame(&gEnMbSpearPrepareChargeAnim);

    Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbSpearPrepareChargeAnim, -4.0f);
    pthis->state = ENMB_STATE_ATTACK;
    pthis->actor.speedXZ = 0.0f;
    pthis->timer3 = (s16)frameCount + 6;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_SPEAR_AT);
    if (pthis->actor.params == ENMB_TYPE_SPEAR_GUARD) {
        EnMb_SetupAction(pthis, EnMb_SpearGuardPrepareAndCharge);
    } else {
        EnMb_SetupAction(pthis, EnMb_SpearPatrolPrepareAndCharge);
    }
}

void EnMb_SetupSpearPatrolImmediateCharge(EnMb* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gEnMbSpearChargeAnim);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_ATTACK);
    pthis->attack = ENMB_ATTACK_SPEAR;
    pthis->state = ENMB_STATE_ATTACK;
    pthis->timer3 = 3;
    pthis->actor.speedXZ = 10.0f;
    EnMb_SetupAction(pthis, EnMb_SpearPatrolImmediateCharge);
}

void EnMb_SetupClubAttack(EnMb* pthis) {
    f32 frames = Animation_GetLastFrame(&gEnMbClubLiftClubAnim);
    s16 relYawFromPlayer;

    pthis->state = ENMB_STATE_ATTACK;
    Animation_Change(&pthis->skelAnime, &gEnMbClubLiftClubAnim, 3.0f, 0.0f, frames, ANIMMODE_ONCE_INTERP, 0.0f);
    pthis->timer3 = 1;
    relYawFromPlayer = pthis->actor.world.rot.y - pthis->actor.yawTowardsPlayer;

    if (ABS(relYawFromPlayer) <= 0x258) {
        pthis->attack = ENMB_ATTACK_CLUB_MIDDLE;
    } else if (relYawFromPlayer >= 0) {
        pthis->attack = ENMB_ATTACK_CLUB_RIGHT;
    } else {
        pthis->attack = ENMB_ATTACK_CLUB_LEFT;
    }

    EnMb_SetupAction(pthis, EnMb_ClubAttack);
}

void EnMb_SetupSpearEndChargeQuick(EnMb* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gEnMbSpearSlowDownAnim);
    pthis->state = ENMB_STATE_ATTACK_END;
    pthis->timer1 = 0;
    pthis->timer3 = 5;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_SLIDE);
    EnMb_SetupAction(pthis, EnMb_SpearEndChargeQuick);
}

void EnMb_SetupSpearPatrolEndCharge(EnMb* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gEnMbSpearSlowDownAnim);
    pthis->state = ENMB_STATE_ATTACK_END;
    pthis->actor.bgCheckFlags &= ~1;
    pthis->timer1 = 0;
    pthis->timer3 = 50;
    pthis->actor.speedXZ = -8.0f;
    pthis->actor.velocity.y = 6.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_SLIDE);
    EnMb_SetupAction(pthis, EnMb_SpearPatrolEndCharge);
}

void EnMb_SetupClubWaitAfterAttack(EnMb* pthis) {
    f32 frameCount = Animation_GetLastFrame(&gEnMbClubStandStillClubDownAnim);

    pthis->state = ENMB_STATE_ATTACK_END;
    Animation_Change(&pthis->skelAnime, &gEnMbClubStandStillClubDownAnim, 5.0f, 0.0f, frameCount, ANIMMODE_ONCE_INTERP,
                     0.0f);
    EnMb_SetupAction(pthis, EnMb_ClubWaitAfterAttack);
}

void EnMb_SetupClubDamaged(EnMb* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gEnMbClubDamagedKneelAnim);
    pthis->state = ENMB_STATE_CLUB_KNEELING;
    pthis->timer1 = 0;
    pthis->timer3 = 20;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DEAD);
    EnMb_SetupAction(pthis, EnMb_ClubDamaged);
}

void EnMb_SetupClubDamagedWhileKneeling(EnMb* pthis) {
    f32 frames = Animation_GetLastFrame(&gEnMbClubBeatenKneelingAnim);

    pthis->state = ENMB_STATE_CLUB_KNEELING_DAMAGED;
    pthis->timer1 = 0;
    pthis->timer3 = 6;
    Animation_Change(&pthis->skelAnime, &gEnMbClubBeatenKneelingAnim, 1.0f, 4.0f, frames, ANIMMODE_ONCE_INTERP, 0.0f);
    EnMb_SetupAction(pthis, EnMb_ClubDamagedWhileKneeling);
}

void EnMb_SetupClubDead(EnMb* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbClubFallOnItsBackAnim, -4.0f);
    pthis->state = ENMB_STATE_CLUB_DEAD;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->hitbox.dim.height = 80;
    pthis->hitbox.dim.radius = 95;
    pthis->timer1 = 30;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DEAD);
    EnMb_SetupAction(pthis, EnMb_ClubDead);
}

void EnMb_SetupStunned(EnMb* pthis) {
    pthis->state = ENMB_STATE_STUNNED;
    pthis->actor.speedXZ = 0.0f;
    Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);
    if (pthis->damageEffect == ENMB_DMGEFF_STUN_ICE) {
        pthis->iceEffectTimer = 40;
    } else {
        if (pthis->actor.params != ENMB_TYPE_CLUB) {
            Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gEnMbSpearDamagedFromFrontAnim, 0.0f);
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    }
    EnMb_SetupAction(pthis, EnMb_Stunned);
}

void EnMb_Stunned(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
        player->stateFlags2 &= ~0x80;
        player->actor.parent = NULL;
        player->unk_850 = 200;
        func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.world.rot.y, 4.0f);
        pthis->attack = ENMB_ATTACK_NONE;
    }

    if (pthis->actor.colorFilterTimer == 0) {
        if (pthis->actor.params == ENMB_TYPE_CLUB) {
            if (pthis->actor.colChkInfo.health == 0) {
                EnMb_SetupClubDead(pthis);
            } else if (pthis->state == ENMB_STATE_CLUB_KNEELING) {
                /* dead code: the setup for pthis action sets state to something else */
                EnMb_SetupClubDamagedWhileKneeling(pthis);
            } else {
                EnMb_SetupClubWaitPlayerNear(pthis);
            }
        } else {
            if (pthis->actor.colChkInfo.health == 0) {
                EnMb_SetupSpearDead(pthis);
            } else {
                EnMb_SetupSpearDamaged(pthis);
            }
        }
    }
}

void EnMb_SpearGuardLookAround(EnMb* pthis, GlobalContext* globalCtx) {
    s16 timer1;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer1 == 0) {
        timer1 = 0;
    } else {
        pthis->timer1--;
        timer1 = pthis->timer1;
    }
    if (timer1 == 0 && Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        EnMb_SetupSpearGuardWalk(pthis);
    }
}

void EnMb_SpearPatrolTurnTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx) {
    s16 relYawFromPlayer;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer1 == 0) {
        pthis->yawToWaypoint = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->waypointPos);
        if (Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->yawToWaypoint, 1, 0x3E8, 0) == 0) {
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
            EnMb_SetupSpearPatrolWalkTowardsWaypoint(pthis);
        }
    } else {
        pthis->timer1--;
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y, 1, 0x3E8, 0);
    }

    if (ABS(pthis->actor.yDistToPlayer) <= 20.0f && EnMb_IsPlayerInCorridor(pthis, globalCtx)) {
        relYawFromPlayer = pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer;
        if (ABS(relYawFromPlayer) <= 0x4000 || (func_8002DDE4(globalCtx) && pthis->actor.xzDistToPlayer < 160.0f)) {
            EnMb_FindWaypointTowardsPlayer(pthis, globalCtx);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_VOICE);
            EnMb_SetupSpearPrepareAndCharge(pthis);
        }
    }
}

/**
 * Slow down and resume walking.
 */
void EnMb_SpearEndChargeQuick(EnMb* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.5f, 1.0f, 0.0f);
    if (pthis->actor.speedXZ > 1.0f) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 5.0f, 3, 4.0f, 100, 15, false);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer1 == 0) {
            pthis->timer3--;
            if (pthis->timer3 == 0) {
                /* Play the charge animation in reverse: let go of the spear and stand normally */
                Animation_Change(&pthis->skelAnime, &gEnMbSpearPrepareChargeAnim, -1.0f,
                                 Animation_GetLastFrame(&gEnMbSpearPrepareChargeAnim), 0.0f, ANIMMODE_ONCE, 0.0f);
                pthis->timer1 = 1;
                pthis->actor.speedXZ = 0.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_SPEAR_NORM);
            }
        } else {
            if (pthis->actor.params <= ENMB_TYPE_SPEAR_GUARD) {
                EnMb_SetupSpearGuardWalk(pthis);
                pthis->timer1 = pthis->timer2 = pthis->timer3 = 80;
            } else {
                EnMb_SetupSpearPatrolTurnTowardsWaypoint(pthis, globalCtx);
            }
        }
    }
}

void EnMb_ClubWaitAfterAttack(EnMb* pthis, GlobalContext* globalCtx) {
    pthis->attack = ENMB_ATTACK_NONE;
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnMb_SetupClubWaitPlayerNear(pthis);
    }
}

/**
 * Slow down, charge again if the player is near, or resume walking.
 */
void EnMb_SpearPatrolEndCharge(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 lastFrame;
    s16 relYawFromPlayer;
    s16 yawPlayerToWaypoint;

    if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
        player->stateFlags2 &= ~0x80;
        player->actor.parent = NULL;
        player->unk_850 = 200;
        func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.world.rot.y, 4.0f);
    }

    if (pthis->actor.bgCheckFlags & 1) {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 1.5f, 0.0f);

        if (pthis->actor.speedXZ > 1.0f) {
            Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 5.0f, 3, 4.0f, 100, 15, false);
        }

        if (pthis->timer1 != 0) {
            pthis->timer3--;
            if (pthis->timer3 == 0) {
                relYawFromPlayer = pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer;

                if (ABS(pthis->actor.yDistToPlayer) <= 20.0f && EnMb_IsPlayerInCorridor(pthis, globalCtx) &&
                    ABS(relYawFromPlayer) <= 0x4000 && pthis->actor.xzDistToPlayer <= 200.0f) {
                    EnMb_SetupSpearPrepareAndCharge(pthis);
                } else {
                    lastFrame = Animation_GetLastFrame(&gEnMbSpearPrepareChargeAnim);
                    /* Play the charge animation in reverse: let go of the spear and stand normally */
                    Animation_Change(&pthis->skelAnime, &gEnMbSpearPrepareChargeAnim, -1.0f, lastFrame, 0.0f,
                                     ANIMMODE_ONCE, 0.0f);
                    pthis->actor.speedXZ = 0.0f;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_SPEAR_NORM);
                }
            } else {
                if (pthis->actor.xzDistToPlayer <= 160.0f) {
                    pthis->actor.speedXZ = -5.0f;
                } else {
                    pthis->actor.speedXZ = 0.0f;
                }
            }
        }

        if (SkelAnime_Update(&pthis->skelAnime)) {
            if (pthis->timer1 == 0) {
                lastFrame = Animation_GetLastFrame(&gEnMbSpearChargeAnim);
                Animation_Change(&pthis->skelAnime, &gEnMbSpearChargeAnim, 0.5f, 0.0f, lastFrame, ANIMMODE_LOOP_INTERP,
                                 0.0f);
                pthis->timer1 = 1;
            } else {
                yawPlayerToWaypoint =
                    Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->waypointPos) - pthis->actor.yawTowardsPlayer;

                if (ABS(yawPlayerToWaypoint) <= 0x4000) {
                    EnMb_SetupSpearPatrolTurnTowardsWaypoint(pthis, globalCtx);
                } else {
                    EnMb_SetupSpearPatrolWalkTowardsWaypoint(pthis);
                }
            }
        }
    }
}

/**
 * Prepare charge (animation), then charge until the player isn't in front.
 */
void EnMb_SpearGuardPrepareAndCharge(EnMb* pthis, GlobalContext* globalCtx) {
    s32 prevFrame;
    s16 relYawTowardsPlayerAbs = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (relYawTowardsPlayerAbs < 0) {
        relYawTowardsPlayerAbs = -relYawTowardsPlayerAbs;
    }

    prevFrame = pthis->skelAnime.curFrame;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        Animation_PlayLoop(&pthis->skelAnime, &gEnMbSpearChargeAnim);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_ATTACK);
    }

    if (pthis->timer3 != 0) {
        pthis->timer3--;
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0xBB8, 0);
    } else {
        pthis->actor.speedXZ = 10.0f;
        pthis->attack = ENMB_ATTACK_SPEAR;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 5.0f, 3, 4.0f, 100, 15, false);
        if (prevFrame != (s32)pthis->skelAnime.curFrame &&
            ((s32)pthis->skelAnime.curFrame == 2 || (s32)pthis->skelAnime.curFrame == 6)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DASH);
        }
    }

    if (relYawTowardsPlayerAbs > 0x1388) {
        pthis->attack = ENMB_ATTACK_NONE;
        EnMb_SetupSpearEndChargeQuick(pthis);
    }
}

void EnMb_ClubAttack(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    Vec3f effSpawnPos;
    Vec3f effWhiteShockwaveDynamics = { 0.0f, 0.0f, 0.0f };
    f32 flamesParams[] = { 18.0f, 18.0f, 0.0f };
    s16 flamesUnused[] = { 20, 40, 0 };
    s16 relYawTarget[] = { -0x9C4, 0, 0xDAC };

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, relYawTarget[pthis->attack - 1] + pthis->actor.world.rot.y, 1, 0x2EE, 0);

    if (pthis->attackCollider.base.atFlags & AT_HIT) {
        pthis->attackCollider.base.atFlags &= ~AT_HIT;
        if (pthis->attackCollider.base.at == &player->actor) {
            u8 prevPlayerInvincibilityTimer = player->invincibilityTimer;

            if (player->invincibilityTimer < 0) {
                if (player->invincibilityTimer <= -40) {
                    player->invincibilityTimer = 0;
                } else {
                    player->invincibilityTimer = 0;
                    globalCtx->damagePlayer(globalCtx, -8);
                }
            }

            func_8002F71C(globalCtx, &pthis->actor, (650.0f - pthis->actor.xzDistToPlayer) * 0.04f + 4.0f,
                          pthis->actor.world.rot.y, 8.0f);

            player->invincibilityTimer = prevPlayerInvincibilityTimer;
        }
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer3 != 0) {
            pthis->timer3--;
            if (pthis->timer3 == 0) {
                f32 lastAnimFrame = Animation_GetLastFrame(&gEnMbClubStrikeDownAnim);
                Animation_Change(&pthis->skelAnime, &gEnMbClubStrikeDownAnim, 1.5f, 0.0f, lastAnimFrame,
                                 ANIMMODE_ONCE_INTERP, 0.0f);
            }
        } else {
            effSpawnPos = pthis->effSpawnPos;
            effSpawnPos.y = pthis->actor.floorHeight;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MONBLIN_HAM_LAND);
            func_800AA000(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
            EffectSsBlast_SpawnWhiteShockwave(globalCtx, &effSpawnPos, &effWhiteShockwaveDynamics,
                                              &effWhiteShockwaveDynamics);
            func_80033480(globalCtx, &effSpawnPos, 2.0f, 3, 0x12C, 0xB4, 1);
            Camera_AddQuake(&globalCtx->mainCamera, 2, 0x19, 5);
            func_800358DC(&pthis->actor, &effSpawnPos, &pthis->actor.world.rot, flamesParams, 20, flamesUnused, globalCtx,
                          -1, 0);
            EnMb_SetupClubWaitAfterAttack(pthis);
        }
    } else {
        if (pthis->timer3 != 0 && pthis->skelAnime.curFrame == 6.0f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MONBLIN_HAM_UP);

        } else if (pthis->timer3 == 0 && pthis->skelAnime.curFrame == 3.0f) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MONBLIN_HAM_DOWN);
        }
    }
}

/**
 * Prepare charge (animation), then charge to the end of the floor collision.
 */
void EnMb_SpearPatrolPrepareAndCharge(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 prevFrame;
    s32 hasHitPlayer = false;
    s32 endCharge = !Actor_TestFloorInDirection(&pthis->actor, globalCtx, 110.0f, pthis->actor.world.rot.y);

    prevFrame = (s32)pthis->skelAnime.curFrame;
    if (SkelAnime_Update(&pthis->skelAnime)) {
        Animation_PlayLoop(&pthis->skelAnime, &gEnMbSpearChargeAnim);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_ATTACK);
    }

    if (pthis->timer3 != 0) {
        pthis->timer3--;
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 1, 0x1F40, 0);
        endCharge = false;
    } else {
        pthis->actor.speedXZ = 10.0f;
        pthis->attack = ENMB_ATTACK_SPEAR;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 5.0f, 3, 4.0f, 100, 15, false);
        if (prevFrame != (s32)pthis->skelAnime.curFrame &&
            ((s32)pthis->skelAnime.curFrame == 2 || (s32)pthis->skelAnime.curFrame == 6)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DASH);
        }
    }

    if (pthis->attackCollider.base.atFlags & AT_HIT) {
        if (pthis->attackCollider.base.at == &player->actor) {
            if (!endCharge && !(player->stateFlags2 & 0x80)) {
                if (player->invincibilityTimer < 0) {
                    if (player->invincibilityTimer < -39) {
                        player->invincibilityTimer = 0;
                    } else {
                        player->invincibilityTimer = 0;
                        globalCtx->damagePlayer(globalCtx, -8);
                    }
                }
                if (!(pthis->attackCollider.base.atFlags & AT_BOUNCED)) {
                    Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
                }
                if (globalCtx->grabPlayer(globalCtx, player)) {
                    player->actor.parent = &pthis->actor;
                }
            }
            hasHitPlayer = true;
        } else {
            pthis->attackCollider.base.atFlags &= ~AT_HIT;
        }
    }

    if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
        player->actor.world.pos.x = pthis->actor.world.pos.x + Math_CosS(pthis->actor.shape.rot.y) * 10.0f +
                                    Math_SinS(pthis->actor.shape.rot.y) * 89.0f;
        hasHitPlayer = true;
        player->actor.world.pos.z = pthis->actor.world.pos.z + Math_SinS(pthis->actor.shape.rot.y) * 10.0f +
                                    Math_CosS(pthis->actor.shape.rot.y) * 89.0f;
        player->unk_850 = 0;
        player->actor.speedXZ = 0.0f;
        player->actor.velocity.y = 0.0f;
    }

    if (endCharge) {
        if (hasHitPlayer || (player->stateFlags2 & 0x80)) {
            pthis->attackCollider.base.atFlags &= ~AT_HIT;
            if (player->stateFlags2 & 0x80) {
                player->stateFlags2 &= ~0x80;
                player->actor.parent = NULL;
                player->unk_850 = 200;
                func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.world.rot.y, 4.0f);
            }
        }
        pthis->attack = ENMB_ATTACK_NONE;
        pthis->actor.speedXZ = -10.0f;
        EnMb_SetupSpearPatrolEndCharge(pthis);
    }
}

/**
 * Charge and follow the path, until hitting the player or, after some time, reaching home.
 */
void EnMb_SpearPatrolImmediateCharge(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 prevFrame;
    s32 hasHitPlayer = false;
    s32 endCharge = !Actor_TestFloorInDirection(&pthis->actor, globalCtx, 110.0f, pthis->actor.world.rot.y);

    prevFrame = (s32)pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);

    Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 5.0f, 3, 4.0f, 100, 15, false);
    if (prevFrame != (s32)pthis->skelAnime.curFrame &&
        ((s32)pthis->skelAnime.curFrame == 2 || (s32)pthis->skelAnime.curFrame == 6)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DASH);
    }

    if (pthis->attackCollider.base.atFlags & AT_HIT) {
        if (pthis->attackCollider.base.at == &player->actor) {
            if (!endCharge && !(player->stateFlags2 & 0x80)) {
                if (player->invincibilityTimer < 0) {
                    if (player->invincibilityTimer <= -40) {
                        player->invincibilityTimer = 0;
                    } else {
                        player->invincibilityTimer = 0;
                        globalCtx->damagePlayer(globalCtx, -8);
                    }
                }
                if (!(pthis->attackCollider.base.atFlags & AT_BOUNCED)) {
                    Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
                }
                if (globalCtx->grabPlayer(globalCtx, player)) {
                    player->actor.parent = &pthis->actor;
                }
            }
            hasHitPlayer = true;
        } else {
            pthis->attackCollider.base.atFlags &= ~AT_HIT;
        }
    }

    if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
        player->actor.world.pos.x = pthis->actor.world.pos.x + Math_CosS(pthis->actor.shape.rot.y) * 10.0f +
                                    Math_SinS(pthis->actor.shape.rot.y) * 89.0f;
        hasHitPlayer = true;
        player->actor.world.pos.z = pthis->actor.world.pos.z + Math_SinS(pthis->actor.shape.rot.y) * 10.0f +
                                    Math_CosS(pthis->actor.shape.rot.y) * 89.0f;
        player->unk_850 = 0;
        player->actor.speedXZ = 0.0f;
        player->actor.velocity.y = 0.0f;
    }

    if (endCharge) {
        if (hasHitPlayer || (player->stateFlags2 & 0x80)) {
            pthis->attackCollider.base.atFlags &= ~AT_HIT;
            if (player->stateFlags2 & 0x80) {
                player->stateFlags2 &= ~0x80;
                player->actor.parent = NULL;
                player->unk_850 = 200;
                func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.world.rot.y, 4.0f);
            }
            pthis->attack = ENMB_ATTACK_NONE;
            pthis->actor.speedXZ = -10.0f;
            EnMb_SetupSpearPatrolEndCharge(pthis);
            pthis->timer3 = 1;
        } else {
            pthis->timer3--;
            EnMb_NextWaypoint(pthis, globalCtx);
        }
    }

    EnMb_FaceWaypoint(pthis, globalCtx);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->timer3 == 0 && Math_Vec3f_DistXZ(&pthis->actor.home.pos, &pthis->actor.world.pos) < 80.0f) {
        pthis->attack = ENMB_ATTACK_NONE;
        EnMb_SetupSpearEndChargeQuick(pthis);
    }
}

void EnMb_ClubDamaged(EnMb* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer3 != 0) {
            Animation_PlayOnce(&pthis->skelAnime, &gEnMbClubStandUpAnim);
            pthis->timer3 = 0;
            func_800AA000(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
            Camera_AddQuake(&globalCtx->mainCamera, 2, 25, 5);
        } else {
            EnMb_SetupClubWaitPlayerNear(pthis);
        }
    }
}

void EnMb_ClubDamagedWhileKneeling(EnMb* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer3 != 0) {
            pthis->timer3--;
            if (pthis->timer3 == 0) {
                if (pthis->timer1 == 0) {
                    Animation_Change(&pthis->skelAnime, &gEnMbClubStandUpAnim, 3.0f, 0.0f,
                                     Animation_GetLastFrame(&gEnMbClubStandUpAnim), ANIMMODE_ONCE_INTERP, 0.0f);
                    pthis->timer1 = 1;
                    pthis->timer3 = 6;
                } else {
                    Animation_Change(&pthis->skelAnime, &gEnMbClubStandUpAnim, 3.0f, 0.0f,
                                     Animation_GetLastFrame(&gEnMbClubStandUpAnim), ANIMMODE_ONCE_INTERP, 0.0f);
                }
            }
        } else {
            EnMb_SetupClubWaitPlayerNear(pthis);
        }
    }
}

void EnMb_ClubDead(EnMb* pthis, GlobalContext* globalCtx) {
    Vec3f effPos;
    Vec3f effPosBase;

    effPos = pthis->actor.world.pos;
    effPos.x += Math_SinS(pthis->actor.shape.rot.y) * -70.0f;
    effPos.z += Math_CosS(pthis->actor.shape.rot.y) * -70.0f;
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    effPosBase = effPos;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer1 > 0) {
            Vec3f effZeroVec = { 0.0f, 0.0f, 0.0f };
            s32 i;

            pthis->timer1--;
            for (i = 4; i >= 0; i--) {
                effPos.x = Rand_CenteredFloat(240.0f) + effPosBase.x;
                effPos.y = Rand_CenteredFloat(15.0f) + (effPosBase.y + 20.0f);
                effPos.z = Rand_CenteredFloat(240.0f) + effPosBase.z;
                EffectSsDeadDb_Spawn(globalCtx, &effPos, &effZeroVec, &effZeroVec, 230, 7, 255, 255, 255, 255, 0, 255,
                                     0, 1, 9, true);
            }
        } else {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &effPos, 0xC0);
            Actor_Kill(&pthis->actor);
        }
    } else if ((s32)pthis->skelAnime.curFrame == 15 || (s32)pthis->skelAnime.curFrame == 22) {
        func_800AA000(pthis->actor.xzDistToPlayer, 0xFF, 0x14, 0x96);
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &effPos, 50.0f, 10, 3.0f, 400, 60, false);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        Camera_AddQuake(&globalCtx->mainCamera, 2, 25, 5);
    }
}

/**
 * Walk around the home point, face and charge the player if close.
 */
void EnMb_SpearGuardWalk(EnMb* pthis, GlobalContext* globalCtx) {
    s32 prevFrame;
    s32 beforeCurFrame;
    s32 pad1;
    s32 pad2;
    Player* player = GET_PLAYER(globalCtx);
    s16 relYawTowardsPlayer = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    s16 yawTowardsHome;
    f32 playSpeedAbs;

    relYawTowardsPlayer = ABS(relYawTowardsPlayer);
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.59999996f, 0.1f, 1.0f, 0.0f);
    pthis->skelAnime.playSpeed = pthis->actor.speedXZ;
    prevFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);

    playSpeedAbs = ABS(pthis->skelAnime.playSpeed);
    beforeCurFrame = pthis->skelAnime.curFrame - playSpeedAbs;
    playSpeedAbs = ABS(pthis->skelAnime.playSpeed);
    if (pthis->timer3 == 0 &&
        Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < pthis->playerDetectionRange) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x2EE, 0);
        pthis->actor.flags |= ACTOR_FLAG_0;
        if (pthis->actor.xzDistToPlayer < 500.0f && relYawTowardsPlayer < 0x1388) {
            EnMb_SetupSpearPrepareAndCharge(pthis);
        }
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        if (Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) > pthis->maxHomeDist || pthis->timer2 != 0) {
            yawTowardsHome = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);
            Math_SmoothStepToS(&pthis->actor.world.rot.y, yawTowardsHome, 1, 0x2EE, 0);
        }
        if (pthis->timer2 != 0) {
            pthis->timer2--;
        }
        if (pthis->timer3 != 0) {
            pthis->timer3--;
        }
        if (pthis->timer2 == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_VOICE);
        }
        pthis->timer1--;
        if (pthis->timer1 == 0) {
            if (Rand_ZeroOne() > 0.7f) {
                pthis->timer1 = Rand_S16Offset(50, 70);
                pthis->timer2 = Rand_S16Offset(15, 40);
            } else {
                EnMb_SetupSpearGuardLookAround(pthis);
            }
        }
    }

    if (prevFrame != (s32)pthis->skelAnime.curFrame) {
        if ((beforeCurFrame <= 1 && prevFrame + (s32)playSpeedAbs >= 1) ||
            (beforeCurFrame <= 20 && prevFrame + (s32)playSpeedAbs >= 20)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnMb_SpearPatrolWalkTowardsWaypoint(EnMb* pthis, GlobalContext* globalCtx) {
    s32 prevFrame;
    s32 beforeCurFrame;
    s16 relYawTowardsPlayer;
    f32 yDistToPlayerAbs;
    f32 playSpeedABS;

    if (Math_Vec3f_DistXZ(&pthis->waypointPos, &pthis->actor.world.pos) <= 8.0f ||
        (Rand_ZeroOne() < 0.1f && Math_Vec3f_DistXZ(&pthis->actor.home.pos, &pthis->actor.world.pos) <= 4.0f)) {
        EnMb_SetupSpearPatrolTurnTowardsWaypoint(pthis, globalCtx);
    } else {
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.59999996f, 0.1f, 1.0f, 0.0f);
        pthis->skelAnime.playSpeed = 2.0f * pthis->actor.speedXZ;
    }

    pthis->yawToWaypoint = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->waypointPos);
    Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->yawToWaypoint, 1, 0x5DC, 0);

    yDistToPlayerAbs = (pthis->actor.yDistToPlayer >= 0.0f) ? pthis->actor.yDistToPlayer : -pthis->actor.yDistToPlayer;
    if (yDistToPlayerAbs <= 20.0f && EnMb_IsPlayerInCorridor(pthis, globalCtx)) {
        relYawTowardsPlayer = (pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer);
        if (ABS(relYawTowardsPlayer) <= 0x4000 || (func_8002DDE4(globalCtx) && pthis->actor.xzDistToPlayer < 160.0f)) {
            EnMb_FindWaypointTowardsPlayer(pthis, globalCtx);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_VOICE);
            EnMb_SetupSpearPrepareAndCharge(pthis);
            return;
        }
    }

    if (pthis->timer2 != 0) {
        pthis->timer2--;
    }
    if (pthis->timer3 != 0) {
        pthis->timer3--;
    }
    if (pthis->timer2 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_VOICE);
        pthis->timer2 = Rand_S16Offset(30, 70);
    }

    prevFrame = pthis->skelAnime.curFrame;
    SkelAnime_Update(&pthis->skelAnime);
    playSpeedABS = ABS(pthis->skelAnime.playSpeed);
    beforeCurFrame = pthis->skelAnime.curFrame - playSpeedABS;
    playSpeedABS = (pthis->skelAnime.playSpeed >= 0.0f) ? pthis->skelAnime.playSpeed : -pthis->skelAnime.playSpeed;
    if (prevFrame != (s32)pthis->skelAnime.curFrame) {
        if ((beforeCurFrame <= 1 && (s32)playSpeedABS + prevFrame >= 1) ||
            (beforeCurFrame <= 20 && (s32)playSpeedABS + prevFrame >= 20)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_WALK);
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnMb_ClubWaitPlayerNear(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    s16 relYawFromPlayer = pthis->actor.world.rot.y - pthis->actor.yawTowardsPlayer;

    SkelAnime_Update(&pthis->skelAnime);
    if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < pthis->playerDetectionRange &&
        !(player->stateFlags1 & 0x4000000) && ABS(relYawFromPlayer) < 0x3E80) {
        EnMb_SetupClubAttack(pthis);
    }
}

void EnMb_SetupSpearDamaged(EnMb* pthis) {
    s16 relYawTowardsPlayer = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (ABS(relYawTowardsPlayer) <= 0x4000) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbSpearDamagedFromFrontAnim, -4.0f);
        pthis->actor.speedXZ = -8.0f;
    } else {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbSpearDamagedFromBehindAnim, -4.0f);
        pthis->actor.speedXZ = 8.0f;
    }

    pthis->timer1 = 30;
    pthis->state = ENMB_STATE_SPEAR_SPEARPATH_DAMAGED;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DEAD);
    EnMb_SetupAction(pthis, EnMb_SpearDamaged);
}

void EnMb_SpearDamaged(EnMb* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.params <= ENMB_TYPE_SPEAR_GUARD) {
            EnMb_SetupSpearGuardLookAround(pthis);
        } else {
            EnMb_SetupSpearPatrolImmediateCharge(pthis);
        }
    }
}

void EnMb_SetupSpearDead(EnMb* pthis) {
    s16 relYawTowardsPlayer = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (ABS(relYawTowardsPlayer) <= 0x4000) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbSpearFallOnItsBackAnim, -4.0f);
        pthis->actor.speedXZ = -8.0f;
    } else {
        /* The gEnMbSpearFallFaceDownAnim animation was probably meant to be used here */
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gEnMbSpearFallOnItsBackAnim, -4.0f);
        pthis->actor.speedXZ = 8.0f;
    }

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->timer1 = 30;
    pthis->state = ENMB_STATE_SPEAR_SPEARPATH_DAMAGED;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_MORIBLIN_DEAD);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnMb_SetupAction(pthis, EnMb_SpearDead);
}

void EnMb_SpearDead(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);

    if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
        player->stateFlags2 &= ~0x80;
        player->actor.parent = NULL;
        player->unk_850 = 200;
        func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.world.rot.y, 4.0f);
        pthis->attack = ENMB_ATTACK_NONE;
    }

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->timer1 > 0) {
            Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
            s32 i;
            Vec3f effPos;

            pthis->actor.shape.shadowScale = 0.0f;
            pthis->timer1--;
            for (i = 4; i >= 0; i--) {
                effPos.x = Rand_CenteredFloat(110.0f) + pthis->actor.world.pos.x;
                effPos.y = Rand_CenteredFloat(15.0f) + (pthis->actor.world.pos.y + 20.0f);
                effPos.z = Rand_CenteredFloat(110.0f) + pthis->actor.world.pos.z;

                EffectSsDeadDb_Spawn(globalCtx, &effPos, &zeroVec, &zeroVec, 100, 7, 255, 255, 255, 255, 0, 255, 0, 1,
                                     9, true);
            }
        } else {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xE0);
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnMb_SpearUpdateAttackCollider(Actor* thisx, GlobalContext* globalCtx) {
    Vec3f quadModel0 = { 1000.0f, 1500.0f, 0.0f };
    Vec3f quadModel1 = { -1000.0f, 1500.0f, 0.0f };
    Vec3f quadModel2 = { 1000.0f, 1500.0f, 4500.0f };
    Vec3f quadModel3 = { -1000.0f, 1500.0f, 4500.0f };
    EnMb* pthis = (EnMb*)thisx;

    if (pthis->actor.params >= ENMB_TYPE_SPEAR_PATROL) {
        quadModel0.x += 2000.0f;
        quadModel0.z = -4000.0f;
        quadModel1.z = -4000.0f;
        quadModel2.x += 2000.0f;
        quadModel1.x -= 2000.0f;
        quadModel3.x -= 2000.0f;
        quadModel2.z += 4000.0f;
        quadModel3.z += 4000.0f;
    }
    Matrix_MultVec3f(&quadModel0, &pthis->attackCollider.dim.quad[1]);
    Matrix_MultVec3f(&quadModel1, &pthis->attackCollider.dim.quad[0]);
    Matrix_MultVec3f(&quadModel2, &pthis->attackCollider.dim.quad[3]);
    Matrix_MultVec3f(&quadModel3, &pthis->attackCollider.dim.quad[2]);
    Collider_SetQuadVertices(&pthis->attackCollider, &pthis->attackCollider.dim.quad[0],
                             &pthis->attackCollider.dim.quad[1], &pthis->attackCollider.dim.quad[2],
                             &pthis->attackCollider.dim.quad[3]);
}

void EnMb_ClubUpdateAttackCollider(Actor* thisx, GlobalContext* globalCtx) {
    EnMb* pthis = (EnMb*)thisx;

    Matrix_MultVec3f(&quadModel_124[0], &pthis->attackCollider.dim.quad[1]);
    Matrix_MultVec3f(&quadModel_124[1], &pthis->attackCollider.dim.quad[0]);
    Matrix_MultVec3f(&quadModel_124[2], &pthis->attackCollider.dim.quad[3]);
    Matrix_MultVec3f(&quadModel_124[3], &pthis->attackCollider.dim.quad[2]);
    Collider_SetQuadVertices(&pthis->attackCollider, &pthis->attackCollider.dim.quad[0],
                             &pthis->attackCollider.dim.quad[1], &pthis->attackCollider.dim.quad[2],
                             &pthis->attackCollider.dim.quad[3]);
}

void EnMb_CheckColliding(EnMb* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->frontShielding.base.acFlags & AC_HIT) {
        pthis->frontShielding.base.acFlags &= ~(AC_HIT | AC_BOUNCED);
        pthis->hitbox.base.acFlags &= ~AC_HIT;
    } else if ((pthis->hitbox.base.acFlags & AC_HIT) && pthis->state >= ENMB_STATE_STUNNED) {
        pthis->hitbox.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != ENMB_DMGEFF_IGNORE &&
            pthis->actor.colChkInfo.damageEffect != ENMB_DMGEFF_FREEZE) {
            if ((player->stateFlags2 & 0x80) && player->actor.parent == &pthis->actor) {
                player->stateFlags2 &= ~0x80;
                player->actor.parent = NULL;
                player->unk_850 = 200;
                func_8002F71C(globalCtx, &pthis->actor, 6.0f, pthis->actor.world.rot.y, 6.0f);
            }
            pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
            pthis->attack = ENMB_ATTACK_NONE;
            Actor_SetDropFlag(&pthis->actor, &pthis->hitbox.info, false);
            if (pthis->actor.colChkInfo.damageEffect == ENMB_DMGEFF_STUN ||
                pthis->actor.colChkInfo.damageEffect == ENMB_DMGEFF_STUN_ICE) {
                if (pthis->state != ENMB_STATE_STUNNED) {
                    Actor_ApplyDamage(&pthis->actor);
                    EnMb_SetupStunned(pthis);
                }
            } else {
                Actor_ApplyDamage(&pthis->actor);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFA, 0, 0xC);
                if (pthis->actor.params == ENMB_TYPE_CLUB) {
                    if (pthis->actor.colChkInfo.health == 0) {
                        EnMb_SetupClubDead(pthis);
                    } else if (pthis->state != ENMB_STATE_CLUB_KNEELING) {
                        EnMb_SetupClubDamaged(pthis);
                    }
                } else {
                    if (pthis->actor.colChkInfo.health == 0) {
                        EnMb_SetupSpearDead(pthis);
                    } else {
                        EnMb_SetupSpearDamaged(pthis);
                    }
                }
            }
        }
    }
}

void EnMb_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMb* pthis = (EnMb*)thisx;
    s32 pad;

    EnMb_CheckColliding(pthis, globalCtx);
    if (thisx->colChkInfo.damageEffect != ENMB_DMGEFF_FREEZE) {
        pthis->actionFunc(pthis, globalCtx);
        Actor_MoveForward(thisx);
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 40.0f, 40.0f, 70.0f, 0x1D);
        Actor_SetFocus(thisx, thisx->scale.x * 4500.0f);
        Collider_UpdateCylinder(thisx, &pthis->hitbox);
        if (thisx->colChkInfo.health <= 0) {
            pthis->hitbox.dim.pos.x += Math_SinS(thisx->shape.rot.y) * (-4400.0f * thisx->scale.y);
            pthis->hitbox.dim.pos.z += Math_CosS(thisx->shape.rot.y) * (-4400.0f * thisx->scale.y);
        }
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->hitbox.base);
        if (pthis->state >= ENMB_STATE_STUNNED &&
            (thisx->params == ENMB_TYPE_CLUB || pthis->state != ENMB_STATE_ATTACK)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->hitbox.base);
        }
        if (pthis->state >= ENMB_STATE_IDLE) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->frontShielding.base);
        }
        if (pthis->attack > ENMB_ATTACK_NONE) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->attackCollider.base);
        }
    }
}

void EnMb_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    s32 bodyPart = -1;
    EnMb* pthis = (EnMb*)thisx;
    Vec3f bodyPartPos;

    if (pthis->actor.params == ENMB_TYPE_CLUB) {
        if (limbIndex == ENMB_LIMB_LHAND) {
            Matrix_MultVec3f(&effSpawnPosModel_127, &pthis->effSpawnPos);
            if (pthis->attack > ENMB_ATTACK_NONE) {
                EnMb_ClubUpdateAttackCollider(&pthis->actor, globalCtx);
            }
        }
        Actor_SetFeetPos(&pthis->actor, limbIndex, ENMB_LIMB_LFOOT, &feetPos_127, ENMB_LIMB_RFOOT, &feetPos_127);
    }

    if (pthis->iceEffectTimer != 0) {
        switch (limbIndex) {
            case ENMB_LIMB_HEAD:
                bodyPart = 0;
                break;
            case ENMB_LIMB_LHAND:
                bodyPart = 1;
                break;
            case ENMB_LIMB_RHAND:
                bodyPart = 2;
                break;
            case ENMB_LIMB_LSHOULDER:
                bodyPart = 3;
                break;
            case ENMB_LIMB_RSHOULDER:
                bodyPart = 4;
                break;
            case ENMB_LIMB_CHEST:
                bodyPart = 5;
                break;
            case ENMB_LIMB_LTHIGH:
                bodyPart = 6;
                break;
            case ENMB_LIMB_RTHIGH:
                bodyPart = 7;
                break;
            case ENMB_LIMB_LFOOT:
                bodyPart = 8;
                break;
            case ENMB_LIMB_RFOOT:
                bodyPart = 9;
                break;
        }
        if (bodyPart >= 0) {
            Matrix_MultVec3f(&zeroVec_127, &bodyPartPos);
            pthis->bodyPartsPos[bodyPart].x = bodyPartPos.x;
            pthis->bodyPartsPos[bodyPart].y = bodyPartPos.y;
            pthis->bodyPartsPos[bodyPart].z = bodyPartPos.z;
        }
    }
}

void EnMb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 i;
    f32 scale;
    Vec3f frontShieldingTri0[3];
    Vec3f frontShieldingTri1[3];
    s32 bodyPartIdx;
    EnMb* pthis = (EnMb*)thisx;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, EnMb_PostLimbDraw, thisx);

    if (thisx->params != ENMB_TYPE_CLUB) {
        if (pthis->attack > ENMB_ATTACK_NONE) {
            EnMb_SpearUpdateAttackCollider(thisx, globalCtx);
        }
        for (i = 0; i < 3; i++) {
            Matrix_MultVec3f(&frontShieldingTriModel0_128[i], &frontShieldingTri0[i]);
            Matrix_MultVec3f(&frontShieldingTriModel1_128[i], &frontShieldingTri1[i]);
        }
        Collider_SetTrisVertices(&pthis->frontShielding, 0, &frontShieldingTri0[0], &frontShieldingTri0[1],
                                 &frontShieldingTri0[2]);
        Collider_SetTrisVertices(&pthis->frontShielding, 1, &frontShieldingTri1[0], &frontShieldingTri1[1],
                                 &frontShieldingTri1[2]);
    }

    if (pthis->iceEffectTimer != 0) {
        thisx->colorFilterTimer++;
        if (pthis->iceEffectTimer >= 0) {
            pthis->iceEffectTimer--;
        }
        if ((pthis->iceEffectTimer % 4) == 0) {
            scale = 2.5f;
            if (thisx->params == ENMB_TYPE_CLUB) {
                scale = 4.0f;
            }
            bodyPartIdx = pthis->iceEffectTimer >> 2;
            EffectSsEnIce_SpawnFlyingVec3s(globalCtx, thisx, &pthis->bodyPartsPos[bodyPartIdx], 150, 150, 150, 250, 235,
                                           245, 255, scale);
        }
    }
}

void EnMb_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    unused_127 = { 1100.0f, -700.0f, 0.0f };

    feetPos_127 = { 0.0f, 0.0f, 0.0f };

    effSpawnPosModel_127 = { 0.0f, -8000.0f, 0.0f };

    zeroVec_127 = { 0.0f, 0.0f, 0.0f };

    En_Mb_InitVars = {
        ACTOR_EN_MB,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_MB,
        sizeof(EnMb),
        (ActorFunc)EnMb_Init,
        (ActorFunc)EnMb_Destroy,
        (ActorFunc)EnMb_Update,
        (ActorFunc)EnMb_Draw,
        (ActorFunc)EnMb_Reset,
    };

    sHitboxInit = {
        {
            COLTYPE_HIT0,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
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

    sFrontShieldingInit = {
        {
            COLTYPE_METAL,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_TRIS,
        },
        2,
        sFrontShieldingTrisInit,
    };

    sAttackColliderInit = {
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
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sSpearMoblinDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Deku stick    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Slingshot     */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
        /* Explosive     */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Boomerang     */ DMG_ENTRY(0, ENMB_DMGEFF_STUN),
        /* Normal arrow  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Hammer swing  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Hookshot      */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Kokiri sword  */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
        /* Master sword  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Giant's Knife */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Fire arrow    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Ice arrow     */ DMG_ENTRY(4, ENMB_DMGEFF_STUN_ICE),
        /* Light arrow   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 1   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 2   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 3   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Fire magic    */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Ice magic     */ DMG_ENTRY(3, ENMB_DMGEFF_STUN_ICE),
        /* Light magic   */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Shield        */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Mirror Ray    */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Kokiri spin   */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
        /* Giant spin    */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Master spin   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Kokiri jump   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Giant jump    */ DMG_ENTRY(8, ENMB_DMGEFF_DEFAULT),
        /* Master jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unknown 1     */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Unblockable   */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Hammer jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unknown 2     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    };

    sClubMoblinDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Deku stick    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Slingshot     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Explosive     */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Boomerang     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Normal arrow  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Hammer swing  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Hookshot      */ DMG_ENTRY(0, ENMB_DMGEFF_STUN),
        /* Kokiri sword  */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
        /* Master sword  */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Giant's Knife */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Fire arrow    */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Ice arrow     */ DMG_ENTRY(4, ENMB_DMGEFF_STUN_ICE),
        /* Light arrow   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 1   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 2   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Unk arrow 3   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Fire magic    */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Ice magic     */ DMG_ENTRY(3, ENMB_DMGEFF_STUN_ICE),
        /* Light magic   */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Shield        */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Mirror Ray    */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Kokiri spin   */ DMG_ENTRY(1, ENMB_DMGEFF_DEFAULT),
        /* Giant spin    */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Master spin   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Kokiri jump   */ DMG_ENTRY(2, ENMB_DMGEFF_DEFAULT),
        /* Giant jump    */ DMG_ENTRY(8, ENMB_DMGEFF_DEFAULT),
        /* Master jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unknown 1     */ DMG_ENTRY(0, ENMB_DMGEFF_FREEZE),
        /* Unblockable   */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
        /* Hammer jump   */ DMG_ENTRY(4, ENMB_DMGEFF_DEFAULT),
        /* Unknown 2     */ DMG_ENTRY(0, ENMB_DMGEFF_IGNORE),
    };

}

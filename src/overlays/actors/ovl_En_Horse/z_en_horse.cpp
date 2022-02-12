#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_Z_EN_HORSE_C
#include "actor_common.h"
/**
 * File: z_en_horse.c
 * Overlay: ovl_En_Horse
 * Description: Rideable horses
 */

#include "z_en_horse.h"
#include "overlays/actors/ovl_En_In/z_en_in.h"
#include "objects/object_horse/object_horse.h"
#include "objects/object_hni/object_hni.h"
#include "scenes/overworld/spot09/spot09_scene.h"

#include "hack.h"
#include "def/assert.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_horse.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"
#include "def/z_skin.h"
#include "def/z_skin_awb.h"
#include "def/z_skin_matrix.h"

#define FLAGS ACTOR_FLAG_4

typedef void (*EnHorseCsFunc)(EnHorse*, GlobalContext*, CsCmdActorAction*);
typedef void (*EnHorseActionFunc)(EnHorse*, GlobalContext*);

void EnHorse_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorse_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorse_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorse_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnHorse_InitCutscene(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_InitHorsebackArchery(EnHorse* pthis);
void EnHorse_InitFleePlayer(EnHorse* pthis);
void EnHorse_ResetIdleAnimation(EnHorse* pthis);
void EnHorse_StartIdleRidable(EnHorse* pthis);
void EnHorse_InitInactive(EnHorse* pthis);
void EnHorse_InitIngoHorse(EnHorse* pthis);

void EnHorse_Frozen(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_Inactive(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_Idle(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_FollowPlayer(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_UpdateIngoRace(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedIdle(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedIdleWhinneying(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedTurn(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedWalk(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedTrot(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedGallop(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_MountedRearing(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_Stopping(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_Reverse(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_LowJump(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_HighJump(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_BridgeJump(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_CutsceneUpdate(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_UpdateHorsebackArchery(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_FleePlayer(EnHorse* pthis, GlobalContext* globalCtx);

static AnimationHeader* sEponaAnimHeaders[] = {
    &gEponaIdleAnim,     &gEponaWhinnyAnim,    &gEponaRefuseAnim,  &gEponaRearingAnim,     &gEponaWalkingAnim,
    &gEponaTrottingAnim, &gEponaGallopingAnim, &gEponaJumpingAnim, &gEponaJumpingHighAnim,
};

static AnimationHeader* sHniAnimHeaders[] = {
    &gHorseIngoIdleAnim,      &gHorseIngoWhinnyAnim,  &gHorseIngoRefuseAnim,
    &gHorseIngoRearingAnim,   &gHorseIngoWalkingAnim, &gHorseIngoTrottingAnim,
    &gHorseIngoGallopingAnim, &gHorseIngoJumpingAnim, &gHorseIngoJumpingHighAnim,
};

static AnimationHeader** sAnimationHeaders[] = { sEponaAnimHeaders, sHniAnimHeaders };

static f32 sPlaybackSpeeds[] = { 2.0f / 3.0f, 2.0f / 3.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f / 3.0f, 2.0f / 3.0f };

static SkeletonHeader* sSkeletonHeaders[] = { &gEponaSkel, &gHorseIngoSkel };

ActorInit En_Horse_InitVars = {
    ACTOR_EN_HORSE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE,
    sizeof(EnHorse),
    (ActorFunc)EnHorse_Init,
    (ActorFunc)EnHorse_Destroy,
    (ActorFunc)EnHorse_Update,
    (ActorFunc)EnHorse_Draw,
};

static ColliderCylinderInit sCylinderInit1 = {
    {
        COLTYPE_NONE,
        AT_TYPE_PLAYER,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000400, 0x00, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInit2 = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 20, 70, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphItemsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F824, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_NO_AT_INFO | BUMP_NO_DAMAGE | BUMP_NO_SWORD_SFX | BUMP_NO_HITMARK,
            OCELEM_ON,
        },
        { 13, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphItemsInit,
};

static CollisionCheckInfoInit D_80A65F38 = { 10, 35, 100, MASS_HEAVY };

typedef struct {
    s16 scene;
    Vec3s pos;
    s16 angle;
} EnHorseSpawnpoint;

static EnHorseSpawnpoint sHorseSpawns[] = {
    // Hyrule Field
    { SCENE_SPOT00, 16, 0, 1341, 0 },
    { SCENE_SPOT00, -1297, 0, 1459, 0 },
    { SCENE_SPOT00, -5416, -300, 1296, 0 },
    { SCENE_SPOT00, -4667, -300, 3620, 0 },
    { SCENE_SPOT00, -3837, 81, 5537, 0 },
    { SCENE_SPOT00, -5093, -226, 6661, 0 },
    { SCENE_SPOT00, -6588, -79, 5053, 0 },
    { SCENE_SPOT00, -7072, -500, 7538, 0 },
    { SCENE_SPOT00, -6139, -500, 8910, 0 },
    { SCENE_SPOT00, -8497, -300, 7802, 0 },
    { SCENE_SPOT00, -5481, -499, 12127, 0 },
    { SCENE_SPOT00, -4808, -700, 13583, 0 },
    { SCENE_SPOT00, -3416, -490, 12092, 0 },
    { SCENE_SPOT00, -2915, 100, 8339, 0 },
    { SCENE_SPOT00, -2277, -500, 13247, 0 },
    { SCENE_SPOT00, -1026, -500, 12101, 0 },
    { SCENE_SPOT00, 1427, -500, 13341, 0 },
    { SCENE_SPOT00, -200, -486, 10205, 0 },
    { SCENE_SPOT00, -1469, 100, 7496, 0 },
    { SCENE_SPOT00, -995, 168, 5652, 0 },
    { SCENE_SPOT00, 1938, 89, 6232, 0 },
    { SCENE_SPOT00, 1387, -105, 9206, 0 },
    { SCENE_SPOT00, 1571, -223, 7701, 0 },
    { SCENE_SPOT00, 3893, -121, 7068, 0 },
    { SCENE_SPOT00, 3179, 373, 5221, 0 },
    { SCENE_SPOT00, 4678, -20, 3869, 0 },
    { SCENE_SPOT00, 3460, 246, 4207, 0 },
    { SCENE_SPOT00, 3686, 128, 2366, 0 },
    { SCENE_SPOT00, 1791, 18, 152, 0 },
    { SCENE_SPOT00, 3667, -16, 1399, 0 },
    { SCENE_SPOT00, 1827, -15, 983, 0 },
    { SCENE_SPOT00, 1574, 399, 4318, 0 },
    { SCENE_SPOT00, 716, 95, 3391, 0 },
    { SCENE_SPOT00, -1189, -41, 4739, 0 },
    { SCENE_SPOT00, -1976, -171, 4172, 0 },
    { SCENE_SPOT00, 1314, 391, 5665, 0 },
    { SCENE_SPOT00, 112, 0, 1959, 0 },
    { SCENE_SPOT00, -3011, -111, 9397, 0 },
    { SCENE_SPOT00, -5674, -270, 8585, 0 },
    { SCENE_SPOT00, -8861, -300, 7836, 0 },
    { SCENE_SPOT00, -6056, -500, 7810, 0 },
    { SCENE_SPOT00, -7306, -500, 5994, 0 },
    { SCENE_SPOT00, -7305, -500, 7605, 0 },
    { SCENE_SPOT00, -7439, -300, 7600, 0 },
    { SCENE_SPOT00, -7464, -300, 6268, 0 },
    { SCENE_SPOT00, -8080, -300, 7553, 0 },
    { SCENE_SPOT00, -8091, -300, 7349, 0 },
    { SCENE_SPOT00, -8785, -300, 7383, 0 },
    { SCENE_SPOT00, -8745, -300, 7508, 0 },
    { SCENE_SPOT00, -8777, -300, 7788, 0 },
    { SCENE_SPOT00, -8048, -299, 7738, 0 },
    { SCENE_SPOT00, -7341, -184, 7730, 0 },
    { SCENE_SPOT00, -6410, -288, 7824, 0 },
    { SCENE_SPOT00, -6326, -290, 8205, 0 },
    { SCENE_SPOT00, -6546, -292, 8400, 0 },
    { SCENE_SPOT00, -7533, -180, 8459, 0 },
    { SCENE_SPOT00, -8024, -295, 7903, 0 },
    { SCENE_SPOT00, -8078, -308, 7994, 0 },
    { SCENE_SPOT00, -9425, -287, 7696, 0 },
    { SCENE_SPOT00, -9322, -292, 7577, 0 },
    { SCENE_SPOT00, -9602, -199, 7160, 0 },
    { SCENE_SPOT00, -9307, -300, 7758, 0 },
    { SCENE_SPOT00, -9230, -300, 7642, 0 },
    { SCENE_SPOT00, -7556, -499, 8695, 0 },
    { SCENE_SPOT00, -6438, -500, 8606, 0 },
    { SCENE_SPOT00, -6078, -500, 8258, 0 },
    { SCENE_SPOT00, -6233, -500, 7613, 0 },
    { SCENE_SPOT00, -5035, -205, 7814, 0 },
    { SCENE_SPOT00, -5971, -500, 8501, 0 },
    { SCENE_SPOT00, -5724, -498, 10123, 0 },
    { SCENE_SPOT00, -5094, -392, 11106, 0 },
    { SCENE_SPOT00, -5105, -393, 11312, 0 },
    { SCENE_SPOT00, -4477, -314, 11132, 0 },
    { SCENE_SPOT00, -3867, -380, 11419, 0 },
    { SCENE_SPOT00, -2952, -500, 11944, 0 },
    { SCENE_SPOT00, -2871, -488, 11743, 0 },
    { SCENE_SPOT00, -3829, -372, 11327, 0 },
    { SCENE_SPOT00, -4439, -293, 10989, 0 },
    { SCENE_SPOT00, -5014, -381, 11086, 0 },
    { SCENE_SPOT00, -5113, -188, 10968, 0 },
    { SCENE_SPOT00, -5269, -188, 11156, 0 },
    { SCENE_SPOT00, -5596, -178, 9972, 0 },
    { SCENE_SPOT00, -5801, -288, 8518, 0 },
    { SCENE_SPOT00, -4910, -178, 7931, 0 },
    { SCENE_SPOT00, -3586, 73, 8140, 0 },
    { SCENE_SPOT00, -4487, -106, 9362, 0 },
    { SCENE_SPOT00, -4339, -112, 6412, 0 },
    { SCENE_SPOT00, -3417, 105, 8194, 0 },
    { SCENE_SPOT00, -4505, -20, 6608, 0 },
    { SCENE_SPOT00, -5038, -199, 6603, 0 },
    { SCENE_SPOT00, -4481, 1, 6448, 0 },
    { SCENE_SPOT00, -5032, -168, 6418, 0 },
    { SCENE_SPOT00, -5256, -700, 14329, 0 },
    { SCENE_SPOT00, -5749, -820, 15380, 0 },
    { SCENE_SPOT00, -3122, -700, 13608, 0 },
    { SCENE_SPOT00, -3758, -525, 13228, 0 },
    { SCENE_SPOT00, -3670, -500, 13123, 0 },
    { SCENE_SPOT00, -2924, -500, 13526, 0 },
    { SCENE_SPOT00, 1389, -115, 9370, 0 },
    { SCENE_SPOT00, 548, -116, 8889, 0 },
    { SCENE_SPOT00, -106, -107, 8530, 0 },
    { SCENE_SPOT00, -1608, 85, 7646, 0 },
    { SCENE_SPOT00, -5300, -700, 13772, 0 },
    { SCENE_SPOT00, -5114, -700, 13400, 0 },
    { SCENE_SPOT00, -4561, -700, 13700, 0 },
    { SCENE_SPOT00, -4762, -700, 14084, 0 },
    { SCENE_SPOT00, -2954, 100, 8216, 0 },
    { SCENE_SPOT00, 1460, -104, 9246, 0 },
    { SCENE_SPOT00, 629, -105, 8791, 0 },
    { SCENE_SPOT00, -10, -90, 8419, 0 },
    { SCENE_SPOT00, -1462, 100, 7504, 0 },
    { SCENE_SPOT00, -3018, -500, 12493, 0 },
    { SCENE_SPOT00, -2994, -311, 10331, 0 },
    { SCENE_SPOT00, -4006, -700, 14152, 0 },
    { SCENE_SPOT00, -4341, -500, 12743, 0 },
    { SCENE_SPOT00, -5879, -497, 6799, 0 },
    { SCENE_SPOT00, 22, -473, 10103, 0 },
    { SCENE_SPOT00, -1389, -192, 8874, 0 },
    { SCENE_SPOT00, -4, 92, 6866, 0 },
    { SCENE_SPOT00, 483, 104, 6637, 0 },
    { SCENE_SPOT00, 1580, 183, 5987, 0 },
    { SCENE_SPOT00, 1548, 308, 5077, 0 },
    { SCENE_SPOT00, 1511, 399, 4267, 0 },
    { SCENE_SPOT00, 1358, 385, 4271, 0 },
    { SCENE_SPOT00, 1379, 395, 5063, 0 },
    { SCENE_SPOT00, 1360, 394, 5870, 0 },
    { SCENE_SPOT00, 813, 283, 6194, 0 },
    { SCENE_SPOT00, -57, 101, 6743, 0 },
    { SCENE_SPOT00, 91, 325, 5143, 0 },
    { SCENE_SPOT00, 1425, -214, 7659, 0 },
    { SCENE_SPOT00, 3487, -19, 880, 0 },
    { SCENE_SPOT00, 2933, 152, 2094, 0 },
    { SCENE_SPOT00, 2888, -145, 6862, 0 },
    { SCENE_SPOT00, 1511, 67, 6471, 0 },
    { SCENE_SPOT00, 4051, -47, 1722, 0 },
    { SCENE_SPOT00, -7335, -500, 8627, 0 },
    { SCENE_SPOT00, -7728, -462, 8498, 0 },
    { SCENE_SPOT00, -7791, -446, 8832, 0 },
    { SCENE_SPOT00, -2915, -435, 11334, 0 },
    { SCENE_SPOT00, 165, -278, 3352, 0 },

    // Lake Hylia
    { SCENE_SPOT06, -2109, -882, 1724, 0 },
    { SCENE_SPOT06, -328, -1238, 2705, 0 },
    { SCENE_SPOT06, -3092, -1033, 3527, 0 },

    // Gerudo Valley
    { SCENE_SPOT09, 2687, -269, 753, 0 },
    { SCENE_SPOT09, 2066, -132, 317, 0 },
    { SCENE_SPOT09, 523, -8, 635, 0 },
    { SCENE_SPOT09, 558, 36, -323, 0 },
    { SCENE_SPOT09, 615, 51, -839, 0 },
    { SCENE_SPOT09, -614, 32, 29, 0 },
    { SCENE_SPOT09, -639, -3, 553, 0 },
    { SCENE_SPOT09, -540, 10, -889, 0 },
    { SCENE_SPOT09, -1666, 58, 378, 0 },
    { SCENE_SPOT09, -3044, 210, -648, 0 },

    // Gerudo's Fortress
    { SCENE_SPOT12, -678, 21, -623, 0 },
    { SCENE_SPOT12, 149, 333, -2499, 0 },
    { SCENE_SPOT12, 499, 581, -547, 0 },
    { SCENE_SPOT12, 3187, 1413, -3775, 0 },
    { SCENE_SPOT12, 3198, 1413, 307, 0 },
    { SCENE_SPOT12, 3380, 1413, -1200, 0 },
    { SCENE_SPOT12, -966, 1, -56, 0 },
    { SCENE_SPOT12, -966, 24, -761, 0 },
    { SCENE_SPOT12, -694, 174, -2820, 0 },

    // Lon Lon Ranch
    { SCENE_SPOT20, 1039, 0, 2051, 0 },
    { SCENE_SPOT20, -1443, 0, 1429, 0 },
    { SCENE_SPOT20, 856, 0, -918, 0 }, // Hardcoded to always load in lon lon
    { SCENE_SPOT20, 882, 0, -2256, 0 },
    { SCENE_SPOT20, -1003, 0, -755, 0 }, // Hardcoded to always load in lon lon
    { SCENE_SPOT20, -2254, 0, -629, 0 },
    { SCENE_SPOT20, 907, 0, -2336, 0 },
};

typedef struct {
    s16 zMin;
    s16 zMax;

    s16 xMin;
    s16 xMax;
    s16 xOffset;

    s16 angle;
    s16 angleRange;

    Vec3s pos;
} BridgeJumpPoint;

static BridgeJumpPoint sBridgeJumps[] = {
    { -195, -40, 225, 120, 360, -0x4000, 0x7D0, -270, -52, -117 },
    { -195, -40, -240, -120, -360, 0x4000, 0x7D0, 270, -52, -117 },
};

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 speed;
    s16 angle;
} RaceWaypoint;

typedef struct {
    s32 numWaypoints;
    RaceWaypoint* waypoints;
} RaceInfo;

static RaceWaypoint sIngoRaceWaypoints[] = {
    { 1056, 1, -1540, 11, 0x2A8D },  { 1593, 1, -985, 10, 0xFC27 },   { 1645, 1, -221, 11, 0xE891 },
    { 985, 1, 403, 10, 0xBB9C },     { -1023, 1, 354, 11, 0xA37D },   { -1679, 1, -213, 10, 0x889C },
    { -1552, 1, -1008, 11, 0x638D }, { -947, -1, -1604, 10, 0x4002 },
};

static RaceInfo sIngoRace = { 8, sIngoRaceWaypoints };
static s32 sAnimSoundFrames[] = { 0, 16 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 600, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_STOP),
};

static u8 sResetNoInput[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 };

static s32 sIdleAnimIds[] = { 1, 3, 0, 3, 1, 0 };

static s16 sIngoAnimations[] = { 7, 6, 2, 2, 1, 1, 0, 0, 0, 0 };

void EnHorse_CsMoveInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsJumpInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsRearingInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_WarpMoveInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsWarpRearingInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);

static EnHorseCsFunc sCutsceneInitFuncs[] = {
    NULL,
    EnHorse_CsMoveInit,
    EnHorse_CsJumpInit,
    EnHorse_CsRearingInit,
    EnHorse_WarpMoveInit,
    EnHorse_CsWarpRearingInit,
};

void EnHorse_CsMoveToPoint(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsJump(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsRearing(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsWarpMoveToPoint(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);
void EnHorse_CsWarpRearing(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action);

static EnHorseCsFunc sCutsceneActionFuncs[] = {
    NULL, EnHorse_CsMoveToPoint, EnHorse_CsJump, EnHorse_CsRearing, EnHorse_CsWarpMoveToPoint, EnHorse_CsWarpRearing,
};

typedef struct {
    s32 csAction;
    s32 csFuncIdx;
} CsActionEntry;

static CsActionEntry sCsActionTable[] = {
    { 36, 1 }, { 37, 2 }, { 38, 3 }, { 64, 4 }, { 65, 5 },
};

static RaceWaypoint sHbaWaypoints[] = {
    { 3600, 1413, -5055, 11, 0x8001 }, { 3360, 1413, -5220, 5, 0xC000 }, { 3100, 1413, -4900, 5, 0x0000 },
    { 3600, 1413, -4100, 11, 0x0000 }, { 3600, 1413, 360, 11, 0x0000 },
};

static RaceInfo sHbaInfo = { 5, sHbaWaypoints };

static EnHorseActionFunc sActionFuncs[] = {
    EnHorse_Frozen,
    EnHorse_Inactive,
    EnHorse_Idle,
    EnHorse_FollowPlayer,
    EnHorse_UpdateIngoRace,
    EnHorse_MountedIdle,
    EnHorse_MountedIdleWhinneying,
    EnHorse_MountedTurn,
    EnHorse_MountedWalk,
    EnHorse_MountedTrot,
    EnHorse_MountedGallop,
    EnHorse_MountedRearing,
    EnHorse_Stopping,
    EnHorse_Reverse,
    EnHorse_LowJump,
    EnHorse_HighJump,
    EnHorse_BridgeJump,
    EnHorse_CutsceneUpdate,
    EnHorse_UpdateHorsebackArchery,
    EnHorse_FleePlayer,
};

s32 EnHorse_BgCheckBridgeJumpPoint(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 xMin;
    f32 xMax;
    s32 i;

    if (globalCtx->sceneNum != SCENE_SPOT09) {
        return false;
    }
    if (pthis->actor.speedXZ < 12.8f) {
        return false;
    }
    if ((gSaveContext.eventChkInf[9] & 0xF) == 0xF) {
        return false;
    }

    for (i = 0; i < 2; i++) {
        xMin = sBridgeJumps[i].xMin;
        xMax = (xMin + sBridgeJumps[i].xMax) + sBridgeJumps[i].xOffset;
        if (xMax < xMin) {
            f32 temp = xMin;

            xMin = xMax;
            xMax = temp;
        }
        if (sBridgeJumps[i].zMin < pthis->actor.world.pos.z && pthis->actor.world.pos.z < sBridgeJumps[i].zMax) {
            if (xMin < pthis->actor.world.pos.x && pthis->actor.world.pos.x < xMax) {
                if (sBridgeJumps[i].angle - sBridgeJumps[i].angleRange < pthis->actor.world.rot.y &&
                    pthis->actor.world.rot.y < sBridgeJumps[i].angle + sBridgeJumps[i].angleRange) {
                    return true;
                }
            }
        }
    }
    return false;
}

void EnHorse_StartBridgeJump(EnHorse* pthis, GlobalContext* globalCtx);

s32 EnHorse_CheckBridgeJumps(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 xMin;
    f32 xMax;
    s32 i;

    if (pthis->actor.speedXZ < 12.8f) {
        return false;
    }

    for (i = 0; i != 2; i++) {
        xMin = sBridgeJumps[i].xMin;
        xMax = sBridgeJumps[i].xMax + xMin;

        if (xMax < xMin) {
            f32 temp = xMin;

            xMin = xMax;
            xMax = temp;
        }

        if (sBridgeJumps[i].zMin < pthis->actor.world.pos.z && pthis->actor.world.pos.z < sBridgeJumps[i].zMax) {
            if (xMin < pthis->actor.world.pos.x && pthis->actor.world.pos.x < xMax) {
                if (sBridgeJumps[i].angle - sBridgeJumps[i].angleRange < pthis->actor.world.rot.y &&
                    pthis->actor.world.rot.y < sBridgeJumps[i].angle + sBridgeJumps[i].angleRange) {
                    pthis->bridgeJumpIdx = i;
                    EnHorse_StartBridgeJump(pthis, globalCtx);
                    return true;
                }
            }
        }
    }

    return false;
}

void EnHorse_RaceWaypointPos(RaceWaypoint* waypoints, s32 idx, Vec3f* pos) {
    pos->x = waypoints[idx].x;
    pos->y = waypoints[idx].y;
    pos->z = waypoints[idx].z;
}

void EnHorse_RotateToPoint(EnHorse* pthis, GlobalContext* globalCtx, Vec3f* pos, s16 turnAmount) {
    func_8006DD9C(&pthis->actor, pos, turnAmount);
}

void EnHorse_UpdateIngoRaceInfo(EnHorse* pthis, GlobalContext* globalCtx, RaceInfo* raceInfo) {
    Vec3f curWaypointPos;
    Vec3f prevWaypointPos;
    f32 playerDist;
    f32 sp50;
    s16 relPlayerYaw;
    f32 px;
    f32 pz;
    f32 d;
    f32 dist;
    s32 prevWaypoint;

    EnHorse_RaceWaypointPos(raceInfo->waypoints, pthis->curRaceWaypoint, &curWaypointPos);
    Math3D_RotateXZPlane(&curWaypointPos, raceInfo->waypoints[pthis->curRaceWaypoint].angle, &px, &pz, &d);
    if (((pthis->actor.world.pos.x * px) + (pz * pthis->actor.world.pos.z) + d) > 0.0f) {
        pthis->curRaceWaypoint++;
        if (pthis->curRaceWaypoint >= raceInfo->numWaypoints) {
            pthis->curRaceWaypoint = 0;
        }
    }

    EnHorse_RaceWaypointPos(raceInfo->waypoints, pthis->curRaceWaypoint, &curWaypointPos);

    prevWaypoint = pthis->curRaceWaypoint - 1;
    if (prevWaypoint < 0) {
        prevWaypoint = raceInfo->numWaypoints - 1;
    }
    EnHorse_RaceWaypointPos(raceInfo->waypoints, prevWaypoint, &prevWaypointPos);
    Math3D_PointDistToLine2D(pthis->actor.world.pos.x, pthis->actor.world.pos.z, prevWaypointPos.x, prevWaypointPos.z,
                             curWaypointPos.x, curWaypointPos.z, &dist);
    EnHorse_RotateToPoint(pthis, globalCtx, &curWaypointPos, 400);

    if (dist < 90000.0f) {
        playerDist = pthis->actor.xzDistToPlayer;
        if (playerDist < 130.0f || pthis->jntSph.elements[0].info.ocElemFlags & 2) {
            if (Math_SinS(pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y) > 0.0f) {
                pthis->actor.world.rot.y = pthis->actor.world.rot.y - 280;
            } else {
                pthis->actor.world.rot.y = pthis->actor.world.rot.y + 280;
            }
        } else if (playerDist < 300.0f) {
            if (Math_SinS(pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y) > 0.0f) {
                pthis->actor.world.rot.y = pthis->actor.world.rot.y + 280;
            } else {
                pthis->actor.world.rot.y = pthis->actor.world.rot.y - 280;
            }
        }
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    sp50 = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
    relPlayerYaw = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.world.rot.y;
    if (sp50 <= 200.0f || (fabsf(Math_SinS(relPlayerYaw)) < 0.8f && Math_CosS(relPlayerYaw) > 0.0f)) {
        if (pthis->actor.speedXZ < pthis->ingoHorseMaxSpeed) {
            pthis->actor.speedXZ += 0.47f;
        } else {
            pthis->actor.speedXZ -= 0.47f;
        }
        pthis->ingoRaceFlags |= 1;
        return;
    }

    if (pthis->actor.speedXZ < raceInfo->waypoints[pthis->curRaceWaypoint].speed) {
        pthis->actor.speedXZ = pthis->actor.speedXZ + 0.4f;
    } else {
        pthis->actor.speedXZ = pthis->actor.speedXZ - 0.4f;
    }
    pthis->ingoRaceFlags &= ~0x1;
}

void EnHorse_PlayWalkingSound(EnHorse* pthis) {
    if (sAnimSoundFrames[pthis->soundTimer] < pthis->curFrame) {
        if (pthis->soundTimer == 0 && (sAnimSoundFrames[1] < pthis->curFrame)) {
            return;
        }

        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_WALK, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        if (++pthis->soundTimer > 1) {
            pthis->soundTimer = 0;
        }
    }
}

void EnHorse_PlayTrottingSound(EnHorse* pthis) {
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void EnHorse_PlayGallopingSound(EnHorse* pthis) {
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

f32 EnHorse_SlopeSpeedMultiplier(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 multiplier = 1.0f;

    if (Math_CosS(pthis->actor.shape.rot.x) < 0.939262f && Math_SinS(pthis->actor.shape.rot.x) < 0.0f) {
        multiplier = 0.7f;
    }
    return multiplier;
}

void func_80A5BB90(GlobalContext* globalCtx, Vec3f* vec, Vec3f* arg2, f32* arg3) {
    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, vec, arg2, arg3);
}

s32 func_80A5BBBC(GlobalContext* globalCtx, EnHorse* pthis, Vec3f* pos) {
    Vec3f sp24;
    f32 sp20;
    f32 eyeDist;

    func_80A5BB90(globalCtx, pos, &sp24, &sp20);
    if (fabsf(sp20) < 0.008f) {
        return false;
    }
    eyeDist = Math3D_Vec3f_DistXYZ(pos, &globalCtx->view.eye);
    return Actor_IsInUncullZone(globalCtx, &pthis->actor, &sp24, sp20) || eyeDist < 100.0f;
}

void EnHorse_IdleAnimSounds(EnHorse* pthis, GlobalContext* globalCtx) {
    if (pthis->animationIdx == ENHORSE_ANIM_IDLE &&
        ((pthis->curFrame > 35.0f && pthis->type == HORSE_EPONA) ||
         (pthis->curFrame > 28.0f && pthis->type == HORSE_HNI)) &&
        !(pthis->stateFlags & ENHORSE_SANDDUST_SOUND)) {
        pthis->stateFlags |= ENHORSE_SANDDUST_SOUND;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SANDDUST, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (pthis->animationIdx == ENHORSE_ANIM_REARING && pthis->curFrame > 25.0f &&
               !(pthis->stateFlags & ENHORSE_LAND2_SOUND)) {
        pthis->stateFlags |= ENHORSE_LAND2_SOUND;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

s32 EnHorse_Spawn(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 minDist = 1e38f;
    s32 spawn = false;
    f32 dist;
    s32 i;
    Player* player;
    Vec3f spawnPos;

    for (i = 0; i < 169; i++) {
        if (sHorseSpawns[i].scene == globalCtx->sceneNum) {
            player = GET_PLAYER(globalCtx);
            if (globalCtx->sceneNum != SCENE_SPOT20 ||
                //! Same flag checked twice
                (Flags_GetEventChkInf(0x18) && ((gSaveContext.eventInf[0] & 0xF) != 6 || Flags_GetEventChkInf(0x18))) ||
                // always load two spawns inside lon lon
                ((sHorseSpawns[i].pos.x == 856 && sHorseSpawns[i].pos.y == 0 && sHorseSpawns[i].pos.z == -918) ||
                 (sHorseSpawns[i].pos.x == -1003 && sHorseSpawns[i].pos.y == 0 && sHorseSpawns[i].pos.z == -755))) {

                spawnPos.x = sHorseSpawns[i].pos.x;
                spawnPos.y = sHorseSpawns[i].pos.y;
                spawnPos.z = sHorseSpawns[i].pos.z;
                dist = Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &spawnPos);

                if (globalCtx->sceneNum) {}
                if (!(minDist < dist) && !func_80A5BBBC(globalCtx, pthis, &spawnPos)) {
                    minDist = dist;
                    pthis->actor.world.pos.x = sHorseSpawns[i].pos.x;
                    pthis->actor.world.pos.y = sHorseSpawns[i].pos.y;
                    pthis->actor.world.pos.z = sHorseSpawns[i].pos.z;
                    pthis->actor.prevPos = pthis->actor.world.pos;
                    pthis->actor.world.rot.y = sHorseSpawns[i].angle;
                    pthis->actor.shape.rot.y = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
                    spawn = true;
                    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &pthis->actor.world.pos,
                                                 &pthis->actor.projectedPos, &pthis->actor.projectedW);
                }
            }
        }
    }

    return spawn;
}

void EnHorse_ResetCutscene(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->cutsceneAction = -1;
    pthis->cutsceneFlags = 0;
}

void EnHorse_ResetRace(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->inRace = false;
}

s32 EnHorse_PlayerCanMove(EnHorse* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((player->stateFlags1 & 1) || func_8002DD78(GET_PLAYER(globalCtx)) == 1 || (player->stateFlags1 & 0x100000) ||
        ((pthis->stateFlags & ENHORSE_FLAG_19) && !pthis->inRace) || pthis->action == ENHORSE_ACT_HBA ||
        player->actor.flags & ACTOR_FLAG_8 || globalCtx->csCtx.state != 0) {
        return false;
    }
    return true;
}

void EnHorse_ResetHorsebackArchery(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->unk_39C = 0;
    pthis->hbaStarted = 0;
    pthis->hbaFlags = 0;
}

void EnHorse_ClearDustFlags(u16* dustFlags) {
    *dustFlags = 0;
}

void EnHorse_Init(Actor* thisx, GlobalContext* globalCtx2) {
    EnHorse* pthis = (EnHorse*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    AREG(6) = 0;
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    EnHorse_ClearDustFlags(&pthis->dustFlags);
    DREG(53) = 0;
    pthis->riderPos = pthis->actor.world.pos;
    pthis->noInputTimer = 0;
    pthis->noInputTimerMax = 0;
    pthis->riderPos.y = pthis->riderPos.y + 70.0f;

    if (DREG(4) == 0) {
        DREG(4) = 70;
    }

    if (pthis->actor.params & 0x8000) {
        pthis->actor.params &= ~0x8000;
        pthis->type = HORSE_HNI;

        if ((pthis->bankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_HNI)) < 0) {
            Actor_Kill(&pthis->actor);
            return;
        }

        do {
        } while (!Object_IsLoaded(&globalCtx->objectCtx, pthis->bankIndex));

        pthis->actor.objBankIndex = pthis->bankIndex;
        Actor_SetObjectDependency(globalCtx, &pthis->actor);
        pthis->boostSpeed = 12;
    } else {
        pthis->type = HORSE_EPONA;
        pthis->boostSpeed = 14;
    }

    // params was -1
    if (pthis->actor.params == 0x7FFF) {
        pthis->actor.params = 1;
    }

    if (globalCtx->sceneNum == SCENE_SOUKO) {
        pthis->stateFlags = ENHORSE_UNRIDEABLE;
    } else if (globalCtx->sceneNum == SCENE_SPOT12 && pthis->type == HORSE_HNI) {
        pthis->stateFlags = ENHORSE_FLAG_18 | ENHORSE_UNRIDEABLE;
    } else {
        if (pthis->actor.params == 3) {
            pthis->stateFlags = ENHORSE_FLAG_19 | ENHORSE_CANT_JUMP | ENHORSE_UNRIDEABLE;
        } else if (pthis->actor.params == 6) {
            pthis->stateFlags = ENHORSE_FLAG_19 | ENHORSE_CANT_JUMP;
            if (Flags_GetEventChkInf(0x18) || DREG(1) != 0) {
                pthis->stateFlags &= ~ENHORSE_CANT_JUMP;
                pthis->stateFlags |= ENHORSE_FLAG_26;
            } else if (gSaveContext.eventInf[0] & 0x40 && pthis->type == HORSE_HNI) {
                pthis->stateFlags |= ENHORSE_FLAG_21 | ENHORSE_FLAG_20;
            }
        } else if (pthis->actor.params == 1) {
            pthis->stateFlags = ENHORSE_FLAG_7;
        } else {
            pthis->stateFlags = 0;
        }
    }

    if (globalCtx->sceneNum == SCENE_SPOT20 && (gSaveContext.eventInf[0] & 0xF) == 6 &&
        Flags_GetEventChkInf(0x18) == 0 && !DREG(1)) {
        pthis->stateFlags |= ENHORSE_FLAG_25;
    }

    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.gravity = -3.5f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);
    pthis->action = ENHORSE_ACT_IDLE;
    pthis->actor.speedXZ = 0.0f;
    Collider_InitCylinder(globalCtx, &pthis->cyl1);
    Collider_SetCylinder(globalCtx, &pthis->cyl1, &pthis->actor, &sCylinderInit1);
    Collider_InitCylinder(globalCtx, &pthis->cyl2);
    Collider_SetCylinder(globalCtx, &pthis->cyl2, &pthis->actor, &sCylinderInit2);
    Collider_InitJntSph(globalCtx, &pthis->jntSph);
    Collider_SetJntSph(globalCtx, &pthis->jntSph, &pthis->actor, &sJntSphInit, &pthis->jntSphList);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, DamageTable_Get(0xB), &D_80A65F38);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    pthis->playerControlled = false;

    if ((globalCtx->sceneNum == SCENE_SPOT20) && (gSaveContext.sceneSetupIndex < 4)) {
        if (pthis->type == HORSE_HNI) {
            if (pthis->actor.world.rot.z == 0 || gSaveContext.nightFlag) {
                Actor_Kill(&pthis->actor);
                return;
            }
            if (Flags_GetEventChkInf(0x18)) {
                Actor_Kill(&pthis->actor);
                return;
            }
            if (pthis->actor.world.rot.z != 5) {
                Actor_Kill(&pthis->actor);
                return;
            }
        } else if (!Flags_GetEventChkInf(0x18) && !DREG(1) && gSaveContext.nightFlag) {
            Actor_Kill(&pthis->actor);
            return;
        }
    } else if (globalCtx->sceneNum == SCENE_MALON_STABLE) {
        if (IS_DAY || Flags_GetEventChkInf(0x18) || DREG(1) != 0 || !LINK_IS_ADULT) {
            Actor_Kill(&pthis->actor);
            return;
        }
        pthis->stateFlags |= ENHORSE_UNRIDEABLE;
    }

    func_800A663C(globalCtx, &pthis->skin, sSkeletonHeaders[pthis->type],
                  sAnimationHeaders[pthis->type][ENHORSE_ANIM_IDLE]);
    pthis->animationIdx = ENHORSE_ANIM_IDLE;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
    pthis->numBoosts = 6;
    pthis->blinkTimer	  = 0;
    pthis->postDrawFunc	  = nullptr;
    pthis->boostRegenTime		    = 0;
    EnHorse_ResetCutscene(pthis, globalCtx);
    EnHorse_ResetRace(pthis, globalCtx);
    EnHorse_ResetHorsebackArchery(pthis, globalCtx);

    if (pthis->actor.params == 2) {
        EnHorse_InitInactive(pthis);
    } else if (pthis->actor.params == 3) {
        EnHorse_InitIngoHorse(pthis);
        pthis->rider =
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_IN, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                        pthis->actor.world.pos.z, pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, 1, 1);
        if (pthis->rider == NULL) {
            __assert("pthis->race.rider != NULL", "../z_en_horse.c", 3077);
        }
        if (!(gSaveContext.eventInf[0] & 0x40)) {
            pthis->ingoHorseMaxSpeed = 12.07f;
        } else {
            pthis->ingoHorseMaxSpeed = 12.625f;
        }
    } else if (pthis->actor.params == 7) {
        EnHorse_InitCutscene(pthis, globalCtx);
    } else if (pthis->actor.params == 8) {
        EnHorse_InitHorsebackArchery(pthis);
        Interface_InitHorsebackArchery(globalCtx);
    } else if (globalCtx->sceneNum == SCENE_SPOT20 && !Flags_GetEventChkInf(0x18) && !DREG(1)) {
        EnHorse_InitFleePlayer(pthis);
    } else {
        if (globalCtx->sceneNum == SCENE_SOUKO) {
            EnHorse_ResetIdleAnimation(pthis);
        } else if (globalCtx->sceneNum == SCENE_SPOT12 && pthis->type == HORSE_HNI) {
            EnHorse_ResetIdleAnimation(pthis);
        } else {
            EnHorse_StartIdleRidable(pthis);
        }
    }
    pthis->actor.home.rot.z = pthis->actor.world.rot.z = pthis->actor.shape.rot.z = 0;
}

void EnHorse_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHorse* pthis = (EnHorse*)thisx;

    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_StopSfxByPos(&pthis->unk_21C);
    }
    func_800A6888(globalCtx, &pthis->skin);
    Collider_DestroyCylinder(globalCtx, &pthis->cyl1);
    Collider_DestroyCylinder(globalCtx, &pthis->cyl2);
    Collider_DestroyJntSph(globalCtx, &pthis->jntSph);
}

void EnHorse_RotateToPlayer(EnHorse* pthis, GlobalContext* globalCtx) {
    EnHorse_RotateToPoint(pthis, globalCtx, &GET_PLAYER(globalCtx)->actor.world.pos, 400);
    if (pthis->stateFlags & ENHORSE_OBSTACLE) {
        pthis->actor.world.rot.y += 800.0f;
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnHorse_Freeze(EnHorse* pthis) {
    if (pthis->action != ENHORSE_ACT_CS_UPDATE && pthis->action != ENHORSE_ACT_HBA) {
        if (sResetNoInput[pthis->actor.params] != 0 && pthis->actor.params != 4) {
            pthis->noInputTimer = 0;
            pthis->noInputTimerMax = 0;
        }
        pthis->prevAction = pthis->action;
        pthis->action = ENHORSE_ACT_FROZEN;
        pthis->cyl1.base.ocFlags1 &= ~OC1_ON;
        pthis->cyl2.base.ocFlags1 &= ~OC1_ON;
        pthis->jntSph.base.ocFlags1 &= ~OC1_ON;
        pthis->animationIdx = ENHORSE_ANIM_IDLE;
    }
}

void EnHorse_ChangeIdleAnimation(EnHorse* pthis, s32 arg1, f32 arg2);
void EnHorse_StartMountedIdleResetAnim(EnHorse* pthis);
void EnHorse_StartMountedIdle(EnHorse* pthis);
void EnHorse_StartGalloping(EnHorse* pthis);

void EnHorse_Frozen(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    pthis->noInputTimer--;
    if (pthis->noInputTimer < 0) {
        pthis->cyl1.base.ocFlags1 |= OC1_ON;
        pthis->cyl2.base.ocFlags1 |= OC1_ON;
        pthis->jntSph.base.ocFlags1 |= OC1_ON;
        if (pthis->playerControlled == true) {
            pthis->stateFlags &= ~ENHORSE_FLAG_7;
            if (pthis->actor.params == 4) {
                EnHorse_StartMountedIdleResetAnim(pthis);
            } else if (pthis->actor.params == 9) {
                pthis->actor.params = 5;
                if (globalCtx->csCtx.state != 0) {
                    EnHorse_StartMountedIdle(pthis);
                } else {
                    pthis->actor.speedXZ = 8.0f;
                    EnHorse_StartGalloping(pthis);
                }
            } else if (pthis->prevAction == 2) {
                EnHorse_StartMountedIdle(pthis);
            } else {
                EnHorse_StartMountedIdleResetAnim(pthis);
            }
            if (pthis->actor.params != 0) {
                pthis->actor.params = 0;
                return;
            }
        } else {
            if (pthis->prevAction == 5) {
                EnHorse_ChangeIdleAnimation(pthis, 0, 0);
                return;
            }
            if (pthis->prevAction == 6) {
                EnHorse_ChangeIdleAnimation(pthis, 0, 0);
                return;
            }
            EnHorse_ChangeIdleAnimation(pthis, 0, 0);
        }
    }
}

void EnHorse_StickDirection(Vec2f* curStick, f32* stickMag, s16* angle);

void EnHorse_UpdateSpeed(EnHorse* pthis, GlobalContext* globalCtx, f32 brakeDecel, f32 brakeAngle, f32 minStickMag,
                         f32 decel, f32 baseSpeed, s16 turnSpeed) {
    s16* stickAnglePtr; // probably fake
    f32 stickMag;
    s16 stickAngle;
    f32 temp_f12;
    f32 traction;
    s16 turn;

    if (!EnHorse_PlayerCanMove(pthis, globalCtx)) {
        if (pthis->actor.speedXZ > 8) {
            pthis->actor.speedXZ -= decel;
        } else if (pthis->actor.speedXZ < 0) {
            pthis->actor.speedXZ = 0;
        }

        return;
    }

    stickAnglePtr = &stickAngle;

    baseSpeed *= EnHorse_SlopeSpeedMultiplier(pthis, globalCtx);
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (Math_CosS(stickAngle) <= brakeAngle) {
        pthis->actor.speedXZ -= brakeDecel;
        pthis->actor.speedXZ = pthis->actor.speedXZ < 0.0f ? 0.0f : pthis->actor.speedXZ;
        return;
    }

    if (stickMag < minStickMag) {
        pthis->stateFlags &= ~ENHORSE_BOOST;
        pthis->stateFlags &= ~ENHORSE_BOOST_DECEL;
        pthis->actor.speedXZ -= decel;
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ = 0.0f;
        }

        return;
    }

    if (pthis->stateFlags & ENHORSE_BOOST) {
        if ((16 - pthis->boostTimer) > 0) {
            pthis->actor.speedXZ =
                (EnHorse_SlopeSpeedMultiplier(pthis, globalCtx) * pthis->boostSpeed - pthis->actor.speedXZ) /
                    (16 - pthis->boostTimer) +
                pthis->actor.speedXZ;
        } else {
            pthis->actor.speedXZ = EnHorse_SlopeSpeedMultiplier(pthis, globalCtx) * pthis->boostSpeed;
        }

        if ((EnHorse_SlopeSpeedMultiplier(pthis, globalCtx) * pthis->boostSpeed) <= pthis->actor.speedXZ) {
            pthis->stateFlags &= ~ENHORSE_BOOST;
            pthis->stateFlags |= ENHORSE_BOOST_DECEL;
        }

    } else if (pthis->stateFlags & ENHORSE_BOOST_DECEL) {
        if (baseSpeed < pthis->actor.speedXZ) {
            temp_f12 = pthis->actor.speedXZ;
            pthis->actor.speedXZ = temp_f12 - 0.06f;
        } else if (pthis->actor.speedXZ < baseSpeed) {
            pthis->actor.speedXZ = baseSpeed;
            pthis->stateFlags &= ~ENHORSE_BOOST_DECEL;
        }
    } else {
        pthis->actor.speedXZ +=
            (pthis->actor.speedXZ <= baseSpeed * (1.0f / 54.0f) * stickMag ? 1.0f : -1.0f) * 50.0f * 0.01f;
        if (baseSpeed < pthis->actor.speedXZ) {
            pthis->actor.speedXZ = pthis->actor.speedXZ - decel;
            if (pthis->actor.speedXZ < baseSpeed) {
                pthis->actor.speedXZ = baseSpeed;
            }
        }
    }

    temp_f12 = *stickAnglePtr * (1 / 32236.f);
    traction = 2.2f - (pthis->actor.speedXZ * (1.0f / pthis->boostSpeed));
    turn = *stickAnglePtr * temp_f12 * temp_f12 * traction;
    turn = CLAMP(turn, -turnSpeed * traction, turnSpeed * traction);
    pthis->actor.world.rot.y += turn;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnHorse_StartMountedIdleResetAnim(EnHorse* pthis) {
    pthis->skin.skelAnime.curFrame = 0.0f;
    EnHorse_StartMountedIdle(pthis);
    pthis->stateFlags &= ~ENHORSE_SANDDUST_SOUND;
}

void EnHorse_StartMountedIdle(EnHorse* pthis) {
    f32 curFrame;

    pthis->action = ENHORSE_ACT_MOUNTED_IDLE;
    pthis->animationIdx = ENHORSE_ANIM_IDLE;
    if ((pthis->curFrame > 35.0f && pthis->type == HORSE_EPONA) || (pthis->curFrame > 28.0f && pthis->type == HORSE_HNI)) {
        if (!(pthis->stateFlags & ENHORSE_SANDDUST_SOUND)) {
            pthis->stateFlags |= ENHORSE_SANDDUST_SOUND;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SANDDUST, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
        }
    }
    curFrame = pthis->skin.skelAnime.curFrame;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, curFrame,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_StartReversingInterruptable(EnHorse* pthis);
void EnHorse_StartTurning(EnHorse* pthis);
void EnHorse_StartWalkingFromIdle(EnHorse* pthis);
void EnHorse_MountedIdleAnim(EnHorse* pthis);
void EnHorse_StartReversing(EnHorse* pthis);
void EnHorse_StartWalkingInterruptable(EnHorse* pthis);
void EnHorse_MountedIdleWhinney(EnHorse* pthis);
void EnHorse_StartWalking(EnHorse* pthis);

void EnHorse_MountedIdle(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 mag;
    s16 angle = 0;

    pthis->actor.speedXZ = 0;
    EnHorse_StickDirection(&pthis->curStick, &mag, &angle);
    if (mag > 10.0f && EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
        if (Math_CosS(angle) <= -0.5f) {
            EnHorse_StartReversingInterruptable(pthis);
        } else if (Math_CosS(angle) <= 0.7071) { // cos(45 degrees)
            EnHorse_StartTurning(pthis);
        } else {
            EnHorse_StartWalkingFromIdle(pthis);
        }
    }
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_MountedIdleAnim(pthis);
    }
}

void EnHorse_MountedIdleAnim(EnHorse* pthis) {
    pthis->skin.skelAnime.curFrame = 0.0f;
    EnHorse_MountedIdleWhinney(pthis);
}

void EnHorse_MountedIdleWhinney(EnHorse* pthis) {
    f32 curFrame;

    pthis->action = ENHORSE_ACT_MOUNTED_IDLE_WHINNEYING;
    pthis->animationIdx = ENHORSE_ANIM_WHINNEY;
    curFrame = pthis->skin.skelAnime.curFrame;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, curFrame,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

void EnHorse_MountedIdleWhinneying(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle = 0;

    pthis->actor.speedXZ = 0;
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (stickMag > 10.0f && EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
        if (Math_CosS(stickAngle) <= -0.5f) {
            EnHorse_StartReversingInterruptable(pthis);
        } else if (Math_CosS(stickAngle) <= 0.7071) { // cos(45 degrees)
            EnHorse_StartTurning(pthis);
        } else {
            EnHorse_StartWalkingFromIdle(pthis);
        }
    }
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_StartMountedIdleResetAnim(pthis);
    }
}

void EnHorse_StartTurning(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_TURN;
    pthis->soundTimer = 0;
    pthis->animationIdx = ENHORSE_ANIM_WALK;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_MountedTurn(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 clampedYaw;
    s16 stickAngle;

    pthis->actor.speedXZ = 0;
    EnHorse_PlayWalkingSound(pthis);
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (stickMag > 10.0f) {
        if (!EnHorse_PlayerCanMove(pthis, globalCtx)) {
            EnHorse_StartMountedIdleResetAnim(pthis);
        } else if (Math_CosS(stickAngle) <= -0.5f) {
            EnHorse_StartReversingInterruptable(pthis);
        } else if (Math_CosS(stickAngle) <= 0.7071) { // cos(45 degrees)
            clampedYaw = CLAMP(stickAngle, -800.0f, 800.0f);
            pthis->actor.world.rot.y = pthis->actor.world.rot.y + clampedYaw;
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        } else {
            EnHorse_StartWalkingInterruptable(pthis);
        }
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (Math_CosS(stickAngle) <= 0.7071) { // cos(45 degrees)
            EnHorse_StartTurning(pthis);
        } else {
            EnHorse_StartMountedIdleResetAnim(pthis);
        }
    }
}

void EnHorse_StartWalkingFromIdle(EnHorse* pthis) {
    EnHorse_StartWalkingInterruptable(pthis);

    if (!(pthis->stateFlags & ENHORSE_FLAG_8) && !(pthis->stateFlags & ENHORSE_FLAG_9)) {
        pthis->stateFlags |= ENHORSE_FLAG_9;
        pthis->waitTimer = 8;
        return;
    }
    pthis->waitTimer = 0;
}

void EnHorse_StartWalkingInterruptable(EnHorse* pthis) {
    pthis->noInputTimer = 0;
    pthis->noInputTimerMax = 0;
    EnHorse_StartWalking(pthis);
}

void EnHorse_StartWalking(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_WALK;
    pthis->soundTimer = 0;
    pthis->animationIdx = ENHORSE_ANIM_WALK;
    pthis->waitTimer = 0;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_MountedWalkingReset(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_WALK;
    pthis->soundTimer = 0;
    pthis->animationIdx = ENHORSE_ANIM_WALK;
    pthis->waitTimer = 0;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
}

void EnHorse_StartTrotting(EnHorse* pthis);

void EnHorse_MountedWalk(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle;

    EnHorse_PlayWalkingSound(pthis);
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (pthis->noInputTimerMax == 0.0f ||
        (pthis->noInputTimer > 0.0f && pthis->noInputTimer < pthis->noInputTimerMax - 20.0f)) {
        EnHorse_UpdateSpeed(pthis, globalCtx, 0.3f, -0.5f, 10.0f, 0.06f, 3.0f, 400);
    } else {
        pthis->actor.speedXZ = 3.0f;
    }

    if (pthis->actor.speedXZ == 0.0f) {
        pthis->stateFlags &= ~ENHORSE_FLAG_9;
        EnHorse_StartMountedIdleResetAnim(pthis);
        pthis->noInputTimer = 0;
        pthis->noInputTimerMax = 0;
    } else if (pthis->actor.speedXZ > 3.0f) {
        pthis->stateFlags &= ~ENHORSE_FLAG_9;
        EnHorse_StartTrotting(pthis);
        pthis->noInputTimer = 0;
        pthis->noInputTimerMax = 0;
    }

    if (pthis->noInputTimer > 0.0f) {
        pthis->noInputTimer--;
        if (pthis->noInputTimer <= 0.0f) {
            pthis->noInputTimerMax = 0;
        }
    }

    if (pthis->waitTimer <= 0) {
        pthis->stateFlags &= ~ENHORSE_FLAG_9;
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.75f;
        if (SkelAnime_Update(&pthis->skin.skelAnime) || pthis->actor.speedXZ == 0.0f) {
            if (pthis->noInputTimer <= 0.0f) {
                if (pthis->actor.speedXZ > 3.0f) {
                    EnHorse_StartTrotting(pthis);
                    pthis->noInputTimer = 0;
                    pthis->noInputTimerMax = 0;
                } else if ((stickMag < 10.0f) || (Math_CosS(stickAngle) <= -0.5f)) {
                    EnHorse_StartMountedIdleResetAnim(pthis);
                    pthis->noInputTimer = 0;
                    pthis->noInputTimerMax = 0;
                } else {
                    EnHorse_MountedWalkingReset(pthis);
                }
            }
        }
    } else {
        pthis->actor.speedXZ = 0.0f;
        pthis->waitTimer--;
    }
}

void EnHorse_StartTrotting(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_TROT;
    pthis->animationIdx = ENHORSE_ANIM_TROT;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_MountedTrotReset(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_TROT;
    pthis->animationIdx = ENHORSE_ANIM_TROT;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
}

void EnHorse_StartGallopingInterruptable(EnHorse* pthis);

void EnHorse_MountedTrot(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle;

    EnHorse_UpdateSpeed(pthis, globalCtx, 0.3f, -0.5f, 10.0f, 0.06f, 6.0f, 400);
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (pthis->actor.speedXZ < 3.0f) {
        EnHorse_StartWalkingInterruptable(pthis);
    }

    pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.375f;
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_PlayTrottingSound(pthis);
        func_800AA000(0.0f, 60, 8, 255);
        if (pthis->actor.speedXZ >= 6.0f) {
            EnHorse_StartGallopingInterruptable(pthis);
        } else if (pthis->actor.speedXZ < 3.0f) {
            EnHorse_StartWalkingInterruptable(pthis);
        } else {
            EnHorse_MountedTrotReset(pthis);
        }
    }
}

void EnHorse_StartGallopingInterruptable(EnHorse* pthis) {
    pthis->noInputTimerMax = 0;
    pthis->noInputTimer = 0;
    EnHorse_StartGalloping(pthis);
}

void EnHorse_StartGalloping(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_GALLOP;
    pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    pthis->unk_234 = 0;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_MountedGallopReset(EnHorse* pthis) {
    pthis->noInputTimerMax = 0;
    pthis->noInputTimer = 0;
    pthis->action = ENHORSE_ACT_MOUNTED_GALLOP;
    pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    pthis->unk_234 = 0;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
}

void EnHorse_JumpLanding(EnHorse* pthis, GlobalContext* globalCtx) {
    Vec3s* jointTable;
    f32 y;

    pthis->action = ENHORSE_ACT_MOUNTED_GALLOP;
    pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
    jointTable = pthis->skin.skelAnime.jointTable;
    y = jointTable->y;
    pthis->riderPos.y += y * 0.01f;
    pthis->postDrawFunc = NULL;
}

void EnHorse_StartBraking(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_MountedGallop(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle;

    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);

    if (pthis->noInputTimer <= 0.0f) {
        EnHorse_UpdateSpeed(pthis, globalCtx, 0.3f, -0.5f, 10.0f, 0.06f, 8.0f, 0x190);
    } else if (pthis->noInputTimer > 0.0f) {
        pthis->noInputTimer -= 1;
        pthis->actor.speedXZ = 8.0f;
    }
    if (pthis->actor.speedXZ < 6.0f) {
        EnHorse_StartTrotting(pthis);
    }

    pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.3f;
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_PlayGallopingSound(pthis);
        func_800AA000(0, 120, 8, 255);
        if (EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
            if (stickMag >= 10.0f && Math_CosS(stickAngle) <= -0.5f) {
                EnHorse_StartBraking(pthis, globalCtx);
            } else if (pthis->actor.speedXZ < 6.0f) {
                EnHorse_StartTrotting(pthis);
            } else {
                EnHorse_MountedGallopReset(pthis);
            }
            return;
        }
        EnHorse_MountedGallopReset(pthis);
    }
}

void EnHorse_StartRearing(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_MOUNTED_REARING;
    pthis->animationIdx = ENHORSE_ANIM_REARING;
    pthis->stateFlags &= ~ENHORSE_LAND2_SOUND;
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
    func_800AA000(0.0f, 180, 20, 100);
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_MountedRearing(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle;

    pthis->actor.speedXZ = 0;
    if (pthis->curFrame > 25.0f) {
        if (!(pthis->stateFlags & ENHORSE_LAND2_SOUND)) {
            pthis->stateFlags |= ENHORSE_LAND2_SOUND;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
            func_800AA000(0, 180, 20, 100);
        }
    }

    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
            if (pthis->stateFlags & ENHORSE_FORCE_REVERSING) {
                pthis->noInputTimer = 100;
                pthis->noInputTimerMax = 100;
                pthis->stateFlags &= ~ENHORSE_FORCE_REVERSING;
                EnHorse_StartReversing(pthis);
            } else if (pthis->stateFlags & ENHORSE_FORCE_WALKING) {
                pthis->noInputTimer = 100;
                pthis->noInputTimerMax = 100;
                pthis->stateFlags &= ~ENHORSE_FORCE_WALKING;
                EnHorse_StartWalking(pthis);
            } else if (Math_CosS(stickAngle) <= -0.5f) {
                EnHorse_StartReversingInterruptable(pthis);
            } else {
                EnHorse_StartMountedIdleResetAnim(pthis);
            }
            return;
        }
        EnHorse_StartMountedIdleResetAnim(pthis);
    }
}

void EnHorse_StartBraking(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->action = ENHORSE_ACT_STOPPING;
    pthis->animationIdx = ENHORSE_ANIM_STOPPING;

    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SLIP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.5f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);

    pthis->stateFlags |= ENHORSE_STOPPING_NEIGH_SOUND;
    pthis->stateFlags &= ~ENHORSE_BOOST;
}

void EnHorse_Stopping(EnHorse* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.speedXZ > 0.0f) {
        pthis->actor.speedXZ = pthis->actor.speedXZ - 0.6f;
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ = 0.0f;
        }
    }

    if (pthis->stateFlags & ENHORSE_STOPPING_NEIGH_SOUND && pthis->skin.skelAnime.curFrame > 29.0f) {
        pthis->actor.speedXZ = 0.0f;
        if (Rand_ZeroOne() > 0.5) {
            pthis->unk_21C = pthis->unk_228;
            if (pthis->stateFlags & ENHORSE_DRAW) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
            func_800AA000(0.0f, 180, 20, 100);
            pthis->stateFlags &= ~ENHORSE_STOPPING_NEIGH_SOUND;
        } else {
            EnHorse_StartMountedIdleResetAnim(pthis);
        }
    }

    if (pthis->skin.skelAnime.curFrame > 29.0f) {
        pthis->actor.speedXZ = 0.0f;
    } else if (pthis->actor.speedXZ > 3.0f && pthis->stateFlags & ENHORSE_FORCE_REVERSING) {
        pthis->actor.speedXZ = 3.0f;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (pthis->stateFlags & ENHORSE_FORCE_REVERSING) {
            pthis->noInputTimer = 100;
            pthis->noInputTimerMax = 100;
            EnHorse_StartReversing(pthis);
            pthis->stateFlags &= ~ENHORSE_FORCE_REVERSING;
        } else {
            EnHorse_StartMountedIdleResetAnim(pthis);
        }
    }
}

void EnHorse_StartReversingInterruptable(EnHorse* pthis) {
    pthis->noInputTimerMax = 0;
    pthis->noInputTimer = 0;
    EnHorse_StartReversing(pthis);
}

void EnHorse_StartReversing(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_REVERSE;
    pthis->animationIdx = ENHORSE_ANIM_WALK;
    pthis->soundTimer = 0;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_LOOP, -3.0f);
}

void EnHorse_Reverse(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 stickMag;
    s16 stickAngle;
    s16 turnAmount;
    Player* player = GET_PLAYER(globalCtx);

    EnHorse_PlayWalkingSound(pthis);
    EnHorse_StickDirection(&pthis->curStick, &stickMag, &stickAngle);
    if (EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
        if (pthis->noInputTimerMax == 0.0f ||
            (pthis->noInputTimer > 0.0f && pthis->noInputTimer < pthis->noInputTimerMax - 20.0f)) {
            if (stickMag < 10.0f && pthis->noInputTimer <= 0.0f) {
                EnHorse_StartMountedIdleResetAnim(pthis);
                pthis->actor.speedXZ = 0.0f;
                return;
            }
            if (stickMag < 10.0f) {
                stickAngle = -0x7FFF;
            } else if (Math_CosS(stickAngle) > -0.5f) {
                pthis->noInputTimerMax = 0;
                EnHorse_StartMountedIdleResetAnim(pthis);
                pthis->actor.speedXZ = 0.0f;
                return;
            }
        } else if (stickMag < 10.0f) {
            stickAngle = -0x7FFF;
        }
    } else if (player->actor.flags & ACTOR_FLAG_8) {
        EnHorse_StartMountedIdleResetAnim(pthis);
        pthis->actor.speedXZ = 0.0f;
        return;
    } else {
        stickAngle = -0x7FFF;
    }

    pthis->actor.speedXZ = -2.0f;
    turnAmount = 0x7FFF - stickAngle;
    turnAmount = CLAMP(turnAmount, -1200.0f, 1200.0f);
    pthis->actor.world.rot.y += turnAmount;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (pthis->noInputTimer > 0.0f) {
        pthis->noInputTimer--;
        if (pthis->noInputTimer <= 0.0f) {
            pthis->noInputTimerMax = 0;
        }
    }
    pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.5f * 1.5f;
    if (SkelAnime_Update(&pthis->skin.skelAnime) && (f32)pthis->noInputTimer <= 0.0f &&
        EnHorse_PlayerCanMove(pthis, globalCtx) == true) {
        if (stickMag > 10.0f && Math_CosS(stickAngle) <= -0.5f) {
            pthis->noInputTimerMax = 0;
            EnHorse_StartReversingInterruptable(pthis);
        } else if (stickMag < 10.0f) {
            pthis->noInputTimerMax = 0;
            EnHorse_StartMountedIdleResetAnim(pthis);
        } else {
            EnHorse_StartReversing(pthis);
        }
    }
}

void EnHorse_StartLowJump(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_LowJumpInit(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->skin.skelAnime.curFrame = 0.0f;
    EnHorse_StartLowJump(pthis, globalCtx);
}

void EnHorse_StartLowJump(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 curFrame;
    Vec3s* jointTable;
    f32 y;

    pthis->action = ENHORSE_ACT_LOW_JUMP;
    pthis->animationIdx = ENHORSE_ANIM_LOW_JUMP;
    curFrame = pthis->skin.skelAnime.curFrame;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.5f, curFrame,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);

    pthis->postDrawFunc = NULL;
    pthis->jumpStartY = pthis->actor.world.pos.y;

    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0;

    jointTable = pthis->skin.skelAnime.jointTable;
    y = jointTable->y;
    pthis->riderPos.y -= y * 0.01f;

    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_JUMP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    func_800AA000(0.0f, 170, 10, 10);
}

void EnHorse_Stub1(EnHorse* pthis) {
}

void EnHorse_LowJump(EnHorse* pthis, GlobalContext* globalCtx) {
    Vec3f pad;
    Vec3s* jointTable;
    f32 curFrame;
    f32 y;

    curFrame = pthis->skin.skelAnime.curFrame;
    pthis->stateFlags |= ENHORSE_JUMPING;
    pthis->actor.speedXZ = 12.0f;
    if (curFrame > 17.0f) {
        pthis->actor.gravity = -3.5f;
        if (pthis->actor.velocity.y == 0) {
            pthis->actor.velocity.y = -6.0f;
        }
        if (pthis->actor.world.pos.y < pthis->actor.floorHeight + 90.0f) {
            pthis->skin.skelAnime.playSpeed = 1.5f;
        } else {
            pthis->skin.skelAnime.playSpeed = 0;
        }
    } else {
        jointTable = pthis->skin.skelAnime.jointTable;
        y = jointTable->y;
        pthis->actor.world.pos.y = pthis->jumpStartY + y * 0.01f;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime) ||
        (curFrame > 17.0f && pthis->actor.world.pos.y < pthis->actor.floorHeight - pthis->actor.velocity.y + 80.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_800AA000(0.0f, 255, 10, 80);
        pthis->stateFlags &= ~ENHORSE_JUMPING;
        pthis->actor.gravity = -3.5f;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        func_80028A54(globalCtx, 25.0f, &pthis->actor.world.pos);
        EnHorse_JumpLanding(pthis, globalCtx);
    }
}

void EnHorse_StartHighJump(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_HighJumpInit(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->skin.skelAnime.curFrame = 0.0f;
    EnHorse_StartHighJump(pthis, globalCtx);
}

void EnHorse_StartHighJump(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 curFrame;
    Vec3s* jointTable;
    f32 y;

    pthis->action = ENHORSE_ACT_HIGH_JUMP;
    pthis->animationIdx = ENHORSE_ANIM_HIGH_JUMP;
    curFrame = pthis->skin.skelAnime.curFrame;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.5f, curFrame,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);

    pthis->jumpStartY = pthis->actor.world.pos.y;
    pthis->postDrawFunc = NULL;

    pthis->actor.gravity = 0;
    pthis->actor.velocity.y = 0.0f;

    jointTable = pthis->skin.skelAnime.jointTable;
    y = jointTable->y;
    pthis->riderPos.y -= y * 0.01f;

    pthis->stateFlags |= ENHORSE_CALC_RIDER_POS;
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_JUMP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    func_800AA000(0.0f, 170, 10, 10);
}

void EnHorse_Stub2(EnHorse* pthis) {
}

void EnHorse_HighJump(EnHorse* pthis, GlobalContext* globalCtx) {
    Vec3f pad;
    Vec3s* jointTable;
    f32 curFrame;
    f32 y;

    curFrame = pthis->skin.skelAnime.curFrame;
    pthis->stateFlags |= ENHORSE_JUMPING;
    pthis->actor.speedXZ = 13.0f;
    if (curFrame > 23.0f) {
        pthis->actor.gravity = -3.5f;
        if (pthis->actor.velocity.y == 0) {
            pthis->actor.velocity.y = -10.5f;
        }

        if (pthis->actor.world.pos.y < pthis->actor.floorHeight + 90.0f) {
            pthis->skin.skelAnime.playSpeed = 1.5f;
        } else {
            pthis->skin.skelAnime.playSpeed = 0;
        }
    } else {
        jointTable = pthis->skin.skelAnime.jointTable;
        y = jointTable->y;
        pthis->actor.world.pos.y = pthis->jumpStartY + y * 0.01f;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime) ||
        (curFrame > 23.0f && pthis->actor.world.pos.y < pthis->actor.floorHeight - pthis->actor.velocity.y + 80.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_800AA000(0.0f, 255, 10, 80);
        pthis->stateFlags &= ~ENHORSE_JUMPING;
        pthis->actor.gravity = -3.5f;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        func_80028A54(globalCtx, 25.0f, &pthis->actor.world.pos);
        EnHorse_JumpLanding(pthis, globalCtx);
    }
}

void EnHorse_InitInactive(EnHorse* pthis) {
    pthis->cyl1.base.ocFlags1 &= ~OC1_ON;
    pthis->cyl2.base.ocFlags1 &= ~OC1_ON;
    pthis->jntSph.base.ocFlags1 &= ~OC1_ON;
    pthis->action = ENHORSE_ACT_INACTIVE;
    pthis->animationIdx = ENHORSE_ANIM_WALK;
    pthis->stateFlags |= ENHORSE_INACTIVE;
    pthis->followTimer = 0;
}

void EnHorse_SetFollowAnimation(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_Inactive(EnHorse* pthis, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;

    if (DREG(53) != 0 && pthis->type == HORSE_EPONA) {
        DREG(53) = 0;
        if (EnHorse_Spawn(pthis, globalCtx) != 0) {
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
            pthis->stateFlags &= ~ENHORSE_INACTIVE;
            gSaveContext.horseData.scene = globalCtx->sceneNum;

            // Focus the camera on Epona
            Camera_SetParam(globalCtx->cameraPtrs[0], 8, pthis);
            Camera_ChangeSetting(globalCtx->cameraPtrs[0], 0x38);
            Camera_SetCameraData(globalCtx->cameraPtrs[0], 4, NULL, NULL, 0x51, 0, 0);
        }
    }
    if (!(pthis->stateFlags & ENHORSE_INACTIVE)) {
        pthis->followTimer = 0;
        EnHorse_SetFollowAnimation(pthis, globalCtx);
        pthis->actor.params = 0;
        pthis->cyl1.base.ocFlags1 |= OC1_ON;
        pthis->cyl2.base.ocFlags1 |= OC1_ON;
        pthis->jntSph.base.ocFlags1 |= OC1_ON;
    }
}

void EnHorse_PlayIdleAnimation(EnHorse* pthis, s32 anim, f32 morphFrames, f32 startFrame) {
    pthis->action = ENHORSE_ACT_IDLE;
    pthis->actor.speedXZ = 0.0f;
    if (anim != ENHORSE_ANIM_IDLE && anim != ENHORSE_ANIM_WHINNEY && anim != ENHORSE_ANIM_REARING) {
        anim = ENHORSE_ANIM_IDLE;
    }
    if (anim != pthis->animationIdx) {
        pthis->animationIdx = anim;
        if (pthis->animationIdx == ENHORSE_ANIM_IDLE) {
            pthis->stateFlags &= ~ENHORSE_SANDDUST_SOUND;
        } else if (pthis->animationIdx == ENHORSE_ANIM_WHINNEY) {
            pthis->unk_21C = pthis->unk_228;
            if (pthis->stateFlags & ENHORSE_DRAW) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        } else if (pthis->animationIdx == ENHORSE_ANIM_REARING) {
            pthis->unk_21C = pthis->unk_228;
            if (pthis->stateFlags & ENHORSE_DRAW) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
            pthis->stateFlags &= ~ENHORSE_LAND2_SOUND;
        }

        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, startFrame,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                         morphFrames);
    }
}

void EnHorse_ChangeIdleAnimation(EnHorse* pthis, s32 anim, f32 morphFrames) {
    EnHorse_PlayIdleAnimation(pthis, anim, morphFrames, pthis->curFrame);
}

void EnHorse_ResetIdleAnimation(EnHorse* pthis) {
    pthis->animationIdx = ENHORSE_ANIM_WALK; // pthis forces anim 0 to play from the beginning
    EnHorse_PlayIdleAnimation(pthis, pthis->animationIdx, 0, 0);
}

void EnHorse_StartIdleRidable(EnHorse* pthis) {
    EnHorse_ResetIdleAnimation(pthis);
    pthis->stateFlags &= ~ENHORSE_UNRIDEABLE;
}

void EnHorse_StartMovingAnimation(EnHorse* pthis, s32 arg1, f32 arg2, f32 arg3);

void EnHorse_Idle(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    EnHorse_IdleAnimSounds(pthis, globalCtx);

    if (DREG(53) && pthis->type == HORSE_EPONA) {
        DREG(53) = 0;
        if (!func_80A5BBBC(globalCtx, pthis, &pthis->actor.world.pos)) {
            if (EnHorse_Spawn(pthis, globalCtx)) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
                pthis->followTimer = 0;
                EnHorse_SetFollowAnimation(pthis, globalCtx);
                Camera_SetParam(globalCtx->cameraPtrs[0], 8, pthis);
                Camera_ChangeSetting(globalCtx->cameraPtrs[0], 0x38);
                Camera_SetCameraData(globalCtx->cameraPtrs[0], 4, NULL, NULL, 0x51, 0, 0);
            }
        } else {
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
            pthis->followTimer = 0;
            EnHorse_StartMovingAnimation(pthis, 6, -3.0f, 0.0f);
        }
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        s32 idleAnimIdx = 0;

        if (pthis->animationIdx != ENHORSE_ANIM_IDLE) {
            if (pthis->animationIdx == ENHORSE_ANIM_WHINNEY) {
                idleAnimIdx = 1;
            } else if (pthis->animationIdx == ENHORSE_ANIM_REARING) {
                idleAnimIdx = 2;
            }
        }

        // Play one of the two other idle animations
        EnHorse_PlayIdleAnimation(pthis, sIdleAnimIds[(Rand_ZeroOne() > 0.5f ? 0 : 1) + idleAnimIdx * 2], 0.0f, 0.0f);
    }
}

void EnHorse_StartMovingAnimation(EnHorse* pthis, s32 animId, f32 morphFrames, f32 startFrame) {
    pthis->action = ENHORSE_ACT_FOLLOW_PLAYER;
    pthis->stateFlags &= ~ENHORSE_TURNING_TO_PLAYER;
    if (animId != ENHORSE_ANIM_TROT && animId != ENHORSE_ANIM_GALLOP && animId != ENHORSE_ANIM_WALK) {
        animId = ENHORSE_ANIM_WALK;
    }
    if (pthis->animationIdx != animId) {
        pthis->animationIdx = animId;
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, startFrame,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                         morphFrames);
    } else {
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, startFrame,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                         0.0f);
    }
}

void EnHorse_SetFollowAnimation(EnHorse* pthis, GlobalContext* globalCtx) {
    s32 animId = ENHORSE_ANIM_WALK;
    f32 distToPlayer;

    distToPlayer = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
    if (distToPlayer > 400.0f) {
        animId = ENHORSE_ANIM_GALLOP;
    } else if (!(distToPlayer <= 300.0f)) {
        if (distToPlayer <= 400.0f) {
            animId = ENHORSE_ANIM_TROT;
        }
    }

    if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        if (distToPlayer > 400.0f) {
            animId = ENHORSE_ANIM_GALLOP;
        } else {
            animId = ENHORSE_ANIM_TROT;
        }
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        if (distToPlayer > 400.0f) {
            animId = ENHORSE_ANIM_GALLOP;
        } else if (distToPlayer < 300.0f) {
            animId = ENHORSE_ANIM_WALK;
        } else {
            animId = ENHORSE_ANIM_TROT;
        }
    } else if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        if (distToPlayer > 300.0f) {
            animId = ENHORSE_ANIM_TROT;
        } else {
            animId = ENHORSE_ANIM_WALK;
        }
    }
    EnHorse_StartMovingAnimation(pthis, animId, -3.0f, 0.0f);
}

void EnHorse_FollowPlayer(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 distToPlayer;
    f32 angleDiff;

    DREG(53) = 0;
    distToPlayer = Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);

    // First rotate if the player is behind
    if ((pthis->playerDir == PLAYER_DIR_BACK_R || pthis->playerDir == PLAYER_DIR_BACK_L) &&
        (distToPlayer > 300.0f && !(pthis->stateFlags & ENHORSE_TURNING_TO_PLAYER))) {
        pthis->animationIdx = ENHORSE_ANIM_REARING;
        pthis->stateFlags |= ENHORSE_TURNING_TO_PLAYER;
        pthis->angleToPlayer = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);
        angleDiff = (f32)pthis->angleToPlayer - (f32)pthis->actor.world.rot.y;
        if (angleDiff > 32767.f) {
            angleDiff -= 32767.0f;
        } else if (angleDiff < -32767) {
            angleDiff += 32767;
        }

        pthis->followPlayerTurnSpeed =
            angleDiff / Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]);
        Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx]);
        pthis->skin.skelAnime.playSpeed = 1.0f;
        pthis->stateFlags &= ~ENHORSE_LAND2_SOUND;
        pthis->unk_21C = pthis->unk_228;
    } else if (pthis->stateFlags & ENHORSE_TURNING_TO_PLAYER) {
        pthis->actor.world.rot.y = pthis->actor.world.rot.y + pthis->followPlayerTurnSpeed;
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        if (pthis->curFrame > 25.0f) {
            if (!(pthis->stateFlags & ENHORSE_LAND2_SOUND)) {
                pthis->stateFlags |= ENHORSE_LAND2_SOUND;
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
            }
        }
    } else {
        EnHorse_RotateToPlayer(pthis, globalCtx);
    }

    if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        pthis->actor.speedXZ = 8;
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.3f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        pthis->actor.speedXZ = 6;
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.375f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        pthis->actor.speedXZ = 3;
        EnHorse_PlayWalkingSound(pthis);
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.75f;
    } else {
        pthis->actor.speedXZ = 0;
        pthis->skin.skelAnime.playSpeed = 1.0f;
    }

    if (!(pthis->stateFlags & ENHORSE_TURNING_TO_PLAYER) && ++pthis->followTimer > 300) {
        EnHorse_StartIdleRidable(pthis);
        pthis->unk_21C = pthis->unk_228;

        if (pthis->stateFlags & ENHORSE_DRAW) {
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
            EnHorse_PlayGallopingSound(pthis);
        } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
            EnHorse_PlayTrottingSound(pthis);
        }
        pthis->stateFlags &= ~ENHORSE_TURNING_TO_PLAYER;
        if (distToPlayer < 100.0f) {
            EnHorse_StartIdleRidable(pthis);
        } else {
            EnHorse_SetFollowAnimation(pthis, globalCtx);
        }
    }
}

void EnHorse_UpdateIngoHorseAnim(EnHorse* pthis);

void EnHorse_InitIngoHorse(EnHorse* pthis) {
    pthis->curRaceWaypoint = 0;
    pthis->soundTimer = 0;
    pthis->actor.speedXZ = 0.0f;
    EnHorse_UpdateIngoHorseAnim(pthis);
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_IT_INGO_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

void EnHorse_SetIngoAnimation(s32 idx, f32 curFrame, s32 arg2, s16* animIdxOut, f32* curFrameOut) {
    *animIdxOut = sIngoAnimations[idx];
    *curFrameOut = curFrame;
    if (idx == 3 || idx == 7 || idx == 8 || idx == 4) {
        *curFrameOut = 0.0f;
    }
    if (arg2 == 1) {
        if (idx == 5) {
            *animIdxOut = 4;
            *curFrameOut = curFrame;
        } else if (idx == 6) {
            *animIdxOut = 3;
            *curFrameOut = curFrame;
        }
    }
}

void EnHorse_UpdateIngoHorseAnim(EnHorse* pthis) {
    s32 animChanged = 0;
    f32 animSpeed;

    pthis->action = ENHORSE_ACT_INGO_RACE;
    pthis->stateFlags &= ~ENHORSE_SANDDUST_SOUND;
    if (pthis->actor.speedXZ == 0.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_IDLE) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_IDLE;
    } else if (pthis->actor.speedXZ <= 3.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_WALK) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_WALK;
    } else if (pthis->actor.speedXZ <= 6.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_TROT) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_TROT;
    } else {
        if (pthis->animationIdx != ENHORSE_ANIM_GALLOP) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    }

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        animSpeed = pthis->actor.speedXZ * 0.5f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        animSpeed = pthis->actor.speedXZ * 0.25f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    } else if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        animSpeed = pthis->actor.speedXZ * 0.2f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    } else {
        animSpeed = 1.0f;
    }

    if (animChanged == true) {
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                         sPlaybackSpeeds[pthis->animationIdx] * animSpeed * 1.5f, 0,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3);
    } else {
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                         sPlaybackSpeeds[pthis->animationIdx] * animSpeed * 1.5f, 0,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, 0);
    }
}

void EnHorse_UpdateIngoRace(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 playSpeed;

    if (pthis->animationIdx == ENHORSE_ANIM_IDLE || pthis->animationIdx == ENHORSE_ANIM_WHINNEY) {
        EnHorse_IdleAnimSounds(pthis, globalCtx);
    } else if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        EnHorse_PlayWalkingSound(pthis);
    }

    EnHorse_UpdateIngoRaceInfo(pthis, globalCtx, &sIngoRace);
    if (!pthis->inRace) {
        pthis->actor.speedXZ = 0.0f;
        pthis->rider->speedXZ = 0.0f;
        if (pthis->animationIdx != ENHORSE_ANIM_IDLE) {
            EnHorse_UpdateIngoHorseAnim(pthis);
        }
    }

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        playSpeed = pthis->actor.speedXZ * 0.5f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        playSpeed = pthis->actor.speedXZ * 0.25f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        playSpeed = pthis->actor.speedXZ * 0.2f;
    } else {
        playSpeed = 1.0f;
    }
    pthis->skin.skelAnime.playSpeed = playSpeed;
    if (SkelAnime_Update(&pthis->skin.skelAnime) ||
        (pthis->animationIdx == ENHORSE_ANIM_IDLE && pthis->actor.speedXZ != 0.0f)) {
        EnHorse_UpdateIngoHorseAnim(pthis);
    }

    if (pthis->stateFlags & ENHORSE_INGO_WON) {
        ((EnIn*)pthis->rider)->animationIdx = 7;
        ((EnIn*)pthis->rider)->unk_1E0 = 0;
        return;
    }

    EnHorse_SetIngoAnimation(pthis->animationIdx, pthis->skin.skelAnime.curFrame, pthis->ingoRaceFlags & 1,
                             &((EnIn*)pthis->rider)->animationIdx, &((EnIn*)pthis->rider)->unk_1E0);
}

void EnHorse_CsMoveInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    pthis->cutsceneAction = 1;
    Animation_PlayOnceSetSpeed(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                               pthis->actor.speedXZ * 0.3f);
}

void EnHorse_CsPlayHighJumpAnim(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_CsMoveToPoint(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    Vec3f endPos;
    f32 speed = 8.0f;

    endPos.x = action->endPos.x;
    endPos.y = action->endPos.y;
    endPos.z = action->endPos.z;
    if (Math3D_Vec3f_DistXYZ(&endPos, &pthis->actor.world.pos) > speed) {
        EnHorse_RotateToPoint(pthis, globalCtx, &endPos, 400);
        pthis->actor.speedXZ = speed;
        pthis->skin.skelAnime.playSpeed = speed * 0.3f;
    } else {
        pthis->actor.world.pos = endPos;
        pthis->actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_PlayGallopingSound(pthis);
        func_800AA000(0.0f, 120, 8, 255);
        Animation_PlayOnceSetSpeed(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                                   pthis->actor.speedXZ * 0.3f);
    }
}

void EnHorse_CsSetAnimHighJump(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->skin.skelAnime.curFrame = 0.0f;
    EnHorse_CsPlayHighJumpAnim(pthis, globalCtx);
}

void EnHorse_CsPlayHighJumpAnim(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 curFrame;
    f32 y;
    Vec3s* jointTable;

    pthis->animationIdx = ENHORSE_ANIM_HIGH_JUMP;
    curFrame = pthis->skin.skelAnime.curFrame;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.5f, curFrame,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
    pthis->postDrawFunc = NULL;
    pthis->jumpStartY = pthis->actor.world.pos.y;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0;

    jointTable = pthis->skin.skelAnime.jointTable;
    y = jointTable->y;
    pthis->riderPos.y -= y * 0.01f;

    pthis->stateFlags |= ENHORSE_CALC_RIDER_POS;
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_JUMP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    func_800AA000(0.0f, 170, 10, 10);
}

void EnHorse_CsJumpInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    EnHorse_CsSetAnimHighJump(pthis, globalCtx);
    pthis->cutsceneAction = 2;
    pthis->cutsceneFlags &= ~1;
}

void EnHorse_CsJump(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    f32 temp_f2;

    if (pthis->cutsceneFlags & 1) {
        EnHorse_CsMoveToPoint(pthis, globalCtx, action);
        return;
    }
    temp_f2 = pthis->skin.skelAnime.curFrame;
    pthis->stateFlags |= ENHORSE_JUMPING;
    pthis->actor.speedXZ = 13.0f;
    if (temp_f2 > 19.0f) {
        pthis->actor.gravity = -3.5f;
        if (pthis->actor.velocity.y == 0.0f) {
            pthis->actor.velocity.y = -10.5f;
        }
        if (pthis->actor.world.pos.y < (pthis->actor.floorHeight + 90.0f)) {
            pthis->skin.skelAnime.playSpeed = 1.5f;
        } else {
            pthis->skin.skelAnime.playSpeed = 0.0f;
        }
    } else {
        Vec3s* jointTable;
        f32 y;

        jointTable = pthis->skin.skelAnime.jointTable;
        y = jointTable->y;
        pthis->actor.world.pos.y = pthis->jumpStartY + y * 0.01f;
    }
    if (SkelAnime_Update(&pthis->skin.skelAnime) ||
        (temp_f2 > 19.0f && pthis->actor.world.pos.y < (pthis->actor.floorHeight - pthis->actor.velocity.y) + 80.0f)) {
        Vec3s* jointTable;
        f32 y;

        pthis->cutsceneFlags |= 1;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_800AA000(0.0f, 255, 10, 80);
        pthis->stateFlags &= ~ENHORSE_JUMPING;
        pthis->actor.gravity = -3.5f;
        pthis->actor.velocity.y = 0;
        pthis->actor.world.pos.y = pthis->actor.floorHeight;
        func_80028A54(globalCtx, 25.0f, &pthis->actor.world.pos);
        pthis->animationIdx = ENHORSE_ANIM_GALLOP;
        Animation_PlayOnceSetSpeed(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                                   sPlaybackSpeeds[6]);
        jointTable = pthis->skin.skelAnime.jointTable;
        y = jointTable->y;
        pthis->riderPos.y += y * 0.01f;
        pthis->postDrawFunc = NULL;
    }
}

void EnHorse_CsRearingInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->animationIdx = ENHORSE_ANIM_REARING;
    pthis->cutsceneAction = 3;
    pthis->cutsceneFlags &= ~4;
    pthis->stateFlags &= ~ENHORSE_LAND2_SOUND;
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_CsRearing(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->actor.speedXZ = 0.0f;
    if (pthis->curFrame > 25.0f) {
        if (!(pthis->stateFlags & ENHORSE_LAND2_SOUND)) {
            pthis->stateFlags |= ENHORSE_LAND2_SOUND;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
        }
    }
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        pthis->animationIdx = ENHORSE_ANIM_IDLE;
        if (!(pthis->cutsceneFlags & 4)) {
            pthis->cutsceneFlags |= 4;
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             -3.0f);
        } else {
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), 0, 0.0f);
        }
    }
}

void EnHorse_WarpMoveInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->actor.world.pos.x = action->startPos.x;
    pthis->actor.world.pos.y = action->startPos.y;
    pthis->actor.world.pos.z = action->startPos.z;
    pthis->actor.prevPos = pthis->actor.world.pos;
    pthis->actor.world.rot.y = action->urot.y;
    pthis->actor.shape.rot = pthis->actor.world.rot;
    pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    pthis->cutsceneAction = 4;
    Animation_PlayOnceSetSpeed(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                               pthis->actor.speedXZ * 0.3f);
}

void EnHorse_CsWarpMoveToPoint(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    Vec3f endPos;
    f32 speed = 8.0f;

    endPos.x = action->endPos.x;
    endPos.y = action->endPos.y;
    endPos.z = action->endPos.z;
    if (Math3D_Vec3f_DistXYZ(&endPos, &pthis->actor.world.pos) > speed) {
        EnHorse_RotateToPoint(pthis, globalCtx, &endPos, 400);
        pthis->actor.speedXZ = speed;
        pthis->skin.skelAnime.playSpeed = speed * 0.3f;
    } else {
        pthis->actor.world.pos = endPos;
        pthis->actor.speedXZ = 0.0f;
    }

    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        EnHorse_PlayGallopingSound(pthis);
        func_800AA000(0.0f, 120, 8, 255);
        Animation_PlayOnceSetSpeed(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                                   pthis->actor.speedXZ * 0.3f);
    }
}

void EnHorse_CsWarpRearingInit(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->actor.world.pos.x = action->startPos.x;
    pthis->actor.world.pos.y = action->startPos.y;
    pthis->actor.world.pos.z = action->startPos.z;
    pthis->actor.prevPos = pthis->actor.world.pos;
    pthis->actor.world.rot.y = action->urot.y;
    pthis->actor.shape.rot = pthis->actor.world.rot;
    pthis->animationIdx = ENHORSE_ANIM_REARING;
    pthis->cutsceneAction = 5;
    pthis->cutsceneFlags &= ~4;
    pthis->stateFlags &= ~ENHORSE_LAND2_SOUND;
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
}

void EnHorse_CsWarpRearing(EnHorse* pthis, GlobalContext* globalCtx, CsCmdActorAction* action) {
    pthis->actor.speedXZ = 0.0f;
    if (pthis->curFrame > 25.0f) {
        if (!(pthis->stateFlags & ENHORSE_LAND2_SOUND)) {
            pthis->stateFlags |= ENHORSE_LAND2_SOUND;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
        }
    }
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        pthis->animationIdx = ENHORSE_ANIM_IDLE;
        if (!(pthis->cutsceneFlags & 4)) {
            pthis->cutsceneFlags |= 4;
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             -3.0f);
        } else {
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), 0, 0.0f);
        }
    }
}

void EnHorse_InitCutscene(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->playerControlled = false;
    pthis->action = ENHORSE_ACT_CS_UPDATE;
    pthis->cutsceneAction = 0;
    pthis->actor.speedXZ = 0.0f;
}

s32 EnHorse_GetCutsceneFunctionIndex(s32 csAction) {
    s32 numActions = ARRAY_COUNT(sCsActionTable); // prevents unrolling
    s32 i;

    for (i = 0; i < numActions; i++) {
        if (csAction == sCsActionTable[i].csAction) {
            return sCsActionTable[i].csFuncIdx;
        }
        if (csAction < sCsActionTable[i].csAction) {
            return 0;
        }
    }
    return 0;
}

void EnHorse_CutsceneUpdate(EnHorse* pthis, GlobalContext* globalCtx) {
    s32 csFunctionIdx;
    CsCmdActorAction* linkCsAction = globalCtx->csCtx.linkAction;

    if (globalCtx->csCtx.state == 3) {
        pthis->playerControlled = 1;
        pthis->actor.params = 10;
        pthis->action = ENHORSE_ACT_IDLE;
        EnHorse_Freeze(pthis);
        return;
    }

    if (linkCsAction != 0) {
        csFunctionIdx = EnHorse_GetCutsceneFunctionIndex(linkCsAction->action);
        if (csFunctionIdx != 0) {
            if (pthis->cutsceneAction != csFunctionIdx) {
                if (pthis->cutsceneAction == 0) {
                    pthis->actor.world.pos.x = linkCsAction->startPos.x;
                    pthis->actor.world.pos.y = linkCsAction->startPos.y;
                    pthis->actor.world.pos.z = linkCsAction->startPos.z;
                    pthis->actor.world.rot.y = linkCsAction->urot.y;
                    pthis->actor.shape.rot = pthis->actor.world.rot;
                    pthis->actor.prevPos = pthis->actor.world.pos;
                }
                pthis->cutsceneAction = csFunctionIdx;
                sCutsceneInitFuncs[pthis->cutsceneAction](pthis, globalCtx, linkCsAction);
            }
            sCutsceneActionFuncs[pthis->cutsceneAction](pthis, globalCtx, linkCsAction);
        }
    }
}

s32 EnHorse_UpdateHbaRaceInfo(EnHorse* pthis, GlobalContext* globalCtx, RaceInfo* raceInfo) {
    Vec3f pos;
    f32 px;
    f32 pz;
    f32 d;

    EnHorse_RaceWaypointPos(raceInfo->waypoints, pthis->curRaceWaypoint, &pos);
    Math3D_RotateXZPlane(&pos, raceInfo->waypoints[pthis->curRaceWaypoint].angle, &px, &pz, &d);

    if (pthis->curRaceWaypoint >= raceInfo->numWaypoints - 1 &&
        Math3D_Vec3f_DistXYZ(&pos, &pthis->actor.world.pos) < DREG(8)) {
        pthis->hbaFlags |= 2;
    }

    if (((pthis->actor.world.pos.x * px) + (pz * pthis->actor.world.pos.z) + d) > 0.0f) {
        pthis->curRaceWaypoint++;
        if (pthis->curRaceWaypoint >= raceInfo->numWaypoints) {
            pthis->hbaFlags |= 1;
            return 1;
        }
    }

    if (!(pthis->hbaFlags & 1)) {
        EnHorse_RotateToPoint(pthis, globalCtx, &pos, 800);
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    if (pthis->actor.speedXZ < raceInfo->waypoints[pthis->curRaceWaypoint].speed && !(pthis->hbaFlags & 1)) {
        pthis->actor.speedXZ += 0.4f;
    } else {
        pthis->actor.speedXZ -= 0.4f;
        if (pthis->actor.speedXZ < 0.0f) {
            pthis->actor.speedXZ = 0.0f;
        }
    }
    return 0;
}

void EnHorse_UpdateHbaAnim(EnHorse* pthis);

void EnHorse_InitHorsebackArchery(EnHorse* pthis) {
    pthis->hbaStarted = 0;
    pthis->soundTimer = 0;
    pthis->curRaceWaypoint = 0;
    pthis->hbaTimer = 0;
    pthis->actor.speedXZ = 0.0f;
    EnHorse_UpdateHbaAnim(pthis);
}

void EnHorse_UpdateHbaAnim(EnHorse* pthis) {
    s32 animChanged = 0;
    f32 animSpeed;

    pthis->action = ENHORSE_ACT_HBA;
    if (pthis->actor.speedXZ == 0.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_IDLE) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_IDLE;
    } else if (pthis->actor.speedXZ <= 3.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_WALK) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_WALK;
    } else if (pthis->actor.speedXZ <= 6.0f) {
        if (pthis->animationIdx != ENHORSE_ANIM_TROT) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_TROT;
    } else {
        if (pthis->animationIdx != ENHORSE_ANIM_GALLOP) {
            animChanged = true;
        }
        pthis->animationIdx = ENHORSE_ANIM_GALLOP;
    }

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        animSpeed = pthis->actor.speedXZ * 0.5f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        animSpeed = pthis->actor.speedXZ * 0.25f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        func_800AA000(0.0f, 60, 8, 255);
    } else if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        animSpeed = pthis->actor.speedXZ * 0.2f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        func_800AA000(0.0f, 120, 8, 255);
    } else {
        animSpeed = 1.0f;
    }

    if (animChanged == true) {
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                         sPlaybackSpeeds[pthis->animationIdx] * animSpeed * 1.5f, 0,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                         -3.0f);
    } else {
        Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx],
                         sPlaybackSpeeds[pthis->animationIdx] * animSpeed * 1.5f, 0,
                         Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, 0);
    }
}

void EnHorse_UpdateHorsebackArchery(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 playSpeed;
    s32 sp20;

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        EnHorse_PlayWalkingSound(pthis);
    }
    if (globalCtx->interfaceCtx.hbaAmmo == 0) {
        pthis->hbaTimer++;
    }

    sp20 = func_800F5A58(NA_BGM_HORSE_GOAL);
    EnHorse_UpdateHbaRaceInfo(pthis, globalCtx, &sHbaInfo);
    if (pthis->hbaFlags & 1 || pthis->hbaTimer >= 46) {
        if (sp20 != 1 && gSaveContext.minigameState != 3) {
            gSaveContext.cutsceneIndex = 0;
            globalCtx->nextEntranceIndex = 0x3B0;
            globalCtx->sceneLoadFlag = 0x14;
            globalCtx->fadeTransition = 0x20;
        }
    }

    if (globalCtx->interfaceCtx.hbaAmmo != 0) {
        if (!(pthis->hbaFlags & 2)) {
            if (gSaveContext.infTable[25] & 1) {
                if ((s32)gSaveContext.minigameScore >= 1500) {
                    pthis->hbaFlags |= 4;
                }
            } else {
                if ((s32)gSaveContext.minigameScore >= 1000) {
                    pthis->hbaFlags |= 4;
                }
            }
        }
    }

    if ((globalCtx->interfaceCtx.hbaAmmo == 0) || (pthis->hbaFlags & 2)) {
        if (pthis->hbaFlags & 4) {
            pthis->hbaFlags &= ~4;
            Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_HORSE_GOAL);
        }
    }

    if (!pthis->hbaStarted) {
        pthis->actor.speedXZ = 0.0f;
        if (pthis->animationIdx != ENHORSE_ANIM_IDLE) {
            EnHorse_UpdateHbaAnim(pthis);
        }
    }

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        playSpeed = pthis->actor.speedXZ * 0.5f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
        playSpeed = pthis->actor.speedXZ * 0.25f;
    } else if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
        playSpeed = pthis->actor.speedXZ * 0.2f;
    } else {
        playSpeed = 1.0f;
    }

    pthis->skin.skelAnime.playSpeed = playSpeed;
    if (SkelAnime_Update(&pthis->skin.skelAnime) ||
        (pthis->animationIdx == ENHORSE_ANIM_IDLE && pthis->actor.speedXZ != 0.0f)) {
        EnHorse_UpdateHbaAnim(pthis);
    }
}

void EnHorse_InitFleePlayer(EnHorse* pthis) {
    pthis->action = ENHORSE_ACT_FLEE_PLAYER;
    pthis->stateFlags |= ENHORSE_UNRIDEABLE;
    pthis->actor.speedXZ = 0.0f;
}

void EnHorse_FleePlayer(EnHorse* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 distToHome;
    f32 playerDistToHome;
    f32 distToPlayer;
    s32 nextAnim = pthis->animationIdx;
    s32 animFinished;
    s16 yaw;

    if (DREG(53) || pthis->type == HORSE_HNI) {
        EnHorse_StartIdleRidable(pthis);
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }

    distToHome = Math3D_Vec3f_DistXYZ(&pthis->actor.home.pos, &pthis->actor.world.pos);
    playerDistToHome = Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &pthis->actor.home.pos);
    distToPlayer = Math3D_Vec3f_DistXYZ(&player->actor.world.pos, &pthis->actor.world.pos);

    // Run home
    if (playerDistToHome > 300.0f) {
        if (distToHome > 150.0f) {
            pthis->actor.speedXZ += 0.4f;
            if (pthis->actor.speedXZ > 8.0f) {
                pthis->actor.speedXZ = 8.0f;
            }
        } else {
            pthis->actor.speedXZ -= 0.47f;
            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ = 0.0f;
            }
        }
    } else {
        // Run away from Link
        if (distToPlayer < 300.0f) {
            pthis->actor.speedXZ += 0.4f;
            if (pthis->actor.speedXZ > 8.0f) {
                pthis->actor.speedXZ = 8.0f;
            }
        } else {
            pthis->actor.speedXZ -= 0.47f;
            if (pthis->actor.speedXZ < 0.0f) {
                pthis->actor.speedXZ = 0.0f;
            }
        }
    }

    if (pthis->actor.speedXZ >= 6.0f) { // hoof it
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.3f;
        nextAnim = ENHORSE_ANIM_GALLOP;
    } else if (pthis->actor.speedXZ >= 3.0f) { // trot
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.375f;
        nextAnim = ENHORSE_ANIM_TROT;
    } else if (pthis->actor.speedXZ > 0.1f) { // walk
        pthis->skin.skelAnime.playSpeed = pthis->actor.speedXZ * 0.75f;
        nextAnim = ENHORSE_ANIM_WALK;
        EnHorse_PlayWalkingSound(pthis);
    } else { // idle
        nextAnim = Rand_ZeroOne() > 0.5f ? 1 : 0;
        EnHorse_IdleAnimSounds(pthis, globalCtx);
        pthis->skin.skelAnime.playSpeed = 1.0f;
    }

    // Turn away from Link, or towards home
    if (nextAnim == ENHORSE_ANIM_GALLOP || nextAnim == ENHORSE_ANIM_TROT || nextAnim == ENHORSE_ANIM_WALK) {
        if (playerDistToHome < 300.0f) {
            yaw = player->actor.shape.rot.y;
            yaw += (Actor_WorldYawTowardActor(&pthis->actor, &player->actor) > 0 ? 1 : -1) * 0x3FFF;
        } else {
            yaw = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos) - pthis->actor.world.rot.y;
        }

        if (yaw > 400) {
            pthis->actor.world.rot.y += 400;
        } else if (yaw < -400) {
            pthis->actor.world.rot.y -= 400;
        } else {
            pthis->actor.world.rot.y += yaw;
        }

        pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
    }

    animFinished = SkelAnime_Update(&pthis->skin.skelAnime);

    if (pthis->animationIdx == ENHORSE_ANIM_IDLE || pthis->animationIdx == ENHORSE_ANIM_WHINNEY) {
        if (nextAnim == ENHORSE_ANIM_GALLOP || nextAnim == ENHORSE_ANIM_TROT || nextAnim == ENHORSE_ANIM_WALK) {
            pthis->animationIdx = nextAnim;
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             -3.0f);
            if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
                EnHorse_PlayGallopingSound(pthis);
            } else if (pthis->animationIdx == ENHORSE_ANIM_TROT) {
                EnHorse_PlayTrottingSound(pthis);
            }
            return;
        }
    }

    if (animFinished) {
        if (nextAnim == ENHORSE_ANIM_GALLOP) {
            EnHorse_PlayGallopingSound(pthis);
        } else if (nextAnim == ENHORSE_ANIM_TROT) {
            EnHorse_PlayTrottingSound(pthis);
        }

        if (pthis->animationIdx == ENHORSE_ANIM_IDLE || pthis->animationIdx == ENHORSE_ANIM_WHINNEY) {
            if (nextAnim != pthis->animationIdx) {
                pthis->animationIdx = nextAnim;
                Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                                 Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]),
                                 ANIMMODE_ONCE, -3.0f);
                return;
            } else {
                if (Rand_ZeroOne() > 0.5f) {
                    pthis->animationIdx = ENHORSE_ANIM_IDLE;
                    pthis->stateFlags &= ~ENHORSE_SANDDUST_SOUND;
                } else {
                    pthis->animationIdx = ENHORSE_ANIM_WHINNEY;
                    pthis->unk_21C = pthis->unk_228;
                    if (pthis->stateFlags & ENHORSE_DRAW) {
                        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_GROAN, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                    }
                }
                Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                                 Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]),
                                 ANIMMODE_ONCE, -3.0f);
                return;
            }
        }

        if (nextAnim != pthis->animationIdx) {
            pthis->animationIdx = nextAnim;
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             -3.0f);
        } else {
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             0.0f);
        }
        return;
    }

    if (pthis->animationIdx == ENHORSE_ANIM_WALK) {
        if (nextAnim == ENHORSE_ANIM_IDLE || nextAnim == ENHORSE_ANIM_WHINNEY) {
            pthis->animationIdx = nextAnim;
            Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.0f, 0.0f,
                             Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE,
                             -3.0f);
        }
    }
}

void EnHorse_BridgeJumpInit(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 y;

    func_80028A54(globalCtx, 25.0f, &pthis->actor.world.pos);
    pthis->action = ENHORSE_ACT_BRIDGE_JUMP;
    pthis->stateFlags |= ENHORSE_JUMPING;
    pthis->animationIdx = ENHORSE_ANIM_HIGH_JUMP;
    y = pthis->skin.skelAnime.jointTable->y;
    y = y * 0.01f;
    pthis->bridgeJumpStart = pthis->actor.world.pos;
    pthis->bridgeJumpStart.y += y;
    pthis->bridgeJumpYVel =
        (((sBridgeJumps[pthis->bridgeJumpIdx].pos.y + 48.7f) - pthis->bridgeJumpStart.y) - -360.0f) / 30.0f;
    pthis->riderPos.y -= y;
    pthis->stateFlags |= ENHORSE_CALC_RIDER_POS;
    pthis->bridgeJumpRelAngle = pthis->actor.world.rot.y - sBridgeJumps[pthis->bridgeJumpIdx].angle;
    pthis->bridgeJumpTimer = 0;
    pthis->actor.gravity = 0.0f;
    pthis->actor.speedXZ = 0;
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->type][pthis->animationIdx], 1.5f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->type][pthis->animationIdx]), ANIMMODE_ONCE, -3.0f);
    pthis->unk_21C = pthis->unk_228;
    if (pthis->stateFlags & ENHORSE_DRAW) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_JUMP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    func_800AA000(0.0f, 170, 10, 10);
    pthis->postDrawFunc = NULL;
}

void EnHorse_StartBridgeJump(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->postDrawFunc = EnHorse_BridgeJumpInit;
    if (pthis->bridgeJumpIdx == 0) {
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGerudoValleyBridgeJumpFieldFortressCs);
        gSaveContext.cutsceneTrigger = 1;
    } else {
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(gGerudoValleyBridgeJumpFortressToFieldCs);
        gSaveContext.cutsceneTrigger = 1;
    }
}

void EnHorse_BridgeJumpMove(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 interp;
    f32 timeSq;

    interp = pthis->bridgeJumpTimer / 30.0f;
    timeSq = (pthis->bridgeJumpTimer * pthis->bridgeJumpTimer);

    pthis->actor.world.pos.x =
        ((sBridgeJumps[pthis->bridgeJumpIdx].pos.x - pthis->bridgeJumpStart.x) * interp) + pthis->bridgeJumpStart.x;
    pthis->actor.world.pos.z =
        ((sBridgeJumps[pthis->bridgeJumpIdx].pos.z - pthis->bridgeJumpStart.z) * interp) + pthis->bridgeJumpStart.z;

    pthis->actor.world.pos.y =
        (pthis->bridgeJumpStart.y + (pthis->bridgeJumpYVel * pthis->bridgeJumpTimer) + (-0.4f * timeSq));

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y =
        (sBridgeJumps[pthis->bridgeJumpIdx].angle + ((1.0f - interp) * pthis->bridgeJumpRelAngle));
    pthis->skin.skelAnime.curFrame = 23.0f * interp;
    SkelAnime_Update(&pthis->skin.skelAnime);
    if (pthis->bridgeJumpTimer < 30) {
        pthis->stateFlags |= ENHORSE_FLAG_24;
    }
}

void EnHorse_CheckBridgeJumpLanding(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 8.0f;
    pthis->skin.skelAnime.playSpeed = 1.5f;
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        pthis->stateFlags &= ~ENHORSE_JUMPING;
        pthis->actor.gravity = -3.5f;
        pthis->actor.world.pos.y = sBridgeJumps[pthis->bridgeJumpIdx].pos.y;
        func_80028A54(globalCtx, 25.0f, &pthis->actor.world.pos);
        EnHorse_JumpLanding(pthis, globalCtx);
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_LAND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        func_800AA000(0.0f, 255, 10, 80);
    }
}

void EnHorse_BridgeJump(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->bridgeJumpTimer++;
    if (pthis->bridgeJumpTimer < 30) {
        EnHorse_BridgeJumpMove(pthis, globalCtx);
        return;
    }
    EnHorse_CheckBridgeJumpLanding(pthis, globalCtx);
}

void EnHorse_Vec3fOffset(Vec3f* src, s16 yaw, f32 dist, f32 height, Vec3f* dst) {
    dst->x = src->x + Math_SinS(yaw) * dist;
    dst->y = src->y + height;
    dst->z = src->z + Math_CosS(yaw) * dist;
}

s32 EnHorse_CalcFloorHeight(EnHorse* pthis, GlobalContext* globalCtx, Vec3f* pos, CollisionPoly** floorPoly,
                            f32* floorHeight) {
    s32 bgId;
    f32 waterY;
    WaterBox* waterBox;

    *floorPoly = NULL;
    *floorHeight = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, floorPoly, &bgId, pos);

    if (*floorHeight == BGCHECK_Y_MIN) {
        return 1; // No floor
    }

    if (WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pos->x, pos->z, &waterY, &waterBox) == 1 &&
        *floorHeight < waterY) {
        return 2; // Water
    }

    if ((*floorPoly)->normal.y * COLPOLY_NORMAL_FRAC < 0.81915206f || // cos(35 degrees)
        SurfaceType_IsHorseBlocked(&globalCtx->colCtx, *floorPoly, bgId) ||
        func_80041D4C(&globalCtx->colCtx, *floorPoly, bgId) == 7) {
        return 3; // Horse blocked surface
    }
    return 0;
}

/**
 * obstacleType:
 *  1: Water in front
 *  2: Water behind?
 *  3: ?
 *  4: Obstructed in front
 *  5: Obstructed behind
 */
void EnHorse_ObstructMovement(EnHorse* pthis, GlobalContext* globalCtx, s32 obstacleType, s32 galloping) {
    if (pthis->action == ENHORSE_ACT_CS_UPDATE || EnHorse_BgCheckBridgeJumpPoint(pthis, globalCtx)) {
        return;
    }

    pthis->actor.world.pos = pthis->lastPos;
    pthis->actor.shape.rot.y = pthis->lastYaw;
    pthis->actor.world.rot.y = pthis->lastYaw;
    pthis->stateFlags |= ENHORSE_OBSTACLE;

    if (!pthis->playerControlled) {
        if (pthis->animationIdx != ENHORSE_ANIM_REARING) {
            return;
        }
    } else if (pthis->action != ENHORSE_ACT_MOUNTED_REARING) {
        if (pthis->stateFlags & ENHORSE_JUMPING) {
            pthis->stateFlags &= ~ENHORSE_JUMPING;
            pthis->actor.gravity = -3.5f;
            pthis->actor.world.pos.y = pthis->actor.floorHeight;
        }
        if (obstacleType == 1 || obstacleType == 4) {
            pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
        } else if (obstacleType == 2 || obstacleType == 5) {
            pthis->stateFlags |= ENHORSE_FORCE_WALKING;
        }
        if (galloping == true) {
            EnHorse_StartRearing(pthis);
        }
    }
}

void EnHorse_CheckFloors(EnHorse* pthis, GlobalContext* globalCtx) {
    s32 status;
    CollisionPoly* frontFloor;
    CollisionPoly* backFloor;
    s16 floorSlope;
    Vec3f frontPos;
    Vec3f backPos;
    Vec3f pos;
    f32 nx;
    f32 ny;
    f32 nz;
    s32 galloping = pthis->actor.speedXZ > 8;
    f32 dist;
    f32 waterHeight;
    WaterBox* waterBox;
    s32 pad;

    if (WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                &waterHeight, &waterBox) == 1 &&
        pthis->actor.floorHeight < waterHeight) {
        EnHorse_ObstructMovement(pthis, globalCtx, 1, galloping);
        return;
    }

    EnHorse_Vec3fOffset(&pthis->actor.world.pos, pthis->actor.shape.rot.y, 30.0f, 60.0f, &frontPos);
    status = EnHorse_CalcFloorHeight(pthis, globalCtx, &frontPos, &frontFloor, &pthis->yFront);
    if (status == 1) {
        pthis->actor.shape.rot.x = 0;
        EnHorse_ObstructMovement(pthis, globalCtx, 4, galloping);
        return;
    }
    if (status == 2) {
        EnHorse_ObstructMovement(pthis, globalCtx, 4, galloping);
        return;
    }
    if (status == 3) {
        EnHorse_ObstructMovement(pthis, globalCtx, 4, galloping);
        return;
    }

    EnHorse_Vec3fOffset(&pthis->actor.world.pos, pthis->actor.shape.rot.y, -30.0f, 60.0f, &backPos);
    status = EnHorse_CalcFloorHeight(pthis, globalCtx, &backPos, &backFloor, &pthis->yBack);
    if (status == 1) {
        pthis->actor.shape.rot.x = 0;
        EnHorse_ObstructMovement(pthis, globalCtx, 5, galloping);
        return;
    }
    if (status == 2) {
        EnHorse_ObstructMovement(pthis, globalCtx, 5, galloping);
        return;
    }
    if (status == 3) {
        EnHorse_ObstructMovement(pthis, globalCtx, 5, galloping);
        return;
    }

    floorSlope = Math_FAtan2F(pthis->yBack - pthis->yFront, 60.0f) * (0x8000 / M_PI);
    if (pthis->actor.floorPoly != 0) {
        nx = pthis->actor.floorPoly->normal.x * COLPOLY_NORMAL_FRAC;
        ny = pthis->actor.floorPoly->normal.y * COLPOLY_NORMAL_FRAC;
        nz = pthis->actor.floorPoly->normal.z * COLPOLY_NORMAL_FRAC;
        pos = frontPos;
        pos.y = pthis->yFront;
        dist = Math3D_DistPlaneToPos(nx, ny, nz, pthis->actor.floorPoly->dist, &pos);
        if ((frontFloor != pthis->actor.floorPoly) && (pthis->actor.speedXZ >= 0.0f)) {
            if ((!(pthis->stateFlags & ENHORSE_JUMPING) && dist < -40.0f) ||
                (pthis->stateFlags & ENHORSE_JUMPING && dist < -200.0f)) {
                EnHorse_ObstructMovement(pthis, globalCtx, 4, galloping);
                return;
            }
        }

        pos = backPos;
        pos.y = pthis->yBack;
        dist = Math3D_DistPlaneToPos(nx, ny, nz, pthis->actor.floorPoly->dist, &pos);
        if (((backFloor != pthis->actor.floorPoly) && (pthis->actor.speedXZ <= 0.0f) &&
             !(pthis->stateFlags & ENHORSE_JUMPING) && (dist < -40.0f)) ||
            (pthis->stateFlags & ENHORSE_JUMPING && dist < -200.0f)) {
            EnHorse_ObstructMovement(pthis, globalCtx, 5, galloping);
            return;
        }

        if (ny < 0.81915206f || // cos(35 degrees)
            SurfaceType_IsHorseBlocked(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId) ||
            func_80041D4C(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId) == 7) {
            if ((pthis->actor.speedXZ >= 0.0f)) {
                EnHorse_ObstructMovement(pthis, globalCtx, 4, galloping);
            } else {
                EnHorse_ObstructMovement(pthis, globalCtx, 5, galloping);
            }
            return;
        }

        if (pthis->stateFlags & ENHORSE_JUMPING) {
            pthis->actor.shape.rot.x = 0;
            return;
        }

        if (pthis->actor.floorHeight + 4.0f < pthis->actor.world.pos.y) {
            pthis->actor.shape.rot.x = 0;
            return;
        }

        if (fabsf(floorSlope) > 8191.0f) {
            return;
        }

        pthis->actor.shape.rot.x = floorSlope;
        pthis->actor.shape.yOffset =
            (pthis->yFront + (((pthis->yBack - pthis->yFront) * 20.0f) / 45.0f)) - pthis->actor.floorHeight;
    }
}

s32 EnHorse_GetMountSide(EnHorse* pthis, GlobalContext* globalCtx);

void EnHorse_MountDismount(EnHorse* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s32 mountSide;
    Player* player = GET_PLAYER(globalCtx);

    mountSide = EnHorse_GetMountSide(pthis, globalCtx);
    if (mountSide != 0 && !(pthis->stateFlags & ENHORSE_UNRIDEABLE) && player->rideActor == NULL) {
        Actor_SetRideActor(globalCtx, &pthis->actor, mountSide);
    }

    if (pthis->playerControlled == false && Actor_IsMounted(globalCtx, &pthis->actor) == true) {
        pthis->noInputTimer = 55;
        pthis->noInputTimerMax = 55;
        pthis->playerControlled = 1;
        EnHorse_Freeze(pthis);
    } else if (pthis->playerControlled == true && Actor_NotMounted(globalCtx, &pthis->actor) == true) {
        pthis->noInputTimer = 35;
        pthis->noInputTimerMax = 35;
        pthis->stateFlags &= ~ENHORSE_UNRIDEABLE;
        pthis->playerControlled = 0;
        EnHorse_Freeze(pthis);
    }
}

void EnHorse_StickDirection(Vec2f* curStick, f32* stickMag, s16* angle) {
    f32 dist;
    f32 y;
    f32 x;

    x = curStick->x;
    y = curStick->y;
    dist = sqrtf(SQ(x) + SQ(y));

    *stickMag = dist;
    if (dist > 60.0f) {
        *stickMag = 60.0f;
    } else {
        *stickMag = *stickMag;
    }

    *angle = Math_FAtan2F(-curStick->x, curStick->y) * (32768.0f / M_PI);
}

void EnHorse_UpdateStick(EnHorse* pthis, GlobalContext* globalCtx) {
    pthis->lastStick = pthis->curStick;
    pthis->curStick.x = globalCtx->state.input[0].rel.stick_x;
    pthis->curStick.y = globalCtx->state.input[0].rel.stick_y;
}

void EnHorse_ResolveCollision(EnHorse* pthis, GlobalContext* globalCtx, CollisionPoly* colPoly) {
    f32 dist;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 offset;

    nx = COLPOLY_GET_NORMAL(colPoly->normal.x);
    ny = COLPOLY_GET_NORMAL(colPoly->normal.y);
    nz = COLPOLY_GET_NORMAL(colPoly->normal.z);
    if (!(Math_CosS(pthis->actor.world.rot.y -
                    (s16)(Math_FAtan2F(colPoly->normal.x, colPoly->normal.z) * (0x8000 / M_PI)) - 0x7FFF) <
          0.7071f)) { // cos(45 degrees)
        dist = Math3D_DistPlaneToPos(nx, ny, nz, colPoly->dist, &pthis->actor.world.pos);
        offset = (1.0f / sqrtf(SQ(nx) + SQ(nz)));
        offset = (30.0f - dist) * offset;
        pthis->actor.world.pos.x += offset * nx;
        pthis->actor.world.pos.z += offset * nz;
    }
}

void EnHorse_BgCheckSlowMoving(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 yOffset;
    Vec3f start;
    Vec3f end;
    Vec3f intersect;
    CollisionPoly* colPoly;
    s32 bgId;

    if (globalCtx->sceneNum == SCENE_SPOT20) {
        yOffset = 19.0f;
    } else {
        yOffset = 40.0f;
    }
    Math_Vec3f_Copy(&start, &pthis->actor.world.pos);
    start.y = start.y + yOffset;

    Math_Vec3f_Copy(&end, &start);
    end.x += 30.0f * Math_SinS(pthis->actor.world.rot.y);
    end.y += 30.0f * Math_SinS(-pthis->actor.shape.rot.x);
    end.z += 30.0f * Math_CosS(pthis->actor.world.rot.y);
    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &start, &end, &intersect, &colPoly, 1, 0, 0, 1, &bgId) != 0) {
        EnHorse_ResolveCollision(pthis, globalCtx, colPoly);
    }
}

void EnHorse_HighJumpInit(EnHorse* pthis, GlobalContext* globalCtx);
void EnHorse_Stub2(EnHorse* pthis);
void EnHorse_Stub1(EnHorse* pthis);

void EnHorse_UpdateBgCheckInfo(EnHorse* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    Vec3f startPos;
    Vec3f endPos;
    Vec3f obstaclePos;
    f32 pad3;
    f32 intersectDist;
    CollisionPoly* wall = NULL;
    CollisionPoly* obstacleFloor = NULL;
    s32 bgId;
    f32 obstacleHeight;
    f32 behindObstacleHeight;
    f32 ny;
    s32 movingFast;
    s32 pad5;
    DynaPolyActor* dynaPoly;
    Vec3f intersect;
    Vec3f obstacleTop;

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, globalCtx->sceneNum == SCENE_SPOT20 ? 19.0f : 40.0f, 35.0f, 100.0f,
                            29);

    if (EnHorse_BgCheckBridgeJumpPoint(pthis, globalCtx)) {
        return;
    }

    // void 0 trick required to match, but is surely not real. revisit at a later time
    if (pthis->actor.bgCheckFlags & 8 && Math_CosS(pthis->actor.wallYaw - ((void)0, pthis->actor.world).rot.y) < -0.3f) {
        if (pthis->actor.speedXZ > 4.0f) {
            pthis->actor.speedXZ -= 1.0f;
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_SANDDUST, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &D_801333E8);
        }
    }

    if (pthis->stateFlags & ENHORSE_JUMPING || !pthis->playerControlled) {
        return;
    }

    if (pthis->actor.speedXZ < 0.0f) {
        return;
    }

    // Braking or rearing from obstacle
    if (pthis->action == ENHORSE_ACT_STOPPING || pthis->action == ENHORSE_ACT_MOUNTED_REARING) {
        return;
    }

    if (pthis->actor.speedXZ > 8.0f) {
        if (pthis->actor.speedXZ < 12.8f) {
            intersectDist = 160.0f;
            movingFast = 0;
        } else {
            intersectDist = 230.0f;
            movingFast = 1;
        }
    } else {
        EnHorse_BgCheckSlowMoving(pthis, globalCtx);
        return;
    }

    startPos = pthis->actor.world.pos;
    startPos.y += 19.0f;
    endPos = startPos;
    endPos.x += (intersectDist * Math_SinS(pthis->actor.world.rot.y));
    endPos.y += (intersectDist * Math_SinS(-pthis->actor.shape.rot.x));
    endPos.z += (intersectDist * Math_CosS(pthis->actor.world.rot.y));
    intersect = endPos;
    wall = NULL;
    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &startPos, &endPos, &intersect, &wall, 1, 0, 0, 1, &bgId) == 1) {
        intersectDist = sqrt(Math3D_Vec3fDistSq(&startPos, &intersect));
        pthis->stateFlags |= ENHORSE_OBSTACLE;
    }

    if (wall != NULL) {
        if (intersectDist < 30.0f) {
            EnHorse_ResolveCollision(pthis, globalCtx, wall);
        }
        if ((Math_CosS(pthis->actor.world.rot.y - (s16)(Math_FAtan2F(wall->normal.x, wall->normal.z) * (0x8000 / M_PI)) -
                       0x7FFF) < 0.5f) ||
            SurfaceType_IsHorseBlocked(&globalCtx->colCtx, wall, bgId) != 0) {
            return;
        }

        // too close to jump
        if ((movingFast == false && intersectDist < 80.0f) || (movingFast == true && intersectDist < 150.0f)) {
            if (movingFast == false) {
                pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            } else if (movingFast == true) {
                pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
                EnHorse_StartBraking(pthis, globalCtx);
            }
            return;
        }

        dynaPoly = DynaPoly_GetActor(&globalCtx->colCtx, bgId);
        if ((pthis->stateFlags & ENHORSE_FLAG_26) && ((dynaPoly && dynaPoly->actor.id != 0x108) || dynaPoly == 0)) {
            if (movingFast == false) {
                pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            } else if (movingFast == true) {
                pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
                EnHorse_StartBraking(pthis, globalCtx);
            }
            return;
        }
    }

    // Get obstacle's height
    intersectDist += 5.0f;
    obstaclePos = startPos;
    obstaclePos.x += intersectDist * Math_SinS(pthis->actor.world.rot.y);
    obstaclePos.y = pthis->actor.world.pos.y + 120.0f;
    obstaclePos.z += intersectDist * Math_CosS(pthis->actor.world.rot.y);
    obstacleTop = obstaclePos;
    obstacleTop.y = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &obstacleFloor, &bgId, &obstaclePos);
    if (obstacleTop.y == BGCHECK_Y_MIN) {
        return;
    }
    obstacleHeight = obstacleTop.y - pthis->actor.world.pos.y;
    if (pthis->actor.floorPoly == NULL || obstacleFloor == NULL) {
        return;
    }

    if (Math3D_DistPlaneToPos(pthis->actor.floorPoly->normal.x * COLPOLY_NORMAL_FRAC,
                              pthis->actor.floorPoly->normal.y * COLPOLY_NORMAL_FRAC,
                              pthis->actor.floorPoly->normal.z * COLPOLY_NORMAL_FRAC, pthis->actor.floorPoly->dist,
                              &obstacleTop) < -40.0f &&
        Math3D_DistPlaneToPos(
            obstacleFloor->normal.x * COLPOLY_NORMAL_FRAC, obstacleFloor->normal.y * COLPOLY_NORMAL_FRAC,
            obstacleFloor->normal.z * COLPOLY_NORMAL_FRAC, obstacleFloor->dist, &pthis->actor.world.pos) > 40.0f) {
        if (movingFast == true && pthis->action != ENHORSE_ACT_STOPPING) {
            pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            EnHorse_StartBraking(pthis, globalCtx);
        }
        pthis->stateFlags |= ENHORSE_OBSTACLE;
        return;
    }

    ny = obstacleFloor->normal.y * COLPOLY_NORMAL_FRAC;
    if (ny < 0.81915206f || // cos(35 degrees)
        (SurfaceType_IsHorseBlocked(&globalCtx->colCtx, obstacleFloor, bgId) != 0) ||
        (func_80041D4C(&globalCtx->colCtx, obstacleFloor, bgId) == 7)) {
        if (movingFast == true && pthis->action != ENHORSE_ACT_STOPPING) {
            pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            EnHorse_StartBraking(pthis, globalCtx);
        }
        return;
    }

    if (wall == NULL || obstacleTop.y < intersect.y || (pthis->stateFlags & ENHORSE_CANT_JUMP)) {
        return;
    }

    obstaclePos = startPos;
    obstaclePos.y = pthis->actor.world.pos.y + 120.0f;
    if (movingFast == false) {
        obstaclePos.x += (276.0f * Math_SinS(pthis->actor.world.rot.y));
        obstaclePos.z += (276.0f * Math_CosS(pthis->actor.world.rot.y));
    } else {
        obstaclePos.x += (390.0f * Math_SinS(pthis->actor.world.rot.y));
        obstaclePos.z += (390.0f * Math_CosS(pthis->actor.world.rot.y));
    }

    obstacleTop = obstaclePos;
    obstacleTop.y = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &obstacleFloor, &bgId, &obstaclePos);
    if (obstacleTop.y == BGCHECK_Y_MIN) {
        return;
    }

    behindObstacleHeight = obstacleTop.y - pthis->actor.world.pos.y;

    if (obstacleFloor == NULL) {
        return;
    }

    ny = obstacleFloor->normal.y * COLPOLY_NORMAL_FRAC;
    if (ny < 0.81915206f || // cos(35 degrees)
        SurfaceType_IsHorseBlocked(&globalCtx->colCtx, obstacleFloor, bgId) ||
        func_80041D4C(&globalCtx->colCtx, obstacleFloor, bgId) == 7) {
        if (movingFast == true && pthis->action != ENHORSE_ACT_STOPPING) {
            pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            EnHorse_StartBraking(pthis, globalCtx);
        }
    } else if (behindObstacleHeight < -DREG(4)) { // -70
        if (movingFast == true && pthis->action != ENHORSE_ACT_STOPPING) {
            pthis->stateFlags |= ENHORSE_FORCE_REVERSING;
            EnHorse_StartBraking(pthis, globalCtx);
        }
    } else if (movingFast == false && obstacleHeight > 19.0f && obstacleHeight <= 40.0f) {
        EnHorse_Stub1(pthis);
        pthis->postDrawFunc = EnHorse_LowJumpInit;
    } else if ((movingFast == true && pthis->actor.speedXZ < 13.8f && obstacleHeight > 19.0f &&
                obstacleHeight <= 72.0f) ||
               (pthis->actor.speedXZ > 13.8f && obstacleHeight <= 112.0f)) {

        EnHorse_Stub2(pthis);
        pthis->postDrawFunc = EnHorse_HighJumpInit;
    }
}

void EnHorse_CheckBoost(EnHorse* thisx, GlobalContext* globalCtx2) {
    EnHorse* pthis = (EnHorse*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 pad;

    if (pthis->action == ENHORSE_ACT_MOUNTED_WALK || pthis->action == ENHORSE_ACT_MOUNTED_TROT ||
        pthis->action == ENHORSE_ACT_MOUNTED_GALLOP) {
        if (CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_A) && (globalCtx->interfaceCtx.unk_1EE == 8)) {
            if (!(pthis->stateFlags & ENHORSE_BOOST) && !(pthis->stateFlags & ENHORSE_FLAG_8) &&
                !(pthis->stateFlags & ENHORSE_FLAG_9)) {
                if (pthis->numBoosts > 0) {
                    func_800AA000(0.0f, 180, 20, 100);
                    pthis->stateFlags |= ENHORSE_BOOST;
                    pthis->stateFlags |= ENHORSE_FIRST_BOOST_REGEN;
                    pthis->stateFlags |= ENHORSE_FLAG_8;
                    pthis->numBoosts--;
                    pthis->boostTimer = 0;
                    if (pthis->numBoosts == 0) {
                        pthis->boostRegenTime = 140;
                        return;
                    }
                    if (pthis->type == HORSE_EPONA) {
                        if (pthis->stateFlags & ENHORSE_FIRST_BOOST_REGEN) {
                            pthis->boostRegenTime = 60;
                            pthis->stateFlags &= ~ENHORSE_FIRST_BOOST_REGEN;
                        } else {
                            pthis->boostRegenTime = 8; // Never happens
                        }
                    } else {
                        pthis->boostRegenTime = 70;
                    }
                    return;
                }
                pthis->unk_21C = pthis->unk_228;
                if (pthis->stateFlags & ENHORSE_DRAW) {
                    if (Rand_ZeroOne() < 0.1f) {
                        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                    }
                }
            }
        }
    }
}

void EnHorse_RegenBoost(EnHorse* pthis, GlobalContext* globalCtx) {
    if (pthis->numBoosts < 6 && pthis->numBoosts > 0) {
        pthis->boostRegenTime--;
        pthis->boostTimer++;

        if (pthis->boostRegenTime <= 0) {
            pthis->numBoosts = pthis->numBoosts + 1;

            if (!EN_HORSE_CHECK_4(pthis)) {
                Audio_PlaySoundGeneral(NA_SE_SY_CARROT_RECOVER, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }

            if (pthis->numBoosts < 6) {
                pthis->boostRegenTime = 11;
            }
        }
    } else if (pthis->numBoosts == 0) {
        pthis->boostRegenTime--;
        pthis->boostTimer++;

        if (pthis->boostRegenTime <= 0) {
            pthis->boostRegenTime = 0;
            pthis->numBoosts = 6;

            if (!EN_HORSE_CHECK_4(pthis)) {
                Audio_PlaySoundGeneral(NA_SE_SY_CARROT_RECOVER, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        }
    }

    if (pthis->boostTimer == 8 && Rand_ZeroOne() < 0.25f) {
        pthis->unk_21C = pthis->unk_228;
        if (pthis->stateFlags & ENHORSE_DRAW) {
            Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }
    globalCtx->interfaceCtx.numHorseBoosts = pthis->numBoosts;
}

void EnHorse_UpdatePlayerDir(EnHorse* pthis, GlobalContext* globalCtx) {
    EnHorse* pad;
    s16 angle;
    f32 s;
    f32 c;

    angle = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.world.rot.y;
    s = Math_SinS(angle);
    c = Math_CosS(angle);
    if (s > 0.8660254f) { // sin(60 degrees)
        pthis->playerDir = PLAYER_DIR_SIDE_L;
    } else if (s < -0.8660254f) { // -sin(60 degrees)
        pthis->playerDir = PLAYER_DIR_SIDE_R;
    } else {
        if (c > 0.0f) {
            if (s > 0) {
                pthis->playerDir = PLAYER_DIR_FRONT_L;
            } else {
                pthis->playerDir = PLAYER_DIR_FRONT_R;
            }
        } else {
            if (s > 0) {
                pthis->playerDir = PLAYER_DIR_BACK_L;
            } else {
                pthis->playerDir = PLAYER_DIR_BACK_R;
            }
        }
    }
}

void EnHorse_TiltBody(EnHorse* pthis, GlobalContext* globalCtx) {
    f32 speed;
    f32 rollDiff;
    s32 targetRoll;
    s16 turnVel;

    speed = pthis->actor.speedXZ / pthis->boostSpeed;
    turnVel = pthis->actor.shape.rot.y - pthis->lastYaw;
    targetRoll = -((s16)((1820.0f * speed) * (turnVel / 480.00003f)));
    rollDiff = targetRoll - pthis->actor.world.rot.z;

    if (fabsf(targetRoll) < 100.0f) {
        pthis->actor.world.rot.z = 0;
    } else if (fabsf(rollDiff) < 100.0f) {
        pthis->actor.world.rot.z = targetRoll;
    } else if (rollDiff > 0.0f) {
        pthis->actor.world.rot.z += 100;
    } else {
        pthis->actor.world.rot.z -= 100;
    }

    pthis->actor.shape.rot.z = pthis->actor.world.rot.z;
}

s32 EnHorse_UpdateConveyors(EnHorse* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 conveyorDir;

    if ((pthis->actor.floorPoly == NULL) && (pthis != (EnHorse*)player->rideActor)) {
        return 0;
    }
    conveyorDir = SurfaceType_GetConveyorDirection(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);
    conveyorDir = (conveyorDir << 10) - pthis->actor.world.rot.y;
    if (conveyorDir > 800.0f) {
        pthis->actor.world.rot.y += 800.0f;
    } else if (conveyorDir < -800.0f) {
        pthis->actor.world.rot.y -= 800.0f;
    } else {
        pthis->actor.world.rot.y += conveyorDir;
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    return 1;
}

s32 EnHorse_RandInt(f32 range) {
    return Rand_ZeroOne() * range;
}

void EnHorse_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnHorse* pthis = (EnHorse*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    Vec3f dustAcc = { 0.0f, 0.0f, 0.0f };
    Vec3f dustVel = { 0.0f, 1.0f, 0.0f };
    Player* player = GET_PLAYER(globalCtx);

    pthis->lastYaw = thisx->shape.rot.y;
    EnHorse_UpdateStick(pthis, globalCtx);
    EnHorse_UpdatePlayerDir(pthis, globalCtx);

    if (!(pthis->stateFlags & ENHORSE_INACTIVE)) {
        EnHorse_MountDismount(pthis, globalCtx);
    }

    if (pthis->stateFlags & ENHORSE_FLAG_19) {
        if (pthis->stateFlags & ENHORSE_FLAG_20 && pthis->inRace == true) {
            pthis->stateFlags &= ~ENHORSE_FLAG_20;
            EnHorse_StartRearing(pthis);
        } else if (!(pthis->stateFlags & ENHORSE_FLAG_20) && pthis->stateFlags & ENHORSE_FLAG_21 &&
                   pthis->action != ENHORSE_ACT_MOUNTED_REARING && pthis->inRace == true) {
            pthis->stateFlags &= ~ENHORSE_FLAG_21;
            EnHorse_StartRearing(pthis);
        }
    }

    sActionFuncs[pthis->action](pthis, globalCtx);
    pthis->stateFlags &= ~ENHORSE_OBSTACLE;
    pthis->curFrame = pthis->skin.skelAnime.curFrame;
    pthis->lastPos = thisx->world.pos;
    if (!(pthis->stateFlags & ENHORSE_INACTIVE)) {
        if (pthis->action == ENHORSE_ACT_MOUNTED_GALLOP || pthis->action == ENHORSE_ACT_MOUNTED_TROT ||
            pthis->action == ENHORSE_ACT_MOUNTED_WALK) {
            EnHorse_CheckBoost(pthis, globalCtx);
        }
        if (pthis->playerControlled == true) {
            EnHorse_RegenBoost(pthis, globalCtx);
        }
        Actor_MoveForward(thisx);
        if (pthis->action == ENHORSE_ACT_INGO_RACE) {
            if (pthis->rider != NULL) {
                pthis->rider->world.pos.x = thisx->world.pos.x;
                pthis->rider->world.pos.y = thisx->world.pos.y + 10.0f;
                pthis->rider->world.pos.z = thisx->world.pos.z;
                pthis->rider->shape.rot.x = thisx->shape.rot.x;
                pthis->rider->shape.rot.y = thisx->shape.rot.y;
            }
        }
        if (pthis->jntSph.elements[0].info.ocElemFlags & 2) {
            if (thisx->speedXZ > 6.0f) {
                thisx->speedXZ -= 1.0f;
            }
        }
        if (pthis->jntSph.base.acFlags & 2) {
            pthis->unk_21C = pthis->unk_228;
            if (pthis->stateFlags & ENHORSE_DRAW) {
                Audio_PlaySoundGeneral(NA_SE_EV_HORSE_NEIGH, &pthis->unk_21C, 4, &D_801333E0, &D_801333E0, &D_801333E8);
            }
        }
        if (pthis->action != ENHORSE_ACT_INGO_RACE) {
            EnHorse_TiltBody(pthis, globalCtx);
        }
        Collider_UpdateCylinder(thisx, &pthis->cyl1);
        Collider_UpdateCylinder(thisx, &pthis->cyl2);

        // Required to match
        pthis->cyl1.dim.pos.x = pthis->cyl1.dim.pos.x + (s16)(Math_SinS(thisx->shape.rot.y) * 11.0f);
        pthis->cyl1.dim.pos.z = pthis->cyl1.dim.pos.z + (s16)(Math_CosS(thisx->shape.rot.y) * 11.0f);
        pthis->cyl2.dim.pos.x = pthis->cyl2.dim.pos.x + (s16)(Math_SinS(thisx->shape.rot.y) * -18.0f);
        pthis->cyl2.dim.pos.z = pthis->cyl2.dim.pos.z + (s16)(Math_CosS(thisx->shape.rot.y) * -18.0f);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->cyl1.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->cyl1.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->cyl2.base);
        if ((player->stateFlags1 & 1) && player->rideActor != NULL) {
            if (globalCtx->sceneNum != SCENE_SPOT20 ||
                (globalCtx->sceneNum == SCENE_SPOT20 && (thisx->world.pos.z < -2400.0f))) {
                EnHorse_UpdateConveyors(pthis, globalCtx);
            }
        }
        if (!(pthis->stateFlags & ENHORSE_FLAG_24)) {
            EnHorse_UpdateBgCheckInfo(pthis, globalCtx);
            EnHorse_CheckFloors(pthis, globalCtx);
            if (thisx->world.pos.y < pthis->yFront && thisx->world.pos.y < pthis->yBack) {
                if (pthis->yBack < pthis->yFront) {
                    thisx->world.pos.y = pthis->yBack;
                } else {
                    thisx->world.pos.y = pthis->yFront;
                }
            }

        } else {
            pthis->stateFlags &= ~ENHORSE_FLAG_24;
        }

        if (globalCtx->sceneNum == SCENE_SPOT09 && (gSaveContext.eventChkInf[9] & 0xF) != 0xF) {
            EnHorse_CheckBridgeJumps(pthis, globalCtx);
        }

        thisx->focus.pos = thisx->world.pos;
        thisx->focus.pos.y += 70.0f;
        if ((Rand_ZeroOne() < 0.025f) && pthis->blinkTimer == 0) {
            pthis->blinkTimer++;
        } else if (pthis->blinkTimer > 0) {
            pthis->blinkTimer++;
            if (pthis->blinkTimer >= 4) {
                pthis->blinkTimer = 0;
            }
        }

        if (thisx->speedXZ == 0.0f && !(pthis->stateFlags & ENHORSE_FLAG_19)) {
            thisx->colChkInfo.mass = 0xFF;
        } else {
            thisx->colChkInfo.mass = 0xFE;
        }

        if (thisx->speedXZ >= 5.0f) {
            pthis->cyl1.base.atFlags |= 1;
        } else {
            pthis->cyl1.base.atFlags &= ~1;
        }

        if (gSaveContext.entranceIndex != 343 || gSaveContext.sceneSetupIndex != 9) {
            if (pthis->dustFlags & 1) {
                pthis->dustFlags &= ~1;
                func_800287AC(globalCtx, &pthis->frontRightHoof, &dustVel, &dustAcc, EnHorse_RandInt(100) + 200,
                              EnHorse_RandInt(10) + 30, EnHorse_RandInt(20) + 30);
            } else if (pthis->dustFlags & 2) {
                pthis->dustFlags &= ~2;
                func_800287AC(globalCtx, &pthis->frontLeftHoof, &dustVel, &dustAcc, EnHorse_RandInt(100) + 200,
                              EnHorse_RandInt(10) + 30, EnHorse_RandInt(20) + 30);
            } else if (pthis->dustFlags & 4) {
                pthis->dustFlags &= ~4;
                func_800287AC(globalCtx, &pthis->backRightHoof, &dustVel, &dustAcc, EnHorse_RandInt(100) + 200,
                              EnHorse_RandInt(10) + 30, EnHorse_RandInt(20) + 30);
            } else if (pthis->dustFlags & 8) {
                pthis->dustFlags &= ~8;
                func_800287AC(globalCtx, &pthis->backLeftHoof, &dustVel, &dustAcc, EnHorse_RandInt(100) + 200,
                              EnHorse_RandInt(10) + 30, EnHorse_RandInt(20) + 30);
            }
        }
        pthis->stateFlags &= ~ENHORSE_DRAW;
    }
}

s32 EnHorse_PlayerDirToMountSide(EnHorse* pthis, GlobalContext* globalCtx, Player* player) {
    if (pthis->playerDir == PLAYER_DIR_SIDE_L) {
        return -1;
    }
    if (pthis->playerDir == PLAYER_DIR_SIDE_R) {
        return 1;
    }
    return 0;
}

s32 EnHorse_MountSideCheck(EnHorse* pthis, GlobalContext* globalCtx, Player* player) {
    s32 mountSide;

    if (Actor_WorldDistXZToActor(&pthis->actor, &player->actor) > 75.0f) {
        return 0;
    } else if (fabsf(pthis->actor.world.pos.y - player->actor.world.pos.y) > 30.0f) {
        return 0;
    } else if (Math_CosS(Actor_WorldYawTowardActor(&player->actor, &pthis->actor) - player->actor.world.rot.y) <
               0.17364818f) { // cos(80 degrees)
        return 0;
    } else {
        mountSide = EnHorse_PlayerDirToMountSide(pthis, globalCtx, player);
        if (mountSide == -1) {
            return -1;
        }
        if (mountSide == 1) {
            return 1;
        }
    }
    return 0;
}

s32 EnHorse_GetMountSide(EnHorse* pthis, GlobalContext* globalCtx) {
    if (pthis->action != ENHORSE_ACT_IDLE) {
        return 0;
    }
    if ((pthis->animationIdx != ENHORSE_ANIM_IDLE) && (pthis->animationIdx != ENHORSE_ANIM_WHINNEY)) {
        return 0;
    }
    return EnHorse_MountSideCheck(pthis, globalCtx, GET_PLAYER(globalCtx));
}

void EnHorse_RandomOffset(Vec3f* src, f32 dist, Vec3f* dst) {
    dst->x = (Rand_ZeroOne() * (dist * 2.0f) + src->x) - dist;
    dst->y = (Rand_ZeroOne() * (dist * 2.0f) + src->y) - dist;
    dst->z = (Rand_ZeroOne() * (dist * 2.0f) + src->z) - dist;
}

void EnHorse_SkinCallback1(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
    EnHorse* pthis = (EnHorse*)thisx;
    s32 pad;
    Vec3f sp94 = { 0.0f, 0.0f, 0.0f };
    Vec3f hoofOffset = { 5.0f, -4.0f, 5.0f };
    Vec3f riderOffset = { 600.0f, -1670.0f, 0.0f };
    Vec3f sp70;
    Vec3f sp64 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp58 = { 0.0f, -1.0f, 0.0f };

    f32 frame = pthis->skin.skelAnime.curFrame;
    Vec3f center;
    Vec3f newCenter;
    s32 i;
    Vec3f sp2C;
    f32 sp28;

    if (!(pthis->stateFlags & ENHORSE_CALC_RIDER_POS)) {
        func_800A6408(skin, 30, &riderOffset, &pthis->riderPos);
        pthis->riderPos.x = pthis->riderPos.x - pthis->actor.world.pos.x;
        pthis->riderPos.y = pthis->riderPos.y - pthis->actor.world.pos.y;
        pthis->riderPos.z = pthis->riderPos.z - pthis->actor.world.pos.z;
    } else {
        pthis->stateFlags &= ~ENHORSE_CALC_RIDER_POS;
    }

    func_800A6408(skin, 13, &sp94, &sp2C);
    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, &sp2C, &pthis->unk_228, &sp28);
    if ((pthis->animationIdx == ENHORSE_ANIM_IDLE && pthis->action != ENHORSE_ACT_FROZEN) &&
        ((frame > 40.0f && frame < 45.0f && pthis->type == HORSE_EPONA) ||
         (frame > 28.0f && frame < 33.0f && pthis->type == HORSE_HNI))) {
        if (Rand_ZeroOne() < 0.6f) {
            pthis->dustFlags |= 1;
            func_800A6408(skin, 28, &hoofOffset, &pthis->frontRightHoof);
            pthis->frontRightHoof.y = pthis->frontRightHoof.y - 5.0f;
        }
    } else {
        if (pthis->action == ENHORSE_ACT_STOPPING) {
            if ((frame > 10.0f && frame < 13.0f) || (frame > 25.0f && frame < 33.0f)) {
                if (Rand_ZeroOne() < 0.7f) {
                    pthis->dustFlags |= 2;
                    func_800A6408(skin, 20, &hoofOffset, &sp70);
                    EnHorse_RandomOffset(&sp70, 10.0f, &pthis->frontLeftHoof);
                }
                if (Rand_ZeroOne() < 0.7f) {
                    pthis->dustFlags |= 1;
                    func_800A6408(skin, 28, &hoofOffset, &sp70);
                    EnHorse_RandomOffset(&sp70, 10.0f, &pthis->frontRightHoof);
                }
            }

            if ((frame > 6.0f && frame < 10.0f) || (frame > 23.0f && frame < 29.0f)) {
                if (Rand_ZeroOne() < 0.7f) {
                    pthis->dustFlags |= 8;
                    func_800A6408(skin, 37, &hoofOffset, &sp70);
                    EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backLeftHoof);
                }
            }

            if ((frame > 7.0f && frame < 14.0f) || (frame > 26.0f && frame < 30.0f)) {
                if (Rand_ZeroOne() < 0.7f) {
                    pthis->dustFlags |= 4;
                    func_800A6408(skin, 45, &hoofOffset, &sp70);
                    EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backRightHoof);
                }
            }
        } else if (pthis->animationIdx == ENHORSE_ANIM_GALLOP) {
            if ((frame > 14.0f) && (frame < 16.0f)) {
                pthis->dustFlags |= 1;
                func_800A6408(skin, 28, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 5.0f, &pthis->frontRightHoof);
            } else if (frame > 8.0f && frame < 10.0f) {
                pthis->dustFlags |= 2;
                func_800A6408(skin, 20, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->frontLeftHoof);
            } else if (frame > 1.0f && frame < 3.0f) {
                pthis->dustFlags |= 4;
                func_800A6408(skin, 45, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backRightHoof);
            } else if ((frame > 26.0f) && (frame < 28.0f)) {
                pthis->dustFlags |= 8;
                func_800A6408(skin, 37, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backLeftHoof);
            }
        } else if (pthis->action == ENHORSE_ACT_LOW_JUMP && frame > 6.0f &&
                   Rand_ZeroOne() < 1.0f - (frame - 6.0f) * (1.0f / 17.0f)) {
            if (Rand_ZeroOne() < 0.5f) {
                pthis->dustFlags |= 8;
                func_800A6408(skin, 37, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backLeftHoof);
            }
            if (Rand_ZeroOne() < 0.5f) {
                pthis->dustFlags |= 4;
                func_800A6408(skin, 45, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backRightHoof);
            }
        } else if (pthis->action == ENHORSE_ACT_HIGH_JUMP && frame > 5.0f &&
                   Rand_ZeroOne() < 1.0f - (frame - 5.0f) * (1.0f / 25.0f)) {
            if (Rand_ZeroOne() < 0.5f) {
                pthis->dustFlags |= 8;
                func_800A6408(skin, 37, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backLeftHoof);
            }
            if (Rand_ZeroOne() < 0.5f) {
                pthis->dustFlags |= 4;
                func_800A6408(skin, 45, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backRightHoof);
            }
        } else if (pthis->action == ENHORSE_ACT_BRIDGE_JUMP && Rand_ZeroOne() < 0.5f) {
            if (Rand_ZeroOne() < 0.5f) {
                pthis->dustFlags |= 8;
                func_800A6408(skin, 37, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backLeftHoof);
            } else {
                pthis->dustFlags |= 4;
                func_800A6408(skin, 45, &hoofOffset, &sp70);
                EnHorse_RandomOffset(&sp70, 10.0f, &pthis->backRightHoof);
            }
        }
    }

    for (i = 0; i < pthis->jntSph.count; i++) {
        center.x = pthis->jntSph.elements[i].dim.modelSphere.center.x;
        center.y = pthis->jntSph.elements[i].dim.modelSphere.center.y;
        center.z = pthis->jntSph.elements[i].dim.modelSphere.center.z;

        func_800A6408(skin, pthis->jntSph.elements[i].dim.limb, &center, &newCenter);
        pthis->jntSph.elements[i].dim.worldSphere.center.x = newCenter.x;
        pthis->jntSph.elements[i].dim.worldSphere.center.y = newCenter.y;
        pthis->jntSph.elements[i].dim.worldSphere.center.z = newCenter.z;
        pthis->jntSph.elements[i].dim.worldSphere.radius =
            pthis->jntSph.elements[i].dim.modelSphere.radius * pthis->jntSph.elements[i].dim.scale;
    }

    //! @bug Setting colliders in a draw function allows for duplicate entries to be added to their respective lists
    //! under certain conditions, like when pausing and unpausing the game.
    //! Actors will draw for a couple of frames between the pauses, but some important logic updates will not occur.
    //! In the case of OC, pthis can cause unwanted effects such as a very large amount of displacement being applied to
    //! a colliding actor.
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->jntSph.base);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->jntSph.base);
}

// unused
static s32 D_80A667DC[] = { 0, 3, 7, 14 };

s32 EnHorse_SkinCallback2(Actor* thisx, GlobalContext* globalCtx, s32 limbIndex, PSkinAwb* arg3) {
    static void* eyeTextures[] = {
        gEponaEyeOpenTex,
        gEponaEyeHalfTex,
        gEponaEyeClosedTex,
    };
    static u8 eyeBlinkIndexes[] = { 0, 1, 2, 1 };
    EnHorse* pthis = (EnHorse*)thisx;
    s32 drawOriginalLimb = true;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_horse.c", 8582);
    if (limbIndex == 13 && pthis->type == HORSE_EPONA) {
        u8 index = eyeBlinkIndexes[pthis->blinkTimer];

        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[index]));
    } else if (pthis->type == HORSE_HNI && pthis->stateFlags & ENHORSE_FLAG_18 && limbIndex == 30) {
        func_800A5F60(globalCtx->state.gfxCtx, &pthis->skin, limbIndex, gHorseIngoGerudoSaddleDL, 0);
        drawOriginalLimb = false;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_horse.c", 8601);
    return drawOriginalLimb;
}

void EnHorse_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHorse* pthis = (EnHorse*)thisx;

    if (!(pthis->stateFlags & ENHORSE_INACTIVE)) {
        func_80093D18(globalCtx->state.gfxCtx);
        pthis->stateFlags |= ENHORSE_DRAW;
        if (pthis->stateFlags & ENHORSE_JUMPING) {
            func_800A6360(thisx, globalCtx, &pthis->skin, EnHorse_SkinCallback1, EnHorse_SkinCallback2, 0);
        } else {
            func_800A6360(thisx, globalCtx, &pthis->skin, EnHorse_SkinCallback1, EnHorse_SkinCallback2, 1);
        }
        if (pthis->postDrawFunc != NULL) {
            pthis->postDrawFunc(pthis, globalCtx);
        }
    }
}

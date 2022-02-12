#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_GOMA_Z_BOSS_GOMA_C
#include "actor_common.h"
#include "z_boss_goma.h"
#include "objects/object_goma/object_goma.h"
#include "overlays/actors/ovl_En_Goma/z_en_goma.h"
#include "overlays/actors/ovl_Door_Shutter/z_door_shutter.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "def/code_800A9F30.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/graph.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

// IRIS_FOLLOW: gohma looks towards the player (iris rotation)
// BONUS_IFRAMES: gain invincibility frames when the player does something (throwing things?), or
// randomly (see BossGoma_UpdateEye)
typedef enum {
    EYESTATE_IRIS_FOLLOW_BONUS_IFRAMES, // default, allows not drawing lens and iris when eye is closed
    EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES,
    EYESTATE_IRIS_FOLLOW_NO_IFRAMES
} GohmaEyeState;

typedef enum {
    VISUALSTATE_RED,         // main/eye: red
    VISUALSTATE_DEFAULT,     // main: greenish cyan, blinks with dark gray every 16 frames; eye: white
    VISUALSTATE_DEFEATED,    // main/eye: dark gray
    VISUALSTATE_STUNNED = 4, // main: greenish cyan, alternates with blue; eye: greenish cyan
    VISUALSTATE_HIT          // main: greenish cyan, alternates with red; eye: greenish cyan
} GohmaVisualState;

void BossGoma_Init(Actor* thisx, GlobalContext* globalCtx);
void BossGoma_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossGoma_Update(Actor* thisx, GlobalContext* globalCtx);
void BossGoma_Draw(Actor* thisx, GlobalContext* globalCtx);

void BossGoma_SetupEncounter(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_Encounter(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_Defeated(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorAttackPosture(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorPrepareAttack(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorAttack(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorDamaged(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorLandStruckDown(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorLand(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorStunned(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FallJump(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FallStruckDown(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_CeilingSpawnGohmas(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_CeilingPrepareSpawnGohmas(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorIdle(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_CeilingIdle(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_FloorMain(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_WallClimb(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_CeilingMoveToCenter(BossGoma* pthis, GlobalContext* globalCtx);
void BossGoma_SpawnChildGohma(BossGoma* pthis, GlobalContext* globalCtx, s16 i);

ActorInit Boss_Goma_InitVars = {
    ACTOR_BOSS_GOMA,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GOMA,
    sizeof(BossGoma),
    (ActorFunc)BossGoma_Init,
    (ActorFunc)BossGoma_Destroy,
    (ActorFunc)BossGoma_Update,
    (ActorFunc)BossGoma_Draw,
};

static ColliderJntSphElementInit sColliderJntSphElementInit[13] = {
    {
        {
            ELEMTYPE_UNK3,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_EYE, { { 0, 0, 1200 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_TAIL4, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_TAIL3, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_TAIL2, { { 0, 0, 0 }, 12 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_TAIL1, { { 0, 0, 0 }, 25 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_R_FEET, { { 0, 0, 0 }, 30 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_R_SHIN, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_R_THIGH_SHELL, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_L_ANTENNA_CLAW, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_R_ANTENNA_CLAW, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_L_FEET, { { 0, 0, 0 }, 30 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_L_SHIN, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { BOSSGOMA_LIMB_L_THIGH_SHELL, { { 0, 0, 0 }, 15 }, 100 },
    },
};

static ColliderJntSphInit sColliderJntSphInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    13,
    sColliderJntSphElementInit,
};

static u8 sClearPixelTableFirstPass[16 * 16] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00
};

static u8 sClearPixelTableSecondPass[16 * 16] = {
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

// indexed by limb (where the root limb is 1)
static u8 sDeadLimbLifetime[] = {
    0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    30, // tail end/last part
    40, // tail 2nd to last part
    0,  0, 0, 0, 0, 0, 0, 0,
    10, // back of right claw/hand
    15, // front of right claw/hand
    21, // part of right arm (inner)
    0,  0,
    25, // part of right arm (shell)
    0,  0,
    31, // part of right arm (shell on shoulder)
    35, // part of right arm (shoulder)
    0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    43, // end of left antenna
    48, // middle of left antenna
    53, // start of left antenna
    0,  0, 0, 0,
    42, // end of right antenna
    45, // middle of right antenna
    53, // start of right antenna
    0,  0, 0, 0, 0, 0,
    11, // back of left claw/hand
    15, // front of left claw/hand
    21, // part of left arm (inner)
    0,  0,
    25, // part of left arm (shell)
    0,  0,
    30, // part of left arm (shell on shoulder)
    35, // part of left arm (shoulder)
    0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

/**
 * Sets the `i`th pixel of a 16x16 RGBA16 image to 0 (transparent black)
 * according to the `clearPixelTable`
 */
void BossGoma_ClearPixels16x16Rgba16(s16* rgba16image, u8* clearPixelTable, s16 i) {
    if (clearPixelTable[i]) {
        rgba16image[i] = 0;
    }
}

/**
 * Sets the `i`th 2x2 pixels block of a 32x32 RGBA16 image to 0 (transparent black)
 * according to the `clearPixelTable`
 */
void BossGoma_ClearPixels32x32Rgba16(s16* rgba16image, u8* clearPixelTable, s16 i) {
    s16* targetPixel;

    if (clearPixelTable[i]) {
        // address of the top left pixel in a 2x2 pixels block located at
        // (i & 0xF, i >> 4) in a 16x16 grid of 2x2 pixels
        targetPixel = (s16*)((uintptr_t)rgba16image + (s16)((i & 0xF) * 2 + (i & 0xF0) * 4) * 2);
        // set the 2x2 block of pixels to 0
        targetPixel[0] = 0;
        targetPixel[1] = 0;
        targetPixel[32 + 0] = 0;
        targetPixel[32 + 1] = 0;
    }
}

/**
 * Clear pixels from Gohma's textures
 */
void BossGoma_ClearPixels(u8* clearPixelTable, s16 i) {
    BossGoma_ClearPixels16x16Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaBodyTex), clearPixelTable, i);
	BossGoma_ClearPixels16x16Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaShellUndersideTex), clearPixelTable, i);
    BossGoma_ClearPixels16x16Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaDarkShellTex), clearPixelTable, i);
	BossGoma_ClearPixels16x16Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaEyeTex), clearPixelTable, i);

    BossGoma_ClearPixels32x32Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaShellTex), clearPixelTable, i);
	BossGoma_ClearPixels32x32Rgba16((s16*)SEGMENTED_TO_VIRTUAL(gGohmaIrisTex), clearPixelTable, i);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x01, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -2000, ICHAIN_STOP),
};

void BossGoma_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossGoma* pthis = (BossGoma*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 4000.0f, ActorShadow_DrawCircle, 150.0f);
    SkelAnime_Init(globalCtx, &pthis->skelanime, &gGohmaSkel, &gGohmaIdleCrouchedAnim, NULL, NULL, 0);
    Animation_PlayLoop(&pthis->skelanime, &gGohmaIdleCrouchedAnim);
    pthis->actor.shape.rot.x = -0x8000; // upside-down
    pthis->eyeIrisScaleX = 1.0f;
    pthis->eyeIrisScaleY = 1.0f;
    pthis->unusedInitX = pthis->actor.world.pos.x;
    pthis->unusedInitZ = pthis->actor.world.pos.z;
    pthis->actor.world.pos.y = -300.0f; // ceiling
    pthis->actor.gravity = 0.0f;
    BossGoma_SetupEncounter(pthis, globalCtx);
    pthis->actor.colChkInfo.health = 10;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sColliderJntSphInit, pthis->colliderItems);

    if (Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
        Actor_Kill(&pthis->actor);
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, -640.0f, 0.0f, 0, 0,
                           0, WARP_DUNGEON_CHILD);
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 141.0f, -640.0f, -84.0f, 0, 0, 0, 0);
    }
}

void BossGoma_PlayEffectsAndSfx(BossGoma* pthis, GlobalContext* globalCtx, s16 arg2, s16 amountMinus1) {
    if (arg2 == 0 || arg2 == 1 || arg2 == 3) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightHandBackLimbWorldPos, 25.0f, amountMinus1, 8.0f,
                                 500, 10, 1);
    }

    if (arg2 == 0 || arg2 == 2 || arg2 == 3) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftHandBackLimbWorldPos, 25.0f, amountMinus1, 8.0f,
                                 500, 10, 1);
    }

    if (arg2 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DOWN);
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_WALK);
    }
}

void BossGoma_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BossGoma* pthis = (BossGoma*)thisx;

    SkelAnime_Free(&pthis->skelanime, globalCtx);
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

/**
 * When Gohma is hit and its health drops to 0
 */
void BossGoma_SetupDefeated(BossGoma* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelanime, &gGohmaDeathAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaDeathAnim),
                     ANIMMODE_ONCE, -2.0f);
    pthis->actionFunc = BossGoma_Defeated;
    pthis->disableGameplayLogic = true;
    pthis->decayingProgress = 0;
    pthis->noBackfaceCulling = false;
    pthis->framesUntilNextAction = 1200;
    pthis->actionState = 0;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.shape.shadowScale = 0.0f;
    Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DEAD);
}

/**
 * Initial action setup, with Gohma waiting on the ceiling for the fight to start.
 */
void BossGoma_SetupEncounter(BossGoma* pthis, GlobalContext* globalCtx) {
    f32 lastFrame = Animation_GetLastFrame(&gGohmaWalkAnim);

    Animation_Change(&pthis->skelanime, &gGohmaWalkAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, -15.0f);
    pthis->actionFunc = BossGoma_Encounter;
    pthis->actionState = 0;
    pthis->disableGameplayLogic = true;
    globalCtx->envCtx.unk_BF = 4;
    globalCtx->envCtx.unk_D6 = 0xFF;
}

/**
 * On the floor and not doing anything for 20-30 frames, before going back to BossGoma_FloorMain
 */
void BossGoma_SetupFloorIdle(BossGoma* pthis) {
    f32 lastFrame = Animation_GetLastFrame(&gGohmaIdleCrouchedAnim);

    pthis->framesUntilNextAction = Rand_S16Offset(20, 30);
    Animation_Change(&pthis->skelanime, &gGohmaIdleCrouchedAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = BossGoma_FloorIdle;
}

/**
 * On the ceiling and not doing anything for 20-30 frames, leads to spawning children gohmas
 */
void BossGoma_SetupCeilingIdle(BossGoma* pthis) {
    pthis->framesUntilNextAction = Rand_S16Offset(20, 30);
    Animation_Change(&pthis->skelanime, &gGohmaHangAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaHangAnim),
                     ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = BossGoma_CeilingIdle;
}

/**
 * When the player killed all children gohmas
 */
void BossGoma_SetupFallJump(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaLandAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_ONCE, -5.0f);
    pthis->actionFunc = BossGoma_FallJump;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -2.0f;
}

/**
 * When the player successfully hits Gohma on the ceiling
 */
void BossGoma_SetupFallStruckDown(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaCrashAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_ONCE, -5.0f);
    pthis->actionFunc = BossGoma_FallStruckDown;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -2.0f;
}

void BossGoma_SetupCeilingSpawnGohmas(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaLayEggsAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaLayEggsAnim),
                     ANIMMODE_LOOP, -15.0f);
    pthis->actionFunc = BossGoma_CeilingSpawnGohmas;
    pthis->spawnGohmasActionTimer = 0;
}

void BossGoma_SetupCeilingPrepareSpawnGohmas(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaPrepareEggsAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gGohmaPrepareEggsAnim), ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = BossGoma_CeilingPrepareSpawnGohmas;
    pthis->framesUntilNextAction = 70;
}

void BossGoma_SetupWallClimb(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaClimbAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaClimbAnim),
                     ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = BossGoma_WallClimb;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = 0.0f;
}

/**
 * Gohma either reached the ceiling after climbing a wall, or is waiting for the player to kill the (children) Gohmas.
 */
void BossGoma_SetupCeilingMoveToCenter(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaWalkAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaWalkAnim),
                     ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = BossGoma_CeilingMoveToCenter;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->framesUntilNextAction = Rand_S16Offset(30, 60);
}

/**
 * Root action when on the floor, leads to attacking or climbing.
 */
void BossGoma_SetupFloorMain(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaWalkCrouchedAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gGohmaWalkCrouchedAnim), ANIMMODE_LOOP, -5.0f);
    pthis->actionFunc = BossGoma_FloorMain;
    pthis->framesUntilNextAction = Rand_S16Offset(70, 110);
}

/**
 * Gohma jumped to the floor on its own, after the player has killed its children Gohmas.
 */
void BossGoma_SetupFloorLand(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaLandAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaLandAnim),
                     ANIMMODE_ONCE, -2.0f);
    pthis->actionFunc = BossGoma_FloorLand;
    pthis->currentAnimFrameCount = Animation_GetLastFrame(&gGohmaLandAnim);
}

/**
 * Gohma was shot by the player down from the ceiling.
 */
void BossGoma_SetupFloorLandStruckDown(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaCrashAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaCrashAnim),
                     ANIMMODE_ONCE, -2.0f);
    pthis->currentAnimFrameCount = Animation_GetLastFrame(&gGohmaCrashAnim);
    pthis->actionFunc = BossGoma_FloorLandStruckDown;
    pthis->currentAnimFrameCount = Animation_GetLastFrame(&gGohmaCrashAnim);
}

/**
 * Gohma is vulnerable, from being struck down from the ceiling or on the ground.
 */
void BossGoma_SetupFloorStunned(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaStunnedAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaStunnedAnim),
                     ANIMMODE_LOOP, -2.0f);
    pthis->actionFunc = BossGoma_FloorStunned;
}

/**
 * Take an attack posture, when the player is close enough.
 */
void BossGoma_SetupFloorAttackPosture(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaPrepareAttackAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gGohmaPrepareAttackAnim), ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = BossGoma_FloorAttackPosture;
}

/**
 * Leads to BossGoma_FloorAttack after 1 frame
 */
void BossGoma_SetupFloorPrepareAttack(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaStandAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaStandAnim),
                     ANIMMODE_LOOP, -10.0f);
    pthis->actionFunc = BossGoma_FloorPrepareAttack;
    pthis->framesUntilNextAction = 0;
}

void BossGoma_SetupFloorAttack(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaAttackAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaAttackAnim),
                     ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = BossGoma_FloorAttack;
    pthis->actionState = 0;
    pthis->framesUntilNextAction = 0;
}

/**
 * Plays an animation for Gohma being hit (while stunned)
 * The setup and the action preserve timers apart from the patience one, notably `framesUntilNextAction` which is used
 * as the stun duration
 */
void BossGoma_SetupFloorDamaged(BossGoma* pthis) {
    Animation_Change(&pthis->skelanime, &gGohmaDamageAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaDamageAnim),
                     ANIMMODE_ONCE, -2.0f);
    pthis->actionFunc = BossGoma_FloorDamaged;
}

void BossGoma_UpdateCeilingMovement(BossGoma* pthis, GlobalContext* globalCtx, f32 dz, f32 targetSpeedXZ,
                                    s16 rotateTowardsCenter) {
    static Vec3f velInit = { 0.0f, 0.0f, 0.0f };
    static Vec3f accelInit = { 0.0f, -0.5f, 0.0f };
    static Vec3f roomCenter = { -150.0f, 0.0f, -350.0f };
    Vec3f* basePos = NULL;
    s16 i;
    Vec3f vel;
    Vec3f accel;
    Vec3f pos;

    roomCenter.z += dz; // dz is always 0
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachF(&pthis->actor.speedXZ, targetSpeedXZ, 0.5f, 2.0f);

    if (rotateTowardsCenter) {
        Math_ApproachS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &roomCenter) + 0x8000, 3,
                       0x3E8);
    }

    if (Animation_OnFrame(&pthis->skelanime, 9.0f)) {
        basePos = &pthis->rightHandBackLimbWorldPos;
    } else if (Animation_OnFrame(&pthis->skelanime, 1.0f)) {
        basePos = &pthis->leftHandBackLimbWorldPos;
    }

    if (basePos != NULL) {
        for (i = 0; i < 5; i++) {
            vel = velInit;
            accel = accelInit;
            pos.x = Rand_CenteredFloat(70.0f) + basePos->x;
            pos.y = Rand_ZeroFloat(30.0f) + basePos->y;
            pos.z = Rand_CenteredFloat(70.0f) + basePos->z;
            EffectSsHahen_Spawn(globalCtx, &pos, &vel, &accel, 0, (s16)(Rand_ZeroOne() * 5.0f) + 10, -1, 10, NULL);
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_HIGH);
    }
}

void BossGoma_SetupEncounterState4(BossGoma* pthis, GlobalContext* globalCtx) {
    Player* player;
    Camera* camera;

    camera = Gameplay_GetCamera(globalCtx, 0);
    player = GET_PLAYER(globalCtx);
    pthis->actionState = 4;
    pthis->actor.flags |= ACTOR_FLAG_0;
    func_80064520(globalCtx, &globalCtx->csCtx);
    func_8002DF54(globalCtx, &pthis->actor, 1);
    pthis->subCameraId = Gameplay_CreateSubCamera(globalCtx);
    Gameplay_ChangeCameraStatus(globalCtx, 0, 3);
    Gameplay_ChangeCameraStatus(globalCtx, pthis->subCameraId, 7);
    Animation_Change(&pthis->skelanime, &gGohmaEyeRollAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaEyeRollAnim),
                     ANIMMODE_ONCE, 0.0f);
    pthis->currentAnimFrameCount = Animation_GetLastFrame(&gGohmaEyeRollAnim);

    // room center (todo: defines for hardcoded positions relative to room center)
    pthis->actor.world.pos.x = -150.0f;
    pthis->actor.world.pos.z = -350.0f;

    // room entrance, towards center
    player->actor.world.pos.x = 150.0f;
    player->actor.world.pos.z = 300.0f;

    player->actor.world.rot.y = player->actor.shape.rot.y = -0x705C;
    pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) + 0x8000;

    // room entrance, closer to room center
    pthis->subCameraEye.x = 90.0f;
    pthis->subCameraEye.z = 170.0f;
    pthis->subCameraEye.y = camera->eye.y + 20.0f;

    pthis->framesUntilNextAction = 50;

    pthis->subCameraAt.x = pthis->actor.world.pos.x;
    pthis->subCameraAt.y = pthis->actor.world.pos.y;
    pthis->subCameraAt.z = pthis->actor.world.pos.z;

    Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
}

/**
 * Spawns the door once the player entered
 * Wait for the player to look at Gohma on the ceiling
 * Handles the "meeting Gohma" cutscene, including boss card
 *
 * Skips the door and look-at-Gohma puzzle if the player already reached the boss card part before
 */
void BossGoma_Encounter(BossGoma* pthis, GlobalContext* globalCtx) {
    Camera* cam;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad[2];

    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);

    switch (pthis->actionState) {
        case 0: // wait for the player to enter the room
            // entrance of the boss room
            if (fabsf(player->actor.world.pos.x - 150.0f) < 60.0f &&
                fabsf(player->actor.world.pos.z - 350.0f) < 60.0f) {
                if (gSaveContext.eventChkInf[7] & 1) {
                    BossGoma_SetupEncounterState4(pthis, globalCtx);
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_SHUTTER, 164.72f,
                                       -480.0f, 397.68002f, 0, -0x705C, 0, 0x180);
                } else {
                    func_8002DF54(globalCtx, &pthis->actor, 8);
                    pthis->actionState = 1;
                }
            }
            break;

        case 1: // player entered the room
            func_80064520(globalCtx, &globalCtx->csCtx);
            pthis->subCameraId = Gameplay_CreateSubCamera(globalCtx);
            osSyncPrintf("MAKE CAMERA !!!   1   !!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            Gameplay_ChangeCameraStatus(globalCtx, 0, 1);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->subCameraId, 7);
            pthis->actionState = 2;
            // ceiling center
            pthis->actor.world.pos.x = -150.0f;
            pthis->actor.world.pos.y = -320.0f;
            pthis->actor.world.pos.z = -350.0f;
            // room entrance
            player->actor.world.pos.x = 150.0f;
            player->actor.world.pos.z = 300.0f;
            // near ceiling center
            pthis->subCameraEye.x = -350.0f;
            pthis->subCameraEye.y = -310.0f;
            pthis->subCameraEye.z = -350.0f;
            // below room entrance
            pthis->subCameraAt.x = player->actor.world.pos.x;
            pthis->subCameraAt.y = player->actor.world.pos.y - 200.0f + 25.0f;
            pthis->subCameraAt.z = player->actor.world.pos.z;
            pthis->framesUntilNextAction = 50;
            pthis->timer = 80;
            pthis->frameCount = 0;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            // fall-through
        case 2: // zoom on player from room center
            // room entrance, towards center
            player->actor.shape.rot.y = -0x705C;
            player->actor.world.pos.x = 150.0f;
            player->actor.world.pos.z = 300.0f;
            player->actor.world.rot.y = player->actor.shape.rot.y;
            player->actor.speedXZ = 0.0f;

            if (pthis->framesUntilNextAction == 0) {
                // (-20, 25, -65) is towards room center
                Math_ApproachF(&pthis->subCameraEye.x, player->actor.world.pos.x - 20.0f, 0.049999997f,
                               pthis->subCameraFollowSpeed * 50.0f);
                Math_ApproachF(&pthis->subCameraEye.y, player->actor.world.pos.y + 25.0f, 0.099999994f,
                               pthis->subCameraFollowSpeed * 130.0f);
                Math_ApproachF(&pthis->subCameraEye.z, player->actor.world.pos.z - 65.0f, 0.049999997f,
                               pthis->subCameraFollowSpeed * 30.0f);
                Math_ApproachF(&pthis->subCameraFollowSpeed, 0.29999998f, 1.0f, 0.0050000004f);
                if (pthis->timer == 0) {
                    Math_ApproachF(&pthis->subCameraAt.y, player->actor.world.pos.y + 35.0f, 0.099999994f,
                                   pthis->subCameraFollowSpeed * 30.0f);
                }
                pthis->subCameraAt.x = player->actor.world.pos.x;
                pthis->subCameraAt.z = player->actor.world.pos.z;
            }

            Gameplay_CameraSetAtEye(globalCtx, 0, &pthis->subCameraAt, &pthis->subCameraEye);

            if (pthis->frameCount == 176) {
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_SHUTTER, 164.72f, -480.0f,
                                   397.68002f, 0, -0x705C, 0, SHUTTER_GOHMA_BLOCK << 6);
            }

            if (pthis->frameCount == 176) {
                globalCtx->envCtx.unk_BF = 3;
                globalCtx->envCtx.unk_D6 = 0xFFFF;
            }

            if (pthis->frameCount == 190) {
                func_8002DF54(globalCtx, &pthis->actor, 2);
            }

            if (pthis->frameCount >= 228) {
                cam = Gameplay_GetCamera(globalCtx, 0);
                cam->eye = pthis->subCameraEye;
                cam->eyeNext = pthis->subCameraEye;
                cam->at = pthis->subCameraAt;
                func_800C08AC(globalCtx, pthis->subCameraId, 0);
                pthis->subCameraId = 0;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, &pthis->actor, 7);
                pthis->actionState = 3;
            }
            break;

        case 3: // wait for the player to look at Gohma
            if (fabsf(pthis->actor.projectedPos.x) < 150.0f && fabsf(pthis->actor.projectedPos.y) < 250.0f &&
                pthis->actor.projectedPos.z < 800.0f && pthis->actor.projectedPos.z > 0.0f) {
                pthis->lookedAtFrames++;
                Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);
                Math_ApproachS(&pthis->actor.world.rot.y,
                               Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) + 0x8000, 2,
                               0xBB8);
                pthis->eyeLidBottomRotX = pthis->eyeLidTopRotX = pthis->eyeIrisRotX = pthis->eyeIrisRotY = 0;
            } else {
                pthis->lookedAtFrames = 0;
                BossGoma_UpdateCeilingMovement(pthis, globalCtx, 0.0f, -5.0f, true);
            }

            if (pthis->lookedAtFrames > 15) {
                BossGoma_SetupEncounterState4(pthis, globalCtx);
            }
            break;

        case 4: // focus Gohma on the ceiling
            if (Animation_OnFrame(&pthis->skelanime, 15.0f)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DEMO_EYE);
            }

            if (pthis->framesUntilNextAction <= 40) {
                // (22, -25, 45) is towards room entrance
                Math_ApproachF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + 22.0f, 0.2f, 100.0f);
                Math_ApproachF(&pthis->subCameraEye.y, pthis->actor.world.pos.y - 25.0f, 0.2f, 100.0f);
                Math_ApproachF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + 45.0f, 0.2f, 100.0f);
                Math_ApproachF(&pthis->subCameraAt.x, pthis->actor.world.pos.x, 0.2f, 100.0f);
                Math_ApproachF(&pthis->subCameraAt.y, pthis->actor.world.pos.y + 5.0f, 0.2f, 100.0f);
                Math_ApproachF(&pthis->subCameraAt.z, pthis->actor.world.pos.z, 0.2f, 100.0f);

                if (pthis->framesUntilNextAction == 30) {
                    globalCtx->envCtx.unk_BF = 4;
                }

                if (pthis->framesUntilNextAction < 20) {
                    SkelAnime_Update(&pthis->skelanime);
                    Math_ApproachF(&pthis->eyeIrisScaleX, 1.0f, 0.8f, 0.4f);
                    Math_ApproachF(&pthis->eyeIrisScaleY, 1.0f, 0.8f, 0.4f);

                    if (Animation_OnFrame(&pthis->skelanime, 36.0f)) {
                        pthis->eyeIrisScaleX = 1.8f;
                        pthis->eyeIrisScaleY = 1.8f;
                    }

                    if (Animation_OnFrame(&pthis->skelanime, pthis->currentAnimFrameCount)) {
                        pthis->actionState = 5;
                        Animation_Change(&pthis->skelanime, &gGohmaWalkAnim, 2.0f, 0.0f,
                                         Animation_GetLastFrame(&gGohmaWalkAnim), ANIMMODE_LOOP, -5.0f);
                        pthis->framesUntilNextAction = 30;
                        pthis->subCameraFollowSpeed = 0.0f;
                    }
                }
            }
            break;

        case 5: // running on the ceiling
            // (98, 0, 85) is towards room entrance
            Math_ApproachF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + 8.0f + 90.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.y, player->actor.world.pos.y, 0.1f, pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + 45.0f + 40.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraFollowSpeed, 1.0f, 1.0f, 0.05f);
            pthis->subCameraAt.x = pthis->actor.world.pos.x;
            pthis->subCameraAt.y = pthis->actor.world.pos.y;
            pthis->subCameraAt.z = pthis->actor.world.pos.z;

            if (pthis->framesUntilNextAction < 0) {
                //! @bug ? unreachable, timer is >= 0
                SkelAnime_Update(&pthis->skelanime);
                Math_ApproachZeroF(&pthis->actor.speedXZ, 1.0f, 2.0f);
            } else {
                BossGoma_UpdateCeilingMovement(pthis, globalCtx, 0.0f, -7.5f, false);
            }

            if (pthis->framesUntilNextAction == 0) {
                Animation_Change(&pthis->skelanime, &gGohmaHangAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gGohmaHangAnim),
                                 ANIMMODE_LOOP, -5.0f);
            }

            if (pthis->framesUntilNextAction == 0) {
                pthis->actionState = 9;
                pthis->actor.speedXZ = 0.0f;
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.gravity = -2.0f;
                Animation_Change(&pthis->skelanime, &gGohmaInitialLandingAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gGohmaInitialLandingAnim), ANIMMODE_ONCE, -5.0f);
                player->actor.world.pos.x = 0.0f;
                player->actor.world.pos.z = -30.0f;
            }
            break;

        case 9: // falling from the ceiling
            Math_ApproachF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + 8.0f + 90.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.y, player->actor.world.pos.y + 10.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + 45.0f + 40.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            pthis->subCameraAt.x = pthis->actor.world.pos.x;
            pthis->subCameraAt.y = pthis->actor.world.pos.y;
            pthis->subCameraAt.z = pthis->actor.world.pos.z;
            SkelAnime_Update(&pthis->skelanime);
            Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);
            Math_ApproachS(&pthis->actor.world.rot.y,
                           Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor), 2, 0x7D0);

            if (pthis->actor.bgCheckFlags & 1) {
                pthis->actionState = 130;
                pthis->actor.velocity.y = 0.0f;
                Animation_Change(&pthis->skelanime, &gGohmaInitialLandingAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gGohmaInitialLandingAnim), ANIMMODE_ONCE, -2.0f);
                pthis->currentAnimFrameCount = Animation_GetLastFrame(&gGohmaInitialLandingAnim);
                BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 0, 5);
                pthis->framesUntilNextAction = 15;
                func_800A9F6C(0.0f, 0xC8, 0x14, 0x14);
            }
            break;

        case 130: // focus Gohma on the ground
            Math_ApproachF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + 8.0f + 90.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.y, player->actor.world.pos.y + 10.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + 45.0f + 40.0f, 0.1f,
                           pthis->subCameraFollowSpeed * 30.0f);
            Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);
            Math_ApproachS(&pthis->actor.world.rot.y,
                           Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor), 2, 0x7D0);
            SkelAnime_Update(&pthis->skelanime);
            pthis->subCameraAt.x = pthis->actor.world.pos.x;
            pthis->subCameraAt.z = pthis->actor.world.pos.z;

            if (pthis->framesUntilNextAction != 0) {
                f32 s = sinf(pthis->framesUntilNextAction * 3.1415f * 0.5f);

                pthis->subCameraAt.y = pthis->framesUntilNextAction * s * 0.7f + pthis->actor.world.pos.y;
            } else {
                Math_ApproachF(&pthis->subCameraAt.y, pthis->actor.focus.pos.y, 0.1f, 10.0f);
            }

            if (Animation_OnFrame(&pthis->skelanime, 40.0f)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_CRY1);

                if (!(gSaveContext.eventChkInf[7] & 1)) {
                    TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx,
                                           SEGMENTED_TO_VIRTUAL(gGohmaTitleCardTex), 0xA0, 0xB4, 0x80, 0x28);
                }

                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
                gSaveContext.eventChkInf[7] |= 1;
            }

            if (Animation_OnFrame(&pthis->skelanime, pthis->currentAnimFrameCount)) {
                pthis->actionState = 140;
                Animation_Change(&pthis->skelanime, &gGohmaStandAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gGohmaStandAnim), ANIMMODE_LOOP, -10.0f);
                pthis->framesUntilNextAction = 20;
            }
            break;

        case 140:
            SkelAnime_Update(&pthis->skelanime);
            Math_ApproachF(&pthis->subCameraAt.y, pthis->actor.focus.pos.y, 0.1f, 10.0f);

            if (pthis->framesUntilNextAction == 0) {
                pthis->framesUntilNextAction = 30;
                pthis->actionState = 150;
                Gameplay_ChangeCameraStatus(globalCtx, 0, 3);
            }
            break;

        case 150:
            SkelAnime_Update(&pthis->skelanime);
            Math_SmoothStepToF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + 150.0f, 0.2f, 100.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.y, pthis->actor.world.pos.y + 20.0f, 0.2f, 100.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + 220.0f, 0.2f, 100.0f, 0.1f);

            if (pthis->framesUntilNextAction == 0) {
                cam = Gameplay_GetCamera(globalCtx, 0);
                cam->eye = pthis->subCameraEye;
                cam->eyeNext = pthis->subCameraEye;
                cam->at = pthis->subCameraAt;
                func_800C08AC(globalCtx, pthis->subCameraId, 0);
                pthis->subCameraId = 0;
                BossGoma_SetupFloorMain(pthis);
                pthis->disableGameplayLogic = false;
                pthis->patienceTimer = 200;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, &pthis->actor, 7);
            }
            break;
    }

    if (pthis->subCameraId != 0) {
        Gameplay_CameraSetAtEye(globalCtx, pthis->subCameraId, &pthis->subCameraAt, &pthis->subCameraEye);
    }
}

/**
 * Handles the "Gohma defeated" cutscene and effects
 * Spawns the heart container and blue warp actors
 */
void BossGoma_Defeated(BossGoma* pthis, GlobalContext* globalCtx) {
    static Vec3f roomCenter = { -150.0f, 0.0f, -350.0f };
    f32 dx;
    f32 dz;
    s16 j;
    Vec3f vel1 = { 0.0f, 0.0f, 0.0f };
    Vec3f accel1 = { 0.0f, 1.0f, 0.0f };
    Color_RGBA8 color1 = { 255, 255, 255, 255 };
    Color_RGBA8 color2 = { 0, 100, 255, 255 };
    Vec3f vel2 = { 0.0f, 0.0f, 0.0f };
    Vec3f accel2 = { 0.0f, -0.5f, 0.0f };
    Vec3f pos;
    Camera* camera;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f childPos;
    s16 i;

    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);

    if (Animation_OnFrame(&pthis->skelanime, 107.0f)) {
        BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 0, 8);
        func_800A9F6C(0.0f, 0x96, 0x14, 0x14);
    }

    pthis->visualState = VISUALSTATE_DEFEATED;
    pthis->eyeState = EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES;

    if (pthis->framesUntilNextAction == 1001) {
        for (i = 0; i < 90; i++) {
            if (sDeadLimbLifetime[i] != 0) {
                pthis->deadLimbsState[i] = 1;
            }
        }
    }

    if (pthis->framesUntilNextAction < 1200 && pthis->framesUntilNextAction > 1100 &&
        pthis->framesUntilNextAction % 8 == 0) {
        EffectSsSibuki_SpawnBurst(globalCtx, &pthis->actor.focus.pos);
    }

    if (pthis->framesUntilNextAction < 1080 && pthis->actionState < 3) {
        if (pthis->framesUntilNextAction < 1070) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_LAST - SFX_FLAG);
        }

        for (i = 0; i < 4; i++) {
            //! @bug pthis 0-indexes into pthis->defeatedLimbPositions which is initialized with
            // pthis->defeatedLimbPositions[limb], but limb is 1-indexed in skelanime callbacks, pthis means effects
            // should spawn at pthis->defeatedLimbPositions[0] too, which is uninitialized, so map origin?
            j = (s16)(Rand_ZeroOne() * (BOSSGOMA_LIMB_MAX - 1));
            if (pthis->defeatedLimbPositions[j].y < 10000.0f) {
                pos.x = Rand_CenteredFloat(20.0f) + pthis->defeatedLimbPositions[j].x;
                pos.y = Rand_CenteredFloat(10.0f) + pthis->defeatedLimbPositions[j].y;
                pos.z = Rand_CenteredFloat(20.0f) + pthis->defeatedLimbPositions[j].z;
                func_8002836C(globalCtx, &pos, &vel1, &accel1, &color1, &color2, 500, 10, 10);
            }
        }

        for (i = 0; i < 15; i++) {
            //! @bug same as above
            j = (s16)(Rand_ZeroOne() * (BOSSGOMA_LIMB_MAX - 1));
            if (pthis->defeatedLimbPositions[j].y < 10000.0f) {
                pos.x = Rand_CenteredFloat(20.0f) + pthis->defeatedLimbPositions[j].x;
                pos.y = Rand_CenteredFloat(10.0f) + pthis->defeatedLimbPositions[j].y;
                pos.z = Rand_CenteredFloat(20.0f) + pthis->defeatedLimbPositions[j].z;
                EffectSsHahen_Spawn(globalCtx, &pos, &vel2, &accel2, 0, (s16)(Rand_ZeroOne() * 5.0f) + 10, -1, 10,
                                    NULL);
            }
        }
    }

    switch (pthis->actionState) {
        case 0:
            pthis->actionState = 1;
            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &pthis->actor, 1);
            pthis->subCameraId = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, 0, 3);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->subCameraId, 7);
            camera = Gameplay_GetCamera(globalCtx, 0);
            pthis->subCameraEye.x = camera->eye.x;
            pthis->subCameraEye.y = camera->eye.y;
            pthis->subCameraEye.z = camera->eye.z;
            pthis->subCameraAt.x = camera->at.x;
            pthis->subCameraAt.y = camera->at.y;
            pthis->subCameraAt.z = camera->at.z;
            dx = pthis->subCameraEye.x - pthis->actor.world.pos.x;
            dz = pthis->subCameraEye.z - pthis->actor.world.pos.z;
            pthis->defeatedCameraEyeDist = sqrtf(SQ(dx) + SQ(dz));
            pthis->defeatedCameraEyeAngle = Math_FAtan2F(dx, dz);
            pthis->timer = 270;
            break;

        case 1:
            dx = Math_SinS(pthis->actor.shape.rot.y) * 100.0f;
            dz = Math_CosS(pthis->actor.shape.rot.y) * 100.0f;
            Math_ApproachF(&player->actor.world.pos.x, pthis->actor.world.pos.x + dx, 0.5f, 5.0f);
            Math_ApproachF(&player->actor.world.pos.z, pthis->actor.world.pos.z + dz, 0.5f, 5.0f);

            if (pthis->framesUntilNextAction < 1080) {
                pthis->noBackfaceCulling = true;

                for (i = 0; i < 4; i++) {
                    BossGoma_ClearPixels(sClearPixelTableFirstPass, pthis->decayingProgress);
                    //! @bug pthis allows pthis->decayingProgress = 0x100 = 256 which is out of bounds when accessing
                    // sClearPixelTableFirstPass, though timers may prevent pthis from ever happening?
                    if (pthis->decayingProgress < 0x100) {
                        pthis->decayingProgress++;
                    }
                }
            }

            if (pthis->framesUntilNextAction < 1070 && pthis->frameCount % 4 == 0 && Rand_ZeroOne() < 0.5f) {
                pthis->blinkTimer = 3;
            }

            pthis->defeatedCameraEyeAngle += 0.022f;
            Math_ApproachF(&pthis->defeatedCameraEyeDist, 150.0f, 0.1f, 5.0f);
            dx = sinf(pthis->defeatedCameraEyeAngle);
            dx = dx * pthis->defeatedCameraEyeDist;
            dz = cosf(pthis->defeatedCameraEyeAngle);
            dz = dz * pthis->defeatedCameraEyeDist;
            Math_SmoothStepToF(&pthis->subCameraEye.x, pthis->actor.world.pos.x + dx, 0.2f, 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.y, pthis->actor.world.pos.y + 20.0f, 0.2f, 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.z, pthis->actor.world.pos.z + dz, 0.2f, 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.x, pthis->firstTailLimbWorldPos.x, 0.2f, 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.y, pthis->actor.focus.pos.y, 0.5f, 100.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.z, pthis->firstTailLimbWorldPos.z, 0.2f, 50.0f, 0.1f);

            if (pthis->timer == 80) {
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS_CLEAR);
            }

            if (pthis->timer == 0) {
                pthis->actionState = 2;
                Gameplay_ChangeCameraStatus(globalCtx, 0, 3);
                pthis->timer = 70;
                pthis->decayingProgress = 0;
                pthis->subCameraFollowSpeed = 0.0f;
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, pthis->actor.world.pos.x,
                            pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
            }
            break;

        case 2:
            camera = Gameplay_GetCamera(globalCtx, 0);
            Math_SmoothStepToF(&pthis->subCameraEye.x, camera->eye.x, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.y, camera->eye.y, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraEye.z, camera->eye.z, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.x, camera->at.x, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.y, camera->at.y, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraAt.z, camera->at.z, 0.2f, pthis->subCameraFollowSpeed * 50.0f, 0.1f);
            Math_SmoothStepToF(&pthis->subCameraFollowSpeed, 1.0f, 1.0f, 0.02f, 0.0f);

            if (pthis->timer == 0) {
                childPos = roomCenter;
                pthis->timer = 30;
                pthis->actionState = 3;

                for (i = 0; i < 10000; i++) {
                    if ((fabsf(childPos.x - player->actor.world.pos.x) < 100.0f &&
                         fabsf(childPos.z - player->actor.world.pos.z) < 100.0f) ||
                        (fabsf(childPos.x - pthis->actor.world.pos.x) < 150.0f &&
                         fabsf(childPos.z - pthis->actor.world.pos.z) < 150.0f)) {
                        childPos.x = Rand_CenteredFloat(400.0f) + -150.0f;
                        childPos.z = Rand_CenteredFloat(400.0f) + -350.0f;
                    } else {
                        break;
                    }
                }

                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, childPos.x,
                                   pthis->actor.world.pos.y, childPos.z, 0, 0, 0, WARP_DUNGEON_CHILD);
                Flags_SetClear(globalCtx, globalCtx->roomCtx.curRoom.num);
            }

            for (i = 0; i < 4; i++) {
                BossGoma_ClearPixels(sClearPixelTableSecondPass, pthis->decayingProgress);
                //! @bug same as sClearPixelTableFirstPass
                if (pthis->decayingProgress < 0x100) {
                    pthis->decayingProgress++;
                }
            }
            break;

        case 3:
            for (i = 0; i < 4; i++) {
                BossGoma_ClearPixels(sClearPixelTableSecondPass, pthis->decayingProgress);
                //! @bug same as sClearPixelTableFirstPass
                if (pthis->decayingProgress < 0x100) {
                    pthis->decayingProgress++;
                }
            }

            if (pthis->timer == 0) {
                if (Math_SmoothStepToF(&pthis->actor.scale.y, 0, 1.0f, 0.00075f, 0.0f) <= 0.001f) {
                    camera = Gameplay_GetCamera(globalCtx, 0);
                    camera->eye = pthis->subCameraEye;
                    camera->eyeNext = pthis->subCameraEye;
                    camera->at = pthis->subCameraAt;
                    func_800C08AC(globalCtx, pthis->subCameraId, 0);
                    pthis->subCameraId = 0;
                    func_80064534(globalCtx, &globalCtx->csCtx);
                    func_8002DF54(globalCtx, &pthis->actor, 7);
                    Actor_Kill(&pthis->actor);
                }

                pthis->actor.scale.x = pthis->actor.scale.z = pthis->actor.scale.y;
            }
            break;
    }

    if (pthis->subCameraId != 0) {
        Gameplay_CameraSetAtEye(globalCtx, pthis->subCameraId, &pthis->subCameraAt, &pthis->subCameraEye);
    }

    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
        globalCtx->envCtx.adjAmbientColor[0] += 40;
        globalCtx->envCtx.adjAmbientColor[1] += 40;
        globalCtx->envCtx.adjAmbientColor[2] += 80;
        globalCtx->envCtx.adjFogColor[0] += 10;
        globalCtx->envCtx.adjFogColor[1] += 10;
        globalCtx->envCtx.adjFogColor[2] += 20;
    } else {
        globalCtx->envCtx.adjAmbientColor[0] -= 20;
        globalCtx->envCtx.adjAmbientColor[1] -= 20;
        globalCtx->envCtx.adjAmbientColor[2] -= 40;
        globalCtx->envCtx.adjFogColor[0] -= 5;
        globalCtx->envCtx.adjFogColor[1] -= 5;
        globalCtx->envCtx.adjFogColor[2] -= 10;
    }

    if (globalCtx->envCtx.adjAmbientColor[0] > 200) {
        globalCtx->envCtx.adjAmbientColor[0] = 200;
    }
    if (globalCtx->envCtx.adjAmbientColor[1] > 200) {
        globalCtx->envCtx.adjAmbientColor[1] = 200;
    }
    if (globalCtx->envCtx.adjAmbientColor[2] > 200) {
        globalCtx->envCtx.adjAmbientColor[2] = 200;
    }
    if (globalCtx->envCtx.adjFogColor[0] > 70) {
        globalCtx->envCtx.adjFogColor[0] = 70;
    }
    if (globalCtx->envCtx.adjFogColor[1] > 70) {
        globalCtx->envCtx.adjFogColor[1] = 70;
    }
    if (globalCtx->envCtx.adjFogColor[2] > 140) {
        globalCtx->envCtx.adjFogColor[2] = 140;
    }

    if (globalCtx->envCtx.adjAmbientColor[0] < 0) {
        globalCtx->envCtx.adjAmbientColor[0] = 0;
    }
    if (globalCtx->envCtx.adjAmbientColor[1] < 0) {
        globalCtx->envCtx.adjAmbientColor[1] = 0;
    }
    if (globalCtx->envCtx.adjAmbientColor[2] < 0) {
        globalCtx->envCtx.adjAmbientColor[2] = 0;
    }
    if (globalCtx->envCtx.adjFogColor[0] < 0) {
        globalCtx->envCtx.adjFogColor[0] = 0;
    }
    if (globalCtx->envCtx.adjFogColor[1] < 0) {
        globalCtx->envCtx.adjFogColor[1] = 0;
    }
    if (globalCtx->envCtx.adjFogColor[2] < 0) {
        globalCtx->envCtx.adjFogColor[2] = 0;
    }
}

/**
 * If the player backs off, cancel the attack, or attack.
 */
void BossGoma_FloorAttackPosture(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);

    if (pthis->skelanime.curFrame >= (19.0f + 1.0f / 3.0f) && pthis->skelanime.curFrame <= 30.0f) {
        Math_ApproachS(&pthis->actor.world.rot.y, Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor),
                       3, 0xBB8);
    }

    if (Animation_OnFrame(&pthis->skelanime, Animation_GetLastFrame(&gGohmaPrepareAttackAnim))) {
        if (pthis->actor.xzDistToPlayer < 250.0f) {
            BossGoma_SetupFloorPrepareAttack(pthis);
        } else {
            BossGoma_SetupFloorMain(pthis);
        }
    }

    pthis->eyeState = EYESTATE_IRIS_FOLLOW_NO_IFRAMES;
    pthis->visualState = VISUALSTATE_RED;
}

/**
 * Only lasts 1 frame. Plays a sound.
 */
void BossGoma_FloorPrepareAttack(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->framesUntilNextAction == 0) {
        BossGoma_SetupFloorAttack(pthis);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_CRY1);
    }

    pthis->eyeState = EYESTATE_IRIS_FOLLOW_NO_IFRAMES;
    pthis->visualState = VISUALSTATE_RED;
}

/**
 * Gohma attacks, then the action eventually goes back to BossGoma_FloorMain
 */
void BossGoma_FloorAttack(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 i;

    pthis->actor.flags |= ACTOR_FLAG_24;
    SkelAnime_Update(&pthis->skelanime);

    switch (pthis->actionState) {
        case 0:
            for (i = 0; i < pthis->collider.count; i++) {
                if (pthis->collider.elements[i].info.toucherFlags & 2) {
                    pthis->framesUntilNextAction = 10;
                    break;
                }
            }

            if (Animation_OnFrame(&pthis->skelanime, 10.0f)) {
                BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 3, 5);
                func_80033E88(&pthis->actor, globalCtx, 5, 15);
            }

            if (Animation_OnFrame(&pthis->skelanime, Animation_GetLastFrame(&gGohmaAttackAnim))) {
                pthis->actionState = 1;
                Animation_Change(&pthis->skelanime, &gGohmaRestAfterAttackAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gGohmaRestAfterAttackAnim), ANIMMODE_LOOP, -1.0f);

                if (pthis->framesUntilNextAction == 0) {
                    pthis->timer = (s16)(Rand_ZeroOne() * 30.0f) + 30;
                }
            }
            break;

        case 1:
            if (Animation_OnFrame(&pthis->skelanime, 3.0f)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_UNARI2);
            }

            if (pthis->timer == 0) {
                pthis->actionState = 2;
                Animation_Change(&pthis->skelanime, &gGohmaRecoverAfterAttackAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gGohmaRecoverAfterAttackAnim), ANIMMODE_ONCE, -5.0f);
            }
            break;

        case 2:
            if (Animation_OnFrame(&pthis->skelanime, Animation_GetLastFrame(&gGohmaRecoverAfterAttackAnim))) {
                BossGoma_SetupFloorIdle(pthis);
            }
            break;
    }

    pthis->eyeState = EYESTATE_IRIS_FOLLOW_NO_IFRAMES;
    pthis->visualState = VISUALSTATE_RED;
}

/**
 * Plays the animation to its end, then goes back to BossGoma_FloorStunned
 */
void BossGoma_FloorDamaged(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, Animation_GetLastFrame(&gGohmaDamageAnim))) {
        BossGoma_SetupFloorStunned(pthis);
        pthis->patienceTimer = 0;
    }

    pthis->eyeState = EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES;
    Math_ApproachF(&pthis->eyeIrisScaleX, 0.4f, 0.5f, 0.2f);
    pthis->visualState = VISUALSTATE_HIT;
}

/**
 * Gohma is back on the floor after the player struck it down from the ceiling.
 * Sets patience to 0
 * Gohma is then stunned (BossGoma_FloorStunned)
 */
void BossGoma_FloorLandStruckDown(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, pthis->currentAnimFrameCount)) {
        BossGoma_SetupFloorStunned(pthis);
        pthis->sfxFaintTimer = 92;
        pthis->patienceTimer = 0;
        pthis->framesUntilNextAction = 150;
    }

    Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 55.0f, 4, 8.0f, 500, 10, 1);
}

/**
 * Gohma is back on the floor after the player has killed its children Gohmas.
 * Plays an animation then goes to usual floor behavior, with refilled patience.
 */
void BossGoma_FloorLand(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, pthis->currentAnimFrameCount)) {
        BossGoma_SetupFloorIdle(pthis);
        pthis->patienceTimer = 200;
    }
}

/**
 * Gohma is stunned and vulnerable. It can only be damaged during pthis action.
 */
void BossGoma_FloorStunned(BossGoma* pthis, GlobalContext* globalCtx) {
    if (pthis->sfxFaintTimer <= 90) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_FAINT - 0x800);
    }
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->timer == 1) {
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, 55.0f, 4, 8.0f, 500, 10, 1);
    }

    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 1.0f);

    if (pthis->framesUntilNextAction == 0) {
        BossGoma_SetupFloorMain(pthis);
        if (pthis->patienceTimer == 0 && pthis->actor.xzDistToPlayer < 130.0f) {
            pthis->timer = 20;
        }
    }

    Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);
    pthis->eyeState = EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES;
    Math_ApproachF(&pthis->eyeIrisScaleX, 0.4f, 0.5f, 0.2f);
    pthis->visualState = VISUALSTATE_STUNNED;
}

/**
 * Gohma goes back to the floor after the player killed the three gohmas it spawned
 */
void BossGoma_FallJump(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);
    Math_ApproachS(&pthis->actor.world.rot.y, Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor), 2,
                   0x7D0);

    if (pthis->actor.bgCheckFlags & 1) {
        BossGoma_SetupFloorLand(pthis);
        pthis->actor.velocity.y = 0.0f;
        BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 0, 8);
        func_80033E88(&pthis->actor, globalCtx, 5, 0xF);
    }
}

/**
 * Gohma falls to the floor after the player hit it
 */
void BossGoma_FallStruckDown(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);
    Math_ApproachS(&pthis->actor.world.rot.y, Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor), 3,
                   0x7D0);

    if (pthis->actor.bgCheckFlags & 1) {
        BossGoma_SetupFloorLandStruckDown(pthis);
        pthis->actor.velocity.y = 0.0f;
        BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 0, 8);
        func_80033E88(&pthis->actor, globalCtx, 0xA, 0xF);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DAM1);
    }
}

/**
 * Spawn three gohmas, one after the other. Cannot be interrupted
 */
void BossGoma_CeilingSpawnGohmas(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 i;

    SkelAnime_Update(&pthis->skelanime);

    if (pthis->frameCount % 16 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_UNARI);
    }

    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);
    pthis->spawnGohmasActionTimer++;

    switch (pthis->spawnGohmasActionTimer) {
        case 24:
            // BOSSGOMA_LIMB_TAIL1, the tail limb closest to the body
            pthis->tailLimbsScaleTimers[3] = 10;
            break;
        case 32:
            // BOSSGOMA_LIMB_TAIL2
            pthis->tailLimbsScaleTimers[2] = 10;
            break;
        case 40:
            // BOSSGOMA_LIMB_TAIL3
            pthis->tailLimbsScaleTimers[1] = 10;
            break;
        case 48:
            // BOSSGOMA_LIMB_TAIL4, the furthest from the body
            pthis->tailLimbsScaleTimers[0] = 10;
            break;
    }

    if (pthis->tailLimbsScaleTimers[0] == 2) {
        for (i = 0; i < ARRAY_COUNT(pthis->childrenGohmaState); i++) {
            if (pthis->childrenGohmaState[i] == 0) {
                BossGoma_SpawnChildGohma(pthis, globalCtx, i);
                break;
            }
        }

        if (pthis->childrenGohmaState[0] == 0 || pthis->childrenGohmaState[1] == 0 || pthis->childrenGohmaState[2] == 0) {
            pthis->spawnGohmasActionTimer = 23;
        }
    }

    if (pthis->spawnGohmasActionTimer >= 64) {
        BossGoma_SetupCeilingIdle(pthis);
    }

    pthis->eyeState = EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES;
}

/**
 * Prepare to spawn children gohmas, red eye for 70 frames
 * During pthis time, the player can interrupt by hitting Gohma and make it fall from the ceiling
 */
void BossGoma_CeilingPrepareSpawnGohmas(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->framesUntilNextAction == 0) {
        BossGoma_SetupCeilingSpawnGohmas(pthis);
    }

    pthis->eyeState = EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES;
    pthis->visualState = VISUALSTATE_RED;
}

/**
 * On the floor, not doing anything special.
 */
void BossGoma_FloorIdle(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);
    Math_ApproachS(&pthis->actor.shape.rot.x, 0, 2, 0xBB8);

    if (pthis->framesUntilNextAction == 0) {
        BossGoma_SetupFloorMain(pthis);
    }
}

/**
 * On the ceiling, not doing anything special.
 * Eventually spawns children gohmas, jumping down to the floor when they are killed, or staying on the ceiling as long
 * as any is still alive.
 */
void BossGoma_CeilingIdle(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 i;

    SkelAnime_Update(&pthis->skelanime);
    Math_ApproachZeroF(&pthis->actor.speedXZ, 0.5f, 2.0f);

    if (pthis->framesUntilNextAction == 0) {
        if (pthis->childrenGohmaState[0] == 0 && pthis->childrenGohmaState[1] == 0 && pthis->childrenGohmaState[2] == 0) {
            // if no child gohma has been spawned
            BossGoma_SetupCeilingPrepareSpawnGohmas(pthis);
        } else if (pthis->childrenGohmaState[0] < 0 && pthis->childrenGohmaState[1] < 0 &&
                   pthis->childrenGohmaState[2] < 0) {
            // if all children gohmas are dead
            BossGoma_SetupFallJump(pthis);
        } else {
            for (i = 0; i < ARRAY_COUNT(pthis->childrenGohmaState); i++) {
                if (pthis->childrenGohmaState[i] == 0) {
                    // if any child gohma hasn't been spawned
                    // pthis seems unreachable since BossGoma_CeilingSpawnGohmas spawns all three and can't be
                    // interrupted
                    BossGoma_SetupCeilingSpawnGohmas(pthis);
                    return;
                }
            }
            // if all children gohmas have been spawned
            BossGoma_SetupCeilingMoveToCenter(pthis);
        }
    }
}

/**
 * Gohma approaches the player as long as it has patience (see patienceTimer), then moves away from the player
 * Gohma climbs any wall it collides with
 * Uses the "walk cautiously" animation
 */
void BossGoma_FloorMain(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 rot;

    SkelAnime_Update(&pthis->skelanime);

    if (Animation_OnFrame(&pthis->skelanime, 1.0f)) {
        pthis->doNotMoveThisFrame = true;
    } else if (Animation_OnFrame(&pthis->skelanime, 30.0f)) {
        pthis->doNotMoveThisFrame = true;
    } else if (Animation_OnFrame(&pthis->skelanime, 15.0f)) {
        pthis->doNotMoveThisFrame = true;
    } else if (Animation_OnFrame(&pthis->skelanime, 16.0f)) {
        pthis->doNotMoveThisFrame = true;
    }

    if (Animation_OnFrame(&pthis->skelanime, 15.0f)) {
        BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 1, 3);
    } else if (Animation_OnFrame(&pthis->skelanime, 30.0f)) {
        BossGoma_PlayEffectsAndSfx(pthis, globalCtx, 2, 3);
    }

    if (pthis->frameCount % 64 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_CRY2);
    }

    if (!pthis->doNotMoveThisFrame) {
        rot = Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor);

        if (pthis->patienceTimer != 0) {
            pthis->patienceTimer--;

            if (pthis->actor.xzDistToPlayer < 150.0f) {
                BossGoma_SetupFloorAttackPosture(pthis);
            }

            Math_ApproachF(&pthis->actor.speedXZ, 10.0f / 3.0f, 0.5f, 2.0f);
            Math_ApproachS(&pthis->actor.world.rot.y, rot, 5, 0x3E8);
        } else {
            if (pthis->timer != 0) {
                // move away from the player, walking backwards
                Math_ApproachF(&pthis->actor.speedXZ, -10.0f, 0.5f, 2.0f);
                pthis->skelanime.playSpeed = -3.0f;
                if (pthis->timer == 1) {
                    pthis->actor.speedXZ = 0.0f;
                }
            } else {
                // move away from the player, walking forwards
                Math_ApproachF(&pthis->actor.speedXZ, 20.0f / 3.0f, 0.5f, 2.0f);
                pthis->skelanime.playSpeed = 2.0f;
                rot += 0x8000;
            }

            Math_ApproachS(&pthis->actor.world.rot.y, rot, 3, 0x9C4);
        }
    }

    if (pthis->actor.bgCheckFlags & 1) {
        pthis->actor.velocity.y = 0.0f;
    }

    if (pthis->actor.bgCheckFlags & 8) {
        BossGoma_SetupWallClimb(pthis);
    }

    if (pthis->framesUntilNextAction == 0 && pthis->patienceTimer != 0) {
        BossGoma_SetupFloorIdle(pthis);
    }
}

/**
 * Gohma moves up until it reaches the ceiling
 */
void BossGoma_WallClimb(BossGoma* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelanime);

    if (pthis->frameCount % 8 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_CLIM);
    }

    Math_ApproachF(&pthis->actor.velocity.y, 5.0f, 0.5f, 2.0f);
    Math_ApproachS(&pthis->actor.shape.rot.x, -0x4000, 2, 0x7D0);
    Math_ApproachS(&pthis->actor.world.rot.y, pthis->actor.wallYaw + 0x8000, 2, 0x5DC);

    // -320 is a bit below boss room ceiling
    if (pthis->actor.world.pos.y > -320.0f) {
        BossGoma_SetupCeilingMoveToCenter(pthis);
        // allow new spawns
        pthis->childrenGohmaState[0] = pthis->childrenGohmaState[1] = pthis->childrenGohmaState[2] = 0;
    }
}

/**
 * Goes to BossGoma_CeilingIdle after enough time and after being close enough to the center of the ceiling.
 */
void BossGoma_CeilingMoveToCenter(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 angle;
    s16 absDiff;

    BossGoma_UpdateCeilingMovement(pthis, globalCtx, 0.0f, -5.0f, true);

    if (pthis->frameCount % 64 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_CRY2);
    }

    Math_ApproachS(&pthis->actor.shape.rot.x, -0x8000, 3, 0x3E8);

    // avoid walking into a wall?
    if (pthis->actor.bgCheckFlags & 8) {
        angle = pthis->actor.shape.rot.y + 0x8000;

        if (angle < pthis->actor.wallYaw) {
            absDiff = pthis->actor.wallYaw - angle;
            angle = angle + absDiff / 2;
        } else {
            absDiff = angle - pthis->actor.wallYaw;
            angle = pthis->actor.wallYaw + absDiff / 2;
        }

        pthis->actor.world.pos.z += Math_CosS(angle) * (5.0f + Rand_ZeroOne() * 5.0f) + Rand_CenteredFloat(2.0f);
        pthis->actor.world.pos.x += Math_SinS(angle) * (5.0f + Rand_ZeroOne() * 5.0f) + Rand_CenteredFloat(2.0f);
    }

    // timer setup to 30-60
    if (pthis->framesUntilNextAction == 0 && fabsf(-150.0f - pthis->actor.world.pos.x) < 100.0f &&
        fabsf(-350.0f - pthis->actor.world.pos.z) < 100.0f) {
        BossGoma_SetupCeilingIdle(pthis);
    }
}

/**
 * Update eye-related properties
 *  - open/close (eye lid rotation)
 *  - look at the player (iris rotation)
 *  - iris scale, when menacing or damaged
 */
void BossGoma_UpdateEye(BossGoma* pthis, GlobalContext* globalCtx) {
    s16 targetEyeIrisRotX;
    s16 targetEyeIrisRotY;

    if (!pthis->disableGameplayLogic) {
        Player* player = GET_PLAYER(globalCtx);

        if (pthis->eyeState == EYESTATE_IRIS_FOLLOW_BONUS_IFRAMES) {
            // player + 0xA73 seems to be related to "throwing something"
            if (player->unk_A73 != 0) {
                player->unk_A73 = 0;
                pthis->eyeClosedTimer = 12;
            }

            if (pthis->frameCount % 16 == 0 && Rand_ZeroOne() < 0.3f) {
                pthis->eyeClosedTimer = 7;
            }
        }

        if (pthis->childrenGohmaState[0] > 0 || pthis->childrenGohmaState[1] > 0 || pthis->childrenGohmaState[2] > 0) {
            pthis->eyeClosedTimer = 7;
        }

        if (pthis->eyeClosedTimer != 0) {
            pthis->eyeClosedTimer--;
            // close eye
            Math_ApproachS(&pthis->eyeLidBottomRotX, -0xA98, 1, 0x7D0);
            Math_ApproachS(&pthis->eyeLidTopRotX, 0x1600, 1, 0x7D0);
        } else {
            // open eye
            Math_ApproachS(&pthis->eyeLidBottomRotX, 0, 1, 0x7D0);
            Math_ApproachS(&pthis->eyeLidTopRotX, 0, 1, 0x7D0);
        }

        if (pthis->eyeState != EYESTATE_IRIS_NO_FOLLOW_NO_IFRAMES) {
            targetEyeIrisRotY =
                Actor_WorldYawTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.shape.rot.y;
            targetEyeIrisRotX =
                Actor_WorldPitchTowardActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) - pthis->actor.shape.rot.x;

            if (pthis->actor.shape.rot.x > 0x4000 || pthis->actor.shape.rot.x < -0x4000) {
                targetEyeIrisRotY = -(s16)(targetEyeIrisRotY + 0x8000);
                targetEyeIrisRotX = -0xBB8;
            }

            if (targetEyeIrisRotY > 0x1770) {
                targetEyeIrisRotY = 0x1770;
            }

            if (targetEyeIrisRotY < -0x1770) {
                targetEyeIrisRotY = -0x1770;
            }

            Math_ApproachS(&pthis->eyeIrisRotY, targetEyeIrisRotY, 3, 0x7D0);
            Math_ApproachS(&pthis->eyeIrisRotX, targetEyeIrisRotX, 3, 0x7D0);
        } else {
            Math_ApproachS(&pthis->eyeIrisRotY, 0, 3, 0x3E8);
            Math_ApproachS(&pthis->eyeIrisRotX, 0, 3, 0x3E8);
        }

        Math_ApproachF(&pthis->eyeIrisScaleX, 1.0f, 0.2f, 0.07f);
        Math_ApproachF(&pthis->eyeIrisScaleY, 1.0f, 0.2f, 0.07f);
    }
}

/**
 * Part of achieving visual effects when spawning children gohmas,
 * inflating each tail limb one after the other.
 */
void BossGoma_UpdateTailLimbsScale(BossGoma* pthis) {
    s16 i;

    if (pthis->frameCount % 128 == 0) {
        pthis->unusedTimer++;
        if (pthis->unusedTimer >= 3) {
            pthis->unusedTimer = 0;
        }
    }

    // See BossGoma_CeilingSpawnGohmas for `tailLimbsScaleTimers` usage
    for (i = 0; i < ARRAY_COUNT(pthis->tailLimbsScaleTimers); i++) {
        if (pthis->tailLimbsScaleTimers[i] != 0) {
            pthis->tailLimbsScaleTimers[i]--;
            Math_ApproachF(&pthis->tailLimbsScale[i], 1.5f, 0.2f, 0.1f);
        } else {
            Math_ApproachF(&pthis->tailLimbsScale[i], 1.0f, 0.2f, 0.1f);
        }
    }
}

void BossGoma_UpdateHit(BossGoma* pthis, GlobalContext* globalCtx) {
    if (pthis->invincibilityFrames != 0) {
        pthis->invincibilityFrames--;
    } else {
        ColliderInfo* acHitInfo = pthis->collider.elements[0].info.acHitInfo;
        s32 damage;

        if (pthis->eyeClosedTimer == 0 && pthis->actionFunc != BossGoma_CeilingSpawnGohmas &&
            (pthis->collider.elements[0].info.bumperFlags & BUMP_HIT)) {
            pthis->collider.elements[0].info.bumperFlags &= ~BUMP_HIT;

            if (pthis->actionFunc == BossGoma_CeilingMoveToCenter || pthis->actionFunc == BossGoma_CeilingIdle ||
                pthis->actionFunc == BossGoma_CeilingPrepareSpawnGohmas) {
                BossGoma_SetupFallStruckDown(pthis);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DAM2);
            } else if (pthis->actionFunc == BossGoma_FloorStunned &&
                       (damage = CollisionCheck_GetSwordDamage(acHitInfo->toucher.dmgFlags)) != 0) {
                pthis->actor.colChkInfo.health -= damage;

                if ((s8)pthis->actor.colChkInfo.health > 0) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DAM1);
                    BossGoma_SetupFloorDamaged(pthis);
                    EffectSsSibuki_SpawnBurst(globalCtx, &pthis->actor.focus.pos);
                } else {
                    BossGoma_SetupDefeated(pthis, globalCtx);
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                }

                pthis->invincibilityFrames = 10;
            } else if (pthis->actionFunc != BossGoma_FloorStunned && pthis->patienceTimer != 0 &&
                       (acHitInfo->toucher.dmgFlags & 0x00000005)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_DAM2);
                Audio_StopSfxById(NA_SE_EN_GOMA_CRY1);
                pthis->invincibilityFrames = 10;
                BossGoma_SetupFloorStunned(pthis);
                pthis->sfxFaintTimer = 100;

                if (acHitInfo->toucher.dmgFlags & 1) {
                    pthis->framesUntilNextAction = 40;
                } else {
                    pthis->framesUntilNextAction = 90;
                }

                pthis->timer = 4;
                func_80033E88(&pthis->actor, globalCtx, 4, 0xC);
            }
        }
    }
}

void BossGoma_UpdateMainEnvColor(BossGoma* pthis) {
    static f32 colors1[][3] = {
        { 255.0f, 17.0f, 0.0f },  { 0.0f, 255.0f, 170.0f }, { 50.0f, 50.0f, 50.0f },
        { 0.0f, 255.0f, 170.0f }, { 0.0f, 255.0f, 170.0f }, { 0.0f, 255.0f, 170.0f },
    };
    static f32 colors2[][3] = {
        { 255.0f, 17.0f, 0.0f },  { 0.0f, 255.0f, 170.0f }, { 50.0f, 50.0f, 50.0f },
        { 0.0f, 255.0f, 170.0f }, { 0.0f, 0.0f, 255.0f },   { 255.0f, 17.0f, 0.0f },
    };

    if (pthis->visualState == VISUALSTATE_DEFAULT && pthis->frameCount & 0x10) {
        Math_ApproachF(&pthis->mainEnvColor[0], 50.0f, 0.5f, 20.0f);
        Math_ApproachF(&pthis->mainEnvColor[1], 50.0f, 0.5f, 20.0f);
        Math_ApproachF(&pthis->mainEnvColor[2], 50.0f, 0.5f, 20.0f);
    } else if (pthis->invincibilityFrames != 0) {
        if (pthis->invincibilityFrames & 2) {
            pthis->mainEnvColor[0] = colors2[pthis->visualState][0];
            pthis->mainEnvColor[1] = colors2[pthis->visualState][1];
            pthis->mainEnvColor[2] = colors2[pthis->visualState][2];
        } else {
            pthis->mainEnvColor[0] = colors1[pthis->visualState][0];
            pthis->mainEnvColor[1] = colors1[pthis->visualState][1];
            pthis->mainEnvColor[2] = colors1[pthis->visualState][2];
        }
    } else {
        Math_ApproachF(&pthis->mainEnvColor[0], colors1[pthis->visualState][0], 0.5f, 20.0f);
        Math_ApproachF(&pthis->mainEnvColor[1], colors1[pthis->visualState][1], 0.5f, 20.0f);
        Math_ApproachF(&pthis->mainEnvColor[2], colors1[pthis->visualState][2], 0.5f, 20.0f);
    }
}

void BossGoma_UpdateEyeEnvColor(BossGoma* pthis) {
    static f32 targetEyeEnvColors[][3] = {
        { 255.0f, 17.0f, 0.0f },  { 255.0f, 255.0f, 255.0f }, { 50.0f, 50.0f, 50.0f },
        { 0.0f, 255.0f, 170.0f }, { 0.0f, 255.0f, 170.0f },   { 0.0f, 255.0f, 170.0f },
    };

    Math_ApproachF(&pthis->eyeEnvColor[0], targetEyeEnvColors[pthis->visualState][0], 0.5f, 20.0f);
    Math_ApproachF(&pthis->eyeEnvColor[1], targetEyeEnvColors[pthis->visualState][1], 0.5f, 20.0f);
    Math_ApproachF(&pthis->eyeEnvColor[2], targetEyeEnvColors[pthis->visualState][2], 0.5f, 20.0f);
}

void BossGoma_Update(Actor* thisx, GlobalContext* globalCtx) {
    BossGoma* pthis = (BossGoma*)thisx;
    s32 pad;

    pthis->visualState = VISUALSTATE_DEFAULT;
    pthis->frameCount++;

    if (pthis->framesUntilNextAction != 0) {
        pthis->framesUntilNextAction--;
    }

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->sfxFaintTimer != 0) {
        pthis->sfxFaintTimer--;
    }

    if (1) {}

    pthis->eyeState = EYESTATE_IRIS_FOLLOW_BONUS_IFRAMES;
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (!pthis->doNotMoveThisFrame) {
        Actor_MoveForward(&pthis->actor);
    } else {
        pthis->doNotMoveThisFrame = false;
    }

    if (pthis->actor.world.pos.y < -400.0f) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 30.0f, 80.0f, 5);
    } else {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 30.0f, 80.0f, 1);
    }

    BossGoma_UpdateEye(pthis, globalCtx);
    BossGoma_UpdateMainEnvColor(pthis);
    BossGoma_UpdateEyeEnvColor(pthis);
    BossGoma_UpdateTailLimbsScale(pthis);

    if (!pthis->disableGameplayLogic) {
        BossGoma_UpdateHit(pthis, globalCtx);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

        if (pthis->actionFunc != BossGoma_FloorStunned && pthis->actionFunc != BossGoma_FloorDamaged &&
            (pthis->actionFunc != BossGoma_FloorMain || pthis->timer == 0)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

s32 BossGoma_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                              void* thisx) {
    BossGoma* pthis = (BossGoma*)thisx;
    s32 doNotDrawLimb = false;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_goma.c", 4685);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, (s16)pthis->mainEnvColor[0], (s16)pthis->mainEnvColor[1], (s16)pthis->mainEnvColor[2],
                   255);

    if (pthis->deadLimbsState[limbIndex] >= 2) {
        *dList = NULL;
    }

    switch (limbIndex) {
        case BOSSGOMA_LIMB_EYE:
            if (pthis->eyeState == EYESTATE_IRIS_FOLLOW_BONUS_IFRAMES && pthis->eyeLidBottomRotX < -0xA8C) {
                *dList = NULL;
            } else if (pthis->invincibilityFrames != 0) {
                gDPSetEnvColor(POLY_OPA_DISP++, (s16)(Rand_ZeroOne() * 255.0f), (s16)(Rand_ZeroOne() * 255.0f),
                               (s16)(Rand_ZeroOne() * 255.0f), 63);
            } else {
                gDPSetEnvColor(POLY_OPA_DISP++, (s16)pthis->eyeEnvColor[0], (s16)pthis->eyeEnvColor[1],
                               (s16)pthis->eyeEnvColor[2], 63);
            }
            break;

        case BOSSGOMA_LIMB_EYE_LID_BOTTOM_ROOT2:
            rot->x += pthis->eyeLidBottomRotX;
            break;

        case BOSSGOMA_LIMB_EYE_LID_TOP_ROOT2:
            rot->x += pthis->eyeLidTopRotX;
            break;

        case BOSSGOMA_LIMB_IRIS_ROOT2:
            rot->x += pthis->eyeIrisRotX;
            rot->y += pthis->eyeIrisRotY;
            break;

        case BOSSGOMA_LIMB_IRIS:
            if (pthis->eyeState == EYESTATE_IRIS_FOLLOW_BONUS_IFRAMES && pthis->eyeLidBottomRotX < -0xA8C) {
                *dList = NULL;
            } else {
                if (pthis->visualState == VISUALSTATE_DEFEATED) {
                    gDPSetEnvColor(POLY_OPA_DISP++, 50, 50, 50, 255);
                } else {
                    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
                }

                Matrix_TranslateRotateZYX(pos, rot);

                if (*dList != NULL) {
                    Matrix_Push();
                    Matrix_Scale(pthis->eyeIrisScaleX, pthis->eyeIrisScaleY, 1.0f, MTXMODE_APPLY);
                    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_goma.c", 4815),
                              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(POLY_OPA_DISP++, *dList);
                    Matrix_Pop();
                }

                doNotDrawLimb = true;
            }
            break;

        case BOSSGOMA_LIMB_TAIL4:
        case BOSSGOMA_LIMB_TAIL3:
        case BOSSGOMA_LIMB_TAIL2:
        case BOSSGOMA_LIMB_TAIL1:
            Matrix_TranslateRotateZYX(pos, rot);

            if (*dList != NULL) {
                Matrix_Push();
                Matrix_Scale(pthis->tailLimbsScale[limbIndex - BOSSGOMA_LIMB_TAIL4],
                             pthis->tailLimbsScale[limbIndex - BOSSGOMA_LIMB_TAIL4],
                             pthis->tailLimbsScale[limbIndex - BOSSGOMA_LIMB_TAIL4], MTXMODE_APPLY);
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_goma.c", 4836),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, *dList);
                Matrix_Pop();
            }

            doNotDrawLimb = true;
            break;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_goma.c", 4858);

    return doNotDrawLimb;
}

void BossGoma_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f tailZero = { 0.0f, 0.0f, 0.0f };
    static Vec3f clawBackLocalPos = { 0.0f, 0.0f, 0.0f };
    static Vec3f focusEyeLocalPos = { 0.0f, 300.0f, 2650.0f }; // in the center of the surface of the lens
    static Vec3f zero = { 0.0f, 0.0f, 0.0f };
    Vec3f childPos;
    Vec3s childRot;
    EnGoma* babyGohma;
    BossGoma* pthis = (BossGoma*)thisx;
    s32 pad;
    MtxF mtx;

    if (limbIndex == BOSSGOMA_LIMB_TAIL4) { // tail end/last part
        Matrix_MultVec3f(&tailZero, &pthis->lastTailLimbWorldPos);
    } else if (limbIndex == BOSSGOMA_LIMB_TAIL1) { // tail start/first part
        Matrix_MultVec3f(&tailZero, &pthis->firstTailLimbWorldPos);
    } else if (limbIndex == BOSSGOMA_LIMB_EYE) {
        Matrix_MultVec3f(&focusEyeLocalPos, &pthis->actor.focus.pos);
    } else if (limbIndex == BOSSGOMA_LIMB_R_FEET_BACK) {
        Matrix_MultVec3f(&clawBackLocalPos, &pthis->rightHandBackLimbWorldPos);
    } else if (limbIndex == BOSSGOMA_LIMB_L_FEET_BACK) {
        Matrix_MultVec3f(&clawBackLocalPos, &pthis->leftHandBackLimbWorldPos);
    }

    if (pthis->visualState == VISUALSTATE_DEFEATED) {
        if (*dList != NULL) {
            Matrix_MultVec3f(&clawBackLocalPos, &pthis->defeatedLimbPositions[limbIndex]);
        } else {
            pthis->defeatedLimbPositions[limbIndex].y = 10000.0f;
        }
    }

    if (pthis->deadLimbsState[limbIndex] == 1) {
        pthis->deadLimbsState[limbIndex] = 2;
        Matrix_MultVec3f(&zero, &childPos);
        Matrix_Get(&mtx);
        Matrix_MtxFToYXZRotS(&mtx, &childRot, 0);
        // These are the pieces of Gohma as it falls apart. It appears to use the same actor as the baby gohmas.
        babyGohma = (EnGoma*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_GOMA,
                                                childPos.x, childPos.y, childPos.z, childRot.x, childRot.y, childRot.z,
                                                sDeadLimbLifetime[limbIndex] + 100);
        if (babyGohma != NULL) {
            babyGohma->bossLimbDl = *dList;
            babyGohma->actor.objBankIndex = pthis->actor.objBankIndex;
        }
    }

    Collider_UpdateSpheres(limbIndex, &pthis->collider);
}

Gfx* BossGoma_EmptyDlist(GraphicsContext* gfxCtx) {
    Gfx* dListHead;
    Gfx* dList;

    dList = dListHead = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 1);

    gSPEndDisplayList(dListHead++);

    return dList;
}

Gfx* BossGoma_NoBackfaceCullingDlist(GraphicsContext* gfxCtx) {
    Gfx* dListHead;
    Gfx* dList;

    dList = dListHead = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 4);

    gDPPipeSync(dListHead++);
    gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2);
    gSPClearGeometryMode(dListHead++, G_CULL_BACK);
    gSPEndDisplayList(dListHead++);

    return dList;
}

void BossGoma_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BossGoma* pthis = (BossGoma*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_goma.c", 4991);

    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_Translate(0.0f, -4000.0f, 0.0f, MTXMODE_APPLY);

    if (pthis->noBackfaceCulling) {
        gSPSegment(POLY_OPA_DISP++, 0x08, BossGoma_NoBackfaceCullingDlist(globalCtx->state.gfxCtx));
    } else {
        gSPSegment(POLY_OPA_DISP++, 0x08, BossGoma_EmptyDlist(globalCtx->state.gfxCtx));
    }

    SkelAnime_DrawOpa(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, BossGoma_OverrideLimbDraw,
                      BossGoma_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_goma.c", 5012);
}

void BossGoma_SpawnChildGohma(BossGoma* pthis, GlobalContext* globalCtx, s16 i) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_GOMA, pthis->lastTailLimbWorldPos.x,
                       pthis->lastTailLimbWorldPos.y - 50.0f, pthis->lastTailLimbWorldPos.z, 0, i * (0x10000 / 3), 0, i);

    pthis->childrenGohmaState[i] = 1;
}

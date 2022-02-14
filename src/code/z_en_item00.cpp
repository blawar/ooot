#define INTERNAL_SRC_CODE_Z_EN_ITEM00_C
#include "global.h"
#include "z64global.h"
#include "ichain.h"
#include "z64player.h"
#include "z64item.h"
#include "z64save.h"
#include "sfx.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "overlays/effects/ovl_Effect_Ss_Dead_Sound/z_eff_ss_dead_sound.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_draw.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/graph.h" // FORCE

#define FLAGS 0

void EnItem00_Init(Actor* pthisx, GlobalContext* globalCtx);
void EnItem00_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void EnItem00_Update(Actor* pthisx, GlobalContext* globalCtx);
void EnItem00_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_8001DFC8(EnItem00* pthis, GlobalContext* globalCtx);
void func_8001E1C8(EnItem00* pthis, GlobalContext* globalCtx);
void func_8001E304(EnItem00* pthis, GlobalContext* globalCtx);
void func_8001E5C8(EnItem00* pthis, GlobalContext* globalCtx);

void EnItem00_DrawRupee(EnItem00* pthis, GlobalContext* globalCtx);
void EnItem00_DrawCollectible(EnItem00* pthis, GlobalContext* globalCtx);
void EnItem00_DrawHeartContainer(EnItem00* pthis, GlobalContext* globalCtx);
void EnItem00_DrawHeartPiece(EnItem00* pthis, GlobalContext* globalCtx);

ActorInit En_Item00_InitVars = {
    ACTOR_EN_ITEM00,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnItem00),
    (ActorFunc)EnItem00_Init,
    (ActorFunc)EnItem00_Destroy,
    (ActorFunc)EnItem00_Update,
    (ActorFunc)EnItem00_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000010, 0x00, 0x00 },
        TOUCH_NONE | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 10, 30, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_STOP),
};

static Color_RGBA8 sEffectPrimColor = { 255, 255, 127, 0 };
static Color_RGBA8 sEffectEnvColor = { 255, 255, 255, 0 };
static Vec3f sEffectVelocity = { 0.0f, 0.1f, 0.0f };
static Vec3f sEffectAccel = { 0.0f, 0.01f, 0.0f };

static void* sRupeeTex[] = {
    gRupeeGreenTex, gRupeeBlueTex, gRupeeRedTex, gRupeePinkTex, gRupeeOrangeTex,
};

static void* sItemDropTex[] = {
    gDropRecoveryHeartTex, gDropBombTex,       gDropArrows1Tex,   gDropArrows2Tex,
    gDropArrows3Tex,       gDropBombTex,       gDropDekuNutTex,   gDropDekuStickTex,
    gDropMagicLargeTex,    gDropMagicSmallTex, gDropDekuSeedsTex, gDropKeySmallTex,
};

static u8 sItemDropIds[] = {
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_BLUE,
    0xFF,
    0xFF,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_GREEN,
    ITEM00_MAGIC_SMALL,
    ITEM00_HEART,
    ITEM00_HEART,
    0xFF,
    ITEM00_MAGIC_SMALL,
    ITEM00_FLEXIBLE,
    ITEM00_SEEDS,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_GREEN,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_BLUE,
    ITEM00_HEART,
    0xFF,
    ITEM00_HEART,
    0xFF,
    ITEM00_FLEXIBLE,
    0xFF,
    ITEM00_BOMBS_A,
    0xFF,
    ITEM00_SEEDS,
    0xFF,
    0xFF,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_GREEN,
    ITEM00_MAGIC_SMALL,
    0xFF,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_HEART,
    0xFF,
    ITEM00_SEEDS,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_BOMBS_A,
    0xFF,
    ITEM00_FLEXIBLE,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_GREEN,
    ITEM00_NUTS,
    0xFF,
    ITEM00_SEEDS,
    ITEM00_SEEDS,
    ITEM00_NUTS,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_FLEXIBLE,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_GREEN,
    ITEM00_SEEDS,
    ITEM00_BOMBS_A,
    ITEM00_MAGIC_SMALL,
    ITEM00_BOMBS_A,
    0xFF,
    0xFF,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_HEART,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    0xFF,
    ITEM00_RUPEE_BLUE,
    0xFF,
    0xFF,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_HEART,
    ITEM00_FLEXIBLE,
    ITEM00_SEEDS,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_MAGIC_SMALL,
    ITEM00_RUPEE_GREEN,
    ITEM00_RUPEE_BLUE,
    0xFF,
    ITEM00_RUPEE_GREEN,
    0xFF,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_BOMBS_A,
    ITEM00_ARROWS_SMALL,
    0xFF,
    ITEM00_ARROWS_MEDIUM,
    ITEM00_MAGIC_SMALL,
    ITEM00_FLEXIBLE,
    0xFF,
    ITEM00_MAGIC_LARGE,
    ITEM00_RUPEE_GREEN,
    0xFF,
    ITEM00_RUPEE_BLUE,
    0xFF,
    ITEM00_RUPEE_GREEN,
    ITEM00_HEART,
    ITEM00_FLEXIBLE,
    ITEM00_BOMBS_A,
    ITEM00_ARROWS_SMALL,
    0xFF,
    0xFF,
    0xFF,
    ITEM00_MAGIC_SMALL,
    0xFF,
    0xFF,
    ITEM00_MAGIC_LARGE,
    ITEM00_ARROWS_LARGE,
    ITEM00_ARROWS_MEDIUM,
    ITEM00_ARROWS_MEDIUM,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_SMALL,
    ITEM00_FLEXIBLE,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_MEDIUM,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_SMALL,
    ITEM00_ARROWS_MEDIUM,
    ITEM00_ARROWS_LARGE,
    ITEM00_ARROWS_LARGE,
    ITEM00_MAGIC_LARGE,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_LARGE,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_LARGE,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_LARGE,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_SMALL,
    ITEM00_MAGIC_LARGE,
    ITEM00_BOMBS_A,
    0xFF,
    ITEM00_BOMBS_A,
    0xFF,
    ITEM00_BOMBS_A,
    ITEM00_FLEXIBLE,
    ITEM00_BOMBS_A,
    ITEM00_BOMBS_A,
    ITEM00_BOMBS_A,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    ITEM00_BOMBS_A,
    0xFF,
    ITEM00_BOMBS_A,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_HEART,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_BLUE,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_RED,
    ITEM00_RUPEE_RED,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_NUTS,
    0xFF,
    ITEM00_STICK,
    0xFF,
    0xFF,
    ITEM00_SEEDS,
    0xFF,
    0xFF,
    0xFF,
    ITEM00_NUTS,
    0xFF,
    ITEM00_NUTS,
    ITEM00_HEART,
    ITEM00_SEEDS,
    ITEM00_HEART,
    0xFF,
    ITEM00_SEEDS,
    0xFF,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_HEART,
    ITEM00_HEART,
    0xFF,
    0xFF,
    ITEM00_HEART,
    0xFF,
    ITEM00_HEART,
    ITEM00_SEEDS,
    ITEM00_FLEXIBLE,
};

static u8 sDropQuantities[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 1, 3, 1, 3, 1, 1, 1, 3, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0,
};

void EnItem00_SetupAction(EnItem00* pthis, EnItem00ActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnItem00_Init(Actor* pthisx, GlobalContext* globalCtx) {
    EnItem00* pthis = (EnItem00*)pthisx;
    s32 pad;
    f32 yOffset = 980.0f;
    f32 shadowScale = 6.0f;
    s32 getItemId = GI_NONE;
    s16 spawnParam8000 = pthis->actor.params & 0x8000;
    s32 pad1;

    pthis->collectibleFlag = (pthis->actor.params & 0x3F00) >> 8;

    pthis->actor.params &= 0xFF;

    if (Flags_GetCollectible(globalCtx, pthis->collectibleFlag)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

    pthis->unk_158 = 1;

    switch (pthis->actor.params) {
        case ITEM00_RUPEE_GREEN:
        case ITEM00_RUPEE_BLUE:
        case ITEM00_RUPEE_RED:
            Actor_SetScale(&pthis->actor, 0.015f);
            pthis->scale = 0.015f;
            yOffset = 750.0f;
            break;
        case ITEM00_SMALL_KEY:
            pthis->unk_158 = 0;
            Actor_SetScale(&pthis->actor, 0.03f);
            pthis->scale = 0.03f;
            yOffset = 350.0f;
            break;
        case ITEM00_HEART_PIECE:
            pthis->unk_158 = 0;
            yOffset = 650.0f;
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->scale = 0.02f;
            break;
        case ITEM00_HEART:
            pthis->actor.home.rot.z = Rand_CenteredFloat(65535.0f);
            yOffset = 430.0f;
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->scale = 0.02f;
            break;
        case ITEM00_HEART_CONTAINER:
            yOffset = 430.0f;
            pthis->unk_158 = 0;
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->scale = 0.02f;
            break;
        case ITEM00_ARROWS_SINGLE:
            yOffset = 400.0f;
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->scale = 0.02f;
            break;
        case ITEM00_ARROWS_SMALL:
        case ITEM00_ARROWS_MEDIUM:
        case ITEM00_ARROWS_LARGE:
            Actor_SetScale(&pthis->actor, 0.035f);
            pthis->scale = 0.035f;
            yOffset = 250.0f;
            break;
        case ITEM00_BOMBS_A:
        case ITEM00_BOMBS_B:
        case ITEM00_NUTS:
        case ITEM00_STICK:
        case ITEM00_MAGIC_SMALL:
        case ITEM00_SEEDS:
        case ITEM00_BOMBS_SPECIAL:
            Actor_SetScale(&pthis->actor, 0.03f);
            pthis->scale = 0.03f;
            yOffset = 320.0f;
            break;
        case ITEM00_MAGIC_LARGE:
            Actor_SetScale(&pthis->actor, 0.045 - 1e-10);
            pthis->scale = 0.045 - 1e-10;
            yOffset = 320.0f;
            break;
        case ITEM00_RUPEE_ORANGE:
            Actor_SetScale(&pthis->actor, 0.045 - 1e-10);
            pthis->scale = 0.045 - 1e-10;
            yOffset = 750.0f;
            break;
        case ITEM00_RUPEE_PURPLE:
            Actor_SetScale(&pthis->actor, 0.03f);
            pthis->scale = 0.03f;
            yOffset = 750.0f;
            break;
        case ITEM00_FLEXIBLE:
            yOffset = 500.0f;
            Actor_SetScale(&pthis->actor, 0.01f);
            pthis->scale = 0.01f;
            break;
        case ITEM00_SHIELD_DEKU:
            pthis->actor.objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GI_SHIELD_1);
            Actor_SetObjectDependency(globalCtx, &pthis->actor);
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->scale = 0.5f;
            yOffset = 0.0f;
            shadowScale = 0.6f;
            pthis->actor.world.rot.x = 0x4000;
            break;
        case ITEM00_SHIELD_HYLIAN:
            pthis->actor.objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GI_SHIELD_2);
            Actor_SetObjectDependency(globalCtx, &pthis->actor);
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->scale = 0.5f;
            yOffset = 0.0f;
            shadowScale = 0.6f;
            pthis->actor.world.rot.x = 0x4000;
            break;
        case ITEM00_TUNIC_ZORA:
        case ITEM00_TUNIC_GORON:
            pthis->actor.objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GI_CLOTHES);
            Actor_SetObjectDependency(globalCtx, &pthis->actor);
            Actor_SetScale(&pthis->actor, 0.5f);
            pthis->scale = 0.5f;
            yOffset = 0.0f;
            shadowScale = 0.6f;
            pthis->actor.world.rot.x = 0x4000;
            break;
    }

    pthis->unk_156 = 0;
    ActorShape_Init(&pthis->actor.shape, yOffset, ActorShadow_DrawCircle, shadowScale);
    pthis->actor.shape.shadowAlpha = 180;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->getItemId = GI_NONE;

    if (!spawnParam8000) {
        EnItem00_SetupAction(pthis, func_8001DFC8);
        pthis->unk_15A = -1;
        return;
    }

    pthis->unk_15A = 15;
    pthis->unk_154 = 35;

    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = 0.0f;

    switch (pthis->actor.params) {
        case ITEM00_RUPEE_GREEN:
            Item_Give(globalCtx, ITEM_RUPEE_GREEN);
            break;
        case ITEM00_RUPEE_BLUE:
            Item_Give(globalCtx, ITEM_RUPEE_BLUE);
            break;
        case ITEM00_RUPEE_RED:
            Item_Give(globalCtx, ITEM_RUPEE_RED);
            break;
        case ITEM00_RUPEE_PURPLE:
            Item_Give(globalCtx, ITEM_RUPEE_PURPLE);
            break;
        case ITEM00_RUPEE_ORANGE:
            Item_Give(globalCtx, ITEM_RUPEE_GOLD);
            break;
        case ITEM00_HEART:
            Item_Give(globalCtx, ITEM_HEART);
            break;
        case ITEM00_FLEXIBLE:
            Health_ChangeBy(globalCtx, 0x70);
            break;
        case ITEM00_BOMBS_A:
        case ITEM00_BOMBS_B:
            Item_Give(globalCtx, ITEM_BOMBS_5);
            break;
        case ITEM00_ARROWS_SINGLE:
            Item_Give(globalCtx, ITEM_BOW);
            break;
        case ITEM00_ARROWS_SMALL:
            Item_Give(globalCtx, ITEM_ARROWS_SMALL);
            break;
        case ITEM00_ARROWS_MEDIUM:
            Item_Give(globalCtx, ITEM_ARROWS_MEDIUM);
            break;
        case ITEM00_ARROWS_LARGE:
            Item_Give(globalCtx, ITEM_ARROWS_LARGE);
            break;
        case ITEM00_MAGIC_LARGE:
            getItemId = GI_MAGIC_SMALL;
            break;
        case ITEM00_MAGIC_SMALL:
            getItemId = GI_MAGIC_LARGE;
            break;
        case ITEM00_SMALL_KEY:
            Item_Give(globalCtx, ITEM_KEY_SMALL);
            break;
        case ITEM00_SEEDS:
            getItemId = GI_SEEDS_5;
            break;
        case ITEM00_NUTS:
            getItemId = GI_NUTS_5;
            break;
        case ITEM00_STICK:
            getItemId = GI_STICKS_1;
            break;
        case ITEM00_HEART_PIECE:
        case ITEM00_HEART_CONTAINER:
        case ITEM00_SHIELD_DEKU:
        case ITEM00_SHIELD_HYLIAN:
        case ITEM00_TUNIC_ZORA:
        case ITEM00_TUNIC_GORON:
        case ITEM00_BOMBS_SPECIAL:
            break;
    }

    if ((getItemId != GI_NONE) && !Actor_HasParent(&pthis->actor, globalCtx)) {
        func_8002F554(&pthis->actor, globalCtx, getItemId);
    }

    EnItem00_SetupAction(pthis, func_8001E5C8);
    pthis->actionFunc(pthis, globalCtx);
}

void EnItem00_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    EnItem00* pthis = (EnItem00*)pthisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_8001DFC8(EnItem00* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.params <= ITEM00_RUPEE_RED) || ((pthis->actor.params == ITEM00_HEART) && (pthis->unk_15A < 0)) ||
        (pthis->actor.params == ITEM00_HEART_PIECE)) {
        pthis->actor.shape.rot.y += 960 * FRAMERATE_SCALER;
    } else {
        if ((pthis->actor.params >= ITEM00_SHIELD_DEKU) && (pthis->actor.params != ITEM00_BOMBS_SPECIAL)) {
            if (pthis->unk_15A == -1) {
                if (Math_SmoothStepToS(&pthis->actor.shape.rot.x, pthis->actor.world.rot.x - 0x4000, 2, 3000, 1500) ==
                    0) {
                    pthis->unk_15A = -2;
                }
            } else {
                if (Math_SmoothStepToS(&pthis->actor.shape.rot.x, -pthis->actor.world.rot.x - 0x4000, 2, 3000, 1500) ==
                    0) {
                    pthis->unk_15A = -1;
                }
            }
            Math_SmoothStepToS(&pthis->actor.world.rot.x, 0, 2, 2500, 500);
        }
    }

    if (pthis->actor.params == ITEM00_HEART_PIECE) {
        pthis->actor.shape.yOffset = Math_SinS(pthis->actor.shape.rot.y) * 150.0f + 850.0f;
    }

    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 1.0f, 0.5f, 0.0f);

    if (pthis->unk_154 == 0) {
        if ((pthis->actor.params != ITEM00_SMALL_KEY) && (pthis->actor.params != ITEM00_HEART_PIECE) &&
            (pthis->actor.params != ITEM00_HEART_CONTAINER)) {
            pthis->unk_154 = -1;
        }
    }

    if (pthis->unk_15A == 0) {
        if ((pthis->actor.params != ITEM00_SMALL_KEY) && (pthis->actor.params != ITEM00_HEART_PIECE) &&
            (pthis->actor.params != ITEM00_HEART_CONTAINER)) {
            Actor_Kill(&pthis->actor);
        }
    }

    if ((pthis->actor.gravity != 0.0f) && !(pthis->actor.bgCheckFlags & 0x0001)) {
        EnItem00_SetupAction(pthis, func_8001E1C8);
    }
}

void func_8001E1C8(EnItem00* pthis, GlobalContext* globalCtx) {
    f32 originalVelocity;
    Vec3f effectPos;

    if (pthis->actor.params <= ITEM00_RUPEE_RED) {
        pthis->actor.shape.rot.y += 960;
    }

    if (globalCtx->gameplayFrames & 1) {
        effectPos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(10.0f);
        effectPos.y = pthis->actor.world.pos.y + Rand_CenteredFloat(10.0f);
        effectPos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(10.0f);
        EffectSsKiraKira_SpawnSmall(globalCtx, &effectPos, &sEffectVelocity, &sEffectAccel, &sEffectPrimColor,
                                    &sEffectEnvColor);
    }

    if (pthis->actor.bgCheckFlags & 0x0003) {
        originalVelocity = pthis->actor.velocity.y;
        if (originalVelocity > -2.0f) {
            EnItem00_SetupAction(pthis, func_8001DFC8);
            pthis->actor.velocity.y = 0.0f;
        } else {
            pthis->actor.velocity.y = originalVelocity * -0.8f;
            pthis->actor.bgCheckFlags &= ~1;
        }
    }
}

void func_8001E304(EnItem00* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f pos;
    s32 rotOffset;

    pthis->unk_15A++;

    if (pthis->actor.params == ITEM00_HEART) {
        if (pthis->actor.velocity.y < 0.0f) {
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.gravity = -0.4f;
            if (pthis->actor.velocity.y < -1.5f) {
                pthis->actor.velocity.y = -1.5f;
            }
            pthis->actor.home.rot.z += (s16)((pthis->actor.velocity.y + 3.0f) * 1000.0f);
            pthis->actor.world.pos.x +=
                Math_CosS(pthis->actor.yawTowardsPlayer) * (-3.0f * Math_CosS(pthis->actor.home.rot.z));
            pthis->actor.world.pos.z +=
                Math_SinS(pthis->actor.yawTowardsPlayer) * (-3.0f * Math_CosS(pthis->actor.home.rot.z));
        }
    }

    if (pthis->actor.params <= ITEM00_RUPEE_RED) {
        pthis->actor.shape.rot.y += 960;
    } else if ((pthis->actor.params >= ITEM00_SHIELD_DEKU) && (pthis->actor.params != ITEM00_BOMBS_SPECIAL)) {
        pthis->actor.world.rot.x -= 700;
        pthis->actor.shape.rot.y += 400;
        pthis->actor.shape.rot.x = pthis->actor.world.rot.x - 0x4000;
    }

    if (pthis->actor.velocity.y <= 2.0f) {
        rotOffset = (u16)pthis->actor.shape.rot.z + 10000;
        if (rotOffset < 65535) {
            pthis->actor.shape.rot.z += 10000;
        } else {
            pthis->actor.shape.rot.z = -1;
        }
    }

    if (!(globalCtx->gameplayFrames & 1)) {
        pos.x = pthis->actor.world.pos.x + (Rand_ZeroOne() - 0.5f) * 10.0f;
        pos.y = pthis->actor.world.pos.y + (Rand_ZeroOne() - 0.5f) * 10.0f;
        pos.z = pthis->actor.world.pos.z + (Rand_ZeroOne() - 0.5f) * 10.0f;
        EffectSsKiraKira_SpawnSmall(globalCtx, &pos, &sEffectVelocity, &sEffectAccel, &sEffectPrimColor,
                                    &sEffectEnvColor);
    }

    if (pthis->actor.bgCheckFlags & 0x0003) {
        EnItem00_SetupAction(pthis, func_8001DFC8);
        pthis->actor.shape.rot.z = 0;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.speedXZ = 0.0f;
    }
}

void func_8001E5C8(EnItem00* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->getItemId != GI_NONE) {
        if (!Actor_HasParent(&pthis->actor, globalCtx)) {
            func_8002F434(&pthis->actor, globalCtx, pthis->getItemId, 50.0f, 80.0f);
            pthis->unk_15A++;
        } else {
            pthis->getItemId = GI_NONE;
        }
    }

    if (pthis->unk_15A == 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->actor.world.pos = player->actor.world.pos;

    if (pthis->actor.params <= ITEM00_RUPEE_RED) {
        pthis->actor.shape.rot.y += 960;
    } else if (pthis->actor.params == ITEM00_HEART) {
        pthis->actor.shape.rot.y = 0;
    }

    pthis->actor.world.pos.y += 40.0f + Math_SinS(pthis->unk_15A * 15000) * (pthis->unk_15A * 0.3f);

    if (LINK_IS_ADULT) {
        pthis->actor.world.pos.y += 20.0f;
    }
}

// The BSS in the function acted weird in the past. It is matching now but might cause issues in the future
void EnItem00_Update(Actor* pthisx, GlobalContext* globalCtx) {
    static u32 D_80157D90;
    static s16 D_80157D94[1];
    s16* params;
    Actor* dynaActor;
    s32 getItemId = GI_NONE;
    s16 sp3A = 0;
    s16 i;
    u32* temp;
    EnItem00* pthis = (EnItem00*)pthisx;
    s32 pad;

    if (pthis->unk_15A > 0) {
        pthis->unk_15A--;
    }

    if ((pthis->unk_15A > 0) && (pthis->unk_15A < 41) && (pthis->unk_154 <= 0)) {
        pthis->unk_156 = pthis->unk_15A;
    }

    pthis->actionFunc(pthis, globalCtx);
    Math_SmoothStepToF(&pthis->actor.scale.x, pthis->scale, 0.1f, pthis->scale * 0.1f, 0.0f);
    temp = &D_80157D90;

    pthis->actor.scale.z = pthis->actor.scale.x;
    pthis->actor.scale.y = pthis->actor.scale.x;

    if (pthis->actor.gravity) {
        if (pthis->actor.bgCheckFlags & 0x0003) {
            if (*temp != globalCtx->gameplayFrames) {
                D_80157D90 = globalCtx->gameplayFrames;
                D_80157D94[0] = 0;
                for (i = 0; i < 50; i++) {
                    if (globalCtx->colCtx.dyna.bgActorFlags[i] & 1) {
                        dynaActor = globalCtx->colCtx.dyna.bgActors[i].actor;
                        if ((dynaActor != NULL) && (dynaActor->update != NULL)) {
                            if ((dynaActor->world.pos.x != dynaActor->prevPos.x) ||
                                (dynaActor->world.pos.y != dynaActor->prevPos.y) ||
                                (dynaActor->world.pos.z != dynaActor->prevPos.z)) {
                                D_80157D94[0]++;
                                break;
                            }
                        }
                    }
                }
            }

        } else {
            sp3A = 1;
            Actor_MoveForward(&pthis->actor);
        }

        if (sp3A || D_80157D94[0]) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 15.0f, 15.0f, 0x1D);

            if (pthis->actor.floorHeight <= -10000.0f) {
                Actor_Kill(&pthis->actor);
                return;
            }
        }
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    if ((pthis->actor.params == ITEM00_SHIELD_DEKU) || (pthis->actor.params == ITEM00_SHIELD_HYLIAN) ||
        (pthis->actor.params == ITEM00_TUNIC_ZORA) || (pthis->actor.params == ITEM00_TUNIC_GORON)) {
        pthis->actor.shape.yOffset = Math_CosS(pthis->actor.shape.rot.x) * 37.0f;
        pthis->actor.shape.yOffset = ABS(pthis->actor.shape.yOffset);
    }

    if (pthis->unk_154 > 0) {
        return;
    }

    if (!((pthis->actor.xzDistToPlayer <= 30.0f) && (pthis->actor.yDistToPlayer >= -50.0f) &&
          (pthis->actor.yDistToPlayer <= 50.0f))) {
        if (!Actor_HasParent(&pthis->actor, globalCtx)) {
            return;
        }
    }

    if (globalCtx->gameOverCtx.state != GAMEOVER_INACTIVE) {
        return;
    }

    switch (pthis->actor.params) {
        case ITEM00_RUPEE_GREEN:
            Item_Give(globalCtx, ITEM_RUPEE_GREEN);
            break;
        case ITEM00_RUPEE_BLUE:
            Item_Give(globalCtx, ITEM_RUPEE_BLUE);
            break;
        case ITEM00_RUPEE_RED:
            Item_Give(globalCtx, ITEM_RUPEE_RED);
            break;
        case ITEM00_RUPEE_PURPLE:
            Item_Give(globalCtx, ITEM_RUPEE_PURPLE);
            break;
        case ITEM00_RUPEE_ORANGE:
            Item_Give(globalCtx, ITEM_RUPEE_GOLD);
            break;
        case ITEM00_STICK:
            getItemId = GI_STICKS_1;
            break;
        case ITEM00_NUTS:
            getItemId = GI_NUTS_5;
            break;
        case ITEM00_HEART:
            Item_Give(globalCtx, ITEM_HEART);
            break;
        case ITEM00_FLEXIBLE:
            Health_ChangeBy(globalCtx, 0x70);
            break;
        case ITEM00_BOMBS_A:
        case ITEM00_BOMBS_B:
            Item_Give(globalCtx, ITEM_BOMBS_5);
            break;
        case ITEM00_ARROWS_SINGLE:
            Item_Give(globalCtx, ITEM_BOW);
            break;
        case ITEM00_ARROWS_SMALL:
            Item_Give(globalCtx, ITEM_ARROWS_SMALL);
            break;
        case ITEM00_ARROWS_MEDIUM:
            Item_Give(globalCtx, ITEM_ARROWS_MEDIUM);
            break;
        case ITEM00_ARROWS_LARGE:
            Item_Give(globalCtx, ITEM_ARROWS_LARGE);
            break;
        case ITEM00_SEEDS:
            getItemId = GI_SEEDS_5;
            break;
        case ITEM00_SMALL_KEY:
            getItemId = GI_KEY_SMALL;
            break;
        case ITEM00_HEART_PIECE:
            getItemId = GI_HEART_PIECE;
            break;
        case ITEM00_HEART_CONTAINER:
            getItemId = GI_HEART_CONTAINER;
            break;
        case ITEM00_MAGIC_LARGE:
            getItemId = GI_MAGIC_LARGE;
            break;
        case ITEM00_MAGIC_SMALL:
            getItemId = GI_MAGIC_SMALL;
            break;
        case ITEM00_SHIELD_DEKU:
            getItemId = GI_SHIELD_DEKU;
            break;
        case ITEM00_SHIELD_HYLIAN:
            getItemId = GI_SHIELD_HYLIAN;
            break;
        case ITEM00_TUNIC_ZORA:
            getItemId = GI_TUNIC_ZORA;
            break;
        case ITEM00_TUNIC_GORON:
            getItemId = GI_TUNIC_GORON;
            break;
        case ITEM00_BOMBS_SPECIAL:
            break;
    }

    params = &pthis->actor.params;

    if ((getItemId != GI_NONE) && !Actor_HasParent(&pthis->actor, globalCtx)) {
        func_8002F554(&pthis->actor, globalCtx, getItemId);
    }

    switch (*params) {
        case ITEM00_HEART_PIECE:
        case ITEM00_HEART_CONTAINER:
        case ITEM00_SMALL_KEY:
        case ITEM00_SHIELD_DEKU:
        case ITEM00_SHIELD_HYLIAN:
        case ITEM00_TUNIC_ZORA:
        case ITEM00_TUNIC_GORON:
            if (Actor_HasParent(&pthis->actor, globalCtx)) {
                Flags_SetCollectible(globalCtx, pthis->collectibleFlag);
                Actor_Kill(&pthis->actor);
            }
            return;
    }

    if ((*params <= ITEM00_RUPEE_RED) || (*params == ITEM00_RUPEE_ORANGE)) {
        Audio_PlaySoundGeneral(NA_SE_SY_GET_RUPY, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    } else if (getItemId != GI_NONE) {
        if (Actor_HasParent(&pthis->actor, globalCtx)) {
            Flags_SetCollectible(globalCtx, pthis->collectibleFlag);
            Actor_Kill(&pthis->actor);
        }
        return;
    } else {
        Audio_PlaySoundGeneral(NA_SE_SY_GET_ITEM, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }

    Flags_SetCollectible(globalCtx, pthis->collectibleFlag);

    pthis->unk_15A = 15;
    pthis->unk_154 = 35;
    pthis->actor.shape.rot.z = 0;
    pthis->actor.speedXZ = 0;
    pthis->actor.velocity.y = 0;
    pthis->actor.gravity = 0;

    Actor_SetScale(&pthis->actor, pthis->scale);

    pthis->getItemId = GI_NONE;
    EnItem00_SetupAction(pthis, func_8001E5C8);
}

void EnItem00_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    EnItem00* pthis = (EnItem00*)pthisx;
    f32 mtxScale;

    if (!(pthis->unk_156 & pthis->unk_158)) {
        switch (pthis->actor.params) {
            case ITEM00_RUPEE_GREEN:
            case ITEM00_RUPEE_BLUE:
            case ITEM00_RUPEE_RED:
            case ITEM00_RUPEE_ORANGE:
            case ITEM00_RUPEE_PURPLE:
                EnItem00_DrawRupee(pthis, globalCtx);
                break;
            case ITEM00_HEART_PIECE:
                EnItem00_DrawHeartPiece(pthis, globalCtx);
                break;
            case ITEM00_HEART_CONTAINER:
                EnItem00_DrawHeartContainer(pthis, globalCtx);
                break;
            case ITEM00_HEART:
                if (pthis->unk_15A < 0) {
                    if (pthis->unk_15A == -1) {
                        s32 bankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GI_HEART);

                        if (Object_IsLoaded(&globalCtx->objectCtx, bankIndex)) {
                            pthis->actor.objBankIndex = bankIndex;
                            Actor_SetObjectDependency(globalCtx, &pthis->actor);
                            pthis->unk_15A = -2;
                        }
                    } else {
                        mtxScale = 16.0f;
                        Matrix_Scale(mtxScale, mtxScale, mtxScale, MTXMODE_APPLY);
                        GetItem_Draw(globalCtx, GID_HEART);
                    }
                    break;
                }
            case ITEM00_BOMBS_A:
            case ITEM00_BOMBS_B:
            case ITEM00_BOMBS_SPECIAL:
            case ITEM00_ARROWS_SINGLE:
            case ITEM00_ARROWS_SMALL:
            case ITEM00_ARROWS_MEDIUM:
            case ITEM00_ARROWS_LARGE:
            case ITEM00_NUTS:
            case ITEM00_STICK:
            case ITEM00_MAGIC_LARGE:
            case ITEM00_MAGIC_SMALL:
            case ITEM00_SEEDS:
            case ITEM00_SMALL_KEY:
                EnItem00_DrawCollectible(pthis, globalCtx);
                break;
            case ITEM00_SHIELD_DEKU:
                GetItem_Draw(globalCtx, GID_SHIELD_DEKU);
                break;
            case ITEM00_SHIELD_HYLIAN:
                GetItem_Draw(globalCtx, GID_SHIELD_HYLIAN);
                break;
            case ITEM00_TUNIC_ZORA:
                GetItem_Draw(globalCtx, GID_TUNIC_ZORA);
                break;
            case ITEM00_TUNIC_GORON:
                GetItem_Draw(globalCtx, GID_TUNIC_GORON);
                break;
            case ITEM00_FLEXIBLE:
                break;
        }
    }
}

/**
 * Draw Function used for Rupee types of En_Item00.
 */
void EnItem00_DrawRupee(EnItem00* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 texIndex;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1546);

    func_80093D18(globalCtx->state.gfxCtx);
    func_8002EBCC(&pthis->actor, globalCtx, 0);

    if (pthis->actor.params <= ITEM00_RUPEE_RED) {
        texIndex = pthis->actor.params;
    } else {
        texIndex = pthis->actor.params - 0x10;
    }

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_item00.c", 1562),
              G_MTX_MODELVIEW | G_MTX_LOAD);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sRupeeTex[texIndex]));

    gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1568);
}

/**
 * Draw Function used for most collectible types of En_Item00 (ammo, bombs, sticks, nuts, magic...).
 */
void EnItem00_DrawCollectible(EnItem00* pthis, GlobalContext* globalCtx) {
    s32 texIndex = pthis->actor.params - 3;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1594);

    POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);

    if (pthis->actor.params == ITEM00_BOMBS_SPECIAL) {
        texIndex = 1;
    } else if (pthis->actor.params >= ITEM00_ARROWS_SMALL) {
        texIndex -= 3;
    }

    POLY_OPA_DISP = func_800946E4(POLY_OPA_DISP);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sItemDropTex[texIndex]));

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_item00.c", 1607),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, gItemDropDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1611);
}

/**
 * Draw Function used for the Heart Container type of En_Item00.
 */
void EnItem00_DrawHeartContainer(EnItem00* pthis, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1623);

    func_80093D18(globalCtx->state.gfxCtx);
    func_8002EBCC(&pthis->actor, globalCtx, 0);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_item00.c", 1634),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_OPA_DISP++, gHeartPieceExteriorDL);

    func_80093D84(globalCtx->state.gfxCtx);
    func_8002ED80(&pthis->actor, globalCtx, 0);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_item00.c", 1644),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, gHeartContainerInteriorDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1647);
}

/**
 * Draw Function used for the Piece of Heart type of En_Item00.
 */
void EnItem00_DrawHeartPiece(EnItem00* pthis, GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1658);

    func_80093D84(globalCtx->state.gfxCtx);
    func_8002ED80(&pthis->actor, globalCtx, 0);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_item00.c", 1670),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(POLY_XLU_DISP++, gHeartPieceInteriorDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_item00.c", 1673);
}

/**
 * Converts a given drop type ID based on link's current age, health and owned items.
 * Returns a new drop type ID or -1 to cancel the drop.
 */
s16 func_8001F404(s16 dropId) {
    if (LINK_IS_ADULT) {
        if (dropId == ITEM00_SEEDS) {
            dropId = ITEM00_ARROWS_SMALL;
        } else if (dropId == ITEM00_STICK) {
            dropId = ITEM00_RUPEE_GREEN;
        }
    } else {
        if (dropId == ITEM00_ARROWS_SMALL || dropId == ITEM00_ARROWS_MEDIUM || dropId == ITEM00_ARROWS_LARGE) {
            dropId = ITEM00_SEEDS;
        }
    }

    // pthis is convoluted but it seems like it must be a single condition to match
    // clang-format off
    if (((dropId == ITEM00_BOMBS_A      || dropId == ITEM00_BOMBS_SPECIAL || dropId == ITEM00_BOMBS_B)      && INV_CONTENT(ITEM_BOMB) == ITEM_NONE) ||
        ((dropId == ITEM00_ARROWS_SMALL || dropId == ITEM00_ARROWS_MEDIUM || dropId == ITEM00_ARROWS_LARGE) && INV_CONTENT(ITEM_BOW) == ITEM_NONE) ||
        ((dropId == ITEM00_MAGIC_LARGE  || dropId == ITEM00_MAGIC_SMALL)                                    && gSaveContext.magicLevel == 0) ||
        ((dropId == ITEM00_SEEDS)                                                                           && INV_CONTENT(ITEM_SLINGSHOT) == ITEM_NONE)) {
        return -1;
    }
    // clang-format on

    if (dropId == ITEM00_HEART && gSaveContext.healthCapacity == gSaveContext.health) {
        return ITEM00_RUPEE_GREEN;
    }

    return dropId;
}

// External functions used by other actors to drop collectibles, which usually results in spawning an En_Item00 actor.

EnItem00* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params) {
    s32 pad[2];
    EnItem00* spawnedActor = NULL;
    s16 param4000 = params & 0x4000;
    s16 param8000 = params & 0x8000;
    s16 param3F00 = params & 0x3F00;

    params &= 0x3FFF;

    if (((params & 0x00FF) == ITEM00_FLEXIBLE) && !param4000) {
        // TODO: Prevent the cast to EnItem00 here since pthis is a different actor (En_Elf)
        spawnedActor = (EnItem00*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, spawnPos->x,
                                              spawnPos->y + 40.0f, spawnPos->z, 0, 0, 0, FAIRY_HEAL_TIMED);
        EffectSsDeadSound_SpawnStationary(globalCtx, spawnPos, NA_SE_EV_BUTTERFRY_TO_FAIRY, true,
                                          DEADSOUND_REPEAT_MODE_OFF, 40);
    } else {
        if (!param8000) {
            params = func_8001F404(params & 0x00FF);
        }

        if (params != -1) {
            spawnedActor = (EnItem00*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ITEM00, spawnPos->x,
                                                  spawnPos->y, spawnPos->z, 0, 0, 0, params | param8000 | param3F00);
            if ((spawnedActor != NULL) && !param8000) {
                spawnedActor->actor.velocity.y = !param4000 ? 8.0f : -2.0f;
                spawnedActor->actor.speedXZ = 2.0f;
                spawnedActor->actor.gravity = -0.9f;
                spawnedActor->actor.world.rot.y = Rand_CenteredFloat(65536.0f);
                Actor_SetScale(&spawnedActor->actor, 0.0f);
                EnItem00_SetupAction(spawnedActor, func_8001E304);
                spawnedActor->unk_15A = 220;
                if ((spawnedActor->actor.params != ITEM00_SMALL_KEY) &&
                    (spawnedActor->actor.params != ITEM00_HEART_PIECE) &&
                    (spawnedActor->actor.params != ITEM00_HEART_CONTAINER)) {
                    spawnedActor->actor.room = -1;
                }
                spawnedActor->actor.flags |= ACTOR_FLAG_4;
            }
        }
    }
    return spawnedActor;
}

EnItem00* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params) {
    EnItem00* spawnedActor = NULL;
    s32 pad;
    s16 param4000 = params & 0x4000;
    s16 param8000 = params & 0x8000;
    s16 param3F00 = params & 0x3F00;

    params &= 0x3FFF;

    if (((params & 0x00FF) == ITEM00_FLEXIBLE) && !param4000) {
        // TODO: Prevent the cast to EnItem00 here since pthis is a different actor (En_Elf)
        spawnedActor = (EnItem00*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, spawnPos->x,
                                              spawnPos->y + 40.0f, spawnPos->z, 0, 0, 0, FAIRY_HEAL_TIMED);
        EffectSsDeadSound_SpawnStationary(globalCtx, spawnPos, NA_SE_EV_BUTTERFRY_TO_FAIRY, true,
                                          DEADSOUND_REPEAT_MODE_OFF, 40);
    } else {
        params = func_8001F404(params & 0x00FF);
        if (params != -1) {
            spawnedActor = (EnItem00*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ITEM00, spawnPos->x,
                                                  spawnPos->y, spawnPos->z, 0, 0, 0, params | param8000 | param3F00);
            if ((spawnedActor != NULL) && !param8000) {
                spawnedActor->actor.velocity.y = 0.0f;
                spawnedActor->actor.speedXZ = 0.0f;
                spawnedActor->actor.gravity = param4000 ? 0.0f : -0.9f;
                spawnedActor->actor.world.rot.y = Rand_CenteredFloat(65536.0f);
                spawnedActor->actor.flags |= ACTOR_FLAG_4;
            }
        }
    }

    return spawnedActor;
}

void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params) {
    s32 pad;
    EnItem00* spawnedActor;
    s16 dropQuantity;
    s16 param8000;
    s16 dropTableIndex = Rand_ZeroOne() * 16.0f;
    u8 dropId;

    param8000 = params & 0x8000;
    params &= 0x7FFF;

    if (fromActor != NULL) {
        if (fromActor->dropFlag) {
            if (fromActor->dropFlag & 0x01) {
                params = 1 * 0x10;
                dropTableIndex = 11;
            } else if (fromActor->dropFlag & 0x02) {
                params = 1 * 0x10;
                dropTableIndex = 6;
            } else if (fromActor->dropFlag & 0x04) {
                params = 6 * 0x10;
                dropTableIndex = 9;
            } else if (fromActor->dropFlag & 0x08) {
                params = 3 * 0x10;
                dropTableIndex = 11;
            } else if (fromActor->dropFlag & 0x10) {
                params = 6 * 0x10;
                dropTableIndex = 12;
            } else if (fromActor->dropFlag & 0x20) {
                params = 0 * 0x10;
                dropTableIndex = 0;
            } else if (fromActor->dropFlag & 0x40) {
                params = 0 * 0x10;
                dropTableIndex = 1;
            }
        }
        if (fromActor->dropFlag & 0x20) {
            dropId = ITEM00_RUPEE_PURPLE;
        } else {
            dropId = sItemDropIds[params + dropTableIndex];
        }
    } else {
        dropId = sItemDropIds[params + dropTableIndex];
    }

    if (dropId == ITEM00_FLEXIBLE) {
        if (gSaveContext.health <= 0x10) { // 1 heart or less
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, spawnPos->x, spawnPos->y + 40.0f, spawnPos->z, 0,
                        0, 0, FAIRY_HEAL_TIMED);
            EffectSsDeadSound_SpawnStationary(globalCtx, spawnPos, NA_SE_EV_BUTTERFRY_TO_FAIRY, true,
                                              DEADSOUND_REPEAT_MODE_OFF, 40);
            return;
        } else if (gSaveContext.health <= 0x30) { // 3 hearts or less
            params = 0xB * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_HEART;
        } else if (gSaveContext.health <= 0x50) { // 5 hearts or less
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_HEART;
        } else if ((gSaveContext.magicLevel != 0) && (gSaveContext.magic == 0)) { // Empty magic meter
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_MAGIC_LARGE;
        } else if ((gSaveContext.magicLevel != 0) && (gSaveContext.magic <= (gSaveContext.magicLevel >> 1))) {
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_MAGIC_SMALL;
        } else if (!LINK_IS_ADULT && (AMMO(ITEM_SLINGSHOT) < 6)) {
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_SEEDS;
        } else if (LINK_IS_ADULT && (AMMO(ITEM_BOW) < 6)) {
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_ARROWS_MEDIUM;
        } else if (AMMO(ITEM_BOMB) < 6) {
            params = 0xD * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_BOMBS_A;
        } else if (gSaveContext.rupees < 11) {
            params = 0xA * 0x10;
            dropTableIndex = 0x0;
            dropId = ITEM00_RUPEE_RED;
        } else {
            return;
        }
    }

    if (dropId != 0xFF) {
        dropQuantity = sDropQuantities[params + dropTableIndex];
        while (dropQuantity > 0) {
            if (!param8000) {
                dropId = func_8001F404(dropId);
                if (dropId != 0xFF) {
                    spawnedActor = (EnItem00*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ITEM00, spawnPos->x,
                                                          spawnPos->y, spawnPos->z, 0, 0, 0, dropId);
                    if ((spawnedActor != NULL) && (dropId != 0xFF)) {
                        spawnedActor->actor.velocity.y = 8.0f;
                        spawnedActor->actor.speedXZ = 2.0f;
                        spawnedActor->actor.gravity = -0.9f;
                        spawnedActor->actor.world.rot.y = Rand_ZeroOne() * 40000.0f;
                        Actor_SetScale(&spawnedActor->actor, 0.0f);
                        EnItem00_SetupAction(spawnedActor, func_8001E304);
                        spawnedActor->actor.flags |= ACTOR_FLAG_4;
                        if ((spawnedActor->actor.params != ITEM00_SMALL_KEY) &&
                            (spawnedActor->actor.params != ITEM00_HEART_PIECE) &&
                            (spawnedActor->actor.params != ITEM00_HEART_CONTAINER)) {
                            spawnedActor->actor.room = -1;
                        }
                        spawnedActor->unk_15A = 220;
                    }
                }
            } else {
                Item_DropCollectible(globalCtx, spawnPos, params | 0x8000);
            }
            dropQuantity--;
        }
    }
}

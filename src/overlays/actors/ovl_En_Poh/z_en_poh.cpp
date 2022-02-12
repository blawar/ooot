#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_POH_Z_EN_POH_C
#include "actor_common.h"
/*
 * File: z_en_poh.c
 * Overlay: ovl_En_Poh
 * Description: Graveyard Poe
 */

#include "z_en_poh.h"
#include "objects/object_poh/object_poh.h"
#include "objects/object_po_composer/object_po_composer.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_12)

void EnPoh_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_Update(Actor* thisx, GlobalContext* globalCtx);

void EnPoh_UpdateLiving(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_UpdateDead(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_DrawRegular(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_DrawComposer(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_DrawSoul(Actor* thisx, GlobalContext* globalCtx);

void func_80ADEAC4(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_Idle(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADEC9C(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_Attack(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADEECC(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADF894(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_ComposerAppear(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADEF38(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADF15C(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADF574(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADF5E0(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_Disappear(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_Appear(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_Death(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADFE28(EnPoh* pthis, GlobalContext* globalCtx);
void func_80ADFE80(EnPoh* pthis, GlobalContext* globalCtx);
void func_80AE009C(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_TalkRegular(EnPoh* pthis, GlobalContext* globalCtx);
void EnPoh_TalkComposer(EnPoh* pthis, GlobalContext* globalCtx);

static s16 D_80AE1A50 = 0;

ActorInit En_Poh_InitVars = {
    ACTOR_EN_POH,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnPoh),
    (ActorFunc)EnPoh_Init,
    (ActorFunc)EnPoh_Destroy,
    (ActorFunc)EnPoh_Update,
    NULL,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT3,
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
    { 20, 40, 20, { 0, 0, 0 } },
};

static ColliderJntSphElementInit D_80AE1AA0[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 18, { { 0, 1400, 0 }, 10 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    D_80AE1AA0,
};

static CollisionCheckInfoInit sColChkInfoInit = { 4, 25, 50, 40 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(1, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static EnPohInfo sPoeInfo[2] = {
    {
        { 255, 170, 255 },
        { 100, 0, 150 },
        18,
        5,
        248,
        &gPoeDisappearAnim,
        &gPoeFloatAnim,
        &gPoeDamagedAnim,
        &gPoeFleeAnim,
        gPoeLanternDL,
        gPoeBurnDL,
        gPoeSoulDL,
    },
    {
        { 255, 255, 170 },
        { 0, 150, 0 },
        9,
        1,
        244,
        &gPoeComposerDisappearAnim,
        &gPoeComposerFloatAnim,
        &gPoeComposerDamagedAnim,
        &gPoeComposerFleeAnim,
        gPoeComposerLanternDL,
        gPoeComposerBurnDL,
        gPoeComposerSoulDL,
    },
};

static Color_RGBA8 D_80AE1B4C = { 75, 20, 25, 255 };
static Color_RGBA8 D_80AE1B50 = { 80, 110, 90, 255 };
static Color_RGBA8 D_80AE1B54 = { 90, 85, 50, 255 };
static Color_RGBA8 D_80AE1B58 = { 100, 90, 100, 255 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 3200, ICHAIN_STOP),
};

static Vec3f D_80AE1B60 = { 0.0f, 3.0f, 0.0f };
static Vec3f D_80AE1B6C = { 0.0f, 0.0f, 0.0f };

void EnPoh_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnItem00* collectible;
    EnPoh* pthis = (EnPoh*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    Collider_InitJntSph(globalCtx, &pthis->colliderSph);
    Collider_SetJntSph(globalCtx, &pthis->colliderSph, &pthis->actor, &sJntSphInit, &pthis->colliderSphItem);
    pthis->colliderSph.elements[0].dim.worldSphere.radius = 0;
    pthis->colliderSph.elements[0].dim.worldSphere.center.x = pthis->actor.world.pos.x;
    pthis->colliderSph.elements[0].dim.worldSphere.center.y = pthis->actor.world.pos.y;
    pthis->colliderSph.elements[0].dim.worldSphere.center.z = pthis->actor.world.pos.z;
    Collider_InitCylinder(globalCtx, &pthis->colliderCyl);
    Collider_SetCylinder(globalCtx, &pthis->colliderCyl, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->unk_194 = 0;
    pthis->unk_195 = 32;
    pthis->visibilityTimer = Rand_S16Offset(700, 300);
    pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
    Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z,
                            255, 255, 255, 0);
    if (pthis->actor.params >= 4) {
        pthis->actor.params = EN_POH_NORMAL;
    }
    if (pthis->actor.params == EN_POH_RUPEE) {
        D_80AE1A50++;
        if (D_80AE1A50 >= 3) {
            Actor_Kill(&pthis->actor);
        } else {
            collectible = Item_DropCollectible(globalCtx, &pthis->actor.world.pos, 0x4000 | ITEM00_RUPEE_BLUE);
            if (collectible != NULL) {
                collectible->actor.speedXZ = 0.0f;
            }
        }
    } else if (pthis->actor.params == EN_POH_FLAT) {
        if (Flags_GetSwitch(globalCtx, 0x28) || Flags_GetSwitch(globalCtx, 0x9)) {
            Actor_Kill(&pthis->actor);
        } else {
            Flags_SetSwitch(globalCtx, 0x28);
        }
    } else if (pthis->actor.params == EN_POH_SHARP) {
        if (Flags_GetSwitch(globalCtx, 0x29) || Flags_GetSwitch(globalCtx, 0x9)) {
            Actor_Kill(&pthis->actor);
        } else {
            Flags_SetSwitch(globalCtx, 0x29);
        }
    }
    if (pthis->actor.params < EN_POH_SHARP) {
        pthis->objectIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_POH);
        pthis->infoIdx = EN_POH_INFO_NORMAL;
        pthis->actor.naviEnemyId = 0x44;
    } else {
        pthis->objectIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_PO_COMPOSER);
        pthis->infoIdx = EN_POH_INFO_COMPOSER;
        pthis->actor.naviEnemyId = 0x43;
    }
    pthis->info = &sPoeInfo[pthis->infoIdx];
    if (pthis->objectIdx < 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnPoh_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
    Collider_DestroyJntSph(globalCtx, &pthis->colliderSph);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderCyl);
    if (pthis->actor.params == EN_POH_RUPEE) {
        D_80AE1A50--;
    }
}

void func_80ADE114(EnPoh* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, pthis->info->idleAnim);
    pthis->unk_198 = Rand_S16Offset(2, 3);
    pthis->actionFunc = func_80ADEAC4;
    pthis->actor.speedXZ = 0.0f;
}

void EnPoh_SetupIdle(EnPoh* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, pthis->info->idleAnim2);
    pthis->unk_198 = Rand_S16Offset(15, 3);
    pthis->actionFunc = EnPoh_Idle;
}

void func_80ADE1BC(EnPoh* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, pthis->info->idleAnim2);
    pthis->actionFunc = func_80ADEC9C;
    pthis->unk_198 = 0;
    pthis->actor.speedXZ = 2.0f;
}

void EnPoh_SetupAttack(EnPoh* pthis) {
    if (pthis->infoIdx == EN_POH_INFO_NORMAL) {
        Animation_MorphToLoop(&pthis->skelAnime, &gPoeAttackAnim, -6.0f);
    } else {
        Animation_PlayLoop(&pthis->skelAnime, &gPoeComposerAttackAnim);
    }
    pthis->unk_198 = 12;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
    pthis->actionFunc = EnPoh_Attack;
}

void func_80ADE28C(EnPoh* pthis) {
    if (pthis->infoIdx == EN_POH_INFO_NORMAL) {
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gPoeDamagedAnim, -6.0f);
    } else {
        Animation_PlayOnce(&pthis->skelAnime, &gPoeComposerDamagedAnim);
    }
    if (pthis->colliderCyl.info.acHitInfo->toucher.dmgFlags & 0x0001F824) {
        pthis->actor.world.rot.y = pthis->colliderCyl.base.ac->world.rot.y;
    } else {
        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, pthis->colliderCyl.base.ac) + 0x8000;
    }
    pthis->colliderCyl.base.acFlags &= ~AC_ON;
    pthis->actor.speedXZ = 5.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x10);
    pthis->actionFunc = func_80ADEECC;
}

void func_80ADE368(EnPoh* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, pthis->info->fleeAnim, -5.0f);
    pthis->actor.speedXZ = 5.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
    pthis->colliderCyl.base.acFlags |= AC_ON;
    pthis->unk_198 = 200;
    pthis->actionFunc = func_80ADF894;
}

void EnPoh_SetupInitialAction(EnPoh* pthis) {
    pthis->lightColor.a = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    if (pthis->infoIdx == EN_POH_INFO_NORMAL) {
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gPoeAppearAnim, 0.0f);
        pthis->actionFunc = func_80ADEF38;
    } else {
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, &gPoeComposerAppearAnim, 1.0f);
        pthis->actor.world.pos.y = pthis->actor.home.pos.y + 20.0f;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
        pthis->actionFunc = EnPoh_ComposerAppear;
    }
}

void func_80ADE48C(EnPoh* pthis) {
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->unk_198 = 0;
    pthis->actor.naviEnemyId = 0xFF;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = func_80ADF15C;
}

void func_80ADE4C8(EnPoh* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, pthis->info->idleAnim2);
    pthis->actionFunc = func_80ADF574;
    pthis->actor.speedXZ = -5.0f;
}

void func_80ADE514(EnPoh* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, pthis->info->idleAnim);
    pthis->unk_19C = pthis->actor.world.rot.y + 0x8000;
    pthis->actionFunc = func_80ADF5E0;
    pthis->actor.speedXZ = 0.0f;
}

void EnPoh_SetupDisappear(EnPoh* pthis) {
    pthis->unk_194 = 32;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DISAPPEAR);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
    pthis->actionFunc = EnPoh_Disappear;
}

void EnPoh_SetupAppear(EnPoh* pthis) {
    pthis->unk_194 = 0;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
    pthis->actionFunc = EnPoh_Appear;
}

void EnPoh_SetupDeath(EnPoh* pthis, GlobalContext* globalCtx) {
    pthis->actor.update = EnPoh_UpdateDead;
    pthis->actor.draw = EnPoh_DrawSoul;
    pthis->actor.shape.shadowDraw = NULL;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.flags |= ACTOR_FLAG_4;
    pthis->actor.gravity = -1.0f;
    pthis->actor.shape.yOffset = 1500.0f;
    pthis->actor.world.pos.y -= 15.0f;
    if (pthis->infoIdx != EN_POH_INFO_COMPOSER) {
        pthis->actor.shape.rot.x = -0x8000;
    }
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, 8);
    pthis->unk_198 = 60;
    pthis->actionFunc = EnPoh_Death;
}

void func_80ADE6D4(EnPoh* pthis) {
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, 0, 0, 0, 0);
    pthis->visibilityTimer = 0;
    pthis->actor.shape.rot.y = 0;
    pthis->lightColor.r = 0;
    pthis->lightColor.a = 0;
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    if (pthis->actor.params >= EN_POH_SHARP) {
        pthis->lightColor.g = 200;
        pthis->lightColor.b = 0;
    } else {
        pthis->lightColor.g = 0;
        pthis->lightColor.b = 200;
    }
    pthis->actor.scale.x = 0.0f;
    pthis->actor.scale.y = 0.0f;
    pthis->actor.shape.rot.x = 0;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_METAL_BOX_BOUND);
    pthis->actionFunc = func_80ADFE28;
}

void EnPoh_Talk(EnPoh* pthis, GlobalContext* globalCtx) {
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    Actor_SetFocus(&pthis->actor, -10.0f);
    pthis->colliderCyl.dim.radius = 13;
    pthis->colliderCyl.dim.height = 30;
    pthis->colliderCyl.dim.yShift = 0;
    pthis->colliderCyl.dim.pos.x = pthis->actor.world.pos.x;
    pthis->colliderCyl.dim.pos.y = pthis->actor.world.pos.y - 20.0f;
    pthis->colliderCyl.dim.pos.z = pthis->actor.world.pos.z;
    pthis->colliderCyl.base.ocFlags1 = OC1_ON | OC1_TYPE_PLAYER;
    if (pthis->actor.params == EN_POH_FLAT || pthis->actor.params == EN_POH_SHARP) {
        if (CHECK_QUEST_ITEM(QUEST_SONG_SUN)) {
            pthis->actor.textId = 0x5000;
        } else if (!Flags_GetSwitch(globalCtx, 0xA) && !Flags_GetSwitch(globalCtx, 0xB)) {
            pthis->actor.textId = 0x500F;
        } else if ((pthis->actor.params == EN_POH_FLAT && Flags_GetSwitch(globalCtx, 0xA)) ||
                   (pthis->actor.params == EN_POH_SHARP && Flags_GetSwitch(globalCtx, 0xB))) {
            pthis->actor.textId = 0x5013;
        } else {
            pthis->actor.textId = 0x5012;
        }
    } else {
        pthis->actor.textId = 0x5005;
    }
    pthis->unk_198 = 200;
    pthis->unk_195 = 32;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = func_80ADFE80;
}

void func_80ADE950(EnPoh* pthis, s32 arg1) {
    if (arg1) {
        Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
    }
    pthis->actionFunc = func_80AE009C;
}

void func_80ADE998(EnPoh* pthis) {
    pthis->actionFunc = EnPoh_TalkRegular;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y - 15.0f;
}

void func_80ADE9BC(EnPoh* pthis) {
    pthis->actionFunc = EnPoh_TalkComposer;
}

void EnPoh_MoveTowardsPlayerHeight(EnPoh* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_StepToF(&pthis->actor.world.pos.y, player->actor.world.pos.y, 1.0f);
    pthis->actor.world.pos.y += 2.5f * Math_SinS(pthis->unk_195 * 0x800);
    if (pthis->unk_195 != 0) {
        pthis->unk_195 -= 1;
    }
    if (pthis->unk_195 == 0) {
        pthis->unk_195 = 32;
    }
}

void func_80ADEA5C(EnPoh* pthis) {
    if (Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) > 400.0f) {
        pthis->unk_19C = Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos);
    }
    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->unk_19C, 0x71C);
}

void func_80ADEAC4(EnPoh* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_198 != 0) {
        pthis->unk_198--;
    }
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    if (pthis->actor.xzDistToPlayer < 200.0f) {
        func_80ADE1BC(pthis);
    } else if (pthis->unk_198 == 0) {
        EnPoh_SetupIdle(pthis);
    }
    if (pthis->lightColor.a == 255) {
        func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
    }
}

void EnPoh_Idle(EnPoh* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.speedXZ, 1.0f, 0.2f);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_198 != 0) {
        pthis->unk_198--;
    }
    func_80ADEA5C(pthis);
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    if (pthis->actor.xzDistToPlayer < 200.0f && pthis->unk_198 < 19) {
        func_80ADE1BC(pthis);
    } else if (pthis->unk_198 == 0) {
        if (Rand_ZeroOne() < 0.1f) {
            func_80ADE514(pthis);
        } else {
            func_80ADE114(pthis);
        }
    }
    if (pthis->lightColor.a == 255) {
        func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
    }
}

void func_80ADEC9C(EnPoh* pthis, GlobalContext* globalCtx) {
    Player* player;
    s16 facingDiff;

    player = GET_PLAYER(globalCtx);
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_198 != 0) {
        pthis->unk_198--;
    }
    facingDiff = pthis->actor.yawTowardsPlayer - player->actor.shape.rot.y;
    if (facingDiff >= 0x3001) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x3000, 0x71C);
    } else if (facingDiff < -0x3000) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer - 0x3000, 0x71C);
    } else {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0x71C);
    }
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    if (pthis->actor.xzDistToPlayer > 280.0f) {
        EnPoh_SetupIdle(pthis);
    } else if (pthis->unk_198 == 0 && pthis->actor.xzDistToPlayer < 140.0f &&
               !Player_IsFacingActor(&pthis->actor, 0x2AAA, globalCtx)) {
        EnPoh_SetupAttack(pthis);
    }
    if (pthis->lightColor.a == 255) {
        func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
    }
}

void EnPoh_Attack(EnPoh* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_KANTERA);
        if (pthis->unk_198 != 0) {
            pthis->unk_198--;
        }
    }
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    if (pthis->unk_198 >= 10) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0xE38);
    } else if (pthis->unk_198 == 9) {
        pthis->actor.speedXZ = 5.0f;
        pthis->skelAnime.playSpeed = 2.0f;
    } else if (pthis->unk_198 == 0) {
        EnPoh_SetupIdle(pthis);
        pthis->unk_198 = 23;
    }
}

void func_80ADEECC(EnPoh* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.colChkInfo.health != 0) {
            func_80ADE368(pthis);
        } else {
            func_80ADE48C(pthis);
        }
    }
}

void func_80ADEF38(EnPoh* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->lightColor.a = 255;
        pthis->visibilityTimer = Rand_S16Offset(700, 300);
        pthis->actor.flags |= ACTOR_FLAG_0;
        EnPoh_SetupIdle(pthis);
    } else if (pthis->skelAnime.curFrame > 10.0f) {
        pthis->lightColor.a = ((pthis->skelAnime.curFrame - 10.0f) * 0.05f) * 255.0f;
    }
    if (pthis->skelAnime.playSpeed < 0.5f && pthis->actor.xzDistToPlayer < 280.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnPoh_ComposerAppear(EnPoh* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->lightColor.a = 255;
        pthis->visibilityTimer = Rand_S16Offset(700, 300);
        pthis->actor.flags |= ACTOR_FLAG_0;
        EnPoh_SetupIdle(pthis);
    } else {
        pthis->lightColor.a = CLAMP_MAX((s32)(pthis->skelAnime.curFrame * 25.5f), 255);
    }
}

void func_80ADF15C(EnPoh* pthis, GlobalContext* globalCtx) {
    Vec3f vec;
    f32 multiplier;
    f32 newScale;
    s32 pad;
    s32 pad1;

    pthis->unk_198++;
    if (pthis->unk_198 < 8) {
        if (pthis->unk_198 < 5) {
            vec.y = Math_SinS((pthis->unk_198 * 0x1000) - 0x4000) * 23.0f + (pthis->actor.world.pos.y + 40.0f);
            multiplier = Math_CosS((pthis->unk_198 * 0x1000) - 0x4000) * 23.0f;
            vec.x = Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * multiplier +
                    pthis->actor.world.pos.x;
            vec.z = Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * multiplier +
                    pthis->actor.world.pos.z;
        } else {
            vec.y = (pthis->actor.world.pos.y + 40.0f) + (15.0f * (pthis->unk_198 - 5));
            vec.x =
                Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f + pthis->actor.world.pos.x;
            vec.z =
                Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f + pthis->actor.world.pos.z;
        }
        EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AE1B60, &D_80AE1B6C, pthis->unk_198 * 10 + 80, 0, 255, 255, 255, 255,
                             0, 0, 255, 1, 9, 1);
        vec.x = (pthis->actor.world.pos.x + pthis->actor.world.pos.x) - vec.x;
        vec.z = (pthis->actor.world.pos.z + pthis->actor.world.pos.z) - vec.z;
        EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AE1B60, &D_80AE1B6C, pthis->unk_198 * 10 + 80, 0, 255, 255, 255, 255,
                             0, 0, 255, 1, 9, 1);
        vec.x = pthis->actor.world.pos.x;
        vec.z = pthis->actor.world.pos.z;
        EffectSsDeadDb_Spawn(globalCtx, &vec, &D_80AE1B60, &D_80AE1B6C, pthis->unk_198 * 10 + 80, 0, 255, 255, 255, 255,
                             0, 0, 255, 1, 9, 1);
        if (pthis->unk_198 == 1) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EXTINCT);
        }
    } else if (pthis->unk_198 == 28) {
        EnPoh_SetupDeath(pthis, globalCtx);
    } else if (pthis->unk_198 >= 19) {
        newScale = (28 - pthis->unk_198) * 0.001f;
        pthis->actor.world.pos.y += 5.0f;
        pthis->actor.scale.z = newScale;
        pthis->actor.scale.y = newScale;
        pthis->actor.scale.x = newScale;
    }
    if (pthis->unk_198 == 18) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DEAD2);
    }
}

void func_80ADF574(EnPoh* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        EnPoh_SetupIdle(pthis);
        pthis->unk_198 = 23;
    } else {
        Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
        pthis->actor.shape.rot.y += 0x1000;
    }
}

void func_80ADF5E0(EnPoh* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->unk_19C, 1820) != 0) {
        EnPoh_SetupIdle(pthis);
    }
    if (pthis->actor.xzDistToPlayer < 200.0f) {
        func_80ADE1BC(pthis);
    }
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
}

void EnPoh_Disappear(EnPoh* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }
    pthis->actor.world.rot.y += 0x1000;
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    pthis->lightColor.a = pthis->unk_194 * 7.96875f;
    if (pthis->unk_194 == 0) {
        pthis->visibilityTimer = Rand_S16Offset(100, 50);
        EnPoh_SetupIdle(pthis);
    }
}

void EnPoh_Appear(EnPoh* pthis, GlobalContext* globalCtx) {
    pthis->unk_194++;
    pthis->actor.world.rot.y -= 0x1000;
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    pthis->lightColor.a = pthis->unk_194 * 7.96875f;
    if (pthis->unk_194 == 32) {
        pthis->visibilityTimer = Rand_S16Offset(700, 300);
        pthis->unk_194 = 0;
        EnPoh_SetupIdle(pthis);
    }
}

void func_80ADF894(EnPoh* pthis, GlobalContext* globalCtx) {
    f32 multiplier;

    SkelAnime_Update(&pthis->skelAnime);
    multiplier = Math_SinS(pthis->unk_195 * 0x800) * 3.0f;
    pthis->actor.world.pos.x -= multiplier * Math_CosS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.z += multiplier * Math_SinS(pthis->actor.shape.rot.y);
    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 0x71C);
    EnPoh_MoveTowardsPlayerHeight(pthis, globalCtx);
    if (pthis->unk_198 == 0 || pthis->actor.xzDistToPlayer > 250.0f) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        EnPoh_SetupIdle(pthis);
    }
    func_8002F974(&pthis->actor, NA_SE_EN_PO_AWAY - SFX_FLAG);
}

void EnPoh_Death(EnPoh* pthis, GlobalContext* globalCtx) {
    s32 objId;

    if (pthis->unk_198 != 0) {
        pthis->unk_198--;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        objId = (pthis->infoIdx == EN_POH_INFO_COMPOSER) ? OBJECT_PO_COMPOSER : OBJECT_POH;
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 6.0f, 0, 1, 1, 15, objId, 10,
                                 pthis->info->lanternDisplayList);
        func_80ADE6D4(pthis);
    } else if (pthis->unk_198 == 0) {
        Actor_Kill(&pthis->actor);
        return;
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 10.0f, 4);
}

void func_80ADFA90(EnPoh* pthis, s32 arg1) {
    f32 multiplier;

    pthis->lightColor.a = CLAMP(pthis->lightColor.a + arg1, 0, 255);
    if (arg1 < 0) {
        multiplier = pthis->lightColor.a * (1.0f / 255);
        pthis->actor.scale.x = pthis->actor.scale.z = 0.0056000002f * multiplier + 0.0014000001f;
        pthis->actor.scale.y = (0.007f - 0.007f * multiplier) + 0.007f;
    } else {
        multiplier = 1.0f;
        pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z = pthis->lightColor.a * (0.007f / 0xFF);
        pthis->actor.world.pos.y = pthis->actor.home.pos.y + (1.0f / 17.0f) * pthis->lightColor.a;
    }
    pthis->lightColor.r = pthis->info->lightColor.r * multiplier;
    pthis->lightColor.g = pthis->info->lightColor.g * multiplier;
    pthis->lightColor.b = pthis->info->lightColor.b * multiplier;
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, pthis->info->lightColor.r, pthis->info->lightColor.g,
                              pthis->info->lightColor.b, pthis->lightColor.a * (200.0f / 255));
}

void func_80ADFE28(EnPoh* pthis, GlobalContext* globalCtx) {
    pthis->actor.home.pos.y += 2.0f;
    func_80ADFA90(pthis, 20);
    if (pthis->lightColor.a == 255) {
        EnPoh_Talk(pthis, globalCtx);
    }
}

void func_80ADFE80(EnPoh* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_198 != 0) {
        pthis->unk_198--;
    }
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        if (pthis->actor.params >= EN_POH_SHARP) {
            func_80ADE9BC(pthis);
        } else {
            func_80ADE998(pthis);
        }
        return;
    }
    if (pthis->unk_198 == 0) {
        func_80ADE950(pthis, 1);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        return;
    }
    if (pthis->colliderCyl.base.ocFlags1 & OC1_HIT) {
        pthis->actor.flags |= ACTOR_FLAG_16;
        func_8002F2F4(&pthis->actor, globalCtx);
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCyl.base);
    }
    pthis->actor.world.pos.y = Math_SinS(pthis->unk_195 * 0x800) * 5.0f + pthis->actor.home.pos.y;
    if (pthis->unk_195 != 0) {
        pthis->unk_195 -= 1;
    }
    if (pthis->unk_195 == 0) {
        pthis->unk_195 = 32;
    }
    pthis->colliderCyl.dim.pos.y = pthis->actor.world.pos.y - 20.0f;
    Actor_SetFocus(&pthis->actor, -10.0f);
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, pthis->info->lightColor.r, pthis->info->lightColor.g,
                              pthis->info->lightColor.b, pthis->lightColor.a * (200.0f / 255));
}

void func_80AE009C(EnPoh* pthis, GlobalContext* globalCtx) {
    func_80ADFA90(pthis, -13);
    if (pthis->lightColor.a == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnPoh_TalkRegular(EnPoh* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.textId != 0x5005) {
        func_80ADFA90(pthis, -13);
    } else {
        func_8002F974(&pthis->actor, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) {
        if (Message_ShouldAdvance(globalCtx)) {
            Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
            if (globalCtx->msgCtx.choiceIndex == 0) {
                if (Inventory_HasEmptyBottle()) {
                    pthis->actor.textId = 0x5008;
                    Item_Give(globalCtx, ITEM_POE);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_BIG_GET);
                } else {
                    pthis->actor.textId = 0x5006;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
                }
            } else {
                pthis->actor.textId = 0x5007;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
            }
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        }
    } else if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        func_80ADE950(pthis, 0);
    }
}

void EnPoh_TalkComposer(EnPoh* pthis, GlobalContext* globalCtx) {
    func_8002F974(&pthis->actor, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) {
        if (Message_ShouldAdvance(globalCtx)) {
            if (globalCtx->msgCtx.choiceIndex == 0) {
                if (!Flags_GetSwitch(globalCtx, 0xB) && !Flags_GetSwitch(globalCtx, 0xA)) {
                    pthis->actor.textId = 0x5010;
                } else {
                    pthis->actor.textId = 0x5014;
                }
                Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            } else {
                if (pthis->actor.params == EN_POH_SHARP) {
                    Flags_SetSwitch(globalCtx, 0xB);
                } else {
                    Flags_SetSwitch(globalCtx, 0xA);
                }
                func_80ADE950(pthis, 1);
            }
        }
    } else if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        if (pthis->actor.textId == 0x5000) {
            Flags_SetSwitch(globalCtx, 9);
        }
        func_80ADE950(pthis, 1);
    }
}

void func_80AE032C(EnPoh* pthis, GlobalContext* globalCtx) {
    if (pthis->colliderCyl.base.acFlags & AC_HIT) {
        pthis->colliderCyl.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != 0 || pthis->actor.colChkInfo.damage != 0) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DEAD);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DAMAGE);
            }
            func_80ADE28C(pthis);
        }
    }
}

void EnPoh_UpdateVisibility(EnPoh* pthis) {
    if (pthis->actionFunc != EnPoh_Appear && pthis->actionFunc != EnPoh_Disappear && pthis->actionFunc != func_80ADEF38 &&
        pthis->actionFunc != EnPoh_ComposerAppear) {
        if (pthis->visibilityTimer != 0) {
            pthis->visibilityTimer--;
        }
        if (pthis->lightColor.a == 255) {
            if (pthis->actor.isTargeted) {
                pthis->unk_194++;
                pthis->unk_194 = CLAMP_MAX(pthis->unk_194, 20);
            } else {
                pthis->unk_194 = 0;
            }
            if ((pthis->unk_194 == 20 || pthis->visibilityTimer == 0) &&
                (pthis->actionFunc == func_80ADEAC4 || pthis->actionFunc == EnPoh_Idle ||
                 pthis->actionFunc == func_80ADEC9C || pthis->actionFunc == func_80ADF894 ||
                 pthis->actionFunc == func_80ADF5E0)) {
                EnPoh_SetupDisappear(pthis);
            }
        } else if (pthis->lightColor.a == 0 && pthis->visibilityTimer == 0 &&
                   (pthis->actionFunc == func_80ADEAC4 || pthis->actionFunc == EnPoh_Idle ||
                    pthis->actionFunc == func_80ADEC9C || pthis->actionFunc == func_80ADF5E0)) {
            EnPoh_SetupAppear(pthis);
        }
    }
}

void EnPoh_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objectIdx) != 0) {
        pthis->actor.objBankIndex = pthis->objectIdx;
        pthis->actor.update = EnPoh_UpdateLiving;
        Actor_SetObjectDependency(globalCtx, &pthis->actor);
        if (pthis->infoIdx == EN_POH_INFO_NORMAL) {
            SkelAnime_Init(globalCtx, &pthis->skelAnime, &gPoeSkel, &gPoeFloatAnim, pthis->jointTable, pthis->morphTable,
                           21);
            pthis->actor.draw = EnPoh_DrawRegular;
        } else {
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gPoeComposerSkel, &gPoeComposerFloatAnim, pthis->jointTable,
                               pthis->morphTable, 12);
            pthis->actor.draw = EnPoh_DrawComposer;
            pthis->colliderSph.elements[0].dim.limb = 9;
            pthis->colliderSph.elements[0].dim.modelSphere.center.y *= -1;
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y = -0x4000;
            pthis->colliderCyl.dim.radius = 20;
            pthis->colliderCyl.dim.height = 55;
            pthis->colliderCyl.dim.yShift = 15;
        }
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        EnPoh_SetupInitialAction(pthis);
    }
}

void func_80AE067C(EnPoh* pthis) {
    s16 temp_var;

    if (pthis->actionFunc == EnPoh_Attack) {
        pthis->lightColor.r = CLAMP_MAX((s16)(pthis->lightColor.r + 5), 255);
        pthis->lightColor.g = CLAMP_MIN((s16)(pthis->lightColor.g - 5), 50);
        temp_var = pthis->lightColor.b - 5;
        pthis->lightColor.b = CLAMP_MIN(temp_var, 0);
    } else if (pthis->actionFunc == func_80ADF894) {
        pthis->lightColor.r = CLAMP_MAX((s16)(pthis->lightColor.r + 5), 80);
        pthis->lightColor.g = CLAMP_MAX((s16)(pthis->lightColor.g + 5), 255);
        temp_var = pthis->lightColor.b + 5;
        pthis->lightColor.b = CLAMP_MAX(temp_var, 225);
    } else if (pthis->actionFunc == func_80ADEECC) {
        if (pthis->actor.colorFilterTimer & 2) {
            pthis->lightColor.r = 0;
            pthis->lightColor.g = 0;
            pthis->lightColor.b = 0;
        } else {
            pthis->lightColor.r = 80;
            pthis->lightColor.g = 255;
            pthis->lightColor.b = 225;
        }
    } else {
        pthis->lightColor.r = CLAMP_MAX((s16)(pthis->lightColor.r + 5), 255);
        pthis->lightColor.g = CLAMP_MAX((s16)(pthis->lightColor.g + 5), 255);
        if (pthis->lightColor.b >= 211) {
            temp_var = pthis->lightColor.b - 5;
            pthis->lightColor.b = CLAMP_MIN(temp_var, 210);
        } else {
            temp_var = pthis->lightColor.b + 5;
            pthis->lightColor.b = CLAMP_MAX(temp_var, 210);
        }
    }
}

void func_80AE089C(EnPoh* pthis) {
    f32 rand;

    if ((pthis->actionFunc == func_80ADEF38 || pthis->actionFunc == EnPoh_ComposerAppear) &&
        pthis->skelAnime.curFrame < 12.0f) {
        pthis->envColor.r = pthis->envColor.g = pthis->envColor.b = (s16)(pthis->skelAnime.curFrame * 16.66f) + 55;
        pthis->envColor.a = pthis->skelAnime.curFrame * (100.0f / 6.0f);
    } else {
        rand = Rand_ZeroOne();
        pthis->envColor.r = (s16)(rand * 30.0f) + 225;
        pthis->envColor.g = (s16)(rand * 100.0f) + 155;
        pthis->envColor.b = (s16)(rand * 160.0f) + 95;
        pthis->envColor.a = 200;
    }
}

void EnPoh_UpdateLiving(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;
    s32 pad;
    Vec3f vec;
    s32 sp38;

    if (pthis->colliderSph.base.atFlags & AT_HIT) {
        pthis->colliderSph.base.atFlags &= ~AT_HIT;
        func_80ADE4C8(pthis);
    }
    func_80AE032C(pthis, globalCtx);
    EnPoh_UpdateVisibility(pthis);
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    if (pthis->actionFunc == EnPoh_Attack && pthis->unk_198 < 10) {
        pthis->actor.flags |= ACTOR_FLAG_24;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
    }
    Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCyl);
    if ((pthis->colliderCyl.base.acFlags & AC_ON) && pthis->lightColor.a == 255) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCyl.base);
    }
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCyl.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSph.base);
    Actor_SetFocus(&pthis->actor, 42.0f);
    if (pthis->actionFunc != func_80ADEECC && pthis->actionFunc != func_80ADF574) {
        if (pthis->actionFunc == func_80ADF894) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
        } else {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        }
    }
    vec.x = pthis->actor.world.pos.x;
    vec.y = pthis->actor.world.pos.y + 20.0f;
    vec.z = pthis->actor.world.pos.z;
    pthis->actor.floorHeight =
        BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &sp38, &pthis->actor, &vec);
    func_80AE089C(pthis);
    pthis->actor.shape.shadowAlpha = pthis->lightColor.a;
}

s32 EnPoh_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                           Gfx** gfxP) {
    EnPoh* pthis = (EnPoh*)thisx;

    if ((pthis->lightColor.a == 0 || limbIndex == pthis->info->unk_6) ||
        (pthis->actionFunc == func_80ADF15C && pthis->unk_198 >= 2)) {
        *dList = NULL;
    } else if (pthis->actor.params == EN_POH_FLAT && limbIndex == 0xA) {
        // Replace Sharp's head with Flat's
        *dList = gPoeComposerFlatHeadDL;
    }
    if (limbIndex == 0x13 && pthis->infoIdx == EN_POH_INFO_NORMAL) {
        gDPPipeSync((*gfxP)++);
        gDPSetEnvColor((*gfxP)++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, pthis->lightColor.a);
    }
    return false;
}

void EnPoh_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfxP) {
    EnPoh* pthis = (EnPoh*)thisx;

    Collider_UpdateSpheres(limbIndex, &pthis->colliderSph);
    if (pthis->actionFunc == func_80ADF15C && pthis->unk_198 >= 2 && limbIndex == pthis->info->unk_7) {
        gSPMatrix((*gfxP)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_poh.c", 2460),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList((*gfxP)++, pthis->info->burnDisplayList);
    }
    if (limbIndex == pthis->info->unk_6) {
        if (pthis->actionFunc == func_80ADF15C && pthis->unk_198 >= 19 && 0.0f != pthis->actor.scale.x) {
            f32 mtxScale = 0.01f / pthis->actor.scale.x;
            Matrix_Scale(mtxScale, mtxScale, mtxScale, MTXMODE_APPLY);
        }
        Matrix_Get(&pthis->unk_368);
        if (pthis->actionFunc == func_80ADF15C && pthis->unk_198 == 27) {
            pthis->actor.world.pos.x = pthis->unk_368.xw;
            pthis->actor.world.pos.y = pthis->unk_368.yw;
            pthis->actor.world.pos.z = pthis->unk_368.zw;
        }
        Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->colliderSph.elements[0].dim.worldSphere.center.x,
                                pthis->colliderSph.elements[0].dim.worldSphere.center.y,
                                pthis->colliderSph.elements[0].dim.worldSphere.center.z, pthis->envColor.r,
                                pthis->envColor.g, pthis->envColor.b, pthis->envColor.a * (200.0f / 255));
    }
}

void EnPoh_DrawRegular(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2629);
    func_80AE067C(pthis);
    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);
    if (pthis->lightColor.a == 255 || pthis->lightColor.a == 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, pthis->lightColor.a);
        gSPSegment(POLY_OPA_DISP++, 0x08, D_80116280 + 2);
        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnPoh_OverrideLimbDraw, EnPoh_PostLimbDraw, &pthis->actor, POLY_OPA_DISP);
    } else {
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, pthis->lightColor.a);
        gSPSegment(POLY_XLU_DISP++, 0x08, D_80116280);
        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnPoh_OverrideLimbDraw, EnPoh_PostLimbDraw, &pthis->actor, POLY_XLU_DISP);
    }
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, pthis->envColor.r, pthis->envColor.g, pthis->envColor.b, 255);
    Matrix_Put(&pthis->unk_368);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_poh.c", 2676),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, pthis->info->lanternDisplayList);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2681);
}

void EnPoh_DrawComposer(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;
    Color_RGBA8* sp90;
    Color_RGBA8* phi_t0;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2694);
    func_80AE067C(pthis);
    if (pthis->actor.params == EN_POH_SHARP) {
        sp90 = &D_80AE1B4C;
        phi_t0 = &D_80AE1B54;
    } else {
        sp90 = &D_80AE1B50;
        phi_t0 = &D_80AE1B58;
    }
    if (pthis->lightColor.a == 255 || pthis->lightColor.a == 0) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x08,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                                pthis->lightColor.a));
        gSPSegment(POLY_OPA_DISP++, 0x0A,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, sp90->r, sp90->g, sp90->b, pthis->lightColor.a));
        gSPSegment(POLY_OPA_DISP++, 0x0B,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, phi_t0->r, phi_t0->g, phi_t0->b, pthis->lightColor.a));
        gSPSegment(POLY_OPA_DISP++, 0x0C, D_80116280 + 2);
        POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, EnPoh_OverrideLimbDraw, EnPoh_PostLimbDraw,
                                           &pthis->actor, POLY_OPA_DISP);
    } else {
        func_80093D18(globalCtx->state.gfxCtx);
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                                pthis->lightColor.a));
        gSPSegment(POLY_XLU_DISP++, 0x0A,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, sp90->r, sp90->g, sp90->b, pthis->lightColor.a));
        gSPSegment(POLY_XLU_DISP++, 0x0B,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, phi_t0->r, phi_t0->g, phi_t0->b, pthis->lightColor.a));
        gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);
        POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, EnPoh_OverrideLimbDraw, EnPoh_PostLimbDraw,
                                           &pthis->actor, POLY_XLU_DISP);
    }
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, pthis->envColor.r, pthis->envColor.g, pthis->envColor.b, 255);
    Matrix_Put(&pthis->unk_368);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_poh.c", 2787),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, pthis->info->lanternDisplayList);
    gSPDisplayList(POLY_OPA_DISP++, gPoeComposerLanternBottomDL);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, sp90->r, sp90->g, sp90->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, gPoeComposerLanternTopDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2802);
}

void EnPoh_UpdateDead(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actionFunc != EnPoh_Death) {
        pthis->visibilityTimer++;
    }
    func_80AE089C(pthis);
}

void EnPoh_DrawSoul(Actor* thisx, GlobalContext* globalCtx) {
    EnPoh* pthis = (EnPoh*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2833);

    if (pthis->actionFunc == EnPoh_Death) {
        func_80093D18(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->envColor.r, pthis->envColor.g, pthis->envColor.b, 255);
        Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                pthis->actor.world.pos.z, pthis->envColor.r, pthis->envColor.g, pthis->envColor.b, 200);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_poh.c", 2854),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, pthis->info->lanternDisplayList);
        if (pthis->infoIdx == EN_POH_INFO_COMPOSER) {
            Color_RGBA8* envColor = (pthis->actor.params == EN_POH_SHARP) ? &D_80AE1B4C : &D_80AE1B50;
            s32 pad;

            gSPDisplayList(POLY_OPA_DISP++, gPoeComposerLanternBottomDL);
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetEnvColor(POLY_OPA_DISP++, envColor->r, envColor->g, envColor->b, 255);
            gSPDisplayList(POLY_OPA_DISP++, gPoeComposerLanternTopDL);
        }
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                    (pthis->visibilityTimer * pthis->info->unk_8) % 512U, 0x20, 0x80));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, pthis->info->primColor.r, pthis->info->primColor.g,
                        pthis->info->primColor.b, pthis->lightColor.a);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, 255);
        Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * 9.58738e-05f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_poh.c", 2910),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, pthis->info->soulDisplayList);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_poh.c", 2916);
}

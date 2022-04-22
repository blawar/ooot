#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DEKUBABA_Z_EN_DEKUBABA_C
#include "actor_common.h"
#include "z_en_dekubaba.h"
#include "objects/object_dekubaba/object_dekubaba.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnDekubaba_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDekubaba_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDekubaba_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDekubaba_SetupWait(EnDekubaba* pthis);
void EnDekubaba_SetupGrow(EnDekubaba* pthis);
void EnDekubaba_Wait(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Grow(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Retract(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_DecideLunge(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Lunge(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_PrepareLunge(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_PullBack(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Recover(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Hit(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_StunnedVertical(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_Sway(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_PrunedSomersault(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_ShrinkDie(EnDekubaba* pthis, GlobalContext* globalCtx);
void EnDekubaba_DeadStickDrop(EnDekubaba* pthis, GlobalContext* globalCtx);

static Color_RGBA8 primColor_49 = { 105, 255, 105, 255 };

static Color_RGBA8 envColor_49 = { 150, 250, 150, 0 };

static Gfx* stemDLists_55[] = { gDekuBabaStemTopDL, gDekuBabaStemMiddleDL, gDekuBabaStemBaseDL };


static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

ActorInit En_Dekubaba_InitVars = {
    ACTOR_EN_DEKUBABA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DEKUBABA,
    sizeof(EnDekubaba),
    (ActorFunc)EnDekubaba_Init,
    (ActorFunc)EnDekubaba_Destroy,
    (ActorFunc)EnDekubaba_Update,
    (ActorFunc)EnDekubaba_Draw,
    (ActorFunc)EnDekubaba_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[7] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 100, 1000 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 51, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 52, { { 0, 0, 500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 53, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 54, { { 0, 0, 500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 55, { { 0, 0, 1500 }, 8 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 56, { { 0, 0, 500 }, 8 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    7,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 2, 25, 25, MASS_IMMOVABLE };

static DamageTable sDekuBabaDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
    /* Deku stick    */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(1, DEKUBABA_DMGEFF_NONE),
    /* Explosive     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_BOOMERANG),
    /* Normal arrow  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Kokiri sword  */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
    /* Master sword  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Giant's Knife */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Fire arrow    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Light arrow   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Light magic   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Shield        */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
    /* Giant spin    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Master spin   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Kokiri jump   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Giant jump    */ DMG_ENTRY(8, DEKUBABA_DMGEFF_SWORD),
    /* Master jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Unknown 1     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
};

// The only difference is that for Big Deku Babas, Hookshot will act the same as Deku Nuts: i.e. it will stun, but
// cannot kill.
static DamageTable sBigDekuBabaDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
    /* Deku stick    */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Slingshot     */ DMG_ENTRY(1, DEKUBABA_DMGEFF_NONE),
    /* Explosive     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Boomerang     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_BOOMERANG),
    /* Normal arrow  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Hammer swing  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Hookshot      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
    /* Kokiri sword  */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
    /* Master sword  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Giant's Knife */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Fire arrow    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
    /* Ice arrow     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Light arrow   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 1   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 2   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Unk arrow 3   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
    /* Fire magic    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
    /* Ice magic     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Light magic   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Shield        */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Mirror Ray    */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Kokiri spin   */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
    /* Giant spin    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Master spin   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Kokiri jump   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
    /* Giant jump    */ DMG_ENTRY(8, DEKUBABA_DMGEFF_SWORD),
    /* Master jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
    /* Unknown 1     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Unblockable   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    /* Hammer jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE),
    /* Unknown 2     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 1500, ICHAIN_STOP),
};

void EnDekubaba_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDekubaba* pthis = (EnDekubaba*)thisx;
    s32 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 22.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDekuBabaSkel, &gDekuBabaFastChompAnim, pthis->jointTable,
                   pthis->morphTable, 8);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderElements);

    if (pthis->actor.params == DEKUBABA_BIG) {
        pthis->size = 2.5f;

        for (i = 0; i < sJntSphInit.count; i++) {
            pthis->collider.elements[i].dim.worldSphere.radius = pthis->collider.elements[i].dim.modelSphere.radius =
                (sJntSphElementsInit[i].dim.modelSphere.radius * 2.50f);
        }

        // This and its counterpart below mean that a Deku Stick jumpslash will not trigger the Deku Stick drop route.
        // (Of course they reckoned without each age being able to use the other's items, so Stick and Master Sword
        // jumpslash can give the Stick drop as adult, and neither will as child.)
        if (!LINK_IS_ADULT) {
            sBigDekuBabaDamageTable.table[0x1B] = DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE); // DMG_JUMP_MASTER
        }

        CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sBigDekuBabaDamageTable, &sColChkInfoInit);
        pthis->actor.colChkInfo.health = 4;
        pthis->actor.naviEnemyId = 0x08; // Big Deku Baba
        pthis->actor.targetMode = 2;
    } else {
        pthis->size = 1.0f;

        for (i = 0; i < sJntSphInit.count; i++) {
            pthis->collider.elements[i].dim.worldSphere.radius = pthis->collider.elements[i].dim.modelSphere.radius;
        }

        if (!LINK_IS_ADULT) {
            sDekuBabaDamageTable.table[0x1B] = DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE); // DMG_JUMP_MASTER
        }

        CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDekuBabaDamageTable, &sColChkInfoInit);
        pthis->actor.naviEnemyId = 0x07; // Deku Baba
        pthis->actor.targetMode = 1;
    }

    EnDekubaba_SetupWait(pthis);
    pthis->timer = 0;
    pthis->boundFloor = NULL;
    pthis->bodyPartsPos[3] = pthis->actor.home.pos;
}

void EnDekubaba_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnDekubaba* pthis = (EnDekubaba*)thisx;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnDekubaba_DisableHitboxes(EnDekubaba* pthis) {
    s32 i;

    for (i = 1; i < ARRAY_COUNT(pthis->colliderElements); i++) {
        pthis->collider.elements[i].info.bumperFlags &= ~BUMP_ON;
    }
}

void EnDekubaba_SetupWait(EnDekubaba* pthis) {
    s32 i;
    ColliderJntSphElement* element;

    pthis->actor.shape.rot.x = -0x4000;
    pthis->stemSectionAngle[0] = pthis->stemSectionAngle[1] = pthis->stemSectionAngle[2] = pthis->actor.shape.rot.x;

    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 14.0f * pthis->size;

    Actor_SetScale(&pthis->actor, pthis->size * 0.01f * 0.5f);

    pthis->collider.base.colType = COLTYPE_HARD;
    pthis->collider.base.acFlags |= AC_HARD;
    pthis->timer = 45;

    for (i = 1; i < ARRAY_COUNT(pthis->colliderElements); i++) {
        element = &pthis->collider.elements[i];
        element->dim.worldSphere.center.x = pthis->actor.world.pos.x;
        element->dim.worldSphere.center.y = (s16)pthis->actor.world.pos.y - 7;
        element->dim.worldSphere.center.z = pthis->actor.world.pos.z;
    }

    pthis->actionFunc = EnDekubaba_Wait;
}

void EnDekubaba_SetupGrow(EnDekubaba* pthis) {
    s32 i;

    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim,
                     Animation_GetLastFrame(&gDekuBabaFastChompAnim) * (1.0f / 15), 0.0f,
                     Animation_GetLastFrame(&gDekuBabaFastChompAnim), ANIMMODE_ONCE, 0.0f);

    pthis->timer = 15;

    for (i = 2; i < ARRAY_COUNT(pthis->colliderElements); i++) {
        pthis->collider.elements[i].info.ocElemFlags |= OCELEM_ON;
    }

    pthis->collider.base.colType = COLTYPE_HIT6;
    pthis->collider.base.acFlags &= ~AC_HARD;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DUMMY482);
    pthis->actionFunc = EnDekubaba_Grow;
}

void EnDekubaba_SetupRetract(EnDekubaba* pthis) {
    s32 i;

    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, -1.5f, Animation_GetLastFrame(&gDekuBabaFastChompAnim),
                     0.0f, ANIMMODE_ONCE, -3.0f);

    pthis->timer = 15;

    for (i = 2; i < ARRAY_COUNT(pthis->colliderElements); i++) {
        pthis->collider.elements[i].info.ocElemFlags &= ~OCELEM_ON;
    }

    pthis->actionFunc = EnDekubaba_Retract;
}

void EnDekubaba_SetupDecideLunge(EnDekubaba* pthis) {
    pthis->timer = Animation_GetLastFrame(&gDekuBabaFastChompAnim) * 2;
    Animation_MorphToLoop(&pthis->skelAnime, &gDekuBabaFastChompAnim, -3.0f);
    pthis->actionFunc = EnDekubaba_DecideLunge;
}

void EnDekubaba_SetupPrepareLunge(EnDekubaba* pthis) {
    pthis->timer = 8;
    pthis->skelAnime.playSpeed = 0.0f;
    pthis->actionFunc = EnDekubaba_PrepareLunge;
}

void EnDekubaba_SetupLunge(EnDekubaba* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gDekuBabaPauseChompAnim);
    pthis->timer = 0;
    pthis->actionFunc = EnDekubaba_Lunge;
}

void EnDekubaba_SetupPullBack(EnDekubaba* pthis) {
    Animation_Change(&pthis->skelAnime, &gDekuBabaPauseChompAnim, 1.0f, 15.0f,
                     Animation_GetLastFrame(&gDekuBabaPauseChompAnim), ANIMMODE_ONCE, -3.0f);
    pthis->timer = 0;
    pthis->actionFunc = EnDekubaba_PullBack;
}

void EnDekubaba_SetupRecover(EnDekubaba* pthis) {
    pthis->timer = 9;
    pthis->collider.base.acFlags |= AC_ON;
    pthis->skelAnime.playSpeed = -1.0f;
    pthis->actionFunc = EnDekubaba_Recover;
}

void EnDekubaba_SetupHit(EnDekubaba* pthis, s32 arg1) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDekuBabaPauseChompAnim, -5.0f);
    pthis->timer = arg1;
    pthis->collider.base.acFlags &= ~AC_ON;
    Actor_SetScale(&pthis->actor, pthis->size * 0.01f);

    if (arg1 == 2) {
        Actor_SetColorFilter(&pthis->actor, 0, 155, 0, 62);
    } else {
        Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 42);
    }

    pthis->actionFunc = EnDekubaba_Hit;
}

void EnDekubaba_SetupPrunedSomersault(EnDekubaba* pthis) {
    pthis->timer = 0;
    pthis->skelAnime.playSpeed = 0.0f;
    pthis->actor.gravity = -0.8f;
    pthis->actor.velocity.y = 4.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.speedXZ = pthis->size * 3.0f;
    pthis->actor.flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
    pthis->actionFunc = EnDekubaba_PrunedSomersault;
}

void EnDekubaba_SetupShrinkDie(EnDekubaba* pthis) {
    Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, -1.5f, Animation_GetLastFrame(&gDekuBabaFastChompAnim),
                     0.0f, ANIMMODE_ONCE, -3.0f);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnDekubaba_ShrinkDie;
}

void EnDekubaba_SetupStunnedVertical(EnDekubaba* pthis) {
    s32 i;

    for (i = 1; i < ARRAY_COUNT(pthis->colliderElements); i++) {
        pthis->collider.elements[i].info.bumperFlags |= BUMP_ON;
    }

    if (pthis->timer == 1) {
        Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, 4.0f, 0.0f,
                         Animation_GetLastFrame(&gDekuBabaFastChompAnim), ANIMMODE_LOOP, -3.0f);
        pthis->timer = 40;
    } else {
        Animation_Change(&pthis->skelAnime, &gDekuBabaFastChompAnim, 0.0f, 0.0f,
                         Animation_GetLastFrame(&gDekuBabaFastChompAnim), ANIMMODE_LOOP, -3.0f);
        pthis->timer = 60;
    }

    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (60.0f * pthis->size);
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    pthis->actionFunc = EnDekubaba_StunnedVertical;
}

void EnDekubaba_SetupSway(EnDekubaba* pthis) {
    pthis->targetSwayAngle = -0x6000;
    pthis->stemSectionAngle[2] = -0x5000;
    pthis->stemSectionAngle[1] = -0x4800;

    EnDekubaba_DisableHitboxes(pthis);
    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 35);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = EnDekubaba_Sway;
}

void EnDekubaba_SetupDeadStickDrop(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Actor_SetScale(&pthis->actor, 0.03f);
    pthis->actor.shape.rot.x -= 0x4000;
    pthis->actor.shape.yOffset = 1000.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.shape.shadowScale = 3.0f;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_MISC);
    pthis->actor.flags &= ~ACTOR_FLAG_5;
    pthis->timer = 200;
    pthis->actionFunc = EnDekubaba_DeadStickDrop;
}

// Action functions

void EnDekubaba_Wait(EnDekubaba* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y + 14.0f * pthis->size;

    if ((pthis->timer == 0) && (pthis->actor.xzDistToPlayer < 200.0f * pthis->size) &&
        (fabsf(pthis->actor.yDistToPlayer) < 30.0f * pthis->size)) {
        EnDekubaba_SetupGrow(pthis);
    }
}

void EnDekubaba_Grow(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 headDistHorizontal;
    f32 headDistVertical;
    f32 headShiftX;
    f32 headShiftZ = 0;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    SkelAnime_Update(&pthis->skelAnime);

    pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z =
        pthis->size * 0.01f * (0.5f + (15 - pthis->timer) * 0.5f / 15.0f);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x1800, 0x800);

    headDistVertical = sinf(CLAMP_MAX((15 - pthis->timer) * (1.0f / 15), 0.7f) * M_PI) * 32.0f + 14.0f;

    if (pthis->actor.shape.rot.x < -0x38E3) {
        headDistHorizontal = 0.0f;
    } else if (pthis->actor.shape.rot.x < -0x238E) {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x5555, 0x38E);
        headDistHorizontal = Math_CosS(pthis->stemSectionAngle[0]) * 20.0f;
    } else if (pthis->actor.shape.rot.x < -0xE38) {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0xAAA, 0x38E);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x5555, 0x38E);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5555, 0x222);

        headDistHorizontal = 20.0f * (Math_CosS(pthis->stemSectionAngle[0]) + Math_CosS(pthis->stemSectionAngle[1])) +
                             (headDistVertical -
                              20.0f * (-Math_SinS(pthis->stemSectionAngle[0]) - Math_SinS(pthis->stemSectionAngle[1]))) *
                                 Math_CosS(pthis->stemSectionAngle[2]) / -Math_SinS(pthis->stemSectionAngle[2]);
    } else {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0xAAA, 0x38E);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x31C7, 0x222);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5555, 0x222);

        headDistHorizontal = 20.0f * (Math_CosS(pthis->stemSectionAngle[0]) + Math_CosS(pthis->stemSectionAngle[1])) +
                             (headDistVertical -
                              20.0f * (-Math_SinS(pthis->stemSectionAngle[0]) - Math_SinS(pthis->stemSectionAngle[1]))) *
                                 Math_CosS(pthis->stemSectionAngle[2]) / -Math_SinS(pthis->stemSectionAngle[2]);
    }

    if (pthis->timer < 10) {
        Math_ApproachS(&pthis->actor.shape.rot.y, Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos), 2,
                       0xE38);
        if (headShiftZ) {} // One way of fake-matching
    }

    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (headDistVertical * pthis->size);
    headShiftX = headDistHorizontal * pthis->size * Math_SinS(pthis->actor.shape.rot.y);
    headShiftZ = headDistHorizontal * pthis->size * Math_CosS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.x = pthis->actor.home.pos.x + headShiftX;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z + headShiftZ;

    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.home.pos, pthis->size * 3.0f, 0, pthis->size * 12.0f,
                             pthis->size * 5.0f, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);

    if (pthis->timer == 0) {
        if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < 240.0f * pthis->size) {
            EnDekubaba_SetupPrepareLunge(pthis);
        } else {
            EnDekubaba_SetupRetract(pthis);
        }
    }
}

void EnDekubaba_Retract(EnDekubaba* pthis, GlobalContext* globalCtx) {
    f32 headDistHorizontal;
    f32 headDistVertical;
    f32 xShift;
    f32 zShift;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    SkelAnime_Update(&pthis->skelAnime);

    pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z =
        pthis->size * 0.01f * (0.5f + pthis->timer * (1.0f / 30));
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x4000, 0x300);

    headDistVertical = (sinf(CLAMP_MAX(pthis->timer * 0.033f, 0.7f) * M_PI) * 32.0f) + 14.0f;

    if (pthis->actor.shape.rot.x < -0x38E3) {
        headDistHorizontal = 0.0f;
    } else if (pthis->actor.shape.rot.x < -0x238E) {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x4000, 0x555);
        headDistHorizontal = Math_CosS(pthis->stemSectionAngle[0]) * 20.0f;
    } else if (pthis->actor.shape.rot.x < -0xE38) {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x5555, 0x555);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x4000, 0x555);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x4000, 0x333);

        headDistHorizontal = 20.0f * (Math_CosS(pthis->stemSectionAngle[0]) + Math_CosS(pthis->stemSectionAngle[1])) +
                             (headDistVertical -
                              20.0f * (-Math_SinS(pthis->stemSectionAngle[0]) - Math_SinS(pthis->stemSectionAngle[1]))) *
                                 Math_CosS(pthis->stemSectionAngle[2]) / -Math_SinS(pthis->stemSectionAngle[2]);
    } else {
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x5555, 0x555);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x5555, 0x333);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x4000, 0x333);

        headDistHorizontal = 20.0f * (Math_CosS(pthis->stemSectionAngle[0]) + Math_CosS(pthis->stemSectionAngle[1])) +
                             (headDistVertical -
                              20.0f * (-Math_SinS(pthis->stemSectionAngle[0]) - Math_SinS(pthis->stemSectionAngle[1]))) *
                                 Math_CosS(pthis->stemSectionAngle[2]) / -Math_SinS(pthis->stemSectionAngle[2]);
    }

    pthis->actor.world.pos.y = pthis->actor.home.pos.y + (headDistVertical * pthis->size);
    xShift = headDistHorizontal * pthis->size * Math_SinS(pthis->actor.shape.rot.y);
    zShift = headDistHorizontal * pthis->size * Math_CosS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.x = pthis->actor.home.pos.x + xShift;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z + zShift;

    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.home.pos, pthis->size * 3.0f, 0, pthis->size * 12.0f,
                             pthis->size * 5.0f, 1, HAHEN_OBJECT_DEFAULT, 0xA, NULL);

    if (pthis->timer == 0) {
        EnDekubaba_SetupWait(pthis);
    }
}

void EnDekubaba_UpdateHeadPosition(EnDekubaba* pthis) {
    f32 horizontalHeadShift = (Math_CosS(pthis->stemSectionAngle[0]) + Math_CosS(pthis->stemSectionAngle[1]) +
                               Math_CosS(pthis->stemSectionAngle[2])) *
                              20.0f;

    pthis->actor.world.pos.x =
        pthis->actor.home.pos.x + Math_SinS(pthis->actor.shape.rot.y) * (horizontalHeadShift * pthis->size);
    pthis->actor.world.pos.y =
        pthis->actor.home.pos.y - (Math_SinS(pthis->stemSectionAngle[0]) + Math_SinS(pthis->stemSectionAngle[1]) +
                                  Math_SinS(pthis->stemSectionAngle[2])) *
                                     20.0f * pthis->size;
    pthis->actor.world.pos.z =
        pthis->actor.home.pos.z + Math_CosS(pthis->actor.shape.rot.y) * (horizontalHeadShift * pthis->size);
}

void EnDekubaba_DecideLunge(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
        if (pthis->actor.params == DEKUBABA_BIG) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_MOUTH);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_MOUTH);
        }
    }

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_ApproachS(&pthis->actor.shape.rot.y, Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos), 2,
                   (pthis->timer % 5) * 0x222);

    if (pthis->timer < 10) {
        pthis->stemSectionAngle[0] += 0x16C;
        pthis->stemSectionAngle[1] += 0x16C;
        pthis->stemSectionAngle[2] += 0xB6;
        pthis->actor.shape.rot.x += 0x222;
    } else if (pthis->timer < 20) {
        pthis->stemSectionAngle[0] -= 0x16C;
        pthis->stemSectionAngle[1] += 0x111;
        pthis->actor.shape.rot.x += 0x16C;
    } else if (pthis->timer < 30) {
        pthis->stemSectionAngle[1] -= 0x111;
        pthis->actor.shape.rot.x -= 0xB6;
    } else {
        pthis->stemSectionAngle[1] -= 0xB6;
        pthis->stemSectionAngle[2] += 0xB6;
        pthis->actor.shape.rot.x -= 0x16C;
    }

    EnDekubaba_UpdateHeadPosition(pthis);

    if (240.0f * pthis->size < Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos)) {
        EnDekubaba_SetupRetract(pthis);
    } else if ((pthis->timer == 0) || (pthis->actor.xzDistToPlayer < 80.0f * pthis->size)) {
        EnDekubaba_SetupPrepareLunge(pthis);
    }
}

void EnDekubaba_Lunge(EnDekubaba* pthis, GlobalContext* globalCtx) {
    s32 allStepsDone;
    s16 curFrame10;
    Vec3f velocity;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer == 0) {
        if (Animation_OnFrame(&pthis->skelAnime, 1.0f)) {
            if (pthis->actor.params == DEKUBABA_BIG) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_ATTACK);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_ATTACK);
            }
        }

        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x222);

        curFrame10 = pthis->skelAnime.curFrame * 10.0f;

        allStepsDone = true;
        allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0xE38, curFrame10 + 0x38E);
        allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0xE38, curFrame10 + 0x71C);
        allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0xE38, curFrame10 + 0xE38);

        if (allStepsDone) {
            Animation_PlayLoopSetSpeed(&pthis->skelAnime, &gDekuBabaFastChompAnim, 4.0f);
            velocity.x = Math_SinS(pthis->actor.shape.rot.y) * 5.0f;
            velocity.y = 0.0f;
            velocity.z = Math_CosS(pthis->actor.shape.rot.y) * 5.0f;

            func_8002829C(globalCtx, &pthis->actor.world.pos, &velocity, &sZeroVec, &primColor_49, &envColor_49, 1,
                          pthis->size * 100.0f);
            pthis->timer = 1;
            pthis->collider.base.acFlags |= AC_ON;
        }
    } else if (pthis->timer > 10) {
        EnDekubaba_SetupPullBack(pthis);
    } else {
        pthis->timer++;

        if ((pthis->timer >= 4) && !Actor_IsFacingPlayer(&pthis->actor, 0x16C)) {
            Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xF, 0x71C);
        }

        if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
            if (pthis->actor.params == DEKUBABA_BIG) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_MOUTH);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_MOUTH);
            }
        }
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

void EnDekubaba_PrepareLunge(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0x1800, 2, 0xE38, 0x71C);
    Math_ApproachS(&pthis->actor.shape.rot.y, Math_Vec3f_Yaw(&pthis->actor.home.pos, &player->actor.world.pos), 2, 0xE38);
    Math_ScaledStepToS(&pthis->stemSectionAngle[0], 0xAAA, 0x444);
    Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x4718, 0x888);
    Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x6AA4, 0x888);

    if (pthis->timer == 0) {
        EnDekubaba_SetupLunge(pthis);
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

void EnDekubaba_PullBack(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Vec3f dustPos;
    f32 xIncr;
    f32 zIncr;
    s32 i;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer == 0) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x93E, 0x38E);
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x888, 0x16C);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x888, 0x16C);
        if (Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x888, 0x16C)) {
            xIncr = Math_SinS(pthis->actor.shape.rot.y) * 30.0f * pthis->size;
            zIncr = Math_CosS(pthis->actor.shape.rot.y) * 30.0f * pthis->size;
            dustPos = pthis->actor.home.pos;

            for (i = 0; i < 3; i++) {
                func_800286CC(globalCtx, &dustPos, &sZeroVec, &sZeroVec, pthis->size * 500.0f, pthis->size * 50.0f);
                dustPos.x += xIncr;
                dustPos.z += zIncr;
            }

            pthis->timer = 1;
        }
    } else if (pthis->timer == 11) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x93E, 0x200);
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0xAAA, 0x200);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5C71, 0x200);

        if (Math_ScaledStepToS(&pthis->stemSectionAngle[1], 0x238C, 0x200)) {
            pthis->timer = 12;
        }
    } else if (pthis->timer == 18) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x2AA8, 0xAAA);

        if (Math_ScaledStepToS(&pthis->stemSectionAngle[0], 0x1554, 0x5B0)) {
            pthis->timer = 25;
        }

        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x38E3, 0xAAA);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5C71, 0x2D8);
    } else if (pthis->timer == 25) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x5550, 0xAAA);

        if (Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x6388, 0x93E)) {
            pthis->timer = 26;
        }

        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x3FFC, 0x4FA);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x238C, 0x444);
    } else if (pthis->timer == 26) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x1800, 0x93E);

        if (Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x1555, 0x71C)) {
            pthis->timer = 27;
        }

        Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x38E3, 0x2D8);
        Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5C71, 0x5B0);
    } else if (pthis->timer >= 27) {
        pthis->timer++;

        if (pthis->timer > 30) {
            if (pthis->actor.xzDistToPlayer < 80.0f * pthis->size) {
                EnDekubaba_SetupPrepareLunge(pthis);
            } else {
                EnDekubaba_SetupDecideLunge(pthis);
            }
        }
    } else {
        pthis->timer++;

        if (pthis->timer == 10) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_SCRAPE);
        }

        if (pthis->timer >= 12) {
            Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x5C71, 0x88);
        }
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

void EnDekubaba_Recover(EnDekubaba* pthis, GlobalContext* globalCtx) {
    s32 anyStepsDone;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer > 8) {
        anyStepsDone = Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0x1800, 1, 0x11C6, 0x71C);
        anyStepsDone |= Math_SmoothStepToS(&pthis->stemSectionAngle[0], -0x1555, 1, 0xAAA, 0x71C);
        anyStepsDone |= Math_SmoothStepToS(&pthis->stemSectionAngle[1], -0x38E3, 1, 0xE38, 0x71C);
        anyStepsDone |= Math_SmoothStepToS(&pthis->stemSectionAngle[2], -0x5C71, 1, 0x11C6, 0x71C);

        if (!anyStepsDone) {
            pthis->timer = 8;
        }
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }

        if (pthis->timer == 0) {
            EnDekubaba_SetupDecideLunge(pthis);
        }
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

/**
 * Hit by a weapon or hit something when lunging.
 */
void EnDekubaba_Hit(EnDekubaba* pthis, GlobalContext* globalCtx) {
    s32 allStepsDone;

    SkelAnime_Update(&pthis->skelAnime);

    allStepsDone = true;
    allStepsDone &= Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x4000, 0xE38);
    allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[0], -0x4000, 0xE38);
    allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[1], -0x4000, 0xE38);
    allStepsDone &= Math_ScaledStepToS(&pthis->stemSectionAngle[2], -0x4000, 0xE38);

    if (allStepsDone) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnDekubaba_SetupShrinkDie(pthis);
        } else {
            pthis->collider.base.acFlags |= AC_ON;
            if (pthis->timer == 0) {
                if (pthis->actor.xzDistToPlayer < 80.0f * pthis->size) {
                    EnDekubaba_SetupPrepareLunge(pthis);
                } else {
                    EnDekubaba_SetupRecover(pthis);
                }
            } else {
                EnDekubaba_SetupStunnedVertical(pthis);
            }
        }
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

void EnDekubaba_StunnedVertical(EnDekubaba* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        EnDekubaba_DisableHitboxes(pthis);

        if (pthis->actor.xzDistToPlayer < 80.0f * pthis->size) {
            EnDekubaba_SetupPrepareLunge(pthis);
        } else {
            EnDekubaba_SetupRecover(pthis);
        }
    }
}

/**
 * Sway back and forth with decaying amplitude until close enough to vertical.
 */
void EnDekubaba_Sway(EnDekubaba* pthis, GlobalContext* globalCtx) {
    s16 angleToVertical;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, pthis->stemSectionAngle[0], 0x71C);
    Math_ScaledStepToS(&pthis->stemSectionAngle[0], pthis->stemSectionAngle[1], 0x71C);
    Math_ScaledStepToS(&pthis->stemSectionAngle[1], pthis->stemSectionAngle[2], 0x71C);

    if (Math_ScaledStepToS(&pthis->stemSectionAngle[2], pthis->targetSwayAngle, 0x71C)) {
        pthis->targetSwayAngle = -0x4000 - (pthis->targetSwayAngle + 0x4000) * 0.8f;
    }
    angleToVertical = pthis->targetSwayAngle + 0x4000;

    if (ABS(angleToVertical) < 0x100) {
        pthis->collider.base.acFlags |= AC_ON;
        if (pthis->actor.xzDistToPlayer < 80.0f * pthis->size) {
            EnDekubaba_SetupPrepareLunge(pthis);
        } else {
            EnDekubaba_SetupRecover(pthis);
        }
    }

    EnDekubaba_UpdateHeadPosition(pthis);
}

void EnDekubaba_PrunedSomersault(EnDekubaba* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f dustPos;
    f32 deltaX;
    f32 deltaZ;
    f32 deltaY;

    Math_StepToF(&pthis->actor.speedXZ, 0.0f, pthis->size * 0.1f);

    if (pthis->timer == 0) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x4800, 0x71C);
        Math_ScaledStepToS(&pthis->stemSectionAngle[0], 0x4800, 0x71C);
        Math_ScaledStepToS(&pthis->stemSectionAngle[1], 0x4800, 0x71C);

        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, pthis->size * 3.0f, 0, pthis->size * 12.0f,
                                 pthis->size * 5.0f, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);

        if ((pthis->actor.scale.x > 0.005f) && ((pthis->actor.bgCheckFlags & 2) || (pthis->actor.bgCheckFlags & 8))) {
            pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z = 0.0f;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
            EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, pthis->size * 3.0f, 0, pthis->size * 12.0f,
                                     pthis->size * 5.0f, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        }

        if (pthis->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
            pthis->timer = 1;
        }
    } else if (pthis->timer == 1) {
        dustPos = pthis->actor.world.pos;

        deltaY = 20.0f * Math_SinS(pthis->actor.shape.rot.x);
        deltaX = -20.0f * Math_CosS(pthis->actor.shape.rot.x) * Math_SinS(pthis->actor.shape.rot.y);
        deltaZ = -20.0f * Math_CosS(pthis->actor.shape.rot.x) * Math_CosS(pthis->actor.shape.rot.y);

        for (i = 0; i < 4; i++) {
            func_800286CC(globalCtx, &dustPos, &sZeroVec, &sZeroVec, 500, 50);
            dustPos.x += deltaX;
            dustPos.y += deltaY;
            dustPos.z += deltaZ;
        }

        func_800286CC(globalCtx, &pthis->actor.home.pos, &sZeroVec, &sZeroVec, pthis->size * 500.0f, pthis->size * 100.0f);
        EnDekubaba_SetupDeadStickDrop(pthis, globalCtx);
    }
}

/**
 * Die and drop Deku Nuts (Stick drop is handled elsewhere)
 */
void EnDekubaba_ShrinkDie(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, pthis->size * 5.0f);

    if (Math_StepToF(&pthis->actor.scale.x, pthis->size * 0.1f * 0.01f, pthis->size * 0.1f * 0.01f)) {
        func_800286CC(globalCtx, &pthis->actor.home.pos, &sZeroVec, &sZeroVec, pthis->size * 500.0f, pthis->size * 100.0f);
        if (pthis->actor.dropFlag == 0) {
            Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_NUTS);

            if (pthis->actor.params == DEKUBABA_BIG) {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_NUTS);
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_NUTS);
            }
        } else {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x30);
        }
        Actor_Kill(&pthis->actor);
    }

    pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;
    pthis->actor.shape.rot.z += 0x1C70;
    EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.home.pos, pthis->size * 3.0f, 0, pthis->size * 12.0f,
                             pthis->size * 5.0f, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);
}

void EnDekubaba_DeadStickDrop(EnDekubaba* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (Actor_HasParent(&pthis->actor, globalCtx) || (pthis->timer == 0)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    func_8002F554(&pthis->actor, globalCtx, GI_STICKS_1);
}

// Update and associated functions

void EnDekubaba_UpdateDamage(EnDekubaba* pthis, GlobalContext* globalCtx) {
    Vec3f* firePos;
    f32 fireScale;
    s32 phi_s0; // Used for both health and iterator

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlagJntSph(&pthis->actor, &pthis->collider, 1);

        if ((pthis->collider.base.colType != COLTYPE_HARD) &&
            ((pthis->actor.colChkInfo.damageEffect != DEKUBABA_DMGEFF_NONE) || (pthis->actor.colChkInfo.damage != 0))) {

            phi_s0 = pthis->actor.colChkInfo.health - pthis->actor.colChkInfo.damage;

            if (pthis->actionFunc != EnDekubaba_StunnedVertical) {
                if ((pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_BOOMERANG) ||
                    (pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_DEKUNUT)) {
                    if (pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_BOOMERANG) {
                        phi_s0 = pthis->actor.colChkInfo.health;
                    }

                    EnDekubaba_SetupHit(pthis, 2);
                } else if (pthis->actionFunc == EnDekubaba_PullBack) {
                    if (phi_s0 <= 0) {
                        phi_s0 = 1;
                    }

                    EnDekubaba_SetupHit(pthis, 1);
                } else {
                    EnDekubaba_SetupHit(pthis, 0);
                }
            } else if ((pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_BOOMERANG) ||
                       (pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_SWORD)) {
                if (phi_s0 > 0) {
                    EnDekubaba_SetupSway(pthis);
                } else {
                    EnDekubaba_SetupPrunedSomersault(pthis);
                }
            } else if (pthis->actor.colChkInfo.damageEffect != DEKUBABA_DMGEFF_DEKUNUT) {
                EnDekubaba_SetupHit(pthis, 0);
            } else {
                return;
            }

            pthis->actor.colChkInfo.health = CLAMP_MIN(phi_s0, 0);

            if (pthis->actor.colChkInfo.damageEffect == DEKUBABA_DMGEFF_FIRE) {
                firePos = &pthis->actor.world.pos;
                fireScale = (pthis->size * 70.0f);

                for (phi_s0 = 0; phi_s0 < 4; phi_s0++) {
                    EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, firePos, fireScale, 0, 0, phi_s0);
                }
            }
        } else {
            return;
        }
    } else if ((globalCtx->actorCtx.unk_02 != 0) && (pthis->collider.base.colType != COLTYPE_HARD) &&
               (pthis->actionFunc != EnDekubaba_StunnedVertical) && (pthis->actionFunc != EnDekubaba_Hit) &&
               (pthis->actor.colChkInfo.health != 0)) {
        pthis->actor.colChkInfo.health--;
        pthis->actor.dropFlag = 0x00;
        EnDekubaba_SetupHit(pthis, 1);
    } else {
        return;
    }

    if (pthis->actor.colChkInfo.health != 0) {
        if (pthis->timer == 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_DAMAGE);
        }
    } else {
        Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
        if (pthis->actor.params == DEKUBABA_BIG) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_DEAD);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DEKU_JR_DEAD);
        }
    }
}

void EnDekubaba_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDekubaba* pthis = (EnDekubaba*)thisx;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        EnDekubaba_SetupRecover(pthis);
    }

    EnDekubaba_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actionFunc == EnDekubaba_PrunedSomersault) {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, pthis->size * 15.0f, 10.0f, 5);
    } else if (pthis->actionFunc != EnDekubaba_DeadStickDrop) {
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
        if (pthis->boundFloor == NULL) {
            pthis->boundFloor = pthis->actor.floorPoly;
        }
    }
    if (pthis->actionFunc == EnDekubaba_Lunge) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        pthis->actor.flags |= ACTOR_FLAG_24;
    }

    if (pthis->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->actionFunc != EnDekubaba_DeadStickDrop) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

// Draw functions

void EnDekubaba_DrawStemRetracted(EnDekubaba* pthis, GlobalContext* globalCtx) {
    f32 horizontalScale;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2445);

    horizontalScale = pthis->size * 0.01f;

    Matrix_Translate(pthis->actor.home.pos.x, pthis->actor.home.pos.y + (-6.0f * pthis->size), pthis->actor.home.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateZYX(pthis->stemSectionAngle[0], pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
    Matrix_Scale(horizontalScale, horizontalScale, horizontalScale, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2461),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDekuBabaStemTopDL);

    Actor_SetFocus(&pthis->actor, 0.0f);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2468);
}

void EnDekubaba_DrawStemExtended(EnDekubaba* pthis, GlobalContext* globalCtx) {
    MtxF mtx;
    s32 i;
    f32 horizontalStepSize;
    f32 spA4;
    f32 scale;
    s32 stemSections;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2487);

    if (pthis->actionFunc == EnDekubaba_PrunedSomersault) {
        stemSections = 2;
    } else {
        stemSections = 3;
    }

    scale = pthis->size * 0.01f;
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_Get(&mtx);
    if (pthis->actor.colorFilterTimer != 0) {
        spA4 = pthis->size * 20.0f;
        pthis->bodyPartsPos[2].x = pthis->actor.world.pos.x;
        pthis->bodyPartsPos[2].y = pthis->actor.world.pos.y - spA4;
        pthis->bodyPartsPos[2].z = pthis->actor.world.pos.z;
    }

    for (i = 0; i < stemSections; i++) {
        mtx.yw += 20.0f * Math_SinS(pthis->stemSectionAngle[i]) * pthis->size;
        horizontalStepSize = 20.0f * Math_CosS(pthis->stemSectionAngle[i]) * pthis->size;
        mtx.xw -= horizontalStepSize * Math_SinS(pthis->actor.shape.rot.y);
        mtx.zw -= horizontalStepSize * Math_CosS(pthis->actor.shape.rot.y);

        Matrix_Put(&mtx);
        Matrix_RotateZYX(pthis->stemSectionAngle[i], pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2533),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPDisplayList(POLY_OPA_DISP++, stemDLists_55[i]);

        Collider_UpdateSpheres(51 + 2 * i, &pthis->collider);
        Collider_UpdateSpheres(52 + 2 * i, &pthis->collider);

        if (i == 0) {
            if (pthis->actionFunc != EnDekubaba_Sway) {
                pthis->actor.focus.pos.x = mtx.xw;
                pthis->actor.focus.pos.y = mtx.yw;
                pthis->actor.focus.pos.z = mtx.zw;
            } else {
                pthis->actor.focus.pos.x = pthis->actor.home.pos.x;
                pthis->actor.focus.pos.y = pthis->actor.home.pos.y + (40.0f * pthis->size);
                pthis->actor.focus.pos.z = pthis->actor.home.pos.z;
            }
        }

        if ((i < 2) && (pthis->actor.colorFilterTimer != 0)) {
            // checking colorFilterTimer ensures that spA4 has been initialized earlier, so not a bug
            pthis->bodyPartsPos[i].x = mtx.xw;
            pthis->bodyPartsPos[i].y = mtx.yw - spA4;
            pthis->bodyPartsPos[i].z = mtx.zw;
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2569);
}

void EnDekubaba_DrawStemBasePruned(EnDekubaba* pthis, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2579);

    Matrix_RotateZYX(pthis->stemSectionAngle[2], pthis->actor.shape.rot.y, 0, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2586),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDekuBabaStemBaseDL);

    Collider_UpdateSpheres(55, &pthis->collider);
    Collider_UpdateSpheres(56, &pthis->collider);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2596);
}

void EnDekubaba_DrawBaseShadow(EnDekubaba* pthis, GlobalContext* globalCtx) {
    MtxF mtx;
    f32 horizontalScale;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2692);
    func_80094044(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, 255);

    func_80038A28(pthis->boundFloor, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, &mtx);
    Matrix_Mult(&mtx, MTXMODE_NEW);

    horizontalScale = pthis->size * 0.15f;
    Matrix_Scale(horizontalScale, 1.0f, horizontalScale, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2710),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gCircleShadowDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2715);
}

void EnDekubaba_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnDekubaba* pthis = (EnDekubaba*)thisx;

    if (limbIndex == 1) {
        Collider_UpdateSpheres(limbIndex, &pthis->collider);
    }
}

void EnDekubaba_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDekubaba* pthis = (EnDekubaba*)thisx;
    f32 scale;

    if (1) {}
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2752);
    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->actionFunc != EnDekubaba_DeadStickDrop) {
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL,
                          EnDekubaba_PostLimbDraw, pthis);

        if (pthis->actionFunc == EnDekubaba_Wait) {
            EnDekubaba_DrawStemRetracted(pthis, globalCtx);
        } else {
            EnDekubaba_DrawStemExtended(pthis, globalCtx);
        }

        scale = pthis->size * 0.01f;
        Matrix_Translate(pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, MTXMODE_NEW);
        Matrix_RotateY(pthis->actor.home.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2780),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gDekuBabaBaseLeavesDL);

        if (pthis->actionFunc == EnDekubaba_PrunedSomersault) {
            EnDekubaba_DrawStemBasePruned(pthis, globalCtx);
        }

        if (pthis->boundFloor != NULL) {
            EnDekubaba_DrawBaseShadow(pthis, globalCtx);
        }

        // Display solid until 40 frames left, then blink until killed.
    } else if ((pthis->timer > 40) || ((pthis->timer % 2) != 0)) {
        Matrix_Translate(0.0f, 0.0f, 200.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2797),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gDekuBabaStickDropDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dekubaba.c", 2804);
}


void EnDekubaba_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    primColor_49 = { 105, 255, 105, 255 };

    envColor_49 = { 150, 250, 150, 0 };

    sZeroVec = { 0.0f, 0.0f, 0.0f };

    En_Dekubaba_InitVars = {
        ACTOR_EN_DEKUBABA,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_DEKUBABA,
        sizeof(EnDekubaba),
        (ActorFunc)EnDekubaba_Init,
        (ActorFunc)EnDekubaba_Destroy,
        (ActorFunc)EnDekubaba_Update,
        (ActorFunc)EnDekubaba_Draw,
        (ActorFunc)EnDekubaba_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_HIT6,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        7,
        sJntSphElementsInit,
    };

    sColChkInfoInit = { 2, 25, 25, MASS_IMMOVABLE };

    sDekuBabaDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
        /* Deku stick    */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(1, DEKUBABA_DMGEFF_NONE),
        /* Explosive     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_BOOMERANG),
        /* Normal arrow  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Hookshot      */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Kokiri sword  */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
        /* Master sword  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Giant's Knife */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Fire arrow    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
        /* Ice arrow     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Light arrow   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 1   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
        /* Ice magic     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Light magic   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Shield        */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
        /* Giant spin    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Master spin   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Kokiri jump   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Giant jump    */ DMG_ENTRY(8, DEKUBABA_DMGEFF_SWORD),
        /* Master jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Unknown 1     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    };

    sBigDekuBabaDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
        /* Deku stick    */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Slingshot     */ DMG_ENTRY(1, DEKUBABA_DMGEFF_NONE),
        /* Explosive     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Boomerang     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_BOOMERANG),
        /* Normal arrow  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Hammer swing  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Hookshot      */ DMG_ENTRY(0, DEKUBABA_DMGEFF_DEKUNUT),
        /* Kokiri sword  */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
        /* Master sword  */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Giant's Knife */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Fire arrow    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
        /* Ice arrow     */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Light arrow   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 1   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 2   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Unk arrow 3   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_NONE),
        /* Fire magic    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_FIRE),
        /* Ice magic     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Light magic   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Shield        */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Mirror Ray    */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Kokiri spin   */ DMG_ENTRY(1, DEKUBABA_DMGEFF_SWORD),
        /* Giant spin    */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Master spin   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Kokiri jump   */ DMG_ENTRY(2, DEKUBABA_DMGEFF_SWORD),
        /* Giant jump    */ DMG_ENTRY(8, DEKUBABA_DMGEFF_SWORD),
        /* Master jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_SWORD),
        /* Unknown 1     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Unblockable   */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
        /* Hammer jump   */ DMG_ENTRY(4, DEKUBABA_DMGEFF_NONE),
        /* Unknown 2     */ DMG_ENTRY(0, DEKUBABA_DMGEFF_NONE),
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DODONGO_Z_EN_DODONGO_C
#include "actor_common.h"
#include "z_en_dodongo.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "overlays/actors/ovl_En_Bombf/z_en_bombf.h"
#include "objects/object_dodongo/object_dodongo.h"
#include "def/code_800FD970.h"
#include "def/sys_math.h"
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


void EnDodongo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDodongo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDodongo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDodongo_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDodongo_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDodongo_SetupDeath(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_ShiftVecRadial(s16 yaw, f32 radius, Vec3f* vec);
s32 EnDodongo_AteBomb(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_SetupIdle(EnDodongo* pthis);

void EnDodongo_Idle(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_EndBreatheFire(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_BreatheFire(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_SwallowBomb(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_Walk(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_Stunned(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_Death(EnDodongo* pthis, GlobalContext* globalCtx);
void EnDodongo_SweepTail(EnDodongo* pthis, GlobalContext* globalCtx);

static Vec3f legOffsets_69[3] = {
    { 1100.0f, -700.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 2190.0f, 0.0f, 0.0f },
};


ActorInit En_Dodongo_InitVars = {
    ACTOR_EN_DODONGO,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_DODONGO,
    sizeof(EnDodongo),
    (ActorFunc)EnDodongo_Init,
    (ActorFunc)EnDodongo_Destroy,
    (ActorFunc)EnDodongo_Update,
    (ActorFunc)EnDodongo_Draw,
    (ActorFunc)EnDodongo_Reset,
};

static ColliderJntSphElementInit sBodyElementsInit[6] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 15, { { 0, 0, 0 }, 17 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 14, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 13, { { 0, 0, 0 }, 10 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 21, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 28, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x0D800691, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON | OCELEM_UNK3,
        },
        { 6, { { 0, 0, 0 }, 35 }, 100 },
    },
};

static ColliderJntSphInit sBodyJntSphInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    6,
    sBodyElementsInit,
};

static ColliderTrisElementInit sHardElementsInit[3] = {
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xF24BF96E, 0x00, 0x00 },
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
            { 0xFFCBF96E, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
    {
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCBF96E, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON | BUMP_HOOKABLE | BUMP_NO_AT_INFO,
            OCELEM_NONE,
        },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
};

static ColliderTrisInit sHardTrisInit = {
    {
        COLTYPE_METAL,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_TRIS,
    },
    3,
    sHardElementsInit,
};

static ColliderQuadInit sAttackQuadInit = {
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
        { 0x20000000, 0x01, 0x10 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(1, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x1),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(4, 0xF),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x6),
    /* Ice magic     */ DMG_ENTRY(3, 0xF),
    /* Light magic   */ DMG_ENTRY(0, 0x6),
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

void EnDodongo_SetupAction(EnDodongo* pthis, EnDodongoActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnDodongo_SpawnBombSmoke(EnDodongo* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };
    Vec3f pos = pthis->headPos;
    s16 randAngle = Rand_CenteredFloat(0x4000);
    f32 randCos;
    f32 randSin;

    randCos = Math_CosS(pthis->actor.shape.rot.y + randAngle);
    randSin = Math_SinS(pthis->actor.shape.rot.y + randAngle);
    if (pthis->bombSmokePrimColor.r > 30) {
        pthis->bombSmokePrimColor.r -= 16;
        pthis->bombSmokePrimColor.g -= 16;
    }

    if (pthis->bombSmokePrimColor.b < 30) {
        pthis->bombSmokePrimColor.b += 5;
        pthis->bombSmokePrimColor.a += 8;
        pthis->bombSmokeEnvColor.a += 8;
    }
    if (pthis->bombSmokeEnvColor.r != 0) {
        pthis->bombSmokeEnvColor.r -= 15;
    }
    if (pthis->bombSmokeEnvColor.g != 0) {
        pthis->bombSmokeEnvColor.g--;
    }
    velocity.x = randSin * 3.5f;
    velocity.y = pthis->bombSmokeEnvColor.r * 0.02f;
    velocity.z = randCos * 3.5f;
    accel.x = ((Rand_ZeroOne() * 0.1f) + 0.15f) * -randSin;
    accel.z = ((Rand_ZeroOne() * 0.1f) + 0.15f) * -randCos;
    func_8002836C(globalCtx, &pos, &velocity, &accel, &pthis->bombSmokePrimColor, &pthis->bombSmokeEnvColor, 100, 25, 20);

    randAngle = Rand_ZeroOne() * 0x2000;
    randCos = Math_CosS(pthis->actor.shape.rot.y + randAngle);
    randSin = Math_SinS(pthis->actor.shape.rot.y + randAngle);
    pos.x -= randCos * 6.0f;
    pos.z += randSin * 6.0f;
    velocity.x = -randCos * 3.5f;
    velocity.y = pthis->bombSmokeEnvColor.r * 0.02f;
    velocity.z = randSin * 3.5f;
    accel.x = ((Rand_ZeroOne() * 0.1f) + 0.15f) * randCos;
    accel.z = ((Rand_ZeroOne() * 0.1f) + 0.15f) * -randSin;
    func_8002836C(globalCtx, &pos, &velocity, &accel, &pthis->bombSmokePrimColor, &pthis->bombSmokeEnvColor, 100, 25, 20);

    randAngle = Rand_ZeroOne() * 0x2000;
    randCos = Math_CosS(pthis->actor.shape.rot.y + randAngle);
    randSin = Math_SinS(pthis->actor.shape.rot.y + randAngle);

    pos.x = pthis->headPos.x + (randCos * 6.0f);
    pos.z = pthis->headPos.z - (randSin * 6.0f);
    velocity.x = randCos * 3.5f;
    velocity.y = pthis->bombSmokeEnvColor.r * 0.02f;
    velocity.z = -randSin * 3.5f;
    accel.x = ((Rand_ZeroOne() * 0.1f) + 0.15f) * -randCos;
    accel.z = ((Rand_ZeroOne() * 0.1f) + 0.15f) * randSin;
    func_8002836C(globalCtx, &pos, &velocity, &accel, &pthis->bombSmokePrimColor, &pthis->bombSmokeEnvColor, 100, 25, 20);
}

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x0D, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -1000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2800, ICHAIN_STOP),
};

void EnDodongo_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDodongo* pthis = (EnDodongo*)thisx;
    EffectBlureInit1 blureInit;

    pthis->actor.targetMode = 3;
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->bombSmokePrimColor.r = pthis->bombSmokePrimColor.g = pthis->bombSmokeEnvColor.r = 255;
    pthis->bombSmokePrimColor.a = pthis->bombSmokeEnvColor.a = 200;
    pthis->bombSmokeEnvColor.g = 10;
    pthis->bodyScale.x = pthis->bodyScale.y = pthis->bodyScale.z = 1.0f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 48.0f);
    Actor_SetScale(&pthis->actor, 0.01875f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDodongoSkel, &gDodongoWaitAnim, pthis->jointTable, pthis->morphTable,
                   31);
    pthis->actor.colChkInfo.health = 4;
    pthis->actor.colChkInfo.mass = MASS_HEAVY;
    pthis->actor.colChkInfo.damageTable = &sDamageTable;
    Collider_InitQuad(globalCtx, &pthis->colliderAT);
    Collider_InitTris(globalCtx, &pthis->colliderHard);
    Collider_InitJntSph(globalCtx, &pthis->colliderBody);
    Collider_SetQuad(globalCtx, &pthis->colliderAT, &pthis->actor, &sAttackQuadInit);
    Collider_SetTris(globalCtx, &pthis->colliderHard, &pthis->actor, &sHardTrisInit, pthis->trisElements);
    Collider_SetJntSph(globalCtx, &pthis->colliderBody, &pthis->actor, &sBodyJntSphInit, pthis->sphElements);

    blureInit.p1StartColor[0] = blureInit.p1StartColor[1] = blureInit.p1StartColor[2] = blureInit.p1StartColor[3] =
        blureInit.p2StartColor[0] = blureInit.p2StartColor[1] = blureInit.p2StartColor[2] = blureInit.p1EndColor[0] =
            blureInit.p1EndColor[1] = blureInit.p1EndColor[2] = blureInit.p2EndColor[0] = blureInit.p2EndColor[1] =
                blureInit.p2EndColor[2] = 255;

    blureInit.p1EndColor[3] = blureInit.p2EndColor[3] = 0;
    blureInit.p2StartColor[3] = 64;
    blureInit.elemDuration = 8;
    blureInit.unkFlag = false;
    blureInit.calcMode = 2;

    Effect_Add(globalCtx, &pthis->blureIdx, EFFECT_BLURE1, 0, 0, &blureInit);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 60.0f, 70.0f, 0x1D);
    EnDodongo_SetupIdle(pthis);
}

void EnDodongo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDodongo* pthis = (EnDodongo*)thisx;

    Effect_Delete(globalCtx, pthis->blureIdx);
    Collider_DestroyTris(globalCtx, &pthis->colliderHard);
    Collider_DestroyJntSph(globalCtx, &pthis->colliderBody);
    Collider_DestroyQuad(globalCtx, &pthis->colliderAT);
}

void EnDodongo_SetupIdle(EnDodongo* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gDodongoWaitAnim, -4.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->timer = Rand_S16Offset(30, 50);
    pthis->actionState = DODONGO_IDLE;
    EnDodongo_SetupAction(pthis, EnDodongo_Idle);
}

void EnDodongo_SetupWalk(EnDodongo* pthis) {
    f32 frames = Animation_GetLastFrame(&gDodongoWalkAnim);

    Animation_Change(&pthis->skelAnime, &gDodongoWalkAnim, 0.0f, 0.0f, frames, ANIMMODE_LOOP, -4.0f);
    pthis->actor.speedXZ = 1.5f;
    pthis->timer = Rand_S16Offset(50, 70);
    pthis->rightFootStep = true;
    pthis->actionState = DODONGO_WALK;
    EnDodongo_SetupAction(pthis, EnDodongo_Walk);
}

void EnDodongo_SetupBreatheFire(EnDodongo* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDodongoBreatheFireAnim, -4.0f);
    pthis->actionState = DODONGO_BREATHE_FIRE;
    pthis->actor.speedXZ = 0.0f;
    EnDodongo_SetupAction(pthis, EnDodongo_BreatheFire);
}

void EnDodongo_SetupEndBreatheFire(EnDodongo* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gDodongoAfterBreatheFireAnim);
    pthis->actionState = DODONGO_END_BREATHE_FIRE;
    pthis->actor.speedXZ = 0.0f;
    EnDodongo_SetupAction(pthis, EnDodongo_EndBreatheFire);
}

void EnDodongo_SetupSwallowBomb(EnDodongo* pthis) {
    Animation_Change(&pthis->skelAnime, &gDodongoBreatheFireAnim, -1.0f, 35.0f, 0.0f, ANIMMODE_ONCE, -4.0f);
    pthis->actionState = DODONGO_SWALLOW_BOMB;
    pthis->timer = 25;
    pthis->actor.speedXZ = 0.0f;
    EnDodongo_SetupAction(pthis, EnDodongo_SwallowBomb);
}

void EnDodongo_SetupStunned(EnDodongo* pthis) {
    Animation_Change(&pthis->skelAnime, &gDodongoBreatheFireAnim, 0.0f, 25.0f, 0.0f, ANIMMODE_ONCE, -4.0f);
    pthis->actionState = DODONGO_STUNNED;
    pthis->actor.speedXZ = 0.0f;
    if (pthis->damageEffect == 0xF) {
        pthis->iceTimer = 36;
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    EnDodongo_SetupAction(pthis, EnDodongo_Stunned);
}

void EnDodongo_Idle(EnDodongo* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((DECR(pthis->timer) == 0) && Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        EnDodongo_SetupWalk(pthis);
    }
}

void EnDodongo_EndBreatheFire(EnDodongo* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDodongo_SetupIdle(pthis);
        pthis->timer = Rand_S16Offset(10, 20);
    }
}

void EnDodongo_BreatheFire(EnDodongo* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    s16 pad2;
    s16 fireFrame;

    if ((s32)pthis->skelAnime.curFrame == 24) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_CRY);
    }
    if ((29.0f <= pthis->skelAnime.curFrame) && (pthis->skelAnime.curFrame <= 43.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_FIRE - SFX_FLAG);
        fireFrame = pthis->skelAnime.curFrame - 29.0f;
        pos = pthis->actor.world.pos;
        pos.y += 35.0f;
        EnDodongo_ShiftVecRadial(pthis->actor.world.rot.y, 30.0f, &pos);
        EnDodongo_ShiftVecRadial(pthis->actor.world.rot.y, 2.5f, &accel);
        EffectSsDFire_SpawnFixedScale(globalCtx, &pos, &velocity, &accel, 255 - (fireFrame * 10), fireFrame + 3);
    } else if ((2.0f <= pthis->skelAnime.curFrame) && (pthis->skelAnime.curFrame <= 20.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_BREATH - SFX_FLAG);
    }
    if (SkelAnime_Update(&pthis->skelAnime)) {
        EnDodongo_SetupEndBreatheFire(pthis);
    }
}

void EnDodongo_SwallowBomb(EnDodongo* pthis, GlobalContext* globalCtx) {
    Vec3f smokeVel = { 0.0f, 0.0f, 0.0f };
    Vec3f smokeAccel = { 0.0f, 0.6f, 0.0f };
    Color_RGBA8 white = { 255, 255, 255, 255 };
    Vec3f deathFireVel = { 0.0f, 0.0f, 0.0f };
    Vec3f deathFireAccel = { 0.0f, 1.0f, 0.0f };
    s16 i;
    Vec3f pos;
    s32 pad;

    if (pthis->actor.child != NULL) {
        pthis->actor.child->world.pos = pthis->mouthPos;
        ((EnBom*)pthis->actor.child)->timer++;
    } else if (pthis->actor.parent != NULL) {
        pthis->actor.parent->world.pos = pthis->mouthPos;
        ((EnBombf*)pthis->actor.parent)->timer++;
        //! @bug An explosive can also be a bombchu, not always a bomb, which leads to a serious bug. ->timer (0x1F8) is
        //! outside the bounds of the bombchu actor, and the memory it writes to happens to be one of the pointers in
        //! the next arena node. When pthis value is written to, massive memory corruption occurs.
    }

    if ((s32)pthis->skelAnime.curFrame == 28) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_EAT);
        if (pthis->actor.child != NULL) {
            Actor_Kill(pthis->actor.child);
            pthis->actor.child = NULL;
        } else if (pthis->actor.parent != NULL) {
            Actor_Kill(pthis->actor.parent);
            pthis->actor.parent = NULL;
        }
    } else if ((s32)pthis->skelAnime.curFrame == 24) {
        pthis->timer--;
        if (pthis->timer != 0) {
            pthis->skelAnime.curFrame++;
            if (pthis->timer == 10) {
                for (i = 10; i >= 0; i--) {
                    deathFireVel.x = Rand_CenteredFloat(10.0f);
                    deathFireVel.y = Rand_CenteredFloat(10.0f);
                    deathFireVel.z = Rand_CenteredFloat(10.0f);
                    deathFireAccel.x = deathFireVel.x * -0.1f;
                    deathFireAccel.y = deathFireVel.y * -0.1f;
                    deathFireAccel.z = deathFireVel.z * -0.1f;
                    pos.x = pthis->sphElements[0].dim.worldSphere.center.x + deathFireVel.x;
                    pos.y = pthis->sphElements[0].dim.worldSphere.center.y + deathFireVel.y;
                    pos.z = pthis->sphElements[0].dim.worldSphere.center.z + deathFireVel.z;
                    func_8002836C(globalCtx, &pos, &deathFireVel, &deathFireAccel, &pthis->bombSmokePrimColor,
                                  &pthis->bombSmokeEnvColor, 400, 10, 10);
                }
                Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_BOMB_EXPLOSION);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0x78, 0, 8);
            }
        }
    }
    if ((s32)pthis->skelAnime.curFrame < 28) {
        if (((s32)pthis->skelAnime.curFrame < 26) && (pthis->timer <= 10)) {
            EnDodongo_SpawnBombSmoke(pthis, globalCtx);
        } else {
            pos = pthis->headPos;
            func_8002829C(globalCtx, &pos, &smokeVel, &smokeAccel, &white, &white, 50, 5);
            pos.x -= (Math_CosS(pthis->actor.shape.rot.y) * 6.0f);
            pos.z += (Math_SinS(pthis->actor.shape.rot.y) * 6.0f);
            func_8002829C(globalCtx, &pos, &smokeVel, &smokeAccel, &white, &white, 50, 5);
            pos.x = pthis->headPos.x + (Math_CosS(pthis->actor.shape.rot.y) * 6.0f);
            pos.z = pthis->headPos.z - (Math_SinS(pthis->actor.shape.rot.y) * 6.0f);
            func_8002829C(globalCtx, &pos, &smokeVel, &smokeAccel, &white, &white, 50, 5);
        }
    }
    pthis->bodyScale.y = pthis->bodyScale.z = (Math_SinS(pthis->actor.colorFilterTimer * 0x1000) * 0.5f) + 1.0f;
    pthis->bodyScale.x = Math_SinS(pthis->actor.colorFilterTimer * 0x1000) + 1.0f;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer == 0) {
        EnDodongo_SetupDeath(pthis, globalCtx);
    }
}

void EnDodongo_Walk(EnDodongo* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 playbackSpeed;
    Player* player = GET_PLAYER(globalCtx);
    s16 yawDiff = (s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y);

    yawDiff = ABS(yawDiff);

    Math_SmoothStepToF(&pthis->actor.speedXZ, 1.5f, 0.1f, 1.0f, 0.0f);

    playbackSpeed = pthis->actor.speedXZ * 0.75f;
    if (pthis->actor.speedXZ >= 0.0f) {
        if (playbackSpeed > 3.0f / 2) {
            playbackSpeed = 3.0f / 2;
        }
    } else {
        if (playbackSpeed < -3.0f / 2) {
            playbackSpeed = -3.0f / 2;
        }
    }
    pthis->skelAnime.playSpeed = playbackSpeed;

    SkelAnime_Update(&pthis->skelAnime);
    if ((s32)pthis->skelAnime.curFrame < 21) {
        if (!pthis->rightFootStep) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_WALK);
            Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->leftFootPos, 10.0f, 3, 2.0f, 0xC8, 0xF, 0);
            pthis->rightFootStep = true;
        }
    } else {
        if (pthis->rightFootStep) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_WALK);
            Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->rightFootPos, 10.0f, 3, 2.0f, 0xC8, 0xF, 0);
            pthis->rightFootStep = false;
        }
    }

    if (Math_Vec3f_DistXZ(&pthis->actor.home.pos, &player->actor.world.pos) < 400.0f) {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1, 0x1F4, 0);
        pthis->actor.flags |= ACTOR_FLAG_0;
        if ((pthis->actor.xzDistToPlayer < 100.0f) && (yawDiff < 0x1388) && (pthis->actor.yDistToPlayer < 60.0f)) {
            EnDodongo_SetupBreatheFire(pthis);
        }
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        if ((Math_Vec3f_DistXZ(&pthis->actor.world.pos, &pthis->actor.home.pos) > 150.0f) || (pthis->retreatTimer != 0)) {
            s16 yawToHome = Math_Vec3f_Yaw(&pthis->actor.world.pos, &pthis->actor.home.pos);

            Math_SmoothStepToS(&pthis->actor.world.rot.y, yawToHome, 1, 0x1F4, 0);
        }
        if (pthis->retreatTimer != 0) {
            pthis->retreatTimer--;
        }
        pthis->timer--;
        if (pthis->timer == 0) {
            if (Rand_ZeroOne() > 0.7f) {
                pthis->timer = Rand_S16Offset(50, 70);
                pthis->retreatTimer = Rand_S16Offset(15, 40);
            } else {
                EnDodongo_SetupIdle(pthis);
            }
        }
    }

    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
}

void EnDodongo_SetupSweepTail(EnDodongo* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDodongoDamageAnim, -4.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_DAMAGE);
    pthis->actionState = DODONGO_SWEEP_TAIL;
    pthis->timer = 0;
    pthis->actor.speedXZ = 0.0f;
    EnDodongo_SetupAction(pthis, EnDodongo_SweepTail);
}

void EnDodongo_SweepTail(EnDodongo* pthis, GlobalContext* globalCtx) {
    s16 yawDiff1 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        if ((pthis->timer != 0) || (ABS(yawDiff1) < 0x4000)) {
            pthis->sphElements[2].info.toucherFlags = TOUCH_NONE;
            pthis->sphElements[1].info.toucherFlags = TOUCH_NONE;
            pthis->colliderBody.base.atFlags = AT_NONE;
            pthis->sphElements[2].info.toucher.dmgFlags = 0;
            pthis->sphElements[1].info.toucher.dmgFlags = 0;
            pthis->sphElements[2].info.toucher.damage = 0;
            pthis->sphElements[1].info.toucher.damage = 0;
            EnDodongo_SetupBreatheFire(pthis);
            pthis->timer = Rand_S16Offset(5, 10);
        } else {
            s16 yawDiff2 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
            AnimationHeader* animation;

            pthis->tailSwipeSpeed = (0xFFFF - ABS(yawDiff2)) / 0xF;
            if ((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) >= 0) {
                pthis->tailSwipeSpeed = -pthis->tailSwipeSpeed;
                animation = &gDodongoSweepTailLeftAnim;
            } else {
                animation = &gDodongoSweepTailRightAnim;
            }
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_TAIL);
            Animation_PlayOnceSetSpeed(&pthis->skelAnime, animation, 2.0f);
            pthis->timer = 18;
            pthis->colliderBody.base.atFlags = pthis->sphElements[1].info.toucherFlags =
                pthis->sphElements[2].info.toucherFlags = AT_ON | AT_TYPE_ENEMY; // also TOUCH_ON | TOUCH_SFX_WOOD
            pthis->sphElements[1].info.toucher.dmgFlags = pthis->sphElements[2].info.toucher.dmgFlags = 0xFFCFFFFF;
            pthis->sphElements[1].info.toucher.damage = pthis->sphElements[2].info.toucher.damage = 8;
        }
    } else if (pthis->timer > 1) {
        Vec3f tailPos;

        pthis->timer--;
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y += pthis->tailSwipeSpeed;
        tailPos.x = pthis->sphElements[1].dim.worldSphere.center.x;
        tailPos.y = pthis->sphElements[1].dim.worldSphere.center.y;
        tailPos.z = pthis->sphElements[1].dim.worldSphere.center.z;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &tailPos, 5.0f, 2, 2.0f, 100, 15, 0);
        tailPos.x = pthis->sphElements[2].dim.worldSphere.center.x;
        tailPos.y = pthis->sphElements[2].dim.worldSphere.center.y;
        tailPos.z = pthis->sphElements[2].dim.worldSphere.center.z;
        Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &tailPos, 5.0f, 2, 2.0f, 100, 15, 0);

        if (pthis->colliderBody.base.atFlags & AT_HIT) {
            Player* player = GET_PLAYER(globalCtx);

            if (pthis->colliderBody.base.at == &player->actor) {
                Audio_PlayActorSound2(&player->actor, NA_SE_PL_BODY_HIT);
            }
        }
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
    }
}

void EnDodongo_SetupDeath(EnDodongo* pthis, GlobalContext* globalCtx) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDodongoDieAnim, -8.0f);
    pthis->timer = 0;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_J_DEAD);
    pthis->actionState = DODONGO_DEATH;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    EnDodongo_SetupAction(pthis, EnDodongo_Death);
}

void EnDodongo_Death(EnDodongo* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    if (pthis->skelAnime.curFrame < 35.0f) {
        if (pthis->actor.params == EN_DODONGO_SMOKE_DEATH) {
            EnDodongo_SpawnBombSmoke(pthis, globalCtx);
        }
    } else if (pthis->actor.colorFilterTimer == 0) {
        Actor_SetColorFilter(&pthis->actor, 0x4000, 0x78, 0, 4);
    }
    if (SkelAnime_Update(&pthis->skelAnime) != 0) {
        if (pthis->timer == 0) {
            bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                       pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 6, BOMB_BODY);
            if (bomb != NULL) {
                bomb->timer = 0;
                pthis->timer = 8;
            }
        }
    } else if ((s32)pthis->skelAnime.curFrame == 52) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
    }
    if (pthis->timer != 0) {
        pthis->timer--;
        if (pthis->timer == 0) {
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x40);
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnDodongo_Stunned(EnDodongo* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.colorFilterTimer == 0) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnDodongo_SetupDeath(pthis, globalCtx);
        } else {
            EnDodongo_SetupIdle(pthis);
        }
    }
}

void EnDodongo_CollisionCheck(EnDodongo* pthis, GlobalContext* globalCtx) {
    if (pthis->colliderHard.base.acFlags & AC_BOUNCED) {
        pthis->colliderHard.base.acFlags &= ~AC_BOUNCED;
        pthis->colliderBody.base.acFlags &= ~AC_HIT;
    } else if ((pthis->colliderBody.base.acFlags & AC_HIT) && (pthis->actionState > DODONGO_DEATH)) {
        pthis->colliderBody.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlagJntSph(&pthis->actor, &pthis->colliderBody, 0);
        if (pthis->actor.colChkInfo.damageEffect != 0xE) {
            pthis->damageEffect = pthis->actor.colChkInfo.damageEffect;
            if ((pthis->actor.colChkInfo.damageEffect == 1) || (pthis->actor.colChkInfo.damageEffect == 0xF)) {
                if (pthis->actionState != DODONGO_STUNNED) {
                    Actor_SetColorFilter(&pthis->actor, 0, 0x78, 0, 0x50);
                    Actor_ApplyDamage(&pthis->actor);
                    EnDodongo_SetupStunned(pthis);
                }
            } else {
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0x78, 0, 8);
                if (Actor_ApplyDamage(&pthis->actor) == 0) {
                    EnDodongo_SetupDeath(pthis, globalCtx);
                } else {
                    EnDodongo_SetupSweepTail(pthis);
                }
            }
        }
    }
}

void EnDodongo_UpdateQuad(EnDodongo* pthis, GlobalContext* globalCtx) {
    Vec3f sp94 = { -1000.0f, -1500.0f, 0.0f };
    Vec3f sp88 = { -1000.0f, -200.0f, 1500.0f };
    Vec3f sp7C = { -1000.0f, -200.0f, -1500.0f };
    Vec3f sp70 = { 0.0f, 0.0f, 0.0f };
    s32 pad4C[9]; // Possibly 3 more Vec3fs?
    s32 a = 0;
    s32 b = 1; // These indices are needed to match.
    s32 c = 2; // Might be a way to quickly test vertex arrangements
    s32 d = 3;
    f32 xMod = Math_SinF((pthis->skelAnime.curFrame - 28.0f) * 0.08f) * 5500.0f;

    sp7C.x -= xMod;
    sp94.x -= xMod;
    sp88.x -= xMod;

    Matrix_MultVec3f(&sp94, &pthis->colliderAT.dim.quad[b]);
    Matrix_MultVec3f(&sp88, &pthis->colliderAT.dim.quad[a]);
    Matrix_MultVec3f(&sp7C, &pthis->colliderAT.dim.quad[d]);
    Matrix_MultVec3f(&sp70, &pthis->colliderAT.dim.quad[c]);

    Collider_SetQuadVertices(&pthis->colliderAT, &pthis->colliderAT.dim.quad[a], &pthis->colliderAT.dim.quad[b],
                             &pthis->colliderAT.dim.quad[c], &pthis->colliderAT.dim.quad[d]);
}

void EnDodongo_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDodongo* pthis = (EnDodongo*)thisx;

    EnDodongo_CollisionCheck(pthis, globalCtx);
    if (pthis->actor.colChkInfo.damageEffect != 0xE) {
        pthis->actionFunc(pthis, globalCtx);
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 60.0f, 70.0f, 0x1D);
        if (pthis->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_RIZA_DOWN);
        }
    }
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
    if (pthis->actionState != DODONGO_DEATH) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderHard.base);
    }
    if (pthis->actionState > DODONGO_DEATH) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
    }
    if ((pthis->actionState >= DODONGO_IDLE) && EnDodongo_AteBomb(pthis, globalCtx)) {
        EnDodongo_SetupSwallowBomb(pthis);
    }
    if (pthis->actionState == DODONGO_BREATHE_FIRE) {
        if ((29.0f < pthis->skelAnime.curFrame) && (pthis->skelAnime.curFrame < 43.0f)) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderAT.base);
        }
    }
    pthis->actor.focus.pos.x = pthis->actor.world.pos.x + Math_SinS(pthis->actor.shape.rot.y) * -30.0f;
    pthis->actor.focus.pos.y = pthis->actor.world.pos.y + 20.0f;
    pthis->actor.focus.pos.z = pthis->actor.world.pos.z + Math_CosS(pthis->actor.shape.rot.y) * -30.0f;
}

s32 EnDodongo_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    EnDodongo* pthis = (EnDodongo*)thisx;

    if ((limbIndex == 15) || (limbIndex == 16)) {
        Matrix_Scale(pthis->bodyScale.x, pthis->bodyScale.y, pthis->bodyScale.z, MTXMODE_APPLY);
    }
    return false;
}

void EnDodongo_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    Vec3f tailTipOffset = { 3000.0f, 0.0f, 0.0f };
    Vec3f baseOffset = { 0.0f, 0.0f, 0.0f };
    s32 i;
    Vec3f hardTris0Vtx[3];
    Vec3f hardTris1Vtx[3];
    Vec3f hardTris2Vtx[3];
    Vec3f tailTip;
    Vec3f tailBase;
    EnDodongo* pthis = (EnDodongo*)thisx;
    Vec3f hardTris0VtxOffset[] = {
        { -300.0f, -2500.0f, 0.0f },
        { -300.0f, 1200.0f, -2700.0f },
        { 3000.0f, 1200.0f, 0.0f },
    };
    Vec3f hardTris1VtxOffset[] = {
        { -300.0f, -2500.0f, 0.0f },
        { -300.0f, 1200.0f, 2700.0f },
        { 3000.0f, 1200.0f, 0.0f },
    };
    Vec3f hardTris2VtxOffset[] = {
        { -600.0f, 1200.0f, -2800.0f },
        { -600.0f, 1200.0f, 2800.0f },
        { 3000.0f, 1200.0f, 0.0f },
    };
    Vec3f mouthOffset = { 1800.0f, 1200.0f, 0.0f };
    Vec3f headOffset = { 1500.0f, 300.0f, 0.0f };

    Collider_UpdateSpheres(limbIndex, &pthis->colliderBody);

    switch (limbIndex) {
        case 2:
            if ((pthis->actionState == DODONGO_BREATHE_FIRE) && (29.0f < pthis->skelAnime.curFrame) &&
                (pthis->skelAnime.curFrame < 43.0f)) {
                EnDodongo_UpdateQuad(pthis, globalCtx);
            }
            break;
        case 7:
            for (i = 0; i < 3; i++) {
                Matrix_MultVec3f(&hardTris0VtxOffset[i], &hardTris0Vtx[i]);
                Matrix_MultVec3f(&hardTris1VtxOffset[i], &hardTris1Vtx[i]);
                Matrix_MultVec3f(&hardTris2VtxOffset[i], &hardTris2Vtx[i]);
            }
            Collider_SetTrisVertices(&pthis->colliderHard, 0, &hardTris0Vtx[0], &hardTris0Vtx[1], &hardTris0Vtx[2]);
            Collider_SetTrisVertices(&pthis->colliderHard, 1, &hardTris1Vtx[0], &hardTris1Vtx[1], &hardTris1Vtx[2]);
            Collider_SetTrisVertices(&pthis->colliderHard, 2, &hardTris2Vtx[0], &hardTris2Vtx[1], &hardTris2Vtx[2]);
            Matrix_MultVec3f(&mouthOffset, &pthis->mouthPos);
            Matrix_MultVec3f(&headOffset, &pthis->headPos);
            break;
        case 15:
            if ((pthis->actionState == DODONGO_SWEEP_TAIL) && (pthis->timer >= 2)) {
                Matrix_MultVec3f(&tailTipOffset, &tailTip);
                Matrix_MultVec3f(&baseOffset, &tailBase);
                EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blureIdx), &tailTip, &tailBase);
            } else if ((pthis->actionState == DODONGO_SWEEP_TAIL) && (pthis->timer != 0)) {
                EffectBlure_AddSpace((EffectBlure*)Effect_GetByIndex(pthis->blureIdx));
            }
            break;
        case 21:
            Matrix_MultVec3f(&legOffsets_69[1], &pthis->leftFootPos);
            break;
        case 28:
            Matrix_MultVec3f(&legOffsets_69[1], &pthis->rightFootPos);
            break;
    }
    if (pthis->iceTimer != 0) {
        i = -1;
        switch (limbIndex) {
            case 7:
                baseOffset.x = 1200.0f;
                i = 0;
                break;
            case 13:
                i = 1;
                break;
            case 14:
                i = 2;
                break;
            case 15:
                i = 3;
                break;
            case 16:
                i = 4;
                break;
            case 22:
                i = 5;
                break;
            case 29:
                i = 6;
                break;
            case 21:
                i = 7;
                break;
            case 28:
                i = 8;
                break;
        }
        if (i >= 0) {
            Matrix_MultVec3f(&baseOffset, &pthis->icePos[i]);
        }
    }
}

void EnDodongo_Draw(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnDodongo* pthis = (EnDodongo*)thisx;
    s32 index;

    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnDodongo_OverrideLimbDraw,
                      EnDodongo_PostLimbDraw, pthis);

    if (pthis->iceTimer != 0) {
        pthis->actor.colorFilterTimer++;
        if (1) {}
        pthis->iceTimer--;
        if ((pthis->iceTimer % 4) == 0) {
            index = pthis->iceTimer >> 2;
            EffectSsEnIce_SpawnFlyingVec3f(globalCtx, &pthis->actor, &pthis->icePos[index], 150, 150, 150, 250, 235, 245,
                                           255, 1.8f);
        }
    }
}

void EnDodongo_ShiftVecRadial(s16 yaw, f32 radius, Vec3f* vec) {
    vec->x += Math_SinS(yaw) * radius;
    vec->z += Math_CosS(yaw) * radius;
}

s32 EnDodongo_AteBomb(EnDodongo* pthis, GlobalContext* globalCtx) {
    Actor* actor = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;
    f32 dx;
    f32 dy;
    f32 dz;

    while (actor != NULL) {
        if ((actor->params != 0) || (actor->parent != NULL)) {
            actor = actor->next;
            continue;
        }
        dx = actor->world.pos.x - pthis->mouthPos.x;
        dy = actor->world.pos.y - pthis->mouthPos.y;
        dz = actor->world.pos.z - pthis->mouthPos.z;
        if ((fabsf(dx) < 20.0f) && (fabsf(dy) < 10.0f) && (fabsf(dz) < 20.0f)) {
            if (actor->id == ACTOR_EN_BOM) {
                pthis->actor.child = actor;
            } else {
                pthis->actor.parent = actor;
            }
            actor->parent = &pthis->actor;
            return true;
        }
        actor = actor->next;
    }
    return false;
}

void EnDodongo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dodongo_InitVars = {
        ACTOR_EN_DODONGO,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_DODONGO,
        sizeof(EnDodongo),
        (ActorFunc)EnDodongo_Init,
        (ActorFunc)EnDodongo_Destroy,
        (ActorFunc)EnDodongo_Update,
        (ActorFunc)EnDodongo_Draw,
        (ActorFunc)EnDodongo_Reset,
    };

    sBodyJntSphInit = {
        {
            COLTYPE_HIT0,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_JNTSPH,
        },
        6,
        sBodyElementsInit,
    };

    sHardTrisInit = {
        {
            COLTYPE_METAL,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_TRIS,
        },
        3,
        sHardElementsInit,
    };

    sAttackQuadInit = {
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
            { 0x20000000, 0x01, 0x10 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x1),
        /* Deku stick    */ DMG_ENTRY(2, 0x0),
        /* Slingshot     */ DMG_ENTRY(1, 0x0),
        /* Explosive     */ DMG_ENTRY(2, 0x0),
        /* Boomerang     */ DMG_ENTRY(0, 0x1),
        /* Normal arrow  */ DMG_ENTRY(1, 0x0),
        /* Hammer swing  */ DMG_ENTRY(2, 0x0),
        /* Hookshot      */ DMG_ENTRY(0, 0x1),
        /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
        /* Master sword  */ DMG_ENTRY(2, 0x0),
        /* Giant's Knife */ DMG_ENTRY(4, 0x0),
        /* Fire arrow    */ DMG_ENTRY(2, 0x0),
        /* Ice arrow     */ DMG_ENTRY(4, 0xF),
        /* Light arrow   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(2, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(2, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x6),
        /* Ice magic     */ DMG_ENTRY(3, 0xF),
        /* Light magic   */ DMG_ENTRY(0, 0x6),
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

}

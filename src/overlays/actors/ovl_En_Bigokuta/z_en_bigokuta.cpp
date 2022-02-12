#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BIGOKUTA_Z_EN_BIGOKUTA_C
#include "actor_common.h"
#include "z_en_bigokuta.h"
#include "objects/object_bigokuta/object_bigokuta.h"
#include "def/code_8006BA00.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnBigokuta_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809BD318(EnBigokuta* pthis);
void func_809BD3E0(EnBigokuta* pthis);
void func_809BDF34(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BD84C(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BD8DC(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BDAE8(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BDB90(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BDC08(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE3E4(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE4A4(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE518(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BCF68(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BDFC8(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE26C(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE180(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BE058(EnBigokuta* pthis, GlobalContext* globalCtx);
void func_809BD1C8(EnBigokuta* pthis, GlobalContext* globalCtx);

static Color_RGBA8 sEffectPrimColor = { 255, 255, 255, 255 };
static Color_RGBA8 sEffectEnvColor = { 100, 255, 255, 255 };
static Vec3f sEffectPosAccel = { 0.0f, 0.0f, 0.0f };

ActorInit En_Bigokuta_InitVars = {
    ACTOR_EN_BIGOKUTA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BIGOKUTA,
    sizeof(EnBigokuta),
    (ActorFunc)EnBigokuta_Init,
    (ActorFunc)EnBigokuta_Destroy,
    (ActorFunc)EnBigokuta_Update,
    (ActorFunc)EnBigokuta_Draw,
};

static ColliderJntSphElementInit sJntSphElementInit[1] = {
    {
        {
            ELEMTYPE_UNK1,
            { 0x20000000, 0x00, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 45, -30 }, 75 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementInit),
    sJntSphElementInit,
};

static ColliderCylinderInit sCylinderInit[] = {
    { {
          COLTYPE_HARD,
          AT_ON | AT_TYPE_ENEMY,
          AC_ON | AC_HARD | AC_TYPE_PLAYER,
          OC1_ON | OC1_TYPE_ALL,
          OC2_TYPE_1,
          COLSHAPE_CYLINDER,
      },
      {
          ELEMTYPE_UNK1,
          { 0x20000000, 0x00, 0x08 },
          { 0xFFCFFFE7, 0x00, 0x00 },
          TOUCH_ON | TOUCH_SFX_HARD,
          BUMP_ON,
          OCELEM_ON,
      },
      { 50, 100, 0, { 30, 0, 12 } } },
    { {
          COLTYPE_HARD,
          AT_ON | AT_TYPE_ENEMY,
          AC_ON | AC_HARD | AC_TYPE_PLAYER,
          OC1_ON | OC1_TYPE_ALL,
          OC2_TYPE_1,
          COLSHAPE_CYLINDER,
      },
      {
          ELEMTYPE_UNK1,
          { 0x20000000, 0x00, 0x08 },
          { 0xFFCFFFE7, 0x00, 0x00 },
          TOUCH_ON | TOUCH_SFX_HARD,
          BUMP_ON,
          OCELEM_ON,
      },
      { 50, 100, 0, { -30, 0, 12 } } },
};

static CollisionCheckInfoInit sColChkInfoInit[] = { 4, 130, 120, 200 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0xF),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(0, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(0, 0x0),
    /* Giant's Knife */ DMG_ENTRY(0, 0x0),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(0, 0x0),
    /* Master spin   */ DMG_ENTRY(0, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(0, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(gravity, -1, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x59, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 33, ICHAIN_STOP),
};

// possibly color data
static s32 sUnused[] = { 0xFFFFFFFF, 0x969696FF };

void EnBigokuta_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBigokuta* pthis = (EnBigokuta*)thisx;
    s32 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_bigokuta_Skel_006BC0, &object_bigokuta_Anim_0014B8,
                       pthis->jointTable, pthis->morphTable, 20);

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, &pthis->element);

    pthis->collider.elements->dim.worldSphere.radius = pthis->collider.elements->dim.modelSphere.radius;

    for (i = 0; i < ARRAY_COUNT(sCylinderInit); i++) {
        Collider_InitCylinder(globalCtx, &pthis->cylinder[i]);
        Collider_SetCylinder(globalCtx, &pthis->cylinder[i], &pthis->actor, &sCylinderInit[i]);
    }

    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, sColChkInfoInit);

    pthis->unk_194 = 1;

    if (pthis->actor.params == 0) {
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
        func_809BD318(pthis);
    } else {
        func_809BD3E0(pthis);
        pthis->unk_19A = 0;
        pthis->unk_196 = 1;
        pthis->actor.home.pos.y = -1025.0f;
    }
}

void EnBigokuta_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBigokuta* pthis = (EnBigokuta*)thisx;
    s32 i;

    Collider_DestroyJntSph(globalCtx, &pthis->collider);
    for (i = 0; i < ARRAY_COUNT(pthis->cylinder); i++) {
        Collider_DestroyCylinder(globalCtx, &pthis->cylinder[i]);
    }
}

void func_809BCE3C(EnBigokuta* pthis) {
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + pthis->unk_194 * -0x4000;
    pthis->actor.world.pos.x = Math_SinS(pthis->actor.world.rot.y) * 263.0f + pthis->actor.home.pos.x;
    pthis->actor.world.pos.z = Math_CosS(pthis->actor.world.rot.y) * 263.0f + pthis->actor.home.pos.z;
}

void func_809BCEBC(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    f32 yDistFromHome = pthis->actor.world.pos.y - pthis->actor.home.pos.y;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.home.pos.y + 3.0f;
    pos.z = pthis->actor.world.pos.z;

    if (((globalCtx->gameplayFrames % 7) == 0) && (yDistFromHome <= 0.0f) && (yDistFromHome > -100.0f)) {
        EffectSsGRipple_Spawn(globalCtx, &pos, 800, 1300, 0);
    }
}

void func_809BCF68(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;
    s16 rot;

    if (globalCtx->gameplayFrames & 1) {
        rot = Rand_S16Offset(0x1200, 0xC00) + pthis->actor.shape.rot.y - pthis->unk_194 * 0xA00;
    } else {
        rot = pthis->actor.shape.rot.y - pthis->unk_194 * 0xA00 - Rand_S16Offset(0x1200, 0xC00);
    }
    if (pthis->actionFunc != func_809BE4A4) {
        if (pthis->actionFunc == func_809BE3E4 || (globalCtx->gameplayFrames & 2)) {
            effectPos.x = pthis->actor.world.pos.x - Math_SinS(rot) * 80.0f;
            effectPos.z = pthis->actor.world.pos.z - Math_CosS(rot) * 80.0f;
            effectPos.y = pthis->actor.home.pos.y + 1.0f;
            EffectSsGRipple_Spawn(globalCtx, &effectPos, 100, 500, 0);
        } else {
            effectPos.x = pthis->actor.world.pos.x - Math_SinS(rot) * 120.0f;
            effectPos.z = pthis->actor.world.pos.z - Math_CosS(rot) * 120.0f;
            effectPos.y = pthis->actor.home.pos.y + 5.0f;
        }
    } else {
        effectPos.x = pthis->actor.world.pos.x - Math_SinS(rot) * 50.0f;
        effectPos.z = pthis->actor.world.pos.z - Math_CosS(rot) * 50.0f;
        effectPos.y = pthis->actor.home.pos.y + 1.0f;
        EffectSsGRipple_Spawn(globalCtx, &effectPos, 100, 500, 0);
    }
    EffectSsGSplash_Spawn(globalCtx, &effectPos, NULL, NULL, 1, 800);
    if (pthis->actionFunc != func_809BE4A4) {
        func_8002F974(&pthis->actor, NA_SE_EN_DAIOCTA_SPLASH - SFX_FLAG);
    }
}

void func_809BD1C8(EnBigokuta* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f effectPos;

    effectPos.y = pthis->actor.world.pos.y;

    for (i = 0; i < 4; i++) {
        effectPos.x = ((i >= 2) ? 1 : -1) * 60.0f + pthis->actor.world.pos.x;
        effectPos.z = ((i & 1) ? 1 : -1) * 60.0f + pthis->actor.world.pos.z;
        EffectSsGSplash_Spawn(globalCtx, &effectPos, NULL, NULL, 1, 2000);
    }

    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_LAND_WATER);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOLON_LAND_BIG);
    func_80033E88(&pthis->actor, globalCtx, 0xA, 8);
}

void func_809BD2E4(EnBigokuta* pthis) {
    Actor* parent = pthis->actor.parent;

    if (parent != NULL) {
        Math_ScaledStepToS(&parent->world.rot.y, pthis->unk_19A, 0x10);
    }
}

void func_809BD318(EnBigokuta* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &object_bigokuta_Anim_0014B8);
    pthis->unk_19A = 0;
    pthis->actor.home.pos.y = -1025.0f;
    pthis->unk_196 = 121;
    pthis->actionFunc = func_809BD84C;
}

void func_809BD370(EnBigokuta* pthis) {
    pthis->unk_196 = 21;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_STAL_JUMP);
    pthis->actionFunc = func_809BD8DC;
}

void func_809BD3AC(EnBigokuta* pthis) {
    pthis->actor.world.pos.x = pthis->actor.home.pos.x + 263.0f;
    pthis->unk_196 = 10;
    pthis->actionFunc = func_809BDAE8;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y;
}

void func_809BD3E0(EnBigokuta* pthis) {
    pthis->unk_196 = 40;
    pthis->actionFunc = func_809BDB90;
}

void func_809BD3F8(EnBigokuta* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_bigokuta_Anim_001CA4, -5.0f);
    pthis->unk_196 = 350;
    pthis->unk_198 = 80;
    pthis->unk_19A = pthis->unk_194 * -0x200;
    func_809BCE3C(pthis);
    pthis->cylinder[0].base.atFlags |= AT_ON;
    pthis->collider.base.acFlags |= AC_ON;
    pthis->actionFunc = func_809BDC08;
}

void func_809BD47C(EnBigokuta* pthis) {
    pthis->unk_196 = 16;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.colorFilterTimer = 0;
    pthis->actionFunc = func_809BDF34;
}

void func_809BD4A4(EnBigokuta* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &object_bigokuta_Anim_0014B8, -5.0f);
    pthis->unk_195 = true;
    pthis->actor.world.rot.x = pthis->actor.shape.rot.y + 0x8000;
    pthis->unk_19A = pthis->unk_194 * 0x200;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->cylinder[0].base.atFlags |= AT_ON;
    pthis->actionFunc = func_809BDFC8;
}

void func_809BD524(EnBigokuta* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_bigokuta_Anim_000D1C, -5.0f);
    pthis->unk_196 = 80;
    pthis->unk_19A = 0;
    pthis->cylinder[0].base.atFlags |= AT_ON;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_MAHI);
    if (pthis->collider.elements->info.acHitInfo->toucher.dmgFlags & 1) {
        pthis->unk_195 = true;
        pthis->unk_196 = 20;
    } else {
        pthis->unk_195 = false;
        pthis->unk_196 = 80;
    }
    Actor_SetColorFilter(&pthis->actor, 0, 255, 0, pthis->unk_196);
    pthis->actionFunc = func_809BE058;
}

void func_809BD5E0(EnBigokuta* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_bigokuta_Anim_000444, -5.0f);
    pthis->unk_196 = 24;
    pthis->unk_19A = 0;
    pthis->cylinder[0].base.atFlags &= ~AT_ON;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 24);
    pthis->actionFunc = func_809BE180;
}
void func_809BD658(EnBigokuta* pthis) {

    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_bigokuta_Anim_000A74, -5.0f);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_DEAD2);
    pthis->unk_196 = 38;
    pthis->unk_198 = 10;
    pthis->actionFunc = func_809BE26C;
}

void func_809BD6B8(EnBigokuta* pthis) {
    if (!pthis->unk_195) {
        if (Rand_ZeroOne() < 0.5f) {
            pthis->unk_196 = 24;
        } else {
            pthis->unk_196 = 28;
        }
    } else {
        if (ABS(pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer) >= 0x4000) {
            pthis->unk_196 = 4;
        } else {
            pthis->unk_196 = 0;
        }
    }
    pthis->unk_19A = 0;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actionFunc = func_809BE3E4;
}

void func_809BD768(EnBigokuta* pthis) {
    pthis->unk_194 = Rand_ZeroOne() < 0.5f ? -1 : 1;
    pthis->unk_19A = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->cylinder[0].base.atFlags &= ~AT_ON;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_SINK);
    pthis->actionFunc = func_809BE4A4;
}

void func_809BD7F0(EnBigokuta* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.rot.y = Actor_WorldYawTowardPoint(&GET_PLAYER(globalCtx)->actor, &pthis->actor.home.pos);
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y + (pthis->unk_194 * 0x4000);
    func_809BCE3C(pthis);
    pthis->actionFunc = func_809BE518;
}

void func_809BD84C(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    pthis->unk_196--;

    if (pthis->unk_196 == 13 || pthis->unk_196 == -20) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_VOICE);
    }
    if (pthis->unk_196 == 1) {
        func_800F5ACC(NA_BGM_MINI_BOSS);
    }
    if (pthis->actor.params == 1) {
        func_809BD370(pthis);
    }
}

void func_809BD8DC(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;

    pthis->unk_196--;

    if (pthis->unk_196 >= 0) {
        Math_StepToF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x + 263.0f, 263.0f / 21);

        if (pthis->unk_196 < 14) {
            pthis->actor.world.pos.y = sinf(pthis->unk_196 * (M_PI / 28)) * 200.0f + pthis->actor.home.pos.y;
        } else {
            pthis->actor.world.pos.y =
                sinf((pthis->unk_196 - 7) * (M_PI / 14)) * 130.0f + (pthis->actor.home.pos.y + 70.0f);
        }
        if (pthis->unk_196 == 0) {
            effectPos.x = pthis->actor.world.pos.x + 40.0f;
            effectPos.y = pthis->actor.world.pos.y;
            effectPos.z = pthis->actor.world.pos.z - 70.0f;
            EffectSsGSplash_Spawn(globalCtx, &effectPos, NULL, NULL, 1, 2000);
            effectPos.x = pthis->actor.world.pos.x - 40.0f;
            EffectSsGSplash_Spawn(globalCtx, &effectPos, NULL, NULL, 1, 2000);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_LAND_WATER);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOLON_LAND_BIG);
            func_800AA000(0.0f, 0xFF, 0x14, 0x96);
        }
    } else if (pthis->unk_196 < -1) {
        pthis->actor.world.pos.y = pthis->actor.home.pos.y - (sinf((pthis->unk_196 + 1) * (M_PI / 10)) * 20.0f);
        if (pthis->unk_196 == -10) {
            func_809BD3AC(pthis);
        }
    }
}

void func_809BDAE8(EnBigokuta* pthis, GlobalContext* globalCtx) {
    if (Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.home.rot.y + 0x4000, 0x400)) {
        if (pthis->unk_196 != 0) {
            pthis->unk_196--;
        }
        if (pthis->unk_196 == 0) {
            func_809BCE3C(pthis);
            pthis->actor.home.pos.y = pthis->actor.world.pos.y;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
            pthis->actor.params = 2;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_VOICE);
            func_809BD3E0(pthis);
        }
    }
}

void func_809BDB90(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }
    if (pthis->unk_196 == 0) {
        if (pthis->actor.params == 3) {
            func_800F5ACC(NA_BGM_MINI_BOSS);
        }
        func_809BD3F8(pthis);
    }
}

void func_809BDC08(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 phi_v0;
    s16 pad;
    s16 phi_v1;
    Vec3f sp28;

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_BUBLE);
    }

    if (pthis->unk_196 < 0) {
        pthis->actor.shape.rot.y += pthis->unk_194 * 0x200;
        func_809BCE3C(pthis);
        pthis->unk_196++;
        if (pthis->unk_196 == 0) {
            pthis->unk_196 = 350;
        }
        func_809BCF68(pthis, globalCtx);
        return;
    }

    phi_v1 = (Actor_WorldDistXZToPoint(&player->actor, &pthis->actor.home.pos) - 180.0f) * (8.0f / 15);
    func_8002DBD0(&pthis->actor, &sp28, &player->actor.world.pos);
    if (fabsf(sp28.x) > 263.0f || ((sp28.z > 0.0f) && !Actor_IsFacingPlayer(&pthis->actor, 0x1B00) &&
                                   !Player_IsFacingActor(&pthis->actor, 0x2000, globalCtx))) {
        phi_v1 -= 0x80;
        if (pthis->unk_196 != 0) {
            pthis->unk_196--;
        }
    }

    if ((pthis->actor.xzDistToPlayer < 250.0f) && !Actor_IsFacingPlayer(&pthis->actor, 0x6000)) {
        if (pthis->unk_198 != 0) {
            pthis->unk_198--;
        }
        if (pthis->actor.xzDistToPlayer < 180.0f) {
            phi_v1 += 0x20;
        }
    } else {
        pthis->unk_198 = 80;
    }
    if (pthis->actor.colChkInfo.health == 1) {
        phi_v1 = (phi_v1 + 0x130) * 1.1f;
    } else {
        phi_v1 += 0x130;
    }
    pthis->actor.shape.rot.y += phi_v1 * pthis->unk_194;
    func_809BCE3C(pthis);
    func_809BCF68(pthis, globalCtx);
    if (pthis->unk_198 == 0) {
        func_809BD768(pthis);
    } else if (pthis->unk_196 == 0) {
        func_809BD4A4(pthis);
    } else if (pthis->unk_195) {
        phi_v0 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
        if (phi_v0 < 0) {
            phi_v0 = -phi_v0;
        }
        if (phi_v0 < 0x4100 && phi_v0 > 0x3F00) {
            if (Rand_ZeroOne() < 0.6f) {
                pthis->unk_196 = 0;
                func_809BD4A4(pthis);
            }
            pthis->unk_195 = false;
        }
    }
}

void func_809BDF34(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }
    pthis->actor.world.pos.y = (sinf(pthis->unk_196 * (M_PI / 16)) * 100.0f) + pthis->actor.home.pos.y;
    if (pthis->unk_196 == 0) {
        func_809BD1C8(pthis, globalCtx);
        func_809BD3F8(pthis);
    }
}

void func_809BDFC8(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }
    if (pthis->unk_196 == 20) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_VOICE);
    }
    if ((pthis->unk_196 == 0) && Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.x, 0x800)) {
        pthis->unk_194 = -pthis->unk_194;
        func_809BD3F8(pthis);
    }
}

void func_809BE058(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 speedXZ;

    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->collider.base.ocFlags1 & OC1_HIT) || (pthis->cylinder[0].base.ocFlags1 & OC1_HIT) ||
        (pthis->cylinder[1].base.ocFlags1 & OC1_HIT)) {
        speedXZ = CLAMP_MIN(player->actor.speedXZ, 1.0f);
        if (!(pthis->collider.base.ocFlags1 & OC1_HIT)) {
            pthis->cylinder[0].base.ocFlags1 &= ~OC1_HIT;
            pthis->cylinder[1].base.ocFlags1 &= ~OC1_HIT;
            speedXZ *= -1.0f;
        }
        player->actor.world.pos.x -= speedXZ * Math_SinS(pthis->actor.shape.rot.y);
        player->actor.world.pos.z -= speedXZ * Math_CosS(pthis->actor.shape.rot.y);
    }
    if (pthis->unk_196 == 0) {
        func_809BD6B8(pthis);
    }
}

void func_809BE180(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }
    if (pthis->unk_196 == 0) {
        if (pthis->actor.colChkInfo.health != 0) {
            func_809BD4A4(pthis);
        } else {
            func_809BD658(pthis);
        }
    } else if (pthis->unk_196 >= 8) {
        pthis->actor.shape.rot.y += pthis->unk_194 * 0x200;
        pthis->actor.world.pos.y = sinf((pthis->unk_196 - 8) * (M_PI / 16)) * 100.0f + pthis->actor.home.pos.y;
        func_809BCE3C(pthis);
        if (pthis->unk_196 == 8) {
            func_809BD1C8(pthis, globalCtx);
        }
    }
}
void func_809BE26C(EnBigokuta* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;

    if (pthis->unk_196 != 0) {
        if (pthis->unk_196 != 0) {
            pthis->unk_196--;
        }
        if (pthis->unk_196 >= 10) {
            pthis->actor.shape.rot.y += 0x2000;
        }
    } else if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->unk_198 != 0) {
            pthis->unk_198--;
        }
        if (pthis->unk_198 == 6) {
            effectPos.x = pthis->actor.world.pos.x;
            effectPos.y = pthis->actor.world.pos.y + 150.0f;
            effectPos.z = pthis->actor.world.pos.z;
            func_8002829C(globalCtx, &effectPos, &sEffectPosAccel, &sEffectPosAccel, &sEffectPrimColor,
                          &sEffectEnvColor, 1200, 20);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_DEAD2);
        }
        if (pthis->unk_198 == 0 && Math_StepToF(&pthis->actor.scale.y, 0.0f, 0.001f)) {
            Flags_SetClear(globalCtx, pthis->actor.room);
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
            func_8005ACFC(globalCtx->cameraPtrs[MAIN_CAM], 4);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 50, NA_SE_EN_OCTAROCK_BUBLE);
            Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xB0);
            Actor_Kill(&pthis->actor);
        }
    }
}

void func_809BE3E4(EnBigokuta* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_196 != 0) {
        if (pthis->unk_196 != 0) {
            pthis->unk_196--;
        }
        pthis->actor.shape.rot.y += 0x2000;
    }
    if (pthis->unk_196 == 0) {
        if ((s16)(pthis->actor.shape.rot.y - pthis->actor.world.rot.y) > 0) {
            pthis->unk_194 = 1;
        } else {
            pthis->unk_194 = -1;
        }

        func_809BD3F8(pthis);
        if (!pthis->unk_195) {
            pthis->unk_196 = -40;
        }
    }
    func_809BCF68(pthis, globalCtx);
}

void func_809BE4A4(EnBigokuta* pthis, GlobalContext* globalCtx) {
    pthis->actor.world.pos.y -= 10.0f;
    pthis->actor.shape.rot.y += 0x2000;
    if (pthis->actor.world.pos.y < (pthis->actor.home.pos.y + -200.0f)) {
        func_809BD7F0(pthis, globalCtx);
    }
    func_809BCF68(pthis, globalCtx);
}

void func_809BE518(EnBigokuta* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 10.0f)) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        func_809BD3F8(pthis);
    }
}

void func_809BE568(EnBigokuta* pthis) {
    s32 i;
    f32 sin = Math_SinS(pthis->actor.shape.rot.y);
    f32 cos = Math_CosS(pthis->actor.shape.rot.y);

    pthis->collider.elements->dim.worldSphere.center.x =
        (pthis->collider.elements->dim.modelSphere.center.z * sin) +
        (pthis->actor.world.pos.x + (pthis->collider.elements->dim.modelSphere.center.x * cos));
    pthis->collider.elements->dim.worldSphere.center.z =
        (pthis->actor.world.pos.z + (pthis->collider.elements->dim.modelSphere.center.z * cos)) -
        (pthis->collider.elements->dim.modelSphere.center.x * sin);
    pthis->collider.elements->dim.worldSphere.center.y =
        pthis->collider.elements->dim.modelSphere.center.y + pthis->actor.world.pos.y;

    for (i = 0; i < ARRAY_COUNT(pthis->cylinder); i++) {
        pthis->cylinder[i].dim.pos.x =
            pthis->actor.world.pos.x + sCylinderInit[i].dim.pos.z * sin + sCylinderInit[i].dim.pos.x * cos;
        pthis->cylinder[i].dim.pos.z =
            pthis->actor.world.pos.z + sCylinderInit[i].dim.pos.z * cos - sCylinderInit[i].dim.pos.x * sin;
        pthis->cylinder[i].dim.pos.y = pthis->actor.world.pos.y;
    }
}

void func_809BE798(EnBigokuta* pthis, GlobalContext* globalCtx) {
    s16 effectRot;
    s16 yawDiff;

    if ((pthis->cylinder[0].base.atFlags & AT_HIT) || (pthis->cylinder[1].base.atFlags & AT_HIT) ||
        (pthis->collider.base.atFlags & AT_HIT)) {
        pthis->cylinder[0].base.atFlags &= ~AT_HIT;
        pthis->cylinder[1].base.atFlags &= ~AT_HIT;
        pthis->collider.base.atFlags &= ~AT_HIT;
        yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y;
        if (yawDiff > 0x4000) {
            effectRot = 0x4000;
        } else if (yawDiff > 0) {
            effectRot = 0x6000;
        } else if (yawDiff < -0x4000) {
            effectRot = -0x4000;
        } else {
            effectRot = -0x6000;
        }
        func_8002F71C(globalCtx, &pthis->actor, 10.0f, pthis->actor.world.rot.y + effectRot, 5.0f);
        if (pthis->actionFunc == func_809BDC08) {
            func_809BD4A4(pthis);
            pthis->unk_196 = 40;
        } else if (pthis->actionFunc == func_809BE3E4) {
            if ((effectRot * pthis->unk_194) > 0) {
                pthis->unk_194 = 0 - pthis->unk_194;
                pthis->unk_196 += 4;
            }
        }
    }
}

void EnBigokuta_UpdateDamage(EnBigokuta* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != 0 || pthis->actor.colChkInfo.damage != 0) {
            if (pthis->actor.colChkInfo.damageEffect == 1) {
                if (pthis->actionFunc != func_809BE058) {
                    func_809BD524(pthis);
                }
            } else if (pthis->actor.colChkInfo.damageEffect == 0xF) {
                func_809BD47C(pthis);
            } else if (!Actor_IsFacingPlayer(&pthis->actor, 0x4000)) {
                if (Actor_ApplyDamage(&pthis->actor) == 0) { // Dead
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_DEAD);
                    Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                } else {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DAIOCTA_DAMAGE);
                }
                func_809BD5E0(pthis);
            }
        }
    }
}

void EnBigokuta_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnBigokuta* pthis = (EnBigokuta*)thisx;
    s32 i;
    GlobalContext* globalCtx = globalCtx2;

    func_809BE798(pthis, globalCtx);
    EnBigokuta_UpdateDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    func_809BD2E4(pthis);
    func_809BE568(pthis);
    Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_BIG_OCTO);
    func_8005AD1C(globalCtx->cameraPtrs[MAIN_CAM], 4);

    if (pthis->cylinder[0].base.atFlags & AT_ON) {
        if (pthis->actionFunc != func_809BE058) {
            for (i = 0; i < ARRAY_COUNT(pthis->cylinder); i++) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->cylinder[i].base);
            }
            pthis->actor.flags |= ACTOR_FLAG_24;
        } else {
            for (i = 0; i < ARRAY_COUNT(pthis->cylinder); i++) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->cylinder[i].base);
            }
        }
        for (i = 0; i < ARRAY_COUNT(pthis->cylinder); i++) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->cylinder[i].base);
        }
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
    if (pthis->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    } else {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    Actor_SetFocus(&pthis->actor, pthis->actor.scale.y * 25.0f * 100.0f);
    func_809BCEBC(pthis, globalCtx);
}

s32 EnBigokuta_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    EnBigokuta* pthis = (EnBigokuta*)thisx;
    u8 intensity;
    f32 temp_f0;
    s32 temp_hi;

    if (limbIndex == 15) {
        if (pthis->actionFunc == func_809BE058 || pthis->actionFunc == func_809BE180) {
            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 1914);

            if (pthis->actionFunc == func_809BE058) {
                temp_hi = pthis->unk_196 % 12;
                if (temp_hi >= 8) {
                    temp_f0 = (12 - temp_hi) * (M_PI / 8);
                } else {
                    temp_f0 = temp_hi * (M_PI / 16);
                }
            } else {
                temp_hi = pthis->unk_196 % 6;
                if (temp_hi >= 4) {
                    temp_f0 = (6 - temp_hi) * (M_PI / 4);
                } else {
                    temp_f0 = temp_hi * (M_PI / 8);
                }
            }

            temp_f0 = sinf(temp_f0) * 125.0f + 130.0f;
            gDPPipeSync(POLY_OPA_DISP++);

            gDPSetEnvColor(POLY_OPA_DISP++, temp_f0, temp_f0, temp_f0, 255);
            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 1945);
        }
    } else if (limbIndex == 10) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 1950);
        if (pthis->actionFunc == func_809BE26C) {
            intensity = pthis->unk_196 * (255.0f / 38);
        } else {
            intensity = 255;
        }
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, intensity, intensity, intensity, intensity);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 1972);
    } else if (limbIndex == 17 && pthis->actionFunc == func_809BE26C) {
        if (pthis->unk_198 < 5) {
            Matrix_Scale((pthis->unk_198 * 0.2f * 0.25f) + 1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
        } else if (pthis->unk_198 < 8) {
            temp_f0 = (pthis->unk_198 - 5) * (1.0f / 12);
            Matrix_Scale(1.25f - temp_f0, 1.0f + temp_f0, 1.0f + temp_f0, MTXMODE_APPLY);
        } else {
            temp_f0 = ((pthis->unk_198 - 8) * 0.125f);
            Matrix_Scale(1.0f, 1.25f - temp_f0, 1.25f - temp_f0, MTXMODE_APPLY);
        }
    }
    return false;
}

void EnBigokuta_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBigokuta* pthis = (EnBigokuta*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 2017);

    if ((pthis->actionFunc != func_809BE26C) || (pthis->unk_196 != 0) || (pthis->unk_198 != 0)) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        if (pthis->unk_196 & 1) {
            if ((pthis->actionFunc == func_809BE180 && pthis->unk_196 >= 8) ||
                (pthis->actionFunc == func_809BE26C && pthis->unk_196 >= 10)) {
                f32 rotX = Rand_ZeroOne() * (M_PI * 2.0f);
                f32 rotY = Rand_ZeroOne() * (M_PI * 2.0f);

                Matrix_RotateY(rotY, MTXMODE_APPLY);
                Matrix_RotateX(rotX, MTXMODE_APPLY);
                Matrix_Scale(0.78999996f, 1.3f, 0.78999996f, MTXMODE_APPLY);
                Matrix_RotateX(-rotX, MTXMODE_APPLY);
                Matrix_RotateY(-rotY, MTXMODE_APPLY);
            }
        }
        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, EnBigokuta_OverrideLimbDraw, NULL, pthis);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, (pthis->actor.scale.y * (255 / 0.033f)));
        POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           pthis->skelAnime.dListCount, NULL, NULL, NULL, POLY_XLU_DISP);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bigokuta.c", 2076);
}

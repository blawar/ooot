#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WEIYER_Z_EN_WEIYER_C
#include "actor_common.h"
/*
 * File: z_en_weiyer.c
 * Overlay: ovl_En_Weiyer
 * Description: Stinger (Water)
 */

#include "z_en_weiyer.h"
#include "objects/object_ei/object_ei.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2)

void EnWeiyer_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWeiyer_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWeiyer_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWeiyer_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B32804(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B328E8(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B32C2C(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B32D30(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B32E34(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B33018(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B331CC(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B333B8(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B332B4(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B33338(EnWeiyer* pthis, GlobalContext* globalCtx);
void func_80B3349C(EnWeiyer* pthis, GlobalContext* globalCtx);

ActorInit En_Weiyer_InitVars = {
    ACTOR_EN_WEIYER,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EI,
    sizeof(EnWeiyer),
    (ActorFunc)EnWeiyer_Init,
    (ActorFunc)EnWeiyer_Destroy,
    (ActorFunc)EnWeiyer_Update,
    (ActorFunc)EnWeiyer_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_ON,
        OCELEM_ON,
    },
    { 16, 10, -6, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 2, 45, 15, 100 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x1),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x1),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0x0),
    /* Master sword  */ DMG_ENTRY(2, 0x0),
    /* Giant's Knife */ DMG_ENTRY(4, 0x0),
    /* Fire arrow    */ DMG_ENTRY(2, 0x0),
    /* Ice arrow     */ DMG_ENTRY(2, 0x0),
    /* Light arrow   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
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
static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x19, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 3, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2500, ICHAIN_STOP),
};

void EnWeiyer_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnWeiyer* pthis = (EnWeiyer*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 1000.0f, ActorShadow_DrawCircle, 65.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gStingerSkel, &gStingerIdleAnim, pthis->jointTable, pthis->morphTable,
                   19);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->actionFunc = func_80B32804;
}

void EnWeiyer_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnWeiyer* pthis = (EnWeiyer*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80B32384(EnWeiyer* pthis) {
    pthis->unk_196 = pthis->actor.shape.rot.y;
    pthis->unk_27C = (cosf(-M_PI / 8) * 3.0f) + pthis->actor.world.pos.y;
    Animation_MorphToLoop(&pthis->skelAnime, &gStingerHitAnim, -5.0f);
    pthis->unk_194 = 30;
    pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 2.5f);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->unk_280 = pthis->actor.floorHeight;
    pthis->actionFunc = func_80B328E8;
}

void func_80B32434(EnWeiyer* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gStingerHitAnim, -5.0f);
    pthis->collider.base.atFlags |= AT_ON;
    pthis->unk_194 = 0;
    pthis->actor.speedXZ = 5.0f;
    pthis->actionFunc = func_80B32C2C;
}

void func_80B32494(EnWeiyer* pthis) {
    Animation_Change(&pthis->skelAnime, &gStingerPopOutAnim, 2.0f, 0.0f, 0.0f, ANIMMODE_LOOP, -8.0f);
    pthis->unk_194 = 40;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->actionFunc = func_80B32D30;
}

void func_80B32508(EnWeiyer* pthis) {
    pthis->unk_194 = 200;
    pthis->collider.base.atFlags |= AT_ON;
    pthis->skelAnime.playSpeed = 3.0f;
    pthis->actionFunc = func_80B32E34;
}

void func_80B32538(EnWeiyer* pthis) {
    pthis->unk_194 = 200;
    pthis->unk_196 = pthis->actor.yawTowardsPlayer + 0x8000;
    pthis->unk_27C = pthis->actor.world.pos.y;
    pthis->actor.speedXZ = CLAMP_MAX(pthis->actor.speedXZ, 4.0f);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->skelAnime.playSpeed = 1.0f;
    pthis->actionFunc = func_80B33018;
}

void func_80B325A0(EnWeiyer* pthis) {
    Animation_Change(&pthis->skelAnime, &gStingerHitAnim, 2.0f, 0.0f, 0.0f, ANIMMODE_LOOP, -3.0f);
    pthis->unk_194 = 40;
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.speedXZ = 3.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0, 0x28);
    pthis->collider.dim.height = sCylinderInit.dim.height;
    pthis->actionFunc = func_80B331CC;
}

void func_80B32660(EnWeiyer* pthis) {
    Animation_Change(&pthis->skelAnime, &gStingerPopOutAnim, 2.0f, 0.0f, 0.0f, ANIMMODE_LOOP, -8.0f);
    pthis->unk_194 = 80;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = -1.0f;
    pthis->collider.dim.height = sCylinderInit.dim.height + 15;
    Actor_SetColorFilter(&pthis->actor, 0, 0xC8, 0, 0x50);
    pthis->collider.base.atFlags &= ~AT_ON;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GOMA_JR_FREEZE);
    pthis->actionFunc = func_80B333B8;
}

void func_80B32724(EnWeiyer* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gStingerHitAnim, -5.0f);
    pthis->unk_194 = 20;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xC8, 0, 0x28);
    pthis->collider.base.atFlags &= ~AT_ON;
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->actor.speedXZ = 3.0f;
    pthis->actionFunc = func_80B332B4;
}

void func_80B327B0(EnWeiyer* pthis) {
    pthis->actor.colorFilterParams |= 0x2000;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actionFunc = func_80B33338;
}

void func_80B327D8(EnWeiyer* pthis) {
    pthis->actor.shape.rot.x = -0x2000;
    pthis->unk_194 = -1;
    pthis->actor.speedXZ = 5.0f;
    pthis->actionFunc = func_80B3349C;
}

void func_80B32804(EnWeiyer* pthis, GlobalContext* globalCtx) {
    WaterBox* waterBox;
    s32 bgId;

    pthis->actor.world.pos.y += 0.5f;
    pthis->actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                          &pthis->actor, &pthis->actor.world.pos);

    if (!WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                 &pthis->actor.home.pos.y, &waterBox) ||
        ((pthis->actor.home.pos.y - 5.0f) <= pthis->actor.floorHeight)) {
        Actor_Kill(&pthis->actor);
    } else {
        pthis->actor.home.pos.y -= 5.0f;
        pthis->actor.world.pos.y = (pthis->actor.home.pos.y + pthis->actor.floorHeight) / 2.0f;
        func_80B32384(pthis);
    }
}

void func_80B328E8(EnWeiyer* pthis, GlobalContext* globalCtx) {
    s32 sp34;
    f32 curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x800);
    sp34 = Animation_OnFrame(&pthis->skelAnime, 0.0f);
    curFrame = pthis->skelAnime.curFrame;
    Math_StepToF(&pthis->unk_27C, pthis->unk_280, 0.5f);
    pthis->actor.world.pos.y = pthis->unk_27C - cosf((curFrame - 5.0f) * (M_PI / 40)) * 3.0f;

    if (curFrame <= 45.0f) {
        Math_StepToF(&pthis->actor.speedXZ, 1.0f, 0.03f);
    } else {
        Math_StepToF(&pthis->actor.speedXZ, 1.3f, 0.03f);
    }

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->unk_196 = pthis->actor.wallYaw;
        pthis->unk_194 = 30;
    }

    if (Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->unk_196, 182)) {
        if (pthis->unk_194 != 0) {
            pthis->unk_194--;
        }

        if (pthis->unk_194 == 0) {
            pthis->unk_196 =
                Rand_S16Offset(0x2000, 0x2000) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1) + pthis->actor.shape.rot.y;
            pthis->unk_194 = 30;

            if (Rand_ZeroOne() < 0.3333f) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_CRY);
            }
        }
    }

    if (pthis->actor.home.pos.y < pthis->actor.world.pos.y) {
        if (pthis->actor.home.pos.y < pthis->actor.floorHeight) {
            func_80B32434(pthis);
        } else {
            pthis->actor.world.pos.y = pthis->actor.home.pos.y;
            pthis->unk_280 =
                Rand_ZeroOne() * ((pthis->actor.home.pos.y - pthis->actor.floorHeight) / 2.0f) + pthis->actor.floorHeight;
        }
    } else {
        Player* player = GET_PLAYER(globalCtx);

        if (pthis->actor.bgCheckFlags & 1) {
            pthis->unk_280 =
                pthis->actor.home.pos.y - Rand_ZeroOne() * ((pthis->actor.home.pos.y - pthis->actor.floorHeight) / 2.0f);
        } else if (sp34 && (Rand_ZeroOne() < 0.1f)) {
            pthis->unk_280 =
                Rand_ZeroOne() * (pthis->actor.home.pos.y - pthis->actor.floorHeight) + pthis->actor.floorHeight;
        }

        if ((pthis->actor.xzDistToPlayer < 400.0f) && (fabsf(pthis->actor.yDistToPlayer) < 250.0f) &&
            (player->actor.world.pos.y < (pthis->actor.home.pos.y + 20.0f))) {
            func_80B32508(pthis);
        }
    }
}

void func_80B32C2C(EnWeiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_194 == 0) {
        if (Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x4000, 0x800)) {
            pthis->actor.shape.rot.z = 0;
            pthis->actor.shape.rot.y += 0x8000;
            pthis->unk_194 = 1;
        } else {
            pthis->actor.shape.rot.z = pthis->actor.shape.rot.x * 2;
        }
    } else {
        Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0x1800, 0x800);

        if (pthis->actor.world.pos.y < pthis->actor.home.pos.y) {
            if (pthis->actor.shape.rot.x > 0) {
                EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 1, 400);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_SINK);
            }

            func_80B32538(pthis);
        } else if (pthis->actor.bgCheckFlags & 1) {
            func_80B32494(pthis);
        }
    }
}

void func_80B32D30(EnWeiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_FLUTTER);
    }

    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x800);
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 1.0f);

    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    if (pthis->unk_194 == 0) {
        func_80B32434(pthis);
    } else if (pthis->actor.world.pos.y < pthis->actor.home.pos.y) {
        func_80B32384(pthis);
    }
}

s16 func_80B32DEC(EnWeiyer* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f vec;

    vec.x = player->actor.world.pos.x;
    vec.y = player->actor.world.pos.y + 20.0f;
    vec.z = player->actor.world.pos.z;

    return Actor_WorldPitchTowardPoint(&pthis->actor, &vec);
}

void func_80B32E34(EnWeiyer* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    if ((pthis->unk_194 == 0) || ((pthis->actor.home.pos.y + 20.0f) <= player->actor.world.pos.y) ||
        (pthis->collider.base.atFlags & AT_HIT)) {
        func_80B32538(pthis);
    } else {
        if (Actor_IsFacingPlayer(&pthis->actor, 0x2800)) {
            Math_StepToF(&pthis->actor.speedXZ, 4.0f, 0.2f);
        } else {
            Math_StepToF(&pthis->actor.speedXZ, 1.3f, 0.2f);
        }

        if (pthis->actor.home.pos.y < pthis->actor.world.pos.y) {
            if (pthis->actor.home.pos.y < pthis->actor.floorHeight) {
                pthis->actor.shape.rot.x = 0;
                func_80B32434(pthis);
                return;
            }

            pthis->actor.world.pos.y = pthis->actor.home.pos.y;
            Math_SmoothStepToS(&pthis->actor.shape.rot.x, 0x1000, 2, 0x100, 0x40);
        } else {
            Math_SmoothStepToS(&pthis->actor.shape.rot.x, func_80B32DEC(pthis, globalCtx), 2, 0x100, 0x40);
        }

        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 0x200, 0x80);

        if ((player->actor.yDistToWater < 50.0f) && (pthis->actor.yDistToWater < 20.0f) &&
            Actor_IsFacingPlayer(&pthis->actor, 0x2000)) {
            func_80B327D8(pthis);
        }
    }
}

void func_80B33018(EnWeiyer* pthis, GlobalContext* globalCtx) {
    f32 curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x800);
    curFrame = pthis->skelAnime.curFrame;
    Math_StepToF(&pthis->unk_27C, (pthis->actor.home.pos.y - pthis->actor.floorHeight) / 4.0f + pthis->actor.floorHeight,
                 1.0f);
    pthis->actor.world.pos.y = pthis->unk_27C - cosf((curFrame - 5.0f) * (M_PI / 40)) * 3.0f;

    if (curFrame <= 45.0f) {
        Math_StepToF(&pthis->actor.speedXZ, 1.0f, 0.03f);
    } else {
        Math_StepToF(&pthis->actor.speedXZ, 1.3f, 0.03f);
    }

    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->unk_196 = pthis->actor.wallYaw;
    }

    if (Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->unk_196, 2, 0x200, 0x80) == 0) {
        pthis->unk_196 = pthis->actor.yawTowardsPlayer + 0x8000;
    }

    if (pthis->actor.home.pos.y < pthis->actor.world.pos.y) {
        if (pthis->actor.home.pos.y < pthis->actor.floorHeight) {
            func_80B32434(pthis);
        } else {
            pthis->actor.world.pos.y = pthis->actor.home.pos.y;
        }
    }

    if (pthis->unk_194 == 0) {
        func_80B32384(pthis);
    }
}

void func_80B331CC(EnWeiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    if (pthis->actor.bgCheckFlags & 8) {
        pthis->unk_196 = pthis->actor.wallYaw;
    } else {
        pthis->unk_196 = pthis->actor.yawTowardsPlayer + 0x8000;
    }

    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->unk_196, 0x38E);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x200);
    pthis->actor.shape.rot.z = sinf(pthis->unk_194 * (M_PI / 5)) * 5120.0f;

    if (pthis->unk_194 == 0) {
        pthis->actor.shape.rot.z = 0;
        pthis->collider.base.acFlags |= AC_ON;
        func_80B32384(pthis);
    }
}

void func_80B332B4(EnWeiyer* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.shape.rot.x, -0x4000, 0x400);
    pthis->actor.shape.rot.z += 0x1000;

    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    if ((pthis->unk_194 == 0) || (pthis->actor.bgCheckFlags & 0x10)) {
        func_80B327B0(pthis);
    }
}

void func_80B33338(EnWeiyer* pthis, GlobalContext* globalCtx) {
    pthis->actor.shape.shadowAlpha = CLAMP_MIN((s16)(pthis->actor.shape.shadowAlpha - 5), 0);
    pthis->actor.world.pos.y -= 2.0f;

    if (pthis->actor.shape.shadowAlpha == 0) {
        Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0xE0);
        Actor_Kill(&pthis->actor);
    }
}

void func_80B333B8(EnWeiyer* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_194 != 0) {
        pthis->unk_194--;
    }

    Math_ScaledStepToS(&pthis->actor.shape.rot.x, 0, 0x200);
    Math_ScaledStepToS(&pthis->actor.shape.rot.z, 0, 0x200);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actor.home.pos.y < pthis->actor.floorHeight) {
        if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_FLUTTER);
        }

        if (pthis->actor.bgCheckFlags & 2) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_GND);
        }
    }

    if (pthis->unk_194 == 0) {
        pthis->actor.gravity = 0.0f;
        pthis->actor.velocity.y = 0.0f;
        pthis->collider.dim.height = sCylinderInit.dim.height;
        func_80B32384(pthis);
    }
}

void func_80B3349C(EnWeiyer* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 phi_a1;
    s32 phi_a0;

    SkelAnime_Update(&pthis->skelAnime);

    phi_a0 = ((pthis->actor.home.pos.y + 20.0f) <= player->actor.world.pos.y);

    if (pthis->unk_194 == -1) {
        if (phi_a0 || (pthis->collider.base.atFlags & AT_HIT)) {
            func_80B32538(pthis);
        } else if (pthis->actor.yDistToWater < 0.0f) {
            pthis->unk_194 = 10;
            EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 1, 400);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_JUMP);
        }
    } else {
        if (phi_a0 || (pthis->collider.base.atFlags & AT_HIT)) {
            pthis->unk_194 = 0;
        } else if (pthis->unk_194 != 0) {
            pthis->unk_194--;
        }

        if (pthis->unk_194 == 0) {
            phi_a1 = 0x1800;
        } else {
            phi_a1 = func_80B32DEC(pthis, globalCtx);
            phi_a1 = CLAMP_MIN(phi_a1, 0);
        }

        if (pthis->actor.shape.rot.x < phi_a1) {
            Math_ScaledStepToS(&pthis->actor.shape.rot.x, phi_a1, 0x400);
        }

        if (pthis->actor.bgCheckFlags & 1) {
            func_80B32434(pthis);
        } else if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actor.shape.rot.x > 0)) {
            EffectSsGSplash_Spawn(globalCtx, &pthis->actor.world.pos, NULL, NULL, 1, 400);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_OCTAROCK_SINK);
            func_80B32538(pthis);
        } else {
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 8, 0x100, 0x80);
        }
    }
}

void func_80B3368C(EnWeiyer* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);

        if ((pthis->actor.colChkInfo.damageEffect != 0) || (pthis->actor.colChkInfo.damage != 0)) {
            if (pthis->actor.colChkInfo.damageEffect == 1) {
                if (pthis->actionFunc != func_80B333B8) {
                    func_80B32660(pthis);
                }
            } else if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_DEAD);
                pthis->actor.flags &= ~ACTOR_FLAG_0;
                func_80B32724(pthis);
            } else {
                func_80B325A0(pthis);
            }
        }
    }
}

void EnWeiyer_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnWeiyer* pthis = (EnWeiyer*)thisx;
    s32 pad;

    pthis->actor.home.pos.y = pthis->actor.yDistToWater + pthis->actor.world.pos.y - 5.0f;
    func_80B3368C(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.world.rot.x = -pthis->actor.shape.rot.x;

    if ((pthis->actor.world.rot.x == 0) || (pthis->actionFunc == func_80B333B8)) {
        Actor_MoveForward(&pthis->actor);
    } else {
        func_8002D97C(&pthis->actor);
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 30.0f, 45.0f, 7);
    Actor_SetFocus(&pthis->actor, 0.0f);

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~(AT_ON | AT_HIT);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EIER_ATTACK);
    }

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if (pthis->collider.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    if (pthis->collider.base.acFlags & AT_ON) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

s32 EnWeiyer_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                              Gfx** gfx) {
    if (limbIndex == 1) {
        pos->z += 2000.0f;
    }

    return 0;
}

void EnWeiyer_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnWeiyer* pthis = (EnWeiyer*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_weiyer.c", 1193);

    if (pthis->actionFunc != func_80B33338) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x08, &D_80116280[2]);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnWeiyer_OverrideLimbDraw, NULL, &pthis->actor, POLY_OPA_DISP);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08, &D_80116280[0]);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, pthis->actor.shape.shadowAlpha);
        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                       EnWeiyer_OverrideLimbDraw, NULL, &pthis->actor, POLY_XLU_DISP);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_weiyer.c", 1240);
}

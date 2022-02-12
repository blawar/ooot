#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PO_SISTERS_Z_EN_PO_SISTERS_C
#include "actor_common.h"
/*
 * File: z_en_po_sisters.c
 * Overlay: ovl_En_Po_Sisters
 * Description: Forest Temple Four Poe Sisters
 */

#include "z_en_po_sisters.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_po_sisters/object_po_sisters.h"
#include "def/code_8006BA00.h"
#include "def/code_800EC960.h"
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
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_9 | ACTOR_FLAG_12 | ACTOR_FLAG_14)

void EnPoSisters_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoSisters_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoSisters_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPoSisters_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80ADA094(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA4A8(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA530(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA6A0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA7F0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA8C0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADA9E8(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADAAA4(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADAC70(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADAD54(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADAE6C(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADAFC0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB17C(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB2B8(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB338(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB9F0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB4B0(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB51C(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADB770(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBB6C(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBBF4(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBC88(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBD38(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBD8C(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBEE8(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80ADBF58(EnPoSisters* pthis, GlobalContext* globalCtx);

void func_80AD9AA8(EnPoSisters* pthis, GlobalContext* globalCtx);
void func_80AD9C24(EnPoSisters* pthis, GlobalContext* globalCtx);

void func_80AD9D44(EnPoSisters* pthis);

static Color_RGBA8 D_80ADD6F0[4] = {
    { 255, 170, 255, 255 },
    { 255, 200, 0, 255 },
    { 0, 170, 255, 255 },
    { 170, 255, 0, 255 },
};

static Color_RGBA8 D_80ADD700[4] = {
    { 100, 0, 255, 255 },
    { 255, 0, 0, 255 },
    { 0, 0, 255, 255 },
    { 0, 150, 0, 255 },
};

ActorInit En_Po_Sisters_InitVars = {
    ACTOR_EN_PO_SISTERS,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_PO_SISTERS,
    sizeof(EnPoSisters),
    (ActorFunc)EnPoSisters_Init,
    (ActorFunc)EnPoSisters_Destroy,
    (ActorFunc)EnPoSisters_Update,
    (ActorFunc)EnPoSisters_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0x4FC7FFEA, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 18, 60, 15, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 10, 25, 60, 40 };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0xF),
    /* Deku stick    */ DMG_ENTRY(2, 0x0),
    /* Slingshot     */ DMG_ENTRY(1, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(2, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(2, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xE),
    /* Master sword  */ DMG_ENTRY(2, 0xE),
    /* Giant's Knife */ DMG_ENTRY(4, 0xE),
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
    /* Kokiri spin   */ DMG_ENTRY(1, 0xE),
    /* Giant spin    */ DMG_ENTRY(4, 0xE),
    /* Master spin   */ DMG_ENTRY(2, 0xE),
    /* Kokiri jump   */ DMG_ENTRY(2, 0xE),
    /* Giant jump    */ DMG_ENTRY(8, 0xE),
    /* Master jump   */ DMG_ENTRY(4, 0xE),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static s32 D_80ADD784 = 0;

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 7, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 6000, ICHAIN_STOP),
};

static Vec3f sZeroVector = { 0.0f, 0.0f, 0.0f };

static s16 D_80ADD79C[4] = { 0xB000, 0xD000, 0x5000, 0x3000 };

static Vec3s D_80ADD7A4[4] = {
    { -22, 337, -1704 },
    { -431, 879, -3410 },
    { 549, 879, -3410 },
    { 1717, 515, -1340 },
};

static Vec3f D_80ADD7BC = { 120.0f, 250.0f, -1420.0f };

static Gfx* D_80ADD7C8[4] = {
    gPoeSistersMegBodyDL,
    gPoeSistersJoelleBodyDL,
    gPoeSistersBethBodyDL,
    gPoeSistersAmyBodyDL,
};

static Gfx* D_80ADD7D8[4] = {
    gPoeSistersMegFaceDL,
    gPoeSistersJoelleFaceDL,
    gPoeSistersBethFaceDL,
    gPoSistersAmyFaceDL,
};

static Color_RGBA8 D_80ADD7E8[4] = {
    { 80, 0, 100, 0 },
    { 80, 15, 0, 0 },
    { 0, 70, 50, 0 },
    { 70, 70, 0, 0 },
};

static Vec3f D_80ADD7F8 = { 1000.0f, -1700.0f, 0.0f };

void EnPoSisters_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnPoSisters* pthis = (EnPoSisters*)thisx;
    s32 pad;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 50.0f);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gPoeSistersSkel, &gPoeSistersSwayAnim, pthis->jointTable,
                   pthis->morphTable, 12);
    pthis->unk_22E.r = 255;
    pthis->unk_22E.g = 255;
    pthis->unk_22E.b = 210;
    pthis->unk_22E.a = 255;
    pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
    Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z, 0,
                            0, 0, 0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    pthis->unk_194 = (thisx->params >> 8) & 3;
    pthis->actor.naviEnemyId = pthis->unk_194 + 0x50;
    if (1) {}
    pthis->unk_195 = (thisx->params >> 0xA) & 3;
    pthis->unk_196 = 32;
    pthis->unk_197 = 20;
    pthis->unk_198 = 1;
    pthis->unk_199 = 32;
    pthis->unk_294 = 110.0f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    if (pthis->actor.params & 0x1000) {
        func_80ADA094(pthis, globalCtx);
    } else if (pthis->unk_194 == 0) {
        if (pthis->unk_195 == 0) {
            pthis->collider.base.ocFlags1 = OC1_ON | OC1_TYPE_PLAYER;
            func_80AD9AA8(pthis, globalCtx);
        } else {
            pthis->actor.flags &= ~(ACTOR_FLAG_9 | ACTOR_FLAG_14);
            pthis->collider.info.elemType = ELEMTYPE_UNK4;
            pthis->collider.info.bumper.dmgFlags |= 1;
            pthis->collider.base.ocFlags1 = OC1_NONE;
            func_80AD9C24(pthis, NULL);
        }
    } else {
        func_80AD9D44(pthis);
    }
    pthis->actor.params &= 0x3F;
}

void EnPoSisters_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnPoSisters* pthis = (EnPoSisters*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
    if (pthis->unk_194 == 0 && pthis->unk_195 == 0) {
        func_800F5B58();
    }
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80AD9240(EnPoSisters* pthis, s32 arg1, Vec3f* arg2) {
    f32 temp_f20 = SQ(arg1) * 0.1f;
    Vec3f* vec;
    s32 i;

    for (i = 0; i < pthis->unk_198; i++) {
        vec = &pthis->unk_234[i];
        vec->x = arg2->x + Math_SinS((s16)(pthis->actor.shape.rot.y + (pthis->unk_19A * 0x800) + i * 0x2000)) * temp_f20;
        vec->z = arg2->z + Math_CosS((s16)(pthis->actor.shape.rot.y + (pthis->unk_19A * 0x800) + i * 0x2000)) * temp_f20;
        vec->y = arg2->y + arg1;
    }
}

void func_80AD9368(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersSwayAnim, -3.0f);
    pthis->unk_19A = Rand_S16Offset(2, 3);
    pthis->actionFunc = func_80ADA4A8;
    pthis->actor.speedXZ = 0.0f;
}

void func_80AD93C4(EnPoSisters* pthis) {
    if (pthis->actionFunc != func_80ADA6A0) {
        Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFloatAnim, -3.0f);
    }
    pthis->unk_19A = Rand_S16Offset(0xF, 3);
    pthis->unk_199 |= 7;
    pthis->actionFunc = func_80ADA530;
}

void func_80AD943C(EnPoSisters* pthis) {
    pthis->actionFunc = func_80ADA6A0;
}

void func_80AD944C(EnPoSisters* pthis) {
    if (pthis->unk_22E.a != 0) {
        pthis->collider.base.colType = COLTYPE_METAL;
        pthis->collider.base.acFlags |= AC_HARD;
    }
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersAttackAnim, -5.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_19A = Animation_GetLastFrame(&gPoeSistersAttackAnim) * 3 + 3;
    pthis->unk_199 &= ~2;
    pthis->actionFunc = func_80ADA7F0;
}

void func_80AD94E0(EnPoSisters* pthis) {
    pthis->actor.speedXZ = 5.0f;
    if (pthis->unk_194 == 0) {
        pthis->collider.base.colType = COLTYPE_METAL;
        pthis->collider.base.acFlags |= AC_HARD;
        Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersAttackAnim, -5.0f);
    }
    pthis->unk_19A = 5;
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    pthis->unk_199 |= 8;
    pthis->actionFunc = func_80ADA8C0;
}

void func_80AD9568(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFloatAnim, -3.0f);
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
    if (pthis->unk_194 != 0) {
        pthis->collider.base.colType = COLTYPE_HIT3;
        pthis->collider.base.acFlags &= ~AC_HARD;
    }
    pthis->actionFunc = func_80ADA9E8;
}

void func_80AD95D8(EnPoSisters* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gPoeSistersDamagedAnim, -3.0f);
    if (pthis->collider.base.ac != NULL) {
        pthis->actor.world.rot.y = (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x1F824)
                                      ? pthis->collider.base.ac->world.rot.y
                                      : Actor_WorldYawTowardActor(&pthis->actor, pthis->collider.base.ac) + 0x8000;
    }
    if (pthis->unk_194 != 0) {
        pthis->actor.speedXZ = 10.0f;
    }
    pthis->unk_199 &= ~0xB;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 0x10);
    pthis->actionFunc = func_80ADAAA4;
}

void func_80AD96A4(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFleeAnim, -3.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
    pthis->unk_19A = 5;
    pthis->unk_199 |= 0xB;
    pthis->actor.speedXZ = 5.0f;
    pthis->actionFunc = func_80ADAC70;
}

void func_80AD9718(EnPoSisters* pthis) {
    Animation_Change(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim, 1.5f, 0.0f,
                     Animation_GetLastFrame(&gPoeSistersAppearDisappearAnim), ANIMMODE_ONCE, -3.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->unk_19C = 100;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->unk_199 &= ~5;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DISAPPEAR);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
    pthis->actionFunc = func_80ADAD54;
}

void func_80AD97C8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 sp20;

    if (pthis->unk_195 == 0 || pthis->actionFunc != func_80ADAAA4) {
        if ((player->swordState == 0 || player->swordAnimation >= 24) &&
            player->actor.world.pos.y - player->actor.floorHeight < 1.0f) {
            Math_StepToF(&pthis->unk_294, 110.0f, 3.0f);
        } else {
            Math_StepToF(&pthis->unk_294, 170.0f, 10.0f);
        }
        sp20 = pthis->unk_294;
    } else if (pthis->unk_195 != 0) {
        sp20 = pthis->actor.parent->xzDistToPlayer;
    }
    pthis->actor.world.pos.x = (Math_SinS(pthis->actor.shape.rot.y + 0x8000) * sp20) + player->actor.world.pos.x;
    pthis->actor.world.pos.z = (Math_CosS(pthis->actor.shape.rot.y + 0x8000) * sp20) + player->actor.world.pos.z;
}

void func_80AD98F4(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim, 1.5f, 0.0f,
                     Animation_GetLastFrame(&gPoeSistersAppearDisappearAnim), ANIMMODE_ONCE, -3.0f);
    if (pthis->unk_194 == 0) {
        pthis->unk_294 = 110.0f;
        func_80AD97C8(pthis, globalCtx);
        pthis->unk_22E.a = 0;
        pthis->actor.draw = EnPoSisters_Draw;
    } else {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    }
    pthis->unk_19A = 15;
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
    pthis->unk_199 &= ~1;
    pthis->actionFunc = func_80ADAE6C;
}

void func_80AD99D4(EnPoSisters* pthis, GlobalContext* globalCtx) {
    pthis->unk_19A = 0;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.pos.y += 42.0f;
    pthis->actor.shape.yOffset = -6000.0f;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->unk_199 = 0;
    pthis->actionFunc = func_80ADAFC0;
    OnePointCutscene_Init(globalCtx, 3190, 999, &pthis->actor, MAIN_CAM);
}

void func_80AD9A54(EnPoSisters* pthis, GlobalContext* globalCtx) {
    pthis->unk_19A = 0;
    pthis->actor.world.pos.y = pthis->unk_234[0].y;
    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos, 0x80);
    pthis->actionFunc = func_80ADB17C;
}

// Meg spawning fakes
void func_80AD9AA8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Actor* actor1 = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_PO_SISTERS, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0x400);
    Actor* actor2 = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_PO_SISTERS, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0x800);
    Actor* actor3 = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_PO_SISTERS, pthis->actor.world.pos.x,
                                pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0xC00);
    s32 pad;
    s32 pad1;

    if (actor1 == NULL || actor2 == NULL || actor3 == NULL) {
        if (actor1 != NULL) {
            Actor_Kill(actor1);
        }
        if (actor2 != NULL) {
            Actor_Kill(actor2);
        }
        if (actor3 != NULL) {
            Actor_Kill(actor3);
        }
        Actor_Kill(&pthis->actor);
    } else {
        actor3->parent = &pthis->actor;
        actor2->parent = &pthis->actor;
        actor1->parent = &pthis->actor;
        Animation_PlayLoop(&pthis->skelAnime, &gPoeSistersMegCryAnim);
        pthis->unk_198 = 0;
        pthis->unk_199 = 160;
        pthis->actionFunc = func_80ADB2B8;
    }
}

void func_80AD9C24(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Vec3f vec;

    pthis->actor.draw = NULL;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->unk_19C = 100;
    pthis->unk_199 = 32;
    pthis->collider.base.colType = COLTYPE_HIT3;
    pthis->collider.base.acFlags &= ~AC_HARD;
    if (globalCtx != NULL) {
        vec.x = pthis->actor.world.pos.x;
        vec.y = pthis->actor.world.pos.y + 45.0f;
        vec.z = pthis->actor.world.pos.z;
        EffectSsDeadDb_Spawn(globalCtx, &vec, &sZeroVector, &sZeroVector, 150, 0, 255, 255, 255, 155, 150, 150, 150, 1,
                             9, 0);
    }
    Lights_PointSetColorAndRadius(&pthis->lightInfo, 0, 0, 0, 0);
    pthis->actionFunc = func_80ADB338;
}

void func_80AD9D44(EnPoSisters* pthis) {
    if (pthis->unk_194 == 3) {
        Animation_PlayOnce(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
    } else {
        Animation_Change(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim, 0.5f, 0.0f,
                         Animation_GetLastFrame(&gPoeSistersAppearDisappearAnim), ANIMMODE_ONCE_INTERP, 0.0f);
    }
    pthis->unk_22E.a = 0;
    pthis->unk_199 = 32;
    pthis->actionFunc = func_80ADB9F0;
}

void func_80AD9DF0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim, -5.0f);
    pthis->unk_198 = 1;
    pthis->unk_199 &= ~0x80;
    pthis->actionFunc = func_80ADB4B0;
    OnePointCutscene_Init(globalCtx, 3180, 156, &pthis->actor, MAIN_CAM);
}

void func_80AD9E60(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFloatAnim, -3.0f);
    pthis->unk_19A = Animation_GetLastFrame(&gPoeSistersFloatAnim) * 7 + 7;
    if (pthis->actor.parent != NULL) {
        pthis->actor.world.pos = pthis->actor.parent->world.pos;
        pthis->actor.shape.rot.y = pthis->actor.parent->shape.rot.y;
    } else {
        pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->unk_19A++;
    }
    if (pthis->unk_195 == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
    }
    pthis->actionFunc = func_80ADB51C;
}

void func_80AD9F1C(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFloatAnim, -3.0f);
    pthis->unk_22E.a = 255;
    pthis->unk_19A = 300;
    pthis->unk_19C = 3;
    pthis->unk_199 |= 9;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = func_80ADB770;
}

void func_80AD9F90(EnPoSisters* pthis) {
    if (pthis->unk_194 == 1) {
        pthis->actor.home.pos.x = -632.0f;
        pthis->actor.home.pos.z = -3440.0f;
    } else {
        pthis->actor.home.pos.x = 752.0f;
        pthis->actor.home.pos.z = -3440.0f;
    }
    Animation_PlayLoop(&pthis->skelAnime, &gPoeSistersFloatAnim);
    pthis->unk_199 |= 0xA;
    pthis->actionFunc = func_80ADBB6C;
    pthis->actor.speedXZ = 5.0f;
}

void func_80ADA028(EnPoSisters* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersSwayAnim, -3.0f);
    pthis->unk_22E.a = 255;
    pthis->unk_199 |= 0x15;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = func_80ADBBF4;
    pthis->actor.speedXZ = 0.0f;
}

void func_80ADA094(EnPoSisters* pthis, GlobalContext* globalCtx) {
    D_80ADD784 = 0;
    pthis->unk_22E.a = 0;
    pthis->unk_199 = 128;
    pthis->unk_19A = 50;
    pthis->unk_234[0] = pthis->actor.home.pos;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
    pthis->actionFunc = func_80ADBC88;
}

void func_80ADA10C(EnPoSisters* pthis) {
    s32 i;

    pthis->unk_198 = ARRAY_COUNT(pthis->unk_234);
    for (i = 0; i < ARRAY_COUNT(pthis->unk_234); i++) {
        pthis->unk_234[i] = pthis->unk_234[0];
    }
    pthis->actionFunc = func_80ADBD38;
}

void func_80ADA1B8(EnPoSisters* pthis) {
    Animation_Change(&pthis->skelAnime, &gPoeSistersAppearDisappearAnim, 0.833f, 0.0f,
                     Animation_GetLastFrame(&gPoeSistersAppearDisappearAnim), ANIMMODE_ONCE_INTERP, 0.0f);
    if (pthis->unk_194 == 0 || pthis->unk_194 == 1) {
        pthis->unk_19A = 40;
    } else {
        pthis->unk_19A = 76;
    }
    pthis->unk_198 = 0;
    D_80ADD784 = 0;
    pthis->actionFunc = func_80ADBD8C;
}

void func_80ADA25C(EnPoSisters* pthis) {
    Animation_PlayLoop(&pthis->skelAnime, &gPoeSistersSwayAnim);
    pthis->unk_198 = 8;
    pthis->unk_19A = 32;
    func_80AD9240(pthis, pthis->unk_19A, &pthis->actor.home.pos);
    pthis->actionFunc = func_80ADBEE8;
}

void func_80ADA2BC(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeSistersFloatAnim, -3.0f);
    pthis->unk_198 = 0;
    pthis->unk_199 = 40;
    pthis->unk_19A = 90;
    pthis->unk_196 = 32;
    pthis->actor.world.rot.y = D_80ADD79C[pthis->unk_194];
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    if (pthis->unk_194 == 0) {
        Flags_SetSwitch(globalCtx, 0x1B);
    }
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FLAME_IGNITION);
    pthis->actionFunc = func_80ADBF58;
}

void func_80ADA35C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    f32 targetY;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->actionFunc == func_80ADBF58) {
        targetY = pthis->actor.home.pos.y;
    } else if (pthis->unk_194 == 0 || pthis->unk_194 == 3) {
        targetY = player->actor.world.pos.y + 5.0f;
    } else {
        targetY = 832.0f;
    }
    Math_ApproachF(&pthis->actor.world.pos.y, targetY, 0.5f, 3.0f);
    if (!pthis->unk_196) {
        pthis->unk_196 = 32;
    }
    if (pthis->unk_196 != 0) {
        pthis->unk_196--;
    }
    pthis->actor.world.pos.y += (2.0f + 0.5f * Rand_ZeroOne()) * Math_SinS(pthis->unk_196 * 0x800);
    if (pthis->unk_22E.a == 255 && pthis->actionFunc != func_80ADA8C0 && pthis->actionFunc != func_80ADA7F0) {
        if (pthis->actionFunc == func_80ADAC70) {
            func_8002F974(&pthis->actor, NA_SE_EN_PO_AWAY - SFX_FLAG);
        } else {
            func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
        }
    }
}

void func_80ADA4A8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    if (pthis->unk_19A == 0 || pthis->actor.xzDistToPlayer < 200.0f) {
        func_80AD93C4(pthis);
    }
}

void func_80ADA530(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_StepToF(&pthis->actor.speedXZ, 1.0f, 0.2f);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    if (pthis->actor.xzDistToPlayer < 200.0f && fabsf(pthis->actor.yDistToPlayer + 5.0f) < 30.0f) {
        func_80AD943C(pthis);
    } else if (pthis->unk_19A == 0 && Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.2f) != 0) {
        func_80AD9368(pthis);
    }
    if (pthis->actor.bgCheckFlags & 8) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos),
                           0x71C);
    } else if (Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) > 300.0f) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos),
                           0x71C);
    }
}

void func_80ADA6A0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 temp_v0;

    SkelAnime_Update(&pthis->skelAnime);
    temp_v0 = pthis->actor.yawTowardsPlayer - player->actor.shape.rot.y;
    Math_StepToF(&pthis->actor.speedXZ, 2.0f, 0.2f);
    if (temp_v0 > 0x3000) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x3000, 0x71C);
    } else if (temp_v0 < -0x3000) {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer - 0x3000, 0x71C);
    } else {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0x71C);
    }
    if (pthis->actor.xzDistToPlayer < 160.0f && fabsf(pthis->actor.yDistToPlayer + 5.0f) < 30.0f) {
        func_80AD944C(pthis);
    } else if (pthis->actor.xzDistToPlayer > 240.0f) {
        func_80AD93C4(pthis);
    }
}

void func_80ADA7F0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    pthis->actor.shape.rot.y += 384.0f * ((pthis->skelAnime.endFrame + 1.0f) * 3.0f - pthis->unk_19A);
    if (pthis->unk_19A == 18 || pthis->unk_19A == 7) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_ROLL);
    }
    if (pthis->unk_19A == 0) {
        func_80AD94E0(pthis);
    }
}

void func_80ADA8C0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    s32 pad;

    SkelAnime_Update(&pthis->skelAnime);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    pthis->actor.shape.rot.y += (384.0f * pthis->skelAnime.endFrame) * 3.0f;
    if (pthis->unk_19A == 0 && ABS((s16)(pthis->actor.shape.rot.y - pthis->actor.world.rot.y)) < 0x1000) {
        if (pthis->unk_194 != 0) {
            pthis->collider.base.colType = COLTYPE_HIT3;
            pthis->collider.base.acFlags &= ~AC_HARD;
            func_80AD93C4(pthis);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
            func_80AD9C24(pthis, globalCtx);
        }
    }
    if (Animation_OnFrame(&pthis->skelAnime, 1.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_ROLL);
    }
}

void func_80ADA9E8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    pthis->actor.shape.rot.y -= (pthis->actor.speedXZ * 10.0f) * 128.0f;
    if (Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.1f) != 0) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        if (pthis->unk_194 != 0) {
            func_80AD93C4(pthis);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
            func_80AD9C24(pthis, globalCtx);
        }
    }
}

void func_80ADAAA4(EnPoSisters* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime) && !(pthis->actor.flags & ACTOR_FLAG_15)) {
        if (pthis->actor.colChkInfo.health != 0) {
            if (pthis->unk_194 != 0) {
                func_80AD96A4(pthis);
            } else if (pthis->unk_195 != 0) {
                func_80AD9C24(pthis, NULL);
            } else {
                func_80AD9C24(pthis, globalCtx);
            }
        } else {
            func_80AD99D4(pthis, globalCtx);
        }
    }
    if (pthis->unk_195 != 0) {
        Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.parent->shape.rot.y,
                           (pthis->unk_195 == 2) ? 0x800 : 0x400);
        pthis->unk_22E.a = ((pthis->skelAnime.endFrame - pthis->skelAnime.curFrame) * 255.0f) / pthis->skelAnime.endFrame;
        pthis->actor.world.pos.y = pthis->actor.parent->world.pos.y;
        func_80AD97C8(pthis, globalCtx);
    } else if (pthis->unk_194 != 0) {
        Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    }
}

void func_80ADAC70(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer + 0x8000, 1820);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) && pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    if (pthis->actor.bgCheckFlags & 8) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        pthis->unk_199 |= 2;
        func_80AD9718(pthis);
    } else if (pthis->unk_19A == 0 && 240.0f < pthis->actor.xzDistToPlayer) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        func_80AD93C4(pthis);
    }
}

void func_80ADAD54(EnPoSisters* pthis, GlobalContext* globalCtx) {
    s32 endFrame;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_22E.a = 0;
        pthis->collider.info.bumper.dmgFlags = 0x00060001;
        func_80AD93C4(pthis);
    } else {
        endFrame = pthis->skelAnime.endFrame;
        pthis->unk_22E.a = ((endFrame - pthis->skelAnime.curFrame) * 255.0f) / endFrame;
    }
}

void func_80ADAE6C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_22E.a = 255;
        if (pthis->unk_194 != 0) {
            pthis->unk_199 |= 1;
            pthis->collider.info.bumper.dmgFlags = 0x4FC7FFEA;
            if (pthis->unk_19A != 0) {
                pthis->unk_19A--;
            }
            if (pthis->unk_19A == 0) {
                pthis->unk_197 = 20;
                func_80AD93C4(pthis);
            }
        } else {
            func_80AD9F1C(pthis);
        }
    } else {
        pthis->unk_22E.a = (pthis->skelAnime.curFrame * 255.0f) / pthis->skelAnime.endFrame;
        if (pthis->unk_194 == 0) {
            func_80AD97C8(pthis, globalCtx);
        }
    }
}

void func_80ADAFC0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    s32 i;

    pthis->unk_19A++;
    pthis->unk_198 = CLAMP_MAX(pthis->unk_198 + 1, 8);
    for (i = pthis->unk_198 - 1; i > 0; i--) {
        pthis->unk_234[i] = pthis->unk_234[i - 1];
    }
    pthis->unk_234[0].x =
        (Math_SinS((pthis->actor.shape.rot.y + pthis->unk_19A * 0x3000) - 0x4000) * (3000.0f * pthis->actor.scale.x)) +
        pthis->actor.world.pos.x;
    pthis->unk_234[0].z =
        (Math_CosS((pthis->actor.shape.rot.y + pthis->unk_19A * 0x3000) - 0x4000) * (3000.0f * pthis->actor.scale.x)) +
        pthis->actor.world.pos.z;
    if (pthis->unk_19A < 8) {
        pthis->unk_234[0].y = pthis->unk_234[1].y - 9.0f;
    } else {
        pthis->unk_234[0].y = pthis->unk_234[1].y + 2.0f;
        if (pthis->unk_19A >= 16) {
            if (Math_StepToF(&pthis->actor.scale.x, 0.0f, 0.001f) != 0) {
                func_80AD9A54(pthis, globalCtx);
            }
            pthis->actor.scale.z = pthis->actor.scale.x;
            pthis->actor.scale.y = pthis->actor.scale.x;
        }
    }
    if (pthis->unk_19A == 16) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DEAD2);
    }
}

void func_80ADB17C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    pthis->unk_19A++;
    if (pthis->unk_19A == 64) {
        Flags_SetSwitch(globalCtx, pthis->actor.params);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 30, NA_SE_EV_FLAME_IGNITION);
        if (pthis->unk_194 == 0) {
            Flags_UnsetSwitch(globalCtx, 0x1B);
        }
        globalCtx->envCtx.unk_BF = 0xFF;
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        Actor_Kill(&pthis->actor);
    } else if (pthis->unk_19A < 32) {
        func_80AD9240(pthis, pthis->unk_19A, &pthis->actor.world.pos);
    } else {
        func_80AD9240(pthis, 64 - pthis->unk_19A, &pthis->actor.world.pos);
    }
    if (pthis->unk_19A == 32) {
        pthis->actor.world.pos.x = D_80ADD7A4[pthis->unk_194].x;
        pthis->actor.world.pos.y = D_80ADD7A4[pthis->unk_194].y;
        pthis->actor.world.pos.z = D_80ADD7A4[pthis->unk_194].z;
    }
}

void func_80ADB2B8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actor.xzDistToPlayer < 130.0f) {
        func_80AD9DF0(pthis, globalCtx);
    }
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_CRY);
    }
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
}

void func_80ADB338(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    EnPoSisters* realMeg = (EnPoSisters*)pthis->actor.parent;

    if (pthis->unk_195 == 0) {
        if (Actor_WorldDistXZToPoint(&player->actor, &pthis->actor.home.pos) < 600.0f) {
            if (pthis->unk_19C != 0) {
                pthis->unk_19C--;
            }
        } else {
            pthis->unk_19C = 100;
        }
        if (pthis->unk_19C == 0) {
            pthis->actor.shape.rot.y = (s32)(4.0f * Rand_ZeroOne()) * 0x4000 + pthis->actor.yawTowardsPlayer;
            pthis->actor.world.pos.y = player->actor.world.pos.y + 5.0f;
            func_80AD98F4(pthis, globalCtx);
        }
    } else {
        if (realMeg->actionFunc == func_80ADB51C) {
            pthis->actor.draw = EnPoSisters_Draw;
            func_80AD9E60(pthis);
        } else if (realMeg->actionFunc == func_80ADAE6C) {
            pthis->actor.shape.rot.y = pthis->actor.parent->shape.rot.y + pthis->unk_195 * 0x4000;
            pthis->actor.world.pos.y = player->actor.world.pos.y + 5.0f;
            func_80AD98F4(pthis, globalCtx);
        } else if (realMeg->actionFunc == func_80ADAFC0) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void func_80ADB4B0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        func_80AD9E60(pthis);
    }
    func_80AD97C8(pthis, globalCtx);
    pthis->actor.world.pos.y += 1.0f;
    Actor_SetFocus(&pthis->actor, 40.0f);
}

void func_80ADB51C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    f32 temp_f2;
    s16 phi_v0;
    s16 phi_a2;
    u8 temp;

    SkelAnime_Update(&pthis->skelAnime);
    temp_f2 = pthis->skelAnime.endFrame * 0.5f;
    pthis->unk_22E.a = (fabsf(temp_f2 - pthis->skelAnime.curFrame) * 255.0f) / temp_f2;
    if (pthis->unk_19A != 0) {
        pthis->unk_19A -= 1;
    }
    if (pthis->unk_19A == 0) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y += 0x4000 * (s32)(Rand_ZeroOne() * 4.0f);
        if (pthis->unk_195 == 0) {
            func_800F5ACC(NA_BGM_MINI_BOSS);
        }
        func_80AD9F1C(pthis);
    } else {
        pthis->actor.world.pos.y += 0.1f;
        temp = pthis->unk_195;
        if (temp != 0) {
            if (pthis->unk_19A > 90) {
                phi_v0 = 1;
                phi_a2 = 64;
            } else if (pthis->unk_19A > 70) {
                phi_v0 = 0;
                phi_a2 = 64;
            } else if (pthis->unk_19A > 55) {
                phi_v0 = 1;
                phi_a2 = 96;
            } else if (pthis->unk_19A > 40) {
                phi_v0 = 0;
                phi_a2 = 96;
            } else {
                phi_v0 = 1;
                phi_a2 = 256;
            }
            if (pthis->unk_195 == 2) {
                phi_a2 *= 2;
            }
            Math_ScaledStepToS(&pthis->actor.shape.rot.y,
                               pthis->actor.parent->shape.rot.y + (pthis->unk_195 * 0x4000) * phi_v0, phi_a2);
        } else if (pthis->unk_19A == 70 || pthis->unk_19A == 40) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
        }
    }
    func_80AD97C8(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 40.0f);
}

void func_80ADB770(EnPoSisters* pthis, GlobalContext* globalCtx) {
    s32 temp_v0;
    s32 phi_a0;

    if (pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    if (pthis->unk_19C > 0) {
        if (pthis->unk_19A >= 16) {
            SkelAnime_Update(&pthis->skelAnime);
            if (pthis->unk_195 == 0) {
                if (ABS((s16)(16 - pthis->unk_196)) < 14) {
                    pthis->actor.shape.rot.y +=
                        (0x580 - (pthis->unk_19C * 0x180)) * fabsf(Math_SinS(pthis->unk_196 * 0x800));
                }
                if (pthis->unk_19A >= 284 || pthis->unk_19A < 31) {
                    pthis->unk_199 |= 0x40;
                } else {
                    pthis->unk_199 &= ~0x40;
                }
            } else {
                pthis->actor.shape.rot.y = (s16)(pthis->actor.parent->shape.rot.y + (pthis->unk_195 * 0x4000));
            }
        }
    }
    if (pthis->unk_195 == 0) {
        if (pthis->unk_19A >= 284 || (pthis->unk_19A < 31 && pthis->unk_19A >= 16)) {
            pthis->unk_199 |= 0x40;
        } else {
            pthis->unk_199 &= ~0x40;
        }
    }
    if (Actor_WorldDistXZToPoint(&GET_PLAYER(globalCtx)->actor, &pthis->actor.home.pos) > 600.0f) {
        pthis->unk_199 &= ~0x40;
        func_80AD9C24(pthis, globalCtx);
    } else if (pthis->unk_19A == 0) {
        if (pthis->unk_195 == 0) {
            func_80AD94E0(pthis);
        } else {
            func_80AD9C24(pthis, globalCtx);
        }
    } else if (pthis->unk_195 != 0) {
        EnPoSisters* realMeg = (EnPoSisters*)pthis->actor.parent;

        if (realMeg->actionFunc == func_80ADAAA4) {
            func_80AD95D8(pthis);
        }
    } else if (pthis->unk_19C == 0) {
        pthis->unk_19C = -15;
    } else if (pthis->unk_19C < 0) {
        pthis->unk_19C++;
        if (pthis->unk_19C == 0) {
            func_80AD94E0(pthis);
        }
    }
    func_80AD97C8(pthis, globalCtx);
}

void func_80ADB9F0(EnPoSisters* pthis, GlobalContext* globalCtx) {
    f32 div;

    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->unk_22E.a = 255;
        if (pthis->unk_194 == 3) {
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->actor.home.pos.x = 1992.0f;
            pthis->actor.home.pos.z = -1440.0f;
            pthis->unk_199 |= 0x18;
            func_80AD93C4(pthis);
        } else {
            func_80AD9F90(pthis);
        }
    } else {
        div = pthis->skelAnime.curFrame / pthis->skelAnime.endFrame;
        pthis->unk_22E.a = 255.0f * div;
    }
    if (pthis->unk_194 != 3 && Animation_OnFrame(&pthis->skelAnime, 1.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
    }
    Actor_SetFocus(&pthis->actor, 40.0f);
}

void func_80ADBB6C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (Actor_WorldDistXZToPoint(&pthis->actor, &pthis->actor.home.pos) < 10.0f) {
        func_80ADA028(pthis);
    } else {
        Math_ScaledStepToS(&pthis->actor.world.rot.y, Actor_WorldYawTowardPoint(&pthis->actor, &pthis->actor.home.pos),
                           1820);
    }
}

void func_80ADBBF4(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_ScaledStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 1820);
    if (pthis->actor.xzDistToPlayer < 240.0f && fabsf(pthis->actor.yDistToPlayer + 5.0f) < 30.0f) {
        func_80AD93C4(pthis);
    }
}

void func_80ADBC88(EnPoSisters* pthis, GlobalContext* globalCtx) {
    if (D_80ADD784 != 0 || !Player_InCsMode(globalCtx)) {
        if (pthis->unk_19A != 0) {
            pthis->unk_19A--;
        }
        if (pthis->unk_19A == 30) {
            if (pthis->unk_194 == 0) {
                OnePointCutscene_Init(globalCtx, 3140, 999, NULL, MAIN_CAM);
            }
            D_80ADD784 = 1;
        }
        if (pthis->unk_19A == 0) {
            func_80ADA10C(pthis);
        }
    }
    func_8002F974(&pthis->actor, NA_SE_EV_TORCH - SFX_FLAG);
}

void func_80ADBD38(EnPoSisters* pthis, GlobalContext* globalCtx) {
    pthis->unk_19A++;
    func_80AD9240(pthis, pthis->unk_19A, &pthis->actor.home.pos);
    if (pthis->unk_19A == 32) {
        func_80ADA1B8(pthis);
    }
}

void func_80ADBD8C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    pthis->unk_19A--;
    if (pthis->unk_19A == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
        pthis->unk_199 &= ~0x80;
    }
    if (pthis->unk_19A <= 0) {
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->unk_22E.a = 255;
            D_80ADD784 |= (1 << pthis->unk_194);
        } else {
            pthis->unk_22E.a = (pthis->skelAnime.curFrame * 255.0f) / pthis->skelAnime.endFrame;
        }
    }
    if (D_80ADD784 == 15) {
        func_80ADA25C(pthis);
    }
}

void func_80ADBEE8(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->unk_19A != 0) {
        pthis->unk_19A--;
    }
    func_80AD9240(pthis, pthis->unk_19A, &pthis->actor.home.pos);
    if (pthis->unk_19A == 0) {
        func_80ADA2BC(pthis, globalCtx);
    }
}

void func_80ADBF58(EnPoSisters* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    pthis->unk_19A--;
    Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 0x500);
    if (pthis->unk_19A == 0 && pthis->unk_194 == 0) {
        globalCtx->envCtx.unk_BF = 4;
    }
    if (pthis->unk_19A < 0) {
        Math_StepToF(&pthis->actor.speedXZ, 5.0f, 0.2f);
    }
    if (pthis->unk_19A == -70 && pthis->unk_194 == 1) {
        Audio_PlaySoundAtPosition(globalCtx, &D_80ADD7BC, 40, NA_SE_EN_PO_LAUGH);
    }
    if (pthis->unk_19A < -120) {
        Actor_Kill(&pthis->actor);
    }
}

void func_80ADC034(EnPoSisters* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.isTargeted && pthis->unk_22E.a == 255) {
        if (pthis->unk_197 != 0) {
            pthis->unk_197--;
        }
    } else {
        pthis->unk_197 = 20;
    }
    if (pthis->unk_22E.a == 0) {
        if (pthis->unk_19C != 0) {
            pthis->unk_19C--;
        }
    }
    if (pthis->actionFunc != func_80ADA7F0 && pthis->actionFunc != func_80ADA8C0 && pthis->actionFunc != func_80ADAAA4) {
        if (pthis->unk_197 == 0) {
            func_80AD9718(pthis);
        } else if (pthis->unk_19C == 0 && pthis->unk_22E.a == 0) {
            func_80AD98F4(pthis, globalCtx);
        }
    }
}

void func_80ADC10C(EnPoSisters* pthis, GlobalContext* globalCtx) {
    Vec3f sp24;

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        Actor_SetDropFlag(&pthis->actor, &pthis->collider.info, 1);
        if (pthis->unk_195 != 0) {
            ((EnPoSisters*)pthis->actor.parent)->unk_19C--;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH2);
            func_80AD9C24(pthis, globalCtx);
            if (Rand_ZeroOne() < 0.2f) {
                sp24.x = pthis->actor.world.pos.x;
                sp24.y = pthis->actor.world.pos.y;
                sp24.z = pthis->actor.world.pos.z;
                Item_DropCollectible(globalCtx, &sp24, ITEM00_ARROWS_SMALL);
            }
        } else if (pthis->collider.base.colType == 9 ||
                   (pthis->actor.colChkInfo.damageEffect == 0 && pthis->actor.colChkInfo.damage == 0)) {
            if (pthis->unk_194 == 0) {
                pthis->actor.freezeTimer = 0;
            }
        } else if (pthis->actor.colChkInfo.damageEffect == 0xF) {
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
            pthis->unk_199 |= 2;
            func_80AD98F4(pthis, globalCtx);
        } else if (pthis->unk_194 == 0 && pthis->actor.colChkInfo.damageEffect == 0xE &&
                   pthis->actionFunc == func_80ADB770) {
            if (pthis->unk_19C == 0) {
                pthis->unk_19C = -45;
            }
        } else {
            if (Actor_ApplyDamage(&pthis->actor) != 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DAMAGE);
            } else {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_SISTER_DEAD);
            }
            func_80AD95D8(pthis);
        }
    }
}

void EnPoSisters_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnPoSisters* pthis = (EnPoSisters*)thisx;
    s16 temp;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        func_80AD9568(pthis);
    }
    func_80ADC10C(pthis, globalCtx);
    if (pthis->unk_199 & 4) {
        func_80ADC034(pthis, globalCtx);
    }
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->unk_199 & 0x1F) {
        if (pthis->unk_199 & 8) {
            func_80ADA35C(pthis, globalCtx);
        }
        Actor_MoveForward(&pthis->actor);

        if (pthis->unk_199 & 0x10) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 0.0f, 5);
        } else {
            Vec3f vec;
            s32 sp34;

            vec.x = pthis->actor.world.pos.x;
            vec.y = pthis->actor.world.pos.y + 10.0f;
            vec.z = pthis->actor.world.pos.z;
            pthis->actor.floorHeight =
                BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &sp34, &pthis->actor, &vec);
        }

        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        if (pthis->actionFunc == func_80ADA8C0 || pthis->actionFunc == func_80ADA7F0) {
            pthis->unk_198++;
            pthis->unk_198 = CLAMP_MAX(pthis->unk_198, 8);
        } else if (pthis->actionFunc != func_80ADAFC0) {
            temp = pthis->unk_198 - 1;
            pthis->unk_198 = CLAMP_MIN(temp, 1);
        }
        if (pthis->actionFunc == func_80ADA8C0) {
            pthis->actor.flags |= ACTOR_FLAG_24;
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->unk_199 & 1) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        if (pthis->actionFunc != func_80ADB338) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
        Actor_SetFocus(&pthis->actor, 40.0f);
        if (pthis->actionFunc == func_80ADAC70) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
        } else if (pthis->unk_199 & 2) {
            pthis->actor.shape.rot.y = pthis->actor.world.rot.y;
        }
    }
}

void func_80ADC55C(EnPoSisters* pthis) {
    s16 temp_var;

    if (pthis->skelAnime.animation == &gPoeSistersAttackAnim) {
        pthis->unk_22E.r = CLAMP_MAX((s16)(pthis->unk_22E.r + 5), 255);
        pthis->unk_22E.g = CLAMP_MIN((s16)(pthis->unk_22E.g - 5), 50);
        temp_var = pthis->unk_22E.b - 5;
        pthis->unk_22E.b = CLAMP_MIN(temp_var, 0);
    } else if (pthis->skelAnime.animation == &gPoeSistersFleeAnim) {
        pthis->unk_22E.r = CLAMP_MAX((s16)(pthis->unk_22E.r + 5), 80);
        pthis->unk_22E.g = CLAMP_MAX((s16)(pthis->unk_22E.g + 5), 255);
        temp_var = pthis->unk_22E.b + 5;
        pthis->unk_22E.b = CLAMP_MAX(temp_var, 225);
    } else if (pthis->skelAnime.animation == &gPoeSistersDamagedAnim) {
        if (pthis->actor.colorFilterTimer & 2) {
            pthis->unk_22E.r = 0;
            pthis->unk_22E.g = 0;
            pthis->unk_22E.b = 0;
        } else {
            pthis->unk_22E.r = 80;
            pthis->unk_22E.g = 255;
            pthis->unk_22E.b = 225;
        }
    } else {
        pthis->unk_22E.r = CLAMP_MAX((s16)(pthis->unk_22E.r + 5), 255);
        pthis->unk_22E.g = CLAMP_MAX((s16)(pthis->unk_22E.g + 5), 255);
        if (pthis->unk_22E.b > 210) {
            temp_var = pthis->unk_22E.b - 5;
            pthis->unk_22E.b = CLAMP_MIN(temp_var, 210);
        } else {
            temp_var = pthis->unk_22E.b + 5;
            pthis->unk_22E.b = CLAMP_MAX(temp_var, 210);
        }
    }
}

s32 EnPoSisters_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                 void* thisx, Gfx** gfxP) {
    EnPoSisters* pthis = (EnPoSisters*)thisx;
    Color_RGBA8* color;

    if (limbIndex == 1 && (pthis->unk_199 & 0x40)) {
        if (pthis->unk_19A >= 284) {
            rot->x += (pthis->unk_19A * 0x1000) + 0xFFEE4000;
        } else {
            rot->x += (pthis->unk_19A * 0x1000) + 0xFFFF1000;
        }
    }
    if (pthis->unk_22E.a == 0 || limbIndex == 8 || (pthis->actionFunc == func_80ADAFC0 && pthis->unk_19A >= 8)) {
        *dList = NULL;
    } else if (limbIndex == 9) {
        *dList = D_80ADD7C8[pthis->unk_194];
    } else if (limbIndex == 10) {
        *dList = D_80ADD7D8[pthis->unk_194];
        gDPPipeSync((*gfxP)++);
        gDPSetEnvColor((*gfxP)++, pthis->unk_22E.r, pthis->unk_22E.g, pthis->unk_22E.b, pthis->unk_22E.a);
    } else if (limbIndex == 11) {
        color = &D_80ADD7E8[pthis->unk_194];
        gDPPipeSync((*gfxP)++);
        gDPSetEnvColor((*gfxP)++, color->r, color->g, color->b, pthis->unk_22E.a);
    }
    return false;
}

void EnPoSisters_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx,
                              Gfx** gfxP) {
    EnPoSisters* pthis = (EnPoSisters*)thisx;
    s32 i;
    s32 pad;

    if (pthis->actionFunc == func_80ADAFC0 && pthis->unk_19A >= 8 && limbIndex == 9) {
        gSPMatrix((*gfxP)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_sisters.c", 2876),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList((*gfxP)++, gPoSistersBurnDL);
    }
    if (limbIndex == 8 && pthis->actionFunc != func_80ADB2B8) {
        if (pthis->unk_199 & 0x20) {
            for (i = pthis->unk_198 - 1; i > 0; i--) {
                pthis->unk_234[i] = pthis->unk_234[i - 1];
            }
            Matrix_MultVec3f(&D_80ADD7F8, &pthis->unk_234[0]);
        } else if (pthis->actionFunc == func_80ADBD8C) {
            Matrix_MultVec3f(&D_80ADD7F8, &pthis->actor.home.pos);
        }
        if (pthis->unk_198 > 0) {
            Color_RGBA8* color = &D_80ADD6F0[pthis->unk_194];
            f32 temp_f2 = Rand_ZeroOne() * 0.3f + 0.7f;

            if (pthis->actionFunc == func_80ADB17C || pthis->actionFunc == func_80ADBD38 ||
                pthis->actionFunc == func_80ADBEE8) {
                Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->unk_234[0].x, pthis->unk_234[0].y + 15.0f,
                                          pthis->unk_234[0].z, color->r * temp_f2, color->g * temp_f2,
                                          color->b * temp_f2, 200);
            } else {
                Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->unk_234[0].x, pthis->unk_234[0].y + 15.0f,
                                        pthis->unk_234[0].z, color->r * temp_f2, color->g * temp_f2, color->b * temp_f2,
                                        200);
            }
        } else {
            Lights_PointSetColorAndRadius(&pthis->lightInfo, 0, 0, 0, 0);
        }
        if (!(pthis->unk_199 & 0x80)) {
            Matrix_Get(&pthis->unk_2F8);
        }
    }
}

void EnPoSisters_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnPoSisters* pthis = (EnPoSisters*)thisx;
    u8 phi_s5;
    f32 phi_f20;
    s32 i;
    u8 spE7 = 0;
    Color_RGBA8* temp_s1 = &D_80ADD700[pthis->unk_194];
    Color_RGBA8* temp_s7 = &D_80ADD6F0[pthis->unk_194];
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_po_sisters.c", 2989);
    func_80ADC55C(pthis);
    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);
    if (pthis->unk_22E.a == 255 || pthis->unk_22E.a == 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->unk_22E.r, pthis->unk_22E.g, pthis->unk_22E.b, pthis->unk_22E.a);
        gSPSegment(POLY_OPA_DISP++, 0x09, D_80116280 + 2);
        POLY_OPA_DISP =
            SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                           EnPoSisters_OverrideLimbDraw, EnPoSisters_PostLimbDraw, &pthis->actor, POLY_OPA_DISP);
    } else {
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, pthis->unk_22E.a);
        gSPSegment(POLY_XLU_DISP++, 0x09, D_80116280);
        POLY_XLU_DISP =
            SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                           EnPoSisters_OverrideLimbDraw, EnPoSisters_PostLimbDraw, &pthis->actor, POLY_XLU_DISP);
    }
    if (!(pthis->unk_199 & 0x80)) {
        Matrix_Put(&pthis->unk_2F8);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_sisters.c", 3034),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gPoSistersTorchDL);
    }
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                (globalCtx->gameplayFrames * -20) % 512, 0x20, 0x80));
    gDPSetEnvColor(POLY_XLU_DISP++, temp_s1->r, temp_s1->g, temp_s1->b, temp_s1->a);
    if (pthis->actionFunc == func_80ADB17C) {
        if (pthis->unk_19A < 32) {
            phi_s5 = ((32 - pthis->unk_19A) * 255) / 32;
            phi_f20 = 0.0056000003f;
        } else {
            phi_s5 = (pthis->unk_19A * 255 - 8160) / 32;
            phi_f20 = 0.0027f;
        }
    } else if (pthis->actionFunc == func_80ADBD38) {
        phi_s5 = ((32 - pthis->unk_19A) * 255) / 32;
        phi_f20 = 0.0027f;
    } else if (pthis->actionFunc == func_80ADBEE8) {
        phi_s5 = ((32 - pthis->unk_19A) * 255) / 32;
        phi_f20 = 0.0035f;
    } else if (pthis->actionFunc == func_80ADBC88) {
        //! @bug uninitialised spE7
        phi_s5 = spE7;
        phi_f20 = 0.0027f;
    } else {
        phi_s5 = spE7;
        phi_f20 = pthis->actor.scale.x * 0.5f;
    }
    for (i = 0; i < pthis->unk_198; i++) {
        if (pthis->actionFunc != func_80ADB17C && pthis->actionFunc != func_80ADBD38 &&
            pthis->actionFunc != func_80ADBEE8) {
            phi_s5 = -i * 31 + 248;
        }
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, temp_s7->r, temp_s7->g, temp_s7->b, phi_s5);
        Matrix_Translate(pthis->unk_234[i].x, pthis->unk_234[i].y, pthis->unk_234[i].z, MTXMODE_NEW);
        Matrix_RotateZYX(0, (s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000), 0, MTXMODE_APPLY);
        if (pthis->actionFunc == func_80ADAFC0) {
            phi_f20 = (pthis->unk_19A - i) * 0.025f + 0.5f;
            phi_f20 = CLAMP(phi_f20, 0.5f, 0.8f) * 0.007f;
        }
        Matrix_Scale(phi_f20, phi_f20, phi_f20, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_sisters.c", 3132),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_po_sisters.c", 3139);
}

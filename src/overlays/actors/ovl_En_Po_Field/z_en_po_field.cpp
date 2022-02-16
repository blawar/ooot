#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_PO_FIELD_Z_EN_PO_FIELD_C
#include "actor_common.h"
/*
 * File: z_en_po_field.c
 * Overlay: ovl_En_Po_Field
 * Description: Field Poe
 */

#include "z_en_po_field.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_po_field/object_po_field.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_12)

void EnPoField_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoField_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnPoField_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoField_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPoField_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnPoField_UpdateDead(Actor* thisx, GlobalContext* globalCtx);
void EnPoField_DrawSoul(Actor* thisx, GlobalContext* globalCtx);

void EnPoField_SetupWaitForSpawn(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_WaitForSpawn(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_Appear(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_CirclePlayer(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_Damage(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_Flee(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_Death(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_Disappear(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_SoulIdle(EnPoField* pthis, GlobalContext* globalCtx);
void func_80AD587C(EnPoField* pthis, GlobalContext* globalCtx);
void func_80AD58D4(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_SoulDisappear(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_SoulInteract(EnPoField* pthis, GlobalContext* globalCtx);
void EnPoField_SpawnFlame(EnPoField* pthis);

ActorInit En_Po_Field_InitVars = {
    ACTOR_EN_PO_FIELD,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_PO_FIELD,
    sizeof(EnPoField),
    (ActorFunc)EnPoField_Init,
    (ActorFunc)EnPoField_Destroy,
    (ActorFunc)EnPoField_Update,
    (ActorFunc)EnPoField_Draw,
    (ActorFunc)EnPoField_Reset,
};

static ColliderCylinderInit D_80AD7080 = {
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
    { 25, 50, 20, { 0, 0, 0 } },
};

static ColliderCylinderInit D_80AD70AC = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x04 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 10, 30, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit D_80AD70D8 = { 4, 25, 50, 40 };

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

static s32 sNumSpawned = 0;

static Vec3f sFieldMiddle = { -1000.0f, 0.0f, 6500.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 3200, ICHAIN_STOP),
};

static Vec3f D_80AD7114 = { 0.0f, 3.0f, 0.0f };

static Vec3f D_80AD7120 = { 0.0f, 0.0f, 0.0f };

static EnPoFieldInfo sPoFieldInfo[2] = {
    { { 255, 170, 255 }, { 100, 0, 150 }, { 255, 85, 0 }, 248, gPoeFieldSoulTex },
    { { 255, 255, 170 }, { 255, 200, 0 }, { 160, 0, 255 }, 241, gBigPoeSoulTex },
};

static Vec3f D_80AD714C = { 0.0f, 1400.0f, 0.0f };

static Vec3s sSpawnPositions[10];
static u8 sSpawnSwitchFlags[10];
static MtxF sLimb7Mtx;

void EnPoField_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnPoField* pthis = (EnPoField*)thisx;
    s32 pad;

    if (sNumSpawned != 10) {
        sSpawnPositions[sNumSpawned].x = pthis->actor.world.pos.x;
        sSpawnPositions[sNumSpawned].y = pthis->actor.world.pos.y;
        sSpawnPositions[sNumSpawned].z = pthis->actor.world.pos.z;
        sSpawnSwitchFlags[sNumSpawned] = pthis->actor.params & 0xFF;
        sNumSpawned++;
    }
    if (sNumSpawned >= 2) {
        pthis->actor.params = 0xFF;
        Actor_Kill(&pthis->actor);
        return;
    }
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gPoeFieldSkel, &gPoeFieldFloatAnim, pthis->jointTable, pthis->morphTable,
                   10);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &D_80AD7080);
    Collider_InitCylinder(globalCtx, &pthis->flameCollider);
    Collider_SetCylinder(globalCtx, &pthis->flameCollider, &pthis->actor, &D_80AD70AC);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, &sDamageTable, &D_80AD70D8);
    pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
    Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y, pthis->actor.home.pos.z,
                            255, 255, 255, 0);
    pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
    EnPoField_SetupWaitForSpawn(pthis, globalCtx);
}

void EnPoField_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnPoField* pthis = (EnPoField*)thisx;

    if (pthis->actor.params != 0xFF) {
        LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
        Collider_DestroyCylinder(globalCtx, &pthis->flameCollider);
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnPoField_SetupWaitForSpawn(EnPoField* pthis, GlobalContext* globalCtx) {
    pthis->actor.update = EnPoField_Update;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
    pthis->actor.shape.rot.x = 0;
    Lights_PointSetColorAndRadius(&pthis->lightInfo, 0, 0, 0, 0);
    pthis->actionTimer = 200;
    Actor_SetScale(&pthis->actor, 0.0f);
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_16);
    pthis->collider.base.acFlags &= ~AC_ON;
    pthis->collider.base.ocFlags1 = OC1_ON | OC1_TYPE_ALL;
    pthis->actor.colChkInfo.health = D_80AD70D8.health;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actionFunc = EnPoField_WaitForSpawn;
}

void EnPoField_SetupAppear(EnPoField* pthis) {
    Animation_PlayOnce(&pthis->skelAnime, &gPoeFieldAppearAnim);
    pthis->actor.draw = EnPoField_Draw;
    pthis->lightColor.r = 255;
    pthis->lightColor.g = 255;
    pthis->lightColor.b = 210;
    pthis->lightColor.a = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->actor.shape.yOffset = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_APPEAR);
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    if (pthis->actor.params == EN_PO_FIELD_BIG) {
        pthis->actor.speedXZ = 12.0f;
        pthis->collider.dim.radius = 35;
        pthis->collider.dim.height = 100;
        pthis->collider.dim.yShift = 10;
        pthis->actor.shape.shadowScale = 45.0f;
        pthis->scaleModifier = 0.014f;
        pthis->actor.naviEnemyId = 0x5A;
    } else {
        pthis->actor.speedXZ = 0.0f;
        pthis->collider.dim.radius = D_80AD7080.dim.radius;
        pthis->collider.dim.height = D_80AD7080.dim.height;
        pthis->collider.dim.yShift = D_80AD7080.dim.yShift;
        pthis->actor.shape.shadowScale = 37.0f;
        pthis->scaleModifier = 0.01f;
        pthis->actor.naviEnemyId = 0x5C;
    }
    pthis->actionFunc = EnPoField_Appear;
}

void EnPoField_SetupCirclePlayer(EnPoField* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Animation_PlayLoop(&pthis->skelAnime, &gPoeFieldFloatAnim);
    pthis->collider.base.acFlags |= AC_ON;
    pthis->scaleModifier = pthis->actor.xzDistToPlayer;
    Math_Vec3f_Copy(&pthis->actor.home.pos, &player->actor.world.pos);
    pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer;
    if (pthis->actionFunc != EnPoField_Damage) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actionTimer = 600;
        pthis->unk_194 = 32;
    }
    pthis->actionFunc = EnPoField_CirclePlayer;
}

void EnPoField_SetupFlee(EnPoField* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeFieldFleeAnim, -5.0f);
    pthis->collider.base.acFlags |= AC_ON;
    pthis->actionFunc = EnPoField_Flee;
    pthis->actor.speedXZ = 12.0f;
    if (pthis->actionFunc != EnPoField_Damage) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
        pthis->actionTimer = 2000;
        pthis->unk_194 = 32;
    }
}

void EnPoField_SetupDamage(EnPoField* pthis) {
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gPoeFieldDamagedAnim, -6.0f);
    if (pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x1F824) {
        pthis->actor.world.rot.y = pthis->collider.base.ac->world.rot.y;
    } else {
        pthis->actor.world.rot.y = Actor_WorldYawTowardActor(&pthis->actor, pthis->collider.base.ac) + 0x8000;
    }
    pthis->collider.base.acFlags &= ~(AC_HIT | AC_ON);
    pthis->actor.speedXZ = 5.0f;
    Actor_SetColorFilter(&pthis->actor, 0x4000, 255, 0, 16);
    pthis->actionFunc = EnPoField_Damage;
}

void EnPoField_SetupDeath(EnPoField* pthis) {
    pthis->actionTimer = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    pthis->actor.naviEnemyId = 0xFF;
    if (pthis->flameTimer >= 20) {
        pthis->flameTimer = 19;
    }
    pthis->actionFunc = EnPoField_Death;
}

void EnPoField_SetupDisappear(EnPoField* pthis) {
    Animation_MorphToLoop(&pthis->skelAnime, &gPoeFieldDisappearAnim, -6.0f);
    pthis->actionTimer = 16;
    pthis->collider.base.acFlags &= ~(AC_HIT | AC_ON);
    pthis->actor.speedXZ = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DISAPPEAR);
    pthis->actionFunc = EnPoField_Disappear;
}

void EnPoField_SetupSoulIdle(EnPoField* pthis, GlobalContext* globalCtx) {
    pthis->actor.update = EnPoField_UpdateDead;
    pthis->actor.draw = EnPoField_DrawSoul;
    pthis->actor.shape.shadowDraw = NULL;
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.gravity = -1.0f;
    pthis->actor.shape.yOffset = 1500.0f;
    pthis->actor.shape.rot.x = -0x8000;
    pthis->actionTimer = 60;
    pthis->actor.world.pos.y -= 15.0f;
    Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_MISC);
    pthis->actionFunc = EnPoField_SoulIdle;
}

void func_80AD42B0(EnPoField* pthis) {
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, 0, 0, 0, 0);
    pthis->actor.shape.rot.y = 0;
    pthis->lightColor.a = 0;
    pthis->actor.shape.rot.x = 0;
    pthis->actor.shape.yOffset = 0.0f;
    pthis->actor.gravity = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    pthis->actor.scale.x = 0.0f;
    pthis->actor.scale.y = 0.0f;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_METAL_BOX_BOUND);
    if (pthis->actor.params == EN_PO_FIELD_BIG) {
        func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
    }
    pthis->actionFunc = func_80AD587C;
}

void func_80AD4384(EnPoField* pthis) {
    pthis->actor.home.pos.y = pthis->actor.world.pos.y;
    Actor_SetFocus(&pthis->actor, -10.0f);
    pthis->collider.dim.radius = 13;
    pthis->collider.dim.height = 30;
    pthis->collider.dim.yShift = 0;
    pthis->collider.dim.pos.x = pthis->actor.world.pos.x;
    pthis->collider.dim.pos.y = pthis->actor.world.pos.y - 20.0f;
    pthis->collider.dim.pos.z = pthis->actor.world.pos.z;
    pthis->collider.base.ocFlags1 = OC1_ON | OC1_TYPE_PLAYER;
    pthis->actor.textId = 0x5005;
    pthis->actionTimer = 400;
    pthis->unk_194 = 32;
    pthis->actor.flags |= ACTOR_FLAG_0;
    pthis->actionFunc = func_80AD58D4;
}

void EnPoField_SetupSoulDisappear(EnPoField* pthis) {
    pthis->actionFunc = EnPoField_SoulDisappear;
}

void EnPoField_SetupInteractWithSoul(EnPoField* pthis) {
    pthis->actionFunc = EnPoField_SoulInteract;
    pthis->actor.home.pos.y = pthis->actor.world.pos.y - 15.0f;
}

void EnPoField_CorrectYPos(EnPoField* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->unk_194 == 0) {
        pthis->unk_194 = 32;
    }
    if (pthis->unk_194 != 0) {
        pthis->unk_194 -= 1;
    }
    if (pthis->actor.floorHeight == BGCHECK_Y_MIN) {
        EnPoField_SetupDisappear(pthis);
        return;
    }
    Math_ApproachF(
        &pthis->actor.home.pos.y,
        ((player->actor.world.pos.y > pthis->actor.floorHeight) ? player->actor.world.pos.y : pthis->actor.floorHeight) +
            13.0f,
        0.2f, 5.0f);
    pthis->actor.world.pos.y = Math_SinS(pthis->unk_194 * 0x800) * 13.0f + pthis->actor.home.pos.y;
}

f32 EnPoField_SetFleeSpeed(EnPoField* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 speed = ((player->stateFlags1 & 0x800000) && player->rideActor != NULL) ? player->rideActor->speedXZ : 12.0f;

    if (pthis->actor.xzDistToPlayer < 300.0f) {
        pthis->actor.speedXZ = speed * 1.5f + 2.0f;
    } else if (pthis->actor.xzDistToPlayer < 400.0f) {
        pthis->actor.speedXZ = speed * 1.25f + 2.0f;
    } else if (pthis->actor.xzDistToPlayer < 500.0f) {
        pthis->actor.speedXZ = speed + 2.0f;
    } else {
        pthis->actor.speedXZ = 12.0f;
    }
    pthis->actor.speedXZ = CLAMP_MIN(pthis->actor.speedXZ, 12.0f);
    return pthis->actor.speedXZ;
}

void EnPoField_WaitForSpawn(EnPoField* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 spawnDist;
    s32 i;
    s32 bgId;

    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (pthis->actionTimer == 0) {
        for (i = 0; i < sNumSpawned; i++) {
            if (fabsf(sSpawnPositions[i].x - player->actor.world.pos.x) < 150.0f &&
                fabsf(sSpawnPositions[i].z - player->actor.world.pos.z) < 150.0f) {
                if (Flags_GetSwitch(globalCtx, sSpawnSwitchFlags[i])) {
                    if (player->stateFlags1 & 0x800000) { // Player riding Epona
                        return;
                    } else {
                        pthis->actor.params = EN_PO_FIELD_SMALL;
                        spawnDist = 300.0f;
                    }
                } else if (player->stateFlags1 & 0x800000 || Rand_ZeroOne() < 0.4f) {
                    pthis->actor.params = EN_PO_FIELD_BIG;
                    pthis->spawnFlagIndex = i;
                    spawnDist = 480.0f;
                } else {
                    pthis->actor.params = EN_PO_FIELD_SMALL;
                    spawnDist = 300.0f;
                }
                pthis->actor.world.pos.x = Math_SinS(player->actor.shape.rot.y) * spawnDist + player->actor.world.pos.x;
                pthis->actor.world.pos.z = Math_CosS(player->actor.shape.rot.y) * spawnDist + player->actor.world.pos.z;
                pthis->actor.world.pos.y = player->actor.world.pos.y + 1000.0f;
                pthis->actor.world.pos.y = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                                      &pthis->actor, &pthis->actor.world.pos);
                if (pthis->actor.world.pos.y != BGCHECK_Y_MIN) {
                    pthis->actor.shape.rot.y = Actor_WorldYawTowardActor(&pthis->actor, &player->actor);
                    EnPoField_SetupAppear(pthis);
                } else {
                    return;
                }
            }
        }
    }
}

void EnPoField_Appear(EnPoField* pthis, GlobalContext* globalCtx) {
    if (SkelAnime_Update(&pthis->skelAnime)) {
        pthis->lightColor.a = 255;
        Actor_SetScale(&pthis->actor, pthis->scaleModifier);
        if (pthis->actor.params == EN_PO_FIELD_BIG) {
            EnPoField_SetupFlee(pthis);
        } else {
            EnPoField_SetupCirclePlayer(pthis, globalCtx);
        }
    } else if (pthis->skelAnime.curFrame > 10.0f) {
        pthis->lightColor.a = ((pthis->skelAnime.curFrame - 10.0f) * 0.05f) * 255.0f;
    } else {
        pthis->actor.scale.x += pthis->scaleModifier * 0.1f;
        pthis->actor.scale.y = pthis->actor.scale.x;
        pthis->actor.scale.z = pthis->actor.scale.x;
    }
    pthis->actor.shape.shadowAlpha = pthis->lightColor.a;
    pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
    if (pthis->actor.params == EN_PO_FIELD_BIG) {
        pthis->actor.world.rot.y = pthis->actor.yawTowardsPlayer + 0x8000;
        EnPoField_SetFleeSpeed(pthis, globalCtx);
    }
}

void EnPoField_CirclePlayer(EnPoField* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 temp_v1 = 16 - pthis->unk_194;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (ABS(temp_v1) < 16) {
        pthis->actor.world.rot.y += 512.0f * fabsf(Math_SinS(pthis->unk_194 * 0x800));
    }
    Math_ApproachF(&pthis->scaleModifier, 180.0f, 0.5f, 10.0f);
    Math_ApproachF(&pthis->actor.home.pos.x, player->actor.world.pos.x, 0.2f, 6.0f);
    Math_ApproachF(&pthis->actor.home.pos.z, player->actor.world.pos.z, 0.2f, 6.0f);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 1, 0x800, 0x200);
    if (pthis->actor.home.pos.x - player->actor.world.pos.x > 100.0f) {
        pthis->actor.home.pos.x = player->actor.world.pos.x + 100.0f;
    } else if (pthis->actor.home.pos.x - player->actor.world.pos.x < -100.0f) {
        pthis->actor.home.pos.x = player->actor.world.pos.x + -100.0f;
    }
    if (pthis->actor.home.pos.z - player->actor.world.pos.z > 100.0f) {
        pthis->actor.home.pos.z = player->actor.world.pos.z + 100.0f;
    } else if (pthis->actor.home.pos.z - player->actor.world.pos.z < -100.0f) {
        pthis->actor.home.pos.z = player->actor.world.pos.z + -100.0f;
    }
    pthis->actor.world.pos.x = pthis->actor.home.pos.x - (Math_SinS(pthis->actor.world.rot.y) * pthis->scaleModifier);
    pthis->actor.world.pos.z = pthis->actor.home.pos.z - (Math_CosS(pthis->actor.world.rot.y) * pthis->scaleModifier);
    if (pthis->actionTimer == 0) {
        EnPoField_SetupDisappear(pthis);
    } else {
        EnPoField_SpawnFlame(pthis);
    }
    EnPoField_CorrectYPos(pthis, globalCtx);
    func_8002F974(&pthis->actor, NA_SE_EN_PO_FLY - SFX_FLAG);
}

void EnPoField_Flee(EnPoField* pthis, GlobalContext* globalCtx) {
    f32 temp_f6;
    s16 phi_t0;

    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (Actor_WorldDistXZToPoint(&pthis->actor, &sFieldMiddle) > 3000.0f) {
        phi_t0 = (s16)(pthis->actor.yawTowardsPlayer - Actor_WorldYawTowardPoint(&pthis->actor, &sFieldMiddle) - 0x8000) *
                 0.2f;
    } else {
        phi_t0 = 0;
    }
    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer - phi_t0, 6, 0x400);
    EnPoField_SetFleeSpeed(pthis, globalCtx);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y + 0x8000;
    temp_f6 = Math_SinS(pthis->actionTimer * 0x800) * 3.0f;
    pthis->actor.world.pos.x -= temp_f6 * Math_CosS(pthis->actor.shape.rot.y);
    pthis->actor.world.pos.z += temp_f6 * Math_SinS(pthis->actor.shape.rot.y);
    if (pthis->actionTimer == 0 || pthis->actor.xzDistToPlayer > 1500.0f) {
        EnPoField_SetupDisappear(pthis);
    } else {
        EnPoField_CorrectYPos(pthis, globalCtx);
    }
    func_8002F974(&pthis->actor, NA_SE_EN_PO_AWAY - SFX_FLAG);
}

void EnPoField_Damage(EnPoField* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->actor.speedXZ, 0.0f, 0.5f);
    if (SkelAnime_Update(&pthis->skelAnime)) {
        if (pthis->actor.colChkInfo.health == 0) {
            EnPoField_SetupDeath(pthis);
        } else if (pthis->actor.params == EN_PO_FIELD_BIG) {
            EnPoField_SetupFlee(pthis);
        } else {
            EnPoField_SetupCirclePlayer(pthis, globalCtx);
        }
    }
}

void EnPoField_Death(EnPoField* pthis, GlobalContext* globalCtx) {
    Vec3f sp6C;
    f32 sp68;
    s32 pad;
    s32 pad1;
    f32 temp_f0;

    pthis->actionTimer++;
    if (pthis->actionTimer < 8) {
        if (pthis->actionTimer < 5) {
            sp6C.y = Math_SinS(pthis->actionTimer * 0x1000 - 0x4000) * 23.0f + (pthis->actor.world.pos.y + 40.0f);
            sp68 = Math_CosS(pthis->actionTimer * 0x1000 - 0x4000) * 23.0f;
            sp6C.x =
                Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * sp68 + pthis->actor.world.pos.x;
            sp6C.z =
                Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * sp68 + pthis->actor.world.pos.z;
        } else {
            sp6C.y = pthis->actor.world.pos.y + 40.0f + 15.0f * (pthis->actionTimer - 5);
            sp6C.x =
                Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f + pthis->actor.world.pos.x;
            sp6C.z =
                Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4800) * 23.0f + pthis->actor.world.pos.z;
        }
        EffectSsDeadDb_Spawn(globalCtx, &sp6C, &D_80AD7114, &D_80AD7120, pthis->actionTimer * 10 + 80, 0, 255, 255, 255,
                             255, 0, 0, 255, 1, 9, 1);
        sp6C.x = (pthis->actor.world.pos.x + pthis->actor.world.pos.x) - sp6C.x;
        sp6C.z = (pthis->actor.world.pos.z + pthis->actor.world.pos.z) - sp6C.z;
        EffectSsDeadDb_Spawn(globalCtx, &sp6C, &D_80AD7114, &D_80AD7120, pthis->actionTimer * 10 + 80, 0, 255, 255, 255,
                             255, 0, 0, 255, 1, 9, 1);
        sp6C.x = pthis->actor.world.pos.x;
        sp6C.z = pthis->actor.world.pos.z;
        EffectSsDeadDb_Spawn(globalCtx, &sp6C, &D_80AD7114, &D_80AD7120, pthis->actionTimer * 10 + 80, 0, 255, 255, 255,
                             255, 0, 0, 255, 1, 9, 1);
        if (pthis->actionTimer == 1) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_EXTINCT);
        }
    } else if (pthis->actionTimer == 28) {
        EnPoField_SetupSoulIdle(pthis, globalCtx);
    } else if (pthis->actionTimer >= 19) {
        temp_f0 = (28 - pthis->actionTimer) * 0.001f;
        pthis->actor.world.pos.y += 5.0f;
        pthis->actor.scale.z = temp_f0;
        pthis->actor.scale.y = temp_f0;
        pthis->actor.scale.x = temp_f0;
    }
    if (pthis->actionTimer == 18) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DEAD2);
    }
}

void EnPoField_Disappear(EnPoField* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    pthis->actor.shape.rot.y += 0x1000;
    pthis->lightColor.a = pthis->actionTimer * 15.9375f;
    pthis->actor.shape.shadowAlpha = pthis->lightColor.a;
    if (pthis->actionTimer == 0) {
        EnPoField_SetupWaitForSpawn(pthis, globalCtx);
    }
}

void EnPoField_SoulIdle(EnPoField* pthis, GlobalContext* globalCtx) {
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (pthis->actor.bgCheckFlags & 1) {
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 6.0f, 0, 1, 1, 15, OBJECT_PO_FIELD, 10,
                                 gPoeFieldLanternDL);
        func_80AD42B0(pthis);
    } else if (pthis->actionTimer == 0) {
        EnPoField_SetupWaitForSpawn(pthis, globalCtx);
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 10.0f, 10.0f, 10.0f, 4);
}

void EnPoField_SoulUpdateProperties(EnPoField* pthis, s32 arg1) {
    EnPoFieldInfo* info = &sPoFieldInfo[pthis->actor.params];
    f32 multiplier;

    pthis->lightColor.a = CLAMP(pthis->lightColor.a + arg1, 0, 255);
    if (arg1 < 0) {
        multiplier = pthis->lightColor.a * (1.0f / 255);
        pthis->actor.scale.x = pthis->actor.scale.z = 0.0056000003f * multiplier + 0.0014000001f;
        pthis->actor.scale.y = 0.007f - 0.007f * multiplier + 0.007f;
    } else {
        multiplier = 1.0f;
        pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z = pthis->lightColor.a * (0.007f / 255);
        pthis->actor.world.pos.y = pthis->actor.home.pos.y + ((1.0f / 17.0f) * pthis->lightColor.a);
    }
    pthis->lightColor.r = info->lightColor.r * multiplier;
    pthis->lightColor.g = info->lightColor.g * multiplier;
    pthis->lightColor.b = info->lightColor.b * multiplier;
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, info->lightColor.r, info->lightColor.g, info->lightColor.b,
                              pthis->lightColor.a * (200.0f / 255));
}

void func_80AD587C(EnPoField* pthis, GlobalContext* globalCtx) {
    pthis->actor.home.pos.y += 2.0f;
    EnPoField_SoulUpdateProperties(pthis, 20);
    if (pthis->lightColor.a == 255) {
        func_80AD4384(pthis);
    }
}

void func_80AD58D4(EnPoField* pthis, GlobalContext* globalCtx) {
    if (pthis->actionTimer != 0) {
        pthis->actionTimer--;
    }
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        EnPoField_SetupInteractWithSoul(pthis);
        return;
    }
    if (pthis->actionTimer == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        EnPoField_SetupSoulDisappear(pthis);
        return;
    }
    if (pthis->collider.base.ocFlags1 & OC1_HIT) {
        pthis->actor.flags |= ACTOR_FLAG_16;
        func_8002F2F4(&pthis->actor, globalCtx);
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_16;
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
    pthis->actor.world.pos.y = Math_SinS(pthis->unk_194 * 0x800) * 5.0f + pthis->actor.home.pos.y;
    if (pthis->unk_194 != 0) {
        pthis->unk_194 -= 1;
    }
    if (pthis->unk_194 == 0) {
        pthis->unk_194 = 32;
    }
    pthis->collider.dim.pos.y = pthis->actor.world.pos.y - 20.0f;
    Actor_SetFocus(&pthis->actor, -10.0f);
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                              pthis->actor.world.pos.z, pthis->lightInfo.params.point.color[0],
                              pthis->lightInfo.params.point.color[1], pthis->lightInfo.params.point.color[2],
                              pthis->lightColor.a * (200.0f / 255));
}

void EnPoField_SoulDisappear(EnPoField* pthis, GlobalContext* globalCtx) {
    EnPoField_SoulUpdateProperties(pthis, -13);
    if (pthis->lightColor.a == 0) {
        EnPoField_SetupWaitForSpawn(pthis, globalCtx);
    }
}

void EnPoField_SoulInteract(EnPoField* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.textId != 0x5005) {
        EnPoField_SoulUpdateProperties(pthis, -13);
    } else {
        func_8002F974(&pthis->actor, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
    }
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) {
        if (Message_ShouldAdvance(globalCtx)) {
            Audio_StopSfxByPosAndId(&pthis->actor.projectedPos, NA_SE_EN_PO_BIG_CRY - SFX_FLAG);
            if (globalCtx->msgCtx.choiceIndex == 0) {
                if (Inventory_HasEmptyBottle()) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_BIG_GET);
                    if (pthis->actor.params == 0) {
                        Item_Give(globalCtx, ITEM_POE);
                        pthis->actor.textId = 0x5008;
                    } else {
                        pthis->actor.textId = 0x508F;
                        Item_Give(globalCtx, ITEM_BIG_POE);
                        Flags_SetSwitch(globalCtx, sSpawnSwitchFlags[pthis->spawnFlagIndex]);
                    }
                } else {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
                    pthis->actor.textId = 0x5006;
                }
            } else {
                pthis->actor.textId = 0x5007;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_LAUGH);
            }
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            return;
        }
    } else if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        EnPoField_SetupSoulDisappear(pthis);
    }
}

void EnPoField_TestForDamage(EnPoField* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != 0 || pthis->actor.colChkInfo.damage != 0) {
            if (Actor_ApplyDamage(&pthis->actor) == 0) {
                Enemy_StartFinishingBlow(globalCtx, &pthis->actor);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DEAD);
            } else {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_PO_DAMAGE);
            }
            EnPoField_SetupDamage(pthis);
        }
    }
}

void EnPoField_SpawnFlame(EnPoField* pthis) {
    if (pthis->flameTimer == 0) {
        pthis->flamePosition.x = pthis->lightInfo.params.point.x;
        pthis->flamePosition.y = pthis->lightInfo.params.point.y;
        pthis->flamePosition.z = pthis->lightInfo.params.point.z;
        pthis->flameTimer = 70;
        pthis->flameRotation = pthis->actor.shape.rot.y;
    }
}

void EnPoField_UpdateFlame(EnPoField* pthis, GlobalContext* globalCtx) {
    if (pthis->flameTimer != 0) {
        if (pthis->flameTimer != 0) {
            pthis->flameTimer--;
        }
        if (pthis->flameCollider.base.atFlags & AT_HIT) {
            pthis->flameCollider.base.atFlags &= ~AT_HIT;
            pthis->flameTimer = 19;
        }
        if (pthis->flameTimer < 20) {
            Math_StepToF(&pthis->flameScale, 0.0f, 0.00015f);
            return;
        }
        if (Math_StepToF(&pthis->flameScale, 0.003f, 0.0006f) != 0) {
            pthis->flamePosition.x += 2.5f * Math_SinS(pthis->flameRotation);
            pthis->flamePosition.z += 2.5f * Math_CosS(pthis->flameRotation);
        }
        pthis->flameCollider.dim.pos.x = pthis->flamePosition.x;
        pthis->flameCollider.dim.pos.y = pthis->flamePosition.y;
        pthis->flameCollider.dim.pos.z = pthis->flamePosition.z;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->flameCollider.base);
    }
}

void EnPoField_DrawFlame(EnPoField* pthis, GlobalContext* globalCtx) {
    f32 sp4C;
    s32 pad;

    if (pthis->flameTimer != 0) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 1669);
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0,
                                    (globalCtx->gameplayFrames * -20) % 512, 32, 128));
        sp4C = pthis->flameScale * 85000.0f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, sp4C);
        Matrix_Translate(pthis->flamePosition.x, pthis->flamePosition.y, pthis->flamePosition.z, MTXMODE_NEW);
        Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * (M_PI / 0x8000), MTXMODE_APPLY);
        if (pthis->flameTimer >= 20) {
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
            Matrix_Scale(pthis->flameScale, pthis->flameScale, pthis->flameScale, MTXMODE_APPLY);
        } else {
            gDPSetEnvColor(POLY_XLU_DISP++, sp4C, 0, 0, 0);
            Matrix_Scale((pthis->flameScale * 0.7f) + 0.00090000004f, (0.003f - pthis->flameScale) + 0.003f, 0.003f,
                         MTXMODE_APPLY);
        }
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_field.c", 1709),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 1712);
    }
}

void func_80AD619C(EnPoField* pthis) {
    s16 temp_var;

    if (pthis->actionFunc == EnPoField_Flee) {
        pthis->lightColor.r = CLAMP_MAX((s16)(pthis->lightColor.r + 5), 80);
        pthis->lightColor.g = CLAMP_MAX((s16)(pthis->lightColor.g + 5), 255);
        temp_var = pthis->lightColor.b + 5;
        pthis->lightColor.b = CLAMP_MAX(temp_var, 225);
    } else if (pthis->actionFunc == EnPoField_Damage) {
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
        if (pthis->lightColor.b > 210) {
            temp_var = pthis->lightColor.b - 5;
            pthis->lightColor.b = CLAMP_MIN(temp_var, 210);
        } else {
            temp_var = pthis->lightColor.b + 5;
            pthis->lightColor.b = CLAMP_MAX(temp_var, 210);
        }
    }
}

void func_80AD6330(EnPoField* pthis) {
    f32 rand;

    if (pthis->actionFunc == EnPoField_Appear && pthis->skelAnime.curFrame < 12.0f) {
        pthis->soulColor.r = pthis->soulColor.g = pthis->soulColor.b = (s16)(pthis->skelAnime.curFrame * 16.66f) + 55;
        pthis->soulColor.a = pthis->skelAnime.curFrame * (100.0f / 6.0f);
    } else {
        rand = Rand_ZeroOne();
        pthis->soulColor.r = (s16)(rand * 30.0f) + 225;
        pthis->soulColor.g = (s16)(rand * 100.0f) + 155;
        pthis->soulColor.b = (s16)(rand * 160.0f) + 95;
        pthis->soulColor.a = 200;
    }
}

void EnPoField_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnPoField* pthis = (EnPoField*)thisx;

    EnPoField_TestForDamage(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    EnPoField_UpdateFlame(pthis, globalCtx);
    if (pthis->actionFunc == EnPoField_Flee || pthis->actionFunc == EnPoField_Damage ||
        pthis->actionFunc == EnPoField_Appear) {
        Actor_MoveForward(&pthis->actor);
    }
    if (pthis->actionFunc != EnPoField_WaitForSpawn) {
        Actor_SetFocus(&pthis->actor, 42.0f);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 27.0f, 60.0f, 4);
        func_80AD619C(pthis);
        func_80AD6330(pthis);
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        if (pthis->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

s32 EnPoField_OverrideLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx, Gfx** gfxP) {
    EnPoField* pthis = (EnPoField*)thisx;

    if (pthis->lightColor.a == 0 || limbIndex == 7 || (pthis->actionFunc == EnPoField_Death && pthis->actionTimer >= 2)) {
        *dList = NULL;
    } else if (pthis->actor.params == EN_PO_FIELD_BIG) {
        if (limbIndex == 1) {
            *dList = gBigPoeFaceDL;
        } else if (limbIndex == 8) {
            *dList = gBigPoeCloakDL;
        } else if (limbIndex == 9) {
            *dList = gBigPoeBodyDL;
        }
    }
    if (pthis->actionFunc == EnPoField_Disappear && limbIndex == 7) {
        Matrix_Scale(pthis->actionTimer / 16.0f, pthis->actionTimer / 16.0f, pthis->actionTimer / 16.0f, MTXMODE_APPLY);
    }
    return false;
}

void EnPoField_PostLimDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfxP) {
    EnPoField* pthis = (EnPoField*)thisx;

    if (pthis->actionFunc == EnPoField_Death && pthis->actionTimer >= 2 && limbIndex == 8) {
        gSPMatrix((*gfxP)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_field.c", 1916),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList((*gfxP)++, gPoeFieldBurnDL);
    }
    if (limbIndex == 7) {
        Vec3f vec;
        Matrix_MultVec3f(&D_80AD714C, &vec);
        if (pthis->actionFunc == EnPoField_Death && pthis->actionTimer >= 19 && pthis->actor.scale.x != 0.0f) {
            f32 mtxScale = 0.01f / pthis->actor.scale.x;
            Matrix_Scale(mtxScale, mtxScale, mtxScale, MTXMODE_APPLY);
        }
        Matrix_Get(&sLimb7Mtx);
        if (pthis->actionFunc == EnPoField_Death && pthis->actionTimer == 27) {
            pthis->actor.world.pos.x = sLimb7Mtx.xw;
            pthis->actor.world.pos.y = sLimb7Mtx.yw;
            pthis->actor.world.pos.z = sLimb7Mtx.zw;
        }
        Lights_PointGlowSetInfo(&pthis->lightInfo, vec.x, vec.y, vec.z, pthis->soulColor.r, pthis->soulColor.g,
                                pthis->soulColor.b, pthis->soulColor.a * (200.0f / 255));
    }
}

void EnPoField_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnPoField* pthis = (EnPoField*)thisx;
    EnPoFieldInfo* info = &sPoFieldInfo[pthis->actor.params];

    if (pthis->actionFunc != EnPoField_WaitForSpawn) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 1976);
        func_80093D18(globalCtx->state.gfxCtx);
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x0A,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, info->envColor.r, info->envColor.g, info->envColor.b, 255));
        if (pthis->lightColor.a == 255 || pthis->lightColor.a == 0) {
            gSPSegment(POLY_OPA_DISP++, 0x08,
                       Gfx_EnvColor(globalCtx->state.gfxCtx, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                                    pthis->lightColor.a));
            gSPSegment(POLY_OPA_DISP++, 0x0C, D_80116280 + 2);
            POLY_OPA_DISP =
                SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                               EnPoField_OverrideLimbDraw2, EnPoField_PostLimDraw2, &pthis->actor, POLY_OPA_DISP);
        } else {
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_EnvColor(globalCtx->state.gfxCtx, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b,
                                    pthis->lightColor.a));
            gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);
            POLY_XLU_DISP =
                SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                               EnPoField_OverrideLimbDraw2, EnPoField_PostLimDraw2, &pthis->actor, POLY_XLU_DISP);
        }
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->soulColor.r, pthis->soulColor.g, pthis->soulColor.b, 255);
        Matrix_Put(&sLimb7Mtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2033),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gPoeFieldLanternDL);
        gSPDisplayList(POLY_OPA_DISP++, gPoeFieldLanternTopDL);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2039);
    }
    EnPoField_DrawFlame(pthis, globalCtx);
}

void EnPoField_UpdateDead(Actor* thisx, GlobalContext* globalCtx) {
    EnPoField* pthis = (EnPoField*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actionFunc == EnPoField_SoulIdle) {
        func_80AD6330(pthis);
    }
    EnPoField_UpdateFlame(pthis, globalCtx);
}

void EnPoField_DrawSoul(Actor* thisx, GlobalContext* globalCtx) {
    EnPoField* pthis = (EnPoField*)thisx;
    s32 pad;
    EnPoFieldInfo* info = &sPoFieldInfo[pthis->actor.params];

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2077);
    if (pthis->actionFunc == EnPoField_SoulIdle) {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x0A,
                   Gfx_EnvColor(globalCtx->state.gfxCtx, info->envColor.r, info->envColor.g, info->envColor.b, 255));
        Lights_PointGlowSetInfo(&pthis->lightInfo, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                pthis->actor.world.pos.z, pthis->soulColor.r, pthis->soulColor.g, pthis->soulColor.b, 200);
        gDPSetEnvColor(POLY_OPA_DISP++, pthis->soulColor.r, pthis->soulColor.g, pthis->soulColor.b, 255);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2104),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gPoeFieldLanternDL);
        gSPDisplayList(POLY_OPA_DISP++, gPoeFieldLanternTopDL);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                    (globalCtx->gameplayFrames * info->unk_9) & 0x1FF, 0x20, 0x80));
        gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(info->soulTexture));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, info->primColor.r, info->primColor.g, info->primColor.b,
                        pthis->lightColor.a);
        gDPSetEnvColor(POLY_XLU_DISP++, pthis->lightColor.r, pthis->lightColor.g, pthis->lightColor.b, 255);
        Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * 9.58738e-05f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2143),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gPoeFieldSoulDL);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_po_field.c", 2149);
    EnPoField_DrawFlame(pthis, globalCtx);
}

void EnPoField_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Po_Field_InitVars = {
        ACTOR_EN_PO_FIELD,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_PO_FIELD,
        sizeof(EnPoField),
        (ActorFunc)EnPoField_Init,
        (ActorFunc)EnPoField_Destroy,
        (ActorFunc)EnPoField_Update,
        (ActorFunc)EnPoField_Draw,
        (ActorFunc)EnPoField_Reset,
    };

    D_80AD7080 = {
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
        { 25, 50, 20, { 0, 0, 0 } },
    };

    D_80AD70AC = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_NONE,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x04 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 10, 30, 0, { 0, 0, 0 } },
    };

    D_80AD70D8 = { 4, 25, 50, 40 };

    sDamageTable = {
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

    sNumSpawned = 0;

    sFieldMiddle = { -1000.0f, 0.0f, 6500.0f };

    D_80AD7114 = { 0.0f, 3.0f, 0.0f };

    D_80AD7120 = { 0.0f, 0.0f, 0.0f };

    D_80AD714C = { 0.0f, 1400.0f, 0.0f };

    sLimb7Mtx = {0};

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_KUSA_Z_EN_KUSA_C
#include "actor_common.h"
/*
 * File: z_en_kusa.c
 * Overlay: ovl_en_kusa
 * Description: Bush
 */

#include "z_en_kusa.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "objects/object_kusa/object_kusa.h"
#include "vt.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_23)

void EnKusa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKusa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKusa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKusa_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnKusa_SetupLiftedUp(EnKusa* pthis);
void EnKusa_SetupWaitObject(EnKusa* pthis);
void EnKusa_SetupMain(EnKusa* pthis);
void EnKusa_SetupFall(EnKusa* pthis);
void EnKusa_SetupCut(EnKusa* pthis);
void EnKusa_SetupUprootedWaitRegrow(EnKusa* pthis);
void EnKusa_SetupRegrow(EnKusa* pthis);

void EnKusa_Fall(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_WaitObject(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_Main(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_LiftedUp(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_CutWaitRegrow(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_DoNothing(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_UprootedWaitRegrow(EnKusa* pthis, GlobalContext* globalCtx);
void EnKusa_Regrow(EnKusa* pthis, GlobalContext* globalCtx);

static s16 rotSpeedXtarget = 0;
static s16 rotSpeedX = 0;
static s16 rotSpeedYtarget = 0;
static s16 rotSpeedY = 0;

ActorInit En_Kusa_InitVars = {
    ACTOR_EN_KUSA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnKusa),
    (ActorFunc)EnKusa_Init,
    (ActorFunc)EnKusa_Destroy,
    (ActorFunc)EnKusa_Update,
    NULL,
};

static s16 sObjectIds[] = { OBJECT_GAMEPLAY_FIELD_KEEP, OBJECT_KUSA, OBJECT_KUSA };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_2,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x4FC00758, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 12, 44, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 12, 30, MASS_IMMOVABLE };

static Vec3f sUnitDirections[] = {
    { 0.0f, 0.7071f, 0.7071f },
    { 0.7071f, 0.7071f, 0.0f },
    { 0.0f, 0.7071f, -0.7071f },
    { -0.7071f, 0.7071f, 0.0f },
};

static s16 sFragmentScales[] = { 108, 102, 96, 84, 66, 55, 42, 38 };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 400, ICHAIN_CONTINUE),         ICHAIN_F32_DIV1000(gravity, -3200, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(minVelocityY, -17000, ICHAIN_CONTINUE), ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 100, ICHAIN_CONTINUE),         ICHAIN_F32(uncullZoneDownward, 120, ICHAIN_STOP),
};

void EnKusa_SetupAction(EnKusa* pthis, EnKusaActionFunc actionFunc) {
    pthis->timer = 0;
    pthis->actionFunc = actionFunc;
}

s32 EnKusa_SnapToFloor(EnKusa* pthis, GlobalContext* globalCtx, f32 yOffset) {
    s32 pad;
    CollisionPoly* poly;
    Vec3f pos;
    s32 bgId;
    f32 floorY;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 30.0f;
    pos.z = pthis->actor.world.pos.z;

    floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &poly, &bgId, &pthis->actor, &pos);

    if (floorY > BGCHECK_Y_MIN) {
        pthis->actor.world.pos.y = floorY + yOffset;
        Math_Vec3f_Copy(&pthis->actor.home.pos, &pthis->actor.world.pos);
        return true;
    } else {
        osSyncPrintf(VT_COL(YELLOW, BLACK));
        // "Failure attaching to ground"
        osSyncPrintf("地面に付着失敗(%s %d)\n", "../z_en_kusa.c", 323);
        osSyncPrintf(VT_RST);
        return false;
    }
}

void EnKusa_DropCollectible(EnKusa* pthis, GlobalContext* globalCtx) {
    s16 dropParams;

    switch (pthis->actor.params & 3) {
        case ENKUSA_TYPE_0:
        case ENKUSA_TYPE_2:
            dropParams = (pthis->actor.params >> 8) & 0xF;

            if (dropParams >= 0xD) {
                dropParams = 0;
            }
            Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, dropParams << 4);
            break;
        case ENKUSA_TYPE_1:
            if (Rand_ZeroOne() < 0.5f) {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_SEEDS);
            } else {
                Item_DropCollectible(globalCtx, &pthis->actor.world.pos, ITEM00_HEART);
            }
            break;
    }
}

void EnKusa_UpdateVelY(EnKusa* pthis) {
    pthis->actor.velocity.y += pthis->actor.gravity;

    if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }
}

void EnKusa_RandScaleVecToZero(Vec3f* vec, f32 scale) {
    scale += ((Rand_ZeroOne() * 0.2f) - 0.1f) * scale;
    vec->x -= vec->x * scale;
    vec->y -= vec->y * scale;
    vec->z -= vec->z * scale;
}

void EnKusa_SetScaleSmall(EnKusa* pthis) {
    pthis->actor.scale.y = 0.16000001f;
    pthis->actor.scale.x = 0.120000005f;
    pthis->actor.scale.z = 0.120000005f;
}

void EnKusa_SpawnFragments(EnKusa* pthis, GlobalContext* globalCtx) {
    Vec3f velocity;
    Vec3f pos;
    s32 i;
    s32 scaleIndex;
    Vec3f* dir;
    s32 pad;

    for (i = 0; i < ARRAY_COUNT(sUnitDirections); i++) {
        dir = &sUnitDirections[i];

        pos.x = pthis->actor.world.pos.x + (dir->x * pthis->actor.scale.x * 20.0f);
        pos.y = pthis->actor.world.pos.y + (dir->y * pthis->actor.scale.y * 20.0f) + 10.0f;
        pos.z = pthis->actor.world.pos.z + (dir->z * pthis->actor.scale.z * 20.0f);

        velocity.x = (Rand_ZeroOne() - 0.5f) * 8.0f;
        velocity.y = Rand_ZeroOne() * 10.0f;
        velocity.z = (Rand_ZeroOne() - 0.5f) * 8.0f;

        scaleIndex = (s32)(Rand_ZeroOne() * 111.1f) & 7;

        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -100, 64, 40, 3, 0, sFragmentScales[scaleIndex], 0, 0,
                             80, KAKERA_COLOR_NONE, OBJECT_GAMEPLAY_KEEP, gCuttableShrubStalkDL);

        pos.x = pthis->actor.world.pos.x + (dir->x * pthis->actor.scale.x * 40.0f);
        pos.y = pthis->actor.world.pos.y + (dir->y * pthis->actor.scale.y * 40.0f) + 10.0f;
        pos.z = pthis->actor.world.pos.z + (dir->z * pthis->actor.scale.z * 40.0f);

        velocity.x = (Rand_ZeroOne() - 0.5f) * 6.0f;
        velocity.y = Rand_ZeroOne() * 10.0f;
        velocity.z = (Rand_ZeroOne() - 0.5f) * 6.0f;

        scaleIndex = (s32)(Rand_ZeroOne() * 111.1f) % 7;

        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -100, 64, 40, 3, 0, sFragmentScales[scaleIndex], 0, 0,
                             80, KAKERA_COLOR_NONE, OBJECT_GAMEPLAY_KEEP, gCuttableShrubTipDL);
    }
}

void EnKusa_SpawnBugs(EnKusa* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Actor* bug = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_INSECT, pthis->actor.world.pos.x,
                                 pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, Rand_ZeroOne() * 0xFFFF, 0, 1);

        if (bug == NULL) {
            break;
        }
    }
}

void EnKusa_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    EnKusa* pthis = (EnKusa*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
}

void EnKusa_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnKusa* pthis = (EnKusa*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        pthis->actor.uncullZoneForward += 1000.0f;
    }

    EnKusa_InitCollider(thisx, globalCtx);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);

    if (pthis->actor.shape.rot.y == 0) {
        s16 rand = Rand_ZeroFloat(0x10000);

        pthis->actor.world.rot.y = rand;
        pthis->actor.home.rot.y = rand;
        pthis->actor.shape.rot.y = rand;
    }

    if (!EnKusa_SnapToFloor(pthis, globalCtx, 0.0f)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, sObjectIds[thisx->params & 3]);

    if (pthis->objBankIndex < 0) {
        // "Bank danger!"
        osSyncPrintf("Error : バンク危険！ (arg_data 0x%04x)(%s %d)\n", thisx->params, "../z_en_kusa.c", 561);
        Actor_Kill(&pthis->actor);
        return;
    }

    EnKusa_SetupWaitObject(pthis);
}

void EnKusa_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnKusa* pthis = (EnKusa*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnKusa_SetupWaitObject(EnKusa* pthis) {
    EnKusa_SetupAction(pthis, EnKusa_WaitObject);
}

void EnKusa_WaitObject(EnKusa* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        if (pthis->actor.flags & ACTOR_FLAG_11) {
            EnKusa_SetupCut(pthis);
        } else {
            EnKusa_SetupMain(pthis);
        }

        pthis->actor.draw = EnKusa_Draw;
        pthis->actor.objBankIndex = pthis->objBankIndex;
        pthis->actor.flags &= ~ACTOR_FLAG_4;
    }
}

void EnKusa_SetupMain(EnKusa* pthis) {
    EnKusa_SetupAction(pthis, EnKusa_Main);
    pthis->actor.flags &= ~ACTOR_FLAG_4;
}

void EnKusa_Main(EnKusa* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        EnKusa_SetupLiftedUp(pthis);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_PL_PULL_UP_PLANT);
    } else if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        EnKusa_SpawnFragments(pthis, globalCtx);
        EnKusa_DropCollectible(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_PLANT_BROKEN);

        if ((pthis->actor.params >> 4) & 1) {
            EnKusa_SpawnBugs(pthis, globalCtx);
        }

        if ((pthis->actor.params & 3) == ENKUSA_TYPE_0) {
            Actor_Kill(&pthis->actor);
            return;
        }

        EnKusa_SetupCut(pthis);
        pthis->actor.flags |= ACTOR_FLAG_11;
    } else {
        if (!(pthis->collider.base.ocFlags1 & OC1_TYPE_PLAYER) && (pthis->actor.xzDistToPlayer > 12.0f)) {
            pthis->collider.base.ocFlags1 |= OC1_TYPE_PLAYER;
        }

        if (pthis->actor.xzDistToPlayer < 600.0f) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

            if (pthis->actor.xzDistToPlayer < 400.0f) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
                if (pthis->actor.xzDistToPlayer < 100.0f) {
                    func_8002F580(&pthis->actor, globalCtx);
                }
            }
        }
    }
}

void EnKusa_SetupLiftedUp(EnKusa* pthis) {
    EnKusa_SetupAction(pthis, EnKusa_LiftedUp);
    pthis->actor.room = -1;
    pthis->actor.flags |= ACTOR_FLAG_4;
}

void EnKusa_LiftedUp(EnKusa* pthis, GlobalContext* globalCtx) {
    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        pthis->actor.room = globalCtx->roomCtx.curRoom.num;
        EnKusa_SetupFall(pthis);
        pthis->actor.velocity.x = pthis->actor.speedXZ * Math_SinS(pthis->actor.world.rot.y);
        pthis->actor.velocity.z = pthis->actor.speedXZ * Math_CosS(pthis->actor.world.rot.y);
        pthis->actor.colChkInfo.mass = 240;
        pthis->actor.gravity = -0.1f;
        EnKusa_UpdateVelY(pthis);
        EnKusa_RandScaleVecToZero(&pthis->actor.velocity, 0.005f);
        func_8002D7EC(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.5f, 35.0f, 0.0f, 0xC5);
        pthis->actor.gravity = -3.2f;
    }
}

void EnKusa_SetupFall(EnKusa* pthis) {
    EnKusa_SetupAction(pthis, EnKusa_Fall);
    rotSpeedXtarget = -0xBB8;
    rotSpeedYtarget = (Rand_ZeroOne() - 0.5f) * 1600.0f;
    rotSpeedX = 0;
    rotSpeedY = 0;
}

void EnKusa_Fall(EnKusa* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f contactPos;

    if (pthis->actor.bgCheckFlags & 0xB) {
        if (!(pthis->actor.bgCheckFlags & 0x20)) {
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EV_PLANT_BROKEN);
        }
        EnKusa_SpawnFragments(pthis, globalCtx);
        EnKusa_DropCollectible(pthis, globalCtx);
        switch (pthis->actor.params & 3) {
            case ENKUSA_TYPE_0:
            case ENKUSA_TYPE_2:
                Actor_Kill(&pthis->actor);
                break;

            case ENKUSA_TYPE_1:
                EnKusa_SetupUprootedWaitRegrow(pthis);
                break;
        }
        return;
    }

    if (pthis->actor.bgCheckFlags & 0x40) {
        contactPos.x = pthis->actor.world.pos.x;
        contactPos.y = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
        contactPos.z = pthis->actor.world.pos.z;
        EffectSsGSplash_Spawn(globalCtx, &contactPos, NULL, NULL, 0, 400);
        EffectSsGRipple_Spawn(globalCtx, &contactPos, 150, 650, 0);
        EffectSsGRipple_Spawn(globalCtx, &contactPos, 400, 800, 4);
        EffectSsGRipple_Spawn(globalCtx, &contactPos, 500, 1100, 8);
        pthis->actor.minVelocityY = -3.0f;
        rotSpeedX >>= 1;
        rotSpeedXtarget >>= 1;
        rotSpeedY >>= 1;
        rotSpeedYtarget >>= 1;
        pthis->actor.bgCheckFlags &= ~0x40;
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
    }

    EnKusa_UpdateVelY(pthis);
    Math_StepToS(&rotSpeedX, rotSpeedXtarget, 0x1F4);
    Math_StepToS(&rotSpeedY, rotSpeedYtarget, 0xAA);
    pthis->actor.shape.rot.x += rotSpeedX;
    pthis->actor.shape.rot.y += rotSpeedY;
    EnKusa_RandScaleVecToZero(&pthis->actor.velocity, 0.05f);
    func_8002D7EC(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.5f, 35.0f, 0.0f, 0xC5);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnKusa_SetupCut(EnKusa* pthis) {
    switch (pthis->actor.params & 3) {
        case ENKUSA_TYPE_2:
            EnKusa_SetupAction(pthis, EnKusa_DoNothing);
            break;
        case ENKUSA_TYPE_1:
            EnKusa_SetupAction(pthis, EnKusa_CutWaitRegrow);
            break;
    }
}

void EnKusa_CutWaitRegrow(EnKusa* pthis, GlobalContext* globalCtx) {
    if (pthis->timer >= 120) {
        EnKusa_SetupRegrow(pthis);
    }
}

void EnKusa_DoNothing(EnKusa* pthis, GlobalContext* globalCtx) {
}

void EnKusa_SetupUprootedWaitRegrow(EnKusa* pthis) {
    pthis->actor.world.pos.x = pthis->actor.home.pos.x;
    pthis->actor.world.pos.y = pthis->actor.home.pos.y - 9.0f;
    pthis->actor.world.pos.z = pthis->actor.home.pos.z;
    EnKusa_SetScaleSmall(pthis);
    pthis->actor.shape.rot = pthis->actor.home.rot;
    EnKusa_SetupAction(pthis, EnKusa_UprootedWaitRegrow);
}

void EnKusa_UprootedWaitRegrow(EnKusa* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 120) {
        if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.6f)) {
            if (pthis->timer >= 170) {
                EnKusa_SetupRegrow(pthis);
            }
        }
    }
}

void EnKusa_SetupRegrow(EnKusa* pthis) {
    EnKusa_SetupAction(pthis, EnKusa_Regrow);
    EnKusa_SetScaleSmall(pthis);
    pthis->actor.shape.rot = pthis->actor.home.rot;
    pthis->actor.flags &= ~ACTOR_FLAG_11;
}

void EnKusa_Regrow(EnKusa* pthis, GlobalContext* globalCtx) {
    s32 isFullyGrown = true;

    isFullyGrown &= Math_StepToF(&pthis->actor.scale.y, 0.4f, 0.014f);
    isFullyGrown &= Math_StepToF(&pthis->actor.scale.x, 0.4f, 0.011f);
    pthis->actor.scale.z = pthis->actor.scale.x;

    if (isFullyGrown) {
        Actor_SetScale(&pthis->actor, 0.4f);
        EnKusa_SetupMain(pthis);
        pthis->collider.base.ocFlags1 &= ~OC1_TYPE_PLAYER;
    }
}

void EnKusa_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnKusa* pthis = (EnKusa*)thisx;

    pthis->timer++;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->actor.flags & ACTOR_FLAG_11) {
        pthis->actor.shape.yOffset = -6.25f;
    } else {
        pthis->actor.shape.yOffset = 0.0f;
    }
}

void EnKusa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* dLists[] = { gFieldBushDL, object_kusa_DL_000140, object_kusa_DL_000140 };
    EnKusa* pthis = (EnKusa*)thisx;

    if (pthis->actor.flags & ACTOR_FLAG_11) {
        Gfx_DrawDListOpa(globalCtx, object_kusa_DL_0002E0);
    } else {
        Gfx_DrawDListOpa(globalCtx, dLists[thisx->params & 3]);
    }
}

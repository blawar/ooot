#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ISHI_Z_EN_ISHI_C
#include "actor_common.h"
/*
 * File: z_en_ishi.c
 * Overlay: ovl_En_Ishi
 * Description: Small and large gray rocks
 */

#include "z_en_ishi.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"

#include "vt.h"
#include "def/code_8006BA00.h"
#include "def/code_800A9F30.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_quake.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_23

void EnIshi_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIshi_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnIshi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIshi_Update(Actor* thisx, GlobalContext* globalCtx);
void EnIshi_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnIshi_SetupWait(EnIshi* pthis);
void EnIshi_Wait(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SetupLiftedUp(EnIshi* pthis);
void EnIshi_LiftedUp(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SetupFly(EnIshi* pthis);
void EnIshi_Fly(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SpawnFragmentsSmall(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SpawnFragmentsLarge(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SpawnDustSmall(EnIshi* pthis, GlobalContext* globalCtx);
void EnIshi_SpawnDustLarge(EnIshi* pthis, GlobalContext* globalCtx);

static s16 scales_55[] = { 16, 13, 11, 9, 7, 5 };

static s16 scales_56[] = { 145, 135, 120, 100, 70, 50, 45, 40, 35 };

static u16 liftSounds_67[] = { NA_SE_PL_PULL_UP_ROCK, NA_SE_PL_PULL_UP_BIGROCK };


static s16 sRotSpeedX = 0;
static s16 sRotSpeedY = 0;

ActorInit En_Ishi_InitVars = {
    ACTOR_EN_ISHI,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(EnIshi),
    (ActorFunc)EnIshi_Init,
    (ActorFunc)EnIshi_Destroy,
    (ActorFunc)EnIshi_Update,
    (ActorFunc)EnIshi_Draw,
    (ActorFunc)EnIshi_Reset,
};

static f32 sRockScales[] = { 0.1f, 0.4f };
static f32 D_80A7FA20[] = { 58.0f, 80.0f };
static f32 D_80A7FA28[] = { 0.0f, 0.005f };

// the sizes of these arrays are very large and take up way more space than it needs to.
// coincidentally the sizes are the same as the ID for NA_SE_EV_ROCK_BROKEN, which may explain a mistake that could
// have been made here
static u16 sBreakSounds[0x2852] = { NA_SE_EV_ROCK_BROKEN, NA_SE_EV_WALL_BROKEN };

static u8 sBreakSoundDurations[0x2852] = { 20, 40 };

static EnIshiEffectSpawnFunc sFragmentSpawnFuncs[] = { EnIshi_SpawnFragmentsSmall, EnIshi_SpawnFragmentsLarge };

static EnIshiEffectSpawnFunc sDustSpawnFuncs[] = { EnIshi_SpawnDustSmall, EnIshi_SpawnDustLarge };

static ColliderCylinderInit sCylinderInits[] = {
    {
        {
            COLTYPE_HARD,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x4FC1FFFE, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 10, 18, -2, { 0, 0, 0 } },
    },
    {
        {
            COLTYPE_HARD,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x4FC1FFF6, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 55, 70, 0, { 0, 0, 0 } },
    },
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 12, 60, MASS_IMMOVABLE };

void EnIshi_InitCollider(Actor* thisx, GlobalContext* globalCtx) {
    EnIshi* pthis = (EnIshi*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInits[pthis->actor.params & 1]);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
}

s32 EnIshi_SnapToFloor(EnIshi* pthis, GlobalContext* globalCtx, f32 arg2) {
    CollisionPoly* poly;
    Vec3f pos;
    s32 bgId;
    f32 floorY;

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 30.0f;
    pos.z = pthis->actor.world.pos.z;
    floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &poly, &bgId, &pthis->actor, &pos);
    if (floorY > BGCHECK_Y_MIN) {
        pthis->actor.world.pos.y = floorY + arg2;
        Math_Vec3f_Copy(&pthis->actor.home.pos, &pthis->actor.world.pos);
        return true;
    } else {
        osSyncPrintf(VT_COL(YELLOW, BLACK));
        // "Failure attaching to ground"
        osSyncPrintf("地面に付着失敗(%s %d)\n", "../z_en_ishi.c", 388);
        osSyncPrintf(VT_RST);
        return false;
    }
}

void EnIshi_SpawnFragmentsSmall(EnIshi* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f velocity;
    Vec3f pos;
    s16 phi_v0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(scales_55); i++) {
        pos.x = pthis->actor.world.pos.x + (Rand_ZeroOne() - 0.5f) * 8.0f;
        pos.y = pthis->actor.world.pos.y + (Rand_ZeroOne() * 5.0f) + 5.0f;
        pos.z = pthis->actor.world.pos.z + (Rand_ZeroOne() - 0.5f) * 8.0f;
        Math_Vec3f_Copy(&velocity, &pthis->actor.velocity);
        if (pthis->actor.bgCheckFlags & 1) {
            velocity.x *= 0.8f;
            velocity.y *= -0.8f;
            velocity.z *= 0.8f;
        } else if (pthis->actor.bgCheckFlags & 8) {
            velocity.x *= -0.8f;
            velocity.y *= 0.8f;
            velocity.z *= -0.8f;
        }
        velocity.x += (Rand_ZeroOne() - 0.5f) * 11.0f;
        velocity.y += Rand_ZeroOne() * 6.0f;
        velocity.z += (Rand_ZeroOne() - 0.5f) * 11.0f;
        if (Rand_ZeroOne() < 0.5f) {
            phi_v0 = 65;
        } else {
            phi_v0 = 33;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pos, -420, phi_v0, 30, 5, 0, scales_55[i], 3, 10, 40,
                             KAKERA_COLOR_NONE, OBJECT_GAMEPLAY_FIELD_KEEP, gFieldKakeraDL);
    }
}

void EnIshi_SpawnFragmentsLarge(EnIshi* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->actor;
    Vec3f velocity;
    Vec3f pos;
    s16 angle = 0x1000;
    s32 i;
    f32 rand;
    s16 phi_v0;
    s16 phi_v1;

    for (i = 0; i < ARRAY_COUNT(scales_56); i++) {
        angle += 0x4E20;
        rand = Rand_ZeroOne() * 10.0f;
        pos.x = pthis->actor.world.pos.x + (Math_SinS(angle) * rand);
        pos.y = pthis->actor.world.pos.y + (Rand_ZeroOne() * 40.0f) + 5.0f;
        pos.z = pthis->actor.world.pos.z + (Math_CosS(angle) * rand);
        Math_Vec3f_Copy(&velocity, &thisx->velocity);
        if (thisx->bgCheckFlags & 1) {
            velocity.x *= 0.9f;
            velocity.y *= -0.8f;
            velocity.z *= 0.9f;
        } else if (thisx->bgCheckFlags & 8) {
            velocity.x *= -0.9f;
            velocity.y *= 0.8f;
            velocity.z *= -0.9f;
        }
        rand = Rand_ZeroOne() * 10.0f;
        velocity.x += rand * Math_SinS(angle);
        velocity.y += (Rand_ZeroOne() * 4.0f) + ((Rand_ZeroOne() * i) * 0.7f);
        velocity.z += rand * Math_CosS(angle);
        if (i == 0) {
            phi_v0 = 41;
            phi_v1 = -450;
        } else if (i < 4) {
            phi_v0 = 37;
            phi_v1 = -380;
        } else {
            phi_v0 = 69;
            phi_v1 = -320;
        }
        EffectSsKakera_Spawn(globalCtx, &pos, &velocity, &pthis->actor.world.pos, phi_v1, phi_v0, 30, 5, 0, scales_56[i], 5,
                             2, 70, KAKERA_COLOR_WHITE, OBJECT_GAMEPLAY_FIELD_KEEP, gSilverRockFragmentsDL);
    }
}

void EnIshi_SpawnDustSmall(EnIshi* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    Math_Vec3f_Copy(&pos, &pthis->actor.world.pos);
    if (pthis->actor.bgCheckFlags & 1) {
        pos.x += 2.0f * pthis->actor.velocity.x;
        pos.y -= 2.0f * pthis->actor.velocity.y;
        pos.z += 2.0f * pthis->actor.velocity.z;
    } else if (pthis->actor.bgCheckFlags & 8) {
        pos.x -= 2.0f * pthis->actor.velocity.x;
        pos.y += 2.0f * pthis->actor.velocity.y;
        pos.z -= 2.0f * pthis->actor.velocity.z;
    }
    func_80033480(globalCtx, &pos, 60.0f, 3, 0x50, 0x3C, 1);
}

void EnIshi_SpawnDustLarge(EnIshi* pthis, GlobalContext* globalCtx) {
    Vec3f pos;

    Math_Vec3f_Copy(&pos, &pthis->actor.world.pos);
    if (pthis->actor.bgCheckFlags & 1) {
        pos.x += 2.0f * pthis->actor.velocity.x;
        pos.y -= 2.0f * pthis->actor.velocity.y;
        pos.z += 2.0f * pthis->actor.velocity.z;
    } else if (pthis->actor.bgCheckFlags & 8) {
        pos.x -= 2.0f * pthis->actor.velocity.x;
        pos.y += 2.0f * pthis->actor.velocity.y;
        pos.z -= 2.0f * pthis->actor.velocity.z;
    }
    func_80033480(globalCtx, &pos, 140.0f, 0xA, 0xB4, 0x5A, 1);
}

void EnIshi_DropCollectible(EnIshi* pthis, GlobalContext* globalCtx) {
    s16 dropParams;

    if ((pthis->actor.params & 1) == ROCK_SMALL) {
        dropParams = (pthis->actor.params >> 8) & 0xF;

        if (dropParams >= 0xD) {
            dropParams = 0;
        }

        Item_DropCollectibleRandom(globalCtx, NULL, &pthis->actor.world.pos, dropParams << 4);
    }
}

void EnIshi_Fall(EnIshi* pthis) {
    pthis->actor.velocity.y += pthis->actor.gravity;

    if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }
}

void func_80A7ED94(Vec3f* arg0, f32 arg1) {
    arg1 += ((Rand_ZeroOne() * 0.2f) - 0.1f) * arg1;
    arg0->x -= arg0->x * arg1;
    arg0->y -= arg0->y * arg1;
    arg0->z -= arg0->z * arg1;
}

void EnIshi_SpawnBugs(EnIshi* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Actor* bug = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_INSECT, pthis->actor.world.pos.x,
                                 pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, Rand_ZeroOne() * 0xFFFF, 0, 1);

        if (bug == NULL) {
            break;
        }
    }
}

static InitChainEntry sInitChains[][5] = {
    {
        ICHAIN_F32_DIV1000(gravity, -1200, ICHAIN_CONTINUE),
        ICHAIN_F32_DIV1000(minVelocityY, -20000, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneScale, 150, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneDownward, 400, ICHAIN_STOP),
    },
    {
        ICHAIN_F32_DIV1000(gravity, -2500, ICHAIN_CONTINUE),
        ICHAIN_F32_DIV1000(minVelocityY, -20000, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneScale, 250, ICHAIN_CONTINUE),
        ICHAIN_F32(uncullZoneDownward, 500, ICHAIN_STOP),
    },
};

void EnIshi_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnIshi* pthis = (EnIshi*)thisx;
    s16 type = pthis->actor.params & 1;

    Actor_ProcessInitChain(&pthis->actor, sInitChains[type]);
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        pthis->actor.uncullZoneForward += 1000.0f;
    }
    if (pthis->actor.shape.rot.y == 0) {
        pthis->actor.shape.rot.y = pthis->actor.world.rot.y = Rand_ZeroFloat(0x10000);
    }
    Actor_SetScale(&pthis->actor, sRockScales[type]);
    EnIshi_InitCollider(&pthis->actor, globalCtx);
    if ((type == ROCK_LARGE) &&
        Flags_GetSwitch(globalCtx, ((pthis->actor.params >> 0xA) & 0x3C) | ((pthis->actor.params >> 6) & 3))) {
        Actor_Kill(&pthis->actor);
        return;
    }
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    pthis->actor.shape.yOffset = D_80A7FA20[type];
    if (!((pthis->actor.params >> 5) & 1) && !EnIshi_SnapToFloor(pthis, globalCtx, 0.0f)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    EnIshi_SetupWait(pthis);
}

void EnIshi_Destroy(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnIshi* pthis = (EnIshi*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnIshi_SetupWait(EnIshi* pthis) {
    pthis->actionFunc = EnIshi_Wait;
}

void EnIshi_Wait(EnIshi* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 type = pthis->actor.params & 1;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        EnIshi_SetupLiftedUp(pthis);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, liftSounds_67[type]);
        if ((pthis->actor.params >> 4) & 1) {
            EnIshi_SpawnBugs(pthis, globalCtx);
        }
    } else if ((pthis->collider.base.acFlags & AC_HIT) && (type == ROCK_SMALL) &&
               pthis->collider.info.acHitInfo->toucher.dmgFlags & 0x40000048) {
        EnIshi_DropCollectible(pthis, globalCtx);
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, sBreakSoundDurations[type], sBreakSounds[type]);
        sFragmentSpawnFuncs[type](pthis, globalCtx);
        sDustSpawnFuncs[type](pthis, globalCtx);
        Actor_Kill(&pthis->actor);
    } else if (pthis->actor.xzDistToPlayer < 600.0f) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        pthis->collider.base.acFlags &= ~AC_HIT;
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        if (pthis->actor.xzDistToPlayer < 400.0f) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            if (pthis->actor.xzDistToPlayer < 90.0f) {
                // GI_NONE in these cases allows the player to lift the actor
                if (type == ROCK_LARGE) {
                    func_8002F434(&pthis->actor, globalCtx, GI_NONE, 80.0f, 20.0f);
                } else {
                    func_8002F434(&pthis->actor, globalCtx, GI_NONE, 50.0f, 10.0f);
                }
            }
        }
    }
}

void EnIshi_SetupLiftedUp(EnIshi* pthis) {
    pthis->actionFunc = EnIshi_LiftedUp;
    pthis->actor.room = -1;
    pthis->actor.flags |= ACTOR_FLAG_4;
}

void EnIshi_LiftedUp(EnIshi* pthis, GlobalContext* globalCtx) {
    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        pthis->actor.room = globalCtx->roomCtx.curRoom.num;
        if ((pthis->actor.params & 1) == ROCK_LARGE) {
            Flags_SetSwitch(globalCtx, ((pthis->actor.params >> 0xA) & 0x3C) | ((pthis->actor.params >> 6) & 3));
        }
        EnIshi_SetupFly(pthis);
        EnIshi_Fall(pthis);
        func_80A7ED94(&pthis->actor.velocity, D_80A7FA28[pthis->actor.params & 1]);
        Actor_UpdatePosition(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.5f, 35.0f, 0.0f, 0xC5);
    }
}

void EnIshi_SetupFly(EnIshi* pthis) {
    pthis->actor.velocity.x = Math_SinS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    pthis->actor.velocity.z = Math_CosS(pthis->actor.world.rot.y) * pthis->actor.speedXZ;
    if ((pthis->actor.params & 1) == ROCK_SMALL) {
        sRotSpeedX = (Rand_ZeroOne() - 0.5f) * 16000.0f;
        sRotSpeedY = (Rand_ZeroOne() - 0.5f) * 2400.0f;
    } else {
        sRotSpeedX = (Rand_ZeroOne() - 0.5f) * 8000.0f;
        sRotSpeedY = (Rand_ZeroOne() - 0.5f) * 1600.0f;
    }
    pthis->actor.colChkInfo.mass = 240;
    pthis->actionFunc = EnIshi_Fly;
}

void EnIshi_Fly(EnIshi* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 type = pthis->actor.params & 1;
    s32 pad2;
    s32 quakeIdx;
    Vec3f contactPos;

    if (pthis->actor.bgCheckFlags & 9) {
        EnIshi_DropCollectible(pthis, globalCtx);
        sFragmentSpawnFuncs[type](pthis, globalCtx);
        if (!(pthis->actor.bgCheckFlags & 0x20)) {
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, sBreakSoundDurations[type],
                                      sBreakSounds[type]);
            sDustSpawnFuncs[type](pthis, globalCtx);
        }
        if (type == ROCK_LARGE) {
            quakeIdx = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
            Quake_SetSpeed(quakeIdx, -0x3CB0);
            Quake_SetQuakeValues(quakeIdx, 3, 0, 0, 0);
            Quake_SetCountdown(quakeIdx, 7);
            Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xFF, 0x14, 0x96);
        }
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->actor.bgCheckFlags & 0x40) {
        contactPos.x = pthis->actor.world.pos.x;
        contactPos.y = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
        contactPos.z = pthis->actor.world.pos.z;
        EffectSsGSplash_Spawn(globalCtx, &contactPos, 0, 0, 0, 350);
        if (type == ROCK_SMALL) {
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 150, 650, 0);
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 400, 800, 4);
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 500, 1100, 8);
        } else {
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 300, 700, 0);
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 500, 900, 4);
            EffectSsGRipple_Spawn(globalCtx, &contactPos, 500, 1300, 8);
        }
        pthis->actor.minVelocityY = -6.0f;
        sRotSpeedX >>= 2;
        sRotSpeedY >>= 2;
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
        pthis->actor.bgCheckFlags &= ~0x40;
    }
    Math_StepToF(&pthis->actor.shape.yOffset, 0.0f, 2.0f);
    EnIshi_Fall(pthis);
    func_80A7ED94(&pthis->actor.velocity, D_80A7FA28[type]);
    Actor_UpdatePosition(&pthis->actor);
    pthis->actor.shape.rot.x += sRotSpeedX;
    pthis->actor.shape.rot.y += sRotSpeedY;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 7.5f, 35.0f, 0.0f, 0xC5);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
}

void EnIshi_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnIshi* pthis = (EnIshi*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnIshi_DrawSmall(EnIshi* pthis, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gFieldKakeraDL);
}

void EnIshi_DrawLarge(EnIshi* pthis, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ishi.c", 1050);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ishi.c", 1055),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gSPDisplayList(POLY_OPA_DISP++, gSilverRockDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ishi.c", 1062);
}

static EnIshiDrawFunc sDrawFuncs[] = { EnIshi_DrawSmall, EnIshi_DrawLarge };

void EnIshi_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnIshi* pthis = (EnIshi*)thisx;

    sDrawFuncs[pthis->actor.params & 1](pthis, globalCtx);
}

void EnIshi_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sRotSpeedX = 0;

    sRotSpeedY = 0;

    En_Ishi_InitVars = {
        ACTOR_EN_ISHI,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_FIELD_KEEP,
        sizeof(EnIshi),
        (ActorFunc)EnIshi_Init,
        (ActorFunc)EnIshi_Destroy,
        (ActorFunc)EnIshi_Update,
        (ActorFunc)EnIshi_Draw,
        (ActorFunc)EnIshi_Reset,
    };

    sColChkInfoInit = { 0, 12, 60, MASS_IMMOVABLE };

}

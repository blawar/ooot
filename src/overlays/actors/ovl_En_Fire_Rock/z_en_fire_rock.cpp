#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FIRE_ROCK_Z_EN_FIRE_ROCK_C
#include "actor_common.h"
#include "z_en_fire_rock.h"
#include "overlays/actors/ovl_En_Encount2/z_en_encount2.h"
#include "vt.h"
#include "objects/object_efc_star_field/object_efc_star_field.h"
#include "def/code_8006BA00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnFireRock_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFireRock_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnFireRock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFireRock_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFireRock_Draw(Actor* thisx, GlobalContext* globalCtx);

void FireRock_WaitSpawnRocksFromCeiling(EnFireRock* pthis, GlobalContext* globalCtx);
void FireRock_WaitOnFloor(EnFireRock* pthis, GlobalContext* globalCtx);
void EnFireRock_Fall(EnFireRock* pthis, GlobalContext* globalCtx);
void EnFireRock_SpawnMoreBrokenPieces(EnFireRock* pthis, GlobalContext* globalCtx);

ActorInit En_Fire_Rock_InitVars = {
    ACTOR_EN_FIRE_ROCK,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EFC_STAR_FIELD,
    sizeof(EnFireRock),
    (ActorFunc)EnFireRock_Init,
    (ActorFunc)EnFireRock_Destroy,
    (ActorFunc)EnFireRock_Update,
    (ActorFunc)EnFireRock_Draw,
    (ActorFunc)EnFireRock_Reset,
};

static ColliderCylinderInit D_80A12CA0 = {
    {
        COLTYPE_HARD,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x09, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 30, 30, -10, { 0, 0, 0 } },
};

static ColliderCylinderInit D_80A12CCC = {
    {
        COLTYPE_HARD,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x08 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 30, 30, -10, { 0, 0, 0 } },
};

void EnFireRock_Init(Actor* thisx, GlobalContext* globalCtx) {
    GlobalContext* globalCtx2 = globalCtx;
    Player* player = GET_PLAYER(globalCtx);
    EnFireRock* pthis = (EnFireRock*)thisx;
    s16 temp;

    pthis->type = pthis->actor.params;
    if (pthis->type != FIRE_ROCK_CEILING_SPOT_SPAWNER) {
        ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 15.0f);
        if (pthis->type != FIRE_ROCK_ON_FLOOR) {
            pthis->angularVelocity.x = (Rand_ZeroFloat(10.0f) + 15.0f);
            pthis->angularVelocity.y = (Rand_ZeroFloat(10.0f) + 15.0f);
            pthis->angularVelocity.z = (Rand_ZeroFloat(10.0f) + 15.0f);
        }
    }
    switch (pthis->type) {
        case FIRE_ROCK_CEILING_SPOT_SPAWNER:
            pthis->actor.draw = NULL;
            // "☆☆☆☆☆ ceiling waiting rock ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 天井待ち岩 ☆☆☆☆☆ \n" VT_RST);
            pthis->actionFunc = FireRock_WaitSpawnRocksFromCeiling;
            break;
        case FIRE_ROCK_ON_FLOOR:
            Actor_SetScale(&pthis->actor, 0.03f);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &D_80A12CCC);
            // "☆☆☆☆☆ floor rock ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 床岩 ☆☆☆☆☆ \n" VT_RST);
            pthis->collider.dim.radius = 23;
            pthis->collider.dim.height = 37;
            pthis->collider.dim.yShift = -10;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
            pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
            pthis->actionFunc = FireRock_WaitOnFloor;
            break;
        case FIRE_ROCK_SPAWNED_FALLING1: // spawned by encount2
            // sets unused vars?
            pthis->unk17C.x = (f32)(Rand_CenteredFloat(50.0f) + player->actor.world.pos.x);
            pthis->unk17C.z = (f32)(Rand_CenteredFloat(50.0f) + player->actor.world.pos.z);
        case FIRE_ROCK_SPAWNED_FALLING2: // spawned by encount2 and by the ceilling spawner
            pthis->scale = (Rand_ZeroFloat(2.0f) / 100.0f) + 0.02f;
            Actor_SetScale(&pthis->actor, pthis->scale);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &D_80A12CA0);
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y = Rand_CenteredFloat(65535.0f);
            pthis->actionFunc = EnFireRock_Fall;
            pthis->actor.shape.shadowScale = 15.0f;
            break;
        case FIRE_ROCK_BROKEN_PIECE1:
            pthis->actor.velocity.y = Rand_ZeroFloat(3.0f) + 4.0f;
            pthis->actor.speedXZ = Rand_ZeroFloat(3.0f) + 3.0f;
            pthis->scale = (Rand_ZeroFloat(1.0f) / 100.0f) + 0.02f;
            Actor_SetScale(&pthis->actor, pthis->scale);
            pthis->actor.gravity = -1.5f;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &D_80A12CA0);
            pthis->actor.shape.shadowScale = 10.0f;
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y = Rand_CenteredFloat(65535.0f);
            pthis->actionFunc = EnFireRock_Fall;
            break;
        case FIRE_ROCK_BROKEN_PIECE2:
            pthis->actor.velocity.y = Rand_ZeroFloat(3.0f) + 4.0f;
            pthis->actor.speedXZ = Rand_ZeroFloat(3.0f) + 2.0f;
            pthis->scale = (Rand_ZeroFloat(1.0f) / 500.0f) + 0.01f;
            Actor_SetScale(&pthis->actor, pthis->scale);
            pthis->actor.gravity = -1.2f;
            pthis->actor.shape.shadowScale = 5.0f;
            pthis->actor.world.rot.y = pthis->actor.shape.rot.y = Rand_CenteredFloat(65535.0f);
            pthis->actionFunc = EnFireRock_Fall;
            break;
        default:
            // "☆☆☆☆☆ No such rock! ERR !!!!!! ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ そんな岩はねぇ！ERR!!!!!! ☆☆☆☆☆ \n" VT_RST);
            Actor_Kill(&pthis->actor);
            break;
    }
}

void EnFireRock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFireRock* pthis = (EnFireRock*)thisx;

    if ((pthis->actor.parent != NULL) && (pthis->actor.parent == &pthis->spawner->actor)) {
        EnEncount2* spawner = (EnEncount2*)pthis->actor.parent;
        if ((spawner->actor.update != NULL) && (spawner->numSpawnedRocks > 0)) {
            spawner->numSpawnedRocks--;
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Number of spawned instances recovery ☆☆☆☆☆%d"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生数回復 ☆☆☆☆☆%d\n" VT_RST, spawner->numSpawnedRocks);
            osSyncPrintf("\n\n");
        }
    }
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnFireRock_Fall(EnFireRock* pthis, GlobalContext* globalCtx) {
    Player* player;
    Vec3f flamePos;
    s32 i;

    player = GET_PLAYER(globalCtx);
    if ((pthis->actor.floorHeight == -10000.0f) || (pthis->actor.world.pos.y < (player->actor.world.pos.y - 200.0f))) {
        Actor_Kill(&pthis->actor);
        return;
    }
    switch (pthis->type) {
        case FIRE_ROCK_SPAWNED_FALLING1:
            if (player->actor.world.pos.y < pthis->actor.world.pos.y) {
                if ((player->actor.world.pos.x > -700.0f) || (player->actor.world.pos.x < 100.0f) ||
                    (player->actor.world.pos.z > -1290.0f) || (player->actor.world.pos.z < -3880.0f)) {
                    Math_ApproachF(&pthis->actor.world.pos.x, player->actor.world.pos.x, 1.0f, 10.0f);
                    Math_ApproachF(&pthis->actor.world.pos.z, player->actor.world.pos.z, 1.0f, 10.0f);
                }
            }
        case FIRE_ROCK_SPAWNED_FALLING2:
            flamePos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
            flamePos.y = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.y;
            flamePos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
            EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &flamePos, 100, 0, 0, -1);
            break;
        case FIRE_ROCK_BROKEN_PIECE1:
            if ((globalCtx->gameplayFrames & 3) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_VALVAISA_ROCK);
            }
            break;
    }
    if ((pthis->actor.bgCheckFlags & 1) && (pthis->timer == 0)) {
        switch (pthis->type) {
            case FIRE_ROCK_SPAWNED_FALLING1:
            case FIRE_ROCK_SPAWNED_FALLING2:
                func_80033E88(&pthis->actor, globalCtx, 5, 2);
            case FIRE_ROCK_BROKEN_PIECE1:
                Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, pthis->actor.shape.shadowScale,
                                         1, 8.0f, 500, 10, 0);
                for (i = 0; i < 5; i++) {
                    flamePos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
                    flamePos.y = pthis->actor.floorHeight;
                    flamePos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
                    EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &flamePos, 300, 0, 0, -1);
                }
                pthis->actionFunc = EnFireRock_SpawnMoreBrokenPieces;
                break;
            default:
                Actor_SpawnFloorDustRing(globalCtx, &pthis->actor, &pthis->actor.world.pos, pthis->actor.shape.shadowScale,
                                         3, 8.0f, 200, 10, 0);
                Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EV_EXPLOSION);
                Actor_Kill(&pthis->actor);
                break;
        }
    }
}

/**
 * After the rock has already hit the ground and started rolling, spawn two more, giving the illusion of breaking into
 * two pieces.
 */
void EnFireRock_SpawnMoreBrokenPieces(EnFireRock* pthis, GlobalContext* globalCtx) {
    EnFireRock* spawnedFireRock;
    s32 nextRockType;
    s32 i;
    s32 temp;

    nextRockType = FIRE_ROCK_SPAWNED_FALLING1;
    switch (pthis->type) {
        case FIRE_ROCK_SPAWNED_FALLING1:
        case FIRE_ROCK_SPAWNED_FALLING2:
            nextRockType = FIRE_ROCK_BROKEN_PIECE1;
            break;
        case FIRE_ROCK_BROKEN_PIECE1:
            nextRockType = FIRE_ROCK_BROKEN_PIECE2;
    }

    if (nextRockType != FIRE_ROCK_SPAWNED_FALLING1) {
        for (i = 0; i < 2; i++) {
            spawnedFireRock = (EnFireRock*)Actor_Spawn(
                &globalCtx->actorCtx, globalCtx, ACTOR_EN_FIRE_ROCK, Rand_CenteredFloat(3.0f) + pthis->actor.world.pos.x,
                Rand_CenteredFloat(3.0f) + (pthis->actor.world.pos.y + 10.0f),
                Rand_CenteredFloat(3.0f) + pthis->actor.world.pos.z, 0, 0, 0, nextRockType);
            if (spawnedFireRock != NULL) {
                spawnedFireRock->actor.world.rot.y = pthis->actor.world.rot.y;
                if (i == 0) {
                    spawnedFireRock->actor.shape.rot.y = pthis->actor.shape.rot.y;
                }
                spawnedFireRock->scale = pthis->scale - 0.01f;
            } else {
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ イッパイデッス ☆☆☆☆☆ \n" VT_RST);
            }
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_VALVAISA_ROCK);
    }
    Actor_Kill(&pthis->actor);
}

void FireRock_WaitSpawnRocksFromCeiling(EnFireRock* pthis, GlobalContext* globalCtx) {
    EnFireRock* spawnedFireRock;

    if (pthis->actor.xzDistToPlayer < 200.0f) {
        if ((pthis->playerNearby == 0) && (pthis->timer2 == 0)) {
            pthis->timer2 = 30;
            spawnedFireRock = (EnFireRock*)Actor_Spawn(
                &globalCtx->actorCtx, globalCtx, ACTOR_EN_FIRE_ROCK, Rand_CenteredFloat(3.0f) + pthis->actor.world.pos.x,
                pthis->actor.world.pos.y + 10.0f, Rand_CenteredFloat(3.0f) + pthis->actor.world.pos.z, 0, 0, 0,
                FIRE_ROCK_SPAWNED_FALLING2);
            if (spawnedFireRock != NULL) {
                spawnedFireRock->timer = 10;
            } else {
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ イッパイデッス ☆☆☆☆☆ \n" VT_RST);
            }
        }
        pthis->playerNearby = 1;
    } else {
        pthis->playerNearby = 0;
    }
}

void FireRock_WaitOnFloor(EnFireRock* pthis, GlobalContext* globalCtx) {
    Vec3f flamePos;
    s16 scale;

    if (pthis->timer2 == 0) {
        flamePos.x = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.x;
        flamePos.y = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.y;
        flamePos.z = Rand_CenteredFloat(20.0f) + pthis->actor.world.pos.z;
        scale = 130 + (s16)Rand_CenteredFloat(60.0f);
        pthis->timer2 = 3 + (s16)Rand_ZeroFloat(3.0f);
        EffectSsEnFire_SpawnVec3f(globalCtx, &pthis->actor, &flamePos, scale, 0, 0, -1);
    }
}

void EnFireRock_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFireRock* pthis = (EnFireRock*)thisx;
    s16 setCollision;
    Player* player = GET_PLAYER(globalCtx);
    Actor* playerActor = &GET_PLAYER(globalCtx)->actor;

    if (pthis->timer2 != 0) {
        pthis->timer2--;
    }
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    pthis->actionFunc(pthis, globalCtx);

    if (pthis->type != FIRE_ROCK_CEILING_SPOT_SPAWNER) {
        f32 temp;

        pthis->rockRotation.x += pthis->angularVelocity.x;
        pthis->rockRotation.y += pthis->angularVelocity.y;
        pthis->rockRotation.z += pthis->angularVelocity.z;
        pthis->relativePos.y = 3.0f;

        temp = 10.0f + (pthis->scale * 300.0f);
        thisx->shape.shadowScale = temp;
        if (thisx->shape.shadowScale < 10.0f) {
            thisx->shape.shadowScale = 10.0f;
        }
        if (thisx->shape.shadowScale > 20.0f) {
            thisx->shape.shadowScale = 20.0f;
        }

        if ((pthis->type == FIRE_ROCK_SPAWNED_FALLING1) || (pthis->type == FIRE_ROCK_SPAWNED_FALLING2)) {
            thisx->gravity = -0.3f - (pthis->scale * 7.0f);
        }
        if (pthis->type != FIRE_ROCK_ON_FLOOR) {
            Actor_MoveForward(thisx);
            Actor_UpdateBgCheckInfo(globalCtx, thisx, 50.0f, 50.0f, 100.0f, 0x1C);
        }

        setCollision = false;
        if (pthis->actionFunc != EnFireRock_SpawnMoreBrokenPieces) {
            if ((pthis->type == FIRE_ROCK_SPAWNED_FALLING1) || (pthis->type == FIRE_ROCK_SPAWNED_FALLING2) ||
                (pthis->type == FIRE_ROCK_BROKEN_PIECE1)) {
                if (pthis->collider.base.atFlags & 4) {
                    pthis->collider.base.atFlags &= ~4;
                    Audio_PlayActorSound2(thisx, NA_SE_EV_BRIDGE_OPEN_STOP);
                    thisx->velocity.y = 0.0f;
                    thisx->speedXZ = 0.0f;
                    pthis->actionFunc = EnFireRock_SpawnMoreBrokenPieces;
                    // "☆☆☆☆☆ Shield Defense Lv1 ☆☆☆☆☆"
                    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ シールド防御 Lv１ ☆☆☆☆☆ \n" VT_RST);
                    return;
                }
                setCollision = true;
            }
        }

        if (pthis->type == FIRE_ROCK_ON_FLOOR) {
            if (pthis->collider.base.atFlags & 2) {
                pthis->collider.base.atFlags &= ~2;
                if (pthis->collider.base.at == playerActor) {
                    if (!(player->stateFlags1 & 0x04000000)) {
                        func_8002F758(globalCtx, thisx, 2.0f, -player->actor.world.rot.y, 3.0f, 4);
                    }
                    return;
                }
            }
            setCollision = true;
        }
        if (setCollision) {
            Collider_UpdateCylinder(thisx, &pthis->collider);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

void EnFireRock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnFireRock* pthis = (EnFireRock*)thisx;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fire_rock.c", 747);
    Matrix_Translate(thisx->world.pos.x + pthis->relativePos.x, thisx->world.pos.y + pthis->relativePos.y,
                     thisx->world.pos.z + pthis->relativePos.z, MTXMODE_NEW);
    Matrix_RotateX(DEG_TO_RAD(pthis->rockRotation.x), MTXMODE_APPLY);
    Matrix_RotateY(DEG_TO_RAD(pthis->rockRotation.y), MTXMODE_APPLY);
    Matrix_RotateZ(DEG_TO_RAD(pthis->rockRotation.z), MTXMODE_APPLY);
    Matrix_Scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MTXMODE_APPLY);
    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 155, 55, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 155, 255, 55, 255);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fire_rock.c", 768),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, object_efc_star_field_DL_000DE0);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fire_rock.c", 773);
}

void EnFireRock_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Fire_Rock_InitVars = {
        ACTOR_EN_FIRE_ROCK,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_EFC_STAR_FIELD,
        sizeof(EnFireRock),
        (ActorFunc)EnFireRock_Init,
        (ActorFunc)EnFireRock_Destroy,
        (ActorFunc)EnFireRock_Update,
        (ActorFunc)EnFireRock_Draw,
        (ActorFunc)EnFireRock_Reset,
    };

    D_80A12CA0 = {
        {
            COLTYPE_HARD,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x09, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 30, 30, -10, { 0, 0, 0 } },
    };

    D_80A12CCC = {
        {
            COLTYPE_HARD,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x01, 0x08 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 30, 30, -10, { 0, 0, 0 } },
    };

}

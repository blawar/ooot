#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WOOD02_Z_EN_WOOD02_C
#include "actor_common.h"
/*
 * File: z_en_wood02.c
 * Overlay: ovl_En_Wood02
 * Description: Trees, bushes, leaves
 */

#include "z_en_wood02.h"
#include "objects/object_wood02/object_wood02.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define FLAGS 0

void EnWood02_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnWood02_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Update(Actor* thisx, GlobalContext* globalCtx);
void EnWood02_Draw(Actor* thisx, GlobalContext* globalCtx);

/**
 * WOOD_SPAWN_SPAWNER is also used by some individual trees: EnWood02_Update also checks for parent before running any
 * despawning code.
 *  */

ActorInit En_Wood02_InitVars = {
    ACTOR_EN_WOOD02,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_WOOD02,
    sizeof(EnWood02),
    (ActorFunc)EnWood02_Init,
    (ActorFunc)EnWood02_Destroy,
    (ActorFunc)EnWood02_Update,
    (ActorFunc)EnWood02_Draw,
    (ActorFunc)EnWood02_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_TREE,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK5,
        { 0x00000000, 0x00, 0x00 },
        { 0x0FC0074A, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 18, 60, 0, { 0, 0, 0 } },
};

static f32 sSpawnDistance[] = { 707.0f, 525.0f, 510.0f, 500.0f, 566.0f, 141.0f };

static s16 sSpawnAngle[] = { 0x1FFF, 0x4C9E, 0x77F5, 0xA5C9, 0xD6C3, 0xA000 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 5600, ICHAIN_STOP),
};

static Gfx* D_80B3BF54[] = {
    object_wood02_DL_0078D0, object_wood02_DL_007CA0, object_wood02_DL_0080D0, object_wood02_DL_000090,
    object_wood02_DL_000340, object_wood02_DL_000340, object_wood02_DL_000700,
};

static Gfx* D_80B3BF70[] = {
    object_wood02_DL_007968,
    object_wood02_DL_007D38,
    object_wood02_DL_0081A8,
    NULL,
    NULL,
    NULL,
    object_wood02_DL_007AD0,
    object_wood02_DL_007E20,
    object_wood02_DL_008350,
    object_wood02_DL_000160,
    object_wood02_DL_000440,
    object_wood02_DL_000700,
};

static f32 sSpawnCos;

static f32 sSpawnSin;

s32 EnWood02_SpawnZoneCheck(EnWood02* pthis, GlobalContext* globalCtx, Vec3f* pos) {
    f32 phi_f12;

    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->viewProjectionMtxF, pos, &pthis->actor.projectedPos,
                                 &pthis->actor.projectedW);

    phi_f12 = ((pthis->actor.projectedW == 0.0f) ? 1000.0f : fabsf(1.0f / pthis->actor.projectedW));

    if ((-pthis->actor.uncullZoneScale < pthis->actor.projectedPos.z) &&
        (pthis->actor.projectedPos.z < (pthis->actor.uncullZoneForward + pthis->actor.uncullZoneScale)) &&
        (((fabsf(pthis->actor.projectedPos.x) - pthis->actor.uncullZoneScale) * phi_f12) < 1.0f) &&
        (((pthis->actor.projectedPos.y + pthis->actor.uncullZoneDownward) * phi_f12) > -1.0f) &&
        (((pthis->actor.projectedPos.y - pthis->actor.uncullZoneScale) * phi_f12) < 1.0f)) {
        return true;
    }
    return false;
}

/** Spawns similar-looking trees or bushes only when the player is sufficiently close. Presumably done pthis way to keep
 * memory usage down in Hyrule Field. */
void EnWood02_SpawnOffspring(EnWood02* pthis, GlobalContext* globalCtx) {
    EnWood02* childWood;
    s16* childSpawnAngle;
    Vec3f childPos;
    s16 extraRot;
    s16 childParams;
    s32 i;

    for (i = 4; i >= 0; i--) {
        if ((pthis->unk_14E[i] & 0x7F) == 0) {
            extraRot = 0;
            if (pthis->actor.params == WOOD_BUSH_GREEN_LARGE_SPAWNER) {
                extraRot = 0x4000;
            }
            childSpawnAngle = &sSpawnAngle[i];
            sSpawnCos = Math_CosS(*childSpawnAngle + pthis->actor.world.rot.y + extraRot);
            sSpawnSin = Math_SinS(*childSpawnAngle + pthis->actor.world.rot.y + extraRot);
            childPos.x = (sSpawnDistance[i] * sSpawnSin) + pthis->actor.home.pos.x;
            childPos.y = pthis->actor.home.pos.y;
            childPos.z = (sSpawnDistance[i] * sSpawnCos) + pthis->actor.home.pos.z;
            if (EnWood02_SpawnZoneCheck(pthis, globalCtx, &childPos)) {
                if ((pthis->unk_14E[i] & 0x80) != 0) {
                    childParams = (0xFF00 | (pthis->actor.params + 1));
                } else {
                    childParams = (((pthis->drawType & 0xF0) << 4) | (pthis->actor.params + 1));
                }
                childWood = (EnWood02*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx,
                                                          ACTOR_EN_WOOD02, childPos.x, childPos.y, childPos.z,
                                                          pthis->actor.world.rot.x, *childSpawnAngle, 0, childParams);
                if (childWood != NULL) {
                    childWood->unk_14E[0] = i;
                    pthis->unk_14E[i] |= 1;
                    childWood->actor.projectedPos = pthis->actor.projectedPos;
                } else {
                    pthis->unk_14E[i] &= 0x80;
                }
            }
        }
    }
}

void EnWood02_Init(Actor* thisx, GlobalContext* globalCtx2) {
    s16 spawnType;
    f32 actorScale;
    GlobalContext* globalCtx = globalCtx2;
    EnWood02* pthis = (EnWood02*)thisx;
    CollisionPoly* outPoly;
    s32 bgId;
    f32 floorY;
    s16 extraRot;

    spawnType = WOOD_SPAWN_NORMAL;
    actorScale = 1.0f;
    pthis->unk_14C = (pthis->actor.params >> 8) & 0xFF;

    if (pthis->actor.home.rot.z != 0) {
        pthis->actor.home.rot.z = (pthis->actor.home.rot.z << 8) | pthis->unk_14C;
        pthis->unk_14C = -1;
        pthis->actor.world.rot.z = pthis->actor.shape.rot.z = 0;
    } else if (pthis->unk_14C & 0x80) {
        pthis->unk_14C = -1;
    }

    pthis->actor.params &= 0xFF;
    Actor_ProcessInitChain(&pthis->actor, sInitChain);

    if (pthis->actor.params <= WOOD_TREE_KAKARIKO_ADULT) {
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    }

    switch (pthis->actor.params) {
        case WOOD_BUSH_GREEN_LARGE_SPAWNER:
        case WOOD_BUSH_BLACK_LARGE_SPAWNER:
            spawnType = 1;
        case WOOD_BUSH_GREEN_LARGE_SPAWNED:
        case WOOD_BUSH_BLACK_LARGE_SPAWNED:
            spawnType++;
        case WOOD_TREE_CONICAL_LARGE:
        case WOOD_BUSH_GREEN_LARGE:
        case WOOD_BUSH_BLACK_LARGE:
            actorScale = 1.5f;
            pthis->actor.uncullZoneForward = 4000.0f;
            pthis->actor.uncullZoneScale = 2000.0f;
            pthis->actor.uncullZoneDownward = 2400.0f;
            break;
        case WOOD_TREE_CONICAL_SPAWNER:
        case WOOD_TREE_OVAL_YELLOW_SPAWNER:
        case WOOD_TREE_OVAL_GREEN_SPAWNER:
        case WOOD_BUSH_GREEN_SMALL_SPAWNER:
        case WOOD_BUSH_BLACK_SMALL_SPAWNER:
            spawnType = 1;
        case WOOD_TREE_CONICAL_SPAWNED:
        case WOOD_TREE_OVAL_YELLOW_SPAWNED:
        case WOOD_TREE_OVAL_GREEN_SPAWNED:
        case WOOD_BUSH_GREEN_SMALL_SPAWNED:
        case WOOD_BUSH_BLACK_SMALL_SPAWNED:
            spawnType++;
        case WOOD_TREE_CONICAL_MEDIUM:
        case WOOD_TREE_OVAL_GREEN:
        case WOOD_TREE_KAKARIKO_ADULT:
        case WOOD_BUSH_GREEN_SMALL:
        case WOOD_BUSH_BLACK_SMALL:
            pthis->actor.uncullZoneForward = 4000.0f;
            pthis->actor.uncullZoneScale = 800.0f;
            pthis->actor.uncullZoneDownward = 1800.0f;
            break;
        case WOOD_TREE_CONICAL_SMALL:
            actorScale = 0.6f;
            pthis->actor.uncullZoneForward = 4000.0f;
            pthis->actor.uncullZoneScale = 400.0f;
            pthis->actor.uncullZoneDownward = 1000.0f;
            break;
        case WOOD_LEAF_GREEN:
        case WOOD_LEAF_YELLOW:
            pthis->unk_14E[0] = 0x4B;
            actorScale = 0.02f;
            pthis->actor.velocity.x = Rand_CenteredFloat(6.0f);
            pthis->actor.velocity.z = Rand_CenteredFloat(6.0f);
            pthis->actor.velocity.y = (Rand_ZeroOne() * 1.25f) + -3.1f;
    }

    if (pthis->actor.params <= WOOD_TREE_CONICAL_SPAWNED) {
        pthis->drawType = WOOD_DRAW_TREE_CONICAL;
    } else if (pthis->actor.params <= WOOD_TREE_OVAL_GREEN_SPAWNED) {
        pthis->drawType = WOOD_DRAW_TREE_OVAL;
    } else if (pthis->actor.params <= WOOD_TREE_KAKARIKO_ADULT) {
        pthis->drawType = WOOD_DRAW_TREE_KAKARIKO_ADULT;
    } else if (pthis->actor.params <= WOOD_BUSH_GREEN_LARGE_SPAWNED) {
        pthis->drawType = WOOD_DRAW_BUSH_GREEN;
    } else if (pthis->actor.params <= WOOD_LEAF_GREEN) { // Black bushes and green leaves
        pthis->drawType = WOOD_DRAW_4;
    } else {
        pthis->drawType = WOOD_DRAW_LEAF_YELLOW;
    }

    Actor_SetScale(&pthis->actor, actorScale);
    pthis->spawnType = spawnType;

    if (spawnType != WOOD_SPAWN_NORMAL) {
        extraRot = 0;

        if (pthis->actor.params == WOOD_BUSH_GREEN_LARGE_SPAWNER) {
            extraRot = 0x4000;
        }

        if (spawnType == WOOD_SPAWN_SPAWNER) {
            pthis->drawType |= pthis->unk_14C << 4;
            EnWood02_SpawnOffspring(pthis, globalCtx);
            sSpawnCos = Math_CosS(sSpawnAngle[5] + pthis->actor.world.rot.y + extraRot);
            sSpawnSin = Math_SinS(sSpawnAngle[5] + pthis->actor.world.rot.y + extraRot);
            pthis->actor.world.pos.x += (sSpawnSin * sSpawnDistance[5]);
            pthis->actor.world.pos.z += (sSpawnCos * sSpawnDistance[5]);
        } else {
            pthis->actor.flags |= ACTOR_FLAG_4;
        }

        // Snap to floor, or remove if over void
        pthis->actor.world.pos.y += 200.0f;
        floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &outPoly, &bgId, &pthis->actor, &pthis->actor.world.pos);

        if (floorY > BGCHECK_Y_MIN) {
            pthis->actor.world.pos.y = floorY;
        } else {
            Actor_Kill(&pthis->actor);
            return;
        }
    }
    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
    pthis->actor.home.rot.y = 0;
    pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
}

void EnWood02_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnWood02* pthis = (EnWood02*)thisx;

    if (pthis->actor.params <= WOOD_TREE_KAKARIKO_ADULT) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void EnWood02_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnWood02* pthis = (EnWood02*)thisx;
    f32 wobbleAmplitude;
    u8 new_var;
    u8 phi_v0;
    s32 pad;
    Vec3f dropsSpawnPt;
    s32 i;
    s32 leavesParams;

    // Despawn extra trees in a group if out of range
    if ((pthis->spawnType == WOOD_SPAWN_SPAWNED) && (pthis->actor.parent != NULL)) {
        if (!(pthis->actor.flags & ACTOR_FLAG_UNCULLED)) {
            new_var = pthis->unk_14E[0];
            phi_v0 = 0;

            if (pthis->unk_14C < 0) {
                phi_v0 = 0x80;
            }

            ((EnWood02*)pthis->actor.parent)->unk_14E[new_var] = phi_v0;
            Actor_Kill(&pthis->actor);
            return;
        }
    } else if (pthis->spawnType == WOOD_SPAWN_SPAWNER) {
        EnWood02_SpawnOffspring(pthis, globalCtx);
    }

    if (pthis->actor.params <= WOOD_TREE_KAKARIKO_ADULT) {
        if (pthis->collider.base.acFlags & AC_HIT) {
            pthis->collider.base.acFlags &= ~AC_HIT;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_REFLECTION_WOOD);
        }

        if (pthis->actor.home.rot.y != 0) {
            dropsSpawnPt = pthis->actor.world.pos;
            dropsSpawnPt.y += 200.0f;

            if ((pthis->unk_14C >= 0) && (pthis->unk_14C < 0x64)) {
                Item_DropCollectibleRandom(globalCtx, &pthis->actor, &dropsSpawnPt, pthis->unk_14C << 4);
            } else {
                if (pthis->actor.home.rot.z != 0) {
                    pthis->actor.home.rot.z &= 0x1FFF;
                    pthis->actor.home.rot.z |= 0xE000;
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_SW, dropsSpawnPt.x, dropsSpawnPt.y,
                                dropsSpawnPt.z, 0, pthis->actor.world.rot.y, 0, pthis->actor.home.rot.z);
                    pthis->actor.home.rot.z = 0;
                }
            }

            // Spawn falling leaves
            if (pthis->unk_14C >= -1) {
                leavesParams = WOOD_LEAF_GREEN;

                if ((pthis->actor.params == WOOD_TREE_OVAL_YELLOW_SPAWNER) ||
                    (pthis->actor.params == WOOD_TREE_OVAL_YELLOW_SPAWNED)) {
                    leavesParams = WOOD_LEAF_YELLOW;
                }
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_TREE_SWING);

                for (i = 3; i >= 0; i--) {
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_WOOD02, dropsSpawnPt.x, dropsSpawnPt.y,
                                dropsSpawnPt.z, 0, Rand_CenteredFloat(65535.0f), 0, leavesParams);
                }
            }
            pthis->unk_14C = -0x15;
            pthis->actor.home.rot.y = 0;
        }

        if (pthis->actor.xzDistToPlayer < 600.0f) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    } else if (pthis->actor.params < 0x17) { // Bush
        Player* player = GET_PLAYER(globalCtx);

        if (pthis->unk_14C >= -1) {
            if (((player->rideActor == NULL) && (sqrt(pthis->actor.xyzDistToPlayerSq) < 20.0) &&
                 (player->linearVelocity != 0.0f)) ||
                ((player->rideActor != NULL) && (sqrt(pthis->actor.xyzDistToPlayerSq) < 60.0) &&
                 (player->rideActor->speedXZ != 0.0f))) {
                if ((pthis->unk_14C >= 0) && (pthis->unk_14C < 0x64)) {
                    Item_DropCollectibleRandom(globalCtx, &pthis->actor, &pthis->actor.world.pos,
                                               ((pthis->unk_14C << 4) | 0x8000));
                }
                pthis->unk_14C = -0x15;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_TREE_SWING);
            }
        }
    } else { // Leaves
        pthis->unk_14C++;
        Math_ApproachF(&pthis->actor.velocity.x, 0.0f, 1.0f, 5 * 0.01f);
        Math_ApproachF(&pthis->actor.velocity.z, 0.0f, 1.0f, 5 * 0.01f);
        func_8002D7EC(&pthis->actor);
        pthis->actor.shape.rot.z = Math_SinS(3000 * pthis->unk_14C) * 0x4000;
        pthis->unk_14E[0]--;

        if (pthis->unk_14E[0] == 0) {
            Actor_Kill(&pthis->actor);
        }
    }

    // Wobble from impact
    if (pthis->unk_14C < -1) {
        pthis->unk_14C++;
        wobbleAmplitude = Math_SinS((pthis->unk_14C ^ 0xFFFF) * 0x3332) * 250.0f;
        pthis->actor.shape.rot.x = (Math_CosS(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) * wobbleAmplitude);
        pthis->actor.shape.rot.z = (Math_SinS(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y) * wobbleAmplitude);
    }
}

void EnWood02_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnWood02* pthis = (EnWood02*)thisx;
    s16 type;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    u8 red;
    u8 green;
    u8 blue;

    OPEN_DISPS(gfxCtx, "../z_en_wood02.c", 775);
    type = pthis->actor.params;

    if ((type == WOOD_TREE_OVAL_GREEN_SPAWNER) || (type == WOOD_TREE_OVAL_GREEN_SPAWNED) ||
        (type == WOOD_TREE_OVAL_GREEN) || (type == WOOD_LEAF_GREEN)) {
        red = 50;
        green = 170;
        blue = 70;
    } else if ((type == WOOD_TREE_OVAL_YELLOW_SPAWNER) || (type == WOOD_TREE_OVAL_YELLOW_SPAWNED) ||
               (type == WOOD_LEAF_YELLOW)) {
        red = 180;
        green = 155;
        blue = 0;
    } else {
        red = green = blue = 255;
    }

    func_80093D84(gfxCtx);

    if ((pthis->actor.params == WOOD_LEAF_GREEN) || (pthis->actor.params == WOOD_LEAF_YELLOW)) {
        func_80093D18(gfxCtx);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, red, green, blue, 127);
        Gfx_DrawDListOpa(globalCtx, object_wood02_DL_000700);
    } else if (D_80B3BF70[pthis->drawType & 0xF] != NULL) {
        Gfx_DrawDListOpa(globalCtx, D_80B3BF54[pthis->drawType & 0xF]);
        gDPSetEnvColor(POLY_XLU_DISP++, red, green, blue, 0);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_wood02.c", 808),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, D_80B3BF70[pthis->drawType & 0xF]);
    } else {
        func_80093D84(gfxCtx);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_wood02.c", 814),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, D_80B3BF54[pthis->drawType & 0xF]);
    }

    CLOSE_DISPS(gfxCtx, "../z_en_wood02.c", 840);
}

void EnWood02_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Wood02_InitVars = {
        ACTOR_EN_WOOD02,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_WOOD02,
        sizeof(EnWood02),
        (ActorFunc)EnWood02_Init,
        (ActorFunc)EnWood02_Destroy,
        (ActorFunc)EnWood02_Update,
        (ActorFunc)EnWood02_Draw,
        (ActorFunc)EnWood02_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_TREE,
            AT_NONE,
            AC_ON | AC_HARD | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK5,
            { 0x00000000, 0x00, 0x00 },
            { 0x0FC0074A, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 18, 60, 0, { 0, 0, 0 } },
    };

    sSpawnCos = {0};

    sSpawnSin = {0};

}

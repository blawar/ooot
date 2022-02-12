#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BOM_CHU_Z_EN_BOM_CHU_C
#include "actor_common.h"
#include "z_en_bom_chu.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800430A0.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_eff_blure.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

#define BOMBCHU_SCALE 0.01f

void EnBomChu_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBomChu_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBomChu_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBomChu_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBomChu_WaitForRelease(EnBomChu* pthis, GlobalContext* globalCtx);
void EnBomChu_Move(EnBomChu* pthis, GlobalContext* globalCtx);
void EnBomChu_WaitForKill(EnBomChu* pthis, GlobalContext* globalCtx);

ActorInit En_Bom_Chu_InitVars = {
    ACTOR_EN_BOM_CHU,
    ACTORCAT_EXPLOSIVE,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnBomChu),
    (ActorFunc)EnBomChu_Init,
    (ActorFunc)EnBomChu_Destroy,
    (ActorFunc)EnBomChu_Update,
    (ActorFunc)EnBomChu_Draw,
};

static ColliderJntSphElementInit sJntSphElemInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 1, { { 0, 0, 0 }, 12 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_1 | OC1_TYPE_2,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElemInit),
    sJntSphElemInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000 * BOMBCHU_SCALE, ICHAIN_STOP),
};

void EnBomChu_Init(Actor* thisx, GlobalContext* globalCtx) {
    static u8 p1StartColor[] = { 250, 0, 0, 250 };
    static u8 p2StartColor[] = { 200, 0, 0, 130 };
    static u8 p1EndColor[] = { 150, 0, 0, 100 };
    static u8 p2EndColor[] = { 100, 0, 0, 50 };
    EnBomChu* pthis = (EnBomChu*)thisx;
    EffectBlureInit1 blureInit;
    s32 i;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->colliderElements);

    pthis->collider.elements[0].dim.worldSphere.radius = pthis->collider.elements[0].dim.modelSphere.radius;

    for (i = 0; i < 4; i++) {
        blureInit.p1StartColor[i] = p1StartColor[i];
        blureInit.p2StartColor[i] = p2StartColor[i];
        blureInit.p1EndColor[i] = p1EndColor[i];
        blureInit.p2EndColor[i] = p2EndColor[i];
    }

    blureInit.elemDuration = 16;
    blureInit.unkFlag = 0;
    blureInit.calcMode = 0;

    Effect_Add(globalCtx, &pthis->blure1Index, EFFECT_BLURE1, 0, 0, &blureInit);
    Effect_Add(globalCtx, &pthis->blure2Index, EFFECT_BLURE1, 0, 0, &blureInit);

    pthis->actor.room = -1;
    pthis->timer = 120;
    pthis->actionFunc = EnBomChu_WaitForRelease;
}

void EnBomChu_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBomChu* pthis = (EnBomChu*)thisx;

    Effect_Delete(globalCtx, pthis->blure1Index);
    Effect_Delete(globalCtx, pthis->blure2Index);
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

void EnBomChu_Explode(EnBomChu* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;
    s32 i;

    bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                               pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, BOMB_BODY);
    if (bomb != NULL) {
        bomb->timer = 0;
    }

    pthis->timer = 1;
    pthis->actor.speedXZ = 0.0f;

    if (pthis->actor.yDistToWater > 0.0f) {
        for (i = 0; i < 40; i++) {
            EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 1.0f, 5.0f, 30.0f, 0.25f);
        }
    }

    pthis->actionFunc = EnBomChu_WaitForKill;
}

void EnBomChu_CrossProduct(Vec3f* a, Vec3f* b, Vec3f* dest) {
    dest->x = (a->y * b->z) - (a->z * b->y);
    dest->y = (a->z * b->x) - (a->x * b->z);
    dest->z = (a->x * b->y) - (a->y * b->x);
}

void EnBomChu_UpdateFloorPoly(EnBomChu* pthis, CollisionPoly* floorPoly, GlobalContext* globalCtx) {
    Vec3f normal;
    Vec3f vec;
    f32 angle;
    f32 magnitude;
    f32 normDotUp;
    MtxF mf;

    pthis->actor.floorPoly = floorPoly;

    normal.x = COLPOLY_GET_NORMAL(floorPoly->normal.x);
    normal.y = COLPOLY_GET_NORMAL(floorPoly->normal.y);
    normal.z = COLPOLY_GET_NORMAL(floorPoly->normal.z);

    normDotUp = DOTXYZ(normal, pthis->axisUp);

    if (!(fabsf(normDotUp) >= 1.0f)) {
        angle = Math_FAcosF(normDotUp);

        if (!(angle < 0.001f)) {
            EnBomChu_CrossProduct(&pthis->axisUp, &normal, &vec);
            //! @bug pthis function expects a unit vector but `vec` is not normalized
            Matrix_RotateAxis(angle, &vec, MTXMODE_NEW);

            Matrix_MultVec3f(&pthis->axisLeft, &vec);
            pthis->axisLeft = vec;

            EnBomChu_CrossProduct(&pthis->axisLeft, &normal, &pthis->axisForwards);

            magnitude = Math3D_Vec3fMagnitude(&pthis->axisForwards);

            if (magnitude < 0.001f) {
                EnBomChu_Explode(pthis, globalCtx);
                return;
            }

            pthis->axisForwards.x *= 1.0f / magnitude;
            pthis->axisForwards.y *= 1.0f / magnitude;
            pthis->axisForwards.z *= 1.0f / magnitude;

            pthis->axisUp = normal;

            if (1) {}

            // mf = (axisLeft | axisUp | axisForwards)

            mf.xx = pthis->axisLeft.x;
            mf.yx = pthis->axisLeft.y;
            mf.zx = pthis->axisLeft.z;

            mf.xy = normal.x;
            mf.yy = normal.y;
            mf.zy = normal.z;

            mf.xz = pthis->axisForwards.x;
            mf.yz = pthis->axisForwards.y;
            mf.zz = pthis->axisForwards.z;

            Matrix_MtxFToYXZRotS(&mf, &pthis->actor.world.rot, 0);

            // A hack for preventing bombchus from sticking to ledges.
            // The visual rotation reverts the sign inversion (shape.rot.x = -world.rot.x).
            // The better fix would be making func_8002D908 compute XYZ velocity better,
            // or not using it and make the bombchu compute its own velocity.
            pthis->actor.world.rot.x = -pthis->actor.world.rot.x;
        }
    }
}

void EnBomChu_WaitForRelease(EnBomChu* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        EnBomChu_Explode(pthis, globalCtx);
        return;
    }

    if (Actor_HasNoParent(&pthis->actor, globalCtx)) {
        pthis->actor.world.pos = player->actor.world.pos;
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
        pthis->actor.shape.rot.y = player->actor.shape.rot.y;

        // rot.y = 0 -> +z (forwards in model space)
        pthis->axisForwards.x = Math_SinS(pthis->actor.shape.rot.y);
        pthis->axisForwards.y = 0.0f;
        pthis->axisForwards.z = Math_CosS(pthis->actor.shape.rot.y);

        // +y (up in model space)
        pthis->axisUp.x = 0.0f;
        pthis->axisUp.y = 1.0f;
        pthis->axisUp.z = 0.0f;

        // rot.y = 0 -> +x (left in model space)
        pthis->axisLeft.x = Math_SinS(pthis->actor.shape.rot.y + 0x4000);
        pthis->axisLeft.y = 0;
        pthis->axisLeft.z = Math_CosS(pthis->actor.shape.rot.y + 0x4000);

        pthis->actor.speedXZ = 8.0f;
        //! @bug there is no NULL check on the floor poly.  If the player is out of bounds the floor poly will be NULL
        //! and will cause a crash inside pthis function.
        EnBomChu_UpdateFloorPoly(pthis, pthis->actor.floorPoly, globalCtx);
        pthis->actor.flags |= ACTOR_FLAG_0; // make chu targetable
        func_8002F850(globalCtx, &pthis->actor);
        pthis->actionFunc = EnBomChu_Move;
    }
}

void EnBomChu_Move(EnBomChu* pthis, GlobalContext* globalCtx) {
    CollisionPoly* polySide;
    CollisionPoly* polyUpDown;
    s32 bgIdSide;
    s32 bgIdUpDown;
    s32 i;
    f32 lineLength;
    Vec3f posA;
    Vec3f posB;
    Vec3f posSide;
    Vec3f posUpDown;

    pthis->actor.speedXZ = 8.0f;
    lineLength = pthis->actor.speedXZ * 2.0f;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if ((pthis->timer == 0) || (pthis->collider.base.acFlags & AC_HIT) ||
        ((pthis->collider.base.ocFlags1 & OC1_HIT) && (pthis->collider.base.oc->category != ACTORCAT_PLAYER))) {
        EnBomChu_Explode(pthis, globalCtx);
        return;
    }

    posA.x = pthis->actor.world.pos.x + (pthis->axisUp.x * 2.0f);
    posA.y = pthis->actor.world.pos.y + (pthis->axisUp.y * 2.0f);
    posA.z = pthis->actor.world.pos.z + (pthis->axisUp.z * 2.0f);

    posB.x = pthis->actor.world.pos.x - (pthis->axisUp.x * 4.0f);
    posB.y = pthis->actor.world.pos.y - (pthis->axisUp.y * 4.0f);
    posB.z = pthis->actor.world.pos.z - (pthis->axisUp.z * 4.0f);

    if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &posA, &posB, &posUpDown, &polyUpDown, true, true, true, true,
                                &bgIdUpDown) &&
        !(func_80041DB8(&globalCtx->colCtx, polyUpDown, bgIdUpDown) & 0x30) && // && not crawl space?
        !SurfaceType_IsIgnoredByProjectiles(&globalCtx->colCtx, polyUpDown, bgIdUpDown)) {
        // forwards
        posB.x = (pthis->axisForwards.x * lineLength) + posA.x;
        posB.y = (pthis->axisForwards.y * lineLength) + posA.y;
        posB.z = (pthis->axisForwards.z * lineLength) + posA.z;

        if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &posA, &posB, &posSide, &polySide, true, true, true, true,
                                    &bgIdSide) &&
            !(func_80041DB8(&globalCtx->colCtx, polySide, bgIdSide) & 0x30) &&
            !SurfaceType_IsIgnoredByProjectiles(&globalCtx->colCtx, polySide, bgIdSide)) {
            EnBomChu_UpdateFloorPoly(pthis, polySide, globalCtx);
            pthis->actor.world.pos = posSide;
            pthis->actor.floorBgId = bgIdSide;
            pthis->actor.speedXZ = 0.0f;
        } else {
            if (pthis->actor.floorPoly != polyUpDown) {
                EnBomChu_UpdateFloorPoly(pthis, polyUpDown, globalCtx);
            }

            pthis->actor.world.pos = posUpDown;
            pthis->actor.floorBgId = bgIdUpDown;
        }
    } else {
        pthis->actor.speedXZ = 0.0f;
        lineLength *= 3.0f;
        posA = posB;

        for (i = 0; i < 3; i++) {
            if (i == 0) {
                // backwards
                posB.x = posA.x - (pthis->axisForwards.x * lineLength);
                posB.y = posA.y - (pthis->axisForwards.y * lineLength);
                posB.z = posA.z - (pthis->axisForwards.z * lineLength);
            } else if (i == 1) {
                // left
                posB.x = posA.x + (pthis->axisLeft.x * lineLength);
                posB.y = posA.y + (pthis->axisLeft.y * lineLength);
                posB.z = posA.z + (pthis->axisLeft.z * lineLength);
            } else {
                // right
                posB.x = posA.x - (pthis->axisLeft.x * lineLength);
                posB.y = posA.y - (pthis->axisLeft.y * lineLength);
                posB.z = posA.z - (pthis->axisLeft.z * lineLength);
            }

            if (BgCheck_EntityLineTest1(&globalCtx->colCtx, &posA, &posB, &posSide, &polySide, true, true, true, true,
                                        &bgIdSide) &&
                !(func_80041DB8(&globalCtx->colCtx, polySide, bgIdSide) & 0x30) &&
                !SurfaceType_IsIgnoredByProjectiles(&globalCtx->colCtx, polySide, bgIdSide)) {
                EnBomChu_UpdateFloorPoly(pthis, polySide, globalCtx);
                pthis->actor.world.pos = posSide;
                pthis->actor.floorBgId = bgIdSide;
                break;
            }
        }

        if (i == 3) {
            // no collision nearby
            EnBomChu_Explode(pthis, globalCtx);
        }
    }

    Math_ScaledStepToS(&pthis->actor.shape.rot.x, -pthis->actor.world.rot.x, 0x800);
    Math_ScaledStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 0x800);
    Math_ScaledStepToS(&pthis->actor.shape.rot.z, pthis->actor.world.rot.z, 0x800);

    func_8002F8F0(&pthis->actor, NA_SE_IT_BOMBCHU_MOVE - SFX_FLAG);
}

void EnBomChu_WaitForKill(EnBomChu* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

/**
 * Transform coordinates from model space to world space, according to current orientation.
 * `posModel` is expected to already be at world scale (1/100 compared to model scale)
 */
void EnBomChu_ModelToWorld(EnBomChu* pthis, Vec3f* posModel, Vec3f* dest) {
    f32 x = posModel->x + pthis->visualJitter;

    dest->x = pthis->actor.world.pos.x + (pthis->axisLeft.x * x) + (pthis->axisUp.x * posModel->y) +
              (pthis->axisForwards.x * posModel->z);
    dest->y = pthis->actor.world.pos.y + (pthis->axisLeft.y * x) + (pthis->axisUp.y * posModel->y) +
              (pthis->axisForwards.y * posModel->z);
    dest->z = pthis->actor.world.pos.z + (pthis->axisLeft.z * x) + (pthis->axisUp.z * posModel->y) +
              (pthis->axisForwards.z * posModel->z);
}

void EnBomChu_SpawnRipples(EnBomChu* pthis, GlobalContext* globalCtx, f32 y) {
    Vec3f pos;

    pos.x = pthis->actor.world.pos.x;
    pos.y = y;
    pos.z = pthis->actor.world.pos.z;

    EffectSsGRipple_Spawn(globalCtx, &pos, 70, 500, 0);
    EffectSsGRipple_Spawn(globalCtx, &pos, 70, 500, 4);
    EffectSsGRipple_Spawn(globalCtx, &pos, 70, 500, 8);
}

void EnBomChu_Update(Actor* thisx, GlobalContext* globalCtx2) {
    static Vec3f blureP1Model = { 0.0f, 7.0f, -6.0f };
    static Vec3f blureP2LeftModel = { 12.0f, 0.0f, -5.0f };
    static Vec3f blureP2RightModel = { -12.0f, 0.0f, -5.0f };
    GlobalContext* globalCtx = globalCtx2;
    EnBomChu* pthis = (EnBomChu*)thisx;
    s16 yaw;
    f32 sin;
    f32 cos;
    f32 tempX;
    Vec3f blureP1;
    Vec3f blureP2;
    WaterBox* waterBox;
    f32 waterY;

    if (pthis->actor.floorBgId != BGCHECK_SCENE) {
        yaw = pthis->actor.shape.rot.y;
        func_800433A4(&globalCtx->colCtx, pthis->actor.floorBgId, &pthis->actor);

        if (yaw != pthis->actor.shape.rot.y) {
            yaw = pthis->actor.shape.rot.y - yaw;

            sin = Math_SinS(yaw);
            cos = Math_CosS(yaw);

            tempX = pthis->axisForwards.x;
            pthis->axisForwards.x = (pthis->axisForwards.z * sin) + (cos * tempX);
            pthis->axisForwards.z = (pthis->axisForwards.z * cos) - (sin * tempX);

            tempX = pthis->axisUp.x;
            pthis->axisUp.x = (pthis->axisUp.z * sin) + (cos * tempX);
            pthis->axisUp.z = (pthis->axisUp.z * cos) - (sin * tempX);

            tempX = pthis->axisLeft.x;
            pthis->axisLeft.x = (pthis->axisLeft.z * sin) + (cos * tempX);
            pthis->axisLeft.z = (pthis->axisLeft.z * cos) - (sin * tempX);
        }
    }

    pthis->actionFunc(pthis, globalCtx);
    func_8002D97C(&pthis->actor);

    pthis->collider.elements[0].dim.worldSphere.center.x = pthis->actor.world.pos.x;
    pthis->collider.elements[0].dim.worldSphere.center.y = pthis->actor.world.pos.y;
    pthis->collider.elements[0].dim.worldSphere.center.z = pthis->actor.world.pos.z;

    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    if (pthis->actionFunc != EnBomChu_WaitForRelease) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    Actor_SetFocus(&pthis->actor, 0.0f);

    if (pthis->actionFunc == EnBomChu_Move) {
        pthis->visualJitter =
            (5.0f + (Rand_ZeroOne() * 3.0f)) * Math_SinS(((Rand_ZeroOne() * (f32)0x200) + (f32)0x3000) * pthis->timer);

        EnBomChu_ModelToWorld(pthis, &blureP1Model, &blureP1);

        EnBomChu_ModelToWorld(pthis, &blureP2LeftModel, &blureP2);
        EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blure1Index), &blureP1, &blureP2);

        EnBomChu_ModelToWorld(pthis, &blureP2RightModel, &blureP2);
        EffectBlure_AddVertex((EffectBlure*)Effect_GetByIndex(pthis->blure2Index), &blureP1, &blureP2);

        waterY = pthis->actor.world.pos.y;

        if (WaterBox_GetSurface1(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                 &waterY, &waterBox)) {
            pthis->actor.yDistToWater = waterY - pthis->actor.world.pos.y;

            if (pthis->actor.yDistToWater < 0.0f) {
                if (pthis->actor.bgCheckFlags & 0x20) {
                    EnBomChu_SpawnRipples(pthis, globalCtx, waterY);
                }

                pthis->actor.bgCheckFlags &= ~0x20;
            } else {
                if (!(pthis->actor.bgCheckFlags & 0x20) && (pthis->timer != 120)) {
                    EnBomChu_SpawnRipples(pthis, globalCtx, waterY);
                } else {
                    EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 0.0f, 3.0f, 15.0f, 0.25f);
                }

                pthis->actor.bgCheckFlags |= 0x20;
            }
        } else {
            pthis->actor.bgCheckFlags &= ~0x20;
            pthis->actor.yDistToWater = BGCHECK_Y_MIN;
        }
    }
}

void EnBomChu_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnBomChu* pthis = (EnBomChu*)thisx;
    f32 colorIntensity;
    s32 blinkHalfPeriod;
    s32 blinkTime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bom_chu.c", 921);

    func_80093D18(globalCtx->state.gfxCtx);
    func_8002EBCC(&pthis->actor, globalCtx, 0);

    if (pthis->timer >= 40) {
        blinkTime = pthis->timer % 20;
        blinkHalfPeriod = 10;
    } else if (pthis->timer >= 10) {
        blinkTime = pthis->timer % 10;
        blinkHalfPeriod = 5;
    } else {
        blinkTime = pthis->timer & 1;
        blinkHalfPeriod = 1;
    }

    if (blinkTime > blinkHalfPeriod) {
        blinkTime = 2 * blinkHalfPeriod - blinkTime;
    }

    colorIntensity = blinkTime / (f32)blinkHalfPeriod;

    gDPSetEnvColor(POLY_OPA_DISP++, 9.0f + (colorIntensity * 209.0f), 9.0f + (colorIntensity * 34.0f),
                   35.0f + (colorIntensity * -35.0f), 255);
    Matrix_Translate(pthis->visualJitter * (1.0f / BOMBCHU_SCALE), 0.0f, 0.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bom_chu.c", 956),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gBombchuDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bom_chu.c", 961);
}

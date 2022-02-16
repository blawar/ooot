#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT18_BASKET_Z_BG_SPOT18_BASKET_C
#include "actor_common.h"
#include "z_bg_spot18_basket.h"
#include "objects/object_spot18_obj/object_spot18_obj.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/code_800EC960.h"
#include "def/code_800FD970.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS ACTOR_FLAG_4

void BgSpot18Basket_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Basket_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgSpot18Basket_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Basket_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot18Basket_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B7BCC(BgSpot18Basket* pthis, GlobalContext* globalCtx);
void func_808B7AEC(BgSpot18Basket* pthis);
void func_808B7B58(BgSpot18Basket* pthis);
void func_808B7BB0(BgSpot18Basket* pthis);
void func_808B7D38(BgSpot18Basket* pthis);
void func_808B7F74(BgSpot18Basket* pthis);
void func_808B818C(BgSpot18Basket* pthis);
void func_808B7AFC(BgSpot18Basket* pthis, GlobalContext* globalCtx);
void func_808B7B6C(BgSpot18Basket* pthis, GlobalContext* globalCtx);
void func_808B7D50(BgSpot18Basket* pthis, GlobalContext* globalCtx);
void func_808B7FC0(BgSpot18Basket* pthis, GlobalContext* globalCtx);
void func_808B81A0(BgSpot18Basket* pthis, GlobalContext* globalCtx);

static s16 D_808B85D0_40 = 0;


ActorInit Bg_Spot18_Basket_InitVars = {
    ACTOR_BG_SPOT18_BASKET,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT18_OBJ,
    sizeof(BgSpot18Basket),
    (ActorFunc)BgSpot18Basket_Init,
    (ActorFunc)BgSpot18Basket_Destroy,
    (ActorFunc)BgSpot18Basket_Update,
    (ActorFunc)BgSpot18Basket_Draw,
    (ActorFunc)BgSpot18Basket_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 0, { { 0, 2040, 0 }, 54 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000008, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 1, { { 0, 1400, 0 }, 13 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_JNTSPH,
    },
    2,
    sJntSphElementsInit,
};

static s16 D_808B85C8[] = { 0x8000, 0x2AAA, 0xD555, 0x0000 };

void func_808B7710(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Basket* pthis = (BgSpot18Basket*)thisx;

    Collider_InitJntSph(globalCtx, &pthis->colliderJntSph);
    Collider_SetJntSph(globalCtx, &pthis->colliderJntSph, &pthis->dyna.actor, &sJntSphInit, pthis->ColliderJntSphElements);
    pthis->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
}

void func_808B7770(BgSpot18Basket* pthis, GlobalContext* globalCtx, f32 arg2) {
    Vec3f acceleration;
    Vec3f velocity;
    Vec3f position;
    f32 cosValue;
    s32 i;
    f32 randomValue;
    f32 sinValue;
    s32 count;

    for (i = 0, count = 2; i != count; i++) {
        if (globalCtx) {}
        if (!(arg2 < Rand_ZeroOne())) {
            D_808B85D0_40 += 0x7530;

            sinValue = Math_SinS(D_808B85D0_40);
            cosValue = Math_CosS(D_808B85D0_40);

            randomValue = (Rand_ZeroOne() * 35.0f) + 35.0f;

            position.x = (randomValue * sinValue) + pthis->dyna.actor.world.pos.x;
            position.y = pthis->dyna.actor.world.pos.y + 10.0f;
            position.z = (randomValue * cosValue) + pthis->dyna.actor.world.pos.z;

            velocity.x = sinValue;
            velocity.y = 0.0f;
            velocity.z = cosValue;

            acceleration.x = 0.0f;
            acceleration.y = 0.5f;
            acceleration.z = 0.0f;

            func_800286CC(globalCtx, &position, &velocity, &acceleration, ((Rand_ZeroOne() * 16) + 80),
                          ((Rand_ZeroOne() * 30) + 80));
        }
    }
}

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

void BgSpot18Basket_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot18Basket* pthis = (BgSpot18Basket*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK3);
    func_808B7710(&pthis->dyna.actor, globalCtx);
    CollisionHeader_GetVirtual(&gGoronCityVaseCol, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    ActorShape_Init(&pthis->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 15.0f);
    pthis->dyna.actor.home.pos.y += 0.01f;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;

    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        func_808B7BB0(pthis);
        return;
    }

    func_808B7AEC(pthis);
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_SPOT18_FUTA,
                       pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z,
                       pthis->dyna.actor.shape.rot.x, pthis->dyna.actor.shape.rot.y + 0x1555,
                       pthis->dyna.actor.shape.rot.z, -1);

    if (pthis->dyna.actor.child == NULL) {
        osSyncPrintf(VT_FGCOL(RED));
        osSyncPrintf("Ｅｒｒｏｒ : 変化壷蓋発生失敗(%s %d)\n", "../z_bg_spot18_basket.c", 351);
        osSyncPrintf(VT_RST);
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgSpot18Basket_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Basket* pthis = (BgSpot18Basket*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyJntSph(globalCtx, &pthis->colliderJntSph);
}

void func_808B7AEC(BgSpot18Basket* pthis) {
    pthis->actionFunc = func_808B7AFC;
}

void func_808B7AFC(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params >> 8) & 0x3F)) {
        OnePointCutscene_Init(globalCtx, 4220, 80, &pthis->dyna.actor, MAIN_CAM);
        func_808B7B58(pthis);
    }
}

void func_808B7B58(BgSpot18Basket* pthis) {
    pthis->actionFunc = func_808B7B6C;
    pthis->unk_216 = 0;
}

void func_808B7B6C(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_216 > 20) {
        func_808B7BB0(pthis);
        pthis->dyna.actor.child->parent = NULL;
        pthis->dyna.actor.child = NULL;
    }
}

void func_808B7BB0(BgSpot18Basket* pthis) {
    pthis->actionFunc = func_808B7BCC;
    pthis->unk_210 = pthis->unk_20C = 0;
}

void func_808B7BCC(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    f32 positionDiff;
    Actor* colliderBaseAc;

    Math_StepToS(&pthis->unk_210, 0x1F4, 0x1E);

    pthis->dyna.actor.shape.rot.y += pthis->unk_210;

    Math_StepToF(&pthis->unk_208, 50.0f, 1.5f);
    Math_StepToS(&pthis->unk_20C, 400, 15);

    pthis->unk_20E += pthis->unk_20C;

    pthis->dyna.actor.world.pos.x = (Math_SinS(pthis->unk_20E) * pthis->unk_208) + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = (Math_CosS(pthis->unk_20E) * pthis->unk_208) + pthis->dyna.actor.home.pos.z;

    if (pthis->colliderJntSph.base.acFlags & AC_HIT) {
        colliderBaseAc = pthis->colliderJntSph.base.ac;

        if (colliderBaseAc != NULL) {
            positionDiff = colliderBaseAc->world.pos.y - pthis->dyna.actor.world.pos.y;

            if (positionDiff > 120.0f && positionDiff < 200.0f) {
                if (Math3D_Dist2DSq(colliderBaseAc->world.pos.z, pthis->colliderJntSph.base.ac->world.pos.x,
                                    pthis->dyna.actor.world.pos.z, pthis->dyna.actor.world.pos.x) < SQ(32.0f)) {
                    OnePointCutscene_Init(globalCtx, 4210, 240, &pthis->dyna.actor, MAIN_CAM);
                    func_808B7D38(pthis);
                    func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
                }
            }
        }
    }
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
}

void func_808B7D38(BgSpot18Basket* pthis) {
    pthis->actionFunc = func_808B7D50;
    pthis->unk_216 = 0;
    pthis->unk_214 = 0;
}

void func_808B7D50(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    f32 tempValue2;
    f32 tempValue;

    if (pthis->unk_216 > 120) {
        Math_StepToS(&pthis->unk_210, 0x3E8, 0x32);
    } else {
        Math_StepToS(&pthis->unk_210, 0xBB8, 0x64);
    }

    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.shape.rot.y + pthis->unk_210;

    if (pthis->unk_216 < 70) {
        Math_StepToF(&pthis->unk_208, 100.0f, 2.0f);
    } else {
        Math_StepToF(&pthis->unk_208, 0.0f, 2.0f);
    }

    Math_StepToS(&pthis->unk_20C, 1000, 20);

    pthis->unk_20E += pthis->unk_20C;

    pthis->dyna.actor.world.pos.x = (Math_SinS(pthis->unk_20E) * pthis->unk_208) + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = (Math_CosS(pthis->unk_20E) * pthis->unk_208) + pthis->dyna.actor.home.pos.z;

    pthis->unk_212 += 0xBB8;

    Math_StepToS(&pthis->unk_214, 0x5DC, 0x1E);

    pthis->dyna.actor.shape.rot.x = Math_CosS(pthis->unk_212) * pthis->unk_214;
    pthis->dyna.actor.shape.rot.z = -Math_SinS(pthis->unk_212) * pthis->unk_214;

    if (pthis->unk_216 > 140) {
        func_808B7F74(pthis);
    }

    if (pthis->unk_216 < 80) {
        func_808B7770(pthis, globalCtx, 1.0f);
    } else {
        func_808B7770(pthis, globalCtx, 0.8f);
    }

    tempValue2 = (pthis->unk_210 - 500) * 0.0006f;

    tempValue = CLAMP(tempValue2, 0.0f, 1.5f);

    func_800F436C(&pthis->dyna.actor.projectedPos, NA_SE_EV_WALL_MOVE_SP - SFX_FLAG, tempValue);
}

void func_808B7F74(BgSpot18Basket* pthis) {
    s16 shapeRotY;

    shapeRotY = pthis->dyna.actor.shape.rot.y;
    pthis->actionFunc = func_808B7FC0;

    if ((shapeRotY < -0x2E93) || (shapeRotY >= 0x7C19)) {
        pthis->unk_218 = 2;
    } else if (shapeRotY < 0x26C2) {
        pthis->unk_218 = 1;
    } else {
        pthis->unk_218 = 0;
    }

    pthis->unk_216 = 0;
}

void func_808B7FC0(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 tempUnk214;
    f32 tempUnk210;
    s16 arrayValue;
    f32 clampedTempUnk210;

    pthis->unk_212 += 0xBB8;

    if (pthis->unk_216 >= 13) {
        tempUnk214 = Math_StepToS(&pthis->unk_214, 0, 55);
    } else {
        tempUnk214 = 0;
    }

    pthis->dyna.actor.shape.rot.x = Math_CosS(pthis->unk_212) * pthis->unk_214;
    pthis->dyna.actor.shape.rot.z = -Math_SinS(pthis->unk_212) * pthis->unk_214;

    Math_StepToS(&pthis->unk_210, 0x1F4, 0xA);
    pthis->dyna.actor.shape.rot.y += pthis->unk_210;

    if (tempUnk214 != 0) {
        arrayValue = D_808B85C8[pthis->unk_218];

        if ((s16)(pthis->dyna.actor.shape.rot.y - arrayValue) >= 0) {
            pthis->dyna.actor.shape.rot.y = arrayValue;

            func_808B818C(pthis);
            func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        }
    }

    if (pthis->unk_216 < 30) {
        func_808B7770(pthis, globalCtx, 0.5f);
    } else {
        func_808B7770(pthis, globalCtx, 0.3f);
    }

    tempUnk210 = (pthis->unk_210 - 500) * 0.0006f;

    clampedTempUnk210 = CLAMP(tempUnk210, 0.0f, 1.5f);

    func_800F436C(&pthis->dyna.actor.projectedPos, NA_SE_EV_WALL_MOVE_SP - SFX_FLAG, clampedTempUnk210);
}

void func_808B818C(BgSpot18Basket* pthis) {
    pthis->actionFunc = func_808B81A0;
    pthis->unk_216 = 0;
}

static s16 D_808B85E4[] = { -0x0FA0, 0x0320, 0x0FA0 };

void func_808B81A0(BgSpot18Basket* pthis, GlobalContext* globalCtx) {
    s32 i;
    Actor* actor = &pthis->dyna.actor;
    Vec3f tempVector;
    EnItem00* collectible;

    if (pthis->unk_216 == 1) {
        tempVector.x = actor->world.pos.x;
        tempVector.y = actor->world.pos.y + 170.0f;
        tempVector.z = actor->world.pos.z;

        if (pthis->unk_218 == 0) {
            for (i = 0; i < ARRAY_COUNT(D_808B85E4); i++) {
                collectible = Item_DropCollectible(globalCtx, &tempVector, ITEM00_BOMBS_A);
                if (collectible != NULL) {
                    collectible->actor.velocity.y = 11.0f;
                    collectible->actor.world.rot.y = D_808B85E4[i];
                }
            }
        } else if (pthis->unk_218 == 1) {
            for (i = 0; i < ARRAY_COUNT(D_808B85E4); i++) {
                collectible = Item_DropCollectible(globalCtx, &tempVector, ITEM00_RUPEE_GREEN);
                if (collectible != NULL) {
                    collectible->actor.velocity.y = 11.0f;
                    collectible->actor.world.rot.y = D_808B85E4[i];
                }
            }
        } else if (pthis->unk_218 == 2) {
            if ((pthis->unk_21A != 0) || Flags_GetCollectible(globalCtx, (actor->params & 0x3F))) {
                collectible = Item_DropCollectible(globalCtx, &tempVector, ITEM00_RUPEE_PURPLE);
                if (collectible != NULL) {
                    collectible->actor.velocity.y = 11.0f;
                    collectible->actor.world.rot.y = D_808B85E4[1];
                }
            } else {
                collectible =
                    Item_DropCollectible(globalCtx, &tempVector, ((actor->params & 0x3F) << 8) | ITEM00_HEART_PIECE);
                if (collectible != NULL) {
                    collectible->actor.velocity.y = 11.0f;
                    collectible->actor.world.rot.y = D_808B85E4[1];
                    pthis->unk_21A = 1;
                }
            }

            collectible = Item_DropCollectible(globalCtx, &tempVector, ITEM00_RUPEE_RED);
            if (collectible != NULL) {
                collectible->actor.velocity.y = 11.0f;
                collectible->actor.world.rot.y = D_808B85E4[0];
            }

            collectible = Item_DropCollectible(globalCtx, &tempVector, ITEM00_RUPEE_BLUE);
            if (collectible != NULL) {
                collectible->actor.velocity.y = 11.0f;
                collectible->actor.world.rot.y = D_808B85E4[2];
            }
        }
    } else if (pthis->unk_216 == 2) {
        if (pthis->unk_218 == 2) {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        } else {
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        }
    } else if (pthis->unk_216 == 200) {
        func_808B7BB0(pthis);
    }
}

void BgSpot18Basket_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot18Basket* pthis = (BgSpot18Basket*)thisx;
    s32 bgId;

    pthis->unk_216++;
    pthis->actionFunc(pthis, globalCtx);
    pthis->dyna.actor.floorHeight = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly, &bgId,
                                                               &pthis->dyna.actor, &pthis->dyna.actor.world.pos);
    if (pthis->actionFunc != func_808B7AFC) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
        if (pthis->actionFunc != func_808B7B6C) {
            pthis->colliderJntSph.base.acFlags &= ~AC_HIT;
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
        }
    }
}

void BgSpot18Basket_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot18Basket* pthis = (BgSpot18Basket*)thisx;

    Collider_UpdateSpheres(0, &pthis->colliderJntSph);
    Collider_UpdateSpheres(1, &pthis->colliderJntSph);
    Gfx_DrawDListOpa(globalCtx, gGoronCityVaseDL);
}

void BgSpot18Basket_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_808B85D0_40 = 0;

    Bg_Spot18_Basket_InitVars = {
        ACTOR_BG_SPOT18_BASKET,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_SPOT18_OBJ,
        sizeof(BgSpot18Basket),
        (ActorFunc)BgSpot18Basket_Init,
        (ActorFunc)BgSpot18Basket_Destroy,
        (ActorFunc)BgSpot18Basket_Update,
        (ActorFunc)BgSpot18Basket_Draw,
        (ActorFunc)BgSpot18Basket_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_PLAYER,
            OC2_TYPE_2,
            COLSHAPE_JNTSPH,
        },
        2,
        sJntSphElementsInit,
    };

}

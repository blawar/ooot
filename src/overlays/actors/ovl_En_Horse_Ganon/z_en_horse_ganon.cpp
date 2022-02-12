#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_GANON_Z_EN_HORSE_GANON_C
#include "actor_common.h"
/*
 * File: z_en_horse_ganon.c
 * Overlay: ovl_En_Horse_Ganon
 * Description: Ganondorf's Horse
 */

#include "z_en_horse_ganon.h"
#include "objects/object_horse_ganon/object_horse_ganon.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin.h"
#include "def/z_skin_awb.h"

#define FLAGS ACTOR_FLAG_4

typedef struct {
    /* 0x0 */ Vec3s unk_0;
    /* 0x6 */ u8 unk_6;
} unk_D_80A69248; // size = 0x8

void EnHorseGanon_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGanon_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGanon_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorseGanon_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A68AC4(EnHorseGanon* pthis);
void func_80A68AF0(EnHorseGanon* pthis, GlobalContext* globalCtx);
void func_80A68DB0(EnHorseGanon* pthis, GlobalContext* globalCtx);

ActorInit En_Horse_Ganon_InitVars = {
    ACTOR_EN_HORSE_GANON,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_GANON,
    sizeof(EnHorseGanon),
    (ActorFunc)EnHorseGanon_Init,
    (ActorFunc)EnHorseGanon_Destroy,
    (ActorFunc)EnHorseGanon_Update,
    (ActorFunc)EnHorseGanon_Draw,
};

static AnimationHeader* sAnimations[] = {
    &gHorseGanonIdleAnim,     &gHorseGanonWhinnyAnim,    &gHorseGanonWalkingAnim,
    &gHorseGanonTrottingAnim, &gHorseGanonGallopingAnim, &gHorseGanonRearingAnim,
};

static f32 splaySpeeds[] = { 2.0f / 3.0f, 2.0f / 3.0f, 1.0f, 1.0f, 1.0f, 2.0f / 3.0f };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 40, 100, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 13, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 10, 35, 100, MASS_HEAVY };

static unk_D_80A69248 D_80A69248[] = {
    { 0x09B8, 0x0126, 0x0E2C, 0x07 }, { 0x0C11, 0x017A, 0x1269, 0x07 }, { 0x064E, 0xFEFB, 0x1DAC, 0x07 },
    { 0x02F2, 0xFF45, 0x244F, 0x07 }, { 0xF96E, 0xFE0C, 0x3122, 0x07 }, { 0xF328, 0xFE0C, 0x32D5, 0x07 },
    { 0xEBEA, 0xFE5F, 0x2D6E, 0x07 }, { 0xE95E, 0xFE27, 0x2565, 0x07 }, { 0xE593, 0xFE0C, 0x20AC, 0x07 },
    { 0xE625, 0xFE77, 0x1B07, 0x07 }, { 0xEBB7, 0x007C, 0x1539, 0x07 }, { 0xF466, 0x0002, 0x11B9, 0x07 },
    { 0xF47B, 0xFFDD, 0x11AF, 0x07 }, { 0xF88D, 0xFFD1, 0x0BA2, 0x07 },
};

static s32 D_80A692B8[] = { 0, 16 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_STOP),
};

static EnHorseGanonActionFunc sActionFuncs[] = { func_80A68AF0, func_80A68DB0 };

void func_80A68660(unk_D_80A69248* data, s32 index, Vec3f* vec) {
    vec->x = data[index].unk_0.x;
    vec->y = data[index].unk_0.y;
    vec->z = data[index].unk_0.z;
}

void func_80A686A8(EnHorseGanon* pthis, GlobalContext* globalCtx) {
    Vec3f* tempPos;
    Vec3f vec;
    s16 y;

    func_80A68660(D_80A69248, pthis->unk_1EC, &vec);
    if (Math3D_Vec3f_DistXYZ(&vec, &pthis->actor.world.pos) <= 400.0f) {
        pthis->unk_1EC += 1;
        if (pthis->unk_1EC >= 14) {
            pthis->unk_1EC = 0;
            func_80A68660(D_80A69248, 0, &vec);
        }
    }

    tempPos = &pthis->actor.world.pos;
    y = Math_Vec3f_Yaw(tempPos, &vec) - pthis->actor.world.rot.y;
    if (y >= 301) {
        pthis->actor.world.rot.y += 300;
    } else if (y < -300) {
        pthis->actor.world.rot.y -= 300;
    } else {
        pthis->actor.world.rot.y += y;
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) <= 300.0f) {
        if (pthis->actor.speedXZ < 12.0f) {
            pthis->actor.speedXZ += 1.0f;
        } else {
            pthis->actor.speedXZ -= 1.0f;
        }
    } else if (pthis->actor.speedXZ < D_80A69248[pthis->unk_1EC].unk_6) {
        pthis->actor.speedXZ += 0.5f;
    } else {
        pthis->actor.speedXZ -= 0.5f;
    }
}

void func_80A68870(EnHorseGanon* pthis) {
    if ((pthis->skin.skelAnime.curFrame > D_80A692B8[pthis->soundCount]) &&
        (pthis->soundCount != 0 || !(pthis->skin.skelAnime.curFrame > D_80A692B8[1]))) {
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_WALK, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);

        pthis->soundCount++;
        if (pthis->soundCount >= 2) {
            pthis->soundCount = 0;
        }
    }
}

void EnHorseGanon_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseGanon* pthis = (EnHorseGanon*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.0115f);

    pthis->actor.gravity = -3.5f;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->action = 0;
    pthis->actor.focus.pos.y += 70.0f;
    func_800A663C(globalCtx, &pthis->skin, &gHorseGanonSkel, &gHorseGanonIdleAnim);
    pthis->currentAnimation = 0;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimations[0]);

    Collider_InitCylinder(globalCtx, &pthis->colliderBody);
    Collider_SetCylinder(globalCtx, &pthis->colliderBody, &pthis->actor, &sCylinderInit);
    Collider_InitJntSph(globalCtx, &pthis->colliderHead);
    Collider_SetJntSph(globalCtx, &pthis->colliderHead, &pthis->actor, &sJntSphInit, pthis->headElements);

    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, 0, &sColChkInfoInit);
    func_80A68AC4(pthis);
}

void EnHorseGanon_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseGanon* pthis = (EnHorseGanon*)thisx;

    func_800A6888(globalCtx, &pthis->skin);
    Collider_DestroyCylinder(globalCtx, &pthis->colliderBody);
    Collider_DestroyJntSph(globalCtx, &pthis->colliderHead);
}

void func_80A68AC4(EnHorseGanon* pthis) {
    pthis->action = 0;
    Animation_PlayLoop(&pthis->skin.skelAnime, sAnimations[4]);
}

void func_80A68AF0(EnHorseGanon* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    SkelAnime_Update(&pthis->skin.skelAnime);
}

void func_80A68B20(EnHorseGanon* pthis) {
    s32 animationChanged;
    f32 sp30;

    animationChanged = 0;
    pthis->action = 1;
    if (pthis->actor.speedXZ <= 3.0f) {
        if (pthis->currentAnimation != 2) {
            animationChanged = 1;
        }
        pthis->currentAnimation = 2;
    } else if (pthis->actor.speedXZ <= 6.0f) {
        if (pthis->currentAnimation != 3) {
            animationChanged = 1;
        }
        pthis->currentAnimation = 3;
    } else {
        if (pthis->currentAnimation != 4) {
            animationChanged = 1;
        }
        pthis->currentAnimation = 4;
    }

    if (pthis->currentAnimation == 2) {
        sp30 = pthis->actor.speedXZ / 3.0f;
    } else if (pthis->currentAnimation == 3) {
        sp30 = pthis->actor.speedXZ / 5.0f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    } else if (pthis->currentAnimation == 4) {
        sp30 = pthis->actor.speedXZ / 7.0f;
        Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    } else {
        sp30 = 1.0f;
    }

    if (animationChanged == 1) {
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->currentAnimation],
                         splaySpeeds[pthis->currentAnimation] * sp30 * 1.5f, 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->currentAnimation]), ANIMMODE_ONCE, -3.0f);
    } else {
        Animation_Change(&pthis->skin.skelAnime, sAnimations[pthis->currentAnimation],
                         splaySpeeds[pthis->currentAnimation] * sp30 * 1.5f, 0.0f,
                         Animation_GetLastFrame(sAnimations[pthis->currentAnimation]), ANIMMODE_ONCE, 0.0f);
    }
}

void func_80A68DB0(EnHorseGanon* pthis, GlobalContext* globalCtx) {
    if (pthis->currentAnimation == 2) {
        func_80A68870(pthis);
    }

    func_80A686A8(pthis, globalCtx);

    if (SkelAnime_Update(&pthis->skin.skelAnime) != 0) {
        func_80A68B20(pthis);
    }
}

void func_80A68E14(EnHorseGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    CollisionPoly* col;
    f32 temp_ret;
    Vec3f v;
    s32 temp1;

    v.x = Math_SinS(pthis->actor.shape.rot.y) * 30.0f + pthis->actor.world.pos.x;
    v.y = pthis->actor.world.pos.y + 60.0f;
    v.z = Math_CosS(pthis->actor.shape.rot.y) * 30.0f + pthis->actor.world.pos.z;

    temp_ret = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &col, &temp1, &v);

    pthis->unk_1F4 = temp_ret;
    pthis->actor.shape.rot.x = (0x8000 / M_PI) * Math_FAtan2F(pthis->actor.world.pos.y - temp_ret, 30.0f);
}

void EnHorseGanon_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseGanon* pthis = (EnHorseGanon*)thisx;
    s32 pad;

    sActionFuncs[pthis->action](pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 55.0f, 100.0f, 29);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    Collider_UpdateCylinder(&pthis->actor, &pthis->colliderBody);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderBody.base);
}

void func_80A68FA8(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
    Vec3f sp4C;
    Vec3f sp40;
    EnHorseGanon* pthis = (EnHorseGanon*)thisx;
    s32 index;

    for (index = 0; index < pthis->colliderHead.count; index++) {
        sp4C.x = pthis->colliderHead.elements[index].dim.modelSphere.center.x;
        sp4C.y = pthis->colliderHead.elements[index].dim.modelSphere.center.y;
        sp4C.z = pthis->colliderHead.elements[index].dim.modelSphere.center.z;

        func_800A6408(skin, pthis->colliderHead.elements[index].dim.limb, &sp4C, &sp40);

        pthis->colliderHead.elements[index].dim.worldSphere.center.x = sp40.x;
        pthis->colliderHead.elements[index].dim.worldSphere.center.y = sp40.y;
        pthis->colliderHead.elements[index].dim.worldSphere.center.z = sp40.z;

        pthis->colliderHead.elements[index].dim.worldSphere.radius =
            pthis->colliderHead.elements[index].dim.modelSphere.radius * pthis->colliderHead.elements[index].dim.scale;
    }

    //! @bug see relevant comment in `EnHorse_SkinCallback1`
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderHead.base);
}

void EnHorseGanon_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseGanon* pthis = (EnHorseGanon*)thisx;

    func_80A68E14(pthis, globalCtx);
    func_80093D18(globalCtx->state.gfxCtx);
    func_800A6330(&pthis->actor, globalCtx, &pthis->skin, func_80A68FA8, 1);
}

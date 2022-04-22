#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_HORSE_ZELDA_Z_EN_HORSE_ZELDA_C
#include "actor_common.h"
/*
 * File: z_en_horse_zelda.c
 * Overlay: ovl_En_Horse_Zelda
 * Description: Zelda's Horse
 */

#include "z_en_horse_zelda.h"
#include "objects/object_horse_zelda/object_horse_zelda.h"
#include "def/audio_bank.h"
#include "def/math_float.h"
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

void EnHorseZelda_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHorseZelda_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnHorseZelda_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHorseZelda_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHorseZelda_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A6DCCC(EnHorseZelda* pthis, GlobalContext* globalCtx);
void func_80A6DDFC(EnHorseZelda* pthis, GlobalContext* globalCtx);
void func_80A6DC7C(EnHorseZelda* pthis);

ActorInit En_Horse_Zelda_InitVars = {
    ACTOR_EN_HORSE_ZELDA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HORSE_ZELDA,
    sizeof(EnHorseZelda),
    (ActorFunc)EnHorseZelda_Init,
    (ActorFunc)EnHorseZelda_Destroy,
    (ActorFunc)EnHorseZelda_Update,
    (ActorFunc)EnHorseZelda_Draw,
    (ActorFunc)EnHorseZelda_Reset,
};

static AnimationHeader* sAnimationHeaders[] = { &gHorseZeldaGallopingAnim };

static f32 splaySpeeds[] = { 2.0f / 3.0f };

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
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

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
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

static unknownStruct D_80A6E240[] = {
    { -1682, -500, 12578, 0x07 }, { -3288, -500, 13013, 0x07 }, { -5142, -417, 11630, 0x07 },
    { -5794, -473, 9573, 0x07 },  { -6765, -500, 8364, 0x07 },  { -6619, -393, 6919, 0x07 },
    { -5193, 124, 5433, 0x07 },   { -2970, 2, 4537, 0x07 },     { -2949, -35, 4527, 0x07 },
    { -1907, -47, 2978, 0x07 },   { 2488, 294, 3628, 0x07 },    { 3089, 378, 4713, 0x07 },
    { 1614, -261, 7596, 0x07 },   { 754, -187, 9295, 0x07 },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_STOP),
};

static EnHorseZeldaActionFunc sActionFuncs[] = {
    func_80A6DCCC,
    func_80A6DDFC,
};

void func_80A6D8D0(unknownStruct* data, s32 index, Vec3f* vec) {
    vec->x = data[index].unk_0.x;
    vec->y = data[index].unk_0.y;
    vec->z = data[index].unk_0.z;
}

void func_80A6D918(EnHorseZelda* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f sp28;
    s16 yawDiff;

    func_80A6D8D0(D_80A6E240, pthis->unk_1EC, &sp28);
    if (Math3D_Vec3f_DistXYZ(&sp28, &pthis->actor.world.pos) <= 400.0f) {
        pthis->unk_1EC++;
        if (pthis->unk_1EC >= 14) {
            pthis->unk_1EC = 0;
            func_80A6D8D0(D_80A6E240, 0, &sp28);
        }
    }
    yawDiff = Math_Vec3f_Yaw(&pthis->actor.world.pos, &sp28) - pthis->actor.world.rot.y;
    if (yawDiff >= 0x12D) {
        pthis->actor.world.rot.y += 0x12C;
    } else if (yawDiff < -0x12C) {
        pthis->actor.world.rot.y -= 0x12C;
    } else {
        pthis->actor.world.rot.y += yawDiff;
    }
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    if (Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) <= 300.0f) {
        if (pthis->actor.speedXZ < 12.0f) {
            pthis->actor.speedXZ += 1.0f;
        } else {
            pthis->actor.speedXZ -= 1.0f;
        }
    } else if (pthis->actor.speedXZ < D_80A6E240[pthis->unk_1EC].unk_6) {
        pthis->actor.speedXZ += 0.5f;
    } else {
        pthis->actor.speedXZ -= 0.5f;
    }
}

void EnHorseZelda_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseZelda* pthis = (EnHorseZelda*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Actor_SetScale(&pthis->actor, 0.0115f);
    pthis->actor.gravity = -3.5f;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawHorse, 20.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->action = 0;
    pthis->actor.focus.pos.y += 70.0f;
    func_800A663C(globalCtx, &pthis->skin, &gHorseZeldaSkel, &gHorseZeldaGallopingAnim);
    pthis->animationIndex = 0;
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[0]);
    Collider_InitCylinder(globalCtx, &pthis->colliderCylinder);
    Collider_SetCylinderType1(globalCtx, &pthis->colliderCylinder, &pthis->actor, &sCylinderInit);
    Collider_InitJntSph(globalCtx, &pthis->colliderSphere);
    Collider_SetJntSph(globalCtx, &pthis->colliderSphere, &pthis->actor, &sJntSphInit, &pthis->colliderSphereItem);
    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);
    pthis->animationIndex = 0;
    func_80A6DC7C(pthis);
}

void EnHorseZelda_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseZelda* pthis = (EnHorseZelda*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinder);
    Collider_DestroyJntSph(globalCtx, &pthis->colliderSphere);
    func_800A6888(globalCtx, &pthis->skin);
}

void func_80A6DC7C(EnHorseZelda* pthis) {
    pthis->action = 0;
    pthis->animationIndex++;
    if (pthis->animationIndex > 0) {
        pthis->animationIndex = 0;
    }
    Animation_PlayOnce(&pthis->skin.skelAnime, sAnimationHeaders[pthis->animationIndex]);
}

void func_80A6DCCC(EnHorseZelda* pthis, GlobalContext* globalCtx) {
    pthis->actor.speedXZ = 0.0f;
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        func_80A6DC7C(pthis);
    }
}

void func_80A6DD14(EnHorseZelda* pthis) {
    f32 sp34;

    pthis->action = 1;
    pthis->animationIndex = 0;
    sp34 = pthis->actor.speedXZ / 6.0f;
    Audio_PlaySoundGeneral(NA_SE_EV_HORSE_RUN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
    Animation_Change(&pthis->skin.skelAnime, sAnimationHeaders[pthis->animationIndex],
                     splaySpeeds[pthis->animationIndex] * sp34 * 1.5f, 0.0f,
                     Animation_GetLastFrame(sAnimationHeaders[pthis->animationIndex]), ANIMMODE_ONCE, 0.0f);
}

void func_80A6DDFC(EnHorseZelda* pthis, GlobalContext* globalCtx) {
    func_80A6D918(pthis, globalCtx);
    if (SkelAnime_Update(&pthis->skin.skelAnime)) {
        func_80A6DD14(pthis);
    }
}

void func_80A6DE38(EnHorseZelda* pthis, GlobalContext* globalCtx) {
    s32 pad;
    CollisionPoly* poly;
    s32 pad2;
    Vec3f pos;
    s32 bgId;

    pos.x = (Math_SinS(pthis->actor.shape.rot.y) * 30.0f) + pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + 60.0f;
    pos.z = (Math_CosS(pthis->actor.shape.rot.y) * 30.0f) + pthis->actor.world.pos.z;
    pthis->unk_1F4 = BgCheck_EntityRaycastFloor3(&globalCtx->colCtx, &poly, &bgId, &pos);
    pthis->actor.shape.rot.x = Math_FAtan2F(pthis->actor.world.pos.y - pthis->unk_1F4, 30.0f) * (0x8000 / M_PI);
}

void EnHorseZelda_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseZelda* pthis = (EnHorseZelda*)thisx;
    s32 pad;

    sActionFuncs[pthis->action](pthis, globalCtx);
    pthis->actor.speedXZ = 0.0f;
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 55.0f, 100.0f, 0x1D);
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCylinder);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
}

void func_80A6DFD4(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
    Vec3f sp4C;
    Vec3f sp40;
    EnHorseZelda* pthis = (EnHorseZelda*)thisx;
    s32 i;

    for (i = 0; i < pthis->colliderSphere.count; i++) {
        sp4C.x = pthis->colliderSphere.elements[i].dim.modelSphere.center.x;
        sp4C.y = pthis->colliderSphere.elements[i].dim.modelSphere.center.y;
        sp4C.z = pthis->colliderSphere.elements[i].dim.modelSphere.center.z;

        func_800A6408(skin, pthis->colliderSphere.elements[i].dim.limb, &sp4C, &sp40);

        pthis->colliderSphere.elements[i].dim.worldSphere.center.x = sp40.x;
        pthis->colliderSphere.elements[i].dim.worldSphere.center.y = sp40.y;
        pthis->colliderSphere.elements[i].dim.worldSphere.center.z = sp40.z;

        pthis->colliderSphere.elements[i].dim.worldSphere.radius =
            pthis->colliderSphere.elements[i].dim.modelSphere.radius * pthis->colliderSphere.elements[i].dim.scale;
    }

    //! @bug see relevant comment in `EnHorse_SkinCallback1`
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSphere.base);
}

void EnHorseZelda_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnHorseZelda* pthis = (EnHorseZelda*)thisx;

    func_80A6DE38(pthis, globalCtx);
    func_80093D18(globalCtx->state.gfxCtx);
    func_800A6330(&pthis->actor, globalCtx, &pthis->skin, func_80A6DFD4, 1);
}

void EnHorseZelda_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Horse_Zelda_InitVars = {
        ACTOR_EN_HORSE_ZELDA,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HORSE_ZELDA,
        sizeof(EnHorseZelda),
        (ActorFunc)EnHorseZelda_Init,
        (ActorFunc)EnHorseZelda_Destroy,
        (ActorFunc)EnHorseZelda_Update,
        (ActorFunc)EnHorseZelda_Draw,
        (ActorFunc)EnHorseZelda_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
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

    sJntSphInit = {
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

    sColChkInfoInit = { 10, 35, 100, MASS_HEAVY };

}

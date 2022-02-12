#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ANUBICE_FIRE_Z_EN_ANUBICE_FIRE_C
#include "actor_common.h"
/*
 * File: z_en_anubice_fire.c
 * Overlay: ovl_En_Anubice_Fire
 * Description: Anubis Fire Attack
 */

#include "z_en_anubice_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_anubice/object_anubice.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void EnAnubiceFire_Init(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceFire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceFire_Update(Actor* thisx, GlobalContext* globalCtx);
void EnAnubiceFire_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809B26EC(EnAnubiceFire* pthis, GlobalContext* globalCtx);
void func_809B27D8(EnAnubiceFire* pthis, GlobalContext* globalCtx);
void func_809B2B48(EnAnubiceFire* pthis, GlobalContext* globalCtx);

ActorInit En_Anubice_Fire_InitVars = {
    ACTOR_EN_ANUBICE_FIRE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_ANUBICE,
    sizeof(EnAnubiceFire),
    (ActorFunc)EnAnubiceFire_Init,
    (ActorFunc)EnAnubiceFire_Destroy,
    (ActorFunc)EnAnubiceFire_Update,
    (ActorFunc)EnAnubiceFire_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 0, 0, 0, { 0, 0, 0 } },
};

void EnAnubiceFire_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceFire* pthis = (EnAnubiceFire*)thisx;
    s32 i;

    Collider_InitCylinder(globalCtx, &pthis->cylinder);
    Collider_SetCylinder(globalCtx, &pthis->cylinder, &pthis->actor, &sCylinderInit);

    pthis->unk_15A = 30;
    pthis->unk_154 = 2.0f;
    pthis->scale = 0.0f;

    for (i = 0; i < 6; i++) {
        pthis->unk_160[i] = pthis->actor.world.pos;
    }

    pthis->unk_15E = 0;
    pthis->actionFunc = func_809B26EC;
}

void EnAnubiceFire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceFire* pthis = (EnAnubiceFire*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->cylinder);
}

void func_809B26EC(EnAnubiceFire* pthis, GlobalContext* globalCtx) {
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };

    Matrix_Push();
    Matrix_RotateY(BINANG_TO_RAD(pthis->actor.world.rot.y), MTXMODE_NEW);
    Matrix_RotateX(BINANG_TO_RAD(pthis->actor.world.rot.x), MTXMODE_APPLY);
    velocity.z = 15.0f;
    Matrix_MultVec3f(&velocity, &pthis->actor.velocity);
    Matrix_Pop();

    pthis->actionFunc = func_809B27D8;
    pthis->actor.world.rot.x = pthis->actor.world.rot.y = pthis->actor.world.rot.z = 0;
}

void func_809B27D8(EnAnubiceFire* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Color_RGBA8 primColor = { 255, 255, 0, 255 };
    Color_RGBA8 envColor = { 255, 0, 0, 255 };
    Vec3f sp84 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp78 = { 0.0f, 0.0f, 0.0f };

    pthis->actor.world.rot.z += 5000;
    if (pthis->unk_15A == 0) {
        pthis->unk_154 = 0.0f;
    }

    Math_ApproachF(&pthis->scale, pthis->unk_154, 0.2f, 0.4f);
    if ((pthis->unk_15A == 0) && (pthis->scale < 0.1f)) {
        Actor_Kill(&pthis->actor);
    } else if ((pthis->actor.params == 0) && (pthis->cylinder.base.atFlags & 4)) {
        if (Player_HasMirrorShieldEquipped(globalCtx)) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SHIELD_REFLECT_SW);
            pthis->cylinder.base.atFlags &= 0xFFE9;
            pthis->cylinder.base.atFlags |= 8;
            pthis->cylinder.info.toucher.dmgFlags = 2;
            pthis->unk_15A = 30;
            pthis->actor.params = 1;
            pthis->actor.velocity.x *= -1.0f;
            pthis->actor.velocity.y *= -0.5f;
            pthis->actor.velocity.z *= -1.0f;
        } else {
            pthis->unk_15A = 0;
            EffectSsBomb2_SpawnLayered(globalCtx, &pthis->actor.world.pos, &sp78, &sp84, 10, 5);
            pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = 0.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_ANUBIS_FIREBOMB);
            pthis->actionFunc = func_809B2B48;
        }
    } else if (!(pthis->scale < .4f)) {
        f32 scale = 1000.0f;
        f32 life = 10.0f;
        s32 i;

        for (i = 0; i < 10; i++) {
            pos.x = pthis->actor.world.pos.x + (Rand_ZeroOne() - 0.5f) * (pthis->scale * 20.0f);
            pos.y = pthis->actor.world.pos.y + (Rand_ZeroOne() - 0.5f) * (pthis->scale * 20.0f);
            pos.z = pthis->actor.world.pos.z;
            EffectSsKiraKira_SpawnDispersed(globalCtx, &pos, &velocity, &accel, &primColor, &envColor, scale, life);
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_ANUBIS_FIRE - SFX_FLAG);
    }
}

void func_809B2B48(EnAnubiceFire* pthis, GlobalContext* globalCtx) {
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;
    Color_RGBA8 primColor = { 255, 255, 0, 255 };
    Color_RGBA8 envColor = { 255, 0, 0, 255 };
    s32 pad;
    s32 i;

    if (pthis->unk_15C == 0) {
        for (i = 0; i < 20; i++) {
            pos.x = pthis->actor.world.pos.x;
            pos.y = pthis->actor.world.pos.y;
            pos.z = pthis->actor.world.pos.z;
            accel.x = Rand_CenteredFloat(8.0f);
            accel.y = Rand_CenteredFloat(2.0f);
            accel.z = Rand_CenteredFloat(8.0f);
            EffectSsKiraKira_SpawnDispersed(globalCtx, &pos, &velocity, &accel, &primColor, &envColor, 2000, 10);
        }

        pthis->unk_15C = 2;
        pthis->unk_15E++;
        if (pthis->unk_15E >= 6) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnAnubiceFire_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnAnubiceFire* pthis = (EnAnubiceFire*)thisx;
    s32 pad;
    s32 i;

    Actor_SetScale(&pthis->actor, pthis->scale);
    pthis->actionFunc(pthis, globalCtx);
    func_8002D7EC(&pthis->actor);
    pthis->unk_160[0] = pthis->actor.world.pos;

    if (1) {}

    for (i = 4; i >= 0; i--) {
        pthis->unk_160[i + 1] = pthis->unk_160[i];
    }

    if (pthis->unk_15A != 0) {
        pthis->unk_15A--;
    }

    if (pthis->unk_15C != 0) {
        pthis->unk_15C--;
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 5.0f, 5.0f, 10.0f, 0x1D);
    if (!(pthis->scale < 0.6f || pthis->actionFunc == func_809B2B48)) {
        pthis->cylinder.dim.radius = pthis->scale * 15.0f + 5.0f;
        pthis->cylinder.dim.height = pthis->scale * 15.0f + 5.0f;
        pthis->cylinder.dim.yShift = pthis->scale * -0.75f + -15.0f;

        if (pthis->unk_15A != 0) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->cylinder);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->cylinder.base);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->cylinder.base);
        }

        if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &pthis->actor.world.pos, 30.0f)) {
            pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = 0.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_ANUBIS_FIREBOMB);
            pthis->actionFunc = func_809B2B48;
        }
    }
}

void EnAnubiceFire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* D_809B3270[] = {
        gDust4Tex, gDust5Tex, gDust6Tex, gDust7Tex, gDust8Tex, gDust7Tex, gDust6Tex, gDust5Tex,
    };
    EnAnubiceFire* pthis = (EnAnubiceFire*)thisx;
    s32 pad[2];
    s32 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_anubice_fire.c", 503);
    func_80093D84(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 0, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    gDPPipeSync(POLY_XLU_DISP++);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_809B3270[0]));

    Matrix_Push();
    for (i = pthis->unk_15E; i < 6; ++i) {
        f32 scale = pthis->actor.scale.x - (i * 0.2f);

        if (scale < 0.0f) {
            scale = 0.0f;
        }

        if (scale >= 0.1f) {
            Matrix_Translate(pthis->unk_160[i].x, pthis->unk_160[i].y, pthis->unk_160[i].z, MTXMODE_NEW);
            Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_RotateZ(pthis->actor.world.rot.z + i * 1000.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_anubice_fire.c", 546),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(POLY_XLU_DISP++, gAnubiceFireAttackDL);
        }

        if (pthis->scale < 0.1f) {
            break;
        }
    }
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_anubice_fire.c", 556);
}

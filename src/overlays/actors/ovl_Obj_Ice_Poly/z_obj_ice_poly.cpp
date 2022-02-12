#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_ICE_POLY_Z_OBJ_ICE_POLY_C
#include "actor_common.h"
/*
 * File: z_obj_ice_poly.c
 * Overlay: ovl_Obj_Ice_Poly
 * Description: Ice / Frozen Actors
 */

#include "z_obj_ice_poly.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void ObjIcePoly_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjIcePoly_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjIcePoly_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjIcePoly_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjIcePoly_Idle(ObjIcePoly* pthis, GlobalContext* globalCtx);
void ObjIcePoly_Melt(ObjIcePoly* pthis, GlobalContext* globalCtx);

ActorInit Obj_Ice_Poly_InitVars = {
    ACTOR_OBJ_ICE_POLY,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjIcePoly),
    (ActorFunc)ObjIcePoly_Init,
    (ActorFunc)ObjIcePoly_Destroy,
    (ActorFunc)ObjIcePoly_Update,
    (ActorFunc)ObjIcePoly_Draw,
};

static ColliderCylinderInit sCylinderInitIce = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x02, 0x00 },
        { 0x00020800, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 50, 120, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderInitHard = {
    {
        COLTYPE_HARD,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x4E01F7F6, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 50, 120, 0, { 0, 0, 0 } },
};

static f32 sScale[] = { 0.5f, 1.0f, 1.5f };
static s16 sOffsetY[] = { -25, 0, -20 };
static Color_RGBA8 sColorWhite = { 250, 250, 250, 255 };
static Color_RGBA8 sColorGray = { 180, 180, 180, 255 };

void ObjIcePoly_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjIcePoly* pthis = (ObjIcePoly*)thisx;

    pthis->unk_151 = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    if (thisx->params < 0 || thisx->params >= 3) {
        Actor_Kill(thisx);
        return;
    }
    Actor_SetScale(thisx, sScale[thisx->params]);
    thisx->world.pos.y = sOffsetY[thisx->params] + thisx->home.pos.y;
    Collider_InitCylinder(globalCtx, &pthis->colliderIce);
    Collider_SetCylinder(globalCtx, &pthis->colliderIce, thisx, &sCylinderInitIce);
    Collider_InitCylinder(globalCtx, &pthis->colliderHard);
    Collider_SetCylinder(globalCtx, &pthis->colliderHard, thisx, &sCylinderInitHard);
    Collider_UpdateCylinder(thisx, &pthis->colliderIce);
    Collider_UpdateCylinder(thisx, &pthis->colliderHard);
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    pthis->alpha = 255;
    pthis->colliderIce.dim.radius *= thisx->scale.x;
    pthis->colliderIce.dim.height *= thisx->scale.y;
    pthis->colliderHard.dim.radius *= thisx->scale.x;
    pthis->colliderHard.dim.height *= thisx->scale.y;
    Actor_SetFocus(thisx, thisx->scale.y * 30.0f);
    pthis->actionFunc = ObjIcePoly_Idle;
}

void ObjIcePoly_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjIcePoly* pthis = (ObjIcePoly*)thisx;

    if ((pthis->actor.params >= 0) && (pthis->actor.params < 3)) {
        Collider_DestroyCylinder(globalCtx, &pthis->colliderIce);
        Collider_DestroyCylinder(globalCtx, &pthis->colliderHard);
    }
}

void ObjIcePoly_Idle(ObjIcePoly* pthis, GlobalContext* globalCtx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    s32 pad;
    Vec3f pos;

    if (pthis->colliderIce.base.acFlags & AC_HIT) {
        pthis->meltTimer = -pthis->colliderIce.info.acHitInfo->toucher.damage;
        pthis->actor.focus.rot.y = pthis->actor.yawTowardsPlayer;
        OnePointCutscene_Init(globalCtx, 5120, 40, &pthis->actor, MAIN_CAM);
        pthis->actionFunc = ObjIcePoly_Melt;
    } else if (pthis->actor.parent != NULL) {
        pthis->actor.parent->freezeTimer = 40;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderIce.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderIce.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderIce.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderHard.base);
    } else {
        Actor_Kill(&pthis->actor);
    }
    pos.x = pthis->actor.world.pos.x + pthis->actor.scale.x * (Rand_S16Offset(15, 15) * (Rand_ZeroOne() < 0.5f ? -1 : 1));
    pos.y = pthis->actor.world.pos.y + pthis->actor.scale.y * Rand_S16Offset(10, 90);
    pos.z = pthis->actor.world.pos.z + pthis->actor.scale.z * (Rand_S16Offset(15, 15) * (Rand_ZeroOne() < 0.5f ? -1 : 1));
    if ((globalCtx->gameplayFrames % 7) == 0) {
        EffectSsKiraKira_SpawnDispersed(globalCtx, &pos, &zeroVec, &zeroVec, &sColorWhite, &sColorGray, 2000, 5);
    }
}

void ObjIcePoly_Melt(ObjIcePoly* pthis, GlobalContext* globalCtx) {
    Vec3f accel;
    Vec3f vel;
    Vec3f pos;
    s32 i;

    accel.x = 0.0f;
    accel.y = pthis->actor.scale.y;
    accel.z = 0.0f;
    vel.x = 0.0f;
    vel.y = pthis->actor.scale.y;
    vel.z = 0.0f;

    for (i = 0; i < 2; i++) {
        pos.x =
            pthis->actor.world.pos.x + pthis->actor.scale.x * (Rand_S16Offset(20, 20) * (Rand_ZeroOne() < 0.5f ? -1 : 1));
        pos.y = pthis->actor.world.pos.y + pthis->actor.scale.y * Rand_ZeroOne() * 50.0f;
        pos.z =
            pthis->actor.world.pos.z + pthis->actor.scale.x * (Rand_S16Offset(20, 20) * (Rand_ZeroOne() < 0.5f ? -1 : 1));
        func_8002829C(globalCtx, &pos, &vel, &accel, &sColorWhite, &sColorGray,
                      Rand_S16Offset(0x15E, 0x64) * pthis->actor.scale.x, pthis->actor.scale.x * 20.0f);
    }
    if (pthis->meltTimer < 0) {
        if (pthis->actor.parent != NULL) {
            pthis->actor.parent->freezeTimer = 40;
        }
        pthis->meltTimer++;
        if (pthis->meltTimer == 0) {
            pthis->meltTimer = 40;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_ICE_MELT);
        }
    } else {
        if (pthis->meltTimer != 0) {
            pthis->meltTimer--;
        }
        pthis->actor.scale.y = sScale[pthis->actor.params] * (0.5f + (pthis->meltTimer * 0.0125f));
        pthis->alpha -= 6;
        if (pthis->meltTimer == 0) {
            Actor_Kill(&pthis->actor);
        }
    }
}

void ObjIcePoly_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjIcePoly* pthis = (ObjIcePoly*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void ObjIcePoly_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjIcePoly* pthis = (ObjIcePoly*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_ice_poly.c", 421);
    func_80093D84(globalCtx->state.gfxCtx);
    func_8002ED80(&pthis->actor, globalCtx, 0);
    Matrix_RotateZYX(0x500, 0, -0x500, MTXMODE_APPLY);

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_ice_poly.c", 428),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, globalCtx->gameplayFrames % 0x100, 0x20, 0x10, 1, 0,
                                (globalCtx->gameplayFrames * 2) % 0x100, 0x40, 0x20));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 50, 100, pthis->alpha);
    gSPDisplayList(POLY_XLU_DISP++, gEffIceFragment3DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_ice_poly.c", 444);
}

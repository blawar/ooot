#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FD_FIRE_Z_EN_FD_FIRE_C
#include "actor_common.h"
#include "z_en_fd_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4)

void EnFdFire_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFdFire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFdFire_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFdFire_Draw(Actor* thisx, GlobalContext* globalCtx);
void EnFdFire_Disappear(EnFdFire* pthis, GlobalContext* globalCtx);
void func_80A0E70C(EnFdFire* pthis, GlobalContext* globalCtx);
void EnFdFire_DanceTowardsPlayer(EnFdFire* pthis, GlobalContext* globalCtx);
void EnFdFire_WaitToDie(EnFdFire* pthis, GlobalContext* globalCtx);

ActorInit En_Fd_Fire_InitVars = {
    ACTOR_EN_FD_FIRE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GAMEPLAY_DANGEON_KEEP,
    sizeof(EnFdFire),
    (ActorFunc)EnFdFire_Init,
    (ActorFunc)EnFdFire_Destroy,
    (ActorFunc)EnFdFire_Update,
    (ActorFunc)EnFdFire_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x01, 0x08 },
        { 0x0D840008, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 12, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInit = { 1, 0, 0, 0, MASS_IMMOVABLE };

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(2, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(0, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(0, 0x0),
    /* Master sword  */ DMG_ENTRY(0, 0x0),
    /* Giant's Knife */ DMG_ENTRY(0, 0x0),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(4, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(0, 0x0),
    /* Giant spin    */ DMG_ENTRY(0, 0x0),
    /* Master spin   */ DMG_ENTRY(0, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(0, 0x0),
    /* Giant jump    */ DMG_ENTRY(0, 0x0),
    /* Master jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

void EnFdFire_UpdatePos(EnFdFire* pthis, Vec3f* targetPos) {
    f32 dist;
    f32 xDiff = targetPos->x - pthis->actor.world.pos.x;
    f32 yDiff = targetPos->y - pthis->actor.world.pos.y;
    f32 zDiff = targetPos->z - pthis->actor.world.pos.z;

    dist = sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
    if (fabsf(dist) > fabsf(pthis->actor.speedXZ)) {
        pthis->actor.velocity.x = (xDiff / dist) * pthis->actor.speedXZ;
        pthis->actor.velocity.z = (zDiff / dist) * pthis->actor.speedXZ;
    } else {
        pthis->actor.velocity.x = 0.0f;
        pthis->actor.velocity.z = 0.0f;
    }

    pthis->actor.velocity.y += pthis->actor.gravity;
    if (!(pthis->actor.minVelocityY <= pthis->actor.velocity.y)) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }
}

s32 EnFdFire_CheckCollider(EnFdFire* pthis, GlobalContext* globalCtx) {
    if (pthis->actionFunc == EnFdFire_Disappear) {
        return false;
    }

    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        return true;
    }

    if (pthis->collider.base.ocFlags2 & OC2_HIT_PLAYER) {
        pthis->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
        return true;
    }
    return false;
}

void EnFdFire_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFdFire* pthis = (EnFdFire*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, &sDamageTable, &sColChkInit);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.gravity = -0.6f;
    pthis->actor.speedXZ = 5.0f;
    pthis->actor.velocity.y = 12.0f;
    pthis->spawnRadius = Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &player->actor.world.pos);
    pthis->scale = 3.0f;
    pthis->tile2Y = (s16)Rand_ZeroFloat(5.0f) - 25;
    pthis->actionFunc = func_80A0E70C;
}

void EnFdFire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFdFire* pthis = (EnFdFire*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80A0E70C(EnFdFire* pthis, GlobalContext* globalCtx) {
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f targetPos = pthis->actor.parent->world.pos;

    targetPos.x += pthis->spawnRadius * Math_SinS(pthis->actor.world.rot.y);
    targetPos.z += pthis->spawnRadius * Math_CosS(pthis->actor.world.rot.y);
    EnFdFire_UpdatePos(pthis, &targetPos);
    if (pthis->actor.bgCheckFlags & 1 && (!(pthis->actor.velocity.y > 0.0f))) {
        pthis->actor.velocity = velocity;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.bgCheckFlags &= ~1;
        if (pthis->actor.params & 0x8000) {
            pthis->deathTimer = 200;
            pthis->actionFunc = EnFdFire_DanceTowardsPlayer;
        } else {
            pthis->deathTimer = 300;
            pthis->actionFunc = EnFdFire_WaitToDie;
        }
    }
}

void EnFdFire_WaitToDie(EnFdFire* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->deathTimer) == 0) {
        pthis->actionFunc = EnFdFire_Disappear;
    }
}

void EnFdFire_DanceTowardsPlayer(EnFdFire* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 angles[] = {
        0.0f, 210.0f, 60.0f, 270.0f, 120.0f, 330.0f, 180.0f, 30.0f, 240.0f, 90.0f, 300.0f, 150.0f,
    };
    Vec3f pos;
    s16 idx;

    idx = ((globalCtx->state.frames / 10) + (pthis->actor.params & 0x7FFF)) % ARRAY_COUNT(angles);
    pos = player->actor.world.pos;
    pos.x += 120.0f * sinf(angles[idx]);
    pos.z += 120.0f * cosf(angles[idx]);

    if (DECR(pthis->deathTimer) == 0) {
        pthis->actionFunc = EnFdFire_Disappear;
    } else {
        Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_Vec3f_Yaw(&pthis->actor.world.pos, &pos), 8, 0xFA0, 1);
        Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.4f, 1.0f, 0.0f);
        if (pthis->actor.speedXZ < 0.1f) {
            pthis->actor.speedXZ = 5.0f;
        }
        func_8002D868(&pthis->actor);
    }
}

void EnFdFire_Disappear(EnFdFire* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->actor.speedXZ, 0.0f, 0.6f, 9.0f, 0.0f);
    func_8002D868(&pthis->actor);
    Math_SmoothStepToF(&pthis->scale, 0.0f, 0.3f, 0.1f, 0.0f);
    pthis->actor.shape.shadowScale = 20.0f;
    pthis->actor.shape.shadowScale *= (pthis->scale / 3.0f);
    if (!(pthis->scale > 0.01f)) {
        Actor_Kill(&pthis->actor);
    }
}

void EnFdFire_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFdFire* pthis = (EnFdFire*)thisx;
    s32 pad;

    if (pthis->actionFunc != EnFdFire_Disappear) {
        if ((pthis->actor.parent->update == NULL) || EnFdFire_CheckCollider(pthis, globalCtx)) {
            pthis->actionFunc = EnFdFire_Disappear;
        }
    }

    func_8002D7EC(&pthis->actor);
    pthis->actionFunc(pthis, globalCtx);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 12.0f, 10.0f, 0.0f, 5);

    if (pthis->actionFunc != EnFdFire_Disappear) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void EnFdFire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Color_RGBA8 primColors[] = {
        { 255, 255, 0, 255 },
        { 255, 255, 255, 255 },
    };
    Color_RGBA8 envColors[] = {
        { 255, 10, 0, 255 },
        { 0, 10, 255, 255 },
    };
    s32 pad;
    EnFdFire* pthis = (EnFdFire*)thisx;
    Vec3f scale = { 0.0f, 0.0f, 0.0f };
    Vec3f sp90 = { 0.0f, 0.0f, 0.0f };
    s16 sp8E;
    f32 sp88;
    f32 sp84;
    f32 sp80;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fd_fire.c", 572);

    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    sp8E = Math_Vec3f_Yaw(&scale, &pthis->actor.velocity) - Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx));
    sp84 = fabsf(Math_CosS(sp8E));
    sp88 = Math_SinS(sp8E);
    sp80 = Math_Vec3f_DistXZ(&scale, &pthis->actor.velocity) / 1.5f;
    if (1) {}
    if (1) {}
    if (1) {}
    Matrix_RotateY((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000) * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_RotateZ(((sp88 * -10.0f) * sp80) * (M_PI / 180.0f), MTXMODE_APPLY);
    scale.x = scale.y = scale.z = pthis->scale * 0.001f;
    Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);
    sp84 = sp80 * ((0.01f * -15.0f) * sp84) + 1.0f;
    if (sp84 < 0.1f) {
        sp84 = 0.1f;
    }
    Matrix_Scale(1.0f, sp84, 1.0f / sp84, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fd_fire.c", 623),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x8,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                (globalCtx->state.frames * pthis->tile2Y).whole(), 0x20, 0x80));
    gDPSetPrimColor(POLY_XLU_DISP++, 128, 128, primColors[((pthis->actor.params & 0x8000) >> 0xF)].r,
                    primColors[((pthis->actor.params & 0x8000) >> 0xF)].g,
                    primColors[((pthis->actor.params & 0x8000) >> 0xF)].b,
                    primColors[((pthis->actor.params & 0x8000) >> 0xF)].a);
    gDPSetEnvColor(POLY_XLU_DISP++, envColors[((pthis->actor.params & 0x8000) >> 0xF)].r,
                   envColors[((pthis->actor.params & 0x8000) >> 0xF)].g,
                   envColors[((pthis->actor.params & 0x8000) >> 0xF)].b,
                   envColors[((pthis->actor.params & 0x8000) >> 0xF)].a);
    gDPPipeSync(POLY_XLU_DISP++);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fd_fire.c", 672);
}

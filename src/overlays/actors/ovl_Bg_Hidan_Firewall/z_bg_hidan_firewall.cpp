#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_FIREWALL_Z_BG_HIDAN_FIREWALL_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_firewall.c
 * Overlay: ovl_Bg_Hidan_Firewall
 * Description: Proximity Triggered Flame Wall
 */

#include "z_bg_hidan_firewall.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgHidanFirewall_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFirewall_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFirewall_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanFirewall_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 BgHidanFirewall_CheckProximity(BgHidanFirewall* pthis, GlobalContext* globalCtx);
void BgHidanFirewall_Wait(BgHidanFirewall* pthis, GlobalContext* globalCtx);
void BgHidanFirewall_Countdown(BgHidanFirewall* pthis, GlobalContext* globalCtx);
void BgHidanFirewall_Erupt(BgHidanFirewall* pthis, GlobalContext* globalCtx);
void BgHidanFirewall_Collide(BgHidanFirewall* pthis, GlobalContext* globalCtx);
void BgHidanFirewall_ColliderFollowPlayer(BgHidanFirewall* pthis, GlobalContext* globalCtx);

ActorInit Bg_Hidan_Firewall_InitVars = {
    ACTOR_BG_HIDAN_FIREWALL,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanFirewall),
    (ActorFunc)BgHidanFirewall_Init,
    (ActorFunc)BgHidanFirewall_Destroy,
    (ActorFunc)BgHidanFirewall_Update,
    NULL,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x01, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 30, 83, 0, { 0 } },
};

static CollisionCheckInfoInit sColChkInfoInit = { 1, 80, 100, MASS_IMMOVABLE };

void BgHidanFirewall_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFirewall* pthis = (BgHidanFirewall*)thisx;

    pthis->actor.scale.x = 0.12f;
    pthis->actor.scale.z = 0.12f;
    pthis->actor.scale.y = 0.01f;

    pthis->unk_150 = 0;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);

    pthis->collider.dim.pos.y = pthis->actor.world.pos.y;

    CollisionCheck_SetInfo(&pthis->actor.colChkInfo, NULL, &sColChkInfoInit);

    pthis->actionFunc = BgHidanFirewall_Wait;
}

void BgHidanFirewall_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFirewall* pthis = (BgHidanFirewall*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 BgHidanFirewall_CheckProximity(BgHidanFirewall* pthis, GlobalContext* globalCtx) {
    Player* player;
    Vec3f distance;

    player = GET_PLAYER(globalCtx);
    func_8002DBD0(&pthis->actor, &distance, &player->actor.world.pos);

    if (fabsf(distance.x) < 100.0f && fabsf(distance.z) < 120.0f) {
        return 1;
    }
    return 0;
}

void BgHidanFirewall_Wait(BgHidanFirewall* pthis, GlobalContext* globalCtx) {
    if (BgHidanFirewall_CheckProximity(pthis, globalCtx) != 0) {
        pthis->actor.draw = BgHidanFirewall_Draw;
        pthis->actor.params = 5;
        pthis->actionFunc = BgHidanFirewall_Countdown;
    }
}

void BgHidanFirewall_Countdown(BgHidanFirewall* pthis, GlobalContext* globalCtx) {

    if (pthis->actor.params != 0) {
        pthis->actor.params--;
    }
    if (pthis->actor.params == 0) {
        pthis->actionFunc = BgHidanFirewall_Erupt;
    }
}

void BgHidanFirewall_Erupt(BgHidanFirewall* pthis, GlobalContext* globalCtx) {
    if (BgHidanFirewall_CheckProximity(pthis, globalCtx) != 0) {
        Math_StepToF(&pthis->actor.scale.y, 0.1f, 0.01f / 0.4f);
    } else {
        if (Math_StepToF(&pthis->actor.scale.y, 0.01f, 0.01f) != 0) {
            pthis->actor.draw = NULL;
            pthis->actionFunc = BgHidanFirewall_Wait;
        } else {
            pthis->actor.params = 0;
        }
    }
}

void BgHidanFirewall_Collide(BgHidanFirewall* pthis, GlobalContext* globalCtx) {
    s16 phi_a3;

    if (Actor_IsFacingPlayer(&pthis->actor, 0x4000)) {
        phi_a3 = pthis->actor.shape.rot.y;
    } else {
        phi_a3 = pthis->actor.shape.rot.y + 0x8000;
    }

    func_8002F71C(globalCtx, &pthis->actor, 5.0f, phi_a3, 1.0f);
}

void BgHidanFirewall_ColliderFollowPlayer(BgHidanFirewall* pthis, GlobalContext* globalCtx) {
    Player* player;
    Vec3f sp30;
    f32 temp_ret;
    f32 sp28;
    f32 phi_f0;

    player = GET_PLAYER(globalCtx);

    func_8002DBD0(&pthis->actor, &sp30, &player->actor.world.pos);
    if (sp30.x < -70.0f) {
        sp30.x = -70.0f;
    } else {
        if (70.0f < sp30.x) {
            phi_f0 = 70.0f;
        } else {
            phi_f0 = sp30.x;
        }
        sp30.x = phi_f0;
    }
    if (pthis->actor.params == 0) {
        if (0.0f < sp30.z) {
            sp30.z = -25.0f;
            pthis->actor.params = -1;
        } else {
            sp30.z = 25.0f;
            pthis->actor.params = 1;
        }
    } else {
        sp30.z = pthis->actor.params * 25.0f;
    }
    sp28 = Math_SinS(pthis->actor.shape.rot.y);
    temp_ret = Math_CosS(pthis->actor.shape.rot.y);
    pthis->collider.dim.pos.x = pthis->actor.world.pos.x + sp30.x * temp_ret + sp30.z * sp28;
    pthis->collider.dim.pos.z = pthis->actor.world.pos.z - sp30.x * sp28 + sp30.z * temp_ret;
}

void BgHidanFirewall_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFirewall* pthis = (BgHidanFirewall*)thisx;
    s32 pad;

    pthis->unk_150 = (pthis->unk_150 + 1) % 8;

    if (pthis->collider.base.atFlags & AT_HIT) {
        pthis->collider.base.atFlags &= ~AT_HIT;
        BgHidanFirewall_Collide(pthis, globalCtx);
    }

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actionFunc == BgHidanFirewall_Erupt) {
        BgHidanFirewall_ColliderFollowPlayer(pthis, globalCtx);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        func_8002F974(&pthis->actor, NA_SE_EV_FIRE_PLATE - SFX_FLAG);
    }
}

static void* sFireballTexs[] = {
    gFireTempleFireball0Tex, gFireTempleFireball1Tex, gFireTempleFireball2Tex, gFireTempleFireball3Tex,
    gFireTempleFireball4Tex, gFireTempleFireball5Tex, gFireTempleFireball6Tex, gFireTempleFireball7Tex,
};

void BgHidanFirewall_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanFirewall* pthis = (BgHidanFirewall*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_firewall.c", 448);

    POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0x14);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sFireballTexs[pthis->unk_150]));
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x01, 255, 255, 0, 150);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 255);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_firewall.c", 458),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gFireTempleFireballUpperHalfDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_firewall.c", 463);
}

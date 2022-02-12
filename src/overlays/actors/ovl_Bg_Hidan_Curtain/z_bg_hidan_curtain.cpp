#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_CURTAIN_Z_BG_HIDAN_CURTAIN_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_curtain.c
 * Overlay: ovl_Bg_Hidan_Curtain
 * Description: Flame circle
 */

#include "z_bg_hidan_curtain.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgHidanCurtain_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanCurtain_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanCurtain_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanCurtain_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHidanCurtain_WaitForSwitchOn(BgHidanCurtain* pthis, GlobalContext* globalCtx);
void BgHidanCurtain_WaitForCutscene(BgHidanCurtain* pthis, GlobalContext* globalCtx);
void BgHidanCurtain_WaitForClear(BgHidanCurtain* pthis, GlobalContext* globalCtx);
void BgHidanCurtain_TurnOn(BgHidanCurtain* pthis, GlobalContext* globalCtx);
void BgHidanCurtain_TurnOff(BgHidanCurtain* pthis, GlobalContext* globalCtx);
void BgHidanCurtain_WaitForTimer(BgHidanCurtain* pthis, GlobalContext* globalCtx);

typedef struct {
    /* 0x00 */ s16 radius;
    /* 0x02 */ s16 height;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 riseDist;
    /* 0x0C */ f32 riseSpeed;
} BgHidanCurtainParams; // size = 0x10

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
    { 81, 144, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit sCcInfoInit = { 1, 80, 100, MASS_IMMOVABLE };

static BgHidanCurtainParams sHCParams[] = { { 81, 144, 0.090f, 144.0f, 5.0f }, { 46, 88, 0.055f, 88.0f, 3.0f } };

ActorInit Bg_Hidan_Curtain_InitVars = {
    ACTOR_BG_HIDAN_CURTAIN,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgHidanCurtain),
    (ActorFunc)BgHidanCurtain_Init,
    (ActorFunc)BgHidanCurtain_Destroy,
    (ActorFunc)BgHidanCurtain_Update,
    (ActorFunc)BgHidanCurtain_Draw,
};

void BgHidanCurtain_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanCurtain* pthis = (BgHidanCurtain*)thisx;
    BgHidanCurtainParams* hcParams;

    osSyncPrintf("Curtain (arg_data 0x%04x)\n", pthis->actor.params);
    Actor_SetFocus(&pthis->actor, 20.0f);
    pthis->type = (thisx->params >> 0xC) & 0xF;
    if (pthis->type > 6) {
        // "Type is not set"
        osSyncPrintf("Error : object のタイプが設定されていない(%s %d)(arg_data 0x%04x)\n", "../z_bg_hidan_curtain.c",
                     352, pthis->actor.params);
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->size = ((pthis->type == 2) || (pthis->type == 4)) ? 1 : 0;
    hcParams = &sHCParams[pthis->size];
    pthis->treasureFlag = (thisx->params >> 6) & 0x3F;
    thisx->params &= 0x3F;

    if ((pthis->actor.params < 0) || (pthis->actor.params > 0x3F)) {
        // "Save bit is not set"
        osSyncPrintf("Warning : object のセーブビットが設定されていない(%s %d)(arg_data 0x%04x)\n",
                     "../z_bg_hidan_curtain.c", 373, pthis->actor.params);
    }
    Actor_SetScale(&pthis->actor, hcParams->scale);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    pthis->collider.dim.pos.x = pthis->actor.world.pos.x;
    pthis->collider.dim.pos.y = pthis->actor.world.pos.y;
    pthis->collider.dim.pos.z = pthis->actor.world.pos.z;
    pthis->collider.dim.radius = hcParams->radius;
    pthis->collider.dim.height = hcParams->height;
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetInfo(&thisx->colChkInfo, NULL, &sCcInfoInit);
    if (pthis->type == 0) {
        pthis->actionFunc = BgHidanCurtain_WaitForClear;
    } else {
        pthis->actionFunc = BgHidanCurtain_WaitForSwitchOn;
        if ((pthis->type == 4) || (pthis->type == 5)) {
            pthis->actor.world.pos.y = pthis->actor.home.pos.y - hcParams->riseDist;
        }
    }
    if (((pthis->type == 1) && Flags_GetTreasure(globalCtx, pthis->treasureFlag)) ||
        (((pthis->type == 0) || (pthis->type == 6)) && Flags_GetClear(globalCtx, pthis->actor.room))) {
        Actor_Kill(&pthis->actor);
    }
    pthis->texScroll = Rand_ZeroOne() * 15.0f;
}

void BgHidanCurtain_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHidanCurtain* pthis = (BgHidanCurtain*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void BgHidanCurtain_WaitForSwitchOn(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        if (pthis->type == 1) {
            pthis->actionFunc = BgHidanCurtain_WaitForCutscene;
            OnePointCutscene_Init(globalCtx, 3350, -99, &pthis->actor, MAIN_CAM);
            pthis->timer = 50;
        } else if (pthis->type == 3) {
            pthis->actionFunc = BgHidanCurtain_WaitForCutscene;
            OnePointCutscene_Init(globalCtx, 3360, 60, &pthis->actor, MAIN_CAM);
            pthis->timer = 30;
        } else {
            pthis->actionFunc = BgHidanCurtain_TurnOff;
        }
    }
}

void BgHidanCurtain_WaitForCutscene(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    if (pthis->timer-- == 0) {
        pthis->actionFunc = BgHidanCurtain_TurnOff;
    }
}

void BgHidanCurtain_WaitForClear(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    if (Flags_GetClear(globalCtx, pthis->actor.room)) {
        pthis->actionFunc = BgHidanCurtain_TurnOff;
    }
}

void BgHidanCurtain_WaitForSwitchOff(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    if (!Flags_GetSwitch(globalCtx, pthis->actor.params)) {
        pthis->actionFunc = BgHidanCurtain_TurnOn;
    }
}

void BgHidanCurtain_TurnOn(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    f32 riseSpeed = sHCParams[pthis->size].riseSpeed;

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, riseSpeed)) {
        Flags_UnsetSwitch(globalCtx, pthis->actor.params);
        pthis->actionFunc = BgHidanCurtain_WaitForSwitchOn;
    }
}

void BgHidanCurtain_TurnOff(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    BgHidanCurtainParams* hcParams = &sHCParams[pthis->size];

    if (Math_StepToF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y - hcParams->riseDist, hcParams->riseSpeed)) {
        if ((pthis->type == 0) || (pthis->type == 6)) {
            Actor_Kill(&pthis->actor);
        } else if (pthis->type == 5) {
            pthis->actionFunc = BgHidanCurtain_WaitForSwitchOff;
        } else {
            if (pthis->type == 2) {
                pthis->timer = 400;
            } else if (pthis->type == 4) {
                pthis->timer = 200;
            } else if (pthis->type == 3) {
                pthis->timer = 160;
            } else { // pthis->type == 1
                pthis->timer = 300;
            }
            pthis->actionFunc = BgHidanCurtain_WaitForTimer;
        }
    }
}

void BgHidanCurtain_WaitForTimer(BgHidanCurtain* pthis, GlobalContext* globalCtx) {
    DECR(pthis->timer);
    if (pthis->timer == 0) {
        pthis->actionFunc = BgHidanCurtain_TurnOn;
    }
    if ((pthis->type == 1) || (pthis->type == 3)) {
        func_8002F994(&pthis->actor, pthis->timer);
    }
}

void BgHidanCurtain_Update(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    BgHidanCurtain* pthis = (BgHidanCurtain*)thisx;
    BgHidanCurtainParams* hcParams = &sHCParams[pthis->size];
    f32 riseProgress;

    if ((globalCtx->cameraPtrs[MAIN_CAM]->setting == CAM_SET_SLOW_CHEST_CS) ||
        (globalCtx->cameraPtrs[MAIN_CAM]->setting == CAM_SET_TURN_AROUND)) {
        pthis->collider.base.atFlags &= ~AT_HIT;
    } else {
        if (pthis->collider.base.atFlags & AT_HIT) {
            pthis->collider.base.atFlags &= ~AT_HIT;
            func_8002F71C(globalCtx, &pthis->actor, 5.0f, pthis->actor.yawTowardsPlayer, 1.0f);
        }
        if ((pthis->type == 4) || (pthis->type == 5)) {
            pthis->actor.world.pos.y = (2.0f * pthis->actor.home.pos.y) - hcParams->riseDist - pthis->actor.world.pos.y;
        }

        pthis->actionFunc(pthis, globalCtx);

        if ((pthis->type == 4) || (pthis->type == 5)) {
            pthis->actor.world.pos.y = (2.0f * pthis->actor.home.pos.y) - hcParams->riseDist - pthis->actor.world.pos.y;
        }
        riseProgress = (hcParams->riseDist - (pthis->actor.home.pos.y - pthis->actor.world.pos.y)) / hcParams->riseDist;
        pthis->alpha = 255.0f * riseProgress;
        if (pthis->alpha > 50) {
            pthis->collider.dim.height = hcParams->height * riseProgress;
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            if (gSaveContext.sceneSetupIndex <= 3) {
                func_8002F974(&pthis->actor, NA_SE_EV_FIRE_PILLAR_S - SFX_FLAG);
            }
        } else if ((pthis->type == 1) && Flags_GetTreasure(globalCtx, pthis->treasureFlag)) {
            Actor_Kill(&pthis->actor);
        }
        pthis->texScroll++;
    }
}

void BgHidanCurtain_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanCurtain* pthis = (BgHidanCurtain*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_curtain.c", 685);
    func_80093D84(globalCtx->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 220, 0, pthis->alpha);

    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->texScroll & 0x7F, 0, 0x20, 0x40, 1, 0,
                                (pthis->texScroll * -0xF) & 0xFF, 0x20, 0x40));

    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_curtain.c", 698),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_XLU_DISP++, gEffFireCircleDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_curtain.c", 702);
}

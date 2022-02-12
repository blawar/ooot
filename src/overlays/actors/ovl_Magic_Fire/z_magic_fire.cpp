#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_MAGIC_FIRE_Z_MAGIC_FIRE_C
#include "actor_common.h"
/*
 * File: z_magic_fire.c
 * Overlay: ovl_Magic_Fire
 * Description: Din's Fire
 */

#include "z_magic_fire.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void MagicFire_Init(Actor* thisx, GlobalContext* globalCtx);
void MagicFire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void MagicFire_Update(Actor* thisx, GlobalContext* globalCtx);
void MagicFire_Draw(Actor* thisx, GlobalContext* globalCtx);

void MagicFire_UpdateBeforeCast(Actor* thisx, GlobalContext* globalCtx);

typedef enum {
    /* 0x00 */ DF_ACTION_INITIALIZE,
    /* 0x01 */ DF_ACTION_EXPAND_SLOWLY,
    /* 0x02 */ DF_ACTION_STOP_EXPANDING,
    /* 0x03 */ DF_ACTION_EXPAND_QUICKLY
} MagicFireAction;

typedef enum {
    /* 0x00 */ DF_SCREEN_TINT_NONE,
    /* 0x01 */ DF_SCREEN_TINT_FADE_IN,
    /* 0x02 */ DF_SCREEN_TINT_MAINTAIN,
    /* 0x03 */ DF_SCREEN_TINT_FADE_OUT,
    /* 0x04 */ DF_SCREEN_TINT_FINISHED
} MagicFireScreenTint;

ActorInit Magic_Fire_InitVars = {
    ACTOR_MAGIC_FIRE,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(MagicFire),
    (ActorFunc)MagicFire_Init,
    (ActorFunc)MagicFire_Destroy,
    (ActorFunc)MagicFire_Update,
    (ActorFunc)MagicFire_Draw,
};

#include "overlays/ovl_Magic_Fire/ovl_Magic_Fire.cpp"

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00020000, 0x00, 0x01 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 9, 9, 0, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F(scale, 0, ICHAIN_STOP),
};

static u8 sVertexIndices[] = {
    3,  4,  5,  6,  7,  8,  9,  10, 16, 17, 18, 19, 25, 26, 27, 32, 35, 36, 37, 38,
    39, 45, 46, 47, 52, 53, 54, 59, 60, 61, 67, 68, 69, 70, 71, 72, 0,  1,  11, 12,
    14, 20, 21, 23, 28, 30, 33, 34, 40, 41, 43, 48, 50, 55, 57, 62, 64, 65, 73, 74,
};

void MagicFire_Init(Actor* thisx, GlobalContext* globalCtx) {
    MagicFire* pthis = (MagicFire*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->action = 0;
    pthis->screenTintBehaviour = 0;
    pthis->actionTimer = 0;
    pthis->alphaMultiplier = -3.0f;
    Actor_SetScale(&pthis->actor, 0.0f);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    pthis->actor.update = MagicFire_UpdateBeforeCast;
    pthis->actionTimer = 20;
    pthis->actor.room = -1;
}

void MagicFire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    func_800876C8(globalCtx);
}

void MagicFire_UpdateBeforeCast(Actor* thisx, GlobalContext* globalCtx) {
    MagicFire* pthis = (MagicFire*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    if ((globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_CORRECT_PLAYBACK) ||
        (globalCtx->msgCtx.msgMode == MSGMODE_SONG_PLAYED)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->actionTimer > 0) {
        pthis->actionTimer--;
    } else {
        pthis->actor.update = MagicFire_Update;
        func_8002F7DC(&player->actor, NA_SE_PL_MAGIC_FIRE);
    }
    pthis->actor.world.pos = player->actor.world.pos;
}

void MagicFire_Update(Actor* thisx, GlobalContext* globalCtx) {
    MagicFire* pthis = (MagicFire*)thisx;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;

    if (1) {}
    pthis->actor.world.pos = player->actor.world.pos;
    if ((globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_CORRECT_PLAYBACK) ||
        (globalCtx->msgCtx.msgMode == MSGMODE_SONG_PLAYED)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    if (pthis->action == DF_ACTION_EXPAND_SLOWLY) {
        pthis->collider.info.toucher.damage = pthis->actionTimer + 25;
    } else if (pthis->action == DF_ACTION_STOP_EXPANDING) {
        pthis->collider.info.toucher.damage = pthis->actionTimer;
    }
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    pthis->collider.dim.radius = (pthis->actor.scale.x * 325.0f);
    pthis->collider.dim.height = (pthis->actor.scale.y * 450.0f);
    pthis->collider.dim.yShift = (pthis->actor.scale.y * -225.0f);
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

    switch (pthis->action) {
        case DF_ACTION_INITIALIZE:
            pthis->actionTimer = 30;
            pthis->actor.scale.x = pthis->actor.scale.y = pthis->actor.scale.z = 0.0f;
            pthis->actor.world.rot.x = pthis->actor.world.rot.y = pthis->actor.world.rot.z = 0;
            pthis->actor.shape.rot.x = pthis->actor.shape.rot.y = pthis->actor.shape.rot.z = 0;
            pthis->alphaMultiplier = 0.0f;
            pthis->scalingSpeed = 0.08f;
            pthis->action++;
            break;
        case DF_ACTION_EXPAND_SLOWLY: // Fire sphere slowly expands out of player for 30 frames
            Math_StepToF(&pthis->alphaMultiplier, 1.0f, 1.0f / 30.0f);
            if (pthis->actionTimer > 0) {
                Math_SmoothStepToF(&pthis->actor.scale.x, 0.4f, pthis->scalingSpeed, 0.1f, 0.001f);
                pthis->actor.scale.y = pthis->actor.scale.z = pthis->actor.scale.x;
            } else {
                pthis->actionTimer = 25;
                pthis->action++;
            }
            break;
        case DF_ACTION_STOP_EXPANDING: // Sphere stops expanding and maintains size for 25 frames
            if (pthis->actionTimer <= 0) {
                pthis->actionTimer = 15;
                pthis->action++;
                pthis->scalingSpeed = 0.05f;
            }
            break;
        case DF_ACTION_EXPAND_QUICKLY: // Sphere beings to grow again and quickly expands out until killed
            pthis->alphaMultiplier -= 8.0f / 119.00001f;
            pthis->actor.scale.x += pthis->scalingSpeed;
            pthis->actor.scale.y += pthis->scalingSpeed;
            pthis->actor.scale.z += pthis->scalingSpeed;
            if (pthis->alphaMultiplier <= 0.0f) {
                pthis->action = 0;
                Actor_Kill(&pthis->actor);
            }
            break;
    }
    switch (pthis->screenTintBehaviour) {
        case DF_SCREEN_TINT_NONE:
            if (pthis->screenTintBehaviourTimer <= 0) {
                pthis->screenTintBehaviourTimer = 20;
                pthis->screenTintBehaviour = DF_SCREEN_TINT_FADE_IN;
            }
            break;
        case DF_SCREEN_TINT_FADE_IN:
            pthis->screenTintIntensity = 1.0f - (pthis->screenTintBehaviourTimer / 20.0f);
            if (pthis->screenTintBehaviourTimer <= 0) {
                pthis->screenTintBehaviourTimer = 45;
                pthis->screenTintBehaviour = DF_SCREEN_TINT_MAINTAIN;
            }
            break;
        case DF_SCREEN_TINT_MAINTAIN:
            if (pthis->screenTintBehaviourTimer <= 0) {
                pthis->screenTintBehaviourTimer = 5;
                pthis->screenTintBehaviour = DF_SCREEN_TINT_FADE_OUT;
            }
            break;
        case DF_SCREEN_TINT_FADE_OUT:
            pthis->screenTintIntensity = (pthis->screenTintBehaviourTimer / 5.0f);
            if (pthis->screenTintBehaviourTimer <= 0) {
                pthis->screenTintBehaviour = DF_SCREEN_TINT_FINISHED;
            }
            break;
    }
    if (pthis->actionTimer > 0) {
        pthis->actionTimer--;
    }
    if (pthis->screenTintBehaviourTimer > 0) {
        pthis->screenTintBehaviourTimer--;
    }
}

void MagicFire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    MagicFire* pthis = (MagicFire*)thisx;
    s32 pad1;
    u32 gameplayFrames = globalCtx->gameplayFrames;
    s32 pad2;
    s32 i;
    u8 alpha;

    if (pthis->action > 0) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_magic_fire.c", 682);
        POLY_XLU_DISP = func_800937C0(POLY_XLU_DISP);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (u8)(s32)(60 * pthis->screenTintIntensity),
                        (u8)(s32)(20 * pthis->screenTintIntensity), (u8)(s32)(0 * pthis->screenTintIntensity),
                        (u8)(s32)(120 * pthis->screenTintIntensity));
        gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_DISABLE);
        gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);
        gDPFillRectangle(POLY_XLU_DISP++, 0, 0, 319, 239);
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 128, 255, 200, 0, (u8)(pthis->alphaMultiplier * 255));
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, (u8)(pthis->alphaMultiplier * 255));
        Matrix_Scale(0.15f, 0.15f, 0.15f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_magic_fire.c", 715),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPTexture(POLY_XLU_DISP++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLUT(POLY_XLU_DISP++, G_TT_NONE);
        gDPLoadTextureBlock(POLY_XLU_DISP++, sTex, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 6, 6, 15, G_TX_NOLOD);
        gDPSetTile(POLY_XLU_DISP++, G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, 14,
                   G_TX_NOMIRROR | G_TX_WRAP, 6, 14);
        gDPSetTileSize(POLY_XLU_DISP++, 1, 0, 0, 252, 252);
        gSPDisplayList(POLY_XLU_DISP++, sMaterialDL);
        gSPDisplayList(POLY_XLU_DISP++,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (gameplayFrames * 2) % 512,
                                        511 - ((gameplayFrames * 5) % 512), 64, 64, 1, (gameplayFrames * 2) % 256,
                                        255 - ((gameplayFrames * 20) % 256), 32, 32));
        gSPDisplayList(POLY_XLU_DISP++, sModelDL);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_magic_fire.c", 750);

        alpha = (s32)(pthis->alphaMultiplier * 255);
        for (i = 0; i < 36; i++) {
            sSphereVtx[sVertexIndices[i]].n.a = alpha;
        }

        alpha = (s32)(pthis->alphaMultiplier * 76);
        for (i = 36; i < 60; i++) {
            sSphereVtx[sVertexIndices[i]].n.a = alpha;
        }
    }
}

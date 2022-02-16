#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_MAGIC_DARK_Z_MAGIC_DARK_C
#include "actor_common.h"
/*
 * File: z_magic_dark.c
 * Overlay: ovl_Magic_Dark
 * Description: Nayru's Love
 */

#include "z_magic_dark.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_25)

void MagicDark_Init(Actor* thisx, GlobalContext* globalCtx);
void MagicDark_Reset(Actor* pthisx, GlobalContext* globalCtx);
void MagicDark_Destroy(Actor* thisx, GlobalContext* globalCtx);
void MagicDark_OrbUpdate(Actor* thisx, GlobalContext* globalCtx);
void MagicDark_OrbDraw(Actor* thisx, GlobalContext* globalCtx);
void MagicDark_DiamondUpdate(Actor* thisx, GlobalContext* globalCtx);
void MagicDark_DiamondDraw(Actor* thisx, GlobalContext* globalCtx);

void MagicDark_DimLighting(GlobalContext* globalCtx, f32 intensity);

ActorInit Magic_Dark_InitVars = {
    ACTOR_MAGIC_DARK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(MagicDark),
    (ActorFunc)MagicDark_Init,
    (ActorFunc)MagicDark_Destroy,
    (ActorFunc)MagicDark_OrbUpdate,
    (ActorFunc)MagicDark_OrbDraw,
    (ActorFunc)MagicDark_Reset,
};

#include "overlays/ovl_Magic_Dark/ovl_Magic_Dark.cpp"

// unused
static Color_RGBA8 D_80B88B10[] = { { 50, 100, 150, 200 }, { 255, 200, 150, 100 } };

void MagicDark_Init(Actor* thisx, GlobalContext* globalCtx) {
    MagicDark* pthis = (MagicDark*)thisx;
    Player* player = GET_PLAYER(globalCtx);

    if (!LINK_IS_ADULT) {
        pthis->scale = 0.4f;
    } else {
        pthis->scale = 0.6f;
    }

    thisx->world.pos = player->actor.world.pos;
    Actor_SetScale(&pthis->actor, 0.0f);
    thisx->room = -1;

    if (gSaveContext.nayrusLoveTimer != 0) {
        thisx->update = MagicDark_DiamondUpdate;
        thisx->draw = MagicDark_DiamondDraw;
        thisx->scale.x = thisx->scale.z = pthis->scale * 1.6f;
        thisx->scale.y = pthis->scale * 0.8f;
        pthis->timer = 0;
        pthis->primAlpha = 0;
    } else {
        pthis->timer = 0;
        gSaveContext.nayrusLoveTimer = 0;
    }
}

void MagicDark_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    if (gSaveContext.nayrusLoveTimer == 0) {
        func_800876C8(globalCtx);
    }
}

void MagicDark_DiamondUpdate(Actor* thisx, GlobalContext* globalCtx) {
    MagicDark* pthis = (MagicDark*)thisx;
    u8 phi_a0;
    Player* player = GET_PLAYER(globalCtx);
    s16 pad;
    s16 nayrusLoveTimer = gSaveContext.nayrusLoveTimer;
    s32 msgMode = globalCtx->msgCtx.msgMode;

    if (1) {}

    if ((msgMode == MSGMODE_OCARINA_CORRECT_PLAYBACK) || (msgMode == MSGMODE_SONG_PLAYED)) {
        Actor_Kill(thisx);
        return;
    }

    if (nayrusLoveTimer >= 1200) {
        player->invincibilityTimer = 0;
        gSaveContext.nayrusLoveTimer = 0;
        Actor_Kill(thisx);
        return;
    }

    player->invincibilityTimer = -100;
    thisx->scale.x = thisx->scale.z = pthis->scale;

    if (pthis->timer < 20) {
        thisx->scale.x = thisx->scale.z = (1.6f - (pthis->timer * 0.03f)) * pthis->scale;
        thisx->scale.y = ((pthis->timer * 0.01f) + 0.8f) * pthis->scale;
    } else {
        thisx->scale.x = thisx->scale.z = pthis->scale;
        thisx->scale.y = pthis->scale;
    }

    thisx->scale.x *= 1.3f;
    thisx->scale.z *= 1.3f;

    phi_a0 = (pthis->timer < 20) ? (pthis->timer * 12) : 255;

    if (nayrusLoveTimer >= 1180) {
        pthis->primAlpha = 15595 - (nayrusLoveTimer * 13);
        if (nayrusLoveTimer & 1) {
            pthis->primAlpha = pthis->primAlpha >> 1;
        }
    } else if (nayrusLoveTimer >= 1100) {
        pthis->primAlpha = (u8)(nayrusLoveTimer << 7) + 127;
    } else {
        pthis->primAlpha = 255;
    }

    if (pthis->primAlpha > phi_a0) {
        pthis->primAlpha = phi_a0;
    }

    thisx->world.rot.y += 0x3E8;
    thisx->shape.rot.y = thisx->world.rot.y + Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx));
    pthis->timer++;
    gSaveContext.nayrusLoveTimer = nayrusLoveTimer + 1;

    if (nayrusLoveTimer < 1100) {
        func_8002F974(thisx, NA_SE_PL_MAGIC_SOUL_NORMAL - SFX_FLAG);
    } else {
        func_8002F974(thisx, NA_SE_PL_MAGIC_SOUL_FLASH - SFX_FLAG);
    }
}

void MagicDark_DimLighting(GlobalContext* globalCtx, f32 intensity) {
    s32 i;
    f32 colorScale;
    f32 fogScale;

    if (globalCtx->roomCtx.curRoom.unk_03 != 5) {
        intensity = CLAMP_MIN(intensity, 0.0f);
        intensity = CLAMP_MAX(intensity, 1.0f);
        fogScale = intensity - 0.2f;

        if (intensity < 0.2f) {
            fogScale = 0.0f;
        }

        globalCtx->envCtx.adjFogNear = (850.0f - globalCtx->envCtx.lightSettings.fogNear) * fogScale;

        if (intensity == 0.0f) {
            for (i = 0; i < ARRAY_COUNT(globalCtx->envCtx.adjFogColor); i++) {
                globalCtx->envCtx.adjFogColor[i] = 0;
            }
        } else {
            colorScale = intensity * 5.0f;

            if (colorScale > 1.0f) {
                colorScale = 1.0f;
            }

            for (i = 0; i < ARRAY_COUNT(globalCtx->envCtx.adjFogColor); i++) {
                globalCtx->envCtx.adjFogColor[i] = -(s16)(globalCtx->envCtx.lightSettings.fogColor[i] * colorScale);
            }
        }
    }
}

void MagicDark_OrbUpdate(Actor* thisx, GlobalContext* globalCtx) {
    MagicDark* pthis = (MagicDark*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    func_8002F974(&pthis->actor, NA_SE_PL_MAGIC_SOUL_BALL - SFX_FLAG);
    if (pthis->timer < 35) {
        MagicDark_DimLighting(globalCtx, pthis->timer * (1 / 45.0f));
        Math_SmoothStepToF(&thisx->scale.x, pthis->scale * (1 / 12.000001f), 0.05f, 0.01f, 0.0001f);
        Actor_SetScale(&pthis->actor, thisx->scale.x);
    } else if (pthis->timer < 55) {
        Actor_SetScale(&pthis->actor, thisx->scale.x * 0.9f);
        Math_SmoothStepToF(&pthis->orbOffset.y, player->bodyPartsPos[0].y, 0.5f, 3.0f, 1.0f);
        if (pthis->timer > 48) {
            MagicDark_DimLighting(globalCtx, (54 - pthis->timer) * 0.2f);
        }
    } else {
        thisx->update = MagicDark_DiamondUpdate;
        thisx->draw = MagicDark_DiamondDraw;
        thisx->scale.x = thisx->scale.z = pthis->scale * 1.6f;
        thisx->scale.y = pthis->scale * 0.8f;
        pthis->timer = 0;
        pthis->primAlpha = 0;
    }

    pthis->timer++;
}

void MagicDark_DiamondDraw(Actor* thisx, GlobalContext* globalCtx) {
    MagicDark* pthis = (MagicDark*)thisx;
    s32 pad;
    u16 gameplayFrames = globalCtx->gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_magic_dark.c", 525);

    func_80093D84(globalCtx->state.gfxCtx);

    {
        Player* player = GET_PLAYER(globalCtx);
        f32 heightDiff;

        pthis->actor.world.pos.x = player->bodyPartsPos[0].x;
        pthis->actor.world.pos.z = player->bodyPartsPos[0].z;
        heightDiff = player->bodyPartsPos[0].y - pthis->actor.world.pos.y;
        if (heightDiff < -2.0f) {
            pthis->actor.world.pos.y = player->bodyPartsPos[0].y + 2.0f;
        } else if (heightDiff > 2.0f) {
            pthis->actor.world.pos.y = player->bodyPartsPos[0].y - 2.0f;
        }
        Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
        Matrix_RotateY(pthis->actor.shape.rot.y * (M_PI / 0x8000), MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_magic_dark.c", 553),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 170, 255, 255, (s32)(pthis->primAlpha * 0.6f) & 0xFF);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, 128);
        gSPDisplayList(POLY_XLU_DISP++, sDiamondMaterialDL);
        gSPDisplayList(POLY_XLU_DISP++,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, gameplayFrames * 2, gameplayFrames * -4, 32, 32, 1,
                                        0, gameplayFrames * -16, 64, 32));
        gSPDisplayList(POLY_XLU_DISP++, sDiamondModelDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_magic_dark.c", 570);
}

void MagicDark_OrbDraw(Actor* thisx, GlobalContext* globalCtx) {
    MagicDark* pthis = (MagicDark*)thisx;
    Vec3f pos;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    f32 sp6C = globalCtx->state.frames & 0x1F;

    if (pthis->timer < 32) {
        pos.x = (player->bodyPartsPos[12].x + player->bodyPartsPos[15].x) * 0.5f;
        pos.y = (player->bodyPartsPos[12].y + player->bodyPartsPos[15].y) * 0.5f;
        pos.z = (player->bodyPartsPos[12].z + player->bodyPartsPos[15].z) * 0.5f;
        if (pthis->timer > 20) {
            pos.y += (pthis->timer - 20) * 1.4f;
        }
        pthis->orbOffset = pos;
    } else if (pthis->timer < 130) {
        pos = pthis->orbOffset;
    } else {
        return;
    }

    pos.x -= (pthis->actor.scale.x * 300.0f * Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx))) *
              Math_CosS(Camera_GetCamDirPitch(GET_ACTIVE_CAM(globalCtx))));
    pos.y -= (pthis->actor.scale.x * 300.0f * Math_SinS(Camera_GetCamDirPitch(GET_ACTIVE_CAM(globalCtx))));
    pos.z -= (pthis->actor.scale.x * 300.0f * Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx))) *
              Math_CosS(Camera_GetCamDirPitch(GET_ACTIVE_CAM(globalCtx))));

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_magic_dark.c", 619);

    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 170, 255, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 150, 255, 255);
    Matrix_Translate(pos.x, pos.y, pos.z, MTXMODE_NEW);
    Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
    Matrix_Mult(&globalCtx->billboardMtxF, MTXMODE_APPLY);
    Matrix_Push();
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_magic_dark.c", 632),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    Matrix_RotateZ(sp6C * (M_PI / 32), MTXMODE_APPLY);
    gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);
    Matrix_Pop();
    Matrix_RotateZ(-sp6C * (M_PI / 32), MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_magic_dark.c", 639),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_magic_dark.c", 643);
}

void MagicDark_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Magic_Dark_InitVars = {
        ACTOR_MAGIC_DARK,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(MagicDark),
        (ActorFunc)MagicDark_Init,
        (ActorFunc)MagicDark_Destroy,
        (ActorFunc)MagicDark_OrbUpdate,
        (ActorFunc)MagicDark_OrbDraw,
        (ActorFunc)MagicDark_Reset,
    };

}

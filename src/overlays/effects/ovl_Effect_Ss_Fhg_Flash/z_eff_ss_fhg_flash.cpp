#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_FHG_FLASH_Z_EFF_SS_FHG_FLASH_C
#include "actor_common.h"
/*
 * File: z_eff_ss_fhg_flash.c
 * Overlay: ovl_Effect_Ss_Fhg_Flash
 * Description: Shock and Light Ball Effect
 */

#include "z_eff_ss_fhg_flash.h"
#include "overlays/actors/ovl_Boss_Ganondrof/z_boss_ganondrof.h"
#include "objects/object_fhg/object_fhg.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rAlpha regs[0]
#define rObjBankIdx regs[2]
#define rXZRot regs[3]
#define rParam regs[4]
#define rScale regs[8]

u32 EffectSsFhgFlash_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsFhgFlash_DrawLightBall(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsFhgFlash_UpdateLightBall(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsFhgFlash_DrawShock(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsFhgFlash_UpdateShock(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Fhg_Flash_InitVars = {
    EFFECT_SS_FHG_FLASH,
    EffectSsFhgFlash_Init,
};

extern UNK_TYPE D_809A5178[258];
extern Gfx D_809A5100[15];

u32 EffectSsFhgFlash_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsFhgFlashInitParams* initParams = (EffectSsFhgFlashInitParams*)initParamsx;
    s32 pad;
    s32 objBankIdx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f sp34 = { 0.0f, -1000.0f, 0.0f };
    void* oldSeg6;

    if (initParams->type == FHGFLASH_LIGHTBALL) {
        objBankIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_FHG);

        if ((objBankIdx > -1) && Object_IsLoaded(&globalCtx->objectCtx, objBankIdx)) {
            oldSeg6 = (void*)gSegments[6];
            gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[objBankIdx].vromStart.get());
            pthis->rObjBankIdx = objBankIdx;
            pthis->pos = initParams->pos;
            pthis->velocity = initParams->velocity;
            pthis->accel = initParams->accel;
            pthis->rParam = initParams->param;
            pthis->life = 100;
            pthis->rScale = initParams->scale;
            pthis->rAlpha = 255;
            pthis->draw = EffectSsFhgFlash_DrawLightBall;
            pthis->update = EffectSsFhgFlash_UpdateLightBall;
            pthis->gfx = SEGMENTED_TO_VIRTUAL(gPhantomEnergyBallDL);
            gSegments[6] = (uintptr_t)oldSeg6;
        } else {
            osSyncPrintf("Effect_Ss_Fhg_Flash_ct():pffd->modeエラー\n");
            return 0;
        }
    } else {
        pthis->actor = initParams->actor;
        pthis->velocity = pthis->accel = zeroVec;
        pthis->life = (s16)(Rand_ZeroOne() * 10.0f) + 111;
        pthis->rScale = (s16)Rand_ZeroFloat(initParams->scale) + initParams->scale;
        pthis->rAlpha = 255;
        pthis->draw = EffectSsFhgFlash_DrawShock;
        pthis->update = EffectSsFhgFlash_UpdateShock;
        pthis->rParam = initParams->param;

        if (initParams->param != FHGFLASH_SHOCK_NO_ACTOR) {
            pthis->pos = sp34;
            pthis->gfx = SEGMENTED_TO_VIRTUAL(D_809A5100);
        } else {
            pthis->pos = initParams->pos;
            pthis->gfx = SEGMENTED_TO_VIRTUAL(D_809A5100);
        }
    }
    return 1;
}

static Color_RGB8 sColors[] = {
    { 165, 255, 61 }, { 0, 255, 255 }, { 255, 40, 0 }, { 255, 255, 0 }, { 0, 0, 255 },
    { 255, 0, 255 },  { 255, 150, 0 }, { 0, 0, 0 },    { 0, 0, 0 },
};

void EffectSsFhgFlash_DrawLightBall(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;
    void* object;

    scale = pthis->rScale / 100.0f;
    object = gObjectTable[pthis->rObjBankIdx].vromStart.buffer();

    OPEN_DISPS(gfxCtx, "../z_eff_fhg_flash.c", 268);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    gSegments[6] = (uintptr_t)VIRTUAL_TO_PHYSICAL(object);
    gSPSegment(POLY_XLU_DISP++, 0x06, object);
    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, pthis->rAlpha);
    gDPSetEnvColor(POLY_XLU_DISP++, sColors[pthis->rParam].r, sColors[pthis->rParam].g, sColors[pthis->rParam].b, 0);
    gDPPipeSync(POLY_XLU_DISP++);
    func_800D1FD4(&globalCtx->billboardMtxF);
    Matrix_RotateZ((pthis->rXZRot / 32768.0f) * 3.1416f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_fhg_flash.c", 326),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_fhg_flash.c", 330);
}

void EffectSsFhgFlash_DrawShock(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;

    scale = pthis->rScale / 100.0f;

    OPEN_DISPS(gfxCtx, "../z_eff_fhg_flash.c", 346);

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

    if (pthis->rParam != FHGFLASH_SHOCK_NO_ACTOR) {
        func_80094044(globalCtx->state.gfxCtx);
        Matrix_RotateX((pthis->rXZRot / 32768.0f) * 1.1416f, MTXMODE_APPLY);
        gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2);
    } else {
        func_80093D84(globalCtx->state.gfxCtx);
        func_800D1FD4(&globalCtx->billboardMtxF);
        gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    }

    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, pthis->rAlpha);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 155, 0);
    Matrix_RotateZ((pthis->rXZRot / 32768.0f) * 3.1416f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_fhg_flash.c", 395),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);

    CLOSE_DISPS(gfxCtx, "../z_eff_fhg_flash.c", 399);
}

void EffectSsFhgFlash_UpdateLightBall(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s16 rand = (Rand_ZeroOne() * 20000.0f);

    pthis->rXZRot = (pthis->rXZRot + rand) + 0x4000;

    if (pthis->rScale > 0) {
        pthis->rScale -= 10;

        if (pthis->rScale <= 0) {
            pthis->rScale = 0;
            pthis->life = 0;
        }
    }

    if (pthis->rAlpha > 0) {
        pthis->rAlpha -= 10;

        if (pthis->rAlpha <= 0) {
            pthis->rAlpha = 0;
        }
    }
}

void EffectSsFhgFlash_UpdateShock(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s16 randBodypart;
    Player* player;
    BossGanondrof* phantomGanon;
    s16 rand;

    rand = (Rand_ZeroOne() * 20000.0f);
    pthis->rXZRot = (pthis->rXZRot + rand) + 0x4000;

    if (pthis->rParam == FHGFLASH_SHOCK_PLAYER) {
        player = GET_PLAYER(globalCtx);
        randBodypart = Rand_ZeroFloat(17.9f);
        pthis->pos.x = player->bodyPartsPos[randBodypart].x + Rand_CenteredFloat(10.0f);
        pthis->pos.y = player->bodyPartsPos[randBodypart].y + Rand_CenteredFloat(15.0f);
        pthis->pos.z = player->bodyPartsPos[randBodypart].z + Rand_CenteredFloat(10.0f);
    } else if (pthis->rParam == FHGFLASH_SHOCK_PG) {
        phantomGanon = (BossGanondrof*)pthis->actor;
        randBodypart = Rand_ZeroFloat(23.9f);
        pthis->pos.x = phantomGanon->bodyPartsPos[randBodypart].x + Rand_CenteredFloat(15.0f);
        pthis->pos.y = phantomGanon->bodyPartsPos[randBodypart].y + Rand_CenteredFloat(20.0f);
        pthis->pos.z = phantomGanon->bodyPartsPos[randBodypart].z + Rand_CenteredFloat(15.0f);
    }

    if (pthis->life < 100) {
        pthis->rAlpha -= 50;

        if (pthis->rAlpha < 0) {
            pthis->rAlpha = 0;
            pthis->life = 0;
        }
    }
}

static Vtx D_809A50C0[4] = {
    VTX(-10, -10, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(10, -10, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(10, 10, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-10, 10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_809A5100[15] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(D_809A5178, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0,
                       COMBINED),
    gsSPClearGeometryMode(G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(D_809A50C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static UNK_TYPE D_809A5178[258] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005B3000, 0x00000000, 0x00000000,
    0x00000000, 0x000B0000, 0x07000000, 0x00000000, 0x00000000, 0x005BB64B, 0x3A000000, 0x00000000, 0x00000000,
    0x005B0000, 0x00000000, 0x00000000, 0x00000000, 0x001E00B6, 0xFF5B0000, 0x00000000, 0x00000000, 0x00251F0C,
    0x07000000, 0x0A000000, 0x00000000, 0x00000000, 0xB6FF0000, 0x00000000, 0x00000000, 0x00255B00, 0x071F1E14,
    0x0A000000, 0x00000000, 0x00000000, 0x00457350, 0x00000000, 0x00000000, 0x00295B8C, 0x5B5B0000, 0x00000000,
    0x00000000, 0x00000000, 0x00455C39, 0x0F000000, 0x00000000, 0x0000A1FF, 0x5B000000, 0x00000000, 0x00000000,
    0x00000000, 0x005B5B00, 0x00000000, 0x00000000, 0x005B311C, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x5BB60000, 0x00000000, 0x00000000, 0x5BB63100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFB60000,
    0x00000000, 0x00000046, 0xEA310000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0072B646, 0x00000000,
    0x0000B6A1, 0x81000000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00172E19, 0xBDAB5D41, 0x366BEAEA,
    0x81000000, 0x00000000, 0x00000000, 0x00000000, 0x06000000, 0x00000074, 0xFFFF0500, 0x0A2342B6, 0xFF000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005B0000, 0x03030100, 0x00FF0700, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020503, 0x00000000, 0x00466200, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00076200, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00002962, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00003EA1, 0x62000000, 0x00000000, 0x00000000, 0x0000002E, 0xB6350000,
    0x00000000, 0x00000000, 0x000000EA, 0x46000000, 0x00000000, 0x00000000, 0x00002EFF, 0xFF5A0000, 0x00000000,
    0x00000000, 0x000000FF, 0xFF001700, 0x00000000, 0x00000000, 0x01015BFF, 0xA1A10000, 0x00000000, 0x00000000,
    0x00030046, 0x97732100, 0x00000000, 0x00000000, 0x040CB65E, 0x4A5B4600, 0x00000000, 0x00000003, 0x0C0E8C46,
    0x1C035C00, 0x00000000, 0x00000017, 0x134F5B00, 0x00000046, 0x46000000, 0x00000000, 0x34D20000, 0x0401005B,
    0x00000000, 0x00000000, 0x5BB60000, 0x00000000, 0x30FCB600, 0x0000A1E7, 0x00000001, 0x0100141E, 0x5B000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000A1FF, 0x5B46FF00, 0x00000100, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000000FC, 0xFFA13100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0xB6000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

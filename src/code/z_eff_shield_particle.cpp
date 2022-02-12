#define INTERNAL_SRC_CODE_Z_EFF_SHIELD_PARTICLE_C
#include "global.h"
#include "vt.h"
#include "z64animation.h"
#include "z64effect.h"
#include "z64camera.h"
#include "z64global.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_eff_shield_particle.h"
#include "def/z_effect.h"
#include "def/z_lights.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"
#include "def/graph.h" // FORCE

static Vtx sVertices[5] = {
    VTX(-32, -32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -32, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};

// original name: "EffectShieldParticle_ct"
void EffectShieldParticle_Init(void* thisx, void* initParamsx) {
    EffectShieldParticle* pthis = (EffectShieldParticle*)thisx;
    EffectShieldParticleInit* initParams = (EffectShieldParticleInit*)initParamsx;
    EffectShieldParticleElement* elem;

    if ((pthis != NULL) && (initParams != NULL)) {
        pthis->numElements = initParams->numElements;
        if (pthis->numElements > ARRAY_COUNT(pthis->elements)) {
            osSyncPrintf(VT_FGCOL(RED));
            osSyncPrintf("EffectShieldParticle_ct():パーティクル数がオーバしてます。\n");
            osSyncPrintf(VT_RST);
            return;
        }

        pthis->position = initParams->position;
        pthis->primColorStart = initParams->primColorStart;
        pthis->envColorStart = initParams->envColorStart;
        pthis->primColorMid = initParams->primColorMid;
        pthis->envColorMid = initParams->envColorMid;
        pthis->primColorEnd = initParams->primColorEnd;
        pthis->envColorEnd = initParams->envColorEnd;
        pthis->deceleration = initParams->deceleration;
        pthis->maxInitialSpeed = initParams->maxInitialSpeed;
        pthis->lengthCutoff = initParams->lengthCutoff;
        pthis->duration = initParams->duration;
        pthis->timer = 0;

        for (elem = &pthis->elements[0]; elem < &pthis->elements[pthis->numElements]; elem++) {
            elem->initialSpeed = (Rand_ZeroOne() * (pthis->maxInitialSpeed * 0.5f)) + (pthis->maxInitialSpeed * 0.5f);
            elem->endX = 0.0f;
            elem->startXChange = 0.0f;
            elem->startX = 0.0f;
            elem->endXChange = elem->initialSpeed;
            elem->yaw = Rand_ZeroOne() * 65534.0f;
            elem->pitch = Rand_ZeroOne() * 65534.0f;
        }

        pthis->lightDecay = initParams->lightDecay;
        if (pthis->lightDecay == true) {
            pthis->lightInfo.type = LIGHT_POINT_NOGLOW;
            pthis->lightInfo.params.point = initParams->lightPoint;
            pthis->lightNode =
                LightContext_InsertLight(Effect_GetGlobalCtx(), &Effect_GetGlobalCtx()->lightCtx, &pthis->lightInfo);
        } else {
            pthis->lightNode = NULL;
        }
    }
}

void EffectShieldParticle_Destroy(void* thisx) {
    EffectShieldParticle* pthis = (EffectShieldParticle*)thisx;

    if ((pthis != NULL) && (pthis->lightDecay == true)) {
        if (pthis->lightNode == Effect_GetGlobalCtx()->lightCtx.listHead) {
            Effect_GetGlobalCtx()->lightCtx.listHead = pthis->lightNode->next;
        }
        LightContext_RemoveLight(Effect_GetGlobalCtx(), &Effect_GetGlobalCtx()->lightCtx, pthis->lightNode);
    }
}

s32 EffectShieldParticle_Update(void* thisx) {
    EffectShieldParticle* pthis = (EffectShieldParticle*)thisx;
    EffectShieldParticleElement* elem;

    if (pthis == NULL) {
        return 0;
    }

    for (elem = &pthis->elements[0]; elem < &pthis->elements[pthis->numElements]; elem++) {
        elem->endXChange -= pthis->deceleration;
        if (elem->endXChange < 0.0f) {
            elem->endXChange = 0.0f;
        }

        if (elem->startXChange > 0.0f) {
            elem->startXChange -= pthis->deceleration;
            if (elem->startXChange < 0.0f) {
                elem->startXChange = 0.0f;
            }
        }

        elem->endX += elem->endXChange;
        elem->startX += elem->startXChange;

        if ((elem->startXChange == 0.0f) && (pthis->lengthCutoff < (elem->endX - elem->startX))) {
            elem->startXChange = elem->initialSpeed;
        }
    }

    if (pthis->lightDecay == true) {
        pthis->lightInfo.params.point.radius /= 2;
    }

    pthis->timer++;

    if (pthis->duration < pthis->timer) {
        return 1;
    }

    return 0;
}

void EffectShieldParticle_GetColors(EffectShieldParticle* pthis, Color_RGBA8* primColor, Color_RGBA8* envColor) {
    s32 halfDuration = pthis->duration * 0.5f;
    f32 ratio;

    if (halfDuration == 0) {
        primColor->r = pthis->primColorStart.r;
        primColor->g = pthis->primColorStart.g;
        primColor->b = pthis->primColorStart.b;
        primColor->a = pthis->primColorStart.a;
        envColor->r = pthis->envColorStart.r;
        envColor->g = pthis->envColorStart.g;
        envColor->b = pthis->envColorStart.b;
        envColor->a = pthis->envColorStart.a;
    } else if (pthis->timer < halfDuration) {
        ratio = pthis->timer / (f32)halfDuration;
        primColor->r = pthis->primColorStart.r + (pthis->primColorMid.r - pthis->primColorStart.r) * ratio;
        primColor->g = pthis->primColorStart.g + (pthis->primColorMid.g - pthis->primColorStart.g) * ratio;
        primColor->b = pthis->primColorStart.b + (pthis->primColorMid.b - pthis->primColorStart.b) * ratio;
        primColor->a = pthis->primColorStart.a + (pthis->primColorMid.a - pthis->primColorStart.a) * ratio;
        envColor->r = pthis->envColorStart.r + (pthis->envColorMid.r - pthis->envColorStart.r) * ratio;
        envColor->g = pthis->envColorStart.g + (pthis->envColorMid.g - pthis->envColorStart.g) * ratio;
        envColor->b = pthis->envColorStart.b + (pthis->envColorMid.b - pthis->envColorStart.b) * ratio;
        envColor->a = pthis->envColorStart.a + (pthis->envColorMid.a - pthis->envColorStart.a) * ratio;
    } else {
        ratio = (pthis->timer - halfDuration) / (f32)halfDuration;
        primColor->r = pthis->primColorMid.r + (pthis->primColorEnd.r - pthis->primColorMid.r) * ratio;
        primColor->g = pthis->primColorMid.g + (pthis->primColorEnd.g - pthis->primColorMid.g) * ratio;
        primColor->b = pthis->primColorMid.b + (pthis->primColorEnd.b - pthis->primColorMid.b) * ratio;
        primColor->a = pthis->primColorMid.a + (pthis->primColorEnd.a - pthis->primColorMid.a) * ratio;
        envColor->r = pthis->envColorMid.r + (pthis->envColorEnd.r - pthis->envColorMid.r) * ratio;
        envColor->g = pthis->envColorMid.g + (pthis->envColorEnd.g - pthis->envColorMid.g) * ratio;
        envColor->b = pthis->envColorMid.b + (pthis->envColorEnd.b - pthis->envColorMid.b) * ratio;
        envColor->a = pthis->envColorMid.a + (pthis->envColorEnd.a - pthis->envColorMid.a) * ratio;
    }
}

void EffectShieldParticle_Draw(void* thisx, GraphicsContext* gfxCtx) {
    EffectShieldParticle* pthis = (EffectShieldParticle*)thisx;
    EffectShieldParticleElement* elem;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;

    OPEN_DISPS(gfxCtx, "../z_eff_shield_particle.c", 272);

    if (pthis != NULL) {
        POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0x26);

        gDPSetCycleType(POLY_XLU_DISP++, G_CYC_2CYCLE);
        gDPPipeSync(POLY_XLU_DISP++);
        gSPTexture(POLY_XLU_DISP++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gDPLoadTextureBlock(POLY_XLU_DISP++, gUnknownCircle6Tex, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        gDPSetCombineLERP(POLY_XLU_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0, 0, 0,
                          0, COMBINED, 0, 0, 0, COMBINED);
        gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
        gSPClearGeometryMode(POLY_XLU_DISP++, G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
        gSPSetGeometryMode(POLY_XLU_DISP++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);

        EffectShieldParticle_GetColors(pthis, &primColor, &envColor);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, primColor.r, primColor.g, primColor.b, primColor.a);
        gDPSetEnvColor(POLY_XLU_DISP++, envColor.r, envColor.g, envColor.b, envColor.a);
        gDPPipeSync(POLY_XLU_DISP++);

        for (elem = &pthis->elements[0]; elem < &pthis->elements[pthis->numElements]; elem++) {
            Mtx* mtx;
            MtxF sp104;
            MtxF spC4;
            MtxF sp84;
            f32 temp1 = (s16)((elem->endX + elem->startX) * 0.5f);
            f32 temp2 = elem->endX - elem->startX;
            f32 temp3 = (s16)((temp2 * (1.0f / 64.0f)) / 0.02f);

            if (temp3 < 1.0f) {
                temp3 = 1.0f;
            }

            SkinMatrix_SetTranslate(&spC4, pthis->position.x, pthis->position.y, pthis->position.z);
            SkinMatrix_SetRotateZYX(&sp104, 0, elem->yaw, 0);
            SkinMatrix_MtxFMtxFMult(&spC4, &sp104, &sp84);
            SkinMatrix_SetRotateZYX(&sp104, 0, 0, elem->pitch);
            SkinMatrix_MtxFMtxFMult(&sp84, &sp104, &spC4);
            SkinMatrix_SetTranslate(&sp104, temp1, 0.0f, 0.0f);
            SkinMatrix_MtxFMtxFMult(&spC4, &sp104, &sp84);
            SkinMatrix_SetScale(&sp104, temp3 * 0.02f, 0.02f, 0.02f);
            SkinMatrix_MtxFMtxFMult(&sp84, &sp104, &spC4);

            mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &spC4);
            if (mtx == NULL) {
                break;
            }

            gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(POLY_XLU_DISP++, sVertices, 4, 0);
            gSP2Triangles(POLY_XLU_DISP++, 0, 1, 2, 0, 0, 3, 1, 0);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_shield_particle.c", 359);
}

#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_ICE_PIECE_Z_EFF_SS_ICE_PIECE_C
#include "actor_common.h"
/*
 * File: z_eff_ss_ice_piece.c
 * Overlay: ovl_Effect_Ss_Ice_Piece
 * Description: Ice Shards
 */

#include "z_eff_ss_ice_piece.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_rcp.h"

#define rLifespan regs[0]
#define rYaw regs[1]
#define rPitch regs[2]
#define rRotSpeed regs[3]
#define rScale regs[4]

u32 EffectSsIcePiece_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsIcePiece_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsIcePiece_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Ice_Piece_InitVars = {
    EFFECT_SS_ICE_PIECE,
    EffectSsIcePiece_Init,
};

u32 EffectSsIcePiece_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsIcePieceInitParams* initParams = (EffectSsIcePieceInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->vec = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->life = initParams->life;
    pthis->draw = EffectSsIcePiece_Draw;
    pthis->update = EffectSsIcePiece_Update;
    pthis->rLifespan = initParams->life;
    pthis->rScale = initParams->scale * 100.0f;
    pthis->rYaw = Math_Atan2S(initParams->velocity.z, initParams->velocity.x);
    pthis->rPitch = 0;
    pthis->rRotSpeed =
        ((fabsf(initParams->velocity.x) + fabsf(initParams->velocity.y)) * 100.0f) * (Rand_ZeroFloat(1.0f) + 0.5f);

    return 1;
}

void EffectSsIcePiece_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;
    const auto& frames = globalCtx->state.frames;
    f32 alpha;

    scale = pthis->rScale * 0.01f;

    OPEN_DISPS(gfxCtx, "../z_eff_ice_piece.c", 161);

    if ((pthis->rLifespan > 0) && (pthis->life < (pthis->rLifespan >> 1))) {
        alpha = ((pthis->life * 2.0f) / pthis->rLifespan);
        alpha *= 255.0f;
    } else {
        alpha = 255.0f;
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_RotateY(pthis->rYaw * (M_PI / 0x8000), MTXMODE_APPLY);
    Matrix_RotateX(pthis->rPitch * (M_PI / 0x8000), MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_ice_piece.c", 185),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 50, 100, (s32)alpha & 0xFF);
    func_8003435C(&pthis->pos, globalCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, (frames * 1) % 256, 0x20, 0x10, 1, 0, (frames * 2) % 256,
                                0x40, 0x20));
    gSPDisplayList(POLY_XLU_DISP++, gEffIceFragment1DL);

    CLOSE_DISPS(gfxCtx, "../z_eff_ice_piece.c", 209);
}

void EffectSsIcePiece_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    pthis->rPitch += pthis->rRotSpeed;
    pthis->velocity.x = pthis->velocity.x * 0.85f;
    pthis->velocity.y = pthis->velocity.y * 0.85f;
    pthis->velocity.z = pthis->velocity.z * 0.85f;
}

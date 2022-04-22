#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_VB_SIMA_Z_BG_VB_SIMA_C
#include "actor_common.h"
/*
 * File: z_bg_vb_sima.c
 * Overlay: ovl_Bg_Vb_Sima
 * Description: Volvagia's platform
 */

#include "z_bg_vb_sima.h"
#include "objects/object_fd/object_fd.h"
#include "overlays/actors/ovl_Boss_Fd/z_boss_fd.h"
#include "def/code_80043480.h"
#include "def/audio_bank.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgVbSima_Init(Actor* thisx, GlobalContext* globalCtx);
void BgVbSima_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgVbSima_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgVbSima_Update(Actor* thisx, GlobalContext* globalCtx);
void BgVbSima_Draw(Actor* thisx, GlobalContext* globalCtx);

static Color_RGBA8 colorYellow_27 = { 255, 255, 0, 255 };

static Color_RGBA8 colorRed_27 = { 255, 10, 0, 255 };


ActorInit Bg_Vb_Sima_InitVars = {
    ACTOR_BG_VB_SIMA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_FD,
    sizeof(BgVbSima),
    (ActorFunc)BgVbSima_Init,
    (ActorFunc)BgVbSima_Destroy,
    (ActorFunc)BgVbSima_Update,
    (ActorFunc)BgVbSima_Draw,
    (ActorFunc)BgVbSima_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgVbSima_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgVbSima* pthis = (BgVbSima*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gVolvagiaPlatformCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void BgVbSima_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgVbSima* pthis = (BgVbSima*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgVbSima_SpawnEmber(BossFdEffect* effect, Vec3f* position, Vec3f* velocity, Vec3f* acceleration, f32 scale) {
    s16 i;

    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_NONE) {
            effect->type = BFD_FX_EMBER;
            effect->pos = *position;
            effect->velocity = *velocity;
            effect->accel = *acceleration;
            effect->scale = scale / 1000.0f;
            effect->alpha = 255;
            effect->timer1 = (s16)Rand_ZeroFloat(10.0f);
            break;
        }
    }
}

void BgVbSima_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgVbSima* pthis = (BgVbSima*)thisx;
    BossFd* bossFd = (BossFd*)pthis->dyna.actor.parent;
    f32 minus1 = -1.0f;

    pthis->shakeTimer++;
    if (!Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
        s32 signal = bossFd->platformSignal;

        if (signal == VBSIMA_COLLAPSE) {
            Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, -1000.0f, 1.0f, 1.5f, 0.0f);
            pthis->dyna.actor.world.pos.z += 2.0f * Math_CosS(pthis->shakeTimer * 0x8000);
            pthis->dyna.actor.shape.rot.x = (s16)Math_SinS(pthis->shakeTimer * 0x7000) * 0x37;
            pthis->dyna.actor.shape.rot.z = (s16)Math_SinS(pthis->shakeTimer * 0x5000) * 0x37;
            Audio_PlaySoundGeneral(NA_SE_EV_BLOCKSINK - SFX_FLAG, &pthis->dyna.actor.projectedPos, 4, &D_801333E0,
                                   &D_801333E0, &gReverbAdd2);
        } else if (signal == VBSIMA_KILL) {
            Actor_Kill(&pthis->dyna.actor);
        }
        if (bossFd->platformSignal != VBSIMA_STAND) {
            s16 i2;
            s16 i1;
            Vec3f splashVel;
            Vec3f splashAcc;
            Vec3f splashPos;
            Vec3f emberPos;
            Vec3f emberVel;
            Vec3f emberAcc;
            f32 edgeX;
            f32 edgeZ;

            for (i1 = 0; i1 < 10; i1++) {
                if (Rand_ZeroOne() < 0.33f) {
                    edgeX = -80.0f;
                    edgeZ = Rand_CenteredFloat(160.0f);
                } else {
                    edgeZ = 80.0f;
                    if (Rand_ZeroOne() < 0.5f) {
                        edgeZ = 80.0f * minus1;
                    }
                    edgeX = Rand_CenteredFloat(160.0f);
                }

                splashVel.x = edgeX * 0.05f;
                splashVel.y = Rand_ZeroFloat(3.0f) + 3.0f;
                splashVel.z = edgeZ * 0.05f;

                splashAcc.y = -0.3f;
                splashAcc.x = splashVel.x;
                splashAcc.z = splashVel.z;

                splashPos.x = pthis->dyna.actor.world.pos.x + edgeX;
                splashPos.y = -80.0f;
                splashPos.z = pthis->dyna.actor.world.pos.z + edgeZ;

                func_8002836C(globalCtx, &splashPos, &splashVel, &splashAcc, &colorYellow_27, &colorRed_27,
                              (s16)Rand_ZeroFloat(100.0f) + 500, 10, 20);

                for (i2 = 0; i2 < 3; i2++) {
                    emberVel.x = splashVel.x;
                    emberVel.y = Rand_ZeroFloat(5.0f);
                    emberVel.z = splashVel.z;

                    emberAcc.y = 0.4f;
                    emberAcc.x = Rand_CenteredFloat(0.5f);
                    emberAcc.z = Rand_CenteredFloat(0.5f);

                    emberPos.x = Rand_CenteredFloat(60.0f) + splashPos.x;
                    emberPos.y = Rand_ZeroFloat(40.0f) + splashPos.y;
                    emberPos.z = Rand_CenteredFloat(60.0f) + splashPos.z;

                    BgVbSima_SpawnEmber(bossFd->effects, &emberPos, &emberVel, &emberAcc,
                                        (s16)Rand_ZeroFloat(2.0f) + 8);
                }
            }
        }
    }
}

void BgVbSima_Draw(Actor* thisx, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_vb_sima.c", 285);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_vb_sima.c", 291),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gVolvagiaPlatformDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_vb_sima.c", 296);
}

void BgVbSima_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    colorYellow_27 = { 255, 255, 0, 255 };

    colorRed_27 = { 255, 10, 0, 255 };

    Bg_Vb_Sima_InitVars = {
        ACTOR_BG_VB_SIMA,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_FD,
        sizeof(BgVbSima),
        (ActorFunc)BgVbSima_Init,
        (ActorFunc)BgVbSima_Destroy,
        (ActorFunc)BgVbSima_Update,
        (ActorFunc)BgVbSima_Draw,
        (ActorFunc)BgVbSima_Reset,
    };

}

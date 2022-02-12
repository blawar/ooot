#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SIOFUKI_Z_EN_SIOFUKI_C
#include "actor_common.h"
/*
 * File: z_en_siofuki.c
 * Overlay: ovl_En_Siofuki
 * Description: Water Spout
 */

#include "z_en_siofuki.h"
#include "objects/object_siofuki/object_siofuki.h"
#include "def/code_80043480.h"
#include "def/code_800EC960.h"
#include "def/code_800FCE80.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnSiofuki_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSiofuki_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSiofuki_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSiofuki_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AFC34C(EnSiofuki* pthis, GlobalContext* globalCtx);
void func_80AFC544(EnSiofuki* pthis, GlobalContext* globalCtx);
void func_80AFC478(EnSiofuki* pthis, GlobalContext* globalCtx);

ActorInit En_Siofuki_InitVars = {
    ACTOR_EN_SIOFUKI,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SIOFUKI,
    sizeof(EnSiofuki),
    (ActorFunc)EnSiofuki_Init,
    (ActorFunc)EnSiofuki_Destroy,
    (ActorFunc)EnSiofuki_Update,
    (ActorFunc)EnSiofuki_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void EnSiofuki_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSiofuki* pthis = (EnSiofuki*)thisx;
    s32 type;
    CollisionHeader* colHeader = NULL;
    s32 pad;

    if ((thisx->room == 10) && Flags_GetSwitch(globalCtx, 0x1E)) {
        Actor_Kill(thisx);
        return;
    }

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&object_siofuki_Col_000D78, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    pthis->sfxFlags |= 1;

    type = ((u16)thisx->params >> 0xC) & 0xF;
    if (!((type == 0) || (type == 1))) {
        Actor_Kill(thisx);
        return;
    }

    pthis->initPosY = thisx->world.pos.y;
    pthis->unk_174 = 35.0f;
    pthis->unk_170 = -6058.0f + pthis->unk_174;

    if (thisx->shape.rot.x != 0) {
        pthis->maxHeight = thisx->shape.rot.x * 40.0f;
        pthis->currentHeight = pthis->maxHeight;
    }
    pthis->activeTime = 0;
    if (thisx->shape.rot.y != 0) {
        pthis->activeTime = thisx->shape.rot.y;
    }
    if (thisx->shape.rot.z != 0) {
        thisx->scale.x = thisx->shape.rot.z * (1.0f / 1.73f) * 0.1f;
        thisx->scale.z = thisx->shape.rot.z * 0.5f * 0.1f;
    }

    thisx->world.rot.x = 0;
    thisx->world.rot.y = 0;
    thisx->world.rot.z = 0;
    thisx->shape.rot.x = 0;
    thisx->shape.rot.y = 0;
    thisx->shape.rot.z = 0;

    type = ((u16)thisx->params >> 0xC) & 0xF;
    if (type == EN_SIOFUKI_RAISING) {
        pthis->currentHeight = 10.0f;
        pthis->targetHeight = 10.0f;
        pthis->actionFunc = func_80AFC34C;
    } else if (type == EN_SIOFUKI_LOWERING) {
        if (Flags_GetTreasure(globalCtx, (u16)thisx->params & 0x3F)) {
            pthis->currentHeight = -45.0f;
            pthis->targetHeight = -45.0f;
            pthis->actionFunc = func_80AFC544;
        } else {
            pthis->targetHeight = pthis->currentHeight;
            pthis->actionFunc = func_80AFC478;
        }
    }
}

void EnSiofuki_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSiofuki* pthis = (EnSiofuki*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_80AFBDC8(EnSiofuki* pthis, GlobalContext* globalCtx) {
    pthis->oscillation = sinf((globalCtx->gameplayFrames & 0x1F) / 32.0f * M_PI * 2.0f) * 4.0f;
    pthis->unk_170 = pthis->unk_174 * 10.0f + -6058.0f - pthis->oscillation * 10.0f;
    pthis->unk_174 = 35.0f;
    pthis->dyna.actor.world.pos.y = pthis->initPosY + pthis->currentHeight + pthis->oscillation;
}

void func_80AFBE8C(EnSiofuki* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 dX;
    f32 dY;
    f32 dZ;
    s16 angle;
    s16 dAngle;
    f32 dist2d;
    f32 speedScale;

    dX = player->actor.world.pos.x - pthis->dyna.actor.world.pos.x;
    dY = player->actor.world.pos.y - pthis->dyna.actor.world.pos.y;
    dZ = player->actor.world.pos.z - pthis->dyna.actor.world.pos.z;

    if ((dX > (pthis->dyna.actor.scale.x * -346.0f)) && (dX < (pthis->dyna.actor.scale.x * 346.0f)) &&
        (dZ > (pthis->dyna.actor.scale.z * -400.0f)) && (dZ < (pthis->dyna.actor.scale.z * 400.0f)) && (dY < 0.0f)) {
        if (func_8004356C(&pthis->dyna)) {
            if (pthis->splashTimer <= 0) {
                EffectSsGSplash_Spawn(globalCtx, &player->actor.world.pos, NULL, NULL, 1, 1);
                pthis->splashTimer = 10;
            } else {
                pthis->splashTimer--;
            }

            pthis->applySpeed = false;
            pthis->appliedSpeed = 0.0f;
            pthis->targetAppliedSpeed = 0.0f;
        } else {
            dist2d = sqrtf(SQ(dX) + SQ(dZ));
            pthis->applySpeed = true;
            pthis->splashTimer = 0;
            angle = Math_FAtan2F(dX, dZ) * (0x8000 / M_PI);
            dAngle = (player->actor.world.rot.y ^ 0x8000) - angle;
            player->actor.gravity = 0.0f;
            player->actor.velocity.y = 0.0f;
            Math_SmoothStepToF(&player->actor.world.pos.y, pthis->dyna.actor.world.pos.y, 0.5f, 4.0f, 1.0f);

            if ((dAngle < 0x4000) && (dAngle > -0x4000)) {
                pthis->appliedYaw = player->actor.world.rot.y ^ 0x8000;
                speedScale = dist2d / (pthis->dyna.actor.scale.x * 40.0f * 10.0f);
                speedScale = CLAMP_MIN(speedScale, 0.0f);
                speedScale = CLAMP_MAX(speedScale, 1.0f);
                player->linearVelocity *= speedScale;
                Math_ApproachF(&pthis->targetAppliedSpeed, 3.0f, 1.0f, 1.0f);
                Math_ApproachF(&pthis->appliedSpeed, pthis->targetAppliedSpeed, 1.0f, 0.3f * speedScale);
            } else {
                pthis->appliedYaw = player->actor.world.rot.y;
                player->linearVelocity /= 2.0f;
                Math_ApproachF(&pthis->targetAppliedSpeed, 3.0f, 1.0f, 1.0f);
                Math_ApproachF(&pthis->appliedSpeed, pthis->targetAppliedSpeed, 1.0f, 0.1f);
            }

            player->windDirection = pthis->appliedYaw;
            player->windSpeed = pthis->appliedSpeed;
        }
    } else {
        if (pthis->applySpeed) {
            player->linearVelocity = pthis->appliedSpeed + player->linearVelocity;
            player->currentYaw = pthis->appliedYaw;
        }

        pthis->targetAppliedSpeed = 0.0f;
        pthis->appliedSpeed = 0.0f;
        pthis->applySpeed = false;
    }
}

void func_80AFC1D0(EnSiofuki* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToF(&pthis->currentHeight, pthis->targetHeight, 0.8f, 3.0f, 0.01f);
}

void func_80AFC218(EnSiofuki* pthis, GlobalContext* globalCtx) {
    func_80AFBDC8(pthis, globalCtx);
    func_80AFBE8C(pthis, globalCtx);
    func_80AFC1D0(pthis, globalCtx);

    pthis->timer--;
    if (pthis->timer < 0) {
        Flags_UnsetSwitch(globalCtx, ((u16)pthis->dyna.actor.params >> 6) & 0x3F);
        switch (((u16)pthis->dyna.actor.params >> 0xC) & 0xF) {
            case EN_SIOFUKI_RAISING:
                pthis->targetHeight = 10.0f;
                pthis->actionFunc = func_80AFC34C;
                break;
            case EN_SIOFUKI_LOWERING:
                pthis->targetHeight = pthis->maxHeight;
                pthis->actionFunc = func_80AFC478;
                break;
        }
    } else {
        func_8002F994(&pthis->dyna.actor, pthis->timer);
    }

    if (((((u16)pthis->dyna.actor.params >> 0xC) & 0xF) == EN_SIOFUKI_LOWERING) &&
        Flags_GetTreasure(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
        pthis->currentHeight = -45.0f;
        pthis->targetHeight = -45.0f;
        Flags_UnsetSwitch(globalCtx, ((u16)pthis->dyna.actor.params >> 6) & 0x3F);
        pthis->actionFunc = func_80AFC544;
    }
}

void func_80AFC34C(EnSiofuki* pthis, GlobalContext* globalCtx) {
    func_80AFBDC8(pthis, globalCtx);
    func_80AFBE8C(pthis, globalCtx);
    func_80AFC1D0(pthis, globalCtx);

    if (Flags_GetSwitch(globalCtx, ((u16)pthis->dyna.actor.params >> 6) & 0x3F)) {
        pthis->targetHeight = 400.0f;
        pthis->timer = 300;
        pthis->actionFunc = func_80AFC218;
    }
}

void func_80AFC3C8(EnSiofuki* pthis, GlobalContext* globalCtx) {
    func_80AFBDC8(pthis, globalCtx);
    func_80AFBE8C(pthis, globalCtx);
    func_80AFC1D0(pthis, globalCtx);

    pthis->timer--;
    if (pthis->timer < 0) {
        pthis->timer = pthis->activeTime * 20;
        pthis->targetHeight = -45.0f;
        pthis->actionFunc = func_80AFC218;
    }

    if (Flags_GetTreasure(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
        pthis->currentHeight = -45.0f;
        pthis->targetHeight = -45.0f;
        pthis->actionFunc = func_80AFC544;
    }
}

void func_80AFC478(EnSiofuki* pthis, GlobalContext* globalCtx) {
    func_80AFBDC8(pthis, globalCtx);
    func_80AFBE8C(pthis, globalCtx);
    func_80AFC1D0(pthis, globalCtx);

    if (((u16)pthis->dyna.actor.params >> 0xC & 0xF) == EN_SIOFUKI_LOWERING) {
        if (Flags_GetSwitch(globalCtx, ((u16)pthis->dyna.actor.params >> 6) & 0x3F)) {
            pthis->timer = 20;
            pthis->actionFunc = func_80AFC3C8;
            OnePointCutscene_Init(globalCtx, 5010, 40, &pthis->dyna.actor, MAIN_CAM);
        }

        if (Flags_GetTreasure(globalCtx, (u16)pthis->dyna.actor.params & 0x3F)) {
            pthis->currentHeight = -45.0f;
            pthis->targetHeight = -45.0f;
            pthis->actionFunc = func_80AFC544;
        }
    }
}

void func_80AFC544(EnSiofuki* pthis, GlobalContext* globalCtx) {
    func_80AFBDC8(pthis, globalCtx);
    func_80AFC1D0(pthis, globalCtx);
}

void EnSiofuki_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSiofuki* pthis = (EnSiofuki*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnSiofuki_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnSiofuki* pthis = (EnSiofuki*)thisx;
    u32 x;
    u32 y;
    u32 gameplayFrames = globalCtx->gameplayFrames;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_siofuki.c", 654);
    func_80093D84(globalCtx->state.gfxCtx);
    Matrix_Translate(0.0f, pthis->unk_170, 0.0f, MTXMODE_APPLY);
    Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_siofuki.c", 662),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    x = gameplayFrames * 15;
    y = gameplayFrames * -15;
    gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, x, y, 64, 64, 1, x, y, 64, 64));
    gSPDisplayList(POLY_XLU_DISP++, object_siofuki_DL_000B70);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_siofuki.c", 674);

    if (pthis->sfxFlags & 1) {
        f32 heightRatio;
        switch (((u16)thisx->params >> 0xC) & 0xF) {
            case EN_SIOFUKI_RAISING:
                heightRatio = (pthis->currentHeight - 10.0f) / (400.0f - 10.0f);
                func_800F436C(&thisx->projectedPos, NA_SE_EV_FOUNTAIN - SFX_FLAG, 1.0f + heightRatio);
                break;
            case EN_SIOFUKI_LOWERING:
                if (pthis->currentHeight > -35.0f) {
                    heightRatio = (pthis->currentHeight - -35.0f) / (pthis->maxHeight - -35.0f);
                    func_800F436C(&thisx->projectedPos, NA_SE_EV_FOUNTAIN - SFX_FLAG, 1.0f + heightRatio);
                }
                break;
        }
    }
}

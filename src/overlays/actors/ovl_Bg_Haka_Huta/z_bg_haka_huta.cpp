#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_HUTA_Z_BG_HAKA_HUTA_C
#include "actor_common.h"
/*
 * File: z_bg_haka_huta.c
 * Overlay: ovl_Bg_Haka_Huta
 * Description: Coffin Lid
 */

#include "z_bg_haka_huta.h"
#include "objects/object_hakach_objects/object_hakach_objects.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_quake.h"

#define FLAGS ACTOR_FLAG_4

void BgHakaHuta_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHakaHuta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaHuta_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgHakaHuta_SpawnDust(BgHakaHuta* pthis, GlobalContext* globalCtx);
void BgHakaHuta_PlaySound(BgHakaHuta* pthis, GlobalContext* globalCtx, u16 sfx);
void BgHakaHuta_SpawnEnemies(BgHakaHuta* pthis, GlobalContext* globalCtx);
void BgHakaHuta_Open(BgHakaHuta* pthis, GlobalContext* globalCtx);
void BgHakaHuta_SlideOpen(BgHakaHuta* pthis, GlobalContext* globalCtx);
void func_8087D720(BgHakaHuta* pthis, GlobalContext* globalCtx);
void BgHakaHuta_DoNothing(BgHakaHuta* pthis, GlobalContext* globalCtx);

static Vec3f sEffectAccel_35[] = { 0.0f, 0.0f, 0.0f };

static Color_RGBA8 primColor_35 = { 30, 20, 50, 255 };

static Color_RGBA8 envColor_35 = { 0, 0, 0, 255 };

static Vec3f D_8087D958_40 = { 30.0f, 0.0f, 0.0f };

static Vec3f D_8087D964_40 = { 0.03258f, 0.3258f, -0.9449f };


ActorInit Bg_Haka_Huta_InitVars = {
    ACTOR_BG_HAKA_HUTA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKACH_OBJECTS,
    sizeof(BgHakaHuta),
    (ActorFunc)BgHakaHuta_Init,
    (ActorFunc)BgHakaHuta_Destroy,
    (ActorFunc)BgHakaHuta_Update,
    (ActorFunc)BgHakaHuta_Draw,
    (ActorFunc)BgHakaHuta_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaHuta_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaHuta* pthis = (BgHakaHuta*)thisx;
    s16 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    CollisionHeader_GetVirtual(&gBotwCoffinLidCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    pthis->unk_16A = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    if (Flags_GetSwitch(globalCtx, thisx->params)) {
        pthis->counter = -1;
        pthis->actionFunc = func_8087D720;
    } else {
        pthis->actionFunc = BgHakaHuta_SpawnEnemies;
    }
}

void BgHakaHuta_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaHuta* pthis = (BgHakaHuta*)thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void BgHakaHuta_SpawnDust(BgHakaHuta* pthis, GlobalContext* globalCtx) {
    f32 scale;
    f32 phi_f20;
    Vec3f effectPos;
    Vec3f effectVel;
    s32 i;
    f32 new_Xpos;
    f32 xPosOffset;

    phi_f20 = (pthis->dyna.actor.world.rot.y == 0) ? 1.0f : -1.0f;
    effectVel.y = 0.0f;
    effectVel.z = 0.0f;
    effectVel.x = -0.5f * phi_f20;
    effectPos.y = pthis->dyna.actor.world.pos.y;
    effectPos.z = pthis->dyna.actor.world.pos.z;
    new_Xpos = 50 - ((pthis->dyna.actor.world.pos.x - pthis->dyna.actor.home.pos.x) * phi_f20);
    xPosOffset = new_Xpos * phi_f20;

    for (i = 0; i < 4; i++) {
        if (i == 2) {
            effectPos.z += 120.0f * phi_f20;
        }
        effectPos.x = pthis->dyna.actor.home.pos.x - (Rand_ZeroOne() * xPosOffset);
        scale = ((Rand_ZeroOne() * 10.0f) + 50.0f);
        func_8002829C(globalCtx, &effectPos, &effectVel, sEffectAccel_35, &primColor_35, &envColor_35, scale, 0xA);
    }
}

void BgHakaHuta_PlaySound(BgHakaHuta* pthis, GlobalContext* globalCtx, u16 sfx) {
    Vec3f pos;

    pos.z = (pthis->dyna.actor.shape.rot.y == 0) ? pthis->dyna.actor.world.pos.z + 120.0f
                                                : pthis->dyna.actor.world.pos.z - 120.0f;
    pos.x = pthis->dyna.actor.world.pos.x;
    pos.y = pthis->dyna.actor.world.pos.y;
    Audio_PlaySoundAtPosition(globalCtx, &pos, 30, sfx);
}

void BgHakaHuta_SpawnEnemies(BgHakaHuta* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params) && !Player_InCsMode(globalCtx)) {
        pthis->counter = 25;
        pthis->actionFunc = BgHakaHuta_Open;
        OnePointCutscene_Init(globalCtx, 6001, 999, &pthis->dyna.actor, MAIN_CAM);
        if (pthis->unk_16A == 2) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_FIREFLY,
                        (pthis->dyna.actor.world.pos.x + (-25.0f) * Math_CosS(pthis->dyna.actor.shape.rot.y) +
                         40.0f * Math_SinS(pthis->dyna.actor.shape.rot.y)),
                        pthis->dyna.actor.world.pos.y - 10.0f,
                        (pthis->dyna.actor.world.pos.z - (-25.0f) * Math_SinS(pthis->dyna.actor.shape.rot.y) +
                         Math_CosS(pthis->dyna.actor.shape.rot.y) * 40.0f),
                        0, pthis->dyna.actor.shape.rot.y + 0x8000, 0, 2);

            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_FIREFLY,
                        (pthis->dyna.actor.world.pos.x + (-25.0f) * (Math_CosS(pthis->dyna.actor.shape.rot.y)) +
                         Math_SinS(pthis->dyna.actor.shape.rot.y) * 80.0f),
                        pthis->dyna.actor.world.pos.y - 10.0f,
                        (pthis->dyna.actor.world.pos.z - (-25.0f) * (Math_SinS(pthis->dyna.actor.shape.rot.y)) +
                         Math_CosS(pthis->dyna.actor.shape.rot.y) * 80.0f),
                        0, pthis->dyna.actor.shape.rot.y, 0, 2);

        } else if (pthis->unk_16A == 1) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_RD,
                        (pthis->dyna.actor.home.pos.x + (-25.0f) * (Math_CosS(pthis->dyna.actor.shape.rot.y)) +
                         Math_SinS(pthis->dyna.actor.shape.rot.y) * 100.0f),
                        pthis->dyna.actor.home.pos.y - 40.0f,
                        (pthis->dyna.actor.home.pos.z - (-25.0f) * (Math_SinS(pthis->dyna.actor.shape.rot.y)) +
                         Math_CosS(pthis->dyna.actor.shape.rot.y) * 100.0f),
                        0, pthis->dyna.actor.shape.rot.y, 0, 0xFD);
        }
    }
}

void BgHakaHuta_Open(BgHakaHuta* pthis, GlobalContext* globalCtx) {
    f32 posOffset;

    if (pthis->counter != 0) {
        pthis->counter--;
    }
    posOffset = (pthis->dyna.actor.world.rot.y == 0) ? 4.0f : -4.0f;
    Math_StepToF(&pthis->dyna.actor.world.pos.x, pthis->dyna.actor.home.pos.x + posOffset, 2.0f);
    if (pthis->counter == 0) {
        pthis->counter = 37;
        BgHakaHuta_PlaySound(pthis, globalCtx, NA_SE_EV_COFFIN_CAP_OPEN);
        pthis->actionFunc = BgHakaHuta_SlideOpen;
    }
}

void BgHakaHuta_SlideOpen(BgHakaHuta* pthis, GlobalContext* globalCtx) {
    f32 posOffset;

    if (pthis->counter != 0) {
        pthis->counter--;
    }
    posOffset = (pthis->dyna.actor.world.rot.y == 0) ? 24.0f : -24.0f;
    if (!Math_StepToF(&pthis->dyna.actor.world.pos.x, pthis->dyna.actor.home.pos.x + posOffset, 0.5f)) {
        BgHakaHuta_SpawnDust(pthis, globalCtx);
    }
    if (pthis->counter == 0) {
        BgHakaHuta_PlaySound(pthis, globalCtx, NA_SE_EV_COFFIN_CAP_BOUND);
        pthis->actionFunc = func_8087D720;
    }
}

void func_8087D720(BgHakaHuta* pthis, GlobalContext* globalCtx) {
    MtxF mtx;
    Vec3f vec;
    s32 quakeIndex;

    pthis->counter++;
    if (pthis->counter == 6) {
        pthis->actionFunc = BgHakaHuta_DoNothing;
        quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 3);
        Quake_SetSpeed(quakeIndex, 0x7530);
        Quake_SetQuakeValues(quakeIndex, 4, 0, 0, 0);
        Quake_SetCountdown(quakeIndex, 2);
    } else if (pthis->counter == 0) {
        pthis->counter = 6;
        pthis->actionFunc = BgHakaHuta_DoNothing;
    }

    D_8087D958_40.x = pthis->counter + 24.0f;
    if (D_8087D958_40.x > 30.0f) {
        D_8087D958_40.x = 30.0f;
    }
    Matrix_RotateY(pthis->dyna.actor.world.rot.y * (M_PI / 0x8000), MTXMODE_NEW);
    Matrix_RotateAxis(pthis->counter * (191 * M_PI / 3750), &D_8087D964_40, MTXMODE_APPLY);
    Matrix_MultVec3f(&D_8087D958_40, &vec);
    pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x + vec.x;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + vec.y;
    pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z + vec.z;
    Matrix_Get(&mtx);
    Matrix_MtxFToYXZRotS(&mtx, &pthis->dyna.actor.shape.rot, 0);
}

void BgHakaHuta_DoNothing(BgHakaHuta* pthis, GlobalContext* globalCtx) {
}

void BgHakaHuta_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaHuta* pthis = (BgHakaHuta*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHakaHuta_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gBotwCoffinLidDL);
}

void BgHakaHuta_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    primColor_35 = { 30, 20, 50, 255 };

    envColor_35 = { 0, 0, 0, 255 };

    D_8087D958_40 = { 30.0f, 0.0f, 0.0f };

    D_8087D964_40 = { 0.03258f, 0.3258f, -0.9449f };

    Bg_Haka_Huta_InitVars = {
        ACTOR_BG_HAKA_HUTA,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HAKACH_OBJECTS,
        sizeof(BgHakaHuta),
        (ActorFunc)BgHakaHuta_Init,
        (ActorFunc)BgHakaHuta_Destroy,
        (ActorFunc)BgHakaHuta_Update,
        (ActorFunc)BgHakaHuta_Draw,
        (ActorFunc)BgHakaHuta_Reset,
    };

}

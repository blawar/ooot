#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SYATEKI_NIW_Z_EN_SYATEKI_NIW_C
#include "actor_common.h"
/*
 * File: z_en_syateki_niw.c
 * Overlay: ovl_En_Syateki_Niw
 * Description: Hopping Cucco
 */

#include "z_en_syateki_niw.h"
#include "objects/object_niw/object_niw.h"
#include "vt.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_eff_ss_dead.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void EnSyatekiNiw_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiNiw_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnSyatekiNiw_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiNiw_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSyatekiNiw_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B11DEC(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B132A8(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B129EC(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B13464(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B123A8(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B11E78(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B12460(EnSyatekiNiw* pthis, GlobalContext* globalCtx);
void func_80B128D8(EnSyatekiNiw* pthis, GlobalContext* globalCtx);

void func_80B131B8(EnSyatekiNiw* pthis, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4);

ActorInit En_Syateki_Niw_InitVars = {
    ACTOR_EN_SYATEKI_NIW,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_NIW,
    sizeof(EnSyatekiNiw),
    (ActorFunc)EnSyatekiNiw_Init,
    (ActorFunc)EnSyatekiNiw_Destroy,
    (ActorFunc)EnSyatekiNiw_Update,
    (ActorFunc)EnSyatekiNiw_Draw,
    (ActorFunc)EnSyatekiNiw_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    },
    { 10, 20, 4, { 0, 0, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 1, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -1000, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void EnSyatekiNiw_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnSyatekiNiw* pthis = (EnSyatekiNiw*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gCuccoSkel, &gCuccoAnim, pthis->jointTable, pthis->morphTable, 16);

    pthis->unk_29E = pthis->actor.params;
    if (pthis->unk_29E < 0) {
        pthis->unk_29E = 0;
    }

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    if (pthis->unk_29E == 0) {
        osSyncPrintf("\n\n");
        // "Archery range chicken"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 射的場鶏 ☆☆☆☆☆ \n" VT_RST);
        Actor_SetScale(&pthis->actor, 0.01f);
    } else {
        osSyncPrintf("\n\n");
        // "Bomb chicken"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ボムにわ！ ☆☆☆☆☆ \n" VT_RST);
        pthis->actor.colChkInfo.mass = MASS_IMMOVABLE;
        Actor_SetScale(&pthis->actor, 0.01f);
    }

    pthis->unk_2DC = pthis->actor.world.pos;
    pthis->unk_2E8 = pthis->actor.world.pos;
    pthis->actionFunc = func_80B11DEC;
}

void EnSyatekiNiw_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnSyatekiNiw* pthis = (EnSyatekiNiw*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80B11A94(EnSyatekiNiw* pthis, GlobalContext* globalCtx, s16 arg2) {
    if (pthis->unk_254 == 0) {
        if (arg2 == 0) {
            pthis->unk_264 = 0.0f;
        } else {
            pthis->unk_264 = -10000.0f;
        }

        pthis->unk_28E += 1;
        pthis->unk_254 = 3;
        if (!(pthis->unk_28E & 1)) {
            pthis->unk_264 = 0.0f;
            if (arg2 == 0) {
                pthis->unk_254 = Rand_ZeroFloat(30.0f);
            }
        }
    }

    if (pthis->unk_258 == 0) {
        pthis->unk_292++;
        pthis->unk_292 &= 1;
        switch (arg2) {
            case 0:
                pthis->unk_26C = 0.0f;
                pthis->unk_268 = 0.0f;
                break;

            case 1:
                pthis->unk_258 = 3;
                pthis->unk_26C = 7000.0f;
                pthis->unk_268 = 7000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_26C = 0.0f;
                    pthis->unk_268 = 0.0f;
                }
                break;

            case 2:
                pthis->unk_258 = 2;
                pthis->unk_268 = pthis->unk_26C = -10000.0f;
                pthis->unk_280 = pthis->unk_278 = 25000.0f;
                pthis->unk_284 = pthis->unk_27C = 6000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 8000.0f;
                    pthis->unk_280 = 8000.0f;
                }
                break;

            case 3:
                pthis->unk_258 = 2;
                pthis->unk_278 = 10000.0f;
                pthis->unk_280 = 10000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 3000.0f;
                    pthis->unk_280 = 3000.0f;
                }
                break;

            case 4:
                pthis->unk_254 = pthis->unk_256 = 5;
                break;

            case 5:
                pthis->unk_258 = 5;
                pthis->unk_278 = 14000.0f;
                pthis->unk_280 = 14000.0f;
                if (pthis->unk_292 == 0) {
                    pthis->unk_278 = 10000.0f;
                    pthis->unk_280 = 10000.0f;
                }
                break;
        }
    }

    if (pthis->unk_264 != pthis->unk_2BC.x) {
        Math_ApproachF(&pthis->unk_2BC.x, pthis->unk_264, 0.5f, 4000.0f);
    }

    if (pthis->unk_26C != pthis->unk_2A4.x) {
        Math_ApproachF(&pthis->unk_2A4.x, pthis->unk_26C, 0.8f, 7000.0f);
    }

    if (pthis->unk_280 != pthis->unk_2A4.y) {
        Math_ApproachF(&pthis->unk_2A4.y, pthis->unk_280, 0.8f, 7000.0f);
    }

    if (pthis->unk_284 != pthis->unk_2A4.z) {
        Math_ApproachF(&pthis->unk_2A4.z, pthis->unk_284, 0.8f, 7000.0f);
    }

    if (pthis->unk_268 != pthis->unk_2B0.x) {
        Math_ApproachF(&pthis->unk_2B0.x, pthis->unk_268, 0.8f, 7000.0f);
    }

    if (pthis->unk_278 != pthis->unk_2B0.y) {
        Math_ApproachF(&pthis->unk_2B0.y, pthis->unk_278, 0.8f, 7000.0f);
    }

    if (pthis->unk_27C != pthis->unk_2B0.z) {
        Math_ApproachF(&pthis->unk_2B0.z, pthis->unk_27C, 0.8f, 7000.0f);
    }
}

void func_80B11DEC(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gCuccoAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCuccoAnim), ANIMMODE_LOOP,
                     -10.0f);
    if (pthis->unk_29E != 0) {
        Actor_SetScale(&pthis->actor, pthis->unk_2F4);
    }

    pthis->actionFunc = func_80B11E78;
}

void func_80B11E78(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    Vec3f dustVelocity = { 0.0f, 0.0f, 0.0f };
    Vec3f dustAccel = { 0.0f, 0.2f, 0.0f };
    Color_RGBA8 dustPrimColor = { 0, 0, 0, 255 };
    Color_RGBA8 dustEnvColor = { 0, 0, 0, 255 };
    Vec3f dustPos;
    f32 tmpf2;
    f32 sp4C;
    f32 sp50;
    f32 tmpf1;
    s16 sp4A;

    if ((pthis->unk_29C != 0) && (pthis->unk_29E == 0) && (pthis->actor.bgCheckFlags & 1)) {
        pthis->unk_29C = 0;
        pthis->actionFunc = func_80B123A8;
        return;
    }

    sp4A = 0;
    if ((pthis->unk_25E == 0) && (pthis->unk_25C == 0)) {
        pthis->unk_294++;
        if (pthis->unk_294 >= 8) {
            pthis->unk_25E = Rand_ZeroFloat(30.0f);
            pthis->unk_294 = Rand_ZeroFloat(3.99f);

            switch (pthis->unk_29E) {
                case 0:
                    sp50 = Rand_CenteredFloat(100.0f);
                    if (sp50 < 0.0f) {
                        sp50 -= 100.0f;
                    } else {
                        sp50 += 100.0f;
                    }

                    sp4C = Rand_CenteredFloat(100.0f);
                    if (sp4C < 0.0f) {
                        sp4C -= 100.0f;
                    } else {
                        sp4C += 100.0f;
                    }

                    pthis->unk_2E8.x = pthis->unk_2DC.x + sp50;
                    pthis->unk_2E8.z = pthis->unk_2DC.z + sp4C;

                    if (pthis->unk_2E8.x < -150.0f) {
                        pthis->unk_2E8.x = -150.0f;
                    }

                    if (pthis->unk_2E8.x > 150.0f) {
                        pthis->unk_2E8.x = 150.0f;
                    }

                    if (pthis->unk_2E8.z < -60.0f) {
                        pthis->unk_2E8.z = -60.0f;
                    }

                    if (pthis->unk_2E8.z > -40.0f) {
                        pthis->unk_2E8.z = -40.0f;
                    }
                    break;

                case 1:
                    sp50 = Rand_CenteredFloat(50.0f);
                    if (sp50 < 0.0f) {
                        sp50 -= 50.0f;
                    } else {
                        sp50 += 50.0f;
                    }

                    sp4C = Rand_CenteredFloat(30.0f);
                    if (sp4C < 0.0f) {
                        sp4C -= 30.0f;
                    } else {
                        sp4C += 30.0f;
                    }

                    pthis->unk_2E8.x = pthis->unk_2DC.x + sp50;
                    pthis->unk_2E8.z = pthis->unk_2DC.z + sp4C;
                    break;
            }
        } else {
            pthis->unk_25C = 4;
            if (pthis->actor.bgCheckFlags & 1) {
                pthis->actor.velocity.y = 2.5f;
                if ((Rand_ZeroFloat(10.0f) < 1.0f) && (pthis->unk_29E == 0)) {
                    pthis->unk_25C = 0xC;
                    pthis->actor.velocity.y = 10.0f;
                }
            }
        }
    }
    if (pthis->unk_25C != 0) {
        sp4A = 1;
        Math_ApproachF(&pthis->actor.world.pos.x, pthis->unk_2E8.x, 1.0f, pthis->unk_2C8.y);
        Math_ApproachF(&pthis->actor.world.pos.z, pthis->unk_2E8.z, 1.0f, pthis->unk_2C8.y);
        Math_ApproachF(&pthis->unk_2C8.y, 3.0f, 1.0f, 0.3f);
        tmpf1 = pthis->unk_2E8.x - pthis->actor.world.pos.x;
        tmpf2 = pthis->unk_2E8.z - pthis->actor.world.pos.z;

        if (fabsf(tmpf1) < 10.0f) {
            tmpf1 = 0;
        }

        if (fabsf(tmpf2) < 10.0f) {
            tmpf2 = 0.0f;
        }

        if ((tmpf1 == 0.0f) && (tmpf2 == 0.0f)) {
            pthis->unk_25C = 0;
            pthis->unk_294 = 7;
        }

        Math_SmoothStepToS(&pthis->actor.world.rot.y, Math_FAtan2F(tmpf1, tmpf2) * (0x8000 / M_PI), 3, pthis->unk_2C8.z,
                           0);
        Math_ApproachF(&pthis->unk_2C8.z, 10000.0f, 1.0f, 1000.0f);
    }

    if (pthis->unk_260 == 0) {
        func_80B11A94(pthis, globalCtx, sp4A);
        return;
    }

    if ((globalCtx->gameplayFrames % 4) == 0) {
        dustVelocity.y = Rand_CenteredFloat(5.0f);
        dustAccel.y = 0.2f;
        dustPos = pthis->actor.world.pos;
        func_8002836C(globalCtx, &dustPos, &dustVelocity, &dustAccel, &dustPrimColor, &dustEnvColor, 600, 40, 30);
    }
}

void func_80B123A8(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    Animation_Change(&pthis->skelAnime, &gCuccoAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gCuccoAnim), ANIMMODE_LOOP,
                     -10.0f);
    pthis->unk_27C = 6000.0f;
    pthis->unk_288 = -10000.0f;
    pthis->unk_2B0.z = 6000.0f;
    pthis->unk_2B0.y = 10000.0f;
    pthis->actionFunc = func_80B12460;
    pthis->unk_2A4.z = 6000.0f;
    pthis->unk_284 = 6000.0f;
    pthis->unk_2B0.x = -10000.0f;
    pthis->unk_268 = -10000.0f;
    pthis->unk_2A4.y = -10000.0f;
    pthis->unk_2A4.x = -10000.0f;
    pthis->unk_26C = -10000.0f;
}

void func_80B12460(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 phi_f16 = 0.0f;

    player->actor.freezeTimer = 10;
    switch (pthis->unk_29A) {
        case 0:
            pthis->unk_296 = 2;
            pthis->unk_2C8.y = 0.0f;
            pthis->unk_29A = 1;
            break;

        case 1:
            pthis->actor.speedXZ = 2.0f;
            if (pthis->unk_25C == 0) {
                pthis->unk_25C = 3;
                pthis->actor.velocity.y = 3.5f;
            }

            if (pthis->unk_25A == 0) {
                pthis->unk_298++;
                pthis->unk_298 &= 1;
                pthis->unk_25A = 5;
            }

            phi_f16 = (pthis->unk_298 == 0) ? 5000.0f : -5000.0f;
            if (pthis->actor.world.pos.z > 100.0f) {
                pthis->actor.speedXZ = 2.0f;
                pthis->actor.gravity = -0.3f;
                pthis->actor.velocity.y = 5.0f;
                pthis->unk_29A = 2;
            }
            break;

        case 2:
            if ((player->actor.world.pos.z - 40.0f) < pthis->actor.world.pos.z) {
                pthis->actor.speedXZ = 0.0f;
            }

            if ((pthis->actor.bgCheckFlags & 1) && (pthis->actor.world.pos.z > 110.0f)) {
                pthis->actor.velocity.y = 0.0f;
                pthis->actor.gravity = 0.0f;
                pthis->unk_284 = 0.0f;
                pthis->unk_27C = 0.0f;
                pthis->unk_278 = 0.0f;
                pthis->unk_280 = 0.0f;
                pthis->unk_288 = 0.0f;
                pthis->actor.speedXZ = 0.5f;
                pthis->unk_254 = pthis->unk_256 = 0;
                pthis->unk_28E = pthis->unk_290 = 0;
                pthis->unk_296 = 1;
                pthis->unk_29A = 3;
            }
            break;

        case 3:
            if ((player->actor.world.pos.z - 50.0f) < pthis->actor.world.pos.z) {
                pthis->actor.speedXZ = 0.0f;
                pthis->unk_262 = 0x3C;
                pthis->unk_25A = 0x14;
                pthis->unk_264 = 10000.0f;
                pthis->unk_29A = 4;
            }
            break;

        case 4:
            if (pthis->unk_25A == 0) {
                pthis->unk_296 = 4;
                pthis->unk_264 = 5000.0f;
                pthis->unk_26C = 0.0f;
                pthis->unk_268 = 0.0f;
                pthis->unk_284 = 0.0f;
                pthis->unk_27C = 0.0f;
                pthis->unk_280 = 14000.0f;
                pthis->unk_278 = 14000.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_M);
                pthis->unk_254 = pthis->unk_256 = pthis->unk_25A = 0x1E;
                pthis->unk_29A = 5;
            }
            break;

        case 5:
            if (pthis->unk_25A == 1) {
                pthis->unk_258 = 0;
                pthis->unk_296 = 5;
                pthis->unk_256 = pthis->unk_258;
                pthis->unk_254 = pthis->unk_258;
                pthis->actor.speedXZ = 1.0f;
            }

            if ((pthis->unk_25A == 0) && ((player->actor.world.pos.z - 30.0f) < pthis->actor.world.pos.z)) {
                Audio_PlaySoundGeneral(NA_SE_VO_LI_DOWN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                       &D_801333E8);
                pthis->unk_25E = 0x14;
                pthis->unk_29A = 6;
                pthis->actor.speedXZ = 0.0f;
            }
            break;

        case 6:
            if (pthis->unk_25E == 1) {
                globalCtx->sceneLoadFlag = 0x14;
                globalCtx->nextEntranceIndex = gSaveContext.entranceIndex;
                globalCtx->shootingGalleryStatus = 0;
                player->actor.freezeTimer = 20;
                pthis->unk_25E = 0x14;
                pthis->actionFunc = func_80B128D8;
            }
            break;
    }

    Math_SmoothStepToS(&pthis->actor.world.rot.y,
                       (s16)(Math_FAtan2F(player->actor.world.pos.x - pthis->actor.world.pos.x,
                                          player->actor.world.pos.z - pthis->actor.world.pos.z) *
                             (0x8000 / M_PI)) +
                           phi_f16,
                       5, pthis->unk_2C8.y, 0);
    Math_ApproachF(&pthis->unk_2C8.y, 3000.0f, 1.0f, 500.0f);
    if (pthis->unk_296 == 2) {
        pthis->unk_256 = 10;
        pthis->unk_254 = pthis->unk_256;
    }

    func_80B11A94(pthis, globalCtx, pthis->unk_296);
}

void func_80B128D8(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_25E == 1) {
        gSaveContext.timer1State = 0;
    }
}

void func_80B128F8(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    s16 sp26;
    s16 sp24;

    Actor_SetFocus(&pthis->actor, pthis->unk_2D4);
    Actor_GetScreenPos(globalCtx, &pthis->actor, &sp26, &sp24);
    if ((pthis->actor.projectedPos.z > 200.0f) && (pthis->actor.projectedPos.z < 800.0f) && (sp26 > 0) &&
        (sp26 < SCREEN_WIDTH) && (sp24 > 0) && (sp24 < SCREEN_HEIGHT)) {
        pthis->actor.speedXZ = 5.0f;
        pthis->unk_298 = Rand_ZeroFloat(1.99f);
        pthis->unk_2D8 = Rand_CenteredFloat(8000.0f) + -10000.0f;
        pthis->unk_262 = 0x1E;
        pthis->unk_25E = 0x64;
        pthis->actionFunc = func_80B129EC;
    }
}

void func_80B129EC(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 phi_f2;
    s16 sp2E;
    s16 sp2C;
    f32 tmpf2;

    Actor_SetFocus(&pthis->actor, pthis->unk_2D4);
    Actor_GetScreenPos(globalCtx, &pthis->actor, &sp2E, &sp2C);
    if ((pthis->unk_25E == 0) || (pthis->actor.projectedPos.z < -70.0f) || (sp2E < 0) || (sp2E > SCREEN_WIDTH) ||
        (sp2C < 0) || (sp2C > SCREEN_HEIGHT)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->unk_2A0 = 1;
    if (pthis->unk_25C == 0) {
        pthis->unk_298++;
        pthis->unk_298 &= 1;
        pthis->unk_25C = (s16)Rand_CenteredFloat(4.0f) + 5;
        if ((Rand_ZeroFloat(5.0f) < 1.0f) && (pthis->actor.bgCheckFlags & 1)) {
            pthis->actor.velocity.y = 4.0f;
        }
    }

    phi_f2 = (pthis->unk_298 == 0) ? 5000.0f : -5000.0f;
    tmpf2 = pthis->unk_2D8 + phi_f2;
    Math_SmoothStepToS(&pthis->actor.world.rot.y, tmpf2, 3, pthis->unk_2C8.y, 0);
    Math_ApproachF(&pthis->unk_2C8.y, 3000.0f, 1.0f, 500.0f);
    func_80B11A94(pthis, globalCtx, 2);
}

void func_80B12BA4(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        switch (pthis->unk_29E) {
            case 0:
                if (pthis->unk_29C == 0) {
                    pthis->unk_262 = 0x1E;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_A);
                    pthis->unk_29C = 1;
                    pthis->unk_2A0 = 1;
                    pthis->actionFunc = func_80B123A8;
                    pthis->actor.gravity = -3.0f;
                }
                break;

            case 1:
                pthis->unk_262 = 0x1E;
                pthis->unk_2F8 = 1;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_A);
                pthis->unk_260 = 100;
                pthis->unk_2A0 = 1;
                pthis->unk_25E = pthis->unk_260;
                break;
        }
    }
}

void EnSyatekiNiw_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnSyatekiNiw* pthis = (EnSyatekiNiw*)thisx;
    s32 pad;
    s16 i;
    Vec3f sp90 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp84 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;

    if (1) {}
    if (1) {}
    if (1) {}

    func_80B132A8(pthis, globalCtx);
    pthis->unk_28C++;
    if (pthis->unk_254 != 0) {
        pthis->unk_254--;
    }

    if (pthis->unk_258 != 0) {
        pthis->unk_258--;
    }

    if (pthis->unk_25A != 0) {
        pthis->unk_25A--;
    }

    if (pthis->unk_25C != 0) {
        pthis->unk_25C--;
    }

    if (pthis->unk_25E != 0) {
        pthis->unk_25E--;
    }

    if (pthis->unk_262 != 0) {
        pthis->unk_262--;
    }

    if (pthis->unk_260 != 0) {
        pthis->unk_260--;
    }

    pthis->actor.shape.rot = pthis->actor.world.rot;
    pthis->actor.shape.shadowScale = 15.0f;

    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 0x1D);

    if (pthis->unk_2A0 != 0) {
        for (i = 0; i < 20; i++) {
            sp78.x = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.x;
            sp78.y = Rand_CenteredFloat(10.0f) + (pthis->actor.world.pos.y + 20.0f);
            sp78.z = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.z;
            sp6C.x = Rand_CenteredFloat(3.0f);
            sp6C.y = (Rand_ZeroFloat(2.0f) * 0.5f) + 2.0f;
            sp6C.z = Rand_CenteredFloat(3.0f);
            sp60.z = sp60.x = 0.0f;
            sp60.y = -0.15f;
            func_80B131B8(pthis, &sp78, &sp6C, &sp60, Rand_ZeroFloat(8.0f) + 8.0f);
        }

        pthis->unk_2A0 = 0;
    }

    func_80B12BA4(pthis, globalCtx);
    if (pthis->unk_262 == 0) {
        if (pthis->actionFunc == func_80B11E78) {
            pthis->unk_262 = 0x12C;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_N);
        } else {
            pthis->unk_262 = 0x1E;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHICKEN_CRY_A);
        }
    }

    i = 0;
    switch (pthis->unk_29E) {
        case 0:
            if (globalCtx->shootingGalleryStatus != 0) {
                i = 1;
            }
            break;

        case 1:
            i = 1;
            break;
    }

    if (i != 0) {
        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

s32 SyatekiNiw_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    EnSyatekiNiw* pthis = (EnSyatekiNiw*)thisx;
    Vec3f sp0 = { 0.0f, 0.0f, 0.0f };

    if (limbIndex == 13) {
        rot->y += (s16)pthis->unk_2BC.x;
    }

    if (limbIndex == 11) {
        rot->x += (s16)pthis->unk_2B0.z;
        rot->y += (s16)pthis->unk_2B0.y;
        rot->z += (s16)pthis->unk_2B0.x;
    }

    if (limbIndex == 7) {
        rot->x += (s16)pthis->unk_2A4.z;
        rot->y += (s16)pthis->unk_2A4.y;
        rot->z += (s16)pthis->unk_2A4.x;
    }

    return false;
}

void EnSyatekiNiw_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnSyatekiNiw* pthis = (EnSyatekiNiw*)thisx;
    Color_RGBA8 sp30 = { 0, 0, 0, 255 };

    if (pthis->actionFunc != func_80B128F8) {
        func_80093D18(globalCtx->state.gfxCtx);
        if (pthis->unk_260 != 0) {
            func_80026230(globalCtx, &sp30, 0, 0x14);
        }

        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, SyatekiNiw_OverrideLimbDraw, NULL, pthis);
        func_80026608(globalCtx);
        func_80B13464(pthis, globalCtx);
    }
}

void func_80B131B8(EnSyatekiNiw* pthis, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4) {
    s16 i;
    EnSyatekiNiw_1* ptr = &pthis->unk_348[0];

    for (i = 0; i < 5; i++, ptr++) {
        if (ptr->unk_00 == 0) {
            ptr->unk_00 = 1;
            ptr->unk_04 = *arg1;
            ptr->unk_10 = *arg2;
            ptr->unk_1C = *arg3;
            ptr->unk_34 = 0;
            ptr->unk_2C = (arg4 / 1000.0f);
            ptr->unk_28 = (s16)Rand_ZeroFloat(20.0f) + 0x28;
            ptr->unk_2A = Rand_ZeroFloat(1000.0f);
            return;
        }
    }
}

void func_80B132A8(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    s16 i;
    EnSyatekiNiw_1* ptr = &pthis->unk_348[0];

    for (i = 0; i < 5; i++, ptr++) {
        if (ptr->unk_00 != 0) {
            ptr->unk_04.x += ptr->unk_10.x;
            ptr->unk_04.y += ptr->unk_10.y;
            ptr->unk_04.z += ptr->unk_10.z;
            ptr->unk_34++;
            ptr->unk_10.x += ptr->unk_1C.x;
            ptr->unk_10.y += ptr->unk_1C.y;
            ptr->unk_10.z += ptr->unk_1C.z;
            if (ptr->unk_00 == 1) {
                ptr->unk_2A++;
                Math_ApproachF(&ptr->unk_10.x, 0.0f, 1.0f, 0.05f);
                Math_ApproachF(&ptr->unk_10.z, 0.0f, 1.0f, 0.05f);
                if (ptr->unk_10.y < -0.5f) {
                    ptr->unk_10.y = 0.5f;
                }

                ptr->unk_30 = (Math_SinS(ptr->unk_2A * 3000) * M_PI) * 0.2f;
                if (ptr->unk_28 < ptr->unk_34) {
                    ptr->unk_00 = 0;
                }
            }
        }
    }
}

void func_80B13464(EnSyatekiNiw* pthis, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;
    EnSyatekiNiw_1* ptr = &pthis->unk_348[0];
    u8 flag = 0;

    OPEN_DISPS(gfxCtx, "../z_en_syateki_niw.c", 1234);

    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < 5; i++, ptr++) {
        if (ptr->unk_00 == 1) {
            if (flag == 0) {
                gSPDisplayList(POLY_XLU_DISP++, gCuccoParticleAppearDL);
                flag++;
            }

            Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(ptr->unk_2C, ptr->unk_2C, 1.0f, MTXMODE_APPLY);
            Matrix_RotateZ(ptr->unk_30, MTXMODE_APPLY);
            Matrix_Translate(0.0f, -1000.0f, 0.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_en_syateki_niw.c", 1251),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gCuccoParticleAliveDL);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_en_syateki_niw.c", 1257);
}

void EnSyatekiNiw_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Syateki_Niw_InitVars = {
        ACTOR_EN_SYATEKI_NIW,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_NIW,
        sizeof(EnSyatekiNiw),
        (ActorFunc)EnSyatekiNiw_Init,
        (ActorFunc)EnSyatekiNiw_Destroy,
        (ActorFunc)EnSyatekiNiw_Update,
        (ActorFunc)EnSyatekiNiw_Draw,
        (ActorFunc)EnSyatekiNiw_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_HIT5,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 10, 20, 4, { 0, 0, 0 } },
    };

}

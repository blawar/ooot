#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_GANON_OTYUKA_Z_BG_GANON_OTYUKA_C
#include "actor_common.h"
/*
 * File: z_bg_ganon_otyka.c
 * Overlay: ovl_Bg_Ganon_Otyka
 * Description: Falling Platform (Ganondorf Fight)
 */

#include "z_bg_ganon_otyuka.h"
#include "overlays/actors/ovl_Boss_Ganon/z_boss_ganon.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/audio_bank.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)


void BgGanonOtyuka_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgGanonOtyuka_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgGanonOtyuka_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgGanonOtyuka_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgGanonOtyuka_Draw(Actor* pthisx, GlobalContext* globalCtx);

void BgGanonOtyuka_WaitToFall(BgGanonOtyuka* pthis, GlobalContext* globalCtx);
void BgGanonOtyuka_Fall(BgGanonOtyuka* pthis, GlobalContext* globalCtx);
void BgGanonOtyuka_DoNothing(Actor* pthisx, GlobalContext* globalCtx);

ActorInit Bg_Ganon_Otyuka_InitVars = {
    ACTOR_BG_GANON_OTYUKA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GANON,
    sizeof(BgGanonOtyuka),
    (ActorFunc)BgGanonOtyuka_Init,
    (ActorFunc)BgGanonOtyuka_Destroy,
    (ActorFunc)BgGanonOtyuka_Update,
    (ActorFunc)BgGanonOtyuka_Draw,
    (ActorFunc)BgGanonOtyuka_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

static u8 sSides[] = { OTYUKA_SIDE_EAST, OTYUKA_SIDE_WEST, OTYUKA_SIDE_SOUTH, OTYUKA_SIDE_NORTH };

static Vec3f D_80876A68[] = {
    { 120.0f, 0.0f, 0.0f },
    { -120.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 120.0f },
    { 0.0f, 0.0f, -120.0f },
};

static Color_RGBA8 sDustPrimColor = { 60, 60, 0, 0 };

static Color_RGBA8 sDustEnvColor = { 50, 20, 0, 0 };

static Vec3f sSideCenters[] = {
    { 60.0f, 0.0f, 0.0f },
    { -60.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 60.0f },
    { 0.0f, 0.0f, -60.0f },
};

static f32 sSideAngles[] = { M_PI / 2, -M_PI / 2, 0.0f, M_PI };

#include "overlays/ovl_Bg_Ganon_Otyuka/ovl_Bg_Ganon_Otyuka.cpp"

void BgGanonOtyuka_Init(Actor* pthisx, GlobalContext* globalCtx2) {
    BgGanonOtyuka* pthis = (BgGanonOtyuka*)pthisx;
    GlobalContext* globalCtx = globalCtx2;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(pthisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&sCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);

    if (pthisx->params != 0x23) {
        pthisx->draw = NULL;
        pthis->actionFunc = BgGanonOtyuka_WaitToFall;
    } else {
        pthisx->update = BgGanonOtyuka_DoNothing;
    }
}

void BgGanonOtyuka_Destroy(Actor* pthisx, GlobalContext* globalCtx2) {
    BgGanonOtyuka* pthis = (BgGanonOtyuka*)pthisx;
    GlobalContext* globalCtx = globalCtx2;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);

    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("WHY !!!!!!!!!!!!!!!!\n");
    osSyncPrintf(VT_RST);
}

void BgGanonOtyuka_WaitToFall(BgGanonOtyuka* pthis, GlobalContext* globalCtx) {
    Actor* pthisx = &pthis->dyna.actor;
    Actor* prop;
    BgGanonOtyuka* platform;
    f32 dx;
    f32 dy;
    f32 dz;
    Vec3f center;
    s16 i;

    if (pthis->isFalling || ((globalCtx->actorCtx.unk_02 != 0) && (pthis->dyna.actor.xyzDistToPlayerSq < 4900.0f))) {
        osSyncPrintf("OTC O 1\n");

        for (i = 0; i < ARRAY_COUNT(D_80876A68); i++) {
            prop = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
            while (prop != NULL) {
                if ((prop == pthisx) || (prop->id != ACTOR_BG_GANON_OTYUKA)) {
                    prop = prop->next;
                    continue;
                }

                platform = (BgGanonOtyuka*)prop;

                dx = platform->dyna.actor.world.pos.x - pthis->dyna.actor.world.pos.x + D_80876A68[i].x;
                dy = platform->dyna.actor.world.pos.y - pthis->dyna.actor.world.pos.y;
                dz = platform->dyna.actor.world.pos.z - pthis->dyna.actor.world.pos.z + D_80876A68[i].z;

                if ((fabsf(dx) < 10.0f) && (fabsf(dy) < 10.0f) && (fabsf(dz) < 10.0f)) {
                    platform->visibleSides |= sSides[i];
                    break;
                } else {
                    prop = prop->next;
                }
            }
        }

        osSyncPrintf("OTC O 2\n");

        for (i = 0; i < ARRAY_COUNT(D_80876A68); i++) {
            center.x = pthis->dyna.actor.world.pos.x + D_80876A68[i].x;
            center.y = pthis->dyna.actor.world.pos.y;
            center.z = pthis->dyna.actor.world.pos.z + D_80876A68[i].z;
            if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &center, 50.0f)) {
                pthis->unwalledSides |= sSides[i];
            }
        }

        osSyncPrintf("OTC O 3\n");

        pthis->actionFunc = BgGanonOtyuka_Fall;
        pthis->isFalling = true;
        pthis->dropTimer = 20;
        pthis->flashState = FLASH_GROW;
        pthis->flashTimer = 0;
        pthis->flashPrimColorR = 255.0f;
        pthis->flashPrimColorG = 255.0f;
        pthis->flashPrimColorB = 255.0f;
        pthis->flashEnvColorR = 255.0f;
        pthis->flashEnvColorG = 255.0f;
        pthis->flashEnvColorB = 0.0f;
    }
}

void BgGanonOtyuka_Fall(BgGanonOtyuka* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 i;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;

    osSyncPrintf("MODE DOWN\n");
    if (pthis->flashState == FLASH_GROW) {
        Math_ApproachF(&pthis->flashPrimColorB, 170.0f, 1.0f, 8.5f);
        Math_ApproachF(&pthis->flashEnvColorR, 120.0f, 1.0f, 13.5f);
        Math_ApproachF(&pthis->flashYScale, 2.5f, 1.0f, 0.25f);
        if (pthis->flashYScale == 2.5f) {
            pthis->flashState = FLASH_SHRINK;
        }
    } else if (pthis->flashState == FLASH_SHRINK) {
        Math_ApproachF(&pthis->flashPrimColorG, 0.0f, 1.0f, 25.5f);
        Math_ApproachF(&pthis->flashEnvColorR, 0.0f, 1.0f, 12.0f);
        Math_ApproachF(&pthis->flashEnvColorG, 0.0f, 1.0f, 25.5f);
        Math_ApproachZeroF(&pthis->flashYScale, 1.0f, 0.25f);
        if (pthis->flashYScale == 0.0f) {
            pthis->flashState = FLASH_NONE;
        }
    }
    if (pthis->dropTimer == 0) {
        pthis->flashYScale = 0.0f;
        Math_ApproachF(&pthis->dyna.actor.world.pos.y, -1000.0f, 1.0f, pthis->dyna.actor.speedXZ);
        Math_ApproachF(&pthis->dyna.actor.speedXZ, 100.0f, 1.0f, 2.0f);
        if (!(pthis->unwalledSides & OTYUKA_SIDE_EAST)) {
            pthis->dyna.actor.shape.rot.z -= (s16)(pthis->dyna.actor.speedXZ * 30.0f);
        }
        if (!(pthis->unwalledSides & OTYUKA_SIDE_WEST)) {
            pthis->dyna.actor.shape.rot.z += (s16)(pthis->dyna.actor.speedXZ * 30.0f);
        }
        if (!(pthis->unwalledSides & OTYUKA_SIDE_SOUTH)) {
            pthis->dyna.actor.shape.rot.x += (s16)(pthis->dyna.actor.speedXZ * 30.0f);
        }
        if (!(pthis->unwalledSides & OTYUKA_SIDE_NORTH)) {
            pthis->dyna.actor.shape.rot.x -= (s16)(pthis->dyna.actor.speedXZ * 30.0f);
        }
        if (pthis->dyna.actor.world.pos.y < -750.0f) {
            if (player->actor.world.pos.y < -400.0f) {
                accel.x = accel.z = 0.0f;
                accel.y = 0.1f;
                velocity.x = velocity.y = velocity.z = 0.0f;

                for (i = 0; i < 30; i++) {
                    pos.x = Rand_CenteredFloat(150.0f) + pthis->dyna.actor.world.pos.x;
                    pos.y = Rand_ZeroFloat(60.0f) + -750.0f;
                    pos.z = Rand_CenteredFloat(150.0f) + pthis->dyna.actor.world.pos.z;
                    func_8002836C(globalCtx, &pos, &velocity, &accel, &sDustPrimColor, &sDustEnvColor,
                                  (s16)Rand_ZeroFloat(100.0f) + 250, 5, (s16)Rand_ZeroFloat(5.0f) + 15);
                }

                func_80033DB8(globalCtx, 10, 15);
                Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 0x28, NA_SE_EV_BOX_BREAK);
            }
            Actor_Kill(&pthis->dyna.actor);
        }
    } else {
        if (pthis->dropTimer == 1) {
            Audio_PlaySoundGeneral(NA_SE_EV_STONEDOOR_STOP, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &gReverbAdd2);
        } else {
            Audio_PlaySoundGeneral(NA_SE_EV_BLOCKSINK - SFX_FLAG, &pthis->dyna.actor.projectedPos, 4, &D_801333E0,
                                   &D_801333E0, &gReverbAdd2);
        }
        Math_ApproachF(&pthis->dyna.actor.world.pos.y, -1000.0f, 1.0f, pthis->dyna.actor.speedXZ);
        Math_ApproachF(&pthis->dyna.actor.speedXZ, 100.0f, 1.0f, 0.1f);
    }
    osSyncPrintf("MODE DOWN END\n");
}

void BgGanonOtyuka_DoNothing(Actor* pthisx, GlobalContext* globalCtx) {
}

void BgGanonOtyuka_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgGanonOtyuka* pthis = (BgGanonOtyuka*)pthisx;

    pthis->actionFunc(pthis, globalCtx);
    pthis->flashTimer++;
    if (pthis->dropTimer != 0) {
        pthis->dropTimer--;
    }
}

void BgGanonOtyuka_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgGanonOtyuka* pthis = (BgGanonOtyuka*)pthisx;
    s16 i;
    Gfx* phi_s2;
    Gfx* phi_s1;
    Camera* camera = Gameplay_GetCamera(globalCtx, 0);
    Actor* actor;
    BgGanonOtyuka* platform;
    BossGanon* ganondorf;
    f32 spBC = -30.0f;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_ganon_otyuka.c", 702);

    actor = globalCtx->actorCtx.actorLists[ACTORCAT_BOSS].head;
    while (actor != NULL) {
        if (actor->id == ACTOR_BOSS_GANON) {
            ganondorf = (BossGanon*)actor;

            if (ganondorf->actor.params == 0) {
                if (ganondorf->unk_198 != 0) {
                    spBC = -2000.0f;
                }

                break;
            }
        }

        actor = actor->next;
    }

    func_80093D18(globalCtx->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, sPlatformMaterialDL);

    actor = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
    while (actor != NULL) {
        if (actor->id == ACTOR_BG_GANON_OTYUKA) {
            platform = (BgGanonOtyuka*)actor;

            if (platform->dyna.actor.projectedPos.z > spBC) {
                if (camera->eye.y > platform->dyna.actor.world.pos.y) {
                    phi_s2 = sPlatformTopDL;
                } else {
                    phi_s2 = sPlatformBottomDL;
                }
                Matrix_Translate(platform->dyna.actor.world.pos.x, platform->dyna.actor.world.pos.y,
                                 platform->dyna.actor.world.pos.z, MTXMODE_NEW);
                phi_s1 = NULL;
                if (platform->isFalling) {
                    Matrix_RotateX((platform->dyna.actor.shape.rot.x / (f32)0x8000) * M_PI, MTXMODE_APPLY);
                    Matrix_RotateZ((platform->dyna.actor.shape.rot.z / (f32)0x8000) * M_PI, MTXMODE_APPLY);
                    if (camera->eye.y > platform->dyna.actor.world.pos.y) {
                        phi_s1 = sPlatformBottomDL;
                    } else {
                        phi_s1 = sPlatformTopDL;
                    }
                }
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ganon_otyuka.c", 766),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, phi_s2);

                if (phi_s1 != NULL) {
                    gSPDisplayList(POLY_OPA_DISP++, phi_s1);
                }

                for (i = 0; i < ARRAY_COUNT(sSides); i++) {
                    if (platform->visibleSides & sSides[i]) {
                        Matrix_Push();
                        Matrix_Translate(sSideCenters[i].x, 0.0f, sSideCenters[i].z, MTXMODE_APPLY);
                        Matrix_RotateY(sSideAngles[i], MTXMODE_APPLY);
                        gSPMatrix(POLY_OPA_DISP++,
                                  Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ganon_otyuka.c", 785),
                                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gSPDisplayList(POLY_OPA_DISP++, sPlatformSideDL);
                        Matrix_Pop();
                    }
                }
            }
        }

        actor = actor->next;
    }

    func_80093D84(globalCtx->state.gfxCtx);
    actor = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
    while (actor != NULL) {
        if (actor->id == ACTOR_BG_GANON_OTYUKA) {
            platform = (BgGanonOtyuka*)actor;

            if ((platform->dyna.actor.projectedPos.z > -30.0f) && (platform->flashState != FLASH_NONE)) {
                gSPSegment(POLY_XLU_DISP++, 0x08,
                           Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, platform->flashTimer * 4, 0, 32, 64, 1,
                                            platform->flashTimer * 4, 0, 32, 64));
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, platform->flashPrimColorR, platform->flashPrimColorG,
                                platform->flashPrimColorB, 0);
                gDPSetEnvColor(POLY_XLU_DISP++, platform->flashEnvColorR, platform->flashEnvColorG,
                               platform->flashEnvColorB, 128);
                Matrix_Translate(platform->dyna.actor.world.pos.x, 0.0f, platform->dyna.actor.world.pos.z, MTXMODE_NEW);

                for (i = 0; i < ARRAY_COUNT(sSides); i++) {
                    if (platform->unwalledSides & sSides[i]) {
                        Matrix_Push();
                        Matrix_Translate(sSideCenters[i].x, 0.0f, sSideCenters[i].z, MTXMODE_APPLY);
                        Matrix_RotateY(sSideAngles[i], MTXMODE_APPLY);
                        Matrix_Scale(0.3f, platform->flashYScale * 0.3f, 0.3f, MTXMODE_APPLY);
                        gSPMatrix(POLY_XLU_DISP++,
                                  Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ganon_otyuka.c", 847),
                                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gSPDisplayList(POLY_XLU_DISP++, sFlashDL);
                        Matrix_Pop();
                    }
                }
            }
        }

        actor = actor->next;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_ganon_otyuka.c", 857);
}

void BgGanonOtyuka_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Ganon_Otyuka_InitVars = {
        ACTOR_BG_GANON_OTYUKA,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GANON,
        sizeof(BgGanonOtyuka),
        (ActorFunc)BgGanonOtyuka_Init,
        (ActorFunc)BgGanonOtyuka_Destroy,
        (ActorFunc)BgGanonOtyuka_Update,
        (ActorFunc)BgGanonOtyuka_Draw,
        (ActorFunc)BgGanonOtyuka_Reset,
    };

    sDustPrimColor = { 60, 60, 0, 0 };

    sDustEnvColor = { 50, 20, 0, 0 };

}

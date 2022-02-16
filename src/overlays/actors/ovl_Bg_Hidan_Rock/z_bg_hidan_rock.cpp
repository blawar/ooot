#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HIDAN_ROCK_Z_BG_HIDAN_ROCK_C
#include "actor_common.h"
/*
 * File: z_bg_hidan_rock.c
 * Overlay: ovl_Bg_Hidan_Rock
 * Description: Stone blocks (Fire Temple)
 */

#include "z_bg_hidan_rock.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/code_800F7260.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_skin_matrix.h"

#define FLAGS 0

void BgHidanRock_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRock_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgHidanRock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRock_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHidanRock_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8088B24C(BgHidanRock* pthis);

void func_8088B268(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B5F4(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B634(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B69C(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B79C(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B90C(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B954(BgHidanRock* pthis, GlobalContext* globalCtx);
void func_8088B990(BgHidanRock* pthis, GlobalContext* globalCtx);

void func_8088BC40(GlobalContext* globalCtx, BgHidanRock* pthis);

static f32 D_8088BFC0_42 = 0.0f;


static Vec3f D_8088BF60 = { 3310.0f, 120.0f, 0.0f };

ActorInit Bg_Hidan_Rock_InitVars = {
    ACTOR_BG_HIDAN_ROCK,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HIDAN_OBJECTS,
    sizeof(BgHidanRock),
    (ActorFunc)BgHidanRock_Init,
    (ActorFunc)BgHidanRock_Destroy,
    (ActorFunc)BgHidanRock_Update,
    (ActorFunc)BgHidanRock_Draw,
    (ActorFunc)BgHidanRock_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x20000000, 0x01, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NONE,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 45, 77, -40, { 3310, 120, 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, -600, ICHAIN_STOP),
};

void BgHidanRock_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRock* pthis = (BgHidanRock*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);

    pthis->type = thisx->params & 0xFF;
    pthis->unk_169 = 0;

    thisx->params = ((thisx->params) >> 8) & 0xFF;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sCylinderInit);

    if (pthis->type == 0) {
        if (Flags_GetSwitch(globalCtx, thisx->params)) {
            Math_Vec3f_Copy(&thisx->home.pos, &D_8088BF60);
            Math_Vec3f_Copy(&thisx->world.pos, &D_8088BF60);
            pthis->timer = 60;
            pthis->actionFunc = func_8088B5F4;
        } else {
            pthis->actionFunc = func_8088B268;
        }
        thisx->flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
        CollisionHeader_GetVirtual(&gFireTempleStoneBlock1Col, &colHeader);
    } else {
        CollisionHeader_GetVirtual(&gFireTempleStoneBlock2Col, &colHeader);
        pthis->collider.dim.pos.x = thisx->home.pos.x;
        pthis->collider.dim.pos.y = thisx->home.pos.y;
        pthis->collider.dim.pos.z = thisx->home.pos.z;
        pthis->actionFunc = func_8088B634;
    }

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    pthis->timer = 0;
}

void BgHidanRock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRock* pthis = (BgHidanRock*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
    Audio_StopSfxByPos(&pthis->unk_170);
}

void func_8088B24C(BgHidanRock* pthis) {
    pthis->dyna.actor.flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
    pthis->actionFunc = func_8088B990;
}

void func_8088B268(BgHidanRock* pthis, GlobalContext* globalCtx) {
    f32 sp2C;
    s32 temp_v1;
    s32 frame;
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->dyna.unk_150 != 0.0f) {
        if (pthis->timer == 0) {
            if (D_8088BFC0_42 == 0.0f) {
                if (pthis->dyna.unk_150 > 0.0f) {
                    D_8088BFC0_42 += 0.01f;
                } else {
                    D_8088BFC0_42 -= 0.01f;
                }
            }

            pthis->dyna.actor.speedXZ += 0.05f;
            pthis->dyna.actor.speedXZ = CLAMP_MAX(pthis->dyna.actor.speedXZ, 2.0f);

            if (D_8088BFC0_42 > 0.0f) {
                temp_v1 = Math_StepToF(&D_8088BFC0_42, 20.0f, pthis->dyna.actor.speedXZ);
            } else {
                temp_v1 = Math_StepToF(&D_8088BFC0_42, -20.0f, pthis->dyna.actor.speedXZ);
            }

            pthis->dyna.actor.world.pos.x = (Math_SinS(pthis->dyna.unk_158) * D_8088BFC0_42) + pthis->dyna.actor.home.pos.x;
            pthis->dyna.actor.world.pos.z = (Math_CosS(pthis->dyna.unk_158) * D_8088BFC0_42) + pthis->dyna.actor.home.pos.z;

            if (temp_v1) {
                player->stateFlags2 &= ~0x10;
                pthis->dyna.unk_150 = 0.0f;
                pthis->dyna.actor.home.pos.x = pthis->dyna.actor.world.pos.x;
                pthis->dyna.actor.home.pos.z = pthis->dyna.actor.world.pos.z;
                D_8088BFC0_42 = 0.0f;
                pthis->dyna.actor.speedXZ = 0.0f;
                pthis->timer = 5;
            }

            func_8002F974(&pthis->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
        } else {
            player->stateFlags2 &= ~0x10;
            pthis->dyna.unk_150 = 0.0f;
            if (pthis->timer != 0) {
                pthis->timer--;
            }
        }
    } else {
        pthis->timer = 0;
    }

    sp2C = pthis->dyna.actor.world.pos.z - D_8088BF60.z;
    if (sp2C < 0.5f) {
        Flags_SetSwitch(globalCtx, pthis->dyna.actor.params);
        Math_Vec3f_Copy(&pthis->dyna.actor.home.pos, &D_8088BF60);
        pthis->dyna.actor.world.pos.x = D_8088BF60.x;
        pthis->dyna.actor.world.pos.z = D_8088BF60.z;
        pthis->dyna.actor.speedXZ = 0.0f;
        D_8088BFC0_42 = 0.0f;
        player->stateFlags2 &= ~0x10;
        pthis->actionFunc = func_8088B79C;
    }

    frame = globalCtx->gameplayFrames & 0xFF;
    if (globalCtx->gameplayFrames & 0x100) {
        pthis->unk_16C = 0.0f;
    } else if (frame < 128) {
        pthis->unk_16C = sinf(frame * (4 * 0.001f * M_PI)) * 19.625f;
    } else if (frame < 230) {
        pthis->unk_16C = 19.625f;
    } else {
        pthis->unk_16C -= 1.0f;
        pthis->unk_16C = CLAMP_MIN(pthis->unk_16C, 0.0f);
    }

    if (sp2C < 100.0f) {
        pthis->unk_16C = CLAMP_MAX(pthis->unk_16C, 6.125f);
    }
}

void func_8088B5F4(BgHidanRock* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        func_8088B24C(pthis);
    }
}

void func_8088B634(BgHidanRock* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) {
        pthis->timer = 20;
        pthis->dyna.actor.world.rot.y = Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x4000;
        pthis->actionFunc = func_8088B69C;
    }
}

void func_8088B69C(BgHidanRock* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer != 0) {
        pthis->dyna.actor.world.pos.x =
            pthis->dyna.actor.home.pos.x + 5.0f * Math_SinS(pthis->dyna.actor.world.rot.y + pthis->timer * 0x4000);
        pthis->dyna.actor.world.pos.z =
            pthis->dyna.actor.home.pos.z + 5.0f * Math_CosS(pthis->dyna.actor.world.rot.y + pthis->timer * 0x4000);
    } else {
        pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x;
        pthis->dyna.actor.world.pos.z = pthis->dyna.actor.home.pos.z;
        func_8088B24C(pthis);
    }

    if (!(pthis->timer % 4)) {
        func_800AA000(pthis->dyna.actor.xyzDistToPlayerSq, 0xB4, 0x0A, 0x64);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_SHAKE);
    }
}

void func_8088B79C(BgHidanRock* pthis, GlobalContext* globalCtx) {
    pthis->timer--;
    if (pthis->dyna.actor.bgCheckFlags & 2) {
        if (pthis->type == 0) {
            pthis->timer = 60;
            pthis->actionFunc = func_8088B5F4;
        } else {
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 15.0f;
            pthis->actionFunc = func_8088B90C;
            pthis->dyna.actor.flags &= ~(ACTOR_FLAG_4 | ACTOR_FLAG_5);
        }

        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        Audio_PlayActorSound2(
            &pthis->dyna.actor,
            SurfaceType_GetSfx(&globalCtx->colCtx, pthis->dyna.actor.floorPoly, pthis->dyna.actor.floorBgId) + 0x800);
    }

    pthis->unk_16C -= 0.5f;
    pthis->unk_16C = CLAMP_MIN(pthis->unk_16C, 0.0f);

    if (pthis->type == 0) {
        if (func_8004356C(&pthis->dyna)) {
            if (pthis->unk_169 == 0) {
                pthis->unk_169 = 3;
            }
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FIRE_PLATFORM);
        } else if (!func_8004356C(&pthis->dyna)) {
            if (pthis->unk_169 != 0) {
                Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
            }
            pthis->unk_169 = 0;
        }
    }
}

void func_8088B90C(BgHidanRock* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 1.0f)) {
        pthis->actionFunc = func_8088B634;
    }
}

void func_8088B954(BgHidanRock* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        pthis->actionFunc = func_8088B79C;
        pthis->dyna.actor.velocity.y = 0.0f;
    }
}

void func_8088B990(BgHidanRock* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->timer++;
    if (pthis->dyna.unk_150 != 0.0f) {
        pthis->dyna.actor.speedXZ = 0.0f;
        player->stateFlags2 &= ~0x10;
    }

    if ((pthis->type == 0 && (Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 1820.0f,
                                                0.25f, 20.0f, 0.5f) < 0.1f)) ||
        ((pthis->type != 0) && (Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 480.0,
                                                  0.25f, 20.0f, 0.5f) < 0.1f))) {
        if (pthis->type == 0) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        }
        pthis->timer = 20;
        pthis->actionFunc = func_8088B954;
    }

    pthis->unk_16C = (pthis->dyna.actor.world.pos.y + 50.0f - pthis->dyna.actor.home.pos.y + 40.0f) / 80.0f;
    if (pthis->type == 0) {
        if (func_8004356C(&pthis->dyna)) {
            if (pthis->unk_169 == 0) {
                pthis->unk_169 = 3;
            }
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_FIRE_PLATFORM);
        } else if (!func_8004356C(&pthis->dyna)) {
            if (pthis->unk_169 != 0) {
                Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_DUNGEON0);
            }
            pthis->unk_169 = 0;
        }
    }
}

void BgHidanRock_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRock* pthis = (BgHidanRock*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->actionFunc == func_8088B79C) {
        Actor_MoveForward(&pthis->dyna.actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 0.0f, 0.0f, 0.0f, 4);
    }

    if (pthis->unk_16C > 0.0f) {
        pthis->collider.dim.height = sCylinderInit.dim.height * pthis->unk_16C;
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

static void* sVerticalFlamesTexs[] = {
    gFireTempleBigVerticalFlame0Tex, gFireTempleBigVerticalFlame1Tex, gFireTempleBigVerticalFlame2Tex,
    gFireTempleBigVerticalFlame3Tex, gFireTempleBigVerticalFlame4Tex, gFireTempleBigVerticalFlame5Tex,
    gFireTempleBigVerticalFlame6Tex, gFireTempleBigVerticalFlame7Tex,
};

void func_8088BC40(GlobalContext* globalCtx, BgHidanRock* pthis) {
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_rock.c", 808);

    POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0x14);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x01, 255, 255, 0, 150);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 255);

    if (pthis->type == 0) {
        Matrix_Translate(D_8088BF60.x, D_8088BF60.y - 40.0f, D_8088BF60.z, MTXMODE_NEW);
    } else {
        Matrix_Translate(pthis->dyna.actor.home.pos.x, pthis->dyna.actor.home.pos.y - 40.0f, pthis->dyna.actor.home.pos.z,
                         MTXMODE_NEW);
    }

    Matrix_RotateZYX(0, Camera_GetCamDirYaw(GET_ACTIVE_CAM(globalCtx)) + 0x8000, 0, MTXMODE_APPLY);
    Matrix_Translate(-10.5f, 0.0f, 0.0f, MTXMODE_APPLY);
    Matrix_Scale(6.0f, pthis->unk_16C, 6.0f, MTXMODE_APPLY);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sVerticalFlamesTexs[globalCtx->gameplayFrames & 7]));
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_hidan_rock.c", 853),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gFireTempleBigVerticalFlameDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_hidan_rock.c", 857);
}

void BgHidanRock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHidanRock* pthis = (BgHidanRock*)thisx;
    s32 pad;

    if (pthis->type == 0) {
        Gfx_DrawDListOpa(globalCtx, gFireTempleStoneBlock1DL);
    } else {
        Gfx_DrawDListOpa(globalCtx, gFireTempleStoneBlock2DL);
    }

    if (pthis->unk_16C > 0.0f) {
        if (pthis->type == 0) {
            SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &D_8088BF60, &pthis->unk_170);
        } else {
            SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &pthis->dyna.actor.home.pos, &pthis->unk_170);
        }

        func_80078914(&pthis->unk_170, NA_SE_EV_FIRE_PILLAR - SFX_FLAG);
        func_8088BC40(globalCtx, pthis);
    }
}

void BgHidanRock_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_8088BFC0_42 = 0.0f;

    D_8088BF60 = { 3310.0f, 120.0f, 0.0f };

    Bg_Hidan_Rock_InitVars = {
        ACTOR_BG_HIDAN_ROCK,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_HIDAN_OBJECTS,
        sizeof(BgHidanRock),
        (ActorFunc)BgHidanRock_Init,
        (ActorFunc)BgHidanRock_Destroy,
        (ActorFunc)BgHidanRock_Update,
        (ActorFunc)BgHidanRock_Draw,
        (ActorFunc)BgHidanRock_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_NONE,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x01, 0x04 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NONE,
            BUMP_NONE,
            OCELEM_NONE,
        },
        { 45, 77, -40, { 3310, 120, 0 } },
    };

}

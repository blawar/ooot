#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_BDAN_OBJECTS_Z_BG_BDAN_OBJECTS_C
#include "actor_common.h"
/*
 * File: z_bg_bdan_objects.c
 * Overlay: ovl_Bg_Bdan_Objects
 * Description: Lord Jabu-Jabu Objects
 */

#include "z_bg_bdan_objects.h"
#include "objects/object_bdan_objects/object_bdan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800A9F30.h"
#include "def/code_800EC960.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_play.h"
#include "def/z_quake.h"

#define FLAGS ACTOR_FLAG_4

void BgBdanObjects_Init(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanObjects_Destroy(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanObjects_Update(Actor* pthisx, GlobalContext* globalCtx);
void BgBdanObjects_Draw(Actor* pthisx, GlobalContext* globalCtx);

void func_8086C054(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C1A0(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C29C(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C55C(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C5BC(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C618(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C6EC(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C76C(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C7D0(BgBdanObjects* pthis, GlobalContext* globalCtx);
void BgBdanObjects_DoNothing(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C874(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C9A8(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086C9F0(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086CABC(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086CB10(BgBdanObjects* pthis, GlobalContext* globalCtx);
void func_8086CB8C(BgBdanObjects* pthis, GlobalContext* globalCtx);

ActorInit Bg_Bdan_Objects_InitVars = {
    ACTOR_BG_BDAN_OBJECTS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_BDAN_OBJECTS,
    sizeof(BgBdanObjects),
    (ActorFunc)BgBdanObjects_Init,
    (ActorFunc)BgBdanObjects_Destroy,
    (ActorFunc)BgBdanObjects_Update,
    (ActorFunc)BgBdanObjects_Draw,
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
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_HARD,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 0x00BB, 0x0050, 0x0000, { 0 } },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static Gfx* sDLists[] = {
    gJabuObjectsLargeRotatingSpikePlatformDL,
    gJabuElevatorPlatformDL,
    gJabuWaterDL,
    gJabuFallingPlatformDL,
};

s32 BgBdanObjects_GetContactRu1(BgBdanObjects* pthis, s32 arg1) {
    switch (arg1) {
        case 0:
            return pthis->cameraSetting == CAM_SET_NORMAL0;
        case 4:
            return gSaveContext.infTable[20] & 0x40;
        case 3:
            return pthis->cameraSetting == CAM_SET_DUNGEON1;
        default:
            osSyncPrintf("Bg_Bdan_Objects_Get_Contact_Ru1\nそんな受信モードは無い%d!!!!!!!!\n");
            return -1;
    }
}

void BgBdanObjects_SetContactRu1(BgBdanObjects* pthis, s32 arg1) {
    switch (arg1) {
        case 1:
            pthis->cameraSetting = CAM_SET_NORMAL1;
            break;
        case 2:
            pthis->cameraSetting = CAM_SET_DUNGEON0;
            break;
        case 4:
            gSaveContext.infTable[20] |= 0x40;
            break;
        default:
            osSyncPrintf("Bg_Bdan_Objects_Set_Contact_Ru1\nそんな送信モードは無い%d!!!!!!!!\n");
    }
}

void BgBdanObjects_Init(Actor* pthisx, GlobalContext* globalCtx) {
    s32 pad;
    BgBdanObjects* pthis = (BgBdanObjects*)pthisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    pthis->switchFlag = (pthisx->params >> 8) & 0x3F;
    pthisx->params &= 0xFF;
    if (pthisx->params == 2) {
        pthisx->flags |= ACTOR_FLAG_4 | ACTOR_FLAG_5;
        globalCtx->colCtx.colHeader->waterBoxes[7].ySurface = pthisx->world.pos.y;
        pthis->actionFunc = func_8086C9A8;
        return;
    }
    if (pthisx->params == 0) {
        CollisionHeader_GetVirtual(&gJabuBigOctoPlatformCol, &colHeader);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->dyna.actor, &sCylinderInit);
        pthisx->world.pos.y += -79.0f;
        if (Flags_GetClear(globalCtx, pthisx->room)) {
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
            pthis->actionFunc = func_8086C6EC;
        } else {
            if (BgBdanObjects_GetContactRu1(pthis, 4)) {
                if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_BIGOKUTA,
                                       pthisx->home.pos.x, pthisx->home.pos.y, pthisx->home.pos.z, 0,
                                       pthisx->shape.rot.y + 0x8000, 0, 3) != NULL) {
                    pthisx->child->world.pos.z = pthisx->child->home.pos.z + 263.0f;
                }
                pthisx->world.rot.y = 0;
                pthis->actionFunc = func_8086C618;
                pthisx->world.pos.y = pthisx->home.pos.y + -70.0f;
            } else {
                Flags_SetSwitch(globalCtx, pthis->switchFlag);
                pthis->timer = 0;
                pthis->actionFunc = func_8086C054;
            }
        }
    } else {
        if (pthisx->params == 1) {
            CollisionHeader_GetVirtual(&gJabuElevatorCol, &colHeader);
            pthis->timer = 512;
            pthis->switchFlag = 0;
            pthis->actionFunc = func_8086C874;
        } else {
            CollisionHeader_GetVirtual(&gJabuLoweringPlatformCol, &colHeader);
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                pthis->actionFunc = BgBdanObjects_DoNothing;
                pthisx->world.pos.y = pthisx->home.pos.y - 400.0f;
            } else {
                pthis->actionFunc = func_8086CB10;
            }
        }
    }
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, pthisx, colHeader);
}

void BgBdanObjects_Destroy(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanObjects* pthis = (BgBdanObjects*)pthisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    if (pthisx->params == 0) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }
}

void func_8086C054(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (BgBdanObjects_GetContactRu1(pthis, 0)) {
        if (pthis->dyna.actor.xzDistToPlayer < 250.0f) {
            BgBdanObjects_SetContactRu1(pthis, 1);
            pthis->timer = 20;
            OnePointCutscene_Init(globalCtx, 3070, -99, &pthis->dyna.actor, MAIN_CAM);
            player->actor.world.pos.x = -1130.0f;
            player->actor.world.pos.y = -1025.0f;
            player->actor.world.pos.z = -3300.0f;
            func_800AA000(0.0f, 0xFF, 0x14, 0x96);
        }
    } else if (pthis->timer != 0) {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if (pthis->timer == 0) {
            pthis->actionFunc = func_8086C1A0;
        }
    }

    if (!Gameplay_InCsMode(globalCtx) && !BgBdanObjects_GetContactRu1(pthis, 0)) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y + -79.0f;
    } else {
        pthis->dyna.actor.world.pos.y = (pthis->dyna.actor.home.pos.y + -79.0f) - 5.0f;
    }
}

void func_8086C1A0(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 500.0f, 0.5f, 7.5f, 1.0f) <
        0.1f) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_STOP_A);
        pthis->actionFunc = func_8086C29C;
        pthis->timer = 30;
        BgBdanObjects_SetContactRu1(pthis, 2);
        func_800AA000(0.0f, 0xFF, 0x14, 0x96);
    } else {
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if (pthis->timer == 0) {
            func_800AA000(0.0f, 0x78, 0x14, 0xA);
            pthis->timer = 11;
        }
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_RISING - SFX_FLAG);
    }
}

void func_8086C29C(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    s32 temp;

    if (pthis->timer != 0) {
        pthis->timer--;
        if (pthis->timer == 0) {
            temp = Quake_Add(GET_ACTIVE_CAM(globalCtx), 1);
            Quake_SetSpeed(temp, 0x3A98);
            Quake_SetQuakeValues(temp, 0, 1, 0xFA, 1);
            Quake_SetCountdown(temp, 0xA);
        }
    }

    if (BgBdanObjects_GetContactRu1(pthis, 3)) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_EN_BIGOKUTA,
                           pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y + 140.0f,
                           pthis->dyna.actor.world.pos.z, 0, pthis->dyna.actor.shape.rot.y + 0x8000, 0, 0);
        BgBdanObjects_SetContactRu1(pthis, 4);
        pthis->timer = 10;
        pthis->actionFunc = func_8086C55C;
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
    }
}

void func_8086C3D8(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->dyna.actor.velocity.y += 0.5f;
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + -70.0f,
                     pthis->dyna.actor.velocity.y)) {
        pthis->dyna.actor.world.rot.y = 0;
        pthis->timer = 60;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_STOP_U);
        pthis->dyna.actor.child->world.pos.y = pthis->dyna.actor.world.pos.y + 140.0f;
        pthis->actionFunc = func_8086C5BC;
        OnePointCutscene_Init(globalCtx, 3080, -99, pthis->dyna.actor.child, MAIN_CAM);
        player->actor.world.pos.x = -1130.0f;
        player->actor.world.pos.y = -1025.0f;
        player->actor.world.pos.z = -3500.0f;
        player->actor.shape.rot.y = 0x7530;
        player->actor.world.rot.y = player->actor.shape.rot.y;
        func_800AA000(0.0f, 0xFF, 0x1E, 0x96);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_FALL - SFX_FLAG);
        if (pthis->timer != 0) {
            pthis->timer--;
        }
        if (pthis->timer == 0) {
            func_800AA000(0.0f, 0x78, 0x14, 0xA);
            pthis->timer = 11;
        }
        if (pthis->dyna.actor.child != NULL) {
            pthis->dyna.actor.child->world.pos.y = pthis->dyna.actor.world.pos.y + 140.0f;
        }
    }
}

void func_8086C55C(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    pthis->timer--;

    if (pthis->timer == 0) {
        Flags_UnsetSwitch(globalCtx, pthis->switchFlag);
    } else if (pthis->timer == -40) {
        pthis->timer = 0;
        pthis->actionFunc = func_8086C3D8;
    }
}

void func_8086C5BC(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if ((pthis->timer == 0) && (pthis->dyna.actor.child != NULL)) {
        if (pthis->dyna.actor.child->params == 2) {
            pthis->actionFunc = func_8086C618;
        } else if (pthis->dyna.actor.child->params == 0) {
            pthis->dyna.actor.child->params = 1;
        }
    }
}

void func_8086C618(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(&pthis->dyna.actor, &pthis->collider);
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    if (Flags_GetClear(globalCtx, pthis->dyna.actor.room)) {
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        pthis->dyna.actor.home.rot.y = (s16)(pthis->dyna.actor.shape.rot.y + 0x2000) & 0xC000;
        pthis->actionFunc = func_8086C6EC;
    } else {
        pthis->dyna.actor.shape.rot.y += pthis->dyna.actor.world.rot.y;
        func_800F436C(&pthis->dyna.actor.projectedPos, 0x2063, ABS(pthis->dyna.actor.world.rot.y) / 512.0f);
    }
}

void func_8086C6EC(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    s32 cond = Math_ScaledStepToS(&pthis->dyna.actor.shape.rot.y, pthis->dyna.actor.home.rot.y, 0x200);

    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + -125.0f, 3.0f)) {
        if (cond) {
            pthis->actionFunc = func_8086C76C;
        }
    }
}

void func_8086C76C(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) {
        if (pthis->dyna.actor.xzDistToPlayer < 120.0f) {
            pthis->actionFunc = func_8086C7D0;
            OnePointCutscene_Init(globalCtx, 3090, -99, &pthis->dyna.actor, MAIN_CAM);
        }
    }
}

void func_8086C7D0(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (Math_SmoothStepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 965.0f, 0.5f, 15.0f, 0.2f) <
        0.01f) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_STOP_A);
        pthis->actionFunc = BgBdanObjects_DoNothing;
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_RISING - SFX_FLAG);
    }
}

void BgBdanObjects_DoNothing(BgBdanObjects* pthis, GlobalContext* globalCtx) {
}

void func_8086C874(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->switchFlag == 0) {
        if (func_8004356C(&pthis->dyna)) {
            pthis->cameraSetting = globalCtx->cameraPtrs[MAIN_CAM]->setting;
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_NORMAL2);
            func_8005AD1C(globalCtx->cameraPtrs[MAIN_CAM], 4);
            pthis->switchFlag = 10;
        }
    } else {
        Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], CAM_SET_NORMAL2);
        if (!func_8004356C(&pthis->dyna)) {
            if (pthis->switchFlag != 0) {
                pthis->switchFlag--;
            }
        }
        if (pthis->switchFlag == 0) {
            if (1) {}
            Camera_ChangeSetting(globalCtx->cameraPtrs[MAIN_CAM], pthis->cameraSetting);
            func_8005ACFC(globalCtx->cameraPtrs[MAIN_CAM], 4);
        }
    }
    pthis->dyna.actor.world.pos.y =
        pthis->dyna.actor.home.pos.y - (sinf(pthis->timer * (M_PI / 256.0f)) * 471.24f); // pi * 150
    if (pthis->timer == 0) {
        pthis->timer = 512;
    }
}

void func_8086C9A8(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        pthis->timer = 100;
        pthis->actionFunc = func_8086C9F0;
    }
}

void func_8086C9F0(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer == 0) {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 0.5f)) {
            Flags_UnsetSwitch(globalCtx, pthis->switchFlag);
            pthis->actionFunc = func_8086C9A8;
        }
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    } else {
        if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 75.0f, 0.5f)) {
            pthis->actionFunc = func_8086CABC;
        }
        func_8002F948(&pthis->dyna.actor, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
    }
    globalCtx->colCtx.colHeader->waterBoxes[7].ySurface = pthis->dyna.actor.world.pos.y;
}

void func_8086CABC(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    func_8002F994(&pthis->dyna.actor, pthis->timer);
    if (pthis->timer == 0) {
        pthis->actionFunc = func_8086C9F0;
    }
}

void func_8086CB10(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (func_8004356C(&pthis->dyna)) {
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        pthis->timer = 50;
        pthis->actionFunc = func_8086CB8C;
        pthis->dyna.actor.home.pos.y -= 200.0f;
        OnePointCutscene_Init(globalCtx, 3100, 51, &pthis->dyna.actor, MAIN_CAM);
    }
}

void func_8086CB8C(BgBdanObjects* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - (cosf(pthis->timer * (M_PI / 50.0f)) * 200.0f);

    if (pthis->timer == 0) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_STOP_U);
        pthis->actionFunc = BgBdanObjects_DoNothing;
        Gameplay_CopyCamera(globalCtx, MAIN_CAM, SUBCAM_ACTIVE);
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_BUYOSTAND_FALL - SFX_FLAG);
    }
}

void BgBdanObjects_Update(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanObjects* pthis = (BgBdanObjects*)pthisx;

    Actor_SetFocus(pthisx, 50.0f);
    pthis->actionFunc(pthis, globalCtx);
}

void BgBdanObjects_Draw(Actor* pthisx, GlobalContext* globalCtx) {
    BgBdanObjects* pthis = (BgBdanObjects*)pthisx;

    if (pthisx->params == 0) {
        if (pthis->actionFunc == func_8086C054) {
            if (((pthisx->home.pos.y + -79.0f) - 5.0f) < pthisx->world.pos.y) {
                Matrix_Translate(0.0f, -50.0f, 0.0f, MTXMODE_APPLY);
            }
        }
    }

    if (pthisx->params == 2) {
        Gfx_DrawDListXlu(globalCtx, gJabuWaterDL);
    } else {
        Gfx_DrawDListOpa(globalCtx, sDLists[pthisx->params]);
    }
}

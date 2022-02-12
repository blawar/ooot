#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_YDAN_SP_Z_BG_YDAN_SP_C
#include "actor_common.h"
/*
 * File: z_bg_ydan_sp.c
 * Overlay: ovl_Bg_Ydan_Sp
 * Description: Webs
 */

#include "z_bg_ydan_sp.h"
#include "objects/object_ydan_objects/object_ydan_objects.h"
#include "def/code_80043480.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

#define FLAGS 0

void BgYdanSp_Init(Actor* thisx, GlobalContext* globalCtx);
void BgYdanSp_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgYdanSp_Update(Actor* thisx, GlobalContext* globalCtx);
void BgYdanSp_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgYdanSp_BurnFloorWeb(BgYdanSp* pthis, GlobalContext* globalCtx);
void BgYdanSp_FloorWebIdle(BgYdanSp* pthis, GlobalContext* globalCtx);
void BgYdanSp_BurnWallWeb(BgYdanSp* pthis, GlobalContext* globalCtx);
void BgYdanSp_WallWebIdle(BgYdanSp* pthis, GlobalContext* globalCtx);

typedef enum {
    /* 0 */ WEB_FLOOR,
    /* 1 */ WEB_WALL
} BgYdanSpType;

ActorInit Bg_Ydan_Sp_InitVars = {
    ACTOR_BG_YDAN_SP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanSp),
    (ActorFunc)BgYdanSp_Init,
    (ActorFunc)BgYdanSp_Destroy,
    (ActorFunc)BgYdanSp_Update,
    (ActorFunc)BgYdanSp_Draw,
};

static ColliderTrisElementInit sTrisItemsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0x00020800, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 75.0f, -8.0f, 75.0f }, { -75.0f, -8.0f, 75.0f }, { -75.0f, -8.0f, -75.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x00 },
            { 0x00020800, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 140.0f, 288.8f, 0.0f }, { -140.0f, 288.0f, 0.0f }, { -140.0f, 0.0f, 0.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_TRIS,
    },
    2,
    sTrisItemsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgYdanSp_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanSp* pthis = (BgYdanSp*)thisx;
    ColliderTrisElementInit* ti0 = &sTrisItemsInit[0];
    Vec3f tri[3];
    s32 i;
    CollisionHeader* colHeader = NULL;
    ColliderTrisElementInit* ti1 = &sTrisItemsInit[1];
    f32 cossY;
    f32 sinsY;
    f32 cossX;
    f32 nSinsX;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->isDestroyedSwitchFlag = thisx->params & 0x3F;
    pthis->burnSwitchFlag = (thisx->params >> 6) & 0x3F;
    pthis->dyna.actor.params = (thisx->params >> 0xC) & 0xF;
    DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
    Collider_InitTris(globalCtx, &pthis->trisCollider);
    Collider_SetTris(globalCtx, &pthis->trisCollider, &pthis->dyna.actor, &sTrisInit, pthis->trisColliderItems);
    if (pthis->dyna.actor.params == WEB_FLOOR) {
        CollisionHeader_GetVirtual(&gDTWebFloorCol, &colHeader);
        pthis->actionFunc = BgYdanSp_FloorWebIdle;

        for (i = 0; i < 3; i++) {
            tri[i].x = ti0->dim.vtx[i].x + pthis->dyna.actor.world.pos.x;
            tri[i].y = ti0->dim.vtx[i].y + pthis->dyna.actor.world.pos.y;
            tri[i].z = ti0->dim.vtx[i].z + pthis->dyna.actor.world.pos.z;
        }

        Collider_SetTrisVertices(&pthis->trisCollider, 0, &tri[0], &tri[1], &tri[2]);
        tri[1].x = tri[0].x;
        tri[1].z = tri[2].z;
        Collider_SetTrisVertices(&pthis->trisCollider, 1, &tri[0], &tri[2], &tri[1]);
        pthis->unk16C = 0.0f;
    } else {
        CollisionHeader_GetVirtual(&gDTWebWallCol, &colHeader);
        pthis->actionFunc = BgYdanSp_WallWebIdle;
        Actor_SetFocus(&pthis->dyna.actor, 30.0f);
        sinsY = Math_SinS(pthis->dyna.actor.shape.rot.y);
        cossY = Math_CosS(pthis->dyna.actor.shape.rot.y);
        nSinsX = -Math_SinS(pthis->dyna.actor.shape.rot.x);
        cossX = Math_CosS(pthis->dyna.actor.shape.rot.x);

        for (i = 0; i < 3; i++) {
            tri[i].x =
                pthis->dyna.actor.world.pos.x + (cossY * ti1->dim.vtx[i].x) - (sinsY * ti1->dim.vtx[i].y * nSinsX);
            tri[i].y = pthis->dyna.actor.world.pos.y + (ti1->dim.vtx[i].y * cossX);
            tri[i].z =
                pthis->dyna.actor.world.pos.z - (sinsY * ti1->dim.vtx[i].x) + (ti1->dim.vtx[i].y * cossY * nSinsX);
        }

        Collider_SetTrisVertices(&pthis->trisCollider, 0, &tri[0], &tri[1], &tri[2]);

        tri[1].x = pthis->dyna.actor.world.pos.x + (cossY * ti1->dim.vtx[0].x) - (ti1->dim.vtx[2].y * sinsY * nSinsX);
        tri[1].y = pthis->dyna.actor.world.pos.y + (ti1->dim.vtx[2].y * cossX);
        tri[1].z = pthis->dyna.actor.world.pos.z - (sinsY * ti1->dim.vtx[0].x) + (ti1->dim.vtx[2].y * cossY * nSinsX);
        Collider_SetTrisVertices(&pthis->trisCollider, 1, &tri[0], &tri[2], &tri[1]);
    }
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    pthis->timer = 0;
    if (Flags_GetSwitch(globalCtx, pthis->isDestroyedSwitchFlag)) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgYdanSp_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanSp* pthis = (BgYdanSp*)thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    Collider_DestroyTris(globalCtx, &pthis->trisCollider);
}

void BgYdanSp_UpdateFloorWebCollision(BgYdanSp* pthis) {
    s16 newY;
    CollisionHeader* colHeader;

    colHeader = SEGMENTED_TO_VIRTUAL(&gDTWebFloorCol);
    colHeader->vtxList = SEGMENTED_TO_VIRTUAL(colHeader->vtxList);
    newY = (pthis->dyna.actor.home.pos.y - pthis->dyna.actor.world.pos.y) * 10;
    colHeader->vtxList[14].y = newY;
    colHeader->vtxList[12].y = newY;
    colHeader->vtxList[10].y = newY;
    colHeader->vtxList[9].y = newY;
    colHeader->vtxList[6].y = newY;
    colHeader->vtxList[5].y = newY;
    colHeader->vtxList[1].y = newY;
    colHeader->vtxList[0].y = newY;
}

void BgYdanSp_BurnWeb(BgYdanSp* pthis, GlobalContext* globalCtx) {
    pthis->timer = 30;
    pthis = pthis;
    func_80078884(NA_SE_SY_CORRECT_CHIME);
    Flags_SetSwitch(globalCtx, pthis->isDestroyedSwitchFlag);
    if (pthis->dyna.actor.params == WEB_FLOOR) {
        pthis->actionFunc = BgYdanSp_BurnFloorWeb;
    } else {
        pthis->actionFunc = BgYdanSp_BurnWallWeb;
    }
}

void BgYdanSp_BurnFloorWeb(BgYdanSp* pthis, GlobalContext* globalCtx) {
    static Vec3f accel = { 0 };
    Vec3f velocity;
    Vec3f pos2;
    f32 distXZ;
    f32 sins;
    f32 coss;
    s16 rot;
    s16 rot2;
    s32 i;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    if ((pthis->timer % 3) == 0) {
        rot2 = Rand_ZeroOne() * 0x2AAA;
        velocity.y = 0.0f;
        pos2.y = pthis->dyna.actor.world.pos.y;

        for (i = 0; i < 6; i++) {
            rot = Rand_CenteredFloat(0x2800) + rot2;
            sins = Math_SinS(rot);
            coss = Math_CosS(rot);
            pos2.x = pthis->dyna.actor.world.pos.x + (120.0f * sins);
            pos2.z = pthis->dyna.actor.world.pos.z + (120.0f * coss);
            distXZ = Math_Vec3f_DistXZ(&pthis->dyna.actor.home.pos, &pos2) * (1.0f / 120.0f);
            if (distXZ < 0.7f) {
                sins = Math_SinS(rot + 0x8000);
                coss = Math_CosS(rot + 0x8000);
                pos2.x = pthis->dyna.actor.world.pos.x + (120.0f * sins);
                pos2.z = pthis->dyna.actor.world.pos.z + (120.0f * coss);
                distXZ = Math_Vec3f_DistXZ(&pthis->dyna.actor.home.pos, &pos2) * (1.0f / 120.0f);
            }
            velocity.x = (7.0f * sins) * distXZ;
            velocity.y = 0.0f;
            velocity.z = (7.0f * coss) * distXZ;
            EffectSsDeadDb_Spawn(globalCtx, &pthis->dyna.actor.home.pos, &velocity, &accel, 60, 6, 255, 255, 150, 170,
                                 255, 0, 0, 1, 0xE, 1);
            rot2 += 0x2AAA;
        }
    }
}

void BgYdanSp_FloorWebBroken(BgYdanSp* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void BgYdanSp_FloorWebBreaking(BgYdanSp* pthis, GlobalContext* globalCtx) {
    static Color_RGBA8 primColor = { 250, 250, 250, 255 };
    static Color_RGBA8 envColor = { 180, 180, 180, 255 };
    static Vec3f zeroVec = { 0 };
    s32 i;
    Vec3f pos;
    s16 rot;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->dyna.actor.world.pos.y = (sinf((f32)pthis->timer * (M_PI / 20)) * pthis->unk16C) + pthis->dyna.actor.home.pos.y;
    if (pthis->dyna.actor.home.pos.y - pthis->dyna.actor.world.pos.y > 190.0f) {
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->timer = 40;
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        Flags_SetSwitch(globalCtx, pthis->isDestroyedSwitchFlag);
        pthis->actionFunc = BgYdanSp_FloorWebBroken;
        pos.y = pthis->dyna.actor.world.pos.y - 60.0f;
        rot = 0;
        for (i = 0; i < 6; i++) {
            pos.x = Math_SinS(rot) * 60.0f + pthis->dyna.actor.world.pos.x;
            pos.z = Math_CosS(rot) * 60.0f + pthis->dyna.actor.world.pos.z;
            func_8002829C(globalCtx, &pos, &zeroVec, &zeroVec, &primColor, &envColor, 1000, 10);

            rot += 0x2AAA;
        }
    }
    BgYdanSp_UpdateFloorWebCollision(pthis);
}

void BgYdanSp_FloorWebIdle(BgYdanSp* pthis, GlobalContext* globalCtx) {
    Player* player;
    Vec3f webPos;
    f32 sqrtFallDistance;
    f32 unk;

    player = GET_PLAYER(globalCtx);
    webPos.x = pthis->dyna.actor.world.pos.x;
    webPos.y = pthis->dyna.actor.world.pos.y - 50.0f;
    webPos.z = pthis->dyna.actor.world.pos.z;
    if (Player_IsBurningStickInRange(globalCtx, &webPos, 70.0f, 50.0f) != 0) {
        pthis->dyna.actor.home.pos.x = player->swordInfo[0].tip.x;
        pthis->dyna.actor.home.pos.z = player->swordInfo[0].tip.z;
        BgYdanSp_BurnWeb(pthis, globalCtx);
        return;
    }
    if ((pthis->trisCollider.base.acFlags & 2) != 0) {
        BgYdanSp_BurnWeb(pthis, globalCtx);
        return;
    }
    if (func_8004356C(&pthis->dyna)) {
        sqrtFallDistance = sqrtf(CLAMP_MIN(player->fallDistance, 0.0f));
        if (player->fallDistance > 750.0f) {
            if (pthis->dyna.actor.xzDistToPlayer < 80.0f) {
                pthis->unk16C = 200.0f;
                pthis->dyna.actor.room = -1;
                pthis->dyna.actor.flags |= ACTOR_FLAG_4;
                pthis->timer = 40;
                Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WEB_BROKEN);
                pthis->actionFunc = BgYdanSp_FloorWebBreaking;
                return;
            }
        }
        unk = sqrtFallDistance + sqrtFallDistance;
        if (pthis->unk16C < unk) {
            if (unk > 2.0f) {
                pthis->unk16C = unk;
                pthis->timer = 14;
            }
        }
        if (player->actor.speedXZ != 0.0f) {
            if (pthis->unk16C < 0.1f) {
                pthis->timer = 14;
            }
            if (pthis->unk16C < 2.0f) {
                pthis->unk16C = 2.0f;
            } else {
                pthis->unk16C = pthis->unk16C;
            }
        }
    }
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        pthis->timer = 14;
    }
    pthis->dyna.actor.world.pos.y = sinf((f32)pthis->timer * (M_PI / 7)) * pthis->unk16C + pthis->dyna.actor.home.pos.y;
    Math_ApproachZeroF(&pthis->unk16C, 1.0f, 0.8f);
    if (pthis->timer == 13) {
        if (pthis->unk16C > 3.0f) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WEB_VIBRATION);
        } else {
            Audio_StopSfxById(NA_SE_EV_WEB_VIBRATION);
        }
    }
    BgYdanSp_UpdateFloorWebCollision(pthis);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->trisCollider.base);
}

void BgYdanSp_BurnWallWeb(BgYdanSp* pthis, GlobalContext* globalCtx) {
    static Vec3f accel = { 0 };
    Vec3f velocity;
    Vec3f spC8;
    f32 distXYZ;
    f32 sins;
    f32 coss;
    f32 coss2;
    s16 rot;
    s16 rot2;
    s32 i;

    if (pthis->timer != 0) {
        pthis->timer--;
    }
    if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
        return;
    }
    if ((pthis->timer % 3) == 0) {
        rot2 = Rand_ZeroOne() * 0x2AAA;

        for (i = 0; i < 6; i++) {
            rot = Rand_CenteredFloat(0x2800) + rot2;
            sins = Math_SinS(rot);
            coss = Math_CosS(rot);
            coss2 = Math_CosS(pthis->dyna.actor.shape.rot.y) * sins;
            sins *= Math_SinS(pthis->dyna.actor.shape.rot.y);

            spC8.x = pthis->dyna.actor.world.pos.x + (140.0f * coss2);
            spC8.y = pthis->dyna.actor.world.pos.y + (140.0f * (1.0f + coss));
            spC8.z = pthis->dyna.actor.world.pos.z - (140.0f * sins);
            distXYZ = Math_Vec3f_DistXYZ(&pthis->dyna.actor.home.pos, &spC8) * (1.0f / 140.0f);
            if (distXYZ < 0.65f) {
                sins = Math_SinS(rot + 0x8000);
                coss = Math_CosS(rot + 0x8000);
                coss2 = Math_CosS(pthis->dyna.actor.shape.rot.y) * sins;
                sins *= Math_SinS(pthis->dyna.actor.shape.rot.y);
                spC8.x = pthis->dyna.actor.world.pos.x + (140.0f * coss2);
                spC8.y = pthis->dyna.actor.world.pos.y + (140.0f * (1.0f + coss));
                spC8.z = pthis->dyna.actor.world.pos.z - (140.0f * sins);
                distXYZ = Math_Vec3f_DistXYZ(&pthis->dyna.actor.home.pos, &spC8) * (1.0f / 140.0f);
            }
            velocity.x = 6.5f * coss2 * distXYZ;
            velocity.y = 6.5f * coss * distXYZ;
            velocity.z = -6.5f * sins * distXYZ;
            EffectSsDeadDb_Spawn(globalCtx, &pthis->dyna.actor.home.pos, &velocity, &accel, 80, 6, 255, 255, 150, 170,
                                 255, 0, 0, 1, 0xE, 1);
            rot2 += 0x2AAA;
        }
    }
}

void BgYdanSp_WallWebIdle(BgYdanSp* pthis, GlobalContext* globalCtx) {
    Player* player;
    Vec3f sp30;

    player = GET_PLAYER(globalCtx);
    if (Flags_GetSwitch(globalCtx, pthis->burnSwitchFlag) || (pthis->trisCollider.base.acFlags & 2)) {
        pthis->dyna.actor.home.pos.y = pthis->dyna.actor.world.pos.y + 80.0f;
        BgYdanSp_BurnWeb(pthis, globalCtx);
    } else if (player->heldItemActionParam == PLAYER_AP_STICK && player->unk_860 != 0) {
        func_8002DBD0(&pthis->dyna.actor, &sp30, &player->swordInfo[0].tip);
        if (fabsf(sp30.x) < 100.0f && sp30.z < 1.0f && sp30.y < 200.0f) {
            OnePointCutscene_Init(globalCtx, 3020, 40, &pthis->dyna.actor, MAIN_CAM);
            Math_Vec3f_Copy(&pthis->dyna.actor.home.pos, &player->swordInfo[0].tip);
            BgYdanSp_BurnWeb(pthis, globalCtx);
        }
    }
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->trisCollider.base);
}

void BgYdanSp_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanSp* pthis = (BgYdanSp*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgYdanSp_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanSp* pthis = (BgYdanSp*)thisx;
    s32 i;
    MtxF mtxF;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 781);
    func_80093D84(globalCtx->state.gfxCtx);
    if (thisx->params == WEB_WALL) {
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 787),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDTWebWallDL);
    } else if (pthis->actionFunc == BgYdanSp_FloorWebBroken) {
        Matrix_Get(&mtxF);
        if (pthis->timer == 40) {
            Matrix_Translate(0.0f, (thisx->home.pos.y - thisx->world.pos.y) * 10.0f, 0.0f, MTXMODE_APPLY);
            Matrix_Scale(1.0f, ((thisx->home.pos.y - thisx->world.pos.y) + 10.0f) * 0.1f, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 808),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDTWebFloorDL);
        }
        for (i = 0; i < 8; i++) {
            Matrix_Put(&mtxF);
            Matrix_RotateZYX(-0x5A0, i * 0x2000, 0, MTXMODE_APPLY);
            Matrix_Translate(0.0f, 700.0f, -900.0f, MTXMODE_APPLY);
            Matrix_Scale(3.5f, 5.0f, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 830),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDTUnknownWebDL);
        }
    } else {
        Matrix_Translate(0.0f, (thisx->home.pos.y - thisx->world.pos.y) * 10.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(1.0f, ((thisx->home.pos.y - thisx->world.pos.y) + 10.0f) * 0.1f, 1.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 849),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDTWebFloorDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_ydan_sp.c", 856);
}

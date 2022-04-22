#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_MORI_HASHIGO_Z_BG_MORI_HASHIGO_C
#include "actor_common.h"
/*
 * File: z_bg_mori_hashigo.c
 * Overlay: ovl_Bg_Mori_Hashigo
 * Description: Falling ladder and clasp that holds it. Unused.
 */

#include "z_bg_mori_hashigo.h"
#include "objects/object_mori_objects/object_mori_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS 0

void BgMoriHashigo_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashigo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgMoriHashigo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashigo_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHashigo_Draw(Actor* thisx, GlobalContext* globalCtx);

void BgMoriHashigo_SetupWaitForMoriTex(BgMoriHashigo* pthis);
void BgMoriHashigo_WaitForMoriTex(BgMoriHashigo* pthis, GlobalContext* globalCtx);
void BgMoriHashigo_SetupClasp(BgMoriHashigo* pthis);
void BgMoriHashigo_Clasp(BgMoriHashigo* pthis, GlobalContext* globalCtx);
void BgMoriHashigo_SetupLadderWait(BgMoriHashigo* pthis);
void BgMoriHashigo_LadderWait(BgMoriHashigo* pthis, GlobalContext* globalCtx);
void BgMoriHashigo_SetupLadderFall(BgMoriHashigo* pthis);
void BgMoriHashigo_LadderFall(BgMoriHashigo* pthis, GlobalContext* globalCtx);
void BgMoriHashigo_SetupLadderRest(BgMoriHashigo* pthis);

static f32 bounceSpeed_48[3] = { 4.0f, 2.7f, 1.7f };


ActorInit Bg_Mori_Hashigo_InitVars = {
    ACTOR_BG_MORI_HASHIGO,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MORI_OBJECTS,
    sizeof(BgMoriHashigo),
    (ActorFunc)BgMoriHashigo_Init,
    (ActorFunc)BgMoriHashigo_Destroy,
    (ActorFunc)BgMoriHashigo_Update,
    NULL,
    (ActorFunc)BgMoriHashigo_Reset,
};

static ColliderJntSphElementInit sJntSphElementsInit[1] = {
    {
        {
            ELEMTYPE_UNK4,
            { 0x00000000, 0x00, 0x00 },
            { 0x0001F820, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 0, { { 0, 0, 0 }, 25 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementsInit,
};

static InitChainEntry sInitChainClasp[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),  ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_CONTINUE), ICHAIN_U8(targetMode, 3, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 40, ICHAIN_CONTINUE),    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

static InitChainEntry sInitChainLadder[] = {
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

void BgMoriHashigo_InitDynapoly(BgMoriHashigo* pthis, GlobalContext* globalCtx, CollisionHeader* collision,
                                s32 moveFlag) {
    s32 pad;
    CollisionHeader* colHeader;
    s32 pad2;

    colHeader = NULL;
    DynaPolyActor_Init(&pthis->dyna, moveFlag);
    CollisionHeader_GetVirtual(collision, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        // "Warning : move BG login failed"
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_mori_hashigo.c", 164,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void BgMoriHashigo_InitCollider(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    s32 pad;

    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->dyna.actor, &sJntSphInit, pthis->colliderItems);

    pthis->collider.elements[0].dim.worldSphere.center.x = (s16)pthis->dyna.actor.world.pos.x;
    pthis->collider.elements[0].dim.worldSphere.center.y = (s16)pthis->dyna.actor.world.pos.y + 21;
    pthis->collider.elements[0].dim.worldSphere.center.z = (s16)pthis->dyna.actor.world.pos.z;
    pthis->collider.elements[0].dim.worldSphere.radius = 19;
}

s32 BgMoriHashigo_SpawnLadder(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    f32 sn;
    f32 cs;
    Vec3f pos;
    Actor* ladder;

    cs = Math_CosS(pthis->dyna.actor.shape.rot.y);
    sn = Math_SinS(pthis->dyna.actor.shape.rot.y);

    pos.x = 6.0f * sn + pthis->dyna.actor.world.pos.x;
    pos.y = -210.0f + pthis->dyna.actor.world.pos.y;
    pos.z = 6.0f * cs + pthis->dyna.actor.world.pos.z;

    ladder = Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_BG_MORI_HASHIGO, pos.x, pos.y,
                                pos.z, pthis->dyna.actor.world.rot.x, pthis->dyna.actor.world.rot.y,
                                pthis->dyna.actor.world.rot.z, 0);
    if (ladder != NULL) {
        return true;
    } else {
        // "Ladder failure"
        osSyncPrintf("Error : 梯子の発生失敗(%s %d)(arg_data 0x%04x)\n", "../z_bg_mori_hashigo.c", 220,
                     pthis->dyna.actor.params);
        return false;
    }
}

s32 BgMoriHashigo_InitClasp(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChainClasp);
    pthis->dyna.actor.flags |= ACTOR_FLAG_0;
    Actor_SetFocus(&pthis->dyna.actor, 55.0f);
    BgMoriHashigo_InitCollider(pthis, globalCtx);
    if ((pthis->dyna.actor.params == HASHIGO_CLASP) && !BgMoriHashigo_SpawnLadder(pthis, globalCtx)) {
        return false;
    } else {
        return true;
    }
}

s32 BgMoriHashigo_InitLadder(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    BgMoriHashigo_InitDynapoly(pthis, globalCtx, &gMoriHashigoCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChainLadder);
    return true;
}

void BgMoriHashigo_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashigo* pthis = (BgMoriHashigo*)thisx;

    if (pthis->dyna.actor.params == HASHIGO_CLASP) {
        if (!BgMoriHashigo_InitClasp(pthis, globalCtx)) {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
    } else if (pthis->dyna.actor.params == HASHIGO_LADDER) {
        if (!BgMoriHashigo_InitLadder(pthis, globalCtx)) {
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
    }
    pthis->moriTexObjIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (pthis->moriTexObjIndex < 0) {
        // "Bank danger!"
        osSyncPrintf("Error : バンク危険！(arg_data 0x%04x)(%s %d)\n", pthis->dyna.actor.params,
                     "../z_bg_mori_hashigo.c", 312);
        Actor_Kill(&pthis->dyna.actor);
    } else {
        BgMoriHashigo_SetupWaitForMoriTex(pthis);
        // "(Forest Temple Ladder and its clasp)"
        osSyncPrintf("(森の神殿 梯子とその留め金)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
    }
}

void BgMoriHashigo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashigo* pthis = (BgMoriHashigo*)thisx;

    if (pthis->dyna.actor.params == HASHIGO_LADDER) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
    if (pthis->dyna.actor.params == HASHIGO_CLASP) {
        Collider_DestroyJntSph(globalCtx, &pthis->collider);
    }
}

void BgMoriHashigo_SetupWaitForMoriTex(BgMoriHashigo* pthis) {
    pthis->actionFunc = BgMoriHashigo_WaitForMoriTex;
}

void BgMoriHashigo_WaitForMoriTex(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->moriTexObjIndex)) {
        if (pthis->dyna.actor.params == HASHIGO_CLASP) {
            BgMoriHashigo_SetupClasp(pthis);
        } else if (pthis->dyna.actor.params == HASHIGO_LADDER) {
            BgMoriHashigo_SetupLadderWait(pthis);
        }
        pthis->dyna.actor.draw = BgMoriHashigo_Draw;
    }
}

void BgMoriHashigo_SetupClasp(BgMoriHashigo* pthis) {
    pthis->actionFunc = BgMoriHashigo_Clasp;
}

void BgMoriHashigo_Clasp(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    if (pthis->hitTimer <= 0) {
        if (pthis->collider.base.acFlags & AC_HIT) {
            pthis->collider.base.acFlags &= ~AC_HIT;
            pthis->hitTimer = 10;
        } else {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

void BgMoriHashigo_SetupLadderWait(BgMoriHashigo* pthis) {
    pthis->actionFunc = BgMoriHashigo_LadderWait;
}

void BgMoriHashigo_LadderWait(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    BgMoriHashigo* clasp = (BgMoriHashigo*)pthis->dyna.actor.parent;

    if (clasp->hitTimer > 0) {
        BgMoriHashigo_SetupLadderFall(pthis);
    }
}

void BgMoriHashigo_SetupLadderFall(BgMoriHashigo* pthis) {
    pthis->bounceCounter = 0;
    pthis->actionFunc = BgMoriHashigo_LadderFall;
    pthis->dyna.actor.gravity = -1.0f;
    pthis->dyna.actor.minVelocityY = -10.0f;
    pthis->dyna.actor.velocity.y = 2.0f;
}

void BgMoriHashigo_LadderFall(BgMoriHashigo* pthis, GlobalContext* globalCtx) {
    Actor* thisx = &pthis->dyna.actor;

    Actor_MoveForward(thisx);
    if ((thisx->bgCheckFlags & 1) && (thisx->velocity.y < 0.0f)) {
        if (pthis->bounceCounter >= ARRAY_COUNT(bounceSpeed_48)) {
            BgMoriHashigo_SetupLadderRest(pthis);
        } else {
            Actor_UpdateBgCheckInfo(globalCtx, thisx, 0.0f, 0.0f, 0.0f, 0x1C);
            thisx->velocity.y = bounceSpeed_48[pthis->bounceCounter];
            pthis->bounceCounter++;
        }
    } else {
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 0.0f, 0.0f, 0.0f, 0x1C);
    }
}

void BgMoriHashigo_SetupLadderRest(BgMoriHashigo* pthis) {
    pthis->actionFunc = NULL;
    pthis->dyna.actor.gravity = 0.0f;
    pthis->dyna.actor.velocity.y = 0.0f;
    pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
}

void BgMoriHashigo_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashigo* pthis = (BgMoriHashigo*)thisx;

    if (pthis->hitTimer > 0) {
        pthis->hitTimer--;
    }
    if (pthis->actionFunc != NULL) {
        pthis->actionFunc(pthis, globalCtx);
    }
}

void BgMoriHashigo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgMoriHashigo* pthis = (BgMoriHashigo*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_hashigo.c", 516);
    func_80093D18(globalCtx->state.gfxCtx);
    if (1) {}
    gSPSegment(POLY_OPA_DISP++, 0x08, gObjectTable[pthis->moriTexObjIndex].vromStart.get());

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hashigo.c", 521),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    switch (pthis->dyna.actor.params) {
        case HASHIGO_CLASP:
            gSPDisplayList(POLY_OPA_DISP++, gMoriHashigoClaspDL);
            break;
        case HASHIGO_LADDER:
            gSPDisplayList(POLY_OPA_DISP++, gMoriHashigoLadderDL);
            break;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_mori_hashigo.c", 531);
}

void BgMoriHashigo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Mori_Hashigo_InitVars = {
        ACTOR_BG_MORI_HASHIGO,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_MORI_OBJECTS,
        sizeof(BgMoriHashigo),
        (ActorFunc)BgMoriHashigo_Init,
        (ActorFunc)BgMoriHashigo_Destroy,
        (ActorFunc)BgMoriHashigo_Update,
        NULL,
        (ActorFunc)BgMoriHashigo_Reset,
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphElementsInit,
    };

}

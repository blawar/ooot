#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_WARP2BLOCK_Z_OBJ_WARP2BLOCK_C
#include "actor_common.h"
/*
 * File: z_obj_warp2block.c
 * Overlay: ovl_Obj_Warp2Block
 * Description: Navi Infospot (Green, Time Block)
 */

#include "z_obj_warp2block.h"
#include "objects/object_timeblock/object_timeblock.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_4 | ACTOR_FLAG_25 | ACTOR_FLAG_27)

void ObjWarp2block_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjWarp2block_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjWarp2block_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjWarp2block_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjWarp2block_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjWarp2block_Spawn(ObjWarp2block* pthis, GlobalContext* globalCtx);
s32 func_80BA1ECC(ObjWarp2block* pthis, GlobalContext* globalCtx);
void ObjWarp2block_SwapWithChild(ObjWarp2block* pthis, GlobalContext* globalCtx);
s32 func_80BA2218(ObjWarp2block* pthis, GlobalContext* globalCtx);
s32 func_80BA228C(ObjWarp2block* pthis, GlobalContext* globalCtx);
s32 func_80BA2304(ObjWarp2block* pthis, GlobalContext* globalCtx);
void ObjWarp2block_SetInactive(ObjWarp2block* pthis);
void ObjWarp2block_DoNothing(ObjWarp2block* pthis, GlobalContext* globalCtx);
void func_80BA24E8(ObjWarp2block* pthis);
void func_80BA24F8(ObjWarp2block* pthis, GlobalContext* globalCtx);
void func_80BA2600(ObjWarp2block* pthis);
void func_80BA2610(ObjWarp2block* pthis, GlobalContext* globalCtx);

ActorInit Obj_Warp2block_InitVars = {
    ACTOR_OBJ_WARP2BLOCK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_TIMEBLOCK,
    sizeof(ObjWarp2block),
    (ActorFunc)ObjWarp2block_Init,
    (ActorFunc)ObjWarp2block_Destroy,
    (ActorFunc)ObjWarp2block_Update,
    (ActorFunc)ObjWarp2block_Draw,
    (ActorFunc)ObjWarp2block_Reset,
}; 

static Warp2BlockSpawnData sSpawnData[] = {
    { 1.0f, 60.0f, 0x0018 },
    { 0.6f, 40.0f, 0x0019 },
};

static f32 sDistances[] = { 60.0f, 100.0f, 140.0f, 180.0f, 220.0f, 260.0f, 300.0f, 300.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1500, ICHAIN_STOP),
};

static Color_RGB8 sColors[] = {
    { 100, 120, 140 }, { 80, 140, 200 }, { 100, 150, 200 }, { 100, 200, 240 },
    { 80, 110, 140 },  { 70, 160, 225 }, { 80, 100, 130 },  { 100, 110, 190 },
};

void ObjWarp2block_Spawn(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_EFFECT, pthis->dyna.actor.world.pos.x,
                pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, 0, 0,
                sSpawnData[(pthis->dyna.actor.params >> 8) & 1].params);

    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_EFFECT, pthis->dyna.actor.child->world.pos.x,
                pthis->dyna.actor.child->world.pos.y, pthis->dyna.actor.child->world.pos.z, 0, 0, 0,
                sSpawnData[(pthis->dyna.actor.child->params >> 8) & 1].params);
}

s32 func_80BA1ECC(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Actor* temp_a3;
    Player* player;
    Vec3f sp20;
    f32 temp_f2;

    if (func_80043590(&pthis->dyna)) {
        return 0;
    }

    temp_a3 = pthis->dyna.actor.child;
    player = GET_PLAYER(globalCtx);
    if ((pthis->dyna.actor.xzDistToPlayer <= sDistances[(((pthis->dyna.actor.params >> 0xB) & 7))]) ||
        (temp_a3->xzDistToPlayer <= sDistances[(((temp_a3->params >> 0xB) & 7))])) {

        func_8002DBD0(&pthis->dyna.actor, &sp20, &player->actor.world.pos);
        temp_f2 = (pthis->dyna.actor.scale.x * 50.0f) + 6.0f;

        if (!(temp_f2 < fabsf(sp20.x)) && !(temp_f2 < fabsf(sp20.z))) {
            return 0;
        }

        func_8002DBD0(temp_a3, &sp20, &player->actor.world.pos);
        temp_f2 = (temp_a3->scale.x * 50.0f) + 6.0f;

        if (!(temp_f2 < fabsf(sp20.x)) && !(temp_f2 < fabsf(sp20.z))) {
            return 0;
        }
    } else {
        return 0;
    }

    return 1;
}

void ObjWarp2block_SwapWithChild(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    Vec3f tempVec;
    Vec3s tempRot;
    s32 temp;

    Math_Vec3f_Copy(&tempVec, &pthis->dyna.actor.world.pos);
    Math_Vec3f_Copy(&pthis->dyna.actor.world.pos, &pthis->dyna.actor.child->world.pos);
    Math_Vec3f_Copy(&pthis->dyna.actor.child->world.pos, &tempVec);

    temp = pthis->dyna.actor.world.rot.y;
    pthis->dyna.actor.world.rot.y = pthis->dyna.actor.child->world.rot.y;
    pthis->dyna.actor.child->world.rot.y = temp;

    temp = pthis->dyna.actor.shape.rot.y;
    pthis->dyna.actor.shape.rot.y = pthis->dyna.actor.child->shape.rot.y;
    pthis->dyna.actor.child->shape.rot.y = temp;

    temp = pthis->dyna.actor.home.rot.z;
    pthis->dyna.actor.home.rot.z = pthis->dyna.actor.child->home.rot.z;
    pthis->dyna.actor.child->home.rot.z = temp;

    Math_Vec3f_Copy(&tempVec, &pthis->dyna.actor.scale);
    Math_Vec3f_Copy(&pthis->dyna.actor.scale, &pthis->dyna.actor.child->scale);
    Math_Vec3f_Copy(&pthis->dyna.actor.child->scale, &tempVec);

    Math_Vec3f_Copy(&tempVec, &pthis->dyna.actor.focus.pos);
    Math_Vec3f_Copy(&pthis->dyna.actor.focus.pos, &pthis->dyna.actor.child->focus.pos);
    Math_Vec3f_Copy(&pthis->dyna.actor.child->focus.pos, &tempVec);

    tempRot = pthis->dyna.actor.focus.rot;
    pthis->dyna.actor.focus.rot = pthis->dyna.actor.child->focus.rot;
    pthis->dyna.actor.child->focus.rot = tempRot;

    temp = pthis->dyna.actor.params & 0x7FFF;
    pthis->dyna.actor.params = (pthis->dyna.actor.params & 0x8000) | (pthis->dyna.actor.child->params & 0x7FFF);
    pthis->dyna.actor.child->params = (pthis->dyna.actor.child->params & 0x8000) | (temp & 0x7FFF);

    if (Math3D_Vec3fDistSq(&pthis->dyna.actor.world.pos, &pthis->dyna.actor.home.pos) < 0.01f) {
        Flags_UnsetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
    } else {
        Flags_SetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F);
    }
}

s32 func_80BA2218(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (func_80BA1ECC(pthis, globalCtx)) {
        if (player->stateFlags2 & 0x1000000) {
            func_8010BD58(globalCtx, OCARINA_ACTION_FREE_PLAY);
            pthis->func_168 = func_80BA228C;
        } else {
            player->stateFlags2 |= 0x800000;
        }
    }

    return 0;
}

s32 func_80BA228C(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
        pthis->func_168 = func_80BA2218;
    }

    if (globalCtx->msgCtx.lastPlayedSong == OCARINA_SONG_TIME) {
        if (pthis->unk_172 == 0xFE) {
            pthis->unk_16E = 0x6E;
        } else {
            pthis->unk_16E--;
            if (pthis->unk_16E == 0) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_80BA2304(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    s32 ret = pthis->func_168(pthis, globalCtx);

    pthis->unk_172 = globalCtx->msgCtx.lastPlayedSong;

    return ret;
}

void ObjWarp2block_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    ObjWarp2block* pthis = (ObjWarp2block*)thisx;
    CollisionHeader* collisionHeader;

    collisionHeader = NULL;
    pthis->dyna.actor.world.rot.z = pthis->dyna.actor.shape.rot.z = 0;
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    Actor_SetScale(&pthis->dyna.actor, sSpawnData[(pthis->dyna.actor.params >> 8) & 1].scale);
    pthis->func_168 = func_80BA2218;
    Actor_SetFocus(&pthis->dyna.actor, sSpawnData[(pthis->dyna.actor.params >> 8) & 1].focus);

    if ((pthis->dyna.actor.params >> 0xF) & 1) {
        func_80BA24E8(pthis);
        if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
            pthis->dyna.actor.draw = NULL;
        }
        DynaPolyActor_Init(&pthis->dyna, 0);
        CollisionHeader_GetVirtual(&gSongOfTimeBlockCol, &collisionHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, collisionHeader);
    } else {
        ObjWarp2block_SetInactive(pthis);
    }

    osSyncPrintf("時のブロック(ワープ２) (<arg> %04xH <type> color:%d range:%d)\n", pthis->dyna.actor.params & 0xFFFF,
                 pthis->dyna.actor.home.rot.z & 7, (pthis->dyna.actor.params >> 0xB) & 7);
}

void ObjWarp2block_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjWarp2block* pthis = (ObjWarp2block*)thisx;
    if ((pthis->dyna.actor.params >> 0xF) & 1) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void ObjWarp2block_SetInactive(ObjWarp2block* pthis) {
    pthis->actionFunc = ObjWarp2block_DoNothing;
    pthis->dyna.actor.draw = NULL;
}

void ObjWarp2block_DoNothing(ObjWarp2block* pthis, GlobalContext* globalCtx) {
}

void func_80BA24E8(ObjWarp2block* pthis) {
    pthis->actionFunc = func_80BA24F8;
}

void func_80BA24F8(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    Actor* current = globalCtx->actorCtx.actorLists[ACTORCAT_ITEMACTION].head;

    while (current != NULL) {
        if (current->id == ACTOR_OBJ_WARP2BLOCK && !((current->params >> 0xF) & 1) &&
            ((pthis->dyna.actor.params & 0x3F) == (current->params & 0x3F))) {
            pthis->dyna.actor.child = current;
            if (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) {
                ObjWarp2block_SwapWithChild(pthis, globalCtx);
                pthis->dyna.actor.draw = ObjWarp2block_Draw;
            }
            func_80BA2600(pthis);
            return;
        }

        current = current->next;
    }

    pthis->unk_174++;
    if (pthis->unk_174 > 60) {
        osSyncPrintf(VT_COL(RED, WHITE));
        osSyncPrintf("Error : 時のブロック(ワープ２)が対でセットされていません(%s %d)\n", "../z_obj_warp2block.c", 505);
        osSyncPrintf(VT_RST);
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_80BA2600(ObjWarp2block* pthis) {
    pthis->actionFunc = func_80BA2610;
}

void func_80BA2610(ObjWarp2block* pthis, GlobalContext* globalCtx) {
    if ((func_80BA2304(pthis, globalCtx) != 0) && (pthis->unk_16C <= 0)) {
        ObjWarp2block_Spawn(pthis, globalCtx);
        pthis->unk_16C = 0xA0;
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        pthis->unk_170 = 0xC;
    }

    if (pthis->unk_170 > 0) {
        pthis->unk_170--;
        if (pthis->unk_170 == 0) {
            ObjWarp2block_SwapWithChild(pthis, globalCtx);
        }
    }
    if (pthis->unk_16C == 0x32) {
        func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
    }
}

void ObjWarp2block_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjWarp2block* pthis = (ObjWarp2block*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->unk_16C > 0) {
        pthis->unk_16C--;
    }
}

void ObjWarp2block_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Color_RGB8* sp44;

    sp44 = &sColors[thisx->home.rot.z & 7];

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_warp2block.c", 584);
    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_warp2block.c", 588),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sp44->r, sp44->g, sp44->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, gSongOfTimeBlockDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_warp2block.c", 594);
}

void ObjWarp2block_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Warp2block_InitVars = {
        ACTOR_OBJ_WARP2BLOCK,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_TIMEBLOCK,
        sizeof(ObjWarp2block),
        (ActorFunc)ObjWarp2block_Init,
        (ActorFunc)ObjWarp2block_Destroy,
        (ActorFunc)ObjWarp2block_Update,
        (ActorFunc)ObjWarp2block_Draw,
        (ActorFunc)ObjWarp2block_Reset,
    };

}

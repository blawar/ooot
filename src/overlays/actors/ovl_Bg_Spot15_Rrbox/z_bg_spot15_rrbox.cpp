#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT15_RRBOX_Z_BG_SPOT15_RRBOX_C
#include "actor_common.h"
/*
 * File: z_bg_spot15_rrbox.c
 * Overlay: ovl_Bg_Spot15_Rrbox
 * Description: Milk Crate
 */

#include "z_bg_spot15_rrbox.h"
#include "objects/object_spot15_obj/object_spot15_obj.h"
#include "def/code_80043480.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"

#define FLAGS 0

void BgSpot15Rrbox_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B4084(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B40AC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B4194(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B4380(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B43D0(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B44B8(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B4178(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);
void func_808B44CC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx);

static s16 D_808B4590 = 0;

ActorInit Bg_Spot15_Rrbox_InitVars = {
    ACTOR_BG_SPOT15_RRBOX,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT15_OBJ,
    sizeof(BgSpot15Rrbox),
    (ActorFunc)BgSpot15Rrbox_Init,
    (ActorFunc)BgSpot15Rrbox_Destroy,
    (ActorFunc)BgSpot15Rrbox_Update,
    (ActorFunc)BgSpot15Rrbox_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static Vec3f D_808B45C4[] = {
    { 770.0f, 1490.0f, -299.0f },
    { 770.0f, 1550.0f, -299.0f },
};

static Vec3f D_808B45DC[] = {
    { 29.99f, 0.01f, -29.99f }, { -29.99f, 0.01f, -29.99f }, { -29.99f, 0.01f, 29.99f },
    { 29.99f, 0.01f, 29.99f },  { 0.0f, 0.01f, 0.0f },
};

void func_808B3960(BgSpot15Rrbox* pthis, GlobalContext* globalCtx, CollisionHeader* collision, s32 flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    u32 pad2;

    DynaPolyActor_Init(&pthis->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (pthis->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot15_rrbox.c", 171,
                     pthis->dyna.actor.id, pthis->dyna.actor.params);
    }
}

void func_808B39E8(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3) {
    arg0->x = (arg1->z * arg2) + (arg1->x * arg3);
    arg0->y = arg1->y;
    arg0->z = (arg1->z * arg3) - (arg1->x * arg2);
}

void func_808B3A34(BgSpot15Rrbox* pthis) {
    pthis->bgId = BG_ACTOR_MAX;
}

s32 func_808B3A40(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    DynaPolyActor* dynaPolyActor = DynaPoly_GetActor(&globalCtx->colCtx, pthis->bgId);

    if ((dynaPolyActor != NULL) &&
        Math3D_Dist2DSq(dynaPolyActor->actor.world.pos.x, dynaPolyActor->actor.world.pos.z,
                        pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.z) < 0.01f) {
        return true;
    }
    return false;
}

s32 func_808B3AAC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    s16 rotY;
    Actor* actor = &pthis->dyna.actor;

    if (globalCtx->sceneNum == SCENE_SOUKO) {
        return true;
    } else if (func_808B3A40(pthis, globalCtx)) {
        return false;
    }

    if (actor->world.pos.x <= 930.0f && actor->world.pos.z >= -360.0f) {
        if (pthis->dyna.unk_150 >= 0.0f) {
            rotY = actor->world.rot.y;
        } else {
            rotY = actor->world.rot.y + 0x8000;
        }

        if (rotY < 0x2000 && rotY > -0x6000) {
            return gSaveContext.eventChkInf[1] & 0x10;
        }
        return true;
    }

    return true;
}

void BgSpot15Rrbox_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot15Rrbox* pthis = (BgSpot15Rrbox*)thisx;

    func_808B3960(pthis, globalCtx, &gLonLonMilkCrateCol, DPM_UNK);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    func_808B3A34(pthis);
    if (Flags_GetSwitch(globalCtx, (pthis->dyna.actor.params & 0x3F))) {
        func_808B44B8(pthis, globalCtx);
        pthis->dyna.actor.world.pos = D_808B45C4[D_808B4590];
        D_808B4590++;
    } else {
        func_808B4084(pthis, globalCtx);
    }
    osSyncPrintf("(spot15 ロンロン木箱)(arg_data 0x%04x)\n", pthis->dyna.actor.params);
}

void BgSpot15Rrbox_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot15Rrbox* pthis = (BgSpot15Rrbox*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    D_808B4590 = 0;
}

s32 func_808B3CA0(BgSpot15Rrbox* pthis, GlobalContext* globalCtx, s32 arg2) {
    f32 chkDist = 0.0f;
    Vec3f actorPosition;
    Vec3f actorScale;

    func_808B3A34(pthis);

    actorScale.x = D_808B45DC[arg2].x * (pthis->dyna.actor.scale.x * 10.0f);
    actorScale.y = D_808B45DC[arg2].y * (pthis->dyna.actor.scale.y * 10.0f);
    actorScale.z = D_808B45DC[arg2].z * (pthis->dyna.actor.scale.z * 10.0f);

    func_808B39E8(&actorPosition, &actorScale, pthis->unk_16C, pthis->unk_170);

    actorPosition.x += pthis->dyna.actor.world.pos.x;
    actorPosition.y += pthis->dyna.actor.prevPos.y;
    actorPosition.z += pthis->dyna.actor.world.pos.z;

    pthis->dyna.actor.floorHeight = BgCheck_EntityRaycastFloor6(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly,
                                                               &pthis->bgId, &pthis->dyna.actor, &actorPosition, chkDist);

    if ((pthis->dyna.actor.floorHeight - pthis->dyna.actor.world.pos.y) >= -0.001f) {
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
        return true;
    }
    return false;
}

f32 func_808B3DDC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f position;
    Vec3f scale;
    Actor* actor = &pthis->dyna.actor;
    f32 yIntersect;
    f32 returnValue = BGCHECK_Y_MIN;
    s32 bgId;

    func_808B3A34(pthis);
    for (i = 0; i < ARRAY_COUNT(D_808B45DC); i++) {
        scale.x = D_808B45DC[i].x * (actor->scale.x * 10.0f);
        scale.y = D_808B45DC[i].y * (actor->scale.y * 10.0f);
        scale.z = D_808B45DC[i].z * (actor->scale.z * 10.0f);

        func_808B39E8(&position, &scale, pthis->unk_16C, pthis->unk_170);

        position.x += actor->world.pos.x;
        position.y += actor->prevPos.y;
        position.z += actor->world.pos.z;

        yIntersect = BgCheck_EntityRaycastFloor6(&globalCtx->colCtx, &actor->floorPoly, &bgId, actor, &position, 0);

        if (returnValue < yIntersect) {
            returnValue = yIntersect;
            pthis->bgId = bgId;
        }
    }
    return returnValue;
}

s32 func_808B3F58(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    if (func_808B3CA0(pthis, globalCtx, 0)) {
        return true;
    }
    if (func_808B3CA0(pthis, globalCtx, 1)) {
        return true;
    }
    if (func_808B3CA0(pthis, globalCtx, 2)) {
        return true;
    }
    if (func_808B3CA0(pthis, globalCtx, 3)) {
        return true;
    }
    if (func_808B3CA0(pthis, globalCtx, 4)) {
        return true;
    }
    return false;
}

s32 func_808B4010(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    return !func_800435D8(globalCtx, &pthis->dyna, pthis->dyna.actor.scale.x * 290.0f,
                          pthis->dyna.actor.scale.x * 290.0f + 20.0f, 1.0f);
}

void func_808B4084(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    pthis->actionFunc = func_808B40AC;
    pthis->dyna.actor.gravity = 0.0f;
    pthis->dyna.actor.velocity.x = 0.0f;
    pthis->dyna.actor.velocity.y = 0.0f;
    pthis->dyna.actor.velocity.z = 0.0f;
}

void func_808B40AC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->unk_168 <= 0 && fabsf(pthis->dyna.unk_150) > 0.001f) {
        if (func_808B3AAC(pthis, globalCtx) && !func_808B4010(pthis, globalCtx)) {
            pthis->unk_17C = pthis->dyna.unk_150;
            func_808B4178(pthis, globalCtx);
        } else {
            player->stateFlags2 &= ~0x10;
            pthis->dyna.unk_150 = 0.0f;
        }
    } else {
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
    }
}

void func_808B4178(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    pthis->actionFunc = func_808B4194;
    pthis->dyna.actor.gravity = 0.0f;
}

void func_808B4194(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    f32 sign;
    Player* player = GET_PLAYER(globalCtx);
    f32 tempUnk178;
    s32 approxFResult;
    Actor* actor = &pthis->dyna.actor;

    pthis->unk_174 += 0.5f;

    pthis->unk_174 = CLAMP_MAX(pthis->unk_174, 2.0f);

    approxFResult = Math_StepToF(&pthis->unk_178, 20.0f, pthis->unk_174);

    sign = pthis->unk_17C >= 0.0f ? 1.0f : -1.0f;

    tempUnk178 = (f32)sign * pthis->unk_178;
    actor->world.pos.x = actor->home.pos.x + (tempUnk178 * pthis->unk_16C);
    actor->world.pos.z = actor->home.pos.z + (tempUnk178 * pthis->unk_170);

    if (!func_808B3F58(pthis, globalCtx)) {
        actor->home.pos.x = actor->world.pos.x;
        actor->home.pos.z = actor->world.pos.z;
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
        pthis->unk_178 = 0.0f;
        pthis->unk_174 = 0.0f;
        func_808B4380(pthis, globalCtx);
    } else if (approxFResult) {
        player = GET_PLAYER(globalCtx);
        if (func_808B4010(pthis, globalCtx)) {
            Audio_PlayActorSound2(actor, NA_SE_EV_WOOD_BOUND);
        }
        if (func_808B3A40(pthis, globalCtx)) {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        }
        actor->home.pos.x = actor->world.pos.x;
        actor->home.pos.z = actor->world.pos.z;
        player->stateFlags2 &= ~0x10;
        pthis->dyna.unk_150 = 0.0f;
        pthis->unk_178 = 0.0f;
        pthis->unk_174 = 0.0f;
        pthis->unk_168 = 10;
        func_808B4084(pthis, globalCtx);
    }
    Audio_PlayActorSound2(actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}

void func_808B4380(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.velocity.x = 0.0f;
    pthis->dyna.actor.velocity.y = 0.0f;
    pthis->dyna.actor.velocity.z = 0.0f;
    pthis->dyna.actor.gravity = -1.0f;
    pthis->dyna.actor.floorHeight = func_808B3DDC(pthis, globalCtx);
    pthis->actionFunc = func_808B43D0;
}

void func_808B43D0(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    f32 floorHeight;
    Player* player = GET_PLAYER(globalCtx);
    Actor* actor = &pthis->dyna.actor;

    if (fabsf(pthis->dyna.unk_150) > 0.001f) {
        pthis->dyna.unk_150 = 0.0f;
        player->stateFlags2 &= ~0x10;
    }

    Actor_MoveForward(actor);

    if (actor->world.pos.y <= BGCHECK_Y_MIN + 10.0f) {
        // "Lon Lon wooden crate fell too much"
        osSyncPrintf("Warning : ロンロン木箱落ちすぎた(%s %d)(arg_data 0x%04x)\n", "../z_bg_spot15_rrbox.c", 599,
                     actor->params);

        Actor_Kill(actor);

        return;
    }

    floorHeight = actor->floorHeight;

    if ((floorHeight - actor->world.pos.y) >= -0.001f) {
        actor->world.pos.y = floorHeight;
        func_808B4084(pthis, globalCtx);
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_WOOD_BOUND);
    }
}

void func_808B44B8(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    pthis->actionFunc = func_808B44CC;
}

void func_808B44CC(BgSpot15Rrbox* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    player->stateFlags2 &= ~0x10;
    pthis->dyna.unk_150 = 0.0f;
}

void BgSpot15Rrbox_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot15Rrbox* pthis = (BgSpot15Rrbox*)thisx;

    if (pthis->unk_168 > 0) {
        pthis->unk_168--;
    }
    pthis->dyna.actor.world.rot.y = pthis->dyna.unk_158;
    pthis->unk_16C = Math_SinS(pthis->dyna.actor.world.rot.y);
    pthis->unk_170 = Math_CosS(pthis->dyna.actor.world.rot.y);
    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot15Rrbox_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gLonLonMilkCrateDL);
}

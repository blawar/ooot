#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_MURE3_Z_OBJ_MURE3_C
#include "actor_common.h"
/*
 * File: z_obj_mure3.c
 * Overlay: ovl_Obj_Mure3
 * Description: Tower of Rupees
 */

#include "z_obj_mure3.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS 0

void ObjMure3_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjMure3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjMure3_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B9AF24(ObjMure3* pthis);
void func_80B9AF34(ObjMure3* pthis, GlobalContext* globalCtx);
void func_80B9AF54(ObjMure3* pthis);
void func_80B9AF64(ObjMure3* pthis, GlobalContext* globalCtx);
void func_80B9AFEC(ObjMure3* pthis);
void func_80B9AFFC(ObjMure3* pthis, GlobalContext* globalCtx);

ActorInit Obj_Mure3_InitVars = {
    ACTOR_OBJ_MURE3,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure3),
    (ActorFunc)ObjMure3_Init,
    (ActorFunc)ObjMure3_Destroy,
    (ActorFunc)ObjMure3_Update,
    NULL,
};

static s16 sRupeeCounts[] = { 5, 5, 7, 0 };

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 100, ICHAIN_STOP),
};

void func_80B9A9D0(ObjMure3* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f spawnPos;

    Math_Vec3f_Copy(&spawnPos, &pthis->actor.world.pos);
    for (i = 0; i < 5; i++, spawnPos.y += 20.0f) {
        if (!((pthis->unk_16C >> i) & 1)) {
            pthis->unk_150[i] = Item_DropCollectible2(globalCtx, &spawnPos, 0x4000 | ITEM00_RUPEE_BLUE);
            if (pthis->unk_150[i] != NULL) {
                pthis->unk_150[i]->actor.room = pthis->actor.room;
            }
        }
    }
}

void func_80B9AA90(ObjMure3* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f spawnPos;
    f32 sn = Math_SinS(pthis->actor.world.rot.y);
    f32 cos = Math_CosS(pthis->actor.world.rot.y);
    f32 radius;

    spawnPos.y = pthis->actor.world.pos.y;

    for (i = 0, radius = -40.0f; i < 5; i++, radius += 20.0f) {
        if (!((pthis->unk_16C >> i) & 1)) {
            spawnPos.x = pthis->actor.world.pos.x + (sn * radius);
            spawnPos.z = pthis->actor.world.pos.z + (cos * radius);
            pthis->unk_150[i] = Item_DropCollectible2(globalCtx, &spawnPos, 0x4000 | ITEM00_RUPEE_GREEN);
            if (pthis->unk_150[i] != NULL) {
                pthis->unk_150[i]->actor.room = pthis->actor.room;
            }
        }
    }
}

void func_80B9ABA0(ObjMure3* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f spawnPos;
    s16 yRot;

    spawnPos.y = pthis->actor.world.pos.y;
    yRot = pthis->actor.world.rot.y;
    for (i = 0; i < 6; i++) {
        if (!((pthis->unk_16C >> i) & 1)) {
            spawnPos.x = (Math_SinS(yRot) * 40.0f) + pthis->actor.world.pos.x;
            spawnPos.z = (Math_CosS(yRot) * 40.0f) + pthis->actor.world.pos.z;
            pthis->unk_150[i] = Item_DropCollectible2(globalCtx, &spawnPos, 0x4000 | ITEM00_RUPEE_GREEN);
            if (pthis->unk_150[i] != NULL) {
                pthis->unk_150[i]->actor.room = pthis->actor.room;
            }
        }
        yRot += 0x2AAA;
    }
    if (!((pthis->unk_16C >> 6) & 1)) {
        spawnPos.x = pthis->actor.world.pos.x;
        spawnPos.z = pthis->actor.world.pos.z;
        pthis->unk_150[6] = Item_DropCollectible2(globalCtx, &spawnPos, 0x4000 | ITEM00_RUPEE_RED);
        if (pthis->unk_150[6] != NULL) {
            pthis->unk_150[6]->actor.room = pthis->actor.room;
        }
    }
}

void func_80B9ACE4(ObjMure3* pthis, GlobalContext* globalCtx) {
    s16 count = sRupeeCounts[(pthis->actor.params >> 13) & 7];
    s32 i;

    for (i = 0; i < count; i++) {
        EnItem00** collectible = &pthis->unk_150[i];

        if (!((pthis->unk_16C >> i) & 1) && (*collectible != NULL)) {
            if (Actor_HasParent(&(*collectible)->actor, globalCtx) || ((*collectible)->actor.update == NULL)) {
                pthis->unk_16C |= (1 << i);
            } else {
                Actor_Kill(&(*collectible)->actor);
            }
        }
        *collectible = NULL;
    }
}

void func_80B9ADCC(ObjMure3* pthis, GlobalContext* globalCtx) {
    s16 count = sRupeeCounts[(pthis->actor.params >> 13) & 7];
    s32 i;

    for (i = 0; i < count; i++) {
        EnItem00** collectible = &pthis->unk_150[i];

        if ((*collectible != NULL) && !((pthis->unk_16C >> i) & 1)) {
            if (Actor_HasParent(&(*collectible)->actor, globalCtx)) {
                Flags_SetSwitch(globalCtx, pthis->actor.params & 0x3F);
            }
            if ((*collectible)->actor.update == NULL) {
                pthis->unk_16C |= (1 << i);
                pthis->unk_150[i] = NULL;
            }
        }
    }
}

void ObjMure3_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjMure3* pthis = (ObjMure3*)thisx;

    if (Flags_GetSwitch(globalCtx, pthis->actor.params & 0x3F)) {
        Actor_Kill(&pthis->actor);
        return;
    }
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    func_80B9AF24(pthis);
}

void ObjMure3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_80B9AF24(ObjMure3* pthis) {
    pthis->actionFunc = func_80B9AF34;
}

void func_80B9AF34(ObjMure3* pthis, GlobalContext* globalCtx) {
    func_80B9AF54(pthis);
}

void func_80B9AF54(ObjMure3* pthis) {
    pthis->actionFunc = func_80B9AF64;
}

void func_80B9AF64(ObjMure3* pthis, GlobalContext* globalCtx) {
    static ObjMure3SpawnFunc spawnFuncs[] = { func_80B9A9D0, func_80B9AA90, func_80B9ABA0 };

    if (Math3D_Dist1DSq(pthis->actor.projectedPos.x, pthis->actor.projectedPos.z) < SQ(1150.0f)) {
        pthis->actor.flags |= ACTOR_FLAG_4;
        spawnFuncs[(pthis->actor.params >> 13) & 7](pthis, globalCtx);
        func_80B9AFEC(pthis);
    }
}

void func_80B9AFEC(ObjMure3* pthis) {
    pthis->actionFunc = func_80B9AFFC;
}

void func_80B9AFFC(ObjMure3* pthis, GlobalContext* globalCtx) {
    func_80B9ADCC(pthis, globalCtx);
    if (Math3D_Dist1DSq(pthis->actor.projectedPos.x, pthis->actor.projectedPos.z) >= SQ(1450.0f)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        func_80B9ACE4(pthis, globalCtx);
        func_80B9AF54(pthis);
    }
}

void ObjMure3_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure3* pthis = (ObjMure3*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

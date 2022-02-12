#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_MURE2_Z_OBJ_MURE2_C
#include "actor_common.h"
/*
 * File: z_obj_mure2.c
 * Overlay: ovl_Obj_Mure2
 * Description: Rock/Bush groups
 */

#include "z_obj_mure2.h"
#include "def/sys_math3d.h"
#include "def/z_actor.h"
#include "def/z_lib.h"

#define FLAGS 0

typedef void (*ObjMure2SetPosFunc)(Vec3f* vec, ObjMure2* pthis);

typedef struct {
    s16 radius;
    s16 angle;
} Mure2sScatteredShrubInfo;

void ObjMure2_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjMure2_Update(Actor* thisx, GlobalContext* globalCtx);

void ObjMure2_SetPosShrubCircle(Vec3f* vec, ObjMure2* pthis);
void ObjMure2_SetPosShrubScattered(Vec3f* vec, ObjMure2* pthis);
void ObjMure2_SetPosRockCircle(Vec3f* vec, ObjMure2* pthis);
void ObjMure2_Wait(ObjMure2* pthis, GlobalContext* globalCtx);
void func_80B9A668(ObjMure2* pthis, GlobalContext* globalCtx);
void func_80B9A6F8(ObjMure2* pthis, GlobalContext* globalCtx);
void ObjMure2_SetupWait(ObjMure2* pthis);
void func_80B9A658(ObjMure2* pthis);
void func_80B9A6E8(ObjMure2* pthis);

ActorInit Obj_Mure2_InitVars = {
    ACTOR_OBJ_MURE2,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ObjMure2),
    (ActorFunc)ObjMure2_Init,
    (ActorFunc)Actor_Noop,
    (ActorFunc)ObjMure2_Update,
    NULL,
};

static f32 sDistSquared1[] = { SQ(1600.0f), SQ(1600.0f), SQ(1600.0f) };

static f32 sDistSquared2[] = { SQ(1705.0f), SQ(1705.0f), SQ(1705.0f) };

static s16 D_80B9A818[] = { 9, 12, 8 };

static s16 sActorSpawnIDs[] = { ACTOR_EN_KUSA, ACTOR_EN_KUSA, ACTOR_EN_ISHI };

void ObjMure2_SetPosShrubCircle(Vec3f* vec, ObjMure2* pthis) {
    s32 i;

    Math_Vec3f_Copy(vec, &pthis->actor.world.pos);
    for (i = 1; i < D_80B9A818[pthis->actor.params & 3]; i++) {
        Math_Vec3f_Copy(vec + i, &pthis->actor.world.pos);
        (vec + i)->x += (80.0f * Math_SinS((i - 1) * 0x2000));
        (vec + i)->z += (80.0f * Math_CosS((i - 1) * 0x2000));
    }
}

static Mure2sScatteredShrubInfo sScatteredShrubInfo[] = {
    { 40, 0x0666 }, { 40, 0x2CCC }, { 40, 0x5999 }, { 40, 0x8666 }, { 20, 0xC000 }, { 80, 0x1333 },
    { 80, 0x4000 }, { 80, 0x6CCC }, { 80, 0x9333 }, { 80, 0xACCC }, { 80, 0xC666 }, { 60, 0xE000 },
};

void ObjMure2_SetPosShrubScattered(Vec3f* vec, ObjMure2* pthis) {
    s32 i;

    for (i = 0; i < D_80B9A818[pthis->actor.params & 3]; i++) {
        Math_Vec3f_Copy(vec + i, &pthis->actor.world.pos);
        (vec + i)->x += (sScatteredShrubInfo[i].radius * Math_CosS(sScatteredShrubInfo[i].angle));
        (vec + i)->z -= (sScatteredShrubInfo[i].radius * Math_SinS(sScatteredShrubInfo[i].angle));
    }
}

void ObjMure2_SetPosRockCircle(Vec3f* vec, ObjMure2* pthis) {
    s32 i;

    for (i = 0; i < D_80B9A818[pthis->actor.params & 3]; i++) {
        Math_Vec3f_Copy(vec + i, &pthis->actor.world.pos);
        (vec + i)->x += (80.0f * Math_SinS(i * 0x2000));
        (vec + i)->z += (80.0f * Math_CosS(i * 0x2000));
    }
}

void ObjMure2_SetActorSpawnParams(s16* params, ObjMure2* pthis) {
    static s16 actorSpawnParams[] = { 0, 0, 0 };
    s16 dropTable = (pthis->actor.params >> 8) & 0xF;

    if (dropTable >= 13) {
        dropTable = 0;
    }
    *params = actorSpawnParams[pthis->actor.params & 3] & 0xF0FF;
    *params |= (dropTable << 8);
}

void ObjMure2_SpawnActors(ObjMure2* pthis, GlobalContext* globalCtx) {
    static ObjMure2SetPosFunc setPosFunc[] = {
        ObjMure2_SetPosShrubCircle,
        ObjMure2_SetPosShrubScattered,
        ObjMure2_SetPosRockCircle,
    };
    s32 actorNum = pthis->actor.params & 3;
    s32 i;
    Vec3f spawnPos[12];
    s16 params;

    setPosFunc[actorNum](spawnPos, pthis);
    ObjMure2_SetActorSpawnParams(&params, pthis);

    for (i = 0; i < D_80B9A818[actorNum]; i++) {
        if (pthis->actorSpawnPtrList[i] != NULL) {
            // "Warning : I already have a child (%s %d)(arg_data 0x%04x)"
            osSyncPrintf("Warning : 既に子供がいる(%s %d)(arg_data 0x%04x)\n", "../z_obj_mure2.c", 269,
                         pthis->actor.params);
            continue;
        }

        if (((pthis->currentActorNum >> i) & 1) == 0) {
            pthis->actorSpawnPtrList[i] =
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, sActorSpawnIDs[actorNum], spawnPos[i].x, spawnPos[i].y,
                            spawnPos[i].z, pthis->actor.world.rot.x, 0, pthis->actor.world.rot.z, params);
            if (pthis->actorSpawnPtrList[i] != NULL) {
                pthis->actorSpawnPtrList[i]->room = pthis->actor.room;
            }
        }
    }
}

void ObjMure2_CleanupAndDie(ObjMure2* pthis, GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < D_80B9A818[pthis->actor.params & 3]; i++) {
        if (((pthis->currentActorNum >> i) & 1) == 0) {
            if (pthis->actorSpawnPtrList[i] != NULL) {
                if (Actor_HasParent(pthis->actorSpawnPtrList[i], globalCtx)) {
                    pthis->currentActorNum |= (1 << i);
                } else {
                    Actor_Kill(pthis->actorSpawnPtrList[i]);
                }
                pthis->actorSpawnPtrList[i] = NULL;
            }
        } else {
            pthis->actorSpawnPtrList[i] = NULL;
        }
    }
}

void func_80B9A534(ObjMure2* pthis) {
    s32 i;

    for (i = 0; i < D_80B9A818[pthis->actor.params & 3]; i++) {
        if (pthis->actorSpawnPtrList[i] != NULL && (((pthis->currentActorNum >> i) & 1) == 0) &&
            (pthis->actorSpawnPtrList[i]->update == NULL)) {
            pthis->currentActorNum |= (1 << i);
            pthis->actorSpawnPtrList[i] = NULL;
        }
    }
}

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneForward, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 2100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 100, ICHAIN_STOP),
};

void ObjMure2_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure2* pthis = (ObjMure2*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        pthis->actor.uncullZoneForward += 1200.0f;
    }
    ObjMure2_SetupWait(pthis);
}

void ObjMure2_SetupWait(ObjMure2* pthis) {
    pthis->actionFunc = ObjMure2_Wait;
}

void ObjMure2_Wait(ObjMure2* pthis, GlobalContext* globalCtx) {
    func_80B9A658(pthis);
}

void func_80B9A658(ObjMure2* pthis) {
    pthis->actionFunc = func_80B9A668;
}

void func_80B9A668(ObjMure2* pthis, GlobalContext* globalCtx) {
    if (Math3D_Dist1DSq(pthis->actor.projectedPos.x, pthis->actor.projectedPos.z) <
        (sDistSquared1[pthis->actor.params & 3] * pthis->unk_184)) {
        pthis->actor.flags |= ACTOR_FLAG_4;
        ObjMure2_SpawnActors(pthis, globalCtx);
        func_80B9A6E8(pthis);
    }
}

void func_80B9A6E8(ObjMure2* pthis) {
    pthis->actionFunc = func_80B9A6F8;
}

void func_80B9A6F8(ObjMure2* pthis, GlobalContext* globalCtx) {
    func_80B9A534(pthis);
    if ((sDistSquared2[pthis->actor.params & 3] * pthis->unk_184) <=
        Math3D_Dist1DSq(pthis->actor.projectedPos.x, pthis->actor.projectedPos.z)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        ObjMure2_CleanupAndDie(pthis, globalCtx);
        func_80B9A658(pthis);
    }
}

void ObjMure2_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjMure2* pthis = (ObjMure2*)thisx;

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        pthis->unk_184 = 1.0f;
    } else {
        pthis->unk_184 = 4.0f;
    }
    pthis->actionFunc(pthis, globalCtx);
}

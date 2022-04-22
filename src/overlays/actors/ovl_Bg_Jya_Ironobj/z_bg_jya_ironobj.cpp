#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_JYA_IRONOBJ_Z_BG_JYA_IRONOBJ_C
#include "actor_common.h"
/*
 * File: z_bg_jya_ironobj.c
 * Overlay: ovl_Bg_Jya_Ironobj
 * Description: Destructable Iron Knuckle objects
 */

#include "z_bg_jya_ironobj.h"
#include "objects/object_jya_iron/object_jya_iron.h"
#include "overlays/actors/ovl_En_Ik/z_en_ik.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/random.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"

#define FLAGS 0

typedef void (*BgJyaIronobjIkFunc)(BgJyaIronobj*, GlobalContext*, EnIk*);

void BgJyaIronobj_Init(Actor* thisx, GlobalContext* globalCtx);
void BgJyaIronobj_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgJyaIronobj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgJyaIronobj_Update(Actor* thisx, GlobalContext* globalCtx);
void BgJyaIronobj_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_808992D8(BgJyaIronobj* pthis);
void func_808992E8(BgJyaIronobj* pthis, GlobalContext* globalCtx);

void BgJyaIronobj_SpawnPillarParticles(BgJyaIronobj* pthis, GlobalContext* globalCtx, EnIk* enIk);
void BgJyaIronobj_SpawnThoneParticles(BgJyaIronobj* pthis, GlobalContext* arg1, EnIk* enIk);

static BgJyaIronobjIkFunc particleFunc_53[] = { BgJyaIronobj_SpawnPillarParticles, BgJyaIronobj_SpawnThoneParticles };


static int sUnused = 0;

ActorInit Bg_Jya_Ironobj_InitVars = {
    ACTOR_BG_JYA_IRONOBJ,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_JYA_IRON,
    sizeof(BgJyaIronobj),
    (ActorFunc)BgJyaIronobj_Init,
    (ActorFunc)BgJyaIronobj_Destroy,
    (ActorFunc)BgJyaIronobj_Update,
    (ActorFunc)BgJyaIronobj_Draw,
    (ActorFunc)BgJyaIronobj_Reset,
};

static Gfx* sOpaDL[] = { gPillarDL, gThroneDL };

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 30, 150, 0, { 0, 0, 0 } },
};

static s16 D_808994D8[] = { 0x8700, 0x4000, 0xC000, 0x0000 };

// Pillar
static s16 D_808994E0[] = { 5, 8, 11, 14, 17, 20, 23, 26 };
static s16 D_808994F0[] = { 18, 26, 34, 42, 50, 60, 70, 80 };
static s16 D_80899500[] = { 48, 42, 36, 32, 28, 24, 20, 16 };

// Throne
static s16 D_80899510[] = { 5, 8, 11, 14, 17, 20, 23, 26 };
static s16 D_80899520[] = { 18, 26, 34, 42, 50, 60, 70, 80 };
static s16 D_80899530[] = { 48, 42, 36, 32, 28, 24, 20, 16 };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

static CollisionHeader* sCollisionHeaders[] = { &gPillarCol, &gThroneCol };

void BgJyaIronobj_InitCylinder(BgJyaIronobj* pthis, GlobalContext* globalCtx) {
    ColliderCylinder* colCylinder = &pthis->colCylinder;

    Collider_InitCylinder(globalCtx, colCylinder);
    Collider_SetCylinder(globalCtx, colCylinder, &pthis->dyna.actor, &sCylinderInit);
    if ((pthis->dyna.actor.params & 1) == 1) {
        pthis->colCylinder.dim.radius = 40;
        pthis->colCylinder.dim.height = 100;
    }
    Collider_UpdateCylinder(&pthis->dyna.actor, colCylinder);
}

/*
 * Spawns particles for the destroyed pillar
 */
void BgJyaIronobj_SpawnPillarParticles(BgJyaIronobj* pthis, GlobalContext* globalCtx, EnIk* enIk) {
    s32 i;
    s32 j;
    s16 unkArg5;
    f32 temp_f22;
    Vec3f pos;
    Vec3f vel;
    f32 coss;
    s16 rotY;
    f32 sins;
    s32 pad[2];

    if (enIk->unk_2FF <= 0 || enIk->unk_2FF >= 4) {
        osSyncPrintf("Error 攻撃方法が分からない(%s %d)\n", "../z_bg_jya_ironobj.c", 233, enIk->unk_2FF);
        return;
    }
    osSyncPrintf("¢ attack_type(%d)\n", enIk->unk_2FF);
    rotY = Actor_WorldYawTowardActor(&pthis->dyna.actor, &enIk->actor) + D_808994D8[enIk->unk_2FF - 1];

    for (i = 0; i < 8; i++) {
        Actor* actor =
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_JYA_HAHENIRON, pthis->dyna.actor.world.pos.x,
                        Rand_ZeroOne() * 80.0f + pthis->dyna.actor.world.pos.y + 20.0f, pthis->dyna.actor.world.pos.z, 0,
                        (s16)(Rand_ZeroOne() * 0x4000) + rotY - 0x2000, 0, 0);
        if (actor != NULL) {
            actor->speedXZ = Rand_ZeroOne() * 8.0f + 9.0f;
            actor->velocity.y = Rand_ZeroOne() * 10.0f + 6.0f;
        }
    }
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_JYA_HAHENIRON, pthis->dyna.actor.world.pos.x,
                pthis->dyna.actor.world.pos.y + 150.0f, pthis->dyna.actor.world.pos.z, 0, 0, 0, 1);
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_JYA_HAHENIRON, pthis->dyna.actor.world.pos.x,
                pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, 0, 0, 2);
    sins = Math_SinS(rotY);
    coss = Math_CosS(rotY);
    for (j = 0; j < 32; j++) {
        f32 rand = Rand_ZeroOne();

        if (rand < 0.1f) {
            unkArg5 = 0x60;
        } else if (rand < 0.8f) {
            unkArg5 = 0x40;
        } else {
            unkArg5 = 0x20;
        }
        pos.x = pthis->dyna.actor.world.pos.x;
        pos.y = pthis->dyna.actor.world.pos.y + ((4.375f * j) + 10.0f);
        pos.z = pthis->dyna.actor.world.pos.z;
        temp_f22 = fabsf(j - 15.5f) * (1.0f / 31) + 0.5f;
        vel.x = 2.0f * ((Rand_ZeroOne() * 6.0f) - 3.0f) + (Rand_ZeroOne() * sins * 8.0f * temp_f22);
        vel.y = (Rand_ZeroOne() * 8.0f) - 3.0f;
        vel.z = 2.0f * ((Rand_ZeroOne() * 6.0f) - 3.0f) + (Rand_ZeroOne() * coss * 8.0f * temp_f22);
        EffectSsKakera_Spawn(globalCtx, &pos, &vel, &pos, -350, unkArg5, D_80899500[j & 7], 4, 0, D_808994E0[j & 7], 0,
                             5, D_808994F0[j & 7], -1, OBJECT_JYA_IRON, gObjectJyaIronDL_000880);
        if (Rand_ZeroOne() < 0.26f) {
            func_80033480(globalCtx, &pos, 200.0f, 1, D_808994E0[j & 7] * 4 + 60, D_808994E0[j & 7] * 4 + 80, 1);
        }
    }
}

/*
 * Spawns particles for the destroyed throne
 */
void BgJyaIronobj_SpawnThoneParticles(BgJyaIronobj* pthis, GlobalContext* arg1, EnIk* enIk) {
    s32 i;
    s32 j;
    s16 unkArg5;
    f32 temp_f22;
    Vec3f pos;
    Vec3f vel;
    f32 coss;
    s16 rotY;
    f32 sins;
    s32 pad[2];

    if (enIk->unk_2FF <= 0 || enIk->unk_2FF >= 4) {
        osSyncPrintf("Error 攻撃方法が分からない(%s %d)\n", "../z_bg_jya_ironobj.c", 362, enIk->unk_2FF);
        return;
    }
    osSyncPrintf("¢ attack_type(%d)\n", enIk->unk_2FF);
    rotY = Actor_WorldYawTowardActor(&pthis->dyna.actor, &enIk->actor) + D_808994D8[enIk->unk_2FF - 1];
    for (i = 0; i < 8; i++) {
        Actor* actor =
            Actor_Spawn(&arg1->actorCtx, arg1, ACTOR_BG_JYA_HAHENIRON, pthis->dyna.actor.world.pos.x,
                        (Rand_ZeroOne() * 80.0f) + pthis->dyna.actor.world.pos.y + 10.0f, pthis->dyna.actor.world.pos.z,
                        0, ((s16)(s32)(Rand_ZeroOne() * 0x4000) + rotY) - 0x2000, 0, 0);
        if (actor != NULL) {
            actor->speedXZ = Rand_ZeroOne() * 8.0f + 9.0f;
            actor->velocity.y = Rand_ZeroOne() * 10.0f + 6.0f;
        }
    }
    sins = Math_SinS(rotY);
    coss = Math_CosS(rotY);

    for (j = 0; j < 32; j++) {
        f32 rand = Rand_ZeroOne();

        if (rand < 0.1f) {
            unkArg5 = 0x60;
        } else if (rand < 0.8f) {
            unkArg5 = 0x40;
        } else {
            unkArg5 = 0x20;
        }
        pos.x = pthis->dyna.actor.world.pos.x + (Rand_ZeroOne() * 40 - 20);
        pos.y = pthis->dyna.actor.world.pos.y + (3.75f * j);
        pos.z = pthis->dyna.actor.world.pos.z + (Rand_ZeroOne() * 40 - 20);
        temp_f22 = fabsf(j - 15.5f) * (1.0f / 31) + 0.5f;
        vel.x = 2.0f * (Rand_ZeroOne() * 6.0f - 3.0f) + (Rand_ZeroOne() * sins * 8.0f * temp_f22);
        vel.y = Rand_ZeroOne() * 8.0f - 3.0f;
        vel.z = 2.0f * (Rand_ZeroOne() * 6.0f - 3.0f) + (Rand_ZeroOne() * coss * 8.0f * temp_f22);
        EffectSsKakera_Spawn(arg1, &pos, &vel, &pos, -350, unkArg5, D_80899530[j & 7], 4, 0, D_80899510[j & 7], 0, 5,
                             D_80899520[j & 7], -1, OBJECT_JYA_IRON, gObjectJyaIronDL_000880);
        if (Rand_ZeroOne() < 0.26f) {
            func_80033480(arg1, &pos, 200.0f, 1, D_80899510[j & 7] * 4 + 60, D_80899510[j & 7] * 4 + 80, 1);
        }
    }
}

void BgJyaIronobj_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaIronobj* pthis = (BgJyaIronobj*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, 0);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    BgJyaIronobj_InitCylinder(pthis, globalCtx);
    CollisionHeader_GetVirtual(sCollisionHeaders[thisx->params & 1], &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    func_808992D8(pthis);
}

void BgJyaIronobj_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaIronobj* pthis = (BgJyaIronobj*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->colCylinder);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808992D8(BgJyaIronobj* pthis) {
    pthis->actionFunc = func_808992E8;
}

void func_808992E8(BgJyaIronobj* pthis, GlobalContext* globalCtx) {
    Actor* actor;
    Vec3f dropPos;
    s32 i;

    if (pthis->colCylinder.base.acFlags & AC_HIT) {
        actor = pthis->colCylinder.base.ac;
        pthis->colCylinder.base.acFlags &= ~AC_HIT;
        if (actor != NULL && actor->id == ACTOR_EN_IK) {
            particleFunc_53[pthis->dyna.actor.params & 1](pthis, globalCtx, (EnIk*)actor);
            Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 80, NA_SE_EN_IRONNACK_BREAK_PILLAR);
            dropPos.x = pthis->dyna.actor.world.pos.x;
            dropPos.y = pthis->dyna.actor.world.pos.y + 20.0f;
            dropPos.z = pthis->dyna.actor.world.pos.z;
            for (i = 0; i < 3; i++) {
                Item_DropCollectible(globalCtx, &dropPos, ITEM00_HEART);
                dropPos.y += 18.0f;
            }
            Actor_Kill(&pthis->dyna.actor);
            return;
        }
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colCylinder.base);
    }
}

void BgJyaIronobj_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgJyaIronobj* pthis = (BgJyaIronobj*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgJyaIronobj_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, sOpaDL[thisx->params & 1]);
}

void BgJyaIronobj_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sUnused = 0;

    Bg_Jya_Ironobj_InitVars = {
        ACTOR_BG_JYA_IRONOBJ,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_JYA_IRON,
        sizeof(BgJyaIronobj),
        (ActorFunc)BgJyaIronobj_Init,
        (ActorFunc)BgJyaIronobj_Destroy,
        (ActorFunc)BgJyaIronobj_Update,
        (ActorFunc)BgJyaIronobj_Draw,
        (ActorFunc)BgJyaIronobj_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_ENEMY,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 30, 150, 0, { 0, 0, 0 } },
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_TRAP_Z_BG_HAKA_TRAP_C
#include "actor_common.h"
/*
 * File: z_bg_haka_trap.c
 * Overlay: ovl_Bg_Haka_Trap
 * Description: Shadow Temple Objects
 */

#include "z_bg_haka_trap.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_eff_ss_dead.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_skin_matrix.h"

#define FLAGS 0

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8087FFC0(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808801B8(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808802D8(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_80880484(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808805C0(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808806BC(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808808F4(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808809B0(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_808809E4(BgHakaTrap* pthis, GlobalContext* globalCtx, s16 arg2);
void func_80880AE8(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_80880C0C(BgHakaTrap* pthis, GlobalContext* globalCtx);
void func_80880D68(BgHakaTrap* pthis);

static UNK_TYPE D_80880F30 = 0;

ActorInit Bg_Haka_Trap_InitVars = {
    ACTOR_BG_HAKA_TRAP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaTrap),
    (ActorFunc)BgHakaTrap_Init,
    (ActorFunc)BgHakaTrap_Destroy,
    (ActorFunc)BgHakaTrap_Update,
    (ActorFunc)BgHakaTrap_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x04 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 30, 90, 0, { 0, 0, 0 } },
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00020000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 1800.0f, 1200.0f, 0.0f }, { -1800.0f, 1200.0f, 0.0f }, { -1800.0f, 0.0f, 0.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00020000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 1800.0f, 1200.0f, 0.0f }, { -1800.0f, 0.0f, 0.0f }, { 1800.0f, 0.0f, 0.0f } } },
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
    sTrisElementsInit,
};

static CollisionCheckInfoInit sColChkInfoInit = { 0, 80, 100, MASS_IMMOVABLE };

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx) {
    static UNK_TYPE D_80881014 = 0;
    BgHakaTrap* pthis = (BgHakaTrap*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    thisx->params &= 0xFF;

    if (thisx->params != HAKA_TRAP_PROPELLER) {
        Collider_InitCylinder(globalCtx, &pthis->colliderCylinder);
        Collider_SetCylinder(globalCtx, &pthis->colliderCylinder, thisx, &sCylinderInit);

        if ((thisx->params == HAKA_TRAP_GUILLOTINE_SLOW) || (thisx->params == HAKA_TRAP_GUILLOTINE_FAST)) {
            pthis->timer = 20;
            pthis->colliderCylinder.dim.yShift = 10;
            thisx->velocity.y = 0.1f;

            if (thisx->params == HAKA_TRAP_GUILLOTINE_FAST) {
                thisx->params = HAKA_TRAP_GUILLOTINE_SLOW;
                pthis->unk_16A = 1;
            }

            pthis->actionFunc = func_80880484;
        } else {
            DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);
            thisx->flags |= ACTOR_FLAG_4;

            if (thisx->params == HAKA_TRAP_SPIKED_BOX) {
                CollisionHeader_GetVirtual(&object_haka_objects_Col_009CD0, &colHeader);
                pthis->timer = 30;

                if (D_80881014 != 0) {
                    pthis->actionFunc = func_808808F4;
                    D_80881014 = 0;
                } else {
                    D_80881014 = 1;
                    pthis->actionFunc = func_808806BC;
                    thisx->velocity.y = 0.5f;
                }

                thisx->floorHeight = thisx->home.pos.y - 225.0f;
                pthis->unk_16A = (thisx->floorHeight + 50.0f) - 25.0f;

                pthis->colliderCylinder.dim.radius = 10;
                pthis->colliderCylinder.dim.height = 40;
            } else {
                if (thisx->params == HAKA_TRAP_SPIKED_WALL) {
                    CollisionHeader_GetVirtual(&object_haka_objects_Col_0081D0, &colHeader);
                    thisx->home.pos.x -= 200.0f;
                } else {
                    thisx->home.pos.x += 200.0f;
                    CollisionHeader_GetVirtual(&object_haka_objects_Col_008D10, &colHeader);
                }

                Collider_InitTris(globalCtx, &pthis->colliderSpikes);
                Collider_SetTris(globalCtx, &pthis->colliderSpikes, thisx, &sTrisInit, pthis->colliderSpikesItem);

                pthis->colliderCylinder.dim.radius = 18;
                pthis->colliderCylinder.dim.height = 115;

                pthis->colliderCylinder.info.toucherFlags = pthis->colliderCylinder.info.toucherFlags;
                pthis->colliderCylinder.info.toucherFlags |= TOUCH_SFX_WOOD;

                pthis->actionFunc = func_808801B8;
            }

            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
        }
    } else {
        pthis->timer = 40;
        pthis->actionFunc = func_808809B0;
        thisx->uncullZoneScale = 500.0f;
    }

    CollisionCheck_SetInfo(&thisx->colChkInfo, 0, &sColChkInfoInit);
}

void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTrap* pthis = (BgHakaTrap*)thisx;

    if (pthis->dyna.actor.params != HAKA_TRAP_PROPELLER) {
        if (pthis->dyna.actor.params != HAKA_TRAP_GUILLOTINE_SLOW) {
            DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
            if ((pthis->dyna.actor.params == HAKA_TRAP_SPIKED_WALL) ||
                (pthis->dyna.actor.params == HAKA_TRAP_SPIKED_WALL_2)) {
                Collider_DestroyTris(globalCtx, &pthis->colliderSpikes);
            }
        }

        Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinder);
    }

    Audio_StopSfxByPos(&pthis->unk_16C);
}

void func_8087FFC0(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    f32 cosine;
    Vec3f sp28;
    f32 sine;
    f32 zNonNegative;
    Player* player = GET_PLAYER(globalCtx);

    func_8002DBD0(&pthis->dyna.actor, &sp28, &player->actor.world.pos);

    sine = Math_SinS(pthis->dyna.actor.shape.rot.y);
    cosine = Math_CosS(pthis->dyna.actor.shape.rot.y);
    if (pthis->dyna.actor.params == HAKA_TRAP_GUILLOTINE_SLOW) {
        sp28.x = CLAMP(sp28.x, -50.0f, 50.0f);
        zNonNegative = (sp28.z >= 0.0f) ? 1.0f : -1.0f;
        sp28.z = zNonNegative * -15.0f;
    } else {
        sp28.x = -CLAMP(sp28.x, -162.0f, 162.0f);
        zNonNegative = (sp28.z >= 0.0f) ? 1.0f : -1.0f;
        sp28.z = zNonNegative * 15.0f;
    }

    pthis->colliderCylinder.dim.pos.x = pthis->dyna.actor.world.pos.x + sp28.x * cosine + sp28.z * sine;
    pthis->colliderCylinder.dim.pos.z = pthis->dyna.actor.world.pos.z + sp28.x * sine + sp28.z * cosine;
}

void func_808801B8(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    static UNK_TYPE D_80881018 = 0;
    Player* player = GET_PLAYER(globalCtx);

    if ((D_80880F30 == 0) && (!Player_InCsMode(globalCtx))) {
        if (!Math_StepToF(&pthis->dyna.actor.world.pos.x, pthis->dyna.actor.home.pos.x, 0.5f)) {
            func_8002F974(&pthis->dyna.actor, NA_SE_EV_TRAP_OBJ_SLIDE - SFX_FLAG);
        } else if (pthis->dyna.actor.params == HAKA_TRAP_SPIKED_WALL) {
            D_80881018 |= 1;
        } else if (pthis->dyna.actor.params == HAKA_TRAP_SPIKED_WALL_2) {
            D_80881018 |= 2;
        }
    }

    func_8087FFC0(pthis, globalCtx);

    if (pthis->colliderSpikes.base.acFlags & AC_HIT) {
        pthis->timer = 20;
        D_80880F30 = 1;
        pthis->actionFunc = func_808802D8;
    } else if (D_80881018 == 3) {
        D_80881018 = 4;
        player->actor.bgCheckFlags |= 0x100;
    }
}

void func_808802D8(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f vector;
    f32 xScale;
    s32 i;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    func_8002F974(&pthis->dyna.actor, NA_SE_EV_BURN_OUT - SFX_FLAG);

    for (i = 0; i < 2; i++) {
        f32 rand = Rand_ZeroOne();

        xScale = (pthis->dyna.actor.params == HAKA_TRAP_SPIKED_WALL) ? -30.0f : 30.0f;

        vector.x = xScale * rand + pthis->dyna.actor.world.pos.x;
        vector.y = Rand_ZeroOne() * 10.0f + pthis->dyna.actor.world.pos.y + 30.0f;
        vector.z = Rand_CenteredFloat(320.0f) + pthis->dyna.actor.world.pos.z;

        EffectSsDeadDb_Spawn(globalCtx, &vector, &zeroVec, &zeroVec, 130, 20, 255, 255, 150, 170, 255, 0, 0, 1, 9,
                             false);
    }

    if (pthis->timer == 0) {
        D_80880F30 = 0;
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_80880484(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    s32 sp24;
    s32 timer;

    if (pthis->unk_16A) {
        pthis->dyna.actor.velocity.y *= 3.0f;
    } else {
        pthis->dyna.actor.velocity.y *= 2.0f;
    }

    if (pthis->timer != 0) {
        pthis->timer -= 1;
    }

    sp24 =
        Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 185.0f, pthis->dyna.actor.velocity.y);
    timer = pthis->timer;

    if ((timer == 10 && !pthis->unk_16A) || (timer == 13 && pthis->unk_16A)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_GUILLOTINE_BOUND);
    }

    if (pthis->timer == 0) {
        pthis->dyna.actor.velocity.y = 0.0f;
        pthis->timer = (pthis->unk_16A) ? 10 : 40;
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_GUILLOTINE_UP);
        pthis->actionFunc = func_808805C0;
    }

    func_8087FFC0(pthis, globalCtx);

    if (sp24 == 0) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
    }
}

void func_808805C0(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->unk_16A) {
        Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 27.0f);
    } else {
        if (pthis->timer > 20) {
            Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 90.0f, 9.0f);
        } else {
            Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 4.5f);
        }

        if (pthis->timer == 20) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_GUILLOTINE_UP);
        }
    }

    if (pthis->timer == 0) {
        pthis->timer = 20;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
        pthis->dyna.actor.velocity.y = 0.1f;
        pthis->actionFunc = func_80880484;
    }

    func_8087FFC0(pthis, globalCtx);
}

void func_808806BC(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    Vec3f vector;
    f32 tempf20;
    f32 temp;
    s32 i;
    s32 sp64;

    pthis->dyna.actor.velocity.y *= 1.6f;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    vector.x = pthis->dyna.actor.world.pos.x + 90.0f;
    vector.y = (pthis->dyna.actor.world.pos.y + 1.0f) + 25.0f;
    vector.z = pthis->dyna.actor.world.pos.z;

    tempf20 = pthis->dyna.actor.floorHeight;

    for (i = 0; i < 3; i++) {
        temp = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &pthis->dyna.actor.floorPoly, &sp64, &pthis->dyna.actor,
                                           &vector) -
               25.0f;
        if (tempf20 < temp) {
            tempf20 = temp;
        }

        vector.x -= 90.0f;
    }

    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, tempf20, pthis->dyna.actor.velocity.y)) {
        if (pthis->dyna.actor.velocity.y > 0.01f) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_TRAP_BOUND);
        }
        pthis->dyna.actor.velocity.y = 0.0f;
    }

    if (pthis->dyna.actor.velocity.y >= 0.01f) {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_CHINETRAP_DOWN - SFX_FLAG);
    }

    if (pthis->timer == 0) {
        pthis->dyna.actor.velocity.y = 0.0f;
        pthis->timer = 30;
        pthis->unk_16A = (s16)pthis->dyna.actor.world.pos.y + 50.0f;
        pthis->unk_16A = CLAMP_MAX(pthis->unk_16A, pthis->dyna.actor.home.pos.y);

        pthis->actionFunc = func_808808F4;
    }
}

void func_808808F4(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer > 20) {
        pthis->unk_169 = Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->unk_16A, 15.0f);
    } else {
        pthis->unk_169 = Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 20.0f);
    }

    if (pthis->timer == 0) {
        pthis->timer = 30;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
        pthis->dyna.actor.velocity.y = 0.5f;
        pthis->actionFunc = func_808806BC;
    }
}

void func_808809B0(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer -= 1;
    }

    if (pthis->timer == 0) {
        pthis->actionFunc = func_80880AE8;
    }
}

void func_808809E4(BgHakaTrap* pthis, GlobalContext* globalCtx, s16 arg2) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f sp18;

    func_8002DBD0(&pthis->dyna.actor, &sp18, &player->actor.world.pos);

    if ((fabsf(sp18.x) < 70.0f) && (fabsf(sp18.y) < 100.0f) && (sp18.z < 500.0f) &&
        (GET_PLAYER(globalCtx)->currentBoots != PLAYER_BOOTS_IRON)) {
        player->windSpeed = ((500.0f - sp18.z) * 0.06f + 5.0f) * arg2 * (1.0f / 0x3A00) * (2.0f / 3.0f);
        player->windDirection = pthis->dyna.actor.shape.rot.y;
    }
}

void func_80880AE8(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        if (Math_ScaledStepToS(&pthis->dyna.actor.world.rot.z, 0, pthis->dyna.actor.world.rot.z * 0.03f + 5.0f)) {
            pthis->timer = 40;
            pthis->actionFunc = func_808809B0;
        }
    } else {
        if (Math_ScaledStepToS(&pthis->dyna.actor.world.rot.z, 0x3A00, pthis->dyna.actor.world.rot.z * 0.03f + 5.0f)) {
            pthis->timer = 100;
            pthis->actionFunc = func_80880C0C;
        }
    }

    pthis->dyna.actor.shape.rot.z += pthis->dyna.actor.world.rot.z;
    if (pthis->dyna.actor.world.rot.z >= 0x1801) {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_WIND_TRAP - SFX_FLAG);
    }

    func_808809E4(pthis, globalCtx, pthis->dyna.actor.world.rot.z);
}

void func_80880C0C(BgHakaTrap* pthis, GlobalContext* globalCtx) {
    if (pthis->timer != 0) {
        pthis->timer--;
    }

    func_8002F974(&pthis->dyna.actor, NA_SE_EV_WIND_TRAP - SFX_FLAG);

    if (pthis->timer == 0) {
        pthis->timer = 1;
        pthis->actionFunc = func_80880AE8;
    }

    pthis->dyna.actor.shape.rot.z += pthis->dyna.actor.world.rot.z;
    func_808809E4(pthis, globalCtx, pthis->dyna.actor.world.rot.z);
}

void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaTrap* pthis = (BgHakaTrap*)thisx;
    Vec3f* actorPos = &pthis->dyna.actor.world.pos;

    pthis->actionFunc(pthis, globalCtx);

    if ((pthis->dyna.actor.params != HAKA_TRAP_PROPELLER) && (thisx->params != HAKA_TRAP_SPIKED_BOX)) {
        pthis->colliderCylinder.dim.pos.y = actorPos->y;

        if ((thisx->params == HAKA_TRAP_GUILLOTINE_SLOW) || (thisx->params == HAKA_TRAP_GUILLOTINE_FAST)) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
        } else {
            if (pthis->actionFunc == func_808801B8) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderSpikes.base);
            }

            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
        }
    }
}

void func_80880D68(BgHakaTrap* pthis) {
    Vec3f vec3;
    Vec3f vec2;
    Vec3f vec1;

    Matrix_MultVec3f(&sTrisElementsInit[0].dim.vtx[0], &vec1);
    Matrix_MultVec3f(&sTrisElementsInit[0].dim.vtx[1], &vec2);
    Matrix_MultVec3f(&sTrisElementsInit[0].dim.vtx[2], &vec3);
    Collider_SetTrisVertices(&pthis->colliderSpikes, 0, &vec1, &vec2, &vec3);

    Matrix_MultVec3f(&sTrisElementsInit[1].dim.vtx[2], &vec2);
    Collider_SetTrisVertices(&pthis->colliderSpikes, 1, &vec1, &vec3, &vec2);
}

void BgHakaTrap_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* sDLists[5] = {
        object_haka_objects_DL_007610, object_haka_objects_DL_009860, object_haka_objects_DL_007EF0,
        object_haka_objects_DL_008A20, object_haka_objects_DL_0072C0,
    };
    static Color_RGBA8 D_8088103C = { 0, 0, 0, 0 };
    BgHakaTrap* pthis = (BgHakaTrap*)thisx;
    s32 pad;
    Vec3f sp2C;

    if (pthis->actionFunc == func_808802D8) {
        func_80026230(globalCtx, &D_8088103C, pthis->timer + 20, 0x28);
    }

    Gfx_DrawDListOpa(globalCtx, sDLists[pthis->dyna.actor.params]);

    if (pthis->actionFunc == func_808801B8) {
        func_80880D68(pthis);
    }

    if (pthis->actionFunc == func_808802D8) {
        func_80026608(globalCtx);
    }

    if ((pthis->actionFunc == func_808808F4) && !pthis->unk_169) {
        sp2C.x = pthis->dyna.actor.world.pos.x;
        sp2C.z = pthis->dyna.actor.world.pos.z;
        sp2C.y = pthis->dyna.actor.world.pos.y + 110.0f;

        SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->viewProjectionMtxF, &sp2C, &pthis->unk_16C);
        func_80078914(&pthis->unk_16C, NA_SE_EV_BRIDGE_CLOSE - SFX_FLAG);
    }
}

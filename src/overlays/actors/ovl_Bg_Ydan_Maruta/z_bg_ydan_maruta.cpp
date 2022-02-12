#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_YDAN_MARUTA_Z_BG_YDAN_MARUTA_C
#include "actor_common.h"
/*
 * File: z_bg_ydan_maruta.c
 * Overlay: ovl_Bg_Ydan_Maruta
 * Description: Rotating spike log and falling ladder in Deku Tree
 */

#include "z_bg_ydan_maruta.h"
#include "objects/object_ydan_objects/object_ydan_objects.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS 0

void BgYdanMaruta_Init(Actor* thisx, GlobalContext* globalCtx);
void BgYdanMaruta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgYdanMaruta_Update(Actor* thisx, GlobalContext* globalCtx);
void BgYdanMaruta_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808BEFF4(BgYdanMaruta* pthis, GlobalContext* globalCtx);
void BgYdanMaruta_DoNothing(BgYdanMaruta* pthis, GlobalContext* globalCtx);
void func_808BF078(BgYdanMaruta* pthis, GlobalContext* globalCtx);
void func_808BF108(BgYdanMaruta* pthis, GlobalContext* globalCtx);
void func_808BF1EC(BgYdanMaruta* pthis, GlobalContext* globalCtx);

ActorInit Bg_Ydan_Maruta_InitVars = {
    ACTOR_BG_YDAN_MARUTA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_YDAN_OBJECTS,
    sizeof(BgYdanMaruta),
    (ActorFunc)BgYdanMaruta_Init,
    (ActorFunc)BgYdanMaruta_Destroy,
    (ActorFunc)BgYdanMaruta_Update,
    (ActorFunc)BgYdanMaruta_Draw,
};

static ColliderTrisElementInit sTrisElementsInit[2] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x00, 0x04 },
            { 0x00000004, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_WOOD,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 220.0f, -10.0f, 0.0f }, { 220.0f, 10.0f, 0.0f }, { -220.0f, 10.0f, 0.0f } } },
    },
    {
        {
            ELEMTYPE_UNK0,
            { 0x20000000, 0x00, 0x04 },
            { 0x00000004, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_WOOD,
            BUMP_ON,
            OCELEM_NONE,
        },
        { { { 16.0f, 0.0f, 0.0f }, { 16.0f, 135.0f, 0.0f }, { -16.0f, 135.0f, 0.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_TRIS,
    },
    2,
    sTrisElementsInit,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgYdanMaruta_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgYdanMaruta* pthis = (BgYdanMaruta*)thisx;
    Vec3f sp4C[3];
    s32 i;
    f32 sinRotY;
    f32 cosRotY;
    CollisionHeader* colHeader = NULL;
    ColliderTrisElementInit* triInit;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    Collider_InitTris(globalCtx, &pthis->collider);
    Collider_SetTris(globalCtx, &pthis->collider, &pthis->dyna.actor, &sTrisInit, pthis->elements);

    pthis->switchFlag = pthis->dyna.actor.params & 0xFFFF;
    thisx->params = (thisx->params >> 8) & 0xFF; // thisx is required to match here

    if (pthis->dyna.actor.params == 0) {
        triInit = &sTrisElementsInit[0];
        pthis->actionFunc = func_808BEFF4;
    } else {
        triInit = &sTrisElementsInit[1];
        DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
        CollisionHeader_GetVirtual(&gDTFallingLadderCol, &colHeader);
        pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
        thisx->home.pos.y += -280.0f;
        if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
            thisx->world.pos.y = thisx->home.pos.y;
            pthis->actionFunc = BgYdanMaruta_DoNothing;
        } else {
            pthis->actionFunc = func_808BF078;
        }
    }

    sinRotY = Math_SinS(pthis->dyna.actor.shape.rot.y);
    cosRotY = Math_CosS(pthis->dyna.actor.shape.rot.y);

    for (i = 0; i < 3; i++) {
        sp4C[i].x = (triInit->dim.vtx[i].x * cosRotY) + pthis->dyna.actor.world.pos.x;
        sp4C[i].y = triInit->dim.vtx[i].y + pthis->dyna.actor.world.pos.y;
        sp4C[i].z = pthis->dyna.actor.world.pos.z - (triInit->dim.vtx[i].x * sinRotY);
    }

    Collider_SetTrisVertices(&pthis->collider, 0, &sp4C[0], &sp4C[1], &sp4C[2]);

    sp4C[1].x = (triInit->dim.vtx[2].x * cosRotY) + pthis->dyna.actor.world.pos.x;
    sp4C[1].y = triInit->dim.vtx[0].y + pthis->dyna.actor.world.pos.y;
    sp4C[1].z = pthis->dyna.actor.world.pos.z - (triInit->dim.vtx[2].x * sinRotY);

    Collider_SetTrisVertices(&pthis->collider, 1, &sp4C[0], &sp4C[2], &sp4C[1]);
}

void BgYdanMaruta_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanMaruta* pthis = (BgYdanMaruta*)thisx;

    Collider_DestroyTris(globalCtx, &pthis->collider);
    if (pthis->dyna.actor.params == 1) {
        DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void func_808BEFF4(BgYdanMaruta* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.atFlags & AT_HIT) {
        func_8002F71C(globalCtx, &pthis->dyna.actor, 7.0f, pthis->dyna.actor.shape.rot.y, 6.0f);
    }
    pthis->dyna.actor.shape.rot.x += 0x360;
    CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_TOGE_STICK_ROLLING - SFX_FLAG);
}

void func_808BF078(BgYdanMaruta* pthis, GlobalContext* globalCtx) {
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->unk_16A = 20;
        Flags_SetSwitch(globalCtx, pthis->switchFlag);
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        pthis->actionFunc = func_808BF108;
        OnePointCutscene_Init(globalCtx, 3010, 50, &pthis->dyna.actor, MAIN_CAM);
    } else {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }
}

void func_808BF108(BgYdanMaruta* pthis, GlobalContext* globalCtx) {
    s16 temp;

    if (pthis->unk_16A != 0) {
        pthis->unk_16A--;
    }
    if (pthis->unk_16A == 0) {
        pthis->actionFunc = func_808BF1EC;
    }

    if (1) {}

    temp = (pthis->unk_16A % 4) - 2;
    if (temp == -2) {
        temp = 0;
    } else {
        temp *= 2;
    }

    pthis->dyna.actor.world.pos.x = (Math_CosS(pthis->dyna.actor.shape.rot.y) * temp) + pthis->dyna.actor.home.pos.x;
    pthis->dyna.actor.world.pos.z = (Math_SinS(pthis->dyna.actor.shape.rot.y) * temp) + pthis->dyna.actor.home.pos.z;

    func_8002F974(&pthis->dyna.actor, NA_SE_EV_TRAP_OBJ_SLIDE - SFX_FLAG);
}

void func_808BF1EC(BgYdanMaruta* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.velocity.y += 1.0f;
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.velocity.y)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_LADDER_DOUND);
        pthis->actionFunc = BgYdanMaruta_DoNothing;
    }
}

void BgYdanMaruta_DoNothing(BgYdanMaruta* pthis, GlobalContext* globalCtx) {
}

void BgYdanMaruta_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanMaruta* pthis = (BgYdanMaruta*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgYdanMaruta_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgYdanMaruta* pthis = (BgYdanMaruta*)thisx;

    if (pthis->dyna.actor.params == 0) {
        Gfx_DrawDListOpa(globalCtx, gDTRollingSpikeTrapDL);
    } else {
        Gfx_DrawDListOpa(globalCtx, gDTFallingLadderDL);
    }
}

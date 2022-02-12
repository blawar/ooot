#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_HAKA_MEGANEBG_Z_BG_HAKA_MEGANEBG_C
#include "actor_common.h"
/*
 * File: z_bg_haka_meganebg.c
 * Overlay: ovl_Bg_Haka_MeganeBG
 * Description:
 */

#include "z_bg_haka_meganebg.h"
#include "objects/object_haka_objects/object_haka_objects.h"
#include "def/code_80043480.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"

#define FLAGS 0

void BgHakaMeganeBG_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMeganeBG_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMeganeBG_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaMeganeBG_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8087DFF8(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E040(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E10C(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E1E0(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E258(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E288(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E2D8(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);
void func_8087E34C(BgHakaMeganeBG* pthis, GlobalContext* globalCtx);

ActorInit Bg_Haka_MeganeBG_InitVars = {
    ACTOR_BG_HAKA_MEGANEBG,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaMeganeBG),
    (ActorFunc)BgHakaMeganeBG_Init,
    (ActorFunc)BgHakaMeganeBG_Destroy,
    (ActorFunc)BgHakaMeganeBG_Update,
    (ActorFunc)BgHakaMeganeBG_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

// Unused
static u32 D_8087E3FC[] = {
    0x00000000, 0x00000000, 0x00000000, 0xC8C800FF, 0xFF0000FF,
};

static Gfx* D_8087E410[] = {
    object_haka_objects_DL_008EB0,
    object_haka_objects_DL_00A1A0,
    object_haka_objects_DL_005000,
    object_haka_objects_DL_000040,
};

void BgHakaMeganeBG_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHakaMeganeBG* pthis = (BgHakaMeganeBG*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    pthis->unk_168 = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;

    if (thisx->params == 2) {
        DynaPolyActor_Init(&pthis->dyna, DPM_UNK3);
        thisx->flags |= ACTOR_FLAG_4;
        CollisionHeader_GetVirtual(&object_haka_objects_Col_005334, &colHeader);
        pthis->actionFunc = func_8087E258;
    } else {
        DynaPolyActor_Init(&pthis->dyna, DPM_PLAYER);

        if (thisx->params == 0) {
            CollisionHeader_GetVirtual(&object_haka_objects_Col_009168, &colHeader);
            thisx->flags |= ACTOR_FLAG_7;
            pthis->unk_16A = 20;
            pthis->actionFunc = func_8087DFF8;
        } else if (thisx->params == 3) {
            CollisionHeader_GetVirtual(&object_haka_objects_Col_000118, &colHeader);
            thisx->home.pos.y += 100.0f;

            if (Flags_GetSwitch(globalCtx, pthis->unk_168)) {
                pthis->actionFunc = func_8087E34C;
                thisx->world.pos.y = thisx->home.pos.y;
            } else {
                thisx->flags |= ACTOR_FLAG_4;
                pthis->actionFunc = func_8087E288;
            }
        } else {
            CollisionHeader_GetVirtual(&object_haka_objects_Col_00A7F4, &colHeader);
            pthis->unk_16A = 80;
            pthis->actionFunc = func_8087E10C;
            thisx->uncullZoneScale = 3000.0f;
            thisx->uncullZoneDownward = 3000.0f;
        }
    }

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
}

void BgHakaMeganeBG_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMeganeBG* pthis = (BgHakaMeganeBG*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_8087DFF8(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_16A != 0) {
        pthis->unk_16A--;
    }

    if (pthis->unk_16A == 0) {
        pthis->unk_16A = 40;
        pthis->dyna.actor.world.rot.y += 0x8000;
        pthis->actionFunc = func_8087E040;
    }
}

void func_8087E040(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    f32 xSub;

    if (pthis->unk_16A != 0) {
        pthis->unk_16A--;
    }

    xSub = (sinf(((pthis->unk_16A * 0.025f) + 0.5f) * M_PI) + 1.0f) * 160.0f;

    if (pthis->dyna.actor.world.rot.y != pthis->dyna.actor.shape.rot.y) {
        xSub = 320.0f - xSub;
    }

    pthis->dyna.actor.world.pos.x = pthis->dyna.actor.home.pos.x - xSub;

    if (pthis->unk_16A == 0) {
        pthis->unk_16A = 20;
        pthis->actionFunc = func_8087DFF8;
    }
}

void func_8087E10C(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.velocity.y += 1.0f;

    if (pthis->dyna.actor.velocity.y > 20.0f) {
        pthis->dyna.actor.velocity.y = 20.0f;
    } else {
        pthis->dyna.actor.velocity.y = pthis->dyna.actor.velocity.y;
    }

    if (pthis->unk_16A != 0) {
        pthis->unk_16A--;
    }

    if (!Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y - 640.0f,
                      pthis->dyna.actor.velocity.y)) {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_CHINETRAP_DOWN - SFX_FLAG);
    }

    if (pthis->unk_16A == 0) {
        pthis->unk_16A = 120;
        pthis->actionFunc = func_8087E1E0;
        pthis->dyna.actor.velocity.y = 0.0f;
    }
}

void func_8087E1E0(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, 16.0f / 3.0f);
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_BRIDGE_CLOSE - SFX_FLAG);

    if (pthis->unk_16A != 0) {
        pthis->unk_16A--;
    }

    if (pthis->unk_16A == 0) {
        pthis->unk_16A = 80;
        pthis->actionFunc = func_8087E10C;
    }
}

void func_8087E258(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    pthis->dyna.actor.shape.rot.y += 0x180;
    func_8002F974(&pthis->dyna.actor, NA_SE_EV_ELEVATOR_MOVE - SFX_FLAG);
}

void func_8087E288(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->unk_168)) {
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        pthis->actionFunc = func_8087E2D8;
    }
}

void func_8087E2D8(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
    Math_StepToF(&pthis->dyna.actor.speedXZ, 30.0f, 2.0f);

    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y, pthis->dyna.actor.speedXZ)) {
        Actor_SetFocus(&pthis->dyna.actor, 50.0f);
        pthis->actionFunc = func_8087E34C;
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_METALDOOR_OPEN);
    }
}

void func_8087E34C(BgHakaMeganeBG* pthis, GlobalContext* globalCtx) {
}

void BgHakaMeganeBG_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMeganeBG* pthis = (BgHakaMeganeBG*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgHakaMeganeBG_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaMeganeBG* pthis = (BgHakaMeganeBG*)thisx;
    s16 params = pthis->dyna.actor.params;

    if (params == 0) {
        Gfx_DrawDListXlu(globalCtx, object_haka_objects_DL_008EB0);
    } else {
        Gfx_DrawDListOpa(globalCtx, D_8087E410[params]);
    }
}

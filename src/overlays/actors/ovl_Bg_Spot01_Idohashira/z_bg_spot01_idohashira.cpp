#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT01_IDOHASHIRA_Z_BG_SPOT01_IDOHASHIRA_C
#include "actor_common.h"
/*
 * File: z_bg_spot01_idohashira.c
 * Overlay: Bg_Spot01_Idohashira
 * Description: Wooden beam above well in Kakariko Village
 */

#include "z_bg_spot01_idohashira.h"
#include "objects/object_spot01_objects/object_spot01_objects.h"
#include "vt.h"
#include "def/code_80043480.h"
#include "def/code_8006BA00.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_effect.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void BgSpot01Idohashira_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idohashira_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idohashira_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot01Idohashira_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808AB504(BgSpot01Idohashira* pthis, GlobalContext* globalCtx);
void func_808AB510(BgSpot01Idohashira* pthis, GlobalContext* globalCtx);
void func_808AB530(BgSpot01Idohashira* pthis, GlobalContext* globalCtx);
void func_808AB570(BgSpot01Idohashira* pthis, GlobalContext* globalCtx);
void func_808AB700(BgSpot01Idohashira* pthis, GlobalContext* globalCtx);

static BgSpot01IdohashiraActionFunc sActionFuncs[] = {
    func_808AB504,
    func_808AB510,
    func_808AB530,
    func_808AB570,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

static BgSpot01IdohashiraDrawFunc sDrawFuncs[] = {
    func_808AB700,
};

ActorInit Bg_Spot01_Idohashira_InitVars = {
    ACTOR_BG_SPOT01_IDOHASHIRA,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_SPOT01_OBJECTS,
    sizeof(BgSpot01Idohashira),
    (ActorFunc)BgSpot01Idohashira_Init,
    (ActorFunc)BgSpot01Idohashira_Destroy,
    (ActorFunc)BgSpot01Idohashira_Update,
    (ActorFunc)BgSpot01Idohashira_Draw,
};

void BgSpot01Idohashira_PlayBreakSfx1(BgSpot01Idohashira* pthis) {
    func_80078914(&pthis->dyna.actor.projectedPos, NA_SE_EV_BOX_BREAK);
}

void BgSpot01Idohashira_PlayBreakSfx2(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    Audio_PlaySoundAtPosition(globalCtx, &pthis->dyna.actor.world.pos, 60, NA_SE_EV_WOODBOX_BREAK);
}

void func_808AAD3C(GlobalContext* globalCtx, Vec3f* vec, u32 arg2) {
    EffectSparkInit effect;
    s32 sp24;

    effect.position.x = vec->x;
    effect.position.y = vec->y;
    effect.position.z = vec->z;
    effect.speed = 8.0f;
    effect.gravity = -1.0f;
    effect.uDiv = arg2;
    effect.vDiv = arg2;
    effect.colorStart[0].r = 0;
    effect.colorStart[0].g = 0;
    effect.colorStart[0].b = 0;
    effect.colorStart[0].a = 255;
    effect.colorStart[1].r = 0;
    effect.colorStart[1].g = 0;
    effect.colorStart[1].b = 0;
    effect.colorStart[1].a = 255;
    effect.colorStart[2].r = 0;
    effect.colorStart[2].g = 0;
    effect.colorStart[2].b = 0;
    effect.colorStart[2].a = 255;
    effect.colorStart[3].r = 0;
    effect.colorStart[3].g = 0;
    effect.colorStart[3].b = 0;
    effect.colorStart[3].a = 255;
    effect.colorEnd[0].r = 0;
    effect.colorEnd[0].g = 0;
    effect.colorEnd[0].b = 0;
    effect.colorEnd[0].a = 0;
    effect.colorEnd[1].r = 0;
    effect.colorEnd[1].g = 0;
    effect.colorEnd[1].b = 0;
    effect.colorEnd[1].a = 0;
    effect.colorEnd[2].r = 0;
    effect.colorEnd[2].g = 0;
    effect.colorEnd[2].b = 0;
    effect.colorEnd[2].a = 0;
    effect.colorEnd[3].r = 0;
    effect.colorEnd[3].g = 0;
    effect.colorEnd[3].b = 0;
    effect.colorEnd[3].a = 0;
    effect.timer = 0;
    effect.duration = 32;

    Effect_Add(globalCtx, &sp24, EFFECT_SPARK, 0, 1, &effect);
}

void func_808AAE6C(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f sp30 = pthis->dyna.actor.world.pos;

    sp30.y += kREG(15);
    func_80033480(globalCtx, &sp30, kREG(11) + 350.0f, kREG(12) + 5, kREG(13) + 0x7D0, kREG(14) + 0x320, 0);
    func_808AAD3C(globalCtx, &sp30, 5);
    BgSpot01Idohashira_PlayBreakSfx2(pthis, globalCtx);
}

void func_808AAF34(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Vec3f dest;
    Vec3f src;

    if (pthis->unk_170 != 0) {
        src.x = kREG(20) + 1300.0f;
        src.y = kREG(21) + 200.0f;
        src.z = 0.0f;
        Matrix_MultVec3f(&src, &dest);
        func_80033480(globalCtx, &dest, kREG(16) + 80.0f, kREG(17) + 10, kREG(18) + 1000, kREG(19), 0);
        func_808AAD3C(globalCtx, &dest, 3);
        src.x = -(kREG(20) + 1300.0f);
        src.y = kREG(21) + 200.0f;
        src.z = 0.0f;
        Matrix_MultVec3f(&src, &dest);
        func_80033480(globalCtx, &dest, kREG(16) + 80.0f, kREG(17) + 10, kREG(18) + 1000, kREG(19), 0);
        func_808AAD3C(globalCtx, &dest, 3);
        pthis->unk_170 = 0;
        BgSpot01Idohashira_PlayBreakSfx1(pthis);
    }
}

void BgSpot01Idohashira_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idohashira* pthis = (BgSpot01Idohashira*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

s32 BgSpot01Idohashira_NotInCsMode(GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        return true;
    }
    return false;
}

CsCmdActorAction* BgSpot01Idohashira_GetNpcAction(GlobalContext* globalCtx, s32 actionIdx) {
    s32 pad[2];
    CsCmdActorAction* npcAction = NULL;

    if (!BgSpot01Idohashira_NotInCsMode(globalCtx)) {
        npcAction = globalCtx->csCtx.npcActions[actionIdx];
    }
    return npcAction;
}

void func_808AB18C(BgSpot01Idohashira* pthis) {
    pthis->dyna.actor.shape.rot.x += kREG(6);
    pthis->dyna.actor.shape.rot.y += (s16)(kREG(7) + 0x3E8);
    pthis->dyna.actor.shape.rot.z += (s16)(kREG(8) + 0x7D0);
}

f32 func_808AB1DC(f32 arg0, f32 arg1, u16 arg2, u16 arg3, u16 arg4) {
    f32 temp_f12;
    f32 regFloat;
    f32 diff23;
    f32 diff43;

    diff23 = arg2 - arg3;
    if (diff23 != 0.0f) {
        regFloat = kREG(9) + 30.0f;
        diff43 = arg4 - arg3;
        temp_f12 = regFloat * diff43;
        return (((((arg1 - arg0) - temp_f12) / SQ(diff23)) * diff43) * diff43) + temp_f12;
    }
    osSyncPrintf(VT_FGCOL(RED) "Bg_Spot01_Idohashira_Get_FreeFallで割り算出来ない!!!!!!!!!!!!!!\n" VT_RST);
    return 0.0f;
}

s32 func_808AB29C(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;
    Vec3f* thisPos;
    f32 endX;
    f32 temp_f0;
    s32 pad2;
    Vec3f initPos;
    f32 endZ;
    f32 tempY;
    f32 tempZ;

    npcAction = BgSpot01Idohashira_GetNpcAction(globalCtx, 2);
    if (npcAction != NULL) {
        temp_f0 = Environment_LerpWeight(npcAction->endFrame, npcAction->startFrame, globalCtx->csCtx.frames);
        initPos = pthis->dyna.actor.home.pos;
        endX = npcAction->endPos.x;
        tempY = ((kREG(10) + 1100.0f) / 10.0f) + npcAction->endPos.y;
        endZ = npcAction->endPos.z;
        thisPos = &pthis->dyna.actor.world.pos;
        thisPos->x = ((endX - initPos.x) * temp_f0) + initPos.x;
        thisPos->y = func_808AB1DC(initPos.y, tempY, npcAction->endFrame, npcAction->startFrame, globalCtx->csCtx.frames) +
            initPos.y;
        thisPos->z = ((endZ - initPos.z) * temp_f0) + initPos.z;

        if (temp_f0 >= 1.0f) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void func_808AB3E8(BgSpot01Idohashira* pthis) {
    pthis->action = 1;
    pthis->drawConfig = 0;
}

void func_808AB3F8(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    pthis->action = 2;
    pthis->drawConfig = 0;
    pthis->unk_170 = 1;
}

void func_808AB414(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    func_808AAE6C(pthis, globalCtx);
    pthis->action = 3;
    pthis->drawConfig = 0;
}

void func_808AB444(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = BgSpot01Idohashira_GetNpcAction(globalCtx, 2);
    u32 action;
    u32 currentNpcAction;

    if (npcAction != NULL) {
        action = npcAction->action;
        currentNpcAction = pthis->npcAction;
        if (action != currentNpcAction) {
            switch (action) {
                case 1:
                    func_808AB3E8(pthis);
                    break;
                case 2:
                    func_808AB3F8(pthis, globalCtx);
                    break;
                case 3:
                    Actor_Kill(&pthis->dyna.actor);
                    break;
                default:
                    osSyncPrintf("Bg_Spot01_Idohashira_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->npcAction = action;
        }
    }
}

void func_808AB504(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
}

void func_808AB510(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    func_808AB444(pthis, globalCtx);
}

void func_808AB530(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    func_808AB18C(pthis);
    if (func_808AB29C(pthis, globalCtx)) {
        func_808AB414(pthis, globalCtx);
    }
}

void func_808AB570(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    func_808AB444(pthis, globalCtx);
}

void BgSpot01Idohashira_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idohashira* pthis = (BgSpot01Idohashira*)thisx;

    if (pthis->action < 0 || pthis->action >= 4 || sActionFuncs[pthis->action] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->action](pthis, globalCtx);
}

void BgSpot01Idohashira_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad[2];
    BgSpot01Idohashira* pthis = (BgSpot01Idohashira*)thisx;
    CollisionHeader* colHeader;

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    colHeader = NULL;
    CollisionHeader_GetVirtual(&gKakarikoWellArchCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    if (gSaveContext.sceneSetupIndex < 4) {
        if ((gSaveContext.eventChkInf[5] & 0x10) && LINK_IS_ADULT) {
            Actor_Kill(&pthis->dyna.actor);
        } else {
            pthis->action = 0;
        }
    } else if (gSaveContext.sceneSetupIndex == 4) {
        pthis->action = 1;
        pthis->dyna.actor.shape.yOffset = -(kREG(10) + 1100.0f);
    } else if (gSaveContext.sceneSetupIndex == 6) {
        pthis->action = 0;
    } else {
        Actor_Kill(&pthis->dyna.actor);
    }
}

void func_808AB700(BgSpot01Idohashira* pthis, GlobalContext* globalCtx) {
    GraphicsContext* localGfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(localGfxCtx, "../z_bg_spot01_idohashira.c", 689);

    func_80093D18(localGfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(localGfxCtx, "../z_bg_spot01_idohashira.c", 699),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_808AAF34(pthis, globalCtx);
    gSPDisplayList(POLY_OPA_DISP++, gKakarikoWellArchDL);

    CLOSE_DISPS(localGfxCtx, "../z_bg_spot01_idohashira.c", 708);
}

void BgSpot01Idohashira_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot01Idohashira* pthis = (BgSpot01Idohashira*)thisx;

    if (pthis->drawConfig < 0 || pthis->drawConfig > 0 || sDrawFuncs[pthis->drawConfig] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawConfig](pthis, globalCtx);
}

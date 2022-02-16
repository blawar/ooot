#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_TRE_LGT_Z_DEMO_TRE_LGT_C
#include "actor_common.h"
#include "z_demo_tre_lgt.h"
#include "overlays/actors/ovl_En_Box/z_en_box.h"
#include "objects/object_box/object_box.h"
#include "def/code_800F7260.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_fcurve_data_skelanime.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void DemoTreLgt_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoTreLgt_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DemoTreLgt_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoTreLgt_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoTreLgt_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80993848(DemoTreLgt* pthis, GlobalContext* globalCtx);
void func_80993754(DemoTreLgt* pthis);
void func_8099375C(DemoTreLgt* pthis, GlobalContext* globalCtx);
void func_809937B4(DemoTreLgt* pthis, GlobalContext* globalCtx, f32 currentFrame); 

static DemoTreLgtInfo sDemoTreLgtInfo[] = {
    { 1.0f, 136.0f, 190.0f, 40.0f },
    { 1.0f, 136.0f, 220.0f, 50.0f },
};

ActorInit Demo_Tre_Lgt_InitVars = {
    ACTOR_DEMO_TRE_LGT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_BOX,
    sizeof(DemoTreLgt),
    (ActorFunc)DemoTreLgt_Init,
    (ActorFunc)DemoTreLgt_Destroy,
    (ActorFunc)DemoTreLgt_Update,
    (ActorFunc)DemoTreLgt_Draw,
    (ActorFunc)DemoTreLgt_Reset,
};

static TransformUpdateIndex* sTransformUpdIdx[] = { &gTreasureChestCurveAnim_4B60, &gTreasureChestCurveAnim_4F70 };

static DemoTreLgtActionFunc sActionFuncs[] = {
    func_8099375C,
    func_80993848,
};

void DemoTreLgt_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoTreLgt* pthis = (DemoTreLgt*)thisx;

    if (!SkelCurve_Init(globalCtx, &pthis->skelCurve, &gTreasureChestCurveSkel, sTransformUpdIdx[0])) {
        // "Demo_Tre_Lgt_Actor_ct (); Construct failed"
        osSyncPrintf("Demo_Tre_Lgt_Actor_ct();コンストラクト失敗\n");
    }

    ASSERT(true, "1", "../z_demo_tre_lgt.c", UNK_LINE);

    pthis->unk_170 = 255;
    pthis->unk_174 = 255;
    pthis->status = 0;
    func_80993754(pthis);
}

void DemoTreLgt_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoTreLgt* pthis = (DemoTreLgt*)thisx;

    SkelCurve_Destroy(globalCtx, &pthis->skelCurve);
}

void func_80993754(DemoTreLgt* pthis) {
    pthis->action = DEMO_TRE_LGT_ACTION_WAIT;
}

void func_8099375C(DemoTreLgt* pthis, GlobalContext* globalCtx) {
    EnBox* treasureChest = (EnBox*)pthis->actor.parent;

    if (treasureChest != NULL && Animation_OnFrame(&treasureChest->skelanime, 10.0f)) {
        func_809937B4(pthis, globalCtx, treasureChest->skelanime.curFrame);
    }
}

void func_809937B4(DemoTreLgt* pthis, GlobalContext* globalCtx, f32 currentFrame) {
    SkelAnimeCurve* skelCurve = &pthis->skelCurve;
    s32 pad[2];

    pthis->action = DEMO_TRE_LGT_ACTION_ANIMATE;

    SkelCurve_SetAnim(skelCurve, sTransformUpdIdx[gSaveContext.linkAge], 1.0f,
                      sDemoTreLgtInfo[gSaveContext.linkAge].endFrame + sDemoTreLgtInfo[gSaveContext.linkAge].unk_08,
                      currentFrame, 1.0f);
    SkelCurve_Update(globalCtx, skelCurve);
}

void func_80993848(DemoTreLgt* pthis, GlobalContext* globalCtx) {
    f32 currentFrame = pthis->skelCurve.animCurFrame;

    if (currentFrame < sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].endFrame) {
        pthis->unk_170 = 255;
    } else {
        if (currentFrame <= (sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].endFrame +
                             sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].unk_08)) {
            pthis->unk_170 = ((((sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].endFrame - currentFrame) /
                               sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].unk_08) *
                              255.0f) +
                             255.0f);
        } else {
            pthis->unk_170 = 0;
        }
    }
    if (currentFrame < sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].unk_0C) {
        pthis->unk_174 = 255;
    } else if (currentFrame < (sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].unk_0C + 10.0f)) {
        pthis->unk_174 =
            ((((sDemoTreLgtInfo[((void)0, gSaveContext.linkAge)].unk_0C - currentFrame) / 10.0f) * 255.0f) + 255.0f);
    } else {
        pthis->unk_174 = 0;
    }
    if ((currentFrame > 30.0f) && !(pthis->status & 1)) {
        pthis->status |= 1;
        Audio_PlaySoundGeneral(NA_SE_EV_TRE_BOX_FLASH, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
    if (SkelCurve_Update(globalCtx, &pthis->skelCurve)) {
        Actor_Kill(&pthis->actor);
    }
}

void DemoTreLgt_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoTreLgt* pthis = (DemoTreLgt*)thisx;

    sActionFuncs[pthis->action](pthis, globalCtx);
}

s32 DemoTreLgt_PostLimbDraw(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, s32 limbIndex, void* thisx) {
    s32 pad;
    DemoTreLgt* pthis = (DemoTreLgt*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_demo_tre_lgt.c", 423);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (globalCtx->state.frames * 2) % 256, 0, 64, 32, 1,
                                (globalCtx->state.frames * -2) % 256, 0, 64, 32));

    if (limbIndex == 1) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 180, pthis->unk_170);
    } else if ((limbIndex == 13) || (limbIndex == 7) || (limbIndex == 4) || (limbIndex == 10)) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 180, pthis->unk_174);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_demo_tre_lgt.c", 448);
    return 1;
}

void DemoTreLgt_Draw(Actor* thisx, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    DemoTreLgt* pthis = (DemoTreLgt*)thisx;

    OPEN_DISPS(gfxCtx, "../z_demo_tre_lgt.c", 461);

    if (pthis->action != DEMO_TRE_LGT_ACTION_ANIMATE) {
        return;
    }

    func_80093D84(gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, 200, 255, 0, 0);
    SkelCurve_Draw(&pthis->actor, globalCtx, &pthis->skelCurve, DemoTreLgt_PostLimbDraw, NULL, 1, thisx);

    CLOSE_DISPS(gfxCtx, "../z_demo_tre_lgt.c", 476);
}

void DemoTreLgt_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Demo_Tre_Lgt_InitVars = {
        ACTOR_DEMO_TRE_LGT,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_BOX,
        sizeof(DemoTreLgt),
        (ActorFunc)DemoTreLgt_Init,
        (ActorFunc)DemoTreLgt_Destroy,
        (ActorFunc)DemoTreLgt_Update,
        (ActorFunc)DemoTreLgt_Draw,
        (ActorFunc)DemoTreLgt_Reset,
    };

}

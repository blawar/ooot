#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_EC_Z_DEMO_EC_C
#include "actor_common.h"
/*
 * File: z_demo_ec.c
 * Overlay: ovl_Demo_Ec
 * Description: Credits revelers in Lon Lon
 */

#include "z_demo_ec.h"
#include "vt.h"
#include "objects/object_zo/object_zo.h"
#include "objects/object_ec/object_ec.h"
#include "objects/object_ma2/object_ma2.h"
#include "objects/object_in/object_in.h"
#include "objects/object_ge1/object_ge1.h"
#include "objects/object_fu/object_fu.h"
#include "objects/object_fish/object_fish.h"
#include "objects/object_ta/object_ta.h"
#include "objects/object_oF1d_map/object_oF1d_map.h"
#include "objects/object_ma2/object_ma2.h"
#include "objects/object_in/object_in.h"
#include "objects/object_ta/object_ta.h"
#include "objects/object_fu/object_fu.h"
#include "objects/object_toryo/object_toryo.h"
#include "objects/object_daiku/object_daiku.h"
#include "objects/object_ge1/object_ge1.h"
#include "objects/object_kz/object_kz.h"
#include "objects/object_md/object_md.h"
#include "objects/object_niw/object_niw.h"
#include "objects/object_ds2/object_ds2.h"
#include "objects/object_os/object_os.h"
#include "objects/object_rs/object_rs.h"
#include "objects/object_gm/object_gm.h"
#include "objects/object_km1/object_km1.h"
#include "objects/object_kw1/object_kw1.h"
#include "objects/object_bji/object_bji.h"
#include "objects/object_ahg/object_ahg.h"
#include "objects/object_bob/object_bob.h"
#include "objects/object_bba/object_bba.h"
#include "objects/object_ane/object_ane.h"
#include "def/graph.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void DemoEc_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoEc_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DemoEc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoEc_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoEc_Draw(Actor* thisx, GlobalContext* globalCtx);

static u8 color1_83[] = { 0, 130, 70, 255 };

static u8 color2_83[] = { 110, 170, 20, 255 };

static void* eyeTextures_88[] = { gKw1EyeOpenTex, gKw1EyeHalfTex, gKw1EyeClosedTex };

static u8 color1_88[] = { 70, 190, 60, 255 };

static u8 color2_88[] = { 100, 30, 0, 255 };

static void* eyeTextures_91[] = { object_bji_Tex_0005FC, object_bji_Tex_0009FC, object_bji_Tex_000DFC };

static u8 color1_91[] = { 0, 50, 100, 255 };

static u8 color2_91[] = { 0, 50, 160, 255 };

static void* eyeTextures_94[] = { object_ahg_Tex_00057C, object_ahg_Tex_00067C, object_ahg_Tex_00077C };

static u8 color1_94[] = { 255, 255, 255, 255 };

static u8 color2_94[] = { 255, 255, 255, 255 };

static u8* eyeTextures_97[] = { object_bob_Tex_0007C8, object_bob_Tex_000FC8, object_bob_Tex_0017C8 };

static void* eyeTextures_114[] = { gGerudoWhiteEyeOpenTex, gGerudoWhiteEyeHalfTex, gGerudoWhiteEyeClosedTex };

static void* eyeTextures_117[] = { gZoraEyeOpenTex, gZoraEyeHalfTex, gZoraEyeClosedTex };

static void* eyeTextures_126[] = { gKzEyeOpenTex, gKzEyeHalfTex, gKzEyeClosedTex, gKzEyeOpen2Tex };

static void* eyeTextures_133[] = { gMidoEyeOpenTex, gMidoEyeHalfTex, gMidoEyeClosedTex, gMidoEyeAngryTex };

static void* eyeTextures_139[] = { gCuccoLadyEyeOpenTex, gCuccoLadyEyeHalfTex, gCuccoLadyEyeClosedTex };

static void* eyeTextures_142[] = { gPotionShopkeeperEyeOpenTex, gPotionShopkeeperEyeHalfTex, gPotionShopkeeperEyeClosedTex };

static void* eyeTextures_149[] = {
    gFishingOwnerEyeOpenTex,
    gFishingOwnerEyeHalfTex,
    gFishingOwnerEyeClosedTex,
};

static void* eyeTextures_152[] = { gBombchuShopkeeperEyeOpenTex, gBombchuShopkeeperEyeHalfTex,
                               gBombchuShopkeeperEyeClosedTex };

static void* eyeTextures_155[] = { gGoronCsEyeOpenTex, gGoronCsEyeHalfTex, gGoronCsEyeClosedTex };

static void* eyeTextures_158[] = { gMalonAdultEyeOpenTex, gMalonAdultEyeHalfTex, gMalonAdultEyeClosedTex };


static s16 sDrawObjects[] = {
    /*  0 */ OBJECT_IN,
    /*  1 */ OBJECT_TA,
    /*  2 */ OBJECT_FU,
    /*  3 */ OBJECT_KM1,
    /*  4 */ OBJECT_KW1,
    /*  5 */ OBJECT_BJI,
    /*  6 */ OBJECT_AHG,
    /*  7 */ OBJECT_BOB,
    /*  8 */ OBJECT_BBA,
    /*  9 */ OBJECT_TORYO,
    /* 10 */ OBJECT_DAIKU,
    /* 11 */ OBJECT_DAIKU,
    /* 12 */ OBJECT_DAIKU,
    /* 13 */ OBJECT_DAIKU,
    /* 14 */ OBJECT_KM1,
    /* 15 */ OBJECT_KW1,
    /* 16 */ OBJECT_GE1,
    /* 17 */ OBJECT_GE1,
    /* 18 */ OBJECT_GE1,
    /* 19 */ OBJECT_ZO,
    /* 20 */ OBJECT_KZ,
    /* 21 */ OBJECT_MD,
    /* 22 */ OBJECT_NIW,
    /* 23 */ OBJECT_NIW,
    /* 24 */ OBJECT_NIW,
    /* 25 */ OBJECT_ANE,
    /* 26 */ OBJECT_DS2,
    /* 27 */ OBJECT_OS,
    /* 28 */ OBJECT_FISH,
    /* 29 */ OBJECT_RS,
    /* 30 */ OBJECT_OF1D_MAP,
    /* 31 */ OBJECT_OF1D_MAP,
    /* 32 */ OBJECT_OF1D_MAP,
    /* 33 */ OBJECT_OF1D_MAP,
    /* 34 */ OBJECT_MA2,
};

static s16 sAnimationObjects[] = {
    OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC,  OBJECT_EC,
    OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC,  OBJECT_EC,
    OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC,  OBJECT_EC,
    OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_EC, OBJECT_GM, OBJECT_MA2,
};

void DemoEc_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DemoEc* pthis = (DemoEc*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
}

void DemoEc_Init(Actor* thisx, GlobalContext* globalCtx) {
    DemoEc* pthis = (DemoEc*)thisx;

    if ((pthis->actor.params < 0) || (pthis->actor.params > 34)) {
        osSyncPrintf(VT_FGCOL(RED) "Demo_Ec_Actor_ct:arg_dataがおかしい!!!!!!!!!!!!\n" VT_RST);
        Actor_Kill(&pthis->actor);
    } else {
        pthis->updateMode = EC_UPDATE_COMMON;
        pthis->drawConfig = EC_DRAW_COMMON;
    }
}

s32 DemoEc_UpdateSkelAnime(DemoEc* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

void DemoEc_UpdateBgFlags(DemoEc* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 30.0f, 25.0f, 30.0f, 7);
}

void func_8096D594(DemoEc* pthis, GlobalContext* globalCtx) {
    pthis->skelAnime.moveFlags |= 3;
    AnimationContext_SetMoveActor(globalCtx, &pthis->actor, &pthis->skelAnime, 1.0f);
}

void func_8096D5D4(DemoEc* pthis, GlobalContext* globalCtx) {
    pthis->skelAnime.baseTransl = pthis->skelAnime.jointTable[0];
    pthis->skelAnime.prevTransl = pthis->skelAnime.jointTable[0];
    pthis->skelAnime.moveFlags |= 3;
    AnimationContext_SetMoveActor(globalCtx, &pthis->actor, &pthis->skelAnime, 1.0f);
}

void func_8096D64C(DemoEc* pthis, GlobalContext* globalCtx) {
    pthis->skelAnime.moveFlags |= 3;
    AnimationContext_SetMoveActor(globalCtx, &pthis->actor, &pthis->skelAnime, 1.0f);
}

void DemoEc_UpdateEyes(DemoEc* pthis) {
    s32 pad[3];
    s16* blinkTimer = &pthis->blinkTimer;
    s16* eyeTexIndex = &pthis->eyeTexIndex;

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(60, 60);
    }

    *eyeTexIndex = *blinkTimer;

    if (*eyeTexIndex >= 3) {
        *eyeTexIndex = 0;
    }
}

void DemoEc_SetEyeTexIndex(DemoEc* pthis, s16 texIndex) {
    pthis->eyeTexIndex = texIndex;
}

void DemoEc_InitSkelAnime(DemoEc* pthis, GlobalContext* globalCtx, FlexSkeletonHeader* skeletonHeader) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, SEGMENTED_TO_VIRTUAL(skeletonHeader), NULL, NULL, NULL, 0);
}

void DemoEc_ChangeAnimation(DemoEc* pthis, AnimationHeader* animation, u8 mode, f32 transitionRate, s32 reverse) {
    f32 frameCount;
    f32 startFrame;
    AnimationHeader* anim;
    f32 playbackSpeed;
    s16 frameCountS;

    anim = SEGMENTED_TO_VIRTUAL(animation);
    frameCountS = Animation_GetLastFrame(anim);

    if (!reverse) {
        startFrame = 0.0f;
        frameCount = frameCountS;
        playbackSpeed = 1.0f;
    } else {
        frameCount = 0.0f;
        startFrame = frameCountS;
        playbackSpeed = -1.0f;
    }

    Animation_Change(&pthis->skelAnime, anim, playbackSpeed, startFrame, frameCount, mode, transitionRate);
}

Gfx* DemoEc_AllocColorDList(GraphicsContext* gfxCtx, u8* color) {
    Gfx* dList;

    dList = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx) * 2);
    gDPSetEnvColor(dList, color[0], color[1], color[2], color[3]);
    gSPEndDisplayList(dList + 1);

    return dList;
}

void DemoEc_DrawSkeleton(DemoEc* pthis, GlobalContext* globalCtx, void* eyeTexture, void* arg3,
                         OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_demo_ec.c", 565);

    func_80093D18(gfxCtx);

    if (eyeTexture != NULL) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTexture));
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTexture));
    }

    if (arg3 != NULL) {
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(arg3));
    }

    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
    POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       overrideLimbDraw, postLimbDraw, &pthis->actor, POLY_OPA_DISP);
    CLOSE_DISPS(gfxCtx, "../z_demo_ec.c", 595);
}

void DemoEc_DrawSkeletonCustomColor(DemoEc* pthis, GlobalContext* globalCtx, Gfx* arg2, Gfx* arg3, u8* color1,
                                    u8* color2, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw) {
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(gfxCtx, "../z_demo_ec.c", 609);

    func_80093D18(gfxCtx);

    if (arg2 != 0) {
        gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(arg2));
    }

    if (arg3 != 0) {
        gSPSegment(POLY_OPA_DISP++, 0x0B, SEGMENTED_TO_VIRTUAL(arg3));
    }

    if (color1 != NULL) {
        //! @bug DemoEc_AllocColorDList is called twice in SEGMENTED_TO_VIRTUAL, allocating two display lists
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(DemoEc_AllocColorDList(gfxCtx, color1)));
    }

    if (color2 != NULL) {
        //! @bug DemoEc_AllocColorDList is called twice in SEGMENTED_TO_VIRTUAL, allocating two display lists
        //! @bug meant to pass color2 instead of color1?
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(DemoEc_AllocColorDList(gfxCtx, color1)));
    }

    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);
    POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       overrideLimbDraw, postLimbDraw, &pthis->actor, POLY_OPA_DISP);

    CLOSE_DISPS(gfxCtx, "../z_demo_ec.c", 646);
}

void DemoEc_UseDrawObject(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s32 drawObjBankIndex = pthis->drawObjBankIndex;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_demo_ec.c", 662);

    gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[drawObjBankIndex].vromStart.get());
    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[drawObjBankIndex].vromStart.get());
    if (!globalCtx) {}

    CLOSE_DISPS(gfxCtx, "../z_demo_ec.c", 670);
}

void DemoEc_UseAnimationObject(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 animObjBankIndex = pthis->animObjBankIndex;

    gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[animObjBankIndex].vromStart.get());
}

CsCmdActorAction* DemoEc_GetNpcAction(GlobalContext* globalCtx, s32 actionIndex) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[actionIndex];
    } else {
        return NULL;
    }
}

void DemoEc_SetNpcActionPosRot(DemoEc* pthis, GlobalContext* globalCtx, s32 actionIndex) {
    CsCmdActorAction* npcAction = DemoEc_GetNpcAction(globalCtx, actionIndex);

    if (npcAction != NULL) {
        pthis->actor.world.pos.x = npcAction->startPos.x;
        pthis->actor.world.pos.y = npcAction->startPos.y;
        pthis->actor.world.pos.z = npcAction->startPos.z;

        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = npcAction->rot.y;
    }
}

void DemoEc_InitIngo(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gIngoSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcIngoAnim, 0, 0.0f, false);
    func_8096D64C(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_INGO;
    pthis->drawConfig = EC_DRAW_INGO;
}

void DemoEc_UpdateIngo(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawIngo(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, gIngoEyeClosed2Tex, gIngoRedTex, 0, 0);
}

void DemoEc_InitTalon(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gTalonSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcTalonAnim, 0, 0.0f, false);
    func_8096D64C(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_TALON;
    pthis->drawConfig = EC_DRAW_TALON;
}

void DemoEc_UpdateTalon(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawTalon(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, gTalonEyeClosed2Tex, gTalonRedTex, NULL, NULL);
}

void DemoEc_InitWindmillMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gWindmillManSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcWindmillManAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_WINDMILL_MAN;
    pthis->drawConfig = EC_DRAW_WINDMILL_MAN;
}

void DemoEc_UpdateWindmillMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawWindmillMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, gWindmillManEyeClosedTex, gWindmillManMouthAngryTex, NULL, NULL);
}

void DemoEc_InitKokiriBoy(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gKm1Skel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcKokiriAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_KOKIRI_BOY;
    pthis->drawConfig = EC_DRAW_KOKIRI_BOY;
}

void DemoEc_InitDancingKokiriBoy(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gKm1Skel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcDancingKokiriAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_DANCING_KOKIRI_BOY;
    pthis->drawConfig = EC_DRAW_KOKIRI_BOY;
}

void DemoEc_UpdateKokiriBoy(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_UpdateDancingKokiriBoy(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateKokiriBoy(pthis, globalCtx);
}

void DemoEc_DrawKokiriBoy(DemoEc* pthis, GlobalContext* globalCtx) {

    DemoEc_DrawSkeletonCustomColor(pthis, globalCtx, NULL, NULL, color1_83, color2_83, NULL, NULL);
}

void DemoEc_InitKokiriGirl(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gKw1Skel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcKokiriAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_KOKIRI_GIRL;
    pthis->drawConfig = EC_DRAW_KOKIRI_GIRL;
}

void DemoEc_InitDancingKokiriGirl(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gKw1Skel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcDancingKokiriAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_DANCING_KOKIRI_GIRL;
    pthis->drawConfig = EC_DRAW_KOKIRI_GIRL;
}

void DemoEc_UpdateKokiriGirl(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_UpdateDancingKokiriGirl(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateKokiriGirl(pthis, globalCtx);
}

void DemoEc_DrawKokiriGirl(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_88[eyeTexIndex];

    DemoEc_DrawSkeletonCustomColor(pthis, globalCtx, (Gfx*)eyeTexture, NULL, color1_88, color2_88, NULL, NULL);
}
void DemoEc_InitOldMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_bji_Skel_0000F0);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcOldManAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_OLD_MAN;
    pthis->drawConfig = EC_DRAW_OLD_MAN;
}

void DemoEc_UpdateOldMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawOldMan(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_91[eyeTexIndex];

    DemoEc_DrawSkeletonCustomColor(pthis, globalCtx, (Gfx*)eyeTexture, NULL, color1_91, color2_91, NULL, NULL);
}

void DemoEc_InitBeardedMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_ahg_Skel_0000F0);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcOldManAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_BEARDED_MAN;
    pthis->drawConfig = EC_DRAW_BEARDED_MAN;
}

void DemoEc_UpdateBeardedMan(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawBeardedMan(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_94[eyeTexIndex];

    DemoEc_DrawSkeletonCustomColor(pthis, globalCtx, (Gfx*)eyeTexture, NULL, color1_94, color2_94, NULL, NULL);
}

void DemoEc_InitWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_bob_Skel_0000F0);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcOldManAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_WOMAN;
    pthis->drawConfig = EC_DRAW_WOMAN;
}

void DemoEc_UpdateWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_97[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitOldWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_bba_Skel_0000F0);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcOldManAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_OLD_WOMAN;
    pthis->drawConfig = EC_DRAW_OLD_WOMAN;
}

void DemoEc_UpdateOldWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawOldWoman(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, &object_bba_Tex_0004C8, NULL, NULL, NULL);
}

void DemoEc_InitBossCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_toryo_Skel_007150);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcCarpenterAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_BOSS_CARPENTER;
    pthis->drawConfig = EC_DRAW_BOSS_CARPENTER;
}

void DemoEc_UpdateBossCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawBossCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, NULL, NULL, NULL, NULL);
}

void DemoEc_InitCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_daiku_Skel_007958);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcCarpenterAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_CARPENTER;
    pthis->drawConfig = EC_DRAW_CARPENTER;
}

void DemoEc_UpdateCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

s32 DemoEc_CarpenterOverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                     void* thisx, Gfx** gfx) {
    DemoEc* pthis = (DemoEc*)thisx;

    if (limbIndex == 1) {
        gDPPipeSync((*gfx)++);
        switch (pthis->actor.params) {
            case 10:
                gDPSetEnvColor((*gfx)++, 170, 10, 70, 255);
                break;
            case 11:
                gDPSetEnvColor((*gfx)++, 170, 200, 255, 255);
                break;
            case 12:
                gDPSetEnvColor((*gfx)++, 0, 230, 70, 255);
                break;
            case 13:
                gDPSetEnvColor((*gfx)++, 200, 0, 150, 255);
                break;
        }
    }

    return false;
}

Gfx* DemoEc_GetCarpenterPostLimbDList(DemoEc* pthis) {
    switch (pthis->actor.params) {
        case 10:
            return object_daiku_DL_005BD0;
        case 11:
            return object_daiku_DL_005AC0;
        case 12:
            return object_daiku_DL_005990;
        case 13:
            return object_daiku_DL_005880;
        default:
            osSyncPrintf(VT_FGCOL(RED) "かつらが無い!!!!!!!!!!!!!!!!\n" VT_RST);
            return NULL;
    }
}

void DemoEc_CarpenterPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx,
                                  Gfx** gfx) {
    DemoEc* pthis = (DemoEc*)thisx;
    Gfx* postLimbDList;

    if (limbIndex == 15) {
        postLimbDList = DemoEc_GetCarpenterPostLimbDList(pthis);
        gSPDisplayList((*gfx)++, SEGMENTED_TO_VIRTUAL(postLimbDList));
    }
}

void DemoEc_DrawCarpenter(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, NULL, 0, DemoEc_CarpenterOverrideLimbDraw, DemoEc_CarpenterPostLimbDraw);
}

void DemoEc_InitGerudo(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gGerudoWhiteSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcGerudoAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_GERUDO;
    pthis->drawConfig = EC_DRAW_GERUDO;
}

void DemoEc_UpdateGerudo(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

Gfx* DemoEc_GetGerudoPostLimbDList(DemoEc* pthis) {
    switch (pthis->actor.params) {
        case 16:
            return gGerudoWhiteHairstyleBobDL;
        case 17:
            return gGerudoWhiteHairstyleStraightFringeDL;
        case 18:
            return gGerudoWhiteHairstyleSpikyDL;
        default:
            osSyncPrintf(VT_FGCOL(RED) "かつらが無い!!!!!!!!!!!!!!!!\n" VT_RST);
            return NULL;
    }
}

void DemoEc_GerudoPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx,
                               Gfx** gfx) {
    DemoEc* pthis = (DemoEc*)thisx;
    Gfx* postLimbDList;

    if (limbIndex == 15) {
        postLimbDList = DemoEc_GetGerudoPostLimbDList(pthis);
        gSPDisplayList((*gfx)++, SEGMENTED_TO_VIRTUAL(postLimbDList));
    }
}

void DemoEc_DrawGerudo(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_114[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, DemoEc_GerudoPostLimbDraw);
}

void DemoEc_InitDancingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gZoraSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcDancingZoraAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_DANCING_ZORA;
    pthis->drawConfig = EC_DRAW_DANCING_ZORA;
}

void DemoEc_UpdateDancingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawDancingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_117[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitKingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gKzSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcKingZoraAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_KING_ZORA;
    pthis->drawConfig = EC_DRAW_KING_ZORA;
    DemoEc_SetEyeTexIndex(pthis, 3);
}

void func_8096F1D4(DemoEc* pthis) {
    f32 currentFrame = pthis->skelAnime.curFrame;

    if (currentFrame <= 32.0f) {
        DemoEc_SetEyeTexIndex(pthis, 3);
    } else {
        DemoEc_UpdateEyes(pthis);
    }
}

void func_8096F224(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcAnim_006930, 2, -8.0f, false);
    pthis->updateMode = EC_UPDATE_17;
}

void func_8096F26C(DemoEc* pthis, s32 arg1) {
    if (arg1 != 0) {
        DemoEc_ChangeAnimation(pthis, &gDemoEcAnim_006220, 0, 0.0f, false);
        pthis->updateMode = EC_UPDATE_18;
    }
}

void func_8096F2B0(DemoEc* pthis, GlobalContext* globalCtx, s32 arg2) {
    CsCmdActorAction* npcAction;
    s32 sp18;

    npcAction = DemoEc_GetNpcAction(globalCtx, arg2);

    if (npcAction != NULL) {
        sp18 = npcAction->action;
        if ((sp18 != pthis->npcAction)) {
            if (pthis->npcAction) {}
            if (sp18 == 2) {
                func_8096F224(pthis, globalCtx);
            }
            pthis->npcAction = sp18;
        }
    }
}

void DemoEc_UpdateKingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_SetNpcActionPosRot(pthis, globalCtx, 6);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
    func_8096F2B0(pthis, globalCtx, 6);
}

void func_8096F378(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 animDone = DemoEc_UpdateSkelAnime(pthis);

    func_8096D594(pthis, globalCtx);
    func_8096F1D4(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
    func_8096F26C(pthis, animDone);
}

void func_8096F3D4(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawKingZora(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_126[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitMido(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gMidoSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcMidoAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_MIDO;
    pthis->drawConfig = EC_DRAW_MIDO;
    DemoEc_SetEyeTexIndex(pthis, 3);
}

void func_8096F4FC(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcAnim_008D1C, 2, -8.0f, false);
    pthis->updateMode = EC_UPDATE_20;
}

void func_8096F544(DemoEc* pthis, s32 changeAnim) {
    if (changeAnim) {
        DemoEc_ChangeAnimation(pthis, &gDemoEcAnim_009234, 0, 0.0f, false);
    }
}

void func_8096F578(DemoEc* pthis, GlobalContext* globalCtx, s32 arg2) {
    CsCmdActorAction* npcAction;
    s32 sp18;

    npcAction = DemoEc_GetNpcAction(globalCtx, arg2);
    if (npcAction != NULL) {
        sp18 = npcAction->action;
        if ((sp18 != pthis->npcAction)) {
            if (pthis->npcAction) {}
            if (sp18 == 2) {
                func_8096F4FC(pthis, globalCtx);
            }
            pthis->npcAction = sp18;
        }
    }
}

void DemoEc_UpdateMido(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_SetNpcActionPosRot(pthis, globalCtx, 7);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
    func_8096F578(pthis, globalCtx, 7);
}

void func_8096F640(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 animDone = DemoEc_UpdateSkelAnime(pthis);

    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
    func_8096F544(pthis, animDone);
}

void DemoEc_DrawMido(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_133[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitCucco(DemoEc* pthis, GlobalContext* globalCtx) {
    AnimationHeader* animation;

    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gCuccoSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);

    if (pthis->actor.params == 22) {
        animation = &gDemoEcJumpingCuccoAnim;
    } else if (pthis->actor.params == 23) {
        animation = &gDemoEcJumpingCucco2Anim;
    } else {
        animation = &gDemoEcWalkingCuccoAnim;
    }

    DemoEc_ChangeAnimation(pthis, animation, 0, 0.0f, false);
    func_8096D64C(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_CUCCO;
    pthis->drawConfig = EC_DRAW_CUCCO;
}

void DemoEc_UpdateCucco(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawCucco(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, NULL, NULL, NULL, NULL);
}

void DemoEc_InitCuccoLady(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gCuccoLadySkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcCuccoLadyAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_CUCCO_LADY;
    pthis->drawConfig = EC_DRAW_CUCCO_LADY;
}

void DemoEc_UpdateCuccoLady(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawCuccoLady(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_139[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitPotionShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_ds2_Skel_004258);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcPotionShopOwnerAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_POTION_SHOP_OWNER;
    pthis->drawConfig = EC_DRAW_POTION_SHOP_OWNER;
}

void DemoEc_UpdatePotionShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawPotionShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_142[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitMaskShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_os_Skel_004658);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcPotionShopOwnerAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_MASK_SHOP_OWNER;
    pthis->drawConfig = EC_DRAW_MASK_SHOP_OWNER;
}

void DemoEc_UpdateMaskShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawMaskShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_DrawSkeleton(pthis, globalCtx, gOsEyeClosedTex, NULL, NULL, NULL);
}

void DemoEc_InitFishingOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gFishingOwnerSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcPotionShopOwnerAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_FISHING_MAN;
    pthis->drawConfig = EC_DRAW_FISHING_MAN;
}

void DemoEc_UpdateFishingOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_FishingOwnerPostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx,
                                     Gfx** gfx) {
    DemoEc* pthis = (DemoEc*)thisx;

    if ((limbIndex == 8) && !(HIGH_SCORE(HS_FISHING) & 0x1000)) {
        gSPDisplayList((*gfx)++, SEGMENTED_TO_VIRTUAL(gFishingOwnerHatDL));
    }
}

void DemoEc_DrawFishingOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_149[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, DemoEc_FishingOwnerPostLimbDraw);
}

void DemoEc_InitBombchuShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &object_rs_Skel_004868);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gDemoEcPotionShopOwnerAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_BOMBCHU_SHOP_OWNER;
    pthis->drawConfig = EC_DRAW_BOMBCHU_SHOP_OWNER;
}

void DempEc_UpdateBombchuShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawBombchuShopOwner(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_152[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, NULL, NULL, NULL);
}

void DemoEc_InitGorons(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    AnimationHeader* animation;
    f32 goronScale;
    Vec3f* scale = &pthis->actor.scale;

    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gGoronSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);

    if (pthis->actor.params == 30) {
        animation = &gDemoEcGoronAnim;
        goronScale = 1.0f;
    } else if (pthis->actor.params == 31) {
        animation = &gDemoEcGoron2Anim;
        goronScale = 1.0f;
    } else if (pthis->actor.params == 32) {
        animation = &gDemoEcGoronAnim;
        goronScale = 15.0f;
    } else {
        goronScale = 5.0f;
        animation = &object_gm_Anim_0002B8;
    }

    DemoEc_ChangeAnimation(pthis, animation, 0, 0.0f, false);

    scale->x *= goronScale;
    scale->y *= goronScale;
    scale->z *= goronScale;

    func_8096D64C(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_GORON;
    pthis->drawConfig = EC_DRAW_GORON;
}

void DemoEc_UpdateGorons(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawGorons(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_155[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, gGoronCsMouthNeutralTex, NULL, NULL);
}

void DemoEc_InitMalon(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UseDrawObject(pthis, globalCtx);
    DemoEc_InitSkelAnime(pthis, globalCtx, &gMalonAdultSkel);
    DemoEc_UseAnimationObject(pthis, globalCtx);
    DemoEc_ChangeAnimation(pthis, &gMalonAdultSingAnim, 0, 0.0f, false);
    func_8096D5D4(pthis, globalCtx);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    pthis->updateMode = EC_UPDATE_MALON;
    pthis->drawConfig = EC_DRAW_MALON;
}

void DemoEc_UpdateMalon(DemoEc* pthis, GlobalContext* globalCtx) {
    DemoEc_UpdateSkelAnime(pthis);
    func_8096D594(pthis, globalCtx);
    DemoEc_UpdateEyes(pthis);
    DemoEc_UpdateBgFlags(pthis, globalCtx);
}

void DemoEc_DrawMalon(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTexture = eyeTextures_158[eyeTexIndex];

    DemoEc_DrawSkeleton(pthis, globalCtx, eyeTexture, gMalonAdultMouthHappyTex, NULL, NULL);
}

static DemoEcInitFunc sInitFuncs[] = {
    /*  0 */ DemoEc_InitIngo,
    /*  1 */ DemoEc_InitTalon,
    /*  2 */ DemoEc_InitWindmillMan,
    /*  3 */ DemoEc_InitKokiriBoy,
    /*  4 */ DemoEc_InitKokiriGirl,
    /*  5 */ DemoEc_InitOldMan,
    /*  6 */ DemoEc_InitBeardedMan,
    /*  7 */ DemoEc_InitWoman,
    /*  8 */ DemoEc_InitOldWoman,
    /*  9 */ DemoEc_InitBossCarpenter,
    /* 10 */ DemoEc_InitCarpenter,
    /* 11 */ DemoEc_InitCarpenter,
    /* 12 */ DemoEc_InitCarpenter,
    /* 13 */ DemoEc_InitCarpenter,
    /* 14 */ DemoEc_InitDancingKokiriBoy,
    /* 15 */ DemoEc_InitDancingKokiriGirl,
    /* 16 */ DemoEc_InitGerudo,
    /* 17 */ DemoEc_InitGerudo,
    /* 18 */ DemoEc_InitGerudo,
    /* 19 */ DemoEc_InitDancingZora,
    /* 20 */ DemoEc_InitKingZora,
    /* 21 */ DemoEc_InitMido,
    /* 22 */ DemoEc_InitCucco,
    /* 23 */ DemoEc_InitCucco,
    /* 24 */ DemoEc_InitCucco,
    /* 25 */ DemoEc_InitCuccoLady,
    /* 26 */ DemoEc_InitPotionShopOwner,
    /* 27 */ DemoEc_InitMaskShopOwner,
    /* 28 */ DemoEc_InitFishingOwner,
    /* 29 */ DemoEc_InitBombchuShopOwner,
    /* 30 */ DemoEc_InitGorons,
    /* 31 */ DemoEc_InitGorons,
    /* 32 */ DemoEc_InitGorons,
    /* 33 */ DemoEc_InitGorons,
    /* 34 */ DemoEc_InitMalon,
};

void DemoEc_InitNpc(DemoEc* pthis, GlobalContext* globalCtx) {
    s16 type = pthis->actor.params;

    if (sInitFuncs[type] == NULL) {
        // "Demo_Ec_main_init: Initialization process is wrong arg_data"
        osSyncPrintf(VT_FGCOL(RED) " Demo_Ec_main_init:初期化処理がおかしいarg_data = %d!\n" VT_RST, type);
        Actor_Kill(&pthis->actor);
        return;
    }

    sInitFuncs[type](pthis, globalCtx);
}

void DemoEc_InitCommon(DemoEc* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 primary;
    s32 type;
    s16 pad2;
    s16 sp28;
    s32 primaryBankIndex;
    s32 secondaryBankIndex;

    type = pthis->actor.params;
    primary = sDrawObjects[type];
    sp28 = sAnimationObjects[type];
    primaryBankIndex = Object_GetIndex(&globalCtx->objectCtx, primary);
    secondaryBankIndex = Object_GetIndex(&globalCtx->objectCtx, sp28);

    if ((secondaryBankIndex < 0) || (primaryBankIndex < 0)) {
        // "Demo_Ec_main_bank: Bank unreadable arg_data = %d!"
        osSyncPrintf(VT_FGCOL(RED) "Demo_Ec_main_bank:バンクを読めない arg_data = %d!\n" VT_RST, type);
        Actor_Kill(&pthis->actor);
        return;
    }

    if (Object_IsLoaded(&globalCtx->objectCtx, primaryBankIndex) &&
        Object_IsLoaded(&globalCtx->objectCtx, secondaryBankIndex)) {

        pthis->drawObjBankIndex = primaryBankIndex;
        pthis->animObjBankIndex = secondaryBankIndex;

        DemoEc_InitNpc(pthis, globalCtx);
    }
}

static DemoEcUpdateFunc sUpdateFuncs[] = {
    DemoEc_InitCommon,
    DemoEc_UpdateIngo,
    DemoEc_UpdateTalon,
    DemoEc_UpdateWindmillMan,
    DemoEc_UpdateKokiriBoy,
    DemoEc_UpdateKokiriGirl,
    DemoEc_UpdateOldMan,
    DemoEc_UpdateBeardedMan,
    DemoEc_UpdateWoman,
    DemoEc_UpdateOldWoman,
    DemoEc_UpdateBossCarpenter,
    DemoEc_UpdateCarpenter,
    DemoEc_UpdateDancingKokiriBoy,
    DemoEc_UpdateDancingKokiriGirl,
    DemoEc_UpdateGerudo,
    DemoEc_UpdateDancingZora,
    DemoEc_UpdateKingZora,
    func_8096F378,
    func_8096F3D4,
    DemoEc_UpdateMido,
    func_8096F640,
    DemoEc_UpdateCucco,
    DemoEc_UpdateCuccoLady,
    DemoEc_UpdatePotionShopOwner,
    DemoEc_UpdateMaskShopOwner,
    DemoEc_UpdateFishingOwner,
    DempEc_UpdateBombchuShopOwner,
    DemoEc_UpdateGorons,
    DemoEc_UpdateMalon,
};

void DemoEc_Update(Actor* thisx, GlobalContext* globalCtx) {
    DemoEc* pthis = (DemoEc*)thisx;
    s32 updateMode = pthis->updateMode;

    if ((updateMode < 0) || (updateMode >= ARRAY_COUNT(sUpdateFuncs)) || sUpdateFuncs[updateMode] == NULL) {
        // "The main mode is strange !!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        if (updateMode != EC_UPDATE_COMMON) {
            DemoEc_UseAnimationObject(pthis, globalCtx);
        }
        sUpdateFuncs[updateMode](pthis, globalCtx);
    }
}

void DemoEc_DrawCommon(DemoEc* pthis, GlobalContext* globalCtx) {
}

static DemoEcDrawFunc sDrawFuncs[] = {
    DemoEc_DrawCommon,          DemoEc_DrawIngo,
    DemoEc_DrawTalon,           DemoEc_DrawWindmillMan,
    DemoEc_DrawKokiriBoy,       DemoEc_DrawKokiriGirl,
    DemoEc_DrawOldMan,          DemoEc_DrawBeardedMan,
    DemoEc_DrawWoman,           DemoEc_DrawOldWoman,
    DemoEc_DrawBossCarpenter,   DemoEc_DrawCarpenter,
    DemoEc_DrawGerudo,          DemoEc_DrawDancingZora,
    DemoEc_DrawKingZora,        DemoEc_DrawMido,
    DemoEc_DrawCucco,           DemoEc_DrawCuccoLady,
    DemoEc_DrawPotionShopOwner, DemoEc_DrawMaskShopOwner,
    DemoEc_DrawFishingOwner,    DemoEc_DrawBombchuShopOwner,
    DemoEc_DrawGorons,          DemoEc_DrawMalon,
};

void DemoEc_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DemoEc* pthis = (DemoEc*)thisx;
    s32 drawConfig = pthis->drawConfig;

    if ((drawConfig < 0) || (drawConfig >= ARRAY_COUNT(sDrawFuncs)) || sDrawFuncs[drawConfig] == NULL) {
        // "The main mode is strange !!!!!!!!!!!!!!!!!!!!!!!!!"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        if (drawConfig != EC_DRAW_COMMON) {
            DemoEc_UseDrawObject(pthis, globalCtx);
        }
        sDrawFuncs[drawConfig](pthis, globalCtx);
    }
}

ActorInit Demo_Ec_InitVars = {
    ACTOR_DEMO_EC,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_EC,
    sizeof(DemoEc),
    (ActorFunc)DemoEc_Init,
    (ActorFunc)DemoEc_Destroy,
    (ActorFunc)DemoEc_Update,
    (ActorFunc)DemoEc_Draw,
    (ActorFunc)DemoEc_Reset,
};

void DemoEc_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Demo_Ec_InitVars = {
        ACTOR_DEMO_EC,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_EC,
        sizeof(DemoEc),
        (ActorFunc)DemoEc_Init,
        (ActorFunc)DemoEc_Destroy,
        (ActorFunc)DemoEc_Update,
        (ActorFunc)DemoEc_Draw,
        (ActorFunc)DemoEc_Reset,
    };

}

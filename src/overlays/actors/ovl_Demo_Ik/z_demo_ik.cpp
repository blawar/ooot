#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DEMO_IK_Z_DEMO_IK_C
#include "actor_common.h"
#include "z_demo_ik.h"
#include "vt.h"
#include "objects/object_ik/object_ik.h"
#include "def/audio_bank.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void DemoIk_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoIk_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DemoIk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoIk_Update(Actor* thisx, GlobalContext* globalCtx);
void DemoIk_Draw(Actor* thisx, GlobalContext* globalCtx);

void DemoIk_Type1Init(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type2Init(DemoIk* pthis, GlobalContext* globalCtx);

void DemoIk_Type1Action0(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type1Action1(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type1Action2(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type2Action0(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type2Action1(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type2Action2(DemoIk* pthis, GlobalContext* globalCtx);

void DemoIk_DrawNothing(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type1Draw(DemoIk* pthis, GlobalContext* globalCtx);
void DemoIk_Type2Draw(DemoIk* pthis, GlobalContext* globalCtx);

static Vec3f deadDbOffsets_40[] = {
    { -14.0f, 5.0f, 5.0f },  { -20.0f, 12.0f, 0.0f }, { -5.0f, 10.0f, -1.0f }, { -10.0f, 8.0f, 14.0f },
    { -3.0f, 10.0f, 7.0f },  { -10.0f, 11.0f, 0.0f }, { 9.0f, 10.0f, -8.0f },  { 4.0f, 10.0f, 3.0f },
    { -6.0f, 13.0f, -5.0f }, { 1.0f, 9.0f, 3.0f },    { -10.0f, 9.0f, 1.0f },
};


void DemoIk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void DemoIk_BgCheck(DemoIk* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 DemoIk_UpdateSkelAnime(DemoIk* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

CsCmdActorAction* DemoIk_GetCue(GlobalContext* globalCtx, s32 index) {
    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        return globalCtx->csCtx.npcActions[index];
    }
    return NULL;
}

s32 DemoIk_CheckCue(GlobalContext* globalCtx, u16 action, s32 index) {
    CsCmdActorAction* cue = DemoIk_GetCue(globalCtx, index);

    if ((cue != NULL) && (cue->action == action)) {
        return 1;
    }
    return 0;
}

void DemoIk_SetMove(DemoIk* pthis, GlobalContext* globalCtx) {
    pthis->skelAnime.moveFlags |= 1;
    AnimationContext_SetMoveActor(globalCtx, &pthis->actor, &pthis->skelAnime, 1.0f);
}

void DemoIk_EndMove(DemoIk* pthis) {
    pthis->skelAnime.moveFlags &= ~1;
}

f32 DemoIk_GetCurFrame(DemoIk* pthis) {
    return pthis->skelAnime.curFrame;
}

Gfx* DemoIk_SetColors(GraphicsContext* gfxCtx, u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB) {
    Gfx* head = (Gfx*)Graph_Alloc(gfxCtx, 3 * sizeof(Gfx));
    Gfx* entry = head;

    gDPSetPrimColor(entry++, 0x00, 0x00, primR, primG, primB, 255);
    gDPSetEnvColor(entry++, envR, envG, envB, 255);
    gSPEndDisplayList(entry++);
    return head;
}

s32 DemoIk_GetIndexFromParams(s32 params) {
    s32 ret;

    if (params == 0) {
        ret = 5;
    } else if (params == 1) {
        ret = 6;
    } else {
        ret = 7;
    }
    return ret;
}

void DemoIk_Type1PlaySound(DemoIk* pthis) {
    switch (pthis->actor.params) {
        case 0:
            if (Animation_OnFrame(&pthis->skelAnime, 5.0f)) {
                Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_LAND1_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);
            }
            break;
        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, 10.0f)) {
                Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_LAND3_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);
            }
            break;
        case 2:
            if (Animation_OnFrame(&pthis->skelAnime, 9.0f)) {
                Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_LAND2_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);
            }
            break;
    }
}

void DemoIk_SpawnDeadDb(DemoIk* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 index = DemoIk_GetIndexFromParams(pthis->actor.params);

    if (DemoIk_CheckCue(globalCtx, 5, index)) {
        Vec3f pos;
        Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
        s32 startIndex;
        s32 endIndex;

        if (index == 5) {
            startIndex = 0;
            endIndex = 4;
        } else if (index == 7) {
            startIndex = 4;
            endIndex = 8;
        } else {
            startIndex = 8;
            endIndex = 11;
        }
        for (i = startIndex; i < endIndex; i++) {
            pos.x = deadDbOffsets_40[i].x + pthis->actor.world.pos.x;
            pos.y = deadDbOffsets_40[i].y + pthis->actor.world.pos.y;
            pos.z = deadDbOffsets_40[i].z + pthis->actor.world.pos.z;
            EffectSsDeadDb_Spawn(globalCtx, &pos, &zeroVec, &zeroVec, 10, 7, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
        }
    }
}

void DemoIk_MoveToStartPos(DemoIk* pthis, GlobalContext* globalCtx, s32 index) {
    CsCmdActorAction* cue = DemoIk_GetCue(globalCtx, index);

    if (cue != NULL) {
        pthis->actor.world.pos.x = cue->startPos.x;
        pthis->actor.world.pos.y = cue->startPos.y;
        pthis->actor.world.pos.z = cue->startPos.z;
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = cue->rot.y;
    }
}

void DemoIk_Type1Init(DemoIk* pthis, GlobalContext* globalCtx) {
    s32 pad[3];
    SkeletonHeader* skeleton;
    AnimationHeader* animation;
    f32 phi_f0;

    switch (pthis->actor.params) {
        case 0:
            skeleton = &object_ik_Skel_000C90;
            animation = &object_ik_Anim_000C6C;
            phi_f0 = 30.0f;
            break;
        case 1:
            skeleton = &object_ik_Skel_000660;
            animation = &object_ik_Anim_000634;
            phi_f0 = 10.0f;
            break;
        default:
            skeleton = &object_ik_Skel_000380;
            animation = &object_ik_Anim_00035C;
            phi_f0 = 20.0f;
            // No break is required for matching
    }
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, phi_f0);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, skeleton, NULL, pthis->jointTable, pthis->morphTable, 2);
    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_ONCE, 0.0f);
}

void func_8098393C(DemoIk* pthis) {
    pthis->actionMode = 0;
    pthis->drawMode = 0;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_8098394C(DemoIk* pthis, GlobalContext* globalCtx) {
    DemoIk_EndMove(pthis);
    DemoIk_MoveToStartPos(pthis, globalCtx, DemoIk_GetIndexFromParams(pthis->actor.params));
    pthis->actionMode = 1;
    pthis->drawMode = 1;
    pthis->actor.shape.shadowAlpha = 255;
    pthis->skelAnime.curFrame = 0.0f;
}

void func_809839AC(DemoIk* pthis) {
    pthis->actionMode = 2;
    pthis->drawMode = 1;
    pthis->actor.shape.shadowAlpha = 255;
    pthis->skelAnime.curFrame = 0.0f;
}

void func_809839D0(DemoIk* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* cue = DemoIk_GetCue(globalCtx, DemoIk_GetIndexFromParams(pthis->actor.params));

    if (cue != NULL) {
        s32 nextCsAction = cue->action;
        s32 csAction = pthis->csAction;

        if (nextCsAction != csAction) {
            switch (nextCsAction) {
                case 1:
                    func_8098393C(pthis);
                    break;
                case 2:
                    func_8098394C(pthis, globalCtx);
                    break;
                case 3:
                    func_809839AC(pthis);
                    break;
                case 4:
                    Actor_Kill(&pthis->actor);
                    break;
                case 5:
                case 6:
                    break;
                default:
                    // "there is no such action"
                    osSyncPrintf("Demo_Ik_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->csAction = nextCsAction;
        }
    }
}

void DemoIk_Type1Action0(DemoIk* pthis, GlobalContext* globalCtx) {
    func_809839D0(pthis, globalCtx);
}

void DemoIk_Type1Action1(DemoIk* pthis, GlobalContext* globalCtx) {
    DemoIk_BgCheck(pthis, globalCtx);
    func_809839D0(pthis, globalCtx);
}

void DemoIk_Type1Action2(DemoIk* pthis, GlobalContext* globalCtx) {
    DemoIk_UpdateSkelAnime(pthis);
    DemoIk_Type1PlaySound(pthis);
    DemoIk_SetMove(pthis, globalCtx);
    DemoIk_BgCheck(pthis, globalCtx);
    DemoIk_SpawnDeadDb(pthis, globalCtx);
    func_809839D0(pthis, globalCtx);
}

void DemoIk_Type1PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    DemoIk* pthis = (DemoIk*)thisx;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_demo_ik_inArmer.c", 385);
    if (limbIndex == 1) {
        switch (pthis->actor.params) {
            case 0:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inArmer.c", 390),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016BE0);
                break;
            case 2:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inArmer.c", 396),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016F88);
                break;
        }
    }
    CLOSE_DISPS(gfxCtx, "../z_demo_ik_inArmer.c", 404);
}

void DemoIk_Type1Draw(DemoIk* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(gfxCtx, "../z_demo_ik_inArmer.c", 422);
    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, DemoIk_SetColors(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(POLY_OPA_DISP++, 0x09, DemoIk_SetColors(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(POLY_OPA_DISP++, 0x0A, DemoIk_SetColors(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, NULL, DemoIk_Type1PostLimbDraw, pthis);
    CLOSE_DISPS(gfxCtx, "../z_demo_ik_inArmer.c", 444);
}

void DemoIk_Type2Init(DemoIk* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    FlexSkeletonHeader* skeleton;
    AnimationHeader* animation;

    switch (pthis->actor.params) {
        case 3:
            skeleton = &object_ik_Skel_01EB40;
            animation = &object_ik_Anim_01EB14;
            break;
        case 4:
            skeleton = &object_ik_Skel_01EE60;
            animation = &object_ik_Anim_01EE34;
            break;
        case 5:
            skeleton = &object_ik_Skel_000F30;
            animation = &object_ik_Anim_000F0C;
            break;
        default:
            skeleton = &object_ik_Skel_000900;
            animation = &object_ik_Anim_0008DC;
    }

    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, skeleton, NULL, pthis->jointTable, pthis->morphTable, 2);
    Animation_Change(&pthis->skelAnime, animation, 1.0f, 0.0f, Animation_GetLastFrame(animation), ANIMMODE_ONCE, 0.0f);
    pthis->actionMode = 3;
    pthis->drawMode = 0;
}

void DemoIk_Type2PlaySoundOnFrame(DemoIk* pthis, f32 frame) {
    if (Animation_OnFrame(&pthis->skelAnime, frame)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_OFF_DEMO, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    }
}

void DemoIk_Type2PlaySound(DemoIk* pthis) {
    switch (pthis->actor.params) {
        case 3:
            DemoIk_Type2PlaySoundOnFrame(pthis, 33.0f);
            break;
        case 5:
            DemoIk_Type2PlaySoundOnFrame(pthis, 44.0f);
            break;
    }
}

void func_80983FDC(DemoIk* pthis) {
    pthis->actionMode = 3;
    pthis->drawMode = 0;
}

void func_80983FEC(DemoIk* pthis, GlobalContext* globalCtx) {
    DemoIk_MoveToStartPos(pthis, globalCtx, 4);
    pthis->actionMode = 4;
    pthis->drawMode = 2;
    pthis->skelAnime.curFrame = 0.0f;
}

void func_8098402C(DemoIk* pthis) {
    pthis->actionMode = 5;
    pthis->drawMode = 2;
    pthis->skelAnime.curFrame = 0.0f;
}

void func_80984048(DemoIk* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* cue = DemoIk_GetCue(globalCtx, 4);

    if (cue != NULL) {
        s32 nextCsAction = cue->action;
        s32 csAction = pthis->csAction;

        if (nextCsAction != csAction) {
            switch (nextCsAction) {
                case 1:
                    func_80983FDC(pthis);
                    break;
                case 5:
                    func_80983FEC(pthis, globalCtx);
                    break;
                case 6:
                    func_8098402C(pthis);
                    break;
                case 7:
                    Actor_Kill(&pthis->actor);
                    break;
                default:
                    // "there is no such action"
                    osSyncPrintf("Demo_Ik_inFace_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->csAction = nextCsAction;
        }
    }
}

void DemoIk_Type2Action0(DemoIk* pthis, GlobalContext* globalCtx) {
    func_80984048(pthis, globalCtx);
}

void DemoIk_Type2Action1(DemoIk* pthis, GlobalContext* globalCtx) {
    func_80984048(pthis, globalCtx);
}

void DemoIk_Type2Action2(DemoIk* pthis, GlobalContext* globalCtx) {
    DemoIk_UpdateSkelAnime(pthis);
    DemoIk_Type2PlaySound(pthis);
    func_80984048(pthis, globalCtx);
}

s32 DemoIk_Type2OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                 void* thisx) {
    DemoIk* pthis = (DemoIk*)thisx;

    if ((limbIndex == 1) && (DemoIk_GetCurFrame(pthis) < 30.0f)) {
        *dList = NULL;
    }
    return 0;
}

void DemoIk_Type2PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    DemoIk* pthis = (DemoIk*)thisx;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    f32 frame = DemoIk_GetCurFrame(pthis);

    OPEN_DISPS(gfxCtx, "../z_demo_ik_inFace.c", 268);
    if (limbIndex == 1 && (frame >= 30.0f)) {
        switch (pthis->actor.params) {
            case 3:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inFace.c", 274),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_017028);
                break;
            case 4:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inFace.c", 280),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_017170);
                break;
            case 5:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inFace.c", 286),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016BE0);
                break;
            default:
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_demo_ik_inFace.c", 292),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, object_ik_DL_016CD8);
                break;
        }
    }
    CLOSE_DISPS(gfxCtx, "../z_demo_ik_inFace.c", 300);
}

void DemoIk_Type2Draw(DemoIk* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(gfxCtx, "../z_demo_ik_inFace.c", 318);
    func_8002EBCC(&pthis->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, DemoIk_SetColors(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(POLY_OPA_DISP++, 0x09, DemoIk_SetColors(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(POLY_OPA_DISP++, 0x0A, DemoIk_SetColors(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                          DemoIk_Type2OverrideLimbDraw, DemoIk_Type2PostLimbDraw, pthis);
    CLOSE_DISPS(gfxCtx, "../z_demo_ik_inFace.c", 341);
}

static DemoIkActionFunc sActionFuncs[] = {
    DemoIk_Type1Action0, DemoIk_Type1Action1, DemoIk_Type1Action2,
    DemoIk_Type2Action0, DemoIk_Type2Action1, DemoIk_Type2Action2,
};

void DemoIk_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    DemoIk* pthis = (DemoIk*)thisx;

    if (pthis->actionMode < 0 || pthis->actionMode >= ARRAY_COUNT(sActionFuncs) ||
        sActionFuncs[pthis->actionMode] == NULL) {
        // "The main mode is strange"
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->actionMode](pthis, globalCtx);
}

void DemoIk_DrawNothing(DemoIk* pthis, GlobalContext* globalCtx) {
}

static DemoIkDrawFunc sDrawFuncs[] = {
    DemoIk_DrawNothing,
    DemoIk_Type1Draw,
    DemoIk_Type2Draw,
};

void DemoIk_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    DemoIk* pthis = (DemoIk*)thisx;

    if (pthis->drawMode < 0 || pthis->drawMode >= ARRAY_COUNT(sDrawFuncs) || sDrawFuncs[pthis->drawMode] == NULL) {
        // "The draw mode is strange"
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawMode](pthis, globalCtx);
}

ActorInit Demo_Ik_InitVars = {
    ACTOR_DEMO_IK,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_IK,
    sizeof(DemoIk),
    (ActorFunc)DemoIk_Init,
    (ActorFunc)DemoIk_Destroy,
    (ActorFunc)DemoIk_Update,
    (ActorFunc)DemoIk_Draw,
    (ActorFunc)DemoIk_Reset,
};

void DemoIk_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    DemoIk* pthis = (DemoIk*)thisx;

    if (pthis->actor.params == 0 || pthis->actor.params == 1 || pthis->actor.params == 2) {
        DemoIk_Type1Init(pthis, globalCtx);
    } else {
        DemoIk_Type2Init(pthis, globalCtx);
    }
}

void DemoIk_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Demo_Ik_InitVars = {
        ACTOR_DEMO_IK,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_IK,
        sizeof(DemoIk),
        (ActorFunc)DemoIk_Init,
        (ActorFunc)DemoIk_Destroy,
        (ActorFunc)DemoIk_Update,
        (ActorFunc)DemoIk_Draw,
        (ActorFunc)DemoIk_Reset,
    };

}

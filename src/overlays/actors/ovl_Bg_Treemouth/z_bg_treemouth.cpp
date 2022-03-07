#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_TREEMOUTH_Z_BG_TREEMOUTH_C
#include "actor_common.h"
#include "def/z_demo.h"

/*
 * File: z_bg_treemouth.c
 * Overlay: ovl_Bg_Treemouth
 * Description: Great Deku Tree's Mouth
 */

#include "z_bg_treemouth.h"
#include "objects/object_spot04_objects/object_spot04_objects.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "def/code_80043480.h"
#include "def/audio_bank.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgTreemouth_Init(Actor* thisx, GlobalContext* globalCtx);
void BgTreemouth_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BgTreemouth_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgTreemouth_Update(Actor* thisx, GlobalContext* globalCtx);
void BgTreemouth_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808BC65C(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BC6F8(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BC80C(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BC864(BgTreemouth* pthis, GlobalContext* globalCtx);
void BgTreemouth_DoNothing(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BC8B8(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BC9EC(BgTreemouth* pthis, GlobalContext* globalCtx);
void func_808BCAF0(BgTreemouth* pthis, GlobalContext* globalCtx);

extern CutsceneData D_808BCE20[];
extern CutsceneData D_808BD2A0[];
extern CutsceneData D_808BD520[];
extern CutsceneData D_808BD790[];

ActorInit Bg_Treemouth_InitVars = {
    ACTOR_BG_TREEMOUTH,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT04_OBJECTS,
    sizeof(BgTreemouth),
    (ActorFunc)BgTreemouth_Init,
    (ActorFunc)BgTreemouth_Destroy,
    (ActorFunc)BgTreemouth_Update,
    (ActorFunc)BgTreemouth_Draw,
    (ActorFunc)BgTreemouth_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_VEC3F(scale, 1, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 8000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_STOP),
};

// unused
static f32 D_808BD9C4[] = {
    -2746.0f, 545.0f, 4694.0f, -2654.0f, 146.0f, 4534.0f,
};

void BgTreemouth_SetupAction(BgTreemouth* pthis, BgTreemouthActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void BgTreemouth_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgTreemouth* pthis = (BgTreemouth*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gDekuTreeMouthCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
    Actor_SetFocus(thisx, 50.0f);

    if ((gSaveContext.sceneSetupIndex < 4) && !LINK_IS_ADULT) {
        BgTreemouth_SetupAction(pthis, func_808BC8B8);
    } else if (LINK_IS_ADULT || (gSaveContext.sceneSetupIndex == 7)) {
        pthis->unk_168 = 0.0f;
        BgTreemouth_SetupAction(pthis, BgTreemouth_DoNothing);
    } else {
        pthis->unk_168 = 1.0f;
        BgTreemouth_SetupAction(pthis, func_808BC6F8);
    }

    thisx->textId = 0x905;
}

void BgTreemouth_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgTreemouth* pthis = (BgTreemouth*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808BC65C(BgTreemouth* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if ((globalCtx->csCtx.state != CS_STATE_IDLE)) {
        npcAction = globalCtx->csCtx.npcActions[0];
        if (npcAction != NULL) {
            if (npcAction->action == 2) {
                BgTreemouth_SetupAction(pthis, func_808BC80C);
            } else if (npcAction->action == 3) {
                Audio_PlaySoundGeneral(NA_SE_EV_WOODDOOR_OPEN, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
                BgTreemouth_SetupAction(pthis, func_808BC6F8);
            }
        }
    }
}

void func_808BC6F8(BgTreemouth* pthis, GlobalContext* globalCtx) {
    Vec3f sp34;

    if (pthis->unk_168 < 1.0f) {
        pthis->unk_168 += 0.01f;
    } else {
        pthis->unk_168 = 1.0f;
    }

    if ((gSaveContext.sceneSetupIndex == 6) && (globalCtx->csCtx.frames >= 0x2BD) &&
        (globalCtx->state.frames % 8 == 0)) {
        sp34.x = (Rand_ZeroOne() * 1158.0f) + 3407.0f;
        sp34.y = 970.0f;
        sp34.z = (Rand_ZeroOne() * 2026.0f) + -2163.0f;
        EffectSsHahen_SpawnBurst(globalCtx, &sp34, 0.8f, 0, 50, 30, 1, HAHEN_OBJECT_DEFAULT, 10, NULL);
    }
}

void func_808BC80C(BgTreemouth* pthis, GlobalContext* globalCtx) {
    pthis->unk_168 += 0.05f;
    if (pthis->unk_168 >= 0.8f) {
        BgTreemouth_SetupAction(pthis, func_808BC864);
    }
}

void func_808BC864(BgTreemouth* pthis, GlobalContext* globalCtx) {
    pthis->unk_168 -= 0.03f;
    if (pthis->unk_168 <= 0.0f) {
        BgTreemouth_SetupAction(pthis, func_808BC65C);
    }
}

void func_808BC8B8(BgTreemouth* pthis, GlobalContext* globalCtx) {
    if ((!(Flags_GetEventChkInf(5))) || LINK_IS_ADULT) {
        if (!LINK_IS_ADULT) {
            if (Flags_GetEventChkInf(0xC)) {
                if (Actor_IsFacingAndNearPlayer(&pthis->dyna.actor, 1658.0f, 0x7530)) {
                    pthis->dyna.actor.flags |= ACTOR_FLAG_0;
                    if (pthis->dyna.actor.isTargeted) {
                        pthis->dyna.actor.flags &= ~ACTOR_FLAG_0;
                        globalCtx->csCtx.segment = D_808BD2A0;
                        gSaveContext.cutsceneTrigger = 1;
                        BgTreemouth_SetupAction(pthis, func_808BC9EC);
                    }
                }
            } else if (Actor_IsFacingAndNearPlayer(&pthis->dyna.actor, 1658.0f, 0x4E20)) {
                Flags_SetEventChkInf(0xC);
                globalCtx->csCtx.segment = D_808BCE20;
                gSaveContext.cutsceneTrigger = 1;
                BgTreemouth_SetupAction(pthis, func_808BC9EC);
            }
        }
    } else {
        pthis->unk_168 = 1.0f;
    }
}

void func_808BC9EC(BgTreemouth* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->csCtx.state == CS_STATE_UNSKIPPABLE_INIT) {
        if (Actor_IsFacingAndNearPlayer(&pthis->dyna.actor, 350.0f, 0x7530)) {
            player->actor.world.pos.x = 3827.0f;
            player->actor.world.pos.y = -161.0f;
            player->actor.world.pos.z = -1142.0f;
        }

        globalCtx->csCtx.frames = 0;
        globalCtx->csCtx.unk_18 = 0xFFFF;
        D_8015FCC0 = 0xFFFF;
        D_8015FCC2 = 0xFFFF;
        D_8015FCC4 = 0xFFFF;
        globalCtx->csCtx.unk_1A = 0;
        globalCtx->csCtx.unk_1B = 0;
        globalCtx->csCtx.state = CS_STATE_SKIPPABLE_EXEC;

        if (globalCtx->msgCtx.choiceIndex == 0) {
            globalCtx->csCtx.segment = D_808BD520;
            Flags_SetEventChkInf(5);
            BgTreemouth_SetupAction(pthis, func_808BCAF0);
        } else {
            globalCtx->csCtx.segment = D_808BD790;
            globalCtx->csCtx.frames = 0;
            BgTreemouth_SetupAction(pthis, func_808BC8B8);
        }
    }
}

void func_808BCAF0(BgTreemouth* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        npcAction = globalCtx->csCtx.npcActions[0];
        if (npcAction != NULL) {
            if (npcAction->action == 2) {
                BgTreemouth_SetupAction(pthis, func_808BC80C);
            } else if (npcAction->action == 3) {
                Audio_PlaySoundGeneral(NA_SE_EV_WOODDOOR_OPEN, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
                BgTreemouth_SetupAction(pthis, func_808BC6F8);
            }
        }
    }
}

void BgTreemouth_DoNothing(BgTreemouth* pthis, GlobalContext* globalCtx) {
}

void BgTreemouth_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgTreemouth* pthis = (BgTreemouth*)thisx;
    f32 unk_168;

    pthis->actionFunc(pthis, globalCtx);
    unk_168 = pthis->unk_168;
    thisx->world.pos.x = (unk_168 * -160.0f) + 4029.0f;
    thisx->world.pos.y = (unk_168 * -399.0f) + 136.0f;
    thisx->world.pos.z = (unk_168 * 92.0f) + -1255.0f;
}

void BgTreemouth_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    u16 alpha = 500;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_treemouth.c", 893);

    func_80093D18(globalCtx->state.gfxCtx);

    if ((gSaveContext.sceneSetupIndex < 4) || LINK_IS_ADULT) {
        if (gSaveContext.eventChkInf[0] & 0x80) {
            alpha = 2150;
        }
    } else { // neeeded to match
    }

    if (gSaveContext.sceneSetupIndex == 6) {
        alpha = (globalCtx->roomCtx.unk_74[0] + 0x1F4);
    }

    gDPSetEnvColor(POLY_OPA_DISP++, 128, 128, 128, alpha * 0.1f);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_treemouth.c", 932),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDekuTreeMouthDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_treemouth.c", 937);
}

void BgTreemouth_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Bg_Treemouth_InitVars = {
        ACTOR_BG_TREEMOUTH,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_SPOT04_OBJECTS,
        sizeof(BgTreemouth),
        (ActorFunc)BgTreemouth_Init,
        (ActorFunc)BgTreemouth_Destroy,
        (ActorFunc)BgTreemouth_Update,
        (ActorFunc)BgTreemouth_Draw,
        (ActorFunc)BgTreemouth_Reset,
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_RL_Z_EN_RL_C
#include "actor_common.h"
/*
 * File: z_en_rl.c
 * Overlay: En_Rl
 * Description: Rauru
 */

#include "z_en_rl.h"
#include "vt.h"
#include "objects/object_rl/object_rl.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void EnRl_Init(Actor* thisx, GlobalContext* globalCtx);
void EnRl_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnRl_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnRl_Update(Actor* thisx, GlobalContext* globalCtx);
void EnRl_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80AE7798(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE77B8(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE77F8(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7838(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7C64(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7C94(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7CE8(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7D40(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7FD0(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7FDC(EnRl* pthis, GlobalContext* globalCtx);
void func_80AE7D94(EnRl* pthis, GlobalContext* globalCtx);

static s32 D_80AE81AC_34 = 0;


static void* D_80AE81A0[] = { object_rl_Tex_003620, object_rl_Tex_003960, object_rl_Tex_003B60 };

void EnRl_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnRl* pthis = (EnRl*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
}

void func_80AE72D0(EnRl* pthis) {
    s32 pad[3];
    s16* timer = &pthis->timer;
    s16* eyeTextureIndex = &pthis->eyeTextureIndex;

    if (DECR(*timer) == 0) {
        *timer = Rand_S16Offset(60, 60);
    }

    *eyeTextureIndex = *timer;
    if (*eyeTextureIndex > 2) {
        *eyeTextureIndex = 0;
    }
}

void func_80AE7358(EnRl* pthis) {
    Animation_Change(&pthis->skelAnime, &object_rl_Anim_000A3C, 1.0f, 0.0f,
                     Animation_GetLastFrame(&object_rl_Anim_000A3C), ANIMMODE_LOOP, 0.0f);
    pthis->action = 4;
    pthis->drawConfig = 0;
    pthis->alpha = 0;
    pthis->lightBallSpawned = 0;
    pthis->actor.shape.shadowAlpha = 0;
    pthis->unk_19C = 0.0f;
}

void func_80AE73D8(EnRl* pthis, GlobalContext* globalCtx) {

    if (globalCtx->csCtx.state == CS_STATE_IDLE) {
        if (D_80AE81AC_34) {
            if (pthis->actor.params == 2) {
                func_80AE7358(pthis);
            }
            D_80AE81AC_34 = 0;
        }
    } else if (!D_80AE81AC_34) {
        D_80AE81AC_34 = 1;
    }
}

void func_80AE744C(EnRl* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 func_80AE7494(EnRl* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

s32 func_80AE74B4(EnRl* pthis, GlobalContext* globalCtx, u16 arg2, s32 arg3) {
    CsCmdActorAction* csCmdActorAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        csCmdActorAction = globalCtx->csCtx.npcActions[arg3];
        if (csCmdActorAction != NULL && csCmdActorAction->action == arg2) {
            return 1;
        }
    }
    return 0;
}

s32 func_80AE74FC(EnRl* pthis, GlobalContext* globalCtx, u16 arg2, s32 arg3) {
    CsCmdActorAction* csCmdActorAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        csCmdActorAction = globalCtx->csCtx.npcActions[arg3];
        if (csCmdActorAction != NULL && csCmdActorAction->action != arg2) {
            return 1;
        }
    }
    return 0;
}

void func_80AE7544(EnRl* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_rl_Skel_007B38, &object_rl_Anim_000A3C, NULL, NULL, 0);
}

void func_80AE7590(EnRl* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player;
    Vec3f pos;
    s16 sceneNum = globalCtx->sceneNum;

    if (gSaveContext.sceneSetupIndex == 4 && sceneNum == SCENE_KENJYANOMA && globalCtx->csCtx.state != CS_STATE_IDLE &&
        globalCtx->csCtx.npcActions[6] != NULL && globalCtx->csCtx.npcActions[6]->action == 2 &&
        !pthis->lightMedallionGiven) {
        player = GET_PLAYER(globalCtx);
        pos.x = player->actor.world.pos.x;
        pos.y = player->actor.world.pos.y + 80.0f;
        pos.z = player->actor.world.pos.z;
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_EFFECT, pos.x, pos.y, pos.z, 0, 0, 0, 0xE);
        Item_Give(globalCtx, ITEM_MEDALLION_LIGHT);
        pthis->lightMedallionGiven = 1;
    }
}

void func_80AE7668(EnRl* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->drawConfig = 1;
    pthis->action = 1;
    player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y + 0x8000;
}

void func_80AE7698(EnRl* pthis, GlobalContext* globalCtx) {
    CsCmdActorAction* csCmdActorAction;

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        csCmdActorAction = globalCtx->csCtx.npcActions[0];
        if (csCmdActorAction != NULL && csCmdActorAction->action == 3) {
            Animation_Change(&pthis->skelAnime, &object_rl_Anim_00040C, 1.0f, 0.0f,
                             Animation_GetLastFrame(&object_rl_Anim_00040C), ANIMMODE_ONCE, 0.0f);
            pthis->action = 2;
        }
    }
}

void func_80AE772C(EnRl* pthis, s32 arg1) {
    if (arg1) {
        Animation_Change(&pthis->skelAnime, &object_rl_Anim_000830, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_rl_Anim_000830), ANIMMODE_LOOP, 0.0f);
        pthis->action = 3;
    }
}

void func_80AE7798(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE7668(pthis, globalCtx);
}

void func_80AE77B8(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE744C(pthis, globalCtx);
    func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE7698(pthis, globalCtx);
}

void func_80AE77F8(EnRl* pthis, GlobalContext* globalCtx) {
    s32 temp;

    func_80AE744C(pthis, globalCtx);
    temp = func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE772C(pthis, temp);
}

void func_80AE7838(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE744C(pthis, globalCtx);
    func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE7590(pthis, globalCtx);
}

void func_80AE7878(EnRl* pthis, GlobalContext* globalCtx) {
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_rl_Skel_007B38, &object_rl_Anim_000A3C, NULL, NULL, 0);
    pthis->action = 4;
    pthis->actor.shape.shadowAlpha = 0;
}

void func_80AE78D4(EnRl* pthis, GlobalContext* globalCtx) {
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DEMO_6K, pthis->actor.world.pos.x,
                       kREG(18) + 22.0f + pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 5);
}

void func_80AE7954(EnRl* pthis, GlobalContext* globalCtx) {
    if (func_80AE74B4(pthis, globalCtx, 4, 0)) {
        pthis->action = 5;
        pthis->drawConfig = 2;
        pthis->alpha = 0;
        pthis->actor.shape.shadowAlpha = 0;
        pthis->unk_19C = 0.0f;
    }
}

void func_80AE79A4(EnRl* pthis, GlobalContext* globalCtx) {
    f32* unk_19C = &pthis->unk_19C;
    s32 alpha = 255;

    if (func_80AE74B4(pthis, globalCtx, 4, 0)) {
        *unk_19C += 1.0f;
        if (*unk_19C >= kREG(5) + 10.0f) {
            pthis->action = 7;
            pthis->drawConfig = 1;
            *unk_19C = kREG(5) + 10.0f;
            pthis->alpha = alpha;
            pthis->actor.shape.shadowAlpha = alpha;
            return;
        }
    } else {
        *unk_19C -= 1.0f;
        if (*unk_19C <= 0.0f) {
            pthis->action = 4;
            pthis->drawConfig = 0;
            *unk_19C = 0.0f;
            pthis->alpha = 0;
            pthis->actor.shape.shadowAlpha = 0;
            return;
        }
    }
    alpha = (*unk_19C / (kREG(5) + 10.0f)) * 255.0f;
    pthis->alpha = alpha;
    pthis->actor.shape.shadowAlpha = alpha;
}

void func_80AE7AF8(EnRl* pthis, GlobalContext* globalCtx) {
    if (func_80AE74B4(pthis, globalCtx, 3, 0)) {
        Animation_Change(&pthis->skelAnime, &object_rl_Anim_00040C, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_rl_Anim_00040C), ANIMMODE_ONCE, -8.0f);
        pthis->action = 6;
    } else if (func_80AE74FC(pthis, globalCtx, 4, 0)) {
        pthis->action = 5;
        pthis->drawConfig = 2;
        pthis->unk_19C = kREG(5) + 10.0f;
        pthis->alpha = 255;
        if (!pthis->lightBallSpawned) {
            func_80AE78D4(pthis, globalCtx);
            pthis->lightBallSpawned = 1;
        }
        pthis->actor.shape.shadowAlpha = 0xFF;
    }
}

void func_80AE7BF8(EnRl* pthis, s32 arg1) {
    if (arg1 != 0) {
        Animation_Change(&pthis->skelAnime, &object_rl_Anim_000830, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_rl_Anim_000830), ANIMMODE_LOOP, 0.0f);
        pthis->action = 7;
    }
}

void func_80AE7C64(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE7954(pthis, globalCtx);
    func_80AE73D8(pthis, globalCtx);
}

void func_80AE7C94(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE744C(pthis, globalCtx);
    func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE79A4(pthis, globalCtx);
    func_80AE73D8(pthis, globalCtx);
}

void func_80AE7CE8(EnRl* pthis, GlobalContext* globalCtx) {
    s32 temp;

    func_80AE744C(pthis, globalCtx);
    temp = func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE7BF8(pthis, temp);
    func_80AE73D8(pthis, globalCtx);
}

void func_80AE7D40(EnRl* pthis, GlobalContext* globalCtx) {
    func_80AE744C(pthis, globalCtx);
    func_80AE7494(pthis);
    func_80AE72D0(pthis);
    func_80AE7AF8(pthis, globalCtx);
    func_80AE73D8(pthis, globalCtx);
}

void func_80AE7D94(EnRl* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 temp = pthis->eyeTextureIndex;
    void* tex = D_80AE81A0[temp];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_rl_inKenjyanomaDemo02.c", 304);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(tex));
    gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(tex));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
    gSPSegment(POLY_XLU_DISP++, 0x0C, D_80116280);

    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       NULL, NULL, NULL, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_rl_inKenjyanomaDemo02.c", 331);
}

static EnRlActionFunc sActionFuncs[] = {
    func_80AE7798, func_80AE77B8, func_80AE77F8, func_80AE7838,
    func_80AE7C64, func_80AE7C94, func_80AE7CE8, func_80AE7D40,
};

void EnRl_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnRl* pthis = (EnRl*)thisx;

    if ((pthis->action < 0) || (pthis->action > 7) || (sActionFuncs[pthis->action] == NULL)) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->action](pthis, globalCtx);
}

void EnRl_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnRl* pthis = (EnRl*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 50.0f);
    if (pthis->actor.params == 2) {
        func_80AE7878(pthis, globalCtx);
    } else {
        func_80AE7544(pthis, globalCtx);
    }
}
void func_80AE7FD0(EnRl* pthis, GlobalContext* globalCtx) {
}

void func_80AE7FDC(EnRl* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 temp = pthis->eyeTextureIndex;
    void* tex = D_80AE81A0[temp];
    SkelAnime* skelAnime = &pthis->skelAnime;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_rl.c", 416);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(tex));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(tex));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0x0C, &D_80116280[2]);

    SkelAnime_DrawFlexOpa(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount, NULL, NULL,
                          &pthis->actor);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_rl.c", 437);
}

static EnRlDrawFunc sDrawFuncs[] = {
    func_80AE7FD0,
    func_80AE7FDC,
    func_80AE7D94,
};

void EnRl_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnRl* pthis = (EnRl*)thisx;

    if (pthis->drawConfig < 0 || pthis->drawConfig >= 3 || sDrawFuncs[pthis->drawConfig] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawConfig](pthis, globalCtx);
}

ActorInit En_Rl_InitVars = {
    ACTOR_EN_RL,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_RL,
    sizeof(EnRl),
    (ActorFunc)EnRl_Init,
    (ActorFunc)EnRl_Destroy,
    (ActorFunc)EnRl_Update,
    (ActorFunc)EnRl_Draw,
    (ActorFunc)EnRl_Reset,
};

void EnRl_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    D_80AE81AC_34 = 0;

    En_Rl_InitVars = {
        ACTOR_EN_RL,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_RL,
        sizeof(EnRl),
        (ActorFunc)EnRl_Init,
        (ActorFunc)EnRl_Destroy,
        (ActorFunc)EnRl_Update,
        (ActorFunc)EnRl_Draw,
        (ActorFunc)EnRl_Reset,
    };

}

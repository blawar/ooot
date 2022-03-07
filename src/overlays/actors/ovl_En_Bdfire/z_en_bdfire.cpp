#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BDFIRE_Z_EN_BDFIRE_C
#include "actor_common.h"
/*
 * File: z_en_bdfire.c
 * Overlay: ovl_En_Bdfire
 * Description: King Dodongo's Fire Breath
 */

#include "z_en_bdfire.h"
#include "objects/object_kingdodongo/object_kingdodongo.h"
#include "def/audio_bank.h"
#include "def/random.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnBdfire_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBdfire_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBdfire_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBdfire_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBdfire_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBdfire_DrawFire(EnBdfire* pthis, GlobalContext* globalCtx);
void func_809BC2A4(EnBdfire* pthis, GlobalContext* globalCtx);
void func_809BC598(EnBdfire* pthis, GlobalContext* globalCtx);

static void* D_809BCB10_30[] = {
    object_kingdodongo_Tex_0264E0, object_kingdodongo_Tex_0274E0, object_kingdodongo_Tex_0284E0,
    object_kingdodongo_Tex_0294E0, object_kingdodongo_Tex_02A4E0, object_kingdodongo_Tex_02B4E0,
    object_kingdodongo_Tex_02C4E0, object_kingdodongo_Tex_02D4E0,
};


ActorInit En_Bdfire_InitVars = {
    0,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_KINGDODONGO,
    sizeof(EnBdfire),
    (ActorFunc)EnBdfire_Init,
    (ActorFunc)EnBdfire_Destroy,
    (ActorFunc)EnBdfire_Update,
    (ActorFunc)EnBdfire_Draw,
    (ActorFunc)EnBdfire_Reset,
};

void EnBdfire_SetupAction(EnBdfire* pthis, EnBdfireActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnbdFire_SetupDraw(EnBdfire* pthis, EnBdfireDrawFunc drawFunc) {
    pthis->drawFunc = drawFunc;
}

void EnBdfire_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnBdfire* pthis = (EnBdfire*)thisx;
    s32 pad;

    Actor_SetScale(&pthis->actor, 0.6f);
    EnbdFire_SetupDraw(pthis, EnBdfire_DrawFire);
    if (pthis->actor.params < 0) {
        EnBdfire_SetupAction(pthis, func_809BC2A4);
        pthis->actor.scale.x = 2.8f;
        pthis->unk_154 = 90;
        Lights_PointNoGlowSetInfo(&pthis->lightInfoNoGlow, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                  pthis->actor.world.pos.z, 255, 255, 255, 300);
        pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfoNoGlow);
    } else {
        EnBdfire_SetupAction(pthis, func_809BC598);
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
        pthis->actor.speedXZ = 30.0f;
        pthis->unk_154 = (25 - (s32)(pthis->actor.params * 0.8f));
        if (pthis->unk_154 < 0) {
            pthis->unk_154 = 0;
        }
        pthis->unk_188 = 4.2000003f - (pthis->actor.params * 0.25f * 0.6f);

        if (pthis->unk_188 < 0.90000004f) {
            pthis->unk_188 = 0.90000004f;
        }
        pthis->unk_18C = 255.0f - (pthis->actor.params * 10.0f);
        if (pthis->unk_18C < 20.0f) {
            pthis->unk_18C = 20.0f;
        }
        pthis->unk_156 = (Rand_ZeroOne() * 8.0f);
    }
}

void EnBdfire_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBdfire* pthis = (EnBdfire*)thisx;

    if (pthis->actor.params < 0) {
        LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
    }
}

void func_809BC2A4(EnBdfire* pthis, GlobalContext* globalCtx) {
    BossDodongo* kingDodongo;
    s32 temp;

    kingDodongo = (BossDodongo*)pthis->actor.parent;
    pthis->actor.world.pos.x = kingDodongo->firePos.x;
    pthis->actor.world.pos.y = kingDodongo->firePos.y;
    pthis->actor.world.pos.z = kingDodongo->firePos.z;
    if (kingDodongo->unk_1E2 == 0) {
        Math_SmoothStepToF(&pthis->actor.scale.x, 0.0f, 1.0f, 0.6f, 0.0f);
        if (Math_SmoothStepToF(&pthis->unk_18C, 0.0f, 1.0f, 20.0f, 0.0f) == 0.0f) {
            Actor_Kill(&pthis->actor);
        }
    } else {
        if (pthis->unk_154 < 70) {
            Math_SmoothStepToF(&pthis->unk_18C, 128.0f, 0.1f, 1.5f, 0.0f);
            Math_SmoothStepToF(&pthis->unk_190, 255.0f, 1.0f, 3.8249998f, 0.0f);
            Math_SmoothStepToF(&pthis->unk_194, 100.0f, 1.0f, 1.5f, 0.0f);
        }
        if (pthis->unk_154 == 0) {
            temp = 0;
        } else {
            pthis->unk_154--;
            temp = pthis->unk_154;
        }
        if (temp == 0) {
            Math_SmoothStepToF(&pthis->actor.scale.x, 0.0f, 1.0f, 0.3f, 0.0f);
            Math_SmoothStepToF(&pthis->unk_190, 0.0f, 1.0f, 25.5f, 0.0f);
            Math_SmoothStepToF(&pthis->unk_194, 0.0f, 1.0f, 10.0f, 0.0f);
            if (Math_SmoothStepToF(&pthis->unk_18C, 0.0f, 1.0f, 10.0f, 0.0f) == 0.0f) {
                Actor_Kill(&pthis->actor);
            }
        }
        Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
        Lights_PointSetColorAndRadius(&pthis->lightInfoNoGlow, pthis->unk_190, pthis->unk_194, 0, 300);
    }
}

void func_809BC598(EnBdfire* pthis, GlobalContext* globalCtx) {
    s16 phi_v1_2;
    Player* player = GET_PLAYER(globalCtx);
    f32 distToBurn;
    BossDodongo* bossDodongo;
    s16 i;
    s16 phi_v1;
    s32 temp;

    bossDodongo = ((BossDodongo*)pthis->actor.parent);
    pthis->unk_158 = bossDodongo->unk_1A2;
    phi_v1_2 = 0;
    if (pthis->actor.params == 0) {
        Audio_PlaySoundGeneral(NA_SE_EN_DODO_K_FIRE - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    }
    Math_SmoothStepToF(&pthis->actor.scale.x, pthis->unk_188, 0.3f, 0.5f, 0.0f);
    Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
    if (pthis->actor.world.pos.x < -1390.0f) {
        if (pthis->actor.velocity.x < -10.0f) {
            pthis->actor.world.pos.x = -1390.0f;
            phi_v1_2 = 1;
        }
    }
    if ((pthis->actor.world.pos.x > -390.0f) && (pthis->actor.velocity.x > 10.0f)) {
        pthis->actor.world.pos.x = -390.0f;
        phi_v1_2 = 1;
    }
    if ((pthis->actor.world.pos.z > -2804.0f) && (pthis->actor.velocity.z > 10.0f)) {
        pthis->actor.world.pos.z = -2804.0f;
        phi_v1_2 = 1;
    }
    if ((pthis->actor.world.pos.z < -3804.0f) && (pthis->actor.velocity.z < -10.0f)) {
        pthis->actor.world.pos.z = -3804.0f;
        phi_v1_2 = 1;
    }
    if (phi_v1_2 != 0) {
        if (pthis->unk_158 == 0) {
            pthis->actor.world.rot.y += 0x4000;
        } else {
            pthis->actor.world.rot.y -= 0x4000;
        }
    }
    if (pthis->unk_154 == 0) {
        temp = 0;
    } else {
        pthis->unk_154--;
        temp = pthis->unk_154;
    }
    if (temp == 0) {
        Math_SmoothStepToF(&pthis->unk_18C, 0.0f, 1.0f, 10.0f, 0.0f);
        if (pthis->unk_18C < 10.0f) {
            Actor_Kill(&pthis->actor);
            return;
        }
    } else if (!player->isBurning) {
        distToBurn = (pthis->actor.scale.x * 130.0f) / 4.2000003f;
        if (pthis->actor.xyzDistToPlayerSq < SQ(distToBurn)) {
            for (i = 0; i < 18; i++) {
                player->flameTimers[i] = Rand_S16Offset(0, 200);
            }
            player->isBurning = true;
            func_8002F6D4(globalCtx, &pthis->actor, 20.0f, pthis->actor.world.rot.y, 0.0f, 8);
            osSyncPrintf("POWER\n");
        }
    }
}

void EnBdfire_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBdfire* pthis = (EnBdfire*)thisx;

    pthis->unk_156++;
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
}

void EnBdfire_DrawFire(EnBdfire* pthis, GlobalContext* globalCtx) {
    s16 temp;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_bdfire.c", 612);
    temp = pthis->unk_156 & 7;
    func_800D1FD4(&globalCtx->billboardMtxF);
    func_80094BC4(globalCtx->state.gfxCtx);
    POLY_XLU_DISP = func_80094968(POLY_XLU_DISP);
    gDPSetCombineLERP(POLY_XLU_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0,
                      ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0,
                      ENVIRONMENT);
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 100, (s8)pthis->unk_18C);
    gDPSetEnvColor(POLY_XLU_DISP++, 200, 0, 0, 0);
    gSPSegment(POLY_XLU_DISP++, 8, SEGMENTED_TO_VIRTUAL(D_809BCB10_30[temp]));
    Matrix_Translate(0.0f, 11.0f, 0.0f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_bdfire.c", 647),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, object_kingdodongo_DL_01D950);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_bdfire.c", 651);
}

void EnBdfire_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBdfire* pthis = (EnBdfire*)thisx;

    pthis->drawFunc(pthis, globalCtx);
}

void EnBdfire_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Bdfire_InitVars = {
        0,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_KINGDODONGO,
        sizeof(EnBdfire),
        (ActorFunc)EnBdfire_Init,
        (ActorFunc)EnBdfire_Destroy,
        (ActorFunc)EnBdfire_Update,
        (ActorFunc)EnBdfire_Draw,
        (ActorFunc)EnBdfire_Reset,
    };

}

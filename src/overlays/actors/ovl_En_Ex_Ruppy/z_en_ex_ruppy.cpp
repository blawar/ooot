#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_EX_RUPPY_Z_EN_EX_RUPPY_C
#include "actor_common.h"
#include "z_en_ex_ruppy.h"
#include "vt.h"
#include "../ovl_En_Diving_Game/z_en_diving_game.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"

#define FLAGS ACTOR_FLAG_4

void EnExRuppy_Init(Actor* thisx, GlobalContext* globalCtx);
void EnExRuppy_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnExRuppy_Update(Actor* thisx, GlobalContext* globalCtx);
void EnExRuppy_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnExRuppy_DropIntoWater(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_WaitToBlowUp(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_WaitAsCollectible(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_GalleryTarget(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_EnterWater(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_Sink(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_WaitInGame(EnExRuppy* pthis, GlobalContext* globalCtx);
void EnExRuppy_Kill(EnExRuppy* pthis, GlobalContext* globalCtx);

static s16 sEnExRuppyCollectibleTypes[] = {
    ITEM00_RUPEE_GREEN, ITEM00_RUPEE_BLUE, ITEM00_RUPEE_RED, ITEM00_RUPEE_ORANGE, ITEM00_RUPEE_PURPLE,
};

// Unused, as the function sets these directly
static s16 sRupeeValues[] = {
    1, 5, 20, 500, 50,
};

ActorInit En_Ex_Ruppy_InitVars = {
    ACTOR_EN_EX_RUPPY,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnExRuppy),
    (ActorFunc)EnExRuppy_Init,
    (ActorFunc)EnExRuppy_Destroy,
    (ActorFunc)EnExRuppy_Update,
    (ActorFunc)EnExRuppy_Draw,
};

void EnExRuppy_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnExRuppy* pthis = (EnExRuppy*)thisx;
    EnDivingGame* divingGame;
    f32 temp1;
    f32 temp2;
    s16 temp3;

    pthis->type = pthis->actor.params;
    // "Index"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ インデックス ☆☆☆☆☆ %x\n" VT_RST, pthis->type);
    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);

    switch (pthis->type) {
        case 0:
            pthis->unk_160 = 0.01f;
            Actor_SetScale(&pthis->actor, pthis->unk_160);
            pthis->actor.room = -1;
            pthis->actor.gravity = 0.0f;

            // If you haven't won the diving game before, you will always get 5 rupees
            if (!(gSaveContext.eventChkInf[3] & 0x100)) {
                pthis->rupeeValue = 5;
                pthis->colorIdx = 1;
            } else {
                temp1 = 200.99f;
                if (pthis->actor.parent != NULL) {
                    divingGame = (EnDivingGame*)pthis->actor.parent;
                    if (divingGame->actor.update != NULL) {
                        temp2 = divingGame->extraWinCount * 10.0f;
                        temp1 += temp2;
                    }
                }

                temp3 = Rand_ZeroFloat(temp1);
                if ((temp3 >= 0) && (temp3 < 40)) {
                    pthis->rupeeValue = 1;
                    pthis->colorIdx = 0;
                } else if ((temp3 >= 40) && (temp3 < 170)) {
                    pthis->rupeeValue = 5;
                    pthis->colorIdx = 1;
                } else if ((temp3 >= 170) && (temp3 < 190)) {
                    pthis->rupeeValue = 20;
                    pthis->colorIdx = 2;
                } else if ((temp3 >= 190) && (temp3 < 200)) {
                    pthis->rupeeValue = 50;
                    pthis->colorIdx = 4;
                } else {
                    pthis->unk_160 = 0.02f;
                    Actor_SetScale(&pthis->actor, pthis->unk_160);
                    pthis->rupeeValue = 500;
                    pthis->colorIdx = 3;
                    if (pthis->actor.parent != NULL) {
                        divingGame = (EnDivingGame*)pthis->actor.parent;
                        if (divingGame->actor.update != NULL) {
                            divingGame->extraWinCount = 0;
                        }
                    }
                }
            }

            pthis->actor.shape.shadowScale = 7.0f;
            pthis->actor.shape.yOffset = 700.0f;
            pthis->unk_15A = pthis->actor.world.rot.z;
            pthis->actor.world.rot.z = 0;
            pthis->timer = 30;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actionFunc = EnExRuppy_DropIntoWater;
            break;

        case 1:
        case 2: // Giant pink ruppe that explodes when you touch it
            if (pthis->type == 1) {
                Actor_SetScale(&pthis->actor, 0.1f);
                pthis->colorIdx = 4;
            } else {
                Actor_SetScale(thisx, 0.02f);
                pthis->colorIdx = (s16)Rand_ZeroFloat(3.99f) + 1;
            }
            pthis->actor.gravity = -3.0f;
            // "Wow Coin"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ わーなーコイン ☆☆☆☆☆ \n" VT_RST);
            pthis->actor.shape.shadowScale = 6.0f;
            pthis->actor.shape.yOffset = 700.0f;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actionFunc = EnExRuppy_WaitToBlowUp;
            break;

        case 3: // Spawned by the guard in Hyrule courtyard
            Actor_SetScale(&pthis->actor, 0.02f);
            pthis->colorIdx = 0;
            switch ((s16)Rand_ZeroFloat(30.99f)) {
                case 0:
                    pthis->colorIdx = 2;
                    break;
                case 10:
                case 20:
                case 30:
                    pthis->colorIdx = 1;
                    break;
            }
            pthis->actor.gravity = -3.0f;
            // "Normal rupee"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ノーマルルピー ☆☆☆☆☆ \n" VT_RST);
            pthis->actor.shape.shadowScale = 6.0f;
            pthis->actor.shape.yOffset = 700.0f;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            pthis->actionFunc = EnExRuppy_WaitAsCollectible;
            break;

        case 4: // Progress markers in the shooting gallery
            pthis->actor.gravity = -3.0f;
            pthis->actor.flags &= ~ACTOR_FLAG_0;
            Actor_SetScale(&pthis->actor, 0.01f);
            pthis->actor.shape.shadowScale = 6.0f;
            pthis->actor.shape.yOffset = -700.0f;
            pthis->actionFunc = EnExRuppy_GalleryTarget;
            break;
    }
}

void EnExRuppy_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnExRuppy_SpawnSparkles(EnExRuppy* pthis, GlobalContext* globalCtx, s16 numSparkles, s32 movementType) {
    static Vec3f velocities[] = { { 0.0f, 0.1f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
    static Vec3f accelerations[] = { { 0.0f, 0.01f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    s32 i;
    s16 scale;
    s16 life;

    if (numSparkles < 1) {
        numSparkles = 1;
    }

    primColor.r = 255;
    primColor.g = 255;
    primColor.b = 0;
    envColor.r = 255;
    envColor.g = 255;
    envColor.b = 255;
    velocity = velocities[movementType];
    accel = accelerations[movementType];
    scale = 3000;
    life = 16;

    for (i = 0; i < numSparkles; i++) {
        if (movementType == 1) {
            accel.x = Rand_CenteredFloat(20.0f);
            accel.z = Rand_CenteredFloat(20.0f);
            scale = 5000;
            life = 20;
        }
        pos.x = (Rand_ZeroOne() - 0.5f) * 10.0f + pthis->actor.world.pos.x;
        pos.y = (Rand_ZeroOne() - 0.5f) * 10.0f + (pthis->actor.world.pos.y + pthis->unk_160 * 600.0f);
        pos.z = (Rand_ZeroOne() - 0.5f) * 10.0f + pthis->actor.world.pos.z;
        EffectSsKiraKira_SpawnDispersed(globalCtx, &pos, &velocity, &accel, &primColor, &envColor, scale, life);
    }
}

void EnExRuppy_DropIntoWater(EnExRuppy* pthis, GlobalContext* globalCtx) {
    EnDivingGame* divingGame;

    pthis->actor.shape.rot.y += 0x7A8;
    Math_ApproachF(&pthis->actor.gravity, -2.0f, 0.3f, 1.0f);
    EnExRuppy_SpawnSparkles(pthis, globalCtx, 2, 0);
    func_80078884(NA_SE_EV_RAINBOW_SHOWER - SFX_FLAG);
    divingGame = (EnDivingGame*)pthis->actor.parent;
    if ((divingGame != NULL) && (divingGame->actor.update != NULL) &&
        ((divingGame->unk_296 == 0) || (pthis->actor.bgCheckFlags & 0x20) || (pthis->timer == 0))) {
        pthis->invisible = true;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.velocity.x = pthis->actor.velocity.y = pthis->actor.velocity.z = 0.0f;
        pthis->actor.gravity = 0.0f;
        func_80078914(&pthis->actor.projectedPos, NA_SE_EV_BOMB_DROP_WATER);
        pthis->actionFunc = EnExRuppy_EnterWater;
    }
}

void EnExRuppy_EnterWater(EnExRuppy* pthis, GlobalContext* globalCtx) {
    EnDivingGame* divingGame = (EnDivingGame*)pthis->actor.parent;
    f32 temp_f2;

    if ((divingGame != NULL) && (divingGame->actor.update != NULL) && (divingGame->unk_2A2 == 2)) {
        pthis->invisible = false;
        pthis->actor.world.pos.x = ((Rand_ZeroOne() - 0.5f) * 300.0f) + -260.0f;
        pthis->actor.world.pos.y = ((Rand_ZeroOne() - 0.5f) * 200.0f) + 370.0f;
        temp_f2 = pthis->unk_15A * -50.0f;
        if (!(gSaveContext.eventChkInf[3] & 0x100)) {
            temp_f2 += -500.0f;
            pthis->actor.world.pos.z = ((Rand_ZeroOne() - 0.5f) * 80.0f) + temp_f2;
        } else {
            temp_f2 += -300.0f;
            pthis->actor.world.pos.z = ((Rand_ZeroOne() - 0.5f) * 60.0f) + temp_f2;
        }
        pthis->actionFunc = EnExRuppy_Sink;
        pthis->actor.gravity = -1.0f;
    }
}

void EnExRuppy_Sink(EnExRuppy* pthis, GlobalContext* globalCtx) {
    EnDivingGame* divingGame;
    Vec3f pos;
    s32 pad;

    if ((pthis->actor.bgCheckFlags & 0x20) && (pthis->actor.yDistToWater > 15.0f)) {
        pos = pthis->actor.world.pos;
        pos.y += pthis->actor.yDistToWater;
        pthis->actor.velocity.y = -1.0f;
        pthis->actor.gravity = -0.2f;
        EffectSsGSplash_Spawn(globalCtx, &pos, 0, 0, 0, 800);
        func_80078914(&pthis->actor.projectedPos, NA_SE_EV_BOMB_DROP_WATER);
        pthis->actionFunc = EnExRuppy_WaitInGame;
    }
    divingGame = (EnDivingGame*)pthis->actor.parent;
    if ((divingGame != NULL) && (divingGame->actor.update != NULL) && (divingGame->phase == ENDIVINGGAME_PHASE_ENDED)) {
        pthis->timer = 20;
        pthis->actionFunc = EnExRuppy_Kill;
    }
}

void EnExRuppy_WaitInGame(EnExRuppy* pthis, GlobalContext* globalCtx) {
    EnDivingGame* divingGame;
    Vec3f D_80A0B388 = { 0.0f, 0.1f, 0.0f };
    Vec3f D_80A0B394 = { 0.0f, 0.0f, 0.0f };
    f32 localConst = 30.0f;

    if (pthis->timer == 0) {
        pthis->timer = 10;
        EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 0.0f, 5.0f, 5.0f, Rand_ZeroFloat(0.03f) + 0.07f);
    }
    if (pthis->actor.parent != NULL) {
        divingGame = (EnDivingGame*)pthis->actor.parent;
        if (divingGame->actor.update != NULL) {
            if (divingGame->phase == ENDIVINGGAME_PHASE_ENDED) {
                pthis->timer = 20;
                pthis->actionFunc = EnExRuppy_Kill;
                if (1) {}
            } else if (pthis->actor.xyzDistToPlayerSq < SQ(localConst)) {
                Rupees_ChangeBy(pthis->rupeeValue);
                func_80078884(NA_SE_SY_GET_RUPY);
                divingGame->grabbedRupeesCounter++;
                Actor_Kill(&pthis->actor);
            }
        } else {
            Actor_Kill(&pthis->actor);
        }
    }
}

void EnExRuppy_Kill(EnExRuppy* pthis, GlobalContext* globalCtx) {
    pthis->invisible += 1;
    pthis->invisible &= 1; // Net effect is pthis->invisible = !pthis->invisible;
    if (pthis->timer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x14C */ char unk_14C[0x11A];
    /* 0x226 */ s16 unk_226;
} EnExRuppyParentActor; // Unclear what actor was intended to spawn pthis.

void EnExRuppy_WaitToBlowUp(EnExRuppy* pthis, GlobalContext* globalCtx) {
    EnExRuppyParentActor* parent;
    Vec3f accel = { 0.0f, 0.1f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    f32 distToBlowUp = 50.0f;
    s16 explosionScale;
    s16 explosionScaleStep;

    if (pthis->type == 2) {
        distToBlowUp = 30.0f;
    }
    if (pthis->actor.xyzDistToPlayerSq < SQ(distToBlowUp)) {
        parent = (EnExRuppyParentActor*)pthis->actor.parent;
        if (parent != NULL) {
            if (parent->actor.update != NULL) {
                parent->unk_226 = 1;
            }
        } else {
            // "That idiot! error"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ そ、そんなばかな！エラー！！！！！ ☆☆☆☆☆ \n" VT_RST);
        }
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ バカめ！ ☆☆☆☆☆ \n" VT_RST); // "Stupid!"
        explosionScale = 100;
        explosionScaleStep = 30;
        if (pthis->type == 2) {
            explosionScale = 20;
            explosionScaleStep = 6;
        }
        EffectSsBomb2_SpawnLayered(globalCtx, &pthis->actor.world.pos, &velocity, &accel, explosionScale,
                                   explosionScaleStep);
        func_8002F71C(globalCtx, &pthis->actor, 2.0f, pthis->actor.yawTowardsPlayer, 0.0f);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_BOMB_EXPLOSION);
        Actor_Kill(&pthis->actor);
    }
}

void EnExRuppy_WaitAsCollectible(EnExRuppy* pthis, GlobalContext* globalCtx) {
    f32 localConst = 30.0f;

    if (pthis->actor.xyzDistToPlayerSq < SQ(localConst)) {
        func_80078884(NA_SE_SY_GET_RUPY);
        Item_DropCollectible(globalCtx, &pthis->actor.world.pos, (sEnExRuppyCollectibleTypes[pthis->colorIdx] | 0x8000));
        Actor_Kill(&pthis->actor);
    }
}

void EnExRuppy_GalleryTarget(EnExRuppy* pthis, GlobalContext* globalCtx) {
    if (pthis->galleryFlag) {
        Math_ApproachF(&pthis->actor.shape.yOffset, 700.0f, 0.5f, 200.0f);
    } else {
        Math_ApproachF(&pthis->actor.shape.yOffset, -700.0f, 0.5f, 200.0f);
    }
}

void EnExRuppy_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnExRuppy* pthis = (EnExRuppy*)thisx;

    pthis->actor.shape.rot.y += 1960;
    pthis->actionFunc(pthis, globalCtx);
    if (pthis->timer != 0) {
        pthis->timer--;
    }
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 50.0f, 0x1C);
}

void EnExRuppy_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static void* rupeeTextures[] = {
        gRupeeGreenTex, gRupeeBlueTex, gRupeeRedTex, gRupeePinkTex, gRupeeOrangeTex,
    };
    s32 pad;
    EnExRuppy* pthis = (EnExRuppy*)thisx;

    if (!pthis->invisible) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ex_ruppy.c", 774);

        func_80093D18(globalCtx->state.gfxCtx);
        func_8002EBCC(thisx, globalCtx, 0);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_ex_ruppy.c", 780),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(rupeeTextures[pthis->colorIdx]));
        gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ex_ruppy.c", 784);
    }
}

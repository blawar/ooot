#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ZO_Z_EN_ZO_C
#include "actor_common.h"
/*
 * File: z_en_zo.c
 * Overlay: ovl_En_Zo
 * Description: Zora
 */

#include "z_en_zo.h"
#include "objects/object_zo/object_zo.h"
#include "framerate.h"
#include "def/code_800FD970.h"
#include "def/cosf.h"
#include "def/sinf.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

typedef enum {
    /* 0 */ ENZO_EFFECT_NONE,
    /* 1 */ ENZO_EFFECT_RIPPLE,
    /* 2 */ ENZO_EFFECT_SPLASH,
    /* 3 */ ENZO_EFFECT_BUBBLE
} EnZoEffectType;

void EnZo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnZo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnZo_Update(Actor* thisx, GlobalContext* globalCtx);
void EnZo_Draw(Actor* thisx, GlobalContext* globalCtx);

// Actions
void EnZo_Standing(EnZo* pthis, GlobalContext* globalCtx);
void EnZo_Submerged(EnZo* pthis, GlobalContext* globalCtx);
void EnZo_Surface(EnZo* pthis, GlobalContext* globalCtx);
void EnZo_TreadWater(EnZo* pthis, GlobalContext* globalCtx);
void EnZo_Dive(EnZo* pthis, GlobalContext* globalCtx);

void EnZo_Ripple(EnZo* pthis, Vec3f* pos, f32 scale, f32 targetScale, u8 alpha) {
    EnZoEffect* effect;
    Vec3f vec = { 0.0f, 0.0f, 0.0f };
    s16 i;

    effect = pthis->effects;
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_NONE) {
            effect->type = ENZO_EFFECT_RIPPLE;
            effect->pos = *pos;
            effect->scale = scale;
            effect->targetScale = targetScale;
            effect->color.a = alpha;
            break;
        }
        effect++;
    }
}

void EnZo_Bubble(EnZo* pthis, Vec3f* pos) {
    EnZoEffect* effect;
    Vec3f vec = { 0.0f, 0.0f, 0.0f };
    Vec3f vel = { 0.0f, 1.0f, 0.0f };
    s16 i;
    f32 waterSurface;

    effect = pthis->effects;
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (1) {}
        if (effect->type == ENZO_EFFECT_NONE) {
            waterSurface = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
            if (!(waterSurface <= pos->y)) {
                effect->type = ENZO_EFFECT_BUBBLE;
                effect->pos = *pos;
                effect->vec = *pos;
                effect->vel = vel;
                effect->scale = ((Rand_ZeroOne() - 0.5f) * 0.02f) + 0.12f;
                break;
            }
        }
        effect++;
    }
}

void EnZo_Splash(EnZo* pthis, Vec3f* pos, Vec3f* vel, f32 scale) {
    EnZoEffect* effect;
    Vec3f accel = { 0.0f, -1.0f, 0.0f };
    s16 i;

    effect = pthis->effects;
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (1) {}
        if (effect->type != ENZO_EFFECT_SPLASH) {
            effect->type = ENZO_EFFECT_SPLASH;
            effect->pos = *pos;
            effect->vec = accel;
            effect->vel = *vel;
            effect->color.a = (Rand_ZeroOne() * 100.0f) + 100.0f;
            effect->scale = scale;
            break;
        }
        effect++;
    }
}

void EnZo_UpdateRipples(EnZo* pthis) {
    EnZoEffect* effect = pthis->effects;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_RIPPLE) {
            Math_ApproachF(&effect->scale, effect->targetScale, 0.2f, 0.8f);
            if (effect->color.a > 20) {
                effect->color.a -= 20;
            } else {
                effect->color.a = 0;
            }

            if (effect->color.a == 0) {
                effect->type = ENZO_EFFECT_NONE;
            }
        }
        effect++;
    }
}

void EnZo_UpdateBubbles(EnZo* pthis) {
    EnZoEffect* effect;
    f32 waterSurface;
    s16 i;

    effect = pthis->effects;
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_BUBBLE) {
            effect->pos.x = ((Rand_ZeroOne() * 0.5f) - 0.25f) + effect->vec.x;
            effect->pos.z = ((Rand_ZeroOne() * 0.5f) - 0.25f) + effect->vec.z;
            effect->pos.y += effect->vel.y;

            // Bubbles turn into ripples when they reach the surface
            waterSurface = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
            if (waterSurface <= effect->pos.y) {
                effect->type = ENZO_EFFECT_NONE;
                effect->pos.y = waterSurface;
                EnZo_Ripple(pthis, &effect->pos, 0.06f, 0.12f, 200);
            }
        }
        effect++;
    }
}

void EnZo_UpdateSplashes(EnZo* pthis) {
    EnZoEffect* effect;
    f32 waterSurface;
    s16 i;

    effect = pthis->effects;
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_SPLASH) {
            effect->pos.x += effect->vel.x;
            effect->pos.y += effect->vel.y;
            effect->pos.z += effect->vel.z;

            if (effect->vel.y >= -20.0f) {
                effect->vel.y += effect->vec.y;
            } else {
                effect->vel.y = -20.0f;
                effect->vec.y = 0.0f;
            }

            // Splash particles turn into ripples when they hit the surface
            waterSurface = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
            if (effect->pos.y < waterSurface) {
                effect->type = ENZO_EFFECT_NONE;
                effect->pos.y = waterSurface;
                EnZo_Ripple(pthis, &effect->pos, 0.06f, 0.12f, 200);
            }
        }
        effect++;
    }
}

void EnZo_DrawRipples(EnZo* pthis, GlobalContext* globalCtx) {
    EnZoEffect* effect;
    s16 i;
    u8 setup;

    effect = pthis->effects;
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 217);
    setup = false;
    func_80093D84(globalCtx->state.gfxCtx);
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_RIPPLE) {
            if (!setup) {
                if (1) {}
                gDPPipeSync(POLY_XLU_DISP++);
                gSPDisplayList(POLY_XLU_DISP++, gZoraRipplesMaterialDL);
                gDPSetEnvColor(POLY_XLU_DISP++, 155, 155, 155, 0);
                setup = true;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, effect->color.a);
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_Scale(effect->scale, 1.0f, effect->scale, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 242),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gZoraRipplesModelDL);
        }
        effect++;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 248);
}

void EnZo_DrawBubbles(EnZo* pthis, GlobalContext* globalCtx) {
    EnZoEffect* effect = pthis->effects;
    s16 i;
    u8 setup;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 260);
    setup = false;
    func_80093D84(globalCtx->state.gfxCtx);
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_BUBBLE) {
            if (!setup) {
                if (1) {}
                gSPDisplayList(POLY_XLU_DISP++, gZoraBubblesMaterialDL);
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 150, 150, 150, 0);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);

                setup = true;
            }

            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 281),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gZoraBubblesModelDL);
        }
        effect++;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 286);
}

void EnZo_DrawSplashes(EnZo* pthis, GlobalContext* globalCtx) {
    EnZoEffect* effect;
    s16 i;
    u8 setup;

    effect = pthis->effects;
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 298);
    setup = false;
    func_80093D84(globalCtx->state.gfxCtx);
    for (i = 0; i < ARRAY_COUNT(pthis->effects); i++) {
        if (effect->type == ENZO_EFFECT_SPLASH) {
            if (!setup) {
                if (1) {}
                gSPDisplayList(POLY_XLU_DISP++, gZoraSplashesMaterialDL);
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 200, 200, 200, 0);
                setup = true;
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 180, 180, 180, effect->color.a);

            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 325),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(POLY_XLU_DISP++, gZoraSplashesModelDL);
        }
        effect++;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zo_eff.c", 331);
}

void EnZo_TreadWaterRipples(EnZo* pthis, f32 scale, f32 targetScale, u8 alpha) {
    Vec3f pos = { 0.0f, 0.0f, 0.0f };

    pos.x = pthis->actor.world.pos.x;
    pos.y = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
    pos.z = pthis->actor.world.pos.z;
    EnZo_Ripple(pthis, &pos, scale, targetScale, alpha);
}

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 26, 64, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

ActorInit En_Zo_InitVars = {
    ACTOR_EN_ZO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZO,
    sizeof(EnZo),
    (ActorFunc)EnZo_Init,
    (ActorFunc)EnZo_Destroy,
    (ActorFunc)EnZo_Update,
    (ActorFunc)EnZo_Draw,
};

static struct_80034EC0_Entry sAnimations[] = {
    { &gZoraIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gZoraIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gZoraSurfaceAnim, 0.0f, 1.0f, 1.0f, ANIMMODE_ONCE, 0.0f },
    { &gZoraSurfaceAnim, 1.0f, 1.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gZoraSurfaceAnim, 1.0f, 8.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gZoraThrowRupeesAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gZoraHandsOnHipsTappingFootAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gZoraOpenArmsAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
};

void EnZo_SpawnSplashes(EnZo* pthis) {
    Vec3f pos;
    Vec3f vel;
    s32 i;

    // Convert 20 particles into splashes (all of them since there are only 15)
    for (i = 0; i < 20; i++) {
        f32 speed = Rand_ZeroOne() * 1.5f + 0.5f;
        f32 angle = Rand_ZeroOne() * 6.28f; // ~pi * 2

        vel.y = Rand_ZeroOne() * 3.0f + 3.0f;

        vel.x = sinf(angle) * speed;
        vel.z = cosf(angle) * speed;

        pos = pthis->actor.world.pos;
        pos.x += vel.x * 6.0f;
        pos.z += vel.z * 6.0f;
        pos.y += pthis->actor.yDistToWater;
        EnZo_Splash(pthis, &pos, &vel, 0.08f);
    }
}

u16 func_80B61024(GlobalContext* globalCtx, Actor* thisx) {
    u16 textId;

    textId = Text_GetFaceReaction(globalCtx, 29);
    if (textId != 0) {
        return textId;
    }

    switch (thisx->params & 0x3F) {
        case 8:
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x402A;
            }
            break;

        case 6:
            return 0x4020;

        case 7:
            return 0x4021;

        case 0:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402D;
            }
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x4007;
            }
            break;

        case 1:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402E;
            }

            if (gSaveContext.eventChkInf[3] & 1) {
                return (gSaveContext.infTable[18] & 0x10) ? 0x4009 : 0x4008;
            }
            break;

        case 2:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402D;
            }
            if (gSaveContext.eventChkInf[3] & 2) {
                return (gSaveContext.infTable[18] & 0x200) ? 0x400B : 0x402F;
            }
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x400A;
            }
            break;

        case 3:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402E;
            }
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x400C;
            }
            break;

        case 4:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402D;
            }

            if (gSaveContext.eventChkInf[3] & 8) {
                return 0x4010;
            }
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x400F;
            }
            break;

        case 5:
            if (CHECK_QUEST_ITEM(QUEST_ZORA_SAPPHIRE)) {
                return 0x402E;
            }
            if (gSaveContext.eventChkInf[3] & 1) {
                return 0x4011;
            }
            break;
    }
    return 0x4006;
}

s16 func_80B61298(GlobalContext* globalCtx, Actor* thisx) {
    switch (Message_GetState(&globalCtx->msgCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            return 1;

        case TEXT_STATE_CLOSING:
            switch (thisx->textId) {
                case 0x4020:
                case 0x4021:
                    return 0;
                case 0x4008:
                    gSaveContext.infTable[18] |= 0x10;
                    break;
                case 0x402F:
                    gSaveContext.infTable[18] |= 0x200;
                    break;
            }
            gSaveContext.eventChkInf[3] |= 1;
            return 0;

        case TEXT_STATE_CHOICE:
            switch (Message_ShouldAdvance(globalCtx)) {
                case 0:
                    return 1;
                default:
                    if (thisx->textId == 0x400C) {
                        thisx->textId = (globalCtx->msgCtx.choiceIndex == 0) ? 0x400D : 0x400E;
                        Message_ContinueTextbox(globalCtx, thisx->textId);
                    }
                    break;
            }
            return 1;

        case TEXT_STATE_EVENT:
            switch (Message_ShouldAdvance(globalCtx)) {
                case 0:
                    return 1;
                default:
                    return 2;
            }
    }

    return 1;
}

void EnZo_Blink(EnZo* pthis) {
    if (DECR(pthis->blinkTimer) == 0) {
        pthis->eyeTexture++;
        if (pthis->eyeTexture >= 3) {
            pthis->blinkTimer = (float)Rand_S16Offset(30, 30);
            pthis->eyeTexture = 0;
        }
    }
}

void EnZo_Dialog(EnZo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_194.unk_18 = player->actor.world.pos;
    if (pthis->actionFunc == EnZo_Standing) {
        // Look down at link if young, look up if old
        pthis->unk_194.unk_14 = !LINK_IS_ADULT ? 10.0f : -10.0f;
    } else {
        pthis->unk_194.unk_18.y = pthis->actor.world.pos.y;
    }
    func_80034A14(&pthis->actor, &pthis->unk_194, 11, pthis->unk_64C);
    if (pthis->canSpeak == true) {
        func_800343CC(globalCtx, &pthis->actor, &pthis->unk_194.unk_00, pthis->dialogRadius, func_80B61024, func_80B61298);
    }
}

s32 EnZo_PlayerInProximity(EnZo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f surfacePos;
    f32 yDist;
    f32 hDist;

    surfacePos.x = pthis->actor.world.pos.x;
    surfacePos.y = pthis->actor.world.pos.y + pthis->actor.yDistToWater;
    surfacePos.z = pthis->actor.world.pos.z;

    hDist = Math_Vec3f_DistXZ(&surfacePos, &player->actor.world.pos);
    yDist = fabsf(player->actor.world.pos.y - surfacePos.y);

    if (hDist < 240.0f && yDist < 80.0f) {
        return 1;
    }
    return 0;
}

void EnZo_SetAnimation(EnZo* pthis) {
    s32 animId = 8;

    if (pthis->skelAnime.animation == &gZoraHandsOnHipsTappingFootAnim ||
        pthis->skelAnime.animation == &gZoraOpenArmsAnim) {
        if (pthis->unk_194.unk_00 == 0) {
            if (pthis->actionFunc == EnZo_Standing) {
                animId = 0;
            } else {
                animId = 3;
            }
        }
    }

    if (pthis->unk_194.unk_00 != 0 && pthis->actor.textId == 0x4006 &&
        pthis->skelAnime.animation != &gZoraHandsOnHipsTappingFootAnim) {
        animId = 6;
    }

    if (pthis->unk_194.unk_00 != 0 && pthis->actor.textId == 0x4007 && pthis->skelAnime.animation != &gZoraOpenArmsAnim) {
        animId = 7;
    }

    if (animId != 8) {
        func_80034EC0(&pthis->skelAnime, sAnimations, animId);
        if (animId == 3) {
            pthis->skelAnime.curFrame = pthis->skelAnime.endFrame;
            pthis->skelAnime.playSpeed = 0.0f;
        }
    }
}

void EnZo_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnZo* pthis = (EnZo*)thisx;

    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gZoraSkel, NULL, pthis->jointTable, pthis->morphTable, 20);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, NULL, &sColChkInit);

    if (LINK_IS_ADULT && ((pthis->actor.params & 0x3F) == 8)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    func_80034EC0(&pthis->skelAnime, sAnimations, 2);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actor.targetMode = 6;
    pthis->dialogRadius = pthis->collider.dim.radius + 30.0f;
    pthis->unk_64C = 1;
    pthis->canSpeak = false;
    pthis->unk_194.unk_00 = 0;
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, pthis->collider.dim.height * 0.5f, pthis->collider.dim.radius, 0.0f,
                            5);

    if (pthis->actor.yDistToWater < 54.0f || (pthis->actor.params & 0x3F) == 8) {
        pthis->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        pthis->actor.shape.shadowScale = 24.0f;
        func_80034EC0(&pthis->skelAnime, sAnimations, 1);
        pthis->canSpeak = true;
        pthis->alpha = 255.0f;
        pthis->actionFunc = EnZo_Standing;
    } else {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actionFunc = EnZo_Submerged;
    }
}

void EnZo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnZo_Standing(EnZo* pthis, GlobalContext* globalCtx) {
    s16 angle;

    func_80034F54(globalCtx, pthis->unk_656, pthis->unk_67E, 20);
    EnZo_SetAnimation(pthis);
    if (pthis->unk_194.unk_00 != 0) {
        pthis->unk_64C = 4;
        return;
    }

    angle = ABS((s16)((f32)pthis->actor.yawTowardsPlayer - (f32)pthis->actor.shape.rot.y));
    if (angle < 0x4718) {
        if (EnZo_PlayerInProximity(pthis, globalCtx)) {
            pthis->unk_64C = 2;
        } else {
            pthis->unk_64C = 1;
        }
    } else {
        pthis->unk_64C = 1;
    }
}

void EnZo_Submerged(EnZo* pthis, GlobalContext* globalCtx) {
    if (EnZo_PlayerInProximity(pthis, globalCtx)) {
        pthis->actionFunc = EnZo_Surface;
        pthis->actor.velocity.y = 4.0f;
    }
}

void EnZo_Surface(EnZo* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.yDistToWater < 54.0f) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_OUT_OF_WATER);
        EnZo_SpawnSplashes(pthis);
        func_80034EC0(&pthis->skelAnime, sAnimations, 3);
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actionFunc = EnZo_TreadWater;
        pthis->actor.velocity.y = 0.0f;
        pthis->alpha = 255.0f;
    } else if (pthis->actor.yDistToWater < 80.0f) {
        Math_ApproachF(&pthis->actor.velocity.y, 2.0f, 0.4f, 0.6f);
        Math_ApproachF(&pthis->alpha, 255.0f, 0.3f, 10.0f);
    }
}

void EnZo_TreadWater(EnZo* pthis, GlobalContext* globalCtx) {
    func_80034F54(globalCtx, pthis->unk_656, pthis->unk_67E, 20);
    if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
        pthis->canSpeak = true;
        pthis->unk_64C = 4;
        pthis->skelAnime.playSpeed = 0.0f;
    }
    EnZo_SetAnimation(pthis);

    Math_ApproachF(&pthis->actor.velocity.y, pthis->actor.yDistToWater < 54.0f ? -0.6f : 0.6f, 0.3f, 0.2f);
    if (pthis->rippleTimer > 0.0f) {
        DECR(pthis->rippleTimer);
        if ((pthis->rippleTimer == 3) || (pthis->rippleTimer == 6)) {
            EnZo_TreadWaterRipples(pthis, 0.2f, 1.0f, 200);
        }
    } else {
        EnZo_TreadWaterRipples(pthis, 0.2f, 1.0f, 200);
        pthis->rippleTimer = 12.0f;
    }

    if (EnZo_PlayerInProximity(pthis, globalCtx) != 0) {
        pthis->timeToDive = Rand_S16Offset(40, 40);
    } else if (DECR(pthis->timeToDive) == 0) {
        f32 startFrame;
        func_80034EC0(&pthis->skelAnime, sAnimations, 4);
        pthis->canSpeak = false;
        pthis->unk_64C = 1;
        pthis->actionFunc = EnZo_Dive;
        startFrame = pthis->skelAnime.startFrame;
        pthis->skelAnime.startFrame = pthis->skelAnime.endFrame;
        pthis->skelAnime.curFrame = pthis->skelAnime.endFrame;
        pthis->skelAnime.endFrame = startFrame;
        pthis->skelAnime.playSpeed = -1.0f;
    }
}

void EnZo_Dive(EnZo* pthis, GlobalContext* globalCtx) {
    if (Animation_OnFrame(&pthis->skelAnime, pthis->skelAnime.endFrame)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_DIVE_WATER);
        EnZo_SpawnSplashes(pthis);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->actor.velocity.y = -4.0f;
        pthis->skelAnime.playSpeed = 0.0f;
    }

    if (pthis->skelAnime.playSpeed > 0.0f) {
        return;
    }

    if (pthis->actor.yDistToWater > 80.0f || pthis->actor.bgCheckFlags & 1) {
        Math_ApproachF(&pthis->actor.velocity.y, -1.0f, 0.4f, 0.6f);
        Math_ApproachF(&pthis->alpha, 0.0f, 0.3f, 10.0f);
    }

    if ((s16)pthis->alpha == 0) {
        func_80034EC0(&pthis->skelAnime, sAnimations, 2);
        pthis->actor.world.pos = pthis->actor.home.pos;
        pthis->alpha = 0.0f;
        pthis->actionFunc = EnZo_Submerged;
    }
}

void EnZo_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnZo* pthis = (EnZo*)thisx;
    u32 pad;
    Vec3f pos;

    if ((s32)pthis->alpha != 0) {
        SkelAnime_Update(&pthis->skelAnime);
        EnZo_Blink(pthis);
    }

    Actor_MoveForward(thisx);
    Actor_UpdateBgCheckInfo(globalCtx, thisx, pthis->collider.dim.radius, pthis->collider.dim.height * 0.25f, 0.0f, 5);
    pthis->actionFunc(pthis, globalCtx);
    EnZo_Dialog(pthis, globalCtx);

    // Spawn air bubbles
    if (globalCtx->state.frames & 8) {
        pos = pthis->actor.world.pos;

        pos.y += (Rand_ZeroOne() - 0.5f) * 10.0f + 18.0f;
        pos.x += (Rand_ZeroOne() - 0.5f) * 28.0f;
        pos.z += (Rand_ZeroOne() - 0.5f) * 28.0f;
        EnZo_Bubble(pthis, &pos);
    }

    if ((s32)pthis->alpha != 0) {
        Collider_UpdateCylinder(thisx, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    EnZo_UpdateRipples(pthis);
    EnZo_UpdateBubbles(pthis);
    EnZo_UpdateSplashes(pthis);
}

s32 EnZo_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                          Gfx** gfx) {
    EnZo* pthis = (EnZo*)thisx;
    Vec3s vec;

    if (limbIndex == 15) {
        Matrix_Translate(1800.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec = pthis->unk_194.unk_08;
        Matrix_RotateX((vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_Translate(-1800.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }

    if (limbIndex == 8) {
        vec = pthis->unk_194.unk_0E;
        Matrix_RotateX((-vec.y / 32768.0f) * M_PI, MTXMODE_APPLY);
        Matrix_RotateZ((vec.x / 32768.0f) * M_PI, MTXMODE_APPLY);
    }

    if ((limbIndex == 8) || (limbIndex == 9) || (limbIndex == 12)) {
        rot->y += (Math_SinS(pthis->unk_656[limbIndex]) * 200.0f);
        rot->z += (Math_CosS(pthis->unk_67E[limbIndex]) * 200.0f);
    }

    return 0;
}

void EnZo_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnZo* pthis = (EnZo*)thisx;
    Vec3f vec = { 0.0f, 600.0f, 0.0f };

    if (limbIndex == 15) {
        Matrix_MultVec3f(&vec, &pthis->actor.focus.pos);
    }
}

void EnZo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnZo* pthis = (EnZo*)thisx;
    void* eyeTextures[] = { gZoraEyeOpenTex, gZoraEyeHalfTex, gZoraEyeClosedTex };

    Matrix_Push();
    EnZo_DrawRipples(pthis, globalCtx);
    EnZo_DrawBubbles(pthis, globalCtx);
    EnZo_DrawSplashes(pthis, globalCtx);
    Matrix_Pop();

    if ((s32)pthis->alpha != 0) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zo.c", 1008);

        if (pthis->alpha == 255.0f) {
            gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeTexture]));
            func_80034BA0(globalCtx, &pthis->skelAnime, EnZo_OverrideLimbDraw, EnZo_PostLimbDraw, thisx, pthis->alpha);
        } else {
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[pthis->eyeTexture]));
            func_80034CC4(globalCtx, &pthis->skelAnime, EnZo_OverrideLimbDraw, EnZo_PostLimbDraw, thisx, pthis->alpha);
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zo.c", 1025);
    }
}

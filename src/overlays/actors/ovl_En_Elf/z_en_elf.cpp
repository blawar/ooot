#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ELF_Z_EN_ELF_C
#include "actor_common.h"
/*
 * File: z_en_elf.c
 * Overlay: ovl_En_Elf
 * Description: Fairy
 */

#include "z_en_elf.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/random.h"
#include "def/graph.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_elf_message.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

#define FAIRY_FLAG_TIMED (1 << 8)
#define FAIRY_FLAG_BIG (1 << 9)

void EnElf_Init(Actor* thisx, GlobalContext* globalCtx);
void EnElf_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnElf_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnElf_Update(Actor* thisx, GlobalContext* globalCtx);
void EnElf_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80A053F0(Actor* thisx, GlobalContext* globalCtx);
void func_80A052F4(Actor* thisx, GlobalContext* globalCtx);
void func_80A05208(Actor* thisx, GlobalContext* globalCtx);
void func_80A05188(Actor* thisx, GlobalContext* globalCtx);
void func_80A05114(Actor* thisx, GlobalContext* globalCtx);
void func_80A05040(Actor* thisx, GlobalContext* globalCtx);

// Navi
void func_80A03CF8(EnElf* pthis, GlobalContext* globalCtx);

// Healing Fairies
void func_80A0329C(EnElf* pthis, GlobalContext* globalCtx);
void func_80A03610(EnElf* pthis, GlobalContext* globalCtx);

// Healing Fairies Revive From Death
void func_80A03990(EnElf* pthis, GlobalContext* globalCtx);
void func_80A03814(EnElf* pthis, GlobalContext* globalCtx);

// Kokiri Fairies
void func_80A0353C(EnElf* pthis, GlobalContext* globalCtx);

// Fairy Spawner
void func_80A03604(EnElf* pthis, GlobalContext* globalCtx);

// Move(?) functions
void func_80A0214C(EnElf* pthis, GlobalContext* globalCtx);
void func_80A02AA4(EnElf* pthis, GlobalContext* globalCtx);
void func_80A02A20(EnElf* pthis, GlobalContext* globalCtx);
void func_80A02B38(EnElf* pthis, GlobalContext* globalCtx);
void func_80A020A4(EnElf* pthis, GlobalContext* globalCtx);
void func_80A01FE0(EnElf* pthis, GlobalContext* globalCtx);

// misc
void func_80A04414(EnElf* pthis, GlobalContext* globalCtx);
void func_80A0461C(EnElf* pthis, GlobalContext* globalCtx);
void EnElf_SpawnSparkles(EnElf* pthis, GlobalContext* globalCtx, s32 sparkleLife);
void EnElf_GetCutsceneNextPos(Vec3f* vec, GlobalContext* globalCtx, s32 action);

static Vec3f sparkleVelocity_105 = { 0.0f, -0.05f, 0.0f };

static Vec3f sparkleAccel_105 = { 0.0f, -0.025f, 0.0f };

static Vec3f zeroVec_121 = { 0.0f, 0.0f, 0.0f };


ActorInit En_Elf_InitVars = {
    ACTOR_EN_ELF,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnElf),
    (ActorFunc)EnElf_Init,
    (ActorFunc)EnElf_Destroy,
    (ActorFunc)EnElf_Update,
    (ActorFunc)EnElf_Draw,
    (ActorFunc)EnElf_Reset,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 8, ICHAIN_STOP),
};

static Color_RGBAf sInnerColors[] = {
    { 255.0f, 255.0f, 255.0f, 255.0f },
    { 255.0f, 220.0f, 220.0f, 255.0f },
};

static Color_RGBAf sOuterColors[] = {
    { 255.0f, 255.0f, 255.0f, 255.0f },
    { 255.0f, 50.0f, 100.0f, 255.0f },
};

static FairyColorFlags sColorFlags[] = {
    { 0, 0, 0 }, { 1, 0, 0 }, { 1, 2, 0 }, { 1, 0, 2 }, { 0, 1, 0 }, { 2, 1, 0 }, { 0, 1, 2 },
    { 0, 0, 1 }, { 2, 0, 1 }, { 0, 2, 1 }, { 1, 1, 0 }, { 1, 0, 1 }, { 0, 1, 1 },
};

void EnElf_SetupAction(EnElf* pthis, EnElfActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void func_80A01C38(EnElf* pthis, s32 arg1) {
    pthis->unk_2A8 = arg1;

    switch (pthis->unk_2A8) {
        case 0:
            pthis->unk_2AE = 0x400;
            pthis->unk_2B0 = 0x200;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2C0 = 100;
            pthis->unk_2B4 = 5.0f;
            pthis->unk_2B8 = 20.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 12:
            pthis->unk_2AE = 0x400;
            pthis->unk_2B0 = 0x200;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2C0 = 100;
            pthis->unk_2B4 = 1.0f;
            pthis->unk_2B8 = 5.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 10:
            pthis->unk_2AE = 0x400;
            pthis->unk_2B0 = 0;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2B8 = 0.0f;
            pthis->unk_2B4 = 5.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 9:
            pthis->unk_2AE = 0x1000;
            pthis->unk_2B0 = 0x200;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2B4 = 3.0f;
            pthis->unk_2B8 = 10.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 7:
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2AE = 0x1E;
            pthis->unk_2C0 = 1;
            pthis->unk_2B4 = 0.0f;
            pthis->unk_2B8 = 0.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 8:
            pthis->unk_2AE = 0x1000;
            pthis->unk_2B0 = 0x200;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2B4 = 0.0f;
            pthis->unk_2B8 = 0.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 1:
            pthis->unk_2AE = 0x1000;
            pthis->unk_2B0 = 0x800;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2B4 = 5.0f;
            pthis->unk_2B8 = 7.5f;
            pthis->skelAnime.playSpeed = 2.0f;
            break;
        case 2:
            pthis->unk_2AE = 0x400;
            pthis->unk_2B0 = 0x1000;
            pthis->func_2C8 = func_80A02AA4;
            pthis->unk_2B4 = 10.0f;
            pthis->unk_2B8 = 20.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 3:
            pthis->unk_2B0 = 0x600;
            pthis->func_2C8 = func_80A02B38;
            pthis->unk_2B8 = 1.0f;
            pthis->unk_2B4 = 1.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
        case 4:
            pthis->unk_2B0 = 0x800;
            pthis->func_2C8 = func_80A02B38;
            pthis->unk_2B4 = 20.0f;
            pthis->unk_2B8 = 10.0;
            pthis->skelAnime.playSpeed = 2.0f;
            break;
        case 5:
            pthis->unk_2B0 = 0x200;
            pthis->func_2C8 = func_80A02B38;
            pthis->unk_2B4 = 10.0f;
            pthis->unk_2B8 = 10.0f;
            pthis->skelAnime.playSpeed = 0.5f;
            break;
        case 6:
            pthis->unk_2AE = 0x1000;
            pthis->unk_2B0 = 0x800;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2B4 = 60.0f;
            pthis->unk_2B8 = 20.0f;
            pthis->skelAnime.playSpeed = 2.0f;
            break;
        case 11:
            pthis->unk_2AE = 0x400;
            pthis->unk_2B0 = 0x2000;
            pthis->func_2C8 = func_80A02A20;
            pthis->unk_2C0 = 42;
            pthis->unk_2B4 = 5.0f;
            pthis->unk_2B8 = 1.0f;
            pthis->skelAnime.playSpeed = 1.0f;
            break;
    }
}

s32 func_80A01F90(Vec3f* pthis, Vec3f* arg1, f32 arg2) {
    return SQ(arg2) < (SQ(arg1->x - pthis->x) + SQ(arg1->z - pthis->z));
}

void func_80A01FE0(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!func_80A01F90(&pthis->actor.world.pos, &player->actor.world.pos, 30.0f)) {
        pthis->unk_2B8 = 0.5f;
    } else {
        pthis->unk_2B8 = 2.0f;
    }

    if (pthis->unk_2C0 > 0) {
        pthis->unk_2C0--;
    } else {
        pthis->unk_2A8 = 1;
        pthis->unk_2AC = 0x80;
        pthis->unk_2B8 = Rand_ZeroFloat(1.0f) + 0.5f;
        pthis->unk_2B0 = Rand_CenteredFloat(32767.0f);
        pthis->func_2C8 = func_80A0214C;
    }
}

void func_80A020A4(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (func_80A01F90(&pthis->actor.world.pos, &player->actor.world.pos, 50.0f)) {
        if (pthis->unk_2C0 > 0) {
            pthis->unk_2C0--;
        } else {
            pthis->unk_2A8 = 1;
            pthis->unk_2AC = 0x80;
            pthis->unk_2B8 = Rand_ZeroFloat(1.0f) + 0.5f;
            pthis->unk_2B0 = Rand_CenteredFloat(32767.0f);
            pthis->func_2C8 = func_80A0214C;
        }
    }
}

void func_80A0214C(EnElf* pthis, GlobalContext* globalCtx) {
    f32 xzDistToPlayer;

    if (pthis->unk_2C0 > 0) {
        pthis->unk_2C0--;
    } else {
        xzDistToPlayer = pthis->actor.xzDistToPlayer;
        if (xzDistToPlayer < 50.0f) {
            if (Rand_ZeroOne() < 0.2f) {
                pthis->unk_2A8 = 2;
                pthis->unk_2AC = 0x400;
                pthis->unk_2B8 = 2.0f;
                pthis->func_2C8 = func_80A020A4;
                pthis->actor.speedXZ = 1.5f;
                pthis->unk_2C0 = (s16)Rand_ZeroFloat(8.0f) + 4;
            } else {
                pthis->unk_2C0 = 10;
            }
        } else {
            if (xzDistToPlayer > 150.0f) {
                xzDistToPlayer = 150.0f;
            }

            xzDistToPlayer = ((xzDistToPlayer - 50.0f) * 0.95f) + 0.05f;

            if (Rand_ZeroOne() < xzDistToPlayer) {
                pthis->unk_2A8 = 3;
                pthis->unk_2AC = 0x200;
                pthis->unk_2B8 = (xzDistToPlayer * 2.0f) + 1.0f;
                pthis->func_2C8 = func_80A01FE0;
                pthis->unk_2C0 = (s16)Rand_ZeroFloat(16.0f) + 0x10;
            } else {
                pthis->unk_2C0 = 10;
            }
        }
    }

    if (Rand_ZeroOne() < 0.1f) {
        pthis->unk_2A8 = 1;
        pthis->unk_2AC = 0x80;
        pthis->unk_2B8 = Rand_ZeroFloat(0.5f) + 0.5f;
        pthis->unk_2B0 = Rand_CenteredFloat(32767.0f);
    }
}

void func_80A0232C(EnElf* pthis, GlobalContext* globalCtx) {
    if (func_80A01F90(&pthis->unk_28C, &pthis->actor.world.pos, 100.0f)) {
        pthis->unk_2A8 = 0;
        pthis->unk_2AC = 0x200;
        pthis->func_2C8 = func_80A0214C;
        pthis->unk_2B8 = 1.5f;
    } else {
        pthis->func_2C8(pthis, globalCtx);
    }
}

f32 EnElf_GetColorValue(s32 colorFlag) {
    switch (colorFlag) {
        case 1:
            return Rand_ZeroFloat(55.0f) + 200.0f;
        case 2:
            return Rand_ZeroFloat(255.0f);
        default:
            return 0.0f;
    }
}

void EnElf_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnElf* pthis = (EnElf*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s32 colorConfig;
    s32 i;

    Actor_ProcessInitChain(thisx, sInitChain);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gFairySkel, &gFairyAnim, pthis->jointTable, pthis->morphTable, 15);
    ActorShape_Init(&thisx->shape, 0.0f, NULL, 15.0f);
    thisx->shape.shadowAlpha = 0xFF;

    Lights_PointGlowSetInfo(&pthis->lightInfoGlow, thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 255, 255,
                            255, 0);
    pthis->lightNodeGlow = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfoGlow);

    Lights_PointNoGlowSetInfo(&pthis->lightInfoNoGlow, thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 255,
                              255, 255, 0);
    pthis->lightNodeNoGlow = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfoNoGlow);

    pthis->fairyFlags = 0;
    pthis->disappearTimer = 600;
    pthis->unk_2A4 = 0.0f;
    colorConfig = 0;

    switch (thisx->params) {
        case FAIRY_NAVI:
            thisx->room = -1;
            EnElf_SetupAction(pthis, func_80A03CF8);
            func_80A01C38(pthis, 0);
            pthis->fairyFlags |= 4;
            thisx->update = func_80A053F0;
            pthis->elfMsg = NULL;
            pthis->unk_2C7 = 0x14;

            if ((gSaveContext.naviTimer >= 25800) || (gSaveContext.naviTimer < 3000)) {
                gSaveContext.naviTimer = 0;
            }
            break;
        case FAIRY_REVIVE_BOTTLE:
            colorConfig = -1;
            EnElf_SetupAction(pthis, func_80A03610);
            pthis->unk_2B8 = Math_Vec3f_DistXZ(&thisx->world.pos, &player->actor.world.pos);
            pthis->unk_2AC = player->actor.shape.rot.y;
            pthis->unk_2B0 = -0x1000;
            pthis->unk_28C.y = thisx->world.pos.y - player->actor.world.pos.y;
            pthis->unk_2AA = 0;
            pthis->unk_2B4 = 0.0f;
            break;
        case FAIRY_REVIVE_DEATH:
            colorConfig = -1;
            EnElf_SetupAction(pthis, func_80A03990);
            pthis->unk_2B8 = 0.0f;
            pthis->unk_2AC = player->actor.shape.rot.y;
            pthis->unk_2B0 = 0;
            pthis->unk_28C.y = thisx->world.pos.y - player->actor.world.pos.y;
            pthis->unk_2AA = 0;
            pthis->unk_2B4 = 7.0f;
            break;
        case FAIRY_HEAL_BIG:
            pthis->fairyFlags |= FAIRY_FLAG_BIG;
            thisx->shape.shadowDraw = ActorShadow_DrawWhiteCircle;
        case FAIRY_HEAL_TIMED:
            pthis->fairyFlags |= FAIRY_FLAG_TIMED;
        case FAIRY_HEAL:
            colorConfig = -1;
            EnElf_SetupAction(pthis, func_80A0329C);
            pthis->unk_2B4 = Rand_ZeroFloat(10.0f) + 10.0f;
            pthis->unk_2AA = 0;
            pthis->unk_2AE = (s16)(Rand_ZeroFloat(1048.0f)) + 0x200;
            pthis->unk_28C = thisx->world.pos;
            pthis->unk_2BC = Rand_CenteredFloat(32767.0f);
            pthis->func_2C8 = func_80A0214C;
            func_80A0232C(pthis, globalCtx);
            pthis->unk_2C0 = 0;
            pthis->disappearTimer = 240;
            break;
        case FAIRY_KOKIRI:
            colorConfig = Rand_ZeroFloat(11.99f) + 1.0f;
            EnElf_SetupAction(pthis, func_80A0353C);
            func_80A01C38(pthis, 0);
            break;
        case FAIRY_SPAWNER:
            EnElf_SetupAction(pthis, func_80A03604);
            func_80A01C38(pthis, 8);

            for (i = 0; i < 8; i++) {
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_ELF, thisx->world.pos.x,
                            thisx->world.pos.y - 30.0f, thisx->world.pos.z, 0, 0, 0, FAIRY_HEAL);
            }
            break;
        default:
            ASSERT(0, "0", "../z_en_elf.c", 1103);
            break;
    }

    pthis->unk_2A0 = 3.0f;
    pthis->innerColor = sInnerColors[0];

    if (colorConfig > 0) {
        pthis->outerColor.r = EnElf_GetColorValue(sColorFlags[colorConfig].r);
        pthis->outerColor.g = EnElf_GetColorValue(sColorFlags[colorConfig].g);
        pthis->outerColor.b = EnElf_GetColorValue(sColorFlags[colorConfig].b);
        pthis->outerColor.a = 0.0f;
    } else {
        pthis->innerColor = sInnerColors[-colorConfig];
        pthis->outerColor = sOuterColors[-colorConfig];
    }
}

void func_80A0299C(EnElf* pthis, s32 arg1) {
}

void func_80A029A8(EnElf* pthis, s16 increment) {
    if (pthis->disappearTimer < 600) {
        pthis->disappearTimer += increment;
    }
}

void EnElf_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnElf* pthis = (EnElf*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNodeGlow);
    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNodeNoGlow);
}

void func_80A02A20(EnElf* pthis, GlobalContext* globalCtx) {
    pthis->unk_28C.x = Math_SinS(pthis->unk_2AC) * pthis->unk_2B8;
    pthis->unk_28C.y = Math_SinS(pthis->unk_2AA) * pthis->unk_2B4;
    pthis->unk_28C.z = Math_CosS(pthis->unk_2AC) * pthis->unk_2B8;
    pthis->unk_2AC += pthis->unk_2B0;
    pthis->unk_2AA += pthis->unk_2AE;
}

void func_80A02AA4(EnElf* pthis, GlobalContext* globalCtx) {
    f32 xzScale;

    xzScale = (Math_CosS(pthis->unk_2AA) * pthis->unk_2B4) + pthis->unk_2B8;

    pthis->unk_28C.x = Math_SinS(pthis->unk_2AC) * xzScale;
    pthis->unk_28C.y = 0.0f;
    pthis->unk_28C.z = Math_CosS(pthis->unk_2AC) * xzScale;

    pthis->unk_2AC += pthis->unk_2B0;
    pthis->unk_2AA += pthis->unk_2AE;
}

void func_80A02B38(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_2AA = (pthis->unk_2AC * 2) & 0xFFFF;
    pthis->unk_28C.x = Math_SinS(pthis->unk_2AC) * pthis->unk_2B8;
    pthis->unk_28C.y = Math_SinS(pthis->unk_2AA) * pthis->unk_2B4;
    pthis->unk_28C.z = -Math_SinS(player->actor.shape.rot.y) * pthis->unk_28C.x;
    pthis->unk_28C.x = Math_CosS(player->actor.shape.rot.y) * pthis->unk_28C.x;
    pthis->unk_2AC += pthis->unk_2B0;
}

void func_80A02BD8(EnElf* pthis, Vec3f* targetPos, f32 arg2) {
    f32 yVelTarget;
    f32 yVelDirection;

    yVelTarget = ((targetPos->y + pthis->unk_28C.y) - pthis->actor.world.pos.y) * arg2;
    yVelDirection = (yVelTarget >= 0.0f) ? 1.0f : -1.0f;
    yVelTarget = fabsf(yVelTarget);
    yVelTarget = CLAMP(yVelTarget, 0.0f, 20.0f) * yVelDirection;
    Math_StepToF(&pthis->actor.velocity.y, yVelTarget, 32.0f);
}

void func_80A02C98(EnElf* pthis, Vec3f* targetPos, f32 arg2) {
    f32 xVelTarget;
    f32 zVelTarget;
    f32 xVelDirection;
    f32 zVelDirection;

    xVelTarget = ((targetPos->x + pthis->unk_28C.x) - pthis->actor.world.pos.x) * arg2;
    zVelTarget = ((targetPos->z + pthis->unk_28C.z) - pthis->actor.world.pos.z) * arg2;

    xVelDirection = (xVelTarget >= 0.0f) ? 1.0f : -1.0f;
    zVelDirection = (zVelTarget >= 0.0f) ? 1.0f : -1.0f;

    xVelTarget = fabsf(xVelTarget);
    zVelTarget = fabsf(zVelTarget);

    xVelTarget = CLAMP(xVelTarget, 0.0f, 20.0f) * xVelDirection;
    zVelTarget = CLAMP(zVelTarget, 0.0f, 20.0f) * zVelDirection;

    func_80A02BD8(pthis, targetPos, arg2);
    Math_StepToF(&pthis->actor.velocity.x, xVelTarget, 1.5f);
    Math_StepToF(&pthis->actor.velocity.z, zVelTarget, 1.5f);
    func_8002D7EC(&pthis->actor);
}

void func_80A02E30(EnElf* pthis, Vec3f* targetPos) {
    func_80A02BD8(pthis, targetPos, 0.2f);
    pthis->actor.velocity.x = (targetPos->x + pthis->unk_28C.x) - pthis->actor.world.pos.x;
    pthis->actor.velocity.z = (targetPos->z + pthis->unk_28C.z) - pthis->actor.world.pos.z;
    func_8002D7EC(&pthis->actor);
    pthis->actor.world.pos.x = targetPos->x + pthis->unk_28C.x;
    pthis->actor.world.pos.z = targetPos->z + pthis->unk_28C.z;
}

void func_80A02EC0(EnElf* pthis, Vec3f* targetPos) {
    func_80A02BD8(pthis, targetPos, 0.2f);
    pthis->actor.velocity.x = pthis->actor.velocity.z = 0.0f;
    func_8002D7EC(&pthis->actor);
    pthis->actor.world.pos.x = targetPos->x + pthis->unk_28C.x;
    pthis->actor.world.pos.z = targetPos->z + pthis->unk_28C.z;
}

void func_80A02F2C(EnElf* pthis, Vec3f* targetPos) {
    f32 yVelTarget;
    f32 yVelDirection;

    yVelTarget = (((Math_SinS(pthis->unk_2AA) * pthis->unk_2B4) + targetPos->y) - pthis->actor.world.pos.y) * 0.2f;
    yVelDirection = (yVelTarget >= 0.0f) ? 1.0f : -1.0f;
    pthis->unk_2AA += pthis->unk_2AE;
    yVelTarget = fabsf(yVelTarget);
    yVelTarget = CLAMP(yVelTarget, 0.0f, 20.0f) * yVelDirection;
    Math_StepToF(&pthis->actor.velocity.y, yVelTarget, 1.5f);
}

void func_80A03018(EnElf* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Player* player = GET_PLAYER(globalCtx);
    s16 targetYaw;
    Vec3f* unk_28C = &pthis->unk_28C;

    Math_SmoothStepToF(&pthis->actor.speedXZ, pthis->unk_2B8, 0.2f, 0.5f, 0.01f);

    switch (pthis->unk_2A8) {
        case 0:
            targetYaw = Math_Atan2S(-(pthis->actor.world.pos.z - unk_28C->z), -(pthis->actor.world.pos.x - unk_28C->x));
            break;

        case 3:
            targetYaw = Math_Atan2S(-(pthis->actor.world.pos.z - player->actor.world.pos.z),
                                    -(pthis->actor.world.pos.x - player->actor.world.pos.x));
            break;

        case 2:
            targetYaw = Math_Atan2S(pthis->actor.world.pos.z - player->actor.world.pos.z,
                                    pthis->actor.world.pos.x - player->actor.world.pos.x);
            break;

        default:
            targetYaw = pthis->unk_2B0;
            break;
    }

    Math_SmoothStepToS(&pthis->unk_2BC, targetYaw, 10, pthis->unk_2AC, 0x20);
    pthis->actor.world.rot.y = pthis->unk_2BC;
    Actor_MoveForward(&pthis->actor);
}

void func_80A03148(EnElf* pthis, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 xVelTarget;
    f32 zVelTarget;
    f32 xzVelocity;
    f32 clampedXZ;

    xVelTarget = ((arg1->x + pthis->unk_28C.x) - pthis->actor.world.pos.x) * arg4;
    zVelTarget = ((arg1->z + pthis->unk_28C.z) - pthis->actor.world.pos.z) * arg4;
    arg4 += 0.3f;
    arg3 += 30.0f;

    func_80A02BD8(pthis, arg1, arg4);

    xzVelocity = sqrtf(SQ(xVelTarget) + SQ(zVelTarget));

    pthis->actor.speedXZ = clampedXZ = CLAMP(xzVelocity, arg2, arg3);

    if ((xzVelocity != clampedXZ) && (xzVelocity != 0.0f)) {
        xzVelocity = clampedXZ / xzVelocity;
        xVelTarget *= xzVelocity;
        zVelTarget *= xzVelocity;
    }

    Math_StepToF(&pthis->actor.velocity.x, xVelTarget, 5.0f);
    Math_StepToF(&pthis->actor.velocity.z, zVelTarget, 5.0f);
    func_8002D7EC(&pthis->actor);
}

void func_80A0329C(EnElf* pthis, GlobalContext* globalCtx) {
    Player* refActor = GET_PLAYER(globalCtx);
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    f32 heightDiff;

    SkelAnime_Update(&pthis->skelAnime);

    if (Rand_ZeroOne() < 0.05f) {
        pthis->unk_2B4 = Rand_ZeroFloat(10.0f) + 10.0f;
        pthis->unk_2AE = (s16)(Rand_ZeroFloat(1024.0f)) + 0x200;
    }

    func_80A0232C(pthis, globalCtx);
    pthis->unk_28C.y = player->bodyPartsPos[0].y;
    func_80A02F2C(pthis, &pthis->unk_28C);
    func_80A03018(pthis, globalCtx);

    if ((pthis->unk_2A8 == 2) || (pthis->unk_2A8 == 3)) {
        EnElf_SpawnSparkles(pthis, globalCtx, 16);
    }

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (!Player_InCsMode(globalCtx)) {
        heightDiff = pthis->actor.world.pos.y - refActor->actor.world.pos.y;

        if ((heightDiff > 0.0f) && (heightDiff < 60.0f)) {
            if (!func_80A01F90(&pthis->actor.world.pos, &refActor->actor.world.pos, 10.0f)) {
                Health_ChangeBy(globalCtx, 128);
                if (pthis->fairyFlags & FAIRY_FLAG_BIG) {
                    Magic_Fill(globalCtx);
                }
                pthis->unk_2B8 = 50.0f;
                pthis->unk_2AC = refActor->actor.shape.rot.y;
                pthis->unk_2B0 = -0x1000;
                pthis->unk_28C.y = 30.0f;
                pthis->unk_2B4 = 0.0f;
                pthis->unk_2AA = 0;
                EnElf_SetupAction(pthis, func_80A03610);
                return;
            }
        }

        if (pthis->fairyFlags & FAIRY_FLAG_TIMED) {
            if (pthis->disappearTimer > 0) {
                pthis->disappearTimer--;
            } else {
                pthis->disappearTimer--;

                if (pthis->disappearTimer > -10) {
                    Actor_SetScale(&pthis->actor, ((pthis->disappearTimer + 10) * 0.008f) * 0.1f);
                } else {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            }
        }

        if (!(pthis->fairyFlags & FAIRY_FLAG_BIG)) {
            // GI_MAX in pthis case allows the player to catch the actor in a bottle
            func_8002F434(&pthis->actor, globalCtx, GI_MAX, 80.0f, 60.0f);
        }
    }
}

void func_80A0353C(EnElf* pthis, GlobalContext* globalCtx) {
    Vec3f parentPos;
    Actor* parent;

    SkelAnime_Update(&pthis->skelAnime);
    func_80A02A20(pthis, globalCtx);
    parent = pthis->actor.parent;

    if ((parent != NULL) && (parent->update != NULL)) {
        parentPos = pthis->actor.parent->world.pos;
        parentPos.y += ((1500.0f * pthis->actor.scale.y) + 40.0f);
        func_80A02C98(pthis, &parentPos, 0.2f);
    } else {
        Actor_Kill(&pthis->actor);
    }

    pthis->unk_2BC = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);
}

void func_80A03604(EnElf* pthis, GlobalContext* globalCtx) {
}

void func_80A03610(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToF(&pthis->unk_2B8, 30.0f, 0.1f, 4.0f, 1.0f);

    pthis->unk_28C.x = Math_CosS(pthis->unk_2AC) * pthis->unk_2B8;
    pthis->unk_28C.y = pthis->unk_28C.y + pthis->unk_2B4;

    switch (pthis->unk_2AA) {
        case 0:
            if (pthis->unk_2B4 < 2.0f) {
                pthis->unk_2B4 += 0.1f;
            } else {
                pthis->unk_2AA++;
            }
            break;
        case 1:
            if (pthis->unk_2B4 > -1.0f) {
                pthis->unk_2B4 -= 0.2f;
            }
    }

    pthis->unk_28C.z = Math_SinS(pthis->unk_2AC) * -pthis->unk_2B8;
    pthis->unk_2AC += pthis->unk_2B0;
    func_80A02C98(pthis, &player->actor.world.pos, 0.2f);

    if (pthis->unk_2B4 < 0.0f) {
        if ((pthis->unk_28C.y < 20.0f) && (pthis->unk_28C.y > 0.0f)) {
            Actor_SetScale(&pthis->actor, (pthis->unk_28C.y * 0.008f) * 0.05f);
        }
    }

    if (pthis->unk_28C.y < -10.0f) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->unk_2BC = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);
    EnElf_SpawnSparkles(pthis, globalCtx, 32);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FIATY_HEAL - SFX_FLAG);
}

void func_80A03814(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_28C.y > 200.0f) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (pthis->unk_2AE >= 0x7E) {
        pthis->unk_2B8 += 0.1f;
        pthis->unk_2B4 += 0.5f;
        pthis->unk_28C.y += pthis->unk_2B4;
    } else {
        pthis->unk_2AE++;

        if (pthis->unk_2B8 < 30.0f) {
            pthis->unk_2B8 += 0.5f;
        }

        if (pthis->unk_28C.y > 0.0f) {
            pthis->unk_28C.y -= 0.7f;
        }
    }

    pthis->unk_28C.x = Math_CosS(pthis->unk_2AC) * pthis->unk_2B8;
    pthis->unk_28C.z = Math_SinS(pthis->unk_2AC) * -pthis->unk_2B8;
    pthis->unk_2AC += pthis->unk_2B0;
    func_80A02E30(pthis, &player->bodyPartsPos[0]);
    pthis->unk_2BC = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);
    EnElf_SpawnSparkles(pthis, globalCtx, 32);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FIATY_HEAL - SFX_FLAG);
}

void func_80A03990(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    SkelAnime_Update(&pthis->skelAnime);

    pthis->unk_28C.z = 0.0f;
    pthis->unk_28C.x = 0.0f;
    pthis->unk_28C.y += pthis->unk_2B4;
    pthis->unk_2B4 -= 0.35f;

    if (pthis->unk_2B4 <= 0.0f) {
        EnElf_SetupAction(pthis, func_80A03814);
        pthis->unk_2B0 = 0x800;
        pthis->unk_2AE = 0;
        pthis->unk_2B4 = 0.0f;
        pthis->unk_2B8 = 1.0f;
    }

    func_80A02E30(pthis, &player->bodyPartsPos[0]);
    Actor_SetScale(&pthis->actor, (1.0f - (SQ(pthis->unk_2B4) * SQ(1.0f / 9.0f))) * 0.008f);
    pthis->unk_2BC = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);
    EnElf_SpawnSparkles(pthis, globalCtx, 32);
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FIATY_HEAL - SFX_FLAG);
}

void func_80A03AB0(EnElf* pthis, GlobalContext* globalCtx) {
    if (pthis->fairyFlags & 4) {
        func_80A04414(pthis, globalCtx);
    }

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->func_2C8 == NULL) {
        ASSERT(0, "0", "../z_en_elf.c", 1725);
    }

    pthis->func_2C8(pthis, globalCtx);
}

void EnElf_UpdateLights(EnElf* pthis, GlobalContext* globalCtx) {
    s16 glowLightRadius;
    Player* player;

    glowLightRadius = 100;

    if (pthis->unk_2A8 == 8) {
        glowLightRadius = 0;
    }

    if (pthis->fairyFlags & 0x20) {
        player = GET_PLAYER(globalCtx);
        Lights_PointNoGlowSetInfo(&pthis->lightInfoNoGlow, player->actor.world.pos.x,
                                  (s16)(player->actor.world.pos.y) + 60.0f, player->actor.world.pos.z, 255, 255, 255,
                                  200);
    } else {
        Lights_PointNoGlowSetInfo(&pthis->lightInfoNoGlow, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                                  pthis->actor.world.pos.z, 255, 255, 255, -1);
    }

    Lights_PointGlowSetInfo(&pthis->lightInfoGlow, pthis->actor.world.pos.x, pthis->actor.world.pos.y,
                            pthis->actor.world.pos.z, 255, 255, 255, glowLightRadius);

    pthis->unk_2BC = Math_Atan2S(pthis->actor.velocity.z, pthis->actor.velocity.x);

    Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
}

void func_80A03CF8(EnElf* pthis, GlobalContext* globalCtx) {
    Vec3f nextPos;
    Vec3f prevPos;
    Player* player = GET_PLAYER(globalCtx);
    Actor* arrowPointedActor;
    f32 xScale;
    f32 distFromLinksHead;

    func_80A0461C(pthis, globalCtx);
    func_80A03AB0(pthis, globalCtx);

    xScale = 0.0f;

    if ((globalCtx->csCtx.state != CS_STATE_IDLE) && (globalCtx->csCtx.npcActions[8] != NULL)) {
        EnElf_GetCutsceneNextPos(&nextPos, globalCtx, 8);

        if (globalCtx->csCtx.npcActions[8]->action == 5) {
            if (1) {}
            EnElf_SpawnSparkles(pthis, globalCtx, 16);
        }

        prevPos = pthis->actor.world.pos;

        if (pthis->unk_2A8 == 0xA) {
            func_80A02EC0(pthis, &nextPos);
        } else {
            func_80A02C98(pthis, &nextPos, 0.2f);
        }

        if ((globalCtx->sceneNum == SCENE_LINK_HOME) && (gSaveContext.sceneSetupIndex == 4)) {
            // play dash sound as Navi enters Links house in the intro
            if (1) {}
            if (globalCtx->csCtx.frames == 55) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FAIRY_DASH);
            }

            // play dash sound in intervals as Navi is waking up Link in the intro
            if (pthis->unk_2A8 == 6) {
                if (pthis->fairyFlags & 0x40) {
                    if (prevPos.y < pthis->actor.world.pos.y) {
                        pthis->fairyFlags &= ~0x40;
                    }
                } else {
                    if (pthis->actor.world.pos.y < prevPos.y) {
                        pthis->fairyFlags |= 0x40;
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FAIRY_DASH);
                    }
                }
            }
        }
    } else {
        distFromLinksHead = Math_Vec3f_DistXYZ(&player->bodyPartsPos[8], &pthis->actor.world.pos);

        switch (pthis->unk_2A8) {
            case 7:
                func_80A02C98(pthis, &player->bodyPartsPos[8], 1.0f - pthis->unk_2AE * (1.0f / 30.0f));
                xScale = Math_Vec3f_DistXYZ(&player->bodyPartsPos[8], &pthis->actor.world.pos);

                if (distFromLinksHead < 7.0f) {
                    pthis->unk_2C0 = 0;
                    xScale = 0.0f;
                } else if (distFromLinksHead < 25.0f) {
                    xScale = (xScale - 5.0f) * 0.05f;
                    xScale = 1.0f - xScale;
                    xScale = (1.0f - SQ(xScale)) * 0.008f;
                } else {
                    xScale = 0.008f;
                }
                EnElf_SpawnSparkles(pthis, globalCtx, 16);
                break;
            case 8:
                func_80A02C98(pthis, &player->bodyPartsPos[8], 0.2f);
                pthis->actor.world.pos = player->bodyPartsPos[8];
                func_80A029A8(pthis, 1);
                break;
            case 11:
                nextPos = player->bodyPartsPos[8];
                nextPos.y += 1500.0f * pthis->actor.scale.y;
                func_80A02E30(pthis, &nextPos);
                EnElf_SpawnSparkles(pthis, globalCtx, 16);

                if (pthis->unk_2B8 <= 19.0f) {
                    pthis->unk_2B8 += 1.0f;
                }

                if (pthis->unk_2B8 >= 21.0f) {
                    pthis->unk_2B8 -= 1.0f;
                }

                if (pthis->unk_2C0 < 0x20) {
                    pthis->unk_2B0 = (pthis->unk_2C0 * 0xF0) + 0x200;
                    func_80A0299C(pthis, 1);
                }
                break;
            case 12:
                nextPos = GET_ACTIVE_CAM(globalCtx)->eye;
                nextPos.y += (-2000.0f * pthis->actor.scale.y);
                func_80A03148(pthis, &nextPos, 0.0f, 20.0f, 0.2f);
                break;
            default:
                func_80A029A8(pthis, 1);
                nextPos = globalCtx->actorCtx.targetCtx.naviRefPos;
                nextPos.y += (1500.0f * pthis->actor.scale.y);
                arrowPointedActor = globalCtx->actorCtx.targetCtx.arrowPointedActor;

                if (arrowPointedActor != NULL) {
                    func_80A03148(pthis, &nextPos, 0.0f, 20.0f, 0.2f);

                    if (pthis->actor.speedXZ >= 5.0f) {
                        EnElf_SpawnSparkles(pthis, globalCtx, 16);
                    }
                } else {
                    if ((pthis->timer % 32) == 0) {
                        pthis->unk_2A0 = Rand_ZeroFloat(7.0f) + 3.0f;
                    }

                    if (pthis->fairyFlags & 2) {
                        if (distFromLinksHead < 30.0f) {
                            pthis->fairyFlags ^= 2;
                        }

                        func_80A03148(pthis, &nextPos, 0.0f, 20.0f, 0.2f);
                        EnElf_SpawnSparkles(pthis, globalCtx, 16);
                    } else {
                        if (distFromLinksHead > 100.0f) {
                            pthis->fairyFlags |= 2;

                            if (pthis->unk_2C7 == 0) {
                                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FAIRY_DASH);
                            }

                            pthis->unk_2C0 = 0x64;
                        }
                        func_80A03148(pthis, &nextPos, 0.0f, pthis->unk_2A0, 0.2f);
                    }
                }
                break;
        }
    }

    if (pthis->unk_2A8 == 7) {
        pthis->actor.scale.x = xScale;
    } else if (pthis->unk_2A8 == 8) {
        pthis->actor.scale.x = 0.0f;
    } else {
        Math_SmoothStepToF(&pthis->actor.scale.x, 0.008f, 0.3f, 0.00080000004f, 0.000080000005f);
    }

    EnElf_UpdateLights(pthis, globalCtx);
}

void EnElf_ChangeColor(Color_RGBAf* dest, Color_RGBAf* newColor, Color_RGBAf* curColor, f32 rate) {
    Color_RGBAf rgbaDiff;

    rgbaDiff.r = (newColor->r - curColor->r);
    rgbaDiff.g = (newColor->g - curColor->g);
    rgbaDiff.b = (newColor->b - curColor->b);
    rgbaDiff.a = (newColor->a - curColor->a);

    dest->r += (rgbaDiff.r * rate);
    dest->g += (rgbaDiff.g * rate);
    dest->b += (rgbaDiff.b * rate);
    dest->a += (rgbaDiff.a * rate);
}

void func_80A04414(EnElf* pthis, GlobalContext* globalCtx) {
    Actor* arrowPointedActor = globalCtx->actorCtx.targetCtx.arrowPointedActor;
    Player* player = GET_PLAYER(globalCtx);
    f32 transitionRate;
    u16 targetSound;

    if (globalCtx->actorCtx.targetCtx.unk_40 != 0.0f) {
        pthis->unk_2C6 = 0;
        pthis->unk_29C = 1.0f;

        if (pthis->unk_2C7 == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FAIRY_DASH);
        }

    } else {
        if (pthis->unk_2C6 == 0) {
            if ((arrowPointedActor == NULL) ||
                (Math_Vec3f_DistXYZ(&pthis->actor.world.pos, &globalCtx->actorCtx.targetCtx.naviRefPos) < 50.0f)) {
                pthis->unk_2C6 = 1;
            }
        } else if (pthis->unk_29C != 0.0f) {
            if (Math_StepToF(&pthis->unk_29C, 0.0f, 0.25f) != 0) {
                pthis->innerColor = globalCtx->actorCtx.targetCtx.naviInner;
                pthis->outerColor = globalCtx->actorCtx.targetCtx.naviOuter;
            } else {
                transitionRate = 0.25f / pthis->unk_29C;
                EnElf_ChangeColor(&pthis->innerColor, &globalCtx->actorCtx.targetCtx.naviInner, &pthis->innerColor,
                                  transitionRate);
                EnElf_ChangeColor(&pthis->outerColor, &globalCtx->actorCtx.targetCtx.naviOuter, &pthis->outerColor,
                                  transitionRate);
            }
        }
    }

    if (pthis->fairyFlags & 1) {
        if ((arrowPointedActor == NULL) || (player->unk_664 == NULL)) {
            pthis->fairyFlags ^= 1;
        }
    } else {
        if ((arrowPointedActor != NULL) && (player->unk_664 != NULL)) {
            if (arrowPointedActor->category == ACTORCAT_NPC) {
                targetSound = NA_SE_VO_NAVY_HELLO;
            } else {
                targetSound =
                    (arrowPointedActor->category == ACTORCAT_ENEMY) ? NA_SE_VO_NAVY_ENEMY : NA_SE_VO_NAVY_HEAR;
            }

            if (pthis->unk_2C7 == 0) {
                Audio_PlayActorSound2(&pthis->actor, targetSound);
            }

            pthis->fairyFlags |= 1;
        }
    }
}

void func_80A0461C(EnElf* pthis, GlobalContext* globalCtx) {
    s32 temp;
    Actor* arrowPointedActor;
    Player* player = GET_PLAYER(globalCtx);

    if (globalCtx->csCtx.state != CS_STATE_IDLE) {
        if (globalCtx->csCtx.npcActions[8] != NULL) {
            switch (globalCtx->csCtx.npcActions[8]->action) {
                case 4:
                    temp = 9;
                    break;
                case 3:
                    temp = 6;
                    break;
                case 1:
                    temp = 10;
                    break;
                default:
                    temp = 0;
                    break;
            }
        } else {
            temp = 0;
            pthis->unk_2C0 = 100;
        }

    } else {
        arrowPointedActor = globalCtx->actorCtx.targetCtx.arrowPointedActor;

        if ((player->stateFlags1 & 0x400) || ((YREG(15) & 0x10) && func_800BC56C(globalCtx, 2))) {
            temp = 12;
            pthis->unk_2C0 = 100;
        } else if (arrowPointedActor == NULL || arrowPointedActor->category == ACTORCAT_NPC) {
            if (arrowPointedActor != NULL) {
                pthis->unk_2C0 = 100;
                player->stateFlags2 |= 0x100000;
                temp = 0;
            } else {
                switch (pthis->unk_2A8) {
                    case 0:
                        if (pthis->unk_2C0 != 0) {
                            pthis->unk_2C0--;
                            temp = 0;
                        } else {
                            if (pthis->unk_2C7 == 0) {
                                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_NAVY_VANISH);
                            }
                            temp = 7;
                        }
                        break;
                    case 7:
                        if (pthis->unk_2C0 != 0) {
                            if (pthis->unk_2AE > 0) {
                                pthis->unk_2AE--;
                                temp = 7;
                            } else {
                                player->stateFlags2 |= 0x100000;
                                temp = 0;
                            }
                        } else {
                            temp = 8;
                            func_80A029A8(pthis, 10);
                        }
                        break;
                    case 8:
                        temp = 8;
                        break;
                    case 11:
                        temp = pthis->unk_2A8;
                        if (pthis->unk_2C0 > 0) {
                            pthis->unk_2C0--;
                        } else {
                            temp = 0;
                        }
                        break;
                    default:
                        temp = 0;
                        break;
                }
            }
        } else {
            temp = 1;
        }

        switch (temp) {
            case 0:
                if (!(player->stateFlags2 & 0x100000)) {
                    temp = 7;
                    if (pthis->unk_2C7 == 0) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_NAVY_VANISH);
                    }
                }
                break;
            case 8:
                if (player->stateFlags2 & 0x100000) {
                    func_80A0299C(pthis, 0x32);
                    pthis->unk_2C0 = 42;
                    temp = 11;
                    if (pthis->unk_2C7 == 0) {
                        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FAIRY_DASH);
                    }
                }
                break;
            case 7:
                player->stateFlags2 &= ~0x100000;
                break;
            default:
                player->stateFlags2 |= 0x100000;
                break;
        }
    }

    if (temp != pthis->unk_2A8) {
        func_80A01C38(pthis, temp);

        if (temp == 11) {
            pthis->unk_2B8 = Math_Vec3f_DistXZ(&player->bodyPartsPos[8], &pthis->actor.world.pos);
            pthis->unk_2AC = Math_Vec3f_Yaw(&pthis->actor.world.pos, &player->bodyPartsPos[8]);
        }
    }
}

void EnElf_SpawnSparkles(EnElf* pthis, GlobalContext* globalCtx, s32 sparkleLife) {
    s32 pad;
    Vec3f sparklePos;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;

    sparklePos.x = Rand_CenteredFloat(6.0f) + pthis->actor.world.pos.x;
    sparklePos.y = (Rand_ZeroOne() * 6.0f) + pthis->actor.world.pos.y;
    sparklePos.z = Rand_CenteredFloat(6.0f) + pthis->actor.world.pos.z;

    primColor.r = pthis->innerColor.r;
    primColor.g = pthis->innerColor.g;
    primColor.b = pthis->innerColor.b;

    envColor.r = pthis->outerColor.r;
    envColor.g = pthis->outerColor.g;
    envColor.b = pthis->outerColor.b;

    EffectSsKiraKira_SpawnDispersed(globalCtx, &sparklePos, &sparkleVelocity_105, &sparkleAccel_105, &primColor, &envColor,
                                    1000, sparkleLife);
}

void func_80A04D90(EnElf* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 bgId;

    pthis->actor.floorHeight = BgCheck_EntityRaycastFloor5(globalCtx, &globalCtx->colCtx, &pthis->actor.floorPoly, &bgId,
                                                          &pthis->actor, &pthis->actor.world.pos);
    pthis->actor.shape.shadowAlpha = 0x32;
}

// move to talk to player
void func_80A04DE4(EnElf* pthis, GlobalContext* globalCtx) {
    Vec3f headCopy;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f naviRefPos;

    if (pthis->fairyFlags & 0x10) {
        naviRefPos = globalCtx->actorCtx.targetCtx.naviRefPos;

        if ((player->unk_664 == NULL) || (&player->actor == player->unk_664) || (&pthis->actor == player->unk_664)) {
            naviRefPos.x = player->bodyPartsPos[7].x + (Math_SinS(player->actor.shape.rot.y) * 20.0f);
            naviRefPos.y = player->bodyPartsPos[7].y + 5.0f;
            naviRefPos.z = player->bodyPartsPos[7].z + (Math_CosS(player->actor.shape.rot.y) * 20.0f);
        }

        pthis->actor.focus.pos = naviRefPos;
        pthis->fairyFlags &= ~0x10;
    }

    func_80A03AB0(pthis, globalCtx);
    headCopy = pthis->actor.focus.pos;

    func_80A03148(pthis, &headCopy, 0, 20.0f, 0.2f);

    if (pthis->actor.speedXZ >= 5.0f) {
        EnElf_SpawnSparkles(pthis, globalCtx, 16);
    }

    Math_SmoothStepToF(&pthis->actor.scale.x, 0.008f, 0.3f, 0.00080000004f, 0.000080000005f);
    EnElf_UpdateLights(pthis, globalCtx);
}

// move after talking to player
void func_80A04F94(EnElf* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->unk_2BC, 5, 0x1000, 0x400);
    pthis->timer++;
    Math_StepToF(&pthis->unk_2A4, 1.0f, 0.05f);
    Environment_AdjustLights(globalCtx, SQ(pthis->unk_2A4), player->actor.projectedPos.z + 780.0f, 0.2f, 0.5f);
}

// ask to talk to saria again
void func_80A05040(Actor* thisx, GlobalContext* globalCtx) {
    EnElf* pthis = (EnElf*)thisx;

    func_80A04DE4(pthis, globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                Message_ContinueTextbox(globalCtx, ElfMessage_GetSariaText(globalCtx));
                pthis->actor.update = func_80A05114;
                break;
            case 1: // no
                Message_CloseTextbox(globalCtx);
                pthis->actor.update = func_80A053F0;
                func_80A01C38(pthis, 0);
                pthis->fairyFlags &= ~0x20;
                break;
        }
    }

    func_80A04F94(pthis, globalCtx);
}

void func_80A05114(Actor* thisx, GlobalContext* globalCtx) {
    EnElf* pthis = (EnElf*)thisx;

    func_80A04DE4(pthis, globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, 0xE3);
        pthis->actor.update = func_80A05040;
    }

    func_80A04F94(pthis, globalCtx);
}

void func_80A05188(Actor* thisx, GlobalContext* globalCtx) {
    EnElf* pthis = (EnElf*)thisx;

    func_80A04DE4(pthis, globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_ContinueTextbox(globalCtx, ElfMessage_GetSariaText(globalCtx));
        pthis->actor.update = func_80A05114;
    }

    func_80A04F94(pthis, globalCtx);
}

// ask to talk to navi
void func_80A05208(Actor* thisx, GlobalContext* globalCtx) {
    s32 naviCUpText;
    EnElf* pthis = (EnElf*)thisx;

    func_80A04DE4(pthis, globalCtx);

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                naviCUpText = ElfMessage_GetCUpText(globalCtx);

                if (naviCUpText != 0) {
                    Message_ContinueTextbox(globalCtx, naviCUpText);
                } else {
                    Message_ContinueTextbox(globalCtx, 0x15F);
                }

                pthis->actor.update = func_80A052F4;
                break;
            case 1: // no
                Message_CloseTextbox(globalCtx);
                pthis->actor.update = func_80A053F0;
                func_80A01C38(pthis, 0);
                pthis->fairyFlags &= ~0x20;
                break;
        }
    }

    func_80A04F94(pthis, globalCtx);
}

// ask to talk to saria
void func_80A052F4(Actor* thisx, GlobalContext* globalCtx) {
    EnElf* pthis = (EnElf*)thisx;

    func_80A04DE4(pthis, globalCtx);

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE) {
        if (Message_ShouldAdvance(globalCtx)) {
            globalCtx->msgCtx.unk_E3F2 = 0xFF;

            switch (globalCtx->msgCtx.choiceIndex) {
                case 0: // yes
                    pthis->actor.update = func_80A05188;
                    Message_ContinueTextbox(globalCtx, 0xE2);
                    break;
                case 1: // no
                    pthis->actor.update = func_80A05208;
                    Message_ContinueTextbox(globalCtx, 0xE1);
                    break;
            }
        }
    } else if (Actor_TextboxIsClosing(thisx, globalCtx)) {
        pthis->actor.update = func_80A053F0;
        func_80A01C38(pthis, 0);
        pthis->fairyFlags &= ~0x20;
    }

    func_80A04F94(pthis, globalCtx);
}

void func_80A053F0(Actor* thisx, GlobalContext* globalCtx) {
    u8 unk2C7;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    EnElf* pthis = (EnElf*)thisx;

    if (player->naviTextId == 0) {
        if (player->unk_664 == NULL) {
            if (((gSaveContext.naviTimer >= 600) && (gSaveContext.naviTimer <= 3000)) || (nREG(89) != 0)) {
                player->naviTextId = ElfMessage_GetCUpText(globalCtx);

                if (player->naviTextId == 0x15F) {
                    player->naviTextId = 0;
                }
            }
        }
    } else if (player->naviTextId < 0) {
        // trigger dialog instantly for negative message IDs
        thisx->flags |= ACTOR_FLAG_16;
    }

    if (Actor_ProcessTalkRequest(thisx, globalCtx)) {
        func_800F4524(&gAudioDefaultPos, NA_SE_VO_SK_LAUGH, 0x20);
        thisx->focus.pos = thisx->world.pos;

        if (thisx->textId == ElfMessage_GetCUpText(globalCtx)) {
            pthis->fairyFlags |= 0x80;
            gSaveContext.naviTimer = 3001;
        }

        pthis->fairyFlags |= 0x10;
        pthis->fairyFlags |= 0x20;
        thisx->update = func_80A052F4;
        func_80A01C38(pthis, 3);

        if (pthis->elfMsg != NULL) {
            pthis->elfMsg->actor.flags |= ACTOR_FLAG_8;
        }

        thisx->flags &= ~ACTOR_FLAG_16;
    } else {
        pthis->actionFunc(pthis, globalCtx);
        thisx->shape.rot.y = pthis->unk_2BC;
        nREG(80) = gSaveContext.sceneFlags[127].chest;

        if (nREG(81) != 0) {
            if (gSaveContext.sceneFlags[127].chest) {
                LOG_NUM("z_common_data.memory.information.room_inf[127][ 0 ]", gSaveContext.sceneFlags[127].chest,
                        "../z_en_elf.c", 2595);
            }
        }

        if (!Gameplay_InCsMode(globalCtx)) {
            if (gSaveContext.naviTimer < 25800) {
                gSaveContext.naviTimer++;
            } else if (!(pthis->fairyFlags & 0x80)) {
                gSaveContext.naviTimer = 0;
            }
        }
    }

    pthis->elfMsg = NULL;
    pthis->timer++;

    if (pthis->unk_2A4 > 0.0f) {
        Math_StepToF(&pthis->unk_2A4, 0.0f, 0.05f);
        Environment_AdjustLights(globalCtx, SQ(pthis->unk_2A4) * pthis->unk_2A4, player->actor.projectedPos.z + 780.0f,
                                 0.2f, 0.5f);
    }

    // temp probably fake match
    unk2C7 = pthis->unk_2C7;
    if (unk2C7 > 0) {
        pthis->unk_2C7--;
    }

    if ((pthis->unk_2C7 == 0) && (globalCtx->csCtx.state != CS_STATE_IDLE)) {
        pthis->unk_2C7 = 1;
    }

    func_80A04D90(pthis, globalCtx);
}

void EnElf_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnElf* pthis = (EnElf*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.shape.rot.y = pthis->unk_2BC;
    pthis->timer++;

    if (pthis->fairyFlags & FAIRY_FLAG_BIG) {
        func_80A04D90(pthis, globalCtx);
    }
}

s32 EnElf_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                           Gfx** gfx) {
    s32 pad;
    f32 scale;
    Vec3f mtxMult;
    EnElf* pthis = (EnElf*)thisx;

    if (limbIndex == 8) {
        scale = ((Math_SinS(pthis->timer * 4096) * 0.1f) + 1.0f) * 0.012f;

        if (pthis->fairyFlags & FAIRY_FLAG_BIG) {
            scale *= 2.0f;
        }

        scale *= (pthis->actor.scale.x * 124.99999f);
        Matrix_MultVec3f(&zeroVec_121, &mtxMult);
        Matrix_Translate(mtxMult.x, mtxMult.y, mtxMult.z, MTXMODE_NEW);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    }

    // do not draw wings for big fairies
    if (pthis->fairyFlags & FAIRY_FLAG_BIG) {
        if (limbIndex == 4 || limbIndex == 7 || limbIndex == 11 || limbIndex == 14) {
            *dList = NULL;
        }
    }

    return false;
}

void EnElf_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    f32 alphaScale;
    s32 envAlpha;
    EnElf* pthis = (EnElf*)thisx;
    s32 pad1;
    Gfx* dListHead;
    Player* player = GET_PLAYER(globalCtx);

    if ((pthis->unk_2A8 != 8) && !(pthis->fairyFlags & 8)) {
        if (!(player->stateFlags1 & 0x100000) || (kREG(90) < pthis->actor.projectedPos.z)) {
            dListHead = (Gfx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Gfx) * 4);

            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_elf.c", 2730);

            func_80094B58(globalCtx->state.gfxCtx);

            envAlpha = (pthis->timer * 50) & 0x1FF;
            envAlpha = (envAlpha > 255) ? 511 - envAlpha : envAlpha;

            alphaScale = pthis->disappearTimer < 0 ? (pthis->disappearTimer * (7.0f / 6000.0f)) + 1.0f : 1.0f;

            gSPSegment(POLY_XLU_DISP++, 0x08, dListHead);
            gDPPipeSync(dListHead++);
            gDPSetPrimColor(dListHead++, 0, 0x01, (u8)pthis->innerColor.r, (u8)pthis->innerColor.g,
                            (u8)pthis->innerColor.b, (u8)(pthis->innerColor.a * alphaScale));

            if (pthis->fairyFlags & 4) {
                gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_CLD_SURF2);
            } else {
                gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
            }

            gSPEndDisplayList(dListHead++);
            gDPSetEnvColor(POLY_XLU_DISP++, (u8)pthis->outerColor.r, (u8)pthis->outerColor.g, (u8)pthis->outerColor.b,
                           (u8)(envAlpha * alphaScale));
            POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                                           EnElf_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);

            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_elf.c", 2793);
        }
    }
}

void EnElf_GetCutsceneNextPos(Vec3f* vec, GlobalContext* globalCtx, s32 action) {
    Vec3f startPos;
    Vec3f endPos;
    CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[action];
    f32 lerp;

    startPos.x = npcAction->startPos.x;
    startPos.y = npcAction->startPos.y;
    startPos.z = npcAction->startPos.z;

    endPos.x = npcAction->endPos.x;
    endPos.y = npcAction->endPos.y;
    endPos.z = npcAction->endPos.z;

    lerp = Environment_LerpWeight(npcAction->endFrame, npcAction->startFrame, globalCtx->csCtx.frames);

    vec->x = ((endPos.x - startPos.x) * lerp) + startPos.x;
    vec->y = ((endPos.y - startPos.y) * lerp) + startPos.y;
    vec->z = ((endPos.z - startPos.z) * lerp) + startPos.z;
}

void EnElf_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sparkleVelocity_105 = { 0.0f, -0.05f, 0.0f };

    sparkleAccel_105 = { 0.0f, -0.025f, 0.0f };

    zeroVec_121 = { 0.0f, 0.0f, 0.0f };

    En_Elf_InitVars = {
        ACTOR_EN_ELF,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnElf),
        (ActorFunc)EnElf_Init,
        (ActorFunc)EnElf_Destroy,
        (ActorFunc)EnElf_Update,
        (ActorFunc)EnElf_Draw,
        (ActorFunc)EnElf_Reset,
    };

}

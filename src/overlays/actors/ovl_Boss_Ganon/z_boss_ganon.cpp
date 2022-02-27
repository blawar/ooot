#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_GANON_Z_BOSS_GANON_C
#include "actor_common.h"
#include "z_kankyo.h"
#include "z_boss_ganon.h"
#include "overlays/ovl_Boss_Ganon/ovl_Boss_Ganon.h"
#include "overlays/actors/ovl_En_Ganon_Mant/z_en_ganon_mant.h"
#include "overlays/actors/ovl_En_Zl3/z_en_zl3.h"
#include "overlays/actors/ovl_Bg_Ganon_Otyuka/z_bg_ganon_otyuka.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/object_ganon/object_ganon.h"
#include "objects/object_ganon_anime1/object_ganon_anime1.h"
#include "objects/object_ganon_anime2/object_ganon_anime2.h"
#include "scenes/dungeons/ganon_boss/ganon_boss_scene.h"
#include "def/code_8006BA00.h"
#include "def/code_800A9F30.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/cosf.h"
#include "def/graph.h"
#include "def/sinf.h"
#include "def/sys_math_atan.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BossGanon_Init(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BossGanon_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Update(Actor* thisx, GlobalContext* globalCtx);
void BossGanon_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_808E1EB4(Actor* thisx, GlobalContext* globalCtx); // update
void func_808E2544(Actor* thisx, GlobalContext* globalCtx); // update
void BossGanon_LightBall_Update(Actor* thisx, GlobalContext* globalCtx);
void func_808E229C(Actor* thisx, GlobalContext* globalCtx); // draw
void func_808E324C(Actor* thisx, GlobalContext* globalCtx); // draw
void BossGanon_LightBall_Draw(Actor* thisx, GlobalContext* globalCtx);

void BossGanon_SetupIntroCutscene(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_SetupTowerCutscene(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_IntroCutscene(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_DeathAndTowerCutscene(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_Wait(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_ChargeLightBall(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_PlayTennis(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_PoundFloor(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_ChargeBigMagic(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_Block(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_HitByLightBall(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_Vulnerable(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_Damaged(BossGanon* pthis, GlobalContext* globalCtx);

void BossGanon_SetupWait(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_SetupChargeLightBall(BossGanon* pthis, GlobalContext* globalCtx);
void BossGanon_SetupPlayTennis(BossGanon* pthis, GlobalContext* globalCtx);

void BossGanon_DrawEffects(GlobalContext* globalCtx);
void BossGanon_UpdateEffects(GlobalContext* globalCtx);

s32 BossGanon_CheckFallingPlatforms(BossGanon* pthis, GlobalContext* globalCtx, Vec3f* checkPos);

static Color_RGB8 shardColors_87[] = { { 255, 175, 85 }, { 155, 205, 155 }, { 155, 125, 55 } };

static Color_RGBA8 bloodPrimColor_109 = { 0, 120, 0, 255 };

static Color_RGBA8 bloodEnvColor_109 = { 0, 120, 0, 255 };

static AnimationHeader* volleyAnims_119[] = { &gDorfVolleyLeftAnim, &gDorfVolleyRightAnim };

static s16 capeRightArmDurations_119[] = { 26, 20 };

static s8 bodyPartLimbMap_132[] = {
    -1, -1, 1, -1, 3, 4, 5, -1, 6, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, 2, 12, 13, 14, 9, 10, 11, -1, -1, -1, -1,
};

static Vec3f D_808E4DA0_132 = { -500.0f, 200.0f, -300.0f };

static Vec3f D_808E4DAC_132 = { -500.0f, 200.0f, 300.0f };

static Vec3f D_808E4DB8_132 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_808E4DC4_132 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_808E4DD0_132 = { 0.0f, 0.0f, 0.0f };

static Vec3f D_808E4DDC_132 = { 1300.0f, 0.0f, 0.0f };

static Vec3f D_808E4DE8_132 = { 600.0f, 420.0f, 100.0f };

static s16 D_808E4DF4_140[] = { 1, 2, 3, 3, 2, 1 };

static s16 D_808E4E00_140[] = { 2, 3, 4, 4, 4, 3, 2 };

static s16 D_808E4E10_140[] = { 2, 3, 4, 4, 4, 4, 3, 2 };

static s16 D_808E4E20_140[] = { 2, 4, 5, 5, 6, 6, 6, 6, 5, 5, 4, 2 };

static s16 D_808E4E38_140[] = { 1, -1, 1, 1, 3, 4, 1, 6, 7, 2, 9, 10, 2, 12, 13 };

static u8 D_808E4E58_140[] = { 3, 2, 2, 1, 3, 3, 1, 3, 3, 1, 0, 3, 1, 0, 3 };


ActorInit Boss_Ganon_InitVars = {
    ACTOR_BOSS_GANON,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_GANON,
    sizeof(BossGanon),
    (ActorFunc)BossGanon_Init,
    (ActorFunc)BossGanon_Destroy,
    (ActorFunc)BossGanon_Update,
    (ActorFunc)BossGanon_Draw,
    (ActorFunc)BossGanon_Reset,
};

static ColliderCylinderInit sDorfCylinderInit = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0xFFCFFFFE, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 20, 80, -50, { 0, 0, 0 } },
};

static ColliderCylinderInit sLightBallCylinderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK6,
        { 0x00100700, 0x00, 0x08 },
        { 0x0D900740, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 20, 30, -15, { 0, 0, 0 } },
};

static u8 D_808E4C58[] = { 0, 12, 10, 12, 14, 16, 12, 14, 16, 12, 14, 16, 12, 14, 16, 10, 16, 14 };
static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

static EnGanonMant* sCape;

static s32 sSeed1;
static s32 sSeed2;
static s32 sSeed3;

static BossGanon* sGanondorf;

static EnZl3* sZelda;         

GanondorfEffect sEffectBuf[200];

void BossGanonEff_SpawnWindowShard(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, f32 scale) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;
    Color_RGB8* color;

    for (i = 0; i < 200; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_WINDOW_SHARD;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = sZeroVec;
            eff->scale = scale;
            eff->accel.y = -1.5f;
            eff->unk_44 = Rand_ZeroFloat(6.28f);
            eff->unk_48 = Rand_ZeroFloat(6.28f);
            color = &shardColors_87[(s16)Rand_ZeroFloat(2.99f)];
            eff->color.r = color->r;
            eff->color.g = color->g;
            eff->color.b = color->b;
            eff->timer = (s16)Rand_ZeroFloat(20.0f);
            break;
        }
    }
}

void BossGanonEff_SpawnSparkle(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 scale,
                               s16 arg6) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_SPARKLE;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = *accel;
            eff->scale = scale / 1000.0f;
            eff->unk_2E = (s16)Rand_ZeroFloat(100.0f) + 0xC8;
            eff->unk_30 = arg6;
            eff->timer = (s16)Rand_ZeroFloat(10.0f);
            break;
        }
    }
}

void BossGanonEff_SpawnLightRay(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 scale,
                                f32 arg5, s16 arg6) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_LIGHT_RAY;
            eff->pos = *pos;
            eff->velocity = *velocity;
            eff->accel = *accel;
            eff->scale = scale / 1000.0f;
            eff->unk_38 = 1.0f;
            eff->unk_40 = arg5;
            eff->unk_2E = (s16)Rand_ZeroFloat(100.0f) + 0xC8;
            eff->unk_30 = arg6;
            eff->timer = (s16)Rand_ZeroFloat(10.0f);
            eff->unk_48 = Math_Atan2F(eff->velocity.z, eff->velocity.x);
            eff->unk_44 = -Math_Atan2F(sqrtf(SQXZ(eff->velocity)), eff->velocity.y);
            break;
        }
    }
}

void BossGanonEff_SpawnShock(GlobalContext* globalCtx, f32 scale, s16 shockType) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 75; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_SHOCK;
            eff->pos = sZeroVec;
            eff->pos.y = -2000.0f;
            eff->velocity = sZeroVec;
            eff->accel = sZeroVec;
            eff->scale = scale / 1000.0f;
            eff->unk_2E = shockType;
            eff->timer = 0;
            break;
        }
    }
}

void BossGanonEff_SpawnLightning(GlobalContext* globalCtx, f32 scale, f32 arg2, f32 arg3) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_LIGHTNING;
            eff->velocity = sZeroVec;
            eff->accel = sZeroVec;
            eff->unk_2E = 0;
            eff->scale = scale;
            eff->unk_48 = arg2;
            eff->unk_3C = arg3;
            eff->timer = 0;
            break;
        }
    }
}

void BossGanonEff_SpawnDustDark(GlobalContext* globalCtx, Vec3f* pos, f32 scale, f32 arg3) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_IMPACT_DUST_DARK;
            eff->pos = *pos;
            eff->velocity = sZeroVec;
            eff->accel = sZeroVec;
            eff->scale = scale;
            eff->unk_40 = 1.0f;
            eff->unk_38 = arg3;
            eff->unk_30 = (s16)Rand_ZeroFloat(100.0f);
            eff->unk_2E = eff->timer = eff->alpha = 0;
            break;
        }
    }
}

void BossGanonEff_SpawnDustLight(GlobalContext* globalCtx, Vec3f* pos, f32 scale, f32 arg3, s16 bufIndex) {
    GanondorfEffect* effArr = (GanondorfEffect*)globalCtx->specialEffects;

    effArr[bufIndex].type = GDF_EFF_IMPACT_DUST_LIGHT;
    effArr[bufIndex].pos = *pos;
    effArr[bufIndex].velocity = sZeroVec;
    effArr[bufIndex].accel = sZeroVec;
    effArr[bufIndex].unk_40 = 1.0f;
    effArr[bufIndex].scale = scale;
    effArr[bufIndex].unk_38 = arg3;
    effArr[bufIndex].unk_30 = Rand_ZeroFloat(100.0f);
    effArr[bufIndex].unk_2E = effArr[bufIndex].timer = effArr[bufIndex].alpha = 0;
}

void BossGanonEff_SpawnShockwave(GlobalContext* globalCtx, Vec3f* pos, f32 scale, f32 arg3) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_SHOCKWAVE;
            eff->pos = *pos;
            eff->velocity = sZeroVec;
            eff->accel = sZeroVec;
            eff->alpha = 255;
            eff->unk_40 = 0.6f;
            eff->scale = scale;
            eff->unk_38 = arg3;
            eff->unk_30 = (s16)Rand_ZeroFloat(100.0f);
            eff->unk_2E = eff->timer = 0;
            break;
        }
    }
}

void BossGanonEff_SpawnBlackDot(GlobalContext* globalCtx, Vec3f* pos, f32 scale) {
    s16 i;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_NONE) {
            eff->type = GDF_EFF_BLACK_DOT;
            eff->pos = *pos;
            eff->velocity = sZeroVec;
            eff->accel = sZeroVec;
            eff->unk_38 = 0.0f;
            eff->scale = scale / 1000.0f;
            eff->timer = 0;
            eff->alpha = 0;
            eff->unk_2E = 0;
            break;
        }
    }
}

void BossGanon_SetColliderPos(Vec3f* pos, ColliderCylinder* collider) {
    collider->dim.pos.x = pos->x;
    collider->dim.pos.y = pos->y;
    collider->dim.pos.z = pos->z;
}

void BossGanon_SetAnimationObject(BossGanon* pthis, GlobalContext* globalCtx, s32 objectId) {
    pthis->animBankIndex = Object_GetIndex(&globalCtx->objectCtx, objectId);
    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->animBankIndex].vromStart.get());
}

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x3D, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void BossGanon_Init(Actor* thisx, GlobalContext* globalCtx2) {
    s16 i;
    GlobalContext* globalCtx = globalCtx2;
    BossGanon* pthis = (BossGanon*)thisx;
    s32 cond;
    f32 xDistFromPlayer;
    f32 yDistFromPlayer;
    f32 zDistFromPlayer;
    Player* player = GET_PLAYER(globalCtx);

    if (thisx->params < 0x64) {
        Flags_SetSwitch(globalCtx, 0x14);
        globalCtx->specialEffects = sEffectBuf;

        for (i = 0; i < ARRAY_COUNT(sEffectBuf); i++) {
            sEffectBuf[i].type = GDF_EFF_NONE;
        }

        sGanondorf = pthis;
        thisx->colChkInfo.health = 40;
        Actor_ProcessInitChain(thisx, sInitChain);
        ActorShape_Init(&thisx->shape, 0, NULL, 0);
        Actor_SetScale(thisx, 0.01f);
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gDorfSkel, NULL, NULL, NULL, 0);
        Collider_InitCylinder(globalCtx, &pthis->collider);
        Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sDorfCylinderInit);

        if (thisx->params != 1) {
            BossGanon_SetupIntroCutscene(pthis, globalCtx);
            pthis->organAlpha = 255;
        } else {
            cond = Flags_GetSwitch(globalCtx, 0x37) &&
                   ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                    (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO));

            if (!cond) {
                BossGanon_SetupTowerCutscene(pthis, globalCtx);
            } else {
                Actor_Kill(thisx);
                return;
            }

            BossGanon_SetupTowerCutscene(pthis, globalCtx);
        }

        sCape = (EnGanonMant*)Actor_SpawnAsChild(&globalCtx->actorCtx, thisx, globalCtx, ACTOR_EN_GANON_MANT, 0.0f,
                                                 0.0f, 0.0f, 0, 0, 0, 1);
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_BOSS);
    } else {
        thisx->flags &= ~ACTOR_FLAG_0;
        pthis->fwork[GDF_FWORK_1] = 255.0f;

        if (thisx->params >= 0xC8) {
            if (thisx->params == 0x12C) {
                thisx->update = BossGanon_LightBall_Update;
                thisx->draw = BossGanon_LightBall_Draw;
                pthis->unk_1A8 = 2;
            } else if (thisx->params == 0x190) {
                thisx->update = BossGanon_LightBall_Update;
                thisx->draw = BossGanon_LightBall_Draw;
                pthis->unk_1A8 = 1;
            } else if (thisx->params >= 0x104) {
                // big magic light ball thrown
                thisx->update = func_808E2544;
                thisx->draw = func_808E324C;
                pthis->unk_1C2 = 10;
                pthis->unk_1A2 = 520 + (-thisx->params * 2);

                for (i = 0; i < 15; i++) {
                    pthis->unk_2EC[i] = thisx->world.pos;
                }

                pthis->timers[1] = 3;
                Collider_InitCylinder(globalCtx, &pthis->collider);
                Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sLightBallCylinderInit);
            } else if (thisx->params >= 0xFA) {
                // big magic light ball charge
                thisx->update = func_808E2544;
                thisx->draw = func_808E324C;
                pthis->unk_1A2 = Rand_ZeroFloat(10000.0f);

                for (i = 0; i < 15; i++) {
                    pthis->unk_2EC[i] = thisx->world.pos;
                }

                pthis->fwork[GDF_FWORK_1] = 0;
            } else {
                thisx->update = func_808E1EB4;
                thisx->draw = func_808E229C;
                if (1) {}
                thisx->speedXZ = 11.0f;

                if (thisx->params == 0xC8) {
                    pthis->timers[0] = 7;
                } else {
                    pthis->timers[0] = (s16)Rand_ZeroFloat(3.0f) + 3;
                }

                for (i = 0; i < 15; i++) {
                    pthis->unk_2EC[i].y = 5000.0f;
                }
            }
        } else {
            // light ball (anything from 0x64 - 0xC7)
            thisx->update = BossGanon_LightBall_Update;
            thisx->draw = BossGanon_LightBall_Draw;
            thisx->speedXZ = 12.0f;

            xDistFromPlayer = player->actor.world.pos.x - thisx->world.pos.x;
            yDistFromPlayer = (player->actor.world.pos.y + 30.0f) - thisx->world.pos.y;
            zDistFromPlayer = player->actor.world.pos.z - thisx->world.pos.z;

            thisx->world.rot.y = Math_Atan2S(zDistFromPlayer, xDistFromPlayer);
            thisx->world.rot.x = Math_Atan2S(sqrtf(SQ(xDistFromPlayer) + SQ(zDistFromPlayer)), yDistFromPlayer);

            if (Rand_ZeroOne() < 0) {
                thisx->world.rot.y += (s16)Rand_CenteredFloat(5000.0f);
                thisx->world.rot.x += (s16)Rand_CenteredFloat(5000.0f);
            }

            pthis->timers[1] = 3;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, thisx, &sLightBallCylinderInit);
        }
    }
}

void BossGanon_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon* pthis = (BossGanon*)thisx;

    if ((pthis->actor.params < 0xC8) || (pthis->actor.params >= 0x104)) {
        Collider_DestroyCylinder(globalCtx, &pthis->collider);
    }

    if (pthis->actor.params < 0x64) {
        SkelAnime_Free(&pthis->skelAnime, globalCtx);
    }
}

void BossGanon_SetupIntroCutscene(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 animBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (animBankIndex < 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if (Object_IsLoaded(&globalCtx->objectCtx, animBankIndex)) {
        pthis->actionFunc = BossGanon_IntroCutscene;
        pthis->unk_198 = 1;
        pthis->animBankIndex = animBankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[animBankIndex].vromStart.get());
        Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_005FFC, 0.0f);
    } else {
        pthis->actionFunc = BossGanon_SetupIntroCutscene;
    }
} 

static CutsceneCameraPosition sIntroCsCameraPositions[] = {
    { { 0, 40, 0 }, { 0, 50, 430 } },
    { { -20, 30, 400 }, { 10, 55, 440 } },
    { { 0, 60, 300 }, { 0, 273, -150 } },
    { { 0, 180, -260 }, { 0, 155, -300 } },
    { { -30, 60, 440 }, { 20, 25, 390 } },
    { { -50, 140, -360 }, { 50, 92, -390 } },
    { { -10, 264, -121 }, { 5, 266, -160 } },
    { { -13, 200, -310 }, { 0, 125, -410 } },
    { { 0, 40, -50 }, { 0, 35, 230 } },
    { { 0, 140, -250 }, { 0, 115, -570 } },
    { { -410, 150, -130 }, { 50, 155, -170 } },
    { { 0, 130, -230 }, { 0, 125, -2000 } },
    { { -2, 147, -293 }, { -200, 345, -2000 } },
};

void BossGanon_SetIntroCsCamera(BossGanon* pthis, u8 camPosIndex) {
    CutsceneCameraPosition* camPos = &sIntroCsCameraPositions[camPosIndex];

    pthis->csCamEye.x = camPos->eye.x;
    pthis->csCamEye.y = camPos->eye.y;
    pthis->csCamEye.z = camPos->eye.z;

    pthis->csCamAt.x = camPos->at.x;
    pthis->csCamAt.y = camPos->at.y;
    pthis->csCamAt.z = camPos->at.z;
}

void BossGanon_IntroCutscene(BossGanon* pthis, GlobalContext* globalCtx) {
    u8 moveCam = false;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    f32 sin;
    f32 cos;
    Camera* mainCam;

    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->animBankIndex].vromStart.get());

    sCape->backPush = -2.0f;
    sCape->backSwayMagnitude = 0.25f;
    sCape->sideSwayMagnitude = -1.0f;
    sCape->minDist = 0.0f;

    pthis->csTimer++;

    SkelAnime_Update(&pthis->skelAnime);

    switch (pthis->csState) {
        case 0:
            player->actor.world.pos.x = 0.0f;
            player->actor.world.pos.y = 0.0f;
            player->actor.world.pos.z = 430.0f;

            pthis->actor.world.pos.x = 0.0f;
            pthis->actor.world.pos.y = 112.0f;
            pthis->actor.world.pos.z = -333.0f;

            pthis->actor.shape.yOffset = -7000.0f;
            pthis->actor.shape.rot.y = 0;

            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &pthis->actor, 8);
            pthis->csCamIndex = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->csCamIndex, CAM_STAT_ACTIVE);
            pthis->csCamFov = 60.0f;

            if (gSaveContext.eventChkInf[7] & 0x100) {
                // watched cutscene already, skip most of it
                pthis->csState = 17;
                pthis->csTimer = 0;
                player->actor.world.pos.z = 20.0f;
                pthis->useOpenHand = false;
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_0089F8, -5.0f);
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
                BossGanon_SetIntroCsCamera(pthis, 11);
                pthis->unk_198 = 2;
                pthis->timers[2] = 110;
                gSaveContext.healthAccumulator = 0x140;
                Audio_QueueSeqCmd(NA_BGM_STOP);
            } else {
                pthis->useOpenHand = true;
                BossGanon_SetIntroCsCamera(pthis, 0);
                pthis->csState = 1;
                sZelda = (EnZl3*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ZL3, 0.0f,
                                                    220.0f, -150.0f, 0, 0, 0, 0x2000);
            }

            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_GANON_ORGAN, 0.0f, 0.0f, 0.0f, 0,
                               0, 0, 1);
            sCape->minY = 57.0f;
            // fallthrough
        case 1:
            pthis->envLightMode = 3;
            if (pthis->csTimer == 70) {
                pthis->csState = 2;
                pthis->csTimer = 0;
            }
            break;

        case 2:
            BossGanon_SetIntroCsCamera(pthis, 1);

            if (pthis->csTimer == 10) {
                func_8002DF54(globalCtx, &pthis->actor, 5);
            }

            if (pthis->csTimer == 13) {
                func_8002F7DC(&player->actor, player->ageProperties->unk_92 + NA_SE_VO_LI_SURPRISE);
            }

            if (pthis->csTimer != 35) {
                break;
            }

            pthis->csState = 3;
            pthis->csTimer = 0;

            pthis->csCamEye.x = 0.0f;
            pthis->csCamEye.y = 60.0f;
            pthis->csCamEye.z = 300.0f;

            pthis->csCamAt.x = 0.0f;
            pthis->unk_704 = 1.2566371f;
            // fallthrough
        case 3:
            pthis->envLightMode = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            pthis->csCamAt.y = (sinf(pthis->unk_704) * 300.0f) + pthis->csCamEye.y;
            pthis->csCamAt.z = (cosf(pthis->unk_704) * -300.0f) + pthis->csCamEye.z;
            Math_ApproachF(&pthis->unk_704, 0.25f, 0.05f, pthis->csCamAtMaxStep.y);
            Math_ApproachF(&pthis->csCamAtMaxStep.y, 0.01f, 1.0f, 0.0001f);

            if (pthis->csTimer != 200) {
                break;
            }

            func_8002DF54(globalCtx, &pthis->actor, 8);
            pthis->csState = 4;
            BossGanon_SetIntroCsCamera(pthis, 2);
            pthis->csTimer = 0;
            // fallthrough
        case 4:
            if ((pthis->csTimer == 0) || (pthis->csTimer == 10) || (pthis->csTimer == 20)) {
                pthis->csCamEye.y += 68.0f;
                pthis->csCamEye.z -= 142.0f;
            }

            if (pthis->csTimer >= 20) {
                pthis->envLightMode = 4;
            } else {
                pthis->envLightMode = 35;
            }

            if (pthis->csTimer == 60) {
                BossGanon_SetIntroCsCamera(pthis, 1);
                pthis->csState = 5;
                pthis->csTimer = 0;
            }
            break;

        case 5:
            pthis->envLightMode = 5;

            if (pthis->csTimer < 50) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            if (pthis->csTimer == 10) {
                func_8002DF54(globalCtx, &pthis->actor, 0x4B);
            }

            if (pthis->csTimer == 70) {
                BossGanon_SetIntroCsCamera(pthis, 3);
                pthis->csState = 6;
                pthis->csTimer = 0;
                pthis->envLightMode = 3;
            }
            break;

        case 6:
            pthis->envLightMode = 3;

            if (pthis->csTimer != 30) {
                break;
            }

            pthis->csState = 7;
            pthis->csTimer = 0;
            BossGanon_SetIntroCsCamera(pthis, 4);
            pthis->triforceType = GDF_TRIFORCE_PLAYER;
            pthis->fwork[GDF_TRIFORCE_SCALE] = 10.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_A] = 0.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_B] = 255.0f;
            pthis->fwork[GDF_TRIFORCE_ENV_G] = 100.0f;
            func_80078884(NA_SE_EV_TRIFORCE_MARK);
            globalCtx->envCtx.unk_D8 = 0.0f;
            // fallthrough
        case 7:
            pthis->envLightMode = 6;
            // fade in links triforce
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_A], 255.0f, 1.0f, 10.0f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_SCALE], 0.4f, 1.0f, 0.3f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_B], 170.0f, 1.0f, 2.55f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_ENV_G], 200.0f, 1.0f, 3.0f);

            if (pthis->csTimer >= 30) {
                pthis->envLightMode = 65;
            }

            if (pthis->csTimer == 30) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            BossGanon_SetIntroCsCamera(pthis, 4);
            pthis->csCamEye.x += 5.0f;
            pthis->csCamEye.z += -10.0f;
            pthis->csCamAt.x += 18.0f;

            if (pthis->csTimer == 60) {
                pthis->csState = 8;
                pthis->csTimer = 0;
            }
            break;

        case 8:
            pthis->envLightMode = 3;
            BossGanon_SetIntroCsCamera(pthis, 5);

            if (pthis->csTimer != 30) {
                break;
            }

            pthis->csState = 9;
            pthis->csTimer = 0;
            func_8002DF54(globalCtx, &pthis->actor, 8);
            sZelda->unk_3C8 = 0;
            pthis->triforceType = GDF_TRIFORCE_ZELDA;
            pthis->fwork[GDF_TRIFORCE_SCALE] = 10.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_A] = 0.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_B] = 255.0f;
            pthis->fwork[GDF_TRIFORCE_ENV_G] = 100.0f;
            func_80078884(NA_SE_EV_TRIFORCE_MARK);
            globalCtx->envCtx.unk_D8 = 0.0f;
            // fallthrough
        case 9:
            pthis->envLightMode = 7;
            BossGanon_SetIntroCsCamera(pthis, 6);
            // fade in zeldas triforce
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_A], 255.0f, 1.0f, 10.0f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_SCALE], 0.4f, 1.0f, 0.3f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_B], 170.0f, 1.0f, 2.55f);
            Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_ENV_G], 200.0f, 1.0f, 3.0f);

            if (pthis->csTimer == 30) {
                sZelda->unk_3C8 = 1;
            }

            if (pthis->csTimer >= 32) {
                pthis->envLightMode = 75;
            }

            if (pthis->csTimer == 32) {
                globalCtx->envCtx.unk_D8 = 1.0f;
            }

            if (pthis->csTimer == 50) {
                pthis->csState = 10;
                pthis->csTimer = 0;
            }
            break;

        case 10: // top view of playing the organ
            pthis->envLightMode = 3;
            BossGanon_SetIntroCsCamera(pthis, 7);

            if (pthis->csTimer == 40) {
                pthis->csState = 11;
                pthis->csTimer = 0;
                pthis->fwork[GDF_TRIFORCE_PRIM_A] = 0.0f;
            }
            break;

        case 11: // link is healed
            pthis->envLightMode = 3;
            BossGanon_SetIntroCsCamera(pthis, 8);
            player->actor.world.pos.z = 20.0f;

            if (pthis->csTimer == 20) {
                func_8002DF54(globalCtx, &pthis->actor, 0x17);
                Interface_ChangeAlpha(11); // show hearts only
            }

            if (pthis->csTimer == 25) {
                gSaveContext.healthAccumulator = 0x140;
            }

            if (pthis->csTimer == 100) {
                Interface_ChangeAlpha(1);
            }

            if (pthis->csTimer == 120) {
                pthis->csState = 12;
                pthis->csTimer = 0;
            }
            break;

        case 12: // first dialogue, ganondorf facing away from link
            pthis->envLightMode = 3;
            BossGanon_SetIntroCsCamera(pthis, 9);

            if (pthis->csTimer == 30) {
                Audio_QueueSeqCmd(0x100100FF);
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_004F64);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_004F64, -5.0f);
            }

            if ((pthis->csTimer > 30) && Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_006AF4, 0.0f);
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
            }

            if (pthis->csTimer == 80) {
                Message_StartTextbox(globalCtx, 0x70C8, NULL);
            }

            if ((pthis->csTimer > 180) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 15;
                pthis->csTimer = 0;
                pthis->useOpenHand = false;
            }
            break;

        case 15: // side view of all 3 of them
            pthis->envLightMode = 0;
            globalCtx->envCtx.unk_D8 = 0.0f;
            BossGanon_SetIntroCsCamera(pthis, 10);

            if (pthis->csTimer == 30) {
                Message_StartTextbox(globalCtx, 0x70C9, NULL);
            }

            if ((pthis->csTimer > 100) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 16;
                pthis->csTimer = 0;
                BossGanon_SetIntroCsCamera(pthis, 11);
                pthis->unk_198 = 2;
                sZelda->unk_3C8 = 2;
                pthis->timers[2] = 110;
                pthis->envLightMode = 3;
            }
            break;

        case 16:
            pthis->envLightMode = 3;

            if (pthis->csTimer <= 20) {
                if (pthis->csTimer == 20) {
                    Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_004304, -5.0f);
                    pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_004304);
                }
            } else if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                Message_StartTextbox(globalCtx, 0x70CA, NULL);
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_0089F8, -5.0f);
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
            }

            if ((pthis->csTimer > 100) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 17;
                pthis->csTimer = 0;
            }
            break;

        case 17: // turns around
            pthis->envLightMode = 3;

            if (pthis->csTimer == 20) {
                Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_001F58, -5.0f);
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_001F58);
            }

            if (pthis->csTimer > 10) {
                if (pthis->csTimer == 62) {
                    sCape->attachRightArmTimer = 20.0f;
                }

                if (pthis->csTimer == 57) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
                }

                Math_ApproachF(&pthis->csCamFov, 110.0f, 0.1f, pthis->csCamMaxStepScale * 2.0f);
                Math_ApproachF(&pthis->csCamEye.z, -290.0f, 0.1f, pthis->csCamMaxStepScale * 2.4f);
                Math_ApproachF(&pthis->csCamMaxStepScale, 0.75f, 1.0f, 0.05f);

                if (pthis->csTimer == 70) {
                    pthis->csState = 18;
                    pthis->csTimer = 0;
                    pthis->csCamFov = 60.0f;
                    BossGanon_SetIntroCsCamera(pthis, 12);
                    Message_StartTextbox(globalCtx, 0x70CB, NULL);
                }
            }
            break;

        case 18: // last dialog before triforce
            pthis->envLightMode = 3;
            BossGanon_SetIntroCsCamera(pthis, 12);
            pthis->csCamEye.y += -6.0f;
            pthis->csCamEye.z += 6.0f;

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1] - 5.0f)) {
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_003018, -5.0f);
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
            }

            if ((pthis->csTimer <= 50) || (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_NONE)) {
                break;
            }

            pthis->csState = 19;
            pthis->csTimer = 0;
            Message_StartTextbox(globalCtx, 0x70CC, NULL);
            Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_007268, -5.0f);
            pthis->triforceType = GDF_TRIFORCE_DORF;
            pthis->fwork[GDF_TRIFORCE_SCALE] = 10.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_A] = 0.0f;
            pthis->fwork[GDF_TRIFORCE_PRIM_B] = 255.0f;
            pthis->fwork[GDF_TRIFORCE_ENV_G] = 100.0f;
            globalCtx->envCtx.unk_D8 = 0.0f;
            // fallthrough
        case 19: // show triforce
            pthis->envLightMode = 8;

            if (pthis->csTimer >= 60) {
                pthis->envLightMode = 9;

                if (pthis->csTimer == 60) {
                    globalCtx->envCtx.unk_D8 = 1.0f;
                }
            }

            BossGanon_SetIntroCsCamera(pthis, 12);
            pthis->csCamEye.y += -6.0f;
            pthis->csCamEye.z += 6.0f;

            if (pthis->csTimer >= 30) {
                if (pthis->csTimer == 30) {
                    func_80078884(NA_SE_EV_TRIFORCE_MARK);
                }

                // fade in ganondorf's triforce
                Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_A], 255.0f, 1.0f, 10.0f);
                Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_SCALE], 0.6f, 1.0f, 0.3f);
                Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_PRIM_B], 170.0f, 1.0f, 2.55f);
                Math_ApproachF(&pthis->fwork[GDF_TRIFORCE_ENV_G], 200.0f, 1.0f, 3.0f);
            }

            if (pthis->csTimer == 17) {
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_007A64, -5.0f);
            }

            if ((pthis->csTimer > 80) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 20;
                pthis->csTimer = 0;

                pthis->csCamTargetEye.x = pthis->csCamEye.x - 50.0f;
                pthis->csCamTargetEye.y = pthis->csCamEye.y - 100.0f;
                pthis->csCamTargetEye.z = pthis->csCamEye.z + 400.0f;

                pthis->csCamEyeMaxStep.x = 50.0f;
                pthis->csCamEyeMaxStep.y = 100.0f;
                pthis->csCamEyeMaxStep.z = 400.0f;

                pthis->csCamAtMaxStep.x = 400.0f;
                pthis->csCamMaxStepScale = 0.0f;

                pthis->csCamTargetAt.x = pthis->csCamAt.x + 400.0f;
                pthis->csCamTargetAt.y = pthis->csCamAt.y;
                pthis->csCamTargetAt.z = pthis->csCamAt.z;

                pthis->csCamMovementScale = 0.2f;

                pthis->fwork[GDF_VORTEX_ALPHA] = 0.0f;
                pthis->fwork[GDF_VORTEX_SCALE] = 0.1f;

                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DARKWAVE);
            }
            break;

        case 20: // zoom cam out
            pthis->envLightMode = 10;
            moveCam = true;
            Math_ApproachF(&pthis->csCamMaxStepScale, 0.15f, 1.0f, 0.015f);

            if (pthis->csTimer <= 40) {
                Math_ApproachF(&pthis->fwork[GDF_VORTEX_ALPHA], 255.0f, 1.0f, 6.5f);
                Math_ApproachF(&pthis->fwork[GDF_VORTEX_SCALE], 0.2f, 1.0f, 0.025f);
            }

            if (pthis->csTimer > 20) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            }

            if (pthis->csTimer > 20) {
                BossGanonEff_SpawnShock(globalCtx, 700.0f, GDF_SHOCK_PLAYER_PURPLE);
                BossGanonEff_SpawnShock(globalCtx, 700.0f, GDF_SHOCK_PLAYER_PURPLE);
            }

            if (pthis->csTimer == 30) {
                func_8002DF54(globalCtx, &pthis->actor, 0x4A);
            }

            if (pthis->csTimer <= 50) {
                break;
            }

            pthis->csState = 21;
            pthis->csTimer = 0;
            pthis->fwork[GDF_TRIFORCE_PRIM_A] = 0.0f;
            pthis->fwork[GDF_VORTEX_SCALE] = 0.16f;
            goto skip_sound_and_fx;

        case 21: // purple vortex
            pthis->envLightMode = 11;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DARKWAVE_M - SFX_FLAG);
            BossGanonEff_SpawnShock(globalCtx, 700.0f, GDF_SHOCK_PLAYER_PURPLE);
            BossGanonEff_SpawnShock(globalCtx, 700.0f, GDF_SHOCK_PLAYER_PURPLE);

        skip_sound_and_fx:
            pthis->csCamEye.x = -30.0f;
            pthis->csCamEye.y = 37.0f;
            pthis->csCamEye.z = -30.0f;

            pthis->csCamAt.x = -10.0f;
            pthis->csCamAt.y = 45.0f;
            pthis->csCamAt.z = 0.0f;

            if (pthis->csTimer == 13) {
                Message_StartTextbox(globalCtx, 0x70CD, NULL);
            }

            if ((pthis->csTimer <= 120) || (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_NONE)) {
                break;
            }

            pthis->csState = 22;
            pthis->csTimer = 0;
            pthis->timers[2] = 30;
            pthis->organAlpha = 254;
            pthis->csCamAt.x = pthis->unk_1FC.x - 10.0f;
            pthis->csCamAt.y = pthis->unk_1FC.y + 30.0f;
            pthis->csCamAt.z = pthis->unk_1FC.z;
            pthis->fwork[GDF_VORTEX_ALPHA] = 255.0f;
            pthis->fwork[GDF_VORTEX_SCALE] = 0.2f;
            // fallthrough
        case 22: // start floating, show title card, start fight
            if (pthis->csTimer > 30) {
                pthis->envLightMode = 0;
            } else {
                pthis->envLightMode = 12;
            }

            Math_ApproachZeroF(&pthis->fwork[GDF_VORTEX_ALPHA], 1.0f, 10.0f);

            pthis->csCamEye.x = -30.0f;
            pthis->csCamEye.y = 137.0f;
            pthis->csCamEye.z = -110.0f;

            Math_ApproachF(&pthis->csCamAt.y, pthis->unk_1FC.y + 30.0f, 0.1f, 20.0f);
            Math_ApproachF(&pthis->csCamAt.x, pthis->unk_1FC.x - 10.0f, 0.1f, 5.0f);

            if (pthis->csTimer == 20) {
                BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp3Anim, 0.0f);
                SkelAnime_Update(&pthis->skelAnime);
                pthis->actor.shape.yOffset = 0.0f;
                sCape->attachShouldersTimer = 18.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
                pthis->unk_198 = 0;
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_GANONDORF_BOSS);
            }

            if (pthis->csTimer == 50) {
                gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON)].vromStart.get());

                if (!(gSaveContext.eventChkInf[7] & 0x100)) {
                    TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx,
                                           SEGMENTED_TO_VIRTUAL(gDorfTitleCardTex), 160, 180, 128, 40);
                }

                gSaveContext.eventChkInf[7] |= 0x100;
            }

            if (pthis->csTimer >= 20) {
                pthis->legSwayEnabled = true;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_FLOAT - SFX_FLAG);

                Math_ApproachF(&pthis->actor.world.pos.y, 228.0f, 0.05f, 2.0f);
                Math_ApproachF(&pthis->actor.world.pos.z, -230.0f, 0.05f, 4.0f);

                sCape->backPush = -3.0f;
                sCape->backSwayMagnitude = 0.25f;
                sCape->sideSwayMagnitude = -3.0f;

                sin = Math_SinS(pthis->csTimer * 1500);
                pthis->actor.velocity.y = pthis->fwork[GDF_FWORK_0] * sin * 0.04f;
                pthis->actor.world.pos.y += pthis->actor.velocity.y;

                cos = Math_CosS(pthis->csTimer * 1800);
                pthis->actor.world.pos.x = pthis->fwork[GDF_FWORK_0] * cos * 0.5f;
                pthis->actor.velocity.x = pthis->actor.world.pos.x - pthis->actor.prevPos.x;

                Math_ApproachF(&pthis->fwork[GDF_FWORK_0], 50.0f, 1.0f, 1.0f);
            }

            if (pthis->csTimer > 30) {
                pthis->organAlpha -= 5;

                if (pthis->organAlpha < 0) {
                    pthis->organAlpha = 0;
                }
            }

            if (pthis->csTimer == 120) {
                mainCam = Gameplay_GetCamera(globalCtx, MAIN_CAM);
                mainCam->eye = pthis->csCamEye;
                mainCam->eyeNext = pthis->csCamEye;
                mainCam->at = pthis->csCamAt;
                func_800C08AC(globalCtx, pthis->csCamIndex, 0);
                pthis->csState = pthis->csCamIndex = 0;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, &pthis->actor, 7);
                BossGanon_SetupWait(pthis, globalCtx);
            }

            if (sZelda != NULL) {
                sZelda->actor.world.pos.x = 0.0f;
                sZelda->actor.world.pos.y = 350.0f;
                sZelda->actor.world.pos.z = 0.0f;
            }
    }

    if (pthis->csCamIndex != 0) {
        if (moveCam) {
            Math_ApproachF(&pthis->csCamEye.x, pthis->csCamTargetEye.x, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.x * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamEye.y, pthis->csCamTargetEye.y, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.y * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamEye.z, pthis->csCamTargetEye.z, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.z * pthis->csCamMaxStepScale);

            Math_ApproachF(&pthis->csCamAt.x, pthis->csCamTargetAt.x, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.x * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamAt.y, pthis->csCamTargetAt.y, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.y * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamAt.z, pthis->csCamTargetAt.z, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.z * pthis->csCamMaxStepScale);
        }

        Gameplay_CameraSetAtEye(globalCtx, pthis->csCamIndex, &pthis->csCamAt, &pthis->csCamEye);
        Gameplay_CameraSetFov(globalCtx, pthis->csCamIndex, pthis->csCamFov);
    }
}

void BossGanon_SetupDeathCutscene(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 animBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (Object_IsLoaded(&globalCtx->objectCtx, animBankIndex)) {
        pthis->actionFunc = BossGanon_DeathAndTowerCutscene;
        pthis->csTimer = pthis->csState = 0;
        pthis->unk_198 = 1;
        pthis->animBankIndex = animBankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[animBankIndex].vromStart.get());
        Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_00EA00, 0.0f);
        pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_00EA00);
        pthis->unk_508 = 0.0f;
    }
}

void BossGanon_SetupTowerCutscene(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s32 animBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GANON_ANIME2);

    if (Object_IsLoaded(&globalCtx->objectCtx, animBankIndex)) {
        pthis->animBankIndex = animBankIndex;
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[animBankIndex].vromStart.get());
        Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_00EA00, 0.0f);
        pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_00EA00);
        pthis->actionFunc = BossGanon_DeathAndTowerCutscene;
        pthis->csTimer = 0;
        pthis->csState = 100;
        pthis->unk_198 = 1;
        gSaveContext.magic = gSaveContext.unk_13F4;
        gSaveContext.health = gSaveContext.healthCapacity;
    } else {
        pthis->actionFunc = BossGanon_SetupTowerCutscene;
    }
}

void BossGanon_ShatterWindows(u8 windowShatterState) {
    s16 i;
    u8* tex1 = SEGMENTED_TO_VIRTUAL(ganon_boss_sceneTex_006C18);
    u8* tex2 = SEGMENTED_TO_VIRTUAL(ganon_boss_sceneTex_007418);

    for (i = 0; i < 2048; i++) {
        if ((tex1[i] != 0) && (Rand_ZeroOne() < 0.03f)) {
            if ((((u8*)gDorfWindowShatterTemplateTex)[i] == 0) || (windowShatterState == GDF_WINDOW_SHATTER_FULL)) {
                tex1[i] = tex2[i] = 1;
            }
        }
    }
}

void BossGanon_DeathAndTowerCutscene(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;
    u8 moveCam = false;
    Player* player = GET_PLAYER(globalCtx);
    s16 pad;
    Vec3f sp98;
    Vec3f sp8C;
    Vec3f sp80;
    Vec3f sp74;
    Camera* mainCam;
    Vec3f sp64;

    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->animBankIndex].vromStart.get());

    pthis->csTimer++;
    SkelAnime_Update(&pthis->skelAnime);

    switch (pthis->csState) {
        case 0:
            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &pthis->actor, 8);
            pthis->csCamIndex = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->csCamIndex, CAM_STAT_ACTIVE);

            pthis->actor.world.pos.x = 0.0f;
            pthis->actor.world.pos.y = 70.0f;
            pthis->actor.world.pos.z = -80.0f;

            pthis->actor.shape.yOffset = -7000.0f;

            pthis->actor.shape.rot.y = 0;
            pthis->csState = 1;
            pthis->csTimer = 0;
            pthis->useOpenHand = true;
            // fallthrough
        case 1:
            player->actor.shape.rot.y = -0x8000;

            player->actor.world.pos.x = -10.0f;
            player->actor.world.pos.y = 0.0f;
            player->actor.world.pos.z = 115.0f;

            pthis->envLightMode = 13;

            if (pthis->csTimer < 30) {
                globalCtx->envCtx.unk_D8 = 0.0f;
            }

            if (pthis->csTimer >= 2) {
                globalCtx->envCtx.fillScreen = false;
            }

            pthis->csCamEye.x = -50.0f;
            pthis->csCamEye.z = -50.0f;
            pthis->csCamEye.y = 50.0f;

            pthis->csCamAt.x = pthis->unk_1FC.x;
            pthis->csCamAt.y = pthis->unk_1FC.y + 30.0f;
            pthis->csCamAt.z = pthis->unk_1FC.z;

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_00F19C, 0.0f);
                pthis->csState = 2;
                pthis->csTimer = 0;
            }
            break;

        case 2:
            pthis->csCamEye.x = -100.0f;
            pthis->csCamEye.y = 20.0f;
            pthis->csCamEye.z = -130.0f;

            pthis->envLightMode = 13;

            pthis->csCamAt.x = pthis->unk_1FC.x;
            pthis->csCamAt.y = pthis->unk_1FC.y;
            pthis->csCamAt.z = pthis->unk_1FC.z + 40.0f;

            if (pthis->csTimer >= 30) {
                pthis->csState = 3;
                pthis->csTimer = 0;
                Message_StartTextbox(globalCtx, 0x70CE, NULL);
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
            }

            if ((pthis->unk_1A2 % 32) == 0) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BREATH);
            }
            break;

        case 3:
            pthis->envLightMode = 14;

            if ((pthis->fwork[GDF_FWORK_1] > 100.0f) && ((pthis->unk_1A2 % 32) == 0)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BREATH);
            }

            pthis->csCamEye.x = 7.0f;
            pthis->csCamEye.y = 52.0f;
            pthis->csCamEye.z = -15.0f;

            pthis->csCamAt.x = pthis->unk_1FC.x - 5.0f;
            pthis->csCamAt.y = pthis->unk_1FC.y + 30.0f - 10.0f;
            pthis->csCamAt.z = pthis->unk_1FC.z;

            if ((pthis->fwork[GDF_FWORK_1] > 100.0f) && (pthis->csTimer > 100) &&
                (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_00B668, 0.0f);
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_00B668);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_TOKETU);
            } else {
                if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1] - 16.0f)) {
                    for (i = 0; i < 40; i++) {
                        sp98.x = Rand_CenteredFloat(5.0f);
                        sp98.y = Rand_CenteredFloat(1.5f) + 1.0f;
                        sp98.z = Rand_ZeroFloat(5.0f) + 2.0f;

                        sp8C.x = 0.0f;
                        sp8C.y = -1.0f;
                        sp8C.z = 0.0f;

                        sp80.x = pthis->unk_208.x;
                        sp80.y = pthis->unk_208.y - 10.0f;
                        sp80.z = pthis->unk_208.z;

                        func_8002836C(globalCtx, &sp80, &sp98, &sp8C, &bloodPrimColor_109, &bloodEnvColor_109,
                                      (s16)Rand_ZeroFloat(50.0f) + 50, 0, 17);
                    }
                }

                if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                    Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_00BE38, 0.0f);
                    pthis->csState = 4;
                    pthis->csTimer = 0;
                }
            }
            break;

        case 4:
            pthis->envLightMode = 14;

            if (pthis->csTimer == 30) {
                Message_StartTextbox(globalCtx, 0x70CF, NULL);
                pthis->csState = 5;
                pthis->csTimer = 0;
            }
            break;

        case 5:
            pthis->envLightMode = 14;

            if ((pthis->csTimer > 70) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 6;
                pthis->csTimer = 0;
                Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_010298, 0.0f);
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_010298);

                pthis->csCamMovementScale = 0.05f;
                pthis->csCamMaxStepScale = 0.0f;

                pthis->csCamTargetEye.x = 7.0f;
                pthis->csCamTargetEye.y = 12.0f;
                pthis->csCamTargetEye.z = 70.0f;

                pthis->csCamTargetAt.x = pthis->unk_1FC.x - 5.0f;
                pthis->csCamTargetAt.y = (pthis->unk_1FC.y + 30.0f) - 10.0f;
                pthis->csCamTargetAt.z = pthis->unk_1FC.z;

                pthis->csCamEyeMaxStep.x = fabsf(pthis->csCamEye.x - pthis->csCamTargetEye.x);
                pthis->csCamEyeMaxStep.y = fabsf(pthis->csCamEye.y - pthis->csCamTargetEye.y);
                pthis->csCamEyeMaxStep.z = fabsf(pthis->csCamEye.z - pthis->csCamTargetEye.z);

                pthis->csCamAtMaxStep.x = fabsf(pthis->csCamAt.x - pthis->csCamTargetAt.x);
                pthis->csCamAtMaxStep.y = fabsf(pthis->csCamAt.y - pthis->csCamTargetAt.y);
                pthis->csCamAtMaxStep.z = fabsf(pthis->csCamAt.z - pthis->csCamTargetAt.z);

                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_CASBREAK);
            }
            break;

        case 6:
            pthis->envLightMode = 14;
            moveCam = true;
            Math_ApproachF(&pthis->csCamMaxStepScale, 0.2f, 1.0f, 0.01f);

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                Animation_MorphToLoop(&pthis->skelAnime, &object_ganon_anime2_Anim_010514, 0.0f);
                pthis->csState = 7;
                pthis->csTimer = 0;
                pthis->unk_2E8 = 0;
                pthis->envLightMode = 15;
                pthis->unk_508 = 0.0f;
                pthis->fwork[GDF_FWORK_1] = 1000.0f;
                globalCtx->envCtx.unk_D8 = 0.0f;
            }
            break;

        case 7:
            if (pthis->csTimer < 10) {
                globalCtx->envCtx.unk_D8 = 0.0f;
            }

            if (pthis->csTimer == 30) {
                pthis->csState = 8;
                pthis->csTimer = 0;
                pthis->unk_70C = 0.0f;
            }
            goto skip_cam_and_quake;

        case 8:
            pthis->csCamEye.x = -60.0f;
            pthis->csCamEye.y = 80.0f;
            pthis->csCamEye.z = -130.0f;

            pthis->csCamAt.x = 0.0f;
            pthis->csCamAt.y = 0.0f;
            pthis->csCamAt.z = 70.0f;

            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.2f;

            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

        skip_cam_and_quake:
            pthis->envLightMode = 15;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BODY_SPARK - SFX_FLAG);

            for (i = 1; i < 15; i++) {
                pthis->unk_4E4[i] = 0xA;
            }

            pthis->unk_2E6 = 20000;
            Math_ApproachF(&pthis->unk_508, 5.0f, 0.05f, 0.1f);

            if (pthis->csTimer == 30) {
                pthis->csState = 9;
                pthis->csTimer = 0;

                pthis->csCamEye.x = -30.0f;
                pthis->csCamEye.y = 40.0f;
                pthis->csCamEye.z = 60.0f;

                pthis->csCamAt.x = 492.0f;
                pthis->csCamAt.y = 43.0f;
                pthis->csCamAt.z = 580.0f;

                pthis->csCamMaxStepScale = 0.0f;
                pthis->unk_710 = 10.0f;
            }
            break;

        case 9:
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BODY_SPARK - SFX_FLAG);

            if (pthis->csTimer == 2) {
                func_8002DF54(globalCtx, &pthis->actor, 0x39);
            }

            if (pthis->csTimer > 50) {
                Math_ApproachZeroF(&pthis->unk_710, 1.0f, 0.2f);
                Math_ApproachF(&pthis->csCamEye.x, 270.0f, 0.05f, pthis->csCamMaxStepScale * 30.0f);
                Math_ApproachF(&pthis->csCamEye.z, 260.0f, 0.05f, pthis->csCamMaxStepScale * 20.0f);
                Math_ApproachF(&pthis->csCamAt.y, 103.0f, 0.05f, pthis->csCamMaxStepScale * 6.0f);
                Math_ApproachF(&pthis->csCamAt.z, 280.0f, 0.05f, pthis->csCamMaxStepScale * 20.0f);
                Math_ApproachF(&pthis->csCamMaxStepScale, 1.0f, 1.0f, 0.01f);
            }

            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * pthis->unk_710;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            if (pthis->csTimer < 100) {
                pthis->windowShatterState = GDF_WINDOW_SHATTER_PARTIAL;
                pthis->envLightMode = 15;
            } else {
                pthis->envLightMode = 16;
                pthis->windowShatterState = GDF_WINDOW_SHATTER_FULL;
            }

            if (pthis->csTimer >= 130) {
                Math_ApproachF(&pthis->whiteFillAlpha, 255.0f, 1.0f, 5.0f);
            }

            if (pthis->csTimer == 180) {
                globalCtx->sceneLoadFlag = 0x14;
                globalCtx->nextEntranceIndex = 0x43F;
                globalCtx->fadeTransition = 5;
            }
            break;

        case 100:
            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &pthis->actor, 8);
            pthis->csCamIndex = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->csCamIndex, CAM_STAT_ACTIVE);
            Animation_MorphToPlayOnce(&pthis->skelAnime, &object_ganon_anime2_Anim_00ADDC, 0.0f);
            pthis->fwork[1] = Animation_GetLastFrame(&object_ganon_anime2_Anim_00EA00);
            pthis->csState = 101;
            pthis->skelAnime.playSpeed = 0.0f;
            sZelda = (EnZl3*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_ZL3, 0.0f,
                                                6000.0f, 0.0f, 0, 0, 0, 0x2000);

            player->actor.world.pos.x = -472.0f;
            player->actor.world.pos.y = 4102.0f;
            player->actor.world.pos.z = -130.0f;

            player->actor.shape.rot.y = -0x8000;

            pthis->actor.world.pos.x = -472.0f;
            pthis->actor.world.pos.y = 4172.0f;
            pthis->actor.world.pos.z = -400.0f;

            pthis->actor.shape.yOffset = -7000.0f;
            pthis->actor.shape.rot.y = 0;

            pthis->csCamEye.x = pthis->csCamAt.x = -472.0f;
            pthis->csCamEye.y = pthis->csCamAt.y = 4152.0f;
            pthis->csCamEye.z = -160.0f;

            pthis->csCamAt.z = -100.0f;

            sCape->backPush = -2.0f;
            sCape->backSwayMagnitude = 0.25f;
            sCape->sideSwayMagnitude = -1.0f;
            sCape->minDist = 0.0f;
            sCape->minY = 4104.0f;
            sCape->tearTimer = 20;

            pthis->whiteFillAlpha = 255.0f;
            globalCtx->envCtx.unk_D8 = 1.0f;
            // fallthrough
        case 101:
            player->actor.world.pos.y = 4102.0f;
            Math_ApproachZeroF(&pthis->whiteFillAlpha, 1.0f, 5.0f);

            if (pthis->csTimer > 40) {
                Math_ApproachF(&pthis->csCamEye.z, -520.0f, 0.1f, pthis->csCamMaxStepScale);
                Math_ApproachF(&pthis->csCamMaxStepScale, 5.0f, 1.0f, 0.1f);

                if (pthis->csTimer == 150) {
                    pthis->skelAnime.playSpeed = 1.0f;
                }

                if (pthis->csTimer == 160) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_BOUND_NOWEAPON);
                }

                if (pthis->csTimer == 187) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_BODY_HIT);
                }

                if (pthis->csTimer == 180) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
                }

                if (pthis->csTimer == 190) {
                    sp74 = pthis->actor.world.pos;
                    sp74.y = 4102.0f;
                    BossGanonEff_SpawnDustDark(globalCtx, &sp74, 0.2f, 0.7f);
                }

                if (pthis->csTimer == 230) {
                    pthis->csState = 102;
                    pthis->csTimer = 0;
                }
            }
            break;

        case 102:
            player->actor.world.pos.y = 4102.0f;

            pthis->csCamEye.x = -442.0f;
            pthis->csCamEye.y = 4152.0f;
            pthis->csCamEye.z = -135.0f;

            pthis->csCamAt.x = -472.0f;
            pthis->csCamAt.y = 4152.0f;
            pthis->csCamAt.z = -135.0f;

            if (pthis->csTimer == 5) {
                func_8002DF54(globalCtx, &pthis->actor, 0x4C);
            }

            if (pthis->csTimer == 70) {
                func_8002DF54(globalCtx, &pthis->actor, 0x4D);
            }

            if (pthis->csTimer == 90) {
                pthis->csState = 103;
                pthis->csTimer = 0;
                sZelda->actor.world.pos.x = -472.0f;
                sZelda->actor.world.pos.y = 4352.0f;
                sZelda->actor.world.pos.z = -200.0f;
                sZelda->unk_3C8 = 3;
            }
            break;

        case 103:
            Audio_PlayActorSound2(&sZelda->actor, NA_SE_EV_DOWN_TO_GROUND - SFX_FLAG);
            Math_ApproachF(&sZelda->actor.world.pos.y, 4102.0f, 0.05f, 1.5f);

            pthis->csCamEye.x = -242.0f;
            pthis->csCamEye.y = 4122.0f;
            pthis->csCamEye.z = -190.0f;

            pthis->csCamAt.x = sZelda->actor.world.pos.x;
            pthis->csCamAt.y = sZelda->actor.world.pos.y + 40.0f + 5.0f;
            pthis->csCamAt.z = sZelda->actor.world.pos.z;

            if (pthis->csTimer == 200) {
                sZelda->actor.world.pos.y = 4102.0f;
                pthis->csState = 104;
                pthis->csTimer = 0;
            } else {
                break;
            }
            // fallthrough
        case 104:
            pthis->csCamEye.x = -432.0f;
            pthis->csCamEye.y = 4147.0f;
            pthis->csCamEye.z = -200.0f;

            pthis->csCamAt.x = sZelda->actor.world.pos.x;
            pthis->csCamAt.y = sZelda->actor.world.pos.y + 40.0f + 5.0f;
            pthis->csCamAt.z = sZelda->actor.world.pos.z;

            if (pthis->csTimer >= 10) {
                Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            }

            if (pthis->csTimer == 10) {
                sZelda->unk_3C8 = 8;
            }

            if (pthis->csTimer == 50) {
                sZelda->unk_3C8 = 4;
            }

            if (pthis->csTimer == 100) {
                pthis->csState = 105;
                pthis->csTimer = 0;
            }
            break;

        case 105:
            pthis->csCamEye.x = -450.0f;
            pthis->csCamEye.y = 4154.0f;
            pthis->csCamEye.z = -182.0f;

            pthis->csCamAt.x = sZelda->actor.world.pos.x - 5.0f;
            pthis->csCamAt.y = sZelda->actor.world.pos.y + 40.0f + 5.0f;
            pthis->csCamAt.z = sZelda->actor.world.pos.z - 25.0f;

            if (pthis->csTimer == 10) {
                Message_StartTextbox(globalCtx, 0x70D0, NULL);
            }

            if ((pthis->csTimer > 100) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 1055;
                pthis->csTimer = 0;
            }
            break;

        case 1055:
            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.3f;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            if (pthis->csTimer == 20) {
                sZelda->unk_3C8 = 5;
                func_8002DF54(globalCtx, &pthis->actor, 0x39);
            }

            if (pthis->csTimer == 40) {
                pthis->csState = 1056;
                pthis->csTimer = 0;
            }
            break;

        case 1056:
            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.3f;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            pthis->csCamEye.x = -503.0f;
            pthis->csCamEye.y = 4128.0f;
            pthis->csCamEye.z = -162.0f;

            pthis->csCamAt.x = -416.0f;
            pthis->csCamAt.y = 4181.0f;
            pthis->csCamAt.z = -75.0f;

            if (pthis->csTimer > 40) {
                pthis->csState = 1057;
                pthis->csTimer = 0;
            }
            break;

        case 1057:
            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * (50.0f * pthis->csCamMovementScale);
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            Math_ApproachF(&pthis->csCamEye.x, -1200.0f, 0.1f, pthis->csCamMovementScale * 697.0f);
            Math_ApproachF(&pthis->csCamEye.y, 4241.0f, 0.1f, pthis->csCamMovementScale * 113.0f);
            Math_ApproachF(&pthis->csCamEye.z, -1048.0f, 0.1f, pthis->csCamMovementScale * 886.0f);

            Math_ApproachF(&pthis->csCamMovementScale, 0.05f, 1.0f, 0.001f);

            if (pthis->csTimer > 80) {
                pthis->csState = 106;
                pthis->csTimer = 60;
            }
            break;

        case 106:
            pthis->csCamEye.x = -450.0f;
            pthis->csCamEye.y = 4154.0f;
            pthis->csCamEye.z = -182.0f;

            pthis->csCamAt.x = sZelda->actor.world.pos.x - 5.0f;
            pthis->csCamAt.y = sZelda->actor.world.pos.y + 40.0f + 5.0f;
            pthis->csCamAt.z = sZelda->actor.world.pos.z - 25.0f;

            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.3f;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            if (pthis->csTimer == 70) {
                sZelda->unk_3C8 = 6;
            }

            if (pthis->csTimer == 90) {
                Message_StartTextbox(globalCtx, 0x70D1, NULL);
            }

            if ((pthis->csTimer > 150) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                pthis->csState = 107;
                pthis->csTimer = 0;
                Message_StartTextbox(globalCtx, 0x70D2, NULL);
                func_8002DF54(globalCtx, &pthis->actor, 0x39);
            }
            break;

        case 107:
            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.8f;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            pthis->csCamEye.x = -380.0f;
            pthis->csCamEye.y = 4154.0f;
            pthis->csCamEye.z = -242.0f;

            pthis->csCamAt.x = (sZelda->actor.world.pos.x - 5.0f) - 30.0f;
            pthis->csCamAt.y = (sZelda->actor.world.pos.y + 40.0f + 5.0f) - 20.0f;
            pthis->csCamAt.z = (sZelda->actor.world.pos.z - 25.0f) + 80.0f;

            if ((pthis->csTimer > 50) && (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_NONE)) {
                sZelda->unk_3C8 = 7;
                pthis->csState = 108;
                pthis->csTimer = 0;
            }
            break;

        case 108:
            pthis->unk_70C = Math_SinS(pthis->csTimer * 0x6300) * 0.8f;
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);

            pthis->csCamAt.x = (sZelda->actor.world.pos.x - 5.0f) - 30.0f;
            pthis->csCamAt.y = (sZelda->actor.world.pos.y + 40.0f + 5.0f) - 20.0f;
            pthis->csCamAt.z = (sZelda->actor.world.pos.z - 25.0f) + 80.0f;

            if (pthis->csTimer > 50) {
                mainCam = Gameplay_GetCamera(globalCtx, MAIN_CAM);

                mainCam->eye = pthis->csCamEye;
                mainCam->eyeNext = pthis->csCamEye;
                mainCam->at = pthis->csCamAt;

                func_800C08AC(globalCtx, pthis->csCamIndex, 0);
                pthis->csState = 109;
                pthis->csCamIndex = 0;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, &pthis->actor, 7);
                Flags_SetSwitch(globalCtx, 0x37);
            }
            break;

        case 109:
            func_80078884(NA_SE_EV_EARTHQUAKE - SFX_FLAG);
            break;
    }

    if (pthis->csState >= 100) {
        pthis->envLightMode = 20;
    }

    if (pthis->csCamIndex != 0) {
        if (moveCam) {
            Math_ApproachF(&pthis->csCamEye.x, pthis->csCamTargetEye.x, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.x * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamEye.y, pthis->csCamTargetEye.y, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.y * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamEye.z, pthis->csCamTargetEye.z, pthis->csCamMovementScale,
                           pthis->csCamEyeMaxStep.z * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamAt.x, pthis->csCamTargetAt.x, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.x * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamAt.y, pthis->csCamTargetAt.y, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.y * pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamAt.z, pthis->csCamTargetAt.z, pthis->csCamMovementScale,
                           pthis->csCamAtMaxStep.z * pthis->csCamMaxStepScale);
        }

        sp64 = pthis->csCamAt;
        sp64.y += pthis->unk_70C;
        Gameplay_CameraSetAtEye(globalCtx, pthis->csCamIndex, &sp64, &pthis->csCamEye);
    }
}

void BossGanon_SetupPoundFloor(BossGanon* pthis, GlobalContext* globalCtx) {
    pthis->unk_1C2 = 0;
    pthis->timers[0] = 40;
    pthis->actionFunc = BossGanon_PoundFloor;
    pthis->actor.velocity.x = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->fwork[GDF_CENTER_POS] = 100.0f;
}

void BossGanon_PoundFloor(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;
    f32 heightTarget;
    f32 targetPosX;
    f32 targetPosZ;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;

    SkelAnime_Update(&pthis->skelAnime);

    switch (pthis->unk_1C2) {
        case 0:
            targetPosX = Math_SinS(pthis->unk_1A2 * 1280);
            targetPosX = targetPosX * pthis->fwork[GDF_CENTER_POS];
            targetPosZ = Math_CosS(pthis->unk_1A2 * 1792);
            targetPosZ = targetPosZ * pthis->fwork[GDF_CENTER_POS];

            Math_ApproachF(&pthis->actor.world.pos.x, targetPosX, 0.05f, pthis->fwork[GDF_FWORK_0]);
            Math_ApproachF(&pthis->actor.world.pos.z, targetPosZ, 0.05f, pthis->fwork[GDF_FWORK_0]);
            Math_ApproachF(&pthis->fwork[GDF_CENTER_POS], 0.0f, 1, 1.5f);

            if (pthis->timers[0] == 5) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_HIT_GND);
            }

            if (pthis->timers[0] < 14) {
                heightTarget = 250.0f;
                pthis->unk_258 += (Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
                Math_ApproachF(&pthis->handLightBallScale, 7.0f, 0.5f, 1.0f);
                pthis->envLightMode = 1;
            } else {
                heightTarget = 200.0f;
            }

            Math_ApproachF(&pthis->actor.world.pos.y, heightTarget, 0.1f, pthis->actor.velocity.y);
            Math_ApproachF(&pthis->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (pthis->timers[0] == 14) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfPoundAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfPoundAnim, 0.0f);
                pthis->actor.velocity.y = 0.0f;
            }

            if (pthis->timers[0] == 0) {
                pthis->unk_1C2 = 1;
                pthis->actor.velocity.y = 0.0f;
            }
            break;

        case 1:
            sCape->gravity = -1.0f;
            pthis->envLightMode = 1;
            Math_ApproachF(&pthis->actor.velocity.y, -50.0f, 1.0f, 10.0f);
            pthis->actor.world.pos.y += pthis->actor.velocity.y;

            if (pthis->actor.world.pos.y < 60.0f) {
                pthis->actor.world.pos.y = 60.0f;
                pthis->unk_1C2 = 2;
                pthis->timers[0] = 10;
                func_80033E88(&pthis->actor, globalCtx, 0xA, 0x14); // rumble
                pthis->unk_19C = 35;
                pthis->unk_19E = 0;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_HIT_GND_IMP);
                pthis->handLightBallScale = 0.0f;
                sp60 = pthis->unk_260;
                sp60.y = 0.0f;

                for (i = 0; i < 80; i++) {
                    sp6C.x = Rand_CenteredFloat(25.0f);
                    sp6C.y = Rand_ZeroFloat(17.0f);
                    sp6C.z = Rand_CenteredFloat(25.0f);
                    BossGanonEff_SpawnLightRay(globalCtx, &sp60, &sp6C, &sZeroVec, Rand_ZeroFloat(300.0f) + 500.0f,
                                               13.0f, 0x1E);
                }
            }
            break;

        case 2:
            pthis->envLightMode = 1;

            if (pthis->timers[0] == 0) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfPoundEndAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfPoundEndAnim, 0.0f);
                pthis->unk_1C2 = 3;
                pthis->unk_19F = 1;
                pthis->actor.velocity.y = 0.0f;
            }
            break;

        case 3:
            Math_ApproachF(&pthis->actor.world.pos.y, 150.0f, 0.1f, pthis->actor.velocity.y);
            Math_ApproachF(&pthis->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfGetUp3Anim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp3Anim, 0.0f);
                SkelAnime_Update(&pthis->skelAnime);
                sCape->attachShouldersTimer = 18.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
                pthis->unk_1C2 = 4;
            }
            break;

        case 4:
            Math_ApproachF(&pthis->actor.world.pos.y, 150.0f, 0.1f, pthis->actor.velocity.y);
            Math_ApproachF(&pthis->actor.velocity.y, 20.0f, 1.0f, 1.0f);

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                BossGanon_SetupWait(pthis, globalCtx);
            }
            break;
    }

    if ((pthis->unk_19C == 35) || (pthis->unk_19C == 30) || (pthis->unk_19C == 25)) {
        sp54 = pthis->actor.world.pos;
        sp54.y = 0.0f;
        BossGanonEff_SpawnDustLight(globalCtx, &sp54, 0, 3.0f, pthis->unk_19C - 25);
    }

    if (pthis->unk_19C == 35) {
        sp48 = pthis->actor.world.pos;
        sp48.y = 0.0f;
        BossGanonEff_SpawnShockwave(globalCtx, &sp48, 0, 3.0f);
    }
}

void BossGanon_SetupChargeBigMagic(BossGanon* pthis, GlobalContext* globalCtx) {
    pthis->unk_1C2 = 0;
    pthis->timers[0] = 30;
    pthis->actor.velocity.x = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->fwork[GDF_CENTER_POS] = 100.0f;
    pthis->unk_1AA = Rand_ZeroFloat(20000.0f);
    pthis->unk_1AC = 0;
    pthis->actionFunc = BossGanon_ChargeBigMagic;
}

void BossGanon_ChargeBigMagic(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 targetPosX;
    f32 targetPosZ;
    Vec3f sp80;
    Vec3f sp74;
    Vec3f sp68;
    s16 i;

    SkelAnime_Update(&pthis->skelAnime);

    targetPosX = Math_SinS(pthis->unk_1A2 * 1280);
    targetPosX = targetPosX * pthis->fwork[GDF_CENTER_POS];

    targetPosZ = Math_CosS(pthis->unk_1A2 * 1792);
    targetPosZ = targetPosZ * pthis->fwork[GDF_CENTER_POS];

    Math_ApproachF(&pthis->actor.world.pos.x, targetPosX, 0.05f, pthis->fwork[GDF_FWORK_0]);
    Math_ApproachF(&pthis->actor.world.pos.z, targetPosZ, 0.05, pthis->fwork[GDF_FWORK_0]);

    Math_ApproachF(&pthis->fwork[GDF_CENTER_POS], 0.0f, 1.0f, 1.5f);
    Math_ApproachF(&pthis->actor.world.pos.y, 200.0f, 0.05f, pthis->actor.velocity.y);
    Math_ApproachF(&pthis->actor.velocity.y, 20.0f, 1.0f, 1.0f);

    switch (pthis->unk_1C2) {
        case 0:
            if (pthis->timers[0] == 0) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicChargeStartAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfBigMagicChargeStartAnim, 0.0f);
                pthis->unk_1C2 = 1;
            }
            break;

        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicChargeHoldAnim);
                Animation_MorphToLoop(&pthis->skelAnime, &gDorfBigMagicChargeHoldAnim, 0.0f);
                pthis->unk_1C2 = 2;
                pthis->timers[0] = 100;
            }
            break;

        case 2:
            pthis->envLightMode = 2;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_CHARGE_MASIC - SFX_FLAG);
            pthis->unk_278.x = pthis->unk_2EC[0].x;
            pthis->unk_278.y = pthis->unk_2EC[0].y + 50.0f + 30.0f;
            pthis->unk_278.z = pthis->unk_2EC[0].z;

            Math_ApproachF(&pthis->unk_284, 0.25f, 0.1f, 0.006f);
            Math_ApproachF(&pthis->unk_288, 255.0f, 1.0f, 255.0f);
            Math_ApproachF(&pthis->unk_28C, 0.25f, 0.1f, 0.006f);

            if ((pthis->timers[0] > 20) && (pthis->timers[0] < 60)) {
                Math_ApproachF(&pthis->unk_290, 255.0f, 1.0f, 15.0f);
            }

            if (pthis->timers[0] == 0) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicWindupAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfBigMagicWindupAnim, 0.0f);
                pthis->unk_1C2 = 3;
                pthis->timers[0] = 6;
                pthis->timers[1] = 15;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DARKWAVE);
                break;
            }

            Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x3E8);

            if (pthis->timers[0] < -4) {
                for (i = 0; i < ARRAY_COUNT(pthis->unk_294); i++) {
                    Math_ApproachF(&pthis->unk_294[i], 0.0f, 1.0f, 40.0f);
                }
            } else if ((pthis->timers[0] >= 7) && (pthis->timers[0] < 26)) {
                if (pthis->unk_1AC < ARRAY_COUNT(pthis->unk_294)) {
                    pthis->unk_1AC++;
                }

                for (i = 0; i < pthis->unk_1AC; i++) {
                    Math_ApproachF(&pthis->unk_294[i], 200.0f, 1.0f, 40.0f);
                }
            }

            if (pthis->timers[0] <= 30) {
                Math_ApproachF(&pthis->unk_284, 0.4f, 0.5f, 0.017f);
                pthis->unk_28C = pthis->unk_284;
            }

            if (pthis->timers[0] <= 30) {
                Math_ApproachF(&pthis->unk_2D0, 45.0f, 0.1f, 10.0f);
                pthis->lensFlareTimer = 1;
                pthis->lensFlareMode = 2;
                gCustomLensFlarePos = pthis->unk_278;
            }

            if (pthis->timers[0] == 47) {
                pthis->unk_274 = 1;
            }

            if (pthis->timers[0] == 46) {
                pthis->unk_274 = 2;
            }

            if (pthis->timers[0] == 45) {
                pthis->unk_274 = 3;
            }

            if (pthis->timers[0] == 44) {
                pthis->unk_274 = 4;
            }

            if (pthis->timers[0] == 43) {
                pthis->unk_274 = 5;
            }

            if (pthis->timers[0] == 42) {
                pthis->unk_274 = 6;
            }

            if (pthis->timers[0] > 30) {
                sp74.x = 0.0f;
                sp74.y = Rand_ZeroFloat(10.0f) + 150.0f;
                sp74.z = 0.0f;

                Matrix_RotateY(BINANG_TO_RAD(pthis->actor.yawTowardsPlayer), MTXMODE_NEW);
                Matrix_RotateZ(Rand_ZeroFloat(65536.0f), MTXMODE_APPLY);
                Matrix_MultVec3f(&sp74, &sp68);

                sp80.x = pthis->unk_278.x + sp68.x;
                sp80.y = pthis->unk_278.y + sp68.y;
                sp80.z = pthis->unk_278.z + sp68.z;

                BossGanonEff_SpawnBlackDot(globalCtx, &sp80, 20.0f);
            }
            break;

        case 3:
            pthis->envLightMode = 2;

            for (i = 0; i < ARRAY_COUNT(pthis->unk_294); i++) {
                Math_ApproachF(&pthis->unk_294[i], 0.0f, 1.0f, 40.0f);
            }

            if (pthis->timers[0] == 1) {
                sCape->attachLeftArmTimer = 15.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
            }

            if (pthis->timers[0] == 0) {
                Math_ApproachZeroF(&pthis->unk_284, 1.0f, 0.08f);
                pthis->unk_28C = pthis->unk_284;
                Math_ApproachZeroF(&pthis->unk_2D0, 1.0f, 10.0f);
                Math_ApproachF(&pthis->unk_278.x, pthis->unk_1FC.x, 0.5f, 30.0f);
                Math_ApproachF(&pthis->unk_278.y, pthis->unk_1FC.y, 0.5f, 30.0f);
                Math_ApproachF(&pthis->unk_278.z, pthis->unk_1FC.z, 0.5f, 30.0f);
            }

            if (pthis->timers[1] == 0) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicThrowAnim);
                Animation_MorphToLoop(&pthis->skelAnime, &gDorfBigMagicThrowAnim, 0.0f);
                pthis->unk_1C2 = 4;
                pthis->unk_288 = 0.0f;
                pthis->unk_290 = 0.0f;
                pthis->unk_284 = 0.0f;
                pthis->unk_28C = 0.0f;
            }
            break;

        case 4:
            pthis->envLightMode = 2;

            if (Animation_OnFrame(&pthis->skelAnime, 5.0f)) {
                for (i = 0; i < 5; i++) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_GANON, pthis->unk_1FC.x,
                                       pthis->unk_1FC.y, pthis->unk_1FC.z, 0, pthis->actor.yawTowardsPlayer, 0, 0x104 + i);
                }

                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_BIGMASIC);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_THROW_BIG);
            }

            if (Animation_OnFrame(&pthis->skelAnime, 3.0f)) {
                sCape->attachShouldersTimer = 26.0f;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
            }

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicThrowEndAnim);
                Animation_MorphToLoop(&pthis->skelAnime, &gDorfBigMagicThrowEndAnim, 0.0f);
                pthis->unk_1C2 = 5;
            }
            break;

        case 5:
            pthis->envLightMode = 2;

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                BossGanon_SetupWait(pthis, globalCtx);
            }
            break;
    }
}

void BossGanon_SetupWait(BossGanon* pthis, GlobalContext* globalCtx) {
    BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    Animation_MorphToLoop(&pthis->skelAnime, &gDorfFloatAnim, -10.0f);
    pthis->actionFunc = BossGanon_Wait;
    pthis->fwork[GDF_FWORK_0] = 0.0f;
    pthis->timers[0] = (s16)Rand_ZeroFloat(64.0f) + 30;
    pthis->unk_1C2 = 0;
    sCape->minY = 2.0f;
}

void BossGanon_Wait(BossGanon* pthis, GlobalContext* globalCtx) {
    f32 sin;
    s32 pad;
    f32 cos;
    Player* player = GET_PLAYER(globalCtx);

    pthis->legSwayEnabled = true;

    sCape->backPush = -3.0f;
    sCape->backSwayMagnitude = 0.25f;
    sCape->sideSwayMagnitude = -3.0f;
    sCape->minDist = 20.0f;

    SkelAnime_Update(&pthis->skelAnime);

    if ((pthis->unk_1C2 == 0) && !(player->actor.world.pos.y < 0.0f)) {
        if (!(player->stateFlags1 & 0x2000) && (fabsf(player->actor.world.pos.x) < 110.0f) &&
            (fabsf(player->actor.world.pos.z) < 110.0f)) {
            BossGanon_SetupPoundFloor(pthis, globalCtx);
        } else if ((pthis->timers[0] == 0) && !(player->stateFlags1 & 0x2000)) {
            pthis->timers[0] = (s16)Rand_ZeroFloat(30.0f) + 30;

            if ((s8)pthis->actor.colChkInfo.health >= 20) {
                BossGanon_SetupChargeLightBall(pthis, globalCtx);
            } else if (Rand_ZeroOne() >= 0.5f) {
                if ((Rand_ZeroOne() >= 0.5f) || (pthis->actor.xzDistToPlayer > 350.0f)) {
                    BossGanon_SetupChargeBigMagic(pthis, globalCtx);
                } else {
                    BossGanon_SetupPoundFloor(pthis, globalCtx);
                }
            } else {
                BossGanon_SetupChargeLightBall(pthis, globalCtx);
            }
        }
    }

    sin = Math_SinS(pthis->unk_1A2 * 1280) * 100.0f;
    cos = Math_CosS(pthis->unk_1A2 * 1792) * 100.0f;

    Math_ApproachF(&pthis->actor.world.pos.x, sin, 0.05f, pthis->fwork[GDF_FWORK_0]);
    Math_ApproachF(&pthis->actor.world.pos.y, 150.0f, 0.05f, pthis->fwork[GDF_FWORK_0] * 0.2f);
    Math_ApproachF(&pthis->actor.world.pos.z, cos, 0.05f, pthis->fwork[GDF_FWORK_0]);
    Math_ApproachF(&pthis->fwork[GDF_FWORK_0], 50.0f, 1.0f, 0.5f);

    pthis->actor.velocity.x = pthis->actor.world.pos.x - pthis->actor.prevPos.x;
    pthis->actor.velocity.z = pthis->actor.world.pos.z - pthis->actor.prevPos.z;

    sin = Math_SinS(pthis->unk_1A2 * 1500);
    pthis->actor.velocity.y = pthis->fwork[GDF_FWORK_0] * sin * 0.04f;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0xBB8);
    func_80078914(&pthis->actor.projectedPos, NA_SE_EN_FANTOM_FLOAT - SFX_FLAG);
}

void BossGanon_SetupChargeLightBall(BossGanon* pthis, GlobalContext* globalCtx) {
    BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfChargeLightBallAnim);
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfChargeLightBallAnim, -3.0f);
    pthis->actionFunc = BossGanon_ChargeLightBall;
    pthis->timers[0] = 25;
}

void BossGanon_ChargeLightBall(BossGanon* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);

    sCape->backPush = -3.0f;
    sCape->backSwayMagnitude = 1.25f;
    sCape->sideSwayMagnitude = -2.0f;
    sCape->minDist = 10.0f;

    if (pthis->timers[0] < 17) {
        pthis->envLightMode = 1;
    }

    if (pthis->timers[0] == 17) {
        pthis->unk_26C = 10;
        pthis->unk_270 = Rand_ZeroFloat(M_PI);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_SPARK);
    }

    if (pthis->timers[0] < 10) {
        pthis->unk_258 += (Rand_ZeroFloat(M_PI / 2) + (M_PI / 2));
        Math_ApproachF(&pthis->handLightBallScale, 10.0f, 0.5f, 1.25f);

        if (pthis->timers[0] == 0) {
            BossGanon_SetupPlayTennis(pthis, globalCtx);
        }
    }

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x7D0);

    pthis->actor.world.pos.x += pthis->actor.velocity.x;
    pthis->actor.world.pos.z += pthis->actor.velocity.z;

    Math_ApproachZeroF(&pthis->actor.velocity.x, 1.0f, 0.5f);
    Math_ApproachZeroF(&pthis->actor.velocity.z, 1.0f, 0.5f);

    pthis->actor.velocity.y = Math_SinS(pthis->unk_1A2 * 1500) * 2.0f;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
}

void BossGanon_SetupPlayTennis(BossGanon* pthis, GlobalContext* globalCtx) {
    BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfThrowAnim);
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfThrowAnim, 0.0f);
    pthis->actionFunc = BossGanon_PlayTennis;
}

void BossGanon_PlayTennis(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 rand;

    SkelAnime_Update(&pthis->skelAnime);
    Math_ApproachZeroF(&pthis->handLightBallScale, 1.0f, 0.2f);

    switch (pthis->unk_1C2) {
        case 0:
            pthis->envLightMode = 1;

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 1;
                Animation_MorphToLoop(&pthis->skelAnime, &gDorfFloatAnim, 0.0f);
            }

            if (pthis->skelAnime.curFrame <= 12.0f) {
                pthis->lensFlareTimer = 2;
                pthis->lensFlareMode = 2;
                gCustomLensFlarePos = pthis->unk_260;
            }

            if (Animation_OnFrame(&pthis->skelAnime, 12.0f)) {
                pthis->handLightBallScale = 0.0f;
            }

            if (Animation_OnFrame(&pthis->skelAnime, 11.0f)) {
                pthis->unk_25C = 1;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_THROW);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_THROW_MASIC);
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_GANON, pthis->unk_260.x,
                                   pthis->unk_260.y, pthis->unk_260.z, 0, 0, 0, 0x64);
            }
            break;

        case 1:
            if (pthis->startVolley) {
                rand = Rand_ZeroOne() * 1.99f;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(volleyAnims_119[rand]);
                Animation_MorphToPlayOnce(&pthis->skelAnime, volleyAnims_119[rand], 0.0f);
                sCape->attachRightArmTimer = capeRightArmDurations_119[rand];
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
                pthis->startVolley = false;
            }
            break;
    }

    Math_ApproachS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, 0x7D0);

    pthis->actor.world.pos.x += pthis->actor.velocity.x;
    pthis->actor.world.pos.z += pthis->actor.velocity.z;

    Math_SmoothStepToF(&pthis->actor.velocity.x, 0.0f, 1.0f, 0.5f, 0.0f);
    Math_SmoothStepToF(&pthis->actor.velocity.z, 0.0f, 1.0f, 0.5f, 0.0f);

    pthis->actor.velocity.y = Math_SinS(pthis->unk_1A2 * 1500) * 2.0f;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
}

void BossGanon_SetupBlock(BossGanon* pthis, GlobalContext* globalCtx) {
    if ((pthis->actionFunc != BossGanon_Block) || (pthis->unk_1C2 != 0)) {
        BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
        pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBlockAnim);
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfBlockAnim, 0.0f);
        pthis->actionFunc = BossGanon_Block;
    }

    pthis->unk_1C2 = 0;
    sCape->attachLeftArmTimer = pthis->timers[0] = 10;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
    pthis->handLightBallScale = 0.0f;
}

void BossGanon_Block(BossGanon* pthis, GlobalContext* globalCtx) {
    pthis->collider.base.colType = 9;
    SkelAnime_Update(&pthis->skelAnime);
    sCape->backPush = -9.0f;
    sCape->backSwayMagnitude = 0.25f;
    sCape->sideSwayMagnitude = -2.0f;
    sCape->minDist = 13.0f;

    if (pthis->unk_1C2 == 0) {
        if (pthis->timers[0] == 0) {
            pthis->unk_1C2 = 1;
            Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfBlockReleaseAnim, 0.0f);
            pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBlockReleaseAnim);
            SkelAnime_Update(&pthis->skelAnime);
            sCape->attachShouldersTimer = 15.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
        }
    } else {
        sCape->sideSwayMagnitude = -13.0f;

        if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
            BossGanon_SetupWait(pthis, globalCtx);
        }
    }

    pthis->actor.world.pos.x += pthis->actor.velocity.x;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
    pthis->actor.world.pos.z += pthis->actor.velocity.z;

    Math_ApproachZeroF(&pthis->actor.velocity.x, 1.0f, 0.5f);
    Math_ApproachZeroF(&pthis->actor.velocity.y, 1.0f, 0.5f);
    Math_ApproachZeroF(&pthis->actor.velocity.z, 1.0f, 0.5f);
}

void BossGanon_SetupHitByLightBall(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;

    BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfBigMagicHitAnim);
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfBigMagicHitAnim, 0);
    pthis->timers[0] = 70;
    sCape->attachRightArmTimer = sCape->attachLeftArmTimer = 0;

    for (i = 1; i < 15; i++) {
        pthis->unk_4E4[i] = D_808E4C58[i];
    }

    pthis->unk_2E6 = 80;
    pthis->unk_2E8 = 0;
    pthis->actionFunc = BossGanon_HitByLightBall;
    pthis->actor.velocity.x = pthis->actor.velocity.z = 0.0f;
    pthis->unk_1C2 = 0;
    pthis->unk_1A6 = 15;
    pthis->unk_508 = 6.0f;
}

void BossGanon_HitByLightBall(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;
    Vec3f sp50;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_1C2 == 0) {
        BossGanonEff_SpawnShock(globalCtx, 1500.0f, GDF_SHOCK_DORF_YELLOW);

        if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
            pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfLightArrowWaitAnim);
            Animation_MorphToLoop(&pthis->skelAnime, &gDorfLightArrowWaitAnim, 0.0f);
            pthis->unk_1C2 = 1;
        }
    } else if (pthis->unk_1C2 == 1) {
        BossGanonEff_SpawnShock(globalCtx, 1000.0f, GDF_SHOCK_DORF_YELLOW);

        if (pthis->timers[0] == 0) {
            pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfGetUp3Anim);
            Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp3Anim, 0.0f);
            pthis->unk_1C2 = 2;
            SkelAnime_Update(&pthis->skelAnime);
            sCape->attachShouldersTimer = 18.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_RESTORE);
            pthis->timers[2] = 130;
        }
    } else {
        if (Animation_OnFrame(&pthis->skelAnime, 7.0f)) {
            for (i = 0; i < 100; i++) {
                sp50.x = Rand_CenteredFloat(25.0f);
                sp50.y = Rand_CenteredFloat(25.0f);
                sp50.z = Rand_CenteredFloat(25.0f);

                BossGanonEff_SpawnSparkle(globalCtx, &pthis->unk_1FC, &sp50, &sZeroVec, Rand_ZeroFloat(200.0f) + 500.0f,
                                          0x14);
            }
            Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_WALK_WATER2);
        }

        if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
            BossGanon_SetupWait(pthis, globalCtx);
        }
    }

    pthis->actor.velocity.y = Math_SinS(pthis->unk_1A2 * 1500) * 2.0f;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;
}

void BossGanon_SetupVulnerable(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;

    if (pthis->actionFunc != BossGanon_Vulnerable) {
        BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
        pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfLightArrowHitAnim);
        Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfLightArrowHitAnim, 0.0f);
        sCape->attachRightArmTimer = sCape->attachLeftArmTimer = 0;
        pthis->actionFunc = BossGanon_Vulnerable;

        pthis->actor.velocity.x = 0.0f;
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.velocity.z = 0.0f;

        pthis->unk_1C2 = 0;
        sCape->backPush = -4.0f;
        sCape->backSwayMagnitude = 0.75f;
        sCape->sideSwayMagnitude = -3.0f;
        sCape->minDist = 20.0f;

        for (i = 0; i < 10; i++) {
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_GANON, pthis->unk_1FC.x,
                               pthis->unk_1FC.y, pthis->unk_1FC.z, Rand_CenteredFloat(0x8000),
                               (s16)Rand_CenteredFloat(0x8000) + pthis->actor.yawTowardsPlayer, 0, 0xC8 + i);
        }

        pthis->unk_1A4 = 0;
        pthis->unk_288 = 0.0f;
        pthis->unk_290 = 0.0f;
        pthis->unk_284 = 0.0f;
        pthis->unk_28C = 0.0f;
    }
}

void BossGanon_Vulnerable(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;
    Vec3f sp40;

    if (pthis->timers[3] == 0) {
        pthis->actor.flags |= ACTOR_FLAG_0;
    }

    SkelAnime_Update(&pthis->skelAnime);

    pthis->envLightMode = 1;
    pthis->actor.world.pos.y += pthis->actor.velocity.y;

    if (pthis->unk_1A4 < 0x28) {
        Math_ApproachF(&pthis->unk_508, 4.0f, 0.1f, 0.1f);
    }

    if ((pthis->unk_1A4 >= 0x28) && (pthis->unk_1A4 < 0x37)) {
        Math_ApproachF(&pthis->unk_508, 0.0f, 1.0f, 0.5f);
    }

    if (pthis->unk_1A4 >= 0x37) {
        Math_ApproachF(&pthis->unk_508, 5.0f, 0.1f, 0.15f);
        pthis->shockGlow = true;
    }

    switch (pthis->unk_1C2) {
        case 0:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 1;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfLightEnergyHitAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfLightEnergyHitAnim, 0.0f);
            }
            break;

        case 1:
            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 2;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfKneelVulnerableAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfKneelVulnerableAnim, 0.0f);
            }
            break;

        case 2:
            sCape->minDist = 0.0f;
            pthis->actor.velocity.y = pthis->actor.velocity.y - 0.5f;

            if (pthis->actor.world.pos.y < 40.0f) {
                pthis->actor.world.pos.y = 40.0f;
                pthis->actor.velocity.y = 0.0f;
                pthis->unk_1C2 = 3;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfLandAnim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfLandAnim, 0.0f);
                pthis->timers[0] = 70;
                pthis->actor.flags |= ACTOR_FLAG_10;
            }
            break;

        case 3:
            if (pthis->timers[0] == 68) {
                pthis->unk_19F = 1;
            }

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 4;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfVulnerableAnim);
                Animation_MorphToLoop(&pthis->skelAnime, &gDorfVulnerableAnim, 0.0f);
            }
            break;

        case 4:
            if (Animation_OnFrame(&pthis->skelAnime, 5.0f)) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DOWN);
            }

            if (pthis->timers[0] == 0) {
                pthis->unk_1C2 = 5;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfGetUp1Anim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp1Anim, 0.0f);
                pthis->unk_2D4 = 80;

                for (i = 1; i < 15; i++) {
                    pthis->unk_4E4[i] = Rand_ZeroFloat(10.0f);
                }

                pthis->unk_2E6 = 80;
                pthis->unk_2E8 = 0;
                pthis->actor.flags &= ~ACTOR_FLAG_10;
            }
            break;

        case 5:
            BossGanonEff_SpawnShock(globalCtx, 1000.0f, GDF_SHOCK_DORF_YELLOW);

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 6;
                pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfGetUp2Anim);
                Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp2Anim, 0.0f);
                sCape->minDist = 20.0f;
                pthis->unk_19F = 1;
            }
            break;

        case 6:
            pthis->envLightMode = 0;
            Math_ApproachF(&pthis->actor.world.pos.y, 200.0f, 0.1f, 1000.0f);

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                pthis->unk_1C2 = 7;
            }
            break;

        case 7:
            pthis->envLightMode = 0;
            Math_ApproachF(&pthis->actor.world.pos.y, 150.0f, 0.05f, 30.0f);
            pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfGetUp3Anim);
            Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfGetUp3Anim, 0.0f);
            pthis->unk_1C2 = 8;
            SkelAnime_Update(&pthis->skelAnime);
            sCape->attachShouldersTimer = 18.0f;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_MANTLE);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_RESTORE);
            break;

        case 8:
            pthis->envLightMode = 0;

            if (Animation_OnFrame(&pthis->skelAnime, 7.0f)) {
                for (i = 0; i < 100; i++) {
                    sp40.x = Rand_CenteredFloat(25.0f);
                    sp40.y = Rand_CenteredFloat(25.0f);
                    sp40.z = Rand_CenteredFloat(25.0f);
                    BossGanonEff_SpawnSparkle(globalCtx, &pthis->unk_1FC, &sp40, &sZeroVec,
                                              Rand_ZeroFloat(200.0f) + 500.0f, 0x14);
                }

                Audio_PlayActorSound2(&pthis->actor, NA_SE_PL_WALK_WATER2);
                pthis->timers[3] = 50;
            }

            if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
                BossGanon_SetupWait(pthis, globalCtx);
            }
            break;
    }
}

void BossGanon_SetupDamaged(BossGanon* pthis, GlobalContext* globalCtx) {
    BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfDamageAnim);
    Animation_MorphToPlayOnce(&pthis->skelAnime, &gDorfDamageAnim, 0.0f);
    pthis->actionFunc = BossGanon_Damaged;
}

void BossGanon_Damaged(BossGanon* pthis, GlobalContext* globalCtx) {
    pthis->actor.flags |= ACTOR_FLAG_0;

    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->unk_1A4 >= 0x37) {
        Math_ApproachF(&pthis->unk_508, 5.0f, 0.1f, 0.15f);
        pthis->shockGlow = true;
    }

    if (Animation_OnFrame(&pthis->skelAnime, pthis->fwork[GDF_FWORK_1])) {
        pthis->actionFunc = BossGanon_Vulnerable;
        pthis->unk_1C2 = 4;
        pthis->fwork[GDF_FWORK_1] = Animation_GetLastFrame(&gDorfVulnerableAnim);
        Animation_MorphToLoop(&pthis->skelAnime, &gDorfVulnerableAnim, 0.0f);
    }
}

void BossGanon_UpdateDamage(BossGanon* pthis, GlobalContext* globalCtx) {
    s16 i;
    s16 j;
    ColliderInfo* acHitInfo;

    if (pthis->collider.base.acFlags & 2) {
        pthis->unk_2D4 = 2;
        pthis->collider.base.acFlags &= ~2;
        acHitInfo = pthis->collider.info.acHitInfo;

        if ((pthis->actionFunc == BossGanon_HitByLightBall) || (pthis->actionFunc == BossGanon_ChargeBigMagic)) {
            if (acHitInfo->toucher.dmgFlags & 0x2000) {
                BossGanon_SetupVulnerable(pthis, globalCtx);
                pthis->timers[2] = 0;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DAMAGE1);
                pthis->unk_1A6 = 15;
            }
        } else if ((pthis->actionFunc == BossGanon_Vulnerable) && (pthis->unk_1C2 >= 3)) {
            if (!(acHitInfo->toucher.dmgFlags & 0x80)) {
                u8 hitWithSword = false;
                u8 damage;
                Vec3f sp50;
                u32 flags;

                for (i = 0; i < 30; i++) {
                    sp50.x = Rand_CenteredFloat(20.0f);
                    sp50.y = Rand_CenteredFloat(20.0f);
                    sp50.z = Rand_CenteredFloat(20.0f);
                    BossGanonEff_SpawnSparkle(globalCtx, &pthis->unk_1FC, &sp50, &sZeroVec,
                                              Rand_ZeroFloat(200.0f) + 500.0f, 0x1E);
                }

                damage = flags = CollisionCheck_GetSwordDamage(acHitInfo->toucher.dmgFlags);

                if (flags == 0) {
                    damage = 2;
                } else {
                    hitWithSword = true;
                }

                if (((s8)pthis->actor.colChkInfo.health >= 3) || hitWithSword) {
                    pthis->actor.colChkInfo.health -= damage;
                }

                for (i = 0; i < ARRAY_COUNT(sCape->strands); i++) {
                    for (j = 1; j < 12; j++) {
                        sCape->strands[i].velocities[j].x = Rand_CenteredFloat(15.0f);
                        sCape->strands[i].velocities[j].z = Rand_CenteredFloat(15.0f);
                    }
                }

                if ((s8)pthis->actor.colChkInfo.health <= 0) {
                    BossGanon_SetupDeathCutscene(pthis, globalCtx);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DEAD);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DD_THUNDER);
                    func_80078914(&sZeroVec, NA_SE_EN_LAST_DAMAGE);
                    Audio_QueueSeqCmd(0x100100FF);
                    pthis->screenFlashTimer = 4;
                } else {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_DAMAGE2);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_CUTBODY);
                    BossGanon_SetupDamaged(pthis, globalCtx);
                    pthis->unk_1A6 = 15;
                    sCape->tearTimer = 1;
                }
            }
        } else if (acHitInfo->toucher.dmgFlags & 0x1F8A4) {
            Audio_PlayActorSound2(&pthis->actor, 0);

            for (i = 0; i < ARRAY_COUNT(sCape->strands); i++) {
                for (j = 1; j < 12; j++) {
                    sCape->strands[i].velocities[j].x = Rand_CenteredFloat(15.0f);
                    sCape->strands[i].velocities[j].z = Rand_CenteredFloat(15.0f);
                }
            }
        }
    }
}

static f32 D_808E4D44[] = {
    1.0f, 3.0f, 0.0f, 7.0f, 13.0f, 4.0f, 6.0f, 11.0f, 5.0f, 2.0f, 8.0f, 14.0f, 10.0f, 12.0f, 9.0f,
};

void BossGanon_Update(Actor* thisx, GlobalContext* globalCtx2) {
    BossGanon* pthis = (BossGanon*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    f32 legRotX;
    f32 legRotY;
    f32 legRotZ;
    Player* player = GET_PLAYER(globalCtx);
    s16 i;
    f32 sin;
    f32 cos;
    Vec3f shardPos;
    Vec3f shardVel;
    Vec3f spE8;
    s16 i2;
    s16 j;
    Vec3f spD8;
    Vec3f platformCheckPos;
    Actor* explosive;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f platCheckPosBomb;
    Actor* prop;
    BgGanonOtyuka* platform;
    f32 targetLensFlareScale;
    f32 xOffset;
    f32 zOffset;

    if ((pthis->actionFunc != BossGanon_IntroCutscene) && (pthis->actionFunc != BossGanon_DeathAndTowerCutscene)) {
        BossGanon_SetAnimationObject(pthis, globalCtx, OBJECT_GANON_ANIME1);
    } else {
	    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->animBankIndex].vromStart.get());
    }

    if (pthis->windowShatterState != GDF_WINDOW_SHATTER_OFF) {
        BossGanon_ShatterWindows(pthis->windowShatterState);
        shardVel.y = 0.0f;

        for (i = 0; i < 10; i++) {
            shardPos.y = Rand_ZeroFloat(240.0f) + 20.0f;

            if (Rand_ZeroOne() < 0.5f) {
                shardPos.x = 463;
                shardPos.z = Rand_ZeroFloat(463.0f);

                shardVel.x = Rand_ZeroFloat(2.0f);
                shardVel.z = Rand_ZeroFloat(1.0f);
            } else {
                shardPos.z = 463;
                shardPos.x = Rand_ZeroFloat(463.0f);

                shardVel.z = Rand_ZeroFloat(2.0f);
                shardVel.x = Rand_ZeroFloat(1.0f);
            }

            BossGanonEff_SpawnWindowShard(globalCtx, &shardPos, &shardVel, Rand_ZeroFloat(0.075f) + 0.08f);
        }
    }

    pthis->collider.base.colType = 3;
    sCape->gravity = -3.0f;
    pthis->shockGlow = false;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->unk_1A2++;
    pthis->unk_1A4++;

    // block players attack if hes shooting something
    if ((pthis->actionFunc == BossGanon_Wait) || (pthis->actionFunc == BossGanon_Block)) {
        if (player->unk_A73 != 0) {
            BossGanon_SetupBlock(pthis, globalCtx);
        }
    }

    pthis->actionFunc(pthis, globalCtx);

    for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }

    if (pthis->unk_1A6 != 0) {
        pthis->unk_1A6--;
    }

    if (pthis->unk_2D4 != 0) {
        pthis->unk_2D4--;
    }

    if (pthis->unk_2E8 != 0) {
        pthis->unk_2E8--;
    }

    if (pthis->unk_2E6 != 0) {
        pthis->unk_2E6--;
    }

    if (pthis->unk_19C != 0) {
        pthis->unk_19C--;
    }

    if (pthis->csState == 0) {
        BossGanon_UpdateDamage(pthis, globalCtx);
        BossGanon_SetColliderPos(&pthis->unk_1FC, &pthis->collider);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

        if (pthis->unk_2D4 == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

            if ((pthis->actionFunc != BossGanon_HitByLightBall) && (pthis->actionFunc != BossGanon_Vulnerable) &&
                (pthis->actionFunc != BossGanon_Damaged)) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }
        }
    }

    if (pthis->legSwayEnabled) {
        sin = Math_SinS(-pthis->actor.shape.rot.y);
        cos = Math_CosS(-pthis->actor.shape.rot.y);

        legRotX = ((pthis->actor.velocity.z * sin) + (cos * pthis->actor.velocity.x)) * 300.0f;
        legRotY = ((-sin * pthis->actor.velocity.x) + (cos * pthis->actor.velocity.z)) * 300.0f;
        legRotZ = (Math_SinS(pthis->unk_1A2 * 2268) * -500.0f) - 500.0f;
    } else {
        legRotY = legRotX = legRotZ = 0.0f;
    }

    pthis->legSwayEnabled = false;

    Math_SmoothStepToF(&pthis->legRot.x, legRotX, 1.0f, 600.0f, 0.0f);
    Math_SmoothStepToF(&pthis->legRot.y, legRotY, 1.0f, 600.0f, 0.0f);
    Math_SmoothStepToF(&pthis->legRot.z, legRotZ, 1.0f, 100.0f, 0.0f);

    if (pthis->timers[2] == 1) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_LAUGH);
    }

    if (pthis->timers[2] == 100) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_ST_LAUGH);
        pthis->timers[2] = 0;
    }

    if ((pthis->unk_2E6 != 0) || (pthis->unk_2E8 != 0)) {
        for (i = 1; i < ARRAY_COUNT(pthis->unk_49C); i++) {
            if (pthis->unk_4E4[i] != 0) {
                pthis->unk_4E4[i]--;
                Math_ApproachF(&pthis->unk_49C[i], pthis->unk_508, 1.0f, 2.0f);
            } else {
                Math_ApproachZeroF(&pthis->unk_49C[i], 1.0f, 0.2f);
            }
        }

        // player hit, spawn shock and play sound
        if (pthis->unk_2E8 != 0) {
            func_80078914(&player->actor.projectedPos, NA_SE_PL_SPARK - SFX_FLAG);
            BossGanonEff_SpawnShock(globalCtx, 700.0f, GDF_SHOCK_PLAYER_YELLOW);
        }
    }

    if (pthis->unk_19F != 0) {
        pthis->unk_19F = 0;
        spE8 = pthis->actor.world.pos;
        spE8.y = 0.0f;
        BossGanonEff_SpawnDustDark(globalCtx, &spE8, 0.2, 0.7f);
        BossGanonEff_SpawnDustDark(globalCtx, &spE8, 0.3f, 0.8f);
    }

    if (pthis->unk_26C != 0) {
        pthis->unk_26C--;

        if (pthis->unk_26C == 0) {
            BossGanonEff_SpawnLightning(globalCtx, 1.0f, 0.0f, 0.0f);
        }

        BossGanonEff_SpawnLightning(globalCtx, 1.0f, D_808E4D44[pthis->unk_26C] * (M_PI / 5) + pthis->unk_270,
                                    Rand_CenteredFloat(M_PI / 5) + (M_PI / 2));
    }

    // see if light ball hit and should knock platform down?
    if ((pthis->unk_19C != 0) && (pthis->unk_19E < 4)) {
        if ((pthis->unk_19A == 0) && (pthis->unk_19C == 20)) {
            pthis->unk_19A = 1;
            platformCheckPos.x = -180.0f;
            platformCheckPos.y = 0.0f;

            for (i2 = 0; i2 < 4; i2++) {
                for (j = 0, platformCheckPos.z = -180.0f; j < 4; j++) {
                    BossGanon_CheckFallingPlatforms(pthis, globalCtx, &platformCheckPos);
                    platformCheckPos.z += 120.0f;
                }

                platformCheckPos.x += 120.0f;
            }
        } else if (pthis->unk_19C < 30) {
            spD8.x = 0.0f;
            spD8.y = 0.0f;
            spD8.z = 15.0f * (30.0f - pthis->unk_19C);

            Matrix_RotateY(Rand_ZeroFloat(6.2831855f), MTXMODE_NEW);
            Matrix_MultVec3f(&spD8, &platformCheckPos);

            pthis->unk_19E += BossGanon_CheckFallingPlatforms(pthis, globalCtx, &platformCheckPos);
        }
    }

    // see if a bomb exploded near a group of platforms and if they should fall
    explosive = globalCtx->actorCtx.actorLists[ACTORCAT_EXPLOSIVE].head;

    while (explosive != NULL) {
        if (explosive->params != BOMB_EXPLOSION) {
            explosive = explosive->next;
        } else {
            for (i = 0; i < 8; i++) {
                spBC.x = 0.0f;
                spBC.y = 0.0f;
                spBC.z = 60.0f;

                Matrix_RotateY(i * (M_PI / 4), MTXMODE_NEW);
                Matrix_MultVec3f(&spBC, &spB0);

                platCheckPosBomb.x = explosive->world.pos.x + spB0.x;
                platCheckPosBomb.y = explosive->world.pos.y;
                platCheckPosBomb.z = explosive->world.pos.z + spB0.z;

                BossGanon_CheckFallingPlatforms(pthis, globalCtx, &platCheckPosBomb);
            }

            explosive = explosive->next;
        }
    }

    BossGanon_UpdateEffects(globalCtx);

    prop = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

    // if a platform is lit up, change the room lighting
    while (prop != NULL) {
        if (prop->id != ACTOR_BG_GANON_OTYUKA) {
            prop = prop->next;
        } else {
            platform = (BgGanonOtyuka*)prop;

            if (platform->flashState != 0) {
                pthis->envLightMode = 1;
                break;
            }

            prop = prop->next;
        }
    }

    globalCtx->envCtx.unk_BF = 0;
    globalCtx->envCtx.unk_BE = 0;
    globalCtx->envCtx.unk_DC = 2;

    switch (pthis->envLightMode) {
        case -1:
            break;
        case 0:
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.0f, 1.0f, 0.02f);
            break;
        case 1:
            globalCtx->envCtx.unk_BD = 1;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.1f);
            break;
        case 2:
            globalCtx->envCtx.unk_BD = 1;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.02f);
            break;
        case 3:
            globalCtx->envCtx.unk_BD = 3;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 35:
            globalCtx->envCtx.unk_BD = 0;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 4:
            globalCtx->envCtx.unk_BD = 4;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 5:
            globalCtx->envCtx.unk_BE = 5;
            globalCtx->envCtx.unk_BD = 3;
            Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.075f);
            break;
        case 6:
            globalCtx->envCtx.unk_BE = 5;
            globalCtx->envCtx.unk_D8 = 0.0f;
            break;
        case 65:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 6;
            Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 7:
            globalCtx->envCtx.unk_BE = 7;
            globalCtx->envCtx.unk_D8 = 0.0f;
            break;
        case 75:
            globalCtx->envCtx.unk_BE = 4;
            globalCtx->envCtx.unk_BD = 8;
            Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 8:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 9;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            break;
        case 9:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 0xA;
            Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 10:
            globalCtx->envCtx.unk_BE = 3;
            globalCtx->envCtx.unk_BD = 0xB;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            pthis->unk_1A4 = 0;
            break;
        case 11:
            globalCtx->envCtx.unk_BE = 0xC;
            globalCtx->envCtx.unk_BD = 0xB;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, (Math_CosS(pthis->unk_1A4 * 0x1800) * 0.5f) + 0.5f, 1.0f, 1.0f);
            break;
        case 12:
            globalCtx->envCtx.unk_BE = 0xC;
            globalCtx->envCtx.unk_BD = 3;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
            break;
        case 13:
            globalCtx->envCtx.unk_BD = 0xD;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.025f);
            break;
        case 14:
            globalCtx->envCtx.unk_BD = 0xE;
            globalCtx->envCtx.unk_D8 = 1.0f;
            break;
        case 15:
            globalCtx->envCtx.unk_BE = 0xE;
            globalCtx->envCtx.unk_BD = 0xF;
            Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.01f);
            break;
        case 16:
            globalCtx->envCtx.unk_BE = 0x10;
            globalCtx->envCtx.unk_BD = 0xF;
            Math_ApproachZeroF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 20:
            globalCtx->envCtx.unk_BE = 2;
            globalCtx->envCtx.unk_BD = 1;
            break;
        default:
            break;
    }

    pthis->envLightMode = 0;

    if (pthis->whiteFillAlpha != 0) {
        globalCtx->envCtx.screenFillColor[3] = (s8)(u8)pthis->whiteFillAlpha;
        globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] =
            globalCtx->envCtx.screenFillColor[2] = 255;
        globalCtx->envCtx.fillScreen = true;
    } else if (pthis->screenFlashTimer != 0) {
        globalCtx->envCtx.fillScreen = true;
        globalCtx->envCtx.screenFillColor[0] = globalCtx->envCtx.screenFillColor[1] =
            globalCtx->envCtx.screenFillColor[2] = 255;

        globalCtx->envCtx.screenFillColor[3] = ((pthis->screenFlashTimer % 2) != 0) ? 100 : 0;

        pthis->screenFlashTimer--;
    } else {
        globalCtx->envCtx.fillScreen = globalCtx->envCtx.screenFillColor[3] = 0;
    }

    if (pthis->lensFlareTimer != 0) {
        pthis->lensFlareTimer--;

        if (pthis->lensFlareMode == 1) {
            targetLensFlareScale = 40.0f;
        } else if (pthis->lensFlareMode == 4) {
            targetLensFlareScale = 25.0f;
        } else {
            targetLensFlareScale = 10.0f;
        }

        Math_ApproachF(&pthis->lensFlareScale, targetLensFlareScale, 0.3f, 10.0f);
    } else {
        Math_ApproachZeroF(&pthis->lensFlareScale, 1.0f, 5.0f);

        if (pthis->lensFlareScale == 0.0f) {
            pthis->lensFlareMode = 0;
        }
    }

    if (pthis->lensFlareMode != 0) {
        gCustomLensFlareOn = true;

        if (pthis->lensFlareMode == 1) {
            gCustomLensFlarePos = pthis->actor.world.pos;
        }

        gLensFlareScale = pthis->lensFlareScale;
        gLensFlareColorIntensity = 10.0f;
        gLensFlareScreenFillAlpha = 0;
    } else {
        gCustomLensFlareOn = false;
    }

    if (pthis->unk_274 != 0) {
        i = pthis->unk_274 - 1;

        pthis->unk_278.x = pthis->unk_2EC[0].x;
        pthis->unk_278.y = pthis->unk_2EC[0].y + 50.0f + 30.0f;
        pthis->unk_278.z = pthis->unk_2EC[0].z;

        xOffset = (sinf(i * 1.2566371f) * 600.0f);
        zOffset = (cosf(i * 1.2566371f) * 600.0f);

        // 5 or 6 light balls that go into the charge. not the same as the ones that he throws
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_GANON, pthis->unk_1FC.x + xOffset,
                           pthis->unk_1FC.y, pthis->unk_1FC.z + zOffset, 0, (s16)(i * 13107.2f) + 0x6000, 0, 0xFA + i);
        pthis->unk_274 = 0;
    }
}

s32 BossGanon_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    BossGanon* pthis = (BossGanon*)thisx;

    switch (limbIndex) {
        case 10:
            if (pthis->useOpenHand) {
                *dList = gDorfOpenHandDL;
            }
            break;

        case 20:
            rot->y += pthis->legRot.x + pthis->legRot.z;
            rot->z += pthis->legRot.y;
            break;

        case 21:
            if (pthis->legRot.y > 0.0f) {
                rot->z += pthis->legRot.y;
            }
            break;

        case 22:
            rot->y += pthis->legRot.x + pthis->legRot.z;
            rot->z += pthis->legRot.y;
            break;

        case 23:
            rot->y += pthis->legRot.x - pthis->legRot.z;
            rot->z += pthis->legRot.y;
            break;

        case 24:
            if (pthis->legRot.y > 0.0f) {
                rot->z += pthis->legRot.y;
            }
            break;

        case 25:
            rot->y += pthis->legRot.x - pthis->legRot.z;
            rot->z += pthis->legRot.y;
            break;

        default:
            break;
    }

    return 0;
}

void BossGanon_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    s8 bodyPart;
    BossGanon* pthis = (BossGanon*)thisx;

    bodyPart = bodyPartLimbMap_132[limbIndex];
    if (bodyPart >= 0) {
        Matrix_MultVec3f(&D_808E4DB8_132, &pthis->unk_2EC[bodyPart]);
    }

    if (limbIndex == 2) {
        Matrix_MultVec3f(&D_808E4DB8_132, &pthis->unk_1FC);
    } else if (limbIndex == 19) {
        Matrix_MultVec3f(&D_808E4DB8_132, &pthis->actor.focus.pos);
    } else if (limbIndex == 11) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7191);

        Matrix_MultVec3f(&D_808E4DB8_132, &pthis->unk_208);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7196),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(object_ganon_DL_00BE90));

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7198);
    } else if (limbIndex == 6) {
        Matrix_MultVec3f(&D_808E4DC4_132, &pthis->unk_238);
    } else if (limbIndex == 10) {
        Matrix_MultVec3f(&D_808E4DD0_132, &pthis->unk_22C);

        if (pthis->unk_25C == 0) {
            Matrix_MultVec3f(&D_808E4DDC_132, &pthis->unk_260);
        }

        pthis->unk_25C = 0;

        if (pthis->triforceType == GDF_TRIFORCE_DORF) {
            Matrix_MultVec3f(&D_808E4DE8_132, &pthis->triforcePos);
        }
    } else if (limbIndex == 4) {
        Vec3f sp28 = D_808E4DA0_132;

        if (pthis->unk_198 == 1) {
            sp28.x += -300.0f;
            sp28.y += -300.0f;
            sp28.z += 700.0f;
        } else if (pthis->unk_198 == 2) {
            sp28.x += -300.0f;
            sp28.z += 700.0f;
        }

        Matrix_MultVec3f(&sp28, &pthis->unk_220);
    } else if (limbIndex == 8) {
        Vec3f sp1C = D_808E4DAC_132;

        if (pthis->unk_198 == 1) {
            sp1C.x += -300.0f;
            sp1C.y += -300.0f;
            sp1C.z += -700.0f;
        } else if (pthis->unk_198 == 2) {
            sp1C.x += -300.0f;
            sp1C.y += 100.0f;
            sp1C.z += -700.0f;
        }

        Matrix_MultVec3f(&sp1C, &pthis->unk_214);
    }
}

void BossGanon_InitRand(s32 seedInit0, s32 seedInit1, s32 seedInit2) {
    sSeed1 = seedInit0;
    sSeed2 = seedInit1;
    sSeed3 = seedInit2;
}

f32 BossGanon_RandZeroOne(void) {
    // Wichmann-Hill algorithm
    f32 randFloat;

    sSeed1 = (sSeed1 * 171) % 30269;
    sSeed2 = (sSeed2 * 172) % 30307;
    sSeed3 = (sSeed3 * 170) % 30323;

    randFloat = (sSeed1 / 30269.0f) + (sSeed2 / 30307.0f) + (sSeed3 / 30323.0f);

    while (randFloat >= 1.0f) {
        randFloat -= 1.0f;
    }

    return fabsf(randFloat);
}

void BossGanon_DrawShock(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;

    OPEN_DISPS(gfxCtx, "../z_boss_ganon.c", 7350);

    if ((pthis->unk_2E8 != 0) || (pthis->unk_2E6 != 0)) {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
        gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

        if (pthis->unk_2E8 != 0) {
            Player* player = GET_PLAYER(globalCtx);

            for (i = 0; i < ARRAY_COUNT(player->bodyPartsPos); i++) {
                Matrix_Translate(player->bodyPartsPos[i].x, player->bodyPartsPos[i].y, player->bodyPartsPos[i].z,
                                 MTXMODE_NEW);
                func_800D1FD4(&globalCtx->billboardMtxF);
                Matrix_Scale(pthis->unk_49C[i], pthis->unk_49C[i], pthis->unk_49C[i], MTXMODE_APPLY);
                Matrix_RotateZ(Rand_CenteredFloat(M_PI), MTXMODE_APPLY);
                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7384),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
            }
        } else {
            for (i = 1; i < 15; i++) {
                Matrix_Translate(pthis->unk_2EC[i].x, pthis->unk_2EC[i].y, pthis->unk_2EC[i].z, MTXMODE_NEW);
                func_800D1FD4(&globalCtx->billboardMtxF);
                Matrix_Scale(pthis->unk_49C[i], pthis->unk_49C[i], pthis->unk_49C[i], MTXMODE_APPLY);

                if (!pthis->shockGlow) {
                    Matrix_RotateZ(Rand_CenteredFloat(M_PI), MTXMODE_APPLY);
                }

                gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7401),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                if (pthis->shockGlow) {
                    gSPSegment(POLY_XLU_DISP++, 0x08,
                               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0,
                                                (pthis->unk_1A2 + i) * -15, 32, 64));
                    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 255, 170, 255);
                    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 128);
                    gSPDisplayList(POLY_XLU_DISP++, gDorfShockGlowDL);
                } else {
                    gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
                }
            }
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_boss_ganon.c", 7465);
}

void BossGanon_DrawHandLightBall(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 alpha;

    OPEN_DISPS(gfxCtx, "../z_boss_ganon.c", 7476);

    if (pthis->handLightBallScale > 0.0f) {
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);

        if ((pthis->unk_1A2 % 2) != 0) {
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
        } else {
            gDPSetEnvColor(POLY_XLU_DISP++, 100, 255, 0, 0);
        }

        gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

        Matrix_Translate(pthis->unk_260.x, pthis->unk_260.y, pthis->unk_260.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_Scale(pthis->handLightBallScale, pthis->handLightBallScale, pthis->handLightBallScale, MTXMODE_APPLY);
        Matrix_RotateZ(pthis->unk_258, 1);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7510),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);

        alpha = ((pthis->unk_1A2 % 2) != 0) ? 100 : 80;
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 155, alpha);
        Matrix_Translate(pthis->unk_260.x, 0.0f, pthis->unk_260.z, MTXMODE_NEW);
        Matrix_Scale(pthis->handLightBallScale * 0.75f, 1.0f, pthis->handLightBallScale * 0.75f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7531),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfLightCoreDL);

        CLOSE_DISPS(gfxCtx, "../z_boss_ganon.c", 7534);
    }
}

void BossGanon_DrawBigMagicCharge(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 yRot;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;

    OPEN_DISPS(gfxCtx, "../z_boss_ganon.c", 7548);

    if (pthis->unk_284 > 0.0f) {
        func_80093D84(globalCtx->state.gfxCtx);

        // light flecks
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, (s8)pthis->unk_290);
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 255, 0, 128);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->unk_1A2 * -2, 0, 0x40, 0x40, 1, 0,
                                    pthis->unk_1A2 * 0xA, 0x40, 0x40));
        Matrix_Translate(pthis->unk_278.x, pthis->unk_278.y, pthis->unk_278.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_Scale(pthis->unk_28C, pthis->unk_28C, pthis->unk_28C, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7588),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfLightFlecksDL);

        // background circle texture
        Matrix_Translate(pthis->unk_278.x, pthis->unk_278.y, pthis->unk_278.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_Scale(pthis->unk_284, pthis->unk_284, pthis->unk_284, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7601),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 0, 100, (s8)pthis->unk_288);
        gSPSegment(
            POLY_XLU_DISP++, 0x09,
            Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, 0, pthis->unk_1A2 * -4, 0x20, 0x20));
        gSPDisplayList(POLY_XLU_DISP++, gDorfBigMagicBGCircleDL);

        // yellow background dot
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 150, 170, 0, (s8)pthis->unk_288);
        gSPSegment(POLY_XLU_DISP++, 0x0A,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, pthis->unk_1A2 * 2,
                                    pthis->unk_1A2 * -0x14, 0x40, 0x40));
        gSPDisplayList(POLY_XLU_DISP++, gDorfDotDL);

        // light ball material
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 100, 0);
        gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

        // light ball geometry
        Matrix_Translate(pthis->unk_278.x, pthis->unk_278.y, pthis->unk_278.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_Scale(pthis->unk_2D0, pthis->unk_2D0, pthis->unk_2D0, MTXMODE_APPLY);
        Matrix_RotateZ((pthis->unk_1A2 * 10.0f) / 1000.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7673),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);

        BossGanon_InitRand(pthis->unk_1AA + 1, 0x71AC, 0x263A);
        Matrix_Translate(pthis->unk_278.x, pthis->unk_278.y, pthis->unk_278.z, MTXMODE_NEW);
        Matrix_RotateY((pthis->unk_1A2 * 10.0f) / 1000.0f, MTXMODE_APPLY);
        gDPSetEnvColor(POLY_XLU_DISP++, 200, 255, 0, 0);

        yRot = BINANG_TO_RAD(pthis->actor.yawTowardsPlayer);

        for (i = 0; i < pthis->unk_1AC; i++) {
            f32 xzRot = (BossGanon_RandZeroOne() - 0.5f) * M_PI * 1.5f;

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)pthis->unk_294[i]);
            Matrix_Push();
            Matrix_RotateY(xzRot + yRot, MTXMODE_APPLY);
            Matrix_RotateX((BossGanon_RandZeroOne() - 0.5f) * M_PI, MTXMODE_APPLY);
            Matrix_RotateZ(xzRot, MTXMODE_APPLY);
            Matrix_Translate(0.0f, 0.0f, 50.0f, MTXMODE_APPLY);
            Matrix_Scale(4.0f, 4.0f, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 7713),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfLightRayTriDL);

            Matrix_Pop();
        }

        CLOSE_DISPS(gfxCtx, "../z_boss_ganon.c", 7721);
    }
}

void BossGanon_DrawTriforce(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (pthis->fwork[GDF_TRIFORCE_PRIM_A] > 0.0f) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7732);

        Matrix_Push();

        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, (u8)pthis->fwork[GDF_TRIFORCE_PRIM_B],
                        (s8)pthis->fwork[GDF_TRIFORCE_PRIM_A]);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, (u8)pthis->fwork[GDF_TRIFORCE_ENV_G], 0, 128);

        if (pthis->triforceType == GDF_TRIFORCE_PLAYER) {
            Player* player = GET_PLAYER(globalCtx);

            pthis->triforcePos = player->bodyPartsPos[12];

            pthis->triforcePos.x += -0.6f;
            pthis->triforcePos.y += 3.0f;
            pthis->triforcePos.z += -2.0f;
        } else if (pthis->triforceType == GDF_TRIFORCE_ZELDA) {
            pthis->triforcePos = sZelda->unk_31C;

            pthis->triforcePos.y += 1.8f;
            pthis->triforcePos.z += 4.0f;
        }

        Matrix_Translate(pthis->triforcePos.x, pthis->triforcePos.y, pthis->triforcePos.z, MTXMODE_NEW);

        if (pthis->triforceType == GDF_TRIFORCE_PLAYER) {
            Matrix_RotateX(-1.4f, MTXMODE_APPLY);
            Matrix_RotateZ(4.0f, MTXMODE_APPLY);
        } else if (pthis->triforceType == GDF_TRIFORCE_ZELDA) {
            Matrix_RotateY(1.5f, 1);
            Matrix_RotateX(1.1f, 1);
            Matrix_RotateZ(-0.99999994f, MTXMODE_APPLY);
        } else {
            func_800D1FD4(&globalCtx->billboardMtxF);
        }

        Matrix_Scale(pthis->fwork[GDF_TRIFORCE_SCALE], pthis->fwork[GDF_TRIFORCE_SCALE], 1.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7779),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gDorfTriforceDL));

        Matrix_Pop();

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7782);
    }
}

void BossGanon_DrawDarkVortex(BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if (pthis->fwork[GDF_VORTEX_ALPHA] > 0.0f) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7792);

        Matrix_Push();
        gDPPipeSync(POLY_XLU_DISP++);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, pthis->unk_1A2 * -8, 0, 0x20, 0x40, 1,
                                    pthis->unk_1A2 * -4, pthis->unk_1A2 * -8, 0x20, 0x20));
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 0, 200, (s8)pthis->fwork[GDF_VORTEX_ALPHA]);
        gDPSetEnvColor(POLY_XLU_DISP++, 130, 0, 0, 128);

        if (pthis->csState != 21) {
            Matrix_Translate(0.0f, 105.0f, -400.0f, MTXMODE_NEW);
            Matrix_RotateX(M_PI / 2, MTXMODE_APPLY);
        } else {
            Matrix_Translate(-50.0f, 50.0f, -150.0f, MTXMODE_NEW);
            Matrix_RotateY(M_PI / 10, MTXMODE_APPLY);
            Matrix_RotateX(M_PI / 2, MTXMODE_APPLY);
        }

        Matrix_Scale(pthis->fwork[GDF_VORTEX_SCALE], pthis->fwork[GDF_VORTEX_SCALE], pthis->fwork[GDF_VORTEX_SCALE],
                     MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7841),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gDorfVortexDL));

        Matrix_Pop();

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 7844);
    }
}

void func_808E0254(BossGanon* pthis, u8* tex, f32 arg2) {
    s16 baseX;
    s16 index;
    s16 i;
    s16 baseY;
    s16 x;
    s16 addY;
    f32 lerpX;
    s16 y;
    f32 lerpY;
    f32 lerpZ;
    Vec3f sp68;
    Vec3f sp5C;

    for (i = 0; i < 15; i++) {
        if (arg2 == 0.0f || (y = D_808E4E38_140[i]) >= 0) {
            if (arg2 > 0.0f) {
                lerpX = pthis->unk_2EC[i].x + (pthis->unk_2EC[y].x - pthis->unk_2EC[i].x) * arg2;
                lerpY = pthis->unk_2EC[i].y + (pthis->unk_2EC[y].y - pthis->unk_2EC[i].y) * arg2;
                lerpZ = pthis->unk_2EC[i].z + (pthis->unk_2EC[y].z - pthis->unk_2EC[i].z) * arg2;

                sp68.x = lerpX - pthis->actor.world.pos.x;
                sp68.y = lerpY - pthis->actor.world.pos.y + 76 + 30 + 30;
                sp68.z = lerpZ - pthis->actor.world.pos.z;
            } else {

                sp68.x = pthis->unk_2EC[i].x - pthis->actor.world.pos.x;
                sp68.y = pthis->unk_2EC[i].y - pthis->actor.world.pos.y + 76 + 30 + 30;
                sp68.z = pthis->unk_2EC[i].z - pthis->actor.world.pos.z;
            }
            Matrix_MultVec3f(&sp68, &sp5C);

            sp5C.x *= 0.4f;
            sp5C.y *= 0.4f;

            baseX = (s16)(sp5C.x + 32.0f);
            baseY = (s16)sp5C.y * 64;

            if (D_808E4E58_140[i] == 2) {
                for (y = 0, addY = -0x180; y < 12; y++, addY += 0x40) {
                    for (x = -D_808E4E20_140[y]; x < D_808E4E20_140[y]; x++) {
                        index = baseX + x + baseY + addY;
                        if ((index >= 0) && (index < 0x1000)) {
                            tex[index] = 255;
                        }
                    }
                }
            } else if (D_808E4E58_140[i] == 1) {
                for (y = 0, addY = -0x100; y < 8; y++, addY += 0x40) {
                    for (x = -D_808E4E10_140[y]; x < D_808E4E10_140[y]; x++) {
                        index = baseX + x + baseY + addY;
                        if ((index >= 0) && (index < 0x1000)) {
                            tex[index] = 255;
                        }
                    }
                }
            } else if (D_808E4E58_140[i] == 0) {
                for (y = 0, addY = -0xC0; y < 7; y++, addY += 0x40) {
                    for (x = -D_808E4E00_140[y]; x < D_808E4E00_140[y] - 1; x++) {
                        index = baseX + x + baseY + addY;
                        if ((index >= 0) && (index < 0x1000)) {
                            tex[index] = 255;
                        }
                    }
                }
            } else {
                for (y = 0, addY = -0x80; y < 6; y++, addY += 0x40) {
                    for (x = -D_808E4DF4_140[y]; x < D_808E4DF4_140[y] - 1; x++) {
                        index = baseX + x + baseY + addY;
                        if ((index >= 0) && (index < 0x1000)) {
                            tex[index] = 255;
                        }
                    }
                }
            }
        }
    }
}

void BossGanon_GenShadowTexture(u8* tex, BossGanon* pthis, GlobalContext* globalCtx) {
    s16 addY;
    s16 baseX;
    s16 baseY;
    s16 i;
    s16 j;
    s16 y;
    s16 x;
    s16 index;
    Vec3f sp7C;
    Vec3f sp70;
    s32* ptr = (s32*)tex;

    for (i = 0; i < 64 * 64 / 4; i++, ptr++) {
        *ptr = 0;
    }

    Matrix_RotateX(1.0f, MTXMODE_NEW);

    for (i = 0; i <= 5; i++) {
        func_808E0254(pthis, tex, i / 5.0f);
    }

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            sp7C.x = sCape->strands[i].joints[j].x - pthis->actor.world.pos.x;
            sp7C.y = sCape->strands[i].joints[j].y - pthis->actor.world.pos.y + 76.0f + 100.0f + 30.0f;
            sp7C.z = sCape->strands[i].joints[j].z - pthis->actor.world.pos.z;

            Matrix_MultVec3f(&sp7C, &sp70);

            sp70.x = sp70.x * 0.28f;
            sp70.y = sp70.y * 0.28f;

            baseX = (s32)(sp70.x + 32.0f);
            baseY = (s16)sp70.y * 0x40;

            if (!sCape->strands[i].torn[j]) {
                for (y = -1, addY = -0x40; y <= 1; y++, addY += 0x40) {
                    for (x = -3; x <= 3; x++) {
                        index = baseX + x + baseY + addY;
                        if (0 <= index && index < 0x1000) {
                            tex[index] = 255;
                        }
                    }
                }
            } else {
                for (y = -1, addY = -0x40; y <= 1; y++, addY += 0x40) {
                    for (x = -1; x <= 1; x++) {
                        index = baseX + x + baseY + addY;
                        if (0 <= index && index < 0x1000) {
                            tex[index] = 255;
                        }
                    }
                }
            }
        }
    }
}

void BossGanon_DrawShadowTexture(void* tex, BossGanon* pthis, GlobalContext* globalCtx) {
    s32 pad;
    f32 zOffset;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_boss_ganon.c", 8372);

    func_80093D18(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, 50);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

    if (pthis->csState < 100) {
        zOffset = (((((pthis->actor.world.pos.y - 10) + 70.0f) * -5.0f) / 10.0f) + 10.0f);
        Matrix_Translate(pthis->actor.world.pos.x, 0.0f, pthis->actor.world.pos.z + zOffset, MTXMODE_NEW);
    } else {
        Matrix_Translate(pthis->actor.world.pos.x, 4102.0f, pthis->actor.world.pos.z - 20.0f, MTXMODE_NEW);
    }

    Matrix_Scale(0.95000005f, 1.0f, 0.95000005f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 8396),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDorfShadowSetupDL);
    gDPLoadTextureBlock(POLY_OPA_DISP++, tex, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPDisplayList(POLY_OPA_DISP++, gDorfShadowModelDL);

    CLOSE_DISPS(gfxCtx, "../z_boss_ganon.c", 8426);
}

void BossGanon_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 i;
    BossGanon* pthis = (BossGanon*)thisx;
    void* shadowTex;

    shadowTex = Graph_Alloc(globalCtx->state.gfxCtx, 64 * 64);

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9138);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    if ((pthis->unk_1A6 & 2) != 0) {
        POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 50, 0, 0, 900, 1099);
    }

    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gDorfEyeTex));

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          BossGanon_OverrideLimbDraw, BossGanon_PostLimbDraw, &pthis->actor);

    pthis->unk_2EC[0].x = pthis->unk_2EC[1].x;
    pthis->unk_2EC[0].y = pthis->unk_2EC[1].y + 30.0f;
    pthis->unk_2EC[0].z = pthis->unk_2EC[1].z;

    POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);

    BossGanon_DrawEffects(globalCtx);

    sCape->actor.world.pos = pthis->actor.world.pos;

    sCape->rightForearmPos = pthis->unk_214;
    sCape->leftForearmPos = pthis->unk_220;

    sCape->rightShoulderPos = pthis->unk_22C;
    sCape->leftShoulderPos = pthis->unk_238;

    BossGanon_DrawShock(pthis, globalCtx);
    BossGanon_DrawHandLightBall(pthis, globalCtx);
    BossGanon_DrawBigMagicCharge(pthis, globalCtx);
    BossGanon_DrawTriforce(pthis, globalCtx);
    BossGanon_DrawDarkVortex(pthis, globalCtx);

    BossGanon_GenShadowTexture((u8*)shadowTex, pthis, globalCtx);
    BossGanon_DrawShadowTexture(shadowTex, pthis, globalCtx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9393);
}

s32 BossGanon_CheckFallingPlatforms(BossGanon* pthis, GlobalContext* globalCtx, Vec3f* checkPos) {
    Actor* prop = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;

    while (prop != NULL) {
        if (((BossGanon*)prop == pthis) || (prop->id != ACTOR_BG_GANON_OTYUKA)) {
            prop = prop->next;
        } else {
            BgGanonOtyuka* platform = (BgGanonOtyuka*)prop;
            f32 xDiff = platform->dyna.actor.world.pos.x - checkPos->x;
            f32 yDiff = platform->dyna.actor.world.pos.y - checkPos->y;
            f32 zDiff = platform->dyna.actor.world.pos.z - checkPos->z;

            if ((fabsf(xDiff) < 60.0f) && (yDiff < 20.0f) && (yDiff > -20.0f) && (fabsf(zDiff) < 60.0f)) {
                platform->isFalling = true;
                platform->visibleSides = OTYUKA_SIDE_ALL;

                return 1;
            } else {
                prop = prop->next;
            }
        }
    }

    return 0;
}

void BossGanon_LightBall_Update(Actor* thisx, GlobalContext* globalCtx2) {
    u8 hitWithBottle;
    s16 i;
    s16 spBA = 0;
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    BossGanon* pthis = (BossGanon*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    f32 xDistFromLink;
    f32 yDistFromLink;
    f32 zDistFromLink;
    f32 minReflectDist;
    f32 xDistFromGanondorf;
    f32 yDistFromGanondorf;
    f32 zDistFromGanondorf;
    Player* player = GET_PLAYER(globalCtx);
    s32 pad;
    BossGanon* ganondorf = (BossGanon*)pthis->actor.parent;
    s32 pad1;

    pthis->unk_1A2++;
    ganondorf->envLightMode = 1;

    if (pthis->unk_1A8 != 0) {
        if (pthis->unk_1A8 == 2) {
            Math_ApproachZeroF(&pthis->fwork[GDF_FWORK_1], 1.0f, 10.0f);
            Math_ApproachF(&pthis->actor.scale.x, 30.0f, 0.5f, 100.0f);
        } else {
            pthis->actor.shape.rot.y += 0x1000;
            ganondorf->lensFlareTimer = 1;
            gCustomLensFlarePos = pthis->actor.world.pos;
            Math_ApproachZeroF(&pthis->fwork[GDF_FWORK_1], 1.0f, 30.0f);
            Math_ApproachF(&pthis->actor.scale.x, 20.0f, 0.5f, 100.0f);
            pthis->fwork[GDF_FWORK_0] += ((M_PI / 2) + Rand_ZeroFloat(M_PI / 4));
        }

        Actor_SetScale(&pthis->actor, pthis->actor.scale.x);

        if (pthis->fwork[GDF_FWORK_1] == 0.0f) {
            Actor_Kill(&pthis->actor);
        }
    } else {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_FIRE - SFX_FLAG);

        if ((pthis->unk_1A2 % 2) != 0) {
            Actor_SetScale(&pthis->actor, 6.0f);
        } else {
            Actor_SetScale(&pthis->actor, 5.25f);
        }

        pthis->actor.shape.rot.z += (s16)(Rand_ZeroOne() * 20000.0f) + 0x4000;

        for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
            if (pthis->timers[i] != 0) {
                pthis->timers[i]--;
            }
        }

        xDistFromGanondorf = ganondorf->unk_1FC.x - pthis->actor.world.pos.x;
        yDistFromGanondorf = ganondorf->unk_1FC.y - pthis->actor.world.pos.y;
        zDistFromGanondorf = ganondorf->unk_1FC.z - pthis->actor.world.pos.z;

        xDistFromLink = player->actor.world.pos.x - pthis->actor.world.pos.x;
        yDistFromLink = (player->actor.world.pos.y + 40.0f) - pthis->actor.world.pos.y;
        zDistFromLink = player->actor.world.pos.z - pthis->actor.world.pos.z;

        func_8002D908(&pthis->actor);
        func_8002D7EC(&pthis->actor);

        switch (pthis->unk_1C2) {
            case 0:
                if ((player->stateFlags1 & 2) &&
                    (ABS((s16)(player->actor.shape.rot.y - (s16)(ganondorf->actor.yawTowardsPlayer + 0x8000))) <
                     0x2000) &&
                    (sqrtf(SQ(xDistFromLink) + SQ(yDistFromLink) + SQ(zDistFromLink)) <= 25.0f)) {
                    hitWithBottle = true;
                } else {
                    hitWithBottle = false;
                }

                if ((pthis->collider.base.acFlags & 2) || hitWithBottle) {
                    ColliderInfo* acHitInfo = pthis->collider.info.acHitInfo;

                    pthis->collider.base.acFlags &= ~2;

                    if ((hitWithBottle == false) && (acHitInfo->toucher.dmgFlags & 0x100000)) {
                        spBA = 2;
                        Audio_PlaySoundGeneral(NA_SE_IT_SHIELD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                        Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xFF, 0x14, 0x96);
                    } else {
                        spBA = 1;
                        pthis->actor.world.rot.y = Math_Atan2S(zDistFromGanondorf, xDistFromGanondorf);
                        pthis->actor.world.rot.x =
                            Math_Atan2S(sqrtf(SQ(xDistFromGanondorf) + SQ(zDistFromGanondorf)), yDistFromGanondorf);
                        pthis->unk_1A4++;
                        pthis->timers[1] = 2;
                        Audio_PlaySoundGeneral(NA_SE_IT_SWORD_REFLECT_MG, &player->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                        Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xB4, 0x14, 0x64);

                        if (hitWithBottle == false) {
                            // if ganondorf is 250 units away from link, at least 3 volleys are required
                            if ((ganondorf->actor.xyzDistToPlayerSq > 62500.0f) && (pthis->unk_1A4 < 3)) {
                                pthis->unk_1C2 = 1;
                            } else if (Rand_ZeroOne() < 0.7f) {
                                pthis->unk_1C2 = 1;
                            } else {
                                pthis->unk_1C2 = 3;
                            }

                            // if a spin attack is used
                            if (player->swordAnimation >= 0x18) {
                                pthis->actor.speedXZ = 20.0f;
                            }
                            break;
                        } else {
                            if (Rand_ZeroOne() < 0.9f) {
                                pthis->unk_1C2 = 1;
                            } else {
                                pthis->unk_1C2 = 3;
                            }
                        }
                    }
                } else {
                    if (sqrtf(SQ(xDistFromLink) + SQ(yDistFromLink) + SQ(zDistFromLink)) <= 25.0f) {
                        spBA = 5;
                        func_8002F6D4(globalCtx, &pthis->actor, 3.0f, pthis->actor.world.rot.y, 0.0f, 0x30);
                        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_GANON_HIT_THUNDER);
                        ganondorf->timers[2] = 20;

                        for (i = 0; i < ARRAY_COUNT(ganondorf->unk_4E4); i++) {
                            ganondorf->unk_4E4[i] = D_808E4C58[i];
                        }

                        ganondorf->unk_2E6 = 0;
                        ganondorf->unk_2E8 = 60;
                        ganondorf->unk_508 = 4.0f;
                    }
                }
                break;

            case 1:
                if ((ganondorf->actionFunc == BossGanon_PlayTennis) && (ganondorf->unk_1C2 == 1)) {
                    minReflectDist = (pthis->actor.speedXZ >= 19.0f) ? 250.0f : 170.0f;

                    if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) <
                        minReflectDist) {
                        ganondorf->startVolley = true;
                        pthis->timers[0] = 8;
                        pthis->unk_1C2 = 2;
                    }
                }
                break;

            case 2:
                if (pthis->timers[0] == 1) {
                    spBA = 1;
                    pthis->actor.world.rot.y = Math_Atan2S(zDistFromLink, xDistFromLink);
                    pthis->actor.world.rot.x = Math_Atan2S(sqrtf(SQ(xDistFromLink) + SQ(zDistFromLink)), yDistFromLink);
                    pthis->timers[1] = 2;
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_IT_SWORD_REFLECT_MG);
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_GANON_AT_RETURN);
                    pthis->unk_1C2 = 0;
                    break;
                }
                // fallthrough
            case 4:
                if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) < 30.0f) {
                    spBA = 3;
                    Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_GANON_DAMAGE1);
                    Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_GANON_HIT_THUNDER);
                }
                break;

            case 3:
                if (sqrtf(SQ(xDistFromGanondorf) + SQ(yDistFromGanondorf) + SQ(zDistFromGanondorf)) < 100.0f) {
                    ganondorf->startVolley = true;
                    pthis->unk_1C2 = 4;
                }
                break;
        }

        Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

        if (pthis->timers[1] == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }

        for (i = 0; i < 2; i++) {
            spA0.x = spA0.z = 0.0f;
            spA0.y = 0.2f;

            spAC.x = spAC.y = spAC.z = 0.0f;

            sp94.x = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.x;
            sp94.y = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.y;
            sp94.z = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.z;

            BossGanonEff_SpawnSparkle(globalCtx, &sp94, &spAC, &spA0, Rand_ZeroFloat(500.0f) + 700.0f, 0x1E);
        }

        if (pthis->actor.world.pos.y < 10.0f) {
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 20.0f, 20.0f, 4);
        }

        if ((fabsf(pthis->actor.world.pos.x) > 465.0f) || (pthis->actor.world.pos.y > 500.0f) ||
            (fabsf(pthis->actor.world.pos.z) > 465.0f)) {
            spBA = 4;
        }

        if ((spBA != 0) || (pthis->actor.bgCheckFlags & 1)) {
            f32 sp58;
            f32 sp54;
            f32 phi_f20;
            s16 sp4E;

            if (spBA == 1) {
                sp58 = Rand_ZeroFloat(100.0f) + 300.0f;
                sp54 = 10.0f;
                phi_f20 = 25.0f;
                sp4E = 40;
            } else {
                sp58 = Rand_ZeroFloat(200.0f) + 500.0f;
                sp54 = 15.0f;
                phi_f20 = 30.0f;
                sp4E = 70;
                Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 80, NA_SE_EN_GANON_HIT_THUNDER);
            }

            for (i = 0; i < sp4E; i++) {
                if (spBA != 0) {
                    spAC.x = Rand_CenteredFloat(phi_f20);
                    spAC.y = Rand_CenteredFloat(phi_f20);
                    spAC.z = Rand_CenteredFloat(phi_f20);
                } else {
                    spAC.x = Rand_CenteredFloat(phi_f20);
                    spAC.y = Rand_ZeroFloat(25.0f);
                    spAC.z = Rand_CenteredFloat(phi_f20);
                }

                BossGanonEff_SpawnLightRay(globalCtx, &pthis->actor.world.pos, &spAC, &sZeroVec, sp58, sp54, 0x1E);
            }

            if (spBA != 1) {
                pthis->unk_1A8 = 1;

                if (spBA == 0) {
                    BossGanon_CheckFallingPlatforms(pthis, globalCtx, &pthis->actor.world.pos);
                }

                if (spBA == 3) {
                    BossGanon_SetupHitByLightBall(ganondorf, globalCtx);
                } else if (ganondorf->actionFunc == BossGanon_PlayTennis) {
                    BossGanon_SetupWait(ganondorf, globalCtx);

                    if (spBA == 5) {
                        ganondorf->timers[0] = 125;
                    }
                }
            }
        }
    }
}

void BossGanon_LightBall_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon* pthis = (BossGanon*)thisx;
    s16 i;
    f32 alpha;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9849);

    func_80093D84(globalCtx->state.gfxCtx);

    alpha = ((pthis->unk_1A2 % 2) != 0) ? pthis->fwork[GDF_FWORK_1] * 0.4f : pthis->fwork[GDF_FWORK_1] * 0.35f;

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 155, (s8)alpha);
    Matrix_Push();
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.floorHeight, pthis->actor.world.pos.z, MTXMODE_NEW);
    Matrix_Scale(pthis->actor.scale.x * 0.75f, 1.0f, pthis->actor.scale.z * 0.75f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9875),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gDorfLightCoreDL);

    Matrix_Pop();
    gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)pthis->fwork[GDF_FWORK_1]);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);

    if (pthis->unk_1A8 == 1) {
        for (i = 0; i < 8; i++) {
            Matrix_Push();
            Matrix_RotateY(i * (M_PI / 8), MTXMODE_APPLY);
            Matrix_RotateZ(pthis->fwork[GDF_FWORK_0], MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9899),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
            Matrix_Pop();
        }
    } else if (pthis->unk_1A8 == 0) {
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_RotateZ((pthis->actor.shape.rot.z / 32768.0f) * 3.1416f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9907),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 9911);
}

void func_808E1EB4(Actor* thisx, GlobalContext* globalCtx2) {
    s16 i;
    BossGanon* pthis = (BossGanon*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    BossGanon* dorf = (BossGanon*)pthis->actor.parent;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 xzDist;
    s16 xRotTarget;
    s16 yRotTarget;
    Vec3f vel;
    Vec3f accel;

    pthis->unk_1A2++;
    dorf->envLightMode = 1;
    Actor_SetScale(&pthis->actor, 6.0f);
    pthis->actor.shape.rot.z += ((s16)(Rand_ZeroOne() * 20000.0f) + 0x4000);

    for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }

    func_8002D908(&pthis->actor);
    func_8002D7EC(&pthis->actor);

    pthis->unk_1A6++;

    if (pthis->unk_1A6 >= 15) {
        pthis->unk_1A6 = 0;
    }

    pthis->unk_2EC[pthis->unk_1A6] = pthis->actor.world.pos;

    if (pthis->unk_1C2 == 0) {
        if (1) {}
        if (pthis->timers[0] == 0) {
            pthis->unk_1C2 = 1;
        }
    } else if (pthis->unk_1C2 == 1) {
        xDiff = dorf->unk_1FC.x - pthis->actor.world.pos.x;
        yDiff = dorf->unk_1FC.y - pthis->actor.world.pos.y;
        zDiff = dorf->unk_1FC.z - pthis->actor.world.pos.z;

        yRotTarget = RADF_TO_BINANG(Math_FAtan2F(xDiff, zDiff));
        xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
        xRotTarget = RADF_TO_BINANG(Math_FAtan2F(yDiff, xzDist));

        Math_ApproachS(&pthis->actor.world.rot.x, xRotTarget, 1, 0x1000);
        Math_ApproachS(&pthis->actor.world.rot.y, yRotTarget, 1, 0x1000);

        if (sqrtf(SQ(xDiff) + SQ(zDiff) + SQ(yDiff)) < 40.0f) {
            pthis->unk_1C2 = 2;
            pthis->timers[0] = 30;
            pthis->actor.speedXZ = 0.0f;

            if (pthis->actor.params == 0xC8) {
                func_80078884(NA_SE_EN_GANON_DAMAGE2);
                func_80078884(NA_SE_EN_GANON_DD_THUNDER);

                for (i = 0; i < 150; i++) {

                    vel.x = Rand_CenteredFloat(25.0f);
                    vel.y = Rand_CenteredFloat(25.0f);
                    vel.z = Rand_CenteredFloat(25.0f);

                    accel.x = vel.x * -0.03f;
                    accel.y = vel.y * -0.03f;
                    accel.z = vel.z * -0.03f;

                    BossGanonEff_SpawnLightRay(globalCtx, &dorf->unk_1FC, &vel, &accel,
                                               Rand_ZeroFloat(500.0f) + 1000.0f, 15.0f, 0x14);
                }

                for (i = 1; i < 15; i++) {
                    dorf->unk_4E4[i] = 1000;
                }

                dorf->unk_2E6 = 1000;
                dorf->unk_2E8 = 0;
                dorf->screenFlashTimer = 4;
                dorf->lensFlareTimer = 10;
                dorf->lensFlareMode = 1;
                dorf->unk_508 = 10.0f;

                Actor_SpawnAsChild(&globalCtx->actorCtx, &dorf->actor, globalCtx, ACTOR_BOSS_GANON, dorf->unk_1FC.x,
                                   dorf->unk_1FC.y, dorf->unk_1FC.z, 0, 0, 0, 0x12C);
            }

            pthis->actor.world.pos.y = 5000.0f;
        }
    } else if (pthis->timers[0] == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_808E229C(Actor* thisx, GlobalContext* globalCtx2) {
    BossGanon* pthis = (BossGanon*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s16 i;
    s32 temp;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10081);
    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
    gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

    for (i = 9; i >= 0; i--) {
        temp = (s16)(((pthis->unk_1A6 - i) + 0xF) % 15);
        Matrix_Translate(pthis->unk_2EC[temp].x, pthis->unk_2EC[temp].y, pthis->unk_2EC[temp].z, MTXMODE_NEW);
        Matrix_Scale(pthis->actor.scale.x * (1.0f - (i * 0.07000001f)), pthis->actor.scale.y * (1.0f - (i * 0.07000001f)),
                     pthis->actor.scale.z * (1.0f - (i * 0.07000001f)), MTXMODE_APPLY);
        func_800D1FD4(&globalCtx->billboardMtxF);
        Matrix_RotateZ(((2.0f * (i * M_PI)) / 10.0f) + BINANG_TO_RAD(pthis->actor.shape.rot.z), MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10109),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10113);
}

void func_808E2544(Actor* thisx, GlobalContext* globalCtx) {
    u8 numEffects = 0;
    s16 xRot;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 xzDist;
    f32 new_var;
    f32 sp84;
    s16 i;
    s16 sp80;
    BossGanon* pthis = (BossGanon*)thisx;
    BossGanon* dorf = (BossGanon*)pthis->actor.parent;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    ColliderInfo* acHitInfo;
    Vec3f sp60;

    pthis->unk_1A2++;
    Actor_SetScale(&pthis->actor, 0.01f);

    for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }

    func_8002D908(&pthis->actor);
    func_8002D7EC(&pthis->actor);

    pthis->unk_1A6++;

    if (pthis->unk_1A6 >= 15) {
        pthis->unk_1A6 = 0;
    }

    pthis->unk_2EC[pthis->unk_1A6] = pthis->actor.world.pos;
    pthis->unk_3C4[pthis->unk_1A6].x = BINANG_TO_RAD(pthis->actor.world.rot.x);
    pthis->unk_3C4[pthis->unk_1A6].y = BINANG_TO_RAD(pthis->actor.world.rot.y);

    switch (pthis->unk_1C2) {
        if (1) {}
        case 0:
            pthis->actor.speedXZ = 40.0f;
            Math_ApproachF(&pthis->fwork[1], 255.0f, 1.0f, 40.0f);
            xDiff = dorf->unk_278.x - pthis->actor.world.pos.x;
            yDiff = dorf->unk_278.y - pthis->actor.world.pos.y;
            zDiff = dorf->unk_278.z - pthis->actor.world.pos.z;
            sp80 = RADF_TO_BINANG(Math_FAtan2F(xDiff, zDiff));
            xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));

            xRot = RADF_TO_BINANG(Math_FAtan2F(yDiff, xzDist));
            sp84 = (xzDist * 700.0f) / 10.0f;
            if (sp84 > 6144.0f) {
                sp84 = 6144.0f;
            }

            xRot += (Math_CosS(pthis->unk_1A2 * 0x2200) * sp84);
            pthis->actor.world.rot.x = xRot;
            Math_ApproachS(&pthis->actor.shape.rot.y, sp80, 1, pthis->csCamMaxStepScale);
            Math_ApproachF(&pthis->csCamMaxStepScale, 4096.0f, 1.0f, 256.0f);
            pthis->actor.world.rot.y = (Math_SinS(pthis->unk_1A2 * 0x1A00) * sp84) + pthis->actor.shape.rot.y;

            if (sqrtf(SQ(xDiff) + SQ(zDiff) + SQ(yDiff)) < 45.0f) {
                pthis->unk_1C2 = 1;
                pthis->actor.speedXZ = 0.0f;
            }
            break;

        case 1:
            Math_ApproachZeroF(&pthis->fwork[1], 1.0f, 40.0f);

            if (pthis->fwork[1] == 0.0f) {
                Actor_Kill(&pthis->actor);
            }
            break;

        case 10:
            pthis->unk_1C2 = 0xB;
            pthis->timers[0] = 14;

            pthis->collider.dim.radius = 15;
            pthis->collider.dim.height = 20;
            pthis->collider.dim.yShift = -10;

            pthis->actor.speedXZ = 20.0f;
            pthis->fwork[1] = 255.0f;
            pthis->unk_1F0 = player->actor.world.pos;
            new_var = pthis->unk_1F0.x - pthis->actor.world.pos.x;
            pthis->actor.shape.rot.y = RADF_TO_BINANG(Math_FAtan2F(new_var, pthis->unk_1F0.z - pthis->actor.world.pos.z)) +
                                      (pthis->actor.params << 0xD) - 0x20C000;
            // fallthrough
        case 11:
            if (pthis->timers[0] != 0) {
                pthis->unk_1F0 = player->actor.world.pos;
                xDiff = pthis->unk_1F0.x - pthis->actor.world.pos.x;
                yDiff = (pthis->unk_1F0.y + 30.0f) - pthis->actor.world.pos.y;
                zDiff = pthis->unk_1F0.z - pthis->actor.world.pos.z;

                sp80 = RADF_TO_BINANG(Math_FAtan2F(xDiff, zDiff));
                pthis->actor.shape.rot.x = RADF_TO_BINANG(Math_FAtan2F(yDiff, sqrtf(SQ(xDiff) + SQ(zDiff))));
                Math_ApproachS(&pthis->actor.shape.rot.y, sp80, 1, pthis->csCamMaxStepScale);
                Math_ApproachF(&pthis->csCamMaxStepScale, 4096.0f, 1.0f, 256.0f);
            }

            sp84 = (sqrtf(pthis->actor.xyzDistToPlayerSq) * 200.0f) / 10.0f;
            if (sp84 > 13824.0f) {
                sp84 = 13824.0f;
            }

            pthis->actor.world.rot.x = (Math_CosS(pthis->unk_1A2 * 0x3400) * sp84 * 0.1f) + pthis->actor.shape.rot.x;
            pthis->actor.world.rot.y = (Math_SinS(pthis->unk_1A2 * 0x1A00) * sp84) + pthis->actor.shape.rot.y;

            if ((player->swordState != 0) && (player->swordAnimation >= 0x18) && (pthis->actor.xzDistToPlayer < 80.0f)) {
                pthis->unk_1C2 = 0xC;
                pthis->actor.speedXZ = -30.0f;
                func_8002D908(&pthis->actor);
                func_8002D7EC(&pthis->actor);
                pthis->unk_1F0 = dorf->unk_1FC;
                numEffects = 10;
                break;
            }

            if (pthis->collider.base.acFlags & 2) {
                acHitInfo = pthis->collider.info.acHitInfo;

                pthis->collider.base.acFlags &= ~2;

                if (!(acHitInfo->toucher.dmgFlags & 0x100000) || Player_HasMirrorShieldEquipped(globalCtx)) {
                    Rumble_Shake(pthis->actor.xyzDistToPlayerSq, 0xB4, 0x14, 0x64);
                    pthis->unk_1C2 = 0xC;
                    pthis->actor.speedXZ = -30.0f;

                    func_8002D908(&pthis->actor);
                    func_8002D7EC(&pthis->actor);

                    pthis->unk_1F0.x = Rand_CenteredFloat(700.0f) + dorf->unk_1FC.x;
                    pthis->unk_1F0.y = Rand_CenteredFloat(200.0f) + dorf->unk_1FC.y;
                    pthis->unk_1F0.z = Rand_CenteredFloat(700.0f) + dorf->unk_1FC.z;

                    pthis->unk_1F0.x = pthis->unk_1F0.x + ((pthis->unk_1F0.x - pthis->actor.world.pos.x) * 100.0f);
                    pthis->unk_1F0.y = pthis->unk_1F0.y + ((pthis->unk_1F0.y - pthis->actor.world.pos.y) * 100.0f);
                    pthis->unk_1F0.z = pthis->unk_1F0.z + ((pthis->unk_1F0.z - pthis->actor.world.pos.z) * 100.0f);

                    numEffects = 10;
                    break;
                }
            }

            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

            if (pthis->timers[1] == 0) {
                CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
            }

            xDiff = player->actor.world.pos.x - pthis->actor.world.pos.x;
            yDiff = (player->actor.world.pos.y + 30.0f) - pthis->actor.world.pos.y;
            zDiff = player->actor.world.pos.z - pthis->actor.world.pos.z;

            if (sqrtf(SQ(xDiff) + SQ(zDiff) + SQ(yDiff)) < 30.0f) {
                pthis->unk_1C2 = 1;
                pthis->actor.speedXZ = 0.0f;

                if (dorf->timers[2] == 0) {
                    func_8002F6D4(globalCtx, &pthis->actor, 3.0f, pthis->actor.world.rot.y, 0.0f, 0x50);
                    Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 40, NA_SE_EN_GANON_HIT_THUNDER);
                    dorf->timers[2] = 20;

                    for (i = 0; i < ARRAY_COUNT(pthis->unk_4E4); i++) {
                        dorf->unk_4E4[i] = D_808E4C58[i];
                    }

                    dorf->unk_2E6 = 0;
                    dorf->unk_2E8 = 60;
                    dorf->unk_508 = 4.0f;
                    numEffects = 40;
                }
            }
            break;

        case 12:
            pthis->actor.speedXZ = 20.0f;

            xDiff = pthis->unk_1F0.x - pthis->actor.world.pos.x;
            yDiff = pthis->unk_1F0.y - pthis->actor.world.pos.y;
            zDiff = pthis->unk_1F0.z - pthis->actor.world.pos.z;

            sp80 = RADF_TO_BINANG(Math_FAtan2F(xDiff, zDiff));
            xzDist = sqrtf(SQ(xDiff) + SQ(zDiff));
            xRot = RADF_TO_BINANG(Math_FAtan2F(yDiff, xzDist));
            sp84 = (xzDist * 700.0f) / 10.0f;

            if (sp84 > 6144.0f) {
                sp84 = 6144.0f;
            }

            sp80 += Math_SinS(pthis->unk_1A2 * 0x2200) * sp84;

            xRot += Math_CosS(pthis->unk_1A2 * 0x1800) * sp84;

            pthis->actor.world.rot.x = xRot;
            pthis->actor.world.rot.y = sp80;

            xDiff = dorf->unk_1FC.x - pthis->actor.world.pos.x;
            yDiff = dorf->unk_1FC.y - pthis->actor.world.pos.y;
            zDiff = dorf->unk_1FC.z - pthis->actor.world.pos.z;

            if (sqrtf(SQ(xDiff) + SQ(zDiff) + SQ(yDiff)) < 45.0f) {
                BossGanon_SetupHitByLightBall(dorf, globalCtx);
                pthis->timers[0] = 150;
                numEffects = 40;
                pthis->unk_1C2 = 1;
                pthis->actor.speedXZ = 0.0f;
            }
            break;
    }

    if (pthis->unk_1C2 >= 0xB) {
        xzDist = (pthis->unk_1C2 == 0xC) ? -65.0f : 0.0f;

        if ((fabsf(pthis->actor.world.pos.x) > (465.0f + xzDist)) ||
            (fabsf(pthis->actor.world.pos.z) > (465.0f + xzDist)) || ((pthis->actor.world.pos.y < 0.0f)) ||
            (pthis->actor.world.pos.y > 450.0f)) {
            pthis->unk_1C2 = 1;
            pthis->actor.speedXZ = 0.0f;
            numEffects = 10;
            BossGanon_CheckFallingPlatforms(pthis, globalCtx, &pthis->actor.world.pos);
            Actor_SpawnAsChild(&globalCtx->actorCtx, &dorf->actor, globalCtx, ACTOR_BOSS_GANON, pthis->actor.world.pos.x,
                               pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0x190);
        }
    }

    if (numEffects) {
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 80, NA_SE_EN_FANTOM_THUNDER);

        for (i = 0; i < numEffects; i++) {
            sp60.x = Rand_CenteredFloat(30.0f);
            sp60.y = Rand_CenteredFloat(30.0f);
            sp60.z = Rand_CenteredFloat(30.0);

            BossGanonEff_SpawnLightRay(globalCtx, &pthis->actor.world.pos, &sp60, &sZeroVec,
                                       Rand_ZeroFloat(200.0f) + 500.0f, 15.0f, 0x1E);
        }
    }
}

static Gfx* sBigMagicLightStreakDLists[] = {
    gDorfLightStreak12DL, gDorfLightStreak11DL, gDorfLightStreak10DL, gDorfLightStreak9DL,
    gDorfLightStreak8DL,  gDorfLightStreak7DL,  gDorfLightStreak6DL,  gDorfLightStreak5DL,
    gDorfLightStreak4DL,  gDorfLightStreak3DL,  gDorfLightStreak2DL,  gDorfLightStreak1DL,
};

void func_808E324C(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon* pthis = (BossGanon*)thisx;
    Mtx* mtx;
    s16 i;
    s32 temp;

    mtx = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, 12 * sizeof(Mtx));

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10489);

    func_80093D84(globalCtx->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, (s8)pthis->fwork[GDF_FWORK_1]);
    gDPSetEnvColor(POLY_XLU_DISP++, 150, 255, 0, 128);
    gSPSegment(POLY_XLU_DISP++, 0x0D, mtx);

    for (i = 0; i < 12; i++) {
        temp = (s16)(((pthis->unk_1A6 - i) + 0xF) % 15);
        Matrix_Translate(pthis->unk_2EC[temp].x, pthis->unk_2EC[temp].y, pthis->unk_2EC[temp].z, MTXMODE_NEW);
        Matrix_RotateY(pthis->unk_3C4[temp].y, MTXMODE_APPLY);
        Matrix_RotateX(-pthis->unk_3C4[temp].x, MTXMODE_APPLY);
        Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
        Matrix_RotateY(M_PI / 2, MTXMODE_APPLY);
        Matrix_ToMtx(mtx, "../z_boss_ganon.c", 10520);
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, sBigMagicLightStreakDLists[i]);
        mtx++;
    };

    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    func_800D1FD4(&globalCtx->billboardMtxF);
    Matrix_Scale(10.0f, 10.0f, 10.0f, MTXMODE_APPLY);
    Matrix_RotateZ(Rand_CenteredFloat(M_PI), MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10534),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);

    gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon.c", 10541);
}

void BossGanon_UpdateEffects(GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;
    s16 i;
    s32 pad;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 yRot;
    f32 xRot;
    Vec3f spA0;
    s16 bodyPart;
    f32 distToPlayer;
    s32 pad2;
    s32 pad3;

    spA0.x = 0.0f;
    spA0.y = 0.0f;

    for (i = 0; i < ARRAY_COUNT(sEffectBuf); i++, eff++) {
        if (eff->type != GDF_EFF_NONE) {
            eff->pos.x += eff->velocity.x;
            eff->pos.y += eff->velocity.y;
            eff->pos.z += eff->velocity.z;

            eff->timer++;

            eff->velocity.x += eff->accel.x;
            eff->velocity.y += eff->accel.y;
            eff->velocity.z += eff->accel.z;

            if (eff->type == GDF_EFF_WINDOW_SHARD) {
                eff->unk_44 += 0.3f;
                eff->unk_48 += 0.5f;

                if (eff->pos.y < 0.0f) {
                    eff->type = GDF_EFF_NONE;
                }
            } else if (eff->type == GDF_EFF_SPARKLE) {
                eff->unk_3C += Rand_ZeroFloat(M_PI / 2) + M_PI / 2;
                eff->unk_2E -= eff->unk_30;

                if (eff->unk_2E <= 0) {
                    eff->unk_2E = 0;
                    eff->type = GDF_EFF_NONE;
                }

                eff->alpha = eff->unk_2E;

                if (eff->alpha > 255) {
                    eff->alpha = 255;
                }
            } else if (eff->type == GDF_EFF_BLACK_DOT) {
                xDiff = sGanondorf->unk_278.x - eff->pos.x;
                yDiff = sGanondorf->unk_278.y - eff->pos.y;
                zDiff = sGanondorf->unk_278.z - eff->pos.z;

                yRot = Math_FAtan2F(xDiff, zDiff);

                xRot = -Math_FAtan2F(yDiff, sqrtf(SQ(xDiff) + SQ(zDiff)));
                spA0.z = eff->unk_38;
                Matrix_RotateY(yRot, MTXMODE_NEW);
                Matrix_RotateX(xRot, MTXMODE_APPLY);
                Matrix_MultVec3f(&spA0, &eff->velocity);
                Math_ApproachF(&eff->unk_38, 10.0f, 1.0f, 0.5f);

                eff->alpha += 10;

                if (eff->alpha > 255) {
                    eff->alpha = 255;
                }

                if ((sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff)) < 20.0f) || (eff->timer > 70)) {
                    eff->type = GDF_EFF_NONE;
                }
            } else if (eff->type == GDF_EFF_LIGHT_RAY) {
                eff->unk_3C += Rand_ZeroFloat(M_PI / 2) + M_PI / 2;
                eff->unk_2E -= eff->unk_30;

                if (eff->unk_2E <= 0) {
                    eff->unk_2E = 0;
                    eff->type = GDF_EFF_NONE;
                }

                eff->alpha = eff->unk_2E;

                if (eff->alpha > 255) {
                    eff->alpha = 255;
                }

                Math_ApproachF(&eff->unk_38, eff->unk_40, 1.0f, (eff->unk_40 / 15.0f) * 4.0f);
            } else if (eff->type == GDF_EFF_SHOCK) {
                if (eff->unk_2E == GDF_SHOCK_DORF_YELLOW) {
                    bodyPart = (s16)Rand_ZeroFloat(13.9f) + 1;

                    eff->pos.x = sGanondorf->unk_2EC[bodyPart].x + Rand_CenteredFloat(20.0f);
                    eff->pos.y = sGanondorf->unk_2EC[bodyPart].y + Rand_CenteredFloat(20.0f);
                    eff->pos.z = sGanondorf->unk_2EC[bodyPart].z + Rand_CenteredFloat(20.0f);
                } else {
                    bodyPart = (s16)Rand_ZeroFloat(17.9f);

                    eff->pos.x = player->bodyPartsPos[bodyPart].x + Rand_CenteredFloat(10.0f);
                    eff->pos.y = player->bodyPartsPos[bodyPart].y + Rand_CenteredFloat(15.0f);
                    eff->pos.z = player->bodyPartsPos[bodyPart].z + Rand_CenteredFloat(10.0f);
                }

                eff->unk_3C += (Rand_ZeroFloat(M_PI / 2) + M_PI / 2);

                if (eff->timer > 20) {
                    eff->type = GDF_EFF_NONE;
                }
            } else if (eff->type == GDF_EFF_LIGHTNING) {
                if (eff->unk_3C == 0.0f) {
                    eff->unk_44 = BINANG_TO_RAD(Camera_GetInputDirYaw(Gameplay_GetCamera(globalCtx, MAIN_CAM)));
                } else {
                    eff->unk_44 = M_PI / 2;
                }

                if (eff->timer > 12) {
                    eff->type = GDF_EFF_NONE;
                }
            } else if (eff->type == GDF_EFF_IMPACT_DUST_DARK) {
                eff->unk_30++; // unused

                if (eff->unk_2E == 0) {
                    eff->alpha += 26;

                    if (eff->alpha > 255) {
                        eff->alpha = 255;
                        eff->unk_2E = 1;
                    }
                } else if (eff->unk_2E == 1) {
                    eff->unk_2E = 2;
                } else if (eff->unk_2E == 2) {
                    eff->alpha -= 26;

                    if (eff->alpha < 0) {
                        eff->alpha = 0;
                        eff->type = GDF_EFF_NONE;
                    }
                }

                Math_ApproachF(&eff->scale, eff->unk_38, 1.0f, 0.01f);
                Math_ApproachF(&eff->unk_40, 4.0f, 1.0f, 0.15f);
            } else if (eff->type == GDF_EFF_IMPACT_DUST_LIGHT) {
                if (i == 0) {
                    func_80078884(NA_SE_EN_GANON_WAVE_GND - SFX_FLAG);
                }

                eff->unk_30++; // unused

                if (eff->unk_2E == 0) {
                    eff->alpha += 100;

                    if (eff->alpha > 255) {
                        eff->alpha = 255;
                        eff->unk_2E = 1;
                    }
                } else if (eff->unk_2E == 1) {
                    if (eff->timer >= 20) {
                        eff->unk_2E = 2;
                    }
                } else if (eff->unk_2E == 2) {
                    eff->alpha -= 30;

                    if (eff->alpha < 0) {
                        eff->alpha = 0;
                        eff->type = GDF_EFF_NONE;
                    }
                }

                Math_ApproachF(&eff->scale, eff->unk_38, 1.0f, 0.1f);
                Math_ApproachF(&eff->unk_40, 1.0f, 1.0f, 0.15f);
            } else if (eff->type == GDF_EFF_SHOCKWAVE) {
                eff->unk_30++; // unused
                eff->alpha -= 30;

                if (eff->alpha < 0) {
                    eff->alpha = 0;
                    eff->type = GDF_EFF_NONE;
                }

                Math_ApproachF(&eff->scale, eff->unk_38, 1.0f, 0.13f);

                if ((eff->timer < 150) && (fabsf(player->actor.world.pos.y) < 5.0f)) {
                    distToPlayer =
                        sqrtf(SQ(eff->pos.x - player->actor.world.pos.x) + SQ(eff->pos.z - player->actor.world.pos.z));

                    if (((eff->scale * 150.0f) < distToPlayer) && (distToPlayer < (eff->scale * 300.0f))) {
                        eff->timer = 150;
                        func_8002F6D4(globalCtx, &sGanondorf->actor, 7.0f, sGanondorf->actor.yawTowardsPlayer, 0.0f,
                                      0x20);
                    }
                }
            }
        }
    }
}

static void* sLightningTextures[] = {
    gDorfLightning1Tex,  gDorfLightning1Tex,  gDorfLightning2Tex,  gDorfLightning3Tex, gDorfLightning4Tex,
    gDorfLightning5Tex,  gDorfLightning6Tex,  gDorfLightning7Tex,  gDorfLightning8Tex, gDorfLightning9Tex,
    gDorfLightning10Tex, gDorfLightning11Tex, gDorfLightning12Tex,
};

static u8 sLightningPrimColors[] = {
    0,   0,   0,   255, 255, 255, 231, 250, 231, 208, 245, 208, 185, 240, 185, 162, 235, 162, 139, 230,
    139, 115, 225, 115, 92,  220, 92,  69,  215, 69,  46,  210, 46,  23,  205, 23,  0,   200, 0,
};

static u8 sLightningEnvColors[] = {
    0,   0,   0,   255, 255, 0,   240, 231, 23,  226, 208, 46,  212, 185, 69,  198, 162, 92,
    184, 139, 115, 170, 115, 139, 156, 92,  162, 142, 69,  185, 128, 46,  208, 114, 23,  231,
    100, 0,   255, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};

void BossGanon_DrawEffects(GlobalContext* globalCtx) {
    u8 flag = 0;
    s16 i;
    s32 pad;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    GanondorfEffect* eff = (GanondorfEffect*)globalCtx->specialEffects;
    GanondorfEffect* effFirst = eff;

    OPEN_DISPS(gfxCtx, "../z_boss_ganon.c", 10865);
    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < 200; i++, eff++) {
        if (eff->type == GDF_EFF_WINDOW_SHARD) {
            gDPPipeSync(POLY_OPA_DISP++);
            if (flag == 0) {
                gSPDisplayList(POLY_OPA_DISP++, gDorfWindowShardMaterialDL);
                flag++;
            }
            if ((eff->timer & 7) != 0) {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, eff->color.r, eff->color.g, eff->color.b, 255);
            } else {
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
            }
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_Scale(eff->scale, eff->scale, eff->scale, MTXMODE_APPLY);
            Matrix_RotateY(eff->unk_48, MTXMODE_APPLY);
            Matrix_RotateX(eff->unk_44, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 10898),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gDorfWindowShardModelDL);
        }
    }

    eff = effFirst;
    flag = 0;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_SPARKLE) {
            gDPPipeSync(POLY_XLU_DISP++);
            if (flag == 0) {
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
                gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);
                flag++;
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, eff->alpha);
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            Matrix_RotateZ(eff->unk_3C, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 10932),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
        }
    }

    eff = effFirst;
    flag = 0;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_LIGHT_RAY) {
            gDPPipeSync(POLY_XLU_DISP++);
            if (flag == 0) {
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
                gSPDisplayList(POLY_XLU_DISP++, gDorfLightBallMaterialDL);
                flag++;
            }
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, eff->alpha);
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_RotateY(eff->unk_48, MTXMODE_APPLY);
            Matrix_RotateX(eff->unk_44, MTXMODE_APPLY);
            Matrix_RotateZ(eff->unk_3C, MTXMODE_APPLY);
            Matrix_Scale(eff->scale, eff->scale, eff->unk_38 * eff->scale, MTXMODE_APPLY);
            Matrix_RotateX(M_PI / 2, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 10971),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfSquareDL);
        }
    }

    eff = effFirst;
    flag = 0;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_SHOCK) {
            if (flag == 0) {
                gDPPipeSync(POLY_XLU_DISP++);
                if (eff->unk_2E == GDF_SHOCK_PLAYER_PURPLE) {
                    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 100, 0, 200, 255);
                    gDPSetEnvColor(POLY_XLU_DISP++, 130, 0, 0, 0);
                } else { // GDF_SHOCK_DORF_YELLOW or GDF_SHOCK_PLAYER_YELLOW
                    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
                    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 0, 0);
                }
                flag++;
            }
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            Matrix_RotateX(eff->unk_3C * 1.3f, MTXMODE_APPLY);
            Matrix_RotateZ(eff->unk_3C, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11023),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfShockDL);
        }
    }

    eff = effFirst;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_LIGHTNING) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, sLightningPrimColors[(eff->timer * 3) + 0],
                            sLightningPrimColors[(eff->timer * 3) + 1], sLightningPrimColors[(eff->timer * 3) + 2],
                            255);
            gDPSetEnvColor(POLY_XLU_DISP++, sLightningEnvColors[(eff->timer * 3) + 0],
                           sLightningEnvColors[(eff->timer * 3) + 1], sLightningEnvColors[(eff->timer * 3) + 2], 0);
            Matrix_Translate(sGanondorf->unk_260.x, sGanondorf->unk_260.y, sGanondorf->unk_260.z, MTXMODE_NEW);
            Matrix_RotateY(eff->unk_48, MTXMODE_APPLY);
            Matrix_RotateZ(eff->unk_3C, MTXMODE_APPLY);
            Matrix_Scale(eff->scale, eff->scale, eff->scale, MTXMODE_APPLY);
            Matrix_RotateY(eff->unk_44, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11074),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sLightningTextures[eff->timer]));
            gSPDisplayList(POLY_XLU_DISP++, gDorfLightningDL);
        }
    }

    eff = effFirst;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_IMPACT_DUST_DARK) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, eff->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 100, 70, 0, 128);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, eff->timer * 4, 0, 32, 64, 1, eff->timer * 2,
                                        eff->timer * -20, 32, 32));
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_Scale(eff->scale, eff->unk_40 * eff->scale, eff->scale, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11121),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfImpactDarkDL);
        }
    }

    eff = effFirst;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_IMPACT_DUST_LIGHT) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, eff->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 200, 100, 0, 128);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, eff->timer * 4, 0, 32, 64, 1, eff->timer * 2,
                                        eff->timer * -20, 32, 32));
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_Scale(eff->scale, eff->unk_40 * eff->scale, eff->scale, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11165),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfImpactLightDL);
        }
    }

    eff = effFirst;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_SHOCKWAVE) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, eff->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 150, 255, 0, 128);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (eff->timer * 100), 0, 64, 32, 1,
                                        (eff->timer * 100), 0, 64, 32));
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            Matrix_Scale((eff->scale * 200.0f) / 1500.0f, (eff->unk_40 * 200.0f) / 1500.0f,
                         (eff->scale * 200.0f) / 1500.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11209),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfShockwaveDL);
        }
    }

    eff = effFirst;

    for (i = 0; i < 150; i++, eff++) {
        if (eff->type == GDF_EFF_BLACK_DOT) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 150, 170, 0, eff->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 128);
            gSPSegment(POLY_XLU_DISP++, 0x0A,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 32, 1, eff->timer * 2, eff->timer * -20,
                                        64, 64));
            Matrix_Translate(eff->pos.x, eff->pos.y, eff->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(eff->scale, eff->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_ganon.c", 11250),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gDorfDotDL);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_boss_ganon.c", 11255);
}

#include "overlays/ovl_Boss_Ganon/ovl_Boss_Ganon.cpp"


void BossGanon_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    bloodPrimColor_109 = { 0, 120, 0, 255 };

    bloodEnvColor_109 = { 0, 120, 0, 255 };

    D_808E4DA0_132 = { -500.0f, 200.0f, -300.0f };

    D_808E4DAC_132 = { -500.0f, 200.0f, 300.0f };

    D_808E4DB8_132 = { 0.0f, 0.0f, 0.0f };

    D_808E4DC4_132 = { 0.0f, 0.0f, 0.0f };

    D_808E4DD0_132 = { 0.0f, 0.0f, 0.0f };

    D_808E4DDC_132 = { 1300.0f, 0.0f, 0.0f };

    D_808E4DE8_132 = { 600.0f, 420.0f, 100.0f };

    Boss_Ganon_InitVars = {
        ACTOR_BOSS_GANON,
        ACTORCAT_BOSS,
        FLAGS,
        OBJECT_GANON,
        sizeof(BossGanon),
        (ActorFunc)BossGanon_Init,
        (ActorFunc)BossGanon_Destroy,
        (ActorFunc)BossGanon_Update,
        (ActorFunc)BossGanon_Draw,
        (ActorFunc)BossGanon_Reset,
    };

    sDorfCylinderInit = {
        {
            COLTYPE_HIT3,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x10 },
            { 0xFFCFFFFE, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON | BUMP_HOOKABLE,
            OCELEM_ON,
        },
        { 20, 80, -50, { 0, 0, 0 } },
    };

    sLightBallCylinderInit = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_ON | OC1_TYPE_ALL,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK6,
            { 0x00100700, 0x00, 0x08 },
            { 0x0D900740, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 20, 30, -15, { 0, 0, 0 } },
    };

    sZeroVec = { 0.0f, 0.0f, 0.0f };

    sCape = 0;

    sSeed1 = 0;

    sSeed2 = 0;

    sSeed3 = 0;

    sGanondorf = 0;

    sZelda = 0;

}

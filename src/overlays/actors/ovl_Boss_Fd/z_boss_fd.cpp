#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BOSS_FD_Z_BOSS_FD_C
#include "actor_common.h"
/*
 * File: z_boss_fd.c
 * Overlay: ovl_Boss_Fd
 * Description: Volvagia, flying form
 */

#include "z_boss_fd.h"
#include "objects/object_fd/object_fd.h"
#include "overlays/actors/ovl_En_Vb_Ball/z_en_vb_ball.h"
#include "overlays/actors/ovl_Bg_Vb_Sima/z_bg_vb_sima.h"
#include "overlays/actors/ovl_Boss_Fd2/z_boss_fd2.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/math_float.h"
#include "def/random.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5)


void BossFd_Init(Actor* thisx, GlobalContext* globalCtx);
void BossFd_Reset(Actor* pthisx, GlobalContext* globalCtx);
void BossFd_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossFd_Update(Actor* thisx, GlobalContext* globalCtx);
void BossFd_Draw(Actor* thisx, GlobalContext* globalCtx);

void BossFd_SetupFly(BossFd* pthis, GlobalContext* globalCtx);
void BossFd_Fly(BossFd* pthis, GlobalContext* globalCtx);
void BossFd_Wait(BossFd* pthis, GlobalContext* globalCtx);
void BossFd_UpdateEffects(BossFd* pthis, GlobalContext* globalCtx);
void BossFd_DrawBody(GlobalContext* globalCtx, BossFd* pthis);

static Color_RGBA8 colorYellow_59 = { 255, 255, 0, 255 };

static Color_RGBA8 colorRed_59 = { 255, 10, 0, 255 };

static void* dustTex_63[] = {
    gDust1Tex, gDust1Tex, gDust2Tex, gDust3Tex, gDust4Tex, gDust5Tex, gDust6Tex, gDust7Tex, gDust8Tex,
};

static Vec3f targetMod_72 = { 4500.0f, 0.0f, 0.0f };

static Vec3f headMod_72 = { 4000.0f, 0.0f, 0.0f };


ActorInit Boss_Fd_InitVars = {
    ACTOR_BOSS_FD,
    ACTORCAT_BOSS,
    FLAGS,
    OBJECT_FD,
    sizeof(BossFd),
    (ActorFunc)BossFd_Init,
    (ActorFunc)BossFd_Destroy,
    (ActorFunc)BossFd_Update,
    (ActorFunc)BossFd_Draw,
    (ActorFunc)BossFd_Reset,
};

#include "z_boss_fd_colchk.cpp"

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 5, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x21, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 0, ICHAIN_STOP),
};

void BossFd_SpawnEmber(BossFdEffect* effect, Vec3f* position, Vec3f* velocity, Vec3f* acceleration, f32 scale) {
    s16 i;

    for (i = 0; i < 150; i++, effect++) {
        if (effect->type == BFD_FX_NONE) {
            effect->type = BFD_FX_EMBER;
            effect->pos = *position;
            effect->velocity = *velocity;
            effect->accel = *acceleration;
            effect->scale = scale / 1000.0f;
            effect->alpha = 255;
            effect->timer1 = (s16)Rand_ZeroFloat(10.0f);
            break;
        }
    }
}

void BossFd_SpawnDebris(BossFdEffect* effect, Vec3f* position, Vec3f* velocity, Vec3f* acceleration, f32 scale) {
    s16 i;

    for (i = 0; i < 150; i++, effect++) {
        if (effect->type == BFD_FX_NONE) {
            effect->type = BFD_FX_DEBRIS;
            effect->pos = *position;
            effect->velocity = *velocity;
            effect->accel = *acceleration;
            effect->scale = scale / 1000.0f;
            effect->vFdFxRotX = Rand_ZeroFloat(100.0f);
            effect->vFdFxRotY = Rand_ZeroFloat(100.0f);
            break;
        }
    }
}

void BossFd_SpawnDust(BossFdEffect* effect, Vec3f* position, Vec3f* velocity, Vec3f* acceleration, f32 scale) {
    s16 i;

    for (i = 0; i < 150; i++, effect++) {
        if (effect->type == BFD_FX_NONE) {
            effect->type = BFD_FX_DUST;
            effect->pos = *position;
            effect->velocity = *velocity;
            effect->accel = *acceleration;
            effect->timer2 = 0;
            effect->scale = scale / 400.0f;
            break;
        }
    }
}

void BossFd_SpawnFireBreath(BossFdEffect* effect, Vec3f* position, Vec3f* velocity, Vec3f* acceleration, f32 scale,
                            s16 alpha, s16 kbAngle) {
    s16 i;

    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_NONE) {
            effect->type = BFD_FX_FIRE_BREATH;
            effect->timer1 = 0;
            effect->pos = *position;
            effect->velocity = *velocity;
            effect->accel = *acceleration;
            effect->pos.x -= effect->velocity.x;
            effect->pos.y -= effect->velocity.y;
            effect->pos.z -= effect->velocity.z;
            effect->vFdFxScaleMod = 0.0f;
            effect->alpha = alpha;
            effect->vFdFxYStop = Rand_ZeroFloat(10.0f);
            effect->timer2 = 0;
            effect->scale = scale / 400.0f;
            effect->kbAngle = kbAngle;
            break;
        }
    }
}

void BossFd_SetCameraSpeed(BossFd* pthis, f32 speedMod) {
    pthis->camData.eyeVel.x = fabsf(pthis->camData.eye.x - pthis->camData.nextEye.x) * speedMod;
    pthis->camData.eyeVel.y = fabsf(pthis->camData.eye.y - pthis->camData.nextEye.y) * speedMod;
    pthis->camData.eyeVel.z = fabsf(pthis->camData.eye.z - pthis->camData.nextEye.z) * speedMod;
    pthis->camData.atVel.x = fabsf(pthis->camData.at.x - pthis->camData.nextAt.x) * speedMod;
    pthis->camData.atVel.y = fabsf(pthis->camData.at.y - pthis->camData.nextAt.y) * speedMod;
    pthis->camData.atVel.z = fabsf(pthis->camData.at.z - pthis->camData.nextAt.z) * speedMod;
}

void BossFd_UpdateCamera(BossFd* pthis, GlobalContext* globalCtx) {
    if (pthis->introCamera != SUBCAM_FREE) {
        Math_ApproachF(&pthis->camData.eye.x, pthis->camData.nextEye.x, pthis->camData.eyeMaxVel.x,
                       pthis->camData.eyeVel.x * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.eye.y, pthis->camData.nextEye.y, pthis->camData.eyeMaxVel.y,
                       pthis->camData.eyeVel.y * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.eye.z, pthis->camData.nextEye.z, pthis->camData.eyeMaxVel.z,
                       pthis->camData.eyeVel.z * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.at.x, pthis->camData.nextAt.x, pthis->camData.atMaxVel.x,
                       pthis->camData.atVel.x * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.at.y, pthis->camData.nextAt.y, pthis->camData.atMaxVel.y,
                       pthis->camData.atVel.y * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.at.z, pthis->camData.nextAt.z, pthis->camData.atMaxVel.z,
                       pthis->camData.atVel.z * pthis->camData.speedMod);
        Math_ApproachF(&pthis->camData.speedMod, 1.0f, 1.0f, pthis->camData.accel);
        pthis->camData.at.y += pthis->camData.yMod;
        Gameplay_CameraSetAtEye(globalCtx, pthis->introCamera, &pthis->camData.at, &pthis->camData.eye);
        Math_ApproachZeroF(&pthis->camData.yMod, 1.0f, 0.1f);
    }
}

void BossFd_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossFd* pthis = (BossFd*)thisx;
    s16 i;

    Flags_SetSwitch(globalCtx, 0x14);
    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BG_VB_SIMA, 680.0f, -100.0f, 0.0f, 0, 0, 0,
                       100);
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(&pthis->actor, 0.05f);
    SkelAnime_Init(globalCtx, &pthis->skelAnimeHead, &gVolvagiaHeadSkel, &gVolvagiaHeadEmergeAnim, NULL, NULL, 0);
    SkelAnime_Init(globalCtx, &pthis->skelAnimeRightArm, &gVolvagiaRightArmSkel, &gVolvagiaRightArmEmergeAnim, NULL,
                   NULL, 0);
    SkelAnime_Init(globalCtx, &pthis->skelAnimeLeftArm, &gVolvagiaLeftArmSkel, &gVolvagiaLeftArmEmergeAnim, NULL, NULL,
                   0);
    pthis->introState = BFD_CS_WAIT;
    if (pthis->introState == BFD_CS_NONE) {
        Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_FIRE_BOSS);
    }

    pthis->actor.world.pos.x = pthis->actor.world.pos.z = 0.0f;
    pthis->actor.world.pos.y = -200.0f;
    Collider_InitJntSph(globalCtx, &pthis->collider);
    Collider_SetJntSph(globalCtx, &pthis->collider, &pthis->actor, &sJntSphInit, pthis->elements);

    for (i = 0; i < 100; i++) {
        pthis->bodySegsPos[i].x = pthis->actor.world.pos.x;
        pthis->bodySegsPos[i].y = pthis->actor.world.pos.y;
        pthis->bodySegsPos[i].z = pthis->actor.world.pos.z;
        if (i < 30) {
            pthis->centerMane.pos[i].x = pthis->actor.world.pos.x;
            pthis->centerMane.pos[i].y = pthis->actor.world.pos.y;
            pthis->centerMane.pos[i].z = pthis->actor.world.pos.z;
        }
    }

    pthis->actor.colChkInfo.health = 24;
    pthis->skinSegments = 18;
    if (pthis->introState == BFD_CS_NONE) {
        pthis->actionFunc = BossFd_Wait;
    } else {
        BossFd_SetupFly(pthis, globalCtx);
    }

    if (Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
        Actor_Kill(&pthis->actor);
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, 100.0f, 0.0f, 0, 0, 0,
                           WARP_DUNGEON_ADULT);
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 0.0f, 100.0f, 200.0f, 0, 0, 0, 0);
    } else {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_FD2, pthis->actor.world.pos.x,
                           pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, pthis->introState);
    }
}

void BossFd_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossFd* pthis = (BossFd*)thisx;

    SkelAnime_Free(&pthis->skelAnimeHead, globalCtx);
    SkelAnime_Free(&pthis->skelAnimeRightArm, globalCtx);
    SkelAnime_Free(&pthis->skelAnimeLeftArm, globalCtx);
    Collider_DestroyJntSph(globalCtx, &pthis->collider);
}

s32 BossFd_IsFacingLink(BossFd* pthis) {
    return ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y)) < 0x2000;
}

void BossFd_SetupFly(BossFd* pthis, GlobalContext* globalCtx) {
    Animation_PlayOnce(&pthis->skelAnimeHead, &gVolvagiaHeadEmergeAnim);
    Animation_PlayOnce(&pthis->skelAnimeRightArm, &gVolvagiaRightArmEmergeAnim);
    Animation_PlayOnce(&pthis->skelAnimeLeftArm, &gVolvagiaLeftArmEmergeAnim);
    pthis->actionFunc = BossFd_Fly;
    pthis->fwork[BFD_TURN_RATE_MAX] = 1000.0f;
}

static Vec3f sHoleLocations[] = {
    { 0.0f, 90.0f, -243.0f },    { 0.0f, 90.0f, 0.0f },    { 0.0f, 90.0f, 243.0f },
    { -243.0f, 90.0f, -243.0f }, { -243.0f, 90.0f, 0.0f }, { -243.0f, 90.0f, 243.0f },
    { 243.0f, 90.0f, -243.0f },  { 243.0f, 90.0f, 0.0f },  { 243.0f, 90.0f, 243.0f },
};

static Vec3f sCeilingTargets[] = {
    { 0.0f, 900.0f, -243.0f }, { 243.0, 900.0f, -100.0f },  { 243.0f, 900.0f, 100.0f },
    { 0.0f, 900.0f, 243.0f },  { -243.0f, 900.0f, 100.0f }, { -243.0, 900.0f, -100.0f },
};

void BossFd_Fly(BossFd* pthis, GlobalContext* globalCtx) {
    u8 sp1CF = false;
    u8 temp_rand;
    s16 i1;
    s16 i2;
    s16 i3;
    f32 dx;
    f32 dy;
    f32 dz;
    Player* player = GET_PLAYER(globalCtx);
    f32 angleToTarget;
    f32 pitchToTarget;
    Vec3f* holePosition1;
    f32 temp_y;
    f32 temp_x;
    f32 temp_z;
    f32 temp;

    SkelAnime_Update(&pthis->skelAnimeHead);
    SkelAnime_Update(&pthis->skelAnimeRightArm);
    SkelAnime_Update(&pthis->skelAnimeLeftArm);
    dx = pthis->targetPosition.x - pthis->actor.world.pos.x;
    dy = pthis->targetPosition.y - pthis->actor.world.pos.y;
    dz = pthis->targetPosition.z - pthis->actor.world.pos.z;
    dx += Math_SinS((2096.0f + pthis->fwork[BFD_FLY_WOBBLE_RATE]) * pthis->work[BFD_MOVE_TIMER]) *
          pthis->fwork[BFD_FLY_WOBBLE_AMP];
    dy += Math_SinS((1096.0f + pthis->fwork[BFD_FLY_WOBBLE_RATE]) * pthis->work[BFD_MOVE_TIMER]) *
          pthis->fwork[BFD_FLY_WOBBLE_AMP];
    dz += Math_SinS((1796.0f + pthis->fwork[BFD_FLY_WOBBLE_RATE]) * pthis->work[BFD_MOVE_TIMER]) *
          pthis->fwork[BFD_FLY_WOBBLE_AMP];
    angleToTarget = (s16)(Math_FAtan2F(dx, dz) * (0x8000 / M_PI));
    pitchToTarget = (s16)(Math_FAtan2F(dy, sqrtf(SQ(dx) + SQ(dz))) * (0x8000 / M_PI));

    osSyncPrintf("MODE %d\n", pthis->work[BFD_ACTION_STATE]);

    Math_ApproachF(&pthis->fwork[BFD_BODY_PULSE], 0.1f, 1.0f, 0.02);

    //                                        Boss Intro Cutscene

    if (pthis->introState != BFD_CS_NONE) {
        Player* player2 = GET_PLAYER(globalCtx);
        Camera* mainCam = Gameplay_GetCamera(globalCtx, MAIN_CAM);

        switch (pthis->introState) {
            case BFD_CS_WAIT:
                pthis->fogMode = 3;
                pthis->targetPosition.x = 0.0f;
                pthis->targetPosition.y = -110.0f;
                pthis->targetPosition.z = 0.0;
                pthis->fwork[BFD_TURN_RATE_MAX] = 10000.0f;
                pthis->work[BFD_ACTION_STATE] = BOSSFD_WAIT_INTRO;
                if ((fabsf(player2->actor.world.pos.z) < 80.0f) &&
                    (fabsf(player2->actor.world.pos.x - 340.0f) < 60.0f)) {

                    pthis->introState = BFD_CS_START;
                    func_80064520(globalCtx, &globalCtx->csCtx);
                    func_8002DF54(globalCtx, &pthis->actor, 8);
                    pthis->introCamera = Gameplay_CreateSubCamera(globalCtx);
                    Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
                    Gameplay_ChangeCameraStatus(globalCtx, pthis->introCamera, CAM_STAT_ACTIVE);
                    player2->actor.world.pos.x = 380.0f;
                    player2->actor.world.pos.y = 100.0f;
                    player2->actor.world.pos.z = 0.0f;
                    player2->actor.shape.rot.y = player2->actor.world.rot.y = -0x4000;
                    player2->actor.speedXZ = 0.0f;
                    pthis->camData.eye.x = player2->actor.world.pos.x - 70.0f;
                    pthis->camData.eye.y = player2->actor.world.pos.y + 40.0f;
                    pthis->camData.eye.z = player2->actor.world.pos.z + 70.0f;
                    pthis->camData.at.x = player2->actor.world.pos.x;
                    pthis->camData.at.y = player2->actor.world.pos.y + 30.0f;
                    pthis->camData.at.z = player2->actor.world.pos.z;
                    pthis->camData.nextEye.x = player2->actor.world.pos.x - 50.0f + 18.0f;
                    pthis->camData.nextEye.y = player2->actor.world.pos.y + 40;
                    pthis->camData.nextEye.z = player2->actor.world.pos.z + 50.0f - 18.0f;
                    pthis->camData.nextAt.x = player2->actor.world.pos.x;
                    pthis->camData.nextAt.y = player2->actor.world.pos.y + 50.0f;
                    pthis->camData.nextAt.z = player2->actor.world.pos.z;
                    BossFd_SetCameraSpeed(pthis, 1.0f);
                    pthis->camData.atMaxVel.x = pthis->camData.atMaxVel.y = pthis->camData.atMaxVel.z = 0.05f;
                    pthis->camData.eyeMaxVel.x = pthis->camData.eyeMaxVel.y = pthis->camData.eyeMaxVel.z = 0.05f;
                    pthis->timers[0] = 0;
                    pthis->camData.speedMod = 0.0f;
                    pthis->camData.accel = 0.0f;
                    if (gSaveContext.eventChkInf[7] & 8) {
                        pthis->introState = BFD_CS_EMERGE;
                        pthis->camData.nextEye.x = player2->actor.world.pos.x + 100.0f + 300.0f - 600.0f;
                        pthis->camData.nextEye.y = player2->actor.world.pos.y + 100.0f - 50.0f;
                        pthis->camData.nextEye.z = player2->actor.world.pos.z + 200.0f - 150.0f;
                        pthis->camData.nextAt.x = 0.0f;
                        pthis->camData.nextAt.y = 120.0f;
                        pthis->camData.nextAt.z = 0.0f;
                        BossFd_SetCameraSpeed(pthis, 0.5f);
                        pthis->camData.eyeMaxVel.x = pthis->camData.eyeMaxVel.y = pthis->camData.eyeMaxVel.z = 0.1f;
                        pthis->camData.atMaxVel.x = pthis->camData.atMaxVel.y = pthis->camData.atMaxVel.z = 0.1f;
                        pthis->camData.accel = 0.005f;
                        pthis->timers[0] = 0;
                        pthis->holeIndex = 1;
                        pthis->targetPosition.x = sHoleLocations[pthis->holeIndex].x;
                        pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y - 200.0f;
                        pthis->targetPosition.z = sHoleLocations[pthis->holeIndex].z;
                        pthis->timers[0] = 50;
                        pthis->work[BFD_ACTION_STATE] = BOSSFD_EMERGE;
                        pthis->actor.world.rot.x = 0x4000;
                        pthis->work[BFD_MOVE_TIMER] = 0;
                        pthis->timers[3] = 250;
                        pthis->timers[2] = 470;
                        pthis->fwork[BFD_FLY_SPEED] = 5.0f;
                    }
                }
                break;
            case BFD_CS_START:
                if (pthis->timers[0] == 0) {
                    pthis->camData.accel = 0.0010000002f;
                    pthis->timers[0] = 100;
                    pthis->introState = BFD_CS_LOOK_LINK;
                }
            case BFD_CS_LOOK_LINK:
                player2->actor.world.pos.x = 380.0f;
                player2->actor.world.pos.y = 100.0f;
                player2->actor.world.pos.z = 0.0f;
                player2->actor.speedXZ = 0.0f;
                player2->actor.shape.rot.y = player2->actor.world.rot.y = -0x4000;
                if (pthis->timers[0] == 50) {
                    pthis->fogMode = 1;
                }
                if (pthis->timers[0] < 50) {
                    Audio_PlaySoundGeneral(NA_SE_EN_DODO_K_ROLL - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                           &D_801333E0, &gReverbAdd2);
                    pthis->camData.yMod = Math_CosS(pthis->work[BFD_MOVE_TIMER] * 0x8000) * pthis->camData.shake;
                    Math_ApproachF(&pthis->camData.shake, 2.0f, 1.0f, 0.8 * 0.01f);
                }
                if (pthis->timers[0] == 40) {
                    func_8002DF54(globalCtx, &pthis->actor, 0x13);
                }
                if (pthis->timers[0] == 0) {
                    pthis->introState = BFD_CS_LOOK_GROUND;
                    pthis->camData.nextAt.y = player2->actor.world.pos.y + 10.0f;
                    pthis->camData.atMaxVel.y = 0.2f;
                    pthis->camData.speedMod = 0.0f;
                    pthis->camData.accel = 0.02f;
                    pthis->timers[0] = 70;
                    pthis->work[BFD_MOVE_TIMER] = 0;
                }
                break;
            case BFD_CS_LOOK_GROUND:
                pthis->camData.yMod = Math_CosS(pthis->work[BFD_MOVE_TIMER] * 0x8000) * pthis->camData.shake;
                Math_ApproachF(&pthis->camData.shake, 2.0f, 1.0f, 0.8 * 0.01f);
                Audio_PlaySoundGeneral(NA_SE_EN_DODO_K_ROLL - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);
                if (pthis->timers[0] == 0) {
                    pthis->introState = BFD_CS_COLLAPSE;
                    pthis->camData.nextEye.x = player2->actor.world.pos.x + 100.0f + 300.0f;
                    pthis->camData.nextEye.y = player2->actor.world.pos.y + 100.0f;
                    pthis->camData.nextEye.z = player2->actor.world.pos.z + 200.0f;
                    pthis->camData.nextAt.x = player2->actor.world.pos.x;
                    pthis->camData.nextAt.y = player2->actor.world.pos.y - 150.0f;
                    pthis->camData.nextAt.z = player2->actor.world.pos.z - 50.0f;
                    BossFd_SetCameraSpeed(pthis, 0.1f);
                    pthis->timers[0] = 170;
                    pthis->camData.speedMod = 0.0f;
                    pthis->camData.accel = 0.0f;
                    func_8002DF54(globalCtx, &pthis->actor, 0x14);
                }
                break;
            case BFD_CS_COLLAPSE:
                pthis->camData.accel = 0.005f;
                pthis->camData.yMod = Math_CosS(pthis->work[BFD_MOVE_TIMER] * 0x8000) * pthis->camData.shake;
                Math_ApproachF(&pthis->camData.shake, 2.0f, 1.0f, 0.8 * 0.01f);
                Audio_PlaySoundGeneral(NA_SE_EN_DODO_K_ROLL - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);
                if (pthis->timers[0] == 100) {
                    pthis->platformSignal = VBSIMA_COLLAPSE;
                }
                if (pthis->timers[0] == 0) {
                    pthis->introState = BFD_CS_EMERGE;
                    pthis->camData.speedMod = 0.0f;
                    pthis->camData.nextEye.x = player2->actor.world.pos.x + 100.0f + 300.0f - 600.0f;
                    pthis->camData.nextEye.y = player2->actor.world.pos.y + 100.0f - 50.0f;
                    pthis->camData.nextEye.z = player2->actor.world.pos.z + 200.0f - 150.0f;
                    pthis->camData.nextAt.x = 0.0f;
                    pthis->camData.nextAt.y = 120.0f;
                    pthis->camData.nextAt.z = 0.0f;
                    BossFd_SetCameraSpeed(pthis, 0.5f);
                    pthis->camData.atMaxVel.x = pthis->camData.atMaxVel.y = pthis->camData.atMaxVel.z = 0.1f;
                    pthis->camData.eyeMaxVel.x = pthis->camData.eyeMaxVel.y = pthis->camData.eyeMaxVel.z = 0.1f;
                    pthis->camData.accel = 0.005f;
                    pthis->timers[0] = 0;
                    pthis->holeIndex = 1;
                    pthis->targetPosition.x = sHoleLocations[pthis->holeIndex].x;
                    pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y - 200.0f;
                    pthis->targetPosition.z = sHoleLocations[pthis->holeIndex].z;
                    pthis->timers[0] = 50;
                    pthis->work[BFD_ACTION_STATE] = BOSSFD_EMERGE;
                    pthis->actor.world.rot.x = 0x4000;
                    pthis->work[BFD_MOVE_TIMER] = 0;
                    pthis->timers[3] = 250;
                    pthis->timers[2] = 470;
                    pthis->fwork[BFD_FLY_SPEED] = 5.0f;
                }
                break;
            case BFD_CS_EMERGE:
                osSyncPrintf("WAY_SPD X = %f\n", pthis->camData.atVel.x);
                osSyncPrintf("WAY_SPD Y = %f\n", pthis->camData.atVel.y);
                osSyncPrintf("WAY_SPD Z = %f\n", pthis->camData.atVel.z);
                if ((pthis->timers[3] > 190) && !(gSaveContext.eventChkInf[7] & 8)) {
                    Audio_PlaySoundGeneral(NA_SE_EN_DODO_K_ROLL - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                           &D_801333E0, &gReverbAdd2);
                }
                if (pthis->timers[3] == 190) {
                    pthis->camData.atMaxVel.x = pthis->camData.atMaxVel.y = pthis->camData.atMaxVel.z = 0.05f;
                    pthis->platformSignal = VBSIMA_KILL;
                    func_8002DF54(globalCtx, &pthis->actor, 1);
                }
                if (pthis->actor.world.pos.y > 120.0f) {
                    pthis->camData.nextAt = pthis->actor.world.pos;
                    pthis->camData.atVel.x = 190.0f;
                    pthis->camData.atVel.y = 85.56f;
                    pthis->camData.atVel.z = 25.0f;
                } else {
                    // the following `temp` stuff is probably fake but is required to match
                    // it's optimized to 1.0f because sp1CF is false at pthis point, but the 0.1f ends up in rodata
                    temp = 0.1f;
                    if (!sp1CF) {
                        temp = 1.0f;
                    }
                    Math_ApproachF(&pthis->camData.shake, 2.0f, temp, 0.1 * 0.08f);
                    pthis->camData.yMod = Math_CosS(pthis->work[BFD_MOVE_TIMER] * 0x8000) * pthis->camData.shake;
                }
                if (pthis->timers[3] == 160) {
                    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_FIRE_BOSS);
                }
                if ((pthis->timers[3] == 130) && !(gSaveContext.eventChkInf[7] & 8)) {
                    TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx,
                                           SEGMENTED_TO_VIRTUAL(gVolvagiaBossTitleCardTex), 0xA0, 0xB4, 0x80, 0x28);
                }
                if (pthis->timers[3] <= 100) {
                    pthis->camData.eyeVel.x = pthis->camData.eyeVel.y = pthis->camData.eyeVel.z = 2.0f;
                    pthis->camData.nextEye.x = player2->actor.world.pos.x + 50.0f;
                    pthis->camData.nextEye.y = player2->actor.world.pos.y + 50.0f;
                    pthis->camData.nextEye.z = player2->actor.world.pos.z + 50.0f;
                }
                if (pthis->work[BFD_ACTION_STATE] == BOSSFD_FLY_HOLE) {
                    switch (pthis->introFlyState) {
                        case INTRO_FLY_EMERGE:
                            pthis->timers[5] = 100;
                            pthis->introFlyState = INTRO_FLY_HOLE;
                        case INTRO_FLY_HOLE:
                            if (pthis->timers[5] == 0) {
                                pthis->introFlyState = INTRO_FLY_CAMERA;
                                pthis->timers[5] = 75;
                            }
                            break;
                        case INTRO_FLY_CAMERA:
                            pthis->targetPosition = pthis->camData.eye;
                            if (pthis->timers[5] == 0) {
                                pthis->timers[0] = 0;
                                pthis->holeIndex = 7;
                                pthis->targetPosition.x = sHoleLocations[pthis->holeIndex].x;
                                pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y + 200.0f + 50.0f;
                                pthis->targetPosition.z = sHoleLocations[pthis->holeIndex].z;
                                pthis->introFlyState = INTRO_FLY_RETRAT;
                            }
                            if (pthis->timers[5] == 30) {
                                pthis->work[BFD_ROAR_TIMER] = 40;
                                pthis->fireBreathTimer = 20;
                            }
                        case INTRO_FLY_RETRAT:
                            break;
                    }
                }
                osSyncPrintf("pthis->timer[2] = %d\n", pthis->timers[2]);
                osSyncPrintf("pthis->timer[5] = %d\n", pthis->timers[5]);
                if (pthis->timers[2] == 0) {
                    mainCam->eye = pthis->camData.eye;
                    mainCam->eyeNext = pthis->camData.eye;
                    mainCam->at = pthis->camData.at;
                    func_800C08AC(globalCtx, pthis->introCamera, 0);
                    pthis->introState = pthis->introFlyState = pthis->introCamera = BFD_CS_NONE;
                    func_80064534(globalCtx, &globalCtx->csCtx);
                    func_8002DF54(globalCtx, &pthis->actor, 7);
                    pthis->actionFunc = BossFd_Wait;
                    pthis->handoffSignal = FD2_SIGNAL_GROUND;
                    gSaveContext.eventChkInf[7] |= 8;
                }
                break;
        }
        BossFd_UpdateCamera(pthis, globalCtx);
    } else {
        pthis->fwork[BFD_FLY_SPEED] = 5.0f;
    }

    //                             Attacks and Death Cutscene

    switch (pthis->work[BFD_ACTION_STATE]) {
        case BOSSFD_FLY_MAIN:
            sp1CF = true;
            if (pthis->timers[0] == 0) {
                if (pthis->actor.colChkInfo.health == 0) {
                    pthis->work[BFD_ACTION_STATE] = BOSSFD_DEATH_START;
                    pthis->timers[0] = 0;
                    pthis->timers[1] = 100;
                } else {
                    if (pthis->introState != BFD_CS_NONE) {
                        pthis->holeIndex = 6;
                    } else {
                        do {
                            temp_rand = Rand_ZeroFloat(8.9f);
                        } while (temp_rand == pthis->holeIndex);
                        pthis->holeIndex = temp_rand;
                    }
                    pthis->targetPosition.x = sHoleLocations[pthis->holeIndex].x;
                    pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y + 200.0f + 50.0f;
                    pthis->targetPosition.z = sHoleLocations[pthis->holeIndex].z;
                    pthis->fwork[BFD_TURN_RATE] = 0.0f;
                    pthis->fwork[BFD_TURN_RATE_MAX] = 1000.0f;
                    if (pthis->introState != BFD_CS_NONE) {
                        pthis->timers[0] = 10050;
                    } else {
                        pthis->timers[0] = 20;
                    }
                    pthis->fwork[BFD_FLY_WOBBLE_AMP] = 100.0f;
                    pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_HOLE;

                    if (pthis->work[BFD_START_ATTACK]) {
                        pthis->work[BFD_START_ATTACK] = false;
                        pthis->work[BFD_FLY_COUNT]++;
                        if (pthis->work[BFD_FLY_COUNT] & 1) {
                            pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_CHASE;
                            pthis->timers[0] = 300;
                            pthis->fwork[BFD_TURN_RATE_MAX] = 900.0f;
                            pthis->fwork[BFD_TARGET_Y_OFFSET] = 300.0f;
                            pthis->work[BFD_UNK_234] = pthis->work[BFD_UNK_236] = 0;
                        } else {
                            pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_CEILING;
                        }
                    }
                }
            }
            break;
        case BOSSFD_FLY_HOLE:
            if ((pthis->timers[0] == 0) && (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 100.0f)) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_BURROW;
                pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y - 70.0f;
                pthis->fwork[BFD_TURN_RATE_MAX] = 10000.0f;
                pthis->fwork[BFD_FLY_WOBBLE_AMP] = 0.0f;
                pthis->timers[0] = 150;
                pthis->work[BFD_ROAR_TIMER] = 40;
                pthis->holePosition.x = pthis->targetPosition.x;
                pthis->holePosition.z = pthis->targetPosition.z;
            }
            break;
        case BOSSFD_BURROW:
            sp1CF = true;
            if (pthis->timers[0] == 0) {
                pthis->actionFunc = BossFd_Wait;
                pthis->handoffSignal = FD2_SIGNAL_GROUND;
            }
            break;
        case BOSSFD_EMERGE:
            if ((pthis->timers[0] == 0) && (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 100.0f)) {
                pthis->actor.world.pos = pthis->targetPosition;
                pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_MAIN;
                pthis->actor.world.rot.x = 0x4000;
                pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y + 200.0f;
                pthis->timers[4] = 80;
                pthis->fwork[BFD_TURN_RATE_MAX] = 1000.0f;
                pthis->fwork[BFD_FLY_WOBBLE_AMP] = 0.0f;
                pthis->holePosition.x = pthis->targetPosition.x;
                pthis->holePosition.z = pthis->targetPosition.z;

                func_80033E1C(globalCtx, 1, 0x50, 0x5000);
                if (pthis->introState != BFD_CS_NONE) {
                    pthis->timers[0] = 50;
                } else {
                    pthis->timers[0] = 50;
                }
            }
            break;
        case BOSSFD_FLY_CEILING:
            pthis->fwork[BFD_FLY_SPEED] = 8;
            pthis->targetPosition.x = 0.0f;
            pthis->targetPosition.y = 700.0f;
            pthis->targetPosition.z = -300.0f;
            pthis->fwork[BFD_FLY_WOBBLE_AMP] = 200.0f;
            pthis->fwork[BFD_TURN_RATE_MAX] = 3000.0f;
            if (pthis->actor.world.pos.y > 700.0f) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_DROP_ROCKS;
                pthis->timers[0] = 25;
                pthis->timers[2] = 150;
                pthis->work[BFD_CEILING_TARGET] = 0;
            }
            break;
        case BOSSFD_DROP_ROCKS:
            pthis->fwork[BFD_FLY_SPEED] = 8;
            pthis->fwork[BFD_FLY_WOBBLE_AMP] = 200.0f;
            pthis->fwork[BFD_TURN_RATE_MAX] = 10000.0f;
            pthis->targetPosition.x = sCeilingTargets[pthis->work[BFD_CEILING_TARGET]].x;
            pthis->targetPosition.y = sCeilingTargets[pthis->work[BFD_CEILING_TARGET]].y + 900.0f;
            pthis->targetPosition.z = sCeilingTargets[pthis->work[BFD_CEILING_TARGET]].z;
            if (pthis->timers[0] == 0) {
                pthis->timers[0] = 25;
                pthis->work[BFD_CEILING_TARGET]++;
                if (pthis->work[BFD_CEILING_TARGET] >= 6) {
                    pthis->work[BFD_CEILING_TARGET] = 0;
                }
            }
            Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 2);
            if (pthis->timers[1] == 0) {
                osSyncPrintf("BGCHECKKKKKKKKKKKKKKKKKKKKKKK\n");
                if (pthis->actor.bgCheckFlags & 0x10) {
                    pthis->fwork[BFD_CEILING_BOUNCE] = -18384.0f;
                    pthis->timers[1] = 10;
                    Audio_PlaySoundGeneral(NA_SE_EV_EXPLOSION, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                           &gReverbAdd2);
                    func_80033E1C(globalCtx, 3, 0xA, 0x7530);
                    pthis->work[BFD_ROCK_TIMER] = 300;
                }
            } else {
                pitchToTarget = pthis->fwork[BFD_CEILING_BOUNCE];
                Math_ApproachZeroF(&pthis->fwork[BFD_CEILING_BOUNCE], 1.0f, 1000.0f);
            }
            if (pthis->timers[2] == 0) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_MAIN;
                pthis->timers[0] = 0;
                pthis->work[BFD_START_ATTACK] = false;
            }
            break;
        case BOSSFD_FLY_CHASE:
            pthis->actor.flags |= ACTOR_FLAG_24;
            temp_y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 2396.0f) * 30.0f + pthis->fwork[BFD_TARGET_Y_OFFSET];
            pthis->targetPosition.x = player->actor.world.pos.x;
            pthis->targetPosition.y = player->actor.world.pos.y + temp_y + 30.0f;
            pthis->targetPosition.z = player->actor.world.pos.z;
            pthis->fwork[BFD_FLY_WOBBLE_AMP] = 0.0f;
            if (((pthis->timers[0] % 64) == 0) && (pthis->timers[0] < 450)) {
                pthis->work[BFD_ROAR_TIMER] = 40;
                if (BossFd_IsFacingLink(pthis)) {
                    pthis->fireBreathTimer = 20;
                }
            }
            if ((pthis->work[BFD_DAMAGE_FLASH_TIMER] != 0) || (pthis->timers[0] == 0) ||
                (player->actor.world.pos.y < 70.0f)) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_FLY_MAIN;
                pthis->timers[0] = 0;
                pthis->work[BFD_START_ATTACK] = false;
            } else {
                Math_ApproachF(&pthis->fwork[BFD_TARGET_Y_OFFSET], 50.0, 1.0f, 2.0f);
            }
            break;
        case BOSSFD_DEATH_START:
            if (sqrtf(SQ(dx) + SQ(dz)) < 50.0f) {
                pthis->timers[0] = 0;
            }
            if (pthis->timers[0] == 0) {
                pthis->timers[0] = (s16)Rand_ZeroFloat(10.0f) + 10;
                do {
                    pthis->targetPosition.x = Rand_CenteredFloat(200.0f);
                    pthis->targetPosition.y = 390.0f;
                    pthis->targetPosition.z = Rand_CenteredFloat(200.0f);
                    temp_x = pthis->targetPosition.x - pthis->actor.world.pos.x;
                    temp_z = pthis->targetPosition.z - pthis->actor.world.pos.z;
                } while (!(sqrtf(SQ(temp_x) + SQ(temp_z)) > 100.0f));
            }
            pthis->fwork[BFD_FLY_WOBBLE_AMP] = 200.0f;
            pthis->fwork[BFD_FLY_WOBBLE_RATE] = 1000.0f;
            pthis->fwork[BFD_TURN_RATE_MAX] = 10000.0f;
            Math_ApproachF(&pthis->fwork[BFD_BODY_PULSE], 0.3f, 1.0f, 0.05f);
            if (pthis->timers[1] == 0) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_SKIN_BURN;
                pthis->timers[0] = 30;
            }
            break;
        case BOSSFD_SKIN_BURN:
            pthis->targetPosition.x = 0.0f;
            pthis->targetPosition.y = 390.0f;
            pthis->targetPosition.z = 0.0f;
            pthis->fwork[BFD_FLY_WOBBLE_AMP] = 200.0f;
            pthis->fwork[BFD_FLY_WOBBLE_RATE] = 1000.0f;
            pthis->fwork[BFD_TURN_RATE_MAX] = 2000.0f;
            Math_ApproachF(&pthis->fwork[BFD_BODY_PULSE], 0.3f, 1.0f, 0.05f);
            if ((pthis->timers[0] == 0) && ((pthis->work[BFD_MOVE_TIMER] % 4) == 0)) {
                if (pthis->skinSegments != 0) {
                    pthis->skinSegments--;
                    if (pthis->skinSegments == 0) {
                        Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS_CLEAR);
                    }
                } else {
                    pthis->work[BFD_ACTION_STATE] = BOSSFD_BONES_FALL;
                    pthis->timers[0] = 30;
                }
            }
            if ((pthis->work[BFD_MOVE_TIMER] % 32) == 0) {
                pthis->work[BFD_ROAR_TIMER] = 40;
            }

            if (pthis->skinSegments != 0) {
                Vec3f sp188;
                Vec3f sp17C = { 0.0f, 0.0f, 0.0f };
                Vec3f sp170;
                Vec3f sp164 = { 0.0f, 0.03f, 0.0f };
                Vec3f sp158;
                f32 pad154;
                s16 temp_rand2;
                s16 sp150;

                if (pthis->fogMode == 0) {
                    globalCtx->envCtx.unk_D8 = 0;
                }
                pthis->fogMode = 0xA;

                sp150 = 1;
                if (pthis->work[BFD_MOVE_TIMER] & 0x1C) {
                    Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_BURN - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                           &D_801333E0, &gReverbAdd2);
                }
                for (i1 = 0; i1 < sp150; i1++) {
                    if (sp150) { // Needed for matching
                        temp_rand2 = Rand_ZeroFloat(99.9f);

                        sp188.x = pthis->bodySegsPos[temp_rand2].x;
                        sp188.y = pthis->bodySegsPos[temp_rand2].y - 10.0f;
                        sp188.z = pthis->bodySegsPos[temp_rand2].z;

                        sp164.y = 0.03f;

                        EffectSsKFire_Spawn(globalCtx, &sp188, &sp17C, &sp164, (s16)Rand_ZeroFloat(20.0f) + 40, 0x64);

                        for (i2 = 0; i2 < 15; i2++) {
                            sp170.x = Rand_CenteredFloat(20.0f);
                            sp170.y = Rand_CenteredFloat(20.0f);
                            sp170.z = Rand_CenteredFloat(20.0f);

                            sp158.y = 0.4f;
                            sp158.x = Rand_CenteredFloat(0.5f);
                            sp158.z = Rand_CenteredFloat(0.5f);

                            BossFd_SpawnEmber(pthis->effects, &sp188, &sp170, &sp158, (s16)Rand_ZeroFloat(3.0f) + 8);
                        }
                    }
                }
            }
            break;
        case BOSSFD_BONES_FALL:
            pthis->work[BFD_STOP_FLAG] = true;
            pthis->fogMode = 3;
            if (pthis->timers[0] < 18) {
                pthis->bodyFallApart[pthis->timers[0]] = 1;
            }
            if (pthis->timers[0] == 0) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_SKULL_PAUSE;
                pthis->timers[0] = 15;
                pthis->work[BFD_CEILING_TARGET] = 0;
                player->actor.world.pos.y = 90.0f;
                player->actor.world.pos.x = 40.0f;
                player->actor.world.pos.z = 150.0f;
            }
            break;
        case BOSSFD_SKULL_PAUSE:
            if (pthis->timers[0] == 0) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_SKULL_FALL;
                pthis->timers[0] = 20;
                pthis->work[BFD_STOP_FLAG] = false;
            }
            break;
        case BOSSFD_SKULL_FALL:
            pthis->fwork[BFD_TURN_RATE] = pthis->fwork[BFD_TURN_RATE_MAX] = pthis->actor.speedXZ =
                pthis->fwork[BFD_FLY_SPEED] = 0;

            if (pthis->timers[0] == 1) {
                pthis->actor.world.pos.x = 0;
                pthis->actor.world.pos.y = 900.0f;
                pthis->actor.world.pos.z = 150.0f;
                pthis->actor.world.rot.x = pthis->actor.world.rot.y = 0;
                pthis->actor.shape.rot.z = 0x1200;
                pthis->actor.velocity.x = 0;
                pthis->actor.velocity.z = 0;
            }
            if (pthis->timers[0] == 0) {
                if (pthis->actor.world.pos.y <= 110.0f) {
                    pthis->actor.world.pos.y = 110.0f;
                    pthis->actor.velocity.y = 0;
                    if (pthis->work[BFD_CEILING_TARGET] == 0) {
                        pthis->work[BFD_CEILING_TARGET]++;
                        pthis->timers[1] = 60;
                        pthis->work[BFD_CAM_SHAKE_TIMER] = 20;
                        Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_LAND2, &pthis->actor.projectedPos, 4, &D_801333E0,
                                               &D_801333E0, &gReverbAdd2);
                        func_8002DF54(globalCtx, &pthis->actor, 5);
                        for (i1 = 0; i1 < 15; i1++) {
                            Vec3f sp144 = { 0.0f, 0.0f, 0.0f };
                            Vec3f sp138 = { 0.0f, 0.0f, 0.0f };
                            Vec3f sp12C;

                            sp144.x = Rand_CenteredFloat(8.0f);
                            sp144.y = Rand_ZeroFloat(1.0f);
                            sp144.z = Rand_CenteredFloat(8.0f);

                            sp138.y = 0.3f;

                            sp12C.x = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.x;
                            sp12C.y = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y;
                            sp12C.z = Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.z;
                            BossFd_SpawnDust(pthis->effects, &sp12C, &sp144, &sp138, Rand_ZeroFloat(100.0f) + 300);
                        }
                    }
                } else {
                    pthis->actor.velocity.y -= 1.0f;
                }
            } else {
                pthis->actor.velocity.y = 0;
            }
            if (pthis->timers[1] == 1) {
                pthis->work[BFD_ACTION_STATE] = BOSSFD_SKULL_BURN;
                pthis->timers[0] = 70;
            }
            break;
        case BOSSFD_SKULL_BURN:
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.world.pos.y = 110.0f;
            pthis->fwork[BFD_TURN_RATE] = pthis->fwork[BFD_TURN_RATE_MAX] = pthis->actor.speedXZ =
                pthis->fwork[BFD_FLY_SPEED] = 0.0f;

            if ((50 > pthis->timers[0]) && (pthis->timers[0] > 0)) {
                Vec3f sp120;
                Vec3f sp114 = { 0.0f, 0.0f, 0.0f };
                Vec3f sp108 = { 0.0f, 0.03f, 0.0f };

                Audio_PlaySoundGeneral(NA_SE_EN_GOMA_LAST - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                                       &D_801333E0, &gReverbAdd2);

                sp120.x = Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.x;
                sp120.y = (Rand_CenteredFloat(10.0f) + pthis->actor.world.pos.y) - 10.0f;
                sp120.z = (Rand_CenteredFloat(40.0f) + pthis->actor.world.pos.z) + 5.0f;

                sp108.y = 0.03f;

                EffectSsKFire_Spawn(globalCtx, &sp120, &sp114, &sp108, (s16)Rand_ZeroFloat(15.0f) + 30, 0);
            }
            if (pthis->timers[0] < 20) {
                Math_ApproachZeroF(&pthis->actor.scale.x, 1.0f, 0.0025f);
                Actor_SetScale(&pthis->actor, pthis->actor.scale.x);
            }
            if (pthis->timers[0] == 0) {
                pthis->actionFunc = BossFd_Wait;
                pthis->actor.world.pos.y -= 1000.0f;
            }
            if (pthis->timers[0] == 7) {
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, pthis->actor.world.pos.x,
                            pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
            }
            break;
        case BOSSFD_WAIT_INTRO:
            break;
    }

    //                                 Update body segments and mane

    if (!pthis->work[BFD_STOP_FLAG]) {
        s16 i4;
        Vec3f spE0[3];
        Vec3f spBC[3];
        f32 phi_f20;
        f32 padB4;
        f32 padB0;
        f32 padAC;

        Math_ApproachS(&pthis->actor.world.rot.y, angleToTarget, 0xA, pthis->fwork[BFD_TURN_RATE]);

        if (((pthis->work[BFD_ACTION_STATE] == BOSSFD_FLY_CHASE) ||
             (pthis->work[BFD_ACTION_STATE] == BOSSFD_FLY_UNUSED)) &&
            (pthis->actor.world.pos.y < 110.0f) && (pitchToTarget < 0)) {
            pitchToTarget = 0;
            Math_ApproachF(&pthis->actor.world.pos.y, 110.0f, 1.0f, 5.0f);
        }

        Math_ApproachS(&pthis->actor.world.rot.x, pitchToTarget, 0xA, pthis->fwork[BFD_TURN_RATE]);
        Math_ApproachF(&pthis->fwork[BFD_TURN_RATE], pthis->fwork[BFD_TURN_RATE_MAX], 1.0f, 20000.0f);
        Math_ApproachF(&pthis->actor.speedXZ, pthis->fwork[BFD_FLY_SPEED], 1.0f, 0.1f);
        if (pthis->work[BFD_ACTION_STATE] < BOSSFD_SKULL_FALL) {
            func_8002D908(&pthis->actor);
        }
        func_8002D7EC(&pthis->actor);

        pthis->work[BFD_LEAD_BODY_SEG]++;
        if (pthis->work[BFD_LEAD_BODY_SEG] >= 100) {
            pthis->work[BFD_LEAD_BODY_SEG] = 0;
        }
        i4 = pthis->work[BFD_LEAD_BODY_SEG];
        pthis->bodySegsPos[i4].x = pthis->actor.world.pos.x;
        pthis->bodySegsPos[i4].y = pthis->actor.world.pos.y;
        pthis->bodySegsPos[i4].z = pthis->actor.world.pos.z;
        pthis->bodySegsRot[i4].x = (pthis->actor.world.rot.x / (f32)0x8000) * M_PI;
        pthis->bodySegsRot[i4].y = (pthis->actor.world.rot.y / (f32)0x8000) * M_PI;
        pthis->bodySegsRot[i4].z = (pthis->actor.world.rot.z / (f32)0x8000) * M_PI;

        pthis->work[BFD_LEAD_MANE_SEG]++;
        if (pthis->work[BFD_LEAD_MANE_SEG] >= 30) {
            pthis->work[BFD_LEAD_MANE_SEG] = 0;
        }
        i4 = pthis->work[BFD_LEAD_MANE_SEG];
        pthis->centerMane.scale[i4] = (Math_SinS(pthis->work[BFD_MOVE_TIMER] * 5596.0f) * 0.3f) + 1.0f;
        pthis->rightMane.scale[i4] = (Math_SinS(pthis->work[BFD_MOVE_TIMER] * 5496.0f) * 0.3f) + 1.0f;
        pthis->leftMane.scale[i4] = (Math_CosS(pthis->work[BFD_MOVE_TIMER] * 5696.0f) * 0.3f) + 1.0f;
        pthis->centerMane.pos[i4] = pthis->centerMane.head;
        pthis->fireManeRot[i4].x = (pthis->actor.world.rot.x / (f32)0x8000) * M_PI;
        pthis->fireManeRot[i4].y = (pthis->actor.world.rot.y / (f32)0x8000) * M_PI;
        pthis->fireManeRot[i4].z = (pthis->actor.world.rot.z / (f32)0x8000) * M_PI;
        pthis->rightMane.pos[i4] = pthis->rightMane.head;
        pthis->leftMane.pos[i4] = pthis->leftMane.head;

        if ((0x3000 > pthis->actor.world.rot.x) && (pthis->actor.world.rot.x > -0x3000)) {
            Math_ApproachF(&pthis->flattenMane, 1.0f, 1.0f, 0.05f);
        } else {
            Math_ApproachF(&pthis->flattenMane, 0.5f, 1.0f, 0.05f);
        }

        if (pthis->work[BFD_ACTION_STATE] < BOSSFD_SKULL_FALL) {
            if ((pthis->actor.prevPos.y < 90.0f) && (90.0f <= pthis->actor.world.pos.y)) {
                pthis->timers[4] = 80;
                func_80033E1C(globalCtx, 1, 80, 0x5000);
                pthis->work[BFD_ROAR_TIMER] = 40;
                pthis->work[BFD_MANE_EMBERS_TIMER] = 30;
                pthis->work[BFD_SPLASH_TIMER] = 10;
            }
            if ((pthis->actor.prevPos.y > 90.0f) && (90.0f >= pthis->actor.world.pos.y)) {
                pthis->timers[4] = 80;
                func_80033E1C(globalCtx, 1, 80, 0x5000);
                pthis->work[BFD_MANE_EMBERS_TIMER] = 30;
                pthis->work[BFD_SPLASH_TIMER] = 10;
            }
        }

        if (!sp1CF) {
            spE0[0].x = spE0[0].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1500.0f) * 3000.0f;
            spE0[1].x = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 2000.0f) * 4000.0f;
            spE0[1].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 2200.0f) * 4000.0f;
            spE0[2].x = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1700.0f) * 2000.0f;
            spE0[2].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1900.0f) * 2000.0f;
            spBC[0].x = spBC[0].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1500.0f) * -3000.0f;
            spBC[1].x = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 2200.0f) * -4000.0f;
            spBC[1].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 2000.0f) * -4000.0f;
            spBC[2].x = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1900.0f) * -2000.0f;
            spBC[2].y = Math_SinS(pthis->work[BFD_MOVE_TIMER] * 1700.0f) * -2000.0f;

            for (i3 = 0; i3 < 3; i3++) {
                Math_ApproachF(&pthis->rightArmRot[i3].x, spE0[i3].x, 1.0f, 1000.0f);
                Math_ApproachF(&pthis->rightArmRot[i3].y, spE0[i3].y, 1.0f, 1000.0f);
                Math_ApproachF(&pthis->leftArmRot[i3].x, spBC[i3].x, 1.0f, 1000.0f);
                Math_ApproachF(&pthis->leftArmRot[i3].y, spBC[i3].y, 1.0f, 1000.0f);
            }
        } else {
            for (i2 = 0; i2 < 3; i2++) {
                phi_f20 = 0.0f;
                Math_ApproachZeroF(&pthis->rightArmRot[i2].y, 0.1f, 100.0f);
                Math_ApproachZeroF(&pthis->leftArmRot[i2].y, 0.1f, 100.0f);
                if (i2 == 0) {
                    phi_f20 = -3000.0f;
                }
                Math_ApproachF(&pthis->rightArmRot[i2].x, phi_f20, 0.1f, 100.0f);
                Math_ApproachF(&pthis->leftArmRot[i2].x, -phi_f20, 0.1f, 100.0f);
            }
        }
    }
}

void BossFd_Wait(BossFd* pthis, GlobalContext* globalCtx) {
    if (pthis->handoffSignal == FD2_SIGNAL_FLY) { // Set by BossFd2
        u8 temp_rand;

        pthis->handoffSignal = FD2_SIGNAL_NONE;
        BossFd_SetupFly(pthis, globalCtx);
        do {
            temp_rand = Rand_ZeroFloat(8.9f);
        } while (temp_rand == pthis->holeIndex);
        pthis->holeIndex = temp_rand;
        if (1) {} // Needed for matching
        pthis->targetPosition.x = sHoleLocations[pthis->holeIndex].x;
        pthis->targetPosition.y = sHoleLocations[pthis->holeIndex].y - 200.0f;
        pthis->targetPosition.z = sHoleLocations[pthis->holeIndex].z;
        pthis->actor.world.pos = pthis->targetPosition;

        pthis->timers[0] = 10;
        pthis->work[BFD_ACTION_STATE] = BOSSFD_EMERGE;
        pthis->work[BFD_START_ATTACK] = true;
    }
    if (pthis->handoffSignal == FD2_SIGNAL_DEATH) {
        pthis->handoffSignal = FD2_SIGNAL_NONE;
        BossFd_SetupFly(pthis, globalCtx);
        pthis->holeIndex = 1;
        pthis->targetPosition.x = sHoleLocations[1].x;
        pthis->targetPosition.y = sHoleLocations[1].y - 200.0f;
        pthis->targetPosition.z = sHoleLocations[1].z;
        pthis->actor.world.pos = pthis->targetPosition;
        pthis->timers[0] = 10;
        pthis->work[BFD_ACTION_STATE] = BOSSFD_EMERGE;
    }
}

static Vec3f sFireAudioVec = { 0.0f, 0.0f, 50.0f };

void BossFd_Effects(BossFd* pthis, GlobalContext* globalCtx) {
    s16 breathOpacity = 0;
    f32 jawAngle;
    f32 jawSpeed;
    f32 emberRate;
    f32 emberSpeed;
    s16 eyeStates[] = { EYE_OPEN, EYE_HALF, EYE_CLOSED, EYE_CLOSED, EYE_HALF };
    f32 temp_x;
    f32 temp_z;
    s16 i;

    if (1) {} // Needed for match

    if (pthis->fogMode == 0) {
        globalCtx->envCtx.unk_BF = 0;
        globalCtx->envCtx.unk_D8 = 0.5f + 0.5f * Math_SinS(pthis->work[BFD_VAR_TIMER] * 0x500);
        globalCtx->envCtx.unk_DC = 2;
        globalCtx->envCtx.unk_BD = 1;
        globalCtx->envCtx.unk_BE = 0;
    } else if (pthis->fogMode == 3) {
        globalCtx->envCtx.unk_BF = 0;
        globalCtx->envCtx.unk_DC = 2;
        globalCtx->envCtx.unk_BD = 2;
        globalCtx->envCtx.unk_BE = 0;
        Math_ApproachF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.05f);
    } else if (pthis->fogMode == 2) {
        pthis->fogMode--;
        globalCtx->envCtx.unk_BF = 0;
        Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.55f + 0.05f * Math_SinS(pthis->work[BFD_VAR_TIMER] * 0x3E00), 1.0f,
                       0.15f);
        globalCtx->envCtx.unk_DC = 2;
        globalCtx->envCtx.unk_BD = 3;
        globalCtx->envCtx.unk_BE = 0;
    } else if (pthis->fogMode == 10) {
        pthis->fogMode = 1;
        globalCtx->envCtx.unk_BF = 0;
        Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.21f + 0.07f * Math_SinS(pthis->work[BFD_VAR_TIMER] * 0xC00), 1.0f,
                       0.05f);
        globalCtx->envCtx.unk_DC = 2;
        globalCtx->envCtx.unk_BD = 3;
        globalCtx->envCtx.unk_BE = 0;
    } else if (pthis->fogMode == 1) {
        Math_ApproachF(&globalCtx->envCtx.unk_D8, 0.0f, 1.0f, 0.03f);
        if (globalCtx->envCtx.unk_D8 <= 0.01f) {
            pthis->fogMode = 0;
        }
    }

    if (pthis->work[BFD_MANE_EMBERS_TIMER] != 0) {
        pthis->work[BFD_MANE_EMBERS_TIMER]--;
        emberSpeed = emberRate = 20.0f;
    } else {
        emberRate = 3.0f;
        emberSpeed = 5.0f;
    }
    Math_ApproachF(&pthis->fwork[BFD_MANE_EMBER_RATE], emberRate, 1.0f, 0.1f);
    Math_ApproachF(&pthis->fwork[BFD_MANE_EMBER_SPEED], emberSpeed, 1.0f, 0.5f);

    if (((pthis->work[BFD_VAR_TIMER] % 8) == 0) && (Rand_ZeroOne() < 0.3f)) {
        pthis->work[BFD_BLINK_TIMER] = 4;
    }
    pthis->eyeState = eyeStates[pthis->work[BFD_BLINK_TIMER]];

    if (pthis->work[BFD_BLINK_TIMER] != 0) {
        pthis->work[BFD_BLINK_TIMER]--;
    }

    if (pthis->work[BFD_ROAR_TIMER] != 0) {
        if (pthis->work[BFD_ROAR_TIMER] == 37) {
            Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_ROAR, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                                   &gReverbAdd2);
        }
        jawAngle = 6000.0f;
        jawSpeed = 1300.0f;
    } else {
        jawAngle = (pthis->work[BFD_VAR_TIMER] & 0x10) ? 0.0f : 1000.0f;
        jawSpeed = 500.0f;
    }
    Math_ApproachF(&pthis->jawOpening, jawAngle, 0.3f, jawSpeed);

    if (pthis->work[BFD_ROAR_TIMER] != 0) {
        pthis->work[BFD_ROAR_TIMER]--;
    }

    if (pthis->timers[4] != 0) {
        Vec3f spawnVel1;
        Vec3f spawnAccel1;
        Vec3f spawnPos1;
        s32 pad;

        Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_APPEAR - SFX_FLAG, &pthis->actor.projectedPos, 4, &D_801333E0,
                               &D_801333E0, &gReverbAdd2);
        if (pthis->work[BFD_SPLASH_TIMER] != 0) {
            pthis->work[BFD_SPLASH_TIMER]--;
            if ((pthis->actor.colChkInfo.health == 0) ||
                ((pthis->introState == BFD_CS_EMERGE) && (pthis->actor.world.rot.x > 0x3000))) {
                if ((u8)pthis->fogMode == 0) {
                    globalCtx->envCtx.unk_D8 = 0.0f;
                }
                pthis->fogMode = 2;
            }
            for (i = 0; i < 5; i++) {
                spawnVel1.x = Rand_CenteredFloat(20.0f);
                spawnVel1.y = Rand_ZeroFloat(5.0f) + 4.0f;
                spawnVel1.z = Rand_CenteredFloat(20.0f);

                spawnAccel1.x = spawnAccel1.z = 0.0f;
                spawnAccel1.y = -0.3f;

                temp_x = (spawnVel1.x * 20) / 10.0f;
                temp_z = (spawnVel1.z * 20) / 10.0f;
                spawnPos1.x = temp_x + pthis->holePosition.x;
                spawnPos1.y = 100.0f;
                spawnPos1.z = temp_z + pthis->holePosition.z;

                func_8002836C(globalCtx, &spawnPos1, &spawnVel1, &spawnAccel1, &colorYellow_59, &colorRed_59,
                              (s16)Rand_ZeroFloat(150.0f) + 800, 10, (s16)Rand_ZeroFloat(5.0f) + 17);
            }
        } else {
            for (i = 0; i < 2; i++) {
                spawnVel1.x = Rand_CenteredFloat(10.0f);
                spawnVel1.y = Rand_ZeroFloat(3.0f) + 3.0f;
                spawnVel1.z = Rand_CenteredFloat(10.0f);

                spawnAccel1.x = spawnAccel1.z = 0.0f;
                spawnAccel1.y = -0.3f;
                temp_x = (spawnVel1.x * 50) / 10.0f;
                temp_z = (spawnVel1.z * 50) / 10.0f;

                spawnPos1.x = temp_x + pthis->holePosition.x;
                spawnPos1.y = 100.0f;
                spawnPos1.z = temp_z + pthis->holePosition.z;

                func_8002836C(globalCtx, &spawnPos1, &spawnVel1, &spawnAccel1, &colorYellow_59, &colorRed_59, 500, 10, 20);
            }
        }

        for (i = 0; i < 8; i++) {
            spawnVel1.x = Rand_CenteredFloat(20.0f);
            spawnVel1.y = Rand_ZeroFloat(10.0f);
            spawnVel1.z = Rand_CenteredFloat(20.0f);

            spawnAccel1.y = 0.4f;
            spawnAccel1.x = Rand_CenteredFloat(0.5f);
            spawnAccel1.z = Rand_CenteredFloat(0.5f);

            spawnPos1.x = Rand_CenteredFloat(60.0) + pthis->holePosition.x;
            spawnPos1.y = Rand_ZeroFloat(40.0f) + 100.0f;
            spawnPos1.z = Rand_CenteredFloat(60.0) + pthis->holePosition.z;

            BossFd_SpawnEmber(pthis->effects, &spawnPos1, &spawnVel1, &spawnAccel1, (s16)Rand_ZeroFloat(1.5f) + 6);
        }
    }

    if ((pthis->fireBreathTimer != 0) && (pthis->fireBreathTimer < 17)) {
        breathOpacity = (pthis->fireBreathTimer >= 6) ? 255 : pthis->fireBreathTimer * 50;
    }
    if (breathOpacity != 0) {
        f32 spawnAngleX;
        f32 spawnAngleY;
        Vec3f spawnSpeed2 = { 0.0f, 0.0f, 0.0f };
        Vec3f spawnVel2;
        Vec3f spawnAccel2 = { 0.0f, 0.0f, 0.0f };
        Vec3f spawnPos2;

        pthis->fogMode = 2;
        spawnSpeed2.z = 30.0f;

        Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_FIRE - SFX_FLAG, &sFireAudioVec, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
        spawnPos2 = pthis->headPos;

        spawnAngleY = (pthis->actor.world.rot.y / (f32)0x8000) * M_PI;
        spawnAngleX = (((-pthis->actor.world.rot.x) / (f32)0x8000) * M_PI) + 0.3f;
        Matrix_RotateY(spawnAngleY, MTXMODE_NEW);
        Matrix_RotateX(spawnAngleX, MTXMODE_APPLY);
        Matrix_MultVec3f(&spawnSpeed2, &spawnVel2);

        BossFd_SpawnFireBreath(pthis->effects, &spawnPos2, &spawnVel2, &spawnAccel2,
                               50.0f * Math_SinS(pthis->work[BFD_VAR_TIMER] * 0x2000) + 300.0f, breathOpacity,
                               pthis->actor.world.rot.y);

        spawnPos2.x += spawnVel2.x * 0.5f;
        spawnPos2.y += spawnVel2.y * 0.5f;
        spawnPos2.z += spawnVel2.z * 0.5f;

        BossFd_SpawnFireBreath(pthis->effects, &spawnPos2, &spawnVel2, &spawnAccel2,
                               50.0f * Math_SinS(pthis->work[BFD_VAR_TIMER] * 0x2000) + 300.0f, breathOpacity,
                               pthis->actor.world.rot.y);
        spawnSpeed2.x = 0.0f;
        spawnSpeed2.y = 17.0f;
        spawnSpeed2.z = 0.0f;

        for (i = 0; i < 6; i++) {
            spawnAngleY = Rand_ZeroFloat(2.0f * M_PI);
            spawnAngleX = Rand_ZeroFloat(2.0f * M_PI);
            Matrix_RotateY(spawnAngleY, MTXMODE_NEW);
            Matrix_RotateX(spawnAngleX, MTXMODE_APPLY);
            Matrix_MultVec3f(&spawnSpeed2, &spawnVel2);

            spawnAccel2.x = (spawnVel2.x * -10) / 100;
            spawnAccel2.y = (spawnVel2.y * -10) / 100;
            spawnAccel2.z = (spawnVel2.z * -10) / 100;

            BossFd_SpawnEmber(pthis->effects, &pthis->headPos, &spawnVel2, &spawnAccel2, (s16)Rand_ZeroFloat(2.0f) + 8);
        }
    }

    if ((pthis->actor.world.pos.y < 90.0f) || (700.0f < pthis->actor.world.pos.y) || (pthis->actionFunc == BossFd_Wait)) {
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    } else {
        pthis->actor.flags |= ACTOR_FLAG_0;
    }
}

void BossFd_CollisionCheck(BossFd* pthis, GlobalContext* globalCtx) {
    ColliderJntSphElement* headCollider = &pthis->collider.elements[0];
    ColliderInfo* hurtbox;

    if (headCollider->info.bumperFlags & BUMP_HIT) {
        headCollider->info.bumperFlags &= ~BUMP_HIT;
        hurtbox = headCollider->info.acHitInfo;
        pthis->actor.colChkInfo.health -= 2;
        if (hurtbox->toucher.dmgFlags & 0x1000) {
            pthis->actor.colChkInfo.health -= 2;
        }
        if ((s8)pthis->actor.colChkInfo.health <= 2) {
            pthis->actor.colChkInfo.health = 2;
        }
        pthis->work[BFD_DAMAGE_FLASH_TIMER] = 10;
        pthis->work[BFD_INVINC_TIMER] = 20;
        Audio_PlaySoundGeneral(NA_SE_EN_VALVAISA_DAMAGE1, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &gReverbAdd2);
    }
}

void BossFd_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossFd* pthis = (BossFd*)thisx;
    f32 headGlow;
    f32 rManeGlow;
    f32 lManeGlow;
    s16 i;

    osSyncPrintf("FD MOVE START \n");
    pthis->work[BFD_VAR_TIMER]++;
    pthis->work[BFD_MOVE_TIMER]++;
    pthis->actionFunc(pthis, globalCtx);

    for (i = 0; i < ARRAY_COUNT(pthis->timers); i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }
    if (pthis->fireBreathTimer != 0) {
        pthis->fireBreathTimer--;
    }
    if (pthis->work[BFD_DAMAGE_FLASH_TIMER] != 0) {
        pthis->work[BFD_DAMAGE_FLASH_TIMER]--;
    }
    if (pthis->work[BFD_INVINC_TIMER] != 0) {
        pthis->work[BFD_INVINC_TIMER]--;
    }
    if (pthis->work[BFD_ACTION_STATE] < BOSSFD_DEATH_START) {
        if (pthis->work[BFD_INVINC_TIMER] == 0) {
            BossFd_CollisionCheck(pthis, globalCtx);
        }
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    }

    BossFd_Effects(pthis, globalCtx);
    pthis->fwork[BFD_TEX1_SCROLL_X] += 4.0f;
    pthis->fwork[BFD_TEX1_SCROLL_Y] = 120.0f;
    pthis->fwork[BFD_TEX2_SCROLL_X] += 3.0f;
    pthis->fwork[BFD_TEX2_SCROLL_Y] -= 2.0f;

    Math_ApproachF(&pthis->fwork[BFD_BODY_TEX2_ALPHA], (pthis->work[BFD_VAR_TIMER] & 0x10) ? 30.0f : 158.0f, 1.0f, 8.0f);
    if (pthis->skinSegments == 0) {
        pthis->fwork[BFD_HEAD_TEX2_ALPHA] = pthis->fwork[BFD_BODY_TEX2_ALPHA];
    } else {
        headGlow = (pthis->work[BFD_VAR_TIMER] & 4) ? 0.0f : 255.0f;
        Math_ApproachF(&pthis->fwork[BFD_HEAD_TEX2_ALPHA], headGlow, 1.0f, 64.0f);
    }

    headGlow = (pthis->work[BFD_VAR_TIMER] & 8) ? 128.0f : 255.0f;
    rManeGlow = ((pthis->work[BFD_VAR_TIMER] + 3) & 8) ? 128.0f : 255.0f;
    lManeGlow = ((pthis->work[BFD_VAR_TIMER] + 6) & 8) ? 128.0f : 255.0f;

    Math_ApproachF(&pthis->fwork[BFD_MANE_COLOR_CENTER], headGlow, 1.0f, 16.0f);
    Math_ApproachF(&pthis->fwork[BFD_MANE_COLOR_RIGHT], rManeGlow, 1.0f, 16.0f);
    Math_ApproachF(&pthis->fwork[BFD_MANE_COLOR_LEFT], lManeGlow, 1.0f, 16.0f);

    if (pthis->work[BFD_ROCK_TIMER] != 0) {
        pthis->work[BFD_ROCK_TIMER]--;
        if ((pthis->work[BFD_ROCK_TIMER] % 16) == 0) {
            EnVbBall* bossFdRock = (EnVbBall*)Actor_SpawnAsChild(
                &globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_VB_BALL, pthis->actor.world.pos.x, 1000.0f,
                pthis->actor.world.pos.z, 0, 0, (s16)Rand_ZeroFloat(50.0f) + 130, 100);

            if (bossFdRock != NULL) {
                for (i = 0; i < 10; i++) {
                    Vec3f debrisVel = { 0.0f, 0.0f, 0.0f };
                    Vec3f debrisAccel = { 0.0f, -1.0f, 0.0f };
                    Vec3f debrisPos;

                    debrisPos.x = Rand_CenteredFloat(300.0f) + bossFdRock->actor.world.pos.x;
                    debrisPos.y = Rand_CenteredFloat(300.0f) + bossFdRock->actor.world.pos.y;
                    debrisPos.z = Rand_CenteredFloat(300.0f) + bossFdRock->actor.world.pos.z;

                    BossFd_SpawnDebris(pthis->effects, &debrisPos, &debrisVel, &debrisAccel,
                                       (s16)Rand_ZeroFloat(15.0f) + 20);
                }
            }
        }
    }

    if (1) { // Needed for matching, and also to define new variables
        Vec3f emberVel = { 0.0f, 0.0f, 0.0f };
        Vec3f emberAccel = { 0.0f, 0.0f, 0.0f };
        Vec3f emberPos;
        s16 temp_rand;

        for (i = 0; i < 6; i++) {
            emberAccel.y = 0.4f;
            emberAccel.x = Rand_CenteredFloat(0.5f);
            emberAccel.z = Rand_CenteredFloat(0.5f);

            temp_rand = Rand_ZeroFloat(8.9f);

            emberPos.x = sHoleLocations[temp_rand].x + Rand_CenteredFloat(60.0f);
            emberPos.y = (sHoleLocations[temp_rand].y + 10.0f) + Rand_ZeroFloat(40.0f);
            emberPos.z = sHoleLocations[temp_rand].z + Rand_CenteredFloat(60.0f);

            BossFd_SpawnEmber(pthis->effects, &emberPos, &emberVel, &emberAccel, (s16)Rand_ZeroFloat(2.0f) + 6);
        }

        if (pthis->skinSegments != 0) {
            for (i = 0; i < (s16)pthis->fwork[BFD_MANE_EMBER_RATE]; i++) {
                temp_rand = Rand_ZeroFloat(29.9f);
                emberPos.y = pthis->centerMane.pos[temp_rand].y + Rand_CenteredFloat(20.0f);

                if (emberPos.y >= 90.0f) {
                    emberPos.x = pthis->centerMane.pos[temp_rand].x + Rand_CenteredFloat(20.0f);
                    emberPos.z = pthis->centerMane.pos[temp_rand].z + Rand_CenteredFloat(20.0f);

                    emberVel.x = Rand_CenteredFloat(pthis->fwork[BFD_MANE_EMBER_SPEED]);
                    emberVel.y = Rand_CenteredFloat(pthis->fwork[BFD_MANE_EMBER_SPEED]);
                    emberVel.z = Rand_CenteredFloat(pthis->fwork[BFD_MANE_EMBER_SPEED]);

                    emberAccel.y = 0.4f;
                    emberAccel.x = Rand_CenteredFloat(0.5f);
                    emberAccel.z = Rand_CenteredFloat(0.5f);

                    BossFd_SpawnEmber(pthis->effects, &emberPos, &emberVel, &emberAccel, (s16)Rand_ZeroFloat(2.0f) + 8);
                }
            }
        }
    }
    osSyncPrintf("FD MOVE END 1\n");
    BossFd_UpdateEffects(pthis, globalCtx);
    osSyncPrintf("FD MOVE END 2\n");
}

void BossFd_UpdateEffects(BossFd* pthis, GlobalContext* globalCtx) {
    BossFdEffect* effect = pthis->effects;
    Player* player = GET_PLAYER(globalCtx);
    Color_RGB8 colors[4] = { { 255, 128, 0 }, { 255, 0, 0 }, { 255, 255, 0 }, { 255, 0, 0 } };
    Vec3f diff;
    s16 i1;
    s16 i2;

    for (i1 = 0; i1 < 180; i1++, effect++) {
        if (effect->type != BFD_FX_NONE) {
            effect->timer1++;

            effect->pos.x += effect->velocity.x;
            effect->pos.y += effect->velocity.y;
            effect->pos.z += effect->velocity.z;

            effect->velocity.x += effect->accel.x;
            effect->velocity.y += effect->accel.y;
            effect->velocity.z += effect->accel.z;
            if (effect->type == BFD_FX_EMBER) {
                s16 cInd = effect->timer1 % 4;

                effect->color.r = colors[cInd].r;
                effect->color.g = colors[cInd].g;
                effect->color.b = colors[cInd].b;
                effect->alpha -= 20;
                if (effect->alpha <= 0) {
                    effect->alpha = 0;
                    effect->type = 0;
                }
            } else if ((effect->type == BFD_FX_DEBRIS) || (effect->type == BFD_FX_SKULL_PIECE)) {
                effect->vFdFxRotX += 0.55f;
                effect->vFdFxRotY += 0.1f;
                if (effect->pos.y <= 100.0f) {
                    effect->type = 0;
                }
            } else if (effect->type == BFD_FX_DUST) {
                if (effect->timer2 >= 8) {
                    effect->timer2 = 8;
                    effect->type = 0;
                } else if (((effect->timer1 % 2) != 0) || (Rand_ZeroOne() < 0.3f)) {
                    effect->timer2++;
                }
            } else if (effect->type == BFD_FX_FIRE_BREATH) {
                diff.x = player->actor.world.pos.x - effect->pos.x;
                diff.y = player->actor.world.pos.y + 30.0f - effect->pos.y;
                diff.z = player->actor.world.pos.z - effect->pos.z;
                if ((pthis->timers[3] == 0) && (sqrtf(SQ(diff.x) + SQ(diff.y) + SQ(diff.z)) < 20.0f)) {
                    pthis->timers[3] = 50;
                    func_8002F6D4(globalCtx, NULL, 5.0f, effect->kbAngle, 0.0f, 0x30);
                    if (player->isBurning == false) {
                        for (i2 = 0; i2 < ARRAY_COUNT(player->flameTimers); i2++) {
                            player->flameTimers[i2] = Rand_S16Offset(0, 200);
                        }
                        player->isBurning = true;
                    }
                }
                if (effect->timer2 == 0) {
                    if (effect->scale < 2.5f) {
                        effect->scale += effect->vFdFxScaleMod;
                        effect->vFdFxScaleMod += 0.08f;
                    }
                    if ((effect->pos.y <= (effect->vFdFxYStop + 130.0f)) || (effect->timer1 >= 10)) {
                        effect->accel.y = 5.0f;
                        effect->timer2++;
                        effect->velocity.y = 0.0f;
                        effect->accel.x = (effect->velocity.x * -25.0f) / 100.0f;
                        effect->accel.z = (effect->velocity.z * -25.0f) / 100.0f;
                    }
                } else {
                    if (effect->scale < 2.5f) {
                        Math_ApproachF(&effect->scale, 2.5f, 0.5f, 0.5f);
                    }
                    effect->timer2++;
                    if (effect->timer2 >= 9) {
                        effect->type = 0;
                    }
                }
            }
        }
    }
}

void BossFd_DrawEffects(BossFdEffect* effect, GlobalContext* globalCtx) {
    u8 flag = false;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;
    BossFdEffect* firstEffect = effect;

    OPEN_DISPS(gfxCtx, "../z_boss_fd.c", 4023);

    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_EMBER) {
            if (!flag) {
                func_80093D84(globalCtx->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gVolvagiaEmberMaterialDL);
                flag++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, effect->color.r, effect->color.g, effect->color.b, effect->alpha);
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_fd.c", 4046),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gVolvagiaEmberModelDL);
        }
    }

    effect = firstEffect;
    flag = false;
    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_DEBRIS) {
            if (!flag) {
                func_80093D18(globalCtx->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, gVolvagiaDebrisMaterialDL);
                flag++;
            }

            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_RotateY(effect->vFdFxRotY, MTXMODE_APPLY);
            Matrix_RotateX(effect->vFdFxRotX, MTXMODE_APPLY);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_fd.c", 4068),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gVolvagiaDebrisModelDL);
        }
    }

    effect = firstEffect;
    flag = false;
    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_DUST) {
            if (!flag) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
                gSPDisplayList(POLY_XLU_DISP++, gVolvagiaDustMaterialDL);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 90, 30, 0, 255);
                gDPSetEnvColor(POLY_XLU_DISP++, 90, 30, 0, 0);
                flag++;
            }

            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
            func_800D1FD4(&globalCtx->billboardMtxF);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_fd.c", 4104),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(dustTex_63[effect->timer2]));
            gSPDisplayList(POLY_XLU_DISP++, gVolvagiaDustModelDL);
        }
    }

    effect = firstEffect;
    flag = false;
    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_FIRE_BREATH) {
            if (!flag) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
                gSPDisplayList(POLY_XLU_DISP++, gVolvagiaDustMaterialDL);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 10, 0, 255);
                flag++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 0, effect->alpha);
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
            func_800D1FD4(&globalCtx->billboardMtxF);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_fd.c", 4154),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(dustTex_63[effect->timer2]));
            gSPDisplayList(POLY_XLU_DISP++, gVolvagiaDustModelDL);
        }
    }

    effect = firstEffect;
    flag = false;
    for (i = 0; i < 180; i++, effect++) {
        if (effect->type == BFD_FX_SKULL_PIECE) {
            if (!flag) {
                func_80093D84(globalCtx->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gVolvagiaSkullPieceMaterialDL);
                flag++;
            }

            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_RotateY(effect->vFdFxRotY, MTXMODE_APPLY);
            Matrix_RotateX(effect->vFdFxRotX, MTXMODE_APPLY);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_boss_fd.c", 4192),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gVolvagiaSkullPieceModelDL);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_boss_fd.c", 4198);
}

void BossFd_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BossFd* pthis = (BossFd*)thisx;

    osSyncPrintf("FD DRAW START\n");
    if (pthis->actionFunc != BossFd_Wait) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4217);
        func_80093D18(globalCtx->state.gfxCtx);
        if (pthis->work[BFD_DAMAGE_FLASH_TIMER] & 2) {
            POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 255, 255, 0, 900, 1099);
        }

        BossFd_DrawBody(globalCtx, pthis);
        POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4243);
    }

    osSyncPrintf("FD DRAW END\n");
    BossFd_DrawEffects(pthis->effects, globalCtx);
    osSyncPrintf("FD DRAW END2\n");
}

s32 BossFd_OverrideRightArmDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    BossFd* pthis = (BossFd*)thisx;

    switch (limbIndex) {
        case 1:
            rot->y += 4000.0f + pthis->rightArmRot[0].x;
            break;
        case 2:
            rot->y += pthis->rightArmRot[1].x;
            rot->z += pthis->rightArmRot[1].y;
            break;
        case 3:
            rot->y += pthis->rightArmRot[2].x;
            rot->z += pthis->rightArmRot[2].y;
            break;
    }
    if (pthis->skinSegments < limbIndex) {
        *dList = NULL;
    }
    return false;
}

s32 BossFd_OverrideLeftArmDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                               void* thisx) {
    BossFd* pthis = (BossFd*)thisx;

    switch (limbIndex) {
        case 1:
            rot->y += -4000.0f + pthis->leftArmRot[0].x;
            break;
        case 2:
            rot->y += pthis->leftArmRot[1].x;
            rot->z += pthis->leftArmRot[1].y;
            break;
        case 3:
            rot->y += pthis->leftArmRot[2].x;
            rot->z += pthis->leftArmRot[2].y;
            break;
    }
    if (pthis->skinSegments < limbIndex) {
        *dList = NULL;
    }
    return false;
}

static s16 sBodyIndex[] = { 0, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5 };
static s16 sManeIndex[] = { 0, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10 }; // Unused

void BossFd_DrawMane(GlobalContext* globalCtx, BossFd* pthis, Vec3f* manePos, Vec3f* maneRot, f32* maneScale, u8 mode) {
    f32 sp140[] = { 0.0f, 10.0f, 17.0f, 20.0f, 19.5f, 18.0f, 17.0f, 15.0f, 15.0f, 15.0f };
    f32 sp118[] = { 0.0f, 10.0f, 17.0f, 20.0f, 21.0f, 21.0f, 21.0f, 21.0f, 21.0f, 21.0f };
    f32 spF0[] = { 0.4636457f, 0.3366129f, 0.14879614f, 0.04995025f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    // arctan of {0.5, 0.35, 0.15, 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    f32 spC8[] = { -0.4636457f, -0.3366129f, -0.14879614f, 0.024927188f, 0.07478157f,
                   0.04995025f, 0.09961288f, 0.0f,         0.0f,         0.0f };
    // arctan of {-0.5, -0.35, -0.15, 0.025, 0.075, 0.05, 0.1, 0.0, 0.0}
    s16 maneIndex;
    s16 i;
    s16 maneLength;
    Vec3f spB4;
    Vec3f spA8;
    f32 phi_f20;
    f32 phi_f22;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4419);

    maneLength = pthis->skinSegments;
    maneLength = CLAMP_MAX(maneLength, 10);

    for (i = 0; i < maneLength; i++) {
        maneIndex = (pthis->work[BFD_LEAD_MANE_SEG] - (i * 2) + 30) % 30;

        if (mode == 0) {
            spB4.x = spB4.z = 0.0f;
            spB4.y = ((sp140[i] * 0.1f) * 10.0f) * pthis->flattenMane;
            phi_f20 = 0.0f;
            phi_f22 = spC8[i] * pthis->flattenMane;
        } else if (mode == 1) {
            phi_f22 = (spC8[i] * pthis->flattenMane) * 0.7f;
            phi_f20 = spF0[i] * pthis->flattenMane;

            spB4.y = (sp140[i] * pthis->flattenMane) * 0.7f;
            spB4.x = -sp118[i] * pthis->flattenMane;
            spB4.z = 0.0f;
        } else {
            phi_f22 = (spC8[i] * pthis->flattenMane) * 0.7f;
            phi_f20 = -spF0[i] * pthis->flattenMane;

            spB4.y = (sp140[i] * pthis->flattenMane) * 0.7f;
            spB4.x = sp118[i] * pthis->flattenMane;
            spB4.z = 0.0f;
        }

        Matrix_RotateY((maneRot + maneIndex)->y, MTXMODE_NEW);
        Matrix_RotateX(-(maneRot + maneIndex)->x, MTXMODE_APPLY);

        Matrix_MultVec3f(&spB4, &spA8);

        Matrix_Translate((manePos + maneIndex)->x + spA8.x, (manePos + maneIndex)->y + spA8.y,
                         (manePos + maneIndex)->z + spA8.z, MTXMODE_NEW);
        Matrix_RotateY((maneRot + maneIndex)->y + phi_f20, MTXMODE_APPLY);
        Matrix_RotateX(-((maneRot + maneIndex)->x + phi_f22), MTXMODE_APPLY);
        Matrix_Scale(maneScale[maneIndex] * (0.01f - (i * 0.0008f)), maneScale[maneIndex] * (0.01f - (i * 0.0008f)),
                     0.01f, MTXMODE_APPLY);
        Matrix_RotateX(-M_PI / 2.0f, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4480),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gVolvagiaManeModelDL);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4483);
}

s32 BossFd_OverrideHeadDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    BossFd* pthis = (BossFd*)thisx;

    switch (limbIndex) {
        case 5:
        case 6:
            rot->z -= pthis->jawOpening * 0.1f;
            break;
        case 2:
            rot->z += pthis->jawOpening;
            break;
    }
    if ((pthis->faceExposed == true) && (limbIndex == 5)) {
        *dList = gVolvagiaBrokenFaceDL;
    }
    if (pthis->skinSegments == 0) {
        if (limbIndex == 6) {
            *dList = gVolvagiaSkullDL;
        } else if (limbIndex == 2) {
            *dList = gVolvagiaJawboneDL;
        } else {
            *dList = NULL;
        }
    }
    return false;
}

void BossFd_PostHeadDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    BossFd* pthis = (BossFd*)thisx;

    if (limbIndex == 5) {
        Matrix_MultVec3f(&targetMod_72, &pthis->actor.focus.pos);
        Matrix_MultVec3f(&headMod_72, &pthis->headPos);
    }
}

static void* sEyeTextures[] = {
    gVolvagiaEyeOpenTex,
    gVolvagiaEyeHalfTex,
    gVolvagiaEyeClosedTex,
};

static Gfx* sBodyDLists[] = {
    gVolvagiaBodySeg1DL,  gVolvagiaBodySeg2DL,  gVolvagiaBodySeg3DL,  gVolvagiaBodySeg4DL,  gVolvagiaBodySeg5DL,
    gVolvagiaBodySeg6DL,  gVolvagiaBodySeg7DL,  gVolvagiaBodySeg8DL,  gVolvagiaBodySeg9DL,  gVolvagiaBodySeg10DL,
    gVolvagiaBodySeg11DL, gVolvagiaBodySeg12DL, gVolvagiaBodySeg13DL, gVolvagiaBodySeg14DL, gVolvagiaBodySeg15DL,
    gVolvagiaBodySeg16DL, gVolvagiaBodySeg17DL, gVolvagiaBodySeg18DL,
};

void BossFd_DrawBody(GlobalContext* globalCtx, BossFd* pthis) {
    s16 segIndex;
    s16 i;
    f32 temp_float;
    Mtx* tempMat = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, 18 * sizeof(Mtx));

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4589);
    if (pthis->skinSegments != 0) {
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sEyeTextures[pthis->eyeState]));
    }
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, (s16)pthis->fwork[BFD_TEX1_SCROLL_X],
                                (s16)pthis->fwork[BFD_TEX1_SCROLL_Y], 0x20, 0x20, 1, (s16)pthis->fwork[BFD_TEX2_SCROLL_X],
                                (s16)pthis->fwork[BFD_TEX2_SCROLL_Y], 0x20, 0x20));
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, (s8)pthis->fwork[BFD_BODY_TEX2_ALPHA]);

    osSyncPrintf("LH\n");
    Matrix_Push();
    segIndex = (pthis->work[BFD_LEAD_BODY_SEG] + sBodyIndex[2]) % 100;
    Matrix_Translate(pthis->bodySegsPos[segIndex].x, pthis->bodySegsPos[segIndex].y, pthis->bodySegsPos[segIndex].z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->bodySegsRot[segIndex].y, MTXMODE_APPLY);
    Matrix_RotateX(-pthis->bodySegsRot[segIndex].x, MTXMODE_APPLY);
    Matrix_Translate(-13.0f, -5.0f, 13.0f, MTXMODE_APPLY);
    Matrix_Scale(pthis->actor.scale.x * 0.1f, pthis->actor.scale.y * 0.1f, pthis->actor.scale.z * 0.1f, MTXMODE_APPLY);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnimeRightArm.skeleton, pthis->skelAnimeRightArm.jointTable,
                      BossFd_OverrideRightArmDraw, NULL, pthis);
    Matrix_Pop();
    osSyncPrintf("RH\n");
    Matrix_Push();
    segIndex = (pthis->work[BFD_LEAD_BODY_SEG] + sBodyIndex[2]) % 100;
    Matrix_Translate(pthis->bodySegsPos[segIndex].x, pthis->bodySegsPos[segIndex].y, pthis->bodySegsPos[segIndex].z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->bodySegsRot[segIndex].y, MTXMODE_APPLY);
    Matrix_RotateX(-pthis->bodySegsRot[segIndex].x, MTXMODE_APPLY);
    Matrix_Translate(13.0f, -5.0f, 13.0f, MTXMODE_APPLY);
    Matrix_Scale(pthis->actor.scale.x * 0.1f, pthis->actor.scale.y * 0.1f, pthis->actor.scale.z * 0.1f, MTXMODE_APPLY);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnimeLeftArm.skeleton, pthis->skelAnimeLeftArm.jointTable,
                      BossFd_OverrideLeftArmDraw, NULL, pthis);
    Matrix_Pop();
    osSyncPrintf("BD\n");
    gSPSegment(POLY_OPA_DISP++, 0x0D, tempMat);

    Matrix_Push();
    for (i = 0; i < 18; i++, tempMat++) {
        segIndex = (pthis->work[BFD_LEAD_BODY_SEG] + sBodyIndex[i + 1]) % 100;
        Matrix_Translate(pthis->bodySegsPos[segIndex].x, pthis->bodySegsPos[segIndex].y, pthis->bodySegsPos[segIndex].z,
                         MTXMODE_NEW);
        Matrix_RotateY(pthis->bodySegsRot[segIndex].y, MTXMODE_APPLY);
        Matrix_RotateX(-pthis->bodySegsRot[segIndex].x, MTXMODE_APPLY);
        Matrix_Translate(0.0f, 0.0f, 35.0f, MTXMODE_APPLY);
        Matrix_Scale(pthis->actor.scale.x, pthis->actor.scale.y, pthis->actor.scale.z, MTXMODE_APPLY);
        if (i < pthis->skinSegments) {
            Matrix_Scale(1.0f + (Math_SinS((pthis->work[BFD_LEAD_BODY_SEG] * 5000.0f) + (i * 7000.0f)) *
                                 pthis->fwork[BFD_BODY_PULSE]),
                         1.0f + (Math_SinS((pthis->work[BFD_LEAD_BODY_SEG] * 5000.0f) + (i * 7000.0f)) *
                                 pthis->fwork[BFD_BODY_PULSE]),
                         1.0f, MTXMODE_APPLY);
            Matrix_RotateY(M_PI / 2.0f, MTXMODE_APPLY);
            Matrix_ToMtx(tempMat, "../z_boss_fd.c", 4719);
            gSPMatrix(POLY_OPA_DISP++, tempMat, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, sBodyDLists[i]);
        } else {
            MtxF spFC;
            Vec3f spF0 = { 0.0f, 0.0f, 0.0f };
            Vec3f spE4;
            Vec3s spDC;
            f32 padD8;

            if (pthis->bodyFallApart[i] < 2) {
                f32 spD4 = 0.1f;

                temp_float = 0.1f;
                Matrix_Translate(0.0f, 0.0f, -1100.0f, MTXMODE_APPLY);
                Matrix_RotateY(-M_PI, MTXMODE_APPLY);
                if (i >= 14) {
                    f32 sp84 = 1.0f - ((i - 14) * 0.2f);

                    Matrix_Scale(sp84, sp84, 1.0f, MTXMODE_APPLY);
                    spD4 = 0.1f * sp84;
                    temp_float = 0.1f * sp84;
                }
                Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4768),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, gVolvagiaRibsDL);

                if (pthis->bodyFallApart[i] == 1) {
                    EnVbBall* bones;

                    pthis->bodyFallApart[i] = 2;
                    Matrix_MultVec3f(&spF0, &spE4);
                    Matrix_Get(&spFC);
                    Matrix_MtxFToYXZRotS(&spFC, &spDC, 0);
                    bones =
                        (EnVbBall*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_VB_BALL,
                                                      spE4.x, spE4.y, spE4.z, spDC.x, spDC.y, spDC.z, i + 200);

                    bones->actor.scale.x = pthis->actor.scale.x * temp_float;
                    bones->actor.scale.y = pthis->actor.scale.y * spD4;
                    bones->actor.scale.z = pthis->actor.scale.z * 0.1f;
                }
            }
        }
        if (i > 0) {
            Collider_UpdateSpheres(i + 1, &pthis->collider);
        }
    }
    Matrix_Pop();
    osSyncPrintf("BH\n");

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, (s8)pthis->fwork[BFD_HEAD_TEX2_ALPHA]);
    Matrix_Push();
    temp_float =
        (pthis->work[BFD_ACTION_STATE] >= BOSSFD_SKULL_FALL) ? -20.0f : -10.0f - ((pthis->actor.speedXZ - 5.0f) * 10.0f);
    segIndex = (pthis->work[BFD_LEAD_BODY_SEG] + sBodyIndex[0]) % 100;
    Matrix_Translate(pthis->bodySegsPos[segIndex].x, pthis->bodySegsPos[segIndex].y, pthis->bodySegsPos[segIndex].z,
                     MTXMODE_NEW);
    Matrix_RotateY(pthis->bodySegsRot[segIndex].y, MTXMODE_APPLY);
    Matrix_RotateX(-pthis->bodySegsRot[segIndex].x, MTXMODE_APPLY);
    Matrix_RotateZ((pthis->actor.shape.rot.z / (f32)0x8000) * M_PI, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, temp_float, MTXMODE_APPLY);
    Matrix_Push();
    Matrix_Translate(0.0f, 0.0f, 25.0f, MTXMODE_APPLY);
    osSyncPrintf("BHC\n");
    Collider_UpdateSpheres(0, &pthis->collider);
    Matrix_Pop();
    osSyncPrintf("BHCE\n");
    Matrix_Scale(pthis->actor.scale.x * 0.1f, pthis->actor.scale.y * 0.1f, pthis->actor.scale.z * 0.1f, MTXMODE_APPLY);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnimeHead.skeleton, pthis->skelAnimeHead.jointTable, BossFd_OverrideHeadDraw,
                      BossFd_PostHeadDraw, &pthis->actor);
    osSyncPrintf("SK\n");
    {
        Vec3f spB0 = { 0.0f, 1700.0f, 7000.0f };
        Vec3f spA4 = { -1000.0f, 700.0f, 7000.0f };

        func_80093D84(globalCtx->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gVolvagiaManeMaterialDL);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, pthis->fwork[BFD_MANE_COLOR_CENTER], 0, 255);
        Matrix_Push();
        Matrix_MultVec3f(&spB0, &pthis->centerMane.head);
        BossFd_DrawMane(globalCtx, pthis, pthis->centerMane.pos, pthis->fireManeRot, pthis->centerMane.scale, MANE_CENTER);
        Matrix_Pop();
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, pthis->fwork[BFD_MANE_COLOR_RIGHT], 0, 255);
        Matrix_Push();
        Matrix_MultVec3f(&spA4, &pthis->rightMane.head);
        BossFd_DrawMane(globalCtx, pthis, pthis->rightMane.pos, pthis->fireManeRot, pthis->rightMane.scale, MANE_RIGHT);
        Matrix_Pop();
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, pthis->fwork[BFD_MANE_COLOR_LEFT], 0, 255);
        Matrix_Push();
        spA4.x *= -1.0f;
        Matrix_MultVec3f(&spA4, &pthis->leftMane.head);
        BossFd_DrawMane(globalCtx, pthis, pthis->leftMane.pos, pthis->fireManeRot, pthis->leftMane.scale, MANE_LEFT);
        Matrix_Pop();
    }

    Matrix_Pop();
    osSyncPrintf("END\n");
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_fd.c", 4987);
}

void BossFd_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    colorYellow_59 = { 255, 255, 0, 255 };

    colorRed_59 = { 255, 10, 0, 255 };

    targetMod_72 = { 4500.0f, 0.0f, 0.0f };

    headMod_72 = { 4000.0f, 0.0f, 0.0f };

    Boss_Fd_InitVars = {
        ACTOR_BOSS_FD,
        ACTORCAT_BOSS,
        FLAGS,
        OBJECT_FD,
        sizeof(BossFd),
        (ActorFunc)BossFd_Init,
        (ActorFunc)BossFd_Destroy,
        (ActorFunc)BossFd_Update,
        (ActorFunc)BossFd_Draw,
        (ActorFunc)BossFd_Reset,
    };

    sFireAudioVec = { 0.0f, 0.0f, 50.0f };

}

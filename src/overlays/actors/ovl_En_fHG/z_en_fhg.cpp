#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FHG_Z_EN_FHG_C
#include "actor_common.h"
/*
 * File: z_en_fhg.c
 * Overlay: ovl_En_fHG
 * Description: Phantom Ganon's Horse
 */

#include "z_en_fhg.h"
#include "objects/object_fhg/object_fhg.h"
#include "overlays/actors/ovl_Door_Shutter/z_door_shutter.h"
#include "overlays/actors/ovl_Boss_Ganondrof/z_boss_ganondrof.h"
#include "overlays/actors/ovl_En_Fhg_Fire/z_en_fhg_fire.h"
#include "def/code_800F9280.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_demo.h"
#include "def/z_lib.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"
#include "def/z_skin.h"
#include "def/z_skin_awb.h"

#define FLAGS ACTOR_FLAG_4


void EnfHG_Init(Actor* thisx, GlobalContext* globalCtx);
void EnfHG_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnfHG_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnfHG_Update(Actor* thisx, GlobalContext* globalCtx);
void EnfHG_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnfHG_SetupIntro(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_Intro(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_SetupApproach(EnfHG* pthis, GlobalContext* globalCtx, s16 paintingIndex);
void EnfHG_Approach(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_Attack(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_Damage(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_Retreat(EnfHG* pthis, GlobalContext* globalCtx);
void EnfHG_Done(EnfHG* pthis, GlobalContext* globalCtx);

void EnfHG_Noop(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin);

static Vec3f audioVec_43 = { 0.0f, 0.0f, 50.0f };


ActorInit En_fHG_InitVars = {
    ACTOR_EN_FHG,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_FHG,
    sizeof(EnfHG),
    (ActorFunc)EnfHG_Init,
    (ActorFunc)EnfHG_Destroy,
    (ActorFunc)EnfHG_Update,
    (ActorFunc)EnfHG_Draw,
    (ActorFunc)EnfHG_Reset,
};

static EnfHGPainting sPaintings[] = {
    { { 0.0f, 60.0f, -315.0f }, 0x0000 },   { { -260.0f, 60.0f, -145.0f }, 0x2AAA },
    { { -260.0f, 60.0f, 165.0f }, 0x5554 }, { { 0.0f, 60.0f, 315.0f }, 0x7FFE },
    { { 260.0f, 60.0f, 155.0f }, 0xAAA8 },  { { 260.0f, 60.0f, -155.0f }, 0xD552 },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_S8(naviEnemyId, 0x1A, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 1200, ICHAIN_STOP),
};

void EnfHG_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnfHG* pthis = (EnfHG*)thisx;

    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    Flags_SetSwitch(globalCtx, 0x14);
    Actor_SetScale(&pthis->actor, 0.011499999f);
    pthis->actor.gravity = -3.5f;
    ActorShape_Init(&pthis->actor.shape, -2600.0f, NULL, 20.0f);
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    func_800A663C(globalCtx, &pthis->skin, &gPhantomHorseSkel, &gPhantomHorseRunningAnim);

    if (pthis->actor.params >= GND_FAKE_BOSS) {
        EnfHG_SetupApproach(pthis, globalCtx, pthis->actor.params - GND_FAKE_BOSS);
    } else {
        EnfHG_SetupIntro(pthis, globalCtx);
    }
}

void EnfHG_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnfHG* pthis = (EnfHG*)thisx;

    osSyncPrintf("F DT1\n");
    func_800A6888(globalCtx, &pthis->skin);
    osSyncPrintf("F DT2\n");
}

void EnfHG_SetupIntro(EnfHG* pthis, GlobalContext* globalCtx) {
    Animation_PlayLoop(&pthis->skin.skelAnime, &gPhantomHorseIdleAnim);
    pthis->actionFunc = EnfHG_Intro;
    pthis->actor.world.pos.x = GND_BOSSROOM_CENTER_X;
    pthis->actor.world.pos.y = GND_BOSSROOM_CENTER_Y - 267.0f;
    pthis->actor.world.pos.z = GND_BOSSROOM_CENTER_Z;
}

void EnfHG_Intro(EnfHG* pthis, GlobalContext* globalCtx) {
    s32 pad64;
    Player* player = GET_PLAYER(globalCtx);
    BossGanondrof* bossGnd = (BossGanondrof*)pthis->actor.parent;
    s32 pad58;
    s32 pad54;

    if (pthis->cutsceneState != INTRO_FINISH) {
        SkelAnime_Update(&pthis->skin.skelAnime);
    }
    switch (pthis->cutsceneState) {
        case INTRO_WAIT:
            if ((fabsf(player->actor.world.pos.x - (GND_BOSSROOM_CENTER_X + 0.0f)) < 150.0f) &&
                (fabsf(player->actor.world.pos.z - (GND_BOSSROOM_CENTER_Z + 0.0f)) < 150.0f)) {
                pthis->cutsceneState = INTRO_READY;
            }
            break;
        case INTRO_READY:
            if ((fabsf(player->actor.world.pos.x - (GND_BOSSROOM_CENTER_X + 0.0f)) < 100.0f) &&
                (fabsf(player->actor.world.pos.z - (GND_BOSSROOM_CENTER_Z + 315.0f)) < 100.0f)) {
                pthis->cutsceneState = INTRO_START;
                if (gSaveContext.eventChkInf[7] & 4) {
                    pthis->timers[0] = 57;
                }
            }
            break;
        case INTRO_START:
            if (gSaveContext.eventChkInf[7] & 4) {
                if (pthis->timers[0] == 55) {
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_SHUTTER,
                                       GND_BOSSROOM_CENTER_X + 0.0f, GND_BOSSROOM_CENTER_Y - 97.0f,
                                       GND_BOSSROOM_CENTER_Z + 308.0f, 0, 0, 0, (SHUTTER_PG_BARS << 6));
                }
                if (pthis->timers[0] == 51) {
                    Audio_PlayActorSound2(pthis->actor.child, NA_SE_EV_SPEAR_FENCE);
                    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
                }
                if (pthis->timers[0] == 0) {
                    EnfHG_SetupApproach(pthis, globalCtx, Rand_ZeroOne() * 5.99f);
                    pthis->bossGndSignal = FHG_START_FIGHT;
                }
                break;
            }
            func_80064520(globalCtx, &globalCtx->csCtx);
            func_8002DF54(globalCtx, &pthis->actor, 8);
            pthis->cutsceneCamera = Gameplay_CreateSubCamera(globalCtx);
            Gameplay_ChangeCameraStatus(globalCtx, MAIN_CAM, CAM_STAT_WAIT);
            Gameplay_ChangeCameraStatus(globalCtx, pthis->cutsceneCamera, CAM_STAT_ACTIVE);
            pthis->cutsceneState = INTRO_FENCE;
            pthis->timers[0] = 60;
            pthis->actor.world.pos.y = GND_BOSSROOM_CENTER_Y - 7.0f;
            Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x100FF);
            gSaveContext.eventChkInf[7] |= 4;
            Flags_SetSwitch(globalCtx, 0x23);
        case INTRO_FENCE:
            player->actor.world.pos.x = GND_BOSSROOM_CENTER_X + 0.0f;
            player->actor.world.pos.y = GND_BOSSROOM_CENTER_Y + 7.0f;
            player->actor.world.pos.z = GND_BOSSROOM_CENTER_Z + 155.0f;
            player->actor.world.rot.y = player->actor.shape.rot.y = 0;
            player->actor.speedXZ = 0.0f;
            pthis->cameraEye.x = GND_BOSSROOM_CENTER_X + 0.0f;
            pthis->cameraEye.y = GND_BOSSROOM_CENTER_Y + 37.0f;
            pthis->cameraEye.z = GND_BOSSROOM_CENTER_Z + 170.0f;
            pthis->cameraAt.x = GND_BOSSROOM_CENTER_X + 0.0f;
            pthis->cameraAt.y = GND_BOSSROOM_CENTER_Y + 47.0f;
            pthis->cameraAt.z = GND_BOSSROOM_CENTER_Z + 315.0f;
            if (pthis->timers[0] == 25) {
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_SHUTTER,
                                   GND_BOSSROOM_CENTER_X + 0.0f, GND_BOSSROOM_CENTER_Y - 97.0f,
                                   GND_BOSSROOM_CENTER_Z + 308.0f, 0, 0, 0, (SHUTTER_PG_BARS << 6));
            }
            if (pthis->timers[0] == 21) {
                Audio_PlayActorSound2(pthis->actor.child, NA_SE_EV_SPEAR_FENCE);
            }
            if (pthis->timers[0] == 0) {
                pthis->cutsceneState = INTRO_BACK;
                pthis->timers[0] = 80;
            }
            break;
        case INTRO_BACK:
            if (pthis->timers[0] == 25) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_HORSE_GROAN);
            }
            if (pthis->timers[0] == 20) {
                func_8002DF54(globalCtx, &pthis->actor, 9);
            }
            if (pthis->timers[0] == 1) {
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_OPENING_GANON);
            }
            Math_ApproachF(&pthis->cameraEye.x, GND_BOSSROOM_CENTER_X + 40.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraEye.y, GND_BOSSROOM_CENTER_Y + 37.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraEye.z, GND_BOSSROOM_CENTER_Z + 80.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.x, GND_BOSSROOM_CENTER_X - 100.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.y, GND_BOSSROOM_CENTER_Y + 47.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.z, GND_BOSSROOM_CENTER_Z + 335.0f, 0.05f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraSpeedMod, 1.0f, 1.0f, 0.01f);
            if (pthis->timers[0] == 0) {
                pthis->cutsceneState = INTRO_REVEAL;
                pthis->timers[0] = 50;
                pthis->cameraSpeedMod = 0.0f;
            }
            break;
        case INTRO_REVEAL:
            Math_ApproachF(&pthis->cameraEye.x, GND_BOSSROOM_CENTER_X + 70.0f, 0.1f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraEye.y, GND_BOSSROOM_CENTER_Y + 7.0f, 0.1f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraEye.z, GND_BOSSROOM_CENTER_Z + 200.0f, 0.1f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.x, GND_BOSSROOM_CENTER_X - 150.0f, 0.1f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.y, GND_BOSSROOM_CENTER_Y + 107.0f, 0.1f, pthis->cameraSpeedMod * 20.0f);
            Math_ApproachF(&pthis->cameraAt.z, GND_BOSSROOM_CENTER_Z - 65.0f, 0.1f, pthis->cameraSpeedMod * 40.0f);
            Math_ApproachF(&pthis->cameraSpeedMod, 1.0f, 1.0f, 0.05f);
            if (pthis->timers[0] == 5) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_HORSE_SANDDUST);
            }
            if (pthis->timers[0] == 0) {
                pthis->cutsceneState = INTRO_CUT;
                pthis->timers[0] = 50;
                pthis->cameraSpeedMod = 0.0f;
            }
            break;
        case INTRO_CUT:
            pthis->cutsceneState = INTRO_LAUGH;
            pthis->cameraEye.x = GND_BOSSROOM_CENTER_X + 50.0f;
            pthis->cameraEye.y = GND_BOSSROOM_CENTER_Y + 17.0f;
            pthis->cameraEye.z = GND_BOSSROOM_CENTER_Z + 110.0f;
            pthis->cameraAt.x = GND_BOSSROOM_CENTER_X - 150.0f;
            pthis->cameraAt.y = GND_BOSSROOM_CENTER_Y + 207.0f;
            pthis->cameraAt.z = GND_BOSSROOM_CENTER_Z - 155.0f;
            pthis->cameraEyeVel.x = fabsf(pthis->cameraEye.x - (GND_BOSSROOM_CENTER_X + 20.0f));
            pthis->cameraEyeVel.y = fabsf(pthis->cameraEye.y - (GND_BOSSROOM_CENTER_Y + 102.0f));
            pthis->cameraEyeVel.z = fabsf(pthis->cameraEye.z - (GND_BOSSROOM_CENTER_Z + 25.0f));
            pthis->cameraAtVel.x = fabsf(pthis->cameraAt.x - (GND_BOSSROOM_CENTER_X - 150.0f));
            pthis->cameraAtVel.y = fabsf(pthis->cameraAt.y - (GND_BOSSROOM_CENTER_Y + 197.0f));
            pthis->cameraAtVel.z = fabsf(pthis->cameraAt.z - (GND_BOSSROOM_CENTER_Z - 65.0f));
            pthis->timers[0] = 250;
        case INTRO_LAUGH:
            Math_ApproachF(&pthis->cameraEye.x, GND_BOSSROOM_CENTER_X + 20.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.x);
            Math_ApproachF(&pthis->cameraEye.y, GND_BOSSROOM_CENTER_Y + 102.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.y);
            Math_ApproachF(&pthis->cameraEye.z, GND_BOSSROOM_CENTER_Z + 25.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.z);
            Math_ApproachF(&pthis->cameraAt.x, GND_BOSSROOM_CENTER_X - 150.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraAtVel.x);
            Math_ApproachF(&pthis->cameraAt.y, GND_BOSSROOM_CENTER_Y + 197.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraAtVel.y);
            Math_ApproachF(&pthis->cameraAt.z, GND_BOSSROOM_CENTER_Z - 65.0f, 0.05f,
                           pthis->cameraSpeedMod * pthis->cameraAtVel.z);
            Math_ApproachF(&pthis->cameraSpeedMod, 0.01f, 1.0f, 0.001f);
            if ((pthis->timers[0] == 245) || (pthis->timers[0] == 3)) {
                Animation_MorphToPlayOnce(&pthis->skin.skelAnime, &gPhantomHorseRearingAnim, -8.0f);
                pthis->bossGndSignal = FHG_REAR;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_HORSE_NEIGH);
                if (pthis->timers[0] == 3) {
                    Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_VOICE);
                }
            }
            if (pthis->timers[0] == 192) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_HORSE_SANDDUST);
            }
            if (pthis->timers[0] == 212) {
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_HORSE_LAND2);
                Animation_Change(&pthis->skin.skelAnime, &gPhantomHorseIdleAnim, 0.3f, 0.0f, 5.0f, ANIMMODE_LOOP_INTERP,
                                 -10.0f);
            }
            if (pthis->timers[0] == 90) {
                globalCtx->envCtx.unk_BF = 2;
                globalCtx->envCtx.unk_D6 = 0x14;
            }
            if (pthis->timers[0] == 100) {
                pthis->bossGndSignal = FHG_LIGHTNING;
            }
            if (pthis->timers[0] == 60) {
                pthis->bossGndSignal = FHG_RIDE;
            }
            if (pthis->timers[0] == 130) {
                Audio_QueueSeqCmd(0x1 << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0x5000FF);
            }
            if (pthis->timers[0] == 30) {
                bossGnd->work[GND_EYE_STATE] = GND_EYESTATE_BRIGHTEN;
            }
            if (pthis->timers[0] == 35) {
                func_80078914(&audioVec_43, NA_SE_EN_FANTOM_EYE);
            }
            if (pthis->timers[0] == 130) {
                bossGnd->work[GND_EYE_STATE] = GND_EYESTATE_FADE;
                func_80078914(&audioVec_43, NA_SE_EN_FANTOM_ST_LAUGH);
            }
            if (pthis->timers[0] == 20) {
                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_BOSS);
            }
            if (pthis->timers[0] == 2) {
                pthis->cameraSpeedMod = 0.0f;
                pthis->cutsceneState = INTRO_TITLE;
                pthis->cameraEyeVel.x = fabsf(pthis->cameraEye.x - (GND_BOSSROOM_CENTER_X + 180.0f));
                pthis->cameraEyeVel.y = fabsf(pthis->cameraEye.y - (GND_BOSSROOM_CENTER_Y + 7.0f));
                pthis->cameraEyeVel.z = fabsf(pthis->cameraEye.z - (GND_BOSSROOM_CENTER_Z + 140.0f));
                pthis->timers[0] = 100;
                pthis->timers[1] = 34;
                pthis->cameraAtVel.x = fabsf(pthis->cameraAt.x - pthis->actor.world.pos.x);
                pthis->cameraAtVel.y = fabsf(pthis->cameraAt.y - ((pthis->actor.world.pos.y + 70.0f) - 20.0f));
                pthis->cameraAtVel.z = fabsf(pthis->cameraAt.z - pthis->actor.world.pos.z);
            }
            break;
        case INTRO_TITLE:
            if (pthis->timers[1] == 1) {
                Animation_Change(&pthis->skin.skelAnime, &gPhantomHorseIdleAnim, 0.5f, 0.0f,
                                 Animation_GetLastFrame(&gPhantomHorseIdleAnim), ANIMMODE_LOOP_INTERP, -3.0f);
            }
            Math_ApproachF(&pthis->cameraEye.x, GND_BOSSROOM_CENTER_X + 180.0f, 0.1f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.x);
            Math_ApproachF(&pthis->cameraEye.y, GND_BOSSROOM_CENTER_Y + 7.0f, 0.1f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.y);
            Math_ApproachF(&pthis->cameraEye.z, pthis->cameraPanZ + (GND_BOSSROOM_CENTER_Z + 140.0f), 0.1f,
                           pthis->cameraSpeedMod * pthis->cameraEyeVel.z);
            Math_ApproachF(&pthis->cameraPanZ, -100.0f, 0.1f, 1.0f);
            Math_ApproachF(&pthis->cameraAt.x, pthis->actor.world.pos.x, 0.1f, pthis->cameraSpeedMod * 10.0f);
            Math_ApproachF(&pthis->cameraAt.y, (pthis->actor.world.pos.y + 70.0f) - 20.0f, 0.1f,
                           pthis->cameraSpeedMod * 10.0f);
            Math_ApproachF(&pthis->cameraAt.z, pthis->actor.world.pos.z, 0.1f, pthis->cameraSpeedMod * 10.0f);
            Math_ApproachF(&pthis->actor.world.pos.y, 60.0f, 0.1f, 2.0f);
            pthis->actor.world.pos.y += 2.0f * Math_SinS(pthis->gallopTimer * 0x5DC);
            Math_ApproachF(&pthis->cameraSpeedMod, 1.0f, 1.0f, 0.05f);
            if (pthis->timers[0] == 75) {
                TitleCard_InitBossName(globalCtx, &globalCtx->actorCtx.titleCtx,
                                       SEGMENTED_TO_VIRTUAL(gPhantomGanonTitleCardTex), 160, 180, 128, 40);
            }
            if (pthis->timers[0] == 0) {
                pthis->cutsceneState = INTRO_RETREAT;
                pthis->timers[0] = 200;
                pthis->timers[1] = 23;
                pthis->cameraSpeedMod = 0.0f;
                Animation_Change(&pthis->skin.skelAnime, &gPhantomHorseLeapAnim, 1.0f, 0.0f,
                                 Animation_GetLastFrame(&gPhantomHorseLeapAnim), ANIMMODE_ONCE_INTERP, -4.0f);
                pthis->bossGndSignal = FHG_SPUR;
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_VOICE);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_HORSE_NEIGH);
            }
            break;
        case INTRO_RETREAT:
            if (pthis->timers[1] == 1) {
                Animation_Change(&pthis->skin.skelAnime, &gPhantomHorseLandAnim, 0.5f, 0.0f,
                                 Animation_GetLastFrame(&gPhantomHorseLandAnim), ANIMMODE_ONCE_INTERP, -3.0f);
                pthis->bossGndSignal = FHG_FINISH;
            }
            if (pthis->timers[0] == 170) {
                func_8002DF54(globalCtx, &pthis->actor, 8);
                Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_MASIC2);
            }
            Math_ApproachF(&pthis->cameraEye.z, pthis->cameraPanZ + (GND_BOSSROOM_CENTER_Z + 100.0f), 0.1f,
                           pthis->cameraSpeedMod * 1.5f);
            Math_ApproachF(&pthis->cameraPanZ, -100.0f, 0.1f, 1.0f);
            Math_ApproachF(&pthis->actor.world.pos.z, GND_BOSSROOM_CENTER_Z + 400.0f - 0.5f, 1.0f,
                           pthis->cameraSpeedMod * 10.0f);
            Math_ApproachF(&pthis->cameraSpeedMod, 1.0f, 1.0f, 0.05f);
            if ((fabsf(pthis->actor.world.pos.z - (GND_BOSSROOM_CENTER_Z + 400.0f - 0.5f)) < 300.0f) &&
                !pthis->spawnedWarp) {
                pthis->spawnedWarp = true;
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                   GND_BOSSROOM_CENTER_X + 0.0f, pthis->actor.world.pos.y + 50.0f,
                                   GND_BOSSROOM_CENTER_Z + 400.0f - 0.5f, 0, pthis->actor.shape.rot.y, 0,
                                   FHGFIRE_WARP_RETREAT);
                pthis->fhgFireKillWarp = true;
            }
            Math_ApproachF(&pthis->cameraAt.x, pthis->actor.world.pos.x, 0.2f, 50.0f);
            Math_ApproachF(&pthis->cameraAt.z, pthis->actor.world.pos.z, 0.2f, 50.0f);
            osSyncPrintf("TIME %d-------------------------------------------------\n", pthis->timers[0]);
            if (fabsf(pthis->actor.world.pos.z - (GND_BOSSROOM_CENTER_Z + 400.0f - 0.5f)) < 1.0f) {
                globalCtx->envCtx.unk_BF = 0;
                globalCtx->envCtx.unk_D6 = 0x14;
                pthis->cutsceneState = INTRO_FINISH;
                Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseRunningAnim, -3.0f);
                pthis->bossGndSignal = FHG_START_FIGHT;
                pthis->timers[1] = 75;
                pthis->timers[0] = 140;
            }
            break;
        case INTRO_FINISH:
            EnfHG_Retreat(pthis, globalCtx);
            Math_ApproachF(&pthis->cameraEye.z, pthis->cameraPanZ + (GND_BOSSROOM_CENTER_Z + 100.0f), 0.1f,
                           pthis->cameraSpeedMod * 1.5f);
            Math_ApproachF(&pthis->cameraPanZ, -100.0f, 0.1f, 1.0f);
            Math_ApproachF(&pthis->cameraAt.y, (pthis->actor.world.pos.y + 70.0f) - 20.0f, 0.1f,
                           pthis->cameraSpeedMod * 10.0f);
            if (pthis->timers[1] == 0) {
                Camera* camera = Gameplay_GetCamera(globalCtx, 0);

                camera->eye = pthis->cameraEye;
                camera->eyeNext = pthis->cameraEye;
                camera->at = pthis->cameraAt;
                func_800C08AC(globalCtx, pthis->cutsceneCamera, 0);
                pthis->cutsceneCamera = 0;
                func_80064534(globalCtx, &globalCtx->csCtx);
                func_8002DF54(globalCtx, &pthis->actor, 7);
                pthis->actionFunc = EnfHG_Retreat;
            }
            break;
    }
    if (pthis->cutsceneCamera != 0) {
        Gameplay_CameraSetAtEye(globalCtx, pthis->cutsceneCamera, &pthis->cameraAt, &pthis->cameraEye);
    }
}

void EnfHG_SetupApproach(EnfHG* pthis, GlobalContext* globalCtx, s16 paintingIndex) {
    s16 oppositeIndex[6] = { 3, 4, 5, 0, 1, 2 };

    Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseRunningAnim, 0.0f);
    pthis->actionFunc = EnfHG_Approach;
    pthis->curPainting = paintingIndex;
    pthis->targetPainting = oppositeIndex[pthis->curPainting];

    osSyncPrintf("KABE NO 1 = %d\n", pthis->curPainting);
    osSyncPrintf("KABE NO 2 = %d\n", pthis->targetPainting);

    pthis->actor.world.pos.x = (1.3f * sPaintings[pthis->curPainting].pos.x) + (GND_BOSSROOM_CENTER_X - 4.0f);
    pthis->actor.world.pos.y = sPaintings[pthis->curPainting].pos.y + (GND_BOSSROOM_CENTER_Y + 153.0f);
    pthis->actor.world.pos.z = (1.3f * sPaintings[pthis->curPainting].pos.z) - -(GND_BOSSROOM_CENTER_Z - 10.0f);
    pthis->actor.world.rot.y = sPaintings[pthis->curPainting].yRot;

    osSyncPrintf("XP1  = %f\n", pthis->actor.world.pos.x);
    osSyncPrintf("ZP1  = %f\n", pthis->actor.world.pos.z);

    pthis->inPaintingPos.x = (sPaintings[pthis->targetPainting].pos.x * 1.3f) + (GND_BOSSROOM_CENTER_X - 4.0f);
    pthis->inPaintingPos.y = sPaintings[pthis->targetPainting].pos.y + (GND_BOSSROOM_CENTER_Y + 33.0f);
    pthis->inPaintingPos.z = (sPaintings[pthis->targetPainting].pos.z * 1.3f) - -(GND_BOSSROOM_CENTER_Z - 10.0f);
    pthis->inPaintingVelX = (fabsf(pthis->inPaintingPos.x - pthis->actor.world.pos.x) * 2) * 0.01f;

    if (pthis->inPaintingVelX < 1.0f) {
        pthis->inPaintingVelX = 1.0f;
    }
    pthis->inPaintingVelZ = (fabsf(pthis->inPaintingPos.z - pthis->actor.world.pos.z) * 2) * 0.01f;
    if (pthis->inPaintingVelZ < 1.0f) {
        pthis->inPaintingVelZ = 1.0f;
    }

    pthis->timers[0] = 100;
    pthis->actor.scale.x = 0.002f;
    pthis->actor.scale.y = 0.002f;
    pthis->actor.scale.z = 0.001f;
    pthis->approachRate = 0.0f;

    pthis->warpColorFilterR = globalCtx->lightCtx.fogColor[0];
    pthis->warpColorFilterG = globalCtx->lightCtx.fogColor[1];
    pthis->warpColorFilterB = globalCtx->lightCtx.fogColor[2];
    pthis->warpColorFilterUnk1 = 0.0f;
    pthis->warpColorFilterUnk2 = 0.0f;
    pthis->turnRot = 0;
    pthis->turnTarget = 0;
    pthis->spawnedWarp = false;
}

void EnfHG_Approach(EnfHG* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("STANDBY !!\n");
    osSyncPrintf("XP2  = %f\n", pthis->actor.world.pos.x);
    osSyncPrintf("ZP2  = %f\n", pthis->actor.world.pos.z);
    if (pthis->actor.params == GND_REAL_BOSS) {
        pthis->hoofSfxPos.x = pthis->actor.projectedPos.x / (pthis->actor.scale.x * 100.0f);
        pthis->hoofSfxPos.y = pthis->actor.projectedPos.y / (pthis->actor.scale.x * 100.0f);
        pthis->hoofSfxPos.z = pthis->actor.projectedPos.z / (pthis->actor.scale.x * 100.0f);
        if ((pthis->gallopTimer % 8) == 0) {
            func_80078914(&pthis->hoofSfxPos, NA_SE_EV_HORSE_RUN);
        }
    }
    SkelAnime_Update(&pthis->skin.skelAnime);
    Math_ApproachF(&pthis->actor.scale.x, 0.011499999f, 1.0f, pthis->approachRate);
    Math_ApproachF(&pthis->approachRate, 0.0002f, 1.0f, 0.0000015f);
    Math_ApproachF(&pthis->actor.world.pos.y, 60.0f, 0.1f, 1.0f);
    pthis->actor.scale.y = pthis->actor.scale.x;
    if (pthis->timers[0] == 0) {
        osSyncPrintf("arg_data ------------------------------------>%d\n", pthis->actor.params);
        if (pthis->actor.params != GND_REAL_BOSS) {
            pthis->timers[0] = 140;
            pthis->actionFunc = EnfHG_Retreat;
            Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseRunningAnim, 0.0f);
            pthis->turnTarget = -0x8000;
        } else {
            pthis->actionFunc = EnfHG_Attack;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_GANON_HORSE_NEIGH);
            pthis->timers[0] = 40;
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                               pthis->actor.world.pos.x, pthis->actor.world.pos.y + 50.0f, pthis->actor.world.pos.z, 0,
                               pthis->actor.shape.rot.y + 0x8000, 0, FHGFIRE_WARP_EMERGE);
            pthis->fhgFireKillWarp = false;
        }
    }
}

void EnfHG_Attack(EnfHG* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("KABE OUT !!\n");
    pthis->bossGndInPainting = false;
    SkelAnime_Update(&pthis->skin.skelAnime);
    if (pthis->timers[0] != 0) {
        Math_ApproachF(&pthis->actor.scale.z, 0.011499999f, 1.0f, 0.0002f);
        if (pthis->timers[0] == 1) {
            pthis->bossGndSignal = FHG_RAISE_SPEAR;
            pthis->timers[1] = 50;
            Animation_MorphToPlayOnce(&pthis->skin.skelAnime, &gPhantomHorseLeapAnim, 0.0f);
        }
        Math_ApproachF(&pthis->warpColorFilterR, 255.0f, 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterG, 255.0f, 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterB, 255.0f, 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterUnk1, -60.0f, 1.0f, 5.0f);
    } else {
        Math_ApproachF(&pthis->warpColorFilterR, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterG, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterB, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
        Math_ApproachF(&pthis->warpColorFilterUnk1, 0.0f, 1.0f, 5.0f);
        if (pthis->timers[1] == 29) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_MASIC2);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_VOICE);
        }
        if (pthis->hitTimer == 0) {
            if (pthis->timers[1] == 24) {
                Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE,
                                   pthis->actor.world.pos.x, (pthis->actor.world.pos.y + 100.0f) + 25.0f,
                                   pthis->actor.world.pos.z, 0, 0, 0, FHGFIRE_LIGHTNING_STRIKE);
            }
            if (pthis->timers[1] == 45) {
                Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseAirAnim, 0.0f);
            }
            if (pthis->timers[1] == 38) {
                pthis->bossGndSignal = FHG_LIGHTNING;
            }
            if (pthis->timers[1] == 16) {
                Animation_MorphToPlayOnce(&pthis->skin.skelAnime, &gPhantomHorseLandAnim, 0.0f);
                pthis->bossGndSignal = FHG_RESET;
            }
        }
        Math_ApproachF(&pthis->actor.scale.z, 0.011499999f, 1.0f, 0.002f);
        Math_ApproachF(&pthis->actor.world.pos.x, pthis->inPaintingPos.x, 1.0f, pthis->inPaintingVelX);
        Math_ApproachF(&pthis->actor.world.pos.y, 60.0f, 0.1f, 1.0f);
        Math_ApproachF(&pthis->actor.world.pos.z, pthis->inPaintingPos.z, 1.0f, pthis->inPaintingVelZ);
    }
    if (pthis->hitTimer == 20) {
        pthis->actionFunc = EnfHG_Damage;
        pthis->spawnedWarp = false;
        Animation_Change(&pthis->skin.skelAnime, &gPhantomHorseLandAnim, -1.0f, 0.0f,
                         Animation_GetLastFrame(&gPhantomHorseLandAnim), ANIMMODE_ONCE, -5.0f);
        pthis->timers[0] = 10;
        pthis->bossGndSignal = FHG_RESET;
        pthis->damageSpeedMod = 1.0f;
    } else {
        f32 dx = pthis->actor.world.pos.x - pthis->inPaintingPos.x;
        f32 dz = pthis->actor.world.pos.z - pthis->inPaintingPos.z;
        f32 dxz = sqrtf(SQ(dx) + SQ(dz));

        if (dxz < 350.0f) {
            pthis->bossGndInPainting = true;
        }
        if ((dxz < 300.0f) && !pthis->spawnedWarp) {
            pthis->spawnedWarp = true;
            Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE, pthis->inPaintingPos.x,
                               pthis->actor.world.pos.y + 50.0f, pthis->inPaintingPos.z, 0, pthis->actor.shape.rot.y, 0,
                               FHGFIRE_WARP_RETREAT);
            pthis->fhgFireKillWarp = true;
        }
        osSyncPrintf("SPD X %f\n", pthis->inPaintingVelX);
        osSyncPrintf("SPD Z %f\n", pthis->inPaintingVelZ);
        osSyncPrintf("X=%f\n", dx);
        osSyncPrintf("Z=%f\n", dz);
        if (dxz == 0.0f) {
            pthis->timers[0] = 140;
            pthis->actionFunc = EnfHG_Retreat;
            Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseRunningAnim, 0.0f);
            pthis->bossGndSignal = FHG_RIDE;
        }
    }
}

void EnfHG_Damage(EnfHG* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;
    f32 dxz2;

    osSyncPrintf("REVISE !!\n");
    SkelAnime_Update(&pthis->skin.skelAnime);
    Math_ApproachF(&pthis->warpColorFilterR, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
    Math_ApproachF(&pthis->warpColorFilterG, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
    Math_ApproachF(&pthis->warpColorFilterB, globalCtx->lightCtx.fogColor[0], 1.0f, 10.0f);
    Math_ApproachF(&pthis->warpColorFilterUnk1, 0.0f, 1.0f, 5.0f);
    Math_ApproachF(&pthis->actor.scale.z, 0.011499999f, 1.0f, 0.002f);
    if (pthis->timers[0] != 0) {
        Math_ApproachZeroF(&pthis->damageSpeedMod, 1.0f, 0.1f);
        if (pthis->timers[0] == 1) {
            pthis->targetPainting = pthis->curPainting;
            pthis->inPaintingPos.x = (sPaintings[pthis->targetPainting].pos.x * 1.3f) + (GND_BOSSROOM_CENTER_X - 4.0f);
            pthis->inPaintingPos.y = sPaintings[pthis->targetPainting].pos.y;
            pthis->inPaintingPos.z = (sPaintings[pthis->targetPainting].pos.z * 1.3f) - -(GND_BOSSROOM_CENTER_Z - 10.0f);
        }
    } else {
        Math_ApproachF(&pthis->damageSpeedMod, 1.0f, 1.0f, 0.1f);
    }
    Math_ApproachF(&pthis->actor.world.pos.x, pthis->inPaintingPos.x, 1.0f, pthis->damageSpeedMod * pthis->inPaintingVelX);
    Math_ApproachF(&pthis->actor.world.pos.y, 60.0f, 0.1f, 1.0f);
    Math_ApproachF(&pthis->actor.world.pos.z, pthis->inPaintingPos.z, 1.0f, pthis->damageSpeedMod * pthis->inPaintingVelZ);
    dx = pthis->actor.world.pos.x - pthis->inPaintingPos.x;
    dz = pthis->actor.world.pos.z - pthis->inPaintingPos.z;
    dxz2 = sqrtf(SQ(dx) + SQ(dz));
    if ((dxz2 < 300.0f) && (!pthis->spawnedWarp)) {
        pthis->spawnedWarp = true;
        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FHG_FIRE, pthis->inPaintingPos.x,
                           pthis->actor.world.pos.y + 50.0f, pthis->inPaintingPos.z, 0, pthis->actor.shape.rot.y + 0x8000,
                           0, FHGFIRE_WARP_RETREAT);
    }
    if (dxz2 == 0.0f) {
        BossGanondrof* bossGnd = (BossGanondrof*)pthis->actor.parent;

        pthis->timers[0] = 140;
        pthis->actionFunc = EnfHG_Retreat;
        Animation_MorphToLoop(&pthis->skin.skelAnime, &gPhantomHorseRunningAnim, 0.0f);
        if (bossGnd->actor.colChkInfo.health > 24) {
            pthis->bossGndSignal = FHG_RIDE;
        } else {
            bossGnd->flyMode = GND_FLY_NEUTRAL;
        }
        pthis->turnTarget = -0x8000;
    }
}

void EnfHG_Retreat(EnfHG* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("KABE IN !!\n");
    if (pthis->turnTarget != 0) {
        Math_ApproachS(&pthis->turnRot, pthis->turnTarget, 5, 2000);
    }
    if (pthis->actor.params == GND_REAL_BOSS) {
        pthis->hoofSfxPos.x = pthis->actor.projectedPos.x / (pthis->actor.scale.x * 100.0f);
        pthis->hoofSfxPos.y = pthis->actor.projectedPos.y / (pthis->actor.scale.x * 100.0f);
        pthis->hoofSfxPos.z = pthis->actor.projectedPos.z / (pthis->actor.scale.x * 100.0f);
        if ((pthis->gallopTimer % 8) == 0) {
            func_80078914(&pthis->hoofSfxPos, NA_SE_EV_HORSE_RUN);
        }
    }
    SkelAnime_Update(&pthis->skin.skelAnime);
    Math_ApproachF(&pthis->actor.scale.z, 0.001f, 1.0f, 0.001f);
    Math_ApproachF(&pthis->actor.scale.x, 0.002f, 0.05f, 0.0001f);
    Math_ApproachF(&pthis->actor.world.pos.y, 200.0f, 0.05f, 1.0f);
    pthis->actor.scale.y = pthis->actor.scale.x;
    if ((pthis->timers[0] == 80) && (pthis->actor.params == GND_REAL_BOSS)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_FANTOM_LAUGH);
    }
    if (pthis->timers[0] == 0) {
        BossGanondrof* bossGnd = (BossGanondrof*)pthis->actor.parent;
        s16 paintingIdxReal;
        s16 paintingIdxFake;

        if (pthis->actor.params != GND_REAL_BOSS) {
            pthis->killActor = true;
            bossGnd->killActor = true;
        } else if (bossGnd->flyMode != GND_FLY_PAINTING) {
            pthis->actionFunc = EnfHG_Done;
            pthis->actor.draw = NULL;
        } else {
            paintingIdxReal = Rand_ZeroOne() * 5.99f;
            EnfHG_SetupApproach(pthis, globalCtx, paintingIdxReal);
            do {
                paintingIdxFake = Rand_ZeroOne() * 5.99f;
            } while (paintingIdxFake == paintingIdxReal);
            osSyncPrintf("ac1 = %x `````````````````````````````````````````````````\n",
                         Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_BOSS_GANONDROF,
                                            pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z,
                                            0, 0, 0, paintingIdxFake + GND_FAKE_BOSS));
        }
    }
}

void EnfHG_Done(EnfHG* pthis, GlobalContext* globalCtx) {
    pthis->bossGndInPainting = false;
}

void EnfHG_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnfHG* pthis = (EnfHG*)thisx;
    u8 i;

    if (pthis->killActor) {
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->gallopTimer++;
    pthis->bossGndInPainting = true;
    for (i = 0; i < 5; i++) {
        if (pthis->timers[i] != 0) {
            pthis->timers[i]--;
        }
    }

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->hitTimer != 0) {
        pthis->hitTimer--;
    }

    pthis->actor.focus.pos = pthis->actor.world.pos;
    pthis->actor.focus.pos.y += 70.0f;
    pthis->actor.shape.rot.y = pthis->actor.world.rot.y;

    pthis->actor.shape.yOffset = Math_SinS(pthis->hitTimer * 0x9000) * 700.0f * (pthis->hitTimer / 20.0f);
    pthis->actor.shape.rot.z = (s16)(Math_SinS(pthis->hitTimer * 0x7000) * 1500.0f) * (pthis->hitTimer / 20.0f);
}

void EnfHG_Noop(Actor* thisx, GlobalContext* globalCtx, PSkinAwb* skin) {
}

void EnfHG_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnfHG* pthis = (EnfHG*)thisx;
    BossGanondrof* bossGnd = (BossGanondrof*)pthis->actor.parent;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fhg.c", 2439);
    func_80093D18(globalCtx->state.gfxCtx);

    POLY_OPA_DISP = ((bossGnd->work[GND_INVINC_TIMER] & 4) && (bossGnd->flyMode == GND_FLY_PAINTING))
                        ? Gfx_SetFog(POLY_OPA_DISP, 255, 50, 0, 0, 900, 1099)
                        : Gfx_SetFog(POLY_OPA_DISP, (u32)pthis->warpColorFilterR, (u32)pthis->warpColorFilterG,
                                     (u32)pthis->warpColorFilterB, 0, (s32)pthis->warpColorFilterUnk1 + 995,
                                     (s32)pthis->warpColorFilterUnk2 + 1000);
    func_800A6330(&pthis->actor, globalCtx, &pthis->skin, EnfHG_Noop, 0x23);
    POLY_OPA_DISP = Gameplay_SetFog(globalCtx, POLY_OPA_DISP);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fhg.c", 2480);
}

void EnfHG_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    audioVec_43 = { 0.0f, 0.0f, 50.0f };

    En_fHG_InitVars = {
        ACTOR_EN_FHG,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_FHG,
        sizeof(EnfHG),
        (ActorFunc)EnfHG_Init,
        (ActorFunc)EnfHG_Destroy,
        (ActorFunc)EnfHG_Update,
        (ActorFunc)EnfHG_Draw,
        (ActorFunc)EnfHG_Reset,
    };

}

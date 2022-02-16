#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_SKJ_Z_EN_SKJ_C
#include "actor_common.h"
#include "z_en_skj.h"
#include "overlays/actors/ovl_En_Skjneedle/z_en_skjneedle.h"
#include "objects/object_skj/object_skj.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_en_item00.h"
#include "def/z_face_reaction.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnSkj_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnSkj_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Update(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnSkj_SariasSongShortStumpUpdate(Actor* thisx, GlobalContext* globalCtx);
void EnSkj_OcarinaMinigameShortStumpUpdate(Actor* thisx, GlobalContext* globalCtx);

void func_80AFF2A0(EnSkj* pthis);
void func_80AFF334(EnSkj* pthis);

void EnSkj_CalculateCenter(EnSkj* pthis);
void EnSkj_OcarinaGameSetupWaitForPlayer(EnSkj* pthis);
void EnSkj_SetupResetFight(EnSkj* pthis);
void EnSkj_SetupLeaveOcarinaGame(EnSkj* pthis);
void EnSkj_SetupPlayOcarinaGame(EnSkj* pthis);
void EnSkj_Backflip(EnSkj* pthis);
void EnSkj_SetupNeedleRecover(EnSkj* pthis);
void EnSkj_SetupSpawnDeathEffect(EnSkj* pthis);
void EnSkj_SetupStand(EnSkj* pthis);
void EnSkj_SetupWaitForSong(EnSkj* pthis);
void EnSkj_SetupTalk(EnSkj* pthis);
void EnSkj_SetupMaskTrade(EnSkj* pthis);
void EnSkj_SetupWrongSong(EnSkj* pthis);
void EnSkj_SetupAfterSong(EnSkj* pthis);
void func_80AFFE24(EnSkj* pthis);
void EnSkj_SetupPostSariasSong(EnSkj* pthis);
void EnSkj_JumpFromStump(EnSkj* pthis);
void EnSkj_SetupWaitForLandAnimFinish(EnSkj* pthis);
void EnSkj_SetupWalkToPlayer(EnSkj* pthis);
void EnSkj_SetupWaitForMaskTextClear(EnSkj* pthis);
void EnSkj_SetupWaitForTextClear(EnSkj* pthis);
void EnSkj_SetupDie(EnSkj* pthis);
void func_80AFF1F0(EnSkj* pthis);
void EnSkj_OfferNextRound(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SetupAskForMask(EnSkj* pthis, GlobalContext* globalCtx);
f32 EnSkj_GetItemXzRange(EnSkj* pthis);
s32 EnSkj_CollisionCheck(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SetupTakeMask(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_TurnPlayer(EnSkj* pthis, Player* player);

void EnSkj_SetupWaitForOcarina(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_StartOcarinaMinigame(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForOcarina(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForPlayback(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_FailedMiniGame(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WonOcarinaMiniGame(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitToGiveReward(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_GiveOcarinaGameReward(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_FinishOcarinaGameRound(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForNextRound(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForOfferResponse(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SetupWaitForOcarina(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_CleanupOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx);

void EnSkj_Fade(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitToShootNeedle(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SariasSongKidIdle(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForDeathAnim(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_PickNextFightAction(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForLandAnim(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_ResetFight(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_Fight(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_NeedleRecover(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SpawnDeathEffect(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitInRange(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForSong(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_AfterSong(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SariaSongTalk(EnSkj* pthis, GlobalContext* globalCtx);
void func_80AFFE44(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_ChangeModeAfterSong(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_StartMaskTrade(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForLanding(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForLandAnimFinish(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WalkToPlayer(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_AskForMask(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_TakeMask(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WaitForMaskTextClear(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_WrongSong(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_SariasSongWaitForTextClear(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_OcarinaGameWaitForPlayer(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_OcarinaGameIdle(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_PlayOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx);
void EnSkj_LeaveOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx);

void EnSkj_SpawnBlood(GlobalContext* globalCtx, Vec3f* pos);

void EnSkj_SetupWaitInRange(EnSkj* pthis);

#define songFailTimer multiuseTimer
#define battleExitTimer multiuseTimer


static unkSkjStruct sSmallStumpSkullKid = { 0, NULL };
static unkSkjStruct sOcarinaMinigameSkullKids[] = { { 0, NULL }, { 0, NULL } };

ActorInit En_Skj_InitVars = {
    ACTOR_EN_SKJ,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_SKJ,
    sizeof(EnSkj),
    (ActorFunc)EnSkj_Init,
    (ActorFunc)EnSkj_Destroy,
    (ActorFunc)EnSkj_Update,
    (ActorFunc)EnSkj_Draw,
    (ActorFunc)EnSkj_Reset,
};

static ColliderCylinderInitType1 D_80B01678 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x0, 0x08 },
        { 0xFFCFFFFF, 0x0, 0x0 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_ON,
    },
    { 8, 48, 0, { 0, 0, 0 } },
};

static DamageTable sDamageTable = {
    /* Deku nut      */ DMG_ENTRY(0, 0x0),
    /* Deku stick    */ DMG_ENTRY(0, 0x0),
    /* Slingshot     */ DMG_ENTRY(0, 0x0),
    /* Explosive     */ DMG_ENTRY(0, 0x0),
    /* Boomerang     */ DMG_ENTRY(0, 0x0),
    /* Normal arrow  */ DMG_ENTRY(0, 0x0),
    /* Hammer swing  */ DMG_ENTRY(2, 0x0),
    /* Hookshot      */ DMG_ENTRY(0, 0x0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0xF),
    /* Master sword  */ DMG_ENTRY(2, 0xF),
    /* Giant's Knife */ DMG_ENTRY(4, 0xF),
    /* Fire arrow    */ DMG_ENTRY(0, 0x0),
    /* Ice arrow     */ DMG_ENTRY(0, 0x0),
    /* Light arrow   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
    /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
    /* Fire magic    */ DMG_ENTRY(0, 0x0),
    /* Ice magic     */ DMG_ENTRY(0, 0x0),
    /* Light magic   */ DMG_ENTRY(0, 0x0),
    /* Shield        */ DMG_ENTRY(0, 0x0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
    /* Giant spin    */ DMG_ENTRY(4, 0x0),
    /* Master spin   */ DMG_ENTRY(2, 0x0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
    /* Giant jump    */ DMG_ENTRY(8, 0x0),
    /* Master jump   */ DMG_ENTRY(4, 0x0),
    /* Unknown 1     */ DMG_ENTRY(0, 0x0),
    /* Unblockable   */ DMG_ENTRY(0, 0x0),
    /* Hammer jump   */ DMG_ENTRY(0, 0x0),
    /* Unknown 2     */ DMG_ENTRY(0, 0x0),
};

static s32 sOcarinaGameRewards[] = {
    GI_RUPEE_GREEN,
    GI_RUPEE_BLUE,
    GI_HEART_PIECE,
    GI_RUPEE_RED,
};

static SkullkidAnimationEntry sSkullKidAnimations[] = {
    { &gSkullKidBackflipAnim, ANIMMODE_ONCE, 0.0f },
    { &gSkullKidShootNeedleAnim, ANIMMODE_ONCE, 0.0f },
    { &gSkullKidPlayFluteAnim, ANIMMODE_LOOP, 0.0f },
    { &gSkullKidDieAnim, ANIMMODE_ONCE, 0.0f },
    { &gSkullKidHitAnim, ANIMMODE_ONCE, 0.0f },
    { &gSkullKidLandAnim, ANIMMODE_ONCE, 0.0f },
    { &gSkullKidLookLeftAndRightAnim, ANIMMODE_LOOP, 0.0f },
    { &gSkullKidFightingStanceAnim, ANIMMODE_LOOP, 0.0f },
    { &gSkullKidWalkToPlayerAnim, ANIMMODE_LOOP, 0.0f },
    { &gSkullKidWaitAnim, ANIMMODE_LOOP, 0.0f },
};

static EnSkjActionFunc sActionFuncs[] = {
    EnSkj_Fade,
    EnSkj_WaitToShootNeedle,
    EnSkj_SariasSongKidIdle,
    EnSkj_WaitForDeathAnim,
    EnSkj_PickNextFightAction,
    EnSkj_WaitForLandAnim,
    EnSkj_ResetFight,
    EnSkj_Fight,
    EnSkj_NeedleRecover,
    EnSkj_SpawnDeathEffect,
    EnSkj_WaitInRange,
    EnSkj_WaitForSong,
    EnSkj_AfterSong,
    EnSkj_SariaSongTalk,
    func_80AFFE44,
    EnSkj_ChangeModeAfterSong,
    EnSkj_StartMaskTrade,
    EnSkj_WaitForLanding,
    EnSkj_WaitForLandAnimFinish,
    EnSkj_WalkToPlayer,
    EnSkj_AskForMask,
    EnSkj_TakeMask,
    EnSkj_WaitForMaskTextClear,
    EnSkj_WrongSong,
    EnSkj_SariasSongWaitForTextClear,
    EnSkj_OcarinaGameWaitForPlayer,
    EnSkj_OcarinaGameIdle,
    EnSkj_PlayOcarinaGame,
    EnSkj_LeaveOcarinaGame,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

static s32 D_80B01EA0; // gets set if ACTOR_FLAG_8 is set

void EnSkj_ChangeAnim(EnSkj* pthis, u8 animIndex) {
    f32 endFrame = Animation_GetLastFrame(sSkullKidAnimations[animIndex].animation);

    pthis->animIndex = animIndex;
    Animation_Change(&pthis->skelAnime, sSkullKidAnimations[animIndex].animation, 1.0f, 0.0f, endFrame,
                     sSkullKidAnimations[animIndex].mode, sSkullKidAnimations[animIndex].morphFrames);
}

void EnSkj_SetupAction(EnSkj* pthis, u8 action) {
    pthis->action = action;
    pthis->actionFunc = sActionFuncs[action];

    switch (action) {
        case SKJ_ACTION_FADE:
        case SKJ_ACTION_WAIT_FOR_DEATH_ANIM:
        case SKJ_ACTION_PICK_NEXT_FIHGT_ACTION:
        case SKJ_ACTION_SPAWN_DEATH_EFFECT:
        case SKJ_ACTION_SARIA_SONG_START_TRADE:
        case SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING:
        case SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING_ANIM:
        case SKJ_ACTION_SARIA_SONG_WALK_TO_PLAYER:
        case SKJ_ACTION_SARIA_SONG_ASK_FOR_MASK:
        case SKJ_ACTION_SARIA_SONG_TAKE_MASK:
        case SKJ_ACTION_SARIA_SONG_WAIT_MASK_TEXT:
        case SKJ_ACTION_SARIA_SONG_WRONG_SONG:
        case SKJ_ACTION_SARIA_SONG_WAIT_FOR_TEXT:
        case SKJ_ACTION_OCARINA_GAME_WAIT_FOR_PLAYER:
        case SKJ_ACTION_OCARINA_GAME_IDLE:
        case SKJ_ACTION_OCARINA_GAME_PLAY:
        case SKJ_ACTION_OCARINA_GAME_LEAVE:
            pthis->unk_2D3 = 0;
            break;
        default:
            pthis->unk_2D3 = 1;
            break;
    }
}

void EnSkj_CalculateCenter(EnSkj* pthis) {
    Vec3f mult;

    mult.x = 0.0f;
    mult.y = 0.0f;
    mult.z = 120.0f;

    Matrix_RotateY((pthis->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_NEW);
    Matrix_MultVec3f(&mult, &pthis->center);

    pthis->center.x += pthis->actor.world.pos.x;
    pthis->center.z += pthis->actor.world.pos.z;
}

void EnSkj_SetNaviId(EnSkj* pthis) {
    switch (pthis->actor.params) {
        case 0:
            if (gSaveContext.itemGetInf[3] & 0x200) {
                pthis->actor.naviEnemyId = 0x41; // Skull kid with skull mask
            } else if (gSaveContext.itemGetInf[1] & 0x40) {
                pthis->actor.naviEnemyId = 0x40; // Skull kid after Saria's song but no mask
            } else {
                pthis->actor.naviEnemyId = 0x3F; // No Sarias song no skull mask
            }
            break;

        case 1:
        case 2:
            pthis->actor.naviEnemyId = 0x3F;
            break;

        default:
            pthis->actor.naviEnemyId = 0x36; // Skull kid as adult
            break;
    }
}

void EnSkj_Init(Actor* thisx, GlobalContext* globalCtx2) {
    s16 type = (thisx->params >> 0xA) & 0x3F;
    EnSkj* pthis = (EnSkj*)thisx;
    GlobalContext* globalCtx = globalCtx2;
    s32 pad;
    Player* player;

    Actor_ProcessInitChain(thisx, sInitChain);
    switch (type) {
        case 5: // Invisible on the small stump (sarias song))
            sSmallStumpSkullKid.unk0 = 1;
            sSmallStumpSkullKid.skullkid = (EnSkj*)thisx;
            pthis->actor.destroy = NULL;
            pthis->actor.draw = NULL;
            pthis->actor.update = EnSkj_SariasSongShortStumpUpdate;
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
            pthis->actor.flags |= 0;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_PROP);
            break;

        case 6: // Invisible on the short stump (ocarina game)
            sSmallStumpSkullKid.unk0 = 1;
            sSmallStumpSkullKid.skullkid = (EnSkj*)thisx;
            pthis->actor.destroy = NULL;
            pthis->actor.draw = NULL;
            pthis->actor.update = EnSkj_OcarinaMinigameShortStumpUpdate;
            pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
            pthis->actor.flags |= 0;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_PROP);
            pthis->actor.focus.pos.x = 1230.0f;
            pthis->actor.focus.pos.y = -90.0f;
            pthis->actor.focus.pos.z = 450.0f;
            pthis->actionFunc = EnSkj_SetupWaitForOcarina;
            break;

        default:
            pthis->actor.params = type;
            if (((pthis->actor.params != 0) && (pthis->actor.params != 1)) && (pthis->actor.params != 2)) {
                if (INV_CONTENT(ITEM_TRADE_ADULT) < ITEM_SAW) {
                    Actor_Kill(&pthis->actor);
                    return;
                }
            }

            EnSkj_SetNaviId(pthis);
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gSkullKidSkel, &gSkullKidPlayFluteAnim, pthis->jointTable,
                               pthis->morphTable, 19);
            if ((type >= 0) && (type < 3)) {
                pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_2);
                pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
                Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_NPC);
            }

            if ((type < 0) || (type >= 7)) {
                pthis->actor.flags &= ~ACTOR_FLAG_25;
            }

            if ((type > 0) && (type < 3)) {
                pthis->actor.targetMode = 7;
                pthis->posCopy = pthis->actor.world.pos;
                sOcarinaMinigameSkullKids[type - 1].unk0 = 1;
                sOcarinaMinigameSkullKids[type - 1].skullkid = pthis;
                pthis->minigameState = 0;
                pthis->alpha = 0;
                EnSkj_OcarinaGameSetupWaitForPlayer(pthis);
            } else {
                pthis->alpha = 255;
                EnSkj_SetupResetFight(pthis);
            }

            pthis->actor.colChkInfo.damageTable = &sDamageTable;
            pthis->actor.colChkInfo.health = 10;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &D_80B01678);
            ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);
            Actor_SetScale(thisx, 0.01f);
            pthis->actor.textId = pthis->textId = 0;
            pthis->multiuseTimer = 0;
            pthis->backfilpFlag = 0;
            pthis->needlesToShoot = 3;
            pthis->hitsUntilDodge = 3;
            pthis->actor.speedXZ = 0.0f;
            pthis->actor.velocity.y = 0.0f;
            pthis->actor.gravity = -1.0f;
            EnSkj_CalculateCenter(pthis);

            player = GET_PLAYER(globalCtx);
            osSyncPrintf("Player_X : %f\n", player->actor.world.pos.x);
            osSyncPrintf("Player_Z : %f\n", player->actor.world.pos.z);
            osSyncPrintf("World_X  : %f\n", pthis->actor.world.pos.x);
            osSyncPrintf("World_Z  : %f\n", pthis->actor.world.pos.z);
            osSyncPrintf("Center_X : %f\n", pthis->center.x);
            osSyncPrintf("Center_Z : %f\n\n", pthis->center.z);

            break;
    }
}

void EnSkj_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSkj* pthis = (EnSkj*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

s32 EnSkj_RangeCheck(Player* player, EnSkj* pthis) {
    f32 xDiff = player->actor.world.pos.x - pthis->actor.world.pos.x;
    f32 zDiff = player->actor.world.pos.z - pthis->actor.world.pos.z;
    f32 yDiff = player->actor.world.pos.y - pthis->actor.world.pos.y;

    return (SQ(xDiff) + SQ(zDiff) <= 676.0f) && (yDiff >= 0.0f);
}

f32 EnSkj_GetItemXzRange(EnSkj* pthis) {
    EnSkj* temp_v0;
    f32 zDiff;
    f32 xDiff;

    temp_v0 = sSmallStumpSkullKid.skullkid;
    xDiff = temp_v0->actor.world.pos.x - pthis->actor.world.pos.x;
    zDiff = temp_v0->actor.world.pos.z - pthis->actor.world.pos.z;
    return sqrtf(SQ(xDiff) + SQ(zDiff)) + 26.0f;
}

f32 EnSkj_GetItemYRange(EnSkj* pthis) {
    return fabsf(sSmallStumpSkullKid.skullkid->actor.world.pos.y - pthis->actor.world.pos.y) + 10.0f;
}

s32 EnSkj_ShootNeedle(EnSkj* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Vec3f pos;
    Vec3f pos2;
    EnSkjneedle* needle;

    pos.x = 1.5f;
    pos.y = 0.0f;
    pos.z = 40.0f;

    Matrix_RotateY((pthis->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_NEW);
    Matrix_MultVec3f(&pos, &pos2);

    pos2.x += pthis->actor.world.pos.x;
    pos2.z += pthis->actor.world.pos.z;
    pos2.y = pthis->actor.world.pos.y + 27.0f;

    needle = (EnSkjneedle*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_SKJNEEDLE, pos2.x, pos2.y, pos2.z,
                                       pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 0);
    if (needle != NULL) {
        needle->killTimer = 100;
        needle->actor.speedXZ = 24.0f;
        return 1;
    }
    return 0;
}

void EnSkj_SpawnBlood(GlobalContext* globalCtx, Vec3f* pos) {
    EffectSparkInit effect;
    s32 sp20;

    effect.position.x = pos->x;
    effect.position.y = pos->y;
    effect.position.z = pos->z;
    effect.uDiv = 5;
    effect.vDiv = 5;

    effect.colorStart[0].r = 0;
    effect.colorStart[0].g = 0;
    effect.colorStart[0].b = 128;
    effect.colorStart[0].a = 255;

    effect.colorStart[1].r = 0;
    effect.colorStart[1].g = 0;
    effect.colorStart[1].b = 128;
    effect.colorStart[1].a = 255;

    effect.colorStart[2].r = 0;
    effect.colorStart[2].g = 0;
    effect.colorStart[2].b = 128;
    effect.colorStart[2].a = 255;

    effect.colorStart[3].r = 0;
    effect.colorStart[3].g = 0;
    effect.colorStart[3].b = 128;
    effect.colorStart[3].a = 255;

    effect.colorEnd[0].r = 0;
    effect.colorEnd[0].g = 0;
    effect.colorEnd[0].b = 32;
    effect.colorEnd[0].a = 0;

    effect.colorEnd[1].r = 0;
    effect.colorEnd[1].g = 0;
    effect.colorEnd[1].b = 32;
    effect.colorEnd[1].a = 0;

    effect.colorEnd[2].r = 0;
    effect.colorEnd[2].g = 0;
    effect.colorEnd[2].b = 64;
    effect.colorEnd[2].a = 0;

    effect.colorEnd[3].r = 0;
    effect.colorEnd[3].g = 0;
    effect.colorEnd[3].b = 64;
    effect.colorEnd[3].a = 0;

    effect.speed = 8.0f;
    effect.gravity = -1.0f;

    effect.timer = 0;
    effect.duration = 8;

    Effect_Add(globalCtx, &sp20, EFFECT_SPARK, 0, 1, &effect);
}

s32 EnSkj_CollisionCheck(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;
    Vec3f effectPos;

    if (!((pthis->unk_2D3 == 0) || (D_80B01EA0 != 0) || !(pthis->collider.base.acFlags & AC_HIT))) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        if (pthis->actor.colChkInfo.damageEffect != 0) {
            if (pthis->actor.colChkInfo.damageEffect == 0xF) {
                effectPos.x = pthis->collider.info.bumper.hitPos.x;
                effectPos.y = pthis->collider.info.bumper.hitPos.y;
                effectPos.z = pthis->collider.info.bumper.hitPos.z;

                EnSkj_SpawnBlood(globalCtx, &effectPos);
                EffectSsHitMark_SpawnFixedScale(globalCtx, 1, &effectPos);

                yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y;
                if ((pthis->action == 2) || (pthis->action == 6)) {
                    if ((yawDiff > 0x6000) || (yawDiff < -0x6000)) {
                        Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);
                        EnSkj_SetupDie(pthis);
                        return 1;
                    }
                }

                Actor_ApplyDamage(&pthis->actor);
                Actor_SetColorFilter(&pthis->actor, 0x4000, 0xFF, 0, 8);

                if (pthis->actor.colChkInfo.health != 0) {
                    if (pthis->hitsUntilDodge != 0) {
                        pthis->hitsUntilDodge--;
                    }
                    if (pthis->dodgeResetTimer == 0) {
                        pthis->dodgeResetTimer = 60;
                    }
                    func_80AFF1F0(pthis);
                    return 1;
                }
                EnSkj_SetupDie(pthis);
                return 1;
            }
        } else {
            pthis->backfilpFlag = 1;
            EnSkj_Backflip(pthis);
            return 1;
        }
    }
    return 0;
}

s32 func_80AFEDF8(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 yawDiff;

    if (pthis->actor.xzDistToPlayer < pthis->unk_2EC) {
        pthis = pthis;
        if (func_8002DDE4(globalCtx) != 0) {
            return 1;
        }
    }

    yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.world.rot.y;

    if ((yawDiff < pthis->unk_2C8) && (-pthis->unk_2C8 < yawDiff)) {
        return 1;
    }

    return 0;
}

void EnSkj_Backflip(EnSkj* pthis) {
    pthis->actor.velocity.y = 8.0f;
    pthis->actor.speedXZ = -8.0f;

    EnSkj_ChangeAnim(pthis, SKJ_ANIM_BACKFLIP);
    EnSkj_SetupAction(pthis, SKJ_ACTION_FADE);
}

void EnSkj_Fade(EnSkj* pthis, GlobalContext* globalCtx) {
    u32 alpha = pthis->alpha;

    if (pthis->unk_2D6 == 2) {
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_00;
        pthis->unk_2D6 = 0;
    }

    alpha -= 20;

    if (pthis->backfilpFlag != 0) {
        if (alpha > 255) {
            alpha = 0;
        }

        pthis->alpha = alpha;
        pthis->actor.shape.shadowAlpha = alpha;
    }

    if (pthis->actor.velocity.y <= 0.0f) {
        if (pthis->actor.bgCheckFlags & 2) {
            pthis->actor.bgCheckFlags &= ~2;
            func_80AFF2A0(pthis);
        }
    }
}

void EnSkj_SetupWaitToShootNeedle(EnSkj* pthis) {
    pthis->needlesToShoot = 3;
    pthis->needleShootTimer = 0;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_SHOOT_NEEDLE);
    EnSkj_SetupAction(pthis, SKJ_ACTION_WAIT_TO_SHOOT_NEEDLE);
}

void EnSkj_WaitToShootNeedle(EnSkj* pthis, GlobalContext* globalCtx) {
    u8 val;
    s16 lastFrame = Animation_GetLastFrame(&gSkullKidShootNeedleAnim);

    if ((pthis->skelAnime.curFrame == lastFrame) && (pthis->needleShootTimer == 0)) {
        val = pthis->needlesToShoot;
        if (pthis->needlesToShoot != 0) {
            EnSkj_ShootNeedle(pthis, globalCtx);
            pthis->needleShootTimer = 4;
            val--;
            pthis->needlesToShoot = val;

        } else {
            EnSkj_SetupNeedleRecover(pthis);
        }
    }
}

void EnSkj_SetupResetFight(EnSkj* pthis) {
    pthis->unk_2C8 = 0xAAA;
    pthis->unk_2EC = 200.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_PLAY_FLUTE);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_IDLE);
}

void EnSkj_SariasSongKidIdle(EnSkj* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.params == 0) {
        if (!(gSaveContext.itemGetInf[1] & 0x40) && (pthis->actor.xzDistToPlayer < 200.0f)) {
            pthis->backfilpFlag = 1;
            EnSkj_Backflip(pthis);
        } else if (sSmallStumpSkullKid.unk0 != 0) {
            Player* player = GET_PLAYER(globalCtx);
            if (EnSkj_RangeCheck(player, sSmallStumpSkullKid.skullkid)) {
                EnSkj_SetupWaitInRange(pthis);
                player->stateFlags2 |= 0x800000;
                player->unk_6A8 = &sSmallStumpSkullKid.skullkid->actor;
            }
        }
    } else {
        if (func_80AFEDF8(pthis, globalCtx) != 0) {
            func_80AFF334(pthis);
        }
    }
}

void EnSkj_SetupDie(EnSkj* pthis) {
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_DIE);
    EnSkj_SetupAction(pthis, SKJ_ACTION_WAIT_FOR_DEATH_ANIM);
}

void EnSkj_WaitForDeathAnim(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 lastFrame = Animation_GetLastFrame(&gSkullKidDieAnim);

    if (pthis->skelAnime.curFrame == lastFrame) {
        EnSkj_SetupSpawnDeathEffect(pthis);
    }
}

void func_80AFF1F0(EnSkj* pthis) {
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_HIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_PICK_NEXT_FIHGT_ACTION);
}

void EnSkj_PickNextFightAction(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 lastFrame = Animation_GetLastFrame(&gSkullKidHitAnim);

    if (pthis->skelAnime.curFrame == lastFrame) {
        if (pthis->hitsUntilDodge == 0) {
            pthis->hitsUntilDodge = 3;
            EnSkj_Backflip(pthis);
        } else {
            EnSkj_SetupStand(pthis);
        }
    }
}

void func_80AFF2A0(EnSkj* pthis) {
    EnSkj_CalculateCenter(pthis);
    pthis->actor.speedXZ = 0.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_LAND);
    EnSkj_SetupAction(pthis, SKJ_ACTION_WAIT_FOR_LAND_ANIM);
}

void EnSkj_WaitForLandAnim(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 lastFrame = Animation_GetLastFrame(&gSkullKidLandAnim);

    if (pthis->skelAnime.curFrame == lastFrame) {
        EnSkj_SetupStand(pthis);
    }
}

void func_80AFF334(EnSkj* pthis) {
    pthis->unk_2C8 = 0x2000;
    pthis->battleExitTimer = 400;
    pthis->unk_2EC = 600.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_LOOK_LEFT_RIGHT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_RESET_FIGHT);
}

void EnSkj_ResetFight(EnSkj* pthis, GlobalContext* globalCtx) {
    if (pthis->battleExitTimer == 0) {
        EnSkj_SetupResetFight(pthis);
    } else if (func_80AFEDF8(pthis, globalCtx) != 0) {
        pthis->battleExitTimer = 600;
        EnSkj_SetupStand(pthis);
    }
}

void EnSkj_SetupStand(EnSkj* pthis) {
    pthis->needleShootTimer = 60;
    pthis->unk_2C8 = 0x2000;
    pthis->unk_2F0 = 0.0f;
    pthis->unk_2EC = 600.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_FIGHTING_STANCE);
    EnSkj_SetupAction(pthis, SKJ_ACTION_FIGHT);
}

void EnSkj_Fight(EnSkj* pthis, GlobalContext* globalCtx) {
    Vec3f pos1;
    Vec3f pos2;
    s32 pad[3];
    f32 prevPosX;
    f32 prevPosZ;
    f32 phi_f14;
    s16 yawDistToPlayer;

    if (pthis->needleShootTimer == 0) {
        EnSkj_SetupWaitToShootNeedle(pthis);
    } else if (pthis->battleExitTimer != 0) {
        yawDistToPlayer =
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 5, pthis->unk_2F0, 0);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
        Math_ApproachF(&pthis->unk_2F0, 2000.0f, 1.0f, 200.0f);

        pos1.x = 0.0f;
        pos1.y = 0.0f;
        pos1.z = -120.0f;

        Matrix_RotateY((pthis->actor.shape.rot.y / 32768.0f) * M_PI, MTXMODE_NEW);
        Matrix_MultVec3f(&pos1, &pos2);
        prevPosX = pthis->actor.world.pos.x;
        prevPosZ = pthis->actor.world.pos.z;
        if (1) {}
        pthis->actor.world.pos.x = pthis->center.x + pos2.x;
        pthis->actor.world.pos.z = pthis->center.z + pos2.z;

        phi_f14 = sqrtf(SQ(pthis->actor.world.pos.x - prevPosX) + SQ(pthis->actor.world.pos.z - prevPosZ));
        phi_f14 = CLAMP_MAX(phi_f14, 10.0f);
        phi_f14 /= 10.0f;

        pthis->skelAnime.playSpeed = (yawDistToPlayer < 0) ? -(1.0f + phi_f14) : (1.0f + phi_f14);

    } else if (func_80AFEDF8(pthis, globalCtx) != 0) {
        pthis->backfilpFlag = 1;
        EnSkj_Backflip(pthis);
    } else {
        EnSkj_SetupResetFight(pthis);
    }
}

void EnSkj_SetupNeedleRecover(EnSkj* pthis) {
    Animation_Reverse(&pthis->skelAnime);
    EnSkj_SetupAction(pthis, SKJ_ACTION_NEEDLE_RECOVER);
}

void EnSkj_NeedleRecover(EnSkj* pthis, GlobalContext* globalCtx) {
    if (pthis->skelAnime.curFrame == 0.0f) {
        EnSkj_SetupStand(pthis);
    }
}

void EnSkj_SetupSpawnDeathEffect(EnSkj* pthis) {
    pthis->backfilpFlag = 1;
    EnSkj_SetupAction(pthis, SKJ_ACTION_SPAWN_DEATH_EFFECT);
}

void EnSkj_SpawnDeathEffect(EnSkj* pthis, GlobalContext* globalCtx) {
    Vec3f effectPos;
    Vec3f effectVel;
    Vec3f effectAccel;
    u32 phi_v0;

    phi_v0 = pthis->alpha - 4;

    if (phi_v0 > 255) {
        phi_v0 = 0;
    }
    pthis->alpha = phi_v0;
    pthis->actor.shape.shadowAlpha = phi_v0;

    effectPos.x = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.x;
    effectPos.y = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.y;
    effectPos.z = Rand_CenteredFloat(30.0f) + pthis->actor.world.pos.z;

    effectAccel.z = 0.0f;
    effectAccel.y = 0.0f;
    effectAccel.x = 0.0f;

    effectVel.z = 0.0f;
    effectVel.y = 0.0f;
    effectVel.x = 0.0f;

    EffectSsDeadDb_Spawn(globalCtx, &effectPos, &effectVel, &effectAccel, 100, 10, 255, 255, 255, 255, 0, 0, 255, 1, 9,
                         1);
}

void EnSkj_SetupWaitInRange(EnSkj* pthis) {
    pthis->textId = 0x10BC;

    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_IN_RANGE);
}

void EnSkj_WaitInRange(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    // When link pulls out the Ocarina center him on the stump
    // Link was probably supposed to be pointed towards skull kid as well
    if (player->stateFlags2 & 0x1000000) {
        player->stateFlags2 |= 0x2000000;
        player->unk_6A8 = &sSmallStumpSkullKid.skullkid->actor;
        player->actor.world.pos.x = sSmallStumpSkullKid.skullkid->actor.world.pos.x;
        player->actor.world.pos.y = sSmallStumpSkullKid.skullkid->actor.world.pos.y;
        player->actor.world.pos.z = sSmallStumpSkullKid.skullkid->actor.world.pos.z;
        EnSkj_TurnPlayer(sSmallStumpSkullKid.skullkid, player);
        func_8010BD88(globalCtx, OCARINA_ACTION_CHECK_SARIA);
        EnSkj_SetupWaitForSong(pthis);
    } else if (D_80B01EA0 != 0) {
        player->actor.world.pos.x = sSmallStumpSkullKid.skullkid->actor.world.pos.x;
        player->actor.world.pos.y = sSmallStumpSkullKid.skullkid->actor.world.pos.y;
        player->actor.world.pos.z = sSmallStumpSkullKid.skullkid->actor.world.pos.z;
        if ((Player_GetMask(globalCtx) == PLAYER_MASK_SKULL) && !(gSaveContext.itemGetInf[3] & 0x200)) {
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
            EnSkj_SetupMaskTrade(pthis);
        } else {
            EnSkj_SetupTalk(pthis);
        }
    } else if (!EnSkj_RangeCheck(player, sSmallStumpSkullKid.skullkid)) {
        EnSkj_SetupResetFight(pthis);
    } else {
        player->stateFlags2 |= 0x800000;
        if (gSaveContext.itemGetInf[1] & 0x40) {
            if (gSaveContext.itemGetInf[3] & 0x200) {
                pthis->textId = Text_GetFaceReaction(globalCtx, 0x15);
                if (pthis->textId == 0) {
                    pthis->textId = 0x1020;
                }
            } else if (Player_GetMask(globalCtx) == PLAYER_MASK_NONE) {
                pthis->textId = 0x10BC;
            } else if (Player_GetMask(globalCtx) == PLAYER_MASK_SKULL) {
                pthis->textId = 0x101B;
            } else {
                pthis->textId = Text_GetFaceReaction(globalCtx, 0x15);
            }
            func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
        }
    }
}

void EnSkj_SetupWaitForSong(EnSkj* pthis) {
    pthis->unk_2D6 = 0;
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_FOR_SONG);
}

void EnSkj_WaitForSong(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    // Played a song thats not Saria's song
    if (!(gSaveContext.itemGetInf[1] & 0x40) && ((globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_FAIL) ||
                                                 (globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_FAIL_NO_TEXT))) {
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        Message_CloseTextbox(globalCtx);
        player->unk_6A8 = &pthis->actor;
        func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
        EnSkj_SetupWrongSong(pthis);
    } else {
        if ((globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_CORRECT_PLAYBACK) && (pthis->unk_2D6 == 0)) {
            pthis->unk_2D6 = 1;
            EnSkj_ChangeAnim(pthis, SKJ_ANIM_PLAY_FLUTE);
        } else if ((pthis->unk_2D6 != 0) && (globalCtx->msgCtx.msgMode == MSGMODE_SONG_DEMONSTRATION_DONE)) {
            pthis->unk_2D6 = 0;
            EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
        }
        if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
            globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_00;
            pthis->unk_2D6 = 0;
            EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
            EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_IN_RANGE);
        } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) {
            if (!(gSaveContext.itemGetInf[1] & 0x40)) {
                // Saria's song has been played for the first titme
                globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                func_80078884(NA_SE_SY_CORRECT_CHIME);
                player->unk_6A8 = &pthis->actor;
                func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
                pthis->textId = 0x10BB;
                EnSkj_SetupAfterSong(pthis);
            } else {
                globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_05;
            }
        } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_02) {
            player->stateFlags2 &= ~0x1000000;
            Actor_Kill(&pthis->actor);
        } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_01) {
            player->stateFlags2 |= 0x800000;
        } else {
            if (globalCtx->msgCtx.ocarinaMode >= OCARINA_MODE_05) {
                gSaveContext.sunsSongState = 0;
                if (gSaveContext.itemGetInf[1] & 0x40) {
                    globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                    player->unk_6A8 = &pthis->actor;
                    func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
                    pthis->textId = 0x10BD;
                    EnSkj_SetupAfterSong(pthis);
                } else {
                    globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                    player->unk_6A8 = &pthis->actor;
                    func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
                    EnSkj_SetupWrongSong(pthis);
                }
            }
        }
    }
}

void EnSkj_SetupAfterSong(EnSkj* pthis) {
    pthis->unk_2D6 = 0;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_AFTER_SONG);
}

void EnSkj_AfterSong(EnSkj* pthis, GlobalContext* globalCtx) {
    if (D_80B01EA0 != 0) {
        EnSkj_SetupTalk(pthis);
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
    }
}

void EnSkj_SetupTalk(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_TALK);
}

void EnSkj_SariaSongTalk(EnSkj* pthis, GlobalContext* globalCtx) {
    s32 pad;

    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        if (gSaveContext.itemGetInf[1] & 0x40) {
            EnSkj_SetupWaitInRange(pthis);
        } else {
            func_80AFFE24(pthis);
            func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, EnSkj_GetItemXzRange(pthis),
                          EnSkj_GetItemYRange(pthis));
        }
    }
}

void func_80AFFE24(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_UNK14);
}

void func_80AFFE44(EnSkj* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        EnSkj_SetupPostSariasSong(pthis);
    } else {
        func_8002F434(&pthis->actor, globalCtx, GI_HEART_PIECE, EnSkj_GetItemXzRange(pthis), EnSkj_GetItemYRange(pthis));
    }
}

void EnSkj_SetupPostSariasSong(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_CHANGE_MODE);
}

void EnSkj_ChangeModeAfterSong(EnSkj* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        gSaveContext.itemGetInf[1] |= 0x40;
        EnSkj_SetNaviId(pthis);
        EnSkj_SetupWaitInRange(pthis);
    }
}

void EnSkj_SetupMaskTrade(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_START_TRADE);
}

void EnSkj_StartMaskTrade(EnSkj* pthis, GlobalContext* globalCtx) {
    u8 sp1F = Message_GetState(&globalCtx->msgCtx);

    func_8002DF54(globalCtx, &pthis->actor, 1);
    if ((sp1F == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        EnSkj_JumpFromStump(pthis);
    }
}

void EnSkj_JumpFromStump(EnSkj* pthis) {
    pthis->actor.velocity.y = 8.0f;
    pthis->actor.speedXZ = 2.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_BACKFLIP);
    Animation_Reverse(&pthis->skelAnime);
    pthis->skelAnime.curFrame = pthis->skelAnime.startFrame;
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING);
}

void EnSkj_WaitForLanding(EnSkj* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.velocity.y <= 0.0f) {
        if (pthis->actor.bgCheckFlags & 2) {
            pthis->actor.bgCheckFlags &= ~2;
            pthis->actor.speedXZ = 0.0f;
            EnSkj_SetupWaitForLandAnimFinish(pthis);
        }
    }
}

void EnSkj_SetupWaitForLandAnimFinish(EnSkj* pthis) {
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_LAND);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_FOR_LANDING_ANIM);
}

void EnSkj_WaitForLandAnimFinish(EnSkj* pthis, GlobalContext* globalCtx) {
    s16 lastFrame = Animation_GetLastFrame(&gSkullKidLandAnim);

    if (pthis->skelAnime.curFrame == lastFrame) {
        EnSkj_SetupWalkToPlayer(pthis);
    }
}

void EnSkj_SetupWalkToPlayer(EnSkj* pthis) {
    pthis->unk_2F0 = 0.0f;
    pthis->actor.speedXZ = 2.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WALK_TO_PLAYER);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WALK_TO_PLAYER);
}

void EnSkj_WalkToPlayer(EnSkj* pthis, GlobalContext* globalCtx) {
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 0xA, pthis->unk_2F0, 0);
    Math_ApproachF(&pthis->unk_2F0, 2000.0f, 1.0f, 100.0f);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if (pthis->actor.xzDistToPlayer < 120.0f) {
        pthis->actor.speedXZ = 0.0f;
        EnSkj_SetupAskForMask(pthis, globalCtx);
    }
}

void EnSkj_SetupAskForMask(EnSkj* pthis, GlobalContext* globalCtx) {
    Message_StartTextbox(globalCtx, 0x101C, &pthis->actor);
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_ASK_FOR_MASK);
}

void EnSkj_AskForMask(EnSkj* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // Yes
                EnSkj_SetupTakeMask(pthis, globalCtx);
                break;
            case 1: // No
                Message_ContinueTextbox(globalCtx, 0x101D);
                EnSkj_SetupWaitForMaskTextClear(pthis);
                break;
        }
    }
}

void EnSkj_SetupTakeMask(EnSkj* pthis, GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x101E);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_TAKE_MASK);
}

void EnSkj_TakeMask(EnSkj* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        Rupees_ChangeBy(10);
        gSaveContext.itemGetInf[3] |= 0x200;
        EnSkj_SetNaviId(pthis);
        Player_UnsetMask(globalCtx);
        Item_Give(globalCtx, ITEM_SOLD_OUT);
        Message_ContinueTextbox(globalCtx, 0x101F);
        EnSkj_SetupWaitForMaskTextClear(pthis);
    }
}

void EnSkj_SetupWaitForMaskTextClear(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_MASK_TEXT);
}

void EnSkj_WaitForMaskTextClear(EnSkj* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        func_8002DF54(globalCtx, &pthis->actor, 7);
        pthis->backfilpFlag = 1;
        EnSkj_Backflip(pthis);
    }
}

void EnSkj_SetupWrongSong(EnSkj* pthis) {
    pthis->textId = 0x1041;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WRONG_SONG);
}

void EnSkj_WrongSong(EnSkj* pthis, GlobalContext* globalCtx) {
    if (D_80B01EA0 != 0) {
        EnSkj_SetupWaitForTextClear(pthis);
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, EnSkj_GetItemXzRange(pthis));
    }
}

void EnSkj_SetupWaitForTextClear(EnSkj* pthis) {
    EnSkj_SetupAction(pthis, SKJ_ACTION_SARIA_SONG_WAIT_FOR_TEXT);
}

void EnSkj_SariasSongWaitForTextClear(EnSkj* pthis, GlobalContext* globalCtx) {
    u8 state = Message_GetState(&globalCtx->msgCtx);
    Player* player = GET_PLAYER(globalCtx);

    if (state == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        EnSkj_SetupWaitInRange(pthis);
        player->stateFlags2 |= 0x800000;
        player->unk_6A8 = (Actor*)sSmallStumpSkullKid.skullkid;
    }
}

void EnSkj_OcarinaGameSetupWaitForPlayer(EnSkj* pthis) {
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_OCARINA_GAME_WAIT_FOR_PLAYER);
}

void EnSkj_OcarinaGameWaitForPlayer(EnSkj* pthis, GlobalContext* globalCtx) {
    if (pthis->playerInRange) {
        pthis->actor.flags |= ACTOR_FLAG_0;
        EnSkj_SetupAction(pthis, SKJ_ACTION_OCARINA_GAME_IDLE);
    }
}

s32 EnSkj_IsLeavingGame(EnSkj* pthis) {
    s32 paramDecr = pthis->actor.params - 1;

    if (sOcarinaMinigameSkullKids[paramDecr].unk0 == 2) {
        EnSkj_SetupLeaveOcarinaGame(pthis);
        return true;
    }
    return false;
}

void EnSkj_SetupIdle(EnSkj* pthis) {
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_WAIT);
    EnSkj_SetupAction(pthis, SKJ_ACTION_OCARINA_GAME_IDLE);
}

void EnSkj_Appear(EnSkj* pthis) {
    if (pthis->alpha != 255) {
        pthis->alpha += 20;

        if (pthis->alpha > 255) {
            pthis->alpha = 255;
        }
    }
}

void EnSkj_OcarinaGameIdle(EnSkj* pthis, GlobalContext* globalCtx) {
    EnSkj_Appear(pthis);

    if ((EnSkj_IsLeavingGame(pthis) == false) && (pthis->minigameState != 0)) {
        EnSkj_SetupPlayOcarinaGame(pthis);
    }
}

void EnSkj_SetupPlayOcarinaGame(EnSkj* pthis) {
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_PLAY_FLUTE);
    EnSkj_SetupAction(pthis, SKJ_ACTION_OCARINA_GAME_PLAY);
}

void EnSkj_PlayOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx) {
    EnSkj_Appear(pthis);

    if (!EnSkj_IsLeavingGame(pthis) && (pthis->minigameState == 0)) {
        EnSkj_SetupIdle(pthis);
    }
}

void EnSkj_SetupLeaveOcarinaGame(EnSkj* pthis) {
    pthis->actor.velocity.y = 8.0f;
    pthis->actor.speedXZ = -8.0f;
    EnSkj_ChangeAnim(pthis, SKJ_ANIM_BACKFLIP);
    EnSkj_SetupAction(pthis, SKJ_ACTION_OCARINA_GAME_LEAVE);
}

void EnSkj_LeaveOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx) {
    s32 paramsDecr = pthis->actor.params - 1;

    sOcarinaMinigameSkullKids[paramsDecr].unk0 = 0;
    sOcarinaMinigameSkullKids[paramsDecr].skullkid = NULL;
    pthis->backfilpFlag = 1;
    EnSkj_Backflip(pthis);
}

void EnSkj_Update(Actor* thisx, GlobalContext* globalCtx) {
    Vec3f dropPos;
    s32 pad;
    EnSkj* pthis = (EnSkj*)thisx;

    D_80B01EA0 = Actor_ProcessTalkRequest(&pthis->actor, globalCtx);

    pthis->timer++;

    if (pthis->multiuseTimer != 0) {
        pthis->multiuseTimer--;
    }

    if (pthis->needleShootTimer != 0) {
        pthis->needleShootTimer--;
    }

    if (pthis->dodgeResetTimer != 0) {
        pthis->dodgeResetTimer--;
    }

    if (pthis->dodgeResetTimer == 0) {
        pthis->hitsUntilDodge = 3;
    }

    if ((pthis->backfilpFlag != 0) && (pthis->alpha == 0)) {
        if (pthis->action == 9) {
            dropPos.x = pthis->actor.world.pos.x;
            dropPos.y = pthis->actor.world.pos.y;
            dropPos.z = pthis->actor.world.pos.z;

            Item_DropCollectible(globalCtx, &dropPos, ITEM00_RUPEE_ORANGE);
        }
        Actor_Kill(&pthis->actor);
        return;
    }

    Actor_SetFocus(&pthis->actor, 30.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->actionFunc(pthis, globalCtx);
    pthis->actor.textId = pthis->textId;
    EnSkj_CollisionCheck(pthis, globalCtx);
    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);

    if ((pthis->unk_2D3 != 0) && (D_80B01EA0 == 0)) {
        CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);

        if (pthis->actor.colorFilterTimer == 0) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }

    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 20.0f, 7);
}

void EnSkj_SariasSongShortStumpUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnSkj* pthis = (EnSkj*)thisx;

    D_80B01EA0 = Actor_ProcessTalkRequest(&pthis->actor, globalCtx);
}

void EnSkj_TurnPlayer(EnSkj* pthis, Player* player) {
    Math_SmoothStepToS(&player->actor.shape.rot.y, pthis->actor.world.rot.y, 5, 2000, 0);
    player->actor.world.rot.y = player->actor.shape.rot.y;
    player->currentYaw = player->actor.shape.rot.y;
}

void EnSkj_SetupWaitForOcarina(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (EnSkj_RangeCheck(player, pthis)) {
        sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid->playerInRange = true;
        sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid->playerInRange = true;

        if (player->stateFlags2 & 0x1000000) {
            player->stateFlags2 |= 0x2000000;
            func_800F5BF0(4);
            EnSkj_TurnPlayer(pthis, player);
            player->unk_6A8 = &pthis->actor;
            Message_StartTextbox(globalCtx, 0x10BE, &pthis->actor);
            pthis->actionFunc = EnSkj_StartOcarinaMinigame;
        } else {
            pthis->actionFunc = EnSkj_WaitForOcarina;
        }
    }
}

void EnSkj_WaitForOcarina(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->stateFlags2 & 0x1000000) {
        player->stateFlags2 |= 0x2000000;
        func_800F5BF0(4);
        EnSkj_TurnPlayer(pthis, player);
        player->unk_6A8 = &pthis->actor;
        Message_StartTextbox(globalCtx, 0x10BE, &pthis->actor);
        pthis->actionFunc = EnSkj_StartOcarinaMinigame;
    } else if (EnSkj_RangeCheck(player, pthis)) {
        player->stateFlags2 |= 0x800000;
    }
}

void EnSkj_StartOcarinaMinigame(EnSkj* pthis, GlobalContext* globalCtx) {
    u8 dialogState = Message_GetState(&globalCtx->msgCtx);
    Player* player = GET_PLAYER(globalCtx);

    EnSkj_TurnPlayer(pthis, player);

    if (dialogState == TEXT_STATE_CLOSING) {
        func_8010BD58(globalCtx, OCARINA_ACTION_MEMORY_GAME);
        if (sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid != NULL) {
            sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid->minigameState = SKULL_KID_OCARINA_PLAY_NOTES;
        }
        pthis->songFailTimer = 160;
        pthis->actionFunc = EnSkj_WaitForPlayback;
    }
}

void EnSkj_WaitForPlayback(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    EnSkj_TurnPlayer(pthis, player);

    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_03) { // failed the game
        Message_CloseTextbox(globalCtx);
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        player->unk_6A8 = &pthis->actor;
        func_8002F2CC(&pthis->actor, globalCtx, 26.0f);
        pthis->textId = 0x102D;
        pthis->actionFunc = EnSkj_FailedMiniGame;
    } else if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_0F) { // completed the game
        func_80078884(NA_SE_SY_CORRECT_CHIME);
        Message_CloseTextbox(globalCtx);
        globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
        player->unk_6A8 = &pthis->actor;
        func_8002F2CC(&pthis->actor, globalCtx, 26.0f);
        pthis->textId = 0x10BF;
        pthis->actionFunc = EnSkj_WonOcarinaMiniGame;
    } else { // playing the game
        switch (globalCtx->msgCtx.msgMode) {
            case MSGMODE_MEMORY_GAME_LEFT_SKULLKID_WAIT:
                if (sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid != NULL) {
                    sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid->minigameState = SKULL_KID_OCRAINA_WAIT;
                }
                if (!Audio_IsSfxPlaying(NA_SE_SY_METRONOME)) {
                    if (sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid != NULL) {
                        sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid->minigameState =
                            SKULL_KID_OCARINA_PLAY_NOTES;
                    }
                    Message_UpdateOcarinaGame(globalCtx);
                }
                break;
            case MSGMODE_MEMORY_GAME_RIGHT_SKULLKID_WAIT:
                if (sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid != NULL) {
                    sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid->minigameState = SKULL_KID_OCRAINA_WAIT;
                }
                if (!Audio_IsSfxPlaying(NA_SE_SY_METRONOME)) {
                    Message_UpdateOcarinaGame(globalCtx);
                    pthis->songFailTimer = 160;
                }
                break;
            case MSGMODE_MEMORY_GAME_PLAYER_PLAYING:
                if (pthis->songFailTimer != 0) {
                    pthis->songFailTimer--;
                } else { // took too long, game failed
                    func_80078884(NA_SE_SY_OCARINA_ERROR);
                    Message_CloseTextbox(globalCtx);
                    globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
                    player->unk_6A8 = &pthis->actor;
                    func_8002F2CC(&pthis->actor, globalCtx, 26.0f);
                    pthis->textId = 0x102D;
                    pthis->actionFunc = EnSkj_FailedMiniGame;
                }
                break;
            case MSGMODE_MEMORY_GAME_START_NEXT_ROUND:
                if (!Audio_IsSfxPlaying(NA_SE_SY_METRONOME)) {
                    if (sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid != NULL) {
                        sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid->minigameState =
                            SKULL_KID_OCARINA_PLAY_NOTES;
                    }
                    pthis->songFailTimer = 160;
                    Audio_OcaSetInstrument(6); // related instrument sound (flute?)
                    Audio_OcaSetSongPlayback(OCARINA_SONG_MEMORY_GAME + 1, 1);
                    globalCtx->msgCtx.msgMode = MSGMODE_MEMORY_GAME_LEFT_SKULLKID_PLAYING;
                    globalCtx->msgCtx.stateTimer = 2;
                }
                break;
        }
    }
}

void EnSkj_FailedMiniGame(EnSkj* pthis, GlobalContext* globalCtx) {
    if (D_80B01EA0) {
        pthis->actionFunc = EnSkj_WaitForNextRound;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 26.0f);
    }
}

void EnSkj_WaitForNextRound(EnSkj* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE && Message_ShouldAdvance(globalCtx)) {
        EnSkj_OfferNextRound(pthis, globalCtx);
    }
}

void EnSkj_OfferNextRound(EnSkj* pthis, GlobalContext* globalCtx) {
    Message_ContinueTextbox(globalCtx, 0x102E);
    pthis->actionFunc = EnSkj_WaitForOfferResponse;
}

void EnSkj_WaitForOfferResponse(EnSkj* pthis, GlobalContext* globalCtx) {
    Player* player;

    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CHOICE && Message_ShouldAdvance(globalCtx)) {
        switch (globalCtx->msgCtx.choiceIndex) {
            case 0: // yes
                player = GET_PLAYER(globalCtx);
                player->stateFlags3 |= 0x20; // makes player take ocarina out right away after closing box
                pthis->actionFunc = EnSkj_SetupWaitForOcarina;
                break;
            case 1: // no
                pthis->actionFunc = EnSkj_CleanupOcarinaGame;
                break;
        }
    }
}

void EnSkj_WonOcarinaMiniGame(EnSkj* pthis, GlobalContext* globalCtx) {
    if (D_80B01EA0) {
        pthis->actionFunc = EnSkj_WaitToGiveReward;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, 26.0f);
    }
}

void EnSkj_WaitToGiveReward(EnSkj* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        func_8002F434(&pthis->actor, globalCtx, sOcarinaGameRewards[gSaveContext.ocarinaGameRoundNum], 26.0f, 26.0f);
        pthis->actionFunc = EnSkj_GiveOcarinaGameReward;
    }
}

void EnSkj_GiveOcarinaGameReward(EnSkj* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnSkj_FinishOcarinaGameRound;
    } else {
        func_8002F434(&pthis->actor, globalCtx, sOcarinaGameRewards[gSaveContext.ocarinaGameRoundNum], 26.0f, 26.0f);
    }
}

void EnSkj_FinishOcarinaGameRound(EnSkj* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        s32 ocarinaGameRoundNum = gSaveContext.ocarinaGameRoundNum;

        if (gSaveContext.ocarinaGameRoundNum < 3) {
            gSaveContext.ocarinaGameRoundNum++;
        }

        if (ocarinaGameRoundNum == 2) {
            gSaveContext.itemGetInf[1] |= 0x80;
            pthis->actionFunc = EnSkj_CleanupOcarinaGame;
        } else {
            EnSkj_OfferNextRound(pthis, globalCtx);
        }
    }
}

void EnSkj_CleanupOcarinaGame(EnSkj* pthis, GlobalContext* globalCtx) {
    if (sOcarinaMinigameSkullKids[SKULL_KID_LEFT].skullkid != NULL) {
        sOcarinaMinigameSkullKids[SKULL_KID_LEFT].unk0 = 2;
    }

    if (sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].skullkid != NULL) {
        sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].unk0 = 2;
    }

    if ((sOcarinaMinigameSkullKids[SKULL_KID_LEFT].unk0 == 2) &&
        (sOcarinaMinigameSkullKids[SKULL_KID_RIGHT].unk0 == 2)) {
        func_800F5C2C();
        Actor_Kill(&pthis->actor);
    }
}

void EnSkj_OcarinaMinigameShortStumpUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnSkj* pthis = (EnSkj*)thisx;

    D_80B01EA0 = Actor_ProcessTalkRequest(&pthis->actor, globalCtx);
    pthis->timer++;

    pthis->actor.focus.pos.x = 1230.0f;
    pthis->actor.focus.pos.y = -90.0f;
    pthis->actor.focus.pos.z = 450.0f;

    pthis->actionFunc(pthis, globalCtx);

    pthis->actor.textId = pthis->textId;
    pthis->actor.xzDistToPlayer = 50.0;
}

s32 EnSkj_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    return 0;
}

void EnSkj_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_skj.c", 2417);

    if ((limbIndex == 11) && (gSaveContext.itemGetInf[3] & 0x200)) {
        func_80093D18(globalCtx->state.gfxCtx);
        Matrix_Push();
        Matrix_RotateZYX(-0x4000, 0, 0, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_skj.c", 2430),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gSKJskullMaskDL);
        Matrix_Pop();
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_skj.c", 2437);
}

Gfx* EnSkj_TranslucentDL(GraphicsContext* gfxCtx, u32 alpha) {
    Gfx* dList;
    Gfx* dListHead;

    //! @bug This only allocates space for 1 command but uses 3
    dList = dListHead = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx));
    gDPSetRenderMode(dListHead++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetEnvColor(dListHead++, 0, 0, 0, alpha);
    gSPEndDisplayList(dListHead++);

    return dList;
}

Gfx* EnSkj_OpaqueDL(GraphicsContext* gfxCtx, u32 alpha) {
    Gfx* dList;
    Gfx* dListHead;

    //! @bug This only allocates space for 1 command but uses 2
    dList = dListHead = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx));
    gDPSetEnvColor(dListHead++, 0, 0, 0, alpha);
    gSPEndDisplayList(dListHead++);

    return dList;
}

void EnSkj_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnSkj* pthis = (EnSkj*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_skj.c", 2475);

    func_80093D18(globalCtx->state.gfxCtx);

    if (pthis->alpha < 255) {
        gSPSegment(POLY_OPA_DISP++, 0x0C, EnSkj_TranslucentDL(globalCtx->state.gfxCtx, pthis->alpha));
    } else {
        gSPSegment(POLY_OPA_DISP++, 0x0C, EnSkj_OpaqueDL(globalCtx->state.gfxCtx, pthis->alpha));
    }

    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnSkj_OverrideLimbDraw, EnSkj_PostLimbDraw, pthis);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_skj.c", 2495);
}

void EnSkj_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sSmallStumpSkullKid = { 0, NULL };

    En_Skj_InitVars = {
        ACTOR_EN_SKJ,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_SKJ,
        sizeof(EnSkj),
        (ActorFunc)EnSkj_Init,
        (ActorFunc)EnSkj_Destroy,
        (ActorFunc)EnSkj_Update,
        (ActorFunc)EnSkj_Draw,
        (ActorFunc)EnSkj_Reset,
    };

    D_80B01678 = {
        {
            COLTYPE_NONE,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x0, 0x08 },
            { 0xFFCFFFFF, 0x0, 0x0 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_ON,
        },
        { 8, 48, 0, { 0, 0, 0 } },
    };

    sDamageTable = {
        /* Deku nut      */ DMG_ENTRY(0, 0x0),
        /* Deku stick    */ DMG_ENTRY(0, 0x0),
        /* Slingshot     */ DMG_ENTRY(0, 0x0),
        /* Explosive     */ DMG_ENTRY(0, 0x0),
        /* Boomerang     */ DMG_ENTRY(0, 0x0),
        /* Normal arrow  */ DMG_ENTRY(0, 0x0),
        /* Hammer swing  */ DMG_ENTRY(2, 0x0),
        /* Hookshot      */ DMG_ENTRY(0, 0x0),
        /* Kokiri sword  */ DMG_ENTRY(1, 0xF),
        /* Master sword  */ DMG_ENTRY(2, 0xF),
        /* Giant's Knife */ DMG_ENTRY(4, 0xF),
        /* Fire arrow    */ DMG_ENTRY(0, 0x0),
        /* Ice arrow     */ DMG_ENTRY(0, 0x0),
        /* Light arrow   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 1   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 2   */ DMG_ENTRY(0, 0x0),
        /* Unk arrow 3   */ DMG_ENTRY(0, 0x0),
        /* Fire magic    */ DMG_ENTRY(0, 0x0),
        /* Ice magic     */ DMG_ENTRY(0, 0x0),
        /* Light magic   */ DMG_ENTRY(0, 0x0),
        /* Shield        */ DMG_ENTRY(0, 0x0),
        /* Mirror Ray    */ DMG_ENTRY(0, 0x0),
        /* Kokiri spin   */ DMG_ENTRY(1, 0x0),
        /* Giant spin    */ DMG_ENTRY(4, 0x0),
        /* Master spin   */ DMG_ENTRY(2, 0x0),
        /* Kokiri jump   */ DMG_ENTRY(2, 0x0),
        /* Giant jump    */ DMG_ENTRY(8, 0x0),
        /* Master jump   */ DMG_ENTRY(4, 0x0),
        /* Unknown 1     */ DMG_ENTRY(0, 0x0),
        /* Unblockable   */ DMG_ENTRY(0, 0x0),
        /* Hammer jump   */ DMG_ENTRY(0, 0x0),
        /* Unknown 2     */ DMG_ENTRY(0, 0x0),
    };

    D_80B01EA0 = 0;

}

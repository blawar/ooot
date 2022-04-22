#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_FR_Z_EN_FR_C
#include "actor_common.h"
#include "z_en_fr.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "vt.h"
#include "objects/object_fr/object_fr.h"
#include "z64audio.h"
#include "def/audio.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_lights.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

void EnFr_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFr_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnFr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFr_Update(Actor* thisx, GlobalContext* globalCtx);
void EnFr_UpdateIdle(Actor* thisx, GlobalContext* globalCtx);
void EnFr_UpdateActive(Actor* thisx, GlobalContext* globalCtx);
void EnFr_Draw(Actor* thisx, GlobalContext* globalCtx);

// Animation Functions
void EnFr_SetupJumpingOutOfWater(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_JumpingOutOfWater(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_OrientOnLogSpot(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ChooseJumpFromLogSpot(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_JumpingUp(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_JumpingBackIntoWater(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_DecrementBlinkTimerUpdate(EnFr* pthis);

// Activation
void EnFr_Idle(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_Activate(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ActivateCheckFrogSong(EnFr* pthis, GlobalContext* globalCtx);

// Listening for Child Songs
void func_80A1BE98(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ListeningToOcarinaNotes(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ChildSong(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ChildSongFirstTime(EnFr* pthis, GlobalContext* globalCtx);

// Frog Song for HP Functions
void EnFr_TalkBeforeFrogSong(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_SetupFrogSong(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_ContinueFrogSong(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_OcarinaMistake(EnFr* pthis, GlobalContext* globalCtx);

// Reward Functions
void EnFr_SetupReward(EnFr* pthis, GlobalContext* globalCtx, u8 unkCondition);
void EnFr_PrintTextBox(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_TalkBeforeReward(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_SetReward(EnFr* pthis, GlobalContext* globalCtx);

// Deactivate
void EnFr_Deactivate(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_GiveReward(EnFr* pthis, GlobalContext* globalCtx);
void EnFr_SetIdle(EnFr* pthis, GlobalContext* globalCtx);

static void* eyeTextures_137[] = {
    object_fr_Tex_0059A0,
    object_fr_Tex_005BA0,
};


/*
Frogs params WIP docs

Represents 6 Actor Instances for frogs:
    - 1 Prop actor instance set to where Link plays Ocarina, manages 5 frogs
    - 5 NPC actor instances for the frogs themselves

0: Prop Actor Instance (located where link detects ocarina, interacts with Link)
1: Frog 0 (Yellow)
2: Frog 1 (Blue)
3: Frog 2 (Red)
4: Frog 3 (Purple)
5: Frog 4 (White)

Note that because of the Prop Actor, actor.params is 1 shifted from frogIndex
Therefore, frogIndex = actor.params - 1


sEnFrPointers.flags = 1
     - Activate frogs, frogs will jump out of the water

sEnFrPointers.flags = 1 to 11:
     - Counter: Frogs will sequentially jump out based on counter:
         - 1: Frog 1 (Blue)
         - 3: frog 3 (Purple)
         - 5: frog 0 (Yellow)
         - 7: frog 2 (Red)
         - 9: frog 4 (White)
     - Will proceed when counter reachers 11

sEnFrPointers.flags = 12
     - Deactivate frogs, frogs will jump back into the water
*/

static EnFrPointers sEnFrPointers = {
    0x00,
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    },
};

// Flags for gSaveContext.eventChkInf[13]
static u16 sSongIndex[] = {
    0x0002, 0x0004, 0x0010, 0x0008, 0x0020, 0x0040, 0x0001, 0x0000,
};

// Frog to Index for Song Flag (sSongIndex) Mapping
static u8 sFrogToSongIndex[] = {
    FROG_SARIA, FROG_SUNS, FROG_SOT, FROG_ZL, FROG_EPONA,
};

// Song to Frog Index Mapping
static s32 sSongToFrog[] = {
    FROG_PURPLE, FROG_WHITE, FROG_YELLOW, FROG_BLUE, FROG_RED,
};

ActorInit En_Fr_InitVars = {
    ACTOR_EN_FR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_FR,
    sizeof(EnFr),
    (ActorFunc)EnFr_Init,
    (ActorFunc)EnFr_Destroy,
    (ActorFunc)EnFr_Update,
    NULL,
    (ActorFunc)EnFr_Reset,
};

static Color_RGBA8 sEnFrColor[] = {
    { 200, 170, 0, 255 }, { 0, 170, 200, 255 }, { 210, 120, 100, 255 }, { 120, 130, 230, 255 }, { 190, 190, 190, 255 },
};

// Jumping back into water frog animation
//      sLogSpotToFromWater[frog].xzDist is magnitude of xz distance frog travels
//      sLogSpotToFromWater[frog].yaw is rot around y-axis of jumping back into water
//      sLogSpotToFromWater[frog].yDist is change in y distance frog travels
static LogSpotToFromWater sLogSpotToFromWater[] = {
    { 0.0f, 0.0f, 0.0f },              // Prop   (Where link pulls ocarina)
    { 80.0f, -0.375f * M_PI, -80.0f }, // FROG_YELLOW
    { 80.0f, -0.5f * M_PI, -80.0f },   // FROG_BLUE
    { 80.0f, -0.25f * M_PI, -80.0f },  // FROG_RED
    { 80.0f, 0.875f * M_PI, -80.0f },  // FROG_PURPLE
    { 80.0f, 0.5f * M_PI, -80.0f },    // FROG_WHITE
};

// Timer values for the frog choir song
static s16 sTimerFrogSong[] = {
    40, 20, 15, 12, 12,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 30, ICHAIN_STOP),
};

// Counter to Coordinate Frog jumping out of water one at a time
// Used as part of sEnFrPointers.flags
static u8 sTimerJumpingOutOfWater[] = {
    5, 1, 7, 3, 9,
};

// targetScale (default = 150.0) Actor scale target for Math_ApproachF
// Used as a frog grows from hearing a new child song
static f32 sGrowingScale[] = {
    180.0f,
    210.0f,
    240.0f,
    270.0f,
};

static u8 sSmallFrogNotes[] = {
    5,  // C-Down Ocarina
    2,  // A Button Ocarina
    9,  // C-Right Ocarina
    11, // C-Left Ocarina
    14, // C Up Ocarina
};

static s8 sLargeFrogNotes[] = {
    -7,  // C-Down Ocarina
    -10, // A Button Ocarina
    -3,  // C-Right Ocarina
    -1,  // C-Left Ocarina
    2,   // C Up Ocarina
};

static u8 sJumpOrder[] = {
    FROG_BLUE, FROG_YELLOW, FROG_RED, FROG_PURPLE, FROG_WHITE, FROG_BLUE, FROG_YELLOW, FROG_RED,
};

static u8 sOcarinaNotes[] = {
    OCARINA_NOTE_A, OCARINA_NOTE_C_DOWN, OCARINA_NOTE_C_RIGHT, OCARINA_NOTE_C_LEFT, OCARINA_NOTE_C_UP,
};

void EnFr_OrientUnderwater(EnFr* pthis) {
    Vec3f vec1;
    Vec3f vec2;

    vec1.x = vec1.y = 0.0f;
    vec1.z = pthis->xzDistToLogSpot = sLogSpotToFromWater[pthis->actor.params].xzDist;
    Matrix_RotateY(sLogSpotToFromWater[pthis->actor.params].yaw, MTXMODE_NEW);
    Matrix_MultVec3f(&vec1, &vec2);
    pthis->actor.world.pos.x = pthis->posLogSpot.x + vec2.x;
    pthis->actor.world.pos.z = pthis->posLogSpot.z + vec2.z;
    pthis->actor.world.pos.y = sLogSpotToFromWater[pthis->actor.params].yDist + pthis->posLogSpot.y;
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y =
        (s16)(sLogSpotToFromWater[pthis->actor.params].yaw * ((f32)0x8000 / M_PI)) + 0x8000;
    pthis->actor.speedXZ = 0.0f;
    pthis->actor.velocity.y = 0.0f;
    pthis->actor.gravity = 0.0f;
}

void EnFr_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnFr* pthis = (EnFr*)thisx;

    if (pthis->actor.params == 0) {
        pthis->actor.destroy = NULL;
        pthis->actor.draw = NULL;
        pthis->actor.update = EnFr_UpdateIdle;
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_4);
        pthis->actor.flags &= ~0;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_PROP);
        pthis->actor.textId = 0x40AC;
        pthis->actionFunc = EnFr_Idle;
    } else {
        if ((pthis->actor.params >= 6) || (pthis->actor.params < 0)) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "The argument is wrong!!"
            osSyncPrintf("%s[%d] : 引数が間違っている！！(%d)\n", "../z_en_fr.c", 370, pthis->actor.params);
            osSyncPrintf(VT_RST);
            ASSERT(0, "0", "../z_en_fr.c", 372);
        }

        pthis->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_GAMEPLAY_FIELD_KEEP);
        if (pthis->objBankIndex < 0) {
            Actor_Kill(&pthis->actor);
            osSyncPrintf(VT_COL(RED, WHITE));
            // "There is no bank!!"
            osSyncPrintf("%s[%d] : バンクが無いよ！！\n", "../z_en_fr.c", 380);
            osSyncPrintf(VT_RST);
            ASSERT(0, "0", "../z_en_fr.c", 382);
        }
    }
}

// Draw only the purple frog when ocarina is not pulled out on the log spot
void EnFr_DrawIdle(EnFr* pthis) {
    pthis->actor.draw = (pthis->actor.params - 1) != FROG_PURPLE ? NULL : EnFr_Draw;
}

void EnFr_DrawActive(EnFr* pthis) {
    pthis->actor.draw = EnFr_Draw;
}

void EnFr_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnFr* pthis = (EnFr*)thisx;
    s32 pad;
    s32 frogIndex;
    s32 pad2;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objBankIndex)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        frogIndex = pthis->actor.params - 1;
        sEnFrPointers.frogs[frogIndex] = pthis;
        Actor_ProcessInitChain(&pthis->actor, sInitChain);
        // frog
        SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_fr_Skel_00B498, &object_fr_Anim_001534,
                           pthis->jointTable, pthis->morphTable, 24);
        // butterfly
        SkelAnime_Init(globalCtx, &pthis->skelAnimeButterfly, &gButterflySkel, &gButterflyAnim,
                       pthis->jointTableButterfly, pthis->morphTableButterfly, 8);
        // When playing the song for the HP, the frog with the next note and the butterfly turns on its lightsource
        pthis->lightNode = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &pthis->lightInfo);
        Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->actor.home.pos.x, pthis->actor.home.pos.y,
                                  pthis->actor.home.pos.z, 255, 255, 255, -1);
        // Check to see if the song for a particular frog has been played.
        // If it has, the frog is larger. If not, the frog is smaller
        pthis->scale = gSaveContext.eventChkInf[13] & sSongIndex[sFrogToSongIndex[frogIndex]] ? 270.0f : 150.0f;
        // When the frogs are not active (link doesn't have his ocarina out),
        // Then shrink the frogs down by a factor of 10,000
        Actor_SetScale(&pthis->actor, pthis->scale * 0.0001f);
        pthis->actor.minVelocityY = -9999.0f;
        Actor_SetFocus(&pthis->actor, 10.0f);
        pthis->eyeTexIndex = 1;
        pthis->blinkTimer = (s16)(Rand_ZeroFloat(60.0f) + 20.0f);
        pthis->blinkFunc = EnFr_DecrementBlinkTimerUpdate;
        pthis->isBelowWaterSurfacePrevious = pthis->isBelowWaterSurfaceCurrent = false;
        pthis->isJumpingUp = false;
        pthis->posLogSpot = pthis->actor.world.pos;
        pthis->actionFunc = EnFr_SetupJumpingOutOfWater;
        pthis->isDeactivating = false;
        pthis->growingScaleIndex = 0;
        pthis->isActive = false;
        pthis->isJumpingToFrogSong = false;
        pthis->songIndex = FROG_NO_SONG;
        pthis->unusedButterflyActor = NULL;
        EnFr_OrientUnderwater(pthis);
        EnFr_DrawIdle(pthis);
        pthis->actor.update = EnFr_UpdateActive;
        pthis->isButterflyDrawn = false;
        pthis->xyAngleButterfly = 0x1000 * (s16)Rand_ZeroFloat(255.0f);
        pthis->posButterflyLight.x = pthis->posButterfly.x = pthis->posLogSpot.x;
        pthis->posButterflyLight.y = pthis->posButterfly.y = pthis->posLogSpot.y + 50.0f;
        pthis->posButterflyLight.z = pthis->posButterfly.z = pthis->posLogSpot.z;
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }
}

void EnFr_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnFr* pthis = (EnFr*)thisx;

    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, pthis->lightNode);
}

void EnFr_IsDivingIntoWater(EnFr* pthis, GlobalContext* globalCtx) {
    WaterBox* waterBox;
    f32 waterSurface;

    if (WaterBox_GetSurfaceImpl(globalCtx, &globalCtx->colCtx, pthis->actor.world.pos.x, pthis->actor.world.pos.z,
                                &waterSurface, &waterBox)) {
        pthis->isBelowWaterSurfacePrevious = pthis->isBelowWaterSurfaceCurrent;
        pthis->isBelowWaterSurfaceCurrent = pthis->actor.world.pos.y <= waterSurface ? true : false;
    }
}

void EnFr_DivingIntoWater(EnFr* pthis, GlobalContext* globalCtx) {
    Vec3f vec;

    // Jumping into or out of water
    if (pthis->isBelowWaterSurfaceCurrent != pthis->isBelowWaterSurfacePrevious) {
        vec.x = pthis->actor.world.pos.x;
        vec.y = pthis->actor.world.pos.y - 10.0f;
        vec.z = pthis->actor.world.pos.z;
        EffectSsGSplash_Spawn(globalCtx, &vec, NULL, NULL, 1, 1);

        if (pthis->isBelowWaterSurfaceCurrent == false) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_DIVE_INTO_WATER_L);
        } else {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_BOMB_DROP_WATER);
        }
    }
}

s32 EnFr_IsBelowLogSpot(EnFr* pthis, f32* yDistToLogSpot) {
    yDistToLogSpot[0] = pthis->actor.world.pos.y - pthis->posLogSpot.y;
    if ((pthis->actor.velocity.y < 0.0f) && (yDistToLogSpot[0] <= 0.0f)) {
        pthis->actor.velocity.y = 0.0f;
        pthis->actor.world.pos.y = pthis->posLogSpot.y;
        return true;
    } else {
        return false;
    }
}

s32 EnFr_IsAboveAndWithin30DistXZ(Player* player, EnFr* pthis) {
    f32 xDistToPlayer = player->actor.world.pos.x - pthis->actor.world.pos.x;
    f32 zDistToPlayer = player->actor.world.pos.z - pthis->actor.world.pos.z;
    f32 yDistToPlayer = player->actor.world.pos.y - pthis->actor.world.pos.y;

    return ((SQ(xDistToPlayer) + SQ(zDistToPlayer)) <= SQ(30.0f)) && (yDistToPlayer >= 0.0f);
}

void EnFr_DecrementBlinkTimer(EnFr* pthis) {
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    } else {
        pthis->blinkFunc = EnFr_DecrementBlinkTimerUpdate;
    }
}

void EnFr_DecrementBlinkTimerUpdate(EnFr* pthis) {
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    } else if (pthis->eyeTexIndex) {
        pthis->eyeTexIndex = 0;
        pthis->blinkTimer = (s16)(Rand_ZeroFloat(60.0f) + 20.0f);
        pthis->blinkFunc = EnFr_DecrementBlinkTimer;
    } else {
        pthis->eyeTexIndex = 1;
        pthis->blinkTimer = 1;
    }
}

void EnFr_SetupJumpingOutOfWater(EnFr* pthis, GlobalContext* globalCtx) {
    if (sEnFrPointers.flags == sTimerJumpingOutOfWater[pthis->actor.params - 1]) {
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_0007BC, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_0007BC), ANIMMODE_ONCE, 0.0f);
        EnFr_DrawActive(pthis);
        pthis->actionFunc = EnFr_JumpingOutOfWater;
    }
}

void EnFr_JumpingOutOfWater(EnFr* pthis, GlobalContext* globalCtx) {
    Vec3f vec1;
    Vec3f vec2;

    if (pthis->skelAnime.curFrame == 6.0f) {
        sEnFrPointers.flags++;
        pthis->skelAnime.playSpeed = 0.0f;
    } else if (pthis->skelAnime.curFrame == 3.0f) {
        pthis->actor.gravity = -10.0f;
        pthis->actor.speedXZ = 0.0f;
        pthis->actor.velocity.y = 47.0f;
    }

    vec1.x = vec1.y = 0.0f;
    vec1.z = pthis->xzDistToLogSpot;
    Matrix_RotateY(((pthis->actor.world.rot.y + 0x8000) / (f32)0x8000) * M_PI, MTXMODE_NEW);
    Matrix_MultVec3f(&vec1, &vec2);
    pthis->actor.world.pos.x = pthis->posLogSpot.x + vec2.x;
    pthis->actor.world.pos.z = pthis->posLogSpot.z + vec2.z;
    if (pthis->skelAnime.curFrame >= 3.0f) {
        Math_ApproachF(&pthis->xzDistToLogSpot, 0.0f, 1.0f, 10.0f);
    }

    if (EnFr_IsBelowLogSpot(pthis, &vec2.y)) {
        pthis->actor.gravity = 0.0f;
        pthis->actionFunc = EnFr_OrientOnLogSpot;
        pthis->unusedFloat = 0.0f;
    }

    if ((pthis->actor.velocity.y <= 0.0f) && (vec2.y < 40.0f)) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnFr_OrientOnLogSpot(EnFr* pthis, GlobalContext* globalCtx) {
    s16 rotYRemaining = Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 2, 10000, 100);

    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;

    if ((rotYRemaining == 0) && (pthis->skelAnime.curFrame == pthis->skelAnime.endFrame)) {
        sEnFrPointers.flags++;
        pthis->actionFunc = EnFr_ChooseJumpFromLogSpot;
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_001534, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_001534), ANIMMODE_LOOP, 0.0f);
    }
}

void EnFr_ChooseJumpFromLogSpot(EnFr* pthis, GlobalContext* globalCtx) {
    if (sEnFrPointers.flags == 12) {
        pthis->actor.world.rot.y = ((f32)0x8000 / M_PI) * sLogSpotToFromWater[pthis->actor.params].yaw;
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_0007BC, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_0007BC), ANIMMODE_ONCE, 0.0f);
        pthis->actionFunc = EnFr_JumpingBackIntoWater;
    } else if (pthis->isJumpingUp) {
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_0007BC, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_0007BC), ANIMMODE_ONCE, 0.0f);
        pthis->actionFunc = EnFr_JumpingUp;
    }
}

void EnFr_JumpingUp(EnFr* pthis, GlobalContext* globalCtx) {
    f32 yDistToLogSpot;

    if (pthis->skelAnime.curFrame == 6.0f) {
        pthis->skelAnime.playSpeed = 0.0f;
    } else if (pthis->skelAnime.curFrame == 3.0f) {
        pthis->actor.gravity = -10.0f;
        pthis->actor.velocity.y = 25.0f;
        if (pthis->isJumpingToFrogSong) {
            pthis->isJumpingToFrogSong = false;
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_DODO_M_EAT);
        }
    }

    if (EnFr_IsBelowLogSpot(pthis, &yDistToLogSpot)) {
        pthis->isJumpingUp = false;
        pthis->actor.gravity = 0.0f;
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_0011C0, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_0011C0), ANIMMODE_LOOP, 0.0f);
        pthis->actionFunc = EnFr_ChooseJumpFromLogSpot;
    } else if ((pthis->actor.velocity.y <= 0.0f) && (yDistToLogSpot < 40.0f)) {
        pthis->skelAnime.playSpeed = 1.0f;
    }
}

void EnFr_JumpingBackIntoWater(EnFr* pthis, GlobalContext* globalCtx) {
    f32 yUnderwater = sLogSpotToFromWater[pthis->actor.params].yDist + pthis->posLogSpot.y;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.world.rot.y, 2, 10000, 100);
    if (pthis->skelAnime.curFrame == 6.0f) {
        pthis->skelAnime.playSpeed = 0.0f;
    } else if (pthis->skelAnime.curFrame == 3.0f) {
        pthis->actor.speedXZ = 6.0f;
        pthis->actor.gravity = -10.0f;
        pthis->actor.velocity.y = 25.0f;
    }

    // Final Spot Reached
    if ((pthis->actor.velocity.y < 0.0f) && (pthis->actor.world.pos.y < yUnderwater)) {
        Animation_Change(&pthis->skelAnime, &object_fr_Anim_001534, 1.0f, 0.0f,
                         Animation_GetLastFrame(&object_fr_Anim_001534), ANIMMODE_LOOP, 0.0f);
        pthis->actionFunc = EnFr_SetupJumpingOutOfWater;
        EnFr_DrawIdle(pthis);
        pthis->isDeactivating = true;
        EnFr_OrientUnderwater(pthis);
    }
}

void EnFr_SetScaleActive(EnFr* pthis, GlobalContext* globalCtx) {
    switch (pthis->isGrowing) {
        case false:
            Math_ApproachF(&pthis->scale, sGrowingScale[pthis->growingScaleIndex], 2.0f, 25.0f);
            if (pthis->scale >= sGrowingScale[pthis->growingScaleIndex]) {
                pthis->scale = sGrowingScale[pthis->growingScaleIndex];
                if (pthis->growingScaleIndex < 3) {
                    pthis->isGrowing = true;
                } else {
                    pthis->isJumpingUp = false;
                    pthis->isActive = false;
                }
            }
            break;
        case true:
            Math_ApproachF(&pthis->scale, 150.0f, 2.0f, 25.0f);
            if (pthis->scale <= 150.0f) {
                pthis->scale = 150.0f;
                pthis->growingScaleIndex++;
                if (pthis->growingScaleIndex >= 4) {
                    pthis->growingScaleIndex = 3;
                }
                pthis->isGrowing = false;
            }
            break;
    }
}

void EnFr_ButterflyPath(EnFr* pthis, GlobalContext* globalCtx) {
    s16 rotY = pthis->actor.shape.rot.y;
    f32 sin;
    Vec3f vec1;
    Vec3f vec2;

    pthis->xyAngleButterfly += 0x1000;
    Matrix_Translate(pthis->actor.world.pos.x, pthis->actor.world.pos.y, pthis->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    vec1.x = vec1.y = 0.0f;
    vec1.z = 25.0f;
    Matrix_MultVec3f(&vec1, &vec2);
    sin = Math_SinS(pthis->xyAngleButterfly * 2) * 5.0f;
    pthis->posButterfly.x = (Math_SinS(rotY) * sin) + vec2.x;
    pthis->posButterfly.y = (2.0f * Math_CosS(pthis->xyAngleButterfly)) + (pthis->posLogSpot.y + 50.0f);
    pthis->posButterfly.z = (Math_CosS(rotY) * sin) + vec2.z;
    Matrix_Translate(pthis->posButterfly.x, pthis->posButterfly.y, pthis->posButterfly.z, MTXMODE_NEW);
    Matrix_RotateZYX(pthis->actor.world.rot.x, pthis->actor.world.rot.y, pthis->actor.world.rot.z, MTXMODE_APPLY);
    vec1.x = 0.0f;
    vec1.y = -15.0f;
    vec1.z = 20.0f;
    Matrix_MultVec3f(&vec1, &pthis->posButterflyLight);
}

void EnFr_UpdateActive(Actor* thisx, GlobalContext* globalCtx) {
    EnFr* pthis = (EnFr*)thisx;

    pthis->jumpCounter++;
    Actor_SetScale(&pthis->actor, pthis->scale * 0.0001f);

    if (pthis->isActive) {
        EnFr_SetScaleActive(pthis, globalCtx);
    } else {
        Actor_SetFocus(&pthis->actor, 10.0f);
        pthis->blinkFunc(pthis);
        pthis->actionFunc(pthis, globalCtx);
        EnFr_IsDivingIntoWater(pthis, globalCtx);
        EnFr_DivingIntoWater(pthis, globalCtx);
        SkelAnime_Update(&pthis->skelAnime);
        SkelAnime_Update(&pthis->skelAnimeButterfly);
        EnFr_ButterflyPath(pthis, globalCtx);
        Actor_MoveForward(&pthis->actor);
    }
}

s32 EnFr_SetupJumpingUp(EnFr* pthis, s32 frogIndex) {
    EnFr* frog = sEnFrPointers.frogs[frogIndex];
    u8 semitone;

    if (frog != NULL && frog->isJumpingUp == false) {
        semitone = frog->growingScaleIndex == 3 ? sLargeFrogNotes[frogIndex] : sSmallFrogNotes[frogIndex];
        if (pthis->songIndex == FROG_CHOIR_SONG) {
            frog->isJumpingToFrogSong = true;
        }
        frog->isJumpingUp = true;
        Audio_PlaySoundTransposed(&frog->actor.projectedPos, NA_SE_EV_FROG_JUMP, semitone);
        return true;
    } else {
        return false;
    }
}

void EnFr_Idle(EnFr* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (player->stateFlags2 & 0x2000000) {
        if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
            globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_00;
        }

        OnePointCutscene_Init(globalCtx, 4110, ~0x62, &pthis->actor, MAIN_CAM);
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        player->actor.world.pos.x = pthis->actor.world.pos.x; // x = 990.0f
        player->actor.world.pos.y = pthis->actor.world.pos.y; // y = 205.0f
        player->actor.world.pos.z = pthis->actor.world.pos.z; // z = -1220.0f
        player->currentYaw = player->actor.world.rot.y = player->actor.shape.rot.y = pthis->actor.world.rot.y;
        pthis->reward = GI_NONE;
        pthis->actionFunc = EnFr_Activate;
    } else if (EnFr_IsAboveAndWithin30DistXZ(player, pthis)) {
        player->unk_6A8 = &pthis->actor;
    }
}

void EnFr_Activate(EnFr* pthis, GlobalContext* globalCtx) {
    if (globalCtx->msgCtx.msgMode == MSGMODE_OCARINA_PLAYING) {
        globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
        sEnFrPointers.flags = 1;
        pthis->actionFunc = EnFr_ActivateCheckFrogSong;
    } else if (globalCtx->msgCtx.msgMode == MSGMODE_PAUSED) { // Goes to Frogs 2 Song
        sEnFrPointers.flags = 1;
        pthis->actionFunc = EnFr_ActivateCheckFrogSong;
    }
}

void EnFr_ActivateCheckFrogSong(EnFr* pthis, GlobalContext* globalCtx) {
    if (sEnFrPointers.flags == 11) {
        // Check if all 6 child songs have been played for the frogs
        if ((gSaveContext.eventChkInf[13] & 0x2)        // ZL
            && (gSaveContext.eventChkInf[13] & 0x4)     // Epona
            && (gSaveContext.eventChkInf[13] & 0x10)    // Saria
            && (gSaveContext.eventChkInf[13] & 0x8)     // Suns
            && (gSaveContext.eventChkInf[13] & 0x20)    // SoT
            && (gSaveContext.eventChkInf[13] & 0x40)) { // SoS
            pthis->actionFunc = EnFr_TalkBeforeFrogSong;
            pthis->songIndex = FROG_CHOIR_SONG;
            Message_StartTextbox(globalCtx, 0x40AB, &pthis->actor);
        } else {
            pthis->songIndex = FROG_ZL;
            pthis->actionFunc = func_80A1BE98;
        }
    }
}

void func_80A1BE98(EnFr* pthis, GlobalContext* globalCtx) {
    EnFr* frog;
    s32 frogIndex;

    for (frogIndex = 0; frogIndex < ARRAY_COUNT(sEnFrPointers.frogs); frogIndex++) {
        frog = sEnFrPointers.frogs[frogIndex];
        if (frog != NULL && frog->actionFunc == EnFr_ChooseJumpFromLogSpot) {
            continue;
        } else {
            return;
        }
    }

    func_8010BD58(globalCtx, OCARINA_ACTION_CHECK_NOWARP);
    pthis->actionFunc = EnFr_ListeningToOcarinaNotes;
}

void EnFr_ListeningToOcarinaNotes(EnFr* pthis, GlobalContext* globalCtx) {
    pthis->songIndex = FROG_NO_SONG;
    switch (globalCtx->msgCtx.ocarinaMode) { // Ocarina Song played
        case OCARINA_MODE_07:
            pthis->songIndex = FROG_ZL;
            break;
        case OCARINA_MODE_06:
            pthis->songIndex = FROG_EPONA;
            break;
        case OCARINA_MODE_05:
            pthis->songIndex = FROG_SARIA;
            break;
        case OCARINA_MODE_08:
            pthis->songIndex = FROG_SUNS;
            break;
        case OCARINA_MODE_09:
            pthis->songIndex = FROG_SOT;
            break;
        case OCARINA_MODE_0A:
            pthis->songIndex = FROG_STORMS;
            break;
        case OCARINA_MODE_04:
            EnFr_OcarinaMistake(pthis, globalCtx);
            break;
        case OCARINA_MODE_01:                           // Ocarina note played, but no song played
            switch (globalCtx->msgCtx.lastOcaNoteIdx) { // Jumping frogs in open ocarina based on ocarina note played
                case OCARINA_NOTE_A:
                    EnFr_SetupJumpingUp(pthis, FROG_BLUE);
                    break;
                case OCARINA_NOTE_C_DOWN:
                    EnFr_SetupJumpingUp(pthis, FROG_YELLOW);
                    break;
                case OCARINA_NOTE_C_RIGHT:
                    EnFr_SetupJumpingUp(pthis, FROG_RED);
                    break;
                case OCARINA_NOTE_C_LEFT:
                    EnFr_SetupJumpingUp(pthis, FROG_PURPLE);
                    break;
                case OCARINA_NOTE_C_UP:
                    EnFr_SetupJumpingUp(pthis, FROG_WHITE);
                    break;
            }
    }
    if (pthis->songIndex != FROG_NO_SONG) {
        pthis->jumpCounter = 0;
        pthis->actionFunc = EnFr_ChildSong;
    }
}

void EnFr_ChildSong(EnFr* pthis, GlobalContext* globalCtx) {
    EnFr* frog;
    u8 songIndex;

    if (pthis->jumpCounter < 48) {
        if (pthis->jumpCounter % 4 == 0) {
            EnFr_SetupJumpingUp(pthis, sJumpOrder[(pthis->jumpCounter >> 2) & 7]);
        }
    } else {
        songIndex = pthis->songIndex;
        if (songIndex == FROG_STORMS) {
            pthis->actor.textId = 0x40AA;
            EnFr_SetupReward(pthis, globalCtx, false);
        } else if (!(gSaveContext.eventChkInf[13] & sSongIndex[songIndex])) {
            frog = sEnFrPointers.frogs[sSongToFrog[songIndex]];
            Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
            if (frog->actionFunc == EnFr_ChooseJumpFromLogSpot) {
                frog->isJumpingUp = true;
                frog->isActive = true;
                Audio_PlayActorSound2(&frog->actor, NA_SE_EV_FROG_GROW_UP);
                pthis->actionFunc = EnFr_ChildSongFirstTime;
            } else {
                pthis->jumpCounter = 48;
            }
        } else {
            pthis->actor.textId = 0x40A9;
            EnFr_SetupReward(pthis, globalCtx, true);
        }
    }
}

void EnFr_ChildSongFirstTime(EnFr* pthis, GlobalContext* globalCtx) {
    EnFr* frog = sEnFrPointers.frogs[sSongToFrog[pthis->songIndex]];

    if (frog->isActive == false) {
        pthis->actor.textId = 0x40A9;
        EnFr_SetupReward(pthis, globalCtx, true);
    }
}

void EnFr_TalkBeforeFrogSong(EnFr* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        pthis->frogSongTimer = 2;
        pthis->actionFunc = EnFr_SetupFrogSong;
    }
}

void EnFr_CheckOcarinaInputFrogSong(u8 ocarinaNote) {
    EnFr* frog;
    s32 frogIndexButterfly;
    s32 frogIndex;

    switch (ocarinaNote) {
        case 0:
            frogIndexButterfly = FROG_BLUE;
            break;
        case 1:
            frogIndexButterfly = FROG_YELLOW;
            break;
        case 2:
            frogIndexButterfly = FROG_RED;
            break;
        case 3:
            frogIndexButterfly = FROG_PURPLE;
            break;
        case 4:
            frogIndexButterfly = FROG_WHITE;
    }
    // Turn on or off butterfly above frog
    for (frogIndex = 0; frogIndex < ARRAY_COUNT(sEnFrPointers.frogs); frogIndex++) {
        frog = sEnFrPointers.frogs[frogIndex];
        frog->isButterflyDrawn = frogIndex == frogIndexButterfly ? true : false;
    }
}

void EnFr_DeactivateButterfly() {
    s32 frogIndex;
    EnFr* frog;

    for (frogIndex = 0; frogIndex < ARRAY_COUNT(sEnFrPointers.frogs); frogIndex++) {
        frog = sEnFrPointers.frogs[frogIndex];
        frog->isButterflyDrawn = false;
    }
}

u8 EnFr_GetNextNoteFrogSong(u8 ocarinaNoteIndex) {
    if (!(gSaveContext.eventChkInf[13] & 1)) {
        return gFrogsSongPtr[ocarinaNoteIndex];
    } else {
        return sOcarinaNotes[(s32)Rand_ZeroFloat(60.0f) % 5];
    }
}

void EnFr_SetupFrogSong(EnFr* pthis, GlobalContext* globalCtx) {
    if (pthis->frogSongTimer != 0) {
        pthis->frogSongTimer--;
    } else {
        pthis->frogSongTimer = 40;
        pthis->ocarinaNoteIndex = 0;
        func_8010BD58(globalCtx, OCARINA_ACTION_FROGS);
        pthis->ocarinaNote = EnFr_GetNextNoteFrogSong(pthis->ocarinaNoteIndex);
        EnFr_CheckOcarinaInputFrogSong(pthis->ocarinaNote);
        pthis->actionFunc = EnFr_ContinueFrogSong;
    }
}

s32 EnFr_IsFrogSongComplete(EnFr* pthis, GlobalContext* globalCtx) {
    u8 index;
    u8 ocarinaNote;
    MessageContext* msgCtx = &globalCtx->msgCtx;
    u8 ocarinaNoteIndex;

    if (pthis->ocarinaNote == (*msgCtx).lastOcaNoteIdx) { // required to match, possibly an array?
        pthis->ocarinaNoteIndex++;
        ocarinaNoteIndex = pthis->ocarinaNoteIndex;
        if (1) {}
        if (ocarinaNoteIndex >= 14) { // Frog Song is completed
            pthis->ocarinaNoteIndex = 13;
            return true;
        }
        // The first four notes have more frames to receive an input
        index = ocarinaNoteIndex < 4 ? (s32)ocarinaNoteIndex : 4;
        ocarinaNote = EnFr_GetNextNoteFrogSong(ocarinaNoteIndex);
        pthis->ocarinaNote = ocarinaNote;
        EnFr_CheckOcarinaInputFrogSong(ocarinaNote);
        pthis->frogSongTimer = sTimerFrogSong[index];
    }
    return false;
}

void EnFr_OcarinaMistake(EnFr* pthis, GlobalContext* globalCtx) {
    Message_CloseTextbox(globalCtx);
    pthis->reward = GI_NONE;
    Common_PlaySfx(NA_SE_SY_OCARINA_ERROR);
    Audio_OcaSetInstrument(0);
    sEnFrPointers.flags = 12;
    EnFr_DeactivateButterfly();
    pthis->actionFunc = EnFr_Deactivate;
}

void EnFr_ContinueFrogSong(EnFr* pthis, GlobalContext* globalCtx) {
    s32 counter;
    EnFr* frog;
    s32 i;

    if (pthis->frogSongTimer == 0) {
        EnFr_OcarinaMistake(pthis, globalCtx);
    } else {
        pthis->frogSongTimer--;
        if (globalCtx->msgCtx.msgMode == MSGMODE_FROGS_PLAYING) {
            counter = 0;
            for (i = 0; i < ARRAY_COUNT(sEnFrPointers.frogs); i++) {
                frog = sEnFrPointers.frogs[i];
                if (frog != NULL && frog->actionFunc == EnFr_ChooseJumpFromLogSpot) {
                    continue;
                } else {
                    counter++;
                }
            }
            if (counter == 0 && CHECK_BTN_ALL(globalCtx->state.input[0].press.button, BTN_B)) {
                EnFr_OcarinaMistake(pthis, globalCtx);
                return;
            }
        }

        if (globalCtx->msgCtx.msgMode == MSGMODE_FROGS_WAITING) {
            globalCtx->msgCtx.msgMode = MSGMODE_FROGS_START;
            switch (globalCtx->msgCtx.lastOcaNoteIdx) {
                case OCARINA_NOTE_A:
                    EnFr_SetupJumpingUp(pthis, FROG_BLUE);
                    break;
                case OCARINA_NOTE_C_DOWN:
                    EnFr_SetupJumpingUp(pthis, FROG_YELLOW);
                    break;
                case OCARINA_NOTE_C_RIGHT:
                    EnFr_SetupJumpingUp(pthis, FROG_RED);
                    break;
                case OCARINA_NOTE_C_LEFT:
                    EnFr_SetupJumpingUp(pthis, FROG_PURPLE);
                    break;
                case OCARINA_NOTE_C_UP:
                    EnFr_SetupJumpingUp(pthis, FROG_WHITE);
            }
            if (EnFr_IsFrogSongComplete(pthis, globalCtx)) {
                pthis->actor.textId = 0x40AC;
                EnFr_SetupReward(pthis, globalCtx, false);
            }
        }
    }
}

void EnFr_SetupReward(EnFr* pthis, GlobalContext* globalCtx, u8 unkCondition) {
    EnFr_DeactivateButterfly();
    if (unkCondition) {
        Common_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
    } else {
        Common_PlaySfx(NA_SE_SY_CORRECT_CHIME);
    }

    Audio_OcaSetInstrument(0);
    globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
    pthis->actionFunc = EnFr_PrintTextBox;
}

void EnFr_PrintTextBox(EnFr* pthis, GlobalContext* globalCtx) {
    Message_StartTextbox(globalCtx, pthis->actor.textId, &pthis->actor);
    pthis->actionFunc = EnFr_TalkBeforeReward;
}

void EnFr_TalkBeforeReward(EnFr* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        pthis->frogSongTimer = 100;
        Message_CloseTextbox(globalCtx);
        pthis->actionFunc = EnFr_SetReward;
    }
}

void EnFr_SetReward(EnFr* pthis, GlobalContext* globalCtx) {
    u16 songIndex;

    sEnFrPointers.flags = 12;
    songIndex = pthis->songIndex;
    pthis->actionFunc = EnFr_Deactivate;
    pthis->reward = GI_NONE;
    if ((songIndex >= FROG_ZL) && (songIndex <= FROG_SOT)) {
        if (!(gSaveContext.eventChkInf[13] & sSongIndex[songIndex])) {
            gSaveContext.eventChkInf[13] |= sSongIndex[songIndex];
            pthis->reward = GI_RUPEE_PURPLE;
        } else {
            pthis->reward = GI_RUPEE_BLUE;
        }
    } else if (songIndex == FROG_STORMS) {
        if (!(gSaveContext.eventChkInf[13] & sSongIndex[songIndex])) {
            gSaveContext.eventChkInf[13] |= sSongIndex[songIndex];
            pthis->reward = GI_HEART_PIECE;
        } else {
            pthis->reward = GI_RUPEE_BLUE;
        }
    } else if (songIndex == FROG_CHOIR_SONG) {
        if (!(gSaveContext.eventChkInf[13] & sSongIndex[songIndex])) {
            gSaveContext.eventChkInf[13] |= sSongIndex[songIndex];
            pthis->reward = GI_HEART_PIECE;
        } else {
            pthis->reward = GI_RUPEE_PURPLE;
        }
    }
}

void EnFr_Deactivate(EnFr* pthis, GlobalContext* globalCtx) {
    EnFr* frogLoop1;
    EnFr* frogLoop2;
    s32 frogIndex;

    // Originally was going to have separate butterfly actor
    // Changed to include butterfly as part of frog actor
    // This unused code would have frozen the butterfly actor above frog
    if (pthis->unusedButterflyActor != NULL) {
        pthis->unusedButterflyActor->freezeTimer = 10;
    }

    for (frogIndex = 0; frogIndex < ARRAY_COUNT(sEnFrPointers.frogs); frogIndex++) {
        frogLoop1 = sEnFrPointers.frogs[frogIndex];
        if (frogLoop1 == NULL) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "There are no frogs!?"
            osSyncPrintf("%s[%d]カエルがいない！？\n", "../z_en_fr.c", 1604);
            osSyncPrintf(VT_RST);
            return;
        } else if (frogLoop1->isDeactivating != true) {
            return;
        }
    }

    for (frogIndex = 0; frogIndex < ARRAY_COUNT(sEnFrPointers.frogs); frogIndex++) {
        frogLoop2 = sEnFrPointers.frogs[frogIndex];
        if (frogLoop2 == NULL) {
            osSyncPrintf(VT_COL(RED, WHITE));
            // "There are no frogs!?"
            osSyncPrintf("%s[%d]カエルがいない！？\n", "../z_en_fr.c", 1618);
            osSyncPrintf(VT_RST);
            return;
        }
        frogLoop2->isDeactivating = false;
    }

    globalCtx->msgCtx.ocarinaMode = OCARINA_MODE_04;
    Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_FROG_CRY_0);
    if (pthis->reward == GI_NONE) {
        pthis->actionFunc = EnFr_Idle;
    } else {
        pthis->actionFunc = EnFr_GiveReward;
        func_8002F434(&pthis->actor, globalCtx, pthis->reward, 30.0f, 100.0f);
    }
}

void EnFr_GiveReward(EnFr* pthis, GlobalContext* globalCtx) {
    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->actor.parent = NULL;
        pthis->actionFunc = EnFr_SetIdle;
    } else {
        func_8002F434(&pthis->actor, globalCtx, pthis->reward, 30.0f, 100.0f);
    }
}

void EnFr_SetIdle(EnFr* pthis, GlobalContext* globalCtx) {
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_DONE) && Message_ShouldAdvance(globalCtx)) {
        pthis->actionFunc = EnFr_Idle;
    }
}

void EnFr_UpdateIdle(Actor* thisx, GlobalContext* globalCtx) {
    EnFr* pthis = (EnFr*)thisx;

    pthis->jumpCounter++;
    pthis->actionFunc(pthis, globalCtx);
}

s32 EnFr_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    if ((limbIndex == 7) || (limbIndex == 8)) {
        *dList = NULL;
    }
    return 0;
}

void EnFr_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnFr* pthis = (EnFr*)thisx;

    if ((limbIndex == 7) || (limbIndex == 8)) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fr.c", 1735);
        Matrix_Push();
        func_800D1FD4(&globalCtx->billboardMtxF);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_fr.c", 1738),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, *dList);
        Matrix_Pop();
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fr.c", 1741);
    }
}

void EnFr_Draw(Actor* thisx, GlobalContext* globalCtx) {
    s16 lightRadius;
    EnFr* pthis = (EnFr*)thisx;
    s16 frogIndex = pthis->actor.params - 1;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_fr.c", 1754);
    func_80093D18(globalCtx->state.gfxCtx);
    // For the frogs 2 HP, the frog with the next note and the butterfly lights up
    lightRadius = pthis->isButterflyDrawn ? 95 : -1;
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
    Lights_PointNoGlowSetInfo(&pthis->lightInfo, pthis->posButterflyLight.x, pthis->posButterflyLight.y,
                              pthis->posButterflyLight.z, 255, 255, 255, lightRadius);
    gDPSetEnvColor(POLY_OPA_DISP++, sEnFrColor[frogIndex].r, sEnFrColor[frogIndex].g, sEnFrColor[frogIndex].b, 255);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures_137[pthis->eyeTexIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTextures_137[pthis->eyeTexIndex]));
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          EnFr_OverrideLimbDraw, EnFr_PostLimbDraw, pthis);
    if (pthis->isButterflyDrawn) {
        Matrix_Translate(pthis->posButterfly.x, pthis->posButterfly.y, pthis->posButterfly.z, MTXMODE_NEW);
        Matrix_Scale(0.015f, 0.015f, 0.015f, MTXMODE_APPLY);
        Matrix_RotateZYX(pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, MTXMODE_APPLY);
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnimeButterfly.skeleton, pthis->skelAnimeButterfly.jointTable, NULL, NULL,
                          NULL);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_fr.c", 1816);
}

void EnFr_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sEnFrPointers = {
        0x00,
        {
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
        },
    };

    En_Fr_InitVars = {
        ACTOR_EN_FR,
        ACTORCAT_NPC,
        FLAGS,
        OBJECT_FR,
        sizeof(EnFr),
        (ActorFunc)EnFr_Init,
        (ActorFunc)EnFr_Destroy,
        (ActorFunc)EnFr_Update,
        NULL,
        (ActorFunc)EnFr_Reset,
    };

}

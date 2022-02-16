#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_BOX_Z_EN_BOX_C
#include "actor_common.h"
#include "z_en_box.h"
#include "objects/object_box/object_box.h"
#include "def/code_80043480.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sys_math3d.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS 0

// movement flags

/*
set on init unless treasure flag is set
if clear, chest moves (Actor_MoveForward) (falls, likely)
ends up cleared from SWITCH_FLAG_FALL types when switch flag is set
*/
#define ENBOX_MOVE_IMMOBILE (1 << 0)
/*
set in the logic for SWITCH_FLAG_FALL types
otherwise unused
*/
#define ENBOX_MOVE_UNUSED (1 << 1)
/*
set with 50% chance on init for SWITCH_FLAG_FALL types
only used for SWITCH_FLAG_FALL types
ends up "blinking" (set/clear every frame) once switch flag is set,
if some collision-related condition (?) is met
only used for signum of z rotation
*/
#define ENBOX_MOVE_FALL_ANGLE_SIDE (1 << 2)
/*
when set, gets cleared next EnBox_Update call and clip to the floor
*/
#define ENBOX_MOVE_STICK_TO_GROUND (1 << 4)


void EnBox_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnBox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBox_FallOnSwitchFlag(EnBox*, GlobalContext*);
void func_809C9700(EnBox*, GlobalContext*);
void EnBox_AppearOnSwitchFlag(EnBox*, GlobalContext*);
void EnBox_AppearOnRoomClear(EnBox*, GlobalContext*);
void EnBox_AppearInit(EnBox*, GlobalContext*);
void EnBox_AppearAnimation(EnBox*, GlobalContext*);
void EnBox_WaitOpen(EnBox*, GlobalContext*);
void EnBox_Open(EnBox*, GlobalContext*);

ActorInit En_Box_InitVars = {
    ACTOR_EN_BOX,
    ACTORCAT_CHEST,
    FLAGS,
    OBJECT_BOX,
    sizeof(EnBox),
    (ActorFunc)EnBox_Init,
    (ActorFunc)EnBox_Destroy,
    (ActorFunc)EnBox_Update,
    (ActorFunc)EnBox_Draw,
    (ActorFunc)EnBox_Reset,
};

static AnimationHeader* sAnimations[4] = { &gTreasureChestAnim_00024C, &gTreasureChestAnim_000128,
                                           &gTreasureChestAnim_00043C, &gTreasureChestAnim_00043C };

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 0, ICHAIN_STOP),
};

static UNK_TYPE sUnused;

void EnBox_SetupAction(EnBox* pthis, EnBoxActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnBox_ClipToGround(EnBox* pthis, GlobalContext* globalCtx) {
    f32 newY;
    CollisionPoly* poly;
    s32 bgId;
    Vec3f pos;

    pos = pthis->dyna.actor.world.pos;
    pos.y += 1.0f;
    newY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &poly, &bgId, &pthis->dyna.actor, &pos);
    if (newY != BGCHECK_Y_MIN) {
        pthis->dyna.actor.world.pos.y = newY;
    }
}

void EnBox_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnBox* pthis = (EnBox*)thisx;
    AnimationHeader* anim;
    CollisionHeader* colHeader;
    f32 animFrameStart;
    f32 endFrame;

    animFrameStart = 0.0f;
    anim = sAnimations[((void)0, gSaveContext.linkAge)];
    colHeader = NULL;
    endFrame = Animation_GetLastFrame(anim);
    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gTreasureChestCol, &colHeader);
    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);
    func_8003ECA8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);

    pthis->movementFlags = 0;
    pthis->type = thisx->params >> 12 & 0xF;
    pthis->iceSmokeTimer = 0;
    pthis->unk_1FB = ENBOX_STATE_0;
    pthis->dyna.actor.gravity = -5.5f;
    pthis->switchFlag = pthis->dyna.actor.world.rot.z;
    pthis->dyna.actor.minVelocityY = -50.0f;

    if (globalCtx) {} // helps the compiler store globalCtx2 into s1

    if (Flags_GetTreasure(globalCtx, pthis->dyna.actor.params & 0x1F)) {
        pthis->alpha = 255;
        pthis->iceSmokeTimer = 100;
        EnBox_SetupAction(pthis, EnBox_Open);
        pthis->movementFlags |= ENBOX_MOVE_STICK_TO_GROUND;
        animFrameStart = endFrame;
    } else if ((pthis->type == ENBOX_TYPE_SWITCH_FLAG_FALL_BIG || pthis->type == ENBOX_TYPE_SWITCH_FLAG_FALL_SMALL) &&
               !Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        if (Rand_ZeroOne() < 0.5f) {
            pthis->movementFlags |= ENBOX_MOVE_FALL_ANGLE_SIDE;
        }
        pthis->unk_1A8 = -12;
        EnBox_SetupAction(pthis, EnBox_FallOnSwitchFlag);
        pthis->alpha = 0;
        pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
    } else if ((pthis->type == ENBOX_TYPE_ROOM_CLEAR_BIG || pthis->type == ENBOX_TYPE_ROOM_CLEAR_SMALL) &&
               !Flags_GetClear(globalCtx, pthis->dyna.actor.room)) {
        EnBox_SetupAction(pthis, EnBox_AppearOnRoomClear);
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 50.0f;
        pthis->alpha = 0;
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
    } else if (pthis->type == ENBOX_TYPE_9 || pthis->type == ENBOX_TYPE_10) {
        EnBox_SetupAction(pthis, func_809C9700);
        pthis->dyna.actor.flags |= ACTOR_FLAG_25;
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 50.0f;
        pthis->alpha = 0;
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
    } else if (pthis->type == ENBOX_TYPE_SWITCH_FLAG_BIG && !Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        EnBox_SetupAction(pthis, EnBox_AppearOnSwitchFlag);
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
        pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y - 50.0f;
        pthis->alpha = 0;
        pthis->dyna.actor.flags |= ACTOR_FLAG_4;
    } else {
        if (pthis->type == ENBOX_TYPE_4 || pthis->type == ENBOX_TYPE_6) {
            pthis->dyna.actor.flags |= ACTOR_FLAG_7;
        }
        EnBox_SetupAction(pthis, EnBox_WaitOpen);
        pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
        pthis->movementFlags |= ENBOX_MOVE_STICK_TO_GROUND;
    }

    pthis->dyna.actor.world.rot.y += 0x8000;
    pthis->dyna.actor.home.rot.z = pthis->dyna.actor.world.rot.z = pthis->dyna.actor.shape.rot.z = 0;

    SkelAnime_Init(globalCtx, &pthis->skelanime, &gTreasureChestSkel, anim, pthis->jointTable, pthis->morphTable, 5);
    Animation_Change(&pthis->skelanime, anim, 1.5f, animFrameStart, endFrame, ANIMMODE_ONCE, 0.0f);

    switch (pthis->type) {
        case ENBOX_TYPE_SMALL:
        case ENBOX_TYPE_6:
        case ENBOX_TYPE_ROOM_CLEAR_SMALL:
        case ENBOX_TYPE_SWITCH_FLAG_FALL_SMALL:
            Actor_SetScale(&pthis->dyna.actor, 0.005f);
            Actor_SetFocus(&pthis->dyna.actor, 20.0f);
            break;
        default:
            Actor_SetScale(&pthis->dyna.actor, 0.01f);
            Actor_SetFocus(&pthis->dyna.actor, 40.0f);
    }
}

void EnBox_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnBox* pthis = (EnBox*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void EnBox_RandomDustKinematic(EnBox* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel) {
    f32 randomRadius = Rand_ZeroOne() * 25.0f;
    s16 randomAngle = Rand_ZeroOne() * 0x10000;

    *pos = pthis->dyna.actor.world.pos;
    pos->x += Math_SinS(randomAngle) * randomRadius;
    pos->z += Math_CosS(randomAngle) * randomRadius;

    velocity->y = 1.0f;
    velocity->x = Math_SinS(randomAngle);
    velocity->z = Math_CosS(randomAngle);

    accel->x = 0.0f;
    accel->y = 0.0f;
    accel->z = 0.0f;
}

/**
 * Spawns dust randomly around the chest when the chest hits the ground after falling (FALL types)
 */
void EnBox_SpawnDust(EnBox* pthis, GlobalContext* globalCtx) {
    s32 i;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;

    for (i = 0; i < 20; i++) {
        EnBox_RandomDustKinematic(pthis, &pos, &velocity, &accel);
        func_8002873C(globalCtx, &pos, &velocity, &accel, 100, 30, 15);
    }
}

/**
 * Used while the chest is falling (FALL types)
 */
void EnBox_Fall(EnBox* pthis, GlobalContext* globalCtx) {
    f32 yDiff;

    pthis->alpha = 255;
    pthis->movementFlags &= ~ENBOX_MOVE_IMMOBILE;
    if (pthis->dyna.actor.bgCheckFlags & 1) {
        pthis->movementFlags |= ENBOX_MOVE_UNUSED;
        if (pthis->movementFlags & ENBOX_MOVE_FALL_ANGLE_SIDE) {
            pthis->movementFlags &= ~ENBOX_MOVE_FALL_ANGLE_SIDE;
        } else {
            pthis->movementFlags |= ENBOX_MOVE_FALL_ANGLE_SIDE;
        }
        if (pthis->type == ENBOX_TYPE_SWITCH_FLAG_FALL_BIG) {
            pthis->dyna.actor.velocity.y = -pthis->dyna.actor.velocity.y * 0.55f;
        } else {
            pthis->dyna.actor.velocity.y = -pthis->dyna.actor.velocity.y * 0.65f;
        }
        if (pthis->dyna.actor.velocity.y < 5.5f) {
            pthis->dyna.actor.shape.rot.z = 0;
            pthis->dyna.actor.world.pos.y = pthis->dyna.actor.floorHeight;
            EnBox_SetupAction(pthis, EnBox_WaitOpen);
            OnePointCutscene_EndCutscene(globalCtx, pthis->unk_1AC);
        }
        Audio_PlaySoundGeneral(NA_SE_EV_COFFIN_CAP_BOUND, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        EnBox_SpawnDust(pthis, globalCtx);
    }
    yDiff = pthis->dyna.actor.world.pos.y - pthis->dyna.actor.floorHeight;
    if (pthis->movementFlags & ENBOX_MOVE_FALL_ANGLE_SIDE) {
        pthis->dyna.actor.shape.rot.z = yDiff * 50.0f;
    } else {
        pthis->dyna.actor.shape.rot.z = -yDiff * 50.0f;
    }
}

void EnBox_FallOnSwitchFlag(EnBox* pthis, GlobalContext* globalCtx) {
    s32 treasureFlag = pthis->dyna.actor.params & 0x1F;

    if (treasureFlag >= ENBOX_TREASURE_FLAG_UNK_MIN && treasureFlag < ENBOX_TREASURE_FLAG_UNK_MAX) {
        func_8002F5F0(&pthis->dyna.actor, globalCtx);
    }

    if (pthis->unk_1A8 >= 0) {
        EnBox_SetupAction(pthis, EnBox_Fall);
        pthis->unk_1AC = OnePointCutscene_Init(globalCtx, 4500, 9999, &pthis->dyna.actor, MAIN_CAM);
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    } else if (pthis->unk_1A8 >= -11) {
        pthis->unk_1A8++;
    } else if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        pthis->unk_1A8++;
    }
}

// used for types 9, 10
void func_809C9700(EnBox* pthis, GlobalContext* globalCtx) {
    s32 treasureFlag = pthis->dyna.actor.params & 0x1F;
    Player* player = GET_PLAYER(globalCtx);

    if (treasureFlag >= ENBOX_TREASURE_FLAG_UNK_MIN && treasureFlag < ENBOX_TREASURE_FLAG_UNK_MAX) {
        func_8002F5F0(&pthis->dyna.actor, globalCtx);
    }

    if (Math3D_Vec3fDistSq(&pthis->dyna.actor.world.pos, &player->actor.world.pos) > 22500.0f) {
        pthis->unk_1FB = ENBOX_STATE_0;
    } else {
        if (pthis->unk_1FB == ENBOX_STATE_0) {
            if (!(player->stateFlags2 & 0x1000000)) {
                player->stateFlags2 |= 0x800000;
                return;
            }
            pthis->unk_1FB = ENBOX_STATE_1;
        }

        if (pthis->unk_1FB == ENBOX_STATE_1) {
            func_8010BD58(globalCtx, OCARINA_ACTION_FREE_PLAY);
            pthis->unk_1FB = ENBOX_STATE_2;
        } else if (pthis->unk_1FB == ENBOX_STATE_2 && globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
            if ((globalCtx->msgCtx.lastPlayedSong == OCARINA_SONG_LULLABY && pthis->type == ENBOX_TYPE_9) ||
                (globalCtx->msgCtx.lastPlayedSong == OCARINA_SONG_SUNS && pthis->type == ENBOX_TYPE_10)) {
                pthis->dyna.actor.flags &= ~ACTOR_FLAG_25;
                EnBox_SetupAction(pthis, EnBox_AppearInit);
                OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
                pthis->unk_1A8 = 0;
                pthis->unk_1FB = ENBOX_STATE_0;
            } else {
                pthis->unk_1FB = ENBOX_STATE_0;
            }
        }
    }
}

void EnBox_AppearOnSwitchFlag(EnBox* pthis, GlobalContext* globalCtx) {
    s32 treasureFlag = pthis->dyna.actor.params & 0x1F;

    if (treasureFlag >= ENBOX_TREASURE_FLAG_UNK_MIN && treasureFlag < ENBOX_TREASURE_FLAG_UNK_MAX) {
        func_8002F5F0(&pthis->dyna.actor, globalCtx);
    }

    if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        EnBox_SetupAction(pthis, EnBox_AppearInit);
        pthis->unk_1A8 = -30;
    }
}

void EnBox_AppearOnRoomClear(EnBox* pthis, GlobalContext* globalCtx) {
    s32 treasureFlag = pthis->dyna.actor.params & 0x1F;

    if (treasureFlag >= ENBOX_TREASURE_FLAG_UNK_MIN && treasureFlag < ENBOX_TREASURE_FLAG_UNK_MAX) {
        func_8002F5F0(&pthis->dyna.actor, globalCtx);
    }

    if (Flags_GetTempClear(globalCtx, pthis->dyna.actor.room) && !Player_InCsMode(globalCtx)) {
        Flags_SetClear(globalCtx, pthis->dyna.actor.room);
        EnBox_SetupAction(pthis, EnBox_AppearInit);
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        if (OnePointCutscene_CheckForCategory(globalCtx, pthis->dyna.actor.category)) {
            pthis->unk_1A8 = 0;
        } else {
            pthis->unk_1A8 = -30;
        }
    }
}

/**
 * The chest is ready to appear, possibly waiting for camera/cutscene-related stuff to happen
 */
void EnBox_AppearInit(EnBox* pthis, GlobalContext* globalCtx) {
    if (func_8005B198() == pthis->dyna.actor.category || pthis->unk_1A8 != 0) {
        EnBox_SetupAction(pthis, EnBox_AppearAnimation);
        pthis->unk_1A8 = 0;
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_KANKYO, pthis->dyna.actor.home.pos.x,
                    pthis->dyna.actor.home.pos.y, pthis->dyna.actor.home.pos.z, 0, 0, 0, 0x0011);
        Audio_PlaySoundGeneral(NA_SE_EV_TRE_BOX_APPEAR, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

void EnBox_AppearAnimation(EnBox* pthis, GlobalContext* globalCtx) {
    func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);

    if (pthis->unk_1A8 < 0) {
        pthis->unk_1A8++;
    } else if (pthis->unk_1A8 < 40) {
        pthis->unk_1A8++;
        pthis->dyna.actor.world.pos.y += 1.25f;
    } else if (pthis->unk_1A8 < 60) {
        pthis->alpha += 12;
        pthis->unk_1A8++;
        pthis->dyna.actor.world.pos.y = pthis->dyna.actor.home.pos.y;
    } else {
        EnBox_SetupAction(pthis, EnBox_WaitOpen);
    }
}

/**
 * Chest is ready to be open
 */
void EnBox_WaitOpen(EnBox* pthis, GlobalContext* globalCtx) {
    f32 frameCount;
    AnimationHeader* anim;
    s32 linkAge;
    s32 pad;
    Vec3f sp4C;
    Player* player;

    pthis->alpha = 255;
    pthis->movementFlags |= ENBOX_MOVE_IMMOBILE;
    if (pthis->unk_1F4 != 0) { // unk_1F4 is modified by player code
        linkAge = gSaveContext.linkAge;
        anim = sAnimations[(pthis->unk_1F4 < 0 ? 2 : 0) + linkAge];
        frameCount = Animation_GetLastFrame(anim);
        Animation_Change(&pthis->skelanime, anim, 1.5f, 0, frameCount, ANIMMODE_ONCE, 0.0f);
        EnBox_SetupAction(pthis, EnBox_Open);
        if (pthis->unk_1F4 > 0) {
            switch (pthis->type) {
                case ENBOX_TYPE_SMALL:
                case ENBOX_TYPE_6:
                case ENBOX_TYPE_ROOM_CLEAR_SMALL:
                case ENBOX_TYPE_SWITCH_FLAG_FALL_SMALL:
                    break;
                default:
                    Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->dyna.actor, globalCtx, ACTOR_DEMO_TRE_LGT,
                                       pthis->dyna.actor.world.pos.x, pthis->dyna.actor.world.pos.y,
                                       pthis->dyna.actor.world.pos.z, pthis->dyna.actor.shape.rot.x,
                                       pthis->dyna.actor.shape.rot.y, pthis->dyna.actor.shape.rot.z, 0xFFFF);
                    Audio_PlayFanfare(NA_BGM_OPEN_TRE_BOX | 0x900);
            }
        }
        osSyncPrintf("Actor_Environment_Tbox_On() %d\n", pthis->dyna.actor.params & 0x1F);
        Flags_SetTreasure(globalCtx, pthis->dyna.actor.params & 0x1F);
    } else {
        player = GET_PLAYER(globalCtx);
        func_8002DBD0(&pthis->dyna.actor, &sp4C, &player->actor.world.pos);
        if (sp4C.z > -50.0f && sp4C.z < 0.0f && fabsf(sp4C.y) < 10.0f && fabsf(sp4C.x) < 20.0f &&
            Player_IsFacingActor(&pthis->dyna.actor, 0x3000, globalCtx)) {
            func_8002F554(&pthis->dyna.actor, globalCtx, 0 - (pthis->dyna.actor.params >> 5 & 0x7F));
        }
        if (Flags_GetTreasure(globalCtx, pthis->dyna.actor.params & 0x1F)) {
            EnBox_SetupAction(pthis, EnBox_Open);
        }
    }
}

/**
 * Plays an animation to its end, playing sounds at key points
 */
void EnBox_Open(EnBox* pthis, GlobalContext* globalCtx) {
    u16 sfxId;

    pthis->dyna.actor.flags &= ~ACTOR_FLAG_7;

    if (SkelAnime_Update(&pthis->skelanime)) {
        if (pthis->unk_1F4 > 0) {
            if (pthis->unk_1F4 < 120) {
                pthis->unk_1F4++;
            } else {
                Math_StepToF(&pthis->unk_1B0, 0.0f, 0.05f);
            }
        } else {
            if (pthis->unk_1F4 > -120) {
                pthis->unk_1F4--;
            } else {
                Math_StepToF(&pthis->unk_1B0, 0.0f, 0.05f);
            }
        }
    } else {
        sfxId = 0;

        if (Animation_OnFrame(&pthis->skelanime, 30.0f)) {
            sfxId = NA_SE_EV_TBOX_UNLOCK;
        } else if (Animation_OnFrame(&pthis->skelanime, 90.0f)) {
            sfxId = NA_SE_EV_TBOX_OPEN;
        }

        if (sfxId != 0) {
            Audio_PlaySoundGeneral(sfxId, &pthis->dyna.actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }

        if (pthis->skelanime.jointTable[3].z > 0) {
            pthis->unk_1B0 = (0x7D00 - pthis->skelanime.jointTable[3].z) * 0.00006f;
            if (pthis->unk_1B0 < 0.0f) {
                pthis->unk_1B0 = 0.0f;
            } else if (pthis->unk_1B0 > 1.0f) {
                pthis->unk_1B0 = 1.0f;
            }
        }
    }
}

void EnBox_SpawnIceSmoke(EnBox* pthis, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f vel = { 0.0f, 1.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    f32 f0;

    pthis->iceSmokeTimer++;
    func_8002F974(&pthis->dyna.actor, NA_SE_EN_MIMICK_BREATH - SFX_FLAG);
    if (Rand_ZeroOne() < 0.3f) {
        f0 = 2.0f * Rand_ZeroOne() - 1.0f;
        pos = pthis->dyna.actor.world.pos;
        if (pthis->type == ENBOX_TYPE_SMALL || pthis->type == ENBOX_TYPE_6 || pthis->type == ENBOX_TYPE_ROOM_CLEAR_SMALL ||
            pthis->type == ENBOX_TYPE_SWITCH_FLAG_FALL_SMALL) {
            pos.x += f0 * 10.0f * Math_SinS(pthis->dyna.actor.world.rot.y + 0x4000);
            pos.z += f0 * 10.0f * Math_CosS(pthis->dyna.actor.world.rot.y + 0x4000);
            f0 = 2.0f * Rand_ZeroOne() - 1.0f;
            vel.x = f0 * 0.8f * Math_SinS(pthis->dyna.actor.world.rot.y);
            vel.y = 1.8f;
            vel.z = f0 * 0.8f * Math_CosS(pthis->dyna.actor.world.rot.y);
        } else {
            pos.x += f0 * 20.0f * Math_SinS(pthis->dyna.actor.world.rot.y + 0x4000);
            pos.z += f0 * 20.0f * Math_CosS(pthis->dyna.actor.world.rot.y + 0x4000);
            f0 = 2.0f * Rand_ZeroOne() - 1.0f;
            vel.x = f0 * 1.6f * Math_SinS(pthis->dyna.actor.world.rot.y);
            vel.y = 1.8f;
            vel.z = f0 * 1.6f * Math_CosS(pthis->dyna.actor.world.rot.y);
        }
        EffectSsIceSmoke_Spawn(globalCtx, &pos, &vel, &accel, 150);
    }
}

void EnBox_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnBox* pthis = (EnBox*)thisx;

    if (pthis->movementFlags & ENBOX_MOVE_STICK_TO_GROUND) {
        pthis->movementFlags &= ~ENBOX_MOVE_STICK_TO_GROUND;
        EnBox_ClipToGround(pthis, globalCtx);
    }

    pthis->actionFunc(pthis, globalCtx);

    if (!(pthis->movementFlags & ENBOX_MOVE_IMMOBILE)) {
        Actor_MoveForward(&pthis->dyna.actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->dyna.actor, 0.0f, 0.0f, 0.0f, 0x1C);
    }

    switch (pthis->type) {
        case ENBOX_TYPE_SMALL:
        case ENBOX_TYPE_6:
        case ENBOX_TYPE_ROOM_CLEAR_SMALL:
        case ENBOX_TYPE_SWITCH_FLAG_FALL_SMALL:
            Actor_SetFocus(&pthis->dyna.actor, 20.0f);
            break;
        default:
            Actor_SetFocus(&pthis->dyna.actor, 40.0f);
    }

    if ((pthis->dyna.actor.params >> 5 & 0x7F) == 0x7C && pthis->actionFunc == EnBox_Open &&
        pthis->skelanime.curFrame > 45 && pthis->iceSmokeTimer < 100) {
        EnBox_SpawnIceSmoke(pthis, globalCtx);
    }
}

void EnBox_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnBox* pthis = (EnBox*)thisx;
    s32 pad;

    if (limbIndex == 1) {
        gSPMatrix((*gfx)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_box.c", 1492),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (pthis->type != ENBOX_TYPE_DECORATED_BIG) {
            gSPDisplayList((*gfx)++, gTreasureChestChestFrontDL);
        } else {
            gSPDisplayList((*gfx)++, gTreasureChestBossKeyChestFrontDL);
        }
    } else if (limbIndex == 3) {
        gSPMatrix((*gfx)++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_box.c", 1502),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (pthis->type != ENBOX_TYPE_DECORATED_BIG) {
            gSPDisplayList((*gfx)++, gTreasureChestChestSideAndLidDL);
        } else {
            gSPDisplayList((*gfx)++, gTreasureChestBossKeyChestSideAndTopDL);
        }
    }
}

Gfx* EnBox_EmptyDList(GraphicsContext* gfxCtx) {
    Gfx* dListHead;
    Gfx* dList;

    dList = (Gfx*)Graph_Alloc(gfxCtx, sizeof(Gfx));
    ASSERT(dList != NULL, "gfxp != NULL", "../z_en_box.c", 1528);

    dListHead = dList;
    gSPEndDisplayList(dListHead++);

    return dList;
}

// set render mode with a focus on transparency
Gfx* func_809CA4A0(GraphicsContext* gfxCtx) {
    Gfx* dList;
    Gfx* dListHead;

    dListHead = (Gfx*)Graph_Alloc(gfxCtx, 2 * sizeof(Gfx));
    ASSERT(dListHead != NULL, "gfxp != NULL", "../z_en_box.c", 1546);

    dList = dListHead;
    gDPSetRenderMode(dListHead++,
                     AA_EN | Z_CMP | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                         GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA),
                     AA_EN | Z_CMP | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gSPEndDisplayList(dListHead++);

    return dList;
}

Gfx* func_809CA518(GraphicsContext* gfxCtx) {
    Gfx* dList;
    Gfx* dListHead;

    dListHead = (Gfx*)Graph_Alloc(gfxCtx, 2 * sizeof(Gfx));
    ASSERT(dListHead != NULL, "gfxp != NULL", "../z_en_box.c", 1564);

    dList = dListHead;
    gDPSetRenderMode(dListHead++,
                     AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |
                         GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA),
                     G_RM_AA_ZB_OPA_SURF2);
    gSPEndDisplayList(dListHead++);

    return dList;
}

void EnBox_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnBox* pthis = (EnBox*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_box.c", 1581);

    /*
    pthis->dyna.actor.flags & ACTOR_FLAG_7 is set by Init (if type is 4 or 6)
    and cleared by Open
    */
    if ((pthis->alpha == 255 && !(pthis->type == ENBOX_TYPE_4 || pthis->type == ENBOX_TYPE_6)) ||
        (!CHECK_FLAG_ALL(pthis->dyna.actor.flags, ACTOR_FLAG_7) &&
         (pthis->type == ENBOX_TYPE_4 || pthis->type == ENBOX_TYPE_6))) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
        gSPSegment(POLY_OPA_DISP++, 0x08, EnBox_EmptyDList(globalCtx->state.gfxCtx));
        func_80093D18(globalCtx->state.gfxCtx);
        POLY_OPA_DISP = SkelAnime_Draw(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, NULL,
                                       EnBox_PostLimbDraw, pthis, POLY_OPA_DISP);
    } else if (pthis->alpha != 0) {
        gDPPipeSync(POLY_XLU_DISP++);
        func_80093D84(globalCtx->state.gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
        if (pthis->type == ENBOX_TYPE_4 || pthis->type == ENBOX_TYPE_6) {
            gSPSegment(POLY_XLU_DISP++, 0x08, func_809CA518(globalCtx->state.gfxCtx));
        } else {
            gSPSegment(POLY_XLU_DISP++, 0x08, func_809CA4A0(globalCtx->state.gfxCtx));
        }
        POLY_XLU_DISP = SkelAnime_Draw(globalCtx, pthis->skelanime.skeleton, pthis->skelanime.jointTable, NULL,
                                       EnBox_PostLimbDraw, pthis, POLY_XLU_DISP);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_box.c", 1639);
}

void EnBox_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Box_InitVars = {
        ACTOR_EN_BOX,
        ACTORCAT_CHEST,
        FLAGS,
        OBJECT_BOX,
        sizeof(EnBox),
        (ActorFunc)EnBox_Init,
        (ActorFunc)EnBox_Destroy,
        (ActorFunc)EnBox_Update,
        (ActorFunc)EnBox_Draw,
        (ActorFunc)EnBox_Reset,
    };

    sUnused = {0};

}

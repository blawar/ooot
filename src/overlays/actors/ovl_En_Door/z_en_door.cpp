#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DOOR_Z_EN_DOOR_C
#include "actor_common.h"
/*
 * File: z_en_door.c
 * Overlay: ovl_En_Door
 * Description: Doors with handles
 */

#include "z_en_door.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "objects/object_haka_door/object_haka_door.h"
#include "def/code_800FD970.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

#define DOOR_AJAR_SLAM_RANGE 120.0f
#define DOOR_AJAR_OPEN_RANGE (2 * DOOR_AJAR_SLAM_RANGE)

#define DOOR_CHECK_RANGE 40.0f

void EnDoor_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDoor_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDoor_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDoor_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnDoor_SetupType(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_Idle(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_WaitForCheck(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_Check(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_AjarWait(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_AjarOpen(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_AjarClose(EnDoor* pthis, GlobalContext* globalCtx);
void EnDoor_Open(EnDoor* pthis, GlobalContext* globalCtx);

ActorInit En_Door_InitVars = {
    ACTOR_EN_DOOR,
    ACTORCAT_DOOR,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDoor),
    (ActorFunc)EnDoor_Init,
    (ActorFunc)EnDoor_Destroy,
    (ActorFunc)EnDoor_Update,
    (ActorFunc)EnDoor_Draw,
};

/**
 * Controls which object and display lists to use in a given scene
 */
static EnDoorInfo sDoorInfo[] = {
    { SCENE_HIDAN, 1, OBJECT_HIDAN_OBJECTS },
    { SCENE_MIZUSIN, 2, OBJECT_MIZU_OBJECTS },
    { SCENE_HAKADAN, 3, OBJECT_HAKA_DOOR },
    { SCENE_HAKADANCH, 3, OBJECT_HAKA_DOOR },
    // KEEP objects should remain last and in pthis order
    { -1, 0, OBJECT_GAMEPLAY_KEEP },
    { -1, 4, OBJECT_GAMEPLAY_FIELD_KEEP },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_STOP),
};

static AnimationHeader* D_809FCECC[] = { &gDoor3Anim, &gDoor1Anim, &gDoor4Anim, &gDoor2Anim };

static u8 sDoorAnimOpenFrames[] = { 25, 25, 25, 25 };

static u8 sDoorAnimCloseFrames[] = { 60, 70, 60, 70 };

static Gfx* D_809FCEE4[5][2] = {
    { gDoorLeftDL, gDoorRightDL },
    { gFireTempleDoorWithHandleFrontDL, gFireTempleDoorWithHandleBackDL },
    { gWaterTempleDoorLeftDL, gWaterTempleDoorRightDL },
    { object_haka_door_DL_0013B8, object_haka_door_DL_001420 },
    { gFieldDoor1DL, gFieldDoor2DL },
};

void EnDoor_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnDoor* pthis = (EnDoor*)thisx;
    EnDoorInfo* objectInfo;
    s32 i;
    s32 objBankIndex;
    f32 xOffset;
    f32 zOffset;

    objectInfo = &sDoorInfo[0];
    Actor_ProcessInitChain(&pthis->actor, sInitChain);
    SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDoorSkel, &gDoor3Anim, pthis->jointTable, pthis->morphTable, 5);
    for (i = 0; i < ARRAY_COUNT(sDoorInfo) - 2; i++, objectInfo++) {
        if (globalCtx->sceneNum == objectInfo->sceneNum) {
            break;
        }
    }
    if (i >= ARRAY_COUNT(sDoorInfo) - 2 && Object_GetIndex(&globalCtx->objectCtx, OBJECT_GAMEPLAY_FIELD_KEEP) >= 0) {
        objectInfo++;
    }

    pthis->dListIndex = objectInfo->dListIndex;
    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, objectInfo->objectId);
    if (objBankIndex < 0) {
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->requiredObjBankIndex = objBankIndex;
    pthis->dListIndex = objectInfo->dListIndex;
    if (pthis->actor.objBankIndex == pthis->requiredObjBankIndex) {
        EnDoor_SetupType(pthis, globalCtx);
    } else {
        pthis->actionFunc = EnDoor_SetupType;
    }

    // Double doors
    if (pthis->actor.params & 0x40) {
        EnDoor* other;

        xOffset = Math_CosS(pthis->actor.shape.rot.y) * 30.0f;
        zOffset = Math_SinS(pthis->actor.shape.rot.y) * 30.0f;
        other = (EnDoor*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_DOOR,
                                            pthis->actor.world.pos.x + xOffset, pthis->actor.world.pos.y,
                                            pthis->actor.world.pos.z - zOffset, 0, pthis->actor.shape.rot.y + 0x8000, 0,
                                            pthis->actor.params & ~0x40);
        if (other != NULL) {
            other->unk_192 = 1;
        }
        pthis->actor.world.pos.x -= xOffset;
        pthis->actor.world.pos.z += zOffset;
    }
    Actor_SetFocus(&pthis->actor, 70.0f);
}

void EnDoor_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    TransitionActorEntry* transitionEntry;
    EnDoor* pthis = (EnDoor*)thisx;

    transitionEntry = &globalCtx->transiActorCtx.list[(u16)pthis->actor.params >> 0xA];
    if (transitionEntry->id < 0) {
        transitionEntry->id = -transitionEntry->id;
    }
}

void EnDoor_SetupType(EnDoor* pthis, GlobalContext* globalCtx) {
    s32 doorType;

    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->requiredObjBankIndex)) {
        doorType = pthis->actor.params >> 7 & 7;
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.objBankIndex = pthis->requiredObjBankIndex;
        pthis->actionFunc = EnDoor_Idle;
        if (doorType == DOOR_EVENING) {
            doorType =
                (gSaveContext.dayTime > 0xC000 && gSaveContext.dayTime < 0xE000) ? DOOR_SCENEEXIT : DOOR_CHECKABLE;
        }
        pthis->actor.world.rot.y = 0x0000;
        if (doorType == DOOR_LOCKED) {
            if (!Flags_GetSwitch(globalCtx, pthis->actor.params & 0x3F)) {
                pthis->lockTimer = 10;
            }
        } else if (doorType == DOOR_AJAR) {
            if (Actor_WorldDistXZToActor(&pthis->actor, &GET_PLAYER(globalCtx)->actor) > DOOR_AJAR_SLAM_RANGE) {
                pthis->actionFunc = EnDoor_AjarWait;
                pthis->actor.world.rot.y = -0x1800;
            }
        } else if (doorType == DOOR_CHECKABLE) {
            pthis->actor.textId = (pthis->actor.params & 0x3F) + 0x0200;
            if (pthis->actor.textId == 0x0229 && !(gSaveContext.eventChkInf[1] & 0x10)) {
                // Talon's house door. If Talon has not been woken up at Hyrule Castle
                // pthis door should be openable at any time of day. Note that there is no
                // check for time of day as the scene setup for Lon Lon merely initializes
                // the door with a different text id between day and night setups
                doorType = DOOR_SCENEEXIT;
            } else {
                pthis->actionFunc = EnDoor_WaitForCheck;
                pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_27;
            }
        }
        // Replace the door type it was loaded with by the new type
        pthis->actor.params = (pthis->actor.params & ~0x380) | (doorType << 7);
    }
}

void EnDoor_Idle(EnDoor* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 doorType;
    Vec3f playerPosRelToDoor;
    s16 phi_v0;

    doorType = pthis->actor.params >> 7 & 7;
    func_8002DBD0(&pthis->actor, &playerPosRelToDoor, &player->actor.world.pos);
    if (pthis->playerIsOpening != 0) {
        pthis->actionFunc = EnDoor_Open;
        Animation_PlayOnceSetSpeed(&pthis->skelAnime, D_809FCECC[pthis->animStyle],
                                   (player->stateFlags1 & 0x8000000) ? 0.75f : 1.5f);
        if (pthis->lockTimer != 0) {
            gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex]--;
            Flags_SetSwitch(globalCtx, pthis->actor.params & 0x3F);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_CHAIN_KEY_UNLOCK);
        }
    } else if (!Player_InCsMode(globalCtx)) {
        if (fabsf(playerPosRelToDoor.y) < 20.0f && fabsf(playerPosRelToDoor.x) < 20.0f &&
            fabsf(playerPosRelToDoor.z) < 50.0f) {
            phi_v0 = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
            if (playerPosRelToDoor.z > 0.0f) {
                phi_v0 = 0x8000 - phi_v0;
            }
            if (ABS(phi_v0) < 0x3000) {
                if (pthis->lockTimer != 0) {
                    if (gSaveContext.inventory.dungeonKeys[gSaveContext.mapIndex] <= 0) {
                        Player* player2 = GET_PLAYER(globalCtx);

                        player2->naviTextId = -0x203;
                        return;
                    } else {
                        player->doorTimer = 10;
                    }
                }
                player->doorType = (doorType == DOOR_AJAR) ? PLAYER_DOORTYPE_AJAR : PLAYER_DOORTYPE_HANDLE;
                player->doorDirection = (playerPosRelToDoor.z >= 0.0f) ? 1.0f : -1.0f;
                player->doorActor = &pthis->actor;
            }
        } else if (doorType == DOOR_AJAR && pthis->actor.xzDistToPlayer > DOOR_AJAR_OPEN_RANGE) {
            pthis->actionFunc = EnDoor_AjarOpen;
        }
    }
}

void EnDoor_WaitForCheck(EnDoor* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDoor_Check;
    } else {
        func_8002F2CC(&pthis->actor, globalCtx, DOOR_CHECK_RANGE);
    }
}

void EnDoor_Check(EnDoor* pthis, GlobalContext* globalCtx) {
    if (Actor_TextboxIsClosing(&pthis->actor, globalCtx)) {
        pthis->actionFunc = EnDoor_WaitForCheck;
    }
}

void EnDoor_AjarWait(EnDoor* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer < DOOR_AJAR_SLAM_RANGE) {
        pthis->actionFunc = EnDoor_AjarClose;
    }
}

void EnDoor_AjarOpen(EnDoor* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer < DOOR_AJAR_SLAM_RANGE) {
        pthis->actionFunc = EnDoor_AjarClose;
    } else if (Math_ScaledStepToS(&pthis->actor.world.rot.y, -0x1800, 0x100)) {
        pthis->actionFunc = EnDoor_AjarWait;
    }
}

void EnDoor_AjarClose(EnDoor* pthis, GlobalContext* globalCtx) {
    if (Math_ScaledStepToS(&pthis->actor.world.rot.y, 0, 0x700)) {
        pthis->actionFunc = EnDoor_Idle;
    }
}

void EnDoor_Open(EnDoor* pthis, GlobalContext* globalCtx) {
    s32 i;
    s32 numEffects;

    if (DECR(pthis->lockTimer) == 0) {
        if (SkelAnime_Update(&pthis->skelAnime)) {
            pthis->actionFunc = EnDoor_Idle;
            pthis->playerIsOpening = 0;
        } else if (Animation_OnFrame(&pthis->skelAnime, sDoorAnimOpenFrames[pthis->animStyle])) {
            Audio_PlayActorSound2(&pthis->actor,
                                  (globalCtx->sceneNum == SCENE_HAKADAN || globalCtx->sceneNum == SCENE_HAKADANCH ||
                                   globalCtx->sceneNum == SCENE_HIDAN)
                                      ? NA_SE_EV_IRON_DOOR_OPEN
                                      : NA_SE_OC_DOOR_OPEN);
            if (pthis->skelAnime.playSpeed < 1.5f) {
                numEffects = (s32)(Rand_ZeroOne() * 30.0f) + 50;
                for (i = 0; i < numEffects; i++) {
                    EffectSsBubble_Spawn(globalCtx, &pthis->actor.world.pos, 60.0f, 100.0f, 50.0f, 0.15f);
                }
            }
        } else if (Animation_OnFrame(&pthis->skelAnime, sDoorAnimCloseFrames[pthis->animStyle])) {
            Audio_PlayActorSound2(&pthis->actor,
                                  (globalCtx->sceneNum == SCENE_HAKADAN || globalCtx->sceneNum == SCENE_HAKADANCH ||
                                   globalCtx->sceneNum == SCENE_HIDAN)
                                      ? NA_SE_EV_IRON_DOOR_CLOSE
                                      : NA_SE_EV_DOOR_CLOSE);
        }
    }
}

void EnDoor_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnDoor* pthis = (EnDoor*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

s32 EnDoor_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    s32 pad;
    TransitionActorEntry* transitionEntry;
    Gfx** temp_a2;
    s32 pad2;
    s16 phi_v0_2;
    s32 phi_v0;
    EnDoor* pthis = (EnDoor*)thisx;

    if (limbIndex == 4) {
        temp_a2 = D_809FCEE4[pthis->dListIndex];
        transitionEntry = &globalCtx->transiActorCtx.list[(u16)pthis->actor.params >> 0xA];
        rot->z += pthis->actor.world.rot.y;
        if ((globalCtx->roomCtx.prevRoom.num >= 0) ||
            (transitionEntry->sides[0].room == transitionEntry->sides[1].room)) {
            phi_v0_2 = ((pthis->actor.shape.rot.y + pthis->skelAnime.jointTable[3].z) + rot->z) -
                       Math_Vec3f_Yaw(&globalCtx->view.eye, &pthis->actor.world.pos);
            *dList = (ABS(phi_v0_2) < 0x4000) ? temp_a2[0] : temp_a2[1];
        } else {
            phi_v0 = pthis->unk_192;
            if (transitionEntry->sides[0].room != pthis->actor.room) {
                phi_v0 ^= 1;
            }
            *dList = temp_a2[phi_v0];
        }
    }
    return false;
}

void EnDoor_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnDoor* pthis = (EnDoor*)thisx;

    if (pthis->actor.objBankIndex == pthis->requiredObjBankIndex) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_door.c", 910);

        func_80093D18(globalCtx->state.gfxCtx);
        SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnDoor_OverrideLimbDraw,
                          NULL, &pthis->actor);
        if (pthis->actor.world.rot.y != 0) {
            if (1) {}
            if (pthis->actor.world.rot.y > 0) {
                gSPDisplayList(POLY_OPA_DISP++, gDoorRightDL);
            } else {
                gSPDisplayList(POLY_OPA_DISP++, gDoorLeftDL);
            }
        }
        if (pthis->lockTimer != 0) {
            Actor_DrawDoorLock(globalCtx, pthis->lockTimer, DOORLOCK_NORMAL);
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_door.c", 941);
    }
}

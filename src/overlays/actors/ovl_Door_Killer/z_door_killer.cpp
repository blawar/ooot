#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_DOOR_KILLER_Z_DOOR_KILLER_C
#include "actor_common.h"
/*
 * File: z_door_killer.c
 * Overlay: ovl_Door_Killer
 * Description: Fake doors which attack player
 */

#include "z_door_killer.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_hidan_objects/object_hidan_objects.h"
#include "objects/object_mizu_objects/object_mizu_objects.h"
#include "objects/object_haka_door/object_haka_door.h"
#include "objects/object_door_killer/object_door_killer.h"
#include "def/code_8006BA00.h"
#include "def/z_actor.h"
#include "def/z_cheap_proc.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4


void DoorKiller_Init(Actor* thisx, GlobalContext* globalCtx);
void DoorKiller_Reset(Actor* pthisx, GlobalContext* globalCtx);
void DoorKiller_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DoorKiller_Update(Actor* thisx, GlobalContext* globalCtx);
void DoorKiller_Wait(DoorKiller* pthis, GlobalContext* globalCtx);
void DoorKiller_SetProperties(DoorKiller* pthis, GlobalContext* globalCtx);
void DoorKiller_DrawDoor(Actor* thisx, GlobalContext* globalCtx);
void DoorKiller_DrawRubble(Actor* thisx, GlobalContext* globalCtx);

static Gfx* dLists_66[] = { object_door_killer_DL_001250, object_door_killer_DL_001550, object_door_killer_DL_0017B8,
                         object_door_killer_DL_001A58 };


ActorInit Door_Killer_InitVars = {
    ACTOR_DOOR_KILLER,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_DOOR_KILLER,
    sizeof(DoorKiller),
    (ActorFunc)DoorKiller_Init,
    (ActorFunc)DoorKiller_Destroy,
    (ActorFunc)DoorKiller_Update,
    NULL,
    (ActorFunc)DoorKiller_Reset,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0x0001FFEE, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 20, 100, 0, { 0, 0, 0 } },
};

static ColliderJntSphElementInit sJntSphItemsInit[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000008, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 0, { { 0, 0, 0 }, 100 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphItemsInit,
};

static DoorKillerTextureEntry sDoorTextures[4] = {
    { OBJECT_HIDAN_OBJECTS, gFireTempleDoorKillerTex },
    { OBJECT_MIZU_OBJECTS, object_mizu_objects_Tex_0035C0 },
    { OBJECT_HAKA_DOOR, object_haka_door_Tex_000000 },
    { OBJECT_GAMEPLAY_KEEP, gWoodenDoorTex },
};

void DoorKiller_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    f32 randF;
    DoorKiller* pthis = (DoorKiller*)thisx;
    s32 bankIndex;
    s32 i;

    // Look in the object bank for one of the four objects containing door textures
    bankIndex = -1;
    for (i = 0; bankIndex < 0; i++) {
        bankIndex = Object_GetIndex(&globalCtx->objectCtx, sDoorTextures[i].objectId);
        pthis->textureEntryIndex = i;
    }
    osSyncPrintf("bank_ID = %d\n", bankIndex);
    osSyncPrintf("status = %d\n", pthis->textureEntryIndex);
    pthis->doorObjBankIndex = bankIndex;
    pthis->texture = sDoorTextures[pthis->textureEntryIndex].texture;

    ActorShape_Init(&pthis->actor.shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(&pthis->actor, 0.01f);
    pthis->timer = 0;
    pthis->hasHitPlayerOrGround = 0;
    pthis->animStyle = 0;
    pthis->playerIsOpening = 0;

    switch ((u8)(pthis->actor.params & 0xFF)) {
        case DOOR_KILLER_DOOR:
            // `jointTable` is used for both the `jointTable` and `morphTable` args here. Because pthis actor doesn't
            // play any animations it does not cause problems, but it would need to be changed otherwise.
            SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &object_door_killer_Skel_001BC8, NULL, pthis->jointTable,
                               pthis->jointTable, 9);
            pthis->actionFunc = DoorKiller_SetProperties;
            DoorKiller_SetProperties(pthis, globalCtx);

            // manually set the overall rotation of the door
            pthis->jointTable[1].x = pthis->jointTable[1].z = 0x4000;

            // Set a cylinder collider to detect link attacks and larger sphere collider to detect explosions
            Collider_InitCylinder(globalCtx, &pthis->colliderCylinder);
            Collider_SetCylinder(globalCtx, &pthis->colliderCylinder, &pthis->actor, &sCylinderInit);
            Collider_InitJntSph(globalCtx, &pthis->colliderJntSph);
            Collider_SetJntSph(globalCtx, &pthis->colliderJntSph, &pthis->actor, &sJntSphInit, pthis->colliderJntSphItems);
            pthis->colliderJntSph.elements[0].dim.worldSphere.radius = 80;
            pthis->colliderJntSph.elements[0].dim.worldSphere.center.x = (s16)pthis->actor.world.pos.x;
            pthis->colliderJntSph.elements[0].dim.worldSphere.center.y = (s16)pthis->actor.world.pos.y + 50;
            pthis->colliderJntSph.elements[0].dim.worldSphere.center.z = (s16)pthis->actor.world.pos.z;

            // If tied to a switch flag and that switch flag is already set, kill the actor.
            if ((((pthis->actor.params >> 8) & 0x3F) != 0x3F) &&
                Flags_GetSwitch(globalCtx, ((pthis->actor.params >> 8) & 0x3F))) {
                Actor_Kill(&pthis->actor);
            }
            break;
        case DOOR_KILLER_RUBBLE_PIECE_1:
        case DOOR_KILLER_RUBBLE_PIECE_2:
        case DOOR_KILLER_RUBBLE_PIECE_3:
        case DOOR_KILLER_RUBBLE_PIECE_4:
            pthis->actionFunc = DoorKiller_SetProperties;
            DoorKiller_SetProperties(pthis, globalCtx);

            pthis->actor.gravity = -0.6f;
            pthis->actor.minVelocityY = -6.0f;

            // Random trajectories for rubble pieces
            randF = Rand_CenteredFloat(8.0f);
            pthis->actor.velocity.z = Rand_ZeroFloat(8.0f);
            pthis->actor.velocity.x = (Math_CosS(pthis->actor.world.rot.y) * randF) +
                                     (Math_SinS(pthis->actor.world.rot.y) * pthis->actor.velocity.z);
            pthis->actor.velocity.z = (-Math_SinS(pthis->actor.world.rot.y) * randF) +
                                     (Math_CosS(pthis->actor.world.rot.y) * pthis->actor.velocity.z);
            pthis->actor.velocity.y = Rand_ZeroFloat(4.0f) + 4.0f;

            // These are used as the x,y,z rotational velocities in DoorKiller_FallAsRubble
            pthis->actor.world.rot.x = Rand_CenteredFloat(0x1000);
            pthis->actor.world.rot.y = Rand_CenteredFloat(0x1000);
            pthis->actor.world.rot.z = Rand_CenteredFloat(0x1000);
            pthis->timer = 80;
            break;
    }
}

void DoorKiller_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;

    if ((thisx->params & 0xFF) == DOOR_KILLER_DOOR) {
        Collider_DestroyCylinder(globalCtx, &pthis->colliderCylinder);
        Collider_DestroyJntSph(globalCtx, &pthis->colliderJntSph);
    }
}

void DoorKiller_SpawnRubble(Actor* thisx, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_KILLER, thisx->world.pos.x, thisx->world.pos.y + 9.0f,
                thisx->world.pos.z, thisx->shape.rot.x, thisx->shape.rot.y, thisx->shape.rot.z,
                DOOR_KILLER_RUBBLE_PIECE_1);
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_KILLER, thisx->world.pos.x + 7.88f,
                thisx->world.pos.y + 39.8f, thisx->world.pos.z, thisx->shape.rot.x, thisx->shape.rot.y,
                thisx->shape.rot.z, DOOR_KILLER_RUBBLE_PIECE_2);
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_KILLER, thisx->world.pos.x - 15.86f,
                thisx->world.pos.y + 61.98f, thisx->world.pos.z, thisx->shape.rot.x, thisx->shape.rot.y,
                thisx->shape.rot.z, DOOR_KILLER_RUBBLE_PIECE_3);
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DOOR_KILLER, thisx->world.pos.x + 3.72f,
                thisx->world.pos.y + 85.1f, thisx->world.pos.z, thisx->shape.rot.x, thisx->shape.rot.y,
                thisx->shape.rot.z, DOOR_KILLER_RUBBLE_PIECE_4);
}

/**
 * action function for the individual door pieces that spawn and fall down when the door is destroyed
 */
void DoorKiller_FallAsRubble(DoorKiller* pthis, GlobalContext* globalCtx) {
    pthis->actor.velocity.y += pthis->actor.gravity;
    if (pthis->actor.velocity.y < pthis->actor.minVelocityY) {
        pthis->actor.velocity.y = pthis->actor.minVelocityY;
    }

    pthis->actor.velocity.x *= 0.98f;
    pthis->actor.velocity.z *= 0.98f;

    // world.rot is repurposed to be the rotation velocity for the rubble pieces
    pthis->actor.shape.rot.x += pthis->actor.world.rot.x;
    pthis->actor.shape.rot.y += pthis->actor.world.rot.y;
    pthis->actor.shape.rot.z += pthis->actor.world.rot.z;

    if (pthis->timer != 0) {
        pthis->timer--;
    } else {
        Actor_Kill(&pthis->actor);
    }
    func_8002D7EC(&pthis->actor);
}

s32 DoorKiller_IsHit(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;
    if ((pthis->colliderCylinder.base.acFlags & 2) && (pthis->colliderCylinder.info.acHitInfo != NULL)) {
        return true;
    }
    return false;
}

void DoorKiller_SetAC(DoorKiller* pthis, GlobalContext* globalCtx) {
    Collider_UpdateCylinder(&pthis->actor, &pthis->colliderCylinder);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderCylinder.base);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->colliderJntSph.base);
}

void DoorKiller_Die(DoorKiller* pthis, GlobalContext* globalCtx) {
    s32 switchFlag = (pthis->actor.params >> 8) & 0x3F;

    // Can set a switch flag on death based on params
    if (switchFlag != 0x3F) {
        Flags_SetSwitch(globalCtx, switchFlag);
    }
    Actor_Kill(&pthis->actor);
}

/**
 * After slamming on the floor, rise back upright
 */
void DoorKiller_RiseBackUp(DoorKiller* pthis, GlobalContext* globalCtx) {
    s32 i;
    s16 rotation;

    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->actionFunc = DoorKiller_Wait;
        pthis->timer = 16;
        DoorKiller_SetAC(pthis, globalCtx);
        return;
    }

    pthis->actor.shape.rot.x = (pthis->timer >= 8) ? (pthis->timer * 0x800) - 0x4000 : 0;

    if (pthis->timer >= 12) {
        rotation = (-pthis->timer * -500) - 8000;
    } else if (pthis->timer >= 8) {
        rotation = -2000;
    } else if (pthis->timer >= 5) {
        rotation = (pthis->timer * -500) + 2000;
    } else {
        rotation = 0;
    }

    for (i = 2; i < 9; i++) {
        pthis->jointTable[i].z = -rotation;
    }

    if (pthis->timer < 8) {
        rotation = Math_SinS(pthis->timer * 0x2000) * pthis->timer * 100.0f;
        for (i = 2; i < 9; i++) {
            pthis->jointTable[i].y = rotation;
        }
    }
}

/**
 * After wobbling, fall over and slam onto the floor, damaging the player if they are in the way. Uses manual distance
 * check for damaging player, not AT system.
 */
void DoorKiller_FallOver(DoorKiller* pthis, GlobalContext* globalCtx) {
    s32 i;
    s16 rotation;

    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->actionFunc = DoorKiller_RiseBackUp;
        pthis->timer = 16;
        return;
    }

    pthis->actor.shape.rot.x = (pthis->timer >= 4) ? 0x8000 + (-pthis->timer * 0x1000) : 0x4000;

    if (pthis->timer >= 6) {
        rotation = (-pthis->timer * -500) - 4000;
    } else if (pthis->timer >= 4) {
        rotation = -1000;
    } else if (pthis->timer >= 3) {
        rotation = (pthis->timer * -500) + 1000;
    } else {
        rotation = 0;
    }

    for (i = 2; i < 9; i++) {
        pthis->jointTable[i].z = rotation;
    }

    if (pthis->timer == 4) {
        // spawn 20 random dust particles just before slamming down
        Vec3f velocity = { 0.0f, 0.0f, 0.0f };
        Vec3f accel = { 0.0f, 1.0f, 0.0f };
        Vec3f pos;
        s32 j;
        f32 randF;

        for (j = 0; j != 20; j++) {
            pos.y = 0.0f;
            randF = Rand_CenteredFloat(40.0f);
            pos.z = Rand_ZeroFloat(100.0f);
            pos.x = (Math_CosS(pthis->actor.world.rot.y) * randF) + (Math_SinS(pthis->actor.world.rot.y) * pos.z);
            pos.z = (-Math_SinS(pthis->actor.world.rot.y) * randF) + (Math_CosS(pthis->actor.world.rot.y) * pos.z);
            velocity.x = pos.x * 0.2f;
            velocity.z = pos.z * 0.2f;
            accel.x = -(velocity.x) * 0.1f;
            accel.z = -(velocity.z) * 0.1f;
            pos.x += pthis->actor.world.pos.x;
            pos.y += pthis->actor.world.pos.y;
            pos.z += pthis->actor.world.pos.z;
            func_8002865C(globalCtx, &pos, &velocity, &accel, 300, 30);
        }
    }
    if (!(pthis->hasHitPlayerOrGround & 1)) {
        Vec3f playerPosRelToDoor;
        Player* player = GET_PLAYER(globalCtx);
        func_8002DBD0(&pthis->actor, &playerPosRelToDoor, &player->actor.world.pos);
        if ((fabsf(playerPosRelToDoor.y) < 20.0f) && (fabsf(playerPosRelToDoor.x) < 20.0f) &&
            (playerPosRelToDoor.z < 100.0f) && (playerPosRelToDoor.z > 0.0f)) {
            pthis->hasHitPlayerOrGround |= 1;
            func_8002F6D4(globalCtx, &pthis->actor, 6.0f, pthis->actor.yawTowardsPlayer, 6.0f, 16);
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KDOOR_HIT);
            func_8002F7DC(&player->actor, NA_SE_PL_BODY_HIT);
        }
    }
    if (!(pthis->hasHitPlayerOrGround & 1) && (pthis->timer == 2)) {
        pthis->hasHitPlayerOrGround |= 1;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KDOOR_HIT_GND);
    }
}

/**
 * Wobble around, signifying the door is about to fall over. Does not set AC and so cannot be destroyed during pthis.
 */
void DoorKiller_Wobble(DoorKiller* pthis, GlobalContext* globalCtx) {
    s16 rotation;
    s32 i;

    if ((pthis->timer == 16) || (pthis->timer == 8)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_KDOOR_WAVE);
    }

    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->actionFunc = DoorKiller_FallOver;
        pthis->timer = 8;
        pthis->hasHitPlayerOrGround &= ~1;
        return;
    }

    rotation = Math_SinS(pthis->timer * 0x2000) * pthis->timer * 100.0f;
    for (i = 2; i < 9; i++) {
        pthis->jointTable[i].y = rotation;
    }
    rotation = (u16)(s32)(-Math_CosS(pthis->timer * 0x1000) * 1000.0f) + 1000;
    for (i = 2; i < 9; i++) {
        pthis->jointTable[i].z = rotation;
    }
}

/**
 * Idle while the player attempts to open the door and then begin to wobble
 */
void DoorKiller_WaitBeforeWobble(DoorKiller* pthis, GlobalContext* globalCtx) {
    if (pthis->timer > 0) {
        pthis->timer--;
    } else {
        pthis->timer = 16;
        pthis->actionFunc = DoorKiller_Wobble;
    }
}

void DoorKiller_Wait(DoorKiller* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Vec3f playerPosRelToDoor;
    s16 angleToFacingPlayer;

    func_8002DBD0(&pthis->actor, &playerPosRelToDoor, &player->actor.world.pos);

    // playerIsOpening is set by player
    if (pthis->playerIsOpening) {
        pthis->actionFunc = DoorKiller_WaitBeforeWobble;
        pthis->timer = 10;
        pthis->playerIsOpening = 0;
        return;
    }

    if (DoorKiller_IsHit(&pthis->actor, globalCtx)) {
        // AC cylinder: wobble if hit by most weapons, die if hit by explosives or hammer
        if ((pthis->colliderCylinder.info.acHitInfo->toucher.dmgFlags & 0x1FFA6) != 0) {
            pthis->timer = 16;
            pthis->actionFunc = DoorKiller_Wobble;
        } else if ((pthis->colliderCylinder.info.acHitInfo->toucher.dmgFlags & 0x48) != 0) {
            DoorKiller_SpawnRubble(&pthis->actor, globalCtx);
            pthis->actionFunc = DoorKiller_Die;
            Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_KDOOR_BREAK);
        }
    } else if (Actor_GetCollidedExplosive(globalCtx, &pthis->colliderJntSph.base) != NULL) {
        // AC sphere: die if hit by explosive
        DoorKiller_SpawnRubble(&pthis->actor, globalCtx);
        pthis->actionFunc = DoorKiller_Die;
        Audio_PlaySoundAtPosition(globalCtx, &pthis->actor.world.pos, 20, NA_SE_EN_KDOOR_BREAK);
    } else if (!Player_InCsMode(globalCtx) && (fabsf(playerPosRelToDoor.y) < 20.0f) &&
               (fabsf(playerPosRelToDoor.x) < 20.0f) && (playerPosRelToDoor.z < 50.0f) &&
               (playerPosRelToDoor.z > 0.0f)) {
        // Set player properties to make the door openable if within range
        angleToFacingPlayer = player->actor.shape.rot.y - pthis->actor.shape.rot.y;
        if (playerPosRelToDoor.z > 0.0f) {
            angleToFacingPlayer = 0x8000 - angleToFacingPlayer;
        }
        if (ABS(angleToFacingPlayer) < 0x3000) {
            player->doorType = PLAYER_DOORTYPE_FAKE;
            player->doorDirection = (playerPosRelToDoor.z >= 0.0f) ? 1.0f : -1.0f;
            player->doorActor = &pthis->actor;
        }
    }

    DoorKiller_SetAC(pthis, globalCtx);
}

/**
 * Grabs the virtual address of the texture from the relevant door object
 */
void DoorKiller_UpdateTexture(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;

    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->doorObjBankIndex].vromStart.get());
    pthis->texture = SEGMENTED_TO_VIRTUAL(pthis->texture);
    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[thisx->objBankIndex].vromStart.get());
}

/**
 * Gets the correct door texture, defines the appropriate draw fucntion and action function based on type behaviour
 * (door or rubble).
 */
void DoorKiller_SetProperties(DoorKiller* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->doorObjBankIndex)) {
        DoorKiller_UpdateTexture(&pthis->actor, globalCtx);
        switch (pthis->actor.params & 0xFF) {
            case DOOR_KILLER_DOOR:
                pthis->actionFunc = DoorKiller_Wait;
                pthis->actor.draw = DoorKiller_DrawDoor;
                break;
            case DOOR_KILLER_RUBBLE_PIECE_1:
            case DOOR_KILLER_RUBBLE_PIECE_2:
            case DOOR_KILLER_RUBBLE_PIECE_3:
            case DOOR_KILLER_RUBBLE_PIECE_4:
                pthis->actionFunc = DoorKiller_FallAsRubble;
                pthis->actor.draw = DoorKiller_DrawRubble;
                break;
        }
    }
}

void DoorKiller_Update(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void DoorKiller_SetTexture(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;
    void* doorTexture = pthis->texture;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_door_killer.c", 883);
    gSPSegment(POLY_OPA_DISP++, 0x08, doorTexture);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_door_killer.c", 885);
}

void DoorKiller_DrawDoor(Actor* thisx, GlobalContext* globalCtx) {
    DoorKiller* pthis = (DoorKiller*)thisx;

    func_800943C8(globalCtx->state.gfxCtx);
    DoorKiller_SetTexture(&pthis->actor, globalCtx);
    SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, pthis->skelAnime.dListCount,
                          NULL, NULL, NULL);
}

void DoorKiller_DrawRubble(Actor* thisx, GlobalContext* globalCtx) {
    s32 rubblePieceIndex = (thisx->params & 0xFF) - 1;
    DoorKiller* pthis = (DoorKiller*)thisx;

    if ((pthis->timer >= 20) || ((pthis->timer & 1) == 0)) {
        DoorKiller_SetTexture(thisx, globalCtx);
        Gfx_DrawDListOpa(globalCtx, dLists_66[rubblePieceIndex]);
    }
}

void DoorKiller_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Door_Killer_InitVars = {
        ACTOR_DOOR_KILLER,
        ACTORCAT_BG,
        FLAGS,
        OBJECT_DOOR_KILLER,
        sizeof(DoorKiller),
        (ActorFunc)DoorKiller_Init,
        (ActorFunc)DoorKiller_Destroy,
        (ActorFunc)DoorKiller_Update,
        NULL,
        (ActorFunc)DoorKiller_Reset,
    };

    sCylinderInit = {
        {
            COLTYPE_METAL,
            AT_ON | AT_TYPE_ENEMY,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_1,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0xFFCFFFFF, 0x00, 0x10 },
            { 0x0001FFEE, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_NORMAL,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 20, 100, 0, { 0, 0, 0 } },
    };

    sJntSphInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_NONE,
            COLSHAPE_JNTSPH,
        },
        1,
        sJntSphItemsInit,
    };

}

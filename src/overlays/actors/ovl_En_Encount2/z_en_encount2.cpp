#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ENCOUNT2_Z_EN_ENCOUNT2_C
#include "actor_common.h"
#include "z_en_encount2.h"
#include "overlays/actors/ovl_En_Fire_Rock/z_en_fire_rock.h"
#include "vt.h"
#include "objects/object_efc_star_field/object_efc_star_field.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_quake.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)


void EnEncount2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEncount2_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnEncount2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnEncount2_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnEncount2_Wait(EnEncount2* pthis, GlobalContext* globalCtx);
void EnEncount2_SpawnRocks(EnEncount2* pthis, GlobalContext* globalCtx);

void EnEncount2_ParticleInit(EnEncount2* pthis, Vec3f* particlePos, f32 scale);
void EnEncount2_ParticleDraw(Actor* thisx, GlobalContext* globalCtx);
void EnEncount2_ParticleUpdate(EnEncount2* pthis, GlobalContext* globalCtx);

ActorInit En_Encount2_InitVars = {
    ACTOR_EN_ENCOUNT2,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_EFC_STAR_FIELD,
    sizeof(EnEncount2),
    (ActorFunc)EnEncount2_Init,
    NULL,
    (ActorFunc)EnEncount2_Update,
    (ActorFunc)EnEncount2_Draw,
    (ActorFunc)EnEncount2_Reset,
};

void EnEncount2_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount2* pthis = (EnEncount2*)thisx;

    if (globalCtx->sceneNum != SCENE_SPOT16) {
        pthis->isNotDeathMountain = true;
    }

    if (!pthis->isNotDeathMountain) {
        osSyncPrintf("\n\n");
        // "☆☆☆☆☆ Death Mountain Encount2 set ☆☆☆☆☆"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ デスマウンテンエンカウント２セットされました ☆☆☆☆☆ %d\n" VT_RST,
                     pthis->actor.params);
        if (LINK_IS_ADULT && (gSaveContext.eventChkInf[4] & 0x200)) { // flag for having used fire temple blue warp
            Actor_Kill(thisx);
        }
    } else {
        osSyncPrintf("\n\n");
        // "☆☆☆☆☆ Ganon Tower Escape Encount2 set ☆☆☆☆☆"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ガノンタワー脱出エンカウント２セットされました ☆☆☆☆☆ %d\n" VT_RST,
                     pthis->actor.params);
    }

    pthis->actionFunc = EnEncount2_Wait;
}

void EnEncount2_Wait(EnEncount2* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 quakeIndex;
    s16 spawnerState;
    Player* player = GET_PLAYER(globalCtx);

    spawnerState = ENCOUNT2_INACTIVE;
    if (!pthis->isNotDeathMountain) {
        if ((player->actor.world.pos.y > 1500.0f) && (player->actor.world.pos.x > -700.0f) &&
            (player->actor.world.pos.x < 100.0f) && (player->actor.world.pos.z < -1290.0f) &&
            (player->actor.world.pos.z > -3600.0f)) {
            spawnerState = ENCOUNT2_ACTIVE_DEATH_MOUNTAIN;
        }
    } else if ((pthis->actor.xzDistToPlayer < 700.0f) && (Flags_GetSwitch(globalCtx, 0x37))) {
        s16 scene = globalCtx->sceneNum;

        if (((scene == SCENE_GANON_DEMO) || (scene == SCENE_GANON_FINAL) || (scene == SCENE_GANON_SONOGO) ||
             (scene == SCENE_GANONTIKA_SONOGO)) &&
            (!pthis->collapseSpawnerInactive)) {
            spawnerState = ENCOUNT2_ACTIVE_GANONS_TOWER;
        }
    }

    switch (spawnerState) {
        case ENCOUNT2_INACTIVE:
            pthis->isQuaking = false;
            pthis->envEffectsTimer--;
            if (pthis->envEffectsTimer <= 0) {
                pthis->envEffectsTimer = 0;
            }
            break;
        case ENCOUNT2_ACTIVE_DEATH_MOUNTAIN:
            if ((pthis->deathMountainSpawnerTimer == 1) || (!pthis->isQuaking)) {
                quakeIndex = Quake_Add(GET_ACTIVE_CAM(globalCtx), 1);
                Quake_SetSpeed(quakeIndex, 0x7FFF);
                Quake_SetQuakeValues(quakeIndex, 50, 0, 0, 0);
                Quake_SetCountdown(quakeIndex, 300);
                pthis->isQuaking = true;
            }
        case ENCOUNT2_ACTIVE_GANONS_TOWER:
            pthis->envEffectsTimer++;
            if (pthis->envEffectsTimer > 60) {
                pthis->envEffectsTimer = 60;
            }
            if (pthis->deathMountainSpawnerTimer == 0) {
                pthis->deathMountainSpawnerTimer = 200;
                pthis->numSpawnedRocks = 0;
                pthis->actionFunc = EnEncount2_SpawnRocks;
            }
            break;
    }
    return;
}

void EnEncount2_SpawnRocks(EnEncount2* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    EnFireRock* spawnedRock;
    f32 tempVec1X;
    f32 tempVec1Y;
    f32 tempVec1Z;
    f32 magnitude;
    f32 tempVec2X;
    f32 tempVec2Y;
    f32 tempVec2Z;
    f32 particleScale;
    Vec3f particlePos;
    s16 spawnedRockType;
    s16 spawnerState;
    s16 maxRocks;

    pthis->envEffectsTimer++;

    if (pthis->envEffectsTimer > 60) {
        pthis->envEffectsTimer = 60;
    }

    spawnerState = ENCOUNT2_INACTIVE;

    if (!pthis->isNotDeathMountain) {
        if (pthis->deathMountainSpawnerTimer == 0) {
            pthis->deathMountainSpawnerTimer = 100;
            pthis->actionFunc = EnEncount2_Wait;
            return;
        }

        if ((player->actor.world.pos.y > 1500.0f) && (player->actor.world.pos.x > -700.0f) &&
            (player->actor.world.pos.x < 100.0f) && (player->actor.world.pos.z < -1290.0f) &&
            (player->actor.world.pos.z > -3860.0f)) {
            maxRocks = 2;
            spawnerState = ENCOUNT2_ACTIVE_DEATH_MOUNTAIN;
        }

        Audio_PlayActorSound2(&pthis->actor, NA_SE_EV_VOLCANO - SFX_FLAG);
    } else if ((pthis->actor.xzDistToPlayer < 700.0f) && (Flags_GetSwitch(globalCtx, 0x37) != 0)) {
        s16 scene = globalCtx->sceneNum;

        if (((scene == SCENE_GANON_DEMO) || (scene == SCENE_GANON_FINAL) || (scene == SCENE_GANON_SONOGO) ||
             (scene == SCENE_GANONTIKA_SONOGO)) &&
            (!pthis->collapseSpawnerInactive)) {
            maxRocks = 1;
            spawnerState = ENCOUNT2_ACTIVE_GANONS_TOWER;
        }
    }
    if (spawnerState != ENCOUNT2_INACTIVE) {
        // Direction vector for the direction the camera is facing
        tempVec1X = globalCtx->view.lookAt.x - globalCtx->view.eye.x;
        tempVec1Y = globalCtx->view.lookAt.y - globalCtx->view.eye.y;
        tempVec1Z = globalCtx->view.lookAt.z - globalCtx->view.eye.z;

        // Normalised direction vector for the direction the camera is facing
        magnitude = sqrtf(SQ(tempVec1X) + SQ(tempVec1Y) + SQ(tempVec1Z));
        tempVec2X = tempVec1X / magnitude;
        tempVec2Y = tempVec1Y / magnitude;
        tempVec2Z = tempVec1Z / magnitude;

        // Position between 160 and 300 units ahead of camera depending on camera pitch, plus a 400 unit offset in +y
        tempVec1X = globalCtx->view.eye.x + (tempVec2X * 300.0f);
        tempVec1Y = globalCtx->view.eye.y + (tempVec2Y * 160.0f) + 400.0f;
        tempVec1Z = globalCtx->view.eye.z + (tempVec2Z * 300.0f);

        // Position between 160 and 200 units ahead of camera depending on camera pitch, plus a 400 unit offset in +y
        // (plus some random variation)
        particlePos.x = Rand_CenteredFloat(200.0f) + (globalCtx->view.eye.x + (tempVec2X * 200.0f));
        particlePos.y = Rand_CenteredFloat(50.0f) + tempVec1Y;
        particlePos.z = Rand_CenteredFloat(200.0f) + (globalCtx->view.eye.z + (tempVec2Z * 200.0f));
        particleScale = Rand_CenteredFloat(0.005f) + 0.007f;

        if (spawnerState == ENCOUNT2_ACTIVE_DEATH_MOUNTAIN) {
            EnEncount2_ParticleInit(pthis, &particlePos, particleScale);
        } else if (pthis->particleSpawnTimer == 0) {
            EnEncount2_ParticleInit(pthis, &particlePos, particleScale);
            pthis->particleSpawnTimer = 5;
        }

        if ((pthis->numSpawnedRocks < maxRocks) && (pthis->timerBetweenRockSpawns == 0)) {
            if (spawnerState == ENCOUNT2_ACTIVE_DEATH_MOUNTAIN) {
                pthis->timerBetweenRockSpawns = 4;
                spawnedRockType = FIRE_ROCK_SPAWNED_FALLING1;
                if ((Rand_ZeroFloat(1.99f) < 1.0f) && !LINK_IS_ADULT) {
                    // rock spawn pos X, Z near player
                    tempVec2X = Rand_CenteredFloat(10.0f) + player->actor.world.pos.x;
                    tempVec2Z = Rand_CenteredFloat(10.0f) + player->actor.world.pos.z;
                } else {
                    if (player->linearVelocity != 0.0f) {
                        // rock spawn pos is between 300 and 600 units from the camera depending on the camera yaw.
                        // Rocks will generally spawn closer to the camera in the X axis than in the Z axis.
                        tempVec2X = Rand_CenteredFloat(200.0f) + (globalCtx->view.eye.x + (tempVec2X * 300.0f));
                        tempVec2Z = Rand_CenteredFloat(50.0f) + (globalCtx->view.eye.z + (tempVec2Z * 600.0f));
                    } else {
                        // rock spawn pos X, Z near player
                        tempVec2X = Rand_CenteredFloat(10.0f) + player->actor.world.pos.x;
                        tempVec2Z = Rand_CenteredFloat(10.0f) + player->actor.world.pos.z;
                    }
                    spawnedRockType = FIRE_ROCK_SPAWNED_FALLING2;
                }
            } else {
                pthis->timerBetweenRockSpawns = 50;
                spawnedRockType = FIRE_ROCK_SPAWNED_FALLING2;
                // rock spawn pos X,Z at a random position roughly 300 units ahead of camera
                tempVec2X = Rand_CenteredFloat(100.0f) + tempVec1X;
                tempVec2Z = Rand_CenteredFloat(100.0f) + tempVec1Z;

                if (Rand_ZeroFloat(3.99f) < 1.0f) {
                    // rock spawn pos X,Z at a random position near player
                    tempVec2X = Rand_CenteredFloat(70.0f) + player->actor.world.pos.x;
                    tempVec2Z = Rand_CenteredFloat(70.0f) + player->actor.world.pos.z;
                }
            }
            spawnedRock =
                (EnFireRock*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_FIRE_ROCK,
                                                tempVec2X, tempVec1Y, tempVec2Z, 0, 0, 0, spawnedRockType);
            if (spawnedRock != NULL) {
                spawnedRock->spawner = pthis;
                pthis->numSpawnedRocks++;
                return;
            }
            // "☆☆☆☆☆ Can't occur! ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n\n" VT_RST);
        }
    }
}

void EnEncount2_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnEncount2* pthis = (EnEncount2*)thisx;
    GlobalContext* globalCtx = globalCtx2;

    if (pthis->deathMountainSpawnerTimer != 0) {
        pthis->deathMountainSpawnerTimer--;
    }

    if (pthis->timerBetweenRockSpawns != 0) {
        pthis->timerBetweenRockSpawns--;
    }

    if (pthis->particleSpawnTimer != 0) {
        pthis->particleSpawnTimer--;
    }

    pthis->actionFunc(pthis, globalCtx);

    EnEncount2_ParticleUpdate(pthis, globalCtx);

    if (!pthis->isNotDeathMountain) {
        pthis->unk17C = pthis->envEffectsTimer / 60.0f;
        pthis->unk160 = pthis->unk17C * -50.0f;
        globalCtx->envCtx.adjAmbientColor[0] = (s16)pthis->unk160 * -1.5f;
        globalCtx->envCtx.adjAmbientColor[1] = globalCtx->envCtx.adjAmbientColor[2] = pthis->unk160;
        pthis->unk168 = pthis->unk17C * -20.0f;
        globalCtx->envCtx.adjLight1Color[0] = (s16)pthis->unk168 * -1.5f;
        globalCtx->envCtx.adjLight1Color[1] = globalCtx->envCtx.adjLight1Color[2] = pthis->unk168;
        pthis->unk170 = pthis->unk17C * -50.0f;
        globalCtx->envCtx.adjFogNear = pthis->unk170;
        globalCtx->envCtx.adjFogColor[0] = (u8)((160.0f - globalCtx->envCtx.lightSettings.fogColor[0]) * pthis->unk17C);
        globalCtx->envCtx.adjFogColor[1] = (u8)((160.0f - globalCtx->envCtx.lightSettings.fogColor[1]) * pthis->unk17C);
        globalCtx->envCtx.adjFogColor[2] = (u8)((150.0f - globalCtx->envCtx.lightSettings.fogColor[2]) * pthis->unk17C);
    }
}

void EnEncount2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount2* pthis = (EnEncount2*)thisx;

    EnEncount2_ParticleDraw(&pthis->actor, globalCtx);
}

void EnEncount2_ParticleInit(EnEncount2* pthis, Vec3f* particlePos, f32 scale) {
    EnEncount2Particle* particle = pthis->particles;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->particles); i++, particle++) {
        if (!particle->isAlive) {
            particle->pos = *particlePos;
            particle->scale = scale;
            particle->rot.x = 0.0f;
            particle->rot.y = 0.0f;
            particle->rot.z = 0.0f;
            particle->moveDirection.x = Rand_CenteredFloat(20.0f);
            particle->moveDirection.y = -20.0f;
            particle->moveDirection.z = Rand_CenteredFloat(20.0f);
            particle->isAlive = 1;
            break;
        }
    }
}

void EnEncount2_ParticleUpdate(EnEncount2* pthis, GlobalContext* globalCtx) {
    s16 i;
    EnEncount2Particle* particle = pthis->particles;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f targetPos;

    for (i = 0; i < ARRAY_COUNT(pthis->particles); particle++, i++) {
        if (particle->isAlive) {
            particle->rot.x += Rand_ZeroOne() * 500.0f;
            particle->rot.y += Rand_ZeroOne() * 500.0f;
            particle->rot.z += Rand_ZeroOne() * 500.0f;
            targetPos.x = particle->pos.x + particle->moveDirection.x;
            targetPos.y = particle->pos.y + particle->moveDirection.y;
            targetPos.z = particle->pos.z + particle->moveDirection.z;
            Math_ApproachF(&particle->pos.x, targetPos.x, 0.3f, 30.0f);
            Math_ApproachF(&particle->pos.y, targetPos.y, 0.8f, 250.0f);
            Math_ApproachF(&particle->pos.z, targetPos.z, 0.3f, 30.0f);
            Math_ApproachF(&particle->moveDirection.y, -20.0f, 0.9f, 1.0f);

            if (globalCtx->sceneNum != SCENE_SPOT16) {
                if (particle->pos.y < (player->actor.floorHeight - 50.0f)) {
                    particle->isAlive = 0;
                }
            } else if (particle->pos.y < 1500.0f) {
                particle->isAlive = 0;
            }
        }
    }
}

void EnEncount2_ParticleDraw(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount2* pthis = (EnEncount2*)thisx;
    EnEncount2Particle* particle = pthis->particles;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s16 i;
    s32 objBankIndex;

    OPEN_DISPS(gfxCtx, "../z_en_encount2.c", 642);

    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_EFC_STAR_FIELD);

    if (objBankIndex >= 0) {
        gDPPipeSync(POLY_XLU_DISP++);
        gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[objBankIndex].vromStart.get());

        for (i = 0; i < ARRAY_COUNT(pthis->particles); particle++, i++) {
            if (particle->isAlive) {
                Matrix_Translate(particle->pos.x, particle->pos.y, particle->pos.z, MTXMODE_NEW);
                Matrix_RotateX(particle->rot.x * (M_PI / 180.0f), MTXMODE_APPLY);
                Matrix_RotateY(particle->rot.y * (M_PI / 180.0f), MTXMODE_APPLY);
                Matrix_RotateZ(particle->rot.z * (M_PI / 180.0f), MTXMODE_APPLY);
                Matrix_Scale(particle->scale, particle->scale, particle->scale, MTXMODE_APPLY);
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 155, 55, 255);
                gDPSetEnvColor(POLY_OPA_DISP++, 155, 255, 55, 255);
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_encount2.c", 669),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, object_efc_star_field_DL_000DE0);
            }
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_en_encount2.c", 678);
}

void EnEncount2_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Encount2_InitVars = {
        ACTOR_EN_ENCOUNT2,
        ACTORCAT_ENEMY,
        FLAGS,
        OBJECT_EFC_STAR_FIELD,
        sizeof(EnEncount2),
        (ActorFunc)EnEncount2_Init,
        NULL,
        (ActorFunc)EnEncount2_Update,
        (ActorFunc)EnEncount2_Draw,
        (ActorFunc)EnEncount2_Reset,
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ENCOUNT1_Z_EN_ENCOUNT1_C
#include "z_debug_display.h"
#include "actor_common.h"
#include "z_en_encount1.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Tite/z_en_tite.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_player_lib.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_27)

void EnEncount1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEncount1_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnEncount1_Update(Actor* thisx, GlobalContext* globalCtx);

void EnEncount1_SpawnLeevers(EnEncount1* pthis, GlobalContext* globalCtx);
void EnEncount1_SpawnTektites(EnEncount1* pthis, GlobalContext* globalCtx);
void EnEncount1_SpawnStalchildOrWolfos(EnEncount1* pthis, GlobalContext* globalCtx);

static s16 sLeeverAngles[] = { 0x0000, 0x2710, 0x7148, 0x8EB8, 0xD8F0 };
static f32 sLeeverDists[] = { 200.0f, 170.0f, 120.0f, 120.0f, 170.0f };

ActorInit En_Encount1_InitVars = {
    ACTOR_EN_ENCOUNT1,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnEncount1),
    (ActorFunc)EnEncount1_Init,
    NULL,
    (ActorFunc)EnEncount1_Update,
    NULL,
    (ActorFunc)EnEncount1_Reset,
};

void EnEncount1_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnEncount1* pthis = (EnEncount1*)thisx;
    f32 spawnRange;

    if (pthis->actor.params <= 0) {
        osSyncPrintf("\n\n");
        // "Input error death!"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 入力エラーデッス！ ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 入力エラーデッス！ ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 入力エラーデッス！ ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 入力エラーデッス！ ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 入力エラーデッス！ ☆☆☆☆☆ \n" VT_RST);
        osSyncPrintf("\n\n");
        Actor_Kill(&pthis->actor);
        return;
    }

    pthis->spawnType = (pthis->actor.params >> 0xB) & 0x1F;
    pthis->maxCurSpawns = (pthis->actor.params >> 6) & 0x1F;
    pthis->maxTotalSpawns = pthis->actor.params & 0x3F;
    pthis->curNumSpawn = pthis->totalNumSpawn = 0;
    spawnRange = 120.0f + (40.0f * pthis->actor.world.rot.z);
    pthis->spawnRange = spawnRange;

    osSyncPrintf("\n\n");
    // "It's an enemy spawner!"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 敵発生ゾーンでた！ ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
    // "Type"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 種類\t\t   ☆☆☆☆☆ %d\n" VT_RST, pthis->spawnType);
    // "Maximum number of simultaneous spawns"
    osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 最大同時発生数     ☆☆☆☆☆ %d\n" VT_RST, pthis->maxCurSpawns);
    // "Maximum number of spawns"
    osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 最大発生数  \t   ☆☆☆☆☆ %d\n" VT_RST, pthis->maxTotalSpawns);
    // "Spawn check range"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生チェック範囲   ☆☆☆☆☆ %f\n" VT_RST, pthis->spawnRange);
    osSyncPrintf("\n\n");

    pthis->actor.flags &= ~ACTOR_FLAG_0;
    switch (pthis->spawnType) {
        case SPAWNER_LEEVER:
            pthis->timer = 30;
            pthis->maxCurSpawns = 5;
            if (globalCtx->sceneNum == SCENE_SPOT13) { // Haunted Wasteland
                pthis->reduceLeevers = true;
                pthis->maxCurSpawns = 3;
            }
            pthis->updateFunc = EnEncount1_SpawnLeevers;
            break;
        case SPAWNER_TEKTITE:
            pthis->maxCurSpawns = 2;
            pthis->updateFunc = EnEncount1_SpawnTektites;
            break;
        case SPAWNER_STALCHILDREN:
        case SPAWNER_WOLFOS:
            if (globalCtx->sceneNum == SCENE_SPOT00) { // Hyrule Field
                pthis->maxTotalSpawns = 10000;
            }
            pthis->updateFunc = EnEncount1_SpawnStalchildOrWolfos;
            break;
    }
}

void EnEncount1_SpawnLeevers(EnEncount1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 floorType;
    f32 spawnDist;
    s32 spawnParams;
    s16 spawnLimit;
    s16 spawnAngle;
    Vec3f spawnPos;
    CollisionPoly* floorPoly;
    s32 bgId;
    f32 floorY;
    EnReeba* leever;

    pthis->outOfRangeTimer = 0;
    spawnPos = pthis->actor.world.pos;

    if ((pthis->timer == 0) && (globalCtx->csCtx.state == CS_STATE_IDLE) && (pthis->curNumSpawn <= pthis->maxCurSpawns) &&
        (pthis->curNumSpawn < 5)) {
        floorType = func_80041D4C(&globalCtx->colCtx, player->actor.floorPoly, player->actor.floorBgId);
        if ((floorType != 4) && (floorType != 7) && (floorType != 12)) {
            pthis->numLeeverSpawns = 0;
        } else if (!(pthis->reduceLeevers && (pthis->actor.xzDistToPlayer > 1300.0f))) {
            spawnLimit = 5;
            if (pthis->reduceLeevers) {
                spawnLimit = 3;
            }
            while ((pthis->curNumSpawn < pthis->maxCurSpawns) && (pthis->curNumSpawn < spawnLimit) && (pthis->timer == 0)) {
                spawnDist = sLeeverDists[pthis->leeverIndex];
                spawnAngle = sLeeverAngles[pthis->leeverIndex] + player->actor.shape.rot.y;
                spawnParams = LEEVER_SMALL;

                if ((pthis->killCount >= 10) && (pthis->bigLeever == NULL)) {
                    pthis->killCount = pthis->numLeeverSpawns = 0;
                    spawnAngle = sLeeverAngles[0];
                    spawnDist = sLeeverDists[2];
                    spawnParams = LEEVER_BIG;
                }

                spawnPos.x = player->actor.world.pos.x + Math_SinS(spawnAngle) * spawnDist;
                spawnPos.y = player->actor.floorHeight + 120.0f;
                spawnPos.z = player->actor.world.pos.z + Math_CosS(spawnAngle) * spawnDist;

                floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &floorPoly, &bgId, &pthis->actor, &spawnPos);
                if (floorY <= BGCHECK_Y_MIN) {
                    break;
                }
                spawnPos.y = floorY;

                leever = (EnReeba*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_REEBA,
                                                      spawnPos.x, spawnPos.y, spawnPos.z, 0, 0, 0, spawnParams);

                if (1) {}
                if (1) {}
                if (leever != NULL) {
                    pthis->curNumSpawn++;
                    leever->unk_280 = pthis->leeverIndex++;
                    if (pthis->leeverIndex >= 5) {
                        pthis->leeverIndex = 0;
                    }
                    pthis->numLeeverSpawns++;
                    if (pthis->numLeeverSpawns >= 12) {
                        pthis->timer = 150;
                        pthis->numLeeverSpawns = 0;
                    }
                    if (spawnParams != LEEVER_SMALL) {
                        pthis->timer = 300;
                        pthis->bigLeever = leever;
                    }
                    if (!pthis->reduceLeevers) {
                        pthis->maxCurSpawns = (s16)Rand_ZeroFloat(3.99f) + 2;
                    } else {
                        pthis->maxCurSpawns = (s16)Rand_ZeroFloat(2.99f) + 1;
                    }
                } else {
                    // "Cannot spawn!"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                    break;
                }
            }
        }
    }
}

void EnEncount1_SpawnTektites(EnEncount1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 bgId;
    CollisionPoly* floorPoly;
    Vec3f spawnPos;
    f32 floorY;

    if (pthis->timer == 0) {
        pthis->timer = 10;
        if ((fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) > 100.0f) ||
            (pthis->actor.xzDistToPlayer > pthis->spawnRange)) {
            pthis->outOfRangeTimer++;
        } else {
            pthis->outOfRangeTimer = 0;
            if ((pthis->curNumSpawn < pthis->maxCurSpawns) && (pthis->totalNumSpawn < pthis->maxTotalSpawns)) {
                spawnPos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(50.0f);
                spawnPos.y = pthis->actor.world.pos.y + 120.0f;
                spawnPos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(50.0f);
                floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &floorPoly, &bgId, &pthis->actor, &spawnPos);
                if (floorY <= BGCHECK_Y_MIN) {
                    return;
                }
                spawnPos.y = floorY;
                if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_TITE, spawnPos.x,
                                       spawnPos.y, spawnPos.z, 0, 0, 0, TEKTITE_RED) != NULL) { // Red tektite
                    pthis->curNumSpawn++;
                    pthis->totalNumSpawn++;
                } else {
                    // "Cannot spawn!"
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                }
            }
        }
    }
}

void EnEncount1_SpawnStalchildOrWolfos(EnEncount1* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 spawnDist;
    s16 spawnAngle;
    s16 spawnId;
    s16 spawnParams;
    s16 kcOver10;
    s16 tempmod;
    Vec3f spawnPos;
    CollisionPoly* floorPoly;
    s32 bgId;
    f32 floorY;

    if (globalCtx->sceneNum != SCENE_SPOT00) {
        if ((fabsf(player->actor.world.pos.y - pthis->actor.world.pos.y) > 100.0f) ||
            (pthis->actor.xzDistToPlayer > pthis->spawnRange)) {
            pthis->outOfRangeTimer++;
            return;
        }
    } else if (IS_DAY || (Player_GetMask(globalCtx) == PLAYER_MASK_BUNNY)) {
        pthis->killCount = 0;
        return;
    }

    pthis->outOfRangeTimer = 0;
    spawnPos = pthis->actor.world.pos;
    if ((pthis->curNumSpawn < pthis->maxCurSpawns) && (pthis->totalNumSpawn < pthis->maxTotalSpawns)) {
        while ((pthis->curNumSpawn < pthis->maxCurSpawns) && (pthis->totalNumSpawn < pthis->maxTotalSpawns)) {
            if (globalCtx->sceneNum == SCENE_SPOT00) {
                if ((player->unk_89E == 0) || (player->actor.floorBgId != BGCHECK_SCENE) ||
                    !(player->actor.bgCheckFlags & 1) || (player->stateFlags1 & 0x08000000)) {

                    pthis->fieldSpawnTimer = 60;
                    break;
                }
                if (pthis->fieldSpawnTimer == 60) {
                    pthis->maxCurSpawns = 2;
                }
                if (pthis->fieldSpawnTimer != 0) {
                    pthis->fieldSpawnTimer--;
                    break;
                }

                spawnDist = Rand_CenteredFloat(40.0f) + 200.0f;
                spawnAngle = player->actor.shape.rot.y;
                if (pthis->curNumSpawn != 0) {
                    spawnAngle = -spawnAngle;
                    spawnDist = Rand_CenteredFloat(40.0f) + 100.0f;
                }
                spawnPos.x =
                    player->actor.world.pos.x + (Math_SinS(spawnAngle) * spawnDist) + Rand_CenteredFloat(40.0f);
                spawnPos.y = player->actor.floorHeight + 120.0f;
                spawnPos.z =
                    player->actor.world.pos.z + (Math_CosS(spawnAngle) * spawnDist) + Rand_CenteredFloat(40.0f);
                floorY = BgCheck_EntityRaycastFloor4(&globalCtx->colCtx, &floorPoly, &bgId, &pthis->actor, &spawnPos);
                if (floorY <= BGCHECK_Y_MIN) {
                    break;
                }
                if ((player->actor.yDistToWater != BGCHECK_Y_MIN) &&
                    (floorY < (player->actor.world.pos.y - player->actor.yDistToWater))) {
                    break;
                }
                spawnPos.y = floorY;
            }
            if (pthis->spawnType == SPAWNER_WOLFOS) {
                spawnId = ACTOR_EN_WF;
                spawnParams = (0xFF << 8) | 0x00;
            } else {
                spawnId = ACTOR_EN_SKB;
                spawnParams = 0;

                kcOver10 = pthis->killCount / 10;
                if (kcOver10 > 0) {
                    tempmod = pthis->killCount % 10;
                    if (tempmod == 0) {
                        spawnParams = kcOver10 * 5;
                    }
                }
                pthis->killCount++;
            }
            if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, spawnId, spawnPos.x, spawnPos.y,
                                   spawnPos.z, 0, 0, 0, spawnParams) != NULL) {
                pthis->curNumSpawn++;
                if (pthis->curNumSpawn >= pthis->maxCurSpawns) {
                    pthis->fieldSpawnTimer = 100;
                }
                if (globalCtx->sceneNum != SCENE_SPOT00) {
                    pthis->totalNumSpawn++;
                }
            } else {
                // "Cannot spawn!"
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 発生できません！ ☆☆☆☆☆\n" VT_RST);
                break;
            }
        }
    }
}

void EnEncount1_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnEncount1* pthis = (EnEncount1*)thisx;

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    pthis->updateFunc(pthis, globalCtx);
}

void EnEncount1_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Encount1_InitVars = {
        ACTOR_EN_ENCOUNT1,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnEncount1),
        (ActorFunc)EnEncount1_Init,
        NULL,
        (ActorFunc)EnEncount1_Update,
        NULL,
        (ActorFunc)EnEncount1_Reset,
    };

}

#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DNT_NOMAL_Z_EN_DNT_NOMAL_C
#include "actor_common.h"
/*
 * File: z_en_dnt_nomal
 * Overlay: ovl_En_Dnt_Nomal
 * Description: Lost Woods minigame scrubs
 */

#include "z_en_dnt_nomal.h"
#include "objects/object_dnk/object_dnk.h"
#include "overlays/actors/ovl_En_Dnt_Demo/z_en_dnt_demo.h"
#include "overlays/actors/ovl_En_Ex_Ruppy/z_en_ex_ruppy.h"
#include "overlays/actors/ovl_En_Ex_Item/z_en_ex_item.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"
#include "objects/object_hintnuts/object_hintnuts.h"
#include "vt.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnDntNomal_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDntNomal_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDntNomal_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDntNomal_DrawTargetScrub(Actor* thisx, GlobalContext* globalCtx);
void EnDntNomal_DrawStageScrub(Actor* thisx, GlobalContext* globalCtx);

void EnDntNomal_WaitForObject(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetFlower(EnDntNomal* pthis, GlobalContext* globalCtx);

void EnDntNomal_SetupTargetWait(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupTargetUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupTargetWalk(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupTargetTalk(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupTargetGivePrize(EnDntNomal* pthis, GlobalContext* globalCtx);

void EnDntNomal_TargetWait(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetWalk(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetFacePlayer(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetTalk(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetGivePrize(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetReturn(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_TargetBurrow(EnDntNomal* pthis, GlobalContext* globalCtx);

void EnDntNomal_SetupStageWait(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupStageCelebrate(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupStageDance(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupStageHide(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_SetupStageAttack(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageSetupReturn(EnDntNomal* pthis, GlobalContext* globalCtx);

void EnDntNomal_StageWait(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageUp(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageCelebrate(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageDance(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageHide(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageAttackHide(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageAttack(EnDntNomal* pthis, GlobalContext* globalCtx);
void EnDntNomal_StageReturn(EnDntNomal* pthis, GlobalContext* globalCtx);

ActorInit En_Dnt_Nomal_InitVars = {
    ACTOR_EN_DNT_NOMAL,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntNomal),
    (ActorFunc)EnDntNomal_Init,
    (ActorFunc)EnDntNomal_Destroy,
    (ActorFunc)EnDntNomal_Update,
    NULL,
};

static ColliderCylinderInit sBodyCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 16, 46, 0, { 0, 0, 0 } },
};

static ColliderQuadInit sTargetQuadInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x0001F824, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static Color_RGBA8 sLeafColors[] = {
    { 255, 255, 255, 255 }, { 255, 195, 175, 255 }, { 210, 255, 0, 255 },
    { 255, 255, 255, 255 }, { 210, 255, 0, 255 },   { 255, 195, 175, 255 },
    { 255, 255, 255, 255 }, { 255, 195, 175, 255 }, { 210, 255, 0, 255 },
};

void EnDntNomal_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntNomal* pthis = (EnDntNomal*)thisx;

    pthis->type = pthis->actor.params;
    if (pthis->type < ENDNTNOMAL_TARGET) {
        pthis->type = ENDNTNOMAL_TARGET;
    }
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actor.colChkInfo.mass = 0xFF;
    pthis->objId = -1;
    if (pthis->type == ENDNTNOMAL_TARGET) {
        osSyncPrintf("\n\n");
        // "Deku Scrub target"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ デグナッツ的当て ☆☆☆☆☆ \n" VT_RST);
        Collider_InitQuad(globalCtx, &pthis->targetQuad);
        Collider_SetQuad(globalCtx, &pthis->targetQuad, &pthis->actor, &sTargetQuadInit);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y = pthis->actor.yawTowardsPlayer;
        pthis->objId = OBJECT_HINTNUTS;
    } else {
        osSyncPrintf("\n\n");
        // "Deku Scrub mask show audience"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ デグナッツお面品評会一般人 ☆☆☆☆☆ \n" VT_RST);
        Collider_InitCylinder(globalCtx, &pthis->bodyCyl);
        Collider_SetCylinder(globalCtx, &pthis->bodyCyl, &pthis->actor, &sBodyCylinderInit);
        pthis->objId = OBJECT_DNK;
    }
    if (pthis->objId >= 0) {
        pthis->objIndex = Object_GetIndex(&globalCtx->objectCtx, pthis->objId);
        if (pthis->objIndex < 0) {
            Actor_Kill(&pthis->actor);
            // "What?"
            osSyncPrintf(VT_FGCOL(PURPLE) " なにみの？ %d\n" VT_RST "\n", pthis->objIndex);
            // "Bank is funny"
            osSyncPrintf(VT_FGCOL(CYAN) " バンクおかしいしぞ！%d\n" VT_RST "\n", pthis->actor.params);
            return;
        }
    } else {
        Actor_Kill(&pthis->actor);
    }
    pthis->actionFunc = EnDntNomal_WaitForObject;
}

void EnDntNomal_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntNomal* pthis = (EnDntNomal*)thisx;

    if (pthis->type == ENDNTNOMAL_TARGET) {
        Collider_DestroyQuad(globalCtx, &pthis->targetQuad);
    } else {
        Collider_DestroyCylinder(globalCtx, &pthis->bodyCyl);
    }
}

void EnDntNomal_WaitForObject(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objIndex)) {
        gSegments[6] = PHYSICAL_TO_VIRTUAL(gObjectTable[pthis->objIndex].vromStart.get());
        pthis->actor.objBankIndex = pthis->objIndex;
        ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
        pthis->actor.gravity = -2.0f;
        Actor_SetScale(&pthis->actor, 0.01f);
        if (pthis->type == ENDNTNOMAL_TARGET) {
            SkelAnime_Init(globalCtx, &pthis->skelAnime, &gHintNutsSkel, &gHintNutsBurrowAnim, pthis->jointTable,
                           pthis->morphTable, 10);
            pthis->actor.draw = EnDntNomal_DrawTargetScrub;
        } else {
            SkelAnime_Init(globalCtx, &pthis->skelAnime, &gDntStageSkel, &gDntStageHideAnim, pthis->jointTable,
                           pthis->morphTable, 11);
            pthis->actor.draw = EnDntNomal_DrawStageScrub;
        }
        pthis->actionFunc = EnDntNomal_SetFlower;
    }
}

void EnDntNomal_SetFlower(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.bgCheckFlags & 1) {
        pthis->flowerPos = pthis->actor.world.pos;
        if (pthis->type == ENDNTNOMAL_TARGET) {
            pthis->actionFunc = EnDntNomal_SetupTargetWait;
        } else {
            pthis->actionFunc = EnDntNomal_SetupStageWait;
        }
    }
}

void EnDntNomal_SetupTargetWait(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsBurrowAnim);
    Animation_Change(&pthis->skelAnime, &gHintNutsBurrowAnim, 0.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    pthis->skelAnime.curFrame = 8.0f;
    pthis->actionFunc = EnDntNomal_TargetWait;
}

void EnDntNomal_TargetWait(EnDntNomal* pthis, GlobalContext* globalCtx) {
    Vec3f scorePos;
    f32 targetX = 1340.0f;
    f32 targetY = 50.0f;
    f32 targetZ = -30.0f;
    f32 dx;
    f32 dy;
    f32 dz;
    Vec3f scoreAccel = { 0.0f, 0.0f, 0.0f };
    Vec3f scoreVel = { 0.0f, 0.0f, 0.0f };

    pthis->targetVtx[0].x = pthis->targetVtx[1].x = pthis->targetVtx[2].x = pthis->targetVtx[3].x = targetX;

    pthis->targetVtx[1].y = pthis->targetVtx[0].y = targetY - 24.0f;

    pthis->targetVtx[2].z = pthis->targetVtx[0].z = targetZ + 24.0f;

    pthis->targetVtx[3].z = pthis->targetVtx[1].z = targetZ - 24.0f;

    pthis->targetVtx[3].y = pthis->targetVtx[2].y = targetY + 24.0f;

    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->targetQuad.base.acFlags & AC_HIT) || BREG(0)) {
        pthis->targetQuad.base.acFlags &= ~AC_HIT;

        dx = fabsf(targetX - pthis->targetQuad.info.bumper.hitPos.x);
        dy = fabsf(targetY - pthis->targetQuad.info.bumper.hitPos.y);
        dz = fabsf(targetZ - pthis->targetQuad.info.bumper.hitPos.z);

        scoreVel.y = 5.0f;

        if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 8.0f) {
            scorePos.x = pthis->actor.world.pos.x - 20.0f;
            scorePos.y = pthis->actor.world.pos.y + 20.0f;
            scorePos.z = pthis->actor.world.pos.z;
            EffectSsExtra_Spawn(globalCtx, &scorePos, &scoreVel, &scoreAccel, 4, 2);
            Audio_StopSfxById(NA_SE_SY_TRE_BOX_APPEAR);
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
            // "Big hit"
            osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ 大当り ☆☆☆☆☆ %d\n" VT_RST, pthis->hitCounter);
            if (!LINK_IS_ADULT && !(gSaveContext.itemGetInf[1] & 0x2000)) {
                pthis->hitCounter++;
                if (pthis->hitCounter >= 3) {
                    OnePointCutscene_Init(globalCtx, 4140, -99, &pthis->actor, MAIN_CAM);
                    func_8002DF54(globalCtx, &pthis->actor, 1);
                    pthis->timer4 = 50;
                    pthis->actionFunc = EnDntNomal_SetupTargetUnburrow;
                }
            }
        } else if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 24.0f) {
            scorePos.x = pthis->actor.world.pos.x;
            scorePos.y = pthis->actor.world.pos.y + 20.0f;
            scorePos.z = pthis->actor.world.pos.z;
            EffectSsExtra_Spawn(globalCtx, &scorePos, &scoreVel, &scoreAccel, 4, 0);
            pthis->hitCounter = 0;
        }
    }
}

void EnDntNomal_SetupTargetUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx) {
    Vec3f spawnPos;

    if (pthis->timer4 == 0) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsUnburrowAnim);
        Animation_Change(&pthis->skelAnime, &gHintNutsUnburrowAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        spawnPos = pthis->actor.world.pos;
        spawnPos.y = pthis->actor.world.pos.y + 50.0f;
        EffectSsHahen_SpawnBurst(globalCtx, &spawnPos, 4.0f, 0, 10, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
        pthis->actionFunc = EnDntNomal_TargetUnburrow;
    }
}

void EnDntNomal_TargetUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (frame >= pthis->endFrame) {
        pthis->actionFunc = EnDntNomal_SetupTargetWalk;
    }
}

void EnDntNomal_SetupTargetWalk(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsRunAnim);
    Animation_Change(&pthis->skelAnime, &gHintNutsRunAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.speedXZ = 1.0f;
    pthis->actor.colChkInfo.mass = 0;
    pthis->actionFunc = EnDntNomal_TargetWalk;
}

void EnDntNomal_TargetWalk(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;

    SkelAnime_Update(&pthis->skelAnime);
    dx = 1340.0f + 3.0f - pthis->actor.world.pos.x;
    dz = 0.0f - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 0x32, 0xBB8, 0);
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if (pthis->actor.world.pos.z > -30.0f) {
        pthis->actor.speedXZ = 0.0f;
        pthis->actionFunc = EnDntNomal_TargetFacePlayer;
    }
}

void EnDntNomal_TargetFacePlayer(EnDntNomal* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if (fabsf(pthis->actor.shape.rot.y - pthis->actor.yawTowardsPlayer) < 30.0f) {
        pthis->actionFunc = EnDntNomal_SetupTargetTalk;
    }
}

void EnDntNomal_SetupTargetTalk(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsTalkAnim);
    Animation_Change(&pthis->skelAnime, &gHintNutsTalkAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.textId = 0x10AF;
    Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
    pthis->actionFunc = EnDntNomal_TargetTalk;
}

void EnDntNomal_TargetTalk(EnDntNomal* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(globalCtx)) {
        Message_CloseTextbox(globalCtx);
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
        GET_ACTIVE_CAM(globalCtx)->csId = 0;
        func_8002DF54(globalCtx, NULL, 8);
        pthis->actionFunc = EnDntNomal_SetupTargetGivePrize;
    }
}

void EnDntNomal_SetupTargetGivePrize(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsSpitAnim);
    Animation_Change(&pthis->skelAnime, &gHintNutsSpitAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
    pthis->actionFunc = EnDntNomal_TargetGivePrize;
}

void EnDntNomal_TargetGivePrize(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if ((frame >= 8.0f) && !pthis->spawnedItem) {
        f32 itemX = pthis->mouthPos.x - 10.0f;
        f32 itemY = pthis->mouthPos.y;
        f32 itemZ = pthis->mouthPos.z;

        if (Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_EX_ITEM, itemX, itemY, itemZ, 0,
                               0, 0, EXITEM_BULLET_BAG) == NULL) {
            func_8002DF54(globalCtx, NULL, 7);
            Actor_Kill(&pthis->actor);
        }
        pthis->spawnedItem = true;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
    }
    if (frame >= pthis->endFrame) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsRunAnim);
        Animation_Change(&pthis->skelAnime, &gHintNutsRunAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
        pthis->actionFunc = EnDntNomal_TargetReturn;
    }
}

void EnDntNomal_TargetReturn(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 dx;
    f32 dz;

    SkelAnime_Update(&pthis->skelAnime);
    dx = pthis->flowerPos.x - pthis->actor.world.pos.x;
    dz = -180.0f - pthis->actor.world.pos.z;

    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 3, 0x1388, 0);
    if (fabsf(pthis->actor.shape.rot.y - (s16)(Math_FAtan2F(dx, dz) * (0x8000 / M_PI))) < 20.0f) {
        pthis->actor.speedXZ = 1.0f;
    }
    if (Animation_OnFrame(&pthis->skelAnime, 0.0f) || Animation_OnFrame(&pthis->skelAnime, 6.0f)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    if (pthis->actor.world.pos.z < -172.0f) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gHintNutsBurrowAnim);
        Animation_Change(&pthis->skelAnime, &gHintNutsBurrowAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        pthis->actor.world.pos.z = -173.0f;
        pthis->actor.speedXZ = 0.0f;
        pthis->actionFunc = EnDntNomal_TargetBurrow;
    }
}

void EnDntNomal_TargetBurrow(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (frame >= pthis->endFrame) {
        pthis->actionFunc = EnDntNomal_SetupTargetWait;
    }
}

void EnDntNomal_SetupStageWait(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->timer3 == 0) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageHideAnim);
        Animation_Change(&pthis->skelAnime, &gDntStageHideAnim, 0.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        pthis->skelAnime.curFrame = 8.0f;
        pthis->isSolid = false;
        pthis->actionFunc = EnDntNomal_StageWait;
    }
}

void EnDntNomal_StageWait(EnDntNomal* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
}

void EnDntNomal_SetupStageUp(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->timer3 == 0) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageUpAnim);
        Animation_Change(&pthis->skelAnime, &gDntStageUpAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        if (pthis->action != DNT_ACTION_ATTACK) {
            pthis->rotDirection = -1;
        }
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 4.0f, 0, 10, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
        pthis->isSolid = true;
        pthis->actionFunc = EnDntNomal_StageUp;
    }
}

void EnDntNomal_StageUp(EnDntNomal* pthis, GlobalContext* globalCtx) {
    s16 rotTarget;
    f32 frame = pthis->skelAnime.curFrame;
    f32 turnMod;

    SkelAnime_Update(&pthis->skelAnime);
    if ((frame >= pthis->endFrame) && (pthis->action == DNT_ACTION_ATTACK)) {
        pthis->actionFunc = EnDntNomal_SetupStageAttack;
    } else {
        if (pthis->timer4 == 0) {
            turnMod = 0.0f;
            if (pthis->stagePrize == DNT_PRIZE_NONE) {
                Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
            } else {
                f32 dx = pthis->targetPos.x - pthis->actor.world.pos.x;
                f32 dz = pthis->targetPos.z - pthis->actor.world.pos.z;

                Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 1, 0xBB8, 0);
                turnMod = 90.0f;
            }
            if ((Rand_ZeroFloat(10.0f + turnMod) < 1.0f) && (pthis->action != DNT_ACTION_ATTACK)) {
                pthis->timer4 = (s16)Rand_ZeroFloat(30.0f) + 30;
            }
        } else {
            if (pthis->timer2 == 0) {
                pthis->rotDirection++;
                if (pthis->rotDirection > 1) {
                    pthis->rotDirection = -1;
                }
                pthis->timer2 = (s16)Rand_ZeroFloat(10.0f) + 10;
            }
            rotTarget = pthis->actor.yawTowardsPlayer;
            if (pthis->rotDirection != 0) {
                rotTarget += pthis->rotDirection * 0x1388;
            }
            Math_SmoothStepToS(&pthis->actor.shape.rot.y, rotTarget, 3, 0x1388, 0);
        }
        if (pthis->actor.xzDistToPlayer < 70.0f) {
            pthis->actionFunc = EnDntNomal_SetupStageHide;
        }
    }
}

void EnDntNomal_SetupStageUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->timer3 == 0) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageUnburrowAnim);
        Animation_Change(&pthis->skelAnime, &gDntStageUnburrowAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        pthis->isSolid = false;
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 4.0f, 0, 10, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
        pthis->actionFunc = EnDntNomal_StageUnburrow;
    }
}

void EnDntNomal_StageUnburrow(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 frame = pthis->skelAnime.curFrame;

    SkelAnime_Update(&pthis->skelAnime);
    if (frame >= pthis->endFrame) {
        if (pthis->action != DNT_ACTION_DANCE) {
            pthis->timer3 = (s16)Rand_ZeroFloat(2.0f) + (s16)(pthis->type * 0.5f);
            pthis->actionFunc = EnDntNomal_SetupStageCelebrate;
        } else {
            pthis->timer2 = 300;
            pthis->actionFunc = EnDntNomal_SetupStageDance;
        }
    }
}

void EnDntNomal_SetupStageCelebrate(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageWalkAnim);
    Animation_Change(&pthis->skelAnime, &gDntStageWalkAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.speedXZ = 3.0f;
    pthis->isSolid = true;
    pthis->actionFunc = EnDntNomal_StageCelebrate;
}

void EnDntNomal_StageCelebrate(EnDntNomal* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if ((pthis->timer1 == 0) && (pthis->timer3 == 0)) {
        f32 dx = pthis->targetPos.x - pthis->actor.world.pos.x;
        f32 dz = pthis->targetPos.z - pthis->actor.world.pos.z;

        if ((fabsf(dx) < 10.0f) && (fabsf(dz) < 10.0f) && (Message_GetState(&globalCtx->msgCtx) != TEXT_STATE_NONE)) {
            pthis->action = DNT_ACTION_PRIZE;
            pthis->actionFunc = EnDntNomal_SetupStageDance;
            pthis->actor.speedXZ = 0.0f;
            return;
        }
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(dx, dz) * (0x8000 / M_PI), 1, 0xBB8, 0);
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    } else {
        if (pthis->timer1 == 1) {
            pthis->timer3 = (s16)Rand_ZeroFloat(20.0f) + 20.0f;
        }
        Math_SmoothStepToS(&pthis->actor.world.rot.y, pthis->actor.yawTowardsPlayer, 0x14, 0x1388, 0);
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    }
    if (pthis->timer5 == 0) {
        pthis->timer5 = 20;
        if ((pthis->type & 1) == 0) {
            Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DAMAGE);
        }
    } else if ((pthis->timer5 & 3) == 0) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if ((pthis->actor.bgCheckFlags & 8) && (pthis->actor.bgCheckFlags & 1)) {
        pthis->actor.velocity.y = 7.5f;
    }
}

void EnDntNomal_SetupStageDance(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageDanceAnim);
    Animation_Change(&pthis->skelAnime, &gDntStageDanceAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->isSolid = true;
    pthis->timer3 = (s16)Rand_ZeroFloat(20.0f) + 20.0f;
    pthis->rotDirection = -1;
    if (Rand_ZeroFloat(1.99f) < 1.0f) {
        pthis->rotDirection = 1;
    }
    pthis->actionFunc = EnDntNomal_StageDance;
}

void EnDntNomal_StageDance(EnDntNomal* pthis, GlobalContext* globalCtx) {
    SkelAnime_Update(&pthis->skelAnime);
    if (pthis->timer2 == 0) {
        if (pthis->action == DNT_ACTION_DANCE) {
            pthis->action = DNT_ACTION_HIGH_RUPEES;
            pthis->actionFunc = EnDntNomal_SetupStageHide;
        } else {
            pthis->action = DNT_ACTION_NONE;
            pthis->actionFunc = EnDntNomal_StageSetupReturn;
        }
    } else if (pthis->timer3 != 0) {
        Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
        if (pthis->timer3 == 1) {
            pthis->timer4 = (s16)Rand_ZeroFloat(20.0f) + 20.0f;
            pthis->rotDirection = -pthis->rotDirection;
        }
    } else if (pthis->timer4 != 0) {
        pthis->actor.shape.rot.y += pthis->rotDirection * 0x800;
        if (pthis->timer4 == 1) {
            pthis->timer3 = (s16)Rand_ZeroFloat(20.0f) + 20.0f;
        }
    }
}

void EnDntNomal_SetupStageHide(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->timer3 != 0) {
        if ((pthis->timer3 == 1) && (pthis->ignore == 1)) {
            func_80078884(NA_SE_SY_ERROR);
        }
    } else {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageHideAnim);
        Animation_Change(&pthis->skelAnime, &gDntStageHideAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        pthis->isSolid = false;
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_DOWN);
        pthis->actionFunc = EnDntNomal_StageHide;
    }
}

void EnDntNomal_StageHide(EnDntNomal* pthis, GlobalContext* globalCtx) {
    EnExRuppy* rupee;
    f32 frame = pthis->skelAnime.curFrame;
    s16 rupeeColor;

    SkelAnime_Update(&pthis->skelAnime);
    if (frame >= pthis->endFrame) {
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->actor.world.pos, 4.0f, 0, 10, 3, 15, HAHEN_OBJECT_DEFAULT, 10, NULL);
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_UP);
        switch (pthis->action) {
            case DNT_ACTION_NONE:
                pthis->actionFunc = EnDntNomal_SetupStageWait;
                break;
            case DNT_ACTION_ATTACK:
                pthis->actionFunc = EnDntNomal_StageAttackHide;
                break;
            case DNT_ACTION_LOW_RUPEES:
            case DNT_ACTION_HIGH_RUPEES:
                rupee =
                    (EnExRuppy*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EX_RUPPY, pthis->actor.world.pos.x,
                                            pthis->actor.world.pos.y + 20.0f, pthis->actor.world.pos.z, 0, 0, 0, 3);
                if (rupee != NULL) {
                    rupeeColor = pthis->action - DNT_ACTION_LOW_RUPEES;
                    rupee->colorIdx = rupeeColor;
                    if (Rand_ZeroFloat(3.99f) < 1.0f) {
                        rupee->colorIdx = rupeeColor + 1;
                    }
                    rupee->actor.velocity.y = 5.0f;
                    if (rupee->colorIdx == 2) {
                        rupee->actor.velocity.y = 7.0f;
                    }
                    func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
                }
                pthis->action = DNT_ACTION_NONE;
                pthis->actionFunc = EnDntNomal_SetupStageWait;
                break;
        }
    }
}

void EnDntNomal_StageAttackHide(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->actor.xzDistToPlayer > 70.0f) {
        pthis->actionFunc = EnDntNomal_SetupStageUp;
    }
}

void EnDntNomal_SetupStageAttack(EnDntNomal* pthis, GlobalContext* globalCtx) {
    if (pthis->timer3 == 0) {
        pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageSpitAnim);
        Animation_Change(&pthis->skelAnime, &gDntStageSpitAnim, 1.0f, 0.0f, pthis->endFrame, ANIMMODE_ONCE, -10.0f);
        pthis->actor.colChkInfo.mass = 0xFF;
        pthis->isSolid = true;
        pthis->timer2 = 0;
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &pthis->actor, ACTORCAT_ENEMY);
        pthis->actionFunc = EnDntNomal_StageAttack;
    }
}

void EnDntNomal_StageAttack(EnDntNomal* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    Actor* nut;
    f32 frame = pthis->skelAnime.curFrame;
    f32 dz;
    f32 dx;
    f32 dy;

    SkelAnime_Update(&pthis->skelAnime);
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, pthis->actor.yawTowardsPlayer, 3, 0x1388, 0);
    dx = player->actor.world.pos.x - pthis->mouthPos.x;
    dy = player->actor.world.pos.y + 30.0f - pthis->mouthPos.y;
    dz = player->actor.world.pos.z - pthis->mouthPos.z;
    Math_SmoothStepToS(&pthis->actor.shape.rot.x, -(s16)(Math_FAtan2F(dy, sqrtf(SQ(dx) + SQ(dz))) * (0x8000 / M_PI)), 3,
                       0x1388, 0);
    if ((frame >= pthis->endFrame) && (pthis->timer2 == 0)) {
        pthis->timer2 = (s16)Rand_ZeroFloat(10.0f) + 10;
    }
    if (pthis->timer2 == 1) {
        pthis->spawnedItem = false;
        pthis->actionFunc = EnDntNomal_SetupStageAttack;
    } else if (pthis->actor.xzDistToPlayer < 50.0f) {
        pthis->action = DNT_ACTION_ATTACK;
        pthis->actionFunc = EnDntNomal_SetupStageHide;
    } else if ((frame >= 8.0f) && (!pthis->spawnedItem)) {
        Vec3f baseOffset;
        Vec3f spawnOffset;
        f32 spawnX;
        f32 spawnY;
        f32 spawnZ;

        Matrix_RotateY(pthis->actor.shape.rot.y / (f32)0x8000 * M_PI, MTXMODE_NEW);
        Matrix_RotateX(pthis->actor.shape.rot.x / (f32)0x8000 * M_PI, MTXMODE_APPLY);
        baseOffset.x = 0.0f;
        baseOffset.y = 0.0f;
        baseOffset.z = 5.0f;
        Matrix_MultVec3f(&baseOffset, &spawnOffset);
        spawnX = pthis->mouthPos.x + spawnOffset.x;
        spawnY = pthis->mouthPos.y + spawnOffset.y;
        spawnZ = pthis->mouthPos.z + spawnOffset.z;

        nut = Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_NUTSBALL, spawnX, spawnY, spawnZ,
                          pthis->actor.shape.rot.x, pthis->actor.shape.rot.y, pthis->actor.shape.rot.z, 4);
        if (nut != NULL) {
            nut->velocity.y = spawnOffset.y * 0.5f;
        }
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_THROW);
        pthis->spawnedItem = true;
    }
}

void EnDntNomal_StageSetupReturn(EnDntNomal* pthis, GlobalContext* globalCtx) {
    pthis->endFrame = (f32)Animation_GetLastFrame(&gDntStageWalkAnim);
    Animation_Change(&pthis->skelAnime, &gDntStageWalkAnim, 1.5f, 0.0f, pthis->endFrame, ANIMMODE_LOOP, -10.0f);
    pthis->actor.speedXZ = 4.0f;
    pthis->isSolid = false;
    pthis->actionFunc = EnDntNomal_StageReturn;
}

void EnDntNomal_StageReturn(EnDntNomal* pthis, GlobalContext* globalCtx) {
    f32 sp2C;
    f32 sp28;

    SkelAnime_Update(&pthis->skelAnime);
    sp2C = pthis->flowerPos.x - pthis->actor.world.pos.x;
    sp28 = pthis->flowerPos.z - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.shape.rot.y, Math_FAtan2F(sp2C, sp28) * (0x8000 / M_PI), 1, 0xBB8, 0);
    if (pthis->timer5 == 0) {
        pthis->timer5 = 10;
    } else if (!(pthis->timer5 & 1)) {
        Audio_PlayActorSound2(&pthis->actor, NA_SE_EN_NUTS_WALK);
    }
    if ((fabsf(sp2C) < 7.0f) && (fabsf(sp28) < 7.0f)) {
        pthis->actor.world.pos.x = pthis->flowerPos.x;
        pthis->actor.world.pos.z = pthis->flowerPos.z;
        pthis->actor.speedXZ = 0.0f;
        pthis->actionFunc = EnDntNomal_SetupStageHide;
    }
}

void EnDntNomal_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntNomal* pthis = (EnDntNomal*)thisx;

    if (pthis->timer1 != 0) {
        pthis->timer1--;
    }
    if (pthis->timer2 != 0) {
        pthis->timer2--;
    }
    if (pthis->timer3 != 0) {
        pthis->timer3--;
    }
    if (pthis->timer4 != 0) {
        pthis->timer4--;
    }
    if (pthis->timer5 != 0) {
        pthis->timer5--;
    }
    if (pthis->blinkTimer != 0) {
        pthis->blinkTimer--;
    }
    pthis->actor.world.rot.x = pthis->actor.shape.rot.x;
    if (pthis->actionFunc != EnDntNomal_StageCelebrate) {
        pthis->actor.world.rot.y = pthis->actor.shape.rot.y;
    }
    pthis->unkCounter++;
    if (pthis->type != ENDNTNOMAL_TARGET) {
        switch (pthis->stageSignal) {
            case DNT_SIGNAL_LOOK:
                if (pthis->stagePrize == DNT_PRIZE_NONE) {
                    pthis->actionFunc = EnDntNomal_SetupStageUp;
                } else {
                    pthis->actionFunc = EnDntNomal_StageUp;
                }
                break;
            case DNT_SIGNAL_CELEBRATE:
                pthis->action = DNT_ACTION_NONE;
                pthis->actor.colChkInfo.mass = 0;
                pthis->timer3 = (s16)Rand_ZeroFloat(3.0f) + (s16)(pthis->type * 0.5f);
                pthis->actionFunc = EnDntNomal_SetupStageUnburrow;
                break;
            case DNT_SIGNAL_DANCE:
                pthis->action = DNT_ACTION_DANCE;
                pthis->actionFunc = EnDntNomal_SetupStageUnburrow;
                break;
            case DNT_SIGNAL_HIDE:
                pthis->actionFunc = EnDntNomal_SetupStageHide;
                break;
            case DNT_SIGNAL_RETURN:
                pthis->actionFunc = EnDntNomal_StageSetupReturn;
                break;
            case DNT_SIGNAL_UNUSED:
                pthis->actionFunc = EnDntNomal_SetupStageDance;
                break;
            case DNT_SIGNAL_NONE:
                break;
        }
    }
    if (pthis->stageSignal != DNT_SIGNAL_NONE) {
        pthis->stageSignal = DNT_SIGNAL_NONE;
    }
    if (pthis->blinkTimer == 0) {
        pthis->eyeState++;
        if (pthis->eyeState >= 3) {
            pthis->eyeState = 0;
            pthis->blinkTimer = (s16)Rand_ZeroFloat(60.0f) + 20;
        }
    }
    pthis->actionFunc(pthis, globalCtx);
    Actor_MoveForward(&pthis->actor);
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 20.0f, 20.0f, 60.0f, 0x1D);
    if (pthis->type == ENDNTNOMAL_TARGET) {
        Collider_SetQuadVertices(&pthis->targetQuad, &pthis->targetVtx[0], &pthis->targetVtx[1], &pthis->targetVtx[2],
                                 &pthis->targetVtx[3]);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->targetQuad.base);
    } else {
        Collider_UpdateCylinder(&pthis->actor, &pthis->bodyCyl);
        if (pthis->isSolid) {
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->bodyCyl.base);
        }
    }
}

s32 EnDntNomal_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void* thisx) {
    EnDntNomal* pthis = (EnDntNomal*)thisx;

    if ((limbIndex == 1) || (limbIndex == 3) || (limbIndex == 4) || (limbIndex == 5) || (limbIndex == 6)) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1733);
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, sLeafColors[pthis->type - ENDNTNOMAL_STAGE].r,
                       sLeafColors[pthis->type - ENDNTNOMAL_STAGE].g, sLeafColors[pthis->type - ENDNTNOMAL_STAGE].b, 255);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1743);
    }
    return false;
}

void EnDntNomal_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnDntNomal* pthis = (EnDntNomal*)thisx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    if (pthis->type == ENDNTNOMAL_TARGET) {
        if (limbIndex == 5) {
            Matrix_MultVec3f(&zeroVec, &pthis->mouthPos);
        }
    } else if (limbIndex == 7) {
        Matrix_MultVec3f(&zeroVec, &pthis->mouthPos);
    }
}

void EnDntNomal_DrawStageScrub(Actor* thisx, GlobalContext* globalCtx) {
    static void* blinkTex[] = { gDntStageEyeOpenTex, gDntStageEyeHalfTex, gDntStageEyeShutTex };
    EnDntNomal* pthis = (EnDntNomal*)thisx;
    Vec3f dustScale = { 0.25f, 0.25f, 0.25f };
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1790);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(blinkTex[pthis->eyeState]));
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, EnDntNomal_OverrideLimbDraw,
                      EnDntNomal_PostLimbDraw, pthis);
    Matrix_Translate(pthis->flowerPos.x, pthis->flowerPos.y, pthis->flowerPos.z, MTXMODE_NEW);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, sLeafColors[pthis->type - ENDNTNOMAL_STAGE].r,
                   sLeafColors[pthis->type - ENDNTNOMAL_STAGE].g, sLeafColors[pthis->type - ENDNTNOMAL_STAGE].b, 255);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1814),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gDntStageFlowerDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1817);
    if (pthis->actionFunc == EnDntNomal_StageCelebrate) {
        func_80033C30(&pthis->actor.world.pos, &dustScale, 255, globalCtx);
    }
}

void EnDntNomal_DrawTargetScrub(Actor* thisx, GlobalContext* globalCtx) {
    EnDntNomal* pthis = (EnDntNomal*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1833);
    func_80093D18(globalCtx->state.gfxCtx);
    SkelAnime_DrawOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable, NULL, EnDntNomal_PostLimbDraw,
                      pthis);
    Matrix_Translate(pthis->flowerPos.x, pthis->flowerPos.y, pthis->flowerPos.z, MTXMODE_NEW);
    Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1848),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gHintNutsFlowerDL);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_dnt_nomal.c", 1851);
}

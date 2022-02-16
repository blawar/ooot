#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_G_SWITCH_Z_EN_G_SWITCH_C
#include "actor_common.h"
/*
 * File: z_en_g_switch.c
 * Overlay: ovl_En_G_Switch
 * Description: Silver rupees, shooting gallery targets, and horseback archery pots
 */

#include "z_en_g_switch.h"
#include "vt.h"
#include "overlays/actors/ovl_En_Syateki_Itm/z_en_syateki_itm.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "overlays/effects/ovl_Effect_Ss_HitMark/z_eff_ss_hitmark.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_tsubo/object_tsubo.h"
#include "def/code_8006BA00.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_collision_check.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_lib.h"
#include "def/z_parameter.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)


void EnGSwitch_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnGSwitch_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGSwitch_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGSwitch_DrawRupee(Actor* thisx, GlobalContext* globalCtx);
void EnGSwitch_DrawPot(Actor* thisx, GlobalContext* globalCtx);

void EnGSwitch_SilverRupeeTracker(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_SilverRupeeIdle(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_WaitForObject(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_SilverRupeeCollected(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_GalleryRupee(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_ArcheryPot(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_Kill(EnGSwitch* pthis, GlobalContext* globalCtx);

void EnGSwitch_SpawnEffects(EnGSwitch* pthis, Vec3f* pos, s16 scale, s16 colorIdx);
void EnGSwitch_UpdateEffects(EnGSwitch* pthis, GlobalContext* globalCtx);
void EnGSwitch_DrawEffects(EnGSwitch* pthis, GlobalContext* globalCtx);

static s8 majorScale_50[] = { 0, 2, 4, 5, 7 };


static s16 sCollectedCount = 0;

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 13, 40, 0, { 0, 0, 0 } },
};

// Unused, but probably intended to be this
static s16 sRupeeTypes[] = {
    ITEM00_RUPEE_GREEN, ITEM00_RUPEE_BLUE, ITEM00_RUPEE_RED, ITEM00_RUPEE_ORANGE, ITEM00_RUPEE_PURPLE,
};

ActorInit En_G_Switch_InitVars = {
    ACTOR_EN_G_SWITCH,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnGSwitch),
    (ActorFunc)EnGSwitch_Init,
    (ActorFunc)EnGSwitch_Destroy,
    (ActorFunc)EnGSwitch_Update,
    NULL,
    (ActorFunc)EnGSwitch_Reset,
};

void EnGSwitch_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGSwitch* pthis = (EnGSwitch*)thisx;

    pthis->type = (pthis->actor.params >> 0xC) & 0xF;
    pthis->switchFlag = pthis->actor.params & 0x3F;
    pthis->numEffects = ARRAY_COUNT(pthis->effects);
    // "index"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ インデックス ☆☆☆☆☆ %x\n" VT_RST, pthis->type);
    // "save"
    osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ セーブ\t     ☆☆☆☆☆ %x\n" VT_RST, pthis->switchFlag);
    switch (pthis->type) {
        case ENGSWITCH_SILVER_TRACKER:
            osSyncPrintf("\n\n");
            // "parent switch spawn"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 親スイッチ発生 ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
            sCollectedCount = 0;
            pthis->silverCount = pthis->actor.params >> 6;
            pthis->silverCount &= 0x3F;
            // "maximum number of checks"
            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ 最大チェック数 ☆☆☆☆☆ %d\n" VT_RST, pthis->silverCount);
            osSyncPrintf("\n\n");
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                // This is a reference to Hokuto no Ken
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Ｙｏｕ ａｒｅ Ｓｈｏｃｋ！  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
                Actor_Kill(&pthis->actor);
            } else {
                pthis->actionFunc = EnGSwitch_SilverRupeeTracker;
            }
            break;
        case ENGSWITCH_SILVER_RUPEE:
            osSyncPrintf("\n\n");
            // "child switch spawn"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 子スイッチ発生 ☆☆☆☆☆ %x\n" VT_RST, pthis->actor.params);
            pthis->colorIdx = 5;
            pthis->numEffects = 20;
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            pthis->actor.draw = EnGSwitch_DrawRupee;
            pthis->actor.shape.yOffset = 700.0f;
            if (Flags_GetSwitch(globalCtx, pthis->switchFlag)) {
                osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ Ｙｏｕ ａｒｅ Ｓｈｏｃｋ！  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
                Actor_Kill(&pthis->actor);
            } else {
                Actor_SetScale(&pthis->actor, 0.03f);
                pthis->actionFunc = EnGSwitch_SilverRupeeIdle;
            }
            break;
        case ENGSWITCH_ARCHERY_POT:
            osSyncPrintf("\n\n");
            // "Horseback archery destructible pot"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ やぶさめぶち抜き壷 ☆☆☆☆☆ \n" VT_RST);
            pthis->actor.gravity = -3.0f;
            pthis->colorIdx = Rand_ZeroFloat(2.99f);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            pthis->actor.scale.x = 0.25f;
            pthis->actor.scale.y = 0.45f;
            pthis->actor.scale.z = 0.25f;
            pthis->collider.info.bumper.dmgFlags = 0x1F820;
            pthis->objId = OBJECT_TSUBO;
            pthis->objIndex = Object_GetIndex(&globalCtx->objectCtx, pthis->objId);
            if (pthis->objIndex < 0) {
                Actor_Kill(&pthis->actor);
                // "what?"
                osSyncPrintf(VT_FGCOL(PURPLE) " なにみの？ %d\n" VT_RST "\n", pthis->objIndex);
                // "bank is funny"
                osSyncPrintf(VT_FGCOL(CYAN) " バンクおかしいしぞ！%d\n" VT_RST "\n", pthis->actor.params);
            }
            pthis->collider.dim.radius = 24;
            pthis->collider.dim.height = 74;
            pthis->collider.dim.yShift = 0;
            pthis->actionFunc = EnGSwitch_WaitForObject;
            break;
        case ENGSWITCH_TARGET_RUPEE:
            pthis->actor.shape.yOffset = 700.0f;
            Actor_SetScale(&pthis->actor, 0.05f);
            Collider_InitCylinder(globalCtx, &pthis->collider);
            Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
            pthis->actor.draw = EnGSwitch_DrawRupee;
            pthis->collider.dim.radius = 20;
            pthis->collider.dim.height = 60;
            pthis->collider.dim.yShift = 5;
            pthis->actionFunc = EnGSwitch_GalleryRupee;
            break;
    }
}

void EnGSwitch_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGSwitch* pthis = (EnGSwitch*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void EnGSwitch_Break(EnGSwitch* pthis, GlobalContext* globalCtx) {
    Vec3f randPos;
    Vec3f hitPos;
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    s32 i;

    randPos.x = pthis->actor.world.pos.x + Rand_CenteredFloat(40.0f);
    randPos.y = pthis->actor.world.pos.y + 30.0f + Rand_CenteredFloat(35.0f);
    randPos.z = pthis->actor.world.pos.z + Rand_CenteredFloat(40.0f);
    hitPos.x = pthis->collider.info.bumper.hitPos.x;
    hitPos.y = pthis->collider.info.bumper.hitPos.y;
    hitPos.z = pthis->collider.info.bumper.hitPos.z;
    EffectSsHitMark_SpawnCustomScale(globalCtx, EFFECT_HITMARK_WHITE, 700, &hitPos);
    if (pthis->type == ENGSWITCH_ARCHERY_POT) {
        velocity.y = 15.0f;
        EffectSsExtra_Spawn(globalCtx, &hitPos, &velocity, &accel, 5, 2);
    }
    if (pthis->type == ENGSWITCH_TARGET_RUPEE) {
        for (i = 0; i < pthis->numEffects; i++) {
            EnGSwitch_SpawnEffects(pthis, &randPos, 100, pthis->colorIdx);
        }
    }
}

void EnGSwitch_WaitForObject(EnGSwitch* pthis, GlobalContext* globalCtx) {
    if (Object_IsLoaded(&globalCtx->objectCtx, pthis->objIndex)) {
        gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[pthis->objIndex].vromStart.get());
        pthis->actor.objBankIndex = pthis->objIndex;
        pthis->actor.draw = EnGSwitch_DrawPot;
        pthis->actionFunc = EnGSwitch_ArcheryPot;
    }
}

void EnGSwitch_SilverRupeeTracker(EnGSwitch* pthis, GlobalContext* globalCtx) {

    if (pthis->noteIndex < sCollectedCount) {
        if (sCollectedCount < 5) {
            // "sound?"
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 音？ ☆☆☆☆☆ %d\n" VT_RST, pthis->noteIndex);
            Audio_PlaySoundTransposed(&D_801333D4, NA_SE_EV_FIVE_COUNT_LUPY, majorScale_50[pthis->noteIndex]);
            pthis->noteIndex = sCollectedCount;
        }
    }
    if (sCollectedCount >= pthis->silverCount) {
        // "It is now the end of the century."
        // This another reference to Hokuto no Ken.
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 時はまさに世紀末〜  ☆☆☆☆☆ %d\n" VT_RST, pthis->switchFlag);
        // "Last!"
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ らすとぉ！          ☆☆☆☆☆ \n" VT_RST);
        if ((globalCtx->sceneNum == SCENE_MEN) && (pthis->actor.room == 2)) {
            Flags_SetTempClear(globalCtx, pthis->actor.room);
        } else {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
            Flags_SetSwitch(globalCtx, pthis->switchFlag);
        }
        func_80078884(NA_SE_SY_GET_RUPY);
        Actor_Kill(&pthis->actor);
    }
}

void EnGSwitch_SilverRupeeIdle(EnGSwitch* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.shape.rot.y += 0x800;
    if (pthis->actor.xyzDistToPlayerSq < 900.0f) {
        Rupees_ChangeBy(5);
        sCollectedCount++;
        func_80078884(NA_SE_SY_GET_RUPY);
        pthis->actor.world.pos = player->actor.world.pos;
        pthis->actor.world.pos.y += 40.0f;
        if (LINK_IS_ADULT) {
            pthis->actor.world.pos.y += 20.0f;
        }
        pthis->actor.gravity = 0.0f;
        pthis->killTimer = 15;
        pthis->actionFunc = EnGSwitch_SilverRupeeCollected;
    }
}

void EnGSwitch_SilverRupeeCollected(EnGSwitch* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->actor.shape.rot.y += 0x3C0;
    if (pthis->killTimer == 0) {
        Actor_Kill(&pthis->actor);
        return;
    }
    pthis->actor.world.pos = player->actor.world.pos;
    pthis->actor.world.pos.y =
        player->actor.world.pos.y + 40.0f + (pthis->killTimer * 0.3f) * Math_SinS(pthis->killTimer * 0x3A98);
    if (LINK_IS_ADULT) {
        pthis->actor.world.pos.y += 20.0f;
    }
}

void EnGSwitch_GalleryRupee(EnGSwitch* pthis, GlobalContext* globalCtx) {
    EnSyatekiItm* gallery;

    pthis->actor.shape.rot.y += 0x3C0;
    if (pthis->delayTimer == 0) {
        switch (pthis->moveMode) {
            case GSWITCH_THROW:
                Actor_MoveForward(&pthis->actor);
                if ((pthis->actor.velocity.y < 0.0f) && (pthis->actor.world.pos.y < (pthis->actor.home.pos.y - 50.0f))) {
                    gallery = ((EnSyatekiItm*)pthis->actor.parent);
                    pthis->actor.velocity.y = 0.0f;
                    pthis->actor.gravity = 0.0f;
                    if (gallery->actor.update != NULL) {
                        gallery->targetState[pthis->index] = ENSYATEKIHIT_MISS;
                    }
                    Actor_Kill(&pthis->actor);
                }
                break;
            case GSWITCH_LEFT:
                func_8002D7EC(&pthis->actor);
                if ((pthis->actor.velocity.x < 0.0f) && (pthis->actor.world.pos.x < pthis->targetPos.x)) {
                    gallery = ((EnSyatekiItm*)pthis->actor.parent);
                    if (gallery->actor.update != NULL) {
                        gallery->targetState[pthis->index] = ENSYATEKIHIT_MISS;
                    }
                    Actor_Kill(&pthis->actor);
                }
                break;
            case GSWITCH_RIGHT:
                func_8002D7EC(&pthis->actor);
                if (pthis->actor.world.pos.x > pthis->targetPos.x) {
                    gallery = ((EnSyatekiItm*)pthis->actor.parent);
                    if (gallery->actor.update != NULL) {
                        gallery->targetState[pthis->index] = ENSYATEKIHIT_MISS;
                    }
                    Actor_Kill(&pthis->actor);
                }
                break;
            default:
                switch (pthis->moveState) {
                    case MOVE_TARGET:
                        if ((fabsf(pthis->actor.world.pos.x - pthis->targetPos.x) > 5.0f) ||
                            (fabsf(pthis->actor.world.pos.y - pthis->targetPos.y) > 5.0f)) {
                            Math_ApproachF(&pthis->actor.world.pos.x, pthis->targetPos.x, 0.3f, 30.0f);
                            Math_ApproachF(&pthis->actor.world.pos.y, pthis->targetPos.y, 0.3f, 30.0f);
                        } else {
                            pthis->moveState = MOVE_HOME;
                            pthis->waitTimer = 60;
                        }
                        break;
                    case MOVE_HOME:
                        if (pthis->waitTimer == 0) {
                            if ((fabsf(pthis->actor.world.pos.x - pthis->actor.home.pos.x) > 5.0f) ||
                                (fabsf(pthis->actor.world.pos.y - pthis->actor.home.pos.y) > 5.0f)) {
                                Math_ApproachF(&pthis->actor.world.pos.x, pthis->actor.home.pos.x, 0.3f, 30.0f);
                                Math_ApproachF(&pthis->actor.world.pos.y, pthis->actor.home.pos.y, 0.3f, 30.0f);
                            } else {
                                gallery = ((EnSyatekiItm*)pthis->actor.parent);
                                if (gallery->actor.update != NULL) {
                                    gallery->targetState[pthis->index] = ENSYATEKIHIT_MISS;
                                }
                                Actor_Kill(&pthis->actor);
                            }
                        }
                        break;
                }
                break;
        }
        if ((pthis->collider.base.acFlags & AC_HIT) || BREG(8)) {
            gallery = ((EnSyatekiItm*)pthis->actor.parent);
            pthis->collider.base.acFlags &= ~AC_HIT;
            if (gallery->actor.update != NULL) {
                gallery->hitCount++;
                gallery->targetState[pthis->index] = ENSYATEKIHIT_HIT;
                func_80078884(NA_SE_EV_HIT_SOUND);
                func_80078884(NA_SE_SY_GET_RUPY);
                // "Yeah !"
                osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ いぇぇーす！ＨＩＴ！！ ☆☆☆☆☆ %d\n" VT_RST, gallery->hitCount);
                EnGSwitch_Break(pthis, globalCtx);
                pthis->killTimer = 50;
                pthis->broken = true;
                pthis->actionFunc = EnGSwitch_Kill;
            }
        }
    }
}

void EnGSwitch_ArcheryPot(EnGSwitch* pthis, GlobalContext* globalCtx) {
    s32 i;
    s16 angle;
    Vec3f* thisPos = &pthis->actor.world.pos;

    pthis->actor.shape.rot.y += 0x3C0;
    if (pthis->collider.base.acFlags & AC_HIT) {
        pthis->collider.base.acFlags &= ~AC_HIT;
        for (i = 0, angle = 0; i < 30; i++, angle += 0x4E20) {
            Vec3f pos;
            Vec3f vel;
            f32 sn = Math_SinS(angle);
            f32 cs = Math_CosS(angle);
            f32 rand;
            s32 phi_s0;
            s32 scale;
            s32 pad;

            pos.x = sn * 8.0f;
            pos.y = 10.0f + Rand_CenteredFloat(5.0f);
            pos.z = cs * 8.0f;

            vel.x = pos.x / 2.0f;
            vel.y = 10.0f + Rand_ZeroOne() * 15.0f;
            vel.z = pos.z / 2.0f;

            pos.x += thisPos->x;
            pos.y += thisPos->y;
            pos.z += thisPos->z;

            rand = Rand_ZeroOne();
            if (rand < 0.2f) {
                phi_s0 = 0x60;
            } else if (rand < 0.6f) {
                phi_s0 = 0x40;
            } else {
                phi_s0 = 0x20;
            }

            scale = 30.0f + Rand_ZeroOne() * 130.0f;

            EffectSsKakera_Spawn(globalCtx, &pos, &vel, thisPos, -240, phi_s0, 10, 10, 0, scale, 0, 0x20, 60,
                                 KAKERA_COLOR_NONE, OBJECT_TSUBO, object_tsubo_DL_001960);
        }
        func_80033480(globalCtx, thisPos, 30.0f, 4, 20, 50, 0);
        Audio_PlaySoundAtPosition(globalCtx, thisPos, 40, NA_SE_EV_POT_BROKEN);
        EnGSwitch_Break(pthis, globalCtx);
        pthis->killTimer = 50;
        pthis->broken = true;
        pthis->actionFunc = EnGSwitch_Kill;
    }
}

void EnGSwitch_Kill(EnGSwitch* pthis, GlobalContext* globalCtx) {
    if (pthis->killTimer == 0) {
        Actor_Kill(&pthis->actor);
    }
}

void EnGSwitch_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGSwitch* pthis = (EnGSwitch*)thisx;

    pthis->actionFunc(pthis, globalCtx);
    if (pthis->killTimer != 0) {
        pthis->killTimer--;
    }
    if (pthis->waitTimer != 0) {
        pthis->waitTimer--;
    }
    if (pthis->delayTimer != 0) {
        pthis->delayTimer--;
    }
    if ((pthis->type != ENGSWITCH_SILVER_TRACKER) && (pthis->type != ENGSWITCH_SILVER_RUPEE) &&
        (pthis->type != ENGSWITCH_TARGET_RUPEE)) {
        Actor_MoveForward(&pthis->actor);
        Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 50.0f, 50.0f, 100.0f, 0x1C);
    }
    if (pthis->actor.draw != NULL) {
        if (pthis->type == ENGSWITCH_TARGET_RUPEE) {
            EnGSwitch_UpdateEffects(pthis, globalCtx);
        }
        if ((pthis->actionFunc != EnGSwitch_Kill) && (pthis->actionFunc != EnGSwitch_SilverRupeeIdle)) {
            Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
        }
    }
}

void EnGSwitch_DrawPot(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGSwitch* pthis = (EnGSwitch*)thisx;

    if (!pthis->broken) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 918);
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 925),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_tsubo_DL_0017C0);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 928);
    }
}

static void* sRupeeTextures[] = {
    gRupeeGreenTex, gRupeeBlueTex, gRupeeRedTex, gRupeePinkTex, gRupeeOrangeTex, gRupeeSilverTex,
};

void EnGSwitch_DrawRupee(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGSwitch* pthis = (EnGSwitch*)thisx;

    if (1) {}
    if (!pthis->broken) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 951);
        func_80093D18(globalCtx->state.gfxCtx);
        func_8002EBCC(&pthis->actor, globalCtx, 0);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 957),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sRupeeTextures[pthis->colorIdx]));
        gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 961);
    }
    if (pthis->type == ENGSWITCH_TARGET_RUPEE) {
        EnGSwitch_DrawEffects(pthis, globalCtx);
    }
}

void EnGSwitch_SpawnEffects(EnGSwitch* pthis, Vec3f* pos, s16 scale, s16 colorIdx) {
    EnGSwitchEffect* effect = pthis->effects;
    s16 i;

    for (i = 0; i < pthis->numEffects; i++, effect++) {
        if (!effect->flag) {
            Vec3f baseVel;
            f32 pitch;
            f32 yaw;

            effect->pos = *pos;
            effect->scale = scale;
            effect->colorIdx = colorIdx;
            effect->timer = 30;
            effect->rot.x = effect->rot.y = effect->rot.z = 0.0f;
            pitch = Rand_CenteredFloat(1000.0f) - 13000.0f;
            yaw = Rand_CenteredFloat(65535.0f);
            Matrix_RotateY(yaw, MTXMODE_NEW);
            Matrix_RotateX(pitch, MTXMODE_APPLY);
            baseVel.x = baseVel.y = 0.0f;
            baseVel.z = 20.0f;
            Matrix_MultVec3f(&baseVel, &effect->velocity);
            effect->flag = true;
            return;
        }
    }
}

void EnGSwitch_UpdateEffects(EnGSwitch* pthis, GlobalContext* globalCtx) {
    Vec3f temp;
    s16 i;
    EnGSwitchEffect* effect = pthis->effects;

    for (i = 0; i < pthis->numEffects; i++, effect++) {
        if (effect->flag) {
            effect->rot.x += Rand_ZeroOne() * 10.0f + 15.0f;
            effect->rot.y += Rand_ZeroOne() * 10.0f + 15.0f;
            effect->rot.z += Rand_ZeroOne() * 10.0f + 15.0f;
            temp.x = effect->pos.x + effect->velocity.x;
            temp.y = effect->pos.y + effect->velocity.y;
            temp.z = effect->pos.z + effect->velocity.z;
            Math_ApproachF(&effect->pos.x, temp.x, 0.3f, 30.0f);
            Math_ApproachF(&effect->pos.y, temp.y, 0.8f, 250.0f);
            Math_ApproachF(&effect->pos.z, temp.z, 0.3f, 30.0f);
            Math_ApproachF(&effect->velocity.y, -20.0f, 0.9f, 1.0f);
            if (effect->timer != 0) {
                effect->timer--;
            } else if (effect->scale < 10) {
                effect->flag = false;
            } else {
                effect->scale -= 2;
            }
        }
    }
}

void EnGSwitch_DrawEffects(EnGSwitch* pthis, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    EnGSwitchEffect* effect = pthis->effects;
    s16 i;
    f32 scale;
    s32 pad;

    OPEN_DISPS(gfxCtx, "../z_en_g_switch.c", 1073);
    func_80093D18(globalCtx->state.gfxCtx);
    for (i = 0; i < pthis->numEffects; i++, effect++) {
        if (effect->flag) {
            scale = effect->scale / 10000.0f;
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
            Matrix_RotateX(effect->rot.x, MTXMODE_APPLY);
            Matrix_RotateY(effect->rot.y, MTXMODE_APPLY);
            Matrix_RotateZ(effect->rot.z, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_g_switch.c", 1088),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sRupeeTextures[effect->colorIdx]));
            gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);
        }
    }
    CLOSE_DISPS(gfxCtx, "../z_en_g_switch.c", 1095);
}

void EnGSwitch_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    sCollectedCount = 0;

    sCylinderInit = {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_ON | AC_TYPE_PLAYER,
            OC1_NONE,
            OC2_TYPE_2,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK2,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_NONE,
        },
        { 13, 40, 0, { 0, 0, 0 } },
    };

    En_G_Switch_InitVars = {
        ACTOR_EN_G_SWITCH,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnGSwitch),
        (ActorFunc)EnGSwitch_Init,
        (ActorFunc)EnGSwitch_Destroy,
        (ActorFunc)EnGSwitch_Update,
        NULL,
        (ActorFunc)EnGSwitch_Reset,
    };

}

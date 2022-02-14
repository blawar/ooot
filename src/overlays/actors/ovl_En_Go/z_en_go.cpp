#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_GO_Z_EN_GO_C
#include "actor_common.h"
#include "z_en_go.h"
#include "overlays/actors/ovl_En_Bom/z_en_bom.h"
#include "objects/gameplay_keep/gameplay_keep.h"
#include "objects/object_oF1d_map/object_oF1d_map.h"
#include "def/code_800F7260.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_camera.h"
#include "def/z_collision_btltbls.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"
#include "def/z_skelanime.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnGo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGo_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGo_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A3FEB4(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_StopRolling(EnGo* pthis, GlobalContext* globalCtx);
void func_80A4008C(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_GoronLinkRolling(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_FireGenericActionFunc(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_CurledUp(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_WakeUp(EnGo* pthis, GlobalContext* globalCtx);

void func_80A40494(EnGo* pthis, GlobalContext* globalCtx);
void func_80A405CC(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_BiggoronActionFunc(EnGo* pthis, GlobalContext* globalCtx);
void func_80A408D8(EnGo* pthis, GlobalContext* globalCtx);

void func_80A40B1C(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_GetItem(EnGo* pthis, GlobalContext* globalCtx);
void func_80A40C78(EnGo* pthis, GlobalContext* globalCtx);
void EnGo_Eyedrops(EnGo* pthis, GlobalContext* globalCtx);
void func_80A40DCC(EnGo* pthis, GlobalContext* globalCtx);

void EnGo_AddDust(EnGo* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u8 initialTimer, f32 scale, f32 scaleStep);
void EnGo_UpdateDust(EnGo* pthis);
void EnGo_DrawDust(EnGo* pthis, GlobalContext* globalCtx);

ActorInit En_Go_InitVars = {
    ACTOR_EN_GO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_OF1D_MAP,
    sizeof(EnGo),
    (ActorFunc)EnGo_Init,
    (ActorFunc)EnGo_Destroy,
    (ActorFunc)EnGo_Update,
    (ActorFunc)EnGo_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
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
    { 20, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = {
    0, 0, 0, 0, MASS_IMMOVABLE,
};

typedef struct {
    AnimationHeader* animation;
    f32 playSpeed;
    u8 mode;
    f32 morphRate;
} EnGoAnimation;

static EnGoAnimation sAnimationEntries[] = {
    { &gGoronAnim_004930, 0.0f, ANIMMODE_LOOP_INTERP, 0.0f },
    { &gGoronAnim_004930, 0.0f, ANIMMODE_LOOP_INTERP, -10.0f },
    { &gGoronAnim_0029A8, 1.0f, ANIMMODE_LOOP_INTERP, -10.0f },
    { &gGoronAnim_010590, 1.0f, ANIMMODE_LOOP_INTERP, -10.0f },
};

void EnGo_SetupAction(EnGo* pthis, EnGoActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

u16 EnGo_GetTextID(GlobalContext* globalCtx, Actor* thisx) {
    Player* player = GET_PLAYER(globalCtx);

    switch (thisx->params & 0xF0) {
        case 0x90:
            if (gSaveContext.bgsFlag) {
                return 0x305E;
            } else if (INV_CONTENT(ITEM_TRADE_ADULT) >= ITEM_CLAIM_CHECK) {
                if (Environment_GetBgsDayCount() >= 3) {
                    return 0x305E;
                } else {
                    return 0x305D;
                }
            } else if (INV_CONTENT(ITEM_TRADE_ADULT) >= ITEM_EYEDROPS) {
                player->exchangeItemId = EXCH_ITEM_EYEDROPS;
                return 0x3059;
            } else if (INV_CONTENT(ITEM_TRADE_ADULT) >= ITEM_PRESCRIPTION) {
                return 0x3058;
            } else {
                player->exchangeItemId = EXCH_ITEM_SWORD_BROKEN;
                return 0x3053;
            }
        case 0x00:
            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_FIRE)) {
                if (gSaveContext.infTable[16] & 0x8000) {
                    return 0x3042;
                } else {
                    return 0x3041;
                }
            } else if (CHECK_OWNED_EQUIP(EQUIP_TUNIC, 1) || (gSaveContext.infTable[16] & 0x2000)) {
                if (gSaveContext.infTable[16] & 0x4000) {
                    return 0x3038;
                } else {
                    return 0x3037;
                }
            } else {
                if (gSaveContext.infTable[16] & 0x200) {
                    if (gSaveContext.infTable[16] & 0x400) {
                        return 0x3033;
                    } else {
                        return 0x3032;
                    }
                } else {
                    return 0x3030;
                }
            }
        case 0x10:
            if (Flags_GetSwitch(globalCtx, thisx->params >> 8)) {
                return 0x3052;
            } else {
                return 0x3051;
            }
        case 0x20:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.eventChkInf[2] & 0x8) {
                return 0x3021;
            } else if (gSaveContext.infTable[14] & 0x1) {
                return 0x302A;
            } else {
                return 0x3008;
            }
        case 0x30:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.eventChkInf[2] & 0x8) {
                return 0x3026;
            } else {
                return 0x3009;
            }
        case 0x40:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.eventChkInf[2] & 0x8) {
                return 0x3026;
            } else {
                return 0x300A;
            }
        case 0x50:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.infTable[15] & 1) {
                return 0x3015;
            } else {
                return 0x3014;
            }
        case 0x60:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.infTable[15] & 0x10) {
                return 0x3017;
            } else {
                return 0x3016;
            }
        case 0x70:
            if (CHECK_QUEST_ITEM(QUEST_GORON_RUBY)) {
                return 0x3027;
            } else if (gSaveContext.infTable[15] & 0x100) {
                return 0x3019;
            } else {
                return 0x3018;
            }
        default:
            return 0x0000;
    }
}

s16 EnGo_SetFlagsGetStates(GlobalContext* globalCtx, Actor* thisx) {
    s16 unkState = 1;
    f32 xzRange;
    f32 yRange = fabsf(thisx->yDistToPlayer) + 1.0f;

    xzRange = thisx->xzDistToPlayer + 1.0f;
    switch (Message_GetState(&globalCtx->msgCtx)) {
        if (globalCtx) {}
        case TEXT_STATE_CLOSING:
            switch (thisx->textId) {
                case 0x3008:
                    gSaveContext.infTable[14] |= 1;
                    unkState = 0;
                    break;
                case 0x300B:
                    gSaveContext.infTable[14] |= 0x800;
                    unkState = 0;
                    break;
                case 0x3014:
                    gSaveContext.infTable[15] |= 1;
                    unkState = 0;
                    break;
                case 0x3016:
                    gSaveContext.infTable[15] |= 0x10;
                    unkState = 0;
                    break;
                case 0x3018:
                    gSaveContext.infTable[15] |= 0x100;
                    unkState = 0;
                    break;
                case 0x3036:
                    func_8002F434(thisx, globalCtx, GI_TUNIC_GORON, xzRange, yRange);
                    gSaveContext.infTable[16] |= 0x2000; // EnGo exclusive flag
                    unkState = 2;
                    break;
                case 0x3037:
                    gSaveContext.infTable[16] |= 0x4000;
                    unkState = 0;
                    break;
                case 0x3041:
                    gSaveContext.infTable[16] |= 0x8000;
                    unkState = 0;
                    break;
                case 0x3059:
                    unkState = 2;
                    break;
                case 0x3052:
                case 0x3054:
                case 0x3055:
                case 0x305A:
                    unkState = 2;
                    break;
                case 0x305E:
                    unkState = 2;
                    break;
                default:
                    unkState = 0;
                    break;
            }
            break;
        case TEXT_STATE_CHOICE:
            if (Message_ShouldAdvance(globalCtx)) {
                switch (thisx->textId) {
                    case 0x300A:
                        if (globalCtx->msgCtx.choiceIndex == 0) {
                            if (CUR_UPG_VALUE(UPG_STRENGTH) != 0 || (gSaveContext.infTable[14] & 0x800)) {
                                thisx->textId = 0x300B;
                            } else {
                                thisx->textId = 0x300C;
                            }
                        } else {
                            thisx->textId = 0x300D;
                        }
                        Message_ContinueTextbox(globalCtx, thisx->textId);
                        unkState = 1;
                        break;
                    case 0x3034:
                        if (globalCtx->msgCtx.choiceIndex == 0) {
                            if (gSaveContext.infTable[16] & 0x800) {
                                thisx->textId = 0x3033;
                            } else {
                                thisx->textId = 0x3035;
                            }
                        } else if (gSaveContext.infTable[16] & 0x800) {
                            thisx->textId = 0x3036;
                        } else {
                            thisx->textId = 0x3033;
                        }
                        Message_ContinueTextbox(globalCtx, thisx->textId);
                        unkState = 1;
                        break;
                    case 0x3054:
                    case 0x3055:
                        if (globalCtx->msgCtx.choiceIndex == 0) {
                            unkState = 2;
                        } else {
                            thisx->textId = 0x3056;
                            Message_ContinueTextbox(globalCtx, thisx->textId);
                            unkState = 1;
                        }
                        gSaveContext.infTable[11] |= 0x10;
                        break;
                }
            }
            break;
        case TEXT_STATE_EVENT:
            if (Message_ShouldAdvance(globalCtx)) {
                switch (thisx->textId) {
                    case 0x3035:
                        gSaveContext.infTable[16] |= 0x800;
                    case 0x3032:
                    case 0x3033:
                        thisx->textId = 0x3034;
                        Message_ContinueTextbox(globalCtx, thisx->textId);
                        unkState = 1;
                        break;
                    default:
                        unkState = 2;
                        break;
                }
            }
            break;
        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(globalCtx)) {
                unkState = 3;
            }
            break;
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_9:
            break;
    }
    return unkState;
}

s32 func_80A3ED24(GlobalContext* globalCtx, EnGo* pthis, struct_80034A14_arg1* arg2, f32 arg3,
                  u16 (*getTextId)(GlobalContext*, Actor*), s16 (*unkFunc2)(GlobalContext*, Actor*)) {
    if (arg2->unk_00) {
        arg2->unk_00 = unkFunc2(globalCtx, &pthis->actor);
        return false;
    } else if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        arg2->unk_00 = 1;
        return true;
    } else if (!func_8002F2CC(&pthis->actor, globalCtx, arg3)) {
        return false;
    } else {
        pthis->actor.textId = getTextId(globalCtx, &pthis->actor);
        return false;
    }
}

void EnGo_ChangeAnimation(EnGo* pthis, s32 animIndex) {
    Animation_Change(&pthis->skelAnime, sAnimationEntries[animIndex].animation,
                     sAnimationEntries[animIndex].playSpeed * ((pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f), 0.0f,
                     Animation_GetLastFrame(sAnimationEntries[animIndex].animation), sAnimationEntries[animIndex].mode,
                     sAnimationEntries[animIndex].morphRate);
}

s32 EnGo_IsActorSpawned(EnGo* pthis, GlobalContext* globalCtx) {
    if (((pthis->actor.params) & 0xF0) == 0x90) {
        return true;
    } else if (globalCtx->sceneNum == SCENE_HIDAN && !Flags_GetSwitch(globalCtx, (pthis->actor.params) >> 8) &&
               LINK_IS_ADULT && (pthis->actor.params & 0xF0) == 0x10) {
        return true;
    } else if (globalCtx->sceneNum == SCENE_SPOT18 && LINK_IS_ADULT && (pthis->actor.params & 0xF0) == 0x00) {
        return true;
    } else if (globalCtx->sceneNum == SCENE_SPOT16 && LINK_IS_CHILD &&
               ((pthis->actor.params & 0xF0) == 0x20 || (pthis->actor.params & 0xF0) == 0x30 ||
                (pthis->actor.params & 0xF0) == 0x40)) {
        return true;
    } else if (globalCtx->sceneNum == SCENE_SPOT18 && LINK_IS_CHILD &&
               ((pthis->actor.params & 0xF0) == 0x50 || (pthis->actor.params & 0xF0) == 0x60 ||
                (pthis->actor.params & 0xF0) == 0x70)) {
        return true;
    } else {
        return false;
    }
}

f32 EnGo_GetGoronSize(EnGo* pthis) {
    switch (pthis->actor.params & 0xF0) {
        case 0x00:
            return 10.0f;
        case 0x20:
        case 0x30:
        case 0x50:
        case 0x60:
        case 0x70:
            return 20.0f;
        case 0x40:
            return 60.0f;
        default:
            return 20.0f;
    }
}

void func_80A3F060(EnGo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s16 unkVal;

    if (pthis->actionFunc != EnGo_BiggoronActionFunc && pthis->actionFunc != EnGo_FireGenericActionFunc &&
        pthis->actionFunc != func_80A40B1C) {
        unkVal = 1;
    }

    pthis->unk_1E0.unk_18 = player->actor.world.pos;
    pthis->unk_1E0.unk_14 = EnGo_GetGoronSize(pthis);
    func_80034A14(&pthis->actor, &pthis->unk_1E0, 4, unkVal);
}

void func_80A3F0E4(EnGo* pthis) {
    if (DECR(pthis->unk_214) == 0) {
        pthis->unk_216++;
        if (pthis->unk_216 >= 3) {
            pthis->unk_214 = Rand_S16Offset(30, 30);
            pthis->unk_216 = 0;
        }
    }
}

s32 EnGo_IsCameraModified(EnGo* pthis, GlobalContext* globalCtx) {
    f32 xyzDist;
    s16 yawDiff = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;
    Camera* camera = globalCtx->cameraPtrs[MAIN_CAM];

    if (fabsf(yawDiff) > 10920.0f) {
        return 0;
    }

    xyzDist = (pthis->actor.scale.x / 0.01f) * 10000.0f;
    if ((pthis->actor.params & 0xF0) == 0x90) {
        Camera_ChangeSetting(camera, CAM_SET_DIRECTED_YAW);
        xyzDist *= 4.8f;
    }

    if (fabsf(pthis->actor.xyzDistToPlayerSq) > xyzDist) {
        if (camera->setting == CAM_SET_DIRECTED_YAW) {
            Camera_ChangeSetting(camera, CAM_SET_NORMAL0);
        }
        return 0;
    } else {
        return 1;
    }
}

void EnGo_ReverseAnimation(EnGo* pthis) {
    f32 startFrame = pthis->skelAnime.startFrame;

    pthis->skelAnime.startFrame = pthis->skelAnime.endFrame;
    pthis->skelAnime.endFrame = startFrame;
}

void EnGo_UpdateShadow(EnGo* pthis) {
    s16 shadowAlpha;
    f32 currentFrame = pthis->skelAnime.curFrame;
    s16 shadowAlphaTarget = (pthis->skelAnime.animation == &gGoronAnim_004930 && currentFrame > 32.0f) ||
                                    pthis->skelAnime.animation != &gGoronAnim_004930
                                ? 255
                                : 0;

    shadowAlpha = pthis->actor.shape.shadowAlpha;
    Math_SmoothStepToS(&shadowAlpha, shadowAlphaTarget, 10, 60, 1);
    pthis->actor.shape.shadowAlpha = shadowAlpha;
}

s32 EnGo_FollowPath(EnGo* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* pointPos;
    f32 xDist;
    f32 zDist;

    if ((pthis->actor.params & 0xF) == 15) {
        return false;
    }

    path = &globalCtx->setupPathList[pthis->actor.params & 0xF];
    pointPos = SEGMENTED_TO_VIRTUAL(path->points);
    pointPos += pthis->unk_218;
    xDist = pointPos->x - pthis->actor.world.pos.x;
    zDist = pointPos->z - pthis->actor.world.pos.z;
    Math_SmoothStepToS(&pthis->actor.world.rot.y, (s16)(Math_FAtan2F(xDist, zDist) * ((f32)0x8000 / M_PI)), 10, 1000, 1);

    if ((SQ(xDist) + SQ(zDist)) < 600.0f) {
        pthis->unk_218++;
        if (pthis->unk_218 >= path->count) {
            pthis->unk_218 = 0;
        }

        if ((pthis->actor.params & 0xF0) != 0x00) {
            return true;
        } else if (Flags_GetSwitch(globalCtx, pthis->actor.params >> 8)) {
            return true;
        } else if (pthis->unk_218 >= pthis->actor.shape.rot.z) {
            pthis->unk_218 = 0;
        }

        return true;
    }

    return false;
}

s32 EnGo_SetMovedPos(EnGo* pthis, GlobalContext* globalCtx) {
    Path* path;
    Vec3s* pointPos;

    if ((pthis->actor.params & 0xF) == 0xF) {
        return false;
    } else {
        path = &globalCtx->setupPathList[pthis->actor.params & 0xF];
        pointPos = SEGMENTED_TO_VIRTUAL(path->points);
        pointPos += (path->count - 1);
        pthis->actor.world.pos.x = pointPos->x;
        pthis->actor.world.pos.y = pointPos->y;
        pthis->actor.world.pos.z = pointPos->z;
        pthis->actor.home.pos = pthis->actor.world.pos;
        return true;
    }
}

s32 EnGo_SpawnDust(EnGo* pthis, u8 initialTimer, f32 scale, f32 scaleStep, s32 numDustEffects, f32 radius, f32 xzAccel) {
    Vec3f pos = { 0.0f, 0.0f, 0.0f };
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.3f, 0.0f };
    s16 angle;
    s32 i;

    pos = pthis->actor.world.pos; // Overwrites pos
    pos.y = pthis->actor.floorHeight;
    angle = (Rand_ZeroOne() - 0.5f) * 0x10000;
    i = numDustEffects;
    while (i >= 0) {
        accel.x = (Rand_ZeroOne() - 0.5f) * xzAccel;
        accel.z = (Rand_ZeroOne() - 0.5f) * xzAccel;
        pos.x = (Math_SinS(angle) * radius) + pthis->actor.world.pos.x;
        pos.z = (Math_CosS(angle) * radius) + pthis->actor.world.pos.z;
        EnGo_AddDust(pthis, &pos, &velocity, &accel, initialTimer, scale, scaleStep);
        angle += (s16)(0x10000 / numDustEffects);
        i--;
    }
    return 0;
}

s32 EnGo_IsRollingOnGround(EnGo* pthis, s16 unkArg1, f32 unkArg2) {
    if ((pthis->actor.bgCheckFlags & 1) == 0 || pthis->actor.velocity.y > 0.0f) {
        return false;
    } else if (pthis->unk_1E0.unk_00 != 0) {
        return true;
    } else if (DECR(pthis->unk_21C)) {
        if ((pthis->unk_21C & 1)) {
            pthis->actor.world.pos.y += 1.5f;
        } else {
            pthis->actor.world.pos.y -= 1.5f;
        }
        return true;
    } else {
        pthis->unk_21A--;
        if (pthis->unk_21A <= 0) {
            if (pthis->unk_21A == 0) {
                pthis->unk_21C = Rand_S16Offset(60, 30);
                pthis->unk_21A = 0;
                pthis->actor.velocity.y = 0.0f;
                return true;
            }
            pthis->unk_21A = unkArg1;
        }
        pthis->actor.velocity.y = ((f32)pthis->unk_21A / (f32)unkArg1) * unkArg2;
        return true;
    }
}

void func_80A3F908(EnGo* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    f32 float1;
    s32 isUnkCondition;

    if (pthis->actionFunc == EnGo_BiggoronActionFunc || pthis->actionFunc == EnGo_GoronLinkRolling ||
        pthis->actionFunc == EnGo_FireGenericActionFunc || pthis->actionFunc == EnGo_Eyedrops ||
        pthis->actionFunc == func_80A40DCC || pthis->actionFunc == EnGo_GetItem || pthis->actionFunc == func_80A40C78 ||
        pthis->actionFunc == func_80A40B1C) {

        float1 = (pthis->collider.dim.radius + 30.0f);
        float1 *= (pthis->actor.scale.x / 0.01f);
        if ((pthis->actor.params & 0xF0) == 0x90) {
            float1 *= 4.8f;
        }

        if ((pthis->actor.params & 0xF0) == 0x90) {
            isUnkCondition =
                func_80A3ED24(globalCtx, pthis, &pthis->unk_1E0, float1, EnGo_GetTextID, EnGo_SetFlagsGetStates);
        } else {
            isUnkCondition = func_800343CC(globalCtx, &pthis->actor, &pthis->unk_1E0.unk_00, float1, EnGo_GetTextID,
                                           EnGo_SetFlagsGetStates);
        }

        if (((pthis->actor.params & 0xF0) == 0x90) && (isUnkCondition == true)) {
            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_SWORD_BROKEN) {
                if (func_8002F368(globalCtx) == EXCH_ITEM_SWORD_BROKEN) {
                    if (gSaveContext.infTable[11] & 0x10) {
                        pthis->actor.textId = 0x3055;
                    } else {
                        pthis->actor.textId = 0x3054;
                    }
                } else {
                    pthis->actor.textId = 0x3053;
                }
                player->actor.textId = pthis->actor.textId;
            }

            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_EYEDROPS) {
                if (func_8002F368(globalCtx) == EXCH_ITEM_EYEDROPS) {
                    pthis->actor.textId = 0x3059;
                } else {
                    pthis->actor.textId = 0x3058;
                }
                player->actor.textId = pthis->actor.textId;
            }
        }
    }
}

void EnGo_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGo* pthis = (EnGo*)thisx;
    s32 pad;
    Vec3f D_80A41B9C = { 0.0f, 0.0f, 0.0f }; // unused
    Vec3f D_80A41BA8 = { 0.0f, 0.0f, 0.0f }; // unused

    ActorShape_Init(&pthis->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gGoronSkel, NULL, 0, 0, 0);
    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinder(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&pthis->actor.colChkInfo, DamageTable_Get(0x16), &sColChkInfoInit);

    if (!EnGo_IsActorSpawned(pthis, globalCtx)) {
        Actor_Kill(&pthis->actor);
        return;
    }

    if ((pthis->actor.params & 0xF0) && ((pthis->actor.params & 0xF0) != 0x90)) {
        pthis->actor.flags &= ~ACTOR_FLAG_4;
        pthis->actor.flags &= ~ACTOR_FLAG_5;
    }

    EnGo_ChangeAnimation(pthis, 0);
    pthis->actor.targetMode = 6;
    pthis->unk_1E0.unk_00 = 0;
    pthis->actor.gravity = -1.0f;

    switch (pthis->actor.params & 0xF0) {
        case 0x00:
            Actor_SetScale(&pthis->actor, 0.008f);
            if (CHECK_OWNED_EQUIP(EQUIP_TUNIC, 1)) {
                EnGo_SetMovedPos(pthis, globalCtx);
                EnGo_SetupAction(pthis, EnGo_CurledUp);
            } else {
                pthis->actor.shape.yOffset = 1400.0f;
                pthis->actor.speedXZ = 3.0f;
                EnGo_SetupAction(pthis, EnGo_GoronLinkRolling);
            }
            break;
        case 0x10:
            pthis->skelAnime.curFrame = Animation_GetLastFrame(&gGoronAnim_004930);
            Actor_SetScale(&pthis->actor, 0.01f);
            EnGo_SetupAction(pthis, EnGo_FireGenericActionFunc);
            break;
        case 0x40:
            if (gSaveContext.infTable[14] & 0x800) {
                EnGo_SetMovedPos(pthis, globalCtx);
            }
            Actor_SetScale(&pthis->actor, 0.015f);
            EnGo_SetupAction(pthis, EnGo_CurledUp);
            break;
        case 0x30:
            pthis->actor.shape.yOffset = 1400.0f;
            Actor_SetScale(&pthis->actor, 0.01f);
            EnGo_SetupAction(pthis, func_80A3FEB4);
            break;
        case 0x90:
            pthis->actor.targetMode = 5;
            Actor_SetScale(&pthis->actor, 0.16f);
            EnGo_SetupAction(pthis, EnGo_CurledUp);
            break;
        case 0x20:
        case 0x50:
        case 0x60:
        case 0x70:
            Actor_SetScale(&pthis->actor, 0.01f);
            EnGo_SetupAction(pthis, EnGo_CurledUp);
            break;
        default:
            Actor_Kill(&pthis->actor);
    }
}

void EnGo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGo* pthis = (EnGo*)thisx;

    SkelAnime_Free(&pthis->skelAnime, globalCtx);
    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80A3FEB4(EnGo* pthis, GlobalContext* globalCtx) {
    if (!(pthis->actor.xyzDistToPlayerSq > SQ(1200.0f))) {
        EnGo_SetupAction(pthis, EnGo_StopRolling);
    }
}

void EnGo_StopRolling(EnGo* pthis, GlobalContext* globalCtx) {
    EnBom* bomb;

    if (DECR(pthis->unk_20E) == 0) {
        if (pthis->collider.base.ocFlags2 & 1) {
            pthis->collider.base.ocFlags2 &= ~1;
            globalCtx->damagePlayer(globalCtx, -4);
            func_8002F71C(globalCtx, &pthis->actor, 4.0f, pthis->actor.yawTowardsPlayer, 6.0f);
            pthis->unk_20E = 0x10;
        }
    }

    pthis->actor.speedXZ = 3.0f;
    if ((EnGo_FollowPath(pthis, globalCtx) == true) && (pthis->unk_218 == 0)) {
        bomb = (EnBom*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOM, pthis->actor.world.pos.x,
                                   pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 0);
        if (bomb != NULL) {
            bomb->timer = 0;
        }

        pthis->actor.speedXZ = 0.0f;
        EnGo_SetupAction(pthis, func_80A4008C);
    }

    pthis->actor.shape.rot = pthis->actor.world.rot;

    if (EnGo_IsRollingOnGround(pthis, 3, 6.0f)) {
        EnGo_SpawnDust(pthis, 12, 0.16f, 0.1f, 1, 10.0f, 20.0f);
    }
}

void func_80A4008C(EnGo* pthis, GlobalContext* globalCtx) {
    if (EnGo_IsRollingOnGround(pthis, 3, 6.0f)) {
        if (pthis->unk_21A == 0) {
            pthis->actor.shape.yOffset = 0.0f;
            EnGo_SetupAction(pthis, EnGo_CurledUp);
        } else {
            EnGo_SpawnDust(pthis, 12, 0.16f, 0.1f, 1, 10.0f, 20.0f);
        }
    }
}

void EnGo_GoronLinkRolling(EnGo* pthis, GlobalContext* globalCtx) {
    if ((EnGo_FollowPath(pthis, globalCtx) == true) && Flags_GetSwitch(globalCtx, pthis->actor.params >> 8) &&
        (pthis->unk_218 == 0)) {
        pthis->actor.speedXZ = 0.0f;
        EnGo_SetupAction(pthis, func_80A4008C);
        gSaveContext.infTable[16] |= 0x200;
    }

    pthis->actor.shape.rot = pthis->actor.world.rot;

    if (EnGo_IsRollingOnGround(pthis, 3, 6.0f)) {
        EnGo_SpawnDust(pthis, 12, 0.18f, 0.2f, 2, 13.0f, 20.0f);
    }
}

void EnGo_FireGenericActionFunc(EnGo* pthis, GlobalContext* globalCtx) {
}

void EnGo_CurledUp(EnGo* pthis, GlobalContext* globalCtx) {
    if ((DECR(pthis->unk_210) == 0) && EnGo_IsCameraModified(pthis, globalCtx)) {
        Audio_PlaySoundGeneral(NA_SE_EN_GOLON_WAKE_UP, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);

        pthis->skelAnime.playSpeed = 0.1f;
        pthis->skelAnime.playSpeed *= (pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f;

        EnGo_SetupAction(pthis, EnGo_WakeUp);
        if ((pthis->actor.params & 0xF0) == 0x90) {
            OnePointCutscene_Init(globalCtx, 4200, -99, &pthis->actor, MAIN_CAM);
        }
    }
}

void EnGo_WakeUp(EnGo* pthis, GlobalContext* globalCtx) {
    f32 frame;

    if (pthis->skelAnime.playSpeed != 0.0f) {
        Math_SmoothStepToF(&pthis->skelAnime.playSpeed, ((pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f) * 0.5f, 0.1f,
                           1000.0f, 0.1f);
        frame = pthis->skelAnime.curFrame;
        frame += pthis->skelAnime.playSpeed;

        if (frame <= 12.0f) {
            return;
        } else {
            pthis->skelAnime.curFrame = 12.0f;
            pthis->skelAnime.playSpeed = 0.0f;
            if ((pthis->actor.params & 0xF0) != 0x90) {
                pthis->unk_212 = 30;
                return;
            }
        }
    }

    if (DECR(pthis->unk_212) == 0) {
        Audio_PlaySoundGeneral(NA_SE_EN_GOLON_SIT_DOWN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        EnGo_SetupAction(pthis, func_80A405CC);
    } else if (!EnGo_IsCameraModified(pthis, globalCtx)) {
        EnGo_ReverseAnimation(pthis);
        pthis->skelAnime.playSpeed = 0.0f;
        EnGo_SetupAction(pthis, func_80A40494);
    }
}

void func_80A40494(EnGo* pthis, GlobalContext* globalCtx) {
    f32 frame;

    Math_SmoothStepToF(&pthis->skelAnime.playSpeed, ((pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f) * -0.5f, 0.1f,
                       1000.0f, 0.1f);
    frame = pthis->skelAnime.curFrame;
    frame += pthis->skelAnime.playSpeed;

    if (!(frame >= 0.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_DODO_M_GND, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        EnGo_SpawnDust(pthis, 10, 0.4f, 0.1f, 16, 26.0f, 2.0f);
        EnGo_ReverseAnimation(pthis);
        pthis->skelAnime.playSpeed = 0.0f;
        pthis->skelAnime.curFrame = 0.0f;
        pthis->unk_210 = Rand_S16Offset(30, 30);
        EnGo_SetupAction(pthis, EnGo_CurledUp);
    }
}

void func_80A405CC(EnGo* pthis, GlobalContext* globalCtx) {
    f32 lastFrame;
    f32 frame;

    lastFrame = Animation_GetLastFrame(&gGoronAnim_004930);
    Math_SmoothStepToF(&pthis->skelAnime.playSpeed, (pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f, 0.1f, 1000.0f,
                       0.1f);

    frame = pthis->skelAnime.curFrame;
    frame += pthis->skelAnime.playSpeed;

    if (!(frame < lastFrame)) {
        pthis->skelAnime.curFrame = lastFrame;
        pthis->skelAnime.playSpeed = 0.0f;
        pthis->unk_212 = Rand_S16Offset(30, 30);
        if (((pthis->actor.params & 0xF0) == 0x40) && ((gSaveContext.infTable[14] & 0x800) == 0)) {
            EnGo_SetupAction(pthis, func_80A40B1C);
        } else {
            EnGo_SetupAction(pthis, EnGo_BiggoronActionFunc);
        }
    }
}

void EnGo_BiggoronActionFunc(EnGo* pthis, GlobalContext* globalCtx) {
    if (((pthis->actor.params & 0xF0) == 0x90) && (pthis->unk_1E0.unk_00 == 2)) {
        if (gSaveContext.bgsFlag) {
            pthis->unk_1E0.unk_00 = 0;
        } else {
            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_EYEDROPS) {
                EnGo_ChangeAnimation(pthis, 2);
                pthis->unk_21E = 100;
                pthis->unk_1E0.unk_00 = 0;
                EnGo_SetupAction(pthis, EnGo_Eyedrops);
                globalCtx->msgCtx.msgMode = MSGMODE_PAUSED;
                gSaveContext.timer2State = 0;
                OnePointCutscene_Init(globalCtx, 4190, -99, &pthis->actor, MAIN_CAM);
            } else {
                pthis->unk_1E0.unk_00 = 0;
                EnGo_SetupAction(pthis, EnGo_GetItem);
                Message_CloseTextbox(globalCtx);
                EnGo_GetItem(pthis, globalCtx);
            }
        }
    } else if (((pthis->actor.params & 0xF0) == 0) && (pthis->unk_1E0.unk_00 == 2)) {
        EnGo_SetupAction(pthis, EnGo_GetItem);
        globalCtx->msgCtx.stateTimer = 4;
        globalCtx->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
    } else {
        if ((DECR(pthis->unk_212) == 0) && !EnGo_IsCameraModified(pthis, globalCtx)) {
            EnGo_ReverseAnimation(pthis);
            pthis->skelAnime.playSpeed = -0.1f;
            pthis->skelAnime.playSpeed *= (pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f;
            EnGo_SetupAction(pthis, func_80A408D8);
        }
    }
}

void func_80A408D8(EnGo* pthis, GlobalContext* globalCtx) {
    f32 frame;

    if (pthis->skelAnime.playSpeed != 0.0f) {
        Math_SmoothStepToF(&pthis->skelAnime.playSpeed, ((pthis->actor.params & 0xF0) == 0x90 ? 0.5f : 1.0f) * -1.0f,
                           0.1f, 1000.0f, 0.1f);
        frame = pthis->skelAnime.curFrame;
        frame += pthis->skelAnime.playSpeed;
        if (frame >= 12.0f) {
            return;
        } else {
            pthis->skelAnime.curFrame = 12.0f;
            pthis->skelAnime.playSpeed = 0.0f;
            if ((pthis->actor.params & 0xF0) != 0x90) {
                pthis->unk_212 = 30;
                return;
            }
        }
    }

    if (DECR(pthis->unk_212) == 0) {
        EnGo_SetupAction(pthis, func_80A40494);
    } else if (EnGo_IsCameraModified(pthis, globalCtx)) {
        EnGo_ReverseAnimation(pthis);
        Audio_PlaySoundGeneral(NA_SE_EN_GOLON_SIT_DOWN, &pthis->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
        pthis->skelAnime.playSpeed = 0.0f;
        EnGo_SetupAction(pthis, func_80A405CC);
    }
}

void func_80A40A54(EnGo* pthis, GlobalContext* globalCtx) {
    f32 float1 = ((f32)0x8000 / Animation_GetLastFrame(&gGoronAnim_010590));
    f32 float2 = pthis->skelAnime.curFrame * float1;

    pthis->actor.speedXZ = Math_SinS((s16)float2);
    if (EnGo_FollowPath(pthis, globalCtx) && pthis->unk_218 == 0) {
        EnGo_ChangeAnimation(pthis, 1);
        pthis->skelAnime.curFrame = Animation_GetLastFrame(&gGoronAnim_004930);
        pthis->actor.speedXZ = 0.0f;
        EnGo_SetupAction(pthis, EnGo_BiggoronActionFunc);
    }
}

void func_80A40B1C(EnGo* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.infTable[14] & 0x800) {
        EnGo_ChangeAnimation(pthis, 3);
        EnGo_SetupAction(pthis, func_80A40A54);
    } else {
        EnGo_BiggoronActionFunc(pthis, globalCtx);
    }
}

void EnGo_GetItem(EnGo* pthis, GlobalContext* globalCtx) {
    f32 xzDist;
    f32 yDist;
    s32 getItemId;

    if (Actor_HasParent(&pthis->actor, globalCtx)) {
        pthis->unk_1E0.unk_00 = 2;
        pthis->actor.parent = NULL;
        EnGo_SetupAction(pthis, func_80A40C78);
    } else {
        pthis->unk_20C = 0;
        if ((pthis->actor.params & 0xF0) == 0x90) {
            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_CLAIM_CHECK) {
                getItemId = GI_SWORD_BGS;
                pthis->unk_20C = 1;
            }
            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_EYEDROPS) {
                getItemId = GI_CLAIM_CHECK;
            }
            if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_SWORD_BROKEN) {
                getItemId = GI_PRESCRIPTION;
            }
        }

        if ((pthis->actor.params & 0xF0) == 0) {
            getItemId = GI_TUNIC_GORON;
        }

        yDist = fabsf(pthis->actor.yDistToPlayer) + 1.0f;
        xzDist = pthis->actor.xzDistToPlayer + 1.0f;
        func_8002F434(&pthis->actor, globalCtx, getItemId, xzDist, yDist);
    }
}

void func_80A40C78(EnGo* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 3) {
        EnGo_SetupAction(pthis, EnGo_BiggoronActionFunc);
        if ((pthis->actor.params & 0xF0) != 0x90) {
            pthis->unk_1E0.unk_00 = 0;
        } else if (pthis->unk_20C) {
            pthis->unk_1E0.unk_00 = 0;
            gSaveContext.bgsFlag = true;
        } else if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_PRESCRIPTION) {
            pthis->actor.textId = 0x3058;
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            pthis->unk_1E0.unk_00 = 1;
        } else if (INV_CONTENT(ITEM_TRADE_ADULT) == ITEM_CLAIM_CHECK) {
            pthis->actor.textId = 0x305C;
            Message_ContinueTextbox(globalCtx, pthis->actor.textId);
            pthis->unk_1E0.unk_00 = 1;
            Environment_ClearBgsDayCount();
        }
    }
}

void EnGo_Eyedrops(EnGo* pthis, GlobalContext* globalCtx) {
    if (DECR(pthis->unk_21E) == 0) {
        pthis->actor.textId = 0x305A;
        Message_ContinueTextbox(globalCtx, pthis->actor.textId);
        pthis->unk_1E0.unk_00 = 1;
        EnGo_SetupAction(pthis, func_80A40DCC);
    }
}

void func_80A40DCC(EnGo* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_1E0.unk_00 == 2) {
        EnGo_ChangeAnimation(pthis, 1);
        pthis->skelAnime.curFrame = Animation_GetLastFrame(&gGoronAnim_004930);
        Message_CloseTextbox(globalCtx);
        EnGo_SetupAction(pthis, EnGo_GetItem);
        EnGo_GetItem(pthis, globalCtx);
    }
}

void EnGo_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnGo* pthis = (EnGo*)thisx;

    Collider_UpdateCylinder(&pthis->actor, &pthis->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &pthis->collider.base);
    SkelAnime_Update(&pthis->skelAnime);

    if (pthis->actionFunc == EnGo_BiggoronActionFunc || pthis->actionFunc == EnGo_FireGenericActionFunc ||
        pthis->actionFunc == func_80A40B1C) {
        func_80034F54(globalCtx, pthis->jointTable, pthis->morphTable, 18);
    }

    EnGo_UpdateShadow(pthis);

    if (pthis->unk_1E0.unk_00 == 0) {
        Actor_MoveForward(&pthis->actor);
    }

    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 0.0f, 0.0f, 0.0f, 4);
    func_80A3F0E4(pthis);
    func_80A3F908(pthis, globalCtx);
    pthis->actionFunc(pthis, globalCtx);
    func_80A3F060(pthis, globalCtx);
}

void EnGo_DrawCurledUp(EnGo* pthis, GlobalContext* globalCtx) {
    Vec3f D_80A41BB4 = { 0.0f, 0.0f, 0.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2320);

    Matrix_Push();
    func_80093D18(globalCtx->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_go.c", 2326),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gGoronDL_00BD80);

    Matrix_MultVec3f(&D_80A41BB4, &pthis->actor.focus.pos);
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2341);
}

void EnGo_DrawRolling(EnGo* pthis, GlobalContext* globalCtx) {
    Vec3f D_80A41BC0 = { 0.0f, 0.0f, 0.0f };

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2355);

    Matrix_Push();
    func_80093D18(globalCtx->state.gfxCtx);
    Matrix_RotateZYX((s16)(globalCtx->state.frames * ((s16)pthis->actor.speedXZ * 1400)).toS16(), 0, pthis->actor.shape.rot.z,
                     MTXMODE_APPLY);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_go.c", 2368),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gGoronDL_00C140);
    Matrix_MultVec3f(&D_80A41BC0, &pthis->actor.focus.pos);
    Matrix_Pop();

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2383);
}

s32 EnGo_OverrideLimbDraw(GlobalContext* globalCtx, s32 limb, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnGo* pthis = (EnGo*)thisx;
    Vec3s vec1;
    f32 float1;

    if (limb == 17) {
        Matrix_Translate(2800.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec1 = pthis->unk_1E0.unk_08;
        float1 = (vec1.y / (f32)0x8000) * M_PI;
        Matrix_RotateX(float1, MTXMODE_APPLY);
        float1 = (vec1.x / (f32)0x8000) * M_PI;
        Matrix_RotateZ(float1, MTXMODE_APPLY);
        Matrix_Translate(-2800.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }

    if (limb == 10) {
        vec1 = pthis->unk_1E0.unk_0E;
        float1 = (vec1.y / (f32)0x8000) * M_PI;
        Matrix_RotateY(float1, MTXMODE_APPLY);
        float1 = (vec1.x / (f32)0x8000) * M_PI;
        Matrix_RotateX(float1, MTXMODE_APPLY);
    }

    if ((limb == 10) || (limb == 11) || (limb == 14)) {
        float1 = Math_SinS(pthis->jointTable[limb]);
        rot->y += float1 * 200.0f;
        float1 = Math_CosS(pthis->morphTable[limb]);
        rot->z += float1 * 200.0f;
    }

    return 0;
}

void EnGo_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    EnGo* pthis = (EnGo*)thisx;
    Vec3f D_80A41BCC = { 600.0f, 0.0f, 0.0f };

    if (limbIndex == 17) {
        Matrix_MultVec3f(&D_80A41BCC, &pthis->actor.focus.pos);
    }
}

void EnGo_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGo* pthis = (EnGo*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2479);

    EnGo_UpdateDust(pthis);
    Matrix_Push();
    EnGo_DrawDust(pthis, globalCtx);
    Matrix_Pop();

    if (pthis->actionFunc == EnGo_CurledUp) {
        EnGo_DrawCurledUp(pthis, globalCtx);
        return; // needed for match?
    } else if (pthis->actionFunc == EnGo_GoronLinkRolling || pthis->actionFunc == func_80A3FEB4 ||
               pthis->actionFunc == EnGo_StopRolling || pthis->actionFunc == func_80A3FEB4) {
        EnGo_DrawRolling(pthis, globalCtx);
        return; // needed for match?
    } else {
        func_800943C8(globalCtx->state.gfxCtx);

        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gGoronCsEyeOpenTex));
        gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gGoronCsMouthNeutralTex));

        SkelAnime_DrawFlexOpa(globalCtx, pthis->skelAnime.skeleton, pthis->skelAnime.jointTable,
                              pthis->skelAnime.dListCount, EnGo_OverrideLimbDraw, EnGo_PostLimbDraw, &pthis->actor);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2525);
        EnGo_DrawDust(pthis, globalCtx);
    }
}

void EnGo_AddDust(EnGo* pthis, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u8 initialTimer, f32 scale, f32 scaleStep) {
    EnGoEffect* dustEffect = pthis->dustEffects;
    s16 i;
    s16 timer;

    for (i = 0; i < ARRAY_COUNT(pthis->dustEffects); i++, dustEffect++) {
        if (dustEffect->type != 1) {
            dustEffect->scale = scale;
            dustEffect->scaleStep = scaleStep;
            if (1) {}
            timer = initialTimer;
            dustEffect->timer = timer;
            dustEffect->type = 1;
            dustEffect->initialTimer = initialTimer;
            dustEffect->pos = *pos;
            dustEffect->accel = *accel;
            dustEffect->velocity = *velocity;
            return;
        }
    }
}

void EnGo_UpdateDust(EnGo* pthis) {
    EnGoEffect* dustEffect = pthis->dustEffects;
    f32 randomNumber;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(pthis->dustEffects); i++, dustEffect++) {
        if (dustEffect->type) {
            dustEffect->timer--;
            if (dustEffect->timer == 0) {
                dustEffect->type = 0;
            }

            dustEffect->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
            randomNumber = Rand_ZeroOne() * 0.4f;
            dustEffect->accel.z = randomNumber - 0.2f;
            dustEffect->pos.x += dustEffect->velocity.x;
            dustEffect->pos.y += dustEffect->velocity.y;
            dustEffect->pos.z += dustEffect->velocity.z;
            dustEffect->velocity.x += dustEffect->accel.x;
            dustEffect->velocity.y += dustEffect->accel.y;
            dustEffect->velocity.z += randomNumber - 0.2f;
            dustEffect->scale += dustEffect->scaleStep;
        }
    }
}

void EnGo_DrawDust(EnGo* pthis, GlobalContext* globalCtx) {
    static void* dustTex[] = { gDust8Tex, gDust7Tex, gDust6Tex, gDust5Tex, gDust4Tex, gDust3Tex, gDust2Tex, gDust1Tex };
    EnGoEffect* dustEffect = pthis->dustEffects;
    s16 alpha;
    s16 firstDone;
    s16 index;
    s16 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2626);
    firstDone = false;
    func_80093D84(globalCtx->state.gfxCtx);
    if (1) {}
    for (i = 0; i < ARRAY_COUNT(pthis->dustEffects); i++, dustEffect++) {
        if (dustEffect->type) {
            if (!firstDone) {
                POLY_XLU_DISP = Gfx_CallSetupDL(POLY_XLU_DISP, 0);
                gSPDisplayList(POLY_XLU_DISP++, gGoronDL_00FD40);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 60, 20, 0);
                firstDone = true;
            }

            alpha = dustEffect->timer * (255.0f / dustEffect->initialTimer);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 170, 130, 90, alpha);
            gDPPipeSync(POLY_XLU_DISP++);
            Matrix_Translate(dustEffect->pos.x, dustEffect->pos.y, dustEffect->pos.z, MTXMODE_NEW);
            func_800D1FD4(&globalCtx->billboardMtxF);
            Matrix_Scale(dustEffect->scale, dustEffect->scale, 1.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_go.c", 2664),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            index = dustEffect->timer * (8.0f / dustEffect->initialTimer);
            gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(dustTex[index]));
            gSPDisplayList(POLY_XLU_DISP++, gGoronDL_00FD50);
        }
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_go.c", 2678);
}

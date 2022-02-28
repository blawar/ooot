#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_DNT_DEMO_Z_EN_DNT_DEMO_C
#include "actor_common.h"
#include "z_debug_display.h"
/*
 * File: z_en_dnt_demo.c
 * Overlay: ovl_En_Dnt_Demo
 * Description: Forest Stage minigame
 */

#include "z_en_dnt_demo.h"

#include "overlays/actors/ovl_En_Dnt_Jiji/z_en_dnt_jiji.h"
#include "overlays/actors/ovl_En_Dnt_Nomal/z_en_dnt_nomal.h"
#include "vt.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_player_lib.h"

#define FLAGS 0


void EnDntDemo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnDntDemo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Update(Actor* pthis, GlobalContext* globalCtx);

void EnDntDemo_Judge(EnDntDemo* pthis, GlobalContext* globalCtx);
void EnDntDemo_Results(EnDntDemo* pthis, GlobalContext* globalCtx);
void EnDntDemo_Prize(EnDntDemo* pthis, GlobalContext* globalCtx);

ActorInit En_Dnt_Demo_InitVars = {
    ACTOR_EN_DNT_DEMO,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntDemo),
    (ActorFunc)EnDntDemo_Init,
    (ActorFunc)EnDntDemo_Destroy,
    (ActorFunc)EnDntDemo_Update,
    NULL,
    (ActorFunc)EnDntDemo_Reset,
};

//! @bug
//! This table is missing a column for the Mask of Truth, so it reads the first value of the next row. In the last row,
//! it reads the first entry of sResultValues (4), which is an invalid result. The scrubs have no reaction in pthis case.
static s16 sResultTable[8][7] = {
    /* Keaton    Skull     Spooky    Bunny     Goron      Zora     Gerudo         Truth   */
    { DNT_LIKE, DNT_HATE, DNT_LIKE, DNT_HATE, DNT_LOVE, DNT_LIKE, DNT_HATE }, /* DNT_HATE */
    { DNT_HATE, DNT_LIKE, DNT_HATE, DNT_LIKE, DNT_HATE, DNT_HATE, DNT_LOVE }, /* DNT_LOVE */
    { DNT_LOVE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_LIKE, DNT_LIKE, DNT_LIKE }, /* DNT_HATE */
    { DNT_HATE, DNT_LOVE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_LIKE }, /* DNT_LIKE */
    { DNT_LIKE, DNT_LIKE, DNT_LOVE, DNT_LIKE, DNT_LIKE, DNT_LIKE, DNT_HATE }, /* DNT_LIKE */
    { DNT_LIKE, DNT_LIKE, DNT_LIKE, DNT_LOVE, DNT_HATE, DNT_LOVE, DNT_LIKE }, /* DNT_HATE */
    { DNT_HATE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_HATE, DNT_HATE }, /* DNT_LOVE */
    { DNT_LOVE, DNT_LOVE, DNT_LOVE, DNT_LOVE, DNT_LOVE, DNT_LOVE, DNT_LOVE }, /* INVALID  */
};

static s16 sResultValues[3][2] = {
    /* DNT_LIKE */ { DNT_SIGNAL_HIDE, DNT_ACTION_LOW_RUPEES },
    /* DNT_HATE */ { DNT_SIGNAL_HIDE, DNT_ACTION_ATTACK },
    /* DNT_LOVE */ { DNT_SIGNAL_DANCE, DNT_ACTION_DANCE },
};

static Vec3f sScrubPos[] = {
    { 3810.0f, -20.0f, 1010.0f }, { 3890.0f, -20.0f, 990.0f }, { 3730.0f, -20.0f, 950.0f },
    { 3840.0f, -20.0f, 930.0f },  { 3910.0f, -20.0f, 870.0f }, { 3780.0f, -20.0f, 860.0f },
    { 3710.0f, -20.0f, 840.0f },  { 3860.0f, -20.0f, 790.0f }, { 3750.0f, -20.0f, 750.0f },
};

void EnDntDemo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnDntDemo_Init(Actor* thisx, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    EnDntDemo* pthis = (EnDntDemo*)thisx;
    s32 i;
    s32 pad;

    osSyncPrintf("\n\n");
    // "Deku Scrub mask show start"
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ デグナッツお面品評会開始 ☆☆☆☆☆ \n" VT_RST);
    for (i = 0; i < 9; i++) {
        pthis->scrubPos[i] = sScrubPos[i];
        pthis->scrubs[i] = (EnDntNomal*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx,
                                                          ACTOR_EN_DNT_NOMAL, pthis->scrubPos[i].x, pthis->scrubPos[i].y,
                                                          pthis->scrubPos[i].z, 0, 0, 0, i + ENDNTNOMAL_STAGE);
        if (pthis->scrubs[i] != NULL) {
            // "zako zako" [small fries]
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ザコザコ ☆☆☆☆☆ %x\n" VT_RST, pthis->scrubs[i]);
        }
    }

    pthis->leaderPos.x = 4050.0f;
    pthis->leaderPos.y = -20.0f;
    pthis->leaderPos.z = 1000.0f;
    pthis->leader = (EnDntJiji*)Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_EN_DNT_JIJI,
                                                  pthis->leaderPos.x, pthis->leaderPos.y, pthis->leaderPos.z, 0, 0, 0, 0);
    if (pthis->leader != NULL) {
        // "jiji jiji jiji jiji jiji" [onomatopoeia for the scrub sound?]
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ じじじじじじじじじじい ☆☆☆☆☆ %x\n" VT_RST, pthis->leader);
    }
    pthis->subCamera = 0;
    pthis->actor.flags &= ~ACTOR_FLAG_0;
    pthis->actionFunc = EnDntDemo_Judge;
}

void EnDntDemo_Judge(EnDntDemo* pthis, GlobalContext* globalCtx) {
    s16 delay;
    s16 reaction;
    s16 rand9;
    s16 maskIdx;
    s16 resultIdx;
    u8 ignore;
    s32 i;

    if (pthis->leaderSignal != DNT_SIGNAL_NONE) {
        for (i = 0; i < 9; i++) {
            pthis->scrubs[i]->stageSignal = pthis->leaderSignal;
            pthis->scrubs[i]->action = pthis->action;
            pthis->scrubs[i]->stagePrize = DNT_PRIZE_NONE;
        }
        if (pthis->leader->isSolid) {
            pthis->leader->stageSignal = DNT_LEADER_SIGNAL_BURROW;
        }
        pthis->leaderSignal = DNT_SIGNAL_NONE;
        pthis->actionFunc = EnDntDemo_Results;
    } else if ((pthis->actor.xzDistToPlayer > 30.0f) || (Player_GetMask(globalCtx) == 0)) {
        pthis->debugArrowTimer++;
        if (pthis->subCamera != SUBCAM_FREE) {
            pthis->subCamera = SUBCAM_FREE;
        }
        if (pthis->judgeTimer != 0) {
            for (i = 0; i < 9; i++) {
                pthis->scrubs[i]->stageSignal = DNT_SIGNAL_HIDE;
            }
            pthis->judgeTimer = 0;
        }
    } else {
        if ((Player_GetMask(globalCtx) != 0) && (pthis->subCamera == SUBCAM_FREE)) {
            pthis->subCamera = OnePointCutscene_Init(globalCtx, 2220, -99, &pthis->scrubs[3]->actor, MAIN_CAM);
        }
        pthis->debugArrowTimer = 0;
        if (pthis->judgeTimer == 40) {
            for (i = 0; i < 9; i++) {
                pthis->scrubs[i]->stageSignal = DNT_SIGNAL_LOOK;
            }
        }
        if (pthis->judgeTimer > 40) {
            // "gera gera" [onomatopoeia for loud giggling]
            osSyncPrintf(VT_FGCOL(RED) "☆☆☆☆☆ げらげら ☆☆☆☆☆ \n" VT_RST);
            func_800F436C(&pthis->actor.projectedPos, NA_SE_EV_CROWD - SFX_FLAG, 2.0f);
        }
        if (pthis->judgeTimer < 120) {
            pthis->judgeTimer++;
        } else {
            ignore = false;
            reaction = DNT_SIGNAL_NONE;
            delay = 0;
            switch (Player_GetMask(globalCtx)) {
                case PLAYER_MASK_SKULL:
                    if (!(gSaveContext.itemGetInf[1] & 0x4000)) {
                        reaction = DNT_SIGNAL_CELEBRATE;
                        pthis->prize = DNT_PRIZE_STICK;
                        Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_SARIA_THEME);
                        break;
                    }
                case PLAYER_MASK_TRUTH:
                    if (!(gSaveContext.itemGetInf[1] & 0x8000) && (Player_GetMask(globalCtx) != PLAYER_MASK_SKULL)) {
                        Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0,
                                               &gReverbAdd2);
                        pthis->prize = DNT_PRIZE_NUTS;
                        pthis->leader->stageSignal = DNT_LEADER_SIGNAL_UP;
                        reaction = DNT_SIGNAL_LOOK;
                        if (pthis->subCamera != SUBCAM_FREE) {
                            pthis->subCamera = SUBCAM_FREE;
                            reaction = DNT_SIGNAL_LOOK;
                            OnePointCutscene_Init(globalCtx, 2340, -99, &pthis->leader->actor, MAIN_CAM);
                        }
                        break;
                    }
                case PLAYER_MASK_KEATON:
                case PLAYER_MASK_SPOOKY:
                case PLAYER_MASK_BUNNY:
                case PLAYER_MASK_GORON:
                case PLAYER_MASK_ZORA:
                case PLAYER_MASK_GERUDO:
                    rand9 = Rand_ZeroFloat(8.99f);
                    maskIdx = Player_GetMask(globalCtx);
                    maskIdx--;
                    if (rand9 == 8) {
                        ignore = true;
                        delay = 8;
                        reaction = DNT_SIGNAL_HIDE;
                        // "Special!"
                        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 特別！ ☆☆☆☆☆ \n" VT_RST);
                    } else {
                        if (maskIdx >= PLAYER_MASK_MAX - 1) {
                            // "This is dangerous!"
                            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ヤバいよこれ！ ☆☆☆☆☆ \n" VT_RST);
                            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ ヤバいよこれ！ ☆☆☆☆☆ \n" VT_RST);
                            osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ ヤバいよこれ！ ☆☆☆☆☆ \n" VT_RST);
                            osSyncPrintf(VT_FGCOL(CYAN) "☆☆☆☆☆ ヤバいよこれ！ ☆☆☆☆☆ \n" VT_RST);
                            maskIdx = Rand_ZeroFloat(7.99f);
                        }

                        resultIdx = sResultTable[rand9][maskIdx];
                        reaction = sResultValues[resultIdx][0];
                        pthis->action = sResultValues[resultIdx][1];
                        switch (pthis->action) {
                            case DNT_ACTION_LOW_RUPEES:
                                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_COURTYARD);
                                break;
                            case DNT_ACTION_ATTACK:
                                if (pthis->subCamera != SUBCAM_FREE) {
                                    pthis->subCamera = SUBCAM_FREE;
                                    OnePointCutscene_Init(globalCtx, 2350, -99, &pthis->scrubs[3]->actor, MAIN_CAM);
                                }
                                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_ENEMY | 0x800);
                                break;
                            case DNT_ACTION_DANCE:
                                Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_SHOP);
                                break;
                        }
                        osSyncPrintf("\n\n");
                        // "Each index 1"
                        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 各インデックス１ ☆☆☆☆☆ %d\n" VT_RST, rand9);
                        // "Each index 2"
                        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 各インデックス２ ☆☆☆☆☆ %d\n" VT_RST, maskIdx);
                        // "Each index 3"
                        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ 各インデックス３ ☆☆☆☆☆ %d\n" VT_RST, resultIdx);
                        osSyncPrintf("\n");
                        // "What kind of evaluation?"
                        osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ どういう評価？  ☆☆☆☆☆☆ %d\n" VT_RST, reaction);
                        // "What kind of action?"
                        osSyncPrintf(VT_FGCOL(PURPLE) "☆☆☆☆☆ どういうアクション？  ☆☆☆ %d\n" VT_RST, pthis->action);
                        osSyncPrintf("\n\n");
                        break;
                    }
            }
            if (reaction != DNT_SIGNAL_NONE) {
                for (i = 0; i < 9; i++) {
                    if (delay != 0) {
                        pthis->scrubs[i]->timer3 = delay * i;
                    }
                    pthis->scrubs[i]->action = pthis->action;
                    pthis->scrubs[i]->stageSignal = reaction;
                    pthis->scrubs[i]->ignore = ignore;
                    if (pthis->prize != DNT_PRIZE_NONE) {
                        pthis->scrubs[i]->timer1 = 300;
                        pthis->scrubs[i]->stagePrize = pthis->prize;
                        pthis->scrubs[i]->targetPos = pthis->leader->actor.world.pos;
                        if (pthis->prize == DNT_PRIZE_NUTS) {
                            pthis->leader->stageSignal = DNT_LEADER_SIGNAL_UP;
                        }
                        if (pthis->prize == DNT_PRIZE_STICK) {
                            pthis->leader->timer = 300;
                        }
                    }
                }
                pthis->actionFunc = EnDntDemo_Results;
            }
        }
    }
}

void EnDntDemo_Results(EnDntDemo* pthis, GlobalContext* globalCtx) {
    s32 i;

    if (pthis->leaderSignal != DNT_SIGNAL_NONE) {
        for (i = 0; i < 9; i++) {
            pthis->scrubs[i]->action = pthis->action;
            pthis->scrubs[i]->stageSignal = pthis->leaderSignal;
            pthis->scrubs[i]->stagePrize = DNT_PRIZE_NONE;
        }
        if (pthis->leader->action == DNT_LEADER_ACTION_UP) {
            pthis->leader->stageSignal = DNT_LEADER_SIGNAL_BURROW;
        } else if (pthis->leader->unburrow) {
            pthis->leader->stageSignal = DNT_LEADER_SIGNAL_RETURN;
        } else {
            pthis->leader->action = DNT_LEADER_ACTION_ATTACK;
        }
        pthis->leader->timer = 0;
        pthis->leaderSignal = pthis->action = DNT_SIGNAL_NONE;
        pthis->actionFunc = EnDntDemo_Prize;
    } else if (pthis->prize == DNT_PRIZE_STICK) {
        for (i = 0; i < 9; i++) {
            s16 offsetAngle = -pthis->leader->actor.shape.rot.y;
            Vec3f leaderPos = pthis->leader->actor.world.pos;
            f32 offsetDist;

            if (!(i & 1)) {
                offsetAngle -= 0x59D8;
            }
            offsetDist = ((i + 1) * 20.0f) + 20.0f;
            pthis->scrubs[i]->timer2 = 10;
            pthis->scrubs[i]->targetPos.x = leaderPos.x + Math_SinS(offsetAngle) * offsetDist;
            pthis->scrubs[i]->targetPos.y = leaderPos.y;
            pthis->scrubs[i]->targetPos.z = leaderPos.z + Math_CosS(offsetAngle) * offsetDist;
        }
    }
}

void EnDntDemo_Prize(EnDntDemo* pthis, GlobalContext* globalCtx) {
    s32 i;

    if (pthis->leaderSignal != DNT_SIGNAL_NONE) {
        for (i = 0; i < 9; i++) {
            pthis->scrubs[i]->action = pthis->action;
            pthis->scrubs[i]->stageSignal = pthis->leaderSignal;
            pthis->scrubs[i]->stagePrize = DNT_PRIZE_NONE;
        }
        pthis->leaderSignal = pthis->action = DNT_SIGNAL_NONE;
    }
}

void EnDntDemo_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnDntDemo* pthis = (EnDntDemo*)thisx;

    if (pthis->unkTimer2 != 0) {
        pthis->unkTimer2--;
    }
    if (pthis->unkTimer1 != 0) {
        pthis->unkTimer1--;
    }
    pthis->actionFunc(pthis, globalCtx);
}

void EnDntDemo_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Dnt_Demo_InitVars = {
        ACTOR_EN_DNT_DEMO,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnDntDemo),
        (ActorFunc)EnDntDemo_Init,
        (ActorFunc)EnDntDemo_Destroy,
        (ActorFunc)EnDntDemo_Update,
        NULL,
        (ActorFunc)EnDntDemo_Reset,
    };

}

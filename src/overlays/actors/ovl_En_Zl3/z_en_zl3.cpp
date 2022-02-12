#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_ZL3_Z_EN_ZL3_C
#include "actor_common.h"
/*
 * File: z_en_zl3.c
 * Overlay: ovl_En_Zl3
 * Description: Adult Zelda
 */

#include "z_en_zl3.h"

#include "vt.h"
#include "overlays/actors/ovl_En_Encount2/z_en_encount2.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"
#include "objects/object_zl2/object_zl2.h"
#include "objects/object_zl2_anime2/object_zl2_anime2.h"
#include "def/code_800EC960.h"
#include "def/code_800F7260.h"
#include "def/code_800F9280.h"
#include "def/code_800FCE80.h"
#include "def/code_800FD970.h"
#include "def/graph.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_camera.h"
#include "def/z_collision_check.h"
#include "def/z_common_data.h"
#include "def/z_en_item00.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_skelanime.h"

#define FLAGS ACTOR_FLAG_4

void EnZl3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnZl3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnZl3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnZl3_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80B59AD0(EnZl3* pthis, GlobalContext* globalCtx);

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_HIT0,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
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
    { 25, 80, 0, { 0, 0, 0 } },
};

static void* sEyeTextures[] = { gZelda2EyeOpenTex, gZelda2EyeHalfTex, gZelda2EyeShutTex, gZelda2Eye03Tex,
                                gZelda2Eye04Tex,   gZelda2Eye05Tex,   gZelda2Eye06Tex,   NULL };

static void* sMouthTextures[] = { gZelda2MouthSeriousTex, gZelda2MouthHappyTex, gZelda2MouthOpenTex };

static s32 D_80B5A468 = 0;

static Vec3f D_80B5A46C = { 0.0f, 0.0f, 0.0f };

static Vec3f D_80B5A478 = { 0.0f, 10.0f, 0.0f };

static f32 D_80B5A484 = 0.0f;

static Vec3f D_80B5A488 = { 0.0f, 0.0f, 0.0f };

static s32 D_80B5A494 = -1;

static Vec3f D_80B5A498 = { 148.0f, 260.0f, -87.0f };

static Vec3f D_80B5A4A4 = { -12.0f, 260.0f, -147.0f };

static Vec3f D_80B5A4B0 = { 42.0f, 260.0f, 13.0f };

static u32 D_80B5A4BC = 0;

void func_80B533B0(Actor* thisx, GlobalContext* globalCtx) {
    EnZl3* pthis = (EnZl3*)thisx;

    Collider_InitCylinder(globalCtx, &pthis->collider);
    Collider_SetCylinderType1(globalCtx, &pthis->collider, &pthis->actor, &sCylinderInit);
}

void func_80B533FC(EnZl3* pthis, GlobalContext* globalCtx) {
    ColliderCylinder* collider = &pthis->collider;
    s32 pad[4];

    Collider_UpdateCylinder(&pthis->actor, collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &collider->base);
}

void EnZl3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnZl3* pthis = (EnZl3*)thisx;

    Collider_DestroyCylinder(globalCtx, &pthis->collider);
}

void func_80B53468(void) {
    Audio_QueueSeqCmd(SEQ_PLAYER_BGM_MAIN << 24 | NA_BGM_ESCAPE);
}

BossGanon2* func_80B53488(EnZl3* pthis, GlobalContext* globalCtx) {
    if (pthis->ganon == NULL) {
        Actor* actorIt = globalCtx->actorCtx.actorLists[ACTORCAT_BOSS].head;

        while (actorIt != NULL) {
            if (actorIt->id == ACTOR_BOSS_GANON2) {
                pthis->ganon = (BossGanon2*)actorIt;
                break;
            }
            actorIt = actorIt->next;
        }
    }
    return pthis->ganon;
}

void EnZl3_UpdateEyes(EnZl3* pthis) {
    s32 pad[2];
    s16* eyeTexIndex = &pthis->eyeTexIndex;
    s16* blinkTimer = &pthis->blinkTimer;

    if (DECR(*blinkTimer) == 0) {
        *blinkTimer = Rand_S16Offset(60, 60);
    }
    *eyeTexIndex = *blinkTimer;
    if (*eyeTexIndex >= 3) {
        *eyeTexIndex = 0;
    }
}

void EnZl3_setEyeIndex(EnZl3* pthis, s16 index) {
    pthis->eyeTexIndex = index;
}

void EnZl3_setMouthIndex(EnZl3* pthis, s16 index) {
    pthis->mouthTexIndex = index;
}

void func_80B5357C(EnZl3* pthis, GlobalContext* globalCtx) {
    Vec3f* thisPos = &pthis->actor.world.pos;
    Vec3f sp20;

    sp20.x = thisPos->x + ((Rand_ZeroOne() - 0.5f) * 10.0f);
    sp20.y = thisPos->y;
    sp20.z = thisPos->z + ((Rand_ZeroOne() - 0.5f) * 10.0f);
    Item_DropCollectible(globalCtx, &sp20, 3);
}

void func_80B53614(EnZl3* pthis, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_RIVER_SOUND, -442.0f, 4102.0f, -371.0f, 0, 0, 0, 0x12);
}

void func_80B5366C(EnZl3* pthis, GlobalContext* globalCtx) {
    Actor_UpdateBgCheckInfo(globalCtx, &pthis->actor, 75.0f, 30.0f, 30.0f, 5);
}

void func_80B536B4(EnZl3* pthis) {
    pthis->actor.bgCheckFlags &= ~0x9;
}

void func_80B536C4(EnZl3* pthis) {
    s32 pad[2];
    Vec3s* vec1 = &pthis->unk_3F8.unk_08;
    Vec3s* vec2 = &pthis->unk_3F8.unk_0E;

    Math_SmoothStepToS(&vec1->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&vec1->y, 0, 20, 6200, 100);
    Math_SmoothStepToS(&vec2->x, 0, 20, 6200, 100);
    Math_SmoothStepToS(&vec2->y, 0, 20, 6200, 100);
}

void func_80B53764(EnZl3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    pthis->unk_3F8.unk_18 = player->actor.world.pos;
    pthis->unk_3F8.unk_14 = kREG(16) - 16.0f;
    func_80034A14(&pthis->actor, &pthis->unk_3F8, kREG(17) + 0xC, 2);
}

s32 func_80B537E8(EnZl3* pthis) {
    s16 yawTowardsPlayer = pthis->actor.yawTowardsPlayer;
    s16* rotY = &pthis->actor.world.rot.y;
    s16* unk_3D0 = &pthis->unk_3D0;
    s16 retVal;
    s16 pad[2];

    Math_SmoothStepToS(unk_3D0, ABS((s16)(yawTowardsPlayer - *rotY)), 5, 6200, 100);
    retVal = Math_SmoothStepToS(rotY, yawTowardsPlayer, 5, *unk_3D0, 100);
    pthis->actor.shape.rot.y = *rotY;
    return retVal;
}

void func_80B538B0(EnZl3* pthis) {
    s16 yawTowardsPlayer = pthis->actor.yawTowardsPlayer;
    s16* rotY = &pthis->actor.world.rot.y;

    if (ABS((s16)(yawTowardsPlayer - *rotY)) >= 0x1556) {
        D_80B5A468 = 1;
    }

    if (D_80B5A468 != 0) {
        if (!func_80B537E8(pthis)) {
            D_80B5A468 = 0;
        }
    } else {
        pthis->unk_3D0 = 0;
    }
}

s32 EnZl3_UpdateSkelAnime(EnZl3* pthis) {
    return SkelAnime_Update(&pthis->skelAnime);
}

s32 func_80B5396C(EnZl3* pthis) {
    return pthis->unk_3C8;
}

void func_80B53974(EnZl3* pthis, u8 arg1) {
    pthis->unk_3C8 = arg1;
}

void func_80B53980(EnZl3* thisx, s16 y, s32 idx) {
    EnZl3* pthis = (EnZl3*)thisx; // pthis function might take thisx
    s32 action = pthis->action;
    s16 y2 = y;
    s32 yTemp;
    f32 curFrame;
    f32 unk_3DC;

    if (pthis->unk_2FC != 0) {
        SkelAnime* skelAnime = &pthis->skelAnime;
        s32 temp25C = pthis->unk_25C[idx];
        s32 temp28C = (s16)(y + pthis->unk_28C[idx]);
        s32 temp2BC = y - pthis->unk_2BC[idx];

        if ((s32)fabsf(temp2BC) > 0x8000) {
            if (y2 > 0) {
                temp2BC -= 0x10000;
            } else {
                temp2BC += 0x10000;
            }
        }

        if ((idx != 0 || action != 4) && (temp2BC != 0)) {
            temp25C += (temp2BC - temp25C) / 16;
        }

        if (temp25C != 0) {
            temp25C -= temp25C / 10;
        }

        if ((s16)(temp28C - y) != 0) {
            temp25C -= (s16)(temp28C - y) / 50;
        }

        temp28C += temp25C;
        if (((pthis->unk_25C[idx] * temp25C) <= 0) && (((s16)(temp28C - y) > -0x64) && ((s16)(temp28C - y) < 0x64))) {
            temp28C = y;
            temp25C = 0;
        }
        if (idx == 0 && action == 3) {
            yTemp = y + -11000;
            if (skelAnime->mode == 2) {
                curFrame = skelAnime->curFrame;
                unk_3DC = pthis->unk_3DC;
                yTemp = (s32)((curFrame / unk_3DC) * -11000) + y;
                if (0) {};
                if (temp28C >= yTemp) {
                    temp28C = yTemp;
                    if (temp25C > 0) {
                        temp25C /= -2;
                    }
                }
            } else {
                if (temp28C >= yTemp) {
                    temp28C = yTemp;
                    if (temp25C > 0) {
                        temp25C /= -2;
                    }
                }
            }
        }
        pthis->unk_25C[idx] = temp25C;
        pthis->unk_28C[idx] = temp28C - y;
    }
    pthis->unk_2BC[idx] = y;
}

void func_80B53B64(EnZl3* pthis, s16 z, s32 idx) {
    SkelAnime* skelAnime = &pthis->skelAnime;
    s32 action = pthis->action;
    s32 phi_a1;
    s32 idx25C;
    s16 temp_t1;
    s32 temp_a0;
    s32 phi_v0;
    s32 phi_v1;
    s32 phi_v1_2;

    if (idx == 2) {
        phi_a1 = 15000;
        idx25C = 0;
    } else if (idx == 5) {
        phi_a1 = 13000;
        idx25C = 3;
    } else if (idx == 8) {
        phi_a1 = 12000;
        idx25C = 6;
    } else if (idx == 11) {
        phi_a1 = 0x4000;
        idx25C = 9;
    } else if (idx == 14) {
        phi_a1 = 0x4000;
        idx25C = 12;
    } else if (idx == 17) {
        phi_a1 = 0x4000;
        idx25C = 15;
    } else {
        phi_a1 = 0x4000;
        idx25C = 18;
    }

    if (pthis->unk_2FC != 0) {
        phi_v0 = pthis->unk_25C[idx];
        temp_a0 = (s16)(z + pthis->unk_28C[idx]);
        phi_v1 = z - pthis->unk_2BC[idx];

        if ((s32)fabsf(phi_v1) > 0x8000) {
            if (z > 0) {
                phi_v1 -= 0x10000;
            } else {
                phi_v1 += 0x10000;
            }
        }

        if (idx25C >= 0) {
            phi_v1 += ABS(pthis->unk_25C[idx25C]) / 3;
        }

        if (idx == 2 && (action == 5 || action == 24)) {
            if (phi_v1 != 0) {
                phi_v0 -= (phi_v1 - phi_v0) / 10;
            }
        } else if (idx == 2 && action == 22 && skelAnime->mode == 2) {
            if (phi_v1 != 0) {
                phi_v0 -= (phi_v1 - phi_v0) / 10;
            }
        } else if (idx == 2 && (action == 20 || action == 21) && skelAnime->mode == 2) {
            if (phi_v1 != 0) {
                phi_v0 -= (phi_v1 - phi_v0) / 10;
            }
        } else {
            if (phi_v1 != 0) {
                phi_v0 += (phi_v1 - phi_v0) / 16;
            }
        }

        if (phi_v0 != 0) {
            phi_v0 -= phi_v0 / 10;
        }

        if ((s16)(temp_a0 - phi_a1) != 0) {
            phi_v0 -= (s16)(temp_a0 - phi_a1) / 50;
        }

        temp_a0 += phi_v0;
        phi_v1 = (s16)(temp_a0 - phi_a1);

        if (((pthis->unk_25C[idx] * phi_v0) <= 0) && (phi_v1 > -100) && (phi_v1 < 100)) {
            temp_a0 = phi_a1;
            phi_v0 = 0;
        }

        if (idx == 2) {
            if (action == 4) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3E0 = pthis->unk_3E0;

                    phi_v1_2 = (s32)(((unk_3E0 - curFrame) / unk_3E0) * -2000.0f) + phi_a1;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if (action == 5) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3E4 = pthis->unk_3E4;

                    phi_v1_2 = (s32)((curFrame / unk_3E4) * -2000.0f) + phi_a1;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 - 2000;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if ((action == 20) || (action == 21)) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3F4 = pthis->unk_3F4;

                    if (curFrame <= 42.0f) {
                        phi_v1_2 = phi_a1 - 2000;
                    } else {
                        phi_v1_2 = (s32)((((curFrame - 42.0f) * 6200.0f) / (unk_3F4 - 42.0f)) + -2000.0f) + phi_a1;
                    }

                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 + 4200;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if (action == 22) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3EC = pthis->unk_3EC;

                    phi_v1_2 = (s32)(((curFrame / unk_3EC) * -5200.0f) + 4200.0f) + phi_a1;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 - 2000;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if (action == 23) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3F0 = pthis->unk_3F0;

                    phi_v1_2 = (s32)(((curFrame / unk_3F0) * -7600.0f) + -2000.0f) + phi_a1;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 - 9600;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if (action == 24) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3E8 = pthis->unk_3E8;

                    phi_v1_2 = (s32)(((curFrame / unk_3E8) * 21000.0f) + -9600.0f) + phi_a1;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 + 11400;
                    if (phi_v1_2 >= temp_a0) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 < 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            }
        } else if (idx == 11 || idx == 17) {
            if (action == 4) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3E0 = pthis->unk_3E0;

                    phi_v1_2 = (s32)((curFrame / unk_3E0) * -7000.0f) + phi_a1;
                    if (temp_a0 >= phi_v1_2) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 > 0) {
                            phi_v0 /= -2;
                        }
                    }
                } else {
                    phi_v1_2 = phi_a1 - 7000;
                    if (temp_a0 >= phi_v1_2) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 > 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            } else if (action == 5) {
                if (skelAnime->mode == 2) {
                    f32 curFrame = skelAnime->curFrame;
                    f32 unk_3E4 = pthis->unk_3E4;

                    phi_v1_2 = (s32)(((unk_3E4 - curFrame) / unk_3E4) * -7000.0f) + phi_a1;
                    if (temp_a0 >= phi_v1_2) {
                        temp_a0 = phi_v1_2;
                        if (phi_v0 > 0) {
                            phi_v0 /= -2;
                        }
                    }
                }
            }
        }
        pthis->unk_25C[idx] = phi_v0;
        pthis->unk_28C[idx] = temp_a0 - z;
    }
    pthis->unk_2BC[idx] = z;
}

void func_80B54360(EnZl3* pthis, s16 arg1, s32 arg2) {
    if (pthis->unk_2FC != 0) {
        s32 temp_v1 = pthis->unk_28C[arg2] - arg1;
        s16 temp_t0 = temp_v1;
        s32 temp_t2 = temp_t0;
        s32 temp_t3 = pthis->unk_25C[arg2];
        s32 phi_v0 = temp_t3;
        s32 index25C;
        s32 phi_t5;

        temp_t3 = arg1 - pthis->unk_2BC[arg2];

        if (arg2 == 1) {
            index25C = 0;
            phi_t5 = pthis->unk_25C[index25C];
        } else if (arg2 == 4) {
            index25C = 3;
            phi_t5 = pthis->unk_25C[index25C];
        } else if (arg2 == 7) {
            index25C = 6;
            phi_t5 = pthis->unk_25C[index25C];
        } else if (arg2 == 10) {
            index25C = 9;
            phi_t5 = ABS(pthis->unk_25C[index25C]);
        } else if (arg2 == 13) {
            index25C = 12;
            phi_t5 = ABS(pthis->unk_25C[index25C]);
        } else if (arg2 == 16) {
            index25C = 15;
            phi_t5 = -ABS(pthis->unk_25C[index25C]);
        } else {
            index25C = 18;
            phi_t5 = -ABS(pthis->unk_25C[index25C]);
        }

        if ((s32)fabsf(temp_t3) > 0x8000) {
            if (arg1 > 0) {
                temp_t3 -= 0x10000;
            } else {
                temp_t3 += 0x10000;
            }
        }
        if (index25C >= 0) {
            temp_t3 += phi_t5 / 3;
        }

        if (temp_t3 != 0) {
            phi_v0 += (temp_t3 - phi_v0) / 16;
        }
        if (phi_v0 != 0) {
            phi_v0 -= phi_v0 / 10;
        }
        if (temp_t0 != 0) {
            phi_v0 -= temp_t0 / 50;
        }
        temp_v1 += phi_v0;
        if (((pthis->unk_25C[arg2] * phi_v0) <= 0) && (temp_t2 > -0x64) && (temp_t2 < 0x64)) {
            temp_v1 = 0;
            phi_v0 = 0;
        }
        pthis->unk_25C[arg2] = phi_v0;
        pthis->unk_28C[arg2] = arg1 + temp_v1;
    }
    pthis->unk_2BC[arg2] = arg1;
}

s32 func_80B5458C(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                  Gfx** gfx) {
    s32 pad[3];
    EnZl3* pthis = (EnZl3*)thisx;
    s16* unk_28C = pthis->unk_28C;
    Mtx* sp78;
    MtxF sp38;
    Vec3s sp30;
    Vec3s* unk_3F8_unk_08 = &pthis->unk_3F8.unk_08;
    Vec3s* unk_3F8_unk_0E = &pthis->unk_3F8.unk_0E;

    if (limbIndex == 14) {
        sp78 = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx) * 7);
        rot->x += unk_3F8_unk_08->y;
        rot->z += unk_3F8_unk_08->x;
        gSPSegment((*gfx)++, 0x0C, sp78);

        Matrix_Push();
        Matrix_Translate(pos->x, pos->y, pos->z, MTXMODE_APPLY);
        Matrix_RotateZYX(rot->x, rot->y, rot->z, MTXMODE_APPLY);
        Matrix_Push();
        Matrix_Translate(362.0f, -133.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 0);
            func_80B54360(pthis, sp30.x, 1);
            func_80B53B64(pthis, sp30.z, 2);
        }
        Matrix_RotateZYX(unk_28C[0] + kREG(31), unk_28C[1] + kREG(32), unk_28C[2] + kREG(33), MTXMODE_APPLY);
        Matrix_Translate(-188.0f, -184.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[0], "../z_en_zl3.c", 1490);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 3);
        }
        Matrix_RotateZYX(unk_28C[3] + kREG(34), unk_28C[4] + kREG(35), unk_28C[5] + kREG(36), MTXMODE_APPLY);
        Matrix_Translate(-410.0f, -184.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[1], "../z_en_zl3.c", 1534);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B54360(pthis, sp30.x, 7);
        }
        Matrix_RotateZYX(unk_28C[6] + kREG(37), unk_28C[7] + kREG(38), unk_28C[8] + kREG(39), MTXMODE_APPLY);
        Matrix_Translate(-1019.0f, -26.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[2], "../z_en_zl3.c", 1554);
        Matrix_Pop();
        Matrix_Push();
        Matrix_Translate(467.0f, 265.0f, 389.0f, MTXMODE_APPLY);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 9);
            func_80B54360(pthis, sp30.x, 10);
            func_80B53B64(pthis, sp30.z, 11);
        }
        Matrix_RotateZYX(unk_28C[9] + kREG(40), unk_28C[10] + kREG(41), unk_28C[11] + kREG(42), MTXMODE_APPLY);
        Matrix_Translate(-427.0f, -1.0f, -3.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[3], "../z_en_zl3.c", 1579);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 12);
            func_80B54360(pthis, sp30.x, 13);
            func_80B53B64(pthis, sp30.z, 14);
        }
        Matrix_RotateZYX(unk_28C[12] + kREG(43), unk_28C[13] + kREG(44), unk_28C[14] + kREG(45), MTXMODE_APPLY);
        Matrix_Translate(-446.0f, -52.0f, 84.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[4], "../z_en_zl3.c", 1598);
        Matrix_Pop();
        Matrix_Push();
        Matrix_Translate(467.0f, 265.0f, -389.0f, MTXMODE_APPLY);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 15);
            func_80B54360(pthis, sp30.x, 16);
            func_80B53B64(pthis, sp30.z, 17);
        }
        Matrix_RotateZYX(unk_28C[15] + kREG(46), unk_28C[16] + kREG(47), unk_28C[17] + kREG(48), MTXMODE_APPLY);
        Matrix_Translate(-427.0f, -1.0f, 3.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[5], "../z_en_zl3.c", 1623);
        Matrix_Get(&sp38);
        Matrix_MtxFToYXZRotS(&sp38, &sp30, 0);
        if (!FrameAdvance_IsEnabled(globalCtx)) {
            func_80B53980(pthis, sp30.y, 18);
            func_80B54360(pthis, sp30.x, 19);
            func_80B53B64(pthis, sp30.z, 20);
        }
        Matrix_RotateZYX(unk_28C[18] + kREG(49), unk_28C[19] + kREG(50), unk_28C[20] + kREG(51), MTXMODE_APPLY);
        Matrix_Translate(-446.0f, -52.0f, -84.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&sp78[6], "../z_en_zl3.c", 1642);
        Matrix_Pop();
        Matrix_Pop();
        pthis->unk_2FC = 1;
    } else if (limbIndex == 7) {
        rot->x += unk_3F8_unk_0E->y;
        rot->y -= unk_3F8_unk_0E->x;
    }
    return false;
}

void EnZl3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnZl3* pthis = (EnZl3*)thisx;
    s32 pad;
    Vec3f sp34;
    s32 pad2;
    Vec3f sp24;
    Vec3f sp18;

    if (limbIndex == 13) {
        sp34 = D_80B5A46C;
        Matrix_MultVec3f(&sp34, &pthis->unk_31C);
    } else if (limbIndex == 14) {
        sp24 = D_80B5A478;
        Matrix_MultVec3f(&sp24, &sp18);
        pthis->actor.focus.pos.x = sp18.x;
        pthis->actor.focus.pos.y = sp18.y;
        pthis->actor.focus.pos.z = sp18.z;
        pthis->actor.focus.rot.x = pthis->actor.world.rot.x;
        pthis->actor.focus.rot.y = pthis->actor.world.rot.y;
        pthis->actor.focus.rot.z = pthis->actor.world.rot.z;
    }
}

s32 func_80B54DB4(EnZl3* pthis) {
    s32 params = pthis->actor.params >> 8;

    return params & 0xFF;
}

s32 func_80B54DC4(EnZl3* pthis) {
    s32 params = pthis->actor.params >> 4;

    return params & 0xF;
}

s32 func_80B54DD4(EnZl3* pthis) {
    s32 params = pthis->actor.params;

    return params & 0xF;
}

void func_80B54DE0(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 idx = pthis->unk_318;

    gSegments[6] = VIRTUAL_TO_PHYSICAL(gObjectTable[idx].vromStart.get());
}

void func_80B54E14(EnZl3* pthis, AnimationHeader* animation, u8 arg2, f32 transitionRate, s32 arg4) {
    f32 frameCount = Animation_GetLastFrame(animation);
    f32 playbackSpeed;
    f32 unk0;
    f32 fc;

    if (arg4 == 0) {
        unk0 = 0.0f;
        fc = frameCount;
        playbackSpeed = 1.0f;
    } else {
        unk0 = frameCount;
        fc = 0.0f;
        playbackSpeed = -1.0f;
    }

    Animation_Change(&pthis->skelAnime, animation, playbackSpeed, unk0, fc, arg2, transitionRate);
}

void func_80B54EA4(EnZl3* pthis, GlobalContext* globalCtx) {
    f32 posX = pthis->actor.world.pos.x;
    f32 posY = pthis->actor.world.pos.y;
    f32 posZ = pthis->actor.world.pos.z;

    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_EG, posX, posY, posZ, 0, 0, 0, 0);
}

void func_80B54EF4(EnZl3* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_VO_Z1_PAIN);
}

void func_80B54F18(EnZl3* pthis, GlobalContext* globalCtx) {
    if (pthis->unk_2F8 == 0) {
        f32 posX = pthis->actor.world.pos.x;
        f32 posY = pthis->actor.world.pos.y + (kREG(5) + -26.0f);
        f32 posZ = pthis->actor.world.pos.z;

        Actor_SpawnAsChild(&globalCtx->actorCtx, &pthis->actor, globalCtx, ACTOR_DOOR_WARP1, posX, posY, posZ, 0, 0x4000,
                           0, WARP_PURPLE_CRYSTAL);
        pthis->unk_2F8 = 1;
    }
}

void func_80B54FB4(EnZl3* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_inFinal_Init通すよ!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    func_80B54E14(pthis, &gZelda2Anime2Anim_008AD0, 0, 0.0f, 0);
    EnZl3_setEyeIndex(pthis, 4);
    EnZl3_setMouthIndex(pthis, 2);
    pthis->action = 1;
    pthis->drawConfig = 1;
    func_80B54F18(pthis, globalCtx);
    pthis->actor.shape.rot.z = 0;
    pthis->unk_3C4 = pthis->actor.world.rot.z;
    pthis->actor.world.rot.z = pthis->actor.shape.rot.z;
    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_inFinal_Initは通った!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

void func_80B55054(EnZl3* pthis) {
    if (pthis->unk_328 != 0) {
        Actor* child = pthis->actor.child;

        if (child != NULL) {
            f32* temp_v0 = &pthis->unk_2EC;

            if (*temp_v0 < 19.0f) {
                ((DoorWarp1*)child)->crystalAlpha = (20.0f - *temp_v0) * 12.75f;
                *temp_v0 += 1.0f;
            } else {
                Actor_Kill(child);
                pthis->actor.child = NULL;
            }
        }
    }
}

void func_80B550F0(EnZl3* pthis) {
    Actor* child = pthis->actor.child;

    if (child != NULL) {
        child->world.pos.x = pthis->actor.world.pos.x;
        child->world.pos.y = pthis->actor.world.pos.y + (kREG(5) + -26.0f);
        child->world.pos.z = pthis->actor.world.pos.z;
    }
}

void func_80B55144(EnZl3* pthis) {
    f32* fl = &D_80B5A484;

    if (1) {} // necessary to match

    if (*fl < 2.0f) {
        *fl += 1.0f;
        EnZl3_setEyeIndex(pthis, 2);
    } else if (*fl < 4.0f) {
        *fl += 1.0f;
        EnZl3_setEyeIndex(pthis, 1);
    } else {
        EnZl3_UpdateEyes(pthis);
    }
}

void func_80B551E0(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_008AD0, 0, 0.0f, 0);
    pthis->action = 1;
}

void func_80B55220(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0091D8, 2, 0.0f, 0);
    pthis->action = 2;
    EnZl3_setMouthIndex(pthis, 0);
}

void func_80B55268(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0091D8, 2, 0.0f, 0);
    pthis->action = 3;
}

void func_80B552A8(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_0099A0, 0, 0.0f, 0);
    }
}

void func_80B552DC(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_00A598, 2, -8.0f, 0);
    func_80B54EF4(pthis);
    EnZl3_setMouthIndex(pthis, 2);
    pthis->action = 4;
    func_80B53468();
}

void func_80B55334(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_00AACC, 0, 0.0f, 0);
    }
}

void func_80B55368(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_00A334, 2, -8.0f, 0);
    EnZl3_setMouthIndex(pthis, 0);
    pthis->action = 5;
}

void func_80B553B4(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, 0.0f, 0);
    }
}

void func_80B553E8(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B59AD0(pthis, globalCtx);
}

void func_80B55408(EnZl3* pthis) {
    Actor* child = pthis->actor.child;

    if (child != NULL) {
        Actor_Kill(child);
    }
    Actor_Kill(&pthis->actor);
}

void func_80B55444(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 temp_v0 = func_80B5396C(pthis);

    if (temp_v0 >= 0) {
        s32 unk_2F0 = pthis->unk_2F0;

        if (temp_v0 != unk_2F0) {
            switch (temp_v0) {
                case 0:
                    func_80B551E0(pthis);
                    break;
                case 1:
                    EnZl3_setEyeIndex(pthis, 3);
                    func_80B54EF4(pthis);
                    break;
                case 3:
                    func_80B55220(pthis);
                    break;
                case 4:
                    func_80B55268(pthis);
                    break;
                case 5:
                    func_80B552DC(pthis);
                    break;
                case 6:
                    func_80B55368(pthis);
                    break;
                case 7:
                    func_80B553E8(pthis, globalCtx);
                    break;
                case 2:
                    func_80B55408(pthis);
                    break;
                case 8:
                    pthis->unk_328 = 1;
                default:
                    osSyncPrintf("En_Zl3_inFinal_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_2F0 = temp_v0;
        }
    }
}

void func_80B55550(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B550F0(pthis);
    func_80B55444(pthis, globalCtx);
}

void func_80B555A4(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_setEyeIndex(pthis, 2);
    func_80B550F0(pthis);
    func_80B55054(pthis);
    func_80B55444(pthis, globalCtx);
}

void func_80B55604(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    func_80B55144(pthis);
    func_80B552A8(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B55054(pthis);
    func_80B55444(pthis, globalCtx);
}

void func_80B5566C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55334(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B55444(pthis, globalCtx);
}

void func_80B556CC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B553B4(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B55444(pthis, globalCtx);
}

void func_80B5572C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B55444(pthis, globalCtx);
}

void func_80B55780(EnZl3* pthis, GlobalContext* globalCtx) {
    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_inFinal2_Init通すよ!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    func_80B54E14(pthis, &gZelda2Anime2Anim_005A0C, 0, 0.0f, 0);
    pthis->action = 7;
    pthis->drawConfig = 1;
    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_inFinal2_Initは通った!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    EnZl3_setMouthIndex(pthis, 1);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void func_80B55808(EnZl3* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_VO_Z1_PAIN);
}

void func_80B5582C(EnZl3* pthis) {
    Audio_PlaySoundRandom(&D_80B5A488, NA_SE_VO_Z1_CRY_0, NA_SE_VO_Z1_CRY_1 - NA_SE_VO_Z1_CRY_0 + 1);
}

void func_80B5585C(EnZl3* pthis) {
    SkelAnime* skelAnime = &pthis->skelAnime;

    if ((skelAnime->mode == 2) && Animation_OnFrame(skelAnime, 4.0f)) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_VO_Z1_PAIN);
    }
}

void func_80B558A8(EnZl3* pthis) {
    s32 pad[4];
    s16 thisRotY = pthis->actor.world.rot.y;
    Vec3f* unk_338 = &pthis->unk_338;

    *unk_338 = pthis->unk_32C = pthis->actor.world.pos;

    unk_338->z += (-1.6074f * Math_CosS(thisRotY)) - (3.1620007f * Math_SinS(thisRotY));
    unk_338->x += (-1.6074f * Math_SinS(thisRotY)) + (3.1620007f * Math_CosS(thisRotY));
    unk_338->y += -0.012199402f;
}

void func_80B559C4(EnZl3* pthis) {
    Vec3f* thisPos = &pthis->actor.world.pos;
    Vec3f* unk_32C = &pthis->unk_32C;
    Vec3f* unk_338 = &pthis->unk_338;
    f32 temp_f0 = Environment_LerpWeightAccelDecel(Animation_GetLastFrame(&gZelda2Anime2Anim_005248), 0,
                                                   (s32)pthis->skelAnime.curFrame, 3, 3);

    thisPos->x = unk_32C->x + (temp_f0 * (unk_338->x - unk_32C->x));
    thisPos->z = unk_32C->z + (temp_f0 * (unk_338->z - unk_32C->z));
}

void func_80B55A58(EnZl3* pthis, GlobalContext* globalCtx) {
    if (globalCtx->activeCamera == MAIN_CAM) {
        func_80B537E8(pthis);
    }
}

void func_80B55A84(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_005A0C, 0, 0.0f, 0);
    pthis->action = 7;
}

void func_80B55AC4(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_00499C, 2, -8.0f, 0);
    pthis->action = 8;
}

void func_80B55B04(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_004408, 0, 0.0f, 0);
    }
}

void func_80B55B38(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_006508, 2, -8.0f, 0);
    pthis->action = 9;
}

void func_80B55B78(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_0061C4, 0, 0.0f, 0);
    }
}

void func_80B55BAC(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_005248, 2, -8.0f, 0);
    func_80B558A8(pthis);
    func_80B55808(pthis);
    EnZl3_setMouthIndex(pthis, 2);
    pthis->action = 10;
}

void func_80B55C0C(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0054E0, 0, 0.0f, 0);
    pthis->action = 11;
}

void func_80B55C4C(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B55C0C(pthis);
    }
}

void func_80B55C70(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_008684, 2, -8.0f, 0);
    pthis->action = 12;
    pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
    pthis->actor.flags &= ~ACTOR_FLAG_0;
}

void func_80B55CCC(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_006F04, 0, 0.0f, 0);
    }
}

void func_80B55D00(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->action = 13;
    } else if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4300) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        pthis->actor.flags |= ACTOR_FLAG_0;
        pthis->actor.textId = 0x70D5;
        func_8002F2F4(&pthis->actor, globalCtx);
    } else {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }
}

void func_80B55DB0(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->action = 12;
    }
}

void func_80B55E08(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_006AB0, 2, -8.0f, 0);
    pthis->action = 14;
}

void func_80B55E48(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_008050, 0, 0.0f, 0);
    }
}

void func_80B55E7C(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_007A78, 2, -8.0f, 0);
    pthis->action = 15;
}

void func_80B55EBC(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_007C84, 0, 0.0f, 0);
    }
}

void func_80B55EF0(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0082F8, 2, -8.0f, 0);
    pthis->action = 16;
    EnZl3_setMouthIndex(pthis, 0);
}

void func_80B55F38(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, 0.0f, 0);
    }
}

void func_80B55F6C(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->action = 0x12;
    } else if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4300) {
        BossGanon2* bossGanon2 = func_80B53488(pthis, globalCtx);

        if ((bossGanon2 != NULL) && (bossGanon2->unk_324 <= (10.0f / 81.0f))) {
            pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
            pthis->actor.flags |= ACTOR_FLAG_0;
            pthis->actor.textId = 0x7059;
            func_8002F2F4(&pthis->actor, globalCtx);
        }
    } else {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }
}

void func_80B5604C(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_007664, 2, -8.0f, 0);
    pthis->action = 17;
    func_80B5582C(pthis);
}

void func_80B56090(EnZl3* pthis, s32 arg1) {
    s32* unk_2F0 = &pthis->unk_2F0;

    if (func_80B5396C(pthis) == *unk_2F0) {
        if (arg1 != 0) {
            func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, 0.0f, 0);
            pthis->action = 16;
            func_80B53974(pthis, 7);
            pthis->unk_2F0 = 7;
        }
    }
}

void func_80B56108(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->action = 16;
    }
}

void func_80B56160(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0001D8, 0, 0.0f, 0);
    pthis->action = 19;
}

void func_80B561A0(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_001110, 2, -8.0f, 0);
    pthis->action = 20;
}

void func_80B561E0(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_0004F4, 0, 0.0f, 0);
    }
}

void func_80B56214(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        pthis->action = 21;
    } else if (ABS((s16)(pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y)) <= 0x4300) {
        BossGanon2* bossGanon2 = func_80B53488(pthis, globalCtx);

        if (bossGanon2 != NULL) {
            if (bossGanon2->unk_324 <= (10.0f / 81.0f)) {
                pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
                pthis->actor.flags |= ACTOR_FLAG_0;
                pthis->actor.textId = 0x7059;
                func_8002F2F4(&pthis->actor, globalCtx);
            }
        }
    } else {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
    }
}

void func_80B562F4(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        pthis->actor.flags &= ~(ACTOR_FLAG_0 | ACTOR_FLAG_3);
        pthis->actor.flags &= ~ACTOR_FLAG_0;
        pthis->action = 20;
    }
}

void func_80B5634C(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_002348, 2, -8.0f, 0);
    pthis->action = 22;
}

void func_80B5638C(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_00210C, 0, 0.0f, 0);
    }
}

void func_80B563C0(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_002E54, 2, -8.0f, 0);
    pthis->action = 23;
}

void func_80B56400(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_002710, 0, 0.0f, 0);
    }
}

void func_80B56434(EnZl3* pthis) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_001D8C, 2, -8.0f, 0);
    pthis->action = 24;
}

void func_80B56474(EnZl3* pthis, s32 arg1) {
    if (arg1 != 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_0014DC, 0, 0.0f, 0);
    }
}

void func_80B564A8(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 temp_v0;
    s32* val = &D_80B5A494;

    temp_v0 = func_80B5396C(pthis);

    if (*val > 0) {
        *val -= 1;
    } else if (*val == 0) {
        *val -= 1;
        if (temp_v0 == 8) {
            func_80B5604C(pthis);
        }
    }

    if (temp_v0 >= 0) {
        s32 unk_2F0 = pthis->unk_2F0;

        if (temp_v0 != unk_2F0) {
            switch (temp_v0) {
                case 0:
                    func_80B55A84(pthis);
                    break;
                case 1:
                    func_80B55AC4(pthis);
                    break;
                case 2:
                    func_80B55B38(pthis);
                    break;
                case 3:
                    func_80B55BAC(pthis);
                    break;
                case 4:
                    func_80B55C70(pthis);
                    break;
                case 5:
                    func_80B55E08(pthis);
                    break;
                case 6:
                    func_80B55E7C(pthis);
                    break;
                case 7:
                    func_80B55EF0(pthis);
                    break;
                case 8:
                    *val = 10;
                    break;
                case 9:
                    func_80B56160(pthis);
                    break;
                case 10:
                    func_80B561A0(pthis);
                    break;
                case 11:
                    func_80B5634C(pthis);
                    break;
                case 12:
                    func_80B563C0(pthis);
                    break;
                case 13:
                    func_80B56434(pthis);
                    break;
                case 14:
                    Actor_Kill(&pthis->actor);
                    break;
                default:
                    osSyncPrintf("En_Zl3_inFinal2_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }
            pthis->unk_2F0 = temp_v0;
        }
    }
}

void func_80B56658(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B564A8(pthis, globalCtx);
}

void func_80B566AC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55B04(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B5670C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55B78(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B5676C(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 something;

    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    something = EnZl3_UpdateSkelAnime(pthis);
    func_80B559C4(pthis);
    func_80B55C4C(pthis, something);
}

void func_80B567CC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B564A8(pthis, globalCtx);
}

void func_80B5682C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B55A58(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55CCC(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
    func_80B55D00(pthis, globalCtx);
}

void func_80B568B4(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B55DB0(pthis, globalCtx);
}

void func_80B5691C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55E48(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B5697C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55EBC(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B5585C(pthis);
    func_80B564A8(pthis, globalCtx);
}

void func_80B569E4(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55F38(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
    func_80B55F6C(pthis, globalCtx);
}

void func_80B56A68(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 something;

    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    something = EnZl3_UpdateSkelAnime(pthis);
    func_80B564A8(pthis, globalCtx);
    func_80B56090(pthis, something);
}

void func_80B56AE0(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B55F38(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B56108(pthis, globalCtx);
}

void func_80B56B54(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B564A8(pthis, globalCtx);
}

void func_80B56BA8(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B561E0(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
    func_80B56214(pthis, globalCtx);
}

void func_80B56C24(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B562F4(pthis, globalCtx);
}

void func_80B56C84(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B5638C(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B56CE4(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B56400(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B56D44(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B56474(pthis, EnZl3_UpdateSkelAnime(pthis));
    func_80B564A8(pthis, globalCtx);
}

void func_80B56DA4(EnZl3* pthis) {
    func_800788CC(NA_SE_EV_ZELDA_POWER);
}

void func_80B56DC8(EnZl3* pthis) {
    func_80078914(&pthis->actor.projectedPos, NA_SE_VO_Z1_PAIN);
}

void func_80B56DEC(EnZl3* pthis) {
    SkelAnime* skelAnime = &pthis->skelAnime;

    if ((skelAnime->mode == 2) && Animation_OnFrame(skelAnime, 9.0f) != 0) {
        func_80078914(&pthis->actor.projectedPos, NA_SE_VO_Z1_OPENDOOR);
    }
}

void func_80B56E38(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s32 sfxId;
    SkelAnime* sp20 = &pthis->skelAnime;

    if ((Animation_OnFrame(sp20, 6.0f) || Animation_OnFrame(sp20, 0.0f)) && (pthis->actor.bgCheckFlags & 1)) {
        sfxId = 0x800;
        sfxId += SurfaceType_GetSfx(&globalCtx->colCtx, pthis->actor.floorPoly, pthis->actor.floorBgId);
        func_80078914(&pthis->actor.projectedPos, sfxId);
    }
}

void func_80B56EB8(EnZl3* pthis, GlobalContext* globalCtx) {
    Flags_SetSwitch(globalCtx, func_80B54DB4(pthis));
}

s32 func_80B56EE4(EnZl3* pthis, GlobalContext* globalCtx) {
    return Flags_GetSwitch(globalCtx, func_80B54DB4(pthis));
}

void func_80B56F10(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 waypoint;
    Path* pathHead = globalCtx->setupPathList;

    if (pathHead != NULL) {
        waypoint = func_80B54DC4(pthis);
        pathHead += waypoint;
        pthis->unk_30C = pathHead;
        pthis->unk_310 = pathHead->count;
        osSyncPrintf("En_Zl3_Get_path_info レールデータをゲットだぜ = %d!!!!!!!!!!!!!!\n", waypoint);
    } else {
        osSyncPrintf("En_Zl3_Get_path_info レールデータが無い!!!!!!!!!!!!!!!!!!!!\n");
    }
}

s32 func_80B56F8C(EnZl3* pthis, s32 arg1) {
    s32 unk_310 = pthis->unk_310;

    if (unk_310 > arg1) {
        return 1;
    }
    return 0;
}

Vec3s* func_80B56FAC(EnZl3* pthis, s32 arg1) {
    Vec3s* point;
    Path* pathList = pthis->unk_30C;

    if ((pathList != NULL) && func_80B56F8C(pthis, arg1)) {
        point = &((Vec3s*)SEGMENTED_TO_VIRTUAL(pathList->points))[arg1];
        return point;
    }
    return NULL;
}

s32 func_80B57034(EnZl3* pthis, s32 arg1, s32 arg2) {
    Vec3s* vec1 = func_80B56FAC(pthis, arg1);
    Vec3s* vec2 = func_80B56FAC(pthis, arg2);

    if ((vec2 != NULL) && (vec1 != NULL)) {
        f32 xDiff = vec2->x - vec1->x;
        f32 zDiff = vec2->z - vec1->z;

        return ((xDiff == 0.0f) && (zDiff == 0.0f)) ? 0 : (s16)(Math_FAtan2F(xDiff, zDiff) * (0x8000 / M_PI));
    }
    return 0;
}

s16 func_80B57104(EnZl3* pthis, s32 arg1) {
    Vec3s* point = func_80B56FAC(pthis, arg1);

    if (point != NULL) {
        f32 xDiff = point->x - pthis->actor.world.pos.x;
        f32 zDiff = point->z - pthis->actor.world.pos.z;

        if ((xDiff != 0.0f) || (zDiff != 0.0f)) {
            return Math_FAtan2F(xDiff, zDiff) * (0x8000 / M_PI);
        }
    }
    return 0;
}

s32 func_80B571A8(EnZl3* pthis) {
    s32 pad;
    s32 unk_314 = pthis->unk_314;
    s32 pad2;

    if (func_80B56F8C(pthis, unk_314 + 1) == 0) {
        return pthis->actor.shape.rot.y;
    } else {
        return func_80B57034(pthis, unk_314, unk_314 + 1);
    }
}

s32 func_80B571FC(EnZl3* pthis) {
    s32 pad;
    s32 unk_314 = pthis->unk_314;

    if (func_80B56F8C(pthis, unk_314) == 0) {
        return pthis->actor.shape.rot.y;
    } else {
        return func_80B57104(pthis, unk_314);
    }
}

void func_80B57240(EnZl3* pthis) {
    s32 temp_a1 = func_80B571FC(pthis);
    s16* rotY = &pthis->actor.world.rot.y;

    Math_SmoothStepToS(rotY, temp_a1, 2, 6400, 1000);
    pthis->actor.shape.rot.y = *rotY;
}

void func_80B57298(EnZl3* pthis) {
    s16* rotY = &pthis->actor.world.rot.y;
    s16 temp_a1 = func_80B571A8(pthis);

    Math_SmoothStepToS(rotY, temp_a1, 2, 6400, 1000);
    pthis->actor.shape.rot.y = *rotY;
}

u16 func_80B572F0(GlobalContext* globalCtx) {
    s16 sceneNum = globalCtx->sceneNum;
    u16 ret;

    if (sceneNum == SCENE_GANON_SONOGO) {
        ret = 0x71A8;
    } else if (sceneNum == SCENE_GANON_FINAL) {
        ret = 0x71A9;
    } else {
        ret = 0x71AB;
    }
    return ret;
}

s32 func_80B57324(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Actor_ProcessTalkRequest(&pthis->actor, globalCtx)) {
        return 1;
    }
    return 0;
}

void func_80B57350(EnZl3* pthis, GlobalContext* globalCtx) {
    s16 temp_v0 = pthis->actor.yawTowardsPlayer - pthis->actor.shape.rot.y;

    if (ABS(temp_v0) <= 0x4300) {
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        pthis->actor.textId = func_80B572F0(globalCtx);
        func_8002F2F4(&pthis->actor, globalCtx);
    }
}

s32 func_80B573C8(EnZl3* pthis, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
        return 1;
    }
    return 0;
}

s32 func_80B573FC(EnZl3* pthis, GlobalContext* globalCtx, f32 arg2) {
    Player* player = GET_PLAYER(globalCtx);
    f32 playerX = player->actor.world.pos.x;
    f32 playerZ = player->actor.world.pos.z;
    f32 thisX = pthis->actor.world.pos.x;
    f32 thisZ = pthis->actor.world.pos.z;

    if (SQ(playerX - thisX) + SQ(playerZ - thisZ) < SQ(arg2)) {
        return 1;
    }
    return 0;
}

s32 func_80B57458(EnZl3* pthis, GlobalContext* globalCtx) {
    Vec3f* thisPos = &pthis->actor.world.pos;
    f32 thisX = thisPos->x;
    f32 thisZ = thisPos->z;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f* playerPos = &player->actor.world.pos;
    s32 pad;
    f32 playerX = playerPos->x;
    f32 playerZ = playerPos->z;
    f32 temp_f12 = playerX - thisX;
    f32 temp_f13 = playerZ - thisZ;
    s16 temp_v0;
    s16 temp_v1 = func_80B571A8(pthis);

    if (temp_f12 == 0.0f && temp_f13 == 0.0f) {
        return 1;
    }

    temp_v0 = (s16)(temp_v1 - (s16)(Math_FAtan2F(temp_f12, temp_f13) * (0x8000 / M_PI)));

    if (temp_v0 < 0x1555) {
        return 1;
    } else if ((temp_v0 < 0x4000) && func_80B573FC(pthis, globalCtx, 150.0f)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80B57564(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B573FC(pthis, globalCtx, 50.0f) || func_80B57458(pthis, globalCtx)) {
        return 1;
    }
    return 0;
}

s32 func_80B575B0(EnZl3* pthis, GlobalContext* globalCtx) {
    return func_80B573FC(pthis, globalCtx, 150.0f);
}

s32 func_80B575D0(EnZl3* pthis, GlobalContext* globalCtx) {
    return func_80B573FC(pthis, globalCtx, 50.0f);
}

s32 func_80B575F0(EnZl3* pthis, GlobalContext* globalCtx) {
    s16 sceneNum = globalCtx->sceneNum;

    if ((sceneNum == SCENE_GANON_SONOGO) && (func_80B54DB4(pthis) == 0x26)) {
        s32 unk_314 = pthis->unk_314;

        if (unk_314 == 1) {
            return 1;
        }
    }
    return 0;
}

void func_80B5764C(EnZl3* pthis, GlobalContext* globalCtx) {
    s16 sceneNum = globalCtx->sceneNum;

    if ((sceneNum == SCENE_GANON_SONOGO) && (func_80B54DB4(pthis) == 0x26)) {
        s32 unk_314 = pthis->unk_314 + 1;

        if ((unk_314 == 1) && !Gameplay_InCsMode(globalCtx)) {
            OnePointCutscene_Init(globalCtx, 1000, 40, &pthis->actor, MAIN_CAM);
        }
    }
}

s32 func_80B576C8(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B575F0(pthis, globalCtx) && (pthis->unk_3D8 == 0)) {
        return 1;
    }
    return 0;
}

void func_80B57704(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 unk_3C4 = pthis->unk_3C4;

    Flags_SetSwitch(globalCtx, unk_3C4);
}

void func_80B5772C(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 unk_3C4 = pthis->unk_3C4;

    Flags_UnsetSwitch(globalCtx, unk_3C4);
}

void func_80B57754(EnZl3* pthis, GlobalContext* globalCtx) {
    if (gSaveContext.unk_13F0 == 0) {
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_OCEFF_WIPE4, pthis->actor.world.pos.x,
                    pthis->actor.world.pos.y, pthis->actor.world.pos.z, 0, 0, 0, 1);
        func_80B56DA4(pthis);
    }
}

void func_80B577BC(GlobalContext* globalCtx, Vec3f* vec) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    Vec3f* playerPos = &player->actor.world.pos;
    f32 posX = vec->x;
    f32 posY = vec->y;
    f32 posZ = vec->z;

    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_TEST, posX, posY, posZ, 0,
                (Math_FAtan2F(playerPos->x - posX, playerPos->z - posZ) * (0x8000 / M_PI)), 0, 5);
}

void func_80B57858(GlobalContext* globalCtx) {
    func_80B577BC(globalCtx, &D_80B5A498);
    func_80B577BC(globalCtx, &D_80B5A4A4);
}

s32 func_80B57890(EnZl3* pthis, GlobalContext* globalCtx) {
    s8 pad[2];
    u8 curSpawn = globalCtx->curSpawn;
    s16 sceneNum = globalCtx->sceneNum;
    s32 result = func_80B54DB4(pthis);

    if (globalCtx) {} // Needed to match, pthis if can be almost anywhere and it still matches

    if (sceneNum == SCENE_GANON_SONOGO) {
        if ((result == 0x24) && (curSpawn == 0)) {
            return 1;
        }
        if ((result == 0x25) && (curSpawn == 2)) {
            return 1;
        }
        if ((result == 0x26) && (curSpawn == 4)) {
            return 1;
        }
        if ((result == 0x27) && (curSpawn == 6)) {
            return 1;
        }
        if ((result == 0x28) && (curSpawn == 6)) {
            return 1;
        }
    } else if (sceneNum == SCENE_GANON_FINAL) {
        if ((result == 0x20) && (curSpawn == 0) && Flags_GetSwitch(globalCtx, 0x37)) {
            if ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO)) {
                return 1;
            }
        }
        if ((result == 0x21) && (curSpawn == 2)) {
            return 1;
        }
        if ((result == 0x22) && (curSpawn == 4)) {
            return 1;
        }
        if ((result == 0x23) && (curSpawn == 6)) {
            return 1;
        }
    } else if (sceneNum == SCENE_GANONTIKA_SONOGO) {
        if ((result == 0x29) && (curSpawn == 0)) {
            return 1;
        }
        if ((result == 0x2A) && (curSpawn == 0)) {
            return 1;
        }
    }
    return 0;
}

void func_80B57A74(GlobalContext* globalCtx) {
    Actor* actorIt = globalCtx->actorCtx.actorLists[ACTORCAT_PROP].head;
    //! @bug checks for encount2 in ACTORCAT_PROP but encount2 is in ACTORCAT_ENEMY so pthis condition is never met
    while (actorIt != NULL) {
        if (actorIt->id == ACTOR_EN_ENCOUNT2) {
            ((EnEncount2*)actorIt)->collapseSpawnerInactive = true;
        }
        actorIt = actorIt->next;
    }
}

void func_80B57AAC(EnZl3* pthis, s32 arg1, AnimationHeader* arg2) {
    if (arg1 != 0) {
        func_80B54E14(pthis, arg2, 0, -8.0f, 0);
    }
}

void func_80B57AE0(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16 shapeRotY = pthis->actor.shape.rot.y;
    s32 pad2;
    Vec3f* unk_354 = &pthis->unk_354;
    Vec3f* unk_348 = &pthis->unk_348;
    Vec3s* temp_v0;
    f32 xDiff;
    f32 zDiff;

    pthis->unk_344 = 0;
    pthis->unk_314 += 1;
    pthis->unk_360 = 0.0f;
    pthis->unk_364 = 0.0f;
    pthis->unk_368 = 0.0f;
    *unk_348 = pthis->actor.world.pos;
    temp_v0 = func_80B56FAC(pthis, pthis->unk_314);

    if (temp_v0 != NULL) {
        unk_354->x = temp_v0->x;
        unk_354->y = temp_v0->y;
        unk_354->z = temp_v0->z;
    } else {
        unk_354->x = unk_348->x + (Math_SinS(shapeRotY) * 200.0f);
        unk_354->y = unk_348->y;
        unk_354->z = unk_348->z + (Math_CosS(shapeRotY) * 200.0f);
    }

    xDiff = unk_354->x - unk_348->x;
    zDiff = unk_354->z - unk_348->z;
    pthis->unk_346 = (s32)(sqrtf(SQ(xDiff) + SQ(zDiff)) / (kREG(6) + 8.0f));
}

s32 func_80B57C54(EnZl3* pthis) {
    if (pthis->unk_344 >= pthis->unk_346) {
        return 1;
    }
    return 0;
}

s32 func_80B57C7C(EnZl3* pthis, GlobalContext* globalCtx) {
    return 1;
}

s32 func_80B57C8C(EnZl3* pthis) {
    return !func_80B56F8C(pthis, pthis->unk_314 + 2);
}

void func_80B57CB4(EnZl3* pthis, GlobalContext* globalCtx) {
    Vec3f* unk_348 = &pthis->unk_348;
    Vec3f* unk_354 = &pthis->unk_354;
    Vec3f* thisPos = &pthis->actor.world.pos;
    f32 temp_f0;

    pthis->unk_344 += 1;
    temp_f0 = Environment_LerpWeightAccelDecel(pthis->unk_346, 0, pthis->unk_344, 3, 3);
    thisPos->x = unk_348->x + (temp_f0 * (unk_354->x - unk_348->x));
    thisPos->y = (unk_348->y + (temp_f0 * (unk_354->y - unk_348->y))) + pthis->unk_360;
    thisPos->z = unk_348->z + (temp_f0 * (unk_354->z - unk_348->z));
}

void func_80B57D60(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B57240(pthis);
}

s32 func_80B57D80(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    s16* sp32 = &pthis->actor.shape.rot.y;
    struct_80034A14_arg1* unk_3F8 = &pthis->unk_3F8;
    Player* player = GET_PLAYER(globalCtx);
    s32 unk_314 = pthis->unk_314;
    s16 temp_v0 = func_80B57104(pthis, unk_314);
    s32 pad2;
    s16 phi_v1;

    unk_3F8->unk_18.y = player->actor.world.pos.y;
    unk_3F8->unk_18.x = (Math_SinS(temp_v0) * pthis->actor.xzDistToPlayer) + pthis->actor.world.pos.x;
    unk_3F8->unk_18.z = (Math_CosS(temp_v0) * pthis->actor.xzDistToPlayer) + pthis->actor.world.pos.z;
    unk_3F8->unk_14 = kREG(16) - 16.0f;
    func_80034A14(&pthis->actor, unk_3F8, kREG(17) + 0xC, 4);

    phi_v1 = ABS(temp_v0 - *sp32);
    if (phi_v1 <= 0x320) {
        *sp32 = temp_v0;
        pthis->actor.world.rot.y = *sp32;
        phi_v1 = 0;
    }
    pthis->actor.world.rot.y = *sp32;
    return phi_v1;
}

void func_80B57EAC(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B57324(pthis, globalCtx)) {
        pthis->action = 26;
    } else {
        func_80B57350(pthis, globalCtx);
    }
}

void func_80B57EEC(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B573C8(pthis, globalCtx)) {
        pthis->action = 27;
    }
}

void func_80B57F1C(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B57D80(pthis, globalCtx) == 0) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009BE4, 0, -8.0f, 0);
        pthis->action = 34;
        pthis->unk_314 -= 1;
        func_80B57AE0(pthis, globalCtx);
    }
}

s32 func_80B57F84(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B575D0(pthis, globalCtx) && func_80B57C7C(pthis, globalCtx) && !Gameplay_InCsMode(globalCtx)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, -8.0f, 0);
        pthis->action = 36;
        pthis->unk_2EC = 0.0f;
        func_80B57A74(globalCtx);
        return 1;
    }
    return 0;
}

void func_80B58014(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s8 invincibilityTimer = player->invincibilityTimer;

    if (func_80B57324(pthis, globalCtx)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, -11.0f, 0);
        pthis->action = 29;
        func_80B538B0(pthis);
    } else if (func_80B57C8C(pthis) && func_80B57F84(pthis, globalCtx)) {
        OnePointCutscene_Init(globalCtx, 4000, -99, &pthis->actor, MAIN_CAM);
        pthis->unk_3D0 = 0;
    } else if (func_80B576C8(pthis, globalCtx) && func_80B575B0(pthis, globalCtx) && !Gameplay_InCsMode(globalCtx)) {
        pthis->action = 0x1F;
        pthis->unk_3CC = 0.0f;
        func_80B537E8(pthis);
        pthis->unk_3D8 = 1;
        OnePointCutscene_Init(globalCtx, 4010, -99, &pthis->actor, MAIN_CAM);
    } else if (!func_80B57C8C(pthis) && !func_80B576C8(pthis, globalCtx) && func_80B57564(pthis, globalCtx)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009BE4, 0, -8.0f, 0);
        func_80B5764C(pthis, globalCtx);
        pthis->action = 34;
        pthis->unk_3D0 = 0;
        func_80B57AE0(pthis, globalCtx);
    } else if ((invincibilityTimer > 0) || (player->fallDistance >= 0x33)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_007664, 0, -11.0f, 0);
        pthis->action = 30;
        func_80B537E8(pthis);
        func_80B56DC8(pthis);
    } else {
        func_80B57350(pthis, globalCtx);
        func_80B538B0(pthis);
    }
}

void func_80B58214(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B573C8(pthis, globalCtx)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, -11.0f, 0);
        pthis->action = 28;
        pthis->unk_3D0 = 0;
    }
}

void func_80B58268(EnZl3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s8 invincibilityTimer = player->invincibilityTimer;

    if ((invincibilityTimer <= 0) && (player->fallDistance <= 50)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, -11.0f, 0);
        pthis->action = 28;
        pthis->unk_3D0 = 0;
    }
}

void func_80B582C8(EnZl3* pthis, GlobalContext* globalCtx) {
    f32* unk_3CC = &pthis->unk_3CC;
    s32 pad;

    if (*unk_3CC == kREG(14) + 10.0f) {
        *unk_3CC += 1.0f;
        func_80B54E14(pthis, &gZelda2Anime2Anim_008050, 0, -12.0f, 0);
        func_80B57704(pthis, globalCtx);
    } else if (*unk_3CC == kREG(15) + 20.0f) {
        *unk_3CC += 1.0f;
        func_80B56DC8(pthis);
        func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, -12.0f, 0);
    } else if (*unk_3CC == kREG(16) + 30.0f) {
        *unk_3CC += 1.0f;
        func_80B57858(globalCtx);
    } else if (*unk_3CC == kREG(17) + 40.0f) {
        func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
        *unk_3CC += 1.0f;
    } else if (*unk_3CC >= ((kREG(17) + 40.0f) + 1.0f)) {
        pthis->action = 32;
        *unk_3CC = 0.0f;
    } else {
        *unk_3CC += 1.0f;
    }
}

void func_80B584B4(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);
    s8 invincibilityTimer = player->invincibilityTimer;
    Actor* nearbyEnTest = Actor_FindNearby(globalCtx, &pthis->actor, ACTOR_EN_TEST, ACTORCAT_ENEMY, 8000.0f);

    if (D_80B5A4BC == 0) {
        if ((nearbyEnTest == NULL) && (!Gameplay_InCsMode(globalCtx))) {
            pthis->action = 33;
            OnePointCutscene_Init(globalCtx, 4011, -99, &pthis->actor, MAIN_CAM);
        } else if (invincibilityTimer > 0) {
            func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, -12.0f, 0);
            D_80B5A4BC = 1;
            func_80B56DC8(pthis);
        }
    } else {
        if ((nearbyEnTest == NULL) && (!Gameplay_InCsMode(globalCtx))) {
            func_80B54E14(pthis, &gZelda2Anime2Anim_007664, 0, -12.0f, 0);
            D_80B5A4BC = 0;
            pthis->action = 33;
            OnePointCutscene_Init(globalCtx, 4011, -99, &pthis->actor, MAIN_CAM);
        } else if (invincibilityTimer <= 0) {
            func_80B54E14(pthis, &gZelda2Anime2Anim_007664, 0, -12.0f, 0);
            D_80B5A4BC = 0;
        }
    }
}

void func_80B58624(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad[4];
    f32* unk_3CC = &pthis->unk_3CC;

    if (*unk_3CC == (kREG(18) + 10.0f)) {
        *unk_3CC += 1.0f;
        func_80B54E14(pthis, &gZelda2Anime2Anim_008050, 0, -12.0f, 0);
        func_80B5772C(pthis, globalCtx);
    } else if (*unk_3CC == kREG(19) + 20.0f) {
        *unk_3CC += 1.0f;
        pthis->actor.textId = 0x71AC;
        Message_StartTextbox(globalCtx, pthis->actor.textId, NULL);
        func_80B54E14(pthis, &gZelda2Anime2Anim_003FF8, 0, -12.0f, 0);
    } else if (*unk_3CC == ((kREG(19) + 20.0f) + 1.0f)) {
        if (Message_GetState(&globalCtx->msgCtx) == TEXT_STATE_CLOSING) {
            *unk_3CC += 1.0f;
            func_80B5357C(pthis, globalCtx);
            func_80B5357C(pthis, globalCtx);
            func_80B5357C(pthis, globalCtx);
            func_80B5357C(pthis, globalCtx);
            func_80B5357C(pthis, globalCtx);
        }
    } else {
        if (*unk_3CC >= kREG(20) + 30.0f) {
            pthis->action = 28;
            func_8005B1A4(GET_ACTIVE_CAM(globalCtx));
            func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, -12.0f, 0);
            *unk_3CC = 0.0f;
        } else {
            *unk_3CC += 1.0f;
        }
    }
}

void func_80B5884C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0038C0, 2, -8.0f, 0);
    pthis->action = 37;
    pthis->unk_36C = 1;
}

void func_80B58898(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_0038C0, 2, -8.0f, 1);
    pthis->action = 38;
    pthis->unk_374 = 1;
}

void func_80B588E8(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54E14(pthis, &gZelda2Anime2Anim_009BE4, 0, -8.0f, 0);
    func_80B57AE0(pthis, globalCtx);
    pthis->action = 39;
}

s32 func_80B58938(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B57C54(pthis)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, -8.0f, 0);
        pthis->action = 28;
        pthis->unk_3D0 = 0;
        return 1;
    }
    return 0;
}

s32 func_80B5899C(EnZl3* pthis, GlobalContext* globalCtx) {
    if ((pthis->actor.bgCheckFlags & 1)) {
        Player* player = GET_PLAYER(globalCtx);
        s8 invincibilityTimer = player->invincibilityTimer;

        if ((invincibilityTimer > 0) || (player->fallDistance >= 0x33)) {
            func_80B54E14(pthis, &gZelda2Anime2Anim_007664, 2, -11.0f, 0);
            pthis->action = 35;
            func_80B56DC8(pthis);
            return 1;
        }
    }
    return 0;
}

void func_80B58A1C(EnZl3* pthis, GlobalContext* globalCtx) {
    if (!func_80B58938(pthis, globalCtx)) {
        func_80B5899C(pthis, globalCtx);
    }
}

void func_80B58A50(EnZl3* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s8 invincibilityTimer = player->invincibilityTimer;

    if ((invincibilityTimer <= 0) && (player->fallDistance <= 50)) {
        func_80B54E14(pthis, &gZelda2Anime2Anim_009BE4, 0, -11.0f, 0);
        pthis->action = 34;
    }
}

void func_80B58AAC(EnZl3* pthis, GlobalContext* globalCtx) {
    f32* unk_2EC = &pthis->unk_2EC;

    *unk_2EC += 1.0f;
    if ((*unk_2EC >= kREG(7) + 24.0f) && (pthis->unk_36C == 0)) {
        func_80B57754(pthis, globalCtx);
        func_80B5884C(pthis, globalCtx);
    } else if ((*unk_2EC >= kREG(8) + 50.0f) && (pthis->unk_370 == 0)) {
        func_80B56EB8(pthis, globalCtx);
        pthis->unk_370 = 1;
    } else if ((*unk_2EC >= kREG(9) + 56.0f) && (pthis->unk_374 == 0)) {
        func_80B58898(pthis, globalCtx);
    } else if (*unk_2EC >= kREG(10) + 82.0f) {
        func_80B588E8(pthis, globalCtx);
    }
}

void func_80B58C08(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    Vec3f* unk_348 = &pthis->unk_348;
    Vec3f* unk_354 = &pthis->unk_354;
    Vec3f* thisPos = &pthis->actor.world.pos;
    s32 unk_344;
    s32 unk_346;
    s32 sp28;
    f32 temp_f0;

    pthis->unk_344 += 1;

    unk_344 = pthis->unk_344;
    unk_346 = pthis->unk_346;
    sp28 = unk_346 - kREG(11) - 2;
    temp_f0 = Environment_LerpWeightAccelDecel(unk_346, 0, unk_344, 3, 0);

    thisPos->x = unk_348->x + (temp_f0 * (unk_354->x - unk_348->x));
    thisPos->y = (unk_348->y + (temp_f0 * (unk_354->y - unk_348->y))) + pthis->unk_360;
    thisPos->z = unk_348->z + (temp_f0 * (unk_354->z - unk_348->z));

    if ((unk_344 - sp28) >= 0) {
        pthis->alpha = ((f32)(unk_346 - unk_344) / (kREG(11) + 2)) * 255.0f;
        pthis->drawConfig = 2;
    }

    if ((unk_346 - unk_344) <= 0) {
        Actor_Kill(&pthis->actor);
    }
}

void func_80B58D50(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B57EAC(pthis, globalCtx);
}

void func_80B58DB0(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B57EEC(pthis, globalCtx);
}

void func_80B58E10(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 60.0f);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B57F1C(pthis, globalCtx);
}

void func_80B58E7C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B53764(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58014(pthis, globalCtx);
    func_80B536B4(pthis);
}

void func_80B58EF4(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B538B0(pthis);
    func_80B53764(pthis, globalCtx);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58214(pthis, globalCtx);
}

void func_80B58F6C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B536C4(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58268(pthis, globalCtx);
}

void func_80B58FDC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B536C4(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B582C8(pthis, globalCtx);
}

void func_80B5904C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B536C4(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B584B4(pthis, globalCtx);
}

void func_80B590BC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B537E8(pthis);
    func_80B536C4(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58624(pthis, globalCtx);
}

void func_80B5912C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    func_80B56E38(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B57CB4(pthis, globalCtx);
    func_80B57D60(pthis, globalCtx);
    func_80B58A1C(pthis, globalCtx);
}

void func_80B591BC(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B538B0(pthis);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58A50(pthis, globalCtx);
}

void func_80B5922C(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B57298(pthis);
    Actor_SetFocus(&pthis->actor, 60.0f);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58AAC(pthis, globalCtx);
}

void func_80B592A8(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B57298(pthis);
    Actor_SetFocus(&pthis->actor, 60.0f);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B57AAC(pthis, EnZl3_UpdateSkelAnime(pthis), &gZelda2Anime2Anim_003D20);
    func_80B56DEC(pthis);
    func_80B58AAC(pthis, globalCtx);
}

void func_80B59340(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B57298(pthis);
    Actor_SetFocus(&pthis->actor, 60.0f);
    func_80B533FC(pthis, globalCtx);
    func_80B5366C(pthis, globalCtx);
    EnZl3_UpdateEyes(pthis);
    func_80B57AAC(pthis, EnZl3_UpdateSkelAnime(pthis), &gZelda2Anime2Anim_009FBC);
    func_80B58AAC(pthis, globalCtx);
}

void func_80B593D0(EnZl3* pthis, GlobalContext* globalCtx) {
    func_80B54DE0(pthis, globalCtx);
    func_80B536C4(pthis);
    func_80B57298(pthis);
    func_80B5366C(pthis, globalCtx);
    func_80B56E38(pthis, globalCtx);
    Actor_SetFocus(&pthis->actor, 60.0f);
    EnZl3_UpdateEyes(pthis);
    EnZl3_UpdateSkelAnime(pthis);
    func_80B58C08(pthis, globalCtx);
}

s32 func_80B5944C(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                  Gfx** gfx) {
    if (limbIndex == 14) {
        Mtx* mtx = (Mtx*)Graph_Alloc(globalCtx->state.gfxCtx, sizeof(Mtx) * 7);
        EnZl3* pthis = (EnZl3*)thisx;
        Vec3s* vec = &pthis->unk_3F8.unk_08;

        gSPSegment(gfx[0]++, 0x0C, mtx);

        rot->x += vec->y;
        rot->z += vec->x;
        Matrix_Push();
        Matrix_Translate(pos->x, pos->y, pos->z, MTXMODE_APPLY);
        Matrix_RotateZYX(rot->x, rot->y, rot->z, MTXMODE_APPLY);
        Matrix_Push();
        Matrix_Translate(174.0f, -317.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[0], "../z_en_zl3_inEscape.c", 2471);
        Matrix_Translate(-410.0f, -184.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[1], "../z_en_zl3_inEscape.c", 2474);
        Matrix_Translate(-1019.0f, -26.0f, 0.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[2], "../z_en_zl3_inEscape.c", 2477);
        Matrix_Pop();
        Matrix_Push();
        Matrix_Translate(40.0f, 264.0f, 386.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[3], "../z_en_zl3_inEscape.c", 2483);
        Matrix_Translate(-446.0f, -52.0f, 84.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[4], "../z_en_zl3_inEscape.c", 2486);
        Matrix_Pop();
        Matrix_Push();
        Matrix_Translate(40.0f, 264.0f, -386.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[5], "../z_en_zl3_inEscape.c", 2492);
        Matrix_Translate(-446.0f, -52.0f, -84.0f, MTXMODE_APPLY);
        Matrix_ToMtx(&mtx[6], "../z_en_zl3_inEscape.c", 2495);
        Matrix_Pop();
        Matrix_Pop();
    }
    return false;
}

s32 func_80B59698(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 cond = Flags_GetSwitch(globalCtx, 0x37) &&
               ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO));

    if (cond) {
        u8 curSpawn = globalCtx->curSpawn;

        if ((func_80B54DB4(pthis) == 0x20) && (curSpawn == 0) &&
            ((gSaveContext.timer2Value <= 0) || (gSaveContext.timer2State == 0))) {
            return 1;
        }
    }
    return 0;
}

s32 func_80B59768(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 cond = Flags_GetSwitch(globalCtx, 0x37) &&
               ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO));

    if (cond) {
        u8 curSpawn = globalCtx->curSpawn;

        if ((func_80B54DB4(pthis) == 0x20) && (curSpawn == 0) && (gSaveContext.timer2Value <= 0)) {
            return 1;
        }
    }
    return 0;
}

void func_80B59828(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B59698(pthis, globalCtx) || (!func_80B56EE4(pthis, globalCtx) && func_80B57890(pthis, globalCtx))) {
        s16 newRotY;

        func_80B54E14(pthis, &gZelda2Anime2Anim_009FBC, 0, 0.0f, 0);
        pthis->actor.flags |= ACTOR_FLAG_0 | ACTOR_FLAG_3;
        func_80B56F10(pthis, globalCtx);
        newRotY = func_80B571A8(pthis);
        pthis->actor.shape.rot.y = newRotY;
        pthis->actor.world.rot.y = newRotY;
        pthis->unk_3C4 = pthis->actor.world.rot.z;
        pthis->actor.shape.rot.z = 0;
        pthis->actor.world.rot.z = pthis->actor.shape.rot.z;
        pthis->action = 28;
        pthis->drawConfig = 1;
    } else {
        Actor_Kill(&pthis->actor);
    }

    if (func_80B59698(pthis, globalCtx) != 0) {
        func_80088AA0(180);
        func_80B53468();
        gSaveContext.healthAccumulator = 320;
        Magic_Fill(globalCtx);
        if (Flags_GetSwitch(globalCtx, 0x20)) {
            Flags_UnsetSwitch(globalCtx, 0x20);
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BG_ZG, -144.0f, 3544.0f, -43.0f, 0, 0x2000, 0, 0x2000);
        }
        Flags_UnsetSwitch(globalCtx, 0x21);
        Flags_UnsetSwitch(globalCtx, 0x22);
        Flags_UnsetSwitch(globalCtx, 0x23);
        Flags_UnsetSwitch(globalCtx, 0x24);
        Flags_UnsetSwitch(globalCtx, 0x25);
        Flags_UnsetSwitch(globalCtx, 0x26);
        Flags_UnsetSwitch(globalCtx, 0x27);
        Flags_UnsetSwitch(globalCtx, 0x28);
        Flags_UnsetSwitch(globalCtx, 0x29);
        Flags_UnsetSwitch(globalCtx, 0x2A);
    }

    if (func_80B54DB4(pthis) == 0x20) {
        s32 cond;

        func_80B54EA4(pthis, globalCtx);
        cond = Flags_GetSwitch(globalCtx, 0x37) &&
               ((globalCtx->sceneNum == SCENE_GANON_DEMO) || (globalCtx->sceneNum == SCENE_GANON_FINAL) ||
                (globalCtx->sceneNum == SCENE_GANON_SONOGO) || (globalCtx->sceneNum == SCENE_GANONTIKA_SONOGO));
        if (cond) {
            func_80B53614(pthis, globalCtx);
        }
    }
}

void func_80B59A80(EnZl3* pthis, GlobalContext* globalCtx) {
    if (func_80B59768(pthis, globalCtx)) {
        Audio_PlaySoundGeneral(NA_SE_OC_REVENGE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
    }
}

void func_80B59AD0(EnZl3* pthis, GlobalContext* globalCtx) {
    // todo look into
    Actor* thisx = &pthis->actor; // unused, necessary to use 'pthis' first to fix regalloc

    Flags_SetSwitch(globalCtx, 0x36);
    func_80088AA0(180);
    func_80B54EA4(pthis, globalCtx);
    func_80B53614(pthis, globalCtx);
    gSaveContext.eventChkInf[12] &= ~0x80;
    func_80B56F10(pthis, globalCtx);
    gSaveContext.healthAccumulator = 320;
    Magic_Fill(globalCtx);
    pthis->action = 27;
    pthis->drawConfig = 1;
}

void func_80B59B6C(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 sp2C = func_80B54DD4(pthis);

    pthis->unk_3DC = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_0091D8));
    pthis->unk_3E0 = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_00A598));
    pthis->unk_3E4 = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_00A334));
    pthis->unk_3F4 = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_001110));
    pthis->unk_3EC = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_002348));
    pthis->unk_3F0 = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_002E54));
    pthis->unk_3E8 = Animation_GetLastFrame(SEGMENTED_TO_VIRTUAL(&gZelda2Anime2Anim_001D8C));

    switch (sp2C) {
        case 0:
            func_80B54FB4(pthis, globalCtx);
            break;
        case 1:
            func_80B55780(pthis, globalCtx);
            break;
        case 3:
            func_80B59828(pthis, globalCtx);
            break;
        default:
            osSyncPrintf(VT_FGCOL(RED) " En_Oa3 の arg_data がおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
            Actor_Kill(&pthis->actor);
    }
}

void func_80B59DB8(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad;
    ObjectContext* objCtx = &globalCtx->objectCtx;
    s32 objIndex = Object_GetIndex(objCtx, OBJECT_ZL2_ANIME2);
    s32 pad2;

    if (objIndex < 0) {
        osSyncPrintf(VT_FGCOL(RED) "En_Zl3_main_bankアニメーションのバンクを読めない!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    if (Object_IsLoaded(objCtx, objIndex)) {
        pthis->unk_318 = objIndex;
        func_80B54DE0(pthis, globalCtx);
        func_80B59B6C(pthis, globalCtx);
    }
}

static EnZl3ActionFunc sActionFuncs[] = {
    func_80B59DB8, func_80B55550, func_80B555A4, func_80B55604, func_80B5566C, func_80B556CC, func_80B5572C,
    func_80B56658, func_80B566AC, func_80B5670C, func_80B5676C, func_80B567CC, func_80B5682C, func_80B568B4,
    func_80B5691C, func_80B5697C, func_80B569E4, func_80B56A68, func_80B56AE0, func_80B56B54, func_80B56BA8,
    func_80B56C24, func_80B56C84, func_80B56CE4, func_80B56D44, func_80B58D50, func_80B58DB0, func_80B58E10,
    func_80B58E7C, func_80B58EF4, func_80B58F6C, func_80B58FDC, func_80B5904C, func_80B590BC, func_80B5912C,
    func_80B591BC, func_80B5922C, func_80B592A8, func_80B59340, func_80B593D0,
};

void EnZl3_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnZl3* pthis = (EnZl3*)thisx;

    if (pthis->action < 0 || pthis->action >= ARRAY_COUNT(sActionFuncs) || sActionFuncs[pthis->action] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sActionFuncs[pthis->action](pthis, globalCtx);
}

void EnZl3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnZl3* pthis = (EnZl3*)thisx;
    ActorShape* shape = &pthis->actor.shape;
    s32 pad;

    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_ct通すよ!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    ActorShape_Init(shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    shape->shadowAlpha = 0;
    func_80B533B0(thisx, globalCtx);
    SkelAnime_InitFlex(globalCtx, &pthis->skelAnime, &gZelda2Skel, NULL, pthis->jointTable, pthis->morphTable, 15);

    switch (func_80B54DD4(pthis)) {
        case 1:
            gSaveContext.timer2State = 0;
            break;
        case 3:
            func_80B59A80(pthis, globalCtx);
            break;
    }

    osSyncPrintf("ゼルダ姫のEn_Zl3_Actor_ctは通った!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

static OverrideLimbDraw sOverrideLimbDrawFuncs[] = {
    func_80B5458C,
    func_80B5944C,
};

s32 EnZl3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                           Gfx** gfx) {
    EnZl3* pthis = (EnZl3*)thisx;

    if (pthis->unk_308 < 0 || pthis->unk_308 >= ARRAY_COUNT(sOverrideLimbDrawFuncs) ||
        sOverrideLimbDrawFuncs[pthis->unk_308] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画前処理モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return 0;
    }
    return sOverrideLimbDrawFuncs[pthis->unk_308](globalCtx, limbIndex, dList, pos, rot, thisx, gfx);
}

void func_80B59FE8(EnZl3* pthis, GlobalContext* globalCtx) {
}

void func_80B59FF4(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTex = sEyeTextures[eyeTexIndex];
    s16 mouthTexIndex = pthis->mouthTexIndex;
    SkelAnime* skelAnime = &pthis->skelAnime;
    void* mouthTex = sMouthTextures[mouthTexIndex];
    s32 pad2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zl3.c", 2165);

    func_80093D18(globalCtx->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x8, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_OPA_DISP++, 0x9, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_OPA_DISP++, 0xA, SEGMENTED_TO_VIRTUAL(mouthTex));
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPSegment(POLY_OPA_DISP++, 0xB, &D_80116280[2]);

    POLY_OPA_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       EnZl3_OverrideLimbDraw, EnZl3_PostLimbDraw, pthis, POLY_OPA_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zl3.c", 2190);
}

void func_80B5A1D0(EnZl3* pthis, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 eyeTexIndex = pthis->eyeTexIndex;
    void* eyeTex = sEyeTextures[eyeTexIndex];
    s16 mouthTexIndex = pthis->mouthTexIndex;
    SkelAnime* skelAnime = &pthis->skelAnime;
    void* mouthTex = sMouthTextures[mouthTexIndex];
    s32 pad2;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_zl3.c", 2205);

    func_80093D84(globalCtx->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 8, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_XLU_DISP++, 9, SEGMENTED_TO_VIRTUAL(eyeTex));
    gSPSegment(POLY_XLU_DISP++, 10, SEGMENTED_TO_VIRTUAL(mouthTex));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, pthis->alpha);
    gSPSegment(POLY_XLU_DISP++, 11, &D_80116280[0]);

    POLY_XLU_DISP = SkelAnime_DrawFlex(globalCtx, skelAnime->skeleton, skelAnime->jointTable, skelAnime->dListCount,
                                       EnZl3_OverrideLimbDraw, NULL, pthis, POLY_XLU_DISP);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_zl3.c", 2234);
}

static EnZl3DrawFunc sDrawFuncs[] = {
    func_80B59FE8,
    func_80B59FF4,
    func_80B5A1D0,
};

void EnZl3_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnZl3* pthis = (EnZl3*)thisx;

    if (pthis->drawConfig < 0 || pthis->drawConfig >= 3 || sDrawFuncs[pthis->drawConfig] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }
    sDrawFuncs[pthis->drawConfig](pthis, globalCtx);
}

ActorInit En_Zl3_InitVars = {
    ACTOR_EN_ZL3,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZL2,
    sizeof(EnZl3),
    (ActorFunc)EnZl3_Init,
    (ActorFunc)EnZl3_Destroy,
    (ActorFunc)EnZl3_Update,
    (ActorFunc)EnZl3_Draw,
};

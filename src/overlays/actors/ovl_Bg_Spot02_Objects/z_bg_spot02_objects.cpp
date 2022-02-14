#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_BG_SPOT02_OBJECTS_Z_BG_SPOT02_OBJECTS_C
#include "actor_common.h"
/*
 * File: z_bg_spot02_objects.c
 * Overlay: ovl_Bg_Spot02_Objects
 * Description: Graveyard Actors
 */

#include "z_bg_spot02_objects.h"
#include "objects/object_spot02_objects/object_spot02_objects.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_cheap_proc.h"
#include "def/z_common_data.h"
#include "def/z_effect_soft_sprite_old_init.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void BgSpot02Objects_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot02Objects_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot02Objects_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot02Objects_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_808ACCB8(Actor* thisx, GlobalContext* globalCtx);
void func_808AD450(Actor* thisx, GlobalContext* globalCtx);

void func_808AC8FC(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808AC908(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808ACA08(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808ACAFC(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808ACB58(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808ACC34(BgSpot02Objects* pthis, GlobalContext* globalCtx);
void func_808AD3D4(BgSpot02Objects* pthis, GlobalContext* globalCtx);

static void* D_808AD850[] = {
    object_spot02_objects_Tex_0096B0, object_spot02_objects_Tex_00A2B0, object_spot02_objects_Tex_00AEB0,
    object_spot02_objects_Tex_00BAB0, object_spot02_objects_Tex_00C6B0, object_spot02_objects_Tex_00D2B0,
    object_spot02_objects_Tex_00DEB0, object_spot02_objects_Tex_00EAB0, object_spot02_objects_Tex_00F6B0,
    object_spot02_objects_Tex_0102B0, object_spot02_objects_Tex_010EB0, object_spot02_objects_Tex_011AB0,
};

ActorInit Bg_Spot02_Objects_InitVars = {
    ACTOR_BG_SPOT02_OBJECTS,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT02_OBJECTS,
    sizeof(BgSpot02Objects),
    (ActorFunc)BgSpot02Objects_Init,
    (ActorFunc)BgSpot02Objects_Destroy,
    (ActorFunc)BgSpot02Objects_Update,
    (ActorFunc)BgSpot02Objects_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgSpot02Objects_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgSpot02Objects* pthis = (BgSpot02Objects*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, 0);
    pthis->unk_16B = (u16)(thisx->params >> 8);
    thisx->params = (u16)(thisx->params & 0xFF);

    switch (thisx->params) {
        case 0:
        case 1:
        case 2:
            Actor_ProcessInitChain(thisx, sInitChain);

            if (thisx->params == 0) {
                if (Flags_GetSwitch(globalCtx, pthis->unk_16B)) {
                    pthis->actionFunc = func_808AC8FC;
                    thisx->world.pos.y += 255.0f;
                } else {
                    pthis->actionFunc = func_808ACAFC;
                }

                CollisionHeader_GetVirtual(&object_spot02_objects_Col_012BA4, &colHeader);
            } else if (thisx->params == 1) {
                pthis->actionFunc = func_808AC8FC;
                CollisionHeader_GetVirtual(&object_spot02_objects_Col_0128D8, &colHeader);
                thisx->flags |= ACTOR_FLAG_22;
            } else {
                if (globalCtx->sceneNum == SCENE_SPOT02) {
                    pthis->actionFunc = func_808AC908;
                } else {
                    pthis->actionFunc = func_808AC8FC;
                }

                CollisionHeader_GetVirtual(&object_spot02_objects_Col_0133EC, &colHeader);
            }

            pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);

            if (((gSaveContext.eventChkInf[1] & 0x2000) && (globalCtx->sceneNum == SCENE_SPOT02) &&
                 (thisx->params == 2)) ||
                (LINK_IS_ADULT && (thisx->params == 1))) {
                Actor_Kill(thisx);
            }
            break;

        case 3:
            pthis->unk_16A = 0;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_ITEMACTION);
            pthis->actionFunc = func_808ACC34;
            thisx->draw = func_808ACCB8;

            if (gSaveContext.eventChkInf[1] & 0x2000) {
                Actor_Kill(thisx);
            }
            break;

        case 4:
            pthis->timer = -12;
            pthis->unk_170 = 0xFFFF;
            Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, thisx, ACTORCAT_ITEMACTION);
            pthis->actionFunc = func_808AD3D4;
            thisx->draw = func_808AD450;
            break;
    }
}

void BgSpot02Objects_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot02Objects* pthis = (BgSpot02Objects*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

void func_808AC8FC(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
}

void func_808AC908(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    static Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    Vec3f pos;

    if (globalCtx->csCtx.state != 0) {
        if (globalCtx->csCtx.npcActions[3] != NULL && globalCtx->csCtx.npcActions[3]->action == 2) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_GRAVE_EXPLOSION);
            gSaveContext.eventChkInf[1] |= 0x2000;
            pthis->timer = 25;
            pos.x = (Math_SinS(pthis->dyna.actor.shape.rot.y) * 50.0f) + pthis->dyna.actor.world.pos.x;
            pos.y = pthis->dyna.actor.world.pos.y + 30.0f;
            pos.z = (Math_CosS(pthis->dyna.actor.shape.rot.y) * 50.0f) + pthis->dyna.actor.world.pos.z;
            EffectSsBomb2_SpawnLayered(globalCtx, &pos, &zeroVec, &zeroVec, 70, 30);
            pthis->actionFunc = func_808ACA08;
        }
    }
}

void func_808ACA08(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->timer != 0) {
        pthis->timer--;
    }

    if (pthis->timer == 20) {
        pthis->dyna.actor.draw = NULL;
        EffectSsHahen_SpawnBurst(globalCtx, &pthis->dyna.actor.world.pos, 30.0f, 0, 25, 5, 40, OBJECT_SPOT02_OBJECTS, 20,
                                 object_spot02_objects_DL_012D30);
    } else if (pthis->timer == 0) {
        Actor_Kill(&pthis->dyna.actor);
    }

    if (globalCtx->csCtx.frames == 402) {
        if (!LINK_IS_ADULT) {
            func_8002F7DC(&player->actor, NA_SE_VO_LI_DEMO_DAMAGE_KID);
        } else {
            func_8002F7DC(&player->actor, NA_SE_VO_LI_DEMO_DAMAGE);
        }
    }
}

void func_808ACAFC(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, pthis->unk_16B)) {
        Actor_SetFocus(&pthis->dyna.actor, 60.0f);
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        pthis->actionFunc = func_808ACB58;
    }
}

void func_808ACB58(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    if (Math_StepToF(&pthis->dyna.actor.world.pos.y, pthis->dyna.actor.home.pos.y + 255.0f, 1.0f)) {
        Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_EV_STONEDOOR_STOP);
        pthis->actionFunc = func_808AC8FC;
    } else {
        func_8002F974(&pthis->dyna.actor, NA_SE_EV_WALL_MOVE_SP - SFX_FLAG);
    }
}

void BgSpot02Objects_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot02Objects* pthis = (BgSpot02Objects*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void BgSpot02Objects_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* dLists[] = {
        object_spot02_objects_DL_012A50,
        object_spot02_objects_DL_0127C0,
        object_spot02_objects_DL_0130B0,
    };

    Gfx_DrawDListOpa(globalCtx, dLists[thisx->params]);
}

void func_808ACC34(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != 0 && globalCtx->csCtx.npcActions[0] != NULL &&
        globalCtx->csCtx.npcActions[0]->action == 2) {
        pthis->unk_16A++;

        if (pthis->unk_16A >= 12) {
            Actor_Kill(&pthis->dyna.actor);
        }
    }

    if (globalCtx->csCtx.frames == 245 || globalCtx->csCtx.frames == 351) {
        func_800788CC(NA_SE_EV_LIGHTNING);
    }
}

void func_808ACCB8(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot02Objects* pthis = (BgSpot02Objects*)thisx;
    f32 rate;
    s32 pad;
    u8 redPrim;
    u8 greenPrim;
    u8 bluePrim;
    u8 redEnv;
    u8 greenEnv;
    u8 blueEnv;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 600);

    if (globalCtx->csCtx.state != 0 && globalCtx->csCtx.npcActions[0] != NULL &&
        globalCtx->csCtx.npcActions[0]->action == 2) {
        if (pthis->unk_16A < 5) {
            rate = (pthis->unk_16A / 5.0f);
            redPrim = greenPrim = bluePrim = 255;
            redEnv = 100.0f + 155.0f * rate;
            greenEnv = 255;
            blueEnv = 255.0f - 155.0f * rate;
        } else {
            rate = ((pthis->unk_16A - 5) / 7.0f);
            redPrim = 255.0f - (255.0f * rate);
            greenPrim = 255.0f - (55.0f * rate);
            bluePrim = 255.0f - (255.0f * rate);
            redEnv = 255.0f - (105.0f * rate);
            greenEnv = 255.0f - (255.0f * rate);
            blueEnv = 100.0f + (100.0f * rate);
        }

        Matrix_Translate(globalCtx->csCtx.npcActions[0]->startPos.x, globalCtx->csCtx.npcActions[0]->startPos.y,
                         globalCtx->csCtx.npcActions[0]->startPos.z, MTXMODE_NEW);
        Matrix_RotateX(globalCtx->csCtx.npcActions[0]->urot.x * (M_PI / (f32)0x8000), MTXMODE_APPLY);
        Matrix_RotateY(globalCtx->csCtx.npcActions[0]->urot.y * (M_PI / (f32)0x8000), MTXMODE_APPLY);
        Matrix_RotateZ(globalCtx->csCtx.npcActions[0]->urot.z * (M_PI / (f32)0x8000), MTXMODE_APPLY);
        Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
        func_80093D84(globalCtx->state.gfxCtx);

        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, redPrim, greenPrim, bluePrim, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, redEnv, greenEnv, blueEnv, 255);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 679),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(D_808AD850[pthis->unk_16A]));
        gDPPipeSync(POLY_XLU_DISP++);
        gSPDisplayList(POLY_XLU_DISP++, object_spot02_objects_DL_0126F0);
        gDPPipeSync(POLY_XLU_DISP++);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 692);
}

void func_808AD3D4(BgSpot02Objects* pthis, GlobalContext* globalCtx) {
    if (globalCtx->csCtx.state != 0 && globalCtx->csCtx.npcActions[2] != NULL &&
        globalCtx->csCtx.npcActions[2]->action == 2) {
        if (pthis->timer == 2) {
            Audio_PlayActorSound2(&pthis->dyna.actor, NA_SE_IT_EXPLOSION_ICE);
        }

        if (pthis->timer < 32) {
            pthis->timer++;
        } else {
            Actor_Kill(&pthis->dyna.actor);
        }
    }
}

void func_808AD450(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot02Objects* pthis = (BgSpot02Objects*)thisx;
    s32 pad;
    f32 lerp;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 736);

    if (globalCtx->csCtx.state != 0 && globalCtx->csCtx.npcActions[2] != NULL) {
        u16 temp_v1 = globalCtx->csCtx.npcActions[2]->urot.z * 0.00549325f;

        if (pthis->unk_170 != temp_v1) {
            if (pthis->unk_170 == 0xFFFF) {
                pthis->unk_170 = temp_v1;
                pthis->unk_172 = temp_v1;
            } else {
                pthis->unk_172 = pthis->unk_170;
                pthis->unk_170 = temp_v1;
            }
        }

        lerp = Environment_LerpWeight(globalCtx->csCtx.npcActions[2]->endFrame, globalCtx->csCtx.npcActions[2]->startFrame, globalCtx->csCtx.frames);

        // should be able to remove & 0xFFFF with some other change
        if ((globalCtx->csCtx.npcActions[2]->action & 0xFFFF) == 2) {
            Matrix_Translate(globalCtx->csCtx.npcActions[2]->startPos.x, globalCtx->csCtx.npcActions[2]->startPos.y,
                             globalCtx->csCtx.npcActions[2]->startPos.z, MTXMODE_NEW);
            Matrix_RotateX(globalCtx->csCtx.npcActions[2]->urot.x * (M_PI / (f32)0x8000), MTXMODE_APPLY);
            Matrix_RotateY(globalCtx->csCtx.npcActions[2]->urot.y * (M_PI / (f32)0x8000), MTXMODE_APPLY);
            Matrix_Scale(0.9f, 0.9f, (((pthis->unk_170 - pthis->unk_172) * lerp) + pthis->unk_172) * 0.1f, MTXMODE_APPLY);
            func_80093D84(globalCtx->state.gfxCtx);

            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 170, 128);
            gDPSetEnvColor(POLY_XLU_DISP++, 150, 120, 0, 128);
            gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 795),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 2 * pthis->timer, -3 * pthis->timer, 32, 64, 1,
                                        4 * pthis->timer, -6 * pthis->timer, 32, 64));
            gDPPipeSync(POLY_XLU_DISP++);
            gSPDisplayList(POLY_XLU_DISP++, object_spot02_objects_DL_0013F0);
            gDPPipeSync(POLY_XLU_DISP++);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_spot02_objects.c", 818);
}

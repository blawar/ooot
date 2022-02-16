#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_OBJ_TIMEBLOCK_Z_OBJ_TIMEBLOCK_C
#include "actor_common.h"
/*
 * File: z_obj_timeblock.c
 * Overlay: ovl_Obj_Timeblock
 * Description: Song of Time Block
 */

#include "z_obj_timeblock.h"
#include "objects/object_timeblock/object_timeblock.h"
#include "def/code_80043480.h"
#include "def/sys_matrix.h"
#include "def/z_actor.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_message_PAL.h"
#include "def/z_onepointdemo.h"
#include "def/z_rcp.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_4 | ACTOR_FLAG_25 | ACTOR_FLAG_27)

void ObjTimeblock_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjTimeblock_Reset(Actor* pthisx, GlobalContext* globalCtx);
void ObjTimeblock_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjTimeblock_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjTimeblock_Draw(Actor* thisx, GlobalContext* globalCtx);

void ObjTimeblock_SetupNormal(ObjTimeblock* pthis);
void ObjTimeblock_SetupAltBehaviorVisible(ObjTimeblock* pthis);
void ObjTimeblock_SetupAltBehaviourNotVisible(ObjTimeblock* pthis);

s32 ObjTimeblock_WaitForOcarina(ObjTimeblock* pthis, GlobalContext* globalCtx);
s32 ObjTimeblock_WaitForSong(ObjTimeblock* pthis, GlobalContext* globalCtx);
void ObjTimeblock_DoNothing(ObjTimeblock* pthis, GlobalContext* globalCtx);
void ObjTimeblock_Normal(ObjTimeblock* pthis, GlobalContext* globalCtx);
void ObjTimeblock_AltBehaviorVisible(ObjTimeblock* pthis, GlobalContext* globalCtx);
void ObjTimeblock_AltBehaviourNotVisible(ObjTimeblock* pthis, GlobalContext* globalCtx);

ActorInit Obj_Timeblock_InitVars = {
    ACTOR_OBJ_TIMEBLOCK,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_TIMEBLOCK,
    sizeof(ObjTimeblock),
    (ActorFunc)ObjTimeblock_Init,
    (ActorFunc)ObjTimeblock_Destroy,
    (ActorFunc)ObjTimeblock_Update,
    (ActorFunc)ObjTimeblock_Draw,
    (ActorFunc)ObjTimeblock_Reset,
}; 

static ObjTimeblockSizeOptions sSizeOptions[] = {
    { 1.0, 60.0, 0x0018 },
    { 0.60, 40.0, 0x0019 },
};

static f32 sRanges[] = { 60.0, 100.0, 140.0, 180.0, 220.0, 260.0, 300.0, 300.0 };

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1800, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1500, ICHAIN_STOP),
};

static Color_RGB8 sPrimColors[] = {
    { 100, 120, 140 }, { 80, 140, 200 }, { 100, 150, 200 }, { 100, 200, 240 },
    { 80, 110, 140 },  { 70, 160, 225 }, { 80, 100, 130 },  { 100, 110, 190 },
};

u32 ObjTimeblock_CalculateIsVisible(ObjTimeblock* pthis) {
    if (!((pthis->dyna.actor.params >> 10) & 1)) {
        if (pthis->unk_177 == 0) {
            return pthis->unk_175;
        } else {
            u8 temp = ((pthis->dyna.actor.params >> 15) & 1) ? true : false;

            if (pthis->unk_177 == 1) {
                return pthis->unk_174 ^ temp;
            } else {
                u8 linkIsYoung = (LINK_AGE_IN_YEARS == YEARS_CHILD) ? true : false;

                return pthis->unk_174 ^ temp ^ linkIsYoung;
            }
        }
    } else {
        return (((pthis->dyna.actor.params >> 15) & 1) ? true : false) ^ pthis->unk_174;
    }
}

void ObjTimeblock_SpawnDemoEffect(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_DEMO_EFFECT, pthis->dyna.actor.world.pos.x,
                pthis->dyna.actor.world.pos.y, pthis->dyna.actor.world.pos.z, 0, 0, 0,
                sSizeOptions[(pthis->dyna.actor.params >> 8) & 1].demoEffectParams);
}

void ObjTimeblock_ToggleSwitchFlag(GlobalContext* globalCtx, s32 flag) {
    if (Flags_GetSwitch(globalCtx, flag)) {
        Flags_UnsetSwitch(globalCtx, flag);
    } else {
        Flags_SetSwitch(globalCtx, flag);
    }
}

void ObjTimeblock_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjTimeblock* pthis = (ObjTimeblock*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&pthis->dyna, DPM_UNK);
    pthis->dyna.actor.world.rot.z = pthis->dyna.actor.shape.rot.z = 0;

    CollisionHeader_GetVirtual(&gSongOfTimeBlockCol, &colHeader);

    pthis->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &pthis->dyna.actor, colHeader);

    Actor_ProcessInitChain(&pthis->dyna.actor, sInitChain);
    Actor_SetScale(&pthis->dyna.actor, sSizeOptions[(pthis->dyna.actor.params >> 8) & 1].scale);

    if ((pthis->dyna.actor.params >> 6) & 1) {
        pthis->unk_177 = 0;
    } else {
        pthis->unk_177 = ((pthis->dyna.actor.params & 0x3F) < 0x38) ? 2 : 1;
    }

    pthis->songObserverFunc = ObjTimeblock_WaitForOcarina;

    Actor_SetFocus(&pthis->dyna.actor, sSizeOptions[(pthis->dyna.actor.params >> 8) & 1].height);

    pthis->unk_174 = (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) ? true : false;
    pthis->unk_175 = ((pthis->dyna.actor.params >> 15) & 1) ? true : false;
    pthis->isVisible = ObjTimeblock_CalculateIsVisible(pthis);

    if (!((pthis->dyna.actor.params >> 10) & 1)) {
        ObjTimeblock_SetupNormal(pthis);
    } else if (pthis->isVisible) {
        ObjTimeblock_SetupAltBehaviorVisible(pthis);
    } else {
        ObjTimeblock_SetupAltBehaviourNotVisible(pthis);
    }

    // "Block of time"
    osSyncPrintf("時のブロック (<arg> %04xH <type> save:%d color:%d range:%d move:%d)\n", (u16)pthis->dyna.actor.params,
                 pthis->unk_177, pthis->dyna.actor.home.rot.z & 7, (pthis->dyna.actor.params >> 11) & 7,
                 (pthis->dyna.actor.params >> 10) & 1);
}

void ObjTimeblock_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    ObjTimeblock* pthis = (ObjTimeblock*)thisx;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
}

u8 ObjTimeblock_PlayerIsInRange(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    if (pthis->isVisible && func_80043590(&pthis->dyna)) {
        return false;
    }

    if (pthis->dyna.actor.xzDistToPlayer <= sRanges[(pthis->dyna.actor.params >> 11) & 7]) {
        Vec3f distance;
        f32 blockSize;

        func_8002DBD0(&pthis->dyna.actor, &distance, &GET_PLAYER(globalCtx)->actor.world.pos);
        blockSize = pthis->dyna.actor.scale.x * 50.0f + 6.0f;
        // Return true if player's xz position is not inside the block
        if (blockSize < fabsf(distance.x) || blockSize < fabsf(distance.z)) {
            return true;
        }
    }

    return false;
}

s32 ObjTimeblock_WaitForOcarina(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (ObjTimeblock_PlayerIsInRange(pthis, globalCtx)) {
        if (player->stateFlags2 & 0x1000000) {
            func_8010BD58(globalCtx, OCARINA_ACTION_FREE_PLAY);
            pthis->songObserverFunc = ObjTimeblock_WaitForSong;
        } else {
            player->stateFlags2 |= 0x800000;
        }
    }
    return false;
}

s32 ObjTimeblock_WaitForSong(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    if (globalCtx->msgCtx.ocarinaMode == OCARINA_MODE_04) {
        pthis->songObserverFunc = ObjTimeblock_WaitForOcarina;
    }
    if (globalCtx->msgCtx.lastPlayedSong == OCARINA_SONG_TIME) {
        if (pthis->unk_172 == 254) {
            pthis->songEndTimer = 110;
        } else {
            pthis->songEndTimer--;
            if (pthis->songEndTimer == 0) {
                return true;
            }
        }
    }
    return false;
}

void ObjTimeblock_SetupDoNothing(ObjTimeblock* pthis) {
    pthis->actionFunc = ObjTimeblock_DoNothing;
}

void ObjTimeblock_DoNothing(ObjTimeblock* pthis, GlobalContext* globalCtx) {
}

void ObjTimeblock_SetupNormal(ObjTimeblock* pthis) {
    pthis->actionFunc = ObjTimeblock_Normal;
}

void ObjTimeblock_Normal(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    u32 newIsVisible;

    if (pthis->songObserverFunc(pthis, globalCtx) && pthis->demoEffectTimer <= 0) {
        ObjTimeblock_SpawnDemoEffect(pthis, globalCtx);
        pthis->demoEffectTimer = 160;

        // Possibly points the camera to pthis actor
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        // "◯◯◯◯ Time Block Attention Camera (frame counter  %d)\n"
        //osSyncPrintf("◯◯◯◯ Time Block 注目カメラ (frame counter  %d)\n", globalCtx->state.frames);

        pthis->demoEffectFirstPartTimer = 12;

        if (pthis->unk_177 == 0) {
            pthis->dyna.actor.params ^= 0x8000;
        } else {
            ObjTimeblock_ToggleSwitchFlag(globalCtx, pthis->dyna.actor.params & 0x3F);
        }
    }

    pthis->unk_172 = globalCtx->msgCtx.lastPlayedSong;
    if (pthis->demoEffectFirstPartTimer > 0) {
        pthis->demoEffectFirstPartTimer--;
        if (pthis->demoEffectFirstPartTimer == 0) {
            if (pthis->unk_177 == 0) {
                pthis->unk_175 = ((pthis->dyna.actor.params >> 15) & 1) ? true : false;
            } else {
                pthis->unk_174 = (Flags_GetSwitch(globalCtx, pthis->dyna.actor.params & 0x3F)) ? true : false;
            }
        }
    }

    newIsVisible = ObjTimeblock_CalculateIsVisible(pthis);
    if (pthis->unk_177 == 1 && newIsVisible != pthis->isVisible) {
        ObjTimeblock_SetupDoNothing(pthis);
    }
    pthis->isVisible = newIsVisible;

    if (pthis->demoEffectTimer == 50) {
        func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
    }
}

void func_80BA06AC(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    s32 switchFlag = pthis->dyna.actor.params & 0x3F;

    pthis->unk_172 = globalCtx->msgCtx.lastPlayedSong;

    if (pthis->demoEffectFirstPartTimer > 0 && --pthis->demoEffectFirstPartTimer == 0) {
        pthis->unk_174 = (Flags_GetSwitch(globalCtx, switchFlag)) ? true : false;
    }

    pthis->isVisible = ObjTimeblock_CalculateIsVisible(pthis);
    pthis->unk_176 = (Flags_GetSwitch(globalCtx, switchFlag)) ? true : false;
}

void ObjTimeblock_SetupAltBehaviorVisible(ObjTimeblock* pthis) {
    pthis->actionFunc = ObjTimeblock_AltBehaviorVisible;
}

void ObjTimeblock_AltBehaviorVisible(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    if (pthis->songObserverFunc(pthis, globalCtx) && pthis->demoEffectTimer <= 0) {
        pthis->demoEffectFirstPartTimer = 12;
        ObjTimeblock_SpawnDemoEffect(pthis, globalCtx);
        pthis->demoEffectTimer = 160;
        OnePointCutscene_Attention(globalCtx, &pthis->dyna.actor);
        // "Time Block Attention Camera (frame counter)"
        //osSyncPrintf("◯◯◯◯ Time Block 注目カメラ (frame counter  %d)\n", globalCtx->state.frames);
        ObjTimeblock_ToggleSwitchFlag(globalCtx, pthis->dyna.actor.params & 0x3F);
    }

    func_80BA06AC(pthis, globalCtx);

    if (pthis->demoEffectTimer == 50) {
        func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
    }

    if (!pthis->isVisible && pthis->demoEffectTimer <= 0) {
        ObjTimeblock_SetupAltBehaviourNotVisible(pthis);
    }
}

void ObjTimeblock_SetupAltBehaviourNotVisible(ObjTimeblock* pthis) {
    pthis->actionFunc = ObjTimeblock_AltBehaviourNotVisible;
}

void ObjTimeblock_AltBehaviourNotVisible(ObjTimeblock* pthis, GlobalContext* globalCtx) {
    s32 switchFlag = pthis->dyna.actor.params & 0x3F;
    s8 switchFlagIsSet = (Flags_GetSwitch(globalCtx, switchFlag)) ? true : false;

    if (pthis->unk_176 ^ switchFlagIsSet && switchFlagIsSet ^ (((pthis->dyna.actor.params >> 15) & 1) ? true : false)) {
        if (pthis->demoEffectTimer <= 0) {
            ObjTimeblock_SpawnDemoEffect(pthis, globalCtx);
            pthis->demoEffectTimer = 160;
        }
        pthis->demoEffectFirstPartTimer = 12;
    }

    func_80BA06AC(pthis, globalCtx);

    if (pthis->isVisible && pthis->demoEffectTimer <= 0) {
        ObjTimeblock_SetupAltBehaviorVisible(pthis);
    }
}

void ObjTimeblock_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjTimeblock* pthis = (ObjTimeblock*)thisx;

    pthis->actionFunc(pthis, globalCtx);

    if (pthis->demoEffectTimer > 0) {
        pthis->demoEffectTimer--;
    }

    if (pthis->isVisible) {
        func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    } else {
        func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, pthis->dyna.bgId);
    }
}

void ObjTimeblock_Draw(Actor* thisx, GlobalContext* globalCtx) {
    if (((ObjTimeblock*)thisx)->isVisible) {
        Color_RGB8* primColor = &sPrimColors[thisx->home.rot.z & 7];

        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_timeblock.c", 762);

        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_timeblock.c", 766),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, primColor->r, primColor->g, primColor->b, 255);
        gSPDisplayList(POLY_OPA_DISP++, gSongOfTimeBlockDL);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_timeblock.c", 772);
    }
}

void ObjTimeblock_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    Obj_Timeblock_InitVars = {
        ACTOR_OBJ_TIMEBLOCK,
        ACTORCAT_ITEMACTION,
        FLAGS,
        OBJECT_TIMEBLOCK,
        sizeof(ObjTimeblock),
        (ActorFunc)ObjTimeblock_Init,
        (ActorFunc)ObjTimeblock_Destroy,
        (ActorFunc)ObjTimeblock_Update,
        (ActorFunc)ObjTimeblock_Draw,
        (ActorFunc)ObjTimeblock_Reset,
    };

}

#pragma once
#include "global.h"
#include "z64scene.h"
#include "z64actor.h"
#include "z64game.h"
#include "view.h"
#include "z64camera.h"
#include "z64light.h"
#include "z64render.h"
#include "audiomgr.h"
#include "z64message.h"
#include "interface.h"
#include "kaleido.h"
#include "z64environment.h"
#include "z64object.h"
#include "z64transition.h"
#include "z64bgcheck.h"
#include "z64sram.h"

struct FrameAdvanceContext {
    /* 0x00 */ s32 enabled;
    /* 0x04 */ s32 timer;
}; // size = 0x8

typedef struct {
    union {
        TransitionFade fade;
        TransitionCircle circle;
        TransitionTriforce triforce;
        TransitionWipe wipe;
        char data[0x228];
    };
    /* 0x228 */ s32   transitionType;
    /* 0x22C */ void* (*init)(void* transition);
    /* 0x230 */ void  (*destroy)(void* transition);
    /* 0x234 */ void  (*update)(void* transition, s32 updateRate);
    /* 0x238 */ void  (*draw)(void* transition, Gfx** gfxP);
    /* 0x23C */ void  (*start)(void* transition);
    /* 0x240 */ void  (*setType)(void* transition, s32 type);
    /* 0x244 */ void  (*setColor)(void* transition, u32 color);
    /* 0x248 */ void  (*setEnvColor)(void* transition, u32 color);
    /* 0x24C */ s32   (*isDone)(void* transition);
} TransitionContext; // size = 0x250

// Global Context (dbg ram start: 80212020)
struct GlobalContext {
    /* 0x00000 */ GameState state;
    /* 0x000A4 */ s16 sceneNum;
    /* 0x000A6 */ u8 sceneConfig;
    /* 0x000A7 */ char unk_A7[0x9];
    /* 0x000B0 */ void* sceneSegment;
    /* 0x000B8 */ View view;
    /* 0x001E0 */ Camera mainCamera;
    /* 0x0034C */ Camera subCameras[NUM_CAMS - SUBCAM_FIRST];
    /* 0x00790 */ Camera* cameraPtrs[NUM_CAMS];
    /* 0x007A0 */ s16 activeCamera;
    /* 0x007A2 */ s16 nextCamera;
    /* 0x007A4 */ SequenceContext sequenceCtx;
    /* 0x007A8 */ LightContext lightCtx;
    /* 0x007B8 */ FrameAdvanceContext frameAdvCtx;
    /* 0x007C0 */ CollisionContext colCtx;
    /* 0x01C24 */ ActorContext actorCtx;
    /* 0x01D64 */ CutsceneContext csCtx; // "demo_play"
    /* 0x01DB4 */ SoundSource soundSources[16];
    /* 0x01F74 */ SramContext sramCtx;
    /* 0x01F78 */ SkyboxContext skyboxCtx;
    /* 0x020D8 */ MessageContext msgCtx;         // "message"
    /* 0x104F0 */ InterfaceContext interfaceCtx; // "parameter"
    /* 0x10760 */ PauseContext pauseCtx;
    /* 0x10A20 */ GameOverContext gameOverCtx;
    /* 0x10A24 */ EnvironmentContext envCtx;
    /* 0x10B20 */ AnimationContext animationCtx;
    /* 0x117A4 */ ObjectContext objectCtx;
    /* 0x11CBC */ RoomContext roomCtx;
    /* 0x11D34 */ TransitionActorContext transiActorCtx;
    /* 0x11D3C */ void (*playerInit)(struct Player* player, struct GlobalContext* globalCtx, FlexSkeletonHeader* skelHeader);
    /* 0x11D40 */ void (*playerUpdate)(struct Player* player, struct GlobalContext* globalCtx, Input* input);
    /* 0x11D44 */ s32 (*isPlayerDroppingFish)(struct GlobalContext* globalCtx);
    /* 0x11D48 */ s32 (*startPlayerFishing)(struct GlobalContext* globalCtx);
    /* 0x11D4C */ s32 (*grabPlayer)(struct GlobalContext* globalCtx, struct Player* player);
    /* 0x11D50 */ s32 (*startPlayerCutscene)(struct GlobalContext* globalCtx, Actor* actor, s32 mode);
    /* 0x11D54 */ void (*func_11D54)(struct Player* player, struct GlobalContext* globalCtx);
    /* 0x11D58 */ s32 (*damagePlayer)(struct GlobalContext* globalCtx, s32 damage);
    /* 0x11D5C */ void (*talkWithPlayer)(struct GlobalContext* globalCtx, Actor* actor);
    /* 0x11D60 */ MtxF viewProjectionMtxF;
    /* 0x11DA0 */ MtxF billboardMtxF;
    /* 0x11DE0 */ Mtx* billboardMtx;
    /* 0x11DE4 */ u32 gameplayFrames;
    /* 0x11DE8 */ u8 linkAgeOnLoad;
    /* 0x11DE9 */ u8 unk_11DE9;
    /* 0x11DEA */ u8 curSpawn;
    /* 0x11DEB */ u8 numSetupActors;
    /* 0x11DEC */ u8 numRooms;
    /* 0x11DF0 */ RomFile* roomList;
    /* 0x11DF4 */ ActorEntry* linkActorEntry;
    /* 0x11DF8 */ ActorEntry* setupActorList;
    /* 0x11DFC */ UNK_PTR unk_11DFC;
    /* 0x11E00 */ EntranceEntry* setupEntranceList;
    /* 0x11E04 */ s16* setupExitList;
    /* 0x11E08 */ Path* setupPathList;
    /* 0x11E0C */ ElfMessage* cUpElfMsgs;
    /* 0x11E10 */ void* specialEffects;
    /* 0x11E14 */ u8 skyboxId;
    /* 0x11E15 */ s8 sceneLoadFlag; // "fade_direction"
    /* 0x11E16 */ s16 unk_11E16;
    /* 0x11E18 */ s16 unk_11E18;
    /* 0x11E1A */ s16 nextEntranceIndex;
    /* 0x11E1C */ char unk_11E1C[0x40];
    /* 0x11E5C */ s8 shootingGalleryStatus;
    /* 0x11E5D */ s8 bombchuBowlingStatus; // "bombchu_game_flag"
    /* 0x11E5E */ u8 fadeTransition;
    /* 0x11E60 */ CollisionCheckContext colChkCtx;
    /* 0x120FC */ u16 envFlags[20];
    /* 0x12124 */ PreRender pauseBgPreRender;
    /* 0x12174 */ char unk_12174[0x53];
    /* 0x121C7 */ s8 unk_121C7;
    /* 0x121C8 */ TransitionContext transitionCtx;
    /* 0x12418 */ char unk_12418[0x3];
    /* 0x1241B */ u8 transitionMode; // "fbdemo_wipe_modem"
    /* 0x1241C */ TransitionFade transitionFade;
    /* 0x12428 */ char unk_12428[0x3];
    /* 0x1242B */ u8 unk_1242B;
    /* 0x1242C */ SceneTableEntry* loadedScene;
    /* 0x12430 */ char unk_12430[0xE8];
}; // size = 0x12518

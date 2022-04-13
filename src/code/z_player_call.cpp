#define INTERNAL_SRC_CODE_Z_PLAYER_CALL_C
#include "global.h"
#include "z64global.h"
#include "z64actor.h"
#include "z64player.h"
#include "def/z_kaleido_manager.h"
#include "def/z_kaleido_scope_call.h"
#include "def/z_player_call.h"

#define FLAGS (ACTOR_FLAG_VISIBLE | ACTOR_FLAG_2 | ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25 | ACTOR_FLAG_26)

void (*sPlayerCallInitFunc)(Actor* thisx, GlobalContext* globalCtx);
void (*sPlayerCallDestroyFunc)(Actor* thisx, GlobalContext* globalCtx);
void (*sPlayerCallUpdateFunc)(Actor* thisx, GlobalContext* globalCtx);
void (*sPlayerCallDrawFunc)(Actor* thisx, GlobalContext* globalCtx);

void PlayerCall_Init(Actor* thisx, GlobalContext* globalCtx);
void PlayerCall_Reset(Actor* thisx, GlobalContext* globalCtx);
void PlayerCall_Destroy(Actor* thisx, GlobalContext* globalCtx);
void PlayerCall_Update(Actor* thisx, GlobalContext* globalCtx);
void PlayerCall_Draw(Actor* thisx, GlobalContext* globalCtx);

void Player_Init(Actor* thisx, GlobalContext* globalCtx);
void Player_Destroy(Actor* thisx, GlobalContext* globalCtx);
void Player_Update(Actor* thisx, GlobalContext* globalCtx);
void Player_Draw(Actor* thisx, GlobalContext* globalCtx);

    /* TODO FIX const*/ ActorInit Player_InitVars = {
    ACTOR_PLAYER, ACTORCAT_PLAYER, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(Player), (ActorFunc)PlayerCall_Init, (ActorFunc)PlayerCall_Destroy, (ActorFunc)PlayerCall_Update, (ActorFunc)PlayerCall_Draw, (ActorFunc)PlayerCall_Reset,
};

void PlayerCall_InitFuncPtrs(void)
{
	sPlayerCallInitFunc = Player_Init;
	sPlayerCallDestroyFunc = Player_Destroy;
	sPlayerCallUpdateFunc = Player_Update;
	sPlayerCallDrawFunc = Player_Draw;
}

void PlayerCall_Init(Actor* thisx, GlobalContext* globalCtx)
{
	KaleidoScopeCall_LoadPlayer();
	PlayerCall_InitFuncPtrs();
	sPlayerCallInitFunc(thisx, globalCtx);
}

void PlayerCall_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
	KaleidoScopeCall_LoadPlayer();
	sPlayerCallDestroyFunc(thisx, globalCtx);
}

void PlayerCall_Update(Actor* thisx, GlobalContext* globalCtx)
{
	KaleidoScopeCall_LoadPlayer();
	sPlayerCallUpdateFunc(thisx, globalCtx);
}

void PlayerCall_Draw(Actor* thisx, GlobalContext* globalCtx)
{
	KaleidoScopeCall_LoadPlayer();
	sPlayerCallDrawFunc(thisx, globalCtx);
}

void PlayerCall_Reset(Actor* thisx, GlobalContext* globalCtx)
{
	Player_InitVars = {
	    ACTOR_PLAYER, ACTORCAT_PLAYER, FLAGS, OBJECT_GAMEPLAY_KEEP, ACTOR_FACTORY(Player), (ActorFunc)PlayerCall_Init, (ActorFunc)PlayerCall_Destroy, (ActorFunc)PlayerCall_Update, (ActorFunc)PlayerCall_Draw, (ActorFunc)PlayerCall_Reset,
	};
}
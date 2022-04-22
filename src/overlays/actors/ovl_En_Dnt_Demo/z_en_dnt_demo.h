#pragma once
#define Z_EN_DNT_DEMO_H

#include "global.h"
#include "ultra64.h"

struct EnDntDemo;

typedef void (*EnDntDemoActionFunc)(struct EnDntDemo*, GlobalContext*);

enum EnDntDemoResults
{
	/* 0 */ DNT_LIKE,
	/* 1 */ DNT_HATE,
	/* 2 */ DNT_LOVE
};
struct EnDntDemo
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnDntDemoActionFunc actionFunc;
	/* 0x0150 */ Timer judgeTimer;
	/* 0x0152 */ Timer unkTimer1;
	/* 0x0154 */ Timer unkTimer2;
	/* 0x0156 */ Timer debugArrowTimer;
	/* 0x0158 */ s16 leaderSignal;
	/* 0x015A */ s16 action;
	/* 0x015C */ s16 prize;
	/* 0x015E */ s16 subCamera;
	/* 0x0160 */ Vec3f scrubPos[9];
	/* 0x01CC */ Vec3f leaderPos;
	/* 0x01D8 */ struct EnDntNomal* scrubs[9];
	/* 0x01FC */ struct EnDntJiji* leader;
};

enum EnDntSignal
{
	/* 0 */ DNT_SIGNAL_NONE,
	/* 1 */ DNT_SIGNAL_LOOK,
	/* 2 */ DNT_SIGNAL_CELEBRATE,
	/* 3 */ DNT_SIGNAL_DANCE,
	/* 4 */ DNT_SIGNAL_HIDE,
	/* 5 */ DNT_SIGNAL_RETURN,
	/* 6 */ DNT_SIGNAL_UNUSED
};

enum EnDntLeaderAction
{
	/* 0 */ DNT_LEADER_ACTION_NONE,
	/* 1 */ DNT_LEADER_ACTION_UP,
	/* 2 */ DNT_LEADER_ACTION_UNUSED,
	/* 3 */ DNT_LEADER_ACTION_ATTACK
};

enum EnDntLeaderSignal
{
	/* 0 */ DNT_LEADER_SIGNAL_NONE,
	/* 1 */ DNT_LEADER_SIGNAL_UP,
	/* 2 */ DNT_LEADER_SIGNAL_BURROW,
	/* 3 */ DNT_LEADER_SIGNAL_RETURN
};

enum EnDntPrize
{
	/* 0 */ DNT_PRIZE_NONE,
	/* 1 */ DNT_PRIZE_NUTS,
	/* 2 */ DNT_PRIZE_STICK
};

enum EnDntAction
{
	/* 0 */ DNT_ACTION_NONE,
	/* 1 */ DNT_ACTION_DANCE,
	/* 2 */ DNT_ACTION_ATTACK,
	/* 3 */ DNT_ACTION_LOW_RUPEES,
	/* 4 */ DNT_ACTION_HIGH_RUPEES,
	/* 5 */ DNT_ACTION_PRIZE
};

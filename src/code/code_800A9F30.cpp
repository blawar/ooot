#define INTERNAL_SRC_CODE_CODE_800A9F30_C
#include "global.h"
#include "padmgr.h"
#include <math.h>
#include "port/player/players.h"
#include "def/code_800A9F30.h"
#include "def/code_800D2E30.h"
#include "def/padmgr.h"

RumbleStruct g_Rumble;

void Rumble_Init(PadMgr* a, s32 b)
{
	Rumble_Update(&g_Rumble);
	PadMgr_RumbleSet(a, g_Rumble.rumbleOn);
}

// Used for bosses and fishing
// distance to player (unused), strength, time, decay
void Rumble_Shake2(f32 playerDistance, u8 baseStrength, u8 length, u8 decay)
{
	s32 distance_decay; // By how much should the rumble effect be lowered, based on the distance
	s32 strength;

	if(1000000.0f < playerDistance)
	{
		distance_decay = 1000;
	}
	else
	{
		distance_decay = sqrtf(playerDistance);
	}

	if((distance_decay < 1000) && (baseStrength != 0) && (decay != 0))
	{
		strength = baseStrength - (distance_decay * 255) / 1000;

		if(strength > 0)
		{
			oot::player(0).SendMotorEvent(length, strength, decay);

			g_Rumble.strength = strength;
			g_Rumble.length = length;
			g_Rumble.decay = decay;
		}
	}
}

// distance to player, strength, time, decay?
void Rumble_Shake(f32 playerDistance, u8 baseStrength, u8 length, u8 decay)
{
	s32 distance_decay; // By how much should the rumble effect be lowered, based on the distance
	s32 strength;
	s32 i;

	if(1000000.0f < playerDistance)
	{
		distance_decay = 1000;
	}
	else
	{
		distance_decay = sqrtf(playerDistance);
	}

	if(distance_decay < 1000 && baseStrength != 0 && decay != 0)
	{
		strength = baseStrength - (distance_decay * 255) / 1000;

		oot::player(0).SendMotorEvent(length, strength, decay);

		for(i = 0; i < 0x40; i++)
		{
			if(g_Rumble.strengthList[i] == 0)
			{
				if(strength > 0)
				{
					g_Rumble.strengthList[i] = strength;
					g_Rumble.lengthList[i] = length;
					g_Rumble.decayList[i] = decay;
				}
				break;
			}
		}
	}
}

void Rumble_Reset(void)
{		   // called on GameState_Init
#ifdef N64_VERSION // Don't clear our callback function
	bzero(&g_Rumble, sizeof(UnkRumbleStruct));
#endif

	g_Rumble.state = 2;
	g_Rumble.reset = 1;

	gPadMgr.retraceCallback = Rumble_Init;
	gPadMgr.retraceCallbackValue = 0;

	if(1)
	{
	}
}

void Rumble_Destroy(void)
{ // called on GameState_Destroy
	PadMgr* padmgr = &gPadMgr;

	if((padmgr->retraceCallback == Rumble_Init) && (padmgr->retraceCallbackValue == 0))
	{
		padmgr->retraceCallback = NULL;
		padmgr->retraceCallbackValue = 0;
	}

#ifdef N64_VERSION
	bzero(&g_Rumble, sizeof(UnkRumbleStruct));
#endif
}

u32 Rumble_IsEnabled(void)
{
	return gPadMgr.pakType[0] == 1;
}

void Rumble_Stop(void)
{ // called on Environment_Init and game over
	g_Rumble.state = 2;
}

void Rumble_Clear(void)
{ // called per frame specific gSaveContext.gameMode
	g_Rumble.state = 0;
}

void Rumble_Enable(u32 a)
{
	g_Rumble.reset = !!a;
}
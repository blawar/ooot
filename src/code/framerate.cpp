#include "framerate.h"
#include "port/options.h"
#include "regs.h"
#include "z64.h"
#include "z64game.h"

#ifdef STATIC_FRAMERATE
float SET_FRAMERATE = STATIC_FRAMERATE;
float R_UPDATE_RATE = 1.0f;
u8 SKIP_GFX_FRAME_MASK = 0;
#else
double TICK_RATE = 20;
double UPDATE_SCALER = 1.0f;
double GAME_SPEED_RATIO = 1.0f;
double FRAMERATE_SCALER = (20.0f * GAME_SPEED_RATIO / TICK_RATE);
double FRAMERATE_SCALER_INV = TICK_RATE / (20.0f * GAME_SPEED_RATIO);
float SET_FRAMERATE = 20.0f;
float R_UPDATE_RATE = 1.0f;
float DEKU_NUT_SPAWN_SCALER = 1.0f;
bool INTERPOLATE_ANIM = false;
u8 SKIP_GFX_FRAME_MASK = 0;
#endif

static bool g_force20FPS = false;
static float g_force20FPSLast = 20.0f;

static FramerateProfile g_profile = PROFILE_BOOT;

static Framerate g_profileRates[] = {
    FRAMERATE_30FPS, // PROFILE_BOOT
    FRAMERATE_60FPS, // PROFILE_PAUSE
    FRAMERATE_20FPS, // PROFILE_GAMEPLAY
    FRAMERATE_60FPS, // PROFILE_UNKNOWN1
    FRAMERATE_60FPS, // PROFILE_UNKNOWN2
    FRAMERATE_60FPS, // PROFILE_SAMPLE
    FRAMERATE_60FPS, // PROFILE_OPENING
    FRAMERATE_60FPS, // PROFILE_SELECT
    FRAMERATE_60FPS, // PROFILE_TITLE
    FRAMERATE_60FPS, // PROFILE_FILE_CHOOSE
};

void framerate_init()
{
}

u32 framerate_get()
{
	switch(g_profileRates[g_profile])
	{
		case FRAMERATE_240FPS:
			return 240;
		case FRAMERATE_120FPS:
			return 120;
		case FRAMERATE_60FPS:
			return 60;
		case FRAMERATE_40FPS:
			return 40;
		case FRAMERATE_30FPS:
			return 30;
		case FRAMERATE_20FPS:
			return 20;
	}
	return 20; // ERROR?
}

static inline float framerate_divider()
{
	switch(g_profileRates[g_profile])
	{
		case FRAMERATE_240FPS:
			return 0.25f;
		case FRAMERATE_120FPS:
			return 0.5f;
		case FRAMERATE_60FPS:
			return 1.0f;
		case FRAMERATE_40FPS:
			return 2.0f;
		case FRAMERATE_30FPS:
			return 1.5f;
		case FRAMERATE_20FPS:
			return 3.0f;
		case FRAMERATE_15FPS:
			return 4.0f;
		case FRAMERATE_12FPS:
			return 5.0f;
		case FRAMERATE_10FPS:
			return 6.0f;
		case FRAMERATE_7FPS:
			return 7.0f;
	}
	return 20; // ERROR?
}

#define COUNTER_SCALER FRAMERATE_SCALER_INV

namespace oot
{
	float getMaxFramerate()
	{
		return SET_FRAMERATE;
	}

	void setMaxFramerate(float targetFramerate)
	{
		const float framerate = g_force20FPS ? 20.0f : targetFramerate;

		if(framerate == SET_FRAMERATE)
		{
			return;
		}
#ifndef STATIC_FRAMERATE
		switch((s32)framerate)
		{
			case 240:
				SET_FRAMERATE = 240.0f;
				TICK_RATE = 60.0f;
				UPDATE_SCALER = 4.0f;
				GAME_SPEED_RATIO = 1.0f / 4.0f;
				DEKU_NUT_SPAWN_SCALER = 1.2f;
				INTERPOLATE_ANIM = true;
				SKIP_GFX_FRAME_MASK = 0;

				g_profileRates[0] = FRAMERATE_7FPS;  // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_15FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_60FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_15FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_15FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_15FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_15FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_15FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_15FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_15FPS; // PROFILE_FILE_CHOOSE
				break;
			case 120:
				SET_FRAMERATE = 120.0f;
				TICK_RATE = 60.0f;
				UPDATE_SCALER = 2.0f;
				GAME_SPEED_RATIO = 0.5f;
				DEKU_NUT_SPAWN_SCALER = 1.2f;
				INTERPOLATE_ANIM = true;
				SKIP_GFX_FRAME_MASK = 0;

				g_profileRates[0] = FRAMERATE_15FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_30FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_60FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_30FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_30FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_30FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_30FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_30FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_30FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_30FPS; // PROFILE_FILE_CHOOSE
				break;
			case 60:
				SET_FRAMERATE = 60.0f;
				TICK_RATE = 60.0f;
				UPDATE_SCALER = 1.0f;
				GAME_SPEED_RATIO = 1.0f;
				DEKU_NUT_SPAWN_SCALER = 1.2f;
				INTERPOLATE_ANIM = true;
				SKIP_GFX_FRAME_MASK = 0;

				g_profileRates[0] = FRAMERATE_30FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_60FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_60FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_60FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_60FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_60FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_60FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_60FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_60FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_60FPS; // PROFILE_FILE_CHOOSE
				break;
			case 30:
				SET_FRAMERATE = 30.0f;
				TICK_RATE = 60.0f;
				UPDATE_SCALER = 1.0f;
				GAME_SPEED_RATIO = 1.0f;
				DEKU_NUT_SPAWN_SCALER = 1.2f;
				INTERPOLATE_ANIM = true;
				SKIP_GFX_FRAME_MASK = 1;

				g_profileRates[0] = FRAMERATE_30FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_60FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_60FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_60FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_60FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_60FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_60FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_60FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_60FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_60FPS; // PROFILE_FILE_CHOOSE
				break;
			case 25:
				SET_FRAMERATE = 25.0f;
				TICK_RATE = 20.0f;
				UPDATE_SCALER = 25.0f / 20.0f;
				GAME_SPEED_RATIO = 1.0f;
				DEKU_NUT_SPAWN_SCALER = 1.0f;
				INTERPOLATE_ANIM = false;
				SKIP_GFX_FRAME_MASK = 0;

				g_profileRates[0] = FRAMERATE_30FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_60FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_20FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_60FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_60FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_60FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_60FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_60FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_60FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_60FPS; // PROFILE_FILE_CHOOSE
				break;
			case 20:
			default:
				SET_FRAMERATE = 20.0f;
				TICK_RATE = 20.0f;
				UPDATE_SCALER = 1.0f;
				GAME_SPEED_RATIO = 1.0f;
				DEKU_NUT_SPAWN_SCALER = 1.0f;
				INTERPOLATE_ANIM = false;
				SKIP_GFX_FRAME_MASK = 0;

				g_profileRates[0] = FRAMERATE_30FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_60FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_20FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_60FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_60FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_60FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_60FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_60FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_60FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_60FPS; // PROFILE_FILE_CHOOSE
				break;
		}

		FRAMERATE_SCALER = (20.0f * GAME_SPEED_RATIO / TICK_RATE);
		FRAMERATE_SCALER_INV = TICK_RATE / (20.0f * GAME_SPEED_RATIO);
		R_UPDATE_RATE = framerate_divider();

		config().save();
#endif
	}
} // namespace oot

void framerate_set_profile(FramerateProfile profile)
{
	g_profile = profile;
	R_UPDATE_RATE = framerate_divider();
}

FramerateProfile framerate_get_profile()
{
	return g_profile;
}

float frameRateDivisor()
{
	return R_UPDATE_RATE;
}

float Round(float value)
{
	return roundf(value * 100) / 100.0f;
}

void force20FPS(bool force)
{
	if(force)
	{
		g_force20FPSLast = oot::getMaxFramerate();
	}
	g_force20FPS = force;
	oot::setMaxFramerate(g_force20FPSLast);
}

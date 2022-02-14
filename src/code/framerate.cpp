#include "z64.h"
#include "framerate.h"
#include "z64game.h"
#include "regs.h"

static FramerateProfile g_profile = PROFILE_BOOT;

#if FRAME_RATE == 20
static Framerate g_profileRates[] = {
FRAMERATE_30FPS, // PROFILE_BOOT
FRAMERATE_20FPS, // PROFILE_PAUSE
FRAMERATE_20FPS, // PROFILE_GAMEPLAY
FRAMERATE_60FPS, // PROFILE_UNKNOWN1
FRAMERATE_60FPS, // PROFILE_UNKNOWN2
FRAMERATE_60FPS, // PROFILE_SAMPLE
FRAMERATE_60FPS, // PROFILE_OPENING
FRAMERATE_60FPS, // PROFILE_SELECT
FRAMERATE_60FPS, // PROFILE_TITLE
FRAMERATE_60FPS, // PROFILE_FILE_CHOOSE
};
#else
static Framerate g_profileRates[] = {
FRAMERATE_30FPS, // PROFILE_BOOT
FRAMERATE_60FPS, // PROFILE_PAUSE
FRAMERATE_60FPS, // PROFILE_GAMEPLAY
FRAMERATE_60FPS, // PROFILE_UNKNOWN1
FRAMERATE_60FPS, // PROFILE_UNKNOWN2
FRAMERATE_60FPS, // PROFILE_SAMPLE
FRAMERATE_60FPS, // PROFILE_OPENING
FRAMERATE_60FPS, // PROFILE_SELECT
FRAMERATE_60FPS, // PROFILE_TITLE
FRAMERATE_60FPS, // PROFILE_FILE_CHOOSE
};
#endif

void framerate_init()
{
}

u32 framerate_get()
{
	switch(g_profileRates[g_profile])
	{
#ifdef ENABLE_HIGH_FRAMERATE
		case FRAMERATE_240FPS:
			return 240;
		case FRAMERATE_120FPS:
			return 120;
		case FRAMERATE_40FPS:
			return 40;
#endif
		case FRAMERATE_60FPS:
			return 60;
		case FRAMERATE_30FPS:
			return 30;
		case FRAMERATE_20FPS:
			return 20;
	}
	return 20; // ERROR?
}

void framerate_set_profile(FramerateProfile profile)
{
	u64 i = 1 * REG_PER_GROUP + 30;
	auto x = &gGameInfo->data[i];
	auto& y = gGameInfo->data[i];
	g_profile = profile;
	R_UPDATE_RATE = g_profileRates[g_profile];
}

FramerateProfile framerate_get_profile()
{
	return g_profile;
}

u64 frameRateDivisor()
{
	return R_UPDATE_RATE;
}
#include "framerate.h"
#include "port/options.h"
#include "regs.h"
#include "z64.h"
#include "z64game.h"

#ifdef STATIC_FRAMERATE
float SET_FRAMERATE = STATIC_FRAMERATE;
float R_UPDATE_RATE = 1.0f;
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
#endif

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

	void setMaxFramerate(float framerate)
	{
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
				UPDATE_SCALER = 0.5f;
				GAME_SPEED_RATIO = 2.0f;
				DEKU_NUT_SPAWN_SCALER = 1.2f;
				INTERPOLATE_ANIM = true;

				g_profileRates[0] = FRAMERATE_60FPS; // PROFILE_BOOT
				g_profileRates[1] = FRAMERATE_120FPS; // PROFILE_PAUSE
				g_profileRates[2] = FRAMERATE_60FPS; // PROFILE_GAMEPLAY
				g_profileRates[3] = FRAMERATE_120FPS; // PROFILE_UNKNOWN1
				g_profileRates[4] = FRAMERATE_120FPS; // PROFILE_UNKNOWN2
				g_profileRates[5] = FRAMERATE_120FPS; // PROFILE_SAMPLE
				g_profileRates[6] = FRAMERATE_120FPS; // PROFILE_OPENING
				g_profileRates[7] = FRAMERATE_120FPS; // PROFILE_SELECT
				g_profileRates[8] = FRAMERATE_120FPS; // PROFILE_TITLE
				g_profileRates[9] = FRAMERATE_120FPS; // PROFILE_FILE_CHOOSE
				break;
			case 25:
				SET_FRAMERATE = 25.0f;
				TICK_RATE = 20.0f;
				UPDATE_SCALER = 25.0f / 20.0f;
				GAME_SPEED_RATIO = 1.0f;
				DEKU_NUT_SPAWN_SCALER = 1.0f;
				INTERPOLATE_ANIM = false;

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

Timer::Timer() : m_counter(0), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF), m_counterScaler(0)
{
	m_counterScaler = COUNTER_SCALER;
}

Timer::Timer(const Timer& t)
{
	m_counter = t.m_counter;
	m_counterInt = t.m_counterInt;
	m_min = t.m_min;
	m_max = t.m_max;
	m_counterScaler = t.m_counterScaler;
}

Timer::Timer(float n) : m_counter(0), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF), m_counterScaler(0)
{
	m_counterScaler = COUNTER_SCALER;
	preUpdate();
	m_counterInt = n * m_counterScaler;
	update();
}

Timer::Timer(float n, s64 min, s64 max) : m_counter(0), m_counterInt(0), m_min(min), m_max(max), m_counterScaler(0)
{
	m_counterScaler = COUNTER_SCALER;
	preUpdate();
	m_counterInt = n * m_counterScaler;
	update();
}

Timer::Timer(s64 min, s64 max) : m_counter(0), m_counterInt(0), m_min(min), m_max(max)
{
	m_counterScaler = COUNTER_SCALER;
}

void Timer::setRange(s64 min, s64 max)
{
	m_min = min;
	m_max = max;
}

float Timer::frac() const
{
	float integer;
	return modf(m_counter, &integer);
	// return (m_counterInt % (s64)FRAMERATE_SCALER_INV) / (float)FRAMERATE_SCALER_INV;
}

Timer Timer::invalid()
{
	Timer r(0);
	r--;
	return r;
}

void Timer::preUpdate()
{
	if(m_counterScaler != COUNTER_SCALER)
	{
		m_counterInt = m_counterInt * COUNTER_SCALER / m_counterScaler;
		m_counterScaler = COUNTER_SCALER;
	}
}

void Timer::update()
{
	if(m_counterInt > m_max * m_counterScaler)
	{
		m_counterInt = (m_min * m_counterScaler) + (m_counterInt - (m_max * m_counterScaler + 1));

		if(m_counterInt > m_max * m_counterScaler)
		{
			m_counterInt = 0;
		}
	}

	if(m_counterInt < m_min * m_counterScaler)
	{
		m_counterInt = (m_max * m_counterScaler) + (m_counterInt - (m_min * m_counterScaler - 1));

		if(m_counterInt < m_min * m_counterScaler)
		{
			m_counterInt = 0;
		}
	}

	m_counter = (float)m_counterInt / m_counterScaler;
}

float Timer::abs() const
{
	float v = toFloat();

	if(v < 0.0f)
	{
		return -v;
	}

	return v;
}

void Timer::clamp(float min, float max)
{
	*this = CLAMP(toFloat(), min, max);
}

Timer& Timer::operator++() // pre
{
	preUpdate();
	m_counterInt++;
	update();
	return *this;
}

Timer Timer::operator++(int) // post
{
	auto r = *this;
	preUpdate();
	m_counterInt++;
	update();
	return r;
}

Timer& Timer::operator--() // pre
{
	preUpdate();
	m_counterInt--;
	update();
	return *this;
}

Timer Timer::operator--(int) // post
{
	auto r = *this;
	preUpdate();
	m_counterInt--;
	update();
	return r;
}

Timer& Timer::dec()
{
	if(m_counter)
	{
		preUpdate();
		m_counterInt--;
		update();
	}
	return *this;
}

bool Timer::isWhole() const
{
	return (m_counterInt % (s32)m_counterScaler) == 0;
}

s32 Timer::whole() const
{
	return (s32)m_counter;
	// return m_counterInt * 20 / TICK_RATE;
}

Timer::operator float() const
{
	return m_counter;
}

Timer& Timer::operator+=(const Timer f)
{
	s64 step = f.m_counterInt / m_counterScaler;

	preUpdate();
	m_counterInt += step;
	update();
	return *this;
}

Timer& Timer::operator-=(const Timer f)
{
	s64 step = f.m_counterInt / m_counterScaler;

	preUpdate();
	m_counterInt -= step;
	update();
	return *this;
}

Timer& Timer::operator*=(float f)
{
	*this = (float)*this * f;
	return *this;
}

Timer& Timer::operator/=(float f)
{
	*this = (float)*this / f;
	return *this;
}

Timer& Timer::operator&=(u64 n)
{
	//*this = m_counterInt & (n * m_counterScaler);
	preUpdate();
	*this = (whole() & n); // + frac();
	update();
	return *this;
}

Timer& Timer::operator|=(u64 n)
{
	//*this = m_counterInt | (n * m_counterScaler);
	preUpdate();
	*this = whole() | n;
	update();
	return *this;
}

Timer& Timer::operator^=(u64 n)
{
	//*this = m_counterInt ^ (n * m_counterScaler);
	preUpdate();
	*this = whole() ^ n;
	update();
	return *this;
}

s32 Timer::operator%(s32 n) const
{
	return whole() % n;
}

Timer Timer::operator&(long n) const
{
	Timer t = *this;
	t &= n;
	return t;
}

Timer Timer::operator|(long n) const
{
	Timer t = *this;
	t |= n;
	return t;
}

Timer Timer::operator^(long n) const
{
	Timer t = *this;
	t ^= n;
	return t;
}

s32 Timer::operator<<(long n)
{
	return whole() << n;
}

s32 Timer::operator>>(long n)
{
	return whole() >> n;
}

Step::Step() : m_value(0)
{
}

Step::Step(const Step& t)
{
	m_value = t.m_value;
}

Step::Step(float n)
{
	// m_value = n; // * FRAMERATE_SCALER;
	m_value = n / COUNTER_SCALER;
}

Step::Step(const Rotation& r)
{
	m_value = (s16)r;
}

float Step::value() const
{
	return m_value;
}

FStep::FStep() : Step()
{
}

FStep::FStep(const Step& t)
{
	m_value = t.value();
}

FStep::FStep(float n)
{
	m_value = n;
}

FStep::FStep(const Rotation& r)
{
	m_value = (s16)r;
}

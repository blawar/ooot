#include "framerate.h"
#include "regs.h"
#include "z64.h"
#include "z64game.h"

#define GAME_SPEED_RATIO2 4

#define COUNTER_STEP (s32)(20 * GAME_SPEED_RATIO) / TICK_RATE
#define COUNTER_SCALER TICK_RATE / (s32)(20 * GAME_SPEED_RATIO)

float R_UPDATE_RATE = 1.0f;
static FramerateProfile g_profile = PROFILE_BOOT;

#define REAL_FRAME_RATE 30

#if TICK_RATE == 20
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
#elif TICK_RATE == 30
static Framerate g_profileRates[] = {
    FRAMERATE_30FPS, // PROFILE_BOOT
    FRAMERATE_60FPS, // PROFILE_PAUSE
    FRAMERATE_30FPS, // PROFILE_GAMEPLAY
    FRAMERATE_60FPS, // PROFILE_UNKNOWN1
    FRAMERATE_60FPS, // PROFILE_UNKNOWN2
    FRAMERATE_60FPS, // PROFILE_SAMPLE
    FRAMERATE_60FPS, // PROFILE_OPENING
    FRAMERATE_60FPS, // PROFILE_SELECT
    FRAMERATE_60FPS, // PROFILE_TITLE
    FRAMERATE_60FPS, // PROFILE_FILE_CHOOSE
};
#elif TICK_RATE == 40
static Framerate g_profileRates[] = {
    FRAMERATE_30FPS, // PROFILE_BOOT
    FRAMERATE_60FPS, // PROFILE_PAUSE
    FRAMERATE_40FPS, // PROFILE_GAMEPLAY
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
	}
	return 20; // ERROR?
}

void framerate_set_profile(FramerateProfile profile)
{
	u64 i = 1 * REG_PER_GROUP + 30;
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

Timer::Timer() : m_counter(0), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF)
{
}

Timer::Timer(const Timer& t)
{
	m_counter = t.m_counter;
	m_counterInt = t.m_counterInt;
	m_min = t.m_min;
	m_max = t.m_max;
}


Timer::Timer(float n) : m_counter(n), m_counterInt(n * COUNTER_SCALER), m_min(-0x8000), m_max(0x7FFF)
{
	if(n == 0xFFFF)
	{
		bool error = true;
	}
}

Timer::Timer(float n, s64 min, s64 max) : m_counter(n), m_counterInt(n * COUNTER_SCALER), m_min(min), m_max(max)
{
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
	//return (m_counterInt % (s64)FRAMERATE_SCALER_INV) / (float)FRAMERATE_SCALER_INV;
}

Timer Timer::invalid()
{
	Timer r(0);
	r--;
	return r;
}

void Timer::update()
{
	while(m_counterInt > m_max * COUNTER_SCALER)
	{
		m_counterInt = (m_min * COUNTER_SCALER) + (m_counterInt - (m_max * COUNTER_SCALER + 1));
	}

	while(m_counterInt < m_min * COUNTER_SCALER)
	{
		m_counterInt = (m_max * COUNTER_SCALER) + (m_counterInt - (m_min * COUNTER_SCALER - 1));
	}

#if TICK_RATE == 30
	if((m_counterInt - 2) % 3 == 0)
	{
		m_counter = (s32)(m_counterInt * COUNTER_STEP);
	}
	else
	{
		m_counter = (float)m_counterInt * COUNTER_STEP;
	}
#else
	m_counter = (float)m_counterInt * COUNTER_STEP;
#endif
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
	m_counterInt++;
	update();
	return *this;
}

Timer Timer::operator++(int) // post
{
	auto r = *this;
	m_counterInt++;
	update();
	return r;
}

Timer& Timer::operator--() // pre
{
	m_counterInt--;
	update();
	return *this;
}

Timer Timer::operator--(int) // post
{
	auto r = *this;
	m_counterInt--;
	update();
	return r;
}

Timer& Timer::dec()
{
	if(m_counter)
	{
		m_counterInt--;
		update();
	}
	return *this;
}

bool Timer::isWhole() const
{
#if TICK_RATE == 30
	return fabs(ceilf(m_counter) - m_counter) < 0.001f;
#else
	return (m_counterInt % COUNTER_SCALER) == 0;
#endif
}

s32 Timer::whole() const
{
	return (s32)m_counter;
	//return m_counterInt * 20 / TICK_RATE;
}

Timer::operator float() const
{
	return m_counter;
}

Timer& Timer::operator+=(const Timer f)
{
	s64 step = f.m_counterInt * COUNTER_STEP;

	m_counterInt += step;
	update();
	return *this;
}

Timer& Timer::operator-=(const Timer f)
{
	s64 step = f.m_counterInt * COUNTER_STEP;

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
	//*this = m_counterInt & (n * COUNTER_SCALER);
	*this = (whole() & n);// + frac();
	update();
	return *this;
}

Timer& Timer::operator|=(u64 n)
{
	//*this = m_counterInt | (n * COUNTER_SCALER);
	*this = whole() | n;
	update();
	return *this;
}

Timer& Timer::operator^=(u64 n)
{
	//*this = m_counterInt ^ (n * COUNTER_SCALER);
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
	//m_value = n; // * FRAMERATE_SCALER;
	m_value = n * COUNTER_STEP;
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

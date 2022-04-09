#include "framerate.h"
#include "regs.h"
#include "z64.h"
#include "z64game.h"

#define COUNTER_STEP 20 / FRAME_RATE
#define COUNTER_SCALER FRAME_RATE / 20

static FramerateProfile g_profile = PROFILE_BOOT;

#if FRAME_RATE == 20
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

Timer::Timer() : m_counter(0), m_counterInt(0)
{
}

Timer::Timer(const Timer& t)
{
	m_counter = t.m_counter;
	m_counterInt = t.m_counterInt;
}

Timer::Timer(float n) : m_counter(n), m_counterInt(n * COUNTER_SCALER)
{
	if(n == 0xFFFF)
	{
		bool error = true;
	}
	/*if(m_counterInt == 0)
	{
		if(n < 1.0f && n > 0.0f)
		{
			m_counterInt = 1;
			update();
		}
		else if(n > -1.0f && n < 0.0f)
		{
			m_counterInt = -1;
			update();
		}
	}*/
}

Timer Timer::invalid()
{
	Timer r(0);
	r--;
	return r;
}

void Timer::update()
{
	m_counter = (float)m_counterInt * COUNTER_STEP;
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
	return (m_counterInt % (COUNTER_SCALER)) == 0;
}

s32 Timer::whole() const
{
	return m_counterInt * 20 / FRAME_RATE;
}

Timer::operator float() const
{
	return m_counter;
}

Timer& Timer::operator+=(const Timer f)
{
	s64 step = f.m_counterInt * COUNTER_STEP;

	if(step == 0)
	{
		if(f.m_counterInt > 0)
		{
			step = 1;
		}
		else
		{
			step = -1;
		}
	}

	m_counterInt += step;
	update();
	return *this;
}

Timer& Timer::operator-=(const Timer f)
{
	s64 step = f.m_counterInt * COUNTER_STEP;

	if(step == 0)
	{
		if(f.m_counterInt > 0)
		{
			step = 1;
		}
		else
		{
			step = -1;
		}
	}

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
	*this = whole() & n;
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
	m_value = n; // * FRAMERATE_SCALER;
}

Step::Step(const Rotation& r)
{
	m_value = (s16)r;
}

float Step::value() const
{
	return m_value;
}

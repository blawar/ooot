#pragma once
#include <math.h>
#include "macros.h"
#include "ultra64/types.h"

#ifdef STATIC_FRAMERATE
#if STATIC_FRAMERATE == 240
#define TICK_RATE 60
#define UPDATE_SCALER 4
#define GAME_SPEED_RATIO 0.25f
#define INTERPOLATE_ANIM 1
#elif STATIC_FRAMERATE == 180
#define TICK_RATE 60
#define UPDATE_SCALER 3
#define GAME_SPEED_RATIO (1.0f / 3.0f)
#define INTERPOLATE_ANIM 1
#elif STATIC_FRAMERATE == 120
#define TICK_RATE 60
#define UPDATE_SCALER 2
#define GAME_SPEED_RATIO 0.5f
#define INTERPOLATE_ANIM 1
#elif STATIC_FRAMERATE == 60
#define TICK_RATE 60
#define UPDATE_SCALER 1
#define GAME_SPEED_RATIO 1
#define INTERPOLATE_ANIM 1
#elif STATIC_FRAMERATE == 40
#define TICK_RATE 40
#define UPDATE_SCALER 1
#define GAME_SPEED_RATIO 1
#define INTERPOLATE_ANIM 1
#elif STATIC_FRAMERATE == 30
#define TICK_RATE 60
#define UPDATE_SCALER 0.5f
#define GAME_SPEED_RATIO 2
#define INTERPOLATE_ANIM 0
#elif STATIC_FRAMERATE == 25
#define TICK_RATE 20
#define UPDATE_SCALER (25.0f / 20.0f)
#define GAME_SPEED_RATIO 1
#define INTERPOLATE_ANIM 0
#else
#define TICK_RATE 20
#define UPDATE_SCALER 1
#define GAME_SPEED_RATIO 1
#define INTERPOLATE_ANIM 0
#endif

#define FRAMERATE_SCALER (20.0f * GAME_SPEED_RATIO / (float)TICK_RATE)
#define FRAMERATE_SCALER_INV ((float)TICK_RATE / (20.0f * GAME_SPEED_RATIO))
#define DEKU_NUT_SPAWN_SCALER 1.2f

#else

extern double TICK_RATE;
extern double UPDATE_SCALER;
extern double GAME_SPEED_RATIO;
extern double FRAMERATE_SCALER;
extern double FRAMERATE_SCALER_INV;
extern float DEKU_NUT_SPAWN_SCALER;
extern bool INTERPOLATE_ANIM;

#endif

enum Framerate
{
	FRAMERATE_NONE = 0,
	FRAMERATE_240FPS = 2,
	FRAMERATE_120FPS = 5,
	FRAMERATE_60FPS = 10,
	FRAMERATE_40FPS = 15,
	FRAMERATE_30FPS = 20,
	FRAMERATE_20FPS = 30,
	FRAMERATE_15FPS = 40,
	FRAMERATE_12FPS = 50,
	FRAMERATE_10FPS = 60,
	FRAMERATE_7FPS = 7
};

//#define FRAMERATE_SCALER (20.0f * GAME_SPEED_RATIO / (float)TICK_RATE)
//#define FRAMERATE_SCALER_INV ((float)TICK_RATE / (20.0f * GAME_SPEED_RATIO))
#define FRAMERATE_ANIM_SCALER (R_UPDATE_RATE * 0.5f * GAME_SPEED_RATIO)
#define FRAMERATE_RATE_SCALER 1
#define FRAMERATE_MAX 60

#define FRAMERATE_RATE_SCALE(x) ((x / FRAMERATE_RATE_SCALER) < 1 ? 1 : (x / FRAMERATE_RATE_SCALER))
#define FRAMERATE_RATE_SCALED ((R_UPDATE_RATE / FRAMERATE_RATE_SCALER) < 1 ? 1 : (R_UPDATE_RATE / FRAMERATE_RATE_SCALER))
#define FRAME_TIME (1.0f / (float)TICK_RATE)

typedef enum
{
	PROFILE_BOOT = 0,   // 30FPS
	PROFILE_PAUSE,	    // 20FPS
	PROFILE_GAMEPLAY,   // 20FPS
	PROFILE_UNKNOWN1,   // 60FPS
	PROFILE_UNKNOWN2,   // 60FPS
	PROFILE_SAMPLE,	    // 60FPS
	PROFILE_OPENING,    // 60FPS
	PROFILE_SELECT,	    // 60FPS
	PROFILE_TITLE,	    // 60FPS
	PROFILE_FILE_CHOOSE // 60FPS
} FramerateProfile;

void framerate_init();
u32 framerate_get();
void framerate_set_profile(FramerateProfile profile);
FramerateProfile framerate_get_profile();
float frameRateDivisor();

class Timer : public f32
{
	public:
	enum class Type
	{
		U8 = 0xFF,
		S8 = 0X7F,
		U16 = 0xFFFF,
		S16 = 0x8000
	};

	Timer() : f32(), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
	}

	Timer(const Timer& t) : f32()
	{
		m_counter = t.m_counter;
		m_counterInt = t.m_counterInt;
		m_min = t.m_min;
		m_max = t.m_max;
		m_counterScaler = t.m_counterScaler;
	}

	Timer(float n) : f32(), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
		preUpdate();
		m_counterInt = n * m_counterScaler;
		update();
	}

	Timer(f32 n) : f32(), m_counterInt(0), m_min(-0x8000), m_max(0x7FFF), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
		preUpdate();
		m_counterInt = n.value() * m_counterScaler;
		update();
	}

	Timer(float n, s64 min, s64 max) : f32(), m_counterInt(0), m_min(min), m_max(max), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
		preUpdate();
		m_counterInt = n * m_counterScaler;
		update();
	}

	Timer(s64 min, s64 max) : f32(), m_counterInt(0), m_min(min), m_max(max)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
	}

	void setRange(s64 min, s64 max)
	{
		m_min = min;
		m_max = max;
	}

	float frac() const
	{
		return m_counter - (s32)m_counter;
		//float integer;
		//return modf(m_counter, &integer);
		// return (m_counterInt % (s64)FRAMERATE_SCALER_INV) / (float)FRAMERATE_SCALER_INV;
	}

	static Timer invalid()
	{
		Timer r(0);
		r--;
		return r;
	}

	float abs() const
	{
		float v = toFloat();

		if(v < 0.0f)
		{
			return -v;
		}

		return v;
	}

	void clamp(float min, float max)
	{
		*this = CLAMP(toFloat(), min, max);
	}

	Timer& operator++() // pre
	{
		preUpdate();
		m_counterInt++;
		update();
		return *this;
	}

	Timer operator++(int) // post
	{
		auto r = *this;
		preUpdate();
		m_counterInt++;
		update();
		return r;
	}

	Timer& operator--() // pre
	{
		preUpdate();
		m_counterInt--;
		update();
		return *this;
	}

	Timer operator--(int) // post
	{
		auto r = *this;
		preUpdate();
		m_counterInt--;
		update();
		return r;
	}

	Timer& dec()
	{
		if(m_counter)
		{
			preUpdate();
			m_counterInt--;
			update();
		}
		return *this;
	}

	bool isWhole() const
	{
		return (m_counterInt % (s32)m_counterScaler) == 0;
	}

	Timer& operator+=(const Timer& f)
	{
		s64 step = f.m_counterInt / m_counterScaler;

		preUpdate();
		m_counterInt += step;
		update();
		return *this;
	}

	Timer& operator-=(const Timer& f)
	{
		s64 step = f.m_counterInt / m_counterScaler;

		preUpdate();
		m_counterInt -= step;
		update();
		return *this;
	}

	Timer& operator*=(float f)
	{
		*this = value() * f;
		return *this;
	}

	Timer& operator/=(float f)
	{
		*this = value() / f;
		return *this;
	}

	Timer& operator&=(u64 n)
	{
		//*this = m_counterInt & (n * m_counterScaler);
		preUpdate();
		*this = (whole() & n); // + frac();
		update();
		return *this;
	}

	Timer& operator|=(u64 n)
	{
		//*this = m_counterInt | (n * m_counterScaler);
		preUpdate();
		*this = whole() | n;
		update();
		return *this;
	}

	Timer& operator^=(u64 n)
	{
		//*this = m_counterInt ^ (n * m_counterScaler);
		preUpdate();
		*this = whole() ^ n;
		update();
		return *this;
	}

	s32 operator%(s32 n) const
	{
		return whole() % n;
	}

	Timer operator&(long n) const
	{
		Timer t = *this;
		t &= n;
		return t;
	}

	Timer operator|(long n) const
	{
		Timer t = *this;
		t |= n;
		return t;
	}

	Timer operator^(long n) const
	{
		Timer t = *this;
		t ^= n;
		return t;
	}

	constexpr static float INVALID = -FRAMERATE_MAX / 20.0f;

	protected:
	void preUpdate()
	{
		if(m_counterScaler != FRAMERATE_SCALER_INV)
		{
			m_counterInt = m_counterInt * FRAMERATE_SCALER_INV / m_counterScaler;
			m_counterScaler = FRAMERATE_SCALER_INV;
		}
	}

	void update()
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

	float m_counterScaler;
	s64 m_counterInt;
	s64 m_min;
	s64 m_max;
};

class TimerU8 : public Timer
{
	public:
	TimerU8() : Timer(0, 0xFF)
	{
	}

	TimerU8(const Timer& t) : Timer(t)
	{
	}

	TimerU8(float n) : Timer(n, 0, 0xFF)
	{
	}

	TimerU8(f32 f) : Timer(f.value(), 0, 0xFF)
	{
	}
};

class TimerS8 : public Timer
{
	public:
	TimerS8() : Timer(-0x80, 0x7F)
	{
	}

	TimerS8(const Timer& t) : Timer(t)
	{
	}

	TimerS8(float n) : Timer(n, -0x80, 0x7F)
	{
	}

	TimerS8(f32 f) : Timer(f.value(), -0x80, 0x7F)
	{
	}
};

class TimerU16 : public Timer
{
	public:
	TimerU16() : Timer(0, 0xFFFF)
	{
	}

	TimerU16(const Timer& t) : Timer(t)
	{
	}

	TimerU16(float n) : Timer(n, 0, 0xFFFF)
	{
	}

	TimerU16(f32 f) : Timer(f.value(), 0, 0xFFFF)
	{
	}
};

#define FLOAT_STEP m_counterScaler
typedef f32 CounterF;
/*
class CounterF : public f32
{
	public:
	CounterF() : f32(), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
	}

	CounterF(const CounterF& t) : f32(t.m_counter), m_counterScaler(t.m_counterScaler)
	{
	}

	CounterF(float n) : f32(n), m_counterScaler(0)
	{
		m_counterScaler = FRAMERATE_SCALER_INV;
	}

	CounterF invalid()
	{
		CounterF r(0);
		r--;
		return r;
	}

	CounterF& operator++() // pre
	{
		m_counter += FLOAT_STEP;
		return *this;
	}

	CounterF operator++(int) // post
	{
		auto r = *this;
		m_counter += FLOAT_STEP;
		return r;
	}

	CounterF& operator--() // pre
	{
		m_counter -= FLOAT_STEP;
		return *this;
	}

	CounterF operator--(int) // post
	{
		auto r = *this;
		m_counter -= FLOAT_STEP;
		return r;
	}

	CounterF& dec()
	{
		if(m_counter >= FLOAT_STEP)
		{
			m_counter -= FLOAT_STEP;
		}
		return *this;
	}

	CounterF& operator+=(float f)
	{
		m_counter += f * m_counterScaler;
		return *this;
	}

	CounterF& operator-=(float f)
	{
		m_counter -= f * m_counterScaler;
		return *this;
	}

	CounterF& operator*=(float f)
	{
		*this = value() * f;
		return *this;
	}

	CounterF& operator/=(float f)
	{
		*this = (float)*this / f;
		return *this;
	}

	CounterF& operator&=(u64 n)
	{
		*this = (whole() & n); // + frac();
		return *this;
	}

	CounterF& operator|=(u64 n)
	{
		*this = whole() | n;
		return *this;
	}

	CounterF& operator^=(u64 n)
	{
		*this = whole() ^ n;
		return *this;
	}

	s32 operator%(s32 n) const
	{
		return whole() % n;
	}

	CounterF operator&(long n) const
	{
		CounterF t = *this;
		t &= n;
		return t;
	}

	CounterF operator|(long n) const
	{
		CounterF t = *this;
		t |= n;
		return t;
	}

	CounterF operator^(long n) const
	{
		CounterF t = *this;
		t ^= n;
		return t;
	}

	s32 operator<<(long n)
	{
		return whole() << n;
	}

	s32 operator>>(long n)
	{
		return whole() >> n;
	}

	float toFloat() const
	{
		return m_counter;
	}

	s16 toS16() const
	{
		return (s16)m_counter;
	}

	u16 toU16() const
	{
		return (u16)m_counter;
	}

	constexpr static float INVALID = -FRAMERATE_MAX / 20.0f;

	protected:
	float m_counterScaler;
};
*/

typedef TimerU16 Counter;
typedef Timer Rotation;
typedef Timer Position;
typedef Timer TimerS16;
typedef Timer TimerS32;
typedef Timer TimerU32;
typedef CounterF TimerF32;

class Step
{
	public:
	Step() : m_value(0)
	{
	}

	Step(const Step& t)
	{
		m_value = t.m_value;
	}

	Step(float n)
	{
		m_value = n / FRAMERATE_SCALER_INV;
	}

	Step(const f32& t)
	{
		m_value = t.value() / FRAMERATE_SCALER_INV;
	}

	Step(const Rotation& r)
	{
		m_value = (s16)r;
	}

	float value() const
	{
		return m_value;
	}

	protected:
	float m_value;
};

class FStep : public Step
{
	public:
	FStep() : Step()
	{
	}

	FStep(const Step& t)
	{
		m_value = t.value();
	}

	FStep(float n)
	{
		m_value = n;
	}

	FStep(const f32& t)
	{
		m_value = t.value();
	}

	FStep(const Rotation& r)
	{
		m_value = (s16)r;
	}
};

namespace oot
{
	void setMaxFramerate(float framerate);
	float getMaxFramerate();
} // namespace oot
#pragma once
#include <math.h>
#include "ultra64/types.h"

#if defined(ENABLE_240FPS)
#define FRAME_RATE 240
#define ENABLE_HIGH_FRAMERATE
#elif defined(ENABLE_120FPS)
#define FRAME_RATE 120
#define ENABLE_HIGH_FRAMERATE
#elif defined(ENABLE_60FPS)
#define FRAME_RATE 60
#elif defined(ENABLE_30FPS)
#define FRAME_RATE 30
#else
#define FRAME_RATE 20
#endif

#ifdef ENABLE_HIGH_FRAMERATE
typedef enum
{
	FRAMERATE_NONE = 0,
	FRAMERATE_240FPS = 1,
	FRAMERATE_120FPS = 2,
	FRAMERATE_60FPS = 4,
	FRAMERATE_40FPS = 6,
	FRAMERATE_30FPS = 8,
	FRAMERATE_20FPS = 12
} Framerate;

#define FRAMERATE_SCALER R_UPDATE_RATE / 12.0f
#define FRAMERATE_RATE_SCALER 4
#define FRAMERATE_MAX 240

#else
typedef enum
{
	FRAMERATE_NONE = 0,
	FRAMERATE_60FPS = 1,
	FRAMERATE_30FPS = 2,
	FRAMERATE_20FPS = 3
} Framerate;

#define FRAMERATE_SCALER (20.0f / (float)FRAME_RATE)
#define FRAMERATE_SCALER_INV ((float)FRAME_RATE / 20.0f)
#define FRAMERATE_ANIM_SCALER (R_UPDATE_RATE * 0.5f)
#define FRAMERATE_RATE_SCALER 1
#define FRAMERATE_MAX 60

#endif

#define FRAMERATE_RATE_SCALE(x) ((x / FRAMERATE_RATE_SCALER) < 1 ? 1 : (x / FRAMERATE_RATE_SCALER))
#define FRAMERATE_RATE_SCALED ((R_UPDATE_RATE / FRAMERATE_RATE_SCALER) < 1 ? 1 : (R_UPDATE_RATE / FRAMERATE_RATE_SCALER))
#define FRAME_TIME (1.0f / (float)FRAME_RATE)

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
u64 frameRateDivisor();

class Timer
{
	public:
	enum class Type
	{
		U8 = 0xFF,
		S8 = 0X7F,
		U16 = 0xFFFF,
		S16 = 0x8000
	};

	Timer();
	Timer(const Timer& t);
	Timer(float n);
	Timer(float n, s64 min, s64 max);
	Timer(s64 min, s64 max) : m_counter(0), m_counterInt(0), m_min(min), m_max(max)
	{
	}

	float frac() const;

	static Timer invalid();

	Timer& operator++();   // pre
	Timer operator++(int); // post
	Timer& operator--();   // pre
	Timer operator--(int); // post
	Timer& dec();
	bool isWhole() const;
	s32 whole() const;
	operator float() const;
	Timer& operator+=(const Timer f);
	Timer& operator-=(const Timer f);
	Timer& operator*=(float f);
	Timer& operator/=(float f);
	Timer& operator&=(u64 n);
	Timer& operator|=(u64 n);
	Timer& operator^=(u64 n);
	s32 operator%(s32 n) const;
	Timer operator&(long n) const;
	Timer operator|(long n) const;
	Timer operator^(long n) const;
	s32 operator<<(long n);
	s32 operator>>(long n);

	float toFloat() const
	{
		return m_counter;
	}

	float abs() const;

	s16 toS16() const
	{
		return (s16)m_counter;
	}

	u16 toU16() const
	{
		return (u16)m_counter;
	}

	void setRange(s64 min, s64 max);

	constexpr static float INVALID = -FRAMERATE_MAX / 20.0f;

	protected:
	void update();
	float m_counter;
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
};

typedef TimerU16 Counter;
typedef Timer Rotation;
typedef Timer Position;
typedef Timer TimerS16;
typedef Timer TimerS32;
typedef Timer TimerU32;

class Step
{
	public:
	Step();
	Step(const Step& t);
	Step(float n);
	Step(const Rotation& r);

	float value() const;

	protected:
	float m_value;
};

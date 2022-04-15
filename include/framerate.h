#pragma once
#include <math.h>
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
	FRAMERATE_20FPS = 30
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
	Timer(s64 min, s64 max);

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
	void clamp(float min, float max);

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
	void preUpdate();
	void update();
	float m_counter;
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
typedef float CounterF;

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

class FStep : public Step
{
	public:
	FStep();
	FStep(const Step& t);
	FStep(float n);
	FStep(const Rotation& r);
};

namespace oot
{
	void setMaxFramerate(float framerate);
	float getMaxFramerate();
} // namespace oot
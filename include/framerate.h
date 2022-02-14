#pragma once
#include <math.h>

//#define ENABLE_60FPS

#if defined(ENABLE_240FPS)
#define FRAME_RATE 240
#define ENABLE_HIGH_FRAMERATE
#elif defined(ENABLE_120FPS)
#define FRAME_RATE 120
#define ENABLE_HIGH_FRAMERATE
#elif defined(ENABLE_60FPS)
#define FRAME_RATE 60
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

typedef enum{
	PROFILE_BOOT = 0,   // 30FPS
	PROFILE_PAUSE,	    // 20FPS
	PROFILE_GAMEPLAY,   // 20FPS
	PROFILE_UNKNOWN1,   // 60FPS
	PROFILE_UNKNOWN2,   // 60FPS
	PROFILE_SAMPLE,     // 60FPS
	PROFILE_OPENING,    // 60FPS
	PROFILE_SELECT,     // 60FPS
	PROFILE_TITLE,      // 60FPS
	PROFILE_FILE_CHOOSE // 60FPS
} FramerateProfile;

void framerate_init();
u32 framerate_get();
void framerate_set_profile(FramerateProfile profile);
FramerateProfile framerate_get_profile();
u64 frameRateDivisor();

template<class T>
struct Frame
{
	constexpr Frame() : m_counter(0)
	{
	}

	constexpr Frame(const T& n) : m_counter(n * (FRAMERATE_MAX / 20))
	{
	}

	template<class S>
	constexpr Frame(const Frame<S>& n) : m_counter(n.m_counter)
	{
	}

	bool isWhole() const
	{
		return fraction() == 0;
	}

	T whole() const
	{
		return m_counter / (FRAMERATE_MAX / 20);
	}

	T fraction() const
	{
		return m_counter % (FRAMERATE_MAX / 20);
	}

	bool operator==(Frame n) const
	{
		return m_counter == n.m_counter;
	}

	bool operator!=(Frame n) const
	{
		return m_counter != n.m_counter;
	}	

	bool operator<(Frame n) const
	{
		return m_counter < n.m_counter;
	}

	bool operator<=(Frame n) const
	{
		return m_counter <= n.m_counter;
	}

	bool operator>(Frame n) const
	{
		return m_counter > n.m_counter;
	}

	bool operator>=(Frame n) const
	{
		return m_counter >= n.m_counter;
	}

	bool operator==(T n) const
	{
		if(!isWhole())
		{
			return false;
		}

		return whole() == n;
	}

	bool operator!=(T n) const
	{
		return !operator==(n);
	}



	bool operator<(T n) const
	{
		return operator<(Frame<T>(n));
	}	

	bool operator>(T n) const
	{
		return operator>(Frame<T>(n));
	}

	bool operator<=(T n) const
	{
		return operator<=(Frame<T>(n));
	}

	bool operator>=(T n) const
	{
		return operator>=(Frame<T>(n));
	}

	Frame& operator+=(const T& f)
	{
		m_counter += f;
		return *this;
	}

	Frame& operator-=(const T& f)
	{
		m_counter -= f;
		return *this;
	}

	Frame operator+(const T& f) const
	{
		Frame r(*this);
		r.m_counter += f;
		return r;
	}

	Frame operator-(const T& f) const
	{
		Frame r(*this);
		r.m_counter -= f;
		return r;
	}

	Frame& operator+=(const Frame& f)
	{
		m_counter += f.m_counter;
		return *this;
	}

	Frame& operator-=(const Frame& f)
	{
		m_counter -= f.m_counter;
		return *this;
	}

	Frame operator+(const Frame& f) const
	{
		Frame r(*this);
		r.m_counter += f.m_counter;
		return r;
	}

	Frame operator-(const Frame& f) const
	{
		Frame r(*this);
		r.m_counter -= f.m_counter;
		return r;
	}

	Frame operator++() // pre
	{
		m_counter++;
		return *this;
	}

	Frame operator++(int) // post
	{
		m_counter++;
		return *this;
	}

	Frame operator--() // pre
	{
		m_counter--;
		return *this;
	}

	Frame operator--(int) // post
	{
		m_counter--;
		return *this;
	}

	Frame& operator*=(const T& f)
	{
		m_counter *= f;
		return *this;
	}

	Frame& operator/=(const T& f)
	{
		m_counter /= f;
		return *this;
	}

	Frame operator*(const T& f) const
	{
		Frame r(*this);
		r.m_counter *= f;
		return r;
	}

	Frame operator/(const T& f) const
	{
		Frame r(*this);
		r.m_counter /= f;
		return r;
	}

	Frame& operator*=(const Frame& f)
	{
		m_counter *= f.m_counter;
		return *this;
	}

	Frame& operator/=(const Frame& f)
	{
		m_counter /= f.m_counter;
		return *this;
	}

	Frame operator*(const Frame& f) const
	{
		Frame r(*this);
		r.m_counter *= f.m_counter;
		return r;
	}

	Frame operator/(const Frame& f) const
	{
		Frame r(*this);
		r.m_counter /= f.m_counter;
		return r;
	}

	T operator%(const T& f) const
	{
		return whole() % f;
	}

	Frame& operator-()
	{
		m_counter = -m_counter;
		return *this;
	}

	T operator&(const T n) const
	{
		return whole() & n;
	}

	T operator|(const T n) const
	{
		return whole() | n;
	}

	float toFloat() const
	{
		return (float)whole() + ((float)fraction() / ((float)FRAMERATE_MAX / 20.0f));
	}

	s16 toS16() const
	{
		return (s16)whole();
	}

	s16 toU16() const
	{
		return (u16)whole();
	}

	const T& get() const
	{
		return m_counter;
	}

	T& get()
	{
		return m_counter;
	}

	//protected:
	T m_counter;
};

typedef Frame<u64> FrameU64;
typedef Frame<s64> FrameS64;
typedef Frame<u64> TimerU64;
typedef Frame<s64> TimerS64;

typedef Frame<u32> FrameU32;
typedef Frame<s32> FrameS32;
typedef Frame<u32> TimerU32;
typedef Frame<s32> TimerS32;

typedef Frame<u16> FrameU16;
typedef Frame<s16> FrameS16;
typedef Frame<u16> TimerU16;
typedef Frame<s16> TimerS16;

typedef Frame<u8> FrameU8;
typedef Frame<s8> FrameS8;
typedef Frame<u8> TimerU8;
typedef Frame<s8> TimerS8;

typedef Frame<s64> Timer;
typedef Frame<s64> Rotation;
typedef Frame<s64> Counter;

template <class T> bool operator<(u16 a, Frame<T> b)
{
	return b >= a;
}

template <class T> bool operator<=(u16 a, Frame<T> b)
{
	return b > a;
}

template <class T> bool operator>(u16 a, Frame<T> b)
{
	return b <= a;
}

template <class T> bool operator>=(u16 a, Frame<T> b)
{
	return b < a;
}



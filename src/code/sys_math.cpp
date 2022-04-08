#define INTERNAL_SRC_CODE_SYS_MATH_C
#include "global.h"
#include "z64math.h"
#include "def/coss.h"
#include "def/sins.h"
#include "def/sys_math.h"

f32 sFactorialTbl[] = {1.0f, 1.0f, 2.0f, 6.0f, 24.0f, 120.0f, 720.0f, 5040.0f, 40320.0f, 362880.0f, 3628800.0f, 39916800.0f, 479001600.0f};

f32 Math_FactorialF(f32 n)
{
	f32 ret = 1.0f;
	s32 i;

	for(i = n; i > 1; i--)
	{
		ret *= i;
	}
	return ret;
}

f32 Math_Factorial(s32 n)
{
	f32 ret;
	s32 i;

	if((u32)n > 12U)
	{
		ret = sFactorialTbl[12];
		for(i = 13; i <= n; i++)
		{
			ret *= i;
		}
	}
	else
	{
		ret = sFactorialTbl[n];
	}
	return ret;
}

f32 Math_PowF(f32 base, s32 exp)
{
	f32 ret = 1.0f;

	while(exp > 0)
	{
		exp--;
		ret *= base;
	}
	return ret;
}

f32 Math_SinF(f32 angle)
{
	return sins((s16)(angle * (32767.0f / M_PI))) * SHT_MINV;
}

f32 Math_CosF(f32 angle)
{
	return coss((s16)(angle * (32767.0f / M_PI))) * SHT_MINV;
}

VecRot::VecRot() : x(0), y(0), z(0)
{
}

VecRot::VecRot(const Rotation& x, const Rotation& y, const Rotation& z) : x(x), y(y), z(z)
{
}

VecRot::VecRot(const VecRot& vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

VecRot::VecRot(const Vec3s& vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

VecRot::VecRot(const Vec3f& vec) : x(vec.x), y(vec.y), z(vec.z)
{
}

VecRot::operator Vec3s() const
{
	Vec3s vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}

VecRot::operator Vec3f() const
{
	Vec3f vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}
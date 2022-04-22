#define INTERNAL_SRC_CODE_CODE_800FD970_C
#include "global.h"
#include "def/random.h"

#ifdef N64_VERSION

// The latest generated random number, used to generate the next number in the sequence.
static u32 sRandInt = 1;

// Space to store a value to be re-interpreted as a float.
static u32 sRandFloat;

/**
 * Gets the next integer in the sequence of pseudo-random numbers.
 */
u32 Rand_Next(void) {
    return sRandInt = (sRandInt * 1664525) + 1013904223;
}

/**
 * Seeds the pseudo-random number generator by providing a starting value.
 */
void Rand_Seed(u32 seed) {
    sRandInt = seed;

}

/**
 * Returns a pseudo-random floating-point number between 0.0f and 1.0f, by generating
 * the next integer and masking it to an IEEE-754 compliant floating-point number
 * between 1.0f and 2.0f, returning the result subtract 1.0f.
 */
f32 Rand_ZeroOne(void) {
    sRandInt = (sRandInt * 1664525) + 1013904223;
    sRandFloat = ((sRandInt >> 9) | 0x3F800000);
    return *((f32*)&sRandFloat) - 1.0f;
}

/**
 * Returns a pseudo-random floating-point number between -0.5f and 0.5f by the same
 * manner in which Rand_ZeroOne generates its result.
 */
f32 Rand_Centered(void) {
    sRandInt = (sRandInt * 1664525) + 1013904223;
    sRandFloat = ((sRandInt >> 9) | 0x3F800000);
    return *((f32*)&sRandFloat) - 1.5f;
}

#else

#define M 397
#define MATRIX_A 0x9908b0df
#define UPPER_MASK 0x80000000
#define LOWER_MASK 0x7fffffff

#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  ((y) >> 11)
#define TEMPERING_SHIFT_S(y)  ((y) << 7)
#define TEMPERING_SHIFT_T(y)  ((y) << 15)
#define TEMPERING_SHIFT_L(y)  ((y) >> 18)

#define MTRAND_N      624


unsigned short mtRand_xsubi[3]={723, 32761, 44444};

unsigned int mt[MTRAND_N];
int mti;


void Rand_Seed(u32 Seed)
{
    mt[0]= Seed & 0xffffffff;
    for ( mti = 1; mti < MTRAND_N; mti++ ) mt[mti] = (69069 * mt[mti - 1]) & 0xffffffff;
    unsigned int s = 373737;
    for ( mti = 1; mti < MTRAND_N; mti++ )
    {
        mt[mti] ^= s;
        s = s * 5531 + 81547;
        s ^= (s >> 9) ^ (s << 19);
    }
}


f32 Rand_ZeroOne(void)
{
    unsigned int y;
    static const unsigned int mag01[2] = {0x0, MATRIX_A};
    if (mti >= MTRAND_N) 
    {
        int kk;
        for (kk=0;kk<MTRAND_N-M;kk++) 
        {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk<MTRAND_N-1;kk++) 
        {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-MTRAND_N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[MTRAND_N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[MTRAND_N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];
        mti = 0;
    }
    y = mt[mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);
    return ( (float)y * 2.3283064370807974e-10f );
}


f32 Rand_Centered(void) {
    return Rand_ZeroOne() - 0.5f;
}


u32 Rand_Next(void)
{
    unsigned int y;
    static const unsigned long mag01[2] = { 0x0, MATRIX_A };
    if (mti >= MTRAND_N) 
    {
        int kk;
        for (kk=0;kk<MTRAND_N-M;kk++) 
        {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk<MTRAND_N-1;kk++) 
        {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-MTRAND_N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[MTRAND_N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[MTRAND_N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1];
        mti = 0;
    }
    y = mt[mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);
    return y;
}


#endif
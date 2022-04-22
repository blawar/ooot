#ifndef ULTRA64_ABI_H
#define ULTRA64_ABI_H

#include "types.h"

uintptr_t check_pointer(uintptr_t p, u32 sz);

/* Audio commands: */
#define A_SPNOOP 0
#define A_ADPCM 1
#define A_CLEARBUFF 2
#define A_UNK3 3
#define A_ADDMIXER 4
#define A_RESAMPLE 5
#define A_RESAMPLE_ZOH 6
#define A_FILTER 7
#define A_SETBUFF 8
#define A_DUPLICATE 9
#define A_DMEMMOVE 10
#define A_LOADADPCM 11
#define A_MIXER 12
#define A_INTERLEAVE 13
#define A_HILOGAIN 14
#define A_SETLOOP 15
#define A_INTERL 17
#define A_ENVSETUP1 18
#define A_ENVMIXER 19
#define A_LOADBUFF 20
#define A_SAVEBUFF 21
#define A_ENVSETUP2 22
#define A_S8DEC 23
#define A_UNK19 25

#define ACMD_SIZE 32

/*
 * Audio flags
 */
#define A_INIT 0x01
#define A_CONTINUE 0x00
#define A_LOOP 0x02
#define A_OUT 0x02
#define A_LEFT 0x02
#define A_RIGHT 0x00
#define A_VOL 0x04
#define A_RATE 0x00
#define A_AUX 0x08
#define A_NOAUX 0x00
#define A_MAIN 0x00
#define A_MIX 0x10

/*
 * Data Structures.
 */

struct Aadpcm
{
#ifdef LITTLE_ENDIAN
	u32 gain : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 gain : 16;
	u32 addr;
#endif
};

struct Apolef
{
#ifdef LITTLE_ENDIAN
	u32 gain : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 gain : 16;
	u32 addr;
#endif
};

struct Aenvelope
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 pad1 : 16;
	u32 addr;
#endif
};

struct Aclearbuff
{
#ifdef LITTLE_ENDIAN
	u32 dmem : 16;
	u32 pad1 : 8;
	u32 cmd : 8;
	u32 count : 16;
	u32 pad2 : 16;
#else
	u32 cmd : 8;
	u32 pad1 : 8;
	u32 dmem : 16;
	u32 pad2 : 16;
	u32 count : 16;
#endif
};

struct Ainterleave
{
#ifdef LITTLE_ENDIAN
	u32 pad2 : 16;
	u32 pad1 : 8;
	u32 cmd : 8;
	u32 inR : 16;
	u32 inL : 16;
#else
	u32 cmd : 8;
	u32 pad1 : 8;
	u32 pad2 : 16;
	u32 inL : 16;
	u32 inR : 16;
#endif
};

struct Aloadbuff
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 24;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 pad1 : 24;
	u32 addr;
#endif
};

struct Aenvmixer
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 pad1 : 16;
	u32 addr;
#endif
};

struct Amixer
{
#ifdef LITTLE_ENDIAN
	u32 gain : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 dmemo : 16;
	u32 dmemi : 16;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 gain : 16;
	u32 dmemi : 16;
	u32 dmemo : 16;
#endif
};

struct Apan
{
#ifdef LITTLE_ENDIAN
	u32 dmem2 : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 dmem2 : 16;
	u32 addr;
#endif
};

struct Aresample
{
#ifdef LITTLE_ENDIAN
	u32 pitch : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 pitch : 16;
	u32 addr;
#endif
};

struct Areverb
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 pad1 : 16;
	u32 addr;
#endif
};

struct Afilter
{
#ifdef LITTLE_ENDIAN
	u32 count : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 count : 16;
	u32 addr;
#endif
};

struct Asavebuff
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 24;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 pad1 : 24;
	u32 addr;
#endif
};

struct Asegment
{
#ifdef LITTLE_ENDIAN
	u32 pad1 : 24;
	u32 cmd : 8;
	u32 pad3 : 2;
	u32 base : 24;
	u32 number : 4;
	u32 pad2 : 2;
#else
	u32 cmd : 8;
	u32 pad1 : 24;
	u32 pad2 : 2;
	u32 number : 4;
	u32 base : 24;
	u32 pad3 : 2;
#endif
};

struct Asetbuff
{
#ifdef LITTLE_ENDIAN
	u32 dmemin : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 count : 16;
	u32 dmemout : 16;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 dmemin : 16;
	u32 dmemout : 16;
	u32 count : 16;
#endif
};

struct Aduplicate
{
#ifdef LITTLE_ENDIAN
	u32 dmemin : 16;
	u32 repeats : 8;
	u32 cmd : 8;
	u32 size : 16;
	u32 dmemout : 16;
#else
	u32 cmd : 8;
	u32 repeats : 8;
	u32 dmemin : 16;
	u32 dmemout : 16;
	u32 size : 16;
#endif
};

struct Asetvol
{
#ifdef LITTLE_ENDIAN
	u32 vol : 16;
	u32 flags : 8;
	u32 cmd : 8;
	u32 volrate : 16;
	u32 voltgt : 16;
#else
	u32 cmd : 8;
	u32 flags : 8;
	u32 vol : 16;
	u32 voltgt : 16;
	u32 volrate : 16;
#endif
};

struct Admemmove
{
#ifdef LITTLE_ENDIAN
	u32 dmemin : 16;
	u32 pad1 : 8;
	u32 cmd : 8;
	u32 count : 16;
	u32 dmemout : 16;
#else
	u32 cmd : 8;
	u32 pad1 : 8;
	u32 dmemin : 16;
	u32 dmemout : 16;
	u32 count : 16;
#endif
};

struct Aloadadpcm
{
#ifdef LITTLE_ENDIAN
	u32 count : 16;
	u32 pad1 : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 pad1 : 8;
	u32 count : 16;
	u32 addr;
#endif
};

struct Asetloop
{
#ifdef LITTLE_ENDIAN
	u32 pad2 : 16;
	u32 pad1 : 8;
	u32 cmd : 8;
	u32 addr;
#else
	u32 cmd : 8;
	u32 pad1 : 8;
	u32 pad2 : 16;
	u32 addr;
#endif
};

/*
 * Generic Acmd Packet
 */

struct Awords
{
	uintptr_t w0;
	uintptr_t w1;
};

union Acmd
{
	Awords words;
	Aadpcm adpcm;
	Apolef polef;
	Aclearbuff clearbuff;
	Aenvelope envelope;
	Ainterleave interleave;
	Aloadbuff loadbuff;
	Aenvmixer envmixer;
	Aresample resample;
	Areverb reverb;
	Asavebuff savebuff;
	Asegment segment;
	Asetbuff setbuff;
	Asetvol setvol;
	Admemmove dmemmove;
	Aloadadpcm loadadpcm;
	Amixer mixer;
	Asetloop setloop;
	Afilter filter;
	Aduplicate duplicate;
	long long int force_union_align; /* dummy, force alignment */
};

/*
 * ADPCM State
 */
#define ADPCMVSIZE 8
#define ADPCMFSIZE 16
typedef short ADPCM_STATE[ADPCMFSIZE];

/*
 * Pole filter state
 */
typedef short POLEF_STATE[4];

/*
 * Resampler state
 */
typedef short RESAMPLE_STATE[16];

/*
 * Resampler constants
 */
#define UNITY_PITCH 0x8000
#define MAX_RATIO 1.99996 /* within .03 cents of +1 octave */

/*
 * Enveloper/Mixer state
 */
typedef short ENVMIX_STATE[40];

/*
 * Macros to assemble the audio command list
 */

#define aADPCMdec(pkt, f, s)                                                                                                                                                                                                                                   \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8);                                                                                                                                                                                    \
		_a->words.w1 = (uintptr_t)(s);                                                                                                                                                                                                                 \
	}

#define aPoleFilter(pkt, f, g, s)                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16));                                                                                                                                                              \
		_a->words.w1 = (uintptr_t)(s);                                                                                                                                                                                                                 \
	}

#define aHiLoGain(pkt, gain, count, dmem, a4)                                                                                                                                                                                                                  \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_HILOGAIN, 24, 8) | _SHIFTL(gain, 16, 8) | _SHIFTL(count, 0, 16));                                                                                                                                                    \
		_a->words.w1 = _SHIFTL(dmem, 16, 16) | _SHIFTL(a4, 0, 16);                                                                                                                                                                                     \
	}

#define aUnkCmd3(pkt, a1, a2, a3)                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_UNK3, 24, 8) | _SHIFTL(a3, 0, 16);                                                                                                                                                                                    \
		_a->words.w1 = _SHIFTL(a1, 16, 16) | _SHIFTL(a2, 0, 16);                                                                                                                                                                                       \
	}

#define aUnkCmd19(pkt, a1, a2, a3, a4)                                                                                                                                                                                                                         \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_UNK19, 24, 8) | _SHIFTL(a1, 16, 8) | _SHIFTL(a2, 0, 16));                                                                                                                                                            \
		_a->words.w1 = _SHIFTL(a3, 16, 16) | _SHIFTL(a4, 0, 16);                                                                                                                                                                                       \
	}

#define aS8Dec(pkt, a1, a2)                                                                                                                                                                                                                                    \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_S8DEC, 24, 8) | _SHIFTL(a1, 16, 8);                                                                                                                                                                                   \
		_a->words.w1 = (uintptr_t)(a2);                                                                                                                                                                                                                \
	}

#define aClearBuffer(pkt, d, c)                                                                                                                                                                                                                                \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24);                                                                                                                                                                                \
		_a->words.w1 = (uintptr_t)(c);                                                                                                                                                                                                                 \
	}

#define aEnvMixer(pkt, dmemi, count, swapLR, x0, x1, x2, x3, m, bits)                                                                                                                                                                                          \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (bits | _SHIFTL(dmemi >> 4, 16, 8) | _SHIFTL(count, 8, 8) | _SHIFTL(swapLR, 4, 1) | _SHIFTL(x0, 3, 1) | _SHIFTL(x1, 2, 1) | _SHIFTL(x2, 1, 1) | _SHIFTL(x3, 0, 1));                                                             \
		_a->words.w1 = (uintptr_t)(m);                                                                                                                                                                                                                 \
	}

#define aInterleave(pkt, o, l, r, c)                                                                                                                                                                                                                           \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_INTERLEAVE, 24, 8) | _SHIFTL(c >> 4, 16, 8) | _SHIFTL(o, 0, 16));                                                                                                                                                    \
		_a->words.w1 = _SHIFTL(l, 16, 16) | _SHIFTL(r, 0, 16);                                                                                                                                                                                         \
	}

#define aInterl(pkt, dmemi, dmemo, count)                                                                                                                                                                                                                      \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_INTERL, 24, 8) | _SHIFTL(count, 0, 16));                                                                                                                                                                             \
		_a->words.w1 = _SHIFTL(dmemi, 16, 16) | _SHIFTL(dmemo, 0, 16);                                                                                                                                                                                 \
	}

#define aLoadBuffer(pkt, s, d, c)                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_LOADBUFF, 24, 8) | _SHIFTL((c) >> 4, 16, 8) | _SHIFTL(d, 0, 16));                                                                                                                                                    \
		_a->words.w1 = check_pointer((uintptr_t)(s), c);                                                                                                                                                                                               \
	}

#define aMix(pkt, f, g, i, o)                                                                                                                                                                                                                                  \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16));                                                                                                                                                              \
		_a->words.w1 = _SHIFTL(i, 16, 16) | _SHIFTL(o, 0, 16);                                                                                                                                                                                         \
	}

#define aPan(pkt, f, d, s)                                                                                                                                                                                                                                     \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_PAN, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(d, 0, 16));                                                                                                                                                                \
		_a->words.w1 = (uintptr_t)(s);                                                                                                                                                                                                                 \
	}

#define aResample(pkt, f, p, s)                                                                                                                                                                                                                                \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16));                                                                                                                                                           \
		_a->words.w1 = (uintptr_t)(s);                                                                                                                                                                                                                 \
	}

#define aSaveBuffer(pkt, s, d, c)                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_SAVEBUFF, 24, 8) | _SHIFTL((c) >> 4, 16, 8) | _SHIFTL(s, 0, 16));                                                                                                                                                    \
		_a->words.w1 = (uintptr_t)(d);                                                                                                                                                                                                                 \
	}

#define aSegment(pkt, s, b)                                                                                                                                                                                                                                    \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_SEGMENT, 24, 8);                                                                                                                                                                                                      \
		_a->words.w1 = _SHIFTL(s, 24, 8) | _SHIFTL(b, 0, 24);                                                                                                                                                                                          \
	}

#define aSetBuffer(pkt, f, i, o, c)                                                                                                                                                                                                                            \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16));                                                                                                                                                            \
		_a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16);                                                                                                                                                                                         \
	}

#define aSetVolume(pkt, f, v, t, r)                                                                                                                                                                                                                            \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) | _SHIFTL(v, 0, 16));                                                                                                                                                            \
		_a->words.w1 = _SHIFTL(r, 0, 16) | _SHIFTL(t, 16, 16);                                                                                                                                                                                         \
	}

#define aSetVolume32(pkt, f, v, tr)                                                                                                                                                                                                                            \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) | _SHIFTL(v, 0, 16));                                                                                                                                                            \
		_a->words.w1 = (uintptr_t)(tr);                                                                                                                                                                                                                \
	}

#define aSetLoop(pkt, a)                                                                                                                                                                                                                                       \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_SETLOOP, 24, 8);                                                                                                                                                                                                      \
		_a->words.w1 = (uintptr_t)(a);                                                                                                                                                                                                                 \
	}

#define aDMEMMove(pkt, i, o, c)                                                                                                                                                                                                                                \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24);                                                                                                                                                                                 \
		_a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16);                                                                                                                                                                                         \
	}

#define aLoadADPCM(pkt, c, d)                                                                                                                                                                                                                                  \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24);                                                                                                                                                                                \
		_a->words.w1 = check_pointer((uintptr_t)d, c);                                                                                                                                                                                                 \
	}

#define aEnvSetup1(pkt, a, b, c, d)                                                                                                                                                                                                                            \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_ENVSETUP1, 24, 8) | _SHIFTL(a, 16, 8) | _SHIFTL(b, 0, 16));                                                                                                                                                          \
		_a->words.w1 = _SHIFTL(c, 16, 16) | _SHIFTL(d, 0, 16);                                                                                                                                                                                         \
	}

#define aEnvSetup2(pkt, volLeft, volRight)                                                                                                                                                                                                                     \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = _SHIFTL(A_ENVSETUP2, 24, 8);                                                                                                                                                                                                    \
		_a->words.w1 = (_SHIFTL(volLeft, 16, 16) | _SHIFTL(volRight, 0, 16));                                                                                                                                                                          \
	}

#define aFilter(pkt, f, countOrBuf, addr)                                                                                                                                                                                                                      \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_FILTER, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(countOrBuf, 0, 16));                                                                                                                                                    \
		_a->words.w1 = (uintptr_t)(addr);                                                                                                                                                                                                              \
	}

#define aDuplicate(pkt, count, dmemi, dmemo, a4)                                                                                                                                                                                                               \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_DUPLICATE, 24, 8) | _SHIFTL(count, 16, 8) | _SHIFTL(dmemi, 0, 16));                                                                                                                                                  \
		_a->words.w1 = _SHIFTL(dmemo, 16, 16) | _SHIFTL(a4, 0, 16);                                                                                                                                                                                    \
	}

#define aAddMixer(pkt, count, dmemi, dmemo, a4)                                                                                                                                                                                                                \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_ADDMIXER, 24, 8) | _SHIFTL(count >> 4, 16, 8) | _SHIFTL(a4, 0, 16));                                                                                                                                                 \
		_a->words.w1 = _SHIFTL(dmemi, 16, 16) | _SHIFTL(dmemo, 0, 16);                                                                                                                                                                                 \
	}

#define aResampleZoh(pkt, pitch, pitchAccu)                                                                                                                                                                                                                    \
	{                                                                                                                                                                                                                                                      \
		Acmd* _a = (Acmd*)pkt;                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                               \
		_a->words.w0 = (_SHIFTL(A_RESAMPLE_ZOH, 24, 8) | _SHIFTL(pitch, 0, 16));                                                                                                                                                                       \
		_a->words.w1 = _SHIFTL(pitchAccu, 0, 16);                                                                                                                                                                                                      \
	}

#endif /* ULTRA64_ABI_H */

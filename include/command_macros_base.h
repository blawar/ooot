#ifndef COMMAND_MACROS_BASE_H
#define COMMAND_MACROS_BASE_H

/**
 * Command Base macros intended for use in designing of more specific command macros
 * Each macro packs bytes (B), halfwords (H) and words (W, for consistency) into a single word
 */
/*
#define CMD_BBBB(a, b, c, d) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 8, 8) | _SHIFTL(d, 0, 8))

#define CMD_BBH(a, b, c) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 0, 16))

#define CMD_HBB(a, b, c) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 0, 8))

#define CMD_HH(a, b) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 0, 16))

#define CMD_W(a) (a)
*/

#if IS_BIG_ENDIAN
#if IS_64_BIT
#define CMD_BBBB(a, b, c, d) \
    ((uintptr_t)(_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 8, 8) | _SHIFTL(d, 0, 8)) << 32)
#define CMD_BBH(a, b, c) ((uintptr_t)(_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 0, 16)) << 32)
#define CMD_HH(a, b) ((uintptr_t)(_SHIFTL(a, 16, 16) | _SHIFTL(b, 0, 16)) << 32)
#define CMD_W(a) ((uintptr_t)(a) << 32)
#else
#define CMD_BBBB(a, b, c, d) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 8, 8) | _SHIFTL(d, 0, 8))
#define CMD_BBH(a, b, c) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 0, 16))
#define CMD_HBB(a, b, c) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 0, 8))
#define CMD_HH(a, b) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 0, 16))
#define CMD_W(a) (a)
#endif
#else
#if IS_64_BIT
#define CMD_BBBB(a, b, c, d) (_SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 16, 8) | _SHIFTL(d, 24, 8))
#define CMD_BBH(a, b, c) (_SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 16, 16))
#define CMD_HBB(a, b, c) (_SHIFTL(a, 0, 16) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 24, 8))
#define CMD_HH(a, b) (_SHIFTL(a, 0, 16) | _SHIFTL(b, 16, 16))
#define CMD_W(a) (a)
#else
#define CMD_BBBB(a, b, c, d) (_SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 16, 8) | _SHIFTL(d, 24, 8))
#define CMD_BBH(a, b, c) (_SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(c, 16, 16))
#define CMD_HBB(a, b, c) (_SHIFTL(a, 0, 16) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 24, 8))
#define CMD_HH(a, b) (_SHIFTL(a, 0, 16) | _SHIFTL(b, 16, 16))
#define CMD_W(a) (a)
#endif
#endif

#ifdef __GNUC__
#define CMD_F(a) {.f = (a)}
#else
#ifdef _MSC_VER
#define CMD_F(a) {.f = (a)}
#else
#define CMD_F(a) {(a)}
#endif
#endif

#define CMD_PTR(a) (uintptr_t)(a)

#endif

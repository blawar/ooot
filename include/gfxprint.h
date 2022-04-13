#pragma once

#define GFXP_UNUSED "\x8E"
#define GFXP_UNUSED_CHAR 0x8E
#define GFXP_HIRAGANA "\x8D"
#define GFXP_HIRAGANA_CHAR 0x8D
#define GFXP_KATAKANA "\x8C"
#define GFXP_KATAKANA_CHAR 0x8C
#define GFXP_RAINBOW_ON "\x8B"
#define GFXP_RAINBOW_ON_CHAR 0x8B
#define GFXP_RAINBOW_OFF "\x8A"
#define GFXP_RAINBOW_OFF_CHAR 0x8A

#define GFXP_FLAG_HIRAGANA (1 << 0)
#define GFXP_FLAG_RAINBOW (1 << 1)
#define GFXP_FLAG_SHADOW (1 << 2)
#define GFXP_FLAG_UPDATE (1 << 3)
#define GFXP_FLAG_ENLARGE (1 << 6)
#define GFXP_FLAG_OPEN (1 << 7)
#define GFXP_FLAG_CENTER (1 << 8)

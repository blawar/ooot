#pragma once
#define Z_EN_TORCH2_H

#include "ultra64.h"
#include "global.h"

// Uses the Player struct (from z64player.h)



enum EnTorch2ActionStates {
    /* 0 */ ENTORCH2_WAIT,
    /* 1 */ ENTORCH2_ATTACK,
    /* 2 */ ENTORCH2_DEATH,
    /* 3 */ ENTORCH2_DAMAGE
};


enum PlayerSwordAnimation {
    /*  0 */ FORWARD_SLASH_1H,
    /*  1 */ FORWARD_SLASH_2H,
    /*  2 */ FORWARD_COMBO_1H,
    /*  3 */ FORWARD_COMBO_2H,
    /*  4 */ RIGHT_SLASH_1H,
    /*  5 */ RIGHT_SLASH_2H,
    /*  6 */ RIGHT_COMBO_1H,
    /*  7 */ RIGHT_COMBO_2H,
    /*  8 */ LEFT_SLASH_1H,
    /*  9 */ LEFT_SLASH_2H,
    /* 10 */ LEFT_COMBO_1H,
    /* 11 */ LEFT_COMBO_2H,
    /* 12 */ STAB_1H,
    /* 13 */ STAB_2H,
    /* 14 */ STAB_COMBO_1H,
    /* 15 */ STAB_COMBO_2H,
    /* 16 */ FLIPSLASH_START,
    /* 17 */ JUMPSLASH_START,
    /* 18 */ FLIPSLASH_FINISH,
    /* 19 */ JUMPSLASH_FINISH,
    /* 20 */ BACKSLASH_RIGHT,
    /* 21 */ BACKSLASH_LEFT,
    /* 22 */ HAMMER_FORWARD,
    /* 23 */ HAMMER_SIDE,
    /* 24 */ SPIN_ATTACK_1H,
    /* 25 */ SPIN_ATTACK_2H,
    /* 26 */ BIG_SPIN_1H,
    /* 27 */ BIG_SPIN_2H
};

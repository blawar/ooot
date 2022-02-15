#pragma once

#include "z64global.h"
#include "gfx.h"
#include "z64math.h"

#include "z64actor.h"

struct Player;

enum PlayerShield {
    /* 0x00 */ PLAYER_SHIELD_NONE,
    /* 0x01 */ PLAYER_SHIELD_DEKU,
    /* 0x02 */ PLAYER_SHIELD_HYLIAN,
    /* 0x03 */ PLAYER_SHIELD_MIRROR,
    /* 0x04 */ PLAYER_SHIELD_MAX
};

enum PlayerTunic {
    /* 0x00 */ PLAYER_TUNIC_KOKIRI,
    /* 0x01 */ PLAYER_TUNIC_GORON,
    /* 0x02 */ PLAYER_TUNIC_ZORA,
    /* 0x03 */ PLAYER_TUNIC_MAX
};

enum PlayerBoots {
    /* 0x00 */ PLAYER_BOOTS_NORMAL,
    /* 0x01 */ PLAYER_BOOTS_IRON,
    /* 0x02 */ PLAYER_BOOTS_HOVER,
    /* Values below are only relevant when setting regs in Player_SetBootData */
    /* 0x03 */ PLAYER_BOOTS_INDOOR,
    /* 0x04 */ PLAYER_BOOTS_IRON_UNDERWATER,
    /* 0x05 */ PLAYER_BOOTS_NORMAL_CHILD,
    /* 0x06 */ PLAYER_BOOTS_MAX
};

enum PlayerStrength {
    /* 0x00 */ PLAYER_STR_NONE,
    /* 0x01 */ PLAYER_STR_BRACELET,
    /* 0x02 */ PLAYER_STR_SILVER_G,
    /* 0x03 */ PLAYER_STR_GOLD_G,
    /* 0x04 */ PLAYER_STR_MAX
};

enum PlayerMask {
    /* 0x00 */ PLAYER_MASK_NONE,
    /* 0x01 */ PLAYER_MASK_KEATON,
    /* 0x02 */ PLAYER_MASK_SKULL,
    /* 0x03 */ PLAYER_MASK_SPOOKY,
    /* 0x04 */ PLAYER_MASK_BUNNY,
    /* 0x05 */ PLAYER_MASK_GORON,
    /* 0x06 */ PLAYER_MASK_ZORA,
    /* 0x07 */ PLAYER_MASK_GERUDO,
    /* 0x08 */ PLAYER_MASK_TRUTH,
    /* 0x09 */ PLAYER_MASK_MAX
};

enum PlayerActionParam {
    /* 0x00 */ PLAYER_AP_NONE,
    /* 0x01 */ PLAYER_AP_LAST_USED,
    /* 0x02 */ PLAYER_AP_FISHING_POLE,
    /* 0x03 */ PLAYER_AP_SWORD_MASTER,
    /* 0x04 */ PLAYER_AP_SWORD_KOKIRI,
    /* 0x05 */ PLAYER_AP_SWORD_BGS,
    /* 0x06 */ PLAYER_AP_STICK,
    /* 0x07 */ PLAYER_AP_HAMMER,
    /* 0x08 */ PLAYER_AP_BOW,
    /* 0x09 */ PLAYER_AP_BOW_FIRE,
    /* 0x0A */ PLAYER_AP_BOW_ICE,
    /* 0x0B */ PLAYER_AP_BOW_LIGHT,
    /* 0x0C */ PLAYER_AP_BOW_0C,
    /* 0x0D */ PLAYER_AP_BOW_0D,
    /* 0x0E */ PLAYER_AP_BOW_0E,
    /* 0x0F */ PLAYER_AP_SLINGSHOT,
    /* 0x10 */ PLAYER_AP_HOOKSHOT,
    /* 0x11 */ PLAYER_AP_LONGSHOT,
    /* 0x12 */ PLAYER_AP_BOMB,
    /* 0x13 */ PLAYER_AP_BOMBCHU,
    /* 0x14 */ PLAYER_AP_BOOMERANG,
    /* 0x15 */ PLAYER_AP_MAGIC_SPELL_15,
    /* 0x16 */ PLAYER_AP_MAGIC_SPELL_16,
    /* 0x17 */ PLAYER_AP_MAGIC_SPELL_17,
    /* 0x18 */ PLAYER_AP_FARORES_WIND,
    /* 0x19 */ PLAYER_AP_NAYRUS_LOVE,
    /* 0x1A */ PLAYER_AP_DINS_FIRE,
    /* 0x1B */ PLAYER_AP_NUT,
    /* 0x1C */ PLAYER_AP_OCARINA_FAIRY,
    /* 0x1D */ PLAYER_AP_OCARINA_TIME,
    /* 0x1E */ PLAYER_AP_BOTTLE,
    /* 0x1F */ PLAYER_AP_BOTTLE_FISH,
    /* 0x20 */ PLAYER_AP_BOTTLE_FIRE,
    /* 0x21 */ PLAYER_AP_BOTTLE_BUG,
    /* 0x22 */ PLAYER_AP_BOTTLE_POE,
    /* 0x23 */ PLAYER_AP_BOTTLE_BIG_POE,
    /* 0x24 */ PLAYER_AP_BOTTLE_LETTER,
    /* 0x25 */ PLAYER_AP_BOTTLE_POTION_RED,
    /* 0x26 */ PLAYER_AP_BOTTLE_POTION_BLUE,
    /* 0x27 */ PLAYER_AP_BOTTLE_POTION_GREEN,
    /* 0x28 */ PLAYER_AP_BOTTLE_MILK,
    /* 0x29 */ PLAYER_AP_BOTTLE_MILK_HALF,
    /* 0x2A */ PLAYER_AP_BOTTLE_FAIRY,
    /* 0x2B */ PLAYER_AP_LETTER_ZELDA,
    /* 0x2C */ PLAYER_AP_WEIRD_EGG,
    /* 0x2D */ PLAYER_AP_CHICKEN,
    /* 0x2E */ PLAYER_AP_BEAN,
    /* 0x2F */ PLAYER_AP_POCKET_EGG,
    /* 0x30 */ PLAYER_AP_POCKET_CUCCO,
    /* 0x31 */ PLAYER_AP_COJIRO,
    /* 0x32 */ PLAYER_AP_ODD_MUSHROOM,
    /* 0x33 */ PLAYER_AP_ODD_POTION,
    /* 0x34 */ PLAYER_AP_SAW,
    /* 0x35 */ PLAYER_AP_SWORD_BROKEN,
    /* 0x36 */ PLAYER_AP_PRESCRIPTION,
    /* 0x37 */ PLAYER_AP_FROG,
    /* 0x38 */ PLAYER_AP_EYEDROPS,
    /* 0x39 */ PLAYER_AP_CLAIM_CHECK,
    /* 0x3A */ PLAYER_AP_MASK_KEATON,
    /* 0x3B */ PLAYER_AP_MASK_SKULL,
    /* 0x3C */ PLAYER_AP_MASK_SPOOKY,
    /* 0x3D */ PLAYER_AP_MASK_BUNNY,
    /* 0x3E */ PLAYER_AP_MASK_GORON,
    /* 0x3F */ PLAYER_AP_MASK_ZORA,
    /* 0x40 */ PLAYER_AP_MASK_GERUDO,
    /* 0x41 */ PLAYER_AP_MASK_TRUTH,
    /* 0x42 */ PLAYER_AP_LENS,
    /* 0x43 */ PLAYER_AP_MAX
};

enum PlayerLimb {
    /* 0x00 */ PLAYER_LIMB_NONE,
    /* 0x01 */ PLAYER_LIMB_ROOT,
    /* 0x02 */ PLAYER_LIMB_WAIST,
    /* 0x03 */ PLAYER_LIMB_LOWER,
    /* 0x04 */ PLAYER_LIMB_R_THIGH,
    /* 0x05 */ PLAYER_LIMB_R_SHIN,
    /* 0x06 */ PLAYER_LIMB_R_FOOT,
    /* 0x07 */ PLAYER_LIMB_L_THIGH,
    /* 0x08 */ PLAYER_LIMB_L_SHIN,
    /* 0x09 */ PLAYER_LIMB_L_FOOT,
    /* 0x0A */ PLAYER_LIMB_UPPER,
    /* 0x0B */ PLAYER_LIMB_HEAD,
    /* 0x0C */ PLAYER_LIMB_HAT,
    /* 0x0D */ PLAYER_LIMB_COLLAR,
    /* 0x0E */ PLAYER_LIMB_L_SHOULDER,
    /* 0x0F */ PLAYER_LIMB_L_FOREARM,
    /* 0x10 */ PLAYER_LIMB_L_HAND,
    /* 0x11 */ PLAYER_LIMB_R_SHOULDER,
    /* 0x12 */ PLAYER_LIMB_R_FOREARM,
    /* 0x13 */ PLAYER_LIMB_R_HAND,
    /* 0x14 */ PLAYER_LIMB_SHEATH,
    /* 0x15 */ PLAYER_LIMB_TORSO,
    /* 0x16 */ PLAYER_LIMB_MAX
};

enum PlayerDoorType {
    /* -1 */ PLAYER_DOORTYPE_AJAR = -1,
    /*  0 */ PLAYER_DOORTYPE_NONE,
    /*  1 */ PLAYER_DOORTYPE_HANDLE,
    /*  2 */ PLAYER_DOORTYPE_SLIDING,
    /*  3 */ PLAYER_DOORTYPE_FAKE
};


#define PLAYER_LIMB_BUF_COUNT PLAYER_LIMB_MAX + 2 // 2 extra entries in limb buffers?

struct PlayerAgeProperties {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ Vec3s unk_44;
    /* 0x4A */ Vec3s unk_4A[4];
    /* 0x62 */ Vec3s unk_62[4];
    /* 0x7A */ Vec3s unk_7A[2];
    /* 0x86 */ Vec3s unk_86[2];
    /* 0x92 */ u16 unk_92;
    /* 0x94 */ u16 unk_94;
    /* 0x98 */ LinkAnimationHeader* unk_98;
    /* 0x9C */ LinkAnimationHeader* unk_9C;
    /* 0xA0 */ LinkAnimationHeader* unk_A0;
    /* 0xA4 */ LinkAnimationHeader* unk_A4;
    /* 0xA8 */ LinkAnimationHeader* unk_A8;
    /* 0xAC */ LinkAnimationHeader* unk_AC[4];
    /* 0xBC */ LinkAnimationHeader* unk_BC[2];
    /* 0xC4 */ LinkAnimationHeader* unk_C4[2];
    /* 0xCC */ LinkAnimationHeader* unk_CC[2];
}; // size = 0xD4

struct WeaponInfo {
    /* 0x00 */ s32 active;
    /* 0x04 */ Vec3f tip;
    /* 0x10 */ Vec3f base;
}; // size = 0x1C

#include "overlays/actors/ovl_player_actor/z_player.h"

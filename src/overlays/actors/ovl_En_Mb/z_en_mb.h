#pragma once
#define Z_EN_MB_H

#include "ultra64.h"
#include "global.h"

struct EnMb;

typedef void (*EnMbActionFunc)(struct EnMb*, GlobalContext*);

enum EnMbState {
    /*  0 */ ENMB_STATE_SPEAR_SPEARPATH_DAMAGED,
    /*  1 */ ENMB_STATE_CLUB_DEAD,
    /*  2 */ ENMB_STATE_CLUB_KNEELING_DAMAGED,
    /*  3 */ ENMB_STATE_CLUB_KNEELING,
    /*  5 */ ENMB_STATE_STUNNED = 5,
    /*  6 */ ENMB_STATE_IDLE,
    /*  9 */ ENMB_STATE_WALK = 9,
    /* 10 */ ENMB_STATE_ATTACK,
    /* 11 */ ENMB_STATE_ATTACK_END
};


enum EnMbType {
    /* -1 */ ENMB_TYPE_SPEAR_GUARD = -1,
    /*  0 */ ENMB_TYPE_CLUB,
    /*  1 */ ENMB_TYPE_SPEAR_PATROL
};

enum EnMbLimb {
    /*  1 */ ENMB_LIMB_ROOT = 1,
    /*  3 */ ENMB_LIMB_WAIST = 3,
    /*  6 */ ENMB_LIMB_CHEST = 6,
    /*  7 */ ENMB_LIMB_HEAD,
    /*  9 */ ENMB_LIMB_LSHOULDER = 9,
    /* 11 */ ENMB_LIMB_LFOREARM = 11,
    /* 12 */ ENMB_LIMB_LHAND,
    /* 14 */ ENMB_LIMB_RSHOULDER = 14,
    /* 16 */ ENMB_LIMB_RFOREARM = 16,
    /* 17 */ ENMB_LIMB_RHAND,
    /* 20 */ ENMB_LIMB_LTHIGH = 20,
    /* 21 */ ENMB_LIMB_LSHIN,
    /* 22 */ ENMB_LIMB_LFOOT,
    /* 25 */ ENMB_LIMB_RTHIGH = 25,
    /* 26 */ ENMB_LIMB_RSHIN,
    /* 27 */ ENMB_LIMB_RFOOT
};


enum EnMbDamageEffect {
    /* 0x0 */ ENMB_DMGEFF_IGNORE,
    /* 0x1 */ ENMB_DMGEFF_STUN,
    /* 0x5 */ ENMB_DMGEFF_FREEZE = 0x5,
    /* 0x6 */ ENMB_DMGEFF_STUN_ICE,
    /* 0xF */ ENMB_DMGEFF_DEFAULT = 0xF
};
struct EnMb {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ Vec3s bodyPartsPos[10];
    /* 0x0188 */ u8 damageEffect;
    /* 0x018C */ SkelAnime skelAnime;
    /* 0x01D0 */ Vec3s jointTable[28];
    /* 0x0278 */ Vec3s morphTable[28];
    /* 0x0320 */ EnMbState state;
    /* 0x0324 */ EnMbActionFunc actionFunc;
    /* 0x0328 */ s16 iceEffectTimer;
    /* 0x032A */ s16 timer1;
    /* 0x032C */ s16 timer2;
    /* 0x032E */ s16 timer3;
    /* 0x0330 */ s16 yawToWaypoint;
    /* 0x0332 */ s16 unk_332;
    /* 0x0334 */ s16 attack;
    /* 0x0338 */ Vec3f effSpawnPos;
    /* 0x0344 */ Vec3f waypointPos;
    /* 0x0350 */ char unk_34A[0xC];
    /* 0x035C */ s8 waypoint;
    /* 0x035D */ s8 path;
    /* 0x035E */ s8 direction;
    /* 0x0360 */ f32 maxHomeDist;
    /* 0x0364 */ f32 playerDetectionRange;
    /* 0x0368 */ ColliderCylinder hitbox;
    /* 0x03B4 */ ColliderQuad attackCollider; // for attacking the player
    /* 0x0434 */ ColliderTris frontShielding; // Moblins don't have shields, but this acts as one
    /* 0x0454 */ ColliderTrisElement frontShieldingTris[2];
}; 



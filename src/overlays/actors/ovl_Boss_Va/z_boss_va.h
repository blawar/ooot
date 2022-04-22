#pragma once
#define Z_BOSS_VA_H

#include "ultra64.h"
#include "global.h"

struct BossVa;

typedef void (*BossVaActionFunc)(struct BossVa*, GlobalContext*);


struct BossVaEffect {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ u8 type;
    /* 0x26 */ u16 timer;
    /* 0x28 */ s16 mode;
    /* 0x2A */ Vec3s rot;
    /* 0x30 */ s16 primColor[4];
    /* 0x38 */ s16 envColor[4];
    /* 0x40 */ f32 scale;
    /* 0x44 */ f32 scaleMod;
    /* 0x48 */ Vec3f offset;
    /* 0x54 */ struct BossVa* parent;
};
 

enum BossVaEffectType {
    /* 0 */ VA_NONE,
    /* 1 */ VA_LARGE_SPARK,
    /* 2 */ VA_BLAST_SPARK,
    /* 3 */ VA_SMALL_SPARK,
    /* 4 */ VA_SPARK_BALL,
    /* 5 */ VA_ZAP_CHARGE,
    /* 6 */ VA_BLOOD,
    /* 7 */ VA_TUMOR,
    /* 8 */ VA_GORE
};


enum BossVaSparkMode {
    /* 1 */ SPARK_TETHER = 1,
    /* 2 */ SPARK_BARI,
    /* 3 */ SPARK_BLAST,
    /* 4 */ SPARK_UNUSED,
    /* 5 */ SPARK_BODY,
    /* 6 */ SPARK_LINK
};


enum BossVaBloodMode {
    /* 0 */ BLOOD_DROPLET,
    /* 1 */ BLOOD_SPLATTER,
    /* 2 */ BLOOD_SPOT
};


enum BossVaTumorMode {
    /* 0 */ TUMOR_UNUSED,
    /* 1 */ TUMOR_BODY,
    /* 2 */ TUMOR_ARM
};


enum BossVaGoreMode {
    /* 0 */ GORE_PERMANENT,
    /* 1 */ GORE_FLOOR,
    /* 2 */ GORE_FADING
};


enum BossVaCutscene {
    /* -5 */ INTRO_UNUSED_START = -5,
    /* -4 */ INTRO_START,
    /* -3 */ INTRO_LOOK_DOOR,
    /* -2 */ INTRO_CLOSE_DOOR,
    /* -1 */ INTRO_DOOR_SHUT,
    /*  0 */ INTRO_CRACKLE,
    /*  1 */ INTRO_SPAWN_BARI,
    /*  2 */ INTRO_LOOK_BARI,
    /*  3 */ INTRO_REVERSE_CAMERA,
    /*  4 */ INTRO_SUPPORT_CAMERA,
    /*  5 */ INTRO_BODY_SOUND,
    /*  6 */ INTRO_LOOK_SUPPORT,
    /*  7 */ INTRO_UNUSED_CALL_BARI,
    /*  8 */ INTRO_CALL_BARI,
    /*  9 */ INTRO_ATTACH_BARI,
    /* 10 */ INTRO_TITLE,
    /* 11 */ INTRO_BRIGHTEN,
    /* 12 */ INTRO_FINISH,
    /* 13 */ BOSSVA_BATTLE,
    /* 14 */ DEATH_START,
    /* 15 */ DEATH_BODY_TUMORS,
    /* 16 */ DEATH_ZAPPER_1,
    /* 17 */ DEATH_ZAPPER_2,
    /* 18 */ DEATH_ZAPPER_3,
    /* 19 */ DEATH_SHELL_BURST,
    /* 20 */ DEATH_CORE_TUMORS,
    /* 21 */ DEATH_CORE_DEAD,
    /* 22 */ DEATH_CORE_BURST,
    /* 23 */ DEATH_MUSIC,
    /* 24 */ DEATH_FINISH
};
struct BossVa {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ BossVaActionFunc actionFunc;
    /* 0x0194 */ u8 onCeiling;
    /* 0x0195 */ u8 burst;
    /* 0x0196 */ s8 invincibilityTimer;
    /* 0x0197 */ u8 isDead;
    /* 0x0198 */ s32 timer;
    /* 0x019C */ s16 timer2;
    /* 0x01A0 */ f32 unk_1A0; // Upper body section pulse, Bari spin radius
    /* 0x01A4 */ f32 unk_1A4; // Lower body segment pulse, Bari bob phase
    /* 0x01A8 */ f32 unk_1A8; // Death camera zoom. Always 0.
    /* 0x01AC */ s16 unk_1AC; // Body pulse phase, death camera rotation, Bari radius
    /* 0x01AE */ s16 bodyGlow;
    /* 0x01B0 */ s16 unk_1B0; // Body glow pulse rate, death growths counter, zapper death camera
    /* 0x01B4 */ Vec3f armTip;
    /* 0x01C0 */ Vec3f zapNeckPos;
    /* 0x01CC */ Vec3f zapHeadPos;
    /* 0x01D8 */ Vec3f unk_1D8; // Bari scale, Attach point for Bari spin, zapper head
    /* 0x01E4 */ s16 unk_1E4; // Various Zapper rotations
    /* 0x01E6 */ s16 unk_1E6;
    /* 0x01E8 */ s16 unk_1E8;
    /* 0x01EA */ s16 unk_1EA;
    /* 0x01EC */ s16 unk_1EC;
    /* 0x01EE */ s16 unk_1EE;
    /* 0x01F0 */ s16 unk_1F0; // Bari lightning scale
    /* 0x01F2 */ s16 unk_1F2; // Intro camera rotation rate
    /* 0x01F4 */ s16 unk_1F4;
    /* 0x01F6 */ Vec3s headRot;
    /* 0x01FC */ Vec3f effectPos[10];
    /* 0x0274 */ Vec3f unk_274; // Unused body position
    /* 0x0280 */ Vec3f unk_280; // Unused body position
    /* 0x028C */ ColliderCylinder colliderBody;
    /* 0x02D8 */ ColliderJntSph colliderSph;
    /* 0x02F8 */ ColliderJntSphElement elements[1];
    /* 0x0338 */ ColliderQuad colliderLightning;
}; 

enum BossVaParam {
    /* -1 */ BOSSVA_BODY = -1,
    /*  0 */ BOSSVA_SUPPORT_1,
    /*  1 */ BOSSVA_SUPPORT_2,
    /*  2 */ BOSSVA_SUPPORT_3,
    /*  3 */ BOSSVA_ZAPPER_1,
    /*  4 */ BOSSVA_ZAPPER_2,
    /*  5 */ BOSSVA_ZAPPER_3,
    /*  6 */ BOSSVA_BARI_UPPER_1,
    /*  7 */ BOSSVA_BARI_UPPER_2,
    /*  8 */ BOSSVA_BARI_UPPER_3,
    /*  9 */ BOSSVA_BARI_UPPER_4,
    /* 10 */ BOSSVA_BARI_UPPER_5,
    /* 11 */ BOSSVA_BARI_LOWER_1,
    /* 12 */ BOSSVA_BARI_LOWER_2,
    /* 13 */ BOSSVA_BARI_LOWER_3,
    /* 14 */ BOSSVA_BARI_LOWER_4,
    /* 15 */ BOSSVA_BARI_LOWER_5,
    /* 16 */ BOSSVA_STUMP_1,
    /* 17 */ BOSSVA_STUMP_2,
    /* 18 */ BOSSVA_STUMP_3,
    /* 19 */ BOSSVA_DOOR
};



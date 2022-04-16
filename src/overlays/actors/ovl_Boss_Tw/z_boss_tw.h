#pragma once
#define Z_BOSS_TW_H

#include "global.h"
#include "ultra64.h"

struct BossTw;

typedef void (*BossTwActionFunc)(BossTw* pthis, GlobalContext* globalCtx);

enum TwEffType
{
	/*  0 */ TWEFF_NONE,
	/*  1 */ TWEFF_DOT,
	/*  2 */ TWEFF_2,
	/*  3 */ TWEFF_3,
	/*  4 */ TWEFF_RING,
	/*  5 */ TWEFF_PLYR_FRZ,
	/*  6 */ TWEFF_FLAME,
	/*  7 */ TWEFF_MERGEFLAME,
	/*  8 */ TWEFF_SHLD_BLST,
	/*  9 */ TWEFF_SHLD_DEFL,
	/* 10 */ TWEFF_SHLD_HIT
};

enum TwinrovaType
{
	/* 0x00 */ TW_KOTAKE,
	/* 0x01 */ TW_KOUME,
	/* 0x02 */ TW_TWINROVA,
	/* 0x64 */ TW_FIRE_BLAST = 0x64,
	/* 0x65 */ TW_FIRE_BLAST_GROUND,
	/* 0x66 */ TW_ICE_BLAST,
	/* 0x67 */ TW_ICE_BLAST_GROUND,
	/* 0x68 */ TW_DEATHBALL_KOTAKE,
	/* 0x69 */ TW_DEATHBALL_KOUME
};

struct BossTwEffect
{
	/* 0x0000 */ u8 type;
	/* 0x0001 */ u8 frame;
	/* 0x0004 */ Vec3f pos;
	/* 0x0010 */ Vec3f curSpeed;
	/* 0x001C */ Vec3f accel;
	/* 0x0028 */ Color_RGB8 color;
	/* 0x002C */ s16 alpha;
	s16 EFF_ARGS;
	s16 EFF_UNKS1;
	f32 EFF_SCALE;
	f32 EFF_DIST;
	f32 EFF_ROLL;
	f32 EFF_YAW;
	/* 0x0044 */ Actor* target;
};
struct BossTw
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ BossTwActionFunc actionFunc;
	TimerS16 CS_TIMER_1;
	TimerS16 CS_TIMER_2;
	s16 TW_PLLR_IDX;
	s16 TAIL_IDX;
	s16 BLINK_IDX;
	TimerS16 INVINC_TIMER;
	TimerS16 FOG_TIMER;
	s16 CAN_SHOOT;
	s16 UNK_S8;
	TimerS16 TW_BLINK_IDX;
	s16 YAW_TGT;
	s16 PLAYED_CHRG_SFX;
	TimerS16 BURN_TMR;
	/* 0x0168 */ char unused_170[0xE]; // Likely unused Work variables
	/* 0x0178 */ Timer timers[5];
	f32 OUTR_CRWN_TX_X1;
	f32 OUTR_CRWN_TX_X2;
	f32 INNR_CRWN_TX_X1;
	f32 INNR_CRWN_TX_X2;
	f32 OUTR_CRWN_TX_Y1;
	f32 OUTR_CRWN_TX_Y2;
	f32 INNR_CRWN_TX_Y1;
	f32 INNR_CRWN_TX_Y2;
	f32 ANIM_SW_TGT;
	f32 UNK_F9;
	f32 KM_GD_FLM_A = 9;
	f32 UNK_F10 = 10;
	f32 TAIL_ALPHA = 10;
	f32 KM_GD_SMOKE_A = 10;
	f32 UNK_F11 = 11;
	f32 KM_GRND_CRTR_A = 11;
	f32 UNK_F12 = 12;
	f32 KM_GD_FLM_SCL = 12;
	f32 UNK_F13 = 13;
	f32 KM_GD_CRTR_SCL = 13;
	f32 UNK_F14;
	f32 UNK_F15;
	f32 UNK_F16;
	f32 UNK_F17;
	f32 UNK_F18;
	f32 UNK_F19;
	/* 0x01D4 */ f32 fogR;
	/* 0x01D8 */ f32 fogG;
	/* 0x01DC */ f32 fogB;
	/* 0x01E0 */ f32 fogNear;
	/* 0x01E4 */ f32 fogFar;
	/* 0x01E8 */ Vec3f blastTailPos[50];
	/* 0x0440 */ s16 csState1;
	/* 0x0444 */ Vec3f crownPos;
	/* 0x0450 */ Vec3f scepterFlamePos[5];
	/* 0x048C */ Vec3f beamOrigin;
	/* 0x0498 */ Vec3f leftScepterPos;
	/* 0x04A4 */ Vec3f rightScepterPos;
	/* 0x04B0 */ Vec3f targetPos;
	/* 0x04BC */ Vec3f groundBlastPos2;
	/* 0x04C8 */ f32 rotateSpeed;
	/* 0x04CC */ s16 eyeTexIdx;
	/* 0x04CE */ s16 leftEyeTexIdx;
	/* 0x04D0 */ f32 scepterAlpha;
	/* 0x04D4 */ f32 flameAlpha;
	/* 0x04D8 */ f32 spawnPortalAlpha;
	/* 0x04DC */ f32 unk_4DC;
	/* 0x04E0 */ f32 spawnPortalScale;
	/* 0x04E4 */ f32 updateRate1;
	/* 0x04E8 */ f32 flameRotation;
	/* 0x04EC */ f32 portalRotation;
	/* 0x04F0 */ f32 updateRate2;
	/* 0x04F4 */ u8 twinrovaStun;
	/* 0x04F8 */ f32 beamScale;
	/* 0x04FC */ s16 beamShootState;
	/* 0x0500 */ Vec3f groundBlastPos;
	/* 0x050C */ Vec3f beamReflectionOrigin;
	/* 0x0518 */ f32 beamPitch;
	/* 0x051C */ f32 beamYaw;
	/* 0x0520 */ f32 beamRoll;
	/* 0x0524 */ Vec3s magicDir;
	/* 0x052C */ f32 beamDist;
	/* 0x0530 */ Vec3f unk_530;
	/* 0x053C */ f32 beamReflectionPitch;
	/* 0x0540 */ f32 beamReflectionYaw;
	/* 0x0544 */ f32 unused_544;
	/* 0x0548 */ f32 beamReflectionDist;
	/* 0x054C */ Vec3f unk_54C;
	/* 0x0558 */ Vec3f unk_558;
	/* 0x0564 */ u8 visible;
	/* 0x0565 */ u8 blastActive;
	/* 0x0566 */ s16 blastType;
	/* 0x0568 */ SkelAnime skelAnime;
	/* 0x05AC */ ColliderCylinder collider;
	/* 0x05F8 */ u8 unk_5F8;
	/* 0x05F9 */ u8 unk_5F9;
	/* 0x05FA */ s16 csState2;
	/* 0x05FC */ s16 subCamId;
	/* 0x05FE */ Timer csSfxTimer;
	/* 0x0600 */ Vec3f subCamEye;
	/* 0x060C */ Vec3f subCamAt;
	/* 0x0618 */ char unused_618[0xC];
	/* 0x0624 */ Vec3f subCamEye2;
	/* 0x0630 */ Vec3f subCamAt2;
	/* 0x063C */ char unused_63C[0x18];
	/* 0x0654 */ Vec3f subCamEyeStep;
	/* 0x0660 */ Vec3f subCamAtStep;
	/* 0x066C */ Vec3f subCamEyeTarget;
	/* 0x0678 */ char unused_678[0xC];
	/* 0x0684 */ Vec3f subCamAtTarget;
	/* 0x0690 */ char unused_690[0xC];
	/* 0x069C */ f32 subCamUpdateRate;
	/* 0x06A0 */ f32 subCamDistStep;
	/* 0x06A4 */ f32 subCamDist;
	/* 0x06A8 */ char unused_6A8[4];
	/* 0x06AC */ f32 subCamYaw;
	/* 0x06B0 */ f32 subCamYawStep;
};

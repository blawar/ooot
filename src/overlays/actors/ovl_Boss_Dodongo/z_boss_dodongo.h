#pragma once
#define Z_BOSS_DODONGO_H

#include "global.h"
#include "ultra64.h"

struct BossDodongo;

typedef void (*BossDodongoActionFunc)(struct BossDodongo*, GlobalContext*);

struct BossDodongoEffect
{
	/* 0x00 */ Vec3f unk_00;
	/* 0x0C */ Vec3f unk_0C;
	/* 0x18 */ Vec3f unk_18;
	/* 0x24 */ u8 unk_24;
	/* 0x25 */ u8 unk_25;
	/* 0x26 */ Color_RGB8 color;
	/* 0x2A */ s16 alpha;
	/* 0x2C */ f32 unk_2C;
};

struct BossDodongo
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ SkelAnime skelAnime;
	/* 0x0190 */ BossDodongoActionFunc actionFunc;
	/* 0x0194 */ s16 health;
	/* 0x0196 */ TimerS16 timer1;//sound related?
	/* 0x0198 */ TimerS16 timer2;//sound related?
	/* 0x019C */ s16 csState;
	/* 0x019E */ TimerS16 lavaFloorTimer;//lava floor speed?
	/* 0x01A0 */ s16 unk_1A0;//corner related index?
	/* 0x01A2 */ s16 unk_1A2;
	/* 0x01A4 */ s16 unk_1A4;
	/* 0x01A6 */ s16 unk_1A6;
	/* 0x01A8 */ s16 numWallCollisions;
	/* 0x01AA */ u8 unk_1AA;//used as boolean
	/* 0x01AC */ TimerS16 eatExplosiveTimer;//eat explosive related?
	/* 0x01AE */ s16 fireBallParams;
	/* 0x01B2 */ char unk_1B2[0x2];
	/* 0x01B4 */ s16 cutsceneCamera;
	/* 0x01B6 */ TimerS16 cutsceneCameraBounceTimer;//cutscenecameratimer?
	/* 0x01B8 */ s16 playerYawInRange;
	/* 0x01BA */ s16 playerPosInRange;
	/* 0x01BC */ s16 walkingState;//walking state?
	/* 0x01BE */ TimerS16 colorFilterTransitionTimer;//color filter transition timer
	/* 0x01C0 */ TimerS16 whiteFlashFogTimer;//?unsure?
	/* 0x01C2 */ TimerS16 unk_1C2;//floor transition index
	/* 0x01C4 */ Rotation unk_1C4;//rolling timer
	/* 0x01C6 */ u8 unk_1C6;//used as a boolean
	/* 0x01C8 */ TimerS16 unk_1C8;//?unsure?fireball begining transition?
	/* 0x01CA */ char unk_1CA[0x2];
	/* 0x01CC */ s16 unk_1CC;//index
	/* 0x01CE */ char unk_1CE[0xC];
	/* 0x01DA */ TimerS16 blowFireTimer;
	/* 0x01E2 */ u8 unk_1E2;//health?
	/* 0x01E4 */ f32 unk_1E4;//position related
	/* 0x01E8 */ f32 unk_1E8;
	/* 0x01EC */ f32 unk_1EC;
	/* 0x01F0 */ char unk_1F0[0x8];
	/* 0x01F8 */ f32 unk_1F8;//laydown related?
	/* 0x0204 */ f32 unk_204;
	/* 0x0208 */ f32 unk_208;//limb rot scal
	/* 0x020C */ f32 unk_20C;
	/* 0x0210 */ f32 colorFilterR;
	/* 0x0214 */ f32 colorFilterG;
	/* 0x0214 */ f32 colorFilterB;
	/* 0x021C */ f32 colorFilterMin;
	/* 0x0220 */ f32 colorFilterMax;
	/* 0x0224 */ f32 floorTexTransitionMultiplier;
	/* 0x0228 */ f32 unk_228;
	/* 0x022C */ f32 unk_22C;
	/* 0x0230 */ f32 unk_230;
	/* 0x0234 */ f32 unk_234;		      // rotation inc?
	/* 0x0238 */ f32 endSceneCameraRotation;//endSceneCameraRotation?
	/* 0x023C */ f32 unk_23C;///groundRotation
	/* 0x0240 */ f32 unk_240;
	/* 0x0244 */ f32 unk_244;
	/* 0x0248 */ char unk_248[0x14];
	/* 0x025C */ f32 limbRot[50];
	/* 0x0324 */ f32 limbRndRot[50];
	/* 0x03EC */ Vec3f vec;
	/* 0x03F8 */ Vec3f firePos;
	/* 0x0404 */ Vec3f unk_404;
	/* 0x0410 */ Vec3f unk_410;
	/* 0x041C */ Vec3f mouthPos;
	/* 0x0428 */ Vec3f cameraEye;
	/* 0x0434 */ Vec3f cameraAt;
	/* 0x0440 */ ColliderJntSph collider;
	/* 0x0460 */ ColliderJntSphElement items[19];
	/* 0x0920 */ BossDodongoEffect effects[80];
};

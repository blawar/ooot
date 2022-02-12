#pragma once

#include "ultra64.h"
#include "ultra64/types.h"
#include "z64math.h"
#include "z64cutscene.h"
#include "z64bgcheck.h"

#define CAM_STAT_CUT        0
#define CAM_STAT_WAIT       1
#define CAM_STAT_UNK3       3
#define CAM_STAT_ACTIVE     7
#define CAM_STAT_UNK100     0x100

#define NUM_CAMS 4
#define MAIN_CAM 0
#define SUBCAM_FIRST 1
#define SUBCAM_FREE 0
#define SUBCAM_NONE -1
#define SUBCAM_ACTIVE -1

#define ONEPOINT_CS_INFO(camera) ((Unique9OnePointCs*)camera->paramData)
#define PARENT_CAM(cam) ((cam)->globalCtx->cameraPtrs[(cam)->parentCamIdx])
#define CHILD_CAM(cam) ((cam)->globalCtx->cameraPtrs[(cam)->childCamIdx])

enum CameraSettingType {
    /* 0x00 */ CAM_SET_NONE,
    /* 0x01 */ CAM_SET_NORMAL0,
    /* 0x02 */ CAM_SET_NORMAL1,
    /* 0x03 */ CAM_SET_DUNGEON0,
    /* 0x04 */ CAM_SET_DUNGEON1,
    /* 0x05 */ CAM_SET_NORMAL3,
    /* 0x06 */ CAM_SET_HORSE, // "HORSE0"
    /* 0x07 */ CAM_SET_BOSS_GOHMA, // "BOSS_GOMA" (unused)
    /* 0x08 */ CAM_SET_BOSS_DODONGO, // "BOSS_DODO" (unused)
    /* 0x09 */ CAM_SET_BOSS_BARINADE, // "BOSS_BARI" (unused)
    /* 0x0A */ CAM_SET_BOSS_PHANTOM_GANON, // "BOSS_FGANON"
    /* 0x0B */ CAM_SET_BOSS_VOLVAGIA, // "BOSS_BAL"
    /* 0x0C */ CAM_SET_BOSS_BONGO, // "BOSS_SHADES"
    /* 0x0D */ CAM_SET_BOSS_MORPHA, // "BOSS_MOFA" (unused)
    /* 0x0E */ CAM_SET_BOSS_TWINROVA_PLATFORM, // Upper main platform and 4 smaller platforms in the room of the Twinrova boss battle "TWIN0"
    /* 0x0F */ CAM_SET_BOSS_TWINROVA_FLOOR, // The floor in the room of the Twinrova boss battle "TWIN1"
    /* 0x10 */ CAM_SET_BOSS_GANONDORF, // "BOSS_GANON1"
    /* 0x11 */ CAM_SET_BOSS_GANON, // "BOSS_GANON2" (unused)
    /* 0x12 */ CAM_SET_TOWER_CLIMB, // Various climbing structures (collapse sequence stairs, spiral around sarias house, zora domain climb, etc...) "TOWER0"
    /* 0x13 */ CAM_SET_TOWER_UNUSED, // Unused but data is in Phantom Ganon's Lair (no surface uses it) "TOWER1"
    /* 0x14 */ CAM_SET_MARKET_BALCONY, // Activated in day child market by talking to NPC on balcony above bombchu bowling "FIXED0"
    /* 0x15 */ CAM_SET_CHU_BOWLING, // Fixes the camera to the bombchu bowling targets while playing the minigame "FIXED1"
    /* 0x16 */ CAM_SET_PIVOT_CRAWLSPACE, // Unknown. In scene data: closely associated with crawlspaces CIRCLE0"
    /* 0x17 */ CAM_SET_PIVOT_SHOP_BROWSING, // Shopping and browsing for items "CIRCLE2"
    /* 0x18 */ CAM_SET_PIVOT_IN_FRONT, // The camera used on Link's balcony in Kokiri forest. Data present in scene data for Deku Tree, GTG, Inside Ganon's Castle (TODO: may or may not be used) "CIRCLE3"
    /* 0x19 */ CAM_SET_PREREND_FIXED, // Camera is fixed in position and rotation "PREREND0"
    /* 0x1A */ CAM_SET_PREREND_PIVET, // Camera is fixed in position with fixed pitch, but is free to rotate in the yaw direction 360 degrees "PREREND1"
    /* 0x1B */ CAM_SET_PREREND_SIDE_SCROLL, // Camera side-scrolls position to follow link. Only used in castle courtyard with the guards "PREREND3"
    /* 0x1C */ CAM_SET_DOOR0, // Custom room door transitions, used in fire and royal family tomb
    /* 0x1D */ CAM_SET_DOORC, // Generic room door transitions, camera moves and follows player as the door is open and closed
    /* 0x1E */ CAM_SET_CRAWLSPACE, // Used in all crawlspaces "RAIL3"
    /* 0x1F */ CAM_SET_START0, // Data is given in Temple of Time, but no surface uses it
    /* 0x20 */ CAM_SET_START1, // Scene/room door transitions that snap the camera to a fixed location (example: ganon's towers doors climbing up)
    /* 0x21 */ CAM_SET_FREE0, // Full manual control is given over the camera 
    /* 0x22 */ CAM_SET_FREE2, // Various OnePoint Cutscenes, 10 total (example: falling chest)
    /* 0x23 */ CAM_SET_PIVOT_CORNER, // Inside the carpenter jail cells from theives hideout "CIRCLE4"
    /* 0x24 */ CAM_SET_PIVOT_WATER_SURFACE, // Player diving from the surface of the water to underwater "CIRCLE5"
    /* 0x25 */ CAM_SET_CS_0, // Various cutscenes "DEMO0"
    /* 0x26 */ CAM_SET_CS_TWISTED_HALLWAY, // Never set to, but checked in twisting hallway (Forest Temple) "DEMO1"
    /* 0x27 */ CAM_SET_FOREST_BIRDS_EYE, // Used in the falling ceiling room in forest temple "MORI1"
    /* 0x28 */ CAM_SET_SLOW_CHEST_CS, // Long cutscene when opening a big chest with a major item "ITEM0"
    /* 0x29 */ CAM_SET_ITEM_UNUSED, // Unused "ITEM1"
    /* 0x2A */ CAM_SET_CS_3, // Various cutscenes "DEMO3"
    /* 0x2B */ CAM_SET_CS_ATTENTION, // Attention cutscenes and the actor siofuki (water spout/jet) "DEMO4"
    /* 0x2C */ CAM_SET_BEAN_GENERIC, // All beans except lost woods "UFOBEAN"
    /* 0x2D */ CAM_SET_BEAN_LOST_WOODS, // Lost woods bean "LIFTBEAN"
    /* 0x2E */ CAM_SET_SCENE_UNUSED, // Unused "SCENE0"
    /* 0x2F */ CAM_SET_SCENE_TRANSITION, // Scene Transitions "SCENE1"
    /* 0x30 */ CAM_SET_FIRE_PLATFORM, // All the fire platforms that rise. Also used in non-mq spirit shortcut "HIDAN1"
    /* 0x31 */ CAM_SET_FIRE_STAIRCASE, // Used on fire staircase actor cutscene in shortcut room connecting vanilla hammer chest to the final goron small key "HIDAN2"
    /* 0x32 */ CAM_SET_FOREST_UNUSED, // Unused "MORI2"
    /* 0x33 */ CAM_SET_FOREST_DEFEAT_POE, // Used when defeating a poe sister "MORI3"
    /* 0x34 */ CAM_SET_BIG_OCTO, // Used by big octo miniboss in Jabu Jabu "TAKO"
    /* 0x35 */ CAM_SET_MEADOW_BIRDS_EYE, // Used only as child in Sacred Forest Meadow Maze "SPOT05A"
    /* 0x36 */ CAM_SET_MEADOW_UNUSED, // Unused from Sacred Forest Meadow "SPOT05B"
    /* 0x37 */ CAM_SET_FIRE_BIRDS_EYE, // Used in lower-floor maze in non-mq fire temple "HIDAN3"
    /* 0x38 */ CAM_SET_TURN_AROUND, // Put the camera in front of player and turn around to look at player from the front "ITEM2"
    /* 0x39 */ CAM_SET_PIVOT_VERTICAL, // Lowering platforms (forest temple bow room, Jabu final shortcut) "CAM_SET_PIVOT_VERTICAL"
    /* 0x3A */ CAM_SET_NORMAL2,
    /* 0x3B */ CAM_SET_FISHING, // Fishing pond by the lake
    /* 0x3C */ CAM_SET_CS_C, // Various cutscenes "DEMOC"
    /* 0x3D */ CAM_SET_JABU_TENTACLE, // Jabu-Jabu Parasitic Tenticle Rooms "UO_FIBER"
    /* 0x3E */ CAM_SET_DUNGEON2,
    /* 0x3F */ CAM_SET_DIRECTED_YAW, // Does not auto-update yaw, tends to keep the camera pointed at a certain yaw (used by biggoron and final spirit lowering platform) "TEPPEN"
    /* 0x40 */ CAM_SET_PIVOT_FROM_SIDE, // Fixed side view, allows rotation of camera (eg. Potion Shop, Meadow at fairy grotto) "CIRCLE7"
    /* 0x41 */ CAM_SET_NORMAL4,
    /* 0x42 */ CAM_SET_MAX
};

enum CameraModeType {
    /* 0x00 */ CAM_MODE_NORMAL,
    /* 0x01 */ CAM_MODE_TARGET, // "PARALLEL"
    /* 0x02 */ CAM_MODE_FOLLOWTARGET, // "KEEPON"
    /* 0x03 */ CAM_MODE_TALK,
    /* 0x04 */ CAM_MODE_BATTLE,
    /* 0x05 */ CAM_MODE_CLIMB,
    /* 0x06 */ CAM_MODE_FIRSTPERSON,  // "SUBJECT"
    /* 0x07 */ CAM_MODE_BOWARROW,
    /* 0x08 */ CAM_MODE_BOWARROWZ,
    /* 0x09 */ CAM_MODE_HOOKSHOT, // "FOOKSHOT"
    /* 0x0A */ CAM_MODE_BOOMERANG,
    /* 0x0B */ CAM_MODE_SLINGSHOT, // "PACHINCO"
    /* 0x0C */ CAM_MODE_CLIMBZ,
    /* 0x0D */ CAM_MODE_JUMP,
    /* 0x0E */ CAM_MODE_HANG,
    /* 0x0F */ CAM_MODE_HANGZ,
    /* 0x10 */ CAM_MODE_FREEFALL,
    /* 0x11 */ CAM_MODE_CHARGE,
    /* 0x12 */ CAM_MODE_STILL,
    /* 0x13 */ CAM_MODE_PUSHPULL,
    /* 0x14 */ CAM_MODE_FOLLOWBOOMERANG, // "BOOKEEPON"
    /* 0x15 */ CAM_MODE_MAX
};

enum CameraFuncType {
    /* 0x00 */ CAM_FUNC_NONE,
    /* 0x01 */ CAM_FUNC_NORM0,
    /* 0x02 */ CAM_FUNC_NORM1,
    /* 0x03 */ CAM_FUNC_NORM2,
    /* 0x04 */ CAM_FUNC_NORM3,
    /* 0x05 */ CAM_FUNC_NORM4,
    /* 0x06 */ CAM_FUNC_PARA0,
    /* 0x07 */ CAM_FUNC_PARA1,
    /* 0x08 */ CAM_FUNC_PARA2,
    /* 0x09 */ CAM_FUNC_PARA3,
    /* 0x0A */ CAM_FUNC_PARA4,
    /* 0x0B */ CAM_FUNC_KEEP0,
    /* 0x0C */ CAM_FUNC_KEEP1,
    /* 0x0D */ CAM_FUNC_KEEP2,
    /* 0x0E */ CAM_FUNC_KEEP3,
    /* 0x0F */ CAM_FUNC_KEEP4,
    /* 0x10 */ CAM_FUNC_SUBJ0,
    /* 0x11 */ CAM_FUNC_SUBJ1,
    /* 0x12 */ CAM_FUNC_SUBJ2,
    /* 0x13 */ CAM_FUNC_SUBJ3,
    /* 0x14 */ CAM_FUNC_SUBJ4,
    /* 0x15 */ CAM_FUNC_JUMP0,
    /* 0x16 */ CAM_FUNC_JUMP1,
    /* 0x17 */ CAM_FUNC_JUMP2,
    /* 0x18 */ CAM_FUNC_JUMP3,
    /* 0x19 */ CAM_FUNC_JUMP4,
    /* 0x1A */ CAM_FUNC_BATT0,
    /* 0x1B */ CAM_FUNC_BATT1,
    /* 0x1C */ CAM_FUNC_BATT2,
    /* 0x1D */ CAM_FUNC_BATT3,
    /* 0x1E */ CAM_FUNC_BATT4,
    /* 0x1F */ CAM_FUNC_FIXD0,
    /* 0x20 */ CAM_FUNC_FIXD1,
    /* 0x21 */ CAM_FUNC_FIXD2,
    /* 0x22 */ CAM_FUNC_FIXD3,
    /* 0x23 */ CAM_FUNC_FIXD4,
    /* 0x24 */ CAM_FUNC_DATA0,
    /* 0x25 */ CAM_FUNC_DATA1,
    /* 0x26 */ CAM_FUNC_DATA2,
    /* 0x27 */ CAM_FUNC_DATA3,
    /* 0x28 */ CAM_FUNC_DATA4,
    /* 0x29 */ CAM_FUNC_UNIQ0,
    /* 0x2A */ CAM_FUNC_UNIQ1,
    /* 0x2B */ CAM_FUNC_UNIQ2,
    /* 0x2C */ CAM_FUNC_UNIQ3,
    /* 0x2D */ CAM_FUNC_UNIQ4,
    /* 0x2E */ CAM_FUNC_UNIQ5,
    /* 0x2F */ CAM_FUNC_UNIQ6,
    /* 0x30 */ CAM_FUNC_UNIQ7,
    /* 0x31 */ CAM_FUNC_UNIQ8,
    /* 0x32 */ CAM_FUNC_UNIQ9,
    /* 0x33 */ CAM_FUNC_DEMO0,
    /* 0x34 */ CAM_FUNC_DEMO1,
    /* 0x35 */ CAM_FUNC_DEMO2,
    /* 0x36 */ CAM_FUNC_DEMO3,
    /* 0x37 */ CAM_FUNC_DEMO4,
    /* 0x38 */ CAM_FUNC_DEMO5,
    /* 0x39 */ CAM_FUNC_DEMO6,
    /* 0x3A */ CAM_FUNC_DEMO7,
    /* 0x3B */ CAM_FUNC_DEMO8,
    /* 0x3C */ CAM_FUNC_DEMO9,
    /* 0x3D */ CAM_FUNC_SPEC0,
    /* 0x3E */ CAM_FUNC_SPEC1,
    /* 0x3F */ CAM_FUNC_SPEC2,
    /* 0x40 */ CAM_FUNC_SPEC3,
    /* 0x41 */ CAM_FUNC_SPEC4,
    /* 0x42 */ CAM_FUNC_SPEC5,
    /* 0x43 */ CAM_FUNC_SPEC6,
    /* 0x44 */ CAM_FUNC_SPEC7,
    /* 0x45 */ CAM_FUNC_SPEC8,
    /* 0x46 */ CAM_FUNC_SPEC9,
    /* 0x47 */ CAM_FUNC_MAX
};

struct SwingAnimation {
    /* 0x00 */ Vec3f collisionClosePoint;
    /* 0x0C */ CollisionPoly* atEyePoly;
    /* 0x10 */ f32 swingUpdateRate;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 swingUpdateRateTimer;
}; // size = 0x1C

struct Normal1Anim {
    /* 0x00 */ SwingAnimation swing;
    /* 0x1C */ f32 yOffset;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s16 slopePitchAdj;
    /* 0x26 */ s16 swingYawTarget;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 startSwingTimer;
}; // size = 0x2C

struct Normal1 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distMin;
    /* 0x08 */ f32 distMax;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 fovTarget;
    /* 0x1C */ f32 atLERPScaleMax;
    /* 0x20 */ s16 pitchTarget;
    /* 0x22 */ s16 interfaceFlags;
    /* 0x24 */ Normal1Anim anim;
}; // size = 0x50

struct Normal2Anim {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s16 unk_28;
}; // size = 0x2A

struct Normal2 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 interfaceFlags;
    /* 0x20 */ Normal2Anim anim;
}; // size = 0x4A

struct Normal3Anim {
    /* 0x00 */ SwingAnimation swing;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s16 curPitch;
    /* 0x26 */ s16 yawUpdAmt;
    /* 0x28 */ s16 yawTimer;
    /* 0x2A */ s16 distTimer;
}; // size = 0x2C

struct Normal3 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distMin;
    /* 0x08 */ f32 distMax;
    /* 0x0C */ f32 yawUpdateSpeed;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 fovTarget;
    /* 0x18 */ f32 maxAtLERPScale;
    /* 0x1C */ s16 pitchTarget;
    /* 0x1E */ s16 interfaceFlags;
    /* 0x20 */ Normal3Anim anim;
}; // size = 0x4C

struct Parallel1Anim {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ f32 yTarget;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 yawTarget;
    /* 0x14 */ s16 pitchTarget;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 animTimer;
}; // size = 0x1A

struct Parallel1 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 distTarget;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 fovTarget;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 pitchTarget;
    /* 0x22 */ s16 yawTarget;
    /* 0x24 */ s16 interfaceFlags;
    /* 0x28 */ Parallel1Anim anim;
}; // size = 0x42

struct Jump1Anim {
    
    /* 0x00 */ SwingAnimation swing;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ VecSph unk_20;
}; // size = 0x28

struct Jump1 {
    /* 0x00 */ f32 atYOffset;
    /* 0x04 */ f32 distMin;
    /* 0x08 */ f32 distMax;
    /* 0x0C */ f32 yawUpateRateTarget;
    /* 0x10 */ f32 maxYawUpdate;
    /* 0x14 */ f32 unk_14; // never used.  
    /* 0x18 */ f32 atLERPScaleMax;
    /* 0x1C */ s16 interfaceFlags;
    /* 0x20 */ Jump1Anim anim;
}; // size = 0x48

struct Jump2Anim {
    /* 0x0 */ f32 floorY;
    /* 0x4 */ s16 yawTarget;
    /* 0x6 */ s16 initYawDiff; // unused, set but not read.
    /* 0x8 */ s16 yawAdj;
    /* 0xA */ s16 onFloor; // unused, set but not read
    /* 0xC */ s16 animTimer;
}; // size = 0x10

struct Jump2 {
    /* 0x00 */ f32 atYOffset;
    /* 0x04 */ f32 minDist;
    /* 0x08 */ f32 maxDist;
    /* 0x0C */ f32 minMaxDistFactor;
    /* 0x10 */ f32 yawUpdRateTarget;
    /* 0x14 */ f32 xzUpdRateTarget;
    /* 0x18 */ f32 fovTarget;
    /* 0x1C */ f32 atLERPStepScale;
    /* 0x20 */ s16 interfaceFlags;
    /* 0x24 */ Jump2Anim anim;
}; // size = 0x34

struct Jump3Anim {
    /* 0x00 */ SwingAnimation swing;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 animTimer;
    /* 0x22 */ s16 mode;
}; // size = 0x24

struct Jump3 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distMin;
    /* 0x08 */ f32 distMax;
    /* 0x0C */ f32 swingUpdateRate;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 fovTarget;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 pitchTarget;
    /* 0x22 */ s16 interfaceFlags;
    /* 0x24 */ Jump3Anim anim;
}; // size = 0x48

struct Battle1Anim {
    /* 0x00 */ f32 initialEyeToAtDist;
    /* 0x04 */ f32 roll;
    /* 0x08 */ f32 yPosOffset;
    /* 0x0C */ struct Actor* target;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14; // unused
    /* 0x16 */ s16 initialEyeToAtYaw;
    /* 0x18 */ s16 initialEyeToAtPitch;
    /* 0x1A */ s16 animTimer;
    /* 0x1C */ s16 chargeTimer;
}; // size = 0x1E

struct Battle1 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distance;
    /* 0x08 */ f32 swingYawInitial;
    /* 0x0C */ f32 swingYawFinal;
    /* 0x10 */ f32 swingPitchInitial;
    /* 0x14 */ f32 swingPitchFinal;
    /* 0x18 */ f32 swingPitchAdj;
    /* 0x1C */ f32 fov;
    /* 0x20 */ f32 atLERPScaleOnGround;
    /* 0x24 */ f32 yOffsetOffGround;
    /* 0x28 */ f32 atLERPScaleOffGround;
    /* 0x2C */ s16 flags;
    /* 0x30 */ Battle1Anim anim;
}; // size = 0x50

struct Battle4Anim {
    /* 0x0000 */ s16 animTimer;
}; // size = 0x2

struct Battle4 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 rTarget;
    /* 0x08 */ s16 pitchTarget;
    /* 0x0C */ f32 lerpUpdateRate;
    /* 0x10 */ f32 fovTarget;
    /* 0x14 */ f32 atLERPTarget;
    /* 0x18 */ s16 interfaceFlags;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ Battle4Anim anim;
}; // size = 0x20

struct Keep1Anim {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ struct Actor* unk_0C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
}; // size = 0x18

struct KeepOn1 {
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
    /* 0x30 */ s16 interfaceFlags;
    /* 0x34 */ Keep1Anim anim;
}; // size = 0x4C

struct Keep3Anim {
    /* 0x00 */ Vec3f eyeToAtTarget; // esentially a VecSph, but all floats.
    /* 0x0C */ struct Actor* target;
    /* 0x10 */ Vec3f atTarget;
    /* 0x1C */ s16 animTimer;
}; // size = 0x20

struct KeepOn3 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 minDist;
    /* 0x08 */ f32 maxDist;
    /* 0x0C */ f32 swingYawInital;
    /* 0x10 */ f32 swingYawFinal;
    /* 0x14 */ f32 swingPitchInitial;
    /* 0x18 */ f32 swingPitchFinal;
    /* 0x1C */ f32 swingPitchAdj;
    /* 0x20 */ f32 fovTarget;
    /* 0x24 */ f32 atLERPScaleMax;
    /* 0x28 */ s16 initTimer;
    /* 0x2A */ s16 flags;
    /* 0x2C */ Keep3Anim anim;
}; // size = 0x4C

struct KeepOn4_Unk20 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
}; // size = 0x14

struct KeepOn4 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ KeepOn4_Unk20 unk_20;
}; // size = 0x34

struct KeepOn0Anim {
    /* 0x0 */ f32 fovTarget;
    /* 0x4 */ s16 animTimer;
}; // size = 0x8

struct KeepOn0 {
    /* 0x00 */ f32 fovScale;
    /* 0x04 */ f32 yawScale;
    /* 0x08 */ s16 timerInit;
    /* 0x0A */ s16 interfaceFlags;
    /* 0x0C */ KeepOn0Anim anim;
}; // size = 0x14

struct Fixed1Anim {
    /* 0x00 */ PosRot eyePosRotTarget;
    /* 0x14 */ s16 fov;
}; // size = 0x18

struct Fixed1 {
    /* 0x00 */ f32 unk_00; // seems to be unused?
    /* 0x04 */ f32 lerpStep;
    /* 0x08 */ f32 fov;
    /* 0x0C */ s16 interfaceFlags;
    /* 0x10 */ Fixed1Anim anim;
}; // size = 0x28

struct Fixed2InitParams {
    /* 0x0 */ Vec3f eye;
    /* 0xC */ s16 fov;
}; // size = 0x10

struct Fixed2 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 eyeStepScale;
    /* 0x08 */ f32 posStepScale;
    /* 0x0C */ f32 fov;
    /* 0x10 */ s16 interfaceFlags;
    /* 0x14 */ Fixed2InitParams initParams;
}; // size = 0x24

struct Fixed3Anim {
    /* 0x0 */ Vec3s rot;
    /* 0x6 */ s16 fov;
    /* 0x8 */ s16 updDirTimer;
    /* 0xA */ s16 jfifId;
}; // size = 0xC

struct Fixed3 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Fixed3Anim anim;
}; // size = 0x10

struct Fixed4Anim {
    /* 0x0 */ Vec3f eyeTarget;
    /* 0xC */ f32 followSpeed;
}; // size = 0x10

struct Fixed4 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 speedToEyePos;
    /* 0x08 */ f32 followSpeed;
    /* 0x0C */ f32 fov;
    /* 0x10 */ s16 interfaceFlags;
    /* 0x14 */ Fixed4Anim anim;
}; // size = 0x24

struct Subj3Anim {
    /* 0x0 */ f32 r;
    /* 0x4 */ s16 yaw;
    /* 0x6 */ s16 pitch;
    /* 0x8 */ s16 animTimer;
}; // size = 0xC

struct Subj3 {
    /* 0x00 */ f32 eyeNextYOffset;
    /* 0x04 */ f32 eyeDist;
    /* 0x08 */ f32 eyeNextDist;
    /* 0x0C */ f32 unk_0C; // unused
    /* 0x10 */ Vec3f atOffset;
    /* 0x1C */ f32 fovTarget;
    /* 0x20 */ s16 interfaceFlags;
    /* 0x24 */ Subj3Anim anim;
}; // size = 0x30

struct Subj4Anim {
    /* 0x00 */ Linef unk_00;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
}; // size = 0x34

struct Subj4 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Subj4Anim anim;
}; // size = 0x38

struct Data4InitParams {
    /* 0x00 */ PosRot eyePosRot;
    /* 0x14 */ char unk_14[0x8];
    /* 0x1C */ s16 fov;
    /* 0x1E */ s16 jfifId;
}; // size = 0x20

struct Data4 {
    /* 0x0 */ f32 yOffset;
    /* 0x4 */ f32 fov;
    /* 0x8 */ s16 interfaceFlags;
    /* 0xC */ Data4InitParams initParams;
}; // size = 0x2C

struct Unique1Anim {
    /* 0x0 */ f32 unk_00; // unused
    /* 0x4 */ s16 yawTarget;
    /* 0x6 */ s16 yawTargetAdj;
    /* 0x8 */ s16 timer;
}; // size = 0xC

struct Unique1 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distMin;
    /* 0x08 */ f32 distMax;
    /* 0x0C */ char unk_0C[4]; // unused
    /* 0x10 */ f32 fovTarget;
    /* 0x14 */ f32 atLERPScaleMax;
    /* 0x18 */ s16 pitchTarget;
    /* 0x1A */ s16 interfaceFlags;
    /* 0x1C */ Unique1Anim anim;
}; // size = 0x28

struct Unique2Unk10 {
    /* 0x0 */ f32 unk_00;
    /* 0x4 */ s16 unk_04;
}; // size = 0x8

struct Unique2 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 distTarget;
    /* 0x08 */ f32 fovTarget;
    /* 0x0C */ s16 interfaceFlags;
    /* 0x10 */ Unique2Unk10 unk_10; // unused, values set but not read.
}; // size = 0x18

struct Unique3Anim {
    /* 0x0 */ f32 initialFov;
    /* 0x4 */ f32 initialDist;
}; // size = 0x8

struct Unique3Params {
    /* 0x0 */ f32 yOffset;
    /* 0x4 */ f32 fov;
    /* 0x8 */ s16 interfaceFlags;
}; // size = 0xC

struct DoorParams {
    /* 0x0 */ struct Actor* doorActor;
    /* 0x4 */ s16 camDataIdx;
    /* 0x6 */ s16 timer1;
    /* 0x8 */ s16 timer2;
    /* 0xA */ s16 timer3;
}; // size = 0xC

struct Unique3 {
    /* 0x00 */ DoorParams doorParams;
    /* 0x0C */ Unique3Params params;
    /* 0x18 */ Unique3Anim anim;
}; // size = 0x20

struct Unique0Anim {
    /* 0x00 */ Vec3f initalPos;
    /* 0x0C */ s16 animTimer;
    /* 0x10 */ Linef sceneCamPosPlayerLine;
}; // size = 0x28

struct Unique0Params {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Unique0Anim anim;
}; // size = 0x2C

struct Unique0 {
    /* 0x0 */ DoorParams doorParams;
    /* 0xC */ Unique0Params uniq0;
}; // size = 0x38

struct Unique6 {
    /* 0x0 */ s16 interfaceFlags;
}; // size = 0x4

union Unique7Unk8 {
    /* 0x0 */ Vec3s unk_00;
}; // size = 0x8

struct Unique7 {
    /* 0x0 */ f32 fov;
    /* 0x4 */ s16 interfaceFlags;
    /* 0x6 */ s16 align;
    /* 0x8 */ Unique7Unk8 unk_08; // unk_08 goes unused.
}; // size = 0x10

/** initFlags
 * & 0x00FF = atInitFlags
 * & 0xFF00 = eyeInitFlags
 * 0x1: Direct Copy of atTargetInit
 *      if initFlags & 0x6060: use head for focus point
 * 0x2: Add atTargetInit to view's lookAt
 *      if initFlags & 0x6060: use world for focus point
 * 0x3: Add atTargetInit to camera's at
 * 0x4: Don't update targets? 
 * 0x8: flag to use atTagetInit as f32 pitch, yaw, r
 * 0x10: ? unused
 * 0x20: focus on player
*/
struct OnePointCsFull {
    /* 0x00 */ u8 actionFlags;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 initFlags;
    /* 0x04 */ s16 timerInit;
    /* 0x06 */ s16 rollTargetInit;
    /* 0x08 */ f32 fovTargetInit;
    /* 0x0C */ f32 lerpStepScale;
    /* 0x10 */ Vec3f atTargetInit;
    /* 0x1C */ Vec3f eyeTargetInit;
}; /* size = 0x28 */

struct Unique9Anim {
    /* 0x00 */ OnePointCsFull* curKeyFrame;
    /* 0x04 */ Vec3f atTarget;
    /* 0x10 */ Vec3f eyeTarget;
    /* 0x1C */ Vec3f playerPos;
    /* 0x28 */ f32 fovTarget;
    /* 0x2C */ VecSph atEyeOffsetTarget;
    /* 0x34 */ s16 rollTarget;
    /* 0x36 */ s16 curKeyFrameIdx;
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 isNewKeyFrame;
    /* 0x3C */ s16 keyFrameTimer;
}; // size = 0x3E

struct Unique9 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Unique9Anim anim;
}; // size = 0x40

struct Unique9OnePointCs {
    /* 0x0 */ s32 keyFrameCnt;
    /* 0x4 */ OnePointCsFull* keyFrames;
    /* 0x8 */ Unique9 uniq9;
}; // size = 0x48

struct Demo1Anim {
    /* 0x0 */ f32 curFrame;
    /* 0x4 */ s16 keyframe;
}; // size = 0x14

struct Demo1 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Demo1Anim anim;
}; // size = 0x18

struct Demo3Anim {
    /* 0x00 */ Vec3f initialAt;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s16 animFrame;
    /* 0x12 */ s16 yawDir;
}; // size = 0x14

struct Demo3 {
    /* 0x0 */ f32 fov;
    /* 0x4 */ f32 unk_04; // unused
    /* 0x8 */ s16 interfaceFlags;
    /* 0xC */ Demo3Anim anim;
}; // size = 0x20

struct Demo6Anim {
    /* 0x0 */ s16 animTimer;
    /* 0x4 */ Vec3f atTarget;
}; // size = 0x10

struct Demo6 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ Demo6Anim anim; 
}; // size = 0x14

struct Demo9Anim {
    /* 0x0 */ f32 curFrame;
    /* 0x4 */ s16 keyframe;
    /* 0x6 */ s16 doLERPAt;
    /* 0x8 */ s16 finishAction;
    /* 0xA */ s16 animTimer;
}; // size = 0xC

struct Demo9 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Demo9Anim anim;
}; // size = 0x10

struct OnePointCsCamera {
    /* 0x0 */ CutsceneCameraPoint* atPoints;
    /* 0x4 */ CutsceneCameraPoint* eyePoints;
    /* 0x8 */ s16 actionParameters;
    /* 0xA */ s16 initTimer;
}; // size = 0xC

struct Demo9OnePointCs {
    /* 0x0 */ OnePointCsCamera onePointCs;
    /* 0xC */ Demo9 demo9;
}; // size = 0x1C

struct Special0 {
    /* 0x0 */ f32 lerpAtScale;
    /* 0x4 */ s16 interfaceFlags;
}; // size = 0x8

struct Special4 {
    /* 0x0 */ s16 initalTimer;
}; // size = 0x4

struct Special5Anim {
    /* 0x0 */ s16 animTimer;
}; // size = 0x4

struct Special5 {
    /* 0x00 */ f32 yOffset;
    /* 0x04 */ f32 eyeDist;
    /* 0x08 */ f32 minDistForRot;
    /* 0x0C */ f32 fovTarget;
    /* 0x10 */ f32 atMaxLERPScale;
    /* 0x14 */ s16 timerInit;
    /* 0x16 */ s16 pitch;
    /* 0x18 */ s16 interfaceFlags;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ Special5Anim anim;
}; // size = 0x20

struct Special7 {
    /* 0x0 */ s16 idx;
}; // size = 0x4

struct Special6Anim {
    /* 0x0 */ f32 initalPlayerY;
    /* 0x4 */ s16 animTimer;
}; // size = 0x8

struct Special6 {
    /* 0x0 */ s16 interfaceFlags;
    /* 0x4 */ Special6Anim anim;
}; // size = 0xC

struct Special9Anim {
    /* 0x0 */ s16 targetYaw;
}; // size = 0x2

struct Special9Params {
    /* 0x0 */ f32 yOffset;
    /* 0x4 */ f32 unk_04;
    /* 0x8 */ s16 interfaceFlags;
    /* 0xA */ s16 unk_0A;
    /* 0xC */ Special9Anim anim;
}; // size = 0x10

struct Special9 {
    /* 0x0 */ DoorParams doorParams;
    /* 0xC */ Special9Params params;
}; // size = 0x1C

struct CamColChk {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f norm;
    /* 0x18 */ CollisionPoly* poly;
    /* 0x1C */ VecSph sphNorm;
    /* 0x24 */ s32 bgId;
}; // size = 0x28

struct Camera {
    /* 0x000 */ char paramData[0x50];
    /* 0x050 */ Vec3f at;
    /* 0x05C */ Vec3f eye;
    /* 0x068 */ Vec3f up;
    /* 0x074 */ Vec3f eyeNext;
    /* 0x080 */ Vec3f skyboxOffset;
    /* 0x08C */ struct GlobalContext* globalCtx;
    /* 0x090 */ struct Player* player;
    /* 0x094 */ PosRot playerPosRot;
    /* 0x0A8 */ struct Actor* target;
    /* 0x0AC */ PosRot targetPosRot;
    /* 0x0C0 */ f32 rUpdateRateInv;
    /* 0x0C4 */ f32 pitchUpdateRateInv;
    /* 0x0C8 */ f32 yawUpdateRateInv;
    /* 0x0CC */ f32 xzOffsetUpdateRate;
    /* 0x0D0 */ f32 yOffsetUpdateRate;
    /* 0x0D4 */ f32 fovUpdateRate;
    /* 0x0D8 */ f32 xzSpeed;
    /* 0x0DC */ f32 dist;
    /* 0x0E0 */ f32 speedRatio;
    /* 0x0E4 */ Vec3f posOffset;
    /* 0x0F0 */ Vec3f playerPosDelta;
    /* 0x0FC */ f32 fov;
    /* 0x100 */ f32 atLERPStepScale;
    /* 0x104 */ f32 playerGroundY;
    /* 0x108 */ Vec3f floorNorm;
    /* 0x114 */ f32 waterYPos;
    /* 0x118 */ s32 waterPrevCamIdx;
    /* 0x11C */ s32 waterPrevCamSetting;
    /* 0x120 */ s32 waterQuakeId;
    /* 0x124 */ void* data0;
    /* 0x128 */ void* data1;
    /* 0x12C */ s16 data2;
    /* 0x12E */ s16 data3;
    /* 0x130 */ s16 uid;
    /* 0x132 */ char unk_132[2];
    /* 0x134 */ Vec3s inputDir;
    /* 0x13A */ Vec3s camDir;
    /* 0x140 */ s16 status;
    /* 0x142 */ s16 setting;
    /* 0x144 */ s16 mode;
    /* 0x146 */ s16 bgCheckId;
    /* 0x148 */ s16 camDataIdx;
    /* 0x14A */ s16 unk_14A;
    /* 0x14C */ s16 unk_14C;
    /* 0x14E */ s16 childCamIdx;
    /* 0x150 */ s16 unk_150;
    /* 0x152 */ s16 unk_152;
    /* 0x154 */ s16 prevSetting;
    /* 0x156 */ s16 nextCamDataIdx;
    /* 0x158 */ s16 nextBGCheckId;
    /* 0x15A */ s16 roll;
    /* 0x15C */ s16 paramFlags;
    /* 0x15E */ s16 animState;
    /* 0x160 */ s16 timer;
    /* 0x162 */ s16 parentCamIdx;
    /* 0x164 */ s16 thisIdx;
    /* 0x166 */ s16 prevCamDataIdx;
    /* 0x168 */ s16 csId;
    /* 0x16A */ s16 unk_16A;
}; // size = 0x16C

/**
 * Debug Camera
*/

struct DbCameraSub {
    /* 0x0000 */ s16 mode;
    /* 0x0002 */ s16 nFrames;
    /* 0x0004 */ s16 nPoints;
    /* 0x0006 */ s16 unkIdx;
    /* 0x0008 */ s16 unk_08;
    /* 0x000A */ s16 unk_0A;
    /* 0x000C */ s32 unk_0C; // bool: indicates position vs lookAt?
    /* 0x0010 */ char unk_10[0x14];
    /* 0x0024 */ CutsceneCameraPoint position[129];
    /* 0x0834 */ CutsceneCameraPoint lookAt[129];
    /* 0x1044 */ s16 demoCtrlMenu;
    /* 0x1046 */ s16 demoCtrlActionIdx; // e (?), s (save), l (load), c (clear)
    /* 0x1048 */ s16 demoCtrlToggleSwitch;
    /* 0x104A */ Vec3s unk_104A;
}; // size = 0x1050

struct DbCamera {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f at;
    /* 0x10 */ Vec3f eye;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C; // bool
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ f32 fov;
    /* 0x4C */ s16 roll;
    /* 0x4E */ char unk_4E[0x2];
    /* 0x50 */ f32 rollDegrees;
    /* 0x54 */ Vec3f unk_54;
    /* 0x60 */ Vec3f unk_60;
    /* 0x6C */ Vec3f unk_6C;
    /* 0x78 */ s16 unk_78;
    /* 0x7A */ s16 unk_7A;
    /* 0x7C */ DbCameraSub sub;
}; // size = 0x10CC

struct DbCameraCut {
    /* 0x00 */ char letter;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 mode;
    /* 0x04 */ CutsceneCameraPoint* position;
    /* 0x08 */ CutsceneCameraPoint* lookAt;
    /* 0x0C */ s16 nFrames;
    /* 0x0E */ s16 nPoints;
}; // size = 0x10

struct DbCameraAnim {
    /* 0x00 */ f32 curFrame;
    /* 0x04 */ f32 unk_04; // frame count?
    /* 0x08 */ s16 keyframe;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ Vec3f positionPos; // confusing name
    /* 0x1C */ Vec3f lookAtPos;
    /* 0x28 */ f32 roll;
    /* 0x2C */ f32 fov;
}; // size = 0x30

/*
void Camera_Init(Camera* camera, struct View* view, struct CollisionContext* colCtx, struct GlobalContext* globalCtx);
void Camera_InitPlayerSettings(Camera* camera, struct Player* player);
s16 Camera_ChangeStatus(Camera* camera, s16 status);
Vec3s Camera_Update(Camera* camera);
void Camera_Finish(Camera* camera);
s32 Camera_ChangeMode(Camera* camera, s16 mode);
s32 Camera_CheckValidMode(Camera* camera, s16 mode);
s32 Camera_ChangeSetting(Camera* camera, s16 setting);
s32 Camera_ChangeDataIdx(Camera* camera, s32 camDataIdx);
s16 Camera_GetInputDirYaw(Camera* camera);
Vec3s* Camera_GetCamDir(Vec3s* dir, Camera* camera);
s16 Camera_GetCamDirPitch(Camera* camera);
s16 Camera_GetCamDirYaw(Camera* camera);
s32 Camera_AddQuake(Camera* camera, s32 arg1, s16 y, s32 countdown);
s32 Camera_SetParam(Camera* camera, s32 param, void* value);
s32 func_8005AC48(Camera* camera, s16 arg1);
s16 func_8005ACFC(Camera* camera, s16 arg1);
s16 func_8005AD1C(Camera* camera, s16 arg1);
s32 Camera_ResetAnim(Camera* camera);
s32 Camera_SetCSParams(Camera* camera, CutsceneCameraPoint* atPoints, CutsceneCameraPoint* eyePoints, struct Player* player,
    s16 relativeToPlayer);
s32 Camera_ChangeDoorCam(Camera* camera, struct Actor* doorActor, s16 camDataIdx, f32 arg3, s16 timer1, s16 timer2,
    s16 timer3);
s32 Camera_Copy(Camera* dstCamera, Camera* srcCamera);
Vec3f* Camera_GetSkyboxOffset(Vec3f* dst, Camera* camera);
void Camera_SetCameraData(Camera* camera, s16 setDataFlags, void* data0, void* data1, s16 data2, s16 data3,
    UNK_TYPE arg6);
s32 func_8005B198(void);
s16 func_8005B1A4(Camera* camera);
*/

extern s32 gDbgCamEnabled;


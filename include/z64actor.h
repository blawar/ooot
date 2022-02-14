#pragma once

#include "z64dma.h"
#include "z64animation.h"
#include "z64math.h"
#include "z64collision_check.h"
#include "color.h"
#include "framerate.h"

#define ACTOR_NUMBER_MAX 200
#define INVISIBLE_ACTOR_MAX 20
#define AM_FIELD_SIZE 0x27A0
#define MASS_IMMOVABLE 0xFF // Cannot be pushed by OC collisions
#define MASS_HEAVY 0xFE // Can only be pushed by OC collisions with IMMOVABLE and HEAVY objects.

enum DynaPolyMoveFlag
{
    DPM_UNK = 0,
    DPM_PLAYER = 1,
    DPM_ENEMY = 2,
    DPM_UNK3 = 3
};

struct Actor;
struct GlobalContext;
struct Lights;

typedef void (*ActorFunc)(struct Actor*, struct GlobalContext*);
typedef void (*ActorShadowFunc)(struct Actor*, struct Lights*, struct GlobalContext*);
typedef u16 (*callback1_800343CC)(struct GlobalContext*, struct Actor*);
typedef s16 (*callback2_800343CC)(struct GlobalContext*, struct Actor*);

struct ActorEntry {
    /* 0x00 */ s16 id;
    /* 0x02 */ Vec3s pos;
    /* 0x08 */ Vec3s rot;
    /* 0x0E */ s16 params;
}; // size = 0x10

struct ActorInit {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 category; // Classifies actor and determines when it will update or draw
    /* 0x04 */ u32 flags;
    /* 0x08 */ s16 objectId;
    /* 0x0C */ u32 instanceSize;
    /* 0x10 */ ActorFunc init; // Constructor
    /* 0x14 */ ActorFunc destroy; // Destructor
    /* 0x18 */ ActorFunc update; // Update Function
    /* 0x1C */ ActorFunc draw; // Draw function
}; // size = 0x20

enum AllocType
{
    /* 0 */ ALLOCTYPE_NORMAL,
    /* 1 */ ALLOCTYPE_ABSOLUTE,
    /* 2 */ ALLOCTYPE_PERMANENT
};

struct ActorOverlay {
    /* 0x00 */ Pointer vromStart;
    /* 0x04 */ Pointer vromEnd;
    /* 0x08 */ Pointer vramStart;
    /* 0x0C */ Pointer vramEnd;
    /* 0x10 */ Pointer loadedRamAddr; // original name: "allocp"
    /* 0x14 */ ActorInit* initInfo;
    /* 0x18 */ const char* name;
    /* 0x1C */ u16 allocType;
    /* 0x1E */ s8 numLoaded; // original name: "clients"
}; // size = 0x20

struct DamageTable
{
    u8 table[32];
};

struct CollisionCheckInfoInit {
    /* 0x00 */ u8 health;
    /* 0x02 */ s16 cylRadius;
    /* 0x04 */ s16 cylHeight;
    /* 0x06 */ u8 mass;
};

struct CollisionCheckInfoInit2 {
    /* 0x00 */ u8 health;
    /* 0x02 */ s16 cylRadius;
    /* 0x04 */ s16 cylHeight;
    /* 0x06 */ s16 cylYShift;
    /* 0x08 */ u8 mass;
};

struct CollisionCheckInfo {
    /* 0x00 */ DamageTable* damageTable;
    /* 0x04 */ Vec3f displacement; // Amount to correct velocity (0x5C) by when colliding into a body
    /* 0x10 */ s16 cylRadius; // Used for various purposes
    /* 0x12 */ s16 cylHeight; // Used for various purposes
    /* 0x14 */ s16 cylYShift; // Unused. Purpose inferred from Cylinder16 and CollisionCheck_CylSideVsLineSeg
    /* 0x16 */ u8 mass; // Used to compute displacement for OC collisions
    /* 0x17 */ u8 health; // Note: some actors may use their own health variable instead of this one
    /* 0x18 */ u8 damage; // Amount to decrement health by
    /* 0x19 */ u8 damageEffect; // Stores what effect should occur when hit by a weapon
    /* 0x1A */ u8 atHitEffect; // Stores what effect should occur when AT connects with an AC
    /* 0x1B */ u8 acHitEffect; // Stores what effect should occur when AC is touched by an AT
}; // size = 0x1C

struct ActorShape {
    /* 0x00 */ Vec3s rot; // Current actor shape rotation
    /* 0x06 */ s16 face; // Used to index eyebrow/eye/mouth textures. Only used by player
    /* 0x08 */ f32 yOffset; // Model y axis offset. Represents model space units
    /* 0x0C */ ActorShadowFunc shadowDraw; // Shadow draw function
    /* 0x10 */ f32 shadowScale; // Changes the size of the shadow
    /* 0x14 */ u8 shadowAlpha; // Default is 255
    /* 0x15 */ u8 feetFloorFlags; // Set if the actor's foot is clipped under the floor. & 1 is right foot, & 2 is left
    /* 0x18 */ Vec3f feetPos[2]; // Update by using `Actor_SetFeetPos` in PostLimbDraw
}; // size = 0x30

#define ACTOR_FLAG_0 (1 << 0)
#define ACTOR_FLAG_2 (1 << 2)
#define ACTOR_FLAG_3 (1 << 3)
#define ACTOR_FLAG_4 (1 << 4)
#define ACTOR_FLAG_5 (1 << 5)
#define ACTOR_FLAG_UNCULLED (1 << 6)
#define ACTOR_FLAG_7 (1 << 7)
#define ACTOR_FLAG_8 (1 << 8)
#define ACTOR_FLAG_9 (1 << 9)
#define ACTOR_FLAG_10 (1 << 10)
#define ACTOR_FLAG_11 (1 << 11)
#define ACTOR_FLAG_12 (1 << 12)
#define ACTOR_FLAG_13 (1 << 13)
#define ACTOR_FLAG_14 (1 << 14)
#define ACTOR_FLAG_15 (1 << 15)
#define ACTOR_FLAG_16 (1 << 16)
#define ACTOR_FLAG_17 (1 << 17)
#define ACTOR_FLAG_18 (1 << 18)
#define ACTOR_FLAG_19 (1 << 19)
#define ACTOR_FLAG_20 (1 << 20)
#define ACTOR_FLAG_21 (1 << 21)
#define ACTOR_FLAG_22 (1 << 22)
#define ACTOR_FLAG_23 (1 << 23)
#define ACTOR_FLAG_24 (1 << 24)
#define ACTOR_FLAG_25 (1 << 25)
#define ACTOR_FLAG_26 (1 << 26)
#define ACTOR_FLAG_27 (1 << 27)
#define ACTOR_FLAG_28 (1 << 28)

struct Actor {
    /* 0x000 */ s16 id; // Actor ID
    /* 0x002 */ u8 category; // Actor category. Refer to the corresponding enum for values
    /* 0x003 */ s8 room; // Room number the actor is in. -1 denotes that the actor won't despawn on a room change
    /* 0x004 */ u32 flags; // Flags used for various purposes
    /* 0x008 */ PosRot home; // Initial position/rotation when spawned. Can be used for other purposes
    /* 0x01C */ s16 params; // Configurable variable set by the actor's spawn data; original name: "args_data"
    /* 0x01E */ s32 objBankIndex; // Object bank index of the actor's object dependency; original name: "bank"
    /* 0x01F */ s8 targetMode; // Controls how far the actor can be targeted from and how far it can stay locked on
    /* 0x020 */ u16 sfx; // SFX ID to play. Sound plays when value is set, then is cleared the following update cycle
    /* 0x024 */ PosRot world; // Position/rotation in the world
    /* 0x038 */ PosRot focus; // Target reticle focuses on this position. For player this represents head pos and rot
    /* 0x04C */ f32 targetArrowOffset; // Height offset of the target arrow relative to `focus` position
    /* 0x050 */ Vec3f scale; // Scale of the actor in each axis
    /* 0x05C */ Vec3f velocity; // Velocity of the actor in each axis
    /* 0x068 */ f32 speedXZ; // How fast the actor is traveling along the XZ plane
    /* 0x06C */ f32 gravity; // Acceleration due to gravity. Value is added to Y velocity every frame
    /* 0x070 */ f32 minVelocityY; // Sets the lower bounds cap on velocity along the Y axis
    /* 0x074 */ struct CollisionPoly* wallPoly; // Wall polygon the actor is touching
    /* 0x078 */ struct CollisionPoly* floorPoly; // Floor polygon directly below the actor
    /* 0x07C */ u8 wallBgId; // Bg ID of the wall polygon the actor is touching
    /* 0x07D */ u8 floorBgId; // Bg ID of the floor polygon directly below the actor
    /* 0x07E */ s16 wallYaw; // Y rotation of the wall polygon the actor is touching
    /* 0x080 */ f32 floorHeight; // Y position of the floor polygon directly below the actor
    /* 0x084 */ f32 yDistToWater; // Distance to the surface of active waterbox. Negative value means above water
    /* 0x088 */ u16 bgCheckFlags; // See comments below actor struct for wip docs. TODO: macros for these flags
    /* 0x08A */ s16 yawTowardsPlayer; // Y rotation difference between the actor and the player
    /* 0x08C */ f32 xyzDistToPlayerSq; // Squared distance between the actor and the player in the x,y,z axis
    /* 0x090 */ f32 xzDistToPlayer; // Distance between the actor and the player in the XZ plane
    /* 0x094 */ f32 yDistToPlayer; // Dist is negative if the actor is above the player
    /* 0x098 */ CollisionCheckInfo colChkInfo; // Variables related to the Collision Check system
    /* 0x0B4 */ ActorShape shape; // Variables related to the physical shape of the actor
    /* 0x0E4 */ Vec3f projectedPos; // Position of the actor in projected space
    /* 0x0F0 */ f32 projectedW; // w component of the projected actor position
    /* 0x0F4 */ f32 uncullZoneForward; // Amount to increase the uncull zone forward by (in projected space)
    /* 0x0F8 */ f32 uncullZoneScale; // Amount to increase the uncull zone scale by (in projected space)
    /* 0x0FC */ f32 uncullZoneDownward; // Amount to increase uncull zone downward by (in projected space)
    /* 0x100 */ Vec3f prevPos; // World position from the previous update cycle
    /* 0x10C */ u8 isTargeted; // Set to true if the actor is currently being targeted by the player
    /* 0x10D */ u8 targetPriority; // Lower values have higher priority. Resets to 0 when player stops targeting
    /* 0x10E */ u16 textId; // Text ID to pass to link/display when interacting with the actor
    /* 0x110 */ u16 freezeTimer; // Actor does not update when set. Timer decrements automatically
    /* 0x112 */ u16 colorFilterParams; // Set color filter to red, blue, or white. Toggle opa or xlu
    /* 0x114 */ u8 colorFilterTimer; // A non-zero value enables the color filter. Decrements automatically
    /* 0x115 */ u8 isDrawn; // Set to true if the actor is currently being drawn. Always stays false for lens actors
    /* 0x116 */ u8 dropFlag; // Configures what item is dropped by the actor from `Item_DropCollectibleRandom`
    /* 0x117 */ u8 naviEnemyId; // Sets what 0600 dialog to display when talking to navi. Default 0xFF
    /* 0x118 */ struct Actor* parent; // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x11C */ struct Actor* child; // Usage is actor specific. Set if actor is spawned via `Actor_SpawnAsChild`
    /* 0x120 */ struct Actor* prev; // Previous actor of this category
    /* 0x124 */ struct Actor* next; // Next actor of this category
    /* 0x128 */ ActorFunc init; // Initialization Routine. Called by `Actor_Init` or `Actor_UpdateAll`
    /* 0x12C */ ActorFunc destroy; // Destruction Routine. Called by `Actor_Destroy`
    /* 0x130 */ ActorFunc update; // Update Routine. Called by `Actor_UpdateAll`
    /* 0x134 */ ActorFunc draw; // Draw Routine. Called by `Actor_Draw`
    /* 0x138 */ ActorOverlay* overlayEntry; // Pointer to the overlay table entry for this actor
    /* 0x13C */ char dbgPad[0x10]; // Padding that only exists in the debug rom
}; // size = 0x14C

enum ActorFootIndex
{
    /* 0 */ FOOT_LEFT,
    /* 1 */ FOOT_RIGHT
};

/*
BgCheckFlags WIP documentation:
& 0x001 : Standing on the ground
& 0x002 : Has touched the ground (only active for 1 frame)
& 0x004 : Has left the ground (only active for 1 frame)
& 0x008 : Touching a wall
& 0x010 : Touching a ceiling
& 0x020 : On or below water surface
& 0x040 : Has touched water (actor is responsible for unsetting this the frame it touches the water)
& 0x080 : Similar to & 0x1 but with no velocity check and is cleared every frame
& 0x100 : Crushed between a floor and ceiling (triggers a void for player)
& 0x200 : Unknown (only set/used by player so far)
*/

/*
colorFilterParams WIP documentation
& 0x8000 : white
& 0x4000 : red
if neither of the above are set : blue

(& 0x1F00 >> 5) | 7 : color intensity
0x2000 : translucent, else opaque
*/

struct DynaPolyActor {
    /* 0x000 */ struct Actor actor;
    /* 0x14C */ s32 bgId;
    /* 0x150 */ f32 unk_150;
    /* 0x154 */ f32 unk_154;
    /* 0x158 */ s16 unk_158; // y rotation?
    /* 0x15A */ u16 unk_15A;
    /* 0x15C */ u32 unk_15C;
    /* 0x160 */ u8 unk_160;
    /* 0x162 */ s16 unk_162;
}; // size = 0x164

struct BodyBreak {
    /* 0x00 */ MtxF* matrices;
    /* 0x04 */ s16* objectIds;
    /* 0x08 */ s16 count;
    /* 0x0C */ Gfx** dLists;
    /* 0x10 */ s32 val; // used for various purposes: both a status indicator and counter
    /* 0x14 */ s32 prevLimbIndex;
};

#define BODYBREAK_OBJECT_DEFAULT -1 // use the same object as the actor
#define BODYBREAK_STATUS_READY -1
#define BODYBREAK_STATUS_FINISHED 0

enum Item00Type
{
    /* 0x00 */ ITEM00_RUPEE_GREEN,
    /* 0x01 */ ITEM00_RUPEE_BLUE,
    /* 0x02 */ ITEM00_RUPEE_RED,
    /* 0x03 */ ITEM00_HEART,
    /* 0x04 */ ITEM00_BOMBS_A,
    /* 0x05 */ ITEM00_ARROWS_SINGLE,
    /* 0x06 */ ITEM00_HEART_PIECE,
    /* 0x07 */ ITEM00_HEART_CONTAINER,
    /* 0x08 */ ITEM00_ARROWS_SMALL,
    /* 0x09 */ ITEM00_ARROWS_MEDIUM,
    /* 0x0A */ ITEM00_ARROWS_LARGE,
    /* 0x0B */ ITEM00_BOMBS_B,
    /* 0x0C */ ITEM00_NUTS,
    /* 0x0D */ ITEM00_STICK,
    /* 0x0E */ ITEM00_MAGIC_LARGE,
    /* 0x0F */ ITEM00_MAGIC_SMALL,
    /* 0x10 */ ITEM00_SEEDS,
    /* 0x11 */ ITEM00_SMALL_KEY,
    /* 0x12 */ ITEM00_FLEXIBLE,
    /* 0x13 */ ITEM00_RUPEE_ORANGE,
    /* 0x14 */ ITEM00_RUPEE_PURPLE,
    /* 0x15 */ ITEM00_SHIELD_DEKU,
    /* 0x16 */ ITEM00_SHIELD_HYLIAN,
    /* 0x17 */ ITEM00_TUNIC_ZORA,
    /* 0x18 */ ITEM00_TUNIC_GORON,
    /* 0x19 */ ITEM00_BOMBS_SPECIAL
};

struct EnItem00;

typedef void (*EnItem00ActionFunc)(struct EnItem00*, struct GlobalContext*);

struct EnItem00 {
    /* 0x000 */ Actor actor;
    /* 0x14C */ EnItem00ActionFunc actionFunc;
    /* 0x150 */ s16 collectibleFlag;
    /* 0x152 */ s16 getItemId;
    /* 0x154 */ s16 unk_154;
    /* 0x156 */ s16 unk_156;
    /* 0x158 */ s16 unk_158;
    /* 0x15A */ s16 unk_15A;
    /* 0x15C */ f32 scale;
    /* 0x160 */ ColliderCylinder collider;
}; // size = 0x1AC

// Only A_OBJ_SIGNPOST_OBLONG and A_OBJ_SIGNPOST_ARROW are used in room files.
enum AObjType
{
    /* 0x00 */ A_OBJ_BLOCK_SMALL,
    /* 0x01 */ A_OBJ_BLOCK_LARGE,
    /* 0x02 */ A_OBJ_BLOCK_HUGE,
    /* 0x03 */ A_OBJ_BLOCK_SMALL_ROT,
    /* 0x04 */ A_OBJ_BLOCK_LARGE_ROT,
    /* 0x05 */ A_OBJ_CUBE_SMALL,
    /* 0x06 */ A_OBJ_UNKNOWN_6,
    /* 0x07 */ A_OBJ_GRASS_CLUMP,
    /* 0x08 */ A_OBJ_TREE_STUMP,
    /* 0x09 */ A_OBJ_SIGNPOST_OBLONG,
    /* 0x0A */ A_OBJ_SIGNPOST_ARROW,
    /* 0x0B */ A_OBJ_BOULDER_FRAGMENT,
    /* 0x0C */ A_OBJ_MAX
};

struct EnAObj;

typedef void (*EnAObjActionFunc)(struct EnAObj*, struct GlobalContext*);

struct EnAObj {
    /* 0x000 */ DynaPolyActor dyna;
    /* 0x164 */ EnAObjActionFunc actionFunc;
    /* 0x168 */ s32 rotateWaitTimer;
    /* 0x16C */ s16 textId;
    /* 0x16E */ s16 rotateState;
    /* 0x170 */ s16 rotateForTimer;
    /* 0x172 */ s16 rotSpeedY;
    /* 0x174 */ s16 rotSpeedX;
    /* 0x178 */ f32 focusYoffset;
    /* 0x17C */ ColliderCylinder collider;
}; // size = 0x1C8

enum ActorCategory
{
    /* 0x00 */ ACTORCAT_SWITCH,
    /* 0x01 */ ACTORCAT_BG,
    /* 0x02 */ ACTORCAT_PLAYER,
    /* 0x03 */ ACTORCAT_EXPLOSIVE,
    /* 0x04 */ ACTORCAT_NPC,
    /* 0x05 */ ACTORCAT_ENEMY,
    /* 0x06 */ ACTORCAT_PROP,
    /* 0x07 */ ACTORCAT_ITEMACTION,
    /* 0x08 */ ACTORCAT_MISC,
    /* 0x09 */ ACTORCAT_BOSS,
    /* 0x0A */ ACTORCAT_DOOR,
    /* 0x0B */ ACTORCAT_CHEST
};

#define DEFINE_ACTOR(_0, enum, _2) enum,
#define DEFINE_ACTOR_INTERNAL(_0, enum, _2) enum,
#define DEFINE_ACTOR_UNSET(enum) enum,

enum ActorID {
    #include "tables/actor_table.h"
    /* 0x0192 */ ACTOR_ID_MAX // originally "ACTOR_DLF_MAX"
};

#undef DEFINE_ACTOR
#undef DEFINE_ACTOR_INTERNAL
#undef DEFINE_ACTOR_UNSET

enum DoorLockType {
    DOORLOCK_NORMAL,
    DOORLOCK_BOSS,
    DOORLOCK_NORMAL_SPIRIT
};

struct TargetContextEntry {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 unk_0C; // radius?
    /* 0x10 */ Color_RGB8 color;
}; // size = 0x14

struct TitleCardContext {
    /* 0x00 */ void* texture;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ u8 width;
    /* 0x09 */ u8 height;
    /* 0x0A */ u8 durationTimer; // how long the title card appears for before fading
    /* 0x0B */ u8 delayTimer;    // how long the title card waits to appear
    /* 0x0C */ s16 alpha;
    /* 0x0E */ s16 intensity;
}; // size = 0x10

struct TargetContext {
    /* 0x00 */ Vec3f naviRefPos; // possibly wrong
    /* 0x0C */ Vec3f targetCenterPos;
    /* 0x18 */ Color_RGBAf naviInner;
    /* 0x28 */ Color_RGBAf naviOuter;
    /* 0x38 */ Actor* arrowPointedActor;
    /* 0x3C */ Actor* targetedActor;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ u8 activeCategory;
    /* 0x4B */ u8 unk_4B;
    /* 0x4C */ s8 unk_4C;
    /* 0x4D */ char unk_4D[0x03];
    /* 0x50 */ TargetContextEntry arr_50[3];
    /* 0x8C */ Actor* unk_8C;
    /* 0x90 */ Actor* bgmEnemy; // The nearest enemy to player with the right flags that will trigger NA_BGM_ENEMY
    /* 0x94 */ Actor* unk_94;
}; // size = 0x98

struct ActorListEntry {
    /* 0x00 */ s32 length;  // number of actors loaded of this category
    /* 0x04 */ Actor* head; // pointer to head of the linked list of this category (most recent actor added)
};           // size = 0x08

struct ActorContext
{
    /* 0x0000 */ u8 freezeFlashTimer;
    /* 0x0001 */ char unk_01[0x01];
    /* 0x0002 */ u8 unk_02;
    /* 0x0003 */ u8 unk_03;
    /* 0x0004 */ char unk_04[0x04];
    /* 0x0008 */ u8 total; // total number of actors loaded
    /* 0x0009 */ char unk_09[0x03];
    /* 0x000C */ ActorListEntry actorLists[12];
    /* 0x006C */ TargetContext targetCtx;
    struct {
        /* 0x0104 */ u32 swch;
        /* 0x0108 */ u32 tempSwch;
        /* 0x010C */ u32 unk0;
        /* 0x0110 */ u32 unk1;
        /* 0x0114 */ u32 chest;
        /* 0x0118 */ u32 clear;
        /* 0x011C */ u32 tempClear;
        /* 0x0120 */ u32 collect;
        /* 0x0124 */ u32 tempCollect;
    } flags;
    /* 0x0128 */ TitleCardContext titleCtx;
    /* 0x0138 */ char unk_138[0x04];
    /* 0x013C */ void* absoluteSpace; // Space used to allocate actor overlays of alloc type 1
};                       // size = 0x140

struct struct_80034A14_arg1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Vec3s unk_08;
    /* 0x0E */ Vec3s unk_0E;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ s16 unk_24;
}; // size = 0x28


// Some animation related structure
struct struct_80034EC0_Entry {
    /* 0x00 */ AnimationHeader* animation;
    /* 0x04 */ f32 playbackSpeed;
    /* 0x08 */ f32 startFrame;
    /* 0x0C */ f32 frameCount;
    /* 0x10 */ u8 mode;
    /* 0x14 */ f32 transitionRate;
}; // size = 0x18

// Another animation related structure
struct struct_D_80AA1678 {
    /* 0x00 */ AnimationHeader* animation;
    /* 0x04 */ f32 frameCount;
    /* 0x08 */ u8 mode;
    /* 0x0C */ f32 transitionRate;
}; // size = 0x10

/*
void ActorShape_Init(ActorShape* shape, f32 yOffset, ActorShadowFunc shadowDraw, f32 shadowScale);
void ActorShadow_DrawCircle(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
void ActorShadow_DrawWhiteCircle(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
void ActorShadow_DrawHorse(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
void ActorShadow_DrawFeet(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
void Actor_SetFeetPos(Actor* actor, s32 limbIndex, s32 leftFootIndex, Vec3f* leftFootPos, s32 rightFootIndex,
    Vec3f* rightFootPos);
void func_8002BE04(struct GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2, f32* arg3);
void func_8002C124(TargetContext* targetCtx, struct GlobalContext* globalCtx);
s32 Flags_GetSwitch(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetSwitch(struct GlobalContext* globalCtx, s32 flag);
void Flags_UnsetSwitch(struct GlobalContext* globalCtx, s32 flag);
s32 Flags_GetUnknown(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetUnknown(struct GlobalContext* globalCtx, s32 flag);
void Flags_UnsetUnknown(struct GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTreasure(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetTreasure(struct GlobalContext* globalCtx, s32 flag);
s32 Flags_GetClear(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetClear(struct GlobalContext* globalCtx, s32 flag);
void Flags_UnsetClear(struct GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTempClear(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetTempClear(struct GlobalContext* globalCtx, s32 flag);
void Flags_UnsetTempClear(struct GlobalContext* globalCtx, s32 flag);
s32 Flags_GetCollectible(struct GlobalContext* globalCtx, s32 flag);
void Flags_SetCollectible(struct GlobalContext* globalCtx, s32 flag);
void TitleCard_InitBossName(struct GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, s16 x, s16 y, u8 width,
    u8 height);
void TitleCard_InitPlaceName(struct GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, s32 x, s32 y,
    s32 width, s32 height, s32 delay);
s32 func_8002D53C(struct GlobalContext* globalCtx, TitleCardContext* titleCtx);
void Actor_Kill(Actor* actor);
void Actor_SetFocus(Actor* actor, f32 offset);
void Actor_SetScale(Actor* actor, f32 scale);
void Actor_SetObjectDependency(struct GlobalContext* globalCtx, Actor* actor);
void func_8002D7EC(Actor* actor);
void func_8002D868(Actor* actor);
void Actor_MoveForward(Actor* actor);
void func_8002D908(Actor* actor);
void func_8002D97C(Actor* actor);
void func_8002D9A4(Actor* actor, f32 arg1);
s16 Actor_WorldYawTowardActor(Actor* actorA, Actor* actorB);
s16 Actor_WorldYawTowardPoint(Actor* actor, Vec3f* refPoint);
f32 Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB);
f32 Actor_WorldDistXYZToPoint(Actor* actor, Vec3f* refPoint);
s16 Actor_WorldPitchTowardActor(Actor* actorA, Actor* actorB);
s16 Actor_WorldPitchTowardPoint(Actor* actor, Vec3f* refPoint);
f32 Actor_WorldDistXZToActor(Actor* actorA, Actor* actorB);
f32 Actor_WorldDistXZToPoint(Actor* actor, Vec3f* refPoint);
void func_8002DBD0(Actor* actor, Vec3f* result, Vec3f* arg2);
f32 Actor_HeightDiff(Actor* actorA, Actor* actorB);

f32 func_8002DCE4(struct Player* player);
s32 func_8002DD6C(struct Player* player);
s32 func_8002DD78(struct Player* player);
s32 func_8002DDE4(struct GlobalContext* globalCtx);
s32 func_8002DDF4(struct GlobalContext* globalCtx);
void func_8002DE04(struct GlobalContext* globalCtx, Actor* actorA, Actor* actorB);
void func_8002DE74(struct GlobalContext* globalCtx, struct Player* player);
void Actor_MountHorse(struct GlobalContext* globalCtx, struct Player* player, Actor* horse);
s32 func_8002DEEC(struct Player* player);
void func_8002DF18(struct GlobalContext* globalCtx, struct Player* player);
s32 func_8002DF38(struct GlobalContext* globalCtx, Actor* actor, u8 csMode);
s32 func_8002DF54(struct GlobalContext* globalCtx, Actor* actor, u8 arg2);
void func_8002DF90(DynaPolyActor* dynaActor);
void func_8002DFA4(DynaPolyActor* dynaActor, f32 arg1, s16 arg2);

s32 Actor_ActorBIsFacingActorA(Actor* actorA, Actor* actorB, s16 angle);
s32 Actor_IsFacingPlayer(Actor* actor, s16 angle);
s32 Actor_ActorAIsFacingActorB(Actor* actorA, Actor* actorB, s16 angle);
s32 Actor_IsFacingAndNearPlayer(Actor* actor, f32 range, s16 angle);
s32 Actor_ActorAIsFacingAndNearActorB(Actor* actorA, Actor* actorB, f32 range, s16 angle);
void Actor_UpdateBgCheckInfo(struct GlobalContext* globalCtx, Actor* actor, f32 wallCheckHeight, f32 wallCheckRadius,
    f32 ceilingCheckHeight, s32 flags);
Hilite* func_8002EABC(Vec3f* object, Vec3f* eye, Vec3f* lightDir, struct GraphicsContext* gfxCtx);
Hilite* func_8002EB44(Vec3f* object, Vec3f* eye, Vec3f* lightDir, struct GraphicsContext* gfxCtx);
void func_8002EBCC(Actor* actor, struct GlobalContext* globalCtx, s32 flag);
void func_8002ED80(Actor* actor, struct GlobalContext* globalCtx, s32 flag);
PosRot* Actor_GetFocus(PosRot* arg0, Actor* actor);
PosRot* Actor_GetWorld(PosRot* arg0, Actor* actor);
PosRot* Actor_GetWorldPosShapeRot(PosRot* arg0, Actor* actor);
s32 func_8002F0C8(Actor* actor, struct Player* player, s32 arg2);
u32 Actor_ProcessTalkRequest(Actor* actor, struct GlobalContext* globalCtx);
s32 func_8002F1C4(Actor* actor, struct GlobalContext* globalCtx, f32 arg2, f32 arg3, u32 arg4);
s32 func_8002F298(Actor* actor, struct GlobalContext* globalCtx, f32 arg2, u32 arg3);
s32 func_8002F2CC(Actor* actor, struct GlobalContext* globalCtx, f32 arg2);
s32 func_8002F2F4(Actor* actor, struct GlobalContext* globalCtx);
u32 Actor_TextboxIsClosing(Actor* actor, struct GlobalContext* globalCtx);
s8 func_8002F368(struct GlobalContext* globalCtx);
void Actor_GetScreenPos(struct GlobalContext* globalCtx, Actor* actor, s16* x, s16* y);
u32 Actor_HasParent(Actor* actor, struct GlobalContext* globalCtx);
s32 func_8002F434(Actor* actor, struct GlobalContext* globalCtx, s32 getItemId, f32 xzRange, f32 yRange);
void func_8002F554(Actor* actor, struct GlobalContext* globalCtx, s32 getItemId);
void func_8002F580(Actor* actor, struct GlobalContext* globalCtx);
u32 Actor_HasNoParent(Actor* actor, struct GlobalContext* globalCtx);
void func_8002F5C4(Actor* actorA, Actor* actorB, struct GlobalContext* globalCtx);
void func_8002F5F0(Actor* actor, struct GlobalContext* globalCtx);
s32 Actor_IsMounted(struct GlobalContext* globalCtx, Actor* horse);
u32 Actor_SetRideActor(struct GlobalContext* globalCtx, Actor* horse, s32 arg2);
s32 Actor_NotMounted(struct GlobalContext* globalCtx, Actor* horse);
void func_8002F698(struct GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5, u32 arg6);
void func_8002F6D4(struct GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F71C(struct GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4);
void func_8002F758(struct GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F7A0(struct GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4);
void func_8002F7DC(Actor* actor, u16 sfxId);
void Audio_PlayActorSound2(Actor* actor, u16 sfxId);
void func_8002F850(struct GlobalContext* globalCtx, Actor* actor);
void func_8002F8F0(Actor* actor, u16 sfxId);
void func_8002F91C(Actor* actor, u16 sfxId);
void func_8002F948(Actor* actor, u16 sfxId);
void func_8002F974(Actor* actor, u16 sfxId);
void func_8002F994(Actor* actor, s32 arg1);
s32 func_8002F9EC(struct GlobalContext* globalCtx, Actor* actor, struct CollisionPoly* poly, s32 bgId, Vec3f* pos);
void func_800304B0(struct GlobalContext* globalCtx);
void func_800304DC(struct GlobalContext* globalCtx, ActorContext* actorCtx, ActorEntry* actorEntry);
void Actor_UpdateAll(struct GlobalContext* globalCtx, ActorContext* actorCtx);
s32 Actor_IsInUncullZone(struct GlobalContext* globalCtx, Actor* actorB, Vec3f* arg2, f32 arg3);
void func_800315AC(struct GlobalContext* globalCtx, ActorContext* actorCtx);
void func_80031A28(struct GlobalContext* globalCtx, ActorContext* actorCtx);
void func_80031B14(struct GlobalContext* globalCtx, ActorContext* actorCtx);
void func_80031C3C(ActorContext* actorCtx, struct GlobalContext* globalCtx);
Actor* Actor_Spawn(ActorContext* actorCtx, struct GlobalContext* globalCtx, s16 actorId, f32 posX, f32 posY, f32 posZ,
    s16 rotX, s16 rotY, s16 rotZ, s16 params);
Actor* Actor_SpawnAsChild(ActorContext* actorCtx, Actor* parent, struct GlobalContext* globalCtx, s16 actorId, f32 posX,
    f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, s16 params);
void Actor_SpawnTransitionActors(struct GlobalContext* globalCtx, ActorContext* actorCtx);
Actor* Actor_SpawnEntry(ActorContext* actorCtx, ActorEntry* actorEntry, struct GlobalContext* globalCtx);
Actor* Actor_Delete(ActorContext* actorCtx, Actor* actor, struct GlobalContext* globalCtx);
Actor* func_80032AF0(struct GlobalContext* globalCtx, ActorContext* actorCtx, Actor** actorPtr, struct Player* player);
Actor* Actor_Find(ActorContext* actorCtx, s32 actorId, s32 actorCategory);
void Enemy_StartFinishingBlow(struct GlobalContext* globalCtx, Actor* actor);
s16 func_80032CB4(s16* arg0, s16 arg1, s16 arg2, s16 arg3);
void BodyBreak_Alloc(BodyBreak* bodyBreak, s32 count, struct GlobalContext* globalCtx);
void BodyBreak_SetInfo(BodyBreak* bodyBreak, s32 limbIndex, s32 minLimbIndex, s32 maxLimbIndex, u32 count, Gfx** dList,
    s16 objectId);
s32 BodyBreak_SpawnParts(Actor* actor, BodyBreak* bodyBreak, struct GlobalContext* globalCtx, s16 type);
void Actor_SpawnFloorDustRing(struct GlobalContext* globalCtx, Actor* actor, Vec3f* posXZ, f32 radius, s32 amountMinusOne,
    f32 randAccelWeight, s16 scale, s16 scaleStep, u8 useLighting);
void func_80033480(struct GlobalContext* globalCtx, Vec3f* posBase, f32 randRangeDiameter, s32 amountMinusOne, s16 scaleBase,
    s16 scaleStep, u8 arg6);
Actor* Actor_GetCollidedExplosive(struct GlobalContext* globalCtx, Collider* collider);
Actor* func_80033684(struct GlobalContext* globalCtx, Actor* explosiveActor);
Actor* Actor_GetProjectileActor(struct GlobalContext* globalCtx, Actor* refActor, f32 radius);
void Actor_ChangeCategory(struct GlobalContext* globalCtx, ActorContext* actorCtx, Actor* actor, u8 actorCategory);
void Actor_SetTextWithPrefix(struct GlobalContext* globalCtx, Actor* actor, s16 textIdLower);
s16 Actor_TestFloorInDirection(Actor* actor, struct GlobalContext* globalCtx, f32 distance, s16 angle);
s32 Actor_IsTargeted(struct GlobalContext* globalCtx, Actor* actor);
s32 Actor_OtherIsTargeted(struct GlobalContext* globalCtx, Actor* actor);
f32 func_80033AEC(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_80033C30(Vec3f* arg0, Vec3f* arg1, u8 alpha, struct GlobalContext* globalCtx);
void func_80033DB8(struct GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80033E1C(struct GlobalContext* globalCtx, s16 arg1, s16 arg2, s16 arg3);
void func_80033E88(Actor* actor, struct GlobalContext* globalCtx, s16 arg2, s16 arg3);
f32 Rand_ZeroFloat(f32 f);
f32 Rand_CenteredFloat(f32 f);
void Actor_DrawDoorLock(struct GlobalContext* globalCtx, s32 arg1, s32 arg2);
void func_8003424C(struct GlobalContext* globalCtx, Vec3f* arg1);
void Actor_SetColorFilter(Actor* actor, s16 colorFlag, s16 colorIntensityMax, s16 xluFlag, s16 duration);
Hilite* func_800342EC(Vec3f* object, struct GlobalContext* globalCtx);
Hilite* func_8003435C(Vec3f* object, struct GlobalContext* globalCtx);
s32 func_800343CC(struct GlobalContext* globalCtx, Actor* actor, s16* arg2, f32 interactRange,
    u16(*unkFunc1)(struct GlobalContext*, Actor*), s16(*unkFunc2)(struct GlobalContext*, Actor*));
s16 func_800347E8(s16 arg0);
void func_80034A14(Actor* actor, struct_80034A14_arg1* arg1, s16 arg2, s16 arg3);
void func_80034BA0(struct GlobalContext* globalCtx, SkelAnime* skelAnime, OverrideLimbDraw overrideLimbDraw,
    PostLimbDraw postLimbDraw, Actor* actor, s16 alpha);
void func_80034CC4(struct GlobalContext* globalCtx, SkelAnime* skelAnime, OverrideLimbDraw overrideLimbDraw,
    PostLimbDraw postLimbDraw, Actor* actor, s16 alpha);
s16 func_80034DD4(Actor* actor, struct GlobalContext* globalCtx, s16 arg2, f32 arg3);
void func_80034EC0(SkelAnime* skelAnime, struct_80034EC0_Entry* animations, s32 index);
void func_80034F54(struct GlobalContext* globalCtx, s16* arg1, s16* arg2, s32 arg3);
void Actor_Noop(Actor* actor, struct GlobalContext* globalCtx);
void Gfx_DrawDListOpa(struct GlobalContext* globalCtx, Gfx* dlist);
void Gfx_DrawDListXlu(struct GlobalContext* globalCtx, Gfx* dlist);
Actor* Actor_FindNearby(struct GlobalContext* globalCtx, Actor* refActor, s16 actorId, u8 actorCategory, f32 range);
s32 func_800354B4(struct GlobalContext* globalCtx, Actor* actor, f32 range, s16 arg3, s16 arg4, s16 arg5);
void func_8003555C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void func_800355B8(struct GlobalContext* globalCtx, Vec3f* pos);
u8 func_800355E4(struct GlobalContext* globalCtx, Collider* collider);
u8 Actor_ApplyDamage(Actor* actor);
void Actor_SetDropFlag(Actor* actor, ColliderInfo* colBody, s32 freezeFlag);
void Actor_SetDropFlagJntSph(Actor* actor, ColliderJntSph* colBody, s32 freezeFlag);
void func_80035844(Vec3f* arg0, Vec3f* arg1, Vec3s* arg2, s32 arg3);
Actor* func_800358DC(Actor* actor, Vec3f* spawnPos, Vec3s* spawnRot, f32* arg3, s32 timer, s16* unused,
    struct GlobalContext* globalCtx, s16 params, s32 arg8);
void func_800359B8(Actor* actor, s16 arg1, Vec3s* arg2);
s32 Flags_GetEventChkInf(s32 flag);
void Flags_SetEventChkInf(s32 flag);
s32 Flags_GetInfTable(s32 flag);
void Flags_SetInfTable(s32 flag);
u16 func_80037C30(struct GlobalContext* globalCtx, s16 arg1);
s32 func_80037D98(struct GlobalContext* globalCtx, Actor* actor, s16 arg2, s32* arg3);
s32 func_80038290(struct GlobalContext* globalCtx, Actor* actor, Vec3s* arg2, Vec3s* arg3, Vec3f arg4);
void ActorOverlayTable_LogPrint(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_Cleanup(void);
// ? func_80038600(?);


void func_80043334(struct CollisionContext* colCtx, Actor* actor, s32 bgId);
s32 func_800433A4(struct CollisionContext* colCtx, s32 bgId, Actor* actor);
void DynaPolyActor_Init(DynaPolyActor* dynaActor, s32 flags);
void func_800434A0(DynaPolyActor* dynaActor);
void func_800434A8(DynaPolyActor* dynaActor);
void func_800434C8(struct CollisionContext* colCtx, s32 floorBgId);
void func_80043508(struct CollisionContext* colCtx, s32 floorBgId);
void func_80043538(DynaPolyActor* dynaActor);
s32 func_80043548(DynaPolyActor* dynaActor);
s32 func_8004356C(DynaPolyActor* dynaActor);
s32 func_80043590(DynaPolyActor* dynaActor);
s32 func_800435B4(DynaPolyActor* dynaActor);
s32 func_800435D8(struct GlobalContext* globalCtx, DynaPolyActor* dynaActor, s16 arg2, s16 arg3, s16 arg4);
*/

s32 func_800343CC(struct GlobalContext* globalCtx, Actor* actor, s16* arg2, f32 interactRange, u16(*unkFunc1)(struct GlobalContext*, Actor*), s16(*unkFunc2)(struct GlobalContext*, Actor*));

extern ActorOverlay gActorOverlayTable[ACTOR_ID_MAX]; // original name: "actor_dlftbls" 801162A0
extern s32 gMaxActorId; // original name: "MaxProfile"
extern Gfx D_80116280[];


#pragma once
#include "z64math.h"

#define COLLISION_CHECK_AT_MAX 50
#define COLLISION_CHECK_AC_MAX 60
#define COLLISION_CHECK_OC_MAX 50
#define COLLISION_CHECK_OC_LINE_MAX 3

struct Collider {
    /* 0x00 */ struct Actor* actor; // Attached actor
    /* 0x04 */ struct Actor* at; // Actor attached to what it collided with as an AT collider.
    /* 0x08 */ struct Actor* ac; // Actor attached to what it collided with as an AC collider.
    /* 0x0C */ struct Actor* oc; // Actor attached to what it collided with as an OC collider.
    /* 0x10 */ u8 atFlags; // Information flags for AT collisions. 
    /* 0x11 */ u8 acFlags; // Information flags for AC collisions.
    /* 0x12 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x13 */ u8 ocFlags2;  // Flags related to which colliders it can OC collide with.
    /* 0x14 */ u8 colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x15 */ u8 shape; // JntSph, Cylinder, Tris, or Quad
}; // size = 0x18

struct ColliderInit {
    /* 0x00 */ u8 colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x01 */ u8 atFlags; // Information flags for AT collisions. 
    /* 0x02 */ u8 acFlags; // Information flags for OC collisions.
    /* 0x03 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x04 */ u8 ocFlags2; // Flags related to which colliders it can OC collide with.
    /* 0x05 */ u8 shape; // JntSph, Cylinder, Tris, or Quad
}; // size = 0x06

struct ColliderInitType1 {
    /* 0x00 */ u8 colType; // Determines hitmarks and sound effects during AC collisions.
    /* 0x01 */ u8 atFlags; // Information flags for AT collisions. 
    /* 0x02 */ u8 acFlags; // Information flags for AC collisions.
    /* 0x03 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x04 */ u8 shape; // JntSph, Cylinder, Tris, or Quad
}; // size = 0x05

struct ColliderInitToActor {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ u8 atFlags; // Information flags for AT collisions.
    /* 0x05 */ u8 acFlags; // Information flags for AC collisions.
    /* 0x06 */ u8 ocFlags1; // Information flags for OC collisions.
    /* 0x07 */ u8 shape;   // JntSph, Cylinder, Tris, or Quad
}; // size = 0x08

struct ColliderTouch {
    /* 0x00 */ u32 dmgFlags; // Toucher damage type flags.
    /* 0x04 */ u8 effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 damage; // Damage or Stun Timer
}; // size = 0x08

struct ColliderBump {
    /* 0x00 */ u32 dmgFlags;  // Bumper damage type flags.
    /* 0x04 */ u8 effect;  // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 defense; // Damage Resistance
    /* 0x06 */ Vec3s hitPos; // Point of contact
}; // size = 0x0C

struct ColliderBumpInit {
    /* 0x00 */ u32 dmgFlags; // Bumper exclusion mask
    /* 0x04 */ u8 effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ u8 defense; // Damage Resistance
}; // size = 0x08

struct ColliderInfo {
    /* 0x00 */ ColliderTouch toucher; // Damage properties when acting as an AT collider
    /* 0x08 */ ColliderBump bumper; // Damage properties when acting as an AC collider
    /* 0x14 */ u8 elemType; // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x15 */ u8 toucherFlags; // Information flags for AT collisions
    /* 0x16 */ u8 bumperFlags; // Information flags for AC collisions
    /* 0x17 */ u8 ocElemFlags; // Information flags for OC collisions
    /* 0x18 */ Collider* atHit;                // object touching this element's AT collider
    /* 0x1C */ Collider* acHit;                // object touching this element's AC collider
    /* 0x20 */ struct ColliderInfo* atHitInfo; // element that hit the AT collider
    /* 0x24 */ struct ColliderInfo* acHitInfo; // element that hit the AC collider
}; // size = 0x28

struct ColliderInfoInit {
    /* 0x00 */ u8 elemType; // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x04 */ ColliderTouch toucher; // Damage properties when acting as an AT collider
    /* 0x0C */ ColliderBumpInit bumper; // Damage properties when acting as an AC collider
    /* 0x14 */ u8 toucherFlags; // Information flags for AT collisions
    /* 0x15 */ u8 bumperFlags;  // Information flags for AC collisions
    /* 0x16 */ u8 ocElemFlags; // Information flags for OC collisions
}; // size = 0x18

struct ColliderJntSphElementDim {
    /* 0x00 */ Sphere16 modelSphere; // model space sphere
    /* 0x08 */ Sphere16 worldSphere; // world space sphere
    /* 0x10 */ f32 scale;          // world space sphere = model * scale * 0.01
    /* 0x14 */ u8 limb;           // attached limb
}; // size = 0x18

struct ColliderJntSphElementDimInit {
    /* 0x00 */ u8 limb; // attached limb
    /* 0x02 */ Sphere16 modelSphere; // model space sphere
    /* 0x0A */ s16 scale; // world space sphere = model * scale * 0.01
}; // size = 0x0C

struct ColliderJntSphElement {
    /* 0x00 */ ColliderInfo info;
    /* 0x28 */ ColliderJntSphElementDim dim;
}; // size = 0x40

struct ColliderJntSphElementInit {
    /* 0x00 */ ColliderInfoInit info;
    /* 0x18 */ ColliderJntSphElementDimInit dim;
}; // size = 0x24

struct ColliderJntSph {
    /* 0x00 */ Collider base;
    /* 0x18 */ s32 count;
    /* 0x1C */ ColliderJntSphElement* elements;
}; // size = 0x20

struct ColliderJntSphInit {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ s32 count;
    /* 0x0C */ ColliderJntSphElementInit* elements;
}; // size = 0x10

struct ColliderJntSphInitType1 {
    /* 0x00 */ ColliderInitType1 base;
    /* 0x08 */ s32 count;
    /* 0x0C */ ColliderJntSphElementInit* elements;
}; // size = 0x10

struct ColliderJntSphInitToActor {
    /* 0x00 */ ColliderInitToActor base;
    /* 0x08 */ s32 count;
    /* 0x0C */ ColliderJntSphElementInit* elements;
}; // size = 0x10

struct ColliderCylinder {
    /* 0x00 */ Collider base;
    /* 0x18 */ ColliderInfo info;
    /* 0x40 */ Cylinder16 dim;
}; // size = 0x4C

struct ColliderCylinderInit {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ Cylinder16 dim;
}; // size = 0x2C

struct ColliderCylinderInitType1 {
    /* 0x00 */ ColliderInitType1 base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ Cylinder16 dim;
}; // size = 0x2C

struct ColliderCylinderInitToActor {
    /* 0x00 */ ColliderInitToActor base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ Cylinder16 dim;
}; // size = 0x2C

struct ColliderTrisElementDimInit {
    /* 0x00 */ Vec3f vtx[3];
}; // size = 0x24

struct ColliderTrisElement {
    /* 0x00 */ ColliderInfo info;
    /* 0x28 */ TriNorm dim;
}; // size = 0x5C

struct ColliderTrisElementInit {
    /* 0x00 */ ColliderInfoInit info;
    /* 0x18 */ ColliderTrisElementDimInit dim;
}; // size = 0x3C

struct ColliderTris {
    /* 0x00 */ Collider base;
    /* 0x18 */ s32 count;
    /* 0x1C */ ColliderTrisElement* elements;
}; // size = 0x20

struct ColliderTrisInit {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ s32 count;
    /* 0x0C */ ColliderTrisElementInit* elements;
}; // size = 0x10

struct ColliderTrisInitType1 {
    /* 0x00 */ ColliderInitType1 base;
    /* 0x08 */ s32 count;
    /* 0x0C */ ColliderTrisElementInit* elements;
}; // size = 0x10

struct ColliderQuadDim {
    /* 0x00 */ Vec3f quad[4];
    /* 0x30 */ Vec3s dcMid; // midpoint of vectors d, c
    /* 0x36 */ Vec3s baMid; // midpoint of vectors b, a
    /* 0x3C */ f32 acDist; // distance to nearest AC collision this frame.
}; // size = 0x40

struct ColliderQuadDimInit {
    /* 0x00 */ Vec3f quad[4];
}; // size = 0x30

struct ColliderQuadElement {
    /* 0x00 */ ColliderInfo info;
    /* 0x24 */ ColliderQuadDim dim;
}; // size = 0x68

struct ColliderQuad {
    /* 0x00 */ Collider base;
    /* 0x18 */ ColliderInfo info;
    /* 0x40 */ ColliderQuadDim dim;
}; // size = 0x80

struct ColliderQuadInit {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ ColliderQuadDimInit dim;
}; // size = 0x50

struct ColliderQuadInitType1 {
    /* 0x00 */ ColliderInitType1 base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ ColliderQuadDimInit dim;
}; // size = 0x50

struct OcLine {
    /* 0x00 */ Linef line;
    /* 0x18 */ u16 ocFlags;
}; // size = 0x1C

enum ColliderType {
    /* 0  */ COLTYPE_HIT0, // Blue blood, white hitmark
    /* 1  */ COLTYPE_HIT1, // No blood, dust hitmark
    /* 2  */ COLTYPE_HIT2, // Green blood, dust hitmark
    /* 3  */ COLTYPE_HIT3, // No blood, white hitmark
    /* 4  */ COLTYPE_HIT4, // Water burst, no hitmark
    /* 5  */ COLTYPE_HIT5, // No blood, red hitmark
    /* 6  */ COLTYPE_HIT6, // Green blood, white hitmark
    /* 7  */ COLTYPE_HIT7, // Red blood, white hitmark
    /* 8  */ COLTYPE_HIT8, // Blue blood, red hitmark
    /* 9  */ COLTYPE_METAL,
    /* 10 */ COLTYPE_NONE,
    /* 11 */ COLTYPE_WOOD,
    /* 12 */ COLTYPE_HARD,
    /* 13 */ COLTYPE_TREE
};

enum ColliderShape {
    /* 0 */ COLSHAPE_JNTSPH,
    /* 1 */ COLSHAPE_CYLINDER,
    /* 2 */ COLSHAPE_TRIS,
    /* 3 */ COLSHAPE_QUAD,
    /* 4 */ COLSHAPE_INVALID
};

/**
 * Affects the sound Link's sword makes when hitting it, hookability,
 * and possibly other things. It's definitely not flags, as all checks
 * are == or !=. Will probably need more actors decomped to truly 
 * understand what this is.
 */
enum ElementType {
    /* 0 */ ELEMTYPE_UNK0,
    /* 1 */ ELEMTYPE_UNK1,
    /* 2 */ ELEMTYPE_UNK2,
    /* 3 */ ELEMTYPE_UNK3,
    /* 4 */ ELEMTYPE_UNK4,
    /* 5 */ ELEMTYPE_UNK5,
    /* 6 */ ELEMTYPE_UNK6,
    /* 7 */ ELEMTYPE_UNK7
};

#define AT_NONE 0 // No flags set. Cannot have AT collisions when set as AT
#define AT_ON (1 << 0) // Can have AT collisions when set as AT
#define AT_HIT (1 << 1) // Had an AT collision
#define AT_BOUNCED (1 << 2) // Had an AT collision with an AC_HARD collider
#define AT_TYPE_PLAYER (1 << 3) // Has player-aligned damage
#define AT_TYPE_ENEMY (1 << 4) // Has enemy-aligned damage
#define AT_TYPE_OTHER (1 << 5) // Has non-aligned damage
#define AT_SELF (1 << 6) // Can have AT collisions with colliders attached to the same actor
#define AT_TYPE_ALL (AT_TYPE_PLAYER | AT_TYPE_ENEMY | AT_TYPE_OTHER) // Has all three damage alignments

#define AC_NONE 0 // No flags set. Cannot have AC collisions when set as AC
#define AC_ON (1 << 0) // Can have AC collisions when set as AC
#define AC_HIT (1 << 1) // Had an AC collision
#define AC_HARD (1 << 2) // Causes AT colliders to bounce off it
#define AC_TYPE_PLAYER AT_TYPE_PLAYER // Takes player-aligned damage
#define AC_TYPE_ENEMY AT_TYPE_ENEMY // Takes enemy-aligned damage
#define AC_TYPE_OTHER AT_TYPE_OTHER // Takes non-aligned damage
#define AC_NO_DAMAGE (1 << 6) // Collider does not take damage
#define AC_BOUNCED (1 << 7) // Caused an AT collider to bounce off it
#define AC_TYPE_ALL (AC_TYPE_PLAYER | AC_TYPE_ENEMY | AC_TYPE_OTHER) // Takes damage from all three alignments

#define OC1_NONE 0 // No flags set. Cannot have OC collisions when set as OC
#define OC1_ON (1 << 0) // Can have OC collisions when set as OC
#define OC1_HIT (1 << 1) // Had an OC collision
#define OC1_NO_PUSH (1 << 2) // Does not push other colliders away during OC collisions
#define OC1_TYPE_PLAYER (1 << 3) // Can have OC collisions with OC type player
#define OC1_TYPE_1 (1 << 4) // Can have OC collisions with OC type 1
#define OC1_TYPE_2 (1 << 5) // Can have OC collisions with OC type 2
#define OC1_TYPE_ALL (OC1_TYPE_PLAYER | OC1_TYPE_1 | OC1_TYPE_2) // Can have collisions with all three OC types

#define OC2_NONE 0 // No flags set. Has no OC type
#define OC2_HIT_PLAYER (1 << 0) // Had an OC collision with OC type player
#define OC2_UNK1 (1 << 1) // Prevents OC collisions with OC2_UNK2. Some horses and toki_sword have it.
#define OC2_UNK2 (1 << 2) // Prevents OC collisions with OC2_UNK1. Nothing has it.
#define OC2_TYPE_PLAYER OC1_TYPE_PLAYER // Has OC type player
#define OC2_TYPE_1 OC1_TYPE_1 // Has OC type 1
#define OC2_TYPE_2 OC1_TYPE_2 // Has OC type 2
#define OC2_FIRST_ONLY (1 << 6) // Skips AC checks on elements after the first collision. Only used by Ganon

#define TOUCH_NONE 0 // No flags set. Cannot have AT collisions
#define TOUCH_ON (1 << 0) // Can have AT collisions
#define TOUCH_HIT (1 << 1) // Had an AT collision
#define TOUCH_NEAREST (1 << 2) // If a Quad, only collides with the closest bumper
#define TOUCH_SFX_NORMAL (0 << 3) // Hit sound effect based on AC collider's type
#define TOUCH_SFX_HARD (1 << 3) // Always uses hard deflection sound
#define TOUCH_SFX_WOOD (2 << 3) // Always uses wood deflection sound
#define TOUCH_SFX_NONE (3 << 3) // No hit sound effect
#define TOUCH_AT_HITMARK (1 << 5) // Draw hitmarks for every AT collision
#define TOUCH_DREW_HITMARK (1 << 6) // Already drew hitmark for this frame
#define TOUCH_UNK7 (1 << 7) // Unknown purpose. Used by some enemy quads

#define BUMP_NONE 0 // No flags set. Cannot have AC collisions
#define BUMP_ON (1 << 0) // Can have AC collisions
#define BUMP_HIT (1 << 1) // Had an AC collision
#define BUMP_HOOKABLE (1 << 2) // Can be hooked if actor has hookability flags set.
#define BUMP_NO_AT_INFO (1 << 3) // Does not give its info to the AT collider that hit it.
#define BUMP_NO_DAMAGE (1 << 4) // Does not take damage.
#define BUMP_NO_SWORD_SFX (1 << 5) // Does not have a sound when hit by player-attached AT colliders.
#define BUMP_NO_HITMARK (1 << 6) // Skips hit effects.
#define BUMP_DRAW_HITMARK (1 << 7) // Draw hitmark for AC collision this frame.

#define OCELEM_NONE 0 // No flags set. Cannot have OC collisions
#define OCELEM_ON (1 << 0) // Can have OC collisions
#define OCELEM_HIT (1 << 1) // Had an OC collision
#define OCELEM_UNK3 (1 << 3) // Unknown purpose. Used by Dead Hand element 0 and Dodongo element 5

#define OCLINE_NONE 0 // Did not have an OcLine collision
#define OCLINE_HIT (1 << 0) // Had an OcLine collision

#define DMG_ENTRY(damage, effect) ((damage) | ((effect) << 4))

// These flags are not to be used in code until we figure out how we want to format them. They are only here for reference 
#define DMG_DEKU_NUT     (1 << 0x00)
#define DMG_DEKU_STICK   (1 << 0x01)
#define DMG_SLINGSHOT    (1 << 0x02)
#define DMG_EXPLOSIVE    (1 << 0x03)
#define DMG_BOOMERANG    (1 << 0x04)
#define DMG_ARROW_NORMAL (1 << 0x05)
#define DMG_HAMMER_SWING (1 << 0x06)
#define DMG_HOOKSHOT     (1 << 0x07)
#define DMG_SLASH_KOKIRI (1 << 0x08)
#define DMG_SLASH_MASTER (1 << 0x09)
#define DMG_SLASH_GIANT  (1 << 0x0A)
#define DMG_ARROW_FIRE   (1 << 0x0B)
#define DMG_ARROW_ICE    (1 << 0x0C)
#define DMG_ARROW_LIGHT  (1 << 0x0D)
#define DMG_ARROW_UNK1   (1 << 0x0E)
#define DMG_ARROW_UNK2   (1 << 0x0F)
#define DMG_ARROW_UNK3   (1 << 0x10)
#define DMG_MAGIC_FIRE   (1 << 0x11)
#define DMG_MAGIC_ICE    (1 << 0x12)
#define DMG_MAGIC_LIGHT  (1 << 0x13)
#define DMG_SHIELD       (1 << 0x14)
#define DMG_MIR_RAY      (1 << 0x15)
#define DMG_SPIN_KOKIRI  (1 << 0x16)
#define DMG_SPIN_GIANT   (1 << 0x17)
#define DMG_SPIN_MASTER  (1 << 0x18)
#define DMG_JUMP_KOKIRI  (1 << 0x19)
#define DMG_JUMP_GIANT   (1 << 0x1A)
#define DMG_JUMP_MASTER  (1 << 0x1B)
#define DMG_UNKNOWN_1    (1 << 0x1C)
#define DMG_UNBLOCKABLE  (1 << 0x1D)
#define DMG_HAMMER_JUMP  (1 << 0x1E)
#define DMG_UNKNOWN_2    (1 << 0x1F)

#define DMG_SLASH (DMG_SLASH_KOKIRI | DMG_SLASH_MASTER | DMG_SLASH_GIANT)
#define DMG_SPIN_ATTACK (DMG_SPIN_KOKIRI | DMG_SPIN_MASTER | DMG_SPIN_GIANT)
#define DMG_JUMP_SLASH (DMG_JUMP_KOKIRI | DMG_JUMP_MASTER | DMG_JUMP_GIANT)
#define DMG_SWORD (DMG_SLASH | DMG_SPIN_ATTACK | DMG_JUMP_SLASH)
#define DMG_HAMMER (DMG_HAMMER_SWING | DMG_HAMMER_JUMP)
#define DMG_FIRE (DMG_ARROW_FIRE | DMG_MAGIC_FIRE)
#define DMG_ARROW (DMG_ARROW_NORMAL | DMG_ARROW_FIRE | DMG_ARROW_ICE | DMG_ARROW_LIGHT | DMG_ARROW_UNK1 | DMG_ARROW_UNK2 | DMG_ARROW_UNK3)
#define DMG_RANGED (DMG_ARROW | DMG_HOOKSHOT | DMG_SLINGSHOT)
#define DMG_DEFAULT ~(DMG_SHIELD | DMG_MIR_RAY)

struct CollisionCheckContext {
    /* 0x000 */ s16 colATCount;
    /* 0x002 */ u16 sacFlags;
    /* 0x004 */ Collider* colAT[COLLISION_CHECK_AT_MAX];
    /* 0x0CC */ s32 colACCount;
    /* 0x0D0 */ Collider* colAC[COLLISION_CHECK_AC_MAX];
    /* 0x1C0 */ s32 colOCCount;
    /* 0x1C4 */ Collider* colOC[COLLISION_CHECK_OC_MAX];
    /* 0x28C */ s32 colLineCount;
    /* 0x290 */ OcLine* colLine[COLLISION_CHECK_OC_LINE_MAX];
}; // size = 0x29C



void Collider_DrawRedPoly(struct GraphicsContext* gfxCtx, Vec3f* vA, Vec3f* vB, Vec3f* vC);
void Collider_DrawPoly(struct GraphicsContext* gfxCtx, Vec3f* vA, Vec3f* vB, Vec3f* vC, u8 r, u8 g, u8 b);
s32 Collider_InitJntSph(struct GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_FreeJntSph(struct GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_DestroyJntSph(struct GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_SetJntSphToActor(struct GlobalContext* globalCtx, ColliderJntSph* dest, ColliderJntSphInitToActor* src);
s32 Collider_SetJntSphAllocType1(struct GlobalContext* globalCtx, ColliderJntSph* dest, struct Actor* actor,
    ColliderJntSphInitType1* src);
s32 Collider_SetJntSphAlloc(struct GlobalContext* globalCtx, ColliderJntSph* dest, struct Actor* actor, ColliderJntSphInit* src);
s32 Collider_SetJntSph(struct GlobalContext* globalCtx, ColliderJntSph* dest, struct Actor* actor, ColliderJntSphInit* src,
    ColliderJntSphElement* elements);
s32 Collider_ResetJntSphAT(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetJntSphAC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetJntSphOC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_DestroyCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_SetCylinderToActor(struct GlobalContext* globalCtx, ColliderCylinder* collider, ColliderCylinderInitToActor* src);
s32 Collider_SetCylinderType1(struct GlobalContext* globalCtx, ColliderCylinder* collider, struct Actor* actor,
    ColliderCylinderInitType1* src);
s32 Collider_SetCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider, struct Actor* actor, ColliderCylinderInit* src);
s32 Collider_ResetCylinderAT(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetCylinderAC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetCylinderOC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitTris(struct GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_FreeTris(struct GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_DestroyTris(struct GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_SetTrisAllocType1(struct GlobalContext* globalCtx, ColliderTris* dest, struct Actor* actor, ColliderTrisInitType1* src);
s32 Collider_SetTrisAlloc(struct GlobalContext* globalCtx, ColliderTris* dest, struct Actor* actor, ColliderTrisInit* src);
s32 Collider_SetTris(struct GlobalContext* globalCtx, ColliderTris* dest, struct Actor* actor, ColliderTrisInit* src,
    ColliderTrisElement* elements);
s32 Collider_ResetTrisAT(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetTrisAC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetTrisOC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitQuad(struct GlobalContext* globalCtx, ColliderQuad* collider);
s32 Collider_DestroyQuad(struct GlobalContext* globalCtx, ColliderQuad* collider);
s32 Collider_SetQuadType1(struct GlobalContext* globalCtx, ColliderQuad* collider, struct Actor* actor, ColliderQuadInitType1* src);
s32 Collider_SetQuad(struct GlobalContext* globalCtx, ColliderQuad* collider, struct Actor* actor, ColliderQuadInit* src);
s32 Collider_ResetQuadAT(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetQuadAC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetQuadOC(struct GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitLine(struct GlobalContext* globalCtx, OcLine* line);
s32 Collider_DestroyLine(struct GlobalContext* globalCtx, OcLine* line);
s32 Collider_SetLinePoints(struct GlobalContext* globalCtx, OcLine* ocLine, Vec3f* a, Vec3f* b);
s32 Collider_SetLine(struct GlobalContext* globalCtx, OcLine* dest, OcLine* src);
s32 Collider_ResetLineOC(struct GlobalContext* globalCtx, OcLine* line);
void CollisionCheck_InitContext(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_DestroyContext(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_ClearContext(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_EnableSAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_DisableSAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void Collider_Draw(struct GlobalContext* globalCtx, Collider* collider);
void CollisionCheck_DrawCollision(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
s32 CollisionCheck_SetAT(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetAT_SAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetAC_SAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetOC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetOC_SAC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetOCLine(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, OcLine* collider);
void CollisionCheck_BlueBlood(struct GlobalContext* globalCtx, Collider* collider, Vec3f* v);
void CollisionCheck_AT(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_OC(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_InitInfo(struct CollisionCheckInfo* info);
void CollisionCheck_ResetDamage(struct CollisionCheckInfo* info);
void CollisionCheck_SetInfoNoDamageTable(struct CollisionCheckInfo* info, struct CollisionCheckInfoInit* init);
void CollisionCheck_SetInfo(struct CollisionCheckInfo* info, struct DamageTable* damageTable, struct CollisionCheckInfoInit* init);
void CollisionCheck_SetInfo2(struct CollisionCheckInfo* info, struct DamageTable* damageTable, struct CollisionCheckInfoInit2* init);
void CollisionCheck_SetInfoGetDamageTable(struct CollisionCheckInfo* info, s32 index, struct CollisionCheckInfoInit2* init);
void CollisionCheck_Damage(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
s32 CollisionCheck_LineOCCheckAll(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* a, Vec3f* b);
s32 CollisionCheck_LineOCCheck(struct GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* a, Vec3f* b,
    struct Actor** exclusions, s32 numExclusions);
void Collider_UpdateCylinder(struct Actor* actor, ColliderCylinder* collider);
void Collider_SetCylinderPosition(ColliderCylinder* collider, Vec3s* pos);
void Collider_SetQuadVertices(ColliderQuad* collider, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d);
void Collider_SetTrisVertices(ColliderTris* collider, s32 index, Vec3f* a, Vec3f* b, Vec3f* c);
void Collider_SetTrisDim(struct GlobalContext* globalCtx, ColliderTris* collider, s32 index, struct ColliderTrisElementDimInit* init);
void Collider_UpdateSpheres(s32 limb, ColliderJntSph* collider);
void CollisionCheck_SpawnRedBlood(struct GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnWaterDroplets(struct GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticles(struct GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesMetal(struct GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesMetalSound(struct GlobalContext* globalCtx, Vec3f* v, Vec3f* actorPos);
void CollisionCheck_SpawnShieldParticlesMetal2(struct GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesWood(struct GlobalContext* globalCtx, Vec3f* b, Vec3f* actorPos);
s32 CollisionCheck_CylSideVsLineSeg(f32 radius, f32 height, f32 offset, Vec3f* actorPos, Vec3f* itemPos,
    Vec3f* itemProjPos, Vec3f* out1, Vec3f* out2);
u8 CollisionCheck_GetSwordDamage(s32 dmgFlags);


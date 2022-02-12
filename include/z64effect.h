#pragma once
#include "z64math.h"
#include "z64light.h"
#include "color.h"

struct GraphicsContext;
struct GlobalContext;

/* Effects */

#define SPARK_COUNT 3
#define BLURE_COUNT 25
#define SHIELD_PARTICLE_COUNT 3

#define TOTAL_EFFECT_COUNT SPARK_COUNT + BLURE_COUNT + SHIELD_PARTICLE_COUNT

struct EffectStatus {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
}; // size = 0x03

struct EffectSparkElement {
    /* 0x00 */ Vec3f velocity;
    /* 0x0C */ Vec3f position;
    /* 0x18 */ Vec3s unkVelocity;
    /* 0x1E */ Vec3s unkPosition;
}; // size = 0x24

struct EffectSparkInit {
    /* 0x000 */ Vec3s position;
    /* 0x008 */ s32 numElements; // "table_size"; calculated as uDiv * vDiv + 2
    /* 0x00C */ EffectSparkElement elements[32];
    /* 0x48C */ f32 speed;
    /* 0x490 */ f32 gravity;
    /* 0x494 */ u32 uDiv; // "u_div"
    /* 0x498 */ u32 vDiv; // "v_div"
    /* 0x49C */ Color_RGBA8 colorStart[4];
    /* 0x4AC */ Color_RGBA8 colorEnd[4];
    /* 0x4BC */ s32 timer;
    /* 0x4C0 */ s32 duration;
}; // size = 0x4C4

struct EffectSpark {
    /* 0x000 */ Vec3s position;
    /* 0x008 */ s32 numElements; // "table_size"; calculated as uDiv * vDiv + 2
    /* 0x00C */ EffectSparkElement elements[32];
    /* 0x48C */ f32 speed;
    /* 0x490 */ f32 gravity;
    /* 0x494 */ u32 uDiv; // "u_div"
    /* 0x498 */ u32 vDiv; // "v_div"
    /* 0x49C */ Color_RGBA8 colorStart[4];
    /* 0x4AC */ Color_RGBA8 colorEnd[4];
    /* 0x4BC */ s32 timer;
    /* 0x4C0 */ s32 duration;
}; // size = 0x4C4

struct EffectBlureElement {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 timer;
    /* 0x08 */ Vec3s p1;
    /* 0x0E */ Vec3s p2;
    /* 0x14 */ u16 flags;
}; // size = 0x18

struct EffectBlureInit1 {
    /* 0x000 */ char unk_00[0x184];
    /* 0x184 */ u8 p1StartColor[4];
    /* 0x188 */ u8 p2StartColor[4];
    /* 0x18C */ u8 p1EndColor[4];
    /* 0x190 */ u8 p2EndColor[4];
    /* 0x194 */ s32 elemDuration;
    /* 0x198 */ s32 unkFlag;
    /* 0x19C */ s32 calcMode;
}; // size = 0x1A0

struct EffectBlureInit2 {
    /* 0x00 */ s32 calcMode;
    /* 0x04 */ u16 flags;
    /* 0x06 */ s16 addAngleChange;
    /* 0x08 */ u8 p1StartColor[4];
    /* 0x0C */ u8 p2StartColor[4];
    /* 0x10 */ u8 p1EndColor[4];
    /* 0x14 */ u8 p2EndColor[4];
    /* 0x18 */ u8 elemDuration;
    /* 0x19 */ u8 unkFlag;
    /* 0x1A */ u8 drawMode; // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1B */ u8 mode4Param;
    /* 0x1C */ Color_RGBA8 altPrimColor; // used with drawMode 1
    /* 0x20 */ Color_RGBA8 altEnvColor; // used with drawMode 1
}; // size = 0x24

struct EffectBlure {
    /* 0x000 */ EffectBlureElement elements[16];
    /* 0x180 */ s32 calcMode;
    /* 0x184 */ f32 mode4Param;
    /* 0x188 */ u16 flags;
    /* 0x18A */ s16 addAngleChange;
    /* 0x18C */ s16 addAngle;
    /* 0x18E */ Color_RGBA8 p1StartColor;
    /* 0x192 */ Color_RGBA8 p2StartColor;
    /* 0x196 */ Color_RGBA8 p1EndColor;
    /* 0x19A */ Color_RGBA8 p2EndColor;
    /* 0x19E */ u8 numElements; // "now_edge_num"
    /* 0x19F */ u8 elemDuration;
    /* 0x1A0 */ u8 unkFlag;
    /* 0x1A1 */ u8 drawMode; // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1A2 */ Color_RGBA8 altPrimColor; // used with drawMode 1
    /* 0x1A6 */ Color_RGBA8 altEnvColor; // used with drawMode 1
}; // size = 0x1AC

struct EffectShieldParticleElement {
    /* 0x00 */ f32 initialSpeed;
    /* 0x04 */ f32 endXChange;
    /* 0x08 */ f32 endX;
    /* 0x0C */ f32 startXChange;
    /* 0x10 */ f32 startX;
    /* 0x14 */ s16 yaw;
    /* 0x16 */ s16 pitch;
}; // size = 0x18

struct EffectShieldParticleInit {
    /* 0x00 */ u8 numElements;
    /* 0x02 */ Vec3s position;
    /* 0x08 */ Color_RGBA8 primColorStart;
    /* 0x0C */ Color_RGBA8 envColorStart;
    /* 0x10 */ Color_RGBA8 primColorMid;
    /* 0x14 */ Color_RGBA8 envColorMid;
    /* 0x18 */ Color_RGBA8 primColorEnd;
    /* 0x1C */ Color_RGBA8 envColorEnd;
    /* 0x20 */ f32 deceleration;
    /* 0x24 */ f32 maxInitialSpeed;
    /* 0x28 */ f32 lengthCutoff;
    /* 0x2C */ u8 duration;
    /* 0x2E */ LightPoint lightPoint;
    /* 0x3C */ s32 lightDecay; // halves light radius every frame when set to 1
}; // size = 0x40

struct EffectShieldParticle {
    /* 0x000 */ EffectShieldParticleElement elements[16];
    /* 0x180 */ u8 numElements;
    /* 0x182 */ Vec3s position;
    /* 0x188 */ Color_RGBA8 primColorStart;
    /* 0x18C */ Color_RGBA8 envColorStart;
    /* 0x190 */ Color_RGBA8 primColorMid;
    /* 0x194 */ Color_RGBA8 envColorMid;
    /* 0x198 */ Color_RGBA8 primColorEnd;
    /* 0x19C */ Color_RGBA8 envColorEnd;
    /* 0x1A0 */ f32 deceleration;
    /* 0x1A4 */ char unk_1A4[0x04];
    /* 0x1A8 */ f32 maxInitialSpeed;
    /* 0x1AC */ f32 lengthCutoff;
    /* 0x1B0 */ u8 duration;
    /* 0x1B1 */ u8 timer;
    /* 0x1B2 */ LightInfo lightInfo;
    /* 0x1C0 */ LightNode* lightNode;
    /* 0x1C4 */ s32 lightDecay; // halves light radius every frame when set to 1
}; // size = 0x1C8

typedef struct {
    /* 0x0000 */ struct GlobalContext* globalCtx;
    struct {
        EffectStatus status;
        EffectSpark effect;
    } /* 0x0004 */ sparks[SPARK_COUNT];
    struct {
        EffectStatus status;
        EffectBlure effect;
    } /* 0x0E5C */ blures[BLURE_COUNT];
    struct {
        EffectStatus status;
        EffectShieldParticle effect;
    } /* 0x388C */ shieldParticles[SHIELD_PARTICLE_COUNT];
} EffectContext; // size = 0x3DF0

struct EffectInfo {
    /* 0x00 */ u32 size;
    /* 0x04 */ void (*init)(void* effect, void* initParams);
    /* 0x08 */ void (*destroy)(void* effect);
    /* 0x0C */ s32 (*update)(void* effect);
    /* 0x10 */ void (*draw)(void* effect, struct GraphicsContext* gfxCtx);
}; // size = 0x14

enum EffectType {
    /* 0x00 */ EFFECT_SPARK,
    /* 0x01 */ EFFECT_BLURE1,
    /* 0x02 */ EFFECT_BLURE2,
    /* 0x03 */ EFFECT_SHIELD_PARTICLE
};

/* Effect Soft Sprites */

struct EffectSs;

typedef u32 (*EffectSsInitFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs, void* initParams);
typedef void (*EffectSsUpdateFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs);
typedef void (*EffectSsDrawFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs);

struct EffectSsInit {
    /* 0x00 */ u32 type;
    /* 0x04 */ EffectSsInitFunc init;
}; // size = 0x08

struct EffectSsOverlay {
    /* 0x00 */ uintptr_t vromStart;
    /* 0x04 */ uintptr_t vromEnd;
    /* 0x08 */ void* vramStart;
    /* 0x0C */ void* vramEnd;
    /* 0x10 */ void* loadedRamAddr;
    /* 0x14 */ EffectSsInit* initInfo;
    /* 0x18 */ u8 unk_18;
}; // size = 0x1C

struct EffectSs {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ EffectSsUpdateFunc update;
    /* 0x28 */ EffectSsDrawFunc draw;
    /* 0x2C */ Vec3f vec; // usage specific per effect
    /* 0x38 */ void* gfx; // mostly used for display lists, sometimes textures
    /* 0x3C */ struct Actor* actor; // interfacing actor, usually the actor that spawned the effect
    /* 0x40 */ s32 regs[13]; // specific per effect
    /* 0x74 */ u16 flags;
    /* 0x76 */ s16 life; // -1 means this entry is free
    /* 0x78 */ u8 priority; // Lower value means higher priority
    /* 0x79 */ u8 type;
}; // size = 0x7A

struct EffectSsInfo {
    /* 0x00 */ EffectSs* table; // "data_table"
    /* 0x04 */ s32 searchStartIndex;
    /* 0x08 */ s32 tableSize;
}; // size = 0x0C

/* G Effect Regs */

#define rgTexIdx regs[0]
#define rgScale regs[1]
#define rgTexIdxStep regs[2]
#define rgPrimColorR regs[3]
#define rgPrimColorG regs[4]
#define rgPrimColorB regs[5]
#define rgPrimColorA regs[6]
#define rgEnvColorR regs[7]
#define rgEnvColorG regs[8]
#define rgEnvColorB regs[9]
#define rgEnvColorA regs[10]
#define rgObjBankIdx regs[11]

#define DEFINE_EFFECT_SS(_0, enum) enum,
#define DEFINE_EFFECT_SS_UNSET(enum) enum,

enum EffectSsType {
    #include "tables/effect_ss_table.h"
    /* 0x25 */ EFFECT_SS_TYPE_MAX // originally "EFFECT_SS2_TYPE_LAST_LABEL"
};

#undef DEFINE_EFFECT_SS
#undef DEFINE_EFFECT_SS_UNSET

void EffectBlure_AddVertex(EffectBlure* t, Vec3f* p1, Vec3f* p2);
void EffectBlure_AddSpace(EffectBlure* t);
void EffectBlure_Init1(void* thissx, void* initParamsx);
void EffectBlure_Init2(void* thissx, void* initParamsx);
void EffectBlure_Destroy(void* thissx);
s32 EffectBlure_Update(void* thissx);
void EffectBlure_Draw(void* thissx, struct GraphicsContext* gfxCtx);
void EffectShieldParticle_Init(void* thissx, void* initParamsx);
void EffectShieldParticle_Destroy(void* thissx);
s32 EffectShieldParticle_Update(void* thissx);
void EffectShieldParticle_Draw(void* thissx, struct GraphicsContext* gfxCtx);
void EffectSpark_Init(void* thissx, void* initParamsx);
void EffectSpark_Destroy(void* thissx);
s32 EffectSpark_Update(void* thissx);
void EffectSpark_Draw(void* thissx, struct GraphicsContext* gfxCtx);
void func_80026230(struct GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026400(struct GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026608(struct GlobalContext* globalCtx);
void func_80026690(struct GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026860(struct GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026A6C(struct GlobalContext* globalCtx);
struct GlobalContext* Effect_GetGlobalCtx(void);
void* Effect_GetByIndex(s32 index);
void Effect_InitContext(struct GlobalContext* globalCtx);
void Effect_Add(struct GlobalContext* globalCtx, s32* pIndex, s32 type, u8 arg3, u8 arg4, void* initParams);
void Effect_DrawAll(struct GraphicsContext* gfxCtx);
void Effect_UpdateAll(struct GlobalContext* globalCtx);
void Effect_Delete(struct GlobalContext* globalCtx, s32 index);
void Effect_DeleteAll(struct GlobalContext* globalCtx);
void EffectSs_InitInfo(struct GlobalContext* globalCtx, s32 tableSize);
void EffectSs_ClearAll(struct GlobalContext* globalCtx);
void EffectSs_Delete(EffectSs* effectSs);
void EffectSs_Reset(EffectSs* effectSs);
void EffectSs_Insert(struct GlobalContext* globalCtx, EffectSs* effectSs);
void EffectSs_Spawn(struct GlobalContext* globalCtx, s32 type, s32 priority, void* initParams);
void EffectSs_UpdateAll(struct GlobalContext* globalCtx);
void EffectSs_DrawAll(struct GlobalContext* globalCtx);
s16 func_80027DD4(s16 arg0, s16 arg1, s32 arg2);
s16 func_80027E34(s16 arg0, s16 arg1, f32 arg2);
u8 func_80027E84(u8 arg0, u8 arg1, f32 arg2);
void EffectSs_DrawGEffect(struct GlobalContext* globalCtx, EffectSs* thiss, void* texture);
void EffectSsDust_Spawn(struct GlobalContext* globalCtx, u16 drawFlags, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life,
    u8 updateMode);
void func_8002829C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_80028304(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_8002836C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_800283D4(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_8002843C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_800284A4(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_80028510(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_8002857C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void func_800285EC(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void func_8002865C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep);
void func_800286CC(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep);
void func_8002873C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 life);
void func_800287AC(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 life);
void func_8002881C(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor);
void func_80028858(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor);
void func_80028990(struct GlobalContext* globalCtx, f32 randScale, Vec3f* srcPos);
void func_80028A54(struct GlobalContext* globalCtx, f32 randScale, Vec3f* srcPos);
void EffectSsKiraKira_SpawnSmallYellow(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsKiraKira_SpawnSmall(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor);
void EffectSsKiraKira_SpawnDispersed(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s32 life);
void EffectSsKiraKira_SpawnFocused(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s32 life);
void EffectSsBomb_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsBomb2_SpawnFade(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsBomb2_SpawnLayered(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
    s16 scaleStep);
void EffectSsBlast_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
    Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 sclaeStepDecay, s16 life);
void EffectSsBlast_SpawnWhiteCustomScale(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
    s16 scaleStep, s16 life);
void EffectSsBlast_SpawnShockwave(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 life);
void EffectSsBlast_SpawnWhiteShockwave(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsGSpk_SpawnAccel(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnNoAccel(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnFuse(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsGSpk_SpawnRandColor(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnSmall(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor);
void EffectSsDFire_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 alpha, s16 fadeDelay, s32 life);
void EffectSsDFire_SpawnFixedScale(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 alpha,
    s16 fadeDelay);
void EffectSsBubble_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, f32 yPosOffset, f32 yPosRandScale, f32 xzPosRandScale,
    f32 scale);
void EffectSsGRipple_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, s16 radius, s16 radiusMax, s16 life);
void EffectSsGSplash_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
    s16 type, s16 scale);
void EffectSsGMagma_Spawn(struct GlobalContext* globalCtx, Vec3f* pos);
void EffectSsGFire_Spawn(struct GlobalContext* globalCtx, Vec3f* pos);
void EffectSsLightning_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
    s16 scale, s16 yaw, s16 life, s16 numBolts);
void EffectSsDtBubble_SpawnColorProfile(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
    s16 life, s16 colorProfile, s16 randXZ);
void EffectSsDtBubble_SpawnCustomColor(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 life, s16 randXZ);
void EffectSsHahen_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 unused, s16 scale,
    s16 objId, s16 life, Gfx* dList);
void EffectSsHahen_SpawnBurst(struct GlobalContext* globalCtx, Vec3f* pos, f32 burstScale, s16 unused, s16 scale,
    s16 randScaleRange, s16 count, s16 objId, s16 life, Gfx* dList);
void EffectSsStick_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, s16 yaw);
void EffectSsSibuki_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 moveDelay,
    s16 direction, s16 scale);
void EffectSsSibuki_SpawnBurst(struct GlobalContext* globalCtx, Vec3f* pos);
void EffectSsSibuki2_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale);
void EffectSsGMagma2_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
    s16 updateRate, s16 drawMode, s16 scale);
void EffectSsStone1_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, s32 arg2);
void EffectSsHitMark_Spawn(struct GlobalContext* globalCtx, s32 type, s16 scale, Vec3f* pos);
void EffectSsHitMark_SpawnFixedScale(struct GlobalContext* globalCtx, s32 type, Vec3f* pos);
void EffectSsHitMark_SpawnCustomScale(struct GlobalContext* globalCtx, s32 type, s16 scale, Vec3f* pos);
void EffectSsFhgFlash_SpawnLightBall(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
    u8 param);
void EffectSsFhgFlash_SpawnShock(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, s16 scale, u8 param);
void EffectSsKFire_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scaleMax, u8 type);
void EffectSsSolderSrchBall_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 unused,
    s16* linkDetected);
void EffectSsKakera_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* arg3, s16 gravity, s16 arg5,
    s16 arg6, s16 arg7, s16 arg8, s16 scale, s16 arg10, s16 arg11, s32 life, s16 colorIdx,
    s16 objId, Gfx* dList);
void EffectSsIcePiece_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, f32 scale, Vec3f* velocity, Vec3f* accel, s32 life);
void EffectSsIcePiece_SpawnBurst(struct GlobalContext* globalCtx, Vec3f* refPos, f32 scale);
void EffectSsEnIce_SpawnFlyingVec3f(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, s16 primR, s16 primG, s16 primB,
    s16 primA, s16 envR, s16 envG, s16 envB, f32 scale);
void EffectSsEnIce_SpawnFlyingVec3s(struct GlobalContext* globalCtx, struct Actor* actor, Vec3s* pos, s16 primR, s16 primG, s16 primB,
    s16 primA, s16 envR, s16 envG, s16 envB, f32 scale);
void EffectSsEnIce_Spawn(struct GlobalContext* arg0, Vec3f* pos, f32 scale, Vec3f* velocity, Vec3f* accel,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s32 life);
void EffectSsFireTail_Spawn(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, f32 scale, Vec3f* arg4, s16 arg5,
    Color_RGBA8* primColor, Color_RGBA8* envColor, s16 type, s16 bodyPart, s32 life);
void EffectSsFireTail_SpawnFlame(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, f32 arg3, s16 bodyPart,
    f32 colorIntensity);
void EffectSsFireTail_SpawnFlameOnPlayer(struct GlobalContext* globalCtx, f32 scale, s16 bodyPart, f32 colorIntensity);
void EffectSsEnFire_SpawnVec3f(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, s16 scale, s16 unk_12, s16 flags,
    s16 bodyPart);
void EffectSsEnFire_SpawnVec3s(struct GlobalContext* globalCtx, struct Actor* actor, Vec3s* vec, s16 scale, s16 arg4, s16 flags,
    s16 bodyPart);
void EffectSsExtra_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scoreIdx);
void EffectSsFCircle_Spawn(struct GlobalContext* globalCtx, struct Actor* actor, Vec3f* pos, s16 radius, s16 height);
void EffectSsDeadDb_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 primR, s16 primG, s16 primB, s16 primA, s16 envR, s16 envG, s16 envB, s16 unused,
    s32 arg14, s16 playSound);
void EffectSsDeadDd_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 primR, s16 primG, s16 primB, s16 alpha, s16 envR, s16 envG, s16 envB, s16 alphaStep,
    s32 life);
void EffectSsDeadDd_SpawnRandYellow(struct GlobalContext* globalCtx, Vec3f* pos, s16 scale, s16 scaleStep, f32 randPosScale,
    s32 randIter, s32 life);
void EffectSsDeadDs_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
    s16 alpha, s32 life);
void EffectSsDeadDs_SpawnStationary(struct GlobalContext* globalCtx, Vec3f* pos, s16 scale, s16 scaleStep, s16 alpha,
    s32 life);
void EffectSsDeadSound_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u16 sfxId,
    s16 lowerPriority, s16 repeatMode, s32 life);
void EffectSsDeadSound_SpawnStationary(struct GlobalContext* globalCtx, Vec3f* pos, u16 sfxId, s16 lowerPriority,
    s16 repeatMode, s32 life);
void EffectSsIceSmoke_Spawn(struct GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale);

extern EffectSsOverlay gEffectSsOverlayTable[EFFECT_SS_TYPE_MAX];

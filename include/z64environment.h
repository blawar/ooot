#pragma once

#include "z64math.h"
#include "z64light.h"
#include "z64dma.h"

#define FILL_SCREEN_OPA (1 << 0)
#define FILL_SCREEN_XLU (1 << 1)

enum LightningMode {
    /* 0 */ LIGHTNING_MODE_OFF, // no lightning
    /* 1 */ LIGHTNING_MODE_ON, // request ligtning strikes at random intervals
    /* 2 */ LIGHTNING_MODE_LAST // request one lightning strike before turning off
};

enum LightningStrikeState {
    /* 0 */ LIGHTNING_STRIKE_WAIT, // wait between lightning strikes. request bolts when timer hits 0
    /* 1 */ LIGHTNING_STRIKE_START, // fade in the flash. note: bolts are requested in the previous state
    /* 2 */ LIGHTNING_STRIKE_END // fade out the flash and go back to wait
};

enum SkyboxDmaState {
    /*  0 */ SKYBOX_DMA_INACTIVE,
    /*  1 */ SKYBOX_DMA_FILE1_START,
    /*  2 */ SKYBOX_DMA_FILE1_DONE,
    /*  3 */ SKYBOX_DMA_PAL1_START,
    /* 11 */ SKYBOX_DMA_FILE2_START = 11,
    /* 12 */ SKYBOX_DMA_FILE2_DONE,
    /* 13 */ SKYBOX_DMA_PAL2_START
};

struct LightningStrike {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 flashRed;
    /* 0x02 */ u8 flashGreen;
    /* 0x03 */ u8 flashBlue;
    /* 0x04 */ u8 flashAlphaTarget;
    /* 0x08 */ f32 delayTimer;
}; // size = 0xC

// describes what skybox files and blending modes to use depending on time of day
struct struct_8011FC1C {
    /* 0x00 */ u16 startTime;
    /* 0x02 */ u16 endTime;
    /* 0x04 */ u8 blend; // if true, blend between.. skyboxes? palettes?
    /* 0x05 */ u8 skybox1Index; // whats the difference between _pal and non _pal files?
    /* 0x06 */ u8 skybox2Index;
}; // size = 0x8

struct EnvLightSettings {
    /* 0x00 */ u8 ambientColor[3];
    /* 0x03 */ s8 light1Dir[3];
    /* 0x06 */ u8 light1Color[3];
    /* 0x09 */ s8 light2Dir[3];
    /* 0x0C */ u8 light2Color[3];
    /* 0x0F */ u8 fogColor[3];
    /* 0x12 */ s16 fogNear;
    /* 0x14 */ s16 fogFar;
}; // size = 0x16

// 1.0: 801D8EC4
// dbg: 80222A44
struct EnvironmentContext {
    /* 0x00 */ char unk_00[0x02];
    /* 0x02 */ u16 timeIncrement; // how many units of time that pass every update
    /* 0x04 */ Vec3f sunPos; // moon position can be found by negating the sun position
    /* 0x10 */ u8 skybox1Index;
    /* 0x11 */ u8 skybox2Index;
    /* 0x12 */ char unk_12[0x01];
    /* 0x13 */ u8 skyboxBlend;
    /* 0x14 */ char unk_14[0x01];
    /* 0x15 */ u8 skyboxDisabled;
    /* 0x16 */ u8 sunMoonDisabled;
    /* 0x17 */ u8 unk_17; // currentWeatherMode for skybox? (prev called gloomySky)
    /* 0x18 */ u8 unk_18; // nextWeatherMode for skybox?
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ char unk_1C[0x02];
    /* 0x1E */ u8 indoors; // when set, day time has no effect on lighting
    /* 0x1F */ u8 unk_1F; // outdoor light index
    /* 0x20 */ u8 unk_20; // prev outdoor light index?
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ char unk_26[0x02];
    /* 0x28 */ LightInfo dirLight1; // used for sunlight outdoors
    /* 0x36 */ LightInfo dirLight2; // used for moonlight outdoors
    /* 0x44 */ s8 skyboxDmaState;
    /* 0x48 */ DmaRequest dmaRequest;
    /* 0x68 */ OSMesgQueue loadQueue;
    /* 0x80 */ OSMesg loadMsg;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ s16 adjAmbientColor[3];
    /* 0x92 */ s16 adjLight1Color[3];
    /* 0x98 */ s16 adjFogColor[3];
    /* 0x9E */ s16 adjFogNear;
    /* 0xA0 */ s16 adjFogFar;
    /* 0xA2 */ char unk_A2[0x06];
    /* 0xA8 */ Vec3s windDirection;
    /* 0xB0 */ f32 windSpeed;
    /* 0xB4 */ u8 numLightSettings;
    /* 0xB8 */ EnvLightSettings* lightSettingsList; // list of light settings from the scene file
    /* 0xBC */ u8 blendIndoorLights; // when true, blend between indoor light settings when switching
    /* 0xBD */ u8 unk_BD; // indoor light index
    /* 0xBE */ u8 unk_BE; // prev indoor light index?
    /* 0xBF */ u8 unk_BF;
    /* 0xC0 */ EnvLightSettings lightSettings;
    /* 0xD6 */ u16 unk_D6;
    /* 0xD8 */ f32 unk_D8; // indoor light blend weight?
    /* 0xDC */ u8 unk_DC;
    /* 0xDD */ u8 gloomySkyMode;
    /* 0xDE */ u8 unk_DE; // gloomy sky state
    /* 0xDF */ u8 lightningMode;
    /* 0xE0 */ u8 unk_E0; // env sounds state
    /* 0xE1 */ u8 fillScreen;
    /* 0xE2 */ u8 screenFillColor[4];
    /* 0xE6 */ u8 sandstormState;
    /* 0xE7 */ u8 sandstormPrimA;
    /* 0xE8 */ u8 sandstormEnvA;
    /* 0xE9 */ u8 customSkyboxFilter;
    /* 0xEA */ u8 skyboxFilterColor[4];
    /* 0xEE */ u8 unk_EE[4];
    /* 0xF2 */ u8 unk_F2[4];
    /* 0xF6 */ char unk_F6[0x06];
}; // size = 0xFC

u16 Environment_GetPixelDepth(s32 x, s32 y);
void Environment_GraphCallback(struct GraphicsContext* gfxCtx, void* param);
void Environment_Init(struct GlobalContext* globalCtx, EnvironmentContext* envCtx, s32 unused);
u8 Environment_SmoothStepToU8(u8* pvalue, u8 target, u8 scale, u8 step, u8 minStep);
u8 Environment_SmoothStepToS8(s8* pvalue, s8 target, u8 scale, u8 step, u8 minStep);
f32 Environment_LerpWeight(u16 max, u16 min, u16 val);
f32 Environment_LerpWeight(const Counter max, const Counter min, const Counter val);
f32 Environment_LerpWeight(u16 max, u16 min, const Counter val);
f32 Environment_LerpWeightAccelDecel(u16 endFrame, u16 startFrame, u16 curFrame, u16 accelDuration, u16 decelDuration);
void Environment_UpdateSkybox(u8 skyboxId, EnvironmentContext* envCtx, SkyboxContext* skyboxCtx);
void Environment_EnableUnderwaterLights(struct GlobalContext* globalCtx, s32 waterLightsIndex);
void Environment_DisableUnderwaterLights(struct GlobalContext* globalCtx);
void Environment_Update(struct GlobalContext* globalCtx, EnvironmentContext* envCtx, LightContext* lightCtx,
    PauseContext* pauseCtx, MessageContext* msgCtx, GameOverContext* gameOverCtx,
    struct GraphicsContext* gfxCtx);
void Environment_DrawSunAndMoon(struct GlobalContext* globalCtx);
void Environment_DrawSunLensFlare(struct GlobalContext* globalCtx, EnvironmentContext* envCtx, View* view,
    struct GraphicsContext* gfxCtx, Vec3f pos, s32 unused);
void Environment_DrawLensFlare(struct GlobalContext* globalCtx, EnvironmentContext* envCtx, View* view,
    struct GraphicsContext* gfxCtx, Vec3f pos, s32 unused, s16 arg6, f32 arg7, s16 arg8, u8 arg9);
void Environment_DrawRain(struct GlobalContext* globalCtx, View* view, struct GraphicsContext* gfxCtx);
void func_80074CE8(struct GlobalContext* globalCtx, u32 arg1);
void Environment_DrawSkyboxFilters(struct GlobalContext* globalCtx);
void Environment_UpdateLightningStrike(struct GlobalContext* globalCtx);
void Environment_AddLightningBolts(struct GlobalContext* globalCtx, u8 num);
void Environment_DrawLightning(struct GlobalContext* globalCtx, s32 unused);
void func_800758AC(struct GlobalContext* globalCtx);
void Environment_DrawCustomLensFlare(struct GlobalContext* globalCtx);
void Environment_InitGameOverLights(struct GlobalContext* globalCtx);
void Environment_FadeInGameOverLights(struct GlobalContext* globalCtx);
void Environment_FadeOutGameOverLights(struct GlobalContext* globalCtx);
void Environment_FillScreen(struct GraphicsContext* gfxCtx, u8 red, u8 green, u8 blue, u8 alpha, u8 drawFlags);
void Environment_DrawSandstorm(struct GlobalContext* globalCtx, u8 sandstormState);
void Environment_AdjustLights(struct GlobalContext* globalCtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 Environment_GetBgsDayCount(void);
void Environment_ClearBgsDayCount(void);
s32 Environment_GetTotalDays(void);
void Environment_ForcePlaySequence(u16);
s32 Environment_IsForcedSequenceDisabled(void);
void func_80077624(struct GlobalContext* globalCtx);
void func_80077684(struct GlobalContext* globalCtx);
void Environment_WarpSongLeave(struct GlobalContext* globalCtx);


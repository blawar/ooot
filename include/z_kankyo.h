#pragma once
#include "ultra64/types.h"
#include "z64environment.h"

s32 func_8006F0A0(s32 arg0);

extern LightningStrike gLightningStrike;
extern u8 gCustomLensFlareOn;
extern Vec3f gCustomLensFlarePos;
extern s16 gLensFlareScale;
extern f32 gLensFlareColorIntensity;
extern s16 gLensFlareScreenFillAlpha;

extern Mtx D_01000000;

extern u8 gWeatherMode;
extern u16 gTimeIncrement;

extern SkyboxFile gSkyboxFiles[];
extern struct_8011FC1C D_8011FC1C[][9];

extern u8 D_8011FB38;
extern u8 D_8011FB34;
extern u8 gSkyboxBlendingEnabled;


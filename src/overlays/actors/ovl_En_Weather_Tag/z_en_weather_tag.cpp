#define INTERNAL_SRC_OVERLAYS_ACTORS_OVL_EN_WEATHER_TAG_Z_EN_WEATHER_TAG_C
#include "actor_common.h"
#include "z_kankyo.h"
/*
 * File: z_en_weather_tag.c
 * Overlay: ovl_En_Weather_Tag
 * Description: Proximity Activated Weather Effects
 */

#include "z_en_weather_tag.h"
#include "vt.h"
#include "def/z_actor.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_lib.h"

#define FLAGS ACTOR_FLAG_4

void EnWeatherTag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnWeatherTag_Reset(Actor* pthisx, GlobalContext* globalCtx);
void EnWeatherTag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnWeatherTag_Update(Actor* thisx, GlobalContext* globalCtx);

void EnWeatherTag_DisabledCloudyHyruleMarket(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledCloudyHyruleMarket(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledCloudyLonLonRanch(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledCloudyLonLonRanch(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledCloudySnow(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledCloudySnow(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledRainLakeHylia(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledRainLakeHylia(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledCloudyDeathMountain(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledCloudyDeathMountain(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledCloudyRainThunderKakariko(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledCloudyRainThunderKakariko(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_SetSandstormIntensity(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_DisabledRainThunder(EnWeatherTag* pthis, GlobalContext* globalCtx);
void EnWeatherTag_EnabledRainThunder(EnWeatherTag* pthis, GlobalContext* globalCtx);

#define WEATHER_TAG_RANGE100(x) ((x >> 8) * 100.0f)

ActorInit En_Weather_Tag_InitVars = {
    ACTOR_EN_WEATHER_TAG,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnWeatherTag),
    (ActorFunc)EnWeatherTag_Init,
    (ActorFunc)EnWeatherTag_Destroy,
    (ActorFunc)EnWeatherTag_Update,
    NULL,
    (ActorFunc)EnWeatherTag_Reset,
};

void EnWeatherTag_SetupAction(EnWeatherTag* pthis, EnWeatherTagActionFunc actionFunc) {
    pthis->actionFunc = actionFunc;
}

void EnWeatherTag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnWeatherTag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnWeatherTag* pthis = (EnWeatherTag*)thisx;

    pthis->actor.flags &= ~ACTOR_FLAG_0;

    switch (pthis->actor.params & 0xF) {
        case EN_WEATHER_TAG_TYPE_CLOUDY_MARKET:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ (;o;) About ☆☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ （;o;) くらいよー ☆☆☆☆☆ \n" VT_RST);
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyHyruleMarket);
            break;
        case EN_WEATHER_TAG_TYPE_CLOUDY_LON_LON_RANCH:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Cloudy (._.) Ah Melancholy ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ くもり (._.) あーあ 憂鬱 ☆☆☆☆☆ \n" VT_RST);
            if (Flags_GetEventChkInf(0x18)) {
                Actor_Kill(&pthis->actor);
            }
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyLonLonRanch);
            break;
        case EN_WEATHER_TAG_TYPE_SNOW_ZORAS_DOMAIN:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Yukigafuru You won't come (._.) ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ ゆきがふるー あなたはこないー (._.) ☆☆☆☆☆ \n" VT_RST);

            if (gSaveContext.eventChkInf[4] & 0x400) {
                Actor_Kill(&pthis->actor);
            }
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudySnow);
            break;
        case EN_WEATHER_TAG_TYPE_RAIN_LAKE_HYLIA:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Wow wa wa na wa saa ki ha (^o^) ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ わわわわー なーがーさーきーはー (^o^) ☆☆☆☆☆ \n" VT_RST);

            if (gSaveContext.eventChkInf[4] & 0x400) {
                Actor_Kill(&pthis->actor);
            }
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledRainLakeHylia);
            break;
        case EN_WEATHER_TAG_TYPE_CLOUDY_DEATH_MOUNTAIN:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Cloudy (._.) Ah Melancholy ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ くもり (._.) あーあ 憂鬱 ☆☆☆☆☆ \n" VT_RST);
            if (gSaveContext.eventChkInf[4] & 0x200) {
                Actor_Kill(&pthis->actor);
            }
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyDeathMountain);
            break;
        case EN_WEATHER_TAG_TYPE_THUNDERSTORM_KAKARIKO:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Cloudy Rain Thunder (;O;) Uo Melancholy ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ くもり雨雷 (;O;) うおお 憂鬱 ☆☆☆☆☆ \n" VT_RST);

            if (!(gSaveContext.eventChkInf[4] & 0x100) || !(gSaveContext.eventChkInf[4] & 0x200) ||
                !(gSaveContext.eventChkInf[4] & 0x400) || CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW)) {
                Actor_Kill(&pthis->actor);
            }
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyRainThunderKakariko);
            break;
        case EN_WEATHER_TAG_TYPE_SANDSTORM_INTENSITY:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ The desert becomes thicker ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ 砂漠が濃くなります ☆☆☆☆☆ \n" VT_RST);
            EnWeatherTag_SetupAction(pthis, EnWeatherTag_SetSandstormIntensity);
            break;
        case EN_WEATHER_TAG_TYPE_THUNDERSTORM_GRAVEYARD:
            osSyncPrintf("\n\n");
            // "☆☆☆☆☆ Wow wa wa na wa saa ki ha (^o^) ☆☆☆☆☆"
            osSyncPrintf(VT_FGCOL(YELLOW) "☆☆☆☆☆ わわわわー なーがーさーきーはー (^o^) ☆☆☆☆☆ \n" VT_RST);

            EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledRainThunder);
            break;
    }
}

u8 WeatherTag_CheckEnableWeatherEffect(EnWeatherTag* pthis, GlobalContext* globalCtx, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                                       u16 arg6, u8 weatherMode) {
    s32 pad;
    u8 ret = false;
    Player* player = GET_PLAYER(globalCtx);

    if (Actor_WorldDistXZToActor(&player->actor, &pthis->actor) < WEATHER_TAG_RANGE100(pthis->actor.params)) {
        if ((globalCtx->envCtx.indoors != 0) || !gSkyboxBlendingEnabled ||
            (globalCtx->skyboxId != SKYBOX_NORMAL_SKY && globalCtx->envCtx.unk_1F == globalCtx->envCtx.unk_20)) {
            D_8011FB38 = 1;
            if (globalCtx->envCtx.gloomySkyMode == 0 &&
                (globalCtx->envCtx.indoors != 0 || (globalCtx->envCtx.unk_1F != 1 && globalCtx->envCtx.unk_21 == 0))) {
                D_8011FB38 = 0;
                if (gWeatherMode != weatherMode) {
                    gWeatherMode = weatherMode;
                    if (globalCtx->envCtx.gloomySkyMode == 0) {
                        globalCtx->envCtx.unk_19 = 1;
                        globalCtx->envCtx.unk_17 = arg2;
                        globalCtx->envCtx.unk_18 = arg3;
                        globalCtx->envCtx.unk_1A = arg6;
                        globalCtx->envCtx.unk_21 = 1;
                        globalCtx->envCtx.unk_1F = arg4;
                        globalCtx->envCtx.unk_20 = arg5;
                        D_8011FB34 = arg5;
                        globalCtx->envCtx.unk_24 = arg6;
                        globalCtx->envCtx.unk_22 = globalCtx->envCtx.unk_24;
                    }
                }
                ret = true;
            }
        } else {
            if (gTimeIncrement != 0) {
                gSaveContext.dayTime += 0x14;
            }
        }
    }

    return ret;
}

u8 WeatherTag_CheckRestoreWeather(EnWeatherTag* pthis, GlobalContext* globalCtx, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                                  u16 arg6) {
    s32 pad;
    u8 ret = false;
    Player* player = GET_PLAYER(globalCtx);

    if ((WEATHER_TAG_RANGE100(pthis->actor.params) + 100.0f) < Actor_WorldDistXZToActor(&player->actor, &pthis->actor)) {
        if (globalCtx->envCtx.indoors != 0 || !gSkyboxBlendingEnabled ||
            (globalCtx->skyboxId != SKYBOX_NORMAL_SKY && globalCtx->envCtx.unk_1F == globalCtx->envCtx.unk_20)) {
            D_8011FB38 = 1;
            if ((globalCtx->envCtx.gloomySkyMode == 0) &&
                (globalCtx->envCtx.indoors != 0 || (globalCtx->envCtx.unk_1F != 1 && globalCtx->envCtx.unk_21 == 0))) {
                D_8011FB38 = 0;
                gWeatherMode = 0;
                globalCtx->envCtx.unk_19 = 1;
                globalCtx->envCtx.unk_17 = arg2;
                globalCtx->envCtx.unk_18 = arg3;
                globalCtx->envCtx.unk_1A = arg6;
                globalCtx->envCtx.unk_21 = 1;
                globalCtx->envCtx.unk_1F = arg4;
                globalCtx->envCtx.unk_20 = arg5;
                D_8011FB34 = arg5;
                globalCtx->envCtx.unk_24 = arg6;
                globalCtx->envCtx.unk_22 = globalCtx->envCtx.unk_24;

                ret = true;
            }
        } else if (gTimeIncrement != 0) {
            gSaveContext.dayTime += 0x14;
        }
    }
    return ret;
}

void EnWeatherTag_DisabledCloudyHyruleMarket(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 3, 60, 1)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledCloudyHyruleMarket);
    }
}

void EnWeatherTag_EnabledCloudyHyruleMarket(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 3, 0, 60)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyHyruleMarket);
    }
}

void EnWeatherTag_DisabledCloudyLonLonRanch(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 2, 100, 2)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledCloudyLonLonRanch);
    }
}

void EnWeatherTag_EnabledCloudyLonLonRanch(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 2, 0, 100)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyLonLonRanch);
    }
}

void EnWeatherTag_DisabledCloudyDeathMountain(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 2, 60, 2)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledCloudyDeathMountain);
    }
}

void EnWeatherTag_EnabledCloudyDeathMountain(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 2, 0, 60)) {
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyLonLonRanch);
    }
}

void EnWeatherTag_DisabledCloudySnow(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 2, 60, 3)) {
        globalCtx->envCtx.unk_EE[3] = 64;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledCloudySnow);
    }
}

void EnWeatherTag_EnabledCloudySnow(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 2, 0, 60)) {
        globalCtx->envCtx.unk_EE[3] = 0;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudySnow);
    }
}

void EnWeatherTag_DisabledRainLakeHylia(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 2, 100, 4)) {
        func_80077624(globalCtx);
        globalCtx->envCtx.unk_EE[0] = 25;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledRainLakeHylia);
    }
}

void EnWeatherTag_EnabledRainLakeHylia(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 2, 0, 100)) {
        func_80077684(globalCtx);
        globalCtx->envCtx.unk_EE[0] = 0;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledRainLakeHylia);
    }
}

void EnWeatherTag_DisabledCloudyRainThunderKakariko(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckEnableWeatherEffect(pthis, globalCtx, 0, 1, 0, 4, 100, 5)) {
        func_80077624(globalCtx);
        globalCtx->envCtx.lightningMode = LIGHTNING_MODE_ON;
        globalCtx->envCtx.unk_EE[0] = 30;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledCloudyRainThunderKakariko);
    }
}

void EnWeatherTag_EnabledCloudyRainThunderKakariko(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    if (WeatherTag_CheckRestoreWeather(pthis, globalCtx, 1, 0, 4, 0, 100)) {
        func_80077684(globalCtx);
        globalCtx->envCtx.lightningMode = LIGHTNING_MODE_LAST;
        globalCtx->envCtx.unk_EE[0] = 0;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledCloudyRainThunderKakariko);
    }
}

void EnWeatherTag_SetSandstormIntensity(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (Actor_WorldDistXZToActor(&player->actor, &pthis->actor) < WEATHER_TAG_RANGE100(pthis->actor.params)) {
        Math_SmoothStepToS(&globalCtx->envCtx.adjFogNear, -0x50, 1, 2, 1);
        Math_SmoothStepToS(&globalCtx->envCtx.adjFogFar, -0x7D0, 1, 50, 1);
    } else {
        Math_SmoothStepToS(&globalCtx->envCtx.adjFogNear, 0, 1, 1, 1);
        Math_SmoothStepToS(&globalCtx->envCtx.adjFogFar, 0, 1, 25, 1);
    }
}

void EnWeatherTag_DisabledRainThunder(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (Actor_WorldDistXZToActor(&player->actor, &pthis->actor) < WEATHER_TAG_RANGE100(pthis->actor.params)) {
        func_80077624(globalCtx);
        globalCtx->envCtx.lightningMode = LIGHTNING_MODE_ON;
        globalCtx->envCtx.unk_EE[0] = 25;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_EnabledRainThunder);
    }
}

void EnWeatherTag_EnabledRainThunder(EnWeatherTag* pthis, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if ((WEATHER_TAG_RANGE100(pthis->actor.params) + 10.0f) < Actor_WorldDistXZToActor(&player->actor, &pthis->actor)) {
        func_80077684(globalCtx);
        globalCtx->envCtx.lightningMode = LIGHTNING_MODE_LAST;
        globalCtx->envCtx.unk_EE[0] = 0;
        globalCtx->envCtx.unk_EE[1] = 10;
        EnWeatherTag_SetupAction(pthis, EnWeatherTag_DisabledRainThunder);
    }
}

void EnWeatherTag_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnWeatherTag* pthis = (EnWeatherTag*)thisx;

    pthis->actionFunc(pthis, globalCtx);
}

void EnWeatherTag_Reset(Actor* pthisx, GlobalContext* globalCtx) {
    En_Weather_Tag_InitVars = {
        ACTOR_EN_WEATHER_TAG,
        ACTORCAT_PROP,
        FLAGS,
        OBJECT_GAMEPLAY_KEEP,
        sizeof(EnWeatherTag),
        (ActorFunc)EnWeatherTag_Init,
        (ActorFunc)EnWeatherTag_Destroy,
        (ActorFunc)EnWeatherTag_Update,
        NULL,
        (ActorFunc)EnWeatherTag_Reset,
    };

}

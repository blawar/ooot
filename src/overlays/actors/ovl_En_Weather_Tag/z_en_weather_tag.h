#pragma once
#define Z_EN_WEATHER_TAG_H

#include "global.h"
#include "ultra64.h"

struct EnWeatherTag;

typedef void (*EnWeatherTagActionFunc)(struct EnWeatherTag*, GlobalContext*);

struct EnWeatherTag
{
	/* 0x0000 */ Actor actor;
	/* 0x014C */ EnWeatherTagActionFunc actionFunc;
	/* 0x0150 */ char unk_150[0x04];
};

enum EnWeatherTagType
{
	/* 0x00 */ EN_WEATHER_TAG_TYPE_CLOUDY_MARKET,
	/* 0x01 */ EN_WEATHER_TAG_TYPE_CLOUDY_LON_LON_RANCH,
	/* 0x02 */ EN_WEATHER_TAG_TYPE_SNOW_ZORAS_DOMAIN,
	/* 0x03 */ EN_WEATHER_TAG_TYPE_RAIN_LAKE_HYLIA,
	/* 0x04 */ EN_WEATHER_TAG_TYPE_CLOUDY_DEATH_MOUNTAIN,
	/* 0x05 */ EN_WEATHER_TAG_TYPE_THUNDERSTORM_KAKARIKO,
	/* 0x06 */ EN_WEATHER_TAG_TYPE_SANDSTORM_INTENSITY,
	/* 0x07 */ EN_WEATHER_TAG_TYPE_THUNDERSTORM_GRAVEYARD
};

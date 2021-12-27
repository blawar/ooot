#pragma once
#include "z64scene.h"

static_assert(offsetof(SCmdBase, code) == 0, "Bad SCmdBase.code alignment");
static_assert(offsetof(SCmdBase, data1) == 1, "Bad SCmdBase.data1 alignment");
static_assert(offsetof(SCmdBase, data2) == 4, "Bad SCmdBase.data2 alignment");

static_assert(offsetof(SCmdWindSettings, code) == 0, "Bad SCmdWindSettings.code alignment");
static_assert(offsetof(SCmdWindSettings, data1) == 1, "Bad SCmdWindSettings.data1 alignment");
static_assert(offsetof(SCmdWindSettings, pad) == 2, "Bad SCmdWindSettings.pad alignment");
static_assert(offsetof(SCmdWindSettings, x) == 4, "Bad SCmdWindSettings.x alignment");
static_assert(offsetof(SCmdWindSettings, y) == 5, "Bad SCmdWindSettings.y alignment");
static_assert(offsetof(SCmdWindSettings, z) == 6, "Bad SCmdWindSettings.z alignment");
static_assert(offsetof(SCmdWindSettings, unk_07) == 7, "Bad SCmdWindSettings.unk_07 alignment");



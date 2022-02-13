#pragma once
#include "ultra64/types.h"
#include "z64.h"
#include "z64math.h"
#include "listalloc.h"
#include "gfx.h"

enum SkyboxId {
    /* 0x00 */ SKYBOX_NONE,
    /* 0x01 */ SKYBOX_NORMAL_SKY,
    /* 0x02 */ SKYBOX_BAZAAR,
    /* 0x03 */ SKYBOX_OVERCAST_SUNSET,
    /* 0x04 */ SKYBOX_MARKET_ADULT,
    /* 0x05 */ SKYBOX_CUTSCENE_MAP,
    /* 0x07 */ SKYBOX_HOUSE_LINK = 7,
    /* 0x09 */ SKYBOX_MARKET_CHILD_DAY = 9,
    /* 0x0A */ SKYBOX_MARKET_CHILD_NIGHT,
    /* 0x0B */ SKYBOX_HAPPY_MASK_SHOP,
    /* 0x0C */ SKYBOX_HOUSE_KNOW_IT_ALL_BROTHERS,
    /* 0x0E */ SKYBOX_HOUSE_OF_TWINS = 14,
    /* 0x0F */ SKYBOX_STABLES,
    /* 0x10 */ SKYBOX_HOUSE_KAKARIKO,
    /* 0x11 */ SKYBOX_KOKIRI_SHOP,
    /* 0x13 */ SKYBOX_GORON_SHOP = 19,
    /* 0x14 */ SKYBOX_ZORA_SHOP,
    /* 0x16 */ SKYBOX_POTION_SHOP_KAKARIKO = 22,
    /* 0x17 */ SKYBOX_POTION_SHOP_MARKET,
    /* 0x18 */ SKYBOX_BOMBCHU_SHOP,
    /* 0x1A */ SKYBOX_HOUSE_RICHARD = 26,
    /* 0x1B */ SKYBOX_HOUSE_IMPA,
    /* 0x1C */ SKYBOX_TENT,
    /* 0x1D */ SKYBOX_UNSET_1D,
    /* 0x20 */ SKYBOX_HOUSE_MIDO = 32,
    /* 0x21 */ SKYBOX_HOUSE_SARIA,
    /* 0x22 */ SKYBOX_HOUSE_ALLEY,
    /* 0x27 */ SKYBOX_UNSET_27 = 39
};

struct SkyboxContext {
    /* 0x000 */ char unk_00[0x128];
    /* 0x128 */ void* staticSegments[2];
    /* 0x130 */ u16 (*palettes)[256];
    /* 0x134 */ Gfx (*dListBuf)[150];
    /* 0x138 */ Gfx* unk_138;
    /* 0x13C */ Vtx* roomVtx;
    /* 0x140 */ s16 unk_140;
    /* 0x144 */ Vec3f rot;
    /* 0x150 */ char unk_150[0x10];
}; // size = 0x160

struct PreRender {
    /* 0x00 */ s32 width;
    /* 0x04 */ s32 height;
    /* 0x08 */ s32 widthSave;
    /* 0x0C */ s32 heightSave;
    /* 0x10 */ u16* fbuf;
    /* 0x14 */ u16* fbufSave;
    /* 0x18 */ u8* cvgSave;
    /* 0x1C */ u16* zbuf;
    /* 0x20 */ u16* zbufSave;
    /* 0x24 */ s32 ulxSave;
    /* 0x28 */ s32 ulySave;
    /* 0x2C */ s32 lrxSave;
    /* 0x30 */ s32 lrySave;
    /* 0x34 */ s32 ulx;
    /* 0x38 */ s32 uly;
    /* 0x3C */ s32 lrx;
    /* 0x40 */ s32 lry;
    /* 0x44 */ ListAlloc alloc;
    /* 0x4C */ u32 unk_4C;
}; // size = 0x50

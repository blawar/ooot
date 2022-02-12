#pragma once
#include "z64animation.h"
#include "ultra64/types.h"
#include "view.h"

struct KaleidoMgrOverlay {
    /* 0x00 */ void* loadedRamAddr;
    /* 0x04 */ uintptr_t vromStart;
    /* 0x08 */ uintptr_t vromEnd;
    /* 0x0C */ void* vramStart;
    /* 0x10 */ void* vramEnd;
    /* 0x14 */ u32 offset; // loadedRamAddr - vramStart
    /* 0x18 */ const char* name;
}; // size = 0x1C

enum KaleidoOverlayType {
    /* 0x00 */ KALEIDO_OVL_KALEIDO_SCOPE,
    /* 0x01 */ KALEIDO_OVL_PLAYER_ACTOR,
    /* 0x02 */ KALEIDO_OVL_MAX
};

#define PAUSE_ITEM_NONE 999

#define PAUSE_CURSOR_PAGE_LEFT 10
#define PAUSE_CURSOR_PAGE_RIGHT 11

enum PauseMenuPage {
    /* 0x00 */ PAUSE_ITEM,
    /* 0x01 */ PAUSE_MAP,
    /* 0x02 */ PAUSE_QUEST,
    /* 0x03 */ PAUSE_EQUIP,
    /* 0x04 */ PAUSE_WORLD_MAP
};

struct PauseContext {
    /* 0x0000 */ View view;
    /* 0x0128 */ u8* iconItemSegment;
    /* 0x012C */ u8* iconItem24Segment;
    /* 0x0130 */ u8* iconItemAltSegment;
    /* 0x0134 */ u8* iconItemLangSegment;
    /* 0x0138 */ u8* nameSegment;
                 u8* uknSegment;
                 u8* uknSegment2;
                 u8* uknSegment3;
    /* 0x013C */ u8* playerSegment;
    /* 0x0140 */ char unk_140[0x04];
    /* 0x0144 */ Vtx* itemPageVtx;
    /* 0x0148 */ Vtx* equipPageVtx;
    /* 0x014C */ Vtx* mapPageVtx;
    /* 0x0150 */ Vtx* questPageVtx;
    /* 0x0154 */ Vtx* infoPanelVtx;
    /* 0x0158 */ Vtx* itemVtx;
    /* 0x015C */ Vtx* equipVtx;
    /* 0x0160 */ char unk_160[0x04];
    /* 0x0164 */ Vtx* questVtx;
    /* 0x0168 */ Vtx  cursorVtx[20];
    /* 0x016C */ Vtx* saveVtx;
    /* 0x0170 */ char unk_170[0x24];
    /* 0x0194 */ struct OcarinaStaff* ocarinaStaff;
    /* 0x0198 */ char unk_198[0x20];
    /* 0x01B8 */ OSMesgQueue loadQueue;
    /* 0x01D0 */ OSMesg loadMsg;
    /* 0x01D4 */ u16 state;
    /* 0x01D6 */ u16 debugState;
    /* 0x01D8 */ Vec3f eye;
    /* 0x01E4 */ u16 unk_1E4;
    /* 0x01E6 */ u16 mode;
    /* 0x01E8 */ u16 pageIndex; // "kscp_pos"
    /* 0x01EA */ u16 unk_1EA;
    /* 0x01EC */ u16 unk_1EC;
    /* 0x01F0 */ f32 unk_1F0;
    /* 0x01F4 */ f32 unk_1F4;
    /* 0x01F8 */ f32 unk_1F8;
    /* 0x01FC */ f32 unk_1FC;
    /* 0x0200 */ f32 unk_200;
    /* 0x0204 */ f32 unk_204; // "angle_s"
    /* 0x0208 */ u16 alpha;
    /* 0x020A */ s16 offsetY;
    /* 0x020C */ char unk_20C[0x08];
    /* 0x0214 */ s16 stickRelX;
    /* 0x0216 */ s16 stickRelY;
    /* 0x0218 */ s16 cursorPoint[5]; // "cursor_point"
    /* 0x0222 */ s16 cursorX[5];     // "cur_xpt"
    /* 0x022C */ s16 cursorY[5];     // "cur_ypt"
    /* 0x0236 */ s16 dungeonMapSlot;
    /* 0x0238 */ s16 cursorSpecialPos; // "key_angle"
    /* 0x023A */ s16 pageSwitchTimer;
    /* 0x023C */ u16 namedItem;     // "zoom_name"
    /* 0x023E */ u16 cursorItem[4]; // "select_name"
    /* 0x0246 */ u16 cursorSlot[4];
    /* 0x024E */ u16 equipTargetItem; // "sl_item_no"
    /* 0x0250 */ u16 equipTargetSlot; // "sl_number"
    /* 0x0252 */ u16 equipTargetCBtn;
    /* 0x0254 */ s16 equipAnimX;
    /* 0x0256 */ s16 equipAnimY;
    /* 0x0258 */ s16 equipAnimAlpha;
    /* 0x025A */ s16 infoPanelOffsetY;
    /* 0x025C */ u16 nameDisplayTimer;
    /* 0x025E */ u16 nameColorSet;   // 0 = white; 1 = grey
    /* 0x0260 */ s16 cursorColorSet; // 0 = white; 4 = yellow; 8 = green
    /* 0x0262 */ s16 promptChoice;   // save/continue choice: 0 = yes; 4 = no
    /* 0x0264 */ s16 ocarinaSongIdx;
    /* 0x0266 */ u8 worldMapPoints[20]; // 0 = hidden; 1 = displayed; 2 = highlighted
    /* 0x027A */ u8 tradeQuestLocation;
    /* 0x027C */ SkelAnime playerSkelAnime;
}; // size = 0x2C0

#define PAUSE_MAP_MARK_NONE -1
#define PAUSE_MAP_MARK_CHEST 0
#define PAUSE_MAP_MARK_BOSS 1

struct PauseMapMarkPoint {
    /* 0x00 */ s16
        chestFlag;       // chest icon is only displayed if this flag is not set for the current room, -1 for no flag
    /* 0x04 */ f32 x, y; // coordinates to place the icon (top-left corner)
};     // size = 0x0C

struct PauseMapMarkData {
    /* 0x00 */ s16 markType; // 0 for the chest icon, 1 for the boss skull icon, -1 for none
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ const Vtx* vtx;
    /* 0x0C */ s32 vtxCount;
    /* 0x10 */ s32 count; // number of icons to display
    /* 0x14 */ PauseMapMarkPoint points[12];
}; // size = 0xA4

typedef PauseMapMarkData PauseMapMarksData[3];



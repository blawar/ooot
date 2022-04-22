#pragma once
#include "ultra64/types.h"
#include "view.h"
#include "z64dma.h"

typedef struct InterfaceContext {
    /* 0x0000 */ View view;
    /* 0x0128 */ Vtx* actionVtx;
    /* 0x012C */ Vtx* beatingHeartVtx;
    /* 0x0130 */ u8* parameterSegment;
    /* 0x0134 */ u8* doActionSegment1;
                 u8* doActionSegment2;
                 u8* doActionSegment3;
    /* 0x0138 */ u8* iconItemSegment1;
                 u8* iconItemSegment2;
                 u8* iconItemSegment3;
                 u8* iconItemSegment4;
    /* 0x013C */ u8* mapSegment1;
                 u8* mapSegment2;
    /* 0x0140 */ u8 mapPalette[32];
    /* 0x0160 */ DmaRequest dmaRequest_160;
    /* 0x0180 */ DmaRequest dmaRequest_180;
    /* 0x01A0 */ char unk_1A0[0x20];
    /* 0x01C0 */ OSMesgQueue loadQueue;
    /* 0x01D8 */ OSMesg loadMsg;
    /* 0x01DC */ Viewport viewport;
    /* 0x01EC */ s16 unk_1EC;
    /* 0x01EE */ u16 unk_1EE;
    /* 0x01F0 */ u16 unk_1F0;
    /* 0x01F4 */ f32 unk_1F4;
    /* 0x01F8 */ s16 naviCalling;
    /* 0x01FA */ s16 unk_1FA;
    /* 0x01FC */ s16 unk_1FC;
    /* 0x01FE */ s16 heartColorOscillator;
    /* 0x0200 */ s16 heartColorOscillatorDirection;
    /* 0x0202 */ s16 beatingHeartPrim[3];
    /* 0x0208 */ s16 beatingHeartEnv[3];
    /* 0x020E */ s16 heartsPrimR[2];
    /* 0x0212 */ s16 heartsPrimG[2];
    /* 0x0216 */ s16 heartsPrimB[2];
    /* 0x021A */ s16 heartsEnvR[2];
    /* 0x021E */ s16 heartsEnvG[2];
    /* 0x0222 */ s16 heartsEnvB[2];
    /* 0x022A */ TimerS16 beatingHeartOscillator;
    /* 0x022C */ s16 beatingHeartOscillatorDirection;
    /* 0x022E */ s16 unk_22E;
    /* 0x0230 */ s16 unk_230;
    /* 0x0232 */ s16 counterDigits[4]; // used for key and rupee counters
    /* 0x023A */ u8 numHorseBoosts;
    /* 0x023C */ u16 unk_23C;
    /* 0x023E */ u16 hbaAmmo; // ammo while playing the horseback archery minigame
    /* 0x0240 */ u16 unk_240;
    /* 0x0242 */ u16 unk_242;
    /* 0x0224 */ u16 unk_244; // screen fill alpha?
    /* 0x0246 */ u16 aAlpha;  // also carrots alpha
    /* 0x0248 */ u16 bAlpha;  // also HBA score alpha
    /* 0x024A */ u16 cLeftAlpha;
    /* 0x024C */ u16 cDownAlpha;
    /* 0x024E */ u16 cRightAlpha;
    /* 0x0250 */ u16 healthAlpha; // also max C-Up alpha
    /* 0x0252 */ u16 magicAlpha;  // also Rupee and Key counters alpha
    /* 0x0254 */ u16 minimapAlpha;
    /* 0x0256 */ s16 startAlpha;
    /* 0x0258 */ s16 unk_258;
    /* 0x025A */ s16 unk_25A;
    /* 0x025C */ s16 mapRoomNum;
    /* 0x025E */ s16 mapPaletteIndex; // "map_palete_no"
    /* 0x0260 */ u8 unk_260;
    /* 0x0261 */ u8 unk_261;
    struct {
        /* 0x0262 */ u8 hGauge;     // "h_gage"; unknown?
        /* 0x0263 */ u8 bButton;    // "b_button"
        /* 0x0264 */ u8 aButton;    // "a_button"
        /* 0x0265 */ u8 bottles;    // "c_bottle"
        /* 0x0266 */ u8 tradeItems; // "c_warasibe"
        /* 0x0267 */ u8 hookshot;   // "c_hook"
        /* 0x0268 */ u8 ocarina;    // "c_ocarina"
        /* 0x0269 */ u8 warpSongs;  // "c_warp"
        /* 0x026A */ u8 sunsSong;   // "m_sunmoon"
        /* 0x026B */ u8 farores;    // "m_wind"
        /* 0x026C */ u8 dinsNayrus; // "m_magic"; din's fire and nayru's love
        /* 0x026D */ u8 all;        // "another"; enables all item restrictions
    } restrictions;
} InterfaceContext; // size = 0x270

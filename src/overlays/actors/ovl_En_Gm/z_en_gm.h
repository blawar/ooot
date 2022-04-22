#pragma once
#define Z_EN_GM_H

#include "ultra64.h"
#include "global.h"

struct EnGm;

typedef void (*EnGmUpdateFunc)(struct EnGm*, GlobalContext*);
typedef void (*EnGmActionFunc)(struct EnGm*, GlobalContext*);


struct EnGm {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s jointTable[18];
    /* 0x01FC */ Vec3s morphTable[18];
    /* 0x0268 */ EnGmUpdateFunc updateFunc;
    /* 0x026C */ EnGmActionFunc actionFunc;
    /* 0x0270 */ ColliderCylinder collider;
    /* 0x02BC */ s32 objGmBankIndex;
    /* 0x02C0 */ s16 timer;
    /* 0x02C4 */ s16 blinkTimer;
    /* 0x02C8 */ u8 eyeTexIndex;
    /* 0x02CC */ Vec3f talkPos;
}; 



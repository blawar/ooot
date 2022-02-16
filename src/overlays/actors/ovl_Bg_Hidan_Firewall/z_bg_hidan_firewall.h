#pragma once
#define Z_BG_HIDAN_FIREWALL_H

#include "ultra64.h"
#include "global.h"

struct BgHidanFirewall;

typedef void (*BgHidanFirewallActionFunc)(struct BgHidanFirewall*, GlobalContext*);


struct BgHidanFirewall {

    /* 0x0000 */ Actor actor;
    /* 0x014C */ BgHidanFirewallActionFunc actionFunc;
    /* 0x0150 */ s16 unk_150;
    /* 0x0154 */ ColliderCylinder collider;
}; 



#define INTERNAL_SRC_CODE_Z_VIMODE_C
#include "global.h"
#include "ultra64/vi.h"
#include "regs.h"
#include "def/z_vimode.h"

extern u32 osTvType;

void ViMode_LogPrint(OSViMode* osViMode) {
}

// This function configures the custom VI mode (`viMode.customViMode`) based on the other flags in `viMode`.
void ViMode_Configure(ViMode* viMode, s32 mode, s32 type, s32 unk_70, s32 unk_74, s32 unk_78, s32 unk_7C, s32 width,
                      s32 height, s32 unk_left, s32 unk_right, s32 unk_top, s32 unk_bottom) {
    s32 not_70;
    s32 not_74;
    s32 not_78;
    s32 not_7C;
    s32 cond_4C;
    s32 cond_48;
    s32 cond_44;
    s32 cond_40;
    s32 cond_3C;
    s32 cond_38;
    s32 cond_34;
    s32 yScaleLo;
    s32 yScaleHi0;
    s32 yScaleHi1;

    not_70 = !unk_70;
    not_74 = !unk_74;
    not_78 = !unk_78;
    not_7C = !unk_7C;

    cond_4C = not_70 && not_78;
    cond_48 = not_70 && unk_78;
    cond_44 = unk_70 && unk_78;
    cond_40 = unk_70 && not_78;
    cond_3C = unk_70 && not_74 && unk_78 && unk_7C;
    cond_38 = unk_70 && unk_74 && unk_78 && not_7C;
    cond_34 = not_70 && unk_74 && unk_78 && not_7C;

    unk_top &= ~1;
    unk_bottom &= ~1;

    yScaleLo = (cond_4C ? 2 : 1) * (((height << 11)) / (SCREEN_HEIGHT * 2 + unk_bottom - unk_top) / (unk_70 ? 1 : 2));

    yScaleHi0 = not_78 ? (cond_40 ? 0x1000000 : 0x2000000) : 0;
    yScaleHi1 = not_78 ? (cond_40 ? 0x3000000 : 0x2000000) : 0;

    viMode->customViMode.type = mode;
    viMode->customViMode.comRegs.ctrl = OS_VI_UNK2000 | OS_VI_UNK1000 | OS_VI_GAMMA | OS_VI_GAMMA_DITHER |
                                        (!cond_44 ? OS_VI_UNK40 : 0) | (not_74 ? OS_VI_DIVOT : 0) |
                                        (not_7C ? OS_VI_UNK2 | OS_VI_UNK1 : OS_VI_UNK2);

    if (cond_3C) {
        viMode->customViMode.comRegs.ctrl |= 0x100;
    } else if (cond_38 | cond_34) {
        viMode->customViMode.comRegs.ctrl |= 0x300;
    } else if (unk_74) {
        viMode->customViMode.comRegs.ctrl |= 0x200;
    } else {
        viMode->customViMode.comRegs.ctrl |= 0;
    }

    viMode->customViMode.comRegs.width = width * (cond_48 ? 2 : 1);

    if (type == 1) {
        viMode->customViMode.comRegs.burst = 0x3E52239;
        viMode->customViMode.comRegs.vSync = 0x20C;
        viMode->customViMode.comRegs.hSync = 0xC15;
        viMode->customViMode.comRegs.leap = 0xC150C15;
        viMode->customViMode.comRegs.hStart = 0x6C02EC;
        viMode->customViMode.fldRegs[0].vStart = 0x2501FF;
        viMode->customViMode.fldRegs[0].vBurst = 0xE0204;
    } else if (type == 0) {
        viMode->customViMode.comRegs.burst = 0x404233A;
        viMode->customViMode.comRegs.vSync = 0x270;
        viMode->customViMode.comRegs.hSync = 0x150C69;
        viMode->customViMode.comRegs.leap = 0xC6F0C6E;
        viMode->customViMode.comRegs.hStart = 0x800300;
        viMode->customViMode.fldRegs[0].vStart = 0x5F0239;
        viMode->customViMode.fldRegs[0].vBurst = 0x9026B;
    } else if (type == 2) {
        viMode->customViMode.comRegs.burst = 0x4651E39;
        viMode->customViMode.comRegs.vSync = 0x20C;
        viMode->customViMode.comRegs.hSync = 0xC10;
        viMode->customViMode.comRegs.leap = 0xC1C0C1C;
        viMode->customViMode.comRegs.hStart = 0x6C02EC;
        viMode->customViMode.fldRegs[0].vStart = 0x2501FF;
        viMode->customViMode.fldRegs[0].vBurst = 0xE0204;
    }

    viMode->customViMode.fldRegs[1].vStart = viMode->customViMode.fldRegs[0].vStart;

    viMode->customViMode.comRegs.hStart += (unk_left << 16) + (s16)unk_right;
    viMode->customViMode.fldRegs[0].vStart += (unk_top << 16) + (s16)unk_bottom;
    viMode->customViMode.fldRegs[1].vStart += (unk_top << 16) + (s16)unk_bottom;

    viMode->customViMode.fldRegs[1].vBurst = viMode->customViMode.fldRegs[0].vBurst;

    if (cond_44) {
        viMode->customViMode.comRegs.vSync++;
        if (type == 2) {
            viMode->customViMode.comRegs.hSync += 0x40001;
        }
        if (type == 2) {
            viMode->customViMode.comRegs.leap += 0xFFFCFFFE;
        }
    } else {
        viMode->customViMode.fldRegs[0].vStart += 0xFFFDFFFE;
        if (type == 2) {
            viMode->customViMode.fldRegs[0].vBurst += 0xFFFCFFFE;
        }
        if (type == 0) {
            viMode->customViMode.fldRegs[1].vBurst += 0x2FFFE;
        }
    }

    viMode->customViMode.comRegs.xScale = (width << 10) / (SCREEN_WIDTH * 2 + unk_right - unk_left);
    viMode->customViMode.comRegs.vCurrent = 0;

    viMode->customViMode.fldRegs[0].origin = width * 2 * (unk_7C ? 1 : 2);
    viMode->customViMode.fldRegs[1].origin = width * 2 * (unk_7C ? 1 : 2) * (unk_70 ? 1 : 2);

    viMode->customViMode.fldRegs[0].yScale = yScaleLo | yScaleHi0;
    viMode->customViMode.fldRegs[1].yScale = yScaleLo | yScaleHi1;

    viMode->customViMode.fldRegs[0].vIntr = 2;
    viMode->customViMode.fldRegs[1].vIntr = 2;
}

void ViMode_Save(ViMode* viMode) {
}

void ViMode_Load(ViMode* viMode) {
}

void ViMode_Init(ViMode* viMode) {
}

void ViMode_Destroy(ViMode* viMode) {
}

void ViMode_ConfigureFeatures(ViMode* viMode, s32 viFeatures) {
    u32 ctrl = viMode->customViMode.comRegs.ctrl;

    if (viFeatures & OS_VI_GAMMA_ON) {
        ctrl |= OS_VI_GAMMA;
    }
    if (viFeatures & OS_VI_GAMMA_OFF) {
        ctrl &= ~OS_VI_GAMMA;
    }
    if (viFeatures & OS_VI_GAMMA_DITHER_ON) {
        ctrl |= OS_VI_GAMMA_DITHER;
    }
    if (viFeatures & OS_VI_GAMMA_DITHER_OFF) {
        ctrl &= ~OS_VI_GAMMA_DITHER;
    }
    if (viFeatures & OS_VI_DIVOT_ON) {
        ctrl |= OS_VI_DIVOT;
    }
    if (viFeatures & OS_VI_DIVOT_OFF) {
        ctrl &= ~OS_VI_DIVOT;
    }
    viMode->customViMode.comRegs.ctrl = ctrl;
}


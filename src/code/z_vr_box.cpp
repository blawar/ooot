#define INTERNAL_SRC_CODE_Z_VR_BOX_C
#include "global.h"
#include "z64render.h"
#include "vt.h"
#include "gfx.h"
#include "z64global.h"
#include "z64save.h"
#include "z64environment.h"
#include "segment_symbols.h"
#include "misc/z_vr_box_assets.h"
#include "z_kankyo.h"
#include "def/game.h"
#include "def/z_common_data.h"
#include "def/z_kankyo.h"
#include "def/z_std_dma.h"
#include "def/z_vr_box.h"

u32 D_8012AC90[4] = {
    0x00000000,
    0x00010000,
    0x00020000,
    0x00030000,
};

u16 D_8012ACA0[2][0x20] = {
    { 0x00, 0x02, 0x0A, 0x0C, 0x02, 0x04, 0x0C, 0x0E, 0x0A, 0x0C, 0x14, 0x16, 0x0C, 0x0E, 0x16, 0x18,
      0x01, 0x03, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0D, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x15, 0x17 },
    { 0x14, 0x16, 0x1E, 0x20, 0x16, 0x18, 0x20, 0x22, 0x1E, 0x20, 0x28, 0x2A, 0x20, 0x22, 0x2A, 0x2C,
      0x15, 0x17, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x21, 0x23, 0x24, 0x25, 0x26, 0x27, 0x29, 0x2B },
};

s16 D_8012AD20[5] = {
    0x0000, 0x0FC0, 0x1F80, 0x2F40, 0x3F00,
};

s16 D_8012AD2C[9] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00, 0x26C0, 0x2E80, 0x3640, 0x3E00,
};

s16 D_8012AD40[0x40] = {
    0x00, 0x10, 0x13, 0x12, 0x10, 0x01, 0x14, 0x13, 0x01, 0x11, 0x15, 0x14, 0x11, 0x05, 0x16, 0x15,
    0x12, 0x13, 0x17, 0x02, 0x13, 0x14, 0x03, 0x17, 0x14, 0x15, 0x18, 0x03, 0x15, 0x16, 0x07, 0x18,
    0x02, 0x17, 0x1A, 0x19, 0x17, 0x03, 0x1B, 0x1A, 0x03, 0x18, 0x1C, 0x1B, 0x18, 0x07, 0x1D, 0x1C,
    0x19, 0x1A, 0x1E, 0x0A, 0x1A, 0x1B, 0x0B, 0x1E, 0x1B, 0x1C, 0x1F, 0x0B, 0x1C, 0x1D, 0x0F, 0x1F,
};

static u32 gTextOffsetLUT[6] = {
    0x00000000, 0x00002000, 0x00004000, 0x00006000, 0x00008000, 0x0000C000,
};

u16 D_8012ADD8[0x20] = {
    0x00, 0x02, 0x0A, 0x0C, 0x02, 0x04, 0x0C, 0x0E, 0x0A, 0x0C, 0x14, 0x16, 0x0C, 0x0E, 0x16, 0x18,
    0x01, 0x03, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0D, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x15, 0x17,
};

s16 D_8012AE18[5] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00,
};

s16 D_8012AE24[5] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00,
};

s16 D_8012AE30[5] = {
    0x0000, 0x07C0, 0x0F80, 0x07C0, 0x0000,
};

s16 D_8012AE3C[0x40] = {
    0x00, 0x10, 0x13, 0x12, 0x10, 0x01, 0x14, 0x13, 0x01, 0x11, 0x15, 0x14, 0x11, 0x05, 0x16, 0x15,
    0x12, 0x13, 0x17, 0x02, 0x13, 0x14, 0x03, 0x17, 0x14, 0x15, 0x18, 0x03, 0x15, 0x16, 0x07, 0x18,
    0x02, 0x17, 0x1A, 0x19, 0x17, 0x03, 0x1B, 0x1A, 0x03, 0x18, 0x1C, 0x1B, 0x18, 0x07, 0x1D, 0x1C,
    0x19, 0x1A, 0x1E, 0x0A, 0x1A, 0x1B, 0x0B, 0x1E, 0x1B, 0x1C, 0x1F, 0x0B, 0x1C, 0x1D, 0x0F, 0x1F,
};

typedef struct {
    /* 0x000 */ s32 unk_0;
    /* 0x004 */ s32 unk_4;
    /* 0x008 */ s32 unk_8;
    /* 0x00C */ s32 unk_C;
    /* 0x010 */ s32 unk_10;
} Struct_8012AF0C; // size = 0x14

Struct_8012AF0C D_8012AEBC[4] = {
    { -0x7E, 0x7C, -0x7E, 0x3F, -0x1F },
    { 0x7E, 0x7C, -0x7E, 0x3F, -0x1F },
    { 0x7E, 0x7C, 0x7E, -0x3F, -0x1F },
    { -0x7E, 0x7C, 0x7E, -0x3F, -0x1F },
};

Struct_8012AF0C D_8012AF0C[6] = {
    { -0x40, 0x40, -0x40, 0x20, -0x20 }, { 0x40, 0x40, 0x40, -0x20, -0x20 }, { -0x40, 0x40, 0x40, -0x20, -0x20 },
    { 0x40, 0x40, -0x40, 0x20, -0x20 },  { -0x40, 0x40, 0x40, 0x20, -0x20 }, { -0x40, -0x40, -0x40, 0x20, 0x20 },
};

s32 func_800ADBB0(SkyboxContext* skyboxCtx, Vtx* roomVtx, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                  s32 arg8, s32 arg9) {
    u32 pad42C;
    s32 pad428;
    s32 sp424;
    s32 i;
    s32 j;
    s32 k;
    u16 index;
    s16 phi_t1;
    s16 phi_a2_4;
    s16 phi_a0_4;
    s16 phi_t2_4;
    s16 phi_ra;
    s32 sp358[9 * 5];
    s32 sp2A4[9 * 5];
    s32 sp1F0[9 * 5];
    s32 sp13C[9 * 5];
    s32 sp88[9 * 5];
    s32 pad;

    switch (arg8) {
        case 0:
        case 2:
            pad428 = arg4;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp1F0[k] = arg5;
                    sp358[k] = pad42C;
                    sp2A4[k] = pad428;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;

        case 1:
        case 3:
            pad428 = arg4;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg5;
                for (j = 0; j < 5; j++, k++) {
                    sp358[k] = arg3;
                    sp2A4[k] = pad428;
                    sp1F0[k] = pad42C;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;

        case 4:
        case 5:
            pad428 = arg5;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp2A4[k] = arg4;
                    sp358[k] = pad42C;
                    sp1F0[k] = pad428;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;
    }

    for (phi_a2_4 = 0, sp424 = 0; sp424 < 2; sp424++) {
        skyboxCtx->unk_138 = skyboxCtx->dListBuf[arg9 + sp424];

        for (i = 0; i < 0x20; i++) {
            index = D_8012ACA0[sp424][i];

            roomVtx[arg2 + i].v.ob[0] = sp358[index];
            roomVtx[arg2 + i].v.ob[1] = sp2A4[index];
            roomVtx[arg2 + i].v.ob[2] = sp1F0[index];
            roomVtx[arg2 + i].v.flag = 0;
            roomVtx[arg2 + i].v.tc[0] = sp13C[index];
            roomVtx[arg2 + i].v.tc[1] = sp88[index];
            roomVtx[arg2 + i].v.cn[1] = 0;
            roomVtx[arg2 + i].v.cn[2] = 0;
            roomVtx[arg2 + i].v.cn[0] = 255;
        }
        gSPVertex(skyboxCtx->unk_138++, &roomVtx[arg2], 32, 0);
        arg2 += i;
        gSPCullDisplayList(skyboxCtx->unk_138++, 0, 15);

        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 4; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x3F, phi_t2_4 += 4) {
                gDPLoadTextureTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[0], D_8012AC90[arg8]),
                                   G_IM_FMT_CI, G_IM_SIZ_8b, 256, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x3F,
                                   phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AD40[phi_t2_4 + 1], D_8012AD40[phi_t2_4 + 2],
                               D_8012AD40[phi_t2_4 + 3], D_8012AD40[phi_t2_4 + 0], 3);
            }
        }
        gSPEndDisplayList(skyboxCtx->unk_138++);
    }
    return arg2;
}

s32 func_800AE2C0(SkyboxContext* skyboxCtx, Vtx* roomVtx, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                  s32 lut_index) {
    s32 i;
    s32 j;
    s32 k;
    s16 phi_a0_4;
    s16 phi_t1;
    s32 temp1;
    u16 index;
    s16 phi_a2_4;
    s16 phi_ra;
    s16 phi_t2_4;
    s32 temp2;
    s32 sp2B4[5 * 5];
    s32 sp250[5 * 5];
    s32 sp1EC[5 * 5];
    s32 sp188[5 * 5];
    s32 sp124[5 * 5];
    s32 pad;

    switch (lut_index) {
        case 0:
        case 1:
            temp1 = arg4;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp1EC[k] = arg5;
                    sp2B4[k] = temp2;
                    sp250[k] = temp1;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE30[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;

        case 2:
        case 3:
            temp1 = arg4;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg5;
                for (j = 0; j < 5; j++, k++) {
                    sp2B4[k] = arg3;
                    sp250[k] = temp1;
                    sp1EC[k] = temp2;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE30[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;

        case 4:
        case 5:
            temp1 = arg5;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp250[k] = arg4;
                    sp2B4[k] = temp2;
                    sp1EC[k] = temp1;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE24[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;
    }
    skyboxCtx->unk_138 = (Gfx*)&skyboxCtx->dListBuf[2 * lut_index];

    for (i = 0; i < 0x20; i++) {
        index = D_8012ADD8[i];

        roomVtx[arg2 + i].v.ob[0] = sp2B4[index];
        roomVtx[arg2 + i].v.ob[1] = sp250[index];
        roomVtx[arg2 + i].v.ob[2] = sp1EC[index];
        roomVtx[arg2 + i].v.flag = 0;
        roomVtx[arg2 + i].v.tc[0] = sp188[index];
        roomVtx[arg2 + i].v.tc[1] = sp124[index];
        roomVtx[arg2 + i].v.cn[1] = 0;
        roomVtx[arg2 + i].v.cn[2] = 0;
        roomVtx[arg2 + i].v.cn[0] = 255;
    }
    gSPVertex(skyboxCtx->unk_138++, &roomVtx[arg2], 32, 0);
    arg2 += i;
    gSPCullDisplayList(skyboxCtx->unk_138++, 0, 15);

    if ((lut_index == 4) || (lut_index == 5)) {
        phi_a2_4 = 0;
        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 4; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[0], gTextOffsetLUT[lut_index]), 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[1], gTextOffsetLUT[lut_index]), 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
    } else {
        phi_a2_4 = 0;
        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 2; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[0], gTextOffsetLUT[lut_index]), 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[1], gTextOffsetLUT[lut_index]), 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
        phi_a2_4 -= 0x1F;
        for (phi_ra = 0; phi_ra < 2; phi_ra++, phi_a2_4 -= 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[0], gTextOffsetLUT[lut_index]), 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, POINTER_ADD(skyboxCtx->staticSegments[1], gTextOffsetLUT[lut_index]), 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
    }
    gSPEndDisplayList(skyboxCtx->unk_138++);
    return arg2;
}

void func_800AEFC8(SkyboxContext* skyboxCtx, s16 skyboxId) {
    s32 i;
    s32 j;
    s32 phi_s3 = 0;

    if (skyboxId == SKYBOX_BAZAAR || (skyboxId > SKYBOX_HOUSE_KAKARIKO && skyboxId <= SKYBOX_BOMBCHU_SHOP)) {
        for (j = 0, i = 0; i < 2; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    } else if (skyboxCtx->unk_140 == 2) {
        for (j = 0, i = 0; i < 3; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    } else {
        for (j = 0, i = 0; i < 4; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    }
}

void func_800AF178(SkyboxContext* skyboxCtx, s32 arg1) {
    s32 phi_s2 = 0;
    s32 i;

    for (i = 0; i < arg1; i++) {
        phi_s2 = func_800AE2C0(skyboxCtx, skyboxCtx->roomVtx, phi_s2, D_8012AF0C[i].unk_0, D_8012AF0C[i].unk_4,
                               D_8012AF0C[i].unk_8, D_8012AF0C[i].unk_C, D_8012AF0C[i].unk_10, i);
    }
}

void Skybox_Setup(GlobalContext* globalCtx, SkyboxContext* skyboxCtx, s16 skyboxId) {
    uintptr_t size;
    s16 i;
    u8 skybox1Index;
    u8 skybox2Index;
    void* start;
    s32 phi_v1;

    switch (skyboxId) {
        case SKYBOX_NORMAL_SKY:
            phi_v1 = 0;
            if (gSaveContext.unk_13C3 != 0 && gSaveContext.sceneSetupIndex < 4 && gWeatherMode > 0 &&
                gWeatherMode < 6) {
                phi_v1 = 1;
            }

            for (i = 0; i < 9; i++) {
                if (gSaveContext.skyboxTime >= D_8011FC1C[phi_v1][i].startTime &&
                    (gSaveContext.skyboxTime < D_8011FC1C[phi_v1][i].endTime ||
                     D_8011FC1C[phi_v1][i].endTime == 0xFFFF)) {
                    globalCtx->envCtx.skybox1Index = skybox1Index = D_8011FC1C[phi_v1][i].skybox1Index;
                    globalCtx->envCtx.skybox2Index = skybox2Index = D_8011FC1C[phi_v1][i].skybox2Index;
                    if (D_8011FC1C[phi_v1][i].blend != 0) {
                        globalCtx->envCtx.skyboxBlend =
                            Environment_LerpWeight(D_8011FC1C[phi_v1][i].endTime, D_8011FC1C[phi_v1][i].startTime,
                                                   ((void)0, gSaveContext.skyboxTime)) *
                            255.0f;
                    } else {
                        globalCtx->envCtx.skyboxBlend = 0;
                    }
                    break;
                }
            }

            size = (gSkyboxFiles[skybox1Index].file.vromEnd - gSkyboxFiles[skybox1Index].file.vromStart).size();
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1054);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1055);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], gSkyboxFiles[skybox1Index].file.vromStart, size, "../z_vr_box.c",
                                1058);
            //skyboxCtx->staticSegments[0] = gSkyboxFiles[skybox1Index].file.vromStart;

            size = (gSkyboxFiles[skybox2Index].file.vromEnd - gSkyboxFiles[skybox2Index].file.vromStart).size();
            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1060);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c",
                   1061);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], gSkyboxFiles[skybox2Index].file.vromStart, size, "../z_vr_box.c",
                                1064);
            //skyboxCtx->staticSegments[1] = gSkyboxFiles[skybox2Index].file.vromStart;

            if ((skybox1Index & 1) ^ ((skybox1Index & 4) >> 2)) {
                size = (gSkyboxFiles[skybox1Index].palette.vromEnd - gSkyboxFiles[skybox1Index].palette.vromStart).size();

                skyboxCtx->palettes = (u16(*)[256])GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", 1072);

                ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1073);

                DmaMgr_SendRequest1(skyboxCtx->palettes, gSkyboxFiles[skybox1Index].palette.vromStart, size, "../z_vr_box.c",
                                    1075);
                DmaMgr_SendRequest1(POINTER_ADD(skyboxCtx->palettes, size), gSkyboxFiles[skybox2Index].palette.vromStart, size,
                                    "../z_vr_box.c", 1077);
            } else {
                size = (gSkyboxFiles[skybox1Index].palette.vromEnd - gSkyboxFiles[skybox1Index].palette.vromStart).size();

                skyboxCtx->palettes = (u16(*)[256])GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", 1085);

                ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1086);

                DmaMgr_SendRequest1(skyboxCtx->palettes, gSkyboxFiles[skybox2Index].palette.vromStart, size, "../z_vr_box.c",
                                    1088);
                DmaMgr_SendRequest1(POINTER_ADD(skyboxCtx->palettes, size), gSkyboxFiles[skybox1Index].palette.vromStart, size,
                                    "../z_vr_box.c", 1090);
            }
            break;

        case SKYBOX_BAZAAR:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_SP1a_static;
            size = sizeof(vr_SP1a_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1127);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1128);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1129);

            start = (void*)vr_SP1a_pal_static;
            size = sizeof(vr_SP1a_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1132);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1133);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1134);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_OVERCAST_SUNSET:
            start = (void*)vr_cloud2_static;
            size = sizeof(vr_cloud2_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1155);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1156);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1159);

            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1162);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c",
                   1163);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], start, size, "../z_vr_box.c", 1166);

            start = (void*)vr_cloud2_pal_static;
            size = sizeof(vr_cloud2_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", 1170);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1171);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1173);
            DmaMgr_SendRequest1(POINTER_ADD(skyboxCtx->palettes, size), start, size, "../z_vr_box.c", 1175);
            break;
        case SKYBOX_MARKET_ADULT:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_RUVR_static;
            size = sizeof(vr_RUVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1182);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1183);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1184);

            start = (void*)vr_RUVR_pal_static;
            size = sizeof(vr_RUVR_pal_static);
            osSyncPrintf("ＳＩＺＥ = %d\n", size);

            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1188);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1189);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1190);
            break;
        case SKYBOX_CUTSCENE_MAP:
            start = (void*)vr_holy0_static;
            size = sizeof(vr_holy0_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1196);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1197);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1200);

            start = (void*)vr_holy1_static;
            size = sizeof(vr_holy1_static);
            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1203);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c",
                   1204);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], start, size, "../z_vr_box.c", 1207);

            start = (void*)vr_holy0_pal_static;
            size = sizeof(vr_holy0_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", 1211);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1212);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1214);
            DmaMgr_SendRequest1(POINTER_ADD(skyboxCtx->palettes, size), (u8*)vr_holy1_pal_static, size,
                                "../z_vr_box.c", 1216);
            break;
        case SKYBOX_HOUSE_LINK:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_LHVR_static;
            size = sizeof(vr_LHVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1226);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1227);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1228);

            start = (void*)vr_LHVR_pal_static;
            size = sizeof(vr_LHVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1231);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1232);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1233);
            break;
        case SKYBOX_MARKET_CHILD_DAY:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_MDVR_static;
            size = sizeof(vr_MDVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1257);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1258);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1259);

            start = (void*)vr_MDVR_pal_static;
            size = sizeof(vr_MDVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1262);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1263);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1264);
            break;
        case SKYBOX_MARKET_CHILD_NIGHT:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_MNVR_static;
            size = sizeof(vr_MNVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1271);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1272);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1273);

            start = (void*)vr_MNVR_pal_static;
            size = sizeof(vr_MNVR_pal_static);
            osSyncPrintf("ＳＩＺＥ = %d\n", size);

            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1277);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1278);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1279);
            break;
        case SKYBOX_HAPPY_MASK_SHOP:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_FCVR_static;
            size = sizeof(vr_FCVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1286);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1287);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1288);

            start = (void*)vr_FCVR_pal_static;
            size = sizeof(vr_FCVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1291);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1292);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1293);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_HOUSE_KNOW_IT_ALL_BROTHERS:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_KHVR_static;
            size = sizeof(vr_KHVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1301);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1302);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1303);

            start = (void*)vr_KHVR_pal_static;
            size = sizeof(vr_KHVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1306);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1307);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1308);
            break;
        case SKYBOX_HOUSE_OF_TWINS:
            skyboxCtx->unk_140 = 2;

            start = (void*)vr_K3VR_static;
            size = sizeof(vr_K3VR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1331);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1332);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1333);

            start = (void*)vr_K3VR_pal_static;
            size = sizeof(vr_K3VR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1336);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1337);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1338);
            break;
        case SKYBOX_STABLES:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_MLVR_static;
            size = sizeof(vr_MLVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1345);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1346);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1347);

            start = (void*)vr_MLVR_pal_static;
            size = sizeof(vr_MLVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1350);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1351);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1352);
            break;
        case SKYBOX_HOUSE_KAKARIKO:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_KKRVR_static;
            size = sizeof(vr_KKRVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1359);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1360);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1361);

            start = (void*)vr_KKRVR_pal_static;
            size = sizeof(vr_KKRVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1364);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1365);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1366);
            break;
        case SKYBOX_KOKIRI_SHOP:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_KSVR_static;
            size = sizeof(vr_KSVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1373);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1374);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1375);

            start = (void*)vr_KSVR_pal_static;
            size = sizeof(vr_KSVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1378);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1379);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1380);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_GORON_SHOP:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_GLVR_static;
            size = sizeof(vr_GLVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1405);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1406);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1407);

            start = (void*)vr_GLVR_pal_static;
            size = sizeof(vr_GLVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1410);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1411);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1412);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_ZORA_SHOP:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_ZRVR_static;
            size = sizeof(vr_ZRVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1420);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1421);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1422);

            start = (void*)vr_ZRVR_pal_static;
            size = sizeof(vr_ZRVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1425);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1426);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1427);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_POTION_SHOP_KAKARIKO:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_DGVR_static;
            size = sizeof(vr_DGVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1451);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1452);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1453);

            start = (void*)vr_DGVR_pal_static;
            size = sizeof(vr_DGVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1456);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1457);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1458);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_POTION_SHOP_MARKET:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_ALVR_static;
            size = sizeof(vr_ALVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1466);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1467);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1468);

            start = (void*)vr_ALVR_pal_static;
            size = sizeof(vr_ALVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1471);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1472);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1473);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_BOMBCHU_SHOP:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_NSVR_static;
            size = sizeof(vr_NSVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1481);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1482);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1483);

            start = (void*)vr_NSVR_pal_static;
            size = sizeof(vr_NSVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1486);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1487);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1488);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_HOUSE_RICHARD:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_IPVR_static;
            size = sizeof(vr_IPVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1512);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1513);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1514);

            start = (void*)vr_IPVR_pal_static;
            size = sizeof(vr_IPVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1517);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1518);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1519);
            break;
        case SKYBOX_HOUSE_IMPA:
            skyboxCtx->unk_140 = 1;

            start = (void*)vr_LBVR_static;
            size = sizeof(vr_LBVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1526);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1527);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1528);

            start = (void*)vr_LBVR_pal_static;
            size = sizeof(vr_LBVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1531);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1532);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1533);
            break;
        case SKYBOX_TENT:
            skyboxCtx->unk_140 = 2;

            start = (void*)vr_TTVR_static;
            size = sizeof(vr_TTVR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1540);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1541);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1542);

            start = (void*)vr_TTVR_pal_static;
            size = sizeof(vr_TTVR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1545);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1546);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1547);
            break;
        case SKYBOX_HOUSE_MIDO:
            skyboxCtx->unk_140 = 2;

            start = (void*)vr_K4VR_static;
            size = sizeof(vr_K4VR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1560);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1561);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1562);

            start = (void*)vr_K4VR_pal_static;
            size = sizeof(vr_K4VR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1565);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1566);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1567);
            break;
        case SKYBOX_HOUSE_SARIA:
            skyboxCtx->unk_140 = 2;

            start = (void*)vr_K5VR_static;
            size = sizeof(vr_K5VR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1574);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1575);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1576);

            start = (void*)vr_K5VR_pal_static;
            size = sizeof(vr_K5VR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1579);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1580);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1581);
            break;
        case SKYBOX_HOUSE_ALLEY:
            skyboxCtx->unk_140 = 2;

            start = (void*)vr_KR3VR_static;
            size = sizeof(vr_KR3VR_static);
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1588);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c",
                   1589);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", 1590);

            start = (void*)vr_KR3VR_pal_static;
            size = sizeof(vr_KR3VR_pal_static);
            skyboxCtx->palettes = (u16 (*)[256])GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", 1593);
            ASSERT(skyboxCtx->palettes != NULL, "vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 1594);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1595);
            break;
        case SKYBOX_UNSET_27:
            break;
    }
}

void Skybox_Init(GameState* state, SkyboxContext* skyboxCtx, s16 skyboxId) {
    GlobalContext* globalCtx = (GlobalContext*)state;

    skyboxCtx->unk_140 = 0;
    skyboxCtx->rot.x = skyboxCtx->rot.y = skyboxCtx->rot.z = 0.0f;

    Skybox_Setup(globalCtx, skyboxCtx, skyboxId);
    osSyncPrintf("\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\n"
                 "ＴＹＰＥ＝%d"
                 "\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\n",
                 skyboxId);

    if (skyboxId != SKYBOX_NONE) {
        osSyncPrintf(VT_FGCOL(GREEN));

        if (skyboxCtx->unk_140 != 0) {
            skyboxCtx->dListBuf = (Gfx (*)[150])GameState_Alloc(state, 8 * 150 * sizeof(Gfx), "../z_vr_box.c", 1636);
            ASSERT(skyboxCtx->dListBuf != NULL, "vr_box->dpList != NULL", "../z_vr_box.c", 1637);

            skyboxCtx->roomVtx = (Vtx*)GameState_Alloc(state, 256 * sizeof(Vtx), "../z_vr_box.c", 1639);
            ASSERT(skyboxCtx->roomVtx != NULL, "vr_box->roomVtx != NULL", "../z_vr_box.c", 1640);

            func_800AEFC8(skyboxCtx, skyboxId);
        } else {
            skyboxCtx->dListBuf = (Gfx (*)[150])GameState_Alloc(state, 12 * 150 * sizeof(Gfx), "../z_vr_box.c", 1643);
            ASSERT(skyboxCtx->dListBuf != NULL, "vr_box->dpList != NULL", "../z_vr_box.c", 1644);

            if (skyboxId == SKYBOX_CUTSCENE_MAP) {
                skyboxCtx->roomVtx = (Vtx*)GameState_Alloc(state, 192 * sizeof(Vtx), "../z_vr_box.c", 1648);
                ASSERT(skyboxCtx->roomVtx != NULL, "vr_box->roomVtx != NULL", "../z_vr_box.c", 1649);

                func_800AF178(skyboxCtx, 6);
            } else {
                skyboxCtx->roomVtx = (Vtx*)GameState_Alloc(state, 160 * sizeof(Vtx), "../z_vr_box.c", 1653);
                ASSERT(skyboxCtx->roomVtx != NULL, "vr_box->roomVtx != NULL", "../z_vr_box.c", 1654);

                func_800AF178(skyboxCtx, 5);
            }
        }
        osSyncPrintf(VT_RST);
    }
}

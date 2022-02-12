#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_KAKERA_Z_EFF_SS_KAKERA_C
#include "actor_common.h"
/*
 * File: z_eff_ss_kakera.c
 * Overlay: ovl_Effect_Ss_Kakera
 * Description: Fragments. Appearance is determined by the supplied display list.
 */

#include "z_eff_ss_kakera.h"
#include "def/code_800FD970.h"
#include "def/logutils.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"

#define rReg0 regs[0]
#define rGravity regs[1]
#define rPitch regs[2]
#define rYaw regs[3]
#define rReg4 regs[4]
#define rReg5 regs[5]
#define rReg6 regs[6]
#define rScale regs[7]
#define rReg8 regs[8]
#define rReg9 regs[9]
#define rObjId regs[10]
#define rObjBankIdx regs[11]
#define rColorIdx regs[12]

u32 EffectSsKakera_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsKakera_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis);
void EffectSsKakera_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

void func_809A9BA8(EffectSs* pthis, GlobalContext* globalCtx);

EffectSsInit Effect_Ss_Kakera_InitVars = {
    EFFECT_SS_KAKERA,
    EffectSsKakera_Init,
};

u32 EffectSsKakera_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsKakeraInitParams* initParams = (EffectSsKakeraInitParams*)initParamsx;
    s32 objId;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->life = initParams->life;
    pthis->priority = 101;

    if (initParams->dList != NULL) {
        pthis->gfx = initParams->dList;
        objId = initParams->objId;

        if (objId == OBJECT_GAMEPLAY_KEEP || objId == OBJECT_GAMEPLAY_FIELD_KEEP ||
            objId == OBJECT_GAMEPLAY_DANGEON_KEEP) {
            pthis->rObjId = KAKERA_OBJECT_DEFAULT;
        } else {
            pthis->rObjId = initParams->objId;
            func_809A9BA8(pthis, globalCtx);
        }

    } else {
        osSyncPrintf("shape_modelがNULL\n");
        LogUtils_HungupThread("../z_eff_kakera.c", 178);
    }

    pthis->draw = EffectSsKakera_Draw;
    pthis->update = EffectSsKakera_Update;
    pthis->vec = initParams->unk_18;
    pthis->rReg0 = initParams->unk_2C;
    pthis->rGravity = initParams->gravity;
    pthis->rPitch = Rand_ZeroOne() * 32767.0f;
    pthis->rYaw = Rand_ZeroOne() * 32767.0f;
    pthis->rReg4 = initParams->unk_26;
    pthis->rReg5 = initParams->unk_28;
    pthis->rReg6 = initParams->unk_2A;
    pthis->rScale = initParams->scale;
    pthis->rReg8 = initParams->unk_30;
    pthis->rReg9 = initParams->unk_32;
    pthis->rColorIdx = initParams->colorIdx;

    return 1;
}

f32 func_809A9818(f32 arg0, f32 arg1) {
    f32 temp_f2;

    if (arg1 < 0.0f) {
        osSyncPrintf("範囲がマイナス！！(randomD_sectionUniformity)\n");
    }

    temp_f2 = Rand_ZeroOne() * arg1;
    return ((temp_f2 * 2.0f) - arg1) + arg0;
}

void EffectSsKakera_Draw(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    static Color_RGB8 colors[] = { { 255, 255, 255 }, { 235, 170, 130 } };
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad;
    f32 scale;
    s32 colorIdx;

    scale = pthis->rScale / 256.0f;
    colorIdx = pthis->rColorIdx;

    OPEN_DISPS(gfxCtx, "../z_eff_kakera.c", 241);

    if (pthis->rObjId != KAKERA_OBJECT_DEFAULT) {
        if ((((pthis->rReg4 >> 7) & 1) << 7) == 0x80) {
            gSPSegment(POLY_XLU_DISP++, 0x06, gObjectTable[pthis->rObjBankIdx].vromStart.get());
        } else {
            gSPSegment(POLY_OPA_DISP++, 0x06, gObjectTable[pthis->rObjBankIdx].vromStart.get());
        }
    }

    Matrix_Translate(pthis->pos.x, pthis->pos.y, pthis->pos.z, MTXMODE_NEW);
    Matrix_RotateY(pthis->rYaw * 0.01f, MTXMODE_APPLY);
    Matrix_RotateX(pthis->rPitch * 0.01f, MTXMODE_APPLY);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

    if ((((pthis->rReg4 >> 7) & 1) << 7) == 0x80) {
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_kakera.c", 268),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80093D84(globalCtx->state.gfxCtx);

        if (colorIdx >= 0) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, colors[colorIdx].r, colors[colorIdx].g, colors[colorIdx].b, 255);
        }

        gSPDisplayList(POLY_XLU_DISP++, pthis->gfx);
    } else {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_eff_kakera.c", 286),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_80093D18(globalCtx->state.gfxCtx);

        if (colorIdx >= 0) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, colors[colorIdx].r, colors[colorIdx].g, colors[colorIdx].b, 255);
        }

        gSPDisplayList(POLY_OPA_DISP++, pthis->gfx);
    }

    CLOSE_DISPS(gfxCtx, "../z_eff_kakera.c", 302);
}

void func_809A9BA8(EffectSs* pthis, GlobalContext* globalCtx) {
    pthis->rObjBankIdx = Object_GetIndex(&globalCtx->objectCtx, pthis->rObjId);

    if ((pthis->rObjBankIdx < 0) || !Object_IsLoaded(&globalCtx->objectCtx, pthis->rObjBankIdx)) {
        pthis->life = 0;
        pthis->draw = NULL;
    }
}

void func_809A9C10(EffectSs* pthis) {
    f32 temp_f14;
    f32 temp_f12;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f0;

    temp_f18 = pthis->rReg5 / 1024.0f;
    temp_f20 = pthis->rReg6 / 1024.0f;
    temp_f14 = (pthis->rReg9 / 1024.0f) * 4.0f;

    temp_f2 = pthis->velocity.x - func_809A9818(0.0f, temp_f14);
    temp_f16 = pthis->velocity.y - func_809A9818(0.0f, temp_f14);
    temp_f12 = pthis->velocity.z - func_809A9818(0.0f, temp_f14);

    if (temp_f2 > 0.0f) {
        pthis->velocity.x -= ((temp_f2 * temp_f18) + (SQ(temp_f2) * temp_f20));
    } else {
        pthis->velocity.x -= ((temp_f2 * temp_f18) - (SQ(temp_f2) * temp_f20));
    }

    if (temp_f16 > 0.0f) {
        temp_f0 = temp_f16 * temp_f18;
        temp_f2 = SQ(temp_f16) * temp_f20;
        pthis->velocity.y -= (temp_f0 + temp_f2);
    } else {
        temp_f0 = temp_f16 * temp_f18;
        temp_f2 = SQ(temp_f16) * temp_f20;
        pthis->velocity.y -= (temp_f0 - temp_f2);
    }

    if (temp_f12 > 0.0f) {
        pthis->velocity.z -= (temp_f0 + temp_f2);
    } else {
        pthis->velocity.z -= (temp_f0 - temp_f2);
    }
}

void func_809A9DC0(EffectSs* pthis) {
    pthis->accel.x = pthis->accel.y = pthis->accel.z = 0.0f;
}

f32 func_809A9DD8(f32 arg0, s32 arg1) {
    return 1.0f;
}

static f32 D_809AA530[] = {
    1.0f, 100.0f, 40.0f, 5.0f, 100.0f, 40.0f, 5.0f, 100.0f, 40.0f, 5.0f,
};

f32 func_809A9DEC(f32 arg0, s32 arg1) {
    if (D_809AA530[arg1] < arg0) {
        return D_809AA530[arg1] / arg0;
    } else {
        return 1.0f;
    }
}

f32 func_809A9E28(f32 arg0, s32 arg1) {
    f32 temp = SQ(arg0);

    if (D_809AA530[arg1] < temp) {
        return D_809AA530[arg1] / temp;
    } else {
        return 1.0f;
    }
}

f32 func_809A9E68(f32 arg0, s32 arg1) {
    return func_809A9E28(arg0, arg1);
}

s32 func_809A9E88(EffectSs* pthis, Vec3f* diff, f32 dist) {
    static f32 D_809AA558[] = { 0.05f, 1.0f };
    s32 temp_v0;
    f32 phi_f0;

    temp_v0 = pthis->rReg0 & 3;

    if (temp_v0 != 0) {

        if (dist > 1.0f) {
            phi_f0 = 1.0f / dist;
        } else {
            phi_f0 = 1.0f;
        }

        pthis->accel.x += ((D_809AA558[temp_v0 - 1] * diff->z) * phi_f0);
        pthis->accel.z -= ((D_809AA558[temp_v0 - 1] * diff->x) * phi_f0);
    }

    return 1;
}

s32 func_809A9F10(EffectSs* pthis, Vec3f* diff, f32 dist) {
    static f32 D_809AA560[] = { 4.0f, 0.1f, 0.3f, 0.9f, -0.1f, -0.3f, -0.9f };
    s32 temp_v0;

    temp_v0 = (pthis->rReg0 >> 2) & 7;

    if (temp_v0 != 0) {
        pthis->accel.y += D_809AA560[temp_v0];
    }

    return 1;
}

s32 func_809A9F4C(EffectSs* pthis, Vec3f* diff, f32 dist) {
    static f32 D_809AA57C[] = { 0.1f, 1.0f, 6.0f };
    s32 temp_v0;
    f32 phi_f0;

    temp_v0 = (pthis->rReg0 >> 5) & 3;

    if (temp_v0 != 0) {

        if (dist > 1.0f) {
            phi_f0 = 1.0f / dist;
        } else {
            phi_f0 = 1.0f;
        }

        pthis->accel.x -= ((diff->x * D_809AA57C[temp_v0 - 1]) * phi_f0);
        pthis->accel.z -= ((diff->z * D_809AA57C[temp_v0 - 1]) * phi_f0);
    }

    return 1;
}

s32 func_809A9FD8(EffectSs* pthis, Vec3f* diff, f32 dist) {
    static f32 (*D_809AA588[])(f32 dist, s32 arg1) = {
        func_809A9DD8, func_809A9DEC, func_809A9DEC, func_809A9DEC, func_809A9E28,
        func_809A9E28, func_809A9E28, func_809A9E68, func_809A9E68, func_809A9E68,
    };
    f32 temp_f0;
    s32 temp_a1;

    temp_a1 = (pthis->rReg0 >> 7) & 0xF;
    temp_f0 = D_809AA588[temp_a1](dist, temp_a1);
    temp_f0 = func_809A9818(temp_f0, (pthis->rReg9 * temp_f0) / 1024.0f);

    pthis->accel.x *= temp_f0;
    pthis->accel.y *= temp_f0;
    pthis->accel.z *= temp_f0;

    pthis->accel.x += temp_f0 * 0.01f;
    pthis->accel.y += temp_f0 * 0.01f;
    pthis->accel.z += temp_f0 * 0.01f;

    return 1;
}

s32 func_809AA0B8(EffectSs* pthis, Vec3f* diff, f32 dist) {
    pthis->accel.y += pthis->rGravity / 256.0f;

    return 1;
}

s32 func_809AA0EC(EffectSs* pthis) {
    Vec3f diff;
    f32 dist;

    func_809A9DC0(pthis);

    diff.x = pthis->pos.x - pthis->vec.x;
    diff.y = pthis->pos.y - pthis->vec.y;
    diff.z = pthis->pos.z - pthis->vec.z;

    dist = sqrtf(SQ(diff.x) + SQ(diff.y) + SQ(diff.z));

    if (dist > 1000.0f) {
        return 0;
    }

    if (pthis->rReg0 != 0) {
        if (!func_809A9E88(pthis, &diff, dist)) {
            return false;
        }

        if (!func_809A9F10(pthis, &diff, dist)) {
            return false;
        }

        if (!func_809A9F4C(pthis, &diff, dist)) {
            return false;
        }

        if (!func_809A9FD8(pthis, &diff, dist)) {
            return false;
        }
    }

    if (!func_809AA0B8(pthis, &diff, dist)) {
        return false;
    }

    return true;
}

void func_809AA230(EffectSs* pthis, GlobalContext* globalCtx) {
    static f32 D_809AA5B0[] = { 10.0f, 20.0f, 40.0f };
    Player* player = GET_PLAYER(globalCtx);

    if (pthis->rReg8 == 0) {
        if ((((pthis->rReg4 >> 4) & 1) * 0x10) == 0x10) {
            if (pthis->pos.y <= (player->actor.floorHeight - ((pthis->rReg4 >> 2) & 3))) {
                pthis->rReg9 = 0;
                pthis->rReg0 = 0;
                pthis->rReg4 &= ~0x60;
                pthis->accel.x = pthis->accel.y = pthis->accel.z = 0.0f;
                pthis->velocity.x = pthis->velocity.y = pthis->velocity.z = 0.0f;
                pthis->rReg5 = pthis->rReg9;
                pthis->rGravity = pthis->rReg9;
            }
        } else {
            if (pthis->pos.y <= ((player->actor.floorHeight - ((pthis->rReg4 >> 2) & 3)) - 600.0f)) {
                pthis->life = 0;
            }
        }
    } else {
        switch (pthis->rReg4 & 3) {
            case 0:
                pthis->rReg8 = 0;
                break;
            case 1:
                if (pthis->velocity.y < 0.0f) {
                    if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &pthis->pos, D_809AA5B0[(pthis->rReg4 >> 2) & 3])) {
                        pthis->velocity.x *= func_809A9818(0.9f, 0.2f);
                        pthis->velocity.y *= -0.8f;
                        pthis->velocity.z *= func_809A9818(0.9f, 0.2f);

                        if (pthis->rReg8 > 0) {
                            pthis->rReg8 -= 1;
                        }
                    }
                }
                break;
            case 2:
                if (BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &pthis->pos, D_809AA5B0[(pthis->rReg4 >> 2) & 3])) {}
                break;
        }
    }
}

void EffectSsKakera_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    switch (((pthis->rReg4 >> 5) & 3) << 5) {
        case 0x20:
            pthis->rPitch += 0xB;
            pthis->rYaw += 3;
            break;
        case 0x40:
            pthis->rPitch += 0x41;
            pthis->rYaw += 0xB;
            break;
        case 0x60:
            pthis->rPitch += 0x9B;
            pthis->rYaw += 0x1F;
            break;
    }

    func_809A9C10(pthis);

    if (!func_809AA0EC(pthis)) {
        pthis->life = 0;
    }

    func_809AA230(pthis, globalCtx);

    if (pthis->rObjId != KAKERA_OBJECT_DEFAULT) {
        func_809A9BA8(pthis, globalCtx);
    }
}

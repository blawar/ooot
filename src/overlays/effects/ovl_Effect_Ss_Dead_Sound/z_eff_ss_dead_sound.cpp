#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_DEAD_SOUND_Z_EFF_SS_DEAD_SOUND_C
#include "actor_common.h"
/*
 * File: z_eff_ss_dead_sound.c
 * Overlay: ovl_Effect_Ss_Dead_Sound
 * Description: Plays a sound effect
 */

#include "z_eff_ss_dead_sound.h"
#include "def/code_800F7260.h"

#define rSfxId regs[10]
#define rRepeatMode regs[11] // sound is replayed every update. unused in the original game

u32 EffectSsDeadSound_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsDeadSound_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Dead_Sound_InitVars = {
    EFFECT_SS_DEAD_SOUND,
    EffectSsDeadSound_Init,
};

u32 EffectSsDeadSound_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsDeadSoundInitParams* initParams = (EffectSsDeadSoundInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->flags = 2;
    pthis->life = initParams->life;
    pthis->draw = NULL;
    pthis->update = EffectSsDeadSound_Update;
    pthis->rRepeatMode = initParams->repeatMode;
    pthis->rSfxId = initParams->sfxId;
    osSyncPrintf("コンストラクター3\n"); // "constructor 3"

    return 1;
}

void EffectSsDeadSound_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    switch (pthis->rRepeatMode) {
        case DEADSOUND_REPEAT_MODE_OFF:
            pthis->rRepeatMode--; // decrement to 0 so sound only plays once
            break;
        case DEADSOUND_REPEAT_MODE_ON:
            break;
        default:
            return;
    }

    Audio_PlaySoundGeneral(pthis->rSfxId, &pthis->pos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

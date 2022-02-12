#define INTERNAL_SRC_OVERLAYS_EFFECTS_OVL_EFFECT_SS_SOLDER_SRCH_BALL_Z_EFF_SS_SOLDER_SRCH_BALL_C
#include "actor_common.h"
/*
 * File: z_eff_ss_solder_srch_ball.c
 * Overlay: ovl_Effect_Ss_Solder_Srch_Ball
 * Description: Vision sphere for courtyard guards
 */

#include "z_eff_ss_solder_srch_ball.h"
#include "def/z_bgcheck.h"

#define rUnused regs[1]

u32 EffectSsSolderSrchBall_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx);
void EffectSsSolderSrchBall_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis);

EffectSsInit Effect_Ss_Solder_Srch_Ball_InitVars = {
    EFFECT_SS_SOLDER_SRCH_BALL,
    EffectSsSolderSrchBall_Init,
};

u32 EffectSsSolderSrchBall_Init(GlobalContext* globalCtx, u32 index, EffectSs* pthis, void* initParamsx) {
    EffectSsSolderSrchBallInitParams* initParams = (EffectSsSolderSrchBallInitParams*)initParamsx;

    pthis->pos = initParams->pos;
    pthis->velocity = initParams->velocity;
    pthis->accel = initParams->accel;
    pthis->update = EffectSsSolderSrchBall_Update;
    pthis->life = 100;
    pthis->rUnused = initParams->unused;
    pthis->actor = (Actor*)initParams->linkDetected; // actor field was incorrectly used as a pointer to something else
    return 1;
}

void EffectSsSolderSrchBall_Update(GlobalContext* globalCtx, u32 index, EffectSs* pthis) {
    s32 pad;
    f32 playerPosDiffX;
    f32 playerPosDiffY;
    f32 playerPosDiffZ;
    s16* linkDetected;
    Player* player = GET_PLAYER(globalCtx);

    linkDetected = (s16*)pthis->actor;

    playerPosDiffX = player->actor.world.pos.x - pthis->pos.x;
    playerPosDiffY = player->actor.world.pos.y - pthis->pos.y;
    playerPosDiffZ = player->actor.world.pos.z - pthis->pos.z;

    if (!BgCheck_SphVsFirstPoly(&globalCtx->colCtx, &pthis->pos, 30.0f)) {
        if (sqrtf(SQ(playerPosDiffX) + SQ(playerPosDiffY) + SQ(playerPosDiffZ)) < 70.0f) {
            *linkDetected = true;
        }
    } else {
        if (pthis->life > 1) {
            pthis->life = 1;
        }
    }
}

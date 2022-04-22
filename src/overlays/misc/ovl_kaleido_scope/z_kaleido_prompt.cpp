#define INTERNAL_SRC_OVERLAYS_MISC_OVL_KALEIDO_SCOPE_Z_KALEIDO_PROMPT_C
#include "actor_common.h"
#include "z_kaleido_scope.h"
#include "def/audio_bank.h"

static s16 D_8082A6E0[] = {100, 255};

void KaleidoScope_UpdatePrompt(GlobalContext* globalCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	Input* input = &globalCtx->input[0];
	s8 relStickX = input->rel.stick_x;
	s16 step;

	if(((pauseCtx->state == 7) && (pauseCtx->unk_1EC == 1)) || (pauseCtx->state == 0xE) || (pauseCtx->state == 0x10))
	{
		if((pauseCtx->promptChoice == 0) && (relStickX >= 30))
		{
			Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
			pauseCtx->promptChoice = 4;
		}
		else if((pauseCtx->promptChoice != 0) && (relStickX <= -30))
		{
			Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
			pauseCtx->promptChoice = 0;
		}

		step = ABS(VREG(61) - D_8082A6E0[VREG(62)]) / VREG(63);
		if(VREG(61) >= D_8082A6E0[VREG(62)])
		{
			VREG(61) -= step;
		}
		else
		{
			VREG(61) += step;
		}

		VREG(63)--;
		if(VREG(63) == 0)
		{
			VREG(61) = D_8082A6E0[VREG(62)];
			VREG(63) = VREG(60) + VREG(62);
			VREG(62) ^= 1;
		}
	}
}

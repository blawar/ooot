#pragma once
#ifdef INTERNAL_SRC_CODE_AUDIO_SYNTHESIS_C
Acmd* AudioSynth_Update(Acmd* cmdStart, s32* cmdCnt, s16* aiStart, s32 aiBufLen);
#else
Acmd* AudioSynth_Update(Acmd* cmdStart, s32* cmdCnt, s16* aiStart, s32 aiBufLen);
#endif

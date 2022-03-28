#define INTERNAL_SRC_CODE_Z_COMMON_DATA_C
#include "global.h"
#include "z64save.h"
#include "sequence.h"
#include "def/z_common_data.h"

SaveContext gSaveContext;
u32 D_8015FA88;
u32 D_8015FA8C;

u8 Get_Language();

void SaveContext_Init(void) {
	u8 currentLanguage = Get_Language();
    bzero(&gSaveContext, sizeof(gSaveContext));
    D_8015FA88 = 0;
    D_8015FA8C = 0;
    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
    gSaveContext.natureAmbienceId = 0xFF;
    gSaveContext.forcedSeqId = NA_BGM_GENERAL_SFX;
    gSaveContext.nextCutsceneIndex = 0xFFEF;
    gSaveContext.cutsceneTrigger = 0;
    gSaveContext.chamberCutsceneNum = 0;
    gSaveContext.nextDayTime = 0xFFFF;
    gSaveContext.skyboxTime = 0;
    gSaveContext.dogIsLost = true;
    gSaveContext.nextTransition = 0xFF;
    gSaveContext.unk_13EE = 50;
    gSaveContext.language = currentLanguage;
}

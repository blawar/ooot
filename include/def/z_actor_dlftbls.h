#pragma once

extern ActorOverlay gActorOverlayTable[ACTOR_ID_MAX];
extern s32 gMaxActorId;

#ifdef INTERNAL_SRC_CODE_Z_ACTOR_DLFTBLS_C
void ActorOverlayTable_Cleanup(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_LogPrint(void);
#else
void ActorOverlayTable_Cleanup(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_LogPrint(void);
#endif

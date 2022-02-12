#pragma once
struct ActorOverlay;

extern ActorOverlay gActorOverlayTable[ACTOR_ID_MAX];
extern s32 gMaxActorId;

void ActorOverlayTable_Cleanup(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_LogPrint(void);

#pragma once
struct GlobalContext;
struct Actor;

s32 OnePointCutscene_Attention(GlobalContext* globalCtx, Actor* actor);
s32 OnePointCutscene_AttentionSetSfx(GlobalContext* globalCtx, Actor* actor, s32 sfxId);
s32 OnePointCutscene_CheckForCategory(GlobalContext* globalCtx, s32 actorCategory);
void OnePointCutscene_DisableAttention(void);
void OnePointCutscene_EnableAttention(void);
s16 OnePointCutscene_EndCutscene(GlobalContext* globalCtx, s16 camIdx);
s16 OnePointCutscene_Init(GlobalContext* globalCtx, s16 csId, s16 timer, Actor* actor, s16 camIdx);
void OnePointCutscene_Noop(GlobalContext* globalCtx, s32 arg1);

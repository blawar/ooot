#pragma once

s16 OnePointCutscene_Init(struct GlobalContext* globalCtx, s16 csId, s16 timer, Actor* actor, s16 camIdx);
s16 OnePointCutscene_EndCutscene(struct GlobalContext* globalCtx, s16 camIdx);
s32 OnePointCutscene_Attention(struct GlobalContext* globalCtx, Actor* actor);
s32 OnePointCutscene_AttentionSetSfx(struct GlobalContext* globalCtx, Actor* actor, s32 sfxId);
void OnePointCutscene_EnableAttention(void);
void OnePointCutscene_DisableAttention(void);
s32 OnePointCutscene_CheckForCategory(struct GlobalContext* globalCtx, s32 actorCategory);
void OnePointCutscene_Noop(struct GlobalContext* globalCtx, s32 arg1);


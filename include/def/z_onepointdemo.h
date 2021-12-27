#pragma once
#ifdef INTERNAL_SRC_CODE_Z_ONEPOINTDEMO_C
s32 OnePointCutscene_Attention(GlobalContext* globalCtx, Actor* actor);
s32 OnePointCutscene_AttentionSetSfx(GlobalContext* globalCtx, Actor* actor, s32 sfxId);
s32 OnePointCutscene_CheckForCategory(GlobalContext* globalCtx, s32 actorCategory);
void OnePointCutscene_DisableAttention(void);
void OnePointCutscene_EnableAttention(void);
s16 OnePointCutscene_EndCutscene(GlobalContext* globalCtx, s16 camIdx);
s16 OnePointCutscene_Init(GlobalContext* globalCtx, s16 csId, s16 timer, Actor* actor, s16 camIdx);
void OnePointCutscene_Noop(GlobalContext* globalCtx, s32 arg1);
#else
s32 OnePointCutscene_Attention(struct GlobalContext* globalCtx, struct Actor* actor);
s32 OnePointCutscene_AttentionSetSfx(struct GlobalContext* globalCtx, struct Actor* actor, s32 sfxId);
s32 OnePointCutscene_CheckForCategory(struct GlobalContext* globalCtx, s32 actorCategory);
void OnePointCutscene_DisableAttention(void);
void OnePointCutscene_EnableAttention(void);
s16 OnePointCutscene_EndCutscene(struct GlobalContext* globalCtx, s16 camIdx);
s16 OnePointCutscene_Init(struct GlobalContext* globalCtx, s16 csId, s16 timer, struct Actor* actor, s16 camIdx);
void OnePointCutscene_Noop(struct GlobalContext* globalCtx, s32 arg1);
#endif

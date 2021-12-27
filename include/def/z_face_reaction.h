#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FACE_REACTION_C
u16 Text_GetFaceReaction(GlobalContext* globalCtx, u32 reactionSet);
#else
u16 Text_GetFaceReaction(struct GlobalContext* globalCtx, u32 reactionSet);
#endif

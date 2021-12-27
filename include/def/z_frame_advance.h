#pragma once
#ifdef INTERNAL_SRC_CODE_Z_FRAME_ADVANCE_C
void FrameAdvance_Init(FrameAdvanceContext* frameAdvCtx);
s32 FrameAdvance_Update(FrameAdvanceContext* frameAdvCtx, Input* input);
#else
void FrameAdvance_Init(struct FrameAdvanceContext* frameAdvCtx);
s32 FrameAdvance_Update(struct FrameAdvanceContext* frameAdvCtx, struct Input* input);
#endif

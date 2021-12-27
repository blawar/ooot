#pragma once

extern volatile OSTime D_8016A520;
extern volatile OSTime D_8016A528;
extern volatile OSTime D_8016A530;
extern volatile OSTime D_8016A538;
extern volatile OSTime D_8016A540;
extern volatile OSTime D_8016A548;
extern volatile OSTime D_8016A550;
extern volatile OSTime D_8016A558;
extern volatile OSTime gRDPTotalTime;
extern volatile OSTime gRSPAudioTotalTime;
extern volatile OSTime gRSPGFXTotalTime;
extern volatile OSTime gRSPOtherTotalTime;

#ifdef INTERNAL_SRC_CODE_SPEED_METER_C
void SpeedMeter_Destroy(SpeedMeter* this);
void SpeedMeter_DrawAllocEntries(SpeedMeter* meter, GraphicsContext* gfxCtx, GameState* state);
void SpeedMeter_DrawAllocEntry(SpeedMeterAllocEntry* this, GraphicsContext* gfxCtx);
void SpeedMeter_DrawTimeEntries(SpeedMeter* this, GraphicsContext* gfxCtx);
void SpeedMeter_Init(SpeedMeter* this);
void SpeedMeter_InitAllocEntry(SpeedMeterAllocEntry* entry, u32 maxval, u32 val, u16 backColor, u16 foreColor, u32 ulx, u32 lrx, u32 uly, u32 lry);
void SpeedMeter_InitImpl(SpeedMeter* this, u32 arg1, u32 y);
#else
void SpeedMeter_Destroy(struct SpeedMeter* this);
void SpeedMeter_DrawAllocEntries(struct SpeedMeter* meter, struct GraphicsContext* gfxCtx, struct GameState* state);
void SpeedMeter_DrawAllocEntry(struct SpeedMeterAllocEntry* this, struct GraphicsContext* gfxCtx);
void SpeedMeter_DrawTimeEntries(struct SpeedMeter* this, struct GraphicsContext* gfxCtx);
void SpeedMeter_Init(struct SpeedMeter* this);
void SpeedMeter_InitAllocEntry(struct SpeedMeterAllocEntry* entry, u32 maxval, u32 val, u16 backColor, u16 foreColor, u32 ulx, u32 lrx, u32 uly, u32 lry);
void SpeedMeter_InitImpl(struct SpeedMeter* this, u32 arg1, u32 y);
#endif

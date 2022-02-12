#pragma once
struct SpeedMeter;
struct GraphicsContext;
struct GameState;
struct SpeedMeterAllocEntry;

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

void SpeedMeter_Destroy(SpeedMeter* pthis);
void SpeedMeter_DrawAllocEntries(SpeedMeter* meter, GraphicsContext* gfxCtx, GameState* state);
void SpeedMeter_DrawAllocEntry(SpeedMeterAllocEntry* pthis, GraphicsContext* gfxCtx);
void SpeedMeter_DrawTimeEntries(SpeedMeter* pthis, GraphicsContext* gfxCtx);
void SpeedMeter_Init(SpeedMeter* pthis);
void SpeedMeter_InitAllocEntry(SpeedMeterAllocEntry* entry, u32 maxval, u32 val, u16 backColor, u16 foreColor, u32 ulx, u32 lrx, u32 uly, u32 lry);
void SpeedMeter_InitImpl(SpeedMeter* pthis, u32 arg1, u32 y);

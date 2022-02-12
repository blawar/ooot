#pragma once
struct OSMesgQueue;
struct OSViMode;

extern s8 D_80009430;
extern u8 D_80013960;
extern OSMesgQueue gPiMgrCmdQ;
extern u8 gViConfigAdditionalScanLines;
extern u32 gViConfigFeatures;
extern OSViMode gViConfigMode;
extern vu8 gViConfigUseDefault;
extern f32 gViConfigXScale;
extern f32 gViConfigYScale;

void Idle_ThreadEntry(void* arg);
void Main_ThreadEntry(void* arg);

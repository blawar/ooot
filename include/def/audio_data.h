#pragma once
struct AdsrEnvelope;

extern s16 D_8012FBA8[];
extern f32 gBendPitchOneOctaveFrequencies[256];
extern f32 gBendPitchTwoSemitonesFrequencies[256];
extern AdsrEnvelope gDefaultEnvelope[4];
extern NoteSubEu gDefaultNoteSub;
extern f32 gDefaultPanVolume[128];
extern u8 gDefaultShortNoteGateTimeTable[16];
extern u8 gDefaultShortNoteVelocityTable[16];
extern u16 gHeadsetPanQuantization[64];
extern f32 gHeadsetPanVolume[128];
extern f32 gNoteFrequencies[];
extern f32 gStereoPanVolume[128];
extern s16* gWaveSamples[9];
extern NoteSubEu gZeroNoteSub;
extern s16 sHighPassFilterData[15*8];
extern s16 sLowPassFilterData[16*8];

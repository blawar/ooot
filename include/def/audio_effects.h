#pragma once
#ifdef INTERNAL_SRC_CODE_AUDIO_EFFECTS_C
void Audio_AdsrInit(AdsrState* adsr, AdsrEnvelope* envelope, s16* volOut);
f32 Audio_AdsrUpdate(AdsrState* adsr);
f32 Audio_GetPortamentoFreqScale(Portamento* p);
f32 Audio_GetVibratoFreqScale(VibratoState* vib);
s16 Audio_GetVibratoPitchChange(VibratoState* vib);
void Audio_NotePortamentoInit(Note* note);
void Audio_NoteVibratoInit(Note* note);
void Audio_NoteVibratoUpdate(Note* note);
void Audio_SequenceChannelProcessSound(SequenceChannel* channel, s32 recalculateVolume, s32 b);
void Audio_SequencePlayerProcessSound(SequencePlayer* seqPlayer);
#else
void Audio_AdsrInit(AdsrState* adsr, struct AdsrEnvelope* envelope, s16* volOut);
f32 Audio_AdsrUpdate(AdsrState* adsr);
f32 Audio_GetPortamentoFreqScale(struct Portamento* p);
f32 Audio_GetVibratoFreqScale(struct VibratoState* vib);
s16 Audio_GetVibratoPitchChange(struct VibratoState* vib);
void Audio_NotePortamentoInit(struct Note* note);
void Audio_NoteVibratoInit(struct Note* note);
void Audio_NoteVibratoUpdate(struct Note* note);
void Audio_SequenceChannelProcessSound(struct SequenceChannel* channel, s32 recalculateVolume, s32 b);
void Audio_SequencePlayerProcessSound(struct SequencePlayer* seqPlayer);
#endif

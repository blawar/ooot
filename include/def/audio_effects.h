#pragma once
struct AdsrEnvelope;
struct Portamento;
struct VibratoState;
struct Note;
struct SequenceChannel;
struct SequencePlayer;

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

#pragma once
struct AudioListItem;
struct SequencePlayer;
struct SequenceChannel;

void* AudioSeq_AudioListPopBack(AudioListItem* list);
void AudioSeq_AudioListPushBack(AudioListItem* list, AudioListItem* item);
void AudioSeq_InitSequencePlayerChannels(s32 playerIdx);
void AudioSeq_InitSequencePlayers(void);
void AudioSeq_ProcessSequences(s32 arg0);
void AudioSeq_ResetSequencePlayer(SequencePlayer* seqPlayer);
void AudioSeq_SequenceChannelDisable(SequenceChannel* channel);
void AudioSeq_SequencePlayerDisable(SequencePlayer* seqPlayer);
void AudioSeq_SequencePlayerDisableAsFinished(SequencePlayer* seqPlayer);
void AudioSeq_SkipForwardSequence(SequencePlayer* seqPlayer);
